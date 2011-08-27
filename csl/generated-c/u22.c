
/* $destdir\u22.c        Machine generated C code */

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


/* Code for subsublis */

static Lisp_Object CC_subsublis(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v49, v50;
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

v51:
    v49 = stack[0];
    v48 = stack[-3];
    v48 = Lassoc(nil, v49, v48);
    v50 = v48;
    if (v48 == nil) goto v52;
    v48 = v50;
    v48 = qcdr(v48);
    { popv(6); return onevalue(v48); }

v52:
    v49 = stack[0];
    v48 = elt(env, 1); /* sqrt */
    if (!consp(v49)) goto v53;
    v49 = qcar(v49);
    if (!(v49 == v48)) goto v53;
    v50 = elt(env, 2); /* expt */
    v48 = stack[0];
    v48 = qcdr(v48);
    v49 = qcar(v48);
    v48 = elt(env, 3); /* (quotient 1 2) */
    v49 = list3(v50, v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v48 = stack[-3];
    v48 = Lassoc(nil, v49, v48);
    v50 = v48;
    goto v55;

v55:
    if (v48 == nil) goto v56;
    v48 = v50;
    v48 = qcdr(v48);
    { popv(6); return onevalue(v48); }

v56:
    v48 = stack[0];
    if (!consp(v48)) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v48 = stack[0];
    v48 = qcar(v48);
    if (symbolp(v48)) goto v57;
    v48 = stack[0];
    stack[-4] = v48;
    v48 = stack[-4];
    if (v48 == nil) goto v58;
    v48 = stack[-4];
    v48 = qcar(v48);
    v49 = stack[-3];
    v48 = CC_subsublis(env, v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v48 = ncons(v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    stack[-1] = v48;
    stack[-2] = v48;
    goto v59;

v59:
    v48 = stack[-4];
    v48 = qcdr(v48);
    stack[-4] = v48;
    v48 = stack[-4];
    if (v48 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v48 = stack[-4];
    v48 = qcar(v48);
    v49 = stack[-3];
    v48 = CC_subsublis(env, v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v48 = ncons(v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v48 = Lrplacd(nil, stack[0], v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v48 = stack[-1];
    v48 = qcdr(v48);
    stack[-1] = v48;
    goto v59;

v58:
    v48 = qvalue(elt(env, 4)); /* nil */
    { popv(6); return onevalue(v48); }

v57:
    v48 = stack[0];
    v49 = qcar(v48);
    v48 = elt(env, 5); /* subfunc */
    v48 = get(v49, v48);
    env = stack[-5];
    v50 = v48;
    if (v48 == nil) goto v60;
    v49 = stack[-3];
    v48 = stack[0];
        popv(6);
        return Lapply2(nil, 3, v50, v49, v48);

v60:
    v48 = stack[0];
    v49 = qcar(v48);
    v48 = elt(env, 6); /* dname */
    v48 = get(v49, v48);
    env = stack[-5];
    if (!(v48 == nil)) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v48 = stack[0];
    v49 = qcar(v48);
    v48 = elt(env, 7); /* !*sq */
    if (v49 == v48) goto v61;
    v48 = stack[0];
    stack[-4] = v48;
    v48 = stack[-4];
    if (v48 == nil) goto v62;
    v48 = stack[-4];
    v48 = qcar(v48);
    v49 = stack[-3];
    v48 = CC_subsublis(env, v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v48 = ncons(v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    stack[-1] = v48;
    stack[-2] = v48;
    goto v63;

v63:
    v48 = stack[-4];
    v48 = qcdr(v48);
    stack[-4] = v48;
    v48 = stack[-4];
    if (v48 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v48 = stack[-4];
    v48 = qcar(v48);
    v49 = stack[-3];
    v48 = CC_subsublis(env, v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v48 = ncons(v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v48 = Lrplacd(nil, stack[0], v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v48 = stack[-1];
    v48 = qcdr(v48);
    stack[-1] = v48;
    goto v63;

v62:
    v48 = qvalue(elt(env, 4)); /* nil */
    { popv(6); return onevalue(v48); }

v61:
    stack[-1] = stack[-3];
    v48 = stack[0];
    v48 = qcdr(v48);
    v48 = qcar(v48);
    v48 = qcar(v48);
    if (v48 == nil) goto v64;
    v48 = stack[0];
    v48 = qcdr(v48);
    v49 = qcar(v48);
    v48 = elt(env, 8); /* prepf */
    fn = elt(env, 9); /* sqform */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    goto v65;

v65:
    stack[-3] = stack[-1];
    stack[0] = v48;
    goto v51;

v64:
    v48 = (Lisp_Object)1; /* 0 */
    goto v65;

v53:
    v48 = qvalue(elt(env, 4)); /* nil */
    goto v55;
/* error exit handlers */
v54:
    popv(6);
    return nil;
}



/* Code for ordexn */

static Lisp_Object CC_ordexn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v80;
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
    goto v81;

v81:
    v79 = stack[-1];
    if (v79 == nil) goto v36;
    v80 = stack[-2];
    v79 = stack[-1];
    v79 = qcar(v79);
    if (v80 == v79) goto v82;
    v79 = stack[-2];
    if (v79 == nil) goto v83;
    v80 = stack[-2];
    v79 = stack[-1];
    v79 = qcar(v79);
    fn = elt(env, 2); /* ordop */
    v79 = (*qfn2(fn))(qenv(fn), v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    if (v79 == nil) goto v83;
    v80 = stack[-2];
    v79 = stack[-3];
    v79 = cons(v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    v80 = Lreverse(nil, v79);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    v79 = stack[-1];
    v79 = Lappend(nil, v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v84;
    {
        Lisp_Object v85 = stack[0];
        popv(5);
        return cons(v85, v79);
    }

v83:
    v79 = stack[-1];
    v80 = qcar(v79);
    v79 = stack[-3];
    v79 = cons(v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    stack[-3] = v79;
    v79 = stack[-1];
    v79 = qcdr(v79);
    stack[-1] = v79;
    v79 = stack[0];
    v79 = (v79 == nil ? lisp_true : nil);
    stack[0] = v79;
    goto v81;

v82:
    v79 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v79); }

v36:
    v80 = stack[-2];
    v79 = stack[-3];
    v79 = cons(v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    v79 = Lreverse(nil, v79);
    nil = C_nil;
    if (exception_pending()) goto v84;
    {
        Lisp_Object v86 = stack[0];
        popv(5);
        return cons(v86, v79);
    }
/* error exit handlers */
v84:
    popv(5);
    return nil;
}



/* Code for monomwrite */

static Lisp_Object CC_monomwrite(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v95, v96;
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
    v95 = v0;
/* end of prologue */
    stack[-5] = nil;
    v86 = qvalue(elt(env, 1)); /* fluidbibasisnumberofvariables */
    stack[-2] = v86;
    v86 = qvalue(elt(env, 2)); /* fluidbibasisreversedvariables */
    stack[-4] = v86;
    v86 = (Lisp_Object)17; /* 1 */
    v86 = *(Lisp_Object *)((char *)v95 + (CELL-TAG_VECTOR) + ((int32_t)v86/(16/CELL)));
    stack[-3] = v86;
    goto v56;

v56:
    v86 = stack[-3];
    v86 = qcar(v86);
    if (v86 == nil) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    v86 = (Lisp_Object)17; /* 1 */
    stack[0] = v86;
    goto v97;

v97:
    v95 = stack[-2];
    v86 = stack[-3];
    v86 = qcar(v86);
    v95 = difference2(v95, v86);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-6];
    v86 = stack[0];
    v86 = difference2(v95, v86);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-6];
    v86 = Lminusp(nil, v86);
    env = stack[-6];
    if (v86 == nil) goto v99;
    v86 = stack[-3];
    v86 = qcar(v86);
    stack[-2] = v86;
    v86 = stack[-5];
    if (v86 == nil) goto v100;
    v86 = stack[-4];
    stack[-1] = qcar(v86);
    stack[0] = (Lisp_Object)17; /* 1 */
    v86 = stack[-5];
    v86 = ncons(v86);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-6];
    v86 = acons(stack[-1], stack[0], v86);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-6];
    stack[-5] = v86;
    goto v101;

v101:
    v86 = stack[-3];
    v86 = qcdr(v86);
    stack[-3] = v86;
    goto v56;

v100:
    v86 = stack[-4];
    v96 = qcar(v86);
    v95 = (Lisp_Object)17; /* 1 */
    v86 = (Lisp_Object)17; /* 1 */
    v86 = acons(v96, v95, v86);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-6];
    stack[-5] = v86;
    goto v101;

v99:
    v86 = stack[-4];
    v86 = qcdr(v86);
    stack[-4] = v86;
    v86 = stack[0];
    v86 = add1(v86);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-6];
    stack[0] = v86;
    goto v97;
/* error exit handlers */
v98:
    popv(7);
    return nil;
}



/* Code for cl_fvarl */

static Lisp_Object CC_cl_fvarl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v104;
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
    v103 = v0;
/* end of prologue */
    fn = elt(env, 2); /* cl_fvarl1 */
    v104 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[0];
    v103 = elt(env, 1); /* ordp */
    {
        popv(1);
        fn = elt(env, 3); /* sort */
        return (*qfn2(fn))(qenv(fn), v104, v103);
    }
/* error exit handlers */
v105:
    popv(1);
    return nil;
}



/* Code for dfconst */

static Lisp_Object CC_dfconst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v36;
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
    v56 = stack[0];
    v56 = qcar(v56);
    if (v56 == nil) goto v68;
    v56 = qvalue(elt(env, 2)); /* zlist */
    fn = elt(env, 3); /* vp2 */
    v36 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-1];
    v56 = stack[0];
    v56 = cons(v36, v56);
    nil = C_nil;
    if (exception_pending()) goto v107;
    popv(2);
    return ncons(v56);

v68:
    v56 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v56); }
/* error exit handlers */
v107:
    popv(2);
    return nil;
}



/* Code for mml2ir */

static Lisp_Object MS_CDECL CC_mml2ir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v113;
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
    v112 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v112;
    v112 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v112; /* mmlatts */
    v113 = elt(env, 3); /* !! */
    v112 = (Lisp_Object)513; /* 32 */
    v112 = list2(v113, v112);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    v112 = Lcompress(nil, v112);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    qvalue(elt(env, 4)) = v112; /* space */
    v112 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 5)) = v112; /* count */
    v112 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    qvalue(elt(env, 6)) = v112; /* ch */
    v112 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 7)) = v112; /* temp2 */
    fn = elt(env, 13); /* lex */
    v112 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    v113 = qvalue(elt(env, 8)); /* char */
    v112 = elt(env, 9); /* (m a t h) */
    if (equal(v113, v112)) goto v56;
    v113 = elt(env, 10); /* "<math>" */
    v112 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 14); /* errorml */
    v112 = (*qfn2(fn))(qenv(fn), v113, v112);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    goto v76;

v76:
    fn = elt(env, 13); /* lex */
    v112 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    v113 = qvalue(elt(env, 8)); /* char */
    v112 = elt(env, 11); /* (!/ m a t h) */
    if (equal(v113, v112)) goto v114;
    v113 = elt(env, 12); /* "</math>" */
    v112 = (Lisp_Object)305; /* 19 */
    fn = elt(env, 14); /* errorml */
    v112 = (*qfn2(fn))(qenv(fn), v113, v112);
    nil = C_nil;
    if (exception_pending()) goto v32;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v114:
    v112 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v56:
    fn = elt(env, 15); /* mathml */
    v112 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    stack[0] = v112;
    goto v76;
/* error exit handlers */
v32:
    popv(2);
    return nil;
}



/* Code for ps!:value */

