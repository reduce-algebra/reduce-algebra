
/* $destdir\u38.c        Machine generated C code */

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


/* Code for fs!:subang */

static Lisp_Object MS_CDECL CC_fsTsubang(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v49, v50, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "fs:subang");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:subang");
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
    v48 = stack[-7];
    if (v48 == nil) goto v52;
    v48 = (Lisp_Object)113; /* 7 */
    v48 = Lmkvect(nil, v48);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-9];
    stack[-8] = v48;
    v49 = stack[-7];
    v48 = (Lisp_Object)33; /* 2 */
    v49 = *(Lisp_Object *)((char *)v49 + (CELL-TAG_VECTOR) + ((int32_t)v48/(16/CELL)));
    v48 = stack[-6];
    v48 = *(Lisp_Object *)((char *)v49 + (CELL-TAG_VECTOR) + ((int32_t)v48/(16/CELL)));
    stack[-4] = v48;
    v48 = (Lisp_Object)1; /* 0 */
    stack[-3] = v48;
    goto v54;

v54:
    v49 = (Lisp_Object)113; /* 7 */
    v48 = stack[-3];
    v48 = difference2(v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-9];
    v48 = Lminusp(nil, v48);
    env = stack[-9];
    if (v48 == nil) goto v55;
    v49 = stack[-7];
    v48 = (Lisp_Object)49; /* 3 */
    v50 = *(Lisp_Object *)((char *)v49 + (CELL-TAG_VECTOR) + ((int32_t)v48/(16/CELL)));
    v49 = stack[-6];
    v48 = stack[-5];
    stack[0] = CC_fsTsubang(env, 3, v50, v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-9];
    v49 = stack[-7];
    v48 = (Lisp_Object)17; /* 1 */
    v51 = *(Lisp_Object *)((char *)v49 + (CELL-TAG_VECTOR) + ((int32_t)v48/(16/CELL)));
    v50 = stack[-8];
    v49 = stack[-7];
    v48 = (Lisp_Object)1; /* 0 */
    v48 = *(Lisp_Object *)((char *)v49 + (CELL-TAG_VECTOR) + ((int32_t)v48/(16/CELL)));
    fn = elt(env, 2); /* make!-term */
    v48 = (*qfnn(fn))(qenv(fn), 3, v51, v50, v48);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-9];
    {
        Lisp_Object v56 = stack[0];
        popv(10);
        fn = elt(env, 3); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v56, v48);
    }

v55:
    v49 = stack[-3];
    v48 = stack[-6];
    if (equal(v49, v48)) goto v57;
    stack[-2] = stack[-8];
    stack[-1] = stack[-3];
    v49 = stack[-7];
    v48 = (Lisp_Object)33; /* 2 */
    v49 = *(Lisp_Object *)((char *)v49 + (CELL-TAG_VECTOR) + ((int32_t)v48/(16/CELL)));
    v48 = stack[-3];
    stack[0] = *(Lisp_Object *)((char *)v49 + (CELL-TAG_VECTOR) + ((int32_t)v48/(16/CELL)));
    v50 = stack[-4];
    v49 = stack[-5];
    v48 = stack[-3];
    v48 = *(Lisp_Object *)((char *)v49 + (CELL-TAG_VECTOR) + ((int32_t)v48/(16/CELL)));
    v48 = times2(v50, v48);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-9];
    v48 = plus2(stack[0], v48);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v48;
    goto v58;

v58:
    v48 = stack[-3];
    v48 = add1(v48);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-9];
    stack[-3] = v48;
    goto v54;

v57:
    stack[-1] = stack[-8];
    stack[0] = stack[-3];
    v50 = stack[-4];
    v49 = stack[-5];
    v48 = stack[-3];
    v48 = *(Lisp_Object *)((char *)v49 + (CELL-TAG_VECTOR) + ((int32_t)v48/(16/CELL)));
    v48 = times2(v50, v48);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v48;
    goto v58;

v52:
    v48 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v48); }
/* error exit handlers */
v53:
    popv(10);
    return nil;
}



/* Code for verify_tens_ids */

static Lisp_Object CC_verify_tens_ids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for verify_tens_ids");
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
    v55 = stack[0];
    v55 = qcar(v55);
    v64 = v55;
    v55 = stack[0];
    v55 = qcdr(v55);
    v55 = qcar(v55);
    stack[-1] = v55;
    v55 = v64;
    fn = elt(env, 5); /* extract_dummy_ids */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    fn = elt(env, 6); /* repeats */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    if (!(v55 == nil)) goto v44;
    v55 = stack[-1];
    fn = elt(env, 5); /* extract_dummy_ids */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    fn = elt(env, 6); /* repeats */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    if (!(v55 == nil)) goto v44;
    v55 = qvalue(elt(env, 4)); /* t */
    { popv(3); return onevalue(v55); }

v44:
    v55 = stack[0];
    v64 = qcar(v55);
    v55 = stack[0];
    v55 = qcdr(v55);
    v55 = qcar(v55);
    v64 = list2(v64, v55);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    v55 = elt(env, 1); /* "are inconsistent lists of indices" */
    v55 = list2(v64, v55);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    v64 = v55;
    v55 = v64;
    qvalue(elt(env, 2)) = v55; /* errmsg!* */
    v55 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v55 == nil)) goto v66;
    v55 = v64;
    fn = elt(env, 7); /* lprie */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    goto v66;

v66:
    v55 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v65;
    v55 = nil;
    { popv(3); return onevalue(v55); }
/* error exit handlers */
v65:
    popv(3);
    return nil;
}



/* Code for bndtst */

static Lisp_Object CC_bndtst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bndtst");
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
    v71 = stack[0];
    v71 = qcdr(v71);
    v72 = qcar(v71);
    v71 = (Lisp_Object)1; /* 0 */
    v71 = (Lisp_Object)greaterp2(v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v66;
    v71 = v71 ? lisp_true : nil;
    env = stack[-2];
    if (v71 == nil) goto v73;
    v71 = stack[0];
    v72 = v71;
    goto v74;

v74:
    v71 = qvalue(elt(env, 2)); /* tentothetenth!*!* */
    {
        popv(3);
        fn = elt(env, 3); /* greaterp!: */
        return (*qfn2(fn))(qenv(fn), v72, v71);
    }

v73:
    stack[-1] = elt(env, 1); /* !:rd!: */
    v71 = stack[0];
    v71 = qcdr(v71);
    v71 = qcar(v71);
    v72 = negate(v71);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-2];
    v71 = stack[0];
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v71 = list2star(stack[-1], v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-2];
    v72 = v71;
    goto v74;
/* error exit handlers */
v66:
    popv(3);
    return nil;
}



/* Code for mk_resimp_rep */

static Lisp_Object CC_mk_resimp_rep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_resimp_rep");
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
    stack[-5] = v0;
/* end of prologue */
    v85 = stack[-5];
    fn = elt(env, 2); /* get_group_in */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-7];
    stack[-6] = v85;
    v85 = stack[-6];
    fn = elt(env, 3); /* get!*elements */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-7];
    stack[-4] = v85;
    v85 = stack[-4];
    if (v85 == nil) goto v87;
    v85 = stack[-4];
    v85 = qcar(v85);
    stack[0] = v85;
    v86 = v85;
    v85 = stack[-5];
    fn = elt(env, 4); /* get_rep_matrix_in */
    v85 = (*qfn2(fn))(qenv(fn), v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-7];
    fn = elt(env, 5); /* mk!+resimp!+mat */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-7];
    v85 = list2(stack[0], v85);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-7];
    v85 = ncons(v85);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-7];
    stack[-2] = v85;
    stack[-3] = v85;
    goto v88;

v88:
    v85 = stack[-4];
    v85 = qcdr(v85);
    stack[-4] = v85;
    v85 = stack[-4];
    if (v85 == nil) goto v89;
    stack[-1] = stack[-2];
    v85 = stack[-4];
    v85 = qcar(v85);
    stack[0] = v85;
    v86 = v85;
    v85 = stack[-5];
    fn = elt(env, 4); /* get_rep_matrix_in */
    v85 = (*qfn2(fn))(qenv(fn), v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-7];
    fn = elt(env, 5); /* mk!+resimp!+mat */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-7];
    v85 = list2(stack[0], v85);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-7];
    v85 = ncons(v85);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-7];
    v85 = Lrplacd(nil, stack[-1], v85);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-7];
    v85 = stack[-2];
    v85 = qcdr(v85);
    stack[-2] = v85;
    goto v88;

v89:
    v85 = stack[-3];
    goto v28;

v28:
    stack[0] = v85;
    v85 = stack[-6];
    v86 = ncons(v85);
    nil = C_nil;
    if (exception_pending()) goto v20;
    v85 = stack[0];
        popv(8);
        return Lappend(nil, v86, v85);

v87:
    v85 = qvalue(elt(env, 1)); /* nil */
    goto v28;
/* error exit handlers */
v20:
    popv(8);
    return nil;
}



/* Code for cl_gand!-col */

