
/* $destdir\u02.c        Machine generated C code */

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


/* Code for rank */

static Lisp_Object CC_rank(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0017;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rank");
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
    v0016 = qvalue(elt(env, 1)); /* !*mcd */
    if (v0016 == nil) goto v0018;
    v0016 = stack[-2];
    v0016 = qcar(v0016);
    v0016 = qcar(v0016);
    v0016 = qcdr(v0016);
    { popv(5); return onevalue(v0016); }

v0018:
    v0016 = stack[-2];
    v0016 = qcar(v0016);
    v0016 = qcar(v0016);
    v0016 = qcdr(v0016);
    stack[-1] = v0016;
    v0016 = stack[-2];
    v0016 = qcar(v0016);
    v0016 = qcar(v0016);
    v0016 = qcar(v0016);
    stack[0] = v0016;
    goto v0019;

v0019:
    v0016 = stack[-2];
    v0016 = qcar(v0016);
    v0016 = qcar(v0016);
    v0016 = qcdr(v0016);
    stack[-3] = v0016;
    v0016 = stack[-2];
    v0016 = qcdr(v0016);
    if (v0016 == nil) goto v0020;
    v0016 = stack[-2];
    v0016 = qcdr(v0016);
    stack[-2] = v0016;
    v0017 = stack[-2];
    v0016 = stack[0];
    fn = elt(env, 2); /* degr */
    v0017 = (*qfn2(fn))(qenv(fn), v0017, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-4];
    v0016 = (Lisp_Object)1; /* 0 */
    if (!(v0017 == v0016)) goto v0019;
    v0017 = stack[-3];
    v0016 = (Lisp_Object)1; /* 0 */
    v0016 = (Lisp_Object)lessp2(v0017, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    v0016 = v0016 ? lisp_true : nil;
    env = stack[-4];
    if (v0016 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0017 = stack[-1];
    v0016 = (Lisp_Object)1; /* 0 */
    v0016 = (Lisp_Object)lessp2(v0017, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    v0016 = v0016 ? lisp_true : nil;
    if (v0016 == nil) goto v0022;
    v0016 = stack[-3];
    popv(5);
    return negate(v0016);

v0022:
    v0017 = stack[-1];
    v0016 = stack[-3];
    popv(5);
    return difference2(v0017, v0016);

v0020:
    v0017 = stack[-1];
    v0016 = stack[-3];
    popv(5);
    return difference2(v0017, v0016);
/* error exit handlers */
v0021:
    popv(5);
    return nil;
}



/* Code for fctargs */

static Lisp_Object CC_fctargs(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0025;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fctargs");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0024 = v0000;
/* end of prologue */
    v0025 = qvalue(elt(env, 1)); /* depl!* */
    v0025 = Lassoc(nil, v0024, v0025);
    v0024 = v0025;
    if (v0025 == nil) goto v0026;
    v0024 = qcdr(v0024);
    return onevalue(v0024);

v0026:
    v0024 = nil;
    return onevalue(v0024);
}



/* Code for mchk */

static Lisp_Object CC_mchk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084, v0085, v0086;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0027;
    stack[-4] = v0000;
/* end of prologue */

v0087:
    v0085 = stack[-4];
    v0084 = stack[-3];
    if (equal(v0085, v0084)) goto v0088;
    v0085 = stack[-4];
    v0084 = elt(env, 2); /* !*sq */
    if (!consp(v0085)) goto v0089;
    v0085 = qcar(v0085);
    if (!(v0085 == v0084)) goto v0089;
    v0084 = stack[-4];
    v0084 = qcdr(v0084);
    v0084 = qcar(v0084);
    fn = elt(env, 7); /* prepsqxx */
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-6];
    stack[-4] = v0084;
    goto v0087;

v0089:
    v0085 = stack[-3];
    v0084 = elt(env, 2); /* !*sq */
    if (!consp(v0085)) goto v0091;
    v0085 = qcar(v0085);
    if (!(v0085 == v0084)) goto v0091;
    v0084 = stack[-3];
    v0084 = qcdr(v0084);
    v0084 = qcar(v0084);
    fn = elt(env, 7); /* prepsqxx */
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-6];
    stack[-3] = v0084;
    goto v0087;

v0091:
    v0084 = stack[-3];
    if (!consp(v0084)) goto v0092;
    v0084 = stack[-4];
    if (!consp(v0084)) goto v0093;
    v0084 = stack[-3];
    v0085 = qcar(v0084);
    v0084 = elt(env, 5); /* difference */
    if (v0085 == v0084) goto v0094;
    v0084 = stack[-4];
    v0084 = qcar(v0084);
    if (!symbolp(v0084)) v0084 = nil;
    else { v0084 = qfastgets(v0084);
           if (v0084 != nil) { v0084 = elt(v0084, 8); /* dname */
#ifdef RECORD_GET
             if (v0084 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0084 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0084 == SPID_NOPROP) v0084 = nil; }}
#endif
    if (!(v0084 == nil)) goto v0095;
    v0084 = stack[-3];
    v0084 = qcar(v0084);
    if (!symbolp(v0084)) v0084 = nil;
    else { v0084 = qfastgets(v0084);
           if (v0084 != nil) { v0084 = elt(v0084, 8); /* dname */
#ifdef RECORD_GET
             if (v0084 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0084 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0084 == SPID_NOPROP) v0084 = nil; }}
#endif
    if (!(v0084 == nil)) goto v0095;
    v0084 = stack[-4];
    v0085 = qcar(v0084);
    v0084 = stack[-3];
    v0084 = qcar(v0084);
    if (v0085 == v0084) goto v0096;
    v0084 = stack[-3];
    v0085 = qcar(v0084);
    v0084 = qvalue(elt(env, 3)); /* frlis!* */
    v0084 = Lmemq(nil, v0085, v0084);
    if (v0084 == nil) goto v0097;
    v0084 = stack[-4];
    v0086 = qcar(v0084);
    v0084 = stack[-3];
    v0085 = qcar(v0084);
    v0084 = stack[-4];
    v0084 = qcdr(v0084);
    stack[0] = Lsubst(nil, 3, v0086, v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-6];
    v0084 = stack[-4];
    v0086 = qcar(v0084);
    v0084 = stack[-3];
    v0085 = qcar(v0084);
    v0084 = stack[-3];
    v0084 = qcdr(v0084);
    v0085 = Lsubst(nil, 3, v0086, v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-6];
    v0084 = stack[-4];
    v0084 = qcar(v0084);
    fn = elt(env, 8); /* mcharg */
    v0084 = (*qfnn(fn))(qenv(fn), 3, stack[0], v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-6];
    stack[-5] = v0084;
    v0084 = stack[-5];
    if (v0084 == nil) goto v0098;
    v0084 = stack[-5];
    v0084 = qcar(v0084);
    v0085 = stack[-3];
    v0086 = qcar(v0085);
    v0085 = stack[-4];
    v0085 = qcar(v0085);
    v0084 = acons(v0086, v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-6];
    v0084 = ncons(v0084);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-6];
    stack[-1] = v0084;
    stack[-2] = v0084;
    goto v0099;

v0099:
    v0084 = stack[-5];
    v0084 = qcdr(v0084);
    stack[-5] = v0084;
    v0084 = stack[-5];
    if (v0084 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v0084 = stack[-5];
    v0084 = qcar(v0084);
    v0085 = stack[-3];
    v0086 = qcar(v0085);
    v0085 = stack[-4];
    v0085 = qcar(v0085);
    v0084 = acons(v0086, v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-6];
    v0084 = ncons(v0084);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-6];
    v0084 = Lrplacd(nil, stack[0], v0084);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-6];
    v0084 = stack[-1];
    v0084 = qcdr(v0084);
    stack[-1] = v0084;
    goto v0099;

v0098:
    v0084 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0084); }

v0097:
    v0084 = stack[-4];
    v0085 = qcar(v0084);
    v0084 = elt(env, 4); /* minus */
    if (v0085 == v0084) goto v0100;
    v0085 = stack[-4];
    v0084 = stack[-3];
    {
        popv(7);
        fn = elt(env, 9); /* mchkopt */
        return (*qfn2(fn))(qenv(fn), v0085, v0084);
    }

v0100:
    v0084 = stack[-4];
    v0084 = qcdr(v0084);
    v0085 = qcar(v0084);
    v0084 = stack[-3];
    {
        popv(7);
        fn = elt(env, 10); /* mchkminus */
        return (*qfn2(fn))(qenv(fn), v0085, v0084);
    }

v0096:
    v0084 = stack[-4];
    v0086 = qcdr(v0084);
    v0084 = stack[-3];
    v0085 = qcdr(v0084);
    v0084 = stack[-4];
    v0084 = qcar(v0084);
    {
        popv(7);
        fn = elt(env, 8); /* mcharg */
        return (*qfnn(fn))(qenv(fn), 3, v0086, v0085, v0084);
    }

v0095:
    v0084 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0084); }

v0094:
    stack[-1] = elt(env, 6); /* plus */
    v0084 = stack[-3];
    v0084 = qcdr(v0084);
    stack[0] = qcar(v0084);
    v0085 = elt(env, 4); /* minus */
    v0084 = stack[-3];
    v0084 = qcdr(v0084);
    v0084 = qcdr(v0084);
    v0084 = qcar(v0084);
    v0084 = list2(v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-6];
    v0084 = list3(stack[-1], stack[0], v0084);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-6];
    stack[-3] = v0084;
    goto v0087;

v0093:
    v0084 = stack[-4];
    if (!(is_number(v0084))) goto v0101;
    v0085 = stack[-4];
    v0084 = (Lisp_Object)1; /* 0 */
    v0084 = (Lisp_Object)lessp2(v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    v0084 = v0084 ? lisp_true : nil;
    env = stack[-6];
    if (v0084 == nil) goto v0101;
    v0085 = stack[-3];
    v0084 = elt(env, 4); /* minus */
    if (!consp(v0085)) goto v0101;
    v0085 = qcar(v0085);
    if (!(v0085 == v0084)) goto v0101;
    stack[0] = elt(env, 4); /* minus */
    v0084 = stack[-4];
    v0084 = negate(v0084);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-6];
    v0084 = list2(stack[0], v0084);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-6];
    stack[-4] = v0084;
    goto v0087;

v0101:
    v0085 = stack[-4];
    v0084 = stack[-3];
    {
        popv(7);
        fn = elt(env, 9); /* mchkopt */
        return (*qfn2(fn))(qenv(fn), v0085, v0084);
    }

v0092:
    v0085 = stack[-3];
    v0084 = qvalue(elt(env, 3)); /* frlis!* */
    v0084 = Lmemq(nil, v0085, v0084);
    if (v0084 == nil) goto v0102;
    v0085 = stack[-3];
    v0084 = stack[-4];
    v0084 = cons(v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-6];
    v0084 = ncons(v0084);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    popv(7);
    return ncons(v0084);

v0102:
    v0084 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0084); }

v0088:
    v0084 = qvalue(elt(env, 1)); /* nil */
    popv(7);
    return ncons(v0084);
/* error exit handlers */
v0090:
    popv(7);
    return nil;
}



/* Code for exptchksq */

static Lisp_Object CC_exptchksq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exptchksq");
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
    v0104 = qvalue(elt(env, 1)); /* !*combineexpt */
    if (v0104 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0104 = stack[0];
    v0104 = qcar(v0104);
    fn = elt(env, 2); /* exptchk */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-2];
    v0104 = stack[0];
    v0104 = qcdr(v0104);
    fn = elt(env, 2); /* exptchk */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-2];
    fn = elt(env, 3); /* invsq */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-2];
    {
        Lisp_Object v0083 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0083, v0104);
    }
/* error exit handlers */
v0105:
    popv(3);
    return nil;
}



/* Code for multd */

static Lisp_Object CC_multd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0117, v0118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0027;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0119;

v0119:
    v0117 = stack[-1];
    if (v0117 == nil) goto v0120;
    v0118 = stack[-1];
    v0117 = (Lisp_Object)17; /* 1 */
    if (v0118 == v0117) goto v0121;
    v0117 = stack[-1];
    if (!consp(v0117)) goto v0122;
    v0117 = stack[-1];
    v0117 = qcar(v0117);
    v0117 = (consp(v0117) ? nil : lisp_true);
    goto v0091;

v0091:
    if (v0117 == nil) goto v0123;
    stack[0] = stack[-3];
    v0118 = stack[-2];
    v0117 = stack[-1];
    fn = elt(env, 2); /* multdm */
    v0117 = (*qfn2(fn))(qenv(fn), v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    {
        Lisp_Object v0074 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0074, v0117);
    }

v0123:
    v0117 = stack[-1];
    v0117 = qcar(v0117);
    stack[0] = qcar(v0117);
    v0118 = stack[-2];
    v0117 = stack[-1];
    v0117 = qcar(v0117);
    v0117 = qcdr(v0117);
    v0118 = CC_multd(env, v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    v0117 = stack[-3];
    v0117 = acons(stack[0], v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-4];
    stack[-3] = v0117;
    v0117 = stack[-1];
    v0117 = qcdr(v0117);
    stack[-1] = v0117;
    goto v0119;

v0122:
    v0117 = qvalue(elt(env, 1)); /* t */
    goto v0091;

v0121:
    v0118 = stack[-3];
    v0117 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0118, v0117);
    }

v0120:
    v0117 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0117);
    }
/* error exit handlers */
v0124:
    popv(5);
    return nil;
}



/* Code for qqe_qopaddp */

static Lisp_Object CC_qqe_qopaddp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0024;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_qopaddp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0013 = v0000;
/* end of prologue */
    v0024 = v0013;
    v0013 = elt(env, 1); /* (ladd radd) */
    v0013 = Lmemq(nil, v0024, v0013);
    if (v0013 == nil) goto v0026;
    v0013 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0013);

v0026:
    v0013 = nil;
    return onevalue(v0013);
}



/* Code for reorder */

static Lisp_Object CC_reorder(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011, v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reorder");
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
    stack[-2] = nil;
    goto v0119;

v0119:
    v0011 = stack[-1];
    if (!consp(v0011)) goto v0013;
    v0011 = stack[-1];
    v0011 = qcar(v0011);
    v0011 = (consp(v0011) ? nil : lisp_true);
    goto v0004;

v0004:
    if (v0011 == nil) goto v0130;
    v0011 = stack[-1];
    v0012 = v0011;
    goto v0088;

v0088:
    v0011 = stack[-2];
    if (v0011 == nil) { popv(4); return onevalue(v0012); }
    v0011 = stack[-2];
    v0011 = qcar(v0011);
    fn = elt(env, 2); /* raddf */
    v0011 = (*qfn2(fn))(qenv(fn), v0011, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-3];
    v0012 = v0011;
    v0011 = stack[-2];
    v0011 = qcdr(v0011);
    stack[-2] = v0011;
    goto v0088;

v0130:
    v0011 = stack[-1];
    v0011 = qcar(v0011);
    stack[0] = qcar(v0011);
    v0011 = stack[-1];
    v0011 = qcar(v0011);
    v0011 = qcdr(v0011);
    v0011 = CC_reorder(env, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-3];
    fn = elt(env, 3); /* rmultpf */
    v0012 = (*qfn2(fn))(qenv(fn), stack[0], v0011);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-3];
    v0011 = stack[-2];
    v0011 = cons(v0012, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-3];
    stack[-2] = v0011;
    v0011 = stack[-1];
    v0011 = qcdr(v0011);
    stack[-1] = v0011;
    goto v0119;

