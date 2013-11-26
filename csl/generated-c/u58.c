
/* $destdir/u58.c        Machine generated C code */

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


/* Code for wedge_pair */

static Lisp_Object CC_wedge_pair(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009, v0010;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wedge_pair");
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
    v0009 = qvalue(elt(env, 1)); /* !*twosided */
    if (v0009 == nil) goto v0011;
    v0009 = stack[0];
    v0009 = qcdr(v0009);
    v0009 = qcdr(v0009);
    v0009 = qcar(v0009);
    fn = elt(env, 2); /* xval */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    v0009 = stack[0];
    v0009 = qcdr(v0009);
    v0009 = qcdr(v0009);
    v0009 = qcdr(v0009);
    v0009 = qcar(v0009);
    fn = elt(env, 2); /* xval */
    v0009 = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    fn = elt(env, 3); /* xdiv */
    v0009 = (*qfn2(fn))(qenv(fn), stack[-1], v0009);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    if (!(v0009 == nil)) goto v0011;
    v0009 = stack[0];
    v0009 = qcdr(v0009);
    v0009 = qcdr(v0009);
    v0010 = qcar(v0009);
    v0009 = stack[0];
    v0009 = qcdr(v0009);
    v0009 = qcdr(v0009);
    v0009 = qcdr(v0009);
    v0009 = qcar(v0009);
    fn = elt(env, 4); /* wedgepf */
    v0010 = (*qfn2(fn))(qenv(fn), v0010, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    v0009 = stack[0];
    v0009 = qcdr(v0009);
    v0009 = qcdr(v0009);
    v0009 = qcar(v0009);
    {
        popv(3);
        fn = elt(env, 4); /* wedgepf */
        return (*qfn2(fn))(qenv(fn), v0010, v0009);
    }

v0011:
    v0009 = stack[0];
    v0009 = qcdr(v0009);
    v0009 = qcdr(v0009);
    v0010 = qcar(v0009);
    v0009 = stack[0];
    v0009 = qcdr(v0009);
    v0009 = qcdr(v0009);
    v0009 = qcdr(v0009);
    v0009 = qcar(v0009);
    {
        popv(3);
        fn = elt(env, 4); /* wedgepf */
        return (*qfn2(fn))(qenv(fn), v0010, v0009);
    }
/* error exit handlers */
v0012:
    popv(3);
    return nil;
}



/* Code for addm1 */

static Lisp_Object MS_CDECL CC_addm1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0026, v0027, v0028;
    Lisp_Object fn;
    Lisp_Object v0018, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "addm1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0017 = va_arg(aa, Lisp_Object);
    v0018 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addm1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0018,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0017,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0018;
    stack[-1] = v0017;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0029;

v0029:
    v0026 = stack[-2];
    if (v0026 == nil) goto v0030;
    v0026 = qvalue(elt(env, 1)); /* nil */
    goto v0031;

v0031:
    if (v0026 == nil) goto v0032;
    v0026 = stack[-3];
    {
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0026);
    }

v0032:
    v0026 = stack[-2];
    if (v0026 == nil) goto v0033;
    v0026 = stack[-1];
    v0026 = (v0026 == nil ? lisp_true : nil);
    goto v0034;

v0034:
    if (v0026 == nil) goto v0035;
    stack[0] = stack[-3];
    v0028 = elt(env, 3); /* matrix */
    v0027 = (Lisp_Object)129; /* 8 */
    v0026 = elt(env, 4); /* "Matrix mismatch" */
    fn = elt(env, 6); /* rerror */
    v0026 = (*qfnn(fn))(qenv(fn), 3, v0028, v0027, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    {
        Lisp_Object v0037 = stack[0];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0037, v0026);
    }

v0035:
    v0028 = stack[0];
    v0026 = stack[-2];
    v0027 = qcar(v0026);
    v0026 = stack[-1];
    v0026 = qcar(v0026);
    v0027 = Lapply2(nil, 3, v0028, v0027, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    v0026 = stack[-3];
    v0026 = cons(v0027, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    stack[-3] = v0026;
    v0026 = stack[-2];
    v0026 = qcdr(v0026);
    stack[-2] = v0026;
    v0026 = stack[-1];
    v0026 = qcdr(v0026);
    stack[-1] = v0026;
    goto v0029;

v0033:
    v0026 = qvalue(elt(env, 2)); /* t */
    goto v0034;

v0030:
    v0026 = stack[-1];
    v0026 = (v0026 == nil ? lisp_true : nil);
    goto v0031;
/* error exit handlers */
v0036:
    popv(5);
    return nil;
}



/* Code for !:pi */

static Lisp_Object CC_Tpi(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0092, v0093;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :pi");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0000;
/* end of prologue */
    v0092 = stack[-6];
    v0092 = integerp(v0092);
    if (v0092 == nil) goto v0094;
    v0093 = stack[-6];
    v0092 = (Lisp_Object)1; /* 0 */
    v0092 = (Lisp_Object)lesseq2(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    v0092 = v0092 ? lisp_true : nil;
    env = stack[-8];
    goto v0029;

v0029:
    if (v0092 == nil) goto v0096;
    v0092 = elt(env, 0); /* !:pi */
    {
        popv(9);
        fn = elt(env, 5); /* bflerrmsg */
        return (*qfn1(fn))(qenv(fn), v0092);
    }

v0096:
    v0093 = elt(env, 0); /* !:pi */
    v0092 = stack[-6];
    fn = elt(env, 6); /* get!:const */
    v0092 = (*qfn2(fn))(qenv(fn), v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    stack[0] = v0092;
    v0093 = stack[0];
    v0092 = elt(env, 2); /* not_found */
    if (!(v0093 == v0092)) { Lisp_Object res = stack[0]; popv(9); return onevalue(res); }
    stack[0] = (Lisp_Object)33; /* 2 */
    v0093 = stack[-6];
    v0092 = (Lisp_Object)49; /* 3 */
    v0092 = plus2(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    stack[-7] = v0092;
    v0093 = Lexpt(nil, stack[0], v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    v0092 = (Lisp_Object)81; /* 5 */
    v0092 = quot2(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    stack[-3] = v0092;
    stack[-5] = v0092;
    v0093 = (Lisp_Object)81; /* 5 */
    v0092 = (Lisp_Object)33; /* 2 */
    v0092 = Lexpt(nil, v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    v0092 = negate(v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    stack[-2] = v0092;
    v0092 = (Lisp_Object)17; /* 1 */
    stack[-4] = v0092;
    goto v0097;

v0097:
    v0093 = stack[-3];
    v0092 = (Lisp_Object)1; /* 0 */
    if (v0093 == v0092) goto v0098;
    v0093 = stack[-3];
    v0092 = stack[-2];
    v0092 = quot2(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    stack[-3] = v0092;
    stack[-1] = stack[-5];
    stack[0] = stack[-3];
    v0093 = stack[-4];
    v0092 = (Lisp_Object)33; /* 2 */
    v0092 = plus2(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    stack[-4] = v0092;
    v0092 = quot2(stack[0], v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    v0092 = plus2(stack[-1], v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    stack[-5] = v0092;
    goto v0097;

v0098:
    v0093 = (Lisp_Object)33; /* 2 */
    v0092 = stack[-7];
    v0093 = Lexpt(nil, v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    v0092 = (Lisp_Object)3825; /* 239 */
    v0092 = quot2(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    stack[-3] = v0092;
    stack[0] = v0092;
    v0093 = (Lisp_Object)3825; /* 239 */
    v0092 = (Lisp_Object)33; /* 2 */
    v0092 = Lexpt(nil, v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    v0092 = negate(v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    stack[-2] = v0092;
    v0092 = (Lisp_Object)17; /* 1 */
    stack[-4] = v0092;
    goto v0099;

v0099:
    v0093 = stack[-3];
    v0092 = (Lisp_Object)1; /* 0 */
    if (v0093 == v0092) goto v0100;
    v0093 = stack[-3];
    v0092 = stack[-2];
    v0092 = quot2(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    stack[-3] = v0092;
    stack[-1] = stack[0];
    stack[0] = stack[-3];
    v0093 = stack[-4];
    v0092 = (Lisp_Object)33; /* 2 */
    v0092 = plus2(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    stack[-4] = v0092;
    v0092 = quot2(stack[0], v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    v0092 = plus2(stack[-1], v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    stack[0] = v0092;
    goto v0099;

v0100:
    stack[-1] = elt(env, 4); /* !:rd!: */
    v0093 = (Lisp_Object)257; /* 16 */
    v0092 = stack[-5];
    stack[-2] = times2(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    v0093 = (Lisp_Object)65; /* 4 */
    v0092 = stack[0];
    v0092 = times2(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    stack[0] = difference2(stack[-2], v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    v0092 = stack[-7];
    v0092 = negate(v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    v0093 = list2star(stack[-1], stack[0], v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    v0092 = stack[-6];
    fn = elt(env, 7); /* round!:mt */
    v0092 = (*qfn2(fn))(qenv(fn), v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-8];
    stack[0] = v0092;
    v0093 = elt(env, 0); /* !:pi */
    v0092 = stack[0];
    fn = elt(env, 8); /* save!:const */
    v0092 = (*qfn2(fn))(qenv(fn), v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    { Lisp_Object res = stack[0]; popv(9); return onevalue(res); }

v0094:
    v0092 = qvalue(elt(env, 1)); /* t */
    goto v0029;
/* error exit handlers */
v0095:
    popv(9);
    return nil;
}



/* Code for ngetvar */

static Lisp_Object CC_ngetvar(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0101, v0040;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ngetvar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0101 = v0017;
    v0040 = v0000;
/* end of prologue */
    v0003 = v0040;
    if (!consp(v0003)) goto v0102;
    v0003 = v0040;
    v0003 = qcar(v0003);
    if (!consp(v0003)) goto v0090;
    v0003 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0003);

v0090:
    v0003 = v0040;
    v0003 = qcar(v0003);
    return get(v0003, v0101);

v0102:
    v0003 = v0040;
    return get(v0003, v0101);
}



/* Code for del!-deltas */

static Lisp_Object CC_delKdeltas(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0059, v0060;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for del-deltas");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0052 = v0017;
    v0059 = v0000;
/* end of prologue */

v0089:
    v0060 = v0059;
    v0060 = qcdr(v0060);
    if (v0060 == nil) { popv(2); return onevalue(v0052); }
    v0060 = v0059;
    v0060 = qcdr(v0060);
    stack[0] = v0060;
    v0059 = qcar(v0059);
    v0059 = qcdr(v0059);
    fn = elt(env, 1); /* del!-tades */
    v0052 = (*qfn2(fn))(qenv(fn), v0059, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-1];
    v0059 = stack[0];
    goto v0089;
/* error exit handlers */
v0101:
    popv(2);
    return nil;
}



/* Code for xprinf2 */

static Lisp_Object CC_xprinf2(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0002;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xprinf2");
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
    goto v0029;

v0029:
    v0104 = stack[0];
    if (!consp(v0104)) goto v0030;
    v0104 = stack[0];
    v0104 = qcar(v0104);
    v0104 = (consp(v0104) ? nil : lisp_true);
    goto v0031;

v0031:
    if (v0104 == nil) goto v0105;
    v0104 = stack[0];
    if (v0104 == nil) goto v0106;
    v0104 = stack[0];
    fn = elt(env, 5); /* minusf */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-2];
    if (v0104 == nil) goto v0020;
    v0104 = elt(env, 3); /* minus */
    fn = elt(env, 6); /* oprin */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-2];
    v0104 = stack[0];
    fn = elt(env, 7); /* !:minus */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-2];
    stack[0] = v0104;
    goto v0107;

v0107:
    v0104 = stack[0];
    if (!consp(v0104)) goto v0108;
    v0104 = stack[0];
    fn = elt(env, 8); /* maprin */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    goto v0109;

v0109:
    v0104 = nil;
    { popv(3); return onevalue(v0104); }

v0108:
    v0104 = stack[0];
    fn = elt(env, 9); /* prin2!* */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    goto v0109;

v0020:
    v0104 = stack[-1];
    if (v0104 == nil) goto v0107;
    v0104 = elt(env, 4); /* plus */
    fn = elt(env, 6); /* oprin */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-2];
    goto v0107;

v0106:
    v0104 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0104); }

v0105:
    v0104 = stack[0];
    v0002 = qcar(v0104);
    v0104 = stack[-1];
    fn = elt(env, 10); /* xprint */
    v0104 = (*qfn2(fn))(qenv(fn), v0002, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-2];
    v0104 = stack[0];
    v0104 = qcdr(v0104);
    stack[0] = v0104;
    v0104 = qvalue(elt(env, 1)); /* t */
    stack[-1] = v0104;
    goto v0029;

v0030:
    v0104 = qvalue(elt(env, 1)); /* t */
    goto v0031;
/* error exit handlers */
v0016:
    popv(3);
    return nil;
}



/* Code for mk!+internal!+mat */

static Lisp_Object CC_mkLinternalLmat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+internal+mat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0089 = v0000;
/* end of prologue */
    {
        fn = elt(env, 1); /* mk!+transpose!+matrix */
        return (*qfn1(fn))(qenv(fn), v0089);
    }
}



/* Code for rl_ppriop */

static Lisp_Object CC_rl_ppriop(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0011, v0110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_ppriop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0011 = v0017;
    stack[0] = v0000;
/* end of prologue */
    v0022 = qvalue(elt(env, 1)); /* !*nat */
    if (v0022 == nil) goto v0102;
    v0022 = qvalue(elt(env, 3)); /* !*rlbrop */
    if (v0022 == nil) goto v0111;
    v0022 = (Lisp_Object)1; /* 0 */
    v0022 = Leqn(nil, v0011, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-1];
    goto v0094;

v0094:
    if (v0022 == nil) goto v0003;
    v0022 = elt(env, 4); /* failed */
    { popv(2); return onevalue(v0022); }

v0003:
    v0022 = elt(env, 5); /* "(" */
    fn = elt(env, 7); /* prin2!* */
    v0022 = (*qfn1(fn))(qenv(fn), v0022);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-1];
    v0022 = stack[0];
    v0110 = qcar(v0022);
    v0022 = stack[0];
    v0022 = qcar(v0022);
    if (!symbolp(v0022)) v0011 = nil;
    else { v0011 = qfastgets(v0022);
           if (v0011 != nil) { v0011 = elt(v0011, 23); /* infix */
#ifdef RECORD_GET
             if (v0011 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0011 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0011 == SPID_NOPROP) v0011 = nil; }}
#endif
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    fn = elt(env, 8); /* inprint */
    v0022 = (*qfnn(fn))(qenv(fn), 3, v0110, v0011, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-1];
    v0022 = elt(env, 6); /* ")" */
    {
        popv(2);
        fn = elt(env, 7); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0022);
    }

v0111:
    v0022 = qvalue(elt(env, 2)); /* t */
    goto v0094;

v0102:
    v0022 = qvalue(elt(env, 2)); /* t */
    goto v0094;
/* error exit handlers */
v0108:
    popv(2);
    return nil;
}



/* Code for elimpt_unif */

static Lisp_Object CC_elimpt_unif(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0102;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for elimpt_unif");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0102 = v0000;
/* end of prologue */
    v0102 = qcdr(v0102);
    v0102 = qcdr(v0102);
    v0102 = qcdr(v0102);
    v0102 = qcdr(v0102);
    v0102 = qcdr(v0102);
    v0102 = qcar(v0102);
    return onevalue(v0102);
}



/* Code for codfac */

static Lisp_Object MS_CDECL CC_codfac(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0066, v0131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "codfac");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for codfac");
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
    push4(nil, nil, nil, nil);
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    v0066 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v0066;
    goto v0132;

v0132:
    v0131 = (Lisp_Object)-15; /* -1 */
    v0066 = stack[-1];
    v0066 = difference2(v0131, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    v0066 = Lminusp(nil, v0066);
    env = stack[-4];
    if (!(v0066 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v0131 = qvalue(elt(env, 4)); /* maxvar */
    v0066 = stack[-1];
    v0066 = plus2(v0131, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    v0131 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0066/(16/CELL)));
    v0066 = (Lisp_Object)49; /* 3 */
    v0131 = *(Lisp_Object *)((char *)v0131 + (CELL-TAG_VECTOR) + ((int32_t)v0066/(16/CELL)));
    v0066 = (Lisp_Object)-15; /* -1 */
    if (v0131 == v0066) goto v0040;
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v0131 = qvalue(elt(env, 4)); /* maxvar */
    v0066 = stack[-1];
    v0066 = plus2(v0131, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    v0131 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0066/(16/CELL)));
    v0066 = (Lisp_Object)49; /* 3 */
    v0131 = *(Lisp_Object *)((char *)v0131 + (CELL-TAG_VECTOR) + ((int32_t)v0066/(16/CELL)));
    v0066 = (Lisp_Object)-31; /* -2 */
    v0066 = (v0131 == v0066 ? lisp_true : nil);
    goto v0101;

v0101:
    if (v0066 == nil) goto v0134;
    v0066 = qvalue(elt(env, 2)); /* nil */
    goto v0052;

v0052:
    if (v0066 == nil) goto v0105;
    v0066 = qvalue(elt(env, 5)); /* t */
    stack[-3] = v0066;
    v0066 = stack[-2];
    stack[0] = v0066;
    goto v0076;

v0076:
    v0066 = stack[0];
    if (v0066 == nil) goto v0105;
    v0066 = stack[0];
    v0066 = qcar(v0066);
    v0131 = stack[-1];
    fn = elt(env, 7); /* commonfac */
    v0066 = (*qfn2(fn))(qenv(fn), v0131, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    v0066 = stack[0];
    v0066 = qcdr(v0066);
    stack[0] = v0066;
    goto v0076;

v0105:
    v0066 = stack[-1];
    v0066 = add1(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    stack[-1] = v0066;
    goto v0132;

v0134:
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v0131 = qvalue(elt(env, 4)); /* maxvar */
    v0066 = stack[-1];
    v0066 = plus2(v0131, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    v0131 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0066/(16/CELL)));
    v0066 = (Lisp_Object)33; /* 2 */
    v0131 = *(Lisp_Object *)((char *)v0131 + (CELL-TAG_VECTOR) + ((int32_t)v0066/(16/CELL)));
    v0066 = elt(env, 6); /* times */
    if (v0131 == v0066) goto v0135;
    v0066 = qvalue(elt(env, 2)); /* nil */
    goto v0052;

v0135:
    v0066 = stack[-1];
    fn = elt(env, 8); /* samefar */
    v0066 = (*qfn1(fn))(qenv(fn), v0066);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    stack[-2] = v0066;
    goto v0052;

v0040:
    v0066 = qvalue(elt(env, 5)); /* t */
    goto v0101;
/* error exit handlers */
v0133:
    popv(5);
    return nil;
}



/* Code for groebfactorize3 */

static Lisp_Object CC_groebfactorize3(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0014;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebfactorize3");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0014 = v0000;
/* end of prologue */
    v0014 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0014);
}



/* Code for sc_negtranspose */

static Lisp_Object CC_sc_negtranspose(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036, v0037, v0126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_negtranspose");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0000;
/* end of prologue */
    v0036 = stack[-7];
    fn = elt(env, 2); /* fast!-row!-dim */
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-9];
    stack[-5] = v0036;
    v0036 = stack[-7];
    fn = elt(env, 3); /* fast!-column!-dim */
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-9];
    stack[-6] = v0036;
    v0037 = stack[-6];
    v0036 = stack[-5];
    fn = elt(env, 4); /* sc_mkmatrix */
    v0036 = (*qfn2(fn))(qenv(fn), v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-9];
    stack[-8] = v0036;
    v0036 = (Lisp_Object)17; /* 1 */
    stack[-4] = v0036;
    goto v0059;

v0059:
    v0037 = stack[-6];
    v0036 = stack[-4];
    v0036 = difference2(v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-9];
    v0036 = Lminusp(nil, v0036);
    env = stack[-9];
    if (!(v0036 == nil)) { Lisp_Object res = stack[-8]; popv(10); return onevalue(res); }
    v0036 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0036;
    goto v0142;

v0142:
    v0037 = stack[-5];
    v0036 = stack[-3];
    v0036 = difference2(v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-9];
    v0036 = Lminusp(nil, v0036);
    env = stack[-9];
    if (v0036 == nil) goto v0129;
    v0036 = stack[-4];
    v0036 = add1(v0036);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-9];
    stack[-4] = v0036;
    goto v0059;

v0129:
    stack[-2] = stack[-8];
    stack[-1] = stack[-4];
    stack[0] = stack[-3];
    v0126 = stack[-7];
    v0037 = stack[-3];
    v0036 = stack[-4];
    fn = elt(env, 5); /* sc_getmat */
    v0036 = (*qfnn(fn))(qenv(fn), 3, v0126, v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-9];
    fn = elt(env, 6); /* sc_negsq */
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-9];
    fn = elt(env, 7); /* sc_setmat */
    v0036 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v0036);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-9];
    v0036 = stack[-3];
    v0036 = add1(v0036);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-9];
    stack[-3] = v0036;
    goto v0142;
/* error exit handlers */
v0141:
    popv(10);
    return nil;
}



/* Code for ev!-gamma */

static Lisp_Object CC_evKgamma(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0138, v0139, v0107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev-gamma");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0138 = v0000;
/* end of prologue */
    v0107 = v0138;
    v0139 = qvalue(elt(env, 1)); /* dipsortmode!* */
    v0138 = elt(env, 2); /* graded */
    if (v0139 == v0138) goto v0032;
    v0139 = qvalue(elt(env, 1)); /* dipsortmode!* */
    v0138 = elt(env, 4); /* weighted */
    if (v0139 == v0138) goto v0091;
    v0138 = qvalue(elt(env, 6)); /* nil */
    goto v0089;

v0089:
    {
        fn = elt(env, 7); /* evweightedcomp1 */
        return (*qfn2(fn))(qenv(fn), v0107, v0138);
    }

v0091:
    v0138 = qvalue(elt(env, 5)); /* vdpsortextension!* */
    goto v0089;

v0032:
    v0138 = qvalue(elt(env, 3)); /* gradedrec!* */
    v0138 = qcar(v0138);
    goto v0089;
}



/* Code for setmatpri */

static Lisp_Object CC_setmatpri(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setmatpri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0031 = v0017;
    v0025 = v0000;
/* end of prologue */
    v0031 = qcdr(v0031);
    {
        fn = elt(env, 1); /* matpri1 */
        return (*qfn2(fn))(qenv(fn), v0031, v0025);
    }
}



/* Code for fact */

static Lisp_Object CC_fact(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0145, v0146, v0142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fact");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0000;
/* end of prologue */
    v0145 = stack[-2];
    fn = elt(env, 3); /* aeval */
    v0146 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-4];
    v0145 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 4); /* evalequal */
    v0145 = (*qfn2(fn))(qenv(fn), v0146, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-4];
    if (v0145 == nil) goto v0008;
    v0145 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0145); }

v0008:
    stack[-3] = elt(env, 1); /* times */
    stack[-1] = stack[-2];
    stack[0] = elt(env, 0); /* fact */
    v0142 = elt(env, 2); /* difference */
    v0146 = stack[-2];
    v0145 = (Lisp_Object)17; /* 1 */
    v0145 = list3(v0142, v0146, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-4];
    v0145 = list2(stack[0], v0145);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-4];
    v0145 = list3(stack[-3], stack[-1], v0145);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 3); /* aeval */
        return (*qfn1(fn))(qenv(fn), v0145);
    }
/* error exit handlers */
v0011:
    popv(5);
    return nil;
}



/* Code for polineqcheck */

static Lisp_Object CC_polineqcheck(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0106, v0149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for polineqcheck");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    stack[-1] = v0000;
/* end of prologue */

v0150:
    v0106 = stack[-1];
    if (v0106 == nil) goto v0112;
    v0106 = stack[-1];
    v0149 = qcar(v0106);
    v0106 = stack[0];
    fn = elt(env, 3); /* subsq */
    v0106 = (*qfn2(fn))(qenv(fn), v0149, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    v0106 = qcar(v0106);
    fn = elt(env, 4); /* minusf */
    v0106 = (*qfn1(fn))(qenv(fn), v0106);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    if (v0106 == nil) goto v0034;
    v0106 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0106); }

v0034:
    v0106 = stack[-1];
    v0149 = qcdr(v0106);
    v0106 = stack[0];
    stack[-1] = v0149;
    stack[0] = v0106;
    goto v0150;

v0112:
    v0106 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0106); }