static Lisp_Object MS_CDECL CC_cl_gandKcol(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v110, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_gand-col");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_gand-col");
#endif
    if (stack >= stacklimit)
    {
        push4(v63,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v63);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v63;
    stack[-5] = v2;
    stack[-6] = v1;
    stack[-7] = v0;
/* end of prologue */
    stack[-8] = nil;
    v111 = elt(env, 1); /* true */
    v110 = stack[-5];
    v109 = elt(env, 2); /* and */
    v109 = (v110 == v109 ? lisp_true : nil);
    fn = elt(env, 5); /* cl_cflip */
    v109 = (*qfn2(fn))(qenv(fn), v111, v109);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    stack[-3] = v109;
    v109 = stack[-3];
    fn = elt(env, 6); /* cl_flip */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    stack[-2] = v109;
    goto v44;

v44:
    v109 = stack[-7];
    if (v109 == nil) goto v47;
    v109 = stack[-7];
    stack[-1] = qcar(v109);
    stack[0] = stack[-4];
    v109 = stack[-6];
    v110 = sub1(v109);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    v109 = stack[-5];
    fn = elt(env, 7); /* cl_simpl1 */
    v109 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    v111 = v109;
    v109 = stack[-7];
    v109 = qcdr(v109);
    stack[-7] = v109;
    v110 = v111;
    v109 = stack[-2];
    if (v110 == v109) goto v64;
    v110 = v111;
    v109 = stack[-3];
    if (equal(v110, v109)) goto v44;
    v109 = v111;
    if (!consp(v109)) goto v85;
    v109 = v111;
    v109 = qcar(v109);
    v110 = v109;
    goto v38;

v38:
    v109 = stack[-5];
    if (v110 == v109) goto v113;
    v109 = qvalue(elt(env, 4)); /* !*rlsichk */
    if (v109 == nil) goto v114;
    v110 = v111;
    v109 = stack[-8];
    v109 = Lmember(nil, v110, v109);
    if (!(v109 == nil)) goto v44;

v114:
    v110 = v111;
    v109 = stack[-8];
    v109 = cons(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    stack[-8] = v109;
    goto v44;

v113:
    v109 = qvalue(elt(env, 4)); /* !*rlsichk */
    if (v109 == nil) goto v115;
    v109 = v111;
    v109 = qcdr(v109);
    stack[0] = v109;
    goto v116;

v116:
    v109 = stack[0];
    if (v109 == nil) goto v44;
    v109 = stack[0];
    v109 = qcar(v109);
    v111 = v109;
    v110 = v111;
    v109 = stack[-8];
    v109 = Lmember(nil, v110, v109);
    if (!(v109 == nil)) goto v23;
    v110 = v111;
    v109 = stack[-8];
    v109 = cons(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    stack[-8] = v109;
    goto v23;

v23:
    v109 = stack[0];
    v109 = qcdr(v109);
    stack[0] = v109;
    goto v116;

v115:
    v109 = v111;
    v109 = qcdr(v109);
    stack[0] = v109;
    goto v117;

v117:
    v109 = stack[0];
    if (v109 == nil) goto v44;
    v109 = stack[0];
    v109 = qcar(v109);
    v110 = v109;
    v109 = stack[-8];
    v109 = cons(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    stack[-8] = v109;
    v109 = stack[0];
    v109 = qcdr(v109);
    stack[0] = v109;
    goto v117;

v85:
    v109 = v111;
    v110 = v109;
    goto v38;

v64:
    v109 = stack[-2];
    v109 = ncons(v109);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    stack[-8] = v109;
    v109 = qvalue(elt(env, 3)); /* nil */
    stack[-7] = v109;
    goto v44;

v47:
    v109 = stack[-8];
    if (v109 == nil) goto v118;
    v109 = stack[-8];
        popv(10);
        return Lnreverse(nil, v109);

v118:
    v109 = stack[-3];
    popv(10);
    return ncons(v109);
/* error exit handlers */
v112:
    popv(10);
    return nil;
}



/* Code for factorf */

static Lisp_Object CC_factorf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v147, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for factorf");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0;
/* end of prologue */
    v146 = qvalue(elt(env, 1)); /* current!-modulus */
    stack[-7] = qvalue(elt(env, 1)); /* current!-modulus */
    qvalue(elt(env, 1)) = v146; /* current!-modulus */
    stack[-6] = qvalue(elt(env, 2)); /* m!-image!-variable */
    qvalue(elt(env, 2)) = nil; /* m!-image!-variable */
    stack[-4] = nil;
    v146 = stack[-3];
    if (!consp(v146)) goto v88;
    v146 = stack[-3];
    v146 = qcar(v146);
    if (!consp(v146)) goto v88;
    v147 = stack[-3];
    v146 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 12); /* kernord */
    v146 = (*qfn2(fn))(qenv(fn), v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v147 = v146;
    v146 = qvalue(elt(env, 4)); /* !*kernreverse */
    if (v146 == nil) goto v150;
    v146 = v147;
    v146 = Lreverse(nil, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v147 = v146;
    goto v150;

v150:
    v146 = v147;
    fn = elt(env, 13); /* setkorder */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    stack[-5] = v146;
    v146 = stack[-3];
    fn = elt(env, 14); /* reorder */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    stack[-3] = v146;
    v146 = stack[-3];
    fn = elt(env, 15); /* minusf */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    if (v146 == nil) goto v72;
    v146 = stack[-4];
    v146 = (v146 == nil ? lisp_true : nil);
    stack[-4] = v146;
    v146 = stack[-3];
    fn = elt(env, 16); /* negf */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    stack[-3] = v146;
    goto v72;

v72:
    v146 = stack[-3];
    fn = elt(env, 17); /* comfac */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    stack[-2] = v146;
    v147 = stack[-3];
    v146 = stack[-2];
    v146 = qcdr(v146);
    fn = elt(env, 18); /* quotf1 */
    v146 = (*qfn2(fn))(qenv(fn), v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    stack[-3] = v146;
    v146 = stack[-3];
    if (!consp(v146)) goto v102;
    v146 = stack[-3];
    v146 = qcar(v146);
    if (!(!consp(v146))) goto v101;

v102:
    v146 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 19); /* terpri!* */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v146 = elt(env, 6); /* "CATASTROPHIC ERROR *****" */
    fn = elt(env, 20); /* lprie */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v146 = elt(env, 7); /* "Improper factors in factorf" */
    v146 = ncons(v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    fn = elt(env, 21); /* printty */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v147 = elt(env, 8); /* " " */
    v146 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 22); /* lpriw */
    v146 = (*qfn2(fn))(qenv(fn), v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v146 = elt(env, 9); /* "Please report output and input listing on the sourceforge bug tracker" 
*/
    v147 = v146;
    v146 = v147;
    qvalue(elt(env, 10)) = v146; /* errmsg!* */
    v146 = qvalue(elt(env, 11)); /* !*protfg */
    if (!(v146 == nil)) goto v151;
    v146 = v147;
    fn = elt(env, 20); /* lprie */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    goto v151;

v151:
    v146 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    goto v101;

v101:
    v146 = stack[-2];
    v146 = qcar(v146);
    stack[-1] = v146;
    v146 = stack[-2];
    v146 = qcdr(v146);
    fn = elt(env, 23); /* fctrf1 */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    stack[-2] = v146;
    v146 = stack[-1];
    if (v146 == nil) goto v152;
    v146 = stack[-2];
    stack[0] = qcar(v146);
    v146 = stack[-1];
    v148 = qcar(v146);
    v147 = (Lisp_Object)17; /* 1 */
    v146 = (Lisp_Object)17; /* 1 */
    v146 = acons(v148, v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v147 = ncons(v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v146 = stack[-1];
    v146 = qcdr(v146);
    v147 = cons(v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v146 = stack[-2];
    v146 = qcdr(v146);
    v146 = list2star(stack[0], v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    stack[-2] = v146;
    goto v152;

v152:
    v146 = stack[-3];
    v146 = qcar(v146);
    v146 = qcar(v146);
    v146 = qcar(v146);
    qvalue(elt(env, 2)) = v146; /* m!-image!-variable */
    v146 = stack[-3];
    fn = elt(env, 24); /* factorize!-primitive!-polynomial */
    v147 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v146 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 25); /* distribute!.multiplicity */
    v146 = (*qfn2(fn))(qenv(fn), v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    stack[-3] = v146;
    v146 = stack[-5];
    fn = elt(env, 13); /* setkorder */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v146 = stack[-4];
    if (v146 == nil) goto v9;
    v146 = stack[-3];
    v146 = qcar(v146);
    v146 = qcar(v146);
    fn = elt(env, 16); /* negf */
    v148 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v146 = stack[-3];
    v146 = qcar(v146);
    v147 = qcdr(v146);
    v146 = stack[-3];
    v146 = qcdr(v146);
    v146 = acons(v148, v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    stack[-3] = v146;
    goto v9;

v9:
    v147 = (Lisp_Object)17; /* 1 */
    v146 = stack[-3];
    v146 = cons(v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    stack[-1] = v146;
    v146 = stack[-2];
    v147 = qcar(v146);
    v146 = stack[-1];
    v146 = qcar(v146);
    fn = elt(env, 26); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v146 = stack[-2];
    v147 = qcdr(v146);
    v146 = stack[-1];
    v146 = qcdr(v146);
    v146 = Lappend(nil, v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v146 = cons(stack[0], v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    stack[-3] = v146;
    v146 = stack[-3];
    stack[-5] = qcar(v146);
    v146 = stack[-3];
    v146 = qcdr(v146);
    stack[-4] = v146;
    v146 = stack[-4];
    if (v146 == nil) goto v153;
    v146 = stack[-4];
    v146 = qcar(v146);
    stack[0] = v146;
    v146 = stack[0];
    v146 = qcar(v146);
    fn = elt(env, 14); /* reorder */
    v147 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v146 = stack[0];
    v146 = qcdr(v146);
    v146 = cons(v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v146 = ncons(v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    stack[-2] = v146;
    stack[-3] = v146;
    goto v154;

v154:
    v146 = stack[-4];
    v146 = qcdr(v146);
    stack[-4] = v146;
    v146 = stack[-4];
    if (v146 == nil) goto v155;
    stack[-1] = stack[-2];
    v146 = stack[-4];
    v146 = qcar(v146);
    stack[0] = v146;
    v146 = stack[0];
    v146 = qcar(v146);
    fn = elt(env, 14); /* reorder */
    v147 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v146 = stack[0];
    v146 = qcdr(v146);
    v146 = cons(v147, v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v146 = ncons(v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v146 = Lrplacd(nil, stack[-1], v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    v146 = stack[-2];
    v146 = qcdr(v146);
    stack[-2] = v146;
    goto v154;

v155:
    v146 = stack[-3];
    goto v156;

v156:
    v146 = cons(stack[-5], v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    goto v83;

v83:
    qvalue(elt(env, 2)) = stack[-6]; /* m!-image!-variable */
    qvalue(elt(env, 1)) = stack[-7]; /* current!-modulus */
    { popv(9); return onevalue(v146); }

v153:
    v146 = qvalue(elt(env, 3)); /* nil */
    goto v156;

v88:
    v146 = stack[-3];
    v146 = ncons(v146);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-8];
    goto v83;
/* error exit handlers */
v149:
    env = stack[-8];
    qvalue(elt(env, 2)) = stack[-6]; /* m!-image!-variable */
    qvalue(elt(env, 1)) = stack[-7]; /* current!-modulus */
    popv(9);
    return nil;
}



/* Code for intervalrd */

static Lisp_Object MS_CDECL CC_intervalrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "intervalrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intervalrd");
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
    fn = elt(env, 4); /* mathml */
    v159 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    stack[-1] = v159;
    fn = elt(env, 4); /* mathml */
    v159 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    stack[0] = v159;
    fn = elt(env, 5); /* lex */
    v159 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    v160 = qvalue(elt(env, 1)); /* char */
    v159 = elt(env, 2); /* (!/ i n t e r v a l) */
    if (equal(v160, v159)) goto v69;
    v160 = elt(env, 3); /* "</interval>" */
    v159 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 6); /* errorml */
    v159 = (*qfn2(fn))(qenv(fn), v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v59;
    v159 = nil;
    { popv(3); return onevalue(v159); }

v69:
    v160 = stack[-1];
    v159 = stack[0];
    popv(3);
    return list2(v160, v159);
/* error exit handlers */
v59:
    popv(3);
    return nil;
}



/* Code for dipcontevmin */

static Lisp_Object CC_dipcontevmin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v34, v161;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipcontevmin");
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
    v161 = nil;
    goto v67;

v67:
    v35 = stack[-1];
    if (v35 == nil) goto v43;
    v35 = stack[0];
    if (v35 == nil) goto v43;
    v35 = stack[-1];
    v34 = qcar(v35);
    v35 = stack[0];
    v35 = qcar(v35);
    if (((int32_t)(v34)) < ((int32_t)(v35))) goto v73;
    v35 = stack[0];
    v35 = qcar(v35);
    goto v70;

v70:
    v34 = v161;
    v35 = cons(v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    v161 = v35;
    v35 = stack[-1];
    v35 = qcdr(v35);
    stack[-1] = v35;
    v35 = stack[0];
    v35 = qcdr(v35);
    stack[0] = v35;
    goto v67;

v73:
    v35 = stack[-1];
    v35 = qcar(v35);
    goto v70;

v43:
    v35 = v161;
    if (v35 == nil) goto v42;
    v34 = (Lisp_Object)1; /* 0 */
    v35 = v161;
    v35 = qcar(v35);
    if (!(v34 == v35)) goto v42;
    v35 = v161;
    v35 = qcdr(v35);
    v161 = v35;
    goto v43;

v42:
    v35 = v161;
        popv(3);
        return Lnreverse(nil, v35);
/* error exit handlers */
v80:
    popv(3);
    return nil;
}



/* Code for dfdeg */

static Lisp_Object CC_dfdeg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v18;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfdeg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v150 = v1;
    v18 = v0;
/* end of prologue */
    v150 = Lmember(nil, v150, v18);
    v18 = v150;
    if (v150 == nil) goto v74;
    v150 = v18;
    v150 = qcdr(v150);
    if (v150 == nil) goto v162;
    v150 = v18;
    v150 = qcdr(v150);
    v150 = qcar(v150);
    v150 = integerp(v150);
    if (v150 == nil) goto v162;
    v150 = v18;
    v150 = qcdr(v150);
    v150 = qcar(v150);
    return onevalue(v150);

v162:
    v150 = (Lisp_Object)17; /* 1 */
    return onevalue(v150);

v74:
    v150 = (Lisp_Object)1; /* 0 */
    return onevalue(v150);
}



/* Code for flattens1 */

static Lisp_Object CC_flattens1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for flattens1");
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

v76:
    v150 = stack[0];
    if (!consp(v150)) goto v90;
    v150 = stack[0];
    v150 = qcdr(v150);
    if (v150 == nil) goto v46;
    v150 = stack[0];
    v150 = qcar(v150);
    stack[-1] = CC_flattens1(env, v150);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-2];
    v150 = stack[0];
    v150 = qcdr(v150);
    v150 = CC_flattens1(env, v150);
    nil = C_nil;
    if (exception_pending()) goto v157;
    {
        Lisp_Object v61 = stack[-1];
        popv(3);
        return Lappend(nil, v61, v150);
    }

v46:
    v150 = stack[0];
    v150 = qcar(v150);
    stack[0] = v150;
    goto v76;

v90:
    v150 = stack[0];
    popv(3);
    return ncons(v150);
/* error exit handlers */
v157:
    popv(3);
    return nil;
}



/* Code for pst_d1 */

static Lisp_Object MS_CDECL CC_pst_d1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pst_d1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_d1");
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
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v2;
    stack[-11] = v1;
    v175 = v0;
/* end of prologue */
    stack[0] = stack[-10];
    v175 = sub1(v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v175/(16/CELL)));
    stack[-12] = v175;
    v175 = stack[-12];
    if (v175 == nil) goto v70;
    v175 = stack[-12];
    v175 = qcar(v175);
    stack[-6] = v175;
    stack[0] = stack[-10];
    v175 = stack[-11];
    v175 = sub1(v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v175/(16/CELL)));
    stack[-5] = v175;
    v175 = stack[-5];
    if (v175 == nil) goto v89;
    v175 = stack[-5];
    v175 = qcar(v175);
    stack[-1] = v175;
    v175 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v175 = (*qfn2(fn))(qenv(fn), stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = qcar(v175);
    fn = elt(env, 4); /* ordn */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = ncons(v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    stack[-3] = v175;
    stack[-4] = v175;
    goto v157;

v157:
    v175 = stack[-5];
    v175 = qcdr(v175);
    stack[-5] = v175;
    v175 = stack[-5];
    if (v175 == nil) goto v35;
    stack[-2] = stack[-3];
    v175 = stack[-5];
    v175 = qcar(v175);
    stack[-1] = v175;
    v175 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v175 = (*qfn2(fn))(qenv(fn), stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = qcar(v175);
    fn = elt(env, 4); /* ordn */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = ncons(v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = Lrplacd(nil, stack[-2], v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = stack[-3];
    v175 = qcdr(v175);
    stack[-3] = v175;
    goto v157;

v35:
    v175 = stack[-4];
    goto v68;

v68:
    fn = elt(env, 4); /* ordn */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = ncons(v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    stack[-8] = v175;
    stack[-9] = v175;
    goto v82;

v82:
    v175 = stack[-12];
    v175 = qcdr(v175);
    stack[-12] = v175;
    v175 = stack[-12];
    if (v175 == nil) { Lisp_Object res = stack[-9]; popv(14); return onevalue(res); }
    stack[-7] = stack[-8];
    v175 = stack[-12];
    v175 = qcar(v175);
    stack[-6] = v175;
    stack[0] = stack[-10];
    v175 = stack[-11];
    v175 = sub1(v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v175/(16/CELL)));
    stack[-5] = v175;
    v175 = stack[-5];
    if (v175 == nil) goto v96;
    v175 = stack[-5];
    v175 = qcar(v175);
    stack[-1] = v175;
    v175 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v175 = (*qfn2(fn))(qenv(fn), stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = qcar(v175);
    fn = elt(env, 4); /* ordn */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = ncons(v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    stack[-3] = v175;
    stack[-4] = v175;
    goto v24;

v24:
    v175 = stack[-5];
    v175 = qcdr(v175);
    stack[-5] = v175;
    v175 = stack[-5];
    if (v175 == nil) goto v176;
    stack[-2] = stack[-3];
    v175 = stack[-5];
    v175 = qcar(v175);
    stack[-1] = v175;
    v175 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v175 = (*qfn2(fn))(qenv(fn), stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = qcar(v175);
    fn = elt(env, 4); /* ordn */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = ncons(v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = Lrplacd(nil, stack[-2], v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = stack[-3];
    v175 = qcdr(v175);
    stack[-3] = v175;
    goto v24;

v176:
    v175 = stack[-4];
    goto v177;

v177:
    fn = elt(env, 4); /* ordn */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = ncons(v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = Lrplacd(nil, stack[-7], v175);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-13];
    v175 = stack[-8];
    v175 = qcdr(v175);
    stack[-8] = v175;
    goto v82;

v96:
    v175 = qvalue(elt(env, 1)); /* nil */
    goto v177;

v89:
    v175 = qvalue(elt(env, 1)); /* nil */
    goto v68;

v70:
    v175 = qvalue(elt(env, 1)); /* nil */
    { popv(14); return onevalue(v175); }
/* error exit handlers */
v138:
    popv(14);
    return nil;
}



/* Code for rd!:prin */

static Lisp_Object CC_rdTprin(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:prin");
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
    v45 = v0;
/* end of prologue */
    v44 = v45;
    v44 = qcdr(v44);
    if (!consp(v44)) goto v10;
    v44 = v45;
    stack[0] = v44;
    goto v107;

v107:
    v45 = qvalue(elt(env, 1)); /* !:bprec!: */
    v44 = (Lisp_Object)49; /* 3 */
    v44 = difference2(v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    fn = elt(env, 2); /* round!:mt */
    v44 = (*qfn2(fn))(qenv(fn), stack[0], v44);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    fn = elt(env, 3); /* csl_normbf */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 4); /* bfprin0 */
        return (*qfn1(fn))(qenv(fn), v44);
    }

v10:
    v44 = v45;
    v44 = qcdr(v44);
    fn = elt(env, 5); /* fl2bf */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    stack[0] = v44;
    goto v107;
/* error exit handlers */
v18:
    popv(2);
    return nil;
}



/* Code for nextu */

static Lisp_Object CC_nextu(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v34, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nextu");
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
    v34 = v1;
    stack[0] = v0;
/* end of prologue */
    v35 = stack[0];
    if (v35 == nil) goto v74;
    v161 = v34;
    v35 = stack[0];
    v34 = qcar(v35);
    v35 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* subtractinds */
    v35 = (*qfnn(fn))(qenv(fn), 3, v161, v34, v35);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    stack[-1] = v35;
    v35 = stack[-1];
    if (v35 == nil) goto v47;
    v35 = stack[0];
    v35 = qcdr(v35);
    v34 = qcar(v35);
    v35 = stack[-1];
    fn = elt(env, 3); /* evaluatecoeffts */
    v35 = (*qfn2(fn))(qenv(fn), v34, v35);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    v161 = v35;
    v35 = v161;
    if (v35 == nil) goto v181;
    v34 = v161;
    v35 = (Lisp_Object)1; /* 0 */
    if (v34 == v35) goto v181;
    v34 = stack[-1];
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = qcdr(v35);
    popv(3);
    return list2star(v34, v161, v35);

v181:
    v35 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v35); }

v47:
    v35 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v35); }

v74:
    v35 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v35); }
/* error exit handlers */
v80:
    popv(3);
    return nil;
}



/* Code for change!+int!+to!+sq */

static Lisp_Object CC_changeLintLtoLsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v28;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for change+int+to+sq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v10 = v0;
/* end of prologue */
    v28 = v10;
    v10 = (Lisp_Object)17; /* 1 */
    return cons(v28, v10);
}



/* Code for pasf_or */

static Lisp_Object CC_pasf_or(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v218, v219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_or");
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
    v219 = stack[0];
    v218 = elt(env, 1); /* true */
    if (v219 == v218) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v219 = stack[0];
    v218 = elt(env, 2); /* false */
    if (v219 == v218) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v219 = stack[0];
    v218 = elt(env, 1); /* true */
    if (v219 == v218) goto v68;
    v219 = stack[0];
    v218 = elt(env, 2); /* false */
    if (v219 == v218) goto v68;
    v218 = stack[0];
    v218 = qcar(v218);
    v218 = Lconsp(nil, v218);
    env = stack[-2];
    if (v218 == nil) goto v41;
    v218 = stack[0];
    v218 = qcar(v218);
    v218 = qcar(v218);
    v219 = v218;
    goto v47;

v47:
    v218 = elt(env, 3); /* (lessp greaterp leq geq) */
    v218 = Lmemq(nil, v219, v218);
    if (v218 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v218 = stack[0];
    v218 = qcdr(v218);
    v218 = qcar(v218);
    fn = elt(env, 9); /* pasf_deci */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-2];
    stack[-1] = v218;
    v219 = stack[0];
    v218 = elt(env, 1); /* true */
    if (v219 == v218) goto v38;
    v219 = stack[0];
    v218 = elt(env, 2); /* false */
    if (v219 == v218) goto v38;
    v218 = stack[0];
    v218 = qcar(v218);
    v218 = Lconsp(nil, v218);
    env = stack[-2];
    if (v218 == nil) goto v221;
    v218 = stack[0];
    v218 = qcar(v218);
    v218 = qcar(v218);
    v219 = v218;
    goto v222;

v222:
    v218 = elt(env, 4); /* lessp */
    if (!(v219 == v218)) goto v93;
    v218 = stack[-1];
    v219 = qcdr(v218);
    v218 = (Lisp_Object)1; /* 0 */
    v218 = (Lisp_Object)lessp2(v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v220;
    v218 = v218 ? lisp_true : nil;
    env = stack[-2];
    if (v218 == nil) goto v93;
    stack[-1] = elt(env, 5); /* leq */
    v218 = stack[0];
    v218 = qcdr(v218);
    stack[0] = qcar(v218);
    v218 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 10); /* simp */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-2];
    v218 = qcar(v218);
    fn = elt(env, 11); /* addf */
    v218 = (*qfn2(fn))(qenv(fn), stack[0], v218);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-2];
    v219 = qvalue(elt(env, 6)); /* nil */
    {
        Lisp_Object v223 = stack[-1];
        popv(3);
        return list3(v223, v218, v219);
    }

v93:
    v219 = stack[0];
    v218 = elt(env, 1); /* true */
    if (v219 == v218) goto v4;
    v219 = stack[0];
    v218 = elt(env, 2); /* false */
    if (v219 == v218) goto v4;
    v218 = stack[0];
    v218 = qcar(v218);
    v218 = Lconsp(nil, v218);
    env = stack[-2];
    if (v218 == nil) goto v50;
    v218 = stack[0];
    v218 = qcar(v218);
    v218 = qcar(v218);
    v219 = v218;
    goto v16;

v16:
    v218 = elt(env, 5); /* leq */
    if (!(v219 == v218)) goto v224;
    v218 = stack[-1];
    v219 = qcdr(v218);
    v218 = (Lisp_Object)1; /* 0 */
    v218 = (Lisp_Object)greaterp2(v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v220;
    v218 = v218 ? lisp_true : nil;
    env = stack[-2];
    if (v218 == nil) goto v224;
    stack[-1] = elt(env, 4); /* lessp */
    v218 = stack[0];
    v218 = qcdr(v218);
    stack[0] = qcar(v218);
    v218 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 10); /* simp */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-2];
    v218 = qcar(v218);
    fn = elt(env, 12); /* negf */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-2];
    fn = elt(env, 11); /* addf */
    v218 = (*qfn2(fn))(qenv(fn), stack[0], v218);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-2];
    v219 = qvalue(elt(env, 6)); /* nil */
    {
        Lisp_Object v225 = stack[-1];
        popv(3);
        return list3(v225, v218, v219);
    }

v224:
    v219 = stack[0];
    v218 = elt(env, 1); /* true */
    if (v219 == v218) goto v226;
    v219 = stack[0];
    v218 = elt(env, 2); /* false */
    if (v219 == v218) goto v226;
    v218 = stack[0];
    v218 = qcar(v218);
    v218 = Lconsp(nil, v218);
    env = stack[-2];
    if (v218 == nil) goto v227;
    v218 = stack[0];
    v218 = qcar(v218);
    v218 = qcar(v218);
    v219 = v218;
    goto v228;

v228:
    v218 = elt(env, 7); /* greaterp */
    if (!(v219 == v218)) goto v229;
    v218 = stack[-1];
    v219 = qcdr(v218);
    v218 = (Lisp_Object)1; /* 0 */
    v218 = (Lisp_Object)greaterp2(v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v220;
    v218 = v218 ? lisp_true : nil;
    env = stack[-2];
    if (v218 == nil) goto v229;
    stack[-1] = elt(env, 8); /* geq */
    v218 = stack[0];
    v218 = qcdr(v218);
    stack[0] = qcar(v218);
    v218 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 10); /* simp */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-2];
    v218 = qcar(v218);
    fn = elt(env, 12); /* negf */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-2];
    fn = elt(env, 11); /* addf */
    v218 = (*qfn2(fn))(qenv(fn), stack[0], v218);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-2];
    v219 = qvalue(elt(env, 6)); /* nil */
    {
        Lisp_Object v230 = stack[-1];
        popv(3);
        return list3(v230, v218, v219);
    }

v229:
    v219 = stack[0];
    v218 = elt(env, 1); /* true */
    if (v219 == v218) goto v231;
    v219 = stack[0];
    v218 = elt(env, 2); /* false */
    if (v219 == v218) goto v231;
    v218 = stack[0];
    v218 = qcar(v218);
    v218 = Lconsp(nil, v218);
    env = stack[-2];
    if (v218 == nil) goto v232;
    v218 = stack[0];
    v218 = qcar(v218);
    v218 = qcar(v218);
    v219 = v218;
    goto v233;

v233:
    v218 = elt(env, 8); /* geq */
    if (!(v219 == v218)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v218 = stack[-1];
    v219 = qcdr(v218);
    v218 = (Lisp_Object)1; /* 0 */
    v218 = (Lisp_Object)lessp2(v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v220;
    v218 = v218 ? lisp_true : nil;
    env = stack[-2];
    if (v218 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = elt(env, 7); /* greaterp */
    v218 = stack[0];
    v218 = qcdr(v218);
    stack[0] = qcar(v218);
    v218 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 10); /* simp */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-2];
    v218 = qcar(v218);
    fn = elt(env, 11); /* addf */
    v218 = (*qfn2(fn))(qenv(fn), stack[0], v218);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-2];
    v219 = qvalue(elt(env, 6)); /* nil */
    {
        Lisp_Object v234 = stack[-1];
        popv(3);
        return list3(v234, v218, v219);
    }

v232:
    v218 = stack[0];
    v218 = qcar(v218);
    v219 = v218;
    goto v233;

v231:
    v218 = stack[0];
    v219 = v218;
    goto v233;

v227:
    v218 = stack[0];
    v218 = qcar(v218);
    v219 = v218;
    goto v228;

v226:
    v218 = stack[0];
    v219 = v218;
    goto v228;

v50:
    v218 = stack[0];
    v218 = qcar(v218);
    v219 = v218;
    goto v16;

v4:
    v218 = stack[0];
    v219 = v218;
    goto v16;

v221:
    v218 = stack[0];
    v218 = qcar(v218);
    v219 = v218;
    goto v222;

v38:
    v218 = stack[0];
    v219 = v218;
    goto v222;

v41:
    v218 = stack[0];
    v218 = qcar(v218);
    v219 = v218;
    goto v47;

v68:
    v218 = stack[0];
    v219 = v218;
    goto v47;
/* error exit handlers */
v220:
    popv(3);
    return nil;
}



/* Code for ratpoly_red */

static Lisp_Object CC_ratpoly_red(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_red");
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
    v28 = stack[0];
    v28 = qcar(v28);
    fn = elt(env, 1); /* numpoly_red */
    v88 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v162;
    v28 = stack[0];
    v28 = qcdr(v28);
    popv(1);
    return cons(v88, v28);
/* error exit handlers */
v162:
    popv(1);
    return nil;
}



/* Code for upperlimitrd */

static Lisp_Object MS_CDECL CC_upperlimitrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "upperlimitrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for upperlimitrd");
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
    fn = elt(env, 4); /* mathml */
    v46 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-1];
    stack[0] = v46;
    fn = elt(env, 5); /* lex */
    v46 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-1];
    v47 = qvalue(elt(env, 1)); /* char */
    v46 = elt(env, 2); /* (!/ u p l i m i t) */
    if (equal(v47, v46)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v47 = elt(env, 3); /* "</uplimit>" */
    v46 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 6); /* errorml */
    v46 = (*qfn2(fn))(qenv(fn), v47, v46);
    nil = C_nil;
    if (exception_pending()) goto v45;
    v46 = nil;
    { popv(2); return onevalue(v46); }
