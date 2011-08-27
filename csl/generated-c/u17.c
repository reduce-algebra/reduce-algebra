
/* $destdir\u17.c        Machine generated C code */

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


/* Code for prepsq!* */

static Lisp_Object CC_prepsqH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsq*");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v0;
/* end of prologue */
    stack[-8] = qvalue(elt(env, 1)); /* !*combinelogs */
    qvalue(elt(env, 1)) = nil; /* !*combinelogs */
    v58 = stack[-9];
    v58 = qcar(v58);
    if (v58 == nil) goto v61;
    v58 = qvalue(elt(env, 2)); /* ordl!* */
    fn = elt(env, 16); /* setkorder */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    stack[-10] = v58;
    v58 = qvalue(elt(env, 3)); /* factors!* */
    stack[-7] = v58;
    goto v63;

v63:
    v58 = stack[-7];
    if (v58 == nil) goto v64;
    v58 = stack[-7];
    v58 = qcar(v58);
    v59 = v58;
    v58 = v59;
    if (symbolp(v58)) goto v65;
    v58 = qvalue(elt(env, 4)); /* nil */
    goto v66;

v66:
    stack[-6] = v58;
    v58 = stack[-6];
    fn = elt(env, 17); /* lastpair */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    stack[-5] = v58;
    v58 = stack[-7];
    v58 = qcdr(v58);
    stack[-7] = v58;
    v58 = stack[-5];
    if (!consp(v58)) goto v63;
    else goto v67;

v67:
    v58 = stack[-7];
    if (v58 == nil) goto v68;
    stack[-4] = stack[-5];
    v58 = stack[-7];
    v58 = qcar(v58);
    v59 = v58;
    if (symbolp(v59)) goto v69;
    v58 = qvalue(elt(env, 4)); /* nil */
    goto v70;

v70:
    v58 = Lrplacd(nil, stack[-4], v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    v58 = stack[-5];
    fn = elt(env, 17); /* lastpair */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    stack[-5] = v58;
    v58 = stack[-7];
    v58 = qcdr(v58);
    stack[-7] = v58;
    goto v67;

v69:
    v60 = v58;
    v59 = elt(env, 5); /* prepsq!*fn */
    v59 = get(v60, v59);
    env = stack[-11];
    v60 = v59;
    if (v59 == nil) goto v71;
    v59 = stack[-9];
    v58 = Lapply2(nil, 3, v60, v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    goto v70;

v71:
    v59 = v58;
    v58 = elt(env, 6); /* klist */
    v58 = get(v59, v58);
    env = stack[-11];
    stack[-3] = v58;
    v58 = stack[-3];
    if (v58 == nil) goto v72;
    v58 = stack[-3];
    v58 = qcar(v58);
    v58 = qcar(v58);
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    stack[-1] = v58;
    stack[-2] = v58;
    goto v73;

v73:
    v58 = stack[-3];
    v58 = qcdr(v58);
    stack[-3] = v58;
    v58 = stack[-3];
    if (v58 == nil) goto v74;
    stack[0] = stack[-1];
    v58 = stack[-3];
    v58 = qcar(v58);
    v58 = qcar(v58);
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    v58 = Lrplacd(nil, stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    v58 = stack[-1];
    v58 = qcdr(v58);
    stack[-1] = v58;
    goto v73;

v74:
    v58 = stack[-2];
    goto v70;

v72:
    v58 = qvalue(elt(env, 4)); /* nil */
    goto v70;

v68:
    v58 = stack[-6];
    v59 = v58;
    goto v75;

v75:
    v58 = elt(env, 7); /* ordop */
    fn = elt(env, 18); /* sort */
    stack[0] = (*qfn2(fn))(qenv(fn), v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    v59 = qvalue(elt(env, 3)); /* factors!* */
    v58 = elt(env, 7); /* ordop */
    fn = elt(env, 18); /* sort */
    v59 = (*qfn2(fn))(qenv(fn), v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    v58 = qvalue(elt(env, 2)); /* ordl!* */
    v58 = Lappend(nil, v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    v58 = Lappend(nil, stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    fn = elt(env, 16); /* setkorder */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    v59 = qvalue(elt(env, 8)); /* kord!* */
    v58 = stack[-10];
    if (equal(v59, v58)) goto v76;
    v58 = qvalue(elt(env, 9)); /* t */
    goto v77;

v77:
    if (v58 == nil) goto v78;
    v58 = stack[-9];
    v58 = qcar(v58);
    fn = elt(env, 19); /* formop */
    stack[0] = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    v58 = stack[-9];
    v58 = qcdr(v58);
    fn = elt(env, 19); /* formop */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    v58 = cons(stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    stack[-9] = v58;
    goto v78;

v78:
    v58 = qvalue(elt(env, 11)); /* !*rat */
    if (!(v58 == nil)) goto v79;
    v58 = qvalue(elt(env, 12)); /* !*div */
    if (!(v58 == nil)) goto v79;
    v58 = qvalue(elt(env, 13)); /* upl!* */
    if (!(v58 == nil)) goto v79;
    v58 = qvalue(elt(env, 14)); /* dnl!* */
    if (!(v58 == nil)) goto v79;
    v59 = stack[-9];
    v58 = elt(env, 15); /* prepsq!*2 */
    fn = elt(env, 20); /* sqform */
    v58 = (*qfn2(fn))(qenv(fn), v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    goto v80;

v80:
    stack[-9] = v58;
    v58 = stack[-10];
    fn = elt(env, 16); /* setkorder */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    v58 = stack[-9];
    goto v81;

v81:
    qvalue(elt(env, 1)) = stack[-8]; /* !*combinelogs */
    { popv(12); return onevalue(v58); }

v79:
    v58 = stack[-9];
    v60 = qcar(v58);
    v58 = stack[-9];
    v59 = qcdr(v58);
    v58 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 21); /* prepsq!*1 */
    v58 = (*qfnn(fn))(qenv(fn), 3, v60, v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    fn = elt(env, 22); /* replus */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    goto v80;

v76:
    v58 = qvalue(elt(env, 10)); /* wtl!* */
    goto v77;

v65:
    v60 = v59;
    v58 = elt(env, 5); /* prepsq!*fn */
    v58 = get(v60, v58);
    env = stack[-11];
    v60 = v58;
    if (v58 == nil) goto v82;
    v58 = stack[-9];
    v58 = Lapply2(nil, 3, v60, v58, v59);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    goto v66;

v82:
    v58 = elt(env, 6); /* klist */
    v58 = get(v59, v58);
    env = stack[-11];
    stack[-3] = v58;
    v58 = stack[-3];
    if (v58 == nil) goto v83;
    v58 = stack[-3];
    v58 = qcar(v58);
    v58 = qcar(v58);
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    stack[-1] = v58;
    stack[-2] = v58;
    goto v84;

v84:
    v58 = stack[-3];
    v58 = qcdr(v58);
    stack[-3] = v58;
    v58 = stack[-3];
    if (v58 == nil) goto v85;
    stack[0] = stack[-1];
    v58 = stack[-3];
    v58 = qcar(v58);
    v58 = qcar(v58);
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    v58 = Lrplacd(nil, stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-11];
    v58 = stack[-1];
    v58 = qcdr(v58);
    stack[-1] = v58;
    goto v84;

v85:
    v58 = stack[-2];
    goto v66;

v83:
    v58 = qvalue(elt(env, 4)); /* nil */
    goto v66;

v64:
    v58 = qvalue(elt(env, 4)); /* nil */
    v59 = v58;
    goto v75;

v61:
    v58 = (Lisp_Object)1; /* 0 */
    goto v81;
/* error exit handlers */
v62:
    env = stack[-11];
    qvalue(elt(env, 1)) = stack[-8]; /* !*combinelogs */
    popv(12);
    return nil;
}



/* Code for qqe_ofsf_varlterm */

static Lisp_Object CC_qqe_ofsf_varlterm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v86)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v54, v95, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_ofsf_varlterm");
#endif
    if (stack >= stacklimit)
    {
        push2(v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v95 = v86;
    v96 = v0;
/* end of prologue */
    v53 = v96;
    if (!consp(v53)) goto v97;
    v53 = qvalue(elt(env, 1)); /* nil */
    goto v98;

v98:
    if (v53 == nil) goto v99;
    v53 = v96;
    v54 = v95;
    fn = elt(env, 3); /* lto_insertq */
    v53 = (*qfn2(fn))(qenv(fn), v53, v54);
    nil = C_nil;
    if (exception_pending()) goto v49;
    v95 = v53;
    { popv(2); return onevalue(v95); }

v99:
    v53 = v96;
    if (!consp(v53)) { popv(2); return onevalue(v95); }
    v53 = v96;
    v53 = qcdr(v53);
    stack[0] = v53;
    goto v100;

v100:
    v53 = stack[0];
    if (v53 == nil) { popv(2); return onevalue(v95); }
    v53 = stack[0];
    v53 = qcar(v53);
    v54 = v95;
    v53 = CC_qqe_ofsf_varlterm(env, v53, v54);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-1];
    v95 = v53;
    v53 = stack[0];
    v53 = qcdr(v53);
    stack[0] = v53;
    goto v100;

v97:
    v53 = v96;
    if (symbolp(v53)) goto v101;
    v53 = qvalue(elt(env, 1)); /* nil */
    goto v98;

v101:
    v54 = v96;
    v53 = elt(env, 2); /* qepsilon */
    v53 = (v54 == v53 ? lisp_true : nil);
    v53 = (v53 == nil ? lisp_true : nil);
    goto v98;
/* error exit handlers */
v49:
    popv(2);
    return nil;
}



/* Code for ibalp_var!-unsatlist */

static Lisp_Object CC_ibalp_varKunsatlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v86)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_var-unsatlist");
#endif
    if (stack >= stacklimit)
    {
        push2(v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v86;
    v105 = v0;
/* end of prologue */
    stack[-3] = v105;
    goto v81;

v81:
    v105 = stack[-3];
    if (v105 == nil) goto v98;
    v105 = stack[-3];
    v105 = qcar(v105);
    stack[-1] = v105;
    v106 = stack[-2];
    v105 = (Lisp_Object)17; /* 1 */
    v105 = Leqn(nil, v106, v105);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-4];
    if (v105 == nil) goto v100;
    v105 = stack[-1];
    v105 = qcdr(v105);
    v105 = qcdr(v105);
    stack[0] = qcdr(v105);
    v105 = stack[-1];
    v105 = qcdr(v105);
    v105 = qcdr(v105);
    v105 = qcdr(v105);
    v105 = qcar(v105);
    v105 = sub1(v105);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-4];
    fn = elt(env, 2); /* setcar */
    v105 = (*qfn2(fn))(qenv(fn), stack[0], v105);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-4];
    goto v108;

v108:
    v105 = stack[-3];
    v105 = qcdr(v105);
    stack[-3] = v105;
    goto v81;

v100:
    v105 = stack[-1];
    v105 = qcdr(v105);
    stack[0] = qcdr(v105);
    v105 = stack[-1];
    v105 = qcdr(v105);
    v105 = qcdr(v105);
    v105 = qcar(v105);
    v105 = sub1(v105);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-4];
    fn = elt(env, 2); /* setcar */
    v105 = (*qfn2(fn))(qenv(fn), stack[0], v105);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-4];
    goto v108;

v98:
    v105 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v105); }
/* error exit handlers */
v107:
    popv(5);
    return nil;
}



/* Code for ratpoly_nullp */

static Lisp_Object CC_ratpoly_nullp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v111;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_nullp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v111 = v0;
/* end of prologue */
    v110 = v111;
    v110 = qcar(v110);
    if (v110 == nil) goto v2;
    v110 = v111;
    v111 = qcar(v110);
    v110 = (Lisp_Object)1; /* 0 */
    v110 = (v111 == v110 ? lisp_true : nil);
    return onevalue(v110);

v2:
    v110 = qvalue(elt(env, 1)); /* t */
    return onevalue(v110);
}



/* Code for ir2mml */

static Lisp_Object CC_ir2mml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ir2mml");
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
    v108 = elt(env, 1); /* (indent) */
    fn = elt(env, 8); /* fluid */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    v108 = (Lisp_Object)49; /* 3 */
    qvalue(elt(env, 2)) = v108; /* ind */
    v108 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v108; /* indent */
    v108 = elt(env, 4); /* "<math>" */
    fn = elt(env, 9); /* printout */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    v108 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 10); /* indent!* */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    v108 = stack[0];
    fn = elt(env, 11); /* expression */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    v108 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 10); /* indent!* */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    v108 = elt(env, 7); /* "</math>" */
    fn = elt(env, 9); /* printout */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v110;
    v108 = nil;
    { popv(2); return onevalue(v108); }
/* error exit handlers */
v110:
    popv(2);
    return nil;
}



/* Code for evalvars */

