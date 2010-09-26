
/* $destdir\u49.c        Machine generated C code */

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


/* Code for smaddm2 */

static Lisp_Object MS_CDECL CC_smaddm2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v41, v42, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "smaddm2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smaddm2");
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
/* copy arguments values to proper place */
    stack[-8] = v2;
    v41 = v1;
    v40 = v0;
/* end of prologue */
    stack[-7] = v40;
    v40 = v41;
    stack[-6] = v40;
    v41 = stack[-6];
    v40 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* copy_vect */
    v40 = (*qfn2(fn))(qenv(fn), v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-10];
    stack[-9] = v40;
    v40 = (Lisp_Object)17; /* 1 */
    stack[-2] = v40;
    goto v45;

v45:
    v40 = stack[-8];
    v40 = qcdr(v40);
    v41 = qcar(v40);
    v40 = stack[-2];
    v40 = difference2(v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-10];
    v40 = Lminusp(nil, v40);
    env = stack[-10];
    if (!(v40 == nil)) { Lisp_Object res = stack[-9]; popv(11); return onevalue(res); }
    v41 = stack[-7];
    v40 = stack[-2];
    fn = elt(env, 3); /* findrow */
    v40 = (*qfn2(fn))(qenv(fn), v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-10];
    stack[0] = v40;
    v41 = stack[-6];
    v40 = stack[-2];
    fn = elt(env, 3); /* findrow */
    v40 = (*qfn2(fn))(qenv(fn), v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-10];
    stack[-5] = v40;
    v40 = stack[0];
    if (v40 == nil) goto v46;
    v40 = stack[0];
    v40 = qcdr(v40);
    stack[-1] = v40;
    goto v47;

v47:
    v40 = stack[-1];
    if (v40 == nil) goto v46;
    v40 = stack[-1];
    v40 = qcar(v40);
    v41 = v40;
    v40 = v41;
    v40 = qcar(v40);
    stack[-3] = v40;
    v40 = v41;
    v40 = qcdr(v40);
    stack[0] = v40;
    v41 = stack[-3];
    v40 = stack[-5];
    v40 = Latsoc(nil, v41, v40);
    stack[-4] = v40;
    v40 = stack[-4];
    if (v40 == nil) goto v48;
    v40 = stack[-4];
    v40 = qcdr(v40);
    stack[-4] = v40;
    v40 = stack[0];
    fn = elt(env, 4); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-10];
    v40 = stack[-4];
    fn = elt(env, 4); /* simp */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-10];
    fn = elt(env, 5); /* addsq */
    v40 = (*qfn2(fn))(qenv(fn), stack[0], v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-10];
    stack[0] = v40;
    v40 = stack[0];
    fn = elt(env, 6); /* mk!*sq */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-10];
    stack[0] = v40;
    v42 = stack[-9];
    v41 = stack[-2];
    v40 = stack[-3];
    v43 = list3(v42, v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-10];
    v42 = stack[0];
    v41 = stack[-9];
    v40 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 7); /* letmtr3 */
    v40 = (*qfnn(fn))(qenv(fn), 4, v43, v42, v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-10];
    goto v49;

v49:
    v40 = stack[-1];
    v40 = qcdr(v40);
    stack[-1] = v40;
    goto v47;

v48:
    v42 = stack[-9];
    v41 = stack[-2];
    v40 = stack[-3];
    v43 = list3(v42, v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-10];
    v42 = stack[0];
    v41 = stack[-9];
    v40 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 7); /* letmtr3 */
    v40 = (*qfnn(fn))(qenv(fn), 4, v43, v42, v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-10];
    goto v49;

v46:
    v40 = stack[-2];
    v40 = add1(v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-10];
    stack[-2] = v40;
    goto v45;
/* error exit handlers */
v44:
    popv(11);
    return nil;
}



/* Code for mod!-domainvalchk */

static Lisp_Object CC_modKdomainvalchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v33, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod-domainvalchk");
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
    v34 = v1;
    v58 = v0;
/* end of prologue */
    v33 = v58;
    v58 = elt(env, 1); /* expt */
    if (v33 == v58) goto v59;
    v58 = qvalue(elt(env, 2)); /* nil */
    goto v29;

v29:
    v34 = v58;
    v33 = v34;
    v58 = elt(env, 3); /* failed */
    if (v33 == v58) goto v60;
    v33 = v34;
    v58 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v33, v58);

v60:
    v58 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v58); }

v59:
    v58 = v34;
    v58 = qcar(v58);
    v33 = v34;
    v33 = qcdr(v33);
    v33 = qcar(v33);
    fn = elt(env, 4); /* mod!-expt!-fract */
    v58 = (*qfn2(fn))(qenv(fn), v58, v33);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[0];
    goto v29;
/* error exit handlers */
v61:
    popv(1);
    return nil;
}



/* Code for nssimp */

static Lisp_Object CC_nssimp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v101, v102, v103, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nssimp");
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
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    stack[-2] = nil;
    stack[0] = nil;
    stack[-1] = nil;
    v101 = stack[-5];
    v100 = stack[-4];
    fn = elt(env, 14); /* dsimp */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    stack[-5] = v100;
    goto v17;

v17:
    v100 = stack[-5];
    if (v100 == nil) { Lisp_Object res = stack[-1]; popv(8); return onevalue(res); }
    v100 = stack[-5];
    v100 = qcar(v100);
    stack[-3] = v100;
    goto v16;

v16:
    v100 = stack[-3];
    if (v100 == nil) goto v13;
    v100 = stack[-3];
    v100 = qcar(v100);
    stack[-6] = v100;
    if (is_number(v100)) goto v106;
    v101 = stack[-6];
    v100 = elt(env, 1); /* !*div */
    if (!consp(v101)) goto v107;
    v101 = qcar(v101);
    if (!(v101 == v100)) goto v107;

v108:
    v100 = stack[-6];
    v100 = ncons(v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    v100 = Lnconc(nil, stack[0], v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    stack[0] = v100;
    goto v60;

v60:
    v100 = stack[-3];
    v100 = qcdr(v100);
    stack[-3] = v100;
    goto v16;

v107:
    v100 = stack[-6];
    fn = elt(env, 15); /* getrtype */
    v101 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    v102 = v101;
    v100 = elt(env, 2); /* yetunknowntype */
    if (v101 == v100) goto v109;
    v100 = v102;
    v101 = v100;
    goto v34;

v34:
    v100 = stack[-4];
    if (v101 == v100) goto v108;
    else goto v106;

v106:
    v100 = stack[-6];
    v100 = ncons(v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    v100 = Lnconc(nil, stack[-2], v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    stack[-2] = v100;
    goto v60;

v109:
    v101 = stack[-6];
    v100 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 16); /* eval!-yetunknowntypeexpr */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    stack[-6] = v100;
    fn = elt(env, 15); /* getrtype */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    v101 = v100;
    goto v34;

v13:
    v100 = stack[0];
    if (!(v100 == nil)) goto v110;
    v100 = stack[-4];
    stack[0] = v100;
    v100 = stack[-2];
    v100 = qcar(v100);
    if (symbolp(v100)) goto v111;
    v101 = stack[0];
    v100 = elt(env, 8); /* tag */
    v101 = get(v101, v100);
    env = stack[-7];
    v100 = elt(env, 9); /* i2d */
    v100 = get(v101, v100);
    env = stack[-7];
    stack[-3] = v100;
    if (v100 == nil) goto v112;
    v101 = stack[-3];
    v100 = (Lisp_Object)17; /* 1 */
    v100 = Lapply1(nil, v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    v100 = ncons(v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    stack[0] = v100;
    goto v110;

v110:
    v100 = stack[-2];
    if (v100 == nil) goto v113;
    v100 = stack[-2];
    fn = elt(env, 17); /* simptimes */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    v101 = v100;
    goto v114;

v114:
    v100 = stack[0];
    v101 = cons(v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    v100 = stack[-1];
    fn = elt(env, 18); /* addns */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    stack[-1] = v100;
    v100 = stack[-5];
    v100 = qcdr(v100);
    stack[-5] = v100;
    v100 = qvalue(elt(env, 3)); /* nil */
    stack[0] = v100;
    stack[-2] = v100;
    goto v17;

v113:
    v101 = (Lisp_Object)17; /* 1 */
    v100 = (Lisp_Object)17; /* 1 */
    v100 = cons(v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    v101 = v100;
    goto v114;

v112:
    v102 = elt(env, 10); /* "Missing" */
    v101 = stack[0];
    v100 = elt(env, 11); /* "in" */
    v104 = list3(v102, v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    v100 = stack[-2];
    v103 = qcar(v100);
    v102 = qvalue(elt(env, 3)); /* nil */
    v101 = qvalue(elt(env, 3)); /* nil */
    v100 = qvalue(elt(env, 12)); /* t */
    fn = elt(env, 19); /* msgpri */
    v100 = (*qfnn(fn))(qenv(fn), 5, v104, v103, v102, v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    goto v115;

v115:
    v100 = stack[-2];
    v102 = qcar(v100);
    v101 = elt(env, 13); /* rtype */
    v100 = stack[0];
    v100 = Lputprop(nil, 3, v102, v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    v100 = stack[-2];
    v100 = qcar(v100);
    v100 = ncons(v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    stack[0] = v100;
    v100 = stack[-2];
    v100 = qcdr(v100);
    stack[-2] = v100;
    goto v110;

v111:
    v100 = stack[-2];
    v102 = qcar(v100);
    v101 = stack[0];
    v100 = elt(env, 4); /* fn */
    v100 = get(v101, v100);
    env = stack[-7];
    v100 = Lflagp(nil, v102, v100);
    env = stack[-7];
    if (v100 == nil) goto v116;
    v102 = stack[0];
    v101 = stack[-2];
    v100 = elt(env, 5); /* "not set" */
    v100 = list3(v102, v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    v101 = v100;
    v100 = v101;
    qvalue(elt(env, 6)) = v100; /* errmsg!* */
    v100 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v100 == nil)) goto v117;
    v100 = v101;
    fn = elt(env, 20); /* lprie */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    goto v117;

v117:
    v100 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    goto v115;

v116:
    v100 = stack[-2];
    v101 = qcar(v100);
    v100 = stack[0];
    fn = elt(env, 21); /* redmsg */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-7];
    goto v115;
/* error exit handlers */
v105:
    popv(8);
    return nil;
}



/* Code for dipreplus */

static Lisp_Object CC_dipreplus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v38;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipreplus");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v38 = v0;
/* end of prologue */
    v55 = v38;
    if (!consp(v55)) return onevalue(v38);
    v55 = v38;
    v55 = qcdr(v55);
    if (v55 == nil) goto v27;
    v55 = elt(env, 1); /* plus */
    return cons(v55, v38);

v27:
    v55 = v38;
    v55 = qcar(v55);
    return onevalue(v55);
}



/* Code for addm1 */

static Lisp_Object MS_CDECL CC_addm1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v28, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "addm1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addm1");
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
    stack[-3] = nil;
    goto v29;

v29:
    v123 = stack[-2];
    if (!(v123 == nil)) goto v17;
    v123 = stack[-1];
    if (!(v123 == nil)) goto v17;
    v123 = stack[-3];
    {
        popv(5);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v123);
    }

v17:
    v123 = stack[-2];
    if (v123 == nil) goto v38;
    v123 = stack[-1];
    if (v123 == nil) goto v38;
    v109 = stack[0];
    v123 = stack[-2];
    v28 = qcar(v123);
    v123 = stack[-1];
    v123 = qcar(v123);
    v28 = Lapply2(nil, 3, v109, v28, v123);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v123 = stack[-3];
    v123 = cons(v28, v123);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    stack[-3] = v123;
    v123 = stack[-2];
    v123 = qcdr(v123);
    stack[-2] = v123;
    v123 = stack[-1];
    v123 = qcdr(v123);
    stack[-1] = v123;
    goto v29;

v38:
    stack[0] = stack[-3];
    v123 = elt(env, 1); /* "Matrix mismatch" */
    v28 = v123;
    v123 = v28;
    qvalue(elt(env, 2)) = v123; /* errmsg!* */
    v123 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v123 == nil)) goto v124;
    v123 = v28;
    fn = elt(env, 5); /* lprie */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    goto v124;

v124:
    v123 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v123 = nil;
    {
        Lisp_Object v95 = stack[0];
        popv(5);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v95, v123);
    }
/* error exit handlers */
v94:
    popv(5);
    return nil;
}



/* Code for indexvp */

static Lisp_Object CC_indexvp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v127;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indexvp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v127 = v0;
/* end of prologue */
    v126 = v127;
    if (!consp(v126)) goto v8;
    v126 = v127;
    v126 = qcar(v126);
    v127 = elt(env, 2); /* indexvar */
        return Lflagp(nil, v126, v127);

v8:
    v126 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v126);
}