/* error exit handlers */
v45:
    popv(2);
    return nil;
}



/* Code for !*kp2q */

static Lisp_Object CC_Hkp2q(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *kp2q");
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
    v33 = stack[0];
    v79 = (Lisp_Object)1; /* 0 */
    v79 = (Lisp_Object)greaterp2(v33, v79);
    nil = C_nil;
    if (exception_pending()) goto v161;
    v79 = v79 ? lisp_true : nil;
    env = stack[-2];
    if (v79 == nil) goto v52;
    v33 = stack[-1];
    v79 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* mksq */
        return (*qfn2(fn))(qenv(fn), v33, v79);
    }

v52:
    v79 = stack[0];
    v79 = (Lisp_Object)zerop(v79);
    v79 = v79 ? lisp_true : nil;
    env = stack[-2];
    if (v79 == nil) goto v60;
    v33 = (Lisp_Object)17; /* 1 */
    v79 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v33, v79);

v60:
    v79 = stack[0];
    v79 = negate(v79);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-2];
    fn = elt(env, 3); /* mksq */
    v79 = (*qfn2(fn))(qenv(fn), stack[-1], v79);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-2];
    stack[-1] = v79;
    v79 = qcar(v79);
    if (v79 == nil) goto v157;
    v79 = stack[-1];
    v33 = qcdr(v79);
    v79 = stack[-1];
    v79 = qcar(v79);
    popv(3);
    return cons(v33, v79);