/* error exit handlers */
v0019:
    popv(3);
    return nil;
}



/* Code for mk!+scal!+mult!+vec */

static Lisp_Object CC_mkLscalLmultLvec(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0152, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+scal+mult+vec");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v0152 = v0017;
    stack[-4] = v0000;
/* end of prologue */
    stack[-5] = v0152;
    v0152 = stack[-5];
    if (v0152 == nil) goto v0111;
    v0152 = stack[-5];
    v0152 = qcar(v0152);
    v0015 = stack[-4];
    fn = elt(env, 4); /* multsq */
    v0152 = (*qfn2(fn))(qenv(fn), v0015, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-6];
    v0015 = v0152;
    v0152 = qvalue(elt(env, 2)); /* t */
    stack[0] = qvalue(elt(env, 3)); /* !*sub2 */
    qvalue(elt(env, 3)) = v0152; /* !*sub2 */
    v0152 = v0015;
    fn = elt(env, 5); /* subs2 */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-6];
    v0015 = v0152;
    qvalue(elt(env, 3)) = stack[0]; /* !*sub2 */
    v0152 = v0015;
    v0152 = ncons(v0152);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-6];
    stack[-2] = v0152;
    stack[-3] = v0152;
    goto v0031;

v0031:
    v0152 = stack[-5];
    v0152 = qcdr(v0152);
    stack[-5] = v0152;
    v0152 = stack[-5];
    if (v0152 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v0152 = stack[-5];
    v0152 = qcar(v0152);
    v0015 = stack[-4];
    fn = elt(env, 4); /* multsq */
    v0152 = (*qfn2(fn))(qenv(fn), v0015, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-6];
    v0015 = v0152;
    v0152 = qvalue(elt(env, 2)); /* t */
    stack[0] = qvalue(elt(env, 3)); /* !*sub2 */
    qvalue(elt(env, 3)) = v0152; /* !*sub2 */
    v0152 = v0015;
    fn = elt(env, 5); /* subs2 */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    v0015 = v0152;
    qvalue(elt(env, 3)) = stack[0]; /* !*sub2 */
    v0152 = v0015;
    v0152 = ncons(v0152);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-6];
    v0152 = Lrplacd(nil, stack[-1], v0152);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-6];
    v0152 = stack[-2];
    v0152 = qcdr(v0152);
    stack[-2] = v0152;
    goto v0031;

v0111:
    v0152 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0152); }
/* error exit handlers */
v0086:
    env = stack[-6];
    qvalue(elt(env, 3)) = stack[0]; /* !*sub2 */
    popv(7);
    return nil;
v0028:
    env = stack[-6];
    qvalue(elt(env, 3)) = stack[0]; /* !*sub2 */
    popv(7);
    return nil;
v0027:
    popv(7);
    return nil;
}



/* Code for rl_vonoff */

static Lisp_Object CC_rl_vonoff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0145, v0146, v0142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_vonoff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = stack[0];
    v0145 = stack[-1];
    fn = elt(env, 5); /* rl_onp */
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-3];
    if (equal(stack[-2], v0145)) goto v0089;
    stack[-2] = elt(env, 1); /* "turned" */
    v0145 = stack[-1];
    fn = elt(env, 5); /* rl_onp */
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-3];
    if (v0145 == nil) goto v0040;
    v0145 = elt(env, 2); /* "off" */
    v0142 = v0145;
    goto v0090;

v0090:
    v0146 = elt(env, 4); /* "switch" */
    v0145 = stack[-1];
    v0145 = list4(stack[-2], v0142, v0146, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-3];
    fn = elt(env, 6); /* lprim */
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-3];
    v0146 = stack[-1];
    v0145 = stack[0];
    {
        popv(4);
        fn = elt(env, 7); /* onoff */
        return (*qfn2(fn))(qenv(fn), v0146, v0145);
    }

v0040:
    v0145 = elt(env, 3); /* "on" */
    v0142 = v0145;
    goto v0090;

v0089:
    v0145 = nil;
    { popv(4); return onevalue(v0145); }
/* error exit handlers */
v0022:
    popv(4);
    return nil;
}



/* Code for rl_bettergaussp */

static Lisp_Object CC_rl_bettergaussp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0140, v0136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_bettergaussp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0140 = v0017;
    v0136 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_bettergaussp!* */
    v0140 = list2(v0136, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-1];
    {
        Lisp_Object v0091 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0091, v0140);
    }
