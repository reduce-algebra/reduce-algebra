
/* $destdir\u28.c        Machine generated C code */

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


/* Code for rd!:difference */

static Lisp_Object CC_rdTdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v41, v42;
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
    v40 = qvalue(elt(env, 2)); /* !*!*roundbf */
    if (!(v40 == nil)) goto v43;
    v40 = stack[0];
    v40 = qcdr(v40);
    if (!(!consp(v40))) goto v43;
    v40 = stack[-1];
    v40 = qcdr(v40);
    if (!(!consp(v40))) goto v43;
    v40 = stack[0];
    stack[-2] = qcdr(v40);
    v40 = stack[-1];
    v40 = qcdr(v40);
    v40 = negate(v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    fn = elt(env, 7); /* safe!-fp!-plus */
    v40 = (*qfn2(fn))(qenv(fn), stack[-2], v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v41 = v40;
    if (v40 == nil) goto v43;
    v40 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v40, v41);

v43:
    v41 = stack[0];
    v40 = stack[-1];
    fn = elt(env, 8); /* convprc2 */
    v40 = (*qfn2(fn))(qenv(fn), v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    stack[-1] = v40;
    v40 = qvalue(elt(env, 4)); /* yy!! */
    stack[-3] = v40;
    v40 = stack[-1];
    if (!consp(v40)) goto v45;
    v41 = stack[-1];
    v40 = stack[-3];
    fn = elt(env, 9); /* difbf */
    v40 = (*qfn2(fn))(qenv(fn), v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    goto v46;

v46:
    stack[0] = v40;
    stack[-2] = stack[0];
    v40 = stack[-3];
    if (!consp(v40)) goto v47;
    stack[0] = elt(env, 3); /* !:rd!: */
    v40 = stack[-3];
    v40 = qcdr(v40);
    v40 = qcar(v40);
    v41 = negate(v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v40 = stack[-3];
    v40 = qcdr(v40);
    v40 = qcdr(v40);
    v40 = list2star(stack[0], v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    goto v48;

v48:
    fn = elt(env, 10); /* rdzchk */
    v40 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v41 = v40;
    v40 = v41;
    if (!(!consp(v40))) { popv(5); return onevalue(v41); }
    v40 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v40, v41);

v47:
    v40 = stack[-3];
    v40 = negate(v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    goto v48;

v45:
    stack[-2] = elt(env, 5); /* difference */
    v40 = stack[-1];
    stack[0] = Lmkquote(nil, v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v40 = stack[-3];
    v40 = Lmkquote(nil, v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v42 = list3(stack[-2], stack[0], v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v41 = qvalue(elt(env, 1)); /* nil */
    v40 = qvalue(elt(env, 6)); /* !*backtrace */
    fn = elt(env, 11); /* errorset */
    v40 = (*qfnn(fn))(qenv(fn), 3, v42, v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v41 = v40;
    v40 = v41;
    if (!consp(v40)) goto v49;
    v40 = v41;
    v40 = qcdr(v40);
    if (!(v40 == nil)) goto v49;
    v40 = v41;
    v40 = qcar(v40);
    goto v46;

v49:
    fn = elt(env, 12); /* rndbfon */
    v40 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v40 = stack[-1];
    v40 = Lfloatp(nil, v40);
    env = stack[-4];
    if (v40 == nil) goto v50;
    v40 = stack[-1];
    fn = elt(env, 13); /* fl2bf */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    stack[0] = v40;
    goto v51;

v51:
    stack[-1] = stack[0];
    v40 = stack[-3];
    v40 = Lfloatp(nil, v40);
    env = stack[-4];
    if (v40 == nil) goto v52;
    v40 = stack[-3];
    fn = elt(env, 13); /* fl2bf */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    goto v53;

v53:
    stack[-3] = v40;
    fn = elt(env, 9); /* difbf */
    v40 = (*qfn2(fn))(qenv(fn), stack[0], v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    goto v46;

v52:
    v40 = stack[-3];
    if (!consp(v40)) goto v54;
    v40 = stack[-3];
    goto v55;

v55:
    fn = elt(env, 14); /* csl_normbf */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    goto v53;

v54:
    v40 = stack[-3];
    v40 = integerp(v40);
    if (v40 == nil) goto v56;
    v42 = elt(env, 3); /* !:rd!: */
    v41 = stack[-3];
    v40 = (Lisp_Object)1; /* 0 */
    v40 = list2star(v42, v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    goto v55;

v56:
    v40 = stack[-3];
    fn = elt(env, 15); /* read!:num */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    goto v55;

v50:
    v40 = stack[-1];
    if (!consp(v40)) goto v57;
    v40 = stack[-1];
    goto v58;

v58:
    fn = elt(env, 14); /* csl_normbf */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    stack[0] = v40;
    goto v51;

v57:
    v40 = stack[-1];
    v40 = integerp(v40);
    if (v40 == nil) goto v59;
    v42 = elt(env, 3); /* !:rd!: */
    v41 = stack[-1];
    v40 = (Lisp_Object)1; /* 0 */
    v40 = list2star(v42, v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    goto v58;

v59:
    v40 = stack[-1];
    fn = elt(env, 15); /* read!:num */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    goto v58;
/* error exit handlers */
v44:
    popv(5);
    return nil;
}



/* Code for physoptimes */

static Lisp_Object CC_physoptimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v44;
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
    v44 = qvalue(elt(env, 1)); /* tstack!* */
    v88 = (Lisp_Object)1; /* 0 */
    if (!(v44 == v88)) goto v89;
    v88 = qvalue(elt(env, 2)); /* mul!* */
    if (v88 == nil) goto v89;
    v88 = qvalue(elt(env, 2)); /* mul!* */
    stack[-2] = v88;
    v88 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 2)) = v88; /* mul!* */
    goto v89;

v89:
    v88 = qvalue(elt(env, 1)); /* tstack!* */
    v88 = add1(v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    qvalue(elt(env, 1)) = v88; /* tstack!* */
    v88 = stack[0];
    v88 = qcar(v88);
    fn = elt(env, 5); /* physopsim!* */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    stack[-6] = v88;
    v88 = stack[0];
    v88 = qcdr(v88);
    stack[-1] = v88;
    goto v91;

v91:
    v88 = stack[-1];
    if (v88 == nil) goto v92;
    v88 = stack[-1];
    v88 = qcar(v88);
    fn = elt(env, 5); /* physopsim!* */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    stack[-5] = v88;
    v88 = stack[-6];
    fn = elt(env, 6); /* getphystype */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    stack[-4] = v88;
    v88 = stack[-5];
    fn = elt(env, 6); /* getphystype */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    stack[-3] = v88;
    v88 = stack[-4];
    if (v88 == nil) goto v93;
    v88 = stack[-3];
    if (v88 == nil) goto v94;
    v88 = stack[-6];
    fn = elt(env, 7); /* physopaeval */
    stack[0] = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    v88 = stack[-5];
    fn = elt(env, 7); /* physopaeval */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    fn = elt(env, 8); /* physopordchk */
    v88 = (*qfn2(fn))(qenv(fn), stack[0], v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    if (v88 == nil) goto v7;
    v44 = stack[-4];
    v88 = stack[-3];
    if (!(equal(v44, v88))) goto v7;
    v44 = stack[-4];
    v88 = elt(env, 4); /* scalar */
    if (!(v44 == v88)) goto v7;
    v88 = stack[-6];
    fn = elt(env, 9); /* physop2sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    v88 = stack[-5];
    fn = elt(env, 9); /* physop2sq */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    fn = elt(env, 10); /* multsq */
    v88 = (*qfn2(fn))(qenv(fn), stack[0], v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    fn = elt(env, 11); /* mk!*sq */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    stack[-6] = v88;
    goto v95;

v95:
    v88 = stack[-1];
    v88 = qcdr(v88);
    stack[-1] = v88;
    goto v91;

v7:
    v44 = stack[-6];
    v88 = stack[-5];
    fn = elt(env, 12); /* multopop!* */
    v88 = (*qfn2(fn))(qenv(fn), v44, v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    stack[-6] = v88;
    goto v95;

v94:
    v88 = stack[-5];
    v88 = (Lisp_Object)zerop(v88);
    v88 = v88 ? lisp_true : nil;
    env = stack[-7];
    if (v88 == nil) goto v96;
    v44 = qvalue(elt(env, 3)); /* nil */
    v88 = (Lisp_Object)17; /* 1 */
    v88 = cons(v44, v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    fn = elt(env, 11); /* mk!*sq */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    goto v97;

v97:
    stack[-6] = v88;
    goto v95;

v96:
    v88 = stack[-5];
    v88 = Lonep(nil, v88);
    env = stack[-7];
    if (v88 == nil) goto v59;
    v88 = stack[-6];
    fn = elt(env, 9); /* physop2sq */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    fn = elt(env, 11); /* mk!*sq */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    goto v97;

v59:
    v88 = stack[-5];
    fn = elt(env, 9); /* physop2sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    v88 = stack[-6];
    fn = elt(env, 9); /* physop2sq */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    fn = elt(env, 10); /* multsq */
    v88 = (*qfn2(fn))(qenv(fn), stack[0], v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    fn = elt(env, 11); /* mk!*sq */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    goto v97;

v93:
    v88 = stack[-3];
    if (v88 == nil) goto v98;
    v88 = stack[-6];
    v88 = (Lisp_Object)zerop(v88);
    v88 = v88 ? lisp_true : nil;
    env = stack[-7];
    if (v88 == nil) goto v99;
    v44 = qvalue(elt(env, 3)); /* nil */
    v88 = (Lisp_Object)17; /* 1 */
    v88 = cons(v44, v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    fn = elt(env, 11); /* mk!*sq */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    stack[-6] = v88;
    goto v95;

v99:
    v88 = stack[-6];
    v88 = Lonep(nil, v88);
    env = stack[-7];
    if (v88 == nil) goto v100;
    v88 = stack[-5];
    fn = elt(env, 9); /* physop2sq */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    fn = elt(env, 11); /* mk!*sq */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    stack[-6] = v88;
    goto v95;

v100:
    v88 = stack[-6];
    fn = elt(env, 9); /* physop2sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    v88 = stack[-5];
    fn = elt(env, 9); /* physop2sq */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    fn = elt(env, 10); /* multsq */
    v88 = (*qfn2(fn))(qenv(fn), stack[0], v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    fn = elt(env, 11); /* mk!*sq */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    stack[-6] = v88;
    goto v95;

v98:
    v88 = stack[-6];
    fn = elt(env, 9); /* physop2sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    v88 = stack[-5];
    fn = elt(env, 9); /* physop2sq */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    fn = elt(env, 10); /* multsq */
    v88 = (*qfn2(fn))(qenv(fn), stack[0], v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    fn = elt(env, 11); /* mk!*sq */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    stack[-6] = v88;
    goto v95;

v92:
    v88 = qvalue(elt(env, 2)); /* mul!* */
    if (v88 == nil) goto v101;
    v44 = qvalue(elt(env, 1)); /* tstack!* */
    v88 = (Lisp_Object)17; /* 1 */
    v88 = (Lisp_Object)greaterp2(v44, v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    v88 = v88 ? lisp_true : nil;
    env = stack[-7];
    if (!(v88 == nil)) goto v101;
    v88 = qvalue(elt(env, 2)); /* mul!* */
    v44 = qcar(v88);
    v88 = stack[-6];
    v88 = Lapply1(nil, v44, v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    stack[-6] = v88;
    v88 = qvalue(elt(env, 2)); /* mul!* */
    v88 = qcdr(v88);
    qvalue(elt(env, 2)) = v88; /* mul!* */
    goto v92;

v101:
    v88 = qvalue(elt(env, 1)); /* tstack!* */
    v88 = sub1(v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-7];
    qvalue(elt(env, 1)) = v88; /* tstack!* */
    v44 = qvalue(elt(env, 1)); /* tstack!* */
    v88 = (Lisp_Object)1; /* 0 */
    if (!(v44 == v88)) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v88 = stack[-2];
    qvalue(elt(env, 2)) = v88; /* mul!* */
    { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
/* error exit handlers */
v90:
    popv(8);
    return nil;
}



/* Code for calc_atlas */

static Lisp_Object CC_calc_atlas(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v105, v38, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_atlas");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v86 = v1;
    v105 = v0;
/* end of prologue */
    v38 = v105;
    v39 = qcar(v38);
    v38 = v105;
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcar(v38);
    v105 = qcdr(v105);
    v105 = qcar(v105);
    {
        fn = elt(env, 1); /* calc_map_2d */
        return (*qfnn(fn))(qenv(fn), 4, v39, v38, v105, v86);
    }
}



/* Code for gettype */

static Lisp_Object CC_gettype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v29;
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
    v31 = stack[0];
    if (is_number(v31)) goto v15;
    v31 = stack[0];
    if (!(!consp(v31))) goto v111;
    v31 = stack[0];
    if (v31 == nil) goto v111;
    v31 = stack[0];
    if (!(symbolp(v31))) goto v111;
    v29 = stack[0];
    v31 = elt(env, 3); /* simpfn */
    v31 = get(v29, v31);
    env = stack[-1];
    if (v31 == nil) goto v112;
    v31 = elt(env, 4); /* operator */
    { popv(2); return onevalue(v31); }

v112:
    v29 = stack[0];
    v31 = elt(env, 5); /* avalue */
    v31 = get(v29, v31);
    env = stack[-1];
    if (v31 == nil) goto v113;
    v29 = stack[0];
    v31 = elt(env, 5); /* avalue */
    v31 = get(v29, v31);
    v31 = qcar(v31);
    { popv(2); return onevalue(v31); }

v113:
    v31 = stack[0];
    fn = elt(env, 12); /* getd */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    if (v31 == nil) goto v114;
    v31 = elt(env, 6); /* procedure */
    { popv(2); return onevalue(v31); }

v114:
    v31 = stack[0];
    v31 = Lsymbol_globalp(nil, v31);
    env = stack[-1];
    if (v31 == nil) goto v46;
    v31 = elt(env, 7); /* global */
    { popv(2); return onevalue(v31); }

v46:
    v31 = stack[0];
    v31 = Lsymbol_specialp(nil, v31);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    if (v31 == nil) goto v115;
    v31 = elt(env, 8); /* fluid */
    { popv(2); return onevalue(v31); }

v115:
    v29 = stack[0];
    v31 = elt(env, 9); /* parm */
    v31 = Lflagp(nil, v29, v31);
    env = stack[-1];
    if (v31 == nil) goto v45;
    v31 = elt(env, 10); /* parameter */
    { popv(2); return onevalue(v31); }

v45:
    v31 = stack[0];
    v29 = elt(env, 11); /* rtype */
    popv(2);
    return get(v31, v29);

v111:
    v31 = elt(env, 2); /* form */
    { popv(2); return onevalue(v31); }

v15:
    v31 = elt(env, 1); /* number */
    { popv(2); return onevalue(v31); }
/* error exit handlers */
v30:
    popv(2);
    return nil;
}



/* Code for subs2chk */

static Lisp_Object CC_subs2chk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v38, v39;
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
    v105 = qvalue(elt(env, 1)); /* subfg!* */
    if (v105 == nil) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v105 = stack[0];
    fn = elt(env, 2); /* subs2f */
    v105 = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v118;
    v39 = v105;
    v38 = qcdr(v105);
    v105 = (Lisp_Object)17; /* 1 */
    if (!(v38 == v105)) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v105 = v39;
    v105 = qcar(v105);
    stack[0] = v105;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
/* error exit handlers */
v118:
    popv(1);
    return nil;
}



/* Code for xremf */

static Lisp_Object MS_CDECL CC_xremf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v60, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v167, v168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xremf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xremf");
#endif
    if (stack >= stacklimit)
    {
        push3(v60,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v60;
    stack[-6] = v1;
    stack[-7] = v0;
/* end of prologue */
    stack[-1] = nil;
    v166 = (Lisp_Object)1; /* 0 */
    stack[-8] = v166;
    v166 = stack[-6];
    if (!consp(v166)) goto v169;
    v166 = stack[-6];
    v166 = qcar(v166);
    if (!consp(v166)) goto v169;
    v166 = stack[-7];
    fn = elt(env, 2); /* termsf */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    stack[0] = v166;
    goto v171;

v171:
    v167 = stack[-5];
    v166 = (Lisp_Object)1; /* 0 */
    v166 = (Lisp_Object)lesseq2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    v166 = v166 ? lisp_true : nil;
    env = stack[-9];
    if (v166 == nil) goto v11;
    v166 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v166); }

v11:
    v166 = stack[-7];
    if (!consp(v166)) goto v172;
    v166 = stack[-7];
    v166 = qcar(v166);
    if (!consp(v166)) goto v172;
    v166 = stack[-7];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v167 = qcar(v166);
    v166 = stack[-6];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v166 = qcar(v166);
    if (v167 == v166) goto v49;
    v166 = stack[-7];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v167 = qcar(v166);
    v166 = stack[-6];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v166 = qcar(v166);
    fn = elt(env, 3); /* ordop */
    v166 = (*qfn2(fn))(qenv(fn), v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    if (v166 == nil) goto v173;
    v167 = stack[-5];
    v166 = stack[-8];
    v166 = plus2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    stack[-5] = v166;
    v166 = stack[-7];
    v166 = qcar(v166);
    v168 = qcdr(v166);
    v167 = stack[-6];
    v166 = stack[-5];
    v166 = CC_xremf(env, 3, v168, v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    stack[-3] = v166;
    v166 = stack[-3];
    if (v166 == nil) goto v174;
    v166 = stack[-7];
    v166 = qcar(v166);
    v167 = qcar(v166);
    v166 = (Lisp_Object)17; /* 1 */
    v166 = cons(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    v167 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    v166 = stack[-3];
    v166 = qcar(v166);
    fn = elt(env, 4); /* multf */
    v166 = (*qfn2(fn))(qenv(fn), v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    fn = elt(env, 5); /* addf */
    v166 = (*qfn2(fn))(qenv(fn), stack[-1], v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    stack[-1] = v166;
    v166 = stack[-1];
    fn = elt(env, 2); /* termsf */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    stack[-8] = v166;
    v167 = stack[-5];
    v166 = stack[-8];
    v166 = difference2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    stack[-5] = v166;
    v166 = stack[-7];
    v166 = qcdr(v166);
    stack[-7] = v166;
    goto v171;

v174:
    v166 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v166); }

v173:
    v167 = stack[-1];
    v166 = stack[-7];
    fn = elt(env, 5); /* addf */
    v166 = (*qfn2(fn))(qenv(fn), v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    popv(10);
    return ncons(v166);

v49:
    v166 = stack[-7];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v167 = qcdr(v166);
    v166 = stack[-6];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v166 = qcdr(v166);
    v167 = difference2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    stack[-4] = v167;
    v166 = (Lisp_Object)1; /* 0 */
    v166 = (Lisp_Object)lessp2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    v166 = v166 ? lisp_true : nil;
    env = stack[-9];
    if (v166 == nil) goto v58;
    v167 = stack[-1];
    v166 = stack[-7];
    fn = elt(env, 5); /* addf */
    v166 = (*qfn2(fn))(qenv(fn), v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    popv(10);
    return ncons(v166);

v58:
    v166 = stack[-7];
    v166 = qcar(v166);
    v167 = qcdr(v166);
    v166 = stack[-6];
    v166 = qcar(v166);
    v166 = qcdr(v166);
    fn = elt(env, 6); /* qremf */
    v166 = (*qfn2(fn))(qenv(fn), v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    stack[-3] = v166;
    v166 = stack[-7];
    v166 = qcar(v166);
    v167 = qcar(v166);
    v166 = (Lisp_Object)17; /* 1 */
    v166 = cons(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    v167 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    v166 = stack[-3];
    v166 = qcdr(v166);
    fn = elt(env, 4); /* multf */
    v166 = (*qfn2(fn))(qenv(fn), v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    stack[-2] = v166;
    v167 = stack[-5];
    v166 = stack[-8];
    v166 = plus2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    stack[-5] = v166;
    v167 = stack[-1];
    v166 = stack[-2];
    fn = elt(env, 5); /* addf */
    v166 = (*qfn2(fn))(qenv(fn), v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    stack[-1] = v166;
    v166 = stack[-1];
    fn = elt(env, 2); /* termsf */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    stack[-8] = v166;
    v167 = stack[-5];
    v166 = stack[-8];
    v167 = difference2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    v166 = stack[0];
    v166 = plus2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    stack[-5] = v166;
    v166 = stack[-3];
    v166 = qcar(v166);
    if (v166 == nil) goto v70;
    stack[0] = stack[-7];
    v167 = stack[-4];
    v166 = (Lisp_Object)1; /* 0 */
    if (v167 == v166) goto v65;
    v166 = stack[-7];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v168 = qcar(v166);
    v167 = stack[-4];
    v166 = (Lisp_Object)17; /* 1 */
    v166 = acons(v168, v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    v167 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    v166 = stack[-6];
    fn = elt(env, 4); /* multf */
    v166 = (*qfn2(fn))(qenv(fn), v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    stack[-4] = v166;
    goto v175;

v175:
    v166 = stack[-3];
    v166 = qcar(v166);
    fn = elt(env, 7); /* negf */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    fn = elt(env, 4); /* multf */
    v166 = (*qfn2(fn))(qenv(fn), stack[-4], v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    fn = elt(env, 5); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    v166 = stack[-2];
    fn = elt(env, 7); /* negf */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    fn = elt(env, 5); /* addf */
    v166 = (*qfn2(fn))(qenv(fn), stack[0], v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    goto v176;

v176:
    stack[-7] = v166;
    v166 = stack[-7];
    fn = elt(env, 2); /* termsf */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    stack[0] = v166;
    v167 = stack[-5];
    v166 = stack[0];
    v166 = difference2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-9];
    stack[-5] = v166;
    goto v171;

v65:
    v166 = stack[-6];
    stack[-4] = v166;
    goto v175;

v70:
    v166 = stack[-7];
    v166 = qcdr(v166);
    goto v176;

v172:
    v167 = stack[-1];
    v166 = stack[-7];
    fn = elt(env, 5); /* addf */
    v166 = (*qfn2(fn))(qenv(fn), v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    popv(10);
    return ncons(v166);

v169:
    v167 = stack[-7];
    v166 = stack[-6];
    fn = elt(env, 8); /* qremd */
    v166 = (*qfn2(fn))(qenv(fn), v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v170;
    v166 = qcdr(v166);
    popv(10);
    return ncons(v166);
/* error exit handlers */
v170:
    popv(10);
    return nil;
}



/* Code for maxfrom1 */

static Lisp_Object MS_CDECL CC_maxfrom1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v60, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "maxfrom1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxfrom1");
#endif
    if (stack >= stacklimit)
    {
        push3(v60,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v60;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v148:
    v37 = stack[-2];
    if (v37 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v37 = stack[-2];
    v37 = qcar(v37);
    v36 = qcar(v37);
    v37 = stack[-1];
    fn = elt(env, 1); /* pnth */
    v37 = (*qfn2(fn))(qenv(fn), v36, v37);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-3];
    v36 = qcar(v37);
    v37 = stack[0];
    fn = elt(env, 2); /* max */
    v37 = (*qfn2(fn))(qenv(fn), v36, v37);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-3];
    stack[0] = v37;
    v37 = stack[-2];
    v37 = qcdr(v37);
    stack[-2] = v37;
    goto v148;
/* error exit handlers */
v11:
    popv(4);
    return nil;
}



/* Code for cancel */

static Lisp_Object CC_cancel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cancel");
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
    v45 = qvalue(elt(env, 1)); /* !*mcd */
    if (!(v45 == nil)) goto v105;
    v45 = stack[0];
    v99 = qcdr(v45);
    v45 = (Lisp_Object)17; /* 1 */
    if (v99 == v45) goto v105;
    v45 = stack[0];
    v99 = qcar(v45);
    v45 = (Lisp_Object)17; /* 1 */
    stack[-1] = cons(v99, v45);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-2];
    v45 = stack[0];
    v99 = qcdr(v45);
    v45 = (Lisp_Object)17; /* 1 */
    v45 = cons(v99, v45);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-2];
    fn = elt(env, 2); /* mk!*sq */
    v99 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-2];
    v45 = (Lisp_Object)-15; /* -1 */
    v45 = list2(v99, v45);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-2];
    fn = elt(env, 3); /* simpexpt */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-2];
    {
        Lisp_Object v107 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* multsq */
        return (*qfn2(fn))(qenv(fn), v107, v45);
    }

v105:
    v45 = stack[0];
    v99 = qcar(v45);
    v45 = (Lisp_Object)17; /* 1 */
    stack[-1] = cons(v99, v45);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-2];
    v99 = (Lisp_Object)17; /* 1 */
    v45 = stack[0];
    v45 = qcdr(v45);
    v45 = cons(v99, v45);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-2];
    {
        Lisp_Object v106 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* multsq */
        return (*qfn2(fn))(qenv(fn), v106, v45);
    }
/* error exit handlers */
v162:
    popv(3);
    return nil;
}



/* Code for mk!+scal!+mult!+mat */

static Lisp_Object CC_mkLscalLmultLmat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v194;
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
    v6 = stack[0];
    fn = elt(env, 6); /* matrix!+p */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-10];
    if (!(v6 == nil)) goto v92;
    v6 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v6 == nil)) goto v103;
    v6 = elt(env, 2); /* "no matrix in add" */
    fn = elt(env, 7); /* lprie */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-10];
    goto v103;

v103:
    v6 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-10];
    goto v92;

v92:
    v6 = stack[0];
    stack[-9] = v6;
    v6 = stack[-9];
    if (v6 == nil) goto v84;
    v6 = stack[-9];
    v6 = qcar(v6);
    stack[-4] = v6;
    v6 = stack[-4];
    if (v6 == nil) goto v195;
    v6 = stack[-4];
    v6 = qcar(v6);
    v194 = stack[-8];
    fn = elt(env, 8); /* multsq */
    v6 = (*qfn2(fn))(qenv(fn), v194, v6);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-10];
    v194 = v6;
    v6 = qvalue(elt(env, 4)); /* t */
    stack[0] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v6; /* !*sub2 */
    v6 = v194;
    fn = elt(env, 9); /* subs2 */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-10];
    v194 = v6;
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    v6 = v194;
    v6 = ncons(v6);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-10];
    stack[-2] = v6;
    stack[-3] = v6;
    goto v163;

v163:
    v6 = stack[-4];
    v6 = qcdr(v6);
    stack[-4] = v6;
    v6 = stack[-4];
    if (v6 == nil) goto v45;
    stack[-1] = stack[-2];
    v6 = stack[-4];
    v6 = qcar(v6);
    v194 = stack[-8];
    fn = elt(env, 8); /* multsq */
    v6 = (*qfn2(fn))(qenv(fn), v194, v6);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-10];
    v194 = v6;
    v6 = qvalue(elt(env, 4)); /* t */
    stack[0] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v6; /* !*sub2 */
    v6 = v194;
    fn = elt(env, 9); /* subs2 */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-10];
    v194 = v6;
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    v6 = v194;
    v6 = ncons(v6);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-10];
    v6 = Lrplacd(nil, stack[-1], v6);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-10];
    v6 = stack[-2];
    v6 = qcdr(v6);
    stack[-2] = v6;
    goto v163;

v45:
    v6 = stack[-3];
    goto v198;

v198:
    v6 = ncons(v6);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-10];
    stack[-6] = v6;
    stack[-7] = v6;
    goto v177;

v177:
    v6 = stack[-9];
    v6 = qcdr(v6);
    stack[-9] = v6;
    v6 = stack[-9];
    if (v6 == nil) { Lisp_Object res = stack[-7]; popv(11); return onevalue(res); }
    stack[-5] = stack[-6];
    v6 = stack[-9];
    v6 = qcar(v6);
    stack[-4] = v6;
    v6 = stack[-4];
    if (v6 == nil) goto v199;
    v6 = stack[-4];
    v6 = qcar(v6);
    v194 = stack[-8];
    fn = elt(env, 8); /* multsq */
    v6 = (*qfn2(fn))(qenv(fn), v194, v6);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-10];
    v194 = v6;
    v6 = qvalue(elt(env, 4)); /* t */
    stack[0] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v6; /* !*sub2 */
    v6 = v194;
    fn = elt(env, 9); /* subs2 */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-10];
    v194 = v6;
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    v6 = v194;
    v6 = ncons(v6);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-10];
    stack[-2] = v6;
    stack[-3] = v6;
    goto v200;

v200:
    v6 = stack[-4];
    v6 = qcdr(v6);
    stack[-4] = v6;
    v6 = stack[-4];
    if (v6 == nil) goto v201;
    stack[-1] = stack[-2];
    v6 = stack[-4];
    v6 = qcar(v6);
    v194 = stack[-8];
    fn = elt(env, 8); /* multsq */
    v6 = (*qfn2(fn))(qenv(fn), v194, v6);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-10];
    v194 = v6;
    v6 = qvalue(elt(env, 4)); /* t */
    stack[0] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v6; /* !*sub2 */
    v6 = v194;
    fn = elt(env, 9); /* subs2 */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-10];
    v194 = v6;
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    v6 = v194;
    v6 = ncons(v6);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-10];
    v6 = Lrplacd(nil, stack[-1], v6);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-10];
    v6 = stack[-2];
    v6 = qcdr(v6);
    stack[-2] = v6;
    goto v200;

v201:
    v6 = stack[-3];
    goto v203;

v203:
    v6 = ncons(v6);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-10];
    v6 = Lrplacd(nil, stack[-5], v6);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-10];
    v6 = stack[-6];
    v6 = qcdr(v6);
    stack[-6] = v6;
    goto v177;

