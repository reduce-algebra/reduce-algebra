
/* $destdir\u07.c        Machine generated C code */

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


/* Code for noncomp2f */

static Lisp_Object CC_noncomp2f(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomp2f");
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

v0005:
    v0003 = stack[0];
    if (!consp(v0003)) goto v0006;
    v0003 = stack[0];
    v0003 = qcar(v0003);
    v0003 = (consp(v0003) ? nil : lisp_true);
    goto v0007;

v0007:
    if (v0003 == nil) goto v0008;
    v0003 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0003); }

v0008:
    v0003 = stack[0];
    v0003 = qcar(v0003);
    v0003 = qcar(v0003);
    v0003 = qcar(v0003);
    v0004 = v0003;
    if (!consp(v0003)) goto v0009;
    v0003 = v0004;
    v0003 = qcar(v0003);
    if (!symbolp(v0003)) v0003 = nil;
    else { v0003 = qfastgets(v0003);
           if (v0003 != nil) { v0003 = elt(v0003, 0); /* noncom */
#ifdef RECORD_GET
             if (v0003 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0003 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0003 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0003 == SPID_NOPROP) v0003 = nil; else v0003 = lisp_true; }}
#endif
    if (v0003 == nil) goto v0010;
    v0003 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0003); }

v0010:
    v0003 = stack[0];
    v0003 = qcar(v0003);
    v0003 = qcdr(v0003);
    v0003 = CC_noncomp2f(env, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-1];
    if (v0003 == nil) goto v0012;
    v0003 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0003); }

v0012:
    v0003 = stack[0];
    v0003 = qcdr(v0003);
    stack[0] = v0003;
    goto v0005;

v0009:
    v0003 = v0004;
    if (!symbolp(v0003)) v0003 = nil;
    else { v0003 = qfastgets(v0003);
           if (v0003 != nil) { v0003 = elt(v0003, 0); /* noncom */
#ifdef RECORD_GET
             if (v0003 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0003 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0003 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0003 == SPID_NOPROP) v0003 = nil; else v0003 = lisp_true; }}
#endif
    if (v0003 == nil) goto v0012;
    v0003 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0003); }

v0006:
    v0003 = qvalue(elt(env, 1)); /* t */
    goto v0007;
/* error exit handlers */
v0011:
    popv(2);
    return nil;
}



/* Code for rread */

static Lisp_Object MS_CDECL CC_rread(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rread");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rread");
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
    v0013 = elt(env, 1); /* " '" */
    fn = elt(env, 2); /* prin2x */
    v0013 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* rread1 */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v0005:
    popv(1);
    return nil;
}



/* Code for mv!-pow!-mv!-term!-!+ */

static Lisp_Object CC_mvKpowKmvKtermKL(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0019;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-mv-term-+");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0014;
    v0018 = v0000;
/* end of prologue */
    v0019 = v0018;
    v0018 = stack[0];
    v0018 = qcar(v0018);
    fn = elt(env, 1); /* mv!-pow!-!+ */
    v0019 = (*qfn2(fn))(qenv(fn), v0019, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    v0018 = stack[0];
    v0018 = qcdr(v0018);
    popv(1);
    return cons(v0019, v0018);
/* error exit handlers */
v0020:
    popv(1);
    return nil;
}



/* Code for rnquotient!: */

static Lisp_Object CC_rnquotientT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnquotient:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0014;
    stack[-1] = v0000;
/* end of prologue */
    v0023 = stack[-1];
    v0023 = qcdr(v0023);
    v0024 = qcar(v0023);
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    stack[-2] = times2(v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-3];
    v0023 = stack[-1];
    v0023 = qcdr(v0023);
    v0024 = qcdr(v0023);
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    v0023 = qcar(v0023);
    v0023 = times2(v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-3];
    {
        Lisp_Object v0026 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v0026, v0023);
    }
/* error exit handlers */
v0025:
    popv(4);
    return nil;
}



/* Code for oprin */

static Lisp_Object CC_oprin(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0028, v0029;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for oprin");
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
    if (!symbolp(v0028)) v0028 = nil;
    else { v0028 = qfastgets(v0028);
           if (v0028 != nil) { v0028 = elt(v0028, 37); /* prtch */
#ifdef RECORD_GET
             if (v0028 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v0028 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v0028 == SPID_NOPROP) v0028 = nil; }}
#endif
    stack[-1] = v0028;
    v0028 = stack[-1];
    if (v0028 == nil) goto v0012;
    v0028 = qvalue(elt(env, 2)); /* !*fort */
    if (v0028 == nil) goto v0017;
    v0028 = stack[-1];
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0028);
    }

v0017:
    v0028 = qvalue(elt(env, 3)); /* !*list */
    if (v0028 == nil) goto v0009;
    v0028 = qvalue(elt(env, 4)); /* obrkp!* */
    if (v0028 == nil) goto v0009;
    v0029 = stack[0];
    v0028 = elt(env, 5); /* (plus minus) */
    v0028 = Lmemq(nil, v0029, v0028);
    if (v0028 == nil) goto v0009;
    v0028 = qvalue(elt(env, 6)); /* testing!-width!* */
    if (v0028 == nil) goto v0030;
    v0028 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 8)) = v0028; /* overflowed!* */
    { popv(3); return onevalue(v0028); }

v0030:
    v0028 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 10); /* terpri!* */
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-2];
    v0028 = stack[-1];
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0028);
    }

v0009:
    v0028 = stack[0];
    if (!symbolp(v0028)) v0028 = nil;
    else { v0028 = qfastgets(v0028);
           if (v0028 != nil) { v0028 = elt(v0028, 61); /* spaced */
#ifdef RECORD_GET
             if (v0028 == SPID_NOPROP)
                record_get(elt(fastget_names, 61), 0),
                v0028 = nil;
             else record_get(elt(fastget_names, 61), 1),
                v0028 = lisp_true; }
           else record_get(elt(fastget_names, 61), 0); }
#else
             if (v0028 == SPID_NOPROP) v0028 = nil; else v0028 = lisp_true; }}
#endif
    if (v0028 == nil) goto v0032;
    v0028 = elt(env, 1); /* " " */
    fn = elt(env, 9); /* prin2!* */
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-2];
    v0028 = stack[-1];
    fn = elt(env, 9); /* prin2!* */
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-2];
    v0028 = elt(env, 1); /* " " */
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0028);
    }

v0032:
    v0028 = stack[-1];
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0028);
    }

v0012:
    v0028 = elt(env, 1); /* " " */
    fn = elt(env, 9); /* prin2!* */
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-2];
    v0028 = stack[0];
    fn = elt(env, 9); /* prin2!* */
    v0028 = (*qfn1(fn))(qenv(fn), v0028);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-2];
    v0028 = elt(env, 1); /* " " */
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0028);
    }
/* error exit handlers */
v0031:
    popv(3);
    return nil;
}



/* Code for gintequiv!: */

static Lisp_Object CC_gintequivT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0009, v0020;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gintequiv:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0020 = v0000;
/* end of prologue */
    v0019 = v0020;
    v0019 = qcdr(v0019);
    v0009 = qcdr(v0019);
    v0019 = (Lisp_Object)1; /* 0 */
    if (v0009 == v0019) goto v0013;
    v0019 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0019);

v0013:
    v0019 = v0020;
    v0019 = qcdr(v0019);
    v0019 = qcar(v0019);
    return onevalue(v0019);
}



/* Code for prepsq!*2 */

static Lisp_Object CC_prepsqH2(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0016, v0035;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsq*2");
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
    v0034 = v0000;
/* end of prologue */
    v0035 = v0034;
    v0016 = (Lisp_Object)17; /* 1 */
    v0034 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepsq!*1 */
    v0034 = (*qfnn(fn))(qenv(fn), 3, v0035, v0016, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* replus */
        return (*qfn1(fn))(qenv(fn), v0034);
    }
/* error exit handlers */
v0017:
    popv(1);
    return nil;
}



/* Code for ofsf_smwcpknowl */

static Lisp_Object CC_ofsf_smwcpknowl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smwcpknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0034 = v0000;
/* end of prologue */
    v0033 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v0033 == nil) goto v0008;
    v0033 = v0034;
    {
        fn = elt(env, 2); /* cl_susicpknowl */
        return (*qfn1(fn))(qenv(fn), v0033);
    }

v0008:
    v0033 = v0034;
    {
        fn = elt(env, 3); /* ofsf_smcpknowl */
        return (*qfn1(fn))(qenv(fn), v0033);
    }
}



/* Code for ibalp_mk2 */

static Lisp_Object MS_CDECL CC_ibalp_mk2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0014,
                         Lisp_Object v0001, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0035, v0017;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ibalp_mk2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0016 = v0001;
    v0035 = v0014;
    v0017 = v0000;
/* end of prologue */
    return list3(v0017, v0035, v0016);
}



/* Code for ctx_new */

static Lisp_Object MS_CDECL CC_ctx_new(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ctx_new");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ctx_new");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0036 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* ctx_fromial */
        return (*qfn1(fn))(qenv(fn), v0036);
    }
}



/* Code for mintype */

static Lisp_Object CC_mintype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0033;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mintype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0006 = v0000;
/* end of prologue */
    v0033 = v0006;
    if (!consp(v0033)) return onevalue(v0006);
    v0006 = qcar(v0006);
    return onevalue(v0006);
}



/* Code for comm_kernels */

static Lisp_Object CC_comm_kernels(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comm_kernels");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0002 = v0000;
/* end of prologue */
    v0007 = v0002;
    v0002 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* comm_kernels1 */
        return (*qfn2(fn))(qenv(fn), v0007, v0002);
    }
}



/* Code for bcone!? */

static Lisp_Object CC_bconeW(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0041, v0030;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcone?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0030 = v0000;
/* end of prologue */
    v0040 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v0040 == nil) goto v0019;
    v0041 = v0030;
    v0040 = (Lisp_Object)17; /* 1 */
        return Leqn(nil, v0041, v0040);

v0019:
    v0040 = v0030;
    v0041 = qcdr(v0040);
    v0040 = (Lisp_Object)17; /* 1 */
    if (v0041 == v0040) goto v0021;
    v0040 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0040);

v0021:
    v0040 = v0030;
    v0041 = qcar(v0040);
    v0040 = (Lisp_Object)17; /* 1 */
    v0040 = (v0041 == v0040 ? lisp_true : nil);
    return onevalue(v0040);
}



/* Code for layout!-formula */

static Lisp_Object MS_CDECL CC_layoutKformula(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0014,
                         Lisp_Object v0001, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0056;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "layout-formula");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for layout-formula");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0001,v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0014,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0001;
    stack[-7] = v0014;
    stack[-8] = v0000;
/* end of prologue */
    stack[-9] = qvalue(elt(env, 1)); /* ycoord!* */
    qvalue(elt(env, 1)) = nil; /* ycoord!* */
    stack[-5] = qvalue(elt(env, 2)); /* ymin!* */
    qvalue(elt(env, 2)) = nil; /* ymin!* */
    stack[-4] = qvalue(elt(env, 3)); /* ymax!* */
    qvalue(elt(env, 3)) = nil; /* ymax!* */
    stack[-3] = qvalue(elt(env, 4)); /* posn!* */
    qvalue(elt(env, 4)) = nil; /* posn!* */
    stack[-2] = qvalue(elt(env, 5)); /* pline!* */
    qvalue(elt(env, 5)) = nil; /* pline!* */
    stack[-1] = qvalue(elt(env, 6)); /* testing!-width!* */
    qvalue(elt(env, 6)) = nil; /* testing!-width!* */
    stack[0] = qvalue(elt(env, 7)); /* overflowed!* */
    qvalue(elt(env, 7)) = nil; /* overflowed!* */
    v0055 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 7)) = v0055; /* overflowed!* */
    qvalue(elt(env, 5)) = v0055; /* pline!* */
    v0055 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v0055; /* ymax!* */
    qvalue(elt(env, 2)) = v0055; /* ymin!* */
    qvalue(elt(env, 1)) = v0055; /* ycoord!* */
    v0055 = qvalue(elt(env, 9)); /* orig!* */
    qvalue(elt(env, 4)) = v0055; /* posn!* */
    v0055 = qvalue(elt(env, 10)); /* t */
    qvalue(elt(env, 6)) = v0055; /* testing!-width!* */
    v0055 = stack[-6];
    if (v0055 == nil) goto v0057;
    v0056 = stack[-6];
    v0055 = elt(env, 11); /* inbrackets */
    if (v0056 == v0055) goto v0058;
    v0055 = stack[-6];
    fn = elt(env, 14); /* oprin */
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-10];
    goto v0057;

v0057:
    v0056 = stack[-8];
    v0055 = stack[-7];
    fn = elt(env, 15); /* maprint */
    v0055 = (*qfn2(fn))(qenv(fn), v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-10];
    v0056 = stack[-6];
    v0055 = elt(env, 11); /* inbrackets */
    if (!(v0056 == v0055)) goto v0060;
    v0055 = elt(env, 13); /* ")" */
    fn = elt(env, 16); /* prin2!* */
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-10];
    goto v0060;

v0060:
    v0055 = qvalue(elt(env, 7)); /* overflowed!* */
    if (v0055 == nil) goto v0061;
    v0055 = qvalue(elt(env, 8)); /* nil */
    goto v0006;

v0006:
    qvalue(elt(env, 7)) = stack[0]; /* overflowed!* */
    qvalue(elt(env, 6)) = stack[-1]; /* testing!-width!* */
    qvalue(elt(env, 5)) = stack[-2]; /* pline!* */
    qvalue(elt(env, 4)) = stack[-3]; /* posn!* */
    qvalue(elt(env, 3)) = stack[-4]; /* ymax!* */
    qvalue(elt(env, 2)) = stack[-5]; /* ymin!* */
    qvalue(elt(env, 1)) = stack[-9]; /* ycoord!* */
    { popv(11); return onevalue(v0055); }

v0061:
    stack[-7] = qvalue(elt(env, 5)); /* pline!* */
    v0056 = qvalue(elt(env, 4)); /* posn!* */
    v0055 = qvalue(elt(env, 9)); /* orig!* */
    stack[-6] = difference2(v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-10];
    v0056 = qvalue(elt(env, 2)); /* ymin!* */
    v0055 = qvalue(elt(env, 3)); /* ymax!* */
    v0055 = cons(v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-10];
    v0055 = acons(stack[-7], stack[-6], v0055);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-10];
    goto v0006;

v0058:
    v0055 = elt(env, 12); /* "(" */
    fn = elt(env, 16); /* prin2!* */
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-10];
    goto v0057;
/* error exit handlers */
v0059:
    env = stack[-10];
    qvalue(elt(env, 7)) = stack[0]; /* overflowed!* */
    qvalue(elt(env, 6)) = stack[-1]; /* testing!-width!* */
    qvalue(elt(env, 5)) = stack[-2]; /* pline!* */
    qvalue(elt(env, 4)) = stack[-3]; /* posn!* */
    qvalue(elt(env, 3)) = stack[-4]; /* ymax!* */
    qvalue(elt(env, 2)) = stack[-5]; /* ymin!* */
    qvalue(elt(env, 1)) = stack[-9]; /* ycoord!* */
    popv(11);
    return nil;
}



/* Code for convertmode1 */

static Lisp_Object MS_CDECL CC_convertmode1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0014,
                         Lisp_Object v0001, Lisp_Object v0036, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0080, v0081, v0082, v0083, v0084, v0085;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "convertmode1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for convertmode1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0036,v0001,v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0014,v0001,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0081 = v0036;
    v0082 = v0001;
    v0083 = v0014;
    v0084 = v0000;
/* end of prologue */
    v0080 = v0081;
    v0079 = elt(env, 1); /* real */
    if (!(v0080 == v0079)) goto v0058;
    v0079 = elt(env, 2); /* algebraic */
    v0081 = v0079;
    goto v0058;

