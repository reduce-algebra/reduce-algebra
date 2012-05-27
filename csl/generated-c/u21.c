
/* $destdir\u21.c        Machine generated C code */

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


/* Code for unresidp */

static Lisp_Object CC_unresidp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unresidp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v3 = v0;
/* end of prologue */
    v4 = qvalue(elt(env, 1)); /* !*reservedops!* */
    v3 = Lmemq(nil, v3, v4);
    v3 = (v3 == nil ? lisp_true : nil);
    return onevalue(v3);
}



/* Code for replace1_parents */

static Lisp_Object MS_CDECL CC_replace1_parents(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v5,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v11, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "replace1_parents");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replace1_parents");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v10 = v6;
    v11 = v5;
    v12 = v0;
/* end of prologue */
    v12 = qcar(v12);
    v11 = qcar(v11);
    v10 = qcdr(v10);
    v10 = qcar(v10);
    {
        fn = elt(env, 1); /* replace2_parents */
        return (*qfnn(fn))(qenv(fn), 3, v12, v11, v10);
    }
}



/* Code for fieldconv */

static Lisp_Object CC_fieldconv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v5)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v62, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fieldconv");
#endif
    if (stack >= stacklimit)
    {
        push2(v5,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v5;
    stack[-2] = v0;
/* end of prologue */
    v61 = stack[-1];
    v61 = qcar(v61);
    stack[-3] = v61;
    v61 = stack[-1];
    v61 = qcdr(v61);
    stack[0] = v61;
    v61 = qvalue(elt(env, 1)); /* dmode!* */
    if (v61 == nil) goto v64;
    v61 = stack[0];
    if (!consp(v61)) goto v65;
    v61 = stack[0];
    v61 = qcar(v61);
    v61 = (consp(v61) ? nil : lisp_true);
    goto v66;

v66:
    if (v61 == nil) goto v67;
    v62 = stack[-3];
    v61 = stack[0];
    fn = elt(env, 6); /* divd */
    v62 = (*qfn2(fn))(qenv(fn), v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v68;
    v61 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v62, v61);

v67:
    v62 = stack[-3];
    v61 = stack[-2];
    fn = elt(env, 6); /* divd */
    stack[-1] = (*qfn2(fn))(qenv(fn), v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    v62 = stack[0];
    v61 = stack[-2];
    fn = elt(env, 6); /* divd */
    v61 = (*qfn2(fn))(qenv(fn), v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v68;
    {
        Lisp_Object v69 = stack[-1];
        popv(5);
        return cons(v69, v61);
    }

v65:
    v61 = qvalue(elt(env, 5)); /* t */
    goto v66;

v64:
    v62 = stack[-2];
    v61 = elt(env, 2); /* !:rn!: */
    if (!consp(v62)) goto v70;
    v62 = qcar(v62);
    if (!(v62 == v61)) goto v70;

v71:
    v61 = stack[-2];
    v63 = qcar(v61);
    v61 = stack[-2];
    v61 = qcdr(v61);
    v62 = qcdr(v61);
    v61 = stack[-2];
    v61 = qcdr(v61);
    v61 = qcar(v61);
    v61 = list2star(v63, v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    stack[-2] = v61;
    v61 = stack[0];
    if (!consp(v61)) goto v72;
    v61 = stack[0];
    v61 = qcar(v61);
    v61 = (consp(v61) ? nil : lisp_true);
    goto v73;

v73:
    if (v61 == nil) goto v74;
    v62 = stack[-2];
    v61 = stack[-3];
    fn = elt(env, 7); /* multd */
    v62 = (*qfn2(fn))(qenv(fn), v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    v61 = (Lisp_Object)17; /* 1 */
    v61 = cons(v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    goto v75;

v75:
    {
        popv(5);
        fn = elt(env, 8); /* simpgd */
        return (*qfn1(fn))(qenv(fn), v61);
    }

v74:
    v62 = stack[-2];
    v61 = stack[-3];
    fn = elt(env, 7); /* multd */
    stack[-1] = (*qfn2(fn))(qenv(fn), v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    v62 = stack[-2];
    v61 = stack[0];
    fn = elt(env, 7); /* multd */
    v61 = (*qfn2(fn))(qenv(fn), v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    v61 = cons(stack[-1], v61);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    goto v75;

v72:
    v61 = qvalue(elt(env, 5)); /* t */
    goto v73;

v70:
    v61 = stack[-2];
    v62 = qcar(v61);
    v61 = elt(env, 2); /* !:rn!: */
    v61 = get(v62, v61);
    env = stack[-4];
    v62 = v61;
    if (v61 == nil) goto v76;
    v61 = v62;
    if (!(!consp(v61))) goto v76;
    v61 = stack[-2];
    v61 = Lapply1(nil, v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    stack[-2] = v61;
    goto v71;

v76:
    v61 = stack[-2];
    v62 = qcar(v61);
    v61 = elt(env, 3); /* quotient */
    v61 = get(v62, v61);
    env = stack[-4];
    if (v61 == nil) goto v77;
    v63 = (Lisp_Object)17; /* 1 */
    v62 = stack[-2];
    v61 = elt(env, 3); /* quotient */
    fn = elt(env, 9); /* dcombine */
    v61 = (*qfnn(fn))(qenv(fn), 3, v63, v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    stack[-2] = v61;
    v62 = stack[-2];
    v61 = stack[-1];
    v61 = qcar(v61);
    fn = elt(env, 7); /* multd */
    stack[0] = (*qfn2(fn))(qenv(fn), v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    v62 = stack[-2];
    v61 = stack[-1];
    v61 = qcdr(v61);
    fn = elt(env, 7); /* multd */
    v61 = (*qfn2(fn))(qenv(fn), v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v68;
    {
        Lisp_Object v78 = stack[0];
        popv(5);
        return cons(v78, v61);
    }

v77:
    v62 = elt(env, 4); /* "field conversion" */
    v61 = stack[-2];
    v61 = list2(v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    fn = elt(env, 10); /* errach */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-4];
    goto v71;
/* error exit handlers */
v68:
    popv(5);
    return nil;
}



/* Code for kernord!-split */

static Lisp_Object CC_kernordKsplit(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v5)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v75, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernord-split");
#endif
    if (stack >= stacklimit)
    {
        push2(v5,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v5;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-1] = nil;
    v75 = stack[-3];
    v26 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* powers0 */
    v26 = (*qfn2(fn))(qenv(fn), v75, v26);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-5];
    stack[-3] = v26;
    v75 = stack[-2];
    v26 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* powers0 */
    v26 = (*qfn2(fn))(qenv(fn), v75, v26);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-5];
    stack[-2] = v26;
    v26 = stack[-3];
    stack[0] = v26;
    goto v97;

v97:
    v26 = stack[0];
    if (v26 == nil) goto v98;
    v26 = stack[0];
    v26 = qcar(v26);
    v95 = v26;
    v26 = v95;
    v75 = qcar(v26);
    v26 = stack[-2];
    v26 = Lassoc(nil, v75, v26);
    if (v26 == nil) goto v99;
    v75 = v95;
    v26 = stack[-1];
    v26 = cons(v75, v26);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-5];
    stack[-1] = v26;
    goto v100;

v100:
    v26 = stack[0];
    v26 = qcdr(v26);
    stack[0] = v26;
    goto v97;

v99:
    v75 = v95;
    v26 = stack[-4];
    v26 = cons(v75, v26);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-5];
    stack[-4] = v26;
    goto v100;

v98:
    v26 = stack[-2];
    stack[0] = v26;
    goto v49;

v49:
    v26 = stack[0];
    if (v26 == nil) goto v101;
    v26 = stack[0];
    v26 = qcar(v26);
    v95 = v26;
    v26 = v95;
    v75 = qcar(v26);
    v26 = stack[-3];
    v26 = Lassoc(nil, v75, v26);
    if (v26 == nil) goto v41;
    v75 = v95;
    v26 = stack[-1];
    v26 = cons(v75, v26);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-5];
    stack[-1] = v26;
    goto v102;

v102:
    v26 = stack[0];
    v26 = qcdr(v26);
    stack[0] = v26;
    goto v49;

v41:
    v75 = v95;
    v26 = stack[-4];
    v26 = cons(v75, v26);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-5];
    stack[-4] = v26;
    goto v102;

v101:
    v26 = stack[-4];
    v75 = Lnreverse(nil, v26);
    env = stack[-5];
    v26 = stack[-1];
    v26 = Lnreverse(nil, v26);
    popv(6);
    return cons(v75, v26);
/* error exit handlers */
v96:
    popv(6);
    return nil;
}



/* Code for gcref_remprops */

static Lisp_Object MS_CDECL CC_gcref_remprops(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v110, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "gcref_remprops");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcref_remprops");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v110 = qvalue(elt(env, 1)); /* seen!* */
    v88 = elt(env, 2); /* (gall calls globs calledby alsois sameas) */
    fn = elt(env, 13); /* rempropss */
    v88 = (*qfn2(fn))(qenv(fn), v110, v88);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[0];
    v110 = qvalue(elt(env, 1)); /* seen!* */
    v88 = elt(env, 3); /* (seen cinthis defd) */
    fn = elt(env, 14); /* remflagss */
    v88 = (*qfn2(fn))(qenv(fn), v110, v88);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[0];
    v110 = qvalue(elt(env, 4)); /* gcref_exportl!* */
    v88 = elt(env, 5); /* (exported) */
    fn = elt(env, 14); /* remflagss */
    v88 = (*qfn2(fn))(qenv(fn), v110, v88);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[0];
    v110 = qvalue(elt(env, 6)); /* gseen!* */
    v88 = elt(env, 7); /* (usedby usedunby boundby setby) */
    fn = elt(env, 13); /* rempropss */
    v88 = (*qfn2(fn))(qenv(fn), v110, v88);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[0];
    v110 = qvalue(elt(env, 6)); /* gseen!* */
    v88 = elt(env, 8); /* (dclglb gseen glb2rf glb2bd glb2st) */
    fn = elt(env, 14); /* remflagss */
    v88 = (*qfn2(fn))(qenv(fn), v110, v88);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[0];
    v88 = qvalue(elt(env, 9)); /* tseen!* */
    v111 = v88;
    goto v112;

v112:
    v88 = v111;
    if (v88 == nil) goto v113;
    v88 = v111;
    v88 = qcar(v88);
    v110 = qcar(v88);
    v88 = elt(env, 11); /* funs */
    v88 = Lremprop(nil, v110, v88);
    env = stack[0];
    v88 = v111;
    v88 = qcdr(v88);
    v111 = v88;
    goto v112;

v113:
    v88 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 9)) = v88; /* tseen!* */
    qvalue(elt(env, 1)) = v88; /* seen!* */
    qvalue(elt(env, 6)) = v88; /* gseen!* */
    qvalue(elt(env, 12)) = v88; /* haveargs!* */
    { popv(1); return onevalue(v88); }
/* error exit handlers */
v86:
    popv(1);
    return nil;
}



/* Code for rl_qefsolset */

static Lisp_Object MS_CDECL CC_rl_qefsolset(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v5,
                         Lisp_Object v6, Lisp_Object v20,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v70, v89, v116, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "rl_qefsolset");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_qefsolset");
#endif
    if (stack >= stacklimit)
    {
        push5(v17,v20,v6,v5,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v5,v6,v20,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v115 = v17;
    v70 = v20;
    v89 = v6;
    v116 = v5;
    v100 = v0;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* rl_qefsolset!* */
    stack[-2] = v100;
    stack[-1] = v116;
    stack[0] = v89;
    v115 = list2(v70, v115);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    v115 = list3star(stack[-2], stack[-1], stack[0], v115);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    {
        Lisp_Object v112 = stack[-3];
        popv(5);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v112, v115);
    }
/* error exit handlers */
v113:
    popv(5);
    return nil;
}



/* Code for rl_identifyonoff */

static Lisp_Object CC_rl_identifyonoff(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_identifyonoff");
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
    v3 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_identifyonoff!* */
    v3 = ncons(v3);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-1];
    {
        Lisp_Object v94 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v94, v3);
    }
/* error exit handlers */
v7:
    popv(2);
    return nil;
}



/* Code for get!-denom!-l */

static Lisp_Object CC_getKdenomKl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v119, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-denom-l");
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
    v119 = v0;
/* end of prologue */
    v55 = v119;
    v55 = qcar(v55);
    if (!consp(v55)) goto v17;
    v55 = v119;
    v55 = qcar(v55);
    v55 = qcdr(v55);
    v55 = qcdr(v55);
    goto v20;

v20:
    v119 = qcdr(v119);
    stack[0] = v119;
    goto v10;

v10:
    v119 = stack[0];
    if (v119 == nil) { popv(2); return onevalue(v55); }
    v119 = stack[0];
    v119 = qcar(v119);
    v103 = v119;
    v119 = v55;
    v55 = v103;
    if (!consp(v55)) goto v105;
    v55 = v103;
    v55 = qcdr(v55);
    v55 = qcdr(v55);
    goto v70;

v70:
    fn = elt(env, 2); /* lcmn */
    v55 = (*qfn2(fn))(qenv(fn), v119, v55);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    v119 = stack[0];
    v119 = qcdr(v119);
    stack[0] = v119;
    goto v10;

v105:
    v55 = (Lisp_Object)17; /* 1 */
    goto v70;

v17:
    v55 = (Lisp_Object)17; /* 1 */
    goto v20;
/* error exit handlers */
v76:
    popv(2);
    return nil;
}