v199:
    v6 = qvalue(elt(env, 3)); /* nil */
    goto v203;

v195:
    v6 = qvalue(elt(env, 3)); /* nil */
    goto v198;

v84:
    v6 = qvalue(elt(env, 3)); /* nil */
    { popv(11); return onevalue(v6); }
/* error exit handlers */
v202:
    env = stack[-10];
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    popv(11);
    return nil;
v175:
    env = stack[-10];
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    popv(11);
    return nil;
v197:
    env = stack[-10];
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    popv(11);
    return nil;
v196:
    env = stack[-10];
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    popv(11);
    return nil;
v142:
    popv(11);
    return nil;
}



/* Code for mksp!* */

static Lisp_Object CC_mkspH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204, v205;
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
    v204 = stack[-1];
    if (v204 == nil) goto v181;
    v204 = stack[-1];
    fn = elt(env, 2); /* kernlp */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-3];
    if (!(v204 == nil)) goto v181;
    v204 = stack[-1];
    fn = elt(env, 3); /* minusf */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-3];
    if (v204 == nil) goto v180;
    v204 = qvalue(elt(env, 1)); /* t */
    stack[-2] = v204;
    v204 = stack[-1];
    fn = elt(env, 4); /* negf */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-3];
    stack[-1] = v204;
    goto v180;