/* Code for calc_world */

static Lisp_Object CC_calc_world(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_world");
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
    stack[0] = stack[-1];
    v31 = stack[-2];
    fn = elt(env, 1); /* s_world_names */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    fn = elt(env, 2); /* actual_alst */
    v31 = (*qfn2(fn))(qenv(fn), stack[0], v31);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    stack[-1] = v31;
    v31 = stack[-2];
    v31 = qcdr(v31);
    v31 = qcar(v31);
    stack[0] = v31;
    v118 = stack[-1];
    v31 = stack[0];
    v31 = qcdr(v31);
    v31 = Lassoc(nil, v118, v31);
    stack[-3] = v31;
    v31 = stack[-3];
    if (v31 == nil) goto v124;
    v31 = stack[-3];
    v31 = qcdr(v31);
    { popv(5); return onevalue(v31); }

v124:
    v31 = stack[-2];
    v31 = qcdr(v31);
    v31 = qcdr(v31);
    v118 = qcar(v31);
    v31 = stack[-1];
    fn = elt(env, 3); /* calc_atlas */
    v31 = (*qfn2(fn))(qenv(fn), v118, v31);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    fn = elt(env, 4); /* reval */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    stack[-3] = v31;
    v118 = stack[-1];
    v31 = stack[-3];
    v31 = cons(v118, v31);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    v31 = ncons(v31);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    v31 = Lnconc(nil, stack[0], v31);
    nil = C_nil;
    if (exception_pending()) goto v123;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v123:
    popv(5);
    return nil;
}



/* Code for intargfn */

static Lisp_Object MS_CDECL CC_intargfn(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135, v47, v136, v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "intargfn");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intargfn");
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
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    v135 = stack[-3];
    v135 = qcdr(v135);
    stack[0] = v135;
    goto v27;

v27:
    v135 = stack[0];
    if (v135 == nil) goto v51;
    v135 = stack[0];
    v136 = qcar(v135);
    v47 = stack[-2];
    v135 = stack[-1];
    fn = elt(env, 4); /* form1 */
    v137 = (*qfnn(fn))(qenv(fn), 3, v136, v47, v135);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-5];
    v136 = stack[-2];
    v47 = elt(env, 1); /* integer */
    v135 = stack[-1];
    fn = elt(env, 5); /* convertmode1 */
    v47 = (*qfnn(fn))(qenv(fn), 4, v137, v136, v47, v135);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-5];
    v135 = stack[-4];
    v135 = cons(v47, v135);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-5];
    stack[-4] = v135;
    v135 = stack[0];
    v135 = qcdr(v135);
    stack[0] = v135;
    goto v27;

v51:
    stack[0] = elt(env, 2); /* list */
    v135 = stack[-3];
    v136 = qcar(v135);
    v47 = stack[-2];
    v135 = elt(env, 3); /* algebraic */
    fn = elt(env, 4); /* form1 */
    v47 = (*qfnn(fn))(qenv(fn), 3, v136, v47, v135);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-5];
    v135 = stack[-4];
    v135 = Lnreverse(nil, v135);
    {
        Lisp_Object v138 = stack[0];
        popv(6);
        return list2star(v138, v47, v135);
    }
/* error exit handlers */
v93:
    popv(6);
    return nil;
}



/* Code for mo!=pair */

static Lisp_Object CC_moMpair(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v124, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=pair");
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
    v141 = nil;
    goto v32;

v32:
    v124 = stack[-1];
    if (v124 == nil) goto v142;
    v124 = stack[0];
    if (v124 == nil) goto v142;
    v124 = stack[-1];
    v45 = qcar(v124);
    v124 = stack[0];
    v124 = qcar(v124);
    v141 = acons(v45, v124, v141);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    v124 = stack[-1];
    v124 = qcdr(v124);
    stack[-1] = v124;
    v124 = stack[0];
    v124 = qcdr(v124);
    stack[0] = v124;
    goto v32;

v142:
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v141);
    }
/* error exit handlers */
v53:
    popv(3);
    return nil;
}



/* Code for permp!: */

static Lisp_Object CC_permpT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v58, v33, v34;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for permp:");
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
    v58 = v1;
    v33 = v0;
/* end of prologue */

v35:
    v50 = v33;
    if (v50 == nil) goto v27;
    v50 = v33;
    v34 = qcar(v50);
    v50 = v58;
    v50 = qcar(v50);
    if (equal(v34, v50)) goto v16;
    v50 = v33;
    stack[0] = qcdr(v50);
    v50 = v58;
    v50 = qcar(v50);
    v33 = qcar(v33);
    v58 = qcdr(v58);
    v50 = Lsubst(nil, 3, v50, v33, v58);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-1];
    v50 = CC_permpT(env, stack[0], v50);
    nil = C_nil;
    if (exception_pending()) goto v144;
    v50 = (v50 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v50); }

v16:
    v50 = v33;
    v50 = qcdr(v50);
    v33 = v50;
    v50 = v58;
    v50 = qcdr(v50);
    v58 = v50;
    goto v35;

v27:
    v50 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v50); }
/* error exit handlers */
v144:
    popv(2);
    return nil;
}



/* Code for movebds */

static Lisp_Object MS_CDECL CC_movebds(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "movebds");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for movebds");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v53 = qvalue(elt(env, 1)); /* !*intp */
    v54 = stack[-1];
    fn = elt(env, 2); /* sgn1 */
    v53 = (*qfn2(fn))(qenv(fn), v53, v54);
    nil = C_nil;
    if (exception_pending()) goto v36;
    v54 = stack[0];
    if (equal(v53, v54)) goto v99;
    v53 = stack[-2];
    v54 = stack[-1];
        popv(3);
        return Lrplaca(nil, v53, v54);

v99:
    v53 = stack[-2];
    v54 = stack[-1];
        popv(3);
        return Lrplacd(nil, v53, v54);
/* error exit handlers */
v36:
    popv(3);
    return nil;
}



/* Code for ofsf_smeqtable */

static Lisp_Object CC_ofsf_smeqtable(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v133, v134, v132, v36, v37;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smeqtable");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v132 = v1;
    v36 = v0;
/* end of prologue */
    v53 = elt(env, 1); /* ((equal (equal . equal) (neq . false) (geq . equal) (leq . equal) (greaterp . false) (lessp . false)) (neq (neq . neq) (geq . greaterp) (leq . lessp) (greaterp . greaterp) (l
essp . lessp)) (geq (geq . geq) (leq . equal) (greaterp . greaterp) (lessp . false)) (leq (leq . leq) (greaterp . false) (lessp . lessp)) (greaterp (greaterp . greaterp) (lessp . false)) (lessp (lessp
 . lessp))) */
    v37 = v53;
    v134 = v132;
    v133 = v36;
    v53 = v37;
    v53 = Latsoc(nil, v133, v53);
    v53 = Latsoc(nil, v134, v53);
    if (!(v53 == nil)) goto v27;
    v53 = v36;
    v133 = v132;
    v134 = v37;
    v133 = Latsoc(nil, v133, v134);
    v53 = Latsoc(nil, v53, v133);
    goto v27;

v27:
    v53 = qcdr(v53);
    return onevalue(v53);
}



/* Code for mkarg */

