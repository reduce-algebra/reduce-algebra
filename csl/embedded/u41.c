
/* $destdir\u41.c        Machine generated C code */

/* Signature: 00000000 28-Sep-2011 */

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


/* Code for pasf_cein */

static Lisp_Object CC_pasf_cein(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045, v0046;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_cein");
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
    v0046 = stack[-3];
    v0045 = elt(env, 1); /* true */
    if (v0046 == v0045) goto v0047;
    v0046 = stack[-3];
    v0045 = elt(env, 3); /* false */
    v0045 = (v0046 == v0045 ? lisp_true : nil);
    goto v0048;

v0048:
    if (v0045 == nil) goto v0049;
    v0045 = qvalue(elt(env, 2)); /* t */
    goto v0050;

v0050:
    if (!(v0045 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0045 = stack[-3];
    v0045 = qcdr(v0045);
    v0045 = qcar(v0045);
    fn = elt(env, 10); /* pasf_deci */
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-5];
    stack[-2] = v0045;
    v0045 = stack[-2];
    v0045 = qcar(v0045);
    fn = elt(env, 11); /* sfto_dcontentf */
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-5];
    stack[-4] = v0045;
    v0045 = stack[-3];
    stack[-1] = qcar(v0045);
    v0045 = stack[-4];
    fn = elt(env, 12); /* simp */
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-5];
    v0045 = qcar(v0045);
    v0046 = qvalue(elt(env, 5)); /* !*exp */
    if (v0046 == nil) goto v0052;
    v0046 = qvalue(elt(env, 6)); /* !*mcd */
    v0046 = (v0046 == nil ? lisp_true : nil);
    goto v0053;

v0053:
    if (v0046 == nil) goto v0054;
    v0046 = stack[-2];
    v0046 = qcar(v0046);
    fn = elt(env, 13); /* quotf */
    v0045 = (*qfn2(fn))(qenv(fn), v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-5];
    stack[0] = v0045;
    goto v0055;

v0055:
    v0046 = stack[-3];
    v0045 = elt(env, 1); /* true */
    if (v0046 == v0045) goto v0056;
    v0046 = stack[-3];
    v0045 = elt(env, 3); /* false */
    v0045 = (v0046 == v0045 ? lisp_true : nil);
    goto v0057;

v0057:
    if (v0045 == nil) goto v0058;
    v0045 = stack[-3];
    v0046 = v0045;
    goto v0059;

v0059:
    v0045 = elt(env, 7); /* (leq greaterp) */
    v0045 = Lmemq(nil, v0046, v0045);
    if (v0045 == nil) goto v0060;
    v0045 = stack[-2];
    v0045 = qcdr(v0045);
    v0046 = negate(v0045);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-5];
    v0045 = stack[-4];
    fn = elt(env, 14); /* pasf_floor */
    v0045 = (*qfn2(fn))(qenv(fn), v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-5];
    fn = elt(env, 15); /* negf */
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-5];
    goto v0061;

v0061:
    fn = elt(env, 16); /* addf */
    v0045 = (*qfn2(fn))(qenv(fn), stack[0], v0045);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-5];
    v0046 = qvalue(elt(env, 9)); /* nil */
    {
        Lisp_Object v0062 = stack[-1];
        popv(6);
        return list3(v0062, v0045, v0046);
    }

v0060:
    v0046 = stack[-3];
    v0045 = elt(env, 1); /* true */
    if (v0046 == v0045) goto v0063;
    v0046 = stack[-3];
    v0045 = elt(env, 3); /* false */
    v0045 = (v0046 == v0045 ? lisp_true : nil);
    goto v0064;

v0064:
    if (v0045 == nil) goto v0065;
    v0045 = stack[-3];
    v0046 = v0045;
    goto v0066;

v0066:
    v0045 = elt(env, 8); /* (geq lessp) */
    v0045 = Lmemq(nil, v0046, v0045);
    if (v0045 == nil) goto v0067;
    v0045 = stack[-2];
    v0045 = qcdr(v0045);
    v0046 = negate(v0045);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-5];
    v0045 = stack[-4];
    fn = elt(env, 17); /* pasf_ceil */
    v0045 = (*qfn2(fn))(qenv(fn), v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-5];
    fn = elt(env, 15); /* negf */
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-5];
    goto v0061;

v0067:
    v0045 = nil;
    goto v0061;

v0065:
    v0045 = stack[-3];
    v0045 = qcar(v0045);
    v0045 = Lconsp(nil, v0045);
    env = stack[-5];
    if (v0045 == nil) goto v0068;
    v0045 = stack[-3];
    v0045 = qcar(v0045);
    v0045 = qcar(v0045);
    v0046 = v0045;
    goto v0066;

v0068:
    v0045 = stack[-3];
    v0045 = qcar(v0045);
    v0046 = v0045;
    goto v0066;

v0063:
    v0045 = qvalue(elt(env, 2)); /* t */
    goto v0064;

v0058:
    v0045 = stack[-3];
    v0045 = qcar(v0045);
    v0045 = Lconsp(nil, v0045);
    env = stack[-5];
    if (v0045 == nil) goto v0069;
    v0045 = stack[-3];
    v0045 = qcar(v0045);
    v0045 = qcar(v0045);
    v0046 = v0045;
    goto v0059;

v0069:
    v0045 = stack[-3];
    v0045 = qcar(v0045);
    v0046 = v0045;
    goto v0059;

v0056:
    v0045 = qvalue(elt(env, 2)); /* t */
    goto v0057;

v0054:
    v0046 = stack[-2];
    v0046 = qcar(v0046);
    fn = elt(env, 18); /* quotfx1 */
    v0045 = (*qfn2(fn))(qenv(fn), v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-5];
    stack[0] = v0045;
    goto v0055;

v0052:
    v0046 = qvalue(elt(env, 2)); /* t */
    goto v0053;

v0049:
    v0046 = stack[-3];
    v0045 = elt(env, 1); /* true */
    if (v0046 == v0045) goto v0070;
    v0046 = stack[-3];
    v0045 = elt(env, 3); /* false */
    v0045 = (v0046 == v0045 ? lisp_true : nil);
    goto v0071;

v0071:
    if (v0045 == nil) goto v0072;
    v0045 = stack[-3];
    v0046 = v0045;
    goto v0073;

v0073:
    v0045 = elt(env, 4); /* (leq greaterp geq lessp) */
    v0045 = Lmemq(nil, v0046, v0045);
    v0045 = (v0045 == nil ? lisp_true : nil);
    goto v0050;

v0072:
    v0045 = stack[-3];
    v0045 = qcar(v0045);
    v0045 = Lconsp(nil, v0045);
    env = stack[-5];
    if (v0045 == nil) goto v0074;
    v0045 = stack[-3];
    v0045 = qcar(v0045);
    v0045 = qcar(v0045);
    v0046 = v0045;
    goto v0073;

v0074:
    v0045 = stack[-3];
    v0045 = qcar(v0045);
    v0046 = v0045;
    goto v0073;

v0070:
    v0045 = qvalue(elt(env, 2)); /* t */
    goto v0071;

v0047:
    v0045 = qvalue(elt(env, 2)); /* t */
    goto v0048;
/* error exit handlers */
v0051:
    popv(6);
    return nil;
}



/* Code for ctx_union */

static Lisp_Object CC_ctx_union(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0075)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0029;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ctx_union");
#endif
    if (stack >= stacklimit)
    {
        push2(v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0075);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0075;
    stack[-3] = v0000;
/* end of prologue */
    stack[-4] = nil;
    v0087 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* setkorder */
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    stack[0] = v0087;
    v0087 = stack[0];
    fn = elt(env, 3); /* setkorder */
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    v0087 = stack[-3];
    fn = elt(env, 4); /* ctx_ial */
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    stack[-3] = v0087;
    v0087 = stack[-2];
    fn = elt(env, 4); /* ctx_ial */
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    stack[-2] = v0087;
    v0087 = stack[0];
    stack[-1] = v0087;
    goto v0089;

v0089:
    v0087 = stack[-1];
    if (v0087 == nil) goto v0090;
    v0087 = stack[-1];
    v0087 = qcar(v0087);
    stack[0] = v0087;
    v0087 = stack[-3];
    if (v0087 == nil) goto v0035;
    v0087 = stack[-3];
    v0087 = qcar(v0087);
    v0029 = qcar(v0087);
    v0087 = stack[0];
    v0087 = (v0029 == v0087 ? lisp_true : nil);
    goto v0042;

v0042:
    if (v0087 == nil) goto v0091;
    v0087 = stack[-3];
    v0029 = qcar(v0087);
    v0087 = stack[-4];
    v0087 = cons(v0029, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    stack[-4] = v0087;
    v0087 = stack[-3];
    v0087 = qcdr(v0087);
    stack[-3] = v0087;
    v0087 = stack[-2];
    if (v0087 == nil) goto v0092;
    v0087 = stack[-2];
    v0087 = qcar(v0087);
    v0029 = qcar(v0087);
    v0087 = stack[0];
    if (!(v0029 == v0087)) goto v0092;
    v0087 = stack[-2];
    v0087 = qcdr(v0087);
    stack[-2] = v0087;
    goto v0092;

v0092:
    v0087 = stack[-1];
    v0087 = qcdr(v0087);
    stack[-1] = v0087;
    goto v0089;

v0091:
    v0087 = stack[-2];
    if (v0087 == nil) goto v0093;
    v0087 = stack[-2];
    v0087 = qcar(v0087);
    v0029 = qcar(v0087);
    v0087 = stack[0];
    v0087 = (v0029 == v0087 ? lisp_true : nil);
    goto v0094;

v0094:
    if (v0087 == nil) goto v0092;
    v0087 = stack[-2];
    v0029 = qcar(v0087);
    v0087 = stack[-4];
    v0087 = cons(v0029, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    stack[-4] = v0087;
    v0087 = stack[-2];
    v0087 = qcdr(v0087);
    stack[-2] = v0087;
    goto v0092;

v0093:
    v0087 = qvalue(elt(env, 1)); /* nil */
    goto v0094;

v0035:
    v0087 = qvalue(elt(env, 1)); /* nil */
    goto v0042;

v0090:
    v0087 = stack[-3];
    if (!(v0087 == nil)) goto v0053;
    v0087 = stack[-2];
    if (!(v0087 == nil)) goto v0053;

v0031:
    v0087 = stack[-4];
    v0087 = Lnreverse(nil, v0087);
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 5); /* ctx_fromial */
        return (*qfn1(fn))(qenv(fn), v0087);
    }

v0053:
    v0087 = elt(env, 2); /* "***** ctx_union: idorder not complete" */
    v0087 = Lprinc(nil, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    v0087 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    goto v0031;
/* error exit handlers */
v0088:
    popv(6);
    return nil;
}



/* Code for numir */

static Lisp_Object MS_CDECL CC_numir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0066, v0122, v0123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "numir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numir");
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
    push2(nil, nil);
/* end of prologue */
    v0122 = qvalue(elt(env, 1)); /* atts */
    v0066 = elt(env, 2); /* name */
    fn = elt(env, 12); /* find */
    v0066 = (*qfn2(fn))(qenv(fn), v0122, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-7];
    v0066 = Lintern(nil, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-7];
    stack[-1] = v0066;
    fn = elt(env, 13); /* lex */
    v0066 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-7];
    fn = elt(env, 14); /* omobj */
    v0066 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-7];
    stack[0] = v0066;
    fn = elt(env, 13); /* lex */
    v0066 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-7];
    fn = elt(env, 14); /* omobj */
    v0066 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-7];
    v0123 = stack[-1];
    v0122 = elt(env, 3); /* complex_cartesian */
    if (!(v0123 == v0122)) goto v0125;
    v0122 = stack[0];
    if (symbolp(v0122)) goto v0126;
    v0122 = v0066;
    if (!(symbolp(v0122))) goto v0125;

