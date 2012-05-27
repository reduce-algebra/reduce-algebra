
/* $destdir\u10.c        Machine generated C code */

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


/* Code for plus!: */

static Lisp_Object CC_plusT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036, v0037, v0038, v0039;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for plus:");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0038 = v0001;
    v0039 = v0000;
/* end of prologue */
    v0036 = v0039;
    v0036 = qcdr(v0036);
    v0037 = qcar(v0036);
    stack[-1] = v0037;
    v0036 = (Lisp_Object)1; /* 0 */
    if (v0037 == v0036) { popv(6); return onevalue(v0038); }
    v0036 = v0038;
    v0036 = qcdr(v0036);
    v0037 = qcar(v0036);
    stack[0] = v0037;
    v0036 = (Lisp_Object)1; /* 0 */
    if (v0037 == v0036) { popv(6); return onevalue(v0039); }
    v0036 = v0039;
    v0036 = qcdr(v0036);
    v0036 = qcdr(v0036);
    stack[-4] = v0036;
    v0037 = v0038;
    v0037 = qcdr(v0037);
    v0037 = qcdr(v0037);
    stack[-2] = v0037;
    v0037 = difference2(v0036, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-5];
    stack[-3] = v0037;
    v0036 = (Lisp_Object)1; /* 0 */
    if (v0037 == v0036) goto v0041;
    v0037 = stack[-3];
    v0036 = (Lisp_Object)1; /* 0 */
    v0036 = (Lisp_Object)greaterp2(v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    v0036 = v0036 ? lisp_true : nil;
    env = stack[-5];
    if (v0036 == nil) goto v0042;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v0037 = stack[-1];
    v0036 = stack[-3];
    v0037 = Lash1(nil, v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-5];
    v0036 = stack[0];
    v0037 = plus2(v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    v0036 = stack[-2];
    {
        Lisp_Object v0043 = stack[-4];
        popv(6);
        return list2star(v0043, v0037, v0036);
    }

v0042:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v0036 = stack[-3];
    v0036 = negate(v0036);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-5];
    v0036 = Lash1(nil, stack[0], v0036);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-5];
    v0037 = plus2(stack[-1], v0036);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    v0036 = stack[-4];
    {
        Lisp_Object v0044 = stack[-2];
        popv(6);
        return list2star(v0044, v0037, v0036);
    }

v0041:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v0037 = stack[-1];
    v0036 = stack[0];
    v0037 = plus2(v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    v0036 = stack[-4];
    {
        Lisp_Object v0045 = stack[-2];
        popv(6);
        return list2star(v0045, v0037, v0036);
    }
/* error exit handlers */
v0040:
    popv(6);
    return nil;
}



/* Code for listsum */

static Lisp_Object CC_listsum(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0049;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listsum");
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
    stack[-1] = nil;
    goto v0016;

v0016:
    v0029 = stack[0];
    if (v0029 == nil) goto v0010;
    v0029 = stack[0];
    v0049 = qcar(v0029);
    v0029 = stack[-1];
    v0029 = cons(v0049, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-2];
    stack[-1] = v0029;
    v0029 = stack[0];
    v0029 = qcdr(v0029);
    stack[0] = v0029;
    goto v0016;

v0010:
    v0029 = (Lisp_Object)1; /* 0 */
    v0049 = v0029;
    goto v0051;

v0051:
    v0029 = stack[-1];
    if (v0029 == nil) { popv(3); return onevalue(v0049); }
    v0029 = stack[-1];
    v0029 = qcar(v0029);
    v0029 = plus2(v0029, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-2];
    v0049 = v0029;
    v0029 = stack[-1];
    v0029 = qcdr(v0029);
    stack[-1] = v0029;
    goto v0051;
/* error exit handlers */
v0050:
    popv(3);
    return nil;
}



/* Code for scalopp */

static Lisp_Object CC_scalopp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0089, v0090;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scalopp");
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
    v0088 = stack[-3];
    if (symbolp(v0088)) goto v0091;
    v0088 = qvalue(elt(env, 1)); /* nil */
    goto v0016;

v0016:
    if (!(v0088 == nil)) { popv(6); return onevalue(v0088); }
    v0088 = stack[-3];
    if (!consp(v0088)) goto v0092;
    v0088 = stack[-3];
    v0089 = qcar(v0088);
    v0088 = elt(env, 2); /* phystype */
    v0089 = get(v0089, v0088);
    env = stack[-5];
    v0088 = elt(env, 3); /* scalar */
    if (v0089 == v0088) goto v0093;
    v0088 = stack[-3];
    v0089 = qcar(v0088);
    v0088 = elt(env, 2); /* phystype */
    v0089 = get(v0089, v0088);
    env = stack[-5];
    v0088 = elt(env, 5); /* vector */
    if (v0089 == v0088) goto v0094;
    v0088 = qvalue(elt(env, 1)); /* nil */
    goto v0095;

v0095:
    if (!(v0088 == nil)) { popv(6); return onevalue(v0088); }
    v0088 = stack[-3];
    v0089 = qcar(v0088);
    v0088 = elt(env, 2); /* phystype */
    v0089 = get(v0089, v0088);
    env = stack[-5];
    v0088 = elt(env, 6); /* tensor */
    if (v0089 == v0088) goto v0015;
    v0088 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0088); }

v0015:
    v0088 = stack[-3];
    v0088 = qcdr(v0088);
    v0090 = Llength(nil, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    v0088 = stack[-3];
    v0089 = qcar(v0088);
    v0088 = elt(env, 7); /* tensdimen */
    v0088 = get(v0089, v0088);
    env = stack[-5];
    v0088 = (Lisp_Object)geq2(v0090, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    v0088 = v0088 ? lisp_true : nil;
    env = stack[-5];
    if (v0088 == nil) goto v0019;
    v0088 = (Lisp_Object)17; /* 1 */
    stack[-4] = v0088;
    v0088 = stack[-3];
    v0089 = qcar(v0088);
    v0088 = elt(env, 7); /* tensdimen */
    v0089 = get(v0089, v0088);
    env = stack[-5];
    v0088 = stack[-4];
    v0088 = difference2(v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    v0088 = Lminusp(nil, v0088);
    env = stack[-5];
    if (v0088 == nil) goto v0097;
    v0088 = qvalue(elt(env, 1)); /* nil */
    goto v0008;

v0008:
    {
        popv(6);
        fn = elt(env, 8); /* areallindices */
        return (*qfn1(fn))(qenv(fn), v0088);
    }

v0097:
    v0088 = stack[-3];
    v0089 = qcdr(v0088);
    v0088 = stack[-4];
    fn = elt(env, 9); /* pnth */
    v0088 = (*qfn2(fn))(qenv(fn), v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    v0088 = qcar(v0088);
    v0088 = ncons(v0088);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    stack[-1] = v0088;
    stack[-2] = v0088;
    goto v0009;

v0009:
    v0088 = stack[-4];
    v0088 = add1(v0088);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    stack[-4] = v0088;
    v0088 = stack[-3];
    v0089 = qcar(v0088);
    v0088 = elt(env, 7); /* tensdimen */
    v0089 = get(v0089, v0088);
    env = stack[-5];
    v0088 = stack[-4];
    v0088 = difference2(v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    v0088 = Lminusp(nil, v0088);
    env = stack[-5];
    if (v0088 == nil) goto v0098;
    v0088 = stack[-2];
    goto v0008;

v0098:
    stack[0] = stack[-1];
    v0088 = stack[-3];
    v0089 = qcdr(v0088);
    v0088 = stack[-4];
    fn = elt(env, 9); /* pnth */
    v0088 = (*qfn2(fn))(qenv(fn), v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    v0088 = qcar(v0088);
    v0088 = ncons(v0088);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    v0088 = Lrplacd(nil, stack[0], v0088);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    v0088 = stack[-1];
    v0088 = qcdr(v0088);
    stack[-1] = v0088;
    goto v0009;

v0019:
    v0088 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0088); }

v0094:
    v0088 = stack[-3];
    v0088 = qcdr(v0088);
    v0088 = qcar(v0088);
    fn = elt(env, 10); /* isanindex */
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    goto v0095;

v0093:
    v0088 = qvalue(elt(env, 4)); /* t */
    { popv(6); return onevalue(v0088); }

v0092:
    v0088 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0088); }

v0091:
    v0089 = stack[-3];
    v0088 = elt(env, 2); /* phystype */
    v0089 = get(v0089, v0088);
    env = stack[-5];
    v0088 = elt(env, 3); /* scalar */
    v0088 = (v0089 == v0088 ? lisp_true : nil);
    goto v0016;
/* error exit handlers */
v0096:
    popv(6);
    return nil;
}



/* Code for sqp */

static Lisp_Object CC_sqp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqp");
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
    v0086 = stack[0];
    v0086 = Lconsp(nil, v0086);
    env = stack[-1];
    if (v0086 == nil) goto v0011;
    v0086 = stack[0];
    v0086 = qcar(v0086);
    fn = elt(env, 2); /* sfpx */
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-1];
    if (v0086 == nil) goto v0099;
    v0086 = stack[0];
    v0086 = qcdr(v0086);
    {
        popv(2);
        fn = elt(env, 2); /* sfpx */
        return (*qfn1(fn))(qenv(fn), v0086);
    }

v0099:
    v0086 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0086); }

v0011:
    v0086 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0086); }
/* error exit handlers */
v0085:
    popv(2);
    return nil;
}



/* Code for mv!-pow!-!+ */

static Lisp_Object CC_mvKpowKL(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0103, v0104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-+");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0016;

v0016:
    v0103 = stack[-1];
    if (v0103 == nil) goto v0105;
    v0103 = stack[-1];
    v0104 = qcar(v0103);
    v0103 = stack[0];
    v0103 = qcar(v0103);
    v0104 = plus2(v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-3];
    v0103 = stack[-2];
    v0103 = cons(v0104, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-3];
    stack[-2] = v0103;
    v0103 = stack[-1];
    v0103 = qcdr(v0103);
    stack[-1] = v0103;
    v0103 = stack[0];
    v0103 = qcdr(v0103);
    stack[0] = v0103;
    goto v0016;

v0105:
    v0103 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0103);
    }
/* error exit handlers */
v0081:
    popv(4);
    return nil;
}



/* Code for subs3f1 */

static Lisp_Object MS_CDECL CC_subs3f1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0048, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0064, v0065, v0118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subs3f1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs3f1");
#endif
    if (stack >= stacklimit)
    {
        push3(v0048,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0048);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0048;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0065 = qvalue(elt(env, 1)); /* nil */
    v0064 = (Lisp_Object)17; /* 1 */
    v0064 = cons(v0065, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-4];
    stack[-3] = v0064;
    goto v0051;

v0051:
    v0064 = stack[-2];
    if (v0064 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v0064 = stack[-2];
    if (!consp(v0064)) goto v0101;
    v0064 = stack[-2];
    v0064 = qcar(v0064);
    v0064 = (consp(v0064) ? nil : lisp_true);
    goto v0120;

v0120:
    if (v0064 == nil) goto v0085;
    stack[0] = stack[-3];
    v0065 = stack[-2];
    v0064 = (Lisp_Object)17; /* 1 */
    v0064 = cons(v0065, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-4];
    {
        Lisp_Object v0121 = stack[0];
        popv(5);
        fn = elt(env, 7); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0121, v0064);
    }

v0085:
    v0064 = stack[0];
    if (v0064 == nil) goto v0079;
    v0064 = stack[-2];
    v0064 = qcar(v0064);
    v0064 = qcdr(v0064);
    if (!consp(v0064)) goto v0094;
    v0064 = stack[-2];
    v0064 = qcar(v0064);
    v0064 = qcdr(v0064);
    v0064 = qcar(v0064);
    v0064 = (consp(v0064) ? nil : lisp_true);
    goto v0095;

v0095:
    if (v0064 == nil) goto v0079;
    v0064 = stack[-2];
    v0064 = qcar(v0064);
    v0065 = ncons(v0064);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-4];
    v0064 = (Lisp_Object)17; /* 1 */
    v0064 = cons(v0065, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-4];
    v0118 = v0064;
    goto v0043;

v0043:
    v0064 = stack[-3];
    v0065 = v0118;
    fn = elt(env, 7); /* addsq */
    v0064 = (*qfn2(fn))(qenv(fn), v0064, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-4];
    stack[-3] = v0064;
    v0064 = stack[-2];
    v0064 = qcdr(v0064);
    stack[-2] = v0064;
    goto v0051;

v0079:
    v0064 = stack[-2];
    v0065 = qcar(v0064);
    v0064 = stack[-1];
    fn = elt(env, 8); /* subs3t */
    v0064 = (*qfn2(fn))(qenv(fn), v0065, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-4];
    v0118 = v0064;
    v0064 = stack[0];
    if (v0064 == nil) goto v0122;
    v0064 = qvalue(elt(env, 3)); /* mchfg!* */
    v0064 = (v0064 == nil ? lisp_true : nil);
    goto v0123;

v0123:
    if (!(v0064 == nil)) goto v0043;
    v0064 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 3)) = v0064; /* mchfg!* */
    v0064 = v0118;
    v0065 = qcar(v0064);
    v0064 = stack[-2];
    if (equal(v0065, v0064)) goto v0069;
    v0064 = qvalue(elt(env, 1)); /* nil */
    goto v0073;

v0073:
    if (v0064 == nil) goto v0074;
    v0065 = stack[-2];
    v0064 = (Lisp_Object)17; /* 1 */
    v0064 = cons(v0065, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-4];
    v0118 = v0064;
    goto v0043;

v0074:
    v0064 = qvalue(elt(env, 4)); /* !*resubs */
    if (v0064 == nil) goto v0043;
    v0064 = qvalue(elt(env, 5)); /* !*sub2 */
    if (!(v0064 == nil)) goto v0004;
    v0064 = qvalue(elt(env, 6)); /* powlis1!* */
    if (!(v0064 == nil)) goto v0004;

v0124:
    v0064 = v0118;
    fn = elt(env, 9); /* subs3q */
    v0064 = (*qfn1(fn))(qenv(fn), v0064);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-4];
    v0118 = v0064;
    goto v0043;

v0004:
    v0064 = v0118;
    fn = elt(env, 10); /* subs2q */
    v0064 = (*qfn1(fn))(qenv(fn), v0064);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-4];
    v0118 = v0064;
    goto v0124;

v0069:
    v0064 = v0118;
    v0065 = qcdr(v0064);
    v0064 = (Lisp_Object)17; /* 1 */
    v0064 = (v0065 == v0064 ? lisp_true : nil);
    goto v0073;

v0122:
    v0064 = qvalue(elt(env, 2)); /* t */
    goto v0123;

v0094:
    v0064 = qvalue(elt(env, 2)); /* t */
    goto v0095;

v0101:
    v0064 = qvalue(elt(env, 2)); /* t */
    goto v0120;
/* error exit handlers */
v0119:
    popv(5);
    return nil;
}



/* Code for gcddd */

static Lisp_Object CC_gcddd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0133, v0134, v0108, v0109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcddd");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0134 = v0001;
    v0108 = v0000;
/* end of prologue */
    v0109 = v0108;
    v0133 = (Lisp_Object)17; /* 1 */
    if (v0109 == v0133) goto v0105;
    v0109 = v0134;
    v0133 = (Lisp_Object)17; /* 1 */
    v0133 = (v0109 == v0133 ? lisp_true : nil);
    goto v0051;

