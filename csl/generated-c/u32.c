
/* $destdir\u32.c        Machine generated C code */

/* Signature: 00000000 07-Oct-2010 */

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
#if !defined UNDER_CE && ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS                  1
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
#define UNWIND_ERROR      0x100       
#define UNWIND_UNWIND     0x200       
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
#define HEADLINE_FLAG 0x08
#define MESSAGES_FLAG 0x10
#define ALWAYS_NOISY  0x20
#define verbos_flag (miscflags & GC_MSG_BITS)
 
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
#ifdef CHECK_STACK
extern int check_stack(char *file, int line);
#define if_check_stack \
   if (check_stack(__FILE__,__LINE__)) return aerror("stack overflow");
#else
#define if_check_stack
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
extern CSLbool always_noisy;
extern int number_of_input_files,
    number_of_symbols_to_define,
    number_of_fasl_paths,
    init_flags;
extern int native_code_tag;
extern char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
extern int force_reclaim_method;
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
#define validate_string(a) 0
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


/* Code for afactor */

static Lisp_Object CC_afactor(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for afactor");
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
    stack[-4] = qvalue(elt(env, 1)); /* afactorvar */
    qvalue(elt(env, 1)) = nil; /* afactorvar */
    stack[-1] = qvalue(elt(env, 2)); /* !*noextend */
    qvalue(elt(env, 2)) = nil; /* !*noextend */
    stack[0] = qvalue(elt(env, 3)); /* !*sqfree */
    qvalue(elt(env, 3)) = nil; /* !*sqfree */
    v8 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 2)) = v8; /* !*noextend */
    v8 = stack[-2];
    qvalue(elt(env, 1)) = v8; /* afactorvar */
    v8 = qvalue(elt(env, 5)); /* !*trfield */
    if (v8 == nil) goto v9;
    v8 = elt(env, 6); /* "We must factorise the following over: " */
    v8 = Lprinc(nil, v8);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    v8 = qvalue(elt(env, 7)); /* listofnewsqrts */
    stack[-2] = v8;
    goto v11;

v11:
    v8 = stack[-2];
    if (v8 == nil) goto v12;
    v8 = stack[-2];
    v8 = qcar(v8);
    v8 = Lprinc(nil, v8);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    v8 = elt(env, 9); /* " " */
    v8 = Lprinc(nil, v8);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    v8 = stack[-2];
    v8 = qcdr(v8);
    stack[-2] = v8;
    goto v11;

v12:
    v8 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    v8 = stack[-3];
    if (v8 == nil) goto v13;
    v8 = stack[-3];
    fn = elt(env, 11); /* xprinf2 */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    goto v14;

v14:
    v8 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 12); /* terpri!* */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    goto v9;

v9:
    v8 = stack[-3];
    fn = elt(env, 13); /* algfactor */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    stack[-2] = v8;
    v8 = qvalue(elt(env, 5)); /* !*trfield */
    if (v8 == nil) goto v15;
    v8 = elt(env, 10); /* "factorizes as " */
    v8 = Lprintc(nil, v8);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    v8 = stack[-2];
    stack[-3] = v8;
    goto v16;

v16:
    v8 = stack[-3];
    if (v8 == nil) goto v15;
    v8 = stack[-3];
    v8 = qcar(v8);
    fn = elt(env, 14); /* printsf */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    v8 = stack[-3];
    v8 = qcdr(v8);
    stack[-3] = v8;
    goto v16;

v15:
    v8 = stack[-2];
    qvalue(elt(env, 3)) = stack[0]; /* !*sqfree */
    qvalue(elt(env, 2)) = stack[-1]; /* !*noextend */
    qvalue(elt(env, 1)) = stack[-4]; /* afactorvar */
    { popv(6); return onevalue(v8); }

v13:
    v8 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 15); /* prin2!* */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    goto v14;
/* error exit handlers */
v10:
    env = stack[-5];
    qvalue(elt(env, 3)) = stack[0]; /* !*sqfree */
    qvalue(elt(env, 2)) = stack[-1]; /* !*noextend */
    qvalue(elt(env, 1)) = stack[-4]; /* afactorvar */
    popv(6);
    return nil;
}



/* Code for cl_bnfsimpl */

static Lisp_Object CC_cl_bnfsimpl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v11, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_bnfsimpl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v11 = v1;
    v19 = v0;
/* end of prologue */
    v12 = qvalue(elt(env, 1)); /* !*rlbnfsac */
    if (v12 == nil) return onevalue(v19);
    v12 = v19;
    {
        fn = elt(env, 2); /* cl_sac */
        return (*qfn2(fn))(qenv(fn), v12, v11);
    }
}



/* Code for aex_neg */

static Lisp_Object CC_aex_neg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_neg");
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
    v19 = stack[-2];
    fn = elt(env, 1); /* aex_ex */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    fn = elt(env, 2); /* ratpoly_neg */
    stack[-3] = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    v19 = stack[-2];
    fn = elt(env, 3); /* aex_ctx */
    stack[-1] = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    v19 = stack[-2];
    fn = elt(env, 4); /* aex_lcnttag */
    stack[0] = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    v19 = stack[-2];
    fn = elt(env, 5); /* aex_reducedtag */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    {
        Lisp_Object v22 = stack[-3];
        Lisp_Object v23 = stack[-1];
        Lisp_Object v24 = stack[0];
        popv(5);
        fn = elt(env, 6); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v22, v23, v24, v19);
    }
/* error exit handlers */
v21:
    popv(5);
    return nil;
}



/* Code for listrd */

static Lisp_Object MS_CDECL CC_listrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v40, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "listrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listrd");
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
    v40 = qvalue(elt(env, 1)); /* atts */
    v39 = elt(env, 2); /* (o r d e r) */
    fn = elt(env, 11); /* search_att */
    v39 = (*qfn2(fn))(qenv(fn), v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    stack[-1] = v39;
    v39 = elt(env, 3); /* (t y p e != l i s t !$) */
    qvalue(elt(env, 1)) = v39; /* atts */
    stack[0] = elt(env, 4); /* list */
    fn = elt(env, 12); /* stats_getargs */
    v39 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    v39 = cons(stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    v40 = v39;
    stack[0] = v40;
    v41 = stack[-1];
    v40 = elt(env, 5); /* (l e x i c o g r a p h i c) */
    if (!(equal(v41, v40))) goto v43;
    v40 = elt(env, 6); /* sortlist */
    v41 = v39;
    v39 = elt(env, 7); /* lexog */
    v39 = list3(v40, v41, v39);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    fn = elt(env, 13); /* aeval */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    goto v43;

v43:
    v41 = stack[-1];
    v40 = elt(env, 8); /* (n u m e r i c) */
    if (equal(v41, v40)) goto v44;
    v41 = elt(env, 6); /* sortlist */
    v40 = v39;
    v39 = elt(env, 10); /* pred */
    v39 = list3(v41, v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    fn = elt(env, 13); /* aeval */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v42;
    goto v45;

v45:
    v40 = v39;
    if (!(v40 == nil)) { popv(3); return onevalue(v39); }
    v39 = stack[0];
    { popv(3); return onevalue(v39); }

v44:
    v41 = elt(env, 6); /* sortlist */
    v40 = v39;
    v39 = elt(env, 9); /* numer */
    v39 = list3(v41, v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    fn = elt(env, 13); /* aeval */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v42;
    goto v45;
/* error exit handlers */
v42:
    popv(3);
    return nil;
}



/* Code for plusrd */

static Lisp_Object MS_CDECL CC_plusrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "plusrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for plusrd");
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
    fn = elt(env, 2); /* mathml */
    v37 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    v46 = v37;
    v37 = v46;
    if (v37 == nil) goto v48;
    stack[0] = v46;
    v37 = CC_plusrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    {
        Lisp_Object v21 = stack[0];
        popv(2);
        fn = elt(env, 3); /* alg_plus */
        return (*qfn2(fn))(qenv(fn), v21, v37);
    }

v48:
    v37 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v37); }
/* error exit handlers */
v47:
    popv(2);
    return nil;
}



/* Code for bfminus */

static Lisp_Object CC_bfminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfminus");
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
    v22 = stack[0];
    if (!consp(v22)) goto v2;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v22 = stack[0];
    v22 = qcdr(v22);
    v22 = qcar(v22);
    v23 = negate(v22);
    nil = C_nil;
    if (exception_pending()) goto v49;
    v22 = stack[0];
    v22 = qcdr(v22);
    v22 = qcdr(v22);
    {
        Lisp_Object v50 = stack[-1];
        popv(2);
        return list2star(v50, v23, v22);
    }

v2:
    v22 = stack[0];
    popv(2);
    return negate(v22);
/* error exit handlers */
v49:
    popv(2);
    return nil;
}



/* Code for findoptrow */

static Lisp_Object MS_CDECL CC_findoptrow(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v31, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v83, v84, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "findoptrow");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findoptrow");
#endif
    if (stack >= stacklimit)
    {
        push3(v31,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v31;
    stack[0] = v1;
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = nil;
    stack[-2] = stack[0];
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v83 = qvalue(elt(env, 2)); /* maxvar */
    v82 = stack[-6];
    v82 = plus2(v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-8];
    v83 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v82/(16/CELL)));
    v82 = (Lisp_Object)65; /* 4 */
    v82 = *(Lisp_Object *)((char *)v83 + (CELL-TAG_VECTOR) + ((int32_t)v82/(16/CELL)));
    fn = elt(env, 8); /* pnthxzz */
    v82 = (*qfn2(fn))(qenv(fn), stack[-2], v82);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-8];
    v82 = qcar(v82);
    v82 = qcdr(v82);
    v82 = qcar(v82);
    stack[-3] = v82;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v83 = qvalue(elt(env, 2)); /* maxvar */
    v82 = stack[0];
    v82 = plus2(v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-8];
    v83 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v82/(16/CELL)));
    v82 = (Lisp_Object)65; /* 4 */
    v82 = *(Lisp_Object *)((char *)v83 + (CELL-TAG_VECTOR) + ((int32_t)v82/(16/CELL)));
    stack[-2] = v82;
    goto v33;

v33:
    v82 = stack[-2];
    if (v82 == nil) { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }
    v82 = stack[-2];
    v82 = qcar(v82);
    stack[-1] = v82;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v83 = qvalue(elt(env, 2)); /* maxvar */
    v82 = stack[-1];
    v82 = qcar(v82);
    stack[-4] = v82;
    v82 = plus2(v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-8];
    v83 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v82/(16/CELL)));
    v82 = (Lisp_Object)1; /* 0 */
    v82 = *(Lisp_Object *)((char *)v83 + (CELL-TAG_VECTOR) + ((int32_t)v82/(16/CELL)));
    if (v82 == nil) goto v87;
    v85 = stack[-4];
    v84 = stack[-6];
    v82 = stack[-1];
    v82 = qcdr(v82);
    v83 = qcar(v82);
    v82 = stack[-3];
    fn = elt(env, 9); /* testpr */
    v82 = (*qfnn(fn))(qenv(fn), 4, v85, v84, v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-8];
    stack[0] = v82;
    v82 = qcdr(v82);
    if (v82 == nil) goto v88;
    v82 = stack[0];
    v83 = Llength(nil, v82);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-8];
    stack[-1] = v83;
    v82 = stack[-5];
    v82 = (Lisp_Object)greaterp2(v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v82 = v82 ? lisp_true : nil;
    env = stack[-8];
    if (v82 == nil) goto v89;
    v82 = stack[-1];
    stack[-5] = v82;
    qvalue(elt(env, 5)) = v82; /* newnjsi */
    v82 = stack[-4];
    stack[-7] = v82;
    v82 = stack[0];
    qvalue(elt(env, 6)) = v82; /* newjsi */
    goto v89;

v89:
    v83 = stack[-4];
    v82 = qvalue(elt(env, 7)); /* roccup2 */
    v82 = cons(v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-8];
    qvalue(elt(env, 7)) = v82; /* roccup2 */
    goto v90;

v90:
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v83 = qvalue(elt(env, 2)); /* maxvar */
    v82 = stack[-4];
    v82 = plus2(v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-8];
    v84 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v82/(16/CELL)));
    v83 = (Lisp_Object)1; /* 0 */
    v82 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v84 + (CELL-TAG_VECTOR) + ((int32_t)v83/(16/CELL))) = v82;
    goto v87;

