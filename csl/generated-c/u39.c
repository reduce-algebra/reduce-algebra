
/* $destdir\u39.c        Machine generated C code */

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


/* Code for rdzchk */

static Lisp_Object MS_CDECL CC_rdzchk(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "rdzchk");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rdzchk");
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
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-3] = v0;
/* end of prologue */
    v49 = stack[-3];
    if (!consp(v49)) goto v51;
    v49 = stack[-3];
    v49 = qcdr(v49);
    v50 = qcar(v49);
    v49 = (Lisp_Object)1; /* 0 */
    if (v50 == v49) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v49 = stack[-1];
    v49 = qcdr(v49);
    v50 = qcar(v49);
    v49 = (Lisp_Object)1; /* 0 */
    v49 = (Lisp_Object)greaterp2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v49 = v49 ? lisp_true : nil;
    env = stack[-5];
    if (v49 == nil) goto v53;
    v49 = stack[0];
    v49 = qcdr(v49);
    v50 = qcar(v49);
    v49 = (Lisp_Object)1; /* 0 */
    v49 = (Lisp_Object)greaterp2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v49 = v49 ? lisp_true : nil;
    env = stack[-5];
    if (!(v49 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v53:
    v49 = stack[-1];
    v49 = qcdr(v49);
    v50 = qcar(v49);
    v49 = (Lisp_Object)1; /* 0 */
    v49 = (Lisp_Object)lessp2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v49 = v49 ? lisp_true : nil;
    env = stack[-5];
    if (v49 == nil) goto v54;
    v49 = stack[0];
    v49 = qcdr(v49);
    v50 = qcar(v49);
    v49 = (Lisp_Object)1; /* 0 */
    v49 = (Lisp_Object)lessp2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v49 = v49 ? lisp_true : nil;
    env = stack[-5];
    if (!(v49 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v54:
    v49 = stack[-1];
    v49 = qcdr(v49);
    v50 = qcar(v49);
    v49 = (Lisp_Object)1; /* 0 */
    v49 = (Lisp_Object)greaterp2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v49 = v49 ? lisp_true : nil;
    env = stack[-5];
    if (v49 == nil) goto v55;
    v49 = stack[-1];
    v50 = v49;
    goto v56;

v56:
    v49 = qvalue(elt(env, 4)); /* rd!-tolerance!* */
    stack[-4] = v50;
    stack[-2] = v49;
    stack[-1] = elt(env, 3); /* !:rd!: */
    v49 = stack[-4];
    v49 = qcdr(v49);
    v50 = qcar(v49);
    v49 = stack[-2];
    v49 = qcdr(v49);
    v49 = qcar(v49);
    stack[0] = times2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-5];
    v49 = stack[-4];
    v49 = qcdr(v49);
    v50 = qcdr(v49);
    v49 = stack[-2];
    v49 = qcdr(v49);
    v49 = qcdr(v49);
    v49 = plus2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-5];
    stack[-1] = list2star(stack[-1], stack[0], v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-5];
    v49 = stack[-3];
    v49 = qcdr(v49);
    v50 = qcar(v49);
    v49 = (Lisp_Object)1; /* 0 */
    v49 = (Lisp_Object)greaterp2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v49 = v49 ? lisp_true : nil;
    env = stack[-5];
    if (v49 == nil) goto v57;
    v49 = stack[-3];
    goto v58;

v58:
    fn = elt(env, 6); /* greaterp!: */
    v49 = (*qfn2(fn))(qenv(fn), stack[-1], v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-5];
    if (v49 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v49 = qvalue(elt(env, 5)); /* bfz!* */
    { popv(6); return onevalue(v49); }

v57:
    stack[0] = elt(env, 3); /* !:rd!: */
    v49 = stack[-3];
    v49 = qcdr(v49);
    v49 = qcar(v49);
    v50 = negate(v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-5];
    v49 = stack[-3];
    v49 = qcdr(v49);
    v49 = qcdr(v49);
    v49 = list2star(stack[0], v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-5];
    goto v58;

v55:
    stack[0] = elt(env, 3); /* !:rd!: */
    v49 = stack[-1];
    v49 = qcdr(v49);
    v49 = qcar(v49);
    v50 = negate(v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-5];
    v49 = stack[-1];
    v49 = qcdr(v49);
    v49 = qcdr(v49);
    v49 = list2star(stack[0], v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-5];
    v50 = v49;
    goto v56;

v51:
    v50 = stack[-3];
    v49 = elt(env, 1); /* 0.0 */
    if (equal(v50, v49)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v50 = stack[-1];
    v49 = elt(env, 1); /* 0.0 */
    v49 = (Lisp_Object)greaterp2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v49 = v49 ? lisp_true : nil;
    env = stack[-5];
    if (v49 == nil) goto v59;
    v50 = stack[0];
    v49 = elt(env, 1); /* 0.0 */
    v49 = (Lisp_Object)greaterp2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v49 = v49 ? lisp_true : nil;
    env = stack[-5];
    if (!(v49 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v59:
    v50 = stack[-1];
    v49 = elt(env, 1); /* 0.0 */
    v49 = (Lisp_Object)lessp2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v49 = v49 ? lisp_true : nil;
    env = stack[-5];
    if (v49 == nil) goto v60;
    v50 = stack[0];
    v49 = elt(env, 1); /* 0.0 */
    v49 = (Lisp_Object)lessp2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v49 = v49 ? lisp_true : nil;
    env = stack[-5];
    if (!(v49 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v60:
    v49 = stack[-3];
    stack[0] = Labsval(nil, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-5];
    v49 = stack[-1];
    v50 = Labsval(nil, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-5];
    v49 = qvalue(elt(env, 2)); /* !!fleps1 */
    v49 = times2(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-5];
    v49 = (Lisp_Object)lessp2(stack[0], v49);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v49 = v49 ? lisp_true : nil;
    env = stack[-5];
    if (v49 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v49 = elt(env, 1); /* 0.0 */
    { popv(6); return onevalue(v49); }
/* error exit handlers */
v52:
    popv(6);
    return nil;
}



/* Code for mo!=modiv1 */

static Lisp_Object CC_moMmodiv1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v62;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=modiv1");
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

v63:
    v44 = stack[-1];
    if (v44 == nil) goto v64;
    v44 = stack[0];
    if (v44 == nil) goto v65;
    v44 = stack[-1];
    v62 = qcar(v44);
    v44 = stack[0];
    v44 = qcar(v44);
    v44 = (Lisp_Object)lesseq2(v62, v44);
    nil = C_nil;
    if (exception_pending()) goto v59;
    v44 = v44 ? lisp_true : nil;
    env = stack[-2];
    if (v44 == nil) goto v66;
    v44 = stack[-1];
    v44 = qcdr(v44);
    stack[-1] = v44;
    v44 = stack[0];
    v44 = qcdr(v44);
    stack[0] = v44;
    goto v63;

v66:
    v44 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v44); }

v65:
    v44 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v44); }

v64:
    v44 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v44); }
/* error exit handlers */
v59:
    popv(3);
    return nil;
}



/* Code for depend!-p */

static Lisp_Object CC_dependKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v60, v72, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for depend-p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v72 = v1;
    v73 = v0;
/* end of prologue */
    v60 = v73;
    v71 = v72;
    if (v60 == v71) goto v63;
    v71 = v73;
    if (!consp(v71)) goto v74;
    v71 = v73;
    v71 = qcar(v71);
    if (!consp(v71)) goto v75;
    v71 = v73;
    v60 = v72;
    {
        fn = elt(env, 4); /* depend!-f */
        return (*qfn2(fn))(qenv(fn), v71, v60);
    }

v75:
    v71 = v73;
    v60 = qcar(v71);
    v71 = elt(env, 3); /* !*sq */
    if (v60 == v71) goto v76;
    v71 = v73;
    v71 = qcdr(v71);
    v60 = v72;
    {
        fn = elt(env, 5); /* depend!-l */
        return (*qfn2(fn))(qenv(fn), v71, v60);
    }

v76:
    v71 = v73;
    v71 = qcdr(v71);
    v71 = qcar(v71);
    v60 = v72;
    {
        fn = elt(env, 6); /* depend!-sq */
        return (*qfn2(fn))(qenv(fn), v71, v60);
    }

v74:
    v71 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v71);

v63:
    v71 = qvalue(elt(env, 1)); /* t */
    return onevalue(v71);
}



/* Code for numir */

static Lisp_Object MS_CDECL CC_numir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v111, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "numir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numir");
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
    push2(nil, nil);