v0126:
    stack[-4] = elt(env, 4); /* plus */
    stack[-3] = qvalue(elt(env, 5)); /* nil */
    stack[-2] = stack[0];
    stack[-1] = elt(env, 6); /* times */
    stack[0] = qvalue(elt(env, 5)); /* nil */
    v0123 = v0066;
    v0122 = elt(env, 7); /* !&imaginaryi!; */
    v0066 = qvalue(elt(env, 5)); /* nil */
    v0066 = list2star(v0123, v0122, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-7];
    v0122 = list2star(stack[-1], stack[0], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-7];
    v0066 = qvalue(elt(env, 5)); /* nil */
    v0066 = list2star(stack[-2], v0122, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    {
        Lisp_Object v0060 = stack[-4];
        Lisp_Object v0127 = stack[-3];
        popv(8);
        return list2star(v0060, v0127, v0066);
    }

v0125:
    v0123 = stack[-1];
    v0122 = elt(env, 8); /* complex_polar */
    if (!(v0123 == v0122)) goto v0128;
    v0122 = stack[0];
    if (symbolp(v0122)) goto v0093;
    v0122 = v0066;
    if (!(symbolp(v0122))) goto v0128;

v0093:
    stack[-6] = elt(env, 6); /* times */
    stack[-5] = qvalue(elt(env, 5)); /* nil */
    stack[-4] = stack[0];
    stack[-3] = elt(env, 9); /* exp */
    stack[-2] = qvalue(elt(env, 5)); /* nil */
    stack[-1] = elt(env, 6); /* times */
    stack[0] = qvalue(elt(env, 5)); /* nil */
    v0123 = v0066;
    v0122 = elt(env, 7); /* !&imaginaryi!; */
    v0066 = qvalue(elt(env, 5)); /* nil */
    v0066 = list2star(v0123, v0122, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-7];
    v0066 = list2star(stack[-1], stack[0], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-7];
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-7];
    v0122 = list2star(stack[-3], stack[-2], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-7];
    v0066 = qvalue(elt(env, 5)); /* nil */
    v0066 = list2star(stack[-4], v0122, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    {
        Lisp_Object v0129 = stack[-6];
        Lisp_Object v0130 = stack[-5];
        popv(8);
        return list2star(v0129, v0130, v0066);
    }

v0128:
    v0123 = stack[-1];
    v0122 = elt(env, 10); /* rational */
    if (!(v0123 == v0122)) goto v0131;
    v0122 = stack[0];
    if (symbolp(v0122)) goto v0024;
    v0122 = v0066;
    if (!(symbolp(v0122))) goto v0131;

v0024:
    stack[-2] = elt(env, 11); /* divide */
    stack[-1] = qvalue(elt(env, 5)); /* nil */
    v0123 = stack[0];
    v0122 = v0066;
    v0066 = qvalue(elt(env, 5)); /* nil */
    v0066 = list2star(v0123, v0122, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    {
        Lisp_Object v0132 = stack[-2];
        Lisp_Object v0016 = stack[-1];
        popv(8);
        return list2star(v0132, v0016, v0066);
    }

v0131:
    stack[-2] = stack[-1];
    stack[-1] = qvalue(elt(env, 5)); /* nil */
    v0123 = stack[0];
    v0122 = v0066;
    v0066 = qvalue(elt(env, 5)); /* nil */
    v0066 = list2star(v0123, v0122, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    {
        Lisp_Object v0015 = stack[-2];
        Lisp_Object v0133 = stack[-1];
        popv(8);
        return list2star(v0015, v0133, v0066);
    }
/* error exit handlers */
v0124:
    popv(8);
    return nil;
}



/* Code for i2crn!* */

static Lisp_Object CC_i2crnH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0137, v0082;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for i2crn*");
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
    v0137 = v0000;
/* end of prologue */
    stack[-1] = elt(env, 1); /* !:crn!: */
    v0082 = v0137;
    v0137 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0082, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-2];
    v0082 = (Lisp_Object)1; /* 0 */
    v0137 = (Lisp_Object)17; /* 1 */
    v0137 = cons(v0082, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    {
        Lisp_Object v0091 = stack[-1];
        Lisp_Object v0041 = stack[0];
        popv(3);
        return list2star(v0091, v0041, v0137);
    }
/* error exit handlers */
v0138:
    popv(3);
    return nil;
}



/* Code for solvealgtrig01 */

static Lisp_Object CC_solvealgtrig01(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0075)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0141, v0142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for solvealgtrig01");
#endif
    if (stack >= stacklimit)
    {
        push2(v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0075);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0075;
    stack[-1] = v0000;
/* end of prologue */

v0143:
    v0141 = stack[-1];
    if (!consp(v0141)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0141 = stack[-1];
    v0142 = qcar(v0141);
    v0141 = elt(env, 1); /* (sin cos tan cot sinh cosh tanh coth) */
    v0141 = Lmemq(nil, v0142, v0141);
    if (v0141 == nil) goto v0086;
    v0141 = stack[-1];
    v0141 = qcdr(v0141);
    v0141 = qcar(v0141);
    fn = elt(env, 2); /* constant_exprp */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    if (!(v0141 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0141 = stack[-1];
    v0141 = qcdr(v0141);
    v0141 = qcar(v0141);
    v0142 = ncons(v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    v0141 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* union */
        return (*qfn2(fn))(qenv(fn), v0142, v0141);
    }

v0086:
    v0141 = stack[-1];
    v0141 = qcdr(v0141);
    stack[-2] = v0141;
    v0141 = stack[-1];
    v0142 = qcar(v0141);
    v0141 = stack[0];
    v0141 = CC_solvealgtrig01(env, v0142, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-3];
    stack[0] = v0141;
    v0141 = stack[-2];
    stack[-1] = v0141;
    goto v0143;
/* error exit handlers */
v0144:
    popv(4);
    return nil;
}



/* Code for add_item */

static Lisp_Object CC_add_item(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0075)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0142, v0148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add_item");
#endif
    if (stack >= stacklimit)
    {
        push2(v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0075);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0075;
    stack[-1] = v0000;
/* end of prologue */

v0149:
    v0142 = stack[0];
    v0142 = qcdr(v0142);
    if (v0142 == nil) goto v0150;
    v0142 = stack[0];
    v0142 = qcar(v0142);
    v0148 = qcar(v0142);
    v0142 = stack[-1];
    v0142 = qcar(v0142);
    fn = elt(env, 3); /* monordp */
    v0142 = (*qfn2(fn))(qenv(fn), v0148, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    if (v0142 == nil) goto v0151;
    v0142 = stack[0];
    v0142 = qcdr(v0142);
    v0142 = qcar(v0142);
    stack[0] = v0142;
    goto v0149;

v0151:
    v0142 = stack[0];
    v0142 = qcdr(v0142);
    v0142 = qcdr(v0142);
    stack[0] = v0142;
    goto v0149;

v0150:
    v0148 = stack[0];
    v0142 = stack[-1];
    fn = elt(env, 4); /* setcar */
    v0142 = (*qfn2(fn))(qenv(fn), v0148, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    stack[-2] = stack[0];
    stack[-1] = elt(env, 1); /* !*xset!* */
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v0142 = elt(env, 1); /* !*xset!* */
    v0142 = ncons(v0142);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    v0142 = acons(stack[-1], stack[0], v0142);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    fn = elt(env, 5); /* setcdr */
    v0142 = (*qfn2(fn))(qenv(fn), stack[-2], v0142);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-3];
    v0142 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0142); }
/* error exit handlers */
v0118:
    popv(4);
    return nil;
}



/* Code for gbftimes */

static Lisp_Object CC_gbftimes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0075)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036, v0037, v0154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gbftimes");
#endif
    if (stack >= stacklimit)
    {
        push2(v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0075);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0037 = v0075;
    v0154 = v0000;
/* end of prologue */
    v0036 = v0154;
    v0036 = qcar(v0036);
    stack[-4] = v0036;
    v0036 = v0154;
    v0036 = qcdr(v0036);
    stack[-3] = v0036;
    v0036 = v0037;
    v0036 = qcar(v0036);
    stack[-2] = v0036;
    v0036 = v0037;
    v0036 = qcdr(v0036);
    stack[-1] = v0036;
    v0037 = stack[-4];
    v0036 = stack[-2];
    fn = elt(env, 1); /* csl_timbf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-5];
    v0037 = stack[-3];
    v0036 = stack[-1];
    fn = elt(env, 1); /* csl_timbf */
    v0036 = (*qfn2(fn))(qenv(fn), v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-5];
    fn = elt(env, 2); /* difbf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0036);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-5];
    v0037 = stack[-4];
    v0036 = stack[-1];
    fn = elt(env, 1); /* csl_timbf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-5];
    v0037 = stack[-3];
    v0036 = stack[-2];
    fn = elt(env, 1); /* csl_timbf */
    v0036 = (*qfn2(fn))(qenv(fn), v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-5];
    fn = elt(env, 3); /* plubf */
    v0036 = (*qfn2(fn))(qenv(fn), stack[-1], v0036);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    {
        Lisp_Object v0120 = stack[0];
        popv(6);
        return cons(v0120, v0036);
    }
/* error exit handlers */
v0155:
    popv(6);
    return nil;
}



/* Code for kernelp */

static Lisp_Object CC_kernelp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0085;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernelp");
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
    v0033 = stack[0];
    if (v0033 == nil) goto v0157;
    v0033 = stack[0];
    fn = elt(env, 4); /* domain!*p */
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-1];
    goto v0158;

v0158:
    if (v0033 == nil) goto v0149;
    v0033 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0033); }

v0149:
    v0033 = stack[0];
    if (symbolp(v0033)) goto v0090;
    v0033 = stack[0];
    fn = elt(env, 5); /* listp */
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-1];
    if (v0033 == nil) goto v0073;
    v0033 = stack[0];
    v0033 = qcar(v0033);
    if (!(symbolp(v0033))) goto v0073;
    v0033 = stack[0];
    v0085 = qcar(v0033);
    v0033 = elt(env, 3); /* (!*sq set setq plus minus difference times quotient) 
*/
    v0033 = Lmemq(nil, v0085, v0033);
    if (!(v0033 == nil)) goto v0073;
    v0033 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0033); }

v0073:
    v0033 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0033); }

v0090:
    v0033 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0033); }

v0157:
    v0033 = qvalue(elt(env, 1)); /* t */
    goto v0158;
/* error exit handlers */
v0072:
    popv(2);
    return nil;
}



/* Code for diff_vertex */

static Lisp_Object CC_diff_vertex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0075)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0159, v0160, v0161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff_vertex");
#endif
    if (stack >= stacklimit)
    {
        push2(v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0075);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0075;
    stack[-1] = v0000;
/* end of prologue */
    v0161 = nil;
    goto v0143;

v0143:
    v0159 = stack[-1];
    if (v0159 == nil) goto v0162;
    v0159 = stack[-1];
    v0159 = qcar(v0159);
    v0160 = qcar(v0159);
    v0159 = stack[0];
    v0159 = Lassoc(nil, v0160, v0159);
    if (v0159 == nil) goto v0153;
    v0159 = stack[-1];
    v0159 = qcar(v0159);
    v0160 = qcar(v0159);
    v0159 = qvalue(elt(env, 1)); /* !_0edge */
    v0159 = qcar(v0159);
    if (v0160 == v0159) goto v0153;
    v0159 = stack[-1];
    v0159 = qcdr(v0159);
    stack[-1] = v0159;
    goto v0143;

v0153:
    v0159 = stack[-1];
    v0159 = qcar(v0159);
    v0160 = v0161;
    v0159 = cons(v0159, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    v0161 = v0159;
    v0159 = stack[-1];
    v0159 = qcdr(v0159);
    stack[-1] = v0159;
    goto v0143;

v0162:
    v0159 = v0161;
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0159);
    }
/* error exit handlers */
v0038:
    popv(3);
    return nil;
}



/* Code for setmatelem */

static Lisp_Object CC_setmatelem(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0075)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0169, v0020, v0170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setmatelem");
#endif
    if (stack >= stacklimit)
    {
        push2(v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0075);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0075;
    stack[-2] = v0000;
/* end of prologue */
    v0169 = stack[-2];
    v0020 = Llength(nil, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-4];
    v0169 = (Lisp_Object)49; /* 3 */
    if (v0020 == v0169) goto v0082;
    v0020 = stack[-2];
    v0169 = elt(env, 1); /* "matrix element" */
    fn = elt(env, 12); /* typerr */
    v0169 = (*qfn2(fn))(qenv(fn), v0020, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-4];
    goto v0082;

v0082:
    v0169 = stack[-2];
    v0020 = qcar(v0169);
    v0169 = elt(env, 2); /* avalue */
    v0169 = get(v0020, v0169);
    env = stack[-4];
    stack[-3] = v0169;
    v0169 = stack[-3];
    if (v0169 == nil) goto v0171;
    v0169 = stack[-3];
    v0020 = qcar(v0169);
    v0169 = elt(env, 4); /* matrix */
    v0169 = (v0020 == v0169 ? lisp_true : nil);
    v0169 = (v0169 == nil ? lisp_true : nil);
    goto v0073;

v0073:
    if (v0169 == nil) goto v0172;
    v0169 = stack[-2];
    v0020 = qcar(v0169);
    v0169 = elt(env, 5); /* "matrix" */
    fn = elt(env, 12); /* typerr */
    v0169 = (*qfn2(fn))(qenv(fn), v0020, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-4];
    goto v0146;

v0146:
    v0169 = stack[-2];
    v0169 = qcdr(v0169);
    v0169 = qcar(v0169);
    fn = elt(env, 13); /* reval_without_mod */
    v0169 = (*qfn1(fn))(qenv(fn), v0169);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-4];
    stack[0] = v0169;
    v0169 = stack[0];
    v0169 = integerp(v0169);
    if (v0169 == nil) goto v0028;
    v0020 = stack[0];
    v0169 = (Lisp_Object)1; /* 0 */
    v0169 = (Lisp_Object)lesseq2(v0020, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    v0169 = v0169 ? lisp_true : nil;
    env = stack[-4];
    goto v0173;

v0173:
    if (v0169 == nil) goto v0114;
    v0020 = stack[0];
    v0169 = elt(env, 11); /* "positive integer" */
    fn = elt(env, 12); /* typerr */
    v0169 = (*qfn2(fn))(qenv(fn), v0020, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-4];
    goto v0114;

v0114:
    v0169 = stack[-3];
    v0020 = qcdr(v0169);
    v0169 = stack[0];
    fn = elt(env, 14); /* pnth */
    v0169 = (*qfn2(fn))(qenv(fn), v0020, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-4];
    v0169 = qcar(v0169);
    stack[-3] = v0169;
    v0169 = stack[-2];
    v0169 = qcdr(v0169);
    v0169 = qcdr(v0169);
    v0169 = qcar(v0169);
    fn = elt(env, 13); /* reval_without_mod */
    v0169 = (*qfn1(fn))(qenv(fn), v0169);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-4];
    stack[0] = v0169;
    v0169 = stack[0];
    v0169 = integerp(v0169);
    if (v0169 == nil) goto v0019;
    v0020 = stack[0];
    v0169 = (Lisp_Object)1; /* 0 */
    v0169 = (Lisp_Object)lesseq2(v0020, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    v0169 = v0169 ? lisp_true : nil;
    env = stack[-4];
    goto v0174;

v0174:
    if (v0169 == nil) goto v0175;
    v0020 = stack[0];
    v0169 = elt(env, 11); /* "positive integer" */
    fn = elt(env, 12); /* typerr */
    v0169 = (*qfn2(fn))(qenv(fn), v0020, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-4];
    goto v0175;

v0175:
    v0020 = stack[-3];
    v0169 = stack[0];
    fn = elt(env, 14); /* pnth */
    v0020 = (*qfn2(fn))(qenv(fn), v0020, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    v0169 = stack[-1];
        popv(5);
        return Lrplaca(nil, v0020, v0169);

v0019:
    v0169 = qvalue(elt(env, 3)); /* t */
    goto v0174;

v0028:
    v0169 = qvalue(elt(env, 3)); /* t */
    goto v0173;

v0172:
    v0169 = stack[-3];
    v0169 = qcdr(v0169);
    v0020 = qcar(v0169);
    stack[-3] = v0020;
    v0169 = elt(env, 6); /* mat */
    if (!consp(v0020)) goto v0176;
    v0020 = qcar(v0020);
    if (v0020 == v0169) goto v0146;
    else goto v0176;

v0176:
    v0170 = elt(env, 7); /* "Matrix" */
    v0169 = stack[-2];
    v0020 = qcar(v0169);
    v0169 = elt(env, 8); /* "not set" */
    v0169 = list3(v0170, v0020, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-4];
    v0020 = v0169;
    v0169 = v0020;
    qvalue(elt(env, 9)) = v0169; /* errmsg!* */
    v0169 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v0169 == nil)) goto v0177;
    v0169 = v0020;
    fn = elt(env, 15); /* lprie */
    v0169 = (*qfn1(fn))(qenv(fn), v0169);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-4];
    goto v0177;