v87:
    v82 = stack[-2];
    v82 = qcdr(v82);
    stack[-2] = v82;
    goto v33;

v88:
    v83 = stack[-4];
    v82 = qvalue(elt(env, 4)); /* roccup1 */
    v82 = cons(v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-8];
    qvalue(elt(env, 4)) = v82; /* roccup1 */
    goto v90;
/* error exit handlers */
v86:
    popv(9);
    return nil;
}



/* Code for critical_element */

static Lisp_Object CC_critical_element(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v38;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for critical_element");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v20 = v0;
/* end of prologue */
    v38 = v20;
    v38 = qcdr(v38);
    v38 = qcar(v38);
        return Lapply1(nil, v38, v20);
}



/* Code for gfftimes */

static Lisp_Object CC_gfftimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v16, v27;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfftimes");
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
    v16 = v1;
    v27 = v0;
/* end of prologue */
    v28 = v27;
    v28 = qcar(v28);
    stack[-4] = v28;
    v28 = v27;
    v28 = qcdr(v28);
    stack[-3] = v28;
    v28 = v16;
    v28 = qcar(v28);
    stack[-2] = v28;
    v28 = v16;
    v28 = qcdr(v28);
    stack[-1] = v28;
    v16 = stack[-4];
    v28 = stack[-2];
    stack[0] = times2(v16, v28);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-5];
    v16 = stack[-3];
    v28 = stack[-1];
    v28 = times2(v16, v28);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-5];
    stack[0] = difference2(stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-5];
    v16 = stack[-4];
    v28 = stack[-1];
    stack[-1] = times2(v16, v28);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-5];
    v16 = stack[-3];
    v28 = stack[-2];
    v28 = times2(v16, v28);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-5];
    v28 = plus2(stack[-1], v28);
    nil = C_nil;
    if (exception_pending()) goto v93;
    {
        Lisp_Object v94 = stack[0];
        popv(6);
        return cons(v94, v28);
    }
/* error exit handlers */
v93:
    popv(6);
    return nil;
}



/* Code for reval3 */

static Lisp_Object CC_reval3(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval3");
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
    fn = elt(env, 1); /* simp */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v58);
    }
/* error exit handlers */
v48:
    popv(1);
    return nil;
}



/* Code for deletez1 */

static Lisp_Object CC_deletez1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v96, v97, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deletez1");
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
    v43 = nil;
    goto v4;

v4:
    v45 = stack[-1];
    if (v45 == nil) goto v98;
    v97 = (Lisp_Object)1; /* 0 */
    v45 = stack[-1];
    v45 = qcar(v45);
    v96 = qcar(v45);
    v45 = stack[0];
    v45 = Lassoc(nil, v96, v45);
    v45 = qcdr(v45);
    if (v97 == v45) goto v17;
    v45 = stack[-1];
    v45 = qcar(v45);
    v96 = v43;
    v45 = cons(v45, v96);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-2];
    v43 = v45;
    v45 = stack[-1];
    v45 = qcdr(v45);
    stack[-1] = v45;
    goto v4;

v17:
    v45 = stack[-1];
    v45 = qcdr(v45);
    stack[-1] = v45;
    goto v4;

v98:
    v45 = v43;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v45);
    }
/* error exit handlers */
v99:
    popv(3);
    return nil;
}



/* Code for splitup */

static Lisp_Object CC_splitup(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v103, v104;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for splitup");
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
    v104 = v1;
    stack[0] = v0;
/* end of prologue */
    v102 = stack[0];
    if (v102 == nil) goto v98;
    v102 = stack[0];
    v102 = qcar(v102);
    v102 = qcar(v102);
    v102 = qcar(v102);
    v103 = v102;
    v102 = v103;
    v102 = (v102 == nil ? lisp_true : nil);
    if (!(v102 == nil)) goto v105;
    v102 = v104;
    v102 = Lmemq(nil, v103, v102);
    goto v105;

v105:
    if (v102 == nil) goto v106;
    v103 = qvalue(elt(env, 1)); /* nil */
    v102 = stack[0];
    popv(3);
    return list2(v103, v102);

v106:
    v102 = stack[0];
    v102 = qcdr(v102);
    v103 = v104;
    v102 = CC_splitup(env, v102, v103);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    v103 = v102;
    v102 = stack[0];
    stack[-1] = qcar(v102);
    v102 = v103;
    stack[0] = qcar(v102);
    v102 = v103;
    v102 = qcdr(v102);
    v102 = qcar(v102);
    v102 = ncons(v102);
    nil = C_nil;
    if (exception_pending()) goto v69;
    {
        Lisp_Object v107 = stack[-1];
        Lisp_Object v87 = stack[0];
        popv(3);
        return acons(v107, v87, v102);
    }

v98:
    v102 = qvalue(elt(env, 1)); /* nil */
    v103 = qvalue(elt(env, 1)); /* nil */
    popv(3);
    return list2(v102, v103);
/* error exit handlers */
v69:
    popv(3);
    return nil;
}



/* Code for set!-weights */

static Lisp_Object CC_setKweights(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for set-weights");
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
    v15 = v0;
/* end of prologue */
    stack[-4] = (Lisp_Object)1; /* 0 */
    v15 = qcdr(v15);
    stack[-3] = v15;
    v15 = stack[-3];
    if (v15 == nil) goto v105;
    v15 = (Lisp_Object)17; /* 1 */
    v15 = ncons(v15);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-5];
    stack[-1] = v15;
    stack[-2] = v15;
    goto v12;

v12:
    v15 = stack[-3];
    v15 = qcdr(v15);
    stack[-3] = v15;
    v15 = stack[-3];
    if (v15 == nil) goto v78;
    stack[0] = stack[-1];
    v15 = (Lisp_Object)17; /* 1 */
    v15 = ncons(v15);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-5];
    v15 = Lrplacd(nil, stack[0], v15);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-5];
    v15 = stack[-1];
    v15 = qcdr(v15);
    stack[-1] = v15;
    goto v12;

v78:
    v15 = stack[-2];
    goto v9;

v9:
    v15 = cons(stack[-4], v15);
    nil = C_nil;
    if (exception_pending()) goto v109;
        popv(6);
        return Lnreverse(nil, v15);

v105:
    v15 = qvalue(elt(env, 1)); /* nil */
    goto v9;
/* error exit handlers */
v109:
    popv(6);
    return nil;
}



/* Code for ofsf_simplat1 */

static Lisp_Object CC_ofsf_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v128, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_simplat1");
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
    v129 = v0;
/* end of prologue */
    v86 = v129;
    v86 = qcar(v86);
    stack[-3] = v86;
    v128 = stack[-3];
    v86 = elt(env, 1); /* (equal neq leq geq lessp greaterp) */
    v86 = Lmemq(nil, v128, v86);
    if (v86 == nil) goto v9;
    v86 = v129;
    v86 = qcdr(v86);
    v86 = qcar(v86);
    stack[-1] = v86;
    v86 = stack[-1];
    if (!consp(v86)) goto v14;
    v86 = stack[-1];
    v86 = qcar(v86);
    if (!consp(v86)) goto v14;
    stack[0] = stack[-1];
    v86 = stack[-1];
    fn = elt(env, 12); /* sfto_dcontentf */
    v86 = (*qfn1(fn))(qenv(fn), v86);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    fn = elt(env, 13); /* quotf */
    v86 = (*qfn2(fn))(qenv(fn), stack[0], v86);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    stack[-1] = v86;
    v86 = stack[-1];
    fn = elt(env, 14); /* minusf */
    v86 = (*qfn1(fn))(qenv(fn), v86);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    if (v86 == nil) goto v44;
    v86 = stack[-1];
    fn = elt(env, 15); /* negf */
    v86 = (*qfn1(fn))(qenv(fn), v86);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    stack[-1] = v86;
    v86 = stack[-3];
    fn = elt(env, 16); /* ofsf_anegrel */
    v86 = (*qfn1(fn))(qenv(fn), v86);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    stack[-3] = v86;
    goto v44;

v44:
    v86 = qvalue(elt(env, 5)); /* !*rlsiatadv */
    if (v86 == nil) goto v93;
    v128 = stack[-3];
    v86 = elt(env, 6); /* equal */
    if (v128 == v86) goto v131;
    v128 = stack[-3];
    v86 = elt(env, 7); /* neq */
    if (v128 == v86) goto v132;
    v128 = stack[-3];
    v86 = elt(env, 8); /* leq */
    if (v128 == v86) goto v133;
    v128 = stack[-3];
    v86 = elt(env, 9); /* geq */
    if (v128 == v86) goto v134;
    v128 = stack[-3];
    v86 = elt(env, 10); /* lessp */
    if (v128 == v86) goto v55;
    v128 = stack[-3];
    v86 = elt(env, 11); /* greaterp */
    if (v128 == v86) goto v135;
    v86 = nil;
    { popv(5); return onevalue(v86); }

v135:
    v128 = stack[-1];
    v86 = stack[-2];
    {
        popv(5);
        fn = elt(env, 17); /* ofsf_simplgreaterp */
        return (*qfn2(fn))(qenv(fn), v128, v86);
    }

v55:
    v128 = stack[-1];
    v86 = stack[-2];
    {
        popv(5);
        fn = elt(env, 18); /* ofsf_simpllessp */
        return (*qfn2(fn))(qenv(fn), v128, v86);
    }

v134:
    v128 = stack[-1];
    v86 = stack[-2];
    {
        popv(5);
        fn = elt(env, 19); /* ofsf_simplgeq */
        return (*qfn2(fn))(qenv(fn), v128, v86);
    }

v133:
    v128 = stack[-1];
    v86 = stack[-2];
    {
        popv(5);
        fn = elt(env, 20); /* ofsf_simplleq */
        return (*qfn2(fn))(qenv(fn), v128, v86);
    }

v132:
    v128 = stack[-1];
    v86 = stack[-2];
    {
        popv(5);
        fn = elt(env, 21); /* ofsf_simplneq */
        return (*qfn2(fn))(qenv(fn), v128, v86);
    }

v131:
    v128 = stack[-1];
    v86 = stack[-2];
    {
        popv(5);
        fn = elt(env, 22); /* ofsf_simplequal */
        return (*qfn2(fn))(qenv(fn), v128, v86);
    }

v93:
    v128 = stack[-3];
    v86 = stack[-1];
    v129 = qvalue(elt(env, 2)); /* nil */
    popv(5);
    return list3(v128, v86, v129);

v14:
    v128 = stack[-3];
    v86 = stack[-1];
    fn = elt(env, 23); /* ofsf_evalatp */
    v86 = (*qfn2(fn))(qenv(fn), v128, v86);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    if (v86 == nil) goto v106;
    v86 = elt(env, 3); /* true */
    { popv(5); return onevalue(v86); }

v106:
    v86 = elt(env, 4); /* false */
    { popv(5); return onevalue(v86); }

v9:
    v86 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v86); }
/* error exit handlers */
v130:
    popv(5);
    return nil;
}



/* Code for pickbasicset */

