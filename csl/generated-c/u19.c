
/* $destdir\u19.c        Machine generated C code */

/* Signature: 00000000 22-Jan-2014 */

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
#ifdef DEBUG
#define SHOW_FNAME  (exit_reason == UNWIND_THROW || \
                     (exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS   (exit_reason == UNWIND_THROW || \
                     (exit_reason & UNWIND_ARGS) != 0)
#else
#define SHOW_FNAME  ((exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS   ((exit_reason & UNWIND_ARGS) != 0)
#endif
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
extern Lisp_Object multiplication_buffer;
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
#if defined HAVE_LIBPTHREAD || defined WIN32
#include <semaphore.h>
#ifdef WIN32
#include <windows.h>
extern HANDLE kara_thread1, kara_thread2;
#define KARARESULT DWORD
#define KARAARG    LPVOID
extern KARARESULT WINAPI kara_worker1(KARAARG p);
extern KARARESULT WINAPI kara_worker2(KARAARG p);
#else
#include <pthread.h>
extern pthread_t kara_thread1, kara_thread2;
#define KARARESULT void *
#define KARAARG    void *
#define WINAPI
extern KARARESULT kara_worker1(KARAARG p);
extern KARARESULT kara_worker2(KARAARG p);
#endif
extern sem_t kara_sem1a, kara_sem1b, kara_sem1c,
             kara_sem2a, kara_sem2b, kara_sem2c;
extern int karatsuba_parallel;
#ifndef KARATSUBA_PARALLEL_CUTOFF
#  define KARATSUBA_PARALLEL_CUTOFF 120
#endif
#endif 
#ifndef KARATSUBA_CUTOFF
#define KARATSUBA_CUTOFF 12
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


/* Code for prepsq!* */

static Lisp_Object CC_prepsqH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0055, v0056;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepsq*");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v0000;
/* end of prologue */
    stack[-8] = qvalue(elt(env, 1)); /* !*combinelogs */
    qvalue(elt(env, 1)) = nil; /* !*combinelogs */
    v0054 = stack[-9];
    v0054 = qcar(v0054);
    if (v0054 == nil) goto v0057;
    v0054 = qvalue(elt(env, 2)); /* ordl!* */
    fn = elt(env, 15); /* setkorder */
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    stack[-10] = v0054;
    v0054 = qvalue(elt(env, 3)); /* factors!* */
    stack[-7] = v0054;
    goto v0059;

v0059:
    v0054 = stack[-7];
    if (v0054 == nil) goto v0060;
    v0054 = stack[-7];
    v0054 = qcar(v0054);
    v0055 = v0054;
    v0054 = v0055;
    if (symbolp(v0054)) goto v0061;
    v0054 = qvalue(elt(env, 4)); /* nil */
    goto v0062;

v0062:
    stack[-6] = v0054;
    v0054 = stack[-6];
    fn = elt(env, 16); /* lastpair */
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    stack[-5] = v0054;
    v0054 = stack[-7];
    v0054 = qcdr(v0054);
    stack[-7] = v0054;
    v0054 = stack[-5];
    if (!consp(v0054)) goto v0059;
    else goto v0063;

v0063:
    v0054 = stack[-7];
    if (v0054 == nil) goto v0064;
    stack[-4] = stack[-5];
    v0054 = stack[-7];
    v0054 = qcar(v0054);
    v0055 = v0054;
    if (symbolp(v0055)) goto v0065;
    v0054 = qvalue(elt(env, 4)); /* nil */
    goto v0066;

v0066:
    v0054 = Lrplacd(nil, stack[-4], v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0054 = stack[-5];
    fn = elt(env, 16); /* lastpair */
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    stack[-5] = v0054;
    v0054 = stack[-7];
    v0054 = qcdr(v0054);
    stack[-7] = v0054;
    goto v0063;

v0065:
    v0056 = v0054;
    v0055 = elt(env, 5); /* prepsq!*fn */
    v0055 = get(v0056, v0055);
    env = stack[-11];
    v0056 = v0055;
    if (v0055 == nil) goto v0067;
    v0055 = stack[-9];
    v0054 = Lapply2(nil, 3, v0056, v0055, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    goto v0066;

v0067:
    if (!symbolp(v0054)) v0054 = nil;
    else { v0054 = qfastgets(v0054);
           if (v0054 != nil) { v0054 = elt(v0054, 24); /* klist */
#ifdef RECORD_GET
             if (v0054 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v0054 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v0054 == SPID_NOPROP) v0054 = nil; }}
#endif
    stack[-3] = v0054;
    v0054 = stack[-3];
    if (v0054 == nil) goto v0068;
    v0054 = stack[-3];
    v0054 = qcar(v0054);
    v0054 = qcar(v0054);
    v0054 = ncons(v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    stack[-1] = v0054;
    stack[-2] = v0054;
    goto v0069;

v0069:
    v0054 = stack[-3];
    v0054 = qcdr(v0054);
    stack[-3] = v0054;
    v0054 = stack[-3];
    if (v0054 == nil) goto v0070;
    stack[0] = stack[-1];
    v0054 = stack[-3];
    v0054 = qcar(v0054);
    v0054 = qcar(v0054);
    v0054 = ncons(v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0054 = Lrplacd(nil, stack[0], v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0054 = stack[-1];
    v0054 = qcdr(v0054);
    stack[-1] = v0054;
    goto v0069;

v0070:
    v0054 = stack[-2];
    goto v0066;

v0068:
    v0054 = qvalue(elt(env, 4)); /* nil */
    goto v0066;

v0064:
    v0054 = stack[-6];
    v0055 = v0054;
    goto v0071;

v0071:
    v0054 = elt(env, 6); /* ordop */
    fn = elt(env, 17); /* sort */
    stack[0] = (*qfn2(fn))(qenv(fn), v0055, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0055 = qvalue(elt(env, 3)); /* factors!* */
    v0054 = elt(env, 6); /* ordop */
    fn = elt(env, 17); /* sort */
    v0055 = (*qfn2(fn))(qenv(fn), v0055, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0054 = qvalue(elt(env, 2)); /* ordl!* */
    v0054 = Lappend(nil, v0055, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0054 = Lappend(nil, stack[0], v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    fn = elt(env, 15); /* setkorder */
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0055 = qvalue(elt(env, 7)); /* kord!* */
    v0054 = stack[-10];
    if (equal(v0055, v0054)) goto v0072;
    v0054 = qvalue(elt(env, 8)); /* t */
    goto v0073;

v0073:
    if (v0054 == nil) goto v0074;
    v0054 = stack[-9];
    v0054 = qcar(v0054);
    fn = elt(env, 18); /* formop */
    stack[0] = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0054 = stack[-9];
    v0054 = qcdr(v0054);
    fn = elt(env, 18); /* formop */
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0054 = cons(stack[0], v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    stack[-9] = v0054;
    goto v0074;

v0074:
    v0054 = qvalue(elt(env, 10)); /* !*rat */
    if (!(v0054 == nil)) goto v0075;
    v0054 = qvalue(elt(env, 11)); /* !*div */
    if (!(v0054 == nil)) goto v0075;
    v0054 = qvalue(elt(env, 12)); /* upl!* */
    if (!(v0054 == nil)) goto v0075;
    v0054 = qvalue(elt(env, 13)); /* dnl!* */
    if (!(v0054 == nil)) goto v0075;
    v0055 = stack[-9];
    v0054 = elt(env, 14); /* prepsq!*2 */
    fn = elt(env, 19); /* sqform */
    v0054 = (*qfn2(fn))(qenv(fn), v0055, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    goto v0076;

v0076:
    stack[-9] = v0054;
    v0054 = stack[-10];
    fn = elt(env, 15); /* setkorder */
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0054 = stack[-9];
    goto v0077;

v0077:
    qvalue(elt(env, 1)) = stack[-8]; /* !*combinelogs */
    { popv(12); return onevalue(v0054); }

v0075:
    v0054 = stack[-9];
    v0056 = qcar(v0054);
    v0054 = stack[-9];
    v0055 = qcdr(v0054);
    v0054 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 20); /* prepsq!*1 */
    v0054 = (*qfnn(fn))(qenv(fn), 3, v0056, v0055, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    fn = elt(env, 21); /* replus */
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    goto v0076;

v0072:
    v0054 = qvalue(elt(env, 9)); /* wtl!* */
    goto v0073;

v0061:
    v0056 = v0055;
    v0054 = elt(env, 5); /* prepsq!*fn */
    v0054 = get(v0056, v0054);
    env = stack[-11];
    v0056 = v0054;
    if (v0054 == nil) goto v0078;
    v0054 = stack[-9];
    v0054 = Lapply2(nil, 3, v0056, v0054, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    goto v0062;

v0078:
    v0054 = v0055;
    if (!symbolp(v0054)) v0054 = nil;
    else { v0054 = qfastgets(v0054);
           if (v0054 != nil) { v0054 = elt(v0054, 24); /* klist */
#ifdef RECORD_GET
             if (v0054 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v0054 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v0054 == SPID_NOPROP) v0054 = nil; }}
#endif
    stack[-3] = v0054;
    v0054 = stack[-3];
    if (v0054 == nil) goto v0079;
    v0054 = stack[-3];
    v0054 = qcar(v0054);
    v0054 = qcar(v0054);
    v0054 = ncons(v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    stack[-1] = v0054;
    stack[-2] = v0054;
    goto v0080;

v0080:
    v0054 = stack[-3];
    v0054 = qcdr(v0054);
    stack[-3] = v0054;
    v0054 = stack[-3];
    if (v0054 == nil) goto v0081;
    stack[0] = stack[-1];
    v0054 = stack[-3];
    v0054 = qcar(v0054);
    v0054 = qcar(v0054);
    v0054 = ncons(v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0054 = Lrplacd(nil, stack[0], v0054);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-11];
    v0054 = stack[-1];
    v0054 = qcdr(v0054);
    stack[-1] = v0054;
    goto v0080;

v0081:
    v0054 = stack[-2];
    goto v0062;

v0079:
    v0054 = qvalue(elt(env, 4)); /* nil */
    goto v0062;

v0060:
    v0054 = qvalue(elt(env, 4)); /* nil */
    v0055 = v0054;
    goto v0071;

v0057:
    v0054 = (Lisp_Object)1; /* 0 */
    goto v0077;
/* error exit handlers */
v0058:
    env = stack[-11];
    qvalue(elt(env, 1)) = stack[-8]; /* !*combinelogs */
    popv(12);
    return nil;
}



/* Code for cl_fvarl */

static Lisp_Object CC_cl_fvarl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084, v0085;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_fvarl");
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
    v0084 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* cl_fvarl1 */
    v0085 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[0];
    v0084 = elt(env, 1); /* ordp */
    {
        popv(1);
        fn = elt(env, 3); /* sort */
        return (*qfn2(fn))(qenv(fn), v0085, v0084);
    }
/* error exit handlers */
v0086:
    popv(1);
    return nil;
}



/* Code for ibalp_tvb */

static Lisp_Object CC_ibalp_tvb(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0092, v0093;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_tvb");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0087;
    v0092 = v0000;
/* end of prologue */
    stack[-2] = v0092;
    goto v0077;

v0077:
    v0092 = stack[-2];
    if (v0092 == nil) goto v0083;
    v0092 = stack[-2];
    v0092 = qcar(v0092);
    stack[0] = v0092;
    v0092 = stack[0];
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0093 = qcar(v0092);
    v0092 = stack[-1];
    v0092 = (Lisp_Object)geq2(v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    v0092 = v0092 ? lisp_true : nil;
    env = stack[-3];
    if (v0092 == nil) goto v0095;
    v0092 = stack[0];
    v0093 = qcdr(v0092);
    v0092 = stack[0];
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0092 = qcar(v0092);
    fn = elt(env, 2); /* ibalp_var!-unset */
    v0092 = (*qfn2(fn))(qenv(fn), v0093, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    goto v0095;

v0095:
    v0092 = stack[-2];
    v0092 = qcdr(v0092);
    stack[-2] = v0092;
    goto v0077;

v0083:
    v0092 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0092); }
/* error exit handlers */
v0094:
    popv(4);
    return nil;
}



/* Code for ratpoly_tad */

static Lisp_Object CC_ratpoly_tad(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084, v0085;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratpoly_tad");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0084 = v0000;
/* end of prologue */
    v0085 = qcar(v0084);
    v0084 = (Lisp_Object)17; /* 1 */
    return cons(v0085, v0084);
}



/* Code for applyrd */

static Lisp_Object MS_CDECL CC_applyrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0100, v0101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "applyrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for applyrd");
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
    fn = elt(env, 7); /* lex */
    v0100 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-1];
    v0101 = qvalue(elt(env, 1)); /* atts */
    v0100 = elt(env, 2); /* (type definitionurl encoding) */
    fn = elt(env, 8); /* retattributes */
    v0100 = (*qfn2(fn))(qenv(fn), v0101, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-1];
    qvalue(elt(env, 3)) = v0100; /* mmlatts */
    v0100 = qvalue(elt(env, 4)); /* char */
    fn = elt(env, 9); /* compress!* */
    v0101 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-1];
    v0100 = qvalue(elt(env, 5)); /* functions!* */
    v0100 = Lassoc(nil, v0101, v0100);
    stack[0] = v0100;
    if (v0100 == nil) goto v0102;
    v0100 = stack[0];
    v0100 = qcdr(v0100);
    v0101 = qcar(v0100);
    v0100 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 10); /* apply */
    v0100 = (*qfn2(fn))(qenv(fn), v0101, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-1];
    v0101 = v0100;
    v0100 = qvalue(elt(env, 3)); /* mmlatts */
    v0100 = cons(v0100, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-1];
    v0101 = v0100;
    v0100 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 3)) = v0100; /* mmlatts */
    v0100 = stack[0];
    v0100 = qcdr(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcar(v0100);
    popv(2);
    return cons(v0100, v0101);

v0102:
    v0100 = qvalue(elt(env, 4)); /* char */
    v0101 = Lcompress(nil, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-1];
    v0100 = (Lisp_Object)273; /* 17 */
    fn = elt(env, 11); /* errorml */
    v0100 = (*qfn2(fn))(qenv(fn), v0101, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    v0100 = nil;
    { popv(2); return onevalue(v0100); }
/* error exit handlers */
v0051:
    popv(2);
    return nil;
}



/* Code for rd!:zerop!: */

static Lisp_Object CC_rdTzeropT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090, v0103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:zerop:");
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
    v0103 = v0000;
/* end of prologue */
    v0090 = v0103;
    v0090 = qcdr(v0090);
    if (!consp(v0090)) goto v0002;
    v0090 = v0103;
    fn = elt(env, 1); /* round!* */
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* bfzerop!: */
        return (*qfn1(fn))(qenv(fn), v0090);
    }

v0002:
    v0090 = v0103;
    v0090 = qcdr(v0090);
    {
        popv(1);
        fn = elt(env, 3); /* ft!:zerop */
        return (*qfn1(fn))(qenv(fn), v0090);
    }
/* error exit handlers */
v0095:
    popv(1);
    return nil;
}



/* Code for freeoff */

static Lisp_Object CC_freeoff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0110, v0111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freeoff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0087;
    stack[-1] = v0000;
/* end of prologue */

v0001:
    v0110 = stack[-1];
    if (!consp(v0110)) goto v0085;
    v0110 = stack[-1];
    v0110 = qcar(v0110);
    v0110 = (consp(v0110) ? nil : lisp_true);
    goto v0084;

v0084:
    if (v0110 == nil) goto v0057;
    v0110 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0110); }

v0057:
    v0110 = stack[-1];
    v0110 = qcar(v0110);
    v0110 = qcar(v0110);
    v0110 = qcar(v0110);
    fn = elt(env, 3); /* sfp */
    v0110 = (*qfn1(fn))(qenv(fn), v0110);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    if (v0110 == nil) goto v0078;
    v0110 = stack[-1];
    v0110 = qcar(v0110);
    v0110 = qcar(v0110);
    v0111 = qcar(v0110);
    v0110 = stack[0];
    v0110 = CC_freeoff(env, v0111, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    if (v0110 == nil) goto v0112;
    v0110 = stack[-1];
    v0110 = qcar(v0110);
    v0111 = qcdr(v0110);
    v0110 = stack[0];
    v0110 = CC_freeoff(env, v0111, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    if (v0110 == nil) goto v0052;
    v0110 = stack[-1];
    v0110 = qcdr(v0110);
    stack[-1] = v0110;
    goto v0001;

v0052:
    v0110 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0110); }

v0112:
    v0110 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0110); }

v0078:
    v0110 = stack[-1];
    v0110 = qcar(v0110);
    v0110 = qcar(v0110);
    v0111 = qcar(v0110);
    v0110 = stack[0];
    fn = elt(env, 4); /* ndepends */
    v0110 = (*qfn2(fn))(qenv(fn), v0111, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    if (v0110 == nil) goto v0113;
    v0110 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0110); }

