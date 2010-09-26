
/* $destdir\u08.c        Machine generated C code */

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


/* Code for reval1 */

static Lisp_Object CC_reval1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v93, v94, v95, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval1");
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
    v92 = qvalue(elt(env, 1)); /* varstack!* */
    stack[-3] = qvalue(elt(env, 1)); /* varstack!* */
    qvalue(elt(env, 1)) = v92; /* varstack!* */
    v92 = stack[-2];
    if (v92 == nil) goto v97;
    v92 = stack[-2];
    v92 = Lstringp(nil, v92);
    env = stack[-4];
    if (v92 == nil) goto v98;
    v92 = stack[-2];
    goto v99;

v99:
    qvalue(elt(env, 1)) = stack[-3]; /* varstack!* */
    { popv(5); return onevalue(v92); }

v98:
    v92 = stack[-2];
    v92 = integerp(v92);
    if (v92 == nil) goto v100;
    v93 = qvalue(elt(env, 3)); /* dmode!* */
    v92 = elt(env, 4); /* convert */
    v92 = Lflagp(nil, v93, v92);
    env = stack[-4];
    if (v92 == nil) goto v101;
    v93 = stack[-2];
    v92 = stack[-1];
    fn = elt(env, 30); /* reval2 */
    v92 = (*qfn2(fn))(qenv(fn), v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    goto v99;

v101:
    v92 = stack[-2];
    goto v99;

v100:
    v92 = stack[-2];
    if (!consp(v92)) goto v103;
    v92 = stack[-2];
    v92 = qcar(v92);
    if (symbolp(v92)) goto v104;
    v96 = elt(env, 10); /* "Syntax error:" */
    v95 = stack[-2];
    v94 = elt(env, 11); /* "invalid" */
    v93 = qvalue(elt(env, 2)); /* nil */
    v92 = qvalue(elt(env, 8)); /* t */
    fn = elt(env, 31); /* msgpri */
    v92 = (*qfnn(fn))(qenv(fn), 5, v96, v95, v94, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    goto v105;

v105:
    v92 = stack[-2];
    fn = elt(env, 32); /* getrtype */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    stack[0] = v92;
    if (v92 == nil) goto v106;
    v93 = stack[0];
    v92 = elt(env, 9); /* evfn */
    v92 = get(v93, v92);
    env = stack[-4];
    v94 = v92;
    if (v92 == nil) goto v107;
    v93 = stack[-2];
    v92 = stack[-1];
    v92 = Lapply2(nil, 3, v94, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    goto v99;

v107:
    v93 = elt(env, 20); /* "Missing evaluation for type" */
    v92 = stack[0];
    v92 = list2(v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    v93 = v92;
    v92 = v93;
    qvalue(elt(env, 21)) = v92; /* errmsg!* */
    v92 = qvalue(elt(env, 22)); /* !*protfg */
    if (!(v92 == nil)) goto v108;
    v92 = v93;
    fn = elt(env, 33); /* lprie */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    goto v108;

v108:
    v92 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    v92 = nil;
    goto v99;

v106:
    v92 = stack[-2];
    if (!consp(v92)) goto v109;
    v92 = stack[-2];
    v92 = qcdr(v92);
    if (!consp(v92)) goto v109;
    v92 = stack[-2];
    v92 = qcdr(v92);
    v92 = qcar(v92);
    fn = elt(env, 32); /* getrtype */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    v94 = v92;
    if (v92 == nil) goto v109;
    v93 = v94;
    v92 = elt(env, 23); /* list */
    if (!(v93 == v92)) goto v110;
    v92 = stack[-2];
    v92 = qcdr(v92);
    v92 = qcdr(v92);
    if (!(v92 == nil)) goto v109;

v110:
    v93 = v94;
    v92 = elt(env, 24); /* aggregatefn */
    v92 = get(v93, v92);
    env = stack[-4];
    stack[0] = v92;
    if (v92 == nil) goto v109;
    v93 = stack[0];
    v92 = elt(env, 25); /* matrixmap */
    if (!(v93 == v92)) goto v111;
    v92 = stack[-2];
    v93 = qcar(v92);
    v92 = elt(env, 26); /* matmapfn */
    v92 = Lflagp(nil, v93, v92);
    env = stack[-4];
    if (!(v92 == nil)) goto v111;

v109:
    v93 = stack[-2];
    v92 = stack[-1];
    fn = elt(env, 30); /* reval2 */
    v92 = (*qfn2(fn))(qenv(fn), v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    goto v99;

v111:
    v92 = stack[-2];
    v93 = qcar(v92);
    v92 = elt(env, 27); /* boolean */
    v92 = Lflagp(nil, v93, v92);
    env = stack[-4];
    if (!(v92 == nil)) goto v109;
    v92 = qvalue(elt(env, 28)); /* !*listargs */
    if (!(v92 == nil)) goto v109;
    v92 = stack[-2];
    v93 = qcar(v92);
    v92 = elt(env, 29); /* listargp */
    v92 = Lflagp(nil, v93, v92);
    env = stack[-4];
    if (!(v92 == nil)) goto v109;
    v94 = stack[0];
    v93 = stack[-2];
    v92 = stack[-1];
    v92 = Lapply2(nil, 3, v94, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    goto v99;

v104:
    v92 = stack[-2];
    v93 = qcar(v92);
    v92 = elt(env, 12); /* !*sq */
    if (v93 == v92) goto v112;
    v92 = stack[-2];
    v93 = qcar(v92);
    v92 = elt(env, 14); /* remember */
    v92 = Lflagp(nil, v93, v92);
    env = stack[-4];
    if (v92 == nil) goto v113;
    v93 = stack[-2];
    v92 = stack[-1];
    fn = elt(env, 34); /* rmmbreval */
    v92 = (*qfn2(fn))(qenv(fn), v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    goto v99;

v113:
    v92 = stack[-2];
    v93 = qcar(v92);
    v92 = elt(env, 15); /* opfn */
    v92 = Lflagp(nil, v93, v92);
    env = stack[-4];
    if (v92 == nil) goto v114;
    v92 = stack[-2];
    fn = elt(env, 35); /* opfneval */
    v93 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    v92 = stack[-1];
    v92 = CC_reval1(env, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    goto v99;

v114:
    v92 = stack[-2];
    v93 = qcar(v92);
    v92 = elt(env, 16); /* psopfn */
    v92 = get(v93, v92);
    env = stack[-4];
    stack[0] = v92;
    if (v92 == nil) goto v115;
    v93 = stack[0];
    v92 = stack[-2];
    v92 = qcdr(v92);
    v92 = Lapply1(nil, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    stack[-2] = v92;
    v93 = stack[0];
    v92 = elt(env, 17); /* cleanupfn */
    v92 = get(v93, v92);
    env = stack[-4];
    stack[0] = v92;
    if (v92 == nil) goto v116;
    v94 = stack[0];
    v93 = stack[-2];
    v92 = stack[-1];
    v92 = Lapply2(nil, 3, v94, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    stack[-2] = v92;
    goto v116;

v116:
    v92 = stack[-2];
    goto v99;

v115:
    v92 = stack[-2];
    v93 = qcar(v92);
    v92 = elt(env, 18); /* rtype */
    v93 = get(v93, v92);
    env = stack[-4];
    v92 = elt(env, 19); /* array */
    if (!(v93 == v92)) goto v105;
    v92 = stack[-2];
    fn = elt(env, 36); /* getelv */
    v93 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    v92 = stack[-1];
    v92 = CC_reval1(env, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    goto v99;

v112:
    v92 = stack[-2];
    v92 = qcdr(v92);
    v92 = qcdr(v92);
    v92 = qcar(v92);
    if (v92 == nil) goto v117;
    v92 = qvalue(elt(env, 13)); /* !*resimp */
    if (!(v92 == nil)) goto v117;
    v92 = stack[-1];
    if (v92 == nil) goto v118;
    v92 = stack[-2];
    v92 = qcdr(v92);
    v92 = qcar(v92);
    fn = elt(env, 37); /* prepsqxx */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    goto v99;

v118:
    v92 = stack[-2];
    goto v99;

v117:
    v93 = stack[-2];
    v92 = stack[-1];
    fn = elt(env, 30); /* reval2 */
    v92 = (*qfn2(fn))(qenv(fn), v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    goto v99;

v103:
    v92 = qvalue(elt(env, 5)); /* subfg!* */
    if (v92 == nil) goto v119;
    v92 = stack[-2];
    if (!(symbolp(v92))) goto v105;
    v93 = stack[-2];
    v92 = elt(env, 6); /* avalue */
    v92 = get(v93, v92);
    env = stack[-4];
    stack[0] = v92;
    if (v92 == nil) goto v105;
    v93 = stack[-2];
    v92 = qvalue(elt(env, 1)); /* varstack!* */
    v92 = Lmemq(nil, v93, v92);
    if (v92 == nil) goto v120;
    v96 = qvalue(elt(env, 2)); /* nil */
    v95 = stack[-2];
    v94 = elt(env, 7); /* "improperly defined in terms of itself" */
    v93 = qvalue(elt(env, 2)); /* nil */
    v92 = qvalue(elt(env, 8)); /* t */
    fn = elt(env, 31); /* msgpri */
    v92 = (*qfnn(fn))(qenv(fn), 5, v96, v95, v94, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    goto v105;

v120:
    v93 = stack[-2];
    v92 = qvalue(elt(env, 1)); /* varstack!* */
    v92 = cons(v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    qvalue(elt(env, 1)) = v92; /* varstack!* */
    v92 = stack[0];
    v93 = qcar(v92);
    v92 = elt(env, 9); /* evfn */
    v92 = get(v93, v92);
    env = stack[-4];
    v94 = v92;
    if (v92 == nil) goto v121;
    v93 = stack[-2];
    v92 = stack[-1];
    v92 = Lapply2(nil, 3, v94, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    goto v99;

v121:
    v92 = stack[0];
    v92 = qcdr(v92);
    v93 = qcar(v92);
    v92 = stack[-1];
    v92 = CC_reval1(env, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    goto v99;

v119:
    v92 = stack[-2];
    goto v99;

v97:
    v92 = qvalue(elt(env, 2)); /* nil */
    goto v99;
/* error exit handlers */
v102:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* varstack!* */
    popv(5);
    return nil;
}



/* Code for setdiff */

static Lisp_Object CC_setdiff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v125;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setdiff");
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
    v124 = v0;
/* end of prologue */

v10:
    v125 = stack[0];
    if (v125 == nil) { popv(2); return onevalue(v124); }
    v125 = v124;
    if (v125 == nil) goto v126;
    v125 = stack[0];
    v125 = qcar(v125);
    v124 = Ldelete(nil, v125, v124);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-1];
    v125 = stack[0];
    v125 = qcdr(v125);
    stack[0] = v125;
    goto v10;

v126:
    v124 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v124); }
/* error exit handlers */
v127:
    popv(2);
    return nil;
}



/* Code for on */

static Lisp_Object CC_on(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for on");
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
    v123 = v0;
/* end of prologue */
    stack[0] = v123;
    goto v10;

v10:
    v123 = stack[0];
    if (v123 == nil) goto v133;
    v123 = stack[0];
    v123 = qcar(v123);
    v132 = v123;
    v123 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 3); /* onoff */
    v123 = (*qfn2(fn))(qenv(fn), v132, v123);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-1];
    v123 = stack[0];
    v123 = qcdr(v123);
    stack[0] = v123;
    goto v10;

v133:
    v123 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v123); }
/* error exit handlers */
v124:
    popv(2);
    return nil;
}



/* Code for xdegreemon */

static Lisp_Object CC_xdegreemon(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v103, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xdegreemon");
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
    v103 = v0;
/* end of prologue */
    v138 = qvalue(elt(env, 1)); /* xdegreelist!* */
    if (v138 == nil) goto v3;
    v138 = v103;
    stack[0] = v138;
    v138 = (Lisp_Object)1; /* 0 */
    v139 = v138;
    goto v98;

v98:
    v138 = stack[0];
    if (v138 == nil) { popv(2); return onevalue(v139); }
    v138 = stack[0];
    v138 = qcar(v138);
    v103 = v138;
    v138 = qvalue(elt(env, 1)); /* xdegreelist!* */
    v138 = Latsoc(nil, v103, v138);
    v138 = qcdr(v138);
    v103 = v139;
    v138 = plus2(v138, v103);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-1];
    v139 = v138;
    v138 = stack[0];
    v138 = qcdr(v138);
    stack[0] = v138;
    goto v98;

v3:
    v138 = v103;
    fn = elt(env, 2); /* mknwedge */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* xdegree */
        return (*qfn1(fn))(qenv(fn), v138);
    }
/* error exit handlers */
v140:
    popv(2);
    return nil;
}



/* Code for algid */

static Lisp_Object CC_algid(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v142, v127;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for algid");
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
    v125 = v1;
    v127 = v0;
/* end of prologue */
    v142 = v127;
    v125 = Latsoc(nil, v142, v125);
    if (!(v125 == nil)) return onevalue(v127);
    v142 = v127;
    v125 = elt(env, 1); /* share */
    v125 = Lflagp(nil, v142, v125);
    if (!(v125 == nil)) return onevalue(v127);
    v125 = v127;
        return Lmkquote(nil, v125);
}



/* Code for greaterp!: */

static Lisp_Object CC_greaterpT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v171, v172, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for greaterp:");
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
    v173 = v0;
/* end of prologue */
    v171 = v173;
    v171 = qcdr(v171);
    v172 = qcdr(v171);
    v171 = stack[0];
    v171 = qcdr(v171);
    v171 = qcdr(v171);
    if (equal(v172, v171)) goto v174;
    v171 = v173;
    fn = elt(env, 2); /* csl_normbf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v171);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-5];
    v171 = stack[0];
    fn = elt(env, 2); /* csl_normbf */
    v171 = (*qfn1(fn))(qenv(fn), v171);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-5];
    stack[0] = v171;
    v171 = stack[-1];
    v171 = qcdr(v171);
    v172 = qcdr(v171);
    v171 = stack[0];
    v171 = qcdr(v171);
    v171 = qcdr(v171);
    v173 = difference2(v172, v171);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-5];
    v171 = stack[-1];
    v171 = qcdr(v171);
    v172 = qcar(v171);
    v171 = stack[0];
    v171 = qcdr(v171);
    v171 = qcar(v171);
    stack[-4] = v173;
    stack[-3] = v172;
    stack[-2] = v171;
    v172 = stack[-4];
    v171 = (Lisp_Object)1; /* 0 */
    if (v172 == v171) goto v176;
    v172 = (Lisp_Object)33; /* 2 */
    v171 = qvalue(elt(env, 1)); /* !:bprec!: */
    v171 = times2(v172, v171);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-5];
    stack[-1] = v171;
    v172 = stack[-4];
    v171 = stack[-1];
    v171 = (Lisp_Object)greaterp2(v172, v171);
    nil = C_nil;
    if (exception_pending()) goto v175;
    v171 = v171 ? lisp_true : nil;
    env = stack[-5];
    if (v171 == nil) goto v177;
    v172 = stack[-3];
    v171 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Lgreaterp(nil, v172, v171);

v177:
    stack[0] = stack[-4];
    v171 = stack[-1];
    v171 = negate(v171);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-5];
    v171 = (Lisp_Object)lessp2(stack[0], v171);
    nil = C_nil;
    if (exception_pending()) goto v175;
    v171 = v171 ? lisp_true : nil;
    env = stack[-5];
    if (v171 == nil) goto v72;
    v172 = stack[-2];
    v171 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Llessp(nil, v172, v171);

v72:
    v172 = stack[-4];
    v171 = (Lisp_Object)1; /* 0 */
    v171 = (Lisp_Object)greaterp2(v172, v171);
    nil = C_nil;
    if (exception_pending()) goto v175;
    v171 = v171 ? lisp_true : nil;
    env = stack[-5];
    if (v171 == nil) goto v178;
    v172 = stack[-3];
    v171 = stack[-4];
    v172 = Lash1(nil, v172, v171);
    nil = C_nil;
    if (exception_pending()) goto v175;
    v171 = stack[-2];
        popv(6);
        return Lgreaterp(nil, v172, v171);

v178:
    stack[0] = stack[-3];
    stack[-1] = stack[-2];
    v171 = stack[-4];
    v171 = negate(v171);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-5];
    v171 = Lash1(nil, stack[-1], v171);
    nil = C_nil;
    if (exception_pending()) goto v175;
    {
        Lisp_Object v179 = stack[0];
        popv(6);
        return Lgreaterp(nil, v179, v171);
    }

