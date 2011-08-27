
/* $destdir\u01.c        Machine generated C code */

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


/* Code for reval */

static Lisp_Object CC_reval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v3 = v0;
/* end of prologue */
    v4 = v3;
    v3 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* reval1 */
        return (*qfn2(fn))(qenv(fn), v4, v3);
    }
}



/* Code for num!-exponents */

static Lisp_Object CC_numKexponents(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for num-exponents");
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

v7:
    v6 = stack[0];
    if (!consp(v6)) goto v1;
    v6 = stack[0];
    v6 = qcar(v6);
    v6 = (consp(v6) ? nil : lisp_true);
    goto v8;

v8:
    if (v6 == nil) goto v9;
    v6 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v6); }

v9:
    v6 = stack[0];
    v6 = qcar(v6);
    v6 = qcar(v6);
    v6 = qcdr(v6);
    v6 = integerp(v6);
    if (v6 == nil) goto v10;
    v6 = stack[0];
    v6 = qcar(v6);
    v6 = qcdr(v6);
    v6 = CC_numKexponents(env, v6);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-1];
    if (v6 == nil) goto v12;
    v6 = stack[0];
    v6 = qcdr(v6);
    stack[0] = v6;
    goto v7;

v12:
    v6 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v6); }

v10:
    v6 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v6); }

v1:
    v6 = qvalue(elt(env, 1)); /* t */
    goto v8;
/* error exit handlers */
v11:
    popv(2);
    return nil;
}



/* Code for arraychk */

static Lisp_Object CC_arraychk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arraychk");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    if (v4 == nil) goto v13;
    v4 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v4);

v13:
    v4 = elt(env, 1); /* array */
    return onevalue(v4);
}



/* Code for getrtypeor */

static Lisp_Object CC_getrtypeor(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrtypeor");
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

v7:
    v14 = stack[0];
    if (v14 == nil) goto v13;
    v14 = stack[0];
    v14 = qcar(v14);
    fn = elt(env, 2); /* getrtype */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-1];
    if (!(v14 == nil)) { popv(2); return onevalue(v14); }
    v14 = stack[0];
    v14 = qcdr(v14);
    stack[0] = v14;
    goto v7;

v13:
    v14 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v14); }
/* error exit handlers */
v15:
    popv(2);
    return nil;
}



/* Code for !*d2q */

static Lisp_Object CC_Hd2q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *d2q");
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
    v23 = stack[0];
    if (is_number(v23)) goto v13;
    v23 = stack[0];
    fn = elt(env, 2); /* !:zerop */
    v23 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    if (v23 == nil) goto v6;
    v24 = qvalue(elt(env, 1)); /* nil */
    v23 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v24, v23);

v6:
    v24 = stack[0];
    v23 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v24, v23);

v13:
    v23 = stack[0];
    v23 = (Lisp_Object)zerop(v23);
    v23 = v23 ? lisp_true : nil;
    env = stack[-1];
    if (v23 == nil) goto v26;
    v24 = qvalue(elt(env, 1)); /* nil */
    v23 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v24, v23);

v26:
    v24 = stack[0];
    v23 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v24, v23);
/* error exit handlers */
v25:
    popv(2);
    return nil;
}



/* Code for readch1 */

static Lisp_Object MS_CDECL CC_readch1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v16;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "readch1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for readch1");
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
    v17 = qvalue(elt(env, 1)); /* !*int */
    if (v17 == nil) goto v5;
    v17 = qvalue(elt(env, 2)); /* ifl!* */
    if (!(v17 == nil)) goto v5;
    v17 = qvalue(elt(env, 6)); /* crbuf1!* */
    if (v17 == nil) goto v30;
    v17 = qvalue(elt(env, 6)); /* crbuf1!* */
    v17 = qcar(v17);
    stack[0] = v17;
    v17 = qvalue(elt(env, 6)); /* crbuf1!* */
    v17 = qcdr(v17);
    qvalue(elt(env, 6)) = v17; /* crbuf1!* */
    goto v31;

v31:
    v16 = stack[0];
    v17 = qvalue(elt(env, 7)); /* crbuf!* */
    v17 = cons(v16, v17);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    qvalue(elt(env, 7)) = v17; /* crbuf!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v30:
    v17 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    stack[0] = v17;
    goto v31;

v5:
    v17 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    stack[0] = v17;
    v16 = stack[0];
    v17 = qvalue(elt(env, 3)); /* !$eol!$ */
    if (!(v16 == v17)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v17 = qvalue(elt(env, 4)); /* curline!* */
    v17 = add1(v17);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    qvalue(elt(env, 4)) = v17; /* curline!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v24:
    popv(2);
    return nil;
}



/* Code for quotf */

static Lisp_Object CC_quotf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v34, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotf");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v34 = v28;
    v35 = v0;
/* end of prologue */
    v33 = qvalue(elt(env, 1)); /* t */
    stack[0] = qvalue(elt(env, 2)); /* !*exp */
    qvalue(elt(env, 2)) = v33; /* !*exp */
    v33 = v35;
    fn = elt(env, 3); /* quotf1 */
    v33 = (*qfn2(fn))(qenv(fn), v33, v34);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*exp */
    { popv(2); return onevalue(v33); }
/* error exit handlers */
v36:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*exp */
    popv(2);
    return nil;
}



/* Code for monomcompare */

static Lisp_Object CC_monomcompare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v40, v25, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monomcompare");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v28;
    v41 = v0;
/* end of prologue */
    v40 = qvalue(elt(env, 1)); /* fluidbibasismonomialorder */
    v24 = elt(env, 2); /* lex */
    if (v40 == v24) goto v36;
    v40 = qvalue(elt(env, 1)); /* fluidbibasismonomialorder */
    v24 = elt(env, 4); /* deglex */
    if (v40 == v24) goto v42;
    v24 = v41;
    v40 = v25;
    {
        fn = elt(env, 5); /* monomcomparedegrevlex */
        return (*qfn2(fn))(qenv(fn), v24, v40);
    }

v42:
    v24 = v41;
    v40 = v25;
    {
        fn = elt(env, 6); /* monomcomparedeglex */
        return (*qfn2(fn))(qenv(fn), v24, v40);
    }

v36:
    v24 = v41;
    v40 = v25;
    {
        fn = elt(env, 7); /* monomcomparelex */
        return (*qfn2(fn))(qenv(fn), v24, v40);
    }
}



/* Code for smember */

static Lisp_Object CC_smember(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v31;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smember");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v28;
    stack[-1] = v0;
/* end of prologue */

v8:
    v31 = stack[-1];
    v18 = stack[0];
    if (equal(v31, v18)) goto v43;
    v18 = stack[0];
    if (!consp(v18)) goto v35;
    v31 = stack[-1];
    v18 = stack[0];
    v18 = qcar(v18);
    v18 = CC_smember(env, v31, v18);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-2];
    if (!(v18 == nil)) { popv(3); return onevalue(v18); }
    v31 = stack[-1];
    v18 = stack[0];
    v18 = qcdr(v18);
    stack[-1] = v31;
    stack[0] = v18;
    goto v8;

v35:
    v18 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v18); }

v43:
    v18 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v18); }
/* error exit handlers */
v6:
    popv(3);
    return nil;
}



/* Code for quotelist */

static Lisp_Object CC_quotelist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v44;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotelist");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v44 = v0;
/* end of prologue */
    v44 = elt(env, 1); /* list */
    return onevalue(v44);
}



/* Code for wuconstantp */

static Lisp_Object CC_wuconstantp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v39;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wuconstantp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v39 = v0;
/* end of prologue */
    v38 = v39;
    if (!consp(v38)) goto v1;
    v38 = v39;
    v38 = qcar(v38);
    v38 = (consp(v38) ? nil : lisp_true);
    goto v8;

v8:
    if (v38 == nil) goto v22;
    v38 = qvalue(elt(env, 1)); /* t */
    return onevalue(v38);

v22:
    v38 = v39;
    v38 = qcar(v38);
    v38 = qcar(v38);
    v38 = qcar(v38);
    v39 = qvalue(elt(env, 2)); /* wuvarlist!* */
    v38 = Lmemq(nil, v38, v39);
    v38 = (v38 == nil ? lisp_true : nil);
    return onevalue(v38);

v1:
    v38 = qvalue(elt(env, 1)); /* t */
    goto v8;
}



/* Code for mkcopy */

static Lisp_Object CC_mkcopy(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkcopy");
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
    stack[-1] = nil;
    goto v43;

v43:
    v39 = stack[0];
    if (!consp(v39)) goto v32;
    v39 = stack[0];
    v39 = qcar(v39);
    v12 = CC_mkcopy(env, v39);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    v39 = stack[-1];
    v39 = cons(v12, v39);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    stack[-1] = v39;
    v39 = stack[0];
    v39 = qcdr(v39);
    stack[0] = v39;
    goto v43;

v32:
    v12 = stack[-1];
    v39 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v12, v39);
    }
/* error exit handlers */
v48:
    popv(3);
    return nil;
}



/* Code for remove!-free!-vars!-l */

static Lisp_Object CC_removeKfreeKvarsKl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v25, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remove-free-vars-l");
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

v13:
    v40 = stack[0];
    if (!consp(v40)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v40 = stack[0];
    v25 = qcar(v40);
    v40 = elt(env, 1); /* !*sq */
    if (v25 == v40) goto v4;
    v40 = stack[0];
    v40 = qcar(v40);
    fn = elt(env, 2); /* remove!-free!-vars */
    stack[-1] = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    v40 = stack[0];
    v40 = qcdr(v40);
    v40 = CC_removeKfreeKvarsKl(env, v40);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    v40 = cons(stack[-1], v40);
    nil = C_nil;
    if (exception_pending()) goto v51;
    v41 = v40;
    v25 = v41;
    v40 = stack[0];
    if (equal(v25, v40)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    else { popv(3); return onevalue(v41); }

v4:
    v40 = stack[0];
    v40 = qcdr(v40);
    v40 = qcar(v40);
    fn = elt(env, 3); /* prepsq!* */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    stack[0] = v40;
    goto v13;
/* error exit handlers */
v51:
    popv(3);
    return nil;
}



/* Code for mchk!* */

static Lisp_Object CC_mchkH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mchk*");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v28;
    stack[-1] = v0;
/* end of prologue */
    v56 = stack[-1];
    v55 = stack[0];
    fn = elt(env, 3); /* mchk */
    v55 = (*qfn2(fn))(qenv(fn), v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-2];
    v56 = v55;
    if (!(v55 == nil)) { popv(3); return onevalue(v56); }
    v55 = qvalue(elt(env, 1)); /* !*mcd */
    if (!(v55 == nil)) goto v14;
    v55 = stack[-1];
    if (!consp(v55)) goto v48;
    v55 = stack[-1];
    v55 = qcar(v55);
    v55 = (consp(v55) ? nil : lisp_true);
    v55 = (v55 == nil ? lisp_true : nil);
    goto v21;

v21:
    if (v55 == nil) goto v16;
    v55 = stack[0];
    if (!consp(v55)) goto v27;
    v55 = stack[0];
    v55 = qcar(v55);
    v55 = (consp(v55) ? nil : lisp_true);
    v55 = (v55 == nil ? lisp_true : nil);
    goto v58;

v58:
    if (v55 == nil) goto v14;
    v55 = stack[-1];
    fn = elt(env, 4); /* prepf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-2];
    v55 = stack[0];
    fn = elt(env, 4); /* prepf */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-2];
    {
        Lisp_Object v59 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* mchk */
        return (*qfn2(fn))(qenv(fn), v59, v55);
    }

v14:
    v55 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v55); }

v27:
    v55 = qvalue(elt(env, 2)); /* nil */
    goto v58;

v16:
    v55 = qvalue(elt(env, 2)); /* nil */
    goto v58;

v48:
    v55 = qvalue(elt(env, 2)); /* nil */
    goto v21;
/* error exit handlers */
v57:
    popv(3);
    return nil;
}



/* Code for prepf */

static Lisp_Object CC_prepf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepf");
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
    v4 = v0;
/* end of prologue */
    v32 = v4;
    v4 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepf1a */
    v4 = (*qfn2(fn))(qenv(fn), v32, v4);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* replus1 */
        return (*qfn1(fn))(qenv(fn), v4);
    }
/* error exit handlers */
v33:
    popv(1);
    return nil;
}



/* Code for get!+mat!+entry */

static Lisp_Object MS_CDECL CC_getLmatLentry(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v28,
                         Lisp_Object v47, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "get+mat+entry");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get+mat+entry");
#endif
    if (stack >= stacklimit)
    {
        push3(v47,v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v28,v47);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v47;
    v29 = v28;
    v26 = v0;
/* end of prologue */
    fn = elt(env, 1); /* pnth */
    v29 = (*qfn2(fn))(qenv(fn), v26, v29);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-1];
    v26 = qcar(v29);
    v29 = stack[0];
    fn = elt(env, 1); /* pnth */
    v29 = (*qfn2(fn))(qenv(fn), v26, v29);
    nil = C_nil;
    if (exception_pending()) goto v60;
    v29 = qcar(v29);
    { popv(2); return onevalue(v29); }
/* error exit handlers */
v60:
    popv(2);
    return nil;
}



/* Code for minusf */

static Lisp_Object CC_minusf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v62, v63;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minusf");
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
    v62 = v0;
/* end of prologue */

v13:
    v51 = v62;
    if (v51 == nil) goto v8;
    v51 = v62;
    if (!consp(v51)) goto v35;
    v51 = v62;
    v51 = qcar(v51);
    v51 = (consp(v51) ? nil : lisp_true);
    goto v34;

v34:
    if (v51 == nil) goto v40;
    v51 = v62;
    if (!consp(v51)) goto v38;
    v51 = v62;
    v63 = qcar(v51);
    v51 = elt(env, 3); /* minusp */
    v51 = get(v63, v51);
        return Lapply1(nil, v51, v62);

v38:
    v51 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v62, v51);

v40:
    v51 = v62;
    v51 = qcar(v51);
    v51 = qcdr(v51);
    v62 = v51;
    goto v13;

v35:
    v51 = qvalue(elt(env, 2)); /* t */
    goto v34;

v8:
    v51 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v51);
}



/* Code for qqe_rqopp */

static Lisp_Object CC_qqe_rqopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_rqopp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v3 = v0;
/* end of prologue */
    v4 = elt(env, 1); /* (qequal qneq) */
    v3 = Lmemq(nil, v3, v4);
    return onevalue(v3);
}



/* Code for kernels1 */

static Lisp_Object CC_kernels1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v55, v56, v66;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernels1");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v56 = v28;
    v65 = v0;
/* end of prologue */