v157:
    v79 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v79 == nil)) goto v43;
    v79 = elt(env, 2); /* "Zero divisor" */
    fn = elt(env, 4); /* lprie */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-2];
    goto v43;

v43:
    v79 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v161;
    v79 = nil;
    { popv(3); return onevalue(v79); }
/* error exit handlers */
v161:
    popv(3);
    return nil;
}



/* Code for reset_opnums */

static Lisp_Object MS_CDECL CC_reset_opnums(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v79, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "reset_opnums");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reset_opnums");
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
/* end of prologue */
    v78 = qvalue(elt(env, 1)); /* oporder!* */
    stack[-4] = v78;
    v78 = (Lisp_Object)17; /* 1 */
    stack[-3] = v78;
    goto v67;

v67:
    v78 = stack[-4];
    if (v78 == nil) goto v28;
    v78 = stack[-4];
    v78 = qcar(v78);
    v79 = v78;
    v78 = stack[-4];
    v78 = qcdr(v78);
    stack[-4] = v78;
    v78 = v79;
    if (symbolp(v78)) goto v107;
    v78 = v79;
    v78 = qcar(v78);
    stack[-2] = v78;
    v78 = v79;
    v78 = qcdr(v78);
    goto v157;

v157:
    stack[-1] = stack[-2];
    stack[0] = elt(env, 3); /* opnum */
    v79 = v78;
    v78 = stack[-3];
    v33 = cons(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    v79 = stack[-2];
    v78 = elt(env, 3); /* opnum */
    v78 = get(v79, v78);
    env = stack[-5];
    fn = elt(env, 4); /* !*xadd */
    v78 = (*qfn2(fn))(qenv(fn), v33, v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    v78 = Lputprop(nil, 3, stack[-1], stack[0], v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    v78 = stack[-3];
    v78 = add1(v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-5];
    stack[-3] = v78;
    goto v67;

v107:
    v78 = v79;
    stack[-2] = v78;
    v78 = qvalue(elt(env, 2)); /* nil */
    goto v157;

v28:
    v78 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v78); }
/* error exit handlers */
v80:
    popv(6);
    return nil;
}



/* Code for fs!:minusp!: */

static Lisp_Object CC_fsTminuspT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:minusp:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v74 = v0;
/* end of prologue */
    v74 = qcdr(v74);
    {
        fn = elt(env, 1); /* fs!:minusp */
        return (*qfn1(fn))(qenv(fn), v74);
    }
}



/* Code for groeb!=testc1 */

