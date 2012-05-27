
/* $destdir\u18.c        Machine generated C code */

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


/* Code for ordop2 */

static Lisp_Object CC_ordop2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v10, v11, v12, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordop2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v12 = v1;
    v13 = v0;
/* end of prologue */
    v9 = qvalue(elt(env, 1)); /* kord!* */
    v11 = v9;
    goto v14;

v14:
    v9 = v11;
    if (v9 == nil) goto v15;
    v10 = v13;
    v9 = v11;
    v9 = qcar(v9);
    if (v10 == v9) goto v16;
    v10 = v12;
    v9 = v11;
    v9 = qcar(v9);
    if (v10 == v9) goto v17;
    v9 = v11;
    v9 = qcdr(v9);
    v11 = v9;
    goto v14;

v17:
    v9 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v9);

v16:
    v9 = qvalue(elt(env, 2)); /* t */
    return onevalue(v9);

v15:
    v9 = v13;
    v10 = v12;
    {
        fn = elt(env, 4); /* ordp */
        return (*qfn2(fn))(qenv(fn), v9, v10);
    }
}



/* Code for contr */

static Lisp_Object CC_contr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contr");
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
    goto v14;

v14:
    v20 = stack[0];
    if (v20 == nil) goto v22;
    v21 = stack[-1];
    v20 = stack[0];
    v20 = qcar(v20);
    fn = elt(env, 1); /* split!-road */
    v21 = (*qfn2(fn))(qenv(fn), v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-3];
    v20 = stack[-2];
    v20 = cons(v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-3];
    stack[-2] = v20;
    v20 = stack[0];
    v20 = qcdr(v20);
    stack[0] = v20;
    goto v14;

v22:
    v20 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v20);
    }
/* error exit handlers */
v2:
    popv(4);
    return nil;
}



/* Code for setelv */

static Lisp_Object CC_setelv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setelv");
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
    stack[-4] = v1;
    v30 = v0;
/* end of prologue */
    v29 = v30;
    stack[-5] = qcar(v29);
    v29 = v30;
    v29 = qcdr(v29);
    stack[-3] = v29;
    v29 = stack[-3];
    if (v29 == nil) goto v31;
    v29 = stack[-3];
    v29 = qcar(v29);
    fn = elt(env, 2); /* reval_without_mod */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    v29 = ncons(v29);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    stack[-1] = v29;
    stack[-2] = v29;
    goto v18;

v18:
    v29 = stack[-3];
    v29 = qcdr(v29);
    stack[-3] = v29;
    v29 = stack[-3];
    if (v29 == nil) goto v3;
    stack[0] = stack[-1];
    v29 = stack[-3];
    v29 = qcar(v29);
    fn = elt(env, 2); /* reval_without_mod */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    v29 = ncons(v29);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    v29 = Lrplacd(nil, stack[0], v29);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    v29 = stack[-1];
    v29 = qcdr(v29);
    stack[-1] = v29;
    goto v18;

v3:
    v29 = stack[-2];
    goto v33;

v33:
    v30 = cons(stack[-5], v29);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    v29 = stack[-4];
    {
        popv(7);
        fn = elt(env, 3); /* setel */
        return (*qfn2(fn))(qenv(fn), v30, v29);
    }

v31:
    v29 = qvalue(elt(env, 1)); /* nil */
    goto v33;
/* error exit handlers */
v32:
    popv(7);
    return nil;
}



/* Code for fs!:times */

static Lisp_Object CC_fsTtimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:times");
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
    v12 = stack[-1];
    if (v12 == nil) goto v39;
    v12 = stack[0];
    if (v12 == nil) goto v22;
    v13 = stack[-1];
    v12 = stack[0];
    fn = elt(env, 2); /* fs!:timesterm */
    v12 = (*qfn2(fn))(qenv(fn), v13, v12);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    stack[-2] = v12;
    v13 = stack[-1];
    v12 = (Lisp_Object)49; /* 3 */
    v13 = *(Lisp_Object *)((char *)v13 + (CELL-TAG_VECTOR) + ((int32_t)v12/(16/CELL)));
    v12 = stack[0];
    v12 = CC_fsTtimes(env, v13, v12);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    {
        Lisp_Object v41 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v41, v12);
    }

v22:
    v12 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v12); }

v39:
    v12 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v12); }
/* error exit handlers */
v40:
    popv(4);
    return nil;
}



/* Code for dpmat_coldegs */

static Lisp_Object CC_dpmat_coldegs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dpmat_coldegs");
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
    v43 = v0;
/* end of prologue */
    v44 = v43;
    v43 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 1); /* pnth */
    v43 = (*qfn2(fn))(qenv(fn), v44, v43);
    errexit();
    v43 = qcar(v43);
    return onevalue(v43);
}



/* Code for st_consolidate */

static Lisp_Object CC_st_consolidate(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_consolidate");
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
    stack[-1] = nil;
    v58 = stack[-3];
    if (v58 == nil) goto v22;
    v58 = stack[-3];
    v58 = qcdr(v58);
    v58 = qcar(v58);
    if (is_number(v58)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v58 = qvalue(elt(env, 2)); /* t */
    stack[-2] = v58;
    v58 = stack[-3];
    v58 = qcdr(v58);
    v58 = Lreverse(nil, v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    stack[0] = v58;
    goto v38;

v38:
    v58 = stack[0];
    if (v58 == nil) goto v37;
    v58 = stack[0];
    v58 = qcar(v58);
    v58 = CC_st_consolidate(env, v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    v59 = v58;
    if (v59 == nil) goto v3;
    v59 = v58;
    v59 = qcdr(v59);
    v59 = qcdr(v59);
    if (v59 == nil) goto v61;
    v59 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v59;
    goto v62;

v62:
    v59 = v58;
    v58 = stack[-1];
    v58 = cons(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    stack[-1] = v58;
    goto v3;

v3:
    v58 = stack[0];
    v58 = qcdr(v58);
    stack[0] = v58;
    goto v38;

v61:
    v59 = elt(env, 3); /* !* */
    v58 = qcdr(v58);
    v58 = qcar(v58);
    v58 = list2(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    goto v62;

v37:
    v58 = stack[-1];
    if (v58 == nil) goto v63;
    v58 = stack[-1];
    v58 = qcdr(v58);
    if (v58 == nil) goto v64;
    v58 = stack[-2];
    if (v58 == nil) goto v65;
    v58 = stack[-1];
    stack[-4] = v58;
    v58 = stack[-4];
    if (v58 == nil) goto v66;
    v58 = stack[-4];
    v58 = qcar(v58);
    v58 = qcdr(v58);
    v58 = qcar(v58);
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    stack[-1] = v58;
    stack[-2] = v58;
    goto v67;

v67:
    v58 = stack[-4];
    v58 = qcdr(v58);
    stack[-4] = v58;
    v58 = stack[-4];
    if (v58 == nil) goto v68;
    stack[0] = stack[-1];
    v58 = stack[-4];
    v58 = qcar(v58);
    v58 = qcdr(v58);
    v58 = qcar(v58);
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    v58 = Lrplacd(nil, stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    v58 = stack[-1];
    v58 = qcdr(v58);
    stack[-1] = v58;
    goto v67;

v68:
    v58 = stack[-2];
    goto v69;

v69:
    stack[-1] = v58;
    goto v65;

v65:
    v58 = stack[-3];
    v59 = qcar(v58);
    v58 = stack[-1];
    popv(6);
    return cons(v59, v58);

v66:
    v58 = qvalue(elt(env, 1)); /* nil */
    goto v69;

v64:
    v58 = stack[-1];
    v58 = qcar(v58);
    { popv(6); return onevalue(v58); }

v63:
    v58 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v58); }

v22:
    v58 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v58); }
/* error exit handlers */
v60:
    popv(6);
    return nil;
}



/* Code for reducepowers */

static Lisp_Object CC_reducepowers(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reducepowers");
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

v56:
    v83 = stack[0];
    if (!consp(v83)) goto v36;
    v83 = stack[0];
    v83 = qcar(v83);
    v83 = (consp(v83) ? nil : lisp_true);
    goto v15;

v15:
    if (v83 == nil) goto v5;
    v83 = qvalue(elt(env, 1)); /* t */
    goto v84;

v84:
    if (!(v83 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v83 = stack[0];
    v83 = qcar(v83);
    v83 = qcar(v83);
    v48 = qcdr(v83);
    v83 = qvalue(elt(env, 2)); /* repowl!* */
    v83 = qcar(v83);
    v83 = qcdr(v83);
    if (equal(v48, v83)) goto v30;
    v83 = stack[0];
    v83 = qcar(v83);
    v83 = qcar(v83);
    stack[-1] = qcar(v83);
    v83 = stack[0];
    v83 = qcar(v83);
    v83 = qcar(v83);
    v48 = qcdr(v83);
    v83 = qvalue(elt(env, 2)); /* repowl!* */
    v83 = qcar(v83);
    v83 = qcdr(v83);
    v48 = difference2(v48, v83);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v83 = (Lisp_Object)17; /* 1 */
    v83 = acons(stack[-1], v48, v83);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v48 = ncons(v83);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v83 = stack[0];
    v83 = qcar(v83);
    v83 = qcdr(v83);
    fn = elt(env, 3); /* multf */
    v48 = (*qfn2(fn))(qenv(fn), v48, v83);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v83 = qvalue(elt(env, 2)); /* repowl!* */
    v83 = qcdr(v83);
    fn = elt(env, 3); /* multf */
    v48 = (*qfn2(fn))(qenv(fn), v48, v83);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v83 = stack[0];
    v83 = qcdr(v83);
    fn = elt(env, 4); /* addf */
    v83 = (*qfn2(fn))(qenv(fn), v48, v83);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    stack[0] = v83;
    goto v56;

v30:
    v83 = qvalue(elt(env, 2)); /* repowl!* */
    v48 = qcdr(v83);
    v83 = stack[0];
    v83 = qcar(v83);
    v83 = qcdr(v83);
    fn = elt(env, 3); /* multf */
    v48 = (*qfn2(fn))(qenv(fn), v48, v83);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v83 = stack[0];
    v83 = qcdr(v83);
    {
        popv(3);
        fn = elt(env, 4); /* addf */
        return (*qfn2(fn))(qenv(fn), v48, v83);
    }

v5:
    v83 = stack[0];
    v83 = qcar(v83);
    v83 = qcar(v83);
    v48 = qcdr(v83);
    v83 = qvalue(elt(env, 2)); /* repowl!* */
    v83 = qcar(v83);
    v83 = qcdr(v83);
    v83 = (Lisp_Object)lessp2(v48, v83);
    nil = C_nil;
    if (exception_pending()) goto v85;
    v83 = v83 ? lisp_true : nil;
    env = stack[-2];
    goto v84;

v36:
    v83 = qvalue(elt(env, 1)); /* t */
    goto v15;
/* error exit handlers */
v85:
    popv(3);
    return nil;
}



/* Code for general!-evaluate!-mod!-p */

static Lisp_Object MS_CDECL CC_generalKevaluateKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v53, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v93, v94, v95, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "general-evaluate-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-evaluate-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v53,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v53);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v53;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v14:
    v92 = stack[-3];
    if (!consp(v92)) goto v33;
    v92 = stack[-3];
    v92 = qcar(v92);
    v92 = (consp(v92) ? nil : lisp_true);
    goto v44;

v44:
    if (!(v92 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v93 = stack[-1];
    v92 = (Lisp_Object)1; /* 0 */
    if (v93 == v92) goto v97;
    v92 = stack[-2];
    if (v92 == nil) goto v34;
    v92 = stack[-3];
    v92 = qcar(v92);
    v92 = qcar(v92);
    v93 = qcar(v92);
    v92 = stack[-2];
    if (equal(v93, v92)) goto v25;
    v92 = stack[-3];
    v92 = qcar(v92);
    stack[-4] = qcar(v92);
    v92 = stack[-3];
    v92 = qcar(v92);
    v94 = qcdr(v92);
    v93 = stack[-2];
    v92 = stack[-1];
    stack[0] = CC_generalKevaluateKmodKp(env, 3, v94, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-5];
    v92 = stack[-3];
    v94 = qcdr(v92);
    v93 = stack[-2];
    v92 = stack[-1];
    v92 = CC_generalKevaluateKmodKp(env, 3, v94, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-5];
    {
        Lisp_Object v99 = stack[-4];
        Lisp_Object v75 = stack[0];
        popv(6);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v99, v75, v92);
    }

v25:
    v92 = stack[-3];
    v92 = qcar(v92);
    v96 = qcdr(v92);
    v92 = stack[-3];
    v92 = qcar(v92);
    v92 = qcar(v92);
    v95 = qcdr(v92);
    v92 = stack[-3];
    v94 = qcdr(v92);
    v93 = stack[-1];
    v92 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* general!-horner!-rule!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 5, v96, v95, v94, v93, v92);
    }

v34:
    v92 = elt(env, 3); /* "Variable=NIL in GENERAL-EVALUATE-MOD-P" */
    {
        popv(6);
        fn = elt(env, 6); /* errorf */
        return (*qfn1(fn))(qenv(fn), v92);
    }

v97:
    v92 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v92;
    goto v14;

v33:
    v92 = qvalue(elt(env, 1)); /* t */
    goto v44;
/* error exit handlers */
v98:
    popv(6);
    return nil;
}



/* Code for mkfil!* */

static Lisp_Object CC_mkfilH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v57, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkfil*");
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
    v101 = nil;
    v100 = stack[0];
    v100 = Lstringp(nil, v100);
    env = stack[-2];
    if (!(v100 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v100 = stack[0];
    if (symbolp(v100)) goto v6;
    v57 = stack[0];
    v100 = elt(env, 1); /* "file name" */
    {
        popv(3);
        fn = elt(env, 6); /* typerr */
        return (*qfn2(fn))(qenv(fn), v57, v100);
    }

v6:
    v57 = stack[0];
    v100 = elt(env, 2); /* share */
    v100 = Lflagp(nil, v57, v100);
    env = stack[-2];
    if (v100 == nil) goto v102;
    v100 = stack[0];
    fn = elt(env, 7); /* eval */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-2];
    v101 = v100;
    v100 = Lstringp(nil, v100);
    env = stack[-2];
    goto v103;

v103:
    if (!(v100 == nil)) { popv(3); return onevalue(v101); }
    stack[-1] = elt(env, 4); /* !" */
    v100 = stack[0];
    fn = elt(env, 8); /* explode2lc */
    v57 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-2];
    v100 = elt(env, 5); /* (!") */
    v100 = Lappend(nil, v57, v100);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-2];
    v100 = cons(stack[-1], v100);
    nil = C_nil;
    if (exception_pending()) goto v81;
        popv(3);
        return Lcompress(nil, v100);

v102:
    v100 = qvalue(elt(env, 3)); /* nil */
    goto v103;
/* error exit handlers */
v81:
    popv(3);
    return nil;
}



