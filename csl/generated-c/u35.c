
/* $destdir/u35.c        Machine generated C code */

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


/* Code for simp!-prop!-dist */

static Lisp_Object CC_simpKpropKdist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0024, v0025;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simp-prop-dist");
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
    v0024 = v0000;
/* end of prologue */
    v0025 = v0024;
    v0023 = elt(env, 1); /* plus */
    if (!consp(v0025)) goto v0026;
    v0025 = qcar(v0025);
    if (!(v0025 == v0023)) goto v0026;
    v0023 = v0024;
    v0023 = qcdr(v0023);
    v0024 = v0023;
    goto v0027;

v0027:
    v0023 = v0024;
    stack[-3] = v0023;
    v0023 = stack[-3];
    if (v0023 == nil) goto v0028;
    v0023 = stack[-3];
    v0023 = qcar(v0023);
    v0025 = v0023;
    v0024 = v0025;
    v0023 = elt(env, 3); /* times */
    if (!consp(v0024)) goto v0029;
    v0024 = qcar(v0024);
    if (!(v0024 == v0023)) goto v0029;
    v0023 = v0025;
    v0023 = qcdr(v0023);
    goto v0030;

v0030:
    v0025 = v0023;
    v0023 = v0025;
    v0023 = qcar(v0023);
    if (!(is_number(v0023))) goto v0031;
    v0023 = v0025;
    v0023 = qcdr(v0023);
    v0025 = v0023;
    goto v0031;

v0031:
    v0024 = v0025;
    v0023 = elt(env, 4); /* lambda_mwvup4_8 */
    fn = elt(env, 7); /* sort */
    v0023 = (*qfn2(fn))(qenv(fn), v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    v0023 = ncons(v0023);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    stack[-1] = v0023;
    stack[-2] = v0023;
    goto v0033;

v0033:
    v0023 = stack[-3];
    v0023 = qcdr(v0023);
    stack[-3] = v0023;
    v0023 = stack[-3];
    if (v0023 == nil) goto v0034;
    stack[0] = stack[-1];
    v0023 = stack[-3];
    v0023 = qcar(v0023);
    v0025 = v0023;
    v0024 = v0025;
    v0023 = elt(env, 3); /* times */
    if (!consp(v0024)) goto v0035;
    v0024 = qcar(v0024);
    if (!(v0024 == v0023)) goto v0035;
    v0023 = v0025;
    v0023 = qcdr(v0023);
    goto v0036;

v0036:
    v0025 = v0023;
    v0023 = v0025;
    v0023 = qcar(v0023);
    if (!(is_number(v0023))) goto v0037;
    v0023 = v0025;
    v0023 = qcdr(v0023);
    v0025 = v0023;
    goto v0037;

v0037:
    v0024 = v0025;
    v0023 = elt(env, 5); /* lambda_mwvup4_9 */
    fn = elt(env, 7); /* sort */
    v0023 = (*qfn2(fn))(qenv(fn), v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    v0023 = ncons(v0023);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    v0023 = Lrplacd(nil, stack[0], v0023);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    v0023 = stack[-1];
    v0023 = qcdr(v0023);
    stack[-1] = v0023;
    goto v0033;

v0035:
    v0023 = v0025;
    v0023 = ncons(v0023);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    goto v0036;

v0034:
    v0023 = stack[-2];
    goto v0038;

v0038:
    v0024 = v0023;
    v0023 = elt(env, 6); /* simp!-prop!-order */
    {
        popv(5);
        fn = elt(env, 7); /* sort */
        return (*qfn2(fn))(qenv(fn), v0024, v0023);
    }

v0029:
    v0023 = v0025;
    v0023 = ncons(v0023);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    goto v0030;

v0028:
    v0023 = qvalue(elt(env, 2)); /* nil */
    goto v0038;

v0026:
    v0023 = v0024;
    v0023 = ncons(v0023);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    v0024 = v0023;
    goto v0027;
/* error exit handlers */
v0032:
    popv(5);
    return nil;
}



/* Code for lambda_mwvup4_9 */

static Lisp_Object CC_lambda_mwvup4_9(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0039)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0042, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_mwvup4_9");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0042 = v0039;
    v0026 = v0000;
/* end of prologue */
    v0026 = qcdr(v0026);
    v0026 = qcar(v0026);
    v0042 = qcdr(v0042);
    v0042 = qcar(v0042);
    {
        fn = elt(env, 1); /* ordp */
        return (*qfn2(fn))(qenv(fn), v0026, v0042);
    }
}



/* Code for lambda_mwvup4_8 */

static Lisp_Object CC_lambda_mwvup4_8(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0039)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0042, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_mwvup4_8");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0042 = v0039;
    v0026 = v0000;
/* end of prologue */
    v0026 = qcdr(v0026);
    v0026 = qcar(v0026);
    v0042 = qcdr(v0042);
    v0042 = qcar(v0042);
    {
        fn = elt(env, 1); /* ordp */
        return (*qfn2(fn))(qenv(fn), v0026, v0042);
    }
}



/* Code for tidysqrtf */

static Lisp_Object CC_tidysqrtf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0073, v0074, v0075;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tidysqrtf");
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
    v0073 = stack[-1];
    if (!consp(v0073)) goto v0076;
    v0073 = stack[-1];
    v0073 = qcar(v0073);
    v0073 = (consp(v0073) ? nil : lisp_true);
    goto v0077;

v0077:
    if (v0073 == nil) goto v0033;
    v0074 = stack[-1];
    v0073 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v0074, v0073);

