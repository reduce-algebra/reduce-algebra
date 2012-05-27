
/* $destdir\u02.c        Machine generated C code */

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


/* Code for lto_hashequalq */

static Lisp_Object CC_lto_hashequalq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_hashequalq");
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
    v12 = (Lisp_Object)1; /* 0 */
    stack[-1] = v12;
    v12 = (Lisp_Object)1; /* 0 */
    stack[0] = v12;
    goto v14;

v14:
    v12 = stack[-3];
    if (v12 == nil) goto v15;
    v12 = stack[-2];
    if (v12 == nil) goto v15;
    v12 = stack[-3];
    v12 = qcar(v12);
    v13 = v12;
    v12 = stack[-2];
    v12 = qcar(v12);
    stack[-4] = v12;
    v12 = stack[-3];
    v12 = qcdr(v12);
    stack[-3] = v12;
    v12 = stack[-2];
    v12 = qcdr(v12);
    stack[-2] = v12;
    v12 = v13;
    fn = elt(env, 2); /* lto_hashid */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-5];
    v12 = (Lisp_Object)(int32_t)((int32_t)stack[-1] + (int32_t)v12 - TAG_FIXNUM);
    stack[-1] = v12;
    v12 = stack[-4];
    fn = elt(env, 2); /* lto_hashid */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-5];
    v12 = (Lisp_Object)(int32_t)((int32_t)stack[0] + (int32_t)v12 - TAG_FIXNUM);
    stack[0] = v12;
    goto v14;

v15:
    v12 = stack[-3];
    if (v12 == nil) goto v17;
    v12 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v12); }

v17:
    v12 = stack[-2];
    if (v12 == nil) goto v18;
    v12 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v12); }

v18:
    v13 = stack[-1];
    v12 = stack[0];
        popv(6);
        return Leqn(nil, v13, v12);
/* error exit handlers */
v16:
    popv(6);
    return nil;
}



/* Code for compress!* */

static Lisp_Object CC_compressH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36, v37, v38;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compress*");
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
    v35 = v0;
/* end of prologue */
    v38 = nil;
    v36 = v35;
    v36 = qcar(v36);
    v36 = Ldigitp(nil, v36);
    env = stack[-1];
    if (v36 == nil) goto v4;
        popv(2);
        return Lcompress(nil, v35);

v4:
    stack[0] = v35;
    goto v39;

v39:
    v35 = stack[0];
    if (v35 == nil) goto v40;
    v35 = stack[0];
    v35 = qcar(v35);
    v37 = v35;
    v36 = v37;
    v35 = elt(env, 2); /* !/ */
    if (v36 == v35) goto v41;
    v36 = v37;
    v35 = elt(env, 4); /* !- */
    if (v36 == v35) goto v42;
    v36 = v37;
    v35 = elt(env, 5); /* !; */
    if (v36 == v35) goto v43;
    v36 = v37;
    v35 = elt(env, 6); /* !. */
    v35 = (v36 == v35 ? lisp_true : nil);
    goto v44;

v44:
    if (v35 == nil) goto v45;
    v36 = v37;
    v35 = elt(env, 7); /* !! */
    v37 = v38;
    v35 = list2star(v36, v35, v37);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    v38 = v35;
    goto v47;

v47:
    v35 = stack[0];
    v35 = qcdr(v35);
    stack[0] = v35;
    goto v39;

v45:
    v35 = v37;
    v36 = v38;
    v35 = cons(v35, v36);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    v38 = v35;
    goto v47;

v43:
    v35 = qvalue(elt(env, 3)); /* t */
    goto v44;

v42:
    v35 = qvalue(elt(env, 3)); /* t */
    goto v44;

v41:
    v35 = qvalue(elt(env, 3)); /* t */
    goto v44;

v40:
    v35 = v38;
    v35 = Lnreverse(nil, v35);
    env = stack[-1];
    v35 = Lcompress(nil, v35);
    nil = C_nil;
    if (exception_pending()) goto v46;
        popv(2);
        return Lintern(nil, v35);
/* error exit handlers */
v46:
    popv(2);
    return nil;
}



/* Code for noncomp1 */

static Lisp_Object CC_noncomp1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v17, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomp1");
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
    v17 = v0;
/* end of prologue */
    v48 = v17;
    v48 = Lconsp(nil, v48);
    env = stack[0];
    if (v48 == nil) goto v6;
    v48 = v17;
    v48 = qcar(v48);
    v48 = Lconsp(nil, v48);
    env = stack[0];
    if (v48 == nil) goto v50;
    v48 = qvalue(elt(env, 2)); /* !*ncmp */
    if (v48 == nil) goto v40;
    v48 = v17;
    {
        popv(1);
        fn = elt(env, 5); /* noncomfp1 */
        return (*qfn1(fn))(qenv(fn), v48);
    }

v40:
    v48 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v48); }

v50:
    v48 = v17;
    v49 = qcar(v48);
    v48 = elt(env, 3); /* taylor!* */
    if (v49 == v48) goto v51;
    v48 = v17;
    v48 = qcar(v48);
    if (!symbolp(v48)) v48 = nil;
    else { v48 = qfastgets(v48);
           if (v48 != nil) { v48 = elt(v48, 0); /* noncom */
#ifdef RECORD_GET
             if (v48 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v48 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v48 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v48 == SPID_NOPROP) v48 = nil; else v48 = lisp_true; }}
#endif
    if (v48 == nil) goto v8;
    v48 = qvalue(elt(env, 4)); /* t */
    { popv(1); return onevalue(v48); }

v8:
    v48 = v17;
    v48 = qcdr(v48);
    {
        popv(1);
        fn = elt(env, 6); /* noncomlistp */
        return (*qfn1(fn))(qenv(fn), v48);
    }

v51:
    v48 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v48); }

v6:
    v48 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v48); }
}



/* Code for ps!:order */

static Lisp_Object CC_psTorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v48, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:order");
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
    v48 = v0;
/* end of prologue */
    v54 = v48;
    if (!consp(v54)) goto v55;
    v54 = v48;
    v17 = qcar(v54);
    v54 = elt(env, 2); /* !:ps!: */
    if (v17 == v54) goto v56;
    v54 = v48;
    v17 = qcar(v54);
    v54 = elt(env, 3); /* dname */
    v54 = get(v17, v54);
    env = stack[0];
    goto v57;

v57:
    if (v54 == nil) goto v58;
    v54 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v54); }

v58:
    v54 = (Lisp_Object)1; /* 0 */
    {
        popv(1);
        fn = elt(env, 5); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v48, v54);
    }

v56:
    v54 = qvalue(elt(env, 4)); /* nil */
    goto v57;

v55:
    v54 = qvalue(elt(env, 1)); /* t */
    goto v57;
}



/* Code for !:zerop */

static Lisp_Object CC_Tzerop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v9, v52;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :zerop");
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
    v52 = v0;
/* end of prologue */
    v8 = v52;
    if (v8 == nil) goto v55;
    v9 = v52;
    v8 = (Lisp_Object)1; /* 0 */
    v8 = (v9 == v8 ? lisp_true : nil);
    goto v57;

v57:
    if (v8 == nil) goto v5;
    v8 = qvalue(elt(env, 1)); /* t */
    return onevalue(v8);

v5:
    v8 = v52;
    if (!consp(v8)) goto v62;
    v8 = v52;
    v9 = qcar(v8);
    v8 = elt(env, 3); /* zerop */
    v8 = get(v9, v8);
    v9 = v52;
        return Lapply1(nil, v8, v9);

v62:
    v8 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v8);

v55:
    v8 = qvalue(elt(env, 1)); /* t */
    goto v57;
}



/* Code for retimes */

static Lisp_Object CC_retimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for retimes");
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
    v8 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*bool */
    qvalue(elt(env, 1)) = nil; /* !*bool */
    fn = elt(env, 4); /* retimes1 */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-1];
    v9 = v8;
    if (v9 == nil) goto v64;
    v9 = v8;
    v9 = qcdr(v9);
    if (v9 == nil) goto v53;
    v9 = elt(env, 2); /* times */
    v8 = cons(v9, v8);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-1];
    goto v55;

v55:
    v9 = qvalue(elt(env, 1)); /* !*bool */
    if (v9 == nil) goto v6;
    v9 = elt(env, 3); /* minus */
    v8 = list2(v9, v8);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-1];
    goto v6;

v6:
    qvalue(elt(env, 1)) = stack[0]; /* !*bool */
    { popv(2); return onevalue(v8); }

v53:
    v8 = qcar(v8);
    goto v55;

v64:
    v8 = (Lisp_Object)17; /* 1 */
    goto v55;
/* error exit handlers */
v42:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*bool */
    popv(2);
    return nil;
}



/* Code for bczero!? */

static Lisp_Object CC_bczeroW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v65;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bczero?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v61 = v0;
/* end of prologue */
    v65 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v65 == nil) goto v66;
    v65 = v61;
    v61 = (Lisp_Object)1; /* 0 */
        return Leqn(nil, v65, v61);

v66:
    v61 = qcar(v61);
    v61 = (v61 == nil ? lisp_true : nil);
    return onevalue(v61);
}



/* Code for rd!:zerop */

static Lisp_Object CC_rdTzerop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v51;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:zerop");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v62 = v0;
/* end of prologue */
    v51 = v62;
    v51 = qcdr(v51);
    if (!consp(v51)) goto v6;
    v62 = qcdr(v62);
    v51 = qcar(v62);
    v62 = (Lisp_Object)1; /* 0 */
    v62 = (v51 == v62 ? lisp_true : nil);
    return onevalue(v62);

v6:
    v62 = qcdr(v62);
        return Lzerop(nil, v62);
}



/* Code for evzero!? */

static Lisp_Object CC_evzeroW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v47, v68;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evzero?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v47 = v0;
/* end of prologue */

v69:
    v67 = v47;
    if (v67 == nil) goto v6;
    v67 = v47;
    v68 = qcar(v67);
    v67 = (Lisp_Object)1; /* 0 */
    if (v68 == v67) goto v15;
    v67 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v67);

v15:
    v67 = v47;
    v67 = qcdr(v67);
    v47 = v67;
    goto v69;

v6:
    v67 = qvalue(elt(env, 1)); /* t */
    return onevalue(v67);
}



/* Code for factorordp */

static Lisp_Object CC_factorordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v50, v22, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for factorordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v22 = v1;
    v67 = v0;
/* end of prologue */
    v50 = v67;
    v53 = v22;
    if (v50 == v53) goto v5;
    v53 = v67;
    v50 = v22;
    {
        fn = elt(env, 2); /* worderp */
        return (*qfn2(fn))(qenv(fn), v53, v50);
    }

v5:
    v53 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v53);
}



/* Code for mtchp */

