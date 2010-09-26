
/* $destdir\u32.c        Machine generated C code */

/* Signature: 00000000 26-Sep-2010 */

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


/* Code for splitup */

static Lisp_Object CC_splitup(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v17, v18;
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
    v18 = v1;
    stack[0] = v0;
/* end of prologue */
    v16 = stack[0];
    if (v16 == nil) goto v19;
    v16 = stack[0];
    v16 = qcar(v16);
    v16 = qcar(v16);
    v16 = qcar(v16);
    v17 = v16;
    v16 = v17;
    v16 = (v16 == nil ? lisp_true : nil);
    if (!(v16 == nil)) goto v20;
    v16 = v18;
    v16 = Lmemq(nil, v17, v16);
    goto v20;

v20:
    if (v16 == nil) goto v21;
    v17 = qvalue(elt(env, 1)); /* nil */
    v16 = stack[0];
    popv(3);
    return list2(v17, v16);

v21:
    v16 = stack[0];
    v16 = qcdr(v16);
    v17 = v18;
    v16 = CC_splitup(env, v16, v17);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    v17 = v16;
    v16 = stack[0];
    stack[-1] = qcar(v16);
    v16 = v17;
    stack[0] = qcar(v16);
    v16 = v17;
    v16 = qcdr(v16);
    v16 = qcar(v16);
    v16 = ncons(v16);
    nil = C_nil;
    if (exception_pending()) goto v22;
    {
        Lisp_Object v23 = stack[-1];
        Lisp_Object v24 = stack[0];
        popv(3);
        return acons(v23, v24, v16);
    }

v19:
    v16 = qvalue(elt(env, 1)); /* nil */
    v17 = qvalue(elt(env, 1)); /* nil */
    popv(3);
    return list2(v16, v17);
/* error exit handlers */
v22:
    popv(3);
    return nil;
}



/* Code for set!-weights */

static Lisp_Object CC_setKweights(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5;
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
    v5 = v0;
/* end of prologue */
    stack[-4] = (Lisp_Object)1; /* 0 */
    v5 = qcdr(v5);
    stack[-3] = v5;
    v5 = stack[-3];
    if (v5 == nil) goto v20;
    v5 = (Lisp_Object)17; /* 1 */
    v5 = ncons(v5);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    stack[-1] = v5;
    stack[-2] = v5;
    goto v30;

v30:
    v5 = stack[-3];
    v5 = qcdr(v5);
    stack[-3] = v5;
    v5 = stack[-3];
    if (v5 == nil) goto v31;
    stack[0] = stack[-1];
    v5 = (Lisp_Object)17; /* 1 */
    v5 = ncons(v5);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    v5 = Lrplacd(nil, stack[0], v5);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    v5 = stack[-1];
    v5 = qcdr(v5);
    stack[-1] = v5;
    goto v30;

v31:
    v5 = stack[-2];
    goto v32;

v32:
    v5 = cons(stack[-4], v5);
    nil = C_nil;
    if (exception_pending()) goto v29;
        popv(6);
        return Lnreverse(nil, v5);

v20:
    v5 = qvalue(elt(env, 1)); /* nil */
    goto v32;
/* error exit handlers */
v29:
    popv(6);
    return nil;
}



/* Code for ofsf_simplat1 */

static Lisp_Object CC_ofsf_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v68, v69;
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
    v69 = v0;
/* end of prologue */
    v67 = v69;
    v67 = qcar(v67);
    stack[-3] = v67;
    v68 = stack[-3];
    v67 = elt(env, 1); /* (equal neq leq geq lessp greaterp) */
    v67 = Lmemq(nil, v68, v67);
    if (v67 == nil) goto v32;
    v67 = v69;
    v67 = qcdr(v67);
    v67 = qcar(v67);
    stack[-1] = v67;
    v67 = stack[-1];
    if (!consp(v67)) goto v70;
    v67 = stack[-1];
    v67 = qcar(v67);
    if (!consp(v67)) goto v70;
    stack[0] = stack[-1];
    v67 = stack[-1];
    fn = elt(env, 12); /* sfto_dcontentf */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    fn = elt(env, 13); /* quotf */
    v67 = (*qfn2(fn))(qenv(fn), stack[0], v67);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    stack[-1] = v67;
    v67 = stack[-1];
    fn = elt(env, 14); /* minusf */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    if (v67 == nil) goto v72;
    v67 = stack[-1];
    fn = elt(env, 15); /* negf */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    stack[-1] = v67;
    v67 = stack[-3];
    fn = elt(env, 16); /* ofsf_anegrel */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    stack[-3] = v67;
    goto v72;

v72:
    v67 = qvalue(elt(env, 5)); /* !*rlsiatadv */
    if (v67 == nil) goto v73;
    v68 = stack[-3];
    v67 = elt(env, 6); /* equal */
    if (v68 == v67) goto v74;
    v68 = stack[-3];
    v67 = elt(env, 7); /* neq */
    if (v68 == v67) goto v75;
    v68 = stack[-3];
    v67 = elt(env, 8); /* leq */
    if (v68 == v67) goto v76;
    v68 = stack[-3];
    v67 = elt(env, 9); /* geq */
    if (v68 == v67) goto v77;
    v68 = stack[-3];
    v67 = elt(env, 10); /* lessp */
    if (v68 == v67) goto v78;
    v68 = stack[-3];
    v67 = elt(env, 11); /* greaterp */
    if (v68 == v67) goto v79;
    v67 = nil;
    { popv(5); return onevalue(v67); }

v79:
    v68 = stack[-1];
    v67 = stack[-2];
    {
        popv(5);
        fn = elt(env, 17); /* ofsf_simplgreaterp */
        return (*qfn2(fn))(qenv(fn), v68, v67);
    }

v78:
    v68 = stack[-1];
    v67 = stack[-2];
    {
        popv(5);
        fn = elt(env, 18); /* ofsf_simpllessp */
        return (*qfn2(fn))(qenv(fn), v68, v67);
    }

v77:
    v68 = stack[-1];
    v67 = stack[-2];
    {
        popv(5);
        fn = elt(env, 19); /* ofsf_simplgeq */
        return (*qfn2(fn))(qenv(fn), v68, v67);
    }

v76:
    v68 = stack[-1];
    v67 = stack[-2];
    {
        popv(5);
        fn = elt(env, 20); /* ofsf_simplleq */
        return (*qfn2(fn))(qenv(fn), v68, v67);
    }

v75:
    v68 = stack[-1];
    v67 = stack[-2];
    {
        popv(5);
        fn = elt(env, 21); /* ofsf_simplneq */
        return (*qfn2(fn))(qenv(fn), v68, v67);
    }

v74:
    v68 = stack[-1];
    v67 = stack[-2];
    {
        popv(5);
        fn = elt(env, 22); /* ofsf_simplequal */
        return (*qfn2(fn))(qenv(fn), v68, v67);
    }

v73:
    v68 = stack[-3];
    v67 = stack[-1];
    v69 = qvalue(elt(env, 2)); /* nil */
    popv(5);
    return list3(v68, v67, v69);

v70:
    v68 = stack[-3];
    v67 = stack[-1];
    fn = elt(env, 23); /* ofsf_evalatp */
    v67 = (*qfn2(fn))(qenv(fn), v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    if (v67 == nil) goto v21;
    v67 = elt(env, 3); /* true */
    { popv(5); return onevalue(v67); }

v21:
    v67 = elt(env, 4); /* false */
    { popv(5); return onevalue(v67); }

v32:
    v67 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v67); }
/* error exit handlers */
v71:
    popv(5);
    return nil;
}



/* Code for pickbasicset */

static Lisp_Object CC_pickbasicset(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v88;
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
    v87 = qvalue(elt(env, 1)); /* wuvarlist!* */
    stack[-1] = v87;
    goto v89;

v89:
    v87 = stack[-1];
    if (v87 == nil) goto v90;
    v87 = stack[-1];
    v87 = qcar(v87);
    stack[0] = v87;
    goto v91;

v91:
    v87 = stack[-2];
    if (v87 == nil) goto v92;
    v87 = stack[-2];
    v87 = qcar(v87);
    v87 = qcar(v87);
    v87 = qcar(v87);
    v88 = qcar(v87);
    v87 = stack[0];
    fn = elt(env, 3); /* symbollessp */
    v87 = (*qfn2(fn))(qenv(fn), v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    if (v87 == nil) goto v92;
    v87 = stack[-2];
    v87 = qcdr(v87);
    stack[-2] = v87;
    goto v91;

v92:
    v87 = stack[-2];
    if (v87 == nil) goto v65;
    v88 = stack[0];
    v87 = stack[-2];
    v87 = qcar(v87);
    v87 = qcar(v87);
    v87 = qcar(v87);
    v87 = qcar(v87);
    if (!(equal(v88, v87))) goto v65;
    v87 = stack[-2];
    v88 = qcar(v87);
    v87 = stack[-3];
    fn = elt(env, 4); /* wureducedpolysp */
    v87 = (*qfn2(fn))(qenv(fn), v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    if (!(v87 == nil)) goto v65;
    v87 = stack[-2];
    v87 = qcdr(v87);
    stack[-2] = v87;
    goto v92;

v65:
    v87 = stack[-2];
    if (v87 == nil) goto v24;
    v88 = stack[0];
    v87 = stack[-2];
    v87 = qcar(v87);
    v87 = qcar(v87);
    v87 = qcar(v87);
    v87 = qcar(v87);
    if (!(equal(v88, v87))) goto v24;
    v87 = stack[-2];
    v88 = qcar(v87);
    v87 = stack[-3];
    v87 = cons(v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-4];
    stack[-3] = v87;
    v87 = stack[-2];
    v87 = qcdr(v87);
    stack[-2] = v87;
    goto v24;

v24:
    v87 = stack[-1];
    v87 = qcdr(v87);
    stack[-1] = v87;
    goto v89;

v90:
    v87 = stack[-3];
        popv(5);
        return Lnreverse(nil, v87);
/* error exit handlers */
v93:
    popv(5);
    return nil;
}



/* Code for expf */

static Lisp_Object CC_expf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v114;
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
    v113 = stack[-2];
    if (v113 == nil) goto v86;
    v114 = stack[-2];
    v113 = (Lisp_Object)17; /* 1 */
    if (v114 == v113) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v113 = stack[-2];
    if (!consp(v113)) goto v10;
    v113 = stack[-2];
    if (!consp(v113)) goto v92;
    v113 = stack[-2];
    v113 = qcar(v113);
    if (!consp(v113)) goto v92;
    v113 = stack[-2];
    v113 = qcdr(v113);
    if (v113 == nil) goto v4;
    v114 = stack[-2];
    v113 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); /* mksp!* */
        return (*qfn2(fn))(qenv(fn), v114, v113);
    }