v176:
    v172 = stack[-3];
    v171 = stack[-2];
        popv(6);
        return Lgreaterp(nil, v172, v171);

v174:
    v171 = v173;
    v171 = qcdr(v171);
    v172 = qcar(v171);
    v171 = stack[0];
    v171 = qcdr(v171);
    v171 = qcar(v171);
        popv(6);
        return Lgreaterp(nil, v172, v171);
/* error exit handlers */
v175:
    popv(6);
    return nil;
}



/* Code for ordpa */

static Lisp_Object CC_ordpa(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v187, v188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordpa");
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
    stack[-3] = v1;
    v187 = v0;
/* end of prologue */

v10:
    v186 = v187;
    if (v186 == nil) goto v99;
    v186 = stack[-3];
    if (v186 == nil) goto v134;
    v186 = v187;
    v186 = Lsimple_vectorp(nil, v186);
    env = stack[-5];
    if (v186 == nil) goto v189;
    v186 = stack[-3];
    v186 = Lsimple_vectorp(nil, v186);
    env = stack[-5];
    if (v186 == nil) goto v138;
    stack[-4] = v187;
    stack[-2] = stack[-3];
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v186 = v187;
    stack[0] = Lupbv(nil, v186);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    v186 = stack[-3];
    v186 = Lupbv(nil, v186);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    {
        Lisp_Object v190 = stack[-4];
        Lisp_Object v191 = stack[-2];
        Lisp_Object v192 = stack[-1];
        Lisp_Object v121 = stack[0];
        popv(6);
        fn = elt(env, 3); /* ordpv1 */
        return (*qfnn(fn))(qenv(fn), 5, v190, v191, v192, v121, v186);
    }

v138:
    v186 = stack[-3];
    v186 = (consp(v186) ? nil : lisp_true);
    { popv(6); return onevalue(v186); }

v189:
    v186 = v187;
    if (!consp(v186)) goto v140;
    v186 = stack[-3];
    if (!consp(v186)) goto v193;
    v186 = v187;
    v188 = qcar(v186);
    v186 = stack[-3];
    v186 = qcar(v186);
    if (equal(v188, v186)) goto v194;
    v186 = v187;
    v186 = qcar(v186);
    v187 = v186;
    v186 = stack[-3];
    v186 = qcar(v186);
    stack[-3] = v186;
    goto v10;

v194:
    v186 = v187;
    v186 = qcdr(v186);
    v187 = v186;
    v186 = stack[-3];
    v186 = qcdr(v186);
    stack[-3] = v186;
    goto v10;

v193:
    v186 = qvalue(elt(env, 1)); /* t */
    { popv(6); return onevalue(v186); }

v140:
    v186 = stack[-3];
    if (!consp(v186)) goto v195;
    v186 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v186); }

v195:
    v186 = v187;
    if (is_number(v186)) goto v196;
    v186 = stack[-3];
    if (symbolp(v186)) goto v162;
    v186 = stack[-3];
    v186 = (is_number(v186) ? lisp_true : nil);
    { popv(6); return onevalue(v186); }

v162:
    v186 = stack[-3];
        popv(6);
        return Lorderp(nil, v187, v186);

v196:
    v186 = stack[-3];
    if (is_number(v186)) goto v176;
    v186 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v186); }

v176:
    v186 = stack[-3];
    v186 = (Lisp_Object)lessp2(v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v72;
    v186 = v186 ? lisp_true : nil;
    v186 = (v186 == nil ? lisp_true : nil);
    { popv(6); return onevalue(v186); }

v134:
    v186 = qvalue(elt(env, 1)); /* t */
    { popv(6); return onevalue(v186); }

v99:
    v186 = stack[-3];
    v186 = (v186 == nil ? lisp_true : nil);
    { popv(6); return onevalue(v186); }
/* error exit handlers */
v72:
    popv(6);
    return nil;
}



/* Code for getphystype */

static Lisp_Object CC_getphystype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202, v177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystype");
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
    v202 = stack[0];
    fn = elt(env, 9); /* physopp */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-2];
    if (v202 == nil) goto v99;
    v202 = stack[0];
    fn = elt(env, 10); /* scalopp */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-2];
    if (v202 == nil) goto v141;
    v202 = elt(env, 1); /* scalar */
    { popv(3); return onevalue(v202); }

v141:
    v202 = stack[0];
    fn = elt(env, 11); /* vecopp */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-2];
    if (v202 == nil) goto v174;
    v202 = elt(env, 2); /* vector */
    { popv(3); return onevalue(v202); }

v174:
    v202 = stack[0];
    fn = elt(env, 12); /* tensopp */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-2];
    if (v202 == nil) goto v87;
    v202 = elt(env, 3); /* tensor */
    { popv(3); return onevalue(v202); }

v87:
    v202 = stack[0];
    fn = elt(env, 13); /* statep */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-2];
    if (v202 == nil) goto v137;
    v202 = elt(env, 4); /* state */
    { popv(3); return onevalue(v202); }

v137:
    v202 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v202); }

v99:
    v202 = stack[0];
    if (!consp(v202)) goto v168;
    v202 = stack[0];
    v177 = qcar(v202);
    v202 = elt(env, 6); /* phystype */
    v177 = get(v177, v202);
    env = stack[-2];
    v202 = v177;
    if (!(v177 == nil)) { popv(3); return onevalue(v202); }
    v202 = stack[0];
    v177 = qcar(v202);
    v202 = elt(env, 7); /* phystypefn */
    v177 = get(v177, v202);
    env = stack[-2];
    v202 = v177;
    if (v177 == nil) goto v204;
    v177 = v202;
    v202 = stack[0];
    v202 = qcdr(v202);
        popv(3);
        return Lapply1(nil, v177, v202);

v204:
    v202 = stack[0];
    fn = elt(env, 14); /* collectphystype */
    v177 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-2];
    v202 = v177;
    if (v177 == nil) goto v205;
    v177 = v202;
    v177 = qcdr(v177);
    if (v177 == nil) goto v164;
    v177 = elt(env, 4); /* state */
    v202 = Lmember(nil, v177, v202);
    if (v202 == nil) goto v79;
    v202 = elt(env, 4); /* state */
    { popv(3); return onevalue(v202); }

v79:
    stack[-1] = elt(env, 0); /* getphystype */
    v177 = elt(env, 8); /* "PHYSOP type conflict in" */
    v202 = stack[0];
    v202 = list2(v177, v202);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-2];
    {
        Lisp_Object v206 = stack[-1];
        popv(3);
        fn = elt(env, 15); /* rederr2 */
        return (*qfn2(fn))(qenv(fn), v206, v202);
    }

v164:
    v202 = qcar(v202);
    { popv(3); return onevalue(v202); }

v205:
    v202 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v202); }

v168:
    v202 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v202); }
/* error exit handlers */
v203:
    popv(3);
    return nil;
}



/* Code for mkid */

static Lisp_Object CC_mkid(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v204;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkid");
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
    v119 = v0;
/* end of prologue */
    v204 = v119;
    if (symbolp(v204)) goto v21;
    v204 = v119;
    v119 = elt(env, 1); /* "MKID root" */
    {
        popv(3);
        fn = elt(env, 3); /* typerr */
        return (*qfn2(fn))(qenv(fn), v204, v119);
    }

v21:
    v204 = stack[0];
    if (!(!consp(v204))) goto v209;
    v204 = stack[0];
    if (symbolp(v204)) goto v137;
    v204 = stack[0];
    v204 = integerp(v204);
    if (v204 == nil) goto v209;
    v204 = stack[0];
    v204 = Lminusp(nil, v204);
    env = stack[-2];
    if (!(v204 == nil)) goto v209;

v137:
    stack[-1] = Lexplode(nil, v119);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    v119 = stack[0];
    v119 = Lexplode(nil, v119);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    v119 = Lnconc(nil, stack[-1], v119);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-2];
    v119 = Lcompress(nil, v119);
    nil = C_nil;
    if (exception_pending()) goto v146;
        popv(3);
        return Lintern(nil, v119);

v209:
    v204 = stack[0];
    v119 = elt(env, 2); /* "MKID index" */
    {
        popv(3);
        fn = elt(env, 3); /* typerr */
        return (*qfn2(fn))(qenv(fn), v204, v119);
    }
/* error exit handlers */
v146:
    popv(3);
    return nil;
}



/* Code for ckpreci!# */