v7:
    v55 = v65;
    if (!consp(v55)) goto v2;
    v55 = v65;
    v55 = qcar(v55);
    v55 = (consp(v55) ? nil : lisp_true);
    goto v1;

v1:
    if (!(v55 == nil)) { popv(4); return onevalue(v56); }
    v55 = v65;
    v55 = qcar(v55);
    v55 = qcar(v55);
    v55 = qcar(v55);
    v66 = v55;
    v55 = v65;
    v55 = qcar(v55);
    stack[-2] = qcdr(v55);
    stack[-1] = qcdr(v65);
    v55 = v66;
    v65 = v56;
    v65 = Lmemq(nil, v55, v65);
    if (v65 == nil) goto v67;
    v65 = v56;
    goto v30;

v30:
    v55 = CC_kernels1(env, stack[-1], v65);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-3];
    v65 = stack[-2];
    v56 = v55;
    goto v7;

v67:
    stack[0] = v56;
    v65 = v66;
    v65 = ncons(v65);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-3];
    v65 = Lappend(nil, stack[0], v65);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-3];
    goto v30;

v2:
    v55 = qvalue(elt(env, 1)); /* t */
    goto v1;
/* error exit handlers */
v68:
    popv(4);
    return nil;
}



/* Code for ibalp_clmember */

static Lisp_Object CC_ibalp_clmember(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_clmember");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v28;
    stack[-1] = v0;
/* end of prologue */

v7:
    v38 = stack[0];
    if (v38 == nil) goto v43;
    v39 = stack[-1];
    v38 = stack[0];
    v38 = qcar(v38);
    fn = elt(env, 2); /* ibalp_cequal */
    v38 = (*qfn2(fn))(qenv(fn), v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    if (!(v38 == nil)) { popv(3); return onevalue(v38); }
    v39 = stack[-1];
    v38 = stack[0];
    v38 = qcdr(v38);
    stack[-1] = v39;
    stack[0] = v38;
    goto v7;

v43:
    v38 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v38); }
/* error exit handlers */
v50:
    popv(3);
    return nil;
}



/* Code for adjoin!-term */

static Lisp_Object MS_CDECL CC_adjoinKterm(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v28,
                         Lisp_Object v47, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v26, v58, v60;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "adjoin-term");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for adjoin-term");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v29 = v47;
    v26 = v28;
    v58 = v0;
/* end of prologue */
    v60 = v26;
    if (v60 == nil) return onevalue(v29);
    return acons(v58, v26, v29);
}



/* Code for delall */

static Lisp_Object CC_delall(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v61;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delall");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v28;
    stack[-1] = v0;
/* end of prologue */

v43:
    v70 = stack[0];
    if (v70 == nil) goto v1;
    v61 = stack[-1];
    v70 = stack[0];
    v70 = qcar(v70);
    if (equal(v61, v70)) goto v32;
    v70 = stack[0];
    v70 = qcar(v70);
    stack[-2] = ncons(v70);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-3];
    v61 = stack[-1];
    v70 = stack[0];
    v70 = qcdr(v70);
    v70 = CC_delall(env, v61, v70);
    nil = C_nil;
    if (exception_pending()) goto v27;
    {
        Lisp_Object v49 = stack[-2];
        popv(4);
        return Lappend(nil, v49, v70);
    }

v32:
    v70 = stack[0];
    v70 = qcdr(v70);
    stack[0] = v70;
    goto v43;

v1:
    v70 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v70); }
/* error exit handlers */
v27:
    popv(4);
    return nil;
}



/* Code for noncomfp1 */

static Lisp_Object CC_noncomfp1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomfp1");
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

v7:
    v6 = stack[0];
    if (!consp(v6)) goto v1;
    v6 = stack[0];
    v6 = qcar(v6);
    v6 = (consp(v6) ? nil : lisp_true);
    goto v8;

v8:
    if (v6 == nil) goto v13;
    v6 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v6); }

v13:
    v6 = qvalue(elt(env, 2)); /* !*ncmp */
    if (v6 == nil) goto v10;
    v6 = stack[0];
    v6 = qcar(v6);
    v6 = qcar(v6);
    v6 = qcar(v6);
    fn = elt(env, 4); /* noncomp1 */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-1];
    goto v15;

v15:
    if (!(v6 == nil)) { popv(2); return onevalue(v6); }
    v6 = stack[0];
    v6 = qcar(v6);
    v6 = qcdr(v6);
    v6 = CC_noncomfp1(env, v6);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-1];
    if (!(v6 == nil)) { popv(2); return onevalue(v6); }
    v6 = stack[0];
    v6 = qcdr(v6);
    stack[0] = v6;
    goto v7;

v10:
    v6 = qvalue(elt(env, 3)); /* nil */
    goto v15;

v1:
    v6 = qvalue(elt(env, 1)); /* t */
    goto v8;
/* error exit handlers */
v11:
    popv(2);
    return nil;
}



/* Code for ordop */

static Lisp_Object CC_ordop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v6, v71, v11, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordop");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v11 = v28;
    v27 = v0;
/* end of prologue */
    v61 = qvalue(elt(env, 1)); /* kord!* */
    v71 = v61;
    goto v5;

v5:
    v61 = v71;
    if (v61 == nil) goto v34;
    v6 = v27;
    v61 = v71;
    v61 = qcar(v61);
    if (v6 == v61) goto v15;
    v6 = v11;
    v61 = v71;
    v61 = qcar(v61);
    if (v6 == v61) goto v38;
    v61 = v71;
    v61 = qcdr(v61);
    v71 = v61;
    goto v5;

v38:
    v61 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v61);

v15:
    v61 = qvalue(elt(env, 2)); /* t */
    return onevalue(v61);

v34:
    v61 = v27;
    v6 = v11;
    {
        fn = elt(env, 4); /* ordp */
        return (*qfn2(fn))(qenv(fn), v61, v6);
    }
}



/* Code for ps!:getv */

static Lisp_Object CC_psTgetv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v64, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:getv");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v28;
    v53 = v0;
/* end of prologue */
    v64 = v53;
    v52 = elt(env, 1); /* !:ps!: */
    if (!consp(v64)) goto v61;
    v64 = qcar(v64);
    if (!(v64 == v52)) goto v61;
    v52 = v53;
    v52 = qcdr(v52);
    if (symbolp(v52)) goto v15;
    v52 = v53;
    v64 = qcdr(v52);
    v52 = stack[0];
    v52 = *(Lisp_Object *)((char *)v64 + (CELL-TAG_VECTOR) + ((int32_t)v52/(16/CELL)));
    { popv(2); return onevalue(v52); }

v15:
    v52 = v53;
    v52 = qcdr(v52);
    fn = elt(env, 5); /* eval */
    v64 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v55;
    v52 = stack[0];
    v52 = *(Lisp_Object *)((char *)v64 + (CELL-TAG_VECTOR) + ((int32_t)v52/(16/CELL)));
    { popv(2); return onevalue(v52); }

v61:
    v52 = elt(env, 2); /* "PS:GETV: not a ps" */
    v64 = v53;
    v52 = list2(v52, v64);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-1];
    v64 = v52;
    v52 = v64;
    qvalue(elt(env, 3)) = v52; /* errmsg!* */
    v52 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v52 == nil)) goto v41;
    v52 = v64;
    fn = elt(env, 6); /* lprie */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-1];
    goto v41;

v41:
    v52 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v55;
    v52 = nil;
    { popv(2); return onevalue(v52); }
/* error exit handlers */
v55:
    popv(2);
    return nil;
}



/* Code for ldepends */

static Lisp_Object CC_ldepends(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldepends");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v28;
    stack[-1] = v0;
/* end of prologue */

v7:
    v31 = stack[-1];
    if (v31 == nil) goto v43;
    v31 = stack[-1];
    if (!consp(v31)) goto v33;
    v31 = stack[-1];
    v70 = qcar(v31);
    v31 = stack[0];
    fn = elt(env, 2); /* depends */
    v31 = (*qfn2(fn))(qenv(fn), v70, v31);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    if (!(v31 == nil)) { popv(3); return onevalue(v31); }
    v31 = stack[-1];
    v70 = qcdr(v31);
    v31 = stack[0];
    stack[-1] = v70;
    stack[0] = v31;
    goto v7;

v33:
    v70 = stack[-1];
    v31 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* depends */
        return (*qfn2(fn))(qenv(fn), v70, v31);
    }

v43:
    v31 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v31); }
/* error exit handlers */
v71:
    popv(3);
    return nil;
}



/* Code for c!:ordxp */

static Lisp_Object CC_cTordxp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v70, v61;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:ordxp");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v31 = v28;
    v70 = v0;
/* end of prologue */
    v61 = v70;
    v61 = Lconsp(nil, v61);
    env = stack[0];
    if (v61 == nil) goto v5;
    v61 = v31;
    v61 = Lconsp(nil, v61);
    env = stack[0];
    if (v61 == nil) goto v58;
    v70 = qcdr(v70);
    v31 = qcdr(v31);
        popv(1);
        return Llessp(nil, v70, v31);

v58:
    v31 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v31); }

v5:
    v61 = v31;
    v61 = Lconsp(nil, v61);
    env = stack[0];
    if (v61 == nil) goto v30;
    v31 = qvalue(elt(env, 2)); /* t */
    { popv(1); return onevalue(v31); }

v30:
        popv(1);
        return Llessp(nil, v70, v31);
}



/* Code for zero2nil */

static Lisp_Object CC_zero2nil(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zero2nil");
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
    fn = elt(env, 2); /* !:zerop */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    if (v32 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v32 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v32); }
/* error exit handlers */
v34:
    popv(2);
    return nil;
}



/* Code for binding */

static Lisp_Object CC_binding(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v14;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for binding");
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
    v9 = v0;
/* end of prologue */
    v14 = v9;
    v9 = elt(env, 0); /* binding */
    v9 = get(v14, v9);
    v14 = v9;
    v9 = v14;
    if (v9 == nil) goto v34;
    v9 = v14;
    v9 = qcar(v9);
    return onevalue(v9);

v34:
    v9 = nil;
    return onevalue(v9);
}



/* Code for evcomp */

static Lisp_Object CC_evcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evcomp");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v9 = v28;
    v14 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dipsortevcomp!* */
    v9 = list2(v14, v9);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-1];
    {
        Lisp_Object v10 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v10, v9);
    }
/* error exit handlers */
v15:
    popv(2);
    return nil;
}



/* Code for pnth */

static Lisp_Object CC_pnth(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v19, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pnth");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v19 = v28;
    stack[0] = v0;
/* end of prologue */

v43:
    v37 = stack[0];
    if (v37 == nil) goto v1;
    v18 = v19;
    v37 = (Lisp_Object)17; /* 1 */
    if (v18 == v37) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v37 = stack[0];
    v37 = qcdr(v37);
    stack[0] = v37;
    v37 = v19;
    v37 = sub1(v37);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    v19 = v37;
    goto v43;

v1:
    v37 = elt(env, 1); /* "Index out of range" */
    v19 = v37;
    v37 = v19;
    qvalue(elt(env, 2)) = v37; /* errmsg!* */
    v37 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v37 == nil)) goto v36;
    v37 = v19;
    fn = elt(env, 4); /* lprie */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    goto v36;

v36:
    v37 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v70;
    v37 = nil;
    { popv(2); return onevalue(v37); }
/* error exit handlers */
v70:
    popv(2);
    return nil;
}



/* Code for evmatrixcomp2 */

static Lisp_Object MS_CDECL CC_evmatrixcomp2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v28,
                         Lisp_Object v47, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v81, v82, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evmatrixcomp2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evmatrixcomp2");
#endif
    if (stack >= stacklimit)
    {
        push3(v47,v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v28,v47);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v47;
    stack[-1] = v28;
    stack[-2] = v0;
/* end of prologue */

v7:
    v80 = stack[-2];
    if (v80 == nil) goto v3;
    v80 = stack[-1];
    v80 = (v80 == nil ? lisp_true : nil);
    goto v2;

v2:
    if (!(v80 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v80 = stack[-1];
    v80 = qcar(v80);
    stack[-3] = v80;
    v81 = stack[-3];
    v80 = (Lisp_Object)1; /* 0 */
    v80 = Leqn(nil, v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    if (v80 == nil) goto v16;
    v80 = stack[-2];
    v82 = qcdr(v80);
    v80 = stack[-1];
    v81 = qcdr(v80);
    v80 = stack[0];
    stack[-2] = v82;
    stack[-1] = v81;
    stack[0] = v80;
    goto v7;

v16:
    v81 = stack[-3];
    v80 = (Lisp_Object)17; /* 1 */
    v80 = Leqn(nil, v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    if (v80 == nil) goto v85;
    v80 = stack[-2];
    v83 = qcdr(v80);
    v80 = stack[-1];
    v82 = qcdr(v80);
    v81 = stack[0];
    v80 = stack[-2];
    v80 = qcar(v80);
    v80 = (Lisp_Object)(int32_t)((int32_t)v81 + (int32_t)v80 - TAG_FIXNUM);
    stack[-2] = v83;
    stack[-1] = v82;
    stack[0] = v80;
    goto v7;

v85:
    v83 = stack[-2];
    v82 = stack[-3];
    v81 = stack[-1];
    v80 = stack[0];
    {
        popv(5);
        fn = elt(env, 2); /* evmatrixcomp3 */
        return (*qfnn(fn))(qenv(fn), 4, v83, v82, v81, v80);
    }

v3:
    v80 = qvalue(elt(env, 1)); /* t */
    goto v2;
/* error exit handlers */
v84:
    popv(5);
    return nil;
}



/* Code for xval */

static Lisp_Object CC_xval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xval");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v5 = v0;
/* end of prologue */
    v5 = qcar(v5);
    v5 = qcar(v5);
    {
        fn = elt(env, 1); /* wedgefax */
        return (*qfn1(fn))(qenv(fn), v5);
    }
}



/* Code for add_prin_char */

static Lisp_Object CC_add_prin_char(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v87, v57;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add_prin_char");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v28;
    stack[-1] = v0;
/* end of prologue */
    v66 = qvalue(elt(env, 1)); /* !*nat */
    if (v66 == nil) goto v43;
    v57 = qvalue(elt(env, 3)); /* posn!* */
    v87 = stack[0];
    v66 = qvalue(elt(env, 4)); /* ycoord!* */
    v57 = acons(v57, v87, v66);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-2];
    v87 = stack[-1];
    v66 = qvalue(elt(env, 5)); /* pline!* */
    v66 = acons(v57, v87, v66);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-2];
    qvalue(elt(env, 5)) = v66; /* pline!* */
    v66 = stack[0];
    qvalue(elt(env, 3)) = v66; /* posn!* */
    { popv(3); return onevalue(v66); }

v43:
    v66 = stack[-1];
    v66 = Lstringp(nil, v66);
    env = stack[-2];
    if (!(v66 == nil)) goto v3;
    v87 = stack[-1];
    v66 = elt(env, 2); /* switch!* */
    v66 = get(v87, v66);
    env = stack[-2];
    if (!(v66 == nil)) goto v3;
    v66 = stack[-1];
    v66 = Ldigitp(nil, v66);
    env = stack[-2];
    if (!(v66 == nil)) goto v3;
    v66 = stack[-1];
    v66 = Lexplodec(nil, v66);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-2];
    v87 = qcar(v66);
    v66 = elt(env, 2); /* switch!* */
    v66 = get(v87, v66);
    if (!(v66 == nil)) goto v3;
    v66 = stack[-1];
        popv(3);
        return Lprin(nil, v66);

v3:
    v66 = stack[-1];
        popv(3);
        return Lprinc(nil, v66);
/* error exit handlers */
v88:
    popv(3);
    return nil;
}