v180:
    v204 = stack[-1];
    fn = elt(env, 5); /* fkern */
    v205 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-3];
    v204 = stack[0];
    fn = elt(env, 6); /* getpower */
    v205 = (*qfn2(fn))(qenv(fn), v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-3];
    v204 = (Lisp_Object)17; /* 1 */
    v204 = cons(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-3];
    v204 = ncons(v204);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-3];
    stack[-1] = v204;
    v204 = stack[-2];
    if (v204 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v204 = stack[0];
    v204 = Levenp(nil, v204);
    env = stack[-3];
    if (!(v204 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v204 = stack[-1];
    {
        popv(4);
        fn = elt(env, 4); /* negf */
        return (*qfn1(fn))(qenv(fn), v204);
    }

v181:
    v205 = stack[-1];
    v204 = stack[0];
    {
        popv(4);
        fn = elt(env, 7); /* exptf */
        return (*qfn2(fn))(qenv(fn), v205, v204);
    }
/* error exit handlers */
v193:
    popv(4);
    return nil;
}



/* Code for pasf_dt */

static Lisp_Object CC_pasf_dt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v227, v130, v128, v129;
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
    v130 = stack[0];
    v227 = elt(env, 1); /* true */
    if (v130 == v227) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v130 = stack[0];
    v227 = elt(env, 2); /* false */
    if (v130 == v227) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v227 = stack[0];
    v227 = qcdr(v227);
    v227 = qcar(v227);
    fn = elt(env, 17); /* pasf_pdp */
    v227 = (*qfn1(fn))(qenv(fn), v227);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-1];
    v129 = v227;
    v130 = stack[0];
    v227 = elt(env, 1); /* true */
    if (v130 == v227) goto v165;
    v130 = stack[0];
    v227 = elt(env, 2); /* false */
    if (v130 == v227) goto v165;
    v227 = stack[0];
    v227 = qcar(v227);
    v227 = Lconsp(nil, v227);
    env = stack[-1];
    if (v227 == nil) goto v229;
    v227 = stack[0];
    v227 = qcar(v227);
    v227 = qcar(v227);
    goto v164;

v164:
    v128 = v227;
    v130 = v129;
    v227 = elt(env, 3); /* pdef */
    if (!(v130 == v227)) goto v160;
    v130 = v128;
    v227 = elt(env, 4); /* (equal lessp leq) */
    v227 = Lmemq(nil, v130, v227);
    if (v227 == nil) goto v160;
    v227 = elt(env, 2); /* false */
    { popv(2); return onevalue(v227); }

v160:
    v130 = v129;
    v227 = elt(env, 5); /* ndef */
    if (!(v130 == v227)) goto v97;
    v130 = v128;
    v227 = elt(env, 6); /* (equal greaterp geq) */
    v227 = Lmemq(nil, v130, v227);
    if (v227 == nil) goto v97;
    v227 = elt(env, 2); /* false */
    { popv(2); return onevalue(v227); }

v97:
    v130 = v129;
    v227 = elt(env, 3); /* pdef */
    if (!(v130 == v227)) goto v25;
    v130 = v128;
    v227 = elt(env, 7); /* (neq greaterp geq) */
    v227 = Lmemq(nil, v130, v227);
    if (v227 == nil) goto v25;
    v227 = elt(env, 1); /* true */
    { popv(2); return onevalue(v227); }

v25:
    v130 = v129;
    v227 = elt(env, 5); /* ndef */
    if (!(v130 == v227)) goto v230;
    v130 = v128;
    v227 = elt(env, 8); /* (neq lessp leq) */
    v227 = Lmemq(nil, v130, v227);
    if (v227 == nil) goto v230;
    v227 = elt(env, 1); /* true */
    { popv(2); return onevalue(v227); }

v230:
    v130 = v129;
    v227 = elt(env, 9); /* psdef */
    if (!(v130 == v227)) goto v152;
    v130 = v128;
    v227 = elt(env, 10); /* lessp */
    if (!(v130 == v227)) goto v152;
    v227 = elt(env, 2); /* false */
    { popv(2); return onevalue(v227); }

v152:
    v130 = v129;
    v227 = elt(env, 11); /* nsdef */
    if (!(v130 == v227)) goto v231;
    v130 = v128;
    v227 = elt(env, 12); /* greaterp */
    if (!(v130 == v227)) goto v231;
    v227 = elt(env, 2); /* false */
    { popv(2); return onevalue(v227); }

v231:
    v130 = v129;
    v227 = elt(env, 9); /* psdef */
    if (!(v130 == v227)) goto v150;
    v130 = v128;
    v227 = elt(env, 13); /* geq */
    if (!(v130 == v227)) goto v150;
    v227 = elt(env, 1); /* true */
    { popv(2); return onevalue(v227); }

v150:
    v130 = v129;
    v227 = elt(env, 11); /* nsdef */
    if (!(v130 == v227)) goto v44;
    v130 = v128;
    v227 = elt(env, 14); /* leq */
    if (!(v130 == v227)) goto v44;
    v227 = elt(env, 1); /* true */
    { popv(2); return onevalue(v227); }

v44:
    v130 = v129;
    v227 = elt(env, 9); /* psdef */
    if (!(v130 == v227)) goto v232;
    v130 = v128;
    v227 = elt(env, 15); /* neq */
    if (!(v130 == v227)) goto v232;
    v130 = elt(env, 12); /* greaterp */
    v227 = stack[0];
    v227 = qcdr(v227);
    v227 = qcar(v227);
    v128 = qvalue(elt(env, 16)); /* nil */
    popv(2);
    return list3(v130, v227, v128);

v232:
    v130 = v129;
    v227 = elt(env, 11); /* nsdef */
    if (!(v130 == v227)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v130 = v128;
    v227 = elt(env, 15); /* neq */
    if (!(v130 == v227)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v130 = elt(env, 10); /* lessp */
    v227 = stack[0];
    v227 = qcdr(v227);
    v227 = qcar(v227);
    v128 = qvalue(elt(env, 16)); /* nil */
    popv(2);
    return list3(v130, v227, v128);

v229:
    v227 = stack[0];
    v227 = qcar(v227);
    goto v164;

v165:
    v227 = stack[0];
    goto v164;
/* error exit handlers */
v228:
    popv(2);
    return nil;
}



/* Code for dvfsf_smupdknowl */

static Lisp_Object MS_CDECL CC_dvfsf_smupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v60, Lisp_Object v69, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v225, v171, v192, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "dvfsf_smupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_smupdknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v225 = v69;
    v171 = v60;
    v192 = v1;
    v43 = v0;
/* end of prologue */
    v11 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v11 == nil) goto v169;
    v11 = v43;
    {
        fn = elt(env, 2); /* cl_susiupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v11, v192, v171, v225);
    }

v169:
    v11 = v43;
    {
        fn = elt(env, 3); /* cl_smupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v11, v192, v171, v225);
    }
}



/* Code for relnrd */

static Lisp_Object MS_CDECL CC_relnrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204, v205;
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
    v204 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    v204 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 6); /* compress!* */
    v205 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    v204 = qvalue(elt(env, 2)); /* rdreln!* */
    v205 = Lassoc(nil, v205, v204);
    v204 = v205;
    if (v205 == nil) goto v84;
    v205 = v204;
    v205 = qcdr(v205);
    v205 = qcar(v205);
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    fn = elt(env, 7); /* apply */
    v204 = (*qfn2(fn))(qenv(fn), v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    stack[0] = v204;
    goto v198;

v198:
    v205 = stack[0];
    v204 = qvalue(elt(env, 3)); /* t */
    if (equal(v205, v204)) goto v43;
    v204 = stack[0];
    if (!(v204 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v204 = elt(env, 4); /* false */
    { popv(2); return onevalue(v204); }

v43:
    v204 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v204); }

v84:
    v204 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 6); /* compress!* */
    v205 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    v204 = (Lisp_Object)289; /* 18 */
    fn = elt(env, 8); /* errorml */
    v204 = (*qfn2(fn))(qenv(fn), v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    goto v198;
/* error exit handlers */
v33:
    popv(2);
    return nil;
}



/* Code for dm!-min */

static Lisp_Object CC_dmKmin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v117;
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
    v117 = stack[-1];
    v116 = stack[0];
    fn = elt(env, 1); /* dm!-gt */
    v116 = (*qfn2(fn))(qenv(fn), v117, v116);
    nil = C_nil;
    if (exception_pending()) goto v86;
    if (v116 == nil) { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v86:
    popv(2);
    return nil;
}



/* Code for oldmtch */

static Lisp_Object CC_oldmtch(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v83, v28;
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
    v179 = stack[-2];
    v28 = qcdr(v179);
    v179 = stack[-1];
    v83 = qcar(v179);
    v179 = stack[-2];
    v179 = qcar(v179);
    fn = elt(env, 2); /* mcharg */
    v179 = (*qfnn(fn))(qenv(fn), 3, v28, v83, v179);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    stack[0] = v179;
    goto v86;

v86:
    v179 = stack[0];
    if (v179 == nil) goto v85;
    v179 = stack[-3];
    if (!(v179 == nil)) goto v85;
    v179 = stack[0];
    v83 = qcar(v179);
    v179 = stack[-1];
    v179 = qcdr(v179);
    v179 = qcar(v179);
    v179 = qcdr(v179);
    v179 = Lsubla(nil, v83, v179);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    fn = elt(env, 3); /* eval */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    if (v179 == nil) goto v36;
    v179 = stack[0];
    v83 = qcar(v179);
    v179 = stack[-1];
    v179 = qcdr(v179);
    v179 = qcdr(v179);
    v179 = qcar(v179);
    v179 = Lsubla(nil, v83, v179);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    goto v84;

v84:
    stack[-3] = v179;
    v179 = stack[0];
    v179 = qcdr(v179);
    stack[0] = v179;
    goto v86;

v36:
    v179 = nil;
    goto v84;

v85:
    v179 = stack[-3];
    if (v179 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    else { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v162:
    popv(5);
    return nil;
}



/* Code for gvar1 */

static Lisp_Object CC_gvar1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v223, v57, v183;
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
    v223 = v1;
    v57 = v0;
/* end of prologue */

v75:
    v58 = v57;
    if (v58 == nil) { popv(1); return onevalue(v223); }
    v58 = v57;
    if (is_number(v58)) { popv(1); return onevalue(v223); }
    v183 = v57;
    v58 = elt(env, 1); /* i */
    if (!(v183 == v58)) goto v127;
    v58 = qvalue(elt(env, 2)); /* !*complex */
    if (!(v58 == nil)) { popv(1); return onevalue(v223); }

v127:
    v58 = v57;
    if (!consp(v58)) goto v165;
    v58 = v57;
    v183 = qcar(v58);
    v58 = elt(env, 3); /* dname */
    v58 = get(v183, v58);
    env = stack[0];
    if (!(v58 == nil)) { popv(1); return onevalue(v223); }
    v58 = v57;
    v183 = qcar(v58);
    v58 = elt(env, 4); /* (plus times expt difference minus) */
    v58 = Lmemq(nil, v183, v58);
    if (v58 == nil) goto v30;
    v58 = v57;
    v58 = qcdr(v58);
    {
        popv(1);
        fn = elt(env, 6); /* gvarlis1 */
        return (*qfn2(fn))(qenv(fn), v58, v223);
    }

v30:
    v58 = v57;
    v183 = qcar(v58);
    v58 = elt(env, 5); /* quotient */
    if (v183 == v58) goto v29;
    v183 = v57;
    v58 = v223;
    v58 = Lmember(nil, v183, v58);
    if (!(v58 == nil)) { popv(1); return onevalue(v223); }
    v58 = v57;
    popv(1);
    return cons(v58, v223);

v29:
    v58 = v57;
    v58 = qcdr(v58);
    v58 = qcar(v58);
    v57 = v58;
    goto v75;

v165:
    v183 = v57;
    v58 = v223;
    v58 = Lmember(nil, v183, v58);
    if (!(v58 == nil)) { popv(1); return onevalue(v223); }
    v58 = v57;
    popv(1);
    return cons(v58, v223);
}



/* Code for incident */

static Lisp_Object MS_CDECL CC_incident(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v60, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v235, v236, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "incident");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for incident");
#endif
    if (stack >= stacklimit)
    {
        push3(v60,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v60;
    stack[0] = v1;
    stack[-2] = v0;
/* end of prologue */

v237:
    v235 = stack[0];
    if (v235 == nil) goto v148;
    v95 = stack[-2];
    v235 = stack[0];
    v236 = qcar(v235);
    v235 = stack[-1];
    fn = elt(env, 2); /* incident1 */
    v235 = (*qfnn(fn))(qenv(fn), 3, v95, v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-3];
    v236 = v235;
    v235 = v236;
    if (v235 == nil) goto v43;
    v235 = stack[0];
    v235 = qcdr(v235);
    popv(4);
    return cons(v236, v235);

v43:
    v235 = stack[0];
    stack[0] = qcdr(v235);
    v235 = stack[-1];
    v235 = add1(v235);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-3];
    stack[-1] = v235;
    goto v237;

v148:
    v235 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v235); }
/* error exit handlers */
v229:
    popv(4);
    return nil;
}