static Lisp_Object CC_pickbasicset(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pickbasicset");
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
    v138 = qvalue(elt(env, 1)); /* wuvarlist!* */
    stack[-1] = v138;
    goto v48;

v48:
    v138 = stack[-1];
    if (v138 == nil) goto v58;
    v138 = stack[-1];
    v138 = qcar(v138);
    stack[0] = v138;
    goto v19;

v19:
    v138 = stack[-2];
    if (v138 == nil) goto v33;
    v138 = stack[-2];
    v138 = qcar(v138);
    v138 = qcar(v138);
    v138 = qcar(v138);
    v139 = qcar(v138);
    v138 = stack[0];
    fn = elt(env, 3); /* symbollessp */
    v138 = (*qfn2(fn))(qenv(fn), v139, v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    if (v138 == nil) goto v33;
    v138 = stack[-2];
    v138 = qcdr(v138);
    stack[-2] = v138;
    goto v19;

v33:
    v138 = stack[-2];
    if (v138 == nil) goto v32;
    v139 = stack[0];
    v138 = stack[-2];
    v138 = qcar(v138);
    v138 = qcar(v138);
    v138 = qcar(v138);
    v138 = qcar(v138);
    if (!(equal(v139, v138))) goto v32;
    v138 = stack[-2];
    v139 = qcar(v138);
    v138 = stack[-3];
    fn = elt(env, 4); /* wureducedpolysp */
    v138 = (*qfn2(fn))(qenv(fn), v139, v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    if (!(v138 == nil)) goto v32;
    v138 = stack[-2];
    v138 = qcdr(v138);
    stack[-2] = v138;
    goto v33;

v32:
    v138 = stack[-2];
    if (v138 == nil) goto v87;
    v139 = stack[0];
    v138 = stack[-2];
    v138 = qcar(v138);
    v138 = qcar(v138);
    v138 = qcar(v138);
    v138 = qcar(v138);
    if (!(equal(v139, v138))) goto v87;
    v138 = stack[-2];
    v139 = qcar(v138);
    v138 = stack[-3];
    v138 = cons(v139, v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    stack[-3] = v138;
    v138 = stack[-2];
    v138 = qcdr(v138);
    stack[-2] = v138;
    goto v87;

v87:
    v138 = stack[-1];
    v138 = qcdr(v138);
    stack[-1] = v138;
    goto v48;

v58:
    v138 = stack[-3];
        popv(5);
        return Lnreverse(nil, v138);
/* error exit handlers */
v140:
    popv(5);
    return nil;
}



/* Code for expf */

static Lisp_Object CC_expf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expf");
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
    v150 = stack[-2];
    if (v150 == nil) goto v3;
    v59 = stack[-2];
    v150 = (Lisp_Object)17; /* 1 */
    if (v59 == v150) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v150 = stack[-2];
    if (!consp(v150)) goto v46;
    v150 = stack[-2];
    if (!consp(v150)) goto v33;
    v150 = stack[-2];
    v150 = qcar(v150);
    if (!consp(v150)) goto v33;
    v150 = stack[-2];
    v150 = qcdr(v150);
    if (v150 == nil) goto v16;
    v59 = stack[-2];
    v150 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); /* mksp!* */
        return (*qfn2(fn))(qenv(fn), v59, v150);
    }

v16:
    v150 = stack[-2];
    v150 = qcar(v150);
    v150 = qcar(v150);
    v59 = qcdr(v150);
    v150 = stack[-1];
    v150 = times2(v59, v150);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    stack[0] = v150;
    v59 = stack[0];
    v150 = (Lisp_Object)1; /* 0 */
    v150 = (Lisp_Object)greaterp2(v59, v150);
    nil = C_nil;
    if (exception_pending()) goto v151;
    v150 = v150 ? lisp_true : nil;
    env = stack[-4];
    if (v150 == nil) goto v133;
    v150 = stack[-2];
    v150 = qcar(v150);
    v150 = qcar(v150);
    v150 = qcar(v150);
    if (!consp(v150)) goto v133;
    v150 = stack[-2];
    v150 = qcar(v150);
    v150 = qcar(v150);
    v150 = qcar(v150);
    v150 = qcar(v150);
    if (!consp(v150)) goto v133;
    v150 = stack[-2];
    v150 = qcar(v150);
    v150 = qcar(v150);
    v59 = qcar(v150);
    v150 = stack[0];
    fn = elt(env, 3); /* exptf */
    stack[0] = (*qfn2(fn))(qenv(fn), v59, v150);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    v150 = stack[-2];
    v150 = qcar(v150);
    v59 = qcdr(v150);
    v150 = stack[-1];
    v150 = CC_expf(env, v59, v150);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    {
        Lisp_Object v152 = stack[0];
        popv(5);
        fn = elt(env, 4); /* multf */
        return (*qfn2(fn))(qenv(fn), v152, v150);
    }

v133:
    v150 = stack[-2];
    v150 = qcar(v150);
    v150 = qcar(v150);
    stack[-3] = qcar(v150);
    v150 = stack[-2];
    v150 = qcar(v150);
    v59 = qcdr(v150);
    v150 = stack[-1];
    v150 = CC_expf(env, v59, v150);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    v150 = acons(stack[-3], stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v151;
    popv(5);
    return ncons(v150);

v33:
    v59 = stack[-2];
    v150 = stack[-1];
    {
        popv(5);
        fn = elt(env, 5); /* !:expt */
        return (*qfn2(fn))(qenv(fn), v59, v150);
    }

v46:
    stack[0] = (Lisp_Object)17; /* 1 */
    v150 = stack[-1];
    v150 = negate(v150);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    v150 = Lexpt(nil, stack[-2], v150);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    {
        Lisp_Object v153 = stack[0];
        popv(5);
        fn = elt(env, 6); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v153, v150);
    }

v3:
    v150 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v150); }
/* error exit handlers */
v151:
    popv(5);
    return nil;
}



/* Code for replace!-next */

static Lisp_Object CC_replaceKnext(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v149, v100, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replace-next");
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
    goto v4;

v4:
    v43 = stack[-1];
    if (v43 == nil) goto v98;
    v43 = stack[-1];
    v43 = qcar(v43);
    v99 = qcar(v43);
    v43 = stack[-1];
    v43 = qcar(v43);
    v43 = qcdr(v43);
    v100 = qcar(v43);
    v43 = stack[-1];
    v43 = qcar(v43);
    v43 = qcdr(v43);
    v43 = qcdr(v43);
    v149 = qcar(v43);
    v43 = stack[0];
    v43 = qcar(v43);
    v149 = list4(v99, v100, v149, v43);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-3];
    v43 = stack[-2];
    v43 = cons(v149, v43);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-3];
    stack[-2] = v43;
    v43 = stack[-1];
    v43 = qcdr(v43);
    stack[-1] = v43;
    v43 = stack[0];
    v43 = qcdr(v43);
    stack[0] = v43;
    goto v4;

v98:
    v43 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v43);
    }
/* error exit handlers */
v76:
    popv(4);
    return nil;
}



/* Code for pasf_zcong */

static Lisp_Object CC_pasf_zcong(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v157, v135;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_zcong");
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
    v157 = v0;
/* end of prologue */
    v85 = v157;
    v85 = Lconsp(nil, v85);
    env = stack[0];
    if (v85 == nil) { popv(1); return onevalue(v157); }
    v85 = v157;
    v85 = qcar(v85);
    v85 = Lconsp(nil, v85);
    env = stack[0];
    if (v85 == nil) { popv(1); return onevalue(v157); }
    v85 = v157;
    v85 = qcar(v85);
    v135 = qcar(v85);
    v85 = elt(env, 1); /* (cong ncong) */
    v85 = Lmemq(nil, v135, v85);
    if (v85 == nil) { popv(1); return onevalue(v157); }
    v85 = v157;
    v85 = qcar(v85);
    v85 = qcdr(v85);
    if (v85 == nil) goto v100;
    v85 = v157;
    v85 = qcdr(v85);
    v85 = qcar(v85);
    if (!(v85 == nil)) goto v39;
    v135 = v157;
    v85 = elt(env, 2); /* true */
    if (v135 == v85) goto v136;
    v135 = v157;
    v85 = elt(env, 3); /* false */
    if (v135 == v85) goto v136;
    v85 = v157;
    v85 = qcar(v85);
    v85 = Lconsp(nil, v85);
    env = stack[0];
    if (v85 == nil) goto v158;
    v85 = v157;
    v85 = qcar(v85);
    v85 = qcar(v85);
    v135 = v85;
    goto v72;

v72:
    v85 = elt(env, 4); /* cong */
    if (!(v135 == v85)) goto v39;
    v85 = elt(env, 2); /* true */
    { popv(1); return onevalue(v85); }

v39:
    v85 = v157;
    v85 = qcdr(v85);
    v85 = qcar(v85);
    if (!(v85 == nil)) { popv(1); return onevalue(v157); }
    v135 = v157;
    v85 = elt(env, 2); /* true */
    if (v135 == v85) goto v116;
    v135 = v157;
    v85 = elt(env, 3); /* false */
    if (v135 == v85) goto v116;
    v85 = v157;
    v85 = qcar(v85);
    v85 = Lconsp(nil, v85);
    env = stack[0];
    if (v85 == nil) goto v112;
    v85 = v157;
    v85 = qcar(v85);
    v85 = qcar(v85);
    v135 = v85;
    goto v61;

v61:
    v85 = elt(env, 8); /* ncong */
    if (!(v135 == v85)) { popv(1); return onevalue(v157); }
    v85 = elt(env, 3); /* false */
    { popv(1); return onevalue(v85); }

v112:
    v85 = v157;
    v85 = qcar(v85);
    v135 = v85;
    goto v61;

v116:
    v85 = v157;
    v135 = v85;
    goto v61;

v158:
    v85 = v157;
    v85 = qcar(v85);
    v135 = v85;
    goto v72;

v136:
    v85 = v157;
    v135 = v85;
    goto v72;

v100:
    v135 = v157;
    v85 = elt(env, 2); /* true */
    if (v135 == v85) goto v97;
    v135 = v157;
    v85 = elt(env, 3); /* false */
    if (v135 == v85) goto v97;
    v85 = v157;
    v85 = qcar(v85);
    v85 = Lconsp(nil, v85);
    env = stack[0];
    if (v85 == nil) goto v69;
    v85 = v157;
    v85 = qcar(v85);
    v85 = qcar(v85);
    v135 = v85;
    goto v32;

v32:
    v85 = elt(env, 4); /* cong */
    if (v135 == v85) goto v159;
    v85 = elt(env, 6); /* neq */
    goto v36;

v36:
    v157 = qcdr(v157);
    v157 = qcar(v157);
    v135 = qvalue(elt(env, 7)); /* nil */
    popv(1);
    return list3(v85, v157, v135);

v159:
    v85 = elt(env, 5); /* equal */
    goto v36;

v69:
    v85 = v157;
    v85 = qcar(v85);
    v135 = v85;
    goto v32;

v97:
    v85 = v157;
    v135 = v85;
    goto v32;
}



/* Code for ratpoly_neg */

static Lisp_Object CC_ratpoly_neg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_neg");
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
    v38 = stack[0];
    v38 = qcar(v38);
    fn = elt(env, 1); /* negf */
    v17 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v108;
    v38 = stack[0];
    v38 = qcdr(v38);
    popv(1);
    return cons(v17, v38);
/* error exit handlers */
v108:
    popv(1);
    return nil;
}



/* Code for symbolsom */

static Lisp_Object CC_symbolsom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v161, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbolsom");
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
    stack[-1] = nil;
    v160 = stack[-4];
    v161 = qcar(v160);
    v160 = qvalue(elt(env, 1)); /* valid_om!* */
    v160 = Lassoc(nil, v161, v160);
    stack[-5] = v160;
    v160 = stack[-5];
    if (v160 == nil) goto v12;
    v160 = stack[-5];
    v160 = qcdr(v160);
    v160 = qcar(v160);
    stack[-5] = v160;
    goto v12;

v12:
    v160 = stack[-4];
    v160 = qcar(v160);
    stack[0] = v160;
    v160 = stack[-4];
    v160 = qcdr(v160);
    v160 = qcdr(v160);
    v160 = qcar(v160);
    stack[-3] = v160;
    v160 = stack[-4];
    v160 = Lreverse(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-6];
    v160 = qcar(v160);
    stack[-2] = v160;
    v161 = stack[0];
    v160 = elt(env, 2); /* diff */
    if (v161 == v160) goto v81;
    v160 = stack[-4];
    v160 = qcdr(v160);
    v160 = qcdr(v160);
    v160 = qcdr(v160);
    v160 = qcar(v160);
    stack[-1] = v160;
    goto v81;

v81:
    v160 = stack[-1];
    if (v160 == nil) goto v149;
    v160 = stack[-1];
    v161 = qcar(v160);
    v160 = elt(env, 3); /* condition */
    if (!(v161 == v160)) goto v149;
    v161 = elt(env, 4); /* "<condition> tag not supported in MathML" */
    v160 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 15); /* errorml */
    v160 = (*qfn2(fn))(qenv(fn), v161, v160);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-6];
    goto v149;

v149:
    v160 = elt(env, 5); /* "<OMA>" */
    fn = elt(env, 16); /* printout */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-6];
    v160 = qvalue(elt(env, 6)); /* t */
    fn = elt(env, 17); /* indent!* */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-6];
    v160 = stack[-1];
    if (v160 == nil) goto v26;
    v161 = stack[0];
    v160 = elt(env, 7); /* int */
    if (!(v161 == v160)) goto v26;
    v160 = elt(env, 8); /* defint */
    stack[0] = v160;
    goto v26;

