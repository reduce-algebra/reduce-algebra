
/* $destdir\u28.c        Machine generated C code */

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


/* Code for valuecoefft */

static Lisp_Object MS_CDECL CC_valuecoefft(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8, v9, v10, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "valuecoefft");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for valuecoefft");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v9 = v2;
    v10 = v1;
    v11 = v0;
/* end of prologue */

v12:
    v7 = v9;
    if (v7 == nil) goto v13;
    v8 = v11;
    v7 = v9;
    v7 = qcar(v7);
    if (v8 == v7) goto v14;
    v7 = v10;
    v7 = qcdr(v7);
    v10 = v7;
    v7 = v9;
    v7 = qcdr(v7);
    v9 = v7;
    goto v12;

v14:
    v7 = v10;
    v8 = qcar(v7);
    v7 = (Lisp_Object)1; /* 0 */
    if (v8 == v7) goto v15;
    v7 = v10;
    v7 = qcar(v7);
    return onevalue(v7);

v15:
    v7 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v7);

v13:
    v7 = elt(env, 1); /* "Valuecoefft - no value" */
    {
        fn = elt(env, 3); /* interr */
        return (*qfn1(fn))(qenv(fn), v7);
    }
}



/* Code for qqe_eta!-in!-term1 */

static Lisp_Object CC_qqe_etaKinKterm1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_eta-in-term1");
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
    v19 = stack[0];
    v19 = qcdr(v19);
    v19 = qcar(v19);
    fn = elt(env, 4); /* qqe_simplterm */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    stack[-1] = v19;
    v19 = stack[0];
    fn = elt(env, 5); /* qqe_op */
    v4 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    v19 = stack[-1];
    v19 = cons(v4, v19);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    v4 = stack[-1];
    v19 = elt(env, 1); /* qepsilon */
    if (v4 == v19) goto v21;
    v19 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v19); }

v21:
    v19 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v19); }
/* error exit handlers */
v20:
    popv(3);
    return nil;
}



/* Code for lambdavar */

static Lisp_Object CC_lambdavar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambdavar");
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
    v13 = v0;
/* end of prologue */
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = Lreverse(nil, v13);
    errexit();
    v13 = qcdr(v13);
    return onevalue(v13);
}



/* Code for domainvalchk */

static Lisp_Object CC_domainvalchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v32, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for domainvalchk");
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
    v32 = qvalue(elt(env, 1)); /* dmode!* */
    v31 = elt(env, 0); /* domainvalchk */
    v31 = get(v32, v31);
    env = stack[-3];
    stack[-2] = v31;
    if (v31 == nil) goto v34;
    v33 = stack[-2];
    v32 = stack[-1];
    v31 = stack[0];
        popv(4);
        return Lapply2(nil, 3, v33, v32, v31);

v34:
    v31 = stack[0];
    v31 = Lreverse(nil, v31);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    stack[0] = v31;
    goto v12;

v12:
    v31 = stack[0];
    if (v31 == nil) goto v36;
    v31 = stack[0];
    v31 = qcar(v31);
    v32 = qcdr(v31);
    v31 = (Lisp_Object)17; /* 1 */
    if (v32 == v31) goto v37;
    v31 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v31); }

v37:
    v31 = stack[0];
    v31 = qcar(v31);
    fn = elt(env, 3); /* mk!*sq */
    v32 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    v31 = stack[-2];
    v31 = cons(v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    stack[-2] = v31;
    v31 = stack[0];
    v31 = qcdr(v31);
    stack[0] = v31;
    goto v12;

v36:
    v32 = stack[-1];
    v31 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); /* valuechk */
        return (*qfn2(fn))(qenv(fn), v32, v31);
    }
/* error exit handlers */
v35:
    popv(4);
    return nil;
}



/* Code for doublep */

static Lisp_Object CC_doublep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v5, v40;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for doublep");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v40 = v0;
/* end of prologue */
    v5 = v40;
    v21 = elt(env, 1); /* !:rd!: */
    if (!consp(v5)) goto v41;
    v5 = qcar(v5);
    if (!(v5 == v21)) goto v41;
    v21 = v40;
    v21 = qcdr(v21);
        return Lconsp(nil, v21);

v41:
    v21 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v21);
}



/* Code for s!-nextarg */

static Lisp_Object CC_sKnextarg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v72, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for s-nextarg");
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
    v71 = qvalue(elt(env, 1)); /* !*udebug */
    if (v71 == nil) goto v74;
    v71 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 13); /* uprint */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    goto v74;

v74:
    v71 = qvalue(elt(env, 3)); /* comb */
    if (!(v71 == nil)) goto v16;
    v71 = qvalue(elt(env, 4)); /* i */
    v71 = add1(v71);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    qvalue(elt(env, 4)) = v71; /* i */
    v71 = stack[0];
    fn = elt(env, 14); /* initcomb */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    qvalue(elt(env, 3)) = v71; /* comb */
    goto v16;

v16:
    v72 = stack[0];
    v71 = qvalue(elt(env, 3)); /* comb */
    fn = elt(env, 15); /* getcomb */
    v71 = (*qfn2(fn))(qenv(fn), v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    stack[-1] = v71;
    if (v71 == nil) goto v76;
    v72 = qvalue(elt(env, 4)); /* i */
    v71 = (Lisp_Object)17; /* 1 */
    if (!(v72 == v71)) goto v31;
    v72 = qvalue(elt(env, 4)); /* i */
    v71 = qvalue(elt(env, 5)); /* upb */
    v71 = (Lisp_Object)lesseq2(v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v75;
    v71 = v71 ? lisp_true : nil;
    env = stack[-2];
    if (v71 == nil) goto v31;
    v71 = stack[-1];
    v71 = qcar(v71);
    v72 = qcar(v71);
    v71 = stack[-1];
    v71 = qcdr(v71);
    popv(3);
    return cons(v72, v71);

v31:
    v72 = qvalue(elt(env, 4)); /* i */
    v71 = (Lisp_Object)1; /* 0 */
    if (!(v72 == v71)) goto v77;
    v72 = qvalue(elt(env, 4)); /* i */
    v71 = qvalue(elt(env, 5)); /* upb */
    v71 = (Lisp_Object)lesseq2(v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v75;
    v71 = v71 ? lisp_true : nil;
    env = stack[-2];
    if (v71 == nil) goto v77;
    v72 = elt(env, 6); /* (null!-fn) */
    v71 = stack[0];
    popv(3);
    return cons(v72, v71);

v77:
    v71 = qvalue(elt(env, 7)); /* acontract */
    if (v71 == nil) goto v78;
    v72 = qvalue(elt(env, 4)); /* i */
    v71 = qvalue(elt(env, 5)); /* upb */
    v71 = (Lisp_Object)lesseq2(v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v75;
    v71 = v71 ? lisp_true : nil;
    env = stack[-2];
    if (v71 == nil) goto v78;
    v73 = qvalue(elt(env, 8)); /* op */
    v71 = stack[-1];
    v72 = qcar(v71);
    v71 = stack[-1];
    v71 = qcdr(v71);
    v71 = acons(v73, v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 16); /* mval */
        return (*qfn1(fn))(qenv(fn), v71);
    }

v78:
    v71 = qvalue(elt(env, 9)); /* mcontract */
    if (v71 == nil) goto v79;
    v72 = qvalue(elt(env, 4)); /* i */
    v71 = qvalue(elt(env, 5)); /* upb */
    v71 = (Lisp_Object)lesseq2(v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v75;
    v71 = v71 ? lisp_true : nil;
    env = stack[-2];
    if (v71 == nil) goto v79;
    v73 = elt(env, 10); /* null!-fn */
    v71 = stack[-1];
    v72 = qcar(v71);
    v71 = stack[-1];
    v71 = qcdr(v71);
    popv(3);
    return acons(v73, v72, v71);

v79:
    v71 = qvalue(elt(env, 11)); /* expand */
    if (v71 == nil) goto v80;
    v71 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 11)) = v71; /* expand */
    v72 = qvalue(elt(env, 12)); /* identity */
    v71 = stack[0];
    popv(3);
    return cons(v72, v71);

v80:
    v71 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v71); }

v76:
    v72 = qvalue(elt(env, 4)); /* i */
    v71 = (Lisp_Object)1; /* 0 */
    if (!(v72 == v71)) goto v81;
    v72 = qvalue(elt(env, 4)); /* i */
    v71 = qvalue(elt(env, 5)); /* upb */
    v71 = (Lisp_Object)lesseq2(v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v75;
    v71 = v71 ? lisp_true : nil;
    env = stack[-2];
    if (v71 == nil) goto v81;
    v72 = elt(env, 6); /* (null!-fn) */
    v71 = stack[0];
    popv(3);
    return cons(v72, v71);

v81:
    v71 = qvalue(elt(env, 11)); /* expand */
    if (v71 == nil) goto v82;
    v71 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 11)) = v71; /* expand */
    v72 = qvalue(elt(env, 12)); /* identity */
    v71 = stack[0];
    popv(3);
    return cons(v72, v71);

v82:
    v71 = nil;
    { popv(3); return onevalue(v71); }
/* error exit handlers */
v75:
    popv(3);
    return nil;
}



/* Code for evinvlexcomp */

static Lisp_Object CC_evinvlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v90;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evinvlexcomp");
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

v91:
    v89 = stack[-1];
    if (v89 == nil) goto v34;
    v89 = stack[0];
    if (v89 == nil) goto v92;
    v89 = stack[-1];
    v90 = qcar(v89);
    v89 = stack[0];
    v89 = qcar(v89);
    v89 = Leqn(nil, v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    if (v89 == nil) goto v10;
    v89 = stack[-1];
    v89 = qcdr(v89);
    stack[-1] = v89;
    v89 = stack[0];
    v89 = qcdr(v89);
    stack[0] = v89;
    goto v91;

v10:
    v89 = stack[-1];
    v90 = qcdr(v89);
    v89 = stack[0];
    v89 = qcdr(v89);
    v89 = CC_evinvlexcomp(env, v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    stack[-2] = v89;
    v90 = stack[-2];
    v89 = (Lisp_Object)1; /* 0 */
    v89 = Leqn(nil, v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v93;
    if (v89 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v89 = stack[0];
    v90 = qcar(v89);
    v89 = stack[-1];
    v89 = qcar(v89);
    if (((int32_t)(v90)) > ((int32_t)(v89))) goto v94;
    v89 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v89); }

v94:
    v89 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v89); }

v92:
    v90 = stack[-1];
    v89 = elt(env, 1); /* (0) */
    {
        popv(4);
        fn = elt(env, 2); /* evlexcomp */
        return (*qfn2(fn))(qenv(fn), v90, v89);
    }

v34:
    v89 = stack[0];
    if (v89 == nil) goto v38;
    v89 = elt(env, 1); /* (0) */
    stack[-1] = v89;
    goto v91;

v38:
    v89 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v89); }
/* error exit handlers */
v93:
    popv(4);
    return nil;
}



/* Code for dipprodin */

static Lisp_Object CC_dipprodin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v98, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipprodin");
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
    goto v74;