static Lisp_Object MS_CDECL CC_mtchp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v19, Lisp_Object v7,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v82, v83, v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "mtchp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mtchp");
#endif
    if (stack >= stacklimit)
    {
        push5(v6,v7,v19,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v19,v7,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    v81 = v7;
    stack[-1] = v19;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v84 = stack[-3];
    v83 = stack[-2];
    v82 = v81;
    v81 = stack[0];
    fn = elt(env, 2); /* mtchp1 */
    v81 = (*qfnn(fn))(qenv(fn), 4, v84, v83, v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    stack[-4] = v81;
    goto v64;

v64:
    v81 = stack[-4];
    if (v81 == nil) goto v22;
    v81 = stack[-4];
    v82 = qcar(v81);
    v81 = stack[0];
    v81 = Lsubla(nil, v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    fn = elt(env, 3); /* eval */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    if (v81 == nil) goto v50;
    v81 = stack[-3];
    stack[0] = qcdr(v81);
    v81 = stack[-4];
    v82 = qcar(v81);
    v81 = stack[-2];
    v81 = qcdr(v81);
    v81 = Lsubla(nil, v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v81 = Ldivide(nil, stack[0], v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    stack[-2] = v81;
    v81 = stack[-4];
    v82 = qcar(v81);
    v81 = stack[-1];
    v81 = Lsubla(nil, v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    fn = elt(env, 4); /* simp */
    v82 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v81 = stack[-2];
    v81 = qcar(v81);
    fn = elt(env, 5); /* exptsq */
    v81 = (*qfn2(fn))(qenv(fn), v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    stack[-1] = v81;
    v81 = stack[-2];
    v82 = qcdr(v81);
    v81 = (Lisp_Object)1; /* 0 */
    if (v82 == v81) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v81 = stack[-3];
    v83 = qcar(v81);
    v81 = stack[-2];
    v82 = qcdr(v81);
    v81 = (Lisp_Object)17; /* 1 */
    v81 = acons(v83, v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v82 = ncons(v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v81 = (Lisp_Object)17; /* 1 */
    v82 = cons(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v81 = stack[-1];
    fn = elt(env, 6); /* multsq */
    v81 = (*qfn2(fn))(qenv(fn), v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    stack[-1] = v81;
    { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }

v50:
    v81 = stack[-4];
    v81 = qcdr(v81);
    stack[-4] = v81;
    goto v64;

v22:
    v81 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v81); }
/* error exit handlers */
v85:
    popv(6);
    return nil;
}



/* Code for collectindices_reversed */

static Lisp_Object CC_collectindices_reversed(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for collectindices_reversed");
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
    v42 = stack[-1];
    if (!(!consp(v42))) goto v47;
    v42 = stack[-1];
    fn = elt(env, 2); /* isanindex */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v49;
    if (v42 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v54 = stack[-1];
    v42 = stack[0];
    popv(3);
    return cons(v54, v42);

v47:
    v42 = stack[-1];
    if (v42 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v42 = stack[-1];
    v54 = qcar(v42);
    v42 = stack[0];
    v42 = CC_collectindices_reversed(env, v54, v42);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    stack[0] = v42;
    v42 = stack[-1];
    v42 = qcdr(v42);
    stack[-1] = v42;
    goto v47;
/* error exit handlers */
v49:
    popv(3);
    return nil;
}



/* Code for getrmacro */

static Lisp_Object CC_getrmacro(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v42, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrmacro");
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
    v52 = stack[0];
    if (symbolp(v52)) goto v55;
    v52 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v52); }

v55:
    v52 = stack[0];
    fn = elt(env, 4); /* getd */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v54 = v52;
    if (v52 == nil) goto v47;
    v52 = v54;
    v42 = qcar(v52);
    v52 = elt(env, 2); /* macro */
    if (v42 == v52) { popv(2); return onevalue(v54); }
    else goto v47;

v47:
    v42 = stack[0];
    v52 = elt(env, 3); /* smacro */
    v52 = get(v42, v52);
    env = stack[-1];
    v54 = v52;
    if (v52 == nil) goto v58;
    v52 = elt(env, 3); /* smacro */
    v42 = v54;
    popv(2);
    return cons(v52, v42);

v58:
    v52 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v52); }
/* error exit handlers */
v17:
    popv(2);
    return nil;
}



/* Code for reval_without_mod */

static Lisp_Object CC_reval_without_mod(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v80, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval_without_mod");
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
    v62 = v0;
/* end of prologue */
    v80 = qvalue(elt(env, 1)); /* dmode!* */
    v65 = elt(env, 2); /* !:mod!: */
    if (v80 == v65) goto v6;
    v65 = v62;
    {
        popv(2);
        fn = elt(env, 4); /* reval */
        return (*qfn1(fn))(qenv(fn), v65);
    }

v6:
    v65 = qvalue(elt(env, 3)); /* nil */
    stack[0] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = v65; /* dmode!* */
    v65 = v62;
    fn = elt(env, 4); /* reval */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* dmode!* */
    { popv(2); return onevalue(v65); }
/* error exit handlers */
v53:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* dmode!* */
    popv(2);
    return nil;
}



/* Code for adddm */

static Lisp_Object CC_adddm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v92, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for adddm");
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
    v92 = v1;
    v25 = v0;
/* end of prologue */
    v91 = v25;
    if (!consp(v91)) goto v64;
    v91 = qvalue(elt(env, 1)); /* nil */
    goto v55;

v55:
    if (v91 == nil) goto v93;
    v91 = v25;
    v91 = plus2(v91, v92);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[0];
    v25 = v91;
    v91 = qvalue(elt(env, 2)); /* dmode!* */
    if (v91 == nil) goto v26;
    v92 = qvalue(elt(env, 2)); /* dmode!* */
    v91 = elt(env, 4); /* convert */
    v91 = Lflagp(nil, v92, v91);
    env = stack[0];
    v91 = (v91 == nil ? lisp_true : nil);
    goto v94;

v94:
    if (v91 == nil) goto v95;
    v91 = v25;
    v91 = (Lisp_Object)zerop(v91);
    v91 = v91 ? lisp_true : nil;
    env = stack[0];
    if (v91 == nil) { popv(1); return onevalue(v25); }
    v91 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v91); }

v95:
    v92 = qvalue(elt(env, 2)); /* dmode!* */
    v91 = elt(env, 5); /* i2d */
    v91 = get(v92, v91);
    env = stack[0];
    v92 = v25;
    v91 = Lapply1(nil, v91, v92);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 7); /* int!-equiv!-chk */
        return (*qfn1(fn))(qenv(fn), v91);
    }

v26:
    v91 = qvalue(elt(env, 3)); /* t */
    goto v94;

v93:
    v91 = elt(env, 6); /* plus */
    {
        popv(1);
        fn = elt(env, 8); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v25, v92, v91);
    }

v64:
    v91 = v92;
    v91 = (consp(v91) ? nil : lisp_true);
    goto v55;
/* error exit handlers */
v23:
    popv(1);
    return nil;
}



/* Code for multf */

static Lisp_Object CC_multf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v150, v151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multf");
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
    goto v57;

v57:
    v149 = stack[-2];
    if (v149 == nil) goto v34;
    v149 = stack[-1];
    v149 = (v149 == nil ? lisp_true : nil);
    goto v14;

v14:
    if (v149 == nil) goto v53;
    v149 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v149); }

v53:
    v150 = stack[-2];
    v149 = (Lisp_Object)17; /* 1 */
    if (v150 == v149) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v150 = stack[-1];
    v149 = (Lisp_Object)17; /* 1 */
    if (v150 == v149) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v149 = stack[-2];
    if (!consp(v149)) goto v52;
    v149 = stack[-2];
    v149 = qcar(v149);
    v149 = (consp(v149) ? nil : lisp_true);
    goto v9;

v9:
    if (v149 == nil) goto v58;
    v150 = stack[-2];
    v149 = stack[-1];
    {
        popv(5);
        fn = elt(env, 11); /* multd */
        return (*qfn2(fn))(qenv(fn), v150, v149);
    }

v58:
    v149 = stack[-1];
    if (!consp(v149)) goto v152;
    v149 = stack[-1];
    v149 = qcar(v149);
    v149 = (consp(v149) ? nil : lisp_true);
    goto v95;

v95:
    if (v149 == nil) goto v3;
    v150 = stack[-1];
    v149 = stack[-2];
    {
        popv(5);
        fn = elt(env, 11); /* multd */
        return (*qfn2(fn))(qenv(fn), v150, v149);
    }

v3:
    v149 = qvalue(elt(env, 3)); /* !*exp */
    if (!(v149 == nil)) goto v64;
    v149 = qvalue(elt(env, 4)); /* ncmp!* */
    if (!(v149 == nil)) goto v64;
    v149 = qvalue(elt(env, 5)); /* wtl!* */
    if (!(v149 == nil)) goto v64;
    v149 = stack[-3];
    if (!(v149 == nil)) goto v64;
    v149 = stack[-2];
    fn = elt(env, 12); /* mkprod */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    stack[-2] = v149;
    v149 = stack[-1];
    fn = elt(env, 12); /* mkprod */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    stack[-1] = v149;
    v149 = qvalue(elt(env, 1)); /* t */
    stack[-3] = v149;
    goto v57;

v64:
    v149 = stack[-2];
    v149 = qcar(v149);
    v149 = qcar(v149);
    v149 = qcar(v149);
    stack[-3] = v149;
    v149 = stack[-1];
    v149 = qcar(v149);
    v149 = qcar(v149);
    v149 = qcar(v149);
    stack[0] = v149;
    v149 = qvalue(elt(env, 6)); /* !*ncmp */
    if (v149 == nil) goto v154;
    v149 = stack[-1];
    fn = elt(env, 13); /* noncomfp1 */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    if (v149 == nil) goto v154;
    v149 = qvalue(elt(env, 6)); /* !*ncmp */
    if (v149 == nil) goto v155;
    v149 = stack[-3];
    fn = elt(env, 14); /* noncomp1 */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    if (!(v149 == nil)) goto v156;

v155:
    v149 = qvalue(elt(env, 7)); /* !*!*processed */
    if (!(v149 == nil)) goto v154;

v156:
    v150 = stack[-2];
    v149 = stack[-1];
    {
        popv(5);
        fn = elt(env, 15); /* multfnc */
        return (*qfn2(fn))(qenv(fn), v150, v149);
    }

