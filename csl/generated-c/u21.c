
/* $destdir\u21.c        Machine generated C code */

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


/* Code for ev_invlexcomp */

static Lisp_Object CC_ev_invlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v16;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_invlexcomp");
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

v17:
    v15 = stack[-1];
    if (v15 == nil) goto v18;
    v15 = stack[-1];
    v16 = qcar(v15);
    v15 = stack[0];
    v15 = qcar(v15);
    v15 = Leqn(nil, v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-3];
    if (v15 == nil) goto v20;
    v15 = stack[-1];
    v16 = qcdr(v15);
    v15 = stack[0];
    v15 = qcdr(v15);
    stack[-1] = v16;
    stack[0] = v15;
    goto v17;

v20:
    v15 = stack[-1];
    v16 = qcdr(v15);
    v15 = stack[0];
    v15 = qcdr(v15);
    v15 = CC_ev_invlexcomp(env, v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-3];
    stack[-2] = v15;
    v16 = stack[-2];
    v15 = (Lisp_Object)1; /* 0 */
    v15 = Leqn(nil, v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-3];
    if (v15 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v15 = stack[0];
    v16 = qcar(v15);
    v15 = stack[-1];
    v15 = qcar(v15);
    v15 = Leqn(nil, v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v19;
    if (v15 == nil) goto v21;
    v15 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v15); }

v21:
    v15 = stack[0];
    v16 = qcar(v15);
    v15 = stack[-1];
    v15 = qcar(v15);
    if (((int32_t)(v16)) > ((int32_t)(v15))) goto v22;
    v15 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v15); }

v22:
    v15 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v15); }

v18:
    v15 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v15); }
/* error exit handlers */
v19:
    popv(4);
    return nil;
}



/* Code for unaryir */

static Lisp_Object CC_unaryir(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unaryir");
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
    v29 = qvalue(elt(env, 1)); /* atts */
    v28 = elt(env, 2); /* name */
    fn = elt(env, 4); /* find */
    v28 = (*qfn2(fn))(qenv(fn), v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    v28 = Lintern(nil, v28);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    stack[-2] = v28;
    v29 = qvalue(elt(env, 1)); /* atts */
    v28 = elt(env, 3); /* cd */
    fn = elt(env, 4); /* find */
    v28 = (*qfn2(fn))(qenv(fn), v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    v28 = Lintern(nil, v28);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    v29 = v28;
    v28 = stack[-1];
    if (equal(v29, v28)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v28 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); /* encodeir */
        return (*qfn1(fn))(qenv(fn), v28);
    }
/* error exit handlers */
v30:
    popv(4);
    return nil;
}



/* Code for ps!:prepfn!: */

static Lisp_Object CC_psTprepfnT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v8;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:prepfn:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    return onevalue(v8);
}



/* Code for quoteequation */

static Lisp_Object CC_quoteequation(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v8;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quoteequation");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    v8 = elt(env, 1); /* equation */
    return onevalue(v8);
}



/* Code for gcompatible */

static Lisp_Object CC_gcompatible(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcompatible");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v33 = v1;
    v34 = v0;
/* end of prologue */
    v32 = qvalue(elt(env, 1)); /* gmodule!* */
    if (v32 == nil) goto v35;
    v32 = v34;
    v32 = qcdr(v32);
    v34 = qcar(v32);
    v32 = v33;
    v32 = qcdr(v32);
    v33 = qcar(v32);
    v32 = qvalue(elt(env, 1)); /* gmodule!* */
    {
        fn = elt(env, 3); /* gevcompatible1 */
        return (*qfnn(fn))(qenv(fn), 3, v34, v33, v32);
    }

v35:
    v32 = qvalue(elt(env, 2)); /* t */
    return onevalue(v32);
}



/* Code for dipsimpcont */

static Lisp_Object CC_dipsimpcont(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipsimpcont");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v37 = v0;
/* end of prologue */
    v36 = qvalue(elt(env, 1)); /* !*vdpinteger */
    if (!(v36 == nil)) goto v24;
    v36 = qvalue(elt(env, 2)); /* !*groebdivide */
    if (v36 == nil) goto v24;
    v36 = v37;
    {
        fn = elt(env, 3); /* dipsimpcontr */
        return (*qfn1(fn))(qenv(fn), v36);
    }

v24:
    v36 = v37;
    {
        fn = elt(env, 4); /* dipsimpconti */
        return (*qfn1(fn))(qenv(fn), v36);
    }
}



/* Code for memqcar */

static Lisp_Object CC_memqcar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v31, v39;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for memqcar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v31 = v1;
    v39 = v0;
/* end of prologue */
    v38 = v39;
    if (!consp(v38)) goto v37;
    v38 = v39;
    v38 = qcar(v38);
    v38 = Lmemq(nil, v38, v31);
    return onevalue(v38);

v37:
    v38 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v38);
}



/* Code for random */

static Lisp_Object CC_random(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for random");
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
    v66 = stack[-3];
    if (is_number(v66)) goto v68;
    v66 = qvalue(elt(env, 1)); /* t */
    goto v69;

v69:
    if (v66 == nil) goto v70;
    v67 = stack[-3];
    v66 = elt(env, 2); /* "positive number" */
    fn = elt(env, 6); /* typerr */
    v66 = (*qfn2(fn))(qenv(fn), v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    goto v70;

v70:
    v66 = stack[-3];
    v66 = Lfloatp(nil, v66);
    env = stack[-5];
    if (v66 == nil) goto v22;
    fn = elt(env, 7); /* next!-random!-number */
    v66 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    v67 = Lfloat(nil, v66);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    v66 = qvalue(elt(env, 3)); /* unidev_fac!* */
    v66 = times2(v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    stack[-2] = v66;
    fn = elt(env, 7); /* next!-random!-number */
    v66 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    v67 = Lfloat(nil, v66);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    v66 = stack[-2];
    stack[0] = plus2(v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    v67 = qvalue(elt(env, 3)); /* unidev_fac!* */
    v66 = stack[-3];
    v66 = times2(v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v71;
    {
        Lisp_Object v72 = stack[0];
        popv(6);
        return times2(v72, v66);
    }

v22:
    fn = elt(env, 7); /* next!-random!-number */
    v66 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    stack[-2] = v66;
    v66 = qvalue(elt(env, 4)); /* randommodulus!* */
    stack[-4] = v66;
    goto v73;

v73:
    v67 = stack[-4];
    v66 = stack[-3];
    v66 = (Lisp_Object)lessp2(v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v71;
    v66 = v66 ? lisp_true : nil;
    env = stack[-5];
    if (v66 == nil) goto v74;
    v67 = stack[-4];
    v66 = qvalue(elt(env, 4)); /* randommodulus!* */
    v66 = times2(v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    stack[-4] = v66;
    v67 = qvalue(elt(env, 4)); /* randommodulus!* */
    v66 = stack[-2];
    stack[0] = times2(v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    fn = elt(env, 7); /* next!-random!-number */
    v66 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    v66 = plus2(stack[0], v66);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    stack[-2] = v66;
    goto v73;

v74:
    stack[-1] = stack[-2];
    stack[0] = stack[-4];
    v67 = stack[-4];
    v66 = stack[-3];
    v66 = Cremainder(v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    v66 = difference2(stack[0], v66);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    v66 = (Lisp_Object)lessp2(stack[-1], v66);
    nil = C_nil;
    if (exception_pending()) goto v71;
    v66 = v66 ? lisp_true : nil;
    env = stack[-5];
    if (v66 == nil) goto v22;
    v67 = stack[-2];
    v66 = stack[-3];
    popv(6);
    return Cremainder(v67, v66);

v68:
    v67 = stack[-3];
    v66 = (Lisp_Object)1; /* 0 */
    v66 = (Lisp_Object)lesseq2(v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v71;
    v66 = v66 ? lisp_true : nil;
    env = stack[-5];
    goto v69;
/* error exit handlers */
v71:
    popv(6);
    return nil;
}



/* Code for assert_structstat */

static Lisp_Object MS_CDECL CC_assert_structstat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v92, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_structstat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_structstat");
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
    fn = elt(env, 17); /* scan */
    v91 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    stack[0] = v91;
    fn = elt(env, 17); /* scan */
    v91 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v92 = qvalue(elt(env, 1)); /* cursym!* */
    v91 = elt(env, 2); /* delim */
    v91 = Lflagp(nil, v92, v91);
    env = stack[-4];
    if (v91 == nil) goto v60;
    v91 = qvalue(elt(env, 3)); /* !*assert */
    if (v91 == nil) goto v31;
    v91 = qvalue(elt(env, 5)); /* !*msg */
    if (v91 == nil) goto v32;
    v91 = qvalue(elt(env, 5)); /* !*msg */
    if (v91 == nil) goto v32;
    stack[-1] = elt(env, 6); /* "***" */
    v93 = elt(env, 7); /* "type" */
    v92 = stack[0];
    v91 = elt(env, 8); /* "is not checked" */
    v91 = list3(v93, v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    fn = elt(env, 18); /* lpriw */
    v91 = (*qfn2(fn))(qenv(fn), stack[-1], v91);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    goto v32;

v32:
    v91 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v91); }

v31:
    v91 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v91); }

v60:
    v92 = qvalue(elt(env, 1)); /* cursym!* */
    v91 = elt(env, 9); /* checked */
    if (v92 == v91) goto v15;
    v91 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v91 == nil)) goto v59;
    v92 = elt(env, 11); /* "expecting 'checked by' in struct but found" 
*/
    v91 = qvalue(elt(env, 1)); /* cursym!* */
    v91 = list2(v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    fn = elt(env, 19); /* lprie */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    goto v59;

v59:
    v91 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    goto v15;

v15:
    fn = elt(env, 17); /* scan */
    v92 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v91 = elt(env, 12); /* by */
    if (v92 == v91) goto v2;
    v91 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v91 == nil)) goto v95;
    v92 = elt(env, 13); /* "expecting 'by' in struct but found" */
    v91 = qvalue(elt(env, 1)); /* cursym!* */
    v91 = list2(v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    fn = elt(env, 19); /* lprie */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    goto v95;

v95:
    v91 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    goto v2;

v2:
    fn = elt(env, 17); /* scan */
    v91 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    stack[-3] = v91;
    fn = elt(env, 17); /* scan */
    v92 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v91 = elt(env, 2); /* delim */
    v91 = Lflagp(nil, v92, v91);
    env = stack[-4];
    if (!(v91 == nil)) goto v51;
    v91 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v91 == nil)) goto v42;
    v92 = elt(env, 14); /* "expecting end of struct but found" */
    v91 = qvalue(elt(env, 1)); /* cursym!* */
    v91 = list2(v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    fn = elt(env, 19); /* lprie */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    goto v42;

v42:
    v91 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    goto v51;

v51:
    v91 = qvalue(elt(env, 3)); /* !*assert */
    if (v91 == nil) goto v96;
    stack[-2] = elt(env, 15); /* put */
    v91 = stack[0];
    stack[-1] = Lmkquote(nil, v91);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    stack[0] = elt(env, 16); /* (quote assert_checkfn) */
    v91 = stack[-3];
    v91 = Lmkquote(nil, v91);
    nil = C_nil;
    if (exception_pending()) goto v94;
    {
        Lisp_Object v97 = stack[-2];
        Lisp_Object v98 = stack[-1];
        Lisp_Object v99 = stack[0];
        popv(5);
        return list4(v97, v98, v99, v91);
    }

v96:
    v91 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v91); }
/* error exit handlers */
v94:
    popv(5);
    return nil;
}



/* Code for changearg */

static Lisp_Object MS_CDECL CC_changearg(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v48, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v5, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "changearg");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for changearg");
#endif
    if (stack >= stacklimit)
    {
        push3(v48,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v48);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v48;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v70;

v70:
    v59 = stack[0];
    if (!consp(v59)) goto v26;
    v59 = stack[0];
    v5 = qcar(v59);
    v59 = stack[-2];
    v59 = Lmemq(nil, v5, v59);
    if (v59 == nil) goto v7;
    stack[-2] = stack[-3];
    v59 = stack[0];
    v5 = qcar(v59);
    v59 = stack[-1];
    v59 = cons(v5, v59);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    {
        Lisp_Object v107 = stack[-2];
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v107, v59);
    }

v7:
    v106 = stack[-2];
    v5 = stack[-1];
    v59 = stack[0];
    v59 = qcar(v59);
    v5 = CC_changearg(env, 3, v106, v5, v59);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    v59 = stack[-3];
    v59 = cons(v5, v59);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    stack[-3] = v59;
    v59 = stack[0];
    v59 = qcdr(v59);
    stack[0] = v59;
    goto v70;

