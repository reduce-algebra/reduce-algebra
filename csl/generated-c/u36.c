
/* $destdir\u36.c        Machine generated C code */

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


/* Code for mk!+mat!+plus!+mat */

static Lisp_Object CC_mkLmatLplusLmat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v70, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+mat+plus+mat");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v1;
    stack[-11] = v0;
/* end of prologue */
    v69 = stack[-11];
    fn = elt(env, 7); /* matrix!+p */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    if (!(v69 == nil)) goto v73;
    v69 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v69 == nil)) goto v74;
    v69 = elt(env, 2); /* "no matrix in add" */
    fn = elt(env, 8); /* lprie */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    goto v74;

v74:
    v69 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    goto v73;

v73:
    v69 = stack[-10];
    fn = elt(env, 7); /* matrix!+p */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    if (!(v69 == nil)) goto v75;
    v69 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v69 == nil)) goto v76;
    v69 = elt(env, 2); /* "no matrix in add" */
    fn = elt(env, 8); /* lprie */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    goto v76;

v76:
    v69 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    goto v75;

v75:
    v69 = stack[-11];
    fn = elt(env, 9); /* get!+col!+nr */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    stack[-12] = v69;
    v69 = stack[-11];
    fn = elt(env, 10); /* get!+row!+nr */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    stack[-9] = v69;
    stack[0] = stack[-12];
    v69 = stack[-10];
    fn = elt(env, 9); /* get!+col!+nr */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    if (equal(stack[0], v69)) goto v77;
    v69 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v69 == nil)) goto v78;
    v69 = elt(env, 3); /* "wrong dimensions in add" */
    fn = elt(env, 8); /* lprie */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    goto v78;

v78:
    v69 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    goto v77;

v77:
    stack[0] = stack[-9];
    v69 = stack[-10];
    fn = elt(env, 10); /* get!+row!+nr */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    if (equal(stack[0], v69)) goto v79;
    v69 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v69 == nil)) goto v80;
    v69 = elt(env, 3); /* "wrong dimensions in add" */
    fn = elt(env, 8); /* lprie */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    goto v80;

v80:
    v69 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    goto v79;