v154:
    v150 = stack[-3];
    v149 = stack[0];
    if (v150 == v149) goto v157;
    v150 = stack[-3];
    v149 = stack[0];
    fn = elt(env, 16); /* ordop */
    v149 = (*qfn2(fn))(qenv(fn), v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    if (v149 == nil) goto v158;
    v149 = stack[-2];
    v149 = qcar(v149);
    v150 = qcdr(v149);
    v149 = stack[-1];
    v149 = CC_multf(env, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    stack[-3] = v149;
    v149 = stack[-2];
    v150 = qcdr(v149);
    v149 = stack[-1];
    v149 = CC_multf(env, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    stack[0] = v149;
    v149 = stack[-3];
    if (v149 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v149 = stack[-2];
    v149 = qcar(v149);
    v151 = qcar(v149);
    v150 = stack[-3];
    v149 = stack[0];
    popv(5);
    return acons(v151, v150, v149);

v158:
    v150 = stack[-2];
    v149 = stack[-1];
    v149 = qcar(v149);
    v149 = qcdr(v149);
    v149 = CC_multf(env, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    stack[-3] = v149;
    v150 = stack[-2];
    v149 = stack[-1];
    v149 = qcdr(v149);
    v149 = CC_multf(env, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    stack[0] = v149;
    v149 = stack[-3];
    if (v149 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v149 = stack[-1];
    v149 = qcar(v149);
    v151 = qcar(v149);
    v150 = stack[-3];
    v149 = stack[0];
    popv(5);
    return acons(v151, v150, v149);

v157:
    v149 = stack[-2];
    v149 = qcar(v149);
    v149 = qcar(v149);
    v149 = qcdr(v149);
    v149 = integerp(v149);
    if (v149 == nil) goto v159;
    v149 = stack[-1];
    v149 = qcar(v149);
    v149 = qcar(v149);
    v149 = qcdr(v149);
    v149 = integerp(v149);
    v149 = (v149 == nil ? lisp_true : nil);
    goto v160;

v160:
    if (v149 == nil) goto v161;
    stack[0] = stack[-3];
    v151 = elt(env, 8); /* plus */
    v149 = stack[-2];
    v149 = qcar(v149);
    v149 = qcar(v149);
    v150 = qcdr(v149);
    v149 = stack[-1];
    v149 = qcar(v149);
    v149 = qcar(v149);
    v149 = qcdr(v149);
    v149 = list3(v151, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    fn = elt(env, 17); /* reval */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    v149 = cons(stack[0], v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    stack[-3] = v149;
    goto v162;

v162:
    v149 = stack[-2];
    v150 = qcdr(v149);
    v149 = stack[-1];
    stack[0] = CC_multf(env, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    v149 = stack[-2];
    v149 = qcar(v149);
    v150 = ncons(v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    v149 = stack[-1];
    v149 = qcdr(v149);
    v149 = CC_multf(env, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    fn = elt(env, 18); /* addf */
    v149 = (*qfn2(fn))(qenv(fn), stack[0], v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    stack[0] = v149;
    v149 = stack[-3];
    if (v149 == nil) goto v163;
    v149 = stack[-2];
    v149 = qcar(v149);
    v150 = qcdr(v149);
    v149 = stack[-1];
    v149 = qcar(v149);
    v149 = qcdr(v149);
    v149 = CC_multf(env, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    stack[-2] = v149;
    v149 = (v149 == nil ? lisp_true : nil);
    goto v164;

v164:
    if (v149 == nil) goto v165;
    v149 = qvalue(elt(env, 1)); /* t */
    qvalue(elt(env, 9)) = v149; /* !*asymp!* */
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v165:
    v150 = stack[-3];
    v149 = (Lisp_Object)17; /* 1 */
    if (v150 == v149) goto v166;
    v149 = qvalue(elt(env, 10)); /* !*mcd */
    if (v149 == nil) goto v167;
    v151 = stack[-3];
    v150 = stack[-2];
    v149 = stack[0];
    popv(5);
    return acons(v151, v150, v149);

v167:
    v150 = stack[-3];
    v149 = stack[-2];
    v149 = cons(v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    v150 = ncons(v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    v149 = stack[0];
    {
        popv(5);
        fn = elt(env, 18); /* addf */
        return (*qfn2(fn))(qenv(fn), v150, v149);
    }

v166:
    v150 = stack[-2];
    v149 = stack[0];
    {
        popv(5);
        fn = elt(env, 18); /* addf */
        return (*qfn2(fn))(qenv(fn), v150, v149);
    }

v163:
    v149 = qvalue(elt(env, 1)); /* t */
    goto v164;

v161:
    stack[0] = stack[-3];
    v149 = stack[-2];
    v149 = qcar(v149);
    v149 = qcar(v149);
    v150 = qcdr(v149);
    v149 = stack[-1];
    v149 = qcar(v149);
    v149 = qcar(v149);
    v149 = qcdr(v149);
    v149 = plus2(v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    fn = elt(env, 19); /* mkspm */
    v149 = (*qfn2(fn))(qenv(fn), stack[0], v149);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    stack[-3] = v149;
    goto v162;

v159:
    v149 = qvalue(elt(env, 1)); /* t */
    goto v160;

v152:
    v149 = qvalue(elt(env, 1)); /* t */
    goto v95;

v52:
    v149 = qvalue(elt(env, 1)); /* t */
    goto v9;

v34:
    v149 = qvalue(elt(env, 1)); /* t */
    goto v14;
/* error exit handlers */
v153:
    popv(5);
    return nil;
}



/* Code for ring_ecart */

static Lisp_Object CC_ring_ecart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ring_ecart");
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
    v86 = v0;
/* end of prologue */
    v15 = v86;
    v86 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 1); /* pnth */
    v86 = (*qfn2(fn))(qenv(fn), v15, v86);
    errexit();
    v86 = qcar(v86);
    return onevalue(v86);
}



/* Code for reduce_pv */

static Lisp_Object CC_reduce_pv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v66, v40;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce_pv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v34 = v1;
    v66 = v0;
/* end of prologue */
    v40 = v66;
    v66 = v34;
    v34 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* reduce_pv0 */
        return (*qfnn(fn))(qenv(fn), 3, v40, v66, v34);
    }
}



/* Code for rnonep!: */

static Lisp_Object CC_rnonepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v47, v68;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnonep:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v68 = v0;
/* end of prologue */
    v67 = v68;
    v67 = qcdr(v67);
    v47 = qcar(v67);
    v67 = (Lisp_Object)17; /* 1 */
    if (v47 == v67) goto v66;
    v67 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v67);

v66:
    v67 = v68;
    v67 = qcdr(v67);
    v47 = qcdr(v67);
    v67 = (Lisp_Object)17; /* 1 */
    v67 = (v47 == v67 ? lisp_true : nil);
    return onevalue(v67);
}



/* Code for general!-modular!-plus */

static Lisp_Object CC_generalKmodularKplus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v10;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-plus");
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
    v56 = v1;
    v10 = v0;
/* end of prologue */
    v56 = plus2(v10, v56);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-1];
    stack[0] = v56;
    v10 = stack[0];
    v56 = qvalue(elt(env, 1)); /* current!-modulus */
    v56 = (Lisp_Object)geq2(v10, v56);
    nil = C_nil;
    if (exception_pending()) goto v168;
    v56 = v56 ? lisp_true : nil;
    env = stack[-1];
    if (v56 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v10 = stack[0];
    v56 = qvalue(elt(env, 1)); /* current!-modulus */
    v56 = difference2(v10, v56);
    nil = C_nil;
    if (exception_pending()) goto v168;
    stack[0] = v56;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v168:
    popv(2);
    return nil;
}



/* Code for !*d2n */

static Lisp_Object CC_Hd2n(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *d2n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v86 = v0;
/* end of prologue */
    v15 = v86;
    if (!(v15 == nil)) return onevalue(v86);
    v86 = (Lisp_Object)1; /* 0 */
    return onevalue(v86);
}



/* Code for add2calls */

static Lisp_Object CC_add2calls(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v169;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add2calls");
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
    v169 = stack[0];
    v31 = elt(env, 1); /* cinthis */
    v31 = Lflagp(nil, v169, v31);
    env = stack[-1];
    if (v31 == nil) goto v60;
    v31 = qvalue(elt(env, 5)); /* nil */
    { popv(2); return onevalue(v31); }

v60:
    v169 = stack[0];
    v31 = elt(env, 2); /* nolist */
    v31 = Lflagp(nil, v169, v31);
    env = stack[-1];
    if (v31 == nil) goto v11;
    v169 = stack[0];
    v31 = qvalue(elt(env, 3)); /* xseen!* */
    v31 = cons(v169, v31);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-1];
    qvalue(elt(env, 3)) = v31; /* xseen!* */
    goto v8;

v8:
    v31 = stack[0];
    v31 = ncons(v31);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-1];
    v169 = elt(env, 1); /* cinthis */
        popv(2);
        return Lflag(nil, v31, v169);

v11:
    v169 = stack[0];
    v31 = qvalue(elt(env, 4)); /* calls!* */
    v31 = cons(v169, v31);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-1];
    qvalue(elt(env, 4)) = v31; /* calls!* */
    goto v8;
/* error exit handlers */
v170:
    popv(2);
    return nil;
}



/* Code for cl_atmlc */

static Lisp_Object CC_cl_atmlc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_atmlc");
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
    v86 = v0;
/* end of prologue */
    v15 = v86;
    v86 = (Lisp_Object)17; /* 1 */
    v86 = cons(v15, v86);
    errexit();
    return ncons(v86);
}



/* Code for monomisdivisibleby */

static Lisp_Object CC_monomisdivisibleby(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v16, v173;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monomisdivisibleby");
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
    v173 = v1;
    v27 = v0;
/* end of prologue */
    v16 = v27;
    v27 = (Lisp_Object)17; /* 1 */
    v27 = *(Lisp_Object *)((char *)v16 + (CELL-TAG_VECTOR) + ((int32_t)v27/(16/CELL)));
    stack[-1] = v27;
    v16 = v173;
    v27 = (Lisp_Object)17; /* 1 */
    v27 = *(Lisp_Object *)((char *)v16 + (CELL-TAG_VECTOR) + ((int32_t)v27/(16/CELL)));
    stack[0] = v27;
    goto v53;

v53:
    v27 = stack[-1];
    v27 = qcar(v27);
    if (v27 == nil) goto v51;
    v27 = stack[0];
    v27 = qcar(v27);
    if (v27 == nil) goto v51;
    v27 = stack[-1];
    v16 = qcar(v27);
    v27 = stack[0];
    v27 = qcar(v27);
    if (equal(v16, v27)) goto v174;
    v27 = stack[-1];
    v16 = qcar(v27);
    v27 = stack[0];
    v27 = qcar(v27);
    v27 = (Lisp_Object)greaterp2(v16, v27);
    nil = C_nil;
    if (exception_pending()) goto v147;
    v27 = v27 ? lisp_true : nil;
    env = stack[-2];
    if (v27 == nil) goto v29;
    v27 = stack[-1];
    v27 = qcdr(v27);
    stack[-1] = v27;
    goto v53;

v29:
    v27 = qvalue(elt(env, 1)); /* nil */
    v27 = ncons(v27);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-2];
    stack[-1] = v27;
    goto v53;

v174:
    v27 = stack[-1];
    v27 = qcdr(v27);
    stack[-1] = v27;
    v27 = stack[0];
    v27 = qcdr(v27);
    stack[0] = v27;
    goto v53;

v51:
    v27 = stack[0];
    v27 = qcar(v27);
    v27 = (v27 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v27); }
/* error exit handlers */
v147:
    popv(3);
    return nil;
}



/* Code for split_form */

static Lisp_Object CC_split_form(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split_form");
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
    v175 = v1;
    v60 = v0;
/* end of prologue */
    stack[-2] = v60;
    stack[-1] = v175;
    stack[0] = (Lisp_Object)17; /* 1 */
    v175 = qvalue(elt(env, 1)); /* nil */
    v175 = ncons(v175);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    {
        Lisp_Object v51 = stack[-2];
        Lisp_Object v53 = stack[-1];
        Lisp_Object v50 = stack[0];
        popv(4);
        fn = elt(env, 2); /* split_f */
        return (*qfnn(fn))(qenv(fn), 4, v51, v53, v50, v175);
    }
/* error exit handlers */
v62:
    popv(4);
    return nil;
}



/* Code for ofsf_posdefp */

static Lisp_Object CC_ofsf_posdefp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_posdefp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v34 = v0;
/* end of prologue */
    v14 = qvalue(elt(env, 1)); /* !*rlpos */
    if (v14 == nil) goto v64;
    v14 = v34;
    {
        fn = elt(env, 2); /* ofsf_posdefp!-pos */
        return (*qfn1(fn))(qenv(fn), v14);
    }

v64:
    v14 = v34;
    {
        fn = elt(env, 3); /* sfto_tsqsumf */
        return (*qfn1(fn))(qenv(fn), v14);
    }
}



/* Code for tayexp!-greaterp */

static Lisp_Object CC_tayexpKgreaterp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-greaterp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v1;
    v86 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* tayexp!-lessp */
        return (*qfn2(fn))(qenv(fn), v15, v86);
    }
}



/* Code for mri_floorp */

static Lisp_Object CC_mri_floorp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v68, v94;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_floorp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v68 = v0;
/* end of prologue */

v69:
    v47 = v68;
    if (v47 == nil) goto v6;
    v47 = v68;
    v94 = qcar(v47);
    v47 = elt(env, 2); /* floor */
    if (!consp(v94)) goto v51;
    v94 = qcar(v94);
    if (!(v94 == v47)) goto v51;
    v47 = qvalue(elt(env, 3)); /* t */
    return onevalue(v47);

v51:
    v47 = v68;
    v47 = qcdr(v47);
    v68 = v47;
    goto v69;

v6:
    v47 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v47);
}



/* Code for qqe_qopaddp */

static Lisp_Object CC_qqe_qopaddp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v40;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_qopaddp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v66 = v0;
/* end of prologue */
    v40 = v66;
    v66 = elt(env, 1); /* (ladd radd) */
    v66 = Lmemq(nil, v40, v66);
    if (v66 == nil) goto v5;
    v66 = qvalue(elt(env, 2)); /* t */
    return onevalue(v66);

v5:
    v66 = nil;
    return onevalue(v66);
}



/* Code for sort */

static Lisp_Object CC_sort(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sort");
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
    v175 = v0;
/* end of prologue */
    v60 = v175;
    v175 = qvalue(elt(env, 1)); /* nil */
    v60 = Lappend(nil, v60, v175);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v175 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* stable!-sortip */
        return (*qfn2(fn))(qenv(fn), v60, v175);
    }
/* error exit handlers */
v65:
    popv(2);
    return nil;
}



/* Code for ibalp_cequal */

static Lisp_Object CC_ibalp_cequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_cequal");
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
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v185 = stack[-5];
    v185 = qcar(v185);
    stack[-3] = v185;
    v185 = stack[-3];
    if (v185 == nil) goto v60;
    v185 = stack[-3];
    v185 = qcar(v185);
    v185 = qcar(v185);
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-7];
    stack[-1] = v185;
    stack[-2] = v185;
    goto v34;

v34:
    v185 = stack[-3];
    v185 = qcdr(v185);
    stack[-3] = v185;
    v185 = stack[-3];
    if (v185 == nil) goto v44;
    stack[0] = stack[-1];
    v185 = stack[-3];
    v185 = qcar(v185);
    v185 = qcar(v185);
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-7];
    v185 = Lrplacd(nil, stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-7];
    v185 = stack[-1];
    v185 = qcdr(v185);
    stack[-1] = v185;
    goto v34;

v44:
    v185 = stack[-2];
    goto v14;

v14:
    stack[-6] = v185;
    v185 = stack[-4];
    v185 = qcar(v185);
    stack[-3] = v185;
    v185 = stack[-3];
    if (v185 == nil) goto v43;
    v185 = stack[-3];
    v185 = qcar(v185);
    v185 = qcar(v185);
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-7];
    stack[-1] = v185;
    stack[-2] = v185;
    goto v169;

v169:
    v185 = stack[-3];
    v185 = qcdr(v185);
    stack[-3] = v185;
    v185 = stack[-3];
    if (v185 == nil) goto v188;
    stack[0] = stack[-1];
    v185 = stack[-3];
    v185 = qcar(v185);
    v185 = qcar(v185);
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-7];
    v185 = Lrplacd(nil, stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-7];
    v185 = stack[-1];
    v185 = qcdr(v185);
    stack[-1] = v185;
    goto v169;

v188:
    v185 = stack[-2];
    goto v189;

v189:
    v186 = stack[-6];
    fn = elt(env, 2); /* lto_setequalq */
    v185 = (*qfn2(fn))(qenv(fn), v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-7];
    if (v185 == nil) goto v190;
    v185 = stack[-5];
    v185 = qcdr(v185);
    v185 = qcar(v185);
    stack[-3] = v185;
    v185 = stack[-3];
    if (v185 == nil) goto v73;
    v185 = stack[-3];
    v185 = qcar(v185);
    v185 = qcar(v185);
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-7];
    stack[-1] = v185;
    stack[-2] = v185;
    goto v191;

v191:
    v185 = stack[-3];
    v185 = qcdr(v185);
    stack[-3] = v185;
    v185 = stack[-3];
    if (v185 == nil) goto v192;
    stack[0] = stack[-1];
    v185 = stack[-3];
    v185 = qcar(v185);
    v185 = qcar(v185);
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-7];
    v185 = Lrplacd(nil, stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-7];
    v185 = stack[-1];
    v185 = qcdr(v185);
    stack[-1] = v185;
    goto v191;

v192:
    v185 = stack[-2];
    goto v38;

v38:
    stack[-3] = v185;
    v185 = stack[-4];
    v185 = qcdr(v185);
    v185 = qcar(v185);
    stack[-4] = v185;
    v185 = stack[-4];
    if (v185 == nil) goto v193;
    v185 = stack[-4];
    v185 = qcar(v185);
    v185 = qcar(v185);
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-7];
    stack[-1] = v185;
    stack[-2] = v185;
    goto v194;

v194:
    v185 = stack[-4];
    v185 = qcdr(v185);
    stack[-4] = v185;
    v185 = stack[-4];
    if (v185 == nil) goto v195;
    stack[0] = stack[-1];
    v185 = stack[-4];
    v185 = qcar(v185);
    v185 = qcar(v185);
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-7];
    v185 = Lrplacd(nil, stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-7];
    v185 = stack[-1];
    v185 = qcdr(v185);
    stack[-1] = v185;
    goto v194;

v195:
    v185 = stack[-2];
    goto v196;

v196:
    v186 = stack[-3];
    {
        popv(8);
        fn = elt(env, 2); /* lto_setequalq */
        return (*qfn2(fn))(qenv(fn), v186, v185);
    }

v193:
    v185 = qvalue(elt(env, 1)); /* nil */
    goto v196;

v73:
    v185 = qvalue(elt(env, 1)); /* nil */
    goto v38;

v190:
    v185 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v185); }

v43:
    v185 = qvalue(elt(env, 1)); /* nil */
    goto v189;

v60:
    v185 = qvalue(elt(env, 1)); /* nil */
    goto v14;
/* error exit handlers */
v187:
    popv(8);
    return nil;
}



/* Code for get_token */

static Lisp_Object MS_CDECL CC_get_token(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v11;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "get_token");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_token");
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
    v10 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v10;
    goto v15;