v0051:
    if (v0133 == nil) goto v0016;
    v0133 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v0133); }

v0016:
    v0133 = v0108;
    if (!consp(v0133)) goto v0135;
    v0133 = v0134;
    if (!consp(v0133)) goto v0123;
    v0133 = v0108;
    v0109 = qcar(v0133);
    v0133 = elt(env, 2); /* field */
    v0133 = Lflagp(nil, v0109, v0133);
    env = stack[0];
    if (v0133 == nil) goto v0136;
    v0133 = qvalue(elt(env, 1)); /* t */
    goto v0042;

v0042:
    if (v0133 == nil) goto v0137;
    v0133 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v0133); }

v0137:
    v0133 = elt(env, 4); /* gcd */
    {
        popv(1);
        fn = elt(env, 5); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0108, v0134, v0133);
    }

v0136:
    v0133 = v0134;
    v0109 = qcar(v0133);
    v0133 = elt(env, 2); /* field */
    v0133 = Lflagp(nil, v0109, v0133);
    env = stack[0];
    goto v0042;

v0123:
    v0133 = v0108;
    v0109 = qcar(v0133);
    v0133 = elt(env, 2); /* field */
    v0133 = Lflagp(nil, v0109, v0133);
    env = stack[0];
    if (v0133 == nil) goto v0138;
    v0133 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v0133); }

v0138:
    v0133 = elt(env, 4); /* gcd */
    {
        popv(1);
        fn = elt(env, 5); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0108, v0134, v0133);
    }

v0135:
    v0133 = v0134;
    if (!consp(v0133)) goto v0046;
    v0133 = v0134;
    if (!consp(v0133)) goto v0139;
    v0133 = v0134;
    v0109 = qcar(v0133);
    v0133 = elt(env, 2); /* field */
    v0133 = Lflagp(nil, v0109, v0133);
    env = stack[0];
    goto v0082;

v0082:
    if (v0133 == nil) goto v0025;
    v0133 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v0133); }

v0025:
    v0133 = elt(env, 4); /* gcd */
    {
        popv(1);
        fn = elt(env, 5); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0108, v0134, v0133);
    }

v0139:
    v0133 = qvalue(elt(env, 3)); /* nil */
    goto v0082;

v0046:
    v0133 = v0108;
        popv(1);
        return Lgcd(nil, v0133, v0134);

v0105:
    v0133 = qvalue(elt(env, 1)); /* t */
    goto v0051;
}



/* Code for adddummy1a */

static Lisp_Object MS_CDECL CC_adddummy1a(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0048, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0139, v0141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "adddummy1a");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for adddummy1a");
#endif
    if (stack >= stacklimit)
    {
        push3(v0048,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0048);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0048;
    v0139 = v0001;
    stack[-2] = v0000;
/* end of prologue */

v0010:
    v0141 = v0139;
    if (v0141 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0141 = v0139;
    v0141 = qcdr(v0141);
    stack[-3] = v0141;
    v0141 = stack[-1];
    if (v0141 == nil) goto v0085;
    v0141 = stack[-1];
    v0141 = qcar(v0141);
    stack[0] = v0141;
    goto v0081;

v0081:
    v0141 = qcar(v0139);
    v0139 = stack[-2];
    v0139 = qcdr(v0139);
    fn = elt(env, 1); /* pappl_pv */
    v0141 = (*qfn2(fn))(qenv(fn), v0141, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-4];
    v0139 = stack[-1];
    if (v0139 == nil) goto v0143;
    v0139 = stack[-1];
    v0139 = qcdr(v0139);
    goto v0046;

v0046:
    fn = elt(env, 2); /* insert_pv */
    v0139 = (*qfn2(fn))(qenv(fn), v0141, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-4];
    v0139 = cons(stack[0], v0139);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-4];
    stack[-1] = v0139;
    v0139 = stack[-3];
    goto v0010;

v0143:
    v0139 = stack[-1];
    goto v0046;

v0085:
    v0141 = stack[-2];
    v0141 = qcar(v0141);
    stack[0] = v0141;
    goto v0081;
/* error exit handlers */
v0142:
    popv(5);
    return nil;
}



/* Code for idcons_ordp */

static Lisp_Object CC_idcons_ordp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0146, v0147, v0132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for idcons_ordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0146 = v0001;
    v0147 = v0000;
/* end of prologue */
    v0132 = v0147;
    v0147 = v0146;
    v0146 = elt(env, 1); /* atom_compare */
    {
        fn = elt(env, 2); /* cons_ordp */
        return (*qfnn(fn))(qenv(fn), 3, v0132, v0147, v0146);
    }
}



/* Code for clear!-column */

static Lisp_Object MS_CDECL CC_clearKcolumn(Lisp_Object env, int nargs,
                         Lisp_Object v0001, Lisp_Object v0048,
                         Lisp_Object v0012, Lisp_Object v0011, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0199, v0200, v0201, v0202, v0203, v0204, v0205, v0206, v0207, v0208;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "clear-column");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clear-column");
#endif
    if (stack >= stacklimit)
    {
        push4(v0011,v0012,v0048,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0001,v0048,v0012,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0012;
    v0199 = v0048;
    stack[-2] = v0001;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* null!-space!-basis */
    qvalue(elt(env, 1)) = nil; /* null!-space!-basis */
    qvalue(elt(env, 1)) = v0199; /* null!-space!-basis */
    v0199 = (Lisp_Object)1; /* 0 */
    goto v0032;

v0032:
    v0201 = stack[-1];
    v0200 = v0199;
    v0201 = *(Lisp_Object *)((char *)v0201 + (CELL-TAG_VECTOR) + ((int32_t)v0200/(16/CELL)));
    v0200 = stack[-2];
    v0201 = *(Lisp_Object *)((char *)v0201 + (CELL-TAG_VECTOR) + ((int32_t)v0200/(16/CELL)));
    v0200 = (Lisp_Object)1; /* 0 */
    if (v0201 == v0200) goto v0035;
    v0201 = v0199;
    v0200 = stack[-2];
    if (((int32_t)(v0201)) < ((int32_t)(v0200))) goto v0027;
    v0200 = qvalue(elt(env, 3)); /* nil */
    goto v0034;

v0034:
    if (v0200 == nil) goto v0018;
    v0201 = (Lisp_Object)((int32_t)(v0199) + 0x10);
    v0199 = v0201;
    v0200 = stack[0];
    if (!(((int32_t)(v0201)) > ((int32_t)(v0200)))) goto v0032;
    v0200 = stack[-2];
    v0199 = qvalue(elt(env, 1)); /* null!-space!-basis */
    v0199 = cons(v0200, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-4];
    goto v0051;

v0051:
    qvalue(elt(env, 1)) = stack[-3]; /* null!-space!-basis */
    { popv(5); return onevalue(v0199); }

v0018:
    v0201 = stack[-1];
    v0200 = v0199;
    v0200 = *(Lisp_Object *)((char *)v0201 + (CELL-TAG_VECTOR) + ((int32_t)v0200/(16/CELL)));
    v0208 = v0200;
    v0202 = stack[-1];
    v0201 = v0199;
    v0200 = stack[-1];
    v0199 = stack[-2];
    v0199 = *(Lisp_Object *)((char *)v0200 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL)));
    *(Lisp_Object *)((char *)v0202 + (CELL-TAG_VECTOR) + ((int32_t)v0201/(16/CELL))) = v0199;
    v0200 = stack[-1];
    v0199 = stack[-2];
    v0201 = v0208;
    *(Lisp_Object *)((char *)v0200 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL))) = v0201;
    v0200 = stack[-1];
    v0199 = stack[-2];
    v0200 = *(Lisp_Object *)((char *)v0200 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL)));
    v0199 = stack[-2];
    v0199 = *(Lisp_Object *)((char *)v0200 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL)));
    v0199 = Lmodular_reciprocal(nil, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v0199);
        if (w != 0) w = current_modulus - w;
        v0199 = fixnum_of_int(w);
    }
    v0208 = v0199;
    v0199 = (Lisp_Object)1; /* 0 */
    v0207 = v0199;
    goto v0118;

v0118:
    v0200 = stack[0];
    v0199 = v0207;
    v0199 = (Lisp_Object)(int32_t)((int32_t)v0200 - (int32_t)v0199 + TAG_FIXNUM);
    v0199 = ((intptr_t)(v0199) < 0 ? lisp_true : nil);
    if (v0199 == nil) goto v0060;
    v0199 = stack[-2];
    v0203 = v0199;
    goto v0210;

v0210:
    v0200 = stack[0];
    v0199 = v0203;
    v0199 = (Lisp_Object)(int32_t)((int32_t)v0200 - (int32_t)v0199 + TAG_FIXNUM);
    v0199 = ((intptr_t)(v0199) < 0 ? lisp_true : nil);
    if (v0199 == nil) goto v0211;
    v0199 = qvalue(elt(env, 1)); /* null!-space!-basis */
    goto v0051;

v0211:
    v0200 = stack[-1];
    v0199 = stack[-2];
    v0202 = *(Lisp_Object *)((char *)v0200 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL)));
    v0201 = v0203;
    v0200 = stack[-1];
    v0199 = stack[-2];
    v0200 = *(Lisp_Object *)((char *)v0200 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL)));
    v0199 = v0203;
    v0200 = *(Lisp_Object *)((char *)v0200 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL)));
    v0199 = v0208;
    v0199 = Lmodular_times(nil, v0200, v0199);
    env = stack[-4];
    *(Lisp_Object *)((char *)v0202 + (CELL-TAG_VECTOR) + ((int32_t)v0201/(16/CELL))) = v0199;
    v0199 = v0203;
    v0199 = (Lisp_Object)((int32_t)(v0199) + 0x10);
    v0203 = v0199;
    goto v0210;

v0060:
    v0200 = v0207;
    v0199 = stack[-2];
    if (equal(v0200, v0199)) goto v0212;
    v0200 = stack[-1];
    v0199 = v0207;
    v0200 = *(Lisp_Object *)((char *)v0200 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL)));
    v0199 = stack[-2];
    v0199 = *(Lisp_Object *)((char *)v0200 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL)));
    v0206 = v0199;
    v0200 = v0206;
    v0199 = (Lisp_Object)1; /* 0 */
    if (v0200 == v0199) goto v0212;
    v0200 = v0206;
    v0199 = v0208;
    v0199 = Lmodular_times(nil, v0200, v0199);
    env = stack[-4];
    v0206 = v0199;
    v0199 = stack[-2];
    v0205 = v0199;
    goto v0213;

v0213:
    v0200 = stack[0];
    v0199 = v0205;
    v0199 = (Lisp_Object)(int32_t)((int32_t)v0200 - (int32_t)v0199 + TAG_FIXNUM);
    v0199 = ((intptr_t)(v0199) < 0 ? lisp_true : nil);
    if (!(v0199 == nil)) goto v0212;
    v0200 = stack[-1];
    v0199 = v0207;
    v0204 = *(Lisp_Object *)((char *)v0200 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL)));
    v0203 = v0205;
    v0200 = stack[-1];
    v0199 = v0207;
    v0200 = *(Lisp_Object *)((char *)v0200 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL)));
    v0199 = v0205;
    v0202 = *(Lisp_Object *)((char *)v0200 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL)));
    v0201 = v0206;
    v0200 = stack[-1];
    v0199 = stack[-2];
    v0200 = *(Lisp_Object *)((char *)v0200 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL)));
    v0199 = v0205;
    v0199 = *(Lisp_Object *)((char *)v0200 + (CELL-TAG_VECTOR) + ((int32_t)v0199/(16/CELL)));
    v0199 = Lmodular_times(nil, v0201, v0199);
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v0202) + int_of_fixnum(v0199);
        if (w >= current_modulus) w -= current_modulus;
        v0199 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v0204 + (CELL-TAG_VECTOR) + ((int32_t)v0203/(16/CELL))) = v0199;
    v0199 = v0205;
    v0199 = (Lisp_Object)((int32_t)(v0199) + 0x10);
    v0205 = v0199;
    goto v0213;

v0212:
    v0199 = v0207;
    v0199 = (Lisp_Object)((int32_t)(v0199) + 0x10);
    v0207 = v0199;
    goto v0118;

v0027:
    v0201 = stack[-1];
    v0200 = v0199;
    v0201 = *(Lisp_Object *)((char *)v0201 + (CELL-TAG_VECTOR) + ((int32_t)v0200/(16/CELL)));
    v0200 = v0199;
    v0201 = *(Lisp_Object *)((char *)v0201 + (CELL-TAG_VECTOR) + ((int32_t)v0200/(16/CELL)));
    v0200 = (Lisp_Object)1; /* 0 */
    v0200 = (v0201 == v0200 ? lisp_true : nil);
    v0200 = (v0200 == nil ? lisp_true : nil);
    goto v0034;

v0035:
    v0200 = qvalue(elt(env, 2)); /* t */
    goto v0034;
/* error exit handlers */
v0209:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* null!-space!-basis */
    popv(5);
    return nil;
}



/* Code for setpage */

static Lisp_Object CC_setpage(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0051;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setpage");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0051 = v0001;
    v0010 = v0000;
/* end of prologue */
    qvalue(elt(env, 1)) = v0010; /* title!* */
    v0010 = v0051;
    qvalue(elt(env, 2)) = v0010; /* pgnum!* */
    v0010 = nil;
    return onevalue(v0010);
}



/* Code for mkkl */

static Lisp_Object CC_mkkl(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0120, v0101, v0135;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkkl");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0120 = v0001;
    v0101 = v0000;
/* end of prologue */

v0016:
    v0135 = v0101;
    if (v0135 == nil) { popv(2); return onevalue(v0120); }
    v0135 = v0101;
    v0135 = qcdr(v0135);
    stack[0] = v0135;
    v0101 = qcar(v0101);
    v0120 = cons(v0101, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-1];
    v0101 = stack[0];
    goto v0016;
/* error exit handlers */
v0100:
    popv(2);
    return nil;
}



/* Code for split_f */