v79:
    v69 = (Lisp_Object)17; /* 1 */
    stack[-8] = v69;
    v70 = stack[-9];
    v69 = stack[-8];
    v69 = difference2(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v69 = Lminusp(nil, v69);
    env = stack[-13];
    if (v69 == nil) goto v81;
    v69 = qvalue(elt(env, 4)); /* nil */
    { popv(14); return onevalue(v69); }

v81:
    v69 = (Lisp_Object)17; /* 1 */
    stack[-4] = v69;
    v70 = stack[-12];
    v69 = stack[-4];
    v69 = difference2(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v69 = Lminusp(nil, v69);
    env = stack[-13];
    if (v69 == nil) goto v82;
    v69 = qvalue(elt(env, 4)); /* nil */
    goto v83;

v83:
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    stack[-6] = v69;
    stack[-7] = v69;
    goto v84;

v84:
    v69 = stack[-8];
    v69 = add1(v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    stack[-8] = v69;
    v70 = stack[-9];
    v69 = stack[-8];
    v69 = difference2(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v69 = Lminusp(nil, v69);
    env = stack[-13];
    if (!(v69 == nil)) { Lisp_Object res = stack[-7]; popv(14); return onevalue(res); }
    stack[-5] = stack[-6];
    v69 = (Lisp_Object)17; /* 1 */
    stack[-4] = v69;
    v70 = stack[-12];
    v69 = stack[-4];
    v69 = difference2(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v69 = Lminusp(nil, v69);
    env = stack[-13];
    if (v69 == nil) goto v85;
    v69 = qvalue(elt(env, 4)); /* nil */
    goto v86;

v86:
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v69 = Lrplacd(nil, stack[-5], v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v69 = stack[-6];
    v69 = qcdr(v69);
    stack[-6] = v69;
    goto v84;

v85:
    v71 = stack[-11];
    v70 = stack[-8];
    v69 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v71, v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v71 = stack[-10];
    v70 = stack[-8];
    v69 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    v69 = (*qfnn(fn))(qenv(fn), 3, v71, v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    fn = elt(env, 12); /* addsq */
    v69 = (*qfn2(fn))(qenv(fn), stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v70 = v69;
    v69 = qvalue(elt(env, 5)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v69; /* !*sub2 */
    v69 = v70;
    fn = elt(env, 13); /* subs2 */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-13];
    v70 = v69;
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    v69 = v70;
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    stack[-2] = v69;
    stack[-3] = v69;
    goto v88;

v88:
    v69 = stack[-4];
    v69 = add1(v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    stack[-4] = v69;
    v70 = stack[-12];
    v69 = stack[-4];
    v69 = difference2(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v69 = Lminusp(nil, v69);
    env = stack[-13];
    if (v69 == nil) goto v89;
    v69 = stack[-3];
    goto v86;

v89:
    stack[-1] = stack[-2];
    v71 = stack[-11];
    v70 = stack[-8];
    v69 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v71, v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v71 = stack[-10];
    v70 = stack[-8];
    v69 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    v69 = (*qfnn(fn))(qenv(fn), 3, v71, v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    fn = elt(env, 12); /* addsq */
    v69 = (*qfn2(fn))(qenv(fn), stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v70 = v69;
    v69 = qvalue(elt(env, 5)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v69; /* !*sub2 */
    v69 = v70;
    fn = elt(env, 13); /* subs2 */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-13];
    v70 = v69;
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    v69 = v70;
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v69 = Lrplacd(nil, stack[-1], v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v69 = stack[-2];
    v69 = qcdr(v69);
    stack[-2] = v69;
    goto v88;

v82:
    v71 = stack[-11];
    v70 = stack[-8];
    v69 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v71, v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v71 = stack[-10];
    v70 = stack[-8];
    v69 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    v69 = (*qfnn(fn))(qenv(fn), 3, v71, v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    fn = elt(env, 12); /* addsq */
    v69 = (*qfn2(fn))(qenv(fn), stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v70 = v69;
    v69 = qvalue(elt(env, 5)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v69; /* !*sub2 */
    v69 = v70;
    fn = elt(env, 13); /* subs2 */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-13];
    v70 = v69;
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    v69 = v70;
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    stack[-2] = v69;
    stack[-3] = v69;
    goto v92;

v92:
    v69 = stack[-4];
    v69 = add1(v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    stack[-4] = v69;
    v70 = stack[-12];
    v69 = stack[-4];
    v69 = difference2(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v69 = Lminusp(nil, v69);
    env = stack[-13];
    if (v69 == nil) goto v93;
    v69 = stack[-3];
    goto v83;

v93:
    stack[-1] = stack[-2];
    v71 = stack[-11];
    v70 = stack[-8];
    v69 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v71, v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v71 = stack[-10];
    v70 = stack[-8];
    v69 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    v69 = (*qfnn(fn))(qenv(fn), 3, v71, v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    fn = elt(env, 12); /* addsq */
    v69 = (*qfn2(fn))(qenv(fn), stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v70 = v69;
    v69 = qvalue(elt(env, 5)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v69; /* !*sub2 */
    v69 = v70;
    fn = elt(env, 13); /* subs2 */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-13];
    v70 = v69;
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    v69 = v70;
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v69 = Lrplacd(nil, stack[-1], v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-13];
    v69 = stack[-2];
    v69 = qcdr(v69);
    stack[-2] = v69;
    goto v92;
/* error exit handlers */
v94:
    env = stack[-13];
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    popv(14);
    return nil;
v91:
    env = stack[-13];
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    popv(14);
    return nil;
v90:
    env = stack[-13];
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    popv(14);
    return nil;
v87:
    env = stack[-13];
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    popv(14);
    return nil;
v72:
    popv(14);
    return nil;
}



/* Code for mri_congp */

static Lisp_Object CC_mri_congp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_congp");
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
    v97 = v0;
/* end of prologue */
    fn = elt(env, 2); /* mri_opn */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[0];
    v73 = elt(env, 1); /* (cong ncong) */
    v97 = Lmemq(nil, v97, v73);
    { popv(1); return onevalue(v97); }
/* error exit handlers */
v98:
    popv(1);
    return nil;
}



/* Code for prsubsetrd */

static Lisp_Object CC_prsubsetrd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prsubsetrd");
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
    stack[-3] = nil;
    v108 = qvalue(elt(env, 1)); /* t */
    stack[-1] = v108;
    goto v110;

v110:
    v108 = stack[-3];
    v109 = Llength(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    v108 = (Lisp_Object)17; /* 1 */
    v108 = (Lisp_Object)greaterp2(v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v111;
    v108 = v108 ? lisp_true : nil;
    env = stack[-4];
    if (v108 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v108 = stack[-3];
    stack[0] = qcar(v108);
    v108 = stack[-3];
    v108 = qcar(v108);
    fn = elt(env, 4); /* reval */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    if (equal(stack[0], v108)) goto v112;
    v108 = stack[-3];
    v108 = qcdr(v108);
    stack[0] = qcar(v108);
    v108 = stack[-3];
    v108 = qcdr(v108);
    v108 = qcar(v108);
    fn = elt(env, 4); /* reval */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    v108 = (equal(stack[0], v108) ? lisp_true : nil);
    goto v113;

v113:
    if (v108 == nil) goto v114;
    v108 = nil;
    stack[-3] = v108;
    stack[0] = elt(env, 3); /* prsubset */
    v108 = stack[-2];
    fn = elt(env, 5); /* eval_list_sets */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    v108 = cons(stack[0], v108);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    stack[-1] = v108;
    goto v110;

v114:
    v108 = stack[-1];
    if (v108 == nil) goto v115;
    v108 = stack[-3];
    v108 = qcar(v108);
    fn = elt(env, 4); /* reval */
    stack[0] = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    v108 = stack[-3];
    v108 = qcdr(v108);
    v108 = qcar(v108);
    fn = elt(env, 4); /* reval */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    fn = elt(env, 6); /* alg_prsubset */
    v108 = (*qfn2(fn))(qenv(fn), stack[0], v108);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-4];
    goto v116;

v116:
    stack[-1] = v108;
    v108 = stack[-3];
    v108 = qcdr(v108);
    stack[-3] = v108;
    goto v110;

v115:
    v108 = qvalue(elt(env, 2)); /* nil */
    goto v116;

v112:
    v108 = qvalue(elt(env, 1)); /* t */
    goto v113;
/* error exit handlers */
v111:
    popv(5);
    return nil;
}



/* Code for ps!:set!-term */

static Lisp_Object MS_CDECL CC_psTsetKterm(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v100, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v156, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ps:set-term");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:set-term");
#endif
    if (stack >= stacklimit)
    {
        push3(v100,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v100);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v100;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v155 = stack[-4];
    fn = elt(env, 9); /* ps!:order */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    stack[-5] = v155;
    v156 = stack[-3];
    v155 = stack[-5];
    v155 = (Lisp_Object)lessp2(v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v155 = v155 ? lisp_true : nil;
    env = stack[-6];
    if (v155 == nil) goto v158;
    v157 = stack[-3];
    v156 = elt(env, 1); /* "less than the order of " */
    v155 = stack[-4];
    v155 = list3(v157, v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    v156 = v155;
    v155 = v156;
    qvalue(elt(env, 2)) = v155; /* errmsg!* */
    v155 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v155 == nil)) goto v105;
    v155 = v156;
    fn = elt(env, 10); /* lprie */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    goto v105;

v105:
    v155 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    goto v97;

v97:
    v155 = stack[-4];
    if (!consp(v155)) goto v159;
    v155 = stack[-4];
    v156 = qcar(v155);
    v155 = elt(env, 6); /* !:ps!: */
    if (v156 == v155) goto v160;
    v155 = stack[-4];
    v156 = qcar(v155);
    v155 = elt(env, 7); /* dname */
    v155 = get(v156, v155);
    env = stack[-6];
    goto v80;

v80:
    if (v155 == nil) goto v161;
    v157 = (Lisp_Object)1; /* 0 */
    v156 = stack[-4];
    v155 = (Lisp_Object)17; /* 1 */
    v155 = list2star(v157, v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    v155 = ncons(v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    goto v162;

v162:
    stack[0] = v155;
    v155 = stack[-2];
    if (!consp(v155)) goto v163;
    v155 = stack[-2];
    v156 = qcar(v155);
    v155 = qvalue(elt(env, 8)); /* nil */
    v155 = Lneq(nil, v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    goto v82;

v82:
    if (v155 == nil) goto v164;
    v155 = stack[0];
    if (v155 == nil) goto v165;
    v156 = stack[-3];
    v155 = stack[-5];
    v156 = difference2(v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    v155 = stack[-2];
    v155 = cons(v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    v155 = ncons(v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    v155 = Lnconc(nil, stack[0], v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    goto v166;

v166:
    v157 = stack[-4];
    v156 = (Lisp_Object)17; /* 1 */
    v155 = stack[-3];
    fn = elt(env, 11); /* ps!:putv */
    v155 = (*qfnn(fn))(qenv(fn), 3, v157, v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v155 = nil;
    { popv(7); return onevalue(v155); }

v165:
    stack[-1] = stack[-4];
    stack[0] = (Lisp_Object)81; /* 5 */
    v156 = stack[-3];
    v155 = stack[-5];
    v156 = difference2(v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    v155 = stack[-2];
    v155 = cons(v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    v155 = ncons(v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    fn = elt(env, 11); /* ps!:putv */
    v155 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    goto v166;

v164:
    v156 = stack[-3];
    v155 = stack[-5];
    if (!(equal(v156, v155))) goto v166;
    stack[-1] = stack[-4];
    stack[0] = (Lisp_Object)1; /* 0 */
    v155 = stack[-3];
    v155 = add1(v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    fn = elt(env, 11); /* ps!:putv */
    v155 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    goto v166;

v163:
    v155 = qvalue(elt(env, 5)); /* t */
    goto v82;

v161:
    v156 = stack[-4];
    v155 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 12); /* ps!:getv */
    v155 = (*qfn2(fn))(qenv(fn), v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    goto v162;

v160:
    v155 = qvalue(elt(env, 8)); /* nil */
    goto v80;

v159:
    v155 = qvalue(elt(env, 5)); /* t */
    goto v80;

v158:
    stack[0] = stack[-3];
    v155 = stack[-4];
    fn = elt(env, 13); /* ps!:last!-term */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    v155 = (Lisp_Object)lesseq2(stack[0], v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v155 = v155 ? lisp_true : nil;
    env = stack[-6];
    if (v155 == nil) goto v97;
    v157 = stack[-3];
    v156 = elt(env, 4); /* "less than power of last term of " */
    v155 = stack[-4];
    v155 = list3(v157, v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    v156 = v155;
    v155 = v156;
    qvalue(elt(env, 2)) = v155; /* errmsg!* */
    v155 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v155 == nil)) goto v115;
    v155 = v156;
    fn = elt(env, 10); /* lprie */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    goto v115;

v115:
    v155 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-6];
    goto v97;
/* error exit handlers */
v86:
    popv(7);
    return nil;
}



/* Code for simpu */

static Lisp_Object CC_simpu(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169, v170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpu");
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
    v170 = v0;
/* end of prologue */
    stack[-1] = elt(env, 1); /* u */
    v169 = v170;
    stack[0] = qcar(v169);
    v169 = v170;
    v169 = qcdr(v169);
    fn = elt(env, 2); /* ordn */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-2];
    v169 = Lreverse(nil, v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-2];
    v169 = list2star(stack[-1], stack[0], v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-2];
    fn = elt(env, 3); /* fkern */
    v170 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-2];
    v169 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 4); /* getpower */
    v170 = (*qfn2(fn))(qenv(fn), v170, v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-2];
    v169 = (Lisp_Object)17; /* 1 */
    v169 = cons(v170, v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-2];
    v170 = ncons(v169);
    nil = C_nil;
    if (exception_pending()) goto v171;
    v169 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v170, v169);
/* error exit handlers */
v171:
    popv(3);
    return nil;
}



/* Code for subs2pf */

static Lisp_Object CC_subs2pf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v106, v169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2pf");
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

v172:
    v105 = stack[0];
    if (v105 == nil) goto v136;
    v105 = stack[0];
    v105 = qcar(v105);
    v105 = qcdr(v105);
    fn = elt(env, 1); /* resimp */
    v105 = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-1];
    fn = elt(env, 2); /* subs2 */
    v105 = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-1];
    v106 = v105;
    v106 = qcar(v106);
    if (v106 == nil) goto v151;
    v106 = stack[0];
    v106 = qcar(v106);
    v169 = qcar(v106);
    v106 = v105;
    v105 = stack[0];
    v105 = qcdr(v105);
    popv(2);
    return acons(v169, v106, v105);

v151:
    v105 = stack[0];
    v105 = qcdr(v105);
    stack[0] = v105;
    goto v172;

v136:
    v105 = nil;
    { popv(2); return onevalue(v105); }
/* error exit handlers */
v173:
    popv(2);
    return nil;
}



/* Code for divide!-by!-power!-of!-ten */

static Lisp_Object CC_divideKbyKpowerKofKten(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v180, v181;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for divide-by-power-of-ten");
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
    v180 = stack[-2];
    v92 = (Lisp_Object)1; /* 0 */
    v92 = (Lisp_Object)lessp2(v180, v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    v92 = v92 ? lisp_true : nil;
    env = stack[-5];
    if (v92 == nil) goto v112;
    stack[0] = (Lisp_Object)1; /* 0 */
    v180 = elt(env, 1); /* "Invalid argument to" */
    v92 = elt(env, 0); /* divide!-by!-power!-of!-ten */
    v92 = list2(v180, v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    {
        Lisp_Object v182 = stack[0];
        popv(6);
        fn = elt(env, 6); /* error */
        return (*qfn2(fn))(qenv(fn), v182, v92);
    }

v112:
    v92 = qvalue(elt(env, 2)); /* bften!* */
    stack[-4] = v92;
    goto v173;

v173:
    v180 = stack[-2];
    v92 = (Lisp_Object)1; /* 0 */
    v92 = (Lisp_Object)greaterp2(v180, v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    v92 = v92 ? lisp_true : nil;
    env = stack[-5];
    if (v92 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v92 = stack[-2];
    v92 = Levenp(nil, v92);
    env = stack[-5];
    if (!(v92 == nil)) goto v183;
    v181 = stack[-3];
    v180 = stack[-4];
    v92 = qvalue(elt(env, 4)); /* !:bprec!: */
    fn = elt(env, 7); /* divide!: */
    v92 = (*qfnn(fn))(qenv(fn), 3, v181, v180, v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    fn = elt(env, 8); /* csl_normbf */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    stack[-3] = v92;
    goto v183;

v183:
    v180 = stack[-2];
    v92 = (Lisp_Object)-15; /* -1 */
    v92 = ash(v180, v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    stack[-2] = v92;
    stack[-1] = elt(env, 5); /* !:rd!: */
    v92 = stack[-4];
    v92 = qcdr(v92);
    v180 = qcar(v92);
    v92 = stack[-4];
    v92 = qcdr(v92);
    v92 = qcar(v92);
    stack[0] = times2(v180, v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    v92 = stack[-4];
    v92 = qcdr(v92);
    v180 = qcdr(v92);
    v92 = stack[-4];
    v92 = qcdr(v92);
    v92 = qcdr(v92);
    v92 = plus2(v180, v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    v180 = list2star(stack[-1], stack[0], v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    v92 = qvalue(elt(env, 4)); /* !:bprec!: */
    fn = elt(env, 9); /* cut!:mt */
    v92 = (*qfn2(fn))(qenv(fn), v180, v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    fn = elt(env, 8); /* csl_normbf */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    stack[-4] = v92;
    goto v173;
/* error exit handlers */
v142:
    popv(6);
    return nil;
}



/* Code for subfindices */

static Lisp_Object CC_subfindices(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204, v166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subfindices");
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
    stack[-3] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v204 = qvalue(elt(env, 2)); /* nil */
    v204 = ncons(v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    qvalue(elt(env, 1)) = v204; /* alglist!* */
    v204 = stack[-2];
    if (!consp(v204)) goto v179;
    v204 = stack[-2];
    v204 = qcar(v204);
    v204 = (consp(v204) ? nil : lisp_true);
    goto v98;

v98:
    if (v204 == nil) goto v169;
    v166 = stack[-2];
    v204 = (Lisp_Object)17; /* 1 */
    v204 = cons(v166, v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    goto v136;

v136:
    qvalue(elt(env, 1)) = stack[-3]; /* alglist!* */
    { popv(5); return onevalue(v204); }

v169:
    v204 = stack[-2];
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcar(v204);
    if (!consp(v204)) goto v205;
    v204 = stack[-2];
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcar(v204);
    if (!consp(v204)) goto v206;
    v204 = stack[-2];
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = (consp(v204) ? nil : lisp_true);
    v204 = (v204 == nil ? lisp_true : nil);
    goto v176;

v176:
    if (v204 == nil) goto v49;
    v204 = stack[-2];
    v204 = qcar(v204);
    v204 = qcar(v204);
    v166 = qcar(v204);
    v204 = stack[-1];
    v166 = CC_subfindices(env, v166, v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    v204 = stack[-2];
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcdr(v204);
    fn = elt(env, 6); /* exptsq */
    v204 = (*qfn2(fn))(qenv(fn), v166, v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    stack[0] = v204;
    goto v44;

v44:
    v204 = stack[-2];
    v204 = qcar(v204);
    v166 = qcdr(v204);
    v204 = stack[-1];
    v204 = CC_subfindices(env, v166, v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    fn = elt(env, 7); /* multsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    v204 = stack[-2];
    v166 = qcdr(v204);
    v204 = stack[-1];
    v204 = CC_subfindices(env, v166, v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    fn = elt(env, 8); /* addsq */
    v204 = (*qfn2(fn))(qenv(fn), stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    goto v136;

v49:
    v204 = stack[-2];
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcar(v204);
    v166 = qcar(v204);
    v204 = elt(env, 4); /* indexvar */
    v204 = Lflagp(nil, v166, v204);
    env = stack[-4];
    if (v204 == nil) goto v56;
    v204 = stack[-2];
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcar(v204);
    stack[0] = qcar(v204);
    v166 = stack[-1];
    v204 = stack[-2];
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcdr(v204);
    v204 = Lsubla(nil, v166, v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    v204 = cons(stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    fn = elt(env, 9); /* simpindexvar */
    v166 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    v204 = stack[-2];
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcdr(v204);
    fn = elt(env, 6); /* exptsq */
    v204 = (*qfn2(fn))(qenv(fn), v166, v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    stack[0] = v204;
    goto v44;

v56:
    v204 = stack[-2];
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcar(v204);
    v166 = qcar(v204);
    v204 = elt(env, 5); /* (wedge d partdf innerprod liedf hodge vardf) 
*/
    v204 = Lmemq(nil, v166, v204);
    if (v204 == nil) goto v48;
    v166 = stack[-1];
    v204 = stack[-2];
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcar(v204);
    fn = elt(env, 10); /* subindk */
    v204 = (*qfn2(fn))(qenv(fn), v166, v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    fn = elt(env, 11); /* simp */
    v166 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    v204 = stack[-2];
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcdr(v204);
    fn = elt(env, 6); /* exptsq */
    v204 = (*qfn2(fn))(qenv(fn), v166, v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    stack[0] = v204;
    goto v44;

v48:
    v204 = stack[-2];
    v204 = qcar(v204);
    v166 = qcar(v204);
    v204 = (Lisp_Object)17; /* 1 */
    v204 = cons(v166, v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    v166 = ncons(v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    v204 = (Lisp_Object)17; /* 1 */
    v204 = cons(v166, v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    stack[0] = v204;
    goto v44;

v206:
    v204 = qvalue(elt(env, 2)); /* nil */
    goto v176;

v205:
    v204 = stack[-2];
    v204 = qcar(v204);
    v166 = qcar(v204);
    v204 = (Lisp_Object)17; /* 1 */
    v204 = cons(v166, v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    v166 = ncons(v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    v204 = (Lisp_Object)17; /* 1 */
    v204 = cons(v166, v204);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    stack[0] = v204;
    goto v44;

v179:
    v204 = qvalue(elt(env, 3)); /* t */
    goto v98;
/* error exit handlers */
v34:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* alglist!* */
    popv(5);
    return nil;
}



/* Code for dfdeg */

static Lisp_Object CC_dfdeg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v106;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfdeg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v106 = v1;
    v105 = v0;
/* end of prologue */
    v106 = Lmember(nil, v106, v105);
    v105 = v106;
    if (v106 == nil) goto v136;
    v106 = v105;
    v106 = qcdr(v106);
    if (v106 == nil) goto v74;
    v106 = v105;
    v106 = qcdr(v106);
    v106 = qcar(v106);
    v106 = integerp(v106);
    v106 = (v106 == nil ? lisp_true : nil);
    goto v208;

v208:
    if (v106 == nil) goto v151;
    v105 = (Lisp_Object)17; /* 1 */
    return onevalue(v105);

v151:
    v105 = qcdr(v105);
    v105 = qcar(v105);
    return onevalue(v105);

v74:
    v106 = qvalue(elt(env, 1)); /* t */
    goto v208;

v136:
    v105 = (Lisp_Object)1; /* 0 */
    return onevalue(v105);
}



/* Code for find_triangles1 */

static Lisp_Object CC_find_triangles1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v112, v152, v153, v151, v212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_triangles1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v113 = v1;
    v112 = v0;
/* end of prologue */
    v212 = qvalue(elt(env, 1)); /* nil */
    v152 = v112;
    v151 = qcar(v152);
    v153 = qvalue(elt(env, 1)); /* nil */
    v152 = v112;
    v152 = qcdr(v152);
    v152 = qcar(v152);
    v112 = qcdr(v112);
    v112 = qcdr(v112);
    v112 = qcar(v112);
    {
        fn = elt(env, 2); /* select_triangles */
        return (*qfnn(fn))(qenv(fn), 6, v212, v151, v153, v152, v112, v113);
    }
}



/* Code for fs!:zerop!: */

static Lisp_Object CC_fsTzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v101, v102;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:zerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v102 = v0;
/* end of prologue */
    v149 = v102;
    if (v149 == nil) goto v36;
    v149 = v102;
    if (is_number(v149)) goto v107;
    v149 = v102;
    v149 = qcdr(v149);
    v149 = (v149 == nil ? lisp_true : nil);
    goto v110;

v110:
    if (v149 == nil) goto v153;
    v149 = qvalue(elt(env, 1)); /* t */
    return onevalue(v149);

v153:
    v149 = v102;
    v101 = qcdr(v149);
    v149 = (Lisp_Object)49; /* 3 */
    v149 = *(Lisp_Object *)((char *)v101 + (CELL-TAG_VECTOR) + ((int32_t)v149/(16/CELL)));
    if (v149 == nil) goto v170;
    v149 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v149);

v170:
    v149 = v102;
    v101 = qcdr(v149);
    v149 = (Lisp_Object)1; /* 0 */
    v149 = *(Lisp_Object *)((char *)v101 + (CELL-TAG_VECTOR) + ((int32_t)v149/(16/CELL)));
    v101 = v149;
    v149 = v101;
    if (is_number(v149)) goto v67;
    v149 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v149);

v67:
    v149 = v101;
        return Lzerop(nil, v149);

v107:
    v149 = qvalue(elt(env, 2)); /* nil */
    goto v110;

v36:
    v149 = qvalue(elt(env, 1)); /* t */
    return onevalue(v149);
}



/* Code for !*g2lex */

static Lisp_Object CC_Hg2lex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *g2lex");
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
    v170 = v0;
/* end of prologue */
    v173 = nil;
    stack[-1] = v170;
    goto v167;

v167:
    v170 = stack[-1];
    if (v170 == nil) { popv(3); return onevalue(v173); }
    v170 = stack[-1];
    v170 = qcar(v170);
    stack[0] = v173;
    v173 = v170;
    v173 = qcar(v173);
    v173 = qcdr(v173);
    v170 = qcdr(v170);
    v170 = cons(v173, v170);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-2];
    v170 = ncons(v170);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-2];
    fn = elt(env, 2); /* psum */
    v170 = (*qfn2(fn))(qenv(fn), stack[0], v170);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-2];
    v173 = v170;
    v170 = stack[-1];
    v170 = qcdr(v170);
    stack[-1] = v170;
    goto v167;
/* error exit handlers */
v186:
    popv(3);
    return nil;
}



/* Code for r2flbf */

static Lisp_Object CC_r2flbf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2flbf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v179 = v0;
/* end of prologue */
    v98 = qvalue(elt(env, 1)); /* !*bftag */
    if (v98 == nil) goto v95;
    v98 = v179;
    {
        fn = elt(env, 2); /* r2bf */
        return (*qfn1(fn))(qenv(fn), v98);
    }

v95:
    v98 = v179;
    {
        fn = elt(env, 3); /* r2fl */
        return (*qfn1(fn))(qenv(fn), v98);
    }
}



/* Code for bfprin0x */

static Lisp_Object CC_bfprin0x(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v168, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfprin0x");
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
/* copy arguments values to proper place */
    v168 = v1;
    v76 = v0;
/* end of prologue */
    fn = elt(env, 1); /* bfexplode0x */
    v76 = (*qfn2(fn))(qenv(fn), v76, v168);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[0];
    v168 = v76;
    v168 = qcdr(v168);
    v168 = qcar(v168);
    v105 = v76;
    v105 = qcdr(v105);
    v105 = qcdr(v105);
    v105 = qcar(v105);
    v76 = qcar(v76);
    {
        popv(1);
        fn = elt(env, 2); /* bfprin!:lst */
        return (*qfnn(fn))(qenv(fn), 3, v76, v168, v105);
    }
/* error exit handlers */
v106:
    popv(1);
    return nil;
}



/* Code for nextu */

static Lisp_Object CC_nextu(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v218, v66, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nextu");
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
    v66 = v1;
    stack[0] = v0;
/* end of prologue */
    v218 = stack[0];
    if (v218 == nil) goto v136;
    v65 = v66;
    v218 = stack[0];
    v66 = qcar(v218);
    v218 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* subtractinds */
    v218 = (*qfnn(fn))(qenv(fn), 3, v65, v66, v218);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-2];
    stack[-1] = v218;
    v218 = stack[-1];
    if (v218 == nil) goto v113;
    v218 = stack[0];
    v218 = qcdr(v218);
    v66 = qcar(v218);
    v218 = stack[-1];
    fn = elt(env, 4); /* evaluatecoeffts */
    v218 = (*qfn2(fn))(qenv(fn), v66, v218);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-2];
    v65 = v218;
    v218 = v65;
    if (v218 == nil) goto v220;
    v66 = v65;
    v218 = (Lisp_Object)1; /* 0 */
    v218 = (v66 == v218 ? lisp_true : nil);
    goto v158;

v158:
    if (v218 == nil) goto v101;
    v218 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v218); }

v101:
    v66 = stack[-1];
    v218 = stack[0];
    v218 = qcdr(v218);
    v218 = qcdr(v218);
    popv(3);
    return list2star(v66, v65, v218);

v220:
    v218 = qvalue(elt(env, 2)); /* t */
    goto v158;

v113:
    v218 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v218); }

v136:
    v218 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v218); }
/* error exit handlers */
v219:
    popv(3);
    return nil;
}



/* Code for repr_a */

static Lisp_Object CC_repr_a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repr_a");
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
    v74 = stack[0];
    v74 = qcdr(v74);
    v74 = qcdr(v74);
    v74 = qcar(v74);
    v74 = Lreverse(nil, v74);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-1];
    v74 = qcar(v74);
    v154 = qcar(v74);
    v74 = stack[0];
    v74 = qcdr(v74);
    v74 = qcdr(v74);
    v74 = qcdr(v74);
    v74 = qcar(v74);
    {
        popv(2);
        fn = elt(env, 1); /* addf */
        return (*qfn2(fn))(qenv(fn), v154, v74);
    }
/* error exit handlers */
v210:
    popv(2);
    return nil;
}



/* Code for cols2rows2 */

static Lisp_Object CC_cols2rows2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cols2rows2");
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
    v169 = stack[0];
    v106 = (Lisp_Object)1; /* 0 */
    if (v169 == v106) goto v221;
    v169 = stack[-1];
    v106 = stack[0];
    fn = elt(env, 1); /* ithlistelem */
    stack[-2] = (*qfn2(fn))(qenv(fn), v169, v106);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    v106 = stack[0];
    v106 = sub1(v106);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-3];
    v106 = CC_cols2rows2(env, stack[-1], v106);
    nil = C_nil;
    if (exception_pending()) goto v171;
    {
        Lisp_Object v186 = stack[-2];
        popv(4);
        return cons(v186, v106);
    }

v221:
    v106 = nil;
    { popv(4); return onevalue(v106); }
/* error exit handlers */
v171:
    popv(4);
    return nil;
}



/* Code for i2ps */

static Lisp_Object CC_i2ps(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v21;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for i2ps");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v21 = v0;
/* end of prologue */
    return onevalue(v21);
}



/* Code for groebcplistmerge */

static Lisp_Object CC_groebcplistmerge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebcplistmerge");
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
    v116 = stack[-2];
    if (v116 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v116 = stack[-1];
    if (v116 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v116 = stack[-2];
    v116 = qcar(v116);
    stack[-3] = v116;
    v116 = stack[-1];
    v116 = qcar(v116);
    stack[0] = v116;
    v115 = stack[-3];
    v116 = stack[0];
    fn = elt(env, 1); /* groebcpcompless!? */
    v116 = (*qfn2(fn))(qenv(fn), v115, v116);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    if (v116 == nil) goto v224;
    stack[0] = stack[-3];
    v116 = stack[-2];
    v115 = qcdr(v116);
    v116 = stack[-1];
    v116 = CC_groebcplistmerge(env, v115, v116);
    nil = C_nil;
    if (exception_pending()) goto v218;
    {
        Lisp_Object v66 = stack[0];
        popv(5);
        return cons(v66, v116);
    }

v224:
    v115 = stack[-2];
    v116 = stack[-1];
    v116 = qcdr(v116);
    v116 = CC_groebcplistmerge(env, v115, v116);
    nil = C_nil;
    if (exception_pending()) goto v218;
    {
        Lisp_Object v65 = stack[0];
        popv(5);
        return cons(v65, v116);
    }
/* error exit handlers */
v218:
    popv(5);
    return nil;
}



/* Code for multsqpf */

static Lisp_Object CC_multsqpf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v226, v223;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multsqpf");
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
    goto v221;

v221:
    v226 = stack[-1];
    if (v226 == nil) goto v98;
    v226 = stack[-2];
    v226 = qcar(v226);
    v226 = (v226 == nil ? lisp_true : nil);
    goto v73;

v73:
    if (v226 == nil) goto v211;
    v226 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v226);
    }

v211:
    v226 = stack[-1];
    v226 = qcar(v226);
    stack[0] = qcar(v226);
    v223 = stack[-2];
    v226 = stack[-1];
    v226 = qcar(v226);
    v226 = qcdr(v226);
    fn = elt(env, 3); /* multsq */
    v223 = (*qfn2(fn))(qenv(fn), v223, v226);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    v226 = stack[-3];
    v226 = acons(stack[0], v223, v226);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    stack[-3] = v226;
    v226 = stack[-1];
    v226 = qcdr(v226);
    stack[-1] = v226;
    goto v221;

v98:
    v226 = qvalue(elt(env, 1)); /* t */
    goto v73;
/* error exit handlers */
v68:
    popv(5);
    return nil;
}



/* Code for !*kp2q */

static Lisp_Object CC_Hkp2q(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *kp2q");
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
    v79 = stack[0];
    v183 = (Lisp_Object)1; /* 0 */
    v183 = (Lisp_Object)greaterp2(v79, v183);
    nil = C_nil;
    if (exception_pending()) goto v77;
    v183 = v183 ? lisp_true : nil;
    env = stack[-2];
    if (v183 == nil) goto v221;
    v79 = stack[-1];
    v183 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* mksq */
        return (*qfn2(fn))(qenv(fn), v79, v183);
    }

v221:
    v183 = stack[0];
    v183 = (Lisp_Object)zerop(v183);
    v183 = v183 ? lisp_true : nil;
    env = stack[-2];
    if (v183 == nil) goto v169;
    v79 = (Lisp_Object)17; /* 1 */
    v183 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v79, v183);

v169:
    v183 = stack[0];
    v183 = negate(v183);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-2];
    fn = elt(env, 3); /* mksq */
    v183 = (*qfn2(fn))(qenv(fn), stack[-1], v183);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-2];
    stack[-1] = v183;
    v183 = qcar(v183);
    if (v183 == nil) goto v215;
    v183 = stack[-1];
    v79 = qcdr(v183);
    v183 = stack[-1];
    v183 = qcar(v183);
    popv(3);
    return cons(v79, v183);

v215:
    v183 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v183 == nil)) goto v226;
    v183 = elt(env, 2); /* "Zero divisor" */
    fn = elt(env, 4); /* lprie */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-2];
    goto v226;

v226:
    v183 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v77;
    v183 = nil;
    { popv(3); return onevalue(v183); }
/* error exit handlers */
v77:
    popv(3);
    return nil;
}



/* Code for gcdld */

static Lisp_Object CC_gcdld(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v203, v217, v205, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdld");
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
    v217 = v1;
    v205 = v0;
/* end of prologue */

v110:
    v78 = v217;
    v203 = (Lisp_Object)17; /* 1 */
    if (v78 == v203) goto v98;
    v78 = v217;
    v203 = (Lisp_Object)-15; /* -1 */
    v203 = (v78 == v203 ? lisp_true : nil);
    goto v73;

v73:
    if (v203 == nil) goto v228;
    v203 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v203); }

v228:
    v203 = v205;
    if (v203 == nil) goto v212;
    v203 = v205;
    v203 = qcar(v203);
    if (v203 == nil) goto v106;
    v203 = v205;
    v203 = qcdr(v203);
    stack[0] = v203;
    v203 = v217;
    v217 = v205;
    v217 = qcar(v217);
    fn = elt(env, 2); /* gcd!-with!-number */
    v203 = (*qfn2(fn))(qenv(fn), v203, v217);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-1];
    v217 = v203;
    v203 = stack[0];
    v205 = v203;
    goto v110;

v106:
    v203 = v205;
    v203 = qcdr(v203);
    v205 = v203;
    goto v110;

v212:
    v203 = v217;
        popv(2);
        return Labsval(nil, v203);

v98:
    v203 = qvalue(elt(env, 1)); /* t */
    goto v73;
/* error exit handlers */
v149:
    popv(2);
    return nil;
}



/* Code for dfp!-rule!-found */

static Lisp_Object CC_dfpKruleKfound(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v113, v112, v152;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfp-rule-found");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v112 = v1;
    v152 = v0;
/* end of prologue */
    v113 = v152;
    v75 = elt(env, 1); /* dfp */
    if (!consp(v113)) goto v136;
    v113 = qcar(v113);
    if (!(v113 == v75)) goto v136;
    v75 = v152;
    v75 = qcdr(v75);
    v75 = qcar(v75);
    v113 = v112;
        return Lneq(nil, v75, v113);

v136:
    v75 = qvalue(elt(env, 2)); /* t */
    return onevalue(v75);
}



/* Code for fs!:minusp */

static Lisp_Object CC_fsTminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v173, v222;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:minusp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v173 = v0;
/* end of prologue */

v36:
    v170 = v173;
    if (v170 == nil) goto v96;
    v222 = v173;
    v170 = (Lisp_Object)49; /* 3 */
    v170 = *(Lisp_Object *)((char *)v222 + (CELL-TAG_VECTOR) + ((int32_t)v170/(16/CELL)));
    if (v170 == nil) goto v229;
    v170 = (Lisp_Object)49; /* 3 */
    v170 = *(Lisp_Object *)((char *)v173 + (CELL-TAG_VECTOR) + ((int32_t)v170/(16/CELL)));
    v173 = v170;
    goto v36;

v229:
    v170 = (Lisp_Object)1; /* 0 */
    v170 = *(Lisp_Object *)((char *)v173 + (CELL-TAG_VECTOR) + ((int32_t)v170/(16/CELL)));
    v170 = qcar(v170);
    {
        fn = elt(env, 2); /* minusf */
        return (*qfn1(fn))(qenv(fn), v170);
    }

v96:
    v170 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v170);
}



/* Code for mo_zero!? */

static Lisp_Object CC_mo_zeroW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_zero?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v136 = v0;
/* end of prologue */
    v136 = qcar(v136);
    {
        fn = elt(env, 1); /* mo!=zero */
        return (*qfn1(fn))(qenv(fn), v136);
    }
}



/* Code for quotfail!-in!-vector */

static Lisp_Object MS_CDECL CC_quotfailKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v100, Lisp_Object v21, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v247, v248, v22, v85, v249, v250, v251, v252;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "quotfail-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfail-in-vector");
#endif
    if (stack >= stacklimit)
    {
        push4(v21,v100,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v100,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v21;
    stack[-2] = v100;
    v22 = v1;
    stack[-3] = v0;
/* end of prologue */
    v248 = v22;
    v247 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v248)) < ((int32_t)(v247))) { popv(6); return onevalue(v22); }
    v248 = stack[-1];
    v247 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v248)) < ((int32_t)(v247))) goto v209;
    v248 = v22;
    v247 = stack[-1];
    if (((int32_t)(v248)) < ((int32_t)(v247))) goto v75;
    v248 = v22;
    v247 = stack[-1];
    v247 = (Lisp_Object)(int32_t)((int32_t)v248 - (int32_t)v247 + TAG_FIXNUM);
    stack[-4] = v247;
    v247 = stack[-4];
    stack[0] = v247;
    goto v227;

v227:
    v247 = stack[0];
    v247 = ((intptr_t)(v247) < 0 ? lisp_true : nil);
    if (v247 == nil) goto v77;
    v247 = (Lisp_Object)1; /* 0 */
    stack[0] = v247;
    goto v40;

v40:
    v247 = stack[-1];
    v248 = (Lisp_Object)((int32_t)(v247) - 0x10);
    v247 = stack[0];
    v247 = (Lisp_Object)(int32_t)((int32_t)v248 - (int32_t)v247 + TAG_FIXNUM);
    v247 = ((intptr_t)(v247) < 0 ? lisp_true : nil);
    if (v247 == nil) goto v42;
    v247 = (Lisp_Object)1; /* 0 */
    v250 = v247;
    goto v33;

v33:
    v248 = stack[-4];
    v247 = v250;
    v247 = (Lisp_Object)(int32_t)((int32_t)v248 - (int32_t)v247 + TAG_FIXNUM);
    v247 = ((intptr_t)(v247) < 0 ? lisp_true : nil);
    if (!(v247 == nil)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v249 = stack[-3];
    v85 = v250;
    v22 = stack[-3];
    v248 = stack[-1];
    v247 = v250;
    v247 = (Lisp_Object)(int32_t)((int32_t)v248 + (int32_t)v247 - TAG_FIXNUM);
    v247 = *(Lisp_Object *)((char *)v22 + (CELL-TAG_VECTOR) + ((int32_t)v247/(16/CELL)));
    *(Lisp_Object *)((char *)v249 + (CELL-TAG_VECTOR) + ((int32_t)v85/(16/CELL))) = v247;
    v247 = v250;
    v247 = (Lisp_Object)((int32_t)(v247) + 0x10);
    v250 = v247;
    goto v33;

v42:
    v248 = stack[-3];
    v247 = stack[0];
    v248 = *(Lisp_Object *)((char *)v248 + (CELL-TAG_VECTOR) + ((int32_t)v247/(16/CELL)));
    v247 = (Lisp_Object)1; /* 0 */
    if (v248 == v247) goto v253;
    v247 = elt(env, 4); /* "Quotient not exact in QUOTFAIL!-IN!-VECTOR" 
*/
    fn = elt(env, 5); /* errorf */
    v247 = (*qfn1(fn))(qenv(fn), v247);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-5];
    goto v253;

v253:
    v247 = stack[0];
    v247 = (Lisp_Object)((int32_t)(v247) + 0x10);
    stack[0] = v247;
    goto v40;

v77:
    v22 = stack[-3];
    v248 = stack[-1];
    v247 = stack[0];
    v247 = (Lisp_Object)(int32_t)((int32_t)v248 + (int32_t)v247 - TAG_FIXNUM);
    v22 = *(Lisp_Object *)((char *)v22 + (CELL-TAG_VECTOR) + ((int32_t)v247/(16/CELL)));
    v248 = stack[-2];
    v247 = stack[-1];
    v247 = *(Lisp_Object *)((char *)v248 + (CELL-TAG_VECTOR) + ((int32_t)v247/(16/CELL)));
    v247 = Lmodular_quotient(nil, v22, v247);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-5];
    v252 = v247;
    v247 = (Lisp_Object)1; /* 0 */
    v251 = v247;
    goto v254;

v254:
    v247 = stack[-1];
    v248 = (Lisp_Object)((int32_t)(v247) - 0x10);
    v247 = v251;
    v247 = (Lisp_Object)(int32_t)((int32_t)v248 - (int32_t)v247 + TAG_FIXNUM);
    v247 = ((intptr_t)(v247) < 0 ? lisp_true : nil);
    if (v247 == nil) goto v37;
    v22 = stack[-3];
    v248 = stack[-1];
    v247 = stack[0];
    v247 = (Lisp_Object)(int32_t)((int32_t)v248 + (int32_t)v247 - TAG_FIXNUM);
    v248 = v252;
    *(Lisp_Object *)((char *)v22 + (CELL-TAG_VECTOR) + ((int32_t)v247/(16/CELL))) = v248;
    v247 = stack[0];
    v247 = (Lisp_Object)((int32_t)(v247) - 0x10);
    stack[0] = v247;
    goto v227;

v37:
    v250 = stack[-3];
    v248 = stack[0];
    v247 = v251;
    v249 = (Lisp_Object)(int32_t)((int32_t)v248 + (int32_t)v247 - TAG_FIXNUM);
    v22 = stack[-3];
    v248 = stack[0];
    v247 = v251;
    v247 = (Lisp_Object)(int32_t)((int32_t)v248 + (int32_t)v247 - TAG_FIXNUM);
    v85 = *(Lisp_Object *)((char *)v22 + (CELL-TAG_VECTOR) + ((int32_t)v247/(16/CELL)));
    v22 = v252;
    v248 = stack[-2];
    v247 = v251;
    v247 = *(Lisp_Object *)((char *)v248 + (CELL-TAG_VECTOR) + ((int32_t)v247/(16/CELL)));
    v247 = Lmodular_times(nil, v22, v247);
    env = stack[-5];
    {   int32_t w = int_of_fixnum(v85) - int_of_fixnum(v247);
        if (w < 0) w += current_modulus;
        v247 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v250 + (CELL-TAG_VECTOR) + ((int32_t)v249/(16/CELL))) = v247;
    v247 = v251;
    v247 = (Lisp_Object)((int32_t)(v247) + 0x10);
    v251 = v247;
    goto v254;

v75:
    v247 = elt(env, 2); /* "Bad degrees in QUOTFAIL-IN-VECTOR" */
    {
        popv(6);
        fn = elt(env, 5); /* errorf */
        return (*qfn1(fn))(qenv(fn), v247);
    }

v209:
    v247 = elt(env, 1); /* "Attempt to divide by zero" */
    {
        popv(6);
        fn = elt(env, 5); /* errorf */
        return (*qfn1(fn))(qenv(fn), v247);
    }
/* error exit handlers */
v23:
    popv(6);
    return nil;
}



/* Code for !*n2a */

static Lisp_Object CC_Hn2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v210;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *n2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v210 = v0;
/* end of prologue */
    v107 = v210;
    v107 = integerp(v107);
    if (!(v107 == nil)) return onevalue(v210);
    v107 = qvalue(elt(env, 1)); /* !*nosq */
    if (v107 == nil) goto v98;
    v107 = v210;
    {
        fn = elt(env, 2); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v107);
    }

v98:
    v107 = v210;
    {
        fn = elt(env, 3); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v107);
    }
}



/* Code for sgn1 */

static Lisp_Object CC_sgn1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v180;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sgn1");
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
    v180 = v1;
    stack[-4] = v0;
/* end of prologue */
    v92 = stack[-4];
    if (!consp(v92)) goto v98;
    v92 = v180;
    v92 = qcar(v92);
    stack[-2] = v92;
    v92 = v180;
    v92 = qcdr(v92);
    stack[-1] = v92;
    v92 = (Lisp_Object)1; /* 0 */
    stack[-3] = v92;
    v92 = (Lisp_Object)17; /* 1 */
    stack[-5] = v92;
    v92 = stack[-4];
    v92 = qcdr(v92);
    stack[-4] = v92;
    goto v205;

v205:
    v180 = stack[-5];
    v92 = stack[-4];
    v92 = qcar(v92);
    stack[0] = times2(v180, v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-6];
    v180 = stack[-2];
    v92 = stack[-3];
    v92 = times2(v180, v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-6];
    v92 = plus2(stack[0], v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-6];
    stack[-3] = v92;
    v180 = stack[-5];
    v92 = stack[-1];
    v92 = times2(v180, v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-6];
    stack[-5] = v92;
    v92 = stack[-4];
    v92 = qcdr(v92);
    stack[-4] = v92;
    if (!(v92 == nil)) goto v205;
    v180 = stack[-3];
    v92 = (Lisp_Object)1; /* 0 */
    v92 = (Lisp_Object)greaterp2(v180, v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    v92 = v92 ? lisp_true : nil;
    env = stack[-6];
    if (v92 == nil) goto v202;
    v92 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v92); }