v15:
    v11 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-1];
    qvalue(elt(env, 2)) = v11; /* ch */
    v10 = elt(env, 3); /* !> */
    if (v11 == v10) goto v47;
    v11 = qvalue(elt(env, 2)); /* ch */
    v10 = stack[0];
    v10 = cons(v11, v10);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-1];
    stack[0] = v10;
    goto v15;

v47:
    v11 = elt(env, 4); /* !$ */
    v10 = stack[0];
    popv(2);
    return cons(v11, v10);
/* error exit handlers */
v174:
    popv(2);
    return nil;
}



/* Code for ps!:last!-term */

static Lisp_Object CC_psTlastKterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v48, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:last-term");
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
    v48 = v0;
/* end of prologue */
    v54 = v48;
    if (!consp(v54)) goto v55;
    v54 = v48;
    v17 = qcar(v54);
    v54 = elt(env, 2); /* !:ps!: */
    if (v17 == v54) goto v56;
    v54 = v48;
    v17 = qcar(v54);
    v54 = elt(env, 3); /* dname */
    v54 = get(v17, v54);
    env = stack[0];
    goto v57;

v57:
    if (v54 == nil) goto v58;
    v54 = qvalue(elt(env, 5)); /* ps!:max!-order */
    { popv(1); return onevalue(v54); }

v58:
    v54 = (Lisp_Object)17; /* 1 */
    {
        popv(1);
        fn = elt(env, 6); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v48, v54);
    }

v56:
    v54 = qvalue(elt(env, 4)); /* nil */
    goto v57;

v55:
    v54 = qvalue(elt(env, 1)); /* t */
    goto v57;
}



/* Code for dm!-abs */

static Lisp_Object CC_dmKabs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-abs");
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
    v10 = stack[0];
    if (!consp(v10)) goto v55;
    v10 = stack[0];
    v11 = qcar(v10);
    v10 = elt(env, 1); /* minusp */
    v11 = get(v11, v10);
    env = stack[-1];
    v10 = stack[0];
    v10 = Lapply1(nil, v11, v10);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-1];
    goto v57;

v57:
    if (v10 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v10 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* dm!-minus */
        return (*qfn1(fn))(qenv(fn), v10);
    }

v55:
    v10 = stack[0];
    v10 = Lminusp(nil, v10);
    env = stack[-1];
    goto v57;
/* error exit handlers */
v174:
    popv(2);
    return nil;
}



/* Code for mval */

static Lisp_Object CC_mval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v7;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mval");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    return onevalue(v7);
}



/* Code for bcprod */

static Lisp_Object CC_bcprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v59, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcprod");
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
    v33 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v33 == nil) goto v62;
    v59 = stack[-1];
    v33 = stack[0];
    v33 = times2(v59, v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v33);
    }

v62:
    v58 = stack[-1];
    v59 = stack[0];
    v33 = elt(env, 2); /* times */
    fn = elt(env, 4); /* bcint2op */
    v33 = (*qfnn(fn))(qenv(fn), 3, v58, v59, v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    if (!(v33 == nil)) { popv(3); return onevalue(v33); }
    v59 = stack[-1];
    v33 = stack[0];
    fn = elt(env, 5); /* multsq */
    v33 = (*qfn2(fn))(qenv(fn), v59, v33);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); /* bccheckz */
        return (*qfn1(fn))(qenv(fn), v33);
    }
/* error exit handlers */
v52:
    popv(3);
    return nil;
}



/* Code for wedgepf2 */

static Lisp_Object CC_wedgepf2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgepf2");
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
    v43 = stack[-2];
    if (v43 == nil) goto v64;
    v43 = stack[-1];
    v43 = (v43 == nil ? lisp_true : nil);
    goto v55;

v55:
    if (v43 == nil) goto v22;
    v43 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v43); }

v22:
    v43 = stack[-2];
    v148 = qcar(v43);
    v43 = stack[-1];
    v43 = qcar(v43);
    fn = elt(env, 3); /* wedget2 */
    stack[-3] = (*qfn2(fn))(qenv(fn), v148, v43);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    v43 = stack[-2];
    v43 = qcar(v43);
    v148 = ncons(v43);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    v43 = stack[-1];
    v43 = qcdr(v43);
    stack[0] = CC_wedgepf2(env, v148, v43);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    v43 = stack[-2];
    v148 = qcdr(v43);
    v43 = stack[-1];
    v43 = CC_wedgepf2(env, v148, v43);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    fn = elt(env, 4); /* addpf */
    v43 = (*qfn2(fn))(qenv(fn), stack[0], v43);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    {
        Lisp_Object v28 = stack[-3];
        popv(5);
        fn = elt(env, 4); /* addpf */
        return (*qfn2(fn))(qenv(fn), v28, v43);
    }

v64:
    v43 = qvalue(elt(env, 1)); /* t */
    goto v55;
/* error exit handlers */
v152:
    popv(5);
    return nil;
}



/* Code for !:plus */

static Lisp_Object CC_Tplus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v148, v172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :plus");
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
    v148 = v1;
    v172 = v0;
/* end of prologue */
    v43 = v172;
    if (v43 == nil) { popv(1); return onevalue(v148); }
    v43 = v148;
    if (v43 == nil) { popv(1); return onevalue(v172); }
    v43 = v172;
    if (!consp(v43)) goto v39;
    v43 = qvalue(elt(env, 1)); /* nil */
    goto v40;

v40:
    if (v43 == nil) goto v31;
    v43 = v172;
    v43 = plus2(v43, v148);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[0];
    v172 = v43;
    v148 = v172;
    v43 = (Lisp_Object)1; /* 0 */
    if (!(v148 == v43)) { popv(1); return onevalue(v172); }
    v43 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v43); }

v31:
    v43 = elt(env, 2); /* plus */
    {
        popv(1);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v172, v148, v43);
    }

v39:
    v43 = v148;
    v43 = (consp(v43) ? nil : lisp_true);
    goto v40;
/* error exit handlers */
v3:
    popv(1);
    return nil;
}



/* Code for idlistp */

static Lisp_Object CC_idlistp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v94;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for idlistp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v68 = v0;
/* end of prologue */

v69:
    v94 = v68;
    if (v94 == nil) goto v6;
    v94 = v68;
    if (!consp(v94)) goto v22;
    v94 = v68;
    v94 = qcar(v94);
    if (symbolp(v94)) goto v80;
    v68 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v68);

v80:
    v68 = qcdr(v68);
    goto v69;

v22:
    v68 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v68);

v6:
    v68 = qvalue(elt(env, 1)); /* t */
    return onevalue(v68);
}



/* Code for macrochk */

static Lisp_Object CC_macrochk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v16, v173, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for macrochk");
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
    v27 = stack[-1];
    if (!consp(v27)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v27 = stack[-1];
    v27 = qcar(v27);
    fn = elt(env, 6); /* expdrmacro */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v16 = v27;
    if (v27 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v173 = stack[0];
    v27 = elt(env, 1); /* symbolic */
    if (v173 == v27) goto v65;
    v27 = stack[-1];
    v27 = qcar(v27);
    if (symbolp(v27)) goto v59;
    v27 = qvalue(elt(env, 3)); /* nil */
    goto v61;

v61:
    if (v27 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v27 = v16;
    v173 = qcar(v27);
    v27 = elt(env, 5); /* macrofn */
    v93 = get(v173, v27);
    v27 = v16;
    v173 = qcdr(v27);
    v27 = stack[-1];
    v16 = qcdr(v27);
    v27 = stack[-1];
    v27 = qcar(v27);
        popv(3);
        return Lapply3(nil, 4, v93, v173, v16, v27);

v59:
    v27 = stack[-1];
    v173 = qcar(v27);
    v27 = elt(env, 4); /* opfn */
    v27 = Lflagp(nil, v173, v27);
    env = stack[-2];
    goto v61;

v65:
    v27 = qvalue(elt(env, 2)); /* t */
    goto v61;
/* error exit handlers */
v87:
    popv(3);
    return nil;
}



/* Code for mo!=sprod */

static Lisp_Object CC_moMsprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v172, v3;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=sprod");
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
    v3 = nil;
    goto v57;

v57:
    v148 = stack[-1];
    if (v148 == nil) goto v40;
    v148 = stack[0];
    v148 = (v148 == nil ? lisp_true : nil);
    goto v66;

v66:
    if (v148 == nil) goto v68;
    v148 = (Lisp_Object)1; /* 0 */
    goto v64;

v64:
    v172 = v3;
    if (v172 == nil) { popv(3); return onevalue(v148); }
    v172 = v3;
    v172 = qcar(v172);
    v148 = (Lisp_Object)(int32_t)((int32_t)v172 + (int32_t)v148 - TAG_FIXNUM);
    v172 = v3;
    v172 = qcdr(v172);
    v3 = v172;
    goto v64;

v68:
    v148 = stack[-1];
    v172 = qcar(v148);
    v148 = stack[0];
    v148 = qcar(v148);
    v148 = fixnum_of_int((int32_t)(int_of_fixnum(v172) * int_of_fixnum(v148)));
    v172 = v3;
    v148 = cons(v148, v172);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    v3 = v148;
    v148 = stack[-1];
    v148 = qcdr(v148);
    stack[-1] = v148;
    v148 = stack[0];
    v148 = qcdr(v148);
    stack[0] = v148;
    goto v57;

v40:
    v148 = qvalue(elt(env, 1)); /* t */
    goto v66;
/* error exit handlers */
v152:
    popv(3);
    return nil;
}



/* Code for hasonevector */

static Lisp_Object CC_hasonevector(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for hasonevector");
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

v69:
    v60 = stack[0];
    if (v60 == nil) goto v6;
    v60 = stack[0];
    v60 = qcar(v60);
    fn = elt(env, 2); /* vecp */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    if (!(v60 == nil)) { popv(2); return onevalue(v60); }
    v60 = stack[0];
    v60 = qcdr(v60);
    stack[0] = v60;
    goto v69;

v6:
    v60 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v60); }
/* error exit handlers */
v65:
    popv(2);
    return nil;
}



/* Code for sieve_pv */

static Lisp_Object CC_sieve_pv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v66, v40;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sieve_pv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v34 = v1;
    v66 = v0;
/* end of prologue */
    v40 = v66;
    v66 = v34;
    v34 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* sieve_pv0 */
        return (*qfnn(fn))(qenv(fn), 3, v40, v66, v34);
    }
}



/* Code for modtimes!: */

static Lisp_Object CC_modtimesT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modtimes:");
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
    v34 = v1;
    v66 = v0;
/* end of prologue */
    v66 = qcdr(v66);
    v34 = qcdr(v34);
    fn = elt(env, 1); /* general!-modular!-times */
    v34 = (*qfn2(fn))(qenv(fn), v66, v34);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v34);
    }
/* error exit handlers */
v40:
    popv(1);
    return nil;
}



/* Code for plus!-mod!-p */

static Lisp_Object CC_plusKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v221, v222;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for plus-mod-p");
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
    stack[0] = nil;
    goto v4;

v4:
    v165 = stack[-3];
    if (v165 == nil) goto v14;
    v165 = stack[-2];
    if (v165 == nil) goto v51;
    v165 = stack[-3];
    if (!consp(v165)) goto v56;
    v165 = stack[-3];
    v165 = qcar(v165);
    v165 = (consp(v165) ? nil : lisp_true);
    goto v41;

v41:
    if (v165 == nil) goto v26;
    v165 = stack[-2];
    if (!consp(v165)) goto v48;
    v165 = stack[-2];
    v165 = qcar(v165);
    v165 = (consp(v165) ? nil : lisp_true);
    goto v54;

v54:
    if (v165 == nil) goto v91;
    v222 = stack[0];
    v221 = stack[-3];
    v165 = stack[-2];
    {   int32_t w = int_of_fixnum(v221) + int_of_fixnum(v165);
        if (w >= current_modulus) w -= current_modulus;
        v165 = fixnum_of_int(w);
    }
    v221 = v165;
    v165 = v221;
    v165 = (Lisp_Object)zerop(v165);
    v165 = v165 ? lisp_true : nil;
    env = stack[-5];
    if (v165 == nil) goto v93;
    v165 = qvalue(elt(env, 2)); /* nil */
    goto v148;

v148:
    {
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v222, v165);
    }

v93:
    v165 = v221;
    goto v148;