static Lisp_Object MS_CDECL CC_split_f(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0048, Lisp_Object v0012, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0224, v0053, v0054, v0225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "split_f");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split_f");
#endif
    if (stack >= stacklimit)
    {
        push4(v0012,v0048,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0048,v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0012;
    stack[-4] = v0048;
    stack[-5] = v0001;
    stack[-6] = v0000;
/* end of prologue */

v0051:
    v0224 = stack[-6];
    if (v0224 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    v0224 = stack[-6];
    if (!consp(v0224)) goto v0091;
    v0224 = stack[-6];
    v0224 = qcar(v0224);
    v0224 = (consp(v0224) ? nil : lisp_true);
    goto v0084;

v0084:
    if (v0224 == nil) goto v0132;
    v0053 = stack[-4];
    v0224 = stack[-6];
    fn = elt(env, 5); /* multf */
    v0053 = (*qfn2(fn))(qenv(fn), v0053, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-8];
    v0224 = stack[-3];
    v0224 = qcar(v0224);
    fn = elt(env, 6); /* addf */
    v0053 = (*qfn2(fn))(qenv(fn), v0053, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    v0224 = stack[-3];
    v0224 = qcdr(v0224);
    popv(9);
    return cons(v0053, v0224);

v0132:
    v0224 = stack[-6];
    v0224 = qcar(v0224);
    v0224 = qcar(v0224);
    v0224 = qcar(v0224);
    if (!consp(v0224)) goto v0079;
    v0224 = stack[-6];
    v0224 = qcar(v0224);
    v0224 = qcar(v0224);
    v0224 = qcar(v0224);
    v0053 = qcar(v0224);
    v0224 = stack[-5];
    v0224 = Lmember(nil, v0053, v0224);
    goto v0028;

v0028:
    if (v0224 == nil) goto v0097;
    v0224 = stack[-6];
    v0224 = qcar(v0224);
    v0224 = qcar(v0224);
    v0053 = qcdr(v0224);
    v0224 = (Lisp_Object)17; /* 1 */
    if (v0053 == v0224) goto v0017;
    v0224 = qvalue(elt(env, 1)); /* t */
    goto v0021;

v0021:
    if (v0224 == nil) goto v0052;
    stack[0] = elt(env, 3); /* "SPLIT_F: expression not linear w.r.t." 
*/
    v0053 = elt(env, 4); /* list */
    v0224 = stack[-5];
    v0225 = cons(v0053, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-8];
    v0054 = qvalue(elt(env, 2)); /* nil */
    v0053 = qvalue(elt(env, 2)); /* nil */
    v0224 = qvalue(elt(env, 1)); /* t */
    {
        Lisp_Object v0227 = stack[0];
        popv(9);
        fn = elt(env, 7); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v0227, v0225, v0054, v0053, v0224);
    }

v0052:
    v0224 = stack[-6];
    v0224 = qcdr(v0224);
    stack[-7] = v0224;
    stack[-1] = stack[-3];
    v0224 = stack[-6];
    v0224 = qcar(v0224);
    v0224 = qcar(v0224);
    stack[0] = qcar(v0224);
    v0053 = stack[-4];
    v0224 = stack[-6];
    v0224 = qcar(v0224);
    v0224 = qcdr(v0224);
    fn = elt(env, 5); /* multf */
    v0224 = (*qfn2(fn))(qenv(fn), v0053, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-8];
    fn = elt(env, 8); /* update_kc_list */
    v0224 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0224);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-8];
    stack[-3] = v0224;
    v0224 = stack[-7];
    stack[-6] = v0224;
    goto v0051;

v0017:
    v0224 = stack[-6];
    v0224 = qcar(v0224);
    v0053 = qcdr(v0224);
    v0224 = stack[-5];
    fn = elt(env, 9); /* get_first_kernel */
    v0224 = (*qfn2(fn))(qenv(fn), v0053, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-8];
    goto v0021;

v0097:
    v0224 = stack[-6];
    v0224 = qcdr(v0224);
    stack[-7] = v0224;
    v0224 = stack[-6];
    v0224 = qcar(v0224);
    stack[-2] = qcdr(v0224);
    stack[-1] = stack[-5];
    stack[0] = stack[-4];
    v0224 = stack[-6];
    v0224 = qcar(v0224);
    v0053 = qcar(v0224);
    v0224 = (Lisp_Object)17; /* 1 */
    v0224 = cons(v0053, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-8];
    v0224 = ncons(v0224);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-8];
    fn = elt(env, 5); /* multf */
    v0053 = (*qfn2(fn))(qenv(fn), stack[0], v0224);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-8];
    v0224 = stack[-3];
    v0224 = CC_split_f(env, 4, stack[-2], stack[-1], v0053, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-8];
    stack[-3] = v0224;
    v0224 = stack[-7];
    stack[-6] = v0224;
    goto v0051;

v0079:
    v0224 = qvalue(elt(env, 2)); /* nil */
    goto v0028;

v0091:
    v0224 = qvalue(elt(env, 1)); /* t */
    goto v0084;
/* error exit handlers */
v0226:
    popv(9);
    return nil;
}



/* Code for totalcompare */

static Lisp_Object CC_totalcompare(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0122, v0230, v0231;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for totalcompare");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0010:
    v0230 = stack[-1];
    v0122 = stack[0];
    if (equal(v0230, v0122)) goto v0005;
    v0230 = stack[-1];
    v0122 = stack[0];
    fn = elt(env, 4); /* wulessp */
    v0122 = (*qfn2(fn))(qenv(fn), v0230, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    if (v0122 == nil) goto v0101;
    v0122 = elt(env, 2); /* less */
    { popv(3); return onevalue(v0122); }

v0101:
    v0230 = stack[0];
    v0122 = stack[-1];
    fn = elt(env, 4); /* wulessp */
    v0122 = (*qfn2(fn))(qenv(fn), v0230, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    if (v0122 == nil) goto v0116;
    v0122 = elt(env, 3); /* greater */
    { popv(3); return onevalue(v0122); }

v0116:
    v0122 = stack[-1];
    fn = elt(env, 5); /* wuconstantp */
    v0122 = (*qfn1(fn))(qenv(fn), v0122);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    if (v0122 == nil) goto v0028;
    v0230 = stack[-1];
    v0122 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* totalcompareconstants */
        return (*qfn2(fn))(qenv(fn), v0230, v0122);
    }

v0028:
    v0122 = stack[-1];
    v0122 = qcar(v0122);
    v0230 = qcdr(v0122);
    v0122 = stack[0];
    v0122 = qcar(v0122);
    v0122 = qcdr(v0122);
    v0122 = CC_totalcompare(env, v0230, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    v0231 = v0122;
    v0230 = v0231;
    v0122 = elt(env, 1); /* equal */
    if (!(v0230 == v0122)) { popv(3); return onevalue(v0231); }
    v0122 = stack[-1];
    v0230 = qcdr(v0122);
    v0122 = stack[0];
    v0122 = qcdr(v0122);
    stack[-1] = v0230;
    stack[0] = v0122;
    goto v0010;

v0005:
    v0122 = elt(env, 1); /* equal */
    { popv(3); return onevalue(v0122); }
/* error exit handlers */
v0013:
    popv(3);
    return nil;
}



/* Code for intexprnp */

static Lisp_Object CC_intexprnp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0128, v0129, v0198, v0112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intexprnp");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0129 = v0001;
    v0198 = v0000;
/* end of prologue */
    v0128 = qvalue(elt(env, 1)); /* !*revalp */
    if (v0128 == nil) goto v0005;
    v0128 = v0198;
    if (!consp(v0128)) goto v0105;
    v0128 = v0198;
    v0128 = qcar(v0128);
    if (symbolp(v0128)) goto v0041;
    v0128 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0128); }

v0041:
    v0128 = v0198;
    v0112 = qcar(v0128);
    v0128 = elt(env, 4); /* intfn */
    v0128 = Lflagp(nil, v0112, v0128);
    env = stack[0];
    if (v0128 == nil) goto v0079;
    v0128 = v0198;
    v0128 = qcdr(v0128);
    {
        popv(1);
        fn = elt(env, 5); /* intexprlisp */
        return (*qfn2(fn))(qenv(fn), v0128, v0129);
    }

v0079:
    v0128 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0128); }

v0105:
    v0128 = v0198;
    if (is_number(v0128)) goto v0146;
    v0128 = v0198;
    v0128 = Latsoc(nil, v0128, v0129);
    v0198 = v0128;
    if (v0128 == nil) goto v0104;
    v0128 = v0198;
    v0128 = qcdr(v0128);
    v0129 = elt(env, 3); /* integer */
    v0128 = (v0128 == v0129 ? lisp_true : nil);
    { popv(1); return onevalue(v0128); }

v0104:
    v0128 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0128); }

v0146:
    v0128 = v0198;
    v0128 = integerp(v0128);
    { popv(1); return onevalue(v0128); }

v0005:
    v0128 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0128); }
}



/* Code for rl_external */

static Lisp_Object CC_rl_external(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0093, v0232;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_external");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0232 = v0001;
    v0032 = v0000;
/* end of prologue */
    v0093 = v0032;
    v0032 = elt(env, 0); /* rl_external */
    v0032 = get(v0093, v0032);
    v0093 = v0032;
    v0032 = v0093;
    if (v0032 == nil) goto v0147;
    v0032 = v0232;
    v0032 = Latsoc(nil, v0032, v0093);
    v0093 = v0032;
    v0032 = v0093;
    if (v0032 == nil) goto v0147;
    v0032 = v0093;
    v0032 = qcdr(v0032);
    return onevalue(v0032);

v0147:
    v0032 = nil;
    return onevalue(v0032);
}



/* Code for aex_deg */

static Lisp_Object CC_aex_deg(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0145, v0099;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_deg");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0145 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v0099 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-1];
    v0145 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* ratpoly_deg */
        return (*qfn2(fn))(qenv(fn), v0099, v0145);
    }
/* error exit handlers */
v0147:
    popv(2);
    return nil;
}



/* Code for omvir */

static Lisp_Object MS_CDECL CC_omvir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0143, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omvir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omvir");
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
    v0031 = qvalue(elt(env, 1)); /* atts */
    v0143 = elt(env, 2); /* name */
    fn = elt(env, 6); /* find */
    v0143 = (*qfn2(fn))(qenv(fn), v0031, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-1];
    stack[0] = v0143;
    v0031 = qvalue(elt(env, 1)); /* atts */
    v0143 = elt(env, 3); /* hex */
    fn = elt(env, 6); /* find */
    v0143 = (*qfn2(fn))(qenv(fn), v0031, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-1];
    if (v0143 == nil) goto v0103;
    v0031 = elt(env, 4); /* "wrong att" */
    v0143 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 7); /* errorml */
    v0143 = (*qfn2(fn))(qenv(fn), v0031, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-1];
    goto v0103;

v0103:
    v0031 = qvalue(elt(env, 1)); /* atts */
    v0143 = elt(env, 5); /* dec */
    fn = elt(env, 6); /* find */
    v0143 = (*qfn2(fn))(qenv(fn), v0031, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-1];
    if (v0143 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0031 = elt(env, 4); /* "wrong att" */
    v0143 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 7); /* errorml */
    v0143 = (*qfn2(fn))(qenv(fn), v0031, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0233:
    popv(2);
    return nil;
}



/* Code for find_sub_df */

static Lisp_Object CC_find_sub_df(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0100, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_sub_df");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0234:
    v0100 = stack[0];
    if (v0100 == nil) goto v0005;
    v0033 = stack[-1];
    v0100 = stack[0];
    v0100 = qcar(v0100);
    fn = elt(env, 2); /* is_sub_df */
    v0100 = (*qfn2(fn))(qenv(fn), v0033, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-2];
    if (!(v0100 == nil)) { popv(3); return onevalue(v0100); }
    v0033 = stack[-1];
    v0100 = stack[0];
    v0100 = qcdr(v0100);
    stack[-1] = v0033;
    stack[0] = v0100;
    goto v0234;

v0005:
    v0100 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0100); }
/* error exit handlers */
v0232:
    popv(3);
    return nil;
}



/* Code for spmultm2 */

static Lisp_Object MS_CDECL CC_spmultm2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0048, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0163, v0164, v0246, v0247;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "spmultm2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spmultm2");
#endif
    if (stack >= stacklimit)
    {
        push3(v0048,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0048);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0163 = v0048;
    stack[-10] = v0001;
    stack[-11] = v0000;
/* end of prologue */
    v0164 = v0163;
    v0164 = qcdr(v0164);
    v0164 = qcar(v0164);
    fn = elt(env, 3); /* mkempspmat */
    v0163 = (*qfn2(fn))(qenv(fn), v0164, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-13];
    stack[-12] = v0163;
    v0163 = stack[-11];
    v0163 = qcdr(v0163);
    v0164 = qcar(v0163);
    v0163 = stack[-11];
    v0163 = qcdr(v0163);
    v0163 = qcdr(v0163);
    v0163 = qcar(v0163);
    v0163 = qcdr(v0163);
    v0163 = qcar(v0163);
    fn = elt(env, 4); /* empty */
    v0163 = (*qfn2(fn))(qenv(fn), v0164, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-13];
    if (v0163 == nil) goto v0100;
    v0163 = stack[-10];
    v0163 = qcdr(v0163);
    v0164 = qcar(v0163);
    v0163 = stack[-10];
    v0163 = qcdr(v0163);
    v0163 = qcdr(v0163);
    v0163 = qcar(v0163);
    v0163 = qcdr(v0163);
    v0163 = qcar(v0163);
    fn = elt(env, 4); /* empty */
    v0163 = (*qfn2(fn))(qenv(fn), v0164, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-13];
    v0163 = (v0163 == nil ? lisp_true : nil);
    goto v0102;

v0102:
    if (!(v0163 == nil)) { Lisp_Object res = stack[-12]; popv(14); return onevalue(res); }
    v0163 = stack[-11];
    v0163 = qcdr(v0163);
    v0163 = qcar(v0163);
    stack[-9] = v0163;
    v0163 = stack[-10];
    v0163 = qcdr(v0163);
    v0163 = qcar(v0163);
    stack[-8] = v0163;
    v0163 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0163;
    goto v0122;

v0122:
    v0163 = stack[-11];
    v0163 = qcdr(v0163);
    v0163 = qcdr(v0163);
    v0163 = qcar(v0163);
    v0163 = qcdr(v0163);
    v0164 = qcar(v0163);
    v0163 = stack[-3];
    v0163 = difference2(v0164, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-13];
    v0163 = Lminusp(nil, v0163);
    env = stack[-13];
    if (!(v0163 == nil)) { Lisp_Object res = stack[-12]; popv(14); return onevalue(res); }
    v0164 = stack[-9];
    v0163 = stack[-3];
    fn = elt(env, 5); /* findrow */
    v0163 = (*qfn2(fn))(qenv(fn), v0164, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-13];
    stack[-7] = v0163;
    v0163 = stack[-7];
    if (v0163 == nil) goto v0248;
    v0163 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0163;
    goto v0249;

v0249:
    v0163 = stack[-10];
    v0163 = qcdr(v0163);
    v0163 = qcdr(v0163);
    v0163 = qcar(v0163);
    v0163 = qcdr(v0163);
    v0164 = qcar(v0163);
    v0163 = stack[-2];
    v0163 = difference2(v0164, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-13];
    v0163 = Lminusp(nil, v0163);
    env = stack[-13];
    if (!(v0163 == nil)) goto v0248;
    v0164 = stack[-8];
    v0163 = stack[-2];
    fn = elt(env, 5); /* findrow */
    v0163 = (*qfn2(fn))(qenv(fn), v0164, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-13];
    stack[-6] = v0163;
    v0163 = stack[-6];
    if (v0163 == nil) goto v0043;
    v0163 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 6); /* simp */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-13];
    stack[-4] = v0163;
    v0163 = stack[-7];
    v0163 = qcdr(v0163);
    stack[-1] = v0163;
    goto v0066;

v0066:
    v0163 = stack[-1];
    if (v0163 == nil) goto v0068;
    v0163 = stack[-1];
    v0163 = qcar(v0163);
    v0164 = v0163;
    v0163 = v0164;
    v0163 = qcar(v0163);
    v0164 = qcdr(v0164);
    v0246 = v0164;
    v0164 = v0163;
    v0163 = stack[-6];
    v0163 = Latsoc(nil, v0164, v0163);
    stack[-5] = v0163;
    v0163 = stack[-5];
    if (v0163 == nil) goto v0250;
    v0163 = stack[-5];
    v0163 = qcdr(v0163);
    stack[-5] = v0163;
    v0163 = v0246;
    fn = elt(env, 6); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-13];
    v0163 = stack[-5];
    fn = elt(env, 6); /* simp */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-13];
    fn = elt(env, 7); /* multsq */
    v0163 = (*qfn2(fn))(qenv(fn), stack[0], v0163);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-13];
    stack[0] = v0163;
    v0164 = stack[-4];
    v0163 = stack[0];
    fn = elt(env, 8); /* addsq */
    v0163 = (*qfn2(fn))(qenv(fn), v0164, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-13];
    stack[-4] = v0163;
    goto v0251;