v26:
    v5 = stack[-3];
    v59 = stack[0];
    {
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v5, v59);
    }
/* error exit handlers */
v21:
    popv(5);
    return nil;
}



/* Code for fs!:null!-angle */

static Lisp_Object CC_fsTnullKangle(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v89;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:null-angle");
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
    v111 = v0;
/* end of prologue */
    v89 = v111;
    v111 = (Lisp_Object)33; /* 2 */
    v111 = *(Lisp_Object *)((char *)v89 + (CELL-TAG_VECTOR) + ((int32_t)v111/(16/CELL)));
    stack[0] = v111;
    v111 = qvalue(elt(env, 1)); /* t */
    stack[-2] = v111;
    v111 = (Lisp_Object)1; /* 0 */
    stack[-1] = v111;
    goto v33;

v33:
    v89 = stack[0];
    v111 = stack[-1];
    v89 = *(Lisp_Object *)((char *)v89 + (CELL-TAG_VECTOR) + ((int32_t)v111/(16/CELL)));
    v111 = (Lisp_Object)1; /* 0 */
    if (v89 == v111) goto v68;
    v111 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v111); }

v68:
    v111 = stack[-1];
    v111 = add1(v111);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-3];
    stack[-1] = v111;
    v89 = stack[-1];
    v111 = (Lisp_Object)129; /* 8 */
    v111 = (Lisp_Object)lessp2(v89, v111);
    nil = C_nil;
    if (exception_pending()) goto v7;
    v111 = v111 ? lisp_true : nil;
    env = stack[-3];
    if (v111 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    else goto v33;
/* error exit handlers */
v7:
    popv(4);
    return nil;
}



/* Code for exptpri */