v0033:
    v0073 = stack[-1];
    v0073 = qcar(v0073);
    v0073 = qcar(v0073);
    stack[-2] = v0073;
    v0073 = stack[-2];
    v0074 = qcar(v0073);
    v0073 = elt(env, 2); /* i */
    if (!(v0074 == v0073)) goto v0031;
    v0074 = elt(env, 3); /* (sqrt -1) */
    v0073 = stack[-2];
    v0073 = qcdr(v0073);
    fn = elt(env, 6); /* mksp */
    v0073 = (*qfn2(fn))(qenv(fn), v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    stack[-2] = v0073;
    goto v0031;

v0031:
    v0073 = stack[-2];
    v0074 = qcar(v0073);
    v0073 = elt(env, 4); /* sqrt */
    if (!consp(v0074)) goto v0079;
    v0074 = qcar(v0074);
    if (!(v0074 == v0073)) goto v0079;
    v0073 = stack[-2];
    v0073 = qcdr(v0073);
    v0073 = Lonep(nil, v0073);
    env = stack[-3];
    v0073 = (v0073 == nil ? lisp_true : nil);
    goto v0080;

v0080:
    if (v0073 == nil) goto v0081;
    v0073 = stack[-2];
    v0074 = qcdr(v0073);
    v0073 = (Lisp_Object)33; /* 2 */
    v0073 = Ldivide(nil, v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    stack[0] = v0073;
    v0073 = stack[-2];
    v0073 = qcar(v0073);
    v0073 = qcdr(v0073);
    v0073 = qcar(v0073);
    fn = elt(env, 7); /* simp */
    v0074 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    v0073 = stack[0];
    v0073 = qcar(v0073);
    fn = elt(env, 8); /* exptsq */
    v0073 = (*qfn2(fn))(qenv(fn), v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    v0075 = v0073;
    v0073 = stack[0];
    v0074 = qcdr(v0073);
    v0073 = (Lisp_Object)1; /* 0 */
    if (v0074 == v0073) goto v0082;
    stack[0] = v0075;
    v0073 = stack[-2];
    v0074 = qcar(v0073);
    v0073 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 6); /* mksp */
    v0074 = (*qfn2(fn))(qenv(fn), v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    v0073 = (Lisp_Object)17; /* 1 */
    v0075 = cons(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    v0074 = qvalue(elt(env, 5)); /* nil */
    v0073 = (Lisp_Object)17; /* 1 */
    v0073 = acons(v0075, v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    fn = elt(env, 9); /* multsq */
    v0073 = (*qfn2(fn))(qenv(fn), stack[0], v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    v0075 = v0073;
    goto v0082;

v0082:
    v0073 = v0075;
    fn = elt(env, 10); /* tidysqrt */
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    v0075 = v0073;
    goto v0083;

v0083:
    stack[0] = v0075;
    v0073 = stack[-1];
    v0073 = qcar(v0073);
    v0073 = qcdr(v0073);
    v0073 = CC_tidysqrtf(env, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    fn = elt(env, 9); /* multsq */
    v0073 = (*qfn2(fn))(qenv(fn), stack[0], v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    stack[-2] = v0073;
    stack[0] = stack[-2];
    v0073 = stack[-1];
    v0073 = qcdr(v0073);
    v0073 = CC_tidysqrtf(env, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    {
        Lisp_Object v0084 = stack[0];
        popv(4);
        fn = elt(env, 11); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0084, v0073);
    }

v0081:
    v0074 = stack[-2];
    v0073 = (Lisp_Object)17; /* 1 */
    v0075 = cons(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    v0074 = qvalue(elt(env, 5)); /* nil */
    v0073 = (Lisp_Object)17; /* 1 */
    v0073 = acons(v0075, v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    v0075 = v0073;
    goto v0083;

v0079:
    v0073 = qvalue(elt(env, 5)); /* nil */
    goto v0080;

v0076:
    v0073 = qvalue(elt(env, 1)); /* t */
    goto v0077;
/* error exit handlers */
v0078:
    popv(4);
    return nil;
}



/* Code for get_dimension_in */

static Lisp_Object CC_get_dimension_in(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get_dimension_in");
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
    v0041 = v0000;
/* end of prologue */
    v0042 = elt(env, 1); /* id */
    fn = elt(env, 2); /* get_rep_matrix_in */
    v0041 = (*qfn2(fn))(qenv(fn), v0042, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[0];
    fn = elt(env, 3); /* mk!+trace */
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); /* change!+sq!+to!+int */
        return (*qfn1(fn))(qenv(fn), v0041);
    }
/* error exit handlers */
v0026:
    popv(1);
    return nil;
}



/* Code for pasf_coeflst */

static Lisp_Object CC_pasf_coeflst(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0039)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0092, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_coeflst");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0039);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0039;
    stack[-2] = v0000;
/* end of prologue */
    stack[0] = nil;
    v0091 = stack[-1];
    v0091 = ncons(v0091);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    fn = elt(env, 3); /* setkorder */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    stack[-3] = v0091;
    v0091 = stack[-2];
    fn = elt(env, 4); /* reorder */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    stack[-2] = v0091;
    goto v0042;

v0042:
    v0091 = stack[-2];
    if (!consp(v0091)) goto v0093;
    v0091 = stack[-2];
    v0091 = qcar(v0091);
    v0091 = (consp(v0091) ? nil : lisp_true);
    goto v0033;

v0033:
    if (v0091 == nil) goto v0094;
    v0091 = qvalue(elt(env, 2)); /* nil */
    goto v0014;

v0014:
    if (v0091 == nil) goto v0041;
    v0091 = stack[-2];
    v0091 = qcar(v0091);
    v0004 = qcdr(v0091);
    v0091 = stack[-2];
    v0091 = qcar(v0091);
    v0091 = qcar(v0091);
    v0092 = qcdr(v0091);
    v0091 = stack[0];
    v0091 = acons(v0004, v0092, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    stack[0] = v0091;
    v0091 = stack[-2];
    v0091 = qcdr(v0091);
    stack[-2] = v0091;
    goto v0042;

v0041:
    v0091 = stack[-3];
    fn = elt(env, 3); /* setkorder */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    v0091 = stack[-2];
    fn = elt(env, 5); /* negf */
    v0004 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-4];
    v0092 = (Lisp_Object)1; /* 0 */
    v0091 = stack[0];
    v0091 = acons(v0004, v0092, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0009;
        popv(5);
        return Lnreverse(nil, v0091);

v0094:
    v0091 = stack[-2];
    v0091 = qcar(v0091);
    v0091 = qcar(v0091);
    v0092 = qcar(v0091);
    v0091 = stack[-1];
    v0091 = (v0092 == v0091 ? lisp_true : nil);
    goto v0014;

v0093:
    v0091 = qvalue(elt(env, 1)); /* t */
    goto v0033;
/* error exit handlers */
v0009:
    popv(5);
    return nil;
}



/* Code for vdpsimpcont */

static Lisp_Object CC_vdpsimpcont(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0089, v0100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpsimpcont");
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
    v0031 = stack[-1];
    v0031 = qcdr(v0031);
    v0031 = qcdr(v0031);
    v0031 = qcdr(v0031);
    v0031 = qcar(v0031);
    stack[0] = v0031;
    v0031 = stack[0];
    if (v0031 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0031 = stack[0];
    fn = elt(env, 3); /* dipsimpcont */
    v0031 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-3];
    stack[-2] = v0031;
    v0031 = stack[-2];
    v0031 = qcdr(v0031);
    fn = elt(env, 4); /* dip2vdp */
    v0031 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-3];
    stack[-1] = v0031;
    v0031 = stack[-2];
    v0031 = qcar(v0031);
    stack[-2] = v0031;
    v0031 = stack[-2];
    fn = elt(env, 5); /* evzero!? */
    v0031 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-3];
    if (v0031 == nil) goto v0101;
    v0031 = qvalue(elt(env, 1)); /* nil */
    goto v0028;

v0028:
    if (v0031 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0100 = stack[-1];
    v0089 = elt(env, 2); /* monfac */
    v0031 = stack[-2];
    fn = elt(env, 6); /* vdpputprop */
    v0031 = (*qfnn(fn))(qenv(fn), 3, v0100, v0089, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v0101:
    v0031 = stack[0];
    v0031 = qcdr(v0031);
    v0031 = qcdr(v0031);
    if (!(v0031 == nil)) goto v0028;
    v0031 = stack[-2];
    fn = elt(env, 7); /* evtdeg */
    v0089 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-3];
    v0031 = (Lisp_Object)17; /* 1 */
    v0031 = (Lisp_Object)greaterp2(v0089, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    v0031 = v0031 ? lisp_true : nil;
    env = stack[-3];
    goto v0028;
/* error exit handlers */
v0016:
    popv(4);
    return nil;
}



/* Code for xpartitk */

static Lisp_Object CC_xpartitk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0106, v0066, v0080;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xpartitk");
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
    v0066 = stack[0];
    v0106 = elt(env, 1); /* (wedge partdf) */
    fn = elt(env, 2); /* memqcar */
    v0106 = (*qfn2(fn))(qenv(fn), v0066, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-1];
    if (v0106 == nil) goto v0019;
    v0106 = stack[0];
    fn = elt(env, 3); /* reval */
    v0106 = (*qfn1(fn))(qenv(fn), v0106);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-1];
    v0080 = v0106;
    v0066 = v0080;
    v0106 = stack[0];
    if (equal(v0066, v0106)) goto v0101;
    v0106 = v0080;
    {
        popv(2);
        fn = elt(env, 4); /* xpartitop */
        return (*qfn1(fn))(qenv(fn), v0106);
    }

v0101:
    v0080 = stack[0];
    v0066 = (Lisp_Object)17; /* 1 */
    v0106 = (Lisp_Object)17; /* 1 */
    v0106 = list2star(v0080, v0066, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    popv(2);
    return ncons(v0106);

v0019:
    v0080 = stack[0];
    v0066 = (Lisp_Object)17; /* 1 */
    v0106 = (Lisp_Object)17; /* 1 */
    v0106 = list2star(v0080, v0066, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    popv(2);
    return ncons(v0106);
/* error exit handlers */
v0096:
    popv(2);
    return nil;
}



/* Code for lndepends */

static Lisp_Object CC_lndepends(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0039)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108, v0109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lndepends");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0039);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0039;
    stack[-1] = v0000;
/* end of prologue */

v0110:
    v0108 = stack[-1];
    if (v0108 == nil) goto v0087;
    v0108 = stack[-1];
    v0109 = qcar(v0108);
    v0108 = stack[0];
    fn = elt(env, 2); /* ndepends */
    v0108 = (*qfn2(fn))(qenv(fn), v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-2];
    if (!(v0108 == nil)) { popv(3); return onevalue(v0108); }
    v0108 = stack[-1];
    v0109 = qcdr(v0108);
    v0108 = stack[0];
    stack[-1] = v0109;
    stack[0] = v0108;
    goto v0110;

v0087:
    v0108 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0108); }
/* error exit handlers */
v0017:
    popv(3);
    return nil;
}



/* Code for color!-roads */

static Lisp_Object CC_colorKroads(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0039)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0120, v0121, v0056;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for color-roads");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0039);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0039;
    v0056 = v0000;
/* end of prologue */
    v0120 = stack[-4];
    v0120 = qcar(v0120);
    v0121 = qcar(v0120);
    v0120 = v0056;
    v0120 = Lassoc(nil, v0121, v0120);
    v0120 = qcdr(v0120);
    stack[-1] = v0120;
    v0120 = stack[-4];
    v0120 = qcdr(v0120);
    v0120 = qcar(v0120);
    v0121 = qcar(v0120);
    v0120 = v0056;
    v0120 = Lassoc(nil, v0121, v0120);
    v0120 = qcdr(v0120);
    stack[0] = v0120;
    v0120 = stack[-4];
    v0120 = qcdr(v0120);
    v0120 = qcdr(v0120);
    v0120 = qcar(v0120);
    v0120 = qcar(v0120);
    v0121 = v0056;
    v0120 = Lassoc(nil, v0120, v0121);
    v0120 = qcdr(v0120);
    stack[-5] = v0120;
    stack[-2] = stack[-1];
    v0121 = stack[0];
    v0120 = stack[-5];
    v0120 = plus2(v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    v0121 = plus2(stack[-2], v0120);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    v0120 = (Lisp_Object)33; /* 2 */
    v0120 = quot2(v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    stack[-2] = v0120;
    v0121 = stack[-2];
    v0120 = stack[-1];
    v0120 = difference2(v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    stack[-1] = v0120;
    v0121 = stack[-2];
    v0120 = stack[0];
    v0120 = difference2(v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    stack[0] = v0120;
    v0121 = stack[-2];
    v0120 = stack[-5];
    v0120 = difference2(v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    stack[-5] = v0120;
    v0120 = stack[-4];
    v0120 = qcar(v0120);
    stack[-3] = qcar(v0120);
    stack[-2] = stack[-1];
    v0120 = stack[-4];
    v0120 = qcdr(v0120);
    v0120 = qcar(v0120);
    stack[-1] = qcar(v0120);
    v0120 = stack[-4];
    v0120 = qcdr(v0120);
    v0120 = qcdr(v0120);
    v0120 = qcar(v0120);
    v0121 = qcar(v0120);
    v0120 = stack[-5];
    v0120 = cons(v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    v0120 = acons(stack[-1], stack[0], v0120);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    {
        Lisp_Object v0123 = stack[-3];
        Lisp_Object v0124 = stack[-2];
        popv(7);
        return acons(v0123, v0124, v0120);
    }
/* error exit handlers */
v0122:
    popv(7);
    return nil;
}



/* Code for gcdf2 */

static Lisp_Object CC_gcdf2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0039)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0156, v0157, v0158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdf2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0039);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0039;
    stack[-5] = v0000;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* asymplis!* */
    qvalue(elt(env, 1)) = nil; /* asymplis!* */
    v0156 = qvalue(elt(env, 2)); /* !*anygcd */
    if (v0156 == nil) goto v0041;
    v0156 = stack[-5];
    fn = elt(env, 6); /* num!-exponents */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    if (v0156 == nil) goto v0013;
    v0156 = stack[-4];
    fn = elt(env, 6); /* num!-exponents */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    v0156 = (v0156 == nil ? lisp_true : nil);
    goto v0021;

v0021:
    if (v0156 == nil) goto v0160;
    v0156 = (Lisp_Object)17; /* 1 */
    goto v0077;

v0077:
    qvalue(elt(env, 1)) = stack[-6]; /* asymplis!* */
    { popv(8); return onevalue(v0156); }

v0160:
    v0156 = qvalue(elt(env, 4)); /* !*gcd */
    if (v0156 == nil) goto v0161;
    v0157 = stack[-5];
    v0156 = stack[-4];
    fn = elt(env, 7); /* kernord */
    v0156 = (*qfn2(fn))(qenv(fn), v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    stack[-3] = v0156;
    v0157 = Llength(nil, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    v0156 = (Lisp_Object)17; /* 1 */
    v0156 = (Lisp_Object)greaterp2(v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    v0156 = v0156 ? lisp_true : nil;
    env = stack[-7];
    if (v0156 == nil) goto v0161;
    v0156 = stack[-3];
    fn = elt(env, 8); /* setkorder */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    v0156 = ncons(v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    stack[-3] = v0156;
    v0156 = stack[-5];
    fn = elt(env, 9); /* reorder */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    stack[-5] = v0156;
    v0156 = stack[-4];
    fn = elt(env, 9); /* reorder */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    stack[-4] = v0156;
    goto v0016;

v0016:
    v0156 = stack[-5];
    v0156 = qcar(v0156);
    v0156 = qcar(v0156);
    v0157 = qcar(v0156);
    v0156 = stack[-4];
    v0156 = qcar(v0156);
    v0156 = qcar(v0156);
    v0156 = qcar(v0156);
    if (v0157 == v0156) goto v0162;
    v0156 = stack[-5];
    v0156 = qcar(v0156);
    v0156 = qcar(v0156);
    v0156 = qcar(v0156);
    fn = elt(env, 10); /* noncomp */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    if (v0156 == nil) goto v0163;
    v0156 = stack[-4];
    v0156 = qcar(v0156);
    v0156 = qcar(v0156);
    v0156 = qcar(v0156);
    fn = elt(env, 10); /* noncomp */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    if (v0156 == nil) goto v0163;
    v0158 = stack[-5];
    v0157 = stack[-4];
    v0156 = stack[-4];
    v0156 = qcar(v0156);
    v0156 = qcar(v0156);
    v0156 = qcar(v0156);
    fn = elt(env, 11); /* gcdfnc */
    v0156 = (*qfnn(fn))(qenv(fn), 3, v0158, v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    stack[-2] = v0156;
    goto v0164;

v0164:
    v0156 = stack[-3];
    if (v0156 == nil) goto v0165;
    v0156 = stack[-3];
    v0156 = qcar(v0156);
    fn = elt(env, 8); /* setkorder */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    v0156 = stack[-2];
    fn = elt(env, 9); /* reorder */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    stack[-2] = v0156;
    goto v0165;

v0165:
    v0156 = stack[-2];
    goto v0077;

v0163:
    v0156 = stack[-5];
    v0156 = qcar(v0156);
    v0156 = qcar(v0156);
    v0157 = qcar(v0156);
    v0156 = stack[-4];
    v0156 = qcar(v0156);
    v0156 = qcar(v0156);
    v0156 = qcar(v0156);
    fn = elt(env, 12); /* ordop */
    v0156 = (*qfn2(fn))(qenv(fn), v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    if (v0156 == nil) goto v0166;
    v0156 = stack[-5];
    fn = elt(env, 13); /* comfac */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    v0157 = qcdr(v0156);
    v0156 = stack[-4];
    fn = elt(env, 14); /* gcdf1 */
    v0156 = (*qfn2(fn))(qenv(fn), v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    stack[-2] = v0156;
    goto v0164;

v0166:
    v0156 = stack[-4];
    fn = elt(env, 13); /* comfac */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    v0157 = qcdr(v0156);
    v0156 = stack[-5];
    fn = elt(env, 14); /* gcdf1 */
    v0156 = (*qfn2(fn))(qenv(fn), v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    stack[-2] = v0156;
    goto v0164;

v0162:
    v0156 = stack[-5];
    fn = elt(env, 13); /* comfac */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    stack[-1] = v0156;
    v0156 = stack[-4];
    fn = elt(env, 13); /* comfac */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    stack[0] = v0156;
    v0156 = stack[-1];
    v0157 = qcdr(v0156);
    v0156 = stack[0];
    v0156 = qcdr(v0156);
    fn = elt(env, 14); /* gcdf1 */
    v0156 = (*qfn2(fn))(qenv(fn), v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    stack[-2] = v0156;
    v0156 = stack[-1];
    fn = elt(env, 15); /* comfac!-to!-poly */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    fn = elt(env, 16); /* quotf1 */
    v0156 = (*qfn2(fn))(qenv(fn), stack[-5], v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    stack[-5] = v0156;
    v0156 = stack[0];
    fn = elt(env, 15); /* comfac!-to!-poly */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    fn = elt(env, 16); /* quotf1 */
    v0156 = (*qfn2(fn))(qenv(fn), stack[-4], v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    stack[-4] = v0156;
    v0156 = qvalue(elt(env, 4)); /* !*gcd */
    if (v0156 == nil) goto v0006;
    v0157 = stack[-5];
    v0156 = stack[-4];
    fn = elt(env, 17); /* gcdk */
    v0157 = (*qfn2(fn))(qenv(fn), v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    v0156 = stack[-2];
    fn = elt(env, 18); /* multf */
    v0156 = (*qfn2(fn))(qenv(fn), v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    stack[-2] = v0156;
    goto v0167;

v0167:
    v0156 = stack[-1];
    v0156 = qcar(v0156);
    if (v0156 == nil) goto v0164;
    v0156 = stack[0];
    v0156 = qcar(v0156);
    if (v0156 == nil) goto v0164;
    v0156 = stack[-1];
    v0156 = qcar(v0156);
    v0157 = qcdr(v0156);
    v0156 = stack[0];
    v0156 = qcar(v0156);
    v0156 = qcdr(v0156);
    v0156 = (Lisp_Object)greaterp2(v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    v0156 = v0156 ? lisp_true : nil;
    env = stack[-7];
    if (v0156 == nil) goto v0168;
    v0156 = stack[0];
    v0157 = qcar(v0156);
    v0156 = (Lisp_Object)17; /* 1 */
    v0156 = cons(v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    v0157 = ncons(v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    v0156 = stack[-2];
    fn = elt(env, 18); /* multf */
    v0156 = (*qfn2(fn))(qenv(fn), v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    stack[-2] = v0156;
    goto v0164;

v0168:
    v0156 = stack[-1];
    v0157 = qcar(v0156);
    v0156 = (Lisp_Object)17; /* 1 */
    v0156 = cons(v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    v0157 = ncons(v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    v0156 = stack[-2];
    fn = elt(env, 18); /* multf */
    v0156 = (*qfn2(fn))(qenv(fn), v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    stack[-2] = v0156;
    goto v0164;

v0006:
    v0156 = stack[-4];
    if (v0156 == nil) goto v0124;
    v0157 = stack[-5];
    v0156 = stack[-4];
    fn = elt(env, 16); /* quotf1 */
    v0156 = (*qfn2(fn))(qenv(fn), v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    if (v0156 == nil) goto v0124;
    v0157 = stack[-4];
    v0156 = stack[-2];
    fn = elt(env, 18); /* multf */
    v0156 = (*qfn2(fn))(qenv(fn), v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    stack[-2] = v0156;
    goto v0167;

v0124:
    v0156 = stack[-5];
    if (v0156 == nil) goto v0167;
    v0157 = stack[-4];
    v0156 = stack[-5];
    fn = elt(env, 16); /* quotf1 */
    v0156 = (*qfn2(fn))(qenv(fn), v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    if (v0156 == nil) goto v0167;
    v0157 = stack[-5];
    v0156 = stack[-2];
    fn = elt(env, 18); /* multf */
    v0156 = (*qfn2(fn))(qenv(fn), v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-7];
    stack[-2] = v0156;
    goto v0167;

v0161:
    v0156 = qvalue(elt(env, 5)); /* nil */
    stack[-3] = v0156;
    goto v0016;

v0013:
    v0156 = qvalue(elt(env, 3)); /* t */
    goto v0021;

v0041:
    v0156 = qvalue(elt(env, 3)); /* t */
    goto v0021;
/* error exit handlers */
v0159:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* asymplis!* */
    popv(8);
    return nil;
}



/* Code for red_redpol */

static Lisp_Object CC_red_redpol(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0039)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108, v0109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_redpol");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0039);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0108 = v0039;
    stack[0] = v0000;
/* end of prologue */
    fn = elt(env, 2); /* red_prepare */
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-1];
    v0109 = qvalue(elt(env, 1)); /* !*red_total */
    if (v0109 == nil) goto v0033;
    v0109 = stack[0];
    fn = elt(env, 3); /* red_totalred */
    v0108 = (*qfn2(fn))(qenv(fn), v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-1];
    goto v0169;

v0169:
    {
        popv(2);
        fn = elt(env, 4); /* red_extract */
        return (*qfn1(fn))(qenv(fn), v0108);
    }

v0033:
    v0109 = stack[0];
    fn = elt(env, 5); /* red_topred */
    v0108 = (*qfn2(fn))(qenv(fn), v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-1];
    goto v0169;
/* error exit handlers */
v0094:
    popv(2);
    return nil;
}



/* Code for baglistp */

static Lisp_Object CC_baglistp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0098, v0094, v0017;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for baglistp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0017 = v0000;
/* end of prologue */
    v0098 = v0017;
    if (!consp(v0098)) goto v0107;
    v0098 = v0017;
    v0094 = qcar(v0098);
    v0098 = elt(env, 1); /* list */
    if (v0094 == v0098) goto v0160;
    v0098 = v0017;
    v0098 = qcar(v0098);
    v0094 = elt(env, 3); /* bag */
        return Lflagp(nil, v0098, v0094);

v0160:
    v0098 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0098);

v0107:
    v0098 = qvalue(elt(env, 4)); /* nil */
    return onevalue(v0098);
}



/* Code for xquotient!-mod!-p */

static Lisp_Object MS_CDECL CC_xquotientKmodKp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0188, v0189, v0143;
    Lisp_Object fn;
    Lisp_Object v0097, v0039, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xquotient-mod-p");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0039 = va_arg(aa, Lisp_Object);
    v0097 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xquotient-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0097,v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0039,v0097);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0097;
    stack[-1] = v0039;
    stack[-2] = v0000;
/* end of prologue */
    v0188 = stack[-2];
    if (v0188 == nil) goto v0072;
    v0188 = stack[-2];
    if (!consp(v0188)) goto v0170;
    v0188 = stack[-2];
    v0188 = qcar(v0188);
    v0188 = (consp(v0188) ? nil : lisp_true);
    goto v0119;

v0119:
    if (v0188 == nil) goto v0098;
    v0188 = qvalue(elt(env, 2)); /* t */
    goto v0021;

v0021:
    if (v0188 == nil) goto v0031;
    v0188 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 3)) = v0188; /* exact!-quotient!-flag */
    { popv(5); return onevalue(v0188); }

v0031:
    v0188 = stack[-2];
    v0188 = qcar(v0188);
    v0188 = qcar(v0188);
    v0189 = qcdr(v0188);
    v0188 = stack[-1];
    v0188 = qcar(v0188);
    v0188 = qcar(v0188);
    v0188 = qcdr(v0188);
    if (equal(v0189, v0188)) goto v0085;
    v0188 = stack[-2];
    v0188 = qcar(v0188);
    v0188 = qcar(v0188);
    v0143 = qcar(v0188);
    v0188 = stack[-2];
    v0188 = qcar(v0188);
    v0188 = qcar(v0188);
    v0189 = qcdr(v0188);
    v0188 = stack[-1];
    v0188 = qcar(v0188);
    v0188 = qcar(v0188);
    v0188 = qcdr(v0188);
    v0188 = (Lisp_Object)(int32_t)((int32_t)v0189 - (int32_t)v0188 + TAG_FIXNUM);
    fn = elt(env, 4); /* mksp */
    stack[-3] = (*qfn2(fn))(qenv(fn), v0143, v0188);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    v0188 = stack[-2];
    v0188 = qcar(v0188);
    v0189 = qcdr(v0188);
    v0188 = stack[-1];
    v0188 = qcar(v0188);
    v0188 = qcdr(v0188);
    fn = elt(env, 5); /* quotient!-mod!-p */
    v0188 = (*qfn2(fn))(qenv(fn), v0189, v0188);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    v0188 = cons(stack[-3], v0188);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    stack[-3] = v0188;
    v0188 = stack[-2];
    stack[-2] = qcdr(v0188);
    v0188 = stack[-3];
    fn = elt(env, 6); /* negate!-term */
    v0189 = (*qfn1(fn))(qenv(fn), v0188);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    v0188 = stack[-1];
    v0188 = qcdr(v0188);
    fn = elt(env, 7); /* times!-term!-mod!-p */
    v0188 = (*qfn2(fn))(qenv(fn), v0189, v0188);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    fn = elt(env, 8); /* plus!-mod!-p */
    v0188 = (*qfn2(fn))(qenv(fn), stack[-2], v0188);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    stack[-2] = v0188;
    v0143 = stack[-2];
    v0189 = stack[-1];
    v0188 = stack[0];
    v0188 = CC_xquotientKmodKp(env, 3, v0143, v0189, v0188);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    {
        Lisp_Object v0191 = stack[-3];
        popv(5);
        return cons(v0191, v0188);
    }

v0085:
    v0188 = stack[-2];
    v0188 = qcar(v0188);
    v0189 = qcdr(v0188);
    v0188 = stack[-1];
    v0188 = qcar(v0188);
    v0188 = qcdr(v0188);
    fn = elt(env, 5); /* quotient!-mod!-p */
    v0188 = (*qfn2(fn))(qenv(fn), v0189, v0188);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    stack[0] = v0188;
    v0188 = stack[0];
    if (v0188 == nil) goto v0153;
    v0189 = stack[0];
    v0188 = stack[-1];
    fn = elt(env, 9); /* times!-mod!-p */
    v0188 = (*qfn2(fn))(qenv(fn), v0189, v0188);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    fn = elt(env, 10); /* difference!-mod!-p */
    v0188 = (*qfn2(fn))(qenv(fn), stack[-2], v0188);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    goto v0064;

v0064:
    if (v0188 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0188 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 3)) = v0188; /* exact!-quotient!-flag */
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v0153:
    v0188 = qvalue(elt(env, 2)); /* t */
    goto v0064;

v0098:
    v0188 = stack[-2];
    v0188 = qcar(v0188);
    v0188 = qcar(v0188);
    v0189 = qcar(v0188);
    v0188 = stack[0];
    if (equal(v0189, v0188)) goto v0020;
    v0188 = qvalue(elt(env, 2)); /* t */
    goto v0021;

v0020:
    v0188 = stack[-2];
    v0188 = qcar(v0188);
    v0188 = qcar(v0188);
    v0189 = qcdr(v0188);
    v0188 = stack[-1];
    v0188 = qcar(v0188);
    v0188 = qcar(v0188);
    v0188 = qcdr(v0188);
    v0188 = ((intptr_t)v0189 < (intptr_t)v0188) ? lisp_true : nil;
    goto v0021;

v0170:
    v0188 = qvalue(elt(env, 2)); /* t */
    goto v0119;

v0072:
    v0188 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0188); }
/* error exit handlers */
v0190:
    popv(5);
    return nil;
}



/* Code for change!+sq!+to!+int */

static Lisp_Object CC_changeLsqLtoLint(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0045, v0048;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for change+sq+to+int");
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
    v0093 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* prepsq */
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[0];
    fn = elt(env, 3); /* simp!* */
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[0];
    v0048 = v0093;
    v0093 = v0048;
    v0045 = qcdr(v0093);
    v0093 = (Lisp_Object)17; /* 1 */
    if (v0045 == v0093) goto v0169;
    v0093 = elt(env, 1); /* "no integer in change!+sq!+to!+int" */
    fn = elt(env, 4); /* rederr */
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    v0093 = nil;
    { popv(1); return onevalue(v0093); }

v0169:
    v0093 = v0048;
    v0093 = qcar(v0093);
    { popv(1); return onevalue(v0093); }
/* error exit handlers */
v0028:
    popv(1);
    return nil;
}



/* Code for fctrf */

static Lisp_Object CC_fctrf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0200, v0201, v0202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fctrf");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0000;
/* end of prologue */
    v0201 = qvalue(elt(env, 1)); /* !*exp */
    v0200 = qvalue(elt(env, 2)); /* ncmp!* */
    stack[-6] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = v0201; /* !*exp */
    stack[-4] = qvalue(elt(env, 2)); /* ncmp!* */
    qvalue(elt(env, 2)) = v0200; /* ncmp!* */
    stack[-3] = qvalue(elt(env, 3)); /* !*ezgcd */
    qvalue(elt(env, 3)) = nil; /* !*ezgcd */
    stack[-2] = qvalue(elt(env, 4)); /* !*gcd */
    qvalue(elt(env, 4)) = nil; /* !*gcd */
    stack[-1] = nil;
    v0200 = stack[-5];
    if (!consp(v0200)) goto v0192;
    v0200 = stack[-5];
    v0200 = qcar(v0200);
    v0200 = (consp(v0200) ? nil : lisp_true);
    goto v0170;

v0170:
    if (v0200 == nil) goto v0026;
    v0200 = stack[-5];
    v0200 = ncons(v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0022;

v0022:
    qvalue(elt(env, 4)) = stack[-2]; /* !*gcd */
    qvalue(elt(env, 3)) = stack[-3]; /* !*ezgcd */
    qvalue(elt(env, 2)) = stack[-4]; /* ncmp!* */
    qvalue(elt(env, 1)) = stack[-6]; /* !*exp */
    { popv(8); return onevalue(v0200); }

v0026:
    v0200 = qvalue(elt(env, 2)); /* ncmp!* */
    if (v0200 == nil) goto v0041;
    v0200 = stack[-5];
    fn = elt(env, 16); /* noncomfp */
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    if (!(v0200 == nil)) goto v0041;
    v0200 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 2)) = v0200; /* ncmp!* */
    goto v0041;

v0041:
    v0200 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 4)) = v0200; /* !*gcd */
    v0200 = qvalue(elt(env, 7)); /* !*limitedfactors */
    if (v0200 == nil) goto v0071;
    v0200 = qvalue(elt(env, 6)); /* nil */
    goto v0070;

v0070:
    if (v0200 == nil) goto v0203;
    v0200 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 3)) = v0200; /* !*ezgcd */
    goto v0203;

v0203:
    v0200 = qvalue(elt(env, 9)); /* !*mcd */
    if (v0200 == nil) goto v0080;
    v0200 = qvalue(elt(env, 1)); /* !*exp */
    if (!(v0200 == nil)) goto v0186;
    v0200 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 1)) = v0200; /* !*exp */
    v0201 = stack[-5];
    v0200 = (Lisp_Object)17; /* 1 */
    v0200 = cons(v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 17); /* resimp */
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 18); /* !*q2f */
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-5] = v0200;
    goto v0186;

v0186:
    v0201 = qvalue(elt(env, 8)); /* dmode!* */
    v0200 = elt(env, 12); /* !:rn!: */
    if (!(v0201 == v0200)) goto v0004;
    v0200 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 8)) = v0200; /* dmode!* */
    v0200 = qvalue(elt(env, 6)); /* nil */
    v0200 = ncons(v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    qvalue(elt(env, 13)) = v0200; /* alglist!* */
    v0200 = stack[-5];
    fn = elt(env, 19); /* prepf */
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 20); /* simp */
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[0] = v0200;
    v0200 = stack[0];
    v0200 = qcdr(v0200);
    if (!consp(v0200)) goto v0065;
    v0200 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0200;
    goto v0004;

v0004:
    v0200 = qvalue(elt(env, 2)); /* ncmp!* */
    if (!(v0200 == nil)) goto v0062;
    v0200 = stack[-5];
    fn = elt(env, 21); /* sf2ss */
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[0] = v0200;
    v0200 = stack[0];
    fn = elt(env, 22); /* homogp */
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    if (v0200 == nil) goto v0062;
    v0200 = qvalue(elt(env, 14)); /* !*trfac */
    if (v0200 == nil) goto v0024;
    v0200 = elt(env, 15); /* "This polynomial is homogeneous - variables scaled" 
*/
    fn = elt(env, 23); /* prin2t */
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0024;

v0024:
    v0200 = stack[0];
    v0200 = qcar(v0200);
    v0200 = qcar(v0200);
    stack[-1] = qcar(v0200);
    v0200 = stack[0];
    v0200 = qcdr(v0200);
    v0200 = qcar(v0200);
    v0200 = qcar(v0200);
    v0200 = qcar(v0200);
    fn = elt(env, 24); /* listsum */
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0200 = cons(stack[-1], v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-5] = v0200;
    v0200 = stack[0];
    stack[-1] = qcar(v0200);
    v0200 = stack[0];
    v0200 = qcdr(v0200);
    v0200 = qcar(v0200);
    fn = elt(env, 25); /* subs0 */
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0201 = Lreverse(nil, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0200 = (Lisp_Object)17; /* 1 */
    v0200 = list2star(stack[-1], v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 26); /* ss2sf */
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 27); /* fctrf1 */
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[0] = v0200;
    v0201 = stack[-5];
    v0200 = stack[0];
    fn = elt(env, 28); /* rconst */
    v0200 = (*qfn2(fn))(qenv(fn), v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[0] = v0200;
    v0200 = stack[0];
    stack[-1] = qcar(v0200);
    v0200 = stack[0];
    v0200 = qcdr(v0200);
    fn = elt(env, 29); /* sort!-factors */
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0200 = cons(stack[-1], v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0022;

v0062:
    v0200 = stack[-5];
    fn = elt(env, 27); /* fctrf1 */
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    stack[-5] = v0200;
    v0200 = stack[-1];
    if (v0200 == nil) goto v0204;
    v0200 = qvalue(elt(env, 6)); /* nil */
    v0200 = ncons(v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    qvalue(elt(env, 13)) = v0200; /* alglist!* */
    v0200 = elt(env, 12); /* !:rn!: */
    qvalue(elt(env, 8)) = v0200; /* dmode!* */
    stack[0] = stack[-5];
    v0200 = stack[-5];
    v0201 = qcar(v0200);
    v0200 = stack[-1];
    fn = elt(env, 30); /* quotf!* */
    v0200 = (*qfn2(fn))(qenv(fn), v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    fn = elt(env, 31); /* setcar */
    v0200 = (*qfn2(fn))(qenv(fn), stack[0], v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0204;

v0204:
    v0200 = stack[-5];
    stack[0] = qcar(v0200);
    v0200 = stack[-5];
    v0200 = qcdr(v0200);
    fn = elt(env, 29); /* sort!-factors */
    v0200 = (*qfn1(fn))(qenv(fn), v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    v0200 = cons(stack[0], v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0022;

v0065:
    v0200 = stack[0];
    v0200 = qcdr(v0200);
    stack[-1] = v0200;
    v0200 = stack[0];
    v0200 = qcar(v0200);
    stack[-5] = v0200;
    goto v0004;

v0080:
    v0202 = elt(env, 10); /* poly */
    v0201 = (Lisp_Object)241; /* 15 */
    v0200 = elt(env, 11); /* "Factorization invalid with MCD off" */
    fn = elt(env, 32); /* rerror */
    v0200 = (*qfnn(fn))(qenv(fn), 3, v0202, v0201, v0200);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-7];
    goto v0186;

v0071:
    v0200 = qvalue(elt(env, 8)); /* dmode!* */
    v0200 = (v0200 == nil ? lisp_true : nil);
    goto v0070;

v0192:
    v0200 = qvalue(elt(env, 5)); /* t */
    goto v0170;
/* error exit handlers */
v0168:
    env = stack[-7];
    qvalue(elt(env, 4)) = stack[-2]; /* !*gcd */
    qvalue(elt(env, 3)) = stack[-3]; /* !*ezgcd */
    qvalue(elt(env, 2)) = stack[-4]; /* ncmp!* */
    qvalue(elt(env, 1)) = stack[-6]; /* !*exp */
    popv(8);
    return nil;
}



/* Code for ps!:set!-term */

static Lisp_Object MS_CDECL CC_psTsetKterm(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0215, v0216, v0217;
    Lisp_Object fn;
    Lisp_Object v0097, v0039, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ps:set-term");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0039 = va_arg(aa, Lisp_Object);
    v0097 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:set-term");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0097,v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0039,v0097);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v0097;
    stack[-3] = v0039;
    stack[-4] = v0000;
/* end of prologue */
    v0215 = stack[-4];
    fn = elt(env, 7); /* ps!:order */
    v0215 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    stack[-5] = v0215;
    v0216 = stack[-3];
    v0215 = stack[-5];
    v0215 = (Lisp_Object)lessp2(v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    v0215 = v0215 ? lisp_true : nil;
    env = stack[-6];
    if (v0215 == nil) goto v0099;
    stack[-1] = elt(env, 1); /* tps */
    stack[0] = (Lisp_Object)49; /* 3 */
    v0217 = stack[-3];
    v0216 = elt(env, 2); /* "less than the order of " */
    v0215 = stack[-4];
    v0215 = list3(v0217, v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    fn = elt(env, 8); /* rerror */
    v0215 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    goto v0040;

v0040:
    v0215 = stack[-4];
    if (!consp(v0215)) goto v0085;
    v0215 = stack[-4];
    v0216 = qcar(v0215);
    v0215 = elt(env, 5); /* !:ps!: */
    if (v0216 == v0215) goto v0111;
    v0215 = stack[-4];
    v0215 = qcar(v0215);
    if (!symbolp(v0215)) v0215 = nil;
    else { v0215 = qfastgets(v0215);
           if (v0215 != nil) { v0215 = elt(v0215, 8); /* dname */
#ifdef RECORD_GET
             if (v0215 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0215 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0215 == SPID_NOPROP) v0215 = nil; }}
#endif
    goto v0219;

v0219:
    if (v0215 == nil) goto v0167;
    v0217 = (Lisp_Object)1; /* 0 */
    v0216 = stack[-4];
    v0215 = (Lisp_Object)17; /* 1 */
    v0215 = list2star(v0217, v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    v0215 = ncons(v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    goto v0079;

v0079:
    stack[0] = v0215;
    v0215 = stack[-2];
    if (!consp(v0215)) goto v0002;
    v0215 = stack[-2];
    v0216 = qcar(v0215);
    v0215 = qvalue(elt(env, 6)); /* nil */
    v0215 = Lneq(nil, v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    goto v0001;

v0001:
    if (v0215 == nil) goto v0143;
    v0215 = stack[0];
    if (v0215 == nil) goto v0144;
    v0216 = stack[-3];
    v0215 = stack[-5];
    v0216 = difference2(v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    v0215 = stack[-2];
    v0215 = cons(v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    v0215 = ncons(v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    v0215 = Lnconc(nil, stack[0], v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    goto v0202;

v0202:
    v0217 = stack[-4];
    v0216 = (Lisp_Object)17; /* 1 */
    v0215 = stack[-3];
    fn = elt(env, 9); /* ps!:putv */
    v0215 = (*qfnn(fn))(qenv(fn), 3, v0217, v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    v0215 = nil;
    { popv(7); return onevalue(v0215); }

v0144:
    stack[-1] = stack[-4];
    stack[0] = (Lisp_Object)81; /* 5 */
    v0216 = stack[-3];
    v0215 = stack[-5];
    v0216 = difference2(v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    v0215 = stack[-2];
    v0215 = cons(v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    v0215 = ncons(v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    fn = elt(env, 9); /* ps!:putv */
    v0215 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    goto v0202;

v0143:
    v0216 = stack[-3];
    v0215 = stack[-5];
    if (!(equal(v0216, v0215))) goto v0202;
    stack[-1] = stack[-4];
    stack[0] = (Lisp_Object)1; /* 0 */
    v0215 = stack[-3];
    v0215 = add1(v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    fn = elt(env, 9); /* ps!:putv */
    v0215 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    goto v0202;

v0002:
    v0215 = qvalue(elt(env, 4)); /* t */
    goto v0001;

v0167:
    v0216 = stack[-4];
    v0215 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 10); /* ps!:getv */
    v0215 = (*qfn2(fn))(qenv(fn), v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    goto v0079;

v0111:
    v0215 = qvalue(elt(env, 6)); /* nil */
    goto v0219;

v0085:
    v0215 = qvalue(elt(env, 4)); /* t */
    goto v0219;

v0099:
    stack[0] = stack[-3];
    v0215 = stack[-4];
    fn = elt(env, 11); /* ps!:last!-term */
    v0215 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    v0215 = (Lisp_Object)lesseq2(stack[0], v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    v0215 = v0215 ? lisp_true : nil;
    env = stack[-6];
    if (v0215 == nil) goto v0040;
    stack[-1] = elt(env, 1); /* tps */
    stack[0] = (Lisp_Object)65; /* 4 */
    v0217 = stack[-3];
    v0216 = elt(env, 3); /* "less than power of last term of " */
    v0215 = stack[-4];
    v0215 = list3(v0217, v0216, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    fn = elt(env, 8); /* rerror */
    v0215 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-6];
    goto v0040;
/* error exit handlers */
v0218:
    popv(7);
    return nil;
}



/* Code for crnprimp */

static Lisp_Object CC_crnprimp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for crnprimp");
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
    v0017 = stack[0];
    fn = elt(env, 4); /* rnonep!: */
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-2];
    if (v0017 == nil) goto v0087;
    v0017 = elt(env, 1); /* i */
    { popv(3); return onevalue(v0017); }

v0087:
    v0017 = stack[0];
    fn = elt(env, 5); /* rnminus!: */
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-2];
    fn = elt(env, 4); /* rnonep!: */
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-2];
    if (v0017 == nil) goto v0033;
    v0017 = elt(env, 2); /* minus */
    v0018 = elt(env, 1); /* i */
    popv(3);
    return list2(v0017, v0018);

v0033:
    stack[-1] = elt(env, 3); /* times */
    v0017 = stack[0];
    fn = elt(env, 6); /* rnprep!: */
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-2];
    v0018 = elt(env, 1); /* i */
    {
        Lisp_Object v0117 = stack[-1];
        popv(3);
        return list3(v0117, v0017, v0018);
    }
/* error exit handlers */
v0203:
    popv(3);
    return nil;
}



/* Code for simpdf */

static Lisp_Object CC_simpdf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0231, v0232;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpdf");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0000;
/* end of prologue */
    stack[-3] = nil;
    v0231 = qvalue(elt(env, 1)); /* subfg!* */
    if (v0231 == nil) goto v0014;
    v0231 = stack[-5];
    v0231 = qcdr(v0231);
    stack[-6] = v0231;
    v0231 = stack[-5];
    v0231 = qcar(v0231);
    fn = elt(env, 10); /* simp!* */
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-7];
    stack[-5] = v0231;
    goto v0076;

v0076:
    v0231 = stack[-6];
    if (v0231 == nil) goto v0203;
    v0231 = stack[-5];
    v0231 = qcar(v0231);
    v0231 = (v0231 == nil ? lisp_true : nil);
    goto v0105;

v0105:
    if (!(v0231 == nil)) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v0231 = stack[-3];
    if (v0231 == nil) goto v0102;
    v0232 = stack[-3];
    v0231 = (Lisp_Object)1; /* 0 */
    v0231 = (v0232 == v0231 ? lisp_true : nil);
    goto v0104;

v0104:
    if (v0231 == nil) goto v0115;
    v0231 = stack[-6];
    v0231 = qcar(v0231);
    fn = elt(env, 10); /* simp!* */
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-7];
    goto v0029;

v0029:
    stack[-4] = v0231;
    v0231 = stack[-4];
    v0232 = qcdr(v0231);
    v0231 = (Lisp_Object)17; /* 1 */
    if (v0232 == v0231) goto v0198;
    v0231 = qvalue(elt(env, 3)); /* t */
    goto v0085;

v0085:
    if (v0231 == nil) goto v0151;
    v0231 = stack[-4];
    fn = elt(env, 11); /* prepsq */
    v0232 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-7];
    v0231 = elt(env, 4); /* "kernel or integer" */
    fn = elt(env, 12); /* typerr */
    v0231 = (*qfn2(fn))(qenv(fn), v0232, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-7];
    goto v0181;

v0181:
    v0231 = stack[-6];
    v0231 = qcdr(v0231);
    stack[-6] = v0231;
    v0231 = stack[-6];
    if (v0231 == nil) goto v0168;
    v0231 = stack[-6];
    v0231 = qcar(v0231);
    fn = elt(env, 10); /* simp!* */
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-7];
    stack[-3] = v0231;
    v0231 = stack[-3];
    v0231 = qcar(v0231);
    if (v0231 == nil) goto v0234;
    v0231 = stack[-3];
    fn = elt(env, 13); /* d2int */
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-7];
    stack[0] = v0231;
    if (v0231 == nil) goto v0235;
    v0231 = stack[-6];
    v0231 = qcdr(v0231);
    stack[-6] = v0231;
    v0231 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0231;
    goto v0236;

v0236:
    v0232 = stack[0];
    v0231 = stack[-1];
    v0231 = difference2(v0232, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-7];
    v0231 = Lminusp(nil, v0231);
    env = stack[-7];
    if (v0231 == nil) goto v0237;
    v0231 = qvalue(elt(env, 8)); /* nil */
    stack[-3] = v0231;
    goto v0076;

v0237:
    v0232 = stack[-5];
    v0231 = stack[-4];
    fn = elt(env, 14); /* diffsq */
    v0231 = (*qfn2(fn))(qenv(fn), v0232, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-7];
    stack[-5] = v0231;
    v0231 = stack[-1];
    v0231 = add1(v0231);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-7];
    stack[-1] = v0231;
    goto v0236;

v0235:
    v0232 = stack[-5];
    v0231 = stack[-4];
    fn = elt(env, 14); /* diffsq */
    v0231 = (*qfn2(fn))(qenv(fn), v0232, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-7];
    stack[-5] = v0231;
    goto v0076;

v0234:
    v0231 = stack[-6];
    v0231 = qcdr(v0231);
    stack[-6] = v0231;
    v0231 = qvalue(elt(env, 8)); /* nil */
    stack[-3] = v0231;
    goto v0076;

v0168:
    v0232 = stack[-5];
    v0231 = stack[-4];
    fn = elt(env, 14); /* diffsq */
    v0231 = (*qfn2(fn))(qenv(fn), v0232, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-7];
    stack[-5] = v0231;
    goto v0076;

v0151:
    v0231 = stack[-4];
    v0231 = qcar(v0231);
    stack[-2] = v0231;
    v0231 = stack[-2];
    if (!consp(v0231)) goto v0185;
    v0231 = stack[-2];
    v0231 = qcar(v0231);
    v0231 = (consp(v0231) ? nil : lisp_true);
    goto v0037;

v0037:
    if (v0231 == nil) goto v0062;
    v0231 = stack[-2];
    v0232 = qcar(v0231);
    v0231 = elt(env, 5); /* domain!-diff!-fn */
    v0231 = get(v0232, v0231);
    env = stack[-7];
    if (v0231 == nil) goto v0238;
    stack[-1] = qvalue(elt(env, 6)); /* dmode!* */
    qvalue(elt(env, 6)) = nil; /* dmode!* */
    stack[0] = qvalue(elt(env, 7)); /* alglist!* */
    qvalue(elt(env, 7)) = nil; /* alglist!* */
    v0231 = qvalue(elt(env, 8)); /* nil */
    v0231 = ncons(v0231);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-7];
    qvalue(elt(env, 7)) = v0231; /* alglist!* */
    v0231 = stack[-2];
    fn = elt(env, 15); /* prepf */
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-7];
    stack[-4] = v0231;
    v0231 = stack[-4];
    fn = elt(env, 16); /* prekernp */
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-7];
    if (!(v0231 == nil)) goto v0197;
    v0232 = stack[-4];
    v0231 = elt(env, 9); /* "kernel" */
    fn = elt(env, 12); /* typerr */
    v0231 = (*qfn2(fn))(qenv(fn), v0232, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-7];
    goto v0197;

v0197:
    qvalue(elt(env, 7)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 6)) = stack[-1]; /* dmode!* */
    goto v0181;

v0238:
    v0231 = stack[-2];
    fn = elt(env, 15); /* prepf */
    v0232 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-7];
    v0231 = elt(env, 9); /* "kernel" */
    fn = elt(env, 12); /* typerr */
    v0231 = (*qfn2(fn))(qenv(fn), v0232, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-7];
    goto v0181;

v0062:
    v0231 = stack[-2];
    v0231 = qcdr(v0231);
    if (v0231 == nil) goto v0176;
    v0231 = qvalue(elt(env, 8)); /* nil */
    goto v0174;

v0174:
    if (v0231 == nil) goto v0239;
    v0231 = stack[-2];
    v0231 = qcar(v0231);
    v0231 = qcar(v0231);
    v0231 = qcar(v0231);
    stack[-4] = v0231;
    goto v0181;

v0239:
    v0231 = stack[-2];
    fn = elt(env, 15); /* prepf */
    v0232 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-7];
    v0231 = elt(env, 9); /* "kernel" */
    fn = elt(env, 12); /* typerr */
    v0231 = (*qfn2(fn))(qenv(fn), v0232, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-7];
    goto v0181;

v0176:
    v0231 = stack[-2];
    v0231 = qcar(v0231);
    v0232 = qcdr(v0231);
    v0231 = (Lisp_Object)17; /* 1 */
    if (v0232 == v0231) goto v0075;
    v0231 = qvalue(elt(env, 8)); /* nil */
    goto v0174;

v0075:
    v0231 = stack[-2];
    v0231 = qcar(v0231);
    v0231 = qcar(v0231);
    v0232 = qcdr(v0231);
    v0231 = (Lisp_Object)17; /* 1 */
    v0231 = (v0232 == v0231 ? lisp_true : nil);
    goto v0174;

v0185:
    v0231 = qvalue(elt(env, 3)); /* t */
    goto v0037;

v0198:
    v0231 = stack[-4];
    v0231 = qcar(v0231);
    v0231 = (consp(v0231) ? nil : lisp_true);
    goto v0085;

v0115:
    v0231 = stack[-3];
    goto v0029;

v0102:
    v0231 = qvalue(elt(env, 3)); /* t */
    goto v0104;

v0203:
    v0231 = qvalue(elt(env, 3)); /* t */
    goto v0105;

v0014:
    v0232 = elt(env, 2); /* df */
    v0231 = stack[-5];
    v0232 = cons(v0232, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-7];
    v0231 = (Lisp_Object)17; /* 1 */
    {
        popv(8);
        fn = elt(env, 17); /* mksq */
        return (*qfn2(fn))(qenv(fn), v0232, v0231);
    }
/* error exit handlers */
v0125:
    env = stack[-7];
    qvalue(elt(env, 7)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 6)) = stack[-1]; /* dmode!* */
    popv(8);
    return nil;
v0233:
    popv(8);
    return nil;
}



/* Code for copy_vect */

static Lisp_Object CC_copy_vect(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0039)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0240, v0230, v0029, v0068;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for copy_vect");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0039);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0039;
    stack[-2] = v0000;
/* end of prologue */
    v0240 = stack[-1];
    v0240 = Lupbv(nil, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-4];
    stack[-3] = v0240;
    v0240 = (Lisp_Object)1; /* 0 */
    stack[0] = v0240;
    goto v0013;

v0013:
    v0230 = stack[-3];
    v0240 = stack[0];
    v0240 = difference2(v0230, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-4];
    v0240 = Lminusp(nil, v0240);
    env = stack[-4];
    if (v0240 == nil) goto v0101;
    v0240 = nil;
    { popv(5); return onevalue(v0240); }

v0101:
    v0068 = stack[-2];
    v0029 = stack[0];
    v0230 = stack[-1];
    v0240 = stack[0];
    v0240 = *(Lisp_Object *)((char *)v0230 + (CELL-TAG_VECTOR) + ((int32_t)v0240/(16/CELL)));
    *(Lisp_Object *)((char *)v0068 + (CELL-TAG_VECTOR) + ((int32_t)v0029/(16/CELL))) = v0240;
    v0240 = stack[0];
    v0240 = add1(v0240);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-4];
    stack[0] = v0240;
    goto v0013;
/* error exit handlers */
v0103:
    popv(5);
    return nil;
}



/* Code for groebsaveltermbc */

static Lisp_Object CC_groebsaveltermbc(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0031, v0089;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebsaveltermbc");
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
    v0161 = stack[0];
    fn = elt(env, 3); /* vbc2a */
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-2];
    stack[0] = v0161;
    v0161 = stack[0];
    if (is_number(v0161)) goto v0026;
    v0161 = stack[0];
    fn = elt(env, 4); /* constant_exprp */
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-2];
    v0161 = (v0161 == nil ? lisp_true : nil);
    goto v0160;

v0160:
    if (v0161 == nil) goto v0077;
    v0161 = stack[0];
    fn = elt(env, 5); /* simp */
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-2];
    v0161 = qcar(v0161);
    fn = elt(env, 6); /* fctrf */
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-2];
    v0161 = qcdr(v0161);
    stack[-1] = v0161;
    goto v0013;

v0013:
    v0161 = stack[-1];
    if (v0161 == nil) goto v0101;
    v0161 = stack[-1];
    v0161 = qcar(v0161);
    v0089 = v0161;
    v0161 = v0089;
    v0161 = qcar(v0161);
    fn = elt(env, 7); /* prepf */
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-2];
    v0089 = v0161;
    v0031 = v0089;
    v0161 = qvalue(elt(env, 2)); /* glterms */
    v0161 = Lmember(nil, v0031, v0161);
    if (!(v0161 == nil)) goto v0117;
    stack[0] = qvalue(elt(env, 2)); /* glterms */
    v0161 = v0089;
    v0161 = ncons(v0161);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-2];
    v0161 = Lnconc(nil, stack[0], v0161);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-2];
    goto v0117;

v0117:
    v0161 = stack[-1];
    v0161 = qcdr(v0161);
    stack[-1] = v0161;
    goto v0013;

v0101:
    v0161 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0161); }