static Lisp_Object CC_ckpreciC(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v214, v215, v76, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ckpreci#");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v77 = v0;
/* end of prologue */
    v214 = v77;
    v215 = qcar(v214);
    v214 = elt(env, 1); /* times */
    if (!consp(v215)) goto v3;
    v215 = qcar(v215);
    if (!(v215 == v214)) goto v3;
    v215 = elt(env, 3); /* i */
    v214 = v77;
    v214 = qcar(v214);
    v214 = qcdr(v214);
    v214 = Lmemq(nil, v215, v214);
    v76 = v214;
    goto v137;

v137:
    v214 = v77;
    v214 = qcdr(v214);
    v215 = qcar(v214);
    v214 = elt(env, 1); /* times */
    if (!consp(v215)) goto v125;
    v215 = qcar(v215);
    if (!(v215 == v214)) goto v125;
    v215 = elt(env, 3); /* i */
    v214 = v77;
    v214 = qcdr(v214);
    v214 = qcar(v214);
    v214 = qcdr(v214);
    v214 = Lmemq(nil, v215, v214);
    goto v124;

v124:
    v215 = v214;
    v214 = qvalue(elt(env, 4)); /* !*complex */
    if (v214 == nil) goto v196;
    v214 = v76;
    if (v214 == nil) goto v166;
    v214 = v215;
    if (!(v214 == nil)) goto v166;
    v214 = v77;
    v214 = qcar(v214);
    v214 = qcdr(v214);
    v215 = v77;
    v215 = qcdr(v215);
    v215 = qcar(v215);
    {
        fn = elt(env, 5); /* ckprec2!# */
        return (*qfn2(fn))(qenv(fn), v214, v215);
    }

v166:
    v214 = v215;
    if (v214 == nil) goto v163;
    v214 = v76;
    if (!(v214 == nil)) goto v163;
    v214 = v77;
    v214 = qcdr(v214);
    v214 = qcar(v214);
    v214 = qcdr(v214);
    v215 = v77;
    v215 = qcar(v215);
    {
        fn = elt(env, 5); /* ckprec2!# */
        return (*qfn2(fn))(qenv(fn), v214, v215);
    }

v163:
    v214 = nil;
    return onevalue(v214);

v196:
    v214 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v214);

v125:
    v214 = qvalue(elt(env, 2)); /* nil */
    goto v124;

v3:
    v214 = qvalue(elt(env, 2)); /* nil */
    v76 = v214;
    goto v137;
}



/* Code for rnplus!: */

static Lisp_Object CC_rnplusT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v207, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnplus:");
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
    v207 = stack[-1];
    v207 = qcdr(v207);
    v119 = qcar(v207);
    v207 = stack[0];
    v207 = qcdr(v207);
    v207 = qcdr(v207);
    stack[-2] = times2(v119, v207);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    v207 = stack[-1];
    v207 = qcdr(v207);
    v119 = qcdr(v207);
    v207 = stack[0];
    v207 = qcdr(v207);
    v207 = qcar(v207);
    v207 = times2(v119, v207);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    stack[-2] = plus2(stack[-2], v207);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    v207 = stack[-1];
    v207 = qcdr(v207);
    v119 = qcdr(v207);
    v207 = stack[0];
    v207 = qcdr(v207);
    v207 = qcdr(v207);
    v207 = times2(v119, v207);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    {
        Lisp_Object v148 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v148, v207);
    }
/* error exit handlers */
v146:
    popv(4);
    return nil;
}



/* Code for mo!=deglist */

static Lisp_Object CC_moMdeglist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=deglist");
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
    v192 = stack[-4];
    if (v192 == nil) goto v3;
    v192 = stack[-4];
    v121 = qcar(v192);
    v192 = qvalue(elt(env, 3)); /* cali!=degrees */
    v192 = Lassoc(nil, v121, v192);
    stack[-5] = v192;
    v192 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_degrees */
    v192 = (*qfn1(fn))(qenv(fn), v192);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-6];
    stack[-3] = v192;
    v192 = stack[-3];
    if (v192 == nil) goto v165;
    v192 = stack[-3];
    v192 = qcar(v192);
    v121 = stack[-4];
    v121 = qcdr(v121);
    fn = elt(env, 5); /* mo!=sprod */
    v192 = (*qfn2(fn))(qenv(fn), v121, v192);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-6];
    v192 = ncons(v192);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-6];
    stack[-1] = v192;
    stack[-2] = v192;
    goto v176;

v176:
    v192 = stack[-3];
    v192 = qcdr(v192);
    stack[-3] = v192;
    v192 = stack[-3];
    if (v192 == nil) goto v79;
    stack[0] = stack[-1];
    v192 = stack[-3];
    v192 = qcar(v192);
    v121 = stack[-4];
    v121 = qcdr(v121);
    fn = elt(env, 5); /* mo!=sprod */
    v192 = (*qfn2(fn))(qenv(fn), v121, v192);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-6];
    v192 = ncons(v192);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-6];
    v192 = Lrplacd(nil, stack[0], v192);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-6];
    v192 = stack[-1];
    v192 = qcdr(v192);
    stack[-1] = v192;
    goto v176;

v79:
    v192 = stack[-2];
    v121 = v192;
    goto v220;

v220:
    v192 = stack[-5];
    if (v192 == nil) goto v72;
    v192 = stack[-5];
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    goto v221;

v221:
    {
        popv(7);
        fn = elt(env, 6); /* mo!=sum */
        return (*qfn2(fn))(qenv(fn), v121, v192);
    }

v72:
    v192 = qvalue(elt(env, 2)); /* nil */
    goto v221;

v165:
    v192 = qvalue(elt(env, 2)); /* nil */
    v121 = v192;
    goto v220;

v3:
    v192 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_degrees */
    v192 = (*qfn1(fn))(qenv(fn), v192);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-6];
    stack[-3] = v192;
    v192 = stack[-3];
    if (v192 == nil) goto v170;
    v192 = (Lisp_Object)1; /* 0 */
    v192 = ncons(v192);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-6];
    stack[-1] = v192;
    stack[-2] = v192;
    goto v126;

v126:
    v192 = stack[-3];
    v192 = qcdr(v192);
    stack[-3] = v192;
    v192 = stack[-3];
    if (v192 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v192 = (Lisp_Object)1; /* 0 */
    v192 = ncons(v192);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-6];
    v192 = Lrplacd(nil, stack[0], v192);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-6];
    v192 = stack[-1];
    v192 = qcdr(v192);
    stack[-1] = v192;
    goto v126;

v170:
    v192 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v192); }
/* error exit handlers */
v69:
    popv(7);
    return nil;
}



/* Code for psum */

static Lisp_Object CC_psum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v173, v226;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for psum");
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
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v172 = stack[-6];
    if (v172 == nil) goto v141;
    v172 = stack[-5];
    if (!(v172 == nil)) goto v123;
    v172 = stack[-6];
    stack[-2] = v172;
    { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }

v123:
    v172 = stack[-5];
    if (v172 == nil) { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }
    v172 = stack[-1];
    if (!(v172 == nil)) { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }
    v172 = stack[-5];
    v172 = qcar(v172);
    stack[0] = v172;
    v172 = stack[0];
    v172 = qcar(v172);
    stack[-7] = v172;
    goto v88;

v88:
    v172 = stack[-6];
    if (v172 == nil) goto v185;
    v173 = stack[-7];
    v172 = stack[-6];
    v172 = qcar(v172);
    v172 = qcar(v172);
    fn = elt(env, 3); /* dless */
    v172 = (*qfn2(fn))(qenv(fn), v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    if (v172 == nil) goto v185;
    v172 = stack[-6];
    v173 = qcar(v172);
    v172 = stack[-3];
    v172 = cons(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    stack[-3] = v172;
    v172 = stack[-6];
    v172 = qcdr(v172);
    stack[-6] = v172;
    goto v88;

v185:
    v172 = stack[-6];
    if (v172 == nil) goto v83;
    v172 = stack[-6];
    v172 = qcar(v172);
    v226 = v172;
    v173 = stack[-7];
    v172 = v226;
    v172 = qcar(v172);
    if (equal(v173, v172)) goto v214;
    v173 = stack[0];
    v172 = stack[-3];
    v172 = cons(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    stack[-3] = v172;
    goto v218;

v218:
    v172 = stack[-5];
    v172 = qcdr(v172);
    stack[-5] = v172;
    v172 = stack[-5];
    if (!(v172 == nil)) goto v123;
    v172 = stack[-3];
    v173 = Lreverse(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    v172 = stack[-6];
    v172 = Lappend(nil, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    stack[-2] = v172;
    goto v123;

v214:
    v172 = v226;
    v173 = qcdr(v172);
    v172 = stack[0];
    v172 = qcdr(v172);
    fn = elt(env, 4); /* csum */
    v172 = (*qfn2(fn))(qenv(fn), v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    stack[-4] = v172;
    stack[0] = stack[-4];
    fn = elt(env, 5); /* c_zero */
    v172 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    if (equal(stack[0], v172)) goto v228;
    v226 = stack[-7];
    v173 = stack[-4];
    v172 = stack[-3];
    v172 = acons(v226, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    stack[-3] = v172;
    goto v228;

v228:
    v172 = stack[-6];
    v172 = qcdr(v172);
    stack[-6] = v172;
    v172 = stack[-6];
    if (v172 == nil) goto v218;
    else goto v218;

v83:
    v172 = stack[-3];
    v173 = Lreverse(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    v172 = stack[-5];
    v172 = Lappend(nil, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-8];
    stack[-2] = v172;
    v172 = qvalue(elt(env, 2)); /* t */
    stack[-1] = v172;
    goto v123;

v141:
    v172 = stack[-5];
    stack[-2] = v172;
    { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }
/* error exit handlers */
v227:
    popv(9);
    return nil;
}



/* Code for vecp */

static Lisp_Object CC_vecp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v197, v214, v215, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vecp");
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
    v215 = v0;
/* end of prologue */
    v197 = v215;
    if (v197 == nil) goto v2;
    v197 = v215;
    if (is_number(v197)) goto v2;
    v197 = v215;
    if (!consp(v197)) goto v123;
    v197 = v215;
    v197 = Lthreevectorp(nil, v197);
    env = stack[0];
    if (v197 == nil) goto v208;
    v197 = qvalue(elt(env, 4)); /* t */
    { popv(1); return onevalue(v197); }

v208:
    v197 = v215;
    v197 = qcar(v197);
    v76 = v197;
    if (!(!consp(v197))) goto v166;
    v214 = v76;
    v197 = elt(env, 2); /* rtype */
    v214 = get(v214, v197);
    env = stack[0];
    v197 = elt(env, 3); /* !3vector */
    if (!(v214 == v197)) goto v166;
    v197 = v215;
    v197 = qcdr(v197);
    v197 = qcar(v197);
    {
        popv(1);
        fn = elt(env, 8); /* isvectorindex */
        return (*qfn1(fn))(qenv(fn), v197);
    }

v166:
    v214 = v76;
    v197 = elt(env, 5); /* vectorfn */
    v197 = Lflagp(nil, v214, v197);
    env = stack[0];
    if (v197 == nil) goto v229;
    v197 = qvalue(elt(env, 4)); /* t */
    { popv(1); return onevalue(v197); }

v229:
    v214 = v76;
    v197 = elt(env, 6); /* varithop */
    v197 = Lflagp(nil, v214, v197);
    env = stack[0];
    if (!(v197 == nil)) goto v164;
    v214 = v76;
    v197 = elt(env, 7); /* vectormapping */
    v197 = Lflagp(nil, v214, v197);
    env = stack[0];
    if (!(v197 == nil)) goto v164;
    v197 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v197); }

v164:
    v197 = v215;
    v197 = qcdr(v197);
    {
        popv(1);
        fn = elt(env, 9); /* hasonevector */
        return (*qfn1(fn))(qenv(fn), v197);
    }

v123:
    v214 = v215;
    v197 = elt(env, 2); /* rtype */
    v197 = get(v214, v197);
    env = stack[0];
    v214 = elt(env, 3); /* !3vector */
    v197 = (v197 == v214 ? lisp_true : nil);
    if (!(v197 == nil)) { popv(1); return onevalue(v197); }
    v197 = v215;
        popv(1);
        return Lthreevectorp(nil, v197);

v2:
    v197 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v197); }
}



/* Code for pappl_pv */

static Lisp_Object CC_pappl_pv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pappl_pv");
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
    v165 = v1;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = v165;
    v165 = stack[-5];
    if (v165 == nil) goto v134;
    v165 = stack[-5];
    v165 = qcar(v165);
    v164 = v165;
    stack[0] = qcar(v164);
    v164 = stack[-4];
    v165 = qcdr(v165);
    fn = elt(env, 2); /* pappl0 */
    v165 = (*qfn2(fn))(qenv(fn), v164, v165);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-6];
    v165 = cons(stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-6];
    v165 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-6];
    stack[-2] = v165;
    stack[-3] = v165;
    goto v133;