/* Code for rl_bestgaussp */

static Lisp_Object CC_rl_bestgaussp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_bestgaussp");
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
    v43 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_bestgaussp!* */
    v43 = ncons(v43);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    {
        Lisp_Object v15 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v15, v43);
    }
/* error exit handlers */
v33:
    popv(2);
    return nil;
}



/* Code for mkpartitions1 */

static Lisp_Object MS_CDECL CC_mkpartitions1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v53, Lisp_Object v4,
                         Lisp_Object v56, Lisp_Object v39, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v48, v49, v116;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "mkpartitions1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkpartitions1");
#endif
    if (stack >= stacklimit)
    {
        push6(v39,v56,v4,v53,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v53,v4,v56,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v39;
    stack[-4] = v56;
    stack[-5] = v4;
    stack[-6] = v53;
    stack[-7] = v1;
    stack[-8] = v0;
/* end of prologue */

v28:
    v48 = stack[-7];
    v83 = (Lisp_Object)17; /* 1 */
    if (v48 == v83) goto v6;
    v48 = stack[-6];
    v83 = stack[-5];
    v83 = (Lisp_Object)greaterp2(v48, v83);
    nil = C_nil;
    if (exception_pending()) goto v117;
    v83 = v83 ? lisp_true : nil;
    env = stack[-10];
    if (!(v83 == nil)) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    v48 = stack[-8];
    v83 = stack[-6];
    v83 = difference2(v48, v83);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-10];
    stack[-9] = v83;
    v83 = stack[-7];
    v83 = sub1(v83);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-10];
    stack[-2] = v83;
    v48 = stack[-8];
    v83 = stack[-6];
    stack[0] = difference2(v48, v83);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-10];
    v83 = stack[-7];
    v83 = sub1(v83);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-10];
    v83 = quot2(stack[0], v83);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-10];
    stack[-1] = v83;
    v48 = stack[-6];
    v83 = stack[-4];
    v83 = cons(v48, v83);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-10];
    stack[0] = v83;
    v83 = stack[-6];
    v116 = add1(v83);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-10];
    v49 = stack[-5];
    v48 = stack[-4];
    v83 = stack[-3];
    v83 = CC_mkpartitions1(env, 6, stack[-8], stack[-7], v116, v49, v48, v83);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-10];
    stack[-3] = v83;
    v83 = stack[0];
    stack[-4] = v83;
    v83 = stack[-1];
    stack[-5] = v83;
    v83 = stack[-2];
    stack[-7] = v83;
    v83 = stack[-9];
    stack[-8] = v83;
    goto v28;

v6:
    v48 = stack[-8];
    v83 = stack[-6];
    v83 = (Lisp_Object)geq2(v48, v83);
    nil = C_nil;
    if (exception_pending()) goto v117;
    v83 = v83 ? lisp_true : nil;
    env = stack[-10];
    if (v83 == nil) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    v48 = stack[-8];
    v83 = stack[-4];
    v83 = cons(v48, v83);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-10];
    v48 = Lreverse(nil, v83);
    nil = C_nil;
    if (exception_pending()) goto v117;
    v83 = stack[-3];
    popv(11);
    return cons(v48, v83);
/* error exit handlers */
v117:
    popv(11);
    return nil;
}



/* Code for tayexp!-times2 */

static Lisp_Object CC_tayexpKtimes2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v129, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-times2");
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
    v128 = stack[-1];
    if (!consp(v128)) goto v22;
    v128 = qvalue(elt(env, 1)); /* nil */
    goto v42;

v42:
    if (v128 == nil) goto v38;
    v129 = stack[-1];
    v128 = stack[0];
    popv(4);
    return times2(v129, v128);

v38:
    v128 = stack[-1];
    if (!consp(v128)) goto v34;
    v128 = stack[0];
    if (!consp(v128)) goto v131;
    v128 = stack[-1];
    v128 = qcdr(v128);
    v129 = qcar(v128);
    v128 = stack[0];
    v128 = qcdr(v128);
    v128 = qcar(v128);
    stack[-2] = times2(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    v128 = stack[-1];
    v128 = qcdr(v128);
    v129 = qcdr(v128);
    v128 = stack[0];
    v128 = qcdr(v128);
    v128 = qcdr(v128);
    v128 = times2(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    fn = elt(env, 3); /* mkrn */
    v128 = (*qfn2(fn))(qenv(fn), stack[-2], v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    goto v5;

v5:
    v130 = v128;
    v128 = v130;
    v128 = qcdr(v128);
    v129 = qcdr(v128);
    v128 = (Lisp_Object)17; /* 1 */
    if (!(v129 == v128)) { popv(4); return onevalue(v130); }
    v128 = v130;
    v128 = qcdr(v128);
    v128 = qcar(v128);
    { popv(4); return onevalue(v128); }

v131:
    v130 = elt(env, 2); /* !:rn!: */
    v129 = stack[0];
    v128 = (Lisp_Object)17; /* 1 */
    v128 = list2star(v130, v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    stack[-2] = v128;
    v128 = stack[-1];
    v128 = qcdr(v128);
    v129 = qcar(v128);
    v128 = stack[-2];
    v128 = qcdr(v128);
    v128 = qcar(v128);
    stack[0] = times2(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    v128 = stack[-1];
    v128 = qcdr(v128);
    v129 = qcdr(v128);
    v128 = stack[-2];
    v128 = qcdr(v128);
    v128 = qcdr(v128);
    v128 = times2(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    fn = elt(env, 3); /* mkrn */
    v128 = (*qfn2(fn))(qenv(fn), stack[0], v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    goto v5;

v34:
    v130 = elt(env, 2); /* !:rn!: */
    v129 = stack[-1];
    v128 = (Lisp_Object)17; /* 1 */
    v128 = list2star(v130, v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    stack[-2] = v128;
    v128 = stack[-2];
    v128 = qcdr(v128);
    v129 = qcar(v128);
    v128 = stack[0];
    v128 = qcdr(v128);
    v128 = qcar(v128);
    stack[-1] = times2(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    v128 = stack[-2];
    v128 = qcdr(v128);
    v129 = qcdr(v128);
    v128 = stack[0];
    v128 = qcdr(v128);
    v128 = qcdr(v128);
    v128 = times2(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    fn = elt(env, 3); /* mkrn */
    v128 = (*qfn2(fn))(qenv(fn), stack[-1], v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    goto v5;

v22:
    v128 = stack[0];
    v128 = (consp(v128) ? nil : lisp_true);
    goto v42;
/* error exit handlers */
v132:
    popv(4);
    return nil;
}



/* Code for ibalp_negateat */

static Lisp_Object CC_ibalp_negateat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_negateat");
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
    v27 = stack[-1];
    fn = elt(env, 1); /* ibalp_op */
    stack[-2] = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    v27 = stack[-1];
    fn = elt(env, 2); /* ibalp_arg2l */
    stack[0] = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    v27 = stack[-1];
    fn = elt(env, 3); /* ibalp_arg2r */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    fn = elt(env, 4); /* ibalp_negatet */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    {
        Lisp_Object v18 = stack[-2];
        Lisp_Object v97 = stack[0];
        popv(4);
        fn = elt(env, 5); /* ibalp_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v18, v97, v27);
    }
/* error exit handlers */
v16:
    popv(4);
    return nil;
}



/* Code for cgp_number */

static Lisp_Object CC_cgp_number(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_number");
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
    v43 = v0;
/* end of prologue */
    v44 = v43;
    v43 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 1); /* pnth */
    v43 = (*qfn2(fn))(qenv(fn), v44, v43);
    errexit();
    v43 = qcar(v43);
    return onevalue(v43);
}



/* Code for crprimp */

static Lisp_Object CC_crprimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v9, v10;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crprimp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v10 = v0;
/* end of prologue */
    v9 = v10;
    v35 = (Lisp_Object)17; /* 1 */
    if (v9 == v35) goto v56;
    v9 = v10;
    v35 = (Lisp_Object)-15; /* -1 */
    if (v9 == v35) goto v37;
    v35 = elt(env, 3); /* times */
    v9 = v10;
    v10 = elt(env, 1); /* i */
    return list3(v35, v9, v10);

v37:
    v35 = elt(env, 2); /* minus */
    v9 = elt(env, 1); /* i */
    return list2(v35, v9);

v56:
    v35 = elt(env, 1); /* i */
    return onevalue(v35);
}



/* Code for pfordp */

static Lisp_Object CC_pfordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v135, v126, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pfordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v135 = v1;
    v126 = v0;
/* end of prologue */

v39:
    v61 = v126;
    if (v61 == nil) goto v42;
    v61 = v135;
    if (v61 == nil) goto v24;
    v61 = v126;
    v61 = qcar(v61);
    v136 = qcar(v61);
    v61 = v135;
    v61 = qcar(v61);
    v61 = qcar(v61);
    if (v136 == v61) goto v114;
    v61 = v126;
    v61 = qcar(v61);
    v61 = qcar(v61);
    v135 = qcar(v135);
    v135 = qcar(v135);
    {
        fn = elt(env, 2); /* termordp */
        return (*qfn2(fn))(qenv(fn), v61, v135);
    }

v114:
    v61 = v126;
    v61 = qcdr(v61);
    v126 = v61;
    v61 = v135;
    v61 = qcdr(v61);
    v135 = v61;
    goto v39;

v24:
    v61 = v126;
    v61 = qcar(v61);
    v135 = qcar(v61);
    v61 = (Lisp_Object)17; /* 1 */
        return Lneq(nil, v135, v61);

v42:
    v61 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v61);
}



/* Code for r2findindex */

static Lisp_Object CC_r2findindex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v36, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2findindex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v1;
    v36 = v0;
/* end of prologue */
    v24 = v36;
    v36 = v15;
    v15 = (Lisp_Object)17; /* 1 */
    {
        fn = elt(env, 1); /* r2findindex1 */
        return (*qfnn(fn))(qenv(fn), 3, v24, v36, v15);
    }
}



/* Code for inttovec!-solve */

static Lisp_Object CC_inttovecKsolve(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v124;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inttovec-solve");
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
    v124 = stack[-2];
    v107 = (Lisp_Object)1; /* 0 */
    if (v124 == v107) goto v22;
    v124 = stack[-3];
    v107 = (Lisp_Object)17; /* 1 */
    v107 = (v124 == v107 ? lisp_true : nil);
    goto v42;

v42:
    if (v107 == nil) goto v134;
    v124 = stack[-2];
    v107 = (Lisp_Object)1; /* 0 */
    popv(6);
    return cons(v124, v107);

v134:
    v107 = (Lisp_Object)1; /* 0 */
    stack[-4] = v107;
    v107 = (Lisp_Object)17; /* 1 */
    stack[0] = v107;
    goto v12;

v12:
    v107 = stack[0];
    stack[-1] = v107;
    v107 = stack[-4];
    v107 = add1(v107);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-5];
    stack[-4] = v107;
    v124 = stack[-3];
    v107 = stack[-4];
    v124 = plus2(v124, v107);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-5];
    v107 = stack[-1];
    v124 = times2(v124, v107);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-5];
    v107 = stack[-4];
    v107 = quot2(v124, v107);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-5];
    stack[0] = v107;
    v124 = stack[0];
    v107 = stack[-2];
    v107 = (Lisp_Object)greaterp2(v124, v107);
    nil = C_nil;
    if (exception_pending()) goto v88;
    v107 = v107 ? lisp_true : nil;
    env = stack[-5];
    if (v107 == nil) goto v12;
    stack[0] = stack[-4];
    v124 = stack[-2];
    v107 = stack[-1];
    v107 = difference2(v124, v107);
    nil = C_nil;
    if (exception_pending()) goto v88;
    {
        Lisp_Object v89 = stack[0];
        popv(6);
        return cons(v89, v107);
    }

v22:
    v107 = qvalue(elt(env, 1)); /* t */
    goto v42;
/* error exit handlers */
v88:
    popv(6);
    return nil;
}



/* Code for rd!:times */

static Lisp_Object CC_rdTtimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v151, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:times");
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
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v150 = qvalue(elt(env, 1)); /* nil */
    v151 = v150;
    v150 = qvalue(elt(env, 2)); /* !*!*roundbf */
    if (v150 == nil) goto v43;
    v150 = qvalue(elt(env, 1)); /* nil */
    goto v84;

v84:
    if (v150 == nil) goto v23;
    v150 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v150, v151);