v0058:
    v0080 = v0082;
    v0079 = elt(env, 1); /* real */
    if (!(v0080 == v0079)) goto v0010;
    v0079 = elt(env, 2); /* algebraic */
    v0082 = v0079;
    goto v0010;

v0010:
    v0080 = v0082;
    v0079 = v0081;
    if (v0080 == v0079) { popv(1); return onevalue(v0084); }
    v0079 = v0084;
    if (!(symbolp(v0079))) goto v0086;
    v0080 = v0084;
    v0079 = v0083;
    v0079 = Latsoc(nil, v0080, v0079);
    v0085 = v0079;
    if (v0079 == nil) goto v0086;
    v0079 = v0085;
    v0080 = qcdr(v0079);
    v0079 = elt(env, 3); /* (integer scalar real) */
    v0079 = Lmemq(nil, v0080, v0079);
    if (v0079 == nil) goto v0087;
    v0079 = qvalue(elt(env, 4)); /* nil */
    goto v0088;

v0088:
    if (v0079 == nil) goto v0086;
    v0079 = v0084;
    v0080 = v0083;
    v0081 = v0082;
    v0082 = v0085;
    v0082 = qcdr(v0082);
    {
        popv(1);
        fn = elt(env, 5); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v0079, v0080, v0081, v0082);
    }

v0086:
    v0080 = v0081;
    v0079 = v0082;
    v0079 = get(v0080, v0079);
    env = stack[0];
    v0085 = v0079;
    if (v0079 == nil) goto v0089;
    v0079 = v0085;
    v0080 = v0084;
    v0081 = v0083;
        popv(1);
        return Lapply2(nil, 3, v0079, v0080, v0081);

v0089:
    v0079 = v0081;
    v0080 = v0082;
    fn = elt(env, 6); /* typerr */
    v0079 = (*qfn2(fn))(qenv(fn), v0079, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    v0079 = nil;
    { popv(1); return onevalue(v0079); }

v0087:
    v0079 = v0085;
    v0080 = qcdr(v0079);
    v0079 = v0081;
    v0079 = (v0080 == v0079 ? lisp_true : nil);
    v0079 = (v0079 == nil ? lisp_true : nil);
    goto v0088;
/* error exit handlers */
v0090:
    popv(1);
    return nil;
}



/* Code for simpdiff */

static Lisp_Object CC_simpdiff(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpdiff");
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
    v0016 = stack[0];
    fn = elt(env, 1); /* ckpreci!# */
    v0016 = (*qfn1(fn))(qenv(fn), v0016);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-2];
    v0016 = stack[0];
    fn = elt(env, 2); /* simpcar */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0016);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-2];
    v0016 = stack[0];
    v0016 = qcdr(v0016);
    fn = elt(env, 3); /* simpminus */
    v0016 = (*qfn1(fn))(qenv(fn), v0016);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-2];
    {
        Lisp_Object v0015 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0015, v0016);
    }
/* error exit handlers */
v0078:
    popv(3);
    return nil;
}



/* Code for bas_make1 */

static Lisp_Object MS_CDECL CC_bas_make1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0014,
                         Lisp_Object v0001, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0039;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "bas_make1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bas_make1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0001,v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0014,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0001;
    stack[-3] = v0014;
    v0038 = v0000;
/* end of prologue */
    stack[-4] = v0038;
    stack[-1] = stack[-3];
    v0038 = stack[-3];
    stack[0] = Llength(nil, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-5];
    v0038 = stack[-3];
    fn = elt(env, 1); /* dp_ecart */
    v0039 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-5];
    v0038 = stack[-2];
    v0038 = list2(v0039, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    {
        Lisp_Object v0027 = stack[-4];
        Lisp_Object v0010 = stack[-1];
        Lisp_Object v0092 = stack[0];
        popv(6);
        return list3star(v0027, v0010, v0092, v0038);
    }
/* error exit handlers */
v0024:
    popv(6);
    return nil;
}



/* Code for sc_kern */

static Lisp_Object CC_sc_kern(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sc_kern");
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
    v0034 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* g_sc_ve */
    v0034 = sub1(v0034);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    v0034 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0034/(16/CELL)));
    v0034 = qcdr(v0034);
    v0034 = qcdr(v0034);
    v0034 = qcar(v0034);
    { popv(1); return onevalue(v0034); }
/* error exit handlers */
v0035:
    popv(1);
    return nil;
}



/* Code for general!-modular!-quotient */

static Lisp_Object CC_generalKmodularKquotient(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-quotient");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0006 = v0014;
    v0033 = v0000;
/* end of prologue */
    stack[0] = v0033;
    fn = elt(env, 1); /* general!-modular!-reciprocal */
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    {
        Lisp_Object v0035 = stack[0];
        popv(2);
        fn = elt(env, 2); /* general!-modular!-times */
        return (*qfn2(fn))(qenv(fn), v0035, v0006);
    }
/* error exit handlers */
v0016:
    popv(2);
    return nil;
}



/* Code for reduce!-mod!-p */

static Lisp_Object CC_reduceKmodKp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-mod-p");
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
    v0093 = stack[-1];
    if (v0093 == nil) goto v0013;
    v0093 = stack[-1];
    if (!consp(v0093)) goto v0006;
    v0093 = stack[-1];
    v0093 = qcar(v0093);
    v0093 = (consp(v0093) ? nil : lisp_true);
    goto v0007;

v0007:
    if (v0093 == nil) goto v0038;
    v0093 = stack[-1];
    v0093 = Lmodular_number(nil, v0093);
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 3); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v0093);
    }

v0038:
    v0093 = stack[-1];
    v0093 = qcar(v0093);
    stack[-2] = qcar(v0093);
    v0093 = stack[-1];
    v0093 = qcar(v0093);
    v0093 = qcdr(v0093);
    stack[0] = CC_reduceKmodKp(env, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    v0093 = stack[-1];
    v0093 = qcdr(v0093);
    v0093 = CC_reduceKmodKp(env, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    {
        Lisp_Object v0094 = stack[-2];
        Lisp_Object v0003 = stack[0];
        popv(4);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0094, v0003, v0093);
    }

v0006:
    v0093 = qvalue(elt(env, 2)); /* t */
    goto v0007;

v0013:
    v0093 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0093); }
/* error exit handlers */
v0060:
    popv(4);
    return nil;
}



/* Code for outdefr */

static Lisp_Object CC_outdefr(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0058, v0095, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for outdefr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0020 = v0014;
    v0058 = v0000;
/* end of prologue */
    v0095 = v0058;
    v0091 = qcar(v0095);
    v0095 = v0058;
    v0095 = qcdr(v0095);
    v0095 = qcar(v0095);
    v0058 = qcdr(v0058);
    v0058 = qcdr(v0058);
    v0058 = qcar(v0058);
    {
        fn = elt(env, 1); /* outref */
        return (*qfnn(fn))(qenv(fn), 4, v0091, v0095, v0058, v0020);
    }
}



/* Code for polynomclone */

static Lisp_Object CC_polynomclone(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0022;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomclone");
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
    v0054 = v0000;
/* end of prologue */
    stack[-1] = nil;
    stack[0] = v0054;
    goto v0008;

v0008:
    v0054 = stack[0];
    if (v0054 == nil) goto v0037;
    v0054 = stack[0];
    v0054 = qcar(v0054);
    fn = elt(env, 2); /* monomclone */
    v0022 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    v0054 = stack[-1];
    v0054 = cons(v0022, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    stack[-1] = v0054;
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    stack[0] = v0054;
    goto v0008;

v0037:
    v0054 = stack[-1];
        popv(3);
        return Lreverse(nil, v0054);
/* error exit handlers */
v0027:
    popv(3);
    return nil;
}



/* Code for totallessp */

static Lisp_Object CC_totallessp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0078, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for totallessp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0078 = v0014;
    v0015 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* totalcompare */
    v0078 = (*qfn2(fn))(qenv(fn), v0015, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[0];
    v0015 = elt(env, 1); /* less */
    v0078 = (v0078 == v0015 ? lisp_true : nil);
    { popv(1); return onevalue(v0078); }
/* error exit handlers */
v0018:
    popv(1);
    return nil;
}



/* Code for mcharg2 */

static Lisp_Object MS_CDECL CC_mcharg2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0014,
                         Lisp_Object v0001, Lisp_Object v0036, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084, v0085, v0090;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "mcharg2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mcharg2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0036,v0001,v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0014,v0001,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-6] = v0036;
    stack[-7] = v0001;
    stack[-8] = v0014;
    stack[-9] = v0000;
/* end of prologue */
    v0084 = stack[-9];
    if (v0084 == nil) { Lisp_Object res = stack[-7]; popv(12); return onevalue(res); }
    v0084 = stack[-9];
    v0085 = qcar(v0084);
    v0084 = stack[-8];
    v0084 = qcar(v0084);
    fn = elt(env, 2); /* mchk */
    v0084 = (*qfn2(fn))(qenv(fn), v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-11];
    v0085 = v0084;
    v0084 = stack[-9];
    v0084 = qcdr(v0084);
    stack[-9] = v0084;
    v0084 = stack[-8];
    v0084 = qcdr(v0084);
    stack[-8] = v0084;
    v0084 = v0085;
    stack[-10] = v0084;
    goto v0023;

v0023:
    v0084 = stack[-10];
    if (v0084 == nil) goto v0025;
    v0084 = stack[-10];
    v0084 = qcar(v0084);
    stack[-2] = v0084;
    stack[-1] = stack[-9];
    v0090 = stack[-2];
    v0085 = stack[-8];
    v0084 = stack[-6];
    fn = elt(env, 3); /* updtemplate */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0090, v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-11];
    v0085 = stack[-7];
    v0084 = stack[-2];
    fn = elt(env, 4); /* msappend */
    v0085 = (*qfn2(fn))(qenv(fn), v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-11];
    v0084 = stack[-6];
    v0084 = CC_mcharg2(env, 4, stack[-1], stack[0], v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-11];
    stack[-5] = v0084;
    v0084 = stack[-5];
    fn = elt(env, 5); /* lastpair */
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-11];
    stack[-4] = v0084;
    v0084 = stack[-10];
    v0084 = qcdr(v0084);
    stack[-10] = v0084;
    v0084 = stack[-4];
    if (!consp(v0084)) goto v0023;
    else goto v0024;

v0024:
    v0084 = stack[-10];
    if (v0084 == nil) { Lisp_Object res = stack[-5]; popv(12); return onevalue(res); }
    stack[-3] = stack[-4];
    v0084 = stack[-10];
    v0084 = qcar(v0084);
    stack[-2] = v0084;
    stack[-1] = stack[-9];
    v0090 = stack[-2];
    v0085 = stack[-8];
    v0084 = stack[-6];
    fn = elt(env, 3); /* updtemplate */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0090, v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-11];
    v0085 = stack[-7];
    v0084 = stack[-2];
    fn = elt(env, 4); /* msappend */
    v0085 = (*qfn2(fn))(qenv(fn), v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-11];
    v0084 = stack[-6];
    v0084 = CC_mcharg2(env, 4, stack[-1], stack[0], v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-11];
    v0084 = Lrplacd(nil, stack[-3], v0084);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-11];
    v0084 = stack[-4];
    fn = elt(env, 5); /* lastpair */
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-11];
    stack[-4] = v0084;
    v0084 = stack[-10];
    v0084 = qcdr(v0084);
    stack[-10] = v0084;
    goto v0024;

v0025:
    v0084 = qvalue(elt(env, 1)); /* nil */
    { popv(12); return onevalue(v0084); }
/* error exit handlers */
v0108:
    popv(12);
    return nil;
}



/* Code for preptayexp */

static Lisp_Object CC_preptayexp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preptayexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0033 = v0000;
/* end of prologue */
    v0006 = v0033;
    if (!consp(v0006)) return onevalue(v0033);
    v0006 = v0033;
    {
        fn = elt(env, 1); /* rnprep!: */
        return (*qfn1(fn))(qenv(fn), v0006);
    }
}



/* Code for symbol */

static Lisp_Object CC_symbol(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0007;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbol");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0002 = v0000;
/* end of prologue */
    v0007 = elt(env, 1); /* symbol!-character */
    return get(v0002, v0007);
}



/* Code for cl_susiminlevel */

static Lisp_Object CC_cl_susiminlevel(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0027, v0010, v0092, v0025;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susiminlevel");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0092 = v0014;
    v0025 = v0000;
/* end of prologue */
    v0010 = v0025;
    v0027 = elt(env, 1); /* ignore */
    if (v0010 == v0027) return onevalue(v0092);
    v0010 = v0092;
    v0027 = elt(env, 1); /* ignore */
    if (v0010 == v0027) return onevalue(v0025);
    v0027 = v0025;
    v0010 = v0092;
    {
        fn = elt(env, 2); /* min */
        return (*qfn2(fn))(qenv(fn), v0027, v0010);
    }
}



/* Code for ibalp_varlt1 */

static Lisp_Object CC_ibalp_varlt1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0109, v0087, v0104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_varlt1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0014;
    v0104 = v0000;
/* end of prologue */
    v0087 = v0104;
    v0109 = (Lisp_Object)1; /* 0 */
    if (v0087 == v0109) goto v0007;
    v0087 = v0104;
    v0109 = (Lisp_Object)17; /* 1 */
    v0109 = (v0087 == v0109 ? lisp_true : nil);
    goto v0002;

v0002:
    if (v0109 == nil) goto v0042;
    v0109 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0109); }

v0042:
    v0109 = v0104;
    if (symbolp(v0109)) goto v0025;
    v0109 = v0104;
    fn = elt(env, 3); /* ibalp_argn */
    v0109 = (*qfn1(fn))(qenv(fn), v0109);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-2];
    stack[-1] = v0109;
    goto v0060;

v0060:
    v0109 = stack[-1];
    if (v0109 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0109 = stack[-1];
    v0109 = qcar(v0109);
    v0087 = v0109;
    v0109 = stack[0];
    v0109 = CC_ibalp_varlt1(env, v0087, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-2];
    stack[0] = v0109;
    v0109 = stack[-1];
    v0109 = qcdr(v0109);
    stack[-1] = v0109;
    goto v0060;

v0025:
    v0087 = v0104;
    v0109 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* lto_insertq */
        return (*qfn2(fn))(qenv(fn), v0087, v0109);
    }

v0007:
    v0109 = qvalue(elt(env, 1)); /* t */
    goto v0002;
/* error exit handlers */
v0045:
    popv(3);
    return nil;
}



/* Code for multiom */

static Lisp_Object CC_multiom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039, v0021;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multiom");
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
    v0039 = stack[0];
    v0021 = Llength(nil, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-1];
    v0039 = (Lisp_Object)17; /* 1 */
    if (v0021 == v0039) goto v0042;
    v0039 = stack[0];
    v0039 = qcar(v0039);
    fn = elt(env, 2); /* objectom */
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-1];
    v0039 = stack[0];
    v0039 = qcdr(v0039);
    v0039 = CC_multiom(env, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    goto v0005;

v0005:
    v0039 = nil;
    { popv(2); return onevalue(v0039); }

v0042:
    v0039 = stack[0];
    v0039 = qcar(v0039);
    fn = elt(env, 2); /* objectom */
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    goto v0005;
/* error exit handlers */
v0054:
    popv(2);
    return nil;
}



/* Code for minusp!: */

static Lisp_Object CC_minuspT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025, v0026, v0057;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minusp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0057 = v0000;
/* end of prologue */
    v0026 = v0057;
    v0025 = elt(env, 1); /* !:rd!: */
    if (!consp(v0026)) goto v0009;
    v0026 = qcar(v0026);
    if (!(v0026 == v0025)) goto v0009;
    v0025 = v0057;
    v0025 = qcdr(v0025);
    v0025 = (consp(v0025) ? nil : lisp_true);
    v0025 = (v0025 == nil ? lisp_true : nil);
    goto v0012;

