
/* $destdir/u34.c        Machine generated C code */

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


/* Code for physoppri */

static Lisp_Object CC_physoppri(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0060, v0061, v0062, v0063;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physoppri");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v0000;
/* end of prologue */
    stack[-6] = nil;
    v0060 = stack[-8];
    if (symbolp(v0060)) goto v0064;
    v0060 = stack[-8];
    v0060 = qcar(v0060);
    goto v0065;

v0065:
    stack[-9] = v0060;
    v0060 = stack[-8];
    if (symbolp(v0060)) goto v0066;
    v0060 = stack[-8];
    v0060 = qcdr(v0060);
    goto v0067;

v0067:
    stack[-7] = v0060;
    stack[-5] = elt(env, 0); /* physoppri */
    stack[-4] = elt(env, 2); /* "x= " */
    stack[-3] = stack[-9];
    stack[-2] = elt(env, 3); /* " y= " */
    stack[-1] = stack[-7];
    stack[0] = elt(env, 4); /* "nat= " */
    v0062 = elt(env, 5); /* !*nat */
    v0061 = elt(env, 6); /* " contract= " */
    v0060 = elt(env, 7); /* !*contract */
    v0060 = list3(v0062, v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = list3star(stack[-2], stack[-1], stack[0], v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = list3star(stack[-5], stack[-4], stack[-3], v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    fn = elt(env, 20); /* trwrite */
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = qvalue(elt(env, 5)); /* !*nat */
    if (v0060 == nil) goto v0069;
    v0060 = qvalue(elt(env, 7)); /* !*contract */
    if (!(v0060 == nil)) goto v0069;
    v0060 = stack[-9];
    v0060 = Lexplode(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = Lreverse(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-9] = v0060;
    v0060 = stack[-9];
    v0061 = Llength(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = (Lisp_Object)33; /* 2 */
    v0060 = (Lisp_Object)greaterp2(v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    v0060 = v0060 ? lisp_true : nil;
    env = stack[-10];
    if (v0060 == nil) goto v0070;
    v0060 = stack[-9];
    v0060 = qcdr(v0060);
    v0061 = qcar(v0060);
    v0060 = elt(env, 14); /* !- */
    if (v0061 == v0060) goto v0071;
    v0060 = stack[-9];
    v0061 = qcar(v0060);
    v0060 = elt(env, 16); /* !+ */
    if (v0061 == v0060) goto v0072;
    v0060 = stack[-9];
    v0060 = Lreverse(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = Lcompress(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-9] = v0060;
    goto v0073;

v0073:
    stack[0] = elt(env, 8); /* !" */
    v0060 = stack[-9];
    v0060 = Lexplode(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[0] = cons(stack[0], v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = elt(env, 8); /* !" */
    v0060 = ncons(v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = Lappend(nil, stack[0], v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = Lcompress(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-9] = v0060;
    v0060 = stack[-7];
    if (v0060 == nil) goto v0074;
    v0061 = stack[-9];
    v0060 = stack[-7];
    v0060 = cons(v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    goto v0075;

v0075:
    stack[-3] = v0060;
    stack[-2] = elt(env, 0); /* physoppri */
    stack[-1] = elt(env, 2); /* "x= " */
    stack[0] = stack[-9];
    v0063 = elt(env, 17); /* " z= " */
    v0062 = stack[-6];
    v0061 = elt(env, 18); /* " x1= " */
    v0060 = stack[-3];
    v0060 = list4(v0063, v0062, v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = list3star(stack[-2], stack[-1], stack[0], v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    fn = elt(env, 20); /* trwrite */
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = stack[-6];
    if (v0060 == nil) goto v0076;
    v0062 = elt(env, 19); /* expt */
    v0061 = stack[-3];
    v0060 = stack[-6];
    v0061 = list3(v0062, v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = elt(env, 19); /* expt */
    if (!symbolp(v0060)) v0060 = nil;
    else { v0060 = qfastgets(v0060);
           if (v0060 != nil) { v0060 = elt(v0060, 23); /* infix */
#ifdef RECORD_GET
             if (v0060 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0060 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0060 == SPID_NOPROP) v0060 = nil; }}
#endif
    fn = elt(env, 21); /* exptpri */
    v0060 = (*qfn2(fn))(qenv(fn), v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v0076:
    v0060 = stack[-9];
    fn = elt(env, 22); /* prin2!* */
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = stack[-7];
    if (v0060 == nil) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v0060 = elt(env, 9); /* "(" */
    fn = elt(env, 22); /* prin2!* */
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 10)) = v0060; /* obrkp!* */
    v0062 = elt(env, 11); /* !*comma!* */
    v0061 = (Lisp_Object)1; /* 0 */
    v0060 = stack[-7];
    fn = elt(env, 23); /* inprint */
    v0060 = (*qfnn(fn))(qenv(fn), 3, v0062, v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = qvalue(elt(env, 12)); /* t */
    qvalue(elt(env, 10)) = v0060; /* obrkp!* */
    v0060 = elt(env, 13); /* ")" */
    fn = elt(env, 22); /* prin2!* */
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v0074:
    v0060 = stack[-9];
    goto v0075;

v0072:
    v0060 = elt(env, 16); /* !+ */
    stack[-6] = v0060;
    v0061 = stack[-9];
    v0060 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 24); /* pnth */
    v0060 = (*qfn2(fn))(qenv(fn), v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = Lreverse(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = Lcompress(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-9] = v0060;
    goto v0073;

v0071:
    v0061 = elt(env, 14); /* !- */
    v0060 = elt(env, 15); /* !1 */
    v0060 = list2(v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = Lcompress(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-6] = v0060;
    v0061 = stack[-9];
    v0060 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 24); /* pnth */
    v0060 = (*qfn2(fn))(qenv(fn), v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = Lreverse(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = Lcompress(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-9] = v0060;
    goto v0073;

v0070:
    v0060 = stack[-9];
    v0060 = Lreverse(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = Lcompress(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-9] = v0060;
    goto v0073;

v0069:
    stack[0] = elt(env, 8); /* !" */
    v0060 = stack[-9];
    v0060 = Lexplode(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[0] = cons(stack[0], v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = elt(env, 8); /* !" */
    v0060 = ncons(v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = Lappend(nil, stack[0], v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = Lcompress(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    stack[-9] = v0060;
    v0060 = stack[-9];
    fn = elt(env, 22); /* prin2!* */
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = stack[-7];
    if (v0060 == nil) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v0060 = elt(env, 9); /* "(" */
    fn = elt(env, 22); /* prin2!* */
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 10)) = v0060; /* obrkp!* */
    v0062 = elt(env, 11); /* !*comma!* */
    v0061 = (Lisp_Object)1; /* 0 */
    v0060 = stack[-7];
    fn = elt(env, 23); /* inprint */
    v0060 = (*qfnn(fn))(qenv(fn), 3, v0062, v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-10];
    v0060 = qvalue(elt(env, 12)); /* t */
    qvalue(elt(env, 10)) = v0060; /* obrkp!* */
    v0060 = elt(env, 13); /* ")" */
    fn = elt(env, 22); /* prin2!* */
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v0066:
    v0060 = qvalue(elt(env, 1)); /* nil */
    goto v0067;

v0064:
    v0060 = stack[-8];
    goto v0065;
/* error exit handlers */
v0068:
    popv(11);
    return nil;
}



/* Code for strand!-alg!-top */

static Lisp_Object MS_CDECL CC_strandKalgKtop(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086, v0087, v0088;
    Lisp_Object fn;
    Lisp_Object v0005, v0083, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "strand-alg-top");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0083 = va_arg(aa, Lisp_Object);
    v0005 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for strand-alg-top");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0005,v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0083,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0005;
    stack[-1] = v0083;
    stack[-2] = v0000;
/* end of prologue */
    v0087 = stack[-2];
    v0086 = stack[0];
    fn = elt(env, 2); /* deletez1 */
    v0086 = (*qfn2(fn))(qenv(fn), v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-3];
    stack[-2] = v0086;
    v0088 = stack[0];
    v0087 = stack[-1];
    v0086 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 3); /* color!-strand */
    v0086 = (*qfnn(fn))(qenv(fn), 3, v0088, v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-3];
    stack[0] = v0086;
    v0087 = stack[-2];
    v0086 = stack[0];
    fn = elt(env, 4); /* contract!-strand */
    v0086 = (*qfn2(fn))(qenv(fn), v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-3];
    stack[-2] = v0086;
    v0088 = stack[-2];
    v0087 = stack[0];
    v0086 = qvalue(elt(env, 1)); /* nil */
    {
        popv(4);
        fn = elt(env, 5); /* dstr!-to!-alg */
        return (*qfnn(fn))(qenv(fn), 3, v0088, v0087, v0086);
    }
/* error exit handlers */
v0089:
    popv(4);
    return nil;
}



/* Code for pst_mkpst */

static Lisp_Object CC_pst_mkpst(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pst_mkpst");
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
    v0090 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* pst_mkpst1 */
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-1];
    v0090 = cons(stack[0], v0090);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* pst_equitable */
        return (*qfn1(fn))(qenv(fn), v0090);
    }
/* error exit handlers */
v0085:
    popv(2);
    return nil;
}



/* Code for add!-factor */

static Lisp_Object CC_addKfactor(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0083)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0096, v0097, v0098;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add-factor");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0083);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0083;
    stack[-1] = v0000;
/* end of prologue */
    v0096 = stack[0];
    v0096 = Lconsp(nil, v0096);
    env = stack[-2];
    if (v0096 == nil) goto v0099;
    v0097 = stack[-1];
    v0096 = stack[0];
    v0096 = qcar(v0096);
    v0096 = qcar(v0096);
    v0096 = (Lisp_Object)greaterp2(v0097, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    v0096 = v0096 ? lisp_true : nil;
    env = stack[-2];
    if (v0096 == nil) goto v0101;
    v0096 = qvalue(elt(env, 1)); /* nil */
    goto v0011;

v0011:
    v0097 = v0096;
    v0096 = v0097;
    if (v0096 == nil) goto v0102;
    stack[-1] = v0097;
    v0096 = v0097;
    v0096 = qcdr(v0096);
    v0096 = add1(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    v0096 = Lrplacd(nil, stack[-1], v0096);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v0102:
    v0098 = stack[-1];
    v0097 = (Lisp_Object)17; /* 1 */
    v0096 = stack[0];
    popv(3);
    return acons(v0098, v0097, v0096);

v0101:
    v0097 = stack[-1];
    v0096 = stack[0];
    v0096 = Lassoc(nil, v0097, v0096);
    goto v0011;

v0099:
    v0096 = qvalue(elt(env, 1)); /* nil */
    goto v0011;
/* error exit handlers */
v0100:
    popv(3);
    return nil;
}



/* Code for pasf_premf */

static Lisp_Object CC_pasf_premf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0083)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0106, v0058;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_premf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0083);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0083;
    v0106 = v0000;
/* end of prologue */
    v0058 = v0106;
    v0106 = stack[0];
    fn = elt(env, 1); /* remf */
    v0058 = (*qfn2(fn))(qenv(fn), v0058, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-1];
    v0106 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* pasf_premf1 */
        return (*qfn2(fn))(qenv(fn), v0058, v0106);
    }
/* error exit handlers */
v0066:
    popv(2);
    return nil;
}



/* Code for ofsf_ordatp */

static Lisp_Object CC_ofsf_ordatp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0083)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0077, v0086, v0087, v0088, v0108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_ordatp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0083);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0088 = v0083;
    v0108 = v0000;
/* end of prologue */
    v0048 = v0108;
    v0048 = qcdr(v0048);
    v0048 = qcar(v0048);
    v0087 = v0048;
    v0048 = v0088;
    v0048 = qcdr(v0048);
    v0048 = qcar(v0048);
    v0086 = v0048;
    v0077 = v0087;
    v0048 = v0086;
    if (equal(v0077, v0048)) goto v0099;
    v0048 = v0087;
    v0077 = v0086;
    fn = elt(env, 1); /* ordp */
    v0048 = (*qfn2(fn))(qenv(fn), v0048, v0077);
    errexit();
    v0048 = (v0048 == nil ? lisp_true : nil);
    return onevalue(v0048);

v0099:
    v0048 = v0108;
    v0048 = qcar(v0048);
    v0077 = v0088;
    v0077 = qcar(v0077);
    {
        fn = elt(env, 2); /* ofsf_ordrelp */
        return (*qfn2(fn))(qenv(fn), v0048, v0077);
    }
}



/* Code for dvfsf_ppolyp */

static Lisp_Object CC_dvfsf_ppolyp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0047;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dvfsf_ppolyp");
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
    v0047 = v0000;
/* end of prologue */
    v0050 = v0047;
    if (!consp(v0050)) goto v0064;
    v0050 = v0047;
    v0050 = qcar(v0050);
    v0050 = (consp(v0050) ? nil : lisp_true);
    goto v0065;

v0065:
    if (v0050 == nil) goto v0111;
    v0050 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v0050); }

v0111:
    v0050 = v0047;
    fn = elt(env, 4); /* kernels */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[0];
    v0047 = v0050;
    v0050 = v0047;
    v0050 = qcdr(v0050);
    if (v0050 == nil) goto v0112;
    v0050 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v0050); }

v0112:
    v0050 = v0047;
    v0050 = qcar(v0050);
    v0047 = elt(env, 2); /* p */
    v0050 = (v0050 == v0047 ? lisp_true : nil);
    { popv(1); return onevalue(v0050); }

v0064:
    v0050 = qvalue(elt(env, 1)); /* t */
    goto v0065;
/* error exit handlers */
v0048:
    popv(1);
    return nil;
}



/* Code for gcdld */

static Lisp_Object CC_gcdld(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0083)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0113, v0114, v0115, v0116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdld");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0083);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0114 = v0083;
    v0115 = v0000;
/* end of prologue */

v0104:
    v0116 = v0114;
    v0113 = (Lisp_Object)17; /* 1 */
    if (v0116 == v0113) goto v0084;
    v0116 = v0114;
    v0113 = (Lisp_Object)-15; /* -1 */
    v0113 = (v0116 == v0113 ? lisp_true : nil);
    goto v0090;

v0090:
    if (v0113 == nil) goto v0065;
    v0113 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v0113); }

v0065:
    v0113 = v0115;
    if (v0113 == nil) goto v0099;
    v0113 = v0115;
    v0113 = qcar(v0113);
    if (v0113 == nil) goto v0117;
    v0113 = v0115;
    v0113 = qcdr(v0113);
    stack[0] = v0113;
    v0113 = v0114;
    v0114 = v0115;
    v0114 = qcar(v0114);
    fn = elt(env, 2); /* gcd!-with!-number */
    v0113 = (*qfn2(fn))(qenv(fn), v0113, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-1];
    v0114 = v0113;
    v0113 = stack[0];
    v0115 = v0113;
    goto v0104;

v0117:
    v0113 = v0115;
    v0113 = qcdr(v0113);
    v0115 = v0113;
    goto v0104;

v0099:
    v0113 = v0114;
        popv(2);
        return Labsval(nil, v0113);

v0084:
    v0113 = qvalue(elt(env, 1)); /* t */
    goto v0090;
/* error exit handlers */
v0057:
    popv(2);
    return nil;
}



/* Code for simpsqrtsq */

static Lisp_Object CC_simpsqrtsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0085;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpsqrtsq");
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
    v0085 = stack[0];
    v0085 = qcar(v0085);
    fn = elt(env, 1); /* simpsqrt2 */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    v0085 = stack[0];
    v0085 = qcdr(v0085);
    fn = elt(env, 1); /* simpsqrt2 */
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    {
        Lisp_Object v0106 = stack[-1];
        popv(3);
        return cons(v0106, v0085);
    }
/* error exit handlers */
v0103:
    popv(3);
    return nil;
}



/* Code for ldf!-dep!-var */

static Lisp_Object CC_ldfKdepKvar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ldf-dep-var");
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
    v0054 = v0000;
/* end of prologue */
    stack[-2] = nil;
    stack[-1] = v0054;
    goto v0118;

v0118:
    v0054 = stack[-1];
    if (v0054 == nil) goto v0120;
    v0054 = stack[-1];
    v0054 = qcar(v0054);
    stack[0] = v0054;
    v0054 = stack[0];
    fn = elt(env, 3); /* ldt!-tvar */
    v0053 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    v0054 = qvalue(elt(env, 2)); /* depl!* */
    v0054 = Lassoc(nil, v0053, v0054);
    if (v0054 == nil) goto v0067;
    v0054 = stack[0];
    fn = elt(env, 3); /* ldt!-tvar */
    v0053 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    v0054 = qvalue(elt(env, 2)); /* depl!* */
    v0054 = Lassoc(nil, v0053, v0054);
    v0053 = qcdr(v0054);
    v0054 = stack[-2];
    v0054 = Lappend(nil, v0053, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    stack[-2] = v0054;
    goto v0067;

v0067:
    v0054 = stack[-1];
    v0054 = qcdr(v0054);
    stack[-1] = v0054;
    goto v0118;

v0120:
    v0054 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); /* makeset */
        return (*qfn1(fn))(qenv(fn), v0054);
    }
/* error exit handlers */
v0121:
    popv(4);
    return nil;
}



/* Code for nestzerop!: */

static Lisp_Object CC_nestzeropT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0106, v0058;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nestzerop:");
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
    v0058 = v0000;
/* end of prologue */
    v0106 = v0058;
    v0106 = integerp(v0106);
    if (v0106 == nil) goto v0065;
    v0106 = v0058;
    fn = elt(env, 1); /* simp */
    v0106 = (*qfn1(fn))(qenv(fn), v0106);
    errexit();
    goto v0004;

v0004:
    v0106 = qcar(v0106);
    v0106 = (v0106 == nil ? lisp_true : nil);
    return onevalue(v0106);

v0065:
    v0106 = v0058;
    v0106 = qcdr(v0106);
    v0106 = qcdr(v0106);
    v0106 = qcdr(v0106);
    goto v0004;
}