static Lisp_Object CC_psTvalue(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v121, v122;
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
    v121 = v0;
/* end of prologue */
    v120 = v121;
    if (!consp(v120)) goto v102;
    v120 = v121;
    v122 = qcar(v120);
    v120 = elt(env, 2); /* !:ps!: */
    if (v122 == v120) goto v99;
    v120 = v121;
    v122 = qcar(v120);
    v120 = elt(env, 3); /* dname */
    v120 = get(v122, v120);
    env = stack[0];
    goto v81;

v81:
    if (v120 == nil) goto v38;
    v120 = v121;
    if (!(v120 == nil)) { popv(1); return onevalue(v121); }
    v120 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v120); }

v38:
    v120 = (Lisp_Object)65; /* 4 */
    {
        popv(1);
        fn = elt(env, 5); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v121, v120);
    }

v99:
    v120 = qvalue(elt(env, 4)); /* nil */
    goto v81;

v102:
    v120 = qvalue(elt(env, 1)); /* t */
    goto v81;
}



/* Code for gf2cr!: */

static Lisp_Object CC_gf2crT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v74, v37, v110;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gf2cr:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v37 = v0;
/* end of prologue */
    v110 = elt(env, 1); /* !:cr!: */
    v123 = v37;
    v123 = qcar(v123);
    if (!consp(v123)) goto v105;
    v123 = v37;
    v123 = qcar(v123);
    v123 = qcdr(v123);
    v74 = v123;
    goto v81;

v81:
    v123 = v37;
    v123 = qcdr(v123);
    if (!consp(v123)) goto v124;
    v123 = v37;
    v123 = qcdr(v123);
    v123 = qcdr(v123);
    goto v102;

v102:
    return list2star(v110, v74, v123);

v124:
    v123 = v37;
    v123 = qcdr(v123);
    goto v102;

v105:
    v123 = v37;
    v123 = qcar(v123);
    v74 = v123;
    goto v81;
}



/* Code for rdcos!* */

static Lisp_Object CC_rdcosH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v39;
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
    v39 = v0;
/* end of prologue */
    v127 = v39;
    v127 = qcdr(v127);
    if (!consp(v127)) goto v93;
    v127 = v39;
    goto v68;

v68:
    fn = elt(env, 3); /* convchk */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[0];
    v39 = v127;
    v127 = v39;
    if (!consp(v127)) goto v94;
    v127 = qvalue(elt(env, 1)); /* !:bprec!: */
    fn = elt(env, 4); /* cos!: */
    v127 = (*qfn2(fn))(qenv(fn), v39, v127);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[0];
    goto v45;

v45:
    v39 = v127;
    v127 = v39;
    if (!(!consp(v127))) { popv(1); return onevalue(v39); }
    v127 = elt(env, 2); /* !:rd!: */
    popv(1);
    return cons(v127, v39);

v94:
    v127 = v39;
    fn = elt(env, 5); /* cos */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[0];
    goto v45;

v93:
    v127 = v39;
    v127 = qcdr(v127);
    goto v68;
/* error exit handlers */
v40:
    popv(1);
    return nil;
}



/* Code for powers3 */

static Lisp_Object CC_powers3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v120;
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
    v116 = v0;
/* end of prologue */

v117:
    v120 = v116;
    if (!consp(v120)) goto v105;
    v120 = v116;
    v120 = qcar(v120);
    v120 = (consp(v120) ? nil : lisp_true);
    goto v104;

v104:
    if (!(v120 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v120 = v116;
    v120 = qcar(v120);
    v120 = qcdr(v120);
    stack[-2] = v120;
    v120 = v116;
    v120 = qcar(v120);
    v120 = qcar(v120);
    stack[0] = qcar(v120);
    v120 = v116;
    v120 = qcar(v120);
    v120 = qcar(v120);
    v120 = qcdr(v120);
    v116 = qcar(v116);
    v116 = qcar(v116);
    v116 = qcdr(v116);
    v120 = cons(v120, v116);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    v116 = stack[-1];
    v116 = acons(stack[0], v120, v116);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    stack[-1] = v116;
    v116 = stack[-2];
    goto v117;

v105:
    v120 = qvalue(elt(env, 1)); /* t */
    goto v104;
/* error exit handlers */
v69:
    popv(4);
    return nil;
}



/* Code for collectphystype */

static Lisp_Object CC_collectphystype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70;
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
    v70 = stack[0];
    fn = elt(env, 2); /* physopp */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    if (v70 == nil) goto v93;
    v70 = stack[0];
    fn = elt(env, 3); /* getphystype */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v112;
    popv(5);
    return ncons(v70);

v93:
    v70 = stack[0];
    if (!consp(v70)) goto v103;
    v70 = stack[0];
    stack[-3] = v70;
    v70 = stack[-3];
    if (v70 == nil) goto v52;
    v70 = stack[-3];
    v70 = qcar(v70);
    fn = elt(env, 3); /* getphystype */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    v70 = ncons(v70);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    stack[-1] = v70;
    stack[-2] = v70;
    goto v55;

v55:
    v70 = stack[-3];
    v70 = qcdr(v70);
    stack[-3] = v70;
    v70 = stack[-3];
    if (v70 == nil) goto v128;
    stack[0] = stack[-1];
    v70 = stack[-3];
    v70 = qcar(v70);
    fn = elt(env, 3); /* getphystype */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    v70 = ncons(v70);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    v70 = Lrplacd(nil, stack[0], v70);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    v70 = stack[-1];
    v70 = qcdr(v70);
    stack[-1] = v70;
    goto v55;

v128:
    v70 = stack[-2];
    goto v36;

v36:
    {
        popv(5);
        fn = elt(env, 4); /* deletemult!* */
        return (*qfn1(fn))(qenv(fn), v70);
    }

v52:
    v70 = qvalue(elt(env, 1)); /* nil */
    goto v36;

v103:
    v70 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v70); }
/* error exit handlers */
v112:
    popv(5);
    return nil;
}



/* Code for calc_atlas */

static Lisp_Object CC_calc_atlas(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v107, v119, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_atlas");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v55 = v1;
    v107 = v0;
/* end of prologue */
    v119 = v107;
    v124 = qcar(v119);
    v119 = v107;
    v119 = qcdr(v119);
    v119 = qcdr(v119);
    v119 = qcar(v119);
    v107 = qcdr(v107);
    v107 = qcar(v107);
    {
        fn = elt(env, 1); /* calc_map_2d */
        return (*qfnn(fn))(qenv(fn), 4, v124, v119, v107, v55);
    }
}



/* Code for one!-entryp */

static Lisp_Object CC_oneKentryp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v97;
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

v93:
    v92 = stack[0];
    if (!consp(v92)) goto v102;
    v97 = stack[-1];
    v92 = stack[0];
    v92 = qcar(v92);
    v92 = Lsmemq(nil, v97, v92);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    if (v92 == nil) goto v128;
    v97 = stack[-1];
    v92 = stack[0];
    v92 = qcdr(v92);
    v92 = Lsmemq(nil, v97, v92);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    if (v92 == nil) goto v123;
    v92 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v92); }

v123:
    v92 = stack[0];
    v92 = qcar(v92);
    stack[0] = v92;
    goto v93;

v128:
    v92 = stack[0];
    v92 = qcdr(v92);
    stack[0] = v92;
    goto v93;

v102:
    v92 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v92); }
/* error exit handlers */
v127:
    popv(3);
    return nil;
}



/* Code for mv!-domainlist */

static Lisp_Object CC_mvKdomainlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v78;
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
    v78 = nil;
    goto v93;

v93:
    v52 = stack[0];
    if (v52 == nil) goto v102;
    v52 = stack[0];
    v52 = qcar(v52);
    v52 = qcdr(v52);
    v52 = cons(v52, v78);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-1];
    v78 = v52;
    v52 = stack[0];
    v52 = qcdr(v52);
    stack[0] = v52;
    goto v93;

v102:
    v52 = v78;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v52);
    }
/* error exit handlers */
v125:
    popv(2);
    return nil;
}



/* Code for mo_from_a */

static Lisp_Object CC_mo_from_a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v98;
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
    v133 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_all_names */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    v133 = Lmember(nil, stack[0], v133);
    if (v133 == nil) goto v45;
    v133 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_all_names */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    stack[-4] = v133;
    v133 = stack[-4];
    if (v133 == nil) goto v110;
    v133 = stack[-4];
    v133 = qcar(v133);
    v98 = v133;
    v133 = stack[-3];
    if (equal(v98, v133)) goto v39;
    v133 = (Lisp_Object)1; /* 0 */
    goto v127;

v127:
    v133 = ncons(v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    stack[-1] = v133;
    stack[-2] = v133;
    goto v99;

v99:
    v133 = stack[-4];
    v133 = qcdr(v133);
    stack[-4] = v133;
    v133 = stack[-4];
    if (v133 == nil) goto v30;
    stack[0] = stack[-1];
    v133 = stack[-4];
    v133 = qcar(v133);
    v98 = v133;
    v133 = stack[-3];
    if (equal(v98, v133)) goto v100;
    v133 = (Lisp_Object)1; /* 0 */
    goto v35;

v35:
    v133 = ncons(v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    v133 = Lrplacd(nil, stack[0], v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    v133 = stack[-1];
    v133 = qcdr(v133);
    stack[-1] = v133;
    goto v99;

v100:
    v133 = (Lisp_Object)17; /* 1 */
    goto v35;

v30:
    v133 = stack[-2];
    goto v118;

v118:
    fn = elt(env, 5); /* mo!=shorten */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    stack[0] = v133;
    fn = elt(env, 6); /* mo!=deglist */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    {
        Lisp_Object v135 = stack[0];
        popv(6);
        return cons(v135, v133);
    }

v39:
    v133 = (Lisp_Object)17; /* 1 */
    goto v127;

v110:
    v133 = qvalue(elt(env, 3)); /* nil */
    goto v118;

v45:
    v98 = stack[-3];
    v133 = elt(env, 2); /* "dpoly variable" */
    {
        popv(6);
        fn = elt(env, 7); /* typerr */
        return (*qfn2(fn))(qenv(fn), v98, v133);
    }
/* error exit handlers */
v134:
    popv(6);
    return nil;
}



/* Code for primep */

static Lisp_Object CC_primep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v142;
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

v68:
    v141 = stack[0];
    v141 = integerp(v141);
    if (v141 == nil) goto v104;
    v142 = stack[0];
    v141 = (Lisp_Object)1; /* 0 */
    v141 = (Lisp_Object)lessp2(v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    v141 = v141 ? lisp_true : nil;
    env = stack[-2];
    if (v141 == nil) goto v42;
    v141 = stack[0];
    v141 = negate(v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-2];
    stack[0] = v141;
    goto v68;

v42:
    v142 = stack[0];
    v141 = (Lisp_Object)17; /* 1 */
    if (v142 == v141) goto v126;
    v142 = stack[0];
    v141 = qvalue(elt(env, 3)); /* !*last!-prime!-in!-list!* */
    v141 = (Lisp_Object)lesseq2(v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    v141 = v141 ? lisp_true : nil;
    env = stack[-2];
    if (v141 == nil) goto v108;
    v141 = stack[0];
    v142 = qvalue(elt(env, 4)); /* !*primelist!* */
    v141 = Lmember(nil, v141, v142);
    { popv(3); return onevalue(v141); }

v108:
    v142 = stack[0];
    v141 = qvalue(elt(env, 5)); /* !*last!-prime!-squared!* */
    v141 = (Lisp_Object)lesseq2(v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    v141 = v141 ? lisp_true : nil;
    env = stack[-2];
    if (v141 == nil) goto v25;
    v141 = qvalue(elt(env, 4)); /* !*primelist!* */
    stack[-1] = v141;
    goto v72;

v72:
    v141 = stack[-1];
    if (v141 == nil) goto v71;
    v142 = stack[0];
    v141 = stack[-1];
    v141 = qcar(v141);
    v142 = Cremainder(v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-2];
    v141 = (Lisp_Object)1; /* 0 */
    if (v142 == v141) goto v71;
    v141 = stack[-1];
    v141 = qcdr(v141);
    stack[-1] = v141;
    goto v72;

v71:
    v141 = stack[-1];
    v141 = (v141 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v141); }

v25:
    v142 = stack[0];
    v141 = qvalue(elt(env, 6)); /* largest!-small!-modulus */
    v141 = (Lisp_Object)greaterp2(v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v143;
    v141 = v141 ? lisp_true : nil;
    env = stack[-2];
    if (v141 == nil) goto v134;
    v141 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* general!-primep */
        return (*qfn1(fn))(qenv(fn), v141);
    }

v134:
    v141 = stack[0];
    {
        popv(3);
        fn = elt(env, 8); /* small!-primep */
        return (*qfn1(fn))(qenv(fn), v141);
    }

v126:
    v141 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v141); }

v104:
    v142 = stack[0];
    v141 = elt(env, 1); /* "integer" */
    {
        popv(3);
        fn = elt(env, 9); /* typerr */
        return (*qfn2(fn))(qenv(fn), v142, v141);
    }
/* error exit handlers */
v143:
    popv(3);
    return nil;
}



/* Code for safe!-modrecip */

static Lisp_Object CC_safeKmodrecip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v108, v109;
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
    v108 = v0;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* !*msg */
    qvalue(elt(env, 1)) = nil; /* !*msg */
    stack[0] = qvalue(elt(env, 2)); /* !*protfg */
    qvalue(elt(env, 2)) = nil; /* !*protfg */
    v69 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v69; /* !*msg */
    v69 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 2)) = v69; /* !*protfg */
    v109 = v108;
    v69 = elt(env, 5); /* !:mod!: */
    if (!consp(v109)) goto v43;
    v109 = qcar(v109);
    if (!(v109 == v69)) goto v43;
    v69 = v108;
    v69 = qcdr(v69);
    v108 = v69;
    goto v43;