v0012:
    if (v0025 == nil) goto v0027;
    v0025 = v0057;
    v0025 = qcdr(v0025);
    v0026 = qcar(v0025);
    v0025 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v0026, v0025);

v0027:
    v0025 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0025);

v0009:
    v0025 = qvalue(elt(env, 2)); /* nil */
    goto v0012;
}



/* Code for letmtr3 */

static Lisp_Object MS_CDECL CC_letmtr3(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0014,
                         Lisp_Object v0001, Lisp_Object v0036, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0159, v0160, v0161, v0162;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "letmtr3");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for letmtr3");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0036,v0001,v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0014,v0001,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0036;
    stack[-3] = v0001;
    stack[-4] = v0014;
    stack[-5] = v0000;
/* end of prologue */
    stack[-6] = nil;
    v0159 = stack[-5];
    v0159 = qcdr(v0159);
    v0159 = qcdr(v0159);
    if (v0159 == nil) goto v0039;
    v0160 = stack[-3];
    v0159 = elt(env, 1); /* sparsemat */
    if (!consp(v0160)) goto v0066;
    v0160 = qcar(v0160);
    if (!(v0160 == v0159)) goto v0066;
    v0159 = stack[-5];
    v0159 = qcdr(v0159);
    fn = elt(env, 9); /* revlis */
    v0159 = (*qfn1(fn))(qenv(fn), v0159);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-7];
    stack[-6] = v0159;
    fn = elt(env, 10); /* numlis */
    v0159 = (*qfn1(fn))(qenv(fn), v0159);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-7];
    if (v0159 == nil) goto v0164;
    v0159 = stack[-6];
    v0160 = Llength(nil, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-7];
    v0159 = (Lisp_Object)33; /* 2 */
    v0159 = Lneq(nil, v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-7];
    goto v0165;

v0165:
    if (v0159 == nil) goto v0166;
    v0160 = stack[-5];
    v0159 = elt(env, 6); /* hold */
    {
        popv(8);
        fn = elt(env, 11); /* errpri2 */
        return (*qfn2(fn))(qenv(fn), v0160, v0159);
    }

v0166:
    v0159 = stack[-3];
    v0159 = qcdr(v0159);
    v0160 = qcar(v0159);
    v0159 = stack[-6];
    v0159 = qcar(v0159);
    v0159 = *(Lisp_Object *)((char *)v0160 + (CELL-TAG_VECTOR) + ((int32_t)v0159/(16/CELL)));
    v0162 = v0159;
    v0159 = v0162;
    if (v0159 == nil) goto v0167;
    v0159 = stack[-6];
    v0159 = qcdr(v0159);
    v0160 = qcar(v0159);
    v0159 = v0162;
    v0159 = Latsoc(nil, v0160, v0159);
    v0161 = v0159;
    v0159 = v0161;
    if (v0159 == nil) goto v0168;
    v0160 = stack[-4];
    v0159 = (Lisp_Object)1; /* 0 */
    if (v0160 == v0159) goto v0169;
    v0159 = qvalue(elt(env, 7)); /* nil */
    goto v0170;

v0170:
    if (v0159 == nil) goto v0171;
    v0159 = v0162;
    v0159 = qcdr(v0159);
    v0159 = qcdr(v0159);
    if (v0159 == nil) goto v0172;
    stack[0] = v0162;
    v0159 = v0161;
    v0160 = v0162;
    v0159 = Ldelete(nil, v0159, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-7];
    v0159 = qcdr(v0159);
    v0159 = Lrplacd(nil, stack[0], v0159);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    goto v0017;

v0017:
    v0159 = nil;
    { popv(8); return onevalue(v0159); }

v0172:
    v0159 = stack[-3];
    v0159 = qcdr(v0159);
    v0160 = qcar(v0159);
    v0159 = stack[-6];
    v0159 = qcar(v0159);
    v0161 = qvalue(elt(env, 7)); /* nil */
    *(Lisp_Object *)((char *)v0160 + (CELL-TAG_VECTOR) + ((int32_t)v0159/(16/CELL))) = v0161;
    goto v0017;

v0171:
    v0160 = v0161;
    v0159 = stack[-4];
    v0159 = Lrplacd(nil, v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    goto v0017;

v0169:
    v0160 = stack[-2];
    v0159 = elt(env, 8); /* cx */
    v0159 = (v0160 == v0159 ? lisp_true : nil);
    v0159 = (v0159 == nil ? lisp_true : nil);
    goto v0170;

v0168:
    v0160 = stack[-4];
    v0159 = (Lisp_Object)1; /* 0 */
    if (v0160 == v0159) goto v0173;
    v0159 = qvalue(elt(env, 7)); /* nil */
    goto v0174;

v0174:
    if (!(v0159 == nil)) goto v0017;
    v0159 = stack[-6];
    v0159 = qcdr(v0159);
    v0160 = qcar(v0159);
    v0161 = v0162;
    v0159 = stack[-4];
    fn = elt(env, 12); /* sortcolelem */
    v0159 = (*qfnn(fn))(qenv(fn), 3, v0160, v0161, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    goto v0017;

v0173:
    v0160 = stack[-2];
    v0159 = elt(env, 8); /* cx */
    v0159 = (v0160 == v0159 ? lisp_true : nil);
    v0159 = (v0159 == nil ? lisp_true : nil);
    goto v0174;

v0167:
    v0160 = stack[-4];
    v0159 = (Lisp_Object)1; /* 0 */
    if (v0160 == v0159) goto v0175;
    v0159 = qvalue(elt(env, 7)); /* nil */
    goto v0176;

v0176:
    if (!(v0159 == nil)) goto v0017;
    v0159 = stack[-3];
    v0159 = qcdr(v0159);
    stack[-2] = qcar(v0159);
    v0159 = stack[-6];
    stack[-1] = qcar(v0159);
    v0159 = qvalue(elt(env, 7)); /* nil */
    stack[0] = ncons(v0159);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-7];
    v0159 = stack[-6];
    v0159 = qcdr(v0159);
    v0160 = qcar(v0159);
    v0159 = stack[-4];
    v0159 = cons(v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-7];
    v0159 = list2(stack[0], v0159);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v0159;
    goto v0017;

v0175:
    v0160 = stack[-2];
    v0159 = elt(env, 8); /* cx */
    v0159 = (v0160 == v0159 ? lisp_true : nil);
    v0159 = (v0159 == nil ? lisp_true : nil);
    goto v0176;

v0164:
    v0159 = qvalue(elt(env, 5)); /* t */
    goto v0165;

v0066:
    stack[-1] = elt(env, 2); /* matrix */
    stack[0] = (Lisp_Object)161; /* 10 */
    v0161 = elt(env, 3); /* "Matrix" */
    v0159 = stack[-5];
    v0160 = qcar(v0159);
    v0159 = elt(env, 4); /* "not set" */
    v0159 = list3(v0161, v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-7];
    fn = elt(env, 13); /* rerror */
    v0159 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0159);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-7];
    goto v0166;

v0039:
    v0160 = stack[-3];
    v0159 = elt(env, 1); /* sparsemat */
    if (!consp(v0160)) goto v0010;
    v0160 = qcar(v0160);
    if (!(v0160 == v0159)) goto v0010;
    v0159 = stack[-5];
    v0159 = qcdr(v0159);
    fn = elt(env, 9); /* revlis */
    v0159 = (*qfn1(fn))(qenv(fn), v0159);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-7];
    stack[-6] = v0159;
    fn = elt(env, 10); /* numlis */
    v0159 = (*qfn1(fn))(qenv(fn), v0159);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-7];
    if (v0159 == nil) goto v0177;
    v0159 = stack[-6];
    v0160 = Llength(nil, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-7];
    v0159 = (Lisp_Object)17; /* 1 */
    v0159 = Lneq(nil, v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-7];
    goto v0088;

v0088:
    if (v0159 == nil) goto v0178;
    v0160 = stack[-5];
    v0159 = elt(env, 6); /* hold */
    {
        popv(8);
        fn = elt(env, 11); /* errpri2 */
        return (*qfn2(fn))(qenv(fn), v0160, v0159);
    }

v0178:
    v0159 = stack[-3];
    v0159 = qcdr(v0159);
    v0161 = qcar(v0159);
    v0159 = stack[-5];
    v0159 = qcdr(v0159);
    v0160 = qcar(v0159);
    v0159 = stack[-4];
    *(Lisp_Object *)((char *)v0161 + (CELL-TAG_VECTOR) + ((int32_t)v0160/(16/CELL))) = v0159;
    goto v0017;

v0177:
    v0159 = qvalue(elt(env, 5)); /* t */
    goto v0088;

v0010:
    stack[-1] = elt(env, 2); /* matrix */
    stack[0] = (Lisp_Object)161; /* 10 */
    v0161 = elt(env, 3); /* "Matrix" */
    v0159 = stack[-5];
    v0160 = qcar(v0159);
    v0159 = elt(env, 4); /* "not set" */
    v0159 = list3(v0161, v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-7];
    fn = elt(env, 13); /* rerror */
    v0159 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0159);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    goto v0178;
/* error exit handlers */
v0163:
    popv(8);
    return nil;
}



/* Code for symtabget */

static Lisp_Object CC_symtabget(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0094, v0003, v0004, v0179;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symtabget");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0014;
    v0003 = v0000;
/* end of prologue */
    v0094 = v0004;
    if (v0094 == nil) goto v0013;
    v0094 = v0003;
    if (!(v0094 == nil)) goto v0008;
    v0094 = qvalue(elt(env, 1)); /* !*symboltable!* */
    v0094 = qcar(v0094);
    goto v0008;

v0008:
    v0003 = v0094;
    goto v0013;

v0013:
    v0094 = v0003;
    if (v0094 == nil) goto v0035;
    v0094 = v0004;
    v0179 = elt(env, 2); /* (!*type!* !*params!* !*decs!*) */
    v0094 = Lmemq(nil, v0094, v0179);
    if (v0094 == nil) goto v0057;
    v0094 = v0003;
    v0003 = v0004;
    return get(v0094, v0003);

v0057:
    v0094 = v0004;
    if (!symbolp(v0003)) v0003 = nil;
    else { v0003 = qfastgets(v0003);
           if (v0003 != nil) { v0003 = elt(v0003, 58); /* !*decs!* */
#ifdef RECORD_GET
             if (v0003 != SPID_NOPROP)
                record_get(elt(fastget_names, 58), 1);
             else record_get(elt(fastget_names, 58), 0),
                v0003 = nil; }
           else record_get(elt(fastget_names, 58), 0); }
#else
             if (v0003 == SPID_NOPROP) v0003 = nil; }}
#endif
    v0094 = Lassoc(nil, v0094, v0003);
    return onevalue(v0094);

v0035:
    v0094 = qvalue(elt(env, 1)); /* !*symboltable!* */
    return onevalue(v0094);
}



/* Code for vdpgetprop */

static Lisp_Object CC_vdpgetprop(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0107, v0031, v0181, v0061;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpgetprop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0181 = v0014;
    v0061 = v0000;
/* end of prologue */
    v0107 = v0061;
    if (v0107 == nil) goto v0005;
    v0031 = v0061;
    v0107 = elt(env, 2); /* vdp */
    if (!consp(v0031)) goto v0018;
    v0031 = qcar(v0031);
    if (!(v0031 == v0107)) goto v0018;
    v0107 = v0181;
    v0031 = v0061;
    v0031 = qcdr(v0031);
    v0031 = qcdr(v0031);
    v0031 = qcdr(v0031);
    v0031 = qcdr(v0031);
    v0031 = qcar(v0031);
    v0107 = Lassoc(nil, v0107, v0031);
    v0031 = v0107;
    v0107 = v0031;
    if (v0107 == nil) goto v0028;
    v0107 = v0031;
    v0107 = qcdr(v0107);
    { popv(3); return onevalue(v0107); }

v0028:
    v0107 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0107); }

v0018:
    stack[-1] = elt(env, 3); /* dipoly */
    stack[0] = (Lisp_Object)113; /* 7 */
    v0107 = elt(env, 4); /* "vdpgetprop given a non-vdp as 1st parameter" 
*/
    v0031 = v0061;
    v0107 = list3(v0107, v0031, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-2];
    {
        Lisp_Object v0104 = stack[-1];
        Lisp_Object v0105 = stack[0];
        popv(3);
        fn = elt(env, 5); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0104, v0105, v0107);
    }

v0005:
    v0107 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0107); }
/* error exit handlers */
v0087:
    popv(3);
    return nil;
}



/* Code for csl_timbf */

static Lisp_Object CC_csl_timbf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0061, v0075, v0109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for csl_timbf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0014;
    stack[-3] = v0000;
/* end of prologue */
    v0061 = stack[-3];
    v0061 = qcdr(v0061);
    v0075 = qcar(v0061);
    v0061 = stack[-2];
    v0061 = qcdr(v0061);
    v0061 = qcar(v0061);
    v0061 = times2(v0075, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-5];
    v0109 = v0061;
    v0075 = v0109;
    v0061 = (Lisp_Object)1; /* 0 */
    if (v0075 == v0061) goto v0018;
    v0075 = v0109;
    v0061 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 4); /* inorm */
    v0061 = (*qfn2(fn))(qenv(fn), v0075, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-5];
    v0109 = v0061;
    stack[-4] = elt(env, 3); /* !:rd!: */
    v0061 = v0109;
    stack[-1] = qcar(v0061);
    v0061 = v0109;
    stack[0] = qcdr(v0061);
    v0061 = stack[-3];
    v0061 = qcdr(v0061);
    v0075 = qcdr(v0061);
    v0061 = stack[-2];
    v0061 = qcdr(v0061);
    v0061 = qcdr(v0061);
    v0061 = plus2(v0075, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-5];
    v0061 = plus2(stack[0], v0061);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    {
        Lisp_Object v0073 = stack[-4];
        Lisp_Object v0074 = stack[-1];
        popv(6);
        return list2star(v0073, v0074, v0061);
    }

v0018:
    v0061 = elt(env, 1); /* (!:rd!: 0 . 0) */
    { popv(6); return onevalue(v0061); }
/* error exit handlers */
v0043:
    popv(6);
    return nil;
}



/* Code for putpline */