v26:
    v160 = elt(env, 9); /* "<OMS cd=""" */
    fn = elt(env, 16); /* printout */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-6];
    v160 = stack[-5];
    v160 = Lprinc(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-6];
    v160 = elt(env, 10); /* """ name=""" */
    v160 = Lprinc(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-6];
    v160 = stack[0];
    v160 = Lprinc(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-6];
    v160 = elt(env, 11); /* """/>" */
    v160 = Lprinc(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-6];
    v160 = stack[-1];
    if (v160 == nil) goto v123;
    v160 = stack[-1];
    fn = elt(env, 18); /* objectom */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-6];
    goto v123;

v123:
    stack[-1] = elt(env, 12); /* lambda */
    stack[0] = qvalue(elt(env, 13)); /* nil */
    v118 = stack[-3];
    v161 = stack[-2];
    v160 = qvalue(elt(env, 13)); /* nil */
    v160 = list2star(v118, v161, v160);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-6];
    v160 = list2star(stack[-1], stack[0], v160);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-6];
    fn = elt(env, 19); /* lambdaom */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-6];
    v160 = qvalue(elt(env, 13)); /* nil */
    fn = elt(env, 17); /* indent!* */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-6];
    v160 = elt(env, 14); /* "</OMA>" */
    fn = elt(env, 16); /* printout */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v141;
    v160 = nil;
    { popv(7); return onevalue(v160); }
/* error exit handlers */
v141:
    popv(7);
    return nil;
}



/* Code for spinnerprod */

static Lisp_Object MS_CDECL CC_spinnerprod(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v31, Lisp_Object v5,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v163, v164, v88;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "spinnerprod");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spinnerprod");
#endif
    if (stack >= stacklimit)
    {
        push6(v3,v2,v5,v31,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v31,v5,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v3;
    v66 = v2;
    v163 = v5;
    stack[-5] = v31;
    v164 = v1;
    v88 = v0;
/* end of prologue */
    stack[-6] = v163;
    v163 = stack[-6];
    stack[-3] = v163;
    v66 = qcdr(v66);
    stack[-1] = v66;
    goto v12;

v12:
    v66 = stack[-1];
    if (v66 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    v66 = stack[-1];
    v66 = qcar(v66);
    v163 = v66;
    v66 = v163;
    v66 = qcar(v66);
    stack[-7] = v66;
    v66 = stack[-7];
    if (!(v66 == nil)) goto v36;
    v66 = (Lisp_Object)1; /* 0 */
    stack[-7] = v66;
    goto v36;

v36:
    v66 = v163;
    v66 = qcdr(v66);
    stack[-2] = v66;
    v66 = stack[-2];
    if (v66 == nil) goto v74;
    stack[0] = stack[-2];
    v66 = qvalue(elt(env, 1)); /* nil */
    v66 = ncons(v66);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-8];
    if (!(equal(stack[0], v66))) goto v166;

v74:
    v66 = (Lisp_Object)1; /* 0 */
    stack[-2] = v66;
    goto v166;

v166:
    v163 = stack[-7];
    v66 = stack[-5];
    v66 = (Lisp_Object)lesseq2(v163, v66);
    nil = C_nil;
    if (exception_pending()) goto v165;
    v66 = v66 ? lisp_true : nil;
    env = stack[-8];
    if (v66 == nil) goto v76;
    v163 = stack[-7];
    v66 = stack[-4];
    v66 = Latsoc(nil, v163, v66);
    stack[-7] = v66;
    v66 = stack[-7];
    if (v66 == nil) goto v76;
    stack[0] = stack[-7];
    v66 = qvalue(elt(env, 1)); /* nil */
    v66 = ncons(v66);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-8];
    if (equal(stack[0], v66)) goto v76;
    stack[0] = elt(env, 2); /* plus */
    stack[-3] = stack[-6];
    v164 = elt(env, 3); /* times */
    v163 = stack[-2];
    v66 = stack[-7];
    v66 = qcdr(v66);
    v66 = list3(v164, v163, v66);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-8];
    v66 = list3(stack[0], stack[-3], v66);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-8];
    stack[-6] = v66;
    v66 = stack[-6];
    stack[-3] = v66;
    goto v76;

v76:
    v66 = stack[-1];
    v66 = qcdr(v66);
    stack[-1] = v66;
    goto v12;
/* error exit handlers */
v165:
    popv(9);
    return nil;
}



/* Code for fnreval */

static Lisp_Object MS_CDECL CC_fnreval(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v31, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v168, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "fnreval");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fnreval");
#endif
    if (stack >= stacklimit)
    {
        push3(v31,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v31;
    stack[-1] = v1;
    stack[0] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v58;

v58:
    v168 = stack[0];
    if (v168 == nil) goto v91;
    v146 = stack[-1];
    v168 = qvalue(elt(env, 1)); /* t */
    if (v146 == v168) goto v47;
    v168 = stack[-1];
    if (v168 == nil) goto v81;
    v168 = stack[-1];
    v168 = qcar(v168);
    if (v168 == nil) goto v169;
    v168 = stack[0];
    v168 = qcar(v168);
    v146 = v168;
    goto v73;

v73:
    v168 = stack[-2];
    v168 = cons(v146, v168);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    stack[-2] = v168;
    v168 = stack[0];
    v168 = qcdr(v168);
    stack[0] = v168;
    v168 = stack[-1];
    v168 = qcdr(v168);
    stack[-1] = v168;
    goto v58;

v169:
    v168 = stack[0];
    v146 = qcar(v168);
    v168 = stack[-4];
    fn = elt(env, 3); /* reval1 */
    v168 = (*qfn2(fn))(qenv(fn), v146, v168);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v146 = v168;
    goto v73;

v81:
    stack[-5] = stack[-2];
    v168 = stack[0];
    stack[-3] = v168;
    v168 = stack[-3];
    if (v168 == nil) goto v43;
    v168 = stack[-3];
    v168 = qcar(v168);
    v146 = v168;
    v168 = stack[-4];
    fn = elt(env, 3); /* reval1 */
    v168 = (*qfn2(fn))(qenv(fn), v146, v168);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v168 = ncons(v168);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    stack[-1] = v168;
    stack[-2] = v168;
    goto v106;

v106:
    v168 = stack[-3];
    v168 = qcdr(v168);
    stack[-3] = v168;
    v168 = stack[-3];
    if (v168 == nil) goto v170;
    stack[0] = stack[-1];
    v168 = stack[-3];
    v168 = qcar(v168);
    v146 = v168;
    v168 = stack[-4];
    fn = elt(env, 3); /* reval1 */
    v168 = (*qfn2(fn))(qenv(fn), v146, v168);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v168 = ncons(v168);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v168 = Lrplacd(nil, stack[0], v168);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v168 = stack[-1];
    v168 = qcdr(v168);
    stack[-1] = v168;
    goto v106;

v170:
    v168 = stack[-2];
    goto v14;

v14:
    {
        Lisp_Object v171 = stack[-5];
        popv(7);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v171, v168);
    }

v43:
    v168 = qvalue(elt(env, 2)); /* nil */
    goto v14;

v47:
    v146 = stack[-2];
    v168 = stack[0];
    {
        popv(7);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v146, v168);
    }

v91:
    v168 = stack[-2];
    {
        popv(7);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v168);
    }
/* error exit handlers */
v165:
    popv(7);
    return nil;
}



/* Code for gpargp */

static Lisp_Object CC_gpargp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gpargp");
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
    v20 = stack[0];
    v20 = Lstringp(nil, v20);
    env = stack[-1];
    if (!(v20 == nil)) { popv(2); return onevalue(v20); }
    v20 = stack[0];
    fn = elt(env, 1); /* gpexpp */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    if (!(v20 == nil)) { popv(2); return onevalue(v20); }
    v20 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* gplogexpp */
        return (*qfn1(fn))(qenv(fn), v20);
    }
/* error exit handlers */
v17:
    popv(2);
    return nil;
}



/* Code for find_bubles_coeff */

static Lisp_Object MS_CDECL CC_find_bubles_coeff(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v31, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v12, v11, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "find_bubles_coeff");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_bubles_coeff");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v127 = v31;
    v12 = v1;
    v11 = v0;
/* end of prologue */
    v19 = v11;
    v11 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* find_bubles1_coeff */
        return (*qfnn(fn))(qenv(fn), 4, v19, v11, v12, v127);
    }
}



/* Code for list2vect!* */

static Lisp_Object CC_list2vectH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list2vect*");
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
    v94 = stack[-4];
    v94 = Llength(nil, v94);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    v94 = sub1(v94);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    v94 = Lmkvect(nil, v94);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    stack[-5] = v94;
    v94 = (Lisp_Object)17; /* 1 */
    stack[-2] = v94;
    goto v19;

v19:
    v94 = stack[-5];
    v94 = Lupbv(nil, v94);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    v69 = add1(v94);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    v94 = stack[-2];
    v94 = difference2(v69, v94);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    v94 = Lminusp(nil, v94);
    env = stack[-6];
    if (!(v94 == nil)) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    stack[-1] = stack[-5];
    v94 = stack[-2];
    stack[0] = sub1(v94);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    v69 = stack[-3];
    v94 = elt(env, 2); /* algebraic */
    if (v69 == v94) goto v99;
    v69 = stack[-4];
    v94 = stack[-2];
    fn = elt(env, 3); /* pnth */
    v94 = (*qfn2(fn))(qenv(fn), v69, v94);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    v94 = qcar(v94);
    goto v81;

v81:
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v94;
    v94 = stack[-2];
    v94 = add1(v94);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    stack[-2] = v94;
    goto v19;

v99:
    v69 = stack[-4];
    v94 = stack[-2];
    fn = elt(env, 3); /* pnth */
    v94 = (*qfn2(fn))(qenv(fn), v69, v94);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    v94 = qcar(v94);
    fn = elt(env, 4); /* symb_to_alg */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    goto v81;
/* error exit handlers */
v126:
    popv(7);
    return nil;
}



/* Code for simprecip */

static Lisp_Object CC_simprecip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simprecip");
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
    v173 = v0;
/* end of prologue */
    v87 = qvalue(elt(env, 1)); /* !*mcd */
    if (v87 == nil) goto v98;
    v87 = v173;
    v87 = qcdr(v87);
    if (v87 == nil) goto v43;
    v173 = elt(env, 2); /* "Wrong number of arguments to" */
    v87 = elt(env, 3); /* recip */
    v87 = list2(v173, v87);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[0];
    v173 = v87;
    v87 = v173;
    qvalue(elt(env, 4)) = v87; /* errmsg!* */
    v87 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v87 == nil)) goto v102;
    v87 = v173;
    fn = elt(env, 6); /* lprie */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[0];
    goto v102;

v102:
    v87 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[0];
    v87 = nil;
    goto v97;

v97:
    fn = elt(env, 7); /* simp */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 8); /* invsq */
        return (*qfn1(fn))(qenv(fn), v87);
    }

v43:
    v87 = v173;
    v87 = qcar(v87);
    goto v97;

v98:
    v87 = v173;
    v87 = qcdr(v87);
    if (v87 == nil) goto v108;
    v173 = elt(env, 2); /* "Wrong number of arguments to" */
    v87 = elt(env, 3); /* recip */
    v87 = list2(v173, v87);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[0];
    v173 = v87;
    v87 = v173;
    qvalue(elt(env, 4)) = v87; /* errmsg!* */
    v87 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v87 == nil)) goto v78;
    v87 = v173;
    fn = elt(env, 6); /* lprie */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[0];
    goto v78;

v78:
    v87 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[0];
    v87 = nil;
    v173 = v87;
    goto v9;

v9:
    v87 = (Lisp_Object)-15; /* -1 */
    v87 = list2(v173, v87);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 9); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v87);
    }

v108:
    v87 = v173;
    v87 = qcar(v87);
    v173 = v87;
    goto v9;
/* error exit handlers */
v26:
    popv(1);
    return nil;
}



/* Code for ordered!-gcd!-mod!-p */

static Lisp_Object CC_orderedKgcdKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordered-gcd-mod-p");
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
    v104 = (Lisp_Object)1; /* 0 */
    stack[-2] = v104;
    goto v98;