/* end of prologue */
    v111 = qvalue(elt(env, 1)); /* atts */
    v110 = elt(env, 2); /* name */
    fn = elt(env, 12); /* find */
    v110 = (*qfn2(fn))(qenv(fn), v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    v110 = Lintern(nil, v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    stack[-1] = v110;
    fn = elt(env, 13); /* lex */
    v110 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    fn = elt(env, 14); /* omobj */
    v110 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    stack[0] = v110;
    fn = elt(env, 13); /* lex */
    v110 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    fn = elt(env, 14); /* omobj */
    v110 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    v13 = stack[-1];
    v111 = elt(env, 3); /* complex_cartesian */
    if (!(v13 == v111)) goto v113;
    v111 = stack[0];
    if (symbolp(v111)) goto v62;
    v111 = v110;
    if (!(symbolp(v111))) goto v113;

v62:
    stack[-4] = elt(env, 4); /* plus */
    stack[-3] = qvalue(elt(env, 5)); /* nil */
    stack[-2] = stack[0];
    stack[-1] = elt(env, 6); /* times */
    stack[0] = qvalue(elt(env, 5)); /* nil */
    v13 = v110;
    v111 = elt(env, 7); /* !&imaginaryi!; */
    v110 = qvalue(elt(env, 5)); /* nil */
    v110 = list2star(v13, v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    v111 = list2star(stack[-1], stack[0], v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    v110 = qvalue(elt(env, 5)); /* nil */
    v110 = list2star(stack[-2], v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    {
        Lisp_Object v114 = stack[-4];
        Lisp_Object v115 = stack[-3];
        popv(8);
        return list2star(v114, v115, v110);
    }

v113:
    v13 = stack[-1];
    v111 = elt(env, 8); /* complex_polar */
    if (!(v13 == v111)) goto v54;
    v111 = stack[0];
    if (symbolp(v111)) goto v116;
    v111 = v110;
    if (!(symbolp(v111))) goto v54;

v116:
    stack[-6] = elt(env, 6); /* times */
    stack[-5] = qvalue(elt(env, 5)); /* nil */
    stack[-4] = stack[0];
    stack[-3] = elt(env, 9); /* exp */
    stack[-2] = qvalue(elt(env, 5)); /* nil */
    stack[-1] = elt(env, 6); /* times */
    stack[0] = qvalue(elt(env, 5)); /* nil */
    v13 = v110;
    v111 = elt(env, 7); /* !&imaginaryi!; */
    v110 = qvalue(elt(env, 5)); /* nil */
    v110 = list2star(v13, v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    v110 = list2star(stack[-1], stack[0], v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    v110 = ncons(v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    v111 = list2star(stack[-3], stack[-2], v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-7];
    v110 = qvalue(elt(env, 5)); /* nil */
    v110 = list2star(stack[-4], v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    {
        Lisp_Object v117 = stack[-6];
        Lisp_Object v118 = stack[-5];
        popv(8);
        return list2star(v117, v118, v110);
    }

v54:
    v13 = stack[-1];
    v111 = elt(env, 10); /* rational */
    if (!(v13 == v111)) goto v119;
    v111 = stack[0];
    if (symbolp(v111)) goto v120;
    v111 = v110;
    if (!(symbolp(v111))) goto v119;

v120:
    stack[-2] = elt(env, 11); /* divide */
    stack[-1] = qvalue(elt(env, 5)); /* nil */
    v13 = stack[0];
    v111 = v110;
    v110 = qvalue(elt(env, 5)); /* nil */
    v110 = list2star(v13, v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    {
        Lisp_Object v121 = stack[-2];
        Lisp_Object v122 = stack[-1];
        popv(8);
        return list2star(v121, v122, v110);
    }

v119:
    stack[-2] = stack[-1];
    stack[-1] = qvalue(elt(env, 5)); /* nil */
    v13 = stack[0];
    v111 = v110;
    v110 = qvalue(elt(env, 5)); /* nil */
    v110 = list2star(v13, v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v112;
    {
        Lisp_Object v123 = stack[-2];
        Lisp_Object v8 = stack[-1];
        popv(8);
        return list2star(v123, v8, v110);
    }
/* error exit handlers */
v112:
    popv(8);
    return nil;
}



/* Code for tchscheme */

static Lisp_Object MS_CDECL CC_tchscheme(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "tchscheme");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tchscheme");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* end of prologue */
    stack[-2] = nil;
    v93 = (Lisp_Object)1; /* 0 */
    stack[-1] = v93;
    goto v138;

v138:
    v95 = qvalue(elt(env, 1)); /* rowmax */
    v93 = stack[-1];
    v93 = difference2(v95, v93);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    v93 = Lminusp(nil, v93);
    env = stack[-3];
    if (!(v93 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v95 = qvalue(elt(env, 4)); /* maxvar */
    v93 = stack[-1];
    v93 = plus2(v95, v93);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    v95 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v93/(16/CELL)));
    v93 = (Lisp_Object)49; /* 3 */
    v95 = *(Lisp_Object *)((char *)v95 + (CELL-TAG_VECTOR) + ((int32_t)v93/(16/CELL)));
    v93 = (Lisp_Object)-15; /* -1 */
    if (v95 == v93) goto v140;
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v95 = qvalue(elt(env, 4)); /* maxvar */
    v93 = stack[-1];
    v93 = plus2(v95, v93);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    v95 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v93/(16/CELL)));
    v93 = (Lisp_Object)65; /* 4 */
    v93 = *(Lisp_Object *)((char *)v95 + (CELL-TAG_VECTOR) + ((int32_t)v93/(16/CELL)));
    stack[0] = v93;
    if (v93 == nil) goto v140;
    v93 = stack[0];
    v93 = qcdr(v93);
    if (!(v93 == nil)) goto v140;
    v95 = stack[-1];
    v93 = stack[0];
    v93 = qcar(v93);
    v93 = qcdr(v93);
    v93 = qcar(v93);
    fn = elt(env, 6); /* transferrow */
    v93 = (*qfn2(fn))(qenv(fn), v95, v93);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    if (v93 == nil) goto v140;
    v95 = stack[-1];
    v93 = stack[0];
    v93 = qcar(v93);
    fn = elt(env, 7); /* chscheme */
    v93 = (*qfn2(fn))(qenv(fn), v95, v93);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    v93 = qvalue(elt(env, 5)); /* t */
    stack[-2] = v93;
    goto v140;

v140:
    v93 = stack[-1];
    v93 = add1(v93);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    stack[-1] = v93;
    goto v138;
/* error exit handlers */
v139:
    popv(4);
    return nil;
}



/* Code for den */

static Lisp_Object CC_den(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for den");
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
    v70 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[0];
    v51 = qcdr(v70);
    v70 = (Lisp_Object)17; /* 1 */
    v70 = cons(v51, v70);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v70);
    }
/* error exit handlers */
v74:
    popv(1);
    return nil;
}



/* Code for groebreduceonestepint */

static Lisp_Object MS_CDECL CC_groebreduceonestepint(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v83,
                         Lisp_Object v84, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v159, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "groebreduceonestepint");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebreduceonestepint");
#endif
    if (stack >= stacklimit)
    {
        push5(v84,v83,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v2,v83,v84);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v84;
    stack[-4] = v83;
    stack[-3] = v2;
    stack[-6] = v1;
    stack[-2] = v0;
/* end of prologue */
    v158 = stack[-1];
    fn = elt(env, 7); /* vdpred */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-8];
    stack[0] = v158;
    v159 = v158;
    v158 = v159;
    v158 = (v158 == nil ? lisp_true : nil);
    if (!(v158 == nil)) goto v137;
    v158 = v159;
    v158 = qcdr(v158);
    v158 = qcdr(v158);
    v158 = qcdr(v158);
    v158 = qcar(v158);
    v158 = (v158 == nil ? lisp_true : nil);
    goto v137;

v137:
    if (v158 == nil) goto v161;
    v158 = stack[-2];
    fn = elt(env, 7); /* vdpred */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-8];
    stack[-2] = v158;
    v158 = stack[-6];
    qvalue(elt(env, 1)) = v158; /* secondvalue!* */
    { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }

v161:
    v159 = stack[-4];
    v158 = stack[-1];
    v158 = qcdr(v158);
    v158 = qcar(v158);
    fn = elt(env, 8); /* vevdif */
    v158 = (*qfn2(fn))(qenv(fn), v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-8];
    stack[-7] = v158;
    v158 = stack[-1];
    v158 = qcdr(v158);
    v158 = qcdr(v158);
    v158 = qcar(v158);
    stack[-5] = v158;
    v158 = qvalue(elt(env, 2)); /* !*groebdivide */
    if (v158 == nil) goto v135;
    v159 = stack[-3];
    v158 = stack[-5];
    fn = elt(env, 9); /* vbcgcd */
    v158 = (*qfn2(fn))(qenv(fn), v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-8];
    goto v134;

v134:
    stack[-4] = v158;
    v159 = stack[-5];
    v158 = stack[-4];
    fn = elt(env, 10); /* vbcquot */
    v158 = (*qfn2(fn))(qenv(fn), v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-8];
    stack[-5] = v158;
    v159 = stack[-3];
    v158 = stack[-4];
    fn = elt(env, 10); /* vbcquot */
    v158 = (*qfn2(fn))(qenv(fn), v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-8];
    stack[-4] = v158;
    v158 = stack[-6];
    if (v158 == nil) goto v113;
    v158 = stack[-6];
    if (v158 == nil) goto v113;
    v158 = stack[-6];
    v158 = qcdr(v158);
    v158 = qcdr(v158);
    v158 = qcdr(v158);
    v158 = qcar(v158);
    if (v158 == nil) goto v113;
    v159 = stack[-6];
    v158 = stack[-5];
    fn = elt(env, 11); /* vdpvbcprod */
    v158 = (*qfn2(fn))(qenv(fn), v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-8];
    stack[-6] = v158;
    goto v113;

v113:
    v158 = qvalue(elt(env, 3)); /* !*groebprot */
    if (v158 == nil) goto v97;
    stack[-3] = stack[-5];
    v158 = stack[-4];
    fn = elt(env, 12); /* vbcneg */
    v91 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-8];
    v159 = stack[-7];
    v158 = stack[-1];
    fn = elt(env, 13); /* groebreductionprotocol */
    v158 = (*qfnn(fn))(qenv(fn), 4, stack[-3], v91, v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-8];
    goto v97;

v97:
    v158 = stack[-2];
    fn = elt(env, 7); /* vdpred */
    stack[-3] = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-8];
    stack[-2] = stack[-5];
    v159 = qvalue(elt(env, 4)); /* vdpvars!* */
    v158 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 14); /* vevmaptozero1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-8];
    v158 = stack[-4];
    fn = elt(env, 12); /* vbcneg */
    v159 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-8];
    v158 = stack[-7];
    fn = elt(env, 15); /* vdpilcomb1 */
    v158 = (*qfnn(fn))(qenv(fn), 6, stack[-3], stack[-2], stack[-1], stack[0], v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-8];
    stack[-2] = v158;
    v158 = stack[-6];
    qvalue(elt(env, 1)) = v158; /* secondvalue!* */
    v158 = stack[-5];
    qvalue(elt(env, 6)) = v158; /* thirdvalue!* */
    { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }

v135:
    v158 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 16); /* vbcfi */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-8];
    goto v134;
/* error exit handlers */
v160:
    popv(9);
    return nil;
}



/* Code for partitwedge */

static Lisp_Object CC_partitwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v162;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partitwedge");
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
    v162 = v0;
/* end of prologue */
    v138 = v162;
    v138 = qcdr(v138);
    if (v138 == nil) goto v84;
    v138 = v162;
    fn = elt(env, 1); /* xpndwedge */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mkuniquewedge */
        return (*qfn1(fn))(qenv(fn), v138);
    }

v84:
    v138 = v162;
    v138 = qcar(v138);
    {
        popv(1);
        fn = elt(env, 3); /* partitop */
        return (*qfn1(fn))(qenv(fn), v138);
    }
/* error exit handlers */
v163:
    popv(1);
    return nil;
}



/* Code for coeff_calc */

static Lisp_Object MS_CDECL CC_coeff_calc(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164, v165, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeff_calc");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeff_calc");
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
    push(nil);
/* copy arguments values to proper place */
    v164 = v2;
    v165 = v1;
    v140 = v0;
/* end of prologue */
    stack[0] = elt(env, 1); /* plus */
    fn = elt(env, 2); /* coeff1_calc */
    v164 = (*qfnn(fn))(qenv(fn), 3, v140, v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-1];
    v164 = cons(stack[0], v164);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* reval */
        return (*qfn1(fn))(qenv(fn), v164);
    }
/* error exit handlers */
v166:
    popv(2);
    return nil;
}



/* Code for gcdld */

static Lisp_Object CC_gcdld(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v131, v129, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdld");
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
    v131 = v1;
    v129 = v0;
/* end of prologue */

v65:
    v128 = v131;
    v130 = (Lisp_Object)17; /* 1 */
    if (v128 == v130) goto v157;
    v128 = v131;
    v130 = (Lisp_Object)-15; /* -1 */
    if (v128 == v130) goto v157;
    v130 = v129;
    if (v130 == nil) goto v168;
    v130 = v129;
    v130 = qcar(v130);
    if (v130 == nil) goto v75;
    v130 = v129;
    v130 = qcdr(v130);
    stack[0] = v130;
    v130 = v131;
    v131 = v129;
    v131 = qcar(v131);
    fn = elt(env, 1); /* gcd!-with!-number */
    v130 = (*qfn2(fn))(qenv(fn), v130, v131);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-1];
    v131 = v130;
    v130 = stack[0];
    v129 = v130;
    goto v65;

v75:
    v130 = v129;
    v130 = qcdr(v130);
    v129 = v130;
    goto v65;

v168:
    v130 = v131;
        popv(2);
        return Labsval(nil, v130);

v157:
    v130 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v130); }
/* error exit handlers */
v40:
    popv(2);
    return nil;
}



/* Code for fs!:zerop!: */

static Lisp_Object CC_fsTzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v128, v39;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:zerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v39 = v0;
/* end of prologue */
    v129 = v39;
    v129 = (v129 == nil ? lisp_true : nil);
    if (!(v129 == nil)) return onevalue(v129);
    v129 = v39;
    if (is_number(v129)) goto v154;
    v129 = v39;
    v129 = qcdr(v129);
    v129 = (v129 == nil ? lisp_true : nil);
    goto v157;

v157:
    if (!(v129 == nil)) return onevalue(v129);
    v129 = v39;
    v128 = qcdr(v129);
    v129 = (Lisp_Object)49; /* 3 */
    v129 = *(Lisp_Object *)((char *)v128 + (CELL-TAG_VECTOR) + ((int32_t)v129/(16/CELL)));
    if (v129 == nil) goto v170;
    v129 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v129);

v170:
    v129 = v39;
    v128 = qcdr(v129);
    v129 = (Lisp_Object)1; /* 0 */
    v129 = *(Lisp_Object *)((char *)v128 + (CELL-TAG_VECTOR) + ((int32_t)v129/(16/CELL)));
    v128 = v129;
    v129 = v128;
    if (is_number(v129)) goto v134;
    v129 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v129);

v134:
    v129 = v128;
        return Lzerop(nil, v129);

v154:
    v129 = qvalue(elt(env, 1)); /* nil */
    goto v157;
}



/* Code for dv_skelsplit */