v74:
    v97 = stack[-1];
    if (v97 == nil) goto v34;
    v97 = stack[0];
    if (v97 == nil) goto v34;
    v97 = stack[-1];
    v97 = qcdr(v97);
    v99 = qcar(v97);
    v97 = stack[-1];
    v98 = qcar(v97);
    v97 = stack[0];
    fn = elt(env, 2); /* dipprodin1 */
    v98 = (*qfnn(fn))(qenv(fn), 3, v99, v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    v97 = stack[-2];
    v97 = cons(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    stack[-2] = v97;
    v97 = stack[-1];
    v97 = qcdr(v97);
    v97 = qcdr(v97);
    stack[-1] = v97;
    goto v74;

v34:
    v97 = qvalue(elt(env, 1)); /* dipzero */
    v98 = v97;
    goto v13;

v13:
    v97 = stack[-2];
    if (v97 == nil) { popv(4); return onevalue(v98); }
    v97 = stack[-2];
    v97 = qcar(v97);
    fn = elt(env, 3); /* dipsum */
    v97 = (*qfn2(fn))(qenv(fn), v97, v98);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    v98 = v97;
    v97 = stack[-2];
    v97 = qcdr(v97);
    stack[-2] = v97;
    goto v13;
/* error exit handlers */
v23:
    popv(4);
    return nil;
}



/* Code for exdff0 */

static Lisp_Object CC_exdff0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exdff0");
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
    goto v12;

v12:
    v108 = stack[-2];
    if (!consp(v108)) goto v74;
    v108 = stack[-2];
    v108 = qcar(v108);
    if (!consp(v108)) goto v74;
    v108 = stack[-2];
    v108 = qcar(v108);
    v109 = qcar(v108);
    v108 = (Lisp_Object)17; /* 1 */
    v108 = cons(v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v109 = ncons(v108);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v108 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v108 = stack[-2];
    v108 = qcar(v108);
    v108 = qcdr(v108);
    v108 = CC_exdff0(env, v108);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    fn = elt(env, 2); /* multsqpf */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v108);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v108 = stack[-2];
    v108 = qcar(v108);
    v108 = qcar(v108);
    fn = elt(env, 3); /* exdfp0 */
    stack[0] = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v108 = stack[-2];
    v108 = qcar(v108);
    v109 = qcdr(v108);
    v108 = (Lisp_Object)17; /* 1 */
    v108 = cons(v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    fn = elt(env, 4); /* multpfsq */
    v108 = (*qfn2(fn))(qenv(fn), stack[0], v108);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    fn = elt(env, 5); /* addpf */
    v109 = (*qfn2(fn))(qenv(fn), stack[-1], v108);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v108 = stack[-3];
    v108 = cons(v109, v108);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    stack[-3] = v108;
    v108 = stack[-2];
    v108 = qcdr(v108);
    stack[-2] = v108;
    goto v12;

v74:
    v108 = qvalue(elt(env, 1)); /* nil */
    v109 = v108;
    goto v34;

v34:
    v108 = stack[-3];
    if (v108 == nil) { popv(5); return onevalue(v109); }
    v108 = stack[-3];
    v108 = qcar(v108);
    fn = elt(env, 5); /* addpf */
    v108 = (*qfn2(fn))(qenv(fn), v108, v109);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v109 = v108;
    v108 = stack[-3];
    v108 = qcdr(v108);
    stack[-3] = v108;
    goto v34;
/* error exit handlers */
v61:
    popv(5);
    return nil;
}



/* Code for applysetop */

static Lisp_Object CC_applysetop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v145, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for applysetop");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v145 = v1;
    stack[-6] = v0;
/* end of prologue */
    stack[-5] = nil;
    v144 = (Lisp_Object)1; /* 0 */
    stack[-7] = v144;
    v144 = v145;
    stack[-4] = v144;
    v144 = stack[-4];
    if (v144 == nil) goto v30;
    v144 = stack[-4];
    v144 = qcar(v144);
    stack[0] = v144;
    v144 = stack[0];
    fn = elt(env, 6); /* reval */
    v145 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[0] = v145;
    v144 = elt(env, 2); /* list */
    if (!consp(v145)) goto v29;
    v145 = qcar(v145);
    if (!(v145 == v144)) goto v29;
    v144 = stack[0];
    v144 = qcdr(v144);
    fn = elt(env, 7); /* delete!-dups */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[0] = v144;
    v145 = stack[-7];
    v144 = (Lisp_Object)1; /* 0 */
    if (v145 == v144) goto v28;
    v146 = stack[-6];
    v145 = stack[-7];
    v144 = stack[0];
    v144 = Lapply2(nil, 3, v146, v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    goto v27;

v27:
    stack[-7] = v144;
    v144 = stack[0];
    fn = elt(env, 8); /* make!-set */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    goto v16;

v16:
    v144 = ncons(v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[-2] = v144;
    stack[-3] = v144;
    goto v148;

v148:
    v144 = stack[-4];
    v144 = qcdr(v144);
    stack[-4] = v144;
    v144 = stack[-4];
    if (v144 == nil) goto v149;
    stack[-1] = stack[-2];
    v144 = stack[-4];
    v144 = qcar(v144);
    stack[0] = v144;
    v144 = stack[0];
    fn = elt(env, 6); /* reval */
    v145 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[0] = v145;
    v144 = elt(env, 2); /* list */
    if (!consp(v145)) goto v150;
    v145 = qcar(v145);
    if (!(v145 == v144)) goto v150;
    v144 = stack[0];
    v144 = qcdr(v144);
    fn = elt(env, 7); /* delete!-dups */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[0] = v144;
    v145 = stack[-7];
    v144 = (Lisp_Object)1; /* 0 */
    if (v145 == v144) goto v151;
    v146 = stack[-6];
    v145 = stack[-7];
    v144 = stack[0];
    v144 = Lapply2(nil, 3, v146, v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    goto v152;

v152:
    stack[-7] = v144;
    v144 = stack[0];
    fn = elt(env, 8); /* make!-set */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    goto v153;

v153:
    v144 = ncons(v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v144 = Lrplacd(nil, stack[-1], v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v144 = stack[-2];
    v144 = qcdr(v144);
    stack[-2] = v144;
    goto v148;

v151:
    v144 = stack[0];
    goto v152;

v150:
    v144 = stack[0];
    if (symbolp(v144)) goto v72;
    v144 = stack[0];
    v144 = Lconsp(nil, v144);
    env = stack[-8];
    if (v144 == nil) goto v154;
    v144 = stack[0];
    v145 = qcar(v144);
    v144 = elt(env, 3); /* setvalued */
    v144 = Lflagp(nil, v145, v144);
    env = stack[-8];
    if (!(v144 == nil)) goto v72;

v154:
    v145 = stack[0];
    v144 = elt(env, 4); /* "set" */
    fn = elt(env, 9); /* typerr */
    v144 = (*qfn2(fn))(qenv(fn), v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    goto v153;

v72:
    v145 = stack[0];
    v144 = stack[-5];
    v144 = Lmember(nil, v145, v144);
    if (!(v144 == nil)) goto v42;
    v145 = stack[0];
    v144 = stack[-5];
    v144 = cons(v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[-5] = v144;
    goto v42;

v42:
    v144 = stack[0];
    goto v153;

v149:
    v144 = stack[-3];
    goto v38;

v38:
    v146 = v144;
    v144 = stack[-5];
    if (v144 == nil) goto v155;
    stack[0] = stack[-6];
    v145 = stack[-6];
    v144 = elt(env, 5); /* setdiff */
    if (v145 == v144) goto v156;
    v145 = stack[-7];
    v144 = (Lisp_Object)1; /* 0 */
    if (v145 == v144) goto v157;
    v144 = stack[-7];
    fn = elt(env, 8); /* make!-set */
    v145 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v144 = stack[-5];
    v144 = cons(v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    goto v158;

v158:
    {
        Lisp_Object v159 = stack[0];
        popv(9);
        return cons(v159, v144);
    }

v157:
    v144 = stack[-5];
    goto v158;

v156:
    v144 = v146;
    goto v158;

v155:
    v144 = stack[-7];
    fn = elt(env, 8); /* make!-set */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    {
        popv(9);
        fn = elt(env, 10); /* aeval */
        return (*qfn1(fn))(qenv(fn), v144);
    }

v28:
    v144 = stack[0];
    goto v27;

v29:
    v144 = stack[0];
    if (symbolp(v144)) goto v63;
    v144 = stack[0];
    v144 = Lconsp(nil, v144);
    env = stack[-8];
    if (v144 == nil) goto v160;
    v144 = stack[0];
    v145 = qcar(v144);
    v144 = elt(env, 3); /* setvalued */
    v144 = Lflagp(nil, v145, v144);
    env = stack[-8];
    if (!(v144 == nil)) goto v63;

v160:
    v145 = stack[0];
    v144 = elt(env, 4); /* "set" */
    fn = elt(env, 9); /* typerr */
    v144 = (*qfn2(fn))(qenv(fn), v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    goto v16;

v63:
    v145 = stack[0];
    v144 = stack[-5];
    v144 = Lmember(nil, v145, v144);
    if (!(v144 == nil)) goto v89;
    v145 = stack[0];
    v144 = stack[-5];
    v144 = cons(v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[-5] = v144;
    goto v89;

v89:
    v144 = stack[0];
    goto v16;

v30:
    v144 = qvalue(elt(env, 1)); /* nil */
    goto v38;
/* error exit handlers */
v147:
    popv(9);
    return nil;
}



/* Code for rd!:difference */

static Lisp_Object CC_rdTdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v176, v177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:difference");
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
    stack[0] = v0;
/* end of prologue */
    v175 = qvalue(elt(env, 2)); /* !*!*roundbf */
    if (!(v175 == nil)) goto v28;
    v175 = stack[0];
    v175 = qcdr(v175);
    if (!(!consp(v175))) goto v28;
    v175 = stack[-1];
    v175 = qcdr(v175);
    if (!(!consp(v175))) goto v28;
    v175 = stack[0];
    stack[-2] = qcdr(v175);
    v175 = stack[-1];
    v175 = qcdr(v175);
    v175 = negate(v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    fn = elt(env, 7); /* safe!-fp!-plus */
    v175 = (*qfn2(fn))(qenv(fn), stack[-2], v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    v176 = v175;
    if (v175 == nil) goto v28;
    v175 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v175, v176);

v28:
    v176 = stack[0];
    v175 = stack[-1];
    fn = elt(env, 8); /* convprc2 */
    v175 = (*qfn2(fn))(qenv(fn), v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    stack[-1] = v175;
    v175 = qvalue(elt(env, 4)); /* yy!! */
    stack[-3] = v175;
    v175 = stack[-1];
    if (!consp(v175)) goto v105;
    v176 = stack[-1];
    v175 = stack[-3];
    fn = elt(env, 9); /* difbf */
    v175 = (*qfn2(fn))(qenv(fn), v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    goto v68;

v68:
    stack[0] = v175;
    stack[-2] = stack[0];
    v175 = stack[-3];
    if (!consp(v175)) goto v179;
    stack[0] = elt(env, 3); /* !:rd!: */
    v175 = stack[-3];
    v175 = qcdr(v175);
    v175 = qcar(v175);
    v176 = negate(v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    v175 = stack[-3];
    v175 = qcdr(v175);
    v175 = qcdr(v175);
    v175 = list2star(stack[0], v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    goto v180;

v180:
    fn = elt(env, 10); /* rdzchk */
    v175 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    v176 = v175;
    v175 = v176;
    if (!(!consp(v175))) { popv(5); return onevalue(v176); }
    v175 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v175, v176);

v179:
    v175 = stack[-3];
    v175 = negate(v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    goto v180;

v105:
    stack[-2] = elt(env, 5); /* difference */
    v175 = stack[-1];
    stack[0] = Lmkquote(nil, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    v175 = stack[-3];
    v175 = Lmkquote(nil, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    v177 = list3(stack[-2], stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    v176 = qvalue(elt(env, 1)); /* nil */
    v175 = qvalue(elt(env, 6)); /* !*backtrace */
    fn = elt(env, 11); /* errorset */
    v175 = (*qfnn(fn))(qenv(fn), 3, v177, v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    v176 = v175;
    v175 = v176;
    if (!consp(v175)) goto v62;
    v175 = v176;
    v175 = qcdr(v175);
    if (!(v175 == nil)) goto v62;
    v175 = v176;
    v175 = qcar(v175);
    goto v68;

v62:
    fn = elt(env, 12); /* rndbfon */
    v175 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    v175 = stack[-1];
    v175 = Lfloatp(nil, v175);
    env = stack[-4];
    if (v175 == nil) goto v181;
    v175 = stack[-1];
    fn = elt(env, 13); /* fl2bf */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    stack[0] = v175;
    goto v182;

v182:
    stack[-1] = stack[0];
    v175 = stack[-3];
    v175 = Lfloatp(nil, v175);
    env = stack[-4];
    if (v175 == nil) goto v183;
    v175 = stack[-3];
    fn = elt(env, 13); /* fl2bf */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    goto v52;

v52:
    stack[-3] = v175;
    fn = elt(env, 9); /* difbf */
    v175 = (*qfn2(fn))(qenv(fn), stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    goto v68;

v183:
    v175 = stack[-3];
    if (!consp(v175)) goto v51;
    v175 = stack[-3];
    goto v152;

v152:
    fn = elt(env, 14); /* csl_normbf */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    goto v52;

v51:
    v175 = stack[-3];
    v175 = integerp(v175);
    if (v175 == nil) goto v184;
    v177 = elt(env, 3); /* !:rd!: */
    v176 = stack[-3];
    v175 = (Lisp_Object)1; /* 0 */
    v175 = list2star(v177, v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    goto v152;

v184:
    v175 = stack[-3];
    fn = elt(env, 15); /* read!:num */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    goto v152;

v181:
    v175 = stack[-1];
    if (!consp(v175)) goto v185;
    v175 = stack[-1];
    goto v186;

v186:
    fn = elt(env, 14); /* csl_normbf */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    stack[0] = v175;
    goto v182;

v185:
    v175 = stack[-1];
    v175 = integerp(v175);
    if (v175 == nil) goto v153;
    v177 = elt(env, 3); /* !:rd!: */
    v176 = stack[-1];
    v175 = (Lisp_Object)1; /* 0 */
    v175 = list2star(v177, v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    goto v186;

v153:
    v175 = stack[-1];
    fn = elt(env, 15); /* read!:num */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-4];
    goto v186;
/* error exit handlers */
v178:
    popv(5);
    return nil;
}



/* Code for physoptimes */

static Lisp_Object CC_physoptimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v178;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physoptimes");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    stack[-2] = nil;
    v178 = qvalue(elt(env, 1)); /* tstack!* */
    v158 = (Lisp_Object)1; /* 0 */
    if (!(v178 == v158)) goto v38;
    v158 = qvalue(elt(env, 2)); /* mul!* */
    if (v158 == nil) goto v38;
    v158 = qvalue(elt(env, 2)); /* mul!* */
    stack[-2] = v158;
    v158 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 2)) = v158; /* mul!* */
    goto v38;

v38:
    v158 = qvalue(elt(env, 1)); /* tstack!* */
    v158 = add1(v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    qvalue(elt(env, 1)) = v158; /* tstack!* */
    v158 = stack[0];
    v158 = qcar(v158);
    fn = elt(env, 5); /* physopsim!* */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    stack[-6] = v158;
    v158 = stack[0];
    v158 = qcdr(v158);
    stack[-1] = v158;
    goto v20;

v20:
    v158 = stack[-1];
    if (v158 == nil) goto v136;
    v158 = stack[-1];
    v158 = qcar(v158);
    fn = elt(env, 5); /* physopsim!* */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    stack[-5] = v158;
    v158 = stack[-6];
    fn = elt(env, 6); /* getphystype */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    stack[-4] = v158;
    v158 = stack[-5];
    fn = elt(env, 6); /* getphystype */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    stack[-3] = v158;
    v158 = stack[-4];
    if (v158 == nil) goto v95;
    v158 = stack[-3];
    if (v158 == nil) goto v202;
    v158 = stack[-6];
    fn = elt(env, 7); /* physopaeval */
    stack[0] = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    v158 = stack[-5];
    fn = elt(env, 7); /* physopaeval */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    fn = elt(env, 8); /* physopordchk */
    v158 = (*qfn2(fn))(qenv(fn), stack[0], v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    if (v158 == nil) goto v165;
    v178 = stack[-4];
    v158 = stack[-3];
    if (!(equal(v178, v158))) goto v165;
    v178 = stack[-4];
    v158 = elt(env, 4); /* scalar */
    if (!(v178 == v158)) goto v165;
    v158 = stack[-6];
    fn = elt(env, 9); /* physop2sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    v158 = stack[-5];
    fn = elt(env, 9); /* physop2sq */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    fn = elt(env, 10); /* multsq */
    v158 = (*qfn2(fn))(qenv(fn), stack[0], v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    fn = elt(env, 11); /* mk!*sq */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    stack[-6] = v158;
    goto v85;

v85:
    v158 = stack[-1];
    v158 = qcdr(v158);
    stack[-1] = v158;
    goto v20;

v165:
    v178 = stack[-6];
    v158 = stack[-5];
    fn = elt(env, 12); /* multopop!* */
    v158 = (*qfn2(fn))(qenv(fn), v178, v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    stack[-6] = v158;
    goto v85;

v202:
    v158 = stack[-5];
    v158 = (Lisp_Object)zerop(v158);
    v158 = v158 ? lisp_true : nil;
    env = stack[-7];
    if (v158 == nil) goto v59;
    v178 = qvalue(elt(env, 3)); /* nil */
    v158 = (Lisp_Object)17; /* 1 */
    v158 = cons(v178, v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    fn = elt(env, 11); /* mk!*sq */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    goto v203;

v203:
    stack[-6] = v158;
    goto v85;

v59:
    v158 = stack[-5];
    v158 = Lonep(nil, v158);
    env = stack[-7];
    if (v158 == nil) goto v153;
    v158 = stack[-6];
    fn = elt(env, 9); /* physop2sq */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    fn = elt(env, 11); /* mk!*sq */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    goto v203;

v153:
    v158 = stack[-5];
    fn = elt(env, 9); /* physop2sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    v158 = stack[-6];
    fn = elt(env, 9); /* physop2sq */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    fn = elt(env, 10); /* multsq */
    v158 = (*qfn2(fn))(qenv(fn), stack[0], v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    fn = elt(env, 11); /* mk!*sq */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    goto v203;

v95:
    v158 = stack[-3];
    if (v158 == nil) goto v77;
    v158 = stack[-6];
    v158 = (Lisp_Object)zerop(v158);
    v158 = v158 ? lisp_true : nil;
    env = stack[-7];
    if (v158 == nil) goto v106;
    v178 = qvalue(elt(env, 3)); /* nil */
    v158 = (Lisp_Object)17; /* 1 */
    v158 = cons(v178, v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    fn = elt(env, 11); /* mk!*sq */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    stack[-6] = v158;
    goto v85;

v106:
    v158 = stack[-6];
    v158 = Lonep(nil, v158);
    env = stack[-7];
    if (v158 == nil) goto v109;
    v158 = stack[-5];
    fn = elt(env, 9); /* physop2sq */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    fn = elt(env, 11); /* mk!*sq */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    stack[-6] = v158;
    goto v85;

v109:
    v158 = stack[-6];
    fn = elt(env, 9); /* physop2sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    v158 = stack[-5];
    fn = elt(env, 9); /* physop2sq */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    fn = elt(env, 10); /* multsq */
    v158 = (*qfn2(fn))(qenv(fn), stack[0], v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    fn = elt(env, 11); /* mk!*sq */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    stack[-6] = v158;
    goto v85;

v77:
    v158 = stack[-6];
    fn = elt(env, 9); /* physop2sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    v158 = stack[-5];
    fn = elt(env, 9); /* physop2sq */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    fn = elt(env, 10); /* multsq */
    v158 = (*qfn2(fn))(qenv(fn), stack[0], v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    fn = elt(env, 11); /* mk!*sq */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    stack[-6] = v158;
    goto v85;

v136:
    v158 = qvalue(elt(env, 2)); /* mul!* */
    if (v158 == nil) goto v135;
    v178 = qvalue(elt(env, 1)); /* tstack!* */
    v158 = (Lisp_Object)17; /* 1 */
    v158 = (Lisp_Object)greaterp2(v178, v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    v158 = v158 ? lisp_true : nil;
    env = stack[-7];
    if (!(v158 == nil)) goto v135;
    v158 = qvalue(elt(env, 2)); /* mul!* */
    v178 = qcar(v158);
    v158 = stack[-6];
    v158 = Lapply1(nil, v178, v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    stack[-6] = v158;
    v158 = qvalue(elt(env, 2)); /* mul!* */
    v158 = qcdr(v158);
    qvalue(elt(env, 2)) = v158; /* mul!* */
    goto v136;

v135:
    v158 = qvalue(elt(env, 1)); /* tstack!* */
    v158 = sub1(v158);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    qvalue(elt(env, 1)) = v158; /* tstack!* */
    v178 = qvalue(elt(env, 1)); /* tstack!* */
    v158 = (Lisp_Object)1; /* 0 */
    if (!(v178 == v158)) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v158 = stack[-2];
    qvalue(elt(env, 2)) = v158; /* mul!* */
    { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
/* error exit handlers */
v201:
    popv(8);
    return nil;
}



/* Code for calc_atlas */

static Lisp_Object CC_calc_atlas(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v92, v138, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_atlas");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v1;
    v92 = v0;
/* end of prologue */
    v138 = v92;
    v15 = qcar(v138);
    v138 = v92;
    v138 = qcdr(v138);
    v138 = qcdr(v138);
    v138 = qcar(v138);
    v92 = qcdr(v92);
    v92 = qcar(v92);
    {
        fn = elt(env, 1); /* calc_map_2d */
        return (*qfnn(fn))(qenv(fn), 4, v15, v138, v92, v6);
    }
}



/* Code for gettype */

static Lisp_Object CC_gettype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gettype");
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
    v64 = stack[0];
    if (is_number(v64)) goto v41;
    v64 = stack[0];
    if (!(!consp(v64))) goto v34;
    v64 = stack[0];
    if (v64 == nil) goto v34;
    v64 = stack[0];
    if (!(symbolp(v64))) goto v34;
    v65 = stack[0];
    v64 = elt(env, 3); /* simpfn */
    v64 = get(v65, v64);
    env = stack[-1];
    if (v64 == nil) goto v205;
    v64 = elt(env, 4); /* operator */
    { popv(2); return onevalue(v64); }

v205:
    v65 = stack[0];
    v64 = elt(env, 5); /* avalue */
    v64 = get(v65, v64);
    env = stack[-1];
    if (v64 == nil) goto v29;
    v65 = stack[0];
    v64 = elt(env, 5); /* avalue */
    v64 = get(v65, v64);
    v64 = qcar(v64);
    { popv(2); return onevalue(v64); }

v29:
    v64 = stack[0];
    fn = elt(env, 12); /* getd */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-1];
    if (v64 == nil) goto v8;
    v64 = elt(env, 6); /* procedure */
    { popv(2); return onevalue(v64); }

v8:
    v64 = stack[0];
    v64 = Lsymbol_globalp(nil, v64);
    env = stack[-1];
    if (v64 == nil) goto v68;
    v64 = elt(env, 7); /* global */
    { popv(2); return onevalue(v64); }

v68:
    v64 = stack[0];
    v64 = Lsymbol_specialp(nil, v64);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-1];
    if (v64 == nil) goto v67;
    v64 = elt(env, 8); /* fluid */
    { popv(2); return onevalue(v64); }

v67:
    v65 = stack[0];
    v64 = elt(env, 9); /* parm */
    v64 = Lflagp(nil, v65, v64);
    env = stack[-1];
    if (v64 == nil) goto v105;
    v64 = elt(env, 10); /* parameter */
    { popv(2); return onevalue(v64); }

v105:
    v64 = stack[0];
    v65 = elt(env, 11); /* rtype */
    popv(2);
    return get(v64, v65);

v34:
    v64 = elt(env, 2); /* form */
    { popv(2); return onevalue(v64); }

v41:
    v64 = elt(env, 1); /* number */
    { popv(2); return onevalue(v64); }
/* error exit handlers */
v142:
    popv(2);
    return nil;
}



/* Code for subs2chk */

static Lisp_Object CC_subs2chk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v138, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2chk");
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
    v92 = qvalue(elt(env, 1)); /* subfg!* */
    if (v92 == nil) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v92 = stack[0];
    fn = elt(env, 2); /* subs2f */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v14;
    v15 = v92;
    v138 = qcdr(v92);
    v92 = (Lisp_Object)17; /* 1 */
    if (!(v138 == v92)) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v92 = v15;
    v92 = qcar(v92);
    stack[0] = v92;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
/* error exit handlers */
v14:
    popv(1);
    return nil;
}



/* Code for xremf */

static Lisp_Object MS_CDECL CC_xremf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v233, v234, v235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xremf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xremf");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v2;
    stack[-6] = v1;
    stack[-7] = v0;
/* end of prologue */
    stack[-1] = nil;
    v233 = (Lisp_Object)1; /* 0 */
    stack[-8] = v233;
    v233 = stack[-6];
    if (!consp(v233)) goto v16;
    v233 = stack[-6];
    v233 = qcar(v233);
    if (!consp(v233)) goto v16;
    v233 = stack[-7];
    fn = elt(env, 2); /* termsf */
    v233 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    stack[0] = v233;
    goto v87;

v87:
    v234 = stack[-5];
    v233 = (Lisp_Object)1; /* 0 */
    v233 = (Lisp_Object)lesseq2(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    v233 = v233 ? lisp_true : nil;
    env = stack[-9];
    if (v233 == nil) goto v86;
    v233 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v233); }

v86:
    v233 = stack[-7];
    if (!consp(v233)) goto v84;
    v233 = stack[-7];
    v233 = qcar(v233);
    if (!consp(v233)) goto v84;
    v233 = stack[-7];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v234 = qcar(v233);
    v233 = stack[-6];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcar(v233);
    if (v234 == v233) goto v62;
    v233 = stack[-7];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v234 = qcar(v233);
    v233 = stack[-6];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcar(v233);
    fn = elt(env, 3); /* ordop */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    if (v233 == nil) goto v237;
    v234 = stack[-5];
    v233 = stack[-8];
    v233 = plus2(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    stack[-5] = v233;
    v233 = stack[-7];
    v233 = qcar(v233);
    v235 = qcdr(v233);
    v234 = stack[-6];
    v233 = stack[-5];
    v233 = CC_xremf(env, 3, v235, v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    stack[-3] = v233;
    v233 = stack[-3];
    if (v233 == nil) goto v238;
    v233 = stack[-7];
    v233 = qcar(v233);
    v234 = qcar(v233);
    v233 = (Lisp_Object)17; /* 1 */
    v233 = cons(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    v234 = ncons(v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    v233 = stack[-3];
    v233 = qcar(v233);
    fn = elt(env, 4); /* multf */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    fn = elt(env, 5); /* addf */
    v233 = (*qfn2(fn))(qenv(fn), stack[-1], v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    stack[-1] = v233;
    v233 = stack[-1];
    fn = elt(env, 2); /* termsf */
    v233 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    stack[-8] = v233;
    v234 = stack[-5];
    v233 = stack[-8];
    v233 = difference2(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    stack[-5] = v233;
    v233 = stack[-7];
    v233 = qcdr(v233);
    stack[-7] = v233;
    goto v87;

v238:
    v233 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v233); }

v237:
    v234 = stack[-1];
    v233 = stack[-7];
    fn = elt(env, 5); /* addf */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    popv(10);
    return ncons(v233);

v62:
    v233 = stack[-7];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v234 = qcdr(v233);
    v233 = stack[-6];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcdr(v233);
    v234 = difference2(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    stack[-4] = v234;
    v233 = (Lisp_Object)1; /* 0 */
    v233 = (Lisp_Object)lessp2(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    v233 = v233 ? lisp_true : nil;
    env = stack[-9];
    if (v233 == nil) goto v186;
    v234 = stack[-1];
    v233 = stack[-7];
    fn = elt(env, 5); /* addf */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    popv(10);
    return ncons(v233);

v186:
    v233 = stack[-7];
    v233 = qcar(v233);
    v234 = qcdr(v233);
    v233 = stack[-6];
    v233 = qcar(v233);
    v233 = qcdr(v233);
    fn = elt(env, 6); /* qremf */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    stack[-3] = v233;
    v233 = stack[-7];
    v233 = qcar(v233);
    v234 = qcar(v233);
    v233 = (Lisp_Object)17; /* 1 */
    v233 = cons(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    v234 = ncons(v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    v233 = stack[-3];
    v233 = qcdr(v233);
    fn = elt(env, 4); /* multf */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    stack[-2] = v233;
    v234 = stack[-5];
    v233 = stack[-8];
    v233 = plus2(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    stack[-5] = v233;
    v234 = stack[-1];
    v233 = stack[-2];
    fn = elt(env, 5); /* addf */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    stack[-1] = v233;
    v233 = stack[-1];
    fn = elt(env, 2); /* termsf */
    v233 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    stack[-8] = v233;
    v234 = stack[-5];
    v233 = stack[-8];
    v234 = difference2(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    v233 = stack[0];
    v233 = plus2(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    stack[-5] = v233;
    v233 = stack[-3];
    v233 = qcar(v233);
    if (v233 == nil) goto v192;
    stack[0] = stack[-7];
    v234 = stack[-4];
    v233 = (Lisp_Object)1; /* 0 */
    if (v234 == v233) goto v189;
    v233 = stack[-7];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v235 = qcar(v233);
    v234 = stack[-4];
    v233 = (Lisp_Object)17; /* 1 */
    v233 = acons(v235, v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    v234 = ncons(v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    v233 = stack[-6];
    fn = elt(env, 4); /* multf */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    stack[-4] = v233;
    goto v125;

v125:
    v233 = stack[-3];
    v233 = qcar(v233);
    fn = elt(env, 7); /* negf */
    v233 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    fn = elt(env, 4); /* multf */
    v233 = (*qfn2(fn))(qenv(fn), stack[-4], v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    fn = elt(env, 5); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    v233 = stack[-2];
    fn = elt(env, 7); /* negf */
    v233 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    fn = elt(env, 5); /* addf */
    v233 = (*qfn2(fn))(qenv(fn), stack[0], v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    goto v239;

v239:
    stack[-7] = v233;
    v233 = stack[-7];
    fn = elt(env, 2); /* termsf */
    v233 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    stack[0] = v233;
    v234 = stack[-5];
    v233 = stack[0];
    v233 = difference2(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-9];
    stack[-5] = v233;
    goto v87;

v189:
    v233 = stack[-6];
    stack[-4] = v233;
    goto v125;

v192:
    v233 = stack[-7];
    v233 = qcdr(v233);
    goto v239;

v84:
    v234 = stack[-1];
    v233 = stack[-7];
    fn = elt(env, 5); /* addf */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    popv(10);
    return ncons(v233);

v16:
    v234 = stack[-7];
    v233 = stack[-6];
    fn = elt(env, 8); /* qremd */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v236;
    v233 = qcdr(v233);
    popv(10);
    return ncons(v233);
/* error exit handlers */
v236:
    popv(10);
    return nil;
}



/* Code for even_action_term */

static Lisp_Object MS_CDECL CC_even_action_term(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v24, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v199, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "even_action_term");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for even_action_term");
#endif
    if (stack >= stacklimit)
    {
        push4(v24,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v24);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v24;
    stack[-3] = v2;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = stack[-5];
    v199 = stack[-4];
    stack[-1] = qcar(v199);
    stack[0] = stack[-3];
    v94 = stack[-2];
    v199 = stack[-4];
    v199 = qcdr(v199);
    fn = elt(env, 1); /* multf */
    v94 = (*qfn2(fn))(qenv(fn), v94, v199);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    v199 = (Lisp_Object)17; /* 1 */
    v199 = cons(v94, v199);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    fn = elt(env, 2); /* even_action_pow */
    stack[-1] = (*qfnn(fn))(qenv(fn), 4, stack[-6], stack[-1], stack[0], v199);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    v199 = stack[-4];
    stack[0] = qcdr(v199);
    v199 = stack[-4];
    v94 = qcar(v199);
    v199 = (Lisp_Object)17; /* 1 */
    v199 = cons(v94, v199);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    v199 = ncons(v199);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    fn = elt(env, 1); /* multf */
    v199 = (*qfn2(fn))(qenv(fn), stack[-2], v199);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    fn = elt(env, 3); /* even_action_sf */
    v199 = (*qfnn(fn))(qenv(fn), 4, stack[-5], stack[0], stack[-3], v199);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    {
        Lisp_Object v204 = stack[-1];
        popv(8);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v204, v199);
    }
/* error exit handlers */
v83:
    popv(8);
    return nil;
}



/* Code for maxfrom1 */

static Lisp_Object MS_CDECL CC_maxfrom1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "maxfrom1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxfrom1");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v12:
    v3 = stack[-2];
    if (v3 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v3 = stack[-2];
    v3 = qcar(v3);
    v96 = qcar(v3);
    v3 = stack[-1];
    fn = elt(env, 1); /* pnth */
    v3 = (*qfn2(fn))(qenv(fn), v96, v3);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    v96 = qcar(v3);
    v3 = stack[0];
    fn = elt(env, 2); /* max */
    v3 = (*qfn2(fn))(qenv(fn), v96, v3);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    stack[0] = v3;
    v3 = stack[-2];
    v3 = qcdr(v3);
    stack[-2] = v3;
    goto v12;
/* error exit handlers */
v86:
    popv(4);
    return nil;
}



/* Code for mk!+scal!+mult!+mat */

static Lisp_Object CC_mkLscalLmultLmat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164, v244;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+scal+mult+mat");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-8] = v0;
/* end of prologue */
    v164 = stack[0];
    fn = elt(env, 6); /* matrix!+p */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-10];
    if (!(v164 == nil)) goto v136;
    v164 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v164 == nil)) goto v30;
    v164 = elt(env, 2); /* "no matrix in add" */
    fn = elt(env, 7); /* lprie */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-10];
    goto v30;

v30:
    v164 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-10];
    goto v136;

v136:
    v164 = stack[0];
    stack[-9] = v164;
    v164 = stack[-9];
    if (v164 == nil) goto v4;
    v164 = stack[-9];
    v164 = qcar(v164);
    stack[-4] = v164;
    v164 = stack[-4];
    if (v164 == nil) goto v11;
    v164 = stack[-4];
    v164 = qcar(v164);
    v244 = stack[-8];
    fn = elt(env, 8); /* multsq */
    v164 = (*qfn2(fn))(qenv(fn), v244, v164);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-10];
    v244 = v164;
    v164 = qvalue(elt(env, 4)); /* t */
    stack[0] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v164; /* !*sub2 */
    v164 = v244;
    fn = elt(env, 9); /* subs2 */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-10];
    v244 = v164;
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    v164 = v244;
    v164 = ncons(v164);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-10];
    stack[-2] = v164;
    stack[-3] = v164;
    goto v7;

v7:
    v164 = stack[-4];
    v164 = qcdr(v164);
    stack[-4] = v164;
    v164 = stack[-4];
    if (v164 == nil) goto v105;
    stack[-1] = stack[-2];
    v164 = stack[-4];
    v164 = qcar(v164);
    v244 = stack[-8];
    fn = elt(env, 8); /* multsq */
    v164 = (*qfn2(fn))(qenv(fn), v244, v164);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-10];
    v244 = v164;
    v164 = qvalue(elt(env, 4)); /* t */
    stack[0] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v164; /* !*sub2 */
    v164 = v244;
    fn = elt(env, 9); /* subs2 */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-10];
    v244 = v164;
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    v164 = v244;
    v164 = ncons(v164);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-10];
    v164 = Lrplacd(nil, stack[-1], v164);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-10];
    v164 = stack[-2];
    v164 = qcdr(v164);
    stack[-2] = v164;
    goto v7;

v105:
    v164 = stack[-3];
    goto v246;

v246:
    v164 = ncons(v164);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-10];
    stack[-6] = v164;
    stack[-7] = v164;
    goto v88;

v88:
    v164 = stack[-9];
    v164 = qcdr(v164);
    stack[-9] = v164;
    v164 = stack[-9];
    if (v164 == nil) { Lisp_Object res = stack[-7]; popv(11); return onevalue(res); }
    stack[-5] = stack[-6];
    v164 = stack[-9];
    v164 = qcar(v164);
    stack[-4] = v164;
    v164 = stack[-4];
    if (v164 == nil) goto v247;
    v164 = stack[-4];
    v164 = qcar(v164);
    v244 = stack[-8];
    fn = elt(env, 8); /* multsq */
    v164 = (*qfn2(fn))(qenv(fn), v244, v164);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-10];
    v244 = v164;
    v164 = qvalue(elt(env, 4)); /* t */
    stack[0] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v164; /* !*sub2 */
    v164 = v244;
    fn = elt(env, 9); /* subs2 */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-10];
    v244 = v164;
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    v164 = v244;
    v164 = ncons(v164);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-10];
    stack[-2] = v164;
    stack[-3] = v164;
    goto v248;

v248:
    v164 = stack[-4];
    v164 = qcdr(v164);
    stack[-4] = v164;
    v164 = stack[-4];
    if (v164 == nil) goto v249;
    stack[-1] = stack[-2];
    v164 = stack[-4];
    v164 = qcar(v164);
    v244 = stack[-8];
    fn = elt(env, 8); /* multsq */
    v164 = (*qfn2(fn))(qenv(fn), v244, v164);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-10];
    v244 = v164;
    v164 = qvalue(elt(env, 4)); /* t */
    stack[0] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v164; /* !*sub2 */
    v164 = v244;
    fn = elt(env, 9); /* subs2 */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-10];
    v244 = v164;
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    v164 = v244;
    v164 = ncons(v164);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-10];
    v164 = Lrplacd(nil, stack[-1], v164);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-10];
    v164 = stack[-2];
    v164 = qcdr(v164);
    stack[-2] = v164;
    goto v248;

v249:
    v164 = stack[-3];
    goto v250;

v250:
    v164 = ncons(v164);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-10];
    v164 = Lrplacd(nil, stack[-5], v164);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-10];
    v164 = stack[-6];
    v164 = qcdr(v164);
    stack[-6] = v164;
    goto v88;

v247:
    v164 = qvalue(elt(env, 3)); /* nil */
    goto v250;

v11:
    v164 = qvalue(elt(env, 3)); /* nil */
    goto v246;

v4:
    v164 = qvalue(elt(env, 3)); /* nil */
    { popv(11); return onevalue(v164); }
/* error exit handlers */
v126:
    env = stack[-10];
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    popv(11);
    return nil;
v125:
    env = stack[-10];
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    popv(11);
    return nil;
v75:
    env = stack[-10];
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    popv(11);
    return nil;
v245:
    env = stack[-10];
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    popv(11);
    return nil;
v224:
    popv(11);
    return nil;
}



/* Code for mksp!* */

static Lisp_Object CC_mkspH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksp*");
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
    v98 = stack[-1];
    if (v98 == nil) goto v251;
    v98 = stack[-1];
    fn = elt(env, 2); /* kernlp */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    if (!(v98 == nil)) goto v251;
    v98 = stack[-1];
    fn = elt(env, 3); /* minusf */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    if (v98 == nil) goto v36;
    v98 = qvalue(elt(env, 1)); /* t */
    stack[-2] = v98;
    v98 = stack[-1];
    fn = elt(env, 4); /* negf */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    stack[-1] = v98;
    goto v36;

v36:
    v98 = stack[-1];
    fn = elt(env, 5); /* fkern */
    v99 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    v98 = stack[0];
    fn = elt(env, 6); /* getpower */
    v99 = (*qfn2(fn))(qenv(fn), v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    v98 = (Lisp_Object)17; /* 1 */
    v98 = cons(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    stack[-1] = v98;
    v98 = stack[-2];
    if (v98 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v98 = stack[0];
    v98 = Levenp(nil, v98);
    env = stack[-3];
    if (!(v98 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v98 = stack[-1];
    {
        popv(4);
        fn = elt(env, 4); /* negf */
        return (*qfn1(fn))(qenv(fn), v98);
    }

v251:
    v99 = stack[-1];
    v98 = stack[0];
    {
        popv(4);
        fn = elt(env, 7); /* exptf */
        return (*qfn2(fn))(qenv(fn), v99, v98);
    }
/* error exit handlers */
v23:
    popv(4);
    return nil;
}



/* Code for pasf_dt */

static Lisp_Object CC_pasf_dt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v267, v217, v215, v216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_dt");
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
    v217 = stack[0];
    v267 = elt(env, 1); /* true */
    if (v217 == v267) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v217 = stack[0];
    v267 = elt(env, 2); /* false */
    if (v217 == v267) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v267 = stack[0];
    v267 = qcdr(v267);
    v267 = qcar(v267);
    fn = elt(env, 17); /* pasf_pdp */
    v267 = (*qfn1(fn))(qenv(fn), v267);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-1];
    v216 = v267;
    v217 = stack[0];
    v267 = elt(env, 1); /* true */
    if (v217 == v267) goto v19;
    v217 = stack[0];
    v267 = elt(env, 2); /* false */
    if (v217 == v267) goto v19;
    v267 = stack[0];
    v267 = qcar(v267);
    v267 = Lconsp(nil, v267);
    env = stack[-1];
    if (v267 == nil) goto v97;
    v267 = stack[0];
    v267 = qcar(v267);
    v267 = qcar(v267);
    goto v70;

v70:
    v215 = v267;
    v217 = v216;
    v267 = elt(env, 3); /* pdef */
    if (!(v217 == v267)) goto v63;
    v217 = v215;
    v267 = elt(env, 4); /* (equal lessp leq) */
    v267 = Lmemq(nil, v217, v267);
    if (v267 == nil) goto v63;
    v267 = elt(env, 2); /* false */
    { popv(2); return onevalue(v267); }

v63:
    v217 = v216;
    v267 = elt(env, 5); /* ndef */
    if (!(v217 == v267)) goto v203;
    v217 = v215;
    v267 = elt(env, 6); /* (equal greaterp geq) */
    v267 = Lmemq(nil, v217, v267);
    if (v267 == nil) goto v203;
    v267 = elt(env, 2); /* false */
    { popv(2); return onevalue(v267); }

v203:
    v217 = v216;
    v267 = elt(env, 3); /* pdef */
    if (!(v217 == v267)) goto v174;
    v217 = v215;
    v267 = elt(env, 7); /* (neq greaterp geq) */
    v267 = Lmemq(nil, v217, v267);
    if (v267 == nil) goto v174;
    v267 = elt(env, 1); /* true */
    { popv(2); return onevalue(v267); }

v174:
    v217 = v216;
    v267 = elt(env, 5); /* ndef */
    if (!(v217 == v267)) goto v50;
    v217 = v215;
    v267 = elt(env, 8); /* (neq lessp leq) */
    v267 = Lmemq(nil, v217, v267);
    if (v267 == nil) goto v50;
    v267 = elt(env, 1); /* true */
    { popv(2); return onevalue(v267); }

v50:
    v217 = v216;
    v267 = elt(env, 9); /* psdef */
    if (!(v217 == v267)) goto v46;
    v217 = v215;
    v267 = elt(env, 10); /* lessp */
    if (!(v217 == v267)) goto v46;
    v267 = elt(env, 2); /* false */
    { popv(2); return onevalue(v267); }

v46:
    v217 = v216;
    v267 = elt(env, 11); /* nsdef */
    if (!(v217 == v267)) goto v42;
    v217 = v215;
    v267 = elt(env, 12); /* greaterp */
    if (!(v217 == v267)) goto v42;
    v267 = elt(env, 2); /* false */
    { popv(2); return onevalue(v267); }

v42:
    v217 = v216;
    v267 = elt(env, 9); /* psdef */
    if (!(v217 == v267)) goto v228;
    v217 = v215;
    v267 = elt(env, 13); /* geq */
    if (!(v217 == v267)) goto v228;
    v267 = elt(env, 1); /* true */
    { popv(2); return onevalue(v267); }

v228:
    v217 = v216;
    v267 = elt(env, 11); /* nsdef */
    if (!(v217 == v267)) goto v178;
    v217 = v215;
    v267 = elt(env, 14); /* leq */
    if (!(v217 == v267)) goto v178;
    v267 = elt(env, 1); /* true */
    { popv(2); return onevalue(v267); }

v178:
    v217 = v216;
    v267 = elt(env, 9); /* psdef */
    if (!(v217 == v267)) goto v269;
    v217 = v215;
    v267 = elt(env, 15); /* neq */
    if (!(v217 == v267)) goto v269;
    v217 = elt(env, 12); /* greaterp */
    v267 = stack[0];
    v267 = qcdr(v267);
    v267 = qcar(v267);
    v215 = qvalue(elt(env, 16)); /* nil */
    popv(2);
    return list3(v217, v267, v215);

v269:
    v217 = v216;
    v267 = elt(env, 11); /* nsdef */
    if (!(v217 == v267)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v217 = v215;
    v267 = elt(env, 15); /* neq */
    if (!(v217 == v267)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v217 = elt(env, 10); /* lessp */
    v267 = stack[0];
    v267 = qcdr(v267);
    v267 = qcar(v267);
    v215 = qvalue(elt(env, 16)); /* nil */
    popv(2);
    return list3(v217, v267, v215);

v97:
    v267 = stack[0];
    v267 = qcar(v267);
    goto v70;

v19:
    v267 = stack[0];
    goto v70;
/* error exit handlers */
v268:
    popv(2);
    return nil;
}



/* Code for dvfsf_smupdknowl */

static Lisp_Object MS_CDECL CC_dvfsf_smupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v24, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v240, v87, v27, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "dvfsf_smupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_smupdknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v240 = v24;
    v87 = v2;
    v27 = v1;
    v28 = v0;
/* end of prologue */
    v86 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v86 == nil) goto v16;
    v86 = v28;
    {
        fn = elt(env, 2); /* cl_susiupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v86, v27, v87, v240);
    }

v16:
    v86 = v28;
    {
        fn = elt(env, 3); /* cl_smupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v86, v27, v87, v240);
    }
}



/* Code for relnrd */

static Lisp_Object MS_CDECL CC_relnrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "relnrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for relnrd");
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
    fn = elt(env, 5); /* lex */
    v98 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    v98 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 6); /* compress!* */
    v99 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    v98 = qvalue(elt(env, 2)); /* rdreln!* */
    v99 = Lassoc(nil, v99, v98);
    v98 = v99;
    if (v99 == nil) goto v4;
    v99 = v98;
    v99 = qcdr(v99);
    v99 = qcar(v99);
    v98 = qcdr(v98);
    v98 = qcdr(v98);
    fn = elt(env, 7); /* apply */
    v98 = (*qfn2(fn))(qenv(fn), v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    stack[0] = v98;
    goto v246;

v246:
    v99 = stack[0];
    v98 = qvalue(elt(env, 3)); /* t */
    if (equal(v99, v98)) goto v28;
    v98 = stack[0];
    if (!(v98 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v98 = elt(env, 4); /* false */
    { popv(2); return onevalue(v98); }

v28:
    v98 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v98); }

v4:
    v98 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 6); /* compress!* */
    v99 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    v98 = (Lisp_Object)289; /* 18 */
    fn = elt(env, 8); /* errorml */
    v98 = (*qfn2(fn))(qenv(fn), v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    goto v246;
/* error exit handlers */
v103:
    popv(2);
    return nil;
}



/* Code for dm!-min */

static Lisp_Object CC_dmKmin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v21;
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
    v21 = stack[-1];
    v206 = stack[0];
    fn = elt(env, 1); /* dm!-gt */
    v206 = (*qfn2(fn))(qenv(fn), v21, v206);
    nil = C_nil;
    if (exception_pending()) goto v6;
    if (v206 == nil) { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v6:
    popv(2);
    return nil;
}



/* Code for oldmtch */

static Lisp_Object CC_oldmtch(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v66, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for oldmtch");
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
    stack[-3] = nil;
    v94 = stack[-2];
    v35 = qcdr(v94);
    v94 = stack[-1];
    v66 = qcar(v94);
    v94 = stack[-2];
    v94 = qcar(v94);
    fn = elt(env, 2); /* mcharg */
    v94 = (*qfnn(fn))(qenv(fn), 3, v35, v66, v94);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-4];
    stack[0] = v94;
    goto v6;

v6:
    v94 = stack[0];
    if (v94 == nil) goto v40;
    v94 = stack[-3];
    if (!(v94 == nil)) goto v40;
    v94 = stack[0];
    v66 = qcar(v94);
    v94 = stack[-1];
    v94 = qcdr(v94);
    v94 = qcar(v94);
    v94 = qcdr(v94);
    v94 = Lsubla(nil, v66, v94);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-4];
    fn = elt(env, 3); /* eval */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-4];
    if (v94 == nil) goto v96;
    v94 = stack[0];
    v66 = qcar(v94);
    v94 = stack[-1];
    v94 = qcdr(v94);
    v94 = qcdr(v94);
    v94 = qcar(v94);
    v94 = Lsubla(nil, v66, v94);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-4];
    goto v4;

v4:
    stack[-3] = v94;
    v94 = stack[0];
    v94 = qcdr(v94);
    stack[0] = v94;
    goto v6;

v96:
    v94 = nil;
    goto v4;

v40:
    v94 = stack[-3];
    if (v94 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    else { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v232:
    popv(5);
    return nil;
}



/* Code for gvar1 */

static Lisp_Object CC_gvar1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v58, v185, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gvar1");
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
/* copy arguments values to proper place */
    v58 = v1;
    v185 = v0;
/* end of prologue */

v91:
    v186 = v185;
    if (v186 == nil) { popv(1); return onevalue(v58); }
    v186 = v185;
    if (is_number(v186)) { popv(1); return onevalue(v58); }
    v79 = v185;
    v186 = elt(env, 1); /* i */
    if (!(v79 == v186)) goto v13;
    v186 = qvalue(elt(env, 2)); /* !*complex */
    if (!(v186 == nil)) { popv(1); return onevalue(v58); }

v13:
    v186 = v185;
    if (!consp(v186)) goto v19;
    v186 = v185;
    v79 = qcar(v186);
    v186 = elt(env, 3); /* dname */
    v186 = get(v79, v186);
    env = stack[0];
    if (!(v186 == nil)) { popv(1); return onevalue(v58); }
    v186 = v185;
    v79 = qcar(v186);
    v186 = elt(env, 4); /* (plus times expt difference minus) */
    v186 = Lmemq(nil, v79, v186);
    if (v186 == nil) goto v142;
    v186 = v185;
    v186 = qcdr(v186);
    {
        popv(1);
        fn = elt(env, 6); /* gvarlis1 */
        return (*qfn2(fn))(qenv(fn), v186, v58);
    }

v142:
    v186 = v185;
    v79 = qcar(v186);
    v186 = elt(env, 5); /* quotient */
    if (v79 == v186) goto v65;
    v79 = v185;
    v186 = v58;
    v186 = Lmember(nil, v79, v186);
    if (!(v186 == nil)) { popv(1); return onevalue(v58); }
    v186 = v185;
    popv(1);
    return cons(v186, v58);

v65:
    v186 = v185;
    v186 = qcdr(v186);
    v186 = qcar(v186);
    v185 = v186;
    goto v91;

v19:
    v79 = v185;
    v186 = v58;
    v186 = Lmember(nil, v79, v186);
    if (!(v186 == nil)) { popv(1); return onevalue(v58); }
    v186 = v185;
    popv(1);
    return cons(v186, v58);
}



/* Code for incident */

static Lisp_Object MS_CDECL CC_incident(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v26, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "incident");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for incident");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v2;
    stack[0] = v1;
    stack[-2] = v0;
/* end of prologue */

v270:
    v25 = stack[0];
    if (v25 == nil) goto v12;
    v85 = stack[-2];
    v25 = stack[0];
    v26 = qcar(v25);
    v25 = stack[-1];
    fn = elt(env, 2); /* incident1 */
    v25 = (*qfnn(fn))(qenv(fn), 3, v85, v26, v25);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    v26 = v25;
    v25 = v26;
    if (v25 == nil) goto v28;
    v25 = stack[0];
    v25 = qcdr(v25);
    popv(4);
    return cons(v26, v25);

v28:
    v25 = stack[0];
    stack[0] = qcdr(v25);
    v25 = stack[-1];
    v25 = add1(v25);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    stack[-1] = v25;
    goto v270;

v12:
    v25 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v25); }
/* error exit handlers */
v97:
    popv(4);
    return nil;
}



/* Code for formsetq0 */

static Lisp_Object MS_CDECL CC_formsetq0(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v322, v323, v324, v325;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formsetq0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formsetq0");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v2;
    stack[-4] = v1;
    stack[0] = v0;
/* end of prologue */
    stack[-1] = nil;
    v322 = stack[0];
    v322 = qcdr(v322);
    stack[0] = v322;
    v322 = qcar(v322);
    stack[-2] = v322;
    if (!(symbolp(v322))) goto v29;
    v323 = stack[-2];
    v322 = stack[-4];
    v322 = Latsoc(nil, v323, v322);
    stack[-1] = v322;
    goto v29;

v29:
    v322 = stack[0];
    v322 = qcdr(v322);
    v323 = qcar(v322);
    v322 = elt(env, 1); /* quote */
    if (!consp(v323)) goto v10;
    v323 = qcar(v323);
    if (!(v323 == v322)) goto v10;
    v322 = elt(env, 2); /* symbolic */
    stack[-3] = v322;
    goto v10;

v10:
    v322 = stack[0];
    v322 = qcdr(v322);
    v324 = qcar(v322);
    v323 = stack[-4];
    v322 = stack[-3];
    fn = elt(env, 27); /* form1 */
    v325 = (*qfnn(fn))(qenv(fn), 3, v324, v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    v324 = stack[-4];
    v323 = elt(env, 2); /* symbolic */
    v322 = stack[-3];
    fn = elt(env, 28); /* convertmode1 */
    v322 = (*qfnn(fn))(qenv(fn), 4, v325, v324, v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    stack[-5] = v322;
    v322 = stack[-2];
    if (!consp(v322)) goto v104;
    v322 = stack[-2];
    v322 = qcar(v322);
    if (symbolp(v322)) goto v89;
    v323 = stack[-2];
    v322 = elt(env, 3); /* "assignment" */
    {
        popv(7);
        fn = elt(env, 29); /* typerr */
        return (*qfn2(fn))(qenv(fn), v323, v322);
    }

v89:
    v323 = stack[-2];
    v322 = stack[-3];
    fn = elt(env, 30); /* macrochk */
    v322 = (*qfn2(fn))(qenv(fn), v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    stack[-2] = v322;
    if (!consp(v322)) goto v141;
    v322 = stack[-2];
    v323 = qcar(v322);
    v322 = elt(env, 4); /* rtype */
    v323 = get(v323, v322);
    env = stack[-6];
    v322 = elt(env, 5); /* array */
    if (!(v323 == v322)) goto v141;
    stack[0] = elt(env, 6); /* setel */
    v324 = stack[-2];
    v323 = stack[-4];
    v322 = stack[-3];
    fn = elt(env, 31); /* intargfn */
    v323 = (*qfnn(fn))(qenv(fn), 3, v324, v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    v322 = stack[-5];
    {
        Lisp_Object v327 = stack[0];
        popv(7);
        return list3(v327, v323, v322);
    }

v141:
    v322 = stack[-2];
    if (!consp(v322)) goto v45;
    v322 = stack[-2];
    v322 = qcdr(v322);
    if (v322 == nil) goto v45;
    v322 = stack[-2];
    v323 = qcar(v322);
    v322 = elt(env, 4); /* rtype */
    v323 = get(v323, v322);
    env = stack[-6];
    v322 = elt(env, 7); /* vector */
    if (v323 == v322) goto v172;
    v322 = stack[-2];
    v322 = qcdr(v322);
    v322 = qcar(v322);
    v322 = Lsimple_vectorp(nil, v322);
    env = stack[-6];
    if (!(v322 == nil)) goto v172;
    v322 = stack[-2];
    v322 = qcdr(v322);
    v323 = qcar(v322);
    v322 = elt(env, 8); /* vecfn */
    v322 = Lflagpcar(nil, v323, v322);
    env = stack[-6];
    if (!(v322 == nil)) goto v172;

v45:
    v323 = stack[-2];
    v322 = elt(env, 9); /* part */
    if (!consp(v323)) goto v266;
    v323 = qcar(v323);
    if (!(v323 == v322)) goto v266;
    stack[-1] = elt(env, 10); /* list */
    v322 = elt(env, 11); /* setpart!* */
    stack[0] = Lmkquote(nil, v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    v322 = stack[-2];
    v324 = qcdr(v322);
    v323 = stack[-4];
    v322 = stack[-3];
    fn = elt(env, 32); /* formlis */
    v322 = (*qfnn(fn))(qenv(fn), 3, v324, v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    stack[0] = list2star(stack[-1], stack[0], v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    v322 = stack[-5];
    v322 = ncons(v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    {
        Lisp_Object v328 = stack[0];
        popv(7);
        return Lnconc(nil, v328, v322);
    }

v266:
    v322 = stack[-2];
    if (!consp(v322)) goto v329;
    v322 = stack[-2];
    v323 = qcar(v322);
    v322 = elt(env, 12); /* setqfn */
    v322 = get(v323, v322);
    env = stack[-6];
    stack[-1] = v322;
    if (v322 == nil) goto v329;
    v322 = stack[-2];
    v323 = qcdr(v322);
    v322 = stack[0];
    v322 = qcdr(v322);
    v323 = Lappend(nil, v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    v322 = qvalue(elt(env, 13)); /* nil */
    fn = elt(env, 33); /* applsmacro */
    v324 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    v323 = stack[-4];
    v322 = stack[-3];
    {
        popv(7);
        fn = elt(env, 27); /* form1 */
        return (*qfnn(fn))(qenv(fn), 3, v324, v323, v322);
    }

v329:
    v323 = stack[-3];
    v322 = elt(env, 2); /* symbolic */
    if (!(v323 == v322)) goto v330;
    v322 = qvalue(elt(env, 14)); /* !*rlisp88 */
    if (!(v322 == nil)) goto v331;
    v323 = stack[-2];
    v322 = elt(env, 15); /* structfetch */
    if (!consp(v323)) goto v330;
    v323 = qcar(v323);
    if (!(v323 == v322)) goto v330;

v331:
    stack[0] = elt(env, 16); /* rsetf */
    v324 = stack[-2];
    v323 = stack[-4];
    v322 = stack[-3];
    fn = elt(env, 27); /* form1 */
    v323 = (*qfnn(fn))(qenv(fn), 3, v324, v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    v322 = stack[-5];
    {
        Lisp_Object v332 = stack[0];
        popv(7);
        return list3(v332, v323, v322);
    }

v330:
    stack[0] = elt(env, 17); /* setk */
    v324 = stack[-2];
    v323 = stack[-4];
    v322 = elt(env, 18); /* algebraic */
    fn = elt(env, 27); /* form1 */
    v323 = (*qfnn(fn))(qenv(fn), 3, v324, v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    v322 = stack[-5];
    {
        Lisp_Object v333 = stack[0];
        popv(7);
        return list3(v333, v323, v322);
    }

v172:
    v324 = stack[0];
    v323 = stack[-4];
    v322 = stack[-3];
    {
        popv(7);
        fn = elt(env, 34); /* putvect */
        return (*qfnn(fn))(qenv(fn), 3, v324, v323, v322);
    }

v104:
    v322 = stack[-2];
    if (symbolp(v322)) goto v334;
    v323 = stack[-2];
    v322 = elt(env, 3); /* "assignment" */
    {
        popv(7);
        fn = elt(env, 29); /* typerr */
        return (*qfn2(fn))(qenv(fn), v323, v322);
    }

v334:
    v323 = stack[-2];
    v322 = elt(env, 19); /* reserved */
    v322 = Lflagp(nil, v323, v322);
    env = stack[-6];
    if (v322 == nil) goto v335;
    v323 = stack[-2];
    v322 = stack[-4];
    v322 = Latsoc(nil, v323, v322);
    if (!(v322 == nil)) goto v335;
    v323 = stack[-2];
    v322 = elt(env, 20); /* "is a reserved identifier" */
    v322 = list2(v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    v323 = v322;
    v322 = v323;
    qvalue(elt(env, 21)) = v322; /* errmsg!* */
    v322 = qvalue(elt(env, 22)); /* !*protfg */
    if (!(v322 == nil)) goto v336;
    v322 = v323;
    fn = elt(env, 35); /* lprie */
    v322 = (*qfn1(fn))(qenv(fn), v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    goto v336;

v336:
    v322 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v326;
    v322 = nil;
    { popv(7); return onevalue(v322); }

v335:
    v323 = stack[-2];
    v322 = elt(env, 23); /* share */
    v322 = Lflagp(nil, v323, v322);
    env = stack[-6];
    if (v322 == nil) goto v337;
    v323 = stack[-2];
    v322 = stack[-4];
    fn = elt(env, 36); /* symbid */
    stack[0] = (*qfn2(fn))(qenv(fn), v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    v324 = elt(env, 24); /* progn */
    v323 = elt(env, 25); /* (setq alglist!* (cons nil nil)) */
    v322 = stack[-5];
    v322 = list3(v324, v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    {
        Lisp_Object v338 = stack[0];
        popv(7);
        fn = elt(env, 37); /* mksetq */
        return (*qfn2(fn))(qenv(fn), v338, v322);
    }

v337:
    v323 = stack[-3];
    v322 = elt(env, 2); /* symbolic */
    if (v323 == v322) goto v339;
    v322 = stack[-1];
    if (!(v322 == nil)) goto v339;
    v323 = stack[-5];
    v322 = elt(env, 1); /* quote */
    if (!consp(v323)) goto v340;
    v323 = qcar(v323);
    if (!(v323 == v322)) goto v340;

v339:
    v323 = stack[-2];
    v322 = stack[-4];
    fn = elt(env, 36); /* symbid */
    v323 = (*qfn2(fn))(qenv(fn), v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-6];
    v322 = stack[-5];
    {
        popv(7);
        fn = elt(env, 37); /* mksetq */
        return (*qfn2(fn))(qenv(fn), v323, v322);
    }

v340:
    v322 = stack[0];
    v322 = qcdr(v322);
    v322 = qcar(v322);
    v322 = Lsimple_vectorp(nil, v322);
    env = stack[-6];
    if (!(v322 == nil)) goto v341;
    v322 = stack[0];
    v322 = qcdr(v322);
    v323 = qcar(v322);
    v322 = elt(env, 8); /* vecfn */
    v322 = Lflagpcar(nil, v323, v322);
    env = stack[-6];
    if (!(v322 == nil)) goto v341;
    stack[0] = elt(env, 17); /* setk */
    v322 = stack[-2];
    v323 = Lmkquote(nil, v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    v322 = stack[-5];
    {
        Lisp_Object v342 = stack[0];
        popv(7);
        return list3(v342, v323, v322);
    }

v341:
    stack[-1] = elt(env, 26); /* setv */
    v322 = stack[-2];
    v323 = Lmkquote(nil, v322);
    nil = C_nil;
    if (exception_pending()) goto v326;
    v322 = stack[0];
    v322 = qcdr(v322);
    v322 = qcar(v322);
    {
        Lisp_Object v343 = stack[-1];
        popv(7);
        return list3(v343, v323, v322);
    }
/* error exit handlers */
v326:
    popv(7);
    return nil;
}



/* Code for red_topred */

static Lisp_Object CC_red_topred(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v344, v232;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_topred");
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
    v344 = stack[0];
    fn = elt(env, 3); /* bas_dpoly */
    v344 = (*qfn1(fn))(qenv(fn), v344);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    if (v344 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v344 = stack[-1];
    if (v344 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v232 = stack[-1];
    v344 = stack[0];
    fn = elt(env, 4); /* red_topredbe */
    v344 = (*qfn2(fn))(qenv(fn), v232, v344);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    stack[0] = v344;
    goto v29;

v29:
    v344 = stack[0];
    fn = elt(env, 3); /* bas_dpoly */
    v344 = (*qfn1(fn))(qenv(fn), v344);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    v232 = v344;
    if (v344 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    stack[-2] = stack[-1];
    v344 = v232;
    fn = elt(env, 5); /* dp_lmon */
    v344 = (*qfn1(fn))(qenv(fn), v344);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    fn = elt(env, 6); /* red_divtest */
    v344 = (*qfn2(fn))(qenv(fn), stack[-2], v344);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    stack[-2] = v344;
    if (v344 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v232 = stack[0];
    v344 = stack[-2];
    fn = elt(env, 7); /* red_subst */
    v344 = (*qfn2(fn))(qenv(fn), v232, v344);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    stack[-2] = v344;
    v344 = qvalue(elt(env, 2)); /* !*noetherian */
    if (!(v344 == nil)) goto v32;
    v232 = stack[-1];
    v344 = stack[0];
    fn = elt(env, 8); /* red_update */
    v344 = (*qfn2(fn))(qenv(fn), v232, v344);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    stack[-1] = v344;
    goto v32;

v32:
    v232 = stack[-1];
    v344 = stack[-2];
    fn = elt(env, 4); /* red_topredbe */
    v344 = (*qfn2(fn))(qenv(fn), v232, v344);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    stack[0] = v344;
    goto v29;
/* error exit handlers */
v65:
    popv(4);
    return nil;
}



/* Code for atom_compare */

static Lisp_Object CC_atom_compare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v240, v87;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for atom_compare");
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
    v240 = v1;
    v87 = v0;
/* end of prologue */
    v86 = v87;
    if (is_number(v86)) goto v91;
    v86 = v240;
    if (symbolp(v86)) goto v29;
    v86 = v240;
    v86 = (is_number(v86) ? lisp_true : nil);
    return onevalue(v86);

v29:
    v86 = v87;
        return Lorderp(nil, v86, v240);

v91:
    v86 = v240;
    if (is_number(v86)) goto v18;
    v86 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v86);

v18:
    v86 = v87;
    v86 = (Lisp_Object)lessp2(v86, v240);
    errexit();
    v86 = v86 ? lisp_true : nil;
    v86 = (v86 == nil ? lisp_true : nil);
    return onevalue(v86);
}



/* Code for quotfail!-in!-vector */

static Lisp_Object MS_CDECL CC_quotfailKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v24, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v315, v355, v237, v257, v144, v145, v146, v218;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "quotfail-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfail-in-vector");
#endif
    if (stack >= stacklimit)
    {
        push4(v24,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v24);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v24;
    stack[-2] = v2;
    v237 = v1;
    stack[-3] = v0;
/* end of prologue */
    v355 = v237;
    v315 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v355)) < ((int32_t)(v315))) { popv(6); return onevalue(v237); }
    v355 = stack[-1];
    v315 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v355)) < ((int32_t)(v315))) goto v18;
    v355 = v237;
    v315 = stack[-1];
    if (((int32_t)(v355)) < ((int32_t)(v315))) goto v14;
    v355 = v237;
    v315 = stack[-1];
    v315 = (Lisp_Object)(int32_t)((int32_t)v355 - (int32_t)v315 + TAG_FIXNUM);
    stack[-4] = v315;
    v315 = stack[-4];
    stack[0] = v315;
    goto v26;

v26:
    v315 = stack[0];
    v315 = ((intptr_t)(v315) < 0 ? lisp_true : nil);
    if (v315 == nil) goto v94;
    v315 = (Lisp_Object)1; /* 0 */
    stack[0] = v315;
    goto v43;

v43:
    v315 = stack[-1];
    v355 = (Lisp_Object)((int32_t)(v315) - 0x10);
    v315 = stack[0];
    v315 = (Lisp_Object)(int32_t)((int32_t)v355 - (int32_t)v315 + TAG_FIXNUM);
    v315 = ((intptr_t)(v315) < 0 ? lisp_true : nil);
    if (v315 == nil) goto v356;
    v315 = (Lisp_Object)1; /* 0 */
    v145 = v315;
    goto v158;

v158:
    v355 = stack[-4];
    v315 = v145;
    v315 = (Lisp_Object)(int32_t)((int32_t)v355 - (int32_t)v315 + TAG_FIXNUM);
    v315 = ((intptr_t)(v315) < 0 ? lisp_true : nil);
    if (!(v315 == nil)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v144 = stack[-3];
    v257 = v145;
    v237 = stack[-3];
    v355 = stack[-1];
    v315 = v145;
    v315 = (Lisp_Object)(int32_t)((int32_t)v355 + (int32_t)v315 - TAG_FIXNUM);
    v315 = *(Lisp_Object *)((char *)v237 + (CELL-TAG_VECTOR) + ((int32_t)v315/(16/CELL)));
    *(Lisp_Object *)((char *)v144 + (CELL-TAG_VECTOR) + ((int32_t)v257/(16/CELL))) = v315;
    v315 = v145;
    v315 = (Lisp_Object)((int32_t)(v315) + 0x10);
    v145 = v315;
    goto v158;

v356:
    v355 = stack[-3];
    v315 = stack[0];
    v355 = *(Lisp_Object *)((char *)v355 + (CELL-TAG_VECTOR) + ((int32_t)v315/(16/CELL)));
    v315 = (Lisp_Object)1; /* 0 */
    if (v355 == v315) goto v166;
    v315 = elt(env, 4); /* "Quotient not exact in QUOTFAIL!-IN!-VECTOR" 
*/
    fn = elt(env, 5); /* errorf */
    v315 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-5];
    goto v166;

v166:
    v315 = stack[0];
    v315 = (Lisp_Object)((int32_t)(v315) + 0x10);
    stack[0] = v315;
    goto v43;

v94:
    v237 = stack[-3];
    v355 = stack[-1];
    v315 = stack[0];
    v315 = (Lisp_Object)(int32_t)((int32_t)v355 + (int32_t)v315 - TAG_FIXNUM);
    v237 = *(Lisp_Object *)((char *)v237 + (CELL-TAG_VECTOR) + ((int32_t)v315/(16/CELL)));
    v355 = stack[-2];
    v315 = stack[-1];
    v315 = *(Lisp_Object *)((char *)v355 + (CELL-TAG_VECTOR) + ((int32_t)v315/(16/CELL)));
    v315 = Lmodular_quotient(nil, v237, v315);
    nil = C_nil;
    if (exception_pending()) goto v357;
    env = stack[-5];
    v218 = v315;
    v315 = (Lisp_Object)1; /* 0 */
    v146 = v315;
    goto v61;

v61:
    v315 = stack[-1];
    v355 = (Lisp_Object)((int32_t)(v315) - 0x10);
    v315 = v146;
    v315 = (Lisp_Object)(int32_t)((int32_t)v355 - (int32_t)v315 + TAG_FIXNUM);
    v315 = ((intptr_t)(v315) < 0 ? lisp_true : nil);
    if (v315 == nil) goto v137;
    v237 = stack[-3];
    v355 = stack[-1];
    v315 = stack[0];
    v315 = (Lisp_Object)(int32_t)((int32_t)v355 + (int32_t)v315 - TAG_FIXNUM);
    v355 = v218;
    *(Lisp_Object *)((char *)v237 + (CELL-TAG_VECTOR) + ((int32_t)v315/(16/CELL))) = v355;
    v315 = stack[0];
    v315 = (Lisp_Object)((int32_t)(v315) - 0x10);
    stack[0] = v315;
    goto v26;

v137:
    v145 = stack[-3];
    v355 = stack[0];
    v315 = v146;
    v144 = (Lisp_Object)(int32_t)((int32_t)v355 + (int32_t)v315 - TAG_FIXNUM);
    v237 = stack[-3];
    v355 = stack[0];
    v315 = v146;
    v315 = (Lisp_Object)(int32_t)((int32_t)v355 + (int32_t)v315 - TAG_FIXNUM);
    v257 = *(Lisp_Object *)((char *)v237 + (CELL-TAG_VECTOR) + ((int32_t)v315/(16/CELL)));
    v237 = v218;
    v355 = stack[-2];
    v315 = v146;
    v315 = *(Lisp_Object *)((char *)v355 + (CELL-TAG_VECTOR) + ((int32_t)v315/(16/CELL)));
    v315 = Lmodular_times(nil, v237, v315);
    env = stack[-5];
    {   int32_t w = int_of_fixnum(v257) - int_of_fixnum(v315);
        if (w < 0) w += current_modulus;
        v315 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v145 + (CELL-TAG_VECTOR) + ((int32_t)v144/(16/CELL))) = v315;
    v315 = v146;
    v315 = (Lisp_Object)((int32_t)(v315) + 0x10);
    v146 = v315;
    goto v61;

v14:
    v315 = elt(env, 2); /* "Bad degrees in QUOTFAIL-IN-VECTOR" */
    {
        popv(6);
        fn = elt(env, 5); /* errorf */
        return (*qfn1(fn))(qenv(fn), v315);
    }

v18:
    v315 = elt(env, 1); /* "Attempt to divide by zero" */
    {
        popv(6);
        fn = elt(env, 5); /* errorf */
        return (*qfn1(fn))(qenv(fn), v315);
    }
/* error exit handlers */
v357:
    popv(6);
    return nil;
}



/* Code for modp */

static Lisp_Object CC_modp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v3;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modp");
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
    v3 = stack[-1];
    v4 = stack[0];
    v4 = Cremainder(v3, v4);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    stack[-1] = v4;
    v3 = stack[-1];
    v4 = (Lisp_Object)1; /* 0 */
    v4 = (Lisp_Object)lessp2(v3, v4);
    nil = C_nil;
    if (exception_pending()) goto v36;
    v4 = v4 ? lisp_true : nil;
    if (v4 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v3 = stack[-1];
    v4 = stack[0];
    popv(3);
    return plus2(v3, v4);
/* error exit handlers */
v36:
    popv(3);
    return nil;
}



/* Code for rl_bnfsimpl */

static Lisp_Object CC_rl_bnfsimpl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v206;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_bnfsimpl");
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
    v30 = v1;
    v206 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_bnfsimpl!* */
    v30 = list2(v206, v30);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    {
        Lisp_Object v40 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v40, v30);
    }
/* error exit handlers */
v5:
    popv(2);
    return nil;
}



/* Code for gb_buch!-ev_divides!? */

static Lisp_Object CC_gb_buchKev_dividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gb_buch-ev_divides?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v39 = v1;
    v135 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* ev_mtest!? */
        return (*qfn2(fn))(qenv(fn), v39, v135);
    }
}



/* Code for rd!:zerop!: */

static Lisp_Object CC_rdTzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:zerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v19 = v4;
    v19 = qcdr(v19);
    if (!consp(v19)) goto v41;
    v19 = v4;
    v19 = qcdr(v19);
    if (!consp(v19)) goto v21;
    v19 = v4;
    goto v206;

v206:
    v19 = qcdr(v19);
    v4 = qcar(v19);
    v19 = (Lisp_Object)1; /* 0 */
    v19 = (v4 == v19 ? lisp_true : nil);
    return onevalue(v19);

v21:
    v19 = v4;
    v19 = qcdr(v19);
    goto v206;

v41:
    v19 = v4;
    v19 = qcdr(v19);
    {
        fn = elt(env, 1); /* ft!:zerop */
        return (*qfn1(fn))(qenv(fn), v19);
    }
}



/* Code for dipsimpcont */

static Lisp_Object CC_dipsimpcont(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v251, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipsimpcont");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v18 = v0;
/* end of prologue */
    v251 = qvalue(elt(env, 1)); /* !*vdpinteger */
    if (!(v251 == nil)) goto v41;
    v251 = qvalue(elt(env, 2)); /* !*groebdivide */
    if (v251 == nil) goto v41;
    v251 = v18;
    {
        fn = elt(env, 3); /* dipsimpcontr */
        return (*qfn1(fn))(qenv(fn), v251);
    }

v41:
    v251 = v18;
    {
        fn = elt(env, 4); /* dipsimpconti */
        return (*qfn1(fn))(qenv(fn), v251);
    }
}



/* Code for add_item */

static Lisp_Object CC_add_item(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add_item");
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

v91:
    v98 = stack[0];
    v98 = qcdr(v98);
    if (v98 == nil) goto v38;
    v98 = stack[0];
    v98 = qcar(v98);
    v99 = qcar(v98);
    v98 = stack[-1];
    v98 = qcar(v98);
    fn = elt(env, 3); /* monordp */
    v98 = (*qfn2(fn))(qenv(fn), v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    if (v98 == nil) goto v85;
    v98 = stack[0];
    v98 = qcdr(v98);
    v98 = qcar(v98);
    stack[0] = v98;
    goto v91;

v85:
    v98 = stack[0];
    v98 = qcdr(v98);
    v98 = qcdr(v98);
    stack[0] = v98;
    goto v91;

v38:
    v99 = stack[0];
    v98 = stack[-1];
    fn = elt(env, 4); /* setcar */
    v98 = (*qfn2(fn))(qenv(fn), v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    stack[-2] = stack[0];
    stack[-1] = elt(env, 1); /* !*xset!* */
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v98 = elt(env, 1); /* !*xset!* */
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    v98 = acons(stack[-1], stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    fn = elt(env, 5); /* setcdr */
    v98 = (*qfn2(fn))(qenv(fn), stack[-2], v98);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-3];
    v98 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v98); }
/* error exit handlers */
v23:
    popv(4);
    return nil;
}



/* Code for edge_new_parents */

static Lisp_Object CC_edge_new_parents(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v4, v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for edge_new_parents");
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
    v3 = v0;
/* end of prologue */
    v19 = v3;
    v4 = qcar(v19);
    v19 = qvalue(elt(env, 1)); /* old_edge_list */
    v19 = Lassoc(nil, v4, v19);
    if (v19 == nil) goto v251;
    v19 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v19); }

v251:
    v19 = v3;
    v19 = qcdr(v19);
    v19 = qcar(v19);
    v4 = v19;
    v4 = qcar(v4);
    v19 = qcdr(v19);
    v19 = list2(v4, v19);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* edge_new_parent */
        return (*qfn1(fn))(qenv(fn), v19);
    }
/* error exit handlers */
v96:
    popv(1);
    return nil;
}



/* Code for in_list1 */

static Lisp_Object CC_in_list1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v119, v153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for in_list1");
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
    v122 = qvalue(elt(env, 1)); /* !*echo */
    stack[-1] = v122;
    v122 = qvalue(elt(env, 2)); /* !*reduce4 */
    if (v122 == nil) goto v168;
    v122 = stack[-3];
    fn = elt(env, 13); /* type */
    v119 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    v122 = elt(env, 3); /* string */
    if (v119 == v122) goto v4;
    v119 = stack[-3];
    v122 = elt(env, 3); /* string */
    fn = elt(env, 14); /* typerr */
    v122 = (*qfn2(fn))(qenv(fn), v119, v122);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    goto v168;

v168:
    v122 = stack[-3];
    fn = elt(env, 15); /* mkfil!* */
    v119 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    stack[-3] = v119;
    v122 = elt(env, 4); /* input */
    fn = elt(env, 16); /* open */
    v122 = (*qfn2(fn))(qenv(fn), v119, v122);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    stack[-4] = v122;
    v122 = stack[-4];
    v122 = Lrds(nil, v122);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    stack[0] = v122;
    v119 = stack[-3];
    v122 = qvalue(elt(env, 5)); /* linelist!* */
    v122 = Lassoc(nil, v119, v122);
    if (!(v122 == nil)) goto v10;

v10:
    v122 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 7)) = v122; /* curline!* */
    v153 = stack[-3];
    v119 = stack[-4];
    v122 = (Lisp_Object)17; /* 1 */
    v122 = list3(v153, v119, v122);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    qvalue(elt(env, 8)) = v122; /* ifl!* */
    v119 = qvalue(elt(env, 8)); /* ifl!* */
    v122 = qvalue(elt(env, 9)); /* ipl!* */
    v122 = cons(v119, v122);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    qvalue(elt(env, 9)) = v122; /* ipl!* */
    v122 = stack[-2];
    qvalue(elt(env, 1)) = v122; /* !*echo */
    fn = elt(env, 17); /* begin1 */
    v122 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    v122 = stack[0];
    v122 = Lrds(nil, v122);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    v122 = stack[-4];
    v122 = Lclose(nil, v122);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    v122 = stack[-1];
    qvalue(elt(env, 1)) = v122; /* !*echo */
    v122 = qvalue(elt(env, 9)); /* ipl!* */
    if (!(v122 == nil)) goto v62;
    v122 = qvalue(elt(env, 10)); /* contl!* */
    if (v122 == nil) goto v62;
    v122 = qvalue(elt(env, 6)); /* nil */
    { popv(6); return onevalue(v122); }

v62:
    v122 = qvalue(elt(env, 9)); /* ipl!* */
    if (v122 == nil) goto v243;
    v119 = stack[-3];
    v122 = qvalue(elt(env, 9)); /* ipl!* */
    v122 = qcar(v122);
    v122 = qcar(v122);
    if (!(v119 == v122)) goto v243;
    v122 = qvalue(elt(env, 9)); /* ipl!* */
    v122 = qcdr(v122);
    qvalue(elt(env, 9)) = v122; /* ipl!* */
    goto v169;

v169:
    v122 = nil;
    { popv(6); return onevalue(v122); }

v243:
    v122 = qvalue(elt(env, 11)); /* !*protfg */
    if (!(v122 == nil)) goto v59;
    v153 = elt(env, 12); /* "FILE STACK CONFUSION" */
    v119 = stack[-3];
    v122 = qvalue(elt(env, 9)); /* ipl!* */
    v122 = list3(v153, v119, v122);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    fn = elt(env, 18); /* lprie */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    goto v59;

v59:
    v122 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v230;
    goto v169;

v4:
    v122 = stack[-3];
    fn = elt(env, 19); /* value */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-5];
    stack[-3] = v122;
    goto v168;
/* error exit handlers */
v230:
    popv(6);
    return nil;
}



/* Code for sf2mv */

static Lisp_Object CC_sf2mv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v17, v251;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sf2mv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v148 = v1;
    v17 = v0;
/* end of prologue */
    v251 = v17;
    v17 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* sf2mv1 */
        return (*qfnn(fn))(qenv(fn), 3, v251, v17, v148);
    }
}



setup_type const u28_setup[] =
{
    {"valuecoefft",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_valuecoefft},
    {"qqe_eta-in-term1",        CC_qqe_etaKinKterm1,too_many_1,wrong_no_1},
    {"lambdavar",               CC_lambdavar,   too_many_1,    wrong_no_1},
    {"domainvalchk",            too_few_2,      CC_domainvalchk,wrong_no_2},
    {"doublep",                 CC_doublep,     too_many_1,    wrong_no_1},
    {"s-nextarg",               CC_sKnextarg,   too_many_1,    wrong_no_1},
    {"evinvlexcomp",            too_few_2,      CC_evinvlexcomp,wrong_no_2},
    {"dipprodin",               too_few_2,      CC_dipprodin,  wrong_no_2},
    {"exdff0",                  CC_exdff0,      too_many_1,    wrong_no_1},
    {"applysetop",              too_few_2,      CC_applysetop, wrong_no_2},
    {"rd:difference",           too_few_2,      CC_rdTdifference,wrong_no_2},
    {"physoptimes",             CC_physoptimes, too_many_1,    wrong_no_1},
    {"calc_atlas",              too_few_2,      CC_calc_atlas, wrong_no_2},
    {"gettype",                 CC_gettype,     too_many_1,    wrong_no_1},
    {"subs2chk",                CC_subs2chk,    too_many_1,    wrong_no_1},
    {"xremf",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_xremf},
    {"even_action_term",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_even_action_term},
    {"maxfrom1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_maxfrom1},
    {"mk+scal+mult+mat",        too_few_2,      CC_mkLscalLmultLmat,wrong_no_2},
    {"mksp*",                   too_few_2,      CC_mkspH,      wrong_no_2},
    {"pasf_dt",                 CC_pasf_dt,     too_many_1,    wrong_no_1},
    {"dvfsf_smupdknowl",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_dvfsf_smupdknowl},
    {"relnrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_relnrd},
    {"dm-min",                  too_few_2,      CC_dmKmin,     wrong_no_2},
    {"oldmtch",                 too_few_2,      CC_oldmtch,    wrong_no_2},
    {"gvar1",                   too_few_2,      CC_gvar1,      wrong_no_2},
    {"incident",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_incident},
    {"formsetq0",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_formsetq0},
    {"red_topred",              too_few_2,      CC_red_topred, wrong_no_2},
    {"atom_compare",            too_few_2,      CC_atom_compare,wrong_no_2},
    {"quotfail-in-vector",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_quotfailKinKvector},
    {"modp",                    too_few_2,      CC_modp,       wrong_no_2},
    {"rl_bnfsimpl",             too_few_2,      CC_rl_bnfsimpl,wrong_no_2},
    {"gb_buch-ev_divides?",     too_few_2,      CC_gb_buchKev_dividesW,wrong_no_2},
    {"rd:zerop:",               CC_rdTzeropT,   too_many_1,    wrong_no_1},
    {"dipsimpcont",             CC_dipsimpcont, too_many_1,    wrong_no_1},
    {"add_item",                too_few_2,      CC_add_item,   wrong_no_2},
    {"edge_new_parents",        CC_edge_new_parents,too_many_1,wrong_no_1},
    {"in_list1",                too_few_2,      CC_in_list1,   wrong_no_2},
    {"sf2mv",                   too_few_2,      CC_sf2mv,      wrong_no_2},
    {NULL, (one_args *)"u28", (two_args *)"5302 3729660 4800081", 0}
};

/* end of generated code */