v43:
    v69 = elt(env, 6); /* general!-modular!-reciprocal */
    v109 = list2(v69, v108);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    v108 = qvalue(elt(env, 3)); /* nil */
    v69 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 8); /* errorset */
    v69 = (*qfnn(fn))(qenv(fn), 3, v109, v108, v69);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    v108 = v69;
    v69 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 7)) = v69; /* erfg!* */
    v69 = v108;
    if (!consp(v69)) goto v132;
    v69 = v108;
    v69 = qcdr(v69);
    goto v41;

v41:
    if (v69 == nil) goto v120;
    v69 = qvalue(elt(env, 3)); /* nil */
    goto v117;

v117:
    qvalue(elt(env, 2)) = stack[0]; /* !*protfg */
    qvalue(elt(env, 1)) = stack[-1]; /* !*msg */
    { popv(3); return onevalue(v69); }

v120:
    v69 = v108;
    v69 = qcar(v69);
    goto v117;

v132:
    v69 = qvalue(elt(env, 4)); /* t */
    goto v41;
/* error exit handlers */
v113:
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
    Lisp_Object v31, v145, v146, v59;
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

v93:
    v31 = stack[-1];
    if (!consp(v31)) goto v104;
    v31 = stack[-1];
    v31 = qcar(v31);
    v31 = (consp(v31) ? nil : lisp_true);
    goto v103;

v103:
    if (v31 == nil) goto v119;
    v31 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* !*d2n */
        return (*qfn1(fn))(qenv(fn), v31);
    }

v119:
    v31 = stack[-1];
    v31 = qcar(v31);
    v31 = qcar(v31);
    v145 = qcar(v31);
    v31 = stack[0];
    v31 = qcar(v31);
    v31 = qcar(v31);
    if (equal(v145, v31)) goto v132;
    v31 = stack[0];
    v31 = qcdr(v31);
    stack[0] = v31;
    goto v93;

v132:
    v31 = stack[-1];
    v31 = qcar(v31);
    v145 = qcdr(v31);
    v31 = stack[0];
    v31 = qcdr(v31);
    v59 = CC_evaluateKinKorderKmodKp(env, v145, v31);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-2];
    v31 = stack[-1];
    v31 = qcar(v31);
    v31 = qcar(v31);
    v146 = qcdr(v31);
    v31 = stack[-1];
    v145 = qcdr(v31);
    v31 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* horner!-rule!-in!-order!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 4, v59, v146, v145, v31);
    }

v104:
    v31 = qvalue(elt(env, 1)); /* t */
    goto v103;
/* error exit handlers */
v72:
    popv(3);
    return nil;
}



/* Code for add2locs */

static Lisp_Object CC_add2locs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154, v155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add2locs");
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
    v155 = v0;
/* end of prologue */
    v154 = qvalue(elt(env, 1)); /* !*globals */
    if (v154 == nil) goto v117;
    v154 = v155;
    stack[-2] = v154;
    goto v105;

v105:
    v154 = stack[-2];
    if (v154 == nil) goto v117;
    v154 = stack[-2];
    v154 = qcar(v154);
    stack[-1] = v154;
    v155 = stack[-1];
    v154 = qvalue(elt(env, 3)); /* locls!* */
    v154 = Lassoc(nil, v155, v154);
    stack[-3] = v154;
    v154 = stack[-3];
    if (v154 == nil) goto v90;
    v155 = stack[-1];
    v154 = elt(env, 4); /* dclglb */
    v154 = Lflagp(nil, v155, v154);
    env = stack[-4];
    if (v154 == nil) goto v90;
    v154 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 13); /* qerline */
    v154 = (*qfn1(fn))(qenv(fn), v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v154 = elt(env, 5); /* "*** Variable " */
    v154 = Lprinc(nil, v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v154 = stack[-1];
    v154 = Lprin(nil, v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v154 = elt(env, 6); /* " nested declaration in " */
    v154 = Lprinc(nil, v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v154 = qvalue(elt(env, 7)); /* curfun!* */
    fn = elt(env, 14); /* princng */
    v154 = (*qfn1(fn))(qenv(fn), v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v154 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 15); /* newline */
    v154 = (*qfn1(fn))(qenv(fn), v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    stack[0] = stack[-3];
    v155 = qvalue(elt(env, 2)); /* nil */
    v154 = stack[-3];
    v154 = cons(v155, v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v154 = Lrplacd(nil, stack[0], v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    goto v139;

v139:
    v155 = stack[-1];
    v154 = elt(env, 4); /* dclglb */
    v154 = Lflagp(nil, v155, v154);
    env = stack[-4];
    if (v154 == nil) goto v133;
    v154 = qvalue(elt(env, 8)); /* t */
    goto v80;

v80:
    if (v154 == nil) goto v157;
    v154 = stack[-1];
    fn = elt(env, 16); /* globind */
    v154 = (*qfn1(fn))(qenv(fn), v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    goto v157;

v157:
    v155 = stack[-1];
    v154 = elt(env, 10); /* seen */
    v154 = Lflagp(nil, v155, v154);
    env = stack[-4];
    if (v154 == nil) goto v28;
    v154 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 13); /* qerline */
    v154 = (*qfn1(fn))(qenv(fn), v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v154 = elt(env, 11); /* "*** Function " */
    v154 = Lprinc(nil, v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v154 = stack[-1];
    fn = elt(env, 14); /* princng */
    v154 = (*qfn1(fn))(qenv(fn), v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v154 = elt(env, 12); /* " used as variable in " */
    v154 = Lprinc(nil, v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v154 = qvalue(elt(env, 7)); /* curfun!* */
    fn = elt(env, 14); /* princng */
    v154 = (*qfn1(fn))(qenv(fn), v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v154 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 15); /* newline */
    v154 = (*qfn1(fn))(qenv(fn), v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    goto v28;

v28:
    v154 = stack[-2];
    v154 = qcdr(v154);
    stack[-2] = v154;
    goto v105;

v133:
    v155 = stack[-1];
    v154 = elt(env, 9); /* glb2rf */
    v154 = Lflagp(nil, v155, v154);
    env = stack[-4];
    goto v80;

v90:
    stack[0] = stack[-1];
    v154 = qvalue(elt(env, 2)); /* nil */
    v155 = ncons(v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v154 = qvalue(elt(env, 3)); /* locls!* */
    v154 = acons(stack[0], v155, v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    qvalue(elt(env, 3)) = v154; /* locls!* */
    goto v139;

v117:
    v154 = nil;
    { popv(5); return onevalue(v154); }
/* error exit handlers */
v156:
    popv(5);
    return nil;
}



/* Code for rl_bettergaussp */

static Lisp_Object CC_rl_bettergaussp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v77;
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
    v106 = v1;
    v77 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_bettergaussp!* */
    v106 = list2(v77, v106);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-1];
    {
        Lisp_Object v36 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v36, v106);
    }
/* error exit handlers */
v56:
    popv(2);
    return nil;
}



/* Code for tayexp!-minus */

static Lisp_Object CC_tayexpKminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v82;
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
    v78 = stack[0];
    if (!consp(v78)) goto v68;
    v78 = stack[0];
    stack[-1] = qcar(v78);
    v78 = stack[0];
    v78 = qcdr(v78);
    v78 = qcar(v78);
    fn = elt(env, 1); /* !:minus */
    v82 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v43;
    v78 = stack[0];
    v78 = qcdr(v78);
    v78 = qcdr(v78);
    {
        Lisp_Object v42 = stack[-1];
        popv(2);
        return list2star(v42, v82, v78);
    }

v68:
    v78 = stack[0];
    popv(2);
    return negate(v78);
/* error exit handlers */
v43:
    popv(2);
    return nil;
}



/* Code for matpri */

static Lisp_Object CC_matpri(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matpri");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v103 = v0;
/* end of prologue */
    v104 = qcdr(v103);
    v103 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* matpri1 */
        return (*qfn2(fn))(qenv(fn), v104, v103);
    }
}



/* Code for ev_lexcomp */

static Lisp_Object CC_ev_lexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v114;
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

v93:
    v159 = stack[-1];
    if (v159 == nil) goto v102;
    v159 = stack[-1];
    v114 = qcar(v159);
    v159 = stack[0];
    v159 = qcar(v159);
    v159 = Leqn(nil, v114, v159);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    if (v159 == nil) goto v125;
    v159 = stack[-1];
    v159 = qcdr(v159);
    stack[-1] = v159;
    v159 = stack[0];
    v159 = qcdr(v159);
    stack[0] = v159;
    goto v93;

v125:
    v159 = stack[-1];
    v114 = qcar(v159);
    v159 = stack[0];
    v159 = qcar(v159);
    if (((int32_t)(v114)) > ((int32_t)(v159))) goto v78;
    v159 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v159); }

v78:
    v159 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v159); }

v102:
    v159 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v159); }
/* error exit handlers */
v41:
    popv(3);
    return nil;
}



/* Code for cl_sacatl */

static Lisp_Object MS_CDECL CC_cl_sacatl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v91, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v149, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_sacatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_sacatl");
#endif
    if (stack >= stacklimit)
    {
        push3(v91,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v91);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v91;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v160:
    v137 = stack[-1];
    if (v137 == nil) goto v158;
    v149 = stack[-2];
    v137 = stack[-1];
    fn = elt(env, 6); /* rl_sacatlp */
    v137 = (*qfn2(fn))(qenv(fn), v149, v137);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    if (v137 == nil) goto v124;
    v150 = stack[-2];
    v137 = stack[-1];
    v149 = qcar(v137);
    v137 = stack[0];
    fn = elt(env, 7); /* rl_sacat */
    v137 = (*qfnn(fn))(qenv(fn), 3, v150, v149, v137);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    v150 = v137;
    v137 = v150;
    if (v137 == nil) goto v40;
    v149 = v150;
    v137 = elt(env, 3); /* (keep1 keep) */
    v137 = Lmemq(nil, v149, v137);
    if (v137 == nil) goto v67;
    v149 = elt(env, 4); /* keep1 */
    v137 = stack[-1];
    v137 = qcdr(v137);
    popv(4);
    return cons(v149, v137);

v67:
    v149 = v150;
    v137 = elt(env, 5); /* keep2 */
    if (v149 == v137) goto v161;
    v149 = v150;
    v137 = stack[-1];
    v137 = qcdr(v137);
    popv(4);
    return cons(v149, v137);

v161:
    v149 = qvalue(elt(env, 2)); /* nil */
    v137 = stack[-1];
    v137 = qcdr(v137);
    popv(4);
    return cons(v149, v137);

v40:
    v150 = stack[-2];
    v137 = stack[-1];
    v149 = qcdr(v137);
    v137 = stack[0];
    stack[-2] = v150;
    stack[-1] = v149;
    stack[0] = v137;
    goto v160;

v124:
    v149 = qvalue(elt(env, 2)); /* nil */
    v137 = stack[-1];
    popv(4);
    return cons(v149, v137);

v158:
    v137 = elt(env, 1); /* (nil) */
    { popv(4); return onevalue(v137); }
/* error exit handlers */
v28:
    popv(4);
    return nil;
}



/* Code for matrixrowom */

static Lisp_Object CC_matrixrowom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124;
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
    v124 = stack[0];
    if (v124 == nil) goto v93;
    v124 = elt(env, 1); /* "<OMA>" */
    fn = elt(env, 6); /* printout */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-1];
    v124 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 7); /* indent!* */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-1];
    v124 = elt(env, 3); /* "<OMS cd=""linalg1"" name=""matrixrow""/>" */
    fn = elt(env, 6); /* printout */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-1];
    v124 = stack[0];
    v124 = qcar(v124);
    fn = elt(env, 8); /* multiom */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-1];
    v124 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 7); /* indent!* */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-1];
    v124 = elt(env, 5); /* "</OMA>" */
    fn = elt(env, 6); /* printout */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-1];
    v124 = stack[0];
    v124 = qcdr(v124);
    v124 = CC_matrixrowom(env, v124);
    nil = C_nil;
    if (exception_pending()) goto v78;
    goto v93;