v23:
    v151 = stack[-1];
    v150 = stack[0];
    fn = elt(env, 8); /* convprc2 */
    v150 = (*qfn2(fn))(qenv(fn), v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    stack[-3] = v150;
    v150 = qvalue(elt(env, 4)); /* yy!! */
    stack[-2] = v150;
    v150 = stack[-3];
    if (!consp(v150)) goto v110;
    v151 = stack[-3];
    v150 = stack[-2];
    fn = elt(env, 9); /* csl_timbf */
    v150 = (*qfn2(fn))(qenv(fn), v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    goto v32;

v32:
    v151 = v150;
    v150 = v151;
    if (!(!consp(v150))) { popv(5); return onevalue(v151); }
    v150 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v150, v151);

v110:
    stack[-1] = elt(env, 5); /* times2 */
    v150 = stack[-3];
    stack[0] = Lmkquote(nil, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    v150 = stack[-2];
    v150 = Lmkquote(nil, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    v152 = list3(stack[-1], stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    v151 = qvalue(elt(env, 1)); /* nil */
    v150 = qvalue(elt(env, 6)); /* !*backtrace */
    fn = elt(env, 10); /* errorset */
    v150 = (*qfnn(fn))(qenv(fn), 3, v152, v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    v151 = v150;
    v150 = v151;
    if (!consp(v150)) goto v93;
    v150 = v151;
    v150 = qcdr(v150);
    goto v92;

v92:
    if (v150 == nil) goto v154;
    fn = elt(env, 11); /* rndbfon */
    v150 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    v150 = stack[-3];
    v150 = Lfloatp(nil, v150);
    env = stack[-4];
    if (v150 == nil) goto v122;
    v150 = stack[-3];
    fn = elt(env, 12); /* fl2bf */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    stack[0] = v150;
    goto v155;

v155:
    v150 = stack[-2];
    v150 = Lfloatp(nil, v150);
    env = stack[-4];
    if (v150 == nil) goto v128;
    v150 = stack[-2];
    fn = elt(env, 12); /* fl2bf */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    goto v73;

v73:
    fn = elt(env, 9); /* csl_timbf */
    v150 = (*qfn2(fn))(qenv(fn), stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    goto v32;

v128:
    v150 = stack[-2];
    if (!consp(v150)) goto v132;
    v150 = stack[-2];
    goto v156;

v156:
    fn = elt(env, 13); /* csl_normbf */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    goto v73;

v132:
    v150 = stack[-2];
    v150 = integerp(v150);
    if (v150 == nil) goto v157;
    v152 = elt(env, 3); /* !:rd!: */
    v151 = stack[-2];
    v150 = (Lisp_Object)1; /* 0 */
    v150 = list2star(v152, v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    goto v156;

v157:
    v150 = stack[-2];
    fn = elt(env, 14); /* read!:num */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    goto v156;

v122:
    v150 = stack[-3];
    if (!consp(v150)) goto v158;
    v150 = stack[-3];
    goto v120;

v120:
    fn = elt(env, 13); /* csl_normbf */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    stack[0] = v150;
    goto v155;

v158:
    v150 = stack[-3];
    v150 = integerp(v150);
    if (v150 == nil) goto v159;
    v152 = elt(env, 3); /* !:rd!: */
    v151 = stack[-3];
    v150 = (Lisp_Object)1; /* 0 */
    v150 = list2star(v152, v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    goto v120;

v159:
    v150 = stack[-3];
    fn = elt(env, 14); /* read!:num */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    goto v120;

v154:
    v150 = v151;
    v150 = qcar(v150);
    goto v32;

v93:
    v150 = qvalue(elt(env, 7)); /* t */
    goto v92;

v43:
    v150 = stack[-1];
    v150 = qcdr(v150);
    if (!consp(v150)) goto v24;
    v150 = qvalue(elt(env, 1)); /* nil */
    goto v84;

v24:
    v150 = stack[0];
    v150 = qcdr(v150);
    if (!consp(v150)) goto v31;
    v150 = qvalue(elt(env, 1)); /* nil */
    goto v84;

v31:
    v150 = stack[-1];
    v151 = qcdr(v150);
    v150 = stack[0];
    v150 = qcdr(v150);
    fn = elt(env, 15); /* safe!-fp!-times */
    v150 = (*qfn2(fn))(qenv(fn), v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-4];
    v151 = v150;
    goto v84;
/* error exit handlers */
v153:
    popv(5);
    return nil;
}



/* Code for factorial */

static Lisp_Object CC_factorial(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for factorial");
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
    v11 = stack[0];
    v11 = integerp(v11);
    if (v11 == nil) goto v42;
    v12 = stack[0];
    v11 = (Lisp_Object)1; /* 0 */
    v11 = (Lisp_Object)lessp2(v12, v11);
    nil = C_nil;
    if (exception_pending()) goto v114;
    v11 = v11 ? lisp_true : nil;
    env = stack[-1];
    goto v115;

v115:
    if (v11 == nil) goto v113;
    v12 = stack[0];
    v11 = elt(env, 2); /* "invalid factorial argument" */
    v11 = list2(v12, v11);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-1];
    v12 = v11;
    v11 = v12;
    qvalue(elt(env, 3)) = v11; /* errmsg!* */
    v11 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v11 == nil)) goto v82;
    v11 = v12;
    fn = elt(env, 5); /* lprie */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-1];
    goto v82;

v82:
    v11 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v114;
    v11 = nil;
    { popv(2); return onevalue(v11); }

v113:
    v11 = stack[0];
    {
        popv(2);
        fn = elt(env, 6); /* nfactorial */
        return (*qfn1(fn))(qenv(fn), v11);
    }

v42:
    v11 = qvalue(elt(env, 1)); /* t */
    goto v115;
/* error exit handlers */
v114:
    popv(2);
    return nil;
}



/* Code for setel1 */

static Lisp_Object MS_CDECL CC_setel1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v53, Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v161, v109, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "setel1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setel1");
#endif
    if (stack >= stacklimit)
    {
        push4(v4,v53,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v53,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v53;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v115:
    v161 = stack[-2];
    v161 = qcar(v161);
    v161 = integerp(v161);
    if (v161 == nil) goto v24;
    v161 = stack[-2];
    v109 = qcar(v161);
    v161 = stack[0];
    v161 = qcar(v161);
    v161 = (Lisp_Object)geq2(v109, v161);
    nil = C_nil;
    if (exception_pending()) goto v51;
    v161 = v161 ? lisp_true : nil;
    env = stack[-4];
    if (!(v161 == nil)) goto v37;
    v161 = stack[-2];
    v109 = qcar(v161);
    v161 = (Lisp_Object)1; /* 0 */
    v161 = (Lisp_Object)lessp2(v109, v161);
    nil = C_nil;
    if (exception_pending()) goto v51;
    v161 = v161 ? lisp_true : nil;
    env = stack[-4];
    if (!(v161 == nil)) goto v37;
    v161 = stack[-2];
    v161 = qcdr(v161);
    if (v161 == nil) goto v57;
    v109 = stack[-3];
    v161 = stack[-2];
    v161 = qcar(v161);
    v161 = *(Lisp_Object *)((char *)v109 + (CELL-TAG_VECTOR) + ((int32_t)v161/(16/CELL)));
    stack[-3] = v161;
    v161 = stack[-2];
    v161 = qcdr(v161);
    stack[-2] = v161;
    v161 = stack[0];
    v161 = qcdr(v161);
    stack[0] = v161;
    goto v115;

v57:
    v110 = stack[-3];
    v161 = stack[-2];
    v109 = qcar(v161);
    v161 = stack[-1];
    *(Lisp_Object *)((char *)v110 + (CELL-TAG_VECTOR) + ((int32_t)v109/(16/CELL))) = v161;
    { popv(5); return onevalue(v161); }

v37:
    v161 = elt(env, 2); /* "Array out of bounds" */
    v109 = v161;
    v161 = v109;
    qvalue(elt(env, 3)) = v161; /* errmsg!* */
    v161 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v161 == nil)) goto v40;
    v161 = v109;
    fn = elt(env, 5); /* lprie */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    goto v40;

v40:
    v161 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v51;
    v161 = nil;
    { popv(5); return onevalue(v161); }

v24:
    v161 = stack[-2];
    v109 = qcar(v161);
    v161 = elt(env, 1); /* "array index" */
    {
        popv(5);
        fn = elt(env, 6); /* typerr */
        return (*qfn2(fn))(qenv(fn), v109, v161);
    }
/* error exit handlers */
v51:
    popv(5);
    return nil;
}



/* Code for comm1 */

static Lisp_Object CC_comm1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comm1");
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
    v51 = stack[0];
    v52 = elt(env, 1); /* end */
    if (!(v51 == v52)) goto v103;

v14:
    fn = elt(env, 10); /* scan */
    v52 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    goto v103;

v103:
    v51 = qvalue(elt(env, 2)); /* cursym!* */
    v52 = elt(env, 3); /* !*semicol!* */
    if (v51 == v52) goto v37;
    v51 = stack[0];
    v52 = elt(env, 1); /* end */
    if (v51 == v52) goto v11;
    v52 = qvalue(elt(env, 6)); /* nil */
    goto v97;

v97:
    if (v52 == nil) goto v101;
    v52 = qvalue(elt(env, 6)); /* nil */
    { popv(3); return onevalue(v52); }

v101:
    v51 = stack[0];
    v52 = elt(env, 1); /* end */
    if (v51 == v52) goto v100;
    v52 = qvalue(elt(env, 6)); /* nil */
    goto v30;

v30:
    if (v52 == nil) goto v14;
    v52 = qvalue(elt(env, 7)); /* !*msg */
    if (v52 == nil) goto v131;
    stack[-1] = elt(env, 8); /* "***" */
    v52 = elt(env, 9); /* "END-COMMENT NO LONGER SUPPORTED" */
    v52 = ncons(v52);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    fn = elt(env, 11); /* lpriw */
    v52 = (*qfn2(fn))(qenv(fn), stack[-1], v52);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    goto v131;

v131:
    v52 = qvalue(elt(env, 4)); /* t */
    stack[-1] = v52;
    goto v14;

v100:
    v52 = stack[-1];
    v52 = (v52 == nil ? lisp_true : nil);
    goto v30;

v11:
    v51 = qvalue(elt(env, 2)); /* cursym!* */
    v52 = elt(env, 5); /* (end else then until !*rpar!* !*rsqbkt!*) */
    v52 = Lmemq(nil, v51, v52);
    goto v97;

v37:
    v52 = qvalue(elt(env, 4)); /* t */
    goto v97;
/* error exit handlers */
v67:
    popv(3);
    return nil;
}



/* Code for cl_atml1 */

static Lisp_Object CC_cl_atml1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_atml1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v84 = v0;
/* end of prologue */
    v43 = v84;
    v84 = elt(env, 1); /* cl_atmlc */
    {
        fn = elt(env, 2); /* cl_f2ml */
        return (*qfn2(fn))(qenv(fn), v43, v84);
    }
}



/* Code for mksq */

static Lisp_Object CC_mksq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v198, v199, v200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksq");
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
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v198 = qvalue(elt(env, 1)); /* subfg!* */
    if (v198 == nil) goto v22;
    v199 = stack[-4];
    v198 = qvalue(elt(env, 2)); /* wtl!* */
    v198 = Lassoc(nil, v199, v198);
    stack[-2] = v198;
    if (v198 == nil) goto v28;
    stack[0] = elt(env, 3); /* k!* */
    v199 = stack[-3];
    v198 = stack[-2];
    v198 = qcdr(v198);
    v198 = times2(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-6];
    v198 = CC_mksq(env, stack[0], v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-6];
    stack[-2] = v198;
    v198 = qcar(v198);
    if (v198 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    else goto v28;

v28:
    v198 = stack[-4];
    if (!consp(v198)) goto v12;
    v198 = qvalue(elt(env, 4)); /* !*nosubs */
    if (v198 == nil) goto v202;
    v198 = qvalue(elt(env, 6)); /* nil */
    goto v203;

v203:
    if (!(v198 == nil)) goto v43;
    stack[0] = elt(env, 7); /* used!* */
    v198 = stack[-4];
    fn = elt(env, 16); /* fkern */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-6];
    stack[-5] = v198;
    v198 = qcdr(v198);
    v198 = qcdr(v198);
    v198 = Lmemq(nil, stack[0], v198);
    if (!(v198 == nil)) goto v42;
    stack[0] = stack[-5];
    v198 = elt(env, 7); /* used!* */
    v198 = ncons(v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-6];
    v198 = Lnconc(nil, stack[0], v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-6];
    goto v42;

v42:
    v198 = qvalue(elt(env, 4)); /* !*nosubs */
    if (!(v198 == nil)) goto v22;
    v199 = stack[-3];
    v198 = (Lisp_Object)17; /* 1 */
    if (v199 == v198) goto v22;
    v199 = stack[-4];
    v198 = qvalue(elt(env, 8)); /* asymplis!* */
    v198 = Lassoc(nil, v199, v198);
    stack[-1] = v198;
    if (v198 == nil) goto v48;
    v198 = stack[-1];
    v199 = qcdr(v198);
    v198 = stack[-3];
    v198 = (Lisp_Object)lesseq2(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    v198 = v198 ? lisp_true : nil;
    env = stack[-6];
    if (v198 == nil) goto v48;
    v199 = qvalue(elt(env, 6)); /* nil */
    v198 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v199, v198);