v202:
    v180 = stack[-3];
    v92 = (Lisp_Object)1; /* 0 */
    v92 = (Lisp_Object)lessp2(v180, v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    v92 = v92 ? lisp_true : nil;
    if (v92 == nil) goto v49;
    v92 = (Lisp_Object)-15; /* -1 */
    { popv(7); return onevalue(v92); }

v49:
    v92 = (Lisp_Object)1; /* 0 */
    { popv(7); return onevalue(v92); }

v98:
    v180 = stack[-4];
    v92 = (Lisp_Object)1; /* 0 */
    v92 = (Lisp_Object)greaterp2(v180, v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    v92 = v92 ? lisp_true : nil;
    env = stack[-6];
    if (v92 == nil) goto v229;
    v92 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v92); }

v229:
    v180 = stack[-4];
    v92 = (Lisp_Object)1; /* 0 */
    v92 = (Lisp_Object)lessp2(v180, v92);
    nil = C_nil;
    if (exception_pending()) goto v142;
    v92 = v92 ? lisp_true : nil;
    if (v92 == nil) goto v153;
    v92 = (Lisp_Object)-15; /* -1 */
    { popv(7); return onevalue(v92); }

v153:
    v92 = (Lisp_Object)1; /* 0 */
    { popv(7); return onevalue(v92); }