/* error exit handlers */
v0090:
    popv(2);
    return nil;
}



/* Code for iv_cutcongs */

static Lisp_Object CC_iv_cutcongs(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0158, v0116, v0159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for iv_cutcongs");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0017;
    stack[-3] = v0000;
/* end of prologue */
    stack[-4] = nil;
    stack[-1] = nil;
    v0158 = stack[-2];
    if (v0158 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    else goto v0007;

v0007:
    v0158 = stack[-3];
    fn = elt(env, 2); /* iv_empty */
    v0158 = (*qfn1(fn))(qenv(fn), v0158);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-5];
    if (v0158 == nil) goto v0111;
    v0158 = stack[-1];
        popv(6);
        return Lreverse(nil, v0158);

v0111:
    v0158 = stack[-3];
    v0158 = qcar(v0158);
    v0158 = qcar(v0158);
    stack[0] = v0158;
    goto v0139;

v0139:
    v0158 = stack[-3];
    v0158 = qcar(v0158);
    v0116 = qcdr(v0158);
    v0158 = stack[0];
    v0158 = difference2(v0116, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-5];
    v0158 = Lminusp(nil, v0158);
    env = stack[-5];
    if (v0158 == nil) goto v0145;
    v0158 = stack[-3];
    v0158 = qcdr(v0158);
    if (v0158 == nil) goto v0134;
    v0158 = qvalue(elt(env, 1)); /* nil */
    goto v0080;

v0080:
    if (v0158 == nil) goto v0161;
    v0158 = stack[-4];
    v0159 = qcar(v0158);
    v0158 = stack[-3];
    v0158 = qcar(v0158);
    v0116 = qcdr(v0158);
    v0158 = stack[-1];
    v0158 = acons(v0159, v0116, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-5];
    stack[-1] = v0158;
    goto v0161;

v0161:
    v0158 = stack[-3];
    v0158 = qcdr(v0158);
    stack[-3] = v0158;
    goto v0007;

v0134:
    v0158 = stack[-4];
    goto v0080;

v0145:
    v0116 = stack[0];
    v0158 = stack[-2];
    fn = elt(env, 3); /* iv_cutcongs1 */
    v0158 = (*qfn2(fn))(qenv(fn), v0116, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-5];
    v0116 = stack[0];
    v0158 = stack[-2];
    fn = elt(env, 3); /* iv_cutcongs1 */
    v0158 = (*qfn2(fn))(qenv(fn), v0116, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-5];
    if (v0158 == nil) goto v0108;
    v0158 = stack[-4];
    if (v0158 == nil) goto v0086;
    v0158 = stack[-4];
    v0116 = qcar(v0158);
    v0158 = stack[0];
    v0158 = cons(v0116, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-5];
    stack[-4] = v0158;
    goto v0110;

v0110:
    v0158 = stack[0];
    v0158 = add1(v0158);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-5];
    stack[0] = v0158;
    goto v0139;

v0086:
    v0116 = stack[0];
    v0158 = stack[0];
    v0158 = cons(v0116, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-5];
    stack[-4] = v0158;
    goto v0110;

v0108:
    v0158 = stack[-4];
    if (v0158 == nil) goto v0110;
    v0116 = stack[-4];
    v0158 = stack[-1];
    v0158 = cons(v0116, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-5];
    stack[-1] = v0158;
    v0158 = qvalue(elt(env, 1)); /* nil */
    stack[-4] = v0158;
    goto v0110;
/* error exit handlers */
v0160:
    popv(6);
    return nil;
}



/* Code for ev_2f */

static Lisp_Object CC_ev_2f(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev_2f");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    stack[-1] = v0000;
/* end of prologue */

v0112:
    v0035 = stack[-1];
    if (v0035 == nil) goto v0094;
    v0035 = stack[-1];
    v0151 = qcar(v0035);
    v0035 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 1); /* iequal */
    v0035 = (*qfn2(fn))(qenv(fn), v0151, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    if (v0035 == nil) goto v0020;
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    stack[-1] = v0035;
    v0035 = stack[0];
    v0035 = qcdr(v0035);
    stack[0] = v0035;
    goto v0112;

v0020:
    v0035 = stack[0];
    v0151 = qcar(v0035);
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    fn = elt(env, 2); /* to */
    v0151 = (*qfn2(fn))(qenv(fn), v0151, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    v0035 = (Lisp_Object)17; /* 1 */
    v0035 = cons(v0151, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    stack[-2] = ncons(v0035);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    v0035 = stack[-1];
    v0151 = qcdr(v0035);
    v0035 = stack[0];
    v0035 = qcdr(v0035);
    v0035 = CC_ev_2f(env, v0151, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    {
        Lisp_Object v0010 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* multf */
        return (*qfn2(fn))(qenv(fn), v0010, v0035);
    }

v0094:
    v0035 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v0035); }
/* error exit handlers */
v0009:
    popv(4);
    return nil;
}



/* Code for look_for_exponential */

static Lisp_Object MS_CDECL CC_look_for_exponential(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0224, v0225, v0226;
    Lisp_Object fn;
    Lisp_Object v0018, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "look_for_exponential");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0017 = va_arg(aa, Lisp_Object);
    v0018 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for look_for_exponential");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0018,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0017,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0018;
    stack[-1] = v0017;
    stack[-3] = v0000;
/* end of prologue */
    v0224 = stack[0];
    v0225 = qcar(v0224);
    stack[0] = v0225;
    v0224 = elt(env, 1); /* expt */
    if (!consp(v0225)) goto v0143;
    v0225 = qcar(v0225);
    if (!(v0225 == v0224)) goto v0143;
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    v0225 = qcar(v0224);
    v0224 = stack[-1];
    fn = elt(env, 7); /* depends */
    v0224 = (*qfn2(fn))(qenv(fn), v0225, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    goto v0102;

v0102:
    if (v0224 == nil) goto v0138;
    v0224 = qvalue(elt(env, 3)); /* nil */
    { popv(11); return onevalue(v0224); }

v0138:
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-8] = nil;
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    v0224 = qcdr(v0224);
    v0224 = qcar(v0224);
    stack[0] = v0224;
    v0225 = stack[0];
    v0224 = elt(env, 1); /* expt */
    if (!consp(v0225)) goto v0037;
    v0225 = qcar(v0225);
    if (!(v0225 == v0224)) goto v0037;
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    v0225 = qcar(v0224);
    v0224 = stack[-1];
    if (equal(v0225, v0224)) goto v0010;
    v0224 = qvalue(elt(env, 3)); /* nil */
    goto v0109;

v0109:
    if (v0224 == nil) goto v0228;
    v0224 = qvalue(elt(env, 2)); /* t */
    stack[-8] = v0224;
    v0224 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0224;
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    v0224 = qcdr(v0224);
    v0224 = qcar(v0224);
    stack[-7] = v0224;
    goto v0021;

v0021:
    v0224 = elt(env, 6); /* intvar */
    fn = elt(env, 8); /* int!-gensym1 */
    v0224 = (*qfn1(fn))(qenv(fn), v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    stack[-9] = v0224;
    v0224 = stack[-8];
    if (v0224 == nil) goto v0229;
    v0226 = stack[-9];
    v0225 = elt(env, 0); /* look_for_exponential */
    v0224 = stack[-7];
    v0224 = Lputprop(nil, 3, v0226, v0225, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    goto v0229;

v0229:
    stack[-4] = elt(env, 1); /* expt */
    v0225 = stack[-2];
    v0224 = (Lisp_Object)17; /* 1 */
    if (v0225 == v0224) goto v0230;
    v0226 = elt(env, 4); /* quotient */
    v0225 = stack[-9];
    v0224 = stack[-2];
    v0224 = list3(v0226, v0225, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    stack[0] = v0224;
    goto v0231;

v0231:
    v0225 = stack[-7];
    v0224 = (Lisp_Object)-15; /* -1 */
    if (v0225 == v0224) goto v0232;
    v0226 = elt(env, 4); /* quotient */
    v0225 = (Lisp_Object)17; /* 1 */
    v0224 = stack[-7];
    v0224 = list3(v0226, v0225, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    goto v0233;

v0233:
    v0224 = list3(stack[-4], stack[0], v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    stack[0] = v0224;
    stack[-6] = stack[-3];
    stack[-5] = stack[-1];
    stack[-4] = stack[-9];
    stack[-3] = stack[0];
    v0226 = elt(env, 1); /* expt */
    v0225 = stack[-1];
    v0224 = stack[-7];
    v0224 = list3(v0226, v0225, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    v0224 = list2(stack[-2], v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    fn = elt(env, 9); /* retimes */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    stack[-1] = elt(env, 4); /* quotient */
    v0226 = elt(env, 5); /* times */
    v0225 = stack[-7];
    v0224 = stack[-9];
    v0224 = list3(v0226, v0225, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    v0224 = list3(stack[-1], stack[0], v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    fn = elt(env, 10); /* simp */
    v0225 = (*qfn1(fn))(qenv(fn), v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    v0224 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 11); /* subst!-and!-int */
    v0224 = (*qfnn(fn))(qenv(fn), 7, stack[-6], stack[-5], stack[-4], stack[-3], stack[-2], v0225, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    v0226 = v0224;
    v0224 = stack[-8];
    if (v0224 == nil) { popv(11); return onevalue(v0226); }
    v0225 = stack[-9];
    v0224 = elt(env, 0); /* look_for_exponential */
    v0224 = Lremprop(nil, v0225, v0224);
    { popv(11); return onevalue(v0226); }

v0232:
    v0224 = (Lisp_Object)-15; /* -1 */
    goto v0233;

v0230:
    v0224 = stack[-9];
    stack[0] = v0224;
    goto v0231;

v0228:
    v0225 = stack[0];
    v0224 = elt(env, 4); /* quotient */
    if (!consp(v0225)) goto v0122;
    v0225 = qcar(v0225);
    if (!(v0225 == v0224)) goto v0122;
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    v0225 = qcar(v0224);
    v0224 = stack[-1];
    fn = elt(env, 7); /* depends */
    v0224 = (*qfn2(fn))(qenv(fn), v0225, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    v0224 = (v0224 == nil ? lisp_true : nil);
    goto v0155;

v0155:
    if (v0224 == nil) goto v0234;
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    v0224 = qcar(v0224);
    stack[-2] = v0224;
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    v0224 = qcdr(v0224);
    v0224 = qcar(v0224);
    stack[0] = v0224;
    v0225 = stack[0];
    v0224 = stack[-1];
    if (equal(v0225, v0224)) goto v0235;
    v0225 = stack[0];
    v0224 = elt(env, 1); /* expt */
    if (!consp(v0225)) goto v0064;
    v0225 = qcar(v0225);
    if (!(v0225 == v0224)) goto v0064;
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    v0225 = qcar(v0224);
    v0224 = stack[-1];
    if (equal(v0225, v0224)) goto v0236;
    v0224 = qvalue(elt(env, 3)); /* nil */
    goto v0067;

v0067:
    if (v0224 == nil) goto v0237;
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    v0224 = qcdr(v0224);
    v0224 = qcar(v0224);
    v0224 = negate(v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    stack[-7] = v0224;
    goto v0021;

v0237:
    v0225 = stack[0];
    v0224 = elt(env, 5); /* times */
    if (!consp(v0225)) goto v0061;
    v0225 = qcar(v0225);
    if (!(v0225 == v0224)) goto v0061;
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    stack[-4] = v0224;
    goto v0056;

v0056:
    v0224 = stack[-4];
    if (v0224 == nil) goto v0055;
    v0224 = stack[-4];
    v0224 = qcar(v0224);
    stack[0] = v0224;
    v0225 = stack[0];
    v0224 = stack[-1];
    fn = elt(env, 7); /* depends */
    v0224 = (*qfn2(fn))(qenv(fn), v0225, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    if (v0224 == nil) goto v0238;
    v0225 = stack[0];
    v0224 = stack[-5];
    v0224 = cons(v0225, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    stack[-5] = v0224;
    goto v0239;

v0239:
    v0224 = stack[-4];
    v0224 = qcdr(v0224);
    stack[-4] = v0224;
    goto v0056;

v0238:
    v0225 = stack[0];
    v0224 = stack[-6];
    v0224 = cons(v0225, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    stack[-6] = v0224;
    goto v0239;

v0055:
    v0224 = stack[-5];
    v0224 = qcdr(v0224);
    if (v0224 == nil) goto v0044;
    v0224 = qvalue(elt(env, 3)); /* nil */
    { popv(11); return onevalue(v0224); }

v0044:
    v0224 = stack[-5];
    v0224 = qcar(v0224);
    stack[0] = v0224;
    stack[-4] = elt(env, 4); /* quotient */
    v0224 = stack[-6];
    fn = elt(env, 9); /* retimes */
    v0224 = (*qfn1(fn))(qenv(fn), v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    v0224 = list3(stack[-4], stack[-2], v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    stack[-2] = v0224;
    v0225 = stack[0];
    v0224 = stack[-1];
    if (equal(v0225, v0224)) goto v0095;
    v0225 = stack[0];
    v0224 = elt(env, 1); /* expt */
    if (!consp(v0225)) goto v0240;
    v0225 = qcar(v0225);
    if (!(v0225 == v0224)) goto v0240;
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    v0225 = qcar(v0224);
    v0224 = stack[-1];
    if (equal(v0225, v0224)) goto v0241;
    v0224 = qvalue(elt(env, 3)); /* nil */
    goto v0242;

v0242:
    if (v0224 == nil) goto v0243;
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    v0224 = qcdr(v0224);
    v0224 = qcar(v0224);
    v0224 = negate(v0224);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-10];
    stack[-7] = v0224;
    goto v0021;

v0243:
    v0224 = qvalue(elt(env, 3)); /* nil */
    { popv(11); return onevalue(v0224); }

v0241:
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    v0224 = qcdr(v0224);
    v0224 = qcar(v0224);
    v0224 = integerp(v0224);
    goto v0242;

v0240:
    v0224 = qvalue(elt(env, 3)); /* nil */
    goto v0242;

v0095:
    v0224 = (Lisp_Object)-15; /* -1 */
    stack[-7] = v0224;
    goto v0021;

v0061:
    v0224 = qvalue(elt(env, 3)); /* nil */
    { popv(11); return onevalue(v0224); }

v0236:
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    v0224 = qcdr(v0224);
    v0224 = qcar(v0224);
    v0224 = integerp(v0224);
    goto v0067;

v0064:
    v0224 = qvalue(elt(env, 3)); /* nil */
    goto v0067;

v0235:
    v0224 = (Lisp_Object)-15; /* -1 */
    stack[-7] = v0224;
    goto v0021;

v0234:
    v0224 = qvalue(elt(env, 3)); /* nil */
    { popv(11); return onevalue(v0224); }

v0122:
    v0224 = qvalue(elt(env, 3)); /* nil */
    goto v0155;

v0010:
    v0224 = stack[0];
    v0224 = qcdr(v0224);
    v0224 = qcdr(v0224);
    v0224 = qcar(v0224);
    v0224 = integerp(v0224);
    goto v0109;

v0037:
    v0224 = qvalue(elt(env, 3)); /* nil */
    goto v0109;

v0143:
    v0224 = qvalue(elt(env, 2)); /* t */
    goto v0102;
/* error exit handlers */
v0227:
    popv(11);
    return nil;
}



/* Code for smaddm2 */

static Lisp_Object MS_CDECL CC_smaddm2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0251, v0252, v0063, v0064;
    Lisp_Object fn;
    Lisp_Object v0018, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "smaddm2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0017 = va_arg(aa, Lisp_Object);
    v0018 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for smaddm2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0018,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0017,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v0018;
    v0252 = v0017;
    v0251 = v0000;
/* end of prologue */
    stack[-7] = v0251;
    v0251 = v0252;
    stack[-6] = v0251;
    v0252 = stack[-6];
    v0251 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* copy_vect */
    v0251 = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-10];
    stack[-9] = v0251;
    v0251 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0251;
    goto v0106;

v0106:
    v0251 = stack[-8];
    v0251 = qcdr(v0251);
    v0252 = qcar(v0251);
    v0251 = stack[-2];
    v0251 = difference2(v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-10];
    v0251 = Lminusp(nil, v0251);
    env = stack[-10];
    if (!(v0251 == nil)) { Lisp_Object res = stack[-9]; popv(11); return onevalue(res); }
    v0252 = stack[-7];
    v0251 = stack[-2];
    fn = elt(env, 3); /* findrow */
    v0251 = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-10];
    stack[0] = v0251;
    v0252 = stack[-6];
    v0251 = stack[-2];
    fn = elt(env, 3); /* findrow */
    v0251 = (*qfn2(fn))(qenv(fn), v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-10];
    stack[-5] = v0251;
    v0251 = stack[0];
    if (v0251 == nil) goto v0002;
    v0251 = stack[0];
    v0251 = qcdr(v0251);
    stack[-1] = v0251;
    goto v0015;

v0015:
    v0251 = stack[-1];
    if (v0251 == nil) goto v0002;
    v0251 = stack[-1];
    v0251 = qcar(v0251);
    v0252 = v0251;
    v0251 = v0252;
    v0251 = qcar(v0251);
    stack[-3] = v0251;
    v0251 = v0252;
    v0251 = qcdr(v0251);
    stack[0] = v0251;
    v0252 = stack[-3];
    v0251 = stack[-5];
    v0251 = Latsoc(nil, v0252, v0251);
    stack[-4] = v0251;
    v0251 = stack[-4];
    if (v0251 == nil) goto v0253;
    v0251 = stack[-4];
    v0251 = qcdr(v0251);
    stack[-4] = v0251;
    v0251 = stack[0];
    fn = elt(env, 4); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v0251);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-10];
    v0251 = stack[-4];
    fn = elt(env, 4); /* simp */
    v0251 = (*qfn1(fn))(qenv(fn), v0251);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-10];
    fn = elt(env, 5); /* addsq */
    v0251 = (*qfn2(fn))(qenv(fn), stack[0], v0251);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-10];
    stack[0] = v0251;
    v0251 = stack[0];
    fn = elt(env, 6); /* mk!*sq */
    v0251 = (*qfn1(fn))(qenv(fn), v0251);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-10];
    stack[0] = v0251;
    v0063 = stack[-9];
    v0252 = stack[-2];
    v0251 = stack[-3];
    v0064 = list3(v0063, v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-10];
    v0063 = stack[0];
    v0252 = stack[-9];
    v0251 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 7); /* letmtr3 */
    v0251 = (*qfnn(fn))(qenv(fn), 4, v0064, v0063, v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-10];
    goto v0141;

v0141:
    v0251 = stack[-1];
    v0251 = qcdr(v0251);
    stack[-1] = v0251;
    goto v0015;

v0253:
    v0063 = stack[-9];
    v0252 = stack[-2];
    v0251 = stack[-3];
    v0064 = list3(v0063, v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-10];
    v0063 = stack[0];
    v0252 = stack[-9];
    v0251 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 7); /* letmtr3 */
    v0251 = (*qfnn(fn))(qenv(fn), 4, v0064, v0063, v0252, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-10];
    goto v0141;

v0002:
    v0251 = stack[-2];
    v0251 = add1(v0251);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-10];
    stack[-2] = v0251;
    goto v0106;
/* error exit handlers */
v0237:
    popv(11);
    return nil;
}



/* Code for rdintequiv */

static Lisp_Object CC_rdintequiv(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rdintequiv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0132 = v0000;
/* end of prologue */
    v0007 = v0132;
    v0007 = qcdr(v0007);
    if (!consp(v0007)) goto v0014;
    v0007 = v0132;
    {
        fn = elt(env, 1); /* bfintequiv */
        return (*qfn1(fn))(qenv(fn), v0007);
    }

v0014:
    v0007 = v0132;
    v0007 = qcdr(v0007);
    {
        fn = elt(env, 2); /* ftintequiv */
        return (*qfn1(fn))(qenv(fn), v0007);
    }
}



/* Code for mkffortassign */

static Lisp_Object CC_mkffortassign(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0128, v0088;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkffortassign");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0017;
    stack[0] = v0000;
/* end of prologue */
    fn = elt(env, 3); /* mkforttab */
    stack[-2] = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-3];
    v0128 = stack[0];
    if (!consp(v0128)) goto v0148;
    v0088 = elt(env, 1); /* dummyarraytoken */
    v0128 = stack[0];
    v0128 = qcdr(v0128);
    v0128 = cons(v0088, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-3];
    fn = elt(env, 4); /* fortexp */
    v0088 = (*qfn1(fn))(qenv(fn), v0128);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-3];
    v0128 = stack[0];
    v0128 = qcar(v0128);
    v0128 = Lrplaca(nil, v0088, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-3];
    goto v0136;

v0136:
    stack[-2] = cons(stack[-2], v0128);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-3];
    stack[0] = elt(env, 2); /* != */
    v0128 = stack[-1];
    fn = elt(env, 4); /* fortexp */
    v0128 = (*qfn1(fn))(qenv(fn), v0128);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-3];
    v0128 = cons(stack[0], v0128);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-3];
    stack[0] = Lappend(nil, stack[-2], v0128);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-3];
    fn = elt(env, 5); /* mkfortterpri */
    v0128 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-3];
    v0128 = ncons(v0128);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    {
        Lisp_Object v0104 = stack[0];
        popv(4);
        return Lappend(nil, v0104, v0128);
    }