v133:
    v165 = stack[-5];
    v165 = qcdr(v165);
    stack[-5] = v165;
    v165 = stack[-5];
    if (v165 == nil) goto v88;
    stack[-1] = stack[-2];
    v165 = stack[-5];
    v165 = qcar(v165);
    v164 = v165;
    stack[0] = qcar(v164);
    v164 = stack[-4];
    v165 = qcdr(v165);
    fn = elt(env, 2); /* pappl0 */
    v165 = (*qfn2(fn))(qenv(fn), v164, v165);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-6];
    v165 = cons(stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-6];
    v165 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-6];
    v165 = Lrplacd(nil, stack[-1], v165);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-6];
    v165 = stack[-2];
    v165 = qcdr(v165);
    stack[-2] = v165;
    goto v133;

v88:
    v165 = stack[-3];
    goto v99;

v99:
    {
        popv(7);
        fn = elt(env, 3); /* pv_sort */
        return (*qfn1(fn))(qenv(fn), v165);
    }

v134:
    v165 = qvalue(elt(env, 1)); /* nil */
    goto v99;
/* error exit handlers */
v233:
    popv(7);
    return nil;
}



/* Code for general!-modular!-reciprocal */

static Lisp_Object CC_generalKmodularKreciprocal(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v213, v195, v146, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-reciprocal");
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
    v213 = qvalue(elt(env, 1)); /* !*balanced_mod */
    if (v213 == nil) goto v185;
    v195 = stack[0];
    v213 = (Lisp_Object)1; /* 0 */
    v213 = (Lisp_Object)lessp2(v195, v213);
    nil = C_nil;
    if (exception_pending()) goto v196;
    v213 = v213 ? lisp_true : nil;
    env = stack[-2];
    if (v213 == nil) goto v185;
    stack[-1] = qvalue(elt(env, 2)); /* current!-modulus */
    v195 = stack[0];
    v213 = qvalue(elt(env, 2)); /* current!-modulus */
    v146 = plus2(v195, v213);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-2];
    v195 = (Lisp_Object)1; /* 0 */
    v213 = (Lisp_Object)17; /* 1 */
    {
        Lisp_Object v200 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* general!-reciprocal!-by!-gcd */
        return (*qfnn(fn))(qenv(fn), 4, v200, v146, v195, v213);
    }

v185:
    v148 = qvalue(elt(env, 2)); /* current!-modulus */
    v146 = stack[0];
    v195 = (Lisp_Object)1; /* 0 */
    v213 = (Lisp_Object)17; /* 1 */
    {
        popv(3);
        fn = elt(env, 3); /* general!-reciprocal!-by!-gcd */
        return (*qfnn(fn))(qenv(fn), 4, v148, v146, v195, v213);
    }
/* error exit handlers */
v196:
    popv(3);
    return nil;
}



/* Code for lto_catsoc */

static Lisp_Object CC_lto_catsoc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v174, v232;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_catsoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v174 = v1;
    v232 = v0;
/* end of prologue */
    v174 = Latsoc(nil, v232, v174);
    v232 = v174;
    v174 = v232;
    if (v174 == nil) goto v130;
    v174 = v232;
    v174 = qcdr(v174);
    return onevalue(v174);

v130:
    v174 = nil;
    return onevalue(v174);
}



/* Code for comfac */

static Lisp_Object CC_comfac(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v222;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comfac");
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
    v222 = qvalue(elt(env, 1)); /* dmode!* */
    v149 = elt(env, 2); /* field */
    v149 = Lflagp(nil, v222, v149);
    env = stack[-4];
    if (v149 == nil) goto v99;
    v149 = stack[-2];
    fn = elt(env, 5); /* lnc */
    v222 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-4];
    stack[-3] = v222;
    v149 = (Lisp_Object)17; /* 1 */
    if (v222 == v149) goto v99;
    v149 = stack[-3];
    fn = elt(env, 6); /* !:recip */
    v222 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-4];
    v149 = stack[-2];
    fn = elt(env, 7); /* multd */
    v149 = (*qfn2(fn))(qenv(fn), v222, v149);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-4];
    stack[-2] = v149;
    goto v99;

v99:
    v149 = stack[-2];
    v149 = qcdr(v149);
    if (v149 == nil) goto v136;
    v149 = stack[-2];
    v149 = qcar(v149);
    v149 = qcdr(v149);
    stack[-3] = v149;
    v149 = stack[-2];
    v149 = qcar(v149);
    v149 = qcar(v149);
    v149 = qcar(v149);
    stack[-1] = v149;
    goto v21;

v21:
    v149 = stack[-2];
    v149 = qcdr(v149);
    stack[-2] = v149;
    v222 = stack[-2];
    v149 = stack[-1];
    fn = elt(env, 8); /* degr */
    v222 = (*qfn2(fn))(qenv(fn), v222, v149);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-4];
    v149 = (Lisp_Object)1; /* 0 */
    if (v222 == v149) goto v183;
    v149 = stack[-2];
    v149 = qcdr(v149);
    if (v149 == nil) goto v224;
    v149 = stack[-2];
    v149 = qcar(v149);
    v222 = qcdr(v149);
    v149 = stack[-3];
    fn = elt(env, 9); /* gcdf */
    v149 = (*qfn2(fn))(qenv(fn), v222, v149);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-4];
    stack[-3] = v149;
    goto v21;

v224:
    v149 = stack[-2];
    v149 = qcar(v149);
    stack[0] = qcar(v149);
    v222 = stack[-3];
    v149 = stack[-2];
    v149 = qcar(v149);
    v149 = qcdr(v149);
    fn = elt(env, 9); /* gcdf */
    v149 = (*qfn2(fn))(qenv(fn), v222, v149);
    nil = C_nil;
    if (exception_pending()) goto v238;
    {
        Lisp_Object v239 = stack[0];
        popv(5);
        return cons(v239, v149);
    }

v183:
    stack[0] = qvalue(elt(env, 3)); /* nil */
    v149 = stack[-2];
    if (!consp(v149)) goto v77;
    v149 = stack[-2];
    v149 = qcar(v149);
    if (!consp(v149)) goto v77;
    v149 = qvalue(elt(env, 4)); /* !*ncmp */
    if (v149 == nil) goto v77;
    v149 = stack[-1];
    fn = elt(env, 10); /* noncomp1 */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-4];
    if (v149 == nil) goto v77;
    v149 = qvalue(elt(env, 4)); /* !*ncmp */
    if (v149 == nil) goto v77;
    v149 = stack[-2];
    v149 = qcar(v149);
    v149 = qcar(v149);
    v149 = qcar(v149);
    fn = elt(env, 10); /* noncomp1 */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v238;
    env = stack[-4];
    if (v149 == nil) goto v77;
    v149 = (Lisp_Object)17; /* 1 */
    goto v164;

v164:
    {
        Lisp_Object v240 = stack[0];
        popv(5);
        return cons(v240, v149);
    }

v77:
    v222 = stack[-3];
    v149 = stack[-2];
    fn = elt(env, 9); /* gcdf */
    v149 = (*qfn2(fn))(qenv(fn), v222, v149);
    nil = C_nil;
    if (exception_pending()) goto v238;
    goto v164;

v136:
    v149 = stack[-2];
    v149 = qcar(v149);
    { popv(5); return onevalue(v149); }
/* error exit handlers */
v238:
    popv(5);
    return nil;
}



/* Code for kernp */

static Lisp_Object CC_kernp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v216, v196, v200;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v196 = v0;
/* end of prologue */
    v216 = v196;
    v200 = qcdr(v216);
    v216 = (Lisp_Object)17; /* 1 */
    if (v200 == v216) goto v10;
    v216 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v216);

v10:
    v216 = v196;
    v216 = qcar(v216);
    v196 = v216;
    v200 = v216;
    v216 = v200;
    v216 = (consp(v216) ? nil : lisp_true);
    if (!(v216 == nil)) goto v100;
    v216 = v200;
    v216 = qcar(v216);
    v216 = (consp(v216) ? nil : lisp_true);
    goto v100;

v100:
    if (v216 == nil) goto v98;
    v216 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v216);

v98:
    v216 = v196;
    v216 = qcdr(v216);
    if (v216 == nil) goto v168;
    v216 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v216);

v168:
    v216 = v196;
    v216 = qcar(v216);
    v200 = qcdr(v216);
    v216 = (Lisp_Object)17; /* 1 */
    if (v200 == v216) goto v139;
    v216 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v216);

v139:
    v216 = v196;
    v216 = qcar(v216);
    v216 = qcar(v216);
    v196 = qcdr(v216);
    v216 = (Lisp_Object)17; /* 1 */
    v216 = (v196 == v216 ? lisp_true : nil);
    return onevalue(v216);
}



/* Code for symbol */

static Lisp_Object CC_symbol(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v97;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbol");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v105 = v0;
/* end of prologue */
    v97 = elt(env, 1); /* symbol!-character */
    return get(v105, v97);
}



/* Code for rl_susitf */

static Lisp_Object CC_rl_susitf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v189, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_susitf");
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
    v189 = v1;
    v174 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_susitf!* */
    v189 = list2(v174, v189);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    {
        Lisp_Object v128 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v128, v189);
    }
/* error exit handlers */
v100:
    popv(2);
    return nil;
}



/* Code for ibalp_istotal */

static Lisp_Object CC_ibalp_istotal(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v129;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_istotal");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v128 = v0;
/* end of prologue */

v241:
    v129 = v128;
    v129 = (v129 == nil ? lisp_true : nil);
    if (!(v129 == nil)) return onevalue(v129);
    v129 = v128;
    v129 = qcar(v129);
    v129 = qcdr(v129);
    v129 = qcdr(v129);
    v129 = qcar(v129);
    if (v129 == nil) goto v133;
    v128 = qcdr(v128);
    goto v241;

v133:
    v128 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v128);
}



/* Code for objectom */

static Lisp_Object CC_objectom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v103, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for objectom");
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
    v103 = v0;
/* end of prologue */
    v138 = v103;
    v138 = Lconsp(nil, v138);
    env = stack[-1];
    if (v138 == nil) goto v88;
    v138 = v103;
    v139 = qcar(v138);
    v138 = qvalue(elt(env, 1)); /* ir2mml!* */
    v138 = Lassoc(nil, v139, v138);
    v139 = v138;
    if (v138 == nil) goto v169;
    v138 = v139;
    v138 = qcdr(v138);
    v138 = qcdr(v138);
    v138 = qcdr(v138);
    stack[0] = qcar(v138);
    v138 = v103;
    v138 = ncons(v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-1];
    fn = elt(env, 3); /* apply */
    v138 = (*qfn2(fn))(qenv(fn), stack[0], v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    goto v21;

v21:
    v138 = nil;
    { popv(2); return onevalue(v138); }

v169:
    v138 = v103;
    fn = elt(env, 4); /* fnom */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    goto v21;

v88:
    v138 = v103;
    fn = elt(env, 5); /* basicom */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v140;
    goto v21;
/* error exit handlers */
v140:
    popv(2);
    return nil;
}



/* Code for c!:extmult */

static Lisp_Object CC_cTextmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v242, v243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:extmult");
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
    v242 = stack[-2];
    if (v242 == nil) goto v10;
    v242 = stack[-1];
    if (v242 == nil) goto v10;
    v243 = stack[-1];
    v242 = (Lisp_Object)17; /* 1 */
    if (v243 == v242) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v242 = stack[-2];
    v242 = qcar(v242);
    v242 = qcar(v242);
    v243 = qcar(v242);
    v242 = stack[-1];
    v242 = qcar(v242);
    v242 = qcar(v242);
    fn = elt(env, 2); /* c!:ordexn */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    v243 = v242;
    v242 = v243;
    if (v242 == nil) goto v156;
    v242 = v243;
    stack[0] = qcdr(v242);
    v242 = v243;
    v242 = qcar(v242);
    if (v242 == nil) goto v235;
    v242 = stack[-2];
    v242 = qcar(v242);
    v243 = qcdr(v242);
    v242 = stack[-1];
    v242 = qcar(v242);
    v242 = qcdr(v242);
    fn = elt(env, 3); /* c!:subs2multf */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    fn = elt(env, 4); /* negf */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    goto v213;