static Lisp_Object CC_putpline(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0185, v0186, v0067;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for putpline");
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
    v0186 = qvalue(elt(env, 1)); /* posn!* */
    v0185 = stack[0];
    v0185 = qcar(v0185);
    v0185 = qcdr(v0185);
    stack[-1] = (Lisp_Object)(int32_t)((int32_t)v0186 + (int32_t)v0185 - TAG_FIXNUM);
    v0185 = qvalue(elt(env, 2)); /* nil */
    v0186 = Llinelength(nil, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    v0185 = qvalue(elt(env, 3)); /* spare!* */
    v0185 = (Lisp_Object)(int32_t)((int32_t)v0186 - (int32_t)v0185 + TAG_FIXNUM);
    v0185 = (Lisp_Object)greaterp2(stack[-1], v0185);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    v0185 = v0185 ? lisp_true : nil;
    env = stack[-2];
    if (v0185 == nil) goto v0094;
    v0185 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 10); /* terpri!* */
    v0185 = (*qfn1(fn))(qenv(fn), v0185);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    goto v0094;

v0094:
    v0186 = qvalue(elt(env, 1)); /* posn!* */
    v0185 = qvalue(elt(env, 5)); /* orig!* */
    v0067 = (Lisp_Object)(int32_t)((int32_t)v0186 - (int32_t)v0185 + TAG_FIXNUM);
    v0186 = qvalue(elt(env, 6)); /* ycoord!* */
    v0185 = stack[0];
    v0185 = qcar(v0185);
    v0185 = qcar(v0185);
    fn = elt(env, 11); /* update!-pline */
    v0186 = (*qfnn(fn))(qenv(fn), 3, v0067, v0186, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    v0185 = qvalue(elt(env, 7)); /* pline!* */
    v0185 = Lappend(nil, v0186, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    qvalue(elt(env, 7)) = v0185; /* pline!* */
    v0186 = qvalue(elt(env, 1)); /* posn!* */
    v0185 = stack[0];
    v0185 = qcar(v0185);
    v0185 = qcdr(v0185);
    v0185 = (Lisp_Object)(int32_t)((int32_t)v0186 + (int32_t)v0185 - TAG_FIXNUM);
    qvalue(elt(env, 1)) = v0185; /* posn!* */
    v0067 = qvalue(elt(env, 8)); /* ymin!* */
    v0185 = stack[0];
    v0185 = qcdr(v0185);
    v0186 = qcar(v0185);
    v0185 = qvalue(elt(env, 6)); /* ycoord!* */
    v0185 = (Lisp_Object)(int32_t)((int32_t)v0186 + (int32_t)v0185 - TAG_FIXNUM);
    fn = elt(env, 12); /* min */
    v0185 = (*qfn2(fn))(qenv(fn), v0067, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    qvalue(elt(env, 8)) = v0185; /* ymin!* */
    v0067 = qvalue(elt(env, 9)); /* ymax!* */
    v0185 = stack[0];
    v0185 = qcdr(v0185);
    v0186 = qcdr(v0185);
    v0185 = qvalue(elt(env, 6)); /* ycoord!* */
    v0185 = (Lisp_Object)(int32_t)((int32_t)v0186 + (int32_t)v0185 - TAG_FIXNUM);
    fn = elt(env, 13); /* max */
    v0185 = (*qfn2(fn))(qenv(fn), v0067, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    qvalue(elt(env, 9)) = v0185; /* ymax!* */
    v0185 = nil;
    { popv(3); return onevalue(v0185); }
/* error exit handlers */
v0089:
    popv(3);
    return nil;
}



/* Code for quotfd */

static Lisp_Object CC_quotfd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0187, v0032, v0088, v0177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0088 = v0014;
    v0177 = v0000;
/* end of prologue */
    v0032 = v0177;
    v0187 = v0088;
    if (equal(v0032, v0187)) goto v0005;
    v0187 = qvalue(elt(env, 1)); /* dmode!* */
    if (!symbolp(v0187)) v0187 = nil;
    else { v0187 = qfastgets(v0187);
           if (v0187 != nil) { v0187 = elt(v0187, 3); /* field */
#ifdef RECORD_GET
             if (v0187 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0187 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0187 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0187 == SPID_NOPROP) v0187 = nil; else v0187 = lisp_true; }}
#endif
    if (v0187 == nil) goto v0035;
    v0187 = v0177;
    v0032 = v0088;
    {
        fn = elt(env, 3); /* divd */
        return (*qfn2(fn))(qenv(fn), v0187, v0032);
    }

v0035:
    v0187 = v0177;
    if (!consp(v0187)) goto v0054;
    v0187 = v0177;
    v0187 = qcar(v0187);
    v0187 = (consp(v0187) ? nil : lisp_true);
    goto v0077;

v0077:
    if (v0187 == nil) goto v0004;
    v0187 = v0177;
    v0032 = v0088;
    {
        fn = elt(env, 4); /* quotdd */
        return (*qfn2(fn))(qenv(fn), v0187, v0032);
    }

v0004:
    v0187 = v0177;
    v0032 = v0088;
    {
        fn = elt(env, 5); /* quotk */
        return (*qfn2(fn))(qenv(fn), v0187, v0032);
    }

v0054:
    v0187 = qvalue(elt(env, 2)); /* t */
    goto v0077;

v0005:
    v0187 = (Lisp_Object)17; /* 1 */
    return onevalue(v0187);
}



/* Code for lprim */

static Lisp_Object CC_lprim(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0078, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lprim");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0078 = v0000;
/* end of prologue */
    v0015 = qvalue(elt(env, 1)); /* !*msg */
    if (v0015 == nil) goto v0013;
    v0015 = elt(env, 3); /* "***" */
    {
        fn = elt(env, 4); /* lpriw */
        return (*qfn2(fn))(qenv(fn), v0015, v0078);
    }

v0013:
    v0078 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0078);
}



/* Code for errorset2 */

static Lisp_Object CC_errorset2(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0078, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for errorset2");
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
    v0078 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*protfg */
    qvalue(elt(env, 1)) = nil; /* !*protfg */
    v0017 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v0017; /* !*protfg */
    v0015 = v0078;
    v0078 = qvalue(elt(env, 3)); /* nil */
    v0017 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 4); /* errorset */
    v0017 = (*qfnn(fn))(qenv(fn), 3, v0015, v0078, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*protfg */
    { popv(2); return onevalue(v0017); }
/* error exit handlers */
v0019:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*protfg */
    popv(2);
    return nil;
}



/* Code for gperm2 */

static Lisp_Object MS_CDECL CC_gperm2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0014,
                         Lisp_Object v0001, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0041, v0030, v0093;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "gperm2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0001,v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0014,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0014;
    v0040 = v0000;
/* end of prologue */

v0012:
    v0041 = v0040;
    if (v0041 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0041 = v0040;
    v0041 = qcdr(v0041);
    stack[-2] = v0041;
    v0041 = qcar(v0040);
    v0040 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* rev */
    v0093 = (*qfn2(fn))(qenv(fn), v0041, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    v0030 = stack[-1];
    v0041 = qvalue(elt(env, 1)); /* nil */
    v0040 = stack[0];
    fn = elt(env, 3); /* gperm1 */
    v0040 = (*qfnn(fn))(qenv(fn), 4, v0093, v0030, v0041, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    stack[0] = v0040;
    v0040 = stack[-2];
    goto v0012;
/* error exit handlers */
v0060:
    popv(4);
    return nil;
}



/* Code for carx */

static Lisp_Object CC_carx(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0022, v0023;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for carx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0022 = v0014;
    v0023 = v0000;
/* end of prologue */
    v0054 = v0023;
    v0054 = qcdr(v0054);
    if (v0054 == nil) goto v0005;
    stack[-1] = elt(env, 1); /* alg */
    stack[0] = (Lisp_Object)81; /* 5 */
    v0054 = elt(env, 2); /* "Wrong number of arguments to" */
    v0054 = list2(v0054, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    {
        Lisp_Object v0092 = stack[-1];
        Lisp_Object v0025 = stack[0];
        popv(3);
        fn = elt(env, 3); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0092, v0025, v0054);
    }

v0005:
    v0054 = v0023;
    v0054 = qcar(v0054);
    { popv(3); return onevalue(v0054); }
/* error exit handlers */
v0010:
    popv(3);
    return nil;
}



/* Code for procstat */

static Lisp_Object MS_CDECL CC_procstat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "procstat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for procstat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0036 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* procstat1 */
        return (*qfn1(fn))(qenv(fn), v0036);
    }
}



/* Code for ofsf_posvarpat */

static Lisp_Object CC_ofsf_posvarpat(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0052, v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_posvarpat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0014;
    v0053 = v0000;
/* end of prologue */
    v0093 = v0053;
    if (!consp(v0093)) goto v0037;
    v0093 = v0053;
    v0093 = qcar(v0093);
    goto v0012;

v0012:
    stack[-1] = v0093;
    v0052 = stack[-1];
    v0093 = elt(env, 1); /* (greaterp geq) */
    v0093 = Lmemq(nil, v0052, v0093);
    if (v0093 == nil) goto v0078;
    v0093 = v0053;
    v0093 = qcdr(v0093);
    v0093 = qcar(v0093);
    fn = elt(env, 3); /* sfto_varp */
    v0052 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    v0093 = stack[0];
    if (v0052 == v0093) { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
    v0093 = nil;
    { popv(2); return onevalue(v0093); }

v0078:
    v0093 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0093); }

v0037:
    v0093 = v0053;
    goto v0012;
/* error exit handlers */
v0094:
    popv(2);
    return nil;
}



/* Code for polynomadd */

static Lisp_Object CC_polynomadd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0194, v0108, v0195;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomadd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0108 = v0014;
    stack[-2] = v0000;
/* end of prologue */
    v0194 = stack[-2];
    stack[-3] = v0194;
    v0194 = v0108;
    stack[-1] = v0194;
    goto v0033;

v0033:
    v0194 = stack[-3];
    v0194 = qcar(v0194);
    if (v0194 == nil) goto v0006;
    v0194 = stack[-1];
    v0194 = qcar(v0194);
    if (v0194 == nil) goto v0006;
    v0194 = stack[-3];
    v0108 = qcar(v0194);
    v0194 = stack[-1];
    v0194 = qcar(v0194);
    fn = elt(env, 2); /* monomcompare */
    v0194 = (*qfn2(fn))(qenv(fn), v0108, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-4];
    v0195 = v0194;
    v0108 = v0195;
    v0194 = (Lisp_Object)17; /* 1 */
    if (v0108 == v0194) goto v0092;
    v0108 = v0195;
    v0194 = (Lisp_Object)-15; /* -1 */
    if (v0108 == v0194) goto v0106;
    v0108 = stack[-3];
    v0194 = stack[-3];
    v0194 = qcdr(v0194);
    v0194 = qcar(v0194);
    v0108 = Lrplaca(nil, v0108, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-4];
    v0194 = stack[-3];
    v0194 = qcdr(v0194);
    v0194 = qcdr(v0194);
    v0194 = Lrplacd(nil, v0108, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-4];
    v0194 = stack[-1];
    v0194 = qcdr(v0194);
    stack[-1] = v0194;
    goto v0033;

v0106:
    stack[0] = stack[-3];
    v0194 = stack[-3];
    v0108 = qcar(v0194);
    v0194 = stack[-3];
    v0194 = qcdr(v0194);
    v0194 = cons(v0108, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-4];
    v0108 = Lrplacd(nil, stack[0], v0194);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-4];
    v0194 = stack[-1];
    v0194 = qcar(v0194);
    v0194 = Lrplaca(nil, v0108, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-4];
    v0194 = stack[-3];
    v0194 = qcdr(v0194);
    stack[-3] = v0194;
    v0194 = stack[-1];
    v0194 = qcdr(v0194);
    stack[-1] = v0194;
    goto v0033;

v0092:
    v0194 = stack[-3];
    v0194 = qcdr(v0194);
    stack[-3] = v0194;
    goto v0033;

v0006:
    v0194 = stack[-1];
    v0194 = qcar(v0194);
    if (v0194 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0108 = stack[-3];
    v0194 = stack[-1];
    v0194 = Lrplacd(nil, v0108, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-4];
    stack[0] = v0194;
    v0108 = stack[0];
    v0194 = stack[0];
    v0194 = qcdr(v0194);
    v0194 = qcar(v0194);
    v0108 = Lrplaca(nil, v0108, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-4];
    v0194 = stack[0];
    v0194 = qcdr(v0194);
    v0194 = qcdr(v0194);
    v0194 = Lrplacd(nil, v0108, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
/* error exit handlers */
v0196:
    popv(5);
    return nil;
}



/* Code for lto_catsoc */

static Lisp_Object CC_lto_catsoc(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0018;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_catsoc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0015 = v0014;
    v0018 = v0000;
/* end of prologue */
    v0015 = Latsoc(nil, v0018, v0015);
    v0018 = v0015;
    v0015 = v0018;
    if (v0015 == nil) goto v0016;
    v0015 = v0018;
    v0015 = qcdr(v0015);
    return onevalue(v0015);

v0016:
    v0015 = nil;
    return onevalue(v0015);
}



/* Code for wulessp!* */

static Lisp_Object CC_wulesspH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0092, v0025;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wulessp*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0014;
    stack[-1] = v0000;
/* end of prologue */
    v0025 = stack[-1];
    v0092 = stack[0];
    fn = elt(env, 3); /* wulessp */
    v0092 = (*qfn2(fn))(qenv(fn), v0025, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    if (v0092 == nil) goto v0015;
    v0092 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0092); }

v0015:
    v0025 = stack[0];
    v0092 = stack[-1];
    fn = elt(env, 3); /* wulessp */
    v0092 = (*qfn2(fn))(qenv(fn), v0025, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    if (v0092 == nil) goto v0077;
    v0092 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0092); }

v0077:
    v0025 = stack[-1];
    v0092 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* totallessp */
        return (*qfn2(fn))(qenv(fn), v0025, v0092);
    }
/* error exit handlers */
v0040:
    popv(3);
    return nil;
}



/* Code for setdiff */

static Lisp_Object CC_setdiff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0077;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setdiff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0014;
    v0021 = v0000;
/* end of prologue */

v0005:
    v0077 = stack[0];
    if (v0077 == nil) { popv(2); return onevalue(v0021); }
    v0077 = v0021;
    if (v0077 == nil) goto v0006;
    v0077 = stack[0];
    v0077 = qcar(v0077);
    v0021 = Ldelete(nil, v0077, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    v0077 = stack[0];
    v0077 = qcdr(v0077);
    stack[0] = v0077;
    goto v0005;

v0006:
    v0021 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0021); }
/* error exit handlers */
v0022:
    popv(2);
    return nil;
}



/* Code for qqe_number!-of!-tails!-in!-qterm */

static Lisp_Object CC_qqe_numberKofKtailsKinKqterm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0077, v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_number-of-tails-in-qterm");
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

v0013:
    v0077 = stack[0];
    if (!consp(v0077)) goto v0012;
    v0077 = stack[0];
    fn = elt(env, 2); /* qqe_op */
    v0054 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-1];
    v0077 = elt(env, 1); /* (ladd radd) */
    v0077 = Lmemq(nil, v0054, v0077);
    if (v0077 == nil) goto v0058;
    v0077 = stack[0];
    fn = elt(env, 3); /* qqe_arg2r */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-1];
    stack[0] = v0077;
    goto v0013;

v0058:
    v0077 = stack[0];
    fn = elt(env, 4); /* qqe_arg2l */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-1];
    v0077 = CC_qqe_numberKofKtailsKinKqterm(env, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    popv(2);
    return add1(v0077);

v0012:
    v0077 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v0077); }
/* error exit handlers */
v0023:
    popv(2);
    return nil;
}



/* Code for pasf_susitf */

static Lisp_Object CC_pasf_susitf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object v0013, v0005;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_susitf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0013 = v0014;
    v0005 = v0000;
/* end of prologue */
    return onevalue(v0005);
}



/* Code for ibalp_istotal */

static Lisp_Object CC_ibalp_istotal(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0091;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_istotal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0095 = v0000;
/* end of prologue */

v0197:
    v0091 = v0095;
    if (v0091 == nil) goto v0013;
    v0091 = v0095;
    v0091 = qcar(v0091);
    v0091 = qcdr(v0091);
    v0091 = qcdr(v0091);
    v0091 = qcar(v0091);
    if (v0091 == nil) goto v0006;
    v0095 = qcdr(v0095);
    goto v0197;

v0006:
    v0095 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0095);

v0013:
    v0095 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0095);
}



/* Code for quotient!-mod!-p */

static Lisp_Object CC_quotientKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0150, v0165, v0164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotient-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0014;
    stack[-2] = v0000;
/* end of prologue */
    v0150 = stack[-1];
    if (v0150 == nil) goto v0005;
    v0150 = stack[-1];
    if (!consp(v0150)) goto v0034;
    v0150 = stack[-1];
    v0150 = qcar(v0150);
    v0150 = (consp(v0150) ? nil : lisp_true);
    goto v0033;