/* Code for int!-equiv!-chk */

static Lisp_Object CC_intKequivKchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v96, v97;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for int-equiv-chk");
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
    v95 = qvalue(elt(env, 1)); /* !*noequiv */
    if (!(v95 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v95 = stack[0];
    if (!consp(v95)) goto v10;
    v95 = stack[0];
    v96 = qcar(v95);
    v95 = elt(env, 3); /* zerop */
    v96 = get(v96, v95);
    env = stack[-1];
    v95 = stack[0];
    v95 = Lapply1(nil, v96, v95);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-1];
    if (v95 == nil) goto v62;
    v95 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v95); }

v62:
    v95 = stack[0];
    v96 = qcar(v95);
    v95 = elt(env, 4); /* onep */
    v96 = get(v96, v95);
    env = stack[-1];
    v95 = stack[0];
    v95 = Lapply1(nil, v96, v95);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-1];
    if (v95 == nil) goto v88;
    v95 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v95); }

v88:
    v95 = stack[0];
    v96 = qcar(v95);
    v95 = elt(env, 5); /* intequivfn */
    v95 = get(v96, v95);
    env = stack[-1];
    v97 = v95;
    if (v95 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v96 = v97;
    v95 = stack[0];
    v95 = Lapply1(nil, v96, v95);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-1];
    v97 = v95;
    if (v95 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v96 = v97;
    v95 = (Lisp_Object)1; /* 0 */
    if (!(v96 == v95)) { popv(2); return onevalue(v97); }
    v95 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v95); }

v10:
    v96 = stack[0];
    v95 = (Lisp_Object)1; /* 0 */
    if (!(v96 == v95)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v95 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v95); }
/* error exit handlers */
v98:
    popv(2);
    return nil;
}



/* Code for physopp */

static Lisp_Object CC_physopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v76;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopp");
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
    v41 = v76;
    if (!consp(v41)) goto v13;
    v41 = v76;
    v41 = qcar(v41);
    if (symbolp(v41)) goto v71;
    v41 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v41); }

v71:
    v41 = v76;
    v76 = qcar(v41);
    v41 = elt(env, 2); /* rtype */
    v41 = get(v76, v41);
    env = stack[0];
    v76 = elt(env, 3); /* physop */
    v41 = (v41 == v76 ? lisp_true : nil);
    { popv(1); return onevalue(v41); }

v13:
    v41 = v76;
    if (symbolp(v41)) goto v29;
    v41 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v41); }

v29:
    v41 = elt(env, 2); /* rtype */
    v41 = get(v76, v41);
    env = stack[0];
    v76 = elt(env, 3); /* physop */
    v41 = (v41 == v76 ? lisp_true : nil);
    { popv(1); return onevalue(v41); }
}



/* Code for memq_edgelist */

static Lisp_Object CC_memq_edgelist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for memq_edgelist");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v28;
    v33 = v0;
/* end of prologue */
    v33 = qcar(v33);
    v32 = Lassoc(nil, v33, v32);
    return onevalue(v32);
}



/* Code for termsf */

static Lisp_Object CC_termsf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v27;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termsf");
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
    v11 = (Lisp_Object)1; /* 0 */
    v27 = v11;
    goto v1;

v1:
    v11 = stack[0];
    if (!consp(v11)) goto v35;
    v11 = stack[0];
    v11 = qcar(v11);
    v11 = (consp(v11) ? nil : lisp_true);
    goto v34;

v34:
    if (v11 == nil) goto v60;
    v11 = stack[0];
    if (v11 == nil) { popv(3); return onevalue(v27); }
    v11 = v27;
    popv(3);
    return add1(v11);

v60:
    stack[-1] = v27;
    v11 = stack[0];
    v11 = qcar(v11);
    v11 = qcdr(v11);
    v11 = CC_termsf(env, v11);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    v11 = plus2(stack[-1], v11);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    v27 = v11;
    v11 = stack[0];
    v11 = qcdr(v11);
    stack[0] = v11;
    goto v1;

v35:
    v11 = qvalue(elt(env, 1)); /* t */
    goto v34;
/* error exit handlers */
v16:
    popv(3);
    return nil;
}



/* Code for mkspm */

static Lisp_Object CC_mkspm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkspm");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v28;
    stack[-1] = v0;
/* end of prologue */
    v76 = stack[0];
    v41 = (Lisp_Object)1; /* 0 */
    if (v76 == v41) goto v43;
    v41 = qvalue(elt(env, 1)); /* subfg!* */
    if (v41 == nil) goto v15;
    v76 = stack[-1];
    v41 = qvalue(elt(env, 2)); /* asymplis!* */
    v41 = Latsoc(nil, v76, v41);
    v76 = v41;
    if (v41 == nil) goto v15;
    v41 = v76;
    v76 = qcdr(v41);
    v41 = stack[0];
    v41 = (Lisp_Object)lesseq2(v76, v41);
    nil = C_nil;
    if (exception_pending()) goto v62;
    v41 = v41 ? lisp_true : nil;
    env = stack[-2];
    if (v41 == nil) goto v15;
    v41 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v41); }

v15:
    v41 = stack[-1];
    fn = elt(env, 4); /* sub2chk */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v62;
    v76 = stack[-1];
    v41 = stack[0];
    popv(3);
    return cons(v76, v41);

v43:
    v41 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v41); }
/* error exit handlers */
v62:
    popv(3);
    return nil;
}



/* Code for mo_comp */

static Lisp_Object CC_mo_comp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v35;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_comp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v34 = v0;
/* end of prologue */
    v35 = v34;
    v35 = qcar(v35);
    if (v35 == nil) goto v13;
    v34 = qcar(v34);
    v34 = qcar(v34);
    return onevalue(v34);

v13:
    v34 = (Lisp_Object)1; /* 0 */
    return onevalue(v34);
}



/* Code for c_zero */

static Lisp_Object MS_CDECL CC_c_zero(Lisp_Object env, int nargs, ...)
{
    Lisp_Object v47;
    argcheck(nargs, 0, "c_zero");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c_zero");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v47 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v47);
}



/* Code for sieve_pv0 */

static Lisp_Object MS_CDECL CC_sieve_pv0(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v28,
                         Lisp_Object v47, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v65, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sieve_pv0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sieve_pv0");
#endif
    if (stack >= stacklimit)
    {
        push3(v47,v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v28,v47);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v47;
    stack[-1] = v28;
    stack[-2] = v0;
/* end of prologue */
    v53 = stack[-2];
    if (!(v53 == nil)) goto v34;
    v53 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v53); }

v34:
    v53 = stack[-1];
    if (v53 == nil) goto v37;
    v53 = stack[-1];
    v53 = qcar(v53);
    v53 = qcar(v53);
    v65 = qcdr(v53);
    v53 = stack[-2];
    v53 = qcar(v53);
    v53 = qcdr(v53);
    v53 = (Lisp_Object)greaterp2(v65, v53);
    nil = C_nil;
    if (exception_pending()) goto v57;
    v53 = v53 ? lisp_true : nil;
    env = stack[-3];
    if (v53 == nil) goto v37;
    v53 = stack[-1];
    v53 = qcdr(v53);
    stack[-1] = v53;
    goto v34;

v37:
    v53 = stack[-2];
    if (v53 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v53 = stack[-1];
    if (v53 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v55 = stack[-2];
    v53 = stack[-1];
    v65 = qcar(v53);
    v53 = stack[0];
    fn = elt(env, 2); /* reduce_pv0 */
    v53 = (*qfnn(fn))(qenv(fn), 3, v55, v65, v53);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-3];
    stack[-2] = v53;
    v53 = stack[-1];
    v53 = qcdr(v53);
    stack[-1] = v53;
    goto v37;
/* error exit handlers */
v57:
    popv(4);
    return nil;
}



/* Code for listp */

static Lisp_Object CC_listp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v10;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */

v7:
    v10 = v15;
    if (v10 == nil) goto v13;
    v10 = v15;
    if (!consp(v10)) goto v9;
    v15 = qcdr(v15);
    goto v7;

v9:
    v15 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v15);

v13:
    v15 = qvalue(elt(env, 1)); /* t */
    return onevalue(v15);
}



/* Code for modzerop!: */

static Lisp_Object CC_modzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modzerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v32 = qcdr(v4);
    v4 = (Lisp_Object)1; /* 0 */
    v4 = (v32 == v4 ? lisp_true : nil);
    return onevalue(v4);
}



/* Code for xcomment */

static Lisp_Object CC_xcomment(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v46, v45;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xcomment");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v45 = v28;
    v46 = v0;
/* end of prologue */
    v60 = v45;
    if (v60 == nil) { popv(3); return onevalue(v46); }
    stack[-1] = elt(env, 1); /* comment */
    v60 = v45;
    stack[0] = Lnreverse(nil, v60);
    env = stack[-2];
    v60 = v46;
    v60 = ncons(v60);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    v60 = Lnconc(nil, stack[0], v60);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    v60 = cons(stack[-1], v60);
    nil = C_nil;
    if (exception_pending()) goto v69;
    v46 = v60;
    { popv(3); return onevalue(v46); }
/* error exit handlers */
v69:
    popv(3);
    return nil;
}



/* Code for monomgetvariabledegree */

static Lisp_Object CC_monomgetvariabledegree(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v62;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monomgetvariabledegree");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v28;
    v51 = v0;
/* end of prologue */
    v62 = v51;
    v51 = (Lisp_Object)17; /* 1 */
    v51 = *(Lisp_Object *)((char *)v62 + (CELL-TAG_VECTOR) + ((int32_t)v51/(16/CELL)));
    stack[-1] = v51;
    goto v54;

v54:
    v51 = stack[-1];
    v51 = qcar(v51);
    if (v51 == nil) goto v35;
    v51 = stack[-1];
    v62 = qcar(v51);
    v51 = stack[0];
    v51 = (Lisp_Object)greaterp2(v62, v51);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v51 = v51 ? lisp_true : nil;
    env = stack[-2];
    if (v51 == nil) goto v35;
    v51 = stack[-1];
    v51 = qcdr(v51);
    stack[-1] = v51;
    goto v54;

v35:
    v51 = stack[-1];
    v51 = qcar(v51);
    if (v51 == nil) goto v25;
    v51 = stack[-1];
    v62 = qcar(v51);
    v51 = stack[0];
    if (!(equal(v62, v51))) goto v25;
    v51 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v51); }

v25:
    v51 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v51); }
/* error exit handlers */
v52:
    popv(3);
    return nil;
}



/* Code for aeval */

static Lisp_Object CC_aeval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aeval");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v3 = v0;
/* end of prologue */
    v4 = v3;
    v3 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* reval1 */
        return (*qfn2(fn))(qenv(fn), v4, v3);
    }
}



/* Code for rl_smupdknowl */

static Lisp_Object MS_CDECL CC_rl_smupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v28,
                         Lisp_Object v47, Lisp_Object v44, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v46, v45, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "rl_smupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_smupdknowl");
#endif
    if (stack >= stacklimit)
    {
        push4(v44,v47,v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v28,v47,v44);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v60 = v44;
    v46 = v47;
    v45 = v28;
    v21 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_smupdknowl!* */
    v60 = list4(v21, v45, v46, v60);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-1];
    {
        Lisp_Object v38 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v38, v60);
    }
/* error exit handlers */
v69:
    popv(2);
    return nil;
}



/* Code for degr */

static Lisp_Object CC_degr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v61, v6;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for degr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v61 = v28;
    v6 = v0;
/* end of prologue */
    v70 = v6;
    if (!consp(v70)) goto v33;
    v70 = v6;
    v70 = qcar(v70);
    v70 = (consp(v70) ? nil : lisp_true);
    goto v32;

v32:
    if (v70 == nil) goto v58;
    v70 = qvalue(elt(env, 1)); /* t */
    goto v1;

v1:
    if (v70 == nil) goto v86;
    v70 = (Lisp_Object)1; /* 0 */
    return onevalue(v70);

v86:
    v70 = v6;
    v70 = qcar(v70);
    v70 = qcar(v70);
    v70 = qcdr(v70);
    return onevalue(v70);

v58:
    v70 = v6;
    v70 = qcar(v70);
    v70 = qcar(v70);
    v70 = qcar(v70);
    v70 = (v70 == v61 ? lisp_true : nil);
    v70 = (v70 == nil ? lisp_true : nil);
    goto v1;

v33:
    v70 = qvalue(elt(env, 1)); /* t */
    goto v32;
}



/* Code for prepf1a */

static Lisp_Object CC_prepf1a(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v54, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepf1a");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v35 = v28;
    v54 = v0;
/* end of prologue */
    v36 = v54;
    v54 = v35;
    v35 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepf1a_reversed */
    v35 = (*qfnn(fn))(qenv(fn), 3, v36, v54, v35);
    errexit();
        return Lnreverse(nil, v35);
}



/* Code for setkorder */

static Lisp_Object CC_setkorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v29, v26;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setkorder");
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
    v26 = v0;
/* end of prologue */
    v10 = qvalue(elt(env, 1)); /* kord!* */
    stack[0] = v10;
    v29 = v26;
    v10 = stack[0];
    if (equal(v29, v10)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v10 = v26;
    qvalue(elt(env, 1)) = v10; /* kord!* */
    v10 = qvalue(elt(env, 2)); /* nil */
    v10 = ncons(v10);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-1];
    qvalue(elt(env, 3)) = v10; /* alglist!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v60:
    popv(2);
    return nil;
}



/* Code for ibalp_emptyclausep */