static Lisp_Object CC_exptpri(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v173, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptpri");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    v173 = v1;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* !*list */
    qvalue(elt(env, 1)) = nil; /* !*list */
    stack[0] = nil;
    v172 = qvalue(elt(env, 2)); /* !*nat */
    if (v172 == nil) goto v37;
    v172 = qvalue(elt(env, 4)); /* !*fort */
    goto v36;

v36:
    if (v172 == nil) goto v64;
    v172 = elt(env, 5); /* failed */
    goto v65;

v65:
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    { popv(8); return onevalue(v172); }

v64:
    v174 = elt(env, 6); /* expt */
    v172 = elt(env, 7); /* infix */
    v172 = get(v174, v172);
    env = stack[-7];
    stack[-2] = v172;
    v172 = (Lisp_Object)greaterp2(v172, v173);
    nil = C_nil;
    if (exception_pending()) goto v175;
    v172 = v172 ? lisp_true : nil;
    env = stack[-7];
    v172 = (v172 == nil ? lisp_true : nil);
    stack[-4] = v172;
    v172 = stack[-5];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    stack[-1] = v172;
    v172 = stack[-5];
    v172 = qcdr(v172);
    v172 = qcdr(v172);
    v172 = qcar(v172);
    stack[-3] = v172;
    v172 = qvalue(elt(env, 8)); /* !*eraise */
    if (v172 == nil) goto v82;
    v172 = stack[-1];
    if (!consp(v172)) goto v176;
    v172 = stack[-1];
    v173 = qcar(v172);
    v172 = elt(env, 9); /* prifn */
    v172 = get(v173, v172);
    env = stack[-7];
    stack[0] = v172;
    if (v172 == nil) goto v177;
    v173 = stack[0];
    v172 = elt(env, 6); /* expt */
    v173 = get(v173, v172);
    env = stack[-7];
    v172 = elt(env, 11); /* inbrackets */
    v172 = (v173 == v172 ? lisp_true : nil);
    goto v6;

v6:
    if (v172 == nil) goto v82;
    v174 = stack[-1];
    v173 = (Lisp_Object)1; /* 0 */
    v172 = elt(env, 11); /* inbrackets */
    fn = elt(env, 21); /* layout!-formula */
    v172 = (*qfnn(fn))(qenv(fn), 3, v174, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    stack[-1] = v172;
    goto v108;

v108:
    v172 = stack[-1];
    if (v172 == nil) goto v66;
    stack[-5] = qvalue(elt(env, 13)); /* !*ratpri */
    qvalue(elt(env, 13)) = nil; /* !*ratpri */
    v173 = stack[-3];
    v172 = elt(env, 14); /* quotient */
    if (!consp(v173)) goto v178;
    v173 = qcar(v173);
    if (!(v173 == v172)) goto v178;
    v172 = stack[-3];
    v172 = qcdr(v172);
    v173 = qcar(v172);
    v172 = elt(env, 15); /* minus */
    v172 = Leqcar(nil, v173, v172);
    env = stack[-7];
    goto v91;

v91:
    if (v172 == nil) goto v179;
    stack[0] = elt(env, 15); /* minus */
    v172 = stack[-3];
    v174 = qcar(v172);
    v172 = stack[-3];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    v172 = qcdr(v172);
    v173 = qcar(v172);
    v172 = stack[-3];
    v172 = qcdr(v172);
    v172 = qcdr(v172);
    v172 = qcar(v172);
    v172 = list3(v174, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-7];
    v172 = list2(stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-7];
    stack[-3] = v172;
    goto v181;

v181:
    v174 = stack[-3];
    v172 = qvalue(elt(env, 8)); /* !*eraise */
    if (v172 == nil) goto v182;
    v172 = (Lisp_Object)1; /* 0 */
    v173 = v172;
    goto v183;

v183:
    v172 = qvalue(elt(env, 10)); /* nil */
    fn = elt(env, 21); /* layout!-formula */
    v172 = (*qfnn(fn))(qenv(fn), 3, v174, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-7];
    stack[-3] = v172;
    qvalue(elt(env, 13)) = stack[-5]; /* !*ratpri */
    v172 = stack[-3];
    if (v172 == nil) goto v184;
    v172 = stack[-1];
    v172 = qcar(v172);
    v173 = qcdr(v172);
    v172 = stack[-3];
    v172 = qcar(v172);
    v172 = qcdr(v172);
    v172 = plus2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    stack[-5] = v172;
    v172 = stack[-4];
    if (v172 == nil) goto v185;
    v173 = stack[-5];
    v172 = (Lisp_Object)33; /* 2 */
    v172 = plus2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    stack[-5] = v172;
    goto v185;

v185:
    stack[0] = stack[-5];
    v172 = qvalue(elt(env, 10)); /* nil */
    v173 = Llinelength(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    v172 = qvalue(elt(env, 16)); /* spare!* */
    v173 = difference2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    v172 = qvalue(elt(env, 17)); /* orig!* */
    v172 = difference2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    v172 = (Lisp_Object)greaterp2(stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    v172 = v172 ? lisp_true : nil;
    env = stack[-7];
    if (v172 == nil) goto v186;
    v172 = elt(env, 5); /* failed */
    goto v65;

v186:
    stack[0] = stack[-5];
    v172 = qvalue(elt(env, 10)); /* nil */
    v173 = Llinelength(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    v172 = qvalue(elt(env, 16)); /* spare!* */
    v173 = difference2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    v172 = qvalue(elt(env, 18)); /* posn!* */
    v172 = difference2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    v172 = (Lisp_Object)greaterp2(stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    v172 = v172 ? lisp_true : nil;
    env = stack[-7];
    if (v172 == nil) goto v187;
    v172 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 22); /* terpri!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    goto v187;

v187:
    v172 = stack[-4];
    if (v172 == nil) goto v188;
    v172 = elt(env, 19); /* "(" */
    fn = elt(env, 23); /* prin2!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    goto v188;

v188:
    v172 = stack[-1];
    fn = elt(env, 24); /* putpline */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    v172 = qvalue(elt(env, 8)); /* !*eraise */
    if (v172 == nil) goto v189;
    v173 = (Lisp_Object)17; /* 1 */
    v172 = stack[-3];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    v172 = difference2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    stack[-5] = v172;
    goto v190;

v190:
    v174 = (Lisp_Object)1; /* 0 */
    v173 = stack[-5];
    v172 = stack[-3];
    v172 = qcar(v172);
    v172 = qcar(v172);
    fn = elt(env, 25); /* update!-pline */
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v174, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    v172 = stack[-3];
    v172 = qcar(v172);
    stack[-1] = qcdr(v172);
    v172 = stack[-3];
    v172 = qcdr(v172);
    v173 = qcar(v172);
    v172 = stack[-5];
    stack[0] = plus2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    v172 = stack[-3];
    v172 = qcdr(v172);
    v173 = qcdr(v172);
    v172 = stack[-5];
    v172 = plus2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    v172 = cons(stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    v172 = acons(stack[-2], stack[-1], v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    fn = elt(env, 24); /* putpline */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    v172 = stack[-4];
    if (v172 == nil) goto v191;
    v172 = elt(env, 20); /* ")" */
    fn = elt(env, 23); /* prin2!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    goto v191;

v191:
    v172 = nil;
    goto v65;

v189:
    v172 = elt(env, 6); /* expt */
    fn = elt(env, 26); /* oprin */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    v172 = (Lisp_Object)1; /* 0 */
    stack[-5] = v172;
    goto v190;

v184:
    v172 = elt(env, 5); /* failed */
    goto v65;

v182:
    v172 = stack[-2];
    v173 = v172;
    goto v183;

v179:
    v173 = stack[-3];
    v172 = elt(env, 15); /* minus */
    if (!consp(v173)) goto v192;
    v173 = qcar(v173);
    if (!(v173 == v172)) goto v192;
    v172 = stack[-3];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    v172 = (is_number(v172) ? lisp_true : nil);
    goto v193;

v193:
    if (v172 == nil) goto v194;
    v172 = stack[-3];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    v172 = negate(v172);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-7];
    goto v195;

v195:
    stack[-3] = v172;
    goto v181;

v194:
    v172 = stack[-3];
    goto v195;

v192:
    v172 = qvalue(elt(env, 10)); /* nil */
    goto v193;

v178:
    v172 = qvalue(elt(env, 10)); /* nil */
    goto v91;

v66:
    v172 = elt(env, 5); /* failed */
    goto v65;

v82:
    v173 = stack[0];
    v172 = elt(env, 12); /* indexprin */
    if (v173 == v172) goto v74;
    v172 = qvalue(elt(env, 10)); /* nil */
    goto v196;

v196:
    if (v172 == nil) goto v79;
    v172 = qvalue(elt(env, 10)); /* nil */
    goto v65;

v79:
    v174 = stack[-1];
    v173 = stack[-2];
    v172 = qvalue(elt(env, 10)); /* nil */
    fn = elt(env, 21); /* layout!-formula */
    v172 = (*qfnn(fn))(qenv(fn), 3, v174, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    stack[-1] = v172;
    goto v108;

v74:
    v173 = stack[-1];
    v172 = stack[-3];
    fn = elt(env, 27); /* indexpower */
    v173 = (*qfn2(fn))(qenv(fn), v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-7];
    v172 = elt(env, 5); /* failed */
    v172 = (v173 == v172 ? lisp_true : nil);
    v172 = (v172 == nil ? lisp_true : nil);
    goto v196;

v177:
    v172 = qvalue(elt(env, 10)); /* nil */
    goto v6;

v176:
    v172 = qvalue(elt(env, 10)); /* nil */
    goto v6;

v37:
    v172 = qvalue(elt(env, 3)); /* t */
    goto v36;
/* error exit handlers */
v180:
    env = stack[-7];
    qvalue(elt(env, 13)) = stack[-5]; /* !*ratpri */
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    popv(8);
    return nil;
v175:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    popv(8);
    return nil;
}



/* Code for pa_coinc_split */

static Lisp_Object CC_pa_coinc_split(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v236, v132, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pa_coinc_split");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v1;
    stack[-9] = v0;
/* end of prologue */
    stack[-6] = nil;
    v236 = stack[-9];
    v236 = qcdr(v236);
    fn = elt(env, 3); /* upbve */
    v236 = (*qfn1(fn))(qenv(fn), v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    stack[-4] = v236;
    v236 = stack[-4];
    v236 = sub1(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v236 = Lmkvect(nil, v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    stack[-10] = v236;
    v236 = stack[-4];
    v236 = sub1(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v236 = Lmkvect(nil, v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    stack[-7] = v236;
    v236 = stack[-4];
    v236 = sub1(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v236 = Lmkvect(nil, v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    stack[-5] = v236;
    v236 = (Lisp_Object)1; /* 0 */
    stack[-3] = v236;
    v236 = stack[-9];
    v236 = qcar(v236);
    stack[-2] = v236;
    goto v64;

v64:
    v236 = stack[-2];
    if (v236 == nil) goto v171;
    v236 = stack[-2];
    v236 = qcar(v236);
    stack[-1] = v236;
    v236 = stack[-3];
    v236 = add1(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    stack[-3] = v236;
    stack[0] = stack[-10];
    v236 = stack[-1];
    v132 = sub1(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v236 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v132/(16/CELL))) = v236;
    v236 = stack[-2];
    v236 = qcdr(v236);
    stack[-2] = v236;
    goto v64;

v171:
    v236 = (Lisp_Object)1; /* 0 */
    stack[-3] = v236;
    v236 = stack[-8];
    v236 = qcar(v236);
    stack[-2] = v236;
    goto v61;

v61:
    v236 = stack[-2];
    if (v236 == nil) goto v177;
    v236 = stack[-2];
    v236 = qcar(v236);
    stack[-1] = v236;
    v236 = stack[-3];
    v236 = add1(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    stack[-3] = v236;
    stack[0] = stack[-7];
    v236 = stack[-1];
    v132 = sub1(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v236 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v132/(16/CELL))) = v236;
    v236 = stack[-2];
    v236 = qcdr(v236);
    stack[-2] = v236;
    goto v61;

v177:
    v236 = (Lisp_Object)17; /* 1 */
    stack[-3] = v236;
    goto v53;

v53:
    v132 = stack[-4];
    v236 = stack[-3];
    v236 = difference2(v132, v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v236 = Lminusp(nil, v236);
    env = stack[-11];
    if (v236 == nil) goto v51;
    v132 = stack[-6];
    v236 = elt(env, 2); /* lambda_lqgavy_5 */
    fn = elt(env, 4); /* sort */
    v236 = (*qfn2(fn))(qenv(fn), v132, v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    stack[-6] = v236;
    v236 = stack[-6];
    stack[-3] = v236;
    v236 = stack[-3];
    if (v236 == nil) goto v238;
    v236 = stack[-3];
    v236 = qcar(v236);
    v236 = qcdr(v236);
    v236 = qcar(v236);
    v236 = ncons(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    stack[-1] = v236;
    stack[-2] = v236;
    goto v239;

v239:
    v236 = stack[-3];
    v236 = qcdr(v236);
    stack[-3] = v236;
    v236 = stack[-3];
    if (v236 == nil) goto v240;
    stack[0] = stack[-1];
    v236 = stack[-3];
    v236 = qcar(v236);
    v236 = qcdr(v236);
    v236 = qcar(v236);
    v236 = ncons(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v236 = Lrplacd(nil, stack[0], v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v236 = stack[-1];
    v236 = qcdr(v236);
    stack[-1] = v236;
    goto v239;

v240:
    v236 = stack[-2];
    v132 = v236;
    goto v241;

v241:
    v236 = stack[-5];
    v236 = cons(v132, v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    stack[-5] = v236;
    v236 = stack[-6];
    stack[-3] = v236;
    v236 = stack[-3];
    if (v236 == nil) goto v242;
    v236 = stack[-3];
    v236 = qcar(v236);
    v132 = v236;
    v132 = qcar(v132);
    v236 = qcdr(v236);
    v236 = qcdr(v236);
    v236 = cons(v132, v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v236 = ncons(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    stack[-1] = v236;
    stack[-2] = v236;
    goto v243;

v243:
    v236 = stack[-3];
    v236 = qcdr(v236);
    stack[-3] = v236;
    v236 = stack[-3];
    if (v236 == nil) goto v244;
    stack[0] = stack[-1];
    v236 = stack[-3];
    v236 = qcar(v236);
    v132 = v236;
    v132 = qcar(v132);
    v236 = qcdr(v236);
    v236 = qcdr(v236);
    v236 = cons(v132, v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v236 = ncons(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v236 = Lrplacd(nil, stack[0], v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v236 = stack[-1];
    v236 = qcdr(v236);
    stack[-1] = v236;
    goto v243;

v244:
    v236 = stack[-2];
    goto v129;

v129:
    v132 = v236;
    v236 = stack[-5];
    popv(12);
    return cons(v132, v236);

v242:
    v236 = qvalue(elt(env, 1)); /* nil */
    goto v129;

v238:
    v236 = qvalue(elt(env, 1)); /* nil */
    v132 = v236;
    goto v241;

v51:
    stack[-1] = stack[-10];
    v236 = stack[-9];
    stack[0] = qcdr(v236);
    v236 = stack[-3];
    v236 = sub1(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v236 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v236/(16/CELL)));
    v236 = sub1(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    stack[-2] = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v236/(16/CELL)));
    stack[-1] = stack[-7];
    v236 = stack[-8];
    stack[0] = qcdr(v236);
    v236 = stack[-3];
    v236 = sub1(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v236 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v236/(16/CELL)));
    v236 = sub1(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v236 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v236/(16/CELL)));
    v236 = cons(stack[-2], v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v130 = v236;
    v132 = v130;
    v236 = stack[-6];
    v236 = Lassoc(nil, v132, v236);
    stack[-1] = v236;
    if (v236 == nil) goto v245;
    v236 = stack[-1];
    stack[0] = qcdr(v236);
    v236 = stack[-1];
    v236 = qcdr(v236);
    v236 = qcdr(v236);
    v236 = add1(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v236 = Lrplacd(nil, stack[0], v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    stack[0] = stack[-5];
    v236 = stack[-3];
    v132 = sub1(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v236 = stack[-1];
    v236 = qcdr(v236);
    v236 = qcar(v236);
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v132/(16/CELL))) = v236;
    goto v40;

v40:
    v236 = stack[-3];
    v236 = add1(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    stack[-3] = v236;
    goto v53;

v245:
    v132 = stack[-3];
    v236 = (Lisp_Object)17; /* 1 */
    v236 = list2star(v130, v132, v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    stack[-1] = v236;
    v132 = stack[-1];
    v236 = stack[-6];
    v236 = cons(v132, v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    stack[-6] = v236;
    stack[0] = stack[-5];
    v236 = stack[-3];
    v132 = sub1(v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v236 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v132/(16/CELL))) = v236;
    goto v40;
/* error exit handlers */
v237:
    popv(12);
    return nil;
}



/* Code for lambda_lqgavy_5 */

static Lisp_Object CC_lambda_lqgavy_5(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v109;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_lqgavy_5");
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
    v108 = stack[-1];
    v108 = qcar(v108);
    v109 = qcar(v108);
    v108 = stack[0];
    v108 = qcar(v108);
    v108 = qcar(v108);
    v108 = (Lisp_Object)lessp2(v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v89;
    v108 = v108 ? lisp_true : nil;
    env = stack[-2];
    if (v108 == nil) goto v11;
    v108 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v108); }

v11:
    v108 = stack[0];
    v108 = qcar(v108);
    v109 = qcar(v108);
    v108 = stack[-1];
    v108 = qcar(v108);
    v108 = qcar(v108);
    v108 = (Lisp_Object)lessp2(v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v89;
    v108 = v108 ? lisp_true : nil;
    env = stack[-2];
    if (v108 == nil) goto v102;
    v108 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v108); }

v102:
    v108 = stack[-1];
    v108 = qcar(v108);
    v109 = qcdr(v108);
    v108 = stack[0];
    v108 = qcar(v108);
    v108 = qcdr(v108);
        popv(3);
        return Lleq(nil, v109, v108);
/* error exit handlers */
v89:
    popv(3);
    return nil;
}



/* Code for subsublis */

static Lisp_Object CC_subsublis(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v257, v258, v183;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subsublis");
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
    stack[0] = v1;
    stack[-3] = v0;
/* end of prologue */

v65:
    v258 = stack[0];
    v257 = stack[-3];
    v257 = Lassoc(nil, v258, v257);
    v183 = v257;
    if (v257 == nil) goto v33;
    v257 = v183;
    v257 = qcdr(v257);
    { popv(6); return onevalue(v257); }

v33:
    v258 = stack[0];
    v257 = elt(env, 1); /* sqrt */
    if (!consp(v258)) goto v88;
    v258 = qcar(v258);
    if (!(v258 == v257)) goto v88;
    v183 = elt(env, 2); /* expt */
    v257 = stack[0];
    v257 = qcdr(v257);
    v258 = qcar(v257);
    v257 = elt(env, 3); /* (quotient 1 2) */
    v258 = list3(v183, v258, v257);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    v257 = stack[-3];
    v257 = Lassoc(nil, v258, v257);
    v183 = v257;
    goto v11;

v11:
    if (v257 == nil) goto v31;
    v257 = v183;
    v257 = qcdr(v257);
    { popv(6); return onevalue(v257); }

v31:
    v257 = stack[0];
    if (!consp(v257)) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v257 = stack[0];
    v257 = qcar(v257);
    if (symbolp(v257)) goto v74;
    v257 = stack[0];
    stack[-4] = v257;
    v257 = stack[-4];
    if (v257 == nil) goto v22;
    v257 = stack[-4];
    v257 = qcar(v257);
    v258 = stack[-3];
    v257 = CC_subsublis(env, v258, v257);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    v257 = ncons(v257);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    stack[-1] = v257;
    stack[-2] = v257;
    goto v5;

v5:
    v257 = stack[-4];
    v257 = qcdr(v257);
    stack[-4] = v257;
    v257 = stack[-4];
    if (v257 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v257 = stack[-4];
    v257 = qcar(v257);
    v258 = stack[-3];
    v257 = CC_subsublis(env, v258, v257);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    v257 = ncons(v257);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    v257 = Lrplacd(nil, stack[0], v257);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    v257 = stack[-1];
    v257 = qcdr(v257);
    stack[-1] = v257;
    goto v5;

v22:
    v257 = qvalue(elt(env, 4)); /* nil */
    { popv(6); return onevalue(v257); }

v74:
    v257 = stack[0];
    v258 = qcar(v257);
    v257 = elt(env, 5); /* subfunc */
    v257 = get(v258, v257);
    env = stack[-5];
    v183 = v257;
    if (v257 == nil) goto v228;
    v258 = stack[-3];
    v257 = stack[0];
        popv(6);
        return Lapply2(nil, 3, v183, v258, v257);

v228:
    v257 = stack[0];
    v258 = qcar(v257);
    v257 = elt(env, 6); /* dname */
    v257 = get(v258, v257);
    env = stack[-5];
    if (!(v257 == nil)) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v257 = stack[0];
    v258 = qcar(v257);
    v257 = elt(env, 7); /* !*sq */
    if (v258 == v257) goto v92;
    v257 = stack[0];
    stack[-4] = v257;
    v257 = stack[-4];
    if (v257 == nil) goto v260;
    v257 = stack[-4];
    v257 = qcar(v257);
    v258 = stack[-3];
    v257 = CC_subsublis(env, v258, v257);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    v257 = ncons(v257);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    stack[-1] = v257;
    stack[-2] = v257;
    goto v218;

v218:
    v257 = stack[-4];
    v257 = qcdr(v257);
    stack[-4] = v257;
    v257 = stack[-4];
    if (v257 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v257 = stack[-4];
    v257 = qcar(v257);
    v258 = stack[-3];
    v257 = CC_subsublis(env, v258, v257);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    v257 = ncons(v257);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    v257 = Lrplacd(nil, stack[0], v257);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    v257 = stack[-1];
    v257 = qcdr(v257);
    stack[-1] = v257;
    goto v218;

v260:
    v257 = qvalue(elt(env, 4)); /* nil */
    { popv(6); return onevalue(v257); }

v92:
    stack[-1] = stack[-3];
    v257 = stack[0];
    v257 = qcdr(v257);
    v257 = qcar(v257);
    v257 = qcar(v257);
    if (v257 == nil) goto v98;
    v257 = stack[0];
    v257 = qcdr(v257);
    v258 = qcar(v257);
    v257 = elt(env, 8); /* prepf */
    fn = elt(env, 9); /* sqform */
    v257 = (*qfn2(fn))(qenv(fn), v258, v257);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-5];
    goto v261;

v261:
    stack[-3] = stack[-1];
    stack[0] = v257;
    goto v65;

v98:
    v257 = (Lisp_Object)1; /* 0 */
    goto v261;

v88:
    v257 = qvalue(elt(env, 4)); /* nil */
    goto v11;
/* error exit handlers */
v259:
    popv(6);
    return nil;
}



/* Code for ordexn */

static Lisp_Object CC_ordexn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordexn");
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
    stack[0] = nil;
    stack[-3] = nil;
    goto v70;

v70:
    v55 = stack[-1];
    if (v55 == nil) goto v39;
    v56 = stack[-2];
    v55 = stack[-1];
    v55 = qcar(v55);
    if (v56 == v55) goto v104;
    v55 = stack[-2];
    if (v55 == nil) goto v264;
    v56 = stack[-2];
    v55 = stack[-1];
    v55 = qcar(v55);
    fn = elt(env, 2); /* ordop */
    v55 = (*qfn2(fn))(qenv(fn), v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-4];
    if (v55 == nil) goto v264;
    v56 = stack[-2];
    v55 = stack[-3];
    v55 = cons(v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-4];
    v56 = Lreverse(nil, v55);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-4];
    v55 = stack[-1];
    v55 = Lappend(nil, v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v265;
    {
        Lisp_Object v95 = stack[0];
        popv(5);
        return cons(v95, v55);
    }

v264:
    v55 = stack[-1];
    v56 = qcar(v55);
    v55 = stack[-3];
    v55 = cons(v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-4];
    stack[-3] = v55;
    v55 = stack[-1];
    v55 = qcdr(v55);
    stack[-1] = v55;
    v55 = stack[0];
    v55 = (v55 == nil ? lisp_true : nil);
    stack[0] = v55;
    goto v70;

v104:
    v55 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v55); }

v39:
    v56 = stack[-2];
    v55 = stack[-3];
    v55 = cons(v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-4];
    v55 = Lreverse(nil, v55);
    nil = C_nil;
    if (exception_pending()) goto v265;
    {
        Lisp_Object v266 = stack[0];
        popv(5);
        return cons(v266, v55);
    }
/* error exit handlers */
v265:
    popv(5);
    return nil;
}



/* Code for monomwrite */

static Lisp_Object CC_monomwrite(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v266, v53, v54;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monomwrite");
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
    v53 = v0;
/* end of prologue */
    stack[-5] = nil;
    v266 = qvalue(elt(env, 1)); /* fluidbibasisnumberofvariables */
    stack[-2] = v266;
    v266 = qvalue(elt(env, 2)); /* fluidbibasisreversedvariables */
    stack[-4] = v266;
    v266 = (Lisp_Object)17; /* 1 */
    v266 = *(Lisp_Object *)((char *)v53 + (CELL-TAG_VECTOR) + ((int32_t)v266/(16/CELL)));
    stack[-3] = v266;
    goto v31;

v31:
    v266 = stack[-3];
    v266 = qcar(v266);
    if (v266 == nil) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    v266 = (Lisp_Object)17; /* 1 */
    stack[0] = v266;
    goto v62;

v62:
    v53 = stack[-2];
    v266 = stack[-3];
    v266 = qcar(v266);
    v53 = difference2(v53, v266);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-6];
    v266 = stack[0];
    v266 = difference2(v53, v266);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-6];
    v266 = Lminusp(nil, v266);
    env = stack[-6];
    if (v266 == nil) goto v13;
    v266 = stack[-3];
    v266 = qcar(v266);
    stack[-2] = v266;
    v266 = stack[-5];
    if (v266 == nil) goto v3;
    v266 = stack[-4];
    stack[-1] = qcar(v266);
    stack[0] = (Lisp_Object)17; /* 1 */
    v266 = stack[-5];
    v266 = ncons(v266);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-6];
    v266 = acons(stack[-1], stack[0], v266);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-6];
    stack[-5] = v266;
    goto v57;

v57:
    v266 = stack[-3];
    v266 = qcdr(v266);
    stack[-3] = v266;
    goto v31;

v3:
    v266 = stack[-4];
    v54 = qcar(v266);
    v53 = (Lisp_Object)17; /* 1 */
    v266 = (Lisp_Object)17; /* 1 */
    v266 = acons(v54, v53, v266);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-6];
    stack[-5] = v266;
    goto v57;

v13:
    v266 = stack[-4];
    v266 = qcdr(v266);
    stack[-4] = v266;
    v266 = stack[0];
    v266 = add1(v266);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-6];
    stack[0] = v266;
    goto v62;
/* error exit handlers */
v49:
    popv(7);
    return nil;
}



/* Code for cl_fvarl */

static Lisp_Object CC_cl_fvarl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v268;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_fvarl");
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
    v69 = v0;
/* end of prologue */
    fn = elt(env, 2); /* cl_fvarl1 */
    v268 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[0];
    v69 = elt(env, 1); /* ordp */
    {
        popv(1);
        fn = elt(env, 3); /* sort */
        return (*qfn2(fn))(qenv(fn), v268, v69);
    }
/* error exit handlers */
v110:
    popv(1);
    return nil;
}



/* Code for dfconst */

static Lisp_Object CC_dfconst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfconst");
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
    v31 = stack[0];
    v31 = qcar(v31);
    if (v31 == nil) goto v24;
    v31 = qvalue(elt(env, 2)); /* zlist */
    fn = elt(env, 3); /* vp2 */
    v39 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v31 = stack[0];
    v31 = cons(v39, v31);
    nil = C_nil;
    if (exception_pending()) goto v25;
    popv(2);
    return ncons(v31);

v24:
    v31 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v31); }
/* error exit handlers */
v25:
    popv(2);
    return nil;
}



/* Code for mml2ir */

static Lisp_Object MS_CDECL CC_mml2ir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mml2ir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mml2ir");
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
    v101 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v101;
    v101 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v101; /* mmlatts */
    v87 = elt(env, 3); /* !! */
    v101 = (Lisp_Object)513; /* 32 */
    v101 = list2(v87, v101);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    v101 = Lcompress(nil, v101);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    qvalue(elt(env, 4)) = v101; /* space */
    v101 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 5)) = v101; /* count */
    v101 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    qvalue(elt(env, 6)) = v101; /* ch */
    v101 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 7)) = v101; /* temp2 */
    fn = elt(env, 13); /* lex */
    v101 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    v87 = qvalue(elt(env, 8)); /* char */
    v101 = elt(env, 9); /* (m a t h) */
    if (equal(v87, v101)) goto v31;
    v87 = elt(env, 10); /* "<math>" */
    v101 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 14); /* errorml */
    v101 = (*qfn2(fn))(qenv(fn), v87, v101);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    goto v38;

v38:
    fn = elt(env, 13); /* lex */
    v101 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    v87 = qvalue(elt(env, 8)); /* char */
    v101 = elt(env, 11); /* (!/ m a t h) */
    if (equal(v87, v101)) goto v30;
    v87 = elt(env, 12); /* "</math>" */
    v101 = (Lisp_Object)305; /* 19 */
    fn = elt(env, 14); /* errorml */
    v101 = (*qfn2(fn))(qenv(fn), v87, v101);
    nil = C_nil;
    if (exception_pending()) goto v100;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v30:
    v101 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v31:
    fn = elt(env, 15); /* mathml */
    v101 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    stack[0] = v101;
    goto v38;
/* error exit handlers */
v100:
    popv(2);
    return nil;
}



/* Code for ps!:value */

static Lisp_Object CC_psTvalue(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v269, v270;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:value");
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
    v269 = v0;
/* end of prologue */
    v7 = v269;
    if (!consp(v7)) goto v18;
    v7 = v269;
    v270 = qcar(v7);
    v7 = elt(env, 2); /* !:ps!: */
    if (v270 == v7) goto v13;
    v7 = v269;
    v270 = qcar(v7);
    v7 = elt(env, 3); /* dname */
    v7 = get(v270, v7);
    env = stack[0];
    goto v70;

v70:
    if (v7 == nil) goto v111;
    v7 = v269;
    if (!(v7 == nil)) { popv(1); return onevalue(v269); }
    v7 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v7); }

v111:
    v7 = (Lisp_Object)65; /* 4 */
    {
        popv(1);
        fn = elt(env, 5); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v269, v7);
    }

v13:
    v7 = qvalue(elt(env, 4)); /* nil */
    goto v70;

v18:
    v7 = qvalue(elt(env, 1)); /* t */
    goto v70;
}



/* Code for gf2cr!: */

static Lisp_Object CC_gf2crT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v102, v28, v29;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gf2cr:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v28 = v0;
/* end of prologue */
    v29 = elt(env, 1); /* !:cr!: */
    v20 = v28;
    v20 = qcar(v20);
    if (!consp(v20)) goto v110;
    v20 = v28;
    v20 = qcar(v20);
    v20 = qcdr(v20);
    v102 = v20;
    goto v70;

v70:
    v20 = v28;
    v20 = qcdr(v20);
    if (!consp(v20)) goto v32;
    v20 = v28;
    v20 = qcdr(v20);
    v20 = qcdr(v20);
    goto v18;

v18:
    return list2star(v29, v102, v20);

v32:
    v20 = v28;
    v20 = qcdr(v20);
    goto v18;

v110:
    v20 = v28;
    v20 = qcar(v20);
    v102 = v20;
    goto v70;
}