v0033:
    if (v0150 == nil) goto v0007;
    v0150 = stack[-1];
    fn = elt(env, 5); /* safe!-modular!-reciprocal */
    v0150 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-4];
    v0165 = stack[-1];
    if (v0165 == nil) goto v0077;
    v0165 = stack[-2];
    {
        popv(5);
        fn = elt(env, 6); /* multiply!-by!-constant!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0165, v0150);
    }

v0077:
    v0150 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v0150; /* exact!-quotient!-flag */
    { popv(5); return onevalue(v0150); }

v0007:
    v0150 = stack[-2];
    if (v0150 == nil) goto v0093;
    v0150 = stack[-2];
    if (!consp(v0150)) goto v0179;
    v0150 = stack[-2];
    v0150 = qcar(v0150);
    v0150 = (consp(v0150) ? nil : lisp_true);
    goto v0004;

v0004:
    if (v0150 == nil) goto v0029;
    v0150 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v0150; /* exact!-quotient!-flag */
    { popv(5); return onevalue(v0150); }

v0029:
    v0150 = stack[-2];
    v0150 = qcar(v0150);
    v0150 = qcar(v0150);
    v0165 = qcar(v0150);
    v0150 = stack[-1];
    v0150 = qcar(v0150);
    v0150 = qcar(v0150);
    v0150 = qcar(v0150);
    if (equal(v0165, v0150)) goto v0073;
    v0150 = stack[-2];
    v0150 = qcar(v0150);
    v0150 = qcar(v0150);
    v0165 = qcar(v0150);
    v0150 = stack[-1];
    v0150 = qcar(v0150);
    v0150 = qcar(v0150);
    v0150 = qcar(v0150);
    fn = elt(env, 7); /* ordop */
    v0150 = (*qfn2(fn))(qenv(fn), v0165, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-4];
    if (v0150 == nil) goto v0085;
    v0150 = stack[-2];
    v0150 = qcar(v0150);
    stack[-3] = qcar(v0150);
    v0150 = stack[-2];
    v0150 = qcar(v0150);
    v0165 = qcdr(v0150);
    v0150 = stack[-1];
    stack[0] = CC_quotientKmodKp(env, v0165, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-4];
    v0150 = stack[-2];
    v0165 = qcdr(v0150);
    v0150 = stack[-1];
    v0150 = CC_quotientKmodKp(env, v0165, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-4];
    {
        Lisp_Object v0201 = stack[-3];
        Lisp_Object v0194 = stack[0];
        popv(5);
        fn = elt(env, 8); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0201, v0194, v0150);
    }

v0085:
    v0150 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v0150; /* exact!-quotient!-flag */
    { popv(5); return onevalue(v0150); }

v0073:
    v0164 = stack[-2];
    v0165 = stack[-1];
    v0150 = stack[-1];
    v0150 = qcar(v0150);
    v0150 = qcar(v0150);
    v0150 = qcar(v0150);
    {
        popv(5);
        fn = elt(env, 9); /* xquotient!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 3, v0164, v0165, v0150);
    }

v0179:
    v0150 = qvalue(elt(env, 2)); /* t */
    goto v0004;

v0093:
    v0150 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v0150); }

v0034:
    v0150 = qvalue(elt(env, 2)); /* t */
    goto v0033;

v0005:
    v0150 = elt(env, 1); /* "B=0 IN QUOTIENT-MOD-P" */
    {
        popv(5);
        fn = elt(env, 10); /* errorf */
        return (*qfn1(fn))(qenv(fn), v0150);
    }
/* error exit handlers */
v0200:
    popv(5);
    return nil;
}



/* Code for difff */

static Lisp_Object CC_difff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0204, v0150, v0165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0014;
    stack[-2] = v0000;
/* end of prologue */
    v0204 = stack[-2];
    if (!consp(v0204)) goto v0008;
    v0204 = stack[-2];
    v0204 = qcar(v0204);
    if (!consp(v0204)) goto v0019;
    v0204 = stack[-2];
    v0204 = qcar(v0204);
    v0150 = qcar(v0204);
    v0204 = (Lisp_Object)17; /* 1 */
    v0204 = cons(v0150, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-4];
    v0150 = ncons(v0204);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-4];
    v0204 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0150, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-4];
    v0204 = stack[-2];
    v0204 = qcar(v0204);
    v0150 = qcdr(v0204);
    v0204 = stack[-1];
    v0204 = CC_difff(env, v0150, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    stack[-3] = (*qfn2(fn))(qenv(fn), stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-4];
    v0204 = stack[-2];
    v0204 = qcar(v0204);
    v0150 = qcar(v0204);
    v0204 = stack[-1];
    fn = elt(env, 4); /* diffp */
    stack[0] = (*qfn2(fn))(qenv(fn), v0150, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-4];
    v0204 = stack[-2];
    v0204 = qcar(v0204);
    v0150 = qcdr(v0204);
    v0204 = (Lisp_Object)17; /* 1 */
    v0204 = cons(v0150, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    v0204 = (*qfn2(fn))(qenv(fn), stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-4];
    fn = elt(env, 5); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-4];
    v0204 = stack[-2];
    v0150 = qcdr(v0204);
    v0204 = stack[-1];
    v0204 = CC_difff(env, v0150, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-4];
    {
        Lisp_Object v0200 = stack[0];
        popv(5);
        fn = elt(env, 5); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0200, v0204);
    }

v0019:
    v0204 = stack[-2];
    v0150 = qcar(v0204);
    v0204 = elt(env, 2); /* domain!-diff!-fn */
    v0204 = get(v0150, v0204);
    env = stack[-4];
    v0150 = v0204;
    v0204 = v0150;
    if (v0204 == nil) goto v0094;
    v0165 = v0150;
    v0150 = stack[-2];
    v0204 = stack[-1];
        popv(5);
        return Lapply2(nil, 3, v0165, v0150, v0204);

v0094:
    v0150 = qvalue(elt(env, 1)); /* nil */
    v0204 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0150, v0204);

v0008:
    v0150 = qvalue(elt(env, 1)); /* nil */
    v0204 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0150, v0204);
/* error exit handlers */
v0188:
    popv(5);
    return nil;
}



/* Code for retimes1 */

static Lisp_Object CC_retimes1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0198, v0203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for retimes1");
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
    goto v0005;

v0005:
    v0198 = stack[0];
    if (v0198 == nil) goto v0037;
    v0198 = stack[0];
    v0203 = qcar(v0198);
    v0198 = (Lisp_Object)17; /* 1 */
    if (v0203 == v0198) goto v0033;
    v0198 = stack[0];
    v0198 = qcar(v0198);
    v0198 = Lminusp(nil, v0198);
    env = stack[-2];
    if (v0198 == nil) goto v0091;
    v0198 = qvalue(elt(env, 1)); /* !*bool */
    v0198 = (v0198 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v0198; /* !*bool */
    v0198 = stack[0];
    v0198 = qcar(v0198);
    v0203 = negate(v0198);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    v0198 = stack[0];
    v0198 = qcdr(v0198);
    v0198 = cons(v0203, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    stack[0] = v0198;
    goto v0005;

v0091:
    v0198 = stack[0];
    v0198 = qcar(v0198);
    if (!consp(v0198)) goto v0060;
    v0198 = stack[0];
    v0198 = qcar(v0198);
    v0203 = qcar(v0198);
    v0198 = elt(env, 2); /* minus */
    if (v0203 == v0198) goto v0187;
    v0198 = stack[0];
    v0198 = qcar(v0198);
    v0203 = qcar(v0198);
    v0198 = elt(env, 3); /* times */
    if (v0203 == v0198) goto v0069;
    v0198 = stack[0];
    v0203 = qcar(v0198);
    v0198 = stack[-1];
    v0198 = cons(v0203, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    stack[-1] = v0198;
    v0198 = stack[0];
    v0198 = qcdr(v0198);
    stack[0] = v0198;
    goto v0005;

v0069:
    v0198 = stack[0];
    v0198 = qcar(v0198);
    v0203 = qcdr(v0198);
    v0198 = stack[0];
    v0198 = qcdr(v0198);
    v0198 = Lappend(nil, v0203, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    stack[0] = v0198;
    goto v0005;

v0187:
    v0198 = qvalue(elt(env, 1)); /* !*bool */
    v0198 = (v0198 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v0198; /* !*bool */
    v0198 = stack[0];
    v0198 = qcar(v0198);
    v0198 = qcdr(v0198);
    v0203 = qcar(v0198);
    v0198 = stack[0];
    v0198 = qcdr(v0198);
    v0198 = cons(v0203, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    stack[0] = v0198;
    goto v0005;

v0060:
    v0198 = stack[0];
    v0203 = qcar(v0198);
    v0198 = stack[-1];
    v0198 = cons(v0203, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    stack[-1] = v0198;
    v0198 = stack[0];
    v0198 = qcdr(v0198);
    stack[0] = v0198;
    goto v0005;

v0033:
    v0198 = stack[0];
    v0198 = qcdr(v0198);
    stack[0] = v0198;
    goto v0005;

v0037:
    v0198 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0198);
    }
/* error exit handlers */
v0101:
    popv(3);
    return nil;
}



/* Code for groebcpcompless!? */

static Lisp_Object CC_groebcpcomplessW(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0157, v0156, v0065, v0066;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebcpcompless?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0014;
    stack[-1] = v0000;
/* end of prologue */
    v0157 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v0157 == nil) goto v0059;
    v0157 = stack[-1];
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0156 = qcar(v0157);
    v0157 = stack[0];
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    stack[-2] = difference2(v0156, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-3];
    v0157 = stack[-1];
    v0156 = qcar(v0157);
    v0157 = stack[0];
    v0157 = qcar(v0157);
    fn = elt(env, 3); /* vevcomp */
    v0157 = (*qfn2(fn))(qenv(fn), v0156, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-3];
    v0066 = stack[-2];
    v0065 = v0157;
    v0156 = v0066;
    v0157 = (Lisp_Object)1; /* 0 */
    if (v0156 == v0157) goto v0051;
    v0156 = v0066;
    v0157 = (Lisp_Object)1; /* 0 */
        popv(4);
        return Llessp(nil, v0156, v0157);

v0051:
    v0156 = v0065;
    v0157 = (Lisp_Object)1; /* 0 */
    if (v0156 == v0157) goto v0208;
    v0156 = v0065;
    v0157 = (Lisp_Object)1; /* 0 */
        popv(4);
        return Llessp(nil, v0156, v0157);

v0208:
    v0157 = stack[-1];
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0156 = qcar(v0157);
    v0157 = elt(env, 2); /* number */
    fn = elt(env, 4); /* vdpgetprop */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0156, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-3];
    v0157 = stack[0];
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0156 = qcar(v0157);
    v0157 = elt(env, 2); /* number */
    fn = elt(env, 4); /* vdpgetprop */
    v0157 = (*qfn2(fn))(qenv(fn), v0156, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    {
        Lisp_Object v0101 = stack[-1];
        popv(4);
        return Llessp(nil, v0101, v0157);
    }

v0059:
    v0157 = stack[-1];
    v0156 = qcar(v0157);
    v0157 = stack[0];
    v0157 = qcar(v0157);
    {
        popv(4);
        fn = elt(env, 5); /* vevcompless!? */
        return (*qfn2(fn))(qenv(fn), v0156, v0157);
    }
/* error exit handlers */
v0100:
    popv(4);
    return nil;
}



/* Code for evtdeg */

static Lisp_Object CC_evtdeg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0091, v0038;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evtdeg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0091 = v0000;
/* end of prologue */
    v0095 = (Lisp_Object)1; /* 0 */
    goto v0042;

v0042:
    v0038 = v0091;
    if (v0038 == nil) return onevalue(v0095);
    v0038 = v0091;
    v0038 = qcar(v0038);
    v0095 = (Lisp_Object)(int32_t)((int32_t)v0038 + (int32_t)v0095 - TAG_FIXNUM);
    v0091 = qcdr(v0091);
    goto v0042;
}



/* Code for deg!*farg */

static Lisp_Object CC_degHfarg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deg*farg");
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
    v0030 = v0000;
/* end of prologue */
    v0041 = v0030;
    v0041 = qcdr(v0041);
    if (v0041 == nil) goto v0013;
    stack[-1] = nil;
    v0041 = v0030;
    stack[0] = v0041;
    goto v0015;

v0015:
    v0041 = stack[0];
    if (v0041 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0041 = stack[0];
    v0041 = qcar(v0041);
    fn = elt(env, 2); /* deg!*form */
    v0030 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-2];
    v0041 = stack[-1];
    fn = elt(env, 3); /* addf */
    v0041 = (*qfn2(fn))(qenv(fn), v0030, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-2];
    stack[-1] = v0041;
    v0041 = stack[0];
    v0041 = qcdr(v0041);
    stack[0] = v0041;
    goto v0015;

v0013:
    v0041 = v0030;
    v0041 = qcar(v0041);
    {
        popv(3);
        fn = elt(env, 2); /* deg!*form */
        return (*qfn1(fn))(qenv(fn), v0041);
    }
/* error exit handlers */
v0053:
    popv(3);
    return nil;
}



/* Code for ncmpchk */

static Lisp_Object CC_ncmpchk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ncmpchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0014;
    stack[-1] = v0000;
/* end of prologue */
    v0038 = stack[-1];
    v0091 = stack[0];
    fn = elt(env, 2); /* noncommuting */
    v0091 = (*qfn2(fn))(qenv(fn), v0038, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[-2];
    if (v0091 == nil) goto v0005;
    v0038 = stack[-1];
    v0091 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* ordop */
        return (*qfn2(fn))(qenv(fn), v0038, v0091);
    }

v0005:
    v0091 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0091); }
/* error exit handlers */
v0077:
    popv(3);
    return nil;
}



/* Code for ord */

static Lisp_Object CC_ord(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0038, v0039;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ord");
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
    v0039 = v0000;
/* end of prologue */
    v0038 = qvalue(elt(env, 1)); /* ordering */
    v0091 = elt(env, 2); /* lex */
    if (v0038 == v0091) goto v0016;
    v0091 = v0039;
    v0091 = qcar(v0091);
    { popv(1); return onevalue(v0091); }

v0016:
    v0091 = elt(env, 3); /* plus */
    v0038 = v0039;
    v0091 = cons(v0091, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); /* eval */
        return (*qfn1(fn))(qenv(fn), v0091);
    }
/* error exit handlers */
v0021:
    popv(1);
    return nil;
}



/* Code for times!-in!-vector */

static Lisp_Object MS_CDECL CC_timesKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0014,
                         Lisp_Object v0001, Lisp_Object v0036,
                         Lisp_Object v0013, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0166, v0216, v0217, v0218, v0219, v0220, v0221, v0146, v0222, v0147, v0223, v0224, v0225, v0226, v0227;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "times-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for times-in-vector");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0013,v0036,v0001,v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0014,v0001,v0036,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0147 = v0013;
    v0223 = v0036;
    v0224 = v0001;
    v0225 = v0014;
    v0226 = v0000;
/* end of prologue */
    v0216 = v0225;
    v0166 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v0216)) < ((int32_t)(v0166))) goto v0033;
    v0216 = v0223;
    v0166 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v0216)) < ((int32_t)(v0166))) goto v0033;
    v0216 = v0225;
    v0166 = v0223;
    v0166 = (Lisp_Object)(int32_t)((int32_t)v0216 + (int32_t)v0166 - TAG_FIXNUM);
    v0227 = v0166;
    v0166 = (Lisp_Object)1; /* 0 */
    v0218 = v0166;
    goto v0094;

v0094:
    v0216 = v0227;
    v0166 = v0218;
    v0166 = (Lisp_Object)(int32_t)((int32_t)v0216 - (int32_t)v0166 + TAG_FIXNUM);
    v0166 = ((intptr_t)(v0166) < 0 ? lisp_true : nil);
    if (v0166 == nil) goto v0032;
    v0166 = (Lisp_Object)1; /* 0 */
    v0146 = v0166;
    goto v0193;

v0193:
    v0216 = v0225;
    v0166 = v0146;
    v0166 = (Lisp_Object)(int32_t)((int32_t)v0216 - (int32_t)v0166 + TAG_FIXNUM);
    v0166 = ((intptr_t)(v0166) < 0 ? lisp_true : nil);
    if (!(v0166 == nil)) { popv(1); return onevalue(v0227); }
    v0216 = v0226;
    v0166 = v0146;
    v0166 = *(Lisp_Object *)((char *)v0216 + (CELL-TAG_VECTOR) + ((int32_t)v0166/(16/CELL)));
    v0222 = v0166;
    v0166 = (Lisp_Object)1; /* 0 */
    v0221 = v0166;
    goto v0186;