v4:
    v113 = stack[-2];
    v113 = qcar(v113);
    v113 = qcar(v113);
    v114 = qcdr(v113);
    v113 = stack[-1];
    v113 = times2(v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    stack[0] = v113;
    v114 = stack[0];
    v113 = (Lisp_Object)1; /* 0 */
    v113 = (Lisp_Object)greaterp2(v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    v113 = v113 ? lisp_true : nil;
    env = stack[-4];
    if (v113 == nil) goto v76;
    v113 = stack[-2];
    v113 = qcar(v113);
    v113 = qcar(v113);
    v113 = qcar(v113);
    if (!consp(v113)) goto v76;
    v113 = stack[-2];
    v113 = qcar(v113);
    v113 = qcar(v113);
    v113 = qcar(v113);
    v113 = qcar(v113);
    if (!consp(v113)) goto v76;
    v113 = stack[-2];
    v113 = qcar(v113);
    v113 = qcar(v113);
    v114 = qcar(v113);
    v113 = stack[0];
    fn = elt(env, 3); /* exptf */
    stack[0] = (*qfn2(fn))(qenv(fn), v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    v113 = stack[-2];
    v113 = qcar(v113);
    v114 = qcdr(v113);
    v113 = stack[-1];
    v113 = CC_expf(env, v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    {
        Lisp_Object v116 = stack[0];
        popv(5);
        fn = elt(env, 4); /* multf */
        return (*qfn2(fn))(qenv(fn), v116, v113);
    }

v76:
    v113 = stack[-2];
    v113 = qcar(v113);
    v113 = qcar(v113);
    stack[-3] = qcar(v113);
    v113 = stack[-2];
    v113 = qcar(v113);
    v114 = qcdr(v113);
    v113 = stack[-1];
    v113 = CC_expf(env, v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    v113 = acons(stack[-3], stack[0], v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    popv(5);
    return ncons(v113);

v92:
    v114 = stack[-2];
    v113 = stack[-1];
    {
        popv(5);
        fn = elt(env, 5); /* !:expt */
        return (*qfn2(fn))(qenv(fn), v114, v113);
    }

v10:
    stack[0] = (Lisp_Object)17; /* 1 */
    v113 = stack[-1];
    v113 = negate(v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    v113 = Lexpt(nil, stack[-2], v113);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    {
        Lisp_Object v117 = stack[0];
        popv(5);
        fn = elt(env, 6); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v117, v113);
    }

v86:
    v113 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v113); }
/* error exit handlers */
v115:
    popv(5);
    return nil;
}



/* Code for replace!-next */

static Lisp_Object CC_replaceKnext(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v108, v6, v7;
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
    goto v119;

v119:
    v107 = stack[-1];
    if (v107 == nil) goto v19;
    v107 = stack[-1];
    v107 = qcar(v107);
    v7 = qcar(v107);
    v107 = stack[-1];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    v6 = qcar(v107);
    v107 = stack[-1];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    v107 = qcdr(v107);
    v108 = qcar(v107);
    v107 = stack[0];
    v107 = qcar(v107);
    v108 = list4(v7, v6, v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    v107 = stack[-2];
    v107 = cons(v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    stack[-2] = v107;
    v107 = stack[-1];
    v107 = qcdr(v107);
    stack[-1] = v107;
    v107 = stack[0];
    v107 = qcdr(v107);
    stack[0] = v107;
    goto v119;

v19:
    v107 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v107);
    }
/* error exit handlers */
v120:
    popv(4);
    return nil;
}



/* Code for pasf_zcong */

static Lisp_Object CC_pasf_zcong(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v129, v79;
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
    v129 = v0;
/* end of prologue */
    v37 = v129;
    v37 = Lconsp(nil, v37);
    env = stack[0];
    if (v37 == nil) { popv(1); return onevalue(v129); }
    v37 = v129;
    v37 = qcar(v37);
    v37 = Lconsp(nil, v37);
    env = stack[0];
    if (v37 == nil) { popv(1); return onevalue(v129); }
    v37 = v129;
    v37 = qcar(v37);
    v79 = qcar(v37);
    v37 = elt(env, 1); /* (cong ncong) */
    v37 = Lmemq(nil, v79, v37);
    if (v37 == nil) { popv(1); return onevalue(v129); }
    v37 = v129;
    v37 = qcar(v37);
    v37 = qcdr(v37);
    if (v37 == nil) goto v6;
    v37 = v129;
    v37 = qcdr(v37);
    v37 = qcar(v37);
    if (!(v37 == nil)) goto v104;
    v79 = v129;
    v37 = elt(env, 2); /* true */
    if (v79 == v37) goto v80;
    v79 = v129;
    v37 = elt(env, 3); /* false */
    if (v79 == v37) goto v80;
    v37 = v129;
    v37 = qcar(v37);
    v37 = Lconsp(nil, v37);
    env = stack[0];
    if (v37 == nil) goto v130;
    v37 = v129;
    v37 = qcar(v37);
    v37 = qcar(v37);
    v79 = v37;
    goto v131;

v131:
    v37 = elt(env, 4); /* cong */
    if (!(v79 == v37)) goto v104;
    v37 = elt(env, 2); /* true */
    { popv(1); return onevalue(v37); }

v104:
    v37 = v129;
    v37 = qcdr(v37);
    v37 = qcar(v37);
    if (!(v37 == nil)) { popv(1); return onevalue(v129); }
    v79 = v129;
    v37 = elt(env, 2); /* true */
    if (v79 == v37) goto v45;
    v79 = v129;
    v37 = elt(env, 3); /* false */
    if (v79 == v37) goto v45;
    v37 = v129;
    v37 = qcar(v37);
    v37 = Lconsp(nil, v37);
    env = stack[0];
    if (v37 == nil) goto v39;
    v37 = v129;
    v37 = qcar(v37);
    v37 = qcar(v37);
    v79 = v37;
    goto v94;

v94:
    v37 = elt(env, 8); /* ncong */
    if (!(v79 == v37)) { popv(1); return onevalue(v129); }
    v37 = elt(env, 3); /* false */
    { popv(1); return onevalue(v37); }

v39:
    v37 = v129;
    v37 = qcar(v37);
    v79 = v37;
    goto v94;

v45:
    v37 = v129;
    v79 = v37;
    goto v94;

v130:
    v37 = v129;
    v37 = qcar(v37);
    v79 = v37;
    goto v131;

v80:
    v37 = v129;
    v79 = v37;
    goto v131;

v6:
    v79 = v129;
    v37 = elt(env, 2); /* true */
    if (v79 == v37) goto v132;
    v79 = v129;
    v37 = elt(env, 3); /* false */
    if (v79 == v37) goto v132;
    v37 = v129;
    v37 = qcar(v37);
    v37 = Lconsp(nil, v37);
    env = stack[0];
    if (v37 == nil) goto v22;
    v37 = v129;
    v37 = qcar(v37);
    v37 = qcar(v37);
    v79 = v37;
    goto v65;

v65:
    v37 = elt(env, 4); /* cong */
    if (v79 == v37) goto v133;
    v37 = elt(env, 6); /* neq */
    goto v12;

v12:
    v129 = qcdr(v129);
    v129 = qcar(v129);
    v79 = qvalue(elt(env, 7)); /* nil */
    popv(1);
    return list3(v37, v129, v79);

v133:
    v37 = elt(env, 5); /* equal */
    goto v12;

v22:
    v37 = v129;
    v37 = qcar(v37);
    v79 = v37;
    goto v65;

v132:
    v37 = v129;
    v79 = v37;
    goto v65;
}



/* Code for ratpoly_neg */

static Lisp_Object CC_ratpoly_neg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v15;
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
    v25 = stack[0];
    v25 = qcar(v25);
    fn = elt(env, 1); /* negf */
    v15 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v28;
    v25 = stack[0];
    v25 = qcdr(v25);
    popv(1);
    return cons(v15, v25);
/* error exit handlers */
v28:
    popv(1);
    return nil;
}



/* Code for symbolsom */

static Lisp_Object CC_symbolsom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v139, v47;
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
    v138 = stack[-4];
    v139 = qcar(v138);
    v138 = qvalue(elt(env, 1)); /* valid_om!* */
    v138 = Lassoc(nil, v139, v138);
    stack[-5] = v138;
    v138 = stack[-5];
    if (v138 == nil) goto v30;
    v138 = stack[-5];
    v138 = qcdr(v138);
    v138 = qcar(v138);
    stack[-5] = v138;
    goto v30;

v30:
    v138 = stack[-4];
    v138 = qcar(v138);
    stack[0] = v138;
    v138 = stack[-4];
    v138 = qcdr(v138);
    v138 = qcdr(v138);
    v138 = qcar(v138);
    stack[-3] = v138;
    v138 = stack[-4];
    v138 = Lreverse(nil, v138);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-6];
    v138 = qcar(v138);
    stack[-2] = v138;
    v139 = stack[0];
    v138 = elt(env, 2); /* diff */
    if (v139 == v138) goto v112;
    v138 = stack[-4];
    v138 = qcdr(v138);
    v138 = qcdr(v138);
    v138 = qcdr(v138);
    v138 = qcar(v138);
    stack[-1] = v138;
    goto v112;

v112:
    v138 = stack[-1];
    if (v138 == nil) goto v108;
    v138 = stack[-1];
    v139 = qcar(v138);
    v138 = elt(env, 3); /* condition */
    if (!(v139 == v138)) goto v108;
    v139 = elt(env, 4); /* "<condition> tag not supported in MathML" */
    v138 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 15); /* errorml */
    v138 = (*qfn2(fn))(qenv(fn), v139, v138);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-6];
    goto v108;

v108:
    v138 = elt(env, 5); /* "<OMA>" */
    fn = elt(env, 16); /* printout */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-6];
    v138 = qvalue(elt(env, 6)); /* t */
    fn = elt(env, 17); /* indent!* */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-6];
    v138 = stack[-1];
    if (v138 == nil) goto v127;
    v139 = stack[0];
    v138 = elt(env, 7); /* int */
    if (!(v139 == v138)) goto v127;
    v138 = elt(env, 8); /* defint */
    stack[0] = v138;
    goto v127;

v127:
    v138 = elt(env, 9); /* "<OMS cd=""" */
    fn = elt(env, 16); /* printout */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-6];
    v138 = stack[-5];
    v138 = Lprinc(nil, v138);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-6];
    v138 = elt(env, 10); /* """ name=""" */
    v138 = Lprinc(nil, v138);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-6];
    v138 = stack[0];
    v138 = Lprinc(nil, v138);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-6];
    v138 = elt(env, 11); /* """/>" */
    v138 = Lprinc(nil, v138);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-6];
    v138 = stack[-1];
    if (v138 == nil) goto v54;
    v138 = stack[-1];
    fn = elt(env, 18); /* objectom */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-6];
    goto v54;

v54:
    stack[-1] = elt(env, 12); /* lambda */
    stack[0] = qvalue(elt(env, 13)); /* nil */
    v47 = stack[-3];
    v139 = stack[-2];
    v138 = qvalue(elt(env, 13)); /* nil */
    v138 = list2star(v47, v139, v138);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-6];
    v138 = list2star(stack[-1], stack[0], v138);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-6];
    fn = elt(env, 19); /* lambdaom */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-6];
    v138 = qvalue(elt(env, 13)); /* nil */
    fn = elt(env, 17); /* indent!* */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-6];
    v138 = elt(env, 14); /* "</OMA>" */
    fn = elt(env, 16); /* printout */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v95;
    v138 = nil;
    { popv(7); return onevalue(v138); }
/* error exit handlers */
v95:
    popv(7);
    return nil;
}



/* Code for spinnerprod */

static Lisp_Object MS_CDECL CC_spinnerprod(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v81, Lisp_Object v38,
                         Lisp_Object v35, Lisp_Object v86, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v144, v145, v146;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "spinnerprod");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spinnerprod");