/* Code for rdcos!* */

static Lisp_Object CC_rdcosH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rdcos*");
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
    v109 = v0;
/* end of prologue */
    v108 = v109;
    v108 = qcdr(v108);
    if (!consp(v108)) goto v35;
    v108 = v109;
    goto v24;

v24:
    fn = elt(env, 3); /* convchk */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[0];
    v109 = v108;
    v108 = v109;
    if (!consp(v108)) goto v37;
    v108 = qvalue(elt(env, 1)); /* !:bprec!: */
    fn = elt(env, 4); /* cos!: */
    v108 = (*qfn2(fn))(qenv(fn), v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[0];
    goto v36;

v36:
    v109 = v108;
    v108 = v109;
    if (!(!consp(v108))) { popv(1); return onevalue(v109); }
    v108 = elt(env, 2); /* !:rd!: */
    popv(1);
    return cons(v108, v109);

v37:
    v108 = v109;
    fn = elt(env, 5); /* cos */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[0];
    goto v36;

v35:
    v108 = v109;
    v108 = qcdr(v108);
    goto v24;
/* error exit handlers */
v256:
    popv(1);
    return nil;
}



/* Code for powers3 */

static Lisp_Object CC_powers3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v7;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powers3");
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
    stack[-1] = v1;
    v6 = v0;
/* end of prologue */

v147:
    v7 = v6;
    if (!consp(v7)) goto v110;
    v7 = v6;
    v7 = qcar(v7);
    v7 = (consp(v7) ? nil : lisp_true);
    goto v268;

v268:
    if (!(v7 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v7 = v6;
    v7 = qcar(v7);
    v7 = qcdr(v7);
    stack[-2] = v7;
    v7 = v6;
    v7 = qcar(v7);
    v7 = qcar(v7);
    stack[0] = qcar(v7);
    v7 = v6;
    v7 = qcar(v7);
    v7 = qcar(v7);
    v7 = qcdr(v7);
    v6 = qcar(v6);
    v6 = qcar(v6);
    v6 = qcdr(v6);
    v7 = cons(v7, v6);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-3];
    v6 = stack[-1];
    v6 = acons(stack[0], v7, v6);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-3];
    stack[-1] = v6;
    v6 = stack[-2];
    goto v147;

v110:
    v7 = qvalue(elt(env, 1)); /* t */
    goto v268;
/* error exit handlers */
v60:
    popv(4);
    return nil;
}



/* Code for collectphystype */

static Lisp_Object CC_collectphystype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for collectphystype");
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
    stack[0] = v0;
/* end of prologue */
    v168 = stack[0];
    fn = elt(env, 2); /* physopp */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-4];
    if (v168 == nil) goto v35;
    v168 = stack[0];
    fn = elt(env, 3); /* getphystype */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v101;
    popv(5);
    return ncons(v168);

v35:
    v168 = stack[0];
    if (!consp(v168)) goto v69;
    v168 = stack[0];
    stack[-3] = v168;
    v168 = stack[-3];
    if (v168 == nil) goto v33;
    v168 = stack[-3];
    v168 = qcar(v168);
    fn = elt(env, 3); /* getphystype */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-4];
    v168 = ncons(v168);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-4];
    stack[-1] = v168;
    stack[-2] = v168;
    goto v11;

v11:
    v168 = stack[-3];
    v168 = qcdr(v168);
    stack[-3] = v168;
    v168 = stack[-3];
    if (v168 == nil) goto v271;
    stack[0] = stack[-1];
    v168 = stack[-3];
    v168 = qcar(v168);
    fn = elt(env, 3); /* getphystype */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-4];
    v168 = ncons(v168);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-4];
    v168 = Lrplacd(nil, stack[0], v168);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-4];
    v168 = stack[-1];
    v168 = qcdr(v168);
    stack[-1] = v168;
    goto v11;

v271:
    v168 = stack[-2];
    goto v39;

v39:
    {
        popv(5);
        fn = elt(env, 4); /* deletemult!* */
        return (*qfn1(fn))(qenv(fn), v168);
    }

v33:
    v168 = qvalue(elt(env, 1)); /* nil */
    goto v39;

v69:
    v168 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v168); }
/* error exit handlers */
v101:
    popv(5);
    return nil;
}



/* Code for calc_atlas */