static Lisp_Object CC_ibalp_emptyclausep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v6;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_emptyclausep");
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
    v61 = stack[0];
    v61 = qcdr(v61);
    v61 = qcdr(v61);
    v61 = qcdr(v61);
    v61 = qcdr(v61);
    v61 = qcar(v61);
    if (v61 == nil) goto v36;
    v61 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v61); }

v36:
    v61 = stack[0];
    v61 = qcdr(v61);
    v61 = qcdr(v61);
    v6 = qcar(v61);
    v61 = (Lisp_Object)1; /* 0 */
    v61 = Leqn(nil, v6, v61);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-1];
    if (v61 == nil) goto v34;
    v61 = stack[0];
    v61 = qcdr(v61);
    v61 = qcdr(v61);
    v61 = qcdr(v61);
    v6 = qcar(v61);
    v61 = (Lisp_Object)1; /* 0 */
        popv(2);
        return Leqn(nil, v6, v61);

v34:
    v61 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v61); }
/* error exit handlers */
v11:
    popv(2);
    return nil;
}



/* Code for multiply!-by!-constant!-mod!-p */

static Lisp_Object CC_multiplyKbyKconstantKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multiply-by-constant-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v28;
    stack[-2] = v0;
/* end of prologue */
    v85 = stack[-2];
    if (v85 == nil) goto v43;
    v100 = stack[-1];
    v85 = (Lisp_Object)17; /* 1 */
    if (v100 == v85) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v85 = stack[-2];
    if (!consp(v85)) goto v29;
    v85 = stack[-2];
    v85 = qcar(v85);
    v85 = (consp(v85) ? nil : lisp_true);
    goto v10;

v10:
    if (v85 == nil) goto v24;
    v100 = stack[-2];
    v85 = stack[-1];
    v85 = Lmodular_times(nil, v100, v85);
    env = stack[-4];
    v100 = v85;
    v85 = v100;
    v85 = (Lisp_Object)zerop(v85);
    v85 = v85 ? lisp_true : nil;
    env = stack[-4];
    if (v85 == nil) { popv(5); return onevalue(v100); }
    v85 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v85); }

v24:
    v85 = stack[-2];
    v85 = qcar(v85);
    stack[-3] = qcar(v85);
    v85 = stack[-2];
    v85 = qcar(v85);
    v100 = qcdr(v85);
    v85 = stack[-1];
    stack[0] = CC_multiplyKbyKconstantKmodKp(env, v100, v85);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-4];
    v85 = stack[-2];
    v100 = qcdr(v85);
    v85 = stack[-1];
    v85 = CC_multiplyKbyKconstantKmodKp(env, v100, v85);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-4];
    {
        Lisp_Object v91 = stack[-3];
        Lisp_Object v92 = stack[0];
        popv(5);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v91, v92, v85);
    }

v29:
    v85 = qvalue(elt(env, 2)); /* t */
    goto v10;

v43:
    v85 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v85); }
/* error exit handlers */
v101:
    popv(5);
    return nil;
}



/* Code for find2 */

static Lisp_Object CC_find2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v6, v71, v11;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v28;
    v71 = v0;
/* end of prologue */

v2:
    v11 = v6;
    v61 = nil;
    if (v11 == v61) goto v8;
    v61 = v6;
    v61 = qcar(v61);
    v71 = Lmember(nil, v61, v71);
    v61 = v6;
    v61 = qcdr(v61);
    v6 = v61;
    goto v2;

v8:
    v61 = v71;
    if (v61 == nil) goto v29;
    v61 = v71;
    v61 = qcdr(v61);
    return onevalue(v61);

v29:
    v61 = elt(env, 1); /* (stop) */
    return onevalue(v61);
}



/* Code for butes */

static Lisp_Object CC_butes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v27, v49;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for butes");
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
    push(nil);
/* copy arguments values to proper place */
    v49 = v0;
/* end of prologue */
    v11 = v49;
    v11 = qcar(v11);
    qvalue(elt(env, 1)) = v11; /* cha */
    v27 = qvalue(elt(env, 1)); /* cha */
    v11 = elt(env, 2); /* !  */
    if (v27 == v11) goto v33;
    v27 = qvalue(elt(env, 1)); /* cha */
    v11 = elt(env, 4); /* !$ */
    v11 = (v27 == v11 ? lisp_true : nil);
    goto v32;

v32:
    if (v11 == nil) goto v86;
    v11 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v11); }

v86:
    v11 = v49;
    stack[0] = qcar(v11);
    v11 = v49;
    v11 = qcdr(v11);
    v11 = CC_butes(env, v11);
    nil = C_nil;
    if (exception_pending()) goto v16;
    {
        Lisp_Object v23 = stack[0];
        popv(1);
        return cons(v23, v11);
    }

v33:
    v11 = qvalue(elt(env, 3)); /* t */
    goto v32;
/* error exit handlers */
v16:
    popv(1);
    return nil;
}



/* Code for mtp */

static Lisp_Object CC_mtp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v71, v11;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mtp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v71 = v0;
/* end of prologue */

v7:
    v6 = v71;
    if (v6 == nil) goto v13;
    v6 = v71;
    v11 = qcar(v6);
    v6 = qvalue(elt(env, 2)); /* frlis!* */
    v6 = Lmemq(nil, v11, v6);
    if (v6 == nil) goto v32;
    v6 = v71;
    v11 = qcar(v6);
    v6 = v71;
    v6 = qcdr(v6);
    v6 = Lmember(nil, v11, v6);
    if (v6 == nil) goto v45;
    v6 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v6);

v45:
    v6 = v71;
    v6 = qcdr(v6);
    v71 = v6;
    goto v7;

v32:
    v6 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v6);

v13:
    v6 = qvalue(elt(env, 1)); /* t */
    return onevalue(v6);
}



/* Code for nil2zero */

static Lisp_Object CC_nil2zero(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nil2zero");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v32 = v4;
    if (!(v32 == nil)) return onevalue(v4);
    v4 = (Lisp_Object)1; /* 0 */
    return onevalue(v4);
}



/* Code for pm!:free */

static Lisp_Object CC_pmTfree(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pm:free");
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
    v4 = v0;
/* end of prologue */
    fn = elt(env, 2); /* binding */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[0];
    v32 = elt(env, 1); /* unbound */
    v4 = (v4 == v32 ? lisp_true : nil);
    { popv(1); return onevalue(v4); }
/* error exit handlers */
v33:
    popv(1);
    return nil;
}



/* Code for vbcsize */

static Lisp_Object CC_vbcsize(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v27, v49;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vbcsize");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v27 = v28;
    stack[0] = v0;
/* end of prologue */

v8:
    v49 = v27;
    v11 = (Lisp_Object)-15; /* -1 */
    if (((int32_t)(v49)) > ((int32_t)(v11))) goto v43;
    v11 = stack[0];
    if (!consp(v11)) { popv(2); return onevalue(v27); }
    v11 = stack[0];
    v11 = qcar(v11);
    v27 = (Lisp_Object)((int32_t)(v27) + 0x10);
    v11 = CC_vbcsize(env, v11, v27);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    v27 = v11;
    v11 = v27;
    if (v11 == nil) goto v42;
    v11 = stack[0];
    v11 = qcdr(v11);
    stack[0] = v11;
    goto v8;

v42:
    v11 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v11); }

v43:
    v11 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v11); }
/* error exit handlers */
v16:
    popv(2);
    return nil;
}



/* Code for wedgefax */

static Lisp_Object CC_wedgefax(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v15, v10;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgefax");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    v22 = v15;
    v10 = elt(env, 1); /* wedge */
    if (!consp(v22)) goto v54;
    v22 = qcar(v22);
    if (!(v22 == v10)) goto v54;
    v22 = v15;
    v22 = qcdr(v22);
    return onevalue(v22);

v54:
    v22 = v15;
    return ncons(v22);
}



/* Code for csl_normbf */

static Lisp_Object CC_csl_normbf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v102, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for csl_normbf");
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
    v78 = stack[-2];
    v78 = qcdr(v78);
    v102 = qcar(v78);
    stack[0] = v102;
    v78 = (Lisp_Object)1; /* 0 */
    if (v102 == v78) goto v3;
    v102 = stack[0];
    v78 = (Lisp_Object)1; /* 0 */
    v78 = (Lisp_Object)lessp2(v102, v78);
    nil = C_nil;
    if (exception_pending()) goto v85;
    v78 = v78 ? lisp_true : nil;
    env = stack[-4];
    if (v78 == nil) goto v29;
    v78 = stack[0];
    v78 = negate(v78);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    stack[0] = v78;
    v78 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v78;
    goto v29;

v29:
    v78 = stack[0];
    fn = elt(env, 4); /* lsd */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    stack[-1] = v78;
    v78 = stack[-1];
    v78 = negate(v78);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    v78 = ash(stack[0], v78);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    stack[0] = v78;
    v78 = stack[-3];
    if (v78 == nil) goto v25;
    v78 = stack[0];
    v78 = negate(v78);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    stack[0] = v78;
    goto v25;

v25:
    v102 = stack[-1];
    v78 = stack[-2];
    v78 = qcdr(v78);
    v78 = qcdr(v78);
    v78 = plus2(v102, v78);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    stack[-1] = v78;
    v79 = elt(env, 3); /* !:rd!: */
    v102 = stack[0];
    v78 = stack[-1];
    popv(5);
    return list2star(v79, v102, v78);

v3:
    v78 = elt(env, 1); /* (!:rd!: 0 . 0) */
    { popv(5); return onevalue(v78); }
/* error exit handlers */
v85:
    popv(5);
    return nil;
}



/* Code for !*physopp */

static Lisp_Object CC_Hphysopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v70;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *physopp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v70 = v0;
/* end of prologue */
    v31 = v70;
    if (!consp(v31)) goto v13;
    v31 = v70;
    v31 = qcar(v31);
    if (symbolp(v31)) goto v42;
    v31 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v31);

v42:
    v31 = v70;
    v31 = qcar(v31);
    v70 = elt(env, 2); /* phystype */
    return get(v31, v70);

v13:
    v31 = v70;
    if (symbolp(v31)) goto v54;
    v31 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v31);

v54:
    v31 = v70;
    v70 = elt(env, 2); /* phystype */
    return get(v31, v70);
}



/* Code for union_edge */

static Lisp_Object CC_union_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for union_edge");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v28;
    stack[-1] = v0;
/* end of prologue */
    v46 = stack[-1];
    v60 = stack[0];
    fn = elt(env, 1); /* memq_edgelist */
    v60 = (*qfn2(fn))(qenv(fn), v46, v60);
    nil = C_nil;
    if (exception_pending()) goto v20;
    if (!(v60 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v46 = stack[-1];
    v60 = stack[0];
    popv(2);
    return cons(v46, v60);
/* error exit handlers */
v20:
    popv(2);
    return nil;
}



/* Code for addf */

static Lisp_Object CC_addf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v124, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addf");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v28;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = nil;
    goto v5;

v5:
    v123 = stack[-2];
    if (v123 == nil) goto v33;
    v123 = stack[-1];
    if (v123 == nil) goto v26;
    v123 = stack[-2];
    if (!consp(v123)) goto v42;
    v123 = stack[-2];
    v123 = qcar(v123);
    v123 = (consp(v123) ? nil : lisp_true);
    goto v12;

v12:
    if (v123 == nil) goto v38;
    v124 = stack[-2];
    v123 = stack[-1];
    fn = elt(env, 2); /* addd */
    v123 = (*qfn2(fn))(qenv(fn), v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    {
        Lisp_Object v127 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v127, v123);
    }

v38:
    v123 = stack[-1];
    if (!consp(v123)) goto v99;
    v123 = stack[-1];
    v123 = qcar(v123);
    v123 = (consp(v123) ? nil : lisp_true);
    goto v63;

v63:
    if (v123 == nil) goto v101;
    v124 = stack[-1];
    v123 = stack[-2];
    fn = elt(env, 2); /* addd */
    v123 = (*qfn2(fn))(qenv(fn), v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    {
        Lisp_Object v128 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v128, v123);
    }

v101:
    v123 = stack[-2];
    v123 = qcar(v123);
    v124 = qcar(v123);
    v123 = stack[-1];
    v123 = qcar(v123);
    v123 = qcar(v123);
    if (equal(v124, v123)) goto v90;
    v123 = stack[-2];
    v123 = qcar(v123);
    v124 = qcar(v123);
    v123 = stack[-1];
    v123 = qcar(v123);
    v123 = qcar(v123);
    fn = elt(env, 4); /* ordpp */
    v123 = (*qfn2(fn))(qenv(fn), v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    if (v123 == nil) goto v129;
    v123 = stack[-2];
    v124 = qcar(v123);
    v123 = stack[0];
    v123 = cons(v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    stack[0] = v123;
    v123 = stack[-2];
    v123 = qcdr(v123);
    stack[-2] = v123;
    goto v5;

v129:
    v123 = stack[-1];
    v124 = qcar(v123);
    v123 = stack[0];
    v123 = cons(v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    stack[0] = v123;
    v123 = stack[-1];
    v123 = qcdr(v123);
    stack[-1] = v123;
    goto v5;

v90:
    stack[-3] = stack[0];
    v123 = stack[-2];
    v123 = qcar(v123);
    v124 = qcdr(v123);
    v123 = stack[-1];
    v123 = qcar(v123);
    v123 = qcdr(v123);
    stack[0] = CC_addf(env, v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    v123 = stack[-2];
    v124 = qcdr(v123);
    v123 = stack[-1];
    v123 = qcdr(v123);
    v123 = CC_addf(env, v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    v124 = stack[0];
    v125 = v124;
    if (v125 == nil) goto v84;
    v125 = stack[-2];
    v125 = qcar(v125);
    v125 = qcar(v125);
    v123 = acons(v125, v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    goto v84;

v84:
    {
        Lisp_Object v130 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v130, v123);
    }

v99:
    v123 = qvalue(elt(env, 1)); /* t */
    goto v63;

v42:
    v123 = qvalue(elt(env, 1)); /* t */
    goto v12;

v26:
    v124 = stack[0];
    v123 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v124, v123);
    }

v33:
    v124 = stack[0];
    v123 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v124, v123);
    }
/* error exit handlers */
v126:
    popv(5);
    return nil;
}



/* Code for expdrmacro */

static Lisp_Object CC_expdrmacro(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v24, v40;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expdrmacro");
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
    v23 = stack[0];
    fn = elt(env, 7); /* getrmacro */
    v23 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    v40 = v23;
    if (v23 == nil) goto v4;
    v24 = stack[0];
    v23 = elt(env, 2); /* noexpand */
    v23 = Lflagp(nil, v24, v23);
    env = stack[-1];
    goto v3;

v3:
    if (v23 == nil) goto v1;
    v23 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v23); }