v0013:
    v0011 = qvalue(elt(env, 1)); /* t */
    goto v0004;
/* error exit handlers */
v0131:
    popv(4);
    return nil;
}



/* Code for ibalp_cequal */

static Lisp_Object CC_ibalp_cequal(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_cequal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0027;
    stack[-5] = v0000;
/* end of prologue */
    v0041 = stack[-5];
    v0041 = qcar(v0041);
    stack[-3] = v0041;
    v0041 = stack[-3];
    if (v0041 == nil) goto v0103;
    v0041 = stack[-3];
    v0041 = qcar(v0041);
    v0041 = qcar(v0041);
    v0041 = ncons(v0041);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-7];
    stack[-1] = v0041;
    stack[-2] = v0041;
    goto v0004;

v0004:
    v0041 = stack[-3];
    v0041 = qcdr(v0041);
    stack[-3] = v0041;
    v0041 = stack[-3];
    if (v0041 == nil) goto v0112;
    stack[0] = stack[-1];
    v0041 = stack[-3];
    v0041 = qcar(v0041);
    v0041 = qcar(v0041);
    v0041 = ncons(v0041);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-7];
    v0041 = Lrplacd(nil, stack[0], v0041);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-7];
    v0041 = stack[-1];
    v0041 = qcdr(v0041);
    stack[-1] = v0041;
    goto v0004;

v0112:
    v0041 = stack[-2];
    goto v0003;

v0003:
    stack[-6] = v0041;
    v0041 = stack[-4];
    v0041 = qcar(v0041);
    stack[-3] = v0041;
    v0041 = stack[-3];
    if (v0041 == nil) goto v0123;
    v0041 = stack[-3];
    v0041 = qcar(v0041);
    v0041 = qcar(v0041);
    v0041 = ncons(v0041);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-7];
    stack[-1] = v0041;
    stack[-2] = v0041;
    goto v0111;

v0111:
    v0041 = stack[-3];
    v0041 = qcdr(v0041);
    stack[-3] = v0041;
    v0041 = stack[-3];
    if (v0041 == nil) goto v0146;
    stack[0] = stack[-1];
    v0041 = stack[-3];
    v0041 = qcar(v0041);
    v0041 = qcar(v0041);
    v0041 = ncons(v0041);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-7];
    v0041 = Lrplacd(nil, stack[0], v0041);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-7];
    v0041 = stack[-1];
    v0041 = qcdr(v0041);
    stack[-1] = v0041;
    goto v0111;

v0146:
    v0041 = stack[-2];
    goto v0147;

v0147:
    v0144 = stack[-6];
    fn = elt(env, 2); /* lto_setequalq */
    v0041 = (*qfn2(fn))(qenv(fn), v0144, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-7];
    if (v0041 == nil) goto v0148;
    v0041 = stack[-5];
    v0041 = qcdr(v0041);
    v0041 = qcar(v0041);
    stack[-3] = v0041;
    v0041 = stack[-3];
    if (v0041 == nil) goto v0149;
    v0041 = stack[-3];
    v0041 = qcar(v0041);
    v0041 = qcar(v0041);
    v0041 = ncons(v0041);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-7];
    stack[-1] = v0041;
    stack[-2] = v0041;
    goto v0150;

v0150:
    v0041 = stack[-3];
    v0041 = qcdr(v0041);
    stack[-3] = v0041;
    v0041 = stack[-3];
    if (v0041 == nil) goto v0094;
    stack[0] = stack[-1];
    v0041 = stack[-3];
    v0041 = qcar(v0041);
    v0041 = qcar(v0041);
    v0041 = ncons(v0041);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-7];
    v0041 = Lrplacd(nil, stack[0], v0041);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-7];
    v0041 = stack[-1];
    v0041 = qcdr(v0041);
    stack[-1] = v0041;
    goto v0150;

v0094:
    v0041 = stack[-2];
    goto v0021;

v0021:
    stack[-3] = v0041;
    v0041 = stack[-4];
    v0041 = qcdr(v0041);
    v0041 = qcar(v0041);
    stack[-4] = v0041;
    v0041 = stack[-4];
    if (v0041 == nil) goto v0151;
    v0041 = stack[-4];
    v0041 = qcar(v0041);
    v0041 = qcar(v0041);
    v0041 = ncons(v0041);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-7];
    stack[-1] = v0041;
    stack[-2] = v0041;
    goto v0152;

v0152:
    v0041 = stack[-4];
    v0041 = qcdr(v0041);
    stack[-4] = v0041;
    v0041 = stack[-4];
    if (v0041 == nil) goto v0153;
    stack[0] = stack[-1];
    v0041 = stack[-4];
    v0041 = qcar(v0041);
    v0041 = qcar(v0041);
    v0041 = ncons(v0041);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-7];
    v0041 = Lrplacd(nil, stack[0], v0041);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-7];
    v0041 = stack[-1];
    v0041 = qcdr(v0041);
    stack[-1] = v0041;
    goto v0152;

v0153:
    v0041 = stack[-2];
    goto v0154;

v0154:
    v0144 = stack[-3];
    {
        popv(8);
        fn = elt(env, 2); /* lto_setequalq */
        return (*qfn2(fn))(qenv(fn), v0144, v0041);
    }

v0151:
    v0041 = qvalue(elt(env, 1)); /* nil */
    goto v0154;

v0149:
    v0041 = qvalue(elt(env, 1)); /* nil */
    goto v0021;

v0148:
    v0041 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v0041); }

v0123:
    v0041 = qvalue(elt(env, 1)); /* nil */
    goto v0147;

v0103:
    v0041 = qvalue(elt(env, 1)); /* nil */
    goto v0003;
/* error exit handlers */
v0145:
    popv(8);
    return nil;
}



/* Code for compress!* */

static Lisp_Object CC_compressH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0072, v0073, v0136, v0021;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for compress*");
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
    v0072 = v0000;
/* end of prologue */
    v0021 = nil;
    v0073 = v0072;
    v0073 = qcar(v0073);
    v0073 = Ldigitp(nil, v0073);
    env = stack[-1];
    if (v0073 == nil) goto v0119;
        popv(2);
        return Lcompress(nil, v0072);

v0119:
    stack[0] = v0072;
    goto v0025;

v0025:
    v0072 = stack[0];
    if (v0072 == nil) goto v0024;
    v0072 = stack[0];
    v0072 = qcar(v0072);
    v0136 = v0072;
    v0073 = v0136;
    v0072 = elt(env, 2); /* !/ */
    if (v0073 == v0072) goto v0091;
    v0073 = v0136;
    v0072 = elt(env, 4); /* !- */
    if (v0073 == v0072) goto v0159;
    v0073 = v0136;
    v0072 = elt(env, 5); /* !; */
    if (v0073 == v0072) goto v0123;
    v0073 = v0136;
    v0072 = elt(env, 6); /* !. */
    v0072 = (v0073 == v0072 ? lisp_true : nil);
    goto v0112;

v0112:
    if (v0072 == nil) goto v0022;
    v0073 = v0136;
    v0072 = elt(env, 7); /* !! */
    v0136 = v0021;
    v0072 = list2star(v0073, v0072, v0136);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-1];
    v0021 = v0072;
    goto v0113;

v0113:
    v0072 = stack[0];
    v0072 = qcdr(v0072);
    stack[0] = v0072;
    goto v0025;

v0022:
    v0072 = v0136;
    v0073 = v0021;
    v0072 = cons(v0072, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-1];
    v0021 = v0072;
    goto v0113;

v0123:
    v0072 = qvalue(elt(env, 3)); /* t */
    goto v0112;

v0159:
    v0072 = qvalue(elt(env, 3)); /* t */
    goto v0112;

v0091:
    v0072 = qvalue(elt(env, 3)); /* t */
    goto v0112;

v0024:
    v0072 = v0021;
    v0072 = Lnreverse(nil, v0072);
    env = stack[-1];
    v0072 = Lcompress(nil, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0160;
        popv(2);
        return Lintern(nil, v0072);
/* error exit handlers */
v0160:
    popv(2);
    return nil;
}



/* Code for bftrim!: */

static Lisp_Object CC_bftrimT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bftrim:");
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
    v0019 = v0000;
/* end of prologue */
    stack[0] = v0019;
    v0103 = qvalue(elt(env, 1)); /* !:bprec!: */
    v0019 = (Lisp_Object)49; /* 3 */
    v0019 = difference2(v0103, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    fn = elt(env, 2); /* round!:mt */
    v0019 = (*qfn2(fn))(qenv(fn), stack[0], v0019);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* normbf */
        return (*qfn1(fn))(qenv(fn), v0019);
    }
/* error exit handlers */
v0115:
    popv(2);
    return nil;
}



/* Code for constp */

static Lisp_Object CC_constp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0105;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for constp");
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
    v0161 = v0000;
/* end of prologue */
    v0105 = v0161;
    v0105 = (is_number(v0105) ? lisp_true : nil);
    if (!(v0105 == nil)) { popv(1); return onevalue(v0105); }
    v0105 = v0161;
    v0105 = Lconsp(nil, v0105);
    env = stack[0];
    if (v0105 == nil) goto v0120;
    v0161 = qcar(v0161);
    v0105 = qvalue(elt(env, 2)); /* domainlist!* */
    v0161 = Lmemq(nil, v0161, v0105);
    { popv(1); return onevalue(v0161); }

v0120:
    v0161 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0161); }
}



/* Code for bczero!? */

static Lisp_Object CC_bczeroW(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0162, v0115;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bczero?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0162 = v0000;
/* end of prologue */
    v0115 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v0115 == nil) goto v0013;
    v0115 = v0162;
    v0162 = (Lisp_Object)1; /* 0 */
        return Leqn(nil, v0115, v0162);

v0013:
    v0162 = qcar(v0162);
    v0162 = (v0162 == nil ? lisp_true : nil);
    return onevalue(v0162);
}



/* Code for wedgepf2 */

static Lisp_Object CC_wedgepf2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0123, v0164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wedgepf2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0027;
    stack[-2] = v0000;
/* end of prologue */
    v0123 = stack[-2];
    if (v0123 == nil) goto v0120;
    v0123 = stack[-1];
    v0123 = (v0123 == nil ? lisp_true : nil);
    goto v0088;

v0088:
    if (v0123 == nil) goto v0083;
    v0123 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v0123); }

v0083:
    v0123 = stack[-2];
    v0164 = qcar(v0123);
    v0123 = stack[-1];
    v0123 = qcar(v0123);
    fn = elt(env, 3); /* wedget2 */
    stack[-3] = (*qfn2(fn))(qenv(fn), v0164, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    v0123 = stack[-2];
    v0123 = qcar(v0123);
    v0164 = ncons(v0123);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    v0123 = stack[-1];
    v0123 = qcdr(v0123);
    stack[0] = CC_wedgepf2(env, v0164, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    v0123 = stack[-2];
    v0164 = qcdr(v0123);
    v0123 = stack[-1];
    v0123 = CC_wedgepf2(env, v0164, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    fn = elt(env, 4); /* addpf */
    v0123 = (*qfn2(fn))(qenv(fn), stack[0], v0123);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    {
        Lisp_Object v0131 = stack[-3];
        popv(5);
        fn = elt(env, 4); /* addpf */
        return (*qfn2(fn))(qenv(fn), v0131, v0123);
    }

v0120:
    v0123 = qvalue(elt(env, 1)); /* t */
    goto v0088;
/* error exit handlers */
v0165:
    popv(5);
    return nil;
}



/* Code for order!: */

static Lisp_Object CC_orderT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0112, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for order:");
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
    v0112 = qcdr(v0112);
    v0091 = qcar(v0112);
    v0112 = (Lisp_Object)1; /* 0 */
    if (v0091 == v0112) goto v0132;
    v0112 = stack[0];
    v0112 = qcdr(v0112);
    v0112 = qcar(v0112);
    v0112 = Labsval(nil, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-2];
    fn = elt(env, 1); /* msd */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-2];
    v0112 = stack[0];
    v0112 = qcdr(v0112);
    v0112 = qcdr(v0112);
    v0112 = sub1(v0112);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    {
        Lisp_Object v0128 = stack[-1];
        popv(3);
        return plus2(v0128, v0112);
    }

v0132:
    v0112 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0112); }
/* error exit handlers */
v0166:
    popv(3);
    return nil;
}



/* Code for collectindices_reversed */

static Lisp_Object CC_collectindices_reversed(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0159, v0167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for collectindices_reversed");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0027;
    stack[-1] = v0000;
/* end of prologue */
    v0159 = stack[-1];
    if (!(!consp(v0159))) goto v0113;
    v0159 = stack[-1];
    fn = elt(env, 2); /* isanindex */
    v0159 = (*qfn1(fn))(qenv(fn), v0159);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    if (v0159 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0167 = stack[-1];
    v0159 = stack[0];
    popv(3);
    return cons(v0167, v0159);

v0113:
    v0159 = stack[-1];
    if (v0159 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0159 = stack[-1];
    v0167 = qcar(v0159);
    v0159 = stack[0];
    v0159 = CC_collectindices_reversed(env, v0167, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-2];
    stack[0] = v0159;
    v0159 = stack[-1];
    v0159 = qcdr(v0159);
    stack[-1] = v0159;
    goto v0113;
/* error exit handlers */
v0141:
    popv(3);
    return nil;
}



/* Code for sinitl */

static Lisp_Object CC_sinitl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sinitl");
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
    v0023 = v0000;
/* end of prologue */
    stack[0] = v0023;
    if (!symbolp(v0023)) v0023 = nil;
    else { v0023 = qfastgets(v0023);
           if (v0023 != nil) { v0023 = elt(v0023, 47); /* initl */
#ifdef RECORD_GET
             if (v0023 != SPID_NOPROP)
                record_get(elt(fastget_names, 47), 1);
             else record_get(elt(fastget_names, 47), 0),
                v0023 = nil; }
           else record_get(elt(fastget_names, 47), 0); }
#else
             if (v0023 == SPID_NOPROP) v0023 = nil; }}
#endif
    fn = elt(env, 1); /* eval */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    {
        Lisp_Object v0013 = stack[0];
        popv(1);
        return Lset(nil, v0013, v0023);
    }