/* Code for formsetq0 */

static Lisp_Object MS_CDECL CC_formsetq0(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v60, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v292, v293, v294, v295;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formsetq0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formsetq0");
#endif
    if (stack >= stacklimit)
    {
        push3(v60,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v60;
    stack[-4] = v1;
    stack[0] = v0;
/* end of prologue */
    stack[-1] = nil;
    v292 = stack[0];
    v292 = qcdr(v292);
    stack[0] = v292;
    v292 = qcar(v292);
    stack[-2] = v292;
    if (!(symbolp(v292))) goto v113;
    v293 = stack[-2];
    v292 = stack[-4];
    v292 = Latsoc(nil, v293, v292);
    stack[-1] = v292;
    goto v113;

v113:
    v292 = stack[0];
    v292 = qcdr(v292);
    v293 = qcar(v292);
    v292 = elt(env, 1); /* quote */
    if (!consp(v293)) goto v35;
    v293 = qcar(v293);
    if (!(v293 == v292)) goto v35;
    v292 = elt(env, 2); /* symbolic */
    stack[-3] = v292;
    goto v35;

v35:
    v292 = stack[0];
    v292 = qcdr(v292);
    v294 = qcar(v292);
    v293 = stack[-4];
    v292 = stack[-3];
    fn = elt(env, 27); /* form1 */
    v295 = (*qfnn(fn))(qenv(fn), 3, v294, v293, v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-6];
    v294 = stack[-4];
    v293 = elt(env, 2); /* symbolic */
    v292 = stack[-3];
    fn = elt(env, 28); /* convertmode1 */
    v292 = (*qfnn(fn))(qenv(fn), 4, v295, v294, v293, v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-6];
    stack[-5] = v292;
    v292 = stack[-2];
    if (!consp(v292)) goto v297;
    v292 = stack[-2];
    v292 = qcar(v292);
    if (symbolp(v292)) goto v26;
    v293 = stack[-2];
    v292 = elt(env, 3); /* "assignment" */
    {
        popv(7);
        fn = elt(env, 29); /* typerr */
        return (*qfn2(fn))(qenv(fn), v293, v292);
    }

v26:
    v293 = stack[-2];
    v292 = stack[-3];
    fn = elt(env, 30); /* macrochk */
    v292 = (*qfn2(fn))(qenv(fn), v293, v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-6];
    stack[-2] = v292;
    if (!consp(v292)) goto v298;
    v292 = stack[-2];
    v293 = qcar(v292);
    v292 = elt(env, 4); /* rtype */
    v293 = get(v293, v292);
    env = stack[-6];
    v292 = elt(env, 5); /* array */
    if (!(v293 == v292)) goto v298;
    stack[0] = elt(env, 6); /* setel */
    v294 = stack[-2];
    v293 = stack[-4];
    v292 = stack[-3];
    fn = elt(env, 31); /* intargfn */
    v293 = (*qfnn(fn))(qenv(fn), 3, v294, v293, v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    v292 = stack[-5];
    {
        Lisp_Object v299 = stack[0];
        popv(7);
        return list3(v299, v293, v292);
    }

v298:
    v292 = stack[-2];
    if (!consp(v292)) goto v300;
    v292 = stack[-2];
    v292 = qcdr(v292);
    if (v292 == nil) goto v300;
    v292 = stack[-2];
    v293 = qcar(v292);
    v292 = elt(env, 4); /* rtype */
    v293 = get(v293, v292);
    env = stack[-6];
    v292 = elt(env, 7); /* vector */
    if (v293 == v292) goto v20;
    v292 = stack[-2];
    v292 = qcdr(v292);
    v292 = qcar(v292);
    v292 = Lsimple_vectorp(nil, v292);
    env = stack[-6];
    if (!(v292 == nil)) goto v20;
    v292 = stack[-2];
    v292 = qcdr(v292);
    v293 = qcar(v292);
    v292 = elt(env, 8); /* vecfn */
    v292 = Lflagpcar(nil, v293, v292);
    env = stack[-6];
    if (!(v292 == nil)) goto v20;

v300:
    v293 = stack[-2];
    v292 = elt(env, 9); /* part */
    if (!consp(v293)) goto v221;
    v293 = qcar(v293);
    if (!(v293 == v292)) goto v221;
    stack[-1] = elt(env, 10); /* list */
    v292 = elt(env, 11); /* setpart!* */
    stack[0] = Lmkquote(nil, v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-6];
    v292 = stack[-2];
    v294 = qcdr(v292);
    v293 = stack[-4];
    v292 = stack[-3];
    fn = elt(env, 32); /* formlis */
    v292 = (*qfnn(fn))(qenv(fn), 3, v294, v293, v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-6];
    stack[0] = list2star(stack[-1], stack[0], v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-6];
    v292 = stack[-5];
    v292 = ncons(v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    {
        Lisp_Object v301 = stack[0];
        popv(7);
        return Lnconc(nil, v301, v292);
    }

v221:
    v292 = stack[-2];
    if (!consp(v292)) goto v302;
    v292 = stack[-2];
    v293 = qcar(v292);
    v292 = elt(env, 12); /* setqfn */
    v292 = get(v293, v292);
    env = stack[-6];
    stack[-1] = v292;
    if (v292 == nil) goto v302;
    v292 = stack[-2];
    v293 = qcdr(v292);
    v292 = stack[0];
    v292 = qcdr(v292);
    v293 = Lappend(nil, v293, v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-6];
    v292 = qvalue(elt(env, 13)); /* nil */
    fn = elt(env, 33); /* applsmacro */
    v294 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v293, v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-6];
    v293 = stack[-4];
    v292 = stack[-3];
    {
        popv(7);
        fn = elt(env, 27); /* form1 */
        return (*qfnn(fn))(qenv(fn), 3, v294, v293, v292);
    }

v302:
    v293 = stack[-3];
    v292 = elt(env, 2); /* symbolic */
    if (!(v293 == v292)) goto v303;
    v292 = qvalue(elt(env, 14)); /* !*rlisp88 */
    if (!(v292 == nil)) goto v304;
    v293 = stack[-2];
    v292 = elt(env, 15); /* structfetch */
    if (!consp(v293)) goto v303;
    v293 = qcar(v293);
    if (!(v293 == v292)) goto v303;

v304:
    stack[0] = elt(env, 16); /* rsetf */
    v294 = stack[-2];
    v293 = stack[-4];
    v292 = stack[-3];
    fn = elt(env, 27); /* form1 */
    v293 = (*qfnn(fn))(qenv(fn), 3, v294, v293, v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    v292 = stack[-5];
    {
        Lisp_Object v305 = stack[0];
        popv(7);
        return list3(v305, v293, v292);
    }

v303:
    stack[0] = elt(env, 17); /* setk */
    v294 = stack[-2];
    v293 = stack[-4];
    v292 = elt(env, 18); /* algebraic */
    fn = elt(env, 27); /* form1 */
    v293 = (*qfnn(fn))(qenv(fn), 3, v294, v293, v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    v292 = stack[-5];
    {
        Lisp_Object v306 = stack[0];
        popv(7);
        return list3(v306, v293, v292);
    }

v20:
    v294 = stack[0];
    v293 = stack[-4];
    v292 = stack[-3];
    {
        popv(7);
        fn = elt(env, 34); /* putvect */
        return (*qfnn(fn))(qenv(fn), 3, v294, v293, v292);
    }

v297:
    v292 = stack[-2];
    if (symbolp(v292)) goto v307;
    v293 = stack[-2];
    v292 = elt(env, 3); /* "assignment" */
    {
        popv(7);
        fn = elt(env, 29); /* typerr */
        return (*qfn2(fn))(qenv(fn), v293, v292);
    }

v307:
    v293 = stack[-2];
    v292 = elt(env, 19); /* reserved */
    v292 = Lflagp(nil, v293, v292);
    env = stack[-6];
    if (v292 == nil) goto v308;
    v293 = stack[-2];
    v292 = stack[-4];
    v292 = Latsoc(nil, v293, v292);
    if (!(v292 == nil)) goto v308;
    v293 = stack[-2];
    v292 = elt(env, 20); /* "is a reserved identifier" */
    v292 = list2(v293, v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-6];
    v293 = v292;
    v292 = v293;
    qvalue(elt(env, 21)) = v292; /* errmsg!* */
    v292 = qvalue(elt(env, 22)); /* !*protfg */
    if (!(v292 == nil)) goto v309;
    v292 = v293;
    fn = elt(env, 35); /* lprie */
    v292 = (*qfn1(fn))(qenv(fn), v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-6];
    goto v309;

v309:
    v292 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v296;
    v292 = nil;
    { popv(7); return onevalue(v292); }

v308:
    v293 = stack[-2];
    v292 = elt(env, 23); /* share */
    v292 = Lflagp(nil, v293, v292);
    env = stack[-6];
    if (v292 == nil) goto v310;
    v293 = stack[-2];
    v292 = stack[-4];
    fn = elt(env, 36); /* symbid */
    stack[0] = (*qfn2(fn))(qenv(fn), v293, v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-6];
    v294 = elt(env, 24); /* progn */
    v293 = elt(env, 25); /* (setq alglist!* (cons nil nil)) */
    v292 = stack[-5];
    v292 = list3(v294, v293, v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-6];
    {
        Lisp_Object v311 = stack[0];
        popv(7);
        fn = elt(env, 37); /* mksetq */
        return (*qfn2(fn))(qenv(fn), v311, v292);
    }

v310:
    v293 = stack[-3];
    v292 = elt(env, 2); /* symbolic */
    if (v293 == v292) goto v312;
    v292 = stack[-1];
    if (!(v292 == nil)) goto v312;
    v293 = stack[-5];
    v292 = elt(env, 1); /* quote */
    if (!consp(v293)) goto v313;
    v293 = qcar(v293);
    if (!(v293 == v292)) goto v313;

v312:
    v293 = stack[-2];
    v292 = stack[-4];
    fn = elt(env, 36); /* symbid */
    v293 = (*qfn2(fn))(qenv(fn), v293, v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-6];
    v292 = stack[-5];
    {
        popv(7);
        fn = elt(env, 37); /* mksetq */
        return (*qfn2(fn))(qenv(fn), v293, v292);
    }

v313:
    v292 = stack[0];
    v292 = qcdr(v292);
    v292 = qcar(v292);
    v292 = Lsimple_vectorp(nil, v292);
    env = stack[-6];
    if (!(v292 == nil)) goto v314;
    v292 = stack[0];
    v292 = qcdr(v292);
    v293 = qcar(v292);
    v292 = elt(env, 8); /* vecfn */
    v292 = Lflagpcar(nil, v293, v292);
    env = stack[-6];
    if (!(v292 == nil)) goto v314;
    stack[0] = elt(env, 17); /* setk */
    v292 = stack[-2];
    v293 = Lmkquote(nil, v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    v292 = stack[-5];
    {
        Lisp_Object v315 = stack[0];
        popv(7);
        return list3(v315, v293, v292);
    }

v314:
    stack[-1] = elt(env, 26); /* setv */
    v292 = stack[-2];
    v293 = Lmkquote(nil, v292);
    nil = C_nil;
    if (exception_pending()) goto v296;
    v292 = stack[0];
    v292 = qcdr(v292);
    v292 = qcar(v292);
    {
        Lisp_Object v316 = stack[-1];
        popv(7);
        return list3(v316, v293, v292);
    }
/* error exit handlers */
v296:
    popv(7);
    return nil;
}



/* Code for red_topred */

static Lisp_Object CC_red_topred(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v317, v162;
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
    v317 = stack[0];
    fn = elt(env, 3); /* bas_dpoly */
    v317 = (*qfn1(fn))(qenv(fn), v317);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-3];
    if (v317 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v317 = stack[-1];
    if (v317 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v162 = stack[-1];
    v317 = stack[0];
    fn = elt(env, 4); /* red_topredbe */
    v317 = (*qfn2(fn))(qenv(fn), v162, v317);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-3];
    stack[0] = v317;
    goto v113;

v113:
    v317 = stack[0];
    fn = elt(env, 3); /* bas_dpoly */
    v317 = (*qfn1(fn))(qenv(fn), v317);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-3];
    v162 = v317;
    if (v317 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    stack[-2] = stack[-1];
    v317 = v162;
    fn = elt(env, 5); /* dp_lmon */
    v317 = (*qfn1(fn))(qenv(fn), v317);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-3];
    fn = elt(env, 6); /* red_divtest */
    v317 = (*qfn2(fn))(qenv(fn), stack[-2], v317);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-3];
    stack[-2] = v317;
    if (v317 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v162 = stack[0];
    v317 = stack[-2];
    fn = elt(env, 7); /* red_subst */
    v317 = (*qfn2(fn))(qenv(fn), v162, v317);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-3];
    stack[-2] = v317;
    v317 = qvalue(elt(env, 2)); /* !*noetherian */
    if (!(v317 == nil)) goto v108;
    v162 = stack[-1];
    v317 = stack[0];
    fn = elt(env, 8); /* red_update */
    v317 = (*qfn2(fn))(qenv(fn), v162, v317);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-3];
    stack[-1] = v317;
    goto v108;

v108:
    v162 = stack[-1];
    v317 = stack[-2];
    fn = elt(env, 4); /* red_topredbe */
    v317 = (*qfn2(fn))(qenv(fn), v162, v317);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-3];
    stack[0] = v317;
    goto v113;
/* error exit handlers */
v29:
    popv(4);
    return nil;
}



/* Code for atom_compare */

static Lisp_Object CC_atom_compare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v225, v171;
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
    v225 = v1;
    v171 = v0;
/* end of prologue */
    v11 = v171;
    if (is_number(v11)) goto v75;
    v11 = v225;
    if (symbolp(v11)) goto v113;
    v11 = v225;
    v11 = (is_number(v11) ? lisp_true : nil);
    return onevalue(v11);

v113:
    v11 = v171;
        return Lorderp(nil, v11, v225);

v75:
    v11 = v225;
    if (is_number(v11)) goto v226;
    v11 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v11);

v226:
    v11 = v171;
    v11 = (Lisp_Object)lessp2(v11, v225);
    errexit();
    v11 = v11 ? lisp_true : nil;
    v11 = (v11 == nil ? lisp_true : nil);
    return onevalue(v11);
}