static Lisp_Object CC_calc_atlas(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v25, v12, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_atlas");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v11 = v1;
    v25 = v0;
/* end of prologue */
    v12 = v25;
    v32 = qcar(v12);
    v12 = v25;
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcar(v12);
    v25 = qcdr(v25);
    v25 = qcar(v25);
    {
        fn = elt(env, 1); /* calc_map_2d */
        return (*qfnn(fn))(qenv(fn), 4, v32, v12, v25, v11);
    }
}



/* Code for one!-entryp */

static Lisp_Object CC_oneKentryp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v62;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for one-entryp");
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

v35:
    v10 = stack[0];
    if (!consp(v10)) goto v18;
    v62 = stack[-1];
    v10 = stack[0];
    v10 = qcar(v10);
    v10 = Lsmemq(nil, v62, v10);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-2];
    if (v10 == nil) goto v271;
    v62 = stack[-1];
    v10 = stack[0];
    v10 = qcdr(v10);
    v10 = Lsmemq(nil, v62, v10);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-2];
    if (v10 == nil) goto v20;
    v10 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v10); }

v20:
    v10 = stack[0];
    v10 = qcar(v10);
    stack[0] = v10;
    goto v35;

v271:
    v10 = stack[0];
    v10 = qcdr(v10);
    stack[0] = v10;
    goto v35;

v18:
    v10 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v10); }
/* error exit handlers */
v108:
    popv(3);
    return nil;
}



/* Code for mv!-domainlist */

static Lisp_Object CC_mvKdomainlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-domainlist");
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
    v34 = nil;
    goto v35;

v35:
    v33 = stack[0];
    if (v33 == nil) goto v18;
    v33 = stack[0];
    v33 = qcar(v33);
    v33 = qcdr(v33);
    v33 = cons(v33, v34);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    v34 = v33;
    v33 = stack[0];
    v33 = qcdr(v33);
    stack[0] = v33;
    goto v35;

v18:
    v33 = v34;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v33);
    }
/* error exit handlers */
v105:
    popv(2);
    return nil;
}



/* Code for mo_from_a */

static Lisp_Object CC_mo_from_a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v196, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_from_a");
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
    stack[0] = stack[-3];
    v196 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_all_names */
    v196 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    v196 = Lmember(nil, stack[0], v196);
    if (v196 == nil) goto v36;
    v196 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_all_names */
    v196 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    stack[-4] = v196;
    v196 = stack[-4];
    if (v196 == nil) goto v29;
    v196 = stack[-4];
    v196 = qcar(v196);
    v49 = v196;
    v196 = stack[-3];
    if (equal(v49, v196)) goto v109;
    v196 = (Lisp_Object)1; /* 0 */
    goto v108;

v108:
    v196 = ncons(v196);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    stack[-1] = v196;
    stack[-2] = v196;
    goto v13;

v13:
    v196 = stack[-4];
    v196 = qcdr(v196);
    stack[-4] = v196;
    v196 = stack[-4];
    if (v196 == nil) goto v86;
    stack[0] = stack[-1];
    v196 = stack[-4];
    v196 = qcar(v196);
    v49 = v196;
    v196 = stack[-3];
    if (equal(v49, v196)) goto v3;
    v196 = (Lisp_Object)1; /* 0 */
    goto v85;

v85:
    v196 = ncons(v196);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    v196 = Lrplacd(nil, stack[0], v196);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    v196 = stack[-1];
    v196 = qcdr(v196);
    stack[-1] = v196;
    goto v13;

v3:
    v196 = (Lisp_Object)17; /* 1 */
    goto v85;

v86:
    v196 = stack[-2];
    goto v23;

v23:
    fn = elt(env, 5); /* mo!=shorten */
    v196 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    stack[0] = v196;
    fn = elt(env, 6); /* mo!=deglist */
    v196 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v51;
    {
        Lisp_Object v52 = stack[0];
        popv(6);
        return cons(v52, v196);
    }

v109:
    v196 = (Lisp_Object)17; /* 1 */
    goto v108;

v29:
    v196 = qvalue(elt(env, 3)); /* nil */
    goto v23;

v36:
    v49 = stack[-3];
    v196 = elt(env, 2); /* "dpoly variable" */
    {
        popv(6);
        fn = elt(env, 7); /* typerr */
        return (*qfn2(fn))(qenv(fn), v49, v196);
    }
/* error exit handlers */
v51:
    popv(6);
    return nil;
}



/* Code for primep */

static Lisp_Object CC_primep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v276, v230;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for primep");
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

v24:
    v276 = stack[0];
    v276 = integerp(v276);
    if (v276 == nil) goto v268;
    v230 = stack[0];
    v276 = (Lisp_Object)1; /* 0 */
    v276 = (Lisp_Object)lessp2(v230, v276);
    nil = C_nil;
    if (exception_pending()) goto v164;
    v276 = v276 ? lisp_true : nil;
    env = stack[-2];
    if (v276 == nil) goto v14;
    v276 = stack[0];
    v276 = negate(v276);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-2];
    stack[0] = v276;
    goto v24;

v14:
    v230 = stack[0];
    v276 = (Lisp_Object)17; /* 1 */
    if (v230 == v276) goto v171;
    v230 = stack[0];
    v276 = qvalue(elt(env, 3)); /* !*last!-prime!-in!-list!* */
    v276 = (Lisp_Object)lesseq2(v230, v276);
    nil = C_nil;
    if (exception_pending()) goto v164;
    v276 = v276 ? lisp_true : nil;
    env = stack[-2];
    if (v276 == nil) goto v177;
    v276 = stack[0];
    v230 = qvalue(elt(env, 4)); /* !*primelist!* */
    v276 = Lmember(nil, v276, v230);
    { popv(3); return onevalue(v276); }

v177:
    v230 = stack[0];
    v276 = qvalue(elt(env, 5)); /* !*last!-prime!-squared!* */
    v276 = (Lisp_Object)lesseq2(v230, v276);
    nil = C_nil;
    if (exception_pending()) goto v164;
    v276 = v276 ? lisp_true : nil;
    env = stack[-2];
    if (v276 == nil) goto v233;
    v276 = qvalue(elt(env, 4)); /* !*primelist!* */
    stack[-1] = v276;
    goto v262;

v262:
    v276 = stack[-1];
    if (v276 == nil) goto v235;
    v230 = stack[0];
    v276 = stack[-1];
    v276 = qcar(v276);
    v230 = Cremainder(v230, v276);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-2];
    v276 = (Lisp_Object)1; /* 0 */
    if (v230 == v276) goto v235;
    v276 = stack[-1];
    v276 = qcdr(v276);
    stack[-1] = v276;
    goto v262;

v235:
    v276 = stack[-1];
    v276 = (v276 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v276); }

v233:
    v230 = stack[0];
    v276 = qvalue(elt(env, 6)); /* largest!-small!-modulus */
    v276 = (Lisp_Object)greaterp2(v230, v276);
    nil = C_nil;
    if (exception_pending()) goto v164;
    v276 = v276 ? lisp_true : nil;
    env = stack[-2];
    if (v276 == nil) goto v51;
    v276 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* general!-primep */
        return (*qfn1(fn))(qenv(fn), v276);
    }

v51:
    v276 = stack[0];
    {
        popv(3);
        fn = elt(env, 8); /* small!-primep */
        return (*qfn1(fn))(qenv(fn), v276);
    }

v171:
    v276 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v276); }

v268:
    v230 = stack[0];
    v276 = elt(env, 1); /* "integer" */
    {
        popv(3);
        fn = elt(env, 9); /* typerr */
        return (*qfn2(fn))(qenv(fn), v230, v276);
    }
/* error exit handlers */
v164:
    popv(3);
    return nil;
}



/* Code for safe!-modrecip */

static Lisp_Object CC_safeKmodrecip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v177, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for safe-modrecip");
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
    v177 = v0;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* !*msg */
    qvalue(elt(env, 1)) = nil; /* !*msg */
    stack[0] = qvalue(elt(env, 2)); /* !*protfg */
    qvalue(elt(env, 2)) = nil; /* !*protfg */
    v60 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v60; /* !*msg */
    v60 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 2)) = v60; /* !*protfg */
    v61 = v177;
    v60 = elt(env, 5); /* !:mod!: */
    if (!consp(v61)) goto v64;
    v61 = qcar(v61);
    if (!(v61 == v60)) goto v64;
    v60 = v177;
    v60 = qcdr(v60);
    v177 = v60;
    goto v64;

v64:
    v60 = elt(env, 6); /* general!-modular!-reciprocal */
    v61 = list2(v60, v177);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v177 = qvalue(elt(env, 3)); /* nil */
    v60 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 8); /* errorset */
    v60 = (*qfnn(fn))(qenv(fn), 3, v61, v177, v60);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v177 = v60;
    v60 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 7)) = v60; /* erfg!* */
    v60 = v177;
    if (!consp(v60)) goto v63;
    v60 = v177;
    v60 = qcdr(v60);
    goto v103;

v103:
    if (v60 == nil) goto v7;
    v60 = qvalue(elt(env, 3)); /* nil */
    goto v147;

v147:
    qvalue(elt(env, 2)) = stack[0]; /* !*protfg */
    qvalue(elt(env, 1)) = stack[-1]; /* !*msg */
    { popv(3); return onevalue(v60); }

v7:
    v60 = v177;
    v60 = qcar(v60);
    goto v147;

v63:
    v60 = qvalue(elt(env, 4)); /* t */
    goto v103;
/* error exit handlers */
v87:
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[0]; /* !*protfg */
    qvalue(elt(env, 1)) = stack[-1]; /* !*msg */
    popv(3);
    return nil;
}



/* Code for evaluate!-in!-order!-mod!-p */

static Lisp_Object CC_evaluateKinKorderKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v255, v4, v59, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate-in-order-mod-p");
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

v35:
    v255 = stack[-1];
    if (!consp(v255)) goto v268;
    v255 = stack[-1];
    v255 = qcar(v255);
    v255 = (consp(v255) ? nil : lisp_true);
    goto v69;

v69:
    if (v255 == nil) goto v12;
    v255 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* !*d2n */
        return (*qfn1(fn))(qenv(fn), v255);
    }

v12:
    v255 = stack[-1];
    v255 = qcar(v255);
    v255 = qcar(v255);
    v4 = qcar(v255);
    v255 = stack[0];
    v255 = qcar(v255);
    v255 = qcar(v255);
    if (equal(v4, v255)) goto v63;
    v255 = stack[0];
    v255 = qcdr(v255);
    stack[0] = v255;
    goto v35;

v63:
    v255 = stack[-1];
    v255 = qcar(v255);
    v4 = qcdr(v255);
    v255 = stack[0];
    v255 = qcdr(v255);
    v5 = CC_evaluateKinKorderKmodKp(env, v4, v255);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-2];
    v255 = stack[-1];
    v255 = qcar(v255);
    v255 = qcar(v255);
    v59 = qcdr(v255);
    v255 = stack[-1];
    v4 = qcdr(v255);
    v255 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* horner!-rule!-in!-order!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 4, v5, v59, v4, v255);
    }

v268:
    v255 = qvalue(elt(env, 1)); /* t */
    goto v69;
/* error exit handlers */
v262:
    popv(3);
    return nil;
}



/* Code for rl_bettergaussp */

static Lisp_Object CC_rl_bettergaussp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_bettergaussp");
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
    v90 = v1;
    v68 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_bettergaussp!* */
    v90 = list2(v68, v90);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    {
        Lisp_Object v39 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v39, v90);
    }
/* error exit handlers */
v31:
    popv(2);
    return nil;
}



/* Code for tayexp!-minus */

static Lisp_Object CC_tayexpKminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-minus");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v34 = stack[0];
    if (!consp(v34)) goto v24;
    v34 = stack[0];
    stack[-1] = qcar(v34);
    v34 = stack[0];
    v34 = qcdr(v34);
    v34 = qcar(v34);
    fn = elt(env, 1); /* !:minus */
    v104 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v64;
    v34 = stack[0];
    v34 = qcdr(v34);
    v34 = qcdr(v34);
    {
        Lisp_Object v14 = stack[-1];
        popv(2);
        return list2star(v14, v104, v34);
    }

v24:
    v34 = stack[0];
    popv(2);
    return negate(v34);
/* error exit handlers */
v64:
    popv(2);
    return nil;
}



/* Code for matpri */

static Lisp_Object CC_matpri(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v268;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matpri");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v69 = v0;
/* end of prologue */
    v268 = qcdr(v69);
    v69 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* matpri1 */
        return (*qfn2(fn))(qenv(fn), v268, v69);
    }
}



/* Code for ev_lexcomp */

static Lisp_Object CC_ev_lexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v30;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_lexcomp");
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