v48:
    v199 = stack[-4];
    v198 = qvalue(elt(env, 9)); /* powlis!* */
    v198 = Lassoc(nil, v199, v198);
    stack[-1] = v198;
    if (!(v198 == nil)) goto v204;
    v198 = stack[-4];
    if (!consp(v198)) goto v205;
    v198 = stack[-4];
    v199 = qcar(v198);
    v198 = elt(env, 10); /* (expt sqrt) */
    v198 = Lmemq(nil, v199, v198);
    if (v198 == nil) goto v206;
    v198 = stack[-4];
    v198 = qcdr(v198);
    v199 = qcar(v198);
    v198 = qvalue(elt(env, 9)); /* powlis!* */
    v198 = Lassoc(nil, v199, v198);
    stack[-1] = v198;
    goto v120;

v120:
    if (!(v198 == nil)) goto v204;

v22:
    v198 = stack[-5];
    if (!(v198 == nil)) goto v207;
    v198 = stack[-4];
    fn = elt(env, 16); /* fkern */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-6];
    stack[-5] = v198;
    goto v207;

v207:
    v199 = stack[-5];
    v198 = stack[-3];
    fn = elt(env, 17); /* getpower */
    v199 = (*qfn2(fn))(qenv(fn), v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-6];
    v198 = (Lisp_Object)17; /* 1 */
    v198 = cons(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-6];
    v199 = ncons(v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-6];
    v198 = (Lisp_Object)17; /* 1 */
    v198 = cons(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-6];
    stack[-5] = v198;
    v198 = stack[-2];
    if (v198 == nil) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    v199 = stack[-2];
    v198 = stack[-5];
    {
        popv(7);
        fn = elt(env, 18); /* multsq */
        return (*qfn2(fn))(qenv(fn), v199, v198);
    }

v204:
    v199 = stack[-3];
    v198 = stack[-1];
    v198 = qcdr(v198);
    v198 = qcar(v198);
    v199 = times2(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-6];
    v198 = (Lisp_Object)1; /* 0 */
    v198 = (Lisp_Object)lessp2(v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    v198 = v198 ? lisp_true : nil;
    env = stack[-6];
    if (!(v198 == nil)) goto v22;
    v198 = qvalue(elt(env, 11)); /* t */
    qvalue(elt(env, 12)) = v198; /* !*sub2 */
    goto v22;

v206:
    v198 = qvalue(elt(env, 6)); /* nil */
    goto v120;

v205:
    v198 = qvalue(elt(env, 6)); /* nil */
    goto v120;

v43:
    v198 = stack[-1];
    v198 = qcdr(v198);
    stack[-1] = v198;
    v198 = qvalue(elt(env, 15)); /* !*resubs */
    if (!(v198 == nil)) goto v208;
    v198 = qvalue(elt(env, 11)); /* t */
    qvalue(elt(env, 4)) = v198; /* !*nosubs */
    goto v208;

v208:
    v198 = stack[-1];
    v198 = qcar(v198);
    fn = elt(env, 19); /* simp */
    v198 = (*qfn1(fn))(qenv(fn), v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-6];
    stack[-5] = v198;
    v198 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 4)) = v198; /* !*nosubs */
    v199 = stack[-5];
    v198 = stack[-3];
    {
        popv(7);
        fn = elt(env, 20); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v199, v198);
    }

v202:
    v198 = stack[-4];
    v198 = qcar(v198);
    if (!consp(v198)) goto v209;
    v198 = qvalue(elt(env, 6)); /* nil */
    goto v203;

v209:
    v198 = stack[-4];
    v199 = qcar(v198);
    v198 = elt(env, 13); /* mksqsubfn */
    v198 = get(v199, v198);
    env = stack[-6];
    stack[-1] = v198;
    if (v198 == nil) goto v210;
    v199 = stack[-1];
    v198 = stack[-4];
    v198 = Lapply1(nil, v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-6];
    stack[-1] = v198;
    goto v211;

v211:
    if (!(v198 == nil)) goto v203;
    v200 = stack[-4];
    v198 = stack[-4];
    v199 = qcar(v198);
    v198 = elt(env, 14); /* kvalue */
    v198 = get(v199, v198);
    env = stack[-6];
    v198 = Lassoc(nil, v200, v198);
    stack[-1] = v198;
    goto v203;

v210:
    v198 = qvalue(elt(env, 6)); /* nil */
    goto v211;

v12:
    v198 = qvalue(elt(env, 4)); /* !*nosubs */
    if (v198 == nil) goto v126;
    v198 = qvalue(elt(env, 6)); /* nil */
    goto v40;

v40:
    if (!(v198 == nil)) goto v43;
    v198 = stack[-4];
    if (!(symbolp(v198))) goto v42;
    v198 = stack[-4];
    v199 = ncons(v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-6];
    v198 = elt(env, 7); /* used!* */
    v198 = Lflag(nil, v199, v198);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-6];
    goto v42;

v126:
    v199 = stack[-4];
    v198 = elt(env, 5); /* avalue */
    v198 = get(v199, v198);
    env = stack[-6];
    stack[-1] = v198;
    goto v40;
/* error exit handlers */
v201:
    popv(7);
    return nil;
}



/* Code for ofsf_smupdknowl */

static Lisp_Object MS_CDECL CC_ofsf_smupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v53, Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v66, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smupdknowl");
#endif
    if (stack >= stacklimit)
    {
        push4(v4,v53,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v53,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v4;
    stack[-2] = v53;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */

v44:
    v124 = stack[-3];
    if (v124 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    v66 = stack[-4];
    v124 = elt(env, 2); /* and */
    if (v66 == v124) goto v16;
    v124 = stack[-3];
    v124 = qcar(v124);
    fn = elt(env, 4); /* ofsf_negateat */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    goto v8;

v8:
    v66 = v124;
    v124 = stack[-3];
    v124 = qcdr(v124);
    stack[-3] = v124;
    v124 = stack[-1];
    fn = elt(env, 5); /* ofsf_at2ir */
    v124 = (*qfn2(fn))(qenv(fn), v66, v124);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    v147 = v124;
    v124 = v147;
    v66 = qcar(v124);
    v124 = stack[-2];
    v124 = Lassoc(nil, v66, v124);
    stack[-5] = v124;
    if (v124 == nil) goto v50;
    stack[0] = stack[-5];
    v124 = v147;
    v124 = qcdr(v124);
    v66 = qcar(v124);
    v124 = stack[-5];
    v124 = qcdr(v124);
    fn = elt(env, 6); /* ofsf_sminsert */
    v124 = (*qfn2(fn))(qenv(fn), v66, v124);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    fn = elt(env, 7); /* setcdr */
    v124 = (*qfn2(fn))(qenv(fn), stack[0], v124);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    v124 = stack[-5];
    v66 = qcdr(v124);
    v124 = elt(env, 3); /* false */
    if (!(v66 == v124)) goto v44;
    v124 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v124;
    v124 = elt(env, 3); /* false */
    stack[-2] = v124;
    goto v44;

v50:
    v66 = v147;
    v124 = stack[-2];
    v124 = cons(v66, v124);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-6];
    stack[-2] = v124;
    goto v44;

v16:
    v124 = stack[-3];
    v124 = qcar(v124);
    goto v8;
/* error exit handlers */
v93:
    popv(7);
    return nil;
}



/* Code for !*tayexp2q */

static Lisp_Object CC_Htayexp2q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v133;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *tayexp2q");
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
    v5 = v0;
/* end of prologue */
    v133 = v5;
    if (!consp(v133)) goto v42;
    v5 = qcdr(v5);
    { popv(1); return onevalue(v5); }

v42:
    v133 = v5;
    v133 = (Lisp_Object)zerop(v133);
    v133 = v133 ? lisp_true : nil;
    env = stack[0];
    if (v133 == nil) goto v8;
    v5 = qvalue(elt(env, 1)); /* nil */
    v133 = v5;
    goto v84;

v84:
    v5 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v133, v5);

v8:
    v133 = v5;
    goto v84;
}



/* Code for mk!+unit!+mat */

static Lisp_Object CC_mkLunitLmat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+unit+mat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v14 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* gen!+can!+bas */
        return (*qfn1(fn))(qenv(fn), v14);
    }
}



/* Code for qqe_arg!-check */

static Lisp_Object CC_qqe_argKcheck(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_arg-check");
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
    v72 = stack[0];
    v72 = qcar(v72);
    stack[-1] = v72;
    v72 = stack[-1];
    fn = elt(env, 4); /* qqe_rqopp */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    if (v72 == nil) goto v42;
    v72 = stack[0];
    fn = elt(env, 5); /* qqe_arg!-check!-lq!-rq */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    goto v14;

v14:
    v72 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v72); }

v42:
    v72 = stack[-1];
    fn = elt(env, 6); /* qqe_rbopp */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    if (v72 == nil) goto v15;
    v72 = stack[0];
    fn = elt(env, 7); /* qqe_arg!-check!-lb!-rb */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    goto v14;

v15:
    v72 = stack[-1];
    fn = elt(env, 8); /* qqe_qopheadp */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    if (!(v72 == nil)) goto v7;
    v72 = stack[-1];
    fn = elt(env, 9); /* qqe_qoptailp */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    if (!(v72 == nil)) goto v7;
    v72 = stack[-1];
    fn = elt(env, 10); /* qqe_qopaddp */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    if (v72 == nil) goto v26;
    v72 = stack[0];
    fn = elt(env, 11); /* qqe_arg!-check!-lb!-rq */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    goto v14;

v26:
    v72 = stack[0];
    v72 = qcdr(v72);
    stack[-1] = v72;
    goto v135;

v135:
    v72 = stack[-1];
    if (v72 == nil) goto v14;
    v72 = stack[-1];
    v72 = qcar(v72);
    fn = elt(env, 12); /* qqe_arg!-check!-b */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    if (!(v72 == nil)) goto v91;
    fn = elt(env, 13); /* qqe_arg!-check!-marked!-ids!-rollback */
    v72 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v212 = stack[0];
    v72 = elt(env, 3); /* "some arguments are not of basic type" */
    fn = elt(env, 14); /* typerr */
    v72 = (*qfn2(fn))(qenv(fn), v212, v72);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    goto v91;

v91:
    v72 = stack[-1];
    v72 = qcdr(v72);
    stack[-1] = v72;
    goto v135;

v7:
    v72 = stack[0];
    v72 = qcdr(v72);
    v72 = qcar(v72);
    fn = elt(env, 15); /* qqe_arg!-check!-q */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    if (!(v72 == nil)) goto v14;
    fn = elt(env, 13); /* qqe_arg!-check!-marked!-ids!-rollback */
    v72 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v212 = stack[0];
    v72 = elt(env, 1); /* "some arguments are not of queue type" */
    fn = elt(env, 14); /* typerr */
    v72 = (*qfn2(fn))(qenv(fn), v212, v72);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    goto v14;
/* error exit handlers */
v110:
    popv(3);
    return nil;
}



/* Code for pasf_varlat */

static Lisp_Object CC_pasf_varlat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_varlat");
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
    v41 = stack[0];
    v41 = qcdr(v41);
    v144 = qcar(v41);
    v41 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* kernels1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v144, v41);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    v41 = stack[0];
    v41 = Lconsp(nil, v41);
    env = stack[-2];
    if (v41 == nil) goto v25;
    v41 = stack[0];
    v41 = qcar(v41);
    v41 = Lconsp(nil, v41);
    env = stack[-2];
    if (v41 == nil) goto v25;
    v41 = stack[0];
    v41 = qcar(v41);
    v144 = qcar(v41);
    v41 = elt(env, 2); /* (cong ncong) */
    v41 = Lmemq(nil, v144, v41);
    if (v41 == nil) goto v25;
    v41 = stack[0];
    v41 = qcar(v41);
    v144 = qcdr(v41);
    v41 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* kernels1 */
    v41 = (*qfn2(fn))(qenv(fn), v144, v41);
    nil = C_nil;
    if (exception_pending()) goto v126;
    goto v14;

v14:
    {
        Lisp_Object v136 = stack[-1];
        popv(3);
        return Lappend(nil, v136, v41);
    }

v25:
    v41 = qvalue(elt(env, 1)); /* nil */
    goto v14;
/* error exit handlers */
v126:
    popv(3);
    return nil;
}



/* Code for cl_qb */

static Lisp_Object CC_cl_qb(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v32, v91, v54, v55;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_qb");
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
    v55 = nil;
    v81 = (Lisp_Object)1; /* 0 */
    v54 = v81;
    goto v84;

v84:
    v81 = stack[0];
    if (!consp(v81)) goto v27;
    v81 = stack[0];
    v81 = qcar(v81);
    goto v24;

v24:
    stack[-1] = v81;
    v91 = v81;
    v32 = v91;
    v81 = elt(env, 1); /* ex */
    if (v32 == v81) goto v5;
    v32 = v91;
    v81 = elt(env, 3); /* all */
    v81 = (v32 == v81 ? lisp_true : nil);
    goto v31;

v31:
    if (v81 == nil) { popv(3); return onevalue(v54); }
    v32 = stack[-1];
    v81 = v55;
    if (equal(v32, v81)) goto v114;
    v81 = v54;
    v81 = add1(v81);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-2];
    v54 = v81;
    v81 = stack[-1];
    v55 = v81;
    goto v114;