#endif
    if (stack >= stacklimit)
    {
        push6(v86,v35,v38,v81,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v81,v38,v35,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v86;
    v143 = v35;
    v144 = v38;
    stack[-5] = v81;
    v145 = v1;
    v146 = v0;
/* end of prologue */
    stack[-6] = v144;
    v144 = stack[-6];
    stack[-3] = v144;
    v143 = qcdr(v143);
    stack[-1] = v143;
    goto v30;

v30:
    v143 = stack[-1];
    if (v143 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    v143 = stack[-1];
    v143 = qcar(v143);
    v144 = v143;
    v143 = v144;
    v143 = qcar(v143);
    stack[-7] = v143;
    v143 = stack[-7];
    if (!(v143 == nil)) goto v12;
    v143 = (Lisp_Object)1; /* 0 */
    stack[-7] = v143;
    goto v12;

v12:
    v143 = v144;
    v143 = qcdr(v143);
    stack[-2] = v143;
    v143 = stack[-2];
    if (v143 == nil) goto v8;
    stack[0] = stack[-2];
    v143 = qvalue(elt(env, 1)); /* nil */
    v143 = ncons(v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    if (!(equal(stack[0], v143))) goto v148;

v8:
    v143 = (Lisp_Object)1; /* 0 */
    stack[-2] = v143;
    goto v148;

v148:
    v144 = stack[-7];
    v143 = stack[-5];
    v143 = (Lisp_Object)lesseq2(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    v143 = v143 ? lisp_true : nil;
    env = stack[-8];
    if (v143 == nil) goto v120;
    v144 = stack[-7];
    v143 = stack[-4];
    v143 = Latsoc(nil, v144, v143);
    stack[-7] = v143;
    v143 = stack[-7];
    if (v143 == nil) goto v120;
    stack[0] = stack[-7];
    v143 = qvalue(elt(env, 1)); /* nil */
    v143 = ncons(v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    if (equal(stack[0], v143)) goto v120;
    stack[0] = elt(env, 2); /* plus */
    stack[-3] = stack[-6];
    v145 = elt(env, 3); /* times */
    v144 = stack[-2];
    v143 = stack[-7];
    v143 = qcdr(v143);
    v143 = list3(v145, v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v143 = list3(stack[0], stack[-3], v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[-6] = v143;
    v143 = stack[-6];
    stack[-3] = v143;
    goto v120;

v120:
    v143 = stack[-1];
    v143 = qcdr(v143);
    stack[-1] = v143;
    goto v30;
/* error exit handlers */
v147:
    popv(9);
    return nil;
}



/* Code for fnreval */

static Lisp_Object MS_CDECL CC_fnreval(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v81, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "fnreval");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fnreval");
#endif
    if (stack >= stacklimit)
    {
        push3(v81,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v81);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v81;
    stack[-1] = v1;
    stack[0] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v90;

v90:
    v151 = stack[0];
    if (v151 == nil) goto v141;
    v100 = stack[-1];
    v151 = qvalue(elt(env, 1)); /* t */
    if (v100 == v151) goto v152;
    v151 = stack[-1];
    if (v151 == nil) goto v112;
    v151 = stack[-1];
    v151 = qcar(v151);
    if (v151 == nil) goto v153;
    v151 = stack[0];
    v151 = qcar(v151);
    v100 = v151;
    goto v154;

v154:
    v151 = stack[-2];
    v151 = cons(v100, v151);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    stack[-2] = v151;
    v151 = stack[0];
    v151 = qcdr(v151);
    stack[0] = v151;
    v151 = stack[-1];
    v151 = qcdr(v151);
    stack[-1] = v151;
    goto v90;

v153:
    v151 = stack[0];
    v100 = qcar(v151);
    v151 = stack[-4];
    fn = elt(env, 3); /* reval1 */
    v151 = (*qfn2(fn))(qenv(fn), v100, v151);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    v100 = v151;
    goto v154;

v112:
    stack[-5] = stack[-2];
    v151 = stack[0];
    stack[-3] = v151;
    v151 = stack[-3];
    if (v151 == nil) goto v107;
    v151 = stack[-3];
    v151 = qcar(v151);
    v100 = v151;
    v151 = stack[-4];
    fn = elt(env, 3); /* reval1 */
    v151 = (*qfn2(fn))(qenv(fn), v100, v151);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    v151 = ncons(v151);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    stack[-1] = v151;
    stack[-2] = v151;
    goto v21;

v21:
    v151 = stack[-3];
    v151 = qcdr(v151);
    stack[-3] = v151;
    v151 = stack[-3];
    if (v151 == nil) goto v155;
    stack[0] = stack[-1];
    v151 = stack[-3];
    v151 = qcar(v151);
    v100 = v151;
    v151 = stack[-4];
    fn = elt(env, 3); /* reval1 */
    v151 = (*qfn2(fn))(qenv(fn), v100, v151);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    v151 = ncons(v151);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    v151 = Lrplacd(nil, stack[0], v151);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-6];
    v151 = stack[-1];
    v151 = qcdr(v151);
    stack[-1] = v151;
    goto v21;

v155:
    v151 = stack[-2];
    goto v70;

v70:
    {
        Lisp_Object v156 = stack[-5];
        popv(7);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v156, v151);
    }

v107:
    v151 = qvalue(elt(env, 2)); /* nil */
    goto v70;

v152:
    v100 = stack[-2];
    v151 = stack[0];
    {
        popv(7);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v100, v151);
    }

v141:
    v151 = stack[-2];
    {
        popv(7);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v151);
    }
/* error exit handlers */
v147:
    popv(7);
    return nil;
}



/* Code for gpargp */

static Lisp_Object CC_gpargp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134;
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
    v134 = stack[0];
    v134 = Lstringp(nil, v134);
    env = stack[-1];
    if (!(v134 == nil)) { popv(2); return onevalue(v134); }
    v134 = stack[0];
    fn = elt(env, 1); /* gpexpp */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-1];
    if (!(v134 == nil)) { popv(2); return onevalue(v134); }
    v134 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* gplogexpp */
        return (*qfn1(fn))(qenv(fn), v134);
    }
/* error exit handlers */
v15:
    popv(2);
    return nil;
}



/* Code for find_bubles_coeff */

static Lisp_Object MS_CDECL CC_find_bubles_coeff(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v81, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v30, v157, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "find_bubles_coeff");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_bubles_coeff");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v66 = v81;
    v30 = v1;
    v157 = v0;
/* end of prologue */
    v91 = v157;
    v157 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* find_bubles1_coeff */
        return (*qfnn(fn))(qenv(fn), 4, v91, v157, v30, v66);
    }
}



/* Code for list2vect!* */

static Lisp_Object CC_list2vectH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v22;
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
    v105 = stack[-4];
    v105 = Llength(nil, v105);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-6];
    v105 = sub1(v105);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-6];
    v105 = Lmkvect(nil, v105);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-6];
    stack[-5] = v105;
    v105 = (Lisp_Object)17; /* 1 */
    stack[-2] = v105;
    goto v91;

v91:
    v105 = stack[-5];
    v105 = Lupbv(nil, v105);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-6];
    v22 = add1(v105);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-6];
    v105 = stack[-2];
    v105 = difference2(v22, v105);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-6];
    v105 = Lminusp(nil, v105);
    env = stack[-6];
    if (!(v105 == nil)) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    stack[-1] = stack[-5];
    v105 = stack[-2];
    stack[0] = sub1(v105);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-6];
    v22 = stack[-3];
    v105 = elt(env, 2); /* algebraic */
    if (v22 == v105) goto v7;
    v22 = stack[-4];
    v105 = stack[-2];
    fn = elt(env, 3); /* pnth */
    v105 = (*qfn2(fn))(qenv(fn), v22, v105);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-6];
    v105 = qcar(v105);
    goto v112;

v112:
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v105;
    v105 = stack[-2];
    v105 = add1(v105);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-6];
    stack[-2] = v105;
    goto v91;

v7:
    v22 = stack[-4];
    v105 = stack[-2];
    fn = elt(env, 3); /* pnth */
    v105 = (*qfn2(fn))(qenv(fn), v22, v105);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-6];
    v105 = qcar(v105);
    fn = elt(env, 4); /* symb_to_alg */
    v105 = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-6];
    goto v112;
/* error exit handlers */
v61:
    popv(7);
    return nil;
}



/* Code for simprecip */

static Lisp_Object CC_simprecip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v163;
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
    v163 = v0;
/* end of prologue */
    v24 = qvalue(elt(env, 1)); /* !*mcd */
    if (v24 == nil) goto v19;
    v24 = v163;
    v24 = qcdr(v24);
    if (v24 == nil) goto v107;
    v163 = elt(env, 2); /* "Wrong number of arguments to" */
    v24 = elt(env, 3); /* recip */
    v24 = list2(v163, v24);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[0];
    v163 = v24;
    v24 = v163;
    qvalue(elt(env, 4)) = v24; /* errmsg!* */
    v24 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v24 == nil)) goto v16;
    v24 = v163;
    fn = elt(env, 6); /* lprie */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[0];
    goto v16;

v16:
    v24 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[0];
    v24 = nil;
    goto v132;

v132:
    fn = elt(env, 7); /* simp */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 8); /* invsq */
        return (*qfn1(fn))(qenv(fn), v24);
    }

v107:
    v24 = v163;
    v24 = qcar(v24);
    goto v132;

v19:
    v24 = v163;
    v24 = qcdr(v24);
    if (v24 == nil) goto v28;
    v163 = elt(env, 2); /* "Wrong number of arguments to" */
    v24 = elt(env, 3); /* recip */
    v24 = list2(v163, v24);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[0];
    v163 = v24;
    v24 = v163;
    qvalue(elt(env, 4)) = v24; /* errmsg!* */
    v24 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v24 == nil)) goto v31;
    v24 = v163;
    fn = elt(env, 6); /* lprie */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[0];
    goto v31;

v31:
    v24 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[0];
    v24 = nil;
    v163 = v24;
    goto v32;

v32:
    v24 = (Lisp_Object)-15; /* -1 */
    v24 = list2(v163, v24);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 9); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v24);
    }

v28:
    v24 = v163;
    v24 = qcar(v24);
    v163 = v24;
    goto v32;
/* error exit handlers */
v127:
    popv(1);
    return nil;
}



/* Code for ordered!-gcd!-mod!-p */

static Lisp_Object CC_orderedKgcdKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v73;
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
    v18 = (Lisp_Object)1; /* 0 */
    stack[-2] = v18;
    goto v19;

v19:
    v73 = stack[-1];
    v18 = stack[0];
    fn = elt(env, 2); /* reduce!-degree!-mod!-p */
    v18 = (*qfn2(fn))(qenv(fn), v73, v18);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    stack[-1] = v18;
    v18 = stack[-1];
    if (v18 == nil) goto v66;
    v18 = stack[-2];
    v18 = add1(v18);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    stack[-2] = v18;
    v18 = stack[-1];
    if (!consp(v18)) goto v111;
    v18 = stack[-1];
    v18 = qcar(v18);
    if (!consp(v18)) goto v111;
    v18 = stack[-1];
    v18 = qcar(v18);
    v18 = qcar(v18);
    v73 = qcdr(v18);
    v18 = stack[0];
    v18 = qcar(v18);
    v18 = qcar(v18);
    v18 = qcdr(v18);
    v18 = (Lisp_Object)lessp2(v73, v18);
    nil = C_nil;
    if (exception_pending()) goto v24;
    v18 = v18 ? lisp_true : nil;
    env = stack[-3];
    if (v18 == nil) goto v19;
    v73 = qvalue(elt(env, 1)); /* reduction!-count */
    v18 = stack[-2];
    v18 = plus2(v73, v18);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    qvalue(elt(env, 1)) = v18; /* reduction!-count */
    v18 = (Lisp_Object)1; /* 0 */
    stack[-2] = v18;
    v18 = stack[-1];
    v73 = v18;
    v18 = stack[0];
    stack[-1] = v18;
    v18 = v73;
    stack[0] = v18;
    goto v19;

v111:
    v73 = qvalue(elt(env, 1)); /* reduction!-count */
    v18 = stack[-2];
    v18 = plus2(v73, v18);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    qvalue(elt(env, 1)) = v18; /* reduction!-count */
    v18 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v18); }