v0251:
    v0163 = stack[-1];
    v0163 = qcdr(v0163);
    stack[-1] = v0163;
    goto v0066;

v0250:
    v0163 = stack[-4];
    stack[-4] = v0163;
    goto v0251;

v0068:
    v0163 = stack[-4];
    fn = elt(env, 9); /* mk!*sq */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-13];
    stack[0] = v0163;
    v0164 = stack[0];
    v0163 = (Lisp_Object)1; /* 0 */
    if (v0164 == v0163) goto v0043;
    v0246 = stack[-12];
    v0164 = stack[-3];
    v0163 = stack[-2];
    v0247 = list3(v0246, v0164, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-13];
    v0246 = stack[0];
    v0164 = stack[-12];
    v0163 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 10); /* letmtr3 */
    v0163 = (*qfnn(fn))(qenv(fn), 4, v0247, v0246, v0164, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-13];
    goto v0043;

v0043:
    v0163 = stack[-2];
    v0163 = add1(v0163);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-13];
    stack[-2] = v0163;
    goto v0249;

v0248:
    v0163 = stack[-3];
    v0163 = add1(v0163);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-13];
    stack[-3] = v0163;
    goto v0122;

v0100:
    v0163 = qvalue(elt(env, 1)); /* t */
    goto v0102;
/* error exit handlers */
v0176:
    popv(14);
    return nil;
}



/* Code for dm!-minus */

static Lisp_Object CC_dmKminus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-minus");
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
    v0005 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* !:minus */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* nil2zero */
        return (*qfn1(fn))(qenv(fn), v0005);
    }
/* error exit handlers */
v0016:
    popv(1);
    return nil;
}



/* Code for getcomb */

static Lisp_Object CC_getcomb(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0140, v0081;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getcomb");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0140 = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0081 = v0140;
    v0140 = qvalue(elt(env, 1)); /* i */
    fn = elt(env, 4); /* nextcomb */
    v0140 = (*qfn2(fn))(qenv(fn), v0081, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-2];
    qvalue(elt(env, 2)) = v0140; /* comb */
    v0140 = qvalue(elt(env, 2)); /* comb */
    v0140 = qcar(v0140);
    v0081 = qvalue(elt(env, 2)); /* comb */
    v0081 = qcdr(v0081);
    qvalue(elt(env, 2)) = v0081; /* comb */
    v0081 = v0140;
    if (v0081 == nil) goto v0104;
    stack[-1] = v0140;
    v0081 = stack[0];
    fn = elt(env, 5); /* setdiff */
    v0140 = (*qfn2(fn))(qenv(fn), v0081, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    {
        Lisp_Object v0223 = stack[-1];
        popv(3);
        return cons(v0223, v0140);
    }

v0104:
    v0140 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v0140); }
/* error exit handlers */
v0114:
    popv(3);
    return nil;
}



/* Code for dcombine */

static Lisp_Object MS_CDECL CC_dcombine(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0048, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0305, v0306, v0307;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dcombine");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dcombine");
#endif
    if (stack >= stacklimit)
    {
        push3(v0048,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0048);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0048;
    stack[-4] = v0001;
    stack[-5] = v0000;
/* end of prologue */
    v0305 = stack[-5];
    if (!consp(v0305)) goto v0084;
    v0305 = stack[-4];
    if (!consp(v0305)) goto v0028;
    v0305 = stack[-5];
    v0306 = qcar(v0305);
    v0305 = stack[-4];
    v0305 = qcar(v0305);
    if (v0306 == v0305) goto v0074;
    v0305 = stack[-5];
    v0306 = qcar(v0305);
    v0305 = stack[-4];
    v0305 = qcar(v0305);
    stack[-6] = v0306;
    stack[-2] = v0305;
    v0306 = stack[-6];
    v0305 = stack[-2];
    v0307 = get(v0306, v0305);
    env = stack[-7];
    v0306 = elt(env, 2); /* (!:crn!: !:gi!:) */
    v0305 = elt(env, 3); /* (!:rd!: !:cr!:) */
    stack[-1] = v0307;
    stack[0] = v0306;
    v0307 = v0305;
    v0305 = stack[-1];
    if (v0305 == nil) goto v0037;
    v0305 = stack[-1];
    if (!(!consp(v0305))) goto v0037;
    v0306 = stack[-6];
    v0305 = elt(env, 5); /* cmpxfn */
    v0305 = get(v0306, v0305);
    env = stack[-7];
    if (v0305 == nil) goto v0308;
    v0306 = stack[-2];
    v0305 = elt(env, 5); /* cmpxfn */
    v0305 = get(v0306, v0305);
    env = stack[-7];
    if (!(v0305 == nil)) goto v0308;

v0243:
    v0306 = stack[-2];
    v0305 = elt(env, 7); /* !:ps!: */
    v0305 = Lneq(nil, v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-7];
    goto v0036;

v0036:
    if (v0305 == nil) goto v0310;
    v0306 = stack[-2];
    v0305 = elt(env, 8); /* noconvert */
    v0305 = Lflagp(nil, v0306, v0305);
    env = stack[-7];
    if (!(v0305 == nil)) goto v0310;
    v0306 = stack[-6];
    v0305 = stack[0];
    v0305 = Lmemq(nil, v0306, v0305);
    if (v0305 == nil) goto v0311;
    v0306 = stack[-2];
    v0305 = elt(env, 9); /* !:rd!: */
    if (!(v0306 == v0305)) goto v0311;

v0246:
    v0306 = stack[-6];
    v0305 = elt(env, 10); /* !:cr!: */
    v0306 = get(v0306, v0305);
    env = stack[-7];
    v0305 = stack[-5];
    v0305 = Lapply1(nil, v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-7];
    stack[-5] = v0305;
    v0305 = elt(env, 10); /* !:cr!: */
    stack[-6] = v0305;
    goto v0312;

v0312:
    v0306 = stack[-2];
    v0305 = stack[-6];
    v0306 = get(v0306, v0305);
    env = stack[-7];
    v0305 = stack[-4];
    v0305 = Lapply1(nil, v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-7];
    stack[-4] = v0305;
    v0306 = stack[-6];
    v0305 = stack[-3];
    v0305 = get(v0306, v0305);
    env = stack[-7];
    stack[-1] = v0305;
    goto v0313;

v0313:
    v0307 = stack[-1];
    v0306 = stack[-5];
    v0305 = stack[-4];
    v0305 = Lapply2(nil, 3, v0307, v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-7];
    goto v0005;

v0005:
    stack[-5] = v0305;
    v0305 = qvalue(elt(env, 14)); /* !*rounded */
    if (v0305 == nil) goto v0314;
    v0305 = qvalue(elt(env, 15)); /* !*roundall */
    if (v0305 == nil) goto v0314;
    v0305 = stack[-5];
    if (!consp(v0305)) goto v0314;
    v0305 = stack[-5];
    v0306 = qcar(v0305);
    stack[-4] = v0306;
    v0305 = elt(env, 11); /* !:rn!: */
    if (v0306 == v0305) goto v0315;
    v0305 = qvalue(elt(env, 6)); /* nil */
    goto v0316;

v0316:
    if (v0305 == nil) goto v0317;
    v0305 = stack[-5];
    fn = elt(env, 17); /* !*rn2rd */
    v0305 = (*qfn1(fn))(qenv(fn), v0305);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-7];
    goto v0318;

v0318:
    {
        popv(8);
        fn = elt(env, 18); /* int!-equiv!-chk */
        return (*qfn1(fn))(qenv(fn), v0305);
    }

v0317:
    v0306 = stack[-4];
    v0305 = elt(env, 13); /* !:crn!: */
    if (v0306 == v0305) goto v0319;
    v0305 = qvalue(elt(env, 6)); /* nil */
    goto v0320;

v0320:
    if (v0305 == nil) goto v0321;
    v0305 = stack[-5];
    fn = elt(env, 19); /* !*crn2cr */
    v0305 = (*qfn1(fn))(qenv(fn), v0305);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-7];
    goto v0318;

v0321:
    v0305 = stack[-5];
    goto v0318;

v0319:
    v0305 = stack[-5];
    v0305 = qcdr(v0305);
    v0305 = qcar(v0305);
    v0306 = qcdr(v0305);
    v0305 = (Lisp_Object)17; /* 1 */
    if (v0306 == v0305) goto v0322;
    v0305 = qvalue(elt(env, 4)); /* t */
    goto v0320;

v0322:
    v0305 = stack[-5];
    v0305 = qcdr(v0305);
    v0305 = qcdr(v0305);
    v0306 = qcdr(v0305);
    v0305 = (Lisp_Object)17; /* 1 */
    v0305 = Lneq(nil, v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-7];
    goto v0320;

v0315:
    v0305 = stack[-5];
    v0305 = qcdr(v0305);
    v0306 = qcdr(v0305);
    v0305 = (Lisp_Object)17; /* 1 */
    v0305 = Lneq(nil, v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-7];
    goto v0316;

v0314:
    v0306 = stack[-3];
    v0305 = elt(env, 16); /* divide */
    if (v0306 == v0305) goto v0323;
    v0305 = stack[-5];
    {
        popv(8);
        fn = elt(env, 18); /* int!-equiv!-chk */
        return (*qfn1(fn))(qenv(fn), v0305);
    }

v0323:
    v0305 = stack[-5];
    v0305 = qcar(v0305);
    fn = elt(env, 18); /* int!-equiv!-chk */
    stack[0] = (*qfn1(fn))(qenv(fn), v0305);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-7];
    v0305 = stack[-5];
    v0305 = qcdr(v0305);
    fn = elt(env, 18); /* int!-equiv!-chk */
    v0305 = (*qfn1(fn))(qenv(fn), v0305);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    {
        Lisp_Object v0324 = stack[0];
        popv(8);
        return cons(v0324, v0305);
    }

v0311:
    v0306 = stack[-6];
    v0305 = elt(env, 9); /* !:rd!: */
    if (v0306 == v0305) goto v0241;
    v0305 = qvalue(elt(env, 6)); /* nil */
    goto v0325;

v0325:
    if (!(v0305 == nil)) goto v0246;
    v0306 = stack[-6];
    v0305 = elt(env, 11); /* !:rn!: */
    if (v0306 == v0305) goto v0167;
    v0305 = qvalue(elt(env, 6)); /* nil */
    goto v0177;

v0177:
    if (v0305 == nil) goto v0326;
    v0305 = qvalue(elt(env, 4)); /* t */
    goto v0327;

v0327:
    if (v0305 == nil) goto v0312;
    v0306 = stack[-6];
    v0305 = elt(env, 13); /* !:crn!: */
    v0306 = get(v0306, v0305);
    env = stack[-7];
    v0305 = stack[-5];
    v0305 = Lapply1(nil, v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-7];
    stack[-5] = v0305;
    v0305 = elt(env, 13); /* !:crn!: */
    stack[-6] = v0305;
    goto v0312;

v0326:
    v0306 = stack[-6];
    v0305 = elt(env, 12); /* !:gi!: */
    if (v0306 == v0305) goto v0328;
    v0305 = qvalue(elt(env, 6)); /* nil */
    goto v0327;

v0328:
    v0306 = stack[-2];
    v0305 = elt(env, 11); /* !:rn!: */
    v0305 = (v0306 == v0305 ? lisp_true : nil);
    goto v0327;

v0167:
    v0306 = stack[-2];
    v0305 = elt(env, 12); /* !:gi!: */
    v0305 = (v0306 == v0305 ? lisp_true : nil);
    goto v0177;

v0241:
    v0306 = stack[-2];
    v0305 = stack[0];
    v0305 = Lmemq(nil, v0306, v0305);
    goto v0325;

v0310:
    v0306 = stack[-1];
    v0305 = stack[-5];
    v0305 = Lapply1(nil, v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-7];
    stack[-5] = v0305;
    v0306 = stack[-2];
    v0305 = stack[-3];
    v0305 = get(v0306, v0305);
    env = stack[-7];
    stack[-1] = v0305;
    goto v0313;

v0308:
    v0306 = stack[-6];
    v0305 = v0307;
    v0305 = Lmemq(nil, v0306, v0305);
    if (v0305 == nil) goto v0045;
    v0305 = stack[-2];
    v0306 = v0307;
    v0305 = Lmemq(nil, v0305, v0306);
    if (v0305 == nil) goto v0243;
    else goto v0045;

v0045:
    v0305 = qvalue(elt(env, 6)); /* nil */
    goto v0036;

v0037:
    v0305 = qvalue(elt(env, 4)); /* t */
    goto v0036;

v0074:
    v0305 = stack[-5];
    v0306 = qcar(v0305);
    v0305 = stack[-3];
    v0307 = get(v0306, v0305);
    env = stack[-7];
    v0306 = stack[-5];
    v0305 = stack[-4];
    v0305 = Lapply2(nil, 3, v0307, v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-7];
    goto v0005;

v0028:
    v0305 = stack[-5];
    v0306 = qcar(v0305);
    v0305 = stack[-3];
    stack[-1] = get(v0306, v0305);
    env = stack[-7];
    stack[0] = stack[-5];
    v0305 = stack[-5];
    v0306 = qcar(v0305);
    v0305 = elt(env, 1); /* i2d */
    v0306 = get(v0306, v0305);
    env = stack[-7];
    v0305 = stack[-4];
    v0305 = Lapply1(nil, v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-7];
    v0305 = Lapply2(nil, 3, stack[-1], stack[0], v0305);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-7];
    goto v0005;

v0084:
    v0305 = stack[-4];
    v0306 = qcar(v0305);
    v0305 = stack[-3];
    stack[0] = get(v0306, v0305);
    env = stack[-7];
    v0305 = stack[-4];
    v0306 = qcar(v0305);
    v0305 = elt(env, 1); /* i2d */
    v0306 = get(v0306, v0305);
    env = stack[-7];
    v0305 = stack[-5];
    v0306 = Lapply1(nil, v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-7];
    v0305 = stack[-4];
    v0305 = Lapply2(nil, 3, stack[0], v0306, v0305);
    nil = C_nil;
    if (exception_pending()) goto v0309;
    env = stack[-7];
    goto v0005;
/* error exit handlers */
v0309:
    popv(8);
    return nil;
}



/* Code for statep!* */

static Lisp_Object CC_statepH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0144, v0145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for statep*");
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
    v0144 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* getphystype */
    v0144 = (*qfn1(fn))(qenv(fn), v0144);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[0];
    v0145 = elt(env, 1); /* state */
    v0144 = (v0144 == v0145 ? lisp_true : nil);
    { popv(1); return onevalue(v0144); }
/* error exit handlers */
v0099:
    popv(1);
    return nil;
}



/* Code for rnconc */

static Lisp_Object CC_rnconc(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0028, v0233;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnconc");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0028 = stack[-1];
    if (v0028 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0028 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v0028 == nil) goto v0120;
    v0028 = stack[-1];
    fn = elt(env, 3); /* noncomfp1 */
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-2];
    if (v0028 == nil) goto v0120;
    v0028 = stack[0];
    fn = elt(env, 3); /* noncomfp1 */
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-2];
    if (v0028 == nil) goto v0120;
    v0233 = stack[-1];
    v0028 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* addf */
        return (*qfn2(fn))(qenv(fn), v0233, v0028);
    }