v114:
    v81 = stack[0];
    v81 = qcdr(v81);
    v81 = qcdr(v81);
    v81 = qcar(v81);
    stack[0] = v81;
    goto v84;

v5:
    v81 = qvalue(elt(env, 2)); /* t */
    goto v31;

v27:
    v81 = stack[0];
    goto v24;
/* error exit handlers */
v111:
    popv(3);
    return nil;
}



/* Code for reln */

static Lisp_Object CC_reln(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reln");
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
    v34 = elt(env, 1); /* "<reln>" */
    fn = elt(env, 6); /* printout */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    v34 = elt(env, 2); /* "<" */
    v34 = Lprinc(nil, v34);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    v34 = stack[0];
    v34 = Lprinc(nil, v34);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    v34 = elt(env, 3); /* "/>" */
    v34 = Lprinc(nil, v34);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    v20 = qvalue(elt(env, 4)); /* indent */
    v34 = (Lisp_Object)49; /* 3 */
    v34 = plus2(v20, v34);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    qvalue(elt(env, 4)) = v34; /* indent */
    v34 = stack[-1];
    fn = elt(env, 7); /* multi_elem */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    v20 = qvalue(elt(env, 4)); /* indent */
    v34 = (Lisp_Object)49; /* 3 */
    v34 = difference2(v20, v34);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    qvalue(elt(env, 4)) = v34; /* indent */
    v34 = elt(env, 5); /* "</reln>" */
    fn = elt(env, 6); /* printout */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v34 = nil;
    { popv(3); return onevalue(v34); }
/* error exit handlers */
v134:
    popv(3);
    return nil;
}



/* Code for ps!:expansion!-point */

static Lisp_Object CC_psTexpansionKpoint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v114, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:expansion-point");
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
    v114 = v0;
/* end of prologue */
    v13 = v114;
    if (!consp(v13)) goto v42;
    v13 = v114;
    v25 = qcar(v13);
    v13 = elt(env, 2); /* !:ps!: */
    if (v25 == v13) goto v21;
    v13 = v114;
    v25 = qcar(v13);
    v13 = elt(env, 3); /* dname */
    v13 = get(v25, v13);
    env = stack[0];
    goto v115;

v115:
    if (v13 == nil) goto v35;
    v13 = qvalue(elt(env, 4)); /* nil */
    { popv(1); return onevalue(v13); }

v35:
    v13 = (Lisp_Object)49; /* 3 */
    {
        popv(1);
        fn = elt(env, 5); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v114, v13);
    }

v21:
    v13 = qvalue(elt(env, 4)); /* nil */
    goto v115;

v42:
    v13 = qvalue(elt(env, 1)); /* t */
    goto v115;
}



/* Code for dm!-min */

static Lisp_Object CC_dmKmin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-min");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v8 = stack[-1];
    v7 = stack[0];
    fn = elt(env, 1); /* dm!-gt */
    v7 = (*qfn2(fn))(qenv(fn), v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v97;
    if (v7 == nil) { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v97:
    popv(2);
    return nil;
}



/* Code for mkprod */

static Lisp_Object CC_mkprod(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v233, v234;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkprod");
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
    stack[-2] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = nil; /* !*exp */
    stack[-1] = qvalue(elt(env, 2)); /* !*sub2 */
    qvalue(elt(env, 2)) = nil; /* !*sub2 */
    v233 = stack[-4];
    if (v233 == nil) goto v24;
    v233 = stack[-4];
    fn = elt(env, 10); /* kernlp */
    v233 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    goto v36;

v36:
    if (v233 == nil) goto v43;
    v233 = stack[-4];
    goto v22;

v22:
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-2]; /* !*exp */
    { popv(7); return onevalue(v233); }

v43:
    v233 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v233; /* !*sub2 */
    v234 = stack[-4];
    v233 = (Lisp_Object)17; /* 1 */
    v233 = cons(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    fn = elt(env, 11); /* subs2 */
    v233 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    stack[0] = v233;
    v233 = stack[0];
    v234 = qcdr(v233);
    v233 = (Lisp_Object)17; /* 1 */
    if (v234 == v233) goto v114;
    v233 = stack[-4];
    goto v22;

v114:
    v233 = stack[0];
    v234 = qcar(v233);
    v233 = stack[-4];
    if (equal(v234, v233)) goto v82;
    v233 = stack[0];
    v233 = qcar(v233);
    stack[-4] = v233;
    v233 = stack[-4];
    if (v233 == nil) goto v62;
    v233 = stack[-4];
    fn = elt(env, 10); /* kernlp */
    v233 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    goto v101;

v101:
    if (v233 == nil) goto v82;
    v233 = stack[-4];
    goto v22;

v82:
    v233 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 1)) = v233; /* !*exp */
    v233 = stack[-4];
    fn = elt(env, 12); /* ckrn */
    v233 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    stack[-5] = v233;
    v234 = stack[-4];
    v233 = stack[-5];
    fn = elt(env, 13); /* quotf */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    stack[-4] = v233;
    v233 = stack[-4];
    fn = elt(env, 14); /* expnd */
    v233 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    stack[0] = v233;
    v233 = stack[0];
    if (v233 == nil) goto v74;
    v233 = stack[0];
    fn = elt(env, 10); /* kernlp */
    v233 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    goto v108;

v108:
    if (v233 == nil) goto v212;
    v234 = stack[-5];
    v233 = stack[0];
    fn = elt(env, 15); /* multf */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    goto v22;

v212:
    v233 = qvalue(elt(env, 4)); /* !*mcd */
    if (v233 == nil) goto v236;
    v233 = qvalue(elt(env, 5)); /* !*sqfree */
    if (!(v233 == nil)) goto v93;
    v233 = qvalue(elt(env, 6)); /* !*factor */
    if (!(v233 == nil)) goto v93;
    v233 = qvalue(elt(env, 7)); /* !*gcd */
    if (!(v233 == nil)) goto v93;

v236:
    v233 = stack[0];
    fn = elt(env, 12); /* ckrn */
    v233 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    stack[-3] = v233;
    v234 = stack[0];
    v233 = stack[-3];
    fn = elt(env, 13); /* quotf */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    stack[0] = v233;
    v234 = stack[0];
    v233 = (Lisp_Object)17; /* 1 */
    v233 = cons(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v233 = list2(stack[-3], v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    stack[-3] = v233;
    goto v159;

v159:
    v233 = stack[-3];
    v233 = qcdr(v233);
    v233 = qcar(v233);
    v234 = qcdr(v233);
    v233 = (Lisp_Object)17; /* 1 */
    v233 = (Lisp_Object)greaterp2(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    v233 = v233 ? lisp_true : nil;
    env = stack[-6];
    if (!(v233 == nil)) goto v237;
    v233 = stack[-3];
    v233 = qcdr(v233);
    v233 = qcdr(v233);
    if (!(v233 == nil)) goto v237;
    v233 = qvalue(elt(env, 9)); /* !*group */
    if (v233 == nil) goto v185;
    v233 = qvalue(elt(env, 8)); /* nil */
    goto v207;

v207:
    if (v233 == nil) goto v210;
    v233 = stack[-3];
    v233 = qcdr(v233);
    v233 = qcar(v233);
    v234 = qcar(v233);
    v233 = stack[-3];
    v233 = qcdr(v233);
    v233 = qcar(v233);
    v233 = qcdr(v233);
    fn = elt(env, 16); /* mksp!* */
    v234 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v233 = stack[-3];
    v233 = qcar(v233);
    fn = elt(env, 15); /* multf */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    stack[0] = v233;
    goto v238;

v238:
    v234 = stack[-5];
    v233 = stack[0];
    fn = elt(env, 15); /* multf */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    goto v22;

v210:
    v234 = stack[-4];
    v233 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 16); /* mksp!* */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    stack[0] = v233;
    goto v238;

v185:
    v233 = stack[-4];
    fn = elt(env, 17); /* tmsf */
    stack[0] = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v233 = stack[-3];
    v233 = qcdr(v233);
    v233 = qcar(v233);
    v233 = qcar(v233);
    fn = elt(env, 17); /* tmsf */
    v233 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v233 = (Lisp_Object)greaterp2(stack[0], v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    v233 = v233 ? lisp_true : nil;
    env = stack[-6];
    goto v207;

v237:
    v233 = stack[-3];
    v233 = qcar(v233);
    stack[0] = v233;
    v233 = stack[-3];
    v233 = qcdr(v233);
    stack[-3] = v233;
    goto v239;

v239:
    v233 = stack[-3];
    if (v233 == nil) goto v238;
    v233 = stack[-3];
    v233 = qcar(v233);
    v234 = v233;
    v234 = qcar(v234);
    v233 = qcdr(v233);
    fn = elt(env, 16); /* mksp!* */
    v234 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v233 = stack[0];
    fn = elt(env, 15); /* multf */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    stack[0] = v233;
    v233 = stack[-3];
    v233 = qcdr(v233);
    stack[-3] = v233;
    goto v239;

v93:
    v233 = stack[0];
    fn = elt(env, 18); /* fctrf */
    v233 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    stack[-3] = v233;
    goto v159;

v74:
    v233 = qvalue(elt(env, 3)); /* t */
    goto v108;

v62:
    v233 = qvalue(elt(env, 3)); /* t */
    goto v101;

v24:
    v233 = qvalue(elt(env, 3)); /* t */
    goto v36;
/* error exit handlers */
v235:
    env = stack[-6];
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-2]; /* !*exp */
    popv(7);
    return nil;
}



/* Code for setdmode1 */

static Lisp_Object CC_setdmode1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210, v246, v247, v209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setdmode1");
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
    v246 = v1;
    stack[-5] = v0;
/* end of prologue */
    v247 = stack[-5];
    v210 = elt(env, 1); /* tag */
    v210 = get(v247, v210);
    env = stack[-7];
    stack[-6] = v210;
    v210 = qvalue(elt(env, 2)); /* dmode!* */
    stack[-4] = v210;
    v210 = v246;
    if (v210 == nil) goto v7;
    v246 = stack[-5];
    v210 = elt(env, 13); /* (rounded complex!-rounded) */
    v210 = Lmemq(nil, v246, v210);
    if (v210 == nil) goto v88;
    fn = elt(env, 21); /* !!mfefix */
    v210 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-7];
    goto v88;

v88:
    v246 = stack[-6];
    v210 = stack[-4];
    if (v246 == v210) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v246 = stack[-6];
    v210 = elt(env, 14); /* realtype */
    v210 = get(v246, v210);
    env = stack[-7];
    stack[-3] = v210;
    if (!(v210 == nil)) goto v104;
    v210 = stack[-6];
    stack[-3] = v210;
    goto v104;

v104:
    v210 = qvalue(elt(env, 15)); /* domainlist!* */
    stack[-2] = v210;
    goto v249;

v249:
    v210 = stack[-2];
    if (v210 == nil) goto v250;
    v210 = stack[-2];
    v210 = qcar(v210);
    stack[-1] = v210;
    v246 = stack[-1];
    v210 = elt(env, 16); /* !:gi!: */
    if (v246 == v210) goto v229;
    v246 = stack[-1];
    v210 = stack[-3];
    v210 = (v246 == v210 ? lisp_true : nil);
    v210 = (v210 == nil ? lisp_true : nil);
    goto v251;

v251:
    if (v210 == nil) goto v206;
    v210 = elt(env, 17); /* !* */
    stack[0] = Lexplode(nil, v210);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-7];
    v246 = stack[-1];
    v210 = elt(env, 4); /* dname */
    v210 = get(v246, v210);
    env = stack[-7];
    v210 = Lexplode(nil, v210);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-7];
    v210 = Lappend(nil, stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-7];
    v210 = Lcompress(nil, v210);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-7];
    v246 = Lintern(nil, v210);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-7];
    v210 = qvalue(elt(env, 3)); /* nil */
    v210 = Lset(nil, v246, v210);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-7];
    goto v206;

v206:
    v210 = stack[-2];
    v210 = qcdr(v210);
    stack[-2] = v210;
    goto v249;

v229:
    v210 = qvalue(elt(env, 3)); /* nil */
    goto v251;

v250:
    v246 = qvalue(elt(env, 5)); /* !*sqvar!* */
    v210 = qvalue(elt(env, 3)); /* nil */
    v210 = Lrplaca(nil, v246, v210);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-7];
    v210 = qvalue(elt(env, 6)); /* t */
    v210 = ncons(v210);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-7];
    qvalue(elt(env, 5)) = v210; /* !*sqvar!* */
    v210 = qvalue(elt(env, 3)); /* nil */
    v210 = ncons(v210);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-7];
    qvalue(elt(env, 7)) = v210; /* alglist!* */
    v246 = stack[-4];
    v210 = elt(env, 4); /* dname */
    v210 = get(v246, v210);
    env = stack[-7];
    stack[-4] = v210;
    v210 = stack[-4];
    if (v210 == nil) goto v152;
    v210 = qvalue(elt(env, 18)); /* !*msg */
    if (v210 == nil) goto v152;
    stack[0] = elt(env, 9); /* "***" */
    v209 = elt(env, 19); /* "Domain mode" */
    v247 = stack[-4];
    v246 = elt(env, 20); /* "changed to" */
    v210 = stack[-5];
    v210 = list4(v209, v247, v246, v210);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-7];
    fn = elt(env, 22); /* lpriw */
    v210 = (*qfn2(fn))(qenv(fn), stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-7];
    goto v152;