v0148:
    v0128 = stack[0];
    v0128 = ncons(v0128);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-3];
    goto v0136;
/* error exit handlers */
v0157:
    popv(4);
    return nil;
}



/* Code for coeffeval */

static Lisp_Object CC_coeffeval(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0250, v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for coeffeval");
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
    v0016 = stack[0];
    v0016 = Llength(nil, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    stack[-1] = v0016;
    v0250 = stack[-1];
    v0016 = (Lisp_Object)33; /* 2 */
    v0016 = (Lisp_Object)lessp2(v0250, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    v0016 = v0016 ? lisp_true : nil;
    env = stack[-2];
    if (!(v0016 == nil)) goto v0060;
    v0250 = stack[-1];
    v0016 = (Lisp_Object)49; /* 3 */
    v0016 = (Lisp_Object)greaterp2(v0250, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    v0016 = v0016 ? lisp_true : nil;
    env = stack[-2];
    if (!(v0016 == nil)) goto v0060;
    v0016 = stack[0];
    v0012 = qcar(v0016);
    v0016 = stack[0];
    v0016 = qcdr(v0016);
    v0250 = qcar(v0016);
    v0016 = stack[0];
    v0016 = qcdr(v0016);
    v0016 = qcdr(v0016);
    if (v0016 == nil) goto v0129;
    v0016 = stack[0];
    v0016 = qcdr(v0016);
    v0016 = qcdr(v0016);
    v0016 = qcar(v0016);
    goto v0142;

v0142:
    {
        popv(3);
        fn = elt(env, 4); /* coeff1 */
        return (*qfnn(fn))(qenv(fn), 3, v0012, v0250, v0016);
    }

v0129:
    v0016 = qvalue(elt(env, 3)); /* nil */
    goto v0142;

v0060:
    v0012 = elt(env, 1); /* alg */
    v0250 = (Lisp_Object)449; /* 28 */
    v0016 = elt(env, 2); /* "COEFF called with wrong number of arguments" 
*/
    fn = elt(env, 5); /* rerror */
    v0016 = (*qfnn(fn))(qenv(fn), 3, v0012, v0250, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    v0016 = nil;
    { popv(3); return onevalue(v0016); }
/* error exit handlers */
v0013:
    popv(3);
    return nil;
}



/* Code for mv!-!+ */

static Lisp_Object CC_mvKL(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0067, v0098, v0257;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-+");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0017;
    stack[-3] = v0000;
/* end of prologue */
    stack[0] = nil;
    goto v0089;

v0089:
    v0067 = stack[-3];
    if (v0067 == nil) goto v0031;
    v0067 = stack[-2];
    if (v0067 == nil) goto v0148;
    v0067 = stack[-3];
    v0067 = qcar(v0067);
    v0098 = qcar(v0067);
    v0067 = stack[-2];
    v0067 = qcar(v0067);
    v0067 = qcar(v0067);
    if (equal(v0098, v0067)) goto v0096;
    v0067 = stack[-3];
    v0067 = qcar(v0067);
    v0098 = qcar(v0067);
    v0067 = stack[-2];
    v0067 = qcar(v0067);
    v0067 = qcar(v0067);
    fn = elt(env, 1); /* mv!-pow!-!> */
    v0067 = (*qfn2(fn))(qenv(fn), v0098, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-5];
    if (v0067 == nil) goto v0116;
    v0067 = stack[-3];
    v0098 = qcar(v0067);
    v0067 = stack[0];
    v0067 = cons(v0098, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-5];
    stack[0] = v0067;
    v0067 = stack[-3];
    v0067 = qcdr(v0067);
    stack[-3] = v0067;
    goto v0089;

v0116:
    v0067 = stack[-2];
    v0098 = qcar(v0067);
    v0067 = stack[0];
    v0067 = cons(v0098, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-5];
    stack[0] = v0067;
    v0067 = stack[-2];
    v0067 = qcdr(v0067);
    stack[-2] = v0067;
    goto v0089;

v0096:
    stack[-4] = stack[0];
    v0067 = stack[-3];
    v0067 = qcar(v0067);
    v0098 = qcdr(v0067);
    v0067 = stack[-2];
    v0067 = qcar(v0067);
    v0067 = qcdr(v0067);
    v0067 = plus2(v0098, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-5];
    v0257 = v0067;
    v0098 = v0257;
    v0067 = (Lisp_Object)1; /* 0 */
    if (v0098 == v0067) goto v0084;
    v0067 = stack[-3];
    v0067 = qcar(v0067);
    stack[-1] = qcar(v0067);
    stack[0] = v0257;
    v0067 = stack[-3];
    v0098 = qcdr(v0067);
    v0067 = stack[-2];
    v0067 = qcdr(v0067);
    v0067 = CC_mvKL(env, v0098, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-5];
    v0067 = acons(stack[-1], stack[0], v0067);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-5];
    goto v0146;

v0146:
    {
        Lisp_Object v0219 = stack[-4];
        popv(6);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0219, v0067);
    }

v0084:
    v0067 = stack[-3];
    v0098 = qcdr(v0067);
    v0067 = stack[-2];
    v0067 = qcdr(v0067);
    v0067 = CC_mvKL(env, v0098, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-5];
    goto v0146;

v0148:
    v0098 = stack[0];
    v0067 = stack[-3];
    {
        popv(6);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0098, v0067);
    }

v0031:
    v0098 = stack[0];
    v0067 = stack[-2];
    {
        popv(6);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0098, v0067);
    }
/* error exit handlers */
v0068:
    popv(6);
    return nil;
}



/* Code for mo!=pair */

static Lisp_Object CC_moMpair(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0020, v0144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=pair");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    stack[-1] = v0000;
/* end of prologue */
    v0019 = nil;
    goto v0089;

v0089:
    v0020 = stack[-1];
    if (v0020 == nil) goto v0031;
    v0020 = stack[0];
    v0020 = (v0020 == nil ? lisp_true : nil);
    goto v0025;

v0025:
    if (v0020 == nil) goto v0024;
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0019);
    }

v0024:
    v0020 = stack[-1];
    v0144 = qcar(v0020);
    v0020 = stack[0];
    v0020 = qcar(v0020);
    v0019 = acons(v0144, v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-2];
    v0020 = stack[-1];
    v0020 = qcdr(v0020);
    stack[-1] = v0020;
    v0020 = stack[0];
    v0020 = qcdr(v0020);
    stack[0] = v0020;
    goto v0089;

v0031:
    v0020 = qvalue(elt(env, 1)); /* t */
    goto v0025;
/* error exit handlers */
v0145:
    popv(3);
    return nil;
}



/* Code for exprsize */