v0120:
    v0028 = stack[-1];
    v0233 = v0028;
    goto v0232;

v0232:
    v0028 = v0233;
    v0028 = qcdr(v0028);
    if (v0028 == nil) goto v0082;
    v0028 = v0233;
    v0028 = qcdr(v0028);
    v0233 = v0028;
    goto v0232;

v0082:
    v0028 = stack[0];
    v0028 = Lrplacd(nil, v0233, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v0095:
    popv(3);
    return nil;
}



/* Code for lpriw */

static Lisp_Object CC_lpriw(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0304, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lpriw");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0026 = v0001;
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = nil;
    v0304 = v0026;
    if (v0304 == nil) goto v0085;
    v0304 = v0026;
    if (!(!consp(v0304))) goto v0085;
    v0304 = v0026;
    v0304 = ncons(v0304);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-2];
    goto v0099;

v0099:
    v0304 = cons(stack[0], v0304);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-2];
    stack[0] = v0304;
    v0304 = qvalue(elt(env, 1)); /* ofl!* */
    if (v0304 == nil) goto v0135;
    v0304 = qvalue(elt(env, 2)); /* !*fort */
    if (!(v0304 == nil)) goto v0051;
    v0304 = qvalue(elt(env, 3)); /* !*nat */
    if (v0304 == nil) goto v0140;
    v0304 = qvalue(elt(env, 5)); /* !*defn */
    goto v0047;

v0047:
    if (!(v0304 == nil)) goto v0051;

v0135:
    v0304 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-2];
    goto v0016;

v0016:
    v0304 = stack[0];
    fn = elt(env, 7); /* lpri */
    v0304 = (*qfn1(fn))(qenv(fn), v0304);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-2];
    v0304 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-2];
    v0304 = stack[-1];
    if (v0304 == nil) goto v0010;
    v0304 = stack[-1];
    v0304 = qcdr(v0304);
    v0304 = Lwrs(nil, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-2];
    v0304 = qvalue(elt(env, 6)); /* nil */
    { popv(3); return onevalue(v0304); }

v0010:
    v0304 = qvalue(elt(env, 1)); /* ofl!* */
    if (!(v0304 == nil)) goto v0051;
    v0304 = qvalue(elt(env, 6)); /* nil */
    { popv(3); return onevalue(v0304); }

v0051:
    v0304 = qvalue(elt(env, 1)); /* ofl!* */
    stack[-1] = v0304;
    v0304 = qvalue(elt(env, 6)); /* nil */
    v0304 = Lwrs(nil, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-2];
    goto v0016;

v0140:
    v0304 = qvalue(elt(env, 4)); /* t */
    goto v0047;

v0085:
    v0304 = v0026;
    goto v0099;
/* error exit handlers */
v0079:
    popv(3);
    return nil;
}



/* Code for getel1 */

static Lisp_Object MS_CDECL CC_getel1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0048, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0129, v0198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "getel1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getel1");
#endif
    if (stack >= stacklimit)
    {
        push3(v0048,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0048);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0048;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */

v0016:
    v0129 = stack[-1];
    if (v0129 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0129 = stack[-1];
    v0129 = qcar(v0129);
    v0129 = integerp(v0129);
    if (v0129 == nil) goto v0091;
    v0129 = stack[-1];
    v0198 = qcar(v0129);
    v0129 = stack[0];
    v0129 = qcar(v0129);
    v0129 = (Lisp_Object)geq2(v0198, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    v0129 = v0129 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0129 == nil)) goto v0116;
    v0129 = stack[-1];
    v0198 = qcar(v0129);
    v0129 = (Lisp_Object)1; /* 0 */
    v0129 = (Lisp_Object)lessp2(v0198, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    v0129 = v0129 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0129 == nil)) goto v0116;
    v0198 = stack[-2];
    v0129 = stack[-1];
    v0129 = qcar(v0129);
    v0129 = *(Lisp_Object *)((char *)v0198 + (CELL-TAG_VECTOR) + ((int32_t)v0129/(16/CELL)));
    stack[-2] = v0129;
    v0129 = stack[-1];
    v0129 = qcdr(v0129);
    stack[-1] = v0129;
    v0129 = stack[0];
    v0129 = qcdr(v0129);
    stack[0] = v0129;
    goto v0016;

v0116:
    v0129 = elt(env, 2); /* "Array out of bounds" */
    v0198 = v0129;
    v0129 = v0198;
    qvalue(elt(env, 3)) = v0129; /* errmsg!* */
    v0129 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v0129 == nil)) goto v0233;
    v0129 = v0198;
    fn = elt(env, 5); /* lprie */
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-3];
    goto v0233;

v0233:
    v0129 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    v0129 = nil;
    { popv(4); return onevalue(v0129); }

v0091:
    v0129 = stack[-1];
    v0198 = qcar(v0129);
    v0129 = elt(env, 1); /* "array index" */
    {
        popv(4);
        fn = elt(env, 6); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0198, v0129);
    }
/* error exit handlers */
v0022:
    popv(4);
    return nil;
}



/* Code for red!-weight1 */

static Lisp_Object CC_redKweight1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0028, v0233;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-weight1");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0010;

v0010:
    v0028 = stack[-1];
    if (v0028 == nil) goto v0051;
    v0028 = stack[-1];
    v0028 = qcar(v0028);
    v0233 = Labsval(nil, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0028 = stack[0];
    v0028 = qcar(v0028);
    v0233 = times2(v0233, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0028 = stack[-2];
    v0028 = cons(v0233, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    stack[-2] = v0028;
    v0028 = stack[-1];
    v0028 = qcdr(v0028);
    stack[-1] = v0028;
    v0028 = stack[0];
    v0028 = qcdr(v0028);
    stack[0] = v0028;
    goto v0010;

v0051:
    v0028 = (Lisp_Object)1; /* 0 */
    v0233 = v0028;
    goto v0105;

v0105:
    v0028 = stack[-2];
    if (v0028 == nil) { popv(4); return onevalue(v0233); }
    v0028 = stack[-2];
    v0028 = qcar(v0028);
    v0028 = plus2(v0028, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0233 = v0028;
    v0028 = stack[-2];
    v0028 = qcdr(v0028);
    stack[-2] = v0028;
    goto v0105;
/* error exit handlers */
v0094:
    popv(4);
    return nil;
}



/* Code for multop */

static Lisp_Object CC_multop(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0223, v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multop");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0050 = v0000;
/* end of prologue */
    v0114 = qvalue(elt(env, 1)); /* kord!* */
    if (v0114 == nil) goto v0132;
    v0114 = v0050;
    v0223 = qcar(v0114);
    v0114 = elt(env, 2); /* k!* */
    if (v0223 == v0114) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0223 = v0050;
    v0114 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); /* rmultpf */
        return (*qfn2(fn))(qenv(fn), v0223, v0114);
    }

v0132:
    v0223 = v0050;
    v0114 = (Lisp_Object)17; /* 1 */
    v0114 = cons(v0223, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-1];
    v0223 = ncons(v0114);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-1];
    v0114 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* multf */
        return (*qfn2(fn))(qenv(fn), v0223, v0114);
    }
/* error exit handlers */
v0082:
    popv(2);
    return nil;
}



/* Code for red_divtestbe */

static Lisp_Object MS_CDECL CC_red_divtestbe(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0048, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "red_divtestbe");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_divtestbe");
#endif
    if (stack >= stacklimit)
    {
        push3(v0048,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0048);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0048;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */

v0016:
    v0049 = stack[-2];
    if (v0049 == nil) goto v0105;
    v0049 = stack[-2];
    v0049 = qcar(v0049);
    fn = elt(env, 2); /* bas_dpecart */
    v0114 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-3];
    v0049 = stack[0];
    v0049 = (Lisp_Object)lesseq2(v0114, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    v0049 = v0049 ? lisp_true : nil;
    env = stack[-3];
    if (v0049 == nil) goto v0047;
    v0049 = stack[-2];
    v0049 = qcar(v0049);
    fn = elt(env, 3); /* bas_dpoly */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-3];
    fn = elt(env, 4); /* dp_lmon */
    v0114 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-3];
    v0049 = stack[-1];
    fn = elt(env, 5); /* mo_vdivides!? */
    v0049 = (*qfn2(fn))(qenv(fn), v0114, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-3];
    if (v0049 == nil) goto v0047;
    v0049 = stack[-2];
    v0049 = qcar(v0049);
    { popv(4); return onevalue(v0049); }

v0047:
    v0049 = stack[-2];
    v0049 = qcdr(v0049);
    stack[-2] = v0049;
    goto v0016;

v0105:
    v0049 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0049); }
/* error exit handlers */
v0082:
    popv(4);
    return nil;
}



/* Code for leftzeros */

static Lisp_Object CC_leftzeros(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076, v0095;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for leftzeros");
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
    stack[-1] = nil;
    goto v0016;

v0016:
    v0076 = stack[0];
    if (v0076 == nil) goto v0147;
    v0076 = stack[0];
    v0095 = qcar(v0076);
    v0076 = (Lisp_Object)1; /* 0 */
    v0076 = Lneq(nil, v0095, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-2];
    goto v0146;

v0146:
    if (v0076 == nil) goto v0102;
    v0076 = (Lisp_Object)1; /* 0 */
    v0095 = v0076;
    goto v0051;

v0051:
    v0076 = stack[-1];
    if (v0076 == nil) { popv(3); return onevalue(v0095); }
    v0076 = stack[-1];
    v0076 = qcar(v0076);
    v0076 = (Lisp_Object)(int32_t)((int32_t)v0076 + (int32_t)v0095 - TAG_FIXNUM);
    v0095 = v0076;
    v0076 = stack[-1];
    v0076 = qcdr(v0076);
    stack[-1] = v0076;
    goto v0051;

v0102:
    v0095 = (Lisp_Object)17; /* 1 */
    v0076 = stack[-1];
    v0076 = cons(v0095, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-2];
    stack[-1] = v0076;
    v0076 = stack[0];
    v0076 = qcdr(v0076);
    stack[0] = v0076;
    goto v0016;

v0147:
    v0076 = qvalue(elt(env, 1)); /* t */
    goto v0146;
/* error exit handlers */
v0139:
    popv(3);
    return nil;
}



/* Code for b!:extmult */

static Lisp_Object CC_bTextmult(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0043;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for b:extmult");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0040 = stack[-3];
    if (v0040 == nil) goto v0105;
    v0040 = stack[-2];
    v0040 = (v0040 == nil ? lisp_true : nil);
    goto v0051;

v0051:
    if (v0040 == nil) goto v0197;
    v0040 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0040); }

v0197:
    v0043 = stack[-2];
    v0040 = (Lisp_Object)17; /* 1 */
    if (v0043 == v0040) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0040 = stack[-3];
    v0040 = qcar(v0040);
    v0040 = qcar(v0040);
    v0043 = qcar(v0040);
    v0040 = stack[-2];
    v0040 = qcar(v0040);
    v0040 = qcar(v0040);
    fn = elt(env, 3); /* b!:ordexn */
    v0040 = (*qfn2(fn))(qenv(fn), v0043, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-5];
    v0043 = v0040;
    v0040 = v0043;
    if (v0040 == nil) goto v0007;
    v0040 = v0043;
    stack[-4] = qcdr(v0040);
    v0040 = v0043;
    v0040 = qcar(v0040);
    if (v0040 == nil) goto v0113;
    v0040 = stack[-3];
    v0040 = qcar(v0040);
    v0043 = qcdr(v0040);
    v0040 = stack[-2];
    v0040 = qcar(v0040);
    v0040 = qcdr(v0040);
    fn = elt(env, 4); /* multf */
    v0040 = (*qfn2(fn))(qenv(fn), v0043, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-5];
    fn = elt(env, 5); /* negf */
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-5];
    stack[-1] = v0040;
    goto v0017;

v0017:
    v0040 = stack[-3];
    v0040 = qcar(v0040);
    v0043 = ncons(v0040);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-5];
    v0040 = stack[-2];
    v0040 = qcdr(v0040);
    stack[0] = CC_bTextmult(env, v0043, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-5];
    v0040 = stack[-3];
    v0043 = qcdr(v0040);
    v0040 = stack[-2];
    v0040 = CC_bTextmult(env, v0043, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-5];
    fn = elt(env, 6); /* b!:extadd */
    v0040 = (*qfn2(fn))(qenv(fn), stack[0], v0040);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    {
        Lisp_Object v0067 = stack[-4];
        Lisp_Object v0068 = stack[-1];
        popv(6);
        return acons(v0067, v0068, v0040);
    }

v0113:
    v0040 = stack[-3];
    v0040 = qcar(v0040);
    v0043 = qcdr(v0040);
    v0040 = stack[-2];
    v0040 = qcar(v0040);
    v0040 = qcdr(v0040);
    fn = elt(env, 4); /* multf */
    v0040 = (*qfn2(fn))(qenv(fn), v0043, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-5];
    stack[-1] = v0040;
    goto v0017;

v0007:
    v0040 = stack[-3];
    v0043 = qcdr(v0040);
    v0040 = stack[-2];
    stack[0] = CC_bTextmult(env, v0043, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-5];
    v0040 = stack[-3];
    v0040 = qcar(v0040);
    v0043 = ncons(v0040);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-5];
    v0040 = stack[-2];
    v0040 = qcdr(v0040);
    v0040 = CC_bTextmult(env, v0043, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-5];
    {
        Lisp_Object v0066 = stack[0];
        popv(6);
        fn = elt(env, 6); /* b!:extadd */
        return (*qfn2(fn))(qenv(fn), v0066, v0040);
    }

v0105:
    v0040 = qvalue(elt(env, 1)); /* t */
    goto v0051;
/* error exit handlers */
v0109:
    popv(6);
    return nil;
}



/* Code for general!-times!-term!-mod!-p */

static Lisp_Object CC_generalKtimesKtermKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0121, v0334, v0216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-times-term-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0121 = stack[-1];
    if (v0121 == nil) goto v0005;
    v0121 = stack[-1];
    if (!consp(v0121)) goto v0099;
    v0121 = stack[-1];
    v0121 = qcar(v0121);
    v0121 = (consp(v0121) ? nil : lisp_true);
    goto v0145;

v0145:
    if (v0121 == nil) goto v0049;
    v0121 = stack[-2];
    stack[0] = qcar(v0121);
    v0121 = stack[-2];
    v0334 = qcdr(v0121);
    v0121 = stack[-1];
    fn = elt(env, 3); /* gen!-mult!-by!-const!-mod!-p */
    v0334 = (*qfn2(fn))(qenv(fn), v0334, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-4];
    v0121 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0060 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0060, v0334, v0121);
    }

v0049:
    v0121 = stack[-2];
    v0121 = qcar(v0121);
    v0334 = qcar(v0121);
    v0121 = stack[-1];
    v0121 = qcar(v0121);
    v0121 = qcar(v0121);
    v0121 = qcar(v0121);
    if (equal(v0334, v0121)) goto v0023;
    v0121 = stack[-2];
    v0121 = qcar(v0121);
    v0334 = qcar(v0121);
    v0121 = stack[-1];
    v0121 = qcar(v0121);
    v0121 = qcar(v0121);
    v0121 = qcar(v0121);
    fn = elt(env, 5); /* ordop */
    v0121 = (*qfn2(fn))(qenv(fn), v0334, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-4];
    if (v0121 == nil) goto v0244;
    v0121 = stack[-2];
    stack[0] = qcar(v0121);
    v0121 = stack[-2];
    v0334 = qcdr(v0121);
    v0121 = stack[-1];
    fn = elt(env, 6); /* general!-times!-mod!-p */
    v0334 = (*qfn2(fn))(qenv(fn), v0334, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-4];
    v0121 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0335 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0335, v0334, v0121);
    }