v91:
    v165 = stack[-2];
    v221 = qcar(v165);
    v165 = stack[0];
    v165 = cons(v221, v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    stack[0] = v165;
    v165 = stack[-2];
    v165 = qcdr(v165);
    stack[-2] = v165;
    goto v4;

v48:
    v165 = qvalue(elt(env, 1)); /* t */
    goto v54;

v26:
    v165 = stack[-2];
    if (!consp(v165)) goto v21;
    v165 = stack[-2];
    v165 = qcar(v165);
    v165 = (consp(v165) ? nil : lisp_true);
    goto v20;

v20:
    if (v165 == nil) goto v83;
    v165 = stack[-3];
    v221 = qcar(v165);
    v165 = stack[0];
    v165 = cons(v221, v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    stack[0] = v165;
    v165 = stack[-3];
    v165 = qcdr(v165);
    stack[-3] = v165;
    goto v4;

v83:
    v165 = stack[-3];
    v165 = qcar(v165);
    v221 = qcar(v165);
    v165 = stack[-2];
    v165 = qcar(v165);
    v165 = qcar(v165);
    if (equal(v221, v165)) goto v145;
    v165 = stack[-3];
    v165 = qcar(v165);
    v165 = qcar(v165);
    v221 = qcar(v165);
    v165 = stack[-2];
    v165 = qcar(v165);
    v165 = qcar(v165);
    v165 = qcar(v165);
    if (equal(v221, v165)) goto v223;
    v165 = qvalue(elt(env, 2)); /* nil */
    goto v224;

v224:
    if (!(v165 == nil)) goto v163;
    v165 = stack[-3];
    v165 = qcar(v165);
    v165 = qcar(v165);
    v221 = qcar(v165);
    v165 = stack[-2];
    v165 = qcar(v165);
    v165 = qcar(v165);
    v165 = qcar(v165);
    if (equal(v221, v165)) goto v225;
    v165 = stack[-3];
    v165 = qcar(v165);
    v165 = qcar(v165);
    v221 = qcar(v165);
    v165 = stack[-2];
    v165 = qcar(v165);
    v165 = qcar(v165);
    v165 = qcar(v165);
    fn = elt(env, 4); /* ordop */
    v165 = (*qfn2(fn))(qenv(fn), v221, v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    goto v226;

v226:
    if (!(v165 == nil)) goto v163;
    v165 = stack[-2];
    v221 = qcar(v165);
    v165 = stack[0];
    v165 = cons(v221, v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    stack[0] = v165;
    v165 = stack[-2];
    v165 = qcdr(v165);
    stack[-2] = v165;
    goto v4;

v163:
    v165 = stack[-3];
    v221 = qcar(v165);
    v165 = stack[0];
    v165 = cons(v221, v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    stack[0] = v165;
    v165 = stack[-3];
    v165 = qcdr(v165);
    stack[-3] = v165;
    goto v4;

v225:
    v165 = qvalue(elt(env, 2)); /* nil */
    goto v226;

v223:
    v165 = stack[-3];
    v165 = qcar(v165);
    v165 = qcar(v165);
    v221 = qcdr(v165);
    v165 = stack[-2];
    v165 = qcar(v165);
    v165 = qcar(v165);
    v165 = qcdr(v165);
    v165 = ((intptr_t)v221 > (intptr_t)v165) ? lisp_true : nil;
    goto v224;

v145:
    stack[-4] = stack[0];
    v165 = stack[-3];
    v165 = qcar(v165);
    stack[-1] = qcar(v165);
    v165 = stack[-3];
    v165 = qcar(v165);
    v221 = qcdr(v165);
    v165 = stack[-2];
    v165 = qcar(v165);
    v165 = qcdr(v165);
    stack[0] = CC_plusKmodKp(env, v221, v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    v165 = stack[-3];
    v221 = qcdr(v165);
    v165 = stack[-2];
    v165 = qcdr(v165);
    v165 = CC_plusKmodKp(env, v221, v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    fn = elt(env, 5); /* adjoin!-term */
    v165 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-5];
    {
        Lisp_Object v227 = stack[-4];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v227, v165);
    }

v21:
    v165 = qvalue(elt(env, 1)); /* t */
    goto v20;

v56:
    v165 = qvalue(elt(env, 1)); /* t */
    goto v41;

v51:
    v221 = stack[0];
    v165 = stack[-3];
    {
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v221, v165);
    }

v14:
    v221 = stack[0];
    v165 = stack[-2];
    {
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v221, v165);
    }
/* error exit handlers */
v166:
    popv(6);
    return nil;
}



/* Code for monomclone */

static Lisp_Object CC_monomclone(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v199, v188, v77, v78;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monomclone");
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
    v199 = stack[0];
    if (v199 == nil) goto v6;
    stack[-2] = nil;
    v199 = (Lisp_Object)17; /* 1 */
    v199 = Lmkvect(nil, v199);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-4];
    stack[-3] = v199;
    v78 = stack[-3];
    v77 = (Lisp_Object)1; /* 0 */
    v188 = stack[0];
    v199 = (Lisp_Object)1; /* 0 */
    v199 = *(Lisp_Object *)((char *)v188 + (CELL-TAG_VECTOR) + ((int32_t)v199/(16/CELL)));
    *(Lisp_Object *)((char *)v78 + (CELL-TAG_VECTOR) + ((int32_t)v77/(16/CELL))) = v199;
    v188 = stack[0];
    v199 = (Lisp_Object)17; /* 1 */
    v199 = *(Lisp_Object *)((char *)v188 + (CELL-TAG_VECTOR) + ((int32_t)v199/(16/CELL)));
    stack[0] = v199;
    goto v58;

v58:
    v199 = stack[0];
    if (v199 == nil) goto v148;
    v199 = stack[0];
    v188 = qcar(v199);
    v199 = stack[-2];
    v199 = cons(v188, v199);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-4];
    stack[-2] = v199;
    v199 = stack[0];
    v199 = qcdr(v199);
    stack[0] = v199;
    goto v58;

v148:
    stack[-1] = stack[-3];
    stack[0] = (Lisp_Object)17; /* 1 */
    v199 = stack[-2];
    v199 = Lreverse(nil, v199);
    nil = C_nil;
    if (exception_pending()) goto v146;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v199;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v6:
    v199 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v199); }
/* error exit handlers */
v146:
    popv(5);
    return nil;
}



/* Code for symbollessp */

static Lisp_Object CC_symbollessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v10, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbollessp");
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
    v10 = v1;
    v11 = v0;
/* end of prologue */
    v56 = v10;
    if (v56 == nil) goto v5;
    v56 = v11;
    if (v56 == nil) goto v64;
    v56 = qvalue(elt(env, 3)); /* wukord!* */
    if (v56 == nil) goto v22;
    v56 = v11;
    {
        fn = elt(env, 4); /* wuorderp */
        return (*qfn2(fn))(qenv(fn), v56, v10);
    }

v22:
    v56 = v11;
    v56 = Lorderp(nil, v56, v10);
    errexit();
    v56 = (v56 == nil ? lisp_true : nil);
    return onevalue(v56);

v64:
    v56 = qvalue(elt(env, 2)); /* t */
    return onevalue(v56);

v5:
    v56 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v56);
}



/* Code for rank */

static Lisp_Object CC_rank(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v228;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rank");
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
    v183 = qvalue(elt(env, 1)); /* !*mcd */
    if (v183 == nil) goto v86;
    v183 = stack[-2];
    v183 = qcar(v183);
    v183 = qcar(v183);
    v183 = qcdr(v183);
    { popv(5); return onevalue(v183); }

v86:
    v183 = stack[-2];
    v183 = qcar(v183);
    v183 = qcar(v183);
    v183 = qcdr(v183);
    stack[-1] = v183;
    v183 = stack[-2];
    v183 = qcar(v183);
    v183 = qcar(v183);
    v183 = qcar(v183);
    stack[0] = v183;
    goto v175;

v175:
    v183 = stack[-2];
    v183 = qcar(v183);
    v183 = qcar(v183);
    v183 = qcdr(v183);
    stack[-3] = v183;
    v183 = stack[-2];
    v183 = qcdr(v183);
    if (v183 == nil) goto v63;
    v183 = stack[-2];
    v183 = qcdr(v183);
    stack[-2] = v183;
    v228 = stack[-2];
    v183 = stack[0];
    fn = elt(env, 2); /* degr */
    v228 = (*qfn2(fn))(qenv(fn), v228, v183);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-4];
    v183 = (Lisp_Object)1; /* 0 */
    if (!(v228 == v183)) goto v175;
    v228 = stack[-3];
    v183 = (Lisp_Object)1; /* 0 */
    v183 = (Lisp_Object)lessp2(v228, v183);
    nil = C_nil;
    if (exception_pending()) goto v38;
    v183 = v183 ? lisp_true : nil;
    env = stack[-4];
    if (v183 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v228 = stack[-1];
    v183 = (Lisp_Object)1; /* 0 */
    v183 = (Lisp_Object)lessp2(v228, v183);
    nil = C_nil;
    if (exception_pending()) goto v38;
    v183 = v183 ? lisp_true : nil;
    if (v183 == nil) goto v45;
    v183 = stack[-3];
    popv(5);
    return negate(v183);

v45:
    v228 = stack[-1];
    v183 = stack[-3];
    popv(5);
    return difference2(v228, v183);

v63:
    v228 = stack[-1];
    v183 = stack[-3];
    popv(5);
    return difference2(v228, v183);
/* error exit handlers */
v38:
    popv(5);
    return nil;
}



/* Code for remove!-free!-vars */

static Lisp_Object CC_removeKfreeKvars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v224, v234, v235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remove-free-vars");
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
    v224 = stack[0];
    if (!consp(v224)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v224 = stack[0];
    v234 = qcar(v224);
    v224 = elt(env, 1); /* !~ */
    if (v234 == v224) goto v15;
    v224 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* remove!-free!-vars!-l */
        return (*qfn1(fn))(qenv(fn), v224);
    }

v15:
    v224 = qvalue(elt(env, 2)); /* !*!*noremove!*!* */
    if (v224 == nil) goto v53;
    v224 = stack[0];
    v224 = qcdr(v224);
    v234 = qcar(v224);
    v224 = qvalue(elt(env, 3)); /* frasc!* */
    v224 = Latsoc(nil, v234, v224);
    v235 = v224;
    if (!(v224 == nil)) goto v47;
    v224 = stack[0];
    v224 = qcdr(v224);
    v234 = qcar(v224);
    v224 = elt(env, 1); /* !~ */
    if (!consp(v234)) goto v28;
    v234 = qcar(v234);
    if (!(v234 == v224)) goto v28;
    v224 = stack[0];
    v224 = qcdr(v224);
    v224 = qcar(v224);
    v224 = qcdr(v224);
    v224 = qcar(v224);
    v234 = qvalue(elt(env, 3)); /* frasc!* */
    v224 = Latsoc(nil, v224, v234);
    v235 = v224;
    goto v58;

v58:
    if (v224 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    else goto v47;

v47:
    v224 = v235;
    v224 = qcdr(v224);
    { popv(3); return onevalue(v224); }

v28:
    v224 = qvalue(elt(env, 4)); /* nil */
    goto v58;

v53:
    v224 = stack[0];
    v224 = qcdr(v224);
    if (!consp(v224)) goto v93;
    v224 = stack[0];
    v224 = qcdr(v224);
    v224 = qcar(v224);
    stack[-1] = v224;
    if (is_number(v224)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v224 = stack[-1];
    if (symbolp(v224)) goto v73;
    v234 = stack[-1];
    v224 = elt(env, 1); /* !~ */
    if (!consp(v234)) goto v76;
    v234 = qcar(v234);
    if (!(v234 == v224)) goto v76;
    v224 = stack[-1];
    v224 = qcdr(v224);
    v224 = qcar(v224);
    stack[-1] = v224;
    goto v20;

v20:
    if (!(v224 == nil)) goto v73;
    v224 = stack[0];
    v224 = qcdr(v224);
    v224 = qcar(v224);
    v224 = qcar(v224);
    if (symbolp(v224)) goto v236;
    v234 = stack[0];
    v224 = elt(env, 5); /* "free variable" */
    {
        popv(3);
        fn = elt(env, 8); /* typerr */
        return (*qfn2(fn))(qenv(fn), v234, v224);
    }

v236:
    v224 = stack[0];
    v224 = qcdr(v224);
    v224 = qcar(v224);
    v224 = qcar(v224);
    fn = elt(env, 9); /* get!-free!-form */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    v234 = ncons(v224);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    v224 = qvalue(elt(env, 6)); /* frlis!* */
    fn = elt(env, 10); /* union */
    v224 = (*qfn2(fn))(qenv(fn), v234, v224);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    qvalue(elt(env, 6)) = v224; /* frlis!* */
    v224 = stack[0];
    v224 = qcdr(v224);
    v224 = qcar(v224);
    stack[-1] = qcar(v224);
    v224 = stack[0];
    v224 = qcdr(v224);
    v224 = qcar(v224);
    v224 = qcdr(v224);
    fn = elt(env, 7); /* remove!-free!-vars!-l */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v140;
    {
        Lisp_Object v237 = stack[-1];
        popv(3);
        return cons(v237, v224);
    }

v73:
    v224 = stack[0];
    v224 = qcdr(v224);
    v224 = qcar(v224);
    fn = elt(env, 9); /* get!-free!-form */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    v234 = ncons(v224);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    v224 = qvalue(elt(env, 6)); /* frlis!* */
    fn = elt(env, 10); /* union */
    v224 = (*qfn2(fn))(qenv(fn), v234, v224);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    qvalue(elt(env, 6)) = v224; /* frlis!* */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v76:
    v224 = qvalue(elt(env, 4)); /* nil */
    goto v20;

v93:
    v234 = stack[0];
    v224 = elt(env, 5); /* "free variable" */
    {
        popv(3);
        fn = elt(env, 8); /* typerr */
        return (*qfn2(fn))(qenv(fn), v234, v224);
    }
/* error exit handlers */
v140:
    popv(3);
    return nil;
}



/* Code for nocp */

static Lisp_Object CC_nocp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nocp");
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

v69:
    v22 = stack[0];
    if (v22 == nil) goto v6;
    v22 = qvalue(elt(env, 2)); /* !*ncmp */
    if (v22 == nil) goto v15;
    v22 = stack[0];
    v22 = qcar(v22);
    v22 = qcar(v22);
    fn = elt(env, 4); /* noncomp1 */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    if (v22 == nil) goto v15;
    v22 = stack[0];
    v22 = qcdr(v22);
    stack[0] = v22;
    goto v69;

v15:
    v22 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v22); }

v6:
    v22 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v22); }
/* error exit handlers */
v47:
    popv(2);
    return nil;
}



/* Code for get!+row!+nr */

static Lisp_Object CC_getLrowLnr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get+row+nr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
        return Llength(nil, v4);
}



/* Code for setcar */