v213:
    v242 = cons(stack[0], v242);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    stack[-3] = ncons(v242);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    v242 = stack[-2];
    v242 = qcar(v242);
    v243 = ncons(v242);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    v242 = stack[-1];
    v242 = qcdr(v242);
    stack[0] = CC_cTextmult(env, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    v242 = stack[-2];
    v243 = qcdr(v242);
    v242 = stack[-1];
    v242 = CC_cTextmult(env, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    fn = elt(env, 5); /* c!:extadd */
    v242 = (*qfn2(fn))(qenv(fn), stack[0], v242);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    {
        Lisp_Object v149 = stack[-3];
        popv(5);
        fn = elt(env, 5); /* c!:extadd */
        return (*qfn2(fn))(qenv(fn), v149, v242);
    }

v235:
    v242 = stack[-2];
    v242 = qcar(v242);
    v243 = qcdr(v242);
    v242 = stack[-1];
    v242 = qcar(v242);
    v242 = qcdr(v242);
    fn = elt(env, 3); /* c!:subs2multf */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    goto v213;

v156:
    v242 = stack[-2];
    v242 = qcar(v242);
    v243 = ncons(v242);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    v242 = stack[-1];
    v242 = qcdr(v242);
    stack[0] = CC_cTextmult(env, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    v242 = stack[-2];
    v243 = qcdr(v242);
    v242 = stack[-1];
    v242 = CC_cTextmult(env, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-4];
    {
        Lisp_Object v222 = stack[0];
        popv(5);
        fn = elt(env, 5); /* c!:extadd */
        return (*qfn2(fn))(qenv(fn), v222, v242);
    }

v10:
    v242 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v242); }
/* error exit handlers */
v152:
    popv(5);
    return nil;
}



/* Code for unbind */

static Lisp_Object CC_unbind(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v128, v129, v87;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unbind");
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
    v100 = v0;
/* end of prologue */
    v87 = v100;
    v129 = elt(env, 1); /* binding */
    v128 = v100;
    v100 = elt(env, 1); /* binding */
    v100 = get(v128, v100);
    v100 = qcdr(v100);
        return Lputprop(nil, 3, v87, v129, v100);
}



/* Code for off */

static Lisp_Object CC_off(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for off");
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
    v123 = v0;
/* end of prologue */
    stack[0] = v123;
    goto v10;

v10:
    v123 = stack[0];
    if (v123 == nil) goto v133;
    v123 = stack[0];
    v123 = qcar(v123);
    v132 = v123;
    v123 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* onoff */
    v123 = (*qfn2(fn))(qenv(fn), v132, v123);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-1];
    v123 = stack[0];
    v123 = qcdr(v123);
    stack[0] = v123;
    goto v10;

v133:
    v123 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v123); }
/* error exit handlers */
v124:
    popv(2);
    return nil;
}



/* Code for deg!*form */

static Lisp_Object CC_degHform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59, v249;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deg*form");
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

v241:
    v58 = stack[0];
    if (!consp(v58)) goto v99;
    v58 = stack[0];
    v58 = qcar(v58);
    v249 = v58;
    v59 = v249;
    v58 = elt(env, 3); /* indexvar */
    v58 = Lflagp(nil, v59, v58);
    env = stack[-2];
    if (v58 == nil) goto v183;
    v58 = stack[0];
    v58 = qcdr(v58);
    v249 = Llength(nil, v58);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-2];
    v58 = stack[0];
    v59 = qcar(v58);
    v58 = elt(env, 4); /* ifdegree */
    v58 = get(v59, v58);
    env = stack[-2];
    v58 = Lassoc(nil, v249, v58);
    v59 = v58;
    v58 = v59;
    if (v58 == nil) goto v166;
    v58 = v59;
    v58 = qcdr(v58);
    { popv(3); return onevalue(v58); }

v166:
    v58 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v58); }

v183:
    v59 = v249;
    v58 = elt(env, 5); /* wedge */
    if (v59 == v58) goto v205;
    v59 = v249;
    v58 = elt(env, 6); /* d */
    if (v59 == v58) goto v80;
    v59 = v249;
    v58 = elt(env, 7); /* hodge */
    if (v59 == v58) goto v228;
    v59 = v249;
    v58 = elt(env, 9); /* partdf */
    if (v59 == v58) goto v188;
    v59 = v249;
    v58 = elt(env, 10); /* liedf */
    if (v59 == v58) goto v242;
    v59 = v249;
    v58 = elt(env, 11); /* innerprod */
    if (v59 == v58) goto v145;
    v59 = v249;
    v58 = elt(env, 12); /* (plus minus difference quotient) */
    v58 = Lmemq(nil, v59, v58);
    if (v58 == nil) goto v251;
    v58 = stack[0];
    v58 = qcdr(v58);
    v58 = qcar(v58);
    stack[0] = v58;
    goto v241;

v251:
    v59 = v249;
    v58 = elt(env, 13); /* times */
    if (v59 == v58) goto v252;
    v58 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v58); }

v252:
    v58 = stack[0];
    v58 = qcdr(v58);
    {
        popv(3);
        fn = elt(env, 14); /* deg!*farg */
        return (*qfn1(fn))(qenv(fn), v58);
    }

v145:
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v58 = stack[0];
    v58 = qcdr(v58);
    v58 = qcdr(v58);
    v58 = qcar(v58);
    v58 = CC_degHform(env, v58);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-2];
    {
        Lisp_Object v253 = stack[-1];
        popv(3);
        fn = elt(env, 15); /* addd */
        return (*qfn2(fn))(qenv(fn), v253, v58);
    }

v242:
    v58 = stack[0];
    v58 = qcdr(v58);
    v58 = qcdr(v58);
    v58 = qcar(v58);
    stack[0] = v58;
    goto v241;

v188:
    v58 = stack[0];
    v58 = qcdr(v58);
    v58 = qcdr(v58);
    if (v58 == nil) goto v69;
    v58 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v58); }

v69:
    v58 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v58); }

v228:
    stack[-1] = qvalue(elt(env, 8)); /* dimex!* */
    v58 = stack[0];
    v58 = qcdr(v58);
    v58 = qcar(v58);
    v58 = CC_degHform(env, v58);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-2];
    fn = elt(env, 16); /* negf */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-2];
    {
        Lisp_Object v254 = stack[-1];
        popv(3);
        fn = elt(env, 17); /* addf */
        return (*qfn2(fn))(qenv(fn), v254, v58);
    }

v80:
    stack[-1] = (Lisp_Object)17; /* 1 */
    v58 = stack[0];
    v58 = qcdr(v58);
    v58 = qcar(v58);
    v58 = CC_degHform(env, v58);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-2];
    {
        Lisp_Object v255 = stack[-1];
        popv(3);
        fn = elt(env, 15); /* addd */
        return (*qfn2(fn))(qenv(fn), v255, v58);
    }

v205:
    v58 = stack[0];
    v58 = qcdr(v58);
    {
        popv(3);
        fn = elt(env, 14); /* deg!*farg */
        return (*qfn1(fn))(qenv(fn), v58);
    }

v99:
    v59 = stack[0];
    v58 = elt(env, 1); /* fdegree */
    v58 = get(v59, v58);
    env = stack[-2];
    v59 = v58;
    v58 = v59;
    if (v58 == nil) goto v129;
    v58 = v59;
    v58 = qcar(v58);
    { popv(3); return onevalue(v58); }

v129:
    v58 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v58); }
/* error exit handlers */
v250:
    popv(3);
    return nil;
}



/* Code for formprogn */

static Lisp_Object MS_CDECL CC_formprogn(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v131, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v87, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formprogn");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formprogn");
#endif
    if (stack >= stacklimit)
    {
        push3(v131,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v131);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v129 = v131;
    v87 = v1;
    v122 = v0;
/* end of prologue */
    stack[0] = elt(env, 1); /* progn */
    v122 = qcdr(v122);
    fn = elt(env, 2); /* formclis */
    v129 = (*qfnn(fn))(qenv(fn), 3, v122, v87, v129);
    nil = C_nil;
    if (exception_pending()) goto v132;
    {
        Lisp_Object v212 = stack[0];
        popv(1);
        return cons(v212, v129);
    }
/* error exit handlers */
v132:
    popv(1);
    return nil;
}



/* Code for red!-ratios2 */

static Lisp_Object MS_CDECL CC_redKratios2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v131, Lisp_Object v225, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v193, v160, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "red-ratios2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-ratios2");
#endif
    if (stack >= stacklimit)
    {
        push4(v225,v131,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v131,v225);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v225;
    stack[-2] = v131;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */

v241:
    v79 = stack[-4];
    if (v79 == nil) goto v97;
    v193 = stack[-2];
    v79 = stack[-3];
    v79 = qcar(v79);
    stack[0] = times2(v193, v79);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    stack[-5] = stack[0];
    v193 = stack[-1];
    v79 = stack[-4];
    v79 = qcar(v79);
    v79 = times2(v193, v79);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    if (!(equal(stack[0], v79))) goto v210;
    v193 = stack[-5];
    v79 = (Lisp_Object)1; /* 0 */
    if (v193 == v79) goto v210;
    v193 = stack[-1];
    v79 = stack[-2];
    v193 = Lgcd(nil, v193, v79);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    v79 = stack[-1];
    v193 = Cremainder(v193, v79);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-6];
    v79 = (Lisp_Object)1; /* 0 */
    if (!(v193 == v79)) goto v210;
    v193 = stack[-1];
    v79 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* red!-lowest!-terms */
        return (*qfn2(fn))(qenv(fn), v193, v79);
    }

v210:
    v79 = stack[-4];
    v161 = qcdr(v79);
    v79 = stack[-3];
    v160 = qcdr(v79);
    v193 = stack[-2];
    v79 = stack[-1];
    stack[-4] = v161;
    stack[-3] = v160;
    stack[-2] = v193;
    stack[-1] = v79;
    goto v241;

v97:
    v79 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v79); }
/* error exit handlers */
v77:
    popv(7);
    return nil;
}



/* Code for divd */

static Lisp_Object CC_divd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v177, v236;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for divd");
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
    goto v21;

v21:
    v177 = stack[-1];
    if (v177 == nil) goto v133;
    v177 = stack[-2];
    if (v177 == nil) goto v216;
    v177 = stack[-2];
    if (!consp(v177)) goto v205;
    v177 = stack[-2];
    v177 = qcar(v177);
    if (!consp(v177)) goto v205;
    v177 = stack[-2];
    v177 = qcar(v177);
    stack[0] = qcar(v177);
    v177 = stack[-2];
    v177 = qcar(v177);
    v236 = qcdr(v177);
    v177 = stack[-1];
    v236 = CC_divd(env, v236, v177);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-4];
    v177 = stack[-3];
    v177 = acons(stack[0], v236, v177);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-4];
    stack[-3] = v177;
    v177 = stack[-2];
    v177 = qcdr(v177);
    stack[-2] = v177;
    goto v21;

v205:
    stack[0] = stack[-3];
    v236 = stack[-2];
    v177 = stack[-1];
    fn = elt(env, 5); /* divdm */
    v177 = (*qfn2(fn))(qenv(fn), v236, v177);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-4];
    {
        Lisp_Object v74 = stack[0];
        popv(5);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v74, v177);
    }

v216:
    v177 = stack[-3];
    {
        popv(5);
        fn = elt(env, 6); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v177);
    }

v133:
    v177 = stack[-2];
    if (v177 == nil) goto v189;
    stack[0] = stack[-3];
    v177 = elt(env, 4); /* "Zero divisor" */
    v236 = v177;
    v177 = v236;
    qvalue(elt(env, 2)) = v177; /* errmsg!* */
    v177 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v177 == nil)) goto v119;
    v177 = v236;
    fn = elt(env, 7); /* lprie */
    v177 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-4];
    goto v119;

v119:
    v177 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-4];
    v177 = nil;
    {
        Lisp_Object v75 = stack[0];
        popv(5);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v75, v177);
    }

v189:
    stack[0] = stack[-3];
    v177 = elt(env, 1); /* "0/0 formed" */
    v236 = v177;
    v177 = v236;
    qvalue(elt(env, 2)) = v177; /* errmsg!* */
    v177 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v177 == nil)) goto v125;
    v177 = v236;
    fn = elt(env, 7); /* lprie */
    v177 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-4];
    goto v125;