v0244:
    v0121 = stack[-1];
    v0121 = qcar(v0121);
    stack[-3] = qcar(v0121);
    v0334 = stack[-2];
    v0121 = stack[-1];
    v0121 = qcar(v0121);
    v0121 = qcdr(v0121);
    stack[0] = CC_generalKtimesKtermKmodKp(env, v0334, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-4];
    v0334 = stack[-2];
    v0121 = stack[-1];
    v0121 = qcdr(v0121);
    v0121 = CC_generalKtimesKtermKmodKp(env, v0334, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-4];
    {
        Lisp_Object v0218 = stack[-3];
        Lisp_Object v0219 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0218, v0219, v0121);
    }

v0023:
    v0121 = stack[-2];
    v0121 = qcar(v0121);
    v0121 = qcar(v0121);
    fn = elt(env, 7); /* fkern */
    v0216 = (*qfn1(fn))(qenv(fn), v0121);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-4];
    v0121 = stack[-2];
    v0121 = qcar(v0121);
    v0334 = qcdr(v0121);
    v0121 = stack[-1];
    v0121 = qcar(v0121);
    v0121 = qcar(v0121);
    v0121 = qcdr(v0121);
    v0121 = (Lisp_Object)(int32_t)((int32_t)v0334 + (int32_t)v0121 - TAG_FIXNUM);
    fn = elt(env, 8); /* getpower */
    stack[-3] = (*qfn2(fn))(qenv(fn), v0216, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-4];
    v0121 = stack[-2];
    v0334 = qcdr(v0121);
    v0121 = stack[-1];
    v0121 = qcar(v0121);
    v0121 = qcdr(v0121);
    fn = elt(env, 6); /* general!-times!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v0334, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-4];
    v0334 = stack[-2];
    v0121 = stack[-1];
    v0121 = qcdr(v0121);
    v0121 = CC_generalKtimesKtermKmodKp(env, v0334, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0251;
    env = stack[-4];
    {
        Lisp_Object v0301 = stack[-3];
        Lisp_Object v0191 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0301, v0191, v0121);
    }

v0099:
    v0121 = qvalue(elt(env, 2)); /* t */
    goto v0145;

v0005:
    v0121 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0121); }
/* error exit handlers */
v0251:
    popv(5);
    return nil;
}



/* Code for removeg */

static Lisp_Object CC_removeg(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0243, v0098, v0220, v0215;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for removeg");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0243 = stack[-1];
    v0098 = qcdr(v0243);
    v0243 = stack[0];
    v0243 = qcdr(v0243);
    v0243 = qcdr(v0243);
    v0243 = qcdr(v0243);
    v0243 = qcar(v0243);
    fn = elt(env, 8); /* finde */
    v0243 = (*qfn2(fn))(qenv(fn), v0098, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-3];
    stack[-2] = v0243;
    v0243 = stack[-2];
    v0098 = qcar(v0243);
    v0243 = stack[0];
    if (!(v0098 == v0243)) goto v0197;
    v0243 = stack[-2];
    v0098 = qcdr(v0243);
    v0243 = stack[0];
    v0243 = qcdr(v0243);
    v0243 = qcdr(v0243);
    v0243 = qcdr(v0243);
    v0243 = qcar(v0243);
    fn = elt(env, 8); /* finde */
    v0243 = (*qfn2(fn))(qenv(fn), v0098, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-3];
    stack[-2] = v0243;
    goto v0197;

v0197:
    v0243 = stack[-2];
    if (!(v0243 == nil)) goto v0114;
    v0215 = elt(env, 1); /* "Free edge" */
    v0243 = stack[0];
    v0243 = qcdr(v0243);
    v0243 = qcdr(v0243);
    v0243 = qcdr(v0243);
    v0220 = qcar(v0243);
    v0098 = elt(env, 2); /* "in vertex" */
    v0243 = stack[0];
    v0243 = list4(v0215, v0220, v0098, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-3];
    fn = elt(env, 9); /* cerror */
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-3];
    goto v0114;

v0114:
    v0243 = stack[-2];
    v0243 = qcar(v0243);
    stack[-2] = v0243;
    v0243 = stack[-2];
    v0243 = qcdr(v0243);
    v0098 = qcar(v0243);
    v0243 = stack[-2];
    v0243 = qcdr(v0243);
    v0243 = qcdr(v0243);
    v0243 = qcar(v0243);
    if (v0098 == v0243) goto v0077;
    v0243 = stack[-2];
    v0243 = qcdr(v0243);
    v0098 = qcar(v0243);
    v0243 = stack[-2];
    v0243 = qcdr(v0243);
    v0243 = qcdr(v0243);
    v0243 = qcdr(v0243);
    v0243 = qcar(v0243);
    if (v0098 == v0243) goto v0195;
    v0243 = stack[-2];
    v0243 = qcdr(v0243);
    v0243 = qcdr(v0243);
    v0098 = qcar(v0243);
    v0243 = stack[-2];
    v0243 = qcdr(v0243);
    v0243 = qcdr(v0243);
    v0243 = qcdr(v0243);
    v0243 = qcar(v0243);
    v0243 = (v0098 == v0243 ? lisp_true : nil);
    goto v0080;

v0080:
    if (v0243 == nil) goto v0339;
    v0098 = qvalue(elt(env, 4)); /* nil */
    v0243 = (Lisp_Object)17; /* 1 */
    v0243 = cons(v0098, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-3];
    v0243 = ncons(v0243);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    popv(4);
    return ncons(v0243);

v0339:
    v0243 = stack[-2];
    v0098 = qcar(v0243);
    v0243 = elt(env, 5); /* qg */
    if (v0098 == v0243) goto v0134;
    v0243 = stack[-2];
    v0098 = qcar(v0243);
    v0243 = elt(env, 6); /* g3 */
    if (v0098 == v0243) goto v0308;
    v0098 = elt(env, 7); /* "Invalid type of vertex" */
    v0243 = stack[0];
    v0243 = list2(v0098, v0243);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-3];
    fn = elt(env, 9); /* cerror */
    v0243 = (*qfn1(fn))(qenv(fn), v0243);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    v0243 = nil;
    { popv(4); return onevalue(v0243); }

v0308:
    v0220 = stack[-1];
    v0098 = stack[0];
    v0243 = stack[-2];
    {
        popv(4);
        fn = elt(env, 10); /* removeg2 */
        return (*qfnn(fn))(qenv(fn), 3, v0220, v0098, v0243);
    }

v0134:
    v0220 = stack[-1];
    v0098 = stack[0];
    v0243 = stack[-2];
    {
        popv(4);
        fn = elt(env, 11); /* removeg1 */
        return (*qfnn(fn))(qenv(fn), 3, v0220, v0098, v0243);
    }

v0195:
    v0243 = qvalue(elt(env, 3)); /* t */
    goto v0080;

v0077:
    v0243 = qvalue(elt(env, 3)); /* t */
    goto v0080;
/* error exit handlers */
v0054:
    popv(4);
    return nil;
}



/* Code for mri_pasf2mri */

static Lisp_Object CC_mri_pasf2mri(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0147, v0132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_pasf2mri");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0147 = v0001;
    v0132 = v0000;
/* end of prologue */
    stack[-1] = v0132;
    stack[0] = elt(env, 1); /* mri_pasf2mriat */
    v0147 = ncons(v0147);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-2];
    {
        Lisp_Object v0197 = stack[-1];
        Lisp_Object v0034 = stack[0];
        popv(3);
        fn = elt(env, 2); /* cl_apply2ats1 */
        return (*qfnn(fn))(qenv(fn), 3, v0197, v0034, v0147);
    }
/* error exit handlers */
v0091:
    popv(3);
    return nil;
}



/* Code for isimplicit */

static Lisp_Object CC_isimplicit(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0046, v0047, v0140;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isimplicit");
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
    v0046 = elt(env, 1); /* implicit!  */
    v0046 = Lexplode(nil, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-2];
    stack[-1] = v0046;
    v0046 = stack[0];
    v0046 = Lexplode(nil, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    v0047 = v0046;
    v0046 = lisp_true;
    v0140 = v0046;
    goto v0146;

v0146:
    v0046 = v0140;
    if (v0046 == nil) { popv(3); return onevalue(v0140); }
    v0046 = stack[-1];
    if (v0046 == nil) { popv(3); return onevalue(v0140); }
    v0046 = v0047;
    v0140 = qcar(v0046);
    v0046 = stack[-1];
    v0046 = qcar(v0046);
    v0046 = (equal(v0140, v0046) ? lisp_true : nil);
    v0140 = v0046;
    v0046 = stack[-1];
    v0046 = qcdr(v0046);
    stack[-1] = v0046;
    v0046 = v0047;
    v0046 = qcdr(v0046);
    v0047 = v0046;
    goto v0146;
/* error exit handlers */
v0049:
    popv(3);
    return nil;
}



/* Code for bind */

static Lisp_Object CC_bind(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0120, v0101, v0135;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bind");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0101 = v0001;
    v0120 = v0000;
/* end of prologue */
    stack[-1] = v0120;
    stack[0] = elt(env, 1); /* binding */
    v0135 = v0101;
    v0101 = v0120;
    v0120 = elt(env, 1); /* binding */
    v0120 = get(v0101, v0120);
    env = stack[-2];
    v0120 = cons(v0135, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    {
        Lisp_Object v0032 = stack[-1];
        Lisp_Object v0093 = stack[0];
        popv(3);
        return Lputprop(nil, 3, v0032, v0093, v0120);
    }
/* error exit handlers */
v0033:
    popv(3);
    return nil;
}



/* Code for getmat */

static Lisp_Object MS_CDECL CC_getmat(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0048, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0139, v0141, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "getmat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getmat");
#endif
    if (stack >= stacklimit)
    {
        push3(v0048,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0048);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0048;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0139 = qvalue(elt(env, 1)); /* !*modular */
    if (v0139 == nil) goto v0005;
    v0139 = elt(env, 2); /* modular */
    v0139 = ncons(v0139);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    fn = elt(env, 6); /* off */
    v0139 = (*qfn1(fn))(qenv(fn), v0139);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    v0139 = elt(env, 3); /* mod_was_on */
    v0139 = ncons(v0139);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    fn = elt(env, 7); /* on */
    v0139 = (*qfn1(fn))(qenv(fn), v0139);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    goto v0005;

v0005:
    v0139 = stack[-1];
    v0139 = integerp(v0139);
    if (v0139 == nil) goto v0228;
    v0139 = stack[-1];
    goto v0117;

v0117:
    stack[-1] = v0139;
    v0139 = stack[0];
    v0139 = integerp(v0139);
    if (v0139 == nil) goto v0032;
    v0139 = stack[0];
    goto v0120;

v0120:
    stack[0] = v0139;
    v0139 = qvalue(elt(env, 5)); /* !*mod_was_on */
    if (v0139 == nil) goto v0115;
    v0139 = elt(env, 2); /* modular */
    v0139 = ncons(v0139);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    fn = elt(env, 7); /* on */
    v0139 = (*qfn1(fn))(qenv(fn), v0139);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    v0139 = elt(env, 3); /* mod_was_on */
    v0139 = ncons(v0139);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    fn = elt(env, 6); /* off */
    v0139 = (*qfn1(fn))(qenv(fn), v0139);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    goto v0115;

v0115:
    v0024 = stack[-2];
    v0141 = stack[-1];
    v0139 = stack[0];
    v0139 = list3(v0024, v0141, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 8); /* unchecked_getmatelem */
        return (*qfn1(fn))(qenv(fn), v0139);
    }

v0032:
    v0139 = stack[0];
    fn = elt(env, 9); /* reval */
    v0139 = (*qfn1(fn))(qenv(fn), v0139);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    goto v0120;

v0228:
    v0139 = stack[-1];
    fn = elt(env, 9); /* reval */
    v0139 = (*qfn1(fn))(qenv(fn), v0139);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-3];
    goto v0117;
/* error exit handlers */
v0142:
    popv(4);
    return nil;
}



/* Code for vdplength */

static Lisp_Object CC_vdplength(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdplength");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0051 = v0000;
/* end of prologue */
    v0051 = qcdr(v0051);
    v0051 = qcdr(v0051);
    v0051 = qcdr(v0051);
    v0051 = qcar(v0051);
    {
        fn = elt(env, 1); /* diplength */
        return (*qfn1(fn))(qenv(fn), v0051);
    }
}



/* Code for wedget2 */

static Lisp_Object CC_wedget2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0196, v0333, v0124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedget2");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0196 = stack[-1];
    v0333 = qcar(v0196);
    v0196 = (Lisp_Object)17; /* 1 */
    if (v0333 == v0196) goto v0117;
    v0196 = stack[0];
    v0196 = qcar(v0196);
    v0333 = qcar(v0196);
    v0196 = (Lisp_Object)17; /* 1 */
    if (v0333 == v0196) goto v0050;
    v0196 = stack[-1];
    v0124 = qcar(v0196);
    v0196 = stack[0];
    v0333 = qcar(v0196);
    v0196 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* wedgek2 */
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v0124, v0333, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-3];
    v0196 = stack[-1];
    v0333 = qcdr(v0196);
    v0196 = stack[0];
    v0196 = qcdr(v0196);
    fn = elt(env, 3); /* multsq */
    v0196 = (*qfn2(fn))(qenv(fn), v0333, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-3];
    {
        Lisp_Object v0138 = stack[-2];
        popv(4);
        fn = elt(env, 4); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v0138, v0196);
    }

v0050:
    v0196 = stack[-1];
    v0196 = qcar(v0196);
    stack[-2] = ncons(v0196);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-3];
    v0196 = stack[-1];
    v0333 = qcdr(v0196);
    v0196 = stack[0];
    v0196 = qcdr(v0196);
    fn = elt(env, 3); /* multsq */
    v0196 = (*qfn2(fn))(qenv(fn), v0333, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-3];
    v0196 = cons(stack[-2], v0196);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    popv(4);
    return ncons(v0196);

v0117:
    v0196 = stack[0];
    stack[-2] = qcar(v0196);
    v0196 = stack[-1];
    v0333 = qcdr(v0196);
    v0196 = stack[0];
    v0196 = qcdr(v0196);
    fn = elt(env, 3); /* multsq */
    v0196 = (*qfn2(fn))(qenv(fn), v0333, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-3];
    v0196 = cons(stack[-2], v0196);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    popv(4);
    return ncons(v0196);
/* error exit handlers */
v0073:
    popv(4);
    return nil;
}



/* Code for greaterp!: */