v1:
    v23 = qvalue(elt(env, 4)); /* !*cref */
    if (v23 == nil) { popv(2); return onevalue(v40); }
    v24 = stack[0];
    v23 = elt(env, 5); /* expand */
    v23 = Lflagp(nil, v24, v23);
    env = stack[-1];
    if (v23 == nil) goto v12;
    v23 = qvalue(elt(env, 3)); /* nil */
    goto v39;

v39:
    if (v23 == nil) { popv(2); return onevalue(v40); }
    v23 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v23); }

v12:
    v23 = qvalue(elt(env, 6)); /* !*force */
    v23 = (v23 == nil ? lisp_true : nil);
    goto v39;

v4:
    v23 = qvalue(elt(env, 1)); /* t */
    goto v3;
/* error exit handlers */
v41:
    popv(2);
    return nil;
}



/* Code for getrtypecar */

static Lisp_Object CC_getrtypecar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrtypecar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v43 = v0;
/* end of prologue */
    v43 = qcar(v43);
    {
        fn = elt(env, 1); /* getrtype */
        return (*qfn1(fn))(qenv(fn), v43);
    }
}



/* Code for addd */

static Lisp_Object CC_addd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addd");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v28;
    stack[-1] = v0;
/* end of prologue */
    v63 = nil;
    goto v5;

v5:
    v62 = stack[0];
    if (v62 == nil) goto v35;
    v62 = stack[0];
    if (!consp(v62)) goto v26;
    v62 = stack[0];
    v62 = qcar(v62);
    v62 = (consp(v62) ? nil : lisp_true);
    goto v29;

v29:
    if (v62 == nil) goto v17;
    stack[-2] = v63;
    v63 = stack[-1];
    v62 = stack[0];
    fn = elt(env, 2); /* adddm */
    v62 = (*qfn2(fn))(qenv(fn), v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    {
        Lisp_Object v65 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v65, v62);
    }

v17:
    v62 = stack[0];
    v62 = qcar(v62);
    v62 = cons(v62, v63);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    v63 = v62;
    v62 = stack[0];
    v62 = qcdr(v62);
    stack[0] = v62;
    goto v5;

v26:
    v62 = qvalue(elt(env, 1)); /* t */
    goto v29;

v35:
    v62 = stack[-1];
    {
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v63, v62);
    }
/* error exit handlers */
v53:
    popv(4);
    return nil;
}



/* Code for sub2chk */

static Lisp_Object CC_sub2chk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v86, v30;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sub2chk");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v30 = v0;
/* end of prologue */
    v48 = qvalue(elt(env, 1)); /* subfg!* */
    if (v48 == nil) goto v43;
    v86 = v30;
    v48 = qvalue(elt(env, 2)); /* powlis!* */
    v48 = Latsoc(nil, v86, v48);
    if (!(v48 == nil)) goto v13;
    v48 = v30;
    if (!consp(v48)) goto v39;
    v48 = v30;
    v86 = qcar(v48);
    v48 = elt(env, 3); /* (expt sqrt) */
    v48 = Lmemq(nil, v86, v48);
    goto v22;

v22:
    if (!(v48 == nil)) goto v13;

v43:
    v48 = nil;
    return onevalue(v48);

v13:
    v48 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 6)) = v48; /* !*sub2 */
    return onevalue(v48);

v39:
    v48 = qvalue(elt(env, 4)); /* nil */
    goto v22;
}



/* Code for mo_divides!? */

static Lisp_Object CC_mo_dividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_divides?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v33 = v28;
    v34 = v0;
/* end of prologue */
    v34 = qcar(v34);
    v33 = qcar(v33);
    {
        fn = elt(env, 1); /* mo!=modiv1 */
        return (*qfn2(fn))(qenv(fn), v34, v33);
    }
}



/* Code for multdm */

static Lisp_Object CC_multdm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v77, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multdm");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v77 = v28;
    v131 = v0;
/* end of prologue */
    v79 = v131;
    if (!consp(v79)) goto v2;
    v79 = qvalue(elt(env, 1)); /* nil */
    goto v1;

v1:
    if (v79 == nil) goto v57;
    v79 = v131;
    v79 = times2(v79, v77);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[0];
    v131 = v79;
    v79 = qvalue(elt(env, 2)); /* dmode!* */
    if (v79 == nil) goto v38;
    v77 = qvalue(elt(env, 2)); /* dmode!* */
    v79 = elt(env, 4); /* convert */
    v79 = Lflagp(nil, v77, v79);
    env = stack[0];
    v79 = (v79 == nil ? lisp_true : nil);
    goto v69;

v69:
    if (!(v79 == nil)) { popv(1); return onevalue(v131); }
    v77 = qvalue(elt(env, 2)); /* dmode!* */
    v79 = elt(env, 5); /* i2d */
    v79 = get(v77, v79);
    v77 = v131;
        popv(1);
        return Lapply1(nil, v79, v77);

v38:
    v79 = qvalue(elt(env, 3)); /* t */
    goto v69;

v57:
    v79 = elt(env, 6); /* times */
    {
        popv(1);
        fn = elt(env, 7); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v131, v77, v79);
    }

v2:
    v79 = v77;
    v79 = (consp(v79) ? nil : lisp_true);
    goto v1;
/* error exit handlers */
v93:
    popv(1);
    return nil;
}



/* Code for dssoc */

static Lisp_Object CC_dssoc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v20, v69, v38;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dssoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v69 = v28;
    v38 = v0;
/* end of prologue */

v43:
    v21 = v69;
    if (v21 == nil) goto v1;
    v20 = v38;
    v21 = v69;
    v21 = qcar(v21);
    v21 = qcdr(v21);
    if (equal(v20, v21)) goto v32;
    v21 = v69;
    v21 = qcdr(v21);
    v69 = v21;
    goto v43;

v32:
    v21 = v69;
    v21 = qcar(v21);
    return onevalue(v21);

v1:
    v21 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v21);
}



/* Code for noncomlistp */

static Lisp_Object CC_noncomlistp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomlistp");
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

v7:
    v22 = stack[0];
    v22 = Lconsp(nil, v22);
    env = stack[-1];
    if (v22 == nil) goto v13;
    v22 = stack[0];
    v22 = qcar(v22);
    fn = elt(env, 2); /* noncomp1 */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-1];
    if (!(v22 == nil)) { popv(2); return onevalue(v22); }
    v22 = stack[0];
    v22 = qcdr(v22);
    stack[0] = v22;
    goto v7;

v13:
    v22 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v22); }
/* error exit handlers */
v10:
    popv(2);
    return nil;
}



/* Code for rnzerop!: */

static Lisp_Object CC_rnzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnzerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v0;
/* end of prologue */
    v32 = qcdr(v32);
    v33 = qcar(v32);
    v32 = (Lisp_Object)1; /* 0 */
    v32 = (v33 == v32 ? lisp_true : nil);
    return onevalue(v32);
}



/* Code for modonep!: */

static Lisp_Object CC_modonepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modonep:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v32 = qcdr(v4);
    v4 = (Lisp_Object)17; /* 1 */
    v4 = (v32 == v4 ? lisp_true : nil);
    return onevalue(v4);
}



/* Code for eolcheck */

static Lisp_Object MS_CDECL CC_eolcheck(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "eolcheck");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for eolcheck");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v86 = qvalue(elt(env, 1)); /* !*eoldelimp */
    if (!(v86 == nil)) goto v54;
    v86 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v86); }

v54:
    v30 = qvalue(elt(env, 3)); /* nxtsym!* */
    v86 = qvalue(elt(env, 4)); /* !$eol!$ */
    if (v30 == v86) goto v46;
    v86 = nil;
    { popv(1); return onevalue(v86); }

v46:
    v30 = qvalue(elt(env, 5)); /* cursym!* */
    v86 = elt(env, 6); /* end */
    if (v30 == v86) goto v58;
    fn = elt(env, 8); /* token1 */
    v86 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[0];
    goto v26;

v26:
    qvalue(elt(env, 3)) = v86; /* nxtsym!* */
    goto v54;

v58:
    v86 = elt(env, 7); /* !; */
    goto v26;
/* error exit handlers */
v37:
    popv(1);
    return nil;
}



/* Code for mtchp1 */

static Lisp_Object MS_CDECL CC_mtchp1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v28,
                         Lisp_Object v47, Lisp_Object v44, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v103, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "mtchp1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mtchp1");
#endif
    if (stack >= stacklimit)
    {
        push4(v44,v47,v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v28,v47,v44);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v143 = v44;
    stack[0] = v47;
    stack[-1] = v28;
    stack[-2] = v0;
/* end of prologue */
    v103 = stack[-2];
    v143 = stack[-1];
    if (equal(v103, v143)) goto v3;
    v143 = stack[-2];
    v103 = qcar(v143);
    v143 = stack[-1];
    v143 = qcar(v143);
    fn = elt(env, 5); /* mchk!* */
    v143 = (*qfn2(fn))(qenv(fn), v103, v143);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    stack[-3] = v143;
    if (v143 == nil) goto v15;
    v143 = stack[-1];
    v103 = qcdr(v143);
    v143 = qvalue(elt(env, 2)); /* frlis!* */
    v143 = Lmemq(nil, v103, v143);
    if (v143 == nil) goto v42;
    v143 = stack[-2];
    v103 = qcdr(v143);
    v143 = (Lisp_Object)17; /* 1 */
    if (v103 == v143) goto v17;
    v143 = stack[-1];
    v104 = qcdr(v143);
    v103 = stack[-3];
    v143 = stack[-2];
    v143 = qcdr(v143);
    fn = elt(env, 6); /* powmtch */
    v143 = (*qfnn(fn))(qenv(fn), 3, v104, v103, v143);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    stack[-3] = v143;
    v143 = (v143 == nil ? lisp_true : nil);
    goto v49;

v49:
    if (v143 == nil) goto v94;
    v143 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v143); }

v94:
    stack[0] = stack[-3];
    v143 = stack[-1];
    v103 = qcdr(v143);
    v143 = stack[-2];
    v143 = qcdr(v143);
    v143 = cons(v103, v143);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    {
        Lisp_Object v144 = stack[0];
        popv(5);
        fn = elt(env, 7); /* mapcons */
        return (*qfn2(fn))(qenv(fn), v144, v143);
    }

v17:
    v143 = qvalue(elt(env, 3)); /* t */
    goto v49;

v42:
    v143 = stack[0];
    if (v143 == nil) goto v145;
    v143 = stack[-2];
    v103 = qcdr(v143);
    v143 = stack[-1];
    v143 = qcdr(v143);
    if (!(equal(v103, v143))) goto v82;

v145:
    v143 = stack[-1];
    v143 = qcdr(v143);
    if (is_number(v143)) goto v146;
    v143 = qvalue(elt(env, 3)); /* t */
    goto v119;

v119:
    if (v143 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    else goto v82;

v82:
    v143 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v143); }

v146:
    v143 = stack[-2];
    v143 = qcdr(v143);
    if (is_number(v143)) goto v114;
    v143 = qvalue(elt(env, 3)); /* t */
    goto v119;

v114:
    v143 = qvalue(elt(env, 4)); /* !*mcd */
    if (v143 == nil) goto v147;
    v143 = stack[-2];
    v103 = qcdr(v143);
    v143 = stack[-1];
    v143 = qcdr(v143);
    v143 = (Lisp_Object)lessp2(v103, v143);
    nil = C_nil;
    if (exception_pending()) goto v125;
    v143 = v143 ? lisp_true : nil;
    env = stack[-4];
    goto v119;

v147:
    v143 = stack[-2];
    v103 = qcdr(v143);
    v143 = stack[-1];
    v143 = qcdr(v143);
    v103 = times2(v103, v143);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    v143 = (Lisp_Object)1; /* 0 */
    v143 = (Lisp_Object)lessp2(v103, v143);
    nil = C_nil;
    if (exception_pending()) goto v125;
    v143 = v143 ? lisp_true : nil;
    env = stack[-4];
    if (!(v143 == nil)) goto v119;
    v143 = stack[-2];
    v143 = qcdr(v143);
    stack[0] = Labsval(nil, v143);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    v143 = stack[-1];
    v143 = qcdr(v143);
    v143 = Labsval(nil, v143);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    v143 = (Lisp_Object)lessp2(stack[0], v143);
    nil = C_nil;
    if (exception_pending()) goto v125;
    v143 = v143 ? lisp_true : nil;
    env = stack[-4];
    goto v119;

v15:
    v143 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v143); }

v3:
    v143 = qvalue(elt(env, 1)); /* nil */
    popv(5);
    return ncons(v143);
/* error exit handlers */
v125:
    popv(5);
    return nil;
}



/* Code for mri_floorkernelp */

static Lisp_Object CC_mri_floorkernelp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_floorkernelp");
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
    v4 = v0;
/* end of prologue */
    v32 = v4;
    v4 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* kernels1 */
    v4 = (*qfn2(fn))(qenv(fn), v32, v4);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* mri_floorp */
        return (*qfn1(fn))(qenv(fn), v4);
    }
/* error exit handlers */
v33:
    popv(1);
    return nil;
}



/* Code for qqe_qoptailp */

static Lisp_Object CC_qqe_qoptailp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v54;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_qoptailp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v35 = v0;
/* end of prologue */
    v54 = v35;
    v35 = elt(env, 1); /* (rtail ltail) */
    v35 = Lmemq(nil, v54, v35);
    if (v35 == nil) goto v43;
    v35 = qvalue(elt(env, 2)); /* t */
    return onevalue(v35);

v43:
    v35 = nil;
    return onevalue(v35);
}



/* Code for lto_setequalq */

static Lisp_Object CC_lto_setequalq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v79, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_setequalq");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v28;
    stack[-1] = v0;
/* end of prologue */
    v102 = qvalue(elt(env, 1)); /* !*rlsetequalqhash */
    if (v102 == nil) goto v69;
    v79 = stack[-1];
    v102 = stack[0];
    fn = elt(env, 4); /* lto_hashequalq */
    v102 = (*qfn2(fn))(qenv(fn), v79, v102);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    goto v54;

v54:
    if (v102 == nil) goto v37;
    v102 = qvalue(elt(env, 3)); /* t */
    v77 = v102;
    goto v71;

v71:
    v102 = v77;
    if (v102 == nil) { popv(3); return onevalue(v77); }
    v102 = stack[-1];
    if (v102 == nil) { popv(3); return onevalue(v77); }
    v102 = stack[-1];
    v102 = qcar(v102);
    v79 = v102;
    v102 = stack[0];
    v102 = Lmemq(nil, v79, v102);
    if (v102 == nil) goto v59;
    v102 = stack[-1];
    v102 = qcdr(v102);
    stack[-1] = v102;
    goto v71;