v0077:
    v0161 = nil;
    { popv(3); return onevalue(v0161); }

v0026:
    v0161 = qvalue(elt(env, 1)); /* nil */
    goto v0160;
/* error exit handlers */
v0162:
    popv(3);
    return nil;
}



/* Code for multiply!-by!-power!-of!-ten */

static Lisp_Object CC_multiplyKbyKpowerKofKten(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0039)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multiply-by-power-of-ten");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0039);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0039;
    stack[-1] = v0000;
/* end of prologue */
    v0005 = stack[0];
    v0004 = (Lisp_Object)1; /* 0 */
    v0004 = (Lisp_Object)lessp2(v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    v0004 = v0004 ? lisp_true : nil;
    env = stack[-3];
    if (v0004 == nil) goto v0119;
    v0004 = elt(env, 0); /* multiply!-by!-power!-of!-ten */
    {
        popv(4);
        fn = elt(env, 4); /* bflerrmsg */
        return (*qfn1(fn))(qenv(fn), v0004);
    }

v0119:
    v0004 = qvalue(elt(env, 1)); /* bften!* */
    stack[-2] = v0004;
    goto v0028;

v0028:
    v0005 = stack[0];
    v0004 = (Lisp_Object)1; /* 0 */
    v0004 = (Lisp_Object)greaterp2(v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    v0004 = v0004 ? lisp_true : nil;
    env = stack[-3];
    if (v0004 == nil) goto v0154;
    v0004 = stack[0];
    v0004 = Levenp(nil, v0004);
    env = stack[-3];
    if (!(v0004 == nil)) goto v0155;
    v0005 = stack[-1];
    v0004 = stack[-2];
    fn = elt(env, 5); /* times!: */
    v0004 = (*qfn2(fn))(qenv(fn), v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    fn = elt(env, 6); /* normbf */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    stack[-1] = v0004;
    goto v0155;

v0155:
    v0005 = stack[0];
    v0004 = (Lisp_Object)-15; /* -1 */
    v0004 = ash(v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    stack[0] = v0004;
    v0005 = stack[-2];
    v0004 = stack[-2];
    fn = elt(env, 5); /* times!: */
    v0005 = (*qfn2(fn))(qenv(fn), v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    v0004 = qvalue(elt(env, 3)); /* !:bprec!: */
    fn = elt(env, 7); /* cut!:mt */
    v0004 = (*qfn2(fn))(qenv(fn), v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    fn = elt(env, 6); /* normbf */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    stack[-2] = v0004;
    goto v0028;

v0154:
    v0005 = stack[-1];
    v0004 = qvalue(elt(env, 3)); /* !:bprec!: */
    fn = elt(env, 7); /* cut!:mt */
    v0004 = (*qfn2(fn))(qenv(fn), v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 6); /* normbf */
        return (*qfn1(fn))(qenv(fn), v0004);
    }
/* error exit handlers */
v0009:
    popv(4);
    return nil;
}



/* Code for diff_vertex */

static Lisp_Object CC_diff_vertex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0039)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0155, v0069, v0104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diff_vertex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0039);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0039;
    stack[-1] = v0000;
/* end of prologue */
    v0104 = nil;
    goto v0072;

v0072:
    v0155 = stack[-1];
    if (v0155 == nil) goto v0160;
    v0155 = stack[-1];
    v0155 = qcar(v0155);
    v0069 = qcar(v0155);
    v0155 = stack[0];
    v0155 = Lassoc(nil, v0069, v0155);
    if (v0155 == nil) goto v0090;
    v0155 = stack[-1];
    v0155 = qcar(v0155);
    v0069 = qcar(v0155);
    v0155 = qvalue(elt(env, 1)); /* !_0edge */
    v0155 = qcar(v0155);
    if (v0069 == v0155) goto v0090;
    v0155 = stack[-1];
    v0155 = qcdr(v0155);
    stack[-1] = v0155;
    goto v0072;

v0090:
    v0155 = stack[-1];
    v0155 = qcar(v0155);
    v0069 = v0104;
    v0155 = cons(v0155, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-2];
    v0104 = v0155;
    v0155 = stack[-1];
    v0155 = qcdr(v0155);
    stack[-1] = v0155;
    goto v0072;

v0160:
    v0155 = v0104;
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0155);
    }