v98:
    v93 = stack[-1];
    v104 = stack[0];
    fn = elt(env, 2); /* reduce!-degree!-mod!-p */
    v104 = (*qfn2(fn))(qenv(fn), v93, v104);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    stack[-1] = v104;
    v104 = stack[-1];
    if (v104 == nil) goto v127;
    v104 = stack[-2];
    v104 = add1(v104);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    stack[-2] = v104;
    v104 = stack[-1];
    if (!consp(v104)) goto v80;
    v104 = stack[-1];
    v104 = qcar(v104);
    if (!consp(v104)) goto v80;
    v104 = stack[-1];
    v104 = qcar(v104);
    v104 = qcar(v104);
    v93 = qcdr(v104);
    v104 = stack[0];
    v104 = qcar(v104);
    v104 = qcar(v104);
    v104 = qcdr(v104);
    v104 = (Lisp_Object)lessp2(v93, v104);
    nil = C_nil;
    if (exception_pending()) goto v87;
    v104 = v104 ? lisp_true : nil;
    env = stack[-3];
    if (v104 == nil) goto v98;
    v93 = qvalue(elt(env, 1)); /* reduction!-count */
    v104 = stack[-2];
    v104 = plus2(v93, v104);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    qvalue(elt(env, 1)) = v104; /* reduction!-count */
    v104 = (Lisp_Object)1; /* 0 */
    stack[-2] = v104;
    v104 = stack[-1];
    v93 = v104;
    v104 = stack[0];
    stack[-1] = v104;
    v104 = v93;
    stack[0] = v104;
    goto v98;

v80:
    v93 = qvalue(elt(env, 1)); /* reduction!-count */
    v104 = stack[-2];
    v104 = plus2(v93, v104);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    qvalue(elt(env, 1)) = v104; /* reduction!-count */
    v104 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v104); }

v127:
    v104 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* monic!-mod!-p */
        return (*qfn1(fn))(qenv(fn), v104);
    }
/* error exit handlers */
v87:
    popv(4);
    return nil;
}



/* Code for prepsq!*0 */

static Lisp_Object CC_prepsqH0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v104, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsq*0");
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
    v103 = stack[-2];
    v103 = qcar(v103);
    if (v103 == nil) goto v48;
    v103 = stack[-2];
    v104 = qcar(v103);
    v103 = stack[-2];
    v103 = qcdr(v103);
    fn = elt(env, 2); /* gcdf */
    v104 = (*qfn2(fn))(qenv(fn), v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-4];
    stack[-3] = v104;
    v103 = (Lisp_Object)17; /* 1 */
    if (v104 == v103) goto v109;
    v103 = stack[-2];
    v104 = qcar(v103);
    v103 = stack[-3];
    fn = elt(env, 3); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-4];
    v103 = stack[-2];
    v104 = qcdr(v103);
    v103 = stack[-3];
    fn = elt(env, 3); /* quotf */
    v104 = (*qfn2(fn))(qenv(fn), v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-4];
    v103 = stack[-1];
    {
        Lisp_Object v26 = stack[0];
        popv(5);
        fn = elt(env, 4); /* prepsq!*1 */
        return (*qfnn(fn))(qenv(fn), 3, v26, v104, v103);
    }

v109:
    v103 = stack[-2];
    v93 = qcar(v103);
    v103 = stack[-2];
    v104 = qcdr(v103);
    v103 = stack[-1];
    {
        popv(5);
        fn = elt(env, 4); /* prepsq!*1 */
        return (*qfnn(fn))(qenv(fn), 3, v93, v104, v103);
    }

v48:
    v103 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v103); }
/* error exit handlers */
v173:
    popv(5);
    return nil;
}



/* Code for tayexp!-max2 */

static Lisp_Object CC_tayexpKmax2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-max2");
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
    v11 = stack[-1];
    v12 = stack[0];
    fn = elt(env, 1); /* tayexp!-lessp */
    v12 = (*qfn2(fn))(qenv(fn), v11, v12);
    nil = C_nil;
    if (exception_pending()) goto v46;
    if (v12 == nil) { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v46:
    popv(2);
    return nil;
}



/* Code for mk!+outer!+list */

static Lisp_Object CC_mkLouterLlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v17;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+outer+list");
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
    v38 = elt(env, 1); /* list */
    v17 = ncons(v38);
    nil = C_nil;
    if (exception_pending()) goto v108;
    v38 = stack[0];
        popv(1);
        return Lappend(nil, v17, v38);
/* error exit handlers */
v108:
    popv(1);
    return nil;
}



/* Code for ofsf_facequal!* */

static Lisp_Object CC_ofsf_facequalH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v14, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_facequal*");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v14 = v1;
    v13 = v0;
/* end of prologue */
    v79 = qvalue(elt(env, 1)); /* !*rlsifac */
    if (v79 == nil) goto v23;
    v79 = qvalue(elt(env, 2)); /* !*rlsiexpla */
    if (!(v79 == nil)) goto v3;
    v79 = qvalue(elt(env, 3)); /* !*rlsiexpl */
    if (v79 == nil) goto v23;
    v79 = elt(env, 4); /* or */
    if (!(v14 == v79)) goto v23;

v3:
    v79 = v13;
    {
        fn = elt(env, 7); /* ofsf_facequal */
        return (*qfn1(fn))(qenv(fn), v79);
    }

v23:
    v79 = elt(env, 5); /* equal */
    v14 = v13;
    v13 = qvalue(elt(env, 6)); /* nil */
    return list3(v79, v14, v13);
}



/* Code for cl_smsimpl!-junct2 */

static Lisp_Object MS_CDECL CC_cl_smsimplKjunct2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v31, Lisp_Object v5,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v39, v40, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "cl_smsimpl-junct2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_smsimpl-junct2");
#endif
    if (stack >= stacklimit)
    {
        push6(v3,v2,v5,v31,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v31,v5,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v3;
    v137 = v2;
    v39 = v5;
    v40 = v31;
    stack[-2] = v1;
    v41 = v0;
/* end of prologue */
    fn = elt(env, 5); /* rl_smmkatl */
    v137 = (*qfnn(fn))(qenv(fn), 4, v41, v40, v39, v137);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    stack[-3] = v137;
    v137 = qvalue(elt(env, 1)); /* !*rlsichk */
    if (v137 == nil) goto v29;
    v137 = stack[-2];
    v39 = v137;
    v137 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v137;
    v137 = v39;
    stack[0] = v137;
    goto v80;

v80:
    v137 = stack[0];
    if (v137 == nil) goto v21;
    v137 = stack[0];
    v137 = qcar(v137);
    v39 = v137;
    v137 = stack[-2];
    fn = elt(env, 6); /* lto_insert */
    v137 = (*qfn2(fn))(qenv(fn), v39, v137);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    stack[-2] = v137;
    v137 = stack[0];
    v137 = qcdr(v137);
    stack[0] = v137;
    goto v80;

v21:
    v137 = qvalue(elt(env, 3)); /* !*rlsiso */
    if (v137 == nil) goto v104;
    v39 = stack[-3];
    v137 = elt(env, 4); /* rl_ordatp */
    fn = elt(env, 7); /* sort */
    v137 = (*qfn2(fn))(qenv(fn), v39, v137);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    stack[-3] = v137;
    goto v104;

v104:
    v39 = stack[-3];
    v137 = stack[-2];
    v137 = Lnconc(nil, v39, v137);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    v39 = v137;
    v137 = v39;
    if (!(v137 == nil)) { popv(5); return onevalue(v39); }
    v137 = stack[-1];
    fn = elt(env, 8); /* cl_flip */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v174;
    popv(5);
    return ncons(v137);

v29:
    v137 = stack[-2];
    v137 = Lnreverse(nil, v137);
    env = stack[-4];
    stack[-2] = v137;
    goto v21;
/* error exit handlers */
v174:
    popv(5);
    return nil;
}



/* Code for binomial!-coefft!-mod!-p */

static Lisp_Object CC_binomialKcoefftKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v171, v160, v161, v118, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for binomial-coefft-mod-p");
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
    v160 = stack[-2];
    v171 = stack[-1];
    v171 = (Lisp_Object)lessp2(v160, v171);
    nil = C_nil;
    if (exception_pending()) goto v61;
    v171 = v171 ? lisp_true : nil;
    env = stack[-4];
    if (v171 == nil) goto v127;
    v171 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v171); }

v127:
    v160 = stack[-2];
    v171 = stack[-1];
    if (equal(v160, v171)) goto v108;
    v160 = stack[-1];
    v171 = (Lisp_Object)17; /* 1 */
    if (v160 == v171) goto v21;
    v171 = (Lisp_Object)17; /* 1 */
    stack[-3] = v171;
    stack[0] = stack[-1];
    v160 = stack[-2];
    v171 = stack[-1];
    v171 = difference2(v160, v171);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    fn = elt(env, 2); /* min */
    v171 = (*qfn2(fn))(qenv(fn), stack[0], v171);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    stack[0] = v171;
    v171 = stack[-2];
    v171 = Lmodular_number(nil, v171);
    env = stack[-4];
    stack[-2] = v171;
    v171 = stack[-1];
    v171 = Lmodular_number(nil, v171);
    env = stack[-4];
    v171 = (Lisp_Object)17; /* 1 */
    stack[-1] = v171;
    goto v176;

v176:
    v160 = stack[0];
    v171 = stack[-1];
    v171 = difference2(v160, v171);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v171 = Lminusp(nil, v171);
    env = stack[-4];
    if (v171 == nil) goto v26;
    v171 = stack[-3];
    v171 = (Lisp_Object)zerop(v171);
    v171 = v171 ? lisp_true : nil;
    env = stack[-4];
    if (v171 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v171 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v171); }

v26:
    v171 = stack[-1];
    v171 = Lmodular_number(nil, v171);
    env = stack[-4];
    v119 = v171;
    v118 = stack[-3];
    v161 = stack[-2];
    v160 = v119;
    v171 = (Lisp_Object)17; /* 1 */
    {   int32_t w = int_of_fixnum(v160) - int_of_fixnum(v171);
        if (w < 0) w += current_modulus;
        v171 = fixnum_of_int(w);
    }
    {   int32_t w = int_of_fixnum(v161) - int_of_fixnum(v171);
        if (w < 0) w += current_modulus;
        v171 = fixnum_of_int(w);
    }
    v171 = Lmodular_times(nil, v118, v171);
    env = stack[-4];
    v160 = v119;
    v171 = Lmodular_quotient(nil, v171, v160);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    stack[-3] = v171;
    v171 = stack[-1];
    v171 = add1(v171);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    stack[-1] = v171;
    goto v176;

v21:
    v171 = stack[-2];
    v171 = Lmodular_number(nil, v171);
    env = stack[-4];
    v160 = v171;
    v171 = v160;
    v171 = (Lisp_Object)zerop(v171);
    v171 = v171 ? lisp_true : nil;
    env = stack[-4];
    if (v171 == nil) { popv(5); return onevalue(v160); }
    v171 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v171); }

v108:
    v171 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v171); }
/* error exit handlers */
v61:
    popv(5);
    return nil;
}



/* Code for dip_fmon */

static Lisp_Object CC_dip_fmon(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18, v108;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip_fmon");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v18 = v1;
    v17 = v0;
/* end of prologue */
    v108 = qvalue(elt(env, 1)); /* nil */
    return list2star(v18, v17, v108);
}



/* Code for applyfnrd */

static Lisp_Object MS_CDECL CC_applyfnrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "applyfnrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for applyfnrd");
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
    fn = elt(env, 2); /* fnrd */
    v37 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    stack[0] = v37;
    fn = elt(env, 3); /* stats_getargs */
    v37 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    v46 = stack[0];
    v37 = cons(v46, v37);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 4); /* aeval */
        return (*qfn1(fn))(qenv(fn), v37);
    }
/* error exit handlers */
v47:
    popv(2);
    return nil;
}



/* Code for reduceroots */