v125:
    v177 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-4];
    v177 = nil;
    {
        Lisp_Object v256 = stack[0];
        popv(5);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v256, v177);
    }
/* error exit handlers */
v158:
    popv(5);
    return nil;
}



/* Code for bas_make1 */

static Lisp_Object MS_CDECL CC_bas_make1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v131, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "bas_make1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bas_make1");
#endif
    if (stack >= stacklimit)
    {
        push3(v131,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v131);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v131;
    stack[-3] = v1;
    v132 = v0;
/* end of prologue */
    stack[-4] = v132;
    stack[-1] = stack[-3];
    v132 = stack[-3];
    stack[0] = Llength(nil, v132);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-5];
    v132 = stack[-3];
    fn = elt(env, 1); /* dp_ecart */
    v212 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-5];
    v132 = stack[-2];
    v132 = list2(v212, v132);
    nil = C_nil;
    if (exception_pending()) goto v90;
    {
        Lisp_Object v91 = stack[-4];
        Lisp_Object v168 = stack[-1];
        Lisp_Object v169 = stack[0];
        popv(6);
        return list3star(v91, v168, v169, v132);
    }
/* error exit handlers */
v90:
    popv(6);
    return nil;
}



/* Code for gperm2 */

static Lisp_Object MS_CDECL CC_gperm2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v131, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v88, v89, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "gperm2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm2");
#endif
    if (stack >= stacklimit)
    {
        push3(v131,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v131);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v131;
    stack[-1] = v1;
    v185 = v0;
/* end of prologue */

v2:
    v88 = v185;
    if (v88 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v88 = v185;
    v88 = qcdr(v88);
    stack[-2] = v88;
    v88 = qcar(v185);
    v185 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* rev */
    v101 = (*qfn2(fn))(qenv(fn), v88, v185);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    v89 = stack[-1];
    v88 = qvalue(elt(env, 1)); /* nil */
    v185 = stack[0];
    fn = elt(env, 3); /* gperm1 */
    v185 = (*qfnn(fn))(qenv(fn), 4, v101, v89, v88, v185);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    stack[0] = v185;
    v185 = stack[-2];
    goto v2;
/* error exit handlers */
v139:
    popv(4);
    return nil;
}



/* Code for removeg */

static Lisp_Object CC_removeg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v260, v261, v227, v262;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for removeg");
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
    v260 = stack[-1];
    v261 = qcdr(v260);
    v260 = stack[0];
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v260 = qcar(v260);
    fn = elt(env, 7); /* finde */
    v260 = (*qfn2(fn))(qenv(fn), v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    stack[-2] = v260;
    v260 = stack[-2];
    v261 = qcar(v260);
    v260 = stack[0];
    if (!(v261 == v260)) goto v232;
    v260 = stack[-2];
    v261 = qcdr(v260);
    v260 = stack[0];
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v260 = qcar(v260);
    fn = elt(env, 7); /* finde */
    v260 = (*qfn2(fn))(qenv(fn), v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    stack[-2] = v260;
    goto v232;

v232:
    v260 = stack[-2];
    if (!(v260 == nil)) goto v209;
    v262 = elt(env, 1); /* "Free edge" */
    v260 = stack[0];
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v227 = qcar(v260);
    v261 = elt(env, 2); /* "in vertex" */
    v260 = stack[0];
    v260 = list4(v262, v227, v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    fn = elt(env, 8); /* cerror */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    goto v209;

v209:
    v260 = stack[-2];
    v260 = qcar(v260);
    stack[-2] = v260;
    v260 = stack[-2];
    v260 = qcdr(v260);
    v261 = qcar(v260);
    v260 = stack[-2];
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v260 = qcar(v260);
    if (v261 == v260) goto v74;
    v260 = stack[-2];
    v260 = qcdr(v260);
    v261 = qcar(v260);
    v260 = stack[-2];
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v260 = qcar(v260);
    if (v261 == v260) goto v74;
    v260 = stack[-2];
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v261 = qcar(v260);
    v260 = stack[-2];
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v260 = qcar(v260);
    if (v261 == v260) goto v74;
    v260 = stack[-2];
    v261 = qcar(v260);
    v260 = elt(env, 4); /* qg */
    if (v261 == v260) goto v234;
    v260 = stack[-2];
    v261 = qcar(v260);
    v260 = elt(env, 5); /* g3 */
    if (v261 == v260) goto v240;
    v261 = elt(env, 6); /* "Invalid type of vertex" */
    v260 = stack[0];
    v260 = list2(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    fn = elt(env, 8); /* cerror */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v247;
    v260 = nil;
    { popv(4); return onevalue(v260); }

v240:
    v227 = stack[-1];
    v261 = stack[0];
    v260 = stack[-2];
    {
        popv(4);
        fn = elt(env, 9); /* removeg2 */
        return (*qfnn(fn))(qenv(fn), 3, v227, v261, v260);
    }

v234:
    v227 = stack[-1];
    v261 = stack[0];
    v260 = stack[-2];
    {
        popv(4);
        fn = elt(env, 10); /* removeg1 */
        return (*qfnn(fn))(qenv(fn), 3, v227, v261, v260);
    }

v74:
    v261 = qvalue(elt(env, 3)); /* nil */
    v260 = (Lisp_Object)17; /* 1 */
    v260 = cons(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    v260 = ncons(v260);
    nil = C_nil;
    if (exception_pending()) goto v247;
    popv(4);
    return ncons(v260);
/* error exit handlers */
v247:
    popv(4);
    return nil;
}



/* Code for mk!+mat!+mult!+mat */

static Lisp_Object CC_mkLmatLmultLmat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v307, v308, v309;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+mat+mult+mat");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-13] = v1;
    stack[-14] = v0;
/* end of prologue */
    v307 = stack[-14];
    fn = elt(env, 7); /* matrix!+p */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    if (!(v307 == nil)) goto v141;
    v307 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v307 == nil)) goto v128;
    v307 = elt(env, 2); /* "no matrix in mult" */
    fn = elt(env, 8); /* lprie */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    goto v128;

v128:
    v307 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    goto v141;

v141:
    v307 = stack[-13];
    fn = elt(env, 7); /* matrix!+p */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    if (!(v307 == nil)) goto v125;
    v307 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v307 == nil)) goto v208;
    v307 = elt(env, 2); /* "no matrix in mult" */
    fn = elt(env, 8); /* lprie */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    goto v208;

v208:
    v307 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    goto v125;

v125:
    v307 = stack[-14];
    fn = elt(env, 9); /* get!+col!+nr */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[-15] = v307;
    v307 = stack[-14];
    fn = elt(env, 10); /* get!+row!+nr */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[-12] = v307;
    v307 = stack[-13];
    fn = elt(env, 9); /* get!+col!+nr */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[-11] = v307;
    stack[0] = stack[-15];
    v307 = stack[-13];
    fn = elt(env, 10); /* get!+row!+nr */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    if (equal(stack[0], v307)) goto v119;
    v307 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v307 == nil)) goto v217;
    v307 = elt(env, 3); /* "matrices can not be multiplied" */
    fn = elt(env, 8); /* lprie */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    goto v217;

v217:
    v307 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    goto v119;

