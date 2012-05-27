
/* $destdir\u35.c        Machine generated C code */

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


/* Code for ofsf_evalatp */

static Lisp_Object CC_ofsf_evalatp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v17, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_evalatp");
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
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    v18 = v0;
/* end of prologue */
    v17 = v18;
    v16 = elt(env, 1); /* equal */
    if (v17 == v16) goto v19;
    v17 = v18;
    v16 = elt(env, 2); /* neq */
    if (v17 == v16) goto v20;
    v17 = v18;
    v16 = elt(env, 3); /* leq */
    if (v17 == v16) goto v21;
    v17 = v18;
    v16 = elt(env, 4); /* geq */
    if (v17 == v16) goto v22;
    v17 = v18;
    v16 = elt(env, 5); /* lessp */
    if (v17 == v16) goto v23;
    v17 = v18;
    v16 = elt(env, 6); /* greaterp */
    if (v17 == v16) goto v24;
    v16 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v16 == nil)) goto v25;
    v16 = elt(env, 8); /* "ofsf_evalatp: unknown operator " */
    v17 = v18;
    v16 = list2(v16, v17);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-1];
    fn = elt(env, 9); /* lprie */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-1];
    goto v25;

v25:
    v16 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v26;
    v16 = nil;
    { popv(2); return onevalue(v16); }

v24:
    v16 = stack[0];
    fn = elt(env, 10); /* minusf */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v26;
    if (!(v16 == nil)) goto v27;
    v16 = stack[0];
    v16 = (v16 == nil ? lisp_true : nil);
    goto v27;

v27:
    v16 = (v16 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v16); }

v23:
    v16 = stack[0];
    {
        popv(2);
        fn = elt(env, 10); /* minusf */
        return (*qfn1(fn))(qenv(fn), v16);
    }

v22:
    v16 = stack[0];
    fn = elt(env, 10); /* minusf */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v26;
    v16 = (v16 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v16); }

v21:
    v16 = stack[0];
    fn = elt(env, 10); /* minusf */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v26;
    if (!(v16 == nil)) { popv(2); return onevalue(v16); }
    v16 = stack[0];
    v16 = (v16 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v16); }

v20:
    v16 = stack[0];
    v16 = (v16 == nil ? lisp_true : nil);
    v16 = (v16 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v16); }

v19:
    v16 = stack[0];
    v16 = (v16 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v16); }
/* error exit handlers */
v26:
    popv(2);
    return nil;
}



/* Code for qqe_ofsf_varlat */

static Lisp_Object CC_qqe_ofsf_varlat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_ofsf_varlat");
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
    v34 = v0;
/* end of prologue */
    fn = elt(env, 2); /* qqe_ofsf_prepat */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    stack[-1] = v34;
    v34 = stack[-1];
    fn = elt(env, 3); /* qqe_arg2l */
    v35 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    v34 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* qqe_ofsf_varlterm */
    stack[0] = (*qfn2(fn))(qenv(fn), v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    v34 = stack[-1];
    fn = elt(env, 5); /* qqe_arg2r */
    v35 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    v34 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* qqe_ofsf_varlterm */
    v34 = (*qfn2(fn))(qenv(fn), v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    {
        Lisp_Object v37 = stack[0];
        popv(3);
        fn = elt(env, 6); /* union */
        return (*qfn2(fn))(qenv(fn), v37, v34);
    }
/* error exit handlers */
v36:
    popv(3);
    return nil;
}



/* Code for aex_subrp */

static Lisp_Object MS_CDECL CC_aex_subrp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v42, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "aex_subrp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_subrp");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v38;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v35 = stack[-2];
    fn = elt(env, 2); /* aex_ex */
    v43 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-3];
    v42 = stack[-1];
    v35 = stack[0];
    fn = elt(env, 3); /* ratpoly_sub */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v43, v42, v35);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-3];
    v35 = stack[-2];
    fn = elt(env, 4); /* aex_ctx */
    v43 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-3];
    v42 = qvalue(elt(env, 1)); /* nil */
    v35 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v44 = stack[0];
        popv(4);
        fn = elt(env, 5); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v44, v43, v42, v35);
    }
/* error exit handlers */
v11:
    popv(4);
    return nil;
}



/* Code for intervalrd */

static Lisp_Object MS_CDECL CC_intervalrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "intervalrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intervalrd");
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
    fn = elt(env, 4); /* mathml */
    v44 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-2];
    stack[-1] = v44;
    fn = elt(env, 4); /* mathml */
    v44 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-2];
    stack[0] = v44;
    fn = elt(env, 5); /* lex */
    v44 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-2];
    v46 = qvalue(elt(env, 1)); /* char */
    v44 = elt(env, 2); /* (!/ i n t e r v a l) */
    if (equal(v46, v44)) goto v29;
    v46 = elt(env, 3); /* "</interval>" */
    v44 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 6); /* errorml */
    v44 = (*qfn2(fn))(qenv(fn), v46, v44);
    nil = C_nil;
    if (exception_pending()) goto v47;
    v44 = nil;
    { popv(3); return onevalue(v44); }

v29:
    v46 = stack[-1];
    v44 = stack[0];
    popv(3);
    return list2(v46, v44);
/* error exit handlers */
v47:
    popv(3);
    return nil;
}



/* Code for simpsqrtsq */

static Lisp_Object CC_simpsqrtsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpsqrtsq");
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
    v39 = stack[0];
    v39 = qcar(v39);
    fn = elt(env, 1); /* simpsqrt2 */
    stack[-1] = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    v39 = stack[0];
    v39 = qcdr(v39);
    fn = elt(env, 1); /* simpsqrt2 */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v32;
    {
        Lisp_Object v45 = stack[-1];
        popv(3);
        return cons(v45, v39);
    }
/* error exit handlers */
v32:
    popv(3);
    return nil;
}



/* Code for cr!:onep */

static Lisp_Object CC_crTonep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cr:onep");
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
    v57 = stack[0];
    v57 = qcdr(v57);
    v57 = qcdr(v57);
    if (!consp(v57)) goto v48;
    v58 = elt(env, 1); /* !:rd!: */
    v57 = stack[0];
    v57 = qcdr(v57);
    v57 = qcdr(v57);
    v57 = cons(v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    goto v60;

v60:
    v58 = v57;
    v57 = v58;
    if (!consp(v57)) goto v42;
    v57 = v58;
    v57 = qcdr(v57);
    v58 = qcar(v57);
    v57 = (Lisp_Object)1; /* 0 */
    v57 = (v58 == v57 ? lisp_true : nil);
    goto v35;

v35:
    if (v57 == nil) goto v31;
    v57 = stack[0];
    v57 = qcdr(v57);
    v57 = qcar(v57);
    if (!consp(v57)) goto v61;
    v58 = elt(env, 1); /* !:rd!: */
    v57 = stack[0];
    v57 = qcdr(v57);
    v57 = qcar(v57);
    v57 = cons(v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    goto v62;

v62:
    v58 = v57;
    if (!(!consp(v58))) goto v63;
    v58 = elt(env, 1); /* !:rd!: */
    v57 = cons(v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    goto v63;

v63:
    {
        popv(2);
        fn = elt(env, 3); /* rd!:onep */
        return (*qfn1(fn))(qenv(fn), v57);
    }

v61:
    v57 = stack[0];
    v57 = qcdr(v57);
    v57 = qcar(v57);
    goto v62;

v31:
    v57 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v57); }

v42:
    v57 = v58;
    v57 = (Lisp_Object)zerop(v57);
    v57 = v57 ? lisp_true : nil;
    env = stack[-1];
    goto v35;

v48:
    v57 = stack[0];
    v57 = qcdr(v57);
    v57 = qcdr(v57);
    goto v60;
/* error exit handlers */
v59:
    popv(2);
    return nil;
}



/* Code for findhr */

static Lisp_Object MS_CDECL CC_findhr(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v4, v5;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "findhr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findhr");
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
    goto v15;

v15:
    v4 = qvalue(elt(env, 1)); /* headhisto */
    v52 = (Lisp_Object)1; /* 0 */
    v52 = (Lisp_Object)greaterp2(v4, v52);
    nil = C_nil;
    if (exception_pending()) goto v69;
    v52 = v52 ? lisp_true : nil;
    env = stack[-2];
    if (v52 == nil) goto v19;
    v4 = qvalue(elt(env, 2)); /* codhisto */
    v52 = qvalue(elt(env, 1)); /* headhisto */
    v52 = *(Lisp_Object *)((char *)v4 + (CELL-TAG_VECTOR) + ((int32_t)v52/(16/CELL)));
    stack[-1] = v52;
    if (!(v52 == nil)) goto v19;
    v52 = qvalue(elt(env, 1)); /* headhisto */
    v52 = sub1(v52);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    qvalue(elt(env, 1)) = v52; /* headhisto */
    goto v15;

v19:
    v52 = stack[-1];
    if (v52 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v52 = stack[-1];
    v52 = ncons(v52);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    qvalue(elt(env, 4)) = v52; /* psi */
    v52 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 5)) = v52; /* npsi */
    stack[0] = qvalue(elt(env, 6)); /* codmat */
    v4 = qvalue(elt(env, 7)); /* maxvar */
    v52 = stack[-1];
    v52 = plus2(v4, v52);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    v5 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v52/(16/CELL)));
    v4 = (Lisp_Object)1; /* 0 */
    v52 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v5 + (CELL-TAG_VECTOR) + ((int32_t)v4/(16/CELL))) = v52;
    v4 = stack[-1];
    v52 = qvalue(elt(env, 8)); /* rcoccup */
    v52 = cons(v4, v52);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    qvalue(elt(env, 8)) = v52; /* rcoccup */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v69:
    popv(3);
    return nil;
}



/* Code for evinsert */

static Lisp_Object MS_CDECL CC_evinsert(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v38, Lisp_Object v70, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v24, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "evinsert");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evinsert");
#endif
    if (stack >= stacklimit)
    {
        push4(v70,v38,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v38,v70);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v70;
    stack[-1] = v38;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v75 = nil;
    goto v48;

v48:
    v74 = stack[-3];
    if (v74 == nil) goto v76;
    v74 = stack[0];
    v74 = (v74 == nil ? lisp_true : nil);
    goto v39;

v39:
    if (v74 == nil) goto v56;
    v74 = v75;
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v74);
    }

v56:
    v74 = stack[0];
    v24 = qcar(v74);
    v74 = stack[-2];
    if (equal(v24, v74)) goto v11;
    v74 = stack[-3];
    v74 = qcar(v74);
    v24 = v75;
    v74 = cons(v74, v24);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v75 = v74;
    v74 = stack[-3];
    v74 = qcdr(v74);
    stack[-3] = v74;
    v74 = stack[0];
    v74 = qcdr(v74);
    stack[0] = v74;
    goto v48;

v11:
    stack[0] = v75;
    v24 = stack[-1];
    v74 = stack[-3];
    v74 = qcdr(v74);
    v74 = cons(v24, v74);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    {
        Lisp_Object v4 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v4, v74);
    }

v76:
    v74 = qvalue(elt(env, 1)); /* t */
    goto v39;
/* error exit handlers */
v52:
    popv(5);
    return nil;
}



/* Code for xpartitop */

static Lisp_Object CC_xpartitop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xpartitop");
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
    v19 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* xpartitsq */
        return (*qfn1(fn))(qenv(fn), v19);
    }
/* error exit handlers */
v55:
    popv(1);
    return nil;
}



/* Code for listpri */

