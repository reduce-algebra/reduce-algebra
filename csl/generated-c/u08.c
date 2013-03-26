
/* $destdir\u08.c        Machine generated C code */

/* Signature: 00000000 26-Mar-2013 */

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
extern Lisp_Object gchook, resources, callstack, procstack, procmem;
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


/* Code for anform1 */

static Lisp_Object CC_anform1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0022;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for anform1");
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
    v0021 = stack[-1];
    v0021 = qcar(v0021);
    stack[-2] = v0021;
    v0021 = stack[-1];
    v0021 = qcdr(v0021);
    stack[-1] = v0021;
    v0021 = stack[-2];
    if (!consp(v0021)) goto v0023;
    v0021 = stack[-2];
    v0021 = CC_anform1(env, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-3];
    v0021 = stack[-1];
    {
        popv(4);
        fn = elt(env, 8); /* anforml */
        return (*qfn1(fn))(qenv(fn), v0021);
    }

v0023:
    v0021 = stack[-2];
    if (symbolp(v0021)) goto v0025;
    v0021 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0021); }

v0025:
    v0022 = stack[-2];
    v0021 = elt(env, 2); /* dclglb */
    v0021 = Lflagp(nil, v0022, v0021);
    env = stack[-3];
    if (v0021 == nil) goto v0026;
    v0022 = stack[-2];
    v0021 = elt(env, 3); /* glb2rf */
    v0021 = Lflagp(nil, v0022, v0021);
    env = stack[-3];
    if (!(v0021 == nil)) goto v0027;
    v0021 = stack[-2];
    v0022 = ncons(v0021);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-3];
    v0021 = elt(env, 3); /* glb2rf */
    v0021 = Lflag(nil, v0022, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-3];
    v0022 = stack[-2];
    v0021 = qvalue(elt(env, 4)); /* globs!* */
    v0021 = cons(v0022, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-3];
    qvalue(elt(env, 4)) = v0021; /* globs!* */
    goto v0027;

v0027:
    v0021 = stack[-1];
    {
        popv(4);
        fn = elt(env, 8); /* anforml */
        return (*qfn1(fn))(qenv(fn), v0021);
    }

v0026:
    v0022 = stack[-2];
    v0021 = qvalue(elt(env, 5)); /* locls!* */
    v0021 = Lassoc(nil, v0022, v0021);
    if (v0021 == nil) goto v0028;
    v0021 = stack[-1];
    {
        popv(4);
        fn = elt(env, 8); /* anforml */
        return (*qfn1(fn))(qenv(fn), v0021);
    }

v0028:
    v0021 = stack[-2];
    fn = elt(env, 9); /* add2calls */
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-3];
    stack[0] = stack[-2];
    v0021 = stack[-1];
    v0021 = Llength(nil, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-3];
    fn = elt(env, 10); /* checkargcount */
    v0021 = (*qfn2(fn))(qenv(fn), stack[0], v0021);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-3];
    v0022 = stack[-2];
    v0021 = elt(env, 6); /* noanl */
    v0021 = Lflagp(nil, v0022, v0021);
    env = stack[-3];
    if (!(v0021 == nil)) goto v0029;
    v0022 = stack[-2];
    v0021 = elt(env, 7); /* anlfn */
    v0021 = get(v0022, v0021);
    env = stack[-3];
    v0022 = v0021;
    if (v0021 == nil) goto v0030;
    v0021 = stack[-1];
    v0021 = Lapply1(nil, v0022, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    goto v0029;

v0029:
    v0021 = nil;
    { popv(4); return onevalue(v0021); }

v0030:
    v0021 = stack[-1];
    fn = elt(env, 8); /* anforml */
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    goto v0029;
/* error exit handlers */
v0024:
    popv(4);
    return nil;
}



/* Code for ckrn1 */

static Lisp_Object CC_ckrn1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0041;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ckrn1");
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
    stack[-1] = nil;
    v0040 = stack[0];
    if (!consp(v0040)) goto v0042;
    v0040 = stack[0];
    v0040 = qcar(v0040);
    v0040 = (consp(v0040) ? nil : lisp_true);
    goto v0023;

v0023:
    if (!(v0040 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v0043:
    v0040 = stack[0];
    v0040 = qcar(v0040);
    v0040 = qcdr(v0040);
    v0041 = CC_ckrn1(env, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-2];
    v0040 = stack[-1];
    fn = elt(env, 2); /* gck2 */
    v0040 = (*qfn2(fn))(qenv(fn), v0041, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-2];
    stack[-1] = v0040;
    v0040 = stack[0];
    v0040 = qcdr(v0040);
    if (v0040 == nil) goto v0045;
    v0040 = stack[0];
    v0040 = qcdr(v0040);
    if (!consp(v0040)) goto v0046;
    v0040 = stack[0];
    v0040 = qcdr(v0040);
    v0040 = qcar(v0040);
    v0040 = (consp(v0040) ? nil : lisp_true);
    goto v0047;

v0047:
    if (v0040 == nil) goto v0048;
    v0040 = qvalue(elt(env, 1)); /* t */
    goto v0049;

v0049:
    if (v0040 == nil) goto v0020;
    v0040 = stack[0];
    v0040 = qcdr(v0040);
    v0041 = CC_ckrn1(env, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-2];
    v0040 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* gck2 */
        return (*qfn2(fn))(qenv(fn), v0041, v0040);
    }

v0020:
    v0040 = stack[0];
    v0040 = qcdr(v0040);
    stack[0] = v0040;
    goto v0043;

v0048:
    v0040 = stack[0];
    v0040 = qcar(v0040);
    v0040 = qcar(v0040);
    v0041 = qcar(v0040);
    v0040 = stack[0];
    v0040 = qcdr(v0040);
    v0040 = qcar(v0040);
    v0040 = qcar(v0040);
    v0040 = qcar(v0040);
    v0040 = (v0041 == v0040 ? lisp_true : nil);
    v0040 = (v0040 == nil ? lisp_true : nil);
    goto v0049;

v0046:
    v0040 = qvalue(elt(env, 1)); /* t */
    goto v0047;

v0045:
    v0040 = stack[0];
    v0040 = qcar(v0040);
    v0040 = qcar(v0040);
    v0040 = qcar(v0040);
    fn = elt(env, 3); /* noncomp */
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-2];
    if (!(v0040 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0040 = stack[0];
    v0040 = qcar(v0040);
    v0041 = qcar(v0040);
    v0040 = stack[-1];
    v0040 = cons(v0041, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    popv(3);
    return ncons(v0040);

v0042:
    v0040 = qvalue(elt(env, 1)); /* t */
    goto v0023;
/* error exit handlers */
v0044:
    popv(3);
    return nil;
}



/* Code for rl_simpat */

static Lisp_Object CC_rl_simpat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simpat");
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
    v0023 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_simpat!* */
    v0023 = ncons(v0023);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-1];
    {
        Lisp_Object v0053 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0053, v0023);
    }
/* error exit handlers */
v0052:
    popv(2);
    return nil;
}



/* Code for ibalp_litp */

static Lisp_Object CC_ibalp_litp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0045;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_litp");
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
    v0020 = stack[0];
    fn = elt(env, 3); /* ibalp_atomp */
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-1];
    if (!(v0020 == nil)) { popv(2); return onevalue(v0020); }
    v0020 = stack[0];
    if (!consp(v0020)) goto v0057;
    v0020 = stack[0];
    v0020 = qcar(v0020);
    v0045 = v0020;
    goto v0052;

v0052:
    v0020 = elt(env, 1); /* not */
    if (v0045 == v0020) goto v0051;
    v0020 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0020); }

v0051:
    v0020 = stack[0];
    v0020 = qcdr(v0020);
    v0020 = qcar(v0020);
    {
        popv(2);
        fn = elt(env, 3); /* ibalp_atomp */
        return (*qfn1(fn))(qenv(fn), v0020);
    }

v0057:
    v0020 = stack[0];
    v0045 = v0020;
    goto v0052;
/* error exit handlers */
v0056:
    popv(2);
    return nil;
}



/* Code for evaluate!-mod!-p */

static Lisp_Object MS_CDECL CC_evaluateKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0058,
                         Lisp_Object v0006, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0040, v0041, v0069, v0070;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evaluate-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0006,v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0058,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0006;
    stack[-2] = v0058;
    stack[-3] = v0000;
/* end of prologue */

v0071:
    v0005 = stack[-3];
    if (!consp(v0005)) goto v0052;
    v0005 = stack[-3];
    v0005 = qcar(v0005);
    v0005 = (consp(v0005) ? nil : lisp_true);
    goto v0042;

v0042:
    if (!(v0005 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0040 = stack[-1];
    v0005 = (Lisp_Object)1; /* 0 */
    if (v0040 == v0005) goto v0043;
    v0005 = stack[-2];
    if (v0005 == nil) goto v0019;
    v0005 = stack[-3];
    v0005 = qcar(v0005);
    v0005 = qcar(v0005);
    v0040 = qcar(v0005);
    v0005 = stack[-2];
    if (equal(v0040, v0005)) goto v0072;
    v0005 = stack[-3];
    v0005 = qcar(v0005);
    stack[-4] = qcar(v0005);
    v0005 = stack[-3];
    v0005 = qcar(v0005);
    v0041 = qcdr(v0005);
    v0040 = stack[-2];
    v0005 = stack[-1];
    stack[0] = CC_evaluateKmodKp(env, 3, v0041, v0040, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-5];
    v0005 = stack[-3];
    v0041 = qcdr(v0005);
    v0040 = stack[-2];
    v0005 = stack[-1];
    v0005 = CC_evaluateKmodKp(env, 3, v0041, v0040, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-5];
    {
        Lisp_Object v0074 = stack[-4];
        Lisp_Object v0075 = stack[0];
        popv(6);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0074, v0075, v0005);
    }

v0072:
    v0005 = stack[-3];
    v0005 = qcar(v0005);
    v0070 = qcdr(v0005);
    v0005 = stack[-3];
    v0005 = qcar(v0005);
    v0005 = qcar(v0005);
    v0069 = qcdr(v0005);
    v0005 = stack[-3];
    v0041 = qcdr(v0005);
    v0040 = stack[-1];
    v0005 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* horner!-rule!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 5, v0070, v0069, v0041, v0040, v0005);
    }

v0019:
    v0005 = elt(env, 3); /* "Variable=NIL in EVALUATE-MOD-P" */
    {
        popv(6);
        fn = elt(env, 6); /* errorf */
        return (*qfn1(fn))(qenv(fn), v0005);
    }

v0043:
    v0005 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v0005;
    goto v0071;

v0052:
    v0005 = qvalue(elt(env, 1)); /* t */
    goto v0042;
/* error exit handlers */
v0073:
    popv(6);
    return nil;
}



/* Code for ident */

static Lisp_Object CC_ident(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0003;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ident");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0003 = v0000;
/* end of prologue */
    return onevalue(v0003);
}



/* Code for diplength */

static Lisp_Object CC_diplength(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0080;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diplength");
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
    stack[-1] = nil;
    goto v0071;

v0071:
    v0079 = stack[0];
    if (v0079 == nil) goto v0081;
    v0080 = (Lisp_Object)17; /* 1 */
    v0079 = stack[-1];
    v0079 = cons(v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-2];
    stack[-1] = v0079;
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    stack[0] = v0079;
    goto v0071;

v0081:
    v0079 = (Lisp_Object)1; /* 0 */
    v0080 = v0079;
    goto v0050;

v0050:
    v0079 = stack[-1];
    if (v0079 == nil) { popv(3); return onevalue(v0080); }
    v0079 = stack[-1];
    v0079 = qcar(v0079);
    v0079 = plus2(v0079, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-2];
    v0080 = v0079;
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    stack[-1] = v0079;
    goto v0050;
/* error exit handlers */
v0082:
    popv(3);
    return nil;
}



/* Code for divide!: */

static Lisp_Object MS_CDECL CC_divideT(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0058,
                         Lisp_Object v0006, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "divide:");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for divide:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0006,v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0058,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0006;
    stack[-2] = v0058;
    stack[-3] = v0000;
/* end of prologue */
    stack[0] = stack[-1];
    v0086 = stack[-2];
    v0086 = qcdr(v0086);
    v0086 = qcar(v0086);
    v0086 = Labsval(nil, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-5];
    fn = elt(env, 2); /* msd */
    v0086 = (*qfn1(fn))(qenv(fn), v0086);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-5];
    v0086 = add1(v0086);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-5];
    v0086 = plus2(stack[0], v0086);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-5];
    fn = elt(env, 3); /* conv!:mt */
    v0086 = (*qfn2(fn))(qenv(fn), stack[-3], v0086);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-5];
    stack[-3] = v0086;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v0086 = stack[-3];
    v0086 = qcdr(v0086);
    v0026 = qcar(v0086);
    v0086 = stack[-2];
    v0086 = qcdr(v0086);
    v0086 = qcar(v0086);
    stack[0] = quot2(v0026, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-5];
    v0086 = stack[-3];
    v0086 = qcdr(v0086);
    v0026 = qcdr(v0086);
    v0086 = stack[-2];
    v0086 = qcdr(v0086);
    v0086 = qcdr(v0086);
    v0086 = difference2(v0026, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-5];
    v0086 = list2star(stack[-4], stack[0], v0086);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-5];
    stack[-3] = v0086;
    v0026 = stack[-3];
    v0086 = stack[-1];
    {
        popv(6);
        fn = elt(env, 4); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v0026, v0086);
    }
/* error exit handlers */
v0012:
    popv(6);
    return nil;
}



/* Code for form1 */

static Lisp_Object MS_CDECL CC_form1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0058,
                         Lisp_Object v0006, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0178, v0179, v0180, v0181;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "form1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for form1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0006,v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0058,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0006;
    stack[-2] = v0058;
    stack[-3] = v0000;
/* end of prologue */

v0182:
    v0178 = stack[-3];
    if (!consp(v0178)) goto v0039;
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    if (!consp(v0178)) goto v0037;
    v0180 = stack[-3];
    v0179 = stack[-2];
    v0178 = stack[-1];
    {
        popv(6);
        fn = elt(env, 25); /* form2 */
        return (*qfnn(fn))(qenv(fn), 3, v0180, v0179, v0178);
    }