static Lisp_Object CC_evalvars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalvars");
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
    goto v1;

v1:
    v121 = stack[-1];
    if (v121 == nil) goto v99;
    v121 = stack[-1];
    v121 = qcar(v121);
    if (!consp(v121)) goto v109;
    v121 = stack[-1];
    v121 = qcar(v121);
    v122 = qcar(v121);
    v121 = elt(env, 2); /* intfn */
    v121 = Lflagp(nil, v122, v121);
    env = stack[-3];
    goto v103;

v103:
    if (v121 == nil) goto v123;
    v121 = stack[-1];
    v122 = qcar(v121);
    v121 = stack[-2];
    v121 = cons(v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    stack[-2] = v121;
    v121 = stack[-1];
    v121 = qcdr(v121);
    stack[-1] = v121;
    goto v1;

v123:
    v121 = stack[-1];
    v121 = qcar(v121);
    v122 = qcar(v121);
    v121 = elt(env, 3); /* rtype */
    v122 = get(v122, v121);
    env = stack[-3];
    v121 = elt(env, 4); /* setelemfn */
    v121 = get(v122, v121);
    env = stack[-3];
    if (v121 == nil) goto v125;
    v121 = stack[-1];
    v121 = qcar(v121);
    stack[0] = qcar(v121);
    v121 = stack[-1];
    v121 = qcar(v121);
    v121 = qcdr(v121);
    fn = elt(env, 5); /* revlis_without_mode */
    v122 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    v121 = stack[-2];
    v121 = acons(stack[0], v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    stack[-2] = v121;
    v121 = stack[-1];
    v121 = qcdr(v121);
    stack[-1] = v121;
    goto v1;

v125:
    v121 = stack[-1];
    v121 = qcar(v121);
    stack[0] = qcar(v121);
    v121 = stack[-1];
    v121 = qcar(v121);
    v121 = qcdr(v121);
    fn = elt(env, 6); /* revlis */
    v122 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    v121 = stack[-2];
    v121 = acons(stack[0], v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    stack[-2] = v121;
    v121 = stack[-1];
    v121 = qcdr(v121);
    stack[-1] = v121;
    goto v1;

v109:
    v121 = qvalue(elt(env, 1)); /* t */
    goto v103;

v99:
    v121 = stack[-2];
    {
        popv(4);
        fn = elt(env, 7); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v121);
    }
/* error exit handlers */
v124:
    popv(4);
    return nil;
}



/* Code for doublep */

static Lisp_Object CC_doublep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v111, v101;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for doublep");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v101 = v0;
/* end of prologue */
    v111 = v101;
    v110 = elt(env, 1); /* !:rd!: */
    if (!consp(v111)) goto v109;
    v111 = qcar(v111);
    if (!(v111 == v110)) goto v109;
    v110 = v101;
    v110 = qcdr(v110);
        return Lconsp(nil, v110);

v109:
    v110 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v110);
}



/* Code for equalreval */

static Lisp_Object CC_equalreval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v105, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for equalreval");
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
    v117 = stack[-1];
    v117 = qcdr(v117);
    v117 = qcar(v117);
    fn = elt(env, 5); /* reval */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-3];
    stack[-2] = v117;
    v117 = qvalue(elt(env, 1)); /* !*evallhseqp */
    if (!(v117 == nil)) goto v132;
    v117 = stack[-1];
    v117 = qcar(v117);
    if (!consp(v117)) goto v21;
    v117 = stack[-1];
    v117 = qcar(v117);
    v105 = qcar(v117);
    v117 = elt(env, 2); /* immediate */
    v117 = Lflagp(nil, v105, v117);
    env = stack[-3];
    goto v109;

v109:
    if (!(v117 == nil)) goto v132;
    v106 = elt(env, 4); /* equal */
    v117 = stack[-1];
    v105 = qcar(v117);
    v117 = stack[-2];
    popv(4);
    return list3(v106, v105, v117);

v132:
    stack[0] = elt(env, 4); /* equal */
    v117 = stack[-1];
    v117 = qcar(v117);
    fn = elt(env, 5); /* reval */
    v105 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v131;
    v117 = stack[-2];
    {
        Lisp_Object v107 = stack[0];
        popv(4);
        return list3(v107, v105, v117);
    }

v21:
    v117 = qvalue(elt(env, 3)); /* nil */
    goto v109;
/* error exit handlers */
v131:
    popv(4);
    return nil;
}



/* Code for gparg1p */

static Lisp_Object CC_gparg1p(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gparg1p");
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

v133:
    v15 = stack[0];
    if (v15 == nil) goto v2;
    v15 = stack[0];
    v15 = qcar(v15);
    fn = elt(env, 3); /* gpargp */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-1];
    if (v15 == nil) goto v127;
    v15 = stack[0];
    v15 = qcdr(v15);
    stack[0] = v15;
    goto v133;

v127:
    v15 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v15); }

v2:
    v15 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v15); }
/* error exit handlers */
v134:
    popv(2);
    return nil;
}



/* Code for no!-side!-effect!-listp */

static Lisp_Object CC_noKsideKeffectKlistp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for no-side-effect-listp");
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

v133:
    v15 = stack[0];
    if (v15 == nil) goto v2;
    v15 = stack[0];
    v15 = qcar(v15);
    fn = elt(env, 3); /* no!-side!-effectp */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-1];
    if (v15 == nil) goto v127;
    v15 = stack[0];
    v15 = qcdr(v15);
    stack[0] = v15;
    goto v133;

v127:
    v15 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v15); }

v2:
    v15 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v15); }
/* error exit handlers */
v134:
    popv(2);
    return nil;
}



/* Code for lengthcdr */

static Lisp_Object CC_lengthcdr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lengthcdr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v1 = v0;
/* end of prologue */
    v1 = qcdr(v1);
        return Llength(nil, v1);
}



/* Code for sc_rep */

static Lisp_Object CC_sc_rep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sc_rep");
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
    v126 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* g_sc_ve */
    v126 = sub1(v126);
    nil = C_nil;
    if (exception_pending()) goto v119;
    v126 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v126/(16/CELL)));
    v126 = qcdr(v126);
    v126 = qcar(v126);
    { popv(1); return onevalue(v126); }
/* error exit handlers */
v119:
    popv(1);
    return nil;
}



/* Code for arplus!: */

static Lisp_Object CC_arplusT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v86)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v75, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arplus:");
#endif
    if (stack >= stacklimit)
    {
        push2(v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v75 = v86;
    v93 = v0;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = nil; /* dmode!* */
    stack[-1] = qvalue(elt(env, 2)); /* !*exp */
    qvalue(elt(env, 2)) = nil; /* !*exp */
    v134 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v134; /* !*exp */
    stack[0] = elt(env, 4); /* !:ar!: */
    v134 = v93;
    v134 = qcdr(v134);
    v75 = qcdr(v75);
    fn = elt(env, 5); /* addf */
    v134 = (*qfn2(fn))(qenv(fn), v134, v75);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    v134 = cons(stack[0], v134);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-2]; /* dmode!* */
    { popv(4); return onevalue(v134); }
/* error exit handlers */
v25:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-2]; /* dmode!* */
    popv(4);
    return nil;
}



/* Code for innprodkp */

static Lisp_Object MS_CDECL CC_innprodkp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v86,
                         Lisp_Object v3, Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v102, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "innprodkp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for innprodkp");
#endif
    if (stack >= stacklimit)
    {
        push4(v38,v3,v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v86,v3,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v38;
    stack[-1] = v3;
    stack[-2] = v86;
    v102 = v0;
/* end of prologue */

v135:
    v65 = stack[-1];
    if (v65 == nil) goto v98;
    v140 = stack[-2];
    v65 = stack[-1];
    v65 = qcar(v65);
    if (equal(v140, v65)) goto v63;
    v65 = stack[-1];
    v65 = qcar(v65);
    v65 = cons(v65, v102);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-3];
    v102 = v65;
    v65 = stack[-1];
    v65 = qcdr(v65);
    stack[-1] = v65;
    v65 = stack[0];
    v65 = (v65 == nil ? lisp_true : nil);
    stack[0] = v65;
    goto v135;

v63:
    v65 = stack[-1];
    v65 = qcdr(v65);
    fn = elt(env, 2); /* reversip2 */
    v65 = (*qfn2(fn))(qenv(fn), v102, v65);
    nil = C_nil;
    if (exception_pending()) goto v57;
    {
        Lisp_Object v117 = stack[0];
        popv(4);
        return cons(v117, v65);
    }

v98:
    v65 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v65); }
/* error exit handlers */
v57:
    popv(4);
    return nil;
}



/* Code for formrlis */

static Lisp_Object MS_CDECL CC_formrlis(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v86,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v152, v153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formrlis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formrlis");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v86,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v151 = v3;
    stack[-1] = v86;
    stack[-2] = v0;
/* end of prologue */
    v151 = stack[-2];
    v152 = qcar(v151);
    v151 = elt(env, 1); /* flagop */
    v151 = Lflagp(nil, v152, v151);
    env = stack[-4];
    if (v151 == nil) goto v108;
    v151 = stack[-2];
    v151 = qcdr(v151);
    fn = elt(env, 8); /* idlistp */
    v151 = (*qfn1(fn))(qenv(fn), v151);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-4];
    if (v151 == nil) goto v154;
    stack[-3] = elt(env, 7); /* flag */
    stack[0] = elt(env, 2); /* list */
    v151 = stack[-2];
    v153 = qcdr(v151);
    v152 = stack[-1];
    v151 = elt(env, 4); /* algebraic */
    fn = elt(env, 9); /* formlis */
    v151 = (*qfnn(fn))(qenv(fn), 3, v153, v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-4];
    stack[0] = cons(stack[0], v151);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-4];
    v151 = stack[-2];
    v151 = qcar(v151);
    v151 = Lmkquote(nil, v151);
    nil = C_nil;
    if (exception_pending()) goto v23;
    {
        Lisp_Object v155 = stack[-3];
        Lisp_Object v156 = stack[0];
        popv(5);
        return list3(v155, v156, v151);
    }

v154:
    v152 = elt(env, 5); /* !*comma!* */
    v151 = stack[-2];
    v151 = qcdr(v151);
    v152 = cons(v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-4];
    v151 = elt(env, 6); /* "identifier list" */
    {
        popv(5);
        fn = elt(env, 10); /* typerr */
        return (*qfn2(fn))(qenv(fn), v152, v151);
    }

v108:
    v151 = stack[-2];
    stack[-3] = qcar(v151);
    stack[0] = elt(env, 2); /* list */
    v151 = stack[-2];
    v152 = qcar(v151);
    v151 = elt(env, 3); /* share */
    if (v152 == v151) goto v63;
    v151 = stack[-2];
    v153 = qcdr(v151);
    v152 = stack[-1];
    v151 = elt(env, 4); /* algebraic */
    fn = elt(env, 9); /* formlis */
    v151 = (*qfnn(fn))(qenv(fn), 3, v153, v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-4];
    goto v41;

v41:
    v151 = cons(stack[0], v151);
    nil = C_nil;
    if (exception_pending()) goto v23;
    {
        Lisp_Object v34 = stack[-3];
        popv(5);
        return list2(v34, v151);
    }

v63:
    stack[-1] = nil;
    v151 = stack[-2];
    v151 = qcdr(v151);
    stack[-2] = v151;
    goto v100;

v100:
    v151 = stack[-2];
    if (v151 == nil) goto v116;
    v151 = stack[-2];
    v151 = qcar(v151);
    v152 = Lmkquote(nil, v151);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-4];
    v151 = stack[-1];
    v151 = cons(v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-4];
    stack[-1] = v151;
    v151 = stack[-2];
    v151 = qcdr(v151);
    stack[-2] = v151;
    goto v100;

v116:
    v151 = stack[-1];
    v151 = Lnreverse(nil, v151);
    env = stack[-4];
    goto v41;
/* error exit handlers */
v23:
    popv(5);
    return nil;
}



/* Code for triplesetprolongset */

static Lisp_Object CC_triplesetprolongset(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v86)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v64;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for triplesetprolongset");
#endif
    if (stack >= stacklimit)
    {
        push2(v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v86;
    stack[-1] = v0;
/* end of prologue */
    v64 = nil;
    goto v99;

v99:
    v104 = stack[0];
    if (v104 == nil) goto v41;
    v104 = stack[0];
    v104 = qcar(v104);
    v104 = cons(v104, v64);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-2];
    v64 = v104;
    v104 = stack[0];
    v104 = qcdr(v104);
    stack[0] = v104;
    goto v99;

v41:
    stack[0] = (Lisp_Object)49; /* 3 */
    v104 = v64;
    v104 = Lreverse(nil, v104);
    nil = C_nil;
    if (exception_pending()) goto v118;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v104;
    v104 = nil;
    { popv(3); return onevalue(v104); }
/* error exit handlers */
v118:
    popv(3);
    return nil;
}