static Lisp_Object CC_listpri(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listpri");
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
    v81 = stack[-2];
    stack[0] = v81;
    v81 = stack[-2];
    v81 = qcdr(v81);
    stack[-2] = v81;
    v82 = elt(env, 1); /* !*lcbkt!* */
    v81 = elt(env, 2); /* prtch */
    v81 = get(v82, v81);
    env = stack[-4];
    fn = elt(env, 10); /* prin2!* */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    v81 = qvalue(elt(env, 3)); /* orig!* */
    stack[-3] = v81;
    v82 = qvalue(elt(env, 4)); /* posn!* */
    v81 = (Lisp_Object)289; /* 18 */
    v81 = (Lisp_Object)lessp2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v83;
    v81 = v81 ? lisp_true : nil;
    env = stack[-4];
    if (v81 == nil) goto v46;
    v81 = qvalue(elt(env, 4)); /* posn!* */
    goto v12;

v12:
    qvalue(elt(env, 3)) = v81; /* orig!* */
    v81 = stack[-2];
    if (v81 == nil) goto v84;
    v82 = stack[-2];
    v81 = (Lisp_Object)641; /* 40 */
    fn = elt(env, 11); /* treesizep1 */
    v82 = (*qfn2(fn))(qenv(fn), v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    v81 = (Lisp_Object)1; /* 0 */
    v81 = (v82 == v81 ? lisp_true : nil);
    stack[-1] = v81;
    goto v85;

v85:
    v81 = stack[-2];
    v82 = qcar(v81);
    v81 = elt(env, 5); /* minus */
    if (!consp(v82)) goto v86;
    v82 = qcar(v82);
    if (!(v82 == v81)) goto v86;
    v81 = stack[-2];
    v81 = qcar(v81);
    v81 = qcdr(v81);
    v81 = qcar(v81);
    v81 = (is_number(v81) ? lisp_true : nil);
    goto v63;

v63:
    if (v81 == nil) goto v3;
    v81 = stack[-2];
    v81 = qcar(v81);
    v81 = qcdr(v81);
    v81 = qcar(v81);
    v81 = negate(v81);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    v82 = v81;
    goto v75;

v75:
    v81 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 12); /* maprint */
    v81 = (*qfn2(fn))(qenv(fn), v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    v81 = stack[-2];
    v81 = qcdr(v81);
    stack[-2] = v81;
    v81 = stack[-2];
    if (v81 == nil) goto v84;
    v81 = elt(env, 7); /* !*comma!* */
    fn = elt(env, 13); /* oprin */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    v81 = stack[-1];
    if (v81 == nil) goto v85;
    v81 = qvalue(elt(env, 8)); /* t */
    fn = elt(env, 14); /* terpri!* */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    goto v85;

v84:
    v82 = elt(env, 9); /* !*rcbkt!* */
    v81 = elt(env, 2); /* prtch */
    v81 = get(v82, v81);
    env = stack[-4];
    fn = elt(env, 10); /* prin2!* */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    v81 = stack[-3];
    qvalue(elt(env, 3)) = v81; /* orig!* */
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v3:
    v81 = stack[-2];
    v81 = qcar(v81);
    v82 = v81;
    goto v75;

v86:
    v81 = qvalue(elt(env, 6)); /* nil */
    goto v63;

v46:
    v82 = qvalue(elt(env, 3)); /* orig!* */
    v81 = (Lisp_Object)49; /* 3 */
    v81 = plus2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    goto v12;
/* error exit handlers */
v83:
    popv(5);
    return nil;
}



/* Code for numprintlen */

static Lisp_Object CC_numprintlen(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numprintlen");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
/* end of prologue */

v31:
    v119 = stack[-1];
    if (!consp(v119)) goto v60;
    v119 = stack[-1];
    v119 = Llength(nil, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v119 = Lonep(nil, v119);
    env = stack[-6];
    if (v119 == nil) goto v41;
    v119 = stack[-1];
    v119 = qcar(v119);
    stack[-1] = v119;
    goto v31;

v41:
    v119 = stack[-1];
    v120 = qcar(v119);
    v119 = elt(env, 1); /* !:rd!: */
    if (v120 == v119) goto v36;
    v119 = stack[-1];
    v120 = qcar(v119);
    v119 = elt(env, 3); /* (!:cr!: !:crn!: !:gi!:) */
    v119 = Lmemq(nil, v120, v119);
    if (v119 == nil) goto v122;
    v120 = elt(env, 1); /* !:rd!: */
    v119 = stack[-1];
    v119 = qcdr(v119);
    v119 = qcar(v119);
    v119 = cons(v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v120 = v119;
    v119 = v120;
    v119 = qcdr(v119);
    if (!consp(v119)) goto v123;
    v119 = v120;
    stack[0] = v119;
    goto v124;

v124:
    v120 = qvalue(elt(env, 2)); /* !:bprec!: */
    v119 = (Lisp_Object)49; /* 3 */
    v119 = difference2(v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    fn = elt(env, 6); /* round!:mt */
    v119 = (*qfn2(fn))(qenv(fn), stack[0], v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    fn = elt(env, 7); /* csl_normbf */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    fn = elt(env, 8); /* bfexplode0 */
    stack[0] = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v120 = elt(env, 1); /* !:rd!: */
    v119 = stack[-1];
    v119 = qcdr(v119);
    v119 = qcdr(v119);
    v119 = cons(v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v120 = v119;
    v119 = v120;
    v119 = qcdr(v119);
    if (!consp(v119)) goto v125;
    v119 = v120;
    stack[-1] = v119;
    goto v126;

v126:
    v120 = qvalue(elt(env, 2)); /* !:bprec!: */
    v119 = (Lisp_Object)49; /* 3 */
    v119 = difference2(v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    fn = elt(env, 6); /* round!:mt */
    v119 = (*qfn2(fn))(qenv(fn), stack[-1], v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    fn = elt(env, 7); /* csl_normbf */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    fn = elt(env, 8); /* bfexplode0 */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v119 = cons(stack[0], v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    stack[-1] = v119;
    stack[-4] = (Lisp_Object)193; /* 12 */
    v119 = stack[-1];
    v119 = qcar(v119);
    v119 = qcar(v119);
    stack[-3] = Llength(nil, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v119 = stack[-1];
    v119 = qcar(v119);
    v119 = qcdr(v119);
    v119 = Lexplode(nil, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    stack[-2] = Llength(nil, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v119 = stack[-1];
    v119 = qcdr(v119);
    v119 = qcar(v119);
    stack[0] = Llength(nil, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v119 = stack[-1];
    v119 = qcdr(v119);
    v119 = qcdr(v119);
    v119 = Lexplode(nil, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v119 = Llength(nil, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v119 = plus2(stack[0], v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v119 = plus2(stack[-2], v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v119 = plus2(stack[-3], v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    {
        Lisp_Object v127 = stack[-4];
        popv(7);
        return plus2(v127, v119);
    }

v125:
    v119 = v120;
    v119 = qcdr(v119);
    fn = elt(env, 9); /* fl2bf */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    stack[-1] = v119;
    goto v126;

v123:
    v119 = v120;
    v119 = qcdr(v119);
    fn = elt(env, 9); /* fl2bf */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    stack[0] = v119;
    goto v124;

v122:
    v119 = stack[-1];
    stack[-5] = Llength(nil, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    stack[-4] = elt(env, 4); /* plus */
    v119 = stack[-1];
    v119 = qcdr(v119);
    stack[-3] = v119;
    v119 = stack[-3];
    if (v119 == nil) goto v128;
    v119 = stack[-3];
    v119 = qcar(v119);
    v119 = CC_numprintlen(env, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v119 = ncons(v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    stack[-1] = v119;
    stack[-2] = v119;
    goto v129;

v129:
    v119 = stack[-3];
    v119 = qcdr(v119);
    stack[-3] = v119;
    v119 = stack[-3];
    if (v119 == nil) goto v130;
    stack[0] = stack[-1];
    v119 = stack[-3];
    v119 = qcar(v119);
    v119 = CC_numprintlen(env, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v119 = ncons(v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v119 = Lrplacd(nil, stack[0], v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v119 = stack[-1];
    v119 = qcdr(v119);
    stack[-1] = v119;
    goto v129;

v130:
    v119 = stack[-2];
    goto v131;

v131:
    v119 = cons(stack[-4], v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    fn = elt(env, 10); /* eval */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    {
        Lisp_Object v132 = stack[-5];
        popv(7);
        return plus2(v132, v119);
    }

v128:
    v119 = qvalue(elt(env, 5)); /* nil */
    goto v131;

v36:
    v119 = stack[-1];
    v119 = qcdr(v119);
    if (!consp(v119)) goto v133;
    v119 = stack[-1];
    stack[0] = v119;
    goto v8;

v8:
    v120 = qvalue(elt(env, 2)); /* !:bprec!: */
    v119 = (Lisp_Object)49; /* 3 */
    v119 = difference2(v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    fn = elt(env, 6); /* round!:mt */
    v119 = (*qfn2(fn))(qenv(fn), stack[0], v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    fn = elt(env, 7); /* csl_normbf */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    fn = elt(env, 8); /* bfexplode0 */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    stack[-1] = v119;
    stack[-2] = (Lisp_Object)33; /* 2 */
    v119 = stack[-1];
    v119 = qcar(v119);
    stack[0] = Llength(nil, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v119 = stack[-1];
    v119 = qcdr(v119);
    v119 = qcar(v119);
    v119 = Lexplode(nil, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v119 = Llength(nil, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    v119 = plus2(stack[0], v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    {
        Lisp_Object v134 = stack[-2];
        popv(7);
        return plus2(v134, v119);
    }

v133:
    v119 = stack[-1];
    v119 = qcdr(v119);
    fn = elt(env, 9); /* fl2bf */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-6];
    stack[0] = v119;
    goto v8;

v60:
    v119 = stack[-1];
    v119 = Lexplode(nil, v119);
    nil = C_nil;
    if (exception_pending()) goto v121;
        popv(7);
        return Llength(nil, v119);
/* error exit handlers */
v121:
    popv(7);
    return nil;
}



/* Code for lndepends */

static Lisp_Object CC_lndepends(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lndepends");
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

v136:
    v43 = stack[-1];
    if (v43 == nil) goto v19;
    v43 = stack[-1];
    v36 = qcar(v43);
    v43 = stack[0];
    fn = elt(env, 2); /* ndepends */
    v43 = (*qfn2(fn))(qenv(fn), v36, v43);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-2];
    if (!(v43 == nil)) { popv(3); return onevalue(v43); }
    v43 = stack[-1];
    v36 = qcdr(v43);
    v43 = stack[0];
    stack[-1] = v36;
    stack[0] = v43;
    goto v136;

v19:
    v43 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v43); }
/* error exit handlers */
v11:
    popv(3);
    return nil;
}



/* Code for listquotient */

static Lisp_Object CC_listquotient(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v137, v133, v47;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listquotient");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v133 = v1;
    v47 = v0;
/* end of prologue */
    v137 = v133;
    v46 = (Lisp_Object)17; /* 1 */
    if (v137 == v46) return onevalue(v47);
    v137 = v133;
    v46 = v47;
    if (equal(v137, v46)) goto v76;
    v46 = elt(env, 1); /* quotient */
    v137 = v47;
    return list3(v46, v137, v133);

v76:
    v46 = (Lisp_Object)17; /* 1 */
    return onevalue(v46);
}



/* Code for fs!:prin!: */

static Lisp_Object CC_fsTprinT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:prin:");
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
    v138 = elt(env, 1); /* "[" */
    fn = elt(env, 3); /* prin2!* */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-1];
    v138 = stack[0];
    v138 = qcdr(v138);
    fn = elt(env, 4); /* fs!:prin */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-1];
    v138 = elt(env, 2); /* "]" */
    {
        popv(2);
        fn = elt(env, 3); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v138);
    }
/* error exit handlers */
v28:
    popv(2);
    return nil;
}



/* Code for cl_pop */

static Lisp_Object CC_cl_pop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v70;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_pop");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v70 = v0;
/* end of prologue */
    return onevalue(v70);
}



/* Code for simpexpt2 */

static Lisp_Object MS_CDECL CC_simpexpt2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v239, v240, v241;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "simpexpt2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpt2");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v38;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v136:
    stack[0] = nil;
    v240 = stack[-3];
    v239 = (Lisp_Object)17; /* 1 */
    if (v240 == v239) goto v135;
    v239 = stack[-2];
    v239 = qcar(v239);
    stack[-4] = v239;
    v239 = stack[-3];
    v239 = Lconsp(nil, v239);
    env = stack[-5];
    if (v239 == nil) goto v42;
    v239 = stack[-3];
    v240 = qcar(v239);
    v239 = elt(env, 1); /* expt */
    if (v240 == v239) goto v71;
    v239 = qvalue(elt(env, 3)); /* nil */
    goto v47;

v47:
    if (v239 == nil) goto v112;
    v239 = stack[-3];
    v239 = qcdr(v239);
    v239 = qcdr(v239);
    v239 = qcar(v239);
    fn = elt(env, 16); /* simp */
    v240 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    stack[-4] = v240;
    v239 = stack[-2];
    fn = elt(env, 17); /* multsq */
    v239 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    stack[-2] = v239;
    v239 = qvalue(elt(env, 4)); /* !*precise */
    if (v239 == nil) goto v86;
    v239 = stack[-4];
    v239 = qcar(v239);
    if (!(is_number(v239))) goto v86;
    v239 = stack[-4];
    v239 = qcar(v239);
    v239 = Levenp(nil, v239);
    env = stack[-5];
    if (v239 == nil) goto v86;
    v240 = elt(env, 5); /* abs */
    v239 = stack[-3];
    v239 = qcdr(v239);
    v239 = qcar(v239);
    v239 = list2(v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    stack[-3] = v239;
    goto v243;

v243:
    v241 = stack[-3];
    v240 = stack[-2];
    v239 = stack[-1];
    {
        popv(6);
        fn = elt(env, 18); /* simpexpt1 */
        return (*qfnn(fn))(qenv(fn), 3, v241, v240, v239);
    }

v86:
    v239 = stack[-3];
    v239 = qcdr(v239);
    v239 = qcar(v239);
    stack[-3] = v239;
    goto v243;

v112:
    v239 = stack[-3];
    v240 = qcar(v239);
    v239 = elt(env, 6); /* sqrt */
    if (v240 == v239) goto v244;
    v239 = qvalue(elt(env, 3)); /* nil */
    goto v245;

v245:
    if (v239 == nil) goto v246;
    v239 = stack[-3];
    v239 = qcdr(v239);
    stack[0] = qcar(v239);
    v240 = (Lisp_Object)17; /* 1 */
    v239 = (Lisp_Object)33; /* 2 */
    v240 = cons(v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v239 = stack[-2];
    fn = elt(env, 17); /* multsq */
    v240 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v239 = stack[-1];
    stack[-3] = stack[0];
    stack[-2] = v240;
    stack[-1] = v239;
    goto v136;

v246:
    v239 = stack[-3];
    v240 = qcar(v239);
    v239 = elt(env, 8); /* times */
    if (v240 == v239) goto v247;
    v239 = qvalue(elt(env, 3)); /* nil */
    goto v248;

v248:
    if (v239 == nil) goto v249;
    v240 = (Lisp_Object)17; /* 1 */
    v239 = (Lisp_Object)17; /* 1 */
    v239 = cons(v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    stack[-4] = v239;
    v239 = stack[-3];
    v239 = qcdr(v239);
    stack[0] = v239;
    goto v250;

v250:
    v239 = stack[0];
    if (v239 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v239 = stack[0];
    v239 = qcar(v239);
    v241 = v239;
    v240 = stack[-2];
    v239 = stack[-1];
    fn = elt(env, 18); /* simpexpt1 */
    v240 = (*qfnn(fn))(qenv(fn), 3, v241, v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v239 = stack[-4];
    fn = elt(env, 17); /* multsq */
    v239 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    stack[-4] = v239;
    v239 = stack[0];
    v239 = qcdr(v239);
    stack[0] = v239;
    goto v250;

v249:
    v239 = stack[-3];
    v240 = qcar(v239);
    v239 = elt(env, 8); /* times */
    if (v240 == v239) goto v251;
    v239 = qvalue(elt(env, 3)); /* nil */
    goto v252;

v252:
    if (v239 == nil) goto v253;
    v239 = stack[0];
    v239 = qcdr(v239);
    v240 = qcar(v239);
    v239 = stack[0];
    v239 = qcdr(v239);
    v239 = qcdr(v239);
    v239 = Lappend(nil, v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    fn = elt(env, 19); /* retimes */
    v241 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v240 = stack[-2];
    v239 = stack[-1];
    fn = elt(env, 18); /* simpexpt1 */
    v239 = (*qfnn(fn))(qenv(fn), 3, v241, v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    stack[-4] = v239;
    v239 = stack[0];
    v239 = qcar(v239);
    stack[0] = v239;
    goto v254;

v254:
    v239 = stack[0];
    if (v239 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v239 = stack[0];
    v239 = qcar(v239);
    v241 = v239;
    v240 = stack[-2];
    v239 = stack[-1];
    fn = elt(env, 18); /* simpexpt1 */
    v240 = (*qfnn(fn))(qenv(fn), 3, v241, v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v239 = stack[-4];
    fn = elt(env, 17); /* multsq */
    v239 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    stack[-4] = v239;
    v239 = stack[0];
    v239 = qcdr(v239);
    stack[0] = v239;
    goto v254;

v253:
    v239 = stack[-3];
    v240 = qcar(v239);
    v239 = elt(env, 9); /* quotient */
    if (v240 == v239) goto v255;
    v239 = qvalue(elt(env, 3)); /* nil */
    goto v256;

v256:
    if (v239 == nil) goto v257;
    v239 = stack[-1];
    if (v239 == nil) goto v258;
    v239 = qvalue(elt(env, 3)); /* nil */
    goto v259;

v259:
    if (v239 == nil) goto v260;
    v239 = stack[-3];
    fn = elt(env, 20); /* simp!* */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v240 = v239;
    v239 = v240;
    v239 = qcar(v239);
    if (v239 == nil) goto v261;
    v239 = elt(env, 11); /* prepf */
    fn = elt(env, 21); /* sqform */
    v239 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v241 = v239;
    goto v262;

v262:
    v240 = stack[-2];
    v239 = qvalue(elt(env, 10)); /* t */
    {
        popv(6);
        fn = elt(env, 18); /* simpexpt1 */
        return (*qfnn(fn))(qenv(fn), 3, v241, v240, v239);
    }

v261:
    v239 = (Lisp_Object)1; /* 0 */
    v241 = v239;
    goto v262;

v260:
    v239 = stack[-2];
    v239 = qcar(v239);
    if (v239 == nil) goto v263;
    v240 = stack[-2];
    v239 = elt(env, 11); /* prepf */
    fn = elt(env, 21); /* sqform */
    v239 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    goto v264;

v264:
    stack[-2] = v239;
    v239 = stack[-3];
    v239 = qcdr(v239);
    v240 = qcar(v239);
    v239 = stack[-2];
    v239 = list2(v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    fn = elt(env, 22); /* simpexpt */
    stack[0] = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v239 = stack[-3];
    v239 = qcdr(v239);
    v239 = qcdr(v239);
    v240 = qcar(v239);
    v239 = stack[-2];
    v239 = list2(v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    fn = elt(env, 22); /* simpexpt */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    fn = elt(env, 23); /* invsq */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    {
        Lisp_Object v265 = stack[0];
        popv(6);
        fn = elt(env, 17); /* multsq */
        return (*qfn2(fn))(qenv(fn), v265, v239);
    }

v263:
    v239 = (Lisp_Object)1; /* 0 */
    goto v264;

v258:
    v239 = qvalue(elt(env, 12)); /* !*mcd */
    goto v259;

v257:
    v239 = stack[-3];
    v240 = qcar(v239);
    v239 = elt(env, 13); /* minus */
    if (v240 == v239) goto v266;
    v239 = qvalue(elt(env, 3)); /* nil */
    goto v267;

v267:
    if (v239 == nil) goto v42;
    v239 = stack[-2];
    v239 = qcar(v239);
    if (v239 == nil) goto v268;
    v240 = stack[-2];
    v239 = elt(env, 11); /* prepf */
    fn = elt(env, 21); /* sqform */
    v239 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    goto v269;

v269:
    stack[-1] = v239;
    v240 = (Lisp_Object)-15; /* -1 */
    v239 = stack[-1];
    v239 = list2(v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    fn = elt(env, 22); /* simpexpt */
    stack[0] = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v239 = stack[-3];
    v239 = qcdr(v239);
    v240 = qcar(v239);
    v239 = stack[-1];
    v239 = list2(v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    fn = elt(env, 22); /* simpexpt */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    {
        Lisp_Object v270 = stack[0];
        popv(6);
        fn = elt(env, 17); /* multsq */
        return (*qfn2(fn))(qenv(fn), v270, v239);
    }

v268:
    v239 = (Lisp_Object)1; /* 0 */
    goto v269;

v42:
    v239 = stack[-1];
    if (v239 == nil) goto v271;
    v239 = stack[-3];
    if (!(is_number(v239))) goto v272;
    v239 = stack[-3];
    v239 = (Lisp_Object)zerop(v239);
    v239 = v239 ? lisp_true : nil;
    env = stack[-5];
    if (v239 == nil) goto v272;
    v240 = qvalue(elt(env, 3)); /* nil */
    v239 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v240, v239);

v272:
    v239 = stack[-4];
    if (is_number(v239)) goto v273;
    v239 = stack[-4];
    fn = elt(env, 11); /* prepf */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    stack[-4] = v239;
    goto v273;

v273:
    v239 = stack[-2];
    v239 = qcdr(v239);
    fn = elt(env, 11); /* prepf */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    stack[-2] = v239;
    v240 = stack[-4];
    v239 = qvalue(elt(env, 15)); /* frlis!* */
    v239 = Lmemq(nil, v240, v239);
    if (v239 == nil) goto v274;
    v240 = stack[-2];
    v239 = (Lisp_Object)17; /* 1 */
    if (!(v240 == v239)) goto v274;
    v241 = stack[-3];
    v240 = stack[-4];
    v239 = (Lisp_Object)17; /* 1 */
    v239 = acons(v241, v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v240 = ncons(v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    v239 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v240, v239);

v274:
    v239 = qvalue(elt(env, 12)); /* !*mcd */
    if (!(v239 == nil)) goto v275;
    v239 = stack[-4];
    if (is_number(v239)) goto v276;
    v239 = qvalue(elt(env, 10)); /* t */
    goto v277;

v277:
    if (!(v239 == nil)) goto v275;
    v240 = stack[-3];
    v239 = stack[-4];
    {
        popv(6);
        fn = elt(env, 24); /* mksq */
        return (*qfn2(fn))(qenv(fn), v240, v239);
    }

v275:
    v241 = stack[-3];
    v240 = stack[-4];
    v239 = stack[-2];
    {
        popv(6);
        fn = elt(env, 25); /* simpx1 */
        return (*qfnn(fn))(qenv(fn), 3, v241, v240, v239);
    }

v276:
    v240 = stack[-2];
    v239 = (Lisp_Object)17; /* 1 */
    if (v240 == v239) goto v278;
    v239 = qvalue(elt(env, 10)); /* t */
    goto v277;

v278:
    v239 = stack[-3];
    if (!consp(v239)) goto v279;
    v239 = stack[-3];
    fn = elt(env, 20); /* simp!* */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v240 = qcdr(v239);
    v239 = (Lisp_Object)17; /* 1 */
    v239 = Lneq(nil, v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    goto v277;

v279:
    v239 = qvalue(elt(env, 10)); /* t */
    goto v277;

v271:
    v239 = qvalue(elt(env, 14)); /* dmode!* */
    if (v239 == nil) goto v280;
    v239 = stack[-3];
    if (!(symbolp(v239))) goto v280;
    v240 = stack[-3];
    v239 = qvalue(elt(env, 14)); /* dmode!* */
    v239 = get(v240, v239);
    env = stack[-5];
    if (!(v239 == nil)) goto v281;

v280:
    v239 = stack[-3];
    fn = elt(env, 20); /* simp!* */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v240 = v239;
    v239 = v240;
    v239 = qcar(v239);
    if (v239 == nil) goto v282;
    v239 = elt(env, 11); /* prepf */
    fn = elt(env, 21); /* sqform */
    v239 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    goto v283;

v283:
    stack[-3] = v239;
    goto v281;

v281:
    v241 = stack[-3];
    v240 = stack[-2];
    v239 = qvalue(elt(env, 10)); /* t */
    {
        popv(6);
        fn = elt(env, 18); /* simpexpt1 */
        return (*qfnn(fn))(qenv(fn), 3, v241, v240, v239);
    }

v282:
    v239 = (Lisp_Object)1; /* 0 */
    goto v283;

v266:
    v239 = qvalue(elt(env, 4)); /* !*precise */
    if (v239 == nil) goto v284;
    v239 = qvalue(elt(env, 3)); /* nil */
    goto v267;

v284:
    v239 = stack[-3];
    v239 = qcdr(v239);
    v240 = qcar(v239);
    v239 = (Lisp_Object)17; /* 1 */
    v239 = (v240 == v239 ? lisp_true : nil);
    v239 = (v239 == nil ? lisp_true : nil);
    goto v267;

v255:
    v239 = qvalue(elt(env, 4)); /* !*precise */
    if (v239 == nil) goto v285;
    v239 = stack[-3];
    v239 = qcdr(v239);
    v239 = qcdr(v239);
    v239 = qcar(v239);
    fn = elt(env, 26); /* posnump */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    if (v239 == nil) goto v286;
    v239 = stack[-2];
    v239 = qcar(v239);
    if (v239 == nil) goto v287;
    v240 = stack[-2];
    v239 = elt(env, 11); /* prepf */
    fn = elt(env, 21); /* sqform */
    v239 = (*qfn2(fn))(qenv(fn), v240, v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    goto v288;

v288:
    fn = elt(env, 26); /* posnump */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    goto v256;

v287:
    v239 = (Lisp_Object)1; /* 0 */
    goto v288;

v286:
    v239 = qvalue(elt(env, 3)); /* nil */
    goto v256;

v285:
    v239 = qvalue(elt(env, 10)); /* t */
    goto v256;

v251:
    v239 = stack[-3];
    v239 = qcdr(v239);
    fn = elt(env, 27); /* split!-sign */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    stack[0] = v239;
    if (v239 == nil) goto v89;
    v239 = stack[0];
    v239 = qcar(v239);
    goto v252;

v89:
    v239 = qvalue(elt(env, 3)); /* nil */
    goto v252;

v247:
    v239 = qvalue(elt(env, 4)); /* !*precise */
    v239 = (v239 == nil ? lisp_true : nil);
    goto v248;

v244:
    v239 = qvalue(elt(env, 7)); /* !*keepsqrts */
    v239 = (v239 == nil ? lisp_true : nil);
    goto v245;

v71:
    v239 = qvalue(elt(env, 2)); /* !*precise_complex */
    v239 = (v239 == nil ? lisp_true : nil);
    goto v47;

v135:
    v240 = (Lisp_Object)17; /* 1 */
    v239 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v240, v239);
/* error exit handlers */
v242:
    popv(6);
    return nil;
}



/* Code for cgp_greenp */

static Lisp_Object CC_cgp_greenp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_greenp");
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
    v19 = v0;
/* end of prologue */
    fn = elt(env, 1); /* cgp_rp */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    errexit();
    v19 = (v19 == nil ? lisp_true : nil);
    return onevalue(v19);
}



/* Code for transposerd */

static Lisp_Object MS_CDECL CC_transposerd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "transposerd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for transposerd");
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
    v32 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-1];
    v45 = elt(env, 1); /* tp */
    v32 = list2(v45, v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-1];
    fn = elt(env, 3); /* aeval */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-1];
    stack[0] = v32;
    fn = elt(env, 4); /* lex */
    v32 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v29;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v29:
    popv(2);
    return nil;
}



/* Code for spmatlength */

static Lisp_Object CC_spmatlength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v289, v290, v291, v292;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spmatlength");
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
    v291 = v0;
/* end of prologue */
    v289 = v291;
    v289 = Lconsp(nil, v289);
    env = stack[0];
    if (v289 == nil) goto v20;
    v289 = v291;
    goto v60;

v60:
    v290 = v289;
    v290 = qcdr(v290);
    v290 = qcdr(v290);
    v290 = qcar(v290);
    v290 = qcdr(v290);
    v292 = v290;
    v290 = v289;
    v289 = elt(env, 2); /* sparsemat */
    if (!consp(v290)) goto v80;
    v290 = qcar(v290);
    if (!(v290 == v289)) goto v80;
    v290 = elt(env, 7); /* list */
    v289 = v292;
    v289 = qcar(v289);
    v291 = v292;
    v291 = qcdr(v291);
    v291 = qcar(v291);
    popv(1);
    return list3(v290, v289, v291);

v80:
    v290 = elt(env, 3); /* "Matrix" */
    v289 = elt(env, 4); /* "not set" */
    v289 = list3(v290, v291, v289);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[0];
    v290 = v289;
    v289 = v290;
    qvalue(elt(env, 5)) = v289; /* errmsg!* */
    v289 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v289 == nil)) goto v294;
    v289 = v290;
    fn = elt(env, 8); /* lprie */
    v289 = (*qfn1(fn))(qenv(fn), v289);
    nil = C_nil;
    if (exception_pending()) goto v293;
    env = stack[0];
    goto v294;

v294:
    v289 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v293;
    v289 = nil;
    { popv(1); return onevalue(v289); }

v20:
    v290 = v291;
    v289 = elt(env, 1); /* avalue */
    v289 = get(v290, v289);
    env = stack[0];
    v289 = qcdr(v289);
    v289 = qcar(v289);
    goto v60;
/* error exit handlers */
v293:
    popv(1);
    return nil;
}



/* Code for tp1 */

static Lisp_Object CC_tp1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v295, v51;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tp1");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0;
/* end of prologue */
    v295 = qvalue(elt(env, 1)); /* nil */
    v295 = ncons(v295);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-6];
    stack[-3] = v295;
    stack[-5] = v295;
    goto v15;

v15:
    v295 = stack[-4];
    v295 = qcar(v295);
    if (v295 == nil) goto v14;
    v295 = stack[-4];
    stack[-2] = v295;
    v295 = qvalue(elt(env, 1)); /* nil */
    v295 = ncons(v295);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-6];
    stack[0] = v295;
    stack[-1] = v295;
    goto v30;

v30:
    v295 = stack[-2];
    if (v295 == nil) goto v118;
    v295 = stack[-2];
    v295 = qcar(v295);
    v295 = qcar(v295);
    v295 = ncons(v295);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-6];
    v295 = Lrplacd(nil, stack[0], v295);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-6];
    v295 = qcdr(v295);
    stack[0] = v295;
    v51 = stack[-2];
    v295 = stack[-2];
    v295 = qcar(v295);
    v295 = qcdr(v295);
    v295 = Lrplaca(nil, v51, v295);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-6];
    v295 = qcdr(v295);
    stack[-2] = v295;
    goto v30;

v118:
    stack[0] = stack[-3];
    v295 = stack[-1];
    v295 = qcdr(v295);
    v295 = ncons(v295);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-6];
    v295 = Lrplacd(nil, stack[0], v295);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-6];
    v295 = qcdr(v295);
    stack[-3] = v295;
    goto v15;

v14:
    v295 = stack[-5];
    v295 = qcdr(v295);
    { popv(7); return onevalue(v295); }
/* error exit handlers */
v27:
    popv(7);
    return nil;
}



/* Code for xregister_wedge_pair */

static Lisp_Object MS_CDECL CC_xregister_wedge_pair(Lisp_Object env, int nargs, ...)
{
    Lisp_Object v38;
    argcheck(nargs, 0, "xregister_wedge_pair");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xregister_wedge_pair");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v38 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v38);
}



/* Code for applysetop */

static Lisp_Object CC_applysetop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v321, v322, v323;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for applysetop");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v322 = v1;
    stack[-6] = v0;
/* end of prologue */
    stack[-5] = nil;
    v321 = (Lisp_Object)1; /* 0 */
    stack[-7] = v321;
    v321 = v322;
    stack[-4] = v321;
    v321 = stack[-4];
    if (v321 == nil) goto v45;
    v321 = stack[-4];
    v321 = qcar(v321);
    stack[0] = v321;
    v321 = stack[0];
    fn = elt(env, 6); /* reval */
    v322 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-8];
    stack[0] = v322;
    v321 = elt(env, 2); /* list */
    if (!consp(v322)) goto v34;
    v322 = qcar(v322);
    if (!(v322 == v321)) goto v34;
    v321 = stack[0];
    v321 = qcdr(v321);
    fn = elt(env, 7); /* delete!-dups */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-8];
    stack[0] = v321;
    v322 = stack[-7];
    v321 = (Lisp_Object)1; /* 0 */
    if (v322 == v321) goto v22;
    v323 = stack[-6];
    v322 = stack[-7];
    v321 = stack[0];
    v321 = Lapply2(nil, 3, v323, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-8];
    goto v80;

v80:
    stack[-7] = v321;
    v321 = stack[0];
    fn = elt(env, 8); /* make!-set */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-8];
    goto v56;

v56:
    v321 = ncons(v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-8];
    stack[-2] = v321;
    stack[-3] = v321;
    goto v39;

v39:
    v321 = stack[-4];
    v321 = qcdr(v321);
    stack[-4] = v321;
    v321 = stack[-4];
    if (v321 == nil) goto v235;
    stack[-1] = stack[-2];
    v321 = stack[-4];
    v321 = qcar(v321);
    stack[0] = v321;
    v321 = stack[0];
    fn = elt(env, 6); /* reval */
    v322 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-8];
    stack[0] = v322;
    v321 = elt(env, 2); /* list */
    if (!consp(v322)) goto v325;
    v322 = qcar(v322);
    if (!(v322 == v321)) goto v325;
    v321 = stack[0];
    v321 = qcdr(v321);
    fn = elt(env, 7); /* delete!-dups */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-8];
    stack[0] = v321;
    v322 = stack[-7];
    v321 = (Lisp_Object)1; /* 0 */
    if (v322 == v321) goto v326;
    v323 = stack[-6];
    v322 = stack[-7];
    v321 = stack[0];
    v321 = Lapply2(nil, 3, v323, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-8];
    goto v105;

v105:
    stack[-7] = v321;
    v321 = stack[0];
    fn = elt(env, 8); /* make!-set */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-8];
    goto v238;

v238:
    v321 = ncons(v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-8];
    v321 = Lrplacd(nil, stack[-1], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-8];
    v321 = stack[-2];
    v321 = qcdr(v321);
    stack[-2] = v321;
    goto v39;

v326:
    v321 = stack[0];
    goto v105;

v325:
    v321 = stack[0];
    if (symbolp(v321)) goto v101;
    v321 = stack[0];
    v321 = Lconsp(nil, v321);
    env = stack[-8];
    if (v321 == nil) goto v251;
    v321 = stack[0];
    v322 = qcar(v321);
    v321 = elt(env, 3); /* setvalued */
    v321 = Lflagp(nil, v322, v321);
    env = stack[-8];
    if (!(v321 == nil)) goto v101;

v251:
    v322 = stack[0];
    v321 = elt(env, 4); /* "set" */
    fn = elt(env, 9); /* typerr */
    v321 = (*qfn2(fn))(qenv(fn), v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-8];
    goto v238;

v101:
    v322 = stack[0];
    v321 = stack[-5];
    v321 = Lmember(nil, v322, v321);
    if (!(v321 == nil)) goto v327;
    v322 = stack[0];
    v321 = stack[-5];
    v321 = cons(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-8];
    stack[-5] = v321;
    goto v327;

v327:
    v321 = stack[0];
    goto v238;

v235:
    v321 = stack[-3];
    goto v15;

v15:
    v323 = v321;
    v321 = stack[-5];
    if (v321 == nil) goto v328;
    stack[0] = stack[-6];
    v322 = stack[-6];
    v321 = elt(env, 5); /* setdiff */
    if (v322 == v321) goto v128;
    v322 = stack[-7];
    v321 = (Lisp_Object)1; /* 0 */
    if (v322 == v321) goto v218;
    v321 = stack[-7];
    fn = elt(env, 8); /* make!-set */
    v322 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-8];
    v321 = stack[-5];
    v321 = cons(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    goto v129;

v129:
    {
        Lisp_Object v329 = stack[0];
        popv(9);
        return cons(v329, v321);
    }

v218:
    v321 = stack[-5];
    goto v129;

v128:
    v321 = v323;
    goto v129;

v328:
    v321 = stack[-7];
    fn = elt(env, 8); /* make!-set */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-8];
    {
        popv(9);
        fn = elt(env, 10); /* aeval */
        return (*qfn1(fn))(qenv(fn), v321);
    }

v22:
    v321 = stack[0];
    goto v80;

v34:
    v321 = stack[0];
    if (symbolp(v321)) goto v57;
    v321 = stack[0];
    v321 = Lconsp(nil, v321);
    env = stack[-8];
    if (v321 == nil) goto v234;
    v321 = stack[0];
    v322 = qcar(v321);
    v321 = elt(env, 3); /* setvalued */
    v321 = Lflagp(nil, v322, v321);
    env = stack[-8];
    if (!(v321 == nil)) goto v57;

v234:
    v322 = stack[0];
    v321 = elt(env, 4); /* "set" */
    fn = elt(env, 9); /* typerr */
    v321 = (*qfn2(fn))(qenv(fn), v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-8];
    goto v56;

v57:
    v322 = stack[0];
    v321 = stack[-5];
    v321 = Lmember(nil, v322, v321);
    if (!(v321 == nil)) goto v116;
    v322 = stack[0];
    v321 = stack[-5];
    v321 = cons(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-8];
    stack[-5] = v321;
    goto v116;

v116:
    v321 = stack[0];
    goto v56;

v45:
    v321 = qvalue(elt(env, 1)); /* nil */
    goto v15;
/* error exit handlers */
v324:
    popv(9);
    return nil;
}



/* Code for unshift */

static Lisp_Object CC_unshift(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v117, v74, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unshift");
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
    v24 = v0;
/* end of prologue */
    v7 = qvalue(elt(env, 1)); /* !*xo */
    v74 = v7;
    v7 = v74;
    v7 = qcar(v7);
    if (!consp(v7)) goto v22;
    v7 = v74;
    v7 = qcar(v7);
    v7 = qcdr(v7);
    v117 = qcar(v7);
    v7 = (Lisp_Object)1; /* 0 */
    if (v117 == v7) goto v21;
    v7 = qvalue(elt(env, 2)); /* nil */
    goto v138;

v138:
    if (!(v7 == nil)) { popv(1); return onevalue(v24); }
    v117 = v24;
    v7 = qvalue(elt(env, 1)); /* !*xo */
    fn = elt(env, 4); /* gfplus */
    v7 = (*qfn2(fn))(qenv(fn), v117, v7);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 5); /* gfadjust */
        return (*qfn1(fn))(qenv(fn), v7);
    }

v21:
    v7 = v74;
    v7 = qcdr(v7);
    v7 = qcdr(v7);
    v117 = qcar(v7);
    v7 = (Lisp_Object)1; /* 0 */
    v7 = (v117 == v7 ? lisp_true : nil);
    goto v138;

v22:
    v117 = v74;
    v7 = elt(env, 3); /* (0.0 . 0.0) */
    v7 = (equal(v117, v7) ? lisp_true : nil);
    goto v138;
/* error exit handlers */
v75:
    popv(1);
    return nil;
}



/* Code for redassignp */

static Lisp_Object CC_redassignp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v12, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for redassignp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v13 = v0;
/* end of prologue */
    v12 = v13;
    v41 = elt(env, 1); /* setq */
    if (!consp(v12)) goto v33;
    v12 = qcar(v12);
    if (!(v12 == v41)) goto v33;
    v41 = v13;
    v41 = qcdr(v41);
    v41 = qcdr(v41);
    v41 = qcar(v41);
    {
        fn = elt(env, 3); /* redassign1p */
        return (*qfn1(fn))(qenv(fn), v41);
    }

v33:
    v41 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v41);
}



/* Code for defined_all_edge */

static Lisp_Object MS_CDECL CC_defined_all_edge(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v69, v332;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "defined_all_edge");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for defined_all_edge");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v38;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v60:
    v27 = stack[-2];
    if (v27 == nil) goto v317;
    v27 = stack[-2];
    v69 = qcar(v27);
    v27 = stack[0];
    fn = elt(env, 3); /* def_edge */
    v27 = (*qfn2(fn))(qenv(fn), v69, v27);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-4];
    if (v27 == nil) goto v6;
    v27 = stack[-2];
    v27 = qcar(v27);
    fn = elt(env, 4); /* p_def_edge */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-4];
    if (v27 == nil) goto v71;
    v27 = qvalue(elt(env, 2)); /* t */
    { popv(5); return onevalue(v27); }

v71:
    v69 = stack[-1];
    v27 = stack[-2];
    stack[0] = Lnconc(nil, v69, v27);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-4];
    v27 = stack[-2];
    v27 = qcar(v27);
    v27 = qcdr(v27);
    v332 = qcar(v27);
    v69 = qvalue(elt(env, 2)); /* t */
    v27 = qvalue(elt(env, 1)); /* nil */
    v27 = list2star(v332, v69, v27);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-4];
    {
        Lisp_Object v293 = stack[0];
        popv(5);
        fn = elt(env, 5); /* rep_edge_prop_ */
        return (*qfn2(fn))(qenv(fn), v293, v27);
    }

v6:
    v27 = stack[-2];
    v27 = qcdr(v27);
    stack[-3] = v27;
    v27 = stack[-2];
    v69 = qcar(v27);
    v27 = stack[-1];
    v27 = cons(v69, v27);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-4];
    stack[-1] = v27;
    v27 = stack[-3];
    stack[-2] = v27;
    goto v60;

v317:
    v27 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v27); }