v0177:
    v0169 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-4];
    goto v0146;

v0171:
    v0169 = qvalue(elt(env, 3)); /* t */
    goto v0073;
/* error exit handlers */
v0097:
    popv(5);
    return nil;
}



/* Code for rfirst */

static Lisp_Object CC_rfirst(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0180, v0155, v0120, v0119, v0083;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rfirst");
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
    v0180 = stack[0];
    v0180 = qcar(v0180);
    stack[0] = v0180;
    v0180 = stack[0];
    fn = elt(env, 7); /* listeval0 */
    v0155 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-2];
    stack[-1] = v0155;
    v0180 = elt(env, 1); /* list */
    if (!consp(v0155)) goto v0135;
    v0155 = qcar(v0155);
    if (!(v0155 == v0180)) goto v0135;
    v0180 = qvalue(elt(env, 2)); /* nil */
    goto v0182;

v0182:
    if (v0180 == nil) goto v0157;
    v0155 = stack[0];
    v0180 = elt(env, 3); /* "list" */
    fn = elt(env, 8); /* typerr */
    v0180 = (*qfn2(fn))(qenv(fn), v0155, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-2];
    goto v0157;

v0157:
    v0180 = stack[-1];
    v0180 = qcdr(v0180);
    if (v0180 == nil) goto v0049;
    v0180 = stack[-1];
    v0180 = qcdr(v0180);
    v0180 = qcar(v0180);
    {
        popv(3);
        fn = elt(env, 9); /* reval */
        return (*qfn1(fn))(qenv(fn), v0180);
    }

v0049:
    v0083 = elt(env, 4); /* "Expression" */
    v0119 = stack[0];
    v0120 = elt(env, 5); /* "does not have part" */
    v0155 = (Lisp_Object)17; /* 1 */
    v0180 = qvalue(elt(env, 6)); /* t */
    fn = elt(env, 10); /* msgpri */
    v0180 = (*qfnn(fn))(qenv(fn), 5, v0083, v0119, v0120, v0155, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    v0180 = nil;
    { popv(3); return onevalue(v0180); }

v0135:
    v0180 = stack[0];
    fn = elt(env, 11); /* aeval */
    v0155 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-2];
    stack[-1] = v0155;
    v0180 = elt(env, 1); /* list */
    v0180 = Leqcar(nil, v0155, v0180);
    env = stack[-2];
    v0180 = (v0180 == nil ? lisp_true : nil);
    goto v0182;
/* error exit handlers */
v0181:
    popv(3);
    return nil;
}



/* Code for bc_from_a */

static Lisp_Object CC_bc_from_a(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_from_a");
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
    v0143 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v0143 = (*qfn1(fn))(qenv(fn), v0143);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[0];
    v0143 = qcar(v0143);
    {
        popv(1);
        fn = elt(env, 2); /* bc!=simp */
        return (*qfn1(fn))(qenv(fn), v0143);
    }
/* error exit handlers */
v0158:
    popv(1);
    return nil;
}



/* Code for st_sorttree1 */

static Lisp_Object MS_CDECL CC_st_sorttree1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0075,
                         Lisp_Object v0008, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0253, v0254, v0255;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "st_sorttree1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_sorttree1");
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0075,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v0008;
    stack[-9] = v0075;
    stack[-10] = v0000;
/* end of prologue */
    stack[-11] = nil;
    stack[-7] = nil;
    stack[-1] = nil;
    v0253 = (Lisp_Object)17; /* 1 */
    stack[-6] = v0253;
    v0253 = stack[-10];
    v0253 = qcdr(v0253);
    v0253 = qcar(v0253);
    if (is_number(v0253)) goto v0044;
    v0253 = stack[-10];
    v0254 = qcar(v0253);
    v0253 = elt(env, 1); /* !* */
    if (v0254 == v0253) goto v0256;
    v0253 = stack[-10];
    v0253 = qcdr(v0253);
    stack[0] = v0253;
    goto v0257;