v59:
    v102 = qvalue(elt(env, 2)); /* nil */
    v77 = v102;
    goto v71;

v37:
    v102 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v102); }

v69:
    v79 = stack[-1];
    v102 = stack[0];
    fn = elt(env, 5); /* lto_equallengthp */
    v102 = (*qfn2(fn))(qenv(fn), v79, v102);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    goto v54;
/* error exit handlers */
v94:
    popv(3);
    return nil;
}



/* Code for numlis */

static Lisp_Object CC_numlis(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v29;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numlis");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v10 = v0;
/* end of prologue */

v7:
    v29 = v10;
    if (v29 == nil) goto v13;
    v29 = v10;
    v29 = qcar(v29);
    if (is_number(v29)) goto v36;
    v10 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v10);

v36:
    v10 = qcdr(v10);
    goto v7;

v13:
    v10 = qvalue(elt(env, 1)); /* t */
    return onevalue(v10);
}



/* Code for constp */

static Lisp_Object CC_constp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v60;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for constp");
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
    v58 = v0;
/* end of prologue */
    v60 = v58;
    v60 = (is_number(v60) ? lisp_true : nil);
    if (!(v60 == nil)) { popv(1); return onevalue(v60); }
    v60 = v58;
    v60 = Lconsp(nil, v60);
    env = stack[0];
    if (v60 == nil) goto v2;
    v58 = qcar(v58);
    v60 = qvalue(elt(env, 2)); /* domainlist!* */
    v58 = Lmemq(nil, v58, v60);
    { popv(1); return onevalue(v58); }

v2:
    v58 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v58); }
}



/* Code for replus1 */

static Lisp_Object CC_replus1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v23, v24;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replus1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v24 = v0;
/* end of prologue */
    v16 = v24;
    if (v16 == nil) goto v13;
    v16 = v24;
    if (!consp(v16)) goto v32;
    v23 = v24;
    v16 = elt(env, 2); /* plus */
    if (!consp(v23)) goto v38;
    v23 = qcar(v23);
    if (!(v23 == v16)) goto v38;
    v16 = v24;
    v16 = qcdr(v16);
    goto v4;

v4:
    if (!(v16 == nil)) return onevalue(v24);
    v16 = v24;
    v16 = qcdr(v16);
    if (v16 == nil) goto v50;
    v16 = elt(env, 2); /* plus */
    v23 = v24;
    return cons(v16, v23);

v50:
    v16 = v24;
    v16 = qcar(v16);
    return onevalue(v16);

v38:
    v16 = qvalue(elt(env, 3)); /* nil */
    goto v4;

v32:
    v16 = qvalue(elt(env, 1)); /* t */
    goto v4;

v13:
    v16 = (Lisp_Object)1; /* 0 */
    return onevalue(v16);
}



/* Code for buchvevdivides!? */

static Lisp_Object CC_buchvevdividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v86, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for buchvevdivides?");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v28;
    stack[-1] = v0;
/* end of prologue */
    v86 = stack[0];
    v48 = stack[-1];
    fn = elt(env, 4); /* vevmtest!? */
    v48 = (*qfn2(fn))(qenv(fn), v86, v48);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    if (v48 == nil) goto v43;
    v48 = qvalue(elt(env, 2)); /* gmodule!* */
    if (v48 == nil) goto v22;
    v30 = stack[-1];
    v86 = stack[0];
    v48 = qvalue(elt(env, 2)); /* gmodule!* */
    {
        popv(3);
        fn = elt(env, 5); /* gevcompatible1 */
        return (*qfnn(fn))(qenv(fn), 3, v30, v86, v48);
    }

v22:
    v48 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v48); }

v43:
    v48 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v48); }
/* error exit handlers */
v18:
    popv(3);
    return nil;
}



/* Code for sublistp */

static Lisp_Object CC_sublistp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v61, v6, v71;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sublistp");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v61 = v28;
    v6 = v0;
/* end of prologue */

v7:
    v70 = v6;
    if (v70 == nil) goto v43;
    v70 = v6;
    v71 = qcar(v70);
    v70 = v61;
    v70 = Lmember(nil, v71, v70);
    if (v70 == nil) goto v33;
    v70 = v6;
    stack[0] = qcdr(v70);
    v70 = v6;
    v70 = qcar(v70);
    v70 = Ldelete(nil, v70, v61);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-1];
    v6 = stack[0];
    v61 = v70;
    goto v7;

v33:
    v70 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v70); }

v43:
    v70 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v70); }
/* error exit handlers */
v27:
    popv(2);
    return nil;
}



/* Code for !:times */

static Lisp_Object CC_Ttimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v16, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :times");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v16 = v28;
    v23 = v0;
/* end of prologue */
    v17 = v23;
    if (v17 == nil) goto v2;
    v17 = v16;
    v17 = (v17 == nil ? lisp_true : nil);
    goto v1;

v1:
    if (v17 == nil) goto v5;
    v17 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v17);

v5:
    v17 = v23;
    if (!consp(v17)) goto v10;
    v17 = qvalue(elt(env, 2)); /* nil */
    goto v15;

v15:
    if (v17 == nil) goto v61;
    v17 = v23;
    return times2(v17, v16);

v61:
    v17 = elt(env, 3); /* times */
    {
        fn = elt(env, 4); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v23, v16, v17);
    }

v10:
    v17 = v16;
    v17 = (consp(v17) ? nil : lisp_true);
    goto v15;

v2:
    v17 = qvalue(elt(env, 1)); /* t */
    goto v1;
}



/* Code for pprin2 */

static Lisp_Object CC_pprin2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v29;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pprin2");
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
    v10 = qvalue(elt(env, 1)); /* !*pprinbuf!* */
    v10 = cons(v29, v10);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    qvalue(elt(env, 1)) = v10; /* !*pprinbuf!* */
    stack[-1] = qvalue(elt(env, 2)); /* !*posn!* */
    v10 = stack[0];
    v10 = Lexplodec(nil, v10);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v10 = Llength(nil, v10);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v10 = plus2(stack[-1], v10);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    qvalue(elt(env, 2)) = v10; /* !*posn!* */
    v10 = nil;
    { popv(3); return onevalue(v10); }
/* error exit handlers */
v60:
    popv(3);
    return nil;
}



/* Code for isanindex */

static Lisp_Object CC_isanindex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v99, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isanindex");
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
    v52 = v0;
/* end of prologue */
    v63 = v52;
    if (symbolp(v63)) goto v33;
    v63 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v63); }

v33:
    v99 = v52;
    v63 = qvalue(elt(env, 2)); /* physopindices!* */
    v63 = Lmemq(nil, v99, v63);
    if (!(v63 == nil)) { popv(1); return onevalue(v63); }
    v99 = v52;
    v63 = qvalue(elt(env, 3)); /* physopvarind!* */
    v63 = Lmember(nil, v99, v63);
    if (!(v63 == nil)) { popv(1); return onevalue(v63); }
    v99 = v52;
    v63 = qvalue(elt(env, 4)); /* frlis!* */
    v63 = Lmemq(nil, v99, v63);
    if (v63 == nil) goto v12;
    v99 = v52;
    v63 = qvalue(elt(env, 5)); /* frasc!* */
    fn = elt(env, 6); /* revassoc */
    v63 = (*qfn2(fn))(qenv(fn), v99, v63);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[0];
    v99 = qvalue(elt(env, 2)); /* physopindices!* */
    v63 = Lmember(nil, v63, v99);
    { popv(1); return onevalue(v63); }

v12:
    v63 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v63); }
/* error exit handlers */
v64:
    popv(1);
    return nil;
}



/* Code for formlis */

static Lisp_Object MS_CDECL CC_formlis(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v28,
                         Lisp_Object v47, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v48, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formlis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formlis");
#endif
    if (stack >= stacklimit)
    {
        push3(v47,v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v28,v47);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v47;
    stack[-1] = v28;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v8;

v8:
    v50 = stack[-2];
    if (v50 == nil) goto v3;
    v50 = stack[-2];
    v86 = qcar(v50);
    v48 = stack[-1];
    v50 = stack[0];
    fn = elt(env, 1); /* form1 */
    v48 = (*qfnn(fn))(qenv(fn), 3, v86, v48, v50);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-4];
    v50 = stack[-3];
    v50 = cons(v48, v50);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-4];
    stack[-3] = v50;
    v50 = stack[-2];
    v50 = qcdr(v50);
    stack[-2] = v50;
    goto v8;

v3:
    v50 = stack[-3];
        popv(5);
        return Lnreverse(nil, v50);
/* error exit handlers */
v31:
    popv(5);
    return nil;
}



/* Code for aeval!* */

static Lisp_Object CC_aevalH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aeval*");
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
    stack[-1] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v35 = qvalue(elt(env, 2)); /* nil */
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    qvalue(elt(env, 1)) = v35; /* alglist!* */
    v54 = stack[0];
    v35 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 3); /* reval1 */
    v35 = (*qfn2(fn))(qenv(fn), v54, v35);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* alglist!* */
    { popv(3); return onevalue(v35); }
/* error exit handlers */
v14:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* alglist!* */
    popv(3);
    return nil;
}



/* Code for bc_prod */

static Lisp_Object CC_bc_prod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_prod");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v32 = v28;
    v33 = v0;
/* end of prologue */
    fn = elt(env, 1); /* multf */
    v32 = (*qfn2(fn))(qenv(fn), v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* bc!=simp */
        return (*qfn1(fn))(qenv(fn), v32);
    }
/* error exit handlers */
v34:
    popv(1);
    return nil;
}



/* Code for dlesslex */

static Lisp_Object CC_dlesslex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v31, v70, v61;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dlesslex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v31 = v28;
    v70 = v0;
/* end of prologue */

v43:
    v18 = v70;
    if (v18 == nil) goto v1;
    v18 = v70;
    v61 = qcar(v18);
    v18 = v31;
    v18 = qcar(v18);
    if (((int32_t)(v61)) > ((int32_t)(v18))) goto v32;
    v18 = v70;
    v61 = qcar(v18);
    v18 = v31;
    v18 = qcar(v18);
    if (((int32_t)(v61)) < ((int32_t)(v18))) goto v26;
    v18 = v70;
    v18 = qcdr(v18);
    v70 = v18;
    v18 = v31;
    v18 = qcdr(v18);
    v31 = v18;
    goto v43;

v26:
    v18 = qvalue(elt(env, 2)); /* t */
    return onevalue(v18);

v32:
    v18 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v18);

v1:
    v18 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v18);
}



/* Code for reduce_pv0 */

static Lisp_Object MS_CDECL CC_reduce_pv0(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v28,
                         Lisp_Object v47, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "reduce_pv0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce_pv0");
#endif
    if (stack >= stacklimit)
    {
        push3(v47,v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v28,v47);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v47;
    stack[-4] = v28;
    stack[0] = v0;
/* end of prologue */
    v111 = stack[-4];
    if (v111 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v111 = stack[0];
    if (v111 == nil) goto v3;
    v111 = stack[0];
    stack[-5] = v111;
    goto v29;

v29:
    v111 = stack[-5];
    if (v111 == nil) goto v10;
    v111 = stack[-4];
    if (v111 == nil) goto v10;
    v111 = stack[-5];
    v111 = qcar(v111);
    v112 = qcdr(v111);
    v111 = stack[-4];
    v111 = qcar(v111);
    v111 = qcdr(v111);
    v111 = (Lisp_Object)greaterp2(v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v136;
    v111 = v111 ? lisp_true : nil;
    env = stack[-6];
    if (v111 == nil) goto v10;
    v111 = stack[-5];
    v111 = qcdr(v111);
    stack[-5] = v111;
    goto v29;

v10:
    v111 = stack[-5];
    if (v111 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v111 = stack[-4];
    if (v111 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v111 = stack[-4];
    v111 = qcar(v111);
    v112 = qcdr(v111);
    v111 = stack[-5];
    v111 = qcar(v111);
    v111 = qcdr(v111);
    if (!(equal(v112, v111))) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v111 = stack[-5];
    v111 = qcar(v111);
    v112 = qcar(v111);
    v111 = stack[-4];
    v111 = qcar(v111);
    v111 = qcar(v111);
    fn = elt(env, 3); /* lcm */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-6];
    stack[-2] = v111;
    v112 = stack[-2];
    v111 = stack[-5];
    v111 = qcar(v111);
    v111 = qcar(v111);
    v111 = quot2(v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-6];
    fn = elt(env, 4); /* pv_multc */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-6];
    stack[0] = stack[-4];
    v112 = stack[-2];
    v111 = stack[-4];
    v111 = qcar(v111);
    v111 = qcar(v111);
    v111 = quot2(v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-6];
    v111 = negate(v111);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-6];
    fn = elt(env, 4); /* pv_multc */
    v111 = (*qfn2(fn))(qenv(fn), stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-6];
    fn = elt(env, 5); /* pv_add */
    v111 = (*qfn2(fn))(qenv(fn), stack[-1], v111);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-6];
    stack[0] = v111;
    v111 = stack[-3];
    if (v111 == nil) goto v115;
    v111 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v111; /* pv_den */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v115:
    stack[-1] = qvalue(elt(env, 2)); /* pv_den */
    v112 = stack[-2];
    v111 = stack[-5];
    v111 = qcar(v111);
    v111 = qcar(v111);
    v111 = quot2(v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-6];
    v111 = times2(stack[-1], v111);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-6];
    qvalue(elt(env, 2)) = v111; /* pv_den */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v3:
    v111 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v111); }
/* error exit handlers */
v136:
    popv(7);
    return nil;
}



/* Code for upbve */

static Lisp_Object CC_upbve(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for upbve");
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
    v34 = stack[0];
    v34 = Lupbv(nil, v34);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-1];
    if (v34 == nil) goto v13;
    v34 = stack[0];
    v34 = Lupbv(nil, v34);
    nil = C_nil;
    if (exception_pending()) goto v54;
    popv(2);
    return add1(v34);

v13:
    v34 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v34); }
/* error exit handlers */
v54:
    popv(2);
    return nil;
}



/* Code for rnequiv */

static Lisp_Object CC_rnequiv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v15, v10;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnequiv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    v22 = v15;
    v22 = qcdr(v22);
    v15 = v22;
    v10 = qcdr(v22);
    v22 = (Lisp_Object)17; /* 1 */
    if (v10 == v22) goto v13;
    v22 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v22);

v13:
    v22 = v15;
    v22 = qcar(v22);
    return onevalue(v22);
}



/* Code for multd */

static Lisp_Object CC_multd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multd");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v28;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v5;