/* error exit handlers */
v292:
    popv(5);
    return nil;
}



/* Code for quotexf!* */

static Lisp_Object CC_quotexfH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotexf*");
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
    stack[-3] = nil;
    goto v55;

v55:
    v133 = stack[-2];
    if (v133 == nil) goto v138;
    v133 = stack[-2];
    v133 = qcar(v133);
    stack[0] = qcar(v133);
    v133 = stack[-2];
    v133 = qcar(v133);
    v47 = qcdr(v133);
    v133 = stack[-1];
    fn = elt(env, 1); /* quotfexf!*1 */
    v47 = (*qfn2(fn))(qenv(fn), v47, v133);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    v133 = stack[-3];
    v133 = acons(stack[0], v47, v133);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    stack[-3] = v133;
    v133 = stack[-2];
    v133 = qcdr(v133);
    stack[-2] = v133;
    goto v55;

v138:
    v133 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v133);
    }
/* error exit handlers */
v54:
    popv(5);
    return nil;
}



/* Code for groeb!=crita */

static Lisp_Object CC_groebMcrita(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v317, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=crita");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v317 = v0;
/* end of prologue */
    v28 = v317;
    v317 = elt(env, 1); /* groeb!=testa */
    {
        fn = elt(env, 2); /* listminimize */
        return (*qfn2(fn))(qenv(fn), v28, v317);
    }
}