v93:
    v124 = nil;
    { popv(2); return onevalue(v124); }
/* error exit handlers */
v78:
    popv(2);
    return nil;
}



/* Code for n_nary */

static Lisp_Object CC_n_nary(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v59;
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
    v146 = stack[-1];
    v59 = qcar(v146);
    v146 = elt(env, 1); /* e */
    if (v59 == v146) goto v56;
    v146 = qvalue(elt(env, 3)); /* nil */
    goto v51;

v51:
    if (v146 == nil) goto v128;
    v146 = stack[-1];
    v59 = qcdr(v146);
    v146 = elt(env, 4); /* exp */
    fn = elt(env, 10); /* unary */
    v146 = (*qfn2(fn))(qenv(fn), v59, v146);
    nil = C_nil;
    if (exception_pending()) goto v72;
    goto v117;

v117:
    v146 = nil;
    { popv(3); return onevalue(v146); }

v128:
    v146 = elt(env, 5); /* "<apply>" */
    fn = elt(env, 11); /* printout */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-2];
    v146 = elt(env, 6); /* "<" */
    v146 = Lprinc(nil, v146);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-2];
    v146 = stack[0];
    v146 = Lprinc(nil, v146);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-2];
    v146 = elt(env, 7); /* "/>" */
    v146 = Lprinc(nil, v146);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-2];
    v59 = qvalue(elt(env, 8)); /* indent */
    v146 = (Lisp_Object)49; /* 3 */
    v146 = plus2(v59, v146);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-2];
    qvalue(elt(env, 8)) = v146; /* indent */
    v146 = stack[-1];
    fn = elt(env, 12); /* multi_elem */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-2];
    v59 = qvalue(elt(env, 8)); /* indent */
    v146 = (Lisp_Object)49; /* 3 */
    v146 = difference2(v59, v146);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-2];
    qvalue(elt(env, 8)) = v146; /* indent */
    v146 = elt(env, 9); /* "</apply>" */
    fn = elt(env, 11); /* printout */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v72;
    goto v117;

v56:
    v59 = stack[0];
    v146 = elt(env, 2); /* power */
    v146 = (v59 == v146 ? lisp_true : nil);
    goto v51;
/* error exit handlers */
v72:
    popv(3);
    return nil;
}



/* Code for exptplus */

static Lisp_Object CC_exptplus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v40, v38;
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
    v40 = v1;
    v38 = v0;
/* end of prologue */
    v39 = v38;
    if (!consp(v39)) goto v93;
    v39 = v40;
    if (!consp(v39)) goto v74;
    v39 = elt(env, 1); /* "Bad exponent sum" */
    {
        fn = elt(env, 2); /* interr */
        return (*qfn1(fn))(qenv(fn), v39);
    }

v74:
    v39 = v38;
    v39 = qcar(v39);
    v39 = plus2(v39, v40);
    errexit();
    return ncons(v39);

v93:
    v39 = v40;
    if (!consp(v39)) goto v111;
    v39 = v38;
    v40 = qcar(v40);
    v39 = plus2(v39, v40);
    errexit();
    return ncons(v39);

v111:
    v39 = v38;
    return plus2(v39, v40);
}



/* Code for reform!-minus */

static Lisp_Object CC_reformKminus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v149, v150;
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
    v137 = stack[0];
    if (v137 == nil) goto v158;
    v137 = stack[-1];
    v137 = (v137 == nil ? lisp_true : nil);
    goto v102;

v102:
    if (!(v137 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v137 = stack[-1];
    v137 = qcar(v137);
    v149 = stack[0];
    v150 = qcar(v149);
    v149 = elt(env, 2); /* minus */
    if (!consp(v150)) goto v146;
    v150 = qcar(v150);
    if (!(v150 == v149)) goto v146;
    v150 = v137;
    v149 = elt(env, 3); /* quotient */
    if (!consp(v150)) goto v32;
    v150 = qcar(v150);
    if (!(v150 == v149)) goto v32;
    v149 = v137;
    v149 = qcdr(v149);
    v150 = qcar(v149);
    v149 = elt(env, 2); /* minus */
    v149 = Leqcar(nil, v150, v149);
    env = stack[-3];
    goto v118;

v118:
    if (v149 == nil) goto v85;
    stack[-2] = elt(env, 2); /* minus */
    v150 = elt(env, 3); /* quotient */
    v149 = v137;
    v149 = qcdr(v149);
    v149 = qcar(v149);
    v149 = qcdr(v149);
    v149 = qcar(v149);
    v137 = qcdr(v137);
    v137 = qcdr(v137);
    v137 = qcar(v137);
    v137 = list3(v150, v149, v137);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    v137 = list2(stack[-2], v137);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    stack[-2] = v137;
    goto v151;

v151:
    v137 = stack[-1];
    v149 = qcdr(v137);
    v137 = stack[0];
    v137 = qcdr(v137);
    v137 = CC_reformKminus(env, v149, v137);
    nil = C_nil;
    if (exception_pending()) goto v28;
    {
        Lisp_Object v141 = stack[-2];
        popv(4);
        return cons(v141, v137);
    }

v85:
    stack[-2] = v137;
    goto v151;

v32:
    v149 = qvalue(elt(env, 4)); /* nil */
    goto v118;

v146:
    v149 = qvalue(elt(env, 4)); /* nil */
    goto v118;

v158:
    v137 = qvalue(elt(env, 1)); /* t */
    goto v102;
/* error exit handlers */
v28:
    popv(4);
    return nil;
}



/* Code for matrixp */

static Lisp_Object CC_matrixp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v77;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v106 = v0;
/* end of prologue */
    v77 = v106;
    v106 = elt(env, 1); /* mat */
    if (!consp(v77)) goto v68;
    v77 = qcar(v77);
    if (!(v77 == v106)) goto v68;
    v106 = qvalue(elt(env, 3)); /* t */
    return onevalue(v106);

v68:
    v106 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v106);
}



/* Code for evload */

static Lisp_Object CC_evload(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45;
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

v68:
    v45 = stack[0];
    if (v45 == nil) goto v81;
    v45 = stack[0];
    v45 = qcar(v45);
    v45 = Lload_module(nil, v45);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-1];
    v45 = stack[0];
    v45 = qcdr(v45);
    stack[0] = v45;
    goto v68;

v81:
    v45 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v45); }
/* error exit handlers */
v106:
    popv(2);
    return nil;
}



/* Code for ncoeffs */

static Lisp_Object CC_ncoeffs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v59;
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
    v59 = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = nil;
    v146 = (Lisp_Object)1; /* 0 */
    stack[-2] = v146;
    v146 = v59;
    stack[-1] = v146;
    goto v103;

v103:
    v146 = stack[-1];
    if (v146 == nil) goto v101;
    v146 = stack[-1];
    v146 = qcar(v146);
    stack[0] = v146;
    v146 = stack[0];
    v146 = qcar(v146);
    stack[-4] = v146;
    goto v43;

v43:
    v59 = stack[-2];
    v146 = stack[-4];
    v146 = (Lisp_Object)lessp2(v59, v146);
    nil = C_nil;
    if (exception_pending()) goto v88;
    v146 = v146 ? lisp_true : nil;
    env = stack[-5];
    if (v146 == nil) goto v119;
    v59 = qvalue(elt(env, 1)); /* nil */
    v146 = stack[-3];
    v146 = cons(v59, v146);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-5];
    stack[-3] = v146;
    v146 = stack[-2];
    v146 = add1(v146);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-5];
    stack[-2] = v146;
    goto v43;

v119:
    v146 = stack[-2];
    v146 = add1(v146);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-5];
    stack[-2] = v146;
    v146 = stack[0];
    v59 = qcdr(v146);
    v146 = stack[-3];
    v146 = cons(v59, v146);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-5];
    stack[-3] = v146;
    v146 = stack[-1];
    v146 = qcdr(v146);
    stack[-1] = v146;
    goto v103;

v101:
    v59 = stack[-4];
    v146 = stack[-3];
    popv(6);
    return cons(v59, v146);
/* error exit handlers */
v88:
    popv(6);
    return nil;
}



/* Code for getphystypetimes */

static Lisp_Object CC_getphystypetimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v159;
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
    v144 = stack[0];
    fn = elt(env, 3); /* collectphystype */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    fn = elt(env, 4); /* deleteall */
    v144 = (*qfn2(fn))(qenv(fn), stack[-1], v144);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    v159 = v144;
    if (v144 == nil) goto v81;
    v144 = v159;
    v144 = qcdr(v144);
    if (v144 == nil) goto v77;
    stack[-1] = elt(env, 0); /* getphystypetimes */
    v159 = elt(env, 2); /* "PHYSOP type mismatch in" */
    v144 = stack[0];
    v144 = list2(v159, v144);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    fn = elt(env, 5); /* rederr2 */
    v144 = (*qfn2(fn))(qenv(fn), stack[-1], v144);
    nil = C_nil;
    if (exception_pending()) goto v97;
    v144 = nil;
    { popv(3); return onevalue(v144); }

v77:
    v144 = v159;
    v144 = qcar(v144);
    { popv(3); return onevalue(v144); }

v81:
    v144 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v144); }
/* error exit handlers */
v97:
    popv(3);
    return nil;
}



/* Code for prop!-simp1 */

static Lisp_Object MS_CDECL CC_propKsimp1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v91, Lisp_Object v22,
                         Lisp_Object v68, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v141, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "prop-simp1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prop-simp1");