v5:
    v121 = stack[-1];
    if (v121 == nil) goto v2;
    v122 = stack[-1];
    v121 = (Lisp_Object)17; /* 1 */
    if (v122 == v121) goto v26;
    v121 = stack[-1];
    if (!consp(v121)) goto v42;
    v121 = stack[-1];
    v121 = qcar(v121);
    v121 = (consp(v121) ? nil : lisp_true);
    goto v12;

v12:
    if (v121 == nil) goto v63;
    stack[0] = stack[-3];
    v122 = stack[-2];
    v121 = stack[-1];
    fn = elt(env, 2); /* multdm */
    v121 = (*qfn2(fn))(qenv(fn), v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    {
        Lisp_Object v72 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v72, v121);
    }

v63:
    v121 = stack[-1];
    v121 = qcar(v121);
    stack[0] = qcar(v121);
    v122 = stack[-2];
    v121 = stack[-1];
    v121 = qcar(v121);
    v121 = qcdr(v121);
    v122 = CC_multd(env, v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    v121 = stack[-3];
    v121 = acons(stack[0], v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    stack[-3] = v121;
    v121 = stack[-1];
    v121 = qcdr(v121);
    stack[-1] = v121;
    goto v5;

v42:
    v121 = qvalue(elt(env, 1)); /* t */
    goto v12;

v26:
    v122 = stack[-3];
    v121 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v122, v121);
    }

v2:
    v121 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v121);
    }
/* error exit handlers */
v92:
    popv(5);
    return nil;
}



/* Code for !*i2mod */

static Lisp_Object CC_Hi2mod(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *i2mod");
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
    v43 = v0;
/* end of prologue */
    fn = elt(env, 1); /* general!-modular!-number */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v43);
    }
/* error exit handlers */
v5:
    popv(1);
    return nil;
}



/* Code for general!-modular!-times */

static Lisp_Object CC_generalKmodularKtimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v31;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-times");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v18 = v28;
    v31 = v0;
/* end of prologue */
    v31 = times2(v31, v18);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-1];
    v18 = qvalue(elt(env, 1)); /* current!-modulus */
    v18 = Cremainder(v31, v18);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-1];
    stack[0] = v18;
    v31 = stack[0];
    v18 = (Lisp_Object)1; /* 0 */
    v18 = (Lisp_Object)lessp2(v31, v18);
    nil = C_nil;
    if (exception_pending()) goto v61;
    v18 = v18 ? lisp_true : nil;
    env = stack[-1];
    if (v18 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v31 = stack[0];
    v18 = qvalue(elt(env, 1)); /* current!-modulus */
    v18 = plus2(v31, v18);
    nil = C_nil;
    if (exception_pending()) goto v61;
    stack[0] = v18;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v61:
    popv(2);
    return nil;
}



/* Code for getpower */

static Lisp_Object CC_getpower(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v18;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getpower");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v28;
    stack[-1] = v0;
/* end of prologue */
    v19 = stack[-1];
    v18 = qcar(v19);
    v19 = elt(env, 1); /* expt */
    if (!consp(v18)) goto v45;
    v18 = qcar(v18);
    if (!(v18 == v19)) goto v45;
    v18 = stack[0];
    v19 = (Lisp_Object)17; /* 1 */
    v19 = (Lisp_Object)greaterp2(v18, v19);
    nil = C_nil;
    if (exception_pending()) goto v61;
    v19 = v19 ? lisp_true : nil;
    env = stack[-2];
    goto v1;

v1:
    if (v19 == nil) goto v39;
    v19 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 4)) = v19; /* !*sub2 */
    goto v39;

v39:
    v19 = stack[-1];
    v18 = qcar(v19);
    v19 = stack[0];
    popv(3);
    return cons(v18, v19);

v45:
    v19 = qvalue(elt(env, 2)); /* nil */
    goto v1;
/* error exit handlers */
v61:
    popv(3);
    return nil;
}



/* Code for anform */

static Lisp_Object CC_anform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for anform");
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
    v93 = stack[0];
    if (!consp(v93)) goto v13;
    v93 = stack[0];
    {
        popv(2);
        fn = elt(env, 6); /* anform1 */
        return (*qfn1(fn))(qenv(fn), v93);
    }

v13:
    v93 = qvalue(elt(env, 1)); /* !*globals */
    if (v93 == nil) goto v3;
    v93 = stack[0];
    if (v93 == nil) goto v3;
    v94 = stack[0];
    v93 = lisp_true;
    if (v94 == v93) goto v61;
    v93 = stack[0];
    if (symbolp(v93)) goto v50;
    v93 = qvalue(elt(env, 2)); /* nil */
    goto v9;

v9:
    if (v93 == nil) goto v3;
    v94 = stack[0];
    v93 = elt(env, 4); /* glb2rf */
    v93 = Lflagp(nil, v94, v93);
    env = stack[-1];
    if (v93 == nil) goto v62;
    v93 = nil;
    { popv(2); return onevalue(v93); }

v62:
    v93 = stack[0];
    v94 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    v93 = elt(env, 4); /* glb2rf */
    v93 = Lflag(nil, v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    v94 = stack[0];
    v93 = qvalue(elt(env, 5)); /* globs!* */
    v93 = cons(v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    qvalue(elt(env, 5)) = v93; /* globs!* */
    { popv(2); return onevalue(v93); }

v3:
    v93 = nil;
    { popv(2); return onevalue(v93); }

v50:
    v94 = stack[0];
    v93 = qvalue(elt(env, 3)); /* locls!* */
    v93 = Lassoc(nil, v94, v93);
    v93 = (v93 == nil ? lisp_true : nil);
    goto v9;

v61:
    v93 = qvalue(elt(env, 2)); /* nil */
    goto v9;
/* error exit handlers */
v100:
    popv(2);
    return nil;
}



/* Code for reorder */

static Lisp_Object CC_reorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reorder");
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
    stack[-2] = nil;
    goto v5;

v5:
    v52 = stack[-1];
    if (!consp(v52)) goto v35;
    v52 = stack[-1];
    v52 = qcar(v52);
    v52 = (consp(v52) ? nil : lisp_true);
    goto v34;

v34:
    if (v52 == nil) goto v69;
    v52 = stack[-1];
    v64 = v52;
    goto v1;

v1:
    v52 = stack[-2];
    if (v52 == nil) { popv(4); return onevalue(v64); }
    v52 = stack[-2];
    v52 = qcar(v52);
    fn = elt(env, 2); /* raddf */
    v52 = (*qfn2(fn))(qenv(fn), v52, v64);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    v64 = v52;
    v52 = stack[-2];
    v52 = qcdr(v52);
    stack[-2] = v52;
    goto v1;

v69:
    v52 = stack[-1];
    v52 = qcar(v52);
    stack[0] = qcar(v52);
    v52 = stack[-1];
    v52 = qcar(v52);
    v52 = qcdr(v52);
    v52 = CC_reorder(env, v52);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    fn = elt(env, 3); /* rmultpf */
    v64 = (*qfn2(fn))(qenv(fn), stack[0], v52);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    v52 = stack[-2];
    v52 = cons(v64, v52);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    stack[-2] = v52;
    v52 = stack[-1];
    v52 = qcdr(v52);
    stack[-1] = v52;
    goto v5;

v35:
    v52 = qvalue(elt(env, 1)); /* t */
    goto v34;
/* error exit handlers */
v56:
    popv(4);
    return nil;
}



/* Code for ofsf_smwupdknowl */

static Lisp_Object MS_CDECL CC_ofsf_smwupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v28,
                         Lisp_Object v47, Lisp_Object v44, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v19, v18, v31, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smwupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smwupdknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v19 = v44;
    v18 = v47;
    v31 = v28;
    v70 = v0;
/* end of prologue */
    v37 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v37 == nil) goto v46;
    v37 = v70;
    {
        fn = elt(env, 2); /* cl_susiupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v37, v31, v18, v19);
    }

v46:
    v37 = v70;
    {
        fn = elt(env, 3); /* ofsf_smupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v37, v31, v18, v19);
    }
}



/* Code for finde */

static Lisp_Object CC_finde(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v20, v69, v38;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for finde");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v38 = v28;
    v69 = v0;
/* end of prologue */

v43:
    v21 = v69;
    if (v21 == nil) goto v1;
    v20 = v38;
    v21 = v69;
    v21 = qcar(v21);
    v21 = qcdr(v21);
    v21 = Lmemq(nil, v20, v21);
    if (!(v21 == nil)) return onevalue(v69);
    v21 = v69;
    v21 = qcdr(v21);
    v69 = v21;
    goto v43;

v1:
    v21 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v21);
}



/* Code for mchk */

static Lisp_Object CC_mchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v203, v204, v205;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mchk");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v28;
    stack[-4] = v0;
/* end of prologue */

v3:
    v204 = stack[-4];
    v203 = stack[-3];
    if (equal(v204, v203)) goto v1;
    v204 = stack[-4];
    v203 = elt(env, 2); /* !*sq */
    if (!consp(v204)) goto v50;
    v204 = qcar(v204);
    if (!(v204 == v203)) goto v50;
    v203 = stack[-4];
    v203 = qcdr(v203);
    v203 = qcar(v203);
    fn = elt(env, 9); /* prepsqxx */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    stack[-4] = v203;
    goto v3;

v50:
    v204 = stack[-3];
    v203 = elt(env, 2); /* !*sq */
    if (!consp(v204)) goto v12;
    v204 = qcar(v204);
    if (!(v204 == v203)) goto v12;
    v203 = stack[-3];
    v203 = qcdr(v203);
    v203 = qcar(v203);
    fn = elt(env, 9); /* prepsqxx */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    stack[-3] = v203;
    goto v3;