/* Code for comb */

static Lisp_Object CC_comb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v335, v234, v245;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comb");
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
    v234 = stack[-3];
    v335 = (Lisp_Object)1; /* 0 */
    if (v234 == v335) goto v28;
    v335 = stack[-4];
    v234 = Llength(nil, v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-6];
    v335 = stack[-3];
    v234 = difference2(v234, v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-6];
    stack[-2] = v234;
    v335 = (Lisp_Object)1; /* 0 */
    v335 = (Lisp_Object)lessp2(v234, v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    v335 = v335 ? lisp_true : nil;
    env = stack[-6];
    if (v335 == nil) goto v317;
    v335 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v335); }

v317:
    v335 = (Lisp_Object)17; /* 1 */
    stack[-1] = v335;
    goto v9;

v9:
    v234 = stack[-2];
    v335 = stack[-1];
    v335 = difference2(v234, v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-6];
    v335 = Lminusp(nil, v335);
    env = stack[-6];
    if (v335 == nil) goto v65;
    v234 = stack[-4];
    v335 = stack[-5];
    popv(7);
    return cons(v234, v335);

v65:
    v335 = stack[-4];
    stack[0] = qcdr(v335);
    v335 = stack[-3];
    v335 = sub1(v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-6];
    v335 = CC_comb(env, stack[0], v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-6];
    stack[0] = v335;
    goto v52;