v119:
    v307 = (Lisp_Object)17; /* 1 */
    stack[-10] = v307;
    v308 = stack[-12];
    v307 = stack[-10];
    v307 = difference2(v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v307 = Lminusp(nil, v307);
    env = stack[-16];
    if (v307 == nil) goto v229;
    v307 = qvalue(elt(env, 4)); /* nil */
    { popv(17); return onevalue(v307); }

v229:
    v307 = (Lisp_Object)17; /* 1 */
    stack[-5] = v307;
    v308 = stack[-11];
    v307 = stack[-5];
    v307 = difference2(v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v307 = Lminusp(nil, v307);
    env = stack[-16];
    if (v307 == nil) goto v158;
    v307 = qvalue(elt(env, 4)); /* nil */
    goto v160;

v160:
    v307 = ncons(v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[-8] = v307;
    stack[-9] = v307;
    goto v83;

v83:
    v307 = stack[-10];
    v307 = add1(v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[-10] = v307;
    v308 = stack[-12];
    v307 = stack[-10];
    v307 = difference2(v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v307 = Lminusp(nil, v307);
    env = stack[-16];
    if (!(v307 == nil)) { Lisp_Object res = stack[-9]; popv(17); return onevalue(res); }
    stack[-7] = stack[-8];
    v307 = (Lisp_Object)17; /* 1 */
    stack[-6] = v307;
    v308 = stack[-11];
    v307 = stack[-6];
    v307 = difference2(v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v307 = Lminusp(nil, v307);
    env = stack[-16];
    if (v307 == nil) goto v311;
    v307 = qvalue(elt(env, 4)); /* nil */
    goto v39;

v39:
    v307 = ncons(v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v307 = Lrplacd(nil, stack[-7], v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v307 = stack[-8];
    v307 = qcdr(v307);
    stack[-8] = v307;
    goto v83;

v311:
    v308 = qvalue(elt(env, 4)); /* nil */
    v307 = (Lisp_Object)17; /* 1 */
    v307 = cons(v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[0] = v307;
    v307 = (Lisp_Object)17; /* 1 */
    stack[-1] = v307;
    goto v31;

v31:
    v308 = stack[-15];
    v307 = stack[-1];
    v307 = difference2(v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v307 = Lminusp(nil, v307);
    env = stack[-16];
    if (v307 == nil) goto v312;
    v307 = qvalue(elt(env, 5)); /* t */
    stack[-1] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v307; /* !*sub2 */
    v307 = stack[0];
    fn = elt(env, 11); /* subs2 */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v313;
    env = stack[-16];
    stack[0] = v307;
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    v307 = stack[0];
    v307 = ncons(v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[-4] = v307;
    stack[-5] = v307;
    goto v37;

v37:
    v307 = stack[-6];
    v307 = add1(v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[-6] = v307;
    v308 = stack[-11];
    v307 = stack[-6];
    v307 = difference2(v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v307 = Lminusp(nil, v307);
    env = stack[-16];
    if (v307 == nil) goto v17;
    v307 = stack[-5];
    goto v39;

v17:
    stack[-3] = stack[-4];
    v308 = qvalue(elt(env, 4)); /* nil */
    v307 = (Lisp_Object)17; /* 1 */
    v307 = cons(v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[0] = v307;
    v307 = (Lisp_Object)17; /* 1 */
    stack[-2] = v307;
    goto v314;

v314:
    v308 = stack[-15];
    v307 = stack[-2];
    v307 = difference2(v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v307 = Lminusp(nil, v307);
    env = stack[-16];
    if (v307 == nil) goto v315;
    v307 = qvalue(elt(env, 5)); /* t */
    stack[-1] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v307; /* !*sub2 */
    v307 = stack[0];
    fn = elt(env, 11); /* subs2 */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v316;
    env = stack[-16];
    stack[0] = v307;
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    v307 = stack[0];
    v307 = ncons(v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v307 = Lrplacd(nil, stack[-3], v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v307 = stack[-4];
    v307 = qcdr(v307);
    stack[-4] = v307;
    goto v37;

v315:
    stack[-1] = stack[0];
    v309 = stack[-14];
    v308 = stack[-10];
    v307 = stack[-2];
    fn = elt(env, 12); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v309, v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v309 = stack[-13];
    v308 = stack[-2];
    v307 = stack[-6];
    fn = elt(env, 12); /* get!+mat!+entry */
    v307 = (*qfnn(fn))(qenv(fn), 3, v309, v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    fn = elt(env, 13); /* multsq */
    v307 = (*qfn2(fn))(qenv(fn), stack[0], v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    fn = elt(env, 14); /* addsq */
    v307 = (*qfn2(fn))(qenv(fn), stack[-1], v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[0] = v307;
    v307 = stack[-2];
    v307 = add1(v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[-2] = v307;
    goto v314;

v312:
    stack[-2] = stack[0];
    v309 = stack[-14];
    v308 = stack[-10];
    v307 = stack[-1];
    fn = elt(env, 12); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v309, v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v309 = stack[-13];
    v308 = stack[-1];
    v307 = stack[-6];
    fn = elt(env, 12); /* get!+mat!+entry */
    v307 = (*qfnn(fn))(qenv(fn), 3, v309, v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    fn = elt(env, 13); /* multsq */
    v307 = (*qfn2(fn))(qenv(fn), stack[0], v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    fn = elt(env, 14); /* addsq */
    v307 = (*qfn2(fn))(qenv(fn), stack[-2], v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[0] = v307;
    v307 = stack[-1];
    v307 = add1(v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[-1] = v307;
    goto v31;

v158:
    v308 = qvalue(elt(env, 4)); /* nil */
    v307 = (Lisp_Object)17; /* 1 */
    v307 = cons(v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[0] = v307;
    v307 = (Lisp_Object)17; /* 1 */
    stack[-1] = v307;
    goto v153;

v153:
    v308 = stack[-15];
    v307 = stack[-1];
    v307 = difference2(v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v307 = Lminusp(nil, v307);
    env = stack[-16];
    if (v307 == nil) goto v242;
    v307 = qvalue(elt(env, 5)); /* t */
    stack[-1] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v307; /* !*sub2 */
    v307 = stack[0];
    fn = elt(env, 11); /* subs2 */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-16];
    stack[0] = v307;
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    v307 = stack[0];
    v307 = ncons(v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[-3] = v307;
    stack[-4] = v307;
    goto v161;

v161:
    v307 = stack[-5];
    v307 = add1(v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[-5] = v307;
    v308 = stack[-11];
    v307 = stack[-5];
    v307 = difference2(v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v307 = Lminusp(nil, v307);
    env = stack[-16];
    if (v307 == nil) goto v318;
    v307 = stack[-4];
    goto v160;

v318:
    stack[-2] = stack[-3];
    v308 = qvalue(elt(env, 4)); /* nil */
    v307 = (Lisp_Object)17; /* 1 */
    v307 = cons(v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[0] = v307;
    v307 = (Lisp_Object)17; /* 1 */
    stack[-1] = v307;
    goto v54;

v54:
    v308 = stack[-15];
    v307 = stack[-1];
    v307 = difference2(v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v307 = Lminusp(nil, v307);
    env = stack[-16];
    if (v307 == nil) goto v319;
    v307 = qvalue(elt(env, 5)); /* t */
    stack[-1] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v307; /* !*sub2 */
    v307 = stack[0];
    fn = elt(env, 11); /* subs2 */
    v307 = (*qfn1(fn))(qenv(fn), v307);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-16];
    stack[0] = v307;
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    v307 = stack[0];
    v307 = ncons(v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v307 = Lrplacd(nil, stack[-2], v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v307 = stack[-3];
    v307 = qcdr(v307);
    stack[-3] = v307;
    goto v161;

v319:
    stack[-6] = stack[0];
    v309 = stack[-14];
    v308 = stack[-10];
    v307 = stack[-1];
    fn = elt(env, 12); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v309, v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v309 = stack[-13];
    v308 = stack[-1];
    v307 = stack[-5];
    fn = elt(env, 12); /* get!+mat!+entry */
    v307 = (*qfnn(fn))(qenv(fn), 3, v309, v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    fn = elt(env, 13); /* multsq */
    v307 = (*qfn2(fn))(qenv(fn), stack[0], v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    fn = elt(env, 14); /* addsq */
    v307 = (*qfn2(fn))(qenv(fn), stack[-6], v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[0] = v307;
    v307 = stack[-1];
    v307 = add1(v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[-1] = v307;
    goto v54;

v242:
    stack[-2] = stack[0];
    v309 = stack[-14];
    v308 = stack[-10];
    v307 = stack[-1];
    fn = elt(env, 12); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v309, v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    v309 = stack[-13];
    v308 = stack[-1];
    v307 = stack[-5];
    fn = elt(env, 12); /* get!+mat!+entry */
    v307 = (*qfnn(fn))(qenv(fn), 3, v309, v308, v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    fn = elt(env, 13); /* multsq */
    v307 = (*qfn2(fn))(qenv(fn), stack[0], v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    fn = elt(env, 14); /* addsq */
    v307 = (*qfn2(fn))(qenv(fn), stack[-2], v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[0] = v307;
    v307 = stack[-1];
    v307 = add1(v307);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-16];
    stack[-1] = v307;
    goto v153;
/* error exit handlers */
v320:
    env = stack[-16];
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    popv(17);
    return nil;
v317:
    env = stack[-16];
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    popv(17);
    return nil;
v316:
    env = stack[-16];
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    popv(17);
    return nil;
v313:
    env = stack[-16];
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    popv(17);
    return nil;
v310:
    popv(17);
    return nil;
}



/* Code for ibalp_litlp */

static Lisp_Object CC_ibalp_litlp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v232;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_litlp");
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

v241:
    v232 = stack[0];
    v232 = (v232 == nil ? lisp_true : nil);
    if (!(v232 == nil)) { popv(2); return onevalue(v232); }
    v232 = stack[0];
    v232 = qcar(v232);
    fn = elt(env, 2); /* ibalp_litp */
    v232 = (*qfn1(fn))(qenv(fn), v232);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-1];
    if (v232 == nil) goto v133;
    v232 = stack[0];
    v232 = qcdr(v232);
    stack[0] = v232;
    goto v241;

v133:
    v232 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v232); }
/* error exit handlers */
v128:
    popv(2);
    return nil;
}



/* Code for ratpoly_ratp */

static Lisp_Object CC_ratpoly_ratp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v126;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_ratp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v97 = v0;
/* end of prologue */
    v126 = v97;
    v126 = qcar(v126);
    v126 = (is_number(v126) ? lisp_true : nil);
    if (!(v126 == nil)) return onevalue(v126);
    v97 = qcar(v97);
    v97 = (v97 == nil ? lisp_true : nil);
    return onevalue(v97);
}



/* Code for spmultm2 */

static Lisp_Object MS_CDECL CC_spmultm2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v131, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v327, v328, v329;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "spmultm2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spmultm2");
#endif
    if (stack >= stacklimit)
    {
        push3(v131,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v131);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v114 = v131;
    stack[-10] = v1;
    stack[-11] = v0;
/* end of prologue */
    v327 = v114;
    v327 = qcdr(v327);
    v327 = qcar(v327);
    fn = elt(env, 2); /* mkempspmat */
    v114 = (*qfn2(fn))(qenv(fn), v327, v114);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-12] = v114;
    v114 = stack[-11];
    v114 = qcdr(v114);
    v327 = qcar(v114);
    v114 = stack[-11];
    v114 = qcdr(v114);
    v114 = qcdr(v114);
    v114 = qcar(v114);
    v114 = qcdr(v114);
    v114 = qcar(v114);
    fn = elt(env, 3); /* empty */
    v114 = (*qfn2(fn))(qenv(fn), v327, v114);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    if (v114 == nil) { Lisp_Object res = stack[-12]; popv(14); return onevalue(res); }
    v114 = stack[-10];
    v114 = qcdr(v114);
    v327 = qcar(v114);
    v114 = stack[-10];
    v114 = qcdr(v114);
    v114 = qcdr(v114);
    v114 = qcar(v114);
    v114 = qcdr(v114);
    v114 = qcar(v114);
    fn = elt(env, 3); /* empty */
    v114 = (*qfn2(fn))(qenv(fn), v327, v114);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    if (v114 == nil) { Lisp_Object res = stack[-12]; popv(14); return onevalue(res); }
    v114 = stack[-11];
    v114 = qcdr(v114);
    v114 = qcar(v114);
    stack[-9] = v114;
    v114 = stack[-10];
    v114 = qcdr(v114);
    v114 = qcar(v114);
    stack[-8] = v114;
    v114 = (Lisp_Object)17; /* 1 */
    stack[-3] = v114;
    goto v210;

v210:
    v114 = stack[-11];
    v114 = qcdr(v114);
    v114 = qcdr(v114);
    v114 = qcar(v114);
    v114 = qcdr(v114);
    v327 = qcar(v114);
    v114 = stack[-3];
    v114 = difference2(v327, v114);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v114 = Lminusp(nil, v114);
    env = stack[-13];
    if (!(v114 == nil)) { Lisp_Object res = stack[-12]; popv(14); return onevalue(res); }
    v327 = stack[-9];
    v114 = stack[-3];
    fn = elt(env, 4); /* findrow */
    v114 = (*qfn2(fn))(qenv(fn), v327, v114);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-7] = v114;
    v114 = stack[-7];
    if (v114 == nil) goto v214;
    v114 = (Lisp_Object)17; /* 1 */
    stack[-2] = v114;
    goto v74;

v74:
    v114 = stack[-10];
    v114 = qcdr(v114);
    v114 = qcdr(v114);
    v114 = qcar(v114);
    v114 = qcdr(v114);
    v327 = qcar(v114);
    v114 = stack[-2];
    v114 = difference2(v327, v114);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v114 = Lminusp(nil, v114);
    env = stack[-13];
    if (!(v114 == nil)) goto v214;
    v327 = stack[-8];
    v114 = stack[-2];
    fn = elt(env, 4); /* findrow */
    v114 = (*qfn2(fn))(qenv(fn), v327, v114);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-6] = v114;
    v114 = stack[-6];
    if (v114 == nil) goto v306;
    v114 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 5); /* simp */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-4] = v114;
    v114 = stack[-7];
    v114 = qcdr(v114);
    stack[-1] = v114;
    goto v151;

v151:
    v114 = stack[-1];
    if (v114 == nil) goto v330;
    v114 = stack[-1];
    v114 = qcar(v114);
    v327 = v114;
    v114 = v327;
    v114 = qcar(v114);
    v327 = qcdr(v327);
    v328 = v327;
    v327 = v114;
    v114 = stack[-6];
    v114 = Latsoc(nil, v327, v114);
    stack[-5] = v114;
    v114 = stack[-5];
    if (v114 == nil) goto v305;
    v114 = stack[-5];
    v114 = qcdr(v114);
    stack[-5] = v114;
    v114 = v328;
    fn = elt(env, 5); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v114 = stack[-5];
    fn = elt(env, 5); /* simp */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    fn = elt(env, 6); /* multsq */
    v114 = (*qfn2(fn))(qenv(fn), stack[0], v114);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[0] = v114;
    v327 = stack[-4];
    v114 = stack[0];
    fn = elt(env, 7); /* addsq */
    v114 = (*qfn2(fn))(qenv(fn), v327, v114);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-4] = v114;
    goto v248;

v248:
    v114 = stack[-1];
    v114 = qcdr(v114);
    stack[-1] = v114;
    goto v151;

v305:
    v114 = stack[-4];
    stack[-4] = v114;
    goto v248;

v330:
    v114 = stack[-4];
    fn = elt(env, 8); /* mk!*sq */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[0] = v114;
    v327 = stack[0];
    v114 = (Lisp_Object)1; /* 0 */
    if (v327 == v114) goto v306;
    v328 = stack[-12];
    v327 = stack[-3];
    v114 = stack[-2];
    v329 = list3(v328, v327, v114);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v328 = stack[0];
    v327 = stack[-12];
    v114 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 9); /* letmtr3 */
    v114 = (*qfnn(fn))(qenv(fn), 4, v329, v328, v327, v114);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    goto v306;

v306:
    v114 = stack[-2];
    v114 = add1(v114);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-2] = v114;
    goto v74;

v214:
    v114 = stack[-3];
    v114 = add1(v114);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-3] = v114;
    goto v210;
/* error exit handlers */
v300:
    popv(14);
    return nil;
}



/* Code for testredh */

static Lisp_Object CC_testredh(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v230, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testredh");
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
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v217 = qvalue(elt(env, 2)); /* maxvar */
    v230 = stack[0];
    v230 = plus2(v217, v230);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-2];
    v217 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v230/(16/CELL)));
    v230 = (Lisp_Object)1; /* 0 */
    v230 = *(Lisp_Object *)((char *)v217 + (CELL-TAG_VECTOR) + ((int32_t)v230/(16/CELL)));
    if (v230 == nil) goto v10;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v217 = qvalue(elt(env, 2)); /* maxvar */
    v230 = stack[0];
    v230 = plus2(v217, v230);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-2];
    v217 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v230/(16/CELL)));
    v230 = (Lisp_Object)17; /* 1 */
    v230 = *(Lisp_Object *)((char *)v217 + (CELL-TAG_VECTOR) + ((int32_t)v230/(16/CELL)));
    v230 = qcar(v230);
    v217 = qcar(v230);
    v230 = (Lisp_Object)33; /* 2 */
    v230 = (Lisp_Object)lessp2(v217, v230);
    nil = C_nil;
    if (exception_pending()) goto v166;
    v230 = v230 ? lisp_true : nil;
    env = stack[-2];
    if (v230 == nil) goto v10;
    v230 = stack[0];
    fn = elt(env, 3); /* rowdel */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-2];
    v230 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* testredzz */
        return (*qfn1(fn))(qenv(fn), v230);
    }

v10:
    v230 = nil;
    { popv(3); return onevalue(v230); }
/* error exit handlers */
v166:
    popv(3);
    return nil;
}



/* Code for bsubs */

static Lisp_Object CC_bsubs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bsubs");
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
    stack[0] = v0;
/* end of prologue */
    v217 = stack[0];
    if (v217 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v217 = stack[0];
    if (!consp(v217)) goto v99;
    v217 = stack[0];
    stack[-3] = v217;
    v217 = stack[-3];
    if (v217 == nil) goto v137;
    v217 = stack[-3];
    v217 = qcar(v217);
    v217 = CC_bsubs(env, v217);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    v217 = ncons(v217);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    stack[-1] = v217;
    stack[-2] = v217;
    goto v124;

v124:
    v217 = stack[-3];
    v217 = qcdr(v217);
    stack[-3] = v217;
    v217 = stack[-3];
    if (v217 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v217 = stack[-3];
    v217 = qcar(v217);
    v217 = CC_bsubs(env, v217);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    v217 = ncons(v217);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    v217 = Lrplacd(nil, stack[0], v217);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    v217 = stack[-1];
    v217 = qcdr(v217);
    stack[-1] = v217;
    goto v124;

v137:
    v217 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v217); }

v99:
    v217 = stack[0];
    fn = elt(env, 2); /* bound */
    v217 = (*qfn1(fn))(qenv(fn), v217);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    if (v217 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v217 = stack[0];
    {
        popv(5);
        fn = elt(env, 3); /* binding */
        return (*qfn1(fn))(qenv(fn), v217);
    }
/* error exit handlers */
v176:
    popv(5);
    return nil;
}



/* Code for vdpgetprop */

static Lisp_Object CC_vdpgetprop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v166, v237, v176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpgetprop");
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
    v237 = v1;
    v176 = v0;
/* end of prologue */
    v86 = v176;
    if (v86 == nil) goto v10;
    v166 = v176;
    v86 = elt(env, 2); /* vdp */
    if (!consp(v166)) goto v232;
    v166 = qcar(v166);
    if (!(v166 == v86)) goto v232;
    v86 = v237;
    v166 = v176;
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    v166 = qcar(v166);
    v86 = Lassoc(nil, v86, v166);
    v166 = v86;
    v86 = v166;
    if (v86 == nil) goto v230;
    v86 = v166;
    v86 = qcdr(v86);
    { popv(1); return onevalue(v86); }

v230:
    v86 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v86); }

v232:
    v86 = elt(env, 3); /* "vdpgetprop given a non-vdp as 1st parameter" 
*/
    v166 = v176;
    v86 = list3(v86, v166, v237);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[0];
    v166 = v86;
    v86 = v166;
    qvalue(elt(env, 4)) = v86; /* errmsg!* */
    v86 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v86 == nil)) goto v91;
    v86 = v166;
    fn = elt(env, 6); /* lprie */
    v86 = (*qfn1(fn))(qenv(fn), v86);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[0];
    goto v91;

v91:
    v86 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v205;
    v86 = nil;
    { popv(1); return onevalue(v86); }

v10:
    v86 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v86); }
/* error exit handlers */
v205:
    popv(1);
    return nil;
}



/* Code for formcond */

static Lisp_Object MS_CDECL CC_formcond(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v131, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v87, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formcond");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formcond");
#endif
    if (stack >= stacklimit)
    {
        push3(v131,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v131);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v129 = v131;
    v87 = v1;
    v122 = v0;
/* end of prologue */
    stack[0] = elt(env, 1); /* cond */
    v122 = qcdr(v122);
    fn = elt(env, 2); /* formcond1 */
    v129 = (*qfnn(fn))(qenv(fn), 3, v122, v87, v129);
    nil = C_nil;
    if (exception_pending()) goto v132;
    {
        Lisp_Object v212 = stack[0];
        popv(1);
        return cons(v212, v129);
    }
/* error exit handlers */
v132:
    popv(1);
    return nil;
}



/* Code for rnquotient!: */

static Lisp_Object CC_rnquotientT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v90;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnquotient:");
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
    v137 = stack[-1];
    v137 = qcdr(v137);
    v90 = qcar(v137);
    v137 = stack[0];
    v137 = qcdr(v137);
    v137 = qcdr(v137);
    stack[-2] = times2(v90, v137);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-3];
    v137 = stack[-1];
    v137 = qcdr(v137);
    v90 = qcdr(v137);
    v137 = stack[0];
    v137 = qcdr(v137);
    v137 = qcar(v137);
    v137 = times2(v90, v137);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-3];
    {
        Lisp_Object v135 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v135, v137);
    }
/* error exit handlers */
v208:
    popv(4);
    return nil;
}



/* Code for dp_ecart */

static Lisp_Object CC_dp_ecart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_ecart");
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
    v100 = stack[0];
    if (v100 == nil) goto v3;
    v100 = stack[0];
    fn = elt(env, 1); /* dp!=ecart */
    stack[-1] = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v100 = stack[0];
    fn = elt(env, 2); /* dp_lmon */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    fn = elt(env, 3); /* mo_ecart */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v87;
    {
        Lisp_Object v122 = stack[-1];
        popv(3);
        return difference2(v122, v100);
    }

v3:
    v100 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v100); }
/* error exit handlers */
v87:
    popv(3);
    return nil;
}