v66:
    v18 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* monic!-mod!-p */
        return (*qfn1(fn))(qenv(fn), v18);
    }
/* error exit handlers */
v24:
    popv(4);
    return nil;
}



/* Code for prepsq!*0 */

static Lisp_Object CC_prepsqH0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18, v73;
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
    v17 = stack[-2];
    v17 = qcar(v17);
    if (v17 == nil) goto v89;
    v17 = stack[-2];
    v18 = qcar(v17);
    v17 = stack[-2];
    v17 = qcdr(v17);
    fn = elt(env, 2); /* gcdf */
    v18 = (*qfn2(fn))(qenv(fn), v18, v17);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-4];
    stack[-3] = v18;
    v17 = (Lisp_Object)17; /* 1 */
    if (v18 == v17) goto v29;
    v17 = stack[-2];
    v18 = qcar(v17);
    v17 = stack[-3];
    fn = elt(env, 3); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v18, v17);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-4];
    v17 = stack[-2];
    v18 = qcdr(v17);
    v17 = stack[-3];
    fn = elt(env, 3); /* quotf */
    v18 = (*qfn2(fn))(qenv(fn), v18, v17);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-4];
    v17 = stack[-1];
    {
        Lisp_Object v127 = stack[0];
        popv(5);
        fn = elt(env, 4); /* prepsq!*1 */
        return (*qfnn(fn))(qenv(fn), 3, v127, v18, v17);
    }

v29:
    v17 = stack[-2];
    v73 = qcar(v17);
    v17 = stack[-2];
    v18 = qcdr(v17);
    v17 = stack[-1];
    {
        popv(5);
        fn = elt(env, 4); /* prepsq!*1 */
        return (*qfnn(fn))(qenv(fn), 3, v73, v18, v17);
    }

v89:
    v17 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v17); }
/* error exit handlers */
v163:
    popv(5);
    return nil;
}



/* Code for tayexp!-max2 */

static Lisp_Object CC_tayexpKmax2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v157;
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
    v157 = stack[-1];
    v30 = stack[0];
    fn = elt(env, 1); /* tayexp!-lessp */
    v30 = (*qfn2(fn))(qenv(fn), v157, v30);
    nil = C_nil;
    if (exception_pending()) goto v10;
    if (v30 == nil) { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v10:
    popv(2);
    return nil;
}



/* Code for mk!+outer!+list */

static Lisp_Object CC_mkLouterLlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v15;
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
    v25 = elt(env, 1); /* list */
    v15 = ncons(v25);
    nil = C_nil;
    if (exception_pending()) goto v28;
    v25 = stack[0];
        popv(1);
        return Lappend(nil, v15, v25);
/* error exit handlers */
v28:
    popv(1);
    return nil;
}



/* Code for ofsf_facequal!* */

static Lisp_Object CC_ofsf_facequalH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v70, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_facequal*");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v70 = v1;
    v85 = v0;
/* end of prologue */
    v118 = qvalue(elt(env, 1)); /* !*rlsifac */
    if (v118 == nil) goto v109;
    v118 = qvalue(elt(env, 2)); /* !*rlsiexpla */
    if (!(v118 == nil)) goto v86;
    v118 = qvalue(elt(env, 3)); /* !*rlsiexpl */
    if (v118 == nil) goto v109;
    v118 = elt(env, 4); /* or */
    if (!(v70 == v118)) goto v109;

v86:
    v118 = v85;
    {
        fn = elt(env, 7); /* ofsf_facequal */
        return (*qfn1(fn))(qenv(fn), v118);
    }

v109:
    v118 = elt(env, 5); /* equal */
    v70 = v85;
    v85 = qvalue(elt(env, 6)); /* nil */
    return list3(v118, v70, v85);
}



/* Code for cl_smsimpl!-junct2 */

static Lisp_Object MS_CDECL CC_cl_smsimplKjunct2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v81, Lisp_Object v38,
                         Lisp_Object v35, Lisp_Object v86, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v104, v137, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "cl_smsimpl-junct2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_smsimpl-junct2");
#endif
    if (stack >= stacklimit)
    {
        push6(v86,v35,v38,v81,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v81,v38,v35,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v86;
    v82 = v35;
    v104 = v38;
    v137 = v81;
    stack[-2] = v1;
    v136 = v0;
/* end of prologue */
    fn = elt(env, 5); /* rl_smmkatl */
    v82 = (*qfnn(fn))(qenv(fn), 4, v136, v137, v104, v82);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-4];
    stack[-3] = v82;
    v82 = qvalue(elt(env, 1)); /* !*rlsichk */
    if (v82 == nil) goto v62;
    v82 = stack[-2];
    v104 = v82;
    v82 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v82;
    v82 = v104;
    stack[0] = v82;
    goto v111;

v111:
    v82 = stack[0];
    if (v82 == nil) goto v159;
    v82 = stack[0];
    v82 = qcar(v82);
    v104 = v82;
    v82 = stack[-2];
    fn = elt(env, 6); /* lto_insert */
    v82 = (*qfn2(fn))(qenv(fn), v104, v82);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-4];
    stack[-2] = v82;
    v82 = stack[0];
    v82 = qcdr(v82);
    stack[0] = v82;
    goto v111;

v159:
    v82 = qvalue(elt(env, 3)); /* !*rlsiso */
    if (v82 == nil) goto v18;
    v104 = stack[-3];
    v82 = elt(env, 4); /* rl_ordatp */
    fn = elt(env, 7); /* sort */
    v82 = (*qfn2(fn))(qenv(fn), v104, v82);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-4];
    stack[-3] = v82;
    goto v18;

v18:
    v104 = stack[-3];
    v82 = stack[-2];
    v82 = Lnconc(nil, v104, v82);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-4];
    v104 = v82;
    v82 = v104;
    if (!(v82 == nil)) { popv(5); return onevalue(v104); }
    v82 = stack[-1];
    fn = elt(env, 8); /* cl_flip */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v165;
    popv(5);
    return ncons(v82);

v62:
    v82 = stack[-2];
    v82 = Lnreverse(nil, v82);
    env = stack[-4];
    stack[-2] = v82;
    goto v159;
/* error exit handlers */
v165:
    popv(5);
    return nil;
}



/* Code for binomial!-coefft!-mod!-p */

static Lisp_Object CC_binomialKcoefftKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v138, v139, v47, v48;
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
    v138 = stack[-2];
    v156 = stack[-1];
    v156 = (Lisp_Object)lessp2(v138, v156);
    nil = C_nil;
    if (exception_pending()) goto v94;
    v156 = v156 ? lisp_true : nil;
    env = stack[-4];
    if (v156 == nil) goto v66;
    v156 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v156); }

v66:
    v138 = stack[-2];
    v156 = stack[-1];
    if (equal(v138, v156)) goto v28;
    v138 = stack[-1];
    v156 = (Lisp_Object)17; /* 1 */
    if (v138 == v156) goto v159;
    v156 = (Lisp_Object)17; /* 1 */
    stack[-3] = v156;
    stack[0] = stack[-1];
    v138 = stack[-2];
    v156 = stack[-1];
    v156 = difference2(v138, v156);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    fn = elt(env, 2); /* min */
    v156 = (*qfn2(fn))(qenv(fn), stack[0], v156);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    stack[0] = v156;
    v156 = stack[-2];
    v156 = Lmodular_number(nil, v156);
    env = stack[-4];
    stack[-2] = v156;
    v156 = stack[-1];
    v156 = Lmodular_number(nil, v156);
    env = stack[-4];
    v156 = (Lisp_Object)17; /* 1 */
    stack[-1] = v156;
    goto v167;

v167:
    v138 = stack[0];
    v156 = stack[-1];
    v156 = difference2(v138, v156);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v156 = Lminusp(nil, v156);
    env = stack[-4];
    if (v156 == nil) goto v127;
    v156 = stack[-3];
    v156 = (Lisp_Object)zerop(v156);
    v156 = v156 ? lisp_true : nil;
    env = stack[-4];
    if (v156 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v156 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v156); }

v127:
    v156 = stack[-1];
    v156 = Lmodular_number(nil, v156);
    env = stack[-4];
    v48 = v156;
    v47 = stack[-3];
    v139 = stack[-2];
    v138 = v48;
    v156 = (Lisp_Object)17; /* 1 */
    {   int32_t w = int_of_fixnum(v138) - int_of_fixnum(v156);
        if (w < 0) w += current_modulus;
        v156 = fixnum_of_int(w);
    }
    {   int32_t w = int_of_fixnum(v139) - int_of_fixnum(v156);
        if (w < 0) w += current_modulus;
        v156 = fixnum_of_int(w);
    }
    v156 = Lmodular_times(nil, v47, v156);
    env = stack[-4];
    v138 = v48;
    v156 = Lmodular_quotient(nil, v156, v138);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    stack[-3] = v156;
    v156 = stack[-1];
    v156 = add1(v156);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    stack[-1] = v156;
    goto v167;

v159:
    v156 = stack[-2];
    v156 = Lmodular_number(nil, v156);
    env = stack[-4];
    v138 = v156;
    v156 = v138;
    v156 = (Lisp_Object)zerop(v156);
    v156 = v156 ? lisp_true : nil;
    env = stack[-4];
    if (v156 == nil) { popv(5); return onevalue(v138); }
    v156 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v156); }

v28:
    v156 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v156); }
/* error exit handlers */
v94:
    popv(5);
    return nil;
}



/* Code for dip_fmon */

static Lisp_Object CC_dip_fmon(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v14, v28;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip_fmon");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v14 = v1;
    v15 = v0;
/* end of prologue */
    v28 = qvalue(elt(env, 1)); /* nil */
    return list2star(v14, v15, v28);
}



/* Code for applyfnrd */

static Lisp_Object MS_CDECL CC_applyfnrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v10;
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
    v13 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-1];
    stack[0] = v13;
    fn = elt(env, 3); /* stats_getargs */
    v13 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-1];
    v10 = stack[0];
    v13 = cons(v10, v13);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 4); /* aeval */
        return (*qfn1(fn))(qenv(fn), v13);
    }
/* error exit handlers */
v152:
    popv(2);
    return nil;
}



/* Code for reduceroots */

static Lisp_Object CC_reduceroots(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v92, v21;
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
    v65 = nil;
    goto v89;

v89:
    v92 = stack[-1];
    if (v92 == nil) { popv(3); return onevalue(v65); }
    v92 = stack[0];
    v21 = qcar(v92);
    v92 = elt(env, 2); /* sqrt */
    if (!consp(v21)) goto v28;
    v21 = qcar(v21);
    if (!(v21 == v92)) goto v28;
    v21 = stack[-1];
    v92 = stack[0];
    v92 = qcar(v92);
    fn = elt(env, 3); /* tryreduction */
    v65 = (*qfnn(fn))(qenv(fn), 3, v21, v92, v65);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-2];
    goto v28;

v28:
    v92 = stack[-1];
    v92 = qcdr(v92);
    stack[-1] = v92;
    v92 = stack[0];
    v92 = qcdr(v92);
    stack[0] = v92;
    goto v89;
/* error exit handlers */
v132:
    popv(3);
    return nil;
}



/* Code for crprcd2 */

static Lisp_Object CC_crprcd2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v93;
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
    v75 = stack[-1];
    v75 = qcdr(v75);
    v75 = qcar(v75);
    if (!consp(v75)) goto v119;
    v93 = elt(env, 1); /* !:rd!: */
    v75 = stack[-1];
    v75 = qcdr(v75);
    v75 = qcar(v75);
    v75 = cons(v93, v75);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    goto v86;