static Lisp_Object CC_setcar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v14;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setcar");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    v15 = v0;
/* end of prologue */
    v14 = v15;
    v15 = stack[0];
    v15 = Lrplaca(nil, v14, v15);
    nil = C_nil;
    if (exception_pending()) goto v66;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
/* error exit handlers */
v66:
    popv(1);
    return nil;
}



/* Code for notstring */

static Lisp_Object CC_notstring(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v52, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for notstring");
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
    v9 = v0;
/* end of prologue */
    v52 = elt(env, 1); /* !  */
    fn = elt(env, 5); /* delall */
    v9 = (*qfn2(fn))(qenv(fn), v52, v9);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[0];
    v42 = v9;
    v9 = v42;
    v52 = qcar(v9);
    v9 = elt(env, 2); /* !" */
    if (v52 == v9) goto v174;
    v9 = v42;
    v9 = Lreverse(nil, v9);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[0];
    v52 = qcar(v9);
    v9 = elt(env, 2); /* !" */
    v9 = Lneq(nil, v52, v9);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[0];
    goto v175;

v175:
    if (v9 == nil) goto v59;
    v9 = qvalue(elt(env, 4)); /* t */
    { popv(1); return onevalue(v9); }

v59:
    v9 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v9); }

v174:
    v9 = qvalue(elt(env, 3)); /* nil */
    goto v175;
/* error exit handlers */
v54:
    popv(1);
    return nil;
}



/* Code for rd!:onep */

static Lisp_Object CC_rdTonep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:onep");
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
    v48 = v0;
/* end of prologue */
    v17 = v48;
    v17 = qcdr(v17);
    if (!consp(v17)) goto v40;
    stack[-1] = qvalue(elt(env, 3)); /* bfone!* */
    stack[0] = v48;
    v17 = qvalue(elt(env, 4)); /* !:bprec!: */
    v48 = (Lisp_Object)49; /* 3 */
    v48 = difference2(v17, v48);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-2];
    fn = elt(env, 5); /* round!:mt */
    v48 = (*qfn2(fn))(qenv(fn), stack[0], v48);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-2];
    fn = elt(env, 6); /* csl_normbf */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-2];
    {
        Lisp_Object v30 = stack[-1];
        popv(3);
        fn = elt(env, 7); /* equal!: */
        return (*qfn2(fn))(qenv(fn), v30, v48);
    }

v40:
    v17 = elt(env, 1); /* 1.0 */
    v48 = qcdr(v48);
    v48 = difference2(v17, v48);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-2];
    v48 = Labsval(nil, v48);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-2];
    v17 = qvalue(elt(env, 2)); /* !!fleps1 */
        popv(3);
        return Llessp(nil, v48, v17);
/* error exit handlers */
v184:
    popv(3);
    return nil;
}



/* Code for subs2!* */

static Lisp_Object CC_subs2H(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2*");
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
    v57 = v0;
/* end of prologue */
    v4 = qvalue(elt(env, 1)); /* !*sub2 */
    stack[0] = qvalue(elt(env, 1)); /* !*sub2 */
    qvalue(elt(env, 1)) = v4; /* !*sub2 */
    v4 = v57;
    fn = elt(env, 2); /* subs2 */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*sub2 */
    { popv(2); return onevalue(v4); }
/* error exit handlers */
v64:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*sub2 */
    popv(2);
    return nil;
}



/* Code for mgenp */

static Lisp_Object CC_mgenp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v60;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mgenp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v60 = v0;
/* end of prologue */
    v175 = v60;
    if (!consp(v175)) goto v55;
    v175 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v175);

v55:
    v175 = v60;
    v60 = elt(env, 1); /* mgen */
    return get(v175, v60);
}



/* Code for evlexcomp */

static Lisp_Object CC_evlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v42;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evlexcomp");
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

v5:
    v52 = stack[-1];
    if (v52 == nil) goto v55;
    v52 = stack[0];
    if (v52 == nil) goto v15;
    v52 = stack[-1];
    v42 = qcar(v52);
    v52 = stack[0];
    v52 = qcar(v52);
    v52 = Leqn(nil, v42, v52);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    if (v52 == nil) goto v41;
    v52 = stack[-1];
    v52 = qcdr(v52);
    stack[-1] = v52;
    v52 = stack[0];
    v52 = qcdr(v52);
    stack[0] = v52;
    goto v5;

v41:
    v52 = stack[-1];
    v42 = qcar(v52);
    v52 = stack[0];
    v52 = qcar(v52);
    if (((int32_t)(v42)) > ((int32_t)(v52))) goto v26;
    v52 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v52); }

v26:
    v52 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v52); }

v15:
    v52 = elt(env, 1); /* (0) */
    stack[0] = v52;
    goto v5;

v55:
    v52 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v52); }
/* error exit handlers */
v17:
    popv(3);
    return nil;
}



/* Code for subs2f */

static Lisp_Object CC_subs2f(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2f");
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
    v147 = qvalue(elt(env, 1)); /* simpcount!* */
    v146 = qvalue(elt(env, 2)); /* simplimit!* */
    v146 = (Lisp_Object)greaterp2(v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v89;
    v146 = v146 ? lisp_true : nil;
    env = stack[-2];
    if (v146 == nil) goto v4;
    v146 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v146; /* simpcount!* */
    v146 = elt(env, 3); /* "Simplification recursion too deep" */
    v147 = v146;
    v146 = v147;
    qvalue(elt(env, 4)) = v146; /* errmsg!* */
    v146 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v146 == nil)) goto v51;
    v146 = v147;
    fn = elt(env, 10); /* lprie */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    goto v51;

v51:
    v146 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    goto v4;

v4:
    v146 = qvalue(elt(env, 1)); /* simpcount!* */
    v146 = add1(v146);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    qvalue(elt(env, 1)) = v146; /* simpcount!* */
    v146 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 7)) = v146; /* !*sub2 */
    v146 = stack[0];
    fn = elt(env, 11); /* subs2f1 */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    stack[-1] = v146;
    v146 = qvalue(elt(env, 7)); /* !*sub2 */
    if (!(v146 == nil)) goto v63;
    v146 = qvalue(elt(env, 8)); /* powlis1!* */
    if (!(v146 == nil)) goto v63;

v11:
    v146 = qvalue(elt(env, 1)); /* simpcount!* */
    v146 = sub1(v146);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    qvalue(elt(env, 1)) = v146; /* simpcount!* */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v63:
    v146 = qvalue(elt(env, 9)); /* !*resubs */
    if (v146 == nil) goto v11;
    v146 = stack[-1];
    v147 = qcar(v146);
    v146 = stack[0];
    if (equal(v147, v146)) goto v148;
    v146 = qvalue(elt(env, 6)); /* nil */
    goto v49;

v49:
    if (v146 == nil) goto v188;
    v146 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 7)) = v146; /* !*sub2 */
    goto v11;

v188:
    v146 = stack[-1];
    fn = elt(env, 12); /* subs2q */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    stack[-1] = v146;
    goto v11;

v148:
    v146 = stack[-1];
    v147 = qcdr(v146);
    v146 = (Lisp_Object)17; /* 1 */
    v146 = (v147 == v146 ? lisp_true : nil);
    goto v49;
/* error exit handlers */
v89:
    popv(3);
    return nil;
}



/* Code for ordpp */

static Lisp_Object CC_ordpp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v12, v13, v199, v188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordpp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v13 = v1;
    v199 = v0;
/* end of prologue */
    v90 = v199;
    v12 = qcar(v90);
    v90 = v13;
    v90 = qcar(v90);
    if (v12 == v90) goto v65;
    v90 = qvalue(elt(env, 1)); /* kord!* */
    v188 = v90;
    v90 = v199;
    v90 = qcar(v90);
    v199 = v90;
    v90 = v13;
    v90 = qcar(v90);
    v13 = v90;
    goto v4;

v4:
    v90 = v188;
    if (v90 == nil) goto v32;
    v12 = v199;
    v90 = v188;
    v90 = qcar(v90);
    if (v12 == v90) goto v42;
    v12 = v13;
    v90 = v188;
    v90 = qcar(v90);
    if (v12 == v90) goto v170;
    v90 = v188;
    v90 = qcdr(v90);
    v188 = v90;
    goto v4;

v170:
    v90 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v90);

v42:
    v90 = qvalue(elt(env, 2)); /* t */
    return onevalue(v90);

v32:
    v90 = v199;
    v12 = v13;
    {
        fn = elt(env, 4); /* ordpa */
        return (*qfn2(fn))(qenv(fn), v90, v12);
    }

v65:
    v90 = v199;
    v90 = qcdr(v90);
    v12 = v13;
    v12 = qcdr(v12);
        return Lgreaterp(nil, v90, v12);
}



/* Code for !:minusp */

static Lisp_Object CC_Tminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v67, v47;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :minusp");
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
    v47 = v0;
/* end of prologue */
    v22 = v47;
    if (!consp(v22)) goto v6;
    v22 = v47;
    v67 = qcar(v22);
    v22 = elt(env, 1); /* minusp */
    v22 = get(v67, v22);
    v67 = v47;
        return Lapply1(nil, v22, v67);

v6:
    v22 = v47;
        return Lminusp(nil, v22);
}



/* Code for fprin2 */

static Lisp_Object CC_fprin2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v40;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fprin2");
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
    v40 = v0;
/* end of prologue */
    v66 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* !*lower */
    qvalue(elt(env, 2)) = v66; /* !*lower */
    v66 = qvalue(elt(env, 3)); /* !*fortupper */
    if (v66 == nil) goto v86;
    v66 = v40;
    fn = elt(env, 4); /* prin2!-upcase */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-1];
    goto v5;

v5:
    qvalue(elt(env, 2)) = stack[0]; /* !*lower */
    { popv(2); return onevalue(v66); }

v86:
    v66 = v40;
    fn = elt(env, 5); /* prin2!-downcase */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-1];
    goto v5;
/* error exit handlers */
v175:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*lower */
    popv(2);
    return nil;
}



/* Code for reordop */

static Lisp_Object CC_reordop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reordop");
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
    v44 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v44 == nil) goto v55;
    v44 = stack[-1];
    fn = elt(env, 3); /* noncomp1 */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-2];
    if (v44 == nil) goto v40;
    v44 = stack[0];
    fn = elt(env, 3); /* noncomp1 */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-2];
    goto v57;

v57:
    if (!(v44 == nil)) { popv(3); return onevalue(v44); }
    v41 = stack[-1];
    v44 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* ordop */
        return (*qfn2(fn))(qenv(fn), v41, v44);
    }

v40:
    v44 = qvalue(elt(env, 2)); /* nil */
    goto v57;

v55:
    v44 = qvalue(elt(env, 2)); /* nil */
    goto v57;
/* error exit handlers */
v11:
    popv(3);
    return nil;
}



/* Code for !*collectphysops_reversed */

static Lisp_Object CC_Hcollectphysops_reversed(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *collectphysops_reversed");
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
    v63 = stack[-1];
    fn = elt(env, 2); /* physopp */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    if (v63 == nil) goto v65;
    v32 = stack[-1];
    v63 = stack[0];
    popv(3);
    return cons(v32, v63);

v65:
    v63 = stack[-1];
    if (!consp(v63)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v63 = stack[-1];
    v32 = qcar(v63);
    v63 = stack[0];
    v63 = CC_Hcollectphysops_reversed(env, v32, v63);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    stack[0] = v63;
    v63 = stack[-1];
    v63 = qcdr(v63);
    stack[-1] = v63;
    goto v65;
/* error exit handlers */
v58:
    popv(3);
    return nil;
}



/* Code for constimes */

static Lisp_Object CC_constimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v171, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for constimes");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v171 = v0;
/* end of prologue */
    v86 = v171;
    v171 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* cstimes */
        return (*qfn2(fn))(qenv(fn), v86, v171);
    }
}



/* Code for angles!-equal */

static Lisp_Object CC_anglesKequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v48, v17;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for angles-equal");
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
    v54 = (Lisp_Object)1; /* 0 */
    stack[-2] = v54;
    goto v39;

v39:
    v48 = stack[-1];
    v54 = stack[-2];
    v17 = *(Lisp_Object *)((char *)v48 + (CELL-TAG_VECTOR) + ((int32_t)v54/(16/CELL)));
    v48 = stack[0];
    v54 = stack[-2];
    v54 = *(Lisp_Object *)((char *)v48 + (CELL-TAG_VECTOR) + ((int32_t)v54/(16/CELL)));
    if (equal(v17, v54)) goto v64;
    v54 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v54); }

v64:
    v54 = stack[-2];
    v54 = add1(v54);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    stack[-2] = v54;
    v48 = stack[-2];
    v54 = (Lisp_Object)129; /* 8 */
    v54 = (Lisp_Object)lessp2(v48, v54);
    nil = C_nil;
    if (exception_pending()) goto v30;
    v54 = v54 ? lisp_true : nil;
    env = stack[-3];
    if (!(v54 == nil)) goto v39;
    v54 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v54); }
/* error exit handlers */
v30:
    popv(4);
    return nil;
}



/* Code for mo_vdivides!? */

static Lisp_Object CC_mo_vdividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_vdivides?");
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
    v67 = stack[-1];
    fn = elt(env, 2); /* mo_comp */
    stack[-2] = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-3];
    v67 = stack[0];
    fn = elt(env, 2); /* mo_comp */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-3];
    v67 = Leqn(nil, stack[-2], v67);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-3];
    if (v67 == nil) goto v5;
    v47 = stack[-1];
    v67 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* mo_divides!? */
        return (*qfn2(fn))(qenv(fn), v47, v67);
    }