/* Code for ofsf_surep */

static Lisp_Object CC_ofsf_surep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v86)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v101, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_surep");
#endif
    if (stack >= stacklimit)
    {
        push2(v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v111 = v86;
    v101 = v0;
/* end of prologue */
    v15 = v101;
    v101 = v111;
    v111 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 2); /* cl_simpl */
    v111 = (*qfnn(fn))(qenv(fn), 3, v15, v101, v111);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[0];
    v101 = elt(env, 1); /* true */
    v111 = (v111 == v101 ? lisp_true : nil);
    { popv(1); return onevalue(v111); }
/* error exit handlers */
v136:
    popv(1);
    return nil;
}



/* Code for qremd */

static Lisp_Object CC_qremd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v86)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qremd");
#endif
    if (stack >= stacklimit)
    {
        push2(v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v86;
    stack[-2] = v0;
/* end of prologue */
    v40 = stack[-2];
    if (v40 == nil) goto v61;
    v170 = stack[-1];
    v40 = (Lisp_Object)17; /* 1 */
    if (v170 == v40) goto v103;
    v170 = qvalue(elt(env, 1)); /* dmode!* */
    v40 = elt(env, 2); /* field */
    v40 = Lflagp(nil, v170, v40);
    env = stack[-4];
    if (v40 == nil) goto v94;
    v40 = stack[-1];
    fn = elt(env, 4); /* !:recip */
    v170 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-4];
    v40 = stack[-2];
    fn = elt(env, 5); /* multd */
    v40 = (*qfn2(fn))(qenv(fn), v170, v40);
    nil = C_nil;
    if (exception_pending()) goto v171;
    popv(5);
    return ncons(v40);

v94:
    v40 = stack[-2];
    if (!consp(v40)) goto v172;
    v40 = stack[-2];
    v40 = qcar(v40);
    v40 = (consp(v40) ? nil : lisp_true);
    goto v138;

v138:
    if (v40 == nil) goto v96;
    v170 = stack[-2];
    v40 = stack[-1];
    {
        popv(5);
        fn = elt(env, 6); /* !:divide */
        return (*qfn2(fn))(qenv(fn), v170, v40);
    }

v96:
    v40 = stack[-2];
    v40 = qcar(v40);
    v170 = qcdr(v40);
    v40 = stack[-1];
    fn = elt(env, 7); /* qremf */
    v40 = (*qfn2(fn))(qenv(fn), v170, v40);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-4];
    stack[-3] = v40;
    v40 = stack[-2];
    v40 = qcar(v40);
    v170 = qcar(v40);
    v40 = (Lisp_Object)17; /* 1 */
    v40 = cons(v170, v40);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-4];
    v170 = ncons(v40);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-4];
    v40 = stack[-3];
    v40 = qcar(v40);
    fn = elt(env, 8); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v170, v40);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-4];
    v40 = stack[-2];
    v40 = qcar(v40);
    v170 = qcar(v40);
    v40 = (Lisp_Object)17; /* 1 */
    v40 = cons(v170, v40);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-4];
    v170 = ncons(v40);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-4];
    v40 = stack[-3];
    v40 = qcdr(v40);
    fn = elt(env, 8); /* multf */
    v40 = (*qfn2(fn))(qenv(fn), v170, v40);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-4];
    stack[0] = cons(stack[0], v40);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-4];
    v40 = stack[-2];
    v170 = qcdr(v40);
    v40 = stack[-1];
    v40 = CC_qremd(env, v170, v40);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-4];
    stack[-2] = stack[0];
    stack[-1] = v40;
    v40 = stack[-2];
    v170 = qcar(v40);
    v40 = stack[-1];
    v40 = qcar(v40);
    fn = elt(env, 9); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v170, v40);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-4];
    v40 = stack[-2];
    v170 = qcdr(v40);
    v40 = stack[-1];
    v40 = qcdr(v40);
    fn = elt(env, 9); /* addf */
    v40 = (*qfn2(fn))(qenv(fn), v170, v40);
    nil = C_nil;
    if (exception_pending()) goto v171;
    {
        Lisp_Object v173 = stack[0];
        popv(5);
        return cons(v173, v40);
    }

v172:
    v40 = qvalue(elt(env, 3)); /* t */
    goto v138;

v103:
    v40 = stack[-2];
    popv(5);
    return ncons(v40);

v61:
    v170 = stack[-2];
    v40 = stack[-2];
    popv(5);
    return cons(v170, v40);
/* error exit handlers */
v171:
    popv(5);
    return nil;
}



/* Code for rndifference!: */

static Lisp_Object CC_rndifferenceT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v86)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rndifference:");
#endif
    if (stack >= stacklimit)
    {
        push2(v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v86;
    stack[-1] = v0;
/* end of prologue */
    v172 = stack[-1];
    v172 = qcdr(v172);
    v174 = qcar(v172);
    v172 = stack[0];
    v172 = qcdr(v172);
    v172 = qcdr(v172);
    stack[-2] = times2(v174, v172);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    v172 = stack[-1];
    v172 = qcdr(v172);
    v174 = qcdr(v172);
    v172 = stack[0];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    v172 = times2(v174, v172);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    stack[-2] = difference2(stack[-2], v172);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    v172 = stack[-1];
    v172 = qcdr(v172);
    v174 = qcdr(v172);
    v172 = stack[0];
    v172 = qcdr(v172);
    v172 = qcdr(v172);
    v172 = times2(v174, v172);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    {
        Lisp_Object v140 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v140, v172);
    }
/* error exit handlers */
v102:
    popv(4);
    return nil;
}



/* Code for token!-number */

static Lisp_Object CC_tokenKnumber(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202, v203, v204;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for token-number");
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
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    v202 = (Lisp_Object)1; /* 0 */
    stack[-3] = v202;
    v202 = (Lisp_Object)33; /* 2 */
    qvalue(elt(env, 1)) = v202; /* ttype!* */
    goto v61;

v61:
    v202 = stack[-1];
    if (!(v202 == nil)) goto v63;
    v203 = stack[-4];
    v202 = elt(env, 2); /* !) */
    if (!(v203 == v202)) goto v63;

v110:
    v202 = stack[-5];
    if (v202 == nil) goto v174;
    v202 = stack[-3];
    v202 = sub1(v202);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    stack[-3] = v202;
    goto v174;

v174:
    fn = elt(env, 23); /* readch1 */
    v203 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    stack[-4] = v203;
    v202 = elt(env, 3); /* !. */
    if (v203 == v202) goto v138;
    v202 = stack[-4];
    v202 = Ldigitp(nil, v202);
    env = stack[-6];
    if (!(v202 == nil)) goto v61;
    v203 = stack[-1];
    v202 = elt(env, 8); /* (!0) */
    if (equal(v203, v202)) goto v147;
    v202 = qvalue(elt(env, 11)); /* nil */
    goto v50;

v50:
    if (v202 == nil) goto v169;
    v202 = (Lisp_Object)1; /* 0 */
    stack[-1] = v202;
    goto v205;

v205:
    fn = elt(env, 23); /* readch1 */
    v203 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    stack[-4] = v203;
    v202 = elt(env, 17); /* hexdigit */
    v202 = get(v203, v202);
    env = stack[-6];
    stack[0] = v202;
    if (v202 == nil) goto v103;
    v203 = (Lisp_Object)257; /* 16 */
    v202 = stack[-1];
    v203 = times2(v203, v202);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    v202 = stack[0];
    v202 = plus2(v203, v202);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    stack[-1] = v202;
    goto v205;

v103:
    v202 = stack[-5];
    if (v202 == nil) goto v80;
    v204 = elt(env, 18); /* !:dn!: */
    v203 = stack[-1];
    v202 = stack[-3];
    v202 = list2star(v204, v203, v202);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    goto v206;

v206:
    qvalue(elt(env, 21)) = v202; /* nxtsym!* */
    v202 = stack[-4];
    qvalue(elt(env, 22)) = v202; /* crchar!* */
    v202 = qvalue(elt(env, 21)); /* nxtsym!* */
    { popv(7); return onevalue(v202); }

v80:
    v202 = qvalue(elt(env, 19)); /* !*adjprec */
    if (v202 == nil) goto v207;
    v204 = elt(env, 20); /* !:int!: */
    v203 = stack[-1];
    v202 = qvalue(elt(env, 11)); /* nil */
    v202 = list2star(v204, v203, v202);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    goto v206;

v207:
    v202 = stack[-1];
    goto v206;

v169:
    v203 = stack[-4];
    v202 = elt(env, 12); /* !\ */
    if (v203 == v202) goto v141;
    v203 = stack[-4];
    v202 = elt(env, 13); /* e */
    if (v203 == v202) goto v162;
    v203 = stack[-4];
    v202 = elt(env, 14); /* !E */
    v202 = (v203 == v202 ? lisp_true : nil);
    goto v68;

v68:
    if (!(v202 == nil)) goto v137;

v119:
    v202 = stack[-1];
    v202 = Lnreverse(nil, v202);
    env = stack[-6];
    v202 = Lcompress(nil, v202);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    stack[-1] = v202;
    goto v103;

v137:
    v202 = qvalue(elt(env, 7)); /* t */
    stack[-5] = v202;
    fn = elt(env, 23); /* readch1 */
    v203 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    stack[-4] = v203;
    v202 = elt(env, 15); /* !- */
    if (v203 == v202) goto v208;
    v203 = stack[-4];
    v202 = elt(env, 16); /* !+ */
    if (v203 == v202) goto v97;
    v202 = stack[-4];
    v202 = Ldigitp(nil, v202);
    env = stack[-6];
    if (v202 == nil) goto v119;
    v202 = stack[-4];
    v202 = ncons(v202);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    stack[0] = v202;
    goto v97;

v97:
    fn = elt(env, 23); /* readch1 */
    v202 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    stack[-4] = v202;
    v202 = Ldigitp(nil, v202);
    env = stack[-6];
    if (v202 == nil) goto v92;
    v203 = stack[-4];
    v202 = stack[0];
    v202 = cons(v203, v202);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    stack[0] = v202;
    goto v97;

v92:
    v202 = stack[0];
    if (!(v202 == nil)) goto v209;
    v202 = elt(env, 4); /* "Syntax error: improper number" */
    v203 = v202;
    v202 = v203;
    qvalue(elt(env, 5)) = v202; /* errmsg!* */
    v202 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v202 == nil)) goto v210;
    v202 = v203;
    fn = elt(env, 24); /* lprie */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    goto v210;

v210:
    v202 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    goto v209;

v209:
    v202 = stack[0];
    v202 = Lnreverse(nil, v202);
    env = stack[-6];
    v202 = Lcompress(nil, v202);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    stack[0] = v202;
    v202 = stack[-2];
    if (v202 == nil) goto v211;
    v203 = stack[-3];
    v202 = stack[0];
    v202 = difference2(v203, v202);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    stack[-3] = v202;
    goto v119;

v211:
    v203 = stack[-3];
    v202 = stack[0];
    v202 = plus2(v203, v202);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    stack[-3] = v202;
    goto v119;

v208:
    v202 = qvalue(elt(env, 7)); /* t */
    stack[-2] = v202;
    goto v97;

v162:
    v202 = qvalue(elt(env, 7)); /* t */
    goto v68;

v141:
    v202 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    goto v174;

v147:
    v203 = stack[-4];
    v202 = elt(env, 9); /* x */
    if (v203 == v202) goto v113;
    v203 = stack[-4];
    v202 = elt(env, 10); /* !X */
    v202 = (v203 == v202 ? lisp_true : nil);
    goto v50;

v113:
    v202 = qvalue(elt(env, 7)); /* t */
    goto v50;

v138:
    v202 = stack[-5];
    if (v202 == nil) goto v48;
    v202 = elt(env, 4); /* "Syntax error: improper number" */
    v203 = v202;
    v202 = v203;
    qvalue(elt(env, 5)) = v202; /* errmsg!* */
    v202 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v202 == nil)) goto v55;
    v202 = v203;
    fn = elt(env, 24); /* lprie */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    goto v55;

v55:
    v202 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    goto v137;

v48:
    v202 = qvalue(elt(env, 7)); /* t */
    stack[-5] = v202;
    goto v174;

v63:
    v203 = stack[-4];
    v202 = stack[-1];
    v202 = cons(v203, v202);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-6];
    stack[-1] = v202;
    goto v110;
/* error exit handlers */
v59:
    popv(7);
    return nil;
}



/* Code for aex_ids */

static Lisp_Object CC_aex_ids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_ids");
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
    v1 = v0;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* ratpoly_idl */
        return (*qfn1(fn))(qenv(fn), v1);
    }
/* error exit handlers */
v81:
    popv(1);
    return nil;
}



/* Code for gcd2 */