/* error exit handlers */
v142:
    popv(7);
    return nil;
}



/* Code for ofsf_lnegrel */

static Lisp_Object CC_ofsf_lnegrel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v80, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_lnegrel");
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
    v159 = v0;
/* end of prologue */
    v80 = v159;
    v144 = elt(env, 1); /* equal */
    if (v80 == v144) goto v36;
    v80 = v159;
    v144 = elt(env, 2); /* neq */
    if (v80 == v144) goto v179;
    v80 = v159;
    v144 = elt(env, 3); /* leq */
    if (v80 == v144) goto v229;
    v80 = v159;
    v144 = elt(env, 5); /* lessp */
    if (v80 == v144) goto v212;
    v80 = v159;
    v144 = elt(env, 6); /* geq */
    if (v80 == v144) goto v171;
    v80 = v159;
    v144 = elt(env, 4); /* greaterp */
    if (v80 == v144) goto v150;
    v144 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v144 == nil)) goto v183;
    v144 = elt(env, 8); /* "ofsf_lnegrel: unknown operator " */
    v80 = v159;
    v144 = list2(v144, v80);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[0];
    fn = elt(env, 9); /* lprie */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[0];
    goto v183;

v183:
    v144 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v246;
    v144 = nil;
    { popv(1); return onevalue(v144); }