/* Code for quotfail!-in!-vector */

static Lisp_Object MS_CDECL CC_quotfailKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v60, Lisp_Object v69, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v282, v335, v173, v211, v336, v337, v338, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "quotfail-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfail-in-vector");
#endif
    if (stack >= stacklimit)
    {
        push4(v69,v60,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v60,v69);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v69;
    stack[-2] = v60;
    v173 = v1;
    stack[-3] = v0;
/* end of prologue */
    v335 = v173;
    v282 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v335)) < ((int32_t)(v282))) { popv(6); return onevalue(v173); }
    v335 = stack[-1];
    v282 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v335)) < ((int32_t)(v282))) goto v226;
    v335 = v173;
    v282 = stack[-1];
    if (((int32_t)(v335)) < ((int32_t)(v282))) goto v118;
    v335 = v173;
    v282 = stack[-1];
    v282 = (Lisp_Object)(int32_t)((int32_t)v335 - (int32_t)v282 + TAG_FIXNUM);
    stack[-4] = v282;
    v282 = stack[-4];
    stack[0] = v282;
    goto v236;

v236:
    v282 = stack[0];
    v282 = ((intptr_t)(v282) < 0 ? lisp_true : nil);
    if (v282 == nil) goto v179;
    v282 = (Lisp_Object)1; /* 0 */
    stack[0] = v282;
    goto v339;