static Lisp_Object CC_greaterpT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0330, v0308, v0119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for greaterp:");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0119 = v0000;
/* end of prologue */
    v0330 = v0119;
    v0330 = qcdr(v0330);
    v0308 = qcdr(v0330);
    v0330 = stack[0];
    v0330 = qcdr(v0330);
    v0330 = qcdr(v0330);
    if (equal(v0308, v0330)) goto v0091;
    v0330 = v0119;
    fn = elt(env, 2); /* csl_normbf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0330);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    v0330 = stack[0];
    fn = elt(env, 2); /* csl_normbf */
    v0330 = (*qfn1(fn))(qenv(fn), v0330);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    stack[0] = v0330;
    v0330 = stack[-1];
    v0330 = qcdr(v0330);
    v0308 = qcdr(v0330);
    v0330 = stack[0];
    v0330 = qcdr(v0330);
    v0330 = qcdr(v0330);
    v0119 = difference2(v0308, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    v0330 = stack[-1];
    v0330 = qcdr(v0330);
    v0308 = qcar(v0330);
    v0330 = stack[0];
    v0330 = qcdr(v0330);
    v0330 = qcar(v0330);
    stack[-4] = v0119;
    stack[-3] = v0308;
    stack[-2] = v0330;
    v0308 = stack[-4];
    v0330 = (Lisp_Object)1; /* 0 */
    if (v0308 == v0330) goto v0026;
    v0308 = (Lisp_Object)33; /* 2 */
    v0330 = qvalue(elt(env, 1)); /* !:bprec!: */
    v0330 = times2(v0308, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    stack[-1] = v0330;
    v0308 = stack[-4];
    v0330 = stack[-1];
    v0330 = (Lisp_Object)greaterp2(v0308, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    v0330 = v0330 ? lisp_true : nil;
    env = stack[-5];
    if (v0330 == nil) goto v0042;
    v0308 = stack[-3];
    v0330 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Lgreaterp(nil, v0308, v0330);

v0042:
    stack[0] = stack[-4];
    v0330 = stack[-1];
    v0330 = negate(v0330);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    v0330 = (Lisp_Object)lessp2(stack[0], v0330);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    v0330 = v0330 ? lisp_true : nil;
    env = stack[-5];
    if (v0330 == nil) goto v0058;
    v0308 = stack[-2];
    v0330 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Llessp(nil, v0308, v0330);

v0058:
    v0308 = stack[-4];
    v0330 = (Lisp_Object)1; /* 0 */
    v0330 = (Lisp_Object)greaterp2(v0308, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    v0330 = v0330 ? lisp_true : nil;
    env = stack[-5];
    if (v0330 == nil) goto v0066;
    v0308 = stack[-3];
    v0330 = stack[-4];
    v0308 = Lash1(nil, v0308, v0330);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    v0330 = stack[-2];
        popv(6);
        return Lgreaterp(nil, v0308, v0330);

v0066:
    stack[0] = stack[-3];
    stack[-1] = stack[-2];
    v0330 = stack[-4];
    v0330 = negate(v0330);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-5];
    v0330 = Lash1(nil, stack[-1], v0330);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    {
        Lisp_Object v0337 = stack[0];
        popv(6);
        return Lgreaterp(nil, v0337, v0330);
    }

v0026:
    v0308 = stack[-3];
    v0330 = stack[-2];
        popv(6);
        return Lgreaterp(nil, v0308, v0330);

v0091:
    v0330 = v0119;
    v0330 = qcdr(v0330);
    v0308 = qcar(v0330);
    v0330 = stack[0];
    v0330 = qcdr(v0330);
    v0330 = qcar(v0330);
        popv(6);
        return Lgreaterp(nil, v0308, v0330);
/* error exit handlers */
v0212:
    popv(6);
    return nil;
}



/* Code for deletemult!* */

static Lisp_Object CC_deletemultH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0028, v0233;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deletemult*");
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
    stack[0] = v0000;
/* end of prologue */
    v0031 = stack[0];
    if (v0031 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0031 = stack[0];
    v0031 = qcar(v0031);
    v0031 = ncons(v0031);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    stack[-2] = v0031;
    v0031 = stack[0];
    v0031 = qcdr(v0031);
    stack[0] = v0031;
    v0031 = stack[0];
    stack[-1] = v0031;
    goto v0091;

v0091:
    v0031 = stack[-1];
    if (v0031 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0031 = stack[-1];
    v0031 = qcar(v0031);
    v0233 = v0031;
    v0028 = v0233;
    v0031 = stack[-2];
    v0031 = Lmember(nil, v0028, v0031);
    if (!(v0031 == nil)) goto v0102;
    stack[0] = stack[-2];
    v0031 = v0233;
    v0031 = ncons(v0031);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0031 = Lnconc(nil, stack[0], v0031);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    goto v0102;

v0102:
    v0031 = stack[-1];
    v0031 = qcdr(v0031);
    stack[-1] = v0031;
    goto v0091;
/* error exit handlers */
v0094:
    popv(4);
    return nil;
}



/* Code for getelv */

static Lisp_Object CC_getelv(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getelv");
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
    v0028 = v0000;
/* end of prologue */
    v0031 = v0028;
    stack[-4] = qcar(v0031);
    v0031 = v0028;
    v0031 = qcdr(v0031);
    stack[-3] = v0031;
    v0031 = stack[-3];
    if (v0031 == nil) goto v0034;
    v0031 = stack[-3];
    v0031 = qcar(v0031);
    fn = elt(env, 2); /* reval_without_mod */
    v0031 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0031 = ncons(v0031);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    stack[-1] = v0031;
    stack[-2] = v0031;
    goto v0132;

v0132:
    v0031 = stack[-3];
    v0031 = qcdr(v0031);
    stack[-3] = v0031;
    v0031 = stack[-3];
    if (v0031 == nil) goto v0093;
    stack[0] = stack[-1];
    v0031 = stack[-3];
    v0031 = qcar(v0031);
    fn = elt(env, 2); /* reval_without_mod */
    v0031 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0031 = ncons(v0031);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0031 = Lrplacd(nil, stack[0], v0031);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0031 = stack[-1];
    v0031 = qcdr(v0031);
    stack[-1] = v0031;
    goto v0132;

v0093:
    v0031 = stack[-2];
    goto v0010;

v0010:
    v0031 = cons(stack[-4], v0031);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 3); /* getel */
        return (*qfn1(fn))(qenv(fn), v0031);
    }

v0034:
    v0031 = qvalue(elt(env, 1)); /* nil */
    goto v0010;
/* error exit handlers */
v0131:
    popv(6);
    return nil;
}



/* Code for prepsqxx */

static Lisp_Object CC_prepsqxx(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0028, v0233, v0041;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsqxx");
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
    v0233 = v0000;
/* end of prologue */
    v0028 = qvalue(elt(env, 1)); /* !*intstr */
    if (v0028 == nil) goto v0005;
    v0028 = v0233;
    fn = elt(env, 5); /* prepsq!* */
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[0];
    goto v0012;

v0012:
    v0041 = v0028;
    v0233 = v0041;
    v0028 = elt(env, 3); /* minus */
    if (!consp(v0233)) goto v0114;
    v0233 = qcar(v0233);
    if (!(v0233 == v0028)) goto v0114;
    v0028 = v0041;
    v0028 = qcdr(v0028);
    v0028 = qcar(v0028);
    v0028 = (is_number(v0028) ? lisp_true : nil);
    goto v0135;

v0135:
    if (v0028 == nil) { popv(1); return onevalue(v0041); }
    v0028 = v0041;
    v0028 = qcdr(v0028);
    v0028 = qcar(v0028);
    popv(1);
    return negate(v0028);

v0114:
    v0028 = qvalue(elt(env, 4)); /* nil */
    goto v0135;

v0005:
    v0028 = v0233;
    v0028 = qcar(v0028);
    if (v0028 == nil) goto v0105;
    v0028 = elt(env, 2); /* prepf */
    fn = elt(env, 6); /* sqform */
    v0028 = (*qfn2(fn))(qenv(fn), v0233, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[0];
    goto v0012;

v0105:
    v0028 = (Lisp_Object)1; /* 0 */
    goto v0012;
/* error exit handlers */
v0076:
    popv(1);
    return nil;
}



/* Code for pdif */

static Lisp_Object CC_pdif(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0145, v0099;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pdif");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0145 = v0001;
    v0099 = v0000;
/* end of prologue */
    stack[0] = v0099;
    fn = elt(env, 1); /* pneg */
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-1];
    {
        Lisp_Object v0132 = stack[0];
        popv(2);
        fn = elt(env, 2); /* psum */
        return (*qfn2(fn))(qenv(fn), v0132, v0145);
    }
/* error exit handlers */
v0147:
    popv(2);
    return nil;
}



/* Code for th_match0 */

static Lisp_Object CC_th_match0(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0032, v0093;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for th_match0");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0093 = v0000;
/* end of prologue */
    v0033 = v0093;
    v0032 = qcar(v0033);
    v0033 = stack[0];
    v0033 = qcar(v0033);
    if (equal(v0032, v0033)) goto v0132;
    v0033 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0033); }

v0132:
    v0033 = v0093;
    v0033 = qcdr(v0033);
    v0033 = qcar(v0033);
    stack[-1] = Llength(nil, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-2];
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    v0033 = qcar(v0033);
    v0033 = Llength(nil, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    v0033 = (equal(stack[-1], v0033) ? lisp_true : nil);
    { popv(3); return onevalue(v0033); }
/* error exit handlers */
v0104:
    popv(3);
    return nil;
}



/* Code for general!-times!-mod!-p */

static Lisp_Object CC_generalKtimesKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0098, v0220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-times-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0098 = stack[-2];
    if (v0098 == nil) goto v0105;
    v0098 = stack[-1];
    v0098 = (v0098 == nil ? lisp_true : nil);
    goto v0051;

v0051:
    if (v0098 == nil) goto v0016;
    v0098 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v0098); }

v0016:
    v0098 = stack[-2];
    if (!consp(v0098)) goto v0035;
    v0098 = stack[-2];
    v0098 = qcar(v0098);
    v0098 = (consp(v0098) ? nil : lisp_true);
    goto v0034;

v0034:
    if (v0098 == nil) goto v0091;
    v0220 = stack[-1];
    v0098 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* gen!-mult!-by!-const!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0220, v0098);
    }

v0091:
    v0098 = stack[-1];
    if (!consp(v0098)) goto v0029;
    v0098 = stack[-1];
    v0098 = qcar(v0098);
    v0098 = (consp(v0098) ? nil : lisp_true);
    goto v0081;

v0081:
    if (v0098 == nil) goto v0139;
    v0220 = stack[-2];
    v0098 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* gen!-mult!-by!-const!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0220, v0098);
    }

v0139:
    v0098 = stack[-2];
    v0098 = qcar(v0098);
    v0098 = qcar(v0098);
    v0220 = qcar(v0098);
    v0098 = stack[-1];
    v0098 = qcar(v0098);
    v0098 = qcar(v0098);
    v0098 = qcar(v0098);
    if (equal(v0220, v0098)) goto v0122;
    v0098 = stack[-2];
    v0098 = qcar(v0098);
    v0098 = qcar(v0098);
    v0220 = qcar(v0098);
    v0098 = stack[-1];
    v0098 = qcar(v0098);
    v0098 = qcar(v0098);
    v0098 = qcar(v0098);
    fn = elt(env, 4); /* ordop */
    v0098 = (*qfn2(fn))(qenv(fn), v0220, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    if (v0098 == nil) goto v0107;
    v0098 = stack[-2];
    v0098 = qcar(v0098);
    stack[-3] = qcar(v0098);
    v0098 = stack[-2];
    v0098 = qcar(v0098);
    v0220 = qcdr(v0098);
    v0098 = stack[-1];
    stack[0] = CC_generalKtimesKmodKp(env, v0220, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    v0098 = stack[-2];
    v0220 = qcdr(v0098);
    v0098 = stack[-1];
    v0098 = CC_generalKtimesKmodKp(env, v0220, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    {
        Lisp_Object v0225 = stack[-3];
        Lisp_Object v0188 = stack[0];
        popv(5);
        fn = elt(env, 5); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0225, v0188, v0098);
    }

v0107:
    v0098 = stack[-1];
    v0098 = qcar(v0098);
    stack[-3] = qcar(v0098);
    v0220 = stack[-2];
    v0098 = stack[-1];
    v0098 = qcar(v0098);
    v0098 = qcdr(v0098);
    stack[0] = CC_generalKtimesKmodKp(env, v0220, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    v0220 = stack[-2];
    v0098 = stack[-1];
    v0098 = qcdr(v0098);
    v0098 = CC_generalKtimesKmodKp(env, v0220, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    {
        Lisp_Object v0189 = stack[-3];
        Lisp_Object v0186 = stack[0];
        popv(5);
        fn = elt(env, 5); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0189, v0186, v0098);
    }

v0122:
    v0098 = stack[-2];
    v0220 = qcar(v0098);
    v0098 = stack[-1];
    fn = elt(env, 6); /* general!-times!-term!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v0220, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    v0098 = stack[-1];
    v0220 = qcar(v0098);
    v0098 = stack[-2];
    v0098 = qcdr(v0098);
    fn = elt(env, 6); /* general!-times!-term!-mod!-p */
    v0098 = (*qfn2(fn))(qenv(fn), v0220, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    fn = elt(env, 7); /* general!-plus!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0098);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    v0098 = stack[-2];
    v0220 = qcdr(v0098);
    v0098 = stack[-1];
    v0098 = qcdr(v0098);
    v0098 = CC_generalKtimesKmodKp(env, v0220, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    {
        Lisp_Object v0187 = stack[0];
        popv(5);
        fn = elt(env, 7); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0187, v0098);
    }

v0029:
    v0098 = qvalue(elt(env, 1)); /* t */
    goto v0081;

v0035:
    v0098 = qvalue(elt(env, 1)); /* t */
    goto v0034;

v0105:
    v0098 = qvalue(elt(env, 1)); /* t */
    goto v0051;
/* error exit handlers */
v0054:
    popv(5);
    return nil;
}



/* Code for mkprogn */

static Lisp_Object CC_mkprogn(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0140, v0081, v0029;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkprogn");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0081 = v0001;
    v0029 = v0000;
/* end of prologue */
    v0140 = v0081;
    v0047 = elt(env, 1); /* progn */
    if (!consp(v0140)) goto v0135;
    v0140 = qcar(v0140);
    if (!(v0140 == v0047)) goto v0135;
    v0047 = elt(env, 1); /* progn */
    v0140 = v0029;
    v0081 = qcdr(v0081);
    return list2star(v0047, v0140, v0081);

v0135:
    v0047 = elt(env, 1); /* progn */
    v0140 = v0029;
    return list3(v0047, v0140, v0081);
}



/* Code for monommultiplybyvariable */

static Lisp_Object CC_monommultiplybyvariable(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0333, v0124;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monommultiplybyvariable");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0124 = stack[-2];
    v0333 = (Lisp_Object)17; /* 1 */
    v0333 = *(Lisp_Object *)((char *)v0124 + (CELL-TAG_VECTOR) + ((int32_t)v0333/(16/CELL)));
    stack[-3] = v0333;
    goto v0132;

v0132:
    v0333 = stack[-3];
    v0333 = qcar(v0333);
    if (v0333 == nil) goto v0147;
    v0333 = stack[-3];
    v0124 = qcar(v0333);
    v0333 = stack[-1];
    v0333 = (Lisp_Object)greaterp2(v0124, v0333);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    v0333 = v0333 ? lisp_true : nil;
    env = stack[-4];
    if (v0333 == nil) goto v0147;
    v0333 = stack[-3];
    v0333 = qcdr(v0333);
    stack[-3] = v0333;
    goto v0132;

v0147:
    v0333 = stack[-3];
    v0333 = qcar(v0333);
    if (v0333 == nil) goto v0131;
    v0333 = stack[-3];
    v0124 = qcar(v0333);
    v0333 = stack[-1];
    if (!(equal(v0124, v0333))) goto v0131;

v0046:
    v0333 = nil;
    { popv(5); return onevalue(v0333); }

v0131:
    stack[0] = stack[-3];
    v0333 = stack[-3];
    v0124 = qcar(v0333);
    v0333 = stack[-3];
    v0333 = qcdr(v0333);
    v0333 = cons(v0124, v0333);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-4];
    v0124 = Lrplacd(nil, stack[0], v0333);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-4];
    v0333 = stack[-1];
    v0333 = Lrplaca(nil, v0124, v0333);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-4];
    stack[-1] = stack[-2];
    stack[0] = (Lisp_Object)1; /* 0 */
    v0124 = stack[-2];
    v0333 = (Lisp_Object)1; /* 0 */
    v0333 = *(Lisp_Object *)((char *)v0124 + (CELL-TAG_VECTOR) + ((int32_t)v0333/(16/CELL)));
    v0333 = add1(v0333);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0333;
    goto v0046;
/* error exit handlers */
v0138:
    popv(5);
    return nil;
}