/* Code for subs3f1 */

static Lisp_Object MS_CDECL CC_subs3f1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v131, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v70, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subs3f1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs3f1");
#endif
    if (stack >= stacklimit)
    {
        push3(v131,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v131);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v131;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v70 = qvalue(elt(env, 1)); /* nil */
    v69 = (Lisp_Object)17; /* 1 */
    v69 = cons(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-4];
    stack[-3] = v69;
    goto v99;

v99:
    v69 = stack[-2];
    if (v69 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v69 = stack[-2];
    if (!consp(v69)) goto v137;
    v69 = stack[-2];
    v69 = qcar(v69);
    if (!consp(v69)) goto v137;
    v69 = stack[0];
    if (v69 == nil) goto v201;
    v69 = stack[-2];
    v69 = qcar(v69);
    v69 = qcdr(v69);
    if (!consp(v69)) goto v191;
    v69 = stack[-2];
    v69 = qcar(v69);
    v69 = qcdr(v69);
    v69 = qcar(v69);
    if (!(!consp(v69))) goto v201;

v191:
    v69 = stack[-2];
    v69 = qcar(v69);
    v70 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-4];
    v69 = (Lisp_Object)17; /* 1 */
    v69 = cons(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-4];
    v150 = v69;
    goto v186;

v186:
    v69 = stack[-3];
    v70 = v150;
    fn = elt(env, 6); /* addsq */
    v69 = (*qfn2(fn))(qenv(fn), v69, v70);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-4];
    stack[-3] = v69;
    v69 = stack[-2];
    v69 = qcdr(v69);
    stack[-2] = v69;
    goto v99;

v201:
    v69 = stack[-2];
    v70 = qcar(v69);
    v69 = stack[-1];
    fn = elt(env, 7); /* subs3t */
    v69 = (*qfn2(fn))(qenv(fn), v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-4];
    v150 = v69;
    v69 = stack[0];
    if (v69 == nil) goto v186;
    v69 = qvalue(elt(env, 2)); /* mchfg!* */
    if (v69 == nil) goto v186;
    v69 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v69; /* mchfg!* */
    v69 = v150;
    v70 = qcar(v69);
    v69 = stack[-2];
    if (!(equal(v70, v69))) goto v210;
    v69 = v150;
    v70 = qcdr(v69);
    v69 = (Lisp_Object)17; /* 1 */
    if (!(v70 == v69)) goto v210;
    v70 = stack[-2];
    v69 = (Lisp_Object)17; /* 1 */
    v69 = cons(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-4];
    v150 = v69;
    goto v186;

v210:
    v69 = qvalue(elt(env, 3)); /* !*resubs */
    if (v69 == nil) goto v186;
    v69 = qvalue(elt(env, 4)); /* !*sub2 */
    if (!(v69 == nil)) goto v177;
    v69 = qvalue(elt(env, 5)); /* powlis1!* */
    if (!(v69 == nil)) goto v177;

v235:
    v69 = v150;
    fn = elt(env, 8); /* subs3q */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-4];
    v150 = v69;
    goto v186;

v177:
    v69 = v150;
    fn = elt(env, 9); /* subs2q */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-4];
    v150 = v69;
    goto v235;

v137:
    stack[0] = stack[-3];
    v70 = stack[-2];
    v69 = (Lisp_Object)17; /* 1 */
    v69 = cons(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v330;
    env = stack[-4];
    {
        Lisp_Object v151 = stack[0];
        popv(5);
        fn = elt(env, 6); /* addsq */
        return (*qfn2(fn))(qenv(fn), v151, v69);
    }
/* error exit handlers */
v330:
    popv(5);
    return nil;
}



setup_type const u08_setup[] =
{
    {"reval1",                  too_few_2,      CC_reval1,     wrong_no_2},
    {"setdiff",                 too_few_2,      CC_setdiff,    wrong_no_2},
    {"on",                      CC_on,          too_many_1,    wrong_no_1},
    {"xdegreemon",              CC_xdegreemon,  too_many_1,    wrong_no_1},
    {"algid",                   too_few_2,      CC_algid,      wrong_no_2},
    {"greaterp:",               too_few_2,      CC_greaterpT,  wrong_no_2},
    {"ordpa",                   too_few_2,      CC_ordpa,      wrong_no_2},
    {"getphystype",             CC_getphystype, too_many_1,    wrong_no_1},
    {"mkid",                    too_few_2,      CC_mkid,       wrong_no_2},
    {"ckpreci#",                CC_ckpreciC,    too_many_1,    wrong_no_1},
    {"rnplus:",                 too_few_2,      CC_rnplusT,    wrong_no_2},
    {"mo=deglist",              CC_moMdeglist,  too_many_1,    wrong_no_1},
    {"psum",                    too_few_2,      CC_psum,       wrong_no_2},
    {"vecp",                    CC_vecp,        too_many_1,    wrong_no_1},
    {"pappl_pv",                too_few_2,      CC_pappl_pv,   wrong_no_2},
    {"general-modular-reciprocal",CC_generalKmodularKreciprocal,too_many_1,wrong_no_1},
    {"lto_catsoc",              too_few_2,      CC_lto_catsoc, wrong_no_2},
    {"comfac",                  CC_comfac,      too_many_1,    wrong_no_1},
    {"kernp",                   CC_kernp,       too_many_1,    wrong_no_1},
    {"symbol",                  CC_symbol,      too_many_1,    wrong_no_1},
    {"rl_susitf",               too_few_2,      CC_rl_susitf,  wrong_no_2},
    {"ibalp_istotal",           CC_ibalp_istotal,too_many_1,   wrong_no_1},
    {"objectom",                CC_objectom,    too_many_1,    wrong_no_1},
    {"c:extmult",               too_few_2,      CC_cTextmult,  wrong_no_2},
    {"unbind",                  CC_unbind,      too_many_1,    wrong_no_1},
    {"off",                     CC_off,         too_many_1,    wrong_no_1},
    {"deg*form",                CC_degHform,    too_many_1,    wrong_no_1},
    {"formprogn",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_formprogn},
    {"red-ratios2",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_redKratios2},
    {"divd",                    too_few_2,      CC_divd,       wrong_no_2},
    {"bas_make1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_bas_make1},
    {"gperm2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm2},
    {"removeg",                 too_few_2,      CC_removeg,    wrong_no_2},
    {"mk+mat+mult+mat",         too_few_2,      CC_mkLmatLmultLmat,wrong_no_2},
    {"ibalp_litlp",             CC_ibalp_litlp, too_many_1,    wrong_no_1},
    {"ratpoly_ratp",            CC_ratpoly_ratp,too_many_1,    wrong_no_1},
    {"spmultm2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_spmultm2},
    {"testredh",                CC_testredh,    too_many_1,    wrong_no_1},
    {"bsubs",                   CC_bsubs,       too_many_1,    wrong_no_1},
    {"vdpgetprop",              too_few_2,      CC_vdpgetprop, wrong_no_2},
    {"formcond",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formcond},
    {"rnquotient:",             too_few_2,      CC_rnquotientT,wrong_no_2},
    {"dp_ecart",                CC_dp_ecart,    too_many_1,    wrong_no_1},
    {"subs3f1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_subs3f1},
    {NULL, (one_args *)"u08", (two_args *)"633 2738367 463490", 0}
};

/* end of generated code */