static Lisp_Object CC_gcd2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v86)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v139, v104;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcd2");
#endif
    if (stack >= stacklimit)
    {
        push2(v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v86;
    v139 = v0;
/* end of prologue */

v61:
    v132 = stack[0];
    v132 = Cremainder(v139, v132);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-1];
    v104 = v132;
    v139 = v104;
    v132 = (Lisp_Object)1; /* 0 */
    if (v139 == v132) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v139 = stack[0];
    v132 = v104;
    stack[0] = v132;
    goto v61;
/* error exit handlers */
v90:
    popv(2);
    return nil;
}



/* Code for bcfd */

static Lisp_Object CC_bcfd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v123, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcfd");
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
    v65 = v0;
/* end of prologue */
    v116 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v116 == nil) goto v99;
    v116 = v65;
    v116 = integerp(v116);
    if (v116 == nil) goto v15;
    v116 = v65;
    {
        popv(1);
        fn = elt(env, 5); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v116);
    }

v15:
    v116 = v65;
    v123 = qcar(v116);
    v116 = elt(env, 2); /* !:mod!: */
    if (v123 == v116) goto v100;
    v116 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v116 == nil)) goto v63;
    v116 = elt(env, 4); /* "Invalid modular coefficient" */
    v123 = v65;
    v116 = list2(v116, v123);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[0];
    fn = elt(env, 6); /* lprie */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[0];
    goto v63;

v63:
    v116 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v102;
    v116 = nil;
    { popv(1); return onevalue(v116); }

v100:
    v116 = v65;
    v116 = qcdr(v116);
    {
        popv(1);
        fn = elt(env, 5); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v116);
    }

v99:
    v123 = v65;
    v116 = (Lisp_Object)17; /* 1 */
    {
        popv(1);
        fn = elt(env, 7); /* mkbc */
        return (*qfn2(fn))(qenv(fn), v123, v116);
    }
/* error exit handlers */
v102:
    popv(1);
    return nil;
}



/* Code for vdpputprop */

static Lisp_Object MS_CDECL CC_vdpputprop(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v86,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v216, v168, v217, v218;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vdpputprop");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpputprop");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v86,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v3;
    stack[-2] = v86;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    v216 = stack[-3];
    v216 = Lconsp(nil, v216);
    env = stack[-5];
    if (v216 == nil) goto v92;
    v216 = stack[-3];
    v216 = qcdr(v216);
    stack[-4] = v216;
    v216 = Lconsp(nil, v216);
    env = stack[-5];
    if (v216 == nil) goto v15;
    v216 = stack[-4];
    v216 = qcdr(v216);
    stack[-4] = v216;
    v216 = Lconsp(nil, v216);
    env = stack[-5];
    if (v216 == nil) goto v120;
    v216 = stack[-4];
    v216 = qcdr(v216);
    stack[-4] = v216;
    v216 = Lconsp(nil, v216);
    env = stack[-5];
    if (v216 == nil) goto v130;
    v216 = stack[-4];
    v216 = qcdr(v216);
    stack[-4] = v216;
    v216 = Lconsp(nil, v216);
    env = stack[-5];
    v216 = (v216 == nil ? lisp_true : nil);
    goto v126;

v126:
    if (v216 == nil) goto v150;
    v218 = elt(env, 2); /* "vdpputprop given a non-vdp as 1st parameter" 
*/
    v217 = stack[-3];
    v168 = stack[-2];
    v216 = stack[-1];
    v216 = list4(v218, v217, v168, v216);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    v168 = v216;
    v216 = v168;
    qvalue(elt(env, 3)) = v216; /* errmsg!* */
    v216 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v216 == nil)) goto v96;
    v216 = v168;
    fn = elt(env, 5); /* lprie */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    goto v96;

v96:
    v216 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    goto v150;

v150:
    v168 = stack[-2];
    v216 = stack[-4];
    v216 = qcar(v216);
    v216 = Lassoc(nil, v168, v216);
    v168 = v216;
    v216 = v168;
    if (v216 == nil) goto v200;
    v216 = stack[-1];
    v216 = Lrplacd(nil, v168, v216);
    nil = C_nil;
    if (exception_pending()) goto v144;
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v200:
    stack[0] = stack[-4];
    v217 = stack[-2];
    v168 = stack[-1];
    v216 = stack[-4];
    v216 = qcar(v216);
    v216 = acons(v217, v168, v216);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    v216 = Lrplaca(nil, stack[0], v216);
    nil = C_nil;
    if (exception_pending()) goto v144;
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v130:
    v216 = qvalue(elt(env, 1)); /* t */
    goto v126;

v120:
    v216 = qvalue(elt(env, 1)); /* t */
    goto v126;

v15:
    v216 = qvalue(elt(env, 1)); /* t */
    goto v126;

v92:
    v216 = qvalue(elt(env, 1)); /* t */
    goto v126;
/* error exit handlers */
v144:
    popv(6);
    return nil;
}



/* Code for coposp */

static Lisp_Object CC_coposp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coposp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v75 = v0;
/* end of prologue */
    v134 = v75;
    v134 = qcdr(v134);
    if (v134 == nil) goto v2;
    v134 = v75;
    v134 = qcar(v134);
    if (!consp(v134)) goto v126;
    v134 = v75;
    v134 = qcdr(v134);
    {
        fn = elt(env, 2); /* covposp */
        return (*qfn1(fn))(qenv(fn), v134);
    }

v126:
    v134 = v75;
    v134 = qcdr(v134);
    {
        fn = elt(env, 3); /* contposp */
        return (*qfn1(fn))(qenv(fn), v134);
    }

v2:
    v134 = qvalue(elt(env, 1)); /* t */
    return onevalue(v134);
}



/* Code for b_expand2 */

static Lisp_Object MS_CDECL CC_b_expand2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v86,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v111, v101, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "b_expand2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for b_expand2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v110 = v3;
    v111 = v86;
    v101 = v0;
/* end of prologue */
    v15 = v101;
    v15 = qcar(v15);
    v101 = qcdr(v101);
    {
        fn = elt(env, 1); /* b_expand2b */
        return (*qfnn(fn))(qenv(fn), 4, v15, v101, v111, v110);
    }
}



/* Code for ratminus */

static Lisp_Object CC_ratminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v92;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratminus");
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
    stack[0] = v0;
/* end of prologue */
    v126 = stack[0];
    v126 = qcar(v126);
    v92 = negate(v126);
    nil = C_nil;
    if (exception_pending()) goto v103;
    v126 = stack[0];
    v126 = qcdr(v126);
    popv(1);
    return cons(v92, v126);
/* error exit handlers */
v103:
    popv(1);
    return nil;
}



/* Code for refprint */

static Lisp_Object CC_refprint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v198, v219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for refprint");
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
    v198 = qvalue(elt(env, 1)); /* cloc!* */
    if (v198 == nil) goto v126;
    v198 = qvalue(elt(env, 1)); /* cloc!* */
    v198 = qcar(v198);
    goto v135;

v135:
    stack[-4] = v198;
    v219 = stack[-4];
    v198 = qvalue(elt(env, 3)); /* pfiles!* */
    v198 = Lassoc(nil, v219, v198);
    qvalue(elt(env, 4)) = v198; /* curfun!* */
    if (v198 == nil) goto v67;
    v198 = qvalue(elt(env, 4)); /* curfun!* */
    v198 = qcar(v198);
    stack[-4] = v198;
    v198 = qvalue(elt(env, 4)); /* curfun!* */
    v198 = qcdr(v198);
    qvalue(elt(env, 4)) = v198; /* curfun!* */
    goto v109;

v109:
    v198 = qvalue(elt(env, 1)); /* cloc!* */
    if (v198 == nil) goto v165;
    v198 = qvalue(elt(env, 1)); /* cloc!* */
    v198 = qcdr(v198);
    if (v198 == nil) goto v165;
    v219 = stack[-4];
    v198 = qvalue(elt(env, 1)); /* cloc!* */
    v198 = qcdr(v198);
    v198 = cons(v219, v198);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-5];
    goto v54;

v54:
    qvalue(elt(env, 8)) = v198; /* curlin!* */
    v198 = qvalue(elt(env, 7)); /* nil */
    qvalue(elt(env, 9)) = v198; /* locls!* */
    qvalue(elt(env, 10)) = v198; /* globs!* */
    qvalue(elt(env, 11)) = v198; /* calls!* */
    v198 = stack[-3];
    fn = elt(env, 12); /* anform */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-5];
    v198 = qvalue(elt(env, 4)); /* curfun!* */
    fn = elt(env, 13); /* outrefend */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v146;
    v198 = nil;
    { popv(6); return onevalue(v198); }

v165:
    v198 = qvalue(elt(env, 7)); /* nil */
    goto v54;

v67:
    stack[0] = stack[-4];
    v198 = elt(env, 5); /* g */
    v219 = Lgensym1(nil, v198);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-5];
    qvalue(elt(env, 4)) = v219; /* curfun!* */
    v198 = qvalue(elt(env, 3)); /* pfiles!* */
    v198 = acons(stack[0], v219, v198);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-5];
    qvalue(elt(env, 3)) = v198; /* pfiles!* */
    v198 = stack[-4];
    v198 = Lexplode(nil, v198);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-5];
    v198 = qcdr(v198);
    v198 = Lnreverse(nil, v198);
    env = stack[-5];
    v198 = qcdr(v198);
    v198 = Lnreverse(nil, v198);
    env = stack[-5];
    stack[-2] = v198;
    stack[-1] = qvalue(elt(env, 4)); /* curfun!* */
    stack[0] = elt(env, 6); /* rccnam */
    v198 = stack[-2];
    v219 = Llength(nil, v198);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-5];
    v198 = stack[-2];
    v198 = cons(v219, v198);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-5];
    v198 = Lputprop(nil, 3, stack[-1], stack[0], v198);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-5];
    goto v109;

v126:
    v198 = elt(env, 2); /* "*TTYINPUT*" */
    goto v135;
/* error exit handlers */
v146:
    popv(6);
    return nil;
}



/* Code for pasf_anegrel */

static Lisp_Object CC_pasf_anegrel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v21, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_anegrel");
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
    v120 = v0;
/* end of prologue */
    v21 = v120;
    v25 = elt(env, 1); /* ((equal . equal) (neq . neq) (leq . geq) (geq . leq) (lessp . greaterp) (greaterp . lessp) (cong . cong) (ncong . ncong)) 
*/
    v25 = Latsoc(nil, v21, v25);
    v25 = qcdr(v25);
    if (!(v25 == nil)) { popv(1); return onevalue(v25); }
    v25 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v25 == nil)) goto v109;
    v25 = elt(env, 3); /* "pasf_anegrel: unknown operator " */
    v21 = v120;
    v25 = list2(v25, v21);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[0];
    fn = elt(env, 4); /* lprie */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[0];
    goto v109;

v109:
    v25 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v63;
    v25 = nil;
    { popv(1); return onevalue(v25); }
/* error exit handlers */
v63:
    popv(1);
    return nil;
}



/* Code for applyrd */

static Lisp_Object MS_CDECL CC_applyrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "applyrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for applyrd");
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
    fn = elt(env, 7); /* lex */
    v88 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-1];
    v131 = qvalue(elt(env, 1)); /* atts */
    v88 = elt(env, 2); /* (type definitionurl encoding) */
    fn = elt(env, 8); /* retattributes */
    v88 = (*qfn2(fn))(qenv(fn), v131, v88);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-1];
    qvalue(elt(env, 3)) = v88; /* mmlatts */
    v88 = qvalue(elt(env, 4)); /* char */
    fn = elt(env, 9); /* compress!* */
    v131 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-1];
    v88 = qvalue(elt(env, 5)); /* functions!* */
    v88 = Lassoc(nil, v131, v88);
    stack[0] = v88;
    if (v88 == nil) goto v89;
    v88 = stack[0];
    v88 = qcdr(v88);
    v131 = qcar(v88);
    v88 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 10); /* apply */
    v88 = (*qfn2(fn))(qenv(fn), v131, v88);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-1];
    v131 = v88;
    v88 = qvalue(elt(env, 3)); /* mmlatts */
    v88 = cons(v88, v131);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-1];
    v131 = v88;
    v88 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 3)) = v88; /* mmlatts */
    v88 = stack[0];
    v88 = qcdr(v88);
    v88 = qcdr(v88);
    v88 = qcar(v88);
    popv(2);
    return cons(v88, v131);

v89:
    v88 = qvalue(elt(env, 4)); /* char */
    v131 = Lcompress(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-1];
    v88 = (Lisp_Object)273; /* 17 */
    fn = elt(env, 11); /* errorml */
    v88 = (*qfn2(fn))(qenv(fn), v131, v88);
    nil = C_nil;
    if (exception_pending()) goto v55;
    v88 = nil;
    { popv(2); return onevalue(v88); }
/* error exit handlers */
v55:
    popv(2);
    return nil;
}