v86:
    fn = elt(env, 3); /* convchk */
    stack[-2] = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    v75 = stack[-1];
    v75 = qcdr(v75);
    v75 = qcdr(v75);
    if (!consp(v75)) goto v110;
    v93 = elt(env, 1); /* !:rd!: */
    v75 = stack[-1];
    v75 = qcdr(v75);
    v75 = qcdr(v75);
    v75 = cons(v93, v75);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    goto v109;

v109:
    fn = elt(env, 3); /* convchk */
    v75 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    v93 = stack[-2];
    v75 = cons(v93, v75);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    stack[-1] = v75;
    v75 = stack[0];
    v75 = qcdr(v75);
    v75 = qcar(v75);
    if (!consp(v75)) goto v148;
    v93 = elt(env, 1); /* !:rd!: */
    v75 = stack[0];
    v75 = qcdr(v75);
    v75 = qcar(v75);
    v75 = cons(v93, v75);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    goto v29;

v29:
    fn = elt(env, 3); /* convchk */
    stack[-2] = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    v75 = stack[0];
    v75 = qcdr(v75);
    v75 = qcdr(v75);
    if (!consp(v75)) goto v149;
    v93 = elt(env, 1); /* !:rd!: */
    v75 = stack[0];
    v75 = qcdr(v75);
    v75 = qcdr(v75);
    v75 = cons(v93, v75);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    goto v61;

v61:
    fn = elt(env, 3); /* convchk */
    v75 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    v93 = stack[-2];
    v75 = cons(v93, v75);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    qvalue(elt(env, 2)) = v75; /* yy!! */
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v149:
    v75 = stack[0];
    v75 = qcdr(v75);
    v75 = qcdr(v75);
    goto v61;

v148:
    v75 = stack[0];
    v75 = qcdr(v75);
    v75 = qcar(v75);
    goto v29;

v110:
    v75 = stack[-1];
    v75 = qcdr(v75);
    v75 = qcdr(v75);
    goto v109;

v119:
    v75 = stack[-1];
    v75 = qcdr(v75);
    v75 = qcar(v75);
    goto v86;
/* error exit handlers */
v51:
    popv(4);
    return nil;
}



/* Code for on!-double1 */

static Lisp_Object CC_onKdouble1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110;
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

v35:
    v110 = stack[0];
    v110 = Lconsp(nil, v110);
    env = stack[-1];
    if (v110 == nil) goto v159;
    v110 = stack[0];
    v110 = qcar(v110);
    fn = elt(env, 3); /* doublep */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-1];
    if (v110 == nil) goto v30;
    v110 = lisp_true;
    qvalue(elt(env, 1)) = v110; /* !*double */
    { popv(2); return onevalue(v110); }

v30:
    v110 = stack[0];
    v110 = qcar(v110);
    v110 = CC_onKdouble1(env, v110);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-1];
    v110 = stack[0];
    v110 = qcdr(v110);
    stack[0] = v110;
    goto v35;

v159:
    v110 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v110); }
/* error exit handlers */
v150:
    popv(2);
    return nil;
}



/* Code for listpri */

static Lisp_Object CC_listpri(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v151;
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
    v146 = stack[-2];
    stack[0] = v146;
    v146 = stack[-2];
    v146 = qcdr(v146);
    stack[-2] = v146;
    v151 = elt(env, 1); /* !*lcbkt!* */
    v146 = elt(env, 2); /* prtch */
    v146 = get(v151, v146);
    env = stack[-4];
    fn = elt(env, 9); /* prin2!* */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-4];
    v146 = qvalue(elt(env, 3)); /* orig!* */
    stack[-3] = v146;
    v151 = qvalue(elt(env, 4)); /* posn!* */
    v146 = (Lisp_Object)289; /* 18 */
    v146 = (Lisp_Object)lessp2(v151, v146);
    nil = C_nil;
    if (exception_pending()) goto v50;
    v146 = v146 ? lisp_true : nil;
    env = stack[-4];
    if (v146 == nil) goto v118;
    v146 = qvalue(elt(env, 4)); /* posn!* */
    goto v10;

v10:
    qvalue(elt(env, 3)) = v146; /* orig!* */
    v146 = stack[-2];
    if (v146 == nil) goto v169;
    v151 = stack[-2];
    v146 = (Lisp_Object)641; /* 40 */
    fn = elt(env, 10); /* treesizep1 */
    v151 = (*qfn2(fn))(qenv(fn), v151, v146);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-4];
    v146 = (Lisp_Object)1; /* 0 */
    v146 = (v151 == v146 ? lisp_true : nil);
    stack[-1] = v146;
    goto v22;

v22:
    v146 = stack[-2];
    v151 = qcar(v146);
    v146 = elt(env, 5); /* minus */
    if (!consp(v151)) goto v58;
    v151 = qcar(v151);
    if (!(v151 == v146)) goto v58;
    v146 = stack[-2];
    v146 = qcar(v146);
    v146 = qcdr(v146);
    v146 = qcar(v146);
    if (!(is_number(v146))) goto v58;
    v146 = stack[-2];
    v146 = qcar(v146);
    v146 = qcdr(v146);
    v146 = qcar(v146);
    v146 = negate(v146);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-4];
    v151 = v146;
    goto v4;

v4:
    v146 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 11); /* maprint */
    v146 = (*qfn2(fn))(qenv(fn), v151, v146);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-4];
    v146 = stack[-2];
    v146 = qcdr(v146);
    stack[-2] = v146;
    v146 = stack[-2];
    if (v146 == nil) goto v169;
    v146 = elt(env, 6); /* !*comma!* */
    fn = elt(env, 12); /* oprin */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-4];
    v146 = stack[-1];
    if (v146 == nil) goto v22;
    v146 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 13); /* terpri!* */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-4];
    goto v22;

v169:
    v151 = elt(env, 8); /* !*rcbkt!* */
    v146 = elt(env, 2); /* prtch */
    v146 = get(v151, v146);
    env = stack[-4];
    fn = elt(env, 9); /* prin2!* */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-4];
    v146 = stack[-3];
    qvalue(elt(env, 3)) = v146; /* orig!* */
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v58:
    v146 = stack[-2];
    v146 = qcar(v146);
    v151 = v146;
    goto v4;

v118:
    v151 = qvalue(elt(env, 3)); /* orig!* */
    v146 = (Lisp_Object)49; /* 3 */
    v146 = plus2(v151, v146);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-4];
    goto v10;
/* error exit handlers */
v50:
    popv(5);
    return nil;
}



/* Code for r2oaddspecies */

static Lisp_Object CC_r2oaddspecies(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v133;
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
    v133 = stack[-1];
    v85 = stack[0];
    v85 = Lassoc(nil, v133, v85);
    if (!(v85 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v85 = elt(env, 1); /* "new species: " */
    v85 = Lprinc(nil, v85);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v85 = stack[-1];
    v85 = Lprinc(nil, v85);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v85 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v133 = stack[-1];
    v85 = (Lisp_Object)1; /* 0 */
    v85 = cons(v133, v85);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v85 = ncons(v85);
    nil = C_nil;
    if (exception_pending()) goto v64;
    {
        Lisp_Object v65 = stack[0];
        popv(3);
        return Lappend(nil, v65, v85);
    }
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for !:!:quotient */

static Lisp_Object CC_TTquotient(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v70;
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
    v70 = v1;
    v118 = v0;
/* end of prologue */
    stack[0] = v118;
    v118 = v70;
    v118 = integerp(v118);
    if (v118 == nil) goto v111;
    v118 = v70;
    fn = elt(env, 2); /* chkint!* */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-1];
    v70 = v118;
    if (!(!consp(v70))) goto v90;
    v70 = elt(env, 1); /* !:rd!: */
    v118 = cons(v70, v118);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-1];
    goto v90;

v90:
    {
        Lisp_Object v9 = stack[0];
        popv(2);
        fn = elt(env, 3); /* !:quotient */
        return (*qfn2(fn))(qenv(fn), v9, v118);
    }

v111:
    v118 = v70;
    goto v90;
/* error exit handlers */
v133:
    popv(2);
    return nil;
}



/* Code for z!-roads */

static Lisp_Object CC_zKroads(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23, v24;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for z-roads");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v24 = v0;
/* end of prologue */
    v23 = (Lisp_Object)1; /* 0 */
    v22 = v24;
    v22 = qcar(v22);
    v22 = qcar(v22);
    v22 = qcdr(v22);
    if (v23 == v22) goto v35;
    v23 = (Lisp_Object)1; /* 0 */
    v22 = v24;
    v22 = qcar(v22);
    v22 = qcdr(v22);
    v22 = qcar(v22);
    v22 = qcdr(v22);
    if (v23 == v22) goto v30;
    v23 = (Lisp_Object)1; /* 0 */
    v22 = v24;
    v22 = qcar(v22);
    v22 = qcdr(v22);
    v22 = qcdr(v22);
    v22 = qcar(v22);
    v22 = qcdr(v22);
    if (v23 == v22) goto v112;
    v22 = qvalue(elt(env, 1)); /* nil */
    goto v38;

v38:
    v23 = v22;
    v22 = v23;
    if (v22 == nil) goto v29;
    v22 = v23;
    v22 = qcar(v22);
    v23 = v24;
    v23 = qcdr(v23);
    return cons(v22, v23);

v29:
    v22 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v22);

v112:
    v22 = v24;
    v22 = qcar(v22);
    v22 = qcdr(v22);
    v22 = qcdr(v22);
    v22 = qcar(v22);
    goto v38;

v30:
    v22 = v24;
    v22 = qcar(v22);
    v22 = qcdr(v22);
    v22 = qcar(v22);
    goto v38;

v35:
    v22 = v24;
    v22 = qcar(v22);
    v22 = qcar(v22);
    goto v38;
}



/* Code for lieninstruc */

static Lisp_Object CC_lieninstruc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v180, v181, v71;
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
    v179 = (Lisp_Object)17; /* 1 */
    stack[-5] = v179;
    goto v14;