static Lisp_Object CC_groebMtestc1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v181, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=testc1");
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
    v66 = stack[0];
    v181 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 1); /* pnth */
    v181 = (*qfn2(fn))(qenv(fn), v66, v181);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    v181 = qcar(v181);
    fn = elt(env, 2); /* bas_dpoly */
    v181 = (*qfn1(fn))(qenv(fn), v181);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    fn = elt(env, 3); /* dp_lmon */
    stack[-1] = (*qfn1(fn))(qenv(fn), v181);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    v66 = stack[0];
    v181 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 1); /* pnth */
    v181 = (*qfn2(fn))(qenv(fn), v66, v181);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    v181 = qcar(v181);
    fn = elt(env, 2); /* bas_dpoly */
    v181 = (*qfn1(fn))(qenv(fn), v181);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    fn = elt(env, 3); /* dp_lmon */
    v181 = (*qfn1(fn))(qenv(fn), v181);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    fn = elt(env, 4); /* mo_sum */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v181);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    v66 = stack[0];
    v181 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* pnth */
    v181 = (*qfn2(fn))(qenv(fn), v66, v181);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    v181 = qcar(v181);
    {
        Lisp_Object v43 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* mo_equal!? */
        return (*qfn2(fn))(qenv(fn), v43, v181);
    }
/* error exit handlers */
v42:
    popv(3);
    return nil;
}



/* Code for taylorp */

static Lisp_Object CC_taylorp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v73;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for taylorp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v73 = v0;
/* end of prologue */
    v106 = v73;
    if (!consp(v106)) goto v76;
    v106 = v73;
    v106 = qcar(v106);
    if (!consp(v106)) goto v67;
    v106 = v73;
    v106 = qcar(v106);
    v106 = qcar(v106);
    v73 = elt(env, 2); /* taylor */
        return Lflagp(nil, v106, v73);

v67:
    v106 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v106);

v76:
    v106 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v106);
}



/* Code for ofsf_ir2atl */

static Lisp_Object MS_CDECL CC_ofsf_ir2atl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v221, v237, v238;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_ir2atl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_ir2atl");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v2;
    stack[0] = v1;
    stack[-5] = v0;
/* end of prologue */
    v221 = stack[0];
    v237 = qcar(v221);
    v221 = (Lisp_Object)17; /* 1 */
    v221 = cons(v237, v221);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-7];
    stack[-6] = v221;
    v221 = stack[0];
    v221 = qcdr(v221);
    stack[-3] = v221;
    goto v87;

v87:
    v221 = stack[-3];
    if (v221 == nil) goto v106;
    v221 = stack[-3];
    v221 = qcar(v221);
    v237 = v221;
    v221 = v237;
    v238 = qcar(v221);
    v221 = stack[-4];
    if (equal(v238, v221)) goto v66;
    v221 = nil;
    goto v18;

v18:
    stack[-2] = v221;
    v221 = stack[-2];
    fn = elt(env, 2); /* lastpair */
    v221 = (*qfn1(fn))(qenv(fn), v221);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-7];
    stack[-1] = v221;
    v221 = stack[-3];
    v221 = qcdr(v221);
    stack[-3] = v221;
    v221 = stack[-1];
    if (!consp(v221)) goto v87;
    else goto v69;

v69:
    v221 = stack[-3];
    if (v221 == nil) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    stack[0] = stack[-1];
    v221 = stack[-3];
    v221 = qcar(v221);
    v237 = v221;
    v221 = v237;
    v238 = qcar(v221);
    v221 = stack[-4];
    if (equal(v238, v221)) goto v19;
    v221 = nil;
    goto v80;

v80:
    v221 = Lrplacd(nil, stack[0], v221);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-7];
    v221 = stack[-1];
    fn = elt(env, 2); /* lastpair */
    v221 = (*qfn1(fn))(qenv(fn), v221);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-7];
    stack[-1] = v221;
    v221 = stack[-3];
    v221 = qcdr(v221);
    stack[-3] = v221;
    goto v69;

v19:
    v238 = stack[-5];
    v221 = v237;
    v237 = qcdr(v221);
    v221 = stack[-6];
    fn = elt(env, 3); /* ofsf_entry2at */
    v221 = (*qfnn(fn))(qenv(fn), 3, v238, v237, v221);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-7];
    v221 = ncons(v221);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-7];
    goto v80;

v66:
    v238 = stack[-5];
    v221 = v237;
    v237 = qcdr(v221);
    v221 = stack[-6];
    fn = elt(env, 3); /* ofsf_entry2at */
    v221 = (*qfnn(fn))(qenv(fn), 3, v238, v237, v221);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-7];
    v221 = ncons(v221);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-7];
    goto v18;

v106:
    v221 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v221); }
/* error exit handlers */
v143:
    popv(8);
    return nil;
}



/* Code for ofsf_evalatp */

static Lisp_Object CC_ofsf_evalatp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v241, v236;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_evalatp");
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
    stack[0] = v1;
    v236 = v0;
/* end of prologue */
    v241 = v236;
    v99 = elt(env, 1); /* equal */
    if (v241 == v99) goto v74;
    v241 = v236;
    v99 = elt(env, 2); /* neq */
    if (v241 == v99) goto v162;
    v241 = v236;
    v99 = elt(env, 3); /* leq */
    if (v241 == v99) goto v46;
    v241 = v236;
    v99 = elt(env, 4); /* geq */
    if (v241 == v99) goto v54;
    v241 = v236;
    v99 = elt(env, 5); /* lessp */
    if (v241 == v99) goto v55;
    v241 = v236;
    v99 = elt(env, 6); /* greaterp */
    if (v241 == v99) goto v178;
    v99 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v99 == nil)) goto v85;
    v99 = elt(env, 8); /* "ofsf_evalatp: unknown operator " */
    v241 = v236;
    v99 = list2(v99, v241);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-1];
    fn = elt(env, 9); /* lprie */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-1];
    goto v85;

v85:
    v99 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v242;
    v99 = nil;
    { popv(2); return onevalue(v99); }

v178:
    v99 = stack[0];
    fn = elt(env, 10); /* minusf */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v242;
    if (!(v99 == nil)) goto v81;
    v99 = stack[0];
    v99 = (v99 == nil ? lisp_true : nil);
    goto v81;

v81:
    v99 = (v99 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v99); }

v55:
    v99 = stack[0];
    {
        popv(2);
        fn = elt(env, 10); /* minusf */
        return (*qfn1(fn))(qenv(fn), v99);
    }

v54:
    v99 = stack[0];
    fn = elt(env, 10); /* minusf */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v242;
    v99 = (v99 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v99); }

v46:
    v99 = stack[0];
    fn = elt(env, 10); /* minusf */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v242;
    if (!(v99 == nil)) { popv(2); return onevalue(v99); }
    v99 = stack[0];
    v99 = (v99 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v99); }

v162:
    v99 = stack[0];
    v99 = (v99 == nil ? lisp_true : nil);
    v99 = (v99 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v99); }

v74:
    v99 = stack[0];
    v99 = (v99 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v99); }
/* error exit handlers */
v242:
    popv(2);
    return nil;
}



/* Code for qqe_ofsf_varlat */

static Lisp_Object CC_qqe_ofsf_varlat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_ofsf_varlat");
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
    v47 = v0;
/* end of prologue */
    fn = elt(env, 2); /* qqe_ofsf_prepat */
    v47 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    stack[-1] = v47;
    v47 = stack[-1];
    fn = elt(env, 3); /* qqe_arg2l */
    v44 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    v47 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* qqe_ofsf_varlterm */
    stack[0] = (*qfn2(fn))(qenv(fn), v44, v47);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    v47 = stack[-1];
    fn = elt(env, 5); /* qqe_arg2r */
    v44 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    v47 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* qqe_ofsf_varlterm */
    v47 = (*qfn2(fn))(qenv(fn), v44, v47);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    {
        Lisp_Object v68 = stack[0];
        popv(3);
        fn = elt(env, 6); /* union */
        return (*qfn2(fn))(qenv(fn), v68, v47);
    }
/* error exit handlers */
v18:
    popv(3);
    return nil;
}



/* Code for ofsf_sacrel */

static Lisp_Object MS_CDECL CC_ofsf_sacrel(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v68, v157, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_sacrel");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sacrel");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v18 = v2;
    v157 = v1;
    v61 = v0;
/* end of prologue */
    v68 = v18;
    v18 = elt(env, 1); /* or */
    if (v68 == v18) goto v162;
    v18 = v61;
    v68 = v157;
    {
        fn = elt(env, 2); /* ofsf_sacrel!-and */
        return (*qfn2(fn))(qenv(fn), v18, v68);
    }

v162:
    v18 = v61;
    v68 = v157;
    {
        fn = elt(env, 3); /* ofsf_sacrel!-or */
        return (*qfn2(fn))(qenv(fn), v18, v68);
    }
}



/* Code for determinantrd */

static Lisp_Object MS_CDECL CC_determinantrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "determinantrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for determinantrd");
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
    fn = elt(env, 1); /* mathml */
    v84 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-1];
    fn = elt(env, 2); /* alg_det */
    v84 = (*qfn1(fn))(qenv(fn), v84);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-1];
    stack[0] = v84;
    fn = elt(env, 3); /* lex */
    v84 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v10;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v10:
    popv(2);
    return nil;
}



/* Code for mulpower */

static Lisp_Object CC_mulpower(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v173, v180, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mulpower");
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
    v173 = v1;
    v180 = v0;
/* end of prologue */
    stack[0] = nil;
    fn = elt(env, 3); /* addexptsdf */
    v173 = (*qfn2(fn))(qenv(fn), v180, v173);
    nil = C_nil;
    if (exception_pending()) goto v243;
    env = stack[-2];
    stack[-1] = v173;
    v173 = qvalue(elt(env, 1)); /* sqrtlist */
    if (v173 == nil) goto v44;
    v180 = stack[-1];
    v173 = qvalue(elt(env, 2)); /* zlist */
    fn = elt(env, 4); /* reduceroots */
    v173 = (*qfn2(fn))(qenv(fn), v180, v173);
    nil = C_nil;
    if (exception_pending()) goto v243;
    env = stack[-2];
    stack[0] = v173;
    goto v44;

v44:
    v55 = stack[-1];
    v180 = (Lisp_Object)17; /* 1 */
    v173 = (Lisp_Object)17; /* 1 */
    v173 = list2star(v55, v180, v173);
    nil = C_nil;
    if (exception_pending()) goto v243;
    env = stack[-2];
    v173 = ncons(v173);
    nil = C_nil;
    if (exception_pending()) goto v243;
    env = stack[-2];
    stack[-1] = v173;
    v173 = stack[0];
    if (v173 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v180 = stack[-1];
    v173 = stack[0];
    fn = elt(env, 5); /* multdf */
    v173 = (*qfn2(fn))(qenv(fn), v180, v173);
    nil = C_nil;
    if (exception_pending()) goto v243;
    stack[-1] = v173;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v243:
    popv(3);
    return nil;
}



/* Code for groebcplistmerge */

static Lisp_Object CC_groebcplistmerge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebcplistmerge");
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
    v35 = stack[-2];
    if (v35 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v35 = stack[-1];
    if (v35 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v35 = stack[-2];
    v35 = qcar(v35);
    stack[-3] = v35;
    v35 = stack[-1];
    v35 = qcar(v35);
    stack[0] = v35;
    v34 = stack[-3];
    v35 = stack[0];
    fn = elt(env, 1); /* groebcpcompless!? */
    v35 = (*qfn2(fn))(qenv(fn), v34, v35);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-4];
    if (v35 == nil) goto v57;
    stack[0] = stack[-3];
    v35 = stack[-2];
    v34 = qcdr(v35);
    v35 = stack[-1];
    v35 = CC_groebcplistmerge(env, v34, v35);
    nil = C_nil;
    if (exception_pending()) goto v81;
    {
        Lisp_Object v36 = stack[0];
        popv(5);
        return cons(v36, v35);
    }

v57:
    v34 = stack[-2];
    v35 = stack[-1];
    v35 = qcdr(v35);
    v35 = CC_groebcplistmerge(env, v34, v35);
    nil = C_nil;
    if (exception_pending()) goto v81;
    {
        Lisp_Object v222 = stack[0];
        popv(5);
        return cons(v222, v35);
    }
/* error exit handlers */
v81:
    popv(5);
    return nil;
}



/* Code for remove_least_item */

static Lisp_Object CC_remove_least_item(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remove_least_item");
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
    v68 = v0;
/* end of prologue */

v76:
    v157 = v68;
    v157 = qcdr(v157);
    if (v157 == nil) goto v90;
    v157 = v68;
    v157 = qcdr(v157);
    v157 = qcar(v157);
    v157 = qcdr(v157);
    if (v157 == nil) goto v70;
    v68 = qcdr(v68);
    v68 = qcar(v68);
    goto v76;

v70:
    {
        popv(1);
        fn = elt(env, 3); /* remove_root_item */
        return (*qfn1(fn))(qenv(fn), v68);
    }

v90:
    v68 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v68 == nil)) goto v88;
    v68 = elt(env, 2); /* "How did we get here?" */
    fn = elt(env, 4); /* lprie */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[0];
    goto v88;