/* Code for vdpcleanup */

static Lisp_Object MS_CDECL CC_vdpcleanup(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "vdpcleanup");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpcleanup");
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
/* end of prologue */
    v0004 = qvalue(elt(env, 1)); /* nil */
    v0004 = ncons(v0004);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[0];
    qvalue(elt(env, 2)) = v0004; /* dipevlist!* */
    { popv(1); return onevalue(v0004); }
/* error exit handlers */
v0011:
    popv(1);
    return nil;
}



/* Code for remove_least_item */

static Lisp_Object CC_remove_least_item(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remove_least_item");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0101 = v0000;
/* end of prologue */

v0011:
    v0122 = v0101;
    v0122 = qcdr(v0122);
    if (v0122 == nil) goto v0120;
    v0122 = v0101;
    v0122 = qcdr(v0122);
    v0122 = qcar(v0122);
    v0122 = qcdr(v0122);
    if (v0122 == nil) goto v0084;
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    goto v0011;

v0084:
    {
        fn = elt(env, 2); /* remove_root_item */
        return (*qfn1(fn))(qenv(fn), v0101);
    }

v0120:
    v0101 = elt(env, 1); /* "How did we get here?" */
    {
        fn = elt(env, 3); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0101);
    }
}



/* Code for applysetop */

static Lisp_Object CC_applysetop(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0083)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008, v0009, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for applysetop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0083);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0009 = v0083;
    stack[-6] = v0000;
/* end of prologue */
    stack[-5] = nil;
    v0008 = (Lisp_Object)1; /* 0 */
    stack[-7] = v0008;
    v0008 = v0009;
    stack[-4] = v0008;
    v0008 = stack[-4];
    if (v0008 == nil) goto v0106;
    v0008 = stack[-4];
    v0008 = qcar(v0008);
    stack[0] = v0008;
    v0008 = stack[0];
    fn = elt(env, 6); /* reval */
    v0009 = (*qfn1(fn))(qenv(fn), v0008);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-8];
    stack[0] = v0009;
    v0008 = elt(env, 2); /* list */
    if (!consp(v0009)) goto v0112;
    v0009 = qcar(v0009);
    if (!(v0009 == v0008)) goto v0112;
    v0008 = stack[0];
    v0008 = qcdr(v0008);
    fn = elt(env, 7); /* delete!-dups */
    v0008 = (*qfn1(fn))(qenv(fn), v0008);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-8];
    stack[0] = v0008;
    v0009 = stack[-7];
    v0008 = (Lisp_Object)1; /* 0 */
    if (v0009 == v0008) goto v0077;
    v0007 = stack[-6];
    v0009 = stack[-7];
    v0008 = stack[0];
    v0008 = Lapply2(nil, 3, v0007, v0009, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-8];
    goto v0048;

v0048:
    stack[-7] = v0008;
    v0008 = stack[0];
    fn = elt(env, 8); /* make!-set */
    v0008 = (*qfn1(fn))(qenv(fn), v0008);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-8];
    goto v0122;

v0122:
    v0008 = ncons(v0008);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-8];
    stack[-2] = v0008;
    stack[-3] = v0008;
    goto v0085;

v0085:
    v0008 = stack[-4];
    v0008 = qcdr(v0008);
    stack[-4] = v0008;
    v0008 = stack[-4];
    if (v0008 == nil) goto v0155;
    stack[-1] = stack[-2];
    v0008 = stack[-4];
    v0008 = qcar(v0008);
    stack[0] = v0008;
    v0008 = stack[0];
    fn = elt(env, 6); /* reval */
    v0009 = (*qfn1(fn))(qenv(fn), v0008);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-8];
    stack[0] = v0009;
    v0008 = elt(env, 2); /* list */
    if (!consp(v0009)) goto v0156;
    v0009 = qcar(v0009);
    if (!(v0009 == v0008)) goto v0156;
    v0008 = stack[0];
    v0008 = qcdr(v0008);
    fn = elt(env, 7); /* delete!-dups */
    v0008 = (*qfn1(fn))(qenv(fn), v0008);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-8];
    stack[0] = v0008;
    v0009 = stack[-7];
    v0008 = (Lisp_Object)1; /* 0 */
    if (v0009 == v0008) goto v0035;
    v0007 = stack[-6];
    v0009 = stack[-7];
    v0008 = stack[0];
    v0008 = Lapply2(nil, 3, v0007, v0009, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-8];
    goto v0034;

v0034:
    stack[-7] = v0008;
    v0008 = stack[0];
    fn = elt(env, 8); /* make!-set */
    v0008 = (*qfn1(fn))(qenv(fn), v0008);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-8];
    goto v0157;

v0157:
    v0008 = ncons(v0008);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-8];
    v0008 = Lrplacd(nil, stack[-1], v0008);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-8];
    v0008 = stack[-2];
    v0008 = qcdr(v0008);
    stack[-2] = v0008;
    goto v0085;

v0035:
    v0008 = stack[0];
    goto v0034;

v0156:
    v0008 = stack[0];
    if (symbolp(v0008)) goto v0158;
    v0008 = stack[0];
    v0008 = Lconsp(nil, v0008);
    env = stack[-8];
    if (v0008 == nil) goto v0159;
    v0008 = stack[0];
    v0009 = qcar(v0008);
    v0008 = elt(env, 3); /* setvalued */
    v0008 = Lflagp(nil, v0009, v0008);
    env = stack[-8];
    if (!(v0008 == nil)) goto v0158;

v0159:
    v0009 = stack[0];
    v0008 = elt(env, 4); /* "set" */
    fn = elt(env, 9); /* typerr */
    v0008 = (*qfn2(fn))(qenv(fn), v0009, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-8];
    goto v0157;

v0158:
    v0009 = stack[0];
    v0008 = stack[-5];
    v0008 = Lmember(nil, v0009, v0008);
    if (!(v0008 == nil)) goto v0160;
    v0009 = stack[0];
    v0008 = stack[-5];
    v0008 = cons(v0009, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-8];
    stack[-5] = v0008;
    goto v0160;

v0160:
    v0008 = stack[0];
    goto v0157;

v0155:
    v0008 = stack[-3];
    goto v0084;

v0084:
    v0007 = v0008;
    v0008 = stack[-5];
    if (v0008 == nil) goto v0161;
    stack[0] = stack[-6];
    v0009 = stack[-6];
    v0008 = elt(env, 5); /* setdiff */
    if (v0009 == v0008) goto v0016;
    v0009 = stack[-7];
    v0008 = (Lisp_Object)1; /* 0 */
    if (v0009 == v0008) goto v0162;
    v0008 = stack[-7];
    fn = elt(env, 8); /* make!-set */
    v0009 = (*qfn1(fn))(qenv(fn), v0008);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-8];
    v0008 = stack[-5];
    v0008 = cons(v0009, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    goto v0163;

v0163:
    {
        Lisp_Object v0164 = stack[0];
        popv(9);
        return cons(v0164, v0008);
    }

v0162:
    v0008 = stack[-5];
    goto v0163;

v0016:
    v0008 = v0007;
    goto v0163;

v0161:
    v0008 = stack[-7];
    fn = elt(env, 8); /* make!-set */
    v0008 = (*qfn1(fn))(qenv(fn), v0008);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-8];
    {
        popv(9);
        fn = elt(env, 10); /* aeval */
        return (*qfn1(fn))(qenv(fn), v0008);
    }

v0077:
    v0008 = stack[0];
    goto v0048;

v0112:
    v0008 = stack[0];
    if (symbolp(v0008)) goto v0044;
    v0008 = stack[0];
    v0008 = Lconsp(nil, v0008);
    env = stack[-8];
    if (v0008 == nil) goto v0042;
    v0008 = stack[0];
    v0009 = qcar(v0008);
    v0008 = elt(env, 3); /* setvalued */
    v0008 = Lflagp(nil, v0009, v0008);
    env = stack[-8];
    if (!(v0008 == nil)) goto v0044;

v0042:
    v0009 = stack[0];
    v0008 = elt(env, 4); /* "set" */
    fn = elt(env, 9); /* typerr */
    v0008 = (*qfn2(fn))(qenv(fn), v0009, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-8];
    goto v0122;

v0044:
    v0009 = stack[0];
    v0008 = stack[-5];
    v0008 = Lmember(nil, v0009, v0008);
    if (!(v0008 == nil)) goto v0045;
    v0009 = stack[0];
    v0008 = stack[-5];
    v0008 = cons(v0009, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-8];
    stack[-5] = v0008;
    goto v0045;

v0045:
    v0008 = stack[0];
    goto v0122;

v0106:
    v0008 = qvalue(elt(env, 1)); /* nil */
    goto v0084;
/* error exit handlers */
v0154:
    popv(9);
    return nil;
}



/* Code for mkassign */

static Lisp_Object CC_mkassign(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0083)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0085, v0104, v0105;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkassign");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0085 = v0083;
    v0104 = v0000;
/* end of prologue */
    v0105 = elt(env, 1); /* setq */
    return list3(v0105, v0104, v0085);
}



/* Code for coeff_calc */