v0113:
    v0110 = stack[-1];
    v0110 = qcar(v0110);
    v0111 = qcdr(v0110);
    v0110 = stack[0];
    v0110 = CC_freeoff(env, v0111, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    if (v0110 == nil) goto v0081;
    v0110 = stack[-1];
    v0110 = qcdr(v0110);
    stack[-1] = v0110;
    goto v0001;

v0081:
    v0110 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0110); }

v0085:
    v0110 = qvalue(elt(env, 1)); /* t */
    goto v0084;
/* error exit handlers */
v0043:
    popv(3);
    return nil;
}



/* Code for wedgek2 */

static Lisp_Object MS_CDECL CC_wedgek2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0141, v0019, v0020;
    Lisp_Object fn;
    Lisp_Object v0003, v0087, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "wedgek2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0087 = va_arg(aa, Lisp_Object);
    v0003 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wedgek2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0003,v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0087,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v0003;
    stack[-3] = v0087;
    stack[-4] = v0000;
/* end of prologue */

v0142:
    v0019 = stack[-4];
    v0141 = stack[-3];
    v0141 = qcar(v0141);
    if (v0019 == v0141) goto v0143;
    v0141 = qvalue(elt(env, 2)); /* nil */
    goto v0085;

v0085:
    if (v0141 == nil) goto v0047;
    v0141 = stack[-4];
    fn = elt(env, 3); /* deg!*form */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    v0019 = v0141;
    v0141 = v0019;
    v0141 = integerp(v0141);
    if (v0141 == nil) goto v0088;
    v0141 = v0019;
    v0141 = Loddp(nil, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    goto v0098;

v0098:
    if (v0141 == nil) goto v0096;
    v0141 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v0141); }

v0096:
    v0019 = stack[-4];
    v0141 = stack[-3];
    v0141 = cons(v0019, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    fn = elt(env, 4); /* wedgef */
    stack[0] = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    v0141 = stack[-2];
    fn = elt(env, 5); /* mksgnsq */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    {
        Lisp_Object v0144 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v0144, v0141);
    }

v0088:
    v0141 = qvalue(elt(env, 2)); /* nil */
    goto v0098;

v0047:
    v0141 = stack[-3];
    v0019 = qcar(v0141);
    v0141 = elt(env, 1); /* wedge */
    if (!consp(v0019)) goto v0145;
    v0019 = qcar(v0019);
    if (!(v0019 == v0141)) goto v0145;
    v0141 = stack[-3];
    v0141 = qcar(v0141);
    v0141 = qcdr(v0141);
    stack[-3] = v0141;
    goto v0142;

v0145:
    v0019 = stack[-4];
    v0141 = elt(env, 1); /* wedge */
    if (!consp(v0019)) goto v0146;
    v0019 = qcar(v0019);
    if (!(v0019 == v0141)) goto v0146;
    v0141 = stack[-4];
    v0019 = qcdr(v0141);
    v0141 = stack[-3];
    fn = elt(env, 7); /* wedgewedge */
    stack[0] = (*qfn2(fn))(qenv(fn), v0019, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    v0141 = stack[-2];
    fn = elt(env, 5); /* mksgnsq */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    {
        Lisp_Object v0147 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v0147, v0141);
    }

v0146:
    v0019 = stack[-4];
    v0141 = stack[-3];
    v0141 = qcar(v0141);
    fn = elt(env, 8); /* worderp */
    v0141 = (*qfn2(fn))(qenv(fn), v0019, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    if (v0141 == nil) goto v0148;
    v0019 = stack[-4];
    v0141 = stack[-3];
    v0141 = cons(v0019, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    fn = elt(env, 4); /* wedgef */
    stack[0] = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    v0141 = stack[-2];
    fn = elt(env, 5); /* mksgnsq */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    {
        Lisp_Object v0149 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v0149, v0141);
    }

v0148:
    v0141 = stack[-3];
    v0141 = qcdr(v0141);
    if (v0141 == nil) goto v0150;
    v0141 = stack[-3];
    v0020 = qcar(v0141);
    v0019 = (Lisp_Object)17; /* 1 */
    v0141 = (Lisp_Object)17; /* 1 */
    v0141 = list2star(v0020, v0019, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    stack[-5] = ncons(v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    stack[-1] = stack[-4];
    v0141 = stack[-3];
    stack[0] = qcdr(v0141);
    v0141 = stack[-4];
    fn = elt(env, 3); /* deg!*form */
    stack[-4] = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    v0141 = stack[-3];
    v0141 = qcar(v0141);
    fn = elt(env, 3); /* deg!*form */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    fn = elt(env, 9); /* multf */
    v0141 = (*qfn2(fn))(qenv(fn), stack[-4], v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    fn = elt(env, 10); /* addf */
    v0141 = (*qfn2(fn))(qenv(fn), stack[-2], v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    v0141 = CC_wedgek2(env, 3, stack[-1], stack[0], v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    {
        Lisp_Object v0151 = stack[-5];
        popv(7);
        fn = elt(env, 11); /* wedgepf2 */
        return (*qfn2(fn))(qenv(fn), v0151, v0141);
    }

v0150:
    v0141 = stack[-3];
    v0019 = qcar(v0141);
    v0141 = stack[-4];
    v0141 = list2(v0019, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    fn = elt(env, 4); /* wedgef */
    stack[0] = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    stack[-1] = stack[-2];
    v0141 = stack[-4];
    fn = elt(env, 3); /* deg!*form */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    v0141 = stack[-3];
    v0141 = qcar(v0141);
    fn = elt(env, 3); /* deg!*form */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    fn = elt(env, 9); /* multf */
    v0141 = (*qfn2(fn))(qenv(fn), stack[-2], v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    fn = elt(env, 10); /* addf */
    v0141 = (*qfn2(fn))(qenv(fn), stack[-1], v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    fn = elt(env, 5); /* mksgnsq */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-6];
    {
        Lisp_Object v0152 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v0152, v0141);
    }

v0143:
    v0019 = stack[-4];
    v0141 = elt(env, 1); /* wedge */
    v0141 = Leqcar(nil, v0019, v0141);
    env = stack[-6];
    v0141 = (v0141 == nil ? lisp_true : nil);
    goto v0085;
/* error exit handlers */
v0073:
    popv(7);
    return nil;
}



/* Code for indordp */

static Lisp_Object CC_indordp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0053, v0136, v0112, v0096;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0112 = v0087;
    v0096 = v0000;
/* end of prologue */
    v0052 = qvalue(elt(env, 1)); /* indxl!* */
    v0136 = v0052;
    v0053 = v0096;
    v0052 = v0136;
    v0052 = Lmemq(nil, v0053, v0052);
    if (!(v0052 == nil)) goto v0077;
    v0052 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0052);

v0077:
    v0052 = v0136;
    if (v0052 == nil) goto v0155;
    v0053 = v0096;
    v0052 = v0136;
    v0052 = qcar(v0052);
    if (v0053 == v0052) goto v0091;
    v0053 = v0112;
    v0052 = v0136;
    v0052 = qcar(v0052);
    if (v0053 == v0052) goto v0062;
    v0052 = v0136;
    v0052 = qcdr(v0052);
    v0136 = v0052;
    goto v0077;

v0062:
    v0052 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0052);

v0091:
    v0052 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0052);

v0155:
    v0052 = v0096;
    v0053 = v0112;
        return Lorderp(nil, v0052, v0053);
}



/* Code for sfpx1 */

static Lisp_Object MS_CDECL CC_sfpx1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0073, v0144, v0147, v0149, v0151;
    Lisp_Object fn;
    Lisp_Object v0002, v0036, v0003, v0087, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "sfpx1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0087 = va_arg(aa, Lisp_Object);
    v0003 = va_arg(aa, Lisp_Object);
    v0036 = va_arg(aa, Lisp_Object);
    v0002 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfpx1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0002,v0036,v0003,v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0087,v0003,v0036,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0002;
    stack[-4] = v0036;
    stack[-5] = v0003;
    stack[-6] = v0087;
    v0149 = v0000;
/* end of prologue */

v0180:
    v0073 = v0149;
    if (!consp(v0073)) goto v0181;
    v0073 = v0149;
    v0073 = qcar(v0073);
    v0073 = (consp(v0073) ? nil : lisp_true);
    goto v0139;

v0139:
    if (v0073 == nil) goto v0090;
    v0073 = qvalue(elt(env, 1)); /* t */
    { popv(9); return onevalue(v0073); }

v0090:
    v0073 = v0149;
    v0073 = Lconsp(nil, v0073);
    env = stack[-8];
    if (v0073 == nil) goto v0154;
    v0073 = v0149;
    v0073 = qcar(v0073);
    v0144 = v0149;
    v0144 = qcdr(v0144);
    stack[-2] = v0144;
    v0144 = v0073;
    v0144 = Lconsp(nil, v0144);
    env = stack[-8];
    if (v0144 == nil) goto v0088;
    v0144 = v0073;
    v0144 = qcdr(v0144);
    stack[-7] = v0144;
    v0073 = qcar(v0073);
    stack[0] = v0073;
    v0073 = stack[0];
    v0073 = Lconsp(nil, v0073);
    env = stack[-8];
    if (v0073 == nil) goto v0061;
    v0073 = stack[0];
    v0073 = qcar(v0073);
    stack[-1] = v0073;
    v0073 = stack[-1];
    fn = elt(env, 3); /* assert_kernelp */
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-8];
    if (v0073 == nil) goto v0096;
    v0073 = stack[0];
    v0073 = qcdr(v0073);
    stack[0] = v0073;
    v0144 = stack[-1];
    v0073 = stack[-5];
    if (v0144 == v0073) goto v0183;
    v0073 = stack[-5];
    if (v0073 == nil) goto v0184;
    v0144 = stack[-5];
    v0073 = stack[-6];
    v0073 = cons(v0144, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-8];
    stack[-6] = v0073;
    goto v0184;

v0184:
    v0073 = stack[-3];
    if (v0073 == nil) goto v0185;
    v0073 = stack[-6];
    if (v0073 == nil) goto v0185;
    v0144 = stack[-1];
    v0073 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 4); /* to */
    stack[-4] = (*qfn2(fn))(qenv(fn), v0144, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-8];
    v0073 = stack[-6];
    v0144 = qcar(v0073);
    v0073 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 4); /* to */
    v0073 = (*qfn2(fn))(qenv(fn), v0144, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-8];
    fn = elt(env, 5); /* ordpp */
    v0073 = (*qfn2(fn))(qenv(fn), stack[-4], v0073);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-8];
    if (v0073 == nil) goto v0185;
    v0073 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0073); }