#endif
    if (stack >= stacklimit)
    {
        push5(v68,v22,v91,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v91,v22,v68);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v68;
    stack[0] = v22;
    stack[-5] = v91;
    stack[-2] = v1;
    stack[-6] = v0;
/* end of prologue */

v160:
    v28 = stack[-2];
    if (v28 == nil) goto v76;
    v141 = stack[-6];
    v28 = stack[-2];
    v28 = qcar(v28);
    fn = elt(env, 1); /* prop!-simp2 */
    v28 = (*qfn2(fn))(qenv(fn), v141, v28);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-8];
    stack[-3] = v28;
    v28 = stack[-3];
    if (v28 == nil) goto v132;
    v28 = stack[-3];
    stack[-6] = qcdr(v28);
    v28 = stack[-2];
    stack[-2] = qcdr(v28);
    stack[-1] = stack[-5];
    v28 = stack[0];
    stack[0] = add1(v28);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-8];
    v28 = stack[-3];
    stack[-7] = qcar(v28);
    stack[-3] = (Lisp_Object)-15; /* -1 */
    v28 = stack[-5];
    v28 = Llength(nil, v28);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-8];
    v28 = Lexpt(nil, stack[-3], v28);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-8];
    v28 = times2(stack[-4], v28);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-8];
    v28 = times2(stack[-7], v28);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-8];
    stack[-5] = stack[-1];
    stack[-4] = v28;
    goto v160;

v132:
    stack[-3] = stack[-6];
    v28 = stack[-2];
    stack[-1] = qcdr(v28);
    v28 = stack[-2];
    v141 = qcar(v28);
    v28 = stack[-5];
    v142 = cons(v141, v28);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-8];
    v141 = stack[0];
    v28 = stack[-4];
    stack[-6] = stack[-3];
    stack[-2] = stack[-1];
    stack[-5] = v142;
    stack[0] = v141;
    stack[-4] = v28;
    goto v160;

v76:
    v141 = stack[0];
    v28 = stack[-4];
    stack[0] = list2(v141, v28);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-8];
    stack[-1] = stack[-6];
    v28 = stack[-5];
    v28 = Lreverse(nil, v28);
    nil = C_nil;
    if (exception_pending()) goto v163;
    {
        Lisp_Object v23 = stack[0];
        Lisp_Object v24 = stack[-1];
        popv(9);
        return list2star(v23, v24, v28);
    }
/* error exit handlers */
v163:
    popv(9);
    return nil;
}



/* Code for comblog */

static Lisp_Object CC_comblog(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v166;
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
    goto v93;

v93:
    v165 = stack[0];
    if (!consp(v165)) goto v104;
    v165 = stack[0];
    v166 = qcar(v165);
    v165 = qvalue(elt(env, 2)); /* domainlist!* */
    v165 = Lmemq(nil, v166, v165);
    goto v103;

v103:
    if (v165 == nil) goto v128;
    v166 = stack[-1];
    v165 = stack[0];
    {
        popv(4);
        fn = elt(env, 7); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v166, v165);
    }

v128:
    v165 = stack[0];
    v166 = qcar(v165);
    v165 = elt(env, 3); /* plus */
    if (v166 == v165) goto v37;
    v165 = stack[0];
    v166 = qcar(v165);
    v165 = elt(env, 4); /* times */
    if (v166 == v165) goto v53;
    v165 = qvalue(elt(env, 6)); /* nil */
    goto v74;

v74:
    if (v165 == nil) goto v167;
    stack[-2] = stack[-1];
    v165 = stack[0];
    fn = elt(env, 8); /* simp!* */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    stack[-1] = v165;
    v165 = stack[-1];
    v165 = qcar(v165);
    fn = elt(env, 9); /* clogf */
    stack[0] = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    v165 = stack[-1];
    v165 = qcdr(v165);
    fn = elt(env, 9); /* clogf */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    v165 = cons(stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    fn = elt(env, 10); /* prepsq!* */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    {
        Lisp_Object v154 = stack[-2];
        popv(4);
        fn = elt(env, 7); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v154, v165);
    }

v167:
    v165 = stack[0];
    v165 = qcar(v165);
    v166 = CC_comblog(env, v165);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    v165 = stack[-1];
    v165 = cons(v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    stack[-1] = v165;
    v165 = stack[0];
    v165 = qcdr(v165);
    stack[0] = v165;
    goto v93;

v53:
    v165 = stack[0];
    fn = elt(env, 8); /* simp!* */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    v165 = qcar(v165);
    v166 = v165;
    v165 = v166;
    if (!consp(v165)) goto v71;
    v165 = v166;
    v165 = qcar(v165);
    v165 = (consp(v165) ? nil : lisp_true);
    goto v153;

v153:
    if (v165 == nil) goto v100;
    v165 = qvalue(elt(env, 6)); /* nil */
    goto v74;

v100:
    v165 = v166;
    v165 = qcar(v165);
    v165 = qcar(v165);
    v166 = qcar(v165);
    v165 = elt(env, 5); /* log */
    v165 = Leqcar(nil, v166, v165);
    env = stack[-3];
    goto v74;

v71:
    v165 = qvalue(elt(env, 1)); /* t */
    goto v153;

v37:
    v165 = qvalue(elt(env, 1)); /* t */
    goto v74;

v104:
    v165 = qvalue(elt(env, 1)); /* t */
    goto v103;
/* error exit handlers */
v21:
    popv(4);
    return nil;
}



/* Code for st_ad_numsorttree */

static Lisp_Object CC_st_ad_numsorttree(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v77;
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
    v106 = v0;
/* end of prologue */
    fn = elt(env, 1); /* st_ad_numsorttree1 */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    errexit();
    v77 = v106;
    v77 = qcar(v77);
    v106 = qcdr(v106);
    v106 = qcar(v106);
    return cons(v77, v106);
}



/* Code for qtypnm */

static Lisp_Object CC_qtypnm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v176, v177, v178;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qtypnm");
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
    v177 = stack[-3];
    v176 = elt(env, 1); /* function */
    v176 = Lflagp(nil, v177, v176);
    env = stack[-6];
    if (v176 == nil) goto v121;
    v177 = stack[-4];
    v176 = elt(env, 2); /* seen */
    v176 = Lflagp(nil, v177, v176);
    env = stack[-6];
    if (!(v176 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v176 = stack[-4];
    v177 = ncons(v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v176 = elt(env, 2); /* seen */
    v176 = Lflag(nil, v177, v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v177 = stack[-4];
    v176 = qvalue(elt(env, 3)); /* seen!* */
    v176 = cons(v177, v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    qvalue(elt(env, 3)) = v176; /* seen!* */
    { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }

v121:
    v177 = stack[-3];
    v176 = elt(env, 4); /* tseen */
    v176 = get(v177, v176);
    env = stack[-6];
    stack[-2] = v176;
    if (v176 == nil) goto v73;
    v177 = stack[-4];
    v176 = stack[-2];
    v176 = qcdr(v176);
    v176 = Latsoc(nil, v177, v176);
    stack[-5] = v176;
    if (v176 == nil) goto v73;
    v176 = stack[-5];
    v176 = qcdr(v176);
    { popv(7); return onevalue(v176); }

v73:
    v176 = stack[-2];
    if (!(v176 == nil)) goto v88;
    stack[-1] = elt(env, 5); /* !( */
    v176 = stack[-3];
    stack[0] = Lexplode(nil, v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v176 = elt(env, 6); /* !) */
    v176 = ncons(v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v176 = Lnconc(nil, stack[0], v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v176 = cons(stack[-1], v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v176 = ncons(v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    stack[-2] = v176;
    v178 = stack[-3];
    v177 = elt(env, 4); /* tseen */
    v176 = stack[-2];
    v176 = Lputprop(nil, 3, v178, v177, v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v177 = stack[-3];
    v176 = qvalue(elt(env, 7)); /* tseen!* */
    v176 = cons(v177, v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    qvalue(elt(env, 7)) = v176; /* tseen!* */
    goto v88;

v88:
    v176 = stack[-4];
    v176 = Lexplode(nil, v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    stack[-1] = v176;
    v176 = Lcompress(nil, v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    stack[-5] = v176;
    stack[0] = stack[-2];
    v178 = stack[-4];
    v177 = stack[-5];
    v176 = stack[-2];
    v176 = qcdr(v176);
    v176 = acons(v178, v177, v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v176 = Lrplacd(nil, stack[0], v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v176 = stack[-2];
    v177 = qcar(v176);
    v176 = stack[-1];
    v176 = Lappend(nil, v177, v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    stack[-2] = v176;
    stack[-1] = stack[-5];
    stack[0] = elt(env, 8); /* rccnam */
    v176 = stack[-2];
    v177 = Llength(nil, v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v176 = stack[-2];
    v176 = cons(v177, v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v176 = Lputprop(nil, 3, stack[-1], stack[0], v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v178 = stack[-3];
    v177 = elt(env, 9); /* funs */
    v176 = stack[-5];
    fn = elt(env, 10); /* traput */
    v176 = (*qfnn(fn))(qenv(fn), 3, v178, v177, v176);
    nil = C_nil;
    if (exception_pending()) goto v179;
    { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
/* error exit handlers */
v179:
    popv(7);
    return nil;
}



/* Code for monomgetfirstmultivar */

static Lisp_Object CC_monomgetfirstmultivar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v125, v126;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monomgetfirstmultivar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v125 = v0;
/* end of prologue */
    v126 = v125;
    v82 = (Lisp_Object)17; /* 1 */
    v82 = *(Lisp_Object *)((char *)v126 + (CELL-TAG_VECTOR) + ((int32_t)v82/(16/CELL)));
    v82 = qcar(v82);
    if (v82 == nil) goto v124;
    v82 = (Lisp_Object)17; /* 1 */
    v82 = *(Lisp_Object *)((char *)v125 + (CELL-TAG_VECTOR) + ((int32_t)v82/(16/CELL)));
    v82 = qcar(v82);
    return onevalue(v82);

v124:
    v82 = (Lisp_Object)17; /* 1 */
    return onevalue(v82);
}



/* Code for om2ir */

static Lisp_Object MS_CDECL CC_om2ir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v31;
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
    v32 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v32;
    v32 = elt(env, 2); /* (safe_atts char ch atts count temp space temp2) 
*/
    fn = elt(env, 13); /* fluid */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-1];
    v31 = elt(env, 3); /* !! */
    v32 = (Lisp_Object)513; /* 32 */
    v32 = list2(v31, v32);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-1];
    v32 = Lcompress(nil, v32);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-1];
    qvalue(elt(env, 4)) = v32; /* space */
    v32 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 5)) = v32; /* count */
    v32 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-1];
    qvalue(elt(env, 6)) = v32; /* ch */
    v32 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 7)) = v32; /* temp2 */
    fn = elt(env, 14); /* lex */
    v32 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-1];
    v31 = qvalue(elt(env, 8)); /* char */
    v32 = elt(env, 9); /* (o m o b j) */
    if (equal(v31, v32)) goto v36;
    v31 = elt(env, 10); /* "<omobj>" */
    v32 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 15); /* errorml */
    v32 = (*qfn2(fn))(qenv(fn), v31, v32);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-1];
    goto v56;

v56:
    fn = elt(env, 14); /* lex */
    v32 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-1];
    v31 = qvalue(elt(env, 8)); /* char */
    v32 = elt(env, 11); /* (!/ o m o b j) */
    if (equal(v31, v32)) goto v41;
    v31 = elt(env, 12); /* "</omobj>" */
    v32 = (Lisp_Object)305; /* 19 */
    fn = elt(env, 15); /* errorml */
    v32 = (*qfn2(fn))(qenv(fn), v31, v32);
    nil = C_nil;
    if (exception_pending()) goto v146;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v41:
    v32 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v146;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v36:
    fn = elt(env, 14); /* lex */
    v32 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-1];
    fn = elt(env, 16); /* omobj */
    v32 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-1];
    stack[0] = v32;
    goto v56;
/* error exit handlers */
v146:
    popv(2);
    return nil;
}



/* Code for ps!:depvar */

static Lisp_Object CC_psTdepvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v39, v40;
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
    v39 = v0;
/* end of prologue */
    v127 = v39;
    if (!consp(v127)) goto v102;
    v127 = v39;
    v40 = qcar(v127);
    v127 = elt(env, 2); /* !:ps!: */
    if (v40 == v127) goto v99;
    v127 = v39;
    v40 = qcar(v127);
    v127 = elt(env, 3); /* dname */
    v127 = get(v40, v127);
    env = stack[0];
    goto v81;

v81:
    if (v127 == nil) goto v114;
    v127 = qvalue(elt(env, 4)); /* nil */
    { popv(1); return onevalue(v127); }

v114:
    v127 = (Lisp_Object)33; /* 2 */
    {
        popv(1);
        fn = elt(env, 5); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v39, v127);
    }

v99:
    v127 = qvalue(elt(env, 4)); /* nil */
    goto v81;

v102:
    v127 = qvalue(elt(env, 1)); /* t */
    goto v81;
}



/* Code for crn!:minusp */

static Lisp_Object CC_crnTminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v119, v124;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crn:minusp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v124 = v0;
/* end of prologue */
    v107 = v124;
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v119 = qcar(v107);
    v107 = (Lisp_Object)1; /* 0 */
    if (v119 == v107) goto v68;
    v107 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v107);

v68:
    v107 = v124;
    v107 = qcdr(v107);
    v107 = qcar(v107);
    v107 = qcar(v107);
        return Lminusp(nil, v107);
}