/* error exit handlers */
v0106:
    popv(3);
    return nil;
}



/* Code for dfp!-rule!-found */

static Lisp_Object CC_dfpKruleKfound(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0039)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0028, v0101, v0107;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dfp-rule-found");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0101 = v0039;
    v0107 = v0000;
/* end of prologue */
    v0028 = v0107;
    v0048 = elt(env, 1); /* dfp */
    if (!consp(v0028)) goto v0087;
    v0028 = qcar(v0028);
    if (!(v0028 == v0048)) goto v0087;
    v0048 = v0107;
    v0048 = qcdr(v0048);
    v0048 = qcar(v0048);
    v0028 = v0101;
        return Lneq(nil, v0048, v0028);

v0087:
    v0048 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0048);
}



/* Code for equiv!-coeffs */

static Lisp_Object CC_equivKcoeffs(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0039)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for equiv-coeffs");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0039);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0039;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0072;

v0072:
    v0086 = stack[-1];
    if (v0086 == nil) goto v0021;
    v0086 = stack[0];
    if (v0086 == nil) goto v0013;
    v0086 = stack[-1];
    v0086 = qcar(v0086);
    v0091 = qcar(v0086);
    v0086 = stack[0];
    v0086 = qcar(v0086);
    v0086 = qcar(v0086);
    if (equal(v0091, v0086)) goto v0117;
    v0086 = stack[-1];
    v0086 = qcar(v0086);
    v0091 = qcar(v0086);
    v0086 = stack[0];
    v0086 = qcar(v0086);
    v0086 = qcar(v0086);
    fn = elt(env, 1); /* mv!-pow!-!> */
    v0086 = (*qfn2(fn))(qenv(fn), v0091, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-3];
    if (v0086 == nil) goto v0115;
    v0086 = stack[-1];
    v0086 = qcdr(v0086);
    stack[-1] = v0086;
    goto v0072;