static Lisp_Object CC_dv_skelsplit(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v207, v208;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skelsplit");
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
    v206 = (Lisp_Object)1; /* 0 */
    stack[-5] = v206;
    v206 = stack[-9];
    fn = elt(env, 10); /* listp */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    if (v206 == nil) goto v163;
    v206 = stack[-9];
    v207 = qcar(v206);
    v206 = elt(env, 3); /* symtree */
    v206 = get(v207, v206);
    env = stack[-11];
    stack[-10] = v206;
    v206 = stack[-10];
    if (!(v206 == nil)) goto v156;
    v206 = (Lisp_Object)17; /* 1 */
    stack[-3] = v206;
    v206 = stack[-9];
    v206 = qcdr(v206);
    v207 = Llength(nil, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v206 = stack[-3];
    v206 = difference2(v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v206 = Lminusp(nil, v206);
    env = stack[-11];
    if (v206 == nil) goto v210;
    v206 = qvalue(elt(env, 4)); /* nil */
    goto v153;

v153:
    stack[-10] = v206;
    v206 = stack[-9];
    v207 = qcar(v206);
    v206 = elt(env, 5); /* symmetric */
    v206 = Lflagp(nil, v207, v206);
    env = stack[-11];
    if (v206 == nil) goto v211;
    v207 = elt(env, 6); /* !+ */
    v206 = stack[-10];
    v206 = cons(v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-10] = v206;
    goto v156;

v156:
    v206 = stack[-9];
    v206 = qcdr(v206);
    v206 = Llength(nil, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v206 = sub1(v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v206 = Lmkvect(nil, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-8] = v206;
    v206 = (Lisp_Object)1; /* 0 */
    stack[-7] = v206;
    v206 = stack[-9];
    v206 = qcdr(v206);
    stack[-4] = v206;
    goto v212;

v212:
    v206 = stack[-4];
    if (v206 == nil) goto v213;
    v206 = stack[-4];
    v206 = qcar(v206);
    stack[-1] = v206;
    v206 = stack[-7];
    v206 = add1(v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-7] = v206;
    v206 = stack[-1];
    fn = elt(env, 10); /* listp */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    if (v206 == nil) goto v214;
    stack[-2] = stack[-8];
    v206 = stack[-7];
    stack[0] = sub1(v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v206 = stack[-1];
    v206 = ncons(v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v206;
    goto v18;

v18:
    v206 = stack[-4];
    v206 = qcdr(v206);
    stack[-4] = v206;
    goto v212;

v214:
    v206 = stack[-1];
    fn = elt(env, 11); /* dummyp */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-6] = v206;
    if (v206 == nil) goto v215;
    v207 = stack[-5];
    v206 = stack[-6];
    fn = elt(env, 12); /* max */
    v206 = (*qfn2(fn))(qenv(fn), v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-5] = v206;
    stack[-3] = stack[-8];
    v206 = stack[-7];
    stack[-2] = sub1(v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-1] = elt(env, 1); /* !~dv */
    stack[0] = elt(env, 2); /* !* */
    v206 = stack[-6];
    v206 = ncons(v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v206 = list2star(stack[-1], stack[0], v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[-2]/(16/CELL))) = v206;
    goto v18;

v215:
    stack[-2] = stack[-8];
    v206 = stack[-7];
    stack[0] = sub1(v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v206 = stack[-1];
    v206 = ncons(v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v206;
    goto v18;

v213:
    v208 = stack[-10];
    v207 = stack[-8];
    v206 = elt(env, 9); /* skp_ordp */
    fn = elt(env, 13); /* st_sorttree */
    v206 = (*qfnn(fn))(qenv(fn), 3, v208, v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-10] = v206;
    v206 = stack[-10];
    if (v206 == nil) goto v216;
    v206 = stack[-10];
    v207 = qcar(v206);
    v206 = (Lisp_Object)1; /* 0 */
    if (!(v207 == v206)) goto v216;
    v206 = qvalue(elt(env, 4)); /* nil */
    { popv(12); return onevalue(v206); }

v216:
    v206 = stack[-10];
    v206 = qcar(v206);
    stack[0] = v206;
    v206 = stack[-10];
    v207 = qcdr(v206);
    v206 = stack[-8];
    fn = elt(env, 14); /* dv_skelsplit1 */
    v206 = (*qfn2(fn))(qenv(fn), v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-1] = v206;
    v206 = stack[-1];
    v206 = qcdr(v206);
    fn = elt(env, 15); /* st_consolidate */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-10] = v206;
    v206 = stack[-9];
    v207 = qcar(v206);
    v206 = stack[-1];
    v206 = qcar(v206);
    v206 = cons(v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-1] = v206;
    stack[-2] = stack[-5];
    v207 = stack[-1];
    v206 = stack[-10];
    v206 = cons(v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    {
        Lisp_Object v217 = stack[0];
        Lisp_Object v218 = stack[-2];
        popv(12);
        return list3(v217, v218, v206);
    }

v211:
    v206 = stack[-9];
    v207 = qcar(v206);
    v206 = elt(env, 7); /* antisymmetric */
    v206 = Lflagp(nil, v207, v206);
    env = stack[-11];
    if (v206 == nil) goto v22;
    v207 = elt(env, 8); /* !- */
    v206 = stack[-10];
    v206 = cons(v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-10] = v206;
    goto v156;

v22:
    v207 = elt(env, 2); /* !* */
    v206 = stack[-10];
    v206 = cons(v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-10] = v206;
    goto v156;

v210:
    v206 = stack[-3];
    v206 = ncons(v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-1] = v206;
    stack[-2] = v206;
    goto v219;

v219:
    v206 = stack[-3];
    v206 = add1(v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-3] = v206;
    v206 = stack[-9];
    v206 = qcdr(v206);
    v207 = Llength(nil, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v206 = stack[-3];
    v206 = difference2(v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v206 = Lminusp(nil, v206);
    env = stack[-11];
    if (v206 == nil) goto v150;
    v206 = stack[-2];
    goto v153;

v150:
    stack[0] = stack[-1];
    v206 = stack[-3];
    v206 = ncons(v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v206 = Lrplacd(nil, stack[0], v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v206 = stack[-1];
    v206 = qcdr(v206);
    stack[-1] = v206;
    goto v219;

v163:
    v206 = stack[-9];
    fn = elt(env, 11); /* dummyp */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-6] = v206;
    if (v206 == nil) goto v130;
    stack[-3] = (Lisp_Object)17; /* 1 */
    stack[-2] = stack[-6];
    stack[-1] = elt(env, 1); /* !~dv */
    stack[0] = elt(env, 2); /* !* */
    v206 = stack[-6];
    v206 = ncons(v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v206 = list2star(stack[-1], stack[0], v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    {
        Lisp_Object v220 = stack[-3];
        Lisp_Object v221 = stack[-2];
        popv(12);
        return list3(v220, v221, v206);
    }

v130:
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[0] = (Lisp_Object)1; /* 0 */
    v206 = stack[-9];
    v206 = ncons(v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    {
        Lisp_Object v222 = stack[-1];
        Lisp_Object v223 = stack[0];
        popv(12);
        return list3(v222, v223, v206);
    }
/* error exit handlers */
v209:
    popv(12);
    return nil;
}



/* Code for gcd!-in!-vector */

static Lisp_Object MS_CDECL CC_gcdKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v83, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v240, v241, v242, v243, v213, v244;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "gcd-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcd-in-vector");
#endif
    if (stack >= stacklimit)
    {
        push4(v83,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v83);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v83;
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v241 = stack[-2];
    v240 = (Lisp_Object)1; /* 0 */
    if (v241 == v240) goto v45;
    v241 = stack[0];
    v240 = (Lisp_Object)1; /* 0 */
    if (v241 == v240) goto v45;
    v241 = stack[-2];
    v240 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v241)) < ((int32_t)(v240))) goto v62;
    v241 = stack[0];
    v240 = (Lisp_Object)1; /* 0 */
    if (!(((int32_t)(v241)) < ((int32_t)(v240)))) goto v68;

v62:
    v240 = elt(env, 1); /* "GCD WITH ZERO NOT ALLOWED" */
    fn = elt(env, 3); /* errorf */
    v240 = (*qfn1(fn))(qenv(fn), v240);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    goto v68;

v68:
    v243 = stack[-3];
    v242 = stack[-2];
    v241 = stack[-1];
    v240 = stack[0];
    fn = elt(env, 4); /* remainder!-in!-vector */
    v240 = (*qfnn(fn))(qenv(fn), 4, v243, v242, v241, v240);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    stack[-2] = v240;
    v241 = stack[-2];
    v240 = (Lisp_Object)1; /* 0 */
    if (v241 == v240) goto v246;
    v241 = stack[-2];
    v240 = (Lisp_Object)-15; /* -1 */
    if (v241 == v240) goto v32;
    v243 = stack[-1];
    v242 = stack[0];
    v241 = stack[-3];
    v240 = stack[-2];
    fn = elt(env, 4); /* remainder!-in!-vector */
    v240 = (*qfnn(fn))(qenv(fn), 4, v243, v242, v241, v240);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    stack[0] = v240;
    v241 = stack[0];
    v240 = (Lisp_Object)1; /* 0 */
    if (v241 == v240) goto v15;
    v241 = stack[0];
    v240 = (Lisp_Object)-15; /* -1 */
    if (!(v241 == v240)) goto v68;
    v241 = stack[-3];
    v240 = stack[-2];
    v240 = *(Lisp_Object *)((char *)v241 + (CELL-TAG_VECTOR) + ((int32_t)v240/(16/CELL)));
    v240 = Lmodular_reciprocal(nil, v240);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    v244 = v240;
    v241 = v244;
    v240 = (Lisp_Object)17; /* 1 */
    if (v241 == v240) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v240 = (Lisp_Object)1; /* 0 */
    v213 = v240;
    goto v194;

v194:
    v241 = stack[-2];
    v240 = v213;
    v240 = (Lisp_Object)(int32_t)((int32_t)v241 - (int32_t)v240 + TAG_FIXNUM);
    v240 = ((intptr_t)(v240) < 0 ? lisp_true : nil);
    if (!(v240 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v243 = stack[-3];
    v242 = v213;
    v241 = stack[-3];
    v240 = v213;
    v241 = *(Lisp_Object *)((char *)v241 + (CELL-TAG_VECTOR) + ((int32_t)v240/(16/CELL)));
    v240 = v244;
    v240 = Lmodular_times(nil, v241, v240);
    env = stack[-4];
    *(Lisp_Object *)((char *)v243 + (CELL-TAG_VECTOR) + ((int32_t)v242/(16/CELL))) = v240;
    v240 = v213;
    v240 = (Lisp_Object)((int32_t)(v240) + 0x10);
    v213 = v240;
    goto v194;

v15:
    v242 = stack[-3];
    v241 = (Lisp_Object)1; /* 0 */
    v240 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v242 + (CELL-TAG_VECTOR) + ((int32_t)v241/(16/CELL))) = v240;
    v240 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v240); }

v32:
    v241 = stack[-1];
    v240 = stack[0];
    v240 = *(Lisp_Object *)((char *)v241 + (CELL-TAG_VECTOR) + ((int32_t)v240/(16/CELL)));
    v240 = Lmodular_reciprocal(nil, v240);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    v244 = v240;
    v240 = (Lisp_Object)1; /* 0 */
    v213 = v240;
    goto v247;

v247:
    v241 = stack[0];
    v240 = v213;
    v240 = (Lisp_Object)(int32_t)((int32_t)v241 - (int32_t)v240 + TAG_FIXNUM);
    v240 = ((intptr_t)(v240) < 0 ? lisp_true : nil);
    if (!(v240 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v243 = stack[-3];
    v242 = v213;
    v241 = stack[-1];
    v240 = v213;
    v241 = *(Lisp_Object *)((char *)v241 + (CELL-TAG_VECTOR) + ((int32_t)v240/(16/CELL)));
    v240 = v244;
    v240 = Lmodular_times(nil, v241, v240);
    env = stack[-4];
    *(Lisp_Object *)((char *)v243 + (CELL-TAG_VECTOR) + ((int32_t)v242/(16/CELL))) = v240;
    v240 = v213;
    v240 = (Lisp_Object)((int32_t)(v240) + 0x10);
    v213 = v240;
    goto v247;

v246:
    v242 = stack[-3];
    v241 = (Lisp_Object)1; /* 0 */
    v240 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v242 + (CELL-TAG_VECTOR) + ((int32_t)v241/(16/CELL))) = v240;
    v240 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v240); }

v45:
    v242 = stack[-3];
    v241 = (Lisp_Object)1; /* 0 */
    v240 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v242 + (CELL-TAG_VECTOR) + ((int32_t)v241/(16/CELL))) = v240;
    v240 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v240); }
/* error exit handlers */
v245:
    popv(5);
    return nil;
}



/* Code for bfprin0 */

static Lisp_Object CC_bfprin0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfprin0");
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
    v132 = v0;
/* end of prologue */
    stack[0] = v132;
    v132 = qvalue(elt(env, 1)); /* !:print!-prec!: */
    if (v132 == nil) goto v140;
    v132 = qvalue(elt(env, 1)); /* !:print!-prec!: */
    goto v70;

v70:
    fn = elt(env, 3); /* round!:dec1 */
    v132 = (*qfn2(fn))(qenv(fn), stack[0], v132);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    v133 = v132;
    v133 = qcar(v133);
    v132 = qcdr(v132);
    fn = elt(env, 4); /* bfprin0x */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v105;
    v132 = nil;
    { popv(2); return onevalue(v132); }

v140:
    v133 = qvalue(elt(env, 2)); /* !:prec!: */
    v132 = (Lisp_Object)33; /* 2 */
    v132 = difference2(v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    goto v70;
/* error exit handlers */
v105:
    popv(2);
    return nil;
}



/* Code for xadd!* */

static Lisp_Object MS_CDECL CC_xaddH(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v188, v189, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xadd*");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xadd*");
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
    stack[-9] = v2;
    stack[-10] = v1;
    stack[-11] = v0;
/* end of prologue */
    v188 = stack[-10];
    stack[-12] = v188;
    goto v141;

v141:
    v188 = stack[-12];
    if (v188 == nil) goto v154;
    v188 = stack[-11];
    v189 = qcar(v188);
    v188 = stack[-12];
    v188 = qcar(v188);
    v188 = qcar(v188);
    if (!(equal(v189, v188))) goto v70;
    v188 = stack[-11];
    v188 = qcdr(v188);
    v189 = qcar(v188);
    v188 = stack[-12];
    v188 = qcar(v188);
    v188 = qcdr(v188);
    v188 = qcar(v188);
    if (!(equal(v189, v188))) goto v70;

v154:
    v188 = stack[-12];
    if (v188 == nil) goto v105;
    v188 = stack[-12];
    v189 = qcar(v188);
    v188 = stack[-10];
    v188 = Ldelete(nil, v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-13];
    stack[-10] = v188;
    v188 = stack[-12];
    v188 = qcar(v188);
    stack[-12] = v188;
    v188 = stack[-9];
    if (v188 == nil) goto v105;
    v188 = qvalue(elt(env, 2)); /* newrule!* */
    if (v188 == nil) goto v105;
    v188 = stack[-12];
    v189 = qcar(v188);
    v188 = qvalue(elt(env, 2)); /* newrule!* */
    v188 = qcar(v188);
    stack[0] = v188;
    if (equal(v189, v188)) goto v13;
    v188 = stack[-12];
    v188 = qcar(v188);
    fn = elt(env, 8); /* powlisp */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-13];
    if (v188 == nil) goto v13;
    stack[-8] = elt(env, 3); /* plus */
    stack[-7] = stack[0];
    stack[-6] = elt(env, 4); /* difference */
    v188 = stack[-12];
    v188 = qcdr(v188);
    v188 = qcdr(v188);
    stack[-5] = qcar(v188);
    stack[-4] = elt(env, 5); /* times */
    v188 = stack[-12];
    v188 = qcar(v188);
    stack[-3] = v188;
    v188 = stack[-3];
    if (v188 == nil) goto v252;
    v188 = stack[-3];
    v188 = qcar(v188);
    v7 = elt(env, 6); /* expt */
    v189 = v188;
    v189 = qcar(v189);
    v188 = qcdr(v188);
    v188 = list3(v7, v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-13];
    v188 = ncons(v188);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-13];
    stack[-1] = v188;
    stack[-2] = v188;
    goto v253;

v253:
    v188 = stack[-3];
    v188 = qcdr(v188);
    stack[-3] = v188;
    v188 = stack[-3];
    if (v188 == nil) goto v91;
    stack[0] = stack[-1];
    v188 = stack[-3];
    v188 = qcar(v188);
    v7 = elt(env, 6); /* expt */
    v189 = v188;
    v189 = qcar(v189);
    v188 = qcdr(v188);
    v188 = list3(v7, v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-13];
    v188 = ncons(v188);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-13];
    v188 = Lrplacd(nil, stack[0], v188);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-13];
    v188 = stack[-1];
    v188 = qcdr(v188);
    stack[-1] = v188;
    goto v253;