v14:
    stack[0] = elt(env, 1); /* difference */
    v181 = elt(env, 1); /* difference */
    v180 = stack[-4];
    v179 = (Lisp_Object)17; /* 1 */
    v179 = list3(v181, v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v180 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v179 = stack[-5];
    v179 = list3(stack[0], v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 8); /* aminusp!: */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    if (v179 == nil) goto v141;
    v179 = nil;
    { popv(7); return onevalue(v179); }

v141:
    v179 = stack[-5];
    v179 = add1(v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    stack[-3] = v179;
    goto v160;

v160:
    stack[0] = elt(env, 1); /* difference */
    v179 = stack[-4];
    fn = elt(env, 7); /* aeval!* */
    v180 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v179 = stack[-3];
    v179 = list3(stack[0], v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 8); /* aminusp!: */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    if (v179 == nil) goto v64;
    v179 = stack[-5];
    v181 = elt(env, 6); /* plus */
    v180 = v179;
    v179 = (Lisp_Object)17; /* 1 */
    v179 = list3(v181, v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    stack[-5] = v179;
    goto v14;

v64:
    v179 = (Lisp_Object)17; /* 1 */
    stack[-2] = v179;
    goto v16;

v16:
    stack[0] = elt(env, 1); /* difference */
    v179 = stack[-4];
    fn = elt(env, 7); /* aeval!* */
    v180 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v179 = stack[-2];
    v179 = list3(stack[0], v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 8); /* aminusp!: */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    if (v179 == nil) goto v104;
    v179 = stack[-3];
    v181 = elt(env, 6); /* plus */
    v180 = v179;
    v179 = (Lisp_Object)17; /* 1 */
    v179 = list3(v181, v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    stack[-3] = v179;
    goto v160;

v104:
    v71 = elt(env, 3); /* lie_cc */
    v181 = stack[-5];
    v180 = stack[-3];
    v179 = stack[-2];
    stack[0] = list4(v71, v181, v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v71 = elt(env, 4); /* lienstrucin */
    v181 = stack[-5];
    v180 = stack[-3];
    v179 = stack[-2];
    v179 = list4(v71, v181, v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 9); /* setk */
    v179 = (*qfn2(fn))(qenv(fn), stack[0], v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v71 = elt(env, 3); /* lie_cc */
    v181 = stack[-3];
    v180 = stack[-5];
    v179 = stack[-2];
    stack[-1] = list4(v71, v181, v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    stack[0] = elt(env, 5); /* minus */
    v71 = elt(env, 4); /* lienstrucin */
    v181 = stack[-5];
    v180 = stack[-3];
    v179 = stack[-2];
    v179 = list4(v71, v181, v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v179 = list2(stack[0], v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 9); /* setk */
    v179 = (*qfn2(fn))(qenv(fn), stack[-1], v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v179 = stack[-2];
    v181 = elt(env, 6); /* plus */
    v180 = v179;
    v179 = (Lisp_Object)17; /* 1 */
    v179 = list3(v181, v180, v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    stack[-2] = v179;
    goto v16;
/* error exit handlers */
v182:
    popv(7);
    return nil;
}



/* Code for pst_subpst */

static Lisp_Object CC_pst_subpst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v15;
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
    v15 = v1;
    v25 = v0;
/* end of prologue */
    stack[0] = qcdr(v25);
    v25 = v15;
    v25 = sub1(v25);
    nil = C_nil;
    if (exception_pending()) goto v28;
    v25 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v25/(16/CELL)));
    { popv(1); return onevalue(v25); }
/* error exit handlers */
v28:
    popv(1);
    return nil;
}



/* Code for ratlessp */

static Lisp_Object CC_ratlessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v157;
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
    v30 = v1;
    v157 = v0;
/* end of prologue */
    fn = elt(env, 1); /* ratdif */
    v30 = (*qfn2(fn))(qenv(fn), v157, v30);
    errexit();
    v157 = qcar(v30);
    v30 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v157, v30);
}



/* Code for diff!-k!-times!-mod!-p */

static Lisp_Object MS_CDECL CC_diffKkKtimesKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v81, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v113, v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "diff-k-times-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff-k-times-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v81,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v81);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v81;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v98 = stack[-3];
    if (!consp(v98)) goto v119;
    v98 = stack[-3];
    v98 = qcar(v98);
    if (!consp(v98)) goto v119;
    v98 = stack[-3];
    v98 = qcar(v98);
    v98 = qcar(v98);
    v113 = qcar(v98);
    v98 = stack[-1];
    if (equal(v113, v98)) goto v150;
    v98 = stack[-3];
    v98 = qcar(v98);
    stack[-4] = qcar(v98);
    v98 = stack[-3];
    v98 = qcar(v98);
    v114 = qcdr(v98);
    v113 = stack[-2];
    v98 = stack[-1];
    stack[0] = CC_diffKkKtimesKmodKp(env, 3, v114, v113, v98);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    v98 = stack[-3];
    v114 = qcdr(v98);
    v113 = stack[-2];
    v98 = stack[-1];
    v98 = CC_diffKkKtimesKmodKp(env, 3, v114, v113, v98);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    {
        Lisp_Object v117 = stack[-4];
        Lisp_Object v187 = stack[0];
        popv(6);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v117, v187, v98);
    }

v150:
    v98 = stack[-3];
    v98 = qcar(v98);
    v98 = qcar(v98);
    v113 = qcdr(v98);
    v98 = stack[-2];
    v98 = (Lisp_Object)lessp2(v113, v98);
    nil = C_nil;
    if (exception_pending()) goto v116;
    v98 = v98 ? lisp_true : nil;
    env = stack[-5];
    if (v98 == nil) goto v64;
    v98 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v98); }

v64:
    v98 = stack[-3];
    v98 = qcar(v98);
    v98 = qcar(v98);
    v113 = qcdr(v98);
    v98 = stack[-2];
    if (equal(v113, v98)) goto v9;
    v98 = stack[-1];
    fn = elt(env, 3); /* fkern */
    stack[0] = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    v98 = stack[-3];
    v98 = qcar(v98);
    v98 = qcar(v98);
    v113 = qcdr(v98);
    v98 = stack[-2];
    v98 = difference2(v113, v98);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    fn = elt(env, 4); /* getpower */
    stack[-4] = (*qfn2(fn))(qenv(fn), stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    v98 = stack[-3];
    v98 = qcar(v98);
    v98 = qcar(v98);
    v113 = qcdr(v98);
    v98 = stack[-2];
    fn = elt(env, 5); /* binomial!-coefft!-mod!-p */
    v113 = (*qfn2(fn))(qenv(fn), v113, v98);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    v98 = stack[-3];
    v98 = qcar(v98);
    v98 = qcdr(v98);
    fn = elt(env, 6); /* times!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v113, v98);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    v98 = stack[-3];
    v114 = qcdr(v98);
    v113 = stack[-2];
    v98 = stack[-1];
    v98 = CC_diffKkKtimesKmodKp(env, 3, v114, v113, v98);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    {
        Lisp_Object v124 = stack[-4];
        Lisp_Object v123 = stack[0];
        popv(6);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v124, v123, v98);
    }

v9:
    v98 = stack[-3];
    v98 = qcar(v98);
    v98 = qcdr(v98);
    { popv(6); return onevalue(v98); }

v119:
    v98 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v98); }
/* error exit handlers */
v116:
    popv(6);
    return nil;
}



/* Code for sfto_reorder */

static Lisp_Object CC_sfto_reorder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15;
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
    v15 = v1;
    stack[0] = v0;
/* end of prologue */
    v15 = ncons(v15);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    fn = elt(env, 1); /* setkorder */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    stack[-1] = v15;
    v15 = stack[0];
    fn = elt(env, 2); /* reorder */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    stack[0] = v15;
    v15 = stack[-1];
    fn = elt(env, 1); /* setkorder */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v26;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v26:
    popv(3);
    return nil;
}



/* Code for depend!-f */

static Lisp_Object CC_dependKf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v132;
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

v188:
    v160 = stack[-1];
    if (!consp(v160)) goto v86;
    v160 = stack[-1];
    v160 = qcar(v160);
    if (!consp(v160)) goto v86;
    v160 = stack[-1];
    v160 = qcar(v160);
    v160 = qcar(v160);
    v132 = qcar(v160);
    v160 = stack[0];
    fn = elt(env, 2); /* depend!-p */
    v160 = (*qfn2(fn))(qenv(fn), v132, v160);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-2];
    if (!(v160 == nil)) { popv(3); return onevalue(v160); }
    v160 = stack[-1];
    v160 = qcar(v160);
    v132 = qcdr(v160);
    v160 = stack[0];
    v160 = CC_dependKf(env, v132, v160);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-2];
    if (!(v160 == nil)) { popv(3); return onevalue(v160); }
    v160 = stack[-1];
    v132 = qcdr(v160);
    v160 = stack[0];
    stack[-1] = v132;
    stack[0] = v160;
    goto v188;

v86:
    v160 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v160); }
/* error exit handlers */
v6:
    popv(3);
    return nil;
}



/* Code for pasf_exprng1 */

static Lisp_Object CC_pasf_exprng1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v213, v214, v215, v216, v217, v218;
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
    v212 = v0;
/* end of prologue */
    v214 = v212;
    v213 = elt(env, 1); /* true */
    if (v214 == v213) { popv(6); return onevalue(v212); }
    v214 = v212;
    v213 = elt(env, 2); /* false */
    if (v214 == v213) { popv(6); return onevalue(v212); }
    v213 = v212;
    if (!consp(v213)) goto v109;
    v213 = v212;
    v213 = qcar(v213);
    goto v164;

v164:
    stack[-4] = v213;
    v214 = stack[-4];
    v213 = elt(env, 3); /* or */
    if (v214 == v213) goto v118;
    v214 = stack[-4];
    v213 = elt(env, 4); /* and */
    if (v214 == v213) goto v118;
    v214 = stack[-4];
    v213 = elt(env, 5); /* not */
    if (v214 == v213) goto v118;
    v214 = stack[-4];
    v213 = elt(env, 6); /* impl */
    if (v214 == v213) goto v118;
    v214 = stack[-4];
    v213 = elt(env, 7); /* repl */
    if (v214 == v213) goto v118;
    v214 = stack[-4];
    v213 = elt(env, 8); /* equiv */
    if (v214 == v213) goto v118;
    v214 = stack[-4];
    v213 = elt(env, 10); /* ex */
    if (v214 == v213) goto v219;
    v214 = stack[-4];
    v213 = elt(env, 11); /* all */
    if (v214 == v213) goto v219;
    v214 = stack[-4];
    v213 = elt(env, 12); /* ball */
    if (v214 == v213) goto v220;
    v214 = stack[-4];
    v213 = elt(env, 13); /* bex */
    if (!(v214 == v213)) { popv(6); return onevalue(v212); }
    v218 = stack[-4];
    v213 = v212;
    v213 = qcdr(v213);
    v217 = qcar(v213);
    v213 = v212;
    v213 = qcdr(v213);
    v213 = qcdr(v213);
    v213 = qcdr(v213);
    v216 = qcar(v213);
    v212 = qcdr(v212);
    v212 = qcdr(v212);
    v215 = qcar(v212);
    v214 = elt(env, 3); /* or */
    v213 = elt(env, 2); /* false */
    v212 = elt(env, 1); /* true */
    {
        popv(6);
        fn = elt(env, 14); /* pasf_exprng1!-gand */
        return (*qfnn(fn))(qenv(fn), 7, v218, v217, v216, v215, v214, v213, v212);
    }

v220:
    v218 = stack[-4];
    v213 = v212;
    v213 = qcdr(v213);
    v217 = qcar(v213);
    v213 = v212;
    v213 = qcdr(v213);
    v213 = qcdr(v213);
    v213 = qcdr(v213);
    v216 = qcar(v213);
    v212 = qcdr(v212);
    v212 = qcdr(v212);
    v215 = qcar(v212);
    v214 = elt(env, 4); /* and */
    v213 = elt(env, 1); /* true */
    v212 = elt(env, 2); /* false */
    {
        popv(6);
        fn = elt(env, 14); /* pasf_exprng1!-gand */
        return (*qfnn(fn))(qenv(fn), 7, v218, v217, v216, v215, v214, v213, v212);
    }

v219:
    stack[-1] = stack[-4];
    v213 = v212;
    v213 = qcdr(v213);
    stack[0] = qcar(v213);
    v212 = qcdr(v212);
    v212 = qcdr(v212);
    v212 = qcar(v212);
    v212 = CC_pasf_exprng1(env, v212);
    nil = C_nil;
    if (exception_pending()) goto v221;
    {
        Lisp_Object v222 = stack[-1];
        Lisp_Object v223 = stack[0];
        popv(6);
        return list3(v222, v223, v212);
    }

v118:
    v212 = qcdr(v212);
    stack[-3] = v212;
    v212 = stack[-3];
    if (v212 == nil) goto v154;
    v212 = stack[-3];
    v212 = qcar(v212);
    v212 = CC_pasf_exprng1(env, v212);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    v212 = ncons(v212);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    stack[-1] = v212;
    stack[-2] = v212;
    goto v224;

v224:
    v212 = stack[-3];
    v212 = qcdr(v212);
    stack[-3] = v212;
    v212 = stack[-3];
    if (v212 == nil) goto v153;
    stack[0] = stack[-1];
    v212 = stack[-3];
    v212 = qcar(v212);
    v212 = CC_pasf_exprng1(env, v212);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    v212 = ncons(v212);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    v212 = Lrplacd(nil, stack[0], v212);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    v212 = stack[-1];
    v212 = qcdr(v212);
    stack[-1] = v212;
    goto v224;