v150:
    v144 = elt(env, 3); /* leq */
    { popv(1); return onevalue(v144); }

v171:
    v144 = elt(env, 5); /* lessp */
    { popv(1); return onevalue(v144); }

v212:
    v144 = elt(env, 6); /* geq */
    { popv(1); return onevalue(v144); }

v229:
    v144 = elt(env, 4); /* greaterp */
    { popv(1); return onevalue(v144); }

v179:
    v144 = elt(env, 1); /* equal */
    { popv(1); return onevalue(v144); }

v36:
    v144 = elt(env, 2); /* neq */
    { popv(1); return onevalue(v144); }
/* error exit handlers */
v246:
    popv(1);
    return nil;
}



/* Code for pickbasicset */

static Lisp_Object CC_pickbasicset(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pickbasicset");
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
    stack[-3] = nil;
    v92 = qvalue(elt(env, 1)); /* wuvarlist!* */
    stack[-1] = v92;
    goto v167;

v167:
    v92 = stack[-1];
    if (v92 == nil) goto v96;
    v92 = stack[-1];
    v92 = qcar(v92);
    stack[0] = v92;
    goto v154;

v154:
    v92 = stack[-2];
    if (v92 == nil) goto v225;
    v92 = stack[-2];
    v92 = qcar(v92);
    v92 = qcar(v92);
    v92 = qcar(v92);
    v180 = qcar(v92);
    v92 = stack[0];
    fn = elt(env, 3); /* symbollessp */
    v92 = (*qfn2(fn))(qenv(fn), v180, v92);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-4];
    if (v92 == nil) goto v225;
    v92 = stack[-2];
    v92 = qcdr(v92);
    stack[-2] = v92;
    goto v154;

v225:
    v92 = stack[-2];
    if (v92 == nil) goto v186;
    v180 = stack[0];
    v92 = stack[-2];
    v92 = qcar(v92);
    v92 = qcar(v92);
    v92 = qcar(v92);
    v92 = qcar(v92);
    if (equal(v180, v92)) goto v79;
    v92 = qvalue(elt(env, 2)); /* nil */
    goto v227;

v227:
    if (v92 == nil) goto v186;
    v92 = stack[-2];
    v92 = qcdr(v92);
    stack[-2] = v92;
    goto v225;

v186:
    v92 = stack[-2];
    if (v92 == nil) goto v246;
    v180 = stack[0];
    v92 = stack[-2];
    v92 = qcar(v92);
    v92 = qcar(v92);
    v92 = qcar(v92);
    v92 = qcar(v92);
    if (!(equal(v180, v92))) goto v246;
    v92 = stack[-2];
    v180 = qcar(v92);
    v92 = stack[-3];
    v92 = cons(v180, v92);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-4];
    stack[-3] = v92;
    v92 = stack[-2];
    v92 = qcdr(v92);
    stack[-2] = v92;
    goto v246;

v246:
    v92 = stack[-1];
    v92 = qcdr(v92);
    stack[-1] = v92;
    goto v167;

v79:
    v92 = stack[-2];
    v180 = qcar(v92);
    v92 = stack[-3];
    fn = elt(env, 4); /* wureducedpolysp */
    v92 = (*qfn2(fn))(qenv(fn), v180, v92);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-4];
    v92 = (v92 == nil ? lisp_true : nil);
    goto v227;

v96:
    v92 = stack[-3];
        popv(5);
        return Lnreverse(nil, v92);
/* error exit handlers */
v143:
    popv(5);
    return nil;
}



/* Code for pasf_smordtable2 */

static Lisp_Object CC_pasf_smordtable2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210, v229, v213;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smordtable2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v210 = v1;
    v229 = v0;
/* end of prologue */
    v213 = elt(env, 1); /* ((lessp (lessp 2) (leq 2) (equal 2) (neq nil) (geq nil) (greaterp nil) (cong nil) (ncong nil)) (leq (lessp 2) (leq 2) (equal 2) (neq nil) (geq nil) (greaterp nil) (cong nil)
 (ncong nil)) (equal (lessp false) (leq false) (equal false) (neq 1) (geq 1) (greaterp 1) (cong nil) (ncong nil)) (neq (lessp 2) (leq 2) (equal 2) (neq nil) (geq nil) (greaterp nil) (cong nil) (ncong 
nil)) (geq (lessp false) (leq false) (equal false) (neq 1) (geq 1) (greaterp 1) (cong nil) (ncong nil)) (greaterp (lessp false) (leq false) (equal false) (neq 1) (geq 1) (greaterp 1) (cong nil) (ncong
 nil))) */
    v229 = Latsoc(nil, v229, v213);
    v210 = Latsoc(nil, v210, v229);
    v210 = qcdr(v210);
    return onevalue(v210);
}



/* Code for conditionml */

static Lisp_Object CC_conditionml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conditionml");
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
    v110 = elt(env, 1); /* "<condition>" */
    fn = elt(env, 5); /* printout */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-1];
    v110 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 6); /* indent!* */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-1];
    v110 = stack[0];
    v110 = qcar(v110);
    fn = elt(env, 7); /* expression */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-1];
    v110 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 6); /* indent!* */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-1];
    v110 = elt(env, 4); /* "</condition>" */
    fn = elt(env, 5); /* printout */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v209;
    v110 = nil;
    { popv(2); return onevalue(v110); }
/* error exit handlers */
v209:
    popv(2);
    return nil;
}



/* Code for ps!:arg!-values */

static Lisp_Object CC_psTargKvalues(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v259, v242, v243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:arg-values");
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
    v242 = v0;
/* end of prologue */
    v259 = v242;
    stack[-4] = qcar(v259);
    v259 = v242;
    v259 = qcdr(v259);
    stack[-3] = v259;
    v259 = stack[-3];
    if (v259 == nil) goto v74;
    v259 = stack[-3];
    v259 = qcar(v259);
    v243 = v259;
    v259 = v243;
    if (!consp(v259)) goto v212;
    v259 = v243;
    v242 = qcar(v259);
    v259 = elt(env, 3); /* !:ps!: */
    if (v242 == v259) goto v205;
    v259 = v243;
    v242 = qcar(v259);
    v259 = elt(env, 4); /* dname */
    v259 = get(v242, v259);
    env = stack[-5];
    goto v151;

v151:
    if (v259 == nil) goto v152;
    v259 = v243;
    goto v113;

v113:
    v259 = ncons(v259);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    stack[-1] = v259;
    stack[-2] = v259;
    goto v110;

v110:
    v259 = stack[-3];
    v259 = qcdr(v259);
    stack[-3] = v259;
    v259 = stack[-3];
    if (v259 == nil) goto v260;
    stack[0] = stack[-1];
    v259 = stack[-3];
    v259 = qcar(v259);
    v243 = v259;
    v259 = v243;
    if (!consp(v259)) goto v64;
    v259 = v243;
    v242 = qcar(v259);
    v259 = elt(env, 3); /* !:ps!: */
    if (v242 == v259) goto v261;
    v259 = v243;
    v242 = qcar(v259);
    v259 = elt(env, 4); /* dname */
    v259 = get(v242, v259);
    env = stack[-5];
    goto v63;

v63:
    if (v259 == nil) goto v202;
    v259 = v243;
    goto v254;

v254:
    v259 = ncons(v259);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    v259 = Lrplacd(nil, stack[0], v259);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    v259 = stack[-1];
    v259 = qcdr(v259);
    stack[-1] = v259;
    goto v110;

v202:
    v259 = v243;
    v259 = Lconsp(nil, v259);
    env = stack[-5];
    if (v259 == nil) goto v138;
    v259 = v243;
    v242 = qcar(v259);
    v259 = elt(env, 3); /* !:ps!: */
    if (!(v242 == v259)) goto v138;
    v259 = v243;
    fn = elt(env, 5); /* ps!:value */
    v259 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    goto v254;

v138:
    v259 = v243;
    v259 = CC_psTargKvalues(env, v259);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    goto v254;

v261:
    v259 = qvalue(elt(env, 1)); /* nil */
    goto v63;

v64:
    v259 = qvalue(elt(env, 2)); /* t */
    goto v63;

v260:
    v259 = stack[-2];
    goto v221;

v221:
    {
        Lisp_Object v196 = stack[-4];
        popv(6);
        return cons(v196, v259);
    }

v152:
    v259 = v243;
    v259 = Lconsp(nil, v259);
    env = stack[-5];
    if (v259 == nil) goto v255;
    v259 = v243;
    v242 = qcar(v259);
    v259 = elt(env, 3); /* !:ps!: */
    if (!(v242 == v259)) goto v255;
    v259 = v243;
    fn = elt(env, 5); /* ps!:value */
    v259 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    goto v113;

v255:
    v259 = v243;
    v259 = CC_psTargKvalues(env, v259);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-5];
    goto v113;