/* Code for rl_simp */

static Lisp_Object CC_rl_simp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simp");
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
    v0005 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* rl_simp1 */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* rl_csimpl */
        return (*qfn1(fn))(qenv(fn), v0005);
    }
/* error exit handlers */
v0016:
    popv(1);
    return nil;
}



/* Code for color1 */

static Lisp_Object MS_CDECL CC_color1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0048, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0282, v0283, v0281, v0355;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "color1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for color1");
#endif
    if (stack >= stacklimit)
    {
        push3(v0048,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0048);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0048;
    stack[-1] = v0001;
    v0281 = v0000;
/* end of prologue */

v0010:
    v0282 = v0281;
    v0282 = qcar(v0282);
    v0282 = qcar(v0282);
    if (v0282 == nil) goto v0146;
    v0282 = v0281;
    v0282 = qcdr(v0282);
    v0282 = (v0282 == nil ? lisp_true : nil);
    goto v0099;

v0099:
    if (v0282 == nil) goto v0024;
    v0282 = stack[-1];
    if (v0282 == nil) goto v0102;
    v0282 = stack[-1];
    v0282 = qcar(v0282);
    stack[-2] = v0282;
    v0282 = stack[-1];
    v0282 = qcdr(v0282);
    stack[-1] = v0282;
    v0282 = v0281;
    v0283 = qcar(v0282);
    v0282 = stack[0];
    fn = elt(env, 7); /* addsq */
    v0282 = (*qfn2(fn))(qenv(fn), v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    stack[0] = v0282;
    v0282 = stack[-2];
    v0281 = v0282;
    goto v0010;

v0102:
    v0282 = v0281;
    v0283 = qcar(v0282);
    v0282 = stack[0];
    {
        popv(4);
        fn = elt(env, 7); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0283, v0282);
    }

v0024:
    v0283 = elt(env, 2); /* qg */
    v0282 = v0281;
    v0282 = qcdr(v0282);
    v0282 = Lassoc(nil, v0283, v0282);
    v0355 = v0282;
    if (v0282 == nil) goto v0062;
    v0282 = v0355;
    v0282 = qcdr(v0282);
    v0283 = qcar(v0282);
    v0282 = v0355;
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    if (v0283 == v0282) goto v0198;
    v0282 = v0355;
    v0282 = qcdr(v0282);
    v0283 = qcar(v0282);
    v0282 = v0355;
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    if (v0283 == v0282) goto v0124;
    v0282 = v0355;
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0283 = qcar(v0282);
    v0282 = v0355;
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    v0282 = (v0283 == v0282 ? lisp_true : nil);
    goto v0129;

v0129:
    if (v0282 == nil) goto v0134;
    v0283 = qvalue(elt(env, 3)); /* nil */
    v0282 = (Lisp_Object)17; /* 1 */
    v0282 = cons(v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    v0281 = ncons(v0282);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    v0283 = stack[-1];
    v0282 = stack[0];
    stack[-1] = v0283;
    stack[0] = v0282;
    goto v0010;

v0134:
    v0282 = v0281;
    v0283 = v0355;
    fn = elt(env, 8); /* removeg */
    v0282 = (*qfn2(fn))(qenv(fn), v0282, v0283);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    v0281 = v0282;
    v0282 = v0281;
    stack[-2] = qcar(v0282);
    v0282 = v0281;
    v0282 = qcdr(v0282);
    if (v0282 == nil) goto v0335;
    v0282 = v0281;
    v0283 = qcdr(v0282);
    v0282 = stack[-1];
    v0282 = cons(v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    v0283 = v0282;
    goto v0356;

v0356:
    v0282 = stack[0];
    v0281 = stack[-2];
    stack[-1] = v0283;
    stack[0] = v0282;
    goto v0010;

v0335:
    v0282 = stack[-1];
    v0283 = v0282;
    goto v0356;

v0124:
    v0282 = qvalue(elt(env, 1)); /* t */
    goto v0129;

v0198:
    v0282 = qvalue(elt(env, 1)); /* t */
    goto v0129;

v0062:
    v0283 = elt(env, 4); /* g3 */
    v0282 = v0281;
    v0282 = qcdr(v0282);
    v0282 = Lassoc(nil, v0283, v0282);
    v0355 = v0282;
    if (v0282 == nil) goto v0357;
    v0282 = v0355;
    v0282 = qcdr(v0282);
    v0283 = qcar(v0282);
    v0282 = v0355;
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    if (v0283 == v0282) goto v0186;
    v0282 = v0355;
    v0282 = qcdr(v0282);
    v0283 = qcar(v0282);
    v0282 = v0355;
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    if (v0283 == v0282) goto v0242;
    v0282 = v0355;
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0283 = qcar(v0282);
    v0282 = v0355;
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    v0282 = (v0283 == v0282 ? lisp_true : nil);
    goto v0189;

v0189:
    if (v0282 == nil) goto v0176;
    v0283 = qvalue(elt(env, 3)); /* nil */
    v0282 = (Lisp_Object)17; /* 1 */
    v0282 = cons(v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    v0281 = ncons(v0282);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    v0283 = stack[-1];
    v0282 = stack[0];
    stack[-1] = v0283;
    stack[0] = v0282;
    goto v0010;

v0176:
    v0282 = v0281;
    v0283 = v0355;
    fn = elt(env, 9); /* split3gv */
    v0282 = (*qfn2(fn))(qenv(fn), v0282, v0283);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    v0281 = v0282;
    v0282 = v0281;
    stack[-2] = qcar(v0282);
    v0282 = v0281;
    v0283 = qcdr(v0282);
    v0282 = stack[-1];
    v0283 = cons(v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    v0282 = stack[0];
    v0281 = stack[-2];
    stack[-1] = v0283;
    stack[0] = v0282;
    goto v0010;

v0242:
    v0282 = qvalue(elt(env, 1)); /* t */
    goto v0189;

v0186:
    v0282 = qvalue(elt(env, 1)); /* t */
    goto v0189;

v0357:
    stack[0] = elt(env, 5); /* "Invalid structure of c0-graph." */
    v0282 = v0281;
    if (v0282 == nil) goto v0358;
    v0282 = v0281;
    v0282 = qcdr(v0282);
    if (v0282 == nil) goto v0359;
    v0282 = elt(env, 6); /* times */
    v0283 = v0281;
    v0282 = cons(v0282, v0283);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    goto v0287;

v0287:
    v0282 = list2(stack[0], v0282);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-3];
    fn = elt(env, 10); /* cerror */
    v0282 = (*qfn1(fn))(qenv(fn), v0282);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    v0282 = nil;
    { popv(4); return onevalue(v0282); }

v0359:
    v0282 = v0281;
    v0282 = qcar(v0282);
    goto v0287;

v0358:
    v0282 = qvalue(elt(env, 3)); /* nil */
    goto v0287;

v0146:
    v0282 = qvalue(elt(env, 1)); /* t */
    goto v0099;
/* error exit handlers */
v0150:
    popv(4);
    return nil;
}



/* Code for qqe_simplterm */

static Lisp_Object CC_qqe_simplterm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0028, v0233;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplterm");
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
    v0031 = stack[0];
    if (!consp(v0031)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0031 = stack[0];
    fn = elt(env, 4); /* qqe_op */
    v0031 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-1];
    v0233 = v0031;
    v0028 = v0233;
    v0031 = elt(env, 1); /* (ltail rtail) */
    v0031 = Lmemq(nil, v0028, v0031);
    if (v0031 == nil) goto v0101;
    v0031 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); /* qqe_simplterm!-tail */
        return (*qfn1(fn))(qenv(fn), v0031);
    }

v0101:
    v0028 = v0233;
    v0031 = elt(env, 2); /* (lhead rhead) */
    v0031 = Lmemq(nil, v0028, v0031);
    if (v0031 == nil) goto v0140;
    v0031 = stack[0];
    {
        popv(2);
        fn = elt(env, 6); /* qqe_simplterm!-head */
        return (*qfn1(fn))(qenv(fn), v0031);
    }

v0140:
    v0028 = v0233;
    v0031 = elt(env, 3); /* (ladd radd) */
    v0031 = Lmemq(nil, v0028, v0031);
    if (v0031 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0031 = stack[0];
    {
        popv(2);
        fn = elt(env, 7); /* qqe_simplterm!-add */
        return (*qfn1(fn))(qenv(fn), v0031);
    }
/* error exit handlers */
v0076:
    popv(2);
    return nil;
}



/* Code for sf_idl */

static Lisp_Object CC_sf_idl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sf_idl");
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
    v0030 = stack[-2];
    if (!consp(v0030)) goto v0051;
    v0030 = stack[-2];
    v0030 = qcar(v0030);
    v0030 = (consp(v0030) ? nil : lisp_true);
    goto v0010;

v0010:
    if (v0030 == nil) goto v0084;
    v0030 = nil;
    { popv(5); return onevalue(v0030); }

v0084:
    v0030 = stack[-2];
    v0030 = qcar(v0030);
    v0030 = qcar(v0030);
    stack[-3] = qcar(v0030);
    v0030 = stack[-2];
    v0030 = qcar(v0030);
    v0030 = qcdr(v0030);
    stack[-1] = CC_sf_idl(env, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-4];
    v0030 = stack[-2];
    v0030 = qcdr(v0030);
    stack[0] = CC_sf_idl(env, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-4];
    v0030 = stack[-2];
    v0030 = qcar(v0030);
    v0030 = qcar(v0030);
    v0030 = qcar(v0030);
    v0030 = ncons(v0030);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-4];
    fn = elt(env, 2); /* lto_setminus */
    v0030 = (*qfn2(fn))(qenv(fn), stack[0], v0030);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-4];
    fn = elt(env, 3); /* setunion */
    v0030 = (*qfn2(fn))(qenv(fn), stack[-1], v0030);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    {
        Lisp_Object v0041 = stack[-3];
        popv(5);
        return cons(v0041, v0030);
    }

v0051:
    v0030 = qvalue(elt(env, 1)); /* t */
    goto v0010;
/* error exit handlers */
v0233:
    popv(5);
    return nil;
}



setup_type const u10_setup[] =
{
    {"plus:",                   too_few_2,      CC_plusT,      wrong_no_2},
    {"listsum",                 CC_listsum,     too_many_1,    wrong_no_1},
    {"scalopp",                 CC_scalopp,     too_many_1,    wrong_no_1},
    {"sqp",                     CC_sqp,         too_many_1,    wrong_no_1},
    {"mv-pow-+",                too_few_2,      CC_mvKpowKL,   wrong_no_2},
    {"subs3f1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_subs3f1},
    {"gcddd",                   too_few_2,      CC_gcddd,      wrong_no_2},
    {"adddummy1a",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_adddummy1a},
    {"idcons_ordp",             too_few_2,      CC_idcons_ordp,wrong_no_2},
    {"clear-column",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_clearKcolumn},
    {"setpage",                 too_few_2,      CC_setpage,    wrong_no_2},
    {"mkkl",                    too_few_2,      CC_mkkl,       wrong_no_2},
    {"split_f",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_split_f},
    {"totalcompare",            too_few_2,      CC_totalcompare,wrong_no_2},
    {"intexprnp",               too_few_2,      CC_intexprnp,  wrong_no_2},
    {"rl_external",             too_few_2,      CC_rl_external,wrong_no_2},
    {"aex_deg",                 too_few_2,      CC_aex_deg,    wrong_no_2},
    {"omvir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omvir},
    {"find_sub_df",             too_few_2,      CC_find_sub_df,wrong_no_2},
    {"spmultm2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_spmultm2},
    {"dm-minus",                CC_dmKminus,    too_many_1,    wrong_no_1},
    {"getcomb",                 too_few_2,      CC_getcomb,    wrong_no_2},
    {"dcombine",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_dcombine},
    {"statep*",                 CC_statepH,     too_many_1,    wrong_no_1},
    {"rnconc",                  too_few_2,      CC_rnconc,     wrong_no_2},
    {"lpriw",                   too_few_2,      CC_lpriw,      wrong_no_2},
    {"getel1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_getel1},
    {"red-weight1",             too_few_2,      CC_redKweight1,wrong_no_2},
    {"multop",                  too_few_2,      CC_multop,     wrong_no_2},
    {"red_divtestbe",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_red_divtestbe},
    {"leftzeros",               CC_leftzeros,   too_many_1,    wrong_no_1},
    {"b:extmult",               too_few_2,      CC_bTextmult,  wrong_no_2},
    {"general-times-term-mod-p",too_few_2,      CC_generalKtimesKtermKmodKp,wrong_no_2},
    {"removeg",                 too_few_2,      CC_removeg,    wrong_no_2},
    {"mri_pasf2mri",            too_few_2,      CC_mri_pasf2mri,wrong_no_2},
    {"isimplicit",              CC_isimplicit,  too_many_1,    wrong_no_1},
    {"bind",                    too_few_2,      CC_bind,       wrong_no_2},
    {"getmat",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_getmat},
    {"vdplength",               CC_vdplength,   too_many_1,    wrong_no_1},
    {"wedget2",                 too_few_2,      CC_wedget2,    wrong_no_2},
    {"greaterp:",               too_few_2,      CC_greaterpT,  wrong_no_2},
    {"deletemult*",             CC_deletemultH, too_many_1,    wrong_no_1},
    {"getelv",                  CC_getelv,      too_many_1,    wrong_no_1},
    {"prepsqxx",                CC_prepsqxx,    too_many_1,    wrong_no_1},
    {"pdif",                    too_few_2,      CC_pdif,       wrong_no_2},
    {"th_match0",               too_few_2,      CC_th_match0,  wrong_no_2},
    {"general-times-mod-p",     too_few_2,      CC_generalKtimesKmodKp,wrong_no_2},
    {"mkprogn",                 too_few_2,      CC_mkprogn,    wrong_no_2},
    {"monommultiplybyvariable", too_few_2,      CC_monommultiplybyvariable,wrong_no_2},
    {"rl_simp",                 CC_rl_simp,     too_many_1,    wrong_no_1},
    {"color1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_color1},
    {"qqe_simplterm",           CC_qqe_simplterm,too_many_1,   wrong_no_1},
    {"sf_idl",                  CC_sf_idl,      too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u10", (two_args *)"5732 9186708 2001748", 0}
};

/* end of generated code */