v88:
    v68 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    v68 = nil;
    { popv(1); return onevalue(v68); }
/* error exit handlers */
v61:
    popv(1);
    return nil;
}



/* Code for rtrnda */

static Lisp_Object CC_rtrnda(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v64, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rtrnda");
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
    v64 = v1;
    stack[0] = v0;
/* end of prologue */
    v55 = stack[0];
    if (!consp(v55)) goto v82;
    v55 = stack[0];
    v55 = qcdr(v55);
    v77 = qcar(v55);
    v55 = (Lisp_Object)1; /* 0 */
    v55 = (v77 == v55 ? lisp_true : nil);
    goto v67;

v67:
    if (v55 == nil) goto v160;
    v64 = (Lisp_Object)1; /* 0 */
    v55 = (Lisp_Object)1; /* 0 */
    v55 = cons(v64, v55);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    qvalue(elt(env, 1)) = v55; /* rlval!# */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v160:
    v55 = stack[0];
    fn = elt(env, 2); /* round!:dec1 */
    v55 = (*qfn2(fn))(qenv(fn), v55, v64);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v64 = v55;
    qvalue(elt(env, 1)) = v64; /* rlval!# */
    v64 = qcar(v64);
    v55 = qcdr(v55);
    {
        popv(2);
        fn = elt(env, 3); /* decimal2internal */
        return (*qfn2(fn))(qenv(fn), v64, v55);
    }

v82:
    v55 = stack[0];
    v55 = (Lisp_Object)zerop(v55);
    v55 = v55 ? lisp_true : nil;
    env = stack[-1];
    goto v67;
/* error exit handlers */
v65:
    popv(2);
    return nil;
}



/* Code for pa_part2list */

static Lisp_Object CC_pa_part2list(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pa_part2list");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0;
/* end of prologue */
    v210 = stack[-6];
    v210 = qcdr(v210);
    fn = elt(env, 2); /* upbve */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-8];
    stack[0] = v210;
    v210 = stack[0];
    v210 = sub1(v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-8];
    v210 = Lmkvect(nil, v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-8];
    stack[-7] = v210;
    v210 = stack[0];
    stack[-4] = v210;
    goto v158;

v158:
    v210 = stack[-4];
    v210 = sub1(v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-8];
    v210 = Lminusp(nil, v210);
    env = stack[-8];
    if (v210 == nil) goto v46;
    v210 = stack[-6];
    v210 = qcar(v210);
    stack[-4] = v210;
    goto v34;

v34:
    v210 = stack[-4];
    if (v210 == nil) goto v36;
    v210 = stack[-4];
    v210 = qcar(v210);
    stack[0] = stack[-7];
    v210 = sub1(v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-8];
    v210 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v210/(16/CELL)));
    fn = elt(env, 3); /* copy */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-8];
    stack[-3] = v210;
    v210 = stack[-3];
    fn = elt(env, 4); /* lastpair */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-8];
    stack[-2] = v210;
    v210 = stack[-4];
    v210 = qcdr(v210);
    stack[-4] = v210;
    v210 = stack[-2];
    if (!consp(v210)) goto v34;
    else goto v161;

v161:
    v210 = stack[-4];
    if (v210 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    stack[-1] = stack[-2];
    v210 = stack[-4];
    v210 = qcar(v210);
    stack[0] = stack[-7];
    v210 = sub1(v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-8];
    v210 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v210/(16/CELL)));
    fn = elt(env, 3); /* copy */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-8];
    v210 = Lrplacd(nil, stack[-1], v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-8];
    v210 = stack[-2];
    fn = elt(env, 4); /* lastpair */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-8];
    stack[-2] = v210;
    v210 = stack[-4];
    v210 = qcdr(v210);
    stack[-4] = v210;
    goto v161;

v36:
    v210 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v210); }

v46:
    v210 = stack[-6];
    stack[0] = qcdr(v210);
    v210 = stack[-4];
    v210 = sub1(v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-8];
    v210 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v210/(16/CELL)));
    stack[-5] = v210;
    stack[-3] = stack[-7];
    v210 = stack[-5];
    stack[-2] = sub1(v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-8];
    stack[-1] = stack[-4];
    stack[0] = stack[-7];
    v210 = stack[-5];
    v210 = sub1(v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-8];
    v210 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v210/(16/CELL)));
    v210 = cons(stack[-1], v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-8];
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[-2]/(16/CELL))) = v210;
    v210 = stack[-4];
    v210 = sub1(v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-8];
    stack[-4] = v210;
    goto v158;
/* error exit handlers */
v212:
    popv(9);
    return nil;
}



/* Code for remainder!-mod!-p */

static Lisp_Object CC_remainderKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v72, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remainder-mod-p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v71 = v1;
    v54 = v0;
/* end of prologue */
    v72 = v71;
    if (v72 == nil) goto v74;
    v72 = v71;
    if (!consp(v72)) goto v84;
    v72 = v71;
    v72 = qcar(v72);
    if (!consp(v72)) goto v84;
    v72 = v54;
    if (!consp(v72)) return onevalue(v54);
    v72 = v54;
    v72 = qcar(v72);
    if (!consp(v72)) return onevalue(v54);
    v72 = v71;
    v71 = qcar(v71);
    v71 = qcar(v71);
    v71 = qcar(v71);
    {
        fn = elt(env, 3); /* xremainder!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 3, v54, v72, v71);
    }

v84:
    v71 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v71);

v74:
    v71 = elt(env, 1); /* "B=0 IN REMAINDER-MOD-P" */
    {
        fn = elt(env, 4); /* errorf */
        return (*qfn1(fn))(qenv(fn), v71);
    }
}



/* Code for sfto_lmultf */

static Lisp_Object CC_sfto_lmultf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_lmultf");
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
    goto v52;

v52:
    v72 = stack[0];
    if (v72 == nil) goto v90;
    v72 = stack[0];
    v54 = qcar(v72);
    v72 = stack[-1];
    v72 = cons(v54, v72);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    stack[-1] = v72;
    v72 = stack[0];
    v72 = qcdr(v72);
    stack[0] = v72;
    goto v52;

v90:
    v72 = (Lisp_Object)17; /* 1 */
    v54 = v72;
    goto v67;

v67:
    v72 = stack[-1];
    if (v72 == nil) { popv(3); return onevalue(v54); }
    v72 = stack[-1];
    v72 = qcar(v72);
    fn = elt(env, 1); /* multf */
    v72 = (*qfn2(fn))(qenv(fn), v72, v54);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    v54 = v72;
    v72 = stack[-1];
    v72 = qcdr(v72);
    stack[-1] = v72;
    goto v67;
/* error exit handlers */
v89:
    popv(3);
    return nil;
}



/* Code for pasf_smordtable2 */

static Lisp_Object CC_pasf_smordtable2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v108, v106;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smordtable2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v107 = v1;
    v108 = v0;
/* end of prologue */
    v106 = elt(env, 1); /* ((lessp (lessp 2) (leq 2) (equal 2) (neq nil) (geq nil) (greaterp nil) (cong nil) (ncong nil)) (leq (lessp 2) (leq 2) (equal 2) (neq nil) (geq nil) (greaterp nil) (cong nil)
 (ncong nil)) (equal (lessp false) (leq false) (equal false) (neq 1) (geq 1) (greaterp 1) (cong nil) (ncong nil)) (neq (lessp 2) (leq 2) (equal 2) (neq nil) (geq nil) (greaterp nil) (cong nil) (ncong 
nil)) (geq (lessp false) (leq false) (equal false) (neq 1) (geq 1) (greaterp 1) (cong nil) (ncong nil)) (greaterp (lessp false) (leq false) (equal false) (neq 1) (geq 1) (greaterp 1) (cong nil) (ncong
 nil))) */
    v108 = Latsoc(nil, v108, v106);
    v107 = Latsoc(nil, v107, v108);
    v107 = qcdr(v107);
    return onevalue(v107);
}



/* Code for symbolsrd */

static Lisp_Object MS_CDECL CC_symbolsrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v7, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "symbolsrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbolsrd");
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
/* end of prologue */
    stack[-4] = nil;
    fn = elt(env, 9); /* lex */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    v7 = qvalue(elt(env, 2)); /* char */
    v12 = elt(env, 3); /* (b v a r) */
    if (equal(v7, v12)) goto v87;
    v7 = elt(env, 5); /* "<bvar>" */
    v12 = (Lisp_Object)225; /* 14 */
    fn = elt(env, 10); /* errorml */
    v12 = (*qfn2(fn))(qenv(fn), v7, v12);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    goto v79;

v79:
    v7 = qvalue(elt(env, 2)); /* char */
    v12 = elt(env, 6); /* (l o w l i m i t) */
    if (equal(v7, v12)) goto v178;
    v12 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v12;
    goto v39;

v39:
    v7 = qvalue(elt(env, 2)); /* char */
    v12 = elt(env, 7); /* (i n t e r v a l) */
    if (equal(v7, v12)) goto v249;
    v12 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v12;
    goto v215;

v215:
    v7 = qvalue(elt(env, 2)); /* char */
    v12 = elt(env, 8); /* (c o n d i t i o n) */
    if (equal(v7, v12)) goto v250;
    v12 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v12;
    goto v20;