static Lisp_Object CC_reduceroots(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduceroots");
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
    v32 = nil;
    goto v48;

v48:
    v33 = stack[-1];
    if (v33 == nil) { popv(3); return onevalue(v32); }
    v33 = stack[0];
    v106 = qcar(v33);
    v33 = elt(env, 2); /* sqrt */
    if (!consp(v106)) goto v108;
    v106 = qcar(v106);
    if (!(v106 == v33)) goto v108;
    v106 = stack[-1];
    v33 = stack[0];
    v33 = qcar(v33);
    fn = elt(env, 3); /* tryreduction */
    v32 = (*qfnn(fn))(qenv(fn), 3, v106, v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    goto v108;

v108:
    v33 = stack[-1];
    v33 = qcdr(v33);
    stack[-1] = v33;
    v33 = stack[0];
    v33 = qcdr(v33);
    stack[0] = v33;
    goto v48;
/* error exit handlers */
v97:
    popv(3);
    return nil;
}



/* Code for crprcd2 */

static Lisp_Object CC_crprcd2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crprcd2");
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
    v132 = stack[-1];
    v132 = qcdr(v132);
    v132 = qcar(v132);
    if (!consp(v132)) goto v4;
    v140 = elt(env, 1); /* !:rd!: */
    v132 = stack[-1];
    v132 = qcdr(v132);
    v132 = qcar(v132);
    v132 = cons(v140, v132);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    goto v3;

v3:
    fn = elt(env, 3); /* convchk */
    stack[-2] = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    v132 = stack[-1];
    v132 = qcdr(v132);
    v132 = qcdr(v132);
    if (!consp(v132)) goto v24;
    v140 = elt(env, 1); /* !:rd!: */
    v132 = stack[-1];
    v132 = qcdr(v132);
    v132 = qcdr(v132);
    v132 = cons(v140, v132);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    goto v23;

v23:
    fn = elt(env, 3); /* convchk */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    v140 = stack[-2];
    v132 = cons(v140, v132);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    stack[-1] = v132;
    v132 = stack[0];
    v132 = qcdr(v132);
    v132 = qcar(v132);
    if (!consp(v132)) goto v166;
    v140 = elt(env, 1); /* !:rd!: */
    v132 = stack[0];
    v132 = qcdr(v132);
    v132 = qcar(v132);
    v132 = cons(v140, v132);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    goto v109;

v109:
    fn = elt(env, 3); /* convchk */
    stack[-2] = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    v132 = stack[0];
    v132 = qcdr(v132);
    v132 = qcdr(v132);
    if (!consp(v132)) goto v167;
    v140 = elt(env, 1); /* !:rd!: */
    v132 = stack[0];
    v132 = qcdr(v132);
    v132 = qcdr(v132);
    v132 = cons(v140, v132);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    goto v126;

v126:
    fn = elt(env, 3); /* convchk */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    v140 = stack[-2];
    v132 = cons(v140, v132);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    qvalue(elt(env, 2)) = v132; /* yy!! */
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v167:
    v132 = stack[0];
    v132 = qcdr(v132);
    v132 = qcdr(v132);
    goto v126;

v166:
    v132 = stack[0];
    v132 = qcdr(v132);
    v132 = qcar(v132);
    goto v109;

v24:
    v132 = stack[-1];
    v132 = qcdr(v132);
    v132 = qcdr(v132);
    goto v23;

v4:
    v132 = stack[-1];
    v132 = qcdr(v132);
    v132 = qcar(v132);
    goto v3;
/* error exit handlers */
v120:
    popv(4);
    return nil;
}



/* Code for on!-double1 */

static Lisp_Object CC_onKdouble1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for on-double1");
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

v2:
    v24 = stack[0];
    v24 = Lconsp(nil, v24);
    env = stack[-1];
    if (v24 == nil) goto v21;
    v24 = stack[0];
    v24 = qcar(v24);
    fn = elt(env, 3); /* doublep */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-1];
    if (v24 == nil) goto v12;
    v24 = lisp_true;
    qvalue(elt(env, 1)) = v24; /* !*double */
    { popv(2); return onevalue(v24); }

v12:
    v24 = stack[0];
    v24 = qcar(v24);
    v24 = CC_onKdouble1(env, v24);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-1];
    v24 = stack[0];
    v24 = qcdr(v24);
    stack[0] = v24;
    goto v2;

v21:
    v24 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v24); }
/* error exit handlers */
v49:
    popv(2);
    return nil;
}



/* Code for listpri */

static Lisp_Object CC_listpri(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listpri");
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
    v88 = stack[-2];
    stack[0] = v88;
    v88 = stack[-2];
    v88 = qcdr(v88);
    stack[-2] = v88;
    v168 = elt(env, 1); /* !*lcbkt!* */
    v88 = elt(env, 2); /* prtch */
    v88 = get(v168, v88);
    env = stack[-4];
    fn = elt(env, 9); /* prin2!* */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    v88 = qvalue(elt(env, 3)); /* orig!* */
    stack[-3] = v88;
    v168 = qvalue(elt(env, 4)); /* posn!* */
    v88 = (Lisp_Object)289; /* 18 */
    v88 = (Lisp_Object)lessp2(v168, v88);
    nil = C_nil;
    if (exception_pending()) goto v64;
    v88 = v88 ? lisp_true : nil;
    env = stack[-4];
    if (v88 == nil) goto v79;
    v88 = qvalue(elt(env, 4)); /* posn!* */
    goto v46;

v46:
    qvalue(elt(env, 3)) = v88; /* orig!* */
    v88 = stack[-2];
    if (v88 == nil) goto v178;
    v168 = stack[-2];
    v88 = (Lisp_Object)641; /* 40 */
    fn = elt(env, 10); /* treesizep1 */
    v168 = (*qfn2(fn))(qenv(fn), v168, v88);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    v88 = (Lisp_Object)1; /* 0 */
    v88 = (v168 == v88 ? lisp_true : nil);
    stack[-1] = v88;
    goto v69;

v69:
    v88 = stack[-2];
    v168 = qcar(v88);
    v88 = elt(env, 5); /* minus */
    if (!consp(v168)) goto v125;
    v168 = qcar(v168);
    if (!(v168 == v88)) goto v125;
    v88 = stack[-2];
    v88 = qcar(v88);
    v88 = qcdr(v88);
    v88 = qcar(v88);
    if (!(is_number(v88))) goto v125;
    v88 = stack[-2];
    v88 = qcar(v88);
    v88 = qcdr(v88);
    v88 = qcar(v88);
    v88 = negate(v88);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    v168 = v88;
    goto v16;

v16:
    v88 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 11); /* maprint */
    v88 = (*qfn2(fn))(qenv(fn), v168, v88);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    v88 = stack[-2];
    v88 = qcdr(v88);
    stack[-2] = v88;
    v88 = stack[-2];
    if (v88 == nil) goto v178;
    v88 = elt(env, 6); /* !*comma!* */
    fn = elt(env, 12); /* oprin */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    v88 = stack[-1];
    if (v88 == nil) goto v69;
    v88 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 13); /* terpri!* */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    goto v69;

v178:
    v168 = elt(env, 8); /* !*rcbkt!* */
    v88 = elt(env, 2); /* prtch */
    v88 = get(v168, v88);
    env = stack[-4];
    fn = elt(env, 9); /* prin2!* */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    v88 = stack[-3];
    qvalue(elt(env, 3)) = v88; /* orig!* */
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v125:
    v88 = stack[-2];
    v88 = qcar(v88);
    v168 = v88;
    goto v16;

v79:
    v168 = qvalue(elt(env, 3)); /* orig!* */
    v88 = (Lisp_Object)49; /* 3 */
    v88 = plus2(v168, v88);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    goto v46;
/* error exit handlers */
v64:
    popv(5);
    return nil;
}



/* Code for r2oaddspecies */

static Lisp_Object CC_r2oaddspecies(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v159;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2oaddspecies");
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
    v159 = stack[-1];
    v13 = stack[0];
    v13 = Lassoc(nil, v159, v13);
    if (!(v13 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v13 = elt(env, 1); /* "new species: " */
    v13 = Lprinc(nil, v13);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-2];
    v13 = stack[-1];
    v13 = Lprinc(nil, v13);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-2];
    v13 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-2];
    v159 = stack[-1];
    v13 = (Lisp_Object)1; /* 0 */
    v13 = cons(v159, v13);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-2];
    v13 = ncons(v13);
    nil = C_nil;
    if (exception_pending()) goto v34;
    {
        Lisp_Object v32 = stack[0];
        popv(3);
        return Lappend(nil, v32, v13);
    }
/* error exit handlers */
v34:
    popv(3);
    return nil;
}



/* Code for !:!:quotient */

static Lisp_Object CC_TTquotient(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ::quotient");
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
    v14 = v1;
    v79 = v0;
/* end of prologue */
    stack[0] = v79;
    v79 = v14;
    v79 = integerp(v79);
    if (v79 == nil) goto v80;
    v79 = v14;
    fn = elt(env, 2); /* chkint!* */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-1];
    v14 = v79;
    if (!(!consp(v14))) goto v58;
    v14 = elt(env, 1); /* !:rd!: */
    v79 = cons(v14, v79);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-1];
    goto v58;

v58:
    {
        Lisp_Object v101 = stack[0];
        popv(2);
        fn = elt(env, 3); /* !:quotient */
        return (*qfn2(fn))(qenv(fn), v101, v79);
    }

v80:
    v79 = v14;
    goto v58;
/* error exit handlers */
v159:
    popv(2);
    return nil;
}



/* Code for z!-roads */