/* error exit handlers */
v0004:
    popv(1);
    return nil;
}



/* Code for aeval!* */

static Lisp_Object CC_aevalH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0013;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aeval*");
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
    v0004 = qvalue(elt(env, 1)); /* nil */
    v0004 = ncons(v0004);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0004; /* alglist!* */
    v0013 = stack[0];
    v0004 = qvalue(elt(env, 1)); /* nil */
    {
        popv(2);
        fn = elt(env, 3); /* reval1 */
        return (*qfn2(fn))(qenv(fn), v0013, v0004);
    }
/* error exit handlers */
v0025:
    popv(2);
    return nil;
}



/* Code for ring_ecart */

static Lisp_Object CC_ring_ecart(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ring_ecart");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0087 = v0000;
/* end of prologue */
    v0018 = v0087;
    v0087 = (Lisp_Object)81; /* 5 */
    {
        fn = elt(env, 1); /* nth */
        return (*qfn2(fn))(qenv(fn), v0018, v0087);
    }
}



/* Code for pappl */

static Lisp_Object CC_pappl(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pappl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0027;
    stack[-3] = v0000;
/* end of prologue */
    stack[-4] = nil;
    v0079 = stack[-3];
    fn = elt(env, 2); /* unpkp */
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    stack[-3] = v0079;
    goto v0003;

v0003:
    v0079 = stack[-3];
    if (v0079 == nil) goto v0023;
    v0079 = stack[-2];
    stack[-1] = v0079;
    v0079 = (Lisp_Object)17; /* 1 */
    stack[0] = v0079;
    goto v0155;

v0155:
    v0079 = stack[-3];
    v0079 = qcar(v0079);
    v0125 = sub1(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    v0079 = stack[0];
    v0079 = difference2(v0125, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    v0079 = Lminusp(nil, v0079);
    env = stack[-5];
    if (v0079 == nil) goto v0083;
    v0079 = stack[-1];
    v0125 = qcar(v0079);
    v0079 = stack[-4];
    v0079 = cons(v0125, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    stack[-4] = v0079;
    v0079 = stack[-3];
    v0079 = qcdr(v0079);
    stack[-3] = v0079;
    goto v0003;

v0083:
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    stack[-1] = v0079;
    v0079 = stack[0];
    v0079 = add1(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-5];
    stack[0] = v0079;
    goto v0155;

v0023:
    v0079 = stack[-4];
        popv(6);
        return Lnreverse(nil, v0079);
/* error exit handlers */
v0168:
    popv(6);
    return nil;
}



/* Code for !*i2mod */

static Lisp_Object CC_Hi2mod(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *i2mod");
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
    v0026 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* general!-modular!-number */
    v0026 = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v0026);
    }
/* error exit handlers */
v0119:
    popv(1);
    return nil;
}



/* Code for getpower */

static Lisp_Object CC_getpower(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0081, v0080;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getpower");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0027;
    stack[-1] = v0000;
/* end of prologue */
    v0081 = stack[-1];
    v0080 = qcar(v0081);
    v0081 = elt(env, 1); /* expt */
    if (!consp(v0080)) goto v0082;
    v0080 = qcar(v0080);
    if (!(v0080 == v0081)) goto v0082;
    v0080 = stack[0];
    v0081 = (Lisp_Object)17; /* 1 */
    v0081 = (Lisp_Object)greaterp2(v0080, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    v0081 = v0081 ? lisp_true : nil;
    env = stack[-2];
    goto v0088;

v0088:
    if (v0081 == nil) goto v0112;
    v0081 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 4)) = v0081; /* !*sub2 */
    goto v0112;

v0112:
    v0081 = stack[-1];
    v0080 = qcar(v0081);
    v0081 = stack[0];
    popv(3);
    return cons(v0080, v0081);

v0082:
    v0081 = qvalue(elt(env, 2)); /* nil */
    goto v0088;
/* error exit handlers */
v0015:
    popv(3);
    return nil;
}



/* Code for rassoc */

static Lisp_Object CC_rassoc(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0113, v0114, v0130, v0155;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rassoc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0130 = v0027;
    v0155 = v0000;
/* end of prologue */

v0026:
    v0113 = v0130;
    if (!consp(v0113)) goto v0088;
    v0114 = v0155;
    v0113 = v0130;
    v0113 = qcar(v0113);
    v0113 = qcdr(v0113);
    if (equal(v0114, v0113)) goto v0023;
    v0113 = v0130;
    v0113 = qcdr(v0113);
    v0130 = v0113;
    goto v0026;

v0023:
    v0113 = v0130;
    v0113 = qcar(v0113);
    return onevalue(v0113);

v0088:
    v0113 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0113);
}



/* Code for delcp */

static Lisp_Object CC_delcp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0132;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delcp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0132 = v0000;
/* end of prologue */
    if (!symbolp(v0132)) v0132 = nil;
    else { v0132 = qfastgets(v0132);
           if (v0132 != nil) { v0132 = elt(v0132, 40); /* delchar */
#ifdef RECORD_GET
             if (v0132 == SPID_NOPROP)
                record_get(elt(fastget_names, 40), 0),
                v0132 = nil;
             else record_get(elt(fastget_names, 40), 1),
                v0132 = lisp_true; }
           else record_get(elt(fastget_names, 40), 0); }
#else
             if (v0132 == SPID_NOPROP) v0132 = nil; else v0132 = lisp_true; }}
#endif
    return onevalue(v0132);
}



/* Code for ofsf_smwupdknowl */

static Lisp_Object MS_CDECL CC_ofsf_smwupdknowl(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0081, v0080, v0127, v0143;
    Lisp_Object fn;
    Lisp_Object v0107, v0126, v0027, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smwupdknowl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0027 = va_arg(aa, Lisp_Object);
    v0126 = va_arg(aa, Lisp_Object);
    v0107 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smwupdknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0081 = v0107;
    v0080 = v0126;
    v0127 = v0027;
    v0143 = v0000;
/* end of prologue */
    v0020 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v0020 == nil) goto v0083;
    v0020 = v0143;
    {
        fn = elt(env, 2); /* cl_susiupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v0020, v0127, v0080, v0081);
    }

v0083:
    v0020 = v0143;
    {
        fn = elt(env, 3); /* ofsf_smupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v0020, v0127, v0080, v0081);
    }
}



/* Code for multsq */

static Lisp_Object CC_multsq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0067, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0027;
    stack[-3] = v0000;
/* end of prologue */
    v0067 = stack[-3];
    v0067 = qcar(v0067);
    if (v0067 == nil) goto v0120;
    v0067 = stack[-2];
    v0067 = qcar(v0067);
    v0067 = (v0067 == nil ? lisp_true : nil);
    goto v0088;

v0088:
    if (v0067 == nil) goto v0112;
    v0095 = qvalue(elt(env, 2)); /* nil */
    v0067 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v0095, v0067);

v0112:
    v0067 = stack[-3];
    v0095 = qcdr(v0067);
    v0067 = (Lisp_Object)17; /* 1 */
    if (v0095 == v0067) goto v0081;
    v0067 = qvalue(elt(env, 2)); /* nil */
    goto v0114;

v0114:
    if (v0067 == nil) goto v0008;
    v0067 = stack[-3];
    v0095 = qcar(v0067);
    v0067 = stack[-2];
    v0067 = qcar(v0067);
    fn = elt(env, 3); /* multf */
    v0095 = (*qfn2(fn))(qenv(fn), v0095, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    v0067 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v0095, v0067);

v0008:
    v0067 = stack[-3];
    v0095 = qcar(v0067);
    v0067 = stack[-2];
    v0067 = qcdr(v0067);
    fn = elt(env, 4); /* gcdf */
    v0067 = (*qfn2(fn))(qenv(fn), v0095, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-5];
    stack[-4] = v0067;
    v0067 = stack[-2];
    v0095 = qcar(v0067);
    v0067 = stack[-3];
    v0067 = qcdr(v0067);
    fn = elt(env, 4); /* gcdf */
    v0067 = (*qfn2(fn))(qenv(fn), v0095, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-5];
    stack[-1] = v0067;
    v0067 = stack[-3];
    v0095 = qcar(v0067);
    v0067 = stack[-4];
    fn = elt(env, 5); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0095, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-5];
    v0067 = stack[-2];
    v0095 = qcar(v0067);
    v0067 = stack[-1];
    fn = elt(env, 5); /* quotf */
    v0067 = (*qfn2(fn))(qenv(fn), v0095, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-5];
    fn = elt(env, 3); /* multf */
    v0067 = (*qfn2(fn))(qenv(fn), stack[0], v0067);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-5];
    stack[0] = v0067;
    v0067 = stack[-3];
    v0095 = qcdr(v0067);
    v0067 = stack[-1];
    fn = elt(env, 5); /* quotf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0095, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-5];
    v0067 = stack[-2];
    v0095 = qcdr(v0067);
    v0067 = stack[-4];
    fn = elt(env, 5); /* quotf */
    v0067 = (*qfn2(fn))(qenv(fn), v0095, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-5];
    fn = elt(env, 3); /* multf */
    v0067 = (*qfn2(fn))(qenv(fn), stack[-1], v0067);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-5];
    stack[-4] = v0067;
    v0095 = stack[0];
    v0067 = stack[-4];
    v0067 = cons(v0095, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 6); /* canonsq */
        return (*qfn1(fn))(qenv(fn), v0067);
    }

v0081:
    v0067 = stack[-2];
    v0095 = qcdr(v0067);
    v0067 = (Lisp_Object)17; /* 1 */
    v0067 = (v0095 == v0067 ? lisp_true : nil);
    goto v0114;

v0120:
    v0067 = qvalue(elt(env, 1)); /* t */
    goto v0088;
/* error exit handlers */
v0179:
    popv(6);
    return nil;
}



/* Code for kernlp */

static Lisp_Object CC_kernlp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0130, v0155;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for kernlp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0130 = v0000;
/* end of prologue */

v0132:
    v0155 = v0130;
    if (!consp(v0155)) goto v0018;
    v0155 = v0130;
    v0155 = qcar(v0155);
    v0155 = (consp(v0155) ? nil : lisp_true);
    goto v0087;

v0087:
    if (!(v0155 == nil)) return onevalue(v0130);
    v0155 = v0130;
    v0155 = qcdr(v0155);
    if (v0155 == nil) goto v0115;
    v0130 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0130);

v0115:
    v0130 = qcar(v0130);
    v0130 = qcdr(v0130);
    goto v0132;

v0018:
    v0155 = qvalue(elt(env, 1)); /* t */
    goto v0087;
}



/* Code for mri_floorkernelp */

static Lisp_Object CC_mri_floorkernelp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_floorkernelp");
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
    v0026 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* kernels */
    v0026 = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mri_floorp */
        return (*qfn1(fn))(qenv(fn), v0026);
    }
/* error exit handlers */
v0119:
    popv(1);
    return nil;
}



/* Code for ibalp_cec */

static Lisp_Object CC_ibalp_cec(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_cec");
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

v0132:
    v0116 = stack[0];
    if (v0116 == nil) goto v0163;
    v0116 = stack[0];
    v0116 = qcar(v0116);
    fn = elt(env, 2); /* ibalp_emptyclausep */
    v0116 = (*qfn1(fn))(qenv(fn), v0116);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-1];
    if (v0116 == nil) goto v0019;
    v0116 = stack[0];
    v0116 = qcar(v0116);
    { popv(2); return onevalue(v0116); }

v0019:
    v0116 = stack[0];
    v0116 = qcdr(v0116);
    stack[0] = v0116;
    goto v0132;

v0163:
    v0116 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0116); }
/* error exit handlers */
v0121:
    popv(2);
    return nil;
}



/* Code for get_token */

static Lisp_Object MS_CDECL CC_get_token(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0166;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "get_token");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get_token");
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
    v0089 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0089;
    goto v0023;

v0023:
    v0166 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0166; /* ch */
    v0089 = elt(env, 3); /* !> */
    if (v0166 == v0089) goto v0113;
    v0166 = qvalue(elt(env, 2)); /* ch */
    v0089 = stack[0];
    v0089 = cons(v0166, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-1];
    stack[0] = v0089;
    goto v0023;

v0113:
    v0166 = elt(env, 4); /* !$ */
    v0089 = stack[0];
    popv(2);
    return cons(v0166, v0089);
/* error exit handlers */
v0129:
    popv(2);
    return nil;
}



/* Code for ps!:order */

static Lisp_Object CC_psTorder(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0127, v0143, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:order");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0015 = v0000;
/* end of prologue */
    v0127 = v0015;
    if (!consp(v0127)) goto v0088;
    v0127 = v0015;
    v0143 = qcar(v0127);
    v0127 = elt(env, 2); /* !:ps!: */
    if (v0143 == v0127) goto v0113;
    v0127 = v0015;
    v0127 = qcar(v0127);
    if (!symbolp(v0127)) v0127 = nil;
    else { v0127 = qfastgets(v0127);
           if (v0127 != nil) { v0127 = elt(v0127, 8); /* dname */
#ifdef RECORD_GET
             if (v0127 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0127 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0127 == SPID_NOPROP) v0127 = nil; }}
#endif
    goto v0163;

v0163:
    if (v0127 == nil) goto v0089;
    v0127 = (Lisp_Object)1; /* 0 */
    return onevalue(v0127);

v0089:
    v0143 = v0015;
    v0127 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 4); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v0143, v0127);
    }

v0113:
    v0127 = qvalue(elt(env, 3)); /* nil */
    goto v0163;

v0088:
    v0127 = qvalue(elt(env, 1)); /* t */
    goto v0163;
}



/* Code for !:zerop */

static Lisp_Object CC_Tzerop(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0129, v0020, v0081;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :zerop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0081 = v0000;
/* end of prologue */
    v0129 = v0081;
    if (v0129 == nil) goto v0088;
    v0020 = v0081;
    v0129 = (Lisp_Object)1; /* 0 */
    v0129 = (v0020 == v0129 ? lisp_true : nil);
    goto v0163;

v0163:
    if (v0129 == nil) goto v0026;
    v0129 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0129);

v0026:
    v0129 = v0081;
    if (!consp(v0129)) goto v0104;
    v0129 = v0081;
    v0129 = qcar(v0129);
    if (!symbolp(v0129)) v0129 = nil;
    else { v0129 = qfastgets(v0129);
           if (v0129 != nil) { v0129 = elt(v0129, 15); /* zerop */
#ifdef RECORD_GET
             if (v0129 != SPID_NOPROP)
                record_get(elt(fastget_names, 15), 1);
             else record_get(elt(fastget_names, 15), 0),
                v0129 = nil; }
           else record_get(elt(fastget_names, 15), 0); }
#else
             if (v0129 == SPID_NOPROP) v0129 = nil; }}