/* Code for rootextractsq */

static Lisp_Object CC_rootextractsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v52;
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
    v52 = v0;
/* end of prologue */
    v124 = v52;
    v124 = qcar(v124);
    if (v124 == nil) { popv(3); return onevalue(v52); }
    v124 = v52;
    fn = elt(env, 1); /* subs2q */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-2];
    stack[-1] = v124;
    v124 = stack[-1];
    v124 = qcar(v124);
    fn = elt(env, 2); /* rootextractf */
    stack[0] = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-2];
    v124 = stack[-1];
    v124 = qcdr(v124);
    fn = elt(env, 2); /* rootextractf */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v125;
    {
        Lisp_Object v126 = stack[0];
        popv(3);
        return cons(v126, v124);
    }
/* error exit handlers */
v125:
    popv(3);
    return nil;
}



/* Code for delhisto */

static Lisp_Object CC_delhisto(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v189, v63, v190;
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
    v63 = qvalue(elt(env, 2)); /* maxvar */
    v189 = stack[-2];
    v189 = plus2(v63, v189);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v63 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v189/(16/CELL)));
    v189 = (Lisp_Object)1; /* 0 */
    v189 = *(Lisp_Object *)((char *)v63 + (CELL-TAG_VECTOR) + ((int32_t)v189/(16/CELL)));
    if (v189 == nil) goto v93;
    v63 = stack[-2];
    v189 = (Lisp_Object)1; /* 0 */
    v189 = (Lisp_Object)geq2(v63, v189);
    nil = C_nil;
    if (exception_pending()) goto v191;
    v189 = v189 ? lisp_true : nil;
    env = stack[-4];
    if (v189 == nil) goto v93;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v63 = qvalue(elt(env, 2)); /* maxvar */
    v189 = stack[-2];
    v189 = plus2(v63, v189);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v63 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v189/(16/CELL)));
    v189 = (Lisp_Object)113; /* 7 */
    v189 = *(Lisp_Object *)((char *)v63 + (CELL-TAG_VECTOR) + ((int32_t)v189/(16/CELL)));
    v189 = qcar(v189);
    stack[-3] = v189;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v63 = qvalue(elt(env, 2)); /* maxvar */
    v189 = stack[-2];
    v189 = plus2(v63, v189);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v63 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v189/(16/CELL)));
    v189 = (Lisp_Object)113; /* 7 */
    v189 = *(Lisp_Object *)((char *)v63 + (CELL-TAG_VECTOR) + ((int32_t)v189/(16/CELL)));
    v189 = qcdr(v189);
    stack[-1] = v189;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v63 = qvalue(elt(env, 2)); /* maxvar */
    v189 = stack[-2];
    v189 = plus2(v63, v189);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v63 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v189/(16/CELL)));
    v189 = (Lisp_Object)17; /* 1 */
    v189 = *(Lisp_Object *)((char *)v63 + (CELL-TAG_VECTOR) + ((int32_t)v189/(16/CELL)));
    v63 = qcdr(v189);
    v189 = (Lisp_Object)3201; /* 200 */
    fn = elt(env, 4); /* min */
    v189 = (*qfn2(fn))(qenv(fn), v63, v189);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v63 = stack[-3];
    if (v63 == nil) goto v192;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v63 = qvalue(elt(env, 2)); /* maxvar */
    v189 = stack[-3];
    v189 = plus2(v63, v189);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v63 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v189/(16/CELL)));
    v189 = (Lisp_Object)113; /* 7 */
    v63 = *(Lisp_Object *)((char *)v63 + (CELL-TAG_VECTOR) + ((int32_t)v189/(16/CELL)));
    v189 = stack[-1];
    v189 = Lrplacd(nil, v63, v189);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    goto v142;

v142:
    v189 = stack[-1];
    if (v189 == nil) goto v61;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v63 = qvalue(elt(env, 2)); /* maxvar */
    v189 = stack[-1];
    v189 = plus2(v63, v189);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v63 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v189/(16/CELL)));
    v189 = (Lisp_Object)113; /* 7 */
    v63 = *(Lisp_Object *)((char *)v63 + (CELL-TAG_VECTOR) + ((int32_t)v189/(16/CELL)));
    v189 = stack[-3];
    v189 = Lrplaca(nil, v63, v189);
    nil = C_nil;
    if (exception_pending()) goto v191;
    goto v61;

v61:
    v189 = nil;
    { popv(5); return onevalue(v189); }

v192:
    v190 = qvalue(elt(env, 3)); /* codhisto */
    v63 = v189;
    v189 = stack[-1];
    *(Lisp_Object *)((char *)v190 + (CELL-TAG_VECTOR) + ((int32_t)v63/(16/CELL))) = v189;
    goto v142;

v93:
    v189 = nil;
    { popv(5); return onevalue(v189); }
/* error exit handlers */
v191:
    popv(5);
    return nil;
}



/* Code for rmsubs */

static Lisp_Object MS_CDECL CC_rmsubs(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v45;
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
    v45 = qvalue(elt(env, 1)); /* !*sqvar!* */
    v44 = qvalue(elt(env, 2)); /* nil */
    v44 = Lrplaca(nil, v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[0];
    v44 = qvalue(elt(env, 3)); /* t */
    v44 = ncons(v44);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[0];
    qvalue(elt(env, 1)) = v44; /* !*sqvar!* */
    v44 = qvalue(elt(env, 2)); /* nil */
    v44 = ncons(v44);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[0];
    qvalue(elt(env, 4)) = v44; /* alglist!* */
    v44 = nil;
    { popv(1); return onevalue(v44); }
/* error exit handlers */
v94:
    popv(1);
    return nil;
}



/* Code for setdmode */

static Lisp_Object CC_setdmode(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v198, v181, v182;
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
    v181 = stack[-1];
    v198 = elt(env, 1); /* dname */
    v198 = get(v181, v198);
    env = stack[-3];
    stack[-2] = v198;
    if (v198 == nil) goto v55;
    v198 = stack[-2];
    stack[-1] = v198;
    goto v55;

v55:
    v181 = stack[-1];
    v198 = elt(env, 2); /* complex!-rational */
    if (v181 == v198) goto v56;
    v181 = stack[-1];
    v198 = elt(env, 6); /* complex!-rounded */
    if (v181 == v198) goto v70;
    v181 = stack[-1];
    v198 = elt(env, 8); /* tag */
    v198 = get(v181, v198);
    env = stack[-3];
    if (!(v198 == nil)) goto v199;
    v182 = elt(env, 9); /* "Domain mode error:" */
    v181 = stack[-1];
    v198 = elt(env, 10); /* "is not a domain mode" */
    v198 = list3(v182, v181, v198);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    v181 = v198;
    v198 = v181;
    qvalue(elt(env, 11)) = v198; /* errmsg!* */
    v198 = qvalue(elt(env, 12)); /* !*protfg */
    if (!(v198 == nil)) goto v147;
    v198 = v181;
    fn = elt(env, 16); /* lprie */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    goto v147;

v147:
    v198 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    goto v199;

v199:
    v181 = stack[-1];
    v198 = elt(env, 13); /* package!-name */
    v198 = get(v181, v198);
    env = stack[-3];
    stack[-2] = v198;
    if (v198 == nil) goto v200;
    v198 = stack[-2];
    fn = elt(env, 17); /* load!-package */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    goto v200;

v200:
    v181 = stack[-1];
    v198 = elt(env, 4); /* complex */
    if (v181 == v198) goto v201;
    v198 = qvalue(elt(env, 15)); /* !*complex */
    goto v18;

v18:
    if (v198 == nil) goto v168;
    v181 = stack[-1];
    v198 = stack[0];
    {
        popv(4);
        fn = elt(env, 18); /* setcmpxmode */
        return (*qfn2(fn))(qenv(fn), v181, v198);
    }

v168:
    v181 = stack[-1];
    v198 = stack[0];
    {
        popv(4);
        fn = elt(env, 19); /* setdmode1 */
        return (*qfn2(fn))(qenv(fn), v181, v198);
    }

v201:
    v198 = qvalue(elt(env, 14)); /* t */
    goto v18;

v70:
    v198 = qvalue(elt(env, 3)); /* dmode!* */
    stack[-2] = v198;
    if (v198 == nil) goto v35;
    v181 = stack[-2];
    v198 = elt(env, 1); /* dname */
    v198 = get(v181, v198);
    env = stack[-3];
    stack[-2] = v198;
    goto v35;

v35:
    v181 = elt(env, 4); /* complex */
    v198 = stack[0];
    fn = elt(env, 20); /* onoff */
    v198 = (*qfn2(fn))(qenv(fn), v181, v198);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    v181 = elt(env, 7); /* rounded */
    v198 = stack[0];
    fn = elt(env, 20); /* onoff */
    v198 = (*qfn2(fn))(qenv(fn), v181, v198);
    nil = C_nil;
    if (exception_pending()) goto v13;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v56:
    v198 = qvalue(elt(env, 3)); /* dmode!* */
    stack[-2] = v198;
    if (v198 == nil) goto v114;
    v181 = stack[-2];
    v198 = elt(env, 1); /* dname */
    v198 = get(v181, v198);
    env = stack[-3];
    stack[-2] = v198;
    goto v114;

v114:
    v181 = elt(env, 4); /* complex */
    v198 = stack[0];
    fn = elt(env, 20); /* onoff */
    v198 = (*qfn2(fn))(qenv(fn), v181, v198);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    v181 = elt(env, 5); /* rational */
    v198 = stack[0];
    fn = elt(env, 20); /* onoff */
    v198 = (*qfn2(fn))(qenv(fn), v181, v198);
    nil = C_nil;
    if (exception_pending()) goto v13;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v13:
    popv(4);
    return nil;
}



/* Code for bcminus!? */

static Lisp_Object CC_bcminusW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcminus?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v111 = v0;
/* end of prologue */
    v105 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v105 == nil) goto v68;
    v105 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v105);

v68:
    v105 = v111;
    v105 = qcar(v105);
    {
        fn = elt(env, 3); /* minusf */
        return (*qfn1(fn))(qenv(fn), v105);
    }
}



/* Code for gfdot */

static Lisp_Object CC_gfdot(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfdot");
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
    v109 = stack[-1];
    v109 = qcar(v109);
    if (!consp(v109)) goto v45;
    v109 = stack[-1];
    v101 = qcar(v109);
    v109 = stack[0];
    v109 = qcar(v109);
    fn = elt(env, 1); /* csl_timbf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v101, v109);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-3];
    v109 = stack[-1];
    v101 = qcdr(v109);
    v109 = stack[0];
    v109 = qcdr(v109);
    fn = elt(env, 1); /* csl_timbf */
    v109 = (*qfn2(fn))(qenv(fn), v101, v109);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-3];
    {
        Lisp_Object v31 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* plubf */
        return (*qfn2(fn))(qenv(fn), v31, v109);
    }