v152:
    v210 = stack[-6];
    qvalue(elt(env, 2)) = v210; /* dmode!* */
    qvalue(elt(env, 8)) = v210; /* gdmode!* */
    { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }

v7:
    v210 = stack[-4];
    if (v210 == nil) goto v37;
    v247 = stack[-5];
    v246 = stack[-4];
    v210 = elt(env, 4); /* dname */
    v210 = get(v246, v210);
    env = stack[-7];
    stack[-4] = v210;
    if (v247 == v210) goto v11;
    stack[-2] = elt(env, 9); /* "***" */
    stack[-1] = elt(env, 10); /* "Failed attempt to turn off" */
    stack[-3] = stack[-5];
    stack[0] = elt(env, 11); /* "when" */
    v246 = stack[-4];
    v210 = elt(env, 12); /* "is on" */
    v210 = list2(v246, v210);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-7];
    v210 = list3star(stack[-1], stack[-3], stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-7];
    {
        Lisp_Object v252 = stack[-2];
        popv(8);
        fn = elt(env, 22); /* lpriw */
        return (*qfn2(fn))(qenv(fn), v252, v210);
    }

v11:
    v246 = qvalue(elt(env, 5)); /* !*sqvar!* */
    v210 = qvalue(elt(env, 3)); /* nil */
    v210 = Lrplaca(nil, v246, v210);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-7];
    v210 = qvalue(elt(env, 6)); /* t */
    v210 = ncons(v210);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-7];
    qvalue(elt(env, 5)) = v210; /* !*sqvar!* */
    v210 = qvalue(elt(env, 3)); /* nil */
    v210 = ncons(v210);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-7];
    qvalue(elt(env, 7)) = v210; /* alglist!* */
    v210 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 2)) = v210; /* dmode!* */
    qvalue(elt(env, 8)) = v210; /* gdmode!* */
    { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }

v37:
    v210 = qvalue(elt(env, 3)); /* nil */
    { popv(8); return onevalue(v210); }
/* error exit handlers */
v248:
    popv(8);
    return nil;
}



/* Code for expvec2a */

static Lisp_Object CC_expvec2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expvec2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v84 = v0;
/* end of prologue */
    v43 = v84;
    v84 = qvalue(elt(env, 1)); /* dipvars!* */
    {
        fn = elt(env, 2); /* expvec2a1 */
        return (*qfn2(fn))(qenv(fn), v43, v84);
    }
}



/* Code for freeindexchk */

static Lisp_Object CC_freeindexchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeindexchk");
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
    v7 = v0;
/* end of prologue */
    v28 = v7;
    if (v28 == nil) goto v36;
    v28 = qvalue(elt(env, 1)); /* indxl!* */
    if (v28 == nil) goto v36;
    v28 = v7;
    fn = elt(env, 4); /* indxchk */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[0];
    if (v28 == nil) goto v36;
    v28 = elt(env, 2); /* form!-with!-free!-indices */
    { popv(1); return onevalue(v28); }

v36:
    v28 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v28); }
/* error exit handlers */
v8:
    popv(1);
    return nil;
}



/* Code for partitexdf */

static Lisp_Object CC_partitexdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partitexdf");
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
    v14 = v0;
/* end of prologue */
    v14 = qcar(v14);
    fn = elt(env, 1); /* partitop */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* exdfpf */
        return (*qfn1(fn))(qenv(fn), v14);
    }
/* error exit handlers */
v115:
    popv(1);
    return nil;
}



/* Code for fctargs */

static Lisp_Object CC_fctargs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v27;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fctargs");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v24 = v0;
/* end of prologue */
    v27 = qvalue(elt(env, 1)); /* depl!* */
    v27 = Lassoc(nil, v24, v27);
    v24 = v27;
    if (v27 == nil) goto v39;
    v24 = qcdr(v24);
    return onevalue(v24);

v39:
    v24 = nil;
    return onevalue(v24);
}



/* Code for powers4 */