v35:
    v9 = stack[-1];
    if (v9 == nil) goto v18;
    v9 = stack[-1];
    v30 = qcar(v9);
    v9 = stack[0];
    v9 = qcar(v9);
    v9 = Leqn(nil, v30, v9);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    if (v9 == nil) goto v105;
    v9 = stack[-1];
    v9 = qcdr(v9);
    stack[-1] = v9;
    v9 = stack[0];
    v9 = qcdr(v9);
    stack[0] = v9;
    goto v35;

v105:
    v9 = stack[-1];
    v30 = qcar(v9);
    v9 = stack[0];
    v9 = qcar(v9);
    if (((int32_t)(v30)) > ((int32_t)(v9))) goto v34;
    v9 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v9); }

v34:
    v9 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v9); }

v18:
    v9 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v9); }
/* error exit handlers */
v103:
    popv(3);
    return nil;
}



/* Code for cl_sacatl */

static Lisp_Object MS_CDECL CC_cl_sacatl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v48, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v273, v278, v279;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_sacatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_sacatl");
#endif
    if (stack >= stacklimit)
    {
        push3(v48,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v48);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v48;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v17:
    v273 = stack[-1];
    if (v273 == nil) goto v112;
    v278 = stack[-2];
    v273 = stack[-1];
    fn = elt(env, 6); /* rl_sacatlp */
    v273 = (*qfn2(fn))(qenv(fn), v278, v273);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-3];
    if (v273 == nil) goto v32;
    v279 = stack[-2];
    v273 = stack[-1];
    v278 = qcar(v273);
    v273 = stack[0];
    fn = elt(env, 7); /* rl_sacat */
    v273 = (*qfnn(fn))(qenv(fn), 3, v279, v278, v273);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-3];
    v279 = v273;
    v273 = v279;
    if (v273 == nil) goto v256;
    v278 = v279;
    v273 = elt(env, 3); /* (keep1 keep) */
    v273 = Lmemq(nil, v278, v273);
    if (v273 == nil) goto v73;
    v278 = elt(env, 4); /* keep1 */
    v273 = stack[-1];
    v273 = qcdr(v273);
    popv(4);
    return cons(v278, v273);

v73:
    v278 = v279;
    v273 = elt(env, 5); /* keep2 */
    if (v278 == v273) goto v83;
    v278 = v279;
    v273 = stack[-1];
    v273 = qcdr(v273);
    popv(4);
    return cons(v278, v273);

v83:
    v278 = qvalue(elt(env, 2)); /* nil */
    v273 = stack[-1];
    v273 = qcdr(v273);
    popv(4);
    return cons(v278, v273);

v256:
    v279 = stack[-2];
    v273 = stack[-1];
    v278 = qcdr(v273);
    v273 = stack[0];
    stack[-2] = v279;
    stack[-1] = v278;
    stack[0] = v273;
    goto v17;

v32:
    v278 = qvalue(elt(env, 2)); /* nil */
    v273 = stack[-1];
    popv(4);
    return cons(v278, v273);

v112:
    v273 = elt(env, 1); /* (nil) */
    { popv(4); return onevalue(v273); }
/* error exit handlers */
v254:
    popv(4);
    return nil;
}



/* Code for matrixrowom */

static Lisp_Object CC_matrixrowom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixrowom");
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
    if (v32 == nil) goto v35;
    v32 = elt(env, 1); /* "<OMA>" */
    fn = elt(env, 6); /* printout */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v32 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 7); /* indent!* */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v32 = elt(env, 3); /* "<OMS cd=""linalg1"" name=""matrixrow""/>" */
    fn = elt(env, 6); /* printout */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v32 = stack[0];
    v32 = qcar(v32);
    fn = elt(env, 8); /* multiom */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v32 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 7); /* indent!* */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v32 = elt(env, 5); /* "</OMA>" */
    fn = elt(env, 6); /* printout */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v32 = stack[0];
    v32 = qcdr(v32);
    v32 = CC_matrixrowom(env, v32);
    nil = C_nil;
    if (exception_pending()) goto v34;
    goto v35;

v35:
    v32 = nil;
    { popv(2); return onevalue(v32); }
/* error exit handlers */
v34:
    popv(2);
    return nil;
}



/* Code for n_nary */

static Lisp_Object CC_n_nary(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for n_nary");
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
    v59 = stack[-1];
    v5 = qcar(v59);
    v59 = elt(env, 1); /* e */
    if (v5 == v59) goto v31;
    v59 = qvalue(elt(env, 3)); /* nil */
    goto v65;

v65:
    if (v59 == nil) goto v271;
    v59 = stack[-1];
    v5 = qcdr(v59);
    v59 = elt(env, 4); /* exp */
    fn = elt(env, 10); /* unary */
    v59 = (*qfn2(fn))(qenv(fn), v5, v59);
    nil = C_nil;
    if (exception_pending()) goto v262;
    goto v147;

v147:
    v59 = nil;
    { popv(3); return onevalue(v59); }

v271:
    v59 = elt(env, 5); /* "<apply>" */
    fn = elt(env, 11); /* printout */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-2];
    v59 = elt(env, 6); /* "<" */
    v59 = Lprinc(nil, v59);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-2];
    v59 = stack[0];
    v59 = Lprinc(nil, v59);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-2];
    v59 = elt(env, 7); /* "/>" */
    v59 = Lprinc(nil, v59);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-2];
    v5 = qvalue(elt(env, 8)); /* indent */
    v59 = (Lisp_Object)49; /* 3 */
    v59 = plus2(v5, v59);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-2];
    qvalue(elt(env, 8)) = v59; /* indent */
    v59 = stack[-1];
    fn = elt(env, 12); /* multi_elem */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-2];
    v5 = qvalue(elt(env, 8)); /* indent */
    v59 = (Lisp_Object)49; /* 3 */
    v59 = difference2(v5, v59);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-2];
    qvalue(elt(env, 8)) = v59; /* indent */
    v59 = elt(env, 9); /* "</apply>" */
    fn = elt(env, 11); /* printout */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v262;
    goto v147;

v31:
    v5 = stack[0];
    v59 = elt(env, 2); /* power */
    v59 = (v5 == v59 ? lisp_true : nil);
    goto v65;
/* error exit handlers */
v262:
    popv(3);
    return nil;
}



/* Code for exptplus */

static Lisp_Object CC_exptplus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v256, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptplus");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v256 = v1;
    v111 = v0;
/* end of prologue */
    v109 = v111;
    if (!consp(v109)) goto v35;
    v109 = v256;
    if (!consp(v109)) goto v102;
    v109 = elt(env, 1); /* "Bad exponent sum" */
    {
        fn = elt(env, 2); /* interr */
        return (*qfn1(fn))(qenv(fn), v109);
    }

v102:
    v109 = v111;
    v109 = qcar(v109);
    v109 = plus2(v109, v256);
    errexit();
    return ncons(v109);

v35:
    v109 = v256;
    if (!consp(v109)) goto v26;
    v109 = v111;
    v256 = qcar(v256);
    v109 = plus2(v109, v256);
    errexit();
    return ncons(v109);

v26:
    v109 = v111;
    return plus2(v109, v256);
}



/* Code for reform!-minus */

static Lisp_Object CC_reformKminus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v273, v278, v279;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reform-minus");
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
    v273 = stack[0];
    if (v273 == nil) goto v112;
    v273 = stack[-1];
    v273 = (v273 == nil ? lisp_true : nil);
    goto v18;

v18:
    if (!(v273 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v273 = stack[-1];
    v273 = qcar(v273);
    v278 = stack[0];
    v279 = qcar(v278);
    v278 = elt(env, 2); /* minus */
    if (!consp(v279)) goto v59;
    v279 = qcar(v279);
    if (!(v279 == v278)) goto v59;
    v279 = v273;
    v278 = elt(env, 3); /* quotient */
    if (!consp(v279)) goto v100;
    v279 = qcar(v279);
    if (!(v279 == v278)) goto v100;
    v278 = v273;
    v278 = qcdr(v278);
    v279 = qcar(v278);
    v278 = elt(env, 2); /* minus */
    v278 = Leqcar(nil, v279, v278);
    env = stack[-3];
    goto v23;

v23:
    if (v278 == nil) goto v95;
    stack[-2] = elt(env, 2); /* minus */
    v279 = elt(env, 3); /* quotient */
    v278 = v273;
    v278 = qcdr(v278);
    v278 = qcar(v278);
    v278 = qcdr(v278);
    v278 = qcar(v278);
    v273 = qcdr(v273);
    v273 = qcdr(v273);
    v273 = qcar(v273);
    v273 = list3(v279, v278, v273);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-3];
    v273 = list2(stack[-2], v273);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-3];
    stack[-2] = v273;
    goto v166;

v166:
    v273 = stack[-1];
    v278 = qcdr(v273);
    v273 = stack[0];
    v273 = qcdr(v273);
    v273 = CC_reformKminus(env, v278, v273);
    nil = C_nil;
    if (exception_pending()) goto v254;
    {
        Lisp_Object v276 = stack[-2];
        popv(4);
        return cons(v276, v273);
    }

v95:
    stack[-2] = v273;
    goto v166;

v100:
    v278 = qvalue(elt(env, 4)); /* nil */
    goto v23;

v59:
    v278 = qvalue(elt(env, 4)); /* nil */
    goto v23;

v112:
    v273 = qvalue(elt(env, 1)); /* t */
    goto v18;
/* error exit handlers */
v254:
    popv(4);
    return nil;
}



/* Code for matrixp */

static Lisp_Object CC_matrixp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v68;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v90 = v0;
/* end of prologue */
    v68 = v90;
    v90 = elt(env, 1); /* mat */
    if (!consp(v68)) goto v24;
    v68 = qcar(v68);
    if (!(v68 == v90)) goto v24;
    v90 = qvalue(elt(env, 3)); /* t */
    return onevalue(v90);

v24:
    v90 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v90);
}



/* Code for evload */

static Lisp_Object CC_evload(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evload");
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

v24:
    v36 = stack[0];
    if (v36 == nil) goto v70;
    v36 = stack[0];
    v36 = qcar(v36);
    v36 = Lload_module(nil, v36);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-1];
    v36 = stack[0];
    v36 = qcdr(v36);
    stack[0] = v36;
    goto v24;

v70:
    v36 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v36); }
/* error exit handlers */
v90:
    popv(2);
    return nil;
}



/* Code for ncoeffs */

static Lisp_Object CC_ncoeffs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v5;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ncoeffs");
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
    v5 = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = nil;
    v59 = (Lisp_Object)1; /* 0 */
    stack[-2] = v59;
    v59 = v5;
    stack[-1] = v59;
    goto v69;

v69:
    v59 = stack[-1];
    if (v59 == nil) goto v57;
    v59 = stack[-1];
    v59 = qcar(v59);
    stack[0] = v59;
    v59 = stack[0];
    v59 = qcar(v59);
    stack[-4] = v59;
    goto v64;

v64:
    v5 = stack[-2];
    v59 = stack[-4];
    v59 = (Lisp_Object)lessp2(v5, v59);
    nil = C_nil;
    if (exception_pending()) goto v21;
    v59 = v59 ? lisp_true : nil;
    env = stack[-5];
    if (v59 == nil) goto v12;
    v5 = qvalue(elt(env, 1)); /* nil */
    v59 = stack[-3];
    v59 = cons(v5, v59);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    stack[-3] = v59;
    v59 = stack[-2];
    v59 = add1(v59);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    stack[-2] = v59;
    goto v64;

v12:
    v59 = stack[-2];
    v59 = add1(v59);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    stack[-2] = v59;
    v59 = stack[0];
    v5 = qcdr(v59);
    v59 = stack[-3];
    v59 = cons(v5, v59);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    stack[-3] = v59;
    v59 = stack[-1];
    v59 = qcdr(v59);
    stack[-1] = v59;
    goto v69;

v57:
    v5 = stack[-4];
    v59 = stack[-3];
    popv(6);
    return cons(v5, v59);
/* error exit handlers */
v21:
    popv(6);
    return nil;
}



/* Code for getphystypetimes */

static Lisp_Object CC_getphystypetimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v277, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystypetimes");
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
    stack[-1] = qvalue(elt(env, 1)); /* nil */
    v277 = stack[0];
    fn = elt(env, 3); /* collectphystype */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-2];
    fn = elt(env, 4); /* deleteall */
    v277 = (*qfn2(fn))(qenv(fn), stack[-1], v277);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-2];
    v9 = v277;
    if (v277 == nil) goto v70;
    v277 = v9;
    v277 = qcdr(v277);
    if (v277 == nil) goto v68;
    stack[-1] = elt(env, 0); /* getphystypetimes */
    v9 = elt(env, 2); /* "PHYSOP type mismatch in" */
    v277 = stack[0];
    v277 = list2(v9, v277);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-2];
    fn = elt(env, 5); /* rederr2 */
    v277 = (*qfn2(fn))(qenv(fn), stack[-1], v277);
    nil = C_nil;
    if (exception_pending()) goto v62;
    v277 = nil;
    { popv(3); return onevalue(v277); }