/* Code for xdegreecheck */

static Lisp_Object CC_xdegreecheck(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xdegreecheck");
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
    v110 = v0;
/* end of prologue */
    v157 = qvalue(elt(env, 1)); /* xtruncate!* */
    if (v157 == nil) goto v2;
    v157 = v110;
    fn = elt(env, 3); /* xdegree */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[0];
    v110 = qvalue(elt(env, 1)); /* xtruncate!* */
        popv(1);
        return Lgreaterp(nil, v157, v110);

v2:
    v157 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v157); }
/* error exit handlers */
v111:
    popv(1);
    return nil;
}



/* Code for testchar1 */

static Lisp_Object CC_testchar1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v137;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testchar1");
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
    v100 = stack[0];
    v100 = integerp(v100);
    if (!(v100 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v100 = stack[0];
    v100 = Lexplodec(nil, v100);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-1];
    v100 = qcdr(v100);
    if (v100 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v137 = stack[0];
    v100 = qvalue(elt(env, 1)); /* nochar!* */
    v100 = Lmember(nil, v137, v100);
    if (!(v100 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v137 = stack[0];
    v100 = qvalue(elt(env, 2)); /* nochar1!* */
    v100 = Lmember(nil, v137, v100);
    if (!(v100 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v137 = stack[0];
    v100 = qvalue(elt(env, 2)); /* nochar1!* */
    v100 = cons(v137, v100);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-1];
    qvalue(elt(env, 2)) = v100; /* nochar1!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v172:
    popv(2);
    return nil;
}



/* Code for !:dmtimeslst */

static Lisp_Object CC_Tdmtimeslst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :dmtimeslst");
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
    v94 = v0;
/* end of prologue */
    v93 = v94;
    if (v93 == nil) goto v2;
    v93 = v94;
    v93 = qcdr(v93);
    if (v93 == nil) goto v99;
    v93 = v94;
    stack[0] = qcar(v93);
    v93 = v94;
    v93 = qcdr(v93);
    v93 = CC_Tdmtimeslst(env, v93);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-1];
    {
        Lisp_Object v25 = stack[0];
        popv(2);
        fn = elt(env, 1); /* !:times */
        return (*qfn2(fn))(qenv(fn), v25, v93);
    }

v99:
    v93 = v94;
    v93 = qcar(v93);
    { popv(2); return onevalue(v93); }

v2:
    v93 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v93); }
/* error exit handlers */
v42:
    popv(2);
    return nil;
}



/* Code for physopsm!* */

static Lisp_Object CC_physopsmH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v175, v206, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopsm*");
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
    stack[0] = nil;
    v11 = stack[-3];
    if (v11 == nil) goto v119;
    v11 = stack[-3];
    v11 = (is_number(v11) ? lisp_true : nil);
    goto v92;

v92:
    if (v11 == nil) goto v127;
    v11 = stack[-3];
    stack[0] = v11;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v127:
    v11 = stack[-3];
    fn = elt(env, 15); /* physopp */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-5];
    if (v11 == nil) goto v134;
    v175 = stack[-3];
    v11 = elt(env, 2); /* rvalue */
    v11 = get(v175, v11);
    env = stack[-5];
    stack[-1] = v11;
    if (v11 == nil) goto v25;
    v11 = stack[-1];
    fn = elt(env, 16); /* physopaeval */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    goto v41;

v41:
    stack[0] = v11;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v25:
    v11 = stack[-3];
    if (symbolp(v11)) goto v118;
    v11 = stack[-3];
    v175 = qcar(v11);
    v11 = elt(env, 3); /* psimpfn */
    v11 = get(v175, v11);
    env = stack[-5];
    stack[-1] = v11;
    if (v11 == nil) goto v107;
    v175 = stack[-1];
    v11 = stack[-3];
    v11 = Lapply1(nil, v175, v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    goto v41;

v107:
    v11 = stack[-3];
    v175 = qcar(v11);
    v11 = elt(env, 4); /* opmtch */
    v11 = get(v175, v11);
    env = stack[-5];
    if (v11 == nil) goto v150;
    v11 = stack[-3];
    fn = elt(env, 17); /* opmtch!* */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    stack[-1] = v11;
    if (v11 == nil) goto v150;
    v11 = stack[-1];
    goto v41;

v150:
    v11 = stack[-3];
    goto v41;

v118:
    v11 = stack[-3];
    goto v41;

v134:
    v11 = stack[-3];
    if (!consp(v11)) goto v82;
    v11 = stack[-3];
    v11 = qcar(v11);
    stack[-4] = v11;
    v11 = stack[-3];
    v11 = qcdr(v11);
    stack[-2] = v11;
    v175 = stack[-4];
    v11 = elt(env, 5); /* physopfunction */
    v11 = get(v175, v11);
    env = stack[-5];
    stack[-1] = v11;
    if (v11 == nil) goto v183;
    v175 = stack[-4];
    v11 = elt(env, 6); /* physoparith */
    v11 = Lflagp(nil, v175, v11);
    env = stack[-5];
    if (v11 == nil) goto v34;
    v11 = stack[-2];
    fn = elt(env, 18); /* hasonephysop */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-5];
    if (v11 == nil) goto v151;
    stack[0] = stack[-1];
    v11 = stack[-2];
    v11 = ncons(v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-5];
    fn = elt(env, 19); /* apply */
    v11 = (*qfn2(fn))(qenv(fn), stack[0], v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    stack[0] = v11;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v151:
    v175 = stack[-4];
    v11 = stack[-2];
    v11 = cons(v175, v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-5];
    fn = elt(env, 20); /* reval3 */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    stack[0] = v11;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v34:
    v175 = stack[-4];
    v11 = elt(env, 7); /* physopfn */
    v11 = Lflagp(nil, v175, v11);
    env = stack[-5];
    if (v11 == nil) goto v239;
    v11 = stack[-2];
    fn = elt(env, 21); /* areallphysops */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-5];
    if (v11 == nil) goto v37;
    stack[0] = stack[-1];
    v11 = stack[-2];
    v11 = ncons(v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-5];
    fn = elt(env, 19); /* apply */
    v11 = (*qfn2(fn))(qenv(fn), stack[0], v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    stack[0] = v11;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v37:
    stack[-1] = elt(env, 0); /* physopsm!* */
    v4 = elt(env, 8); /* "invalid call of " */
    v206 = stack[-4];
    v175 = elt(env, 9); /* " with args: " */
    v11 = stack[-2];
    v11 = list4(v4, v206, v175, v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-5];
    fn = elt(env, 22); /* rederr2 */
    v11 = (*qfn2(fn))(qenv(fn), stack[-1], v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v239:
    stack[-1] = elt(env, 0); /* physopsm!* */
    v206 = stack[-4];
    v175 = elt(env, 10); /* " has been flagged Physopfunction" */
    v11 = elt(env, 11); /* " but is not defined" */
    v11 = list3(v206, v175, v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-5];
    fn = elt(env, 22); /* rederr2 */
    v11 = (*qfn2(fn))(qenv(fn), stack[-1], v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v183:
    v175 = stack[-4];
    v11 = elt(env, 12); /* physopmapping */
    v11 = Lflagp(nil, v175, v11);
    env = stack[-5];
    if (v11 == nil) goto v240;
    v11 = stack[-2];
    fn = elt(env, 23); /* !*physopp!* */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-5];
    goto v241;

v241:
    if (v11 == nil) goto v14;
    v175 = stack[-4];
    v11 = stack[-2];
    v206 = cons(v175, v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-5];
    v175 = (Lisp_Object)17; /* 1 */
    v11 = (Lisp_Object)17; /* 1 */
    v11 = acons(v206, v175, v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-5];
    v175 = ncons(v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-5];
    v11 = (Lisp_Object)17; /* 1 */
    v11 = cons(v175, v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-5];
    fn = elt(env, 24); /* mk!*sq */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    stack[0] = v11;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v14:
    v175 = stack[-4];
    v11 = elt(env, 14); /* prog */
    if (v175 == v11) goto v242;
    v11 = stack[-3];
    fn = elt(env, 25); /* aeval */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    stack[0] = v11;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v242:
    v11 = stack[-2];
    fn = elt(env, 26); /* physopprog */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    stack[0] = v11;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v240:
    v11 = qvalue(elt(env, 13)); /* nil */
    goto v241;

v82:
    v11 = stack[-3];
    fn = elt(env, 25); /* aeval */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v238;
    stack[0] = v11;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v119:
    v11 = qvalue(elt(env, 1)); /* t */
    goto v92;
/* error exit handlers */
v238:
    popv(6);
    return nil;
}



/* Code for def_edge */

static Lisp_Object CC_def_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v86)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v120, v63, v67;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for def_edge");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v67 = v86;
    v21 = v0;
/* end of prologue */
    v21 = qcdr(v21);
    v21 = qcar(v21);
    v63 = v21;
    v21 = v63;
    v120 = qcar(v21);
    v21 = v67;
    v21 = Lassoc(nil, v120, v21);
    if (v21 == nil) goto v61;
    v21 = v63;
    v21 = qcdr(v21);
    v120 = v67;
    v21 = Lassoc(nil, v21, v120);
    return onevalue(v21);

v61:
    v21 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v21);
}



/* Code for lienjactest */