v0186:
    v0216 = v0223;
    v0166 = v0221;
    v0166 = (Lisp_Object)(int32_t)((int32_t)v0216 - (int32_t)v0166 + TAG_FIXNUM);
    v0166 = ((intptr_t)(v0166) < 0 ? lisp_true : nil);
    if (v0166 == nil) goto v0066;
    v0166 = v0146;
    v0166 = (Lisp_Object)((int32_t)(v0166) + 0x10);
    v0146 = v0166;
    goto v0193;

v0066:
    v0216 = v0146;
    v0166 = v0221;
    v0166 = (Lisp_Object)(int32_t)((int32_t)v0216 + (int32_t)v0166 - TAG_FIXNUM);
    v0220 = v0147;
    v0219 = v0166;
    v0216 = v0147;
    v0218 = *(Lisp_Object *)((char *)v0216 + (CELL-TAG_VECTOR) + ((int32_t)v0166/(16/CELL)));
    v0217 = v0222;
    v0216 = v0224;
    v0166 = v0221;
    v0166 = *(Lisp_Object *)((char *)v0216 + (CELL-TAG_VECTOR) + ((int32_t)v0166/(16/CELL)));
    v0166 = Lmodular_times(nil, v0217, v0166);
    env = stack[0];
    {   int32_t w = int_of_fixnum(v0218) + int_of_fixnum(v0166);
        if (w >= current_modulus) w -= current_modulus;
        v0166 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v0220 + (CELL-TAG_VECTOR) + ((int32_t)v0219/(16/CELL))) = v0166;
    v0166 = v0221;
    v0166 = (Lisp_Object)((int32_t)(v0166) + 0x10);
    v0221 = v0166;
    goto v0186;

v0032:
    v0217 = v0147;
    v0216 = v0218;
    v0166 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v0217 + (CELL-TAG_VECTOR) + ((int32_t)v0216/(16/CELL))) = v0166;
    v0166 = v0218;
    v0166 = (Lisp_Object)((int32_t)(v0166) + 0x10);
    v0218 = v0166;
    goto v0094;

v0033:
    v0166 = (Lisp_Object)-15; /* -1 */
    { popv(1); return onevalue(v0166); }
}



/* Code for general!-plus!-mod!-p */

static Lisp_Object CC_generalKplusKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0242, v0243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-plus-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0014;
    stack[-3] = v0000;
/* end of prologue */
    stack[0] = nil;
    goto v0042;

v0042:
    v0242 = stack[-3];
    if (v0242 == nil) goto v0033;
    v0242 = stack[-2];
    if (v0242 == nil) goto v0058;
    v0242 = stack[-3];
    if (!consp(v0242)) goto v0027;
    v0242 = stack[-3];
    v0242 = qcar(v0242);
    v0242 = (consp(v0242) ? nil : lisp_true);
    goto v0024;

v0024:
    if (v0242 == nil) goto v0022;
    v0242 = stack[-2];
    if (!consp(v0242)) goto v0003;
    v0242 = stack[-2];
    v0242 = qcar(v0242);
    v0242 = (consp(v0242) ? nil : lisp_true);
    goto v0094;

v0094:
    if (v0242 == nil) goto v0073;
    v0243 = stack[-3];
    v0242 = stack[-2];
    fn = elt(env, 3); /* general!-modular!-plus */
    v0242 = (*qfn2(fn))(qenv(fn), v0243, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-5];
    fn = elt(env, 4); /* !*n2f */
    v0242 = (*qfn1(fn))(qenv(fn), v0242);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-5];
    {
        Lisp_Object v0245 = stack[0];
        popv(6);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0245, v0242);
    }

v0073:
    v0242 = stack[-2];
    v0243 = qcar(v0242);
    v0242 = stack[0];
    v0242 = cons(v0243, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-5];
    stack[0] = v0242;
    v0242 = stack[-2];
    v0242 = qcdr(v0242);
    stack[-2] = v0242;
    goto v0042;

v0003:
    v0242 = qvalue(elt(env, 1)); /* t */
    goto v0094;

v0022:
    v0242 = stack[-2];
    if (!consp(v0242)) goto v0047;
    v0242 = stack[-2];
    v0242 = qcar(v0242);
    v0242 = (consp(v0242) ? nil : lisp_true);
    goto v0046;

v0046:
    if (v0242 == nil) goto v0157;
    v0242 = stack[-3];
    v0243 = qcar(v0242);
    v0242 = stack[0];
    v0242 = cons(v0243, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-5];
    stack[0] = v0242;
    v0242 = stack[-3];
    v0242 = qcdr(v0242);
    stack[-3] = v0242;
    goto v0042;

v0157:
    v0242 = stack[-3];
    v0242 = qcar(v0242);
    v0243 = qcar(v0242);
    v0242 = stack[-2];
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    if (equal(v0243, v0242)) goto v0154;
    v0242 = stack[-3];
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    v0243 = qcar(v0242);
    v0242 = stack[-2];
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    if (equal(v0243, v0242)) goto v0246;
    v0242 = qvalue(elt(env, 2)); /* nil */
    goto v0216;

v0216:
    if (!(v0242 == nil)) goto v0247;
    v0242 = stack[-3];
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    v0243 = qcar(v0242);
    v0242 = stack[-2];
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    if (equal(v0243, v0242)) goto v0138;
    v0242 = stack[-3];
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    v0243 = qcar(v0242);
    v0242 = stack[-2];
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    fn = elt(env, 6); /* ordop */
    v0242 = (*qfn2(fn))(qenv(fn), v0243, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-5];
    goto v0142;

v0142:
    if (!(v0242 == nil)) goto v0247;
    v0242 = stack[-2];
    v0243 = qcar(v0242);
    v0242 = stack[0];
    v0242 = cons(v0243, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-5];
    stack[0] = v0242;
    v0242 = stack[-2];
    v0242 = qcdr(v0242);
    stack[-2] = v0242;
    goto v0042;

v0247:
    v0242 = stack[-3];
    v0243 = qcar(v0242);
    v0242 = stack[0];
    v0242 = cons(v0243, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-5];
    stack[0] = v0242;
    v0242 = stack[-3];
    v0242 = qcdr(v0242);
    stack[-3] = v0242;
    goto v0042;

v0138:
    v0242 = qvalue(elt(env, 2)); /* nil */
    goto v0142;

v0246:
    v0242 = stack[-3];
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    v0243 = qcdr(v0242);
    v0242 = stack[-2];
    v0242 = qcar(v0242);
    v0242 = qcar(v0242);
    v0242 = qcdr(v0242);
    v0242 = ((intptr_t)v0243 > (intptr_t)v0242) ? lisp_true : nil;
    goto v0216;

v0154:
    stack[-4] = stack[0];
    v0242 = stack[-3];
    v0242 = qcar(v0242);
    stack[-1] = qcar(v0242);
    v0242 = stack[-3];
    v0242 = qcar(v0242);
    v0243 = qcdr(v0242);
    v0242 = stack[-2];
    v0242 = qcar(v0242);
    v0242 = qcdr(v0242);
    stack[0] = CC_generalKplusKmodKp(env, v0243, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-5];
    v0242 = stack[-3];
    v0243 = qcdr(v0242);
    v0242 = stack[-2];
    v0242 = qcdr(v0242);
    v0242 = CC_generalKplusKmodKp(env, v0243, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-5];
    fn = elt(env, 7); /* adjoin!-term */
    v0242 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0242);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-5];
    {
        Lisp_Object v0168 = stack[-4];
        popv(6);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0168, v0242);
    }

v0047:
    v0242 = qvalue(elt(env, 1)); /* t */
    goto v0046;

v0027:
    v0242 = qvalue(elt(env, 1)); /* t */
    goto v0024;

v0058:
    v0243 = stack[0];
    v0242 = stack[-3];
    {
        popv(6);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0243, v0242);
    }

v0033:
    v0243 = stack[0];
    v0242 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0243, v0242);
    }
/* error exit handlers */
v0244:
    popv(6);
    return nil;
}



/* Code for ordpa */

static Lisp_Object CC_ordpa(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0098, v0205, v0157, v0156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordpa");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0205 = v0014;
    v0157 = v0000;
/* end of prologue */

v0005:
    v0098 = v0157;
    if (v0098 == nil) goto v0037;
    v0098 = v0205;
    if (v0098 == nil) goto v0033;
    v0098 = v0157;
    v0098 = Lsimple_vectorp(nil, v0098);
    env = stack[0];
    if (v0098 == nil) goto v0078;
    v0098 = v0205;
    v0098 = Lsimple_vectorp(nil, v0098);
    env = stack[0];
    if (v0098 == nil) goto v0027;
    v0098 = v0157;
    {
        popv(1);
        fn = elt(env, 3); /* ordpv */
        return (*qfn2(fn))(qenv(fn), v0098, v0205);
    }

v0027:
    v0098 = v0205;
    v0098 = (consp(v0098) ? nil : lisp_true);
    { popv(1); return onevalue(v0098); }

v0078:
    v0098 = v0157;
    if (!consp(v0098)) goto v0026;
    v0098 = v0205;
    if (!consp(v0098)) goto v0178;
    v0098 = v0157;
    v0156 = qcar(v0098);
    v0098 = v0205;
    v0098 = qcar(v0098);
    if (equal(v0156, v0098)) goto v0046;
    v0098 = v0157;
    v0098 = qcar(v0098);
    v0157 = v0098;
    v0098 = v0205;
    v0098 = qcar(v0098);
    v0205 = v0098;
    goto v0005;

v0046:
    v0098 = v0157;
    v0098 = qcdr(v0098);
    v0157 = v0098;
    v0098 = v0205;
    v0098 = qcdr(v0098);
    v0205 = v0098;
    goto v0005;

v0178:
    v0098 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v0098); }

v0026:
    v0098 = v0205;
    if (!consp(v0098)) goto v0093;
    v0098 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0098); }

v0093:
    v0098 = v0157;
    if (is_number(v0098)) goto v0094;
    v0098 = v0205;
    if (symbolp(v0098)) goto v0104;
    v0098 = v0205;
    v0098 = (is_number(v0098) ? lisp_true : nil);
    { popv(1); return onevalue(v0098); }

v0104:
    v0098 = v0157;
        popv(1);
        return Lorderp(nil, v0098, v0205);

v0094:
    v0098 = v0205;
    if (is_number(v0098)) goto v0187;
    v0098 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0098); }

v0187:
    v0098 = v0157;
    v0098 = (Lisp_Object)lessp2(v0098, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    v0098 = v0098 ? lisp_true : nil;
    v0098 = (v0098 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v0098); }

v0033:
    v0098 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v0098); }

v0037:
    v0098 = v0205;
    v0098 = (v0098 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v0098); }
/* error exit handlers */
v0065:
    popv(1);
    return nil;
}



/* Code for pasf_deci */

static Lisp_Object CC_pasf_deci(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0038, v0039;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_deci");
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
    v0091 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* pasf_dec */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    errexit();
    v0039 = v0091;
    v0091 = v0039;
    v0038 = qcar(v0091);
    v0091 = v0039;
    v0091 = qcdr(v0091);
    if (v0091 == nil) goto v0017;
    v0091 = v0039;
    v0091 = qcdr(v0091);
    goto v0007;

v0007:
    return cons(v0038, v0091);

v0017:
    v0091 = (Lisp_Object)1; /* 0 */
    goto v0007;
}



/* Code for ratpoly_ldeg */

static Lisp_Object CC_ratpoly_ldeg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_ldeg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0005 = v0000;
/* end of prologue */
    v0005 = qcar(v0005);
    {
        fn = elt(env, 1); /* numpoly_ldeg */
        return (*qfn1(fn))(qenv(fn), v0005);
    }
}



/* Code for c!:extmult */

static Lisp_Object CC_cTextmult(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0195, v0248;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:extmult");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0014;
    stack[-2] = v0000;
/* end of prologue */
    v0195 = stack[-2];
    if (v0195 == nil) goto v0008;
    v0195 = stack[-1];
    v0195 = (v0195 == nil ? lisp_true : nil);
    goto v0037;

v0037:
    if (v0195 == nil) goto v0018;
    v0195 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v0195); }

v0018:
    v0248 = stack[-1];
    v0195 = (Lisp_Object)17; /* 1 */
    if (v0248 == v0195) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0195 = stack[-2];
    v0195 = qcar(v0195);
    v0195 = qcar(v0195);
    v0248 = qcar(v0195);
    v0195 = stack[-1];
    v0195 = qcar(v0195);
    v0195 = qcar(v0195);
    fn = elt(env, 3); /* c!:ordexn */
    v0195 = (*qfn2(fn))(qenv(fn), v0248, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    v0248 = v0195;
    v0195 = v0248;
    if (v0195 == nil) goto v0080;
    v0195 = v0248;
    stack[0] = qcdr(v0195);
    v0195 = v0248;
    v0195 = qcar(v0195);
    if (v0195 == nil) goto v0158;
    v0195 = stack[-2];
    v0195 = qcar(v0195);
    v0248 = qcdr(v0195);
    v0195 = stack[-1];
    v0195 = qcar(v0195);
    v0195 = qcdr(v0195);
    fn = elt(env, 4); /* c!:subs2multf */
    v0195 = (*qfn2(fn))(qenv(fn), v0248, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    fn = elt(env, 5); /* negf */
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    goto v0088;

v0088:
    v0195 = cons(stack[0], v0195);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    stack[-3] = ncons(v0195);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    v0195 = stack[-2];
    v0195 = qcar(v0195);
    v0248 = ncons(v0195);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    v0195 = stack[-1];
    v0195 = qcdr(v0195);
    stack[0] = CC_cTextmult(env, v0248, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    v0195 = stack[-2];
    v0248 = qcdr(v0195);
    v0195 = stack[-1];
    v0195 = CC_cTextmult(env, v0248, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    fn = elt(env, 6); /* c!:extadd */
    v0195 = (*qfn2(fn))(qenv(fn), stack[0], v0195);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    {
        Lisp_Object v0249 = stack[-3];
        popv(5);
        fn = elt(env, 6); /* c!:extadd */
        return (*qfn2(fn))(qenv(fn), v0249, v0195);
    }

v0158:
    v0195 = stack[-2];
    v0195 = qcar(v0195);
    v0248 = qcdr(v0195);
    v0195 = stack[-1];
    v0195 = qcar(v0195);
    v0195 = qcdr(v0195);
    fn = elt(env, 4); /* c!:subs2multf */
    v0195 = (*qfn2(fn))(qenv(fn), v0248, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    goto v0088;

v0080:
    v0195 = stack[-2];
    v0195 = qcar(v0195);
    v0248 = ncons(v0195);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    v0195 = stack[-1];
    v0195 = qcdr(v0195);
    stack[0] = CC_cTextmult(env, v0248, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    v0195 = stack[-2];
    v0248 = qcdr(v0195);
    v0195 = stack[-1];
    v0195 = CC_cTextmult(env, v0248, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    {
        Lisp_Object v0152 = stack[0];
        popv(5);
        fn = elt(env, 6); /* c!:extadd */
        return (*qfn2(fn))(qenv(fn), v0152, v0195);
    }

v0008:
    v0195 = qvalue(elt(env, 1)); /* t */
    goto v0037;
/* error exit handlers */
v0151:
    popv(5);
    return nil;
}



/* Code for addpf */

static Lisp_Object CC_addpf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0251, v0141, v0176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addpf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0014;
    stack[-2] = v0000;
/* end of prologue */
    stack[0] = nil;
    goto v0042;

v0042:
    v0251 = stack[-2];
    if (v0251 == nil) goto v0033;
    v0251 = stack[-1];
    if (v0251 == nil) goto v0058;
    v0251 = stack[-2];
    v0251 = qcar(v0251);
    v0141 = qcar(v0251);
    v0251 = (Lisp_Object)17; /* 1 */
    if (v0141 == v0251) goto v0003;
    v0251 = stack[-1];
    v0251 = qcar(v0251);
    v0141 = qcar(v0251);
    v0251 = (Lisp_Object)17; /* 1 */
    if (v0141 == v0251) goto v0045;
    v0251 = stack[-2];
    v0251 = qcar(v0251);
    v0141 = qcar(v0251);
    v0251 = stack[-1];
    v0251 = qcar(v0251);
    v0251 = qcar(v0251);
    if (equal(v0141, v0251)) goto v0071;
    v0251 = stack[-2];
    v0251 = qcar(v0251);
    v0141 = qcar(v0251);
    v0251 = stack[-1];
    v0251 = qcar(v0251);
    v0251 = qcar(v0251);
    fn = elt(env, 1); /* ordop */
    v0251 = (*qfn2(fn))(qenv(fn), v0141, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-4];
    if (v0251 == nil) goto v0147;
    v0251 = stack[-2];
    v0141 = qcar(v0251);
    v0251 = stack[0];
    v0251 = cons(v0141, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-4];
    stack[0] = v0251;
    v0251 = stack[-2];
    v0251 = qcdr(v0251);
    stack[-2] = v0251;
    goto v0042;

v0147:
    v0251 = stack[-1];
    v0141 = qcar(v0251);
    v0251 = stack[0];
    v0251 = cons(v0141, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-4];
    stack[0] = v0251;
    v0251 = stack[-1];
    v0251 = qcdr(v0251);
    stack[-1] = v0251;
    goto v0042;

v0071:
    stack[-3] = stack[0];
    v0251 = stack[-2];
    v0251 = qcar(v0251);
    v0141 = qcdr(v0251);
    v0251 = stack[-1];
    v0251 = qcar(v0251);
    v0251 = qcdr(v0251);
    fn = elt(env, 2); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v0141, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-4];
    v0251 = stack[-2];
    v0141 = qcdr(v0251);
    v0251 = stack[-1];
    v0251 = qcdr(v0251);
    v0251 = CC_addpf(env, v0141, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-4];
    v0141 = stack[0];
    v0176 = v0141;
    v0176 = qcar(v0176);
    if (v0176 == nil) goto v0099;
    v0176 = stack[-2];
    v0176 = qcar(v0176);
    v0176 = qcar(v0176);
    v0251 = acons(v0176, v0141, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-4];
    goto v0099;

v0099:
    {
        Lisp_Object v0253 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0253, v0251);
    }

v0045:
    v0141 = stack[-1];
    v0251 = stack[-2];
    fn = elt(env, 4); /* addmpf */
    v0251 = (*qfn2(fn))(qenv(fn), v0141, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-4];
    {
        Lisp_Object v0254 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0254, v0251);
    }

v0003:
    v0141 = stack[-2];
    v0251 = stack[-1];
    fn = elt(env, 4); /* addmpf */
    v0251 = (*qfn2(fn))(qenv(fn), v0141, v0251);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-4];
    {
        Lisp_Object v0144 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0144, v0251);
    }

v0058:
    v0141 = stack[0];
    v0251 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0141, v0251);
    }