v0037:
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    if (symbolp(v0178)) goto v0029;
    v0178 = stack[-3];
    v0179 = qcar(v0178);
    v0178 = elt(env, 3); /* "operator" */
    fn = elt(env, 26); /* typerr */
    v0178 = (*qfn2(fn))(qenv(fn), v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    goto v0184;

v0184:
    v0179 = stack[-1];
    v0178 = elt(env, 6); /* symbolic */
    if (v0179 == v0178) goto v0185;
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    if (!symbolp(v0178)) v0178 = nil;
    else { v0178 = qfastgets(v0178);
           if (v0178 != nil) { v0178 = elt(v0178, 59); /* opfn */
#ifdef RECORD_GET
             if (v0178 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v0178 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v0178 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v0178 == SPID_NOPROP) v0178 = nil; else v0178 = lisp_true; }}
#endif
    goto v0186;

v0186:
    if (v0178 == nil) goto v0187;
    v0178 = stack[-3];
    fn = elt(env, 27); /* argnochk */
    v0178 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    goto v0187;

v0187:
    v0178 = stack[-3];
    v0180 = qcdr(v0178);
    v0179 = stack[-2];
    v0178 = stack[-1];
    fn = elt(env, 28); /* formlis */
    v0178 = (*qfnn(fn))(qenv(fn), 3, v0180, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    stack[-4] = v0178;
    v0179 = stack[-4];
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    if (equal(v0179, v0178)) goto v0188;
    v0178 = stack[-3];
    v0179 = qcar(v0178);
    v0178 = stack[-4];
    v0178 = cons(v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    goto v0189;

v0189:
    stack[0] = v0178;
    v0179 = stack[-1];
    v0178 = elt(env, 6); /* symbolic */
    if (v0179 == v0178) goto v0190;
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    if (!symbolp(v0178)) v0178 = nil;
    else { v0178 = qfastgets(v0178);
           if (v0178 != nil) { v0178 = elt(v0178, 36); /* stat */
#ifdef RECORD_GET
             if (v0178 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v0178 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v0178 == SPID_NOPROP) v0178 = nil; }}
#endif
    if (!(v0178 == nil)) goto v0191;
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    if (v0178 == nil) goto v0192;
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    v0179 = qcar(v0178);
    v0178 = elt(env, 18); /* quote */
    if (!consp(v0179)) goto v0193;
    v0179 = qcar(v0179);
    if (!(v0179 == v0178)) goto v0193;
    v0178 = qvalue(elt(env, 19)); /* !*micro!-version */
    if (v0178 == nil) goto v0194;
    v0178 = qvalue(elt(env, 20)); /* !*defn */
    v0178 = (v0178 == nil ? lisp_true : nil);
    goto v0195;

v0195:
    v0178 = (v0178 == nil ? lisp_true : nil);
    goto v0196;

v0196:
    if (!(v0178 == nil)) goto v0191;
    v0179 = stack[0];
    v0178 = stack[-2];
    fn = elt(env, 29); /* intexprnp */
    v0178 = (*qfn2(fn))(qenv(fn), v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    if (v0178 == nil) goto v0197;
    v0178 = qvalue(elt(env, 21)); /* !*composites */
    if (v0178 == nil) goto v0198;
    v0178 = qvalue(elt(env, 15)); /* nil */
    goto v0191;

v0191:
    if (v0178 == nil) goto v0199;
    v0179 = stack[0];
    v0178 = stack[-1];
    {
        popv(6);
        fn = elt(env, 30); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v0179, v0178);
    }

v0199:
    v0179 = stack[-1];
    v0178 = elt(env, 23); /* algebraic */
    if (v0179 == v0178) goto v0200;
    v0181 = stack[0];
    v0180 = stack[-2];
    v0179 = stack[-1];
    v0178 = elt(env, 23); /* algebraic */
    {
        popv(6);
        fn = elt(env, 31); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v0181, v0180, v0179, v0178);
    }

v0200:
    stack[0] = elt(env, 24); /* list */
    v0178 = stack[-3];
    v0179 = qcar(v0178);
    v0178 = stack[-2];
    fn = elt(env, 32); /* algid */
    v0179 = (*qfn2(fn))(qenv(fn), v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    v0178 = stack[-4];
    {
        Lisp_Object v0201 = stack[0];
        popv(6);
        return list2star(v0201, v0179, v0178);
    }

v0198:
    v0179 = qvalue(elt(env, 22)); /* current!-modulus */
    v0178 = (Lisp_Object)17; /* 1 */
    v0178 = (v0179 == v0178 ? lisp_true : nil);
    goto v0191;

v0197:
    v0178 = qvalue(elt(env, 15)); /* nil */
    goto v0191;

v0194:
    v0178 = qvalue(elt(env, 15)); /* nil */
    goto v0195;

v0193:
    v0178 = qvalue(elt(env, 15)); /* nil */
    goto v0196;

v0192:
    v0178 = qvalue(elt(env, 15)); /* nil */
    goto v0196;

v0190:
    v0178 = qvalue(elt(env, 9)); /* t */
    goto v0191;

v0188:
    v0178 = stack[-3];
    goto v0189;

v0185:
    v0178 = qvalue(elt(env, 9)); /* t */
    goto v0186;

v0029:
    v0178 = stack[-3];
    v0179 = qcar(v0178);
    v0178 = elt(env, 4); /* comment */
    if (v0179 == v0178) goto v0007;
    v0178 = stack[-3];
    v0179 = qcar(v0178);
    v0178 = elt(env, 5); /* noform */
    v0178 = Lflagp(nil, v0179, v0178);
    env = stack[-5];
    if (!(v0178 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    fn = elt(env, 33); /* arrayp */
    v0178 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    if (v0178 == nil) goto v0021;
    v0179 = stack[-1];
    v0178 = elt(env, 6); /* symbolic */
    if (!(v0179 == v0178)) goto v0021;
    stack[0] = elt(env, 7); /* getel */
    v0180 = stack[-3];
    v0179 = stack[-2];
    v0178 = stack[-1];
    fn = elt(env, 34); /* intargfn */
    v0178 = (*qfnn(fn))(qenv(fn), 3, v0180, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    {
        Lisp_Object v0202 = stack[0];
        popv(6);
        return list2(v0202, v0178);
    }

v0021:
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    if (v0178 == nil) goto v0203;
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    if (!symbolp(v0178)) v0179 = nil;
    else { v0179 = qfastgets(v0178);
           if (v0179 != nil) { v0179 = elt(v0179, 2); /* rtype */
#ifdef RECORD_GET
             if (v0179 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0179 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0179 == SPID_NOPROP) v0179 = nil; }}
#endif
    v0178 = elt(env, 8); /* vector */
    if (v0179 == v0178) goto v0204;
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    v0178 = qcar(v0178);
    v0178 = Lsimple_vectorp(nil, v0178);
    env = stack[-5];
    if (!(v0178 == nil)) goto v0205;
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    v0179 = qcar(v0178);
    v0178 = elt(env, 10); /* vecfn */
    v0178 = Lflagpcar(nil, v0179, v0178);
    env = stack[-5];
    goto v0205;

v0205:
    if (v0178 == nil) goto v0203;
    v0180 = stack[-3];
    v0179 = stack[-2];
    v0178 = stack[-1];
    {
        popv(6);
        fn = elt(env, 35); /* getvect */
        return (*qfnn(fn))(qenv(fn), 3, v0180, v0179, v0178);
    }

v0203:
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    if (!symbolp(v0178)) v0178 = nil;
    else { v0178 = qfastgets(v0178);
           if (v0178 != nil) { v0178 = elt(v0178, 48); /* modefn */
#ifdef RECORD_GET
             if (v0178 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v0178 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v0178 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v0178 == SPID_NOPROP) v0178 = nil; else v0178 = lisp_true; }}
#endif
    if (v0178 == nil) goto v0206;
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    v0181 = qcar(v0178);
    v0180 = stack[-2];
    v0179 = stack[-1];
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    {
        popv(6);
        fn = elt(env, 31); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v0181, v0180, v0179, v0178);
    }

v0206:
    v0178 = stack[-3];
    v0179 = qcar(v0178);
    v0178 = elt(env, 11); /* formfn */
    v0178 = get(v0179, v0178);
    env = stack[-5];
    stack[-4] = v0178;
    if (v0178 == nil) goto v0207;
    v0181 = stack[-4];
    v0180 = stack[-3];
    v0179 = stack[-2];
    v0178 = stack[-1];
    v0179 = Lapply3(nil, 4, v0181, v0180, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    v0178 = stack[-1];
    {
        popv(6);
        fn = elt(env, 30); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v0179, v0178);
    }

v0207:
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    if (!symbolp(v0178)) v0179 = nil;
    else { v0179 = qfastgets(v0178);
           if (v0179 != nil) { v0179 = elt(v0179, 36); /* stat */
#ifdef RECORD_GET
             if (v0179 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v0179 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v0179 == SPID_NOPROP) v0179 = nil; }}
#endif
    v0178 = elt(env, 12); /* rlis */
    if (v0179 == v0178) goto v0208;
    v0178 = stack[-3];
    v0179 = qcar(v0178);
    v0178 = elt(env, 13); /* !*comma!* */
    if (!(v0179 == v0178)) goto v0184;
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    v0178 = qcar(v0178);
    if (!consp(v0178)) goto v0209;
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    v0178 = qcdr(v0178);
    v0178 = qcar(v0178);
    if (!consp(v0178)) goto v0210;
    v0178 = qvalue(elt(env, 15)); /* nil */
    goto v0211;

v0211:
    if (v0178 == nil) goto v0212;
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    fn = elt(env, 36); /* blocktyperr */
    v0178 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    goto v0184;

v0212:
    stack[-4] = elt(env, 16); /* rlisp */
    stack[0] = (Lisp_Object)161; /* 10 */
    v0179 = elt(env, 17); /* "Syntax error: , invalid after" */
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    v0178 = qcar(v0178);
    v0178 = list2(v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    fn = elt(env, 37); /* rerror */
    v0178 = (*qfnn(fn))(qenv(fn), 3, stack[-4], stack[0], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    goto v0184;

v0210:
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    v0178 = qcar(v0178);
    v0179 = qcar(v0178);
    v0178 = elt(env, 14); /* type */
    v0178 = Lflagp(nil, v0179, v0178);
    env = stack[-5];
    goto v0211;

v0209:
    v0178 = qvalue(elt(env, 15)); /* nil */
    goto v0211;

v0208:
    v0180 = stack[-3];
    v0179 = stack[-2];
    v0178 = stack[-1];
    fn = elt(env, 38); /* formrlis */
    v0179 = (*qfnn(fn))(qenv(fn), 3, v0180, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    v0178 = stack[-1];
    {
        popv(6);
        fn = elt(env, 30); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v0179, v0178);
    }

v0204:
    v0178 = qvalue(elt(env, 9)); /* t */
    goto v0205;

v0007:
    v0178 = stack[-3];
    fn = elt(env, 39); /* lastpair */
    v0178 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-5];
    v0180 = qcar(v0178);
    v0179 = stack[-2];
    v0178 = stack[-1];
    stack[-3] = v0180;
    stack[-2] = v0179;
    stack[-1] = v0178;
    goto v0182;

v0039:
    v0178 = stack[-3];
    if (!(symbolp(v0178))) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0179 = stack[-3];
    v0178 = elt(env, 1); /* ed */
    if (v0179 == v0178) goto v0085;
    v0178 = stack[-3];
    if (!symbolp(v0178)) v0178 = nil;
    else { v0178 = qfastgets(v0178);
           if (v0178 != nil) { v0178 = elt(v0178, 48); /* modefn */
#ifdef RECORD_GET
             if (v0178 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v0178 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v0178 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v0178 == SPID_NOPROP) v0178 = nil; else v0178 = lisp_true; }}
#endif
    if (v0178 == nil) goto v0076;
    v0178 = stack[-3];
    {
        popv(6);
        fn = elt(env, 40); /* set!-global!-mode */
        return (*qfn1(fn))(qenv(fn), v0178);
    }

v0076:
    v0179 = stack[-1];
    v0178 = elt(env, 2); /* idfn */
    v0178 = get(v0179, v0178);
    stack[-4] = v0178;
    if (v0178 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0180 = stack[-4];
    v0179 = stack[-3];
    v0178 = stack[-2];
        popv(6);
        return Lapply2(nil, 3, v0180, v0179, v0178);

v0085:
    v0178 = stack[-3];
    popv(6);
    return ncons(v0178);
/* error exit handlers */
v0183:
    popv(6);
    return nil;
}



/* Code for compactfmatch2 */

static Lisp_Object CC_compactfmatch2(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0045;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compactfmatch2");
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
    v0020 = stack[0];
    if (!consp(v0020)) goto v0090;
    v0020 = stack[0];
    v0045 = qcar(v0020);
    v0020 = elt(env, 2); /* !~ */
    if (v0045 == v0020) goto v0050;
    v0020 = stack[0];
    v0020 = qcar(v0020);
    stack[-1] = CC_compactfmatch2(env, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-2];
    v0020 = stack[0];
    v0020 = qcdr(v0020);
    v0020 = CC_compactfmatch2(env, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    {
        Lisp_Object v0076 = stack[-1];
        popv(3);
        return Lappend(nil, v0076, v0020);
    }

v0050:
    v0020 = stack[0];
    popv(3);
    return ncons(v0020);

v0090:
    v0020 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0020); }
/* error exit handlers */
v0214:
    popv(3);
    return nil;
}



/* Code for multop */

static Lisp_Object CC_multop(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0058)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0018, v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0058;
    v0082 = v0000;
/* end of prologue */
    v0017 = qvalue(elt(env, 1)); /* kord!* */
    if (v0017 == nil) goto v0054;
    v0017 = v0082;
    v0018 = qcar(v0017);
    v0017 = elt(env, 2); /* k!* */
    if (v0018 == v0017) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0018 = v0082;
    v0017 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); /* rmultpf */
        return (*qfn2(fn))(qenv(fn), v0018, v0017);
    }

v0054:
    v0018 = v0082;
    v0017 = (Lisp_Object)17; /* 1 */
    v0017 = cons(v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-1];
    v0018 = ncons(v0017);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-1];
    v0017 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* multf */
        return (*qfn2(fn))(qenv(fn), v0018, v0017);
    }
/* error exit handlers */
v0066:
    popv(2);
    return nil;
}



/* Code for mo!=lexcomp */

static Lisp_Object CC_moMlexcomp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0058)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0175, v0016, v0176, v0216;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=lexcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0016 = v0058;
    v0176 = v0000;
/* end of prologue */

v0097:
    v0175 = v0176;
    if (v0175 == nil) goto v0050;
    v0175 = v0016;
    if (v0175 == nil) goto v0028;
    v0175 = v0176;
    v0216 = qcar(v0175);
    v0175 = v0016;
    v0175 = qcar(v0175);
    if (equal(v0216, v0175)) goto v0217;
    v0175 = v0176;
    v0175 = qcar(v0175);
    v0016 = qcar(v0016);
    if (((int32_t)(v0175)) > ((int32_t)(v0016))) goto v0076;
    v0175 = (Lisp_Object)-15; /* -1 */
    return onevalue(v0175);

v0076:
    v0175 = (Lisp_Object)17; /* 1 */
    return onevalue(v0175);

v0217:
    v0175 = v0176;
    v0175 = qcdr(v0175);
    v0176 = v0175;
    v0175 = v0016;
    v0175 = qcdr(v0175);
    v0016 = v0175;
    goto v0097;