v0115:
    v0091 = (Lisp_Object)1; /* 0 */
    v0086 = stack[-2];
    v0086 = cons(v0091, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-3];
    stack[-2] = v0086;
    v0086 = stack[0];
    v0086 = qcdr(v0086);
    stack[0] = v0086;
    goto v0072;

v0117:
    v0086 = stack[-1];
    v0086 = qcar(v0086);
    v0091 = qcdr(v0086);
    v0086 = stack[-2];
    v0086 = cons(v0091, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-3];
    stack[-2] = v0086;
    v0086 = stack[-1];
    v0086 = qcdr(v0086);
    stack[-1] = v0086;
    v0086 = stack[0];
    v0086 = qcdr(v0086);
    stack[0] = v0086;
    goto v0072;

v0013:
    v0086 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0086);
    }

v0021:
    stack[-1] = stack[-2];
    v0086 = stack[0];
    v0086 = Llength(nil, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-3];
    fn = elt(env, 3); /* nzeros */
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-3];
    {
        Lisp_Object v0186 = stack[-1];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0186, v0086);
    }
/* error exit handlers */
v0214:
    popv(4);
    return nil;
}



/* Code for addnew */

static Lisp_Object MS_CDECL CC_addnew(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0240, v0230, v0029, v0068;
    Lisp_Object fn;
    Lisp_Object v0097, v0039, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "addnew");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0039 = va_arg(aa, Lisp_Object);
    v0097 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addnew");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0097,v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0039,v0097);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0097;
    v0029 = v0039;
    v0068 = v0000;
/* end of prologue */
    v0230 = qvalue(elt(env, 1)); /* gv!* */
    v0240 = v0029;
    v0019 = v0068;
    *(Lisp_Object *)((char *)v0230 + (CELL-TAG_VECTOR) + ((int32_t)v0240/(16/CELL))) = v0019;
    v0230 = qvalue(elt(env, 2)); /* bv!* */
    v0240 = v0029;
    v0019 = qvalue(elt(env, 3)); /* t */
    *(Lisp_Object *)((char *)v0230 + (CELL-TAG_VECTOR) + ((int32_t)v0240/(16/CELL))) = v0019;
    v0019 = v0068;
    if (v0019 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = v0029;
    v0019 = v0068;
    fn = elt(env, 4); /* ljet */
    v0019 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-2];
    v0240 = cons(stack[-1], v0019);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-2];
    v0019 = stack[0];
    fn = elt(env, 5); /* insert */
    v0019 = (*qfn2(fn))(qenv(fn), v0240, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    { popv(3); return onevalue(v0019); }
/* error exit handlers */
v0104:
    popv(3);
    return nil;
}



/* Code for mchsarg */

static Lisp_Object MS_CDECL CC_mchsarg(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0241, v0178;
    Lisp_Object fn;
    Lisp_Object v0097, v0039, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mchsarg");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0039 = va_arg(aa, Lisp_Object);
    v0097 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mchsarg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0097,v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0039,v0097);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0097;
    stack[-6] = v0039;
    stack[-1] = v0000;