static Lisp_Object CC_powers4(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v272, v273, v274;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powers4");
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
    stack[-1] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v14;

v14:
    v272 = stack[-1];
    if (v272 == nil) goto v33;
    v272 = stack[0];
    if (v272 == nil) goto v212;
    v272 = stack[-1];
    v272 = qcar(v272);
    v273 = qcar(v272);
    v272 = stack[0];
    v272 = qcar(v272);
    v272 = qcar(v272);
    if (equal(v273, v272)) goto v132;
    v272 = stack[-1];
    v272 = qcar(v272);
    v273 = qcar(v272);
    v272 = stack[0];
    v272 = qcar(v272);
    v272 = qcar(v272);
    fn = elt(env, 2); /* ordop */
    v272 = (*qfn2(fn))(qenv(fn), v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    if (v272 == nil) goto v276;
    v272 = stack[0];
    v272 = qcar(v272);
    v273 = qcdr(v272);
    v272 = (Lisp_Object)1; /* 0 */
    v272 = Lrplacd(nil, v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    stack[-2] = stack[0];
    v273 = stack[-1];
    v272 = stack[0];
    v272 = qcdr(v272);
    v272 = CC_powers4(env, v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    v272 = Lrplacd(nil, stack[-2], v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    {
        Lisp_Object v277 = stack[-3];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v277, v272);
    }

v276:
    v272 = stack[-1];
    v272 = qcar(v272);
    stack[-2] = qcar(v272);
    v272 = stack[-1];
    v272 = qcar(v272);
    v273 = qcdr(v272);
    v272 = (Lisp_Object)1; /* 0 */
    v273 = cons(v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    v272 = stack[-3];
    v272 = acons(stack[-2], v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    stack[-3] = v272;
    v272 = stack[-1];
    v272 = qcdr(v272);
    stack[-1] = v272;
    goto v14;

v132:
    v272 = stack[-1];
    v272 = qcar(v272);
    v273 = qcdr(v272);
    v272 = stack[0];
    v272 = qcar(v272);
    v272 = qcdr(v272);
    v272 = qcar(v272);
    v272 = (Lisp_Object)greaterp2(v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    v272 = v272 ? lisp_true : nil;
    env = stack[-5];
    if (v272 == nil) goto v227;
    v272 = stack[0];
    v272 = qcar(v272);
    v273 = qcdr(v272);
    v272 = stack[-1];
    v272 = qcar(v272);
    v272 = qcdr(v272);
    v272 = Lrplaca(nil, v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    goto v227;

v227:
    v272 = stack[-1];
    v272 = qcar(v272);
    v273 = qcdr(v272);
    v272 = stack[0];
    v272 = qcar(v272);
    v272 = qcdr(v272);
    v272 = qcdr(v272);
    v272 = (Lisp_Object)lessp2(v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    v272 = v272 ? lisp_true : nil;
    env = stack[-5];
    if (v272 == nil) goto v221;
    v272 = stack[0];
    v272 = qcar(v272);
    v273 = qcdr(v272);
    v272 = stack[-1];
    v272 = qcar(v272);
    v272 = qcdr(v272);
    v272 = Lrplacd(nil, v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    goto v221;

v221:
    stack[-2] = stack[0];
    v272 = stack[-1];
    v273 = qcdr(v272);
    v272 = stack[0];
    v272 = qcdr(v272);
    v272 = CC_powers4(env, v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    v272 = Lrplacd(nil, stack[-2], v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    {
        Lisp_Object v278 = stack[-3];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v278, v272);
    }

v212:
    stack[-4] = stack[-3];
    v272 = stack[-1];
    stack[-3] = v272;
    v272 = stack[-3];
    if (v272 == nil) goto v66;
    v272 = stack[-3];
    v272 = qcar(v272);
    v273 = v272;
    v274 = qcar(v273);
    v273 = qcdr(v272);
    v272 = (Lisp_Object)1; /* 0 */
    v272 = list2star(v274, v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    v272 = ncons(v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    stack[-1] = v272;
    stack[-2] = v272;
    goto v67;

v67:
    v272 = stack[-3];
    v272 = qcdr(v272);
    stack[-3] = v272;
    v272 = stack[-3];
    if (v272 == nil) goto v48;
    stack[0] = stack[-1];
    v272 = stack[-3];
    v272 = qcar(v272);
    v273 = v272;
    v274 = qcar(v273);
    v273 = qcdr(v272);
    v272 = (Lisp_Object)1; /* 0 */
    v272 = list2star(v274, v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    v272 = ncons(v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    v272 = Lrplacd(nil, stack[0], v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    v272 = stack[-1];
    v272 = qcdr(v272);
    stack[-1] = v272;
    goto v67;

v48:
    v272 = stack[-2];
    goto v110;

v110:
    {
        Lisp_Object v279 = stack[-4];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v279, v272);
    }

v66:
    v272 = qvalue(elt(env, 1)); /* nil */
    goto v110;

v33:
    stack[-4] = stack[-3];
    v272 = stack[0];
    stack[-3] = v272;
    v272 = stack[-3];
    if (v272 == nil) goto v5;
    v272 = stack[-3];
    v272 = qcar(v272);
    v273 = v272;
    v274 = qcar(v273);
    v272 = qcdr(v272);
    v273 = qcar(v272);
    v272 = (Lisp_Object)1; /* 0 */
    v272 = list2star(v274, v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    v272 = ncons(v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    stack[-1] = v272;
    stack[-2] = v272;
    goto v37;

v37:
    v272 = stack[-3];
    v272 = qcdr(v272);
    stack[-3] = v272;
    v272 = stack[-3];
    if (v272 == nil) goto v41;
    stack[0] = stack[-1];
    v272 = stack[-3];
    v272 = qcar(v272);
    v273 = v272;
    v274 = qcar(v273);
    v272 = qcdr(v272);
    v273 = qcar(v272);
    v272 = (Lisp_Object)1; /* 0 */
    v272 = list2star(v274, v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    v272 = ncons(v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    v272 = Lrplacd(nil, stack[0], v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-5];
    v272 = stack[-1];
    v272 = qcdr(v272);
    stack[-1] = v272;
    goto v37;

v41:
    v272 = stack[-2];
    goto v24;

v24:
    {
        Lisp_Object v280 = stack[-4];
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v280, v272);
    }

v5:
    v272 = qvalue(elt(env, 1)); /* nil */
    goto v24;
/* error exit handlers */
v275:
    popv(6);
    return nil;
}



/* Code for assert_check1 */

static Lisp_Object MS_CDECL CC_assert_check1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v53, Lisp_Object v4,
                         Lisp_Object v56, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v186, v184, v150, v151, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "assert_check1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_check1");
#endif
    if (stack >= stacklimit)
    {
        push5(v56,v4,v53,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v53,v4,v56);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-5] = v56;
    stack[-6] = v4;
    stack[-7] = v53;
    stack[-8] = v1;
    stack[-9] = v0;
/* end of prologue */
    stack[-4] = nil;
    v185 = (Lisp_Object)1; /* 0 */
    stack[-3] = v185;
    v185 = qvalue(elt(env, 1)); /* !*assertstatistics */
    if (v185 == nil) goto v24;
    v186 = stack[-9];
    v185 = qvalue(elt(env, 2)); /* assertstatistics!* */
    v185 = Latsoc(nil, v186, v185);
    v186 = v185;
    v185 = v186;
    if (v185 == nil) goto v12;
    v185 = v186;
    stack[0] = qcdr(v185);
    v185 = v186;
    v185 = qcdr(v185);
    v185 = qcar(v185);
    v185 = add1(v185);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-11];
    fn = elt(env, 6); /* setcar */
    v185 = (*qfn2(fn))(qenv(fn), stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-11];
    goto v24;

v24:
    v185 = stack[-6];
    stack[-10] = v185;
    v185 = stack[-7];
    stack[-2] = v185;
    goto v55;

v55:
    v185 = stack[-2];
    if (v185 == nil) goto v231;
    v185 = stack[-2];
    v185 = qcar(v185);
    stack[-1] = v185;
    v185 = stack[-3];
    v185 = add1(v185);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-11];
    stack[-3] = v185;
    v185 = stack[-10];
    v186 = qcar(v185);
    v185 = elt(env, 4); /* assert_checkfn */
    v185 = get(v186, v185);
    env = stack[-11];
    v186 = v185;
    if (v185 == nil) goto v87;
    stack[0] = v186;
    v185 = stack[-1];
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-11];
    fn = elt(env, 7); /* apply */
    v185 = (*qfn2(fn))(qenv(fn), stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-11];
    if (!(v185 == nil)) goto v87;
    v185 = qvalue(elt(env, 5)); /* t */
    stack[-4] = v185;
    v152 = stack[-9];
    v151 = stack[-6];
    v150 = stack[-5];
    v184 = stack[-3];
    v185 = stack[-10];
    v186 = qcar(v185);
    v185 = stack[-1];
    fn = elt(env, 8); /* assert_error */
    v185 = (*qfnn(fn))(qenv(fn), 6, v152, v151, v150, v184, v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-11];
    goto v87;

v87:
    v185 = stack[-10];
    v185 = qcdr(v185);
    stack[-10] = v185;
    v185 = stack[-2];
    v185 = qcdr(v185);
    stack[-2] = v185;
    goto v55;

v231:
    v186 = stack[-8];
    v185 = stack[-7];
    fn = elt(env, 7); /* apply */
    v185 = (*qfn2(fn))(qenv(fn), v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-11];
    stack[-1] = v185;
    v186 = stack[-5];
    v185 = elt(env, 4); /* assert_checkfn */
    v185 = get(v186, v185);
    env = stack[-11];
    v186 = v185;
    if (v185 == nil) goto v230;
    stack[0] = v186;
    v185 = stack[-1];
    v185 = ncons(v185);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-11];
    fn = elt(env, 7); /* apply */
    v185 = (*qfn2(fn))(qenv(fn), stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-11];
    if (!(v185 == nil)) goto v230;
    v185 = qvalue(elt(env, 5)); /* t */
    stack[-4] = v185;
    v152 = stack[-9];
    v151 = stack[-6];
    v150 = stack[-5];
    v184 = (Lisp_Object)1; /* 0 */
    v186 = stack[-5];
    v185 = stack[-1];
    fn = elt(env, 8); /* assert_error */
    v185 = (*qfnn(fn))(qenv(fn), 6, v152, v151, v150, v184, v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-11];
    goto v230;

v230:
    v185 = qvalue(elt(env, 1)); /* !*assertstatistics */
    if (v185 == nil) { Lisp_Object res = stack[-1]; popv(12); return onevalue(res); }
    v185 = stack[-4];
    if (v185 == nil) { Lisp_Object res = stack[-1]; popv(12); return onevalue(res); }
    v186 = stack[-9];
    v185 = qvalue(elt(env, 2)); /* assertstatistics!* */
    v185 = Latsoc(nil, v186, v185);
    v185 = qcdr(v185);
    v186 = v185;
    v185 = v186;
    stack[0] = qcdr(v185);
    v185 = v186;
    v185 = qcdr(v185);
    v185 = qcar(v185);
    v185 = add1(v185);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-11];
    fn = elt(env, 6); /* setcar */
    v185 = (*qfn2(fn))(qenv(fn), stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v286;
    { Lisp_Object res = stack[-1]; popv(12); return onevalue(res); }

v12:
    stack[0] = stack[-9];
    v184 = (Lisp_Object)17; /* 1 */
    v186 = (Lisp_Object)1; /* 0 */
    v185 = (Lisp_Object)1; /* 0 */
    v186 = list3(v184, v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-11];
    v185 = qvalue(elt(env, 2)); /* assertstatistics!* */
    v185 = acons(stack[0], v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-11];
    qvalue(elt(env, 2)) = v185; /* assertstatistics!* */
    goto v24;
/* error exit handlers */
v286:
    popv(12);
    return nil;
}



/* Code for splitlist!: */

static Lisp_Object CC_splitlistT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v3, v127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for splitlist:");
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
    v127 = nil;
    goto v14;

v14:
    v102 = stack[-1];
    if (v102 == nil) goto v22;
    v102 = stack[-1];
    v3 = qcar(v102);
    v102 = stack[0];
    if (!consp(v3)) goto v82;
    v3 = qcar(v3);
    if (!(v3 == v102)) goto v82;
    v102 = stack[-1];
    v102 = qcar(v102);
    v3 = v127;
    v102 = cons(v102, v3);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    v127 = v102;
    v102 = stack[-1];
    v102 = qcdr(v102);
    stack[-1] = v102;
    goto v14;

v82:
    v102 = stack[-1];
    v102 = qcdr(v102);
    stack[-1] = v102;
    goto v14;

v22:
    v102 = v127;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v102);
    }
/* error exit handlers */
v9:
    popv(3);
    return nil;
}



/* Code for horner!-rule!-mod!-p */

static Lisp_Object MS_CDECL CC_hornerKruleKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v53, Lisp_Object v4,
                         Lisp_Object v56, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v145, v60, v159, v287;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "horner-rule-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for horner-rule-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push5(v56,v4,v53,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v53,v4,v56);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v56;
    stack[-3] = v4;
    stack[-4] = v53;
    v60 = v1;
    v159 = v0;
/* end of prologue */

v288:
    v146 = stack[-4];
    if (!consp(v146)) goto v24;
    v146 = stack[-4];
    v146 = qcar(v146);
    v146 = (consp(v146) ? nil : lisp_true);
    goto v36;

v36:
    if (v146 == nil) goto v5;
    v146 = qvalue(elt(env, 1)); /* t */
    goto v43;

v43:
    if (v146 == nil) goto v149;
    v146 = stack[-3];
    if (v146 == nil) goto v10;
    v146 = stack[-3];
    v146 = (Lisp_Object)zerop(v146);
    v146 = v146 ? lisp_true : nil;
    env = stack[-6];
    goto v9;

v9:
    if (!(v146 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[0] = v159;
    v146 = stack[-3];
    v145 = v60;
    fn = elt(env, 2); /* expt!-mod!-p */
    v146 = (*qfn2(fn))(qenv(fn), v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    fn = elt(env, 3); /* times!-mod!-p */
    v146 = (*qfn2(fn))(qenv(fn), stack[0], v146);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    v159 = v146;
    v146 = stack[-4];
    v145 = v159;
    {
        popv(7);
        fn = elt(env, 4); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v146, v145);
    }

v10:
    v146 = qvalue(elt(env, 1)); /* t */
    goto v9;

v149:
    v146 = stack[-4];
    v146 = qcar(v146);
    v146 = qcar(v146);
    v146 = qcdr(v146);
    stack[-5] = v146;
    v146 = stack[-3];
    if (v146 == nil) goto v76;
    v146 = stack[-3];
    v146 = (Lisp_Object)zerop(v146);
    v146 = v146 ? lisp_true : nil;
    env = stack[-6];
    goto v78;

v78:
    if (v146 == nil) goto v98;
    v146 = stack[-4];
    v146 = qcar(v146);
    v146 = qcdr(v146);
    v159 = v146;
    goto v110;

v110:
    v60 = stack[-5];
    v146 = stack[-4];
    v287 = qcdr(v146);
    v145 = stack[-3];
    v146 = stack[-2];
    stack[-4] = v287;
    stack[-3] = v145;
    stack[-2] = v146;
    goto v288;

v98:
    v146 = stack[-4];
    v146 = qcar(v146);
    stack[-1] = qcdr(v146);
    stack[0] = v159;
    v145 = stack[-3];
    v146 = stack[-5];
    v146 = (Lisp_Object)(int32_t)((int32_t)v60 - (int32_t)v146 + TAG_FIXNUM);
    fn = elt(env, 2); /* expt!-mod!-p */
    v146 = (*qfn2(fn))(qenv(fn), v145, v146);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    fn = elt(env, 3); /* times!-mod!-p */
    v146 = (*qfn2(fn))(qenv(fn), stack[0], v146);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    fn = elt(env, 4); /* plus!-mod!-p */
    v146 = (*qfn2(fn))(qenv(fn), stack[-1], v146);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    v159 = v146;
    goto v110;

v76:
    v146 = qvalue(elt(env, 1)); /* t */
    goto v78;

v5:
    v146 = stack[-4];
    v146 = qcar(v146);
    v146 = qcar(v146);
    v145 = qcar(v146);
    v146 = stack[-2];
    v146 = (equal(v145, v146) ? lisp_true : nil);
    v146 = (v146 == nil ? lisp_true : nil);
    goto v43;

v24:
    v146 = qvalue(elt(env, 1)); /* t */
    goto v36;
/* error exit handlers */
v193:
    popv(7);
    return nil;
}



/* Code for drnconv */

static Lisp_Object CC_drnconv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v23, v29;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for drnconv");
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
    v23 = v0;
/* end of prologue */
    v136 = v23;
    if (v136 == nil) goto v42;
    v136 = v23;
    v136 = (is_number(v136) ? lisp_true : nil);
    if (!(v136 == nil)) goto v115;
    v29 = v23;
    v136 = qvalue(elt(env, 2)); /* dmd!* */
    v136 = Leqcar(nil, v29, v136);
    env = stack[0];
    goto v115;

v115:
    if (!(v136 == nil)) { popv(1); return onevalue(v23); }
    v136 = v23;
    v29 = qcar(v136);
    v136 = qvalue(elt(env, 2)); /* dmd!* */
    v136 = get(v29, v136);
    v29 = v136;
    v136 = v29;
    if (v136 == nil) { popv(1); return onevalue(v23); }
    v136 = v29;
    if (!(!consp(v136))) { popv(1); return onevalue(v23); }
    v136 = v29;
        popv(1);
        return Lapply1(nil, v136, v23);

v42:
    v136 = qvalue(elt(env, 1)); /* t */
    goto v115;
}



/* Code for cl_identifyonoff */

static Lisp_Object CC_cl_identifyonoff(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v4;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_identifyonoff");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v4 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v4; /* cl_identify!-atl!* */
    return onevalue(v4);
}



/* Code for qqe_prepat */

static Lisp_Object CC_qqe_prepat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v4;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_prepat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    return onevalue(v4);
}



/* Code for ibalp_negatet */

static Lisp_Object CC_ibalp_negatet(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21, v82;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_negatet");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v82 = v0;
/* end of prologue */
    v21 = v82;
    v20 = (Lisp_Object)1; /* 0 */
    if (v21 == v20) goto v56;
    v21 = v82;
    v20 = (Lisp_Object)17; /* 1 */
    if (v21 == v20) goto v15;
    v20 = elt(env, 1); /* bnot */
    v21 = v82;
    return list2(v20, v21);

v15:
    v20 = (Lisp_Object)1; /* 0 */
    return onevalue(v20);

v56:
    v20 = (Lisp_Object)17; /* 1 */
    return onevalue(v20);
}



/* Code for makeset */

static Lisp_Object CC_makeset(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v3, v127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makeset");
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
    v127 = nil;
    goto v39;

v39:
    v102 = stack[0];
    if (v102 == nil) goto v42;
    v102 = stack[0];
    v3 = qcar(v102);
    v102 = stack[0];
    v102 = qcdr(v102);
    v102 = Lmember(nil, v3, v102);
    if (v102 == nil) goto v6;
    v102 = stack[0];
    v102 = qcdr(v102);
    stack[0] = v102;
    goto v39;

v6:
    v102 = stack[0];
    v102 = qcar(v102);
    v3 = v127;
    v102 = cons(v102, v3);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-1];
    v127 = v102;
    v102 = stack[0];
    v102 = qcdr(v102);
    stack[0] = v102;
    goto v39;

v42:
    v102 = v127;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v102);
    }
/* error exit handlers */
v35:
    popv(2);
    return nil;
}



/* Code for onoff */

static Lisp_Object CC_onoff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v231, v232, v123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for onoff");
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
    v231 = stack[0];
    if (symbolp(v231)) goto v97;
    v232 = stack[0];
    v231 = elt(env, 1); /* "switch" */
    fn = elt(env, 12); /* typerr */
    v231 = (*qfn2(fn))(qenv(fn), v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    goto v40;

v40:
    v231 = elt(env, 6); /* !* */
    stack[-1] = Lexplode(nil, v231);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v231 = stack[0];
    v231 = Lexplode(nil, v231);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v231 = Lappend(nil, stack[-1], v231);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v231 = Lcompress(nil, v231);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v231 = Lintern(nil, v231);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    stack[-3] = v231;
    v231 = qvalue(elt(env, 7)); /* !*switchcheck */
    if (v231 == nil) goto v149;
    v231 = stack[-3];
    fn = elt(env, 13); /* eval */
    v232 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v231 = stack[-2];
    if (!(v232 == v231)) goto v149;
    v231 = qvalue(elt(env, 8)); /* nil */
    { popv(5); return onevalue(v231); }

v149:
    v123 = stack[-2];
    v232 = stack[0];
    v231 = elt(env, 9); /* simpfg */
    v231 = get(v232, v231);
    env = stack[-4];
    v231 = Latsoc(nil, v123, v231);
    v232 = v231;
    if (v231 == nil) goto v100;
    stack[-1] = elt(env, 10); /* progn */
    v231 = v232;
    stack[0] = qcdr(v231);
    v231 = qvalue(elt(env, 8)); /* nil */
    v231 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v231 = Lappend(nil, stack[0], v231);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v231 = cons(stack[-1], v231);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    fn = elt(env, 13); /* eval */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    goto v100;

v100:
    v231 = stack[-2];
    if (v231 == nil) goto v48;
    v232 = stack[-3];
    v231 = elt(env, 11); /* !*raise */
    if (!(v232 == v231)) goto v48;
    v231 = elt(env, 11); /* !*raise */
    stack[-3] = v231;
    goto v48;

v48:
    v232 = stack[-3];
    v231 = stack[-2];
    v231 = Lset(nil, v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v191;
    v231 = nil;
    { popv(5); return onevalue(v231); }

v97:
    v232 = stack[0];
    v231 = elt(env, 2); /* switch */
    v231 = Lflagp(nil, v232, v231);
    env = stack[-4];
    if (!(v231 == nil)) goto v40;
    v232 = stack[0];
    v231 = elt(env, 3); /* "not defined as switch" */
    v231 = list2(v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v232 = v231;
    v231 = v232;
    qvalue(elt(env, 4)) = v231; /* errmsg!* */
    v231 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v231 == nil)) goto v113;
    v231 = v232;
    fn = elt(env, 14); /* lprie */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    goto v113;

v113:
    v231 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    goto v40;
/* error exit handlers */
v191:
    popv(5);
    return nil;
}



/* Code for indexvarordp */

static Lisp_Object CC_indexvarordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indexvarordp");
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
    v104 = stack[-1];
    v68 = qcar(v104);
    v104 = stack[0];
    v104 = qcar(v104);
    if (v68 == v104) goto v103;
    v104 = qvalue(elt(env, 1)); /* t */
    goto v42;

v42:
    if (v104 == nil) goto v114;
    v68 = stack[-1];
    v104 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* ordop */
        return (*qfn2(fn))(qenv(fn), v68, v104);
    }

v114:
    v104 = stack[-1];
    v104 = qcdr(v104);
    fn = elt(env, 6); /* flatindxl */
    stack[-2] = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    v104 = stack[0];
    v104 = qcdr(v104);
    fn = elt(env, 6); /* flatindxl */
    v68 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    v104 = stack[-2];
    stack[-2] = v68;
    v68 = v104;
    v104 = qvalue(elt(env, 3)); /* indxl!* */
    fn = elt(env, 7); /* boundindp */
    v104 = (*qfn2(fn))(qenv(fn), v68, v104);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    if (v104 == nil) goto v67;
    v68 = stack[-2];
    v104 = qvalue(elt(env, 3)); /* indxl!* */
    fn = elt(env, 7); /* boundindp */
    v104 = (*qfn2(fn))(qenv(fn), v68, v104);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    if (v104 == nil) goto v74;
    v104 = stack[-1];
    v68 = qcdr(v104);
    v104 = stack[0];
    v104 = qcdr(v104);
    {
        popv(4);
        fn = elt(env, 8); /* indordlp */
        return (*qfn2(fn))(qenv(fn), v68, v104);
    }

v74:
    v104 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v104); }

v67:
    v68 = stack[-2];
    v104 = qvalue(elt(env, 3)); /* indxl!* */
    fn = elt(env, 7); /* boundindp */
    v104 = (*qfn2(fn))(qenv(fn), v68, v104);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    if (v104 == nil) goto v92;
    v104 = qvalue(elt(env, 4)); /* nil */
    { popv(4); return onevalue(v104); }

v92:
    v68 = stack[-1];
    v104 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* ordop */
        return (*qfn2(fn))(qenv(fn), v68, v104);
    }