static Lisp_Object CC_lienjactest(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v295, v296, v297, v298;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lienjactest");
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
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-11] = v0;
/* end of prologue */
    stack[0] = elt(env, 1); /* lie_jtest */
    v295 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 7); /* aeval */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 8); /* setk */
    v295 = (*qfn2(fn))(qenv(fn), stack[0], v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v295 = (Lisp_Object)17; /* 1 */
    stack[-12] = v295;
    goto v136;

v136:
    stack[0] = elt(env, 2); /* difference */
    v297 = elt(env, 2); /* difference */
    v296 = stack[-11];
    v295 = (Lisp_Object)33; /* 2 */
    v295 = list3(v297, v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v296 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v295 = stack[-12];
    v295 = list3(stack[0], v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 10); /* aminusp!: */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    if (v295 == nil) goto v157;
    v295 = nil;
    { popv(14); return onevalue(v295); }

v157:
    v295 = stack[-12];
    v295 = add1(v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-10] = v295;
    goto v128;

v128:
    stack[0] = elt(env, 2); /* difference */
    v297 = elt(env, 2); /* difference */
    v296 = stack[-11];
    v295 = (Lisp_Object)17; /* 1 */
    v295 = list3(v297, v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v296 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v295 = stack[-10];
    v295 = list3(stack[0], v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 10); /* aminusp!: */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    if (v295 == nil) goto v116;
    v295 = stack[-12];
    v297 = elt(env, 4); /* plus */
    v296 = v295;
    v295 = (Lisp_Object)17; /* 1 */
    v295 = list3(v297, v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-12] = v295;
    goto v136;

v116:
    v295 = stack[-10];
    v295 = add1(v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-9] = v295;
    goto v300;

v300:
    stack[0] = elt(env, 2); /* difference */
    v295 = stack[-11];
    fn = elt(env, 9); /* aeval!* */
    v296 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v295 = stack[-9];
    v295 = list3(stack[0], v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 10); /* aminusp!: */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    if (v295 == nil) goto v50;
    v295 = stack[-10];
    v297 = elt(env, 4); /* plus */
    v296 = v295;
    v295 = (Lisp_Object)17; /* 1 */
    v295 = list3(v297, v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-10] = v295;
    goto v128;

v50:
    v295 = (Lisp_Object)17; /* 1 */
    stack[-8] = v295;
    goto v45;

v45:
    stack[0] = elt(env, 2); /* difference */
    v295 = stack[-11];
    fn = elt(env, 9); /* aeval!* */
    v296 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v295 = stack[-8];
    v295 = list3(stack[0], v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 10); /* aminusp!: */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    if (v295 == nil) goto v145;
    v295 = stack[-9];
    v297 = elt(env, 4); /* plus */
    v296 = v295;
    v295 = (Lisp_Object)17; /* 1 */
    v295 = list3(v297, v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-9] = v295;
    goto v300;

v145:
    v295 = (Lisp_Object)17; /* 1 */
    stack[-7] = v295;
    v295 = (Lisp_Object)1; /* 0 */
    stack[-6] = v295;
    goto v301;

v301:
    stack[0] = elt(env, 2); /* difference */
    v295 = stack[-11];
    fn = elt(env, 9); /* aeval!* */
    v296 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v295 = stack[-7];
    v295 = list3(stack[0], v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 10); /* aminusp!: */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    if (v295 == nil) goto v40;
    v295 = stack[-6];
    v296 = v295;
    v295 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 11); /* evalneq */
    v295 = (*qfn2(fn))(qenv(fn), v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    if (v295 == nil) goto v218;
    stack[0] = elt(env, 1); /* lie_jtest */
    v295 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 9); /* aeval!* */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 8); /* setk */
    v295 = (*qfn2(fn))(qenv(fn), stack[0], v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v297 = elt(env, 2); /* difference */
    v296 = stack[-11];
    v295 = (Lisp_Object)17; /* 1 */
    v295 = list3(v297, v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-12] = v295;
    v295 = stack[-11];
    fn = elt(env, 9); /* aeval!* */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-10] = v295;
    v297 = elt(env, 4); /* plus */
    v296 = stack[-11];
    v295 = (Lisp_Object)17; /* 1 */
    v295 = list3(v297, v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-9] = v295;
    v297 = elt(env, 4); /* plus */
    v296 = stack[-11];
    v295 = (Lisp_Object)17; /* 1 */
    v295 = list3(v297, v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-8] = v295;
    goto v218;

v218:
    v295 = stack[-8];
    v297 = elt(env, 4); /* plus */
    v296 = v295;
    v295 = (Lisp_Object)17; /* 1 */
    v295 = list3(v297, v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-8] = v295;
    goto v45;

v40:
    stack[-5] = elt(env, 4); /* plus */
    stack[-4] = elt(env, 4); /* plus */
    stack[-1] = elt(env, 5); /* times */
    v298 = elt(env, 6); /* lie_cc */
    v297 = stack[-10];
    v296 = stack[-9];
    v295 = stack[-7];
    stack[0] = list4(v298, v297, v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v298 = elt(env, 6); /* lie_cc */
    v297 = stack[-12];
    v296 = stack[-7];
    v295 = stack[-8];
    v295 = list4(v298, v297, v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-3] = list3(stack[-1], stack[0], v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-1] = elt(env, 5); /* times */
    v298 = elt(env, 6); /* lie_cc */
    v297 = stack[-12];
    v296 = stack[-10];
    v295 = stack[-7];
    stack[0] = list4(v298, v297, v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v298 = elt(env, 6); /* lie_cc */
    v297 = stack[-9];
    v296 = stack[-7];
    v295 = stack[-8];
    v295 = list4(v298, v297, v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-2] = list3(stack[-1], stack[0], v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-1] = elt(env, 5); /* times */
    v298 = elt(env, 6); /* lie_cc */
    v297 = stack[-9];
    v296 = stack[-12];
    v295 = stack[-7];
    stack[0] = list4(v298, v297, v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v298 = elt(env, 6); /* lie_cc */
    v297 = stack[-10];
    v296 = stack[-7];
    v295 = stack[-8];
    v295 = list4(v298, v297, v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v295 = list3(stack[-1], stack[0], v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v295 = list4(stack[-4], stack[-3], stack[-2], v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v296 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    v295 = stack[-6];
    v295 = list3(stack[-5], v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-6] = v295;
    v295 = stack[-7];
    v297 = elt(env, 4); /* plus */
    v296 = v295;
    v295 = (Lisp_Object)17; /* 1 */
    v295 = list3(v297, v296, v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    fn = elt(env, 9); /* aeval!* */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-13];
    stack[-7] = v295;
    goto v301;
/* error exit handlers */
v299:
    popv(14);
    return nil;
}



/* Code for rnprep!: */

static Lisp_Object CC_rnprepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v139, v104, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnprep:");
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
    v139 = stack[-1];
    v139 = qcdr(v139);
    v139 = qcar(v139);
    fn = elt(env, 2); /* prepf */
    v139 = (*qfn1(fn))(qenv(fn), v139);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-3];
    v64 = v139;
    v139 = stack[-1];
    v139 = qcdr(v139);
    v104 = qcdr(v139);
    v139 = (Lisp_Object)17; /* 1 */
    if (v104 == v139) { popv(4); return onevalue(v64); }
    stack[-2] = elt(env, 1); /* quotient */
    stack[0] = v64;
    v139 = stack[-1];
    v139 = qcdr(v139);
    v139 = qcdr(v139);
    fn = elt(env, 2); /* prepf */
    v139 = (*qfn1(fn))(qenv(fn), v139);
    nil = C_nil;
    if (exception_pending()) goto v130;
    {
        Lisp_Object v129 = stack[-2];
        Lisp_Object v52 = stack[0];
        popv(4);
        return list3(v129, v52, v139);
    }
/* error exit handlers */
v130:
    popv(4);
    return nil;
}



/* Code for di_insert */

static Lisp_Object MS_CDECL CC_di_insert(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v86,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v44, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "di_insert");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for di_insert");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v86,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v3;
    stack[-2] = v86;
    stack[-3] = v0;
/* end of prologue */

v99:
    v48 = stack[-2];
    if (v48 == nil) goto v97;
    v44 = stack[-3];
    v48 = stack[-2];
    v48 = qcar(v48);
    v48 = qcar(v48);
    fn = elt(env, 2); /* eqdummy */
    v48 = (*qfn2(fn))(qenv(fn), v44, v48);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-5];
    if (v48 == nil) goto v105;
    v48 = qvalue(elt(env, 1)); /* nil */
    stack[-4] = v48;
    v48 = stack[-2];
    v48 = qcdr(v48);
    stack[0] = v48;
    v48 = stack[-2];
    v48 = qcar(v48);
    v115 = qcar(v48);
    v44 = stack[-3];
    v48 = stack[-1];
    v48 = acons(v115, v44, v48);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-5];
    stack[-1] = v48;
    v48 = stack[0];
    stack[-2] = v48;
    v48 = stack[-4];
    stack[-3] = v48;
    goto v99;

v105:
    v48 = stack[-2];
    v48 = qcdr(v48);
    stack[-4] = v48;
    v48 = stack[-2];
    v44 = qcar(v48);
    v48 = stack[-1];
    v48 = cons(v44, v48);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-5];
    stack[-1] = v48;
    v48 = stack[-4];
    stack[-2] = v48;
    goto v99;

v97:
    v48 = stack[-3];
    if (v48 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v44 = stack[-3];
    v115 = qvalue(elt(env, 1)); /* nil */
    v48 = stack[-1];
    popv(6);
    return acons(v44, v115, v48);
/* error exit handlers */
v125:
    popv(6);
    return nil;
}



/* Code for general!-reduce!-degree!-mod!-p */

static Lisp_Object CC_generalKreduceKdegreeKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v86)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169, v216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-reduce-degree-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v86;
    stack[-2] = v0;
/* end of prologue */
    v169 = stack[-2];
    v169 = qcar(v169);
    v216 = qcdr(v169);
    v169 = (Lisp_Object)1; /* 0 */
    if (v216 == v169) goto v119;
    v216 = qvalue(elt(env, 1)); /* current!-modulus */
    v169 = stack[-2];
    v169 = qcar(v169);
    v169 = qcdr(v169);
    v169 = difference2(v216, v169);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    stack[0] = v169;
    goto v98;

v98:
    v169 = stack[-1];
    v169 = qcar(v169);
    v169 = qcdr(v169);
    fn = elt(env, 2); /* general!-modular!-reciprocal */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    fn = elt(env, 3); /* general!-modular!-times */
    v169 = (*qfn2(fn))(qenv(fn), stack[0], v169);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    stack[-3] = v169;
    v169 = stack[-2];
    v169 = qcar(v169);
    v169 = qcar(v169);
    v216 = qcdr(v169);
    v169 = stack[-1];
    v169 = qcar(v169);
    v169 = qcar(v169);
    v169 = qcdr(v169);
    v169 = (Lisp_Object)(int32_t)((int32_t)v216 - (int32_t)v169 + TAG_FIXNUM);
    stack[0] = v169;
    v216 = stack[0];
    v169 = (Lisp_Object)1; /* 0 */
    if (v216 == v169) goto v53;
    v169 = stack[-2];
    stack[-2] = qcdr(v169);
    v169 = stack[-1];
    v169 = qcar(v169);
    v169 = qcar(v169);
    v169 = qcar(v169);
    fn = elt(env, 4); /* fkern */
    v216 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    v169 = stack[0];
    fn = elt(env, 5); /* getpower */
    v216 = (*qfn2(fn))(qenv(fn), v216, v169);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    v169 = stack[-3];
    v216 = cons(v216, v169);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    v169 = stack[-1];
    v169 = qcdr(v169);
    fn = elt(env, 6); /* general!-times!-term!-mod!-p */
    v169 = (*qfn2(fn))(qenv(fn), v216, v169);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    {
        Lisp_Object v236 = stack[-2];
        popv(5);
        fn = elt(env, 7); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v236, v169);
    }

v53:
    v169 = stack[-2];
    stack[0] = qcdr(v169);
    v169 = stack[-1];
    v216 = qcdr(v169);
    v169 = stack[-3];
    fn = elt(env, 8); /* general!-multiply!-by!-constant!-mod!-p */
    v169 = (*qfn2(fn))(qenv(fn), v216, v169);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    {
        Lisp_Object v145 = stack[0];
        popv(5);
        fn = elt(env, 7); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v145, v169);
    }

v119:
    v169 = stack[-2];
    v169 = qcar(v169);
    v169 = qcdr(v169);
    stack[0] = v169;
    goto v98;
/* error exit handlers */
v196:
    popv(5);
    return nil;
}



/* Code for evaluate!-mod!-p */

static Lisp_Object MS_CDECL CC_evaluateKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v86,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v213, v304, v167, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evaluate-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v86,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v3;
    stack[-2] = v86;
    stack[-3] = v0;
/* end of prologue */

v81:
    v212 = stack[-3];
    if (!consp(v212)) goto v126;
    v212 = stack[-3];
    v212 = qcar(v212);
    v212 = (consp(v212) ? nil : lisp_true);
    goto v127;

v127:
    if (!(v212 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v213 = stack[-1];
    v212 = (Lisp_Object)1; /* 0 */
    if (v213 == v212) goto v15;
    v212 = stack[-2];
    if (v212 == nil) goto v120;
    v212 = stack[-3];
    v212 = qcar(v212);
    v212 = qcar(v212);
    v213 = qcar(v212);
    v212 = stack[-2];
    if (equal(v213, v212)) goto v172;
    v212 = stack[-3];
    v212 = qcar(v212);
    stack[-4] = qcar(v212);
    v212 = stack[-3];
    v212 = qcar(v212);
    v304 = qcdr(v212);
    v213 = stack[-2];
    v212 = stack[-1];
    stack[0] = CC_evaluateKmodKp(env, 3, v304, v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    v212 = stack[-3];
    v304 = qcdr(v212);
    v213 = stack[-2];
    v212 = stack[-1];
    v212 = CC_evaluateKmodKp(env, 3, v304, v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    {
        Lisp_Object v141 = stack[-4];
        Lisp_Object v142 = stack[0];
        popv(6);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v141, v142, v212);
    }

v172:
    v212 = stack[-3];
    v212 = qcar(v212);
    v45 = qcdr(v212);
    v212 = stack[-3];
    v212 = qcar(v212);
    v212 = qcar(v212);
    v167 = qcdr(v212);
    v212 = stack[-3];
    v304 = qcdr(v212);
    v213 = stack[-1];
    v212 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* horner!-rule!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 5, v45, v167, v304, v213, v212);
    }

v120:
    v212 = elt(env, 3); /* "Variable=NIL in EVALUATE-MOD-P" */
    {
        popv(6);
        fn = elt(env, 6); /* errorf */
        return (*qfn1(fn))(qenv(fn), v212);
    }

v15:
    v212 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v212;
    goto v81;

v126:
    v212 = qvalue(elt(env, 1)); /* t */
    goto v127;
/* error exit handlers */
v214:
    popv(6);
    return nil;
}



/* Code for outref */

static Lisp_Object MS_CDECL CC_outref(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v86,
                         Lisp_Object v3, Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v305, v215, v214, v141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "outref");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for outref");
#endif
    if (stack >= stacklimit)
    {
        push4(v38,v3,v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v86,v3,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v38;
    stack[-6] = v3;
    stack[-7] = v86;
    stack[-8] = v0;
/* end of prologue */
    stack[-9] = qvalue(elt(env, 1)); /* curfun!* */
    qvalue(elt(env, 1)) = nil; /* curfun!* */
    stack[-4] = qvalue(elt(env, 2)); /* calls!* */
    qvalue(elt(env, 2)) = nil; /* calls!* */
    stack[-3] = qvalue(elt(env, 3)); /* globs!* */
    qvalue(elt(env, 3)) = nil; /* globs!* */
    stack[-2] = qvalue(elt(env, 4)); /* locls!* */
    qvalue(elt(env, 4)) = nil; /* locls!* */
    stack[-1] = qvalue(elt(env, 5)); /* toplv!* */
    qvalue(elt(env, 5)) = nil; /* toplv!* */
    v215 = stack[-7];
    v305 = elt(env, 6); /* (anp!!atom anp!!idb anp!!eq anp!!unknown) */
    v305 = Lmemq(nil, v215, v305);
    if (v305 == nil) goto v75;
    v305 = qvalue(elt(env, 7)); /* nil */
    goto v92;

v92:
    stack[0] = v305;
    v141 = stack[-8];
    v214 = stack[-5];
    v305 = stack[0];
    if (v305 == nil) goto v137;
    v305 = stack[0];
    goto v132;

v132:
    fn = elt(env, 13); /* outrdefun */
    v305 = (*qfnn(fn))(qenv(fn), 3, v141, v214, v305);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-10];
    stack[-8] = v305;
    v305 = stack[0];
    if (v305 == nil) goto v89;
    v305 = stack[-7];
    fn = elt(env, 14); /* add2locs */
    v305 = (*qfn1(fn))(qenv(fn), v305);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-10];
    v305 = stack[-6];
    fn = elt(env, 15); /* anform */
    v305 = (*qfn1(fn))(qenv(fn), v305);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-10];
    v305 = stack[-7];
    fn = elt(env, 16); /* remlocs */
    v305 = (*qfn1(fn))(qenv(fn), v305);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-10];
    goto v140;