static Lisp_Object MS_CDECL CC_coeff_calc(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0080, v0081;
    Lisp_Object fn;
    Lisp_Object v0005, v0083, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeff_calc");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0083 = va_arg(aa, Lisp_Object);
    v0005 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for coeff_calc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0005,v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0083,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0082 = v0005;
    v0080 = v0083;
    v0081 = v0000;
/* end of prologue */
    stack[0] = elt(env, 1); /* plus */
    fn = elt(env, 2); /* coeff1_calc */
    v0082 = (*qfnn(fn))(qenv(fn), 3, v0081, v0080, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-1];
    v0082 = cons(stack[0], v0082);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* reval */
        return (*qfn1(fn))(qenv(fn), v0082);
    }
/* error exit handlers */
v0122:
    popv(2);
    return nil;
}



/* Code for rfirst */

static Lisp_Object CC_rfirst(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0056;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rfirst");
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
    v0055 = stack[0];
    v0055 = qcar(v0055);
    stack[0] = v0055;
    v0055 = stack[0];
    fn = elt(env, 4); /* listeval0 */
    v0056 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    stack[-1] = v0056;
    v0055 = elt(env, 1); /* list */
    if (!consp(v0056)) goto v0081;
    v0056 = qcar(v0056);
    if (!(v0056 == v0055)) goto v0081;
    v0055 = qvalue(elt(env, 2)); /* nil */
    goto v0090;

v0090:
    if (v0055 == nil) goto v0118;
    v0056 = stack[0];
    v0055 = elt(env, 3); /* "list" */
    fn = elt(env, 5); /* typerr */
    v0055 = (*qfn2(fn))(qenv(fn), v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    goto v0118;

v0118:
    v0055 = stack[-1];
    v0055 = qcdr(v0055);
    if (v0055 == nil) goto v0151;
    v0055 = stack[-1];
    v0055 = qcdr(v0055);
    v0055 = qcar(v0055);
    {
        popv(3);
        fn = elt(env, 6); /* reval */
        return (*qfn1(fn))(qenv(fn), v0055);
    }

v0151:
    v0056 = stack[0];
    v0055 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 7); /* parterr */
    v0055 = (*qfn2(fn))(qenv(fn), v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    v0055 = nil;
    { popv(3); return onevalue(v0055); }

v0081:
    v0055 = stack[0];
    fn = elt(env, 8); /* aeval */
    v0056 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    stack[-1] = v0056;
    v0055 = elt(env, 1); /* list */
    v0055 = Leqcar(nil, v0056, v0055);
    env = stack[-2];
    v0055 = (v0055 == nil ? lisp_true : nil);
    goto v0090;
/* error exit handlers */
v0098:
    popv(3);
    return nil;
}



/* Code for set!-weights */

static Lisp_Object CC_setKweights(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for set-weights");
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
    v0051 = v0000;
/* end of prologue */
    stack[-4] = (Lisp_Object)1; /* 0 */
    v0051 = qcdr(v0051);
    stack[-3] = v0051;
    v0051 = stack[-3];
    if (v0051 == nil) goto v0080;
    v0051 = (Lisp_Object)17; /* 1 */
    v0051 = ncons(v0051);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-5];
    stack[-1] = v0051;
    stack[-2] = v0051;
    goto v0058;

v0058:
    v0051 = stack[-3];
    v0051 = qcdr(v0051);
    stack[-3] = v0051;
    v0051 = stack[-3];
    if (v0051 == nil) goto v0093;
    stack[0] = stack[-1];
    v0051 = (Lisp_Object)17; /* 1 */
    v0051 = ncons(v0051);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-5];
    v0051 = Lrplacd(nil, stack[0], v0051);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-5];
    v0051 = stack[-1];
    v0051 = qcdr(v0051);
    stack[-1] = v0051;
    goto v0058;

v0093:
    v0051 = stack[-2];
    goto v0064;

v0064:
    v0051 = cons(stack[-4], v0051);
    nil = C_nil;
    if (exception_pending()) goto v0115;
        popv(6);
        return Lnreverse(nil, v0051);

v0080:
    v0051 = qvalue(elt(env, 1)); /* nil */
    goto v0064;
/* error exit handlers */
v0115:
    popv(6);
    return nil;
}



/* Code for fs!:minusp */

static Lisp_Object CC_fsTminusp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0047, v0048;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:minusp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0047 = v0000;
/* end of prologue */

v0011:
    v0050 = v0047;
    if (v0050 == nil) goto v0120;
    v0048 = v0047;
    v0050 = (Lisp_Object)49; /* 3 */
    v0050 = *(Lisp_Object *)((char *)v0048 + (CELL-TAG_VECTOR) + ((int32_t)v0050/(16/CELL)));
    if (v0050 == nil) goto v0080;
    v0050 = (Lisp_Object)49; /* 3 */
    v0050 = *(Lisp_Object *)((char *)v0047 + (CELL-TAG_VECTOR) + ((int32_t)v0050/(16/CELL)));
    v0047 = v0050;
    goto v0011;

v0080:
    v0050 = (Lisp_Object)1; /* 0 */
    v0050 = *(Lisp_Object *)((char *)v0047 + (CELL-TAG_VECTOR) + ((int32_t)v0050/(16/CELL)));
    v0050 = qcar(v0050);
    {
        fn = elt(env, 2); /* minusf */
        return (*qfn1(fn))(qenv(fn), v0050);
    }

v0120:
    v0050 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0050);
}



/* Code for lesspcar */

static Lisp_Object CC_lesspcar(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0083)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084, v0085;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lesspcar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0084 = v0083;
    v0085 = v0000;
/* end of prologue */
    v0085 = qcar(v0085);
    v0084 = qcar(v0084);
        return Llessp(nil, v0085, v0084);
}



/* Code for mkrootsq */

static Lisp_Object CC_mkrootsq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0083)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0183, v0184, v0185;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkrootsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0083);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0083;
    stack[-1] = v0000;
/* end of prologue */
    v0184 = stack[-1];
    v0183 = (Lisp_Object)17; /* 1 */
    if (v0184 == v0183) goto v0012;
    v0184 = stack[0];
    v0183 = (Lisp_Object)33; /* 2 */
    if (v0184 == v0183) goto v0079;
    v0183 = qvalue(elt(env, 3)); /* nil */
    goto v0058;

v0058:
    if (v0183 == nil) goto v0186;
    v0183 = elt(env, 4); /* i */
    {
        popv(4);
        fn = elt(env, 10); /* simp */
        return (*qfn1(fn))(qenv(fn), v0183);
    }

v0186:
    v0184 = stack[-1];
    v0183 = elt(env, 5); /* expt */
    if (!consp(v0184)) goto v0187;
    v0184 = qcar(v0184);
    if (!(v0184 == v0183)) goto v0187;
    v0183 = stack[-1];
    v0183 = qcdr(v0183);
    v0183 = qcdr(v0183);
    v0183 = qcar(v0183);
    v0183 = integerp(v0183);
    if (v0183 == nil) goto v0100;
    v0183 = qvalue(elt(env, 6)); /* !*precise_complex */
    v0183 = (v0183 == nil ? lisp_true : nil);
    goto v0113;

v0113:
    if (v0183 == nil) goto v0188;
    v0183 = stack[-1];
    v0183 = qcdr(v0183);
    v0184 = qcar(v0183);
    v0183 = stack[0];
    v0184 = CC_mkrootsq(env, v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-3];
    v0183 = stack[-1];
    v0183 = qcdr(v0183);
    v0183 = qcdr(v0183);
    v0183 = qcar(v0183);
    {
        popv(4);
        fn = elt(env, 11); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v0184, v0183);
    }

v0188:
    stack[-2] = nil;
    v0183 = stack[-1];
    v0183 = integerp(v0183);
    if (v0183 == nil) goto v0190;
    v0183 = stack[-1];
    v0183 = Lminusp(nil, v0183);
    env = stack[-3];
    if (v0183 == nil) goto v0157;
    v0183 = qvalue(elt(env, 3)); /* nil */
    goto v0155;

v0155:
    if (v0183 == nil) goto v0190;
    v0184 = stack[-2];
    v0183 = stack[0];
    {
        popv(4);
        fn = elt(env, 12); /* mkrootsql */
        return (*qfn2(fn))(qenv(fn), v0184, v0183);
    }

v0190:
    v0184 = stack[0];
    v0183 = (Lisp_Object)33; /* 2 */
    if (v0184 == v0183) goto v0191;
    stack[-2] = elt(env, 5); /* expt */
    v0185 = elt(env, 9); /* quotient */
    v0184 = (Lisp_Object)17; /* 1 */
    v0183 = stack[0];
    v0183 = list3(v0185, v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-3];
    v0183 = list3(stack[-2], stack[-1], v0183);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-3];
    goto v0192;

v0192:
    stack[-2] = v0183;
    v0183 = stack[-2];
    fn = elt(env, 13); /* opmtch */
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-3];
    v0184 = v0183;
    if (v0183 == nil) goto v0193;
    v0183 = v0184;
    {
        popv(4);
        fn = elt(env, 10); /* simp */
        return (*qfn1(fn))(qenv(fn), v0183);
    }

v0193:
    v0184 = stack[-2];
    v0183 = (Lisp_Object)17; /* 1 */
    {
        popv(4);
        fn = elt(env, 14); /* mksq */
        return (*qfn2(fn))(qenv(fn), v0184, v0183);
    }

v0191:
    v0183 = stack[-1];
    fn = elt(env, 15); /* mksqrt */
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-3];
    goto v0192;

v0157:
    stack[-2] = stack[-1];
    v0184 = stack[-1];
    v0183 = qvalue(elt(env, 7)); /* factorbound!* */
    v0183 = (Lisp_Object)lessp2(v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    v0183 = v0183 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0183 == nil)) goto v0194;
    v0183 = qvalue(elt(env, 8)); /* !*ifactor */
    goto v0194;

v0194:
    fn = elt(env, 16); /* zfactor1 */
    v0183 = (*qfn2(fn))(qenv(fn), stack[-2], v0183);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-3];
    stack[-2] = v0183;
    v0184 = Llength(nil, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-3];
    v0183 = (Lisp_Object)17; /* 1 */
    v0183 = (Lisp_Object)greaterp2(v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    v0183 = v0183 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0183 == nil)) goto v0155;
    v0183 = stack[-2];
    v0183 = qcar(v0183);
    v0184 = qcdr(v0183);
    v0183 = (Lisp_Object)17; /* 1 */
    v0183 = (Lisp_Object)greaterp2(v0184, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    v0183 = v0183 ? lisp_true : nil;
    env = stack[-3];
    goto v0155;

v0100:
    v0183 = qvalue(elt(env, 3)); /* nil */
    goto v0113;

v0187:
    v0183 = qvalue(elt(env, 3)); /* nil */
    goto v0113;

v0079:
    v0184 = stack[-1];
    v0183 = (Lisp_Object)-15; /* -1 */
    if (v0184 == v0183) goto v0094;
    v0184 = stack[-1];
    v0183 = elt(env, 2); /* (minus 1) */
    v0183 = (equal(v0184, v0183) ? lisp_true : nil);
    goto v0058;

v0094:
    v0183 = qvalue(elt(env, 1)); /* t */
    goto v0058;

v0012:
    v0183 = (Lisp_Object)17; /* 1 */
    {
        popv(4);
        fn = elt(env, 17); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v0183);
    }
/* error exit handlers */
v0189:
    popv(4);
    return nil;
}



/* Code for cl_bnfsimpl */

static Lisp_Object CC_cl_bnfsimpl(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0083)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0067, v0066;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_bnfsimpl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0067 = v0083;
    v0066 = v0000;
/* end of prologue */
    v0058 = qvalue(elt(env, 1)); /* !*rlbnfsac */
    if (v0058 == nil) return onevalue(v0066);
    v0058 = v0066;
    {
        fn = elt(env, 2); /* cl_sac */
        return (*qfn2(fn))(qenv(fn), v0058, v0067);
    }
}



/* Code for diffp */

static Lisp_Object CC_diffp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0083)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0412, v0413, v0414, v0415, v0416;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diffp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0083);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0083;
    stack[-5] = v0000;