v205:
    v259 = qvalue(elt(env, 1)); /* nil */
    goto v151;

v212:
    v259 = qvalue(elt(env, 2)); /* t */
    goto v151;

v74:
    v259 = qvalue(elt(env, 1)); /* nil */
    goto v221;
/* error exit handlers */
v195:
    popv(6);
    return nil;
}



/* Code for letmtr */

static Lisp_Object MS_CDECL CC_letmtr(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v100, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v64, v145, v160, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "letmtr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for letmtr");
#endif
    if (stack >= stacklimit)
    {
        push3(v100,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v100);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v100;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    v64 = stack[0];
    v63 = elt(env, 1); /* mat */
    if (!consp(v64)) goto v74;
    v64 = qcar(v64);
    if (!(v64 == v63)) goto v74;
    v63 = stack[-2];
    v63 = qcdr(v63);
    fn = elt(env, 11); /* revlis */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    stack[-3] = v63;
    fn = elt(env, 12); /* numlis */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    if (v63 == nil) goto v178;
    v63 = stack[-3];
    v64 = Llength(nil, v63);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    v63 = (Lisp_Object)33; /* 2 */
    v63 = Lneq(nil, v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    goto v225;

v225:
    if (v63 == nil) goto v109;
    v45 = elt(env, 7); /* "Syntax error:" */
    v160 = stack[-2];
    v145 = elt(env, 8); /* "invalid" */
    v64 = qvalue(elt(env, 9)); /* nil */
    v63 = elt(env, 10); /* hold */
    {
        popv(5);
        fn = elt(env, 13); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v45, v160, v145, v64, v63);
    }

v109:
    v63 = stack[0];
    v64 = qcdr(v63);
    v63 = stack[-3];
    v63 = qcar(v63);
    fn = elt(env, 14); /* pnth */
    v63 = (*qfn2(fn))(qenv(fn), v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    v64 = qcar(v63);
    v63 = stack[-3];
    v63 = qcdr(v63);
    v63 = qcar(v63);
    fn = elt(env, 14); /* pnth */
    v64 = (*qfn2(fn))(qenv(fn), v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    v63 = stack[-1];
    v63 = Lrplaca(nil, v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v92;
    v63 = nil;
    { popv(5); return onevalue(v63); }

v178:
    v63 = qvalue(elt(env, 6)); /* t */
    goto v225;

v74:
    v145 = elt(env, 2); /* "Matrix" */
    v63 = stack[-2];
    v64 = qcar(v63);
    v63 = elt(env, 3); /* "not set" */
    v63 = list3(v145, v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    v64 = v63;
    v63 = v64;
    qvalue(elt(env, 4)) = v63; /* errmsg!* */
    v63 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v63 == nil)) goto v76;
    v63 = v64;
    fn = elt(env, 15); /* lprie */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    goto v76;

v76:
    v63 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    goto v109;
/* error exit handlers */
v92:
    popv(5);
    return nil;
}



/* Code for chksymmetries!&sub1 */

static Lisp_Object MS_CDECL CC_chksymmetriesGsub1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v100, Lisp_Object v21, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v173, v222;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "chksymmetries&sub1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chksymmetries&sub1");
#endif
    if (stack >= stacklimit)
    {
        push4(v21,v100,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v100,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    v170 = v100;
    v173 = v1;
    v222 = v0;
/* end of prologue */
    v170 = Lsubst(nil, 3, v222, v173, v170);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-2];
    stack[-1] = v170;
    v170 = stack[0];
    if (v170 == nil) goto v210;
    v173 = stack[-1];
    v170 = stack[0];
    fn = elt(env, 3); /* indxsymp */
    v170 = (*qfn2(fn))(qenv(fn), v173, v170);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-2];
    goto v107;

v107:
    if (!(v170 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v170 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v170); }

v210:
    v170 = qvalue(elt(env, 1)); /* t */
    goto v107;
/* error exit handlers */
v225:
    popv(3);
    return nil;
}



/* Code for coeff_calc */

static Lisp_Object MS_CDECL CC_coeff_calc(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v100, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210, v229, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeff_calc");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeff_calc");
#endif
    if (stack >= stacklimit)
    {
        push3(v100,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v100);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v210 = v100;
    v229 = v1;
    v213 = v0;
/* end of prologue */
    stack[0] = elt(env, 1); /* plus */
    fn = elt(env, 2); /* coeff1_calc */
    v210 = (*qfnn(fn))(qenv(fn), 3, v213, v229, v210);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-1];
    v210 = cons(stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* reval */
        return (*qfn1(fn))(qenv(fn), v210);
    }
/* error exit handlers */
v211:
    popv(2);
    return nil;
}



/* Code for xremf */

static Lisp_Object MS_CDECL CC_xremf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v100, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v286, v287, v288;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xremf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xremf");
#endif
    if (stack >= stacklimit)
    {
        push3(v100,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v100);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v100;
    stack[-6] = v1;
    stack[-7] = v0;
/* end of prologue */
    stack[-1] = nil;
    v286 = (Lisp_Object)1; /* 0 */
    stack[-8] = v286;
    v286 = stack[-6];
    if (!consp(v286)) goto v107;
    v286 = stack[-6];
    v286 = qcar(v286);
    v286 = (consp(v286) ? nil : lisp_true);
    goto v154;

v154:
    if (v286 == nil) goto v209;
    v287 = stack[-7];
    v286 = stack[-6];
    fn = elt(env, 3); /* qremd */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    v286 = qcdr(v286);
    popv(10);
    return ncons(v286);

v209:
    v286 = stack[-7];
    fn = elt(env, 4); /* termsf */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    stack[0] = v286;
    goto v158;

v158:
    v287 = stack[-5];
    v286 = (Lisp_Object)1; /* 0 */
    v286 = (Lisp_Object)lesseq2(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    v286 = v286 ? lisp_true : nil;
    env = stack[-9];
    if (v286 == nil) goto v225;
    v286 = qvalue(elt(env, 2)); /* nil */
    { popv(10); return onevalue(v286); }

v225:
    v286 = stack[-7];
    if (!consp(v286)) goto v217;
    v286 = stack[-7];
    v286 = qcar(v286);
    v286 = (consp(v286) ? nil : lisp_true);
    goto v203;

v203:
    if (v286 == nil) goto v162;
    v287 = stack[-1];
    v286 = stack[-7];
    fn = elt(env, 5); /* addf */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    popv(10);
    return ncons(v286);

v162:
    v286 = stack[-7];
    v286 = qcar(v286);
    v286 = qcar(v286);
    v287 = qcar(v286);
    v286 = stack[-6];
    v286 = qcar(v286);
    v286 = qcar(v286);
    v286 = qcar(v286);
    if (v287 == v286) goto v174;
    v286 = stack[-7];
    v286 = qcar(v286);
    v286 = qcar(v286);
    v287 = qcar(v286);
    v286 = stack[-6];
    v286 = qcar(v286);
    v286 = qcar(v286);
    v286 = qcar(v286);
    fn = elt(env, 6); /* ordop */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    if (v286 == nil) goto v290;
    v287 = stack[-5];
    v286 = stack[-8];
    v286 = plus2(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    stack[-5] = v286;
    v286 = stack[-7];
    v286 = qcar(v286);
    v288 = qcdr(v286);
    v287 = stack[-6];
    v286 = stack[-5];
    v286 = CC_xremf(env, 3, v288, v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    stack[-3] = v286;
    v286 = stack[-3];
    if (v286 == nil) goto v291;
    v286 = stack[-7];
    v286 = qcar(v286);
    v287 = qcar(v286);
    v286 = (Lisp_Object)17; /* 1 */
    v286 = cons(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    v287 = ncons(v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    v286 = stack[-3];
    v286 = qcar(v286);
    fn = elt(env, 7); /* multf */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    fn = elt(env, 5); /* addf */
    v286 = (*qfn2(fn))(qenv(fn), stack[-1], v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    stack[-1] = v286;
    v286 = stack[-1];
    fn = elt(env, 4); /* termsf */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    stack[-8] = v286;
    v287 = stack[-5];
    v286 = stack[-8];
    v286 = difference2(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    stack[-5] = v286;
    v286 = stack[-7];
    v286 = qcdr(v286);
    stack[-7] = v286;
    goto v158;

v291:
    v286 = qvalue(elt(env, 2)); /* nil */
    { popv(10); return onevalue(v286); }

v290:
    v287 = stack[-1];
    v286 = stack[-7];
    fn = elt(env, 5); /* addf */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    popv(10);
    return ncons(v286);

v174:
    v286 = stack[-7];
    v286 = qcar(v286);
    v286 = qcar(v286);
    v287 = qcdr(v286);
    v286 = stack[-6];
    v286 = qcar(v286);
    v286 = qcar(v286);
    v286 = qcdr(v286);
    v287 = difference2(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    stack[-4] = v287;
    v286 = (Lisp_Object)1; /* 0 */
    v286 = (Lisp_Object)lessp2(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    v286 = v286 ? lisp_true : nil;
    env = stack[-9];
    if (v286 == nil) goto v161;
    v287 = stack[-1];
    v286 = stack[-7];
    fn = elt(env, 5); /* addf */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    popv(10);
    return ncons(v286);

v161:
    v286 = stack[-7];
    v286 = qcar(v286);
    v287 = qcdr(v286);
    v286 = stack[-6];
    v286 = qcar(v286);
    v286 = qcdr(v286);
    fn = elt(env, 8); /* qremf */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    stack[-3] = v286;
    v286 = stack[-7];
    v286 = qcar(v286);
    v287 = qcar(v286);
    v286 = (Lisp_Object)17; /* 1 */
    v286 = cons(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    v287 = ncons(v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    v286 = stack[-3];
    v286 = qcdr(v286);
    fn = elt(env, 7); /* multf */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    stack[-2] = v286;
    v287 = stack[-5];
    v286 = stack[-8];
    v286 = plus2(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    stack[-5] = v286;
    v287 = stack[-1];
    v286 = stack[-2];
    fn = elt(env, 5); /* addf */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    stack[-1] = v286;
    v286 = stack[-1];
    fn = elt(env, 4); /* termsf */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    stack[-8] = v286;
    v287 = stack[-5];
    v286 = stack[-8];
    v287 = difference2(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    v286 = stack[0];
    v286 = plus2(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    stack[-5] = v286;
    v286 = stack[-3];
    v286 = qcar(v286);
    if (v286 == nil) goto v193;
    stack[0] = stack[-7];
    v287 = stack[-4];
    v286 = (Lisp_Object)1; /* 0 */
    if (v287 == v286) goto v187;
    v286 = stack[-7];
    v286 = qcar(v286);
    v286 = qcar(v286);
    v288 = qcar(v286);
    v287 = stack[-4];
    v286 = (Lisp_Object)17; /* 1 */
    v286 = acons(v288, v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    v287 = ncons(v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    v286 = stack[-6];
    fn = elt(env, 7); /* multf */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    stack[-4] = v286;
    goto v43;

v43:
    v286 = stack[-3];
    v286 = qcar(v286);
    fn = elt(env, 9); /* negf */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    fn = elt(env, 7); /* multf */
    v286 = (*qfn2(fn))(qenv(fn), stack[-4], v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    fn = elt(env, 5); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    v286 = stack[-2];
    fn = elt(env, 9); /* negf */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    fn = elt(env, 5); /* addf */
    v286 = (*qfn2(fn))(qenv(fn), stack[0], v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    goto v292;

v292:
    stack[-7] = v286;
    v286 = stack[-7];
    fn = elt(env, 4); /* termsf */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    stack[0] = v286;
    v287 = stack[-5];
    v286 = stack[0];
    v286 = difference2(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-9];
    stack[-5] = v286;
    goto v158;

v187:
    v286 = stack[-6];
    stack[-4] = v286;
    goto v43;

v193:
    v286 = stack[-7];
    v286 = qcdr(v286);
    goto v292;

v217:
    v286 = qvalue(elt(env, 1)); /* t */
    goto v203;

v107:
    v286 = qvalue(elt(env, 1)); /* t */
    goto v154;
/* error exit handlers */
v289:
    popv(10);
    return nil;
}



/* Code for extract_numid */

static Lisp_Object CC_extract_numid(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v215;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extract_numid");
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

v172:
    v212 = stack[0];
    if (v212 == nil) goto v36;
    v212 = stack[0];
    v212 = qcar(v212);
    fn = elt(env, 2); /* !*id2num */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    v215 = v212;
    v212 = v215;
    if (v212 == nil) goto v113;
    stack[-1] = v215;
    v212 = stack[0];
    v212 = qcdr(v212);
    v212 = CC_extract_numid(env, v212);
    nil = C_nil;
    if (exception_pending()) goto v105;
    {
        Lisp_Object v106 = stack[-1];
        popv(3);
        return cons(v106, v212);
    }

v113:
    v212 = stack[0];
    v212 = qcdr(v212);
    stack[0] = v212;
    goto v172;

v36:
    v212 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v212); }
/* error exit handlers */
v105:
    popv(3);
    return nil;
}



/* Code for st_flatten */

static Lisp_Object CC_st_flatten(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_flatten");
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
    v148 = v0;
/* end of prologue */
    v102 = v148;
    v102 = qcdr(v102);
    v102 = qcar(v102);
    if (is_number(v102)) goto v36;
    v102 = v148;
    v102 = qcdr(v102);
    stack[-3] = v102;
    goto v207;

v207:
    v102 = stack[-3];
    if (v102 == nil) goto v229;
    v102 = stack[-3];
    v102 = qcar(v102);
    v102 = CC_st_flatten(env, v102);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    fn = elt(env, 2); /* copy */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    stack[-2] = v102;
    v102 = stack[-2];
    fn = elt(env, 3); /* lastpair */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    stack[-1] = v102;
    v102 = stack[-3];
    v102 = qcdr(v102);
    stack[-3] = v102;
    v102 = stack[-1];
    if (!consp(v102)) goto v207;
    else goto v208;

v208:
    v102 = stack[-3];
    if (v102 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v102 = stack[-3];
    v102 = qcar(v102);
    v102 = CC_st_flatten(env, v102);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    fn = elt(env, 2); /* copy */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    v102 = Lrplacd(nil, stack[0], v102);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    v102 = stack[-1];
    fn = elt(env, 3); /* lastpair */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    stack[-1] = v102;
    v102 = stack[-3];
    v102 = qcdr(v102);
    stack[-3] = v102;
    goto v208;

v229:
    v102 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v102); }

v36:
    v102 = v148;
    v102 = qcdr(v102);
    { popv(5); return onevalue(v102); }
/* error exit handlers */
v115:
    popv(5);
    return nil;
}



/* Code for diff!-k!-times!-mod!-p */

static Lisp_Object MS_CDECL CC_diffKkKtimesKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v100, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v259, v242;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "diff-k-times-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff-k-times-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v100,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v100);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v100;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v56 = stack[-3];
    if (!consp(v56)) goto v228;
    v56 = stack[-3];
    v56 = qcar(v56);
    v56 = (consp(v56) ? nil : lisp_true);
    goto v95;

v95:
    if (v56 == nil) goto v107;
    v56 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v56); }

v107:
    v56 = stack[-3];
    v56 = qcar(v56);
    v56 = qcar(v56);
    v259 = qcar(v56);
    v56 = stack[-1];
    if (equal(v259, v56)) goto v168;
    v56 = stack[-3];
    v56 = qcar(v56);
    stack[-4] = qcar(v56);
    v56 = stack[-3];
    v56 = qcar(v56);
    v242 = qcdr(v56);
    v259 = stack[-2];
    v56 = stack[-1];
    stack[0] = CC_diffKkKtimesKmodKp(env, 3, v242, v259, v56);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-5];
    v56 = stack[-3];
    v242 = qcdr(v56);
    v259 = stack[-2];
    v56 = stack[-1];
    v56 = CC_diffKkKtimesKmodKp(env, 3, v242, v259, v56);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-5];
    {
        Lisp_Object v195 = stack[-4];
        Lisp_Object v196 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v195, v196, v56);
    }

v168:
    v56 = stack[-3];
    v56 = qcar(v56);
    v56 = qcar(v56);
    v259 = qcdr(v56);
    v56 = stack[-2];
    v56 = (Lisp_Object)lessp2(v259, v56);
    nil = C_nil;
    if (exception_pending()) goto v132;
    v56 = v56 ? lisp_true : nil;
    env = stack[-5];
    if (v56 == nil) goto v226;
    v56 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v56); }

v226:
    v56 = stack[-3];
    v56 = qcar(v56);
    v56 = qcar(v56);
    v259 = qcdr(v56);
    v56 = stack[-2];
    if (equal(v259, v56)) goto v158;
    v56 = stack[-1];
    fn = elt(env, 4); /* fkern */
    stack[0] = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-5];
    v56 = stack[-3];
    v56 = qcar(v56);
    v56 = qcar(v56);
    v259 = qcdr(v56);
    v56 = stack[-2];
    v56 = difference2(v259, v56);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-5];
    fn = elt(env, 5); /* getpower */
    stack[-4] = (*qfn2(fn))(qenv(fn), stack[0], v56);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-5];
    v56 = stack[-3];
    v56 = qcar(v56);
    v56 = qcar(v56);
    v259 = qcdr(v56);
    v56 = stack[-2];
    fn = elt(env, 6); /* binomial!-coefft!-mod!-p */
    v259 = (*qfn2(fn))(qenv(fn), v259, v56);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-5];
    v56 = stack[-3];
    v56 = qcar(v56);
    v56 = qcdr(v56);
    fn = elt(env, 7); /* times!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v259, v56);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-5];
    v56 = stack[-3];
    v242 = qcdr(v56);
    v259 = stack[-2];
    v56 = stack[-1];
    v56 = CC_diffKkKtimesKmodKp(env, 3, v242, v259, v56);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-5];
    {
        Lisp_Object v297 = stack[-4];
        Lisp_Object v281 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v297, v281, v56);
    }

v158:
    v56 = stack[-3];
    v56 = qcar(v56);
    v56 = qcdr(v56);
    { popv(6); return onevalue(v56); }

v228:
    v56 = qvalue(elt(env, 1)); /* t */
    goto v95;
/* error exit handlers */
v132:
    popv(6);
    return nil;
}



/* Code for dvfsf_v */

static Lisp_Object CC_dvfsf_v(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v229, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_v");
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
    v229 = v0;
/* end of prologue */
    v213 = v229;
    v229 = qvalue(elt(env, 1)); /* dvfsf_p!* */
    fn = elt(env, 2); /* qremf */
    v229 = (*qfn2(fn))(qenv(fn), v213, v229);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[0];
    v213 = v229;
    v229 = v213;
    v229 = qcdr(v229);
    if (v229 == nil) goto v98;
    v229 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v229); }

v98:
    v229 = v213;
    v229 = qcar(v229);
    v229 = CC_dvfsf_v(env, v229);
    nil = C_nil;
    if (exception_pending()) goto v214;
    popv(1);
    return add1(v229);
/* error exit handlers */
v214:
    popv(1);
    return nil;
}



/* Code for iv_cutcongs1 */

static Lisp_Object CC_iv_cutcongs1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for iv_cutcongs1");
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
    v153 = stack[0];
    if (v153 == nil) goto v113;
    v151 = stack[-1];
    v153 = stack[0];
    v153 = qcar(v153);
    fn = elt(env, 3); /* iv_cutcongs2 */
    v153 = (*qfn2(fn))(qenv(fn), v151, v153);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    if (v153 == nil) goto v214;
    v153 = stack[0];
    v153 = qcdr(v153);
    stack[0] = v153;
    goto v136;

v214:
    v153 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v153); }