v45:
    v109 = stack[-1];
    v101 = qcar(v109);
    v109 = stack[0];
    v109 = qcar(v109);
    stack[-2] = times2(v101, v109);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-3];
    v109 = stack[-1];
    v101 = qcdr(v109);
    v109 = stack[0];
    v109 = qcdr(v109);
    v109 = times2(v101, v109);
    nil = C_nil;
    if (exception_pending()) goto v32;
    {
        Lisp_Object v145 = stack[-2];
        popv(4);
        return plus2(v145, v109);
    }
/* error exit handlers */
v32:
    popv(4);
    return nil;
}



/* Code for min0 */

static Lisp_Object CC_min0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for min0");
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
    v106 = v1;
    v77 = v0;
/* end of prologue */
    fn = elt(env, 1); /* min */
    v77 = (*qfn2(fn))(qenv(fn), v77, v106);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[0];
    v106 = (Lisp_Object)1; /* 0 */
    {
        popv(1);
        fn = elt(env, 2); /* max */
        return (*qfn2(fn))(qenv(fn), v77, v106);
    }
/* error exit handlers */
v76:
    popv(1);
    return nil;
}



/* Code for locate_member */

static Lisp_Object CC_locate_member(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v110, v128, v144;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for locate_member");
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
    v128 = v1;
    v144 = v0;
/* end of prologue */
    v110 = v144;
    v37 = v128;
    v37 = Lmember(nil, v110, v37);
    if (v37 == nil) goto v93;
    v110 = v144;
    v37 = v128;
    v37 = qcar(v37);
    if (equal(v110, v37)) goto v45;
    v37 = v144;
    v110 = v128;
    v110 = qcdr(v110);
    v37 = CC_locate_member(env, v37, v110);
    errexit();
    return add1(v37);

v45:
    v37 = (Lisp_Object)17; /* 1 */
    return onevalue(v37);

v93:
    v37 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v37);
}



/* Code for mv!-pow!-mv!-!+ */

static Lisp_Object CC_mvKpowKmvKL(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-mv-+");
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
    goto v117;

v117:
    v118 = stack[0];
    if (v118 == nil) goto v158;
    v99 = stack[-1];
    v118 = stack[0];
    v118 = qcar(v118);
    fn = elt(env, 1); /* mv!-pow!-mv!-term!-!+ */
    v99 = (*qfn2(fn))(qenv(fn), v99, v118);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    v118 = stack[-2];
    v118 = cons(v99, v118);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    stack[-2] = v118;
    v118 = stack[0];
    v118 = qcdr(v118);
    stack[0] = v118;
    goto v117;

v158:
    v118 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v118);
    }
/* error exit handlers */
v37:
    popv(4);
    return nil;
}



/* Code for mo_equal!? */

static Lisp_Object CC_mo_equalW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_equal?");
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
    v44 = v0;
/* end of prologue */
    v44 = qcar(v44);
    fn = elt(env, 1); /* mo!=shorten */
    stack[-1] = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-2];
    v44 = stack[0];
    v44 = qcar(v44);
    fn = elt(env, 1); /* mo!=shorten */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v106;
    v44 = (equal(stack[-1], v44) ? lisp_true : nil);
    { popv(3); return onevalue(v44); }
/* error exit handlers */
v106:
    popv(3);
    return nil;
}



/* Code for proper!-simpsqrt */

static Lisp_Object CC_properKsimpsqrt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for proper-simpsqrt");
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
    v103 = v0;
/* end of prologue */
    v104 = v103;
    v103 = elt(env, 0); /* proper!-simpsqrt */
    fn = elt(env, 1); /* carx */
    v103 = (*qfn2(fn))(qenv(fn), v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* simpsqrti */
        return (*qfn1(fn))(qenv(fn), v103);
    }
/* error exit handlers */
v105:
    popv(1);
    return nil;
}



/* Code for createtriplewithancestor */

static Lisp_Object CC_createtriplewithancestor(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v73, v53;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for createtriplewithancestor");
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
    v38 = (Lisp_Object)49; /* 3 */
    v38 = Lmkvect(nil, v38);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-3];
    stack[-2] = v38;
    v53 = stack[-2];
    v73 = (Lisp_Object)1; /* 0 */
    v38 = qvalue(elt(env, 1)); /* fluidbibasistripleid */
    *(Lisp_Object *)((char *)v53 + (CELL-TAG_VECTOR) + ((int32_t)v73/(16/CELL))) = v38;
    v53 = stack[-2];
    v73 = (Lisp_Object)17; /* 1 */
    v38 = stack[-1];
    *(Lisp_Object *)((char *)v53 + (CELL-TAG_VECTOR) + ((int32_t)v73/(16/CELL))) = v38;
    v53 = stack[-2];
    v73 = (Lisp_Object)33; /* 2 */
    v38 = stack[0];
    *(Lisp_Object *)((char *)v53 + (CELL-TAG_VECTOR) + ((int32_t)v73/(16/CELL))) = v38;
    stack[-1] = stack[-2];
    stack[0] = (Lisp_Object)49; /* 3 */
    v38 = qvalue(elt(env, 2)); /* nil */
    v38 = ncons(v38);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-3];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v38;
    v38 = qvalue(elt(env, 1)); /* fluidbibasistripleid */
    v38 = (Lisp_Object)((int32_t)(v38) + 0x10);
    qvalue(elt(env, 1)) = v38; /* fluidbibasistripleid */
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v121:
    popv(4);
    return nil;
}



/* Code for aex_fromrp */

static Lisp_Object CC_aex_fromrp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_fromrp");
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
    v55 = v0;
/* end of prologue */
    stack[-2] = elt(env, 1); /* aex */
    stack[-1] = v55;
    fn = elt(env, 3); /* ctx_new */
    stack[0] = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-3];
    v107 = qvalue(elt(env, 2)); /* t */
    v55 = qvalue(elt(env, 2)); /* t */
    v55 = list2(v107, v55);
    nil = C_nil;
    if (exception_pending()) goto v78;
    {
        Lisp_Object v82 = stack[-2];
        Lisp_Object v125 = stack[-1];
        Lisp_Object v126 = stack[0];
        popv(4);
        return list3star(v82, v125, v126, v55);
    }
/* error exit handlers */
v78:
    popv(4);
    return nil;
}



/* Code for dvfsf_mk2 */

static Lisp_Object MS_CDECL CC_dvfsf_mk2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v91, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v45, v94;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dvfsf_mk2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_mk2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v44 = v91;
    v45 = v1;
    v94 = v0;
/* end of prologue */
    return list3(v94, v45, v44);
}



/* Code for multi_args */

static Lisp_Object CC_multi_args(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multi_args");
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
    v45 = stack[0];
    if (v45 == nil) goto v93;
    v45 = stack[0];
    v45 = qcar(v45);
    fn = elt(env, 2); /* expression */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-1];
    v45 = stack[0];
    v45 = qcdr(v45);
    v45 = CC_multi_args(env, v45);
    nil = C_nil;
    if (exception_pending()) goto v106;
    goto v93;

v93:
    v45 = nil;
    { popv(2); return onevalue(v45); }
/* error exit handlers */
v106:
    popv(2);
    return nil;
}



/* Code for cr!:zerop */

static Lisp_Object CC_crTzerop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v87;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cr:zerop");
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
    v80 = stack[0];
    v80 = qcdr(v80);
    v80 = qcar(v80);
    if (!consp(v80)) goto v102;
    v87 = elt(env, 1); /* !:rd!: */
    v80 = stack[0];
    v80 = qcdr(v80);
    v80 = qcar(v80);
    v80 = cons(v87, v80);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-1];
    goto v81;

v81:
    v87 = v80;
    v80 = v87;
    if (!consp(v80)) goto v126;
    v80 = v87;
    v80 = qcdr(v80);
    v87 = qcar(v80);
    v80 = (Lisp_Object)1; /* 0 */
    v80 = (v87 == v80 ? lisp_true : nil);
    goto v125;

v125:
    if (v80 == nil) goto v68;
    v80 = stack[0];
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    if (!consp(v80)) goto v73;
    v87 = elt(env, 1); /* !:rd!: */
    v80 = stack[0];
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = cons(v87, v80);
    nil = C_nil;
    if (exception_pending()) goto v140;
    goto v38;

v38:
    v87 = v80;
    v80 = v87;
    if (!consp(v80)) goto v58;
    v80 = v87;
    v80 = qcdr(v80);
    v87 = qcar(v80);
    v80 = (Lisp_Object)1; /* 0 */
    v80 = (v87 == v80 ? lisp_true : nil);
    { popv(2); return onevalue(v80); }

v58:
    v80 = v87;
        popv(2);
        return Lzerop(nil, v80);

v73:
    v80 = stack[0];
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    goto v38;

v68:
    v80 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v80); }

v126:
    v80 = v87;
    v80 = (Lisp_Object)zerop(v80);
    v80 = v80 ? lisp_true : nil;
    env = stack[-1];
    goto v125;

v102:
    v80 = stack[0];
    v80 = qcdr(v80);
    v80 = qcar(v80);
    goto v81;
/* error exit handlers */
v140:
    popv(2);
    return nil;
}



/* Code for oldmtch */