v0185:
    stack[-4] = stack[-7];
    v0144 = stack[-1];
    v0073 = stack[-6];
    v0149 = cons(v0144, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-8];
    v0147 = qvalue(elt(env, 2)); /* nil */
    v0144 = (Lisp_Object)1; /* 0 */
    v0073 = stack[-3];
    v0073 = CC_sfpx1(env, 5, stack[-4], v0149, v0147, v0144, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-8];
    if (v0073 == nil) goto v0186;
    v0149 = stack[-2];
    v0151 = stack[-6];
    v0147 = stack[-1];
    v0144 = stack[0];
    v0073 = stack[-3];
    stack[-6] = v0151;
    stack[-5] = v0147;
    stack[-4] = v0144;
    stack[-3] = v0073;
    goto v0180;

v0186:
    v0073 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0073); }

v0183:
    v0144 = stack[0];
    v0073 = stack[-4];
    v0073 = (Lisp_Object)lessp2(v0144, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    v0073 = v0073 ? lisp_true : nil;
    env = stack[-8];
    if (v0073 == nil) goto v0187;
    stack[-1] = stack[-7];
    v0144 = stack[-5];
    v0073 = stack[-6];
    v0149 = cons(v0144, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-8];
    v0147 = qvalue(elt(env, 2)); /* nil */
    v0144 = (Lisp_Object)1; /* 0 */
    v0073 = stack[-3];
    v0073 = CC_sfpx1(env, 5, stack[-1], v0149, v0147, v0144, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-8];
    if (v0073 == nil) goto v0081;
    v0149 = stack[-2];
    v0151 = stack[-6];
    v0147 = stack[-5];
    v0144 = stack[0];
    v0073 = stack[-3];
    stack[-6] = v0151;
    stack[-5] = v0147;
    stack[-4] = v0144;
    stack[-3] = v0073;
    goto v0180;

v0081:
    v0073 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0073); }

v0187:
    v0073 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0073); }

v0096:
    v0073 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0073); }

v0061:
    v0073 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0073); }

v0088:
    v0073 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0073); }

v0154:
    v0073 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0073); }

v0181:
    v0073 = qvalue(elt(env, 1)); /* t */
    goto v0139;
/* error exit handlers */
v0182:
    popv(9);
    return nil;
}



/* Code for fs!:times */

static Lisp_Object CC_fsTtimes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:times");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0087;
    stack[-1] = v0000;
/* end of prologue */
    v0089 = stack[-1];
    if (v0089 == nil) goto v0001;
    v0089 = stack[0];
    if (v0089 == nil) goto v0057;
    v0188 = stack[-1];
    v0089 = stack[0];
    fn = elt(env, 2); /* fs!:timesterm */
    v0089 = (*qfn2(fn))(qenv(fn), v0188, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-3];
    stack[-2] = v0089;
    v0188 = stack[-1];
    v0089 = (Lisp_Object)49; /* 3 */
    v0188 = *(Lisp_Object *)((char *)v0188 + (CELL-TAG_VECTOR) + ((int32_t)v0089/(16/CELL)));
    v0089 = stack[0];
    v0089 = CC_fsTtimes(env, v0188, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0189;
    env = stack[-3];
    {
        Lisp_Object v0153 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v0153, v0089);
    }

v0057:
    v0089 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0089); }

v0001:
    v0089 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0089); }
/* error exit handlers */
v0189:
    popv(4);
    return nil;
}



/* Code for symbvarlst */

static Lisp_Object MS_CDECL CC_symbvarlst(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0110, v0111, v0195;
    Lisp_Object fn;
    Lisp_Object v0003, v0087, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "symbvarlst");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0087 = va_arg(aa, Lisp_Object);
    v0003 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for symbvarlst");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0003,v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0087,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0110 = v0003;
    stack[-3] = v0087;
    v0195 = v0000;
/* end of prologue */
    v0111 = v0110;
    v0110 = elt(env, 1); /* symbolic */
    if (v0111 == v0110) goto v0083;
    v0110 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0110); }

v0083:
    v0110 = v0195;
    stack[-4] = v0110;
    goto v0082;

v0082:
    v0110 = stack[-4];
    if (v0110 == nil) goto v0143;
    v0110 = stack[-4];
    v0110 = qcar(v0110);
    v0110 = Lconsp(nil, v0110);
    env = stack[-5];
    if (v0110 == nil) goto v0196;
    v0110 = stack[-4];
    v0110 = qcar(v0110);
    v0110 = qcar(v0110);
    goto v0039;

v0039:
    stack[0] = v0110;
    v0110 = stack[0];
    v0110 = Lsymbol_specialp(nil, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-5];
    if (v0110 == nil) goto v0089;
    v0110 = qvalue(elt(env, 2)); /* nil */
    goto v0062;

v0062:
    if (v0110 == nil) goto v0098;
    stack[-2] = elt(env, 4); /* "local variable" */
    stack[-1] = stack[0];
    stack[0] = elt(env, 5); /* "in procedure" */
    v0111 = qvalue(elt(env, 6)); /* fname!* */
    v0110 = elt(env, 7); /* "not used" */
    v0110 = list2(v0111, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-5];
    v0110 = list3star(stack[-2], stack[-1], stack[0], v0110);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-5];
    fn = elt(env, 8); /* lprim */
    v0110 = (*qfn1(fn))(qenv(fn), v0110);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-5];
    goto v0098;

v0098:
    v0110 = stack[-4];
    v0110 = qcdr(v0110);
    stack[-4] = v0110;
    goto v0082;

v0089:
    v0110 = stack[0];
    v0110 = Lsymbol_globalp(nil, v0110);
    env = stack[-5];
    if (v0110 == nil) goto v0112;
    v0110 = qvalue(elt(env, 2)); /* nil */
    goto v0062;

v0112:
    v0111 = stack[0];
    v0110 = stack[-3];
    v0110 = Lsmemq(nil, v0111, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-5];
    if (v0110 == nil) goto v0052;
    v0110 = qvalue(elt(env, 2)); /* nil */
    goto v0062;

v0052:
    v0110 = qvalue(elt(env, 3)); /* !*novarmsg */
    v0110 = (v0110 == nil ? lisp_true : nil);
    goto v0062;

v0196:
    v0110 = stack[-4];
    v0110 = qcar(v0110);
    goto v0039;

v0143:
    v0110 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0110); }
/* error exit handlers */
v0167:
    popv(6);
    return nil;
}



/* Code for evaluatecoeffts */

static Lisp_Object CC_evaluatecoeffts(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0170, v0130, v0166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evaluatecoeffts");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0087;
    stack[-1] = v0000;
/* end of prologue */
    v0170 = stack[-1];
    if (v0170 == nil) goto v0057;
    v0170 = stack[-1];
    if (!consp(v0170)) goto v0103;
    v0170 = stack[-1];
    v0170 = qcar(v0170);
    v0170 = (consp(v0170) ? nil : lisp_true);
    goto v0082;

v0082:
    if (v0170 == nil) goto v0201;
    v0130 = stack[-1];
    v0170 = (Lisp_Object)1; /* 0 */
    if (!(v0130 == v0170)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0170 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0170); }

v0201:
    v0170 = stack[-1];
    v0170 = qcar(v0170);
    v0170 = qcar(v0170);
    v0130 = qcar(v0170);
    v0170 = qvalue(elt(env, 3)); /* indexlist */
    v0170 = Lmember(nil, v0130, v0170);
    if (v0170 == nil) goto v0202;
    v0170 = stack[-1];
    v0170 = qcar(v0170);
    v0170 = qcar(v0170);
    v0166 = qcar(v0170);
    v0130 = stack[0];
    v0170 = qvalue(elt(env, 3)); /* indexlist */
    fn = elt(env, 4); /* valuecoefft */
    v0170 = (*qfnn(fn))(qenv(fn), 3, v0166, v0130, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-3];
    goto v0204;

v0204:
    stack[-2] = v0170;
    v0170 = stack[-1];
    v0170 = qcar(v0170);
    v0130 = qcdr(v0170);
    v0170 = stack[0];
    v0170 = CC_evaluatecoeffts(env, v0130, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-3];
    fn = elt(env, 5); /* !*multf */
    v0170 = (*qfn2(fn))(qenv(fn), stack[-2], v0170);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-3];
    stack[-2] = v0170;
    v0170 = stack[-1];
    v0130 = qcdr(v0170);
    v0170 = stack[0];
    v0170 = CC_evaluatecoeffts(env, v0130, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-3];
    {
        Lisp_Object v0205 = stack[-2];
        popv(4);
        fn = elt(env, 6); /* addf */
        return (*qfn2(fn))(qenv(fn), v0205, v0170);
    }

v0202:
    v0170 = stack[-1];
    v0170 = qcar(v0170);
    v0130 = qcar(v0170);
    v0170 = (Lisp_Object)17; /* 1 */
    v0170 = cons(v0130, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-3];
    v0170 = ncons(v0170);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-3];
    goto v0204;

v0103:
    v0170 = qvalue(elt(env, 1)); /* t */
    goto v0082;

v0057:
    v0170 = qvalue(elt(env, 1)); /* t */
    goto v0082;
/* error exit handlers */
v0203:
    popv(4);
    return nil;
}



/* Code for qqe_arg!-check */

static Lisp_Object CC_qqe_argKcheck(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0113, v0204;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_arg-check");
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
    v0113 = stack[0];
    v0113 = qcar(v0113);
    stack[-1] = v0113;
    v0113 = stack[-1];
    fn = elt(env, 4); /* qqe_rqopp */
    v0113 = (*qfn1(fn))(qenv(fn), v0113);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-2];
    if (v0113 == nil) goto v0082;
    v0113 = stack[0];
    fn = elt(env, 5); /* qqe_arg!-check!-lq!-rq */
    v0113 = (*qfn1(fn))(qenv(fn), v0113);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-2];
    goto v0077;

v0077:
    v0113 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0113); }

v0082:
    v0113 = stack[-1];
    fn = elt(env, 6); /* qqe_rbopp */
    v0113 = (*qfn1(fn))(qenv(fn), v0113);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-2];
    if (v0113 == nil) goto v0206;
    v0113 = stack[0];
    fn = elt(env, 7); /* qqe_arg!-check!-lb!-rb */
    v0113 = (*qfn1(fn))(qenv(fn), v0113);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-2];
    goto v0077;

v0206:
    v0113 = stack[-1];
    fn = elt(env, 8); /* qqe_qopheadp */
    v0113 = (*qfn1(fn))(qenv(fn), v0113);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-2];
    if (!(v0113 == nil)) goto v0174;
    v0113 = stack[-1];
    fn = elt(env, 9); /* qqe_qoptailp */
    v0113 = (*qfn1(fn))(qenv(fn), v0113);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-2];
    if (!(v0113 == nil)) goto v0174;
    v0113 = stack[-1];
    fn = elt(env, 10); /* qqe_qopaddp */
    v0113 = (*qfn1(fn))(qenv(fn), v0113);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-2];
    if (v0113 == nil) goto v0093;
    v0113 = stack[0];
    fn = elt(env, 11); /* qqe_arg!-check!-lb!-rq */
    v0113 = (*qfn1(fn))(qenv(fn), v0113);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-2];
    goto v0077;

v0093:
    v0113 = stack[0];
    v0113 = qcdr(v0113);
    stack[-1] = v0113;
    goto v0108;

v0108:
    v0113 = stack[-1];
    if (v0113 == nil) goto v0077;
    v0113 = stack[-1];
    v0113 = qcar(v0113);
    fn = elt(env, 12); /* qqe_arg!-check!-b */
    v0113 = (*qfn1(fn))(qenv(fn), v0113);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-2];
    if (!(v0113 == nil)) goto v0051;
    fn = elt(env, 13); /* qqe_arg!-check!-marked!-ids!-rollback */
    v0113 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-2];
    v0204 = stack[0];
    v0113 = elt(env, 3); /* "some arguments are not of basic type" */
    fn = elt(env, 14); /* typerr */
    v0113 = (*qfn2(fn))(qenv(fn), v0204, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-2];
    goto v0051;

v0051:
    v0113 = stack[-1];
    v0113 = qcdr(v0113);
    stack[-1] = v0113;
    goto v0108;