static Lisp_Object CC_zKroads(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v107, v87;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for z-roads");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v87 = v0;
/* end of prologue */
    v107 = (Lisp_Object)1; /* 0 */
    v69 = v87;
    v69 = qcar(v69);
    v69 = qcar(v69);
    v69 = qcdr(v69);
    if (v107 == v69) goto v2;
    v107 = (Lisp_Object)1; /* 0 */
    v69 = v87;
    v69 = qcar(v69);
    v69 = qcdr(v69);
    v69 = qcar(v69);
    v69 = qcdr(v69);
    if (v107 == v69) goto v12;
    v107 = (Lisp_Object)1; /* 0 */
    v69 = v87;
    v69 = qcar(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcar(v69);
    v69 = qcdr(v69);
    if (v107 == v69) goto v81;
    v69 = qvalue(elt(env, 1)); /* nil */
    goto v5;

v5:
    v107 = v69;
    v69 = v107;
    if (v69 == nil) goto v109;
    v69 = v107;
    v69 = qcar(v69);
    v107 = v87;
    v107 = qcdr(v107);
    return cons(v69, v107);

v109:
    v69 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v69);

v81:
    v69 = v87;
    v69 = qcar(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = qcar(v69);
    goto v5;

v12:
    v69 = v87;
    v69 = qcar(v69);
    v69 = qcdr(v69);
    v69 = qcar(v69);
    goto v5;

v2:
    v69 = v87;
    v69 = qcar(v69);
    v69 = qcar(v69);
    goto v5;
}



/* Code for lieninstruc */

static Lisp_Object CC_lieninstruc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v186, v187, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lieninstruc");
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
    v185 = (Lisp_Object)17; /* 1 */
    stack[-5] = v185;
    goto v18;

v18:
    stack[0] = elt(env, 1); /* difference */
    v187 = elt(env, 1); /* difference */
    v186 = stack[-4];
    v185 = (Lisp_Object)17; /* 1 */
    v185 = list3(v187, v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v186 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    v185 = stack[-5];
    v185 = list3(stack[0], v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    fn = elt(env, 8); /* aminusp!: */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    if (v185 == nil) goto v91;
    v185 = nil;
    { popv(7); return onevalue(v185); }

v91:
    v185 = stack[-5];
    v185 = add1(v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    stack[-3] = v185;
    goto v96;

v96:
    stack[0] = elt(env, 1); /* difference */
    v185 = stack[-4];
    fn = elt(env, 7); /* aeval!* */
    v186 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    v185 = stack[-3];
    v185 = list3(stack[0], v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    fn = elt(env, 8); /* aminusp!: */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    if (v185 == nil) goto v34;
    v185 = stack[-5];
    v187 = elt(env, 6); /* plus */
    v186 = v185;
    v185 = (Lisp_Object)17; /* 1 */
    v185 = list3(v187, v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    stack[-5] = v185;
    goto v18;

v34:
    v185 = (Lisp_Object)17; /* 1 */
    stack[-2] = v185;
    goto v102;

v102:
    stack[0] = elt(env, 1); /* difference */
    v185 = stack[-4];
    fn = elt(env, 7); /* aeval!* */
    v186 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    v185 = stack[-2];
    v185 = list3(stack[0], v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    fn = elt(env, 8); /* aminusp!: */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    if (v185 == nil) goto v39;
    v185 = stack[-3];
    v187 = elt(env, 6); /* plus */
    v186 = v185;
    v185 = (Lisp_Object)17; /* 1 */
    v185 = list3(v187, v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    stack[-3] = v185;
    goto v96;

v39:
    v130 = elt(env, 3); /* lie_cc */
    v187 = stack[-5];
    v186 = stack[-3];
    v185 = stack[-2];
    stack[0] = list4(v130, v187, v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    v130 = elt(env, 4); /* lienstrucin */
    v187 = stack[-5];
    v186 = stack[-3];
    v185 = stack[-2];
    v185 = list4(v130, v187, v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    fn = elt(env, 9); /* setk */
    v185 = (*qfn2(fn))(qenv(fn), stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    v130 = elt(env, 3); /* lie_cc */
    v187 = stack[-3];
    v186 = stack[-5];
    v185 = stack[-2];
    stack[-1] = list4(v130, v187, v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    stack[0] = elt(env, 5); /* minus */
    v130 = elt(env, 4); /* lienstrucin */
    v187 = stack[-5];
    v186 = stack[-3];
    v185 = stack[-2];
    v185 = list4(v130, v187, v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    v185 = list2(stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    fn = elt(env, 9); /* setk */
    v185 = (*qfn2(fn))(qenv(fn), stack[-1], v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    v185 = stack[-2];
    v187 = elt(env, 6); /* plus */
    v186 = v185;
    v185 = (Lisp_Object)17; /* 1 */
    v185 = list3(v187, v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-6];
    stack[-2] = v185;
    goto v102;
/* error exit handlers */
v188:
    popv(7);
    return nil;
}



/* Code for pst_subpst */

static Lisp_Object CC_pst_subpst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v17;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_subpst");
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
    push(nil);
/* copy arguments values to proper place */
    v17 = v1;
    v38 = v0;
/* end of prologue */
    stack[0] = qcdr(v38);
    v38 = v17;
    v38 = sub1(v38);
    nil = C_nil;
    if (exception_pending()) goto v108;
    v38 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v38/(16/CELL)));
    { popv(1); return onevalue(v38); }
/* error exit handlers */
v108:
    popv(1);
    return nil;
}



/* Code for ratlessp */

static Lisp_Object CC_ratlessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratlessp");
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
    v12 = v1;
    v11 = v0;
/* end of prologue */
    fn = elt(env, 1); /* ratdif */
    v12 = (*qfn2(fn))(qenv(fn), v11, v12);
    errexit();
    v11 = qcar(v12);
    v12 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v11, v12);
}



/* Code for diff!-k!-times!-mod!-p */

static Lisp_Object MS_CDECL CC_diffKkKtimesKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v31, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v150, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "diff-k-times-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff-k-times-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v31,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v31;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v144 = stack[-3];
    if (!consp(v144)) goto v4;
    v144 = stack[-3];
    v144 = qcar(v144);
    if (!consp(v144)) goto v4;
    v144 = stack[-3];
    v144 = qcar(v144);
    v144 = qcar(v144);
    v150 = qcar(v144);
    v144 = stack[-1];
    if (equal(v150, v144)) goto v49;
    v144 = stack[-3];
    v144 = qcar(v144);
    stack[-4] = qcar(v144);
    v144 = stack[-3];
    v144 = qcar(v144);
    v59 = qcdr(v144);
    v150 = stack[-2];
    v144 = stack[-1];
    stack[0] = CC_diffKkKtimesKmodKp(env, 3, v59, v150, v144);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-5];
    v144 = stack[-3];
    v59 = qcdr(v144);
    v150 = stack[-2];
    v144 = stack[-1];
    v144 = CC_diffKkKtimesKmodKp(env, 3, v59, v150, v144);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-5];
    {
        Lisp_Object v153 = stack[-4];
        Lisp_Object v192 = stack[0];
        popv(6);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v153, v192, v144);
    }

v49:
    v144 = stack[-3];
    v144 = qcar(v144);
    v144 = qcar(v144);
    v150 = qcdr(v144);
    v144 = stack[-2];
    v144 = (Lisp_Object)lessp2(v150, v144);
    nil = C_nil;
    if (exception_pending()) goto v152;
    v144 = v144 ? lisp_true : nil;
    env = stack[-5];
    if (v144 == nil) goto v34;
    v144 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v144); }

v34:
    v144 = stack[-3];
    v144 = qcar(v144);
    v144 = qcar(v144);
    v150 = qcdr(v144);
    v144 = stack[-2];
    if (equal(v150, v144)) goto v101;
    v144 = stack[-1];
    fn = elt(env, 3); /* fkern */
    stack[0] = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-5];
    v144 = stack[-3];
    v144 = qcar(v144);
    v144 = qcar(v144);
    v150 = qcdr(v144);
    v144 = stack[-2];
    v144 = difference2(v150, v144);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-5];
    fn = elt(env, 4); /* getpower */
    stack[-4] = (*qfn2(fn))(qenv(fn), stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-5];
    v144 = stack[-3];
    v144 = qcar(v144);
    v144 = qcar(v144);
    v150 = qcdr(v144);
    v144 = stack[-2];
    fn = elt(env, 5); /* binomial!-coefft!-mod!-p */
    v150 = (*qfn2(fn))(qenv(fn), v150, v144);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-5];
    v144 = stack[-3];
    v144 = qcar(v144);
    v144 = qcdr(v144);
    fn = elt(env, 6); /* times!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v150, v144);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-5];
    v144 = stack[-3];
    v59 = qcdr(v144);
    v150 = stack[-2];
    v144 = stack[-1];
    v144 = CC_diffKkKtimesKmodKp(env, 3, v59, v150, v144);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-5];
    {
        Lisp_Object v90 = stack[-4];
        Lisp_Object v155 = stack[0];
        popv(6);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v90, v155, v144);
    }

v101:
    v144 = stack[-3];
    v144 = qcar(v144);
    v144 = qcdr(v144);
    { popv(6); return onevalue(v144); }

v4:
    v144 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v144); }
/* error exit handlers */
v152:
    popv(6);
    return nil;
}



/* Code for sfto_reorder */

static Lisp_Object CC_sfto_reorder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_reorder");
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
    v17 = v1;
    stack[0] = v0;
/* end of prologue */
    v17 = ncons(v17);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-2];
    fn = elt(env, 1); /* setkorder */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-2];
    stack[-1] = v17;
    v17 = stack[0];
    fn = elt(env, 2); /* reorder */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-2];
    stack[0] = v17;
    v17 = stack[-1];
    fn = elt(env, 1); /* setkorder */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v7;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v7:
    popv(3);
    return nil;
}



/* Code for depend!-f */

static Lisp_Object CC_dependKf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for depend-f");
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

v193:
    v96 = stack[-1];
    if (!consp(v96)) goto v3;
    v96 = stack[-1];
    v96 = qcar(v96);
    if (!consp(v96)) goto v3;
    v96 = stack[-1];
    v96 = qcar(v96);
    v96 = qcar(v96);
    v97 = qcar(v96);
    v96 = stack[0];
    fn = elt(env, 2); /* depend!-p */
    v96 = (*qfn2(fn))(qenv(fn), v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    if (!(v96 == nil)) { popv(3); return onevalue(v96); }
    v96 = stack[-1];
    v96 = qcar(v96);
    v97 = qcdr(v96);
    v96 = stack[0];
    v96 = CC_dependKf(env, v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    if (!(v96 == nil)) { popv(3); return onevalue(v96); }
    v96 = stack[-1];
    v97 = qcdr(v96);
    v96 = stack[0];
    stack[-1] = v97;
    stack[0] = v96;
    goto v193;

v3:
    v96 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v96); }
/* error exit handlers */
v100:
    popv(3);
    return nil;
}



/* Code for pasf_exprng1 */

static Lisp_Object CC_pasf_exprng1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v217, v218, v219, v220, v221, v222, v223;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_exprng1");
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
    v217 = v0;
/* end of prologue */
    v219 = v217;
    v218 = elt(env, 1); /* true */
    if (v219 == v218) { popv(6); return onevalue(v217); }
    v219 = v217;
    v218 = elt(env, 2); /* false */
    if (v219 == v218) { popv(6); return onevalue(v217); }
    v218 = v217;
    if (!consp(v218)) goto v23;
    v218 = v217;
    v218 = qcar(v218);
    goto v22;

v22:
    stack[-4] = v218;
    v219 = stack[-4];
    v218 = elt(env, 3); /* or */
    if (v219 == v218) goto v79;
    v219 = stack[-4];
    v218 = elt(env, 4); /* and */
    if (v219 == v218) goto v79;
    v219 = stack[-4];
    v218 = elt(env, 5); /* not */
    if (v219 == v218) goto v79;
    v219 = stack[-4];
    v218 = elt(env, 6); /* impl */
    if (v219 == v218) goto v79;
    v219 = stack[-4];
    v218 = elt(env, 7); /* repl */
    if (v219 == v218) goto v79;
    v219 = stack[-4];
    v218 = elt(env, 8); /* equiv */
    if (v219 == v218) goto v79;
    v219 = stack[-4];
    v218 = elt(env, 10); /* ex */
    if (v219 == v218) goto v224;
    v219 = stack[-4];
    v218 = elt(env, 11); /* all */
    if (v219 == v218) goto v224;
    v219 = stack[-4];
    v218 = elt(env, 12); /* ball */
    if (v219 == v218) goto v225;
    v219 = stack[-4];
    v218 = elt(env, 13); /* bex */
    if (!(v219 == v218)) { popv(6); return onevalue(v217); }
    v223 = stack[-4];
    v218 = v217;
    v218 = qcdr(v218);
    v222 = qcar(v218);
    v218 = v217;
    v218 = qcdr(v218);
    v218 = qcdr(v218);
    v218 = qcdr(v218);
    v221 = qcar(v218);
    v217 = qcdr(v217);
    v217 = qcdr(v217);
    v220 = qcar(v217);
    v219 = elt(env, 3); /* or */
    v218 = elt(env, 2); /* false */
    v217 = elt(env, 1); /* true */
    {
        popv(6);
        fn = elt(env, 14); /* pasf_exprng1!-gand */
        return (*qfnn(fn))(qenv(fn), 7, v223, v222, v221, v220, v219, v218, v217);
    }

v225:
    v223 = stack[-4];
    v218 = v217;
    v218 = qcdr(v218);
    v222 = qcar(v218);
    v218 = v217;
    v218 = qcdr(v218);
    v218 = qcdr(v218);
    v218 = qcdr(v218);
    v221 = qcar(v218);
    v217 = qcdr(v217);
    v217 = qcdr(v217);
    v220 = qcar(v217);
    v219 = elt(env, 4); /* and */
    v218 = elt(env, 1); /* true */
    v217 = elt(env, 2); /* false */
    {
        popv(6);
        fn = elt(env, 14); /* pasf_exprng1!-gand */
        return (*qfnn(fn))(qenv(fn), 7, v223, v222, v221, v220, v219, v218, v217);
    }

v224:
    stack[-1] = stack[-4];
    v218 = v217;
    v218 = qcdr(v218);
    stack[0] = qcar(v218);
    v217 = qcdr(v217);
    v217 = qcdr(v217);
    v217 = qcar(v217);
    v217 = CC_pasf_exprng1(env, v217);
    nil = C_nil;
    if (exception_pending()) goto v226;
    {
        Lisp_Object v227 = stack[-1];
        Lisp_Object v228 = stack[0];
        popv(6);
        return list3(v227, v228, v217);
    }

v79:
    v217 = qcdr(v217);
    stack[-3] = v217;
    v217 = stack[-3];
    if (v217 == nil) goto v73;
    v217 = stack[-3];
    v217 = qcar(v217);
    v217 = CC_pasf_exprng1(env, v217);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-5];
    v217 = ncons(v217);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-5];
    stack[-1] = v217;
    stack[-2] = v217;
    goto v42;

v42:
    v217 = stack[-3];
    v217 = qcdr(v217);
    stack[-3] = v217;
    v217 = stack[-3];
    if (v217 == nil) goto v169;
    stack[0] = stack[-1];
    v217 = stack[-3];
    v217 = qcar(v217);
    v217 = CC_pasf_exprng1(env, v217);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-5];
    v217 = ncons(v217);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-5];
    v217 = Lrplacd(nil, stack[0], v217);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-5];
    v217 = stack[-1];
    v217 = qcdr(v217);
    stack[-1] = v217;
    goto v42;

v169:
    v217 = stack[-2];
    goto v125;

v125:
    v218 = v217;
    v217 = v218;
    if (v217 == nil) goto v160;
    v217 = v218;
    v217 = qcdr(v217);
    if (v217 == nil) goto v160;
    v217 = stack[-4];
    popv(6);
    return cons(v217, v218);