static Lisp_Object CC_exprsize(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0060;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exprsize");
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
    v0059 = (Lisp_Object)1; /* 0 */
    stack[-1] = v0059;
    goto v0112;

v0112:
    v0059 = stack[0];
    if (v0059 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0059 = stack[0];
    if (!consp(v0059)) goto v0031;
    v0059 = stack[0];
    v0059 = qcar(v0059);
    v0060 = CC_exprsize(env, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    v0059 = stack[-1];
    v0059 = plus2(v0060, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    stack[-1] = v0059;
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    stack[0] = v0059;
    goto v0112;

v0031:
    v0059 = stack[-1];
    popv(3);
    return add1(v0059);
/* error exit handlers */
v0040:
    popv(3);
    return nil;
}



/* Code for form!-sum!-and!-product!-mod!-p */

static Lisp_Object MS_CDECL CC_formKsumKandKproductKmodKp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0130, v0128, v0088;
    Lisp_Object fn;
    Lisp_Object v0018, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "form-sum-and-product-mod-p");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0017 = va_arg(aa, Lisp_Object);
    v0018 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for form-sum-and-product-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0018,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0017,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0018;
    stack[-2] = v0017;
    stack[-3] = v0000;
/* end of prologue */
    v0130 = qvalue(elt(env, 1)); /* polyzero */
    stack[-4] = v0130;
    v0130 = (Lisp_Object)17; /* 1 */
    stack[0] = v0130;
    goto v0136;

v0136:
    v0128 = stack[-1];
    v0130 = stack[0];
    v0130 = difference2(v0128, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-5];
    v0130 = Lminusp(nil, v0130);
    env = stack[-5];
    if (!(v0130 == nil)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v0128 = stack[-3];
    v0130 = stack[0];
    v0088 = *(Lisp_Object *)((char *)v0128 + (CELL-TAG_VECTOR) + ((int32_t)v0130/(16/CELL)));
    v0128 = stack[-2];
    v0130 = stack[0];
    v0130 = *(Lisp_Object *)((char *)v0128 + (CELL-TAG_VECTOR) + ((int32_t)v0130/(16/CELL)));
    fn = elt(env, 3); /* times!-mod!-p */
    v0128 = (*qfn2(fn))(qenv(fn), v0088, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-5];
    v0130 = stack[-4];
    fn = elt(env, 4); /* plus!-mod!-p */
    v0130 = (*qfn2(fn))(qenv(fn), v0128, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-5];
    stack[-4] = v0130;
    v0130 = stack[0];
    v0130 = add1(v0130);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-5];
    stack[0] = v0130;
    goto v0136;
/* error exit handlers */
v0002:
    popv(6);
    return nil;
}



/* Code for freeofdepl */

static Lisp_Object MS_CDECL CC_freeofdepl(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0020;
    Lisp_Object fn;
    Lisp_Object v0018, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "freeofdepl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0017 = va_arg(aa, Lisp_Object);
    v0018 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freeofdepl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0018,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0017,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0018;
    stack[-1] = v0017;
    stack[-2] = v0000;
/* end of prologue */

v0089:
    v0019 = stack[-2];
    if (v0019 == nil) goto v0102;
    v0020 = stack[0];
    v0019 = stack[-2];
    v0019 = qcar(v0019);
    v0019 = qcdr(v0019);
    fn = elt(env, 3); /* smember */
    v0019 = (*qfn2(fn))(qenv(fn), v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-3];
    if (v0019 == nil) goto v0106;
    v0019 = stack[-2];
    v0019 = qcar(v0019);
    v0020 = qcar(v0019);
    v0019 = stack[-1];
    fn = elt(env, 3); /* smember */
    v0019 = (*qfn2(fn))(qenv(fn), v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-3];
    if (v0019 == nil) goto v0106;
    v0019 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0019); }

v0106:
    v0019 = stack[-2];
    v0019 = qcdr(v0019);
    stack[-2] = v0019;
    goto v0089;

v0102:
    v0019 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v0019); }
/* error exit handlers */
v0145:
    popv(4);
    return nil;
}



/* Code for int!-gensym1 */

static Lisp_Object CC_intKgensym1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0147;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for int-gensym1");
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
    v0147 = qvalue(elt(env, 1)); /* gensymcount */
    v0147 = add1(v0147);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0147; /* gensymcount */
    v0147 = elt(env, 2); /* !! */
    stack[-1] = Lexplode(nil, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0147 = stack[0];
    stack[0] = Lexplode(nil, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0147 = qvalue(elt(env, 1)); /* gensymcount */
    v0147 = Lexplode(nil, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0147 = Lappend(nil, stack[0], v0147);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0147 = Lappend(nil, stack[-1], v0147);
    nil = C_nil;
    if (exception_pending()) goto v0024;
        popv(3);
        return Lcompress(nil, v0147);
/* error exit handlers */
v0024:
    popv(3);
    return nil;
}



/* Code for makecoeffshom0 */

static Lisp_Object MS_CDECL CC_makecoeffshom0(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0276, v0038;
    Lisp_Object fn;
    Lisp_Object v0018, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "makecoeffshom0");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0017 = va_arg(aa, Lisp_Object);
    v0018 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for makecoeffshom0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0018,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0017,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-7] = v0018;
    stack[-8] = v0017;
    stack[-9] = v0000;
/* end of prologue */
    v0038 = stack[-9];
    v0276 = (Lisp_Object)1; /* 0 */
    if (v0038 == v0276) goto v0089;
    v0276 = (Lisp_Object)1; /* 0 */
    stack[-10] = v0276;
    goto v0003;

v0003:
    stack[0] = stack[-7];
    v0038 = stack[-8];
    v0276 = stack[-10];
    fn = elt(env, 3); /* tayexp!-difference */
    v0276 = (*qfn2(fn))(qenv(fn), v0038, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    fn = elt(env, 4); /* tayexp!-times2 */
    v0276 = (*qfn2(fn))(qenv(fn), stack[0], v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    fn = elt(env, 5); /* tayexp!-minusp */
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    if (v0276 == nil) goto v0001;
    v0276 = qvalue(elt(env, 2)); /* nil */
    { popv(12); return onevalue(v0276); }

v0001:
    v0038 = stack[-9];
    v0276 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 3); /* tayexp!-difference */
    stack[0] = (*qfn2(fn))(qenv(fn), v0038, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0038 = stack[-8];
    v0276 = stack[-10];
    fn = elt(env, 3); /* tayexp!-difference */
    v0038 = (*qfn2(fn))(qenv(fn), v0038, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0276 = stack[-7];
    v0276 = CC_makecoeffshom0(env, 3, stack[0], v0038, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-3] = v0276;
    v0276 = stack[-3];
    if (v0276 == nil) goto v0026;
    v0276 = stack[-3];
    v0276 = qcar(v0276);
    v0038 = stack[-10];
    v0276 = cons(v0038, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0276 = ncons(v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-1] = v0276;
    stack[-2] = v0276;
    goto v0021;

v0021:
    v0276 = stack[-3];
    v0276 = qcdr(v0276);
    stack[-3] = v0276;
    v0276 = stack[-3];
    if (v0276 == nil) goto v0155;
    stack[0] = stack[-1];
    v0276 = stack[-3];
    v0276 = qcar(v0276);
    v0038 = stack[-10];
    v0276 = cons(v0038, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0276 = ncons(v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0276 = Lrplacd(nil, stack[0], v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0276 = stack[-1];
    v0276 = qcdr(v0276);
    stack[-1] = v0276;
    goto v0021;

v0155:
    v0276 = stack[-2];
    goto v0023;

v0023:
    stack[-6] = v0276;
    v0276 = stack[-6];
    fn = elt(env, 6); /* lastpair */
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-5] = v0276;
    v0038 = stack[-10];
    v0276 = stack[-7];
    fn = elt(env, 7); /* tayexp!-plus2 */
    v0276 = (*qfn2(fn))(qenv(fn), v0038, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-10] = v0276;
    v0276 = stack[-5];
    if (!consp(v0276)) goto v0003;
    else goto v0217;

v0217:
    stack[0] = stack[-7];
    v0038 = stack[-8];
    v0276 = stack[-10];
    fn = elt(env, 3); /* tayexp!-difference */
    v0276 = (*qfn2(fn))(qenv(fn), v0038, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    fn = elt(env, 4); /* tayexp!-times2 */
    v0276 = (*qfn2(fn))(qenv(fn), stack[0], v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    fn = elt(env, 5); /* tayexp!-minusp */
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    if (!(v0276 == nil)) { Lisp_Object res = stack[-6]; popv(12); return onevalue(res); }
    stack[-4] = stack[-5];
    v0038 = stack[-9];
    v0276 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 3); /* tayexp!-difference */
    stack[0] = (*qfn2(fn))(qenv(fn), v0038, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0038 = stack[-8];
    v0276 = stack[-10];
    fn = elt(env, 3); /* tayexp!-difference */
    v0038 = (*qfn2(fn))(qenv(fn), v0038, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0276 = stack[-7];
    v0276 = CC_makecoeffshom0(env, 3, stack[0], v0038, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-3] = v0276;
    v0276 = stack[-3];
    if (v0276 == nil) goto v0278;
    v0276 = stack[-3];
    v0276 = qcar(v0276);
    v0038 = stack[-10];
    v0276 = cons(v0038, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0276 = ncons(v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-1] = v0276;
    stack[-2] = v0276;
    goto v0099;

v0099:
    v0276 = stack[-3];
    v0276 = qcdr(v0276);
    stack[-3] = v0276;
    v0276 = stack[-3];
    if (v0276 == nil) goto v0279;
    stack[0] = stack[-1];
    v0276 = stack[-3];
    v0276 = qcar(v0276);
    v0038 = stack[-10];
    v0276 = cons(v0038, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0276 = ncons(v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0276 = Lrplacd(nil, stack[0], v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0276 = stack[-1];
    v0276 = qcdr(v0276);
    stack[-1] = v0276;
    goto v0099;

v0279:
    v0276 = stack[-2];
    goto v0131;

v0131:
    v0276 = Lrplacd(nil, stack[-4], v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    v0276 = stack[-5];
    fn = elt(env, 6); /* lastpair */
    v0276 = (*qfn1(fn))(qenv(fn), v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-5] = v0276;
    v0038 = stack[-10];
    v0276 = stack[-7];
    fn = elt(env, 7); /* tayexp!-plus2 */
    v0276 = (*qfn2(fn))(qenv(fn), v0038, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-11];
    stack[-10] = v0276;
    goto v0217;

v0278:
    v0276 = qvalue(elt(env, 2)); /* nil */
    goto v0131;

v0026:
    v0276 = qvalue(elt(env, 2)); /* nil */
    goto v0023;

v0089:
    v0276 = elt(env, 1); /* (nil) */
    { popv(12); return onevalue(v0276); }
/* error exit handlers */
v0277:
    popv(12);
    return nil;
}



/* Code for relation_check_p */

static Lisp_Object CC_relation_check_p(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for relation_check_p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0017;
    stack[-1] = v0000;
/* end of prologue */
    v0040 = stack[-1];
    v0138 = qcar(v0040);
    v0040 = stack[0];
    fn = elt(env, 1); /* mk_relation_mat */
    v0040 = (*qfn2(fn))(qenv(fn), v0138, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-3];
    stack[-2] = v0040;
    v0040 = stack[-1];
    v0040 = qcdr(v0040);
    v0138 = qcar(v0040);
    v0040 = stack[0];
    fn = elt(env, 1); /* mk_relation_mat */
    v0040 = (*qfn2(fn))(qenv(fn), v0138, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-3];
    v0138 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* equal!+matrices!+p */
        return (*qfn2(fn))(qenv(fn), v0138, v0040);
    }
/* error exit handlers */
v0149:
    popv(4);
    return nil;
}



/* Code for elimpt_bvl */

static Lisp_Object CC_elimpt_bvl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0094;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for elimpt_bvl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0094 = v0000;
/* end of prologue */
    v0094 = qcdr(v0094);
    v0094 = qcdr(v0094);
    v0094 = qcdr(v0094);
    v0094 = qcdr(v0094);
    v0094 = qcar(v0094);
    return onevalue(v0094);
}



/* Code for ofsf_updsignvar */

static Lisp_Object MS_CDECL CC_ofsf_updsignvar(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0137, v0026, v0027, v0028, v0086, v0087, v0083, v0280;
    Lisp_Object v0089, v0112, v0014, v0103, v0018, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 7, "ofsf_updsignvar");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0017 = va_arg(aa, Lisp_Object);
    v0018 = va_arg(aa, Lisp_Object);
    v0103 = va_arg(aa, Lisp_Object);
    v0014 = va_arg(aa, Lisp_Object);
    v0112 = va_arg(aa, Lisp_Object);
    v0089 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_updsignvar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0027 = v0089;
    v0028 = v0112;
    v0086 = v0014;
    v0087 = v0103;
    v0083 = v0018;
    v0137 = v0017;
    v0280 = v0000;
/* end of prologue */
    v0026 = v0280;
    v0137 = Lmemq(nil, v0026, v0137);
    if (v0137 == nil) goto v0147;
    v0137 = elt(env, 1); /* equal */
    return onevalue(v0137);

v0147:
    v0137 = v0280;
    v0026 = v0083;
    v0137 = Lmemq(nil, v0137, v0026);
    if (v0137 == nil) goto v0040;
    v0137 = elt(env, 2); /* greaterp */
    return onevalue(v0137);

v0040:
    v0137 = v0280;
    v0026 = v0087;
    v0137 = Lmemq(nil, v0137, v0026);
    if (v0137 == nil) goto v0096;
    v0137 = elt(env, 3); /* lessp */
    return onevalue(v0137);

v0096:
    v0137 = v0280;
    v0026 = v0086;
    v0137 = Lmemq(nil, v0137, v0026);
    if (v0137 == nil) goto v0109;
    v0137 = elt(env, 4); /* geq */
    return onevalue(v0137);

v0109:
    v0137 = v0280;
    v0026 = v0028;
    v0137 = Lmemq(nil, v0137, v0026);
    if (v0137 == nil) goto v0002;
    v0137 = elt(env, 5); /* leq */
    return onevalue(v0137);

v0002:
    v0137 = v0280;
    v0026 = v0027;
    v0137 = Lmemq(nil, v0137, v0026);
    if (v0137 == nil) goto v0084;
    v0137 = elt(env, 6); /* neq */
    return onevalue(v0137);

v0084:
    v0137 = elt(env, 7); /* unknown */
    return onevalue(v0137);
}



/* Code for logsort */

static Lisp_Object CC_logsort(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0111, v0140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for logsort");
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
    v0111 = v0000;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* !*div */
    qvalue(elt(env, 1)) = nil; /* !*div */
    stack[-3] = qvalue(elt(env, 2)); /* !*combinelogs */
    qvalue(elt(env, 2)) = nil; /* !*combinelogs */
    stack[-2] = qvalue(elt(env, 3)); /* !*expandlogs */
    qvalue(elt(env, 3)) = nil; /* !*expandlogs */
    stack[-1] = qvalue(elt(env, 4)); /* !*noneglogs */
    qvalue(elt(env, 4)) = nil; /* !*noneglogs */
    v0140 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 4)) = v0140; /* !*noneglogs */
    qvalue(elt(env, 3)) = v0140; /* !*expandlogs */
    qvalue(elt(env, 1)) = v0140; /* !*div */
    v0140 = qvalue(elt(env, 5)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*uncached */
    qvalue(elt(env, 6)) = v0140; /* !*uncached */
    fn = elt(env, 8); /* simp */
    v0111 = (*qfn1(fn))(qenv(fn), v0111);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-5];
    qvalue(elt(env, 6)) = stack[0]; /* !*uncached */
    v0140 = qvalue(elt(env, 7)); /* nil */
    qvalue(elt(env, 3)) = v0140; /* !*expandlogs */
    fn = elt(env, 9); /* prepsq!* */
    v0111 = (*qfn1(fn))(qenv(fn), v0111);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-5];
    fn = elt(env, 10); /* comblog */
    v0111 = (*qfn1(fn))(qenv(fn), v0111);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-5];
    qvalue(elt(env, 4)) = stack[-1]; /* !*noneglogs */
    qvalue(elt(env, 3)) = stack[-2]; /* !*expandlogs */
    qvalue(elt(env, 2)) = stack[-3]; /* !*combinelogs */
    qvalue(elt(env, 1)) = stack[-4]; /* !*div */
    { popv(6); return onevalue(v0111); }
/* error exit handlers */
v0105:
    env = stack[-5];
    qvalue(elt(env, 4)) = stack[-1]; /* !*noneglogs */
    qvalue(elt(env, 3)) = stack[-2]; /* !*expandlogs */
    qvalue(elt(env, 2)) = stack[-3]; /* !*combinelogs */
    qvalue(elt(env, 1)) = stack[-4]; /* !*div */
    popv(6);
    return nil;
v0148:
    env = stack[-5];
    qvalue(elt(env, 6)) = stack[0]; /* !*uncached */
    qvalue(elt(env, 4)) = stack[-1]; /* !*noneglogs */
    qvalue(elt(env, 3)) = stack[-2]; /* !*expandlogs */
    qvalue(elt(env, 2)) = stack[-3]; /* !*combinelogs */
    qvalue(elt(env, 1)) = stack[-4]; /* !*div */
    popv(6);
    return nil;
}



/* Code for bcpow */

static Lisp_Object CC_bcpow(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0034, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcpow");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0034 = v0017;
    v0033 = v0000;
/* end of prologue */
    v0024 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v0024 == nil) goto v0136;
    v0024 = v0033;
        return Lmodular_expt(nil, v0024, v0034);

v0136:
    v0024 = v0033;
    {
        fn = elt(env, 2); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v0024, v0034);
    }
}



/* Code for map_2_from_map_1 */

static Lisp_Object CC_map_2_from_map_1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0060, v0003;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for map_2_from_map_1");
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
    v0059 = stack[-1];
    fn = elt(env, 2); /* map_1_to_strand1 */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-3];
    v0059 = qvalue(elt(env, 1)); /* nil */
    stack[0] = ncons(v0059);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-3];
    v0059 = stack[-1];
    v0059 = qcar(v0059);
    v0003 = qcdr(v0059);
    v0059 = stack[-1];
    v0059 = qcar(v0059);
    v0060 = qcar(v0059);
    v0059 = stack[-1];
    v0059 = qcdr(v0059);
    fn = elt(env, 3); /* mark_edges */
    v0059 = (*qfnn(fn))(qenv(fn), 3, v0003, v0060, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    {
        Lisp_Object v0107 = stack[-2];
        Lisp_Object v0106 = stack[0];
        popv(4);
        return list3(v0107, v0106, v0059);
    }
/* error exit handlers */
v0139:
    popv(4);
    return nil;
}



/* Code for compactsq */

static Lisp_Object MS_CDECL CC_compactsq(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086, v0087, v0083, v0280;
    Lisp_Object fn;
    Lisp_Object v0018, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "compactsq");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0017 = va_arg(aa, Lisp_Object);
    v0018 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for compactsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0018,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0017,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0018;
    stack[-2] = v0017;
    stack[-3] = v0000;
/* end of prologue */
    v0086 = stack[-2];
    v0087 = qcdr(v0086);
    v0086 = (Lisp_Object)17; /* 1 */
    if (v0087 == v0086) goto v0029;
    stack[0] = elt(env, 1); /* "Relation denominator" */
    v0086 = stack[-2];
    v0086 = qcdr(v0086);
    fn = elt(env, 4); /* prepf */
    v0280 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-5];
    v0083 = elt(env, 2); /* "discarded" */
    v0087 = qvalue(elt(env, 3)); /* nil */
    v0086 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 5); /* msgpri */
    v0086 = (*qfnn(fn))(qenv(fn), 5, stack[0], v0280, v0083, v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-5];
    goto v0029;

v0029:
    v0086 = stack[-2];
    v0086 = qcar(v0086);
    stack[-2] = v0086;
    v0086 = stack[-3];
    v0083 = qcar(v0086);
    v0087 = stack[-2];
    v0086 = stack[-1];
    fn = elt(env, 6); /* compactf */
    v0087 = (*qfnn(fn))(qenv(fn), 3, v0083, v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-5];
    v0086 = (Lisp_Object)17; /* 1 */
    stack[-4] = cons(v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-5];
    stack[0] = (Lisp_Object)17; /* 1 */
    v0086 = stack[-3];
    v0083 = qcdr(v0086);
    v0087 = stack[-2];
    v0086 = stack[-1];
    fn = elt(env, 6); /* compactf */
    v0086 = (*qfnn(fn))(qenv(fn), 3, v0083, v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-5];
    v0086 = cons(stack[0], v0086);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-5];
    {
        Lisp_Object v0081 = stack[-4];
        popv(6);
        fn = elt(env, 7); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0081, v0086);
    }