v339:
    v282 = stack[-1];
    v335 = (Lisp_Object)((int32_t)(v282) - 0x10);
    v282 = stack[0];
    v282 = (Lisp_Object)(int32_t)((int32_t)v335 - (int32_t)v282 + TAG_FIXNUM);
    v282 = ((intptr_t)(v282) < 0 ? lisp_true : nil);
    if (v282 == nil) goto v340;
    v282 = (Lisp_Object)1; /* 0 */
    v337 = v282;
    goto v88;

v88:
    v335 = stack[-4];
    v282 = v337;
    v282 = (Lisp_Object)(int32_t)((int32_t)v335 - (int32_t)v282 + TAG_FIXNUM);
    v282 = ((intptr_t)(v282) < 0 ? lisp_true : nil);
    if (!(v282 == nil)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v336 = stack[-3];
    v211 = v337;
    v173 = stack[-3];
    v335 = stack[-1];
    v282 = v337;
    v282 = (Lisp_Object)(int32_t)((int32_t)v335 + (int32_t)v282 - TAG_FIXNUM);
    v282 = *(Lisp_Object *)((char *)v173 + (CELL-TAG_VECTOR) + ((int32_t)v282/(16/CELL)));
    *(Lisp_Object *)((char *)v336 + (CELL-TAG_VECTOR) + ((int32_t)v211/(16/CELL))) = v282;
    v282 = v337;
    v282 = (Lisp_Object)((int32_t)(v282) + 0x10);
    v337 = v282;
    goto v88;

v340:
    v335 = stack[-3];
    v282 = stack[0];
    v335 = *(Lisp_Object *)((char *)v335 + (CELL-TAG_VECTOR) + ((int32_t)v282/(16/CELL)));
    v282 = (Lisp_Object)1; /* 0 */
    if (v335 == v282) goto v8;
    v282 = elt(env, 4); /* "Quotient not exact in QUOTFAIL!-IN!-VECTOR" 
*/
    fn = elt(env, 5); /* errorf */
    v282 = (*qfn1(fn))(qenv(fn), v282);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-5];
    goto v8;

v8:
    v282 = stack[0];
    v282 = (Lisp_Object)((int32_t)(v282) + 0x10);
    stack[0] = v282;
    goto v339;

v179:
    v173 = stack[-3];
    v335 = stack[-1];
    v282 = stack[0];
    v282 = (Lisp_Object)(int32_t)((int32_t)v335 + (int32_t)v282 - TAG_FIXNUM);
    v173 = *(Lisp_Object *)((char *)v173 + (CELL-TAG_VECTOR) + ((int32_t)v282/(16/CELL)));
    v335 = stack[-2];
    v282 = stack[-1];
    v282 = *(Lisp_Object *)((char *)v335 + (CELL-TAG_VECTOR) + ((int32_t)v282/(16/CELL)));
    v282 = Lmodular_quotient(nil, v173, v282);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-5];
    v133 = v282;
    v282 = (Lisp_Object)1; /* 0 */
    v338 = v282;
    goto v80;

v80:
    v282 = stack[-1];
    v335 = (Lisp_Object)((int32_t)(v282) - 0x10);
    v282 = v338;
    v282 = (Lisp_Object)(int32_t)((int32_t)v335 - (int32_t)v282 + TAG_FIXNUM);
    v282 = ((intptr_t)(v282) < 0 ? lisp_true : nil);
    if (v282 == nil) goto v233;
    v173 = stack[-3];
    v335 = stack[-1];
    v282 = stack[0];
    v282 = (Lisp_Object)(int32_t)((int32_t)v335 + (int32_t)v282 - TAG_FIXNUM);
    v335 = v133;
    *(Lisp_Object *)((char *)v173 + (CELL-TAG_VECTOR) + ((int32_t)v282/(16/CELL))) = v335;
    v282 = stack[0];
    v282 = (Lisp_Object)((int32_t)(v282) - 0x10);
    stack[0] = v282;
    goto v236;

v233:
    v337 = stack[-3];
    v335 = stack[0];
    v282 = v338;
    v336 = (Lisp_Object)(int32_t)((int32_t)v335 + (int32_t)v282 - TAG_FIXNUM);
    v173 = stack[-3];
    v335 = stack[0];
    v282 = v338;
    v282 = (Lisp_Object)(int32_t)((int32_t)v335 + (int32_t)v282 - TAG_FIXNUM);
    v211 = *(Lisp_Object *)((char *)v173 + (CELL-TAG_VECTOR) + ((int32_t)v282/(16/CELL)));
    v173 = v133;
    v335 = stack[-2];
    v282 = v338;
    v282 = *(Lisp_Object *)((char *)v335 + (CELL-TAG_VECTOR) + ((int32_t)v282/(16/CELL)));
    v282 = Lmodular_times(nil, v173, v282);
    env = stack[-5];
    {   int32_t w = int_of_fixnum(v211) - int_of_fixnum(v282);
        if (w < 0) w += current_modulus;
        v282 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v337 + (CELL-TAG_VECTOR) + ((int32_t)v336/(16/CELL))) = v282;
    v282 = v338;
    v282 = (Lisp_Object)((int32_t)(v282) + 0x10);
    v338 = v282;
    goto v80;

v118:
    v282 = elt(env, 2); /* "Bad degrees in QUOTFAIL-IN-VECTOR" */
    {
        popv(6);
        fn = elt(env, 5); /* errorf */
        return (*qfn1(fn))(qenv(fn), v282);
    }

v226:
    v282 = elt(env, 1); /* "Attempt to divide by zero" */
    {
        popv(6);
        fn = elt(env, 5); /* errorf */
        return (*qfn1(fn))(qenv(fn), v282);
    }
/* error exit handlers */
v341:
    popv(6);
    return nil;
}



/* Code for modp */

static Lisp_Object CC_modp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v37;
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
    v37 = stack[-1];
    v84 = stack[0];
    v84 = Cremainder(v37, v84);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-2];
    stack[-1] = v84;
    v37 = stack[-1];
    v84 = (Lisp_Object)1; /* 0 */
    v84 = (Lisp_Object)lessp2(v37, v84);
    nil = C_nil;
    if (exception_pending()) goto v180;
    v84 = v84 ? lisp_true : nil;
    if (v84 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v37 = stack[-1];
    v84 = stack[0];
    popv(3);
    return plus2(v37, v84);
/* error exit handlers */
v180:
    popv(3);
    return nil;
}



/* Code for rl_bnfsimpl */

static Lisp_Object CC_rl_bnfsimpl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v116;
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
    v103 = v1;
    v116 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_bnfsimpl!* */
    v103 = list2(v116, v103);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-1];
    {
        Lisp_Object v85 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v85, v103);
    }
/* error exit handlers */
v104:
    popv(2);
    return nil;
}



/* Code for gb_buch!-ev_divides!? */

static Lisp_Object CC_gb_buchKev_dividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v342;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gb_buch-ev_divides?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v342 = v1;
    v101 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* ev_mtest!? */
        return (*qfn2(fn))(qenv(fn), v342, v101);
    }
}



/* Code for rd!:zerop!: */

static Lisp_Object CC_rdTzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:zerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v84 = v0;
/* end of prologue */
    v165 = v84;
    v165 = qcdr(v165);
    if (!consp(v165)) goto v15;
    v165 = v84;
    v165 = qcdr(v165);
    if (!consp(v165)) goto v117;
    v165 = v84;
    goto v116;

v116:
    v165 = qcdr(v165);
    v84 = qcar(v165);
    v165 = (Lisp_Object)1; /* 0 */
    v165 = (v84 == v165 ? lisp_true : nil);
    return onevalue(v165);

v117:
    v165 = v84;
    v165 = qcdr(v165);
    goto v116;

v15:
    v165 = v84;
    v165 = qcdr(v165);
    {
        fn = elt(env, 1); /* ft!:zerop */
        return (*qfn1(fn))(qenv(fn), v165);
    }
}



/* Code for dipsimpcont */

static Lisp_Object CC_dipsimpcont(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v181, v226;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipsimpcont");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v226 = v0;
/* end of prologue */
    v181 = qvalue(elt(env, 1)); /* !*vdpinteger */
    if (!(v181 == nil)) goto v15;
    v181 = qvalue(elt(env, 2)); /* !*groebdivide */
    if (v181 == nil) goto v15;
    v181 = v226;
    {
        fn = elt(env, 3); /* dipsimpcontr */
        return (*qfn1(fn))(qenv(fn), v181);
    }

v15:
    v181 = v226;
    {
        fn = elt(env, 4); /* dipsimpconti */
        return (*qfn1(fn))(qenv(fn), v181);
    }
}



/* Code for add_item */

static Lisp_Object CC_add_item(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204, v205;
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

v75:
    v204 = stack[0];
    v204 = qcdr(v204);
    if (v204 == nil) goto v89;
    v204 = stack[0];
    v204 = qcar(v204);
    v205 = qcar(v204);
    v204 = stack[-1];
    v204 = qcar(v204);
    fn = elt(env, 3); /* monordp */
    v204 = (*qfn2(fn))(qenv(fn), v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-3];
    if (v204 == nil) goto v95;
    v204 = stack[0];
    v204 = qcdr(v204);
    v204 = qcar(v204);
    stack[0] = v204;
    goto v75;

v95:
    v204 = stack[0];
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    stack[0] = v204;
    goto v75;

v89:
    v205 = stack[0];
    v204 = stack[-1];
    fn = elt(env, 4); /* setcar */
    v204 = (*qfn2(fn))(qenv(fn), v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-3];
    stack[-2] = stack[0];
    stack[-1] = elt(env, 1); /* !*xset!* */
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v204 = elt(env, 1); /* !*xset!* */
    v204 = ncons(v204);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-3];
    v204 = acons(stack[-1], stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-3];
    fn = elt(env, 5); /* setcdr */
    v204 = (*qfn2(fn))(qenv(fn), stack[-2], v204);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-3];
    v204 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v204); }
/* error exit handlers */
v193:
    popv(4);
    return nil;
}



/* Code for edge_new_parents */

static Lisp_Object CC_edge_new_parents(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v84, v37;
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
    v37 = v0;
/* end of prologue */
    v165 = v37;
    v84 = qcar(v165);
    v165 = qvalue(elt(env, 1)); /* old_edge_list */
    v165 = Lassoc(nil, v84, v165);
    if (v165 == nil) goto v181;
    v165 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v165); }

v181:
    v165 = v37;
    v165 = qcdr(v165);
    v165 = qcar(v165);
    v84 = v165;
    v84 = qcar(v84);
    v165 = qcdr(v165);
    v165 = list2(v84, v165);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* edge_new_parent */
        return (*qfn1(fn))(qenv(fn), v165);
    }