v5:
    v67 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v67); }
/* error exit handlers */
v44:
    popv(4);
    return nil;
}



/* Code for dless */

static Lisp_Object CC_dless(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v89, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dless");
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
    v91 = v1;
    stack[0] = v0;
/* end of prologue */
    v89 = qvalue(elt(env, 1)); /* ordering */
    v88 = elt(env, 2); /* lex */
    if (v89 == v88) goto v66;
    v88 = stack[0];
    v89 = qcar(v88);
    v88 = v91;
    v88 = qcar(v88);
    if (((int32_t)(v89)) < ((int32_t)(v88))) goto v80;
    v88 = stack[0];
    v89 = qcar(v88);
    v88 = v91;
    v88 = qcar(v88);
    if (((int32_t)(v89)) > ((int32_t)(v88))) goto v41;
    v89 = qvalue(elt(env, 1)); /* ordering */
    v88 = elt(env, 5); /* glex */
    if (v89 == v88) goto v31;
    v89 = qvalue(elt(env, 1)); /* ordering */
    v88 = elt(env, 6); /* grev */
    if (v89 == v88) goto v199;
    v88 = nil;
    { popv(3); return onevalue(v88); }

v199:
    v88 = v91;
    v88 = qcdr(v88);
    stack[-1] = Lreverse(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    v88 = stack[0];
    v88 = qcdr(v88);
    v88 = Lreverse(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    {
        Lisp_Object v24 = stack[-1];
        popv(3);
        fn = elt(env, 7); /* dlesslex */
        return (*qfn2(fn))(qenv(fn), v24, v88);
    }

v31:
    v88 = stack[0];
    v88 = qcdr(v88);
    v89 = v91;
    v89 = qcdr(v89);
    {
        popv(3);
        fn = elt(env, 7); /* dlesslex */
        return (*qfn2(fn))(qenv(fn), v88, v89);
    }

v41:
    v88 = qvalue(elt(env, 4)); /* nil */
    { popv(3); return onevalue(v88); }

v80:
    v88 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v88); }

v66:
    v88 = stack[0];
    v89 = v91;
    {
        popv(3);
        fn = elt(env, 7); /* dlesslex */
        return (*qfn2(fn))(qenv(fn), v88, v89);
    }
/* error exit handlers */
v23:
    popv(3);
    return nil;
}



/* Code for pappl0 */

static Lisp_Object CC_pappl0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pappl0");
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
    v14 = v1;
    v34 = v0;
/* end of prologue */
    stack[0] = v34;
    fn = elt(env, 1); /* unpkp */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-1];
    fn = elt(env, 2); /* pappl */
    v14 = (*qfn2(fn))(qenv(fn), stack[0], v14);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* pkp */
        return (*qfn1(fn))(qenv(fn), v14);
    }
/* error exit handlers */
v40:
    popv(2);
    return nil;
}



/* Code for checkargcount */

static Lisp_Object CC_checkargcount(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v95, v152, v28, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checkargcount");
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
    v152 = v1;
    v28 = v0;
/* end of prologue */
    v95 = v28;
    v2 = elt(env, 1); /* naryargs */
    v2 = Lflagp(nil, v95, v2);
    env = stack[-3];
    if (v2 == nil) goto v61;
    v2 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v2); }

v61:
    v95 = v28;
    v2 = elt(env, 3); /* number!-of!-args */
    v2 = get(v95, v2);
    env = stack[-3];
    v29 = v2;
    v2 = v29;
    if (v2 == nil) goto v44;
    v95 = v29;
    v2 = v152;
    if (equal(v95, v2)) goto v32;
    stack[-2] = v28;
    stack[-1] = v29;
    stack[0] = v152;
    v2 = qvalue(elt(env, 4)); /* curfun!* */
    v2 = ncons(v2);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    fn = elt(env, 5); /* instdof */
    v2 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v2);
    nil = C_nil;
    if (exception_pending()) goto v13;
    goto v32;

v32:
    v2 = nil;
    { popv(4); return onevalue(v2); }

v44:
    v2 = v28;
    v95 = v152;
    {
        popv(4);
        fn = elt(env, 6); /* hasarg */
        return (*qfn2(fn))(qenv(fn), v2, v95);
    }
/* error exit handlers */
v13:
    popv(4);
    return nil;
}



/* Code for sfto_dcontentf */

static Lisp_Object CC_sfto_dcontentf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v171, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_dcontentf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v171 = v0;
/* end of prologue */
    v86 = v171;
    v171 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* sfto_dcontentf1 */
        return (*qfn2(fn))(qenv(fn), v86, v171);
    }
}



/* Code for lt!* */

static Lisp_Object CC_ltH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v198, v90;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lt*");
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
    v29 = qvalue(elt(env, 1)); /* !*mcd */
    if (!(v29 == nil)) goto v6;
    v29 = stack[-1];
    v29 = qcar(v29);
    v29 = qcar(v29);
    v198 = qcdr(v29);
    v29 = (Lisp_Object)1; /* 0 */
    v29 = (Lisp_Object)greaterp2(v198, v29);
    nil = C_nil;
    if (exception_pending()) goto v188;
    v29 = v29 ? lisp_true : nil;
    env = stack[-3];
    if (!(v29 == nil)) goto v6;
    v29 = stack[-1];
    v29 = qcar(v29);
    stack[-2] = v29;
    v29 = stack[-1];
    v29 = qcar(v29);
    v29 = qcar(v29);
    v29 = qcar(v29);
    stack[0] = v29;
    goto v67;

v67:
    v29 = stack[-1];
    v29 = qcdr(v29);
    stack[-1] = v29;
    v29 = stack[-1];
    if (v29 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v198 = stack[-1];
    v29 = stack[0];
    fn = elt(env, 2); /* degr */
    v198 = (*qfn2(fn))(qenv(fn), v198, v29);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-3];
    v29 = (Lisp_Object)1; /* 0 */
    if (!(v198 == v29)) goto v67;
    v90 = stack[0];
    v198 = (Lisp_Object)1; /* 0 */
    v29 = stack[-1];
    popv(4);
    return acons(v90, v198, v29);

v6:
    v29 = stack[-1];
    v29 = qcar(v29);
    { popv(4); return onevalue(v29); }
/* error exit handlers */
v188:
    popv(4);
    return nil;
}



/* Code for mtchk */

static Lisp_Object CC_mtchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v162, v245, v207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mtchk");
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
    stack[-4] = nil;
    stack[-3] = nil;
    v126 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v126 == nil) goto v61;
    v126 = stack[-9];
    v126 = qcar(v126);
    fn = elt(env, 3); /* noncomp1 */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-11];
    goto v60;

v60:
    stack[-10] = v126;
    goto v15;

v15:
    v126 = stack[-8];
    if (v126 == nil) { Lisp_Object res = stack[-4]; popv(12); return onevalue(res); }
    v126 = stack[-8];
    v126 = qcar(v126);
    stack[-7] = v126;
    v126 = stack[-7];
    v126 = qcar(v126);
    stack[-6] = v126;
    goto v14;

v14:
    v126 = stack[-6];
    if (v126 == nil) goto v40;
    v207 = stack[-9];
    v126 = stack[-6];
    v245 = qcar(v126);
    v126 = stack[-7];
    v126 = qcdr(v126);
    v126 = qcar(v126);
    v162 = qcar(v126);
    v126 = stack[-7];
    v126 = qcdr(v126);
    v126 = qcar(v126);
    v126 = qcdr(v126);
    fn = elt(env, 4); /* mtchp1 */
    v126 = (*qfnn(fn))(qenv(fn), 4, v207, v245, v162, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-11];
    stack[-5] = v126;
    goto v34;

v34:
    v126 = stack[-5];
    if (v126 == nil) goto v66;
    v126 = stack[-5];
    stack[0] = qcar(v126);
    v126 = stack[-6];
    v162 = qcar(v126);
    v126 = stack[-7];
    v126 = qcar(v126);
    v126 = Ldelete(nil, v162, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-11];
    stack[-2] = Lsubla(nil, stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-11];
    v126 = stack[-5];
    v162 = qcar(v126);
    v126 = stack[-7];
    v126 = qcdr(v126);
    v126 = qcar(v126);
    stack[-1] = Lsubla(nil, v162, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-11];
    v126 = stack[-5];
    v162 = qcar(v126);
    v126 = stack[-7];
    v126 = qcdr(v126);
    v126 = qcdr(v126);
    v126 = qcar(v126);
    stack[0] = Lsubla(nil, v162, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-11];
    v126 = stack[-5];
    v162 = qcar(v126);
    v126 = stack[-6];
    v126 = qcar(v126);
    v162 = Lsubla(nil, v162, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-11];
    v126 = stack[-7];
    v126 = qcdr(v126);
    v126 = qcdr(v126);
    v126 = qcdr(v126);
    v126 = qcar(v126);
    v126 = cons(v162, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-11];
    v126 = list2(stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-11];
    v126 = list2star(stack[-2], stack[-1], v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-11];
    stack[0] = v126;
    v126 = qcar(v126);
    if (v126 == nil) goto v246;
    v162 = stack[0];
    v126 = stack[-4];
    v126 = cons(v162, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-11];
    stack[-4] = v126;
    v126 = stack[-3];
    if (!(v126 == nil)) goto v2;
    v126 = stack[-4];
    stack[-3] = v126;
    goto v2;

v2:
    v126 = stack[-5];
    v126 = qcdr(v126);
    stack[-5] = v126;
    goto v34;

v246:
    v126 = stack[-5];
    v162 = qcar(v126);
    v126 = stack[-7];
    v126 = qcdr(v126);
    v126 = qcar(v126);
    v126 = qcdr(v126);
    v126 = Lsubla(nil, v162, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-11];
    fn = elt(env, 5); /* eval */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-11];
    if (v126 == nil) goto v2;
    v126 = stack[0];
    popv(12);
    return ncons(v126);

v66:
    v126 = stack[-10];
    if (v126 == nil) goto v140;
    v126 = stack[-7];
    v126 = qcdr(v126);
    v126 = qcdr(v126);
    v126 = qcdr(v126);
    v126 = qcar(v126);
    if (v126 == nil) goto v40;
    v126 = stack[-6];
    fn = elt(env, 6); /* nocp */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-11];
    if (!(v126 == nil)) goto v39;

v40:
    v126 = stack[-4];
    if (v126 == nil) goto v133;
    stack[0] = stack[-3];
    v126 = stack[-7];
    v126 = ncons(v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-11];
    v126 = Lrplacd(nil, stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-11];
    v126 = stack[-3];
    v126 = qcdr(v126);
    stack[-3] = v126;
    goto v39;

v39:
    v126 = stack[-8];
    v126 = qcdr(v126);
    stack[-8] = v126;
    goto v15;

v133:
    v126 = stack[-7];
    v126 = ncons(v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-11];
    stack[-3] = v126;
    stack[-4] = v126;
    goto v39;

v140:
    v126 = stack[-6];
    v126 = qcdr(v126);
    stack[-6] = v126;
    goto v14;

v61:
    v126 = qvalue(elt(env, 2)); /* nil */
    goto v60;
/* error exit handlers */
v128:
    popv(12);
    return nil;
}



/* Code for tayexp!-lessp */

static Lisp_Object CC_tayexpKlessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v197, v43, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-lessp");
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
    v43 = v1;
    v148 = v0;
/* end of prologue */
    v197 = v148;
    if (!consp(v197)) goto v64;
    v197 = qvalue(elt(env, 1)); /* nil */
    goto v55;

v55:
    if (v197 == nil) goto v67;
    v197 = v148;
        popv(1);
        return Llessp(nil, v197, v43);

v67:
    v197 = v148;
    fn = elt(env, 3); /* tayexp!-difference */
    v197 = (*qfn2(fn))(qenv(fn), v197, v43);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[0];
    v148 = v197;
    v197 = v148;
    if (!consp(v197)) goto v168;
    v197 = v148;
    v43 = qcar(v197);
    v197 = elt(env, 2); /* minusp */
    v197 = get(v43, v197);
    v43 = v148;
        popv(1);
        return Lapply1(nil, v197, v43);

v168:
    v197 = v148;
        popv(1);
        return Lminusp(nil, v197);

v64:
    v197 = v43;
    v197 = (consp(v197) ? nil : lisp_true);
    goto v55;
/* error exit handlers */
v172:
    popv(1);
    return nil;
}



/* Code for get!+vec!+entry */

static Lisp_Object CC_getLvecLentry(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get+vec+entry");
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
    v34 = v1;
    v66 = v0;
/* end of prologue */
    fn = elt(env, 1); /* pnth */
    v34 = (*qfn2(fn))(qenv(fn), v66, v34);
    errexit();
    v34 = qcar(v34);
    return onevalue(v34);
}



/* Code for qqe_qopheadp */

static Lisp_Object CC_qqe_qopheadp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v171, v86;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_qopheadp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v171 = v0;
/* end of prologue */
    v86 = elt(env, 1); /* (lhead rhead) */
    v171 = Lmemq(nil, v171, v86);
    return onevalue(v171);
}



/* Code for ibalp_cec */

static Lisp_Object CC_ibalp_cec(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_cec");
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

v6:
    v80 = stack[0];
    if (v80 == nil) goto v57;
    v80 = stack[0];
    v80 = qcar(v80);
    fn = elt(env, 2); /* ibalp_emptyclausep */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-1];
    if (v80 == nil) goto v175;
    v80 = stack[0];
    v80 = qcar(v80);
    { popv(2); return onevalue(v80); }