v153:
    v212 = stack[-2];
    goto v58;

v58:
    v213 = v212;
    v212 = v213;
    if (v212 == nil) goto v138;
    v212 = v213;
    v212 = qcdr(v212);
    if (v212 == nil) goto v138;
    v212 = stack[-4];
    popv(6);
    return cons(v212, v213);

v138:
    v212 = v213;
    if (v212 == nil) goto v43;
    v212 = v213;
    v212 = qcar(v212);
    { popv(6); return onevalue(v212); }

v43:
    v213 = stack[-4];
    v212 = elt(env, 4); /* and */
    if (v213 == v212) goto v113;
    v212 = elt(env, 2); /* false */
    { popv(6); return onevalue(v212); }

v113:
    v212 = elt(env, 1); /* true */
    { popv(6); return onevalue(v212); }

v154:
    v212 = qvalue(elt(env, 9)); /* nil */
    goto v58;

v109:
    v213 = v212;
    goto v164;
/* error exit handlers */
v221:
    popv(6);
    return nil;
}



/* Code for vdp_make */

static Lisp_Object MS_CDECL CC_vdp_make(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v81, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152, v159, v164;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vdp_make");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_make");
#endif
    if (stack >= stacklimit)
    {
        push3(v81,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v81);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v152 = v81;
    v159 = v1;
    v164 = v0;
/* end of prologue */
    stack[-2] = elt(env, 1); /* vdp */
    stack[-1] = v159;
    stack[0] = v164;
    v159 = v152;
    v152 = qvalue(elt(env, 2)); /* nil */
    v152 = list2(v159, v152);
    nil = C_nil;
    if (exception_pending()) goto v150;
    {
        Lisp_Object v162 = stack[-2];
        Lisp_Object v11 = stack[-1];
        Lisp_Object v12 = stack[0];
        popv(3);
        return list3star(v162, v11, v12, v152);
    }
/* error exit handlers */
v150:
    popv(3);
    return nil;
}



/* Code for matrixom */

static Lisp_Object CC_matrixom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157;
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
    v157 = elt(env, 1); /* "<OMA>" */
    fn = elt(env, 6); /* printout */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-1];
    v157 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 7); /* indent!* */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-1];
    v157 = elt(env, 3); /* "<OMS cd=""linalg1"" name=""matrix""/>" */
    fn = elt(env, 6); /* printout */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-1];
    v157 = stack[0];
    v157 = qcdr(v157);
    v157 = qcdr(v157);
    v157 = qcdr(v157);
    v157 = qcar(v157);
    fn = elt(env, 8); /* matrixrowom */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-1];
    v157 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 7); /* indent!* */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-1];
    v157 = elt(env, 5); /* "</OMA>" */
    fn = elt(env, 6); /* printout */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v13;
    v157 = nil;
    { popv(2); return onevalue(v157); }
/* error exit handlers */
v13:
    popv(2);
    return nil;
}



/* Code for splitcomplex */

static Lisp_Object CC_splitcomplex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v105;
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
    v105 = qvalue(elt(env, 1)); /* kord!* */
    v73 = qvalue(elt(env, 2)); /* t */
    stack[-4] = qvalue(elt(env, 1)); /* kord!* */
    qvalue(elt(env, 1)) = v105; /* kord!* */
    stack[-3] = qvalue(elt(env, 3)); /* !*exp */
    qvalue(elt(env, 3)) = v73; /* !*exp */
    v105 = elt(env, 4); /* i */
    v73 = elt(env, 5); /* idvalfn */
    v73 = get(v105, v73);
    env = stack[-5];
    if (v73 == nil) goto v142;
    v73 = stack[0];
    fn = elt(env, 6); /* expand!-imrepart */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    goto v141;

v141:
    stack[-2] = v73;
    v73 = stack[-2];
    v73 = qcar(v73);
    fn = elt(env, 7); /* repartf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    v73 = stack[-2];
    stack[0] = qcdr(v73);
    v73 = stack[-2];
    v73 = qcar(v73);
    fn = elt(env, 8); /* impartf */
    v105 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    v73 = stack[-2];
    v73 = qcdr(v73);
    v73 = cons(v105, v73);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    v73 = acons(stack[-1], stack[0], v73);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    qvalue(elt(env, 3)) = stack[-3]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-4]; /* kord!* */
    { popv(6); return onevalue(v73); }

v142:
    v105 = elt(env, 4); /* i */
    v73 = stack[0];
    v73 = Lsmemq(nil, v105, v73);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    if (v73 == nil) goto v159;
    v105 = elt(env, 4); /* i */
    v73 = qvalue(elt(env, 1)); /* kord!* */
    v73 = cons(v105, v73);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    fn = elt(env, 9); /* setkorder */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    v73 = stack[0];
    fn = elt(env, 10); /* reorder */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    stack[0] = v73;
    goto v159;

v159:
    v73 = stack[0];
    fn = elt(env, 6); /* expand!-imrepart */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    fn = elt(env, 11); /* subs2 */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-5];
    goto v141;
/* error exit handlers */
v60:
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
    Lisp_Object v10, v20, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcompatible");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v20 = v1;
    v152 = v0;
/* end of prologue */
    v10 = qvalue(elt(env, 1)); /* gmodule!* */
    v10 = (v10 == nil ? lisp_true : nil);
    if (!(v10 == nil)) return onevalue(v10);
    v10 = v152;
    v10 = qcdr(v10);
    v152 = qcar(v10);
    v10 = v20;
    v10 = qcdr(v10);
    v20 = qcar(v10);
    v10 = qvalue(elt(env, 1)); /* gmodule!* */
    {
        fn = elt(env, 2); /* gevcompatible1 */
        return (*qfnn(fn))(qenv(fn), 3, v152, v20, v10);
    }
}



/* Code for subs2p */

static Lisp_Object MS_CDECL CC_subs2p(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v81, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v178, v154, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subs2p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2p");
#endif
    if (stack >= stacklimit)
    {
        push3(v81,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v81);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v81;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v178 = stack[-2];
    v178 = qcdr(v178);
    v178 = integerp(v178);
    if (v178 == nil) goto v70;
    v178 = stack[-2];
    v154 = qcdr(v178);
    v178 = stack[-1];
    v178 = Ldivide(nil, v154, v178);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-3];
    stack[-1] = v178;
    v154 = qcar(v178);
    v178 = (Lisp_Object)1; /* 0 */
    if (v154 == v178) goto v70;
    v178 = stack[0];
    fn = elt(env, 1); /* simp */
    v154 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-3];
    v178 = stack[-1];
    v178 = qcar(v178);
    fn = elt(env, 2); /* exptsq */
    v178 = (*qfn2(fn))(qenv(fn), v154, v178);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-3];
    stack[0] = v178;
    v178 = stack[-1];
    v154 = qcdr(v178);
    v178 = (Lisp_Object)1; /* 0 */
    if (v154 == v178) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v178 = stack[-2];
    v55 = qcar(v178);
    v178 = stack[-1];
    v154 = qcdr(v178);
    v178 = (Lisp_Object)17; /* 1 */
    v178 = acons(v55, v154, v178);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-3];
    v154 = ncons(v178);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-3];
    v178 = (Lisp_Object)17; /* 1 */
    v154 = cons(v154, v178);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-3];
    v178 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* multsq */
        return (*qfn2(fn))(qenv(fn), v154, v178);
    }

v70:
    v154 = stack[-2];
    v178 = (Lisp_Object)17; /* 1 */
    v178 = cons(v154, v178);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-3];
    v154 = ncons(v178);
    nil = C_nil;
    if (exception_pending()) goto v168;
    v178 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v154, v178);
/* error exit handlers */
v168:
    popv(4);
    return nil;
}



/* Code for vdp2a */

static Lisp_Object CC_vdp2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v89 = v0;
/* end of prologue */
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v89 = qcar(v89);
    {
        fn = elt(env, 1); /* dip2a */
        return (*qfn1(fn))(qenv(fn), v89);
    }
}



/* Code for weak_xreduce1 */