/* error exit handlers */
v0125:
    popv(6);
    return nil;
}



/* Code for mo_linear */

static Lisp_Object CC_mo_linear(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0164, v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_linear");
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
    v0164 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* mo_2list */
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-1];
    stack[0] = v0164;
    v0164 = stack[0];
    v0005 = Llength(nil, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-1];
    v0164 = (Lisp_Object)17; /* 1 */
    if (v0005 == v0164) goto v0090;
    v0164 = qvalue(elt(env, 1)); /* nil */
    goto v0143;

v0143:
    if (v0164 == nil) goto v0107;
    v0164 = stack[0];
    v0164 = qcar(v0164);
    v0164 = qcar(v0164);
    { popv(2); return onevalue(v0164); }

v0107:
    v0164 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0164); }

v0090:
    v0164 = stack[0];
    v0164 = qcar(v0164);
    v0005 = qcdr(v0164);
    v0164 = (Lisp_Object)17; /* 1 */
    v0164 = (v0005 == v0164 ? lisp_true : nil);
    goto v0143;
/* error exit handlers */
v0020:
    popv(2);
    return nil;
}



/* Code for dv_compare */

static Lisp_Object MS_CDECL CC_dv_compare(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0310, v0311, v0312, v0313, v0314, v0315;
    Lisp_Object fn;
    Lisp_Object v0103, v0018, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "dv_compare");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0017 = va_arg(aa, Lisp_Object);
    v0018 = va_arg(aa, Lisp_Object);
    v0103 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dv_compare");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0103,v0018,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0017,v0018,v0103);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0103;
    stack[0] = v0018;
    stack[-6] = v0017;
    stack[-7] = v0000;