v91:
    v188 = stack[-2];
    goto v150;

v150:
    v188 = cons(stack[-4], v188);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-13];
    v188 = list3(stack[-6], stack[-5], v188);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-13];
    v188 = list3(stack[-8], stack[-7], v188);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-13];
    fn = elt(env, 9); /* simp */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-13];
    v189 = v188;
    v188 = v189;
    v188 = qcar(v188);
    if (v188 == nil) goto v119;
    v188 = elt(env, 7); /* prepf */
    fn = elt(env, 10); /* sqform */
    v188 = (*qfn2(fn))(qenv(fn), v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-13];
    v189 = v188;
    goto v254;

v254:
    v188 = stack[-12];
    v188 = qcdr(v188);
    v188 = qcar(v188);
    v188 = qcdr(v188);
    fn = elt(env, 11); /* updoldrules */
    v188 = (*qfn2(fn))(qenv(fn), v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-13];
    goto v105;

v105:
    v188 = stack[-9];
    if (v188 == nil) { Lisp_Object res = stack[-10]; popv(14); return onevalue(res); }
    v189 = stack[-11];
    v188 = stack[-10];
    v188 = cons(v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v251;
    stack[-10] = v188;
    { Lisp_Object res = stack[-10]; popv(14); return onevalue(res); }

v119:
    v188 = (Lisp_Object)1; /* 0 */
    v189 = v188;
    goto v254;

v252:
    v188 = qvalue(elt(env, 1)); /* nil */
    goto v150;

v13:
    v188 = stack[-12];
    v188 = qcdr(v188);
    v188 = qcdr(v188);
    v189 = qcar(v188);
    v188 = stack[-12];
    v188 = qcdr(v188);
    v188 = qcar(v188);
    v188 = qcdr(v188);
    fn = elt(env, 11); /* updoldrules */
    v188 = (*qfn2(fn))(qenv(fn), v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-13];
    goto v105;

v70:
    v188 = stack[-12];
    v188 = qcdr(v188);
    stack[-12] = v188;
    goto v141;
/* error exit handlers */
v251:
    popv(14);
    return nil;
}



/* Code for rl_surep */

static Lisp_Object CC_rl_surep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_surep");
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
    v163 = v1;
    v47 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_surep!* */
    v163 = list2(v47, v163);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-1];
    {
        Lisp_Object v137 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v137, v163);
    }
/* error exit handlers */
v136:
    popv(2);
    return nil;
}



/* Code for ciom */

static Lisp_Object CC_ciom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ciom");
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
    v60 = elt(env, 1); /* "<OMATTR>" */
    fn = elt(env, 11); /* printout */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v60 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 12); /* indent!* */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v60 = elt(env, 3); /* "<OMATP>" */
    fn = elt(env, 11); /* printout */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v60 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 12); /* indent!* */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v60 = elt(env, 4); /* "<OMS cd=""typmml"" name=""type"">" */
    fn = elt(env, 11); /* printout */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v60 = elt(env, 5); /* "<OMS cd=""typmml"" name=""" */
    fn = elt(env, 11); /* printout */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v60 = stack[0];
    v60 = qcdr(v60);
    v60 = qcar(v60);
    v60 = qcar(v60);
    v60 = qcdr(v60);
    v60 = qcar(v60);
    v72 = Lintern(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v60 = qvalue(elt(env, 6)); /* mmltypes!* */
    v60 = Lassoc(nil, v72, v60);
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v60 = stack[0];
    v60 = qcdr(v60);
    v60 = qcar(v60);
    v60 = qcar(v60);
    v60 = qcdr(v60);
    v60 = qcar(v60);
    v72 = Lintern(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v60 = qvalue(elt(env, 6)); /* mmltypes!* */
    v60 = Lassoc(nil, v72, v60);
    v60 = qcdr(v60);
    v60 = qcar(v60);
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v60 = elt(env, 7); /* """>" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v60 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 12); /* indent!* */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v60 = elt(env, 9); /* "</OMATP>" */
    fn = elt(env, 11); /* printout */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v60 = stack[0];
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcar(v60);
    fn = elt(env, 13); /* objectom */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v60 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 12); /* indent!* */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v60 = elt(env, 10); /* "</OMATTR>" */
    fn = elt(env, 11); /* printout */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v108;
    v60 = nil;
    { popv(2); return onevalue(v60); }
/* error exit handlers */
v108:
    popv(2);
    return nil;
}



/* Code for simpsqrtsq */

static Lisp_Object CC_simpsqrtsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpsqrtsq");
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
    v51 = stack[0];
    v51 = qcar(v51);
    fn = elt(env, 1); /* simpsqrt2 */
    stack[-1] = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-2];
    v51 = stack[0];
    v51 = qcdr(v51);
    fn = elt(env, 1); /* simpsqrt2 */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v162;
    {
        Lisp_Object v163 = stack[-1];
        popv(3);
        return cons(v163, v51);
    }
/* error exit handlers */
v162:
    popv(3);
    return nil;
}



/* Code for lengthn */

static Lisp_Object CC_lengthn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lengthn");
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
    v46 = stack[0];
    if (v46 == nil) goto v84;
    v46 = stack[0];
    v46 = qcar(v46);
    if (is_number(v46)) goto v70;
    v46 = stack[0];
    v46 = qcdr(v46);
    v46 = CC_lengthn(env, v46);
    nil = C_nil;
    if (exception_pending()) goto v75;
    popv(3);
    return add1(v46);

v70:
    v46 = stack[0];
    v46 = qcar(v46);
    stack[-1] = sub1(v46);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    v46 = stack[0];
    v46 = qcdr(v46);
    v46 = CC_lengthn(env, v46);
    nil = C_nil;
    if (exception_pending()) goto v75;
    {
        Lisp_Object v255 = stack[-1];
        popv(3);
        return plus2(v255, v46);
    }

v84:
    v46 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v46); }
/* error exit handlers */
v75:
    popv(3);
    return nil;
}



/* Code for dip2a */

static Lisp_Object CC_dip2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip2a");
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
    v51 = v0;
/* end of prologue */
    v70 = v51;
    if (v70 == nil) goto v84;
    v70 = v51;
    fn = elt(env, 1); /* dip2a1 */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dipreplus */
        return (*qfn1(fn))(qenv(fn), v70);
    }

v84:
    v70 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v70); }
/* error exit handlers */
v74:
    popv(1);
    return nil;
}



/* Code for dim!<!=deg */

static Lisp_Object CC_dimRMdeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dim<=deg");
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
    v170 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dimex!* */
    fn = elt(env, 3); /* deg!*form */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    fn = elt(env, 4); /* negf */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    fn = elt(env, 5); /* addf */
    v170 = (*qfn2(fn))(qenv(fn), stack[0], v170);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    v66 = v170;
    v170 = v66;
    v170 = (v170 == nil ? lisp_true : nil);
    if (!(v170 == nil)) { popv(2); return onevalue(v170); }
    v170 = v66;
    v170 = integerp(v170);
    if (v170 == nil) goto v48;
    v170 = (Lisp_Object)1; /* 0 */
        popv(2);
        return Lleq(nil, v66, v170);

v48:
    v170 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v170); }
/* error exit handlers */
v43:
    popv(2);
    return nil;
}



/* Code for r2speclist */

static Lisp_Object CC_r2speclist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v60, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2speclist");
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
    v60 = v0;
/* end of prologue */
    v72 = v60;
    v71 = elt(env, 1); /* plus */
    if (!consp(v72)) goto v138;
    v72 = qcar(v72);
    if (!(v72 == v71)) goto v138;
    v71 = v60;
    v71 = qcdr(v71);
    goto v83;

v83:
    v60 = v71;
    v71 = v60;
    stack[-3] = v71;
    v71 = stack[-3];
    if (v71 == nil) goto v45;
    v71 = stack[-3];
    v71 = qcar(v71);
    fn = elt(env, 3); /* r2speclist1 */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    v71 = ncons(v71);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    stack[-1] = v71;
    stack[-2] = v71;
    goto v140;

v140:
    v71 = stack[-3];
    v71 = qcdr(v71);
    stack[-3] = v71;
    v71 = stack[-3];
    if (v71 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v71 = stack[-3];
    v71 = qcar(v71);
    fn = elt(env, 3); /* r2speclist1 */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    v71 = ncons(v71);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    v71 = Lrplacd(nil, stack[0], v71);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    v71 = stack[-1];
    v71 = qcdr(v71);
    stack[-1] = v71;
    goto v140;

v45:
    v71 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v71); }

v138:
    v71 = v60;
    v71 = ncons(v71);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    goto v83;
/* error exit handlers */
v126:
    popv(5);
    return nil;
}



/* Code for fortassign */

static Lisp_Object CC_fortassign(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fortassign");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v74 = v0;
/* end of prologue */
    v138 = v74;
    v138 = qcdr(v138);
    v138 = qcar(v138);
    v74 = qcdr(v74);
    v74 = qcdr(v74);
    v74 = qcar(v74);
    {
        fn = elt(env, 1); /* mkffortassign */
        return (*qfn2(fn))(qenv(fn), v138, v74);
    }
}



/* Code for strand!-alg!-top */