v68:
    v277 = v9;
    v277 = qcar(v277);
    { popv(3); return onevalue(v277); }

v70:
    v277 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v277); }
/* error exit handlers */
v62:
    popv(3);
    return nil;
}



/* Code for prop!-simp1 */

static Lisp_Object MS_CDECL CC_propKsimp1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v48, Lisp_Object v8,
                         Lisp_Object v24, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v254, v276, v230;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "prop-simp1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prop-simp1");
#endif
    if (stack >= stacklimit)
    {
        push5(v24,v8,v48,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v48,v8,v24);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v24;
    stack[0] = v8;
    stack[-5] = v48;
    stack[-2] = v1;
    stack[-6] = v0;
/* end of prologue */

v17:
    v254 = stack[-2];
    if (v254 == nil) goto v38;
    v276 = stack[-6];
    v254 = stack[-2];
    v254 = qcar(v254);
    fn = elt(env, 1); /* prop!-simp2 */
    v254 = (*qfn2(fn))(qenv(fn), v276, v254);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-8];
    stack[-3] = v254;
    v254 = stack[-3];
    if (v254 == nil) goto v63;
    v254 = stack[-3];
    stack[-6] = qcdr(v254);
    v254 = stack[-2];
    stack[-2] = qcdr(v254);
    stack[-1] = stack[-5];
    v254 = stack[0];
    stack[0] = add1(v254);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-8];
    v254 = stack[-3];
    stack[-7] = qcar(v254);
    stack[-3] = (Lisp_Object)-15; /* -1 */
    v254 = stack[-5];
    v254 = Llength(nil, v254);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-8];
    v254 = Lexpt(nil, stack[-3], v254);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-8];
    v254 = times2(stack[-4], v254);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-8];
    v254 = times2(stack[-7], v254);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-8];
    stack[-5] = stack[-1];
    stack[-4] = v254;
    goto v17;

v63:
    stack[-3] = stack[-6];
    v254 = stack[-2];
    stack[-1] = qcdr(v254);
    v254 = stack[-2];
    v276 = qcar(v254);
    v254 = stack[-5];
    v230 = cons(v276, v254);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-8];
    v276 = stack[0];
    v254 = stack[-4];
    stack[-6] = stack[-3];
    stack[-2] = stack[-1];
    stack[-5] = v230;
    stack[0] = v276;
    stack[-4] = v254;
    goto v17;

v38:
    v276 = stack[0];
    v254 = stack[-4];
    stack[0] = list2(v276, v254);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-8];
    stack[-1] = stack[-6];
    v254 = stack[-5];
    v254 = Lreverse(nil, v254);
    nil = C_nil;
    if (exception_pending()) goto v42;
    {
        Lisp_Object v43 = stack[0];
        Lisp_Object v165 = stack[-1];
        popv(9);
        return list2star(v43, v165, v254);
    }
/* error exit handlers */
v42:
    popv(9);
    return nil;
}



/* Code for comblog */

static Lisp_Object CC_comblog(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v226;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comblog");
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
    stack[0] = v0;
/* end of prologue */
    stack[-1] = nil;
    goto v35;

v35:
    v45 = stack[0];
    if (!consp(v45)) goto v268;
    v45 = stack[0];
    v226 = qcar(v45);
    v45 = qvalue(elt(env, 2)); /* domainlist!* */
    v45 = Lmemq(nil, v226, v45);
    goto v69;

v69:
    if (v45 == nil) goto v271;
    v226 = stack[-1];
    v45 = stack[0];
    {
        popv(4);
        fn = elt(env, 7); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v226, v45);
    }

v271:
    v45 = stack[0];
    v226 = qcar(v45);
    v45 = elt(env, 3); /* plus */
    if (v226 == v45) goto v28;
    v45 = stack[0];
    v226 = qcar(v45);
    v45 = elt(env, 4); /* times */
    if (v226 == v45) goto v88;
    v45 = qvalue(elt(env, 6)); /* nil */
    goto v102;

v102:
    if (v45 == nil) goto v281;
    stack[-2] = stack[-1];
    v45 = stack[0];
    fn = elt(env, 8); /* simp!* */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-3];
    stack[-1] = v45;
    v45 = stack[-1];
    v45 = qcar(v45);
    fn = elt(env, 9); /* clogf */
    stack[0] = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-3];
    v45 = stack[-1];
    v45 = qcdr(v45);
    fn = elt(env, 9); /* clogf */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-3];
    v45 = cons(stack[0], v45);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-3];
    fn = elt(env, 10); /* prepsq!* */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-3];
    {
        Lisp_Object v46 = stack[-2];
        popv(4);
        fn = elt(env, 7); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v46, v45);
    }

v281:
    v45 = stack[0];
    v45 = qcar(v45);
    v226 = CC_comblog(env, v45);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-3];
    v45 = stack[-1];
    v45 = cons(v226, v45);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-3];
    stack[-1] = v45;
    v45 = stack[0];
    v45 = qcdr(v45);
    stack[0] = v45;
    goto v35;

v88:
    v45 = stack[0];
    fn = elt(env, 8); /* simp!* */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-3];
    v45 = qcar(v45);
    v226 = v45;
    v45 = v226;
    if (!consp(v45)) goto v235;
    v45 = v226;
    v45 = qcar(v45);
    v45 = (consp(v45) ? nil : lisp_true);
    goto v106;

v106:
    if (v45 == nil) goto v3;
    v45 = qvalue(elt(env, 6)); /* nil */
    goto v102;

v3:
    v45 = v226;
    v45 = qcar(v45);
    v45 = qcar(v45);
    v226 = qcar(v45);
    v45 = elt(env, 5); /* log */
    v45 = Leqcar(nil, v226, v45);
    env = stack[-3];
    goto v102;

v235:
    v45 = qvalue(elt(env, 1)); /* t */
    goto v106;

v28:
    v45 = qvalue(elt(env, 1)); /* t */
    goto v102;

v268:
    v45 = qvalue(elt(env, 1)); /* t */
    goto v69;
/* error exit handlers */
v253:
    popv(4);
    return nil;
}



/* Code for st_ad_numsorttree */

static Lisp_Object CC_st_ad_numsorttree(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_ad_numsorttree");
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
    v90 = v0;
/* end of prologue */
    fn = elt(env, 1); /* st_ad_numsorttree1 */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    errexit();
    v68 = v90;
    v68 = qcar(v68);
    v90 = qcdr(v90);
    v90 = qcar(v90);
    return cons(v68, v90);
}



/* Code for monomgetfirstmultivar */

static Lisp_Object CC_monomgetfirstmultivar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v105, v171;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monomgetfirstmultivar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v105 = v0;
/* end of prologue */
    v171 = v105;
    v104 = (Lisp_Object)17; /* 1 */
    v104 = *(Lisp_Object *)((char *)v171 + (CELL-TAG_VECTOR) + ((int32_t)v104/(16/CELL)));
    v104 = qcar(v104);
    if (v104 == nil) goto v32;
    v104 = (Lisp_Object)17; /* 1 */
    v104 = *(Lisp_Object *)((char *)v105 + (CELL-TAG_VECTOR) + ((int32_t)v104/(16/CELL)));
    v104 = qcar(v104);
    return onevalue(v104);

v32:
    v104 = (Lisp_Object)17; /* 1 */
    return onevalue(v104);
}



/* Code for om2ir */

static Lisp_Object MS_CDECL CC_om2ir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v255;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "om2ir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for om2ir");
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
    v100 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v100;
    v100 = elt(env, 2); /* (safe_atts char ch atts count temp space temp2) 
*/
    fn = elt(env, 13); /* fluid */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    v255 = elt(env, 3); /* !! */
    v100 = (Lisp_Object)513; /* 32 */
    v100 = list2(v255, v100);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    v100 = Lcompress(nil, v100);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    qvalue(elt(env, 4)) = v100; /* space */
    v100 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 5)) = v100; /* count */
    v100 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    qvalue(elt(env, 6)) = v100; /* ch */
    v100 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 7)) = v100; /* temp2 */
    fn = elt(env, 14); /* lex */
    v100 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    v255 = qvalue(elt(env, 8)); /* char */
    v100 = elt(env, 9); /* (o m o b j) */
    if (equal(v255, v100)) goto v39;
    v255 = elt(env, 10); /* "<omobj>" */
    v100 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 15); /* errorml */
    v100 = (*qfn2(fn))(qenv(fn), v255, v100);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    goto v31;

v31:
    fn = elt(env, 14); /* lex */
    v100 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    v255 = qvalue(elt(env, 8)); /* char */
    v100 = elt(env, 11); /* (!/ o m o b j) */
    if (equal(v255, v100)) goto v103;
    v255 = elt(env, 12); /* "</omobj>" */
    v100 = (Lisp_Object)305; /* 19 */
    fn = elt(env, 15); /* errorml */
    v100 = (*qfn2(fn))(qenv(fn), v255, v100);
    nil = C_nil;
    if (exception_pending()) goto v59;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v103:
    v100 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v39:
    fn = elt(env, 14); /* lex */
    v100 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    fn = elt(env, 16); /* omobj */
    v100 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    stack[0] = v100;
    goto v31;
/* error exit handlers */
v59:
    popv(2);
    return nil;
}



/* Code for ps!:depvar */

static Lisp_Object CC_psTdepvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v109, v256;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:depvar");
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
    v109 = v0;
/* end of prologue */
    v108 = v109;
    if (!consp(v108)) goto v18;
    v108 = v109;
    v256 = qcar(v108);
    v108 = elt(env, 2); /* !:ps!: */
    if (v256 == v108) goto v13;
    v108 = v109;
    v256 = qcar(v108);
    v108 = elt(env, 3); /* dname */
    v108 = get(v256, v108);
    env = stack[0];
    goto v70;

v70:
    if (v108 == nil) goto v30;
    v108 = qvalue(elt(env, 4)); /* nil */
    { popv(1); return onevalue(v108); }

v30:
    v108 = (Lisp_Object)33; /* 2 */
    {
        popv(1);
        fn = elt(env, 5); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v109, v108);
    }

v13:
    v108 = qvalue(elt(env, 4)); /* nil */
    goto v70;

v18:
    v108 = qvalue(elt(env, 1)); /* t */
    goto v70;
}



/* Code for crn!:minusp */

static Lisp_Object CC_crnTminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v12, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crn:minusp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v0;
/* end of prologue */
    v25 = v32;
    v25 = qcdr(v25);
    v25 = qcdr(v25);
    v12 = qcar(v25);
    v25 = (Lisp_Object)1; /* 0 */
    if (v12 == v25) goto v24;
    v25 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v25);

v24:
    v25 = v32;
    v25 = qcdr(v25);
    v25 = qcar(v25);
    v25 = qcar(v25);
        return Lminusp(nil, v25);
}



/* Code for rootextractsq */

static Lisp_Object CC_rootextractsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rootextractsq");
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
    v33 = v0;
/* end of prologue */
    v32 = v33;
    v32 = qcar(v32);
    if (v32 == nil) { popv(3); return onevalue(v33); }
    v32 = v33;
    fn = elt(env, 1); /* subs2q */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    stack[-1] = v32;
    v32 = stack[-1];
    v32 = qcar(v32);
    fn = elt(env, 2); /* rootextractf */
    stack[0] = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    v32 = stack[-1];
    v32 = qcdr(v32);
    fn = elt(env, 2); /* rootextractf */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v105;
    {
        Lisp_Object v171 = stack[0];
        popv(3);
        return cons(v171, v32);
    }
/* error exit handlers */
v105:
    popv(3);
    return nil;
}



/* Code for delhisto */