v52:
    v335 = stack[0];
    if (v335 == nil) goto v337;
    v335 = stack[0];
    v335 = qcar(v335);
    v234 = stack[-4];
    v245 = qcar(v234);
    v234 = v335;
    v335 = stack[-5];
    v335 = acons(v245, v234, v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-6];
    stack[-5] = v335;
    v335 = stack[0];
    v335 = qcdr(v335);
    stack[0] = v335;
    goto v52;

v337:
    v335 = stack[-4];
    v335 = qcdr(v335);
    stack[-4] = v335;
    v335 = stack[-1];
    v335 = add1(v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-6];
    stack[-1] = v335;
    goto v9;

v28:
    v335 = qvalue(elt(env, 1)); /* nil */
    popv(7);
    return ncons(v335);
/* error exit handlers */
v336:
    popv(7);
    return nil;
}



/* Code for lto_insert */

static Lisp_Object CC_lto_insert(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v56, v21, v34;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_insert");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v56 = v1;
    v21 = v0;
/* end of prologue */
    v34 = v21;
    v30 = v56;
    v30 = Lmember(nil, v34, v30);
    if (!(v30 == nil)) return onevalue(v56);
    v30 = v21;
    return cons(v30, v56);
}



/* Code for !*invsq */

static Lisp_Object CC_Hinvsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *invsq");
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
    v76 = v0;
/* end of prologue */
    v39 = qvalue(elt(env, 1)); /* sqrtflag */
    if (v39 == nil) goto v317;
    v39 = v76;
    fn = elt(env, 2); /* invsq */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* sqrt2top */
        return (*qfn1(fn))(qenv(fn), v39);
    }

v317:
    v39 = v76;
    {
        popv(1);
        fn = elt(env, 2); /* invsq */
        return (*qfn1(fn))(qenv(fn), v39);
    }
/* error exit handlers */
v20:
    popv(1);
    return nil;
}



/* Code for pasf_fact */

static Lisp_Object CC_pasf_fact(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v344, v345, v250;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_fact");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
/* end of prologue */
    v345 = stack[-1];
    v344 = elt(env, 1); /* true */
    if (v345 == v344) goto v15;
    v345 = stack[-1];
    v344 = elt(env, 3); /* false */
    v344 = (v345 == v344 ? lisp_true : nil);
    goto v14;

v14:
    if (!(v344 == nil)) { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
    v344 = stack[-1];
    v344 = qcar(v344);
    stack[-5] = v344;
    v344 = stack[-1];
    v344 = qcdr(v344);
    v344 = qcar(v344);
    fn = elt(env, 10); /* fctrf */
    v344 = (*qfn1(fn))(qenv(fn), v344);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-6];
    stack[0] = v344;
    v344 = stack[0];
    v345 = Llength(nil, v344);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-6];
    v344 = (Lisp_Object)49; /* 3 */
    v344 = (Lisp_Object)lessp2(v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v346;
    v344 = v344 ? lisp_true : nil;
    env = stack[-6];
    if (!(v344 == nil)) { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
    v345 = stack[-5];
    v344 = elt(env, 4); /* (equal neq) */
    v344 = Lmemq(nil, v345, v344);
    if (v344 == nil) goto v105;
    v345 = stack[-5];
    v344 = elt(env, 5); /* equal */
    if (v345 == v344) goto v4;
    v344 = elt(env, 7); /* and */
    stack[-4] = v344;
    goto v295;

v295:
    v344 = stack[0];
    v344 = qcdr(v344);
    stack[-3] = v344;
    v344 = stack[-3];
    if (v344 == nil) goto v320;
    v344 = stack[-3];
    v344 = qcar(v344);
    v250 = stack[-5];
    v345 = qcar(v344);
    v344 = qvalue(elt(env, 8)); /* nil */
    v344 = list3(v250, v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-6];
    v344 = ncons(v344);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-6];
    stack[-1] = v344;
    stack[-2] = v344;
    goto v58;

v58:
    v344 = stack[-3];
    v344 = qcdr(v344);
    stack[-3] = v344;
    v344 = stack[-3];
    if (v344 == nil) goto v236;
    stack[0] = stack[-1];
    v344 = stack[-3];
    v344 = qcar(v344);
    v250 = stack[-5];
    v345 = qcar(v344);
    v344 = qvalue(elt(env, 8)); /* nil */
    v344 = list3(v250, v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-6];
    v344 = ncons(v344);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-6];
    v344 = Lrplacd(nil, stack[0], v344);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-6];
    v344 = stack[-1];
    v344 = qcdr(v344);
    stack[-1] = v344;
    goto v58;

v236:
    v344 = stack[-2];
    goto v51;

v51:
    {
        Lisp_Object v347 = stack[-4];
        popv(7);
        return cons(v347, v344);
    }

v320:
    v344 = qvalue(elt(env, 8)); /* nil */
    goto v51;