v0257:
    v0253 = stack[0];
    if (v0253 == nil) goto v0258;
    v0253 = stack[0];
    v0253 = qcar(v0253);
    v0255 = v0253;
    v0254 = stack[-6];
    v0253 = (Lisp_Object)1; /* 0 */
    if (v0254 == v0253) goto v0259;
    v0254 = stack[-9];
    v0253 = stack[-8];
    v0253 = CC_st_sorttree1(env, 3, v0255, v0254, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    stack[-2] = v0253;
    v0254 = stack[-6];
    v0253 = stack[-2];
    v0253 = qcdr(v0253);
    v0253 = qcar(v0253);
    v0253 = times2(v0254, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    stack[-6] = v0253;
    v0253 = stack[-2];
    v0253 = qcdr(v0253);
    v0255 = qcdr(v0253);
    v0253 = stack[-2];
    v0254 = qcar(v0253);
    v0253 = stack[-1];
    v0253 = acons(v0255, v0254, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    stack[-1] = v0253;
    goto v0259;

v0259:
    v0253 = stack[0];
    v0253 = qcdr(v0253);
    stack[0] = v0253;
    goto v0257;

v0258:
    v0254 = stack[-6];
    v0253 = (Lisp_Object)1; /* 0 */
    if (v0254 == v0253) goto v0261;
    v0253 = stack[-10];
    v0254 = qcar(v0253);
    v0253 = elt(env, 3); /* !+ */
    if (v0254 == v0253) goto v0262;
    v0254 = stack[-1];
    v0253 = stack[-8];
    fn = elt(env, 4); /* cdr_signsort */
    v0253 = (*qfn2(fn))(qenv(fn), v0254, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    stack[-1] = v0253;
    v0253 = stack[-1];
    v0254 = qcar(v0253);
    v0253 = (Lisp_Object)1; /* 0 */
    if (v0254 == v0253) goto v0263;
    v0254 = stack[-6];
    v0253 = stack[-1];
    v0253 = qcar(v0253);
    v0253 = times2(v0254, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    stack[-6] = v0253;
    v0253 = stack[-1];
    v0253 = qcdr(v0253);
    stack[-1] = v0253;
    goto v0264;

v0264:
    v0253 = stack[-1];
    if (v0253 == nil) goto v0265;
    v0253 = stack[-1];
    v0253 = qcar(v0253);
    v0254 = qcar(v0253);
    v0253 = stack[-7];
    v0253 = cons(v0254, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    stack[-7] = v0253;
    v0253 = stack[-1];
    v0253 = qcar(v0253);
    v0254 = qcdr(v0253);
    v0253 = stack[-11];
    v0253 = cons(v0254, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    stack[-11] = v0253;
    v0253 = stack[-1];
    v0253 = qcdr(v0253);
    stack[-1] = v0253;
    goto v0264;

v0265:
    v0253 = stack[-10];
    stack[0] = qcar(v0253);
    v0253 = stack[-7];
    v0253 = Lreverse(nil, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    v0253 = cons(stack[0], v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    stack[-7] = v0253;
    v0253 = stack[-11];
    v0253 = Lreverse(nil, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    stack[-11] = v0253;
    v0255 = stack[-11];
    v0254 = stack[-6];
    v0253 = stack[-7];
    popv(13);
    return list2star(v0255, v0254, v0253);

v0263:
    v0254 = qvalue(elt(env, 2)); /* nil */
    v0253 = (Lisp_Object)1; /* 0 */
    v0255 = qvalue(elt(env, 2)); /* nil */
    popv(13);
    return list2star(v0254, v0253, v0255);

v0262:
    v0254 = stack[-1];
    v0253 = stack[-8];
    fn = elt(env, 5); /* cdr_sort */
    v0253 = (*qfn2(fn))(qenv(fn), v0254, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    stack[-1] = v0253;
    goto v0264;

v0261:
    v0254 = qvalue(elt(env, 2)); /* nil */
    v0253 = (Lisp_Object)1; /* 0 */
    v0255 = qvalue(elt(env, 2)); /* nil */
    popv(13);
    return list2star(v0254, v0253, v0255);

v0256:
    v0253 = stack[-10];
    v0253 = qcdr(v0253);
    stack[0] = v0253;
    goto v0104;

v0104:
    v0253 = stack[0];
    if (v0253 == nil) goto v0266;
    v0253 = stack[0];
    v0253 = qcar(v0253);
    v0255 = v0253;
    v0254 = stack[-6];
    v0253 = (Lisp_Object)1; /* 0 */
    if (v0254 == v0253) goto v0095;
    v0254 = stack[-9];
    v0253 = stack[-8];
    v0253 = CC_st_sorttree1(env, 3, v0255, v0254, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    stack[-2] = v0253;
    v0254 = stack[-6];
    v0253 = stack[-2];
    v0253 = qcdr(v0253);
    v0253 = qcar(v0253);
    v0253 = times2(v0254, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    stack[-6] = v0253;
    v0253 = stack[-2];
    v0254 = qcar(v0253);
    v0253 = stack[-11];
    v0253 = cons(v0254, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    stack[-11] = v0253;
    v0253 = stack[-2];
    v0253 = qcdr(v0253);
    v0254 = qcdr(v0253);
    v0253 = stack[-7];
    v0253 = cons(v0254, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    stack[-7] = v0253;
    goto v0095;

v0095:
    v0253 = stack[0];
    v0253 = qcdr(v0253);
    stack[0] = v0253;
    goto v0104;

v0266:
    v0254 = stack[-6];
    v0253 = (Lisp_Object)1; /* 0 */
    if (v0254 == v0253) goto v0267;
    v0253 = stack[-7];
    v0253 = Lreverse(nil, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    stack[-7] = v0253;
    v0253 = stack[-11];
    v0253 = Lreverse(nil, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    stack[-11] = v0253;
    stack[0] = stack[-11];
    stack[-1] = stack[-6];
    v0254 = elt(env, 1); /* !* */
    v0253 = stack[-7];
    v0253 = cons(v0254, v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    {
        Lisp_Object v0268 = stack[0];
        Lisp_Object v0269 = stack[-1];
        popv(13);
        return list2star(v0268, v0269, v0253);
    }

v0267:
    v0254 = qvalue(elt(env, 2)); /* nil */
    v0253 = (Lisp_Object)1; /* 0 */
    v0255 = qvalue(elt(env, 2)); /* nil */
    popv(13);
    return list2star(v0254, v0253, v0255);

v0044:
    v0253 = stack[-10];
    v0254 = qcar(v0253);
    v0253 = elt(env, 1); /* !* */
    if (v0254 == v0253) goto v0139;
    v0253 = stack[-10];
    v0253 = qcdr(v0253);
    stack[-5] = v0253;
    v0253 = stack[-5];
    if (v0253 == nil) goto v0106;
    v0253 = stack[-5];
    v0253 = qcar(v0253);
    stack[-1] = v0253;
    stack[0] = stack[-9];
    v0253 = sub1(v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    v0253 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0253/(16/CELL)));
    v0253 = cons(stack[-1], v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    v0253 = ncons(v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    stack[-3] = v0253;
    stack[-4] = v0253;
    goto v0001;

v0001:
    v0253 = stack[-5];
    v0253 = qcdr(v0253);
    stack[-5] = v0253;
    v0253 = stack[-5];
    if (v0253 == nil) goto v0114;
    stack[-2] = stack[-3];
    v0253 = stack[-5];
    v0253 = qcar(v0253);
    stack[-1] = v0253;
    stack[0] = stack[-9];
    v0253 = sub1(v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    v0253 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0253/(16/CELL)));
    v0253 = cons(stack[-1], v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    v0253 = ncons(v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    v0253 = Lrplacd(nil, stack[-2], v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    v0253 = stack[-3];
    v0253 = qcdr(v0253);
    stack[-3] = v0253;
    goto v0001;

v0114:
    v0253 = stack[-4];
    goto v0002;

v0002:
    stack[-1] = v0253;
    goto v0258;

v0106:
    v0253 = qvalue(elt(env, 2)); /* nil */
    goto v0002;

v0139:
    v0253 = stack[-10];
    v0253 = qcdr(v0253);
    stack[-4] = v0253;
    v0253 = stack[-4];
    if (v0253 == nil) goto v0073;
    v0253 = stack[-4];
    v0253 = qcar(v0253);
    stack[0] = stack[-9];
    v0253 = sub1(v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    v0253 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0253/(16/CELL)));
    v0253 = ncons(v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    stack[-2] = v0253;
    stack[-3] = v0253;
    goto v0145;

v0145:
    v0253 = stack[-4];
    v0253 = qcdr(v0253);
    stack[-4] = v0253;
    v0253 = stack[-4];
    if (v0253 == nil) goto v0148;
    stack[-1] = stack[-2];
    v0253 = stack[-4];
    v0253 = qcar(v0253);
    stack[0] = stack[-9];
    v0253 = sub1(v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    v0253 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0253/(16/CELL)));
    v0253 = ncons(v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    v0253 = Lrplacd(nil, stack[-1], v0253);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-12];
    v0253 = stack[-2];
    v0253 = qcdr(v0253);
    stack[-2] = v0253;
    goto v0145;

v0148:
    v0253 = stack[-3];
    goto v0147;

v0147:
    stack[-11] = v0253;
    v0255 = stack[-11];
    v0254 = (Lisp_Object)17; /* 1 */
    v0253 = stack[-10];
    popv(13);
    return list2star(v0255, v0254, v0253);

v0073:
    v0253 = qvalue(elt(env, 2)); /* nil */
    goto v0147;
/* error exit handlers */
v0260:
    popv(13);
    return nil;
}



/* Code for ofsf_bestgaussp */

static Lisp_Object CC_ofsf_bestgaussp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0094, v0168;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_bestgaussp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0168 = v0000;
/* end of prologue */
    v0079 = v0168;
    v0094 = qcar(v0079);
    v0079 = elt(env, 1); /* failed */
    if (v0094 == v0079) goto v0252;
    v0079 = v0168;
    v0094 = qcar(v0079);
    v0079 = elt(env, 2); /* gignore */
    if (v0094 == v0079) goto v0074;
    v0079 = v0168;
    v0079 = qcar(v0079);
    v0079 = qcdr(v0079);
    v0094 = qcar(v0079);
    v0079 = elt(env, 3); /* lin */
    if (v0094 == v0079) goto v0033;
    v0079 = qvalue(elt(env, 5)); /* nil */
    return onevalue(v0079);

v0033:
    v0079 = v0168;
    v0079 = qcar(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0094 = qcar(v0079);
    v0079 = elt(env, 4); /* con */
    if (v0094 == v0079) goto v0171;
    v0079 = qvalue(elt(env, 5)); /* nil */
    return onevalue(v0079);

v0171:
    v0079 = v0168;
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    v0079 = qcdr(v0079);
    if (v0079 == nil) goto v0039;
    v0079 = qvalue(elt(env, 5)); /* nil */
    return onevalue(v0079);

v0039:
    v0079 = v0168;
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    v0079 = qcar(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0079 = (v0079 == nil ? lisp_true : nil);
    return onevalue(v0079);

v0074:
    v0079 = qvalue(elt(env, 5)); /* nil */
    return onevalue(v0079);

v0252:
    v0079 = qvalue(elt(env, 5)); /* nil */
    return onevalue(v0079);
}



/* Code for merge_lists */

static Lisp_Object CC_merge_lists(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0075)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0164, v0175;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for merge_lists");
#endif
    if (stack >= stacklimit)
    {
        push2(v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0075);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0075;
    stack[-5] = v0000;
/* end of prologue */
    stack[-6] = nil;
    stack[-3] = nil;
    stack[-1] = nil;
    v0164 = (Lisp_Object)17; /* 1 */
    stack[0] = v0164;
    v0164 = stack[-5];
    v0164 = Lreverse(nil, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-7];
    stack[-5] = v0164;
    v0164 = stack[-5];
    if (v0164 == nil) goto v0182;
    v0164 = stack[-5];
    v0164 = qcar(v0164);
    stack[-6] = v0164;
    goto v0050;

v0050:
    v0164 = stack[-4];
    if (v0164 == nil) goto v0182;
    v0164 = stack[-4];
    v0164 = qcar(v0164);
    stack[-2] = v0164;
    v0175 = stack[-6];
    v0164 = stack[-2];
    v0164 = (Lisp_Object)lessp2(v0175, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    v0164 = v0164 ? lisp_true : nil;
    env = stack[-7];
    if (!(v0164 == nil)) goto v0182;
    v0175 = stack[-2];
    v0164 = stack[-3];
    v0164 = cons(v0175, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-7];
    stack[-3] = v0164;
    v0164 = stack[-1];
    v0164 = (v0164 == nil ? lisp_true : nil);
    stack[-1] = v0164;
    v0164 = stack[-4];
    v0164 = qcdr(v0164);
    stack[-4] = v0164;
    goto v0050;

v0182:
    v0164 = stack[-5];
    if (v0164 == nil) goto v0250;
    v0164 = stack[-3];
    if (v0164 == nil) goto v0277;
    v0164 = stack[-3];
    v0164 = qcar(v0164);
    stack[-2] = v0164;
    v0175 = stack[-6];
    v0164 = stack[-2];
    if (equal(v0175, v0164)) goto v0108;
    v0164 = qvalue(elt(env, 1)); /* nil */
    goto v0278;

v0278:
    if (v0164 == nil) goto v0279;
    v0164 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v0164); }

v0279:
    v0175 = stack[-6];
    v0164 = stack[-2];
    v0164 = (Lisp_Object)greaterp2(v0175, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    v0164 = v0164 ? lisp_true : nil;
    env = stack[-7];
    if (v0164 == nil) goto v0088;
    v0175 = stack[-6];
    v0164 = stack[-4];
    v0164 = cons(v0175, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-7];
    stack[-4] = v0164;
    v0164 = stack[-5];
    v0164 = qcdr(v0164);
    stack[-5] = v0164;
    v0164 = stack[-1];
    if (v0164 == nil) goto v0056;
    v0175 = stack[-6];
    v0164 = (Lisp_Object)1; /* 0 */
    v0164 = (Lisp_Object)greaterp2(v0175, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    v0164 = v0164 ? lisp_true : nil;
    env = stack[-7];
    if (v0164 == nil) goto v0056;
    v0164 = stack[0];
    v0164 = negate(v0164);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-7];
    stack[0] = v0164;
    goto v0056;

v0056:
    v0164 = stack[-5];
    if (v0164 == nil) goto v0182;
    v0164 = stack[-5];
    v0164 = qcar(v0164);
    stack[-6] = v0164;
    goto v0182;

v0088:
    v0175 = stack[-2];
    v0164 = stack[-4];
    v0164 = cons(v0175, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-7];
    stack[-4] = v0164;
    v0164 = stack[-3];
    v0164 = qcdr(v0164);
    stack[-3] = v0164;
    v0164 = stack[-1];
    v0164 = (v0164 == nil ? lisp_true : nil);
    stack[-1] = v0164;
    goto v0182;

v0108:
    v0175 = stack[-6];
    v0164 = (Lisp_Object)1; /* 0 */
    v0164 = (Lisp_Object)greaterp2(v0175, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    v0164 = v0164 ? lisp_true : nil;
    env = stack[-7];
    goto v0278;

v0277:
    v0175 = stack[-5];
    v0164 = stack[-4];
    fn = elt(env, 2); /* reversip2 */
    v0164 = (*qfn2(fn))(qenv(fn), v0175, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    {
        Lisp_Object v0020 = stack[0];
        popv(8);
        return cons(v0020, v0164);
    }

v0250:
    v0175 = stack[-3];
    v0164 = stack[-4];
    fn = elt(env, 2); /* reversip2 */
    v0164 = (*qfn2(fn))(qenv(fn), v0175, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    {
        Lisp_Object v0170 = stack[0];
        popv(8);
        return cons(v0170, v0164);
    }
/* error exit handlers */
v0169:
    popv(8);
    return nil;
}



/* Code for replace!-nth */

static Lisp_Object MS_CDECL CC_replaceKnth(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0075,
                         Lisp_Object v0008, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070, v0152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "replace-nth");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replace-nth");
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0075,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0008;
    stack[-1] = v0075;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0182;

v0182:
    v0152 = stack[-1];
    v0070 = (Lisp_Object)17; /* 1 */
    if (v0152 == v0070) goto v0280;
    v0070 = stack[-2];
    v0152 = qcar(v0070);
    v0070 = stack[-3];
    v0070 = cons(v0152, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    stack[-3] = v0070;
    v0070 = stack[-2];
    v0070 = qcdr(v0070);
    stack[-2] = v0070;
    v0070 = stack[-1];
    v0070 = sub1(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    stack[-1] = v0070;
    goto v0182;

v0280:
    stack[-1] = stack[-3];
    v0152 = stack[0];
    v0070 = stack[-2];
    v0070 = qcdr(v0070);
    v0070 = cons(v0152, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    {
        Lisp_Object v0039 = stack[-1];
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0039, v0070);
    }
/* error exit handlers */
v0151:
    popv(5);
    return nil;
}



/* Code for get!*nr!*real!*irred!*reps */

static Lisp_Object CC_getHnrHrealHirredHreps(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0182, v0150;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*nr*real*irred*reps");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0182 = v0000;
/* end of prologue */
    v0150 = elt(env, 1); /* realrepnumber */
    return get(v0182, v0150);
}



/* Code for mri_ofsf2mriat */

static Lisp_Object CC_mri_ofsf2mriat(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0075)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090, v0089, v0134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_ofsf2mriat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0090 = v0075;
    v0089 = v0000;
/* end of prologue */
    v0134 = v0089;
    v0134 = qcar(v0134);
    v0089 = qcdr(v0089);
    v0089 = qcar(v0089);
    {
        fn = elt(env, 1); /* mri_0mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v0134, v0089, v0090);
    }
}



/* Code for aex_red */

static Lisp_Object CC_aex_red(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0075)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0147, v0145, v0146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_red");
#endif
    if (stack >= stacklimit)
    {
        push2(v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0075);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0147 = v0075;
    stack[0] = v0000;
/* end of prologue */
    v0145 = stack[0];
    fn = elt(env, 2); /* aex_mvaroccurtest */
    v0147 = (*qfn2(fn))(qenv(fn), v0145, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-2];
    if (v0147 == nil) goto v0091;
    v0147 = stack[0];
    fn = elt(env, 3); /* aex_ex */
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-2];
    fn = elt(env, 4); /* ratpoly_red */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-2];
    v0147 = stack[0];
    fn = elt(env, 5); /* aex_ctx */
    v0146 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-2];
    v0145 = qvalue(elt(env, 1)); /* nil */
    v0147 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0073 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v0073, v0146, v0145, v0147);
    }

v0091:
    {
        popv(3);
        fn = elt(env, 7); /* aex_0 */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v0126:
    popv(3);
    return nil;
}



/* Code for operator_fn */

static Lisp_Object CC_operator_fn(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for operator_fn");
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
    v0151 = qcar(v0161);
    v0161 = elt(env, 1); /* ((arcsinh . sinh) (arcsech . sech) (arccosh . cosh) (arccsch csch) (arctanh . tanh) (arccoth . coth)) 
*/
    v0161 = Latsoc(nil, v0151, v0161);
    stack[-1] = v0161;
    v0161 = stack[-1];
    if (v0161 == nil) goto v0135;
    v0161 = elt(env, 2); /* "<apply><inverse/>" */
    fn = elt(env, 8); /* printout */
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    v0161 = stack[-1];
    v0161 = qcdr(v0161);
    v0161 = Lprinc(nil, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    goto v0147;

v0147:
    v0151 = qvalue(elt(env, 6)); /* indent */
    v0161 = (Lisp_Object)49; /* 3 */
    v0161 = plus2(v0151, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    qvalue(elt(env, 6)) = v0161; /* indent */
    v0161 = stack[0];
    v0161 = qcdr(v0161);
    fn = elt(env, 9); /* multi_args */
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    v0151 = qvalue(elt(env, 6)); /* indent */
    v0161 = (Lisp_Object)49; /* 3 */
    v0161 = difference2(v0151, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    qvalue(elt(env, 6)) = v0161; /* indent */
    v0161 = elt(env, 7); /* "</apply>" */
    fn = elt(env, 8); /* printout */
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    v0161 = nil;
    { popv(3); return onevalue(v0161); }

v0135:
    v0161 = elt(env, 4); /* "<apply><fn><ci>" */
    fn = elt(env, 8); /* printout */
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    v0161 = stack[0];
    v0161 = qcar(v0161);
    v0161 = Lprinc(nil, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    v0161 = elt(env, 5); /* "</ci></fn>" */
    v0161 = Lprinc(nil, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    goto v0147;
/* error exit handlers */
v0084:
    popv(3);
    return nil;
}



/* Code for mkratnum */

static Lisp_Object CC_mkratnum(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0142, v0148, v0179;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkratnum");
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
/* copy arguments values to proper place */
    v0179 = v0000;
/* end of prologue */
    v0142 = v0179;
    if (!consp(v0142)) goto v0157;
    v0142 = v0179;
    v0148 = qcar(v0142);
    v0142 = elt(env, 2); /* !:gi!: */
    if (v0148 == v0142) goto v0147;
    v0142 = v0179;
    v0148 = qcar(v0142);
    v0142 = elt(env, 1); /* !:rn!: */
    v0142 = get(v0148, v0142);
    v0148 = v0179;
        return Lapply1(nil, v0142, v0148);

v0147:
    v0148 = elt(env, 2); /* !:gi!: */
    v0142 = elt(env, 3); /* !:crn!: */
    v0142 = get(v0148, v0142);
    v0148 = v0179;
        return Lapply1(nil, v0142, v0148);

v0157:
    v0148 = elt(env, 1); /* !:rn!: */
    v0142 = (Lisp_Object)17; /* 1 */
    return list2star(v0148, v0179, v0142);
}



/* Code for tp */

static Lisp_Object CC_tp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tp");
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
    v0149 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* matsm */
    v0149 = (*qfn1(fn))(qenv(fn), v0149);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* tp1 */
        return (*qfn1(fn))(qenv(fn), v0149);
    }
/* error exit handlers */
v0143:
    popv(1);
    return nil;
}



/* Code for fs!:subang */

static Lisp_Object MS_CDECL CC_fsTsubang(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0075,
                         Lisp_Object v0008, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0235, v0164, v0175, v0104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "fs:subang");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:subang");
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0075,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0008;
    stack[-6] = v0075;
    stack[-7] = v0000;
/* end of prologue */
    v0235 = stack[-7];
    if (v0235 == nil) goto v0143;
    v0235 = (Lisp_Object)113; /* 7 */
    v0235 = Lmkvect(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    stack[-8] = v0235;
    v0164 = stack[-7];
    v0235 = (Lisp_Object)33; /* 2 */
    v0164 = *(Lisp_Object *)((char *)v0164 + (CELL-TAG_VECTOR) + ((int32_t)v0235/(16/CELL)));
    v0235 = stack[-6];
    v0235 = *(Lisp_Object *)((char *)v0164 + (CELL-TAG_VECTOR) + ((int32_t)v0235/(16/CELL)));
    stack[-4] = v0235;
    v0235 = (Lisp_Object)1; /* 0 */
    stack[-3] = v0235;
    goto v0033;

v0033:
    v0164 = (Lisp_Object)113; /* 7 */
    v0235 = stack[-3];
    v0235 = difference2(v0164, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    v0235 = Lminusp(nil, v0235);
    env = stack[-9];
    if (v0235 == nil) goto v0151;
    v0164 = stack[-7];
    v0235 = (Lisp_Object)49; /* 3 */
    v0175 = *(Lisp_Object *)((char *)v0164 + (CELL-TAG_VECTOR) + ((int32_t)v0235/(16/CELL)));
    v0164 = stack[-6];
    v0235 = stack[-5];
    stack[0] = CC_fsTsubang(env, 3, v0175, v0164, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    v0164 = stack[-7];
    v0235 = (Lisp_Object)17; /* 1 */
    v0104 = *(Lisp_Object *)((char *)v0164 + (CELL-TAG_VECTOR) + ((int32_t)v0235/(16/CELL)));
    v0175 = stack[-8];
    v0164 = stack[-7];
    v0235 = (Lisp_Object)1; /* 0 */
    v0235 = *(Lisp_Object *)((char *)v0164 + (CELL-TAG_VECTOR) + ((int32_t)v0235/(16/CELL)));
    fn = elt(env, 2); /* make!-term */
    v0235 = (*qfnn(fn))(qenv(fn), 3, v0104, v0175, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    {
        Lisp_Object v0233 = stack[0];
        popv(10);
        fn = elt(env, 3); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v0233, v0235);
    }

v0151:
    v0164 = stack[-3];
    v0235 = stack[-6];
    if (equal(v0164, v0235)) goto v0179;
    stack[-2] = stack[-8];
    stack[-1] = stack[-3];
    v0164 = stack[-7];
    v0235 = (Lisp_Object)33; /* 2 */
    v0164 = *(Lisp_Object *)((char *)v0164 + (CELL-TAG_VECTOR) + ((int32_t)v0235/(16/CELL)));
    v0235 = stack[-3];
    stack[0] = *(Lisp_Object *)((char *)v0164 + (CELL-TAG_VECTOR) + ((int32_t)v0235/(16/CELL)));
    v0175 = stack[-4];
    v0164 = stack[-5];
    v0235 = stack[-3];
    v0235 = *(Lisp_Object *)((char *)v0164 + (CELL-TAG_VECTOR) + ((int32_t)v0235/(16/CELL)));
    v0235 = times2(v0175, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    v0235 = plus2(stack[0], v0235);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v0235;
    goto v0159;

v0159:
    v0235 = stack[-3];
    v0235 = add1(v0235);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    stack[-3] = v0235;
    goto v0033;

v0179:
    stack[-1] = stack[-8];
    stack[0] = stack[-3];
    v0175 = stack[-4];
    v0164 = stack[-5];
    v0235 = stack[-3];
    v0235 = *(Lisp_Object *)((char *)v0164 + (CELL-TAG_VECTOR) + ((int32_t)v0235/(16/CELL)));
    v0235 = times2(v0175, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0235;
    goto v0159;

v0143:
    v0235 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v0235); }
/* error exit handlers */
v0287:
    popv(10);
    return nil;
}



/* Code for split!-further */

static Lisp_Object MS_CDECL CC_splitKfurther(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0075,
                         Lisp_Object v0008, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0066, v0122, v0123, v0010;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "split-further");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split-further");
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0075,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0008;
    stack[-2] = v0075;
    stack[-3] = v0000;
/* end of prologue */
    v0066 = stack[-3];
    if (v0066 == nil) goto v0143;
    v0066 = stack[-3];
    v0123 = qcdr(v0066);
    v0122 = stack[-2];
    v0066 = stack[-1];
    v0066 = CC_splitKfurther(env, 3, v0123, v0122, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    stack[-4] = v0066;
    v0066 = stack[-4];
    v0066 = qcdr(v0066);
    stack[0] = v0066;
    v0066 = stack[-4];
    v0066 = qcar(v0066);
    stack[-4] = v0066;
    v0122 = qvalue(elt(env, 2)); /* number!-needed */
    v0066 = (Lisp_Object)1; /* 0 */
    if (v0122 == v0066) goto v0097;
    v0123 = stack[-2];
    v0122 = stack[-1];
    v0066 = qvalue(elt(env, 3)); /* work!-vector1 */
    fn = elt(env, 8); /* copy!-vector */
    v0066 = (*qfnn(fn))(qenv(fn), 3, v0123, v0122, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    qvalue(elt(env, 4)) = v0066; /* dwork1 */
    v0066 = stack[-3];
    v0066 = qcar(v0066);
    v0123 = qcar(v0066);
    v0066 = stack[-3];
    v0066 = qcar(v0066);
    v0122 = qcdr(v0066);
    v0066 = qvalue(elt(env, 5)); /* work!-vector2 */
    fn = elt(env, 8); /* copy!-vector */
    v0066 = (*qfnn(fn))(qenv(fn), 3, v0123, v0122, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    qvalue(elt(env, 6)) = v0066; /* dwork2 */
    v0010 = qvalue(elt(env, 3)); /* work!-vector1 */
    v0123 = qvalue(elt(env, 4)); /* dwork1 */
    v0122 = qvalue(elt(env, 5)); /* work!-vector2 */
    v0066 = qvalue(elt(env, 6)); /* dwork2 */
    fn = elt(env, 9); /* gcd!-in!-vector */
    v0066 = (*qfnn(fn))(qenv(fn), 4, v0010, v0123, v0122, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    qvalue(elt(env, 4)) = v0066; /* dwork1 */
    v0122 = qvalue(elt(env, 4)); /* dwork1 */
    v0066 = (Lisp_Object)1; /* 0 */
    if (v0122 == v0066) goto v0290;
    v0122 = qvalue(elt(env, 4)); /* dwork1 */
    v0066 = stack[-3];
    v0066 = qcar(v0066);
    v0066 = qcdr(v0066);
    v0066 = (equal(v0122, v0066) ? lisp_true : nil);
    goto v0277;

v0277:
    if (!(v0066 == nil)) goto v0097;
    v0066 = stack[-3];
    v0066 = qcar(v0066);
    v0123 = qcar(v0066);
    v0066 = stack[-3];
    v0066 = qcar(v0066);
    v0122 = qcdr(v0066);
    v0066 = qvalue(elt(env, 5)); /* work!-vector2 */
    fn = elt(env, 8); /* copy!-vector */
    v0066 = (*qfnn(fn))(qenv(fn), 3, v0123, v0122, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    qvalue(elt(env, 6)) = v0066; /* dwork2 */
    v0010 = qvalue(elt(env, 5)); /* work!-vector2 */
    v0123 = qvalue(elt(env, 6)); /* dwork2 */
    v0122 = qvalue(elt(env, 3)); /* work!-vector1 */
    v0066 = qvalue(elt(env, 4)); /* dwork1 */
    fn = elt(env, 10); /* quotfail!-in!-vector */
    v0066 = (*qfnn(fn))(qenv(fn), 4, v0010, v0123, v0122, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    qvalue(elt(env, 6)) = v0066; /* dwork2 */
    v0066 = qvalue(elt(env, 4)); /* dwork1 */
    v0066 = Lmkvect(nil, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    stack[-1] = v0066;
    v0123 = qvalue(elt(env, 3)); /* work!-vector1 */
    v0122 = qvalue(elt(env, 4)); /* dwork1 */
    v0066 = stack[-1];
    fn = elt(env, 8); /* copy!-vector */
    v0066 = (*qfnn(fn))(qenv(fn), 3, v0123, v0122, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    v0123 = stack[-1];
    v0122 = qvalue(elt(env, 4)); /* dwork1 */
    v0066 = stack[-4];
    v0066 = acons(v0123, v0122, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    stack[-4] = v0066;
    stack[-2] = qvalue(elt(env, 5)); /* work!-vector2 */
    stack[-1] = qvalue(elt(env, 6)); /* dwork2 */
    v0066 = qvalue(elt(env, 6)); /* dwork2 */
    v0066 = Lmkvect(nil, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    stack[-3] = v0066;
    fn = elt(env, 8); /* copy!-vector */
    v0066 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    v0123 = stack[-3];
    v0122 = qvalue(elt(env, 6)); /* dwork2 */
    v0066 = stack[0];
    v0066 = acons(v0123, v0122, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-5];
    stack[0] = v0066;
    v0066 = qvalue(elt(env, 2)); /* number!-needed */
    v0066 = (Lisp_Object)((int32_t)(v0066) - 0x10);
    qvalue(elt(env, 2)) = v0066; /* number!-needed */
    v0122 = stack[-4];
    v0066 = stack[0];
    popv(6);
    return cons(v0122, v0066);

v0097:
    v0123 = stack[-4];
    v0066 = stack[-3];
    v0122 = qcar(v0066);
    v0066 = stack[0];
    popv(6);
    return list2star(v0123, v0122, v0066);

v0290:
    v0066 = qvalue(elt(env, 7)); /* t */
    goto v0277;

v0143:
    v0066 = qvalue(elt(env, 1)); /* nil */
    popv(6);
    return ncons(v0066);
/* error exit handlers */
v0063:
    popv(6);
    return nil;
}



/* Code for zfactor1 */

static Lisp_Object CC_zfactor1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0075)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0096, v0095, v0097;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zfactor1");
#endif
    if (stack >= stacklimit)
    {
        push2(v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0075);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0075;
    stack[-4] = v0000;
/* end of prologue */
    stack[0] = nil;
    goto v0182;

v0182:
    v0095 = stack[-4];
    v0096 = (Lisp_Object)1; /* 0 */
    v0096 = (Lisp_Object)lessp2(v0095, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    v0096 = v0096 ? lisp_true : nil;
    env = stack[-6];
    if (v0096 == nil) goto v0147;
    v0097 = (Lisp_Object)-15; /* -1 */
    v0095 = (Lisp_Object)17; /* 1 */
    v0096 = stack[0];
    v0096 = acons(v0097, v0095, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-6];
    stack[0] = v0096;
    v0096 = stack[-4];
    v0096 = negate(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-6];
    stack[-4] = v0096;
    goto v0182;

v0147:
    v0095 = stack[-4];
    v0096 = (Lisp_Object)65; /* 4 */
    v0096 = (Lisp_Object)lessp2(v0095, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    v0096 = v0096 ? lisp_true : nil;
    env = stack[-6];
    if (v0096 == nil) goto v0142;
    v0095 = stack[-4];
    v0096 = (Lisp_Object)17; /* 1 */
    v0096 = cons(v0095, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-6];
    v0096 = ncons(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-6];
    {
        Lisp_Object v0067 = stack[0];
        popv(7);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0067, v0096);
    }

v0142:
    stack[-5] = stack[0];
    v0096 = qvalue(elt(env, 1)); /* !*primelist!* */
    stack[-2] = v0096;
    v0096 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v0096;
    goto v0119;

v0119:
    v0096 = stack[-2];
    if (v0096 == nil) goto v0291;
    v0096 = stack[-2];
    v0096 = qcar(v0096);
    stack[0] = v0096;
    v0096 = stack[-2];
    v0096 = qcdr(v0096);
    stack[-2] = v0096;
    goto v0244;

v0244:
    v0095 = stack[-4];
    v0096 = stack[0];
    v0096 = Ldivide(nil, v0095, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-6];
    v0097 = v0096;
    v0095 = qcdr(v0096);
    v0096 = (Lisp_Object)1; /* 0 */
    if (v0095 == v0096) goto v0277;
    v0095 = stack[-4];
    v0096 = (Lisp_Object)17; /* 1 */
    if (v0095 == v0096) goto v0242;
    v0095 = stack[0];
    v0096 = stack[0];
    v0095 = times2(v0095, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-6];
    v0096 = stack[-4];
    v0096 = (Lisp_Object)greaterp2(v0095, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    v0096 = v0096 ? lisp_true : nil;
    env = stack[-6];
    goto v0111;

v0111:
    if (v0096 == nil) goto v0119;
    v0096 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v0096;
    v0095 = stack[-4];
    v0096 = stack[-1];
    fn = elt(env, 4); /* add!-factor */
    v0096 = (*qfn2(fn))(qenv(fn), v0095, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-6];
    stack[-1] = v0096;
    v0096 = (Lisp_Object)17; /* 1 */
    stack[-4] = v0096;
    goto v0119;

v0242:
    v0096 = qvalue(elt(env, 2)); /* nil */
    goto v0111;

v0277:
    v0096 = v0097;
    v0096 = qcar(v0096);
    stack[-4] = v0096;
    v0095 = stack[0];
    v0096 = stack[-1];
    fn = elt(env, 4); /* add!-factor */
    v0096 = (*qfn2(fn))(qenv(fn), v0095, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-6];
    stack[-1] = v0096;
    goto v0244;

v0291:
    v0095 = stack[-4];
    v0096 = (Lisp_Object)17; /* 1 */
    if (v0095 == v0096) goto v0289;
    v0096 = stack[-3];
    if (v0096 == nil) goto v0022;
    v0095 = stack[-4];
    v0096 = stack[-1];
    fn = elt(env, 5); /* mcfactor!* */
    v0096 = (*qfn2(fn))(qenv(fn), v0095, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-6];
    goto v0178;

v0178:
    {
        Lisp_Object v0098 = stack[-5];
        popv(7);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0098, v0096);
    }

v0022:
    v0097 = stack[-4];
    v0095 = (Lisp_Object)17; /* 1 */
    v0096 = stack[-1];
    v0096 = acons(v0097, v0095, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-6];
    goto v0178;

v0289:
    v0096 = stack[-1];
    goto v0178;
/* error exit handlers */
v0234:
    popv(7);
    return nil;
}



/* Code for janettreeinsert */

static Lisp_Object CC_janettreeinsert(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0299, v0300, v0301;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for janettreeinsert");
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
    v0300 = stack[-7];
    v0299 = (Lisp_Object)17; /* 1 */
    v0299 = *(Lisp_Object *)((char *)v0300 + (CELL-TAG_VECTOR) + ((int32_t)v0299/(16/CELL)));
    v0299 = qcar(v0299);
    stack[-3] = v0299;
    v0300 = stack[-3];
    v0299 = (Lisp_Object)1; /* 0 */
    v0299 = *(Lisp_Object *)((char *)v0300 + (CELL-TAG_VECTOR) + ((int32_t)v0299/(16/CELL)));
    stack[-6] = v0299;
    v0299 = (Lisp_Object)17; /* 1 */
    stack[-8] = v0299;
    v0299 = qvalue(elt(env, 1)); /* fluidbibasisjanettreerootnode */
    if (v0299 == nil) goto v0147;
    v0299 = qvalue(elt(env, 1)); /* fluidbibasisjanettreerootnode */
    stack[-5] = v0299;
    goto v0039;

v0039:
    v0300 = stack[-6];
    v0299 = (Lisp_Object)1; /* 0 */
    v0299 = (Lisp_Object)greaterp2(v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    v0299 = v0299 ? lisp_true : nil;
    env = stack[-9];
    if (!(v0299 == nil)) goto v0036;

v0092:
    v0299 = nil;
    { popv(10); return onevalue(v0299); }

v0036:
    v0299 = stack[-5];
    if (v0299 == nil) goto v0118;
    v0299 = stack[-5];
    v0299 = qcar(v0299);
    stack[0] = qcar(v0299);
    v0300 = stack[-3];
    v0299 = stack[-8];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v0299 = (*qfn2(fn))(qenv(fn), v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    v0299 = (Lisp_Object)lessp2(stack[0], v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    v0299 = v0299 ? lisp_true : nil;
    env = stack[-9];
    if (v0299 == nil) goto v0118;
    v0299 = stack[-5];
    v0299 = qcdr(v0299);
    v0299 = qcar(v0299);
    if (v0299 == nil) goto v0118;
    v0299 = stack[-5];
    v0299 = qcdr(v0299);
    v0299 = qcar(v0299);
    stack[-5] = v0299;
    goto v0036;

v0118:
    v0299 = stack[-5];
    if (v0299 == nil) goto v0273;
    v0299 = stack[-5];
    v0299 = qcar(v0299);
    stack[0] = qcar(v0299);
    v0300 = stack[-3];
    v0299 = stack[-8];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v0299 = (*qfn2(fn))(qenv(fn), v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    v0299 = (Lisp_Object)greaterp2(stack[0], v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    v0299 = v0299 ? lisp_true : nil;
    env = stack[-9];
    if (v0299 == nil) goto v0273;
    v0301 = stack[-6];
    v0300 = stack[-8];
    v0299 = stack[-7];
    fn = elt(env, 4); /* janettreenodebuild */
    v0299 = (*qfnn(fn))(qenv(fn), 3, v0301, v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    stack[-4] = v0299;
    v0299 = (Lisp_Object)1; /* 0 */
    stack[-6] = v0299;
    v0299 = stack[-5];
    stack[-2] = qcdr(v0299);
    v0299 = stack[-5];
    v0299 = qcar(v0299);
    stack[-1] = qcar(v0299);
    v0299 = stack[-5];
    v0299 = qcar(v0299);
    stack[0] = qcdr(v0299);
    v0299 = stack[-5];
    v0299 = qcdr(v0299);
    v0300 = qcar(v0299);
    v0299 = stack[-5];
    v0299 = qcdr(v0299);
    v0299 = qcdr(v0299);
    v0299 = cons(v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    v0299 = acons(stack[-1], stack[0], v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    fn = elt(env, 5); /* setcar */
    v0299 = (*qfn2(fn))(qenv(fn), stack[-2], v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    v0299 = stack[-5];
    v0300 = qcdr(v0299);
    v0299 = stack[-4];
    v0299 = qcdr(v0299);
    v0299 = qcdr(v0299);
    fn = elt(env, 6); /* setcdr */
    v0299 = (*qfn2(fn))(qenv(fn), v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    v0299 = stack[-5];
    v0300 = qcar(v0299);
    v0299 = stack[-4];
    v0299 = qcar(v0299);
    v0299 = qcar(v0299);
    fn = elt(env, 5); /* setcar */
    v0299 = (*qfn2(fn))(qenv(fn), v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    v0299 = stack[-5];
    v0300 = qcar(v0299);
    v0299 = stack[-4];
    v0299 = qcar(v0299);
    v0299 = qcdr(v0299);
    fn = elt(env, 6); /* setcdr */
    v0299 = (*qfn2(fn))(qenv(fn), v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    goto v0039;

v0273:
    v0299 = stack[-5];
    if (v0299 == nil) goto v0303;
    v0299 = stack[-5];
    v0299 = qcar(v0299);
    stack[0] = qcar(v0299);
    v0300 = stack[-3];
    v0299 = stack[-8];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v0299 = (*qfn2(fn))(qenv(fn), v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    if (equal(stack[0], v0299)) goto v0066;
    v0299 = qvalue(elt(env, 2)); /* nil */
    goto v0099;

v0099:
    if (v0299 == nil) goto v0303;
    stack[0] = stack[-6];
    v0300 = stack[-3];
    v0299 = stack[-8];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v0299 = (*qfn2(fn))(qenv(fn), v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    v0299 = difference2(stack[0], v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    stack[-6] = v0299;
    v0299 = stack[-8];
    v0299 = add1(v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    stack[-8] = v0299;
    v0299 = stack[-5];
    v0299 = qcdr(v0299);
    v0299 = qcdr(v0299);
    stack[-5] = v0299;
    goto v0039;

v0303:
    v0299 = stack[-5];
    if (v0299 == nil) goto v0039;
    v0299 = stack[-5];
    stack[0] = qcdr(v0299);
    v0301 = stack[-6];
    v0300 = stack[-8];
    v0299 = stack[-7];
    fn = elt(env, 4); /* janettreenodebuild */
    v0299 = (*qfnn(fn))(qenv(fn), 3, v0301, v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    fn = elt(env, 5); /* setcar */
    v0299 = (*qfn2(fn))(qenv(fn), stack[0], v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    v0299 = (Lisp_Object)1; /* 0 */
    stack[-6] = v0299;
    goto v0039;

v0066:
    v0299 = stack[-5];
    v0299 = qcdr(v0299);
    v0299 = qcdr(v0299);
    goto v0099;

v0147:
    v0301 = stack[-6];
    v0300 = stack[-8];
    v0299 = stack[-7];
    fn = elt(env, 4); /* janettreenodebuild */
    v0299 = (*qfnn(fn))(qenv(fn), 3, v0301, v0300, v0299);
    nil = C_nil;
    if (exception_pending()) goto v0302;
    env = stack[-9];
    qvalue(elt(env, 1)) = v0299; /* fluidbibasisjanettreerootnode */
    goto v0092;
/* error exit handlers */
v0302:
    popv(10);
    return nil;
}



/* Code for subdf */

static Lisp_Object MS_CDECL CC_subdf(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0075,
                         Lisp_Object v0008, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0078, v0173, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subdf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subdf");
#endif
    if (stack >= stacklimit)
    {
        push3(v0008,v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0075,v0008);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v0008;
    stack[-3] = v0075;
    stack[-4] = v0000;
/* end of prologue */

v0305:
    v0078 = stack[-4];
    if (v0078 == nil) goto v0143;
    v0078 = stack[-4];
    v0078 = qcar(v0078);
    v0078 = qcdr(v0078);
    stack[0] = qcar(v0078);
    v0173 = stack[-2];
    v0078 = stack[-3];
    v0078 = cons(v0173, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    v0078 = ncons(v0078);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    fn = elt(env, 2); /* subf */
    v0078 = (*qfn2(fn))(qenv(fn), stack[0], v0078);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    fn = elt(env, 3); /* subs2q */
    v0078 = (*qfn1(fn))(qenv(fn), v0078);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    stack[-5] = v0078;
    stack[0] = stack[-5];
    v0173 = qvalue(elt(env, 1)); /* nil */
    v0078 = (Lisp_Object)17; /* 1 */
    v0078 = cons(v0173, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    if (equal(stack[0], v0078)) goto v0160;
    v0078 = stack[-4];
    v0078 = qcar(v0078);
    stack[-1] = qcar(v0078);
    v0078 = stack[-5];
    stack[0] = qcar(v0078);
    v0078 = stack[-5];
    v0173 = qcdr(v0078);
    v0078 = stack[-4];
    v0078 = qcar(v0078);
    v0078 = qcdr(v0078);
    v0078 = qcdr(v0078);
    fn = elt(env, 4); /* !*multf */
    v0078 = (*qfn2(fn))(qenv(fn), v0173, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    v0078 = list2star(stack[-1], stack[0], v0078);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    stack[0] = ncons(v0078);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    v0078 = stack[-4];
    v0028 = qcdr(v0078);
    v0173 = stack[-3];
    v0078 = stack[-2];
    v0078 = CC_subdf(env, 3, v0028, v0173, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-6];
    {
        Lisp_Object v0306 = stack[0];
        popv(7);
        fn = elt(env, 5); /* plusdf */
        return (*qfn2(fn))(qenv(fn), v0306, v0078);
    }

v0160:
    v0078 = stack[-4];
    v0028 = qcdr(v0078);
    v0173 = stack[-3];
    v0078 = stack[-2];
    stack[-4] = v0028;
    stack[-3] = v0173;
    stack[-2] = v0078;
    goto v0305;

v0143:
    v0078 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0078); }
/* error exit handlers */
v0052:
    popv(7);
    return nil;
}



/* Code for tendstoml */

static Lisp_Object CC_tendstoml(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0092, v0138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tendstoml");
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
    v0092 = elt(env, 1); /* "<apply><tendsto" */
    fn = elt(env, 6); /* printout */
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    v0092 = stack[0];
    v0138 = qcar(v0092);
    v0092 = elt(env, 2); /* "/" */
    fn = elt(env, 7); /* attributesml */
    v0092 = (*qfn2(fn))(qenv(fn), v0138, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    v0092 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 8); /* indent!* */
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    v0092 = stack[0];
    v0092 = qcdr(v0092);
    v0092 = qcar(v0092);
    fn = elt(env, 9); /* expression */
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    v0092 = stack[0];
    v0092 = qcdr(v0092);
    v0092 = qcdr(v0092);
    v0092 = qcar(v0092);
    fn = elt(env, 9); /* expression */
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    v0092 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 8); /* indent!* */
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    v0092 = elt(env, 5); /* "</apply>" */
    fn = elt(env, 6); /* printout */
    v0092 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    v0092 = nil;
    { popv(2); return onevalue(v0092); }
/* error exit handlers */
v0041:
    popv(2);
    return nil;
}



/* Code for parseml */

static Lisp_Object MS_CDECL CC_parseml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036, v0037;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "parseml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for parseml");
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
    v0036 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0036;
    v0037 = elt(env, 2); /* !! */
    v0036 = (Lisp_Object)513; /* 32 */
    v0036 = list2(v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    v0036 = Lcompress(nil, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    qvalue(elt(env, 3)) = v0036; /* space */
    v0036 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 4)) = v0036; /* count */
    v0036 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    qvalue(elt(env, 5)) = v0036; /* ch */
    v0036 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 6)) = v0036; /* temp2 */
    fn = elt(env, 12); /* lex */
    v0036 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    v0037 = qvalue(elt(env, 7)); /* char */
    v0036 = elt(env, 8); /* (m a t h) */
    if (equal(v0037, v0036)) goto v0140;
    v0037 = elt(env, 9); /* "<math>" */
    v0036 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 13); /* errorml */
    v0036 = (*qfn2(fn))(qenv(fn), v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    goto v0139;

v0139:
    fn = elt(env, 12); /* lex */
    v0036 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    v0037 = qvalue(elt(env, 7)); /* char */
    v0036 = elt(env, 10); /* (!/ m a t h) */
    if (equal(v0037, v0036)) goto v0085;
    v0037 = elt(env, 11); /* "</math>" */
    v0036 = (Lisp_Object)305; /* 19 */
    fn = elt(env, 13); /* errorml */
    v0036 = (*qfn2(fn))(qenv(fn), v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    goto v0033;

v0033:
    v0036 = stack[0];
    {
        popv(2);
        fn = elt(env, 14); /* aeval */
        return (*qfn1(fn))(qenv(fn), v0036);
    }

v0085:
    v0036 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    goto v0033;

v0140:
    fn = elt(env, 15); /* mathml */
    v0036 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    stack[0] = v0036;
    goto v0139;
/* error exit handlers */
v0172:
    popv(2);
    return nil;
}



/* Code for getvariables */

static Lisp_Object CC_getvariables(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0134, v0280;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getvariables");
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
    v0280 = v0000;
/* end of prologue */
    v0134 = v0280;
    stack[0] = qcar(v0134);
    v0134 = v0280;
    v0280 = qcdr(v0134);
    v0134 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* varsinsf */
    v0134 = (*qfn2(fn))(qenv(fn), v0280, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-1];
    {
        Lisp_Object v0044 = stack[0];
        popv(2);
        fn = elt(env, 2); /* varsinsf */
        return (*qfn2(fn))(qenv(fn), v0044, v0134);
    }
/* error exit handlers */
v0140:
    popv(2);
    return nil;
}



/* Code for subscriptedvarp2 */

static Lisp_Object CC_subscriptedvarp2(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subscriptedvarp2");
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
    v0089 = v0000;
/* end of prologue */
    v0134 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* symtabget */
    v0089 = (*qfn2(fn))(qenv(fn), v0134, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    env = stack[0];
    v0134 = Llength(nil, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0280;
    v0089 = (Lisp_Object)33; /* 2 */
        popv(1);
        return Lgreaterp(nil, v0134, v0089);
/* error exit handlers */
v0280:
    popv(1);
    return nil;
}



/* Code for evalgeq */

static Lisp_Object CC_evalgeq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0075)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0182, v0150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalgeq");
#endif
    if (stack >= stacklimit)
    {
        push2(v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0075);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0150 = v0075;
    v0182 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* evalgreaterp */
    v0182 = (*qfn2(fn))(qenv(fn), v0150, v0182);
    errexit();
    v0182 = (v0182 == nil ? lisp_true : nil);
    return onevalue(v0182);
}



/* Code for f2dip2 */

static Lisp_Object MS_CDECL CC_f2dip2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0075,
                         Lisp_Object v0008, Lisp_Object v0009,
                         Lisp_Object v0076, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0125, v0079, v0094;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "f2dip2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2dip2");
#endif
    if (stack >= stacklimit)
    {
        push5(v0076,v0009,v0008,v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0075,v0008,v0009,v0076);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0076;
    stack[-1] = v0009;
    stack[-2] = v0008;
    stack[-3] = v0075;
    stack[-4] = v0000;
/* end of prologue */
    v0125 = stack[-4];
    v0034 = qvalue(elt(env, 1)); /* dipvars!* */
    v0034 = Lmemq(nil, v0125, v0034);
    if (v0034 == nil) goto v0091;
    v0094 = stack[-1];
    v0079 = stack[-4];
    v0125 = stack[-3];
    v0034 = qvalue(elt(env, 1)); /* dipvars!* */
    fn = elt(env, 3); /* evinsert */
    v0034 = (*qfnn(fn))(qenv(fn), 4, v0094, v0079, v0125, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-5];
    goto v0158;

v0158:
    v0125 = v0034;
    v0034 = v0125;
    if (v0034 == nil) goto v0141;
    v0034 = v0125;
    stack[-1] = v0034;
    goto v0251;

v0251:
    v0079 = stack[-2];
    v0125 = stack[-1];
    v0034 = stack[0];
    {
        popv(6);
        fn = elt(env, 4); /* f2dip1 */
        return (*qfnn(fn))(qenv(fn), 3, v0079, v0125, v0034);
    }

v0141:
    v0079 = stack[-4];
    v0125 = stack[-3];
    v0034 = (Lisp_Object)17; /* 1 */
    v0079 = acons(v0079, v0125, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-5];
    v0125 = qvalue(elt(env, 2)); /* nil */
    v0034 = (Lisp_Object)17; /* 1 */
    v0034 = acons(v0079, v0125, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-5];
    fn = elt(env, 5); /* multsq */
    v0034 = (*qfn2(fn))(qenv(fn), stack[0], v0034);
    nil = C_nil;
    if (exception_pending()) goto v0277;
    env = stack[-5];
    stack[0] = v0034;
    goto v0251;

v0091:
    v0034 = qvalue(elt(env, 2)); /* nil */
    goto v0158;
/* error exit handlers */
v0277:
    popv(6);
    return nil;
}



/* Code for make_wedge_pair */

static Lisp_Object CC_make_wedge_pair(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0075)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0277, v0290, v0304;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make_wedge_pair");
#endif
    if (stack >= stacklimit)
    {
        push2(v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0075);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0075;
    stack[-2] = v0000;
/* end of prologue */
    v0290 = stack[-2];
    v0277 = stack[-2];
    stack[0] = list2(v0290, v0277);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    v0277 = stack[-1];
    fn = elt(env, 5); /* xval */
    v0277 = (*qfn1(fn))(qenv(fn), v0277);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    fn = elt(env, 6); /* xlcm */
    v0277 = (*qfn2(fn))(qenv(fn), stack[0], v0277);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    stack[-3] = v0277;
    v0277 = qvalue(elt(env, 1)); /* !*twosided */
    if (v0277 == nil) goto v0092;
    v0277 = qvalue(elt(env, 2)); /* xtruncate!* */
    if (!(v0277 == nil)) goto v0092;

v0072:
    v0290 = stack[-2];
    v0277 = stack[-1];
    fn = elt(env, 7); /* overall_factor */
    v0277 = (*qfn2(fn))(qenv(fn), v0290, v0277);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    if (v0277 == nil) goto v0033;
    v0277 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v0277); }

v0033:
    v0277 = stack[-3];
    fn = elt(env, 8); /* mknwedge */
    v0277 = (*qfn1(fn))(qenv(fn), v0277);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    fn = elt(env, 9); /* xdegreecheck */
    v0277 = (*qfn1(fn))(qenv(fn), v0277);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    if (v0277 == nil) goto v0178;
    v0277 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v0277); }

v0178:
    stack[0] = elt(env, 4); /* wedge_pair */
    v0304 = stack[-2];
    v0290 = (Lisp_Object)17; /* 1 */
    v0277 = (Lisp_Object)17; /* 1 */
    v0277 = list2star(v0304, v0290, v0277);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    v0290 = ncons(v0277);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    v0277 = stack[-1];
    {
        Lisp_Object v0093 = stack[-3];
        Lisp_Object v0244 = stack[0];
        popv(5);
        return list4(v0093, v0244, v0290, v0277);
    }

v0092:
    stack[0] = stack[-2];
    v0277 = stack[-1];
    fn = elt(env, 5); /* xval */
    v0277 = (*qfn1(fn))(qenv(fn), v0277);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-4];
    v0277 = Lmemq(nil, stack[0], v0277);
    if (!(v0277 == nil)) goto v0072;
    v0277 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v0277); }
/* error exit handlers */
v0243:
    popv(5);
    return nil;
}



/* Code for !:dmexpt */

static Lisp_Object CC_Tdmexpt(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0075)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071, v0070;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :dmexpt");
#endif
    if (stack >= stacklimit)
    {
        push2(v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0075);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0075;
    stack[-1] = v0000;
/* end of prologue */
    v0071 = stack[0];
    fn = elt(env, 2); /* !:dm2fix */
    v0071 = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    v0070 = v0071;
    v0070 = integerp(v0070);
    if (v0070 == nil) goto v0280;
    v0070 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* !:expt */
        return (*qfn2(fn))(qenv(fn), v0070, v0071);
    }

v0280:
    v0071 = stack[-1];
    fn = elt(env, 4); /* force!-to!-dm */
    v0071 = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    stack[-1] = v0071;
    v0071 = stack[0];
    fn = elt(env, 4); /* force!-to!-dm */
    v0071 = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    stack[0] = v0071;
    v0071 = qvalue(elt(env, 1)); /* !*complex */
    if (v0071 == nil) goto v0171;
    v0070 = stack[-1];
    v0071 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* crexpt!* */
        return (*qfn2(fn))(qenv(fn), v0070, v0071);
    }

v0171:
    v0070 = stack[-1];
    v0071 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* rdexpt!* */
        return (*qfn2(fn))(qenv(fn), v0070, v0071);
    }
/* error exit handlers */
v0159:
    popv(3);
    return nil;
}



/* Code for deletez1 */

static Lisp_Object CC_deletez1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0075)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0071, v0070, v0152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deletez1");
#endif
    if (stack >= stacklimit)
    {
        push2(v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0075);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0075;
    stack[-1] = v0000;
/* end of prologue */
    v0152 = nil;
    goto v0143;

v0143:
    v0035 = stack[-1];
    if (v0035 == nil) goto v0162;
    v0070 = (Lisp_Object)1; /* 0 */
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    v0071 = qcar(v0035);
    v0035 = stack[0];
    v0035 = Lassoc(nil, v0071, v0035);
    v0035 = qcdr(v0035);
    if (v0070 == v0035) goto v0040;
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    v0071 = v0152;
    v0035 = cons(v0035, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-2];
    v0152 = v0035;
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    stack[-1] = v0035;
    goto v0143;

v0040:
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    stack[-1] = v0035;
    goto v0143;

v0162:
    v0035 = v0152;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0035);
    }
/* error exit handlers */
v0160:
    popv(3);
    return nil;
}



/* Code for mapcarcar */

static Lisp_Object CC_mapcarcar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mapcarcar");
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
    v0033 = v0000;
/* end of prologue */
    stack[-3] = v0033;
    v0033 = stack[-3];
    if (v0033 == nil) goto v0050;
    v0033 = stack[-3];
    v0033 = qcar(v0033);
    v0033 = qcar(v0033);
    v0033 = ncons(v0033);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    stack[-1] = v0033;
    stack[-2] = v0033;
    goto v0158;

v0158:
    v0033 = stack[-3];
    v0033 = qcdr(v0033);
    stack[-3] = v0033;
    v0033 = stack[-3];
    if (v0033 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0033 = stack[-3];
    v0033 = qcar(v0033);
    v0033 = qcar(v0033);
    v0033 = ncons(v0033);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    v0033 = Lrplacd(nil, stack[0], v0033);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    v0033 = stack[-1];
    v0033 = qcdr(v0033);
    stack[-1] = v0033;
    goto v0158;

v0050:
    v0033 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0033); }
/* error exit handlers */
v0071:
    popv(5);
    return nil;
}



/* Code for simp!-prop!-form */

static Lisp_Object CC_simpKpropKform(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0224, v0313, v0314;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop-form");
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
    v0313 = v0000;
/* end of prologue */
    v0314 = v0313;
    v0224 = elt(env, 1); /* (nil) */
    if (equal(v0314, v0224)) goto v0076;
    v0224 = v0313;
    stack[-7] = v0224;
    v0224 = stack[-7];
    if (v0224 == nil) goto v0135;
    v0224 = stack[-7];
    v0224 = qcar(v0224);
    stack[-3] = v0224;
    v0224 = stack[-3];
    if (v0224 == nil) goto v0171;
    v0224 = stack[-3];
    v0224 = qcar(v0224);
    v0314 = v0224;
    v0313 = v0314;
    v0224 = elt(env, 4); /* not_prop!* */
    if (!consp(v0313)) goto v0250;
    v0313 = qcar(v0313);
    if (!(v0313 == v0224)) goto v0250;
    v0224 = elt(env, 5); /* not */
    v0313 = v0314;
    v0313 = qcdr(v0313);
    v0313 = qcar(v0313);
    v0224 = list2(v0224, v0313);
    nil = C_nil;
    if (exception_pending()) goto v0315;
    env = stack[-8];
    goto v0152;

v0152:
    v0224 = ncons(v0224);
    nil = C_nil;
    if (exception_pending()) goto v0315;
    env = stack[-8];
    stack[-1] = v0224;
    stack[-2] = v0224;
    goto v0156;

v0156:
    v0224 = stack[-3];
    v0224 = qcdr(v0224);
    stack[-3] = v0224;
    v0224 = stack[-3];
    if (v0224 == nil) goto v0181;
    stack[0] = stack[-1];
    v0224 = stack[-3];
    v0224 = qcar(v0224);
    v0314 = v0224;
    v0313 = v0314;
    v0224 = elt(env, 4); /* not_prop!* */
    if (!consp(v0313)) goto v0031;
    v0313 = qcar(v0313);
    if (!(v0313 == v0224)) goto v0031;
    v0224 = elt(env, 5); /* not */
    v0313 = v0314;
    v0313 = qcdr(v0313);
    v0313 = qcar(v0313);
    v0224 = list2(v0224, v0313);
    nil = C_nil;
    if (exception_pending()) goto v0315;
    env = stack[-8];
    goto v0080;

v0080:
    v0224 = ncons(v0224);
    nil = C_nil;
    if (exception_pending()) goto v0315;
    env = stack[-8];
    v0224 = Lrplacd(nil, stack[0], v0224);
    nil = C_nil;
    if (exception_pending()) goto v0315;
    env = stack[-8];
    v0224 = stack[-1];
    v0224 = qcdr(v0224);
    stack[-1] = v0224;
    goto v0156;

v0031:
    v0224 = v0314;
    v0224 = qcdr(v0224);
    v0224 = qcar(v0224);
    goto v0080;

v0181:
    v0224 = stack[-2];
    goto v0146;

v0146:
    v0313 = v0224;
    v0313 = qcdr(v0313);
    if (v0313 == nil) goto v0113;
    v0313 = qvalue(elt(env, 6)); /* !'and */
    v0224 = cons(v0313, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0315;
    env = stack[-8];
    goto v0111;

v0111:
    v0224 = ncons(v0224);
    nil = C_nil;
    if (exception_pending()) goto v0315;
    env = stack[-8];
    stack[-5] = v0224;
    stack[-6] = v0224;
    goto v0139;

v0139:
    v0224 = stack[-7];
    v0224 = qcdr(v0224);
    stack[-7] = v0224;
    v0224 = stack[-7];
    if (v0224 == nil) goto v0027;
    stack[-4] = stack[-5];
    v0224 = stack[-7];
    v0224 = qcar(v0224);
    stack[-3] = v0224;
    v0224 = stack[-3];
    if (v0224 == nil) goto v0024;
    v0224 = stack[-3];
    v0224 = qcar(v0224);
    v0314 = v0224;
    v0313 = v0314;
    v0224 = elt(env, 4); /* not_prop!* */
    if (!consp(v0313)) goto v0095;
    v0313 = qcar(v0313);
    if (!(v0313 == v0224)) goto v0095;
    v0224 = elt(env, 5); /* not */
    v0313 = v0314;
    v0313 = qcdr(v0313);
    v0313 = qcar(v0313);
    v0224 = list2(v0224, v0313);
    nil = C_nil;
    if (exception_pending()) goto v0315;
    env = stack[-8];
    goto v0022;

v0022:
    v0224 = ncons(v0224);
    nil = C_nil;
    if (exception_pending()) goto v0315;
    env = stack[-8];
    stack[-1] = v0224;
    stack[-2] = v0224;
    goto v0240;

v0240:
    v0224 = stack[-3];
    v0224 = qcdr(v0224);
    stack[-3] = v0224;
    v0224 = stack[-3];
    if (v0224 == nil) goto v0067;
    stack[0] = stack[-1];
    v0224 = stack[-3];
    v0224 = qcar(v0224);
    v0314 = v0224;
    v0313 = v0314;
    v0224 = elt(env, 4); /* not_prop!* */
    if (!consp(v0313)) goto v0316;
    v0313 = qcar(v0313);
    if (!(v0313 == v0224)) goto v0316;
    v0224 = elt(env, 5); /* not */
    v0313 = v0314;
    v0313 = qcdr(v0313);
    v0313 = qcar(v0313);
    v0224 = list2(v0224, v0313);
    nil = C_nil;
    if (exception_pending()) goto v0315;
    env = stack[-8];
    goto v0129;

v0129:
    v0224 = ncons(v0224);
    nil = C_nil;
    if (exception_pending()) goto v0315;
    env = stack[-8];
    v0224 = Lrplacd(nil, stack[0], v0224);
    nil = C_nil;
    if (exception_pending()) goto v0315;
    env = stack[-8];
    v0224 = stack[-1];
    v0224 = qcdr(v0224);
    stack[-1] = v0224;
    goto v0240;

v0316:
    v0224 = v0314;
    v0224 = qcdr(v0224);
    v0224 = qcar(v0224);
    goto v0129;

v0067:
    v0224 = stack[-2];
    goto v0289;

v0289:
    v0313 = v0224;
    v0313 = qcdr(v0313);
    if (v0313 == nil) goto v0003;
    v0313 = qvalue(elt(env, 6)); /* !'and */
    v0224 = cons(v0313, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0315;
    env = stack[-8];
    goto v0011;

v0011:
    v0224 = ncons(v0224);
    nil = C_nil;
    if (exception_pending()) goto v0315;
    env = stack[-8];
    v0224 = Lrplacd(nil, stack[-4], v0224);
    nil = C_nil;
    if (exception_pending()) goto v0315;
    env = stack[-8];
    v0224 = stack[-5];
    v0224 = qcdr(v0224);
    stack[-5] = v0224;
    goto v0139;

v0003:
    v0224 = qcar(v0224);
    goto v0011;

v0095:
    v0224 = v0314;
    v0224 = qcdr(v0224);
    v0224 = qcar(v0224);
    goto v0022;

v0024:
    v0224 = qvalue(elt(env, 3)); /* nil */
    goto v0289;

v0027:
    v0224 = stack[-6];
    goto v0280;

v0280:
    v0313 = v0224;
    v0224 = v0313;
    v0224 = qcdr(v0224);
    if (v0224 == nil) goto v0317;
    v0224 = qvalue(elt(env, 7)); /* !'or */
    popv(9);
    return cons(v0224, v0313);

v0317:
    v0224 = v0313;
    v0224 = qcar(v0224);
    { popv(9); return onevalue(v0224); }

v0113:
    v0224 = qcar(v0224);
    goto v0111;

v0250:
    v0224 = v0314;
    v0224 = qcdr(v0224);
    v0224 = qcar(v0224);
    goto v0152;

v0171:
    v0224 = qvalue(elt(env, 3)); /* nil */
    goto v0146;

v0135:
    v0224 = qvalue(elt(env, 3)); /* nil */
    goto v0280;

v0076:
    v0224 = qvalue(elt(env, 2)); /* !'true */
    { popv(9); return onevalue(v0224); }
/* error exit handlers */
v0315:
    popv(9);
    return nil;
}



/* Code for monomcomparelex */

static Lisp_Object CC_monomcomparelex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0075)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0281, v0165, v0166;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monomcomparelex");
#endif
    if (stack >= stacklimit)
    {
        push2(v0075,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0075);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0075;
    v0281 = v0000;
/* end of prologue */
    v0166 = qvalue(elt(env, 1)); /* nil */
    v0165 = v0281;
    v0281 = (Lisp_Object)17; /* 1 */
    v0281 = *(Lisp_Object *)((char *)v0165 + (CELL-TAG_VECTOR) + ((int32_t)v0281/(16/CELL)));
    v0281 = cons(v0166, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-3];
    v0281 = Lreverse(nil, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-3];
    v0281 = qcdr(v0281);
    stack[-2] = v0281;
    v0166 = qvalue(elt(env, 1)); /* nil */
    v0165 = stack[0];
    v0281 = (Lisp_Object)17; /* 1 */
    v0281 = *(Lisp_Object *)((char *)v0165 + (CELL-TAG_VECTOR) + ((int32_t)v0281/(16/CELL)));
    v0281 = cons(v0166, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-3];
    v0281 = Lreverse(nil, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-3];
    v0281 = qcdr(v0281);
    stack[-1] = v0281;
    v0281 = (Lisp_Object)1; /* 0 */
    stack[0] = v0281;
    goto v0086;

v0086:
    v0281 = stack[-2];
    v0281 = qcar(v0281);
    if (v0281 == nil) goto v0105;
    v0281 = stack[-1];
    v0281 = qcar(v0281);
    if (v0281 == nil) goto v0105;
    v0281 = stack[-2];
    v0165 = qcar(v0281);
    v0281 = stack[-1];
    v0281 = qcar(v0281);
    v0281 = (Lisp_Object)lessp2(v0165, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    v0281 = v0281 ? lisp_true : nil;
    env = stack[-3];
    if (v0281 == nil) goto v0074;
    v0281 = (Lisp_Object)17; /* 1 */
    stack[0] = v0281;
    v0281 = qvalue(elt(env, 1)); /* nil */
    v0281 = ncons(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-3];
    stack[-2] = v0281;
    goto v0086;

v0074:
    v0281 = stack[-2];
    v0165 = qcar(v0281);
    v0281 = stack[-1];
    v0281 = qcar(v0281);
    v0281 = (Lisp_Object)greaterp2(v0165, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    v0281 = v0281 ? lisp_true : nil;
    env = stack[-3];
    if (v0281 == nil) goto v0277;
    v0281 = (Lisp_Object)-15; /* -1 */
    stack[0] = v0281;
    v0281 = qvalue(elt(env, 1)); /* nil */
    v0281 = ncons(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-3];
    stack[-2] = v0281;
    goto v0086;

v0277:
    v0281 = stack[-2];
    v0281 = qcdr(v0281);
    stack[-2] = v0281;
    v0281 = stack[-1];
    v0281 = qcdr(v0281);
    stack[-1] = v0281;
    goto v0086;

v0105:
    v0165 = stack[0];
    v0281 = (Lisp_Object)1; /* 0 */
    if (v0165 == v0281) goto v0273;
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0001;

v0001:
    if (v0281 == nil) goto v0109;
    v0281 = (Lisp_Object)17; /* 1 */
    stack[0] = v0281;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v0109:
    v0165 = stack[0];
    v0281 = (Lisp_Object)1; /* 0 */
    if (v0165 == v0281) goto v0285;
    v0281 = qvalue(elt(env, 1)); /* nil */
    goto v0298;

v0298:
    if (v0281 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0281 = (Lisp_Object)-15; /* -1 */
    stack[0] = v0281;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v0285:
    v0281 = stack[-1];
    v0281 = qcar(v0281);
    goto v0298;

v0273:
    v0281 = stack[-2];
    v0281 = qcar(v0281);
    goto v0001;
/* error exit handlers */
v0005:
    popv(4);
    return nil;
}



/* Code for impartf */

static Lisp_Object CC_impartf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for impartf");
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
    v0112 = elt(env, 1); /* i */
    v0114 = qvalue(elt(env, 2)); /* kord!* */
    v0114 = cons(v0112, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-4];
    stack[-3] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v0114; /* kord!* */
    v0114 = stack[0];
    fn = elt(env, 7); /* reorder */
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-4];
    stack[-2] = v0114;
    v0114 = stack[-2];
    if (!consp(v0114)) goto v0280;
    v0114 = stack[-2];
    v0114 = qcar(v0114);
    v0114 = (consp(v0114) ? nil : lisp_true);
    goto v0134;

v0134:
    if (v0114 == nil) goto v0034;
    v0114 = stack[-2];
    if (!consp(v0114)) goto v0138;
    v0114 = stack[-2];
    v0112 = qcar(v0114);
    v0114 = elt(env, 5); /* cmpxfn */
    v0114 = get(v0112, v0114);
    env = stack[-4];
    if (v0114 == nil) goto v0083;
    v0114 = stack[-2];
    stack[-1] = qcar(v0114);
    v0114 = stack[-2];
    v0114 = qcdr(v0114);
    stack[0] = qcdr(v0114);
    v0114 = stack[-2];
    v0112 = qcar(v0114);
    v0114 = elt(env, 6); /* i2d */
    v0112 = get(v0112, v0114);
    env = stack[-4];
    v0114 = (Lisp_Object)1; /* 0 */
    v0114 = Lapply1(nil, v0112, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-4];
    v0114 = qcdr(v0114);
    v0114 = qcar(v0114);
    v0114 = list2star(stack[-1], stack[0], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-4];
    fn = elt(env, 8); /* int!-equiv!-chk */
    v0114 = (*qfn1(fn))(qenv(fn), v0114);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-4];
    goto v0048;

v0048:
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    { popv(5); return onevalue(v0114); }

v0083:
    v0114 = qvalue(elt(env, 4)); /* nil */
    goto v0048;

v0138:
    v0114 = qvalue(elt(env, 4)); /* nil */
    goto v0048;

v0034:
    v0114 = stack[-2];
    v0114 = qcar(v0114);
    v0114 = qcar(v0114);
    v0112 = qcar(v0114);
    v0114 = elt(env, 1); /* i */
    if (v0112 == v0114) goto v0304;
    v0114 = stack[-2];
    v0114 = qcar(v0114);
    v0112 = qcar(v0114);
    v0114 = (Lisp_Object)17; /* 1 */
    v0114 = cons(v0112, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-4];
    stack[0] = ncons(v0114);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-4];
    v0114 = stack[-2];
    v0114 = qcar(v0114);
    v0114 = qcdr(v0114);
    v0114 = CC_impartf(env, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-4];
    fn = elt(env, 9); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-4];
    v0114 = stack[-2];
    v0114 = qcdr(v0114);
    v0114 = CC_impartf(env, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-4];
    fn = elt(env, 10); /* addf */
    v0114 = (*qfn2(fn))(qenv(fn), stack[0], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-4];
    goto v0048;

v0304:
    v0114 = stack[-2];
    v0114 = qcar(v0114);
    stack[0] = qcdr(v0114);
    v0114 = stack[-2];
    v0114 = qcdr(v0114);
    v0114 = CC_impartf(env, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-4];
    fn = elt(env, 10); /* addf */
    v0114 = (*qfn2(fn))(qenv(fn), stack[0], v0114);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-4];
    goto v0048;

v0280:
    v0114 = qvalue(elt(env, 3)); /* t */
    goto v0134;
/* error exit handlers */
v0166:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    popv(5);
    return nil;
v0165:
    popv(5);
    return nil;
}



setup_type const u41_setup[] =
{
    {"pasf_cein",               CC_pasf_cein,   too_many_1,    wrong_no_1},
    {"ctx_union",               too_few_2,      CC_ctx_union,  wrong_no_2},
    {"numir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_numir},
    {"i2crn*",                  CC_i2crnH,      too_many_1,    wrong_no_1},
    {"solvealgtrig01",          too_few_2,      CC_solvealgtrig01,wrong_no_2},
    {"add_item",                too_few_2,      CC_add_item,   wrong_no_2},
    {"gbftimes",                too_few_2,      CC_gbftimes,   wrong_no_2},
    {"kernelp",                 CC_kernelp,     too_many_1,    wrong_no_1},
    {"diff_vertex",             too_few_2,      CC_diff_vertex,wrong_no_2},
    {"setmatelem",              too_few_2,      CC_setmatelem, wrong_no_2},
    {"rfirst",                  CC_rfirst,      too_many_1,    wrong_no_1},
    {"bc_from_a",               CC_bc_from_a,   too_many_1,    wrong_no_1},
    {"st_sorttree1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_sorttree1},
    {"ofsf_bestgaussp",         CC_ofsf_bestgaussp,too_many_1, wrong_no_1},
    {"merge_lists",             too_few_2,      CC_merge_lists,wrong_no_2},
    {"replace-nth",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_replaceKnth},
    {"get*nr*real*irred*reps",  CC_getHnrHrealHirredHreps,too_many_1,wrong_no_1},
    {"mri_ofsf2mriat",          too_few_2,      CC_mri_ofsf2mriat,wrong_no_2},
    {"aex_red",                 too_few_2,      CC_aex_red,    wrong_no_2},
    {"operator_fn",             CC_operator_fn, too_many_1,    wrong_no_1},
    {"mkratnum",                CC_mkratnum,    too_many_1,    wrong_no_1},
    {"tp",                      CC_tp,          too_many_1,    wrong_no_1},
    {"fs:subang",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_fsTsubang},
    {"split-further",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_splitKfurther},
    {"zfactor1",                too_few_2,      CC_zfactor1,   wrong_no_2},
    {"janettreeinsert",         CC_janettreeinsert,too_many_1, wrong_no_1},
    {"subdf",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_subdf},
    {"tendstoml",               CC_tendstoml,   too_many_1,    wrong_no_1},
    {"parseml",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_parseml},
    {"getvariables",            CC_getvariables,too_many_1,    wrong_no_1},
    {"subscriptedvarp2",        CC_subscriptedvarp2,too_many_1,wrong_no_1},
    {"evalgeq",                 too_few_2,      CC_evalgeq,    wrong_no_2},
    {"f2dip2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_f2dip2},
    {"make_wedge_pair",         too_few_2,      CC_make_wedge_pair,wrong_no_2},
    {":dmexpt",                 too_few_2,      CC_Tdmexpt,    wrong_no_2},
    {"deletez1",                too_few_2,      CC_deletez1,   wrong_no_2},
    {"mapcarcar",               CC_mapcarcar,   too_many_1,    wrong_no_1},
    {"simp-prop-form",          CC_simpKpropKform,too_many_1,  wrong_no_1},
    {"monomcomparelex",         too_few_2,      CC_monomcomparelex,wrong_no_2},
    {"impartf",                 CC_impartf,     too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u41", (two_args *)"16785 86016 7645227", 0}
};

/* end of generated code */