/* Code for exptf1 */

static Lisp_Object CC_exptf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v5)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptf1");
#endif
    if (stack >= stacklimit)
    {
        push2(v5,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v5;
    stack[-1] = v0;
/* end of prologue */
    v92 = stack[0];
    v91 = (Lisp_Object)1; /* 0 */
    if (v92 == v91) goto v56;
    v91 = stack[-1];
    stack[-2] = v91;
    goto v122;

v122:
    v91 = stack[0];
    v92 = sub1(v91);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    stack[0] = v92;
    v91 = (Lisp_Object)1; /* 0 */
    v91 = (Lisp_Object)greaterp2(v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v55;
    v91 = v91 ? lisp_true : nil;
    env = stack[-3];
    if (v91 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v92 = stack[-1];
    v91 = stack[-2];
    fn = elt(env, 2); /* multf */
    v91 = (*qfn2(fn))(qenv(fn), v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    stack[-2] = v91;
    goto v122;

v56:
    v91 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v91); }
/* error exit handlers */
v55:
    popv(4);
    return nil;
}



/* Code for sfto_sqfpartf */

static Lisp_Object CC_sfto_sqfpartf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_sqfpartf");
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
    v127 = stack[-3];
    if (!consp(v127)) goto v4;
    v127 = stack[-3];
    v127 = qcar(v127);
    v127 = (consp(v127) ? nil : lisp_true);
    goto v3;

v3:
    if (v127 == nil) goto v2;
    v127 = (Lisp_Object)17; /* 1 */
    { popv(6); return onevalue(v127); }

v2:
    v127 = stack[-3];
    fn = elt(env, 2); /* sfto_ucontentf */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    stack[0] = v127;
    v87 = stack[-3];
    v127 = stack[0];
    fn = elt(env, 3); /* quotf */
    v127 = (*qfn2(fn))(qenv(fn), v87, v127);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    stack[-4] = v127;
    v127 = stack[0];
    stack[-2] = CC_sfto_sqfpartf(env, v127);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    stack[-1] = stack[-4];
    stack[0] = stack[-4];
    v87 = stack[-4];
    v127 = stack[-3];
    v127 = qcar(v127);
    v127 = qcar(v127);
    v127 = qcar(v127);
    fn = elt(env, 4); /* diff */
    v127 = (*qfn2(fn))(qenv(fn), v87, v127);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    fn = elt(env, 5); /* sfto_gcdf!* */
    v127 = (*qfn2(fn))(qenv(fn), stack[0], v127);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    fn = elt(env, 3); /* quotf */
    v127 = (*qfn2(fn))(qenv(fn), stack[-1], v127);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    {
        Lisp_Object v49 = stack[-2];
        popv(6);
        fn = elt(env, 6); /* multf */
        return (*qfn2(fn))(qenv(fn), v49, v127);
    }

v4:
    v127 = qvalue(elt(env, 1)); /* t */
    goto v3;
/* error exit handlers */
v51:
    popv(6);
    return nil;
}



/* Code for unaryir */

static Lisp_Object CC_unaryir(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v5)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unaryir");
#endif
    if (stack >= stacklimit)
    {
        push2(v5,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v5;
    stack[-1] = v0;
/* end of prologue */
    v105 = qvalue(elt(env, 1)); /* atts */
    v104 = elt(env, 2); /* name */
    fn = elt(env, 4); /* find */
    v104 = (*qfn2(fn))(qenv(fn), v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-3];
    v104 = Lintern(nil, v104);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-3];
    stack[-2] = v104;
    v105 = qvalue(elt(env, 1)); /* atts */
    v104 = elt(env, 3); /* cd */
    fn = elt(env, 4); /* find */
    v104 = (*qfn2(fn))(qenv(fn), v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-3];
    v104 = Lintern(nil, v104);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-3];
    v105 = v104;
    v104 = stack[-1];
    if (equal(v105, v104)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v104 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); /* encodeir */
        return (*qfn1(fn))(qenv(fn), v104);
    }
/* error exit handlers */
v112:
    popv(4);
    return nil;
}



/* Code for ft!:zerop */

static Lisp_Object CC_ftTzerop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v112;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ft:zerop");
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
    v113 = v0;
/* end of prologue */
    stack[0] = v113;
    v112 = (Lisp_Object)161; /* 10 */
    v113 = qvalue(elt(env, 1)); /* !:prec!: */
    v113 = Lexpt(nil, v112, v113);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-1];
    v113 = times2(stack[0], v113);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-1];
    stack[0] = v113;
    v112 = stack[0];
    v113 = (Lisp_Object)-799; /* -50 */
    v113 = (Lisp_Object)greaterp2(v112, v113);
    nil = C_nil;
    if (exception_pending()) goto v123;
    v113 = v113 ? lisp_true : nil;
    env = stack[-1];
    if (v113 == nil) goto v64;
    v112 = stack[0];
    v113 = (Lisp_Object)801; /* 50 */
        popv(2);
        return Llessp(nil, v112, v113);

v64:
    v113 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v113); }
/* error exit handlers */
v123:
    popv(2);
    return nil;
}



/* Code for vevdif */

static Lisp_Object CC_vevdif(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v5)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevdif");
#endif
    if (stack >= stacklimit)
    {
        push2(v5,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v5;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = nil;
    v26 = nil;
    v133 = stack[-4];
    stack[-1] = v133;
    v133 = stack[-3];
    stack[0] = v133;
    goto v94;

v94:
    v133 = stack[-1];
    if (v133 == nil) goto v7;
    v133 = stack[0];
    if (v133 == nil) goto v7;
    v133 = v26;
    if (!(v133 == nil)) goto v7;
    v133 = stack[-1];
    v26 = qcar(v133);
    v133 = stack[0];
    v133 = qcar(v133);
    v133 = (Lisp_Object)(int32_t)((int32_t)v26 - (int32_t)v133 + TAG_FIXNUM);
    stack[-2] = v133;
    v26 = stack[-2];
    v133 = stack[-5];
    v133 = cons(v26, v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    stack[-5] = v133;
    v26 = stack[-2];
    v133 = (Lisp_Object)1; /* 0 */
    v133 = ((intptr_t)v26 < (intptr_t)v133) ? lisp_true : nil;
    v26 = v133;
    v133 = stack[-1];
    v133 = qcdr(v133);
    stack[-1] = v133;
    v133 = stack[0];
    v133 = qcdr(v133);
    stack[0] = v133;
    goto v94;

v7:
    v133 = v26;
    if (!(v133 == nil)) goto v135;
    v133 = stack[0];
    if (v133 == nil) goto v101;
    v133 = stack[0];
    if (v133 == nil) goto v111;
    v133 = stack[0];
    v26 = qcar(v133);
    v133 = (Lisp_Object)1; /* 0 */
    if (v26 == v133) goto v136;
    v133 = qvalue(elt(env, 1)); /* nil */
    goto v110;

v110:
    if (!(v133 == nil)) goto v101;

v135:
    v133 = stack[-4];
    v133 = Lprint(nil, v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    v133 = stack[-3];
    v133 = Lprint(nil, v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    v133 = elt(env, 3); /* backtrace */
    fn = elt(env, 7); /* getd */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    if (v133 == nil) goto v46;
    fn = elt(env, 3); /* backtrace */
    v133 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    goto v46;

v46:
    v133 = elt(env, 4); /* "Vevdif, difference would be < 0" */
    v26 = v133;
    v133 = v26;
    qvalue(elt(env, 5)) = v133; /* errmsg!* */
    v133 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v133 == nil)) goto v137;
    v133 = v26;
    fn = elt(env, 8); /* lprie */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    goto v137;

v137:
    v133 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v133 = nil;
    { popv(7); return onevalue(v133); }

v101:
    v133 = stack[-5];
    v26 = Lnreverse(nil, v133);
    v133 = stack[-1];
        popv(7);
        return Lnconc(nil, v26, v133);

v136:
    v133 = stack[0];
    v133 = qcdr(v133);
    fn = elt(env, 9); /* vevzero!?1 */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    goto v110;

v111:
    v133 = qvalue(elt(env, 2)); /* t */
    goto v110;
/* error exit handlers */
v134:
    popv(7);
    return nil;
}



/* Code for nconc2 */

static Lisp_Object CC_nconc2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v5)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v89, v116;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nconc2");
#endif
    if (stack >= stacklimit)
    {
        push2(v5,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v89 = v5;
    v116 = v0;
/* end of prologue */
    v70 = v116;
    if (!consp(v70)) { popv(2); return onevalue(v89); }
    v70 = v116;
    stack[0] = v70;
    goto v8;

v8:
    v70 = stack[0];
    v70 = qcdr(v70);
    v70 = Lconsp(nil, v70);
    env = stack[-1];
    if (v70 == nil) goto v60;
    v70 = stack[0];
    v70 = qcdr(v70);
    stack[0] = v70;
    goto v8;

v60:
    v70 = stack[0];
    v70 = Lrplacd(nil, v70, v89);
    nil = C_nil;
    if (exception_pending()) goto v104;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v104:
    popv(2);
    return nil;
}



/* Code for getphystypeor */

static Lisp_Object CC_getphystypeor(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystypeor");
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

v138:
    v10 = stack[0];
    if (!consp(v10)) goto v109;
    v10 = stack[0];
    v10 = qcar(v10);
    fn = elt(env, 2); /* getphystype */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    if (!(v10 == nil)) { popv(2); return onevalue(v10); }
    v10 = stack[0];
    v10 = qcdr(v10);
    stack[0] = v10;
    goto v138;

v109:
    v10 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v10); }
/* error exit handlers */
v12:
    popv(2);
    return nil;
}



/* Code for nfactorial */

static Lisp_Object CC_nfactorial(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v139, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nfactorial");
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
    v135 = stack[-1];
    v139 = (Lisp_Object)321; /* 20 */
    v139 = (Lisp_Object)greaterp2(v135, v139);
    nil = C_nil;
    if (exception_pending()) goto v53;
    v139 = v139 ? lisp_true : nil;
    env = stack[-3];
    if (v139 == nil) goto v64;
    v135 = (Lisp_Object)17; /* 1 */
    v139 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* fac!-part */
        return (*qfn2(fn))(qenv(fn), v135, v139);
    }

v64:
    v139 = (Lisp_Object)17; /* 1 */
    stack[-2] = v139;
    v139 = (Lisp_Object)17; /* 1 */
    stack[0] = v139;
    goto v104;