static Lisp_Object MS_CDECL CC_strandKalgKtop(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v205, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "strand-alg-top");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for strand-alg-top");
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
    v205 = stack[-2];
    v133 = stack[0];
    fn = elt(env, 2); /* deletez1 */
    v133 = (*qfn2(fn))(qenv(fn), v205, v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    stack[-2] = v133;
    v105 = stack[0];
    v205 = stack[-1];
    v133 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 3); /* color!-strand */
    v133 = (*qfnn(fn))(qenv(fn), 3, v105, v205, v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    stack[0] = v133;
    v205 = stack[-2];
    v133 = stack[0];
    fn = elt(env, 4); /* contract!-strand */
    v133 = (*qfn2(fn))(qenv(fn), v205, v133);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    stack[-2] = v133;
    v105 = stack[-2];
    v205 = stack[0];
    v133 = qvalue(elt(env, 1)); /* nil */
    {
        popv(4);
        fn = elt(env, 5); /* dstr!-to!-alg */
        return (*qfnn(fn))(qenv(fn), 3, v105, v205, v133);
    }
/* error exit handlers */
v134:
    popv(4);
    return nil;
}



/* Code for njets */

static Lisp_Object CC_njets(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for njets");
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
    v47 = v1;
    v48 = v0;
/* end of prologue */
    stack[-1] = v47;
    stack[0] = v47;
    v47 = v48;
    v47 = sub1(v47);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-2];
    v47 = plus2(stack[0], v47);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-2];
    {
        Lisp_Object v165 = stack[-1];
        popv(3);
        fn = elt(env, 1); /* combin */
        return (*qfn2(fn))(qenv(fn), v165, v47);
    }
/* error exit handlers */
v164:
    popv(3);
    return nil;
}



/* Code for distri_pol */

static Lisp_Object CC_distri_pol(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v257, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for distri_pol");
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
    v257 = stack[-1];
    if (v257 == nil) goto v84;
    v257 = stack[-1];
    if (!consp(v257)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v257 = stack[-1];
    v257 = qcdr(v257);
    if (v257 == nil) goto v45;
    v257 = stack[-1];
    v257 = qcar(v257);
    v257 = ncons(v257);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-3];
    stack[0] = CC_distri_pol(env, v257);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-3];
    v257 = stack[-1];
    v257 = qcdr(v257);
    v257 = CC_distri_pol(env, v257);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-3];
    {
        Lisp_Object v53 = stack[0];
        popv(4);
        fn = elt(env, 2); /* addfd */
        return (*qfn2(fn))(qenv(fn), v53, v257);
    }

v45:
    v257 = (Lisp_Object)17; /* 1 */
    stack[0] = v257;
    v257 = stack[-1];
    stack[-2] = v257;
    goto v44;

v44:
    v257 = stack[-2];
    if (!consp(v257)) goto v43;
    v257 = stack[-2];
    v257 = qcdr(v257);
    if (!(v257 == nil)) goto v43;
    v257 = stack[-2];
    v257 = qcar(v257);
    v29 = qcar(v257);
    v257 = (Lisp_Object)17; /* 1 */
    v257 = cons(v29, v257);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-3];
    v257 = ncons(v257);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-3];
    fn = elt(env, 3); /* multf */
    v257 = (*qfn2(fn))(qenv(fn), stack[0], v257);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-3];
    stack[0] = v257;
    v257 = stack[-2];
    v257 = qcar(v257);
    v257 = qcdr(v257);
    stack[-2] = v257;
    goto v44;

v43:
    v257 = stack[-2];
    if (!consp(v257)) goto v109;
    stack[-1] = stack[0];
    v257 = stack[-2];
    v257 = qcar(v257);
    v257 = ncons(v257);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-3];
    v257 = CC_distri_pol(env, v257);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-3];
    fn = elt(env, 3); /* multf */
    v257 = (*qfn2(fn))(qenv(fn), stack[-1], v257);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-3];
    stack[-1] = CC_distri_pol(env, v257);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-3];
    v257 = stack[-2];
    v257 = qcdr(v257);
    v257 = CC_distri_pol(env, v257);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-3];
    fn = elt(env, 3); /* multf */
    v257 = (*qfn2(fn))(qenv(fn), stack[0], v257);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-3];
    v257 = CC_distri_pol(env, v257);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-3];
    {
        Lisp_Object v150 = stack[-1];
        popv(4);
        fn = elt(env, 2); /* addfd */
        return (*qfn2(fn))(qenv(fn), v150, v257);
    }

v109:
    v29 = stack[0];
    v257 = stack[-2];
    {
        popv(4);
        fn = elt(env, 3); /* multf */
        return (*qfn2(fn))(qenv(fn), v29, v257);
    }

v84:
    v257 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v257); }
/* error exit handlers */
v258:
    popv(4);
    return nil;
}



/* Code for make!-x!-to!-p */

static Lisp_Object MS_CDECL CC_makeKxKtoKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v117, v118, v121, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "make-x-to-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-x-to-p");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v117 = stack[-2];
    v115 = qvalue(elt(env, 1)); /* dpoly */
    if (((int32_t)(v117)) < ((int32_t)(v115))) goto v154;
    v117 = stack[-2];
    v115 = (Lisp_Object)33; /* 2 */
    v118 = quot2(v117, v115);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    v117 = stack[-1];
    v115 = stack[0];
    v115 = CC_makeKxKtoKp(env, 3, v118, v117, v115);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    v122 = stack[0];
    v121 = v115;
    v118 = stack[0];
    v117 = v115;
    v115 = stack[-1];
    fn = elt(env, 4); /* times!-in!-vector */
    v115 = (*qfnn(fn))(qenv(fn), 5, v122, v121, v118, v117, v115);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    stack[-3] = v115;
    v121 = stack[-1];
    v118 = stack[-3];
    v117 = qvalue(elt(env, 3)); /* poly!-vector */
    v115 = qvalue(elt(env, 1)); /* dpoly */
    fn = elt(env, 5); /* remainder!-in!-vector */
    v115 = (*qfnn(fn))(qenv(fn), 4, v121, v118, v117, v115);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    stack[-3] = v115;
    v117 = stack[-2];
    v115 = (Lisp_Object)33; /* 2 */
    v117 = Liremainder(nil, v117, v115);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    v115 = (Lisp_Object)1; /* 0 */
    if (v117 == v115) goto v238;
    v115 = stack[-3];
    v122 = v115;
    goto v263;

v263:
    v115 = v122;
    v115 = ((intptr_t)(v115) < 0 ? lisp_true : nil);
    if (v115 == nil) goto v234;
    v118 = stack[-1];
    v117 = (Lisp_Object)1; /* 0 */
    v115 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v118 + (CELL-TAG_VECTOR) + ((int32_t)v117/(16/CELL))) = v115;
    v121 = stack[-1];
    v115 = stack[-3];
    v118 = (Lisp_Object)((int32_t)(v115) + 0x10);
    v117 = qvalue(elt(env, 3)); /* poly!-vector */
    v115 = qvalue(elt(env, 1)); /* dpoly */
    fn = elt(env, 5); /* remainder!-in!-vector */
    v115 = (*qfnn(fn))(qenv(fn), 4, v121, v118, v117, v115);
    nil = C_nil;
    if (exception_pending()) goto v194;
    stack[-3] = v115;
    goto v238;

v238:
    v115 = (Lisp_Object)1; /* 0 */
    v122 = v115;
    goto v10;

v10:
    v117 = stack[-3];
    v115 = v122;
    v115 = (Lisp_Object)(int32_t)((int32_t)v117 - (int32_t)v115 + TAG_FIXNUM);
    v115 = ((intptr_t)(v115) < 0 ? lisp_true : nil);
    if (!(v115 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v121 = stack[0];
    v118 = v122;
    v117 = stack[-1];
    v115 = v122;
    v115 = *(Lisp_Object *)((char *)v117 + (CELL-TAG_VECTOR) + ((int32_t)v115/(16/CELL)));
    *(Lisp_Object *)((char *)v121 + (CELL-TAG_VECTOR) + ((int32_t)v118/(16/CELL))) = v115;
    v115 = v122;
    v115 = (Lisp_Object)((int32_t)(v115) + 0x10);
    v122 = v115;
    goto v10;

v234:
    v121 = stack[-1];
    v115 = v122;
    v118 = (Lisp_Object)((int32_t)(v115) + 0x10);
    v117 = stack[-1];
    v115 = v122;
    v115 = *(Lisp_Object *)((char *)v117 + (CELL-TAG_VECTOR) + ((int32_t)v115/(16/CELL)));
    *(Lisp_Object *)((char *)v121 + (CELL-TAG_VECTOR) + ((int32_t)v118/(16/CELL))) = v115;
    v115 = v122;
    v115 = (Lisp_Object)((int32_t)(v115) - 0x10);
    v122 = v115;
    goto v263;

v154:
    v115 = (Lisp_Object)1; /* 0 */
    v121 = v115;
    goto v168;

v168:
    v115 = stack[-2];
    v117 = (Lisp_Object)((int32_t)(v115) - 0x10);
    v115 = v121;
    v115 = (Lisp_Object)(int32_t)((int32_t)v117 - (int32_t)v115 + TAG_FIXNUM);
    v115 = ((intptr_t)(v115) < 0 ? lisp_true : nil);
    if (v115 == nil) goto v44;
    v118 = stack[0];
    v117 = stack[-2];
    v115 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v118 + (CELL-TAG_VECTOR) + ((int32_t)v117/(16/CELL))) = v115;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v44:
    v118 = stack[0];
    v117 = v121;
    v115 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v118 + (CELL-TAG_VECTOR) + ((int32_t)v117/(16/CELL))) = v115;
    v115 = v121;
    v115 = (Lisp_Object)((int32_t)(v115) + 0x10);
    v121 = v115;
    goto v168;
/* error exit handlers */
v194:
    popv(5);
    return nil;
}



/* Code for add!-factor */

static Lisp_Object CC_addKfactor(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v35, v126;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add-factor");
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
    v107 = stack[0];
    v107 = Lconsp(nil, v107);
    env = stack[-2];
    if (v107 == nil) goto v255;
    v35 = stack[-1];
    v107 = stack[0];
    v107 = qcar(v107);
    v107 = qcar(v107);
    v107 = (Lisp_Object)greaterp2(v35, v107);
    nil = C_nil;
    if (exception_pending()) goto v204;
    v107 = v107 ? lisp_true : nil;
    env = stack[-2];
    if (v107 == nil) goto v167;
    v107 = qvalue(elt(env, 1)); /* nil */
    goto v84;

v84:
    v35 = v107;
    v107 = v35;
    if (v107 == nil) goto v39;
    stack[-1] = v35;
    v107 = v35;
    v107 = qcdr(v107);
    v107 = add1(v107);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-2];
    v107 = Lrplacd(nil, stack[-1], v107);
    nil = C_nil;
    if (exception_pending()) goto v204;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v39:
    v126 = stack[-1];
    v35 = (Lisp_Object)17; /* 1 */
    v107 = stack[0];
    popv(3);
    return acons(v126, v35, v107);

v167:
    v35 = stack[-1];
    v107 = stack[0];
    v107 = Lassoc(nil, v35, v107);
    goto v84;

v255:
    v107 = qvalue(elt(env, 1)); /* nil */
    goto v84;
/* error exit handlers */
v204:
    popv(3);
    return nil;
}



/* Code for gd_simpl */

static Lisp_Object CC_gd_simpl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v137, v164, v165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gd_simpl");
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
    v165 = v0;
/* end of prologue */
    v164 = qvalue(elt(env, 1)); /* nil */
    v137 = qvalue(elt(env, 2)); /* t */
    v136 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = qvalue(elt(env, 3)); /* !*guardian */
    qvalue(elt(env, 3)) = v164; /* !*guardian */
    stack[-1] = qvalue(elt(env, 4)); /* !*rlnzden */
    qvalue(elt(env, 4)) = v137; /* !*rlnzden */
    stack[0] = qvalue(elt(env, 5)); /* !*rladdcond */
    qvalue(elt(env, 5)) = v136; /* !*rladdcond */
    v136 = v165;
    fn = elt(env, 6); /* rl_simp */
    v164 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-3];
    v137 = qvalue(elt(env, 1)); /* nil */
    v136 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 7); /* rl_simpl */
    v136 = (*qfnn(fn))(qenv(fn), 3, v164, v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-3];
    fn = elt(env, 8); /* rl_prepfof */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-3];
    qvalue(elt(env, 5)) = stack[0]; /* !*rladdcond */
    qvalue(elt(env, 4)) = stack[-1]; /* !*rlnzden */
    qvalue(elt(env, 3)) = stack[-2]; /* !*guardian */
    { popv(4); return onevalue(v136); }
/* error exit handlers */
v168:
    env = stack[-3];
    qvalue(elt(env, 5)) = stack[0]; /* !*rladdcond */
    qvalue(elt(env, 4)) = stack[-1]; /* !*rlnzden */
    qvalue(elt(env, 3)) = stack[-2]; /* !*guardian */
    popv(4);
    return nil;
}