v4:
    v344 = elt(env, 6); /* or */
    stack[-4] = v344;
    goto v295;

v105:
    v345 = stack[-5];
    v344 = elt(env, 9); /* (leq lessp geq greaterp) */
    v344 = Lmemq(nil, v345, v344);
    if (v344 == nil) { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
    v344 = stack[0];
    stack[-1] = qcdr(v344);
    v344 = stack[0];
    v344 = qcar(v344);
    fn = elt(env, 11); /* minusf */
    v344 = (*qfn1(fn))(qenv(fn), v344);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-6];
    if (v344 == nil) goto v348;
    v344 = stack[-5];
    fn = elt(env, 12); /* pasf_anegrel */
    v344 = (*qfn1(fn))(qenv(fn), v344);
    nil = C_nil;
    if (exception_pending()) goto v346;
    env = stack[-6];
    goto v106;

v106:
    {
        Lisp_Object v349 = stack[-1];
        popv(7);
        fn = elt(env, 13); /* pasf_fact1 */
        return (*qfn2(fn))(qenv(fn), v349, v344);
    }

v348:
    v344 = stack[-5];
    goto v106;

v15:
    v344 = qvalue(elt(env, 2)); /* t */
    goto v14;
/* error exit handlers */
v346:
    popv(7);
    return nil;
}



/* Code for diffrd */

static Lisp_Object MS_CDECL CC_diffrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v53, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "diffrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diffrd");
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
    fn = elt(env, 4); /* lex */
    v22 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v53 = qvalue(elt(env, 1)); /* char */
    v22 = elt(env, 2); /* (b v a r) */
    if (equal(v53, v22)) goto v317;
    v22 = qvalue(elt(env, 3)); /* nil */
    stack[-2] = v22;
    v22 = qvalue(elt(env, 3)); /* nil */
    stack[-1] = v22;
    goto v138;

v138:
    fn = elt(env, 5); /* mathml2 */
    v22 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    stack[0] = v22;
    fn = elt(env, 4); /* lex */
    v22 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v54 = stack[0];
    v53 = stack[-2];
    v22 = stack[-1];
    {
        popv(4);
        fn = elt(env, 6); /* alg_df */
        return (*qfnn(fn))(qenv(fn), 3, v54, v53, v22);
    }

v317:
    fn = elt(env, 7); /* bvarrd */
    v22 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    stack[-2] = v22;
    v22 = stack[-2];
    v22 = qcdr(v22);
    v22 = qcar(v22);
    stack[-1] = v22;
    v22 = stack[-2];
    v22 = qcar(v22);
    stack[-2] = v22;
    fn = elt(env, 4); /* lex */
    v22 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    goto v138;
/* error exit handlers */
v73:
    popv(4);
    return nil;
}



/* Code for rewrite */

static Lisp_Object MS_CDECL CC_rewrite(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v38, Lisp_Object v70, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v359, v360, v254, v361;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "rewrite");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rewrite");
#endif
    if (stack >= stacklimit)
    {
        push4(v70,v38,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v38,v70);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-9] = v70;
    stack[-10] = v38;
    stack[-11] = v1;
    stack[-12] = v0;
/* end of prologue */
    v359 = (Lisp_Object)17; /* 1 */
    stack[-13] = v359;
    v359 = (Lisp_Object)17; /* 1 */
    stack[-2] = v359;
    v359 = stack[-12];
    v359 = qcdr(v359);
    v359 = qcdr(v359);
    v359 = qcar(v359);
    v360 = v359;
    v360 = qcdr(v360);
    v360 = qcar(v360);
    v359 = qcdr(v359);
    v359 = qcdr(v359);
    v359 = qcar(v359);
    if (equal(v360, v359)) goto v21;
    v359 = stack[-11];
    stack[-1] = v359;
    goto v56;

v56:
    v359 = (Lisp_Object)17; /* 1 */
    stack[0] = v359;
    goto v294;

v294:
    v360 = stack[-1];
    v359 = stack[0];
    v359 = difference2(v360, v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    v359 = Lminusp(nil, v359);
    env = stack[-14];
    if (v359 == nil) goto v24;
    v359 = stack[-11];
    v360 = add1(v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    v359 = stack[-12];
    v359 = qcdr(v359);
    v359 = qcdr(v359);
    v359 = qcar(v359);
    v359 = qcdr(v359);
    v359 = qcar(v359);
    if (!(equal(v360, v359))) { Lisp_Object res = stack[-12]; popv(15); return onevalue(res); }
    stack[0] = stack[-12];
    v359 = stack[-11];
    v359 = add1(v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    v361 = list2(stack[0], v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    v254 = qvalue(elt(env, 1)); /* nil */
    v360 = stack[-12];
    v359 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* letmtr3 */
    v359 = (*qfnn(fn))(qenv(fn), 4, v361, v254, v360, v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    { Lisp_Object res = stack[-12]; popv(15); return onevalue(res); }

v24:
    v360 = stack[-12];
    v359 = stack[0];
    fn = elt(env, 3); /* findrow */
    v359 = (*qfn2(fn))(qenv(fn), v360, v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    v360 = v359;
    v359 = v360;
    if (v359 == nil) goto v249;
    v359 = v360;
    v359 = qcdr(v359);
    stack[-7] = v359;
    v359 = stack[0];
    stack[-3] = v359;
    v360 = stack[-13];
    v359 = stack[-10];
    if (!(equal(v360, v359))) goto v243;
    v359 = stack[-13];
    v359 = add1(v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    stack[-13] = v359;
    goto v243;

v243:
    v360 = stack[-3];
    v359 = stack[-13];
    if (equal(v360, v359)) goto v320;
    v359 = stack[-13];
    v359 = add1(v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    stack[-13] = v359;
    v359 = stack[-2];
    v359 = add1(v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    stack[-2] = v359;
    goto v5;

v5:
    v359 = stack[0];
    v359 = add1(v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    stack[0] = v359;
    goto v294;

v320:
    v359 = (Lisp_Object)17; /* 1 */
    stack[-4] = v359;
    v359 = (Lisp_Object)17; /* 1 */
    stack[-8] = v359;
    v359 = qvalue(elt(env, 1)); /* nil */
    stack[-5] = v359;
    goto v234;

v234:
    v359 = stack[-7];
    if (v359 == nil) goto v347;
    stack[-3] = stack[-4];
    v359 = stack[-11];
    v359 = add1(v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    if (equal(stack[-3], v359)) goto v347;
    v359 = stack[-7];
    v359 = qcar(v359);
    v360 = v359;
    v359 = v360;
    v359 = qcar(v359);
    stack[-6] = v359;
    v359 = v360;
    v359 = qcdr(v359);
    stack[-3] = v359;
    v360 = stack[-4];
    v359 = stack[-9];
    if (!(equal(v360, v359))) goto v232;
    v359 = stack[-8];
    v359 = add1(v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    stack[-8] = v359;
    goto v232;

v232:
    v360 = stack[-6];
    v359 = stack[-8];
    if (equal(v360, v359)) goto v247;
    v359 = stack[-8];
    v359 = add1(v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    stack[-8] = v359;
    v359 = stack[-4];
    v359 = add1(v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    stack[-4] = v359;
    goto v234;

v247:
    v254 = stack[-4];
    v360 = stack[-3];
    v359 = stack[-5];
    v359 = acons(v254, v360, v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    stack[-5] = v359;
    v359 = stack[-4];
    v359 = add1(v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    stack[-4] = v359;
    v359 = stack[-7];
    v359 = qcdr(v359);
    stack[-7] = v359;
    v359 = stack[-8];
    v359 = add1(v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    stack[-8] = v359;
    goto v234;

v347:
    v360 = stack[-12];
    v359 = stack[-2];
    stack[-4] = list2(v360, v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    v359 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = ncons(v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    v359 = stack[-5];
    v359 = Lreverse(nil, v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    v254 = cons(stack[-3], v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    v360 = stack[-12];
    v359 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* letmtr3 */
    v359 = (*qfnn(fn))(qenv(fn), 4, stack[-4], v254, v360, v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    v359 = stack[-2];
    v359 = add1(v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    stack[-2] = v359;
    v359 = stack[-13];
    v359 = add1(v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    stack[-13] = v359;
    goto v5;

v249:
    v359 = stack[-13];
    v359 = add1(v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    stack[-13] = v359;
    goto v5;

v21:
    v359 = stack[-11];
    v359 = add1(v359);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-14];
    stack[-1] = v359;
    goto v56;
/* error exit handlers */
v134:
    popv(15);
    return nil;
}



/* Code for dm!-quotient */

static Lisp_Object CC_dmKquotient(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-quotient");
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
    v135 = v0;
/* end of prologue */
    v29 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 1)) = v29; /* !*noequiv */
    v29 = v135;
    fn = elt(env, 3); /* dm!-mkfloat */
    stack[-1] = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-2];
    v29 = stack[0];
    fn = elt(env, 3); /* dm!-mkfloat */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-2];
    fn = elt(env, 4); /* !:quotient */
    v29 = (*qfn2(fn))(qenv(fn), stack[-1], v29);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 5); /* nil2zero */
        return (*qfn1(fn))(qenv(fn), v29);
    }
/* error exit handlers */
v13:
    popv(3);
    return nil;
}



/* Code for evweightedcomp1 */

static Lisp_Object CC_evweightedcomp1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v76, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evweightedcomp1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v39 = v1;
    v76 = v0;
/* end of prologue */
    v20 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 1); /* evweightedcomp2 */
        return (*qfnn(fn))(qenv(fn), 3, v20, v76, v39);
    }
}



/* Code for evaluate2 */

static Lisp_Object MS_CDECL CC_evaluate2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v356, v327, v354;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evaluate2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate2");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v38;
    v327 = v1;
    stack[-4] = v0;
/* end of prologue */
    v354 = stack[-4];
    v356 = elt(env, 1); /* !:dn!: */
    if (v354 == v356) goto v55;
    v356 = v327;
    stack[-5] = v356;
    v356 = stack[-5];
    if (v356 == nil) goto v42;
    v356 = stack[-5];
    v356 = qcar(v356);
    v327 = v356;
    v356 = stack[-3];
    fn = elt(env, 6); /* evaluate1 */
    v356 = (*qfn2(fn))(qenv(fn), v327, v356);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-6];
    v356 = ncons(v356);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-6];
    stack[-1] = v356;
    stack[-2] = v356;
    goto v56;

v56:
    v356 = stack[-5];
    v356 = qcdr(v356);
    stack[-5] = v356;
    v356 = stack[-5];
    if (v356 == nil) goto v8;
    stack[0] = stack[-1];
    v356 = stack[-5];
    v356 = qcar(v356);
    v327 = v356;
    v356 = stack[-3];
    fn = elt(env, 6); /* evaluate1 */
    v356 = (*qfn2(fn))(qenv(fn), v327, v356);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-6];
    v356 = ncons(v356);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-6];
    v356 = Lrplacd(nil, stack[0], v356);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-6];
    v356 = stack[-1];
    v356 = qcdr(v356);
    stack[-1] = v356;
    goto v56;

v8:
    v356 = stack[-2];
    goto v30;

v30:
    v327 = v356;
    v354 = stack[-4];
    v356 = elt(env, 3); /* plus */
    if (v354 == v356) goto v69;
    v354 = stack[-4];
    v356 = elt(env, 4); /* times */
    if (v354 == v356) goto v25;
    v354 = stack[-4];
    v356 = qvalue(elt(env, 5)); /* dmarith!* */
    v356 = Lassoc(nil, v354, v356);
    v354 = v356;
    if (v356 == nil) goto v3;
    v356 = v354;
    v356 = qcdr(v356);
    {
        popv(7);
        fn = elt(env, 7); /* apply */
        return (*qfn2(fn))(qenv(fn), v356, v327);
    }

v3:
    v356 = v327;
    v356 = qcar(v356);
    v356 = Lconsp(nil, v356);
    env = stack[-6];
    if (v356 == nil) goto v232;
    v354 = stack[-4];
    v356 = v327;
    v356 = qcar(v356);
    v356 = qcar(v356);
    v356 = get(v354, v356);
    env = stack[-6];
    v354 = v356;
    if (v356 == nil) goto v232;
    v356 = v354;
    {
        popv(7);
        fn = elt(env, 7); /* apply */
        return (*qfn2(fn))(qenv(fn), v356, v327);
    }

v232:
    v356 = v327;
    stack[-3] = v356;
    v356 = stack[-3];
    if (v356 == nil) goto v366;
    v356 = stack[-3];
    v356 = qcar(v356);
    fn = elt(env, 8); /* prepf */
    v356 = (*qfn1(fn))(qenv(fn), v356);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-6];
    v356 = ncons(v356);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-6];
    stack[-1] = v356;
    stack[-2] = v356;
    goto v340;

v340:
    v356 = stack[-3];
    v356 = qcdr(v356);
    stack[-3] = v356;
    v356 = stack[-3];
    if (v356 == nil) goto v367;
    stack[0] = stack[-1];
    v356 = stack[-3];
    v356 = qcar(v356);
    fn = elt(env, 8); /* prepf */
    v356 = (*qfn1(fn))(qenv(fn), v356);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-6];
    v356 = ncons(v356);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-6];
    v356 = Lrplacd(nil, stack[0], v356);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-6];
    v356 = stack[-1];
    v356 = qcdr(v356);
    stack[-1] = v356;
    goto v340;

v367:
    v356 = stack[-2];
    goto v233;

v233:
    v356 = cons(stack[-4], v356);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-6];
    fn = elt(env, 9); /* simp */
    v356 = (*qfn1(fn))(qenv(fn), v356);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-6];
    v356 = qcar(v356);
    {
        popv(7);
        fn = elt(env, 10); /* force!-to!-dm */
        return (*qfn1(fn))(qenv(fn), v356);
    }

v366:
    v356 = qvalue(elt(env, 2)); /* nil */
    goto v233;

v25:
    v356 = v327;
    {
        popv(7);
        fn = elt(env, 11); /* !:dmtimeslst */
        return (*qfn1(fn))(qenv(fn), v356);
    }

v69:
    v356 = v327;
    {
        popv(7);
        fn = elt(env, 12); /* !:dmpluslst */
        return (*qfn1(fn))(qenv(fn), v356);
    }

v42:
    v356 = qvalue(elt(env, 2)); /* nil */
    goto v30;

v55:
    v356 = v327;
    fn = elt(env, 13); /* dn!:simp */
    v356 = (*qfn1(fn))(qenv(fn), v356);
    nil = C_nil;
    if (exception_pending()) goto v309;
    v356 = qcar(v356);
    { popv(7); return onevalue(v356); }
/* error exit handlers */
v309:
    popv(7);
    return nil;
}



/* Code for smemberl */

static Lisp_Object CC_smemberl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v331, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smemberl");
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
    goto v55;

v55:
    v331 = stack[-1];
    if (v331 == nil) goto v80;
    v331 = stack[0];
    if (v331 == nil) goto v80;
    v331 = stack[-1];
    v72 = qcar(v331);
    v331 = stack[0];
    fn = elt(env, 1); /* smember */
    v331 = (*qfn2(fn))(qenv(fn), v72, v331);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-3];
    if (v331 == nil) goto v137;
    v331 = stack[-1];
    v72 = qcar(v331);
    v331 = stack[-2];
    v331 = cons(v72, v331);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-3];
    stack[-2] = v331;
    v331 = stack[-1];
    v331 = qcdr(v331);
    stack[-1] = v331;
    goto v55;