v0028:
    v0175 = elt(env, 1); /* (0) */
    v0016 = v0175;
    goto v0097;

v0050:
    v0175 = v0016;
    if (v0175 == nil) goto v0052;
    v0175 = elt(env, 1); /* (0) */
    v0176 = v0175;
    goto v0097;

v0052:
    v0175 = (Lisp_Object)1; /* 0 */
    return onevalue(v0175);
}



/* Code for th_match0 */

static Lisp_Object CC_th_match0(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0058)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0020, v0045;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for th_match0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0058;
    v0045 = v0000;
/* end of prologue */
    v0019 = v0045;
    v0020 = qcar(v0019);
    v0019 = stack[0];
    v0019 = qcar(v0019);
    if (equal(v0020, v0019)) goto v0054;
    v0019 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0019); }

v0054:
    v0019 = v0045;
    v0019 = qcdr(v0019);
    v0019 = qcar(v0019);
    stack[-1] = Llength(nil, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-2];
    v0019 = stack[0];
    v0019 = qcdr(v0019);
    v0019 = qcar(v0019);
    v0019 = Llength(nil, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    v0019 = (equal(stack[-1], v0019) ? lisp_true : nil);
    { popv(3); return onevalue(v0019); }
/* error exit handlers */
v0214:
    popv(3);
    return nil;
}



/* Code for ofsf_smwmkatl */

static Lisp_Object MS_CDECL CC_ofsf_smwmkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0058,
                         Lisp_Object v0006, Lisp_Object v0003, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0077, v0220, v0221, v0079, v0080;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smwmkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smwmkatl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0220 = v0003;
    v0221 = v0006;
    v0079 = v0058;
    v0080 = v0000;
/* end of prologue */
    v0077 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v0077 == nil) goto v0177;
    v0077 = v0080;
    {
        fn = elt(env, 2); /* cl_susimkatl */
        return (*qfnn(fn))(qenv(fn), 4, v0077, v0079, v0221, v0220);
    }

v0177:
    v0077 = v0080;
    {
        fn = elt(env, 3); /* ofsf_smmkatl */
        return (*qfnn(fn))(qenv(fn), 4, v0077, v0079, v0221, v0220);
    }
}



/* Code for qqe_ofsf_prepat */

static Lisp_Object CC_qqe_ofsf_prepat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_ofsf_prepat");
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
    v0219 = stack[0];
    fn = elt(env, 1); /* qqe_op */
    v0219 = (*qfn1(fn))(qenv(fn), v0219);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-1];
    fn = elt(env, 2); /* qqe_rqopp */
    v0219 = (*qfn1(fn))(qenv(fn), v0219);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-1];
    if (v0219 == nil) goto v0023;
    v0219 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); /* qqe_prepat */
        return (*qfn1(fn))(qenv(fn), v0219);
    }

v0023:
    v0219 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* ofsf_prepat */
        return (*qfn1(fn))(qenv(fn), v0219);
    }
/* error exit handlers */
v0213:
    popv(2);
    return nil;
}



/* Code for rl_gettype */

static Lisp_Object CC_rl_gettype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0213, v0057;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_gettype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0213 = v0000;
/* end of prologue */
    v0054 = v0213;
    if (!symbolp(v0054)) v0054 = nil;
    else { v0054 = qfastgets(v0054);
           if (v0054 != nil) { v0054 = elt(v0054, 4); /* avalue */
#ifdef RECORD_GET
             if (v0054 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0054 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0054 == SPID_NOPROP) v0054 = nil; }}
#endif
    v0057 = v0054;
    v0054 = v0057;
    if (v0054 == nil) goto v0042;
    v0054 = v0057;
    v0054 = qcar(v0054);
    return onevalue(v0054);

v0042:
    v0054 = v0213;
    if (!symbolp(v0054)) v0054 = nil;
    else { v0054 = qfastgets(v0054);
           if (v0054 != nil) { v0054 = elt(v0054, 2); /* rtype */
#ifdef RECORD_GET
             if (v0054 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0054 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0054 == SPID_NOPROP) v0054 = nil; }}
#endif
    return onevalue(v0054);
}



/* Code for expression */

static Lisp_Object CC_expression(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0225, v0226, v0227;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expression");
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
    v0227 = v0000;
/* end of prologue */
    v0225 = v0227;
    if (!consp(v0225)) goto v0081;
    v0225 = v0227;
    v0226 = qcar(v0225);
    v0225 = elt(env, 1); /* !:rd!: */
    if (v0226 == v0225) goto v0042;
    v0225 = v0227;
    v0226 = qcar(v0225);
    v0225 = qvalue(elt(env, 2)); /* unary!* */
    v0225 = Lassoc(nil, v0226, v0225);
    v0226 = v0225;
    if (v0225 == nil) goto v0048;
    v0225 = v0226;
    v0225 = qcdr(v0225);
    v0225 = qcdr(v0225);
    v0225 = qcar(v0225);
    if (v0225 == nil) goto v0065;
    v0225 = v0226;
    v0225 = qcdr(v0225);
    stack[0] = qcar(v0225);
    v0225 = v0227;
    v0225 = qcdr(v0225);
    v0226 = qcdr(v0226);
    v0226 = qcdr(v0226);
    v0226 = qcar(v0226);
    v0225 = list2(v0225, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-1];
    fn = elt(env, 5); /* apply */
    v0225 = (*qfn2(fn))(qenv(fn), stack[0], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    goto v0071;

v0071:
    v0225 = nil;
    { popv(2); return onevalue(v0225); }

v0065:
    v0225 = v0226;
    v0225 = qcdr(v0225);
    stack[0] = qcar(v0225);
    v0225 = v0227;
    v0225 = qcdr(v0225);
    v0225 = ncons(v0225);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-1];
    fn = elt(env, 5); /* apply */
    v0225 = (*qfn2(fn))(qenv(fn), stack[0], v0225);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    goto v0071;

v0048:
    v0225 = v0227;
    v0226 = qcar(v0225);
    v0225 = elt(env, 3); /* !*sq */
    if (v0226 == v0225) goto v0228;
    v0225 = v0227;
    fn = elt(env, 6); /* operator_fn */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    goto v0071;

v0228:
    v0225 = v0227;
    v0225 = qcdr(v0225);
    v0225 = qcar(v0225);
    fn = elt(env, 7); /* prepsq */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-1];
    v0225 = CC_expression(env, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    goto v0071;

v0042:
    v0225 = v0227;
    fn = elt(env, 8); /* printout */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    goto v0071;

v0081:
    v0225 = v0227;
    fn = elt(env, 9); /* f4 */
    v0225 = (*qfn1(fn))(qenv(fn), v0225);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    goto v0071;
/* error exit handlers */
v0031:
    popv(2);
    return nil;
}



/* Code for rd!:prep */

static Lisp_Object CC_rdTprep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:prep");
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
    v0217 = qvalue(elt(env, 1)); /* !*noconvert */
    if (v0217 == nil) goto v0097;
    v0217 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* rdprep1 */
        return (*qfn1(fn))(qenv(fn), v0217);
    }

v0097:
    v0217 = stack[0];
    fn = elt(env, 3); /* rd!:onep */
    v0217 = (*qfn1(fn))(qenv(fn), v0217);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-1];
    if (v0217 == nil) goto v0039;
    v0217 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v0217); }

v0039:
    v0217 = stack[0];
    fn = elt(env, 4); /* rd!:minus */
    v0217 = (*qfn1(fn))(qenv(fn), v0217);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-1];
    fn = elt(env, 3); /* rd!:onep */
    v0217 = (*qfn1(fn))(qenv(fn), v0217);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-1];
    if (v0217 == nil) goto v0028;
    v0217 = (Lisp_Object)-15; /* -1 */
    { popv(2); return onevalue(v0217); }

v0028:
    v0217 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* rdprep1 */
        return (*qfn1(fn))(qenv(fn), v0217);
    }
/* error exit handlers */
v0055:
    popv(2);
    return nil;
}



/* Code for c!:extadd */

static Lisp_Object CC_cTextadd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0058)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0239, v0173, v0174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:extadd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0058;
    stack[-2] = v0000;
/* end of prologue */
    stack[0] = nil;
    goto v0071;

v0071:
    v0239 = stack[-2];
    if (v0239 == nil) goto v0052;
    v0239 = stack[-1];
    if (v0239 == nil) goto v0217;
    v0239 = stack[-2];
    v0239 = qcar(v0239);
    v0173 = qcar(v0239);
    v0239 = stack[-1];
    v0239 = qcar(v0239);
    v0239 = qcar(v0239);
    if (equal(v0173, v0239)) goto v0017;
    v0239 = stack[-2];
    v0239 = qcar(v0239);
    v0173 = qcar(v0239);
    v0239 = stack[-1];
    v0239 = qcar(v0239);
    v0239 = qcar(v0239);
    fn = elt(env, 1); /* c!:ordexp */
    v0239 = (*qfn2(fn))(qenv(fn), v0173, v0239);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    if (v0239 == nil) goto v0021;
    v0239 = stack[-2];
    v0173 = qcar(v0239);
    v0239 = stack[0];
    v0239 = cons(v0173, v0239);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    stack[0] = v0239;
    v0239 = stack[-2];
    v0239 = qcdr(v0239);
    stack[-2] = v0239;
    goto v0071;

v0021:
    v0239 = stack[-1];
    v0173 = qcar(v0239);
    v0239 = stack[0];
    v0239 = cons(v0173, v0239);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    stack[0] = v0239;
    v0239 = stack[-1];
    v0239 = qcdr(v0239);
    stack[-1] = v0239;
    goto v0071;

v0017:
    stack[-3] = stack[0];
    v0239 = stack[-2];
    v0239 = qcar(v0239);
    v0173 = qcdr(v0239);
    v0239 = stack[-1];
    v0239 = qcar(v0239);
    v0239 = qcdr(v0239);
    fn = elt(env, 2); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0173, v0239);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    v0239 = stack[-2];
    v0173 = qcdr(v0239);
    v0239 = stack[-1];
    v0239 = qcdr(v0239);
    v0239 = CC_cTextadd(env, v0173, v0239);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    v0173 = stack[0];
    v0174 = v0173;
    if (v0174 == nil) goto v0065;
    v0174 = stack[-2];
    v0174 = qcar(v0174);
    v0174 = qcar(v0174);
    v0239 = acons(v0174, v0173, v0239);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0065;

v0065:
    {
        Lisp_Object v0241 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0241, v0239);
    }

v0217:
    v0173 = stack[0];
    v0239 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0173, v0239);
    }

v0052:
    v0173 = stack[0];
    v0239 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0173, v0239);
    }
/* error exit handlers */
v0240:
    popv(5);
    return nil;
}



/* Code for off_mod_reval */

static Lisp_Object CC_off_mod_reval(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for off_mod_reval");
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
    v0043 = qvalue(elt(env, 1)); /* !*modular */
    if (v0043 == nil) goto v0057;
    v0043 = elt(env, 2); /* modular */
    v0043 = ncons(v0043);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-1];
    fn = elt(env, 4); /* off */
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-1];
    v0043 = stack[0];
    fn = elt(env, 5); /* reval */
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-1];
    stack[0] = v0043;
    v0043 = elt(env, 2); /* modular */
    v0043 = ncons(v0043);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-1];
    fn = elt(env, 6); /* on */
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0057:
    v0043 = stack[0];
    fn = elt(env, 5); /* reval */
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    stack[0] = v0043;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0218:
    popv(2);
    return nil;
}



/* Code for chknewnam */

static Lisp_Object CC_chknewnam(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045, v0027, v0056, v0214;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chknewnam");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0056 = v0000;
/* end of prologue */

v0182:
    v0045 = v0056;
    if (!symbolp(v0045)) v0045 = nil;
    else { v0045 = qfastgets(v0045);
           if (v0045 != nil) { v0045 = elt(v0045, 28); /* newnam */
#ifdef RECORD_GET
             if (v0045 != SPID_NOPROP)
                record_get(elt(fastget_names, 28), 1);
             else record_get(elt(fastget_names, 28), 0),
                v0045 = nil; }
           else record_get(elt(fastget_names, 28), 0); }
#else
             if (v0045 == SPID_NOPROP) v0045 = nil; }}
#endif
    v0214 = v0045;
    if (v0045 == nil) goto v0023;
    v0027 = v0214;
    v0045 = v0056;
    v0045 = (v0027 == v0045 ? lisp_true : nil);
    goto v0039;

v0039:
    if (!(v0045 == nil)) return onevalue(v0056);
    v0045 = v0214;
    if (!(symbolp(v0045))) return onevalue(v0214);
    v0045 = v0214;
    v0056 = v0045;
    goto v0182;

v0023:
    v0045 = qvalue(elt(env, 1)); /* t */
    goto v0039;
}



/* Code for red_divtestbe */

static Lisp_Object MS_CDECL CC_red_divtestbe(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0058,
                         Lisp_Object v0006, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0080, v0017;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "red_divtestbe");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_divtestbe");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0006,v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0058,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0006;
    stack[-1] = v0058;
    stack[-2] = v0000;
/* end of prologue */

v0071:
    v0080 = stack[-2];
    if (v0080 == nil) goto v0051;
    v0080 = stack[-2];
    v0080 = qcar(v0080);
    fn = elt(env, 2); /* bas_dpecart */
    v0017 = (*qfn1(fn))(qenv(fn), v0080);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-3];
    v0080 = stack[0];
    v0080 = (Lisp_Object)lesseq2(v0017, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    v0080 = v0080 ? lisp_true : nil;
    env = stack[-3];
    if (v0080 == nil) goto v0077;
    v0080 = stack[-2];
    v0080 = qcar(v0080);
    fn = elt(env, 3); /* bas_dpoly */
    v0080 = (*qfn1(fn))(qenv(fn), v0080);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-3];
    fn = elt(env, 4); /* dp_lmon */
    v0017 = (*qfn1(fn))(qenv(fn), v0080);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-3];
    v0080 = stack[-1];
    fn = elt(env, 5); /* mo_vdivides!? */
    v0080 = (*qfn2(fn))(qenv(fn), v0017, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-3];
    if (v0080 == nil) goto v0077;
    v0080 = stack[-2];
    v0080 = qcar(v0080);
    { popv(4); return onevalue(v0080); }

v0077:
    v0080 = stack[-2];
    v0080 = qcdr(v0080);
    stack[-2] = v0080;
    goto v0071;

v0051:
    v0080 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0080); }
/* error exit handlers */
v0066:
    popv(4);
    return nil;
}



/* Code for gcddd */

static Lisp_Object CC_gcddd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0058)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0231, v0001, v0002;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcddd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0058;
    stack[-1] = v0000;
/* end of prologue */
    v0001 = stack[-1];
    v0231 = (Lisp_Object)17; /* 1 */
    if (v0001 == v0231) goto v0051;
    v0001 = stack[0];
    v0231 = (Lisp_Object)17; /* 1 */
    v0231 = (v0001 == v0231 ? lisp_true : nil);
    goto v0050;