/* end of prologue */
    v0241 = stack[-6];
    fn = elt(env, 4); /* mtp */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-8];
    if (v0241 == nil) goto v0092;
    v0178 = stack[-5];
    v0241 = elt(env, 1); /* times */
    if (v0178 == v0241) goto v0033;
    v0241 = qvalue(elt(env, 2)); /* t */
    goto v0041;

v0041:
    if (v0241 == nil) goto v0092;
    v0241 = stack[-6];
    fn = elt(env, 5); /* noncomperm */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-8];
    stack[-4] = v0241;
    v0241 = stack[-4];
    if (v0241 == nil) goto v0105;
    v0241 = stack[-4];
    v0241 = qcar(v0241);
    v0178 = v0241;
    v0241 = stack[-1];
    fn = elt(env, 6); /* pair */
    v0241 = (*qfn2(fn))(qenv(fn), v0178, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-8];
    v0241 = ncons(v0241);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-8];
    stack[-2] = v0241;
    stack[-3] = v0241;
    goto v0098;

v0098:
    v0241 = stack[-4];
    v0241 = qcdr(v0241);
    stack[-4] = v0241;
    v0241 = stack[-4];
    if (v0241 == nil) goto v0066;
    stack[0] = stack[-2];
    v0241 = stack[-4];
    v0241 = qcar(v0241);
    v0178 = v0241;
    v0241 = stack[-1];
    fn = elt(env, 6); /* pair */
    v0241 = (*qfn2(fn))(qenv(fn), v0178, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-8];
    v0241 = ncons(v0241);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-8];
    v0241 = Lrplacd(nil, stack[0], v0241);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-8];
    v0241 = stack[-2];
    v0241 = qcdr(v0241);
    stack[-2] = v0241;
    goto v0098;

v0066:
    v0241 = stack[-3];
    goto v0072;

v0072:
    {
        popv(9);
        fn = elt(env, 7); /* reversip!* */
        return (*qfn1(fn))(qenv(fn), v0241);
    }

v0105:
    v0241 = qvalue(elt(env, 3)); /* nil */
    goto v0072;

v0092:
    v0241 = stack[-1];
    fn = elt(env, 5); /* noncomperm */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-8];
    stack[-7] = v0241;
    goto v0036;

v0036:
    v0241 = stack[-7];
    if (v0241 == nil) goto v0064;
    v0241 = stack[-7];
    v0241 = qcar(v0241);
    stack[-1] = v0241;
    stack[0] = stack[-6];
    v0241 = qvalue(elt(env, 3)); /* nil */
    v0178 = ncons(v0241);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-8];
    v0241 = stack[-5];
    fn = elt(env, 8); /* mcharg2 */
    v0241 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v0178, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-8];
    stack[-4] = v0241;
    v0241 = stack[-4];
    fn = elt(env, 9); /* lastpair */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-8];
    stack[-3] = v0241;
    v0241 = stack[-7];
    v0241 = qcdr(v0241);
    stack[-7] = v0241;
    v0241 = stack[-3];
    if (!consp(v0241)) goto v0036;
    else goto v0242;

v0242:
    v0241 = stack[-7];
    if (v0241 == nil) goto v0121;
    stack[-2] = stack[-3];
    v0241 = stack[-7];
    v0241 = qcar(v0241);
    stack[-1] = v0241;
    stack[0] = stack[-6];
    v0241 = qvalue(elt(env, 3)); /* nil */
    v0178 = ncons(v0241);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-8];
    v0241 = stack[-5];
    fn = elt(env, 8); /* mcharg2 */
    v0241 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v0178, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-8];
    v0241 = Lrplacd(nil, stack[-2], v0241);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-8];
    v0241 = stack[-3];
    fn = elt(env, 9); /* lastpair */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-8];
    stack[-3] = v0241;
    v0241 = stack[-7];
    v0241 = qcdr(v0241);
    stack[-7] = v0241;
    goto v0242;

v0121:
    v0241 = stack[-4];
    goto v0072;

v0064:
    v0241 = qvalue(elt(env, 3)); /* nil */
    goto v0072;

v0033:
    v0241 = stack[-1];
    fn = elt(env, 10); /* noncomfree */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0211;
    env = stack[-8];
    goto v0041;
/* error exit handlers */
v0211:
    popv(9);
    return nil;
}



/* Code for mri_simplat1 */

static Lisp_Object CC_mri_simplat1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0039)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0182, v0064;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_simplat1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0039);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0039;
    stack[-2] = v0000;
/* end of prologue */
    v0182 = qvalue(elt(env, 1)); /* !*rlsimplfloor */
    if (v0182 == nil) goto v0076;
    v0182 = stack[-2];
    fn = elt(env, 4); /* mri_op */
    stack[-3] = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0182 = stack[-2];
    fn = elt(env, 5); /* mri_arg2l */
    v0182 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    fn = elt(env, 6); /* mri_simplfloor */
    stack[0] = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0182 = stack[-2];
    fn = elt(env, 7); /* mri_type */
    v0182 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    fn = elt(env, 8); /* mri_0mk2 */
    v0182 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v0182);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    stack[-2] = v0182;
    goto v0076;

v0076:
    v0182 = stack[-2];
    fn = elt(env, 7); /* mri_type */
    v0182 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    if (!(v0182 == nil)) goto v0048;
    v0182 = stack[-2];
    fn = elt(env, 9); /* mri_dettype */
    v0182 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    goto v0048;

v0048:
    stack[0] = v0182;
    v0064 = stack[0];
    v0182 = elt(env, 2); /* int */
    if (v0064 == v0182) goto v0068;
    v0182 = stack[-2];
    fn = elt(env, 10); /* mri_congp */
    v0182 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    if (v0182 == nil) goto v0116;
    v0182 = stack[-2];
    fn = elt(env, 4); /* mri_op */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0182 = stack[-2];
    fn = elt(env, 5); /* mri_arg2l */
    v0064 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0182 = stack[0];
    {
        Lisp_Object v0065 = stack[-1];
        popv(5);
        fn = elt(env, 8); /* mri_0mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v0065, v0064, v0182);
    }

v0116:
    v0182 = stack[-2];
    fn = elt(env, 11); /* mri_2ofsfat */
    v0064 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0182 = stack[-1];
    fn = elt(env, 12); /* ofsf_simplat1 */
    v0064 = (*qfn2(fn))(qenv(fn), v0064, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0182 = elt(env, 3); /* real */
    {
        popv(5);
        fn = elt(env, 13); /* mri_ofsf2mri */
        return (*qfn2(fn))(qenv(fn), v0064, v0182);
    }

v0068:
    v0182 = stack[-2];
    fn = elt(env, 14); /* mri_2pasfat */
    v0064 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0182 = stack[-1];
    fn = elt(env, 15); /* pasf_simplat1 */
    v0064 = (*qfn2(fn))(qenv(fn), v0064, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0182 = elt(env, 2); /* int */
    {
        popv(5);
        fn = elt(env, 16); /* mri_pasf2mri */
        return (*qfn2(fn))(qenv(fn), v0064, v0182);
    }
/* error exit handlers */
v0111:
    popv(5);
    return nil;
}



/* Code for rl_sacatlp */

static Lisp_Object CC_rl_sacatlp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0039)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0170, v0192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_sacatlp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0039);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0170 = v0039;
    v0192 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_sacatlp!* */
    v0170 = list2(v0192, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-1];
    {
        Lisp_Object v0013 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0013, v0170);
    }
/* error exit handlers */
v0014:
    popv(2);
    return nil;
}



/* Code for pasf_sacat */

static Lisp_Object MS_CDECL CC_pasf_sacat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object v0087, v0072, v0077;
    Lisp_Object v0097, v0039, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pasf_sacat");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0039 = va_arg(aa, Lisp_Object);
    v0097 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_sacat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0087 = v0097;
    v0072 = v0039;
    v0077 = v0000;
/* end of prologue */
    v0087 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0087);
}



/* Code for aex_pp */

static Lisp_Object CC_aex_pp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0028, v0101, v0107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_pp");
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
    v0028 = stack[0];
    fn = elt(env, 2); /* aex_ex */
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    fn = elt(env, 3); /* ratpoly_univarp */
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    if (v0028 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0028 = stack[0];
    fn = elt(env, 2); /* aex_ex */
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    fn = elt(env, 4); /* ratpoly_pp */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    v0028 = stack[0];
    fn = elt(env, 5); /* aex_ctx */
    v0107 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    v0101 = qvalue(elt(env, 1)); /* nil */
    v0028 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0094 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v0094, v0107, v0101, v0028);
    }
/* error exit handlers */
v0098:
    popv(3);
    return nil;
}



/* Code for look_for_rational */

static Lisp_Object MS_CDECL CC_look_for_rational(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0148, v0210, v0051;
    Lisp_Object fn;
    Lisp_Object v0097, v0039, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "look_for_rational");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0039 = va_arg(aa, Lisp_Object);
    v0097 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for look_for_rational");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0097,v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0039,v0097);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0097;
    stack[-1] = v0039;
    stack[-2] = v0000;
/* end of prologue */
    v0210 = stack[-1];
    v0148 = elt(env, 1); /* look_for_exponential */
    v0148 = get(v0210, v0148);
    env = stack[-3];
    if (v0148 == nil) goto v0003;
    v0148 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0148); }

v0003:
    v0148 = stack[0];
    v0210 = qcar(v0148);
    v0148 = elt(env, 3); /* sqrt */
    if (v0210 == v0148) goto v0107;
    v0148 = qvalue(elt(env, 2)); /* nil */
    goto v0012;

v0012:
    if (v0148 == nil) goto v0095;
    v0051 = stack[-2];
    v0210 = stack[-1];
    v0148 = (Lisp_Object)33; /* 2 */
    {
        popv(4);
        fn = elt(env, 6); /* look_for_rational1 */
        return (*qfnn(fn))(qenv(fn), 3, v0051, v0210, v0148);
    }

v0095:
    v0148 = stack[0];
    v0210 = qcar(v0148);
    v0148 = elt(env, 4); /* expt */
    if (v0210 == v0148) goto v0115;
    v0148 = qvalue(elt(env, 2)); /* nil */
    goto v0106;

v0106:
    if (v0148 == nil) goto v0177;
    v0051 = stack[-2];
    v0210 = stack[-1];
    v0148 = stack[0];
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcar(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcar(v0148);
    {
        popv(4);
        fn = elt(env, 6); /* look_for_rational1 */
        return (*qfnn(fn))(qenv(fn), 3, v0051, v0210, v0148);
    }

v0177:
    v0148 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0148); }

v0115:
    v0148 = stack[0];
    v0148 = qcdr(v0148);
    v0210 = qcar(v0148);
    v0148 = stack[-1];
    if (equal(v0210, v0148)) goto v0067;
    v0148 = qvalue(elt(env, 2)); /* nil */
    goto v0106;

v0067:
    v0148 = stack[0];
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcar(v0148);
    fn = elt(env, 7); /* listp */
    v0148 = (*qfn1(fn))(qenv(fn), v0148);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-3];
    if (v0148 == nil) goto v0092;
    v0148 = stack[0];
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcar(v0148);
    v0210 = qcar(v0148);
    v0148 = elt(env, 5); /* quotient */
    if (v0210 == v0148) goto v0182;
    v0148 = qvalue(elt(env, 2)); /* nil */
    goto v0106;

v0182:
    v0148 = stack[0];
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcar(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcar(v0148);
    if (is_number(v0148)) goto v0167;
    v0148 = qvalue(elt(env, 2)); /* nil */
    goto v0106;

v0167:
    v0148 = stack[0];
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcar(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcar(v0148);
    v0148 = (is_number(v0148) ? lisp_true : nil);
    goto v0106;

v0092:
    v0148 = qvalue(elt(env, 2)); /* nil */
    goto v0106;

v0107:
    v0148 = stack[0];
    v0148 = qcdr(v0148);
    v0210 = qcar(v0148);
    v0148 = stack[-1];
    v0148 = (equal(v0210, v0148) ? lisp_true : nil);
    goto v0012;
/* error exit handlers */
v0238:
    popv(4);
    return nil;
}



/* Code for decimal2internal */

static Lisp_Object CC_decimal2internal(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0039)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0096, v0161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for decimal2internal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0039);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0039;
    stack[-1] = v0000;
/* end of prologue */
    v0096 = stack[0];
    v0095 = (Lisp_Object)1; /* 0 */
    v0095 = (Lisp_Object)geq2(v0096, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    v0095 = v0095 ? lisp_true : nil;
    env = stack[-3];
    if (v0095 == nil) goto v0240;
    stack[-2] = elt(env, 1); /* !:rd!: */
    v0096 = (Lisp_Object)161; /* 10 */
    v0095 = stack[0];
    v0095 = Lexpt(nil, v0096, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-3];
    v0096 = times2(stack[-1], v0095);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    v0095 = (Lisp_Object)1; /* 0 */
    {
        Lisp_Object v0162 = stack[-2];
        popv(4);
        return list2star(v0162, v0096, v0095);
    }

v0240:
    v0161 = elt(env, 1); /* !:rd!: */
    v0096 = stack[-1];
    v0095 = (Lisp_Object)1; /* 0 */
    stack[-1] = list2star(v0161, v0096, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-3];
    v0095 = stack[0];
    v0095 = negate(v0095);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-3];
    {
        Lisp_Object v0015 = stack[-1];
        popv(4);
        fn = elt(env, 2); /* divide!-by!-power!-of!-ten */
        return (*qfn2(fn))(qenv(fn), v0015, v0095);
    }
/* error exit handlers */
v0164:
    popv(4);
    return nil;
}



/* Code for chksymmetries!&sub1 */

static Lisp_Object MS_CDECL CC_chksymmetriesGsub1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0117, v0118, v0090;
    Lisp_Object fn;
    Lisp_Object v0027, v0097, v0039, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "chksymmetries&sub1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0039 = va_arg(aa, Lisp_Object);
    v0097 = va_arg(aa, Lisp_Object);
    v0027 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for chksymmetries&sub1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0027,v0097,v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0039,v0097,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0027;
    v0117 = v0097;
    v0118 = v0039;
    v0090 = v0000;
/* end of prologue */
    v0117 = Lsubst(nil, 3, v0090, v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-2];
    stack[-1] = v0117;
    v0117 = stack[0];
    if (v0117 == nil) goto v0003;
    v0118 = stack[-1];
    v0117 = stack[0];
    fn = elt(env, 3); /* indxsymp */
    v0117 = (*qfn2(fn))(qenv(fn), v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-2];
    goto v0013;