v113:
    v153 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v153); }
/* error exit handlers */
v76:
    popv(3);
    return nil;
}



/* Code for ev_sum */

static Lisp_Object CC_ev_sum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v106, v169;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_sum");
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
    v169 = nil;
    goto v167;

v167:
    v105 = stack[-1];
    if (v105 == nil) goto v96;
    v105 = stack[-1];
    v106 = qcar(v105);
    v105 = stack[0];
    v105 = qcar(v105);
    v105 = (Lisp_Object)(int32_t)((int32_t)v106 + (int32_t)v105 - TAG_FIXNUM);
    v106 = v169;
    v105 = cons(v105, v106);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-2];
    v169 = v105;
    v105 = stack[-1];
    v105 = qcdr(v105);
    stack[-1] = v105;
    v105 = stack[0];
    v105 = qcdr(v105);
    stack[0] = v105;
    goto v167;

v96:
    v105 = v169;
        popv(3);
        return Lnreverse(nil, v105);
/* error exit handlers */
v222:
    popv(3);
    return nil;
}



/* Code for conditionrd */

static Lisp_Object MS_CDECL CC_conditionrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v210;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "conditionrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conditionrd");
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
    fn = elt(env, 3); /* lex */
    v107 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-1];
    v210 = qvalue(elt(env, 1)); /* char */
    v107 = elt(env, 2); /* (r e l n) */
    if (equal(v210, v107)) goto v96;
    fn = elt(env, 4); /* mathml */
    v107 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-1];
    stack[0] = v107;
    goto v221;

v221:
    fn = elt(env, 3); /* lex */
    v107 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v213;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v96:
    fn = elt(env, 5); /* relnrd */
    v107 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-1];
    stack[0] = v107;
    goto v221;
/* error exit handlers */
v213:
    popv(2);
    return nil;
}



/* Code for crprep1 */

static Lisp_Object CC_crprep1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v257, v199, v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crprep1");
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
    v257 = v0;
/* end of prologue */
    v199 = v257;
    v199 = qcar(v199);
    v257 = qcdr(v257);
    stack[-2] = v199;
    stack[-1] = v257;
    v257 = stack[-1];
    if (is_number(v257)) goto v105;
    v257 = stack[-1];
    v257 = qcdr(v257);
    if (!consp(v257)) goto v208;
    v257 = stack[-1];
    v257 = qcdr(v257);
    v199 = qcar(v257);
    v257 = (Lisp_Object)1; /* 0 */
    v257 = (v199 == v257 ? lisp_true : nil);
    goto v98;

v98:
    if (!(v257 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v257 = stack[-1];
    if (is_number(v257)) goto v225;
    v257 = stack[-1];
    fn = elt(env, 4); /* rd!:minusp */
    v257 = (*qfn1(fn))(qenv(fn), v257);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-3];
    if (v257 == nil) goto v225;
    stack[0] = elt(env, 2); /* minus */
    v257 = stack[-1];
    fn = elt(env, 5); /* rd!:minus */
    v257 = (*qfn1(fn))(qenv(fn), v257);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-3];
    fn = elt(env, 6); /* crprimp */
    v257 = (*qfn1(fn))(qenv(fn), v257);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-3];
    v257 = list2(stack[0], v257);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-3];
    goto v186;

v186:
    stack[-1] = v257;
    v257 = stack[-2];
    if (is_number(v257)) goto v200;
    v257 = stack[-2];
    v257 = qcdr(v257);
    if (!consp(v257)) goto v66;
    v257 = stack[-2];
    v257 = qcdr(v257);
    v199 = qcar(v257);
    v257 = (Lisp_Object)1; /* 0 */
    v257 = (v199 == v257 ? lisp_true : nil);
    goto v115;

v115:
    if (!(v257 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v199 = stack[-2];
    v257 = (Lisp_Object)-15; /* -1 */
    if (v199 == v257) goto v49;
    v257 = stack[-2];
    if (is_number(v257)) goto v61;
    v257 = stack[-2];
    fn = elt(env, 4); /* rd!:minusp */
    v257 = (*qfn1(fn))(qenv(fn), v257);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-3];
    goto v141;

v141:
    if (v257 == nil) goto v198;
    stack[0] = elt(env, 2); /* minus */
    v257 = stack[-2];
    fn = elt(env, 5); /* rd!:minus */
    v257 = (*qfn1(fn))(qenv(fn), v257);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-3];
    v257 = list2(stack[0], v257);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-3];
    stack[-2] = v257;
    goto v198;

v198:
    v137 = elt(env, 3); /* plus */
    v199 = stack[-2];
    v257 = stack[-1];
    popv(4);
    return list3(v137, v199, v257);

v61:
    v257 = qvalue(elt(env, 1)); /* nil */
    goto v141;