/* Code for ofsf_lnegrel */

static Lisp_Object CC_ofsf_lnegrel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v219, v113, v246;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_lnegrel");
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
    v246 = v0;
/* end of prologue */
    v113 = v246;
    v219 = elt(env, 1); /* equal */
    if (v113 == v219) goto v84;
    v113 = v246;
    v219 = elt(env, 2); /* neq */
    if (v113 == v219) goto v51;
    v113 = v246;
    v219 = elt(env, 3); /* leq */
    if (v113 == v219) goto v165;
    v113 = v246;
    v219 = elt(env, 5); /* lessp */
    if (v113 == v219) goto v255;
    v113 = v246;
    v219 = elt(env, 6); /* geq */
    if (v113 == v219) goto v132;
    v113 = v246;
    v219 = elt(env, 4); /* greaterp */
    if (v113 == v219) goto v131;
    v219 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v219 == nil)) goto v126;
    v219 = elt(env, 8); /* "ofsf_lnegrel: unknown operator " */
    v113 = v246;
    v219 = list2(v219, v113);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[0];
    fn = elt(env, 9); /* lprie */
    v219 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[0];
    goto v126;

v126:
    v219 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v210;
    v219 = nil;
    { popv(1); return onevalue(v219); }

v131:
    v219 = elt(env, 3); /* leq */
    { popv(1); return onevalue(v219); }

v132:
    v219 = elt(env, 5); /* lessp */
    { popv(1); return onevalue(v219); }

v255:
    v219 = elt(env, 6); /* geq */
    { popv(1); return onevalue(v219); }

v165:
    v219 = elt(env, 4); /* greaterp */
    { popv(1); return onevalue(v219); }

v51:
    v219 = elt(env, 1); /* equal */
    { popv(1); return onevalue(v219); }

v84:
    v219 = elt(env, 2); /* neq */
    { popv(1); return onevalue(v219); }
/* error exit handlers */
v210:
    popv(1);
    return nil;
}



/* Code for !*multsq */

static Lisp_Object CC_Hmultsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *multsq");
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
    v12 = stack[-3];
    v12 = qcar(v12);
    if (v12 == nil) goto v51;
    v12 = stack[-2];
    v12 = qcar(v12);
    if (v12 == nil) goto v51;
    v12 = stack[-3];
    v10 = qcdr(v12);
    v12 = (Lisp_Object)17; /* 1 */
    if (!(v10 == v12)) goto v108;
    v12 = stack[-2];
    v10 = qcdr(v12);
    v12 = (Lisp_Object)17; /* 1 */
    if (!(v10 == v12)) goto v108;
    v12 = stack[-3];
    v10 = qcar(v12);
    v12 = stack[-2];
    v12 = qcar(v12);
    fn = elt(env, 2); /* !*multf */
    v10 = (*qfn2(fn))(qenv(fn), v10, v12);
    nil = C_nil;
    if (exception_pending()) goto v77;
    v12 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v10, v12);

v108:
    v12 = stack[-3];
    v10 = qcar(v12);
    v12 = stack[-2];
    v12 = qcdr(v12);
    fn = elt(env, 3); /* gcdf */
    v12 = (*qfn2(fn))(qenv(fn), v10, v12);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[-4] = v12;
    v12 = stack[-2];
    v10 = qcar(v12);
    v12 = stack[-3];
    v12 = qcdr(v12);
    fn = elt(env, 3); /* gcdf */
    v12 = (*qfn2(fn))(qenv(fn), v10, v12);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[-1] = v12;
    v12 = stack[-3];
    v10 = qcar(v12);
    v12 = stack[-4];
    fn = elt(env, 4); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v10, v12);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v12 = stack[-2];
    v10 = qcar(v12);
    v12 = stack[-1];
    fn = elt(env, 4); /* quotf */
    v12 = (*qfn2(fn))(qenv(fn), v10, v12);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    fn = elt(env, 2); /* !*multf */
    v12 = (*qfn2(fn))(qenv(fn), stack[0], v12);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[0] = v12;
    v12 = stack[-3];
    v10 = qcdr(v12);
    v12 = stack[-1];
    fn = elt(env, 4); /* quotf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v10, v12);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v12 = stack[-2];
    v10 = qcdr(v12);
    v12 = stack[-4];
    fn = elt(env, 4); /* quotf */
    v12 = (*qfn2(fn))(qenv(fn), v10, v12);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    fn = elt(env, 2); /* !*multf */
    v12 = (*qfn2(fn))(qenv(fn), stack[-1], v12);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[-4] = v12;
    v12 = stack[-4];
    fn = elt(env, 5); /* minusf */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    if (v12 == nil) goto v198;
    v12 = stack[0];
    fn = elt(env, 6); /* negf */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[0] = v12;
    v12 = stack[-4];
    fn = elt(env, 6); /* negf */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[-4] = v12;
    goto v198;

v198:
    v10 = stack[0];
    v12 = stack[-4];
    fn = elt(env, 3); /* gcdf */
    v12 = (*qfn2(fn))(qenv(fn), v10, v12);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[-1] = v12;
    v10 = stack[-1];
    v12 = (Lisp_Object)17; /* 1 */
    if (v10 == v12) goto v24;
    v10 = stack[0];
    v12 = stack[-1];
    fn = elt(env, 4); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v10, v12);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v10 = stack[-4];
    v12 = stack[-1];
    fn = elt(env, 4); /* quotf */
    v12 = (*qfn2(fn))(qenv(fn), v10, v12);
    nil = C_nil;
    if (exception_pending()) goto v77;
    {
        Lisp_Object v79 = stack[0];
        popv(6);
        return cons(v79, v12);
    }

v24:
    v10 = stack[0];
    v12 = stack[-4];
    popv(6);
    return cons(v10, v12);

v51:
    v10 = qvalue(elt(env, 1)); /* nil */
    v12 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v10, v12);
/* error exit handlers */
v77:
    popv(6);
    return nil;
}



/* Code for makecoeffpairs1 */