#endif
    v0020 = v0081;
        return Lapply1(nil, v0129, v0020);

v0104:
    v0129 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0129);

v0088:
    v0129 = qvalue(elt(env, 1)); /* t */
    goto v0163;
}



/* Code for evlexcomp */

static Lisp_Object CC_evlexcomp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0178, v0159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evlexcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0027;
    stack[-1] = v0000;
/* end of prologue */

v0026:
    v0178 = stack[-1];
    if (v0178 == nil) goto v0088;
    v0178 = stack[0];
    if (v0178 == nil) goto v0023;
    v0178 = stack[-1];
    v0159 = qcar(v0178);
    v0178 = stack[0];
    v0178 = qcar(v0178);
    fn = elt(env, 2); /* iequal */
    v0178 = (*qfn2(fn))(qenv(fn), v0159, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-2];
    if (v0178 == nil) goto v0091;
    v0178 = stack[-1];
    v0178 = qcdr(v0178);
    stack[-1] = v0178;
    v0178 = stack[0];
    v0178 = qcdr(v0178);
    stack[0] = v0178;
    goto v0026;

v0091:
    v0178 = stack[-1];
    v0159 = qcar(v0178);
    v0178 = stack[0];
    v0178 = qcar(v0178);
    if (((int32_t)(v0159)) > ((int32_t)(v0178))) goto v0155;
    v0178 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v0178); }

v0155:
    v0178 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0178); }

v0023:
    v0178 = elt(env, 1); /* (0) */
    stack[0] = v0178;
    goto v0026;

v0088:
    v0178 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0178); }
/* error exit handlers */
v0110:
    popv(3);
    return nil;
}



/* Code for peel */

static Lisp_Object CC_peel(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for peel");
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
    v0079 = stack[0];
    v0125 = qcar(v0079);
    v0079 = elt(env, 1); /* (liedf innerprod) */
    v0079 = Lmemq(nil, v0125, v0079);
    if (v0079 == nil) goto v0115;
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    { popv(1); return onevalue(v0079); }

v0115:
    v0079 = stack[0];
    v0125 = qcar(v0079);
    v0079 = elt(env, 2); /* quotient */
    if (v0125 == v0079) goto v0091;
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    { popv(1); return onevalue(v0079); }

v0091:
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    v0125 = qcar(v0079);
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    fn = elt(env, 3); /* worderp */
    v0079 = (*qfn2(fn))(qenv(fn), v0125, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    if (v0079 == nil) goto v0167;
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    { popv(1); return onevalue(v0079); }

v0167:
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    { popv(1); return onevalue(v0079); }
/* error exit handlers */
v0164:
    popv(1);
    return nil;
}



/* Code for makelist */

static Lisp_Object CC_makelist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0018;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for makelist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0087 = v0000;
/* end of prologue */
    v0018 = elt(env, 1); /* list */
    return cons(v0018, v0087);
}



/* Code for int!-equiv!-chk */

static Lisp_Object CC_intKequivKchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0074, v0075, v0176;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for int-equiv-chk");
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
    v0074 = qvalue(elt(env, 1)); /* !*noequiv */
    if (!(v0074 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0074 = stack[0];
    if (!consp(v0074)) goto v0116;
    v0074 = stack[0];
    v0074 = qcar(v0074);
    if (!symbolp(v0074)) v0075 = nil;
    else { v0075 = qfastgets(v0074);
           if (v0075 != nil) { v0075 = elt(v0075, 15); /* zerop */
#ifdef RECORD_GET
             if (v0075 != SPID_NOPROP)
                record_get(elt(fastget_names, 15), 1);
             else record_get(elt(fastget_names, 15), 0),
                v0075 = nil; }
           else record_get(elt(fastget_names, 15), 0); }
#else
             if (v0075 == SPID_NOPROP) v0075 = nil; }}
#endif
    v0074 = stack[0];
    v0074 = Lapply1(nil, v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    if (v0074 == nil) goto v0167;
    v0074 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0074); }

v0167:
    v0074 = stack[0];
    v0074 = qcar(v0074);
    if (!symbolp(v0074)) v0075 = nil;
    else { v0075 = qfastgets(v0074);
           if (v0075 != nil) { v0075 = elt(v0075, 26); /* onep */
#ifdef RECORD_GET
             if (v0075 != SPID_NOPROP)
                record_get(elt(fastget_names, 26), 1);
             else record_get(elt(fastget_names, 26), 0),
                v0075 = nil; }
           else record_get(elt(fastget_names, 26), 0); }
#else
             if (v0075 == SPID_NOPROP) v0075 = nil; }}
#endif
    v0074 = stack[0];
    v0074 = Lapply1(nil, v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    if (v0074 == nil) goto v0178;
    v0074 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v0074); }

v0178:
    v0074 = stack[0];
    v0074 = qcar(v0074);
    if (!symbolp(v0074)) v0074 = nil;
    else { v0074 = qfastgets(v0074);
           if (v0074 != nil) { v0074 = elt(v0074, 33); /* intequivfn */
#ifdef RECORD_GET
             if (v0074 != SPID_NOPROP)
                record_get(elt(fastget_names, 33), 1);
             else record_get(elt(fastget_names, 33), 0),
                v0074 = nil; }
           else record_get(elt(fastget_names, 33), 0); }
#else
             if (v0074 == SPID_NOPROP) v0074 = nil; }}
#endif
    v0176 = v0074;
    if (v0074 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0075 = v0176;
    v0074 = stack[0];
    v0074 = Lapply1(nil, v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    v0176 = v0074;
    if (v0074 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0075 = v0176;
    v0074 = (Lisp_Object)1; /* 0 */
    if (!(v0075 == v0074)) { popv(2); return onevalue(v0176); }
    v0074 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0074); }

v0116:
    v0075 = stack[0];
    v0074 = (Lisp_Object)1; /* 0 */
    if (!(v0075 == v0074)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0074 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0074); }
/* error exit handlers */
v0022:
    popv(2);
    return nil;
}



/* Code for pprin2 */

static Lisp_Object CC_pprin2(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0116, v0104;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pprin2");
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
    v0104 = stack[0];
    v0116 = qvalue(elt(env, 1)); /* !*pprinbuf!* */
    v0116 = cons(v0104, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0116; /* !*pprinbuf!* */
    stack[-1] = qvalue(elt(env, 2)); /* !*posn!* */
    v0116 = stack[0];
    v0116 = Lexplodec(nil, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-2];
    v0116 = Llength(nil, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-2];
    v0116 = plus2(stack[-1], v0116);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-2];
    qvalue(elt(env, 2)) = v0116; /* !*posn!* */
    v0116 = nil;
    { popv(3); return onevalue(v0116); }
/* error exit handlers */
v0105:
    popv(3);
    return nil;
}



/* Code for idlistp */

static Lisp_Object CC_idlistp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0130;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for idlistp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0114 = v0000;
/* end of prologue */

v0181:
    v0130 = v0114;
    if (v0130 == nil) goto v0132;
    v0130 = v0114;
    if (!consp(v0130)) goto v0083;
    v0130 = v0114;
    v0130 = qcar(v0130);
    if (symbolp(v0130)) goto v0116;
    v0114 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0114);

v0116:
    v0114 = qcdr(v0114);
    goto v0181;

v0083:
    v0114 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0114);

v0132:
    v0114 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0114);
}



/* Code for getrtypecar */

static Lisp_Object CC_getrtypecar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getrtypecar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0026 = v0000;
/* end of prologue */
    v0026 = qcar(v0026);
    {
        fn = elt(env, 1); /* getrtype */
        return (*qfn1(fn))(qenv(fn), v0026);
    }
}



/* Code for adddm */

static Lisp_Object CC_adddm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0165, v0131, v0076;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for adddm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0131 = v0027;
    v0076 = v0000;
/* end of prologue */
    v0165 = v0076;
    if (!consp(v0165)) goto v0120;
    v0165 = qvalue(elt(env, 1)); /* nil */
    goto v0088;

v0088:
    if (v0165 == nil) goto v0123;
    v0165 = v0076;
    v0165 = plus2(v0165, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[0];
    v0131 = qvalue(elt(env, 2)); /* dmode!* */
    if (v0131 == nil) goto v0155;
    v0131 = qvalue(elt(env, 2)); /* dmode!* */
    if (!symbolp(v0131)) v0131 = nil;
    else { v0131 = qfastgets(v0131);
           if (v0131 != nil) { v0131 = elt(v0131, 5); /* convert */
#ifdef RECORD_GET
             if (v0131 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v0131 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v0131 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v0131 == SPID_NOPROP) v0131 = nil; else v0131 = lisp_true; }}
#endif
    v0131 = (v0131 == nil ? lisp_true : nil);
    goto v0130;

v0130:
    if (v0131 == nil) goto v0178;
    {
        popv(1);
        fn = elt(env, 5); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v0165);
    }

v0178:
    v0131 = qvalue(elt(env, 2)); /* dmode!* */
    if (!symbolp(v0131)) v0131 = nil;
    else { v0131 = qfastgets(v0131);
           if (v0131 != nil) { v0131 = elt(v0131, 34); /* i2d */
#ifdef RECORD_GET
             if (v0131 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0131 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0131 == SPID_NOPROP) v0131 = nil; }}
#endif
    v0165 = Lapply1(nil, v0131, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 6); /* int!-equiv!-chk */
        return (*qfn1(fn))(qenv(fn), v0165);
    }

v0155:
    v0131 = qvalue(elt(env, 3)); /* t */
    goto v0130;

v0123:
    v0165 = elt(env, 4); /* plus */
    {
        popv(1);
        fn = elt(env, 7); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0076, v0131, v0165);
    }

v0120:
    v0165 = v0131;
    v0165 = (consp(v0165) ? nil : lisp_true);
    goto v0088;
/* error exit handlers */
v0077:
    popv(1);
    return nil;
}



/* Code for mo!=sprod */

static Lisp_Object CC_moMsprod(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0164, v0011, v0012;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo=sprod");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0027;
    stack[-1] = v0000;
/* end of prologue */
    v0012 = nil;
    goto v0163;

v0163:
    v0164 = stack[-1];
    if (v0164 == nil) goto v0024;
    v0164 = stack[0];
    v0164 = (v0164 == nil ? lisp_true : nil);
    goto v0013;

v0013:
    if (v0164 == nil) goto v0114;
    v0164 = (Lisp_Object)1; /* 0 */
    goto v0120;

v0120:
    v0011 = v0012;
    if (v0011 == nil) { popv(3); return onevalue(v0164); }
    v0011 = v0012;
    v0011 = qcar(v0011);
    v0164 = (Lisp_Object)(int32_t)((int32_t)v0011 + (int32_t)v0164 - TAG_FIXNUM);
    v0011 = v0012;
    v0011 = qcdr(v0011);
    v0012 = v0011;
    goto v0120;

v0114:
    v0164 = stack[-1];
    v0011 = qcar(v0164);
    v0164 = stack[0];
    v0164 = qcar(v0164);
    v0164 = fixnum_of_int((int32_t)(int_of_fixnum(v0011) * int_of_fixnum(v0164)));
    v0011 = v0012;
    v0164 = cons(v0164, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-2];
    v0012 = v0164;
    v0164 = stack[-1];
    v0164 = qcdr(v0164);
    stack[-1] = v0164;
    v0164 = stack[0];
    v0164 = qcdr(v0164);
    stack[0] = v0164;
    goto v0163;

v0024:
    v0164 = qvalue(elt(env, 1)); /* t */
    goto v0013;
/* error exit handlers */
v0165:
    popv(3);
    return nil;
}



/* Code for dless */

static Lisp_Object CC_dless(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118, v0140, v0182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dless");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0182 = v0027;
    stack[0] = v0000;
/* end of prologue */
    v0140 = qvalue(elt(env, 1)); /* ordering */
    v0118 = elt(env, 2); /* lex */
    if (v0140 == v0118) goto v0013;
    v0118 = stack[0];
    v0140 = qcar(v0118);
    v0118 = v0182;
    v0118 = qcar(v0118);
    if (((int32_t)(v0140)) < ((int32_t)(v0118))) goto v0116;
    v0118 = stack[0];
    v0140 = qcar(v0118);
    v0118 = v0182;
    v0118 = qcar(v0118);
    if (((int32_t)(v0140)) > ((int32_t)(v0118))) goto v0091;
    v0140 = qvalue(elt(env, 1)); /* ordering */
    v0118 = elt(env, 5); /* glex */
    if (v0140 == v0118) goto v0158;
    v0140 = qvalue(elt(env, 1)); /* ordering */
    v0118 = elt(env, 6); /* grev */
    if (v0140 == v0118) goto v0093;
    v0118 = nil;
    { popv(3); return onevalue(v0118); }

v0093:
    v0118 = v0182;
    v0118 = qcdr(v0118);
    stack[-1] = Lreverse(nil, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-2];
    v0118 = stack[0];
    v0118 = qcdr(v0118);
    v0118 = Lreverse(nil, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-2];
    {
        Lisp_Object v0074 = stack[-1];
        popv(3);
        fn = elt(env, 7); /* dlesslex */
        return (*qfn2(fn))(qenv(fn), v0074, v0118);
    }

v0158:
    v0118 = stack[0];
    v0118 = qcdr(v0118);
    v0140 = v0182;
    v0140 = qcdr(v0140);
    {
        popv(3);
        fn = elt(env, 7); /* dlesslex */
        return (*qfn2(fn))(qenv(fn), v0118, v0140);
    }

v0091:
    v0118 = qvalue(elt(env, 4)); /* nil */
    { popv(3); return onevalue(v0118); }

v0116:
    v0118 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v0118); }

v0013:
    v0118 = stack[0];
    v0140 = v0182;
    {
        popv(3);
        fn = elt(env, 7); /* dlesslex */
        return (*qfn2(fn))(qenv(fn), v0118, v0140);
    }
/* error exit handlers */
v0124:
    popv(3);
    return nil;
}



/* Code for sieve_pv */

static Lisp_Object CC_sieve_pv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0013, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sieve_pv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0027;
    v0013 = v0000;
/* end of prologue */
    v0024 = v0013;
    v0013 = v0004;
    v0004 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* sieve_pv0 */
        return (*qfnn(fn))(qenv(fn), 3, v0024, v0013, v0004);
    }
}



/* Code for upbve */

static Lisp_Object CC_upbve(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for upbve");
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
    v0004 = stack[0];
    v0004 = Lupbv(nil, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-1];
    if (v0004 == nil) goto v0132;
    v0004 = stack[0];
    v0004 = Lupbv(nil, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    popv(2);
    return add1(v0004);

v0132:
    v0004 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v0004); }
/* error exit handlers */
v0024:
    popv(2);
    return nil;
}



/* Code for modtimes!: */