v103:
    v68 = stack[-1];
    v104 = qvalue(elt(env, 2)); /* kord!* */
    v104 = Lmemq(nil, v68, v104);
    if (!(v104 == nil)) goto v42;
    v68 = stack[0];
    v104 = qvalue(elt(env, 2)); /* kord!* */
    v104 = Lmemq(nil, v68, v104);
    goto v42;
/* error exit handlers */
v75:
    popv(4);
    return nil;
}



/* Code for mkfortterpri */

static Lisp_Object MS_CDECL CC_mkfortterpri(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mkfortterpri");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkfortterpri");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v4 = elt(env, 1); /* fortterpri */
    return ncons(v4);
}



/* Code for can_be_proved */

static Lisp_Object CC_can_be_proved(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for can_be_proved");
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

v39:
    v5 = stack[-1];
    if (v5 == nil) goto v42;
    v5 = stack[-1];
    v133 = qcar(v5);
    v5 = stack[0];
    fn = elt(env, 3); /* can_be_p */
    v5 = (*qfn2(fn))(qenv(fn), v133, v5);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    if (v5 == nil) goto v38;
    v5 = stack[-1];
    v5 = qcdr(v5);
    stack[-1] = v5;
    goto v39;

v38:
    v5 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v5); }

v42:
    v5 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v5); }
/* error exit handlers */
v17:
    popv(3);
    return nil;
}



/* Code for assert_stat1 */

static Lisp_Object MS_CDECL CC_assert_stat1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_stat1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_stat1");
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
    stack[0] = nil;
    fn = elt(env, 9); /* scan */
    v73 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-1];
    v155 = elt(env, 1); /* !*lpar!* */
    if (v73 == v155) goto v82;
    v155 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v155 == nil)) goto v28;
    v73 = elt(env, 3); /* "expecting '(' in assert but found" */
    v155 = qvalue(elt(env, 4)); /* cursym!* */
    v155 = list2(v73, v155);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-1];
    fn = elt(env, 10); /* lprie */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-1];
    goto v28;

v28:
    v155 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-1];
    goto v82;

v82:
    fn = elt(env, 9); /* scan */
    v73 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-1];
    v155 = elt(env, 5); /* !*rpar!* */
    if (!(v73 == v155)) goto v12;
    v155 = qvalue(elt(env, 6)); /* nil */
    { popv(2); return onevalue(v155); }

v12:
    v73 = qvalue(elt(env, 4)); /* cursym!* */
    v155 = stack[0];
    v155 = cons(v73, v155);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-1];
    stack[0] = v155;
    fn = elt(env, 9); /* scan */
    v155 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-1];
    v73 = qvalue(elt(env, 4)); /* cursym!* */
    v155 = elt(env, 7); /* !*comma!* */
    if (v73 == v155) goto v148;
    v73 = qvalue(elt(env, 4)); /* cursym!* */
    v155 = elt(env, 5); /* !*rpar!* */
    v155 = Lneq(nil, v73, v155);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-1];
    goto v29;

v29:
    if (v155 == nil) goto v124;
    v155 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v155 == nil)) goto v86;
    v73 = elt(env, 8); /* "expecting ',' or ')' in assert but found" */
    v155 = qvalue(elt(env, 4)); /* cursym!* */
    v155 = list2(v73, v155);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-1];
    fn = elt(env, 10); /* lprie */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-1];
    goto v86;

v86:
    v155 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-1];
    goto v124;

v124:
    v73 = qvalue(elt(env, 4)); /* cursym!* */
    v155 = elt(env, 7); /* !*comma!* */
    if (!(v73 == v155)) goto v96;
    fn = elt(env, 9); /* scan */
    v155 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-1];
    goto v96;

v96:
    v73 = qvalue(elt(env, 4)); /* cursym!* */
    v155 = elt(env, 5); /* !*rpar!* */
    if (!(v73 == v155)) goto v12;
    v155 = stack[0];
        popv(2);
        return Lnreverse(nil, v155);

v148:
    v155 = qvalue(elt(env, 6)); /* nil */
    goto v29;
/* error exit handlers */
v71:
    popv(2);
    return nil;
}



/* Code for no_dum_varp */

static Lisp_Object CC_no_dum_varp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for no_dum_varp");
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
    v82 = stack[0];
    v82 = qcdr(v82);
    if (v82 == nil) goto v42;
    v82 = stack[0];
    v134 = qcdr(v82);
    v82 = elt(env, 2); /* list */
    fn = elt(env, 4); /* splitlist!: */
    v134 = (*qfn2(fn))(qenv(fn), v134, v82);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-1];
    v82 = stack[0];
    v82 = qcdr(v82);
    v82 = (equal(v134, v82) ? lisp_true : nil);
    goto v115;

v115:
    if (v82 == nil) goto v34;
    v82 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v82); }

v34:
    v82 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v82); }

v42:
    v82 = qvalue(elt(env, 1)); /* t */
    goto v115;
/* error exit handlers */
v2:
    popv(2);
    return nil;
}



/* Code for ratn */

static Lisp_Object CC_ratn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v41, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratn");
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
    v144 = v0;
/* end of prologue */
    v40 = v144;
    if (v40 == nil) goto v42;
    v40 = v144;
    if (!consp(v40)) goto v7;
    v40 = v144;
    v41 = qcar(v40);
    v40 = elt(env, 1); /* !:rn!: */
    if (v41 == v40) goto v103;
    v40 = elt(env, 2); /* "Illegal domain in :ar:" */
    v41 = v40;
    v40 = v41;
    qvalue(elt(env, 3)) = v40; /* errmsg!* */
    v40 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v40 == nil)) goto v10;
    v40 = v41;
    fn = elt(env, 5); /* lprie */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[0];
    goto v10;

v10:
    v40 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    v40 = nil;
    { popv(1); return onevalue(v40); }

v103:
    v40 = v144;
    v40 = qcdr(v40);
    { popv(1); return onevalue(v40); }

v7:
    v41 = v144;
    v40 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v41, v40);

v42:
    v41 = (Lisp_Object)1; /* 0 */
    v40 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v41, v40);
/* error exit handlers */
v61:
    popv(1);
    return nil;
}



/* Code for cl_fvarl1 */

static Lisp_Object CC_cl_fvarl1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_fvarl1");
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
    v39 = v0;
/* end of prologue */
    fn = elt(env, 1); /* cl_varl1 */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    errexit();
    v39 = qcar(v39);
    return onevalue(v39);
}



/* Code for wusort */

static Lisp_Object CC_wusort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wusort");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v84 = v0;
/* end of prologue */
    v43 = v84;
    v84 = elt(env, 1); /* wulessp!* */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v43, v84);
    }
}



setup_type const u18_setup[] =
{
    {"ordop2",                  too_few_2,      CC_ordop2,     wrong_no_2},
    {"contr",                   too_few_2,      CC_contr,      wrong_no_2},
    {"setelv",                  too_few_2,      CC_setelv,     wrong_no_2},
    {"fs:times",                too_few_2,      CC_fsTtimes,   wrong_no_2},
    {"dpmat_coldegs",           CC_dpmat_coldegs,too_many_1,   wrong_no_1},
    {"st_consolidate",          CC_st_consolidate,too_many_1,  wrong_no_1},
    {"reducepowers",            CC_reducepowers,too_many_1,    wrong_no_1},
    {"general-evaluate-mod-p",  wrong_no_na,    wrong_no_nb,   (n_args *)CC_generalKevaluateKmodKp},
    {"mkfil*",                  CC_mkfilH,      too_many_1,    wrong_no_1},
    {"rl_bestgaussp",           CC_rl_bestgaussp,too_many_1,   wrong_no_1},
    {"mkpartitions1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkpartitions1},
    {"tayexp-times2",           too_few_2,      CC_tayexpKtimes2,wrong_no_2},
    {"ibalp_negateat",          CC_ibalp_negateat,too_many_1,  wrong_no_1},
    {"cgp_number",              CC_cgp_number,  too_many_1,    wrong_no_1},
    {"crprimp",                 CC_crprimp,     too_many_1,    wrong_no_1},
    {"pfordp",                  too_few_2,      CC_pfordp,     wrong_no_2},
    {"r2findindex",             too_few_2,      CC_r2findindex,wrong_no_2},
    {"inttovec-solve",          too_few_2,      CC_inttovecKsolve,wrong_no_2},
    {"rd:times",                too_few_2,      CC_rdTtimes,   wrong_no_2},
    {"factorial",               CC_factorial,   too_many_1,    wrong_no_1},
    {"setel1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_setel1},
    {"comm1",                   CC_comm1,       too_many_1,    wrong_no_1},
    {"cl_atml1",                CC_cl_atml1,    too_many_1,    wrong_no_1},
    {"mksq",                    too_few_2,      CC_mksq,       wrong_no_2},
    {"ofsf_smupdknowl",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smupdknowl},
    {"*tayexp2q",               CC_Htayexp2q,   too_many_1,    wrong_no_1},
    {"mk+unit+mat",             CC_mkLunitLmat, too_many_1,    wrong_no_1},
    {"qqe_arg-check",           CC_qqe_argKcheck,too_many_1,   wrong_no_1},
    {"pasf_varlat",             CC_pasf_varlat, too_many_1,    wrong_no_1},
    {"cl_qb",                   CC_cl_qb,       too_many_1,    wrong_no_1},
    {"reln",                    too_few_2,      CC_reln,       wrong_no_2},
    {"ps:expansion-point",      CC_psTexpansionKpoint,too_many_1,wrong_no_1},
    {"dm-min",                  too_few_2,      CC_dmKmin,     wrong_no_2},
    {"mkprod",                  CC_mkprod,      too_many_1,    wrong_no_1},
    {"setdmode1",               too_few_2,      CC_setdmode1,  wrong_no_2},
    {"expvec2a",                CC_expvec2a,    too_many_1,    wrong_no_1},
    {"freeindexchk",            CC_freeindexchk,too_many_1,    wrong_no_1},
    {"partitexdf",              CC_partitexdf,  too_many_1,    wrong_no_1},
    {"fctargs",                 CC_fctargs,     too_many_1,    wrong_no_1},
    {"powers4",                 too_few_2,      CC_powers4,    wrong_no_2},
    {"assert_check1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_check1},
    {"splitlist:",              too_few_2,      CC_splitlistT, wrong_no_2},
    {"horner-rule-mod-p",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKruleKmodKp},
    {"drnconv",                 CC_drnconv,     too_many_1,    wrong_no_1},
    {"cl_identifyonoff",        CC_cl_identifyonoff,too_many_1,wrong_no_1},
    {"qqe_prepat",              CC_qqe_prepat,  too_many_1,    wrong_no_1},
    {"ibalp_negatet",           CC_ibalp_negatet,too_many_1,   wrong_no_1},
    {"makeset",                 CC_makeset,     too_many_1,    wrong_no_1},
    {"onoff",                   too_few_2,      CC_onoff,      wrong_no_2},
    {"indexvarordp",            too_few_2,      CC_indexvarordp,wrong_no_2},
    {"mkfortterpri",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkfortterpri},
    {"can_be_proved",           too_few_2,      CC_can_be_proved,wrong_no_2},
    {"assert_stat1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_stat1},
    {"no_dum_varp",             CC_no_dum_varp, too_many_1,    wrong_no_1},
    {"ratn",                    CC_ratn,        too_many_1,    wrong_no_1},
    {"cl_fvarl1",               CC_cl_fvarl1,   too_many_1,    wrong_no_1},
    {"wusort",                  CC_wusort,      too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u18", (two_args *)"7201 5305786 4079122", 0}
};

/* end of generated code */