static Lisp_Object MS_CDECL CC_makecoeffpairs1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v83, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v244, v270, v271, v272;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "makecoeffpairs1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makecoeffpairs1");
#endif
    if (stack >= stacklimit)
    {
        push4(v83,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v83);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v83;
    stack[-11] = v2;
    stack[-12] = v1;
    stack[-13] = v0;
/* end of prologue */
    v244 = stack[-12];
    if (v244 == nil) goto v146;
    v244 = stack[-13];
    v272 = qcdr(v244);
    v244 = stack[-12];
    v271 = qcdr(v244);
    v244 = stack[-11];
    v270 = qcdr(v244);
    v244 = stack[-10];
    v244 = qcdr(v244);
    v244 = CC_makecoeffpairs1(env, 4, v272, v271, v270, v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    stack[-14] = v244;
    goto v163;

v163:
    v244 = stack[-14];
    if (v244 == nil) goto v62;
    v244 = stack[-14];
    v244 = qcar(v244);
    stack[-6] = v244;
    v244 = stack[-13];
    stack[-2] = qcar(v244);
    v244 = stack[-12];
    stack[-1] = qcar(v244);
    v244 = stack[-11];
    stack[0] = qcar(v244);
    v244 = stack[-10];
    v244 = qcar(v244);
    fn = elt(env, 3); /* tayexp!-minus */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    fn = elt(env, 4); /* makecoeffpairshom */
    v244 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    stack[-5] = v244;
    v244 = stack[-5];
    if (v244 == nil) goto v156;
    v244 = stack[-5];
    v244 = qcar(v244);
    v270 = v244;
    v244 = v270;
    stack[-1] = qcar(v244);
    v244 = stack[-6];
    stack[0] = qcar(v244);
    v244 = v270;
    v270 = qcdr(v244);
    v244 = stack[-6];
    v244 = qcdr(v244);
    v244 = cons(v270, v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    v244 = acons(stack[-1], stack[0], v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    v244 = ncons(v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    stack[-3] = v244;
    stack[-4] = v244;
    goto v135;

v135:
    v244 = stack[-5];
    v244 = qcdr(v244);
    stack[-5] = v244;
    v244 = stack[-5];
    if (v244 == nil) goto v93;
    stack[-2] = stack[-3];
    v244 = stack[-5];
    v244 = qcar(v244);
    v270 = v244;
    v244 = v270;
    stack[-1] = qcar(v244);
    v244 = stack[-6];
    stack[0] = qcar(v244);
    v244 = v270;
    v270 = qcdr(v244);
    v244 = stack[-6];
    v244 = qcdr(v244);
    v244 = cons(v270, v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    v244 = acons(stack[-1], stack[0], v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    v244 = ncons(v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    v244 = Lrplacd(nil, stack[-2], v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    v244 = stack[-3];
    v244 = qcdr(v244);
    stack[-3] = v244;
    goto v135;

v93:
    v244 = stack[-4];
    goto v134;

v134:
    stack[-9] = v244;
    v244 = stack[-9];
    fn = elt(env, 5); /* lastpair */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    stack[-8] = v244;
    v244 = stack[-14];
    v244 = qcdr(v244);
    stack[-14] = v244;
    v244 = stack[-8];
    if (!consp(v244)) goto v163;
    else goto v47;

v47:
    v244 = stack[-14];
    if (v244 == nil) { Lisp_Object res = stack[-9]; popv(16); return onevalue(res); }
    stack[-7] = stack[-8];
    v244 = stack[-14];
    v244 = qcar(v244);
    stack[-6] = v244;
    v244 = stack[-13];
    stack[-2] = qcar(v244);
    v244 = stack[-12];
    stack[-1] = qcar(v244);
    v244 = stack[-11];
    stack[0] = qcar(v244);
    v244 = stack[-10];
    v244 = qcar(v244);
    fn = elt(env, 3); /* tayexp!-minus */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    fn = elt(env, 4); /* makecoeffpairshom */
    v244 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    stack[-5] = v244;
    v244 = stack[-5];
    if (v244 == nil) goto v274;
    v244 = stack[-5];
    v244 = qcar(v244);
    v270 = v244;
    v244 = v270;
    stack[-1] = qcar(v244);
    v244 = stack[-6];
    stack[0] = qcar(v244);
    v244 = v270;
    v270 = qcdr(v244);
    v244 = stack[-6];
    v244 = qcdr(v244);
    v244 = cons(v270, v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    v244 = acons(stack[-1], stack[0], v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    v244 = ncons(v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    stack[-3] = v244;
    stack[-4] = v244;
    goto v275;

v275:
    v244 = stack[-5];
    v244 = qcdr(v244);
    stack[-5] = v244;
    v244 = stack[-5];
    if (v244 == nil) goto v193;
    stack[-2] = stack[-3];
    v244 = stack[-5];
    v244 = qcar(v244);
    v270 = v244;
    v244 = v270;
    stack[-1] = qcar(v244);
    v244 = stack[-6];
    stack[0] = qcar(v244);
    v244 = v270;
    v270 = qcdr(v244);
    v244 = stack[-6];
    v244 = qcdr(v244);
    v244 = cons(v270, v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    v244 = acons(stack[-1], stack[0], v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    v244 = ncons(v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    v244 = Lrplacd(nil, stack[-2], v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    v244 = stack[-3];
    v244 = qcdr(v244);
    stack[-3] = v244;
    goto v275;

v193:
    v244 = stack[-4];
    goto v276;

v276:
    v244 = Lrplacd(nil, stack[-7], v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    v244 = stack[-8];
    fn = elt(env, 5); /* lastpair */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-15];
    stack[-8] = v244;
    v244 = stack[-14];
    v244 = qcdr(v244);
    stack[-14] = v244;
    goto v47;

v274:
    v244 = qvalue(elt(env, 2)); /* nil */
    goto v276;

v156:
    v244 = qvalue(elt(env, 2)); /* nil */
    goto v134;

v62:
    v244 = qvalue(elt(env, 2)); /* nil */
    { popv(16); return onevalue(v244); }

v146:
    v244 = elt(env, 1); /* ((nil)) */
    { popv(16); return onevalue(v244); }
/* error exit handlers */
v273:
    popv(16);
    return nil;
}



/* Code for repr_a */

static Lisp_Object CC_repr_a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repr_a");
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
    v48 = stack[0];
    v48 = qcdr(v48);
    v48 = qcdr(v48);
    v48 = qcar(v48);
    v48 = Lreverse(nil, v48);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-1];
    v48 = qcar(v48);
    v136 = qcar(v48);
    v48 = stack[0];
    v48 = qcdr(v48);
    v48 = qcdr(v48);
    v48 = qcdr(v48);
    v48 = qcar(v48);
    {
        popv(2);
        fn = elt(env, 1); /* addf */
        return (*qfn2(fn))(qenv(fn), v136, v48);
    }
/* error exit handlers */
v164:
    popv(2);
    return nil;
}



/* Code for ofsf_sacrel!-and */

static Lisp_Object CC_ofsf_sacrelKand(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v140, v167;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sacrel-and");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v165 = v1;
    v140 = v0;
/* end of prologue */
    v167 = elt(env, 1); /* ((lessp (lessp . keep) (leq . keep2) (equal . drop) (neq . keep2) (geq . drop) (greaterp . drop)) (leq (lessp . keep1) (leq . keep) (equal . keep1) (neq . lessp) (geq . equa
l) (greaterp . drop)) (equal (lessp . drop) (leq . keep2) (equal . keep) (neq . drop) (geq . keep2) (greaterp . drop)) (neq (lessp . keep1) (leq . lessp) (equal . drop) (neq . keep) (geq . greaterp) (
greaterp . keep1)) (geq (lessp . drop) (leq . equal) (equal . keep1) (neq . greaterp) (geq . keep) (greaterp . keep1)) (greaterp (lessp . drop) (leq . drop) (equal . drop) (neq . keep2) (geq . keep2) 
(greaterp . keep))) */
    v165 = Latsoc(nil, v165, v167);
    v165 = qcdr(v165);
    v165 = Latsoc(nil, v140, v165);
    v165 = qcdr(v165);
    return onevalue(v165);
}



/* Code for prsubsetrd */

static Lisp_Object CC_prsubsetrd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v277, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prsubsetrd");
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
    v277 = qvalue(elt(env, 1)); /* t */
    stack[-1] = v277;
    goto v74;

v74:
    v277 = stack[-3];
    v103 = Llength(nil, v277);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    v277 = (Lisp_Object)17; /* 1 */
    v277 = (Lisp_Object)greaterp2(v103, v277);
    nil = C_nil;
    if (exception_pending()) goto v34;
    v277 = v277 ? lisp_true : nil;
    env = stack[-4];
    if (v277 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v277 = stack[-3];
    stack[0] = qcar(v277);
    v277 = stack[-3];
    v277 = qcar(v277);
    fn = elt(env, 4); /* reval */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    if (equal(stack[0], v277)) goto v167;
    v277 = stack[-3];
    v277 = qcdr(v277);
    stack[0] = qcar(v277);
    v277 = stack[-3];
    v277 = qcdr(v277);
    v277 = qcar(v277);
    fn = elt(env, 4); /* reval */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    if (equal(stack[0], v277)) goto v167;
    v277 = stack[-1];
    if (v277 == nil) goto v108;
    v277 = stack[-3];
    v277 = qcar(v277);
    fn = elt(env, 4); /* reval */
    stack[0] = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    v277 = stack[-3];
    v277 = qcdr(v277);
    v277 = qcar(v277);
    fn = elt(env, 4); /* reval */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    fn = elt(env, 5); /* alg_prsubset */
    v277 = (*qfn2(fn))(qenv(fn), stack[0], v277);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    goto v73;

v73:
    stack[-1] = v277;
    v277 = stack[-3];
    v277 = qcdr(v277);
    stack[-3] = v277;
    goto v74;

v108:
    v277 = qvalue(elt(env, 2)); /* nil */
    goto v73;

v167:
    v277 = nil;
    stack[-3] = v277;
    stack[0] = elt(env, 3); /* prsubset */
    v277 = stack[-2];
    fn = elt(env, 6); /* eval_list_sets */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    v277 = cons(stack[0], v277);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    stack[-1] = v277;
    goto v74;
/* error exit handlers */
v34:
    popv(5);
    return nil;
}



/* Code for spmatsm!* */

static Lisp_Object CC_spmatsmH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v167, v166, v168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spmatsm*");
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
    v167 = v1;
    v166 = v0;
/* end of prologue */
    v167 = v166;
    fn = elt(env, 3); /* spmatsm */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[0];
    v168 = v167;
    v166 = v168;
    v167 = elt(env, 1); /* sparsemat */
    if (!consp(v166)) goto v136;
    v166 = qcar(v166);
    if (v166 == v167) { popv(1); return onevalue(v168); }
    else goto v136;

v136:
    v167 = v168;
    {
        popv(1);
        fn = elt(env, 4); /* matsm!*1 */
        return (*qfn1(fn))(qenv(fn), v167);
    }
/* error exit handlers */
v45:
    popv(1);
    return nil;
}



/* Code for vdpmember */

static Lisp_Object CC_vdpmember(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v168, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpmember");
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

v63:
    v168 = stack[0];
    if (v168 == nil) goto v64;
    v45 = stack[-1];
    v168 = stack[0];
    v168 = qcar(v168);
    fn = elt(env, 2); /* vdpequal */
    v168 = (*qfn2(fn))(qenv(fn), v45, v168);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-2];
    if (!(v168 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v168 = stack[0];
    v168 = qcdr(v168);
    stack[0] = v168;
    goto v63;

v64:
    v168 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v168); }
/* error exit handlers */
v256:
    popv(3);
    return nil;
}



/* Code for dipcontenti */

static Lisp_Object CC_dipcontenti(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v60, v72, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipcontenti");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v73 = v0;
/* end of prologue */
    v71 = v73;
    if (v71 == nil) goto v84;
    v71 = v73;
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v72 = v71;
    v71 = v72;
    if (v71 == nil) goto v48;
    v71 = v73;
    v71 = qcdr(v71);
    v60 = qcar(v71);
    v71 = qvalue(elt(env, 1)); /* !*groebrm */
    if (v71 == nil) goto v40;
    v71 = v73;
    v71 = qcar(v71);
    goto v205;

v205:
    {
        fn = elt(env, 3); /* dipcontenti1 */
        return (*qfnn(fn))(qenv(fn), 3, v60, v71, v72);
    }

v40:
    v71 = qvalue(elt(env, 2)); /* nil */
    goto v205;

v48:
    v71 = v73;
    v71 = qcdr(v71);
    v60 = qcar(v71);
    v71 = qvalue(elt(env, 1)); /* !*groebrm */
    if (v71 == nil) goto v170;
    v71 = v73;
    v71 = qcar(v71);
    goto v164;

v164:
    return cons(v60, v71);

v170:
    v71 = qvalue(elt(env, 2)); /* nil */
    goto v164;

v84:
    v71 = (Lisp_Object)17; /* 1 */
    return onevalue(v71);
}



/* Code for gf2bf */

static Lisp_Object CC_gf2bf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v94, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gf2bf");
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
    goto v63;

v63:
    v32 = stack[0];
    if (v32 == nil) goto v279;
    v32 = stack[0];
    if (!consp(v32)) goto v70;
    v94 = stack[0];
    v32 = elt(env, 1); /* !:rd!: */
    if (!consp(v94)) goto v254;
    v94 = qcar(v94);
    if (!(v94 == v32)) goto v254;
    v32 = stack[0];
    v32 = qcdr(v32);
    if (!consp(v32)) goto v254;
    v94 = stack[-1];
    v32 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v94, v32);
    }

v254:
    v32 = stack[0];
    v32 = qcar(v32);
    v94 = CC_gf2bf(env, v32);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-2];
    v32 = stack[-1];
    v32 = cons(v94, v32);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-2];
    stack[-1] = v32;
    v32 = stack[0];
    v32 = qcdr(v32);
    stack[0] = v32;
    goto v63;

v70:
    v32 = stack[0];
    v32 = Lfloatp(nil, v32);
    env = stack[-2];
    if (v32 == nil) goto v66;
    v32 = stack[0];
    fn = elt(env, 3); /* fl2bf */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-2];
    {
        Lisp_Object v238 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v238, v32);
    }

v66:
    v32 = stack[0];
    if (!consp(v32)) goto v132;
    v32 = stack[0];
    goto v76;

v76:
    fn = elt(env, 4); /* csl_normbf */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-2];
    {
        Lisp_Object v139 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v139, v32);
    }

v132:
    v32 = stack[0];
    v32 = integerp(v32);
    if (v32 == nil) goto v71;
    v93 = elt(env, 1); /* !:rd!: */
    v94 = stack[0];
    v32 = (Lisp_Object)1; /* 0 */
    v32 = list2star(v93, v94, v32);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-2];
    goto v76;

v71:
    v32 = stack[0];
    fn = elt(env, 5); /* read!:num */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-2];
    goto v76;

v279:
    v32 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v32);
    }
/* error exit handlers */
v237:
    popv(3);
    return nil;
}



/* Code for addnew */

static Lisp_Object MS_CDECL CC_addnew(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v42, v69, v134, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "addnew");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addnew");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    v134 = v1;
    v135 = v0;
/* end of prologue */
    v69 = qvalue(elt(env, 1)); /* gv */
    v42 = v134;
    v41 = v135;
    *(Lisp_Object *)((char *)v69 + (CELL-TAG_VECTOR) + ((int32_t)v42/(16/CELL))) = v41;
    v69 = qvalue(elt(env, 2)); /* bv */
    v42 = v134;
    v41 = qvalue(elt(env, 3)); /* t */
    *(Lisp_Object *)((char *)v69 + (CELL-TAG_VECTOR) + ((int32_t)v42/(16/CELL))) = v41;
    v41 = v135;
    if (v41 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = v134;
    v41 = v135;
    fn = elt(env, 4); /* ljet */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-2];
    v42 = cons(stack[-1], v41);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-2];
    v41 = stack[0];
    fn = elt(env, 5); /* insert */
    v41 = (*qfn2(fn))(qenv(fn), v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v129;
    { popv(3); return onevalue(v41); }
/* error exit handlers */
v129:
    popv(3);
    return nil;
}



/* Code for rl_qefsolset */

static Lisp_Object MS_CDECL CC_rl_qefsolset(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v83,
                         Lisp_Object v84, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v255, v170, v66, v161, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "rl_qefsolset");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_qefsolset");
#endif
    if (stack >= stacklimit)
    {
        push5(v84,v83,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v2,v83,v84);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v255 = v84;
    v170 = v83;
    v66 = v2;
    v161 = v1;
    v43 = v0;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* rl_qefsolset!* */
    stack[-2] = v43;
    stack[-1] = v161;
    stack[0] = v66;
    v255 = list2(v170, v255);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-4];
    v255 = list3star(stack[-2], stack[-1], stack[0], v255);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-4];
    {
        Lisp_Object v132 = stack[-3];
        popv(5);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v132, v255);
    }
/* error exit handlers */
v59:
    popv(5);
    return nil;
}



/* Code for sfto_yun!-updecf */

static Lisp_Object CC_sfto_yunKupdecf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v281, v282;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_yun-updecf");
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
    stack[-7] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    stack[-1] = nil;
    v281 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v281; /* !*gcd */
    v282 = (Lisp_Object)17; /* 1 */
    v281 = (Lisp_Object)17; /* 1 */
    v281 = cons(v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    stack[-2] = v281;
    v281 = stack[-6];
    v281 = qcar(v281);
    v281 = qcar(v281);
    v281 = qcar(v281);
    stack[-5] = v281;
    stack[-3] = stack[-6];
    v282 = stack[-6];
    v281 = stack[-5];
    fn = elt(env, 3); /* diff */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    stack[0] = v281;
    fn = elt(env, 4); /* sfto_gcdf */
    v281 = (*qfn2(fn))(qenv(fn), stack[-3], v281);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    stack[-3] = v281;
    v282 = stack[-6];
    v281 = stack[-3];
    fn = elt(env, 5); /* quotf */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    stack[-4] = v281;
    v282 = stack[0];
    v281 = stack[-3];
    fn = elt(env, 5); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    v282 = stack[-4];
    v281 = stack[-5];
    fn = elt(env, 3); /* diff */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    fn = elt(env, 6); /* negf */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    fn = elt(env, 7); /* addf */
    v281 = (*qfn2(fn))(qenv(fn), stack[0], v281);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    stack[-3] = v281;
    goto v155;

v155:
    v281 = stack[-1];
    v281 = (v281 == nil ? lisp_true : nil);
    stack[-1] = v281;
    v282 = stack[-4];
    v281 = stack[-3];
    fn = elt(env, 4); /* sfto_gcdf */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    stack[-6] = v281;
    v281 = stack[-1];
    if (v281 == nil) goto v93;
    stack[0] = stack[-2];
    v281 = stack[-2];
    v282 = qcar(v281);
    v281 = stack[-6];
    fn = elt(env, 8); /* multf */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    fn = elt(env, 9); /* setcar */
    v281 = (*qfn2(fn))(qenv(fn), stack[0], v281);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    goto v148;

v148:
    v282 = stack[-4];
    v281 = stack[-6];
    fn = elt(env, 5); /* quotf */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    stack[-4] = v281;
    v282 = stack[-3];
    v281 = stack[-6];
    fn = elt(env, 5); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    v282 = stack[-4];
    v281 = stack[-5];
    fn = elt(env, 3); /* diff */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    fn = elt(env, 6); /* negf */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    fn = elt(env, 7); /* addf */
    v281 = (*qfn2(fn))(qenv(fn), stack[0], v281);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    stack[-3] = v281;
    v281 = stack[-4];
    if (!consp(v281)) goto v204;
    v281 = stack[-4];
    v281 = qcar(v281);
    if (!(!consp(v281))) goto v155;

v204:
    v281 = stack[-2];
    qvalue(elt(env, 1)) = stack[-7]; /* !*gcd */
    { popv(9); return onevalue(v281); }

v93:
    stack[0] = stack[-2];
    v281 = stack[-2];
    v282 = qcdr(v281);
    v281 = stack[-6];
    fn = elt(env, 8); /* multf */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    fn = elt(env, 10); /* setcdr */
    v281 = (*qfn2(fn))(qenv(fn), stack[0], v281);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    goto v148;
/* error exit handlers */
v249:
    env = stack[-8];
    qvalue(elt(env, 1)) = stack[-7]; /* !*gcd */
    popv(9);
    return nil;
}