v175:
    v80 = stack[0];
    v80 = qcdr(v80);
    stack[0] = v80;
    goto v6;

v57:
    v80 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v80); }
/* error exit handlers */
v51:
    popv(2);
    return nil;
}



/* Code for ctx_fromial */

static Lisp_Object CC_ctx_fromial(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v171, v86;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ctx_fromial");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v171 = v0;
/* end of prologue */
    v86 = elt(env, 1); /* ctx */
    return list2(v86, v171);
}



/* Code for rmultpf */

static Lisp_Object CC_rmultpf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rmultpf");
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
    goto v4;

v4:
    v91 = stack[-1];
    if (v91 == nil) goto v64;
    v91 = stack[-1];
    if (!consp(v91)) goto v80;
    v91 = stack[-1];
    v91 = qcar(v91);
    v91 = (consp(v91) ? nil : lisp_true);
    goto v65;

v65:
    if (v91 == nil) goto v56;
    v91 = qvalue(elt(env, 1)); /* t */
    goto v39;

v39:
    if (v91 == nil) goto v3;
    stack[0] = stack[-3];
    v92 = stack[-2];
    v91 = stack[-1];
    v91 = cons(v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-4];
    v91 = ncons(v91);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-4];
    {
        Lisp_Object v220 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v220, v91);
    }

v3:
    v91 = stack[-1];
    v91 = qcar(v91);
    stack[0] = qcar(v91);
    v92 = stack[-2];
    v91 = stack[-1];
    v91 = qcar(v91);
    v91 = qcdr(v91);
    v92 = CC_rmultpf(env, v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-4];
    v91 = stack[-3];
    v91 = acons(stack[0], v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-4];
    stack[-3] = v91;
    v91 = stack[-1];
    v91 = qcdr(v91);
    stack[-1] = v91;
    goto v4;

v56:
    v91 = stack[-2];
    v92 = qcar(v91);
    v91 = stack[-1];
    v91 = qcar(v91);
    v91 = qcar(v91);
    v91 = qcar(v91);
    fn = elt(env, 3); /* reordop */
    v91 = (*qfn2(fn))(qenv(fn), v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-4];
    goto v39;

v80:
    v91 = qvalue(elt(env, 1)); /* t */
    goto v65;

v64:
    v91 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v91);
    }
/* error exit handlers */
v219:
    popv(5);
    return nil;
}



/* Code for multi_isarb_compl */

static Lisp_Object CC_multi_isarb_compl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multi_isarb_compl");
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
    v53 = stack[0];
    v53 = Lconsp(nil, v53);
    env = stack[-1];
    if (v53 == nil) goto v5;
    v53 = stack[0];
    if (v53 == nil) goto v5;
    v53 = stack[0];
    v53 = qcar(v53);
    fn = elt(env, 2); /* isarb_compl */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    v53 = stack[0];
    v53 = qcdr(v53);
    v53 = CC_multi_isarb_compl(env, v53);
    nil = C_nil;
    if (exception_pending()) goto v22;
    goto v5;

v5:
    v53 = nil;
    { popv(2); return onevalue(v53); }
/* error exit handlers */
v22:
    popv(2);
    return nil;
}



/* Code for dm!-times */

static Lisp_Object CC_dmKtimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-times");
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
    v34 = v0;
/* end of prologue */
    fn = elt(env, 1); /* zero2nil */
    stack[-1] = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    v34 = stack[0];
    fn = elt(env, 1); /* zero2nil */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    fn = elt(env, 2); /* !:times */
    v34 = (*qfn2(fn))(qenv(fn), stack[-1], v34);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* nil2zero */
        return (*qfn1(fn))(qenv(fn), v34);
    }
/* error exit handlers */
v39:
    popv(3);
    return nil;
}



/* Code for sqchk */

static Lisp_Object CC_sqchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v59, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqchk");
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
    v59 = v0;
/* end of prologue */
    v33 = v59;
    if (!consp(v33)) { popv(1); return onevalue(v59); }
    v33 = v59;
    v58 = qcar(v33);
    v33 = elt(env, 1); /* prepfn2 */
    v33 = get(v58, v33);
    env = stack[0];
    v58 = v33;
    v33 = v58;
    if (v33 == nil) goto v62;
    v33 = v58;
        popv(1);
        return Lapply1(nil, v33, v59);

v62:
    v33 = v59;
    v33 = qcar(v33);
    if (!consp(v33)) { popv(1); return onevalue(v59); }
    v33 = v59;
    {
        popv(1);
        fn = elt(env, 2); /* prepf */
        return (*qfn1(fn))(qenv(fn), v33);
    }
}



/* Code for exptchk */

static Lisp_Object CC_exptchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v198, v90;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptchk");
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
    v29 = stack[0];
    if (!consp(v29)) goto v55;
    v29 = stack[0];
    v29 = qcar(v29);
    v29 = (consp(v29) ? nil : lisp_true);
    goto v57;

v57:
    if (v29 == nil) goto v67;
    v198 = stack[0];
    v29 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v198, v29);

v67:
    v198 = stack[0];
    v29 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 3); /* comm_kernels1 */
    v29 = (*qfn2(fn))(qenv(fn), v198, v29);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-2];
    stack[-1] = v29;
    v29 = stack[-1];
    v198 = Llength(nil, v29);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-2];
    v29 = (Lisp_Object)33; /* 2 */
    v29 = (Lisp_Object)lessp2(v198, v29);
    nil = C_nil;
    if (exception_pending()) goto v199;
    v29 = v29 ? lisp_true : nil;
    env = stack[-2];
    if (v29 == nil) goto v18;
    v198 = stack[0];
    v29 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v198, v29);

v18:
    v90 = stack[0];
    v198 = qvalue(elt(env, 2)); /* nil */
    v29 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* exptchk0 */
        return (*qfnn(fn))(qenv(fn), 3, v90, v198, v29);
    }

v55:
    v29 = qvalue(elt(env, 1)); /* t */
    goto v57;
/* error exit handlers */
v199:
    popv(3);
    return nil;
}



/* Code for quotematrix */

static Lisp_Object CC_quotematrix(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v7;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotematrix");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v7 = elt(env, 1); /* matrix */
    return onevalue(v7);
}



setup_type const u02_setup[] =
{
    {"lto_hashequalq",          too_few_2,      CC_lto_hashequalq,wrong_no_2},
    {"compress*",               CC_compressH,   too_many_1,    wrong_no_1},
    {"noncomp1",                CC_noncomp1,    too_many_1,    wrong_no_1},
    {"ps:order",                CC_psTorder,    too_many_1,    wrong_no_1},
    {":zerop",                  CC_Tzerop,      too_many_1,    wrong_no_1},
    {"retimes",                 CC_retimes,     too_many_1,    wrong_no_1},
    {"bczero?",                 CC_bczeroW,     too_many_1,    wrong_no_1},
    {"rd:zerop",                CC_rdTzerop,    too_many_1,    wrong_no_1},
    {"evzero?",                 CC_evzeroW,     too_many_1,    wrong_no_1},
    {"factorordp",              too_few_2,      CC_factorordp, wrong_no_2},
    {"mtchp",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_mtchp},
    {"collectindices_reversed", too_few_2,      CC_collectindices_reversed,wrong_no_2},
    {"getrmacro",               CC_getrmacro,   too_many_1,    wrong_no_1},
    {"reval_without_mod",       CC_reval_without_mod,too_many_1,wrong_no_1},
    {"adddm",                   too_few_2,      CC_adddm,      wrong_no_2},
    {"multf",                   too_few_2,      CC_multf,      wrong_no_2},
    {"ring_ecart",              CC_ring_ecart,  too_many_1,    wrong_no_1},
    {"reduce_pv",               too_few_2,      CC_reduce_pv,  wrong_no_2},
    {"rnonep:",                 CC_rnonepT,     too_many_1,    wrong_no_1},
    {"general-modular-plus",    too_few_2,      CC_generalKmodularKplus,wrong_no_2},
    {"*d2n",                    CC_Hd2n,        too_many_1,    wrong_no_1},
    {"add2calls",               CC_add2calls,   too_many_1,    wrong_no_1},
    {"cl_atmlc",                CC_cl_atmlc,    too_many_1,    wrong_no_1},
    {"monomisdivisibleby",      too_few_2,      CC_monomisdivisibleby,wrong_no_2},
    {"split_form",              too_few_2,      CC_split_form, wrong_no_2},
    {"ofsf_posdefp",            CC_ofsf_posdefp,too_many_1,    wrong_no_1},
    {"tayexp-greaterp",         too_few_2,      CC_tayexpKgreaterp,wrong_no_2},
    {"mri_floorp",              CC_mri_floorp,  too_many_1,    wrong_no_1},
    {"qqe_qopaddp",             CC_qqe_qopaddp, too_many_1,    wrong_no_1},
    {"sort",                    too_few_2,      CC_sort,       wrong_no_2},
    {"ibalp_cequal",            too_few_2,      CC_ibalp_cequal,wrong_no_2},
    {"get_token",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_get_token},
    {"ps:last-term",            CC_psTlastKterm,too_many_1,    wrong_no_1},
    {"dm-abs",                  CC_dmKabs,      too_many_1,    wrong_no_1},
    {"mval",                    CC_mval,        too_many_1,    wrong_no_1},
    {"bcprod",                  too_few_2,      CC_bcprod,     wrong_no_2},
    {"wedgepf2",                too_few_2,      CC_wedgepf2,   wrong_no_2},
    {":plus",                   too_few_2,      CC_Tplus,      wrong_no_2},
    {"idlistp",                 CC_idlistp,     too_many_1,    wrong_no_1},
    {"macrochk",                too_few_2,      CC_macrochk,   wrong_no_2},
    {"mo=sprod",                too_few_2,      CC_moMsprod,   wrong_no_2},
    {"hasonevector",            CC_hasonevector,too_many_1,    wrong_no_1},
    {"sieve_pv",                too_few_2,      CC_sieve_pv,   wrong_no_2},
    {"modtimes:",               too_few_2,      CC_modtimesT,  wrong_no_2},
    {"plus-mod-p",              too_few_2,      CC_plusKmodKp, wrong_no_2},
    {"monomclone",              CC_monomclone,  too_many_1,    wrong_no_1},
    {"symbollessp",             too_few_2,      CC_symbollessp,wrong_no_2},
    {"rank",                    CC_rank,        too_many_1,    wrong_no_1},
    {"remove-free-vars",        CC_removeKfreeKvars,too_many_1,wrong_no_1},
    {"nocp",                    CC_nocp,        too_many_1,    wrong_no_1},
    {"get+row+nr",              CC_getLrowLnr,  too_many_1,    wrong_no_1},
    {"setcar",                  too_few_2,      CC_setcar,     wrong_no_2},
    {"notstring",               CC_notstring,   too_many_1,    wrong_no_1},
    {"rd:onep",                 CC_rdTonep,     too_many_1,    wrong_no_1},
    {"subs2*",                  CC_subs2H,      too_many_1,    wrong_no_1},
    {"mgenp",                   CC_mgenp,       too_many_1,    wrong_no_1},
    {"evlexcomp",               too_few_2,      CC_evlexcomp,  wrong_no_2},
    {"subs2f",                  CC_subs2f,      too_many_1,    wrong_no_1},
    {"ordpp",                   too_few_2,      CC_ordpp,      wrong_no_2},
    {":minusp",                 CC_Tminusp,     too_many_1,    wrong_no_1},
    {"fprin2",                  CC_fprin2,      too_many_1,    wrong_no_1},
    {"reordop",                 too_few_2,      CC_reordop,    wrong_no_2},
    {"*collectphysops_reversed",too_few_2,      CC_Hcollectphysops_reversed,wrong_no_2},
    {"constimes",               CC_constimes,   too_many_1,    wrong_no_1},
    {"angles-equal",            too_few_2,      CC_anglesKequal,wrong_no_2},
    {"mo_vdivides?",            too_few_2,      CC_mo_vdividesW,wrong_no_2},
    {"dless",                   too_few_2,      CC_dless,      wrong_no_2},
    {"pappl0",                  too_few_2,      CC_pappl0,     wrong_no_2},
    {"checkargcount",           too_few_2,      CC_checkargcount,wrong_no_2},
    {"sfto_dcontentf",          CC_sfto_dcontentf,too_many_1,  wrong_no_1},
    {"lt*",                     CC_ltH,         too_many_1,    wrong_no_1},
    {"mtchk",                   too_few_2,      CC_mtchk,      wrong_no_2},
    {"tayexp-lessp",            too_few_2,      CC_tayexpKlessp,wrong_no_2},
    {"get+vec+entry",           too_few_2,      CC_getLvecLentry,wrong_no_2},
    {"qqe_qopheadp",            CC_qqe_qopheadp,too_many_1,    wrong_no_1},
    {"ibalp_cec",               CC_ibalp_cec,   too_many_1,    wrong_no_1},
    {"ctx_fromial",             CC_ctx_fromial, too_many_1,    wrong_no_1},
    {"rmultpf",                 too_few_2,      CC_rmultpf,    wrong_no_2},
    {"multi_isarb_compl",       CC_multi_isarb_compl,too_many_1,wrong_no_1},
    {"dm-times",                too_few_2,      CC_dmKtimes,   wrong_no_2},
    {"sqchk",                   CC_sqchk,       too_many_1,    wrong_no_1},
    {"exptchk",                 CC_exptchk,     too_many_1,    wrong_no_1},
    {"quotematrix",             CC_quotematrix, too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u02", (two_args *)"6831 8489523 5386027", 0}
};

/* end of generated code */