static Lisp_Object CC_modtimesT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0013;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for modtimes:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0004 = v0027;
    v0013 = v0000;
/* end of prologue */
    v0013 = qcdr(v0013);
    v0004 = qcdr(v0004);
    fn = elt(env, 1); /* general!-modular!-times */
    v0004 = (*qfn2(fn))(qenv(fn), v0013, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v0004);
    }
/* error exit handlers */
v0024:
    popv(1);
    return nil;
}



/* Code for general!-modular!-plus */

static Lisp_Object CC_generalKmodularKplus(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0122, v0089;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-plus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0122 = v0027;
    v0089 = v0000;
/* end of prologue */
    v0122 = plus2(v0089, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-1];
    stack[0] = v0122;
    v0089 = stack[0];
    v0122 = qvalue(elt(env, 1)); /* current!-modulus */
    v0122 = (Lisp_Object)geq2(v0089, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    v0122 = v0122 ? lisp_true : nil;
    env = stack[-1];
    if (v0122 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0089 = stack[0];
    v0122 = qvalue(elt(env, 1)); /* current!-modulus */
    v0122 = difference2(v0089, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    stack[0] = v0122;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0128:
    popv(2);
    return nil;
}



/* Code for lalr_prin_symbol */

static Lisp_Object CC_lalr_prin_symbol(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0008;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_prin_symbol");
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
    v0008 = stack[0];
    v0007 = (Lisp_Object)1; /* 0 */
    if (v0008 == v0007) goto v0163;
    v0007 = stack[0];
    if (v0007 == nil) goto v0019;
    v0008 = stack[0];
    v0007 = elt(env, 3); /* !. */
    if (v0008 == v0007) goto v0104;
    v0007 = stack[0];
    if (!(is_number(v0007))) goto v0122;
    v0008 = stack[0];
    v0007 = qvalue(elt(env, 5)); /* terminals */
    fn = elt(env, 7); /* rassoc */
    v0007 = (*qfn2(fn))(qenv(fn), v0008, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-1];
    v0008 = v0007;
    if (v0007 == nil) goto v0122;
    v0007 = v0008;
    v0007 = qcar(v0007);
    v0007 = Lprin(nil, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    goto v0119;

v0119:
    v0007 = nil;
    { popv(2); return onevalue(v0007); }

v0122:
    v0007 = stack[0];
    v0007 = Lstringp(nil, v0007);
    env = stack[-1];
    if (v0007 == nil) goto v0158;
    v0007 = stack[0];
    v0007 = Lprin(nil, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    goto v0119;

v0158:
    v0007 = stack[0];
    fn = elt(env, 8); /* explode2uc */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-1];
    stack[0] = v0007;
    goto v0125;

v0125:
    v0007 = stack[0];
    if (v0007 == nil) goto v0119;
    v0007 = stack[0];
    v0007 = qcar(v0007);
    v0007 = Lprinc(nil, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-1];
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    stack[0] = v0007;
    goto v0125;

v0104:
    v0007 = elt(env, 4); /* "." */
    v0007 = Lprinc(nil, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    goto v0119;

v0019:
    v0007 = elt(env, 2); /* "<empty>" */
    v0007 = Lprinc(nil, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    goto v0119;

v0163:
    v0007 = elt(env, 1); /* "$" */
    v0007 = Lprinc(nil, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    goto v0119;
/* error exit handlers */
v0157:
    popv(2);
    return nil;
}



/* Code for monomisdivisibleby */

static Lisp_Object CC_monomisdivisibleby(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0156, v0157, v0108;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monomisdivisibleby");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0108 = v0027;
    v0156 = v0000;
/* end of prologue */
    v0157 = v0156;
    v0156 = (Lisp_Object)17; /* 1 */
    v0156 = *(Lisp_Object *)((char *)v0157 + (CELL-TAG_VECTOR) + ((int32_t)v0156/(16/CELL)));
    stack[-1] = v0156;
    v0157 = v0108;
    v0156 = (Lisp_Object)17; /* 1 */
    v0156 = *(Lisp_Object *)((char *)v0157 + (CELL-TAG_VECTOR) + ((int32_t)v0156/(16/CELL)));
    stack[0] = v0156;
    goto v0161;

v0161:
    v0156 = stack[-1];
    v0156 = qcar(v0156);
    if (v0156 == nil) goto v0121;
    v0156 = stack[0];
    v0156 = qcar(v0156);
    if (v0156 == nil) goto v0121;
    v0156 = stack[-1];
    v0157 = qcar(v0156);
    v0156 = stack[0];
    v0156 = qcar(v0156);
    if (equal(v0157, v0156)) goto v0129;
    v0156 = stack[-1];
    v0157 = qcar(v0156);
    v0156 = stack[0];
    v0156 = qcar(v0156);
    v0156 = (Lisp_Object)greaterp2(v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    v0156 = v0156 ? lisp_true : nil;
    env = stack[-2];
    if (v0156 == nil) goto v0076;
    v0156 = stack[-1];
    v0156 = qcdr(v0156);
    stack[-1] = v0156;
    goto v0161;

v0076:
    v0156 = qvalue(elt(env, 1)); /* nil */
    v0156 = ncons(v0156);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-2];
    stack[-1] = v0156;
    goto v0161;

v0129:
    v0156 = stack[-1];
    v0156 = qcdr(v0156);
    stack[-1] = v0156;
    v0156 = stack[0];
    v0156 = qcdr(v0156);
    stack[0] = v0156;
    goto v0161;

v0121:
    v0156 = stack[0];
    v0156 = qcar(v0156);
    v0156 = (v0156 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v0156); }
/* error exit handlers */
v0177:
    popv(3);
    return nil;
}



/* Code for ofsf_posdefp */

static Lisp_Object CC_ofsf_posdefp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_posdefp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0000;
/* end of prologue */
    v0003 = qvalue(elt(env, 1)); /* !*rlpos */
    if (v0003 == nil) goto v0120;
    v0003 = v0004;
    {
        fn = elt(env, 2); /* ofsf_posdefp!-pos */
        return (*qfn1(fn))(qenv(fn), v0003);
    }

v0120:
    v0003 = v0004;
    {
        fn = elt(env, 3); /* sfto_tsqsumf */
        return (*qfn1(fn))(qenv(fn), v0003);
    }
}



/* Code for lt!* */

static Lisp_Object CC_ltH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076, v0077, v0102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lt*");
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
    v0076 = qvalue(elt(env, 1)); /* !*mcd */
    if (!(v0076 == nil)) goto v0132;
    v0076 = stack[-1];
    v0076 = qcar(v0076);
    v0076 = qcar(v0076);
    v0077 = qcdr(v0076);
    v0076 = (Lisp_Object)1; /* 0 */
    v0076 = (Lisp_Object)greaterp2(v0077, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    v0076 = v0076 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0076 == nil)) goto v0132;
    v0076 = stack[-1];
    v0076 = qcar(v0076);
    stack[-2] = v0076;
    v0076 = stack[-1];
    v0076 = qcar(v0076);
    v0076 = qcar(v0076);
    v0076 = qcar(v0076);
    stack[0] = v0076;
    goto v0082;

v0082:
    v0076 = stack[-1];
    v0076 = qcdr(v0076);
    stack[-1] = v0076;
    v0076 = stack[-1];
    if (v0076 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0077 = stack[-1];
    v0076 = stack[0];
    fn = elt(env, 2); /* degr */
    v0077 = (*qfn2(fn))(qenv(fn), v0077, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-3];
    v0076 = (Lisp_Object)1; /* 0 */
    if (!(v0077 == v0076)) goto v0082;
    v0102 = stack[0];
    v0077 = (Lisp_Object)1; /* 0 */
    v0076 = stack[-1];
    popv(4);
    return acons(v0102, v0077, v0076);

v0132:
    v0076 = stack[-1];
    v0076 = qcar(v0076);
    { popv(4); return onevalue(v0076); }
/* error exit handlers */
v0146:
    popv(4);
    return nil;
}



/* Code for mtchp */

static Lisp_Object MS_CDECL CC_mtchp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0187, v0170, v0188, v0189;
    Lisp_Object fn;
    Lisp_Object v0132, v0107, v0126, v0027, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "mtchp");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0027 = va_arg(aa, Lisp_Object);
    v0126 = va_arg(aa, Lisp_Object);
    v0107 = va_arg(aa, Lisp_Object);
    v0132 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mtchp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0132,v0107,v0126,v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0027,v0126,v0107,v0132);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0132;
    v0187 = v0107;
    stack[-1] = v0126;
    stack[-2] = v0027;
    stack[-3] = v0000;
/* end of prologue */
    v0189 = stack[-3];
    v0188 = stack[-2];
    v0170 = v0187;
    v0187 = stack[0];
    fn = elt(env, 2); /* mtchp1 */
    v0187 = (*qfnn(fn))(qenv(fn), 4, v0189, v0188, v0170, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-5];
    stack[-4] = v0187;
    goto v0120;

v0120:
    v0187 = stack[-4];
    if (v0187 == nil) goto v0083;
    v0187 = stack[-4];
    v0170 = qcar(v0187);
    v0187 = stack[0];
    v0187 = Lsubla(nil, v0170, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-5];
    fn = elt(env, 3); /* lispeval */
    v0187 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-5];
    if (v0187 == nil) goto v0105;
    v0187 = stack[-3];
    stack[0] = qcdr(v0187);
    v0187 = stack[-4];
    v0170 = qcar(v0187);
    v0187 = stack[-2];
    v0187 = qcdr(v0187);
    v0187 = Lsubla(nil, v0170, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-5];
    v0187 = Ldivide(nil, stack[0], v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-5];
    stack[-2] = v0187;
    v0187 = stack[-4];
    v0170 = qcar(v0187);
    v0187 = stack[-1];
    v0187 = Lsubla(nil, v0170, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-5];
    fn = elt(env, 4); /* simp */
    v0170 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-5];
    v0187 = stack[-2];
    v0187 = qcar(v0187);
    fn = elt(env, 5); /* exptsq */
    v0187 = (*qfn2(fn))(qenv(fn), v0170, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-5];
    stack[-1] = v0187;
    v0187 = stack[-2];
    v0170 = qcdr(v0187);
    v0187 = (Lisp_Object)1; /* 0 */
    if (v0170 == v0187) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v0187 = stack[-3];
    v0170 = qcar(v0187);
    v0187 = stack[-2];
    v0187 = qcdr(v0187);
    fn = elt(env, 6); /* to */
    v0170 = (*qfn2(fn))(qenv(fn), v0170, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-5];
    v0187 = (Lisp_Object)17; /* 1 */
    v0187 = cons(v0170, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-5];
    v0170 = ncons(v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-5];
    v0187 = (Lisp_Object)17; /* 1 */
    v0170 = cons(v0170, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-5];
    v0187 = stack[-1];
    fn = elt(env, 7); /* multsq */
    v0187 = (*qfn2(fn))(qenv(fn), v0170, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    stack[-1] = v0187;
    { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }

v0105:
    v0187 = stack[-4];
    v0187 = qcdr(v0187);
    stack[-4] = v0187;
    goto v0120;

v0083:
    v0187 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0187); }
/* error exit handlers */
v0173:
    popv(6);
    return nil;
}



/* Code for not_included */

static Lisp_Object CC_not_included(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0092, v0139, v0158, v0111, v0009;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for not_included");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0009 = v0027;
    v0111 = v0000;
/* end of prologue */
    v0092 = qvalue(elt(env, 1)); /* t */
    v0158 = v0092;
    goto v0120;

v0120:
    v0092 = v0111;
    if (v0092 == nil) goto v0088;
    v0092 = v0158;
    if (v0092 == nil) goto v0088;
    v0092 = v0009;
    v0158 = v0092;
    goto v0116;

v0116:
    v0092 = v0158;
    if (v0092 == nil) goto v0115;
    v0092 = v0111;
    v0139 = qcar(v0092);
    v0092 = v0158;
    v0092 = qcar(v0092);
    if (equal(v0139, v0092)) goto v0115;
    v0092 = v0158;
    v0092 = qcdr(v0092);
    v0158 = v0092;
    goto v0116;

v0115:
    v0092 = v0111;
    v0092 = qcdr(v0092);
    v0111 = v0092;
    goto v0120;

v0088:
    v0092 = v0158;
    if (v0092 == nil) goto v0110;
    v0092 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0092);

v0110:
    v0092 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0092);
}



/* Code for remove!-free!-vars */

static Lisp_Object CC_removeKfreeKvars(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0194, v0195, v0196;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remove-free-vars");
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
    v0194 = stack[0];
    if (!consp(v0194)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0194 = stack[0];
    v0195 = qcar(v0194);
    v0194 = elt(env, 1); /* !~ */
    if (v0195 == v0194) goto v0023;
    v0194 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* remove!-free!-vars!-l */
        return (*qfn1(fn))(qenv(fn), v0194);
    }

v0023:
    v0194 = qvalue(elt(env, 2)); /* !*!*noremove!*!* */
    if (v0194 == nil) goto v0161;
    v0194 = stack[0];
    v0194 = qcdr(v0194);
    v0195 = qcar(v0194);
    v0194 = qvalue(elt(env, 3)); /* frasc!* */
    v0194 = Latsoc(nil, v0195, v0194);
    v0196 = v0194;
    if (!(v0194 == nil)) goto v0113;
    v0194 = stack[0];
    v0194 = qcdr(v0194);
    v0195 = qcar(v0194);
    v0194 = elt(env, 1); /* !~ */
    if (!consp(v0195)) goto v0131;
    v0195 = qcar(v0195);
    if (!(v0195 == v0194)) goto v0131;
    v0194 = stack[0];
    v0194 = qcdr(v0194);
    v0194 = qcar(v0194);
    v0194 = qcdr(v0194);
    v0194 = qcar(v0194);
    v0195 = qvalue(elt(env, 3)); /* frasc!* */
    v0194 = Latsoc(nil, v0194, v0195);
    v0196 = v0194;
    goto v0143;

v0143:
    if (v0194 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    else goto v0113;

v0113:
    v0194 = v0196;
    v0194 = qcdr(v0194);
    { popv(3); return onevalue(v0194); }

v0131:
    v0194 = qvalue(elt(env, 4)); /* nil */
    goto v0143;

v0161:
    v0194 = stack[0];
    v0194 = qcdr(v0194);
    if (!consp(v0194)) goto v0106;
    v0194 = stack[0];
    v0194 = qcdr(v0194);
    v0194 = qcar(v0194);
    stack[-1] = v0194;
    if (is_number(v0194)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0194 = stack[-1];
    if (symbolp(v0194)) goto v0149;
    v0195 = stack[-1];
    v0194 = elt(env, 1); /* !~ */
    if (!consp(v0195)) goto v0101;
    v0195 = qcar(v0195);
    if (!(v0195 == v0194)) goto v0101;
    v0194 = stack[-1];
    v0194 = qcdr(v0194);
    v0194 = qcar(v0194);
    stack[-1] = v0194;
    goto v0002;

v0002:
    if (!(v0194 == nil)) goto v0149;
    v0194 = stack[0];
    v0194 = qcdr(v0194);
    v0194 = qcar(v0194);
    v0194 = qcar(v0194);
    if (symbolp(v0194)) goto v0197;
    v0195 = stack[0];
    v0194 = elt(env, 5); /* "free variable" */
    {
        popv(3);
        fn = elt(env, 8); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0195, v0194);
    }

v0197:
    v0194 = stack[0];
    v0194 = qcdr(v0194);
    v0194 = qcar(v0194);
    v0194 = qcar(v0194);
    fn = elt(env, 9); /* get!-free!-form */
    v0194 = (*qfn1(fn))(qenv(fn), v0194);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-2];
    v0195 = ncons(v0194);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-2];
    v0194 = qvalue(elt(env, 6)); /* frlis!* */
    fn = elt(env, 10); /* union */
    v0194 = (*qfn2(fn))(qenv(fn), v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-2];
    qvalue(elt(env, 6)) = v0194; /* frlis!* */
    v0194 = stack[0];
    v0194 = qcdr(v0194);
    v0194 = qcar(v0194);
    stack[-1] = qcar(v0194);
    v0194 = stack[0];
    v0194 = qcdr(v0194);
    v0194 = qcar(v0194);
    v0194 = qcdr(v0194);
    fn = elt(env, 7); /* remove!-free!-vars!-l */
    v0194 = (*qfn1(fn))(qenv(fn), v0194);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    {
        Lisp_Object v0199 = stack[-1];
        popv(3);
        return cons(v0199, v0194);
    }