v0050:
    if (v0231 == nil) goto v0071;
    v0231 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0231); }

v0071:
    v0231 = stack[-1];
    if (!consp(v0231)) goto v0067;
    v0231 = stack[0];
    if (!consp(v0231)) goto v0033;
    v0231 = stack[-1];
    v0231 = qcar(v0231);
    if (!symbolp(v0231)) v0231 = nil;
    else { v0231 = qfastgets(v0231);
           if (v0231 != nil) { v0231 = elt(v0231, 3); /* field */
#ifdef RECORD_GET
             if (v0231 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0231 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0231 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0231 == SPID_NOPROP) v0231 = nil; else v0231 = lisp_true; }}
#endif
    if (v0231 == nil) goto v0061;
    v0231 = qvalue(elt(env, 1)); /* t */
    goto v0222;

v0222:
    if (v0231 == nil) goto v0242;
    v0231 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0231); }

v0242:
    v0002 = stack[-1];
    v0001 = stack[0];
    v0231 = elt(env, 2); /* gcd */
    {
        popv(3);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0002, v0001, v0231);
    }

v0061:
    v0231 = stack[0];
    v0231 = qcar(v0231);
    if (!symbolp(v0231)) v0231 = nil;
    else { v0231 = qfastgets(v0231);
           if (v0231 != nil) { v0231 = elt(v0231, 3); /* field */
#ifdef RECORD_GET
             if (v0231 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0231 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0231 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0231 == SPID_NOPROP) v0231 = nil; else v0231 = lisp_true; }}
#endif
    goto v0222;

v0033:
    v0231 = stack[-1];
    v0231 = qcar(v0231);
    if (!symbolp(v0231)) v0231 = nil;
    else { v0231 = qfastgets(v0231);
           if (v0231 != nil) { v0231 = elt(v0231, 3); /* field */
#ifdef RECORD_GET
             if (v0231 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0231 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0231 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0231 == SPID_NOPROP) v0231 = nil; else v0231 = lisp_true; }}
#endif
    if (v0231 == nil) goto v0243;
    v0231 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0231); }

v0243:
    v0002 = stack[-1];
    v0001 = stack[0];
    v0231 = elt(env, 2); /* gcd */
    {
        popv(3);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0002, v0001, v0231);
    }

v0067:
    v0231 = stack[0];
    if (!consp(v0231)) goto v0076;
    v0231 = stack[0];
    fn = elt(env, 4); /* fieldp */
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-2];
    if (v0231 == nil) goto v0175;
    v0231 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0231); }

v0175:
    v0002 = stack[-1];
    v0001 = stack[0];
    v0231 = elt(env, 2); /* gcd */
    {
        popv(3);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0002, v0001, v0231);
    }

v0076:
    v0001 = stack[-1];
    v0231 = stack[0];
        popv(3);
        return Lgcd(nil, v0001, v0231);

v0051:
    v0231 = qvalue(elt(env, 1)); /* t */
    goto v0050;
/* error exit handlers */
v0074:
    popv(3);
    return nil;
}



/* Code for arintequiv!: */

static Lisp_Object CC_arintequivT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0082, v0065;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arintequiv:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0065 = v0000;
/* end of prologue */
    v0018 = v0065;
    v0018 = qcdr(v0018);
    if (is_number(v0018)) goto v0090;
    v0018 = v0065;
    v0018 = qcdr(v0018);
    v0082 = qcar(v0018);
    v0018 = elt(env, 1); /* !:rn!: */
    if (v0082 == v0018) goto v0218;
    v0018 = qvalue(elt(env, 2)); /* nil */
    goto v0052;

v0052:
    if (v0018 == nil) goto v0079;
    v0018 = v0065;
    v0018 = qcdr(v0018);
    v0018 = qcdr(v0018);
    v0018 = qcar(v0018);
    return onevalue(v0018);

v0079:
    v0018 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0018);

v0218:
    v0018 = v0065;
    v0018 = qcdr(v0018);
    v0018 = qcdr(v0018);
    v0082 = qcdr(v0018);
    v0018 = (Lisp_Object)17; /* 1 */
    v0018 = (v0082 == v0018 ? lisp_true : nil);
    goto v0052;

v0090:
    v0018 = v0065;
    v0018 = qcdr(v0018);
    return onevalue(v0018);
}



/* Code for mconv */

static Lisp_Object CC_mconv(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mconv");
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
    v0071 = qvalue(elt(env, 1)); /* dmode!* */
    fn = elt(env, 2); /* dmconv0 */
    v0071 = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-1];
    v0071 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); /* mconv1 */
        return (*qfn1(fn))(qenv(fn), v0071);
    }
/* error exit handlers */
v0050:
    popv(2);
    return nil;
}



/* Code for canonsq */

static Lisp_Object CC_canonsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0154, v0259, v0260;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for canonsq");
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
    v0154 = stack[-2];
    v0259 = qcdr(v0154);
    v0154 = (Lisp_Object)17; /* 1 */
    if (v0259 == v0154) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0154 = stack[-2];
    v0154 = qcar(v0154);
    if (v0154 == nil) goto v0028;
    stack[-1] = nil;
    v0154 = qvalue(elt(env, 2)); /* asymplis!* */
    if (v0154 == nil) goto v0020;
    v0154 = stack[-2];
    v0259 = qcar(v0154);
    v0154 = stack[-2];
    v0154 = qcdr(v0154);
    fn = elt(env, 7); /* gcdf */
    v0259 = (*qfn2(fn))(qenv(fn), v0259, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    stack[-3] = v0259;
    v0154 = (Lisp_Object)17; /* 1 */
    if (v0259 == v0154) goto v0020;
    v0154 = stack[-2];
    v0259 = qcar(v0154);
    v0154 = stack[-3];
    fn = elt(env, 8); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0259, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0154 = stack[-2];
    v0259 = qcdr(v0154);
    v0154 = stack[-3];
    fn = elt(env, 8); /* quotf */
    v0154 = (*qfn2(fn))(qenv(fn), v0259, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0154 = cons(stack[0], v0154);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    stack[-2] = v0154;
    goto v0020;

v0020:
    v0154 = stack[-2];
    v0154 = qcdr(v0154);
    fn = elt(env, 9); /* lnc */
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    stack[-3] = v0154;
    v0259 = stack[-3];
    v0154 = (Lisp_Object)17; /* 1 */
    if (v0259 == v0154) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0154 = stack[-3];
    if (!consp(v0154)) goto v0235;
    v0154 = stack[-3];
    v0154 = qcar(v0154);
    if (!symbolp(v0154)) v0259 = nil;
    else { v0259 = qfastgets(v0154);
           if (v0259 != nil) { v0259 = elt(v0259, 30); /* minusp */
#ifdef RECORD_GET
             if (v0259 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v0259 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v0259 == SPID_NOPROP) v0259 = nil; }}
#endif
    v0154 = stack[-3];
    v0154 = Lapply1(nil, v0259, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    if (v0154 == nil) goto v0048;
    v0154 = stack[-2];
    v0154 = qcar(v0154);
    fn = elt(env, 10); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0154 = stack[-2];
    v0154 = qcdr(v0154);
    fn = elt(env, 10); /* negf */
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0154 = cons(stack[0], v0154);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    stack[-2] = v0154;
    v0154 = stack[-3];
    v0259 = qcar(v0154);
    v0154 = elt(env, 3); /* difference */
    stack[0] = get(v0259, v0154);
    env = stack[-4];
    v0154 = stack[-3];
    v0154 = qcar(v0154);
    if (!symbolp(v0154)) v0259 = nil;
    else { v0259 = qfastgets(v0154);
           if (v0259 != nil) { v0259 = elt(v0259, 34); /* i2d */
#ifdef RECORD_GET
             if (v0259 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0259 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0259 == SPID_NOPROP) v0259 = nil; }}
#endif
    v0154 = (Lisp_Object)1; /* 0 */
    v0259 = Lapply1(nil, v0259, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0154 = stack[-3];
    v0154 = Lapply2(nil, 3, stack[0], v0259, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    stack[-3] = v0154;
    goto v0048;

v0048:
    v0154 = stack[-3];
    if (is_number(v0154)) goto v0261;
    v0259 = qvalue(elt(env, 4)); /* dmode!* */
    v0154 = elt(env, 5); /* unitsfn */
    v0154 = get(v0259, v0154);
    env = stack[-4];
    stack[-1] = v0154;
    goto v0262;

v0262:
    if (v0154 == nil) goto v0263;
    v0260 = stack[-1];
    v0259 = stack[-2];
    v0154 = stack[-3];
        popv(5);
        return Lapply2(nil, 3, v0260, v0259, v0154);

v0263:
    v0154 = qvalue(elt(env, 4)); /* dmode!* */
    if (!symbolp(v0154)) v0154 = nil;
    else { v0154 = qfastgets(v0154);
           if (v0154 != nil) { v0154 = elt(v0154, 3); /* field */
#ifdef RECORD_GET
             if (v0154 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0154 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0154 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0154 == SPID_NOPROP) v0154 = nil; else v0154 = lisp_true; }}
#endif
    if (v0154 == nil) goto v0264;
    v0154 = qvalue(elt(env, 6)); /* t */
    goto v0265;

v0265:
    if (v0154 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0259 = stack[-3];
    v0154 = stack[-2];
    {
        popv(5);
        fn = elt(env, 11); /* fieldconv */
        return (*qfn2(fn))(qenv(fn), v0259, v0154);
    }

v0264:
    v0154 = stack[-3];
    if (!consp(v0154)) goto v0156;
    v0154 = stack[-3];
    v0154 = qcar(v0154);
    if (!symbolp(v0154)) v0154 = nil;
    else { v0154 = qfastgets(v0154);
           if (v0154 != nil) { v0154 = elt(v0154, 3); /* field */
#ifdef RECORD_GET
             if (v0154 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0154 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0154 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0154 == SPID_NOPROP) v0154 = nil; else v0154 = lisp_true; }}
#endif
    goto v0265;

v0156:
    v0154 = qvalue(elt(env, 1)); /* nil */
    goto v0265;

v0261:
    v0154 = qvalue(elt(env, 1)); /* nil */
    goto v0262;

v0235:
    v0154 = stack[-3];
    v0154 = Lminusp(nil, v0154);
    env = stack[-4];
    if (v0154 == nil) goto v0048;
    v0154 = stack[-2];
    v0154 = qcar(v0154);
    fn = elt(env, 10); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0154 = stack[-2];
    v0154 = qcdr(v0154);
    fn = elt(env, 10); /* negf */
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    v0154 = cons(stack[0], v0154);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    stack[-2] = v0154;
    v0154 = stack[-3];
    v0154 = negate(v0154);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-4];
    stack[-3] = v0154;
    goto v0048;

v0028:
    v0259 = qvalue(elt(env, 1)); /* nil */
    v0154 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0259, v0154);
/* error exit handlers */
v0147:
    popv(5);
    return nil;
}



/* Code for searchtm */

static Lisp_Object CC_searchtm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0019;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for searchtm");
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
    v0019 = v0000;
/* end of prologue */
    v0038 = v0019;
    if (!consp(v0038)) goto v0050;
    v0038 = v0019;
    v0038 = qcar(v0038);
    v0038 = (consp(v0038) ? nil : lisp_true);
    goto v0081;

v0081:
    if (v0038 == nil) goto v0078;
    v0038 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0038); }

v0078:
    v0038 = v0019;
    v0038 = qcar(v0038);
    stack[0] = qcar(v0038);
    v0038 = v0019;
    v0038 = qcdr(v0038);
    fn = elt(env, 3); /* searchpl */
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    {
        Lisp_Object v0027 = stack[0];
        popv(1);
        return cons(v0027, v0038);
    }

v0050:
    v0038 = qvalue(elt(env, 1)); /* t */
    goto v0081;
/* error exit handlers */
v0045:
    popv(1);
    return nil;
}



/* Code for ibalp_atomp */

static Lisp_Object CC_ibalp_atomp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0083, v0086;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_atomp");
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
    v0086 = stack[0];
    v0083 = elt(env, 1); /* true */
    if (v0086 == v0083) goto v0050;
    v0086 = stack[0];
    v0083 = elt(env, 3); /* false */
    v0083 = (v0086 == v0083 ? lisp_true : nil);
    goto v0081;

v0081:
    if (v0083 == nil) goto v0045;
    v0083 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v0083); }

v0045:
    v0083 = stack[0];
    if (!consp(v0083)) goto v0221;
    v0083 = stack[0];
    v0083 = qcar(v0083);
    v0086 = v0083;
    goto v0056;

v0056:
    v0083 = elt(env, 4); /* equal */
    if (v0086 == v0083) goto v0019;
    v0083 = qvalue(elt(env, 5)); /* nil */
    { popv(2); return onevalue(v0083); }

v0019:
    v0083 = stack[0];
    fn = elt(env, 6); /* ibalp_arg2l */
    v0083 = (*qfn1(fn))(qenv(fn), v0083);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-1];
    if (symbolp(v0083)) goto v0084;
    v0083 = qvalue(elt(env, 5)); /* nil */
    { popv(2); return onevalue(v0083); }

v0084:
    v0083 = stack[0];
    fn = elt(env, 7); /* ibalp_arg2r */
    v0083 = (*qfn1(fn))(qenv(fn), v0083);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    v0083 = (is_number(v0083) ? lisp_true : nil);
    { popv(2); return onevalue(v0083); }

v0221:
    v0083 = stack[0];
    v0086 = v0083;
    goto v0056;

v0050:
    v0083 = qvalue(elt(env, 2)); /* t */
    goto v0081;
/* error exit handlers */
v0047:
    popv(2);
    return nil;
}



/* Code for aex_reducedtag */

static Lisp_Object CC_aex_reducedtag(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0050;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_reducedtag");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0050 = v0000;
/* end of prologue */
    v0050 = qcdr(v0050);
    v0050 = qcdr(v0050);
    v0050 = qcdr(v0050);
    v0050 = qcdr(v0050);
    v0050 = qcar(v0050);
    return onevalue(v0050);
}



/* Code for ps!:get!-term */

static Lisp_Object CC_psTgetKterm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0058)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0269, v0024, v0229;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:get-term");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0058;
    stack[-2] = v0000;
/* end of prologue */
    v0269 = stack[-2];
    fn = elt(env, 4); /* ps!:order */
    stack[0] = (*qfn1(fn))(qenv(fn), v0269);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-4];
    v0269 = stack[-2];
    fn = elt(env, 5); /* ps!:last!-term */
    v0269 = (*qfn1(fn))(qenv(fn), v0269);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v0269;
    v0024 = stack[-1];
    v0269 = stack[-3];
    v0269 = (Lisp_Object)lessp2(v0024, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    v0269 = v0269 ? lisp_true : nil;
    env = stack[-4];
    if (v0269 == nil) goto v0038;
    v0024 = qvalue(elt(env, 1)); /* nil */
    v0269 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0024, v0269);