v49:
    v199 = elt(env, 2); /* minus */
    v257 = (Lisp_Object)17; /* 1 */
    v257 = list2(v199, v257);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-3];
    stack[-2] = v257;
    goto v198;

v66:
    v257 = stack[-2];
    v257 = qcdr(v257);
    v257 = (Lisp_Object)zerop(v257);
    v257 = v257 ? lisp_true : nil;
    env = stack[-3];
    goto v115;

v200:
    v257 = qvalue(elt(env, 1)); /* nil */
    goto v115;

v225:
    v257 = stack[-1];
    fn = elt(env, 6); /* crprimp */
    v257 = (*qfn1(fn))(qenv(fn), v257);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-3];
    goto v186;

v208:
    v257 = stack[-1];
    v257 = qcdr(v257);
    v257 = (Lisp_Object)zerop(v257);
    v257 = v257 ? lisp_true : nil;
    env = stack[-3];
    goto v98;

v105:
    v257 = qvalue(elt(env, 1)); /* nil */
    goto v98;
/* error exit handlers */
v57:
    popv(4);
    return nil;
}



/* Code for sptransmat */

static Lisp_Object CC_sptransmat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v240, v197, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sptransmat");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
/* end of prologue */
    v138 = stack[-1];
    v138 = Lconsp(nil, v138);
    env = stack[-7];
    if (v138 == nil) goto v107;
    v138 = stack[-1];
    stack[0] = v138;
    v138 = stack[-1];
    fn = elt(env, 3); /* matlength */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-7];
    v138 = qcdr(v138);
    goto v98;

v98:
    v240 = (Lisp_Object)1; /* 0 */
    stack[-6] = v240;
    v240 = (Lisp_Object)1; /* 0 */
    stack[-5] = v240;
    v240 = v138;
    stack[-1] = qcar(v240);
    v240 = elt(env, 1); /* spm */
    v138 = cons(v240, v138);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-7];
    fn = elt(env, 4); /* mkempspmat */
    v138 = (*qfn2(fn))(qenv(fn), stack[-1], v138);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-7];
    stack[-2] = v138;
    v138 = qvalue(elt(env, 2)); /* nil */
    v138 = ncons(v138);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-7];
    v138 = ncons(v138);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-7];
    stack[-3] = v138;
    v138 = stack[0];
    v138 = qcdr(v138);
    stack[-1] = v138;
    goto v150;

v150:
    v138 = stack[-1];
    if (v138 == nil) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    v138 = stack[-1];
    v138 = qcar(v138);
    stack[0] = v138;
    v138 = stack[-6];
    v138 = add1(v138);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-7];
    stack[-6] = v138;
    v138 = stack[0];
    stack[0] = v138;
    goto v115;

v115:
    v138 = stack[0];
    if (v138 == nil) goto v116;
    v138 = stack[0];
    v138 = qcar(v138);
    stack[-4] = v138;
    v138 = stack[-5];
    v138 = add1(v138);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-7];
    stack[-5] = v138;
    v240 = stack[-4];
    v138 = (Lisp_Object)1; /* 0 */
    if (v240 == v138) goto v99;
    v197 = stack[-5];
    v240 = stack[-4];
    v138 = stack[-3];
    v138 = acons(v197, v240, v138);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-7];
    stack[-3] = v138;
    goto v99;

v99:
    v138 = stack[0];
    v138 = qcdr(v138);
    stack[0] = v138;
    goto v115;

v116:
    v138 = stack[-3];
    v138 = Lreverse(nil, v138);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-7];
    stack[-3] = v138;
    stack[0] = stack[-3];
    v138 = qvalue(elt(env, 2)); /* nil */
    v138 = ncons(v138);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-7];
    v138 = ncons(v138);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-7];
    if (equal(stack[0], v138)) goto v37;
    v240 = stack[-2];
    v138 = stack[-6];
    v57 = list2(v240, v138);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-7];
    v197 = stack[-3];
    v240 = stack[-2];
    v138 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 5); /* letmtr3 */
    v138 = (*qfnn(fn))(qenv(fn), 4, v57, v197, v240, v138);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-7];
    goto v37;

v37:
    v138 = (Lisp_Object)1; /* 0 */
    stack[-5] = v138;
    v138 = qvalue(elt(env, 2)); /* nil */
    v138 = ncons(v138);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-7];
    v138 = ncons(v138);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-7];
    stack[-3] = v138;
    v138 = stack[-1];
    v138 = qcdr(v138);
    stack[-1] = v138;
    goto v150;

v107:
    v138 = stack[-1];
    fn = elt(env, 6); /* aeval */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-7];
    stack[0] = v138;
    v138 = stack[-1];
    fn = elt(env, 6); /* aeval */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-7];
    fn = elt(env, 3); /* matlength */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-7];
    v138 = qcdr(v138);
    goto v98;
/* error exit handlers */
v301:
    popv(8);
    return nil;
}



/* Code for f2dip */

static Lisp_Object CC_f2dip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2dip");
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
    v179 = v0;
/* end of prologue */
    stack[-1] = v179;
    fn = elt(env, 1); /* evzero */
    stack[0] = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-2];
    v179 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 2); /* bcfd */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-2];
    {
        Lisp_Object v207 = stack[-1];
        Lisp_Object v208 = stack[0];
        popv(3);
        fn = elt(env, 3); /* f2dip1 */
        return (*qfnn(fn))(qenv(fn), 3, v207, v208, v179);
    }
/* error exit handlers */
v209:
    popv(3);
    return nil;
}



/* Code for preproc */

static Lisp_Object CC_preproc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v209, v207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preproc");
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
    v209 = v0;
/* end of prologue */
    fn = elt(env, 1); /* preproc1 */
    v209 = (*qfn1(fn))(qenv(fn), v209);
    errexit();
    v207 = v209;
    v209 = v207;
    if (v209 == nil) return onevalue(v207);
    v209 = v207;
    v209 = qcar(v209);
    return onevalue(v209);
}



/* Code for free */

static Lisp_Object CC_free(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for free");
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
    v207 = stack[0];
    v207 = qcdr(v207);
    v207 = qcar(v207);
    fn = elt(env, 2); /* freeind */
    v207 = (*qfn1(fn))(qenv(fn), v207);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-1];
    if (v207 == nil) goto v36;
    v207 = stack[0];
    v207 = qcdr(v207);
    v207 = qcdr(v207);
    v207 = qcar(v207);
    {
        popv(2);
        fn = elt(env, 2); /* freeind */
        return (*qfn1(fn))(qenv(fn), v207);
    }

v36:
    v207 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v207); }
/* error exit handlers */
v74:
    popv(2);
    return nil;
}



/* Code for set!-weights */

static Lisp_Object CC_setKweights(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v227;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for set-weights");
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
    v227 = v0;
/* end of prologue */
    stack[-4] = (Lisp_Object)1; /* 0 */
    v227 = qcdr(v227);
    stack[-3] = v227;
    v227 = stack[-3];
    if (v227 == nil) goto v229;
    v227 = (Lisp_Object)17; /* 1 */
    v227 = ncons(v227);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-5];
    stack[-1] = v227;
    stack[-2] = v227;
    goto v208;

v208:
    v227 = stack[-3];
    v227 = qcdr(v227);
    stack[-3] = v227;
    v227 = stack[-3];
    if (v227 == nil) goto v168;
    stack[0] = stack[-1];
    v227 = (Lisp_Object)17; /* 1 */
    v227 = ncons(v227);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-5];
    v227 = Lrplacd(nil, stack[0], v227);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-5];
    v227 = stack[-1];
    v227 = qcdr(v227);
    stack[-1] = v227;
    goto v208;

v168:
    v227 = stack[-2];
    goto v97;

v97:
    v227 = cons(stack[-4], v227);
    nil = C_nil;
    if (exception_pending()) goto v205;
        popv(6);
        return Lnreverse(nil, v227);

v229:
    v227 = qvalue(elt(env, 1)); /* nil */
    goto v97;
/* error exit handlers */
v205:
    popv(6);
    return nil;
}



setup_type const u36_setup[] =
{
    {"mk+mat+plus+mat",         too_few_2,      CC_mkLmatLplusLmat,wrong_no_2},
    {"mri_congp",               CC_mri_congp,   too_many_1,    wrong_no_1},
    {"prsubsetrd",              CC_prsubsetrd,  too_many_1,    wrong_no_1},
    {"ps:set-term",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_psTsetKterm},
    {"simpu",                   CC_simpu,       too_many_1,    wrong_no_1},
    {"subs2pf",                 CC_subs2pf,     too_many_1,    wrong_no_1},
    {"divide-by-power-of-ten",  too_few_2,      CC_divideKbyKpowerKofKten,wrong_no_2},
    {"subfindices",             too_few_2,      CC_subfindices,wrong_no_2},
    {"dfdeg",                   too_few_2,      CC_dfdeg,      wrong_no_2},
    {"find_triangles1",         too_few_2,      CC_find_triangles1,wrong_no_2},
    {"fs:zerop:",               CC_fsTzeropT,   too_many_1,    wrong_no_1},
    {"*g2lex",                  CC_Hg2lex,      too_many_1,    wrong_no_1},
    {"r2flbf",                  CC_r2flbf,      too_many_1,    wrong_no_1},
    {"bfprin0x",                too_few_2,      CC_bfprin0x,   wrong_no_2},
    {"nextu",                   too_few_2,      CC_nextu,      wrong_no_2},
    {"repr_a",                  CC_repr_a,      too_many_1,    wrong_no_1},
    {"cols2rows2",              too_few_2,      CC_cols2rows2, wrong_no_2},
    {"i2ps",                    CC_i2ps,        too_many_1,    wrong_no_1},
    {"groebcplistmerge",        too_few_2,      CC_groebcplistmerge,wrong_no_2},
    {"multsqpf",                too_few_2,      CC_multsqpf,   wrong_no_2},
    {"*kp2q",                   too_few_2,      CC_Hkp2q,      wrong_no_2},
    {"gcdld",                   too_few_2,      CC_gcdld,      wrong_no_2},
    {"dfp-rule-found",          too_few_2,      CC_dfpKruleKfound,wrong_no_2},
    {"fs:minusp",               CC_fsTminusp,   too_many_1,    wrong_no_1},
    {"mo_zero?",                CC_mo_zeroW,    too_many_1,    wrong_no_1},
    {"quotfail-in-vector",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_quotfailKinKvector},
    {"*n2a",                    CC_Hn2a,        too_many_1,    wrong_no_1},
    {"sgn1",                    too_few_2,      CC_sgn1,       wrong_no_2},
    {"ofsf_lnegrel",            CC_ofsf_lnegrel,too_many_1,    wrong_no_1},
    {"pickbasicset",            CC_pickbasicset,too_many_1,    wrong_no_1},
    {"pasf_smordtable2",        too_few_2,      CC_pasf_smordtable2,wrong_no_2},
    {"conditionml",             CC_conditionml, too_many_1,    wrong_no_1},
    {"ps:arg-values",           CC_psTargKvalues,too_many_1,   wrong_no_1},
    {"letmtr",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_letmtr},
    {"chksymmetries&sub1",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_chksymmetriesGsub1},
    {"coeff_calc",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeff_calc},
    {"xremf",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_xremf},
    {"extract_numid",           CC_extract_numid,too_many_1,   wrong_no_1},
    {"st_flatten",              CC_st_flatten,  too_many_1,    wrong_no_1},
    {"diff-k-times-mod-p",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffKkKtimesKmodKp},
    {"dvfsf_v",                 CC_dvfsf_v,     too_many_1,    wrong_no_1},
    {"iv_cutcongs1",            too_few_2,      CC_iv_cutcongs1,wrong_no_2},
    {"ev_sum",                  too_few_2,      CC_ev_sum,     wrong_no_2},
    {"conditionrd",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_conditionrd},
    {"crprep1",                 CC_crprep1,     too_many_1,    wrong_no_1},
    {"sptransmat",              CC_sptransmat,  too_many_1,    wrong_no_1},
    {"f2dip",                   CC_f2dip,       too_many_1,    wrong_no_1},
    {"preproc",                 CC_preproc,     too_many_1,    wrong_no_1},
    {"free",                    CC_free,        too_many_1,    wrong_no_1},
    {"set-weights",             CC_setKweights, too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u36", (two_args *)"1655 1546201 5186978", 0}
};

/* end of generated code */