v0033:
    v0141 = stack[0];
    v0251 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0141, v0251);
    }
/* error exit handlers */
v0252:
    popv(5);
    return nil;
}



/* Code for condterpri */

static Lisp_Object MS_CDECL CC_condterpri(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0187;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "condterpri");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for condterpri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0187 = qvalue(elt(env, 1)); /* !*output */
    if (v0187 == nil) goto v0036;
    v0187 = qvalue(elt(env, 3)); /* !*echo */
    if (v0187 == nil) goto v0007;
    v0187 = qvalue(elt(env, 4)); /* !*extraecho */
    if (v0187 == nil) goto v0015;
    v0187 = qvalue(elt(env, 5)); /* !*int */
    if (v0187 == nil) goto v0054;
    v0187 = qvalue(elt(env, 7)); /* ifl!* */
    goto v0077;

v0077:
    if (v0187 == nil) goto v0038;
    v0187 = qvalue(elt(env, 8)); /* !*defn */
    if (v0187 == nil) goto v0030;
    v0187 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0187);

v0030:
    v0187 = qvalue(elt(env, 9)); /* !*demo */
    if (v0187 == nil) goto v0060;
    v0187 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0187);

v0060:
        return Lterpri(nil, 0);

v0038:
    v0187 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0187);

v0054:
    v0187 = qvalue(elt(env, 6)); /* t */
    goto v0077;

v0015:
    v0187 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0187);

v0007:
    v0187 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0187);

v0036:
    v0187 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0187);
}



/* Code for red!-ratios2 */

static Lisp_Object MS_CDECL CC_redKratios2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0014,
                         Lisp_Object v0001, Lisp_Object v0036, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068, v0202, v0089, v0098;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "red-ratios2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-ratios2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0036,v0001,v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0014,v0001,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0036;
    stack[-2] = v0001;
    stack[-3] = v0014;
    stack[-4] = v0000;
/* end of prologue */

v0197:
    v0068 = stack[-4];
    if (v0068 == nil) goto v0007;
    v0202 = stack[-2];
    v0068 = stack[-3];
    v0068 = qcar(v0068);
    stack[0] = times2(v0202, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-6];
    stack[-5] = stack[0];
    v0202 = stack[-1];
    v0068 = stack[-4];
    v0068 = qcar(v0068);
    v0068 = times2(v0202, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-6];
    if (equal(stack[0], v0068)) goto v0060;
    v0068 = qvalue(elt(env, 1)); /* nil */
    goto v0078;

v0078:
    if (v0068 == nil) goto v0056;
    v0202 = stack[-1];
    v0068 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* red!-lowest!-terms */
        return (*qfn2(fn))(qenv(fn), v0202, v0068);
    }

v0056:
    v0068 = stack[-4];
    v0098 = qcdr(v0068);
    v0068 = stack[-3];
    v0089 = qcdr(v0068);
    v0202 = stack[-2];
    v0068 = stack[-1];
    stack[-4] = v0098;
    stack[-3] = v0089;
    stack[-2] = v0202;
    stack[-1] = v0068;
    goto v0197;

v0060:
    v0202 = stack[-5];
    v0068 = (Lisp_Object)1; /* 0 */
    if (v0202 == v0068) goto v0043;
    v0202 = stack[-1];
    v0068 = stack[-2];
    v0202 = Lgcd(nil, v0202, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-6];
    v0068 = stack[-1];
    v0202 = Cremainder(v0202, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-6];
    v0068 = (Lisp_Object)1; /* 0 */
    v0068 = (v0202 == v0068 ? lisp_true : nil);
    goto v0078;

v0043:
    v0068 = qvalue(elt(env, 1)); /* nil */
    goto v0078;

v0007:
    v0068 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0068); }
/* error exit handlers */
v0203:
    popv(7);
    return nil;
}



/* Code for adddummy1a */

static Lisp_Object MS_CDECL CC_adddummy1a(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0014,
                         Lisp_Object v0001, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0207, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "adddummy1a");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for adddummy1a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0001,v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0014,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    v0207 = v0014;
    stack[-2] = v0000;
/* end of prologue */

v0012:
    v0028 = v0207;
    if (v0028 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0028 = v0207;
    v0028 = qcdr(v0028);
    stack[-3] = v0028;
    v0028 = stack[-1];
    if (v0028 == nil) goto v0091;
    v0028 = stack[-1];
    v0028 = qcar(v0028);
    stack[0] = v0028;
    goto v0041;

v0041:
    v0028 = qcar(v0207);
    v0207 = stack[-2];
    v0207 = qcdr(v0207);
    fn = elt(env, 1); /* pappl_pv */
    v0028 = (*qfn2(fn))(qenv(fn), v0028, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-4];
    v0207 = stack[-1];
    if (v0207 == nil) goto v0011;
    v0207 = stack[-1];
    v0207 = qcdr(v0207);
    goto v0026;

v0026:
    fn = elt(env, 2); /* insert_pv */
    v0207 = (*qfn2(fn))(qenv(fn), v0028, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-4];
    v0207 = cons(stack[0], v0207);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[-4];
    stack[-1] = v0207;
    v0207 = stack[-3];
    goto v0012;

v0011:
    v0207 = stack[-1];
    goto v0026;

v0091:
    v0028 = stack[-2];
    v0028 = qcar(v0028);
    stack[0] = v0028;
    goto v0041;
/* error exit handlers */
v0181:
    popv(5);
    return nil;
}



/* Code for ordn */

static Lisp_Object CC_ordn(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordn");
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
    v0030 = v0000;
/* end of prologue */
    v0041 = v0030;
    if (v0041 == nil) goto v0013;
    v0041 = v0030;
    v0041 = qcdr(v0041);
    if (v0041 == nil) { popv(2); return onevalue(v0030); }
    v0041 = v0030;
    v0041 = qcdr(v0041);
    v0041 = qcdr(v0041);
    if (v0041 == nil) goto v0015;
    v0041 = v0030;
    stack[0] = qcar(v0041);
    v0041 = v0030;
    v0041 = qcdr(v0041);
    v0041 = CC_ordn(env, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-1];
    {
        Lisp_Object v0053 = stack[0];
        popv(2);
        fn = elt(env, 2); /* ordad */
        return (*qfn2(fn))(qenv(fn), v0053, v0041);
    }

v0015:
    v0041 = v0030;
    v0041 = qcar(v0041);
    v0030 = qcdr(v0030);
    v0030 = qcar(v0030);
    {
        popv(2);
        fn = elt(env, 3); /* ord2 */
        return (*qfn2(fn))(qenv(fn), v0041, v0030);
    }

v0013:
    v0041 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0041); }
/* error exit handlers */
v0052:
    popv(2);
    return nil;
}



/* Code for gionep!: */

static Lisp_Object CC_gionepT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039, v0021, v0077;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gionep:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0077 = v0000;
/* end of prologue */
    v0039 = v0077;
    v0039 = qcdr(v0039);
    v0021 = qcar(v0039);
    v0039 = (Lisp_Object)17; /* 1 */
    if (v0021 == v0039) goto v0016;
    v0039 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0039);

v0016:
    v0039 = v0077;
    v0039 = qcdr(v0039);
    v0021 = qcdr(v0039);
    v0039 = (Lisp_Object)1; /* 0 */
    v0039 = (v0021 == v0039 ? lisp_true : nil);
    return onevalue(v0039);
}



/* Code for rmplus */

static Lisp_Object CC_rmplus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0019, v0009;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rmplus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0019 = v0000;
/* end of prologue */
    v0018 = v0019;
    v0009 = elt(env, 1); /* plus */
    if (!consp(v0018)) goto v0035;
    v0018 = qcar(v0018);
    if (!(v0018 == v0009)) goto v0035;
    v0018 = v0019;
    v0018 = qcdr(v0018);
    return onevalue(v0018);

v0035:
    v0018 = v0019;
    return ncons(v0018);
}



/* Code for diffp1 */

static Lisp_Object CC_diffp1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0051, v0187;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diffp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0050 = v0014;
    v0187 = v0000;
/* end of prologue */
    v0051 = v0187;
    v0051 = qcar(v0051);
    if (v0051 == v0050) goto v0078;
    v0050 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0050); }

v0078:
    v0050 = v0187;
    v0051 = qcdr(v0050);
    v0050 = (Lisp_Object)17; /* 1 */
    if (v0051 == v0050) goto v0035;
    v0050 = v0187;
    stack[-1] = qcdr(v0050);
    v0050 = v0187;
    stack[0] = qcar(v0050);
    v0050 = v0187;
    v0050 = qcdr(v0050);
    v0050 = sub1(v0050);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-2];
    fn = elt(env, 2); /* to */
    v0051 = (*qfn2(fn))(qenv(fn), stack[0], v0050);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-2];
    v0050 = (Lisp_Object)17; /* 1 */
    v0050 = cons(v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-2];
    v0050 = ncons(v0050);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-2];
    {
        Lisp_Object v0207 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* multd */
        return (*qfn2(fn))(qenv(fn), v0207, v0050);
    }

v0035:
    v0050 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0050); }
/* error exit handlers */
v0177:
    popv(3);
    return nil;
}



/* Code for wuorderp */

static Lisp_Object CC_wuorderp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0065, v0066, v0198, v0203, v0102, v0100;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wuorderp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0102 = v0014;
    v0100 = v0000;
/* end of prologue */
    v0198 = nil;
    v0066 = v0100;
    v0065 = v0102;
    if (v0066 == v0065) goto v0008;
    v0065 = qvalue(elt(env, 2)); /* wukord!* */
    v0203 = v0065;
    goto v0009;

v0009:
    v0065 = v0203;
    if (v0065 == nil) goto v0019;
    v0065 = v0198;
    if (!(v0065 == nil)) goto v0019;
    v0066 = v0100;
    v0065 = v0203;
    v0065 = qcar(v0065);
    if (v0066 == v0065) goto v0060;
    v0066 = v0102;
    v0065 = v0203;
    v0065 = qcar(v0065);
    if (v0066 == v0065) goto v0103;
    v0065 = v0203;
    v0065 = qcdr(v0065);
    v0203 = v0065;
    goto v0009;

v0103:
    v0066 = v0100;
    v0065 = v0203;
    v0065 = qcdr(v0065);
    v0065 = Lmemq(nil, v0066, v0065);
    if (v0065 == nil) goto v0044;
    v0065 = elt(env, 4); /* no */
    goto v0087;

v0087:
    v0198 = v0065;
    goto v0009;

v0044:
    v0065 = elt(env, 3); /* yes */
    goto v0087;

v0060:
    v0066 = v0102;
    v0065 = v0203;
    v0065 = qcdr(v0065);
    v0065 = Lmemq(nil, v0066, v0065);
    if (v0065 == nil) goto v0187;
    v0065 = elt(env, 3); /* yes */
    goto v0052;

v0052:
    v0198 = v0065;
    goto v0009;

v0187:
    v0065 = elt(env, 4); /* no */
    goto v0052;

v0019:
    v0065 = v0198;
    if (v0065 == nil) goto v0067;
    v0065 = v0198;
    v0066 = elt(env, 3); /* yes */
    v0065 = (v0065 == v0066 ? lisp_true : nil);
    return onevalue(v0065);

v0067:
    v0065 = v0100;
    v0066 = v0102;
    v0065 = Lorderp(nil, v0065, v0066);
    errexit();
    v0065 = (v0065 == nil ? lisp_true : nil);
    return onevalue(v0065);

v0008:
    v0065 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0065);
}



/* Code for comfac */

static Lisp_Object CC_comfac(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0255, v0240;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comfac");
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
    stack[-3] = nil;
    v0255 = qvalue(elt(env, 1)); /* dmode!* */
    if (!symbolp(v0255)) v0255 = nil;
    else { v0255 = qfastgets(v0255);
           if (v0255 != nil) { v0255 = elt(v0255, 3); /* field */
#ifdef RECORD_GET
             if (v0255 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0255 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0255 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0255 == SPID_NOPROP) v0255 = nil; else v0255 = lisp_true; }}
#endif
    if (v0255 == nil) goto v0091;
    v0255 = stack[-2];
    fn = elt(env, 4); /* lnc */
    v0240 = (*qfn1(fn))(qenv(fn), v0255);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-4];
    stack[-3] = v0240;
    v0255 = (Lisp_Object)17; /* 1 */
    v0255 = Lneq(nil, v0240, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-4];
    goto v0006;