/* end of prologue */
    v0310 = stack[-6];
    v0311 = qcar(v0310);
    v0310 = (Lisp_Object)17; /* 1 */
    if (v0311 == v0310) goto v0105;
    v0311 = stack[0];
    v0310 = (Lisp_Object)17; /* 1 */
    if (v0311 == v0310) goto v0109;
    v0310 = stack[-6];
    fn = elt(env, 4); /* last_part_kern */
    v0310 = (*qfn1(fn))(qenv(fn), v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    stack[-8] = v0310;
    stack[-2] = stack[-8];
    stack[-1] = stack[-7];
    v0310 = stack[0];
    v0310 = sub1(v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    v0310 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0310/(16/CELL)));
    fn = elt(env, 5); /* sc_kern */
    v0310 = (*qfn1(fn))(qenv(fn), v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    fn = elt(env, 6); /* pa_coinc_split */
    v0310 = (*qfn2(fn))(qenv(fn), stack[-2], v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    stack[-8] = v0310;
    stack[-1] = stack[-7];
    v0310 = stack[0];
    v0310 = sub1(v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    v0310 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0310/(16/CELL)));
    fn = elt(env, 7); /* sc_rep */
    v0311 = (*qfn1(fn))(qenv(fn), v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    v0310 = stack[-8];
    v0310 = qcar(v0310);
    v0310 = cons(v0311, v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    stack[-4] = v0310;
    v0310 = stack[-8];
    v0310 = qcdr(v0310);
    stack[-8] = v0310;
    goto v0078;

v0078:
    v0311 = stack[-6];
    v0310 = stack[0];
    fn = elt(env, 8); /* can_rep_cell */
    v0310 = (*qfn2(fn))(qenv(fn), v0311, v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    stack[-3] = v0310;
    v0310 = stack[0];
    stack[-2] = v0310;
    goto v0235;

v0235:
    v0311 = stack[-3];
    v0310 = stack[-4];
    if (equal(v0311, v0310)) goto v0073;
    v0311 = stack[-3];
    v0310 = stack[-4];
    fn = elt(env, 9); /* numlist_ordp */
    v0310 = (*qfn2(fn))(qenv(fn), v0311, v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    if (v0310 == nil) goto v0211;
    v0310 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0310;
    v0311 = stack[-6];
    v0310 = (Lisp_Object)17; /* 1 */
    v0310 = Lrplaca(nil, v0311, v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    v0315 = stack[-7];
    v0314 = stack[-6];
    v0313 = stack[-2];
    v0312 = stack[-5];
    v0311 = stack[-4];
    v0310 = stack[-8];
    fn = elt(env, 10); /* dv_fill_comp_info */
    v0310 = (*qfnn(fn))(qenv(fn), 6, v0315, v0314, v0313, v0312, v0311, v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    stack[-6] = v0310;
    goto v0317;

v0317:
    v0311 = stack[-1];
    v0310 = (Lisp_Object)1; /* 0 */
    if (v0311 == v0310) goto v0318;
    v0310 = qvalue(elt(env, 2)); /* t */
    goto v0206;

v0206:
    if (v0310 == nil) goto v0235;
    v0311 = stack[-1];
    v0310 = (Lisp_Object)1; /* 0 */
    if (!(v0311 == v0310)) { Lisp_Object res = stack[-6]; popv(10); return onevalue(res); }
    v0310 = stack[-6];
    stack[0] = qcdr(v0310);
    v0311 = stack[-8];
    v0310 = stack[-6];
    v0310 = qcdr(v0310);
    v0310 = qcdr(v0310);
    v0310 = cons(v0311, v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    v0310 = Lrplacd(nil, stack[0], v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    v0311 = stack[-2];
    v0310 = stack[-5];
    if (equal(v0311, v0310)) goto v0197;
    v0310 = qvalue(elt(env, 1)); /* nil */
    goto v0319;

v0319:
    if (v0310 == nil) { Lisp_Object res = stack[-6]; popv(10); return onevalue(res); }
    v0310 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v0310; /* g_skip_to_level */
    v0311 = stack[-6];
    v0310 = (Lisp_Object)33; /* 2 */
    v0310 = Lrplaca(nil, v0311, v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    { Lisp_Object res = stack[-6]; popv(10); return onevalue(res); }

v0197:
    v0311 = stack[-7];
    v0310 = stack[-6];
    fn = elt(env, 11); /* dv_new_aut_hook */
    v0310 = (*qfn2(fn))(qenv(fn), v0311, v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    goto v0319;

v0318:
    stack[0] = stack[-2];
    v0310 = stack[-7];
    fn = elt(env, 12); /* upbve */
    v0310 = (*qfn1(fn))(qenv(fn), v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    v0310 = (equal(stack[0], v0310) ? lisp_true : nil);
    goto v0206;

v0211:
    v0310 = (Lisp_Object)33; /* 2 */
    stack[-1] = v0310;
    v0310 = stack[-6];
    stack[0] = qcdr(v0310);
    v0311 = qvalue(elt(env, 1)); /* nil */
    v0310 = stack[-6];
    v0310 = qcdr(v0310);
    v0310 = qcdr(v0310);
    v0310 = cons(v0311, v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    v0310 = Lrplacd(nil, stack[0], v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    v0311 = stack[-6];
    v0310 = (Lisp_Object)33; /* 2 */
    v0310 = Lrplaca(nil, v0311, v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    goto v0317;

v0073:
    v0310 = (Lisp_Object)1; /* 0 */
    stack[-1] = v0310;
    stack[0] = stack[-2];
    v0310 = stack[-7];
    fn = elt(env, 12); /* upbve */
    v0310 = (*qfn1(fn))(qenv(fn), v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    v0310 = (Lisp_Object)lessp2(stack[0], v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    v0310 = v0310 ? lisp_true : nil;
    env = stack[-9];
    if (v0310 == nil) goto v0317;
    v0310 = stack[-2];
    v0310 = add1(v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    stack[-2] = v0310;
    stack[-3] = stack[-8];
    stack[0] = stack[-7];
    v0310 = stack[-2];
    v0310 = sub1(v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    v0310 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0310/(16/CELL)));
    fn = elt(env, 5); /* sc_kern */
    v0310 = (*qfn1(fn))(qenv(fn), v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    fn = elt(env, 6); /* pa_coinc_split */
    v0310 = (*qfn2(fn))(qenv(fn), stack[-3], v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    stack[-8] = v0310;
    stack[0] = stack[-7];
    v0310 = stack[-2];
    v0310 = sub1(v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    v0310 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0310/(16/CELL)));
    fn = elt(env, 7); /* sc_rep */
    v0311 = (*qfn1(fn))(qenv(fn), v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    v0310 = stack[-8];
    v0310 = qcar(v0310);
    v0310 = cons(v0311, v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    stack[-4] = v0310;
    v0310 = stack[-8];
    v0310 = qcdr(v0310);
    stack[-8] = v0310;
    v0311 = stack[-6];
    v0310 = stack[-2];
    fn = elt(env, 8); /* can_rep_cell */
    v0310 = (*qfn2(fn))(qenv(fn), v0311, v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    stack[-3] = v0310;
    goto v0317;

v0109:
    v0311 = stack[-7];
    v0310 = (Lisp_Object)1; /* 0 */
    v0310 = *(Lisp_Object *)((char *)v0311 + (CELL-TAG_VECTOR) + ((int32_t)v0310/(16/CELL)));
    fn = elt(env, 5); /* sc_kern */
    v0310 = (*qfn1(fn))(qenv(fn), v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    stack[-8] = v0310;
    v0311 = stack[-7];
    v0310 = (Lisp_Object)1; /* 0 */
    v0310 = *(Lisp_Object *)((char *)v0311 + (CELL-TAG_VECTOR) + ((int32_t)v0310/(16/CELL)));
    fn = elt(env, 7); /* sc_rep */
    v0310 = (*qfn1(fn))(qenv(fn), v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    v0310 = ncons(v0310);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-9];
    stack[-4] = v0310;
    goto v0078;

v0105:
    v0315 = stack[-7];
    v0314 = stack[-6];
    v0313 = stack[0];
    v0312 = stack[-5];
    v0311 = qvalue(elt(env, 1)); /* nil */
    v0310 = qvalue(elt(env, 1)); /* nil */
    {
        popv(10);
        fn = elt(env, 10); /* dv_fill_comp_info */
        return (*qfnn(fn))(qenv(fn), 6, v0315, v0314, v0313, v0312, v0311, v0310);
    }
/* error exit handlers */
v0316:
    popv(10);
    return nil;
}



/* Code for ratplusm */

static Lisp_Object MS_CDECL CC_ratplusm(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0066, v0131, v0244;
    Lisp_Object v0018, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ratplusm");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0017 = va_arg(aa, Lisp_Object);
    v0018 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratplusm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0018,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0017,v0018);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0018;
    v0131 = v0017;
    v0244 = v0000;
/* end of prologue */
    v0066 = v0244;
    v0066 = qcar(v0066);
    stack[0] = v0066;
    v0066 = v0244;
    v0066 = qcdr(v0066);
    stack[-5] = v0066;
    v0066 = v0131;
    v0066 = qcar(v0066);
    stack[-3] = v0066;
    v0066 = v0131;
    v0066 = qcdr(v0066);
    stack[-2] = v0066;
    v0131 = stack[-5];
    v0066 = stack[-2];
    if (equal(v0131, v0066)) goto v0101;
    v0131 = stack[-5];
    v0066 = stack[-2];
    v0066 = Lgcd(nil, v0131, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    stack[-1] = v0066;
    v0131 = stack[-2];
    v0066 = stack[-1];
    v0131 = quot2(v0131, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    v0066 = stack[0];
    stack[0] = times2(v0131, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    v0131 = stack[-5];
    v0066 = stack[-1];
    v0131 = quot2(v0131, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    v0066 = stack[-3];
    v0066 = times2(v0131, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    v0066 = plus2(stack[0], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    stack[0] = v0066;
    v0131 = stack[-5];
    v0066 = stack[-1];
    v0131 = quot2(v0131, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    v0066 = stack[-2];
    v0066 = times2(v0131, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    stack[-2] = v0066;
    goto v0091;

v0091:
    v0066 = stack[-4];
    if (v0066 == nil) goto v0222;
    v0131 = stack[-2];
    v0066 = stack[-2];
    v0066 = plus2(v0131, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    stack[-2] = v0066;
    goto v0222;

v0222:
    v0131 = stack[0];
    v0066 = (Lisp_Object)1; /* 0 */
    if (v0131 == v0066) goto v0118;
    v0131 = stack[0];
    v0066 = stack[-2];
    v0066 = Lgcd(nil, v0131, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    stack[-1] = v0066;
    v0131 = stack[0];
    v0066 = stack[-1];
    stack[0] = quot2(v0131, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    v0131 = stack[-2];
    v0066 = stack[-1];
    v0066 = quot2(v0131, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    {
        Lisp_Object v0321 = stack[0];
        popv(7);
        return cons(v0321, v0066);
    }

v0118:
    v0131 = (Lisp_Object)1; /* 0 */
    v0066 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v0131, v0066);

v0101:
    v0131 = stack[0];
    v0066 = stack[-3];
    v0066 = plus2(v0131, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    stack[0] = v0066;
    v0066 = stack[-5];
    stack[-2] = v0066;
    goto v0091;
/* error exit handlers */
v0099:
    popv(7);
    return nil;
}



/* Code for general!-make!-modular!-symmetric */

static Lisp_Object CC_generalKmakeKmodularKsymmetric(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0157, v0104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-make-modular-symmetric");
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
    v0157 = stack[-1];
    if (v0157 == nil) goto v0014;
    v0157 = stack[-1];
    if (!consp(v0157)) goto v0025;
    v0157 = stack[-1];
    v0157 = qcar(v0157);
    v0157 = (consp(v0157) ? nil : lisp_true);
    goto v0032;

v0032:
    if (v0157 == nil) goto v0146;
    v0104 = stack[-1];
    v0157 = qvalue(elt(env, 3)); /* modulus!/2 */
    v0157 = (Lisp_Object)greaterp2(v0104, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    v0157 = v0157 ? lisp_true : nil;
    env = stack[-3];
    if (v0157 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0104 = stack[-1];
    v0157 = qvalue(elt(env, 4)); /* current!-modulus */
    v0157 = difference2(v0104, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 5); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v0157);
    }

v0146:
    v0157 = stack[-1];
    v0157 = qcar(v0157);
    stack[-2] = qcar(v0157);
    v0157 = stack[-1];
    v0157 = qcar(v0157);
    v0157 = qcdr(v0157);
    stack[0] = CC_generalKmakeKmodularKsymmetric(env, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-3];
    v0157 = stack[-1];
    v0157 = qcdr(v0157);
    v0157 = CC_generalKmakeKmodularKsymmetric(env, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-3];
    {
        Lisp_Object v0250 = stack[-2];
        Lisp_Object v0012 = stack[0];
        popv(4);
        fn = elt(env, 6); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0250, v0012, v0157);
    }

v0025:
    v0157 = qvalue(elt(env, 2)); /* t */
    goto v0032;

v0014:
    v0157 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0157); }
/* error exit handlers */
v0016:
    popv(4);
    return nil;
}



/* Code for coefdf */

static Lisp_Object CC_coefdf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0060, v0003, v0101;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for coefdf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0101 = v0017;
    v0003 = v0000;
/* end of prologue */

v0112:
    v0059 = v0003;
    if (v0059 == nil) goto v0094;
    v0059 = v0003;
    v0059 = qcar(v0059);
    v0060 = qcar(v0059);
    v0059 = v0101;
    if (equal(v0060, v0059)) goto v0025;
    v0059 = v0003;
    v0059 = qcdr(v0059);
    v0003 = v0059;
    goto v0112;

v0025:
    v0059 = v0003;
    v0059 = qcar(v0059);
    v0059 = qcdr(v0059);
    return onevalue(v0059);

v0094:
    v0059 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0059);
}



/* Code for fqa */

static Lisp_Object CC_fqa(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0320, v0309;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fqa");
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
    v0320 = stack[-1];
    v0320 = qcdr(v0320);
    v0309 = qcdr(v0320);
    v0320 = (Lisp_Object)1; /* 0 */
    if (v0309 == v0320) goto v0014;
    v0320 = stack[-1];
    v0320 = qcdr(v0320);
    v0309 = qcar(v0320);
    v0320 = (Lisp_Object)1; /* 0 */
    if (v0309 == v0320) goto v0060;
    v0320 = stack[-1];
    v0320 = qcdr(v0320);
    v0309 = qcar(v0320);
    v0320 = stack[-1];
    v0320 = qcdr(v0320);
    v0320 = qcdr(v0320);
    v0309 = times2(v0309, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-3];
    v0320 = (Lisp_Object)1; /* 0 */
    v0320 = (Lisp_Object)greaterp2(v0309, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    v0320 = v0320 ? lisp_true : nil;
    env = stack[-3];
    if (v0320 == nil) goto v0083;
    stack[-2] = elt(env, 1); /* !:gi!: */
    v0320 = stack[-1];
    v0320 = qcdr(v0320);
    v0320 = qcar(v0320);
    stack[0] = Labsval(nil, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-3];
    v0320 = stack[-1];
    v0320 = qcdr(v0320);
    v0320 = qcdr(v0320);
    v0320 = Labsval(nil, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    {
        Lisp_Object v0322 = stack[-2];
        Lisp_Object v0079 = stack[0];
        popv(4);
        return list2star(v0322, v0079, v0320);
    }

v0083:
    stack[-2] = elt(env, 1); /* !:gi!: */
    v0320 = stack[-1];
    v0320 = qcdr(v0320);
    v0320 = qcdr(v0320);
    stack[0] = Labsval(nil, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-3];
    v0320 = stack[-1];
    v0320 = qcdr(v0320);
    v0320 = qcar(v0320);
    v0320 = Labsval(nil, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    {
        Lisp_Object v0080 = stack[-2];
        Lisp_Object v0134 = stack[0];
        popv(4);
        return list2star(v0080, v0134, v0320);
    }

v0060:
    stack[0] = elt(env, 1); /* !:gi!: */
    v0320 = stack[-1];
    v0320 = qcdr(v0320);
    v0320 = qcdr(v0320);
    v0309 = Labsval(nil, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    v0320 = (Lisp_Object)1; /* 0 */
    {
        Lisp_Object v0275 = stack[0];
        popv(4);
        return list2star(v0275, v0309, v0320);
    }

v0014:
    v0320 = stack[-1];
    v0320 = qcdr(v0320);
    v0320 = qcar(v0320);
        popv(4);
        return Labsval(nil, v0320);
/* error exit handlers */
v0256:
    popv(4);
    return nil;
}



/* Code for pasf_atf2iv */

static Lisp_Object CC_pasf_atf2iv(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0202, v0334;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_atf2iv");
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
    stack[0] = stack[-4];
    v0202 = stack[-4];
    fn = elt(env, 12); /* cl_fvarl */
    v0202 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    v0334 = qcar(v0202);
    v0202 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 13); /* repr_atfnew */
    v0202 = (*qfnn(fn))(qenv(fn), 3, stack[0], v0334, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    stack[-5] = v0202;
    v0202 = stack[-5];
    fn = elt(env, 14); /* repr_a */
    v0202 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    stack[-3] = v0202;
    v0202 = stack[-5];
    fn = elt(env, 15); /* repr_n */
    v0202 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    stack[-2] = v0202;
    v0334 = stack[-3];
    v0202 = stack[-2];
    fn = elt(env, 16); /* pasf_floor */
    v0202 = (*qfn2(fn))(qenv(fn), v0334, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    stack[-1] = v0202;
    v0334 = stack[-3];
    v0202 = stack[-2];
    fn = elt(env, 17); /* pasf_ceil */
    v0202 = (*qfn2(fn))(qenv(fn), v0334, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    stack[0] = v0202;
    v0202 = stack[-5];
    fn = elt(env, 18); /* repr_op */
    v0334 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    v0202 = elt(env, 2); /* equal */
    if (v0334 == v0202) goto v0128;
    v0202 = stack[-5];
    fn = elt(env, 18); /* repr_op */
    v0334 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    v0202 = elt(env, 3); /* leq */
    if (v0334 == v0202) goto v0124;
    v0202 = stack[-5];
    fn = elt(env, 18); /* repr_op */
    v0334 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    v0202 = elt(env, 5); /* lessp */
    if (v0334 == v0202) goto v0275;
    v0202 = stack[-5];
    fn = elt(env, 18); /* repr_op */
    v0334 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    v0202 = elt(env, 6); /* geq */
    if (v0334 == v0202) goto v0075;
    v0202 = stack[-5];
    fn = elt(env, 18); /* repr_op */
    v0334 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    v0202 = elt(env, 8); /* greaterp */
    if (v0334 == v0202) goto v0131;
    v0202 = stack[-5];
    fn = elt(env, 18); /* repr_op */
    v0334 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    v0202 = elt(env, 9); /* neq */
    if (v0334 == v0202) goto v0336;
    v0202 = stack[-4];
    v0202 = Lconsp(nil, v0202);
    env = stack[-6];
    if (v0202 == nil) goto v0337;
    v0202 = stack[-4];
    v0202 = qcar(v0202);
    v0202 = Lconsp(nil, v0202);
    env = stack[-6];
    if (v0202 == nil) goto v0337;
    v0202 = stack[-4];
    v0202 = qcar(v0202);
    v0334 = qcar(v0202);
    v0202 = elt(env, 10); /* (cong ncong) */
    v0202 = Lmemq(nil, v0334, v0202);
    if (v0202 == nil) goto v0337;
    v0334 = stack[-2];
    v0202 = stack[-4];
    v0202 = qcar(v0202);
    v0202 = qcdr(v0202);
    fn = elt(env, 19); /* gcdf */
    v0334 = (*qfn2(fn))(qenv(fn), v0334, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    v0202 = (Lisp_Object)17; /* 1 */
    if (v0334 == v0202) goto v0209;
    v0202 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0202); }

v0209:
    v0334 = stack[-2];
    v0202 = stack[-4];
    v0202 = qcar(v0202);
    v0202 = qcdr(v0202);
    fn = elt(env, 20); /* sfto_exteucd */
    v0202 = (*qfn2(fn))(qenv(fn), v0334, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    stack[0] = v0202;
    v0202 = stack[-5];
    fn = elt(env, 18); /* repr_op */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    v0202 = stack[0];
    v0202 = qcdr(v0202);
    v0334 = qcar(v0202);
    v0202 = stack[-3];
    fn = elt(env, 21); /* multf */
    v0202 = (*qfn2(fn))(qenv(fn), v0334, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    {
        Lisp_Object v0240 = stack[-1];
        popv(7);
        fn = elt(env, 22); /* iv_newcong */
        return (*qfn2(fn))(qenv(fn), v0240, v0202);
    }

v0337:
    v0334 = elt(env, 11); /* "pasf_atf2iv: illegal operator " */
    v0202 = stack[-4];
    v0202 = qcar(v0202);
    v0202 = list2(v0334, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    fn = elt(env, 23); /* rederr */
    v0202 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    v0202 = nil;
    { popv(7); return onevalue(v0202); }

v0336:
    stack[-2] = elt(env, 4); /* minf */
    v0202 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 24); /* negf */
    v0202 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    fn = elt(env, 25); /* addf */
    v0202 = (*qfn2(fn))(qenv(fn), stack[0], v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    fn = elt(env, 26); /* iv_new */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-2], v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    v0334 = stack[-1];
    v0202 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 25); /* addf */
    v0334 = (*qfn2(fn))(qenv(fn), v0334, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    v0202 = elt(env, 7); /* pinf */
    fn = elt(env, 26); /* iv_new */
    v0202 = (*qfn2(fn))(qenv(fn), v0334, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    {
        Lisp_Object v0338 = stack[0];
        popv(7);
        fn = elt(env, 27); /* iv_merge */
        return (*qfn2(fn))(qenv(fn), v0338, v0202);
    }

v0131:
    v0334 = stack[-1];
    v0202 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 25); /* addf */
    v0334 = (*qfn2(fn))(qenv(fn), v0334, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    v0202 = elt(env, 7); /* pinf */
    {
        popv(7);
        fn = elt(env, 26); /* iv_new */
        return (*qfn2(fn))(qenv(fn), v0334, v0202);
    }

v0075:
    v0334 = stack[0];
    v0202 = elt(env, 7); /* pinf */
    {
        popv(7);
        fn = elt(env, 26); /* iv_new */
        return (*qfn2(fn))(qenv(fn), v0334, v0202);
    }

v0275:
    stack[-1] = elt(env, 4); /* minf */
    v0202 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 24); /* negf */
    v0202 = (*qfn1(fn))(qenv(fn), v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    fn = elt(env, 25); /* addf */
    v0202 = (*qfn2(fn))(qenv(fn), stack[0], v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    {
        Lisp_Object v0339 = stack[-1];
        popv(7);
        fn = elt(env, 26); /* iv_new */
        return (*qfn2(fn))(qenv(fn), v0339, v0202);
    }

v0124:
    v0334 = elt(env, 4); /* minf */
    v0202 = stack[-1];
    {
        popv(7);
        fn = elt(env, 26); /* iv_new */
        return (*qfn2(fn))(qenv(fn), v0334, v0202);
    }

v0128:
    v0334 = stack[-2];
    v0202 = (Lisp_Object)17; /* 1 */
    v0202 = Leqn(nil, v0334, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0335;
    env = stack[-6];
    if (v0202 == nil) goto v0013;
    v0334 = stack[-1];
    v0202 = stack[-1];
    {
        popv(7);
        fn = elt(env, 26); /* iv_new */
        return (*qfn2(fn))(qenv(fn), v0334, v0202);
    }

v0013:
    v0202 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0202); }
/* error exit handlers */
v0335:
    popv(7);
    return nil;
}



/* Code for bc_abs */

static Lisp_Object CC_bc_abs(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bc_abs");
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
    v0031 = stack[0];
    v0031 = qcar(v0031);
    fn = elt(env, 1); /* absf */
    v0030 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    v0031 = stack[0];
    v0031 = qcdr(v0031);
    popv(1);
    return cons(v0030, v0031);
/* error exit handlers */
v0132:
    popv(1);
    return nil;
}



/* Code for ps!:sqrt!-erule */

static Lisp_Object CC_psTsqrtKerule(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0344, v0045, v0043;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:sqrt-erule");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0017;
    v0344 = v0000;
/* end of prologue */
    v0344 = qcdr(v0344);
    v0344 = qcar(v0344);
    stack[-8] = v0344;
    v0045 = qvalue(elt(env, 1)); /* nil */
    v0344 = (Lisp_Object)17; /* 1 */
    v0344 = cons(v0045, v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    stack[0] = v0344;
    v0344 = stack[-8];
    fn = elt(env, 4); /* ps!:order */
    v0344 = (*qfn1(fn))(qenv(fn), v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    stack[-5] = v0344;
    v0344 = qvalue(elt(env, 2)); /* ps */
    fn = elt(env, 4); /* ps!:order */
    v0344 = (*qfn1(fn))(qenv(fn), v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    stack[-6] = v0344;
    v0045 = stack[-7];
    v0344 = stack[-6];
    if (equal(v0045, v0344)) goto v0144;
    v0344 = (Lisp_Object)17; /* 1 */
    stack[-4] = v0344;
    goto v0010;

v0010:
    v0045 = stack[-7];
    v0344 = stack[-6];
    v0045 = difference2(v0045, v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    v0344 = stack[-4];
    v0344 = difference2(v0045, v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    v0344 = Lminusp(nil, v0344);
    env = stack[-9];
    if (v0344 == nil) goto v0137;
    stack[-1] = stack[0];
    stack[0] = (Lisp_Object)33; /* 2 */
    v0045 = stack[-7];
    v0344 = stack[-6];
    v0344 = difference2(v0045, v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    v0045 = times2(stack[0], v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    v0344 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0045, v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    v0045 = stack[-8];
    v0344 = stack[-5];
    fn = elt(env, 5); /* ps!:evaluate */
    v0344 = (*qfn2(fn))(qenv(fn), v0045, v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    fn = elt(env, 6); /* multsq */
    v0344 = (*qfn2(fn))(qenv(fn), stack[0], v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    {
        Lisp_Object v0301 = stack[-1];
        popv(10);
        fn = elt(env, 7); /* quotsq */
        return (*qfn2(fn))(qenv(fn), v0301, v0344);
    }

v0137:
    stack[-3] = stack[0];
    v0045 = stack[-4];
    v0344 = (Lisp_Object)49; /* 3 */
    stack[0] = times2(v0045, v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    v0045 = (Lisp_Object)33; /* 2 */
    v0344 = stack[-7];
    v0344 = times2(v0045, v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    v0045 = difference2(stack[0], v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    v0344 = stack[-5];
    v0344 = plus2(v0045, v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    v0043 = v0344;
    v0045 = v0043;
    v0344 = (Lisp_Object)1; /* 0 */
    if (v0045 == v0344) goto v0345;
    v0344 = v0043;
    v0045 = v0344;
    goto v0082;

v0082:
    v0344 = (Lisp_Object)17; /* 1 */
    stack[-2] = cons(v0045, v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    stack[0] = stack[-8];
    v0045 = stack[-4];
    v0344 = stack[-5];
    v0344 = plus2(v0045, v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    fn = elt(env, 5); /* ps!:evaluate */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    stack[0] = qvalue(elt(env, 2)); /* ps */
    v0045 = stack[-7];
    v0344 = stack[-4];
    v0344 = difference2(v0045, v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    fn = elt(env, 5); /* ps!:evaluate */
    v0344 = (*qfn2(fn))(qenv(fn), stack[0], v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    fn = elt(env, 6); /* multsq */
    v0344 = (*qfn2(fn))(qenv(fn), stack[-1], v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    fn = elt(env, 6); /* multsq */
    v0344 = (*qfn2(fn))(qenv(fn), stack[-2], v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    fn = elt(env, 8); /* addsq */
    v0344 = (*qfn2(fn))(qenv(fn), stack[-3], v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    stack[0] = v0344;
    v0344 = stack[-4];
    v0344 = add1(v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    stack[-4] = v0344;
    goto v0010;

v0345:
    v0344 = qvalue(elt(env, 1)); /* nil */
    v0045 = v0344;
    goto v0082;

v0144:
    v0045 = stack[-8];
    v0344 = stack[-5];
    fn = elt(env, 5); /* ps!:evaluate */
    v0344 = (*qfn2(fn))(qenv(fn), v0045, v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    fn = elt(env, 9); /* prepsqxx */
    v0045 = (*qfn1(fn))(qenv(fn), v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    v0344 = elt(env, 3); /* (quotient 1 2) */
    v0344 = list2(v0045, v0344);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    {
        popv(10);
        fn = elt(env, 10); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v0344);
    }
/* error exit handlers */
v0302:
    popv(10);
    return nil;
}



/* Code for cr!:times */

static Lisp_Object CC_crTtimes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0017)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0027, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cr:times");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0028 = v0017;
    v0027 = v0000;
/* end of prologue */
    fn = elt(env, 5); /* crprcd2 */
    v0027 = (*qfn2(fn))(qenv(fn), v0027, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-3];
    stack[-2] = v0027;
    v0027 = qvalue(elt(env, 1)); /* !*!*roundbf */
    if (v0027 == nil) goto v0052;
    v0028 = stack[-2];
    v0027 = qvalue(elt(env, 2)); /* yy!! */
    fn = elt(env, 3); /* gftimes */
    v0027 = (*qfn2(fn))(qenv(fn), v0028, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-3];
    goto v0030;

v0030:
    {
        popv(4);
        fn = elt(env, 6); /* gf2cr!: */
        return (*qfn1(fn))(qenv(fn), v0027);
    }

v0052:
    v0028 = stack[-2];
    v0027 = qvalue(elt(env, 2)); /* yy!! */
    fn = elt(env, 7); /* safe!-crfp!-times */
    v0028 = (*qfn2(fn))(qenv(fn), v0028, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-3];
    v0027 = v0028;
    if (!(v0028 == nil)) goto v0030;
    stack[-1] = elt(env, 3); /* gftimes */
    v0027 = stack[-2];
    stack[0] = Lmkquote(nil, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-3];
    v0027 = qvalue(elt(env, 2)); /* yy!! */
    v0027 = Lmkquote(nil, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-3];
    v0028 = list3(stack[-1], stack[0], v0027);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-3];
    v0027 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 8); /* errorset!* */
    v0027 = (*qfn2(fn))(qenv(fn), v0028, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-3];
    stack[0] = v0027;
    v0027 = stack[0];
    fn = elt(env, 9); /* errorp */
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-3];
    if (v0027 == nil) goto v0085;
    fn = elt(env, 10); /* rndbfon */
    v0027 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-3];
    v0027 = stack[-2];
    fn = elt(env, 11); /* gf2bf */
    stack[0] = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-3];
    v0027 = qvalue(elt(env, 2)); /* yy!! */
    fn = elt(env, 11); /* gf2bf */
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-3];
    fn = elt(env, 3); /* gftimes */
    v0027 = (*qfn2(fn))(qenv(fn), stack[0], v0027);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[-3];
    goto v0030;

v0085:
    v0027 = stack[0];
    v0027 = qcar(v0027);
    goto v0030;
/* error exit handlers */
v0280:
    popv(4);
    return nil;
}



setup_type const u58_setup[] =
{
    {"wedge_pair",              CC_wedge_pair,  too_many_1,    wrong_no_1},
    {"addm1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_addm1},
    {":pi",                     CC_Tpi,         too_many_1,    wrong_no_1},
    {"ngetvar",                 too_few_2,      CC_ngetvar,    wrong_no_2},
    {"del-deltas",              too_few_2,      CC_delKdeltas, wrong_no_2},
    {"xprinf2",                 CC_xprinf2,     too_many_1,    wrong_no_1},
    {"mk+internal+mat",         CC_mkLinternalLmat,too_many_1, wrong_no_1},
    {"rl_ppriop",               too_few_2,      CC_rl_ppriop,  wrong_no_2},
    {"elimpt_unif",             CC_elimpt_unif, too_many_1,    wrong_no_1},
    {"codfac",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_codfac},
    {"groebfactorize3",         CC_groebfactorize3,too_many_1, wrong_no_1},
    {"sc_negtranspose",         CC_sc_negtranspose,too_many_1, wrong_no_1},
    {"ev-gamma",                CC_evKgamma,    too_many_1,    wrong_no_1},
    {"setmatpri",               too_few_2,      CC_setmatpri,  wrong_no_2},
    {"fact",                    CC_fact,        too_many_1,    wrong_no_1},
    {"polineqcheck",            too_few_2,      CC_polineqcheck,wrong_no_2},
    {"mk+scal+mult+vec",        too_few_2,      CC_mkLscalLmultLvec,wrong_no_2},
    {"rl_vonoff",               too_few_2,      CC_rl_vonoff,  wrong_no_2},
    {"rl_bettergaussp",         too_few_2,      CC_rl_bettergaussp,wrong_no_2},
    {"iv_cutcongs",             too_few_2,      CC_iv_cutcongs,wrong_no_2},
    {"ev_2f",                   too_few_2,      CC_ev_2f,      wrong_no_2},
    {"look_for_exponential",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_look_for_exponential},
    {"smaddm2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_smaddm2},
    {"rdintequiv",              CC_rdintequiv,  too_many_1,    wrong_no_1},
    {"mkffortassign",           too_few_2,      CC_mkffortassign,wrong_no_2},
    {"coeffeval",               CC_coeffeval,   too_many_1,    wrong_no_1},
    {"mv-+",                    too_few_2,      CC_mvKL,       wrong_no_2},
    {"mo=pair",                 too_few_2,      CC_moMpair,    wrong_no_2},
    {"exprsize",                CC_exprsize,    too_many_1,    wrong_no_1},
    {"form-sum-and-product-mod-p",wrong_no_na,  wrong_no_nb,   (n_args *)CC_formKsumKandKproductKmodKp},
    {"freeofdepl",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_freeofdepl},
    {"int-gensym1",             CC_intKgensym1, too_many_1,    wrong_no_1},
    {"makecoeffshom0",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_makecoeffshom0},
    {"relation_check_p",        too_few_2,      CC_relation_check_p,wrong_no_2},
    {"elimpt_bvl",              CC_elimpt_bvl,  too_many_1,    wrong_no_1},
    {"ofsf_updsignvar",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_updsignvar},
    {"logsort",                 CC_logsort,     too_many_1,    wrong_no_1},
    {"bcpow",                   too_few_2,      CC_bcpow,      wrong_no_2},
    {"map_2_from_map_1",        CC_map_2_from_map_1,too_many_1,wrong_no_1},
    {"compactsq",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_compactsq},
    {"mo_linear",               CC_mo_linear,   too_many_1,    wrong_no_1},
    {"dv_compare",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_dv_compare},
    {"ratplusm",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_ratplusm},
    {"general-make-modular-symmetric",CC_generalKmakeKmodularKsymmetric,too_many_1,wrong_no_1},
    {"coefdf",                  too_few_2,      CC_coefdf,     wrong_no_2},
    {"fqa",                     CC_fqa,         too_many_1,    wrong_no_1},
    {"pasf_atf2iv",             CC_pasf_atf2iv, too_many_1,    wrong_no_1},
    {"bc_abs",                  CC_bc_abs,      too_many_1,    wrong_no_1},
    {"ps:sqrt-erule",           too_few_2,      CC_psTsqrtKerule,wrong_no_2},
    {"cr:times",                too_few_2,      CC_crTtimes,   wrong_no_2},
    {NULL, (one_args *)"u58", (two_args *)"9372 2709789 7033170", 0}
};

/* end of generated code */