static Lisp_Object CC_oldmtch(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v71, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for oldmtch");
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
    v153 = stack[-2];
    v72 = qcdr(v153);
    v153 = stack[-1];
    v71 = qcar(v153);
    v153 = stack[-2];
    v153 = qcar(v153);
    fn = elt(env, 2); /* mcharg */
    v153 = (*qfnn(fn))(qenv(fn), 3, v72, v71, v153);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    stack[0] = v153;
    goto v55;

v55:
    v153 = stack[0];
    if (v153 == nil) goto v36;
    v153 = stack[-3];
    if (!(v153 == nil)) goto v36;
    v153 = stack[0];
    v71 = qcar(v153);
    v153 = stack[-1];
    v153 = qcdr(v153);
    v153 = qcar(v153);
    v153 = qcdr(v153);
    v153 = Lsubla(nil, v71, v153);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    fn = elt(env, 3); /* eval */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    if (v153 == nil) goto v75;
    v153 = stack[0];
    v71 = qcar(v153);
    v153 = stack[-1];
    v153 = qcdr(v153);
    v153 = qcdr(v153);
    v153 = qcar(v153);
    v153 = Lsubla(nil, v71, v153);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    goto v118;

v118:
    stack[-3] = v153;
    v153 = stack[0];
    v153 = qcdr(v153);
    stack[0] = v153;
    goto v55;

v75:
    v153 = nil;
    goto v118;

v36:
    v153 = stack[-3];
    if (v153 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    else { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v83:
    popv(5);
    return nil;
}



/* Code for assert_declarestat */

static Lisp_Object MS_CDECL CC_assert_declarestat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v242, v243, v244, v245;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_declarestat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_declarestat");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* end of prologue */
    stack[-10] = nil;
    v242 = (Lisp_Object)1; /* 0 */
    stack[-7] = v242;
    fn = elt(env, 20); /* assert_stat!-parse */
    v242 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-5] = v242;
    v242 = qvalue(elt(env, 1)); /* !*assert */
    if (v242 == nil) goto v76;
    v242 = stack[-5];
    v242 = qcar(v242);
    v242 = Lexplode(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[0] = v242;
    v242 = elt(env, 3); /* assert!: */
    v243 = Lexplode(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = stack[0];
    v242 = Lnconc(nil, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = Lcompress(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = Lintern(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-9] = v242;
    v242 = elt(env, 4); /* noassert!: */
    v243 = Lexplode(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = stack[0];
    v242 = Lnconc(nil, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = Lcompress(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = Lintern(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-4] = v242;
    v242 = stack[-5];
    v242 = qcdr(v242);
    v242 = qcar(v242);
    stack[-6] = v242;
    v242 = stack[-6];
    if (v242 == nil) goto v70;
    stack[0] = elt(env, 5); /* a */
    v242 = stack[-7];
    v242 = add1(v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-7] = v242;
    fn = elt(env, 21); /* mkid */
    v242 = (*qfn2(fn))(qenv(fn), stack[0], v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = ncons(v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-2] = v242;
    stack[-3] = v242;
    goto v53;

v53:
    v242 = stack[-6];
    v242 = qcdr(v242);
    stack[-6] = v242;
    v242 = stack[-6];
    if (v242 == nil) goto v131;
    stack[-1] = stack[-2];
    stack[0] = elt(env, 5); /* a */
    v242 = stack[-7];
    v242 = add1(v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-7] = v242;
    fn = elt(env, 21); /* mkid */
    v242 = (*qfn2(fn))(qenv(fn), stack[0], v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = ncons(v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = Lrplacd(nil, stack[-1], v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = stack[-2];
    v242 = qcdr(v242);
    stack[-2] = v242;
    goto v53;

v131:
    v242 = stack[-3];
    goto v73;

v73:
    stack[-3] = v242;
    v242 = stack[-5];
    v242 = qcar(v242);
    v242 = Lmkquote(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-8] = v242;
    v242 = stack[-4];
    v242 = Lmkquote(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-7] = v242;
    v243 = elt(env, 6); /* list */
    v242 = stack[-3];
    v242 = cons(v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-6] = v242;
    stack[-11] = elt(env, 6); /* list */
    v242 = stack[-5];
    v242 = qcdr(v242);
    v242 = qcar(v242);
    stack[-4] = v242;
    v242 = stack[-4];
    if (v242 == nil) goto v166;
    v242 = stack[-4];
    v242 = qcar(v242);
    v242 = Lmkquote(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = ncons(v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-1] = v242;
    stack[-2] = v242;
    goto v247;

v247:
    v242 = stack[-4];
    v242 = qcdr(v242);
    stack[-4] = v242;
    v242 = stack[-4];
    if (v242 == nil) goto v17;
    stack[0] = stack[-1];
    v242 = stack[-4];
    v242 = qcar(v242);
    v242 = Lmkquote(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = ncons(v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = Lrplacd(nil, stack[0], v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = stack[-1];
    v242 = qcdr(v242);
    stack[-1] = v242;
    goto v247;

v17:
    v242 = stack[-2];
    goto v57;

v57:
    v242 = cons(stack[-11], v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-11] = v242;
    v242 = stack[-5];
    v242 = qcdr(v242);
    v242 = qcdr(v242);
    v242 = qcar(v242);
    v242 = Lmkquote(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-5] = elt(env, 7); /* de */
    stack[-4] = stack[-9];
    stack[-2] = elt(env, 8); /* assert_check1 */
    stack[-1] = stack[-8];
    stack[0] = stack[-7];
    v244 = stack[-6];
    v243 = stack[-11];
    v242 = list3(v244, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = list3star(stack[-2], stack[-1], stack[0], v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v243 = list4(stack[-5], stack[-4], stack[-3], v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = stack[-10];
    v242 = cons(v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-10] = v242;
    stack[-2] = elt(env, 9); /* put */
    stack[-1] = stack[-8];
    stack[0] = elt(env, 10); /* (quote assert_assertfn) */
    v242 = stack[-9];
    v242 = Lmkquote(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v243 = list4(stack[-2], stack[-1], stack[0], v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = stack[-10];
    v242 = cons(v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-10] = v242;
    v245 = elt(env, 9); /* put */
    v244 = stack[-8];
    v243 = elt(env, 11); /* (quote assert_noassertfn) */
    v242 = stack[-7];
    v243 = list4(v245, v244, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = stack[-10];
    v242 = cons(v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-10] = v242;
    v245 = elt(env, 9); /* put */
    v244 = stack[-8];
    v243 = elt(env, 12); /* (quote assert_installed) */
    v242 = qvalue(elt(env, 2)); /* nil */
    v243 = list4(v245, v244, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = stack[-10];
    v242 = cons(v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-10] = v242;
    stack[-3] = elt(env, 13); /* cond */
    stack[0] = elt(env, 14); /* not */
    v244 = elt(env, 15); /* member */
    v243 = stack[-8];
    v242 = elt(env, 16); /* assert_functionl!* */
    v242 = list3(v244, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-2] = list2(stack[0], v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-1] = elt(env, 17); /* setq */
    stack[0] = elt(env, 16); /* assert_functionl!* */
    v244 = elt(env, 18); /* cons */
    v243 = stack[-8];
    v242 = elt(env, 16); /* assert_functionl!* */
    v242 = list3(v244, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = list3(stack[-1], stack[0], v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = list2(stack[-2], v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v243 = list2(stack[-3], v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    v242 = stack[-10];
    v242 = cons(v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-12];
    stack[-10] = v242;
    v243 = elt(env, 19); /* progn */
    v242 = stack[-10];
    v242 = Lnreverse(nil, v242);
    popv(13);
    return cons(v243, v242);

v166:
    v242 = qvalue(elt(env, 2)); /* nil */
    goto v57;

v70:
    v242 = qvalue(elt(env, 2)); /* nil */
    goto v73;

v76:
    v242 = qvalue(elt(env, 2)); /* nil */
    { popv(13); return onevalue(v242); }
/* error exit handlers */
v246:
    popv(13);
    return nil;
}



/* Code for red_totalred */

static Lisp_Object CC_red_totalred(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_totalred");
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
    v106 = v1;
    v77 = v0;
/* end of prologue */
    stack[0] = v77;
    fn = elt(env, 1); /* red_topred */
    v106 = (*qfn2(fn))(qenv(fn), v77, v106);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-1];
    {
        Lisp_Object v36 = stack[0];
        popv(2);
        fn = elt(env, 2); /* red_tailred */
        return (*qfn2(fn))(qenv(fn), v36, v106);
    }
/* error exit handlers */
v56:
    popv(2);
    return nil;
}



/* Code for reverse!-num1 */

static Lisp_Object CC_reverseKnum1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169, v250;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reverse-num1");
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
    stack[-2] = v1;
    stack[0] = v0;
/* end of prologue */
    v250 = stack[0];
    v169 = (Lisp_Object)1; /* 0 */
    if (v250 == v169) goto v93;
    v250 = stack[-2];
    v169 = (Lisp_Object)17; /* 1 */
    if (v250 == v169) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v250 = stack[-2];
    v169 = (Lisp_Object)33; /* 2 */
    if (v250 == v169) goto v118;
    v250 = stack[-2];
    v169 = (Lisp_Object)49; /* 3 */
    if (v250 == v169) goto v121;
    v250 = stack[-2];
    v169 = (Lisp_Object)65; /* 4 */
    if (v250 == v169) goto v130;
    stack[-1] = (Lisp_Object)33; /* 2 */
    v250 = stack[-2];
    v169 = (Lisp_Object)33; /* 2 */
    v169 = quot2(v250, v169);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    v169 = Lexpt(nil, stack[-1], v169);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    stack[-3] = v169;
    v250 = stack[0];
    v169 = stack[-3];
    v169 = Ldivide(nil, v250, v169);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    stack[-1] = v169;
    v169 = stack[-2];
    v169 = Levenp(nil, v169);
    env = stack[-4];
    if (!(v169 == nil)) goto v60;
    v250 = stack[-3];
    v169 = (Lisp_Object)33; /* 2 */
    v169 = times2(v250, v169);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    stack[-3] = v169;
    goto v60;

v60:
    v169 = stack[-1];
    stack[0] = qcdr(v169);
    v250 = stack[-2];
    v169 = (Lisp_Object)33; /* 2 */
    v169 = quot2(v250, v169);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    v250 = CC_reverseKnum1(env, stack[0], v169);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    v169 = stack[-3];
    stack[0] = times2(v250, v169);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    v169 = stack[-1];
    stack[-1] = qcar(v169);
    v169 = stack[-2];
    v250 = add1(v169);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    v169 = (Lisp_Object)33; /* 2 */
    v169 = quot2(v250, v169);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    v169 = CC_reverseKnum1(env, stack[-1], v169);
    nil = C_nil;
    if (exception_pending()) goto v198;
    {
        Lisp_Object v181 = stack[0];
        popv(5);
        return plus2(v181, v169);
    }

v130:
    v250 = qvalue(elt(env, 1)); /* reverse!-num!-table!* */
    v169 = stack[0];
    v169 = *(Lisp_Object *)((char *)v250 + (CELL-TAG_VECTOR) + ((int32_t)v169/(16/CELL)));
    { popv(5); return onevalue(v169); }

v121:
    stack[-1] = qvalue(elt(env, 1)); /* reverse!-num!-table!* */
    v250 = (Lisp_Object)33; /* 2 */
    v169 = stack[0];
    v169 = times2(v250, v169);
    nil = C_nil;
    if (exception_pending()) goto v198;
    v169 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v169/(16/CELL)));
    { popv(5); return onevalue(v169); }

v118:
    stack[-1] = qvalue(elt(env, 1)); /* reverse!-num!-table!* */
    v250 = (Lisp_Object)65; /* 4 */
    v169 = stack[0];
    v169 = times2(v250, v169);
    nil = C_nil;
    if (exception_pending()) goto v198;
    v169 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v169/(16/CELL)));
    { popv(5); return onevalue(v169); }

v93:
    v169 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v169); }
/* error exit handlers */
v198:
    popv(5);
    return nil;
}



setup_type const u22_setup[] =
{
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
    {"add2locs",                CC_add2locs,    too_many_1,    wrong_no_1},
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
    {"qtypnm",                  too_few_2,      CC_qtypnm,     wrong_no_2},
    {"monomgetfirstmultivar",   CC_monomgetfirstmultivar,too_many_1,wrong_no_1},
    {"om2ir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_om2ir},
    {"ps:depvar",               CC_psTdepvar,   too_many_1,    wrong_no_1},
    {"crn:minusp",              CC_crnTminusp,  too_many_1,    wrong_no_1},
    {"rootextractsq",           CC_rootextractsq,too_many_1,   wrong_no_1},
    {"delhisto",                CC_delhisto,    too_many_1,    wrong_no_1},
    {"rmsubs",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_rmsubs},
    {"setdmode",                too_few_2,      CC_setdmode,   wrong_no_2},
    {"bcminus?",                CC_bcminusW,    too_many_1,    wrong_no_1},
    {"gfdot",                   too_few_2,      CC_gfdot,      wrong_no_2},
    {"min0",                    too_few_2,      CC_min0,       wrong_no_2},
    {"locate_member",           too_few_2,      CC_locate_member,wrong_no_2},
    {"mv-pow-mv-+",             too_few_2,      CC_mvKpowKmvKL,wrong_no_2},
    {"mo_equal?",               too_few_2,      CC_mo_equalW,  wrong_no_2},
    {"proper-simpsqrt",         CC_properKsimpsqrt,too_many_1, wrong_no_1},
    {"createtriplewithancestor",too_few_2,      CC_createtriplewithancestor,wrong_no_2},
    {"aex_fromrp",              CC_aex_fromrp,  too_many_1,    wrong_no_1},
    {"dvfsf_mk2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_dvfsf_mk2},
    {"multi_args",              CC_multi_args,  too_many_1,    wrong_no_1},
    {"cr:zerop",                CC_crTzerop,    too_many_1,    wrong_no_1},
    {"oldmtch",                 too_few_2,      CC_oldmtch,    wrong_no_2},
    {"assert_declarestat",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_declarestat},
    {"red_totalred",            too_few_2,      CC_red_totalred,wrong_no_2},
    {"reverse-num1",            too_few_2,      CC_reverseKnum1,wrong_no_2},
    {NULL, (one_args *)"u22", (two_args *)"4849 2613999 9655105", 0}
};

/* end of generated code */