v0174:
    v0113 = stack[0];
    v0113 = qcdr(v0113);
    v0113 = qcar(v0113);
    fn = elt(env, 15); /* qqe_arg!-check!-q */
    v0113 = (*qfn1(fn))(qenv(fn), v0113);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-2];
    if (!(v0113 == nil)) goto v0077;
    fn = elt(env, 13); /* qqe_arg!-check!-marked!-ids!-rollback */
    v0113 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-2];
    v0204 = stack[0];
    v0113 = elt(env, 1); /* "some arguments are not of queue type" */
    fn = elt(env, 14); /* typerr */
    v0113 = (*qfn2(fn))(qenv(fn), v0204, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-2];
    goto v0077;
/* error exit handlers */
v0171:
    popv(3);
    return nil;
}



/* Code for pasf_vf */

static Lisp_Object CC_pasf_vf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0166, v0131, v0207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_vf");
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
    v0131 = v0000;
/* end of prologue */
    v0207 = v0131;
    v0166 = elt(env, 1); /* true */
    if (v0207 == v0166) goto v0206;
    v0207 = v0131;
    v0166 = elt(env, 3); /* false */
    v0166 = (v0207 == v0166 ? lisp_true : nil);
    goto v0086;

v0086:
    if (v0166 == nil) goto v0083;
    v0166 = qvalue(elt(env, 4)); /* nil */
    goto v0057;

v0057:
    if (v0166 == nil) { popv(1); return onevalue(v0131); }
    v0166 = v0131;
    v0166 = Lconsp(nil, v0166);
    env = stack[0];
    if (v0166 == nil) goto v0208;
    v0166 = v0131;
    v0166 = qcar(v0166);
    v0166 = Lconsp(nil, v0166);
    env = stack[0];
    if (v0166 == nil) goto v0208;
    v0166 = v0131;
    v0166 = qcar(v0166);
    v0207 = qcar(v0166);
    v0166 = elt(env, 5); /* (cong ncong) */
    v0166 = Lmemq(nil, v0207, v0166);
    if (v0166 == nil) goto v0208;
    v0166 = v0131;
    v0166 = qcar(v0166);
    v0166 = qcdr(v0166);
    if (!consp(v0166)) goto v0202;
    v0166 = v0131;
    v0166 = qcar(v0166);
    v0166 = qcdr(v0166);
    v0166 = qcar(v0166);
    v0166 = (consp(v0166) ? nil : lisp_true);
    goto v0042;

v0042:
    if (!(v0166 == nil)) goto v0208;
    v0166 = v0131;
    v0166 = qcdr(v0166);
    v0166 = qcar(v0166);
    if (!(v0166 == nil)) { popv(1); return onevalue(v0131); }
    v0166 = elt(env, 3); /* false */
    { popv(1); return onevalue(v0166); }

v0208:
    v0166 = v0131;
    v0166 = qcar(v0166);
    v0131 = qcdr(v0131);
    v0131 = qcar(v0131);
    fn = elt(env, 6); /* pasf_evalatp */
    v0166 = (*qfn2(fn))(qenv(fn), v0166, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[0];
    if (v0166 == nil) goto v0197;
    v0166 = elt(env, 1); /* true */
    { popv(1); return onevalue(v0166); }

v0197:
    v0166 = elt(env, 3); /* false */
    { popv(1); return onevalue(v0166); }

v0202:
    v0166 = qvalue(elt(env, 2)); /* t */
    goto v0042;

v0083:
    v0166 = v0131;
    v0166 = qcdr(v0166);
    v0166 = qcar(v0166);
    if (!consp(v0166)) goto v0091;
    v0166 = v0131;
    v0166 = qcdr(v0166);
    v0166 = qcar(v0166);
    v0166 = qcar(v0166);
    v0166 = (consp(v0166) ? nil : lisp_true);
    goto v0057;

v0091:
    v0166 = qvalue(elt(env, 2)); /* t */
    goto v0057;

v0206:
    v0166 = qvalue(elt(env, 2)); /* t */
    goto v0086;
/* error exit handlers */
v0209:
    popv(1);
    return nil;
}



/* Code for ibalp_var!-wclist */

static Lisp_Object CC_ibalp_varKwclist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0122, v0162;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_var-wclist");
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
    stack[-3] = nil;
    v0122 = stack[-4];
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcar(v0122);
    stack[-2] = v0122;
    goto v0057;

v0057:
    v0122 = stack[-2];
    if (v0122 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    v0122 = stack[-2];
    v0122 = qcar(v0122);
    stack[-1] = v0122;
    v0122 = stack[-1];
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcar(v0122);
    if (!(v0122 == nil)) goto v0021;
    v0122 = stack[-1];
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    stack[0] = qcdr(v0122);
    v0162 = stack[-4];
    v0122 = stack[-1];
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcar(v0122);
    fn = elt(env, 2); /* delq */
    v0122 = (*qfn2(fn))(qenv(fn), v0162, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v0122 = (*qfn2(fn))(qenv(fn), stack[0], v0122);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    v0122 = stack[-4];
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    stack[0] = qcdr(v0122);
    v0162 = stack[-1];
    v0122 = stack[-4];
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcar(v0122);
    fn = elt(env, 2); /* delq */
    v0122 = (*qfn2(fn))(qenv(fn), v0162, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v0122 = (*qfn2(fn))(qenv(fn), stack[0], v0122);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    v0122 = stack[-1];
    fn = elt(env, 4); /* ibalp_getnewwl */
    v0122 = (*qfn1(fn))(qenv(fn), v0122);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    stack[-5] = v0122;
    v0122 = stack[-5];
    if (v0122 == nil) goto v0167;
    v0122 = stack[-1];
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    stack[0] = qcdr(v0122);
    v0162 = stack[-5];
    v0122 = stack[-1];
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcar(v0122);
    v0122 = cons(v0162, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v0122 = (*qfn2(fn))(qenv(fn), stack[0], v0122);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    v0122 = stack[-5];
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    stack[0] = qcdr(v0122);
    v0162 = stack[-1];
    v0122 = stack[-5];
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = qcar(v0122);
    v0122 = cons(v0162, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v0122 = (*qfn2(fn))(qenv(fn), stack[0], v0122);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    goto v0021;

v0021:
    v0122 = stack[-2];
    v0122 = qcdr(v0122);
    stack[-2] = v0122;
    goto v0057;

v0167:
    v0162 = stack[-1];
    v0122 = stack[-3];
    v0122 = cons(v0162, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    stack[-3] = v0122;
    goto v0021;
/* error exit handlers */
v0185:
    popv(7);
    return nil;
}



/* Code for cgb_buch!-ev_divides!? */

static Lisp_Object CC_cgb_buchKev_dividesW(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084, v0085;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cgb_buch-ev_divides?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0085 = v0087;
    v0084 = v0000;
/* end of prologue */
    {
        fn = elt(env, 1); /* ev_mtest!? */
        return (*qfn2(fn))(qenv(fn), v0085, v0084);
    }
}



/* Code for diff!-over!-k!-mod!-p */

static Lisp_Object MS_CDECL CC_diffKoverKkKmodKp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0221, v0065, v0222;
    Lisp_Object fn;
    Lisp_Object v0003, v0087, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "diff-over-k-mod-p");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0087 = va_arg(aa, Lisp_Object);
    v0003 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diff-over-k-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0003,v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0087,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0003;
    stack[-2] = v0087;
    stack[-3] = v0000;
/* end of prologue */
    v0221 = stack[-3];
    if (!consp(v0221)) goto v0083;
    v0221 = stack[-3];
    v0221 = qcar(v0221);
    v0221 = (consp(v0221) ? nil : lisp_true);
    goto v0057;

v0057:
    if (v0221 == nil) goto v0140;
    v0221 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0221); }

v0140:
    v0221 = stack[-3];
    v0221 = qcar(v0221);
    v0221 = qcar(v0221);
    v0065 = qcar(v0221);
    v0221 = stack[-1];
    if (equal(v0065, v0221)) goto v0091;
    v0221 = stack[-3];
    v0221 = qcar(v0221);
    stack[-4] = qcar(v0221);
    v0221 = stack[-3];
    v0221 = qcar(v0221);
    v0222 = qcdr(v0221);
    v0065 = stack[-2];
    v0221 = stack[-1];
    stack[0] = CC_diffKoverKkKmodKp(env, 3, v0222, v0065, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-5];
    v0221 = stack[-3];
    v0222 = qcdr(v0221);
    v0065 = stack[-2];
    v0221 = stack[-1];
    v0221 = CC_diffKoverKkKmodKp(env, 3, v0222, v0065, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-5];
    {
        Lisp_Object v0224 = stack[-4];
        Lisp_Object v0225 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0224, v0225, v0221);
    }

v0091:
    v0221 = stack[-3];
    v0221 = qcar(v0221);
    v0221 = qcar(v0221);
    v0065 = qcdr(v0221);
    v0221 = (Lisp_Object)17; /* 1 */
    if (v0065 == v0221) goto v0062;
    v0065 = stack[-1];
    v0221 = stack[-3];
    v0221 = qcar(v0221);
    v0221 = qcar(v0221);
    v0221 = qcdr(v0221);
    v0221 = (Lisp_Object)((int32_t)(v0221) - 0x10);
    fn = elt(env, 4); /* mksp */
    stack[-4] = (*qfn2(fn))(qenv(fn), v0065, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-5];
    v0221 = stack[-3];
    v0221 = qcar(v0221);
    v0221 = qcar(v0221);
    v0221 = qcdr(v0221);
    v0065 = Lmodular_number(nil, v0221);
    env = stack[-5];
    v0221 = stack[-3];
    v0221 = qcar(v0221);
    v0221 = qcdr(v0221);
    fn = elt(env, 5); /* times!-mod!-p */
    v0065 = (*qfn2(fn))(qenv(fn), v0065, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-5];
    v0221 = stack[-2];
    v0221 = Lmodular_number(nil, v0221);
    env = stack[-5];
    fn = elt(env, 6); /* quotient!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v0065, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-5];
    v0221 = stack[-3];
    v0222 = qcdr(v0221);
    v0065 = stack[-2];
    v0221 = stack[-1];
    v0221 = CC_diffKoverKkKmodKp(env, 3, v0222, v0065, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-5];
    {
        Lisp_Object v0126 = stack[-4];
        Lisp_Object v0124 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0126, v0124, v0221);
    }

v0062:
    v0221 = stack[-3];
    v0221 = qcar(v0221);
    v0065 = qcdr(v0221);
    v0221 = stack[-2];
    v0221 = Lmodular_number(nil, v0221);
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 6); /* quotient!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0065, v0221);
    }

v0083:
    v0221 = qvalue(elt(env, 1)); /* t */
    goto v0057;
/* error exit handlers */
v0223:
    popv(6);
    return nil;
}



/* Code for ir2mml */

static Lisp_Object CC_ir2mml(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ir2mml");
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
    v0095 = elt(env, 1); /* (indent) */
    fn = elt(env, 8); /* fluid */
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-1];
    v0095 = (Lisp_Object)49; /* 3 */
    qvalue(elt(env, 2)) = v0095; /* ind */
    v0095 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v0095; /* indent */
    v0095 = elt(env, 4); /* "<math>" */
    fn = elt(env, 9); /* printout */
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-1];
    v0095 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 10); /* indent!* */
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-1];
    v0095 = stack[0];
    fn = elt(env, 11); /* expression */
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-1];
    v0095 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 10); /* indent!* */
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-1];
    v0095 = elt(env, 7); /* "</math>" */
    fn = elt(env, 9); /* printout */
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    v0095 = nil;
    { popv(2); return onevalue(v0095); }
/* error exit handlers */
v0139:
    popv(2);
    return nil;
}



/* Code for pfordp */

static Lisp_Object CC_pfordp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0094, v0108, v0193, v0102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pfordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0108 = v0087;
    v0193 = v0000;
/* end of prologue */

v0001:
    v0094 = v0193;
    if (v0094 == nil) goto v0082;
    v0094 = v0108;
    if (v0094 == nil) goto v0090;
    v0094 = v0193;
    v0094 = qcar(v0094);
    v0102 = qcar(v0094);
    v0094 = v0108;
    v0094 = qcar(v0094);
    v0094 = qcar(v0094);
    if (v0102 == v0094) goto v0201;
    v0094 = v0193;
    v0094 = qcar(v0094);
    v0094 = qcar(v0094);
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    {
        fn = elt(env, 2); /* termordp */
        return (*qfn2(fn))(qenv(fn), v0094, v0108);
    }

v0201:
    v0094 = v0193;
    v0094 = qcdr(v0094);
    v0193 = v0094;
    v0094 = v0108;
    v0094 = qcdr(v0094);
    v0108 = v0094;
    goto v0001;

v0090:
    v0094 = v0193;
    v0094 = qcar(v0094);
    v0108 = qcar(v0094);
    v0094 = (Lisp_Object)17; /* 1 */
        return Lneq(nil, v0108, v0094);

v0082:
    v0094 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0094);
}



/* Code for delete!-dups */