v0038:
    v0024 = stack[-1];
    v0269 = stack[0];
    v0269 = (Lisp_Object)greaterp2(v0024, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    v0269 = v0269 ? lisp_true : nil;
    env = stack[-4];
    if (v0269 == nil) goto v0072;
    v0269 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0269); }

v0072:
    v0024 = stack[-1];
    v0269 = stack[-3];
    stack[0] = difference2(v0024, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-4];
    v0269 = stack[-2];
    if (!consp(v0269)) goto v0033;
    v0269 = stack[-2];
    v0024 = qcar(v0269);
    v0269 = elt(env, 3); /* !:ps!: */
    if (v0024 == v0269) goto v0059;
    v0269 = stack[-2];
    v0269 = qcar(v0269);
    if (!symbolp(v0269)) v0269 = nil;
    else { v0269 = qfastgets(v0269);
           if (v0269 != nil) { v0269 = elt(v0269, 8); /* dname */
#ifdef RECORD_GET
             if (v0269 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0269 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0269 == SPID_NOPROP) v0269 = nil; }}
#endif
    goto v0014;

v0014:
    if (v0269 == nil) goto v0226;
    v0229 = (Lisp_Object)1; /* 0 */
    v0024 = stack[-2];
    v0269 = (Lisp_Object)17; /* 1 */
    v0269 = list2star(v0229, v0024, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-4];
    v0269 = ncons(v0269);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-4];
    goto v0065;

v0065:
    v0269 = Lassoc(nil, stack[0], v0269);
    v0024 = v0269;
    v0269 = v0024;
    if (v0269 == nil) goto v0073;
    v0269 = v0024;
    v0269 = qcdr(v0269);
    { popv(5); return onevalue(v0269); }

v0073:
    v0024 = qvalue(elt(env, 1)); /* nil */
    v0269 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0024, v0269);

v0226:
    v0024 = stack[-2];
    v0269 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 6); /* ps!:getv */
    v0269 = (*qfn2(fn))(qenv(fn), v0024, v0269);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-4];
    goto v0065;

v0059:
    v0269 = qvalue(elt(env, 1)); /* nil */
    goto v0014;

v0033:
    v0269 = qvalue(elt(env, 2)); /* t */
    goto v0014;
/* error exit handlers */
v0173:
    popv(5);
    return nil;
}



/* Code for evenfree */

static Lisp_Object CC_evenfree(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0080, v0017;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evenfree");
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
    v0080 = stack[0];
    if (v0080 == nil) goto v0090;
    v0080 = stack[0];
    if (is_number(v0080)) goto v0052;
    v0080 = stack[0];
    v0080 = qcar(v0080);
    v0017 = ncons(v0080);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-2];
    v0080 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 2); /* qremd */
    v0080 = (*qfn2(fn))(qenv(fn), v0017, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-2];
    v0080 = qcdr(v0080);
    fn = elt(env, 3); /* absf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0080);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-2];
    v0080 = stack[0];
    v0080 = qcdr(v0080);
    v0080 = CC_evenfree(env, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-2];
    {
        Lisp_Object v0066 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* addf */
        return (*qfn2(fn))(qenv(fn), v0066, v0080);
    }

v0052:
    v0017 = stack[0];
    v0080 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 2); /* qremd */
    v0080 = (*qfn2(fn))(qenv(fn), v0017, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-2];
    v0080 = qcdr(v0080);
    {
        popv(3);
        fn = elt(env, 3); /* absf */
        return (*qfn1(fn))(qenv(fn), v0080);
    }

v0090:
    v0080 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0080); }
/* error exit handlers */
v0065:
    popv(3);
    return nil;
}



/* Code for getphystypesf */

static Lisp_Object CC_getphystypesf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystypesf");
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

v0182:
    v0068 = stack[0];
    if (v0068 == nil) goto v0050;
    v0068 = stack[0];
    fn = elt(env, 3); /* domain!*p */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-1];
    goto v0081;

v0081:
    if (v0068 == nil) goto v0213;
    v0068 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0068); }

v0213:
    v0068 = stack[0];
    v0068 = qcar(v0068);
    v0068 = qcar(v0068);
    v0068 = qcar(v0068);
    fn = elt(env, 4); /* getphystype */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-1];
    if (!(v0068 == nil)) { popv(2); return onevalue(v0068); }
    v0068 = stack[0];
    v0068 = qcar(v0068);
    v0068 = qcdr(v0068);
    stack[0] = v0068;
    goto v0182;

v0050:
    v0068 = qvalue(elt(env, 1)); /* t */
    goto v0081;
/* error exit handlers */
v0019:
    popv(2);
    return nil;
}



/* Code for add2resultbuf */

static Lisp_Object CC_add2resultbuf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0058)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0234, v0235, v0062;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add2resultbuf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0234 = v0058;
    stack[0] = v0000;
/* end of prologue */
    v0062 = v0234;
    v0235 = elt(env, 1); /* symbolic */
    if (v0062 == v0235) goto v0023;
    v0235 = stack[0];
    if (v0235 == nil) goto v0238;
    v0235 = qvalue(elt(env, 5)); /* nil */
    goto v0025;

v0025:
    if (v0235 == nil) goto v0015;
    v0235 = qvalue(elt(env, 2)); /* t */
    goto v0039;

v0039:
    if (v0235 == nil) goto v0071;
    v0234 = qvalue(elt(env, 5)); /* nil */
    { popv(2); return onevalue(v0234); }

v0071:
    v0235 = qvalue(elt(env, 3)); /* !*reduce4 */
    if (v0235 == nil) goto v0011;
    v0062 = elt(env, 7); /* ws */
    v0235 = stack[0];
    fn = elt(env, 11); /* putobject */
    v0234 = (*qfnn(fn))(qenv(fn), 3, v0062, v0235, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    goto v0084;

v0084:
    fn = elt(env, 12); /* terminalp */
    v0234 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    if (v0234 == nil) goto v0257;
    v0062 = qvalue(elt(env, 9)); /* statcounter */
    v0235 = stack[0];
    v0234 = qvalue(elt(env, 10)); /* resultbuflis!* */
    v0234 = acons(v0062, v0235, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    qvalue(elt(env, 10)) = v0234; /* resultbuflis!* */
    goto v0257;

v0257:
    v0234 = nil;
    { popv(2); return onevalue(v0234); }

v0011:
    v0234 = qvalue(elt(env, 5)); /* nil */
    v0234 = ncons(v0234);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    qvalue(elt(env, 8)) = v0234; /* alglist!* */
    v0234 = stack[0];
    qvalue(elt(env, 7)) = v0234; /* ws */
    goto v0084;

v0015:
    v0235 = qvalue(elt(env, 6)); /* !*nosave!* */
    goto v0039;

v0238:
    v0235 = qvalue(elt(env, 3)); /* !*reduce4 */
    if (v0235 == nil) goto v0020;
    v0062 = v0234;
    v0235 = elt(env, 4); /* empty_list */
    v0235 = (v0062 == v0235 ? lisp_true : nil);
    v0235 = (v0235 == nil ? lisp_true : nil);
    goto v0025;

v0020:
    v0235 = qvalue(elt(env, 2)); /* t */
    goto v0025;

v0023:
    v0235 = qvalue(elt(env, 2)); /* t */
    goto v0039;
/* error exit handlers */
v0061:
    popv(2);
    return nil;
}



/* Code for getel */

static Lisp_Object CC_getel(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0176, v0216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getel");
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
    v0016 = stack[-1];
    v0176 = qcar(v0016);
    v0016 = elt(env, 1); /* dimension */
    v0016 = get(v0176, v0016);
    env = stack[-3];
    stack[-2] = v0016;
    v0016 = stack[-2];
    stack[0] = Llength(nil, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-3];
    v0016 = stack[-1];
    v0016 = qcdr(v0016);
    v0016 = Llength(nil, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-3];
    if (equal(stack[0], v0016)) goto v0077;
    v0216 = elt(env, 2); /* rlisp */
    v0176 = (Lisp_Object)337; /* 21 */
    v0016 = elt(env, 3); /* "Incorrect array reference" */
    {
        popv(4);
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0216, v0176, v0016);
    }

v0077:
    v0016 = stack[-1];
    v0016 = qcar(v0016);
    if (!symbolp(v0016)) v0016 = nil;
    else { v0016 = qfastgets(v0016);
           if (v0016 != nil) { v0016 = elt(v0016, 4); /* avalue */
#ifdef RECORD_GET
             if (v0016 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0016 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0016 == SPID_NOPROP) v0016 = nil; }}
#endif
    v0016 = qcdr(v0016);
    v0216 = qcar(v0016);
    v0016 = stack[-1];
    v0176 = qcdr(v0016);
    v0016 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); /* getel1 */
        return (*qfnn(fn))(qenv(fn), 3, v0216, v0176, v0016);
    }
/* error exit handlers */
v0037:
    popv(4);
    return nil;
}



/* Code for pdmult */

static Lisp_Object CC_pdmult(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0058)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0250, v0261;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pdmult");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v0058;
    v0250 = v0000;
/* end of prologue */
    stack[-9] = v0250;
    v0250 = stack[-9];
    if (v0250 == nil) goto v0042;
    v0250 = stack[-9];
    v0250 = qcar(v0250);
    stack[-4] = v0250;
    v0250 = stack[-4];
    v0261 = qcar(v0250);
    v0250 = stack[-8];
    fn = elt(env, 2); /* pair */
    v0250 = (*qfn2(fn))(qenv(fn), v0261, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-10];
    stack[-3] = v0250;
    v0250 = stack[-3];
    if (v0250 == nil) goto v0079;
    v0250 = stack[-3];
    v0250 = qcar(v0250);
    v0261 = v0250;
    v0261 = qcar(v0261);
    v0250 = qcdr(v0250);
    v0250 = (Lisp_Object)(int32_t)((int32_t)v0261 + (int32_t)v0250 - TAG_FIXNUM);
    v0250 = ncons(v0250);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-10];
    stack[-1] = v0250;
    stack[-2] = v0250;
    goto v0068;

v0068:
    v0250 = stack[-3];
    v0250 = qcdr(v0250);
    stack[-3] = v0250;
    v0250 = stack[-3];
    if (v0250 == nil) goto v0049;
    stack[0] = stack[-1];
    v0250 = stack[-3];
    v0250 = qcar(v0250);
    v0261 = v0250;
    v0261 = qcar(v0261);
    v0250 = qcdr(v0250);
    v0250 = (Lisp_Object)(int32_t)((int32_t)v0261 + (int32_t)v0250 - TAG_FIXNUM);
    v0250 = ncons(v0250);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-10];
    v0250 = Lrplacd(nil, stack[0], v0250);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-10];
    v0250 = stack[-1];
    v0250 = qcdr(v0250);
    stack[-1] = v0250;
    goto v0068;

v0049:
    v0250 = stack[-2];
    v0261 = v0250;
    goto v0043;

v0043:
    v0250 = stack[-4];
    v0250 = qcdr(v0250);
    v0250 = cons(v0261, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-10];
    v0250 = ncons(v0250);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-10];
    stack[-6] = v0250;
    stack[-7] = v0250;
    goto v0050;

v0050:
    v0250 = stack[-9];
    v0250 = qcdr(v0250);
    stack[-9] = v0250;
    v0250 = stack[-9];
    if (v0250 == nil) { Lisp_Object res = stack[-7]; popv(11); return onevalue(res); }
    stack[-5] = stack[-6];
    v0250 = stack[-9];
    v0250 = qcar(v0250);
    stack[-4] = v0250;
    v0250 = stack[-4];
    v0261 = qcar(v0250);
    v0250 = stack[-8];
    fn = elt(env, 2); /* pair */
    v0250 = (*qfn2(fn))(qenv(fn), v0261, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-10];
    stack[-3] = v0250;
    v0250 = stack[-3];
    if (v0250 == nil) goto v0174;
    v0250 = stack[-3];
    v0250 = qcar(v0250);
    v0261 = v0250;
    v0261 = qcar(v0261);
    v0250 = qcdr(v0250);
    v0250 = (Lisp_Object)(int32_t)((int32_t)v0261 + (int32_t)v0250 - TAG_FIXNUM);
    v0250 = ncons(v0250);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-10];
    stack[-1] = v0250;
    stack[-2] = v0250;
    goto v0021;

v0021:
    v0250 = stack[-3];
    v0250 = qcdr(v0250);
    stack[-3] = v0250;
    v0250 = stack[-3];
    if (v0250 == nil) goto v0278;
    stack[0] = stack[-1];
    v0250 = stack[-3];
    v0250 = qcar(v0250);
    v0261 = v0250;
    v0261 = qcar(v0261);
    v0250 = qcdr(v0250);
    v0250 = (Lisp_Object)(int32_t)((int32_t)v0261 + (int32_t)v0250 - TAG_FIXNUM);
    v0250 = ncons(v0250);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-10];
    v0250 = Lrplacd(nil, stack[0], v0250);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-10];
    v0250 = stack[-1];
    v0250 = qcdr(v0250);
    stack[-1] = v0250;
    goto v0021;

v0278:
    v0250 = stack[-2];
    v0261 = v0250;
    goto v0044;

v0044:
    v0250 = stack[-4];
    v0250 = qcdr(v0250);
    v0250 = cons(v0261, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-10];
    v0250 = ncons(v0250);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-10];
    v0250 = Lrplacd(nil, stack[-5], v0250);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-10];
    v0250 = stack[-6];
    v0250 = qcdr(v0250);
    stack[-6] = v0250;
    goto v0050;

v0174:
    v0250 = qvalue(elt(env, 1)); /* nil */
    v0261 = v0250;
    goto v0044;

v0079:
    v0250 = qvalue(elt(env, 1)); /* nil */
    v0261 = v0250;
    goto v0043;

v0042:
    v0250 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v0250); }
/* error exit handlers */
v0248:
    popv(11);
    return nil;
}



/* Code for maprint */

static Lisp_Object CC_maprint(Lisp_Object env,
                         Lisp_Object v0058, Lisp_Object v0006)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0290, v0291, v0292;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maprint");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0006,v0058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0058,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0290 = v0006;
    stack[-3] = v0058;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* p!*!* */
    qvalue(elt(env, 1)) = nil; /* p!*!* */
    qvalue(elt(env, 1)) = v0290; /* p!*!* */
    stack[0] = nil;
    v0290 = qvalue(elt(env, 1)); /* p!*!* */
    stack[-2] = v0290;
    v0290 = stack[-3];
    if (v0290 == nil) goto v0054;
    v0290 = stack[-3];
    if (!consp(v0290)) goto v0028;
    v0290 = stack[-3];
    v0290 = qcar(v0290);
    if (!consp(v0290)) goto v0293;
    v0290 = stack[-3];
    v0291 = qcar(v0290);
    v0290 = stack[-2];
    v0290 = CC_maprint(env, v0291, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-5];
    goto v0219;