/* error exit handlers */
v36:
    popv(1);
    return nil;
}



/* Code for in_list1 */

static Lisp_Object CC_in_list1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v24, v59;
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
    v23 = qvalue(elt(env, 1)); /* !*echo */
    stack[-1] = v23;
    v23 = qvalue(elt(env, 2)); /* !*reduce4 */
    if (v23 == nil) goto v12;
    v23 = stack[-3];
    fn = elt(env, 13); /* type */
    v24 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-5];
    v23 = elt(env, 3); /* string */
    if (v24 == v23) goto v84;
    v24 = stack[-3];
    v23 = elt(env, 3); /* string */
    fn = elt(env, 14); /* typerr */
    v23 = (*qfn2(fn))(qenv(fn), v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-5];
    goto v12;

v12:
    v23 = stack[-3];
    fn = elt(env, 15); /* mkfil!* */
    v24 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-5];
    stack[-3] = v24;
    v23 = elt(env, 4); /* input */
    fn = elt(env, 16); /* open */
    v23 = (*qfn2(fn))(qenv(fn), v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-5];
    stack[-4] = v23;
    v23 = stack[-4];
    v23 = Lrds(nil, v23);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-5];
    stack[0] = v23;
    v24 = stack[-3];
    v23 = qvalue(elt(env, 5)); /* linelist!* */
    v23 = Lassoc(nil, v24, v23);
    if (!(v23 == nil)) goto v35;

v35:
    v23 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 7)) = v23; /* curline!* */
    v59 = stack[-3];
    v24 = stack[-4];
    v23 = (Lisp_Object)17; /* 1 */
    v23 = list3(v59, v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-5];
    qvalue(elt(env, 8)) = v23; /* ifl!* */
    v24 = qvalue(elt(env, 8)); /* ifl!* */
    v23 = qvalue(elt(env, 9)); /* ipl!* */
    v23 = cons(v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-5];
    qvalue(elt(env, 9)) = v23; /* ipl!* */
    v23 = stack[-2];
    qvalue(elt(env, 1)) = v23; /* !*echo */
    fn = elt(env, 17); /* begin1 */
    v23 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-5];
    v23 = stack[0];
    v23 = Lrds(nil, v23);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-5];
    v23 = stack[-4];
    v23 = Lclose(nil, v23);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-5];
    v23 = stack[-1];
    qvalue(elt(env, 1)) = v23; /* !*echo */
    v23 = qvalue(elt(env, 9)); /* ipl!* */
    if (!(v23 == nil)) goto v49;
    v23 = qvalue(elt(env, 10)); /* contl!* */
    if (v23 == nil) goto v49;
    v23 = qvalue(elt(env, 6)); /* nil */
    { popv(6); return onevalue(v23); }

v49:
    v23 = qvalue(elt(env, 9)); /* ipl!* */
    if (v23 == nil) goto v191;
    v24 = stack[-3];
    v23 = qvalue(elt(env, 9)); /* ipl!* */
    v23 = qcar(v23);
    v23 = qcar(v23);
    if (!(v24 == v23)) goto v191;
    v23 = qvalue(elt(env, 9)); /* ipl!* */
    v23 = qcdr(v23);
    qvalue(elt(env, 9)) = v23; /* ipl!* */
    goto v14;

v14:
    v23 = nil;
    { popv(6); return onevalue(v23); }

v191:
    v23 = qvalue(elt(env, 11)); /* !*protfg */
    if (!(v23 == nil)) goto v96;
    v59 = elt(env, 12); /* "FILE STACK CONFUSION" */
    v24 = stack[-3];
    v23 = qvalue(elt(env, 9)); /* ipl!* */
    v23 = list3(v59, v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-5];
    fn = elt(env, 18); /* lprie */
    v23 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-5];
    goto v96;

v96:
    v23 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v158;
    goto v14;

v84:
    v23 = stack[-3];
    fn = elt(env, 19); /* value */
    v23 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-5];
    stack[-3] = v23;
    goto v12;
/* error exit handlers */
v158:
    popv(6);
    return nil;
}



/* Code for sf2mv */

static Lisp_Object CC_sf2mv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v182, v181;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sf2mv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v102 = v1;
    v182 = v0;
/* end of prologue */
    v181 = v182;
    v182 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* sf2mv1 */
        return (*qfnn(fn))(qenv(fn), 3, v181, v182, v102);
    }
}



/* Code for red!=hide */

static Lisp_Object CC_redMhide(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red=hide");
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
    v45 = v0;
/* end of prologue */
    stack[-5] = v45;
    v45 = stack[-5];
    if (v45 == nil) goto v101;
    v45 = stack[-5];
    v45 = qcar(v45);
    stack[-1] = v45;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v45 = stack[-1];
    v45 = qcar(v45);
    fn = elt(env, 2); /* mo_neg */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-6];
    fn = elt(env, 3); /* mo_times_ei */
    v99 = (*qfn2(fn))(qenv(fn), stack[0], v45);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-6];
    v45 = stack[-1];
    v45 = qcdr(v45);
    v45 = cons(v99, v45);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-6];
    v45 = ncons(v45);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-6];
    stack[-3] = v45;
    stack[-4] = v45;
    goto v61;

v61:
    v45 = stack[-5];
    v45 = qcdr(v45);
    stack[-5] = v45;
    v45 = stack[-5];
    if (v45 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[-2] = stack[-3];
    v45 = stack[-5];
    v45 = qcar(v45);
    stack[-1] = v45;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v45 = stack[-1];
    v45 = qcar(v45);
    fn = elt(env, 2); /* mo_neg */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-6];
    fn = elt(env, 3); /* mo_times_ei */
    v99 = (*qfn2(fn))(qenv(fn), stack[0], v45);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-6];
    v45 = stack[-1];
    v45 = qcdr(v45);
    v45 = cons(v99, v45);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-6];
    v45 = ncons(v45);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-6];
    v45 = Lrplacd(nil, stack[-2], v45);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-6];
    v45 = stack[-3];
    v45 = qcdr(v45);
    stack[-3] = v45;
    goto v61;

v101:
    v45 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v45); }
/* error exit handlers */
v29:
    popv(7);
    return nil;
}



/* Code for clean_numid */

static Lisp_Object CC_clean_numid(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clean_numid");
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
    goto v75;

v75:
    v165 = stack[0];
    if (v165 == nil) goto v111;
    v165 = stack[0];
    v165 = qcar(v165);
    fn = elt(env, 1); /* !*id2num */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-2];
    if (v165 == nil) goto v86;
    v165 = stack[0];
    v165 = qcdr(v165);
    stack[0] = v165;
    goto v75;

v86:
    v165 = stack[0];
    v84 = qcar(v165);
    v165 = stack[-1];
    v165 = cons(v84, v165);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-2];
    stack[-1] = v165;
    v165 = stack[0];
    v165 = qcdr(v165);
    stack[0] = v165;
    goto v75;

v111:
    v165 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v165);
    }
/* error exit handlers */
v91:
    popv(3);
    return nil;
}



/* Code for orddf */

static Lisp_Object CC_orddf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v229;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for orddf");
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

v75:
    v172 = stack[-1];
    if (v172 == nil) goto v111;
    v172 = stack[0];
    if (v172 == nil) goto v85;
    v172 = stack[-1];
    v229 = qcar(v172);
    v172 = stack[0];
    v172 = qcar(v172);
    fn = elt(env, 6); /* exptcompare */
    v172 = (*qfn2(fn))(qenv(fn), v229, v172);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    if (v172 == nil) goto v192;
    v172 = qvalue(elt(env, 4)); /* t */
    { popv(3); return onevalue(v172); }

v192:
    v172 = stack[0];
    v229 = qcar(v172);
    v172 = stack[-1];
    v172 = qcar(v172);
    fn = elt(env, 6); /* exptcompare */
    v172 = (*qfn2(fn))(qenv(fn), v229, v172);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    if (v172 == nil) goto v46;
    v172 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v172); }

v46:
    v172 = stack[-1];
    v172 = qcdr(v172);
    stack[-1] = v172;
    v172 = stack[0];
    v172 = qcdr(v172);
    stack[0] = v172;
    goto v75;

v85:
    v172 = elt(env, 3); /* "Orddf u longer than v" */
    {
        popv(3);
        fn = elt(env, 7); /* interr */
        return (*qfn1(fn))(qenv(fn), v172);
    }

v111:
    v172 = stack[0];
    if (v172 == nil) goto v89;
    v172 = elt(env, 2); /* "Orddf v longer than u" */
    {
        popv(3);
        fn = elt(env, 7); /* interr */
        return (*qfn1(fn))(qenv(fn), v172);
    }

v89:
    v172 = elt(env, 1); /* "Orddf = case" */
    {
        popv(3);
        fn = elt(env, 7); /* interr */
        return (*qfn1(fn))(qenv(fn), v172);
    }
/* error exit handlers */
v32:
    popv(3);
    return nil;
}



/* Code for mk!+mat!+plus!+mat */

static Lisp_Object CC_mkLmatLplusLmat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v358, v359, v360;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+mat+plus+mat");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v1;
    stack[-11] = v0;
/* end of prologue */
    v358 = stack[-11];
    fn = elt(env, 7); /* matrix!+p */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    if (!(v358 == nil)) goto v342;
    v358 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v358 == nil)) goto v117;
    v358 = elt(env, 2); /* "no matrix in add" */
    fn = elt(env, 8); /* lprie */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    goto v117;

v117:
    v358 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    goto v342;

v342:
    v358 = stack[-10];
    fn = elt(env, 7); /* matrix!+p */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    if (!(v358 == nil)) goto v118;
    v358 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v358 == nil)) goto v36;
    v358 = elt(env, 2); /* "no matrix in add" */
    fn = elt(env, 8); /* lprie */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    goto v36;

v36:
    v358 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    goto v118;

v118:
    v358 = stack[-11];
    fn = elt(env, 9); /* get!+col!+nr */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    stack[-12] = v358;
    v358 = stack[-11];
    fn = elt(env, 10); /* get!+row!+nr */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    stack[-9] = v358;
    stack[0] = stack[-12];
    v358 = stack[-10];
    fn = elt(env, 9); /* get!+col!+nr */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    if (equal(stack[0], v358)) goto v179;
    v358 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v358 == nil)) goto v205;
    v358 = elt(env, 3); /* "wrong dimensions in add" */
    fn = elt(env, 8); /* lprie */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    goto v205;

v205:
    v358 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    goto v179;

v179:
    stack[0] = stack[-9];
    v358 = stack[-10];
    fn = elt(env, 10); /* get!+row!+nr */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    if (equal(stack[0], v358)) goto v108;
    v358 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v358 == nil)) goto v29;
    v358 = elt(env, 3); /* "wrong dimensions in add" */
    fn = elt(env, 8); /* lprie */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    goto v29;

v29:
    v358 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    goto v108;