v0013:
    if (!(v0117 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0117 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0117); }

v0003:
    v0117 = qvalue(elt(env, 1)); /* t */
    goto v0013;
/* error exit handlers */
v0099:
    popv(3);
    return nil;
}



/* Code for free */

static Lisp_Object CC_free(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for free");
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
    v0170 = stack[0];
    v0170 = qcdr(v0170);
    v0170 = qcar(v0170);
    fn = elt(env, 2); /* freeind */
    v0170 = (*qfn1(fn))(qenv(fn), v0170);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-1];
    if (v0170 == nil) goto v0088;
    v0170 = stack[0];
    v0170 = qcdr(v0170);
    v0170 = qcdr(v0170);
    v0170 = qcar(v0170);
    {
        popv(2);
        fn = elt(env, 2); /* freeind */
        return (*qfn1(fn))(qenv(fn), v0170);
    }

v0088:
    v0170 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0170); }
/* error exit handlers */
v0012:
    popv(2);
    return nil;
}



/* Code for prepcadr */

static Lisp_Object CC_prepcadr(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0072;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepcadr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0072 = v0000;
/* end of prologue */
    v0072 = qcdr(v0072);
    v0072 = qcar(v0072);
    {
        fn = elt(env, 1); /* prepsq */
        return (*qfn1(fn))(qenv(fn), v0072);
    }
}



/* Code for njets */

static Lisp_Object CC_njets(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0039)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0192, v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for njets");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0039);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0192 = v0039;
    v0012 = v0000;
/* end of prologue */
    stack[-1] = v0192;
    stack[0] = v0192;
    v0192 = v0012;
    v0192 = sub1(v0192);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    v0192 = plus2(stack[0], v0192);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    {
        Lisp_Object v0038 = stack[-1];
        popv(3);
        fn = elt(env, 1); /* combin */
        return (*qfn2(fn))(qenv(fn), v0038, v0192);
    }
/* error exit handlers */
v0003:
    popv(3);
    return nil;
}



/* Code for st_flatten */

static Lisp_Object CC_st_flatten(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0100, v0164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for st_flatten");
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
    v0164 = v0000;
/* end of prologue */
    v0100 = v0164;
    v0100 = qcdr(v0100);
    v0100 = qcar(v0100);
    if (is_number(v0100)) goto v0088;
    v0100 = v0164;
    v0100 = qcdr(v0100);
    stack[-3] = v0100;
    goto v0170;

v0170:
    v0100 = stack[-3];
    if (v0100 == nil) goto v0038;
    v0100 = stack[-3];
    v0100 = qcar(v0100);
    v0100 = CC_st_flatten(env, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-4];
    fn = elt(env, 2); /* copy */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-4];
    stack[-2] = v0100;
    v0100 = stack[-2];
    fn = elt(env, 3); /* lastpair */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-4];
    stack[-1] = v0100;
    v0100 = stack[-3];
    v0100 = qcdr(v0100);
    stack[-3] = v0100;
    v0100 = stack[-1];
    if (!consp(v0100)) goto v0170;
    else goto v0192;

v0192:
    v0100 = stack[-3];
    if (v0100 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0100 = stack[-3];
    v0100 = qcar(v0100);
    v0100 = CC_st_flatten(env, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-4];
    fn = elt(env, 2); /* copy */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-4];
    v0100 = Lrplacd(nil, stack[0], v0100);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-4];
    v0100 = stack[-1];
    fn = elt(env, 3); /* lastpair */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-4];
    stack[-1] = v0100;
    v0100 = stack[-3];
    v0100 = qcdr(v0100);
    stack[-3] = v0100;
    goto v0192;

v0038:
    v0100 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0100); }

v0088:
    v0100 = v0164;
    v0100 = qcdr(v0100);
    { popv(5); return onevalue(v0100); }
/* error exit handlers */
v0187:
    popv(5);
    return nil;
}



/* Code for prim!-part */

static Lisp_Object CC_primKpart(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prim-part");
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
    v0022 = v0000;
/* end of prologue */
    stack[0] = v0022;
    fn = elt(env, 1); /* comfac */
    v0022 = (*qfn1(fn))(qenv(fn), v0022);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    fn = elt(env, 2); /* comfac!-to!-poly */
    v0022 = (*qfn1(fn))(qenv(fn), v0022);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    {
        Lisp_Object v0042 = stack[0];
        popv(2);
        fn = elt(env, 3); /* quotf1 */
        return (*qfn2(fn))(qenv(fn), v0042, v0022);
    }
/* error exit handlers */
v0041:
    popv(2);
    return nil;
}



/* Code for gcdlist */

static Lisp_Object CC_gcdlist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0331, v0332, v0333;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdlist");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0331 = stack[0];
    if (v0331 == nil) goto v0088;
    v0331 = stack[0];
    v0331 = qcdr(v0331);
    if (v0331 == nil) goto v0076;
    v0331 = stack[0];
    v0331 = qcar(v0331);
    if (!consp(v0331)) goto v0192;
    v0331 = stack[0];
    v0331 = qcar(v0331);
    v0331 = qcar(v0331);
    v0331 = (consp(v0331) ? nil : lisp_true);
    goto v0170;

v0170:
    if (v0331 == nil) goto v0203;
    v0331 = stack[0];
    v0332 = qcdr(v0331);
    v0331 = stack[0];
    v0331 = qcar(v0331);
    {
        popv(15);
        fn = elt(env, 4); /* gcdld */
        return (*qfn2(fn))(qenv(fn), v0332, v0331);
    }

v0203:
    stack[-1] = nil;
    goto v0240;

v0240:
    v0331 = stack[0];
    if (v0331 == nil) goto v0019;
    v0331 = stack[0];
    v0331 = qcar(v0331);
    if (v0331 == nil) goto v0106;
    v0331 = stack[0];
    v0331 = qcar(v0331);
    if (!consp(v0331)) goto v0162;
    v0331 = stack[0];
    v0331 = qcar(v0331);
    v0331 = qcar(v0331);
    v0331 = (consp(v0331) ? nil : lisp_true);
    goto v0164;