static Lisp_Object CC_mkarg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v152;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkarg");
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
    v151 = stack[-1];
    if (v151 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v151 = stack[-1];
    v151 = Lconstantp(nil, v151);
    env = stack[-3];
    if (!(v151 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v151 = stack[-1];
    if (!consp(v151)) goto v127;
    v151 = stack[-1];
    v152 = qcar(v151);
    v151 = elt(env, 1); /* (quote !:dn!: !:int!:) */
    v151 = Lmemq(nil, v152, v151);
    if (v151 == nil) goto v37;
    v151 = stack[-1];
        popv(4);
        return Lmkquote(nil, v151);

v37:
    stack[-2] = nil;
    goto v51;

v51:
    v151 = stack[-1];
    if (v151 == nil) goto v92;
    v151 = stack[-1];
    v152 = qcar(v151);
    v151 = stack[0];
    v152 = CC_mkarg(env, v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    v151 = stack[-2];
    v151 = cons(v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    stack[-2] = v151;
    v151 = stack[-1];
    v151 = qcdr(v151);
    stack[-1] = v151;
    goto v51;

v92:
    v152 = elt(env, 2); /* list */
    v151 = stack[-2];
    v151 = Lnreverse(nil, v151);
    popv(4);
    return cons(v152, v151);

v127:
    v152 = stack[-1];
    v151 = stack[0];
    v151 = Latsoc(nil, v152, v151);
    if (!(v151 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v151 = stack[-1];
        popv(4);
        return Lmkquote(nil, v151);
/* error exit handlers */
v90:
    popv(4);
    return nil;
}



/* Code for product!-set2 */

static Lisp_Object CC_productKset2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v34;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for product-set2");
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
    v33 = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-2] = v33;
    goto v142;

v142:
    v33 = stack[-2];
    if (v33 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v33 = stack[-2];
    v33 = qcar(v33);
    stack[-1] = v33;
    v33 = stack[-3];
    stack[0] = v33;
    goto v99;

v99:
    v33 = stack[0];
    if (v33 == nil) goto v98;
    v33 = stack[0];
    v33 = qcar(v33);
    v34 = stack[-1];
    v34 = list2(v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-5];
    v33 = stack[-4];
    v33 = cons(v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-5];
    stack[-4] = v33;
    v33 = stack[0];
    v33 = qcdr(v33);
    stack[0] = v33;
    goto v99;

v98:
    v33 = stack[-2];
    v33 = qcdr(v33);
    stack[-2] = v33;
    goto v142;
/* error exit handlers */
v128:
    popv(6);
    return nil;
}



/* Code for ratnump */

static Lisp_Object CC_ratnump(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratnump");
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
    v56 = v0;
/* end of prologue */
    fn = elt(env, 2); /* simp!* */
    v57 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[0];
    v56 = v57;
    v57 = qcar(v57);
    if (!consp(v57)) goto v153;
    v56 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v56); }

v153:
    v56 = qcdr(v56);
    v56 = (consp(v56) ? nil : lisp_true);
    { popv(1); return onevalue(v56); }
/* error exit handlers */
v125:
    popv(1);
    return nil;
}



/* Code for dip!-nc!-ev!-prod */

static Lisp_Object MS_CDECL CC_dipKncKevKprod(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v52, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v121, v154, v141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "dip-nc-ev-prod");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip-nc-ev-prod");
#endif
    if (stack >= stacklimit)
    {
        push4(v52,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v60 = v52;
    v121 = v2;
    v154 = v1;
    v141 = v0;
/* end of prologue */
    stack[-2] = v154;
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[0] = v60;
    v60 = v141;
    fn = elt(env, 2); /* bcprod */
    v121 = (*qfn2(fn))(qenv(fn), v60, v121);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-3];
    v60 = qvalue(elt(env, 1)); /* nil */
    v60 = list2star(stack[0], v121, v60);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-3];
    {
        Lisp_Object v53 = stack[-2];
        Lisp_Object v133 = stack[-1];
        popv(4);
        fn = elt(env, 3); /* dip!-nc!-ev!-prod1 */
        return (*qfnn(fn))(qenv(fn), 3, v53, v133, v60);
    }
/* error exit handlers */
v54:
    popv(4);
    return nil;
}



/* Code for fortexp1 */

static Lisp_Object CC_fortexp1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v288, v289, v290;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fortexp1");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v1;
    stack[-1] = v0;
/* end of prologue */

v35:
    v288 = stack[-1];
    if (!consp(v288)) goto v27;
    v288 = stack[-1];
    fn = elt(env, 28); /* listp */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    if (v288 == nil) goto v56;
    v288 = stack[-1];
    v288 = Llength(nil, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = Lonep(nil, v288);
    env = stack[-9];
    if (v288 == nil) goto v56;
    v288 = stack[-1];
    {
        popv(10);
        fn = elt(env, 29); /* fortranname */
        return (*qfn1(fn))(qenv(fn), v288);
    }

v56:
    v288 = stack[-1];
    v288 = qcar(v288);
    fn = elt(env, 30); /* optype */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    if (v288 == nil) goto v104;
    v288 = stack[-1];
    v288 = qcar(v288);
    fn = elt(env, 31); /* fortranprecedence */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[-4] = v288;
    v288 = stack[-1];
    v288 = qcar(v288);
    fn = elt(env, 32); /* fortranop */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[-2] = v288;
    v288 = stack[-1];
    v288 = qcdr(v288);
    stack[-1] = v288;
    v288 = stack[-1];
    v288 = Llength(nil, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = Lonep(nil, v288);
    env = stack[-9];
    if (v288 == nil) goto v96;
    stack[0] = stack[-2];
    v288 = stack[-1];
    v289 = qcar(v288);
    v288 = stack[-4];
    v288 = CC_fortexp1(env, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = cons(stack[0], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[0] = v288;
    goto v64;

v64:
    v289 = stack[-3];
    v288 = stack[-4];
    v288 = (Lisp_Object)geq2(v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    v288 = v288 ? lisp_true : nil;
    env = stack[-9];
    if (v288 == nil) { Lisp_Object res = stack[0]; popv(10); return onevalue(res); }
    v288 = stack[0];
    fn = elt(env, 33); /* insertparens */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    stack[0] = v288;
    { Lisp_Object res = stack[0]; popv(10); return onevalue(res); }

v96:
    v288 = stack[-1];
    v289 = qcar(v288);
    v288 = stack[-4];
    v288 = CC_fortexp1(env, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[0] = v288;
    v289 = stack[-2];
    v288 = elt(env, 1); /* !+ */
    if (v289 == v288) goto v91;
    v289 = stack[-2];
    v288 = elt(env, 4); /* !*!* */
    if (!(v289 == v288)) goto v292;

v293:
    v288 = stack[-1];
    v288 = qcdr(v288);
    stack[-1] = v288;
    if (v288 == nil) goto v64;
    v288 = stack[-1];
    v288 = qcar(v288);
    if (!(is_number(v288))) goto v294;
    v288 = stack[-1];
    v289 = qcar(v288);
    v288 = (Lisp_Object)1; /* 0 */
    v288 = (Lisp_Object)lessp2(v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    v288 = v288 ? lisp_true : nil;
    env = stack[-9];
    if (v288 == nil) goto v294;
    v288 = stack[-2];
    v288 = ncons(v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[0] = Lappend(nil, stack[0], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = stack[-1];
    v289 = qcar(v288);
    v288 = stack[-4];
    v288 = CC_fortexp1(env, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    fn = elt(env, 33); /* insertparens */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = Lappend(nil, stack[0], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[0] = v288;
    goto v293;

v294:
    v288 = stack[-2];
    v288 = ncons(v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[0] = Lappend(nil, stack[0], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = stack[-1];
    v289 = qcar(v288);
    v288 = stack[-4];
    v288 = CC_fortexp1(env, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = Lappend(nil, stack[0], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[0] = v288;
    goto v293;

v292:
    v288 = stack[-1];
    v288 = qcdr(v288);
    stack[-1] = v288;
    if (v288 == nil) goto v64;
    v288 = stack[-2];
    v288 = ncons(v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[0] = Lappend(nil, stack[0], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = stack[-1];
    v289 = qcar(v288);
    v288 = stack[-4];
    v288 = CC_fortexp1(env, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = Lappend(nil, stack[0], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[0] = v288;
    goto v292;

v91:
    v288 = stack[-1];
    v288 = qcdr(v288);
    stack[-1] = v288;
    if (v288 == nil) goto v64;
    v288 = stack[-1];
    v288 = qcar(v288);
    if (!consp(v288)) goto v295;
    v288 = stack[-1];
    v288 = qcar(v288);
    v289 = qcar(v288);
    v288 = elt(env, 3); /* minus */
    if (!(v289 == v288)) goto v295;

v296:
    v288 = stack[-1];
    v289 = qcar(v288);
    v288 = stack[-4];
    v288 = CC_fortexp1(env, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = Lappend(nil, stack[0], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[0] = v288;
    goto v91;

v295:
    v288 = stack[-2];
    v288 = ncons(v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = Lappend(nil, stack[0], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[0] = v288;
    goto v296;

v104:
    v288 = stack[-1];
    v289 = qcar(v288);
    v288 = elt(env, 5); /* literal */
    if (v289 == v288) goto v102;
    v288 = stack[-1];
    v289 = qcar(v288);
    v288 = elt(env, 6); /* range */
    if (v289 == v288) goto v297;
    v288 = stack[-1];
    v289 = qcar(v288);
    v288 = elt(env, 8); /* !:rd!: */
    if (v289 == v288) goto v298;
    v288 = stack[-1];
    v289 = qcar(v288);
    v288 = elt(env, 17); /* !:crn!: */
    if (v289 == v288) goto v299;
    v288 = stack[-1];
    v289 = qcar(v288);
    v288 = elt(env, 18); /* !:gi!: */
    if (v289 == v288) goto v300;
    v288 = stack[-1];
    v289 = qcar(v288);
    v288 = elt(env, 19); /* !:cr!: */
    if (v289 == v288) goto v301;
    v288 = stack[-1];
    v289 = qcar(v288);
    v288 = elt(env, 25); /* !*fortranname!* */
    v288 = get(v289, v288);
    env = stack[-9];
    stack[-7] = v288;
    v288 = stack[-1];
    v288 = qcar(v288);
    fn = elt(env, 29); /* fortranname */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[-8] = v288;
    v288 = stack[-1];
    v288 = qcdr(v288);
    stack[-1] = v288;
    v288 = stack[-1];
    stack[-6] = v288;
    goto v302;

v302:
    v288 = stack[-6];
    if (v288 == nil) goto v303;
    v288 = stack[-6];
    v288 = qcar(v288);
    stack[-2] = v288;
    stack[-1] = elt(env, 22); /* !, */
    v288 = stack[-7];
    if (v288 == nil) goto v304;
    v288 = stack[-2];
    v288 = integerp(v288);
    if (v288 == nil) goto v305;
    v288 = stack[-2];
    v288 = Lfloat(nil, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = ncons(v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    goto v306;

v306:
    v288 = cons(stack[-1], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[-5] = v288;
    v288 = stack[-5];
    fn = elt(env, 34); /* lastpair */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[-4] = v288;
    v288 = stack[-6];
    v288 = qcdr(v288);
    stack[-6] = v288;
    v288 = stack[-4];
    if (!consp(v288)) goto v302;
    else goto v307;

v307:
    v288 = stack[-6];
    if (v288 == nil) goto v308;
    stack[-3] = stack[-4];
    v288 = stack[-6];
    v288 = qcar(v288);
    stack[-2] = v288;
    stack[-1] = elt(env, 22); /* !, */
    v288 = stack[-7];
    if (v288 == nil) goto v309;
    v288 = stack[-2];
    v288 = integerp(v288);
    if (v288 == nil) goto v310;
    v288 = stack[-2];
    v288 = Lfloat(nil, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = ncons(v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    goto v311;

v311:
    v288 = cons(stack[-1], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = Lrplacd(nil, stack[-3], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = stack[-4];
    fn = elt(env, 34); /* lastpair */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[-4] = v288;
    v288 = stack[-6];
    v288 = qcdr(v288);
    stack[-6] = v288;
    goto v307;

v310:
    v288 = stack[-2];
    fn = elt(env, 35); /* isfloat */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    if (!(v288 == nil)) goto v312;
    v289 = stack[-8];
    v288 = elt(env, 26); /* (real dble) */
    v288 = Lmemq(nil, v289, v288);
    if (!(v288 == nil)) goto v312;
    v288 = elt(env, 27); /* real */
    fn = elt(env, 29); /* fortranname */
    stack[0] = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v289 = stack[-2];
    v288 = (Lisp_Object)1; /* 0 */
    v288 = CC_fortexp1(env, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    fn = elt(env, 33); /* insertparens */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = cons(stack[0], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    goto v311;

v312:
    v289 = stack[-2];
    v288 = (Lisp_Object)1; /* 0 */
    v288 = CC_fortexp1(env, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    goto v311;

v309:
    v289 = stack[-2];
    v288 = (Lisp_Object)1; /* 0 */
    v288 = CC_fortexp1(env, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    goto v311;

v308:
    v288 = stack[-5];
    goto v313;

v313:
    v288 = qcdr(v288);
    stack[0] = stack[-8];
    fn = elt(env, 33); /* insertparens */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    {
        Lisp_Object v314 = stack[0];
        popv(10);
        return cons(v314, v288);
    }

v305:
    v288 = stack[-2];
    fn = elt(env, 35); /* isfloat */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    if (!(v288 == nil)) goto v315;
    v289 = stack[-8];
    v288 = elt(env, 26); /* (real dble) */
    v288 = Lmemq(nil, v289, v288);
    if (!(v288 == nil)) goto v315;
    v288 = elt(env, 27); /* real */
    fn = elt(env, 29); /* fortranname */
    stack[0] = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v289 = stack[-2];
    v288 = (Lisp_Object)1; /* 0 */
    v288 = CC_fortexp1(env, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    fn = elt(env, 33); /* insertparens */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = cons(stack[0], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    goto v306;

v315:
    v289 = stack[-2];
    v288 = (Lisp_Object)1; /* 0 */
    v288 = CC_fortexp1(env, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    goto v306;

v304:
    v289 = stack[-2];
    v288 = (Lisp_Object)1; /* 0 */
    v288 = CC_fortexp1(env, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    goto v306;

v303:
    v288 = qvalue(elt(env, 2)); /* nil */
    goto v313;

v301:
    v288 = qvalue(elt(env, 13)); /* !*double */
    if (v288 == nil) goto v316;
    v288 = qvalue(elt(env, 20)); /* !*f90 */
    if (v288 == nil) goto v316;
    stack[-4] = elt(env, 21); /* cmplx!( */
    v289 = elt(env, 8); /* !:rd!: */
    v288 = stack[-1];
    v288 = qcdr(v288);
    v288 = qcar(v288);
    v289 = cons(v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = stack[-3];
    stack[-2] = CC_fortexp1(env, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[0] = elt(env, 22); /* !, */
    v289 = elt(env, 8); /* !:rd!: */
    v288 = stack[-1];
    v288 = qcdr(v288);
    v288 = qcdr(v288);
    v289 = cons(v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = stack[-3];
    stack[-1] = CC_fortexp1(env, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v290 = elt(env, 22); /* !, */
    v289 = elt(env, 23); /* kind!(1!.0!D0!) */
    v288 = elt(env, 24); /* !) */
    v288 = list3(v290, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = Lappend(nil, stack[-1], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = cons(stack[0], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = Lappend(nil, stack[-2], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    {
        Lisp_Object v317 = stack[-4];
        popv(10);
        return cons(v317, v288);
    }

v316:
    stack[-4] = elt(env, 21); /* cmplx!( */
    v289 = elt(env, 8); /* !:rd!: */
    v288 = stack[-1];
    v288 = qcdr(v288);
    v288 = qcar(v288);
    v289 = cons(v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = stack[-3];
    stack[-2] = CC_fortexp1(env, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[0] = elt(env, 22); /* !, */
    v289 = elt(env, 8); /* !:rd!: */
    v288 = stack[-1];
    v288 = qcdr(v288);
    v288 = qcdr(v288);
    v289 = cons(v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = stack[-3];
    stack[-1] = CC_fortexp1(env, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = elt(env, 24); /* !) */
    v288 = ncons(v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = Lappend(nil, stack[-1], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = cons(stack[0], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = Lappend(nil, stack[-2], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    {
        Lisp_Object v318 = stack[-4];
        popv(10);
        return cons(v318, v288);
    }

v300:
    v288 = stack[-1];
    fn = elt(env, 36); /* !*gi2cr */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[-1] = v288;
    goto v35;

v299:
    v288 = stack[-1];
    fn = elt(env, 37); /* !*crn2cr */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[-1] = v288;
    goto v35;

v298:
    v288 = stack[-1];
    v288 = qcdr(v288);
    if (!consp(v288)) goto v319;
    stack[-3] = qvalue(elt(env, 9)); /* !:lower!-sci!: */
    qvalue(elt(env, 9)) = nil; /* !:lower!-sci!: */
    stack[-2] = qvalue(elt(env, 10)); /* !:upper!-sci!: */
    qvalue(elt(env, 10)) = nil; /* !:upper!-sci!: */
    v288 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 9)) = v288; /* !:lower!-sci!: */
    v288 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 10)) = v288; /* !:upper!-sci!: */
    v288 = stack[-1];
    v288 = qcdr(v288);
    if (!consp(v288)) goto v320;
    v288 = stack[-1];
    stack[0] = v288;
    goto v321;

v321:
    v289 = qvalue(elt(env, 11)); /* !:bprec!: */
    v288 = (Lisp_Object)49; /* 3 */
    v288 = difference2(v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-9];
    fn = elt(env, 38); /* round!:mt */
    v288 = (*qfn2(fn))(qenv(fn), stack[0], v288);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-9];
    fn = elt(env, 39); /* csl_normbf */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-9];
    fn = elt(env, 40); /* bfexplode0 */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-9];
    stack[-4] = v288;
    v288 = stack[-4];
    v288 = qcar(v288);
    stack[-1] = v288;
    v288 = stack[-4];
    v288 = qcdr(v288);
    stack[0] = qcar(v288);
    v288 = stack[-4];
    v288 = qcdr(v288);
    v288 = qcdr(v288);
    v288 = qcar(v288);
    v288 = sub1(v288);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-9];
    v288 = plus2(stack[0], v288);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-9];
    stack[-4] = v288;
    v290 = elt(env, 5); /* literal */
    v288 = stack[-1];
    v289 = qcar(v288);
    v288 = elt(env, 12); /* !. */
    v289 = list3(v290, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-9];
    v288 = stack[-1];
    v288 = qcdr(v288);
    v288 = Lappend(nil, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-9];
    stack[-1] = v288;
    v289 = stack[-4];
    v288 = (Lisp_Object)1; /* 0 */
    if (v289 == v288) goto v323;
    stack[0] = stack[-1];
    v288 = qvalue(elt(env, 13)); /* !*double */
    if (v288 == nil) goto v324;
    v288 = elt(env, 14); /* !D */
    v289 = v288;
    goto v325;

v325:
    v288 = stack[-4];
    v288 = list2(v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-9];
    v288 = Lappend(nil, stack[0], v288);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-9];
    stack[-1] = v288;
    goto v326;

v326:
    v288 = stack[-1];
    fn = elt(env, 41); /* fortliteral */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-9];
    qvalue(elt(env, 10)) = stack[-2]; /* !:upper!-sci!: */
    qvalue(elt(env, 9)) = stack[-3]; /* !:lower!-sci!: */
    { popv(10); return onevalue(v288); }

v324:
    v288 = elt(env, 15); /* !E */
    v289 = v288;
    goto v325;

v323:
    v288 = qvalue(elt(env, 13)); /* !*double */
    if (v288 == nil) goto v326;
    v289 = stack[-1];
    v288 = elt(env, 16); /* (!D 0) */
    v288 = Lappend(nil, v289, v288);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-9];
    stack[-1] = v288;
    goto v326;

v320:
    v288 = stack[-1];
    v288 = qcdr(v288);
    fn = elt(env, 42); /* fl2bf */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v322;
    env = stack[-9];
    stack[0] = v288;
    goto v321;

v319:
    v288 = stack[-1];
    v288 = qcdr(v288);
    popv(10);
    return ncons(v288);

v297:
    v288 = stack[-1];
    v288 = qcdr(v288);
    v288 = qcar(v288);
    fn = elt(env, 43); /* fortexp */
    stack[-2] = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    stack[0] = elt(env, 7); /* !: */
    v288 = stack[-1];
    v288 = qcdr(v288);
    v288 = qcdr(v288);
    v288 = qcar(v288);
    fn = elt(env, 43); /* fortexp */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-9];
    v288 = cons(stack[0], v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    {
        Lisp_Object v327 = stack[-2];
        popv(10);
        return Lappend(nil, v327, v288);
    }

v102:
    v288 = stack[-1];
    {
        popv(10);
        fn = elt(env, 41); /* fortliteral */
        return (*qfn1(fn))(qenv(fn), v288);
    }

v27:
    v288 = stack[-1];
    fn = elt(env, 29); /* fortranname */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v291;
    popv(10);
    return ncons(v288);
/* error exit handlers */
v322:
    env = stack[-9];
    qvalue(elt(env, 10)) = stack[-2]; /* !:upper!-sci!: */
    qvalue(elt(env, 9)) = stack[-3]; /* !:lower!-sci!: */
    popv(10);
    return nil;
v291:
    popv(10);
    return nil;
}



/* Code for store_edges */

static Lisp_Object CC_store_edges(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v128;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for store_edges");
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
    v119 = v0;
/* end of prologue */
    stack[-3] = v119;
    v119 = stack[-3];
    if (v119 == nil) goto v17;
    v119 = stack[-3];
    v119 = qcar(v119);
    v128 = v119;
    v128 = qcar(v128);
    v119 = qcdr(v119);
    v119 = cons(v128, v119);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-4];
    v119 = ncons(v119);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-4];
    stack[-1] = v119;
    stack[-2] = v119;
    goto v29;

v29:
    v119 = stack[-3];
    v119 = qcdr(v119);
    stack[-3] = v119;
    v119 = stack[-3];
    if (v119 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v119 = stack[-3];
    v119 = qcar(v119);
    v128 = v119;
    v128 = qcar(v128);
    v119 = qcdr(v119);
    v119 = cons(v128, v119);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-4];
    v119 = ncons(v119);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-4];
    v119 = Lrplacd(nil, stack[0], v119);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-4];
    v119 = stack[-1];
    v119 = qcdr(v119);
    stack[-1] = v119;
    goto v29;

v17:
    v119 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v119); }
/* error exit handlers */
v328:
    popv(5);
    return nil;
}



/* Code for ezgcd!-comfac */

static Lisp_Object CC_ezgcdKcomfac(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v332, v293, v333;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ezgcd-comfac");
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
    v332 = stack[-1];
    if (!consp(v332)) goto v16;
    v332 = stack[-1];
    v332 = qcar(v332);
    if (!consp(v332)) goto v16;
    v332 = stack[-1];
    v332 = qcdr(v332);
    if (v332 == nil) goto v38;
    stack[-2] = nil;
    v333 = nil;
    v332 = stack[-1];
    v332 = qcar(v332);
    v332 = qcar(v332);
    v332 = qcar(v332);
    stack[0] = v332;
    goto v61;

v61:
    v332 = stack[-1];
    v332 = qcar(v332);
    v332 = qcar(v332);
    v293 = qcar(v332);
    v332 = stack[0];
    if (!(equal(v293, v332))) goto v334;
    v332 = stack[-1];
    v332 = qcdr(v332);
    if (!consp(v332)) goto v334;
    v332 = stack[-1];
    v332 = qcdr(v332);
    v332 = qcar(v332);
    if (!consp(v332)) goto v334;
    v332 = stack[-1];
    v332 = qcar(v332);
    v332 = qcdr(v332);
    v293 = v333;
    v332 = cons(v332, v293);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    v333 = v332;
    v332 = stack[-1];
    v332 = qcdr(v332);
    stack[-1] = v332;
    goto v61;

v334:
    v332 = stack[-1];
    v332 = qcar(v332);
    v332 = qcar(v332);
    v293 = qcar(v332);
    v332 = stack[0];
    if (equal(v293, v332)) goto v335;
    v332 = stack[-1];
    v293 = v333;
    v332 = cons(v332, v293);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    v333 = v332;
    goto v336;

v336:
    stack[0] = stack[-2];
    v332 = v333;
    fn = elt(env, 2); /* gcdlist */
    v332 = (*qfn1(fn))(qenv(fn), v332);
    nil = C_nil;
    if (exception_pending()) goto v111;
    {
        Lisp_Object v337 = stack[0];
        popv(4);
        return cons(v337, v332);
    }

v335:
    v332 = stack[-1];
    v332 = qcar(v332);
    v332 = qcdr(v332);
    v293 = v333;
    v332 = cons(v332, v293);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    v333 = v332;
    v332 = stack[-1];
    v332 = qcdr(v332);
    if (v332 == nil) goto v20;
    v332 = stack[-1];
    v332 = qcdr(v332);
    v293 = v333;
    v332 = cons(v332, v293);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    v333 = v332;
    goto v336;

v20:
    v332 = stack[-1];
    v332 = qcar(v332);
    v332 = qcar(v332);
    stack[-2] = v332;
    goto v336;

v38:
    v332 = stack[-1];
    v332 = qcar(v332);
    stack[0] = qcar(v332);
    v332 = stack[-1];
    v332 = qcar(v332);
    v332 = qcdr(v332);
    fn = elt(env, 3); /* poly!-abs */
    v332 = (*qfn1(fn))(qenv(fn), v332);
    nil = C_nil;
    if (exception_pending()) goto v111;
    {
        Lisp_Object v338 = stack[0];
        popv(4);
        return cons(v338, v332);
    }

v16:
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v332 = stack[-1];
    fn = elt(env, 3); /* poly!-abs */
    v332 = (*qfn1(fn))(qenv(fn), v332);
    nil = C_nil;
    if (exception_pending()) goto v111;
    {
        Lisp_Object v339 = stack[0];
        popv(4);
        return cons(v339, v332);
    }
/* error exit handlers */
v111:
    popv(4);
    return nil;
}



/* Code for linineqevaltest */

static Lisp_Object CC_linineqevaltest(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v109, v135, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for linineqevaltest");
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
    v109 = v1;
    v135 = v0;
/* end of prologue */

v32:
    v28 = v135;
    if (!consp(v28)) { popv(2); return onevalue(v109); }
    v28 = v135;
    v28 = qcar(v28);
    if (!consp(v28)) { popv(2); return onevalue(v109); }
    v28 = v135;
    v28 = qcar(v28);
    v28 = qcar(v28);
    v47 = qcdr(v28);
    v28 = (Lisp_Object)17; /* 1 */
    if (v47 == v28) goto v133;
    v28 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 1)) = v28; /* !*ineqerr */
    v28 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v28 == nil)) goto v60;
    v28 = elt(env, 3); /* "unable to process nonlinear system" */
    fn = elt(env, 4); /* lprie */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-1];
    goto v60;

v60:
    v28 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v137;
    v28 = nil;
    { popv(2); return onevalue(v28); }

v133:
    v28 = v135;
    v28 = qcar(v28);
    v28 = qcar(v28);
    v47 = qcar(v28);
    v28 = v109;
    v28 = Lmember(nil, v47, v28);
    if (v28 == nil) goto v34;
    v28 = v135;
    v28 = qcdr(v28);
    v135 = v28;
    goto v32;

v34:
    v28 = v135;
    v28 = qcdr(v28);
    stack[0] = v28;
    v28 = v135;
    v28 = qcar(v28);
    v28 = qcar(v28);
    v28 = qcar(v28);
    v28 = cons(v28, v109);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-1];
    v109 = v28;
    v28 = stack[0];
    v135 = v28;
    goto v32;
/* error exit handlers */
v137:
    popv(2);
    return nil;
}



/* Code for chrstrem */

static Lisp_Object CC_chrstrem(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v362, v363;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chrstrem");
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
    v362 = qvalue(elt(env, 1)); /* !*trwu */
    if (!(v362 == nil)) goto v153;
    v362 = qvalue(elt(env, 2)); /* !*trchrstrem */
    if (!(v362 == nil)) goto v153;

v99:
    v362 = stack[-3];
    fn = elt(env, 15); /* wusort */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    stack[-3] = v362;
    v362 = qvalue(elt(env, 1)); /* !*trwu */
    if (!(v362 == nil)) goto v140;
    v362 = qvalue(elt(env, 2)); /* !*trchrstrem */
    if (!(v362 == nil)) goto v140;

v3:
    v362 = stack[-3];
    v362 = qcar(v362);
    fn = elt(env, 16); /* wuconstantp */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    if (v362 == nil) goto v287;
    v362 = qvalue(elt(env, 1)); /* !*trwu */
    if (v362 == nil) goto v94;
    v362 = elt(env, 7); /* "which is trivially trivial" */
    fn = elt(env, 17); /* prin2t!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v94;

v94:
    v362 = elt(env, 8); /* inconsistent */
    stack[-2] = v362;
    v362 = (Lisp_Object)17; /* 1 */
    v362 = ncons(v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    stack[-4] = v362;
    goto v123;

v123:
    v362 = qvalue(elt(env, 1)); /* !*trwu */
    if (v362 == nil) goto v15;
    v362 = stack[-2];
    if (!(v362 == nil)) goto v15;
    v362 = elt(env, 9); /* "A basic set is" */
    fn = elt(env, 17); /* prin2t!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    v362 = stack[-4];
    v362 = Lreverse(nil, v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    stack[0] = v362;
    goto v365;

v365:
    v362 = stack[0];
    if (v362 == nil) goto v366;
    v362 = stack[0];
    v362 = qcar(v362);
    v363 = v362;
    v362 = v363;
    if (v362 == nil) goto v24;
    v362 = v363;
    fn = elt(env, 18); /* xprinf2 */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v367;

v367:
    v362 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 19); /* terpri!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    v362 = stack[0];
    v362 = qcdr(v362);
    stack[0] = v362;
    goto v365;

v24:
    v362 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 20); /* prin2!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v367;

v366:
    v362 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 19); /* terpri!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v15;

v15:
    v363 = stack[-3];
    v362 = stack[-4];
    fn = elt(env, 21); /* setdiff */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    stack[-1] = v362;
    goto v368;

v368:
    v362 = stack[-1];
    if (v362 == nil) goto v282;
    v362 = stack[-1];
    v362 = qcar(v362);
    stack[0] = v362;
    v363 = stack[-2];
    v362 = elt(env, 8); /* inconsistent */
    if (v363 == v362) goto v12;
    v362 = qvalue(elt(env, 1)); /* !*trwu */
    if (v362 == nil) goto v369;
    v362 = elt(env, 10); /* "The remainder of " */
    fn = elt(env, 20); /* prin2!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    v362 = stack[0];
    if (v362 == nil) goto v370;
    v362 = stack[0];
    fn = elt(env, 18); /* xprinf2 */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v43;

v43:
    v362 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 19); /* terpri!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    v362 = elt(env, 11); /* "wrt the basic set is " */
    fn = elt(env, 20); /* prin2!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v369;

v369:
    v363 = stack[0];
    v362 = stack[-4];
    fn = elt(env, 22); /* findremainder */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    stack[0] = v362;
    v362 = qvalue(elt(env, 1)); /* !*trwu */
    if (v362 == nil) goto v371;
    v362 = stack[0];
    if (v362 == nil) goto v372;
    v362 = stack[0];
    fn = elt(env, 18); /* xprinf2 */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v373;

v373:
    v362 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 19); /* terpri!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v371;

v371:
    v362 = stack[0];
    if (v362 == nil) goto v12;
    v362 = stack[0];
    fn = elt(env, 16); /* wuconstantp */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    if (v362 == nil) goto v70;
    v362 = elt(env, 8); /* inconsistent */
    stack[-2] = v362;
    v362 = qvalue(elt(env, 1)); /* !*trwu */
    if (v362 == nil) goto v12;
    v362 = elt(env, 12); /* "which is a non-zero constant, and so" */
    v362 = Lprinc(nil, v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    v362 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    v362 = elt(env, 13); /* "the equations are inconsistent." */
    v362 = Lprinc(nil, v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    v362 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v12;

v12:
    v362 = stack[-1];
    v362 = qcdr(v362);
    stack[-1] = v362;
    goto v368;

v70:
    v362 = stack[0];
    fn = elt(env, 23); /* minusf */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    if (v362 == nil) goto v374;
    v362 = stack[0];
    fn = elt(env, 24); /* negf */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v375;

v375:
    v363 = ncons(v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    v362 = stack[-2];
    fn = elt(env, 25); /* union */
    v362 = (*qfn2(fn))(qenv(fn), v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    stack[-2] = v362;
    goto v12;

v374:
    v362 = stack[0];
    goto v375;

v372:
    v362 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 20); /* prin2!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v373;

v370:
    v362 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 20); /* prin2!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v43;

v282:
    v362 = stack[-2];
    if (v362 == nil) goto v269;
    v363 = stack[-2];
    v362 = elt(env, 8); /* inconsistent */
    if (v363 == v362) goto v269;
    v363 = stack[-3];
    v362 = stack[-2];
    v362 = Lappend(nil, v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    stack[-3] = v362;
    goto v269;

v269:
    v362 = stack[-2];
    if (v362 == nil) goto v376;
    v363 = stack[-2];
    v362 = elt(env, 8); /* inconsistent */
    if (!(v363 == v362)) goto v99;

v376:
    v363 = stack[-2];
    v362 = elt(env, 8); /* inconsistent */
    if (!(v363 == v362)) goto v260;
    v362 = (Lisp_Object)17; /* 1 */
    v362 = ncons(v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    stack[-4] = v362;
    goto v260;

v260:
    v362 = qvalue(elt(env, 1)); /* !*trwu */
    if (!(v362 == nil)) goto v377;
    v362 = qvalue(elt(env, 2)); /* !*trchrstrem */
    if (!(v362 == nil)) goto v377;

v378:
    v362 = stack[-4];
    stack[-4] = v362;
    v362 = stack[-4];
    if (v362 == nil) goto v379;
    v362 = stack[-4];
    v362 = qcar(v362);
    stack[0] = v362;
    v362 = stack[0];
    fn = elt(env, 23); /* minusf */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    if (v362 == nil) goto v380;
    v362 = stack[0];
    fn = elt(env, 24); /* negf */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v381;

v381:
    v362 = ncons(v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    stack[-2] = v362;
    stack[-3] = v362;
    goto v321;

v321:
    v362 = stack[-4];
    v362 = qcdr(v362);
    stack[-4] = v362;
    v362 = stack[-4];
    if (v362 == nil) goto v382;
    stack[-1] = stack[-2];
    v362 = stack[-4];
    v362 = qcar(v362);
    stack[0] = v362;
    v362 = stack[0];
    fn = elt(env, 23); /* minusf */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    if (v362 == nil) goto v383;
    v362 = stack[0];
    fn = elt(env, 24); /* negf */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v384;

v384:
    v362 = ncons(v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    v362 = Lrplacd(nil, stack[-1], v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    v362 = stack[-2];
    v362 = qcdr(v362);
    stack[-2] = v362;
    goto v321;

v383:
    v362 = stack[0];
    goto v384;

v382:
    v362 = stack[-3];
    goto v255;

v255:
        popv(6);
        return Lnreverse(nil, v362);

v380:
    v362 = stack[0];
    goto v381;

v379:
    v362 = qvalue(elt(env, 5)); /* nil */
    goto v255;

v377:
    v362 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 19); /* terpri!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    v362 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 19); /* terpri!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    v362 = elt(env, 14); /* "The final characteristic set is:" */
    fn = elt(env, 17); /* prin2t!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    v362 = stack[-4];
    v362 = Lreverse(nil, v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    stack[0] = v362;
    goto v385;

v385:
    v362 = stack[0];
    if (v362 == nil) goto v378;
    v362 = stack[0];
    v362 = qcar(v362);
    v363 = v362;
    v362 = v363;
    if (v362 == nil) goto v386;
    v362 = v363;
    fn = elt(env, 18); /* xprinf2 */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v387;

v387:
    v362 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 19); /* terpri!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    v362 = stack[0];
    v362 = qcdr(v362);
    stack[0] = v362;
    goto v385;

v386:
    v362 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 20); /* prin2!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v387;

v287:
    v362 = qvalue(elt(env, 5)); /* nil */
    stack[-2] = v362;
    v362 = stack[-3];
    fn = elt(env, 26); /* pickbasicset */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    v362 = Lnreverse(nil, v362);
    env = stack[-5];
    stack[-4] = v362;
    goto v123;

v140:
    v362 = elt(env, 6); /* "The new pol-set in ascending order is" */
    fn = elt(env, 17); /* prin2t!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    v362 = stack[-3];
    stack[0] = v362;
    goto v145;

v145:
    v362 = stack[0];
    if (v362 == nil) goto v45;
    v362 = stack[0];
    v362 = qcar(v362);
    v363 = v362;
    v362 = v363;
    if (v362 == nil) goto v50;
    v362 = v363;
    fn = elt(env, 18); /* xprinf2 */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v51;

v51:
    v362 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 19); /* terpri!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    v362 = stack[0];
    v362 = qcdr(v362);
    stack[0] = v362;
    goto v145;

v50:
    v362 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 20); /* prin2!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v51;

v45:
    v362 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 19); /* terpri!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v3;

v153:
    v362 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 19); /* terpri!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    v362 = elt(env, 4); /* "--------------------------------------------------------" 
*/
    fn = elt(env, 17); /* prin2t!* */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v364;
    env = stack[-5];
    goto v99;
/* error exit handlers */
v364:
    popv(6);
    return nil;
}



/* Code for multtaylor1 */

static Lisp_Object MS_CDECL CC_multtaylor1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v404, v405, v406;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "multtaylor1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multtaylor1");
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
    stack[-7] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-6] = nil;
    v404 = stack[-3];
    stack[-5] = v404;
    v404 = stack[-5];
    if (v404 == nil) goto v147;
    v404 = stack[-5];
    v404 = qcar(v404);
    v404 = qcdr(v404);
    v404 = qcdr(v404);
    v404 = qcar(v404);
    v404 = ncons(v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[-1] = v404;
    stack[-4] = v404;
    goto v125;

v125:
    v404 = stack[-5];
    v404 = qcdr(v404);
    stack[-5] = v404;
    v404 = stack[-5];
    if (v404 == nil) goto v124;
    stack[0] = stack[-1];
    v404 = stack[-5];
    v404 = qcar(v404);
    v404 = qcdr(v404);
    v404 = qcdr(v404);
    v404 = qcar(v404);
    v404 = ncons(v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v404 = Lrplacd(nil, stack[0], v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v404 = stack[-1];
    v404 = qcdr(v404);
    stack[-1] = v404;
    goto v125;

v124:
    v404 = stack[-4];
    goto v57;

v57:
    stack[-4] = v404;
    v404 = stack[-3];
    stack[-5] = v404;
    v404 = stack[-5];
    if (v404 == nil) goto v46;
    v404 = stack[-5];
    v404 = qcar(v404);
    v404 = qcdr(v404);
    v404 = qcdr(v404);
    v404 = qcdr(v404);
    v404 = qcar(v404);
    v404 = ncons(v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[-1] = v404;
    stack[-3] = v404;
    goto v30;

v30:
    v404 = stack[-5];
    v404 = qcdr(v404);
    stack[-5] = v404;
    v404 = stack[-5];
    if (v404 == nil) goto v151;
    stack[0] = stack[-1];
    v404 = stack[-5];
    v404 = qcar(v404);
    v404 = qcdr(v404);
    v404 = qcdr(v404);
    v404 = qcdr(v404);
    v404 = qcar(v404);
    v404 = ncons(v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v404 = Lrplacd(nil, stack[0], v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v404 = stack[-1];
    v404 = qcdr(v404);
    stack[-1] = v404;
    goto v30;

v151:
    v404 = stack[-3];
    goto v107;

v107:
    stack[-5] = v404;
    v404 = stack[-2];
    stack[-3] = v404;
    goto v330;

v330:
    v404 = stack[-3];
    if (v404 == nil) goto v408;
    v404 = stack[-3];
    v404 = qcar(v404);
    stack[-2] = v404;
    v404 = stack[-7];
    stack[-1] = v404;
    goto v23;

v23:
    v404 = stack[-1];
    if (v404 == nil) goto v22;
    v404 = stack[-1];
    v404 = qcar(v404);
    stack[0] = v404;
    v404 = stack[-2];
    v405 = qcar(v404);
    v404 = stack[0];
    v404 = qcar(v404);
    fn = elt(env, 2); /* add!-degrees */
    v404 = (*qfn2(fn))(qenv(fn), v405, v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[-8] = v404;
    v405 = stack[-5];
    v404 = stack[-8];
    fn = elt(env, 3); /* exceeds!-order */
    v404 = (*qfn2(fn))(qenv(fn), v405, v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    if (v404 == nil) goto v337;
    v406 = stack[-5];
    v405 = stack[-4];
    v404 = stack[-8];
    fn = elt(env, 4); /* min2!-order */
    v404 = (*qfnn(fn))(qenv(fn), 3, v406, v405, v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[-5] = v404;
    goto v359;

v359:
    v404 = stack[-1];
    v404 = qcdr(v404);
    stack[-1] = v404;
    goto v23;

v337:
    v404 = stack[-2];
    v405 = qcdr(v404);
    v404 = stack[0];
    v404 = qcdr(v404);
    fn = elt(env, 5); /* multsq */
    v404 = (*qfn2(fn))(qenv(fn), v405, v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v405 = v404;
    v404 = v405;
    v404 = qcar(v404);
    if (v404 == nil) goto v359;
    v406 = stack[-8];
    v404 = stack[-6];
    v404 = Lassoc(nil, v406, v404);
    v406 = v404;
    v404 = v406;
    if (v404 == nil) goto v81;
    stack[0] = v406;
    v404 = v406;
    v404 = qcdr(v404);
    fn = elt(env, 6); /* addsq */
    v404 = (*qfn2(fn))(qenv(fn), v404, v405);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v404 = Lrplacd(nil, stack[0], v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    goto v359;

v81:
    v404 = stack[-8];
    v405 = cons(v404, v405);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v404 = stack[-6];
    fn = elt(env, 7); /* enter!-sorted */
    v404 = (*qfn2(fn))(qenv(fn), v405, v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[-6] = v404;
    goto v359;

v22:
    v404 = stack[-3];
    v404 = qcdr(v404);
    stack[-3] = v404;
    goto v330;

v408:
    stack[-4] = stack[-5];
    v404 = stack[-6];
    stack[-5] = v404;
    goto v270;

v270:
    v404 = stack[-5];
    if (v404 == nil) goto v409;
    v404 = stack[-5];
    v404 = qcar(v404);
    stack[0] = v404;
    v404 = stack[0];
    v404 = qcdr(v404);
    fn = elt(env, 8); /* subs2!* */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v405 = v404;
    v405 = qcar(v405);
    if (v405 == nil) goto v410;
    v405 = stack[0];
    v405 = qcar(v405);
    v404 = cons(v405, v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v404 = ncons(v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    goto v273;

v273:
    stack[-3] = v404;
    v404 = stack[-3];
    fn = elt(env, 9); /* lastpair */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[-2] = v404;
    v404 = stack[-5];
    v404 = qcdr(v404);
    stack[-5] = v404;
    v404 = stack[-2];
    if (!consp(v404)) goto v270;
    else goto v411;

v411:
    v404 = stack[-5];
    if (v404 == nil) goto v105;
    stack[-1] = stack[-2];
    v404 = stack[-5];
    v404 = qcar(v404);
    stack[0] = v404;
    v404 = stack[0];
    v404 = qcdr(v404);
    fn = elt(env, 8); /* subs2!* */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v405 = v404;
    v405 = qcar(v405);
    if (v405 == nil) goto v412;
    v405 = stack[0];
    v405 = qcar(v405);
    v404 = cons(v405, v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v404 = ncons(v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    goto v413;

v413:
    v404 = Lrplacd(nil, stack[-1], v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    v404 = stack[-2];
    fn = elt(env, 9); /* lastpair */
    v404 = (*qfn1(fn))(qenv(fn), v404);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-9];
    stack[-2] = v404;
    v404 = stack[-5];
    v404 = qcdr(v404);
    stack[-5] = v404;
    goto v411;

v412:
    v404 = nil;
    goto v413;

v105:
    v404 = stack[-3];
    goto v414;

v414:
    {
        Lisp_Object v385 = stack[-4];
        popv(10);
        return cons(v385, v404);
    }

v410:
    v404 = nil;
    goto v273;

v409:
    v404 = qvalue(elt(env, 1)); /* nil */
    goto v414;

v46:
    v404 = qvalue(elt(env, 1)); /* nil */
    goto v107;

v147:
    v404 = qvalue(elt(env, 1)); /* nil */
    goto v57;
/* error exit handlers */
v407:
    popv(10);
    return nil;
}



/* Code for mk!+mat!+mult!+vec */

static Lisp_Object CC_mkLmatLmultLvec(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+mat+mult+vec");
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
    v119 = v0;
/* end of prologue */
    stack[-4] = v119;
    v119 = stack[-4];
    if (v119 == nil) goto v56;
    v119 = stack[-4];
    v119 = qcar(v119);
    v128 = v119;
    v119 = stack[-3];
    fn = elt(env, 2); /* mk!+real!+inner!+product */
    v119 = (*qfn2(fn))(qenv(fn), v128, v119);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v119 = ncons(v119);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    stack[-1] = v119;
    stack[-2] = v119;
    goto v17;

v17:
    v119 = stack[-4];
    v119 = qcdr(v119);
    stack[-4] = v119;
    v119 = stack[-4];
    if (v119 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v119 = stack[-4];
    v119 = qcar(v119);
    v128 = v119;
    v119 = stack[-3];
    fn = elt(env, 2); /* mk!+real!+inner!+product */
    v119 = (*qfn2(fn))(qenv(fn), v128, v119);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v119 = ncons(v119);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v119 = Lrplacd(nil, stack[0], v119);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v119 = stack[-1];
    v119 = qcdr(v119);
    stack[-1] = v119;
    goto v17;

v56:
    v119 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v119); }
/* error exit handlers */
v46:
    popv(6);
    return nil;
}



/* Code for qqe_dfs */

static Lisp_Object CC_qqe_dfs(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v93;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_dfs");
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
    stack[-1] = v1;
    v93 = v0;
/* end of prologue */
    v148 = qvalue(elt(env, 1)); /* t */
    stack[0] = v148;
    v148 = v93;
    if (!consp(v148)) goto v126;
    v148 = v93;
    stack[-2] = v148;
    goto v122;

v122:
    v148 = stack[-2];
    if (v148 == nil) goto v139;
    v148 = stack[0];
    if (v148 == nil) goto v139;
    v148 = stack[-2];
    v93 = qcar(v148);
    v148 = stack[-1];
    if (!(v93 == v148)) goto v119;
    v148 = qvalue(elt(env, 2)); /* nil */
    stack[0] = v148;
    goto v119;

v119:
    v148 = stack[-2];
    v93 = qcar(v148);
    v148 = stack[-1];
    v148 = CC_qqe_dfs(env, v93, v148);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    if (v148 == nil) goto v61;
    v148 = qvalue(elt(env, 2)); /* nil */
    stack[0] = v148;
    goto v61;

v61:
    v148 = stack[-2];
    v148 = qcdr(v148);
    stack[-2] = v148;
    goto v122;

v139:
    v148 = stack[0];
    if (v148 == nil) goto v95;
    v148 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v148); }

v95:
    v148 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v148); }

v126:
    v148 = stack[-1];
    if (v93 == v148) goto v56;
    v148 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v148); }

v56:
    v148 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v148); }
/* error exit handlers */
v106:
    popv(4);
    return nil;
}



/* Code for cl_dnf */

static Lisp_Object CC_cl_dnf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v147, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_dnf");
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
    v127 = v0;
/* end of prologue */
    v147 = v127;
    v127 = elt(env, 1); /* or */
    fn = elt(env, 3); /* cl_gdnf0 */
    v98 = (*qfn2(fn))(qenv(fn), v147, v127);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[0];
    v147 = qvalue(elt(env, 2)); /* nil */
    v127 = (Lisp_Object)-15; /* -1 */
    {
        popv(1);
        fn = elt(env, 4); /* rl_simpl */
        return (*qfnn(fn))(qenv(fn), 3, v98, v147, v127);
    }
/* error exit handlers */
v99:
    popv(1);
    return nil;
}



/* Code for vdelete */

static Lisp_Object CC_vdelete(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v361, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdelete");
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
    v97 = nil;
    goto v32;

v32:
    v143 = stack[0];
    if (v143 == nil) goto v142;
    v143 = stack[-1];
    v361 = qcar(v143);
    v143 = stack[0];
    v143 = qcar(v143);
    v143 = qcar(v143);
    if (equal(v361, v143)) goto v3;
    v143 = stack[0];
    v143 = qcar(v143);
    v361 = v97;
    v143 = cons(v143, v361);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    v97 = v143;
    v143 = stack[0];
    v143 = qcdr(v143);
    stack[0] = v143;
    goto v32;

v3:
    v361 = v97;
    v143 = stack[0];
    v143 = qcdr(v143);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v361, v143);
    }

v142:
    v143 = v97;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v143);
    }
/* error exit handlers */
v58:
    popv(3);
    return nil;
}



/* Code for dvfsf_smcpknowl */

static Lisp_Object CC_dvfsf_smcpknowl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_smcpknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v9 = v0;
/* end of prologue */
    v13 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v13 == nil) goto v142;
    v13 = v9;
    {
        fn = elt(env, 2); /* cl_susicpknowl */
        return (*qfn1(fn))(qenv(fn), v13);
    }

v142:
    v13 = v9;
    {
        fn = elt(env, 3); /* cl_smcpknowl */
        return (*qfn1(fn))(qenv(fn), v13);
    }
}



/* Code for unary */

static Lisp_Object CC_unary(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unary");
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
    v121 = elt(env, 1); /* "<apply>" */
    fn = elt(env, 6); /* printout */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    v121 = elt(env, 2); /* "<" */
    v121 = Lprinc(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    v121 = stack[0];
    v121 = Lprinc(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    v121 = elt(env, 3); /* "/>" */
    v121 = Lprinc(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    v154 = qvalue(elt(env, 4)); /* indent */
    v121 = (Lisp_Object)49; /* 3 */
    v121 = plus2(v154, v121);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    qvalue(elt(env, 4)) = v121; /* indent */
    v121 = stack[-1];
    v121 = qcar(v121);
    fn = elt(env, 7); /* expression */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    v154 = qvalue(elt(env, 4)); /* indent */
    v121 = (Lisp_Object)49; /* 3 */
    v121 = difference2(v154, v121);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    qvalue(elt(env, 4)) = v121; /* indent */
    v121 = elt(env, 5); /* "</apply>" */
    fn = elt(env, 6); /* printout */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v45;
    v121 = nil;
    { popv(3); return onevalue(v121); }
/* error exit handlers */
v45:
    popv(3);
    return nil;
}



/* Code for powmtch */

static Lisp_Object MS_CDECL CC_powmtch(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v109, v135, v47, v136;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "powmtch");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powmtch");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v28 = v2;
    v109 = v1;
    v135 = v0;
/* end of prologue */

v415:
    v47 = v109;
    if (v47 == nil) goto v32;
    v136 = v135;
    v47 = v109;
    v47 = qcar(v47);
    v47 = Latsoc(nil, v136, v47);
    v136 = v47;
    v47 = v136;
    if (v47 == nil) goto v45;
    v47 = v136;
    v136 = qcdr(v47);
    v47 = v28;
    if (equal(v136, v47)) goto v45;
    v109 = qcdr(v109);
    goto v415;

v45:
    v47 = v109;
    stack[0] = qcar(v47);
    v109 = qcdr(v109);
    v28 = CC_powmtch(env, 3, v135, v109, v28);
    nil = C_nil;
    if (exception_pending()) goto v94;
    {
        Lisp_Object v95 = stack[0];
        popv(1);
        return cons(v95, v28);
    }

v32:
    v28 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v28); }
/* error exit handlers */
v94:
    popv(1);
    return nil;
}



/* Code for pm!:gensym */

static Lisp_Object MS_CDECL CC_pmTgensym(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "pm:gensym");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pm:gensym");
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
    stack[-1] = elt(env, 1); /* !? */
    stack[0] = elt(env, 2); /* !_ */
    v56 = qvalue(elt(env, 3)); /* pm!:gensym!-count!* */
    v56 = add1(v56);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    qvalue(elt(env, 3)) = v56; /* pm!:gensym!-count!* */
    v56 = Lexplode(nil, v56);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    v56 = list2star(stack[-1], stack[0], v56);
    nil = C_nil;
    if (exception_pending()) goto v59;
        popv(3);
        return Lcompress(nil, v56);
/* error exit handlers */
v59:
    popv(3);
    return nil;
}



/* Code for xnormalise */

static Lisp_Object CC_xnormalise(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xnormalise");
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
    v54 = stack[0];
    if (v54 == nil) goto v8;
    v54 = stack[0];
    v54 = qcar(v54);
    stack[-1] = qcdr(v54);
    v53 = (Lisp_Object)17; /* 1 */
    v54 = (Lisp_Object)17; /* 1 */
    v54 = cons(v53, v54);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-2];
    if (equal(stack[-1], v54)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = stack[0];
    v54 = stack[0];
    v54 = qcar(v54);
    v54 = qcdr(v54);
    fn = elt(env, 2); /* invsq */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-2];
    {
        Lisp_Object v36 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v36, v54);
    }

v8:
    v54 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v54); }
/* error exit handlers */
v132:
    popv(3);
    return nil;
}



/* Code for evalset_eq */

static Lisp_Object CC_evalset_eq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v139, v122, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalset_eq");
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
    v139 = v1;
    v122 = v0;
/* end of prologue */
    v60 = elt(env, 1); /* set_eq */
    fn = elt(env, 3); /* evalsetbool */
    v139 = (*qfnn(fn))(qenv(fn), 3, v60, v122, v139);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[0];
    v122 = v139;
    if (!consp(v122)) { popv(1); return onevalue(v139); }
    v122 = elt(env, 2); /* equal */
    {
        popv(1);
        fn = elt(env, 4); /* apply */
        return (*qfn2(fn))(qenv(fn), v122, v139);
    }
/* error exit handlers */
v121:
    popv(1);
    return nil;
}



/* Code for iscale */

static Lisp_Object CC_iscale(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v99, v55;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for iscale");
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
    v99 = v1;
    v55 = v0;
/* end of prologue */
    v98 = v99;
    v98 = qcdr(v98);
    stack[0] = qcar(v98);
    v98 = v55;
    v99 = qcdr(v99);
    v99 = qcdr(v99);
    v98 = plus2(v98, v99);
    nil = C_nil;
    if (exception_pending()) goto v39;
    {
        Lisp_Object v3 = stack[0];
        popv(1);
        return Lash1(nil, v3, v98);
    }
/* error exit handlers */
v39:
    popv(1);
    return nil;
}



/* Code for ev!-tades */

static Lisp_Object CC_evKtades(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v361, v97, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev-tades");
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
    goto v32;

v32:
    v361 = stack[-1];
    if (v361 == nil) goto v13;
    v51 = qvalue(elt(env, 1)); /* ndim!* */
    v361 = stack[-1];
    v97 = qcar(v361);
    v361 = stack[0];
    v361 = Lassoc(nil, v97, v361);
    v361 = qcdr(v361);
    fn = elt(env, 2); /* binc */
    v97 = (*qfn2(fn))(qenv(fn), v51, v361);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    v361 = stack[-2];
    v361 = cons(v97, v361);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    stack[-2] = v361;
    v361 = stack[-1];
    v361 = qcdr(v361);
    stack[-1] = v361;
    goto v32;

v13:
    stack[0] = stack[-2];
    v361 = (Lisp_Object)17; /* 1 */
    v361 = ncons(v361);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    {
        Lisp_Object v61 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v61, v361);
    }
/* error exit handlers */
v34:
    popv(4);
    return nil;
}



/* Code for degree!-order */

static Lisp_Object CC_degreeKorder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v45, v145;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for degree-order");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v45 = v1;
    v145 = v0;
/* end of prologue */
    v124 = v145;
    if (!consp(v124)) goto v35;
    v124 = v145;
    v124 = qcar(v124);
    if (!consp(v124)) goto v35;
    v124 = v45;
    if (!consp(v124)) goto v13;
    v124 = v45;
    v124 = qcar(v124);
    if (!consp(v124)) goto v13;
    v124 = v145;
    v124 = qcar(v124);
    v124 = qcar(v124);
    v124 = qcdr(v124);
    v45 = qcar(v45);
    v45 = qcar(v45);
    v45 = qcdr(v45);
        return Llessp(nil, v124, v45);

v13:
    v124 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v124);

v35:
    v124 = qvalue(elt(env, 1)); /* t */
    return onevalue(v124);
}



/* Code for listsub */

static Lisp_Object CC_listsub(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v328;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listsub");
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
    v118 = v1;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = elt(env, 1); /* list */
    v118 = qcdr(v118);
    stack[-3] = v118;
    v118 = stack[-3];
    if (v118 == nil) goto v127;
    v118 = stack[-3];
    v118 = qcar(v118);
    v328 = stack[-4];
    fn = elt(env, 3); /* subeval1 */
    v118 = (*qfn2(fn))(qenv(fn), v328, v118);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-6];
    v118 = ncons(v118);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-6];
    stack[-1] = v118;
    stack[-2] = v118;
    goto v56;

v56:
    v118 = stack[-3];
    v118 = qcdr(v118);
    stack[-3] = v118;
    v118 = stack[-3];
    if (v118 == nil) goto v54;
    stack[0] = stack[-1];
    v118 = stack[-3];
    v118 = qcar(v118);
    v328 = stack[-4];
    fn = elt(env, 3); /* subeval1 */
    v118 = (*qfn2(fn))(qenv(fn), v328, v118);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-6];
    v118 = ncons(v118);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-6];
    v118 = Lrplacd(nil, stack[0], v118);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-6];
    v118 = stack[-1];
    v118 = qcdr(v118);
    stack[-1] = v118;
    goto v56;

v54:
    v118 = stack[-2];
    goto v29;

v29:
    {
        Lisp_Object v47 = stack[-5];
        popv(7);
        return cons(v47, v118);
    }

v127:
    v118 = qvalue(elt(env, 2)); /* nil */
    goto v29;
/* error exit handlers */
v135:
    popv(7);
    return nil;
}



/* Code for bc_from_a */

static Lisp_Object CC_bc_from_a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_from_a");
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
    v32 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[0];
    v32 = qcar(v32);
    {
        popv(1);
        fn = elt(env, 2); /* bc!=simp */
        return (*qfn1(fn))(qenv(fn), v32);
    }
/* error exit handlers */
v29:
    popv(1);
    return nil;
}



/* Code for algebnp */

static Lisp_Object CC_algebnp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v54;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for algebnp");
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

v415:
    v145 = stack[0];
    if (!consp(v145)) goto v8;
    v145 = stack[0];
    v54 = qcar(v145);
    v145 = elt(env, 2); /* !:ar!: */
    if (v54 == v145) goto v27;
    v145 = stack[0];
    if (!consp(v145)) goto v126;
    v145 = stack[0];
    v145 = qcar(v145);
    if (!consp(v145)) goto v126;
    v145 = stack[0];
    v145 = qcar(v145);
    v145 = qcdr(v145);
    v145 = CC_algebnp(env, v145);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-1];
    if (!(v145 == nil)) { popv(2); return onevalue(v145); }
    v145 = stack[0];
    v145 = qcdr(v145);
    stack[0] = v145;
    goto v415;

v126:
    v145 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v145); }

v27:
    v145 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v145); }

v8:
    v145 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v145); }
/* error exit handlers */
v133:
    popv(2);
    return nil;
}



setup_type const u49_setup[] =
{
    {"smaddm2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_smaddm2},
    {"mod-domainvalchk",        too_few_2,      CC_modKdomainvalchk,wrong_no_2},
    {"nssimp",                  too_few_2,      CC_nssimp,     wrong_no_2},
    {"dipreplus",               CC_dipreplus,   too_many_1,    wrong_no_1},
    {"addm1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_addm1},
    {"indexvp",                 CC_indexvp,     too_many_1,    wrong_no_1},
    {"calc_world",              too_few_2,      CC_calc_world, wrong_no_2},
    {"intargfn",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_intargfn},
    {"mo=pair",                 too_few_2,      CC_moMpair,    wrong_no_2},
    {"permp:",                  too_few_2,      CC_permpT,     wrong_no_2},
    {"movebds",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_movebds},
    {"ofsf_smeqtable",          too_few_2,      CC_ofsf_smeqtable,wrong_no_2},
    {"mkarg",                   too_few_2,      CC_mkarg,      wrong_no_2},
    {"product-set2",            too_few_2,      CC_productKset2,wrong_no_2},
    {"ratnump",                 CC_ratnump,     too_many_1,    wrong_no_1},
    {"dip-nc-ev-prod",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipKncKevKprod},
    {"fortexp1",                too_few_2,      CC_fortexp1,   wrong_no_2},
    {"store_edges",             CC_store_edges, too_many_1,    wrong_no_1},
    {"ezgcd-comfac",            CC_ezgcdKcomfac,too_many_1,    wrong_no_1},
    {"linineqevaltest",         too_few_2,      CC_linineqevaltest,wrong_no_2},
    {"chrstrem",                CC_chrstrem,    too_many_1,    wrong_no_1},
    {"multtaylor1",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_multtaylor1},
    {"mk+mat+mult+vec",         too_few_2,      CC_mkLmatLmultLvec,wrong_no_2},
    {"qqe_dfs",                 too_few_2,      CC_qqe_dfs,    wrong_no_2},
    {"cl_dnf",                  CC_cl_dnf,      too_many_1,    wrong_no_1},
    {"vdelete",                 too_few_2,      CC_vdelete,    wrong_no_2},
    {"dvfsf_smcpknowl",         CC_dvfsf_smcpknowl,too_many_1, wrong_no_1},
    {"unary",                   too_few_2,      CC_unary,      wrong_no_2},
    {"powmtch",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_powmtch},
    {"pm:gensym",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_pmTgensym},
    {"xnormalise",              CC_xnormalise,  too_many_1,    wrong_no_1},
    {"evalset_eq",              too_few_2,      CC_evalset_eq, wrong_no_2},
    {"iscale",                  too_few_2,      CC_iscale,     wrong_no_2},
    {"ev-tades",                too_few_2,      CC_evKtades,   wrong_no_2},
    {"degree-order",            too_few_2,      CC_degreeKorder,wrong_no_2},
    {"listsub",                 too_few_2,      CC_listsub,    wrong_no_2},
    {"bc_from_a",               CC_bc_from_a,   too_many_1,    wrong_no_1},
    {"algebnp",                 CC_algebnp,     too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u49", (two_args *)"4793 3193041 4459231", 0}
};

/* end of generated code */