v20:
    fn = elt(env, 11); /* mathml2 */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    stack[-1] = v12;
    fn = elt(env, 9); /* lex */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    v12 = stack[-3];
    if (v12 == nil) goto v29;
    v5 = stack[-4];
    v7 = stack[-3];
    v12 = stack[-1];
    popv(6);
    return list3(v5, v7, v12);

v29:
    v12 = stack[-2];
    if (v12 == nil) goto v27;
    v5 = stack[-4];
    v7 = stack[-2];
    v12 = stack[-1];
    popv(6);
    return list3(v5, v7, v12);

v27:
    v12 = stack[0];
    if (v12 == nil) goto v94;
    v5 = stack[-4];
    v7 = stack[0];
    v12 = stack[-1];
    popv(6);
    return list3(v5, v7, v12);

v94:
    v7 = stack[-4];
    v5 = qvalue(elt(env, 1)); /* nil */
    v12 = stack[-1];
    popv(6);
    return list3(v7, v5, v12);

v250:
    fn = elt(env, 12); /* conditionrd */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    stack[0] = v12;
    fn = elt(env, 9); /* lex */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    goto v20;

v249:
    fn = elt(env, 13); /* intervalrd */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    stack[-2] = v12;
    fn = elt(env, 9); /* lex */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    goto v215;

v178:
    fn = elt(env, 14); /* lowupperlimitrd */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    stack[-3] = v12;
    fn = elt(env, 9); /* lex */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    goto v39;

v87:
    fn = elt(env, 15); /* bvarrd */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    stack[-4] = v12;
    v12 = stack[-4];
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v7 = qcar(v12);
    v12 = (Lisp_Object)17; /* 1 */
    if (v7 == v12) goto v45;
    v7 = elt(env, 4); /* "" */
    v12 = (Lisp_Object)209; /* 13 */
    fn = elt(env, 10); /* errorml */
    v12 = (*qfn2(fn))(qenv(fn), v7, v12);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    goto v44;

v44:
    fn = elt(env, 9); /* lex */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-5];
    goto v79;

v45:
    v12 = stack[-4];
    stack[-4] = v12;
    goto v44;
/* error exit handlers */
v8:
    popv(6);
    return nil;
}



/* Code for ps!:find!-order */

static Lisp_Object CC_psTfindKorder(Lisp_Object env,
                         Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v250, v214, v215;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:find-order");
#endif
    if (stack >= stacklimit)
    {
        push(v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v250 = v1;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v250; /* ps */
    v250 = qvalue(elt(env, 1)); /* ps */
    if (v250 == nil) goto v82;
    v250 = qvalue(elt(env, 1)); /* ps */
    if (symbolp(v250)) goto v28;
    v250 = qvalue(elt(env, 1)); /* ps */
    v215 = v250;
    v250 = v215;
    v250 = (is_number(v250) ? lisp_true : nil);
    if (!(v250 == nil)) goto v163;
    v250 = v215;
    v250 = Lconsp(nil, v250);
    env = stack[-1];
    if (v250 == nil) goto v46;
    v250 = v215;
    v214 = qcar(v250);
    v250 = elt(env, 3); /* !:ps!: */
    if (v214 == v250) goto v18;
    v250 = v215;
    v214 = qcar(v250);
    v250 = elt(env, 4); /* dname */
    v250 = get(v214, v250);
    env = stack[-1];
    goto v163;

v163:
    if (v250 == nil) goto v243;
    v250 = (Lisp_Object)1; /* 0 */
    goto v74;

v74:
    qvalue(elt(env, 1)) = stack[0]; /* ps */
    { popv(2); return onevalue(v250); }

v243:
    v214 = qvalue(elt(env, 1)); /* ps */
    v250 = elt(env, 3); /* !:ps!: */
    if (!consp(v214)) goto v38;
    v214 = qcar(v214);
    if (!(v214 == v250)) goto v38;
    v250 = qvalue(elt(env, 1)); /* ps */
    v250 = qcdr(v250);
    if (symbolp(v250)) goto v78;
    v250 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 8); /* ps!:expression */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-1];
    if (!consp(v250)) goto v239;
    v250 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 9); /* ps!:find!-order1 */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-1];
    goto v74;

v239:
    v250 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 10); /* ps!:order */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-1];
    goto v74;

v78:
    v250 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 11); /* ps!:unknown!-order */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-1];
    goto v74;

v38:
    v250 = elt(env, 5); /* "Unexpected form in ps!:find!-order" */
    v214 = v250;
    v250 = v214;
    qvalue(elt(env, 6)) = v250; /* errmsg!* */
    v250 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v250 == nil)) goto v216;
    v250 = v214;
    fn = elt(env, 12); /* lprie */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-1];
    goto v216;

v216:
    v250 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-1];
    v250 = nil;
    goto v74;

v18:
    v250 = qvalue(elt(env, 2)); /* nil */
    goto v163;

v46:
    v250 = qvalue(elt(env, 2)); /* nil */
    goto v163;

v28:
    v250 = qvalue(elt(env, 1)); /* ps */
    goto v74;

v82:
    v250 = (Lisp_Object)1; /* 0 */
    goto v74;
/* error exit handlers */
v99:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* ps */
    popv(2);
    return nil;
}



/* Code for setprev */

static Lisp_Object CC_setprev(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152, v251;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setprev");
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
    stack[-3] = v0;
/* end of prologue */

v174:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v251 = qvalue(elt(env, 2)); /* maxvar */
    v152 = stack[-3];
    v152 = plus2(v251, v152);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-5];
    v251 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v152/(16/CELL)));
    v152 = (Lisp_Object)49; /* 3 */
    v152 = *(Lisp_Object *)((char *)v251 + (CELL-TAG_VECTOR) + ((int32_t)v152/(16/CELL)));
    if (is_number(v152)) goto v159;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v251 = qvalue(elt(env, 2)); /* maxvar */
    v152 = stack[-3];
    v152 = plus2(v251, v152);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-5];
    stack[-4] = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v152/(16/CELL)));
    stack[-2] = (Lisp_Object)129; /* 8 */
    stack[-1] = stack[0];
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v251 = qvalue(elt(env, 2)); /* maxvar */
    v152 = stack[-3];
    v152 = plus2(v251, v152);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-5];
    v251 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v152/(16/CELL)));
    v152 = (Lisp_Object)129; /* 8 */
    v152 = *(Lisp_Object *)((char *)v251 + (CELL-TAG_VECTOR) + ((int32_t)v152/(16/CELL)));
    v152 = cons(stack[-1], v152);
    nil = C_nil;
    if (exception_pending()) goto v32;
    *(Lisp_Object *)((char *)stack[-4] + (CELL-TAG_VECTOR) + ((int32_t)stack[-2]/(16/CELL))) = v152;
    { popv(6); return onevalue(v152); }

v159:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v251 = qvalue(elt(env, 2)); /* maxvar */
    v152 = stack[-3];
    v152 = plus2(v251, v152);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-5];
    v251 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v152/(16/CELL)));
    v152 = (Lisp_Object)49; /* 3 */
    v152 = *(Lisp_Object *)((char *)v251 + (CELL-TAG_VECTOR) + ((int32_t)v152/(16/CELL)));
    stack[-3] = v152;
    goto v174;
/* error exit handlers */
v32:
    popv(6);
    return nil;
}



/* Code for make_wedge_pair */

static Lisp_Object CC_make_wedge_pair(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v39, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make_wedge_pair");
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
    v39 = stack[-2];
    v38 = stack[-2];
    stack[0] = list2(v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    v38 = stack[-1];
    fn = elt(env, 5); /* xval */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    fn = elt(env, 6); /* xlcm */
    v38 = (*qfn2(fn))(qenv(fn), stack[0], v38);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    stack[-3] = v38;
    v38 = qvalue(elt(env, 1)); /* !*twosided */
    if (v38 == nil) goto v44;
    v38 = qvalue(elt(env, 2)); /* xtruncate!* */
    if (!(v38 == nil)) goto v44;

v72:
    v39 = stack[-2];
    v38 = stack[-1];
    fn = elt(env, 7); /* overall_factor */
    v38 = (*qfn2(fn))(qenv(fn), v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    if (v38 == nil) goto v59;
    v38 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v38); }

v59:
    v38 = stack[-3];
    fn = elt(env, 8); /* mknwedge */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    fn = elt(env, 9); /* xdegreecheck */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    if (v38 == nil) goto v40;
    v38 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v38); }

v40:
    stack[0] = elt(env, 4); /* wedge_pair */
    v37 = stack[-2];
    v39 = (Lisp_Object)17; /* 1 */
    v38 = (Lisp_Object)17; /* 1 */
    v38 = list2star(v37, v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    v39 = ncons(v38);
    nil = C_nil;
    if (exception_pending()) goto v245;
    v38 = stack[-1];
    {
        Lisp_Object v216 = stack[-3];
        Lisp_Object v172 = stack[0];
        popv(5);
        return list4(v216, v172, v39, v38);
    }

v44:
    stack[0] = stack[-2];
    v38 = stack[-1];
    fn = elt(env, 5); /* xval */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    v38 = Lmemq(nil, stack[0], v38);
    if (!(v38 == nil)) goto v72;
    v38 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v38); }
/* error exit handlers */
v245:
    popv(5);
    return nil;
}



/* Code for physopsubs */

static Lisp_Object CC_physopsubs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v248, v26, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopsubs");
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
    stack[-2] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v248 = qvalue(elt(env, 2)); /* nil */
    v248 = ncons(v248);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    qvalue(elt(env, 1)) = v248; /* alglist!* */
    v248 = stack[-1];
    fn = elt(env, 12); /* physop2sq */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    stack[-1] = v248;
    v248 = qvalue(elt(env, 3)); /* physoplist!* */
    stack[0] = v248;
    goto v88;

v88:
    v248 = stack[0];
    if (v248 == nil) goto v89;
    v248 = stack[0];
    v248 = qcar(v248);
    v27 = v248;
    v26 = v27;
    v248 = elt(env, 4); /* rtype */
    v248 = Lremprop(nil, v26, v248);
    env = stack[-3];
    v26 = elt(env, 5); /* simpfn */
    v248 = elt(env, 6); /* simpiden */
    v248 = Lputprop(nil, 3, v27, v26, v248);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v248 = stack[0];
    v248 = qcdr(v248);
    stack[0] = v248;
    goto v88;

v89:
    v26 = elt(env, 7); /* (dot) */
    v248 = elt(env, 8); /* physopfn */
    v248 = Lremflag(nil, v26, v248);
    env = stack[-3];
    v27 = elt(env, 9); /* dot */
    v26 = elt(env, 5); /* simpfn */
    v248 = elt(env, 6); /* simpiden */
    v248 = Lputprop(nil, 3, v27, v26, v248);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v248 = stack[-1];
    fn = elt(env, 13); /* subs2 */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    stack[-1] = v248;
    v248 = qvalue(elt(env, 10)); /* !*nosq */
    if (v248 == nil) goto v79;
    v248 = stack[-1];
    fn = elt(env, 14); /* prepsqxx */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    goto v78;

v78:
    stack[-1] = v248;
    v248 = qvalue(elt(env, 3)); /* physoplist!* */
    stack[0] = v248;
    goto v170;