static Lisp_Object CC_deleteKdups(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0048, v0041;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delete-dups");
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
    v0041 = nil;
    goto v0001;

v0001:
    v0088 = stack[0];
    if (v0088 == nil) goto v0227;
    v0088 = stack[0];
    v0048 = qcar(v0088);
    v0088 = stack[0];
    v0088 = qcdr(v0088);
    v0088 = Lmember(nil, v0048, v0088);
    if (v0088 == nil) goto v0040;
    v0088 = stack[0];
    v0088 = qcdr(v0088);
    stack[0] = v0088;
    goto v0001;

v0040:
    v0088 = stack[0];
    v0088 = qcar(v0088);
    v0048 = v0041;
    v0088 = cons(v0088, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    v0041 = v0088;
    v0088 = stack[0];
    v0088 = qcdr(v0088);
    stack[0] = v0088;
    goto v0001;

v0227:
    v0088 = v0041;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0088);
    }
/* error exit handlers */
v0089:
    popv(2);
    return nil;
}



/* Code for fortranname */

static Lisp_Object CC_fortranname(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0228, v0097;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fortranname");
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
    v0228 = stack[0];
    v0228 = Lstringp(nil, v0228);
    env = stack[-1];
    if (v0228 == nil) goto v0090;
    v0228 = stack[0];
    {
        popv(2);
        fn = elt(env, 9); /* stringtoatom */
        return (*qfn1(fn))(qenv(fn), v0228);
    }

v0090:
    v0097 = stack[0];
    v0228 = qvalue(elt(env, 1)); /* !*notfortranfuns!* */
    v0228 = Lmemq(nil, v0097, v0228);
    if (v0228 == nil) goto v0086;
    v0228 = qvalue(elt(env, 2)); /* !*stdout!* */
    v0228 = qcdr(v0228);
    v0228 = Lwrs(nil, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-1];
    v0228 = elt(env, 3); /* "*** WARNING: " */
    v0228 = Lprinc(nil, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-1];
    v0228 = stack[0];
    v0228 = Lprin(nil, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-1];
    v0228 = elt(env, 4); /* " is not an intrinsic Fortran function" */
    fn = elt(env, 10); /* prin2t */
    v0228 = (*qfn1(fn))(qenv(fn), v0228);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-1];
    goto v0086;

v0086:
    v0228 = qvalue(elt(env, 6)); /* !*double */
    if (v0228 == nil) goto v0108;
    v0097 = stack[0];
    v0228 = elt(env, 7); /* !*doublename!* */
    v0228 = get(v0097, v0228);
    if (v0228 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v0228); }

v0108:
    v0097 = stack[0];
    v0228 = elt(env, 8); /* !*fortranname!* */
    v0228 = get(v0097, v0228);
    if (v0228 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v0228); }
/* error exit handlers */
v0101:
    popv(2);
    return nil;
}



/* Code for coposp */

static Lisp_Object CC_coposp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0099, v0071;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for coposp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0071 = v0000;
/* end of prologue */
    v0099 = v0071;
    v0099 = qcdr(v0099);
    if (v0099 == nil) goto v0002;
    v0099 = v0071;
    v0099 = qcar(v0099);
    if (!consp(v0099)) goto v0086;
    v0099 = v0071;
    v0099 = qcdr(v0099);
    {
        fn = elt(env, 2); /* covposp */
        return (*qfn1(fn))(qenv(fn), v0099);
    }

v0086:
    v0099 = v0071;
    v0099 = qcdr(v0099);
    {
        fn = elt(env, 3); /* contposp */
        return (*qfn1(fn))(qenv(fn), v0099);
    }

v0002:
    v0099 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0099);
}



/* Code for factorial */

static Lisp_Object CC_factorial(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0041;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for factorial");
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
    v0048 = stack[-1];
    v0048 = integerp(v0048);
    if (v0048 == nil) goto v0082;
    v0041 = stack[-1];
    v0048 = (Lisp_Object)1; /* 0 */
    v0048 = (Lisp_Object)lessp2(v0041, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    v0048 = v0048 ? lisp_true : nil;
    env = stack[-3];
    goto v0173;

v0173:
    if (v0048 == nil) goto v0138;
    stack[-2] = elt(env, 2); /* arith */
    stack[0] = (Lisp_Object)65; /* 4 */
    v0041 = stack[-1];
    v0048 = elt(env, 3); /* "invalid factorial argument" */
    v0048 = list2(v0041, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-3];
    {
        Lisp_Object v0092 = stack[-2];
        Lisp_Object v0093 = stack[0];
        popv(4);
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0092, v0093, v0048);
    }

v0138:
    v0048 = stack[-1];
    {
        popv(4);
        fn = elt(env, 5); /* nfactorial */
        return (*qfn1(fn))(qenv(fn), v0048);
    }

v0082:
    v0048 = qvalue(elt(env, 1)); /* t */
    goto v0173;
/* error exit handlers */
v0201:
    popv(4);
    return nil;
}



/* Code for mv!-domainlist!-!* */

static Lisp_Object CC_mvKdomainlistKH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0063;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-domainlist-*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0087;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0077;

v0077:
    v0059 = stack[0];
    if (v0059 == nil) goto v0057;
    v0063 = stack[-1];
    v0059 = stack[0];
    v0059 = qcar(v0059);
    v0063 = times2(v0063, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    v0059 = stack[-2];
    v0059 = cons(v0063, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    stack[-2] = v0059;
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    stack[0] = v0059;
    goto v0077;

v0057:
    v0059 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0059);
    }
/* error exit handlers */
v0060:
    popv(4);
    return nil;
}



/* Code for dv_cambhead */

static Lisp_Object CC_dv_cambhead(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0098, v0088;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dv_cambhead");
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

v0180:
    v0098 = stack[0];
    fn = elt(env, 4); /* listp */
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-2];
    if (v0098 == nil) goto v0001;
    v0098 = stack[0];
    stack[-1] = qcar(v0098);
    v0088 = elt(env, 1); /* expt */
    v0098 = elt(env, 2); /* minus */
    v0098 = list2(v0088, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-2];
    v0098 = Lmember(nil, stack[-1], v0098);
    if (v0098 == nil) goto v0084;
    v0098 = stack[0];
    v0098 = qcdr(v0098);
    v0098 = qcar(v0098);
    stack[0] = v0098;
    goto v0180;

v0084:
    v0098 = stack[0];
    fn = elt(env, 4); /* listp */
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    if (v0098 == nil) goto v0001;
    v0098 = stack[0];
    v0098 = qcar(v0098);
    { popv(3); return onevalue(v0098); }

v0001:
    v0098 = nil;
    { popv(3); return onevalue(v0098); }
/* error exit handlers */
v0062:
    popv(3);
    return nil;
}



/* Code for lalr_clean_up */

static Lisp_Object MS_CDECL CC_lalr_clean_up(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0041, v0062, v0089;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "lalr_clean_up");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_clean_up");
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
    v0048 = qvalue(elt(env, 1)); /* terminals */
    v0089 = v0048;
    goto v0077;

v0077:
    v0048 = v0089;
    if (v0048 == nil) goto v0001;
    v0048 = v0089;
    v0048 = qcar(v0048);
    v0062 = v0048;
    v0041 = v0062;
    v0048 = elt(env, 3); /* produces */
    v0048 = Lremprop(nil, v0041, v0048);
    env = stack[0];
    v0041 = v0062;
    v0048 = elt(env, 4); /* lalr_first */
    v0048 = Lremprop(nil, v0041, v0048);
    env = stack[0];
    v0041 = v0062;
    v0048 = elt(env, 5); /* non_terminal_code */
    v0048 = Lremprop(nil, v0041, v0048);
    env = stack[0];
    v0048 = v0089;
    v0048 = qcdr(v0048);
    v0089 = v0048;
    goto v0077;

v0001:
    v0048 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 6)) = v0048; /* symbols */
    qvalue(elt(env, 7)) = v0048; /* non_terminals */
    v0048 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 8)) = v0048; /* action_map */
    qvalue(elt(env, 9)) = v0048; /* goto_cache */
    v0048 = nil;
    { popv(1); return onevalue(v0048); }
}



/* Code for remlocs */