v0006:
    if (v0255 == nil) goto v0037;
    v0255 = stack[-3];
    fn = elt(env, 5); /* !:recip */
    v0240 = (*qfn1(fn))(qenv(fn), v0255);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-4];
    v0255 = stack[-2];
    fn = elt(env, 6); /* multd */
    v0255 = (*qfn2(fn))(qenv(fn), v0240, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-4];
    stack[-2] = v0255;
    goto v0037;

v0037:
    v0255 = stack[-2];
    v0255 = qcdr(v0255);
    if (v0255 == nil) goto v0057;
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = qcdr(v0255);
    stack[-3] = v0255;
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    stack[-1] = v0255;
    goto v0042;

v0042:
    v0255 = stack[-2];
    v0255 = qcdr(v0255);
    stack[-2] = v0255;
    v0240 = stack[-2];
    v0255 = stack[-1];
    fn = elt(env, 7); /* degr */
    v0240 = (*qfn2(fn))(qenv(fn), v0240, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-4];
    v0255 = (Lisp_Object)1; /* 0 */
    if (v0240 == v0255) goto v0105;
    v0255 = stack[-2];
    v0255 = qcdr(v0255);
    if (v0255 == nil) goto v0081;
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0240 = qcdr(v0255);
    v0255 = stack[-3];
    fn = elt(env, 8); /* gcdf */
    v0255 = (*qfn2(fn))(qenv(fn), v0240, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-4];
    stack[-3] = v0255;
    goto v0042;

v0081:
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    stack[0] = qcar(v0255);
    v0240 = stack[-3];
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = qcdr(v0255);
    fn = elt(env, 8); /* gcdf */
    v0255 = (*qfn2(fn))(qenv(fn), v0240, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    {
        Lisp_Object v0217 = stack[0];
        popv(5);
        return cons(v0217, v0255);
    }

v0105:
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v0255 = stack[-2];
    if (!consp(v0255)) goto v0199;
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = (consp(v0255) ? nil : lisp_true);
    goto v0206;

v0206:
    if (v0255 == nil) goto v0099;
    v0255 = qvalue(elt(env, 3)); /* t */
    goto v0044;

v0044:
    if (v0255 == nil) goto v0153;
    v0240 = stack[-3];
    v0255 = stack[-2];
    fn = elt(env, 8); /* gcdf */
    v0255 = (*qfn2(fn))(qenv(fn), v0240, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    goto v0043;

v0043:
    {
        Lisp_Object v0218 = stack[0];
        popv(5);
        return cons(v0218, v0255);
    }

v0153:
    v0255 = (Lisp_Object)17; /* 1 */
    goto v0043;

v0099:
    v0255 = stack[-1];
    fn = elt(env, 9); /* noncomp */
    v0255 = (*qfn1(fn))(qenv(fn), v0255);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-4];
    if (v0255 == nil) goto v0182;
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    v0255 = qcar(v0255);
    fn = elt(env, 9); /* noncomp */
    v0255 = (*qfn1(fn))(qenv(fn), v0255);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-4];
    goto v0086;

v0086:
    v0255 = (v0255 == nil ? lisp_true : nil);
    goto v0044;

v0182:
    v0255 = qvalue(elt(env, 2)); /* nil */
    goto v0086;

v0199:
    v0255 = qvalue(elt(env, 3)); /* t */
    goto v0206;

v0057:
    v0255 = stack[-2];
    v0255 = qcar(v0255);
    { popv(5); return onevalue(v0255); }

v0091:
    v0255 = qvalue(elt(env, 2)); /* nil */
    goto v0006;
/* error exit handlers */
v0216:
    popv(5);
    return nil;
}



/* Code for ibalp_litlp */

static Lisp_Object CC_ibalp_litlp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_litlp");
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

v0197:
    v0020 = stack[0];
    if (v0020 == nil) goto v0013;
    v0020 = stack[0];
    v0020 = qcar(v0020);
    fn = elt(env, 3); /* ibalp_litp */
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-1];
    if (v0020 == nil) goto v0006;
    v0020 = stack[0];
    v0020 = qcdr(v0020);
    stack[0] = v0020;
    goto v0197;

v0006:
    v0020 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0020); }

v0013:
    v0020 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0020); }
/* error exit handlers */
v0095:
    popv(2);
    return nil;
}



/* Code for objectom */

static Lisp_Object CC_objectom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0180, v0060;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for objectom");
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
    v0180 = v0000;
/* end of prologue */
    v0053 = v0180;
    v0053 = Lconsp(nil, v0053);
    env = stack[-1];
    if (v0053 == nil) goto v0041;
    v0053 = v0180;
    v0060 = qcar(v0053);
    v0053 = qvalue(elt(env, 1)); /* ir2mml!* */
    v0053 = Lassoc(nil, v0060, v0053);
    v0060 = v0053;
    if (v0053 == nil) goto v0092;
    v0053 = v0060;
    v0053 = qcdr(v0053);
    v0053 = qcdr(v0053);
    v0053 = qcdr(v0053);
    stack[0] = qcar(v0053);
    v0053 = v0180;
    v0053 = ncons(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-1];
    fn = elt(env, 3); /* apply */
    v0053 = (*qfn2(fn))(qenv(fn), stack[0], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    goto v0042;

v0042:
    v0053 = nil;
    { popv(2); return onevalue(v0053); }

v0092:
    v0053 = v0180;
    fn = elt(env, 4); /* fnom */
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    goto v0042;

v0041:
    v0053 = v0180;
    fn = elt(env, 5); /* basicom */
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    goto v0042;
/* error exit handlers */
v0003:
    popv(2);
    return nil;
}



/* Code for zeropp */

static Lisp_Object CC_zeropp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0095, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zeropp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0091 = v0000;
/* end of prologue */
    v0058 = v0091;
    if (!consp(v0058)) goto v0013;
    v0058 = v0091;
    v0095 = qcar(v0058);
    v0058 = elt(env, 1); /* !:rd!: */
    if (v0095 == v0058) goto v0008;
    v0058 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0058);

v0008:
    v0058 = v0091;
    {
        fn = elt(env, 3); /* rd!:zerop */
        return (*qfn1(fn))(qenv(fn), v0058);
    }

v0013:
    v0058 = v0091;
        return Lzerop(nil, v0058);
}



/* Code for dim!<deg */

static Lisp_Object CC_dimRdeg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039, v0021;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dim<deg");
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
    v0039 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dimex!* */
    fn = elt(env, 4); /* deg!*farg */
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-1];
    fn = elt(env, 5); /* negf */
    v0039 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-1];
    fn = elt(env, 6); /* addf */
    v0039 = (*qfn2(fn))(qenv(fn), stack[0], v0039);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-1];
    v0021 = v0039;
    v0039 = v0021;
    if (!(is_number(v0039))) goto v0095;
    v0039 = v0021;
    v0039 = Lminusp(nil, v0039);
    env = stack[-1];
    if (v0039 == nil) goto v0095;
    v0039 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v0039); }

v0095:
    v0039 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v0039); }
/* error exit handlers */
v0054:
    popv(2);
    return nil;
}



/* Code for sroad */

static Lisp_Object MS_CDECL CC_sroad(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0014,
                         Lisp_Object v0001, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0184, v0076, v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sroad");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sroad");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0001,v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0014,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0014;
    stack[-2] = v0000;
/* end of prologue */
    v0050 = nil;
    goto v0012;

v0012:
    v0184 = stack[0];
    if (v0184 == nil) goto v0002;
    v0076 = stack[-2];
    v0184 = stack[0];
    v0184 = qcar(v0184);
    if (equal(v0076, v0184)) goto v0091;
    v0184 = stack[0];
    v0184 = qcar(v0184);
    v0076 = v0050;
    v0184 = cons(v0184, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    v0050 = v0184;
    v0184 = stack[0];
    v0184 = qcdr(v0184);
    stack[0] = v0184;
    goto v0012;

v0091:
    stack[-2] = v0050;
    v0076 = stack[-1];
    v0184 = stack[0];
    v0184 = qcdr(v0184);
    v0184 = Lappend(nil, v0076, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    {
        Lisp_Object v0177 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0177, v0184);
    }

v0002:
    v0184 = v0050;
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0184);
    }
/* error exit handlers */
v0088:
    popv(4);
    return nil;
}



/* Code for lpri */

static Lisp_Object CC_lpri(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0078;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lpri");
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

v0013:
    v0078 = stack[0];
    if (v0078 == nil) goto v0012;
    v0078 = stack[0];
    v0078 = qcar(v0078);
    v0078 = Lprinc(nil, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-1];
    v0078 = elt(env, 2); /* " " */
    v0078 = Lprinc(nil, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-1];
    v0078 = stack[0];
    v0078 = qcdr(v0078);
    stack[0] = v0078;
    goto v0013;

v0012:
    v0078 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0078); }
/* error exit handlers */
v0018:
    popv(2);
    return nil;
}



/* Code for mo_diff */

static Lisp_Object CC_mo_diff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_diff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0006 = v0014;
    v0033 = v0000;
/* end of prologue */
    stack[0] = v0033;
    fn = elt(env, 1); /* mo_neg */
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    {
        Lisp_Object v0035 = stack[0];
        popv(2);
        fn = elt(env, 2); /* mo_sum */
        return (*qfn2(fn))(qenv(fn), v0035, v0006);
    }
/* error exit handlers */
v0016:
    popv(2);
    return nil;
}



setup_type const u07_setup[] =
{
    {"noncomp2f",               CC_noncomp2f,   too_many_1,    wrong_no_1},
    {"rread",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_rread},
    {"mv-pow-mv-term-+",        too_few_2,      CC_mvKpowKmvKtermKL,wrong_no_2},
    {"rnquotient:",             too_few_2,      CC_rnquotientT,wrong_no_2},
    {"oprin",                   CC_oprin,       too_many_1,    wrong_no_1},
    {"gintequiv:",              CC_gintequivT,  too_many_1,    wrong_no_1},
    {"prepsq*2",                CC_prepsqH2,    too_many_1,    wrong_no_1},
    {"ofsf_smwcpknowl",         CC_ofsf_smwcpknowl,too_many_1, wrong_no_1},
    {"ibalp_mk2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ibalp_mk2},
    {"ctx_new",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_ctx_new},
    {"mintype",                 CC_mintype,     too_many_1,    wrong_no_1},
    {"comm_kernels",            CC_comm_kernels,too_many_1,    wrong_no_1},
    {"bcone?",                  CC_bconeW,      too_many_1,    wrong_no_1},
    {"layout-formula",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_layoutKformula},
    {"convertmode1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_convertmode1},
    {"simpdiff",                CC_simpdiff,    too_many_1,    wrong_no_1},
    {"bas_make1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_bas_make1},
    {"sc_kern",                 CC_sc_kern,     too_many_1,    wrong_no_1},
    {"general-modular-quotient",too_few_2,      CC_generalKmodularKquotient,wrong_no_2},
    {"reduce-mod-p",            CC_reduceKmodKp,too_many_1,    wrong_no_1},
    {"outdefr",                 too_few_2,      CC_outdefr,    wrong_no_2},
    {"polynomclone",            CC_polynomclone,too_many_1,    wrong_no_1},
    {"totallessp",              too_few_2,      CC_totallessp, wrong_no_2},
    {"mcharg2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg2},
    {"preptayexp",              CC_preptayexp,  too_many_1,    wrong_no_1},
    {"symbol",                  CC_symbol,      too_many_1,    wrong_no_1},
    {"cl_susiminlevel",         too_few_2,      CC_cl_susiminlevel,wrong_no_2},
    {"ibalp_varlt1",            too_few_2,      CC_ibalp_varlt1,wrong_no_2},
    {"multiom",                 CC_multiom,     too_many_1,    wrong_no_1},
    {"minusp:",                 CC_minuspT,     too_many_1,    wrong_no_1},
    {"letmtr3",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_letmtr3},
    {"symtabget",               too_few_2,      CC_symtabget,  wrong_no_2},
    {"vdpgetprop",              too_few_2,      CC_vdpgetprop, wrong_no_2},
    {"csl_timbf",               too_few_2,      CC_csl_timbf,  wrong_no_2},
    {"putpline",                CC_putpline,    too_many_1,    wrong_no_1},
    {"quotfd",                  too_few_2,      CC_quotfd,     wrong_no_2},
    {"lprim",                   CC_lprim,       too_many_1,    wrong_no_1},
    {"errorset2",               CC_errorset2,   too_many_1,    wrong_no_1},
    {"gperm2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm2},
    {"carx",                    too_few_2,      CC_carx,       wrong_no_2},
    {"procstat",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_procstat},
    {"ofsf_posvarpat",          too_few_2,      CC_ofsf_posvarpat,wrong_no_2},
    {"polynomadd",              too_few_2,      CC_polynomadd, wrong_no_2},
    {"lto_catsoc",              too_few_2,      CC_lto_catsoc, wrong_no_2},
    {"wulessp*",                too_few_2,      CC_wulesspH,   wrong_no_2},
    {"setdiff",                 too_few_2,      CC_setdiff,    wrong_no_2},
    {"qqe_number-of-tails-in-qterm",CC_qqe_numberKofKtailsKinKqterm,too_many_1,wrong_no_1},
    {"pasf_susitf",             too_few_2,      CC_pasf_susitf,wrong_no_2},
    {"ibalp_istotal",           CC_ibalp_istotal,too_many_1,   wrong_no_1},
    {"quotient-mod-p",          too_few_2,      CC_quotientKmodKp,wrong_no_2},
    {"difff",                   too_few_2,      CC_difff,      wrong_no_2},
    {"retimes1",                CC_retimes1,    too_many_1,    wrong_no_1},
    {"groebcpcompless?",        too_few_2,      CC_groebcpcomplessW,wrong_no_2},
    {"evtdeg",                  CC_evtdeg,      too_many_1,    wrong_no_1},
    {"deg*farg",                CC_degHfarg,    too_many_1,    wrong_no_1},
    {"ncmpchk",                 too_few_2,      CC_ncmpchk,    wrong_no_2},
    {"ord",                     CC_ord,         too_many_1,    wrong_no_1},
    {"times-in-vector",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_timesKinKvector},
    {"general-plus-mod-p",      too_few_2,      CC_generalKplusKmodKp,wrong_no_2},
    {"ordpa",                   too_few_2,      CC_ordpa,      wrong_no_2},
    {"pasf_deci",               CC_pasf_deci,   too_many_1,    wrong_no_1},
    {"ratpoly_ldeg",            CC_ratpoly_ldeg,too_many_1,    wrong_no_1},
    {"c:extmult",               too_few_2,      CC_cTextmult,  wrong_no_2},
    {"addpf",                   too_few_2,      CC_addpf,      wrong_no_2},
    {"condterpri",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_condterpri},
    {"red-ratios2",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_redKratios2},
    {"adddummy1a",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_adddummy1a},
    {"ordn",                    CC_ordn,        too_many_1,    wrong_no_1},
    {"gionep:",                 CC_gionepT,     too_many_1,    wrong_no_1},
    {"rmplus",                  CC_rmplus,      too_many_1,    wrong_no_1},
    {"diffp1",                  too_few_2,      CC_diffp1,     wrong_no_2},
    {"wuorderp",                too_few_2,      CC_wuorderp,   wrong_no_2},
    {"comfac",                  CC_comfac,      too_many_1,    wrong_no_1},
    {"ibalp_litlp",             CC_ibalp_litlp, too_many_1,    wrong_no_1},
    {"objectom",                CC_objectom,    too_many_1,    wrong_no_1},
    {"zeropp",                  CC_zeropp,      too_many_1,    wrong_no_1},
    {"dim<deg",                 CC_dimRdeg,     too_many_1,    wrong_no_1},
    {"sroad",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_sroad},
    {"lpri",                    CC_lpri,        too_many_1,    wrong_no_1},
    {"mo_diff",                 too_few_2,      CC_mo_diff,    wrong_no_2},
    {NULL, (one_args *)"u07", (two_args *)"5296 2854163 6846800", 0}
};

/* end of generated code */