v137:
    v331 = stack[-1];
    v331 = qcdr(v331);
    stack[-1] = v331;
    goto v55;

v80:
    v331 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v331);
    }
/* error exit handlers */
v9:
    popv(4);
    return nil;
}



/* Code for ev!-edgeloop */

static Lisp_Object CC_evKedgeloop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v135, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev-edgeloop");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v29 = v1;
    v135 = v0;
/* end of prologue */
    v41 = qvalue(elt(env, 1)); /* ndim!* */
    v135 = qcar(v135);
    v29 = Lassoc(nil, v135, v29);
    v29 = qcdr(v29);
    {
        fn = elt(env, 2); /* binc */
        return (*qfn2(fn))(qenv(fn), v41, v29);
    }
}



/* Code for mv!-compact */

static Lisp_Object MS_CDECL CC_mvKcompact(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v370, v232, v233;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mv-compact");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-compact");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v38;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v136:
    v370 = stack[-3];
    if (v370 == nil) goto v317;
    v232 = stack[-3];
    v370 = stack[-2];
    fn = elt(env, 2); /* mv!-pow!-chk */
    v370 = (*qfn2(fn))(qenv(fn), v232, v370);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-5];
    stack[-4] = v370;
    if (v370 == nil) goto v67;
    stack[0] = stack[-3];
    v232 = stack[-4];
    v370 = stack[-2];
    fn = elt(env, 3); /* mv!-pow!-mv!-!+ */
    v370 = (*qfn2(fn))(qenv(fn), v232, v370);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-5];
    fn = elt(env, 4); /* mv!-compact2 */
    v370 = (*qfn2(fn))(qenv(fn), stack[0], v370);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-5];
    stack[0] = v370;
    if (v370 == nil) goto v67;
    v233 = stack[0];
    v232 = stack[-2];
    v370 = stack[-1];
    stack[-3] = v233;
    stack[-2] = v232;
    stack[-1] = v370;
    goto v136;

v67:
    v232 = stack[-3];
    v370 = stack[-2];
    v370 = qcdr(v370);
    fn = elt(env, 2); /* mv!-pow!-chk */
    v370 = (*qfn2(fn))(qenv(fn), v232, v370);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-5];
    stack[-4] = v370;
    if (v370 == nil) goto v342;
    v232 = stack[-4];
    v370 = stack[-2];
    v370 = qcar(v370);
    v370 = qcar(v370);
    fn = elt(env, 5); /* mv!-pow!-!+ */
    v232 = (*qfn2(fn))(qenv(fn), v232, v370);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-5];
    stack[0] = v232;
    v370 = stack[-1];
    fn = elt(env, 6); /* mv!-pow!-assoc */
    v370 = (*qfn2(fn))(qenv(fn), v232, v370);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-5];
    if (v370 == nil) goto v319;
    v370 = qvalue(elt(env, 1)); /* nil */
    goto v295;

v295:
    if (v370 == nil) goto v342;
    v233 = stack[0];
    v232 = stack[-2];
    v370 = stack[-1];
    stack[-3] = v233;
    stack[-2] = v232;
    stack[-1] = v370;
    goto v136;

v342:
    v370 = stack[-3];
    stack[0] = qcdr(v370);
    v370 = stack[-3];
    v232 = qcar(v370);
    v370 = stack[-1];
    v370 = cons(v232, v370);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-5];
    stack[-3] = stack[0];
    stack[-1] = v370;
    goto v136;

v319:
    v233 = stack[0];
    v232 = (Lisp_Object)1; /* 0 */
    v370 = stack[-3];
    stack[0] = acons(v233, v232, v370);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-5];
    v232 = stack[-4];
    v370 = stack[-2];
    fn = elt(env, 3); /* mv!-pow!-mv!-!+ */
    v370 = (*qfn2(fn))(qenv(fn), v232, v370);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-5];
    fn = elt(env, 4); /* mv!-compact2 */
    v370 = (*qfn2(fn))(qenv(fn), stack[0], v370);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-5];
    stack[0] = v370;
    goto v295;

v317:
    v370 = stack[-1];
    {
        popv(6);
        fn = elt(env, 7); /* mv!-reverse */
        return (*qfn1(fn))(qenv(fn), v370);
    }
/* error exit handlers */
v248:
    popv(6);
    return nil;
}



/* Code for redall */

static Lisp_Object MS_CDECL CC_redall(Lisp_Object env, int nargs,
                         Lisp_Object v1, Lisp_Object v38,
                         Lisp_Object v70, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v219, v351, v377;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "redall");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for redall");