v104:
    v135 = stack[-1];
    v139 = stack[0];
    v139 = difference2(v135, v139);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    v139 = Lminusp(nil, v139);
    env = stack[-3];
    if (!(v139 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v135 = stack[-2];
    v139 = stack[0];
    v139 = times2(v135, v139);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    stack[-2] = v139;
    v139 = stack[0];
    v139 = add1(v139);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    stack[0] = v139;
    goto v104;
/* error exit handlers */
v53:
    popv(4);
    return nil;
}



/* Code for begin11 */

static Lisp_Object CC_begin11(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v200, v201, v202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for begin11");
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
    stack[-5] = qvalue(elt(env, 1)); /* errmsg!* */
    qvalue(elt(env, 1)) = nil; /* errmsg!* */
    stack[-3] = nil;
    stack[-2] = qvalue(elt(env, 2)); /* newrule!* */
    qvalue(elt(env, 2)) = nil; /* newrule!* */
    v201 = qvalue(elt(env, 3)); /* cursym!* */
    v200 = elt(env, 4); /* end */
    if (v201 == v200) goto v126;
    v200 = qvalue(elt(env, 12)); /* !*reduce4 */
    if (v200 == nil) goto v55;
    v200 = stack[-4];
    v201 = v200;
    goto v113;

v113:
    v200 = elt(env, 13); /* retry */
    if (!consp(v201)) goto v117;
    v201 = qcar(v201);
    if (!(v201 == v200)) goto v117;
    v200 = qvalue(elt(env, 14)); /* programl!* */
    if (v200 == nil) goto v125;
    v200 = qvalue(elt(env, 14)); /* programl!* */
    stack[-4] = v200;
    goto v117;

v117:
    v200 = qvalue(elt(env, 12)); /* !*reduce4 */
    if (!(v200 == nil)) goto v203;
    v200 = stack[-4];
    v200 = qcar(v200);
    stack[-3] = v200;
    v200 = stack[-4];
    v200 = qcdr(v200);
    v200 = qcar(v200);
    stack[-4] = v200;
    goto v203;

v203:
    v200 = stack[-4];
    qvalue(elt(env, 18)) = v200; /* program!* */
    v201 = qvalue(elt(env, 18)); /* program!* */
    v200 = qvalue(elt(env, 19)); /* !$eof!$ */
    if (v201 == v200) goto v80;
    v200 = qvalue(elt(env, 11)); /* nil */
    goto v204;

v204:
    if (v200 == nil) goto v95;
    v200 = elt(env, 22); /* c */
    goto v2;

v2:
    qvalue(elt(env, 2)) = stack[-2]; /* newrule!* */
    qvalue(elt(env, 1)) = stack[-5]; /* errmsg!* */
    { popv(7); return onevalue(v200); }

v95:
    v200 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 21)) = v200; /* eof!* */
    v201 = stack[-4];
    v200 = qvalue(elt(env, 12)); /* !*reduce4 */
    if (v200 == nil) goto v205;
    v200 = qvalue(elt(env, 11)); /* nil */
    goto v206;