v0219:
    v0290 = elt(env, 5); /* "(" */
    fn = elt(env, 12); /* prin2!* */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-5];
    v0290 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 10)) = v0290; /* obrkp!* */
    v0290 = qvalue(elt(env, 8)); /* orig!* */
    stack[0] = v0290;
    v0291 = qvalue(elt(env, 9)); /* posn!* */
    v0290 = (Lisp_Object)289; /* 18 */
    v0290 = (Lisp_Object)lessp2(v0291, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    v0290 = v0290 ? lisp_true : nil;
    env = stack[-5];
    if (v0290 == nil) goto v0245;
    v0290 = qvalue(elt(env, 9)); /* posn!* */
    goto v0295;

v0295:
    qvalue(elt(env, 8)) = v0290; /* orig!* */
    v0290 = stack[-3];
    v0290 = qcdr(v0290);
    if (v0290 == nil) goto v0296;
    v0292 = elt(env, 11); /* !*comma!* */
    v0291 = (Lisp_Object)1; /* 0 */
    v0290 = stack[-3];
    v0290 = qcdr(v0290);
    fn = elt(env, 13); /* inprint */
    v0290 = (*qfnn(fn))(qenv(fn), 3, v0292, v0291, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-5];
    goto v0296;

v0296:
    v0290 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 10)) = v0290; /* obrkp!* */
    v0290 = stack[0];
    qvalue(elt(env, 8)) = v0290; /* orig!* */
    v0290 = elt(env, 6); /* ")" */
    fn = elt(env, 12); /* prin2!* */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-5];
    v0290 = stack[-3];
    goto v0071;

v0071:
    qvalue(elt(env, 1)) = stack[-4]; /* p!*!* */
    { popv(6); return onevalue(v0290); }

v0245:
    v0291 = qvalue(elt(env, 8)); /* orig!* */
    v0290 = (Lisp_Object)49; /* 3 */
    v0290 = plus2(v0291, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-5];
    goto v0295;

v0293:
    v0290 = stack[-3];
    v0290 = qcar(v0290);
    if (!symbolp(v0290)) v0290 = nil;
    else { v0290 = qfastgets(v0290);
           if (v0290 != nil) { v0290 = elt(v0290, 60); /* pprifn */
#ifdef RECORD_GET
             if (v0290 != SPID_NOPROP)
                record_get(elt(fastget_names, 60), 1);
             else record_get(elt(fastget_names, 60), 0),
                v0290 = nil; }
           else record_get(elt(fastget_names, 60), 0); }
#else
             if (v0290 == SPID_NOPROP) v0290 = nil; }}
#endif
    stack[-1] = v0290;
    if (v0290 == nil) goto v0035;
    v0292 = stack[-1];
    v0291 = stack[-3];
    v0290 = stack[-2];
    v0291 = Lapply2(nil, 3, v0292, v0291, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-5];
    v0290 = elt(env, 7); /* failed */
    if (!(v0291 == v0290)) goto v0235;

v0035:
    v0290 = stack[-3];
    v0290 = qcar(v0290);
    if (!symbolp(v0290)) v0290 = nil;
    else { v0290 = qfastgets(v0290);
           if (v0290 != nil) { v0290 = elt(v0290, 57); /* prifn */
#ifdef RECORD_GET
             if (v0290 != SPID_NOPROP)
                record_get(elt(fastget_names, 57), 1);
             else record_get(elt(fastget_names, 57), 0),
                v0290 = nil; }
           else record_get(elt(fastget_names, 57), 0); }
#else
             if (v0290 == SPID_NOPROP) v0290 = nil; }}
#endif
    stack[-1] = v0290;
    if (v0290 == nil) goto v0062;
    v0291 = stack[-1];
    v0290 = stack[-3];
    v0291 = Lapply1(nil, v0291, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-5];
    v0290 = elt(env, 7); /* failed */
    if (!(v0291 == v0290)) goto v0235;

v0062:
    v0290 = stack[-3];
    v0290 = qcar(v0290);
    if (!symbolp(v0290)) v0290 = nil;
    else { v0290 = qfastgets(v0290);
           if (v0290 != nil) { v0290 = elt(v0290, 23); /* infix */
#ifdef RECORD_GET
             if (v0290 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0290 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0290 == SPID_NOPROP) v0290 = nil; }}
#endif
    stack[-1] = v0290;
    if (v0290 == nil) goto v0297;
    v0291 = stack[-1];
    v0290 = stack[-2];
    v0290 = (Lisp_Object)greaterp2(v0291, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    v0290 = v0290 ? lisp_true : nil;
    env = stack[-5];
    v0290 = (v0290 == nil ? lisp_true : nil);
    stack[-2] = v0290;
    v0290 = stack[-2];
    if (v0290 == nil) goto v0298;
    v0290 = qvalue(elt(env, 8)); /* orig!* */
    stack[0] = v0290;
    v0290 = elt(env, 5); /* "(" */
    fn = elt(env, 12); /* prin2!* */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-5];
    v0291 = qvalue(elt(env, 9)); /* posn!* */
    v0290 = (Lisp_Object)289; /* 18 */
    v0290 = (Lisp_Object)lessp2(v0291, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    v0290 = v0290 ? lisp_true : nil;
    env = stack[-5];
    if (v0290 == nil) goto v0272;
    v0290 = qvalue(elt(env, 9)); /* posn!* */
    goto v0299;

v0299:
    qvalue(elt(env, 8)) = v0290; /* orig!* */
    goto v0298;

v0298:
    v0290 = stack[-3];
    v0292 = qcar(v0290);
    v0291 = stack[-1];
    v0290 = stack[-3];
    v0290 = qcdr(v0290);
    fn = elt(env, 13); /* inprint */
    v0290 = (*qfnn(fn))(qenv(fn), 3, v0292, v0291, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-5];
    v0290 = stack[-2];
    if (v0290 == nil) goto v0300;
    v0290 = elt(env, 6); /* ")" */
    fn = elt(env, 12); /* prin2!* */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-5];
    v0290 = stack[0];
    qvalue(elt(env, 8)) = v0290; /* orig!* */
    goto v0300;

v0300:
    v0290 = stack[-3];
    goto v0071;

v0272:
    v0291 = qvalue(elt(env, 8)); /* orig!* */
    v0290 = (Lisp_Object)49; /* 3 */
    v0290 = plus2(v0291, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-5];
    goto v0299;

v0297:
    v0290 = stack[-3];
    v0290 = qcar(v0290);
    fn = elt(env, 12); /* prin2!* */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-5];
    goto v0219;

v0235:
    v0290 = stack[-3];
    goto v0071;

v0028:
    v0290 = stack[-3];
    v0290 = Lsimple_vectorp(nil, v0290);
    env = stack[-5];
    if (v0290 == nil) goto v0055;
    v0291 = stack[-3];
    v0290 = qvalue(elt(env, 1)); /* p!*!* */
    fn = elt(env, 14); /* vec!-maprin */
    v0290 = (*qfn2(fn))(qenv(fn), v0291, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-5];
    goto v0217;

v0217:
    v0290 = stack[-3];
    goto v0071;

v0055:
    v0290 = stack[-3];
    if (is_number(v0290)) goto v0258;
    v0290 = qvalue(elt(env, 3)); /* t */
    goto v0077;

v0077:
    if (v0290 == nil) goto v0011;
    v0290 = stack[-3];
    fn = elt(env, 12); /* prin2!* */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-5];
    goto v0217;

v0011:
    v0290 = elt(env, 5); /* "(" */
    fn = elt(env, 12); /* prin2!* */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-5];
    v0290 = stack[-3];
    fn = elt(env, 12); /* prin2!* */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-5];
    v0290 = elt(env, 6); /* ")" */
    fn = elt(env, 12); /* prin2!* */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-5];
    goto v0217;

v0258:
    v0291 = stack[-3];
    v0290 = (Lisp_Object)1; /* 0 */
    v0290 = (Lisp_Object)lessp2(v0291, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    v0290 = v0290 ? lisp_true : nil;
    env = stack[-5];
    if (v0290 == nil) goto v0066;
    v0291 = stack[-2];
    v0290 = elt(env, 4); /* minus */
    if (!symbolp(v0290)) v0290 = nil;
    else { v0290 = qfastgets(v0290);
           if (v0290 != nil) { v0290 = elt(v0290, 23); /* infix */
#ifdef RECORD_GET
             if (v0290 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0290 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0290 == SPID_NOPROP) v0290 = nil; }}
#endif
    v0290 = (Lisp_Object)lesseq2(v0291, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    v0290 = v0290 ? lisp_true : nil;
    env = stack[-5];
    goto v0077;

v0066:
    v0290 = qvalue(elt(env, 3)); /* t */
    goto v0077;

v0054:
    v0290 = qvalue(elt(env, 2)); /* nil */
    goto v0071;
/* error exit handlers */
v0294:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* p!*!* */
    popv(6);
    return nil;
}



/* Code for conv!:bf2i */

static Lisp_Object CC_convTbf2i(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0219;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conv:bf2i");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0053 = v0000;
/* end of prologue */
    v0219 = v0053;
    v0219 = qcdr(v0219);
    v0219 = qcar(v0219);
    v0053 = qcdr(v0053);
    v0053 = qcdr(v0053);
        return Lash1(nil, v0219, v0053);
}



/* Code for undefdchk */

static Lisp_Object CC_undefdchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0215, v0043, v0217;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for undefdchk");
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
    v0043 = v0000;
/* end of prologue */
    v0217 = v0043;
    v0215 = elt(env, 1); /* defd */
    v0215 = Lflagp(nil, v0217, v0215);
    env = stack[0];
    if (v0215 == nil) goto v0213;
    v0215 = nil;
    { popv(1); return onevalue(v0215); }

v0213:
    v0215 = qvalue(elt(env, 2)); /* undefns!* */
    v0215 = cons(v0043, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[0];
    qvalue(elt(env, 2)) = v0215; /* undefns!* */
    { popv(1); return onevalue(v0215); }
/* error exit handlers */
v0218:
    popv(1);
    return nil;
}



/* Code for ofsf_ordatp */

static Lisp_Object CC_ofsf_ordatp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0058)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0080, v0017, v0018, v0082, v0065;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_ordatp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0082 = v0058;
    v0065 = v0000;
/* end of prologue */
    v0079 = v0065;
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    v0018 = v0079;
    v0079 = v0082;
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    v0017 = v0079;
    v0080 = v0018;
    v0079 = v0017;
    if (equal(v0080, v0079)) goto v0020;
    v0079 = v0018;
    v0080 = v0017;
    fn = elt(env, 1); /* ordp */
    v0079 = (*qfn2(fn))(qenv(fn), v0079, v0080);
    errexit();
    v0079 = (v0079 == nil ? lisp_true : nil);
    return onevalue(v0079);

v0020:
    v0079 = v0065;
    v0079 = qcar(v0079);
    v0080 = v0082;
    v0080 = qcar(v0080);
    {
        fn = elt(env, 2); /* ofsf_ordrelp */
        return (*qfn2(fn))(qenv(fn), v0079, v0080);
    }
}



/* Code for polynommultiplybymonom */

static Lisp_Object CC_polynommultiplybymonom(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0058)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0065, v0066;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynommultiplybymonom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0058;
    v0066 = v0000;
/* end of prologue */
    v0065 = v0066;
    if (v0065 == nil) goto v0097;
    v0065 = v0066;
    fn = elt(env, 2); /* polynomclone */
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-2];
    stack[-1] = v0065;
    v0066 = stack[0];
    v0065 = (Lisp_Object)17; /* 1 */
    v0065 = *(Lisp_Object *)((char *)v0066 + (CELL-TAG_VECTOR) + ((int32_t)v0065/(16/CELL)));
    stack[0] = v0065;
    goto v0177;

v0177:
    v0065 = stack[0];
    v0065 = qcar(v0065);
    if (v0065 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0066 = stack[-1];
    v0065 = stack[0];
    v0065 = qcar(v0065);
    fn = elt(env, 3); /* polynommultiplybyvariable */
    v0065 = (*qfn2(fn))(qenv(fn), v0066, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-2];
    v0065 = stack[0];
    v0065 = qcdr(v0065);
    stack[0] = v0065;
    goto v0177;

v0097:
    v0065 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0065); }
/* error exit handlers */
v0258:
    popv(3);
    return nil;
}



/* Code for processpartitie1 */

static Lisp_Object MS_CDECL CC_processpartitie1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0058,
                         Lisp_Object v0006, Lisp_Object v0003,
                         Lisp_Object v0090, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0275, v0239, v0173, v0174, v0288;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "processpartitie1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for processpartitie1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0090,v0003,v0006,v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0058,v0006,v0003,v0090);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0090;
    stack[-1] = v0003;
    v0173 = v0006;
    v0174 = v0058;
    stack[-2] = v0000;
/* end of prologue */

v0050:
    v0275 = stack[-2];
    if (v0275 == nil) goto v0023;
    v0275 = stack[-2];
    v0239 = qcar(v0275);
    v0275 = (Lisp_Object)1; /* 0 */
    if (v0239 == v0275) goto v0237;
    v0275 = stack[-2];
    v0239 = qcar(v0275);
    v0275 = v0174;
    if (equal(v0239, v0275)) goto v0228;
    v0275 = stack[-2];
    stack[-3] = qcar(v0275);
    v0275 = elt(env, 3); /* graadlijst */
    if (!symbolp(v0275)) v0275 = nil;
    else { v0275 = qfastgets(v0275);
           if (v0275 != nil) { v0275 = elt(v0275, 4); /* avalue */
#ifdef RECORD_GET
             if (v0275 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0275 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0275 == SPID_NOPROP) v0275 = nil; }}
#endif
    v0275 = qcdr(v0275);
    v0275 = qcar(v0275);
    v0239 = qcdr(v0275);
    v0275 = stack[-2];
    v0275 = qcar(v0275);
    fn = elt(env, 4); /* nth */
    v0275 = (*qfn2(fn))(qenv(fn), v0239, v0275);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-4];
    v0174 = qcdr(v0275);
    v0275 = stack[-2];
    v0173 = qcdr(v0275);
    v0239 = stack[-1];
    v0275 = stack[0];
    {
        Lisp_Object v0169 = stack[-3];
        popv(5);
        fn = elt(env, 5); /* processcarpartitie1 */
        return (*qfnn(fn))(qenv(fn), 5, v0169, v0174, v0173, v0239, v0275);
    }

v0228:
    v0288 = v0174;
    v0174 = v0173;
    v0275 = stack[-2];
    v0173 = qcdr(v0275);
    v0239 = stack[-1];
    v0275 = stack[0];
    {
        popv(5);
        fn = elt(env, 5); /* processcarpartitie1 */
        return (*qfnn(fn))(qenv(fn), 5, v0288, v0174, v0173, v0239, v0275);
    }