#endif
    if (stack >= stacklimit)
    {
        push3(v70,v38,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v1,v38,v70);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v70;
    v351 = v38;
    v219 = v1;
/* end of prologue */
    stack[-8] = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = nil; /* gg */
    qvalue(elt(env, 1)) = v219; /* gg */
    v219 = v351;
    stack[-6] = v219;
    v219 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v219; /* shortway */
    qvalue(elt(env, 4)) = v219; /* thirdway */
    v219 = qvalue(elt(env, 5)); /* t */
    stack[-1] = v219;
    goto v41;

v41:
    v219 = stack[-6];
    if (v219 == nil) goto v135;
    v219 = stack[-6];
    v219 = Lreverse(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    v219 = qcar(v219);
    stack[-5] = v219;
    v351 = stack[-5];
    v219 = stack[-6];
    v219 = Ldelete(nil, v351, v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    stack[-6] = v219;
    v219 = stack[-5];
    v219 = qcar(v219);
    stack[-2] = v219;
    v351 = qvalue(elt(env, 6)); /* gv */
    v219 = stack[-2];
    v219 = *(Lisp_Object *)((char *)v351 + (CELL-TAG_VECTOR) + ((int32_t)v219/(16/CELL)));
    stack[-4] = v219;
    v219 = qvalue(elt(env, 7)); /* path */
    if (v219 == nil) goto v5;
    v219 = stack[-1];
    if (v219 == nil) goto v74;
    v219 = stack[-4];
    fn = elt(env, 12); /* ljet */
    v219 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    v219 = Lprinc(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    v219 = elt(env, 8); /* " ==> " */
    v219 = Lprinc(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    goto v5;

v5:
    stack[-3] = qvalue(elt(env, 6)); /* gv */
    stack[0] = stack[-2];
    v377 = stack[-4];
    v351 = qvalue(elt(env, 1)); /* gg */
    v219 = stack[-7];
    fn = elt(env, 13); /* nf */
    v219 = (*qfnn(fn))(qenv(fn), 3, v377, v351, v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v219;
    stack[-5] = v219;
    v219 = stack[-5];
    if (v219 == nil) goto v115;
    v219 = stack[-5];
    fn = elt(env, 12); /* ljet */
    v219 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    goto v319;

v319:
    stack[-3] = v219;
    v219 = qvalue(elt(env, 7)); /* path */
    if (v219 == nil) goto v114;
    v219 = stack[-3];
    v219 = Lprinc(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    v219 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    goto v114;

v114:
    v219 = stack[-5];
    if (v219 == nil) goto v41;
    v219 = stack[-3];
    fn = elt(env, 14); /* ord */
    v351 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    v219 = (Lisp_Object)1; /* 0 */
    if (v351 == v219) goto v342;
    v219 = stack[-5];
    fn = elt(env, 12); /* ljet */
    stack[0] = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    v219 = stack[-4];
    fn = elt(env, 12); /* ljet */
    v219 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    if (equal(stack[0], v219)) goto v110;
    v219 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 3)) = v219; /* shortway */
    goto v110;

v110:
    v219 = stack[-1];
    if (v219 == nil) goto v366;
    v219 = qvalue(elt(env, 2)); /* nil */
    goto v247;

v247:
    if (v219 == nil) goto v326;
    v219 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 4)) = v219; /* thirdway */
    goto v326;

v326:
    v219 = qvalue(elt(env, 1)); /* gg */
    stack[-4] = v219;
    goto v367;

v367:
    v219 = stack[-4];
    if (v219 == nil) goto v302;
    v219 = stack[-4];
    v219 = qcar(v219);
    stack[-1] = v219;
    v351 = stack[-3];
    v219 = stack[-1];
    v219 = qcdr(v219);
    fn = elt(env, 15); /* dd */
    stack[0] = (*qfn2(fn))(qenv(fn), v351, v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    v351 = stack[-7];
    v219 = (Lisp_Object)33; /* 2 */
    v219 = plus2(v351, v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    v219 = (Lisp_Object)geq2(stack[0], v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    v219 = v219 ? lisp_true : nil;
    env = stack[-9];
    if (v219 == nil) goto v378;
    v351 = stack[-1];
    v219 = qvalue(elt(env, 1)); /* gg */
    v219 = Ldelete(nil, v351, v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    qvalue(elt(env, 1)) = v219; /* gg */
    v351 = stack[-1];
    v219 = stack[-6];
    fn = elt(env, 16); /* insert */
    v219 = (*qfn2(fn))(qenv(fn), v351, v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    stack[-6] = v219;
    v377 = qvalue(elt(env, 11)); /* bv */
    v219 = stack[-1];
    v351 = qcar(v219);
    v219 = qvalue(elt(env, 5)); /* t */
    *(Lisp_Object *)((char *)v377 + (CELL-TAG_VECTOR) + ((int32_t)v351/(16/CELL))) = v219;
    goto v378;

v378:
    v219 = stack[-4];
    v219 = qcdr(v219);
    stack[-4] = v219;
    goto v367;

v302:
    v351 = stack[-2];
    v219 = stack[-3];
    v351 = cons(v351, v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    v219 = qvalue(elt(env, 1)); /* gg */
    fn = elt(env, 16); /* insert */
    v219 = (*qfn2(fn))(qenv(fn), v351, v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    qvalue(elt(env, 1)) = v219; /* gg */
    v219 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v219;
    goto v41;

v366:
    v351 = stack[-5];
    v219 = stack[-4];
    v219 = Lneq(nil, v351, v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    goto v247;

v342:
    v351 = stack[-5];
    v219 = qvalue(elt(env, 10)); /* conds */
    v219 = cons(v351, v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    qvalue(elt(env, 10)) = v219; /* conds */
    goto v41;

v115:
    v219 = (Lisp_Object)1; /* 0 */
    goto v319;

v74:
    v219 = stack[-4];
    fn = elt(env, 12); /* ljet */
    v219 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    v219 = Lprinc(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    v219 = elt(env, 9); /* " --> " */
    v219 = Lprinc(nil, v219);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-9];
    goto v5;

v135:
    v219 = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = stack[-8]; /* gg */
    { popv(10); return onevalue(v219); }
/* error exit handlers */
v328:
    env = stack[-9];
    qvalue(elt(env, 1)) = stack[-8]; /* gg */
    popv(10);
    return nil;
}



/* Code for tidysqrtf */

static Lisp_Object CC_tidysqrtf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v349, v382, v227;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tidysqrtf");
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
    v349 = stack[-1];
    if (!consp(v349)) goto v48;
    v349 = stack[-1];
    v349 = qcar(v349);
    v349 = (consp(v349) ? nil : lisp_true);
    goto v60;

v60:
    if (v349 == nil) goto v40;
    v382 = stack[-1];
    v349 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v382, v349);

v40:
    v349 = stack[-1];
    v349 = qcar(v349);
    v349 = qcar(v349);
    stack[-2] = v349;
    v349 = stack[-2];
    v382 = qcar(v349);
    v349 = elt(env, 2); /* i */
    if (!(v382 == v349)) goto v117;
    v349 = elt(env, 3); /* (sqrt -1) */
    fn = elt(env, 6); /* fkern */
    v382 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-3];
    v349 = stack[-2];
    v349 = qcdr(v349);
    fn = elt(env, 7); /* getpower */
    v349 = (*qfn2(fn))(qenv(fn), v382, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-3];
    stack[-2] = v349;
    goto v117;

v117:
    v349 = stack[-2];
    v382 = qcar(v349);
    v349 = elt(env, 4); /* sqrt */
    if (!consp(v382)) goto v27;
    v382 = qcar(v382);
    if (!(v382 == v349)) goto v27;
    v349 = stack[-2];
    v349 = qcdr(v349);
    v349 = Lonep(nil, v349);
    env = stack[-3];
    v349 = (v349 == nil ? lisp_true : nil);
    goto v65;

v65:
    if (v349 == nil) goto v366;
    v349 = stack[-2];
    v382 = qcdr(v349);
    v349 = (Lisp_Object)33; /* 2 */
    v349 = Ldivide(nil, v382, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-3];
    stack[0] = v349;
    v349 = stack[-2];
    v349 = qcar(v349);
    v349 = qcdr(v349);
    v349 = qcar(v349);
    fn = elt(env, 8); /* simp */
    v382 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-3];
    v349 = stack[0];
    v349 = qcar(v349);
    fn = elt(env, 9); /* exptsq */
    v349 = (*qfn2(fn))(qenv(fn), v382, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-3];
    v227 = v349;
    v349 = stack[0];
    v382 = qcdr(v349);
    v349 = (Lisp_Object)1; /* 0 */
    if (v382 == v349) goto v114;
    stack[0] = v227;
    v349 = stack[-2];
    v349 = qcar(v349);
    fn = elt(env, 6); /* fkern */
    v382 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-3];
    v349 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 7); /* getpower */
    v382 = (*qfn2(fn))(qenv(fn), v382, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-3];
    v349 = (Lisp_Object)17; /* 1 */
    v227 = cons(v382, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-3];
    v382 = qvalue(elt(env, 5)); /* nil */
    v349 = (Lisp_Object)17; /* 1 */
    v349 = acons(v227, v382, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-3];
    fn = elt(env, 10); /* multsq */
    v349 = (*qfn2(fn))(qenv(fn), stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-3];
    v227 = v349;
    goto v114;

v114:
    v349 = v227;
    fn = elt(env, 11); /* tidysqrt */
    v349 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-3];
    v227 = v349;
    goto v383;

v383:
    stack[0] = v227;
    v349 = stack[-1];
    v349 = qcar(v349);
    v349 = qcdr(v349);
    v349 = CC_tidysqrtf(env, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-3];
    fn = elt(env, 10); /* multsq */
    v349 = (*qfn2(fn))(qenv(fn), stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-3];
    stack[-2] = v349;
    stack[0] = stack[-2];
    v349 = stack[-1];
    v349 = qcdr(v349);
    v349 = CC_tidysqrtf(env, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-3];
    {
        Lisp_Object v384 = stack[0];
        popv(4);
        fn = elt(env, 12); /* addsq */
        return (*qfn2(fn))(qenv(fn), v384, v349);
    }

v366:
    v382 = stack[-2];
    v349 = (Lisp_Object)17; /* 1 */
    v227 = cons(v382, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-3];
    v382 = qvalue(elt(env, 5)); /* nil */
    v349 = (Lisp_Object)17; /* 1 */
    v349 = acons(v227, v382, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-3];
    v227 = v349;
    goto v383;

v27:
    v349 = qvalue(elt(env, 5)); /* nil */
    goto v65;

v48:
    v349 = qvalue(elt(env, 1)); /* t */
    goto v60;
/* error exit handlers */
v354:
    popv(4);
    return nil;
}



/* Code for rd!:prin */

static Lisp_Object CC_rdTprin(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:prin");
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
    v42 = v0;
/* end of prologue */
    v35 = v42;
    v35 = qcdr(v35);
    if (!consp(v35)) goto v14;
    v35 = v42;
    stack[0] = v35;
    goto v12;

v12:
    v42 = qvalue(elt(env, 1)); /* !:bprec!: */
    v35 = (Lisp_Object)49; /* 3 */
    v35 = difference2(v42, v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-1];
    fn = elt(env, 2); /* round!:mt */
    v35 = (*qfn2(fn))(qenv(fn), stack[0], v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-1];
    fn = elt(env, 3); /* csl_normbf */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 4); /* bfprin0 */
        return (*qfn1(fn))(qenv(fn), v35);
    }

v14:
    v35 = v42;
    v35 = qcdr(v35);
    fn = elt(env, 5); /* fl2bf */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-1];
    stack[0] = v35;
    goto v12;
/* error exit handlers */
v36:
    popv(2);
    return nil;
}



/* Code for processpartitie1list1 */

static Lisp_Object CC_processpartitie1list1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for processpartitie1list1");
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
    stack[-3] = v1;
    v44 = v0;
/* end of prologue */

v55:
    v46 = v44;
    if (v46 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v46 = v44;
    v46 = qcdr(v46);
    stack[-4] = v46;
    stack[-2] = qcar(v44);
    stack[-1] = (Lisp_Object)1; /* 0 */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v44 = qvalue(elt(env, 1)); /* nil */
    v46 = ncons(v44);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-5];
    v44 = stack[-3];
    fn = elt(env, 2); /* processpartitie1 */
    v44 = (*qfnn(fn))(qenv(fn), 5, stack[-2], stack[-1], stack[0], v46, v44);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-5];
    stack[-3] = v44;
    v44 = stack[-4];
    goto v55;
/* error exit handlers */
v22:
    popv(6);
    return nil;
}



/* Code for ofsf_smwrmknowl */

static Lisp_Object CC_ofsf_smwrmknowl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v56, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smwrmknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v56 = v1;
    v21 = v0;
/* end of prologue */
    v30 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v30 == nil) goto v33;
    v30 = v21;
    {
        fn = elt(env, 2); /* ofsf_susirmknowl */
        return (*qfn2(fn))(qenv(fn), v30, v56);
    }

v33:
    v30 = v21;
    {
        fn = elt(env, 3); /* ofsf_smrmknowl */
        return (*qfn2(fn))(qenv(fn), v30, v56);
    }
}



setup_type const u35_setup[] =
{
    {"ofsf_evalatp",            too_few_2,      CC_ofsf_evalatp,wrong_no_2},
    {"qqe_ofsf_varlat",         CC_qqe_ofsf_varlat,too_many_1, wrong_no_1},
    {"aex_subrp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_subrp},
    {"intervalrd",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_intervalrd},
    {"simpsqrtsq",              CC_simpsqrtsq,  too_many_1,    wrong_no_1},
    {"cr:onep",                 CC_crTonep,     too_many_1,    wrong_no_1},
    {"findhr",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_findhr},
    {"evinsert",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_evinsert},
    {"xpartitop",               CC_xpartitop,   too_many_1,    wrong_no_1},
    {"listpri",                 CC_listpri,     too_many_1,    wrong_no_1},
    {"numprintlen",             CC_numprintlen, too_many_1,    wrong_no_1},
    {"lndepends",               too_few_2,      CC_lndepends,  wrong_no_2},
    {"listquotient",            too_few_2,      CC_listquotient,wrong_no_2},
    {"fs:prin:",                CC_fsTprinT,    too_many_1,    wrong_no_1},
    {"cl_pop",                  CC_cl_pop,      too_many_1,    wrong_no_1},
    {"simpexpt2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpexpt2},
    {"cgp_greenp",              CC_cgp_greenp,  too_many_1,    wrong_no_1},
    {"transposerd",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_transposerd},
    {"spmatlength",             CC_spmatlength, too_many_1,    wrong_no_1},
    {"tp1",                     CC_tp1,         too_many_1,    wrong_no_1},
    {"xregister_wedge_pair",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_xregister_wedge_pair},
    {"applysetop",              too_few_2,      CC_applysetop, wrong_no_2},
    {"unshift",                 CC_unshift,     too_many_1,    wrong_no_1},
    {"redassignp",              CC_redassignp,  too_many_1,    wrong_no_1},
    {"defined_all_edge",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_defined_all_edge},
    {"quotexf*",                too_few_2,      CC_quotexfH,   wrong_no_2},
    {"groeb=crita",             CC_groebMcrita, too_many_1,    wrong_no_1},
    {"comb",                    too_few_2,      CC_comb,       wrong_no_2},
    {"lto_insert",              too_few_2,      CC_lto_insert, wrong_no_2},
    {"*invsq",                  CC_Hinvsq,      too_many_1,    wrong_no_1},
    {"pasf_fact",               CC_pasf_fact,   too_many_1,    wrong_no_1},
    {"diffrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffrd},
    {"rewrite",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_rewrite},
    {"dm-quotient",             too_few_2,      CC_dmKquotient,wrong_no_2},
    {"evweightedcomp1",         too_few_2,      CC_evweightedcomp1,wrong_no_2},
    {"evaluate2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_evaluate2},
    {"smemberl",                too_few_2,      CC_smemberl,   wrong_no_2},
    {"ev-edgeloop",             too_few_2,      CC_evKedgeloop,wrong_no_2},
    {"mv-compact",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_mvKcompact},
    {"redall",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_redall},
    {"tidysqrtf",               CC_tidysqrtf,   too_many_1,    wrong_no_1},
    {"rd:prin",                 CC_rdTprin,     too_many_1,    wrong_no_1},
    {"processpartitie1list1",   too_few_2,      CC_processpartitie1list1,wrong_no_2},
    {"ofsf_smwrmknowl",         too_few_2,      CC_ofsf_smwrmknowl,wrong_no_2},
    {NULL, (one_args *)"u35", (two_args *)"8955 6344454 251367", 0}
};

/* end of generated code */