static Lisp_Object CC_delhisto(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v217, v218, v283;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delhisto");
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
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v218 = qvalue(elt(env, 2)); /* maxvar */
    v217 = stack[-2];
    v217 = plus2(v218, v217);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-4];
    v218 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    v217 = (Lisp_Object)1; /* 0 */
    v217 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    if (v217 == nil) goto v35;
    v218 = stack[-2];
    v217 = (Lisp_Object)1; /* 0 */
    v217 = (Lisp_Object)geq2(v218, v217);
    nil = C_nil;
    if (exception_pending()) goto v284;
    v217 = v217 ? lisp_true : nil;
    env = stack[-4];
    if (v217 == nil) goto v35;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v218 = qvalue(elt(env, 2)); /* maxvar */
    v217 = stack[-2];
    v217 = plus2(v218, v217);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-4];
    v218 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    v217 = (Lisp_Object)113; /* 7 */
    v217 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    v217 = qcar(v217);
    stack[-3] = v217;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v218 = qvalue(elt(env, 2)); /* maxvar */
    v217 = stack[-2];
    v217 = plus2(v218, v217);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-4];
    v218 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    v217 = (Lisp_Object)113; /* 7 */
    v217 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    v217 = qcdr(v217);
    stack[-1] = v217;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v218 = qvalue(elt(env, 2)); /* maxvar */
    v217 = stack[-2];
    v217 = plus2(v218, v217);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-4];
    v218 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    v217 = (Lisp_Object)17; /* 1 */
    v217 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    v218 = qcdr(v217);
    v217 = (Lisp_Object)3201; /* 200 */
    fn = elt(env, 4); /* min */
    v217 = (*qfn2(fn))(qenv(fn), v218, v217);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-4];
    v218 = stack[-3];
    if (v218 == nil) goto v285;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v218 = qvalue(elt(env, 2)); /* maxvar */
    v217 = stack[-3];
    v217 = plus2(v218, v217);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-4];
    v218 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    v217 = (Lisp_Object)113; /* 7 */
    v218 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    v217 = stack[-1];
    v217 = Lrplacd(nil, v218, v217);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-4];
    goto v230;

v230:
    v217 = stack[-1];
    if (v217 == nil) goto v92;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v218 = qvalue(elt(env, 2)); /* maxvar */
    v217 = stack[-1];
    v217 = plus2(v218, v217);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-4];
    v218 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    v217 = (Lisp_Object)113; /* 7 */
    v218 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    v217 = stack[-3];
    v217 = Lrplaca(nil, v218, v217);
    nil = C_nil;
    if (exception_pending()) goto v284;
    goto v92;

v92:
    v217 = nil;
    { popv(5); return onevalue(v217); }

v285:
    v283 = qvalue(elt(env, 3)); /* codhisto */
    v218 = v217;
    v217 = stack[-1];
    *(Lisp_Object *)((char *)v283 + (CELL-TAG_VECTOR) + ((int32_t)v218/(16/CELL))) = v217;
    goto v230;

v35:
    v217 = nil;
    { popv(5); return onevalue(v217); }
/* error exit handlers */
v284:
    popv(5);
    return nil;
}



/* Code for rmsubs */

static Lisp_Object MS_CDECL CC_rmsubs(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v36;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rmsubs");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rmsubs");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v36 = qvalue(elt(env, 1)); /* !*sqvar!* */
    v27 = qvalue(elt(env, 2)); /* nil */
    v27 = Lrplaca(nil, v36, v27);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[0];
    v27 = qvalue(elt(env, 3)); /* t */
    v27 = ncons(v27);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[0];
    qvalue(elt(env, 1)) = v27; /* !*sqvar!* */
    v27 = qvalue(elt(env, 2)); /* nil */
    v27 = ncons(v27);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[0];
    qvalue(elt(env, 4)) = v27; /* alglist!* */
    v27 = nil;
    { popv(1); return onevalue(v27); }
/* error exit handlers */
v37:
    popv(1);
    return nil;
}



/* Code for setdmode */

static Lisp_Object CC_setdmode(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v178, v221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setdmode");
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
    v178 = stack[-1];
    v159 = elt(env, 1); /* dname */
    v159 = get(v178, v159);
    env = stack[-3];
    stack[-2] = v159;
    if (v159 == nil) goto v11;
    v159 = stack[-2];
    stack[-1] = v159;
    goto v11;

v11:
    v178 = stack[-1];
    v159 = elt(env, 2); /* complex!-rational */
    if (v178 == v159) goto v31;
    v178 = stack[-1];
    v159 = elt(env, 6); /* complex!-rounded */
    if (v178 == v159) goto v168;
    v178 = stack[-1];
    v159 = elt(env, 8); /* tag */
    v159 = get(v178, v159);
    env = stack[-3];
    if (!(v159 == nil)) goto v227;
    v221 = elt(env, 9); /* "Domain mode error:" */
    v178 = stack[-1];
    v159 = elt(env, 10); /* "is not a domain mode" */
    v159 = list3(v221, v178, v159);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-3];
    v178 = v159;
    v159 = v178;
    qvalue(elt(env, 11)) = v159; /* errmsg!* */
    v159 = qvalue(elt(env, 12)); /* !*protfg */
    if (!(v159 == nil)) goto v287;
    v159 = v178;
    fn = elt(env, 16); /* lprie */
    v159 = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-3];
    goto v287;

v287:
    v159 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-3];
    goto v227;

v227:
    v178 = stack[-1];
    v159 = elt(env, 13); /* package!-name */
    v159 = get(v178, v159);
    env = stack[-3];
    stack[-2] = v159;
    if (v159 == nil) goto v288;
    v159 = stack[-2];
    fn = elt(env, 17); /* load!-package */
    v159 = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-3];
    goto v288;

v288:
    v178 = stack[-1];
    v159 = elt(env, 4); /* complex */
    if (v178 == v159) goto v67;
    v159 = qvalue(elt(env, 15)); /* !*complex */
    goto v66;

v66:
    if (v159 == nil) goto v289;
    v178 = stack[-1];
    v159 = stack[0];
    {
        popv(4);
        fn = elt(env, 18); /* setcmpxmode */
        return (*qfn2(fn))(qenv(fn), v178, v159);
    }

v289:
    v178 = stack[-1];
    v159 = stack[0];
    {
        popv(4);
        fn = elt(env, 19); /* setdmode1 */
        return (*qfn2(fn))(qenv(fn), v178, v159);
    }

v67:
    v159 = qvalue(elt(env, 14)); /* t */
    goto v66;

v168:
    v159 = qvalue(elt(env, 3)); /* dmode!* */
    stack[-2] = v159;
    if (v159 == nil) goto v85;
    v178 = stack[-2];
    v159 = elt(env, 1); /* dname */
    v159 = get(v178, v159);
    env = stack[-3];
    stack[-2] = v159;
    goto v85;

v85:
    v178 = elt(env, 4); /* complex */
    v159 = stack[0];
    fn = elt(env, 20); /* onoff */
    v159 = (*qfn2(fn))(qenv(fn), v178, v159);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-3];
    v178 = elt(env, 7); /* rounded */
    v159 = stack[0];
    fn = elt(env, 20); /* onoff */
    v159 = (*qfn2(fn))(qenv(fn), v178, v159);
    nil = C_nil;
    if (exception_pending()) goto v251;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v31:
    v159 = qvalue(elt(env, 3)); /* dmode!* */
    stack[-2] = v159;
    if (v159 == nil) goto v30;
    v178 = stack[-2];
    v159 = elt(env, 1); /* dname */
    v159 = get(v178, v159);
    env = stack[-3];
    stack[-2] = v159;
    goto v30;

v30:
    v178 = elt(env, 4); /* complex */
    v159 = stack[0];
    fn = elt(env, 20); /* onoff */
    v159 = (*qfn2(fn))(qenv(fn), v178, v159);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-3];
    v178 = elt(env, 5); /* rational */
    v159 = stack[0];
    fn = elt(env, 20); /* onoff */
    v159 = (*qfn2(fn))(qenv(fn), v178, v159);
    nil = C_nil;
    if (exception_pending()) goto v251;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v251:
    popv(4);
    return nil;
}



/* Code for bcminus!? */

static Lisp_Object CC_bcminusW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcminus?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v26 = v0;
/* end of prologue */
    v110 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v110 == nil) goto v24;
    v110 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v110);

v24:
    v110 = v26;
    v110 = qcar(v110);
    {
        fn = elt(env, 3); /* minusf */
        return (*qfn1(fn))(qenv(fn), v110);
    }
}



setup_type const u21_setup[] =
{
    {"ev_invlexcomp",           too_few_2,      CC_ev_invlexcomp,wrong_no_2},
    {"unaryir",                 too_few_2,      CC_unaryir,    wrong_no_2},
    {"ps:prepfn:",              CC_psTprepfnT,  too_many_1,    wrong_no_1},
    {"quoteequation",           CC_quoteequation,too_many_1,   wrong_no_1},
    {"gcompatible",             too_few_2,      CC_gcompatible,wrong_no_2},
    {"dipsimpcont",             CC_dipsimpcont, too_many_1,    wrong_no_1},
    {"memqcar",                 too_few_2,      CC_memqcar,    wrong_no_2},
    {"random",                  CC_random,      too_many_1,    wrong_no_1},
    {"assert_structstat",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_structstat},
    {"changearg",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_changearg},
    {"fs:null-angle",           CC_fsTnullKangle,too_many_1,   wrong_no_1},
    {"exptpri",                 too_few_2,      CC_exptpri,    wrong_no_2},
    {"pa_coinc_split",          too_few_2,      CC_pa_coinc_split,wrong_no_2},
    {"lambda_lqgavy_5",         too_few_2,      CC_lambda_lqgavy_5,wrong_no_2},
    {"subsublis",               too_few_2,      CC_subsublis,  wrong_no_2},
    {"ordexn",                  too_few_2,      CC_ordexn,     wrong_no_2},
    {"monomwrite",              CC_monomwrite,  too_many_1,    wrong_no_1},
    {"cl_fvarl",                CC_cl_fvarl,    too_many_1,    wrong_no_1},
    {"dfconst",                 CC_dfconst,     too_many_1,    wrong_no_1},
    {"mml2ir",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mml2ir},
    {"ps:value",                CC_psTvalue,    too_many_1,    wrong_no_1},
    {"gf2cr:",                  CC_gf2crT,      too_many_1,    wrong_no_1},
    {"rdcos*",                  CC_rdcosH,      too_many_1,    wrong_no_1},
    {"powers3",                 too_few_2,      CC_powers3,    wrong_no_2},
    {"collectphystype",         CC_collectphystype,too_many_1, wrong_no_1},
    {"calc_atlas",              too_few_2,      CC_calc_atlas, wrong_no_2},
    {"one-entryp",              too_few_2,      CC_oneKentryp, wrong_no_2},
    {"mv-domainlist",           CC_mvKdomainlist,too_many_1,   wrong_no_1},
    {"mo_from_a",               CC_mo_from_a,   too_many_1,    wrong_no_1},
    {"primep",                  CC_primep,      too_many_1,    wrong_no_1},
    {"safe-modrecip",           CC_safeKmodrecip,too_many_1,   wrong_no_1},
    {"evaluate-in-order-mod-p", too_few_2,      CC_evaluateKinKorderKmodKp,wrong_no_2},
    {"rl_bettergaussp",         too_few_2,      CC_rl_bettergaussp,wrong_no_2},
    {"tayexp-minus",            CC_tayexpKminus,too_many_1,    wrong_no_1},
    {"matpri",                  CC_matpri,      too_many_1,    wrong_no_1},
    {"ev_lexcomp",              too_few_2,      CC_ev_lexcomp, wrong_no_2},
    {"cl_sacatl",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_sacatl},
    {"matrixrowom",             CC_matrixrowom, too_many_1,    wrong_no_1},
    {"n_nary",                  too_few_2,      CC_n_nary,     wrong_no_2},
    {"exptplus",                too_few_2,      CC_exptplus,   wrong_no_2},
    {"reform-minus",            too_few_2,      CC_reformKminus,wrong_no_2},
    {"matrixp",                 CC_matrixp,     too_many_1,    wrong_no_1},
    {"evload",                  CC_evload,      too_many_1,    wrong_no_1},
    {"ncoeffs",                 CC_ncoeffs,     too_many_1,    wrong_no_1},
    {"getphystypetimes",        CC_getphystypetimes,too_many_1,wrong_no_1},
    {"prop-simp1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_propKsimp1},
    {"comblog",                 CC_comblog,     too_many_1,    wrong_no_1},
    {"st_ad_numsorttree",       CC_st_ad_numsorttree,too_many_1,wrong_no_1},
    {"monomgetfirstmultivar",   CC_monomgetfirstmultivar,too_many_1,wrong_no_1},
    {"om2ir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_om2ir},
    {"ps:depvar",               CC_psTdepvar,   too_many_1,    wrong_no_1},
    {"crn:minusp",              CC_crnTminusp,  too_many_1,    wrong_no_1},
    {"rootextractsq",           CC_rootextractsq,too_many_1,   wrong_no_1},
    {"delhisto",                CC_delhisto,    too_many_1,    wrong_no_1},
    {"rmsubs",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_rmsubs},
    {"setdmode",                too_few_2,      CC_setdmode,   wrong_no_2},
    {"bcminus?",                CC_bcminusW,    too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u21", (two_args *)"4084 9696751 9384272", 0}
};

/* end of generated code */