v206:
    fn = elt(env, 53); /* add2inputbuf */
    v200 = (*qfn2(fn))(qenv(fn), v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    v200 = stack[-4];
    if (!consp(v200)) goto v74;
    v200 = stack[-4];
    v201 = qcar(v200);
    v200 = elt(env, 23); /* (bye quit) */
    v200 = Lmemq(nil, v201, v200);
    goto v208;

v208:
    if (v200 == nil) goto v209;
    v200 = elt(env, 24); /* bye */
    fn = elt(env, 54); /* getd */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    if (v200 == nil) goto v29;
    v200 = stack[-4];
    fn = elt(env, 34); /* eval */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    v200 = qvalue(elt(env, 9)); /* t */
    qvalue(elt(env, 10)) = v200; /* !*nosave!* */
    v200 = qvalue(elt(env, 11)); /* nil */
    goto v2;

v29:
    v200 = qvalue(elt(env, 9)); /* t */
    qvalue(elt(env, 25)) = v200; /* !*byeflag!* */
    v200 = qvalue(elt(env, 11)); /* nil */
    goto v2;

v209:
    v200 = qvalue(elt(env, 12)); /* !*reduce4 */
    if (v200 == nil) goto v210;
    v200 = qvalue(elt(env, 11)); /* nil */
    goto v66;

v66:
    if (v200 == nil) goto v211;
    v200 = elt(env, 27); /* cedit */
    fn = elt(env, 54); /* getd */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    if (v200 == nil) goto v212;
    v200 = qvalue(elt(env, 5)); /* !*int */
    if (v200 == nil) goto v212;
    v200 = qvalue(elt(env, 6)); /* ifl!* */
    if (!(v200 == nil)) goto v212;
    v200 = stack[-4];
    v200 = qcdr(v200);
    fn = elt(env, 27); /* cedit */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    goto v22;

v22:
    v200 = qvalue(elt(env, 9)); /* t */
    qvalue(elt(env, 10)) = v200; /* !*nosave!* */
    v200 = qvalue(elt(env, 11)); /* nil */
    goto v2;

v212:
    v200 = qvalue(elt(env, 15)); /* !*msg */
    if (v200 == nil) goto v22;
    v201 = elt(env, 16); /* "***" */
    v200 = elt(env, 28); /* "ED not supported" */
    fn = elt(env, 55); /* lpriw */
    v200 = (*qfn2(fn))(qenv(fn), v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    goto v22;

v211:
    v200 = qvalue(elt(env, 29)); /* !*defn */
    if (v200 == nil) goto v213;
    v200 = qvalue(elt(env, 30)); /* erfg!* */
    if (v200 == nil) goto v214;
    v200 = qvalue(elt(env, 11)); /* nil */
    goto v2;

v214:
    v201 = qvalue(elt(env, 31)); /* key!* */
    v200 = elt(env, 32); /* ignore */
    v200 = Lflagp(nil, v201, v200);
    env = stack[-6];
    if (v200 == nil) goto v215;
    v200 = qvalue(elt(env, 11)); /* nil */
    goto v216;

v216:
    if (v200 == nil) goto v213;
    v200 = stack[-4];
    if (v200 == nil) goto v217;
    v200 = stack[-4];
    fn = elt(env, 56); /* dfprint */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    goto v217;

v217:
    v201 = qvalue(elt(env, 31)); /* key!* */
    v200 = elt(env, 34); /* eval */
    v200 = Lflagp(nil, v201, v200);
    env = stack[-6];
    if (!(v200 == nil)) goto v213;
    v200 = qvalue(elt(env, 11)); /* nil */
    goto v2;

v213:
    v200 = qvalue(elt(env, 35)); /* !*output */
    if (v200 == nil) goto v218;
    v200 = qvalue(elt(env, 6)); /* ifl!* */
    if (v200 == nil) goto v218;
    v200 = qvalue(elt(env, 36)); /* !*echo */
    if (v200 == nil) goto v218;
    v200 = qvalue(elt(env, 37)); /* !*lessspace */
    if (!(v200 == nil)) goto v218;
    v200 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    goto v218;

v218:
    v202 = stack[-4];
    v201 = qvalue(elt(env, 9)); /* t */
    v200 = qvalue(elt(env, 38)); /* !*backtrace */
    fn = elt(env, 57); /* errorset */
    v200 = (*qfnn(fn))(qenv(fn), 3, v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    stack[0] = v200;
    v200 = stack[0];
    if (!consp(v200)) goto v219;
    v200 = stack[0];
    v200 = qcdr(v200);
    goto v220;

v220:
    if (!(v200 == nil)) goto v221;
    v200 = qvalue(elt(env, 30)); /* erfg!* */
    if (!(v200 == nil)) goto v221;
    v200 = qvalue(elt(env, 29)); /* !*defn */
    if (v200 == nil) goto v222;
    v200 = qvalue(elt(env, 11)); /* nil */
    goto v2;

v222:
    v200 = qvalue(elt(env, 12)); /* !*reduce4 */
    if (v200 == nil) goto v223;
    v200 = stack[0];
    v200 = qcar(v200);
    stack[0] = v200;
    v200 = stack[0];
    if (!(v200 == nil)) goto v224;
    v201 = qvalue(elt(env, 11)); /* nil */
    v200 = elt(env, 41); /* noval */
    fn = elt(env, 58); /* mkobject */
    v200 = (*qfn2(fn))(qenv(fn), v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    stack[0] = v200;
    goto v224;

v224:
    v200 = stack[0];
    fn = elt(env, 59); /* type */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    stack[-3] = v200;
    v200 = stack[0];
    fn = elt(env, 60); /* value */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    stack[0] = v200;
    goto v225;

v225:
    v200 = qvalue(elt(env, 12)); /* !*reduce4 */
    if (v200 == nil) goto v226;
    v200 = stack[0];
    v201 = v200;
    goto v227;

v227:
    v200 = stack[-3];
    fn = elt(env, 61); /* add2resultbuf */
    v200 = (*qfn2(fn))(qenv(fn), v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    v200 = qvalue(elt(env, 35)); /* !*output */
    if (v200 == nil) goto v228;
    v201 = qvalue(elt(env, 42)); /* semic!* */
    v200 = elt(env, 43); /* !$ */
    if (v201 == v200) goto v229;
    v200 = qvalue(elt(env, 12)); /* !*reduce4 */
    if (v200 == nil) goto v230;
    v200 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    v201 = stack[-3];
    v200 = elt(env, 41); /* noval */
    if (v201 == v200) goto v229;
    v200 = qvalue(elt(env, 44)); /* !*debug */
    if (v200 == nil) goto v231;
    v200 = elt(env, 45); /* "Value:" */
    v200 = Lprinc(nil, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    v200 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    goto v231;

v231:
    stack[-1] = elt(env, 46); /* print */
    v201 = stack[-3];
    v200 = stack[0];
    v200 = list2(v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    v200 = ncons(v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    fn = elt(env, 62); /* rapply1 */
    v200 = (*qfn2(fn))(qenv(fn), stack[-1], v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    goto v229;

v229:
    v200 = qvalue(elt(env, 12)); /* !*reduce4 */
    if (v200 == nil) goto v232;
    v201 = qvalue(elt(env, 47)); /* !*mode */
    v200 = elt(env, 41); /* noval */
    if (v201 == v200) goto v233;
    v200 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    v200 = elt(env, 52); /* "of type: " */
    v200 = Lprinc(nil, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    v200 = stack[-3];
    v200 = Lprint(nil, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    goto v233;

v233:
    v200 = qvalue(elt(env, 11)); /* nil */
    goto v2;

v232:
    v200 = stack[0];
    if (!consp(v200)) goto v234;
    v200 = stack[0];
    v200 = qcdr(v200);
    goto v235;

v235:
    if (v200 == nil) goto v236;
    v200 = elt(env, 51); /* err3 */
    goto v2;

v236:
    v200 = qvalue(elt(env, 11)); /* nil */
    goto v2;

v234:
    v200 = qvalue(elt(env, 9)); /* t */
    goto v235;

v230:
    v201 = stack[-3];
    v200 = elt(env, 40); /* symbolic */
    if (v201 == v200) goto v237;
    v200 = stack[0];
    v200 = qcar(v200);
    if (v200 == nil) goto v229;
    stack[-1] = elt(env, 48); /* assgnpri */
    v200 = stack[0];
    v200 = qcar(v200);
    stack[0] = Lmkquote(nil, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    v200 = stack[-4];
    if (v200 == nil) goto v238;
    v201 = elt(env, 49); /* list */
    v200 = stack[-4];
    v200 = cons(v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    stack[-4] = v200;
    goto v239;

v239:
    v200 = elt(env, 50); /* only */
    v200 = Lmkquote(nil, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    v202 = list4(stack[-1], stack[0], stack[-4], v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    v201 = qvalue(elt(env, 9)); /* t */
    v200 = qvalue(elt(env, 38)); /* !*backtrace */
    fn = elt(env, 57); /* errorset */
    v200 = (*qfnn(fn))(qenv(fn), 3, v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    stack[0] = v200;
    goto v229;

v238:
    v200 = qvalue(elt(env, 11)); /* nil */
    stack[-4] = v200;
    goto v239;

v237:
    v200 = stack[0];
    v200 = qcar(v200);
    if (v200 == nil) goto v240;
    v200 = qvalue(elt(env, 11)); /* nil */
    goto v241;

v241:
    if (!(v200 == nil)) goto v229;
    v200 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    stack[-1] = elt(env, 46); /* print */
    v200 = stack[0];
    v200 = qcar(v200);
    v200 = Lmkquote(nil, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    v202 = list2(stack[-1], v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    v201 = qvalue(elt(env, 9)); /* t */
    v200 = qvalue(elt(env, 38)); /* !*backtrace */
    fn = elt(env, 57); /* errorset */
    v200 = (*qfnn(fn))(qenv(fn), 3, v202, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    stack[0] = v200;
    goto v229;

v240:
    v201 = qvalue(elt(env, 47)); /* !*mode */
    v200 = elt(env, 40); /* symbolic */
    v200 = (v201 == v200 ? lisp_true : nil);
    v200 = (v200 == nil ? lisp_true : nil);
    goto v241;

v228:
    v200 = qvalue(elt(env, 11)); /* nil */
    goto v2;

v226:
    v200 = stack[0];
    v200 = qcar(v200);
    v201 = v200;
    goto v227;

v223:
    v201 = stack[-3];
    v200 = elt(env, 40); /* symbolic */
    if (v201 == v200) goto v225;
    v200 = stack[-4];
    fn = elt(env, 63); /* getsetvars */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    stack[-4] = v200;
    goto v225;

v221:
    v201 = stack[-3];
    v200 = stack[-4];
    v200 = list2(v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    qvalue(elt(env, 14)) = v200; /* programl!* */
    v200 = elt(env, 39); /* err2 */
    goto v2;

v219:
    v200 = qvalue(elt(env, 9)); /* t */
    goto v220;

v215:
    v201 = stack[-4];
    v200 = elt(env, 33); /* quote */
    v200 = Leqcar(nil, v201, v200);
    env = stack[-6];
    v200 = (v200 == nil ? lisp_true : nil);
    goto v216;

v210:
    v201 = stack[-4];
    v200 = elt(env, 26); /* ed */
    v200 = Leqcar(nil, v201, v200);
    env = stack[-6];
    goto v66;

v74:
    v200 = qvalue(elt(env, 11)); /* nil */
    goto v208;

v205:
    v200 = stack[-3];
    goto v206;

v80:
    v201 = qvalue(elt(env, 20)); /* ttype!* */
    v200 = (Lisp_Object)49; /* 3 */
    if (v201 == v200) goto v71;
    v200 = qvalue(elt(env, 11)); /* nil */
    goto v204;

v71:
    v200 = qvalue(elt(env, 21)); /* eof!* */
    v200 = add1(v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    qvalue(elt(env, 21)) = v200; /* eof!* */
    goto v204;

v125:
    v200 = qvalue(elt(env, 15)); /* !*msg */
    if (v200 == nil) goto v88;
    v201 = elt(env, 16); /* "***" */
    v200 = elt(env, 17); /* "No previous expression" */
    fn = elt(env, 55); /* lpriw */
    v200 = (*qfn2(fn))(qenv(fn), v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    goto v88;

v88:
    v200 = qvalue(elt(env, 11)); /* nil */
    goto v2;

v55:
    v200 = stack[-4];
    v200 = qcdr(v200);
    v200 = qcar(v200);
    v201 = v200;
    goto v113;

v126:
    v200 = qvalue(elt(env, 5)); /* !*int */
    if (v200 == nil) goto v114;
    v200 = qvalue(elt(env, 6)); /* ifl!* */
    if (!(v200 == nil)) goto v114;
    v200 = qvalue(elt(env, 7)); /* !*lisp_hook */
    if (!(v200 == nil)) goto v114;
    v200 = elt(env, 8); /* !*semicol!* */
    qvalue(elt(env, 3)) = v200; /* cursym!* */
    v200 = qvalue(elt(env, 9)); /* t */
    qvalue(elt(env, 10)) = v200; /* !*nosave!* */
    v200 = qvalue(elt(env, 11)); /* nil */
    goto v2;

v114:
    v200 = elt(env, 4); /* end */
    fn = elt(env, 64); /* comm1 */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    v200 = elt(env, 4); /* end */
    goto v2;
/* error exit handlers */
v207:
    env = stack[-6];
    qvalue(elt(env, 2)) = stack[-2]; /* newrule!* */
    qvalue(elt(env, 1)) = stack[-5]; /* errmsg!* */
    popv(7);
    return nil;
}



/* Code for bas_newnumber */

static Lisp_Object CC_bas_newnumber(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v5)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v7;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bas_newnumber");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v5;
    v7 = v0;
/* end of prologue */
    v4 = qcdr(v4);
    return cons(v7, v4);
}



/* Code for gcdout */

static Lisp_Object CC_gcdout(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v47, v243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdout");
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
    v131 = qvalue(elt(env, 1)); /* !*modular */
    if (!(v131 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v131 = stack[0];
    if (v131 == nil) goto v1;
    v131 = stack[0];
    fn = elt(env, 3); /* ljet */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-2];
    fn = elt(env, 4); /* ord */
    v47 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-2];
    v131 = (Lisp_Object)1; /* 0 */
    if (v47 == v131) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v131 = stack[0];
    stack[-1] = v131;
    v131 = stack[-1];
    v131 = qcar(v131);
    v131 = qcdr(v131);
    v243 = v131;
    goto v89;

v89:
    v131 = stack[-1];
    if (v131 == nil) goto v110;
    v47 = v243;
    v131 = (Lisp_Object)17; /* 1 */
    if (v47 == v131) goto v110;
    v47 = v243;
    v131 = stack[-1];
    v131 = qcar(v131);
    v131 = qcdr(v131);
    fn = elt(env, 5); /* gcdf!* */
    v131 = (*qfn2(fn))(qenv(fn), v47, v131);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-2];
    v243 = v131;
    v131 = stack[-1];
    v131 = qcdr(v131);
    stack[-1] = v131;
    goto v89;

v110:
    v47 = v243;
    v131 = (Lisp_Object)17; /* 1 */
    if (v47 == v131) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v131 = stack[0];
    v47 = v243;
    {
        popv(3);
        fn = elt(env, 6); /* pcdiv */
        return (*qfn2(fn))(qenv(fn), v131, v47);
    }

v1:
    v131 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v131); }
/* error exit handlers */
v244:
    popv(3);
    return nil;
}



/* Code for dv_ind2var */

static Lisp_Object CC_dv_ind2var(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_ind2var");
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
    stack[-1] = stack[0];
    v115 = qvalue(elt(env, 1)); /* g_dvnames */
    fn = elt(env, 3); /* upbve */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    v115 = (Lisp_Object)lesseq2(stack[-1], v115);
    nil = C_nil;
    if (exception_pending()) goto v100;
    v115 = v115 ? lisp_true : nil;
    env = stack[-2];
    if (v115 == nil) goto v60;
    stack[-1] = qvalue(elt(env, 1)); /* g_dvnames */
    v115 = stack[0];
    v115 = sub1(v115);
    nil = C_nil;
    if (exception_pending()) goto v100;
    v115 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v115/(16/CELL)));
    { popv(3); return onevalue(v115); }

v60:
    v70 = qvalue(elt(env, 2)); /* g_dvbase */
    v115 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* mkid */
        return (*qfn2(fn))(qenv(fn), v70, v115);
    }
/* error exit handlers */
v100:
    popv(3);
    return nil;
}



/* Code for ilog2 */

static Lisp_Object CC_ilog2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v250, v196, v197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ilog2");
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
    v196 = stack[-2];
    v250 = (Lisp_Object)1; /* 0 */
    v250 = (Lisp_Object)lesseq2(v196, v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    v250 = v250 ? lisp_true : nil;
    env = stack[-4];
    if (v250 == nil) goto v1;
    stack[0] = (Lisp_Object)1; /* 0 */
    v197 = stack[-2];
    v196 = elt(env, 1); /* " invalid for " */
    v250 = elt(env, 0); /* ilog2 */
    v250 = list3(v197, v196, v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    fn = elt(env, 3); /* error */
    v250 = (*qfn2(fn))(qenv(fn), stack[0], v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    goto v1;

v1:
    v250 = (Lisp_Object)33; /* 2 */
    stack[0] = v250;
    v250 = stack[0];
    v250 = ncons(v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    stack[-1] = v250;
    goto v92;

v92:
    v196 = stack[-2];
    v250 = stack[0];
    v250 = (Lisp_Object)greaterp2(v196, v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    v250 = v250 ? lisp_true : nil;
    env = stack[-4];
    if (v250 == nil) goto v57;
    v196 = stack[0];
    v250 = stack[-1];
    v250 = cons(v196, v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    stack[-1] = v250;
    v196 = stack[0];
    v250 = stack[0];
    v250 = times2(v196, v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    stack[0] = v250;
    goto v92;

v57:
    v250 = (Lisp_Object)1; /* 0 */
    stack[-3] = v250;
    goto v199;

v199:
    v250 = stack[-1];
    v196 = qcar(v250);
    stack[0] = v196;
    v250 = (Lisp_Object)33; /* 2 */
    if (v196 == v250) goto v26;
    v250 = stack[-1];
    v250 = qcdr(v250);
    stack[-1] = v250;
    v196 = stack[-2];
    v250 = stack[0];
    v250 = (Lisp_Object)geq2(v196, v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    v250 = v250 ? lisp_true : nil;
    env = stack[-4];
    if (v250 == nil) goto v252;
    v196 = stack[-2];
    v250 = stack[0];
    v250 = quot2(v196, v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    stack[-2] = v250;
    v250 = stack[-3];
    v250 = add1(v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    stack[-3] = v250;
    goto v252;

v252:
    v196 = stack[-3];
    v250 = (Lisp_Object)33; /* 2 */
    v250 = times2(v196, v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    stack[-3] = v250;
    goto v199;

v26:
    v196 = stack[-2];
    v250 = (Lisp_Object)33; /* 2 */
    v250 = (Lisp_Object)geq2(v196, v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    v250 = v250 ? lisp_true : nil;
    env = stack[-4];
    if (v250 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v250 = stack[-3];
    v250 = add1(v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    stack[-3] = v250;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v251:
    popv(5);
    return nil;
}



/* Code for outrdefun */

static Lisp_Object MS_CDECL CC_outrdefun(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v5,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v256, v257;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "outrdefun");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for outrdefun");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v5,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v5,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v5;
    stack[-2] = v0;
/* end of prologue */
    v257 = stack[-2];
    v256 = stack[-1];
    fn = elt(env, 16); /* qtypnm */
    v256 = (*qfn2(fn))(qenv(fn), v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-4];
    stack[-2] = v256;
    v257 = stack[-2];
    v256 = elt(env, 1); /* defd */
    v256 = Lflagp(nil, v257, v256);
    env = stack[-4];
    if (v256 == nil) goto v116;
    v257 = stack[-2];
    v256 = stack[-1];
    fn = elt(env, 17); /* recref */
    v256 = (*qfn2(fn))(qenv(fn), v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-4];
    goto v103;

v103:
    v257 = stack[-1];
    v256 = elt(env, 2); /* function */
    v256 = Lflagp(nil, v257, v256);
    env = stack[-4];
    if (v256 == nil) goto v203;
    v257 = stack[-2];
    v256 = elt(env, 3); /* dclglb */
    v256 = Lflagp(nil, v257, v256);
    env = stack[-4];
    if (v256 == nil) goto v259;
    v256 = qvalue(elt(env, 4)); /* t */
    goto v132;

v132:
    if (v256 == nil) goto v123;
    v256 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 18); /* qerline */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-4];
    v256 = elt(env, 7); /* "**** Variable " */
    v256 = Lprinc(nil, v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-4];
    v256 = stack[-2];
    fn = elt(env, 19); /* princng */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-4];
    v256 = elt(env, 8); /* " defined as function" */
    v256 = Lprinc(nil, v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-4];
    v256 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 20); /* newline */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-4];
    goto v123;

v123:
    v256 = stack[0];
    if (v256 == nil) goto v26;
    v257 = stack[-1];
    v256 = elt(env, 9); /* naryarg */
    v256 = Lflagp(nil, v257, v256);
    env = stack[-4];
    if (!(v256 == nil)) goto v26;
    v257 = stack[-2];
    v256 = stack[0];
    fn = elt(env, 21); /* defineargs */
    v256 = (*qfn2(fn))(qenv(fn), v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-4];
    goto v34;

v34:
    stack[-3] = stack[-2];
    stack[0] = elt(env, 11); /* gall */
    v257 = qvalue(elt(env, 12)); /* curlin!* */
    v256 = stack[-1];
    v256 = cons(v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-4];
    v256 = Lputprop(nil, 3, stack[-3], stack[0], v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-4];
    v256 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 13)) = v256; /* globs!* */
    v256 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 14)) = v256; /* calls!* */
    v256 = stack[-2];
    qvalue(elt(env, 15)) = v256; /* curfun!* */
    { popv(5); return onevalue(v256); }

v26:
    v257 = stack[-1];
    v256 = elt(env, 9); /* naryarg */
    v256 = Lflagp(nil, v257, v256);
    env = stack[-4];
    if (v256 == nil) goto v260;
    v257 = stack[-2];
    v256 = elt(env, 10); /* naryargs */
    v256 = Lflagp(nil, v257, v256);
    env = stack[-4];
    v256 = (v256 == nil ? lisp_true : nil);
    goto v79;

v79:
    if (v256 == nil) goto v34;
    v256 = stack[-2];
    v257 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-4];
    v256 = elt(env, 10); /* naryargs */
    v256 = Lflag(nil, v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-4];
    goto v34;

v260:
    v256 = qvalue(elt(env, 6)); /* nil */
    goto v79;

v259:
    v257 = stack[-2];
    v256 = qvalue(elt(env, 5)); /* locls!* */
    v256 = Lassoc(nil, v257, v256);
    goto v132;

v203:
    v256 = qvalue(elt(env, 6)); /* nil */
    goto v132;

v116:
    v256 = stack[-2];
    v257 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-4];
    v256 = elt(env, 1); /* defd */
    v256 = Lflag(nil, v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-4];
    goto v103;
/* error exit handlers */
v258:
    popv(5);
    return nil;
}



/* Code for rl_transform */

static Lisp_Object CC_rl_transform(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v5)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_transform");
#endif
    if (stack >= stacklimit)
    {
        push2(v5,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v9 = v5;
    v10 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_transform!* */
    v9 = list2(v10, v9);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    {
        Lisp_Object v64 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v64, v9);
    }
/* error exit handlers */
v12:
    popv(2);
    return nil;
}



/* Code for super_der_simp */

static Lisp_Object CC_super_der_simp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v167, v321, v322;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for super_der_simp");
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
    v167 = stack[-9];
    v321 = Llength(nil, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = (Lisp_Object)33; /* 2 */
    if (v321 == v167) goto v17;
    v167 = stack[-9];
    {
        popv(12);
        fn = elt(env, 7); /* simpiden */
        return (*qfn1(fn))(qenv(fn), v167);
    }

v17:
    v167 = stack[-9];
    v167 = qcar(v167);
    fn = elt(env, 8); /* reval */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    stack[-10] = v167;
    v321 = stack[-10];
    v167 = elt(env, 1); /* variables */
    v167 = get(v321, v167);
    env = stack[-11];
    stack[-8] = v167;
    v167 = stack[-9];
    v167 = qcdr(v167);
    v167 = qcar(v167);
    fn = elt(env, 9); /* simp!* */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    stack[-9] = v167;
    v167 = stack[-9];
    v321 = qcar(v167);
    v167 = elt(env, 2); /* (ext) */
    fn = elt(env, 10); /* split_form */
    v167 = (*qfn2(fn))(qenv(fn), v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    stack[-7] = v167;
    v167 = elt(env, 3); /* ext */
    v322 = ncons(v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = stack[-7];
    v321 = qcar(v167);
    v167 = stack[-7];
    v167 = qcdr(v167);
    v167 = acons(v322, v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    stack[-7] = v167;
    v167 = stack[-9];
    v321 = qcdr(v167);
    v167 = elt(env, 2); /* (ext) */
    fn = elt(env, 10); /* split_form */
    v167 = (*qfn2(fn))(qenv(fn), v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    stack[-6] = v167;
    v167 = elt(env, 3); /* ext */
    v322 = ncons(v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = stack[-6];
    v321 = qcar(v167);
    v167 = stack[-6];
    v167 = qcdr(v167);
    v167 = acons(v322, v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    stack[-6] = v167;
    v167 = (Lisp_Object)17; /* 1 */
    stack[-5] = v167;
    v321 = stack[-10];
    v167 = elt(env, 4); /* even_dimension */
    v321 = get(v321, v167);
    env = stack[-11];
    v167 = stack[-5];
    v167 = difference2(v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = Lminusp(nil, v167);
    env = stack[-11];
    if (v167 == nil) goto v81;
    v167 = qvalue(elt(env, 5)); /* nil */
    goto v47;

v47:
    stack[-5] = v167;
    v167 = (Lisp_Object)17; /* 1 */
    stack[-4] = v167;
    v321 = stack[-10];
    v167 = elt(env, 6); /* odd_dimension */
    v321 = get(v321, v167);
    env = stack[-11];
    v167 = stack[-4];
    v167 = difference2(v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = Lminusp(nil, v167);
    env = stack[-11];
    if (v167 == nil) goto v216;
    v167 = qvalue(elt(env, 5)); /* nil */
    goto v324;

v324:
    stack[0] = v167;
    v321 = stack[-5];
    v167 = stack[-6];
    fn = elt(env, 11); /* even_action */
    stack[-1] = (*qfn2(fn))(qenv(fn), v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = stack[-9];
    v321 = qcar(v167);
    v167 = (Lisp_Object)17; /* 1 */
    v167 = cons(v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    fn = elt(env, 12); /* super_product_sq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = stack[-9];
    v321 = qcdr(v167);
    v167 = stack[-9];
    v167 = qcdr(v167);
    fn = elt(env, 13); /* multf */
    v321 = (*qfn2(fn))(qenv(fn), v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = (Lisp_Object)17; /* 1 */
    v167 = cons(v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    fn = elt(env, 14); /* invsq */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    fn = elt(env, 15); /* multsq */
    v167 = (*qfn2(fn))(qenv(fn), stack[-1], v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    stack[-1] = v167;
    v321 = stack[-5];
    v167 = stack[-7];
    fn = elt(env, 11); /* even_action */
    stack[-2] = (*qfn2(fn))(qenv(fn), v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v321 = stack[0];
    v167 = stack[-7];
    fn = elt(env, 16); /* odd_action */
    v167 = (*qfn2(fn))(qenv(fn), v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    fn = elt(env, 17); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-2], v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = stack[-9];
    v321 = qcdr(v167);
    v167 = (Lisp_Object)17; /* 1 */
    v167 = cons(v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    fn = elt(env, 14); /* invsq */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    fn = elt(env, 15); /* multsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = stack[-1];
    v167 = qcar(v167);
    fn = elt(env, 18); /* negf */
    v321 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = stack[-1];
    v167 = qcdr(v167);
    v167 = cons(v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    {
        Lisp_Object v325 = stack[0];
        popv(12);
        fn = elt(env, 17); /* addsq */
        return (*qfn2(fn))(qenv(fn), v325, v167);
    }

v216:
    v322 = stack[-10];
    v321 = (Lisp_Object)17; /* 1 */
    v167 = stack[-4];
    v167 = list3(v322, v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    fn = elt(env, 9); /* simp!* */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    stack[0] = stack[-4];
    v321 = v167;
    v167 = elt(env, 2); /* (ext) */
    fn = elt(env, 19); /* split_ext */
    v167 = (*qfn2(fn))(qenv(fn), v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = cons(stack[0], v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = ncons(v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    stack[-2] = v167;
    stack[-3] = v167;
    goto v326;

v326:
    v167 = stack[-4];
    v167 = add1(v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    stack[-4] = v167;
    v321 = stack[-10];
    v167 = elt(env, 6); /* odd_dimension */
    v321 = get(v321, v167);
    env = stack[-11];
    v167 = stack[-4];
    v167 = difference2(v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = Lminusp(nil, v167);
    env = stack[-11];
    if (v167 == nil) goto v327;
    v167 = stack[-3];
    goto v324;

v327:
    stack[-1] = stack[-2];
    v322 = stack[-10];
    v321 = (Lisp_Object)17; /* 1 */
    v167 = stack[-4];
    v167 = list3(v322, v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    fn = elt(env, 9); /* simp!* */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    stack[0] = stack[-4];
    v321 = v167;
    v167 = elt(env, 2); /* (ext) */
    fn = elt(env, 19); /* split_ext */
    v167 = (*qfn2(fn))(qenv(fn), v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = cons(stack[0], v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = ncons(v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = Lrplacd(nil, stack[-1], v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = stack[-2];
    v167 = qcdr(v167);
    stack[-2] = v167;
    goto v326;

v81:
    v322 = stack[-10];
    v321 = (Lisp_Object)1; /* 0 */
    v167 = stack[-5];
    v167 = list3(v322, v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    fn = elt(env, 9); /* simp!* */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    stack[-1] = v167;
    v321 = stack[-8];
    v167 = stack[-5];
    fn = elt(env, 20); /* pnth */
    v167 = (*qfn2(fn))(qenv(fn), v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    stack[0] = qcar(v167);
    v321 = stack[-1];
    v167 = elt(env, 2); /* (ext) */
    fn = elt(env, 19); /* split_ext */
    v167 = (*qfn2(fn))(qenv(fn), v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = cons(stack[0], v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = ncons(v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    stack[-3] = v167;
    stack[-4] = v167;
    goto v243;

v243:
    v167 = stack[-5];
    v167 = add1(v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    stack[-5] = v167;
    v321 = stack[-10];
    v167 = elt(env, 4); /* even_dimension */
    v321 = get(v321, v167);
    env = stack[-11];
    v167 = stack[-5];
    v167 = difference2(v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = Lminusp(nil, v167);
    env = stack[-11];
    if (v167 == nil) goto v32;
    v167 = stack[-4];
    goto v47;

v32:
    stack[-2] = stack[-3];
    v322 = stack[-10];
    v321 = (Lisp_Object)1; /* 0 */
    v167 = stack[-5];
    v167 = list3(v322, v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    fn = elt(env, 9); /* simp!* */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    stack[-1] = v167;
    v321 = stack[-8];
    v167 = stack[-5];
    fn = elt(env, 20); /* pnth */
    v167 = (*qfn2(fn))(qenv(fn), v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    stack[0] = qcar(v167);
    v321 = stack[-1];
    v167 = elt(env, 2); /* (ext) */
    fn = elt(env, 19); /* split_ext */
    v167 = (*qfn2(fn))(qenv(fn), v321, v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = cons(stack[0], v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = ncons(v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = Lrplacd(nil, stack[-2], v167);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-11];
    v167 = stack[-3];
    v167 = qcdr(v167);
    stack[-3] = v167;
    goto v243;
/* error exit handlers */
v323:
    popv(12);
    return nil;
}



/* Code for findremainder */

static Lisp_Object CC_findremainder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v5)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v89, v116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findremainder");
#endif
    if (stack >= stacklimit)
    {
        push2(v5,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v70 = v5;
    v89 = v0;
/* end of prologue */
    stack[0] = v70;
    goto v128;

v128:
    v70 = stack[0];
    if (v70 == nil) { popv(2); return onevalue(v89); }
    v70 = stack[0];
    v70 = qcar(v70);
    v116 = v89;
    v89 = v70;
    v70 = qcar(v70);
    v70 = qcar(v70);
    v70 = qcar(v70);
    fn = elt(env, 2); /* wupseudodivide */
    v70 = (*qfnn(fn))(qenv(fn), 3, v116, v89, v70);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-1];
    v70 = qcdr(v70);
    v89 = v70;
    v70 = stack[0];
    v70 = qcdr(v70);
    stack[0] = v70;
    goto v128;
/* error exit handlers */
v104:
    popv(2);
    return nil;
}



/* Code for checku */

static Lisp_Object CC_checku(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v5)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v100, v104, v105;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checku");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v100 = v5;
    v104 = v0;
/* end of prologue */

v138:
    v116 = v104;
    if (v116 == nil) goto v56;
    v116 = v100;
    v105 = qcar(v116);
    v116 = v104;
    v116 = qcar(v116);
    v116 = qcar(v116);
    if (equal(v105, v116)) goto v7;
    v116 = v104;
    v104 = qcdr(v116);
    v116 = v100;
    v100 = v116;
    goto v138;

v7:
    v116 = qvalue(elt(env, 2)); /* t */
    return onevalue(v116);

v56:
    v116 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v116);
}



/* Code for lx2xx */

static Lisp_Object CC_lx2xx(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lx2xx");
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
    v82 = stack[-2];
    if (!consp(v82)) goto v109;
    v82 = stack[-2];
    v82 = qcar(v82);
    v82 = (consp(v82) ? nil : lisp_true);
    goto v8;

v8:
    if (v82 == nil) goto v97;
    v82 = qvalue(elt(env, 1)); /* t */
    goto v3;

v3:
    if (!(v82 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v82 = stack[-2];
    v82 = qcdr(v82);
    v82 = qcar(v82);
    stack[-3] = v82;
    v82 = stack[-3];
    fn = elt(env, 3); /* lastnondomain */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-4];
    v82 = qcdr(v82);
    stack[-1] = v82;
    v82 = stack[-2];
    stack[0] = qcar(v82);
    v203 = stack[-1];
    v82 = stack[-3];
    fn = elt(env, 4); /* delet */
    v203 = (*qfn2(fn))(qenv(fn), v203, v82);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-4];
    v82 = elt(env, 2); /* lambda_lqlbvc_4 */
    fn = elt(env, 5); /* sort */
    v203 = (*qfn2(fn))(qenv(fn), v203, v82);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-4];
    v82 = stack[-1];
    v203 = Lappend(nil, v203, v82);
    nil = C_nil;
    if (exception_pending()) goto v48;
    v82 = stack[-2];
    v82 = qcdr(v82);
    v82 = qcdr(v82);
    {
        Lisp_Object v43 = stack[0];
        popv(5);
        return list2star(v43, v203, v82);
    }

v97:
    v82 = stack[-2];
    v82 = qcar(v82);
    if (!consp(v82)) goto v118;
    v82 = stack[-2];
    v82 = qcar(v82);
    v82 = qcar(v82);
    v82 = (consp(v82) ? nil : lisp_true);
    goto v3;

v118:
    v82 = qvalue(elt(env, 1)); /* t */
    goto v3;

v109:
    v82 = qvalue(elt(env, 1)); /* t */
    goto v8;
/* error exit handlers */
v48:
    popv(5);
    return nil;
}



/* Code for lambda_lqlbvc_4 */

static Lisp_Object CC_lambda_lqlbvc_4(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v5)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_lqlbvc_4");
#endif
    if (stack >= stacklimit)
    {
        push2(v5,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v11 = v5;
    v12 = v0;
/* end of prologue */
    v12 = qcar(v12);
    v11 = qcar(v11);
    fn = elt(env, 1); /* termorder */
    v12 = (*qfn2(fn))(qenv(fn), v12, v11);
    errexit();
    v11 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v12, v11);
}



/* Code for ev_invlexcomp */

static Lisp_Object CC_ev_invlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v5)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v43;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_invlexcomp");
#endif
    if (stack >= stacklimit)
    {
        push2(v5,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v5;
    stack[-1] = v0;
/* end of prologue */

v138:
    v48 = stack[-1];
    if (v48 == nil) goto v1;
    v48 = stack[-1];
    v43 = qcar(v48);
    v48 = stack[0];
    v48 = qcar(v48);
    v48 = Leqn(nil, v43, v48);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    if (v48 == nil) goto v116;
    v48 = stack[-1];
    v43 = qcdr(v48);
    v48 = stack[0];
    v48 = qcdr(v48);
    stack[-1] = v43;
    stack[0] = v48;
    goto v138;

v116:
    v48 = stack[-1];
    v43 = qcdr(v48);
    v48 = stack[0];
    v48 = qcdr(v48);
    v48 = CC_ev_invlexcomp(env, v43, v48);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    stack[-2] = v48;
    v43 = stack[-2];
    v48 = (Lisp_Object)1; /* 0 */
    v48 = Leqn(nil, v43, v48);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    if (v48 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v48 = stack[0];
    v43 = qcar(v48);
    v48 = stack[-1];
    v48 = qcar(v48);
    v48 = Leqn(nil, v43, v48);
    nil = C_nil;
    if (exception_pending()) goto v84;
    if (v48 == nil) goto v329;
    v48 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v48); }

v329:
    v48 = stack[0];
    v43 = qcar(v48);
    v48 = stack[-1];
    v48 = qcar(v48);
    if (((int32_t)(v43)) > ((int32_t)(v48))) goto v259;
    v48 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v48); }

v259:
    v48 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v48); }

v1:
    v48 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v48); }
/* error exit handlers */
v84:
    popv(4);
    return nil;
}



/* Code for ps!:prepfn!: */

static Lisp_Object CC_psTprepfnT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v20;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:prepfn:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v20 = v0;
/* end of prologue */
    return onevalue(v20);
}



/* Code for quoteequation */

static Lisp_Object CC_quoteequation(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v20;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quoteequation");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v20 = v0;
/* end of prologue */
    v20 = elt(env, 1); /* equation */
    return onevalue(v20);
}



/* Code for gcompatible */

static Lisp_Object CC_gcompatible(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v5)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v60, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcompatible");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v60 = v5;
    v59 = v0;
/* end of prologue */
    v97 = qvalue(elt(env, 1)); /* gmodule!* */
    if (v97 == nil) goto v56;
    v97 = v59;
    v97 = qcdr(v97);
    v59 = qcar(v97);
    v97 = v60;
    v97 = qcdr(v97);
    v60 = qcar(v97);
    v97 = qvalue(elt(env, 1)); /* gmodule!* */
    {
        fn = elt(env, 3); /* gevcompatible1 */
        return (*qfnn(fn))(qenv(fn), 3, v59, v60, v97);
    }

v56:
    v97 = qvalue(elt(env, 2)); /* t */
    return onevalue(v97);
}



/* Code for dipsimpcont */

static Lisp_Object CC_dipsimpcont(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipsimpcont");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v121 = v0;
/* end of prologue */
    v109 = qvalue(elt(env, 1)); /* !*vdpinteger */
    if (!(v109 == nil)) goto v17;
    v109 = qvalue(elt(env, 2)); /* !*groebdivide */
    if (v109 == nil) goto v17;
    v109 = v121;
    {
        fn = elt(env, 3); /* dipsimpcontr */
        return (*qfn1(fn))(qenv(fn), v109);
    }

v17:
    v109 = v121;
    {
        fn = elt(env, 4); /* dipsimpconti */
        return (*qfn1(fn))(qenv(fn), v109);
    }
}



/* Code for memqcar */

static Lisp_Object CC_memqcar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v5)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v12, v64;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for memqcar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v12 = v5;
    v64 = v0;
/* end of prologue */
    v11 = v64;
    if (!consp(v11)) goto v121;
    v11 = v64;
    v11 = qcar(v11);
    v11 = Lmemq(nil, v11, v12);
    return onevalue(v11);

v121:
    v11 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v11);
}



/* Code for random */

static Lisp_Object CC_random(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v208, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for random");
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
    v208 = stack[-3];
    if (is_number(v208)) goto v10;
    v208 = qvalue(elt(env, 1)); /* t */
    goto v3;

v3:
    if (v208 == nil) goto v2;
    v35 = stack[-3];
    v208 = elt(env, 2); /* "positive number" */
    fn = elt(env, 6); /* typerr */
    v208 = (*qfn2(fn))(qenv(fn), v35, v208);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-5];
    goto v2;

v2:
    v208 = stack[-3];
    v208 = Lfloatp(nil, v208);
    env = stack[-5];
    if (v208 == nil) goto v259;
    fn = elt(env, 7); /* next!-random!-number */
    v208 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-5];
    v35 = Lfloat(nil, v208);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-5];
    v208 = qvalue(elt(env, 3)); /* unidev_fac!* */
    v208 = times2(v35, v208);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-5];
    stack[-2] = v208;
    fn = elt(env, 7); /* next!-random!-number */
    v208 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-5];
    v35 = Lfloat(nil, v208);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-5];
    v208 = stack[-2];
    stack[0] = plus2(v35, v208);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-5];
    v35 = qvalue(elt(env, 3)); /* unidev_fac!* */
    v208 = stack[-3];
    v208 = times2(v35, v208);
    nil = C_nil;
    if (exception_pending()) goto v336;
    {
        Lisp_Object v314 = stack[0];
        popv(6);
        return times2(v314, v208);
    }

v259:
    fn = elt(env, 7); /* next!-random!-number */
    v208 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-5];
    stack[-2] = v208;
    v208 = qvalue(elt(env, 4)); /* randommodulus!* */
    stack[-4] = v208;
    goto v47;

v47:
    v35 = stack[-4];
    v208 = stack[-3];
    v208 = (Lisp_Object)lessp2(v35, v208);
    nil = C_nil;
    if (exception_pending()) goto v336;
    v208 = v208 ? lisp_true : nil;
    env = stack[-5];
    if (v208 == nil) goto v320;
    v35 = stack[-4];
    v208 = qvalue(elt(env, 4)); /* randommodulus!* */
    v208 = times2(v35, v208);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-5];
    stack[-4] = v208;
    v35 = qvalue(elt(env, 4)); /* randommodulus!* */
    v208 = stack[-2];
    stack[0] = times2(v35, v208);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-5];
    fn = elt(env, 7); /* next!-random!-number */
    v208 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-5];
    v208 = plus2(stack[0], v208);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-5];
    stack[-2] = v208;
    goto v47;

v320:
    stack[-1] = stack[-2];
    stack[0] = stack[-4];
    v35 = stack[-4];
    v208 = stack[-3];
    v208 = Cremainder(v35, v208);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-5];
    v208 = difference2(stack[0], v208);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-5];
    v208 = (Lisp_Object)lessp2(stack[-1], v208);
    nil = C_nil;
    if (exception_pending()) goto v336;
    v208 = v208 ? lisp_true : nil;
    env = stack[-5];
    if (v208 == nil) goto v259;
    v35 = stack[-2];
    v208 = stack[-3];
    popv(6);
    return Cremainder(v35, v208);

v10:
    v35 = stack[-3];
    v208 = (Lisp_Object)1; /* 0 */
    v208 = (Lisp_Object)lesseq2(v35, v208);
    nil = C_nil;
    if (exception_pending()) goto v336;
    v208 = v208 ? lisp_true : nil;
    env = stack[-5];
    goto v3;
/* error exit handlers */
v336:
    popv(6);
    return nil;
}



/* Code for assert_structstat */

static Lisp_Object MS_CDECL CC_assert_structstat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v74, v316;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_structstat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_structstat");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* end of prologue */
    fn = elt(env, 17); /* scan */
    v27 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    stack[0] = v27;
    fn = elt(env, 17); /* scan */
    v27 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    v74 = qvalue(elt(env, 1)); /* cursym!* */
    v27 = elt(env, 2); /* delim */
    v27 = Lflagp(nil, v74, v27);
    env = stack[-4];
    if (v27 == nil) goto v99;
    v27 = qvalue(elt(env, 3)); /* !*assert */
    if (v27 == nil) goto v12;
    v27 = qvalue(elt(env, 5)); /* !*msg */
    if (v27 == nil) goto v97;
    v27 = qvalue(elt(env, 5)); /* !*msg */
    if (v27 == nil) goto v97;
    stack[-1] = elt(env, 6); /* "***" */
    v316 = elt(env, 7); /* "type" */
    v74 = stack[0];
    v27 = elt(env, 8); /* "is not checked" */
    v27 = list3(v316, v74, v27);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    fn = elt(env, 18); /* lpriw */
    v27 = (*qfn2(fn))(qenv(fn), stack[-1], v27);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    goto v97;

v97:
    v27 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v27); }

v12:
    v27 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v27); }

v99:
    v74 = qvalue(elt(env, 1)); /* cursym!* */
    v27 = elt(env, 9); /* checked */
    if (v74 == v27) goto v48;
    v27 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v27 == nil)) goto v249;
    v74 = elt(env, 11); /* "expecting 'checked by' in struct but found" 
*/
    v27 = qvalue(elt(env, 1)); /* cursym!* */
    v27 = list2(v74, v27);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    fn = elt(env, 19); /* lprie */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    goto v249;

v249:
    v27 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    goto v48;

v48:
    fn = elt(env, 17); /* scan */
    v74 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    v27 = elt(env, 12); /* by */
    if (v74 == v27) goto v131;
    v27 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v27 == nil)) goto v204;
    v74 = elt(env, 13); /* "expecting 'by' in struct but found" */
    v27 = qvalue(elt(env, 1)); /* cursym!* */
    v27 = list2(v74, v27);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    fn = elt(env, 19); /* lprie */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    goto v204;

v204:
    v27 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    goto v131;

v131:
    fn = elt(env, 17); /* scan */
    v27 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    stack[-3] = v27;
    fn = elt(env, 17); /* scan */
    v74 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    v27 = elt(env, 2); /* delim */
    v27 = Lflagp(nil, v74, v27);
    env = stack[-4];
    if (!(v27 == nil)) goto v252;
    v27 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v27 == nil)) goto v95;
    v74 = elt(env, 14); /* "expecting end of struct but found" */
    v27 = qvalue(elt(env, 1)); /* cursym!* */
    v27 = list2(v74, v27);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    fn = elt(env, 19); /* lprie */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    goto v95;

v95:
    v27 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    goto v252;

v252:
    v27 = qvalue(elt(env, 3)); /* !*assert */
    if (v27 == nil) goto v205;
    stack[-2] = elt(env, 15); /* put */
    v27 = stack[0];
    stack[-1] = Lmkquote(nil, v27);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    stack[0] = elt(env, 16); /* (quote assert_checkfn) */
    v27 = stack[-3];
    v27 = Lmkquote(nil, v27);
    nil = C_nil;
    if (exception_pending()) goto v32;
    {
        Lisp_Object v28 = stack[-2];
        Lisp_Object v339 = stack[-1];
        Lisp_Object v340 = stack[0];
        popv(5);
        return list4(v28, v339, v340, v27);
    }

v205:
    v27 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v27); }
/* error exit handlers */
v32:
    popv(5);
    return nil;
}



/* Code for changearg */

static Lisp_Object MS_CDECL CC_changearg(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v5,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v249, v51, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "changearg");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for changearg");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v5,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v5,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v5;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v2;

v2:
    v249 = stack[0];
    if (!consp(v249)) goto v94;
    v249 = stack[0];
    v51 = qcar(v249);
    v249 = stack[-2];
    v249 = Lmemq(nil, v51, v249);
    if (v249 == nil) goto v90;
    stack[-2] = stack[-3];
    v249 = stack[0];
    v51 = qcar(v249);
    v249 = stack[-1];
    v249 = cons(v51, v249);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-4];
    {
        Lisp_Object v328 = stack[-2];
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v328, v249);
    }

v90:
    v49 = stack[-2];
    v51 = stack[-1];
    v249 = stack[0];
    v249 = qcar(v249);
    v51 = CC_changearg(env, 3, v49, v51, v249);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-4];
    v249 = stack[-3];
    v249 = cons(v51, v249);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-4];
    stack[-3] = v249;
    v249 = stack[0];
    v249 = qcdr(v249);
    stack[0] = v249;
    goto v2;

v94:
    v51 = stack[-3];
    v249 = stack[0];
    {
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v51, v249);
    }
/* error exit handlers */
v329:
    popv(5);
    return nil;
}



/* Code for fs!:null!-angle */

static Lisp_Object CC_fsTnullKangle(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v119;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:null-angle");
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
    v119 = v55;
    v55 = (Lisp_Object)33; /* 2 */
    v55 = *(Lisp_Object *)((char *)v119 + (CELL-TAG_VECTOR) + ((int32_t)v55/(16/CELL)));
    stack[0] = v55;
    v55 = qvalue(elt(env, 1)); /* t */
    stack[-2] = v55;
    v55 = (Lisp_Object)1; /* 0 */
    stack[-1] = v55;
    goto v60;

v60:
    v119 = stack[0];
    v55 = stack[-1];
    v119 = *(Lisp_Object *)((char *)v119 + (CELL-TAG_VECTOR) + ((int32_t)v55/(16/CELL)));
    v55 = (Lisp_Object)1; /* 0 */
    if (v119 == v55) goto v10;
    v55 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v55); }

v10:
    v55 = stack[-1];
    v55 = add1(v55);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    stack[-1] = v55;
    v119 = stack[-1];
    v55 = (Lisp_Object)129; /* 8 */
    v55 = (Lisp_Object)lessp2(v119, v55);
    nil = C_nil;
    if (exception_pending()) goto v90;
    v55 = v55 ? lisp_true : nil;
    env = stack[-3];
    if (v55 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    else goto v60;
/* error exit handlers */
v90:
    popv(4);
    return nil;
}



/* Code for exptpri */

static Lisp_Object CC_exptpri(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v5)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v168, v167, v321;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptpri");
#endif
    if (stack >= stacklimit)
    {
        push2(v5,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v167 = v5;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* !*list */
    qvalue(elt(env, 1)) = nil; /* !*list */
    stack[0] = nil;
    v168 = qvalue(elt(env, 2)); /* !*nat */
    if (v168 == nil) goto v121;
    v168 = qvalue(elt(env, 4)); /* !*fort */
    goto v109;

v109:
    if (v168 == nil) goto v107;
    v168 = elt(env, 5); /* failed */
    goto v126;

v126:
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    { popv(8); return onevalue(v168); }

v107:
    v321 = elt(env, 6); /* expt */
    v168 = elt(env, 7); /* infix */
    v168 = get(v321, v168);
    env = stack[-7];
    stack[-2] = v168;
    v168 = (Lisp_Object)greaterp2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v366;
    v168 = v168 ? lisp_true : nil;
    env = stack[-7];
    v168 = (v168 == nil ? lisp_true : nil);
    stack[-4] = v168;
    v168 = stack[-5];
    v168 = qcdr(v168);
    v168 = qcar(v168);
    stack[-1] = v168;
    v168 = stack[-5];
    v168 = qcdr(v168);
    v168 = qcdr(v168);
    v168 = qcar(v168);
    stack[-3] = v168;
    v168 = qvalue(elt(env, 8)); /* !*eraise */
    if (v168 == nil) goto v71;
    v168 = stack[-1];
    if (!consp(v168)) goto v244;
    v168 = stack[-1];
    v167 = qcar(v168);
    v168 = elt(env, 9); /* prifn */
    v168 = get(v167, v168);
    env = stack[-7];
    stack[0] = v168;
    if (v168 == nil) goto v52;
    v167 = stack[0];
    v168 = elt(env, 6); /* expt */
    v167 = get(v167, v168);
    env = stack[-7];
    v168 = elt(env, 11); /* inbrackets */
    v168 = (v167 == v168 ? lisp_true : nil);
    goto v76;

v76:
    if (v168 == nil) goto v71;
    v321 = stack[-1];
    v167 = (Lisp_Object)1; /* 0 */
    v168 = elt(env, 11); /* inbrackets */
    fn = elt(env, 21); /* layout!-formula */
    v168 = (*qfnn(fn))(qenv(fn), 3, v321, v167, v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    stack[-1] = v168;
    goto v242;

v242:
    v168 = stack[-1];
    if (v168 == nil) goto v208;
    stack[-5] = qvalue(elt(env, 13)); /* !*ratpri */
    qvalue(elt(env, 13)) = nil; /* !*ratpri */
    v167 = stack[-3];
    v168 = elt(env, 14); /* quotient */
    if (!consp(v167)) goto v66;
    v167 = qcar(v167);
    if (!(v167 == v168)) goto v66;
    v168 = stack[-3];
    v168 = qcdr(v168);
    v167 = qcar(v168);
    v168 = elt(env, 15); /* minus */
    v168 = Leqcar(nil, v167, v168);
    env = stack[-7];
    goto v27;

v27:
    if (v168 == nil) goto v19;
    stack[0] = elt(env, 15); /* minus */
    v168 = stack[-3];
    v321 = qcar(v168);
    v168 = stack[-3];
    v168 = qcdr(v168);
    v168 = qcar(v168);
    v168 = qcdr(v168);
    v167 = qcar(v168);
    v168 = stack[-3];
    v168 = qcdr(v168);
    v168 = qcdr(v168);
    v168 = qcar(v168);
    v168 = list3(v321, v167, v168);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-7];
    v168 = list2(stack[0], v168);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-7];
    stack[-3] = v168;
    goto v216;

v216:
    v321 = stack[-3];
    v168 = qvalue(elt(env, 8)); /* !*eraise */
    if (v168 == nil) goto v368;
    v168 = (Lisp_Object)1; /* 0 */
    v167 = v168;
    goto v214;

v214:
    v168 = qvalue(elt(env, 10)); /* nil */
    fn = elt(env, 21); /* layout!-formula */
    v168 = (*qfnn(fn))(qenv(fn), 3, v321, v167, v168);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-7];
    stack[-3] = v168;
    qvalue(elt(env, 13)) = stack[-5]; /* !*ratpri */
    v168 = stack[-3];
    if (v168 == nil) goto v369;
    v168 = stack[-1];
    v168 = qcar(v168);
    v167 = qcdr(v168);
    v168 = stack[-3];
    v168 = qcar(v168);
    v168 = qcdr(v168);
    v168 = plus2(v167, v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    stack[-5] = v168;
    v168 = stack[-4];
    if (v168 == nil) goto v370;
    v167 = stack[-5];
    v168 = (Lisp_Object)33; /* 2 */
    v168 = plus2(v167, v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    stack[-5] = v168;
    goto v370;

v370:
    stack[0] = stack[-5];
    v168 = qvalue(elt(env, 10)); /* nil */
    v167 = Llinelength(nil, v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    v168 = qvalue(elt(env, 16)); /* spare!* */
    v167 = difference2(v167, v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    v168 = qvalue(elt(env, 17)); /* orig!* */
    v168 = difference2(v167, v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    v168 = (Lisp_Object)greaterp2(stack[0], v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    v168 = v168 ? lisp_true : nil;
    env = stack[-7];
    if (v168 == nil) goto v371;
    v168 = elt(env, 5); /* failed */
    goto v126;

v371:
    stack[0] = stack[-5];
    v168 = qvalue(elt(env, 10)); /* nil */
    v167 = Llinelength(nil, v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    v168 = qvalue(elt(env, 16)); /* spare!* */
    v167 = difference2(v167, v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    v168 = qvalue(elt(env, 18)); /* posn!* */
    v168 = difference2(v167, v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    v168 = (Lisp_Object)greaterp2(stack[0], v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    v168 = v168 ? lisp_true : nil;
    env = stack[-7];
    if (v168 == nil) goto v220;
    v168 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 22); /* terpri!* */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    goto v220;

v220:
    v168 = stack[-4];
    if (v168 == nil) goto v280;
    v168 = elt(env, 19); /* "(" */
    fn = elt(env, 23); /* prin2!* */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    goto v280;

v280:
    v168 = stack[-1];
    fn = elt(env, 24); /* putpline */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    v168 = qvalue(elt(env, 8)); /* !*eraise */
    if (v168 == nil) goto v277;
    v167 = (Lisp_Object)17; /* 1 */
    v168 = stack[-3];
    v168 = qcdr(v168);
    v168 = qcar(v168);
    v168 = difference2(v167, v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    stack[-5] = v168;
    goto v225;

v225:
    v321 = (Lisp_Object)1; /* 0 */
    v167 = stack[-5];
    v168 = stack[-3];
    v168 = qcar(v168);
    v168 = qcar(v168);
    fn = elt(env, 25); /* update!-pline */
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v321, v167, v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    v168 = stack[-3];
    v168 = qcar(v168);
    stack[-1] = qcdr(v168);
    v168 = stack[-3];
    v168 = qcdr(v168);
    v167 = qcar(v168);
    v168 = stack[-5];
    stack[0] = plus2(v167, v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    v168 = stack[-3];
    v168 = qcdr(v168);
    v167 = qcdr(v168);
    v168 = stack[-5];
    v168 = plus2(v167, v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    v168 = cons(stack[0], v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    v168 = acons(stack[-2], stack[-1], v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    fn = elt(env, 24); /* putpline */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    v168 = stack[-4];
    if (v168 == nil) goto v372;
    v168 = elt(env, 20); /* ")" */
    fn = elt(env, 23); /* prin2!* */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    goto v372;

v372:
    v168 = nil;
    goto v126;

v277:
    v168 = elt(env, 6); /* expt */
    fn = elt(env, 26); /* oprin */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    v168 = (Lisp_Object)1; /* 0 */
    stack[-5] = v168;
    goto v225;

v369:
    v168 = elt(env, 5); /* failed */
    goto v126;

v368:
    v168 = stack[-2];
    v167 = v168;
    goto v214;

v19:
    v167 = stack[-3];
    v168 = elt(env, 15); /* minus */
    if (!consp(v167)) goto v63;
    v167 = qcar(v167);
    if (!(v167 == v168)) goto v63;
    v168 = stack[-3];
    v168 = qcdr(v168);
    v168 = qcar(v168);
    v168 = (is_number(v168) ? lisp_true : nil);
    goto v326;

v326:
    if (v168 == nil) goto v78;
    v168 = stack[-3];
    v168 = qcdr(v168);
    v168 = qcar(v168);
    v168 = negate(v168);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-7];
    goto v294;

v294:
    stack[-3] = v168;
    goto v216;

v78:
    v168 = stack[-3];
    goto v294;

v63:
    v168 = qvalue(elt(env, 10)); /* nil */
    goto v326;

v66:
    v168 = qvalue(elt(env, 10)); /* nil */
    goto v27;

v208:
    v168 = elt(env, 5); /* failed */
    goto v126;

v71:
    v167 = stack[0];
    v168 = elt(env, 12); /* indexprin */
    if (v167 == v168) goto v320;
    v168 = qvalue(elt(env, 10)); /* nil */
    goto v41;

v41:
    if (v168 == nil) goto v254;
    v168 = qvalue(elt(env, 10)); /* nil */
    goto v126;

v254:
    v321 = stack[-1];
    v167 = stack[-2];
    v168 = qvalue(elt(env, 10)); /* nil */
    fn = elt(env, 21); /* layout!-formula */
    v168 = (*qfnn(fn))(qenv(fn), 3, v321, v167, v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    stack[-1] = v168;
    goto v242;

v320:
    v167 = stack[-1];
    v168 = stack[-3];
    fn = elt(env, 27); /* indexpower */
    v167 = (*qfn2(fn))(qenv(fn), v167, v168);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-7];
    v168 = elt(env, 5); /* failed */
    v168 = (v167 == v168 ? lisp_true : nil);
    v168 = (v168 == nil ? lisp_true : nil);
    goto v41;

v52:
    v168 = qvalue(elt(env, 10)); /* nil */
    goto v76;

v244:
    v168 = qvalue(elt(env, 10)); /* nil */
    goto v76;

v121:
    v168 = qvalue(elt(env, 3)); /* t */
    goto v109;
/* error exit handlers */
v367:
    env = stack[-7];
    qvalue(elt(env, 13)) = stack[-5]; /* !*ratpri */
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    popv(8);
    return nil;
v366:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    popv(8);
    return nil;
}



/* Code for pa_coinc_split */

static Lisp_Object CC_pa_coinc_split(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v5)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v390, v353, v351;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pa_coinc_split");
#endif
    if (stack >= stacklimit)
    {
        push2(v5,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v5;
    stack[-9] = v0;
/* end of prologue */
    stack[-6] = nil;
    v390 = stack[-9];
    v390 = qcdr(v390);
    fn = elt(env, 3); /* upbve */
    v390 = (*qfn1(fn))(qenv(fn), v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    stack[-4] = v390;
    v390 = stack[-4];
    v390 = sub1(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v390 = Lmkvect(nil, v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    stack[-10] = v390;
    v390 = stack[-4];
    v390 = sub1(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v390 = Lmkvect(nil, v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    stack[-7] = v390;
    v390 = stack[-4];
    v390 = sub1(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v390 = Lmkvect(nil, v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    stack[-5] = v390;
    v390 = (Lisp_Object)1; /* 0 */
    stack[-3] = v390;
    v390 = stack[-9];
    v390 = qcar(v390);
    stack[-2] = v390;
    goto v107;

v107:
    v390 = stack[-2];
    if (v390 == nil) goto v106;
    v390 = stack[-2];
    v390 = qcar(v390);
    stack[-1] = v390;
    v390 = stack[-3];
    v390 = add1(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    stack[-3] = v390;
    stack[0] = stack[-10];
    v390 = stack[-1];
    v353 = sub1(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v390 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v353/(16/CELL))) = v390;
    v390 = stack[-2];
    v390 = qcdr(v390);
    stack[-2] = v390;
    goto v107;

v106:
    v390 = (Lisp_Object)1; /* 0 */
    stack[-3] = v390;
    v390 = stack[-8];
    v390 = qcar(v390);
    stack[-2] = v390;
    goto v53;

v53:
    v390 = stack[-2];
    if (v390 == nil) goto v52;
    v390 = stack[-2];
    v390 = qcar(v390);
    stack[-1] = v390;
    v390 = stack[-3];
    v390 = add1(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    stack[-3] = v390;
    stack[0] = stack[-7];
    v390 = stack[-1];
    v353 = sub1(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v390 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v353/(16/CELL))) = v390;
    v390 = stack[-2];
    v390 = qcdr(v390);
    stack[-2] = v390;
    goto v53;

v52:
    v390 = (Lisp_Object)17; /* 1 */
    stack[-3] = v390;
    goto v247;

v247:
    v353 = stack[-4];
    v390 = stack[-3];
    v390 = difference2(v353, v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v390 = Lminusp(nil, v390);
    env = stack[-11];
    if (v390 == nil) goto v252;
    v353 = stack[-6];
    v390 = elt(env, 2); /* lambda_lqlbvc_5 */
    fn = elt(env, 4); /* sort */
    v390 = (*qfn2(fn))(qenv(fn), v353, v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    stack[-6] = v390;
    v390 = stack[-6];
    stack[-3] = v390;
    v390 = stack[-3];
    if (v390 == nil) goto v391;
    v390 = stack[-3];
    v390 = qcar(v390);
    v390 = qcdr(v390);
    v390 = qcar(v390);
    v390 = ncons(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    stack[-1] = v390;
    stack[-2] = v390;
    goto v303;

v303:
    v390 = stack[-3];
    v390 = qcdr(v390);
    stack[-3] = v390;
    v390 = stack[-3];
    if (v390 == nil) goto v215;
    stack[0] = stack[-1];
    v390 = stack[-3];
    v390 = qcar(v390);
    v390 = qcdr(v390);
    v390 = qcar(v390);
    v390 = ncons(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v390 = Lrplacd(nil, stack[0], v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v390 = stack[-1];
    v390 = qcdr(v390);
    stack[-1] = v390;
    goto v303;

v215:
    v390 = stack[-2];
    v353 = v390;
    goto v15;

v15:
    v390 = stack[-5];
    v390 = cons(v353, v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    stack[-5] = v390;
    v390 = stack[-6];
    stack[-3] = v390;
    v390 = stack[-3];
    if (v390 == nil) goto v392;
    v390 = stack[-3];
    v390 = qcar(v390);
    v353 = v390;
    v353 = qcar(v353);
    v390 = qcdr(v390);
    v390 = qcdr(v390);
    v390 = cons(v353, v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v390 = ncons(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    stack[-1] = v390;
    stack[-2] = v390;
    goto v217;

v217:
    v390 = stack[-3];
    v390 = qcdr(v390);
    stack[-3] = v390;
    v390 = stack[-3];
    if (v390 == nil) goto v393;
    stack[0] = stack[-1];
    v390 = stack[-3];
    v390 = qcar(v390);
    v353 = v390;
    v353 = qcar(v353);
    v390 = qcdr(v390);
    v390 = qcdr(v390);
    v390 = cons(v353, v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v390 = ncons(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v390 = Lrplacd(nil, stack[0], v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v390 = stack[-1];
    v390 = qcdr(v390);
    stack[-1] = v390;
    goto v217;

v393:
    v390 = stack[-2];
    goto v350;

v350:
    v353 = v390;
    v390 = stack[-5];
    popv(12);
    return cons(v353, v390);

v392:
    v390 = qvalue(elt(env, 1)); /* nil */
    goto v350;

v391:
    v390 = qvalue(elt(env, 1)); /* nil */
    v353 = v390;
    goto v15;

v252:
    stack[-1] = stack[-10];
    v390 = stack[-9];
    stack[0] = qcdr(v390);
    v390 = stack[-3];
    v390 = sub1(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v390 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v390/(16/CELL)));
    v390 = sub1(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    stack[-2] = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v390/(16/CELL)));
    stack[-1] = stack[-7];
    v390 = stack[-8];
    stack[0] = qcdr(v390);
    v390 = stack[-3];
    v390 = sub1(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v390 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v390/(16/CELL)));
    v390 = sub1(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v390 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v390/(16/CELL)));
    v390 = cons(stack[-2], v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v351 = v390;
    v353 = v351;
    v390 = stack[-6];
    v390 = Lassoc(nil, v353, v390);
    stack[-1] = v390;
    if (v390 == nil) goto v394;
    v390 = stack[-1];
    stack[0] = qcdr(v390);
    v390 = stack[-1];
    v390 = qcdr(v390);
    v390 = qcdr(v390);
    v390 = add1(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v390 = Lrplacd(nil, stack[0], v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    stack[0] = stack[-5];
    v390 = stack[-3];
    v353 = sub1(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v390 = stack[-1];
    v390 = qcdr(v390);
    v390 = qcar(v390);
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v353/(16/CELL))) = v390;
    goto v193;

v193:
    v390 = stack[-3];
    v390 = add1(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    stack[-3] = v390;
    goto v247;

v394:
    v353 = stack[-3];
    v390 = (Lisp_Object)17; /* 1 */
    v390 = list2star(v351, v353, v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    stack[-1] = v390;
    v353 = stack[-1];
    v390 = stack[-6];
    v390 = cons(v353, v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    stack[-6] = v390;
    stack[0] = stack[-5];
    v390 = stack[-3];
    v353 = sub1(v390);
    nil = C_nil;
    if (exception_pending()) goto v282;
    env = stack[-11];
    v390 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v353/(16/CELL))) = v390;
    goto v193;
/* error exit handlers */
v282:
    popv(12);
    return nil;
}



/* Code for lambda_lqlbvc_5 */

static Lisp_Object CC_lambda_lqlbvc_5(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v5)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v242, v132;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_lqlbvc_5");
#endif
    if (stack >= stacklimit)
    {
        push2(v5,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v5;
    stack[-1] = v0;
/* end of prologue */
    v242 = stack[-1];
    v242 = qcar(v242);
    v132 = qcar(v242);
    v242 = stack[0];
    v242 = qcar(v242);
    v242 = qcar(v242);
    v242 = (Lisp_Object)lessp2(v132, v242);
    nil = C_nil;
    if (exception_pending()) goto v119;
    v242 = v242 ? lisp_true : nil;
    env = stack[-2];
    if (v242 == nil) goto v93;
    v242 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v242); }

v93:
    v242 = stack[0];
    v242 = qcar(v242);
    v132 = qcar(v242);
    v242 = stack[-1];
    v242 = qcar(v242);
    v242 = qcar(v242);
    v242 = (Lisp_Object)lessp2(v132, v242);
    nil = C_nil;
    if (exception_pending()) goto v119;
    v242 = v242 ? lisp_true : nil;
    env = stack[-2];
    if (v242 == nil) goto v100;
    v242 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v242); }

v100:
    v242 = stack[-1];
    v242 = qcar(v242);
    v132 = qcdr(v242);
    v242 = stack[0];
    v242 = qcar(v242);
    v242 = qcdr(v242);
        popv(3);
        return Lleq(nil, v132, v242);
/* error exit handlers */
v119:
    popv(3);
    return nil;
}



setup_type const u21_setup[] =
{
    {"unresidp",                CC_unresidp,    too_many_1,    wrong_no_1},
    {"replace1_parents",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_replace1_parents},
    {"fieldconv",               too_few_2,      CC_fieldconv,  wrong_no_2},
    {"kernord-split",           too_few_2,      CC_kernordKsplit,wrong_no_2},
    {"gcref_remprops",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_gcref_remprops},
    {"rl_qefsolset",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_qefsolset},
    {"rl_identifyonoff",        CC_rl_identifyonoff,too_many_1,wrong_no_1},
    {"get-denom-l",             CC_getKdenomKl, too_many_1,    wrong_no_1},
    {"exptf1",                  too_few_2,      CC_exptf1,     wrong_no_2},
    {"sfto_sqfpartf",           CC_sfto_sqfpartf,too_many_1,   wrong_no_1},
    {"unaryir",                 too_few_2,      CC_unaryir,    wrong_no_2},
    {"ft:zerop",                CC_ftTzerop,    too_many_1,    wrong_no_1},
    {"vevdif",                  too_few_2,      CC_vevdif,     wrong_no_2},
    {"nconc2",                  too_few_2,      CC_nconc2,     wrong_no_2},
    {"getphystypeor",           CC_getphystypeor,too_many_1,   wrong_no_1},
    {"nfactorial",              CC_nfactorial,  too_many_1,    wrong_no_1},
    {"begin11",                 CC_begin11,     too_many_1,    wrong_no_1},
    {"bas_newnumber",           too_few_2,      CC_bas_newnumber,wrong_no_2},
    {"gcdout",                  CC_gcdout,      too_many_1,    wrong_no_1},
    {"dv_ind2var",              CC_dv_ind2var,  too_many_1,    wrong_no_1},
    {"ilog2",                   CC_ilog2,       too_many_1,    wrong_no_1},
    {"outrdefun",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_outrdefun},
    {"rl_transform",            too_few_2,      CC_rl_transform,wrong_no_2},
    {"super_der_simp",          CC_super_der_simp,too_many_1,  wrong_no_1},
    {"findremainder",           too_few_2,      CC_findremainder,wrong_no_2},
    {"checku",                  too_few_2,      CC_checku,     wrong_no_2},
    {"lx2xx",                   CC_lx2xx,       too_many_1,    wrong_no_1},
    {"lambda_lqlbvc_4",         too_few_2,      CC_lambda_lqlbvc_4,wrong_no_2},
    {"ev_invlexcomp",           too_few_2,      CC_ev_invlexcomp,wrong_no_2},
    {"ps:prepfn:",              CC_psTprepfnT,  too_many_1,    wrong_no_1},
    {"quoteequation",           CC_quoteequation,too_many_1,   wrong_no_1},
    {"gcompatible",             too_few_2,      CC_gcompatible,wrong_no_2},
    {"dipsimpcont",             CC_dipsimpcont, too_many_1,    wrong_no_1},
    {"memqcar",                 too_few_2,      CC_memqcar,    wrong_no_2},
    {"random",                  CC_random,      too_many_1,    wrong_no_1},
    {"assert_structstat",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_structstat},
    {"changearg",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_changearg},
    {"fs:null-angle",           CC_fsTnullKangle,too_many_1,   wrong_no_1},
    {"exptpri",                 too_few_2,      CC_exptpri,    wrong_no_2},
    {"pa_coinc_split",          too_few_2,      CC_pa_coinc_split,wrong_no_2},
    {"lambda_lqlbvc_5",         too_few_2,      CC_lambda_lqlbvc_5,wrong_no_2},
    {NULL, (one_args *)"u21", (two_args *)"792 735147 4192730", 0}
};

/* end of generated code */