v0149:
    v0194 = stack[0];
    v0194 = qcdr(v0194);
    v0194 = qcar(v0194);
    fn = elt(env, 9); /* get!-free!-form */
    v0194 = (*qfn1(fn))(qenv(fn), v0194);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-2];
    v0195 = ncons(v0194);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-2];
    v0194 = qvalue(elt(env, 6)); /* frlis!* */
    fn = elt(env, 10); /* union */
    v0194 = (*qfn2(fn))(qenv(fn), v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-2];
    qvalue(elt(env, 6)) = v0194; /* frlis!* */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v0101:
    v0194 = qvalue(elt(env, 4)); /* nil */
    goto v0002;

v0106:
    v0195 = stack[0];
    v0194 = elt(env, 5); /* "free variable" */
    {
        popv(3);
        fn = elt(env, 8); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0195, v0194);
    }
/* error exit handlers */
v0198:
    popv(3);
    return nil;
}



/* Code for quotsq */

static Lisp_Object CC_quotsq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0003;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0023 = v0027;
    v0003 = v0000;
/* end of prologue */
    stack[0] = v0003;
    fn = elt(env, 1); /* invsq */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-1];
    {
        Lisp_Object v0024 = stack[0];
        popv(2);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0024, v0023);
    }
/* error exit handlers */
v0013:
    popv(2);
    return nil;
}



/* Code for tayexp!-plus2 */

static Lisp_Object CC_tayexpKplus2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0180, v0177, v0117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tayexp-plus2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0027;
    v0177 = v0000;
/* end of prologue */
    v0180 = v0177;
    if (!consp(v0180)) goto v0120;
    v0180 = qvalue(elt(env, 1)); /* nil */
    goto v0088;

v0088:
    if (v0180 == nil) goto v0161;
    v0180 = stack[0];
    popv(3);
    return plus2(v0177, v0180);

v0161:
    v0180 = v0177;
    if (!consp(v0180)) goto v0112;
    v0180 = stack[0];
    if (!consp(v0180)) goto v0015;
    v0180 = stack[0];
    fn = elt(env, 2); /* rnplus!: */
    v0180 = (*qfn2(fn))(qenv(fn), v0177, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    goto v0082;

v0082:
    v0117 = v0180;
    v0180 = v0117;
    v0180 = qcdr(v0180);
    v0177 = qcdr(v0180);
    v0180 = (Lisp_Object)17; /* 1 */
    if (!(v0177 == v0180)) { popv(3); return onevalue(v0117); }
    v0180 = v0117;
    v0180 = qcdr(v0180);
    v0180 = qcar(v0180);
    { popv(3); return onevalue(v0180); }

v0015:
    stack[-1] = v0177;
    v0180 = stack[0];
    fn = elt(env, 3); /* !*i2rn */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-2];
    fn = elt(env, 2); /* rnplus!: */
    v0180 = (*qfn2(fn))(qenv(fn), stack[-1], v0180);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    goto v0082;

v0112:
    v0180 = v0177;
    fn = elt(env, 3); /* !*i2rn */
    v0177 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-2];
    v0180 = stack[0];
    fn = elt(env, 2); /* rnplus!: */
    v0180 = (*qfn2(fn))(qenv(fn), v0177, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    goto v0082;

v0120:
    v0180 = stack[0];
    v0180 = (consp(v0180) ? nil : lisp_true);
    goto v0088;
/* error exit handlers */
v0182:
    popv(3);
    return nil;
}



/* Code for subs2f */

static Lisp_Object CC_subs2f(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108, v0106, v0180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subs2f");
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
    v0106 = qvalue(elt(env, 1)); /* simpcount!* */
    v0108 = qvalue(elt(env, 2)); /* simplimit!* */
    v0108 = (Lisp_Object)greaterp2(v0106, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    v0108 = v0108 ? lisp_true : nil;
    env = stack[-2];
    if (v0108 == nil) goto v0119;
    v0108 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v0108; /* simpcount!* */
    v0180 = elt(env, 3); /* poly */
    v0106 = (Lisp_Object)337; /* 21 */
    v0108 = elt(env, 4); /* "Simplification recursion too deep" */
    fn = elt(env, 9); /* rerror */
    v0108 = (*qfnn(fn))(qenv(fn), 3, v0180, v0106, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    goto v0119;

v0119:
    v0108 = qvalue(elt(env, 1)); /* simpcount!* */
    v0108 = add1(v0108);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0108; /* simpcount!* */
    v0108 = qvalue(elt(env, 5)); /* nil */
    qvalue(elt(env, 6)) = v0108; /* !*sub2 */
    v0108 = stack[0];
    fn = elt(env, 10); /* subs2f1 */
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    stack[-1] = v0108;
    v0108 = qvalue(elt(env, 6)); /* !*sub2 */
    if (!(v0108 == nil)) goto v0128;
    v0108 = qvalue(elt(env, 7)); /* powlis1!* */
    if (!(v0108 == nil)) goto v0128;

v0122:
    v0108 = qvalue(elt(env, 1)); /* simpcount!* */
    v0108 = sub1(v0108);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0108; /* simpcount!* */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v0128:
    v0108 = qvalue(elt(env, 8)); /* !*resubs */
    if (v0108 == nil) goto v0122;
    v0108 = stack[-1];
    v0106 = qcar(v0108);
    v0108 = stack[0];
    if (equal(v0106, v0108)) goto v0125;
    v0108 = qvalue(elt(env, 5)); /* nil */
    goto v0109;

v0109:
    if (v0108 == nil) goto v0169;
    v0108 = qvalue(elt(env, 5)); /* nil */
    qvalue(elt(env, 6)) = v0108; /* !*sub2 */
    goto v0122;

v0169:
    v0108 = stack[-1];
    fn = elt(env, 11); /* subs2q */
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    stack[-1] = v0108;
    goto v0122;

v0125:
    v0108 = stack[-1];
    v0106 = qcdr(v0108);
    v0108 = (Lisp_Object)17; /* 1 */
    v0108 = (v0106 == v0108 ? lisp_true : nil);
    goto v0109;
/* error exit handlers */
v0118:
    popv(3);
    return nil;
}



/* Code for retimes */

static Lisp_Object CC_retimes(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0014;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for retimes");
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
    v0015 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*bool */
    qvalue(elt(env, 1)) = nil; /* !*bool */
    fn = elt(env, 4); /* retimes1 */
    v0015 = (*qfn1(fn))(qenv(fn), v0015);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-1];
    v0014 = v0015;
    if (v0014 == nil) goto v0120;
    v0014 = v0015;
    v0014 = qcdr(v0014);
    if (v0014 == nil) goto v0161;
    v0014 = elt(env, 2); /* times */
    v0015 = cons(v0014, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-1];
    goto v0088;

v0088:
    v0014 = qvalue(elt(env, 1)); /* !*bool */
    if (v0014 == nil) goto v0132;
    v0014 = elt(env, 3); /* minus */
    v0015 = list2(v0014, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-1];
    goto v0132;

v0132:
    qvalue(elt(env, 1)) = stack[0]; /* !*bool */
    { popv(2); return onevalue(v0015); }

v0161:
    v0015 = qcar(v0015);
    goto v0088;

v0120:
    v0015 = (Lisp_Object)17; /* 1 */
    goto v0088;
/* error exit handlers */
v0159:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*bool */
    popv(2);
    return nil;
}



/* Code for mri_floorp */

static Lisp_Object CC_mri_floorp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0113, v0114, v0130;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_floorp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0114 = v0000;
/* end of prologue */

v0181:
    v0113 = v0114;
    if (v0113 == nil) goto v0132;
    v0113 = v0114;
    v0130 = qcar(v0113);
    v0113 = elt(env, 2); /* floor */
    if (!consp(v0130)) goto v0121;
    v0130 = qcar(v0130);
    if (!(v0130 == v0113)) goto v0121;
    v0113 = qvalue(elt(env, 3)); /* t */
    return onevalue(v0113);

v0121:
    v0113 = v0114;
    v0113 = qcdr(v0113);
    v0114 = v0113;
    goto v0181;

v0132:
    v0113 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0113);
}



/* Code for qqe_rbopp */

static Lisp_Object CC_qqe_rbopp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0018;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_rbopp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0087 = v0000;
/* end of prologue */
    v0018 = elt(env, 1); /* (equal neq lessp leq geq greaterp) */
    v0087 = Lmemq(nil, v0087, v0018);
    return onevalue(v0087);
}



/* Code for setcar */

static Lisp_Object CC_setcar(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0003;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setcar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0027;
    v0023 = v0000;
/* end of prologue */
    v0003 = v0023;
    v0023 = stack[0];
    v0023 = Lrplaca(nil, v0003, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
/* error exit handlers */
v0013:
    popv(1);
    return nil;
}



/* Code for notstring */

static Lisp_Object CC_notstring(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0178, v0159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for notstring");
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
    v0014 = v0000;
/* end of prologue */
    v0178 = elt(env, 1); /* !  */
    fn = elt(env, 5); /* delall */
    v0014 = (*qfn2(fn))(qenv(fn), v0178, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[0];
    v0159 = v0014;
    v0014 = v0159;
    v0178 = qcar(v0014);
    v0014 = elt(env, 2); /* !" */
    if (v0178 == v0014) goto v0129;
    v0014 = v0159;
    v0014 = Lreverse(nil, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[0];
    v0178 = qcar(v0014);
    v0014 = elt(env, 2); /* !" */
    v0014 = Lneq(nil, v0178, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[0];
    goto v0019;

v0019:
    if (v0014 == nil) goto v0127;
    v0014 = qvalue(elt(env, 4)); /* t */
    { popv(1); return onevalue(v0014); }

v0127:
    v0014 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v0014); }

v0129:
    v0014 = qvalue(elt(env, 3)); /* nil */
    goto v0019;
/* error exit handlers */
v0167:
    popv(1);
    return nil;
}



/* Code for ps!:last!-term */

static Lisp_Object CC_psTlastKterm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0127, v0143, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:last-term");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0015 = v0000;
/* end of prologue */
    v0127 = v0015;
    if (!consp(v0127)) goto v0088;
    v0127 = v0015;
    v0143 = qcar(v0127);
    v0127 = elt(env, 2); /* !:ps!: */
    if (v0143 == v0127) goto v0113;
    v0127 = v0015;
    v0127 = qcar(v0127);
    if (!symbolp(v0127)) v0127 = nil;
    else { v0127 = qfastgets(v0127);
           if (v0127 != nil) { v0127 = elt(v0127, 8); /* dname */
#ifdef RECORD_GET
             if (v0127 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0127 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0127 == SPID_NOPROP) v0127 = nil; }}
#endif
    goto v0163;

v0163:
    if (v0127 == nil) goto v0089;
    v0127 = qvalue(elt(env, 4)); /* ps!:max!-order */
    return onevalue(v0127);

v0089:
    v0143 = v0015;
    v0127 = (Lisp_Object)17; /* 1 */
    {
        fn = elt(env, 5); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v0143, v0127);
    }

v0113:
    v0127 = qvalue(elt(env, 3)); /* nil */
    goto v0163;

v0088:
    v0127 = qvalue(elt(env, 1)); /* t */
    goto v0163;
}



/* Code for minus!: */

static Lisp_Object CC_minusT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0103;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for minus:");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = elt(env, 1); /* !:rd!: */
    v0019 = stack[0];
    v0019 = qcdr(v0019);
    v0019 = qcar(v0019);
    v0103 = negate(v0019);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    v0019 = stack[0];
    v0019 = qcdr(v0019);
    v0019 = qcdr(v0019);
    {
        Lisp_Object v0104 = stack[-1];
        popv(2);
        return list2star(v0104, v0103, v0019);
    }
/* error exit handlers */
v0116:
    popv(2);
    return nil;
}



/* Code for !*q2a */

static Lisp_Object CC_Hq2a(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *q2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0087 = v0000;
/* end of prologue */
    v0018 = v0087;
    v0087 = qvalue(elt(env, 1)); /* !*nosq */
    {
        fn = elt(env, 2); /* !*q2a1 */
        return (*qfn2(fn))(qenv(fn), v0018, v0087);
    }
}



/* Code for mgenp */

static Lisp_Object CC_mgenp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0103;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mgenp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0103 = v0000;
/* end of prologue */
    v0019 = v0103;
    if (!consp(v0019)) goto v0088;
    v0019 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0019);

v0088:
    v0019 = v0103;
    v0103 = elt(env, 1); /* mgen */
    return get(v0019, v0103);
}



/* Code for rd!:zerop */

static Lisp_Object CC_rdTzerop(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0121;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:zerop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0104 = v0000;
/* end of prologue */
    v0121 = v0104;
    v0121 = qcdr(v0121);
    if (!consp(v0121)) goto v0132;
    v0104 = qcdr(v0104);
    v0121 = qcar(v0104);
    v0104 = (Lisp_Object)1; /* 0 */
    v0104 = (v0121 == v0104 ? lisp_true : nil);
    return onevalue(v0104);

v0132:
    v0104 = qcdr(v0104);
        return Lzerop(nil, v0104);
}