/* end of prologue */
    stack[-3] = nil;
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    stack[-6] = v0412;
    v0412 = stack[-5];
    v0412 = qcar(v0412);
    stack[-5] = v0412;
    v0413 = stack[-6];
    v0412 = (Lisp_Object)17; /* 1 */
    v0412 = (Lisp_Object)greaterp2(v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    v0412 = v0412 ? lisp_true : nil;
    env = stack[-7];
    if (v0412 == nil) goto v0418;
    v0412 = stack[-5];
    fn = elt(env, 20); /* noncomp */
    v0412 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    if (v0412 == nil) goto v0418;
    v0413 = stack[-5];
    v0412 = stack[-4];
    v0412 = list2(v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    fn = elt(env, 21); /* simpdf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[0] = stack[-5];
    v0412 = stack[-6];
    v0412 = sub1(v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = list2(stack[0], v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    fn = elt(env, 22); /* simpexpt */
    v0412 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    fn = elt(env, 23); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0413 = stack[-5];
    v0412 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 24); /* to */
    v0413 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = (Lisp_Object)17; /* 1 */
    v0412 = cons(v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0413 = ncons(v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-2] = stack[-5];
    v0412 = stack[-6];
    v0412 = sub1(v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0413 = cons(stack[-2], v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = stack[-4];
    v0412 = CC_diffp(env, v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    fn = elt(env, 23); /* multsq */
    v0412 = (*qfn2(fn))(qenv(fn), stack[0], v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    {
        Lisp_Object v0419 = stack[-1];
        popv(8);
        fn = elt(env, 25); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0419, v0412);
    }

v0418:
    v0413 = stack[-5];
    v0412 = stack[-4];
    if (v0413 == v0412) goto v0420;
    v0412 = qvalue(elt(env, 1)); /* nil */
    goto v0144;

v0144:
    if (!(v0412 == nil)) goto v0421;
    v0412 = stack[-5];
    if (!consp(v0412)) goto v0422;
    v0412 = stack[-5];
    v0412 = qcar(v0412);
    if (!consp(v0412)) goto v0423;
    v0413 = stack[-5];
    v0412 = stack[-4];
    fn = elt(env, 26); /* difff */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0037;

v0037:
    if (!(v0412 == nil)) goto v0421;
    v0412 = stack[-5];
    v0413 = qcar(v0412);
    v0412 = elt(env, 2); /* !*sq */
    if (v0413 == v0412) goto v0031;
    v0412 = qvalue(elt(env, 1)); /* nil */
    goto v0140;

v0140:
    if (!(v0412 == nil)) goto v0421;
    v0412 = stack[-5];
    v0413 = qcar(v0412);
    v0412 = elt(env, 3); /* dfform */
    v0412 = get(v0413, v0412);
    env = stack[-7];
    stack[-2] = v0412;
    if (v0412 == nil) goto v0025;
    v0415 = stack[-2];
    v0414 = stack[-5];
    v0413 = stack[-4];
    v0412 = stack[-6];
        popv(8);
        return Lapply3(nil, 4, v0415, v0414, v0413, v0412);

v0025:
    v0412 = stack[-5];
    stack[0] = qcar(v0412);
    v0412 = stack[-5];
    fn = elt(env, 27); /* dfn_prop */
    v0412 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = get(stack[0], v0412);
    env = stack[-7];
    stack[-2] = v0412;
    if (v0412 == nil) goto v0165;
    v0412 = stack[-2];
    stack[-1] = v0412;
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    stack[0] = v0412;
    goto v0128;

v0128:
    v0412 = stack[0];
    v0412 = qcar(v0412);
    fn = elt(env, 28); /* simp */
    v0413 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = stack[-4];
    fn = elt(env, 29); /* diffsq */
    v0413 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = stack[-3];
    v0412 = cons(v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    v0412 = stack[-3];
    v0412 = qcar(v0412);
    v0412 = qcar(v0412);
    if (v0412 == nil) goto v0424;
    v0412 = stack[-1];
    v0412 = qcar(v0412);
    if (!(v0412 == nil)) goto v0424;

v0425:
    v0412 = stack[-5];
    v0413 = qcar(v0412);
    v0412 = elt(env, 13); /* df */
    if (v0413 == v0412) goto v0426;
    v0414 = elt(env, 13); /* df */
    v0413 = stack[-5];
    v0412 = stack[-4];
    v0412 = list3(v0414, v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0105;

v0105:
    v0412 = stack[-3];
    fn = elt(env, 30); /* opmtch */
    v0412 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-2] = v0412;
    if (v0412 == nil) goto v0427;
    v0412 = stack[-2];
    fn = elt(env, 28); /* simp */
    v0412 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0421;

v0421:
    v0413 = stack[-5];
    v0412 = qvalue(elt(env, 5)); /* wtl!* */
    v0412 = Latsoc(nil, v0413, v0412);
    stack[-2] = v0412;
    if (v0412 == nil) goto v0428;
    stack[0] = elt(env, 6); /* k!* */
    v0412 = stack[-2];
    v0412 = qcdr(v0412);
    v0412 = negate(v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    fn = elt(env, 24); /* to */
    v0413 = (*qfn2(fn))(qenv(fn), stack[0], v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = (Lisp_Object)17; /* 1 */
    v0412 = cons(v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0413 = ncons(v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = (Lisp_Object)17; /* 1 */
    v0413 = cons(v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = stack[-3];
    fn = elt(env, 23); /* multsq */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0428;

v0428:
    v0412 = stack[-6];
    v0412 = sub1(v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[0] = v0412;
    v0413 = stack[-6];
    v0412 = (Lisp_Object)17; /* 1 */
    if (v0413 == v0412) goto v0429;
    v0412 = qvalue(elt(env, 7)); /* dmode!* */
    if (!symbolp(v0412)) v0412 = nil;
    else { v0412 = qfastgets(v0412);
           if (v0412 != nil) { v0412 = elt(v0412, 5); /* convert */
#ifdef RECORD_GET
             if (v0412 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v0412 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v0412 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v0412 == SPID_NOPROP) v0412 = nil; else v0412 = lisp_true; }}
#endif
    if (v0412 == nil) goto v0430;
    v0412 = qvalue(elt(env, 7)); /* dmode!* */
    if (!symbolp(v0412)) v0413 = nil;
    else { v0413 = qfastgets(v0412);
           if (v0413 != nil) { v0413 = elt(v0413, 34); /* i2d */
#ifdef RECORD_GET
             if (v0413 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0413 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0413 == SPID_NOPROP) v0413 = nil; }}
#endif
    v0412 = stack[-6];
    v0412 = Lapply1(nil, v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    fn = elt(env, 31); /* int!-equiv!-chk */
    v0412 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-6] = v0412;
    v0412 = (v0412 == nil ? lisp_true : nil);
    goto v0431;

v0431:
    if (v0412 == nil) goto v0432;
    v0413 = qvalue(elt(env, 1)); /* nil */
    v0412 = (Lisp_Object)17; /* 1 */
    v0412 = cons(v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    goto v0433;

v0433:
    {
        popv(8);
        fn = elt(env, 32); /* rationalizesq */
        return (*qfn1(fn))(qenv(fn), v0412);
    }

v0432:
    v0413 = stack[-5];
    v0412 = stack[0];
    fn = elt(env, 24); /* to */
    v0413 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = stack[-6];
    v0412 = cons(v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0413 = ncons(v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = (Lisp_Object)17; /* 1 */
    v0413 = cons(v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = stack[-3];
    fn = elt(env, 23); /* multsq */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    goto v0433;

v0430:
    v0412 = qvalue(elt(env, 1)); /* nil */
    goto v0431;

v0429:
    v0412 = stack[-3];
    goto v0433;

v0427:
    v0413 = stack[-5];
    v0412 = stack[-4];
    fn = elt(env, 33); /* depends */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    if (v0412 == nil) goto v0434;
    v0412 = qvalue(elt(env, 1)); /* nil */
    goto v0435;

v0435:
    if (v0412 == nil) goto v0436;
    v0413 = qvalue(elt(env, 1)); /* nil */
    v0412 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v0413, v0412);

v0436:
    v0412 = qvalue(elt(env, 11)); /* !*expanddf */
    if (v0412 == nil) goto v0437;
    v0412 = stack[-5];
    if (!consp(v0412)) goto v0438;
    v0412 = stack[-3];
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    if (v0412 == nil) goto v0439;
    v0412 = qvalue(elt(env, 1)); /* nil */
    goto v0440;

v0440:
    if (v0412 == nil) goto v0437;
    v0413 = stack[-5];
    v0412 = qvalue(elt(env, 12)); /* depl!* */
    v0412 = Lassoc(nil, v0413, v0412);
    stack[-2] = v0412;
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    if (v0412 == nil) goto v0441;
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    fn = elt(env, 34); /* get!-all!-kernels */
    v0412 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    goto v0442;

v0442:
    stack[-1] = v0412;
    v0412 = stack[-2];
    if (v0412 == nil) goto v0443;
    v0412 = stack[-1];
    if (v0412 == nil) goto v0443;
    v0413 = stack[-4];
    v0412 = stack[-1];
    v0413 = Ldelete(nil, v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = stack[-4];
    fn = elt(env, 35); /* ldepends */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    if (v0412 == nil) goto v0443;
    v0416 = elt(env, 19); /* "Possible inconsistent dependencies in" */
    v0415 = stack[-5];
    v0414 = qvalue(elt(env, 1)); /* nil */
    v0413 = qvalue(elt(env, 1)); /* nil */
    v0412 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 36); /* msgpri */
    v0412 = (*qfnn(fn))(qenv(fn), 5, v0416, v0415, v0414, v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0413 = stack[-3];
    v0412 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 37); /* mksq */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0421;

v0443:
    v0412 = stack[-2];
    if (v0412 == nil) goto v0444;
    v0413 = stack[-4];
    v0412 = stack[-2];
    v0412 = qcdr(v0412);
    stack[-2] = v0412;
    v0412 = Lmemq(nil, v0413, v0412);
    if (v0412 == nil) goto v0445;
    v0413 = stack[-3];
    v0412 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 37); /* mksq */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0421;

v0445:
    v0414 = stack[-5];
    v0413 = stack[-4];
    v0412 = stack[-2];
    fn = elt(env, 38); /* df!-chain!-rule */
    v0412 = (*qfnn(fn))(qenv(fn), 3, v0414, v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0421;

v0444:
    v0412 = stack[-1];
    if (v0412 == nil) goto v0446;
    v0413 = stack[-4];
    v0412 = stack[-1];
    fn = elt(env, 39); /* smember */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    if (v0412 == nil) goto v0447;
    v0413 = stack[-3];
    v0412 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 37); /* mksq */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    goto v0448;

v0448:
    stack[-3] = v0412;
    goto v0421;

v0447:
    v0414 = stack[-5];
    v0413 = stack[-4];
    v0412 = stack[-1];
    fn = elt(env, 38); /* df!-chain!-rule */
    v0412 = (*qfnn(fn))(qenv(fn), 3, v0414, v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    goto v0448;

v0446:
    v0413 = stack[-3];
    v0412 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 37); /* mksq */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0421;

v0441:
    v0412 = qvalue(elt(env, 1)); /* nil */
    goto v0442;

v0437:
    v0413 = stack[-3];
    v0412 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 37); /* mksq */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0421;

v0439:
    v0412 = stack[-5];
    v0413 = qcar(v0412);
    v0412 = elt(env, 18); /* (df int) */
    v0412 = Lmemq(nil, v0413, v0412);
    if (v0412 == nil) goto v0449;
    v0412 = qvalue(elt(env, 1)); /* nil */
    goto v0440;

v0449:
    v0413 = stack[-4];
    v0412 = stack[-5];
    fn = elt(env, 39); /* smember */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    if (v0412 == nil) goto v0450;
    v0412 = qvalue(elt(env, 1)); /* nil */
    goto v0440;

v0450:
    v0413 = stack[-5];
    v0412 = qvalue(elt(env, 8)); /* powlis!* */
    v0412 = Latsoc(nil, v0413, v0412);
    stack[-2] = v0412;
    if (v0412 == nil) goto v0451;
    v0412 = stack[-2];
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    v0413 = qcar(v0412);
    v0412 = stack[-4];
    fn = elt(env, 33); /* depends */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = (v0412 == nil ? lisp_true : nil);
    goto v0440;

v0451:
    v0412 = qvalue(elt(env, 9)); /* t */
    goto v0440;

v0438:
    v0412 = qvalue(elt(env, 1)); /* nil */
    goto v0440;

v0434:
    v0412 = stack[-3];
    v0412 = qcdr(v0412);
    v0413 = qcar(v0412);
    stack[-5] = v0413;
    v0412 = qvalue(elt(env, 8)); /* powlis!* */
    v0412 = Latsoc(nil, v0413, v0412);
    stack[-2] = v0412;
    if (v0412 == nil) goto v0452;
    v0412 = stack[-2];
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    v0413 = qcar(v0412);
    v0412 = stack[-3];
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    fn = elt(env, 40); /* dependsl */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = (v0412 == nil ? lisp_true : nil);
    goto v0453;

v0453:
    if (v0412 == nil) goto v0454;
    v0412 = qvalue(elt(env, 10)); /* !*depend */
    v0412 = (v0412 == nil ? lisp_true : nil);
    goto v0435;

v0454:
    v0412 = qvalue(elt(env, 1)); /* nil */
    goto v0435;

v0452:
    v0412 = qvalue(elt(env, 9)); /* t */
    goto v0453;

v0426:
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    v0413 = qcar(v0412);
    v0412 = stack[-4];
    if (v0413 == v0412) goto v0455;
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    v0413 = qcar(v0412);
    v0412 = elt(env, 16); /* int */
    if (!consp(v0413)) goto v0456;
    v0413 = qcar(v0413);
    if (!(v0413 == v0412)) goto v0456;
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    v0412 = qcar(v0412);
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    v0413 = qcar(v0412);
    v0412 = stack[-4];
    if (v0413 == v0412) goto v0457;
    v0412 = qvalue(elt(env, 17)); /* !*allowdfint */
    if (v0412 == nil) goto v0456;
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    v0412 = qcar(v0412);
    v0412 = qcdr(v0412);
    v0412 = qcar(v0412);
    fn = elt(env, 41); /* simp!* */
    v0413 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = stack[-4];
    fn = elt(env, 29); /* diffsq */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    fn = elt(env, 42); /* not_df_p */
    v0412 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    if (v0412 == nil) goto v0456;
    stack[-1] = elt(env, 13); /* df */
    stack[0] = elt(env, 16); /* int */
    v0412 = stack[-3];
    fn = elt(env, 43); /* mk!*sq */
    v0413 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    v0412 = qcar(v0412);
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    v0412 = qcar(v0412);
    v0412 = list3(stack[0], v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    fn = elt(env, 44); /* reval */
    v0413 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    v0412 = list2star(stack[-1], v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0105;

v0456:
    v0412 = qvalue(elt(env, 11)); /* !*expanddf */
    if (v0412 == nil) goto v0458;
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    v0413 = qcar(v0412);
    v0412 = stack[-4];
    fn = elt(env, 33); /* depends */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    if (v0412 == nil) goto v0458;
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    v0413 = qcar(v0412);
    v0412 = qvalue(elt(env, 8)); /* powlis!* */
    v0412 = Latsoc(nil, v0413, v0412);
    stack[-2] = v0412;
    if (v0412 == nil) goto v0459;
    v0412 = stack[-2];
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    v0413 = qcar(v0412);
    v0412 = stack[-4];
    fn = elt(env, 33); /* depends */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = (v0412 == nil ? lisp_true : nil);
    goto v0460;

v0460:
    if (v0412 == nil) goto v0458;
    v0413 = stack[-4];
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    v0412 = qcar(v0412);
    fn = elt(env, 39); /* smember */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    if (!(v0412 == nil)) goto v0458;
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    v0413 = qcar(v0412);
    v0412 = qvalue(elt(env, 12)); /* depl!* */
    v0412 = Lassoc(nil, v0413, v0412);
    stack[-2] = v0412;
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    v0412 = qcar(v0412);
    if (!consp(v0412)) goto v0461;
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    v0412 = qcar(v0412);
    v0412 = qcdr(v0412);
    if (v0412 == nil) goto v0462;
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    v0412 = qcar(v0412);
    v0412 = qcdr(v0412);
    fn = elt(env, 34); /* get!-all!-kernels */
    v0412 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    goto v0463;

v0463:
    stack[-1] = v0412;
    v0412 = stack[-2];
    if (v0412 == nil) goto v0464;
    v0412 = stack[-1];
    if (v0412 == nil) goto v0464;
    v0413 = stack[-4];
    v0412 = stack[-1];
    v0413 = Ldelete(nil, v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = stack[-4];
    fn = elt(env, 35); /* ldepends */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    if (!(v0412 == nil)) goto v0458;

v0464:
    v0412 = stack[-2];
    if (v0412 == nil) goto v0465;
    v0413 = stack[-4];
    v0412 = stack[-2];
    v0412 = qcdr(v0412);
    stack[-2] = v0412;
    v0412 = Lmemq(nil, v0413, v0412);
    if (!(v0412 == nil)) goto v0465;
    v0414 = stack[-5];
    v0413 = stack[-4];
    v0412 = stack[-2];
    fn = elt(env, 38); /* df!-chain!-rule */
    v0412 = (*qfnn(fn))(qenv(fn), 3, v0414, v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0421;

v0465:
    v0412 = stack[-1];
    if (v0412 == nil) goto v0458;
    v0413 = stack[-4];
    v0412 = stack[-1];
    fn = elt(env, 39); /* smember */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    if (!(v0412 == nil)) goto v0458;
    v0414 = stack[-5];
    v0413 = stack[-4];
    v0412 = stack[-1];
    fn = elt(env, 38); /* df!-chain!-rule */
    v0412 = (*qfnn(fn))(qenv(fn), 3, v0414, v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0421;

v0458:
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    stack[0] = qcar(v0412);
    v0413 = stack[-5];
    v0412 = stack[-4];
    fn = elt(env, 45); /* merge!-ind!-vars */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0413 = cons(stack[0], v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0413;
    v0412 = elt(env, 13); /* df */
    if (!symbolp(v0412)) v0412 = nil;
    else { v0412 = qfastgets(v0412);
           if (v0412 != nil) { v0412 = elt(v0412, 50); /* kvalue */
#ifdef RECORD_GET
             if (v0412 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v0412 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v0412 == SPID_NOPROP) v0412 = nil; }}
#endif
    fn = elt(env, 46); /* find_sub_df */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-2] = v0412;
    if (v0412 == nil) goto v0466;
    v0412 = stack[-2];
    v0412 = qcar(v0412);
    fn = elt(env, 28); /* simp */
    v0412 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    v0412 = stack[-2];
    v0412 = qcdr(v0412);
    stack[-2] = v0412;
    goto v0467;

v0467:
    v0412 = stack[-2];
    if (v0412 == nil) goto v0421;
    v0412 = stack[-2];
    v0412 = qcar(v0412);
    stack[-1] = v0412;
    v0412 = (Lisp_Object)17; /* 1 */
    stack[0] = v0412;
    goto v0468;

v0468:
    v0412 = stack[-1];
    v0413 = qcdr(v0412);
    v0412 = stack[0];
    v0412 = difference2(v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = Lminusp(nil, v0412);
    env = stack[-7];
    if (v0412 == nil) goto v0469;
    v0412 = stack[-2];
    v0412 = qcdr(v0412);
    stack[-2] = v0412;
    goto v0467;

v0469:
    v0413 = stack[-3];
    v0412 = stack[-1];
    v0412 = qcar(v0412);
    fn = elt(env, 29); /* diffsq */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    v0412 = stack[0];
    v0412 = add1(v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[0] = v0412;
    goto v0468;

v0466:
    v0413 = elt(env, 13); /* df */
    v0412 = stack[-3];
    v0412 = cons(v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0105;

v0462:
    v0412 = qvalue(elt(env, 1)); /* nil */
    goto v0463;

v0461:
    v0412 = qvalue(elt(env, 1)); /* nil */
    goto v0463;

v0459:
    v0412 = qvalue(elt(env, 9)); /* t */
    goto v0460;

v0457:
    v0414 = elt(env, 13); /* df */
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    v0412 = qcar(v0412);
    v0412 = qcdr(v0412);
    v0413 = qcar(v0412);
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    v0412 = list2star(v0414, v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0105;

v0455:
    v0412 = qvalue(elt(env, 14)); /* !*commutedf */
    if (v0412 == nil) goto v0470;
    v0412 = qvalue(elt(env, 10)); /* !*depend */
    if (!(v0412 == nil)) goto v0470;
    v0413 = qvalue(elt(env, 1)); /* nil */
    v0412 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v0413, v0412);

v0470:
    v0412 = qvalue(elt(env, 15)); /* !*simpnoncomdf */
    if (v0412 == nil) goto v0456;
    v0413 = stack[-4];
    v0412 = qvalue(elt(env, 12)); /* depl!* */
    v0412 = Latsoc(nil, v0413, v0412);
    stack[-3] = v0412;
    if (v0412 == nil) goto v0456;
    v0412 = stack[-3];
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    if (!(v0412 == nil)) goto v0456;
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    v0412 = qcar(v0412);
    stack[-2] = v0412;
    v0414 = elt(env, 13); /* df */
    v0413 = stack[-5];
    v0412 = stack[-2];
    v0412 = list3(v0414, v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    fn = elt(env, 28); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0414 = elt(env, 13); /* df */
    v0413 = stack[-4];
    v0412 = stack[-2];
    v0412 = list3(v0414, v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    fn = elt(env, 28); /* simp */
    v0412 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    fn = elt(env, 47); /* quotsq */
    v0412 = (*qfn2(fn))(qenv(fn), stack[0], v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0421;

v0424:
    v0412 = stack[-1];
    v0412 = qcdr(v0412);
    stack[-1] = v0412;
    v0412 = stack[0];
    v0412 = qcdr(v0412);
    stack[0] = v0412;
    v0412 = stack[0];
    if (v0412 == nil) goto v0471;
    v0412 = stack[-1];
    if (!(v0412 == nil)) goto v0128;

v0471:
    v0412 = stack[0];
    if (!(v0412 == nil)) goto v0425;
    v0412 = stack[-1];
    if (!(v0412 == nil)) goto v0425;
    v0412 = stack[-3];
    v0412 = Lreverse(nil, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-1] = v0412;
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    stack[0] = v0412;
    v0413 = qvalue(elt(env, 1)); /* nil */
    v0412 = (Lisp_Object)17; /* 1 */
    v0412 = cons(v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0472;

v0472:
    v0412 = stack[-1];
    v0412 = qcar(v0412);
    v0412 = qcar(v0412);
    if (v0412 == nil) goto v0473;
    v0412 = stack[-1];
    stack[-4] = qcar(v0412);
    v0412 = stack[-2];
    v0412 = qcar(v0412);
    v0413 = qcar(v0412);
    v0412 = stack[0];
    fn = elt(env, 48); /* pair */
    v0413 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = stack[-2];
    v0412 = qcar(v0412);
    v0412 = qcdr(v0412);
    v0412 = Lsubla(nil, v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    fn = elt(env, 28); /* simp */
    v0412 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    fn = elt(env, 23); /* multsq */
    v0413 = (*qfn2(fn))(qenv(fn), stack[-4], v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = stack[-3];
    fn = elt(env, 25); /* addsq */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0473;

v0473:
    v0412 = stack[-2];
    v0412 = qcdr(v0412);
    stack[-2] = v0412;
    v0412 = stack[-1];
    v0412 = qcdr(v0412);
    stack[-1] = v0412;
    v0412 = stack[-1];
    if (v0412 == nil) goto v0421;
    else goto v0472;

v0165:
    v0412 = stack[-5];
    v0413 = qcar(v0412);
    v0412 = elt(env, 4); /* plus */
    if (v0413 == v0412) goto v0163;
    v0412 = qvalue(elt(env, 1)); /* nil */
    goto v0022;

v0022:
    if (v0412 == nil) goto v0425;
    else goto v0421;

v0163:
    v0412 = stack[-5];
    fn = elt(env, 28); /* simp */
    v0413 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = stack[-4];
    fn = elt(env, 29); /* diffsq */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0022;

v0031:
    v0412 = stack[-5];
    v0412 = qcdr(v0412);
    v0413 = qcar(v0412);
    v0412 = stack[-4];
    fn = elt(env, 29); /* diffsq */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0140;

v0423:
    v0412 = qvalue(elt(env, 1)); /* nil */
    goto v0037;

v0422:
    v0413 = stack[-5];
    v0412 = stack[-4];
    fn = elt(env, 33); /* depends */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    if (v0412 == nil) goto v0474;
    v0412 = qvalue(elt(env, 1)); /* nil */
    goto v0475;

v0475:
    if (v0412 == nil) goto v0476;
    v0413 = qvalue(elt(env, 1)); /* nil */
    v0412 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v0413, v0412);

v0476:
    v0412 = qvalue(elt(env, 11)); /* !*expanddf */
    if (v0412 == nil) goto v0477;
    v0413 = stack[-5];
    v0412 = qvalue(elt(env, 8)); /* powlis!* */
    v0412 = Latsoc(nil, v0413, v0412);
    stack[-2] = v0412;
    if (v0412 == nil) goto v0478;
    v0412 = stack[-2];
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    v0413 = qcar(v0412);
    v0412 = stack[-4];
    fn = elt(env, 33); /* depends */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = (v0412 == nil ? lisp_true : nil);
    goto v0479;

v0479:
    if (v0412 == nil) goto v0480;
    v0413 = stack[-5];
    v0412 = qvalue(elt(env, 12)); /* depl!* */
    v0412 = Latsoc(nil, v0413, v0412);
    stack[-2] = v0412;
    if (v0412 == nil) goto v0481;
    v0413 = stack[-4];
    v0412 = stack[-2];
    v0412 = qcdr(v0412);
    stack[-2] = v0412;
    v0412 = Lmemq(nil, v0413, v0412);
    v0412 = (v0412 == nil ? lisp_true : nil);
    goto v0482;

v0482:
    if (v0412 == nil) goto v0477;
    v0414 = stack[-5];
    v0413 = stack[-4];
    v0412 = stack[-2];
    fn = elt(env, 38); /* df!-chain!-rule */
    v0412 = (*qfnn(fn))(qenv(fn), 3, v0414, v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0421;

v0477:
    v0414 = elt(env, 13); /* df */
    v0413 = stack[-5];
    v0412 = stack[-4];
    v0412 = list3(v0414, v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    v0412 = stack[-3];
    fn = elt(env, 30); /* opmtch */
    v0412 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-2] = v0412;
    if (v0412 == nil) goto v0483;
    v0412 = stack[-2];
    fn = elt(env, 28); /* simp */
    v0412 = (*qfn1(fn))(qenv(fn), v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    goto v0484;

v0484:
    stack[-3] = v0412;
    goto v0421;

v0483:
    v0413 = stack[-3];
    v0412 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 37); /* mksq */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    goto v0484;

v0481:
    v0412 = qvalue(elt(env, 1)); /* nil */
    goto v0482;

v0480:
    v0412 = qvalue(elt(env, 1)); /* nil */
    goto v0482;

v0478:
    v0412 = qvalue(elt(env, 9)); /* t */
    goto v0479;

v0474:
    v0413 = stack[-5];
    v0412 = qvalue(elt(env, 8)); /* powlis!* */
    v0412 = Latsoc(nil, v0413, v0412);
    stack[-2] = v0412;
    if (v0412 == nil) goto v0485;
    v0412 = stack[-2];
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    v0412 = qcdr(v0412);
    v0413 = qcar(v0412);
    v0412 = stack[-4];
    fn = elt(env, 33); /* depends */
    v0412 = (*qfn2(fn))(qenv(fn), v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    v0412 = (v0412 == nil ? lisp_true : nil);
    goto v0486;

v0486:
    if (v0412 == nil) goto v0487;
    v0412 = qvalue(elt(env, 10)); /* !*depend */
    v0412 = (v0412 == nil ? lisp_true : nil);
    goto v0475;

v0487:
    v0412 = qvalue(elt(env, 1)); /* nil */
    goto v0475;

v0485:
    v0412 = qvalue(elt(env, 9)); /* t */
    goto v0486;

v0420:
    v0413 = (Lisp_Object)17; /* 1 */
    v0412 = (Lisp_Object)17; /* 1 */
    v0412 = cons(v0413, v0412);
    nil = C_nil;
    if (exception_pending()) goto v0417;
    env = stack[-7];
    stack[-3] = v0412;
    goto v0144;
/* error exit handlers */
v0417:
    popv(8);
    return nil;
}



/* Code for rewrite */

static Lisp_Object MS_CDECL CC_rewrite(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0392, v0006, v0125, v0424;
    Lisp_Object fn;
    Lisp_Object v0004, v0005, v0083, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "rewrite");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0083 = va_arg(aa, Lisp_Object);
    v0005 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rewrite");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0004,v0005,v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0083,v0005,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-9] = v0004;
    stack[-10] = v0005;
    stack[-11] = v0083;
    stack[-12] = v0000;
/* end of prologue */
    v0392 = (Lisp_Object)17; /* 1 */
    stack[-13] = v0392;
    v0392 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0392;
    v0392 = stack[-12];
    v0392 = qcdr(v0392);
    v0392 = qcdr(v0392);
    v0392 = qcar(v0392);
    v0006 = v0392;
    v0006 = qcdr(v0006);
    v0006 = qcar(v0006);
    v0392 = qcdr(v0392);
    v0392 = qcdr(v0392);
    v0392 = qcar(v0392);
    if (equal(v0006, v0392)) goto v0119;
    v0392 = stack[-11];
    stack[-1] = v0392;
    goto v0122;

v0122:
    v0392 = (Lisp_Object)17; /* 1 */
    stack[0] = v0392;
    goto v0121;

v0121:
    v0006 = stack[-1];
    v0392 = stack[0];
    v0392 = difference2(v0006, v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    v0392 = Lminusp(nil, v0392);
    env = stack[-14];
    if (v0392 == nil) goto v0096;
    v0392 = stack[-11];
    v0006 = add1(v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    v0392 = stack[-12];
    v0392 = qcdr(v0392);
    v0392 = qcdr(v0392);
    v0392 = qcar(v0392);
    v0392 = qcdr(v0392);
    v0392 = qcar(v0392);
    if (!(equal(v0006, v0392))) { Lisp_Object res = stack[-12]; popv(15); return onevalue(res); }
    stack[0] = stack[-12];
    v0392 = stack[-11];
    v0392 = add1(v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    v0424 = list2(stack[0], v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    v0125 = qvalue(elt(env, 1)); /* nil */
    v0006 = stack[-12];
    v0392 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* letmtr3 */
    v0392 = (*qfnn(fn))(qenv(fn), 4, v0424, v0125, v0006, v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    { Lisp_Object res = stack[-12]; popv(15); return onevalue(res); }

v0096:
    v0006 = stack[-12];
    v0392 = stack[0];
    fn = elt(env, 3); /* findrow */
    v0392 = (*qfn2(fn))(qenv(fn), v0006, v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    v0006 = v0392;
    v0392 = v0006;
    if (v0392 == nil) goto v0500;
    v0392 = v0006;
    v0392 = qcdr(v0392);
    stack[-7] = v0392;
    v0392 = stack[0];
    stack[-3] = v0392;
    v0006 = stack[-13];
    v0392 = stack[-10];
    if (!(equal(v0006, v0392))) goto v0501;
    v0392 = stack[-13];
    v0392 = add1(v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    stack[-13] = v0392;
    goto v0501;

v0501:
    v0006 = stack[-3];
    v0392 = stack[-13];
    if (equal(v0006, v0392)) goto v0148;
    v0392 = stack[-13];
    v0392 = add1(v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    stack[-13] = v0392;
    v0392 = stack[-2];
    v0392 = add1(v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    stack[-2] = v0392;
    goto v0404;

v0404:
    v0392 = stack[0];
    v0392 = add1(v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    stack[0] = v0392;
    goto v0121;

v0148:
    v0392 = (Lisp_Object)17; /* 1 */
    stack[-4] = v0392;
    v0392 = (Lisp_Object)17; /* 1 */
    stack[-8] = v0392;
    v0392 = qvalue(elt(env, 1)); /* nil */
    stack[-5] = v0392;
    goto v0042;

v0042:
    v0392 = stack[-7];
    if (v0392 == nil) goto v0502;
    stack[-3] = stack[-4];
    v0392 = stack[-11];
    v0392 = add1(v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    if (equal(stack[-3], v0392)) goto v0502;
    v0392 = stack[-7];
    v0392 = qcar(v0392);
    v0006 = v0392;
    v0392 = v0006;
    v0392 = qcar(v0392);
    stack[-6] = v0392;
    v0392 = v0006;
    v0392 = qcdr(v0392);
    stack[-3] = v0392;
    v0006 = stack[-4];
    v0392 = stack[-9];
    if (!(equal(v0006, v0392))) goto v0503;
    v0392 = stack[-8];
    v0392 = add1(v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    stack[-8] = v0392;
    goto v0503;

v0503:
    v0006 = stack[-6];
    v0392 = stack[-8];
    if (equal(v0006, v0392)) goto v0504;
    v0392 = stack[-8];
    v0392 = add1(v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    stack[-8] = v0392;
    v0392 = stack[-4];
    v0392 = add1(v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    stack[-4] = v0392;
    goto v0042;

v0504:
    v0125 = stack[-4];
    v0006 = stack[-3];
    v0392 = stack[-5];
    v0392 = acons(v0125, v0006, v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    stack[-5] = v0392;
    v0392 = stack[-4];
    v0392 = add1(v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    stack[-4] = v0392;
    v0392 = stack[-7];
    v0392 = qcdr(v0392);
    stack[-7] = v0392;
    v0392 = stack[-8];
    v0392 = add1(v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    stack[-8] = v0392;
    goto v0042;

v0502:
    v0006 = stack[-12];
    v0392 = stack[-2];
    stack[-4] = list2(v0006, v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    v0392 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = ncons(v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    v0392 = stack[-5];
    v0392 = Lreverse(nil, v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    v0125 = cons(stack[-3], v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    v0006 = stack[-12];
    v0392 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* letmtr3 */
    v0392 = (*qfnn(fn))(qenv(fn), 4, stack[-4], v0125, v0006, v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    v0392 = stack[-2];
    v0392 = add1(v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    stack[-2] = v0392;
    v0392 = stack[-13];
    v0392 = add1(v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    stack[-13] = v0392;
    goto v0404;

v0500:
    v0392 = stack[-13];
    v0392 = add1(v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    stack[-13] = v0392;
    goto v0404;

v0119:
    v0392 = stack[-11];
    v0392 = add1(v0392);
    nil = C_nil;
    if (exception_pending()) goto v0499;
    env = stack[-14];
    stack[-1] = v0392;
    goto v0122;
/* error exit handlers */
v0499:
    popv(15);
    return nil;
}



/* Code for dipretimes */

static Lisp_Object CC_dipretimes(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0077, v0086, v0087;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipretimes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0086 = v0000;
/* end of prologue */

v0059:
    v0077 = v0086;
    v0087 = qcar(v0077);
    v0077 = (Lisp_Object)17; /* 1 */
    if (v0087 == v0077) goto v0120;
    v0077 = v0086;
    v0077 = qcdr(v0077);
    if (v0077 == nil) goto v0119;
    v0077 = elt(env, 1); /* times */
    return cons(v0077, v0086);

v0119:
    v0077 = v0086;
    v0077 = qcar(v0077);
    return onevalue(v0077);

v0120:
    v0077 = v0086;
    v0077 = qcdr(v0077);
    if (v0077 == nil) goto v0081;
    v0077 = v0086;
    v0077 = qcdr(v0077);
    v0086 = v0077;
    goto v0059;

v0081:
    v0077 = (Lisp_Object)17; /* 1 */
    return onevalue(v0077);
}



/* Code for weak_xreduce1 */

static Lisp_Object MS_CDECL CC_weak_xreduce1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0139, v0168;
    Lisp_Object fn;
    Lisp_Object v0005, v0083, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "weak_xreduce1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0083 = va_arg(aa, Lisp_Object);
    v0005 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for weak_xreduce1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0005,v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0083,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0005;
    stack[-4] = v0083;
    stack[-5] = v0000;
/* end of prologue */
    v0030 = stack[-4];
    stack[0] = v0030;
    goto v0085;

v0085:
    v0030 = stack[-5];
    if (v0030 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v0030 = stack[0];
    if (v0030 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v0030 = stack[0];
    v0030 = qcar(v0030);
    stack[-6] = v0030;
    v0030 = stack[0];
    v0030 = qcdr(v0030);
    stack[0] = v0030;
    v0030 = stack[-6];
    fn = elt(env, 8); /* xval */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    v0030 = stack[-5];
    fn = elt(env, 8); /* xval */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    fn = elt(env, 9); /* xdiv */
    v0030 = (*qfn2(fn))(qenv(fn), stack[-1], v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    stack[-1] = v0030;
    if (v0030 == nil) goto v0085;
    v0030 = stack[-1];
    fn = elt(env, 10); /* mknwedge */
    v0168 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    v0139 = (Lisp_Object)17; /* 1 */
    v0030 = (Lisp_Object)17; /* 1 */
    v0030 = list2star(v0168, v0139, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    v0030 = ncons(v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    stack[-1] = v0030;
    v0139 = stack[-1];
    v0030 = stack[-6];
    fn = elt(env, 11); /* wedgepf */
    v0030 = (*qfn2(fn))(qenv(fn), v0139, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    stack[0] = v0030;
    v0030 = stack[-5];
    v0030 = qcar(v0030);
    v0139 = qcdr(v0030);
    v0030 = stack[0];
    v0030 = qcar(v0030);
    v0030 = qcdr(v0030);
    fn = elt(env, 12); /* quotsq */
    v0030 = (*qfn2(fn))(qenv(fn), v0139, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    stack[-2] = v0030;
    v0030 = stack[-2];
    fn = elt(env, 13); /* negsq */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    fn = elt(env, 14); /* multpfsq */
    v0030 = (*qfn2(fn))(qenv(fn), stack[0], v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    fn = elt(env, 15); /* addpf */
    v0030 = (*qfn2(fn))(qenv(fn), stack[-5], v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    fn = elt(env, 16); /* subs2pf */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    stack[-5] = v0030;
    v0030 = qvalue(elt(env, 2)); /* !*trxmod */
    if (v0030 == nil) goto v0148;
    stack[0] = stack[-3];
    v0139 = stack[-1];
    v0030 = stack[-2];
    fn = elt(env, 14); /* multpfsq */
    v0139 = (*qfn2(fn))(qenv(fn), v0139, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    v0030 = stack[-6];
    v0030 = list2(v0139, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    v0030 = ncons(v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    v0030 = Lnconc(nil, stack[0], v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    stack[-3] = v0030;
    goto v0148;

v0148:
    v0030 = qvalue(elt(env, 2)); /* !*trxmod */
    if (v0030 == nil) goto v0403;
    v0139 = elt(env, 3); /* "   " */
    v0030 = elt(env, 4); /* first */
    fn = elt(env, 17); /* writepri */
    v0030 = (*qfn2(fn))(qenv(fn), v0139, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    stack[0] = elt(env, 5); /* wedge */
    v0139 = stack[-1];
    v0030 = stack[-2];
    fn = elt(env, 14); /* multpfsq */
    v0030 = (*qfn2(fn))(qenv(fn), v0139, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    fn = elt(env, 18); /* preppf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    v0030 = stack[-6];
    fn = elt(env, 18); /* preppf */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    v0030 = list3(stack[0], stack[-1], v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    v0139 = Lmkquote(nil, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    v0030 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 17); /* writepri */
    v0030 = (*qfn2(fn))(qenv(fn), v0139, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    v0139 = elt(env, 6); /* " +" */
    v0030 = elt(env, 7); /* last */
    fn = elt(env, 17); /* writepri */
    v0030 = (*qfn2(fn))(qenv(fn), v0139, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-7];
    goto v0403;

v0403:
    v0030 = stack[-4];
    stack[0] = v0030;
    goto v0085;
/* error exit handlers */
v0028:
    popv(8);
    return nil;
}



/* Code for is_buble */

static Lisp_Object CC_is_buble(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0083)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for is_buble");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0083);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0083;
    stack[-1] = v0000;
/* end of prologue */
    v0108 = stack[-1];
    v0088 = stack[0];
    fn = elt(env, 2); /* diff_vertex */
    v0088 = (*qfn2(fn))(qenv(fn), v0108, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-3];
    v0088 = Llength(nil, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-3];
    stack[-2] = v0088;
    v0108 = stack[-2];
    v0088 = (Lisp_Object)33; /* 2 */
    v0088 = (Lisp_Object)geq2(v0108, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    v0088 = v0088 ? lisp_true : nil;
    env = stack[-3];
    if (v0088 == nil) goto v0093;
    v0088 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0088); }

v0093:
    v0108 = (Lisp_Object)33; /* 2 */
    v0088 = stack[-2];
    stack[-2] = times2(v0108, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-3];
    v0088 = stack[0];
    v0088 = ncons(v0088);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    {
        Lisp_Object v0054 = stack[-2];
        Lisp_Object v0053 = stack[-1];
        popv(4);
        return list2star(v0054, v0053, v0088);
    }
/* error exit handlers */
v0151:
    popv(4);
    return nil;
}



/* Code for quotexf!* */

static Lisp_Object CC_quotexfH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0083)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotexf*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0083);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0083;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0111;

v0111:
    v0049 = stack[-2];
    if (v0049 == nil) goto v0059;
    v0049 = stack[-2];
    v0049 = qcar(v0049);
    stack[0] = qcar(v0049);
    v0049 = stack[-2];
    v0049 = qcar(v0049);
    v0050 = qcdr(v0049);
    v0049 = stack[-1];
    fn = elt(env, 1); /* quotfexf!*1 */
    v0050 = (*qfn2(fn))(qenv(fn), v0050, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-4];
    v0049 = stack[-3];
    v0049 = acons(stack[0], v0050, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-4];
    stack[-3] = v0049;
    v0049 = stack[-2];
    v0049 = qcdr(v0049);
    stack[-2] = v0049;
    goto v0111;

v0059:
    v0049 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0049);
    }
/* error exit handlers */
v0087:
    popv(5);
    return nil;
}



/* Code for actual_arguments */

static Lisp_Object CC_actual_arguments(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0080, v0081;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for actual_arguments");
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
    v0080 = v0000;
/* end of prologue */
    v0081 = elt(env, 1); /* list */
    v0082 = v0080;
    v0082 = qcdr(v0082);
    if (!(v0082 == nil)) goto v0111;
    v0082 = v0080;
    v0080 = qcar(v0082);
    v0082 = elt(env, 2); /* generic_function */
    v0082 = get(v0080, v0082);
    goto v0111;

v0111:
    return cons(v0081, v0082);
}



/* Code for fs!:prin!: */

static Lisp_Object CC_fsTprinT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:prin:");
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
    v0059 = elt(env, 1); /* "[" */
    fn = elt(env, 3); /* prin2!* */
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-1];
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    fn = elt(env, 4); /* fs!:prin */
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-1];
    v0059 = elt(env, 2); /* "]" */
    {
        popv(2);
        fn = elt(env, 3); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0059);
    }
/* error exit handlers */
v0064:
    popv(2);
    return nil;
}



/* Code for split!-further */

static Lisp_Object MS_CDECL CC_splitKfurther(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0027, v0521, v0025, v0135;
    Lisp_Object fn;
    Lisp_Object v0005, v0083, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "split-further");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0083 = va_arg(aa, Lisp_Object);
    v0005 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for split-further");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0005,v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0083,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0005;
    stack[-2] = v0083;
    stack[-3] = v0000;
/* end of prologue */
    v0027 = stack[-3];
    if (v0027 == nil) goto v0111;
    v0027 = stack[-3];
    v0025 = qcdr(v0027);
    v0521 = stack[-2];
    v0027 = stack[-1];
    v0027 = CC_splitKfurther(env, 3, v0025, v0521, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-5];
    stack[-4] = v0027;
    v0027 = stack[-4];
    v0027 = qcdr(v0027);
    stack[0] = v0027;
    v0027 = stack[-4];
    v0027 = qcar(v0027);
    stack[-4] = v0027;
    v0521 = qvalue(elt(env, 2)); /* number!-needed */
    v0027 = (Lisp_Object)1; /* 0 */
    if (v0521 == v0027) goto v0158;
    v0025 = stack[-2];
    v0521 = stack[-1];
    v0027 = qvalue(elt(env, 3)); /* work!-vector1 */
    fn = elt(env, 8); /* copy!-vector */
    v0027 = (*qfnn(fn))(qenv(fn), 3, v0025, v0521, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-5];
    qvalue(elt(env, 4)) = v0027; /* dwork1 */
    v0027 = stack[-3];
    v0027 = qcar(v0027);
    v0025 = qcar(v0027);
    v0027 = stack[-3];
    v0027 = qcar(v0027);
    v0521 = qcdr(v0027);
    v0027 = qvalue(elt(env, 5)); /* work!-vector2 */
    fn = elt(env, 8); /* copy!-vector */
    v0027 = (*qfnn(fn))(qenv(fn), 3, v0025, v0521, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-5];
    qvalue(elt(env, 6)) = v0027; /* dwork2 */
    v0135 = qvalue(elt(env, 3)); /* work!-vector1 */
    v0025 = qvalue(elt(env, 4)); /* dwork1 */
    v0521 = qvalue(elt(env, 5)); /* work!-vector2 */
    v0027 = qvalue(elt(env, 6)); /* dwork2 */
    fn = elt(env, 9); /* gcd!-in!-vector */
    v0027 = (*qfnn(fn))(qenv(fn), 4, v0135, v0025, v0521, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-5];
    qvalue(elt(env, 4)) = v0027; /* dwork1 */
    v0521 = qvalue(elt(env, 4)); /* dwork1 */
    v0027 = (Lisp_Object)1; /* 0 */
    if (v0521 == v0027) goto v0179;
    v0521 = qvalue(elt(env, 4)); /* dwork1 */
    v0027 = stack[-3];
    v0027 = qcar(v0027);
    v0027 = qcdr(v0027);
    v0027 = (equal(v0521, v0027) ? lisp_true : nil);
    goto v0497;

v0497:
    if (!(v0027 == nil)) goto v0158;
    v0027 = stack[-3];
    v0027 = qcar(v0027);
    v0025 = qcar(v0027);
    v0027 = stack[-3];
    v0027 = qcar(v0027);
    v0521 = qcdr(v0027);
    v0027 = qvalue(elt(env, 5)); /* work!-vector2 */
    fn = elt(env, 8); /* copy!-vector */
    v0027 = (*qfnn(fn))(qenv(fn), 3, v0025, v0521, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-5];
    qvalue(elt(env, 6)) = v0027; /* dwork2 */
    v0135 = qvalue(elt(env, 5)); /* work!-vector2 */
    v0025 = qvalue(elt(env, 6)); /* dwork2 */
    v0521 = qvalue(elt(env, 3)); /* work!-vector1 */
    v0027 = qvalue(elt(env, 4)); /* dwork1 */
    fn = elt(env, 10); /* quotfail!-in!-vector */
    v0027 = (*qfnn(fn))(qenv(fn), 4, v0135, v0025, v0521, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-5];
    qvalue(elt(env, 6)) = v0027; /* dwork2 */
    v0027 = qvalue(elt(env, 4)); /* dwork1 */
    v0027 = Lmkvect(nil, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-5];
    stack[-1] = v0027;
    v0025 = qvalue(elt(env, 3)); /* work!-vector1 */
    v0521 = qvalue(elt(env, 4)); /* dwork1 */
    v0027 = stack[-1];
    fn = elt(env, 8); /* copy!-vector */
    v0027 = (*qfnn(fn))(qenv(fn), 3, v0025, v0521, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-5];
    v0025 = stack[-1];
    v0521 = qvalue(elt(env, 4)); /* dwork1 */
    v0027 = stack[-4];
    v0027 = acons(v0025, v0521, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-5];
    stack[-4] = v0027;
    stack[-2] = qvalue(elt(env, 5)); /* work!-vector2 */
    stack[-1] = qvalue(elt(env, 6)); /* dwork2 */
    v0027 = qvalue(elt(env, 6)); /* dwork2 */
    v0027 = Lmkvect(nil, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-5];
    stack[-3] = v0027;
    fn = elt(env, 8); /* copy!-vector */
    v0027 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v0027);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-5];
    v0025 = stack[-3];
    v0521 = qvalue(elt(env, 6)); /* dwork2 */
    v0027 = stack[0];
    v0027 = acons(v0025, v0521, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-5];
    stack[0] = v0027;
    v0027 = qvalue(elt(env, 2)); /* number!-needed */
    v0027 = (Lisp_Object)((int32_t)(v0027) - 0x10);
    qvalue(elt(env, 2)) = v0027; /* number!-needed */
    v0521 = stack[-4];
    v0027 = stack[0];
    popv(6);
    return cons(v0521, v0027);

v0158:
    v0025 = stack[-4];
    v0027 = stack[-3];
    v0521 = qcar(v0027);
    v0027 = stack[0];
    popv(6);
    return list2star(v0025, v0521, v0027);

v0179:
    v0027 = qvalue(elt(env, 7)); /* t */
    goto v0497;

v0111:
    v0027 = qvalue(elt(env, 1)); /* nil */
    popv(6);
    return ncons(v0027);
/* error exit handlers */
v0159:
    popv(6);
    return nil;
}



/* Code for subtractinds */

static Lisp_Object MS_CDECL CC_subtractinds(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0186, v0057;
    Lisp_Object v0005, v0083, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subtractinds");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0083 = va_arg(aa, Lisp_Object);
    v0005 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subtractinds");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0005,v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0083,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0005;
    stack[-2] = v0083;
    stack[-3] = v0000;
/* end of prologue */

v0118:
    v0186 = stack[-2];
    if (v0186 == nil) goto v0064;
    v0186 = stack[-3];
    v0057 = qcar(v0186);
    v0186 = stack[-2];
    v0186 = qcar(v0186);
    v0186 = qcar(v0186);
    v0057 = difference2(v0057, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-5];
    v0186 = (Lisp_Object)1; /* 0 */
    v0186 = (Lisp_Object)lessp2(v0057, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    v0186 = v0186 ? lisp_true : nil;
    env = stack[-5];
    if (v0186 == nil) goto v0093;
    v0186 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0186); }

v0093:
    v0186 = stack[-3];
    v0186 = qcdr(v0186);
    stack[-4] = v0186;
    v0186 = stack[-2];
    v0186 = qcdr(v0186);
    stack[0] = v0186;
    v0186 = stack[-3];
    v0057 = qcar(v0186);
    v0186 = stack[-2];
    v0186 = qcar(v0186);
    v0186 = qcar(v0186);
    v0057 = difference2(v0057, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-5];
    v0186 = stack[-1];
    v0186 = cons(v0057, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-5];
    stack[-1] = v0186;
    v0186 = stack[0];
    stack[-2] = v0186;
    v0186 = stack[-4];
    stack[-3] = v0186;
    goto v0118;

v0064:
    v0186 = stack[-1];
        popv(6);
        return Lnreverse(nil, v0186);
/* error exit handlers */
v0182:
    popv(6);
    return nil;
}



/* Code for change!+int!+to!+sq */

static Lisp_Object CC_changeLintLtoLsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090, v0084;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for change+int+to+sq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0090 = v0000;
/* end of prologue */
    v0084 = v0090;
    v0090 = (Lisp_Object)17; /* 1 */
    return cons(v0084, v0090);
}



/* Code for mri_ofsf2mri */

static Lisp_Object CC_mri_ofsf2mri(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0083)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_ofsf2mri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0083);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0104 = v0083;
    v0105 = v0000;
/* end of prologue */
    stack[-1] = v0105;
    stack[0] = elt(env, 1); /* mri_ofsf2mriat */
    v0104 = ncons(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    {
        Lisp_Object v0067 = stack[-1];
        Lisp_Object v0066 = stack[0];
        popv(3);
        fn = elt(env, 2); /* cl_apply2ats1 */
        return (*qfnn(fn))(qenv(fn), 3, v0067, v0066, v0104);
    }
/* error exit handlers */
v0058:
    popv(3);
    return nil;
}



/* Code for qqe_simplqneq */

static Lisp_Object CC_qqe_simplqneq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0083)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0522, v0404, v0523;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_simplqneq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0083);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0404 = v0083;
    v0522 = v0000;
/* end of prologue */
    v0404 = v0522;
    v0404 = qcdr(v0404);
    v0404 = qcar(v0404);
    v0522 = qcdr(v0522);
    v0522 = qcdr(v0522);
    v0522 = qcar(v0522);
    v0523 = elt(env, 1); /* qequal */
    fn = elt(env, 6); /* qqe_mk2 */
    v0404 = (*qfnn(fn))(qenv(fn), 3, v0523, v0404, v0522);
    nil = C_nil;
    if (exception_pending()) goto v0524;
    env = stack[-3];
    v0522 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 7); /* qqe_simplqequal */
    v0522 = (*qfn2(fn))(qenv(fn), v0404, v0522);
    nil = C_nil;
    if (exception_pending()) goto v0524;
    env = stack[-3];
    stack[-2] = v0522;
    v0404 = stack[-2];
    v0522 = elt(env, 3); /* true */
    if (v0404 == v0522) goto v0152;
    v0404 = stack[-2];
    v0522 = elt(env, 4); /* false */
    if (v0404 == v0522) goto v0108;
    stack[-1] = elt(env, 5); /* qneq */
    v0522 = stack[-2];
    fn = elt(env, 8); /* qqe_arg2l */
    stack[0] = (*qfn1(fn))(qenv(fn), v0522);
    nil = C_nil;
    if (exception_pending()) goto v0524;
    env = stack[-3];
    v0522 = stack[-2];
    fn = elt(env, 9); /* qqe_arg2r */
    v0522 = (*qfn1(fn))(qenv(fn), v0522);
    nil = C_nil;
    if (exception_pending()) goto v0524;
    env = stack[-3];
    fn = elt(env, 6); /* qqe_mk2 */
    v0522 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0522);
    nil = C_nil;
    if (exception_pending()) goto v0524;
    { popv(4); return onevalue(v0522); }

v0108:
    v0522 = elt(env, 3); /* true */
    { popv(4); return onevalue(v0522); }

v0152:
    v0522 = elt(env, 4); /* false */
    { popv(4); return onevalue(v0522); }
/* error exit handlers */
v0524:
    popv(4);
    return nil;
}



/* Code for pasf_leqp */

static Lisp_Object CC_pasf_leqp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0083)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0150, v0513, v0045, v0046;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_leqp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0083);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0513 = v0083;
    v0045 = v0000;
/* end of prologue */
    v0150 = v0045;
    if (!(v0150 == nil)) goto v0111;
    v0150 = (Lisp_Object)1; /* 0 */
    v0045 = v0150;
    goto v0111;

v0111:
    v0150 = v0513;
    if (!(v0150 == nil)) goto v0081;
    v0150 = (Lisp_Object)1; /* 0 */
    v0513 = v0150;
    goto v0081;

v0081:
    v0046 = v0045;
    v0150 = elt(env, 1); /* minf */
    if (v0046 == v0150) goto v0082;
    v0046 = v0513;
    v0150 = elt(env, 3); /* pinf */
    if (v0046 == v0150) goto v0093;
    v0046 = v0045;
    v0150 = elt(env, 3); /* pinf */
    if (v0046 == v0150) goto v0043;
    v0046 = v0513;
    v0150 = elt(env, 1); /* minf */
    if (v0046 == v0150) goto v0526;
    v0150 = v0045;
    v0150 = (Lisp_Object)lesseq2(v0150, v0513);
    nil = C_nil;
    if (exception_pending()) goto v0527;
    v0150 = v0150 ? lisp_true : nil;
    env = stack[0];
    goto v0095;

v0095:
    if (v0150 == nil) goto v0067;
    v0150 = qvalue(elt(env, 2)); /* t */
    { popv(1); return onevalue(v0150); }

v0067:
    v0150 = nil;
    { popv(1); return onevalue(v0150); }

v0526:
    v0150 = qvalue(elt(env, 4)); /* nil */
    goto v0095;

v0043:
    v0150 = qvalue(elt(env, 4)); /* nil */
    goto v0095;

v0093:
    v0150 = qvalue(elt(env, 2)); /* t */
    goto v0095;

v0082:
    v0150 = qvalue(elt(env, 2)); /* t */
    goto v0095;
/* error exit handlers */
v0527:
    popv(1);
    return nil;
}



/* Code for diford */

static Lisp_Object CC_diford(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diford");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0111 = v0000;
/* end of prologue */
    v0111 = qcdr(v0111);
    v0111 = qcdr(v0111);
    {
        fn = elt(env, 1); /* lengthn */
        return (*qfn1(fn))(qenv(fn), v0111);
    }
}



/* Code for greatertype */

static Lisp_Object CC_greatertype(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0083)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0516, v0530, v0493;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for greatertype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0083);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0083;
    stack[-6] = v0000;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v0516 = qvalue(elt(env, 1)); /* optlang!* */
    if (v0516 == nil) goto v0080;
    v0516 = qvalue(elt(env, 1)); /* optlang!* */
    v0530 = v0516;
    goto v0104;

v0104:
    v0516 = elt(env, 3); /* conversion */
    v0516 = get(v0530, v0516);
    env = stack[-8];
    fn = elt(env, 6); /* eval */
    v0516 = (*qfn1(fn))(qenv(fn), v0516);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    stack[-7] = v0516;
    v0516 = stack[-7];
    v0530 = qcar(v0516);
    v0516 = stack[-5];
    if (equal(v0530, v0516)) goto v0107;
    v0516 = stack[-7];
    v0530 = qcar(v0516);
    v0516 = stack[-6];
    if (!(equal(v0530, v0516))) goto v0052;
    v0516 = qvalue(elt(env, 5)); /* nil */
    stack[-1] = v0516;
    { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }

v0052:
    v0516 = stack[-7];
    v0516 = qcdr(v0516);
    stack[-7] = v0516;
    if (v0516 == nil) { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }
    v0516 = stack[-4];
    if (!(v0516 == nil)) { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }
    v0516 = stack[-7];
    v0516 = qcar(v0516);
    v0493 = v0516;
    goto v0520;

v0520:
    v0516 = v0493;
    if (v0516 == nil) goto v0182;
    v0516 = stack[-2];
    if (!(v0516 == nil)) goto v0182;
    v0516 = v0493;
    v0530 = qcar(v0516);
    v0516 = stack[-6];
    if (!(equal(v0530, v0516))) goto v0405;
    v0516 = qvalue(elt(env, 4)); /* t */
    stack[-3] = v0516;
    goto v0405;

v0405:
    v0516 = v0493;
    v0530 = qcar(v0516);
    v0516 = stack[-5];
    if (equal(v0530, v0516)) goto v0147;
    v0516 = v0493;
    v0516 = qcdr(v0516);
    v0493 = v0516;
    goto v0520;

v0147:
    v0516 = qvalue(elt(env, 4)); /* t */
    stack[-2] = v0516;
    goto v0520;

v0182:
    v0516 = stack[-2];
    if (v0516 == nil) goto v0040;
    v0516 = v0493;
    v0516 = qcdr(v0516);
    v0493 = v0516;
    goto v0418;

v0418:
    v0516 = v0493;
    if (v0516 == nil) goto v0040;
    v0516 = stack[-1];
    if (!(v0516 == nil)) goto v0040;
    v0516 = v0493;
    v0530 = qcar(v0516);
    v0516 = stack[-6];
    if (equal(v0530, v0516)) goto v0131;
    v0516 = v0493;
    v0516 = qcdr(v0516);
    v0493 = v0516;
    goto v0418;

v0131:
    v0516 = qvalue(elt(env, 4)); /* t */
    stack[-1] = v0516;
    stack[-3] = v0516;
    goto v0418;

v0040:
    v0516 = stack[-3];
    if (v0516 == nil) goto v0506;
    v0516 = stack[-2];
    if (!(v0516 == nil)) goto v0506;

v0495:
    stack[0] = (Lisp_Object)65; /* 4 */
    v0530 = stack[-6];
    v0516 = stack[-5];
    v0516 = cons(v0530, v0516);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    fn = elt(env, 7); /* typerror */
    v0516 = (*qfn2(fn))(qenv(fn), stack[0], v0516);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-8];
    goto v0052;

v0506:
    v0516 = stack[-3];
    if (v0516 == nil) goto v0507;
    v0516 = qvalue(elt(env, 5)); /* nil */
    goto v0504;

v0504:
    if (!(v0516 == nil)) goto v0495;
    v0516 = stack[-3];
    if (v0516 == nil) goto v0052;
    v0516 = stack[-2];
    if (v0516 == nil) goto v0052;
    v0516 = qvalue(elt(env, 4)); /* t */
    stack[-4] = v0516;
    goto v0052;

v0507:
    v0516 = stack[-2];
    goto v0504;

v0107:
    v0516 = qvalue(elt(env, 4)); /* t */
    stack[-1] = v0516;
    { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }

v0080:
    v0516 = elt(env, 2); /* fortran */
    v0530 = v0516;
    goto v0104;
/* error exit handlers */
v0170:
    popv(9);
    return nil;
}



/* Code for newvar */

static Lisp_Object CC_newvar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0112, v0107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for newvar");
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
    v0112 = stack[0];
    if (symbolp(v0112)) goto v0067;
    v0107 = stack[0];
    v0112 = elt(env, 1); /* "free variable" */
    {
        popv(3);
        fn = elt(env, 3); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0107, v0112);
    }

v0067:
    v0112 = elt(env, 2); /* != */
    stack[-1] = Lexplode(nil, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-2];
    v0112 = stack[0];
    v0112 = Lexplode(nil, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-2];
    v0112 = Lappend(nil, stack[-1], v0112);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-2];
    v0112 = Lcompress(nil, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0079;
        popv(3);
        return Lintern(nil, v0112);
/* error exit handlers */
v0079:
    popv(3);
    return nil;
}



/* Code for divide!-by!-power!-of!-ten */

static Lisp_Object CC_divideKbyKpowerKofKten(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0083)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0524, v0407, v0043;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for divide-by-power-of-ten");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0083,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0083);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0083;
    stack[-1] = v0000;
/* end of prologue */
    v0407 = stack[0];
    v0524 = (Lisp_Object)1; /* 0 */
    v0524 = (Lisp_Object)lessp2(v0407, v0524);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    v0524 = v0524 ? lisp_true : nil;
    env = stack[-3];
    if (v0524 == nil) goto v0103;
    v0524 = elt(env, 0); /* divide!-by!-power!-of!-ten */
    {
        popv(4);
        fn = elt(env, 4); /* bflerrmsg */
        return (*qfn1(fn))(qenv(fn), v0524);
    }

v0103:
    v0524 = qvalue(elt(env, 1)); /* bften!* */
    stack[-2] = v0524;
    goto v0112;

v0112:
    v0407 = stack[0];
    v0524 = (Lisp_Object)1; /* 0 */
    v0524 = (Lisp_Object)greaterp2(v0407, v0524);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    v0524 = v0524 ? lisp_true : nil;
    env = stack[-3];
    if (v0524 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0524 = stack[0];
    v0524 = Levenp(nil, v0524);
    env = stack[-3];
    if (!(v0524 == nil)) goto v0052;
    v0043 = stack[-1];
    v0407 = stack[-2];
    v0524 = qvalue(elt(env, 3)); /* !:bprec!: */
    fn = elt(env, 5); /* divide!: */
    v0524 = (*qfnn(fn))(qenv(fn), 3, v0043, v0407, v0524);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    fn = elt(env, 6); /* normbf */
    v0524 = (*qfn1(fn))(qenv(fn), v0524);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    stack[-1] = v0524;
    goto v0052;

v0052:
    v0407 = stack[0];
    v0524 = (Lisp_Object)-15; /* -1 */
    v0524 = ash(v0407, v0524);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    stack[0] = v0524;
    v0407 = stack[-2];
    v0524 = stack[-2];
    fn = elt(env, 7); /* times!: */
    v0407 = (*qfn2(fn))(qenv(fn), v0407, v0524);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    v0524 = qvalue(elt(env, 3)); /* !:bprec!: */
    fn = elt(env, 8); /* cut!:mt */
    v0524 = (*qfn2(fn))(qenv(fn), v0407, v0524);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    fn = elt(env, 6); /* normbf */
    v0524 = (*qfn1(fn))(qenv(fn), v0524);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    stack[-2] = v0524;
    goto v0112;
/* error exit handlers */
v0150:
    popv(4);
    return nil;
}



/* Code for mk_parents_prim */

static Lisp_Object CC_mk_parents_prim(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0152, v0117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk_parents_prim");
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
    v0152 = stack[0];
    v0117 = Llength(nil, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-1];
    v0152 = (Lisp_Object)49; /* 3 */
    if (!(v0117 == v0152)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0152 = stack[0];
    fn = elt(env, 1); /* s_noparents */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-1];
    v0117 = v0152;
    if (v0117 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0117 = stack[0];
    v0152 = qcar(v0152);
    fn = elt(env, 2); /* mk_edge_parents */
    v0152 = (*qfn2(fn))(qenv(fn), v0117, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0050:
    popv(2);
    return nil;
}



/* Code for mo_zero!? */

static Lisp_Object CC_mo_zeroW(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_zero?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0012 = v0000;
/* end of prologue */
    v0012 = qcar(v0012);
    {
        fn = elt(env, 1); /* mo!=zero */
        return (*qfn1(fn))(qenv(fn), v0012);
    }
}



setup_type const u34_setup[] =
{
    {"physoppri",               CC_physoppri,   too_many_1,    wrong_no_1},
    {"strand-alg-top",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_strandKalgKtop},
    {"pst_mkpst",               CC_pst_mkpst,   too_many_1,    wrong_no_1},
    {"add-factor",              too_few_2,      CC_addKfactor, wrong_no_2},
    {"pasf_premf",              too_few_2,      CC_pasf_premf, wrong_no_2},
    {"ofsf_ordatp",             too_few_2,      CC_ofsf_ordatp,wrong_no_2},
    {"dvfsf_ppolyp",            CC_dvfsf_ppolyp,too_many_1,    wrong_no_1},
    {"gcdld",                   too_few_2,      CC_gcdld,      wrong_no_2},
    {"simpsqrtsq",              CC_simpsqrtsq,  too_many_1,    wrong_no_1},
    {"ldf-dep-var",             CC_ldfKdepKvar, too_many_1,    wrong_no_1},
    {"nestzerop:",              CC_nestzeropT,  too_many_1,    wrong_no_1},
    {"vdpcleanup",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpcleanup},
    {"remove_least_item",       CC_remove_least_item,too_many_1,wrong_no_1},
    {"applysetop",              too_few_2,      CC_applysetop, wrong_no_2},
    {"mkassign",                too_few_2,      CC_mkassign,   wrong_no_2},
    {"coeff_calc",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeff_calc},
    {"rfirst",                  CC_rfirst,      too_many_1,    wrong_no_1},
    {"set-weights",             CC_setKweights, too_many_1,    wrong_no_1},
    {"fs:minusp",               CC_fsTminusp,   too_many_1,    wrong_no_1},
    {"lesspcar",                too_few_2,      CC_lesspcar,   wrong_no_2},
    {"mkrootsq",                too_few_2,      CC_mkrootsq,   wrong_no_2},
    {"cl_bnfsimpl",             too_few_2,      CC_cl_bnfsimpl,wrong_no_2},
    {"diffp",                   too_few_2,      CC_diffp,      wrong_no_2},
    {"rewrite",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_rewrite},
    {"dipretimes",              CC_dipretimes,  too_many_1,    wrong_no_1},
    {"weak_xreduce1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_weak_xreduce1},
    {"is_buble",                too_few_2,      CC_is_buble,   wrong_no_2},
    {"quotexf*",                too_few_2,      CC_quotexfH,   wrong_no_2},
    {"actual_arguments",        CC_actual_arguments,too_many_1,wrong_no_1},
    {"fs:prin:",                CC_fsTprinT,    too_many_1,    wrong_no_1},
    {"split-further",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_splitKfurther},
    {"subtractinds",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_subtractinds},
    {"change+int+to+sq",        CC_changeLintLtoLsq,too_many_1,wrong_no_1},
    {"mri_ofsf2mri",            too_few_2,      CC_mri_ofsf2mri,wrong_no_2},
    {"qqe_simplqneq",           too_few_2,      CC_qqe_simplqneq,wrong_no_2},
    {"pasf_leqp",               too_few_2,      CC_pasf_leqp,  wrong_no_2},
    {"diford",                  CC_diford,      too_many_1,    wrong_no_1},
    {"greatertype",             too_few_2,      CC_greatertype,wrong_no_2},
    {"newvar",                  CC_newvar,      too_many_1,    wrong_no_1},
    {"divide-by-power-of-ten",  too_few_2,      CC_divideKbyKpowerKofKten,wrong_no_2},
    {"mk_parents_prim",         CC_mk_parents_prim,too_many_1, wrong_no_1},
    {"mo_zero?",                CC_mo_zeroW,    too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u34", (two_args *)"11721 1858893 5038728", 0}
};

/* end of generated code */