v170:
    v248 = stack[0];
    if (v248 == nil) goto v31;
    v248 = stack[0];
    v248 = qcar(v248);
    v27 = v248;
    v26 = v27;
    v248 = elt(env, 5); /* simpfn */
    v248 = Lremprop(nil, v26, v248);
    env = stack[-3];
    v26 = elt(env, 4); /* rtype */
    v248 = elt(env, 11); /* physop */
    v248 = Lputprop(nil, 3, v27, v26, v248);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v248 = stack[0];
    v248 = qcdr(v248);
    stack[0] = v248;
    goto v170;

v31:
    v26 = elt(env, 9); /* dot */
    v248 = elt(env, 5); /* simpfn */
    v248 = Lremprop(nil, v26, v248);
    env = stack[-3];
    v26 = elt(env, 7); /* (dot) */
    v248 = elt(env, 8); /* physopfn */
    v248 = Lflag(nil, v26, v248);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v248 = stack[-1];
    qvalue(elt(env, 1)) = stack[-2]; /* alglist!* */
    { popv(4); return onevalue(v248); }

v79:
    v248 = stack[-1];
    fn = elt(env, 15); /* mk!*sq */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    goto v78;
/* error exit handlers */
v95:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* alglist!* */
    popv(4);
    return nil;
}



/* Code for simp!-prop!-form */

static Lisp_Object CC_simpKpropKform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v258, v259, v260;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop-form");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v259 = v0;
/* end of prologue */
    v260 = v259;
    v258 = elt(env, 1); /* (nil) */
    if (equal(v260, v258)) goto v76;
    v258 = v259;
    stack[-7] = v258;
    v258 = stack[-7];
    if (v258 == nil) goto v106;
    v258 = stack[-7];
    v258 = qcar(v258);
    stack[-3] = v258;
    v258 = stack[-3];
    if (v258 == nil) goto v71;
    v258 = stack[-3];
    v258 = qcar(v258);
    v260 = v258;
    v259 = v260;
    v258 = elt(env, 4); /* not_prop!* */
    if (!consp(v259)) goto v34;
    v259 = qcar(v259);
    if (!(v259 == v258)) goto v34;
    v258 = elt(env, 5); /* not */
    v259 = v260;
    v259 = qcdr(v259);
    v259 = qcar(v259);
    v258 = list2(v258, v259);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    goto v217;

v217:
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    stack[-1] = v258;
    stack[-2] = v258;
    goto v160;

v160:
    v258 = stack[-3];
    v258 = qcdr(v258);
    stack[-3] = v258;
    v258 = stack[-3];
    if (v258 == nil) goto v170;
    stack[0] = stack[-1];
    v258 = stack[-3];
    v258 = qcar(v258);
    v260 = v258;
    v259 = v260;
    v258 = elt(env, 4); /* not_prop!* */
    if (!consp(v259)) goto v22;
    v259 = qcar(v259);
    if (!(v259 == v258)) goto v22;
    v258 = elt(env, 5); /* not */
    v259 = v260;
    v259 = qcdr(v259);
    v259 = qcar(v259);
    v258 = list2(v258, v259);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    goto v21;

v21:
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    v258 = Lrplacd(nil, stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    v258 = stack[-1];
    v258 = qcdr(v258);
    stack[-1] = v258;
    goto v160;

v22:
    v258 = v260;
    v258 = qcdr(v258);
    v258 = qcar(v258);
    goto v21;

v170:
    v258 = stack[-2];
    goto v159;

v159:
    v259 = v258;
    v259 = qcdr(v259);
    if (v259 == nil) goto v144;
    v259 = qvalue(elt(env, 6)); /* !'and */
    v258 = cons(v259, v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    goto v244;

v244:
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    stack[-5] = v258;
    stack[-6] = v258;
    goto v70;

v70:
    v258 = stack[-7];
    v258 = qcdr(v258);
    stack[-7] = v258;
    v258 = stack[-7];
    if (v258 == nil) goto v211;
    stack[-4] = stack[-5];
    v258 = stack[-7];
    v258 = qcar(v258);
    stack[-3] = v258;
    v258 = stack[-3];
    if (v258 == nil) goto v165;
    v258 = stack[-3];
    v258 = qcar(v258);
    v260 = v258;
    v259 = v260;
    v258 = elt(env, 4); /* not_prop!* */
    if (!consp(v259)) goto v110;
    v259 = qcar(v259);
    if (!(v259 == v258)) goto v110;
    v258 = elt(env, 5); /* not */
    v259 = v260;
    v259 = qcdr(v259);
    v259 = qcar(v259);
    v258 = list2(v258, v259);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    goto v262;

v262:
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    stack[-1] = v258;
    stack[-2] = v258;
    goto v263;

v263:
    v258 = stack[-3];
    v258 = qcdr(v258);
    stack[-3] = v258;
    v258 = stack[-3];
    if (v258 == nil) goto v203;
    stack[0] = stack[-1];
    v258 = stack[-3];
    v258 = qcar(v258);
    v260 = v258;
    v259 = v260;
    v258 = elt(env, 4); /* not_prop!* */
    if (!consp(v259)) goto v264;
    v259 = qcar(v259);
    if (!(v259 == v258)) goto v264;
    v258 = elt(env, 5); /* not */
    v259 = v260;
    v259 = qcdr(v259);
    v259 = qcar(v259);
    v258 = list2(v258, v259);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    goto v128;

v128:
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    v258 = Lrplacd(nil, stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    v258 = stack[-1];
    v258 = qcdr(v258);
    stack[-1] = v258;
    goto v263;

v264:
    v258 = v260;
    v258 = qcdr(v258);
    v258 = qcar(v258);
    goto v128;

v203:
    v258 = stack[-2];
    goto v265;

v265:
    v259 = v258;
    v259 = qcdr(v259);
    if (v259 == nil) goto v121;
    v259 = qvalue(elt(env, 6)); /* !'and */
    v258 = cons(v259, v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    goto v266;

v266:
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    v258 = Lrplacd(nil, stack[-4], v258);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    v258 = stack[-5];
    v258 = qcdr(v258);
    stack[-5] = v258;
    goto v70;

v121:
    v258 = qcar(v258);
    goto v266;

v110:
    v258 = v260;
    v258 = qcdr(v258);
    v258 = qcar(v258);
    goto v262;

v165:
    v258 = qvalue(elt(env, 3)); /* nil */
    goto v265;

v211:
    v258 = stack[-6];
    goto v69;

v69:
    v259 = v258;
    v258 = v259;
    v258 = qcdr(v258);
    if (v258 == nil) goto v148;
    v258 = qvalue(elt(env, 7)); /* !'or */
    popv(9);
    return cons(v258, v259);

v148:
    v258 = v259;
    v258 = qcar(v258);
    { popv(9); return onevalue(v258); }

v144:
    v258 = qcar(v258);
    goto v244;

v34:
    v258 = v260;
    v258 = qcdr(v258);
    v258 = qcar(v258);
    goto v217;

v71:
    v258 = qvalue(elt(env, 3)); /* nil */
    goto v159;

v106:
    v258 = qvalue(elt(env, 3)); /* nil */
    goto v69;

v76:
    v258 = qvalue(elt(env, 2)); /* !'true */
    { popv(9); return onevalue(v258); }
/* error exit handlers */
v261:
    popv(9);
    return nil;
}



/* Code for lesspcar */

static Lisp_Object CC_lesspcar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v88;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lesspcar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v28 = v1;
    v88 = v0;
/* end of prologue */
    v88 = qcar(v88);
    v28 = qcar(v28);
        return Llessp(nil, v88, v28);
}



setup_type const u38_setup[] =
{
    {"fs:subang",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_fsTsubang},
    {"verify_tens_ids",         CC_verify_tens_ids,too_many_1, wrong_no_1},
    {"bndtst",                  CC_bndtst,      too_many_1,    wrong_no_1},
    {"mk_resimp_rep",           CC_mk_resimp_rep,too_many_1,   wrong_no_1},
    {"cl_gand-col",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_gandKcol},
    {"factorf",                 CC_factorf,     too_many_1,    wrong_no_1},
    {"intervalrd",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_intervalrd},
    {"dipcontevmin",            too_few_2,      CC_dipcontevmin,wrong_no_2},
    {"dfdeg",                   too_few_2,      CC_dfdeg,      wrong_no_2},
    {"flattens1",               CC_flattens1,   too_many_1,    wrong_no_1},
    {"pst_d1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_pst_d1},
    {"rd:prin",                 CC_rdTprin,     too_many_1,    wrong_no_1},
    {"nextu",                   too_few_2,      CC_nextu,      wrong_no_2},
    {"change+int+to+sq",        CC_changeLintLtoLsq,too_many_1,wrong_no_1},
    {"pasf_or",                 CC_pasf_or,     too_many_1,    wrong_no_1},
    {"ratpoly_red",             CC_ratpoly_red, too_many_1,    wrong_no_1},
    {"upperlimitrd",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_upperlimitrd},
    {"*kp2q",                   too_few_2,      CC_Hkp2q,      wrong_no_2},
    {"reset_opnums",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_reset_opnums},
    {"fs:minusp:",              CC_fsTminuspT,  too_many_1,    wrong_no_1},
    {"groeb=testc1",            CC_groebMtestc1,too_many_1,    wrong_no_1},
    {"taylorp",                 CC_taylorp,     too_many_1,    wrong_no_1},
    {"ofsf_ir2atl",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_ir2atl},
    {"ofsf_evalatp",            too_few_2,      CC_ofsf_evalatp,wrong_no_2},
    {"qqe_ofsf_varlat",         CC_qqe_ofsf_varlat,too_many_1, wrong_no_1},
    {"ofsf_sacrel",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_sacrel},
    {"determinantrd",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_determinantrd},
    {"mulpower",                too_few_2,      CC_mulpower,   wrong_no_2},
    {"groebcplistmerge",        too_few_2,      CC_groebcplistmerge,wrong_no_2},
    {"remove_least_item",       CC_remove_least_item,too_many_1,wrong_no_1},
    {"rtrnda",                  too_few_2,      CC_rtrnda,     wrong_no_2},
    {"pa_part2list",            CC_pa_part2list,too_many_1,    wrong_no_1},
    {"remainder-mod-p",         too_few_2,      CC_remainderKmodKp,wrong_no_2},
    {"sfto_lmultf",             CC_sfto_lmultf, too_many_1,    wrong_no_1},
    {"pasf_smordtable2",        too_few_2,      CC_pasf_smordtable2,wrong_no_2},
    {"symbolsrd",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_symbolsrd},
    {"ps:find-order",           CC_psTfindKorder,too_many_1,   wrong_no_1},
    {"setprev",                 too_few_2,      CC_setprev,    wrong_no_2},
    {"make_wedge_pair",         too_few_2,      CC_make_wedge_pair,wrong_no_2},
    {"physopsubs",              CC_physopsubs,  too_many_1,    wrong_no_1},
    {"simp-prop-form",          CC_simpKpropKform,too_many_1,  wrong_no_1},
    {"lesspcar",                too_few_2,      CC_lesspcar,   wrong_no_2},
    {NULL, (one_args *)"u38", (two_args *)"11091 4412127 740057", 0}
};

/* end of generated code */