v108:
    v358 = (Lisp_Object)17; /* 1 */
    stack[-8] = v358;
    v359 = stack[-9];
    v358 = stack[-8];
    v358 = difference2(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v358 = Lminusp(nil, v358);
    env = stack[-13];
    if (v358 == nil) goto v362;
    v358 = qvalue(elt(env, 4)); /* nil */
    { popv(14); return onevalue(v358); }

v362:
    v358 = (Lisp_Object)17; /* 1 */
    stack[-4] = v358;
    v359 = stack[-12];
    v358 = stack[-4];
    v358 = difference2(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v358 = Lminusp(nil, v358);
    env = stack[-13];
    if (v358 == nil) goto v17;
    v358 = qvalue(elt(env, 4)); /* nil */
    goto v22;

v22:
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    stack[-6] = v358;
    stack[-7] = v358;
    goto v224;

v224:
    v358 = stack[-8];
    v358 = add1(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    stack[-8] = v358;
    v359 = stack[-9];
    v358 = stack[-8];
    v358 = difference2(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v358 = Lminusp(nil, v358);
    env = stack[-13];
    if (!(v358 == nil)) { Lisp_Object res = stack[-7]; popv(14); return onevalue(res); }
    stack[-5] = stack[-6];
    v358 = (Lisp_Object)17; /* 1 */
    stack[-4] = v358;
    v359 = stack[-12];
    v358 = stack[-4];
    v358 = difference2(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v358 = Lminusp(nil, v358);
    env = stack[-13];
    if (v358 == nil) goto v211;
    v358 = qvalue(elt(env, 4)); /* nil */
    goto v216;

v216:
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v358 = Lrplacd(nil, stack[-5], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v358 = stack[-6];
    v358 = qcdr(v358);
    stack[-6] = v358;
    goto v224;

v211:
    v360 = stack[-11];
    v359 = stack[-8];
    v358 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v360, v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v360 = stack[-10];
    v359 = stack[-8];
    v358 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    v358 = (*qfnn(fn))(qenv(fn), 3, v360, v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    fn = elt(env, 12); /* addsq */
    v358 = (*qfn2(fn))(qenv(fn), stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v359 = v358;
    v358 = qvalue(elt(env, 5)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v358; /* !*sub2 */
    v358 = v359;
    fn = elt(env, 13); /* subs2 */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-13];
    v359 = v358;
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    v358 = v359;
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    stack[-2] = v358;
    stack[-3] = v358;
    goto v364;

v364:
    v358 = stack[-4];
    v358 = add1(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    stack[-4] = v358;
    v359 = stack[-12];
    v358 = stack[-4];
    v358 = difference2(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v358 = Lminusp(nil, v358);
    env = stack[-13];
    if (v358 == nil) goto v365;
    v358 = stack[-3];
    goto v216;

v365:
    stack[-1] = stack[-2];
    v360 = stack[-11];
    v359 = stack[-8];
    v358 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v360, v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v360 = stack[-10];
    v359 = stack[-8];
    v358 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    v358 = (*qfnn(fn))(qenv(fn), 3, v360, v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    fn = elt(env, 12); /* addsq */
    v358 = (*qfn2(fn))(qenv(fn), stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v359 = v358;
    v358 = qvalue(elt(env, 5)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v358; /* !*sub2 */
    v358 = v359;
    fn = elt(env, 13); /* subs2 */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-13];
    v359 = v358;
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    v358 = v359;
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v358 = Lrplacd(nil, stack[-1], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v358 = stack[-2];
    v358 = qcdr(v358);
    stack[-2] = v358;
    goto v364;

v17:
    v360 = stack[-11];
    v359 = stack[-8];
    v358 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v360, v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v360 = stack[-10];
    v359 = stack[-8];
    v358 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    v358 = (*qfnn(fn))(qenv(fn), 3, v360, v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    fn = elt(env, 12); /* addsq */
    v358 = (*qfn2(fn))(qenv(fn), stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v359 = v358;
    v358 = qvalue(elt(env, 5)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v358; /* !*sub2 */
    v358 = v359;
    fn = elt(env, 13); /* subs2 */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-13];
    v359 = v358;
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    v358 = v359;
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    stack[-2] = v358;
    stack[-3] = v358;
    goto v58;

v58:
    v358 = stack[-4];
    v358 = add1(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    stack[-4] = v358;
    v359 = stack[-12];
    v358 = stack[-4];
    v358 = difference2(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v358 = Lminusp(nil, v358);
    env = stack[-13];
    if (v358 == nil) goto v71;
    v358 = stack[-3];
    goto v22;

v71:
    stack[-1] = stack[-2];
    v360 = stack[-11];
    v359 = stack[-8];
    v358 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v360, v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v360 = stack[-10];
    v359 = stack[-8];
    v358 = stack[-4];
    fn = elt(env, 11); /* get!+mat!+entry */
    v358 = (*qfnn(fn))(qenv(fn), 3, v360, v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    fn = elt(env, 12); /* addsq */
    v358 = (*qfn2(fn))(qenv(fn), stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v359 = v358;
    v358 = qvalue(elt(env, 5)); /* t */
    stack[0] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v358; /* !*sub2 */
    v358 = v359;
    fn = elt(env, 13); /* subs2 */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-13];
    v359 = v358;
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    v358 = v359;
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v358 = Lrplacd(nil, stack[-1], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-13];
    v358 = stack[-2];
    v358 = qcdr(v358);
    stack[-2] = v358;
    goto v58;
/* error exit handlers */
v308:
    env = stack[-13];
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    popv(14);
    return nil;
v367:
    env = stack[-13];
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    popv(14);
    return nil;
v366:
    env = stack[-13];
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    popv(14);
    return nil;
v363:
    env = stack[-13];
    qvalue(elt(env, 6)) = stack[0]; /* !*sub2 */
    popv(14);
    return nil;
v361:
    popv(14);
    return nil;
}



/* Code for semanticml */

static Lisp_Object CC_semanticml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v298;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for semanticml");
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
    v29 = stack[0];
    v298 = Llength(nil, v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = (Lisp_Object)17; /* 1 */
    v29 = (Lisp_Object)greaterp2(v298, v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    v29 = v29 ? lisp_true : nil;
    env = stack[-1];
    if (v29 == nil) goto v75;
    v29 = elt(env, 1); /* "<apply>" */
    fn = elt(env, 15); /* printout */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = elt(env, 3); /* "<fn>" */
    fn = elt(env, 15); /* printout */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    goto v75;

v75:
    v29 = elt(env, 5); /* "<semantic>" */
    fn = elt(env, 15); /* printout */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = elt(env, 6); /* "<ci><mo>" */
    fn = elt(env, 15); /* printout */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = stack[0];
    v29 = qcar(v29);
    v29 = qcar(v29);
    v29 = Lprinc(nil, v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = elt(env, 7); /* "</mo></ci>" */
    v29 = Lprinc(nil, v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = elt(env, 8); /* "<annotation-xml encoding=""OpenMath"">" */
    fn = elt(env, 15); /* printout */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = elt(env, 9); /* "<" */
    fn = elt(env, 15); /* printout */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = stack[0];
    v29 = qcar(v29);
    v29 = qcdr(v29);
    v29 = qcar(v29);
    fn = elt(env, 17); /* list2string */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = elt(env, 10); /* ">" */
    v29 = Lprinc(nil, v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = elt(env, 11); /* "</annotation-xml>" */
    fn = elt(env, 15); /* printout */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = elt(env, 12); /* "</semantic>" */
    fn = elt(env, 15); /* printout */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = stack[0];
    v298 = Llength(nil, v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = (Lisp_Object)17; /* 1 */
    v29 = (Lisp_Object)greaterp2(v298, v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    v29 = v29 ? lisp_true : nil;
    env = stack[-1];
    if (v29 == nil) goto v229;
    v29 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = elt(env, 13); /* "</fn>" */
    fn = elt(env, 15); /* printout */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = stack[0];
    v29 = qcdr(v29);
    fn = elt(env, 18); /* multi_elem */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    v29 = elt(env, 14); /* "</apply>" */
    fn = elt(env, 15); /* printout */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v81;
    goto v229;

v229:
    v29 = nil;
    { popv(2); return onevalue(v29); }
/* error exit handlers */
v81:
    popv(2);
    return nil;
}



/* Code for alg_plus */

static Lisp_Object CC_alg_plus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v226, v103, v116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for alg_plus");
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
    v226 = v1;
    v103 = v0;
/* end of prologue */
    v116 = elt(env, 1); /* plus */
    v226 = list3(v116, v103, v226);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* aeval */
        return (*qfn1(fn))(qenv(fn), v226);
    }
/* error exit handlers */
v117:
    popv(1);
    return nil;
}



/* Code for crn!:zerop */

static Lisp_Object CC_crnTzerop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v177, v112, v164;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crn:zerop");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v164 = v0;
/* end of prologue */
    v177 = v164;
    v177 = qcdr(v177);
    v177 = qcar(v177);
    v112 = qcar(v177);
    v177 = (Lisp_Object)1; /* 0 */
    if (v112 == v177) goto v116;
    v177 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v177);

v116:
    v177 = v164;
    v177 = qcdr(v177);
    v177 = qcdr(v177);
    v112 = qcar(v177);
    v177 = (Lisp_Object)1; /* 0 */
    v177 = (v112 == v177 ? lisp_true : nil);
    return onevalue(v177);
}



/* Code for findelem2 */

static Lisp_Object MS_CDECL CC_findelem2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v60, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v229, v204, v205, v32;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "findelem2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findelem2");
#endif
    if (stack >= stacklimit)
    {
        push3(v60,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v172 = v60;
    v229 = v1;
    v204 = v0;
/* end of prologue */
    v205 = v204;
    v205 = Lconsp(nil, v205);
    env = stack[0];
    if (v205 == nil) goto v37;
    v205 = v204;
    v205 = qcar(v205);
    v32 = elt(env, 1); /* sparsemat */
    if (!(v205 == v32)) goto v37;
    v204 = qcdr(v204);
    v204 = qcar(v204);
    goto v37;

v37:
    v229 = *(Lisp_Object *)((char *)v204 + (CELL-TAG_VECTOR) + ((int32_t)v229/(16/CELL)));
    v172 = Latsoc(nil, v172, v229);
    v229 = v172;
    v172 = v229;
    if (v172 == nil) goto v35;
    v172 = v229;
    v172 = qcdr(v172);
    { popv(1); return onevalue(v172); }

v35:
    v172 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v172); }
}



/* Code for size_of_matrix */

static Lisp_Object CC_size_of_matrix(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v177;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for size_of_matrix");
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
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v113 = stack[0];
    v113 = Llength(nil, v113);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-2];
    v113 = plus2(stack[-1], v113);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-2];
    stack[-1] = v113;
    v113 = stack[0];
    v113 = qcdr(v113);
    v113 = qcar(v113);
    v113 = Llength(nil, v113);
    nil = C_nil;
    if (exception_pending()) goto v165;
    v177 = stack[-1];
    popv(3);
    return list2(v177, v113);
/* error exit handlers */
v165:
    popv(3);
    return nil;
}



setup_type const u28_setup[] =
{
    {"rd:difference",           too_few_2,      CC_rdTdifference,wrong_no_2},
    {"physoptimes",             CC_physoptimes, too_many_1,    wrong_no_1},
    {"calc_atlas",              too_few_2,      CC_calc_atlas, wrong_no_2},
    {"gettype",                 CC_gettype,     too_many_1,    wrong_no_1},
    {"subs2chk",                CC_subs2chk,    too_many_1,    wrong_no_1},
    {"xremf",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_xremf},
    {"maxfrom1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_maxfrom1},
    {"cancel",                  CC_cancel,      too_many_1,    wrong_no_1},
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
    {"red=hide",                CC_redMhide,    too_many_1,    wrong_no_1},
    {"clean_numid",             CC_clean_numid, too_many_1,    wrong_no_1},
    {"orddf",                   too_few_2,      CC_orddf,      wrong_no_2},
    {"mk+mat+plus+mat",         too_few_2,      CC_mkLmatLplusLmat,wrong_no_2},
    {"semanticml",              CC_semanticml,  too_many_1,    wrong_no_1},
    {"alg_plus",                too_few_2,      CC_alg_plus,   wrong_no_2},
    {"crn:zerop",               CC_crnTzerop,   too_many_1,    wrong_no_1},
    {"findelem2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_findelem2},
    {"size_of_matrix",          CC_size_of_matrix,too_many_1,  wrong_no_1},
    {NULL, (one_args *)"u28", (two_args *)"5144 700014 2569178", 0}
};

/* end of generated code */