v0237:
    v0275 = stack[-2];
    v0275 = qcdr(v0275);
    stack[-2] = v0275;
    goto v0050;

v0023:
    v0275 = stack[-1];
    v0275 = qcar(v0275);
    if (v0275 == nil) goto v0078;
    stack[-3] = elt(env, 1); /* times */
    stack[-2] = elt(env, 2); /* ext */
    v0275 = stack[-1];
    v0275 = qcar(v0275);
    fn = elt(env, 6); /* ordn */
    v0275 = (*qfn1(fn))(qenv(fn), v0275);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-4];
    v0239 = Lreverse(nil, v0275);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-4];
    v0275 = stack[-1];
    v0275 = qcdr(v0275);
    v0239 = acons(stack[-2], v0239, v0275);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    v0275 = stack[0];
    {
        Lisp_Object v0168 = stack[-3];
        popv(5);
        return acons(v0168, v0239, v0275);
    }

v0078:
    v0173 = elt(env, 1); /* times */
    v0275 = stack[-1];
    v0239 = qcdr(v0275);
    v0275 = stack[0];
    popv(5);
    return acons(v0173, v0239, v0275);
/* error exit handlers */
v0241:
    popv(5);
    return nil;
}



/* Code for quotfx */

static Lisp_Object CC_quotfx(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0058)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045, v0027, v0056;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0027 = v0058;
    v0056 = v0000;
/* end of prologue */
    v0045 = qvalue(elt(env, 1)); /* !*exp */
    if (v0045 == nil) goto v0051;
    v0045 = qvalue(elt(env, 3)); /* !*mcd */
    v0045 = (v0045 == nil ? lisp_true : nil);
    goto v0050;

v0050:
    if (v0045 == nil) goto v0025;
    v0045 = v0056;
    {
        fn = elt(env, 4); /* quotf */
        return (*qfn2(fn))(qenv(fn), v0045, v0027);
    }

v0025:
    v0045 = v0056;
    {
        fn = elt(env, 5); /* quotfx1 */
        return (*qfn2(fn))(qenv(fn), v0045, v0027);
    }

v0051:
    v0045 = qvalue(elt(env, 2)); /* t */
    goto v0050;
}



/* Code for ibalp_simpat */

static Lisp_Object CC_ibalp_simpat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0078;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_simpat");
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
    v0078 = stack[-1];
    stack[-2] = qcar(v0078);
    v0078 = stack[-1];
    v0078 = qcdr(v0078);
    v0078 = qcar(v0078);
    fn = elt(env, 1); /* ibalp_simpterm */
    stack[0] = (*qfn1(fn))(qenv(fn), v0078);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    v0078 = stack[-1];
    v0078 = qcdr(v0078);
    v0078 = qcdr(v0078);
    v0078 = qcar(v0078);
    fn = elt(env, 1); /* ibalp_simpterm */
    v0078 = (*qfn1(fn))(qenv(fn), v0078);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-3];
    {
        Lisp_Object v0055 = stack[-2];
        Lisp_Object v0177 = stack[0];
        popv(4);
        fn = elt(env, 2); /* ibalp_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v0055, v0177, v0078);
    }
/* error exit handlers */
v0218:
    popv(4);
    return nil;
}



/* Code for aex_deg */

static Lisp_Object CC_aex_deg(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0058)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0042, v0052;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_deg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0058;
    v0042 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v0052 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-1];
    v0042 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* ratpoly_deg */
        return (*qfn2(fn))(qenv(fn), v0052, v0042);
    }
/* error exit handlers */
v0219:
    popv(2);
    return nil;
}



/* Code for omair */

static Lisp_Object MS_CDECL CC_omair(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0019;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omair");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omair");
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
    push2(nil, nil);
/* end of prologue */
    stack[0] = nil;
    fn = elt(env, 4); /* lex */
    v0038 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    fn = elt(env, 5); /* omobj */
    v0038 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    stack[-1] = v0038;
    v0038 = stack[-1];
    v0019 = qcar(v0038);
    v0038 = elt(env, 1); /* matrix */
    if (v0019 == v0038) goto v0218;
    fn = elt(env, 4); /* lex */
    v0038 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    fn = elt(env, 6); /* omobjs */
    v0038 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    stack[0] = v0038;
    v0038 = elt(env, 2); /* (!/ o m a) */
    fn = elt(env, 7); /* checktag */
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    goto v0218;

v0218:
    v0019 = stack[-1];
    v0038 = stack[0];
        popv(3);
        return Lappend(nil, v0019, v0038);
/* error exit handlers */
v0027:
    popv(3);
    return nil;
}



/* Code for ps!:expression */

static Lisp_Object CC_psTexpression(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0080, v0017;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:expression");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0017 = v0000;
/* end of prologue */
    v0079 = v0017;
    if (!consp(v0079)) goto v0050;
    v0079 = v0017;
    v0080 = qcar(v0079);
    v0079 = elt(env, 2); /* !:ps!: */
    if (v0080 == v0079) goto v0238;
    v0079 = v0017;
    v0079 = qcar(v0079);
    if (!symbolp(v0079)) v0079 = nil;
    else { v0079 = qfastgets(v0079);
           if (v0079 != nil) { v0079 = elt(v0079, 8); /* dname */
#ifdef RECORD_GET
             if (v0079 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0079 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0079 == SPID_NOPROP) v0079 = nil; }}
#endif
    goto v0081;

v0081:
    if (!(v0079 == nil)) return onevalue(v0017);
    v0080 = v0017;
    v0079 = (Lisp_Object)97; /* 6 */
    {
        fn = elt(env, 4); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v0080, v0079);
    }

v0238:
    v0079 = qvalue(elt(env, 3)); /* nil */
    goto v0081;

v0050:
    v0079 = qvalue(elt(env, 1)); /* t */
    goto v0081;
}



/* Code for dfn_prop */

static Lisp_Object CC_dfn_prop(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0065, v0066, v0232;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfn_prop");
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
    v0065 = v0000;
/* end of prologue */
    v0065 = qcdr(v0065);
    v0065 = Llength(nil, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[0];
    v0232 = v0065;
    v0066 = v0232;
    v0065 = (Lisp_Object)17; /* 1 */
    if (v0066 == v0065) goto v0050;
    v0066 = v0232;
    v0065 = (Lisp_Object)33; /* 2 */
    if (v0066 == v0065) goto v0057;
    v0066 = v0232;
    v0065 = (Lisp_Object)49; /* 3 */
    if (v0066 == v0065) goto v0025;
    v0065 = elt(env, 1); /* dfn */
    v0066 = v0232;
    {
        popv(1);
        fn = elt(env, 4); /* mkid */
        return (*qfn2(fn))(qenv(fn), v0065, v0066);
    }

v0025:
    v0065 = elt(env, 3); /* dfn3 */
    { popv(1); return onevalue(v0065); }

v0057:
    v0065 = elt(env, 2); /* dfn2 */
    { popv(1); return onevalue(v0065); }

v0050:
    v0065 = elt(env, 1); /* dfn */
    { popv(1); return onevalue(v0065); }
/* error exit handlers */
v0072:
    popv(1);
    return nil;
}



/* Code for mksgnsq */

static Lisp_Object CC_mksgnsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0258, v0015, v0175;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksgnsq");
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
    v0258 = v0015;
    fn = elt(env, 1); /* evenfree */
    v0258 = (*qfn1(fn))(qenv(fn), v0258);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-1];
    v0015 = v0258;
    if (v0258 == nil) goto v0051;
    v0175 = v0015;
    v0258 = (Lisp_Object)17; /* 1 */
    if (v0175 == v0258) goto v0055;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v0258 = (Lisp_Object)17; /* 1 */
    v0258 = cons(v0015, v0258);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-1];
    fn = elt(env, 2); /* mk!*sq */
    v0258 = (*qfn1(fn))(qenv(fn), v0258);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-1];
    v0258 = list2(stack[0], v0258);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v0258);
    }

v0055:
    v0015 = (Lisp_Object)-15; /* -1 */
    v0258 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v0015, v0258);

v0051:
    v0015 = (Lisp_Object)17; /* 1 */
    v0258 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v0015, v0258);
/* error exit handlers */
v0176:
    popv(2);
    return nil;
}



/* Code for covposp */

static Lisp_Object CC_covposp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0215, v0043;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for covposp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0215 = v0000;
/* end of prologue */

v0182:
    v0043 = v0215;
    if (v0043 == nil) goto v0090;
    v0043 = v0215;
    v0043 = qcar(v0043);
    if (!consp(v0043)) goto v0085;
    v0215 = qcdr(v0215);
    goto v0182;

v0085:
    v0215 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0215);

v0090:
    v0215 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0215);
}



/* Code for contrsp */

static Lisp_Object CC_contrsp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0058)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0214, v0076, v0077;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contrsp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0058;
    stack[-1] = v0000;
/* end of prologue */
    v0214 = stack[-1];
    v0214 = qcdr(v0214);
    v0077 = qcar(v0214);
    v0214 = stack[-1];
    v0214 = qcdr(v0214);
    v0214 = qcdr(v0214);
    v0076 = qcar(v0214);
    v0214 = stack[0];
    fn = elt(env, 1); /* contrsp2 */
    v0214 = (*qfnn(fn))(qenv(fn), 3, v0077, v0076, v0214);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-2];
    if (!(v0214 == nil)) { popv(3); return onevalue(v0214); }
    v0214 = stack[-1];
    v0214 = qcdr(v0214);
    v0214 = qcdr(v0214);
    v0077 = qcar(v0214);
    v0214 = stack[-1];
    v0214 = qcdr(v0214);
    v0076 = qcar(v0214);
    v0214 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* contrsp2 */
        return (*qfnn(fn))(qenv(fn), 3, v0077, v0076, v0214);
    }
/* error exit handlers */
v0079:
    popv(3);
    return nil;
}



/* Code for tokquote */

static Lisp_Object MS_CDECL CC_tokquote(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "tokquote");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tokquote");
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
/* end of prologue */
    fn = elt(env, 4); /* readch1 */
    v0050 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[0];
    qvalue(elt(env, 1)) = v0050; /* crchar!* */
    fn = elt(env, 5); /* rread */
    v0050 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[0];
    v0050 = Lmkquote(nil, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[0];
    qvalue(elt(env, 2)) = v0050; /* nxtsym!* */
    v0050 = (Lisp_Object)65; /* 4 */
    qvalue(elt(env, 3)) = v0050; /* ttype!* */
    v0050 = qvalue(elt(env, 2)); /* nxtsym!* */
    { popv(1); return onevalue(v0050); }
/* error exit handlers */
v0051:
    popv(1);
    return nil;
}



/* Code for cdarx */

static Lisp_Object CC_cdarx(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cdarx");
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
/* copy arguments values to proper place */
    v0023 = v0000;
/* end of prologue */
    v0042 = v0023;
    v0023 = elt(env, 1); /* cdar */
    fn = elt(env, 2); /* carx */
    v0023 = (*qfn2(fn))(qenv(fn), v0042, v0023);
    errexit();
    v0023 = qcdr(v0023);
    return onevalue(v0023);
}



/* Code for totalcompare */

static Lisp_Object CC_totalcompare(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0058)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0277, v0301, v0029;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for totalcompare");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0058;
    stack[-1] = v0000;
/* end of prologue */

v0081:
    v0301 = stack[-1];
    v0277 = stack[0];
    if (equal(v0301, v0277)) goto v0097;
    v0301 = stack[-1];
    v0277 = stack[0];
    fn = elt(env, 4); /* wulessp */
    v0277 = (*qfn2(fn))(qenv(fn), v0301, v0277);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    if (v0277 == nil) goto v0238;
    v0277 = elt(env, 2); /* less */
    { popv(3); return onevalue(v0277); }

v0238:
    v0301 = stack[0];
    v0277 = stack[-1];
    fn = elt(env, 4); /* wulessp */
    v0277 = (*qfn2(fn))(qenv(fn), v0301, v0277);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    if (v0277 == nil) goto v0177;
    v0277 = elt(env, 3); /* greater */
    { popv(3); return onevalue(v0277); }

v0177:
    v0277 = stack[-1];
    fn = elt(env, 5); /* wuconstantp */
    v0277 = (*qfn1(fn))(qenv(fn), v0277);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    if (v0277 == nil) goto v0016;
    v0301 = stack[-1];
    v0277 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* totalcompareconstants */
        return (*qfn2(fn))(qenv(fn), v0301, v0277);
    }

v0016:
    v0277 = stack[-1];
    v0277 = qcar(v0277);
    v0301 = qcdr(v0277);
    v0277 = stack[0];
    v0277 = qcar(v0277);
    v0277 = qcdr(v0277);
    v0277 = CC_totalcompare(env, v0301, v0277);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    v0029 = v0277;
    v0301 = v0029;
    v0277 = elt(env, 1); /* equal */
    if (!(v0301 == v0277)) { popv(3); return onevalue(v0029); }
    v0277 = stack[-1];
    v0301 = qcdr(v0277);
    v0277 = stack[0];
    v0277 = qcdr(v0277);
    stack[-1] = v0301;
    stack[0] = v0277;
    goto v0081;

v0097:
    v0277 = elt(env, 1); /* equal */
    { popv(3); return onevalue(v0277); }
/* error exit handlers */
v0236:
    popv(3);
    return nil;
}



/* Code for qsort */

static Lisp_Object CC_qsort(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0223, v0243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qsort");
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
    v0243 = v0000;
/* end of prologue */
    stack[-2] = nil;
    stack[-1] = nil;
    v0223 = v0243;
    if (v0223 == nil) goto v0042;
    v0223 = v0243;
    v0223 = qcar(v0223);
    stack[-3] = v0223;
    v0223 = v0243;
    v0223 = qcdr(v0223);
    stack[0] = v0223;
    goto v0050;

v0050:
    v0223 = stack[0];
    if (v0223 == nil) goto v0037;
    v0243 = stack[-3];
    v0223 = stack[0];
    v0223 = qcar(v0223);
    fn = elt(env, 2); /* ordop */
    v0223 = (*qfn2(fn))(qenv(fn), v0243, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-4];
    if (v0223 == nil) goto v0232;
    v0223 = stack[0];
    v0243 = qcar(v0223);
    v0223 = stack[-1];
    v0223 = cons(v0243, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-4];
    stack[-1] = v0223;
    goto v0055;

v0055:
    v0223 = stack[0];
    v0223 = qcdr(v0223);
    stack[0] = v0223;
    goto v0050;

v0232:
    v0223 = stack[0];
    v0243 = qcar(v0223);
    v0223 = stack[-2];
    v0223 = cons(v0243, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-4];
    stack[-2] = v0223;
    goto v0055;

v0037:
    v0223 = stack[-2];
    stack[0] = CC_qsort(env, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-4];
    stack[-2] = stack[-3];
    v0223 = stack[-1];
    v0223 = CC_qsort(env, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-4];
    v0223 = cons(stack[-2], v0223);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    {
        Lisp_Object v0048 = stack[0];
        popv(5);
        return Lappend(nil, v0048, v0223);
    }

v0042:
    v0223 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0223); }