v140:
    v305 = stack[-8];
    fn = elt(env, 17); /* outrefend */
    v305 = (*qfn1(fn))(qenv(fn), v305);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-10];
    v305 = nil;
    qvalue(elt(env, 5)) = stack[-1]; /* toplv!* */
    qvalue(elt(env, 4)) = stack[-2]; /* locls!* */
    qvalue(elt(env, 3)) = stack[-3]; /* globs!* */
    qvalue(elt(env, 2)) = stack[-4]; /* calls!* */
    qvalue(elt(env, 1)) = stack[-9]; /* curfun!* */
    { popv(11); return onevalue(v305); }

v89:
    v305 = stack[-6];
    if (v305 == nil) goto v53;
    v305 = stack[-6];
    v305 = Lsymbolp(nil, v305);
    env = stack[-10];
    v305 = (v305 == nil ? lisp_true : nil);
    goto v55;

v55:
    if (!(v305 == nil)) goto v140;
    v215 = stack[-7];
    v305 = elt(env, 10); /* anp!!eq */
    if (v215 == v305) goto v83;
    v305 = stack[-6];
    fn = elt(env, 18); /* add2calls */
    v305 = (*qfn1(fn))(qenv(fn), v305);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-10];
    goto v140;

v83:
    stack[-5] = stack[-8];
    stack[0] = elt(env, 11); /* sameas */
    v305 = stack[-6];
    v305 = ncons(v305);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-10];
    v305 = Lputprop(nil, 3, stack[-5], stack[0], v305);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-10];
    v214 = stack[-6];
    v215 = elt(env, 12); /* alsois */
    v305 = stack[-8];
    fn = elt(env, 19); /* traput */
    v305 = (*qfnn(fn))(qenv(fn), 3, v214, v215, v305);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-10];
    goto v140;

v53:
    v305 = qvalue(elt(env, 9)); /* t */
    goto v55;

v137:
    v215 = stack[-6];
    v305 = elt(env, 8); /* number!-of!-args */
    v305 = get(v215, v305);
    env = stack[-10];
    goto v132;

v75:
    v305 = stack[-7];
    v305 = Llength(nil, v305);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-10];
    goto v92;
/* error exit handlers */
v143:
    env = stack[-10];
    qvalue(elt(env, 5)) = stack[-1]; /* toplv!* */
    qvalue(elt(env, 4)) = stack[-2]; /* locls!* */
    qvalue(elt(env, 3)) = stack[-3]; /* globs!* */
    qvalue(elt(env, 2)) = stack[-4]; /* calls!* */
    qvalue(elt(env, 1)) = stack[-9]; /* curfun!* */
    popv(11);
    return nil;
}



/* Code for tripleisprolongedby */

static Lisp_Object CC_tripleisprolongedby(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v86)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v57;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tripleisprolongedby");
#endif
    if (stack >= stacklimit)
    {
        push2(v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v86;
    v56 = v0;
/* end of prologue */
    v57 = v56;
    v56 = (Lisp_Object)49; /* 3 */
    v56 = *(Lisp_Object *)((char *)v57 + (CELL-TAG_VECTOR) + ((int32_t)v56/(16/CELL)));
    stack[-1] = v56;
    goto v103;

v103:
    v56 = stack[-1];
    v56 = qcar(v56);
    if (v56 == nil) goto v119;
    v56 = stack[-1];
    v57 = qcar(v56);
    v56 = stack[0];
    v56 = (Lisp_Object)greaterp2(v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v106;
    v56 = v56 ? lisp_true : nil;
    env = stack[-2];
    if (v56 == nil) goto v119;
    v56 = stack[-1];
    v56 = qcdr(v56);
    stack[-1] = v56;
    goto v103;

v119:
    v56 = stack[-1];
    v56 = qcar(v56);
    if (v56 == nil) goto v102;
    v56 = stack[-1];
    v57 = qcar(v56);
    v56 = stack[0];
    if (!(equal(v57, v56))) goto v102;
    v56 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v56); }

v102:
    v56 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v56); }
/* error exit handlers */
v106:
    popv(3);
    return nil;
}



/* Code for simpexpt */

static Lisp_Object CC_simpexpt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v129, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpt");
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
    v130 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v130; /* kord!* */
    v130 = stack[0];
    v129 = qcdr(v130);
    v130 = elt(env, 3); /* expt */
    fn = elt(env, 6); /* carx */
    v129 = (*qfn2(fn))(qenv(fn), v129, v130);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    v130 = elt(env, 4); /* simp!* */
    fn = elt(env, 7); /* simpexpon1 */
    v130 = (*qfn2(fn))(qenv(fn), v129, v130);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; /* kord!* */
    v129 = v130;
    v130 = elt(env, 5); /* resimp */
    fn = elt(env, 7); /* simpexpon1 */
    v130 = (*qfn2(fn))(qenv(fn), v129, v130);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-2];
    v129 = stack[0];
    v52 = qcar(v129);
    v129 = v130;
    v130 = qvalue(elt(env, 1)); /* nil */
    {
        popv(3);
        fn = elt(env, 8); /* simpexpt1 */
        return (*qfnn(fn))(qenv(fn), 3, v52, v129, v130);
    }
/* error exit handlers */
v137:
    popv(3);
    return nil;
v100:
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; /* kord!* */
    popv(3);
    return nil;
}



/* Code for get!*elements */

static Lisp_Object CC_getHelements(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v92;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*elements");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v126 = v0;
/* end of prologue */
    v92 = elt(env, 1); /* elems */
    return get(v126, v92);
}



/* Code for qqe_eta!-in!-term */

static Lisp_Object CC_qqe_etaKinKterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_eta-in-term");
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
    v49 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v49;
    v49 = stack[0];
    if (!consp(v49)) goto v61;
    v49 = stack[0];
    fn = elt(env, 3); /* qqe_op */
    v48 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    v49 = elt(env, 2); /* (lhead rhead) */
    v49 = Lmemq(nil, v48, v49);
    if (v49 == nil) goto v75;
    v49 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* qqe_eta!-in!-term1 */
        return (*qfn1(fn))(qenv(fn), v49);
    }

v75:
    v49 = stack[0];
    v49 = qcdr(v49);
    stack[0] = v49;
    goto v21;

v21:
    v49 = stack[0];
    if (v49 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v49 = stack[-1];
    if (!(v49 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v49 = stack[0];
    v49 = qcar(v49);
    if (!consp(v49)) goto v130;
    v49 = stack[0];
    v49 = qcar(v49);
    fn = elt(env, 3); /* qqe_op */
    v48 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    v49 = elt(env, 2); /* (lhead rhead) */
    v49 = Lmemq(nil, v48, v49);
    if (v49 == nil) goto v201;
    v49 = stack[0];
    v49 = qcar(v49);
    fn = elt(env, 4); /* qqe_eta!-in!-term1 */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    stack[-1] = v49;
    goto v130;

v130:
    v49 = stack[0];
    v49 = qcdr(v49);
    stack[0] = v49;
    goto v21;

v201:
    v49 = stack[0];
    v49 = qcar(v49);
    v49 = CC_qqe_etaKinKterm(env, v49);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    stack[-1] = v49;
    goto v130;

v61:
    v49 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v49); }
/* error exit handlers */
v84:
    popv(3);
    return nil;
}



/* Code for sf2ss */

static Lisp_Object CC_sf2ss(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sf2ss");
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
    v116 = stack[-1];
    if (!consp(v116)) goto v127;
    v116 = stack[-1];
    v116 = qcar(v116);
    v116 = (consp(v116) ? nil : lisp_true);
    goto v97;

v97:
    if (!(v116 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v116 = stack[-1];
    fn = elt(env, 2); /* searchpl */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-3];
    stack[-2] = v116;
    v116 = stack[-2];
    fn = elt(env, 3); /* qsort */
    stack[0] = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-3];
    v116 = stack[-2];
    v116 = Llength(nil, v116);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-3];
    v116 = cons(stack[0], v116);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-3];
    stack[0] = v116;
    v123 = stack[-1];
    fn = elt(env, 4); /* sq2sspl */
    v123 = (*qfn2(fn))(qenv(fn), v123, v116);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-3];
    v116 = (Lisp_Object)17; /* 1 */
    v116 = list2star(stack[0], v123, v116);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 5); /* lx2xx */
        return (*qfn1(fn))(qenv(fn), v116);
    }

v127:
    v116 = qvalue(elt(env, 1)); /* t */
    goto v97;
/* error exit handlers */
v128:
    popv(4);
    return nil;
}



/* Code for ibalp_recalcv */

static Lisp_Object CC_ibalp_recalcv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_recalcv");
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
    v51 = v0;
/* end of prologue */
    stack[-2] = v51;
    goto v1;

v1:
    v51 = stack[-2];
    if (v51 == nil) goto v61;
    v51 = stack[-2];
    v51 = qcar(v51);
    stack[-1] = v51;
    v51 = stack[-1];
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    stack[0] = qcdr(v51);
    v51 = stack[-1];
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v165 = qcar(v51);
    v51 = elt(env, 2); /* 0.05 */
    v51 = difference2(v165, v51);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-3];
    fn = elt(env, 3); /* setcar */
    v51 = (*qfn2(fn))(qenv(fn), stack[0], v51);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-3];
    v51 = stack[-1];
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    stack[0] = qcdr(v51);
    v51 = stack[-1];
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v165 = qcar(v51);
    v51 = elt(env, 2); /* 0.05 */
    v51 = difference2(v165, v51);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-3];
    fn = elt(env, 3); /* setcar */
    v51 = (*qfn2(fn))(qenv(fn), stack[0], v51);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-3];
    v51 = stack[-2];
    v51 = qcdr(v51);
    stack[-2] = v51;
    goto v1;

v61:
    v51 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v51); }
/* error exit handlers */
v306:
    popv(4);
    return nil;
}



/* Code for aex_lc */

static Lisp_Object CC_aex_lc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v86)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v132, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_lc");
#endif
    if (stack >= stacklimit)
    {
        push2(v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v67 = v86;
    stack[0] = v0;
/* end of prologue */
    v132 = stack[0];
    fn = elt(env, 2); /* aex_mvaroccurtest */
    v67 = (*qfn2(fn))(qenv(fn), v132, v67);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    if (v67 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v67 = stack[0];
    fn = elt(env, 3); /* aex_ex */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    fn = elt(env, 4); /* ratpoly_lc */
    stack[-1] = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    v67 = stack[0];
    fn = elt(env, 5); /* aex_ctx */
    v139 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    v132 = qvalue(elt(env, 1)); /* nil */
    v67 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v91 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v91, v139, v132, v67);
    }
/* error exit handlers */
v90:
    popv(3);
    return nil;
}



/* Code for !*!*a2s */

static Lisp_Object CC_HHa2s(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v86)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for **a2s");
#endif
    if (stack >= stacklimit)
    {
        push2(v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v114 = v86;
    stack[-3] = v0;
/* end of prologue */
    v114 = stack[-3];
    if (v114 == nil) goto v1;
    v112 = stack[-3];
    v114 = elt(env, 3); /* nochange */
    v114 = Lflagpcar(nil, v112, v114);
    env = stack[-5];
    if (v114 == nil) goto v118;
    v114 = stack[-3];
    v112 = qcar(v114);
    v114 = elt(env, 4); /* getel */
    if (!(v112 == v114)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v118:
    v112 = elt(env, 5); /* random */
    v114 = stack[-3];
    fn = elt(env, 12); /* smember */
    v114 = (*qfn2(fn))(qenv(fn), v112, v114);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    if (v114 == nil) goto v50;
    stack[-4] = elt(env, 6); /* lambda */
    stack[-2] = elt(env, 7); /* (!*uncached) */
    stack[-1] = elt(env, 8); /* progn */
    stack[0] = elt(env, 9); /* (declare (special !*uncached)) */
    v112 = qvalue(elt(env, 10)); /* !*!*a2sfn */
    v114 = stack[-3];
    v114 = list2(v112, v114);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    v114 = list3(stack[-1], stack[0], v114);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    v114 = list3(stack[-4], stack[-2], v114);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    v112 = qvalue(elt(env, 11)); /* t */
    popv(6);
    return list2(v114, v112);

v50:
    v112 = qvalue(elt(env, 10)); /* !*!*a2sfn */
    v114 = stack[-3];
    popv(6);
    return list2(v112, v114);

v1:
    v114 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v114 == nil)) goto v97;
    v114 = elt(env, 2); /* "tell Hearn!!" */
    fn = elt(env, 13); /* lprie */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    goto v97;

v97:
    v114 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v147;
    v114 = nil;
    { popv(6); return onevalue(v114); }
/* error exit handlers */
v147:
    popv(6);
    return nil;
}