v12:
    v203 = stack[-3];
    if (!consp(v203)) goto v24;
    v203 = stack[-4];
    if (!consp(v203)) goto v88;
    v203 = stack[-3];
    v204 = qcar(v203);
    v203 = elt(env, 6); /* difference */
    if (v204 == v203) goto v112;
    v203 = stack[-4];
    v204 = qcar(v203);
    v203 = elt(env, 8); /* dname */
    v203 = get(v204, v203);
    env = stack[-6];
    if (!(v203 == nil)) goto v105;
    v203 = stack[-3];
    v204 = qcar(v203);
    v203 = elt(env, 8); /* dname */
    v203 = get(v204, v203);
    env = stack[-6];
    if (!(v203 == nil)) goto v105;
    v203 = stack[-4];
    v204 = qcar(v203);
    v203 = stack[-3];
    v203 = qcar(v203);
    if (v204 == v203) goto v207;
    v203 = stack[-3];
    v204 = qcar(v203);
    v203 = qvalue(elt(env, 3)); /* frlis!* */
    v203 = Lmemq(nil, v204, v203);
    if (v203 == nil) goto v208;
    v203 = stack[-4];
    v205 = qcar(v203);
    v203 = stack[-3];
    v204 = qcar(v203);
    v203 = stack[-4];
    v203 = qcdr(v203);
    stack[0] = Lsubst(nil, 3, v205, v204, v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v203 = stack[-4];
    v205 = qcar(v203);
    v203 = stack[-3];
    v204 = qcar(v203);
    v203 = stack[-3];
    v203 = qcdr(v203);
    v204 = Lsubst(nil, 3, v205, v204, v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v203 = stack[-4];
    v203 = qcar(v203);
    fn = elt(env, 10); /* mcharg */
    v203 = (*qfnn(fn))(qenv(fn), 3, stack[0], v204, v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    stack[-5] = v203;
    v203 = stack[-5];
    if (v203 == nil) goto v209;
    v203 = stack[-5];
    v203 = qcar(v203);
    v204 = stack[-3];
    v205 = qcar(v204);
    v204 = stack[-4];
    v204 = qcar(v204);
    v203 = acons(v205, v204, v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v203 = ncons(v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    stack[-1] = v203;
    stack[-2] = v203;
    goto v210;

v210:
    v203 = stack[-5];
    v203 = qcdr(v203);
    stack[-5] = v203;
    v203 = stack[-5];
    if (v203 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v203 = stack[-5];
    v203 = qcar(v203);
    v204 = stack[-3];
    v205 = qcar(v204);
    v204 = stack[-4];
    v204 = qcar(v204);
    v203 = acons(v205, v204, v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v203 = ncons(v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v203 = Lrplacd(nil, stack[0], v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v203 = stack[-1];
    v203 = qcdr(v203);
    stack[-1] = v203;
    goto v210;

v209:
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v203); }

v208:
    v203 = stack[-4];
    v204 = qcar(v203);
    v203 = elt(env, 4); /* minus */
    if (v204 == v203) goto v211;
    v203 = stack[-3];
    v204 = qcar(v203);
    v203 = elt(env, 5); /* optional */
    v203 = get(v204, v203);
    env = stack[-6];
    v204 = v203;
    if (v204 == nil) goto v212;
    v205 = stack[-4];
    v204 = stack[-3];
    {
        popv(7);
        fn = elt(env, 11); /* mchkopt1 */
        return (*qfnn(fn))(qenv(fn), 3, v205, v204, v203);
    }

v212:
    v203 = nil;
    { popv(7); return onevalue(v203); }

v211:
    v203 = stack[-4];
    v203 = qcdr(v203);
    v204 = qcar(v203);
    v203 = stack[-3];
    {
        popv(7);
        fn = elt(env, 12); /* mchkminus */
        return (*qfn2(fn))(qenv(fn), v204, v203);
    }

v207:
    v203 = stack[-4];
    v205 = qcdr(v203);
    v203 = stack[-3];
    v204 = qcdr(v203);
    v203 = stack[-4];
    v203 = qcar(v203);
    {
        popv(7);
        fn = elt(env, 10); /* mcharg */
        return (*qfnn(fn))(qenv(fn), 3, v205, v204, v203);
    }

v105:
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v203); }

v112:
    stack[-1] = elt(env, 7); /* plus */
    v203 = stack[-3];
    v203 = qcdr(v203);
    stack[0] = qcar(v203);
    v204 = elt(env, 4); /* minus */
    v203 = stack[-3];
    v203 = qcdr(v203);
    v203 = qcdr(v203);
    v203 = qcar(v203);
    v203 = list2(v204, v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v203 = list3(stack[-1], stack[0], v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    stack[-3] = v203;
    goto v3;

v88:
    v203 = stack[-4];
    if (!(is_number(v203))) goto v119;
    v204 = stack[-4];
    v203 = (Lisp_Object)1; /* 0 */
    v203 = (Lisp_Object)lessp2(v204, v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    v203 = v203 ? lisp_true : nil;
    env = stack[-6];
    if (v203 == nil) goto v119;
    v204 = stack[-3];
    v203 = elt(env, 4); /* minus */
    if (!consp(v204)) goto v119;
    v204 = qcar(v204);
    if (!(v204 == v203)) goto v119;
    stack[0] = elt(env, 4); /* minus */
    v203 = stack[-4];
    v203 = negate(v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v203 = list2(stack[0], v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    stack[-4] = v203;
    goto v3;

v119:
    v203 = stack[-3];
    v204 = qcar(v203);
    v203 = elt(env, 5); /* optional */
    v203 = get(v204, v203);
    env = stack[-6];
    v204 = v203;
    if (v204 == nil) goto v213;
    v205 = stack[-4];
    v204 = stack[-3];
    {
        popv(7);
        fn = elt(env, 11); /* mchkopt1 */
        return (*qfnn(fn))(qenv(fn), 3, v205, v204, v203);
    }

v213:
    v203 = nil;
    { popv(7); return onevalue(v203); }

v24:
    v204 = stack[-3];
    v203 = qvalue(elt(env, 3)); /* frlis!* */
    v203 = Lmemq(nil, v204, v203);
    if (v203 == nil) goto v57;
    v204 = stack[-3];
    v203 = stack[-4];
    v203 = cons(v204, v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-6];
    v203 = ncons(v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    popv(7);
    return ncons(v203);

v57:
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v203); }

v1:
    v203 = qvalue(elt(env, 1)); /* nil */
    popv(7);
    return ncons(v203);
/* error exit handlers */
v206:
    popv(7);
    return nil;
}



/* Code for multsq */

static Lisp_Object CC_multsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v28)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v220, v221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multsq");
#endif
    if (stack >= stacklimit)
    {
        push2(v28,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v28;
    stack[-3] = v0;
/* end of prologue */
    v220 = stack[-3];
    v220 = qcar(v220);
    if (v220 == nil) goto v2;
    v220 = stack[-2];
    v220 = qcar(v220);
    v220 = (v220 == nil ? lisp_true : nil);
    goto v1;

v1:
    if (v220 == nil) goto v39;
    v221 = qvalue(elt(env, 2)); /* nil */
    v220 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v221, v220);

v39:
    v220 = stack[-3];
    v221 = qcdr(v220);
    v220 = (Lisp_Object)17; /* 1 */
    if (v221 == v220) goto v19;
    v220 = qvalue(elt(env, 2)); /* nil */
    goto v20;

v20:
    if (v220 == nil) goto v79;
    v220 = stack[-3];
    v221 = qcar(v220);
    v220 = stack[-2];
    v220 = qcar(v220);
    fn = elt(env, 3); /* multf */
    v221 = (*qfn2(fn))(qenv(fn), v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v196;
    v220 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v221, v220);

v79:
    v220 = stack[-3];
    v221 = qcar(v220);
    v220 = stack[-2];
    v220 = qcdr(v220);
    fn = elt(env, 4); /* gcdf */
    v220 = (*qfn2(fn))(qenv(fn), v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-5];
    stack[-4] = v220;
    v220 = stack[-2];
    v221 = qcar(v220);
    v220 = stack[-3];
    v220 = qcdr(v220);
    fn = elt(env, 4); /* gcdf */
    v220 = (*qfn2(fn))(qenv(fn), v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-5];
    stack[-1] = v220;
    v220 = stack[-3];
    v221 = qcar(v220);
    v220 = stack[-4];
    fn = elt(env, 5); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-5];
    v220 = stack[-2];
    v221 = qcar(v220);
    v220 = stack[-1];
    fn = elt(env, 5); /* quotf */
    v220 = (*qfn2(fn))(qenv(fn), v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-5];
    fn = elt(env, 3); /* multf */
    v220 = (*qfn2(fn))(qenv(fn), stack[0], v220);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-5];
    stack[0] = v220;
    v220 = stack[-3];
    v221 = qcdr(v220);
    v220 = stack[-1];
    fn = elt(env, 5); /* quotf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-5];
    v220 = stack[-2];
    v221 = qcdr(v220);
    v220 = stack[-4];
    fn = elt(env, 5); /* quotf */
    v220 = (*qfn2(fn))(qenv(fn), v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-5];
    fn = elt(env, 3); /* multf */
    v220 = (*qfn2(fn))(qenv(fn), stack[-1], v220);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-5];
    stack[-4] = v220;
    v221 = stack[0];
    v220 = stack[-4];
    v220 = cons(v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 6); /* canonsq */
        return (*qfn1(fn))(qenv(fn), v220);
    }

v19:
    v220 = stack[-2];
    v221 = qcdr(v220);
    v220 = (Lisp_Object)17; /* 1 */
    v220 = (v221 == v220 ? lisp_true : nil);
    goto v20;

v2:
    v220 = qvalue(elt(env, 1)); /* t */
    goto v1;
/* error exit handlers */
v196:
    popv(6);
    return nil;
}



/* Code for kernlp */

static Lisp_Object CC_kernlp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v38;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernlp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v69 = v0;
/* end of prologue */

v13:
    v38 = v69;
    if (!consp(v38)) goto v4;
    v38 = v69;
    v38 = qcar(v38);
    v38 = (consp(v38) ? nil : lisp_true);
    goto v3;

v3:
    if (!(v38 == nil)) return onevalue(v69);
    v38 = v69;
    v38 = qcdr(v38);
    if (v38 == nil) goto v15;
    v69 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v69);

v15:
    v69 = qcar(v69);
    v69 = qcdr(v69);
    goto v13;

v4:
    v38 = qvalue(elt(env, 1)); /* t */
    goto v3;
}



/* Code for qqe_rbopp */

static Lisp_Object CC_qqe_rbopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_rbopp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v3 = v0;
/* end of prologue */
    v4 = elt(env, 1); /* (equal neq lessp leq geq greaterp) */
    v3 = Lmemq(nil, v3, v4);
    return onevalue(v3);
}



setup_type const u01_setup[] =
{
    {"reval",                   CC_reval,       too_many_1,    wrong_no_1},
    {"num-exponents",           CC_numKexponents,too_many_1,   wrong_no_1},
    {"arraychk",                CC_arraychk,    too_many_1,    wrong_no_1},
    {"getrtypeor",              CC_getrtypeor,  too_many_1,    wrong_no_1},
    {"*d2q",                    CC_Hd2q,        too_many_1,    wrong_no_1},
    {"readch1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_readch1},
    {"quotf",                   too_few_2,      CC_quotf,      wrong_no_2},
    {"monomcompare",            too_few_2,      CC_monomcompare,wrong_no_2},
    {"smember",                 too_few_2,      CC_smember,    wrong_no_2},
    {"quotelist",               CC_quotelist,   too_many_1,    wrong_no_1},
    {"wuconstantp",             CC_wuconstantp, too_many_1,    wrong_no_1},
    {"mkcopy",                  CC_mkcopy,      too_many_1,    wrong_no_1},
    {"remove-free-vars-l",      CC_removeKfreeKvarsKl,too_many_1,wrong_no_1},
    {"mchk*",                   too_few_2,      CC_mchkH,      wrong_no_2},
    {"prepf",                   CC_prepf,       too_many_1,    wrong_no_1},
    {"get+mat+entry",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_getLmatLentry},
    {"minusf",                  CC_minusf,      too_many_1,    wrong_no_1},
    {"qqe_rqopp",               CC_qqe_rqopp,   too_many_1,    wrong_no_1},
    {"kernels1",                too_few_2,      CC_kernels1,   wrong_no_2},
    {"ibalp_clmember",          too_few_2,      CC_ibalp_clmember,wrong_no_2},
    {"adjoin-term",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_adjoinKterm},
    {"delall",                  too_few_2,      CC_delall,     wrong_no_2},
    {"noncomfp1",               CC_noncomfp1,   too_many_1,    wrong_no_1},
    {"ordop",                   too_few_2,      CC_ordop,      wrong_no_2},
    {"ps:getv",                 too_few_2,      CC_psTgetv,    wrong_no_2},
    {"ldepends",                too_few_2,      CC_ldepends,   wrong_no_2},
    {"c:ordxp",                 too_few_2,      CC_cTordxp,    wrong_no_2},
    {"zero2nil",                CC_zero2nil,    too_many_1,    wrong_no_1},
    {"binding",                 CC_binding,     too_many_1,    wrong_no_1},
    {"evcomp",                  too_few_2,      CC_evcomp,     wrong_no_2},
    {"pnth",                    too_few_2,      CC_pnth,       wrong_no_2},
    {"evmatrixcomp2",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_evmatrixcomp2},
    {"xval",                    CC_xval,        too_many_1,    wrong_no_1},
    {"add_prin_char",           too_few_2,      CC_add_prin_char,wrong_no_2},
    {"int-equiv-chk",           CC_intKequivKchk,too_many_1,   wrong_no_1},
    {"physopp",                 CC_physopp,     too_many_1,    wrong_no_1},
    {"memq_edgelist",           too_few_2,      CC_memq_edgelist,wrong_no_2},
    {"termsf",                  CC_termsf,      too_many_1,    wrong_no_1},
    {"mkspm",                   too_few_2,      CC_mkspm,      wrong_no_2},
    {"mo_comp",                 CC_mo_comp,     too_many_1,    wrong_no_1},
    {"c_zero",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_c_zero},
    {"sieve_pv0",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_sieve_pv0},
    {"listp",                   CC_listp,       too_many_1,    wrong_no_1},
    {"modzerop:",               CC_modzeropT,   too_many_1,    wrong_no_1},
    {"xcomment",                too_few_2,      CC_xcomment,   wrong_no_2},
    {"monomgetvariabledegree",  too_few_2,      CC_monomgetvariabledegree,wrong_no_2},
    {"aeval",                   CC_aeval,       too_many_1,    wrong_no_1},
    {"rl_smupdknowl",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_smupdknowl},
    {"degr",                    too_few_2,      CC_degr,       wrong_no_2},
    {"prepf1a",                 too_few_2,      CC_prepf1a,    wrong_no_2},
    {"setkorder",               CC_setkorder,   too_many_1,    wrong_no_1},
    {"ibalp_emptyclausep",      CC_ibalp_emptyclausep,too_many_1,wrong_no_1},
    {"multiply-by-constant-mod-p",too_few_2,    CC_multiplyKbyKconstantKmodKp,wrong_no_2},
    {"find2",                   too_few_2,      CC_find2,      wrong_no_2},
    {"butes",                   CC_butes,       too_many_1,    wrong_no_1},
    {"mtp",                     CC_mtp,         too_many_1,    wrong_no_1},
    {"nil2zero",                CC_nil2zero,    too_many_1,    wrong_no_1},
    {"pm:free",                 CC_pmTfree,     too_many_1,    wrong_no_1},
    {"vbcsize",                 too_few_2,      CC_vbcsize,    wrong_no_2},
    {"wedgefax",                CC_wedgefax,    too_many_1,    wrong_no_1},
    {"csl_normbf",              CC_csl_normbf,  too_many_1,    wrong_no_1},
    {"*physopp",                CC_Hphysopp,    too_many_1,    wrong_no_1},
    {"union_edge",              too_few_2,      CC_union_edge, wrong_no_2},
    {"addf",                    too_few_2,      CC_addf,       wrong_no_2},
    {"expdrmacro",              CC_expdrmacro,  too_many_1,    wrong_no_1},
    {"getrtypecar",             CC_getrtypecar, too_many_1,    wrong_no_1},
    {"addd",                    too_few_2,      CC_addd,       wrong_no_2},
    {"sub2chk",                 CC_sub2chk,     too_many_1,    wrong_no_1},
    {"mo_divides?",             too_few_2,      CC_mo_dividesW,wrong_no_2},
    {"multdm",                  too_few_2,      CC_multdm,     wrong_no_2},
    {"dssoc",                   too_few_2,      CC_dssoc,      wrong_no_2},
    {"noncomlistp",             CC_noncomlistp, too_many_1,    wrong_no_1},
    {"rnzerop:",                CC_rnzeropT,    too_many_1,    wrong_no_1},
    {"modonep:",                CC_modonepT,    too_many_1,    wrong_no_1},
    {"eolcheck",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_eolcheck},
    {"mtchp1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mtchp1},
    {"mri_floorkernelp",        CC_mri_floorkernelp,too_many_1,wrong_no_1},
    {"qqe_qoptailp",            CC_qqe_qoptailp,too_many_1,    wrong_no_1},
    {"lto_setequalq",           too_few_2,      CC_lto_setequalq,wrong_no_2},
    {"numlis",                  CC_numlis,      too_many_1,    wrong_no_1},
    {"constp",                  CC_constp,      too_many_1,    wrong_no_1},
    {"replus1",                 CC_replus1,     too_many_1,    wrong_no_1},
    {"buchvevdivides?",         too_few_2,      CC_buchvevdividesW,wrong_no_2},
    {"sublistp",                too_few_2,      CC_sublistp,   wrong_no_2},
    {":times",                  too_few_2,      CC_Ttimes,     wrong_no_2},
    {"pprin2",                  CC_pprin2,      too_many_1,    wrong_no_1},
    {"isanindex",               CC_isanindex,   too_many_1,    wrong_no_1},
    {"formlis",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_formlis},
    {"aeval*",                  CC_aevalH,      too_many_1,    wrong_no_1},
    {"bc_prod",                 too_few_2,      CC_bc_prod,    wrong_no_2},
    {"dlesslex",                too_few_2,      CC_dlesslex,   wrong_no_2},
    {"reduce_pv0",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_reduce_pv0},
    {"upbve",                   CC_upbve,       too_many_1,    wrong_no_1},
    {"rnequiv",                 CC_rnequiv,     too_many_1,    wrong_no_1},
    {"multd",                   too_few_2,      CC_multd,      wrong_no_2},
    {"*i2mod",                  CC_Hi2mod,      too_many_1,    wrong_no_1},
    {"general-modular-times",   too_few_2,      CC_generalKmodularKtimes,wrong_no_2},
    {"getpower",                too_few_2,      CC_getpower,   wrong_no_2},
    {"anform",                  CC_anform,      too_many_1,    wrong_no_1},
    {"reorder",                 CC_reorder,     too_many_1,    wrong_no_1},
    {"ofsf_smwupdknowl",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smwupdknowl},
    {"finde",                   too_few_2,      CC_finde,      wrong_no_2},
    {"mchk",                    too_few_2,      CC_mchk,       wrong_no_2},
    {"multsq",                  too_few_2,      CC_multsq,     wrong_no_2},
    {"kernlp",                  CC_kernlp,      too_many_1,    wrong_no_1},
    {"qqe_rbopp",               CC_qqe_rbopp,   too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u01", (two_args *)"19095 7754670 5407145", 0}
};

/* end of generated code */