/* Code for factorordp */

static Lisp_Object CC_factorordp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0105, v0083, v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for factorordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0083 = v0027;
    v0082 = v0000;
/* end of prologue */
    v0105 = v0082;
    v0161 = v0083;
    if (v0105 == v0161) goto v0026;
    v0161 = v0082;
    v0105 = v0083;
    {
        fn = elt(env, 2); /* worderp */
        return (*qfn2(fn))(qenv(fn), v0161, v0105);
    }

v0026:
    v0161 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0161);
}



/* Code for !*collectphysops_reversed */

static Lisp_Object CC_Hcollectphysops_reversed(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0081;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *collectphysops_reversed");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0027;
    stack[-1] = v0000;
/* end of prologue */
    v0020 = stack[-1];
    fn = elt(env, 2); /* physopp */
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-2];
    if (v0020 == nil) goto v0115;
    v0081 = stack[-1];
    v0020 = stack[0];
    popv(3);
    return cons(v0081, v0020);

v0115:
    v0020 = stack[-1];
    if (!consp(v0020)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0020 = stack[-1];
    v0081 = qcar(v0020);
    v0020 = stack[0];
    v0020 = CC_Hcollectphysops_reversed(env, v0081, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-2];
    stack[0] = v0020;
    v0020 = stack[-1];
    v0020 = qcdr(v0020);
    stack[-1] = v0020;
    goto v0115;
/* error exit handlers */
v0143:
    popv(3);
    return nil;
}



/* Code for prepsqxx */

static Lisp_Object CC_prepsqxx(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepsqxx");
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
    v0026 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* prepsqx */
    v0026 = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* negnumberchk */
        return (*qfn1(fn))(qenv(fn), v0026);
    }
/* error exit handlers */
v0119:
    popv(1);
    return nil;
}



/* Code for angles!-equal */

static Lisp_Object CC_anglesKequal(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0167, v0109, v0110;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for angles-equal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0027;
    stack[-1] = v0000;
/* end of prologue */
    v0167 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0167;
    goto v0025;

v0025:
    v0109 = stack[-1];
    v0167 = stack[-2];
    v0110 = *(Lisp_Object *)((char *)v0109 + (CELL-TAG_VECTOR) + ((int32_t)v0167/(16/CELL)));
    v0109 = stack[0];
    v0167 = stack[-2];
    v0167 = *(Lisp_Object *)((char *)v0109 + (CELL-TAG_VECTOR) + ((int32_t)v0167/(16/CELL)));
    if (equal(v0110, v0167)) goto v0120;
    v0167 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0167); }

v0120:
    v0167 = stack[-2];
    v0167 = add1(v0167);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-3];
    stack[-2] = v0167;
    v0109 = stack[-2];
    v0167 = (Lisp_Object)129; /* 8 */
    v0167 = (Lisp_Object)lessp2(v0109, v0167);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    v0167 = v0167 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0167 == nil)) goto v0025;
    v0167 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v0167); }
/* error exit handlers */
v0139:
    popv(4);
    return nil;
}



/* Code for pappl0 */

static Lisp_Object CC_pappl0(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pappl0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0003 = v0027;
    v0004 = v0000;
/* end of prologue */
    stack[0] = v0004;
    fn = elt(env, 1); /* unpkp */
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-1];
    fn = elt(env, 2); /* pappl */
    v0003 = (*qfn2(fn))(qenv(fn), stack[0], v0003);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* pkp */
        return (*qfn1(fn))(qenv(fn), v0003);
    }
/* error exit handlers */
v0024:
    popv(2);
    return nil;
}



/* Code for rnonep!: */

static Lisp_Object CC_rnonepT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0113, v0114;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnonep:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0114 = v0000;
/* end of prologue */
    v0082 = v0114;
    v0082 = qcdr(v0082);
    v0113 = qcar(v0082);
    v0082 = (Lisp_Object)17; /* 1 */
    if (v0113 == v0082) goto v0013;
    v0082 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0082);

v0013:
    v0082 = v0114;
    v0082 = qcdr(v0082);
    v0113 = qcdr(v0082);
    v0082 = (Lisp_Object)17; /* 1 */
    v0082 = (v0113 == v0082 ? lisp_true : nil);
    return onevalue(v0082);
}



/* Code for !*d2n */

static Lisp_Object CC_Hd2n(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0023;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *d2n");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0018 = v0000;
/* end of prologue */
    v0023 = v0018;
    if (!(v0023 == nil)) return onevalue(v0018);
    v0018 = (Lisp_Object)1; /* 0 */
    return onevalue(v0018);
}



/* Code for toknump */

static Lisp_Object CC_toknump(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0130, v0155;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for toknump");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0155 = v0000;
/* end of prologue */
    v0114 = v0155;
    v0114 = (is_number(v0114) ? lisp_true : nil);
    if (!(v0114 == nil)) return onevalue(v0114);
    v0130 = v0155;
    v0114 = elt(env, 1); /* !:dn!: */
    if (!consp(v0130)) goto v0104;
    v0130 = qcar(v0130);
    if (!(v0130 == v0114)) goto v0104;
    v0114 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0114);

v0104:
    v0114 = v0155;
    v0130 = elt(env, 3); /* !:int!: */
        return Leqcar(nil, v0114, v0130);
}



/* Code for rl_varlat */

static Lisp_Object CC_rl_varlat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_varlat");
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
    v0018 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_varlat!* */
    v0018 = ncons(v0018);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-1];
    {
        Lisp_Object v0004 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0004, v0018);
    }
/* error exit handlers */
v0003:
    popv(2);
    return nil;
}



/* Code for monomclone */

static Lisp_Object CC_monomclone(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0146, v0007, v0008;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monomclone");
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
    stack[0] = v0000;
/* end of prologue */
    v0093 = stack[0];
    if (v0093 == nil) goto v0132;
    stack[-2] = nil;
    v0093 = (Lisp_Object)17; /* 1 */
    v0093 = Lmkvect(nil, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-4];
    stack[-3] = v0093;
    v0008 = stack[-3];
    v0007 = (Lisp_Object)1; /* 0 */
    v0146 = stack[0];
    v0093 = (Lisp_Object)1; /* 0 */
    v0093 = *(Lisp_Object *)((char *)v0146 + (CELL-TAG_VECTOR) + ((int32_t)v0093/(16/CELL)));
    *(Lisp_Object *)((char *)v0008 + (CELL-TAG_VECTOR) + ((int32_t)v0007/(16/CELL))) = v0093;
    v0146 = stack[0];
    v0093 = (Lisp_Object)17; /* 1 */
    v0093 = *(Lisp_Object *)((char *)v0146 + (CELL-TAG_VECTOR) + ((int32_t)v0093/(16/CELL)));
    stack[0] = v0093;
    goto v0143;

v0143:
    v0093 = stack[0];
    if (v0093 == nil) goto v0164;
    v0093 = stack[0];
    v0146 = qcar(v0093);
    v0093 = stack[-2];
    v0093 = cons(v0146, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-4];
    stack[-2] = v0093;
    v0093 = stack[0];
    v0093 = qcdr(v0093);
    stack[0] = v0093;
    goto v0143;

v0164:
    stack[-1] = stack[-3];
    stack[0] = (Lisp_Object)17; /* 1 */
    v0093 = stack[-2];
    v0093 = Lreverse(nil, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0093;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v0132:
    v0093 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0093); }
/* error exit handlers */
v0180:
    popv(5);
    return nil;
}



/* Code for rmultpf */

static Lisp_Object CC_rmultpf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0182, v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rmultpf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0027;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0119;

v0119:
    v0182 = stack[-1];
    if (v0182 == nil) goto v0120;
    v0182 = stack[-1];
    if (!consp(v0182)) goto v0116;
    v0182 = stack[-1];
    v0182 = qcar(v0182);
    v0182 = (consp(v0182) ? nil : lisp_true);
    goto v0115;

v0115:
    if (v0182 == nil) goto v0122;
    v0182 = qvalue(elt(env, 1)); /* t */
    goto v0025;

v0025:
    if (v0182 == nil) goto v0012;
    stack[0] = stack[-3];
    v0005 = stack[-2];
    v0182 = stack[-1];
    v0182 = cons(v0005, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-4];
    v0182 = ncons(v0182);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-4];
    {
        Lisp_Object v0200 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0200, v0182);
    }

v0012:
    v0182 = stack[-1];
    v0182 = qcar(v0182);
    stack[0] = qcar(v0182);
    v0005 = stack[-2];
    v0182 = stack[-1];
    v0182 = qcar(v0182);
    v0182 = qcdr(v0182);
    v0005 = CC_rmultpf(env, v0005, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-4];
    v0182 = stack[-3];
    v0182 = acons(stack[0], v0005, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-4];
    stack[-3] = v0182;
    v0182 = stack[-1];
    v0182 = qcdr(v0182);
    stack[-1] = v0182;
    goto v0119;

v0122:
    v0182 = stack[-2];
    v0005 = qcar(v0182);
    v0182 = stack[-1];
    v0182 = qcar(v0182);
    v0182 = qcar(v0182);
    v0182 = qcar(v0182);
    fn = elt(env, 3); /* reordop */
    v0182 = (*qfn2(fn))(qenv(fn), v0005, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-4];
    goto v0025;

v0116:
    v0182 = qvalue(elt(env, 1)); /* t */
    goto v0115;

v0120:
    v0182 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0182);
    }
/* error exit handlers */
v0176:
    popv(5);
    return nil;
}



/* Code for symbollessp */

static Lisp_Object CC_symbollessp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0122, v0089, v0166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for symbollessp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0089 = v0027;
    v0166 = v0000;
/* end of prologue */
    v0122 = v0089;
    if (v0122 == nil) goto v0026;
    v0122 = v0166;
    if (v0122 == nil) goto v0120;
    v0122 = qvalue(elt(env, 3)); /* wukord!* */
    if (v0122 == nil) goto v0083;
    v0122 = v0166;
    {
        fn = elt(env, 4); /* wuorderp */
        return (*qfn2(fn))(qenv(fn), v0122, v0089);
    }

v0083:
    v0122 = v0166;
    v0122 = Lorderp(nil, v0122, v0089);
    errexit();
    v0122 = (v0122 == nil ? lisp_true : nil);
    return onevalue(v0122);

v0120:
    v0122 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0122);

v0026:
    v0122 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0122);
}



/* Code for comfac!-to!-poly */

static Lisp_Object CC_comfacKtoKpoly(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0013;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for comfac-to-poly");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0000;
/* end of prologue */
    v0013 = v0004;
    v0013 = qcar(v0013);
    if (v0013 == nil) goto v0132;
    return ncons(v0004);

v0132:
    v0004 = qcdr(v0004);
    return onevalue(v0004);
}



/* Code for freeofdepl */

static Lisp_Object MS_CDECL CC_freeofdepl(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0080, v0127;
    Lisp_Object fn;
    Lisp_Object v0126, v0027, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "freeofdepl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0027 = va_arg(aa, Lisp_Object);
    v0126 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freeofdepl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0126,v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0027,v0126);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0126;
    stack[-1] = v0027;
    stack[-2] = v0000;
/* end of prologue */

v0119:
    v0080 = stack[-2];
    if (v0080 == nil) goto v0120;
    v0127 = stack[0];
    v0080 = stack[-2];
    v0080 = qcar(v0080);
    v0080 = qcdr(v0080);
    fn = elt(env, 3); /* smember */
    v0080 = (*qfn2(fn))(qenv(fn), v0127, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    if (v0080 == nil) goto v0128;
    v0080 = stack[-2];
    v0080 = qcar(v0080);
    v0127 = qcar(v0080);
    v0080 = stack[-1];
    fn = elt(env, 3); /* smember */
    v0080 = (*qfn2(fn))(qenv(fn), v0127, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    if (v0080 == nil) goto v0128;
    v0080 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0080); }

v0128:
    v0080 = stack[-2];
    v0080 = qcdr(v0080);
    stack[-2] = v0080;
    goto v0119;

v0120:
    v0080 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v0080); }
/* error exit handlers */
v0178:
    popv(4);
    return nil;
}



/* Code for nocp */

static Lisp_Object CC_nocp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nocp");
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

v0181:
    v0121 = stack[0];
    if (v0121 == nil) goto v0132;
    v0121 = stack[0];
    v0121 = qcar(v0121);
    v0121 = qcar(v0121);
    fn = elt(env, 3); /* noncomp */
    v0121 = (*qfn1(fn))(qenv(fn), v0121);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-1];
    if (v0121 == nil) goto v0023;
    v0121 = stack[0];
    v0121 = qcdr(v0121);
    stack[0] = v0121;
    goto v0181;

v0023:
    v0121 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0121); }

v0132:
    v0121 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0121); }
/* error exit handlers */
v0105:
    popv(2);
    return nil;
}



/* Code for qqe_qopheadp */

static Lisp_Object CC_qqe_qopheadp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0018;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_qopheadp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0087 = v0000;
/* end of prologue */
    v0018 = elt(env, 1); /* (lhead rhead) */
    v0087 = Lmemq(nil, v0087, v0018);
    return onevalue(v0087);
}



/* Code for xsimp */

static Lisp_Object CC_xsimp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xsimp");
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
    v0026 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v0026 = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* expchk */
        return (*qfn1(fn))(qenv(fn), v0026);
    }
/* error exit handlers */
v0119:
    popv(1);
    return nil;
}



/* Code for replus1 */

static Lisp_Object CC_replus1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0141, v0142, v0092;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for replus1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0092 = v0000;
/* end of prologue */
    v0141 = v0092;
    if (v0141 == nil) goto v0132;
    v0141 = v0092;
    if (!consp(v0141)) goto v0023;
    v0142 = v0092;
    v0141 = elt(env, 2); /* plus */
    if (!consp(v0142)) goto v0155;
    v0142 = qcar(v0142);
    if (!(v0142 == v0141)) goto v0155;
    v0141 = v0092;
    v0141 = qcdr(v0141);
    goto v0018;

v0018:
    if (!(v0141 == nil)) return onevalue(v0092);
    v0141 = v0092;
    v0141 = qcdr(v0141);
    if (v0141 == nil) goto v0089;
    v0141 = elt(env, 2); /* plus */
    v0142 = v0092;
    return cons(v0141, v0142);

v0089:
    v0141 = v0092;
    v0141 = qcar(v0141);
    return onevalue(v0141);

v0155:
    v0141 = qvalue(elt(env, 3)); /* nil */
    goto v0018;

v0023:
    v0141 = qvalue(elt(env, 1)); /* t */
    goto v0018;

v0132:
    v0141 = (Lisp_Object)1; /* 0 */
    return onevalue(v0141);
}



/* Code for evmatrixcomp1 */