static Lisp_Object MS_CDECL CC_weak_xreduce1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v81, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v67, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "weak_xreduce1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for weak_xreduce1");
#endif
    if (stack >= stacklimit)
    {
        push3(v81,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v81);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v81;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v34 = stack[-4];
    stack[0] = v34;
    goto v15;

v15:
    v34 = stack[-5];
    if (v34 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v34 = stack[0];
    if (v34 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v34 = stack[0];
    v34 = qcar(v34);
    stack[-6] = v34;
    v34 = stack[0];
    v34 = qcdr(v34);
    stack[0] = v34;
    v34 = stack[-6];
    fn = elt(env, 8); /* xval */
    stack[-1] = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    v34 = stack[-5];
    fn = elt(env, 8); /* xval */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    fn = elt(env, 9); /* xdiv */
    v34 = (*qfn2(fn))(qenv(fn), stack[-1], v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    stack[-1] = v34;
    if (v34 == nil) goto v15;
    v34 = stack[-1];
    fn = elt(env, 10); /* mknwedge */
    v68 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    v67 = (Lisp_Object)17; /* 1 */
    v34 = (Lisp_Object)17; /* 1 */
    v34 = list2star(v68, v67, v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    v34 = ncons(v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    stack[-1] = v34;
    v67 = stack[-1];
    v34 = stack[-6];
    fn = elt(env, 11); /* wedgepf */
    v34 = (*qfn2(fn))(qenv(fn), v67, v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    stack[0] = v34;
    v34 = stack[-5];
    v34 = qcar(v34);
    stack[-2] = qcdr(v34);
    v34 = stack[0];
    v34 = qcar(v34);
    v34 = qcdr(v34);
    fn = elt(env, 12); /* invsq */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    fn = elt(env, 13); /* multsq */
    v34 = (*qfn2(fn))(qenv(fn), stack[-2], v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    stack[-2] = v34;
    v34 = stack[-2];
    v34 = qcar(v34);
    fn = elt(env, 14); /* negf */
    v67 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    v34 = stack[-2];
    v34 = qcdr(v34);
    v34 = cons(v67, v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    fn = elt(env, 15); /* multpfsq */
    v34 = (*qfn2(fn))(qenv(fn), stack[0], v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    fn = elt(env, 16); /* addpf */
    v34 = (*qfn2(fn))(qenv(fn), stack[-5], v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    fn = elt(env, 17); /* subs2pf */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    stack[-5] = v34;
    v34 = qvalue(elt(env, 2)); /* !*trxmod */
    if (v34 == nil) goto v231;
    stack[0] = stack[-3];
    v67 = stack[-1];
    v34 = stack[-2];
    fn = elt(env, 15); /* multpfsq */
    v67 = (*qfn2(fn))(qenv(fn), v67, v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    v34 = stack[-6];
    v34 = list2(v67, v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    v34 = ncons(v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    v34 = Lnconc(nil, stack[0], v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    stack[-3] = v34;
    goto v231;

v231:
    v34 = qvalue(elt(env, 2)); /* !*trxmod */
    if (v34 == nil) goto v76;
    v34 = elt(env, 3); /* "   " */
    fn = elt(env, 18); /* eval */
    v68 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    v67 = qvalue(elt(env, 1)); /* nil */
    v34 = elt(env, 4); /* first */
    fn = elt(env, 19); /* assgnpri */
    v34 = (*qfnn(fn))(qenv(fn), 3, v68, v67, v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    stack[0] = elt(env, 5); /* wedge */
    v67 = stack[-1];
    v34 = stack[-2];
    fn = elt(env, 15); /* multpfsq */
    v34 = (*qfn2(fn))(qenv(fn), v67, v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    fn = elt(env, 20); /* preppf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    v34 = stack[-6];
    fn = elt(env, 20); /* preppf */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    v34 = list3(stack[0], stack[-1], v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    v34 = Lmkquote(nil, v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    fn = elt(env, 18); /* eval */
    v68 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    v67 = qvalue(elt(env, 1)); /* nil */
    v34 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 19); /* assgnpri */
    v34 = (*qfnn(fn))(qenv(fn), 3, v68, v67, v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    v34 = elt(env, 6); /* " +" */
    fn = elt(env, 18); /* eval */
    v68 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    v67 = qvalue(elt(env, 1)); /* nil */
    v34 = elt(env, 7); /* last */
    fn = elt(env, 19); /* assgnpri */
    v34 = (*qfnn(fn))(qenv(fn), 3, v68, v67, v34);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-7];
    goto v76;

v76:
    v34 = stack[-4];
    stack[0] = v34;
    goto v15;
/* error exit handlers */
v230:
    popv(8);
    return nil;
}



/* Code for mkprec */

static Lisp_Object MS_CDECL CC_mkprec(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v75, v93;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mkprec");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkprec");
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
    v75 = qvalue(elt(env, 1)); /* fixedpreclis!* */
    v153 = qvalue(elt(env, 2)); /* preclis!* */
    v153 = Lappend(nil, v75, v153);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    stack[-3] = v153;
    v153 = (Lisp_Object)17; /* 1 */
    stack[-2] = v153;
    goto v119;

v119:
    v153 = stack[-3];
    if (v153 == nil) goto v66;
    v153 = stack[-3];
    v93 = qcar(v153);
    v75 = elt(env, 4); /* infix */
    v153 = stack[-2];
    v153 = Lputprop(nil, 3, v93, v75, v153);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v153 = stack[-3];
    stack[-1] = qcar(v153);
    stack[0] = elt(env, 5); /* op */
    v75 = stack[-2];
    v153 = stack[-2];
    v153 = list2(v75, v153);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v153 = ncons(v153);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v153 = Lputprop(nil, 3, stack[-1], stack[0], v153);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v153 = stack[-3];
    v75 = qcar(v153);
    v153 = elt(env, 6); /* unary */
    v153 = get(v75, v153);
    env = stack[-4];
    stack[0] = v153;
    if (v153 == nil) goto v5;
    v93 = stack[0];
    v75 = elt(env, 4); /* infix */
    v153 = stack[-2];
    v153 = Lputprop(nil, 3, v93, v75, v153);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    goto v5;

v5:
    v153 = stack[0];
    if (v153 == nil) goto v24;
    v75 = stack[0];
    v153 = elt(env, 7); /* nary */
    v153 = Lflagp(nil, v75, v153);
    env = stack[-4];
    if (!(v153 == nil)) goto v24;
    stack[-1] = stack[0];
    stack[0] = elt(env, 5); /* op */
    v75 = qvalue(elt(env, 3)); /* nil */
    v153 = stack[-2];
    v153 = list2(v75, v153);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v153 = Lputprop(nil, 3, stack[-1], stack[0], v153);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    goto v24;

v24:
    v153 = stack[-3];
    v153 = qcdr(v153);
    stack[-3] = v153;
    v153 = stack[-2];
    v153 = add1(v153);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    stack[-2] = v153;
    goto v119;

v66:
    v153 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v153); }
/* error exit handlers */
v52:
    popv(5);
    return nil;
}



/* Code for ev!-denom2 */

static Lisp_Object CC_evKdenom2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev-denom2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v134 = v1;
    v25 = v0;
/* end of prologue */
    v25 = qcar(v25);
    {
        fn = elt(env, 1); /* ev!-edgeloop */
        return (*qfn2(fn))(qenv(fn), v25, v134);
    }
}



/* Code for mv!-compact2 */

static Lisp_Object CC_mvKcompact2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v106, v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-compact2");
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
    v106 = stack[-1];
    v148 = stack[0];
    fn = elt(env, 2); /* equiv!-coeffs */
    v148 = (*qfn2(fn))(qenv(fn), v106, v148);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-3];
    stack[-2] = v148;
    v148 = stack[0];
    fn = elt(env, 3); /* mv!-domainlist */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-3];
    v106 = stack[-2];
    fn = elt(env, 4); /* reduce */
    v148 = (*qfn2(fn))(qenv(fn), v106, v148);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-3];
    v84 = v148;
    v106 = v84;
    v148 = stack[-2];
    if (equal(v106, v148)) goto v109;
    v106 = v84;
    v148 = stack[-2];
    fn = elt(env, 5); /* mv!-domainlist!-!- */
    v148 = (*qfn2(fn))(qenv(fn), v106, v148);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-3];
    fn = elt(env, 6); /* mv!-coeff!-replace */
    v106 = (*qfn2(fn))(qenv(fn), stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-3];
    v148 = stack[-1];
    {
        popv(4);
        fn = elt(env, 7); /* mv!-!+ */
        return (*qfn2(fn))(qenv(fn), v106, v148);
    }

v109:
    v148 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v148); }
/* error exit handlers */
v4:
    popv(4);
    return nil;
}



/* Code for redall */

static Lisp_Object MS_CDECL CC_redall(Lisp_Object env, int nargs,
                         Lisp_Object v1, Lisp_Object v81,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v242, v243, v244;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "redall");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for redall");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v81,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v1,v81,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v38;
    v243 = v81;
    v242 = v1;
/* end of prologue */
    stack[-8] = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = nil; /* gg */
    qvalue(elt(env, 1)) = v242; /* gg */
    v242 = v243;
    stack[-6] = v242;
    v242 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v242; /* shortway */
    qvalue(elt(env, 4)) = v242; /* thirdway */
    v242 = qvalue(elt(env, 5)); /* t */
    stack[-1] = v242;
    goto v13;

v13:
    v242 = stack[-6];
    if (v242 == nil) goto v91;
    v242 = stack[-6];
    v242 = Lreverse(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    v242 = qcar(v242);
    stack[-5] = v242;
    v243 = stack[-5];
    v242 = stack[-6];
    v242 = Ldelete(nil, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    stack[-6] = v242;
    v242 = stack[-5];
    v242 = qcar(v242);
    stack[-2] = v242;
    v243 = qvalue(elt(env, 6)); /* gv */
    v242 = stack[-2];
    v242 = *(Lisp_Object *)((char *)v243 + (CELL-TAG_VECTOR) + ((int32_t)v242/(16/CELL)));
    stack[-4] = v242;
    v242 = qvalue(elt(env, 7)); /* path */
    if (v242 == nil) goto v73;
    v242 = stack[-1];
    if (v242 == nil) goto v128;
    v242 = stack[-4];
    fn = elt(env, 12); /* ljet */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    v242 = Lprinc(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    v242 = elt(env, 8); /* " ==> " */
    v242 = Lprinc(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    goto v73;

v73:
    stack[-3] = qvalue(elt(env, 6)); /* gv */
    stack[0] = stack[-2];
    v244 = stack[-4];
    v243 = qvalue(elt(env, 1)); /* gg */
    v242 = stack[-7];
    fn = elt(env, 13); /* nf */
    v242 = (*qfnn(fn))(qenv(fn), 3, v244, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v242;
    stack[-5] = v242;
    v242 = stack[-5];
    if (v242 == nil) goto v55;
    v242 = stack[-5];
    fn = elt(env, 12); /* ljet */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    goto v224;

v224:
    stack[-3] = v242;
    v242 = qvalue(elt(env, 7)); /* path */
    if (v242 == nil) goto v168;
    v242 = stack[-3];
    v242 = Lprinc(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    v242 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    goto v168;

v168:
    v242 = stack[-5];
    if (v242 == nil) goto v13;
    v242 = stack[-3];
    fn = elt(env, 14); /* ord */
    v243 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    v242 = (Lisp_Object)1; /* 0 */
    if (v243 == v242) goto v130;
    v242 = stack[-5];
    fn = elt(env, 12); /* ljet */
    stack[0] = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    v242 = stack[-4];
    fn = elt(env, 12); /* ljet */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    if (equal(stack[0], v242)) goto v48;
    v242 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 3)) = v242; /* shortway */
    goto v48;

v48:
    v242 = stack[-1];
    if (!(v242 == nil)) goto v97;
    v243 = stack[-5];
    v242 = stack[-4];
    if (equal(v243, v242)) goto v97;
    v242 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 4)) = v242; /* thirdway */
    goto v97;

v97:
    v242 = qvalue(elt(env, 1)); /* gg */
    stack[-4] = v242;
    goto v176;

v176:
    v242 = stack[-4];
    if (v242 == nil) goto v246;
    v242 = stack[-4];
    v242 = qcar(v242);
    stack[-1] = v242;
    v243 = stack[-3];
    v242 = stack[-1];
    v242 = qcdr(v242);
    fn = elt(env, 15); /* dd */
    stack[0] = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    v243 = stack[-7];
    v242 = (Lisp_Object)33; /* 2 */
    v242 = plus2(v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    v242 = (Lisp_Object)geq2(stack[0], v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    v242 = v242 ? lisp_true : nil;
    env = stack[-9];
    if (v242 == nil) goto v208;
    v243 = stack[-1];
    v242 = qvalue(elt(env, 1)); /* gg */
    v242 = Ldelete(nil, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    qvalue(elt(env, 1)) = v242; /* gg */
    v243 = stack[-1];
    v242 = stack[-6];
    fn = elt(env, 16); /* insert */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    stack[-6] = v242;
    v244 = qvalue(elt(env, 11)); /* bv */
    v242 = stack[-1];
    v243 = qcar(v242);
    v242 = qvalue(elt(env, 5)); /* t */
    *(Lisp_Object *)((char *)v244 + (CELL-TAG_VECTOR) + ((int32_t)v243/(16/CELL))) = v242;
    goto v208;

v208:
    v242 = stack[-4];
    v242 = qcdr(v242);
    stack[-4] = v242;
    goto v176;

v246:
    v243 = stack[-2];
    v242 = stack[-3];
    v243 = cons(v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    v242 = qvalue(elt(env, 1)); /* gg */
    fn = elt(env, 16); /* insert */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    qvalue(elt(env, 1)) = v242; /* gg */
    v242 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v242;
    goto v13;

v130:
    v243 = stack[-5];
    v242 = qvalue(elt(env, 10)); /* conds */
    v242 = cons(v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    qvalue(elt(env, 10)) = v242; /* conds */
    goto v13;

v55:
    v242 = (Lisp_Object)1; /* 0 */
    goto v224;

v128:
    v242 = stack[-4];
    fn = elt(env, 12); /* ljet */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    v242 = Lprinc(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    v242 = elt(env, 9); /* " --> " */
    v242 = Lprinc(nil, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-9];
    goto v73;

v91:
    v242 = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = stack[-8]; /* gg */
    { popv(10); return onevalue(v242); }
/* error exit handlers */
v245:
    env = stack[-9];
    qvalue(elt(env, 1)) = stack[-8]; /* gg */
    popv(10);
    return nil;
}



setup_type const u32_setup[] =
{
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
    {"weak_xreduce1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_weak_xreduce1},
    {"mkprec",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkprec},
    {"ev-denom2",               too_few_2,      CC_evKdenom2,  wrong_no_2},
    {"mv-compact2",             too_few_2,      CC_mvKcompact2,wrong_no_2},
    {"redall",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_redall},
    {NULL, (one_args *)"u32", (two_args *)"1225 8005883 5597124", 0}
};

/* end of generated code */