/* error exit handlers */
v0293:
    popv(5);
    return nil;
}



/* Code for make!-univariate!-image!-mod!-p */

static Lisp_Object CC_makeKunivariateKimageKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0058)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0001, v0002;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-univariate-image-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0058;
    stack[-2] = v0000;
/* end of prologue */
    v0001 = stack[-2];
    if (!consp(v0001)) goto v0051;
    v0001 = stack[-2];
    v0001 = qcar(v0001);
    v0001 = (consp(v0001) ? nil : lisp_true);
    goto v0050;

v0050:
    if (v0001 == nil) goto v0068;
    v0001 = stack[-2];
    if (v0001 == nil) goto v0028;
    v0001 = stack[-2];
    v0001 = Lmodular_number(nil, v0001);
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 3); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v0001);
    }

v0028:
    v0001 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v0001); }

v0068:
    v0001 = stack[-2];
    v0001 = qcar(v0001);
    v0001 = qcar(v0001);
    v0002 = qcar(v0001);
    v0001 = stack[-1];
    if (equal(v0002, v0001)) goto v0221;
    v0001 = stack[-2];
    v0001 = qcar(v0001);
    v0001 = qcar(v0001);
    v0002 = qcar(v0001);
    v0001 = stack[-2];
    v0001 = qcar(v0001);
    v0001 = qcar(v0001);
    v0001 = qcdr(v0001);
    fn = elt(env, 4); /* image!-of!-power */
    stack[0] = (*qfn2(fn))(qenv(fn), v0002, v0001);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-4];
    v0001 = stack[-2];
    v0001 = qcar(v0001);
    v0002 = qcdr(v0001);
    v0001 = stack[-1];
    v0001 = CC_makeKunivariateKimageKmodKp(env, v0002, v0001);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-4];
    fn = elt(env, 5); /* times!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0001);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-4];
    v0001 = stack[-2];
    v0002 = qcdr(v0001);
    v0001 = stack[-1];
    v0001 = CC_makeKunivariateKimageKmodKp(env, v0002, v0001);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-4];
    {
        Lisp_Object v0022 = stack[0];
        popv(5);
        fn = elt(env, 6); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0022, v0001);
    }

v0221:
    v0001 = stack[-2];
    v0001 = qcar(v0001);
    stack[-3] = qcar(v0001);
    v0001 = stack[-2];
    v0001 = qcar(v0001);
    v0002 = qcdr(v0001);
    v0001 = stack[-1];
    stack[0] = CC_makeKunivariateKimageKmodKp(env, v0002, v0001);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-4];
    v0001 = stack[-2];
    v0002 = qcdr(v0001);
    v0001 = stack[-1];
    v0001 = CC_makeKunivariateKimageKmodKp(env, v0002, v0001);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-4];
    {
        Lisp_Object v0267 = stack[-3];
        Lisp_Object v0266 = stack[0];
        popv(5);
        fn = elt(env, 7); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0267, v0266, v0001);
    }

v0051:
    v0001 = qvalue(elt(env, 1)); /* t */
    goto v0050;
/* error exit handlers */
v0021:
    popv(5);
    return nil;
}



/* Code for writepri */

static Lisp_Object CC_writepri(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0058)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0219, v0054, v0213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for writepri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0058;
    v0219 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* eval */
    v0213 = (*qfn1(fn))(qenv(fn), v0219);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-1];
    v0054 = qvalue(elt(env, 1)); /* nil */
    v0219 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); /* assgnpri */
        return (*qfnn(fn))(qenv(fn), 3, v0213, v0054, v0219);
    }
/* error exit handlers */
v0085:
    popv(2);
    return nil;
}



/* Code for testred */

static Lisp_Object CC_testred(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0174, v0288, v0289;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testred");
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
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0288 = qvalue(elt(env, 2)); /* maxvar */
    v0174 = stack[0];
    v0174 = plus2(v0288, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-2];
    v0288 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0174/(16/CELL)));
    v0174 = (Lisp_Object)1; /* 0 */
    v0174 = *(Lisp_Object *)((char *)v0288 + (CELL-TAG_VECTOR) + ((int32_t)v0174/(16/CELL)));
    if (v0174 == nil) goto v0097;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0288 = qvalue(elt(env, 2)); /* maxvar */
    v0174 = stack[0];
    v0174 = plus2(v0288, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-2];
    v0288 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0174/(16/CELL)));
    v0174 = (Lisp_Object)17; /* 1 */
    v0174 = *(Lisp_Object *)((char *)v0288 + (CELL-TAG_VECTOR) + ((int32_t)v0174/(16/CELL)));
    v0174 = qcar(v0174);
    v0288 = qcar(v0174);
    v0174 = (Lisp_Object)33; /* 2 */
    v0174 = (Lisp_Object)lessp2(v0288, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    v0174 = v0174 ? lisp_true : nil;
    env = stack[-2];
    if (v0174 == nil) goto v0097;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0288 = qvalue(elt(env, 2)); /* maxvar */
    v0174 = stack[0];
    v0174 = plus2(v0288, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-2];
    v0289 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0174/(16/CELL)));
    v0288 = (Lisp_Object)1; /* 0 */
    v0174 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v0289 + (CELL-TAG_VECTOR) + ((int32_t)v0288/(16/CELL))) = v0174;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0288 = qvalue(elt(env, 2)); /* maxvar */
    v0174 = stack[0];
    v0174 = plus2(v0288, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-2];
    v0288 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0174/(16/CELL)));
    v0174 = (Lisp_Object)65; /* 4 */
    v0174 = *(Lisp_Object *)((char *)v0288 + (CELL-TAG_VECTOR) + ((int32_t)v0174/(16/CELL)));
    stack[-1] = v0174;
    goto v0277;

v0277:
    v0174 = stack[-1];
    if (v0174 == nil) goto v0041;
    v0174 = stack[-1];
    v0174 = qcar(v0174);
    stack[0] = v0174;
    v0174 = stack[0];
    v0288 = qcar(v0174);
    v0174 = stack[0];
    v0174 = qcdr(v0174);
    v0174 = qcar(v0174);
    fn = elt(env, 4); /* downwght1 */
    v0174 = (*qfn2(fn))(qenv(fn), v0288, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-2];
    v0174 = stack[0];
    v0174 = qcar(v0174);
    v0174 = CC_testred(env, v0174);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-2];
    v0174 = stack[-1];
    v0174 = qcdr(v0174);
    stack[-1] = v0174;
    goto v0277;

v0041:
    v0174 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v0174); }

v0097:
    v0174 = nil;
    { popv(3); return onevalue(v0174); }
/* error exit handlers */
v0240:
    popv(3);
    return nil;
}



/* Code for mkuwedge */

static Lisp_Object CC_mkuwedge(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0215, v0043;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkuwedge");
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
    v0215 = v0000;
/* end of prologue */
    v0043 = v0215;
    v0043 = qcdr(v0043);
    if (v0043 == nil) goto v0057;
    v0043 = elt(env, 1); /* wedge */
    v0215 = cons(v0043, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[0];
    fn = elt(env, 2); /* fkern */
    v0215 = (*qfn1(fn))(qenv(fn), v0215);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    v0215 = qcar(v0215);
    { popv(1); return onevalue(v0215); }

v0057:
    v0215 = qcar(v0215);
    { popv(1); return onevalue(v0215); }
/* error exit handlers */
v0217:
    popv(1);
    return nil;
}



/* Code for has_parents */

static Lisp_Object CC_has_parents(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0067, v0068, v0038;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for has_parents");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0067 = v0000;
/* end of prologue */
    v0067 = qcdr(v0067);
    v0067 = qcar(v0067);
    v0038 = v0067;
    v0067 = v0038;
    v0068 = qcar(v0067);
    v0067 = elt(env, 1); /* !? */
    if (v0068 == v0067) goto v0177;
    v0067 = v0038;
    v0067 = qcdr(v0067);
    v0068 = elt(env, 1); /* !? */
        return Lneq(nil, v0067, v0068);

v0177:
    v0067 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0067);
}



/* Code for quotk */

static Lisp_Object CC_quotk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0058)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0064, v0011, v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0058,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0058);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0058;
    stack[-1] = v0000;
/* end of prologue */
    v0064 = stack[-1];
    v0064 = qcar(v0064);
    v0011 = qcdr(v0064);
    v0064 = stack[0];
    fn = elt(env, 2); /* quotf1 */
    v0064 = (*qfn2(fn))(qenv(fn), v0011, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-3];
    stack[-2] = v0064;
    v0064 = stack[-2];
    if (v0064 == nil) goto v0047;
    v0064 = stack[-1];
    v0064 = qcdr(v0064);
    if (v0064 == nil) goto v0177;
    v0064 = stack[-1];
    v0011 = qcdr(v0064);
    v0064 = stack[0];
    fn = elt(env, 2); /* quotf1 */
    v0064 = (*qfn2(fn))(qenv(fn), v0011, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    env = stack[-3];
    v0011 = v0064;
    v0064 = v0011;
    if (v0064 == nil) goto v0083;
    v0064 = stack[-1];
    v0064 = qcar(v0064);
    v0012 = qcar(v0064);
    v0064 = stack[-2];
    popv(4);
    return acons(v0012, v0064, v0011);

v0083:
    v0064 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0064); }

v0177:
    v0064 = stack[-1];
    v0064 = qcar(v0064);
    v0011 = qcar(v0064);
    v0064 = stack[-2];
    v0064 = cons(v0011, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0243;
    popv(4);
    return ncons(v0064);

v0047:
    v0064 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0064); }
/* error exit handlers */
v0243:
    popv(4);
    return nil;
}



setup_type const u08_setup[] =
{
    {"anform1",                 CC_anform1,     too_many_1,    wrong_no_1},
    {"ckrn1",                   CC_ckrn1,       too_many_1,    wrong_no_1},
    {"rl_simpat",               CC_rl_simpat,   too_many_1,    wrong_no_1},
    {"ibalp_litp",              CC_ibalp_litp,  too_many_1,    wrong_no_1},
    {"evaluate-mod-p",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_evaluateKmodKp},
    {"ident",                   CC_ident,       too_many_1,    wrong_no_1},
    {"diplength",               CC_diplength,   too_many_1,    wrong_no_1},
    {"divide:",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_divideT},
    {"form1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_form1},
    {"compactfmatch2",          CC_compactfmatch2,too_many_1,  wrong_no_1},
    {"multop",                  too_few_2,      CC_multop,     wrong_no_2},
    {"mo=lexcomp",              too_few_2,      CC_moMlexcomp, wrong_no_2},
    {"th_match0",               too_few_2,      CC_th_match0,  wrong_no_2},
    {"ofsf_smwmkatl",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smwmkatl},
    {"qqe_ofsf_prepat",         CC_qqe_ofsf_prepat,too_many_1, wrong_no_1},
    {"rl_gettype",              CC_rl_gettype,  too_many_1,    wrong_no_1},
    {"expression",              CC_expression,  too_many_1,    wrong_no_1},
    {"rd:prep",                 CC_rdTprep,     too_many_1,    wrong_no_1},
    {"c:extadd",                too_few_2,      CC_cTextadd,   wrong_no_2},
    {"off_mod_reval",           CC_off_mod_reval,too_many_1,   wrong_no_1},
    {"chknewnam",               CC_chknewnam,   too_many_1,    wrong_no_1},
    {"red_divtestbe",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_red_divtestbe},
    {"gcddd",                   too_few_2,      CC_gcddd,      wrong_no_2},
    {"arintequiv:",             CC_arintequivT, too_many_1,    wrong_no_1},
    {"mconv",                   CC_mconv,       too_many_1,    wrong_no_1},
    {"canonsq",                 CC_canonsq,     too_many_1,    wrong_no_1},
    {"searchtm",                CC_searchtm,    too_many_1,    wrong_no_1},
    {"ibalp_atomp",             CC_ibalp_atomp, too_many_1,    wrong_no_1},
    {"aex_reducedtag",          CC_aex_reducedtag,too_many_1,  wrong_no_1},
    {"ps:get-term",             too_few_2,      CC_psTgetKterm,wrong_no_2},
    {"evenfree",                CC_evenfree,    too_many_1,    wrong_no_1},
    {"getphystypesf",           CC_getphystypesf,too_many_1,   wrong_no_1},
    {"add2resultbuf",           too_few_2,      CC_add2resultbuf,wrong_no_2},
    {"getel",                   CC_getel,       too_many_1,    wrong_no_1},
    {"pdmult",                  too_few_2,      CC_pdmult,     wrong_no_2},
    {"maprint",                 too_few_2,      CC_maprint,    wrong_no_2},
    {"conv:bf2i",               CC_convTbf2i,   too_many_1,    wrong_no_1},
    {"undefdchk",               CC_undefdchk,   too_many_1,    wrong_no_1},
    {"ofsf_ordatp",             too_few_2,      CC_ofsf_ordatp,wrong_no_2},
    {"polynommultiplybymonom",  too_few_2,      CC_polynommultiplybymonom,wrong_no_2},
    {"processpartitie1",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_processpartitie1},
    {"quotfx",                  too_few_2,      CC_quotfx,     wrong_no_2},
    {"ibalp_simpat",            CC_ibalp_simpat,too_many_1,    wrong_no_1},
    {"aex_deg",                 too_few_2,      CC_aex_deg,    wrong_no_2},
    {"omair",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omair},
    {"ps:expression",           CC_psTexpression,too_many_1,   wrong_no_1},
    {"dfn_prop",                CC_dfn_prop,    too_many_1,    wrong_no_1},
    {"mksgnsq",                 CC_mksgnsq,     too_many_1,    wrong_no_1},
    {"covposp",                 CC_covposp,     too_many_1,    wrong_no_1},
    {"contrsp",                 too_few_2,      CC_contrsp,    wrong_no_2},
    {"tokquote",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_tokquote},
    {"cdarx",                   CC_cdarx,       too_many_1,    wrong_no_1},
    {"totalcompare",            too_few_2,      CC_totalcompare,wrong_no_2},
    {"qsort",                   CC_qsort,       too_many_1,    wrong_no_1},
    {"make-univariate-image-mod-p",too_few_2,   CC_makeKunivariateKimageKmodKp,wrong_no_2},
    {"writepri",                too_few_2,      CC_writepri,   wrong_no_2},
    {"testred",                 CC_testred,     too_many_1,    wrong_no_1},
    {"mkuwedge",                CC_mkuwedge,    too_many_1,    wrong_no_1},
    {"has_parents",             CC_has_parents, too_many_1,    wrong_no_1},
    {"quotk",                   too_few_2,      CC_quotk,      wrong_no_2},
    {NULL, (one_args *)"u08", (two_args *)"3843 9641946 8147554", 0}
};

/* end of generated code */