static Lisp_Object MS_CDECL CC_evmatrixcomp1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0146, v0007;
    Lisp_Object fn;
    Lisp_Object v0126, v0027, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evmatrixcomp1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0027 = va_arg(aa, Lisp_Object);
    v0126 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evmatrixcomp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0126,v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0027,v0126);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0126;
    stack[-2] = v0027;
    stack[-3] = v0000;
/* end of prologue */

v0181:
    v0093 = stack[-1];
    if (v0093 == nil) goto v0119;
    v0007 = stack[-3];
    v0093 = stack[-1];
    v0146 = qcar(v0093);
    v0093 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 1); /* evmatrixcomp2 */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0007, v0146, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    v0007 = stack[-2];
    v0093 = stack[-1];
    v0146 = qcar(v0093);
    v0093 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 1); /* evmatrixcomp2 */
    v0093 = (*qfnn(fn))(qenv(fn), 3, v0007, v0146, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    stack[-4] = stack[0];
    stack[0] = v0093;
    v0146 = stack[-4];
    v0093 = stack[0];
    fn = elt(env, 2); /* iequal */
    v0093 = (*qfn2(fn))(qenv(fn), v0146, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[-5];
    if (v0093 == nil) goto v0011;
    v0007 = stack[-3];
    v0146 = stack[-2];
    v0093 = stack[-1];
    v0093 = qcdr(v0093);
    stack[-3] = v0007;
    stack[-2] = v0146;
    stack[-1] = v0093;
    goto v0181;

v0011:
    v0146 = stack[-4];
    v0093 = stack[0];
    if (((int32_t)(v0146)) > ((int32_t)(v0093))) goto v0123;
    v0093 = (Lisp_Object)-15; /* -1 */
    { popv(6); return onevalue(v0093); }

v0123:
    v0093 = (Lisp_Object)17; /* 1 */
    { popv(6); return onevalue(v0093); }

v0119:
    v0093 = (Lisp_Object)1; /* 0 */
    { popv(6); return onevalue(v0093); }
/* error exit handlers */
v0180:
    popv(6);
    return nil;
}



/* Code for reordop */

static Lisp_Object CC_reordop(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0112, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reordop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0027;
    stack[-1] = v0000;
/* end of prologue */
    v0112 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v0112 == nil) goto v0088;
    v0112 = stack[-1];
    fn = elt(env, 3); /* noncomp1 */
    v0112 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-2];
    if (v0112 == nil) goto v0024;
    v0112 = stack[0];
    fn = elt(env, 3); /* noncomp1 */
    v0112 = (*qfn1(fn))(qenv(fn), v0112);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-2];
    goto v0163;

v0163:
    if (!(v0112 == nil)) { popv(3); return onevalue(v0112); }
    v0091 = stack[-1];
    v0112 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* ordop */
        return (*qfn2(fn))(qenv(fn), v0091, v0112);
    }

v0024:
    v0112 = qvalue(elt(env, 2)); /* nil */
    goto v0163;

v0088:
    v0112 = qvalue(elt(env, 2)); /* nil */
    goto v0163;
/* error exit handlers */
v0166:
    popv(3);
    return nil;
}



/* Code for errorp */

static Lisp_Object CC_errorp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0003;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for errorp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0003 = v0000;
/* end of prologue */
    v0023 = v0003;
    if (!consp(v0023)) goto v0132;
    v0023 = v0003;
    v0023 = qcdr(v0023);
    return onevalue(v0023);

v0132:
    v0023 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0023);
}



/* Code for mo_vdivides!? */

static Lisp_Object CC_mo_vdividesW(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_vdivides?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0027;
    stack[-1] = v0000;
/* end of prologue */
    v0082 = stack[-1];
    fn = elt(env, 2); /* mo_comp */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-3];
    v0082 = stack[0];
    fn = elt(env, 2); /* mo_comp */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-3];
    v0082 = Leqn(nil, stack[-2], v0082);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-3];
    if (v0082 == nil) goto v0026;
    v0113 = stack[-1];
    v0082 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* mo_divides!? */
        return (*qfn2(fn))(qenv(fn), v0113, v0082);
    }

v0026:
    v0082 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0082); }
/* error exit handlers */
v0112:
    popv(4);
    return nil;
}



/* Code for !:minus */

static Lisp_Object CC_Tminus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0110, v0141, v0142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :minus");
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
    v0141 = v0000;
/* end of prologue */
    v0110 = v0141;
    if (v0110 == nil) goto v0132;
    v0110 = v0141;
    if (!consp(v0110)) goto v0088;
    v0110 = v0141;
    v0142 = qcar(v0110);
    v0110 = elt(env, 2); /* minus */
    v0110 = get(v0142, v0110);
    env = stack[0];
    v0142 = v0110;
    v0110 = v0142;
    if (v0110 == nil) goto v0081;
    v0110 = v0142;
        popv(1);
        return Lapply1(nil, v0110, v0141);

v0081:
    v0142 = v0141;
    v0141 = (Lisp_Object)-15; /* -1 */
    v0110 = elt(env, 3); /* times */
    {
        popv(1);
        fn = elt(env, 4); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0142, v0141, v0110);
    }

v0088:
    v0110 = v0141;
    popv(1);
    return negate(v0110);

v0132:
    v0110 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0110); }
}



/* Code for pv_multc */

static Lisp_Object CC_pv_multc(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0027)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0182, v0005, v0006;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pv_multc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0027,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0027;
    stack[-1] = v0000;
/* end of prologue */
    v0005 = stack[0];
    v0182 = (Lisp_Object)1; /* 0 */
    if (v0005 == v0182) goto v0120;
    v0182 = stack[-1];
    v0182 = (v0182 == nil ? lisp_true : nil);
    goto v0088;

v0088:
    if (v0182 == nil) goto v0105;
    v0182 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0182); }

v0105:
    v0005 = stack[0];
    v0182 = (Lisp_Object)17; /* 1 */
    if (v0005 == v0182) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = nil;
    goto v0081;

v0081:
    v0182 = stack[-1];
    if (v0182 == nil) goto v0020;
    v0182 = stack[-1];
    v0182 = qcar(v0182);
    v0005 = qcar(v0182);
    v0182 = (Lisp_Object)1; /* 0 */
    if (v0005 == v0182) goto v0167;
    v0005 = stack[0];
    v0182 = stack[-1];
    v0182 = qcar(v0182);
    v0182 = qcar(v0182);
    v0006 = times2(v0005, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-3];
    v0182 = stack[-1];
    v0182 = qcar(v0182);
    v0005 = qcdr(v0182);
    v0182 = stack[-2];
    v0182 = acons(v0006, v0005, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-3];
    stack[-2] = v0182;
    goto v0167;

v0167:
    v0182 = stack[-1];
    v0182 = qcdr(v0182);
    stack[-1] = v0182;
    goto v0081;

v0020:
    v0182 = stack[-2];
        popv(4);
        return Lnreverse(nil, v0182);

v0120:
    v0182 = qvalue(elt(env, 1)); /* t */
    goto v0088;
/* error exit handlers */
v0176:
    popv(4);
    return nil;
}



setup_type const u02_setup[] =
{
    {"rank",                    CC_rank,        too_many_1,    wrong_no_1},
    {"fctargs",                 CC_fctargs,     too_many_1,    wrong_no_1},
    {"mchk",                    too_few_2,      CC_mchk,       wrong_no_2},
    {"exptchksq",               CC_exptchksq,   too_many_1,    wrong_no_1},
    {"multd",                   too_few_2,      CC_multd,      wrong_no_2},
    {"qqe_qopaddp",             CC_qqe_qopaddp, too_many_1,    wrong_no_1},
    {"reorder",                 CC_reorder,     too_many_1,    wrong_no_1},
    {"ibalp_cequal",            too_few_2,      CC_ibalp_cequal,wrong_no_2},
    {"compress*",               CC_compressH,   too_many_1,    wrong_no_1},
    {"bftrim:",                 CC_bftrimT,     too_many_1,    wrong_no_1},
    {"constp",                  CC_constp,      too_many_1,    wrong_no_1},
    {"bczero?",                 CC_bczeroW,     too_many_1,    wrong_no_1},
    {"wedgepf2",                too_few_2,      CC_wedgepf2,   wrong_no_2},
    {"order:",                  CC_orderT,      too_many_1,    wrong_no_1},
    {"collectindices_reversed", too_few_2,      CC_collectindices_reversed,wrong_no_2},
    {"sinitl",                  CC_sinitl,      too_many_1,    wrong_no_1},
    {"aeval*",                  CC_aevalH,      too_many_1,    wrong_no_1},
    {"ring_ecart",              CC_ring_ecart,  too_many_1,    wrong_no_1},
    {"pappl",                   too_few_2,      CC_pappl,      wrong_no_2},
    {"*i2mod",                  CC_Hi2mod,      too_many_1,    wrong_no_1},
    {"getpower",                too_few_2,      CC_getpower,   wrong_no_2},
    {"rassoc",                  too_few_2,      CC_rassoc,     wrong_no_2},
    {"delcp",                   CC_delcp,       too_many_1,    wrong_no_1},
    {"ofsf_smwupdknowl",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smwupdknowl},
    {"multsq",                  too_few_2,      CC_multsq,     wrong_no_2},
    {"kernlp",                  CC_kernlp,      too_many_1,    wrong_no_1},
    {"mri_floorkernelp",        CC_mri_floorkernelp,too_many_1,wrong_no_1},
    {"ibalp_cec",               CC_ibalp_cec,   too_many_1,    wrong_no_1},
    {"get_token",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_get_token},
    {"ps:order",                CC_psTorder,    too_many_1,    wrong_no_1},
    {":zerop",                  CC_Tzerop,      too_many_1,    wrong_no_1},
    {"evlexcomp",               too_few_2,      CC_evlexcomp,  wrong_no_2},
    {"peel",                    CC_peel,        too_many_1,    wrong_no_1},
    {"makelist",                CC_makelist,    too_many_1,    wrong_no_1},
    {"int-equiv-chk",           CC_intKequivKchk,too_many_1,   wrong_no_1},
    {"pprin2",                  CC_pprin2,      too_many_1,    wrong_no_1},
    {"idlistp",                 CC_idlistp,     too_many_1,    wrong_no_1},
    {"getrtypecar",             CC_getrtypecar, too_many_1,    wrong_no_1},
    {"adddm",                   too_few_2,      CC_adddm,      wrong_no_2},
    {"mo=sprod",                too_few_2,      CC_moMsprod,   wrong_no_2},
    {"dless",                   too_few_2,      CC_dless,      wrong_no_2},
    {"sieve_pv",                too_few_2,      CC_sieve_pv,   wrong_no_2},
    {"upbve",                   CC_upbve,       too_many_1,    wrong_no_1},
    {"modtimes:",               too_few_2,      CC_modtimesT,  wrong_no_2},
    {"general-modular-plus",    too_few_2,      CC_generalKmodularKplus,wrong_no_2},
    {"lalr_prin_symbol",        CC_lalr_prin_symbol,too_many_1,wrong_no_1},
    {"monomisdivisibleby",      too_few_2,      CC_monomisdivisibleby,wrong_no_2},
    {"ofsf_posdefp",            CC_ofsf_posdefp,too_many_1,    wrong_no_1},
    {"lt*",                     CC_ltH,         too_many_1,    wrong_no_1},
    {"mtchp",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_mtchp},
    {"not_included",            too_few_2,      CC_not_included,wrong_no_2},
    {"remove-free-vars",        CC_removeKfreeKvars,too_many_1,wrong_no_1},
    {"quotsq",                  too_few_2,      CC_quotsq,     wrong_no_2},
    {"tayexp-plus2",            too_few_2,      CC_tayexpKplus2,wrong_no_2},
    {"subs2f",                  CC_subs2f,      too_many_1,    wrong_no_1},
    {"retimes",                 CC_retimes,     too_many_1,    wrong_no_1},
    {"mri_floorp",              CC_mri_floorp,  too_many_1,    wrong_no_1},
    {"qqe_rbopp",               CC_qqe_rbopp,   too_many_1,    wrong_no_1},
    {"setcar",                  too_few_2,      CC_setcar,     wrong_no_2},
    {"notstring",               CC_notstring,   too_many_1,    wrong_no_1},
    {"ps:last-term",            CC_psTlastKterm,too_many_1,    wrong_no_1},
    {"minus:",                  CC_minusT,      too_many_1,    wrong_no_1},
    {"*q2a",                    CC_Hq2a,        too_many_1,    wrong_no_1},
    {"mgenp",                   CC_mgenp,       too_many_1,    wrong_no_1},
    {"rd:zerop",                CC_rdTzerop,    too_many_1,    wrong_no_1},
    {"factorordp",              too_few_2,      CC_factorordp, wrong_no_2},
    {"*collectphysops_reversed",too_few_2,      CC_Hcollectphysops_reversed,wrong_no_2},
    {"prepsqxx",                CC_prepsqxx,    too_many_1,    wrong_no_1},
    {"angles-equal",            too_few_2,      CC_anglesKequal,wrong_no_2},
    {"pappl0",                  too_few_2,      CC_pappl0,     wrong_no_2},
    {"rnonep:",                 CC_rnonepT,     too_many_1,    wrong_no_1},
    {"*d2n",                    CC_Hd2n,        too_many_1,    wrong_no_1},
    {"toknump",                 CC_toknump,     too_many_1,    wrong_no_1},
    {"rl_varlat",               CC_rl_varlat,   too_many_1,    wrong_no_1},
    {"monomclone",              CC_monomclone,  too_many_1,    wrong_no_1},
    {"rmultpf",                 too_few_2,      CC_rmultpf,    wrong_no_2},
    {"symbollessp",             too_few_2,      CC_symbollessp,wrong_no_2},
    {"comfac-to-poly",          CC_comfacKtoKpoly,too_many_1,  wrong_no_1},
    {"freeofdepl",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_freeofdepl},
    {"nocp",                    CC_nocp,        too_many_1,    wrong_no_1},
    {"qqe_qopheadp",            CC_qqe_qopheadp,too_many_1,    wrong_no_1},
    {"xsimp",                   CC_xsimp,       too_many_1,    wrong_no_1},
    {"replus1",                 CC_replus1,     too_many_1,    wrong_no_1},
    {"evmatrixcomp1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_evmatrixcomp1},
    {"reordop",                 too_few_2,      CC_reordop,    wrong_no_2},
    {"errorp",                  CC_errorp,      too_many_1,    wrong_no_1},
    {"mo_vdivides?",            too_few_2,      CC_mo_vdividesW,wrong_no_2},
    {":minus",                  CC_Tminus,      too_many_1,    wrong_no_1},
    {"pv_multc",                too_few_2,      CC_pv_multc,   wrong_no_2},
    {NULL, (one_args *)"u02", (two_args *)"3928 6232047 3835993", 0}
};

/* end of generated code */