v160:
    v217 = v218;
    if (v217 == nil) goto v60;
    v217 = v218;
    v217 = qcar(v217);
    { popv(6); return onevalue(v217); }

v60:
    v218 = stack[-4];
    v217 = elt(env, 4); /* and */
    if (v218 == v217) goto v150;
    v217 = elt(env, 2); /* false */
    { popv(6); return onevalue(v217); }

v150:
    v217 = elt(env, 1); /* true */
    { popv(6); return onevalue(v217); }

v73:
    v217 = qvalue(elt(env, 9)); /* nil */
    goto v125;

v23:
    v218 = v217;
    goto v22;
/* error exit handlers */
v226:
    popv(6);
    return nil;
}



/* Code for vdp_make */

static Lisp_Object MS_CDECL CC_vdp_make(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v31, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v21, v22;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vdp_make");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_make");
#endif
    if (stack >= stacklimit)
    {
        push3(v31,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v47 = v31;
    v21 = v1;
    v22 = v0;
/* end of prologue */
    stack[-2] = elt(env, 1); /* vdp */
    stack[-1] = v21;
    stack[0] = v22;
    v21 = v47;
    v47 = qvalue(elt(env, 2)); /* nil */
    v47 = list2(v21, v47);
    nil = C_nil;
    if (exception_pending()) goto v49;
    {
        Lisp_Object v50 = stack[-2];
        Lisp_Object v35 = stack[-1];
        Lisp_Object v36 = stack[0];
        popv(3);
        return list3star(v50, v35, v36, v47);
    }
/* error exit handlers */
v49:
    popv(3);
    return nil;
}



/* Code for matrixom */

static Lisp_Object CC_matrixom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixom");
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
    v11 = elt(env, 1); /* "<OMA>" */
    fn = elt(env, 6); /* printout */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v11 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 7); /* indent!* */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v11 = elt(env, 3); /* "<OMS cd=""linalg1"" name=""matrix""/>" */
    fn = elt(env, 6); /* printout */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v11 = stack[0];
    v11 = qcdr(v11);
    v11 = qcdr(v11);
    v11 = qcdr(v11);
    v11 = qcar(v11);
    fn = elt(env, 8); /* matrixrowom */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v11 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 7); /* indent!* */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v11 = elt(env, 5); /* "</OMA>" */
    fn = elt(env, 6); /* printout */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v11 = nil;
    { popv(2); return onevalue(v11); }
/* error exit handlers */
v37:
    popv(2);
    return nil;
}



/* Code for splitcomplex */

static Lisp_Object CC_splitcomplex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for splitcomplex");
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
    stack[0] = v0;
/* end of prologue */
    v94 = qvalue(elt(env, 1)); /* kord!* */
    v93 = qvalue(elt(env, 2)); /* t */
    stack[-4] = qvalue(elt(env, 1)); /* kord!* */
    qvalue(elt(env, 1)) = v94; /* kord!* */
    stack[-3] = qvalue(elt(env, 3)); /* !*exp */
    qvalue(elt(env, 3)) = v93; /* !*exp */
    v94 = elt(env, 4); /* i */
    v93 = elt(env, 5); /* idvalfn */
    v93 = get(v94, v93);
    env = stack[-5];
    if (v93 == nil) goto v95;
    v93 = stack[0];
    fn = elt(env, 6); /* expand!-imrepart */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    goto v91;

v91:
    stack[-2] = v93;
    v93 = stack[-2];
    v93 = qcar(v93);
    fn = elt(env, 7); /* repartf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    v93 = stack[-2];
    stack[0] = qcdr(v93);
    v93 = stack[-2];
    v93 = qcar(v93);
    fn = elt(env, 8); /* impartf */
    v94 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    v93 = stack[-2];
    v93 = qcdr(v93);
    v93 = cons(v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    v93 = acons(stack[-1], stack[0], v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    qvalue(elt(env, 3)) = stack[-3]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-4]; /* kord!* */
    { popv(6); return onevalue(v93); }

v95:
    v94 = elt(env, 4); /* i */
    v93 = stack[0];
    v93 = Lsmemq(nil, v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    if (v93 == nil) goto v21;
    v94 = elt(env, 4); /* i */
    v93 = qvalue(elt(env, 1)); /* kord!* */
    v93 = cons(v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    fn = elt(env, 9); /* setkorder */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    v93 = stack[0];
    fn = elt(env, 10); /* reorder */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    stack[0] = v93;
    goto v21;

v21:
    v93 = stack[0];
    fn = elt(env, 6); /* expand!-imrepart */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    fn = elt(env, 11); /* subs2 */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    goto v91;
/* error exit handlers */
v8:
    env = stack[-5];
    qvalue(elt(env, 3)) = stack[-3]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-4]; /* kord!* */
    popv(6);
    return nil;
}



/* Code for gcompatible */

static Lisp_Object CC_gcompatible(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v105, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcompatible");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v105 = v1;
    v47 = v0;
/* end of prologue */
    v46 = qvalue(elt(env, 1)); /* gmodule!* */
    v46 = (v46 == nil ? lisp_true : nil);
    if (!(v46 == nil)) return onevalue(v46);
    v46 = v47;
    v46 = qcdr(v46);
    v47 = qcar(v46);
    v46 = v105;
    v46 = qcdr(v46);
    v105 = qcar(v46);
    v46 = qvalue(elt(env, 1)); /* gmodule!* */
    {
        fn = elt(env, 2); /* gevcompatible1 */
        return (*qfnn(fn))(qenv(fn), 3, v47, v105, v46);
    }
}



/* Code for subs2p */

static Lisp_Object MS_CDECL CC_subs2p(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v31, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v184, v73, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subs2p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2p");
#endif
    if (stack >= stacklimit)
    {
        push3(v31,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v184 = stack[-2];
    v184 = qcdr(v184);
    v184 = integerp(v184);
    if (v184 == nil) goto v14;
    v184 = stack[-2];
    v73 = qcdr(v184);
    v184 = stack[-1];
    v184 = Ldivide(nil, v73, v184);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-3];
    stack[-1] = v184;
    v73 = qcar(v184);
    v184 = (Lisp_Object)1; /* 0 */
    if (v73 == v184) goto v14;
    v184 = stack[0];
    fn = elt(env, 1); /* simp */
    v73 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-3];
    v184 = stack[-1];
    v184 = qcar(v184);
    fn = elt(env, 2); /* exptsq */
    v184 = (*qfn2(fn))(qenv(fn), v73, v184);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-3];
    stack[0] = v184;
    v184 = stack[-1];
    v73 = qcdr(v184);
    v184 = (Lisp_Object)1; /* 0 */
    if (v73 == v184) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v184 = stack[-2];
    v70 = qcar(v184);
    v184 = stack[-1];
    v73 = qcdr(v184);
    v184 = (Lisp_Object)17; /* 1 */
    v184 = acons(v70, v73, v184);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-3];
    v73 = ncons(v184);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-3];
    v184 = (Lisp_Object)17; /* 1 */
    v73 = cons(v73, v184);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-3];
    v184 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* multsq */
        return (*qfn2(fn))(qenv(fn), v73, v184);
    }

v14:
    v73 = stack[-2];
    v184 = (Lisp_Object)17; /* 1 */
    v184 = cons(v73, v184);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-3];
    v73 = ncons(v184);
    nil = C_nil;
    if (exception_pending()) goto v177;
    v184 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v73, v184);
/* error exit handlers */
v177:
    popv(4);
    return nil;
}



/* Code for vdp2a */

static Lisp_Object CC_vdp2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v48 = v0;
/* end of prologue */
    v48 = qcdr(v48);
    v48 = qcdr(v48);
    v48 = qcdr(v48);
    v48 = qcar(v48);
    {
        fn = elt(env, 1); /* dip2a */
        return (*qfn1(fn))(qenv(fn), v48);
    }
}



setup_type const u32_setup[] =
{
    {"afactor",                 too_few_2,      CC_afactor,    wrong_no_2},
    {"cl_bnfsimpl",             too_few_2,      CC_cl_bnfsimpl,wrong_no_2},
    {"aex_neg",                 CC_aex_neg,     too_many_1,    wrong_no_1},
    {"listrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_listrd},
    {"plusrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_plusrd},
    {"bfminus",                 CC_bfminus,     too_many_1,    wrong_no_1},
    {"findoptrow",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_findoptrow},
    {"critical_element",        CC_critical_element,too_many_1,wrong_no_1},
    {"gfftimes",                too_few_2,      CC_gfftimes,   wrong_no_2},
    {"reval3",                  CC_reval3,      too_many_1,    wrong_no_1},
    {"deletez1",                too_few_2,      CC_deletez1,   wrong_no_2},
    {"splitup",                 too_few_2,      CC_splitup,    wrong_no_2},
    {"set-weights",             CC_setKweights, too_many_1,    wrong_no_1},
    {"ofsf_simplat1",           too_few_2,      CC_ofsf_simplat1,wrong_no_2},
    {"pickbasicset",            CC_pickbasicset,too_many_1,    wrong_no_1},
    {"expf",                    too_few_2,      CC_expf,       wrong_no_2},
    {"replace-next",            too_few_2,      CC_replaceKnext,wrong_no_2},
    {"pasf_zcong",              CC_pasf_zcong,  too_many_1,    wrong_no_1},
    {"ratpoly_neg",             CC_ratpoly_neg, too_many_1,    wrong_no_1},
    {"symbolsom",               CC_symbolsom,   too_many_1,    wrong_no_1},
    {"spinnerprod",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_spinnerprod},
    {"fnreval",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_fnreval},
    {"gpargp",                  CC_gpargp,      too_many_1,    wrong_no_1},
    {"find_bubles_coeff",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_find_bubles_coeff},
    {"list2vect*",              too_few_2,      CC_list2vectH, wrong_no_2},
    {"simprecip",               CC_simprecip,   too_many_1,    wrong_no_1},
    {"ordered-gcd-mod-p",       too_few_2,      CC_orderedKgcdKmodKp,wrong_no_2},
    {"prepsq*0",                too_few_2,      CC_prepsqH0,   wrong_no_2},
    {"tayexp-max2",             too_few_2,      CC_tayexpKmax2,wrong_no_2},
    {"mk+outer+list",           CC_mkLouterLlist,too_many_1,   wrong_no_1},
    {"ofsf_facequal*",          too_few_2,      CC_ofsf_facequalH,wrong_no_2},
    {"cl_smsimpl-junct2",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_smsimplKjunct2},
    {"binomial-coefft-mod-p",   too_few_2,      CC_binomialKcoefftKmodKp,wrong_no_2},
    {"dip_fmon",                too_few_2,      CC_dip_fmon,   wrong_no_2},
    {"applyfnrd",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_applyfnrd},
    {"reduceroots",             too_few_2,      CC_reduceroots,wrong_no_2},
    {"crprcd2",                 too_few_2,      CC_crprcd2,    wrong_no_2},
    {"on-double1",              CC_onKdouble1,  too_many_1,    wrong_no_1},
    {"listpri",                 CC_listpri,     too_many_1,    wrong_no_1},
    {"r2oaddspecies",           too_few_2,      CC_r2oaddspecies,wrong_no_2},
    {"::quotient",              too_few_2,      CC_TTquotient, wrong_no_2},
    {"z-roads",                 CC_zKroads,     too_many_1,    wrong_no_1},
    {"lieninstruc",             CC_lieninstruc, too_many_1,    wrong_no_1},
    {"pst_subpst",              too_few_2,      CC_pst_subpst, wrong_no_2},
    {"ratlessp",                too_few_2,      CC_ratlessp,   wrong_no_2},
    {"diff-k-times-mod-p",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffKkKtimesKmodKp},
    {"sfto_reorder",            too_few_2,      CC_sfto_reorder,wrong_no_2},
    {"depend-f",                too_few_2,      CC_dependKf,   wrong_no_2},
    {"pasf_exprng1",            CC_pasf_exprng1,too_many_1,    wrong_no_1},
    {"vdp_make",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdp_make},
    {"matrixom",                CC_matrixom,    too_many_1,    wrong_no_1},
    {"splitcomplex",            CC_splitcomplex,too_many_1,    wrong_no_1},
    {"gcompatible",             too_few_2,      CC_gcompatible,wrong_no_2},
    {"subs2p",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_subs2p},
    {"vdp2a",                   CC_vdp2a,       too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u32", (two_args *)"21063 2984727 6017251", 0}
};

/* end of generated code */