/* Code for checkexp */

static Lisp_Object CC_checkexp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v62, v169, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checkexp");
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
    v169 = v1;
    v76 = v0;
/* end of prologue */
    v62 = v169;
    v44 = (Lisp_Object)1; /* 0 */
    if (v62 == v44) goto v63;
    v62 = v169;
    v44 = (Lisp_Object)17; /* 1 */
    if (v62 == v44) { popv(2); return onevalue(v76); }
    stack[-1] = elt(env, 1); /* expt */
    stack[0] = v76;
    v44 = v169;
    fn = elt(env, 2); /* preptayexp */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v133;
    {
        Lisp_Object v205 = stack[-1];
        Lisp_Object v105 = stack[0];
        popv(2);
        return list3(v205, v105, v44);
    }

v63:
    v44 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v44); }
/* error exit handlers */
v133:
    popv(2);
    return nil;
}



/* Code for rule!* */

static Lisp_Object MS_CDECL CC_ruleH(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v83,
                         Lisp_Object v84, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v284, v18, v11, v214, v285;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "rule*");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rule*");
#endif
    if (stack >= stacklimit)
    {
        push5(v84,v83,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v2,v83,v84);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v84;
    stack[-1] = v83;
    stack[-2] = v2;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v284 = stack[-2];
    qvalue(elt(env, 1)) = v284; /* frasc!* */
    v18 = stack[-1];
    v284 = qvalue(elt(env, 2)); /* t */
    v284 = (v18 == v284 ? lisp_true : nil);
    if (!(v284 == nil)) goto v141;
    v18 = stack[-2];
    v284 = stack[-1];
    v284 = Lsubla(nil, v18, v284);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-5];
    goto v141;

v141:
    qvalue(elt(env, 3)) = v284; /* mcond!* */
    v284 = stack[0];
    if (v284 == nil) goto v86;
    v18 = stack[0];
    v284 = elt(env, 4); /* old */
    if (v18 == v284) goto v86;
    v214 = stack[-4];
    v11 = stack[-3];
    v18 = stack[-2];
    v284 = stack[-1];
    v284 = list4(v214, v11, v18, v284);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-5];
    qvalue(elt(env, 5)) = v284; /* newrule!* */
    v284 = stack[-4];
    if (!(symbolp(v284))) goto v286;
    v18 = stack[-4];
    v284 = elt(env, 6); /* rtype */
    v284 = get(v18, v284);
    env = stack[-5];
    v18 = v284;
    if (v284 == nil) goto v31;
    stack[-1] = stack[-4];
    v284 = elt(env, 6); /* rtype */
    v18 = cons(v284, v18);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-5];
    v284 = qvalue(elt(env, 7)); /* props!* */
    v284 = acons(stack[-1], v18, v284);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-5];
    qvalue(elt(env, 7)) = v284; /* props!* */
    v18 = stack[-4];
    v284 = elt(env, 6); /* rtype */
    v284 = Lremprop(nil, v18, v284);
    env = stack[-5];
    goto v31;

v31:
    v18 = stack[-4];
    v284 = elt(env, 8); /* avalue */
    v284 = get(v18, v284);
    env = stack[-5];
    v18 = v284;
    if (v284 == nil) goto v286;
    v284 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 12); /* updoldrules */
    v284 = (*qfn2(fn))(qenv(fn), v18, v284);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-5];
    v18 = stack[-4];
    v284 = elt(env, 8); /* avalue */
    v284 = Lremprop(nil, v18, v284);
    env = stack[-5];
    goto v286;

v286:
    v18 = stack[-3];
    v284 = (Lisp_Object)1; /* 0 */
    if (!(v18 == v284)) goto v86;
    v18 = stack[-4];
    v284 = elt(env, 10); /* expt */
    if (!consp(v18)) goto v86;
    v18 = qcar(v18);
    if (!(v18 == v284)) goto v86;
    v284 = stack[-4];
    v284 = qcdr(v284);
    v284 = qcar(v284);
    if (!(symbolp(v284))) goto v86;
    v284 = stack[-4];
    v284 = qcdr(v284);
    v284 = qcdr(v284);
    v284 = qcar(v284);
    if (!(is_number(v284))) goto v86;
    v284 = stack[-4];
    v284 = qcdr(v284);
    v18 = qcar(v284);
    v284 = qvalue(elt(env, 11)); /* asymplis!* */
    v284 = Lassoc(nil, v18, v284);
    v18 = v284;
    if (v284 == nil) goto v86;
    v284 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 12); /* updoldrules */
    v284 = (*qfn2(fn))(qenv(fn), v18, v284);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-5];
    goto v86;

v86:
    v285 = stack[-4];
    v214 = stack[-3];
    v11 = stack[-2];
    v18 = stack[0];
    v284 = elt(env, 4); /* old */
    if (v18 == v284) goto v230;
    v284 = stack[0];
    goto v15;

v15:
    {
        popv(6);
        fn = elt(env, 13); /* rule */
        return (*qfnn(fn))(qenv(fn), 4, v285, v214, v11, v284);
    }

v230:
    v284 = qvalue(elt(env, 2)); /* t */
    goto v15;
/* error exit handlers */
v13:
    popv(6);
    return nil;
}



/* Code for qqe_simplbtat */

static Lisp_Object CC_qqe_simplbtat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v239, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplbtat");
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
    v239 = v1;
    stack[-2] = v0;
/* end of prologue */
    v239 = stack[-2];
    fn = elt(env, 6); /* rl_prepat */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-4];
    stack[-3] = v239;
    v239 = stack[-2];
    fn = elt(env, 7); /* qqe_op */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-4];
    stack[0] = v239;
    v239 = stack[-3];
    fn = elt(env, 8); /* qqe_arg2l */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-4];
    fn = elt(env, 9); /* qqe_eta!-in!-term */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-4];
    stack[-1] = v239;
    v239 = stack[-3];
    fn = elt(env, 10); /* qqe_arg2r */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-4];
    fn = elt(env, 9); /* qqe_eta!-in!-term */
    v239 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-4];
    v33 = v239;
    v239 = stack[-1];
    if (v239 == nil) goto v137;
    v239 = v33;
    if (!(v239 == nil)) goto v137;
    v33 = stack[0];
    v239 = elt(env, 1); /* neq */
    if (v33 == v239) goto v44;
    v239 = elt(env, 2); /* false */
    { popv(5); return onevalue(v239); }

v44:
    v239 = elt(env, 3); /* true */
    { popv(5); return onevalue(v239); }

v137:
    v239 = v33;
    if (v239 == nil) goto v132;
    v239 = stack[-1];
    if (!(v239 == nil)) goto v132;
    v33 = stack[0];
    v239 = elt(env, 1); /* neq */
    if (v33 == v239) goto v68;
    v239 = elt(env, 2); /* false */
    { popv(5); return onevalue(v239); }

v68:
    v239 = elt(env, 3); /* true */
    { popv(5); return onevalue(v239); }

v132:
    v239 = stack[-1];
    if (v239 == nil) goto v277;
    v239 = v33;
    if (v239 == nil) goto v277;
    v239 = stack[-2];
    fn = elt(env, 7); /* qqe_op */
    v33 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-4];
    v239 = elt(env, 5); /* equal */
    if (v33 == v239) goto v155;
    v239 = elt(env, 2); /* false */
    { popv(5); return onevalue(v239); }

v155:
    v239 = elt(env, 3); /* true */
    { popv(5); return onevalue(v239); }

v277:
    v239 = stack[-3];
    {
        popv(5);
        fn = elt(env, 11); /* rl_simpat */
        return (*qfn1(fn))(qenv(fn), v239);
    }
/* error exit handlers */
v265:
    popv(5);
    return nil;
}



setup_type const u39_setup[] =
{
    {"rdzchk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_rdzchk},
    {"mo=modiv1",               too_few_2,      CC_moMmodiv1,  wrong_no_2},
    {"depend-p",                too_few_2,      CC_dependKp,   wrong_no_2},
    {"numir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_numir},
    {"tchscheme",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_tchscheme},
    {"den",                     CC_den,         too_many_1,    wrong_no_1},
    {"groebreduceonestepint",   wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebreduceonestepint},
    {"partitwedge",             CC_partitwedge, too_many_1,    wrong_no_1},
    {"coeff_calc",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeff_calc},
    {"gcdld",                   too_few_2,      CC_gcdld,      wrong_no_2},
    {"fs:zerop:",               CC_fsTzeropT,   too_many_1,    wrong_no_1},
    {"dv_skelsplit",            CC_dv_skelsplit,too_many_1,    wrong_no_1},
    {"gcd-in-vector",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_gcdKinKvector},
    {"bfprin0",                 CC_bfprin0,     too_many_1,    wrong_no_1},
    {"xadd*",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_xaddH},
    {"rl_surep",                too_few_2,      CC_rl_surep,   wrong_no_2},
    {"ciom",                    CC_ciom,        too_many_1,    wrong_no_1},
    {"simpsqrtsq",              CC_simpsqrtsq,  too_many_1,    wrong_no_1},
    {"lengthn",                 CC_lengthn,     too_many_1,    wrong_no_1},
    {"dip2a",                   CC_dip2a,       too_many_1,    wrong_no_1},
    {"dim<=deg",                CC_dimRMdeg,    too_many_1,    wrong_no_1},
    {"r2speclist",              CC_r2speclist,  too_many_1,    wrong_no_1},
    {"fortassign",              CC_fortassign,  too_many_1,    wrong_no_1},
    {"strand-alg-top",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_strandKalgKtop},
    {"njets",                   too_few_2,      CC_njets,      wrong_no_2},
    {"distri_pol",              CC_distri_pol,  too_many_1,    wrong_no_1},
    {"make-x-to-p",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeKxKtoKp},
    {"add-factor",              too_few_2,      CC_addKfactor, wrong_no_2},
    {"gd_simpl",                CC_gd_simpl,    too_many_1,    wrong_no_1},
    {"ofsf_lnegrel",            CC_ofsf_lnegrel,too_many_1,    wrong_no_1},
    {"*multsq",                 too_few_2,      CC_Hmultsq,    wrong_no_2},
    {"makecoeffpairs1",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_makecoeffpairs1},
    {"repr_a",                  CC_repr_a,      too_many_1,    wrong_no_1},
    {"ofsf_sacrel-and",         too_few_2,      CC_ofsf_sacrelKand,wrong_no_2},
    {"prsubsetrd",              CC_prsubsetrd,  too_many_1,    wrong_no_1},
    {"spmatsm*",                too_few_2,      CC_spmatsmH,   wrong_no_2},
    {"vdpmember",               too_few_2,      CC_vdpmember,  wrong_no_2},
    {"dipcontenti",             CC_dipcontenti, too_many_1,    wrong_no_1},
    {"gf2bf",                   CC_gf2bf,       too_many_1,    wrong_no_1},
    {"addnew",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_addnew},
    {"rl_qefsolset",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_qefsolset},
    {"sfto_yun-updecf",         CC_sfto_yunKupdecf,too_many_1, wrong_no_1},
    {"checkexp",                too_few_2,      CC_checkexp,   wrong_no_2},
    {"rule*",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_ruleH},
    {"qqe_simplbtat",           too_few_2,      CC_qqe_simplbtat,wrong_no_2},
    {NULL, (one_args *)"u39", (two_args *)"11501 8724812 8251453", 0}
};

/* end of generated code */