static Lisp_Object CC_remlocs(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0220, v0081;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remlocs");
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
    v0081 = v0000;
/* end of prologue */
    v0220 = qvalue(elt(env, 1)); /* !*globals */
    if (v0220 == nil) goto v0077;
    v0220 = v0081;
    stack[-2] = v0220;
    goto v0086;

v0086:
    v0220 = stack[-2];
    if (v0220 == nil) goto v0077;
    v0220 = stack[-2];
    v0220 = qcar(v0220);
    stack[-1] = v0220;
    v0081 = stack[-1];
    v0220 = qvalue(elt(env, 3)); /* locls!* */
    v0220 = Lassoc(nil, v0081, v0220);
    stack[-3] = v0220;
    v0220 = stack[-3];
    if (!(v0220 == nil)) goto v0154;
    v0220 = elt(env, 4); /* begin */
    fn = elt(env, 6); /* getd */
    v0220 = (*qfn1(fn))(qenv(fn), v0220);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    if (v0220 == nil) goto v0061;
    v0081 = elt(env, 5); /* " Lvar confused" */
    v0220 = stack[-1];
    v0220 = list2(v0081, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    fn = elt(env, 7); /* rederr */
    v0220 = (*qfn1(fn))(qenv(fn), v0220);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    goto v0154;

v0154:
    v0220 = stack[-3];
    v0220 = qcdr(v0220);
    v0220 = qcdr(v0220);
    if (v0220 == nil) goto v0204;
    v0081 = stack[-3];
    v0220 = stack[-3];
    v0220 = qcdr(v0220);
    v0220 = qcdr(v0220);
    v0220 = Lrplacd(nil, v0081, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    goto v0051;

v0051:
    v0220 = stack[-2];
    v0220 = qcdr(v0220);
    stack[-2] = v0220;
    goto v0086;

v0204:
    v0081 = stack[-3];
    v0220 = qvalue(elt(env, 3)); /* locls!* */
    fn = elt(env, 8); /* efface1 */
    v0220 = (*qfn2(fn))(qenv(fn), v0081, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    qvalue(elt(env, 3)) = v0220; /* locls!* */
    goto v0051;

v0061:
    stack[0] = (Lisp_Object)1; /* 0 */
    v0081 = elt(env, 5); /* " Lvar confused" */
    v0220 = stack[-1];
    v0220 = list2(v0081, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    fn = elt(env, 9); /* error */
    v0220 = (*qfn2(fn))(qenv(fn), stack[0], v0220);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    goto v0154;

v0077:
    v0220 = nil;
    { popv(5); return onevalue(v0220); }
/* error exit handlers */
v0198:
    popv(5);
    return nil;
}



/* Code for ofsf_surep */

static Lisp_Object CC_ofsf_surep(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0181, v0140, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_surep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0181 = v0087;
    v0140 = v0000;
/* end of prologue */
    v0015 = v0140;
    v0140 = v0181;
    v0181 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 2); /* cl_simpl */
    v0181 = (*qfnn(fn))(qenv(fn), 3, v0015, v0140, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[0];
    v0140 = elt(env, 1); /* true */
    v0181 = (v0181 == v0140 ? lisp_true : nil);
    { popv(1); return onevalue(v0181); }
/* error exit handlers */
v0143:
    popv(1);
    return nil;
}



/* Code for simpqg */

static Lisp_Object CC_simpqg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0083, v0084;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpqg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0083 = v0000;
/* end of prologue */
    v0084 = v0083;
    v0083 = elt(env, 1); /* qg */
    {
        fn = elt(env, 2); /* simpcv */
        return (*qfn2(fn))(qenv(fn), v0084, v0083);
    }
}



/* Code for new_pde */

static Lisp_Object MS_CDECL CC_new_pde(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0096, v0228;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "new_pde");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for new_pde");
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
    v0096 = qvalue(elt(env, 1)); /* recycle_eqns */
    v0096 = qcar(v0096);
    if (v0096 == nil) goto v0083;
    v0096 = qvalue(elt(env, 2)); /* nil */
    goto v0057;

v0057:
    if (v0096 == nil) goto v0001;
    v0096 = qvalue(elt(env, 1)); /* recycle_eqns */
    v0096 = qcdr(v0096);
    fn = elt(env, 5); /* clean_prop_list */
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    goto v0001;

v0001:
    v0096 = qvalue(elt(env, 1)); /* recycle_eqns */
    v0096 = qcar(v0096);
    if (v0096 == nil) goto v0039;
    v0096 = qvalue(elt(env, 1)); /* recycle_eqns */
    v0096 = qcar(v0096);
    v0096 = qcar(v0096);
    stack[0] = v0096;
    v0096 = qvalue(elt(env, 1)); /* recycle_eqns */
    v0096 = qcar(v0096);
    v0228 = qcdr(v0096);
    v0096 = qvalue(elt(env, 1)); /* recycle_eqns */
    v0096 = qcdr(v0096);
    v0096 = cons(v0228, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    qvalue(elt(env, 1)) = v0096; /* recycle_eqns */
    goto v0094;

v0094:
    v0228 = stack[0];
    v0096 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 6); /* setprop */
    v0096 = (*qfn2(fn))(qenv(fn), v0228, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0039:
    v0228 = qvalue(elt(env, 3)); /* eqname_ */
    v0096 = qvalue(elt(env, 4)); /* nequ_ */
    fn = elt(env, 7); /* mkid */
    v0096 = (*qfn2(fn))(qenv(fn), v0228, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    stack[0] = v0096;
    v0096 = qvalue(elt(env, 4)); /* nequ_ */
    v0096 = add1(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    qvalue(elt(env, 4)) = v0096; /* nequ_ */
    goto v0094;

v0083:
    v0096 = qvalue(elt(env, 1)); /* recycle_eqns */
    v0096 = qcdr(v0096);
    goto v0057;
/* error exit handlers */
v0100:
    popv(2);
    return nil;
}



/* Code for kernord!-split */

static Lisp_Object CC_kernordKsplit(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0148, v0229, v0146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for kernord-split");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0087;
    stack[-3] = v0000;
/* end of prologue */
    stack[-4] = nil;
    stack[-1] = nil;
    v0148 = stack[-3];
    fn = elt(env, 2); /* powers */
    v0148 = (*qfn1(fn))(qenv(fn), v0148);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-5];
    stack[-3] = v0148;
    v0148 = stack[-2];
    fn = elt(env, 2); /* powers */
    v0148 = (*qfn1(fn))(qenv(fn), v0148);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-5];
    stack[-2] = v0148;
    v0148 = stack[-3];
    stack[0] = v0148;
    goto v0206;

v0206:
    v0148 = stack[0];
    if (v0148 == nil) goto v0086;
    v0148 = stack[0];
    v0148 = qcar(v0148);
    v0146 = v0148;
    v0148 = v0146;
    v0229 = qcar(v0148);
    v0148 = stack[-2];
    v0148 = Lassoc(nil, v0229, v0148);
    if (v0148 == nil) goto v0188;
    v0229 = v0146;
    v0148 = stack[-1];
    v0148 = cons(v0229, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-5];
    stack[-1] = v0148;
    goto v0071;

v0071:
    v0148 = stack[0];
    v0148 = qcdr(v0148);
    stack[0] = v0148;
    goto v0206;

v0188:
    v0229 = v0146;
    v0148 = stack[-4];
    v0148 = cons(v0229, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-5];
    stack[-4] = v0148;
    goto v0071;

v0086:
    v0148 = stack[-2];
    stack[0] = v0148;
    goto v0053;

v0053:
    v0148 = stack[0];
    if (v0148 == nil) goto v0111;
    v0148 = stack[0];
    v0148 = qcar(v0148);
    v0146 = v0148;
    v0148 = v0146;
    v0229 = qcar(v0148);
    v0148 = stack[-3];
    v0148 = Lassoc(nil, v0229, v0148);
    if (v0148 == nil) goto v0105;
    v0229 = v0146;
    v0148 = stack[-1];
    v0148 = cons(v0229, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-5];
    stack[-1] = v0148;
    goto v0078;

v0078:
    v0148 = stack[0];
    v0148 = qcdr(v0148);
    stack[0] = v0148;
    goto v0053;

v0105:
    v0229 = v0146;
    v0148 = stack[-4];
    v0148 = cons(v0229, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-5];
    stack[-4] = v0148;
    goto v0078;

v0111:
    v0148 = stack[-4];
    v0229 = Lnreverse(nil, v0148);
    env = stack[-5];
    v0148 = stack[-1];
    v0148 = Lnreverse(nil, v0148);
    popv(6);
    return cons(v0229, v0148);
/* error exit handlers */
v0166:
    popv(6);
    return nil;
}



/* Code for ibalp_isinminclause */

static Lisp_Object CC_ibalp_isinminclause(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0230, v0212;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_isinminclause");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0087;
    stack[-2] = v0000;
/* end of prologue */
    stack[0] = nil;
    v0230 = stack[-2];
    v0230 = qcdr(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcar(v0230);
    stack[-3] = v0230;
    goto v0086;

v0086:
    v0230 = stack[-3];
    if (v0230 == nil) goto v0085;
    v0230 = stack[0];
    if (!(v0230 == nil)) goto v0085;
    v0230 = stack[-3];
    v0230 = qcar(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcar(v0230);
    if (v0230 == nil) goto v0048;
    v0230 = qvalue(elt(env, 1)); /* nil */
    goto v0194;

v0194:
    if (v0230 == nil) goto v0143;
    v0230 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0230;
    goto v0143;

v0143:
    v0230 = stack[-3];
    v0230 = qcdr(v0230);
    stack[-3] = v0230;
    goto v0086;

v0048:
    v0230 = stack[-3];
    v0230 = qcar(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcdr(v0230);
    v0212 = qcar(v0230);
    v0230 = stack[-3];
    v0230 = qcar(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcar(v0230);
    v0212 = plus2(v0212, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    v0230 = stack[-1];
    v0230 = Leqn(nil, v0212, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    goto v0194;

v0085:
    v0230 = stack[-2];
    v0230 = qcdr(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcar(v0230);
    stack[-3] = v0230;
    goto v0047;

v0047:
    v0230 = stack[-3];
    if (v0230 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0230 = stack[0];
    if (!(v0230 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0230 = stack[-3];
    v0230 = qcar(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcar(v0230);
    if (v0230 == nil) goto v0208;
    v0230 = qvalue(elt(env, 1)); /* nil */
    goto v0219;

v0219:
    if (v0230 == nil) goto v0183;
    v0230 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0230;
    goto v0183;

v0183:
    v0230 = stack[-3];
    v0230 = qcdr(v0230);
    stack[-3] = v0230;
    goto v0047;

v0208:
    v0230 = stack[-3];
    v0230 = qcar(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcdr(v0230);
    v0212 = qcar(v0230);
    v0230 = stack[-3];
    v0230 = qcar(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcdr(v0230);
    v0230 = qcar(v0230);
    v0212 = plus2(v0212, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    v0230 = stack[-1];
    v0230 = Leqn(nil, v0212, v0230);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    goto v0219;
/* error exit handlers */
v0023:
    popv(5);
    return nil;
}



/* Code for aex_lc */

static Lisp_Object CC_aex_lc(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0063, v0091, v0226;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_lc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0063 = v0087;
    stack[0] = v0000;
/* end of prologue */
    v0091 = stack[0];
    fn = elt(env, 2); /* aex_mvartest */
    v0063 = (*qfn2(fn))(qenv(fn), v0091, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-2];
    if (v0063 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0063 = stack[0];
    fn = elt(env, 3); /* aex_ex */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-2];
    fn = elt(env, 4); /* ratpoly_lc */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-2];
    v0063 = stack[0];
    fn = elt(env, 5); /* aex_ctx */
    v0226 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-2];
    v0091 = qvalue(elt(env, 1)); /* nil */
    v0063 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0138 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v0138, v0226, v0091, v0063);
    }
/* error exit handlers */
v0227:
    popv(3);
    return nil;
}



/* Code for resume */

static Lisp_Object CC_resume(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0227, v0138, v0109, v0098;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for resume");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0227 = v0087;
    v0138 = v0000;
/* end of prologue */
    v0109 = v0227;
    if (v0109 == nil) goto v0040;
    v0109 = v0227;
    v0109 = qcar(v0109);
    v0098 = qcar(v0109);
    v0109 = v0227;
    v0109 = qcar(v0109);
    v0109 = qcdr(v0109);
    v0109 = qcar(v0109);
    v0227 = qcdr(v0227);
    {
        popv(1);
        fn = elt(env, 3); /* amatch */
        return (*qfnn(fn))(qenv(fn), 4, v0098, v0109, v0138, v0227);
    }

v0040:
    v0227 = v0138;
    fn = elt(env, 4); /* chk */
    v0138 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[0];
    v0227 = qvalue(elt(env, 1)); /* t */
    if (v0138 == v0227) goto v0194;
    v0227 = nil;
    { popv(1); return onevalue(v0227); }

v0194:
    v0227 = qvalue(elt(env, 2)); /* substitution */
    {
        popv(1);
        fn = elt(env, 5); /* bsubs */
        return (*qfn1(fn))(qenv(fn), v0227);
    }
/* error exit handlers */
v0088:
    popv(1);
    return nil;
}



/* Code for onoff */

static Lisp_Object CC_onoff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0205, v0064, v0231;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for onoff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0087;
    stack[0] = v0000;
/* end of prologue */
    v0205 = stack[0];
    if (symbolp(v0205)) goto v0083;
    v0064 = stack[0];
    v0205 = elt(env, 1); /* "switch" */
    fn = elt(env, 10); /* typerr */
    v0205 = (*qfn2(fn))(qenv(fn), v0064, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    goto v0048;

v0048:
    v0205 = elt(env, 4); /* !* */
    stack[-1] = Lexplode(nil, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    v0205 = stack[0];
    v0205 = Lexplode(nil, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    v0205 = Lappend(nil, stack[-1], v0205);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    v0205 = Lcompress(nil, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    v0205 = Lintern(nil, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    stack[-3] = v0205;
    v0205 = qvalue(elt(env, 5)); /* !*switchcheck */
    if (v0205 == nil) goto v0050;
    v0205 = stack[-3];
    fn = elt(env, 11); /* lispeval */
    v0064 = (*qfn1(fn))(qenv(fn), v0205);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    v0205 = stack[-2];
    if (!(v0064 == v0205)) goto v0050;
    v0205 = qvalue(elt(env, 6)); /* nil */
    { popv(5); return onevalue(v0205); }

v0050:
    v0231 = stack[-2];
    v0064 = stack[0];
    v0205 = elt(env, 7); /* simpfg */
    v0205 = get(v0064, v0205);
    env = stack[-4];
    v0205 = Latsoc(nil, v0231, v0205);
    v0064 = v0205;
    if (v0205 == nil) goto v0061;
    stack[-1] = elt(env, 8); /* progn */
    v0205 = v0064;
    stack[0] = qcdr(v0205);
    v0205 = qvalue(elt(env, 6)); /* nil */
    v0205 = ncons(v0205);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    v0205 = Lappend(nil, stack[0], v0205);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    v0205 = cons(stack[-1], v0205);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    fn = elt(env, 11); /* lispeval */
    v0205 = (*qfn1(fn))(qenv(fn), v0205);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    goto v0061;

v0061:
    v0205 = stack[-2];
    if (v0205 == nil) goto v0170;
    v0064 = stack[-3];
    v0205 = elt(env, 9); /* !*raise */
    if (!(v0064 == v0205)) goto v0170;
    v0205 = elt(env, 9); /* !*raise */
    stack[-3] = v0205;
    goto v0170;

v0170:
    v0064 = stack[-3];
    v0205 = stack[-2];
    v0205 = Lset(nil, v0064, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    v0205 = nil;
    { popv(5); return onevalue(v0205); }

v0083:
    v0205 = stack[0];
    if (!symbolp(v0205)) v0205 = nil;
    else { v0205 = qfastgets(v0205);
           if (v0205 != nil) { v0205 = elt(v0205, 51); /* switch */
#ifdef RECORD_GET
             if (v0205 == SPID_NOPROP)
                record_get(elt(fastget_names, 51), 0),
                v0205 = nil;
             else record_get(elt(fastget_names, 51), 1),
                v0205 = lisp_true; }
           else record_get(elt(fastget_names, 51), 0); }
#else
             if (v0205 == SPID_NOPROP) v0205 = nil; else v0205 = lisp_true; }}
#endif
    if (!(v0205 == nil)) goto v0048;
    stack[-3] = elt(env, 2); /* rlisp */
    stack[-1] = (Lisp_Object)401; /* 25 */
    v0064 = stack[0];
    v0205 = elt(env, 3); /* "not defined as switch" */
    v0205 = list2(v0064, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    fn = elt(env, 12); /* rerror */
    v0205 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[-1], v0205);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    goto v0048;
/* error exit handlers */
v0213:
    popv(5);
    return nil;
}



/* Code for evdif */

static Lisp_Object CC_evdif(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0092, v0093, v0189;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evdif");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0087;
    stack[-1] = v0000;
/* end of prologue */
    v0189 = nil;
    goto v0082;

v0082:
    v0092 = stack[0];
    if (v0092 == nil) goto v0098;
    v0092 = stack[-1];
    if (!(v0092 == nil)) goto v0155;
    v0092 = elt(env, 2); /* (0) */
    stack[-1] = v0092;
    goto v0155;

v0155:
    v0092 = stack[-1];
    v0093 = qcar(v0092);
    v0092 = stack[0];
    v0092 = qcar(v0092);
    v0092 = (Lisp_Object)(int32_t)((int32_t)v0093 - (int32_t)v0092 + TAG_FIXNUM);
    v0093 = v0189;
    v0092 = cons(v0092, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-2];
    v0189 = v0092;
    v0092 = stack[-1];
    v0092 = qcdr(v0092);
    stack[-1] = v0092;
    v0092 = stack[0];
    v0092 = qcdr(v0092);
    stack[0] = v0092;
    goto v0082;

v0098:
    v0092 = v0189;
    v0093 = Lnreverse(nil, v0092);
    v0092 = stack[-1];
        popv(3);
        return Lnconc(nil, v0093, v0092);
/* error exit handlers */
v0094:
    popv(3);
    return nil;
}



/* Code for all_defined_vertex */

static Lisp_Object CC_all_defined_vertex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0103, v0095, v0174, v0139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for all_defined_vertex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0103 = v0087;
    v0095 = v0000;
/* end of prologue */
    v0139 = v0095;
    v0174 = qvalue(elt(env, 1)); /* nil */
    v0095 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* al1_defined_vertex */
        return (*qfnn(fn))(qenv(fn), 4, v0139, v0174, v0095, v0103);
    }
}



/* Code for set!-global!-mode */

static Lisp_Object CC_setKglobalKmode(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for set-global-mode");
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
    v0071 = qvalue(elt(env, 1)); /* nil */
    v0071 = ncons(v0071);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0071; /* alglist!* */
    v0071 = stack[-2];
    qvalue(elt(env, 3)) = v0071; /* !*mode */
    stack[-3] = elt(env, 4); /* null */
    stack[-1] = elt(env, 5); /* setq */
    stack[0] = elt(env, 3); /* !*mode */
    v0071 = stack[-2];
    v0071 = Lmkquote(nil, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-4];
    v0071 = list3(stack[-1], stack[0], v0071);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    {
        Lisp_Object v0021 = stack[-3];
        popv(5);
        return list2(v0021, v0071);
    }
/* error exit handlers */
v0025:
    popv(5);
    return nil;
}



/* Code for groeb!=weight */

static Lisp_Object MS_CDECL CC_groebMweight(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0140;
    Lisp_Object fn;
    Lisp_Object v0003, v0087, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "groeb=weight");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0087 = va_arg(aa, Lisp_Object);
    v0003 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groeb=weight");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0003,v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0087,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0087;
    v0140 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* mo_ecart */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0140);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-3];
    v0140 = stack[-1];
    fn = elt(env, 2); /* bas_dpecart */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0140);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-3];
    v0140 = stack[0];
    fn = elt(env, 2); /* bas_dpecart */
    v0140 = (*qfn1(fn))(qenv(fn), v0140);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-3];
    v0140 = Lmin2(nil, stack[-1], v0140);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    {
        Lisp_Object v0155 = stack[-2];
        popv(4);
        return plus2(v0155, v0140);
    }
/* error exit handlers */
v0071:
    popv(4);
    return nil;
}



/* Code for general!-evaluate!-mod!-p */

static Lisp_Object MS_CDECL CC_generalKevaluateKmodKp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0134, v0133, v0167, v0168, v0148;
    Lisp_Object fn;
    Lisp_Object v0003, v0087, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "general-evaluate-mod-p");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0087 = va_arg(aa, Lisp_Object);
    v0003 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-evaluate-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0003,v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0087,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0003;
    stack[-2] = v0087;
    stack[-3] = v0000;
/* end of prologue */

v0077:
    v0134 = stack[-3];
    if (!consp(v0134)) goto v0086;
    v0134 = stack[-3];
    v0134 = qcar(v0134);
    v0134 = (consp(v0134) ? nil : lisp_true);
    goto v0085;

v0085:
    if (!(v0134 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0133 = stack[-1];
    v0134 = (Lisp_Object)1; /* 0 */
    if (v0133 == v0134) goto v0015;
    v0134 = stack[-2];
    if (v0134 == nil) goto v0154;
    v0134 = stack[-3];
    v0134 = qcar(v0134);
    v0134 = qcar(v0134);
    v0133 = qcar(v0134);
    v0134 = stack[-2];
    if (equal(v0133, v0134)) goto v0092;
    v0134 = stack[-3];
    v0134 = qcar(v0134);
    stack[-4] = qcar(v0134);
    v0134 = stack[-3];
    v0134 = qcar(v0134);
    v0167 = qcdr(v0134);
    v0133 = stack[-2];
    v0134 = stack[-1];
    stack[0] = CC_generalKevaluateKmodKp(env, 3, v0167, v0133, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-5];
    v0134 = stack[-3];
    v0167 = qcdr(v0134);
    v0133 = stack[-2];
    v0134 = stack[-1];
    v0134 = CC_generalKevaluateKmodKp(env, 3, v0167, v0133, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-5];
    {
        Lisp_Object v0130 = stack[-4];
        Lisp_Object v0166 = stack[0];
        popv(6);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0130, v0166, v0134);
    }

v0092:
    v0134 = stack[-3];
    v0134 = qcar(v0134);
    v0148 = qcdr(v0134);
    v0134 = stack[-3];
    v0134 = qcar(v0134);
    v0134 = qcar(v0134);
    v0168 = qcdr(v0134);
    v0134 = stack[-3];
    v0167 = qcdr(v0134);
    v0133 = stack[-1];
    v0134 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* general!-horner!-rule!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 5, v0148, v0168, v0167, v0133, v0134);
    }

v0154:
    v0134 = elt(env, 3); /* "Variable=NIL in GENERAL-EVALUATE-MOD-P" */
    {
        popv(6);
        fn = elt(env, 6); /* errorf */
        return (*qfn1(fn))(qenv(fn), v0134);
    }

v0015:
    v0134 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v0134;
    goto v0077;

v0086:
    v0134 = qvalue(elt(env, 1)); /* t */
    goto v0085;
/* error exit handlers */
v0170:
    popv(6);
    return nil;
}



/* Code for gettype */

static Lisp_Object CC_gettype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0078;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gettype");
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
    v0050 = stack[0];
    if (is_number(v0050)) goto v0002;
    v0050 = stack[0];
    if (!consp(v0050)) goto v0090;
    v0050 = qvalue(elt(env, 2)); /* t */
    goto v0084;

v0084:
    if (v0050 == nil) goto v0057;
    v0050 = elt(env, 3); /* form */
    { popv(2); return onevalue(v0050); }

v0057:
    v0050 = stack[0];
    if (!symbolp(v0050)) v0050 = nil;
    else { v0050 = qfastgets(v0050);
           if (v0050 != nil) { v0050 = elt(v0050, 22); /* simpfn */
#ifdef RECORD_GET
             if (v0050 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v0050 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v0050 == SPID_NOPROP) v0050 = nil; }}
#endif
    if (v0050 == nil) goto v0025;
    v0050 = elt(env, 4); /* operator */
    { popv(2); return onevalue(v0050); }

v0025:
    v0050 = stack[0];
    if (!symbolp(v0050)) v0050 = nil;
    else { v0050 = qfastgets(v0050);
           if (v0050 != nil) { v0050 = elt(v0050, 4); /* avalue */
#ifdef RECORD_GET
             if (v0050 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0050 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0050 == SPID_NOPROP) v0050 = nil; }}
#endif
    if (v0050 == nil) goto v0091;
    v0050 = stack[0];
    if (!symbolp(v0050)) v0050 = nil;
    else { v0050 = qfastgets(v0050);
           if (v0050 != nil) { v0050 = elt(v0050, 4); /* avalue */
#ifdef RECORD_GET
             if (v0050 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0050 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0050 == SPID_NOPROP) v0050 = nil; }}
#endif
    v0050 = qcar(v0050);
    { popv(2); return onevalue(v0050); }

v0091:
    v0050 = stack[0];
    fn = elt(env, 10); /* getd */
    v0050 = (*qfn1(fn))(qenv(fn), v0050);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    if (v0050 == nil) goto v0098;
    v0050 = elt(env, 5); /* procedure */
    { popv(2); return onevalue(v0050); }

v0098:
    v0050 = stack[0];
    v0050 = Lsymbol_globalp(nil, v0050);
    env = stack[-1];
    if (v0050 == nil) goto v0089;
    v0050 = elt(env, 6); /* global */
    { popv(2); return onevalue(v0050); }

v0089:
    v0050 = stack[0];
    v0050 = Lsymbol_specialp(nil, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    if (v0050 == nil) goto v0052;
    v0050 = elt(env, 7); /* fluid */
    { popv(2); return onevalue(v0050); }

v0052:
    v0078 = stack[0];
    v0050 = elt(env, 8); /* parm */
    v0050 = Lflagp(nil, v0078, v0050);
    env = stack[-1];
    if (v0050 == nil) goto v0101;
    v0050 = elt(env, 9); /* parameter */
    { popv(2); return onevalue(v0050); }

v0101:
    v0050 = stack[0];
    if (!symbolp(v0050)) v0050 = nil;
    else { v0050 = qfastgets(v0050);
           if (v0050 != nil) { v0050 = elt(v0050, 2); /* rtype */
#ifdef RECORD_GET
             if (v0050 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0050 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0050 == SPID_NOPROP) v0050 = nil; }}
#endif
    { popv(2); return onevalue(v0050); }

v0090:
    v0050 = stack[0];
    if (v0050 == nil) goto v0139;
    v0050 = stack[0];
    v0050 = Lsymbolp(nil, v0050);
    env = stack[-1];
    v0050 = (v0050 == nil ? lisp_true : nil);
    goto v0084;

v0139:
    v0050 = qvalue(elt(env, 2)); /* t */
    goto v0084;

v0002:
    v0050 = elt(env, 1); /* number */
    { popv(2); return onevalue(v0050); }
/* error exit handlers */
v0045:
    popv(2);
    return nil;
}



/* Code for setqget */

static Lisp_Object MS_CDECL CC_setqget(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0194, v0039;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setqget");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setqget");
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
    push2(nil, nil);
/* end of prologue */
    v0194 = qvalue(elt(env, 1)); /* fluidbibasissetq */
    v0194 = qcar(v0194);
    stack[-1] = v0194;
    v0194 = qvalue(elt(env, 1)); /* fluidbibasissetq */
    stack[0] = v0194;
    v0039 = stack[0];
    v0194 = stack[0];
    v0194 = qcdr(v0194);
    v0194 = qcar(v0194);
    v0039 = Lrplaca(nil, v0039, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-2];
    v0194 = stack[0];
    v0194 = qcdr(v0194);
    v0194 = qcdr(v0194);
    v0194 = Lrplacd(nil, v0039, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v0021:
    popv(3);
    return nil;
}



/* Code for delet */

static Lisp_Object CC_delet(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0078, v0200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delet");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0087;
    stack[-1] = v0000;
/* end of prologue */
    v0200 = nil;
    goto v0077;

v0077:
    v0050 = stack[-1];
    if (v0050 == nil) goto v0086;
    v0050 = stack[0];
    if (v0050 == nil) goto v0143;
    v0078 = stack[-1];
    v0050 = stack[0];
    v0050 = (equal(v0078, v0050) ? lisp_true : nil);
    goto v0015;

v0015:
    if (v0050 == nil) goto v0109;
    v0050 = v0200;
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0050);
    }

v0109:
    v0078 = stack[-1];
    v0050 = stack[0];
    v0050 = qcar(v0050);
    if (equal(v0078, v0050)) goto v0092;
    v0050 = stack[0];
    v0050 = qcar(v0050);
    v0078 = v0200;
    v0050 = cons(v0050, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0200 = v0050;
    v0050 = stack[0];
    v0050 = qcdr(v0050);
    stack[0] = v0050;
    goto v0077;

v0092:
    v0078 = v0200;
    v0050 = stack[0];
    v0050 = qcdr(v0050);
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0078, v0050);
    }

v0143:
    v0050 = qvalue(elt(env, 1)); /* t */
    goto v0015;

v0086:
    v0078 = v0200;
    v0050 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0078, v0050);
    }
/* error exit handlers */
v0046:
    popv(3);
    return nil;
}