v0164:
    if (v0331 == nil) goto v0065;
    v0331 = stack[0];
    stack[-2] = qcdr(v0331);
    v0331 = stack[-1];
    fn = elt(env, 5); /* mapcarcar */
    v0332 = (*qfn1(fn))(qenv(fn), v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = stack[0];
    v0331 = qcar(v0331);
    fn = elt(env, 4); /* gcdld */
    v0331 = (*qfn2(fn))(qenv(fn), v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    fn = elt(env, 4); /* gcdld */
    v0331 = (*qfn2(fn))(qenv(fn), stack[-2], v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = ncons(v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = ncons(v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    stack[-1] = v0331;
    v0331 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0331;
    goto v0240;

v0065:
    v0331 = stack[0];
    stack[-2] = qcar(v0331);
    v0331 = stack[0];
    v0331 = qcar(v0331);
    fn = elt(env, 6); /* powers1 */
    v0332 = (*qfn1(fn))(qenv(fn), v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = stack[-1];
    v0331 = acons(stack[-2], v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    stack[-1] = v0331;
    v0331 = stack[0];
    v0331 = qcdr(v0331);
    stack[0] = v0331;
    goto v0240;

v0162:
    v0331 = qvalue(elt(env, 2)); /* t */
    goto v0164;

v0106:
    v0331 = stack[0];
    v0331 = qcdr(v0331);
    stack[0] = v0331;
    goto v0240;

v0019:
    v0331 = stack[-1];
    if (v0331 == nil) goto v0167;
    v0331 = stack[-1];
    v0331 = qcdr(v0331);
    if (v0331 == nil) goto v0335;
    v0331 = qvalue(elt(env, 1)); /* nil */
    stack[-13] = v0331;
    v0331 = qvalue(elt(env, 1)); /* nil */
    stack[-12] = v0331;
    v0331 = stack[-1];
    stack[-11] = v0331;
    v0331 = stack[-11];
    if (v0331 == nil) goto v0197;
    v0331 = stack[-11];
    v0331 = qcar(v0331);
    stack[-7] = v0331;
    stack[-6] = nil;
    v0331 = stack[-7];
    v0331 = qcdr(v0331);
    stack[-5] = v0331;
    v0331 = stack[-5];
    if (v0331 == nil) goto v0336;
    v0331 = stack[-5];
    v0331 = qcar(v0331);
    stack[-1] = v0331;
    v0331 = stack[-1];
    v0333 = qcar(v0331);
    v0331 = stack[-1];
    v0331 = qcdr(v0331);
    v0332 = qcdr(v0331);
    v0331 = stack[-6];
    v0331 = acons(v0333, v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    stack[-6] = v0331;
    v0331 = stack[-1];
    stack[0] = qcar(v0331);
    v0331 = stack[-1];
    v0331 = qcdr(v0331);
    v0332 = qcar(v0331);
    v0331 = stack[-1];
    v0331 = qcdr(v0331);
    v0331 = qcdr(v0331);
    v0331 = difference2(v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = cons(stack[0], v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = ncons(v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    stack[-3] = v0331;
    stack[-4] = v0331;
    goto v0051;

v0051:
    v0331 = stack[-5];
    v0331 = qcdr(v0331);
    stack[-5] = v0331;
    v0331 = stack[-5];
    if (v0331 == nil) goto v0191;
    stack[-2] = stack[-3];
    v0331 = stack[-5];
    v0331 = qcar(v0331);
    stack[-1] = v0331;
    v0331 = stack[-1];
    v0333 = qcar(v0331);
    v0331 = stack[-1];
    v0331 = qcdr(v0331);
    v0332 = qcdr(v0331);
    v0331 = stack[-6];
    v0331 = acons(v0333, v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    stack[-6] = v0331;
    v0331 = stack[-1];
    stack[0] = qcar(v0331);
    v0331 = stack[-1];
    v0331 = qcdr(v0331);
    v0332 = qcar(v0331);
    v0331 = stack[-1];
    v0331 = qcdr(v0331);
    v0331 = qcdr(v0331);
    v0331 = difference2(v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = cons(stack[0], v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = ncons(v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = Lrplacd(nil, stack[-2], v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = stack[-3];
    v0331 = qcdr(v0331);
    stack[-3] = v0331;
    goto v0051;

v0191:
    v0331 = stack[-4];
    goto v0210;

v0210:
    stack[0] = v0331;
    v0331 = stack[-7];
    v0331 = qcar(v0331);
    fn = elt(env, 7); /* numeric!-content */
    v0331 = (*qfn1(fn))(qenv(fn), v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    stack[-1] = v0331;
    v0331 = stack[-12];
    if (v0331 == nil) goto v0337;
    v0332 = stack[-13];
    v0331 = stack[-6];
    fn = elt(env, 8); /* vintersection */
    v0331 = (*qfn2(fn))(qenv(fn), v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    stack[-13] = v0331;
    v0332 = stack[-12];
    v0331 = stack[-1];
    fn = elt(env, 9); /* gcddd */
    v0331 = (*qfn2(fn))(qenv(fn), v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    stack[-12] = v0331;
    goto v0222;

v0222:
    v0331 = stack[-6];
    stack[-2] = v0331;
    goto v0338;

v0338:
    v0331 = stack[-2];
    if (v0331 == nil) goto v0339;
    v0331 = stack[-2];
    v0331 = qcar(v0331);
    v0333 = v0331;
    v0331 = v0333;
    v0332 = qcdr(v0331);
    v0331 = (Lisp_Object)1; /* 0 */
    if (v0332 == v0331) goto v0233;
    v0331 = v0333;
    v0331 = qcar(v0331);
    v0332 = v0333;
    v0332 = qcdr(v0332);
    fn = elt(env, 10); /* mksp */
    v0332 = (*qfn2(fn))(qenv(fn), v0331, v0332);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = (Lisp_Object)17; /* 1 */
    v0331 = cons(v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = ncons(v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    fn = elt(env, 11); /* multf */
    v0331 = (*qfn2(fn))(qenv(fn), stack[-1], v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    stack[-1] = v0331;
    goto v0233;

v0233:
    v0331 = stack[-2];
    v0331 = qcdr(v0331);
    stack[-2] = v0331;
    goto v0338;

v0339:
    v0331 = stack[-7];
    v0333 = qcar(v0331);
    v0332 = stack[-1];
    v0331 = elt(env, 3); /* "Term content division failed" */
    fn = elt(env, 12); /* quotfail1 */
    v0332 = (*qfnn(fn))(qenv(fn), 3, v0333, v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = stack[0];
    v0331 = cons(v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = ncons(v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    stack[-9] = v0331;
    stack[-10] = v0331;
    goto v0123;

v0123:
    v0331 = stack[-11];
    v0331 = qcdr(v0331);
    stack[-11] = v0331;
    v0331 = stack[-11];
    if (v0331 == nil) goto v0340;
    stack[-8] = stack[-9];
    v0331 = stack[-11];
    v0331 = qcar(v0331);
    stack[-7] = v0331;
    stack[-6] = nil;
    v0331 = stack[-7];
    v0331 = qcdr(v0331);
    stack[-5] = v0331;
    v0331 = stack[-5];
    if (v0331 == nil) goto v0341;
    v0331 = stack[-5];
    v0331 = qcar(v0331);
    stack[-1] = v0331;
    v0331 = stack[-1];
    v0333 = qcar(v0331);
    v0331 = stack[-1];
    v0331 = qcdr(v0331);
    v0332 = qcdr(v0331);
    v0331 = stack[-6];
    v0331 = acons(v0333, v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    stack[-6] = v0331;
    v0331 = stack[-1];
    stack[0] = qcar(v0331);
    v0331 = stack[-1];
    v0331 = qcdr(v0331);
    v0332 = qcar(v0331);
    v0331 = stack[-1];
    v0331 = qcdr(v0331);
    v0331 = qcdr(v0331);
    v0331 = difference2(v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = cons(stack[0], v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = ncons(v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    stack[-3] = v0331;
    stack[-4] = v0331;
    goto v0342;

v0342:
    v0331 = stack[-5];
    v0331 = qcdr(v0331);
    stack[-5] = v0331;
    v0331 = stack[-5];
    if (v0331 == nil) goto v0343;
    stack[-2] = stack[-3];
    v0331 = stack[-5];
    v0331 = qcar(v0331);
    stack[-1] = v0331;
    v0331 = stack[-1];
    v0333 = qcar(v0331);
    v0331 = stack[-1];
    v0331 = qcdr(v0331);
    v0332 = qcdr(v0331);
    v0331 = stack[-6];
    v0331 = acons(v0333, v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    stack[-6] = v0331;
    v0331 = stack[-1];
    stack[0] = qcar(v0331);
    v0331 = stack[-1];
    v0331 = qcdr(v0331);
    v0332 = qcar(v0331);
    v0331 = stack[-1];
    v0331 = qcdr(v0331);
    v0331 = qcdr(v0331);
    v0331 = difference2(v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = cons(stack[0], v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = ncons(v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = Lrplacd(nil, stack[-2], v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = stack[-3];
    v0331 = qcdr(v0331);
    stack[-3] = v0331;
    goto v0342;

v0343:
    v0331 = stack[-4];
    goto v0344;

v0344:
    stack[0] = v0331;
    v0331 = stack[-7];
    v0331 = qcar(v0331);
    fn = elt(env, 7); /* numeric!-content */
    v0331 = (*qfn1(fn))(qenv(fn), v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    stack[-1] = v0331;
    v0331 = stack[-12];
    if (v0331 == nil) goto v0345;
    v0332 = stack[-13];
    v0331 = stack[-6];
    fn = elt(env, 8); /* vintersection */
    v0331 = (*qfn2(fn))(qenv(fn), v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    stack[-13] = v0331;
    v0332 = stack[-12];
    v0331 = stack[-1];
    fn = elt(env, 9); /* gcddd */
    v0331 = (*qfn2(fn))(qenv(fn), v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    stack[-12] = v0331;
    goto v0346;

v0346:
    v0331 = stack[-6];
    stack[-2] = v0331;
    goto v0347;

v0347:
    v0331 = stack[-2];
    if (v0331 == nil) goto v0348;
    v0331 = stack[-2];
    v0331 = qcar(v0331);
    v0333 = v0331;
    v0331 = v0333;
    v0332 = qcdr(v0331);
    v0331 = (Lisp_Object)1; /* 0 */
    if (v0332 == v0331) goto v0349;
    v0331 = v0333;
    v0331 = qcar(v0331);
    v0332 = v0333;
    v0332 = qcdr(v0332);
    fn = elt(env, 10); /* mksp */
    v0332 = (*qfn2(fn))(qenv(fn), v0331, v0332);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = (Lisp_Object)17; /* 1 */
    v0331 = cons(v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = ncons(v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    fn = elt(env, 11); /* multf */
    v0331 = (*qfn2(fn))(qenv(fn), stack[-1], v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    stack[-1] = v0331;
    goto v0349;

v0349:
    v0331 = stack[-2];
    v0331 = qcdr(v0331);
    stack[-2] = v0331;
    goto v0347;

v0348:
    v0331 = stack[-7];
    v0333 = qcar(v0331);
    v0332 = stack[-1];
    v0331 = elt(env, 3); /* "Term content division failed" */
    fn = elt(env, 12); /* quotfail1 */
    v0332 = (*qfnn(fn))(qenv(fn), 3, v0333, v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = stack[0];
    v0331 = cons(v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = ncons(v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = Lrplacd(nil, stack[-8], v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = stack[-9];
    v0331 = qcdr(v0331);
    stack[-9] = v0331;
    goto v0123;

v0345:
    v0331 = stack[-6];
    stack[-13] = v0331;
    v0331 = stack[-1];
    stack[-12] = v0331;
    goto v0346;

v0341:
    v0331 = qvalue(elt(env, 1)); /* nil */
    goto v0344;

v0340:
    v0331 = stack[-10];
    goto v0122;

v0122:
    stack[0] = v0331;
    v0331 = stack[-13];
    stack[-1] = v0331;
    goto v0350;

v0350:
    v0331 = stack[-1];
    if (v0331 == nil) goto v0351;
    v0331 = stack[-1];
    v0331 = qcar(v0331);
    stack[-2] = stack[-12];
    v0332 = v0331;
    v0332 = qcar(v0332);
    v0331 = qcdr(v0331);
    fn = elt(env, 10); /* mksp */
    v0332 = (*qfn2(fn))(qenv(fn), v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = (Lisp_Object)17; /* 1 */
    v0331 = cons(v0332, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    v0331 = ncons(v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    fn = elt(env, 11); /* multf */
    v0331 = (*qfn2(fn))(qenv(fn), stack[-2], v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    stack[-12] = v0331;
    v0331 = stack[-1];
    v0331 = qcdr(v0331);
    stack[-1] = v0331;
    goto v0350;

v0351:
    stack[-1] = stack[-12];
    v0331 = stack[0];
    fn = elt(env, 13); /* gcdlist1 */
    v0331 = (*qfn1(fn))(qenv(fn), v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    fn = elt(env, 11); /* multf */
    v0331 = (*qfn2(fn))(qenv(fn), stack[-1], v0331);
    nil = C_nil;
    if (exception_pending()) goto v0334;
    env = stack[-14];
    {
        popv(15);
        fn = elt(env, 14); /* poly!-abs */
        return (*qfn1(fn))(qenv(fn), v0331);
    }

v0337:
    v0331 = stack[-6];
    stack[-13] = v0331;
    v0331 = stack[-1];
    stack[-12] = v0331;
    goto v0222;

v0336:
    v0331 = qvalue(elt(env, 1)); /* nil */
    goto v0210;

v0197:
    v0331 = qvalue(elt(env, 1)); /* nil */
    goto v0122;

v0335:
    v0331 = stack[-1];
    v0331 = qcar(v0331);
    v0331 = qcar(v0331);
    {
        popv(15);
        fn = elt(env, 14); /* poly!-abs */
        return (*qfn1(fn))(qenv(fn), v0331);
    }

v0167:
    v0331 = qvalue(elt(env, 1)); /* nil */
    { popv(15); return onevalue(v0331); }

v0192:
    v0331 = qvalue(elt(env, 2)); /* t */
    goto v0170;

v0076:
    v0331 = stack[0];
    v0331 = qcar(v0331);
    {
        popv(15);
        fn = elt(env, 14); /* poly!-abs */
        return (*qfn1(fn))(qenv(fn), v0331);
    }

v0088:
    v0331 = qvalue(elt(env, 1)); /* nil */
    { popv(15); return onevalue(v0331); }
/* error exit handlers */
v0334:
    popv(15);
    return nil;
}



/* Code for vdp_putprop */

static Lisp_Object MS_CDECL CC_vdp_putprop(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0103, v0106, v0066, v0080, v0095;
    Lisp_Object v0097, v0039, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vdp_putprop");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0039 = va_arg(aa, Lisp_Object);
    v0097 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdp_putprop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0097,v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0039,v0097);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0066 = v0097;
    v0080 = v0039;
    stack[0] = v0000;
/* end of prologue */
    v0103 = stack[0];
    v0103 = qcdr(v0103);
    v0103 = qcdr(v0103);
    v0103 = qcdr(v0103);
    v0103 = qcdr(v0103);
    v0106 = v0103;
    v0095 = v0080;
    v0103 = v0106;
    v0103 = qcar(v0103);
    v0103 = Latsoc(nil, v0095, v0103);
    v0095 = v0103;
    v0103 = v0095;
    if (v0103 == nil) goto v0030;
    v0103 = v0095;
    v0106 = v0066;
    v0103 = Lrplacd(nil, v0103, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v0030:
    stack[-1] = v0106;
    v0103 = v0080;
    v0106 = qcar(v0106);
    v0103 = acons(v0103, v0066, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-2];
    v0103 = Lrplaca(nil, stack[-1], v0103);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v0031:
    popv(3);
    return nil;
}



/* Code for ofsf_at2ir */

static Lisp_Object CC_ofsf_at2ir(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0039)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0064, v0153, v0352;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_at2ir");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0039,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0039);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0039;
    v0153 = v0000;
/* end of prologue */
    v0064 = v0153;
    v0064 = qcar(v0064);
    stack[-4] = v0064;
    v0064 = v0153;
    v0064 = qcdr(v0064);
    v0064 = qcar(v0064);
    stack[-2] = v0064;
    stack[0] = v0064;
    goto v0026;

v0026:
    v0064 = stack[0];
    if (!consp(v0064)) goto v0003;
    v0064 = stack[0];
    v0064 = qcar(v0064);
    v0064 = (consp(v0064) ? nil : lisp_true);
    goto v0013;

v0013:
    if (v0064 == nil) goto v0170;
    stack[-1] = stack[-2];
    v0064 = stack[0];
    fn = elt(env, 3); /* negf */
    v0064 = (*qfn1(fn))(qenv(fn), v0064);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    fn = elt(env, 4); /* addf */
    v0064 = (*qfn2(fn))(qenv(fn), stack[-1], v0064);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    stack[-2] = v0064;
    v0064 = stack[-2];
    fn = elt(env, 5); /* sfto_dcontentf */
    v0064 = (*qfn1(fn))(qenv(fn), v0064);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    stack[-1] = v0064;
    v0153 = stack[-2];
    v0064 = stack[-1];
    fn = elt(env, 6); /* quotf */
    v0064 = (*qfn2(fn))(qenv(fn), v0153, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    stack[-2] = v0064;
    v0153 = stack[0];
    v0064 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0153, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    v0153 = stack[-1];
    v0064 = (Lisp_Object)17; /* 1 */
    v0064 = cons(v0153, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    fn = elt(env, 7); /* quotsq */
    v0064 = (*qfn2(fn))(qenv(fn), stack[0], v0064);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    stack[0] = v0064;
    stack[-1] = stack[-2];
    v0352 = stack[-3];
    v0153 = stack[-4];
    v0064 = stack[0];
    v0064 = list2star(v0352, v0153, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    v0153 = qvalue(elt(env, 2)); /* nil */
    {
        Lisp_Object v0229 = stack[-1];
        popv(6);
        return list2star(v0229, v0064, v0153);
    }

v0170:
    v0064 = stack[0];
    v0064 = qcdr(v0064);
    stack[0] = v0064;
    goto v0026;

v0003:
    v0064 = qvalue(elt(env, 1)); /* t */
    goto v0013;
/* error exit handlers */
v0082:
    popv(6);
    return nil;
}



/* Code for idsort */

static Lisp_Object CC_idsort(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0169, v0040;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for idsort");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0169 = v0000;
/* end of prologue */
    v0040 = v0169;
    v0169 = elt(env, 1); /* idcompare */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v0040, v0169);
    }
}



setup_type const u35_setup[] =
{
    {"simp-prop-dist",          CC_simpKpropKdist,too_many_1,  wrong_no_1},
    {"lambda_mwvup4_9",         too_few_2,      CC_lambda_mwvup4_9,wrong_no_2},
    {"lambda_mwvup4_8",         too_few_2,      CC_lambda_mwvup4_8,wrong_no_2},
    {"tidysqrtf",               CC_tidysqrtf,   too_many_1,    wrong_no_1},
    {"get_dimension_in",        CC_get_dimension_in,too_many_1,wrong_no_1},
    {"pasf_coeflst",            too_few_2,      CC_pasf_coeflst,wrong_no_2},
    {"vdpsimpcont",             CC_vdpsimpcont, too_many_1,    wrong_no_1},
    {"xpartitk",                CC_xpartitk,    too_many_1,    wrong_no_1},
    {"lndepends",               too_few_2,      CC_lndepends,  wrong_no_2},
    {"color-roads",             too_few_2,      CC_colorKroads,wrong_no_2},
    {"gcdf2",                   too_few_2,      CC_gcdf2,      wrong_no_2},
    {"red_redpol",              too_few_2,      CC_red_redpol, wrong_no_2},
    {"baglistp",                CC_baglistp,    too_many_1,    wrong_no_1},
    {"xquotient-mod-p",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_xquotientKmodKp},
    {"change+sq+to+int",        CC_changeLsqLtoLint,too_many_1,wrong_no_1},
    {"fctrf",                   CC_fctrf,       too_many_1,    wrong_no_1},
    {"ps:set-term",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_psTsetKterm},
    {"crnprimp",                CC_crnprimp,    too_many_1,    wrong_no_1},
    {"simpdf",                  CC_simpdf,      too_many_1,    wrong_no_1},
    {"copy_vect",               too_few_2,      CC_copy_vect,  wrong_no_2},
    {"groebsaveltermbc",        CC_groebsaveltermbc,too_many_1,wrong_no_1},
    {"multiply-by-power-of-ten",too_few_2,      CC_multiplyKbyKpowerKofKten,wrong_no_2},
    {"diff_vertex",             too_few_2,      CC_diff_vertex,wrong_no_2},
    {"dfp-rule-found",          too_few_2,      CC_dfpKruleKfound,wrong_no_2},
    {"equiv-coeffs",            too_few_2,      CC_equivKcoeffs,wrong_no_2},
    {"addnew",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_addnew},
    {"mchsarg",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mchsarg},
    {"mri_simplat1",            too_few_2,      CC_mri_simplat1,wrong_no_2},
    {"rl_sacatlp",              too_few_2,      CC_rl_sacatlp, wrong_no_2},
    {"pasf_sacat",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_sacat},
    {"aex_pp",                  CC_aex_pp,      too_many_1,    wrong_no_1},
    {"look_for_rational",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_look_for_rational},
    {"decimal2internal",        too_few_2,      CC_decimal2internal,wrong_no_2},
    {"chksymmetries&sub1",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_chksymmetriesGsub1},
    {"free",                    CC_free,        too_many_1,    wrong_no_1},
    {"prepcadr",                CC_prepcadr,    too_many_1,    wrong_no_1},
    {"njets",                   too_few_2,      CC_njets,      wrong_no_2},
    {"st_flatten",              CC_st_flatten,  too_many_1,    wrong_no_1},
    {"prim-part",               CC_primKpart,   too_many_1,    wrong_no_1},
    {"gcdlist",                 CC_gcdlist,     too_many_1,    wrong_no_1},
    {"vdp_putprop",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdp_putprop},
    {"ofsf_at2ir",              too_few_2,      CC_ofsf_at2ir, wrong_no_2},
    {"idsort",                  CC_idsort,      too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u35", (two_args *)"12051 3258208 4626909", 0}
};

/* end of generated code */