/* Code for mchkopt1 */

static Lisp_Object MS_CDECL CC_mchkopt1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v86,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v189, v190, v229;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mchkopt1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mchkopt1");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v86,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v3;
    v189 = v86;
    v190 = v0;
/* end of prologue */
    v189 = qcdr(v189);
    v229 = v189;
    if (v189 == nil) goto v97;
    v189 = v229;
    v189 = qcar(v189);
    stack[-3] = v189;
    v189 = v229;
    v189 = qcdr(v189);
    v229 = v189;
    if (v189 == nil) goto v110;
    v189 = v229;
    v189 = qcar(v189);
    stack[-5] = v189;
    v189 = v229;
    v189 = qcdr(v189);
    if (v189 == nil) goto v64;
    v189 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v189); }

v64:
    v229 = stack[-3];
    v189 = elt(env, 2); /* optional */
    v189 = Lflagp(nil, v229, v189);
    env = stack[-6];
    if (v189 == nil) goto v237;
    v189 = stack[-5];
    fn = elt(env, 3); /* mchk */
    v189 = (*qfn2(fn))(qenv(fn), v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    stack[-5] = v189;
    v189 = stack[-5];
    if (v189 == nil) goto v117;
    v189 = stack[-5];
    v189 = qcar(v189);
    v229 = stack[-3];
    v190 = stack[-4];
    v190 = qcar(v190);
    v189 = acons(v229, v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v189 = ncons(v189);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    stack[-1] = v189;
    stack[-2] = v189;
    goto v172;

v172:
    v189 = stack[-5];
    v189 = qcdr(v189);
    stack[-5] = v189;
    v189 = stack[-5];
    if (v189 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v189 = stack[-5];
    v189 = qcar(v189);
    v229 = stack[-3];
    v190 = stack[-4];
    v190 = qcar(v190);
    v189 = acons(v229, v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v189 = ncons(v189);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v189 = Lrplacd(nil, stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v189 = stack[-1];
    v189 = qcdr(v189);
    stack[-1] = v189;
    goto v172;

v117:
    v189 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v189); }

v237:
    v229 = stack[-5];
    v189 = elt(env, 2); /* optional */
    v189 = Lflagp(nil, v229, v189);
    env = stack[-6];
    if (v189 == nil) goto v239;
    v189 = stack[-3];
    fn = elt(env, 3); /* mchk */
    v189 = (*qfn2(fn))(qenv(fn), v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    stack[-3] = v189;
    v189 = stack[-3];
    if (v189 == nil) goto v307;
    v189 = stack[-3];
    v189 = qcar(v189);
    v229 = stack[-5];
    v190 = stack[-4];
    v190 = qcdr(v190);
    v190 = qcar(v190);
    v189 = acons(v229, v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v189 = ncons(v189);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    stack[-1] = v189;
    stack[-2] = v189;
    goto v196;

v196:
    v189 = stack[-3];
    v189 = qcdr(v189);
    stack[-3] = v189;
    v189 = stack[-3];
    if (v189 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v189 = stack[-3];
    v189 = qcar(v189);
    v229 = stack[-5];
    v190 = stack[-4];
    v190 = qcdr(v190);
    v190 = qcar(v190);
    v189 = acons(v229, v190, v189);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v189 = ncons(v189);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v189 = Lrplacd(nil, stack[0], v189);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v189 = stack[-1];
    v189 = qcdr(v189);
    stack[-1] = v189;
    goto v196;

v307:
    v189 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v189); }

v239:
    v189 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v189); }

v110:
    v189 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v189); }

v97:
    v189 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v189); }
/* error exit handlers */
v74:
    popv(7);
    return nil;
}



/* Code for getdec */

static Lisp_Object CC_getdec(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getdec");
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
    v101 = qvalue(elt(env, 1)); /* nil */
    v111 = stack[0];
    fn = elt(env, 2); /* symtabget */
    v111 = (*qfn2(fn))(qenv(fn), v101, v111);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-1];
    v101 = v111;
    v111 = v101;
    if (!(v111 == nil)) { popv(2); return onevalue(v101); }
    v111 = stack[0];
    fn = elt(env, 3); /* implicitdec */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v136;
    v101 = v111;
    { popv(2); return onevalue(v101); }
/* error exit handlers */
v136:
    popv(2);
    return nil;
}



/* Code for meq */

static Lisp_Object CC_meq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v86)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v21, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for meq");
#endif
    if (stack >= stacklimit)
    {
        push2(v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v86;
    stack[-1] = v0;
/* end of prologue */
    v25 = stack[-1];
    fn = elt(env, 2); /* binding */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-2];
    v21 = v25;
    v25 = v21;
    if (v25 == nil) goto v75;
    v25 = v21;
    v120 = elt(env, 1); /* unbound */
    if (v25 == v120) goto v75;
    v25 = v21;
    v21 = v25;
    goto v99;

v99:
    v25 = stack[0];
    v25 = (equal(v21, v25) ? lisp_true : nil);
    { popv(3); return onevalue(v25); }

v75:
    v25 = stack[-1];
    v21 = v25;
    goto v99;
/* error exit handlers */
v132:
    popv(3);
    return nil;
}



/* Code for dipprodin1 */

static Lisp_Object MS_CDECL CC_dipprodin1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v86,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dipprodin1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipprodin1");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v86,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v86,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v86;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v135;

v135:
    v89 = stack[0];
    if (v89 == nil) goto v92;
    v56 = stack[-1];
    v89 = stack[0];
    v89 = qcar(v89);
    fn = elt(env, 2); /* evsum */
    v56 = (*qfn2(fn))(qenv(fn), v56, v89);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-4];
    v89 = stack[-3];
    v89 = cons(v56, v89);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-4];
    stack[-3] = v89;
    v56 = stack[-2];
    v89 = stack[0];
    v89 = qcdr(v89);
    v89 = qcar(v89);
    fn = elt(env, 3); /* bcprod */
    v56 = (*qfn2(fn))(qenv(fn), v56, v89);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-4];
    v89 = stack[-3];
    v89 = cons(v56, v89);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-4];
    stack[-3] = v89;
    v89 = stack[0];
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    stack[0] = v89;
    goto v135;

v92:
    v56 = stack[-3];
    v89 = qvalue(elt(env, 1)); /* dipzero */
    {
        popv(5);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v56, v89);
    }
/* error exit handlers */
v201:
    popv(5);
    return nil;
}



/* Code for opmtchrevop */

static Lisp_Object CC_opmtchrevop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opmtchrevop");
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
    v104 = qvalue(elt(env, 1)); /* !*val */
    if (v104 == nil) goto v99;
    v64 = elt(env, 3); /* cons */
    v104 = stack[0];
    v104 = Lsmemq(nil, v64, v104);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-2];
    goto v135;

v135:
    if (v104 == nil) goto v94;
    v104 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* opmtch */
        return (*qfn1(fn))(qenv(fn), v104);
    }

v94:
    v104 = stack[0];
    stack[-1] = qcar(v104);
    v104 = stack[0];
    v104 = qcdr(v104);
    fn = elt(env, 5); /* revlis */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-2];
    v104 = cons(stack[-1], v104);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* opmtch */
        return (*qfn1(fn))(qenv(fn), v104);
    }

v99:
    v104 = qvalue(elt(env, 2)); /* t */
    goto v135;
/* error exit handlers */
v118:
    popv(3);
    return nil;
}



setup_type const u17_setup[] =
{
    {"prepsq*",                 CC_prepsqH,     too_many_1,    wrong_no_1},
    {"qqe_ofsf_varlterm",       too_few_2,      CC_qqe_ofsf_varlterm,wrong_no_2},
    {"ibalp_var-unsatlist",     too_few_2,      CC_ibalp_varKunsatlist,wrong_no_2},
    {"ratpoly_nullp",           CC_ratpoly_nullp,too_many_1,   wrong_no_1},
    {"ir2mml",                  CC_ir2mml,      too_many_1,    wrong_no_1},
    {"evalvars",                CC_evalvars,    too_many_1,    wrong_no_1},
    {"doublep",                 CC_doublep,     too_many_1,    wrong_no_1},
    {"equalreval",              CC_equalreval,  too_many_1,    wrong_no_1},
    {"gparg1p",                 CC_gparg1p,     too_many_1,    wrong_no_1},
    {"no-side-effect-listp",    CC_noKsideKeffectKlistp,too_many_1,wrong_no_1},
    {"lengthcdr",               CC_lengthcdr,   too_many_1,    wrong_no_1},
    {"sc_rep",                  CC_sc_rep,      too_many_1,    wrong_no_1},
    {"arplus:",                 too_few_2,      CC_arplusT,    wrong_no_2},
    {"innprodkp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_innprodkp},
    {"formrlis",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formrlis},
    {"triplesetprolongset",     too_few_2,      CC_triplesetprolongset,wrong_no_2},
    {"ofsf_surep",              too_few_2,      CC_ofsf_surep, wrong_no_2},
    {"qremd",                   too_few_2,      CC_qremd,      wrong_no_2},
    {"rndifference:",           too_few_2,      CC_rndifferenceT,wrong_no_2},
    {"token-number",            CC_tokenKnumber,too_many_1,    wrong_no_1},
    {"aex_ids",                 CC_aex_ids,     too_many_1,    wrong_no_1},
    {"gcd2",                    too_few_2,      CC_gcd2,       wrong_no_2},
    {"bcfd",                    CC_bcfd,        too_many_1,    wrong_no_1},
    {"vdpputprop",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpputprop},
    {"coposp",                  CC_coposp,      too_many_1,    wrong_no_1},
    {"b_expand2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_b_expand2},
    {"ratminus",                CC_ratminus,    too_many_1,    wrong_no_1},
    {"refprint",                CC_refprint,    too_many_1,    wrong_no_1},
    {"pasf_anegrel",            CC_pasf_anegrel,too_many_1,    wrong_no_1},
    {"applyrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_applyrd},
    {"xdegreecheck",            CC_xdegreecheck,too_many_1,    wrong_no_1},
    {"testchar1",               CC_testchar1,   too_many_1,    wrong_no_1},
    {":dmtimeslst",             CC_Tdmtimeslst, too_many_1,    wrong_no_1},
    {"physopsm*",               CC_physopsmH,   too_many_1,    wrong_no_1},
    {"def_edge",                too_few_2,      CC_def_edge,   wrong_no_2},
    {"lienjactest",             CC_lienjactest, too_many_1,    wrong_no_1},
    {"rnprep:",                 CC_rnprepT,     too_many_1,    wrong_no_1},
    {"di_insert",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_di_insert},
    {"general-reduce-degree-mod-p",too_few_2,   CC_generalKreduceKdegreeKmodKp,wrong_no_2},
    {"evaluate-mod-p",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_evaluateKmodKp},
    {"outref",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_outref},
    {"tripleisprolongedby",     too_few_2,      CC_tripleisprolongedby,wrong_no_2},
    {"simpexpt",                CC_simpexpt,    too_many_1,    wrong_no_1},
    {"get*elements",            CC_getHelements,too_many_1,    wrong_no_1},
    {"qqe_eta-in-term",         CC_qqe_etaKinKterm,too_many_1, wrong_no_1},
    {"sf2ss",                   CC_sf2ss,       too_many_1,    wrong_no_1},
    {"ibalp_recalcv",           CC_ibalp_recalcv,too_many_1,   wrong_no_1},
    {"aex_lc",                  too_few_2,      CC_aex_lc,     wrong_no_2},
    {"**a2s",                   too_few_2,      CC_HHa2s,      wrong_no_2},
    {"mchkopt1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mchkopt1},
    {"getdec",                  CC_getdec,      too_many_1,    wrong_no_1},
    {"meq",                     too_few_2,      CC_meq,        wrong_no_2},
    {"dipprodin1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipprodin1},
    {"opmtchrevop",             CC_opmtchrevop, too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u17", (two_args *)"21651 3358858 8313171", 0}
};

/* end of generated code */