/* Code for ibalp_var!-set */

static Lisp_Object MS_CDECL CC_ibalp_varKset(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0213, v0218;
    Lisp_Object fn;
    Lisp_Object v0036, v0003, v0087, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ibalp_var-set");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0087 = va_arg(aa, Lisp_Object);
    v0003 = va_arg(aa, Lisp_Object);
    v0036 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_var-set");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0036,v0003,v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0087,v0003,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
    stack[-1] = v0003;
    stack[-2] = v0087;
    stack[-3] = v0000;
/* end of prologue */
    v0213 = stack[-3];
    v0218 = qcdr(v0213);
    v0213 = stack[-2];
    fn = elt(env, 1); /* setcar */
    v0213 = (*qfn2(fn))(qenv(fn), v0218, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-4];
    v0213 = stack[-3];
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0218 = qcdr(v0213);
    v0213 = stack[-1];
    fn = elt(env, 1); /* setcar */
    v0213 = (*qfn2(fn))(qenv(fn), v0218, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-4];
    v0213 = stack[-3];
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0218 = qcdr(v0213);
    v0213 = stack[0];
    fn = elt(env, 1); /* setcar */
    v0213 = (*qfn2(fn))(qenv(fn), v0218, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-4];
    v0213 = stack[-3];
    v0213 = qcar(v0213);
    stack[0] = v0213;
    v0218 = stack[-2];
    v0213 = (Lisp_Object)1; /* 0 */
    v0213 = Leqn(nil, v0218, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-4];
    if (v0213 == nil) goto v0100;
    v0213 = stack[-3];
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcar(v0213);
    goto v0200;

v0200:
    v0218 = v0213;
    v0213 = stack[0];
    fn = elt(env, 2); /* ibalp_var!-satlist */
    v0213 = (*qfn2(fn))(qenv(fn), v0218, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-4];
    v0218 = stack[-2];
    v0213 = (Lisp_Object)17; /* 1 */
    v0213 = Leqn(nil, v0218, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-4];
    if (v0213 == nil) goto v0220;
    v0213 = stack[-3];
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcar(v0213);
    goto v0110;

v0110:
    v0218 = v0213;
    v0213 = stack[-2];
    fn = elt(env, 3); /* ibalp_var!-unsatlist */
    v0213 = (*qfn2(fn))(qenv(fn), v0218, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-4];
    v0213 = stack[-3];
    fn = elt(env, 4); /* ibalp_var!-wclist */
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-4];
    stack[-1] = v0213;
    v0213 = stack[-3];
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    stack[0] = qcdr(v0213);
    v0213 = stack[-3];
    fn = elt(env, 5); /* ibalp_calcmom */
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-4];
    fn = elt(env, 1); /* setcar */
    v0213 = (*qfn2(fn))(qenv(fn), stack[0], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }

v0220:
    v0213 = stack[-3];
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcar(v0213);
    goto v0110;

v0100:
    v0213 = stack[-3];
    v0213 = qcdr(v0213);
    v0213 = qcdr(v0213);
    v0213 = qcar(v0213);
    goto v0200;
/* error exit handlers */
v0178:
    popv(5);
    return nil;
}



/* Code for ratpoly_1 */

static Lisp_Object MS_CDECL CC_ratpoly_1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0083;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ratpoly_1");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratpoly_1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0083 = (Lisp_Object)17; /* 1 */
    v0057 = (Lisp_Object)17; /* 1 */
    return cons(v0083, v0057);
}



/* Code for reln */

static Lisp_Object CC_reln(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0154, v0059;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reln");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0087;
    stack[-1] = v0000;
/* end of prologue */
    v0154 = elt(env, 1); /* "<reln>" */
    fn = elt(env, 6); /* printout */
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-2];
    v0154 = elt(env, 2); /* "<" */
    v0154 = Lprinc(nil, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-2];
    v0154 = stack[0];
    v0154 = Lprinc(nil, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-2];
    v0154 = elt(env, 3); /* "/>" */
    v0154 = Lprinc(nil, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-2];
    v0059 = qvalue(elt(env, 4)); /* indent */
    v0154 = (Lisp_Object)49; /* 3 */
    v0154 = plus2(v0059, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0154; /* indent */
    v0154 = stack[-1];
    fn = elt(env, 7); /* multi_elem */
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-2];
    v0059 = qvalue(elt(env, 4)); /* indent */
    v0154 = (Lisp_Object)49; /* 3 */
    v0154 = difference2(v0059, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0154; /* indent */
    v0154 = elt(env, 5); /* "</reln>" */
    fn = elt(env, 6); /* printout */
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    v0154 = nil;
    { popv(3); return onevalue(v0154); }
/* error exit handlers */
v0226:
    popv(3);
    return nil;
}



/* Code for diffsq */

static Lisp_Object CC_diffsq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0201, v0092;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diffsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0087,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0087);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0087;
    stack[-2] = v0000;
/* end of prologue */
    v0201 = stack[-2];
    v0092 = qcar(v0201);
    v0201 = stack[-1];
    fn = elt(env, 1); /* difff */
    stack[-3] = (*qfn2(fn))(qenv(fn), v0092, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-4];
    stack[0] = stack[-2];
    v0201 = stack[-2];
    v0092 = qcdr(v0201);
    v0201 = stack[-1];
    fn = elt(env, 1); /* difff */
    v0201 = (*qfn2(fn))(qenv(fn), v0092, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-4];
    fn = elt(env, 2); /* multsq */
    v0201 = (*qfn2(fn))(qenv(fn), stack[0], v0201);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-4];
    fn = elt(env, 3); /* negsq */
    v0201 = (*qfn1(fn))(qenv(fn), v0201);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v0201);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-4];
    v0092 = (Lisp_Object)17; /* 1 */
    v0201 = stack[-2];
    v0201 = qcdr(v0201);
    v0201 = cons(v0092, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-4];
    {
        Lisp_Object v0108 = stack[0];
        popv(5);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0108, v0201);
    }
/* error exit handlers */
v0094:
    popv(5);
    return nil;
}



/* Code for take!-realpart */

static Lisp_Object CC_takeKrealpart(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086, v0206;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for take-realpart");
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
    v0086 = stack[0];
    v0086 = qcar(v0086);
    fn = elt(env, 1); /* repartf */
    v0206 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    v0086 = stack[0];
    v0086 = qcdr(v0086);
    popv(1);
    return cons(v0206, v0086);
/* error exit handlers */
v0090:
    popv(1);
    return nil;
}



/* Code for sc_minussq */

static Lisp_Object CC_sc_minussq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0001;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_minussq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0001 = v0000;
/* end of prologue */
    v0001 = qcar(v0001);
    {
        fn = elt(env, 1); /* minusf */
        return (*qfn1(fn))(qenv(fn), v0001);
    }
}



/* Code for ordop2 */

static Lisp_Object CC_ordop2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0087)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0041, v0062, v0089, v0188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordop2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0089 = v0087;
    v0188 = v0000;
/* end of prologue */
    v0048 = qvalue(elt(env, 1)); /* kord!* */
    v0062 = v0048;
    goto v0077;

v0077:
    v0048 = v0062;
    if (v0048 == nil) goto v0206;
    v0041 = v0188;
    v0048 = v0062;
    v0048 = qcar(v0048);
    if (v0041 == v0048) goto v0181;
    v0041 = v0089;
    v0048 = v0062;
    v0048 = qcar(v0048);
    if (v0041 == v0048) goto v0021;
    v0048 = v0062;
    v0048 = qcdr(v0048);
    v0062 = v0048;
    goto v0077;

v0021:
    v0048 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0048);

v0181:
    v0048 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0048);

v0206:
    v0048 = v0188;
    v0041 = v0089;
    {
        fn = elt(env, 4); /* ordp */
        return (*qfn2(fn))(qenv(fn), v0048, v0041);
    }
}



/* Code for mo_from_a */

static Lisp_Object CC_mo_from_a(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0208, v0043;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_from_a");
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
    stack[0] = stack[-3];
    v0208 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_all_names */
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-5];
    v0208 = Lmember(nil, stack[0], v0208);
    if (v0208 == nil) goto v0090;
    v0208 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_all_names */
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-5];
    stack[-4] = v0208;
    v0208 = stack[-4];
    if (v0208 == nil) goto v0227;
    v0208 = stack[-4];
    v0208 = qcar(v0208);
    v0043 = v0208;
    v0208 = stack[-3];
    if (equal(v0043, v0208)) goto v0201;
    v0208 = (Lisp_Object)1; /* 0 */
    goto v0188;

v0188:
    v0208 = ncons(v0208);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-5];
    stack[-1] = v0208;
    stack[-2] = v0208;
    goto v0063;

v0063:
    v0208 = stack[-4];
    v0208 = qcdr(v0208);
    stack[-4] = v0208;
    v0208 = stack[-4];
    if (v0208 == nil) goto v0100;
    stack[0] = stack[-1];
    v0208 = stack[-4];
    v0208 = qcar(v0208);
    v0043 = v0208;
    v0208 = stack[-3];
    if (equal(v0043, v0208)) goto v0187;
    v0208 = (Lisp_Object)1; /* 0 */
    goto v0135;

v0135:
    v0208 = ncons(v0208);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-5];
    v0208 = Lrplacd(nil, stack[0], v0208);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-5];
    v0208 = stack[-1];
    v0208 = qcdr(v0208);
    stack[-1] = v0208;
    goto v0063;

v0187:
    v0208 = (Lisp_Object)17; /* 1 */
    goto v0135;

v0100:
    v0208 = stack[-2];
    goto v0059;

v0059:
    fn = elt(env, 5); /* mo!=shorten */
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-5];
    stack[0] = v0208;
    fn = elt(env, 6); /* mo!=deglist */
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    {
        Lisp_Object v0229 = stack[0];
        popv(6);
        return cons(v0229, v0208);
    }

v0201:
    v0208 = (Lisp_Object)17; /* 1 */
    goto v0188;

v0227:
    v0208 = qvalue(elt(env, 3)); /* nil */
    goto v0059;

v0090:
    v0043 = stack[-3];
    v0208 = elt(env, 2); /* "dpoly variable" */
    {
        popv(6);
        fn = elt(env, 7); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0043, v0208);
    }
/* error exit handlers */
v0148:
    popv(6);
    return nil;
}



/* Code for pst_termnodep */

static Lisp_Object CC_pst_termnodep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086, v0206;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pst_termnodep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0086 = v0000;
/* end of prologue */
    v0206 = qcdr(v0086);
    v0086 = (Lisp_Object)1; /* 0 */
    v0086 = *(Lisp_Object *)((char *)v0206 + (CELL-TAG_VECTOR) + ((int32_t)v0086/(16/CELL)));
    v0086 = qcdr(v0086);
    v0086 = (v0086 == nil ? lisp_true : nil);
    return onevalue(v0086);
}



setup_type const u19_setup[] =
{
    {"prepsq*",                 CC_prepsqH,     too_many_1,    wrong_no_1},
    {"cl_fvarl",                CC_cl_fvarl,    too_many_1,    wrong_no_1},
    {"ibalp_tvb",               too_few_2,      CC_ibalp_tvb,  wrong_no_2},
    {"ratpoly_tad",             CC_ratpoly_tad, too_many_1,    wrong_no_1},
    {"applyrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_applyrd},
    {"rd:zerop:",               CC_rdTzeropT,   too_many_1,    wrong_no_1},
    {"freeoff",                 too_few_2,      CC_freeoff,    wrong_no_2},
    {"wedgek2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_wedgek2},
    {"indordp",                 too_few_2,      CC_indordp,    wrong_no_2},
    {"sfpx1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_sfpx1},
    {"fs:times",                too_few_2,      CC_fsTtimes,   wrong_no_2},
    {"symbvarlst",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_symbvarlst},
    {"evaluatecoeffts",         too_few_2,      CC_evaluatecoeffts,wrong_no_2},
    {"qqe_arg-check",           CC_qqe_argKcheck,too_many_1,   wrong_no_1},
    {"pasf_vf",                 CC_pasf_vf,     too_many_1,    wrong_no_1},
    {"ibalp_var-wclist",        CC_ibalp_varKwclist,too_many_1,wrong_no_1},
    {"cgb_buch-ev_divides?",    too_few_2,      CC_cgb_buchKev_dividesW,wrong_no_2},
    {"diff-over-k-mod-p",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffKoverKkKmodKp},
    {"ir2mml",                  CC_ir2mml,      too_many_1,    wrong_no_1},
    {"pfordp",                  too_few_2,      CC_pfordp,     wrong_no_2},
    {"delete-dups",             CC_deleteKdups, too_many_1,    wrong_no_1},
    {"fortranname",             CC_fortranname, too_many_1,    wrong_no_1},
    {"coposp",                  CC_coposp,      too_many_1,    wrong_no_1},
    {"factorial",               CC_factorial,   too_many_1,    wrong_no_1},
    {"mv-domainlist-*",         too_few_2,      CC_mvKdomainlistKH,wrong_no_2},
    {"dv_cambhead",             CC_dv_cambhead, too_many_1,    wrong_no_1},
    {"lalr_clean_up",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_lalr_clean_up},
    {"remlocs",                 CC_remlocs,     too_many_1,    wrong_no_1},
    {"ofsf_surep",              too_few_2,      CC_ofsf_surep, wrong_no_2},
    {"simpqg",                  CC_simpqg,      too_many_1,    wrong_no_1},
    {"new_pde",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_new_pde},
    {"kernord-split",           too_few_2,      CC_kernordKsplit,wrong_no_2},
    {"ibalp_isinminclause",     too_few_2,      CC_ibalp_isinminclause,wrong_no_2},
    {"aex_lc",                  too_few_2,      CC_aex_lc,     wrong_no_2},
    {"resume",                  too_few_2,      CC_resume,     wrong_no_2},
    {"onoff",                   too_few_2,      CC_onoff,      wrong_no_2},
    {"evdif",                   too_few_2,      CC_evdif,      wrong_no_2},
    {"all_defined_vertex",      too_few_2,      CC_all_defined_vertex,wrong_no_2},
    {"set-global-mode",         CC_setKglobalKmode,too_many_1, wrong_no_1},
    {"groeb=weight",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebMweight},
    {"general-evaluate-mod-p",  wrong_no_na,    wrong_no_nb,   (n_args *)CC_generalKevaluateKmodKp},
    {"gettype",                 CC_gettype,     too_many_1,    wrong_no_1},
    {"setqget",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_setqget},
    {"delet",                   too_few_2,      CC_delet,      wrong_no_2},
    {"ibalp_var-set",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ibalp_varKset},
    {"ratpoly_1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ratpoly_1},
    {"reln",                    too_few_2,      CC_reln,       wrong_no_2},
    {"diffsq",                  too_few_2,      CC_diffsq,     wrong_no_2},
    {"take-realpart",           CC_takeKrealpart,too_many_1,   wrong_no_1},
    {"sc_minussq",              CC_sc_minussq,  too_many_1,    wrong_no_1},
    {"ordop2",                  too_few_2,      CC_ordop2,     wrong_no_2},
    {"mo_from_a",               CC_mo_from_a,   too_many_1,    wrong_no_1},
    {"pst_termnodep",           CC_pst_termnodep,too_many_1,   wrong_no_1},
    {NULL, (one_args *)"u19", (two_args *)"3309 178431 1664088", 0}
};

/* end of generated code */
