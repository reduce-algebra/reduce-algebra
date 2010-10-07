
/* $destdir\u07.c        Machine generated C code */

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


/* Code for form */

static Lisp_Object CC_form(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v22, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for form");
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
    v22 = v0;
/* end of prologue */
    v21 = v22;
    if (!consp(v21)) goto v24;
    v21 = v22;
    v23 = qcar(v21);
    v21 = elt(env, 1); /* always_nform */
    v21 = Lflagp(nil, v23, v21);
    env = stack[0];
    if (v21 == nil) goto v24;
    v21 = v22;
    {
        popv(1);
        fn = elt(env, 9); /* n_form */
        return (*qfn1(fn))(qenv(fn), v21);
    }

v24:
    v21 = qvalue(elt(env, 2)); /* !*rlisp88 */
    if (v21 == nil) goto v25;
    v23 = qvalue(elt(env, 4)); /* !*mode */
    v21 = elt(env, 5); /* symbolic */
    if (!(v23 == v21)) goto v26;
    v23 = v22;
    v21 = elt(env, 6); /* modefn */
    v21 = Lflagp(nil, v23, v21);
    env = stack[0];
    if (v21 == nil) goto v27;
    v23 = v22;
    v21 = elt(env, 5); /* symbolic */
    if (!(v23 == v21)) goto v26;

v27:
    v23 = v22;
    v21 = elt(env, 6); /* modefn */
    v21 = Lflagpcar(nil, v23, v21);
    env = stack[0];
    if (v21 == nil) goto v28;
    v21 = v22;
    v23 = qcar(v21);
    v21 = elt(env, 5); /* symbolic */
    if (!(v23 == v21)) goto v26;

v28:
    v23 = v22;
    v22 = qvalue(elt(env, 3)); /* !*vars!* */
    v21 = qvalue(elt(env, 4)); /* !*mode */
    {
        popv(1);
        fn = elt(env, 10); /* form1 */
        return (*qfnn(fn))(qenv(fn), 3, v23, v22, v21);
    }

v26:
    v22 = elt(env, 7); /* "algebraic expression" */
    v21 = elt(env, 8); /* "Rlisp88 form" */
    {
        popv(1);
        fn = elt(env, 11); /* typerr */
        return (*qfn2(fn))(qenv(fn), v22, v21);
    }

v25:
    v23 = v22;
    v22 = qvalue(elt(env, 3)); /* !*vars!* */
    v21 = qvalue(elt(env, 4)); /* !*mode */
    {
        popv(1);
        fn = elt(env, 10); /* form1 */
        return (*qfnn(fn))(qenv(fn), 3, v23, v22, v21);
    }
}



/* Code for red!-weight1 */

static Lisp_Object CC_redKweight1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-weight1");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v29;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v37;

v37:
    v35 = stack[-1];
    if (v35 == nil) goto v38;
    v35 = stack[-1];
    v35 = qcar(v35);
    v36 = Labsval(nil, v35);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    v35 = stack[0];
    v35 = qcar(v35);
    v36 = times2(v36, v35);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    v35 = stack[-2];
    v35 = cons(v36, v35);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    stack[-2] = v35;
    v35 = stack[-1];
    v35 = qcdr(v35);
    stack[-1] = v35;
    v35 = stack[0];
    v35 = qcdr(v35);
    stack[0] = v35;
    goto v37;

v38:
    v35 = (Lisp_Object)1; /* 0 */
    v36 = v35;
    goto v39;

v39:
    v35 = stack[-2];
    if (v35 == nil) { popv(4); return onevalue(v36); }
    v35 = stack[-2];
    v35 = qcar(v35);
    v35 = plus2(v35, v36);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    v36 = v35;
    v35 = stack[-2];
    v35 = qcdr(v35);
    stack[-2] = v35;
    goto v39;
/* error exit handlers */
v10:
    popv(4);
    return nil;
}



/* Code for dp_times_bc */

static Lisp_Object CC_dp_times_bc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_times_bc");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v47 = v29;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = v47;
    v47 = stack[-5];
    if (v47 == nil) goto v49;
    v47 = stack[-5];
    v47 = qcar(v47);
    v48 = v47;
    stack[0] = qcar(v48);
    v48 = stack[-4];
    v47 = qcdr(v47);
    fn = elt(env, 2); /* bc_prod */
    v47 = (*qfn2(fn))(qenv(fn), v48, v47);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-6];
    v47 = cons(stack[0], v47);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-6];
    v47 = ncons(v47);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-6];
    stack[-2] = v47;
    stack[-3] = v47;
    goto v38;

v38:
    v47 = stack[-5];
    v47 = qcdr(v47);
    stack[-5] = v47;
    v47 = stack[-5];
    if (v47 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v47 = stack[-5];
    v47 = qcar(v47);
    v48 = v47;
    stack[0] = qcar(v48);
    v48 = stack[-4];
    v47 = qcdr(v47);
    fn = elt(env, 2); /* bc_prod */
    v47 = (*qfn2(fn))(qenv(fn), v48, v47);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-6];
    v47 = cons(stack[0], v47);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-6];
    v47 = ncons(v47);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-6];
    v47 = Lrplacd(nil, stack[-1], v47);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-6];
    v47 = stack[-2];
    v47 = qcdr(v47);
    stack[-2] = v47;
    goto v38;

v49:
    v47 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v47); }
/* error exit handlers */
v50:
    popv(7);
    return nil;
}



/* Code for pdmult */

static Lisp_Object CC_pdmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pdmult");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v29;
    v78 = v0;
/* end of prologue */
    stack[-9] = v78;
    v78 = stack[-9];
    if (v78 == nil) goto v49;
    v78 = stack[-9];
    v78 = qcar(v78);
    stack[-4] = v78;
    v78 = stack[-4];
    v79 = qcar(v78);
    v78 = stack[-8];
    fn = elt(env, 2); /* pair */
    v78 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-10];
    stack[-3] = v78;
    v78 = stack[-3];
    if (v78 == nil) goto v15;
    v78 = stack[-3];
    v78 = qcar(v78);
    v79 = v78;
    v79 = qcar(v79);
    v78 = qcdr(v78);
    v78 = (Lisp_Object)(int32_t)((int32_t)v79 + (int32_t)v78 - TAG_FIXNUM);
    v78 = ncons(v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-10];
    stack[-1] = v78;
    stack[-2] = v78;
    goto v16;

v16:
    v78 = stack[-3];
    v78 = qcdr(v78);
    stack[-3] = v78;
    v78 = stack[-3];
    if (v78 == nil) goto v27;
    stack[0] = stack[-1];
    v78 = stack[-3];
    v78 = qcar(v78);
    v79 = v78;
    v79 = qcar(v79);
    v78 = qcdr(v78);
    v78 = (Lisp_Object)(int32_t)((int32_t)v79 + (int32_t)v78 - TAG_FIXNUM);
    v78 = ncons(v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-10];
    v78 = Lrplacd(nil, stack[0], v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-10];
    v78 = stack[-1];
    v78 = qcdr(v78);
    stack[-1] = v78;
    goto v16;

v27:
    v78 = stack[-2];
    v79 = v78;
    goto v81;

v81:
    v78 = stack[-4];
    v78 = qcdr(v78);
    v78 = cons(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-10];
    v78 = ncons(v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-10];
    stack[-6] = v78;
    stack[-7] = v78;
    goto v38;

v38:
    v78 = stack[-9];
    v78 = qcdr(v78);
    stack[-9] = v78;
    v78 = stack[-9];
    if (v78 == nil) { Lisp_Object res = stack[-7]; popv(11); return onevalue(res); }
    stack[-5] = stack[-6];
    v78 = stack[-9];
    v78 = qcar(v78);
    stack[-4] = v78;
    v78 = stack[-4];
    v79 = qcar(v78);
    v78 = stack[-8];
    fn = elt(env, 2); /* pair */
    v78 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-10];
    stack[-3] = v78;
    v78 = stack[-3];
    if (v78 == nil) goto v82;
    v78 = stack[-3];
    v78 = qcar(v78);
    v79 = v78;
    v79 = qcar(v79);
    v78 = qcdr(v78);
    v78 = (Lisp_Object)(int32_t)((int32_t)v79 + (int32_t)v78 - TAG_FIXNUM);
    v78 = ncons(v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-10];
    stack[-1] = v78;
    stack[-2] = v78;
    goto v83;

v83:
    v78 = stack[-3];
    v78 = qcdr(v78);
    stack[-3] = v78;
    v78 = stack[-3];
    if (v78 == nil) goto v84;
    stack[0] = stack[-1];
    v78 = stack[-3];
    v78 = qcar(v78);
    v79 = v78;
    v79 = qcar(v79);
    v78 = qcdr(v78);
    v78 = (Lisp_Object)(int32_t)((int32_t)v79 + (int32_t)v78 - TAG_FIXNUM);
    v78 = ncons(v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-10];
    v78 = Lrplacd(nil, stack[0], v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-10];
    v78 = stack[-1];
    v78 = qcdr(v78);
    stack[-1] = v78;
    goto v83;

v84:
    v78 = stack[-2];
    v79 = v78;
    goto v85;

v85:
    v78 = stack[-4];
    v78 = qcdr(v78);
    v78 = cons(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-10];
    v78 = ncons(v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-10];
    v78 = Lrplacd(nil, stack[-5], v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-10];
    v78 = stack[-6];
    v78 = qcdr(v78);
    stack[-6] = v78;
    goto v38;

v82:
    v78 = qvalue(elt(env, 1)); /* nil */
    v79 = v78;
    goto v85;

v15:
    v78 = qvalue(elt(env, 1)); /* nil */
    v79 = v78;
    goto v81;

v49:
    v78 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v78); }
/* error exit handlers */
v80:
    popv(11);
    return nil;
}



/* Code for gperm1 */

static Lisp_Object MS_CDECL CC_gperm1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v29,
                         Lisp_Object v86, Lisp_Object v32, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v41, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "gperm1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm1");
#endif
    if (stack >= stacklimit)
    {
        push4(v32,v86,v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v29,v86,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v32;
    stack[-2] = v86;
    stack[-3] = v29;
    stack[-4] = v0;
/* end of prologue */

v39:
    v40 = stack[-4];
    if (v40 == nil) goto v19;
    v40 = stack[-4];
    v40 = qcdr(v40);
    stack[-5] = v40;
    v40 = stack[-4];
    v41 = qcar(v40);
    v40 = stack[-2];
    v40 = cons(v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-6];
    stack[0] = v40;
    v41 = stack[-3];
    v40 = stack[-2];
    v40 = cons(v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-6];
    fn = elt(env, 1); /* rev */
    v41 = (*qfn2(fn))(qenv(fn), stack[-4], v40);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-6];
    v40 = stack[-1];
    v40 = cons(v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-6];
    stack[-1] = v40;
    v40 = stack[0];
    stack[-2] = v40;
    v40 = stack[-5];
    stack[-4] = v40;
    goto v39;

v19:
    v27 = stack[-3];
    v41 = stack[-2];
    v40 = stack[-1];
    popv(7);
    return acons(v27, v41, v40);
/* error exit handlers */
v42:
    popv(7);
    return nil;
}



/* Code for arzerop!: */

static Lisp_Object CC_arzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arzerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v24 = v0;
/* end of prologue */
    v24 = qcdr(v24);
    v24 = (v24 == nil ? lisp_true : nil);
    return onevalue(v24);
}



/* Code for cl_cflip */

static Lisp_Object CC_cl_cflip(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_cflip");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v93 = v29;
    v94 = v0;
/* end of prologue */
    if (!(v93 == nil)) return onevalue(v94);
    v93 = v94;
    {
        fn = elt(env, 1); /* cl_flip */
        return (*qfn1(fn))(qenv(fn), v93);
    }
}



/* Code for sfto_gcdf!* */

static Lisp_Object CC_sfto_gcdfH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v94, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_gcdf*");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v94 = v29;
    v96 = v0;
/* end of prologue */
    v93 = qvalue(elt(env, 1)); /* t */
    stack[0] = qvalue(elt(env, 2)); /* !*gcd */
    qvalue(elt(env, 2)) = v93; /* !*gcd */
    v93 = v96;
    fn = elt(env, 3); /* sfto_gcdf */
    v93 = (*qfn2(fn))(qenv(fn), v93, v94);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*gcd */
    { popv(2); return onevalue(v93); }
/* error exit handlers */
v20:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*gcd */
    popv(2);
    return nil;
}



/* Code for exceeds!-order */

static Lisp_Object CC_exceedsKorder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exceeds-order");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v29;
    stack[-1] = v0;
/* end of prologue */

v101:
    v10 = stack[-1];
    if (v10 == nil) goto v24;
    v10 = stack[0];
    v10 = qcar(v10);
    stack[-2] = v10;
    v10 = (Lisp_Object)1; /* 0 */
    v11 = v10;
    goto v25;

v25:
    v10 = stack[-2];
    if (v10 == nil) goto v102;
    v10 = stack[-2];
    v10 = qcar(v10);
    fn = elt(env, 2); /* tayexp!-plus2 */
    v10 = (*qfn2(fn))(qenv(fn), v10, v11);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-3];
    v11 = v10;
    v10 = stack[-2];
    v10 = qcdr(v10);
    stack[-2] = v10;
    goto v25;

v102:
    v10 = v11;
    v11 = v10;
    v10 = stack[-1];
    v10 = qcar(v10);
    fn = elt(env, 3); /* tayexp!-lessp */
    v10 = (*qfn2(fn))(qenv(fn), v11, v10);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-3];
    v10 = (v10 == nil ? lisp_true : nil);
    if (!(v10 == nil)) { popv(4); return onevalue(v10); }
    v10 = stack[-1];
    v11 = qcdr(v10);
    v10 = stack[0];
    v10 = qcdr(v10);
    stack[-1] = v11;
    stack[0] = v10;
    goto v101;

v24:
    v10 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v10); }
/* error exit handlers */
v27:
    popv(4);
    return nil;
}



/* Code for qqe_qtidp */

static Lisp_Object CC_qqe_qtidp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v103;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_qtidp");
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
    v20 = v0;
/* end of prologue */
    v103 = v20;
    v20 = elt(env, 1); /* idtype */
    v20 = get(v103, v20);
    env = stack[0];
    v103 = elt(env, 2); /* qt */
    v20 = (v20 == v103 ? lisp_true : nil);
    { popv(1); return onevalue(v20); }
}



/* Code for aex_deg */

static Lisp_Object CC_aex_deg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_deg");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v29;
    v49 = v0;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v93 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    v49 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* ratpoly_deg */
        return (*qfn2(fn))(qenv(fn), v93, v49);
    }
/* error exit handlers */
v96:
    popv(2);
    return nil;
}



/* Code for rl_sacat */

static Lisp_Object MS_CDECL CC_rl_sacat(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v29,
                         Lisp_Object v86, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v81, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "rl_sacat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_sacat");
#endif
    if (stack >= stacklimit)
    {
        push3(v86,v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v29,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v97 = v86;
    v81 = v29;
    v25 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_sacat!* */
    v97 = list3(v25, v81, v97);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-1];
    {
        Lisp_Object v34 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v34, v97);
    }
/* error exit handlers */
v72:
    popv(2);
    return nil;
}



/* Code for omobjs */

static Lisp_Object MS_CDECL CC_omobjs(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omobjs");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omobjs");
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
    v99 = qvalue(elt(env, 1)); /* char */
    v15 = elt(env, 2); /* (!/ o m a) */
    if (equal(v99, v15)) goto v92;
    fn = elt(env, 4); /* omobj */
    v15 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-1];
    stack[0] = v15;
    fn = elt(env, 5); /* lex */
    v15 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-1];
    v15 = CC_omobjs(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v106;
    v99 = stack[0];
    if (v99 == nil) goto v91;
    v99 = stack[0];
    popv(2);
    return cons(v99, v15);

v91:
    v99 = stack[0];
        popv(2);
        return Lappend(nil, v99, v15);

v92:
    v15 = nil;
    { popv(2); return onevalue(v15); }
/* error exit handlers */
v106:
    popv(2);
    return nil;
}



/* Code for rationalizei */

static Lisp_Object CC_rationalizei(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v116, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rationalizei");
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
    v115 = stack[-1];
    v115 = qcdr(v115);
    stack[-2] = v115;
    v116 = v115;
    v115 = v116;
    v115 = (consp(v115) ? nil : lisp_true);
    if (!(v115 == nil)) goto v96;
    v115 = v116;
    v115 = qcar(v115);
    v115 = (consp(v115) ? nil : lisp_true);
    goto v96;

v96:
    if (!(v115 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v116 = elt(env, 1); /* i */
    v115 = stack[-2];
    v115 = Lsmemq(nil, v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    if (v115 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v116 = elt(env, 1); /* i */
    v115 = qvalue(elt(env, 2)); /* kord!* */
    v115 = cons(v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    stack[0] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v115; /* kord!* */
    v115 = stack[-1];
    v115 = qcar(v115);
    fn = elt(env, 4); /* reorder */
    stack[-2] = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-3];
    v115 = stack[-1];
    v115 = qcdr(v115);
    fn = elt(env, 4); /* reorder */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-3];
    v115 = cons(stack[-2], v115);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-3];
    stack[-2] = v115;
    qvalue(elt(env, 2)) = stack[0]; /* kord!* */
    v115 = stack[-2];
    v115 = qcdr(v115);
    stack[0] = v115;
    v115 = qcar(v115);
    v116 = qcar(v115);
    v115 = elt(env, 3); /* (i . 1) */
    if (!(equal(v116, v115))) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v115 = stack[0];
    v115 = qcdr(v115);
    if (!(v115 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v51 = elt(env, 1); /* i */
    v116 = (Lisp_Object)17; /* 1 */
    v115 = (Lisp_Object)17; /* 1 */
    v115 = acons(v51, v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    stack[-1] = ncons(v115);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    v115 = stack[-2];
    v115 = qcar(v115);
    fn = elt(env, 4); /* reorder */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    fn = elt(env, 5); /* multf */
    v115 = (*qfn2(fn))(qenv(fn), stack[-1], v115);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    fn = elt(env, 6); /* negf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    v115 = stack[0];
    v115 = qcar(v115);
    v115 = qcdr(v115);
    fn = elt(env, 4); /* reorder */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v55;
    {
        Lisp_Object v118 = stack[-1];
        popv(4);
        return cons(v118, v115);
    }
/* error exit handlers */
v117:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[0]; /* kord!* */
    popv(4);
    return nil;
v55:
    popv(4);
    return nil;
}



/* Code for comm_kernels1 */

static Lisp_Object CC_comm_kernels1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comm_kernels1");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v29;
    v119 = v0;
/* end of prologue */

v101:
    v120 = v119;
    if (!consp(v120)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v120 = v119;
    v120 = qcar(v120);
    if (!consp(v120)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v120 = v119;
    v120 = qcar(v120);
    v120 = qcar(v120);
    v120 = qcar(v120);
    stack[-3] = v120;
    v120 = v119;
    v120 = qcar(v120);
    stack[-1] = qcdr(v120);
    stack[0] = qcdr(v119);
    v120 = stack[-3];
    v119 = stack[-2];
    v119 = Lmemq(nil, v120, v119);
    if (!(v119 == nil)) goto v76;
    v119 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v119 == nil) goto v121;
    v119 = stack[-3];
    fn = elt(env, 2); /* noncomp1 */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    if (!(v119 == nil)) goto v76;

v121:
    v119 = stack[-3];
    v119 = ncons(v119);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    v119 = Lappend(nil, stack[-2], v119);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    goto v18;

v18:
    v120 = CC_comm_kernels1(env, stack[0], v119);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    v119 = stack[-1];
    stack[-2] = v120;
    goto v101;

v76:
    v119 = stack[-2];
    goto v18;
/* error exit handlers */
v122:
    popv(5);
    return nil;
}



/* Code for diplength */

static Lisp_Object CC_diplength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v99;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diplength");
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
    goto v92;

v92:
    v15 = stack[0];
    if (v15 == nil) goto v37;
    v99 = (Lisp_Object)17; /* 1 */
    v15 = stack[-1];
    v15 = cons(v99, v15);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    stack[-1] = v15;
    v15 = stack[0];
    v15 = qcdr(v15);
    v15 = qcdr(v15);
    stack[0] = v15;
    goto v92;

v37:
    v15 = (Lisp_Object)1; /* 0 */
    v99 = v15;
    goto v38;

v38:
    v15 = stack[-1];
    if (v15 == nil) { popv(3); return onevalue(v99); }
    v15 = stack[-1];
    v15 = qcar(v15);
    v15 = plus2(v15, v99);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    v99 = v15;
    v15 = stack[-1];
    v15 = qcdr(v15);
    stack[-1] = v15;
    goto v38;
/* error exit handlers */
v114:
    popv(3);
    return nil;
}



/* Code for boundindp */

static Lisp_Object CC_boundindp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18, v44, v123;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for boundindp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v123 = v29;
    v44 = v0;
/* end of prologue */

v24:
    v17 = v44;
    if (v17 == nil) goto v38;
    v17 = v44;
    v18 = qcar(v17);
    v17 = v123;
    v17 = Lmember(nil, v18, v17);
    if (v17 == nil) goto v69;
    v17 = v44;
    v17 = qcdr(v17);
    v44 = v17;
    goto v24;

v69:
    v17 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v17);

v38:
    v17 = qvalue(elt(env, 1)); /* t */
    return onevalue(v17);
}



/* Code for plus!: */

static Lisp_Object CC_plusT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v131, v132, v133;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for plus:");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v132 = v29;
    v133 = v0;
/* end of prologue */
    v130 = v133;
    v130 = qcdr(v130);
    v131 = qcar(v130);
    stack[-1] = v131;
    v130 = (Lisp_Object)1; /* 0 */
    if (v131 == v130) { popv(6); return onevalue(v132); }
    v130 = v132;
    v130 = qcdr(v130);
    v131 = qcar(v130);
    stack[0] = v131;
    v130 = (Lisp_Object)1; /* 0 */
    if (v131 == v130) { popv(6); return onevalue(v133); }
    v130 = v133;
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    stack[-4] = v130;
    v131 = v132;
    v131 = qcdr(v131);
    v131 = qcdr(v131);
    stack[-2] = v131;
    v131 = difference2(v130, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    stack[-3] = v131;
    v130 = (Lisp_Object)1; /* 0 */
    if (v131 == v130) goto v73;
    v131 = stack[-3];
    v130 = (Lisp_Object)1; /* 0 */
    v130 = (Lisp_Object)greaterp2(v131, v130);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v130 = v130 ? lisp_true : nil;
    env = stack[-5];
    if (v130 == nil) goto v55;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v131 = stack[-1];
    v130 = stack[-3];
    v131 = Lash1(nil, v131, v130);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    v130 = stack[0];
    v131 = plus2(v131, v130);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v130 = stack[-2];
    {
        Lisp_Object v135 = stack[-4];
        popv(6);
        return list2star(v135, v131, v130);
    }

v55:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v130 = stack[-3];
    v130 = negate(v130);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    v130 = Lash1(nil, stack[0], v130);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    v131 = plus2(stack[-1], v130);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v130 = stack[-4];
    {
        Lisp_Object v136 = stack[-2];
        popv(6);
        return list2star(v136, v131, v130);
    }

v73:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v131 = stack[-1];
    v130 = stack[0];
    v131 = plus2(v131, v130);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v130 = stack[-4];
    {
        Lisp_Object v137 = stack[-2];
        popv(6);
        return list2star(v137, v131, v130);
    }
/* error exit handlers */
v134:
    popv(6);
    return nil;
}



/* Code for rd!:minusp */

static Lisp_Object CC_rdTminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v15, v99;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:minusp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v99 = v0;
/* end of prologue */
    v14 = v99;
    v14 = qcdr(v14);
    if (!consp(v14)) goto v31;
    v15 = v99;
    v14 = elt(env, 1); /* !:rd!: */
    if (!consp(v15)) goto v96;
    v15 = qcar(v15);
    if (!(v15 == v14)) goto v96;
    v14 = v99;
    v14 = qcdr(v14);
    if (!consp(v14)) goto v96;
    v14 = v99;
    v14 = qcdr(v14);
    v15 = qcar(v14);
    v14 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v15, v14);

v96:
    v14 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v14);

v31:
    v14 = v99;
    v14 = qcdr(v14);
        return Lminusp(nil, v14);
}



/* Code for areallindices */

static Lisp_Object CC_areallindices(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for areallindices");
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

v101:
    v33 = stack[0];
    v33 = qcar(v33);
    fn = elt(env, 2); /* isanindex */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    if (v33 == nil) goto v31;
    v33 = stack[0];
    v33 = qcdr(v33);
    v33 = (v33 == nil ? lisp_true : nil);
    if (!(v33 == nil)) { popv(2); return onevalue(v33); }
    v33 = stack[0];
    v33 = qcdr(v33);
    stack[0] = v33;
    goto v101;

v31:
    v33 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v33); }
/* error exit handlers */
v81:
    popv(2);
    return nil;
}



/* Code for symbid */

static Lisp_Object CC_symbid(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v140, v141, v1;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbid");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v141 = v29;
    stack[0] = v0;
/* end of prologue */
    v109 = qvalue(elt(env, 1)); /* fname!* */
    if (v109 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v140 = qvalue(elt(env, 2)); /* ftype!* */
    v109 = elt(env, 3); /* (macro smacro) */
    v109 = Lmemq(nil, v140, v109);
    if (!(v109 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v109 = stack[0];
    v140 = v141;
    v109 = Latsoc(nil, v109, v140);
    if (!(v109 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v109 = stack[0];
    v109 = Lsymbol_specialp(nil, v109);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-2];
    if (!(v109 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v109 = stack[0];
    v109 = Lsymbol_globalp(nil, v109);
    env = stack[-2];
    if (!(v109 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v109 = stack[0];
    if (v109 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v140 = stack[0];
    v109 = qvalue(elt(env, 4)); /* t */
    if (v140 == v109) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v140 = stack[0];
    v109 = elt(env, 5); /* share */
    v109 = Lflagp(nil, v140, v109);
    env = stack[-2];
    if (!(v109 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v109 = qvalue(elt(env, 6)); /* !*comp */
    if (!(v109 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v109 = qvalue(elt(env, 7)); /* !*cref */
    if (!(v109 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v140 = stack[0];
    v109 = elt(env, 8); /* constant!? */
    v109 = get(v140, v109);
    env = stack[-2];
    if (!(v109 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v109 = qvalue(elt(env, 9)); /* !*msg */
    if (v109 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = elt(env, 11); /* "***" */
    v1 = elt(env, 12); /* "nonlocal use of undeclared variable" */
    v141 = stack[0];
    v140 = elt(env, 13); /* "in procedure" */
    v109 = qvalue(elt(env, 1)); /* fname!* */
    v109 = list4(v1, v141, v140, v109);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-2];
    fn = elt(env, 14); /* lpriw */
    v109 = (*qfn2(fn))(qenv(fn), stack[-1], v109);
    nil = C_nil;
    if (exception_pending()) goto v21;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v21:
    popv(3);
    return nil;
}



/* Code for mv!-pow!-minusp */

static Lisp_Object CC_mvKpowKminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v72;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-minusp");
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

v101:
    v91 = stack[0];
    if (v91 == nil) goto v31;
    v91 = stack[0];
    v72 = qcar(v91);
    v91 = (Lisp_Object)1; /* 0 */
    v91 = (Lisp_Object)lessp2(v72, v91);
    nil = C_nil;
    if (exception_pending()) goto v43;
    v91 = v91 ? lisp_true : nil;
    env = stack[-1];
    if (!(v91 == nil)) { popv(2); return onevalue(v91); }
    v91 = stack[0];
    v91 = qcdr(v91);
    stack[0] = v91;
    goto v101;

v31:
    v91 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v91); }
/* error exit handlers */
v43:
    popv(2);
    return nil;
}



/* Code for dp_sum */

static Lisp_Object CC_dp_sum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v132, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_sum");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v29;
    stack[-1] = v0;
/* end of prologue */

v101:
    v131 = stack[-1];
    if (v131 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v131 = stack[0];
    if (v131 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v131 = stack[-1];
    fn = elt(env, 1); /* dp_lmon */
    stack[-2] = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    v131 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    fn = elt(env, 2); /* mo_compare */
    v131 = (*qfn2(fn))(qenv(fn), stack[-2], v131);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    v133 = v131;
    v132 = v133;
    v131 = (Lisp_Object)17; /* 1 */
    if (v132 == v131) goto v105;
    v132 = v133;
    v131 = (Lisp_Object)-15; /* -1 */
    if (v132 == v131) goto v120;
    v131 = stack[-1];
    fn = elt(env, 3); /* dp_lc */
    stack[-2] = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    v131 = stack[0];
    fn = elt(env, 3); /* dp_lc */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    fn = elt(env, 4); /* bc_sum */
    v131 = (*qfn2(fn))(qenv(fn), stack[-2], v131);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    stack[-2] = v131;
    v131 = stack[-2];
    fn = elt(env, 5); /* bc_zero!? */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    if (v131 == nil) goto v53;
    v131 = stack[-1];
    v132 = qcdr(v131);
    v131 = stack[0];
    v131 = qcdr(v131);
    stack[-1] = v132;
    stack[0] = v131;
    goto v101;

v53:
    v131 = stack[-1];
    fn = elt(env, 1); /* dp_lmon */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    fn = elt(env, 6); /* dp_term */
    stack[-2] = (*qfn2(fn))(qenv(fn), stack[-2], v131);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    v131 = stack[-1];
    v132 = qcdr(v131);
    v131 = stack[0];
    v131 = qcdr(v131);
    v131 = CC_dp_sum(env, v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v146;
    {
        Lisp_Object v147 = stack[-2];
        popv(4);
        return cons(v147, v131);
    }

v120:
    v131 = stack[0];
    stack[-2] = qcar(v131);
    v132 = stack[-1];
    v131 = stack[0];
    v131 = qcdr(v131);
    v131 = CC_dp_sum(env, v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v146;
    {
        Lisp_Object v134 = stack[-2];
        popv(4);
        return cons(v134, v131);
    }

v105:
    v131 = stack[-1];
    stack[-2] = qcar(v131);
    v131 = stack[-1];
    v132 = qcdr(v131);
    v131 = stack[0];
    v131 = CC_dp_sum(env, v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v146;
    {
        Lisp_Object v135 = stack[-2];
        popv(4);
        return cons(v135, v131);
    }
/* error exit handlers */
v146:
    popv(4);
    return nil;
}



/* Code for pv_sort2a */

static Lisp_Object CC_pv_sort2a(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v51;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_sort2a");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v29;
    stack[-1] = v0;
/* end of prologue */

v24:
    v116 = stack[0];
    v116 = qcdr(v116);
    if (v116 == nil) goto v20;
    v116 = stack[-1];
    v51 = qcdr(v116);
    v116 = stack[0];
    v116 = qcar(v116);
    v116 = qcdr(v116);
    v116 = (Lisp_Object)greaterp2(v51, v116);
    nil = C_nil;
    if (exception_pending()) goto v55;
    v116 = v116 ? lisp_true : nil;
    env = stack[-3];
    if (v116 == nil) goto v26;
    v116 = stack[0];
    v116 = qcdr(v116);
    stack[0] = v116;
    goto v24;

v26:
    v116 = stack[0];
    v51 = qcar(v116);
    v116 = stack[0];
    v116 = qcdr(v116);
    v116 = cons(v51, v116);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    stack[-2] = v116;
    v51 = stack[0];
    v116 = stack[-1];
    v51 = Lrplaca(nil, v51, v116);
    nil = C_nil;
    if (exception_pending()) goto v55;
    v116 = stack[-2];
        popv(4);
        return Lrplacd(nil, v51, v116);

v20:
    v116 = stack[-1];
    v51 = qcdr(v116);
    v116 = stack[0];
    v116 = qcar(v116);
    v116 = qcdr(v116);
    v116 = (Lisp_Object)greaterp2(v51, v116);
    nil = C_nil;
    if (exception_pending()) goto v55;
    v116 = v116 ? lisp_true : nil;
    env = stack[-3];
    if (v116 == nil) goto v76;
    v116 = stack[-1];
    v116 = ncons(v116);
    nil = C_nil;
    if (exception_pending()) goto v55;
    {
        Lisp_Object v117 = stack[0];
        popv(4);
        return Lrplacd(nil, v117, v116);
    }

v76:
    v116 = stack[0];
    v51 = qcar(v116);
    v116 = stack[0];
    v116 = qcdr(v116);
    v116 = cons(v51, v116);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    stack[-2] = v116;
    v51 = stack[0];
    v116 = stack[-1];
    v51 = Lrplaca(nil, v51, v116);
    nil = C_nil;
    if (exception_pending()) goto v55;
    v116 = stack[-2];
        popv(4);
        return Lrplacd(nil, v51, v116);
/* error exit handlers */
v55:
    popv(4);
    return nil;
}



/* Code for ordn */

static Lisp_Object CC_ordn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordn");
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
    v8 = stack[0];
    if (v8 == nil) goto v31;
    v8 = stack[0];
    v8 = qcdr(v8);
    if (v8 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v8 = stack[0];
    v8 = qcdr(v8);
    v8 = qcdr(v8);
    if (v8 == nil) goto v81;
    v8 = stack[0];
    stack[-1] = qcar(v8);
    v8 = stack[0];
    v8 = qcdr(v8);
    v8 = CC_ordn(env, v8);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    {
        Lisp_Object v47 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* ordad */
        return (*qfn2(fn))(qenv(fn), v47, v8);
    }

v81:
    v8 = stack[0];
    v9 = qcar(v8);
    v8 = stack[0];
    v8 = qcdr(v8);
    v8 = qcar(v8);
    fn = elt(env, 3); /* ordp */
    v8 = (*qfn2(fn))(qenv(fn), v9, v8);
    nil = C_nil;
    if (exception_pending()) goto v122;
    if (v8 == nil) goto v114;
    v8 = stack[0];
    v9 = qcar(v8);
    v8 = stack[0];
    v8 = qcdr(v8);
    v8 = qcar(v8);
    popv(3);
    return list2(v9, v8);

v114:
    v8 = stack[0];
    v8 = qcdr(v8);
    v9 = qcar(v8);
    v8 = stack[0];
    v8 = qcar(v8);
    popv(3);
    return list2(v9, v8);

v31:
    v8 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v8); }
/* error exit handlers */
v122:
    popv(3);
    return nil;
}



/* Code for general!-times!-term!-mod!-p */

static Lisp_Object CC_generalKtimesKtermKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v57, v156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-times-term-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v29;
    stack[-2] = v0;
/* end of prologue */
    v56 = stack[-1];
    if (v56 == nil) goto v24;
    v56 = stack[-1];
    if (!consp(v56)) goto v20;
    v56 = stack[-1];
    v56 = qcar(v56);
    if (!consp(v56)) goto v20;
    v56 = stack[-2];
    v56 = qcar(v56);
    v57 = qcar(v56);
    v56 = stack[-1];
    v56 = qcar(v56);
    v56 = qcar(v56);
    v56 = qcar(v56);
    if (equal(v57, v56)) goto v74;
    v56 = stack[-2];
    v56 = qcar(v56);
    v57 = qcar(v56);
    v56 = stack[-1];
    v56 = qcar(v56);
    v56 = qcar(v56);
    v56 = qcar(v56);
    fn = elt(env, 2); /* ordop */
    v56 = (*qfn2(fn))(qenv(fn), v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    if (v56 == nil) goto v132;
    v56 = stack[-2];
    stack[0] = qcar(v56);
    v56 = stack[-2];
    v57 = qcdr(v56);
    v56 = stack[-1];
    fn = elt(env, 3); /* general!-times!-mod!-p */
    v57 = (*qfn2(fn))(qenv(fn), v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v56 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v158 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v158, v57, v56);
    }

v132:
    v56 = stack[-1];
    v56 = qcar(v56);
    stack[-3] = qcar(v56);
    v57 = stack[-2];
    v56 = stack[-1];
    v56 = qcar(v56);
    v56 = qcdr(v56);
    stack[0] = CC_generalKtimesKtermKmodKp(env, v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v57 = stack[-2];
    v56 = stack[-1];
    v56 = qcdr(v56);
    v56 = CC_generalKtimesKtermKmodKp(env, v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    {
        Lisp_Object v159 = stack[-3];
        Lisp_Object v160 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v159, v160, v56);
    }

v74:
    v56 = stack[-2];
    v56 = qcar(v56);
    v56 = qcar(v56);
    fn = elt(env, 5); /* fkern */
    v156 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v56 = stack[-2];
    v56 = qcar(v56);
    v57 = qcdr(v56);
    v56 = stack[-1];
    v56 = qcar(v56);
    v56 = qcar(v56);
    v56 = qcdr(v56);
    v56 = (Lisp_Object)(int32_t)((int32_t)v57 + (int32_t)v56 - TAG_FIXNUM);
    fn = elt(env, 6); /* getpower */
    stack[-3] = (*qfn2(fn))(qenv(fn), v156, v56);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v56 = stack[-2];
    v57 = qcdr(v56);
    v56 = stack[-1];
    v56 = qcar(v56);
    v56 = qcdr(v56);
    fn = elt(env, 3); /* general!-times!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v57 = stack[-2];
    v56 = stack[-1];
    v56 = qcdr(v56);
    v56 = CC_generalKtimesKtermKmodKp(env, v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    {
        Lisp_Object v58 = stack[-3];
        Lisp_Object v161 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v58, v161, v56);
    }

v20:
    v56 = stack[-2];
    stack[0] = qcar(v56);
    v56 = stack[-2];
    v57 = qcdr(v56);
    v56 = stack[-1];
    fn = elt(env, 7); /* gen!-mult!-by!-const!-mod!-p */
    v57 = (*qfn2(fn))(qenv(fn), v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v56 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v59 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v59, v57, v56);
    }

v24:
    v56 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v56); }
/* error exit handlers */
v157:
    popv(5);
    return nil;
}



/* Code for cl_varl1 */

static Lisp_Object CC_cl_varl1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20, v103, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_varl1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v19 = v0;
/* end of prologue */
    v46 = v19;
    v103 = qvalue(elt(env, 1)); /* nil */
    v20 = qvalue(elt(env, 1)); /* nil */
    v19 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* cl_varl2 */
        return (*qfnn(fn))(qenv(fn), 4, v46, v103, v20, v19);
    }
}



/* Code for stable!-sortip */

static Lisp_Object CC_stableKsortip(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v168, v169, v170;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for stable-sortip");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v29;
    stack[-3] = v0;
/* end of prologue */
    v168 = stack[-3];
    if (v168 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v168 = stack[-3];
    stack[-4] = v168;
    v168 = stack[-3];
    v168 = qcdr(v168);
    stack[-1] = v168;
    v168 = stack[-1];
    if (v168 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v168 = stack[-1];
    v168 = qcdr(v168);
    stack[-3] = v168;
    v168 = stack[-3];
    if (v168 == nil) goto v123;
    v168 = stack[-4];
    stack[-3] = v168;
    goto v8;

v8:
    v168 = stack[-1];
    if (v168 == nil) goto v120;
    v170 = stack[-2];
    v168 = stack[-1];
    v169 = qcar(v168);
    v168 = stack[-3];
    v168 = qcar(v168);
    v168 = Lapply2(nil, 3, v170, v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-5];
    if (!(v168 == nil)) goto v120;
    v168 = stack[-1];
    stack[-3] = v168;
    v168 = stack[-1];
    v168 = qcdr(v168);
    stack[-1] = v168;
    goto v8;

v120:
    v168 = stack[-1];
    if (v168 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v168 = stack[-4];
    stack[-1] = v168;
    v168 = stack[-1];
    v168 = qcdr(v168);
    v168 = qcdr(v168);
    stack[-3] = v168;
    goto v116;

v116:
    v168 = stack[-3];
    if (v168 == nil) goto v115;
    v168 = stack[-3];
    v168 = qcdr(v168);
    if (v168 == nil) goto v115;
    v168 = stack[-1];
    v168 = qcdr(v168);
    stack[-1] = v168;
    v168 = stack[-3];
    v168 = qcdr(v168);
    v168 = qcdr(v168);
    stack[-3] = v168;
    goto v116;

v115:
    v168 = stack[-1];
    stack[-3] = v168;
    v168 = stack[-1];
    v168 = qcdr(v168);
    stack[-1] = v168;
    v169 = stack[-3];
    v168 = qvalue(elt(env, 1)); /* nil */
    v168 = Lrplacd(nil, v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-5];
    v169 = stack[-4];
    v168 = stack[-2];
    v168 = CC_stableKsortip(env, v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-5];
    stack[-4] = v168;
    v169 = stack[-1];
    v168 = stack[-2];
    v168 = CC_stableKsortip(env, v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-5];
    stack[-1] = v168;
    v168 = qvalue(elt(env, 1)); /* nil */
    v168 = ncons(v168);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-5];
    stack[0] = v168;
    stack[-3] = v168;
    goto v172;

v172:
    v168 = stack[-4];
    if (v168 == nil) goto v173;
    v168 = stack[-1];
    if (v168 == nil) goto v173;
    v170 = stack[-2];
    v168 = stack[-1];
    v169 = qcar(v168);
    v168 = stack[-4];
    v168 = qcar(v168);
    v168 = Lapply2(nil, 3, v170, v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-5];
    if (v168 == nil) goto v174;
    v169 = stack[0];
    v168 = stack[-1];
    v168 = Lrplacd(nil, v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-5];
    v168 = stack[-1];
    stack[0] = v168;
    v168 = stack[-1];
    v168 = qcdr(v168);
    stack[-1] = v168;
    goto v172;

v174:
    v169 = stack[0];
    v168 = stack[-4];
    v168 = Lrplacd(nil, v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-5];
    v168 = stack[-4];
    stack[0] = v168;
    v168 = stack[-4];
    v168 = qcdr(v168);
    stack[-4] = v168;
    goto v172;

v173:
    v168 = stack[-4];
    if (v168 == nil) goto v175;
    v168 = stack[-4];
    stack[-1] = v168;
    goto v175;

v175:
    v169 = stack[0];
    v168 = stack[-1];
    v168 = Lrplacd(nil, v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v171;
    v168 = stack[-3];
    v168 = qcdr(v168);
    { popv(6); return onevalue(v168); }

v123:
    v170 = stack[-2];
    v168 = stack[-1];
    v169 = qcar(v168);
    v168 = stack[-4];
    v168 = qcar(v168);
    v168 = Lapply2(nil, 3, v170, v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-5];
    if (v168 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v168 = stack[-4];
    v168 = qcar(v168);
    stack[-3] = v168;
    v169 = stack[-4];
    v168 = stack[-1];
    v168 = qcar(v168);
    v168 = Lrplaca(nil, v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-5];
    v169 = stack[-1];
    v168 = stack[-3];
    v168 = Lrplaca(nil, v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v171;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v171:
    popv(6);
    return nil;
}



/* Code for ckrn1 */

static Lisp_Object CC_ckrn1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ckrn1");
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
    v109 = stack[0];
    if (!consp(v109)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v109 = stack[0];
    v109 = qcar(v109);
    if (!consp(v109)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    else goto v20;

v20:
    v109 = stack[0];
    v109 = qcar(v109);
    v109 = qcdr(v109);
    v140 = CC_ckrn1(env, v109);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-2];
    v109 = stack[-1];
    fn = elt(env, 2); /* gck2 */
    v109 = (*qfn2(fn))(qenv(fn), v140, v109);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-2];
    stack[-1] = v109;
    v109 = stack[0];
    v109 = qcdr(v109);
    if (v109 == nil) goto v69;
    v109 = stack[0];
    v109 = qcdr(v109);
    if (!consp(v109)) goto v177;
    v109 = stack[0];
    v109 = qcdr(v109);
    v109 = qcar(v109);
    if (!consp(v109)) goto v177;
    v109 = stack[0];
    v109 = qcar(v109);
    v109 = qcar(v109);
    v140 = qcar(v109);
    v109 = stack[0];
    v109 = qcdr(v109);
    v109 = qcar(v109);
    v109 = qcar(v109);
    v109 = qcar(v109);
    if (!(v140 == v109)) goto v177;
    v109 = stack[0];
    v109 = qcdr(v109);
    stack[0] = v109;
    goto v20;

v177:
    v109 = stack[0];
    v109 = qcdr(v109);
    v140 = CC_ckrn1(env, v109);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-2];
    v109 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* gck2 */
        return (*qfn2(fn))(qenv(fn), v140, v109);
    }

v69:
    v109 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v109 == nil) goto v75;
    v109 = stack[0];
    v109 = qcar(v109);
    v109 = qcar(v109);
    v109 = qcar(v109);
    fn = elt(env, 3); /* noncomp1 */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-2];
    if (!(v109 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v75:
    v109 = stack[0];
    v109 = qcar(v109);
    v140 = qcar(v109);
    v109 = stack[-1];
    v109 = cons(v140, v109);
    nil = C_nil;
    if (exception_pending()) goto v2;
    popv(3);
    return ncons(v109);
/* error exit handlers */
v2:
    popv(3);
    return nil;
}



/* Code for rl_prepat */

static Lisp_Object CC_rl_prepat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_prepat");
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
    v95 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_prepat!* */
    v95 = ncons(v95);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-1];
    {
        Lisp_Object v94 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v94, v95);
    }
/* error exit handlers */
v93:
    popv(2);
    return nil;
}



/* Code for pasf_susipost */

static Lisp_Object CC_pasf_susipost(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object v31, v24;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_susipost");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v31 = v29;
    v24 = v0;
/* end of prologue */
    return onevalue(v24);
}



/* Code for ibalp_varlt1 */

static Lisp_Object CC_ibalp_varlt1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v112, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_varlt1");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v29;
    v113 = v0;
/* end of prologue */
    v112 = v113;
    v27 = (Lisp_Object)1; /* 0 */
    if (v112 == v27) goto v37;
    v112 = v113;
    v27 = (Lisp_Object)17; /* 1 */
    if (v112 == v27) goto v37;
    v27 = v113;
    if (symbolp(v27)) goto v17;
    v27 = v113;
    fn = elt(env, 2); /* ibalp_argn */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-2];
    stack[-1] = v27;
    goto v14;

v14:
    v27 = stack[-1];
    if (v27 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v27 = stack[-1];
    v27 = qcar(v27);
    v112 = v27;
    v27 = stack[0];
    v27 = CC_ibalp_varlt1(env, v112, v27);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-2];
    stack[0] = v27;
    v27 = stack[-1];
    v27 = qcdr(v27);
    stack[-1] = v27;
    goto v14;

v17:
    v112 = v113;
    v27 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* lto_insertq */
        return (*qfn2(fn))(qenv(fn), v112, v27);
    }

v37:
    v27 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v27); }
/* error exit handlers */
v8:
    popv(3);
    return nil;
}



/* Code for ratpoly_mvartest */

static Lisp_Object CC_ratpoly_mvartest(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v102, v16;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_mvartest");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v102 = v29;
    v16 = v0;
/* end of prologue */
    v69 = v16;
    v69 = qcar(v69);
    if (v69 == nil) goto v24;
    v69 = v16;
    v69 = qcar(v69);
    if (is_number(v69)) goto v104;
    v69 = v16;
    v69 = qcar(v69);
    v69 = qcar(v69);
    v69 = qcar(v69);
    v69 = qcar(v69);
    v69 = (v69 == v102 ? lisp_true : nil);
    return onevalue(v69);

v104:
    v69 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v69);

v24:
    v69 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v69);
}



/* Code for ev_comp */

static Lisp_Object CC_ev_comp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_comp");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v103 = v29;
    v46 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dip_sortevcomp!* */
    v103 = list2(v46, v103);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    {
        Lisp_Object v97 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v97, v103);
    }
/* error exit handlers */
v33:
    popv(2);
    return nil;
}



/* Code for letmtr3 */

static Lisp_Object MS_CDECL CC_letmtr3(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v29,
                         Lisp_Object v86, Lisp_Object v32, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v216, v217, v218, v219, v220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "letmtr3");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for letmtr3");
#endif
    if (stack >= stacklimit)
    {
        push4(v32,v86,v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v29,v86,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v32;
    stack[-1] = v86;
    stack[-2] = v29;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    v216 = stack[-3];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    if (v216 == nil) goto v43;
    v217 = stack[-1];
    v216 = elt(env, 1); /* sparsemat */
    if (!consp(v217)) goto v53;
    v217 = qcar(v217);
    if (!(v217 == v216)) goto v53;
    v216 = stack[-3];
    v216 = qcdr(v216);
    fn = elt(env, 11); /* revlis */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    stack[-4] = v216;
    fn = elt(env, 12); /* numlis */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    if (v216 == nil) goto v222;
    v216 = stack[-4];
    v217 = Llength(nil, v216);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    v216 = (Lisp_Object)33; /* 2 */
    if (!(v217 == v216)) goto v222;

v160:
    v216 = stack[-1];
    v216 = qcdr(v216);
    v217 = qcar(v216);
    v216 = stack[-4];
    v216 = qcar(v216);
    v216 = *(Lisp_Object *)((char *)v217 + (CELL-TAG_VECTOR) + ((int32_t)v216/(16/CELL)));
    v219 = v216;
    v216 = v219;
    if (v216 == nil) goto v223;
    v216 = stack[-4];
    v216 = qcdr(v216);
    v217 = qcar(v216);
    v216 = v219;
    v216 = Latsoc(nil, v217, v216);
    v218 = v216;
    v216 = v218;
    if (v216 == nil) goto v224;
    v217 = stack[-2];
    v216 = (Lisp_Object)1; /* 0 */
    if (!(v217 == v216)) goto v225;
    v217 = stack[0];
    v216 = elt(env, 10); /* cx */
    if (v217 == v216) goto v225;
    v216 = v219;
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    if (v216 == nil) goto v226;
    stack[0] = v219;
    v216 = v218;
    v217 = v219;
    v216 = Ldelete(nil, v216, v217);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    v216 = qcdr(v216);
    v216 = Lrplacd(nil, stack[0], v216);
    nil = C_nil;
    if (exception_pending()) goto v221;
    goto v20;

v20:
    v216 = nil;
    { popv(6); return onevalue(v216); }

v226:
    v216 = stack[-1];
    v216 = qcdr(v216);
    v217 = qcar(v216);
    v216 = stack[-4];
    v216 = qcar(v216);
    v218 = qvalue(elt(env, 8)); /* nil */
    *(Lisp_Object *)((char *)v217 + (CELL-TAG_VECTOR) + ((int32_t)v216/(16/CELL))) = v218;
    goto v20;

v225:
    v217 = v218;
    v216 = stack[-2];
    v216 = Lrplacd(nil, v217, v216);
    nil = C_nil;
    if (exception_pending()) goto v221;
    goto v20;

v224:
    v217 = stack[-2];
    v216 = (Lisp_Object)1; /* 0 */
    if (!(v217 == v216)) goto v227;
    v217 = stack[0];
    v216 = elt(env, 10); /* cx */
    if (!(v217 == v216)) goto v20;

v227:
    v216 = stack[-4];
    v216 = qcdr(v216);
    v217 = qcar(v216);
    v218 = v219;
    v216 = stack[-2];
    fn = elt(env, 13); /* sortcolelem */
    v216 = (*qfnn(fn))(qenv(fn), 3, v217, v218, v216);
    nil = C_nil;
    if (exception_pending()) goto v221;
    goto v20;

v223:
    v217 = stack[-2];
    v216 = (Lisp_Object)1; /* 0 */
    if (!(v217 == v216)) goto v162;
    v217 = stack[0];
    v216 = elt(env, 10); /* cx */
    if (!(v217 == v216)) goto v20;

v162:
    v216 = stack[-1];
    v216 = qcdr(v216);
    stack[-3] = qcar(v216);
    v216 = stack[-4];
    stack[-1] = qcar(v216);
    v216 = qvalue(elt(env, 8)); /* nil */
    stack[0] = ncons(v216);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    v216 = stack[-4];
    v216 = qcdr(v216);
    v217 = qcar(v216);
    v216 = stack[-2];
    v216 = cons(v217, v216);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    v216 = list2(stack[0], v216);
    nil = C_nil;
    if (exception_pending()) goto v221;
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v216;
    goto v20;

v222:
    v220 = elt(env, 6); /* "Syntax error:" */
    v219 = stack[-3];
    v218 = elt(env, 7); /* "invalid" */
    v217 = qvalue(elt(env, 8)); /* nil */
    v216 = elt(env, 9); /* hold */
    {
        popv(6);
        fn = elt(env, 14); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v220, v219, v218, v217, v216);
    }

v53:
    v218 = elt(env, 2); /* "Matrix" */
    v216 = stack[-3];
    v217 = qcar(v216);
    v216 = elt(env, 3); /* "not set" */
    v216 = list3(v218, v217, v216);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    v217 = v216;
    v216 = v217;
    qvalue(elt(env, 4)) = v216; /* errmsg!* */
    v216 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v216 == nil)) goto v131;
    v216 = v217;
    fn = elt(env, 15); /* lprie */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    goto v131;

v131:
    v216 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    goto v160;

v43:
    v217 = stack[-1];
    v216 = elt(env, 1); /* sparsemat */
    if (!consp(v217)) goto v45;
    v217 = qcar(v217);
    if (!(v217 == v216)) goto v45;
    v216 = stack[-3];
    v216 = qcdr(v216);
    fn = elt(env, 11); /* revlis */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    stack[-4] = v216;
    fn = elt(env, 12); /* numlis */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    if (v216 == nil) goto v48;
    v216 = stack[-4];
    v217 = Llength(nil, v216);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    v216 = (Lisp_Object)17; /* 1 */
    if (!(v217 == v216)) goto v48;

v28:
    v216 = stack[-1];
    v216 = qcdr(v216);
    v218 = qcar(v216);
    v216 = stack[-3];
    v216 = qcdr(v216);
    v217 = qcar(v216);
    v216 = stack[-2];
    *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL))) = v216;
    goto v20;

v48:
    v220 = elt(env, 6); /* "Syntax error:" */
    v219 = stack[-3];
    v218 = elt(env, 7); /* "invalid" */
    v217 = qvalue(elt(env, 8)); /* nil */
    v216 = elt(env, 9); /* hold */
    {
        popv(6);
        fn = elt(env, 14); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v220, v219, v218, v217, v216);
    }

v45:
    v218 = elt(env, 2); /* "Matrix" */
    v216 = stack[-3];
    v217 = qcar(v216);
    v216 = elt(env, 3); /* "not set" */
    v216 = list3(v218, v217, v216);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    v217 = v216;
    v216 = v217;
    qvalue(elt(env, 4)) = v216; /* errmsg!* */
    v216 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v216 == nil)) goto v12;
    v216 = v217;
    fn = elt(env, 15); /* lprie */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-5];
    goto v12;

v12:
    v216 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v221;
    goto v28;
/* error exit handlers */
v221:
    popv(6);
    return nil;
}



/* Code for mintype */

static Lisp_Object CC_mintype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v93;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mintype");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v49 = v0;
/* end of prologue */
    v93 = v49;
    if (!consp(v93)) return onevalue(v49);
    v49 = qcar(v49);
    return onevalue(v49);
}



/* Code for off_mod_reval */

static Lisp_Object CC_off_mod_reval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for off_mod_reval");
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
    v81 = qvalue(elt(env, 1)); /* !*modular */
    if (v81 == nil) goto v103;
    v81 = elt(env, 2); /* modular */
    v81 = ncons(v81);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-1];
    fn = elt(env, 4); /* off */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-1];
    v81 = stack[0];
    fn = elt(env, 5); /* reval */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-1];
    stack[0] = v81;
    v81 = elt(env, 2); /* modular */
    v81 = ncons(v81);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-1];
    fn = elt(env, 6); /* on */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v91;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v103:
    v81 = stack[0];
    fn = elt(env, 5); /* reval */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v91;
    stack[0] = v81;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v91:
    popv(2);
    return nil;
}



/* Code for bcsum */

static Lisp_Object CC_bcsum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v15, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcsum");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v29;
    stack[-1] = v0;
/* end of prologue */
    v14 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v14 == nil) goto v81;
    v15 = stack[-1];
    v14 = stack[0];
    v14 = plus2(v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v14);
    }

v81:
    v99 = stack[-1];
    v15 = stack[0];
    v14 = elt(env, 2); /* plus2 */
    fn = elt(env, 4); /* bcint2op */
    v14 = (*qfnn(fn))(qenv(fn), 3, v99, v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    if (!(v14 == nil)) { popv(3); return onevalue(v14); }
    v15 = stack[-1];
    v14 = stack[0];
    fn = elt(env, 5); /* addsq */
    v14 = (*qfn2(fn))(qenv(fn), v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); /* bccheckz */
        return (*qfn1(fn))(qenv(fn), v14);
    }
/* error exit handlers */
v114:
    popv(3);
    return nil;
}



/* Code for contr1!-strand */

static Lisp_Object CC_contr1Kstrand(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v103, v46, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contr1-strand");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v20 = v29;
    v103 = v0;
/* end of prologue */
    v100 = v103;
    v46 = v20;
    v103 = qvalue(elt(env, 1)); /* nil */
    v20 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* contr2!-strand */
        return (*qfnn(fn))(qenv(fn), 4, v100, v46, v103, v20);
    }
}



/* Code for add2resultbuf */

static Lisp_Object CC_add2resultbuf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v47, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add2resultbuf");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v122 = v29;
    stack[0] = v0;
/* end of prologue */
    v48 = v122;
    v47 = elt(env, 1); /* symbolic */
    if (v48 == v47) goto v37;
    v47 = stack[0];
    if (!(v47 == nil)) goto v20;
    v47 = qvalue(elt(env, 2)); /* !*reduce4 */
    if (v47 == nil) goto v37;
    v48 = v122;
    v47 = elt(env, 3); /* empty_list */
    if (!(v48 == v47)) goto v37;

v20:
    v47 = qvalue(elt(env, 4)); /* !*nosave!* */
    if (!(v47 == nil)) goto v37;
    v47 = qvalue(elt(env, 2)); /* !*reduce4 */
    if (v47 == nil) goto v75;
    v48 = elt(env, 6); /* ws */
    v47 = stack[0];
    fn = elt(env, 12); /* putobject */
    v122 = (*qfnn(fn))(qenv(fn), 3, v48, v47, v122);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-1];
    goto v123;

v123:
    v122 = qvalue(elt(env, 8)); /* !*int */
    if (v122 == nil) goto v36;
    v122 = qvalue(elt(env, 9)); /* ifl!* */
    if (!(v122 == nil)) goto v36;
    v48 = qvalue(elt(env, 10)); /* statcounter */
    v47 = stack[0];
    v122 = qvalue(elt(env, 11)); /* resultbuflis!* */
    v122 = acons(v48, v47, v122);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-1];
    qvalue(elt(env, 11)) = v122; /* resultbuflis!* */
    goto v36;

v36:
    v122 = nil;
    { popv(2); return onevalue(v122); }

v75:
    v122 = qvalue(elt(env, 5)); /* nil */
    v122 = ncons(v122);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-1];
    qvalue(elt(env, 7)) = v122; /* alglist!* */
    v122 = stack[0];
    qvalue(elt(env, 6)) = v122; /* ws */
    goto v123;

v37:
    v122 = qvalue(elt(env, 5)); /* nil */
    { popv(2); return onevalue(v122); }
/* error exit handlers */
v176:
    popv(2);
    return nil;
}



/* Code for errorset2 */

static Lisp_Object CC_errorset2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v103, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for errorset2");
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
    stack[0] = qvalue(elt(env, 1)); /* !*protfg */
    qvalue(elt(env, 1)) = nil; /* !*protfg */
    v20 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v20; /* !*protfg */
    v46 = v103;
    v103 = qvalue(elt(env, 3)); /* nil */
    v20 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 4); /* errorset */
    v20 = (*qfnn(fn))(qenv(fn), 3, v46, v103, v20);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*protfg */
    { popv(2); return onevalue(v20); }
/* error exit handlers */
v33:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*protfg */
    popv(2);
    return nil;
}



/* Code for mv!-pow!-mv!-term!-!+ */

static Lisp_Object CC_mvKpowKmvKtermKL(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-mv-term-+");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v29;
    v100 = v0;
/* end of prologue */
    v33 = v100;
    v100 = stack[0];
    v100 = qcar(v100);
    fn = elt(env, 1); /* mv!-pow!-!+ */
    v33 = (*qfn2(fn))(qenv(fn), v33, v100);
    nil = C_nil;
    if (exception_pending()) goto v81;
    v100 = stack[0];
    v100 = qcdr(v100);
    popv(1);
    return cons(v33, v100);
/* error exit handlers */
v81:
    popv(1);
    return nil;
}



/* Code for groeb!=testa */

static Lisp_Object CC_groebMtesta(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=testa");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v29;
    v34 = v0;
/* end of prologue */
    v43 = v34;
    v34 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* pnth */
    v34 = (*qfn2(fn))(qenv(fn), v43, v34);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    stack[-1] = qcar(v34);
    v43 = stack[0];
    v34 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* pnth */
    v34 = (*qfn2(fn))(qenv(fn), v43, v34);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    v34 = qcar(v34);
    {
        Lisp_Object v17 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* mo_divides!? */
        return (*qfn2(fn))(qenv(fn), v17, v34);
    }
/* error exit handlers */
v16:
    popv(3);
    return nil;
}



/* Code for tsym4 */

static Lisp_Object MS_CDECL CC_tsym4(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v29,
                         Lisp_Object v86, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "tsym4");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tsym4");
#endif
    if (stack >= stacklimit)
    {
        push3(v86,v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v29,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v86;
    stack[-1] = v29;
    v99 = v0;
/* end of prologue */

v37:
    v87 = v99;
    if (v87 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v87 = v99;
    v87 = qcdr(v87);
    stack[-2] = v87;
    v87 = stack[-1];
    v87 = qcdr(v87);
    v99 = qcar(v99);
    fn = elt(env, 1); /* pv_applp */
    v87 = (*qfn2(fn))(qenv(fn), v87, v99);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v99 = stack[0];
    fn = elt(env, 2); /* sieve_pv */
    v99 = (*qfn2(fn))(qenv(fn), v87, v99);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    fn = elt(env, 3); /* pv_renorm */
    v87 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v99 = stack[0];
    fn = elt(env, 4); /* insert_pv */
    v99 = (*qfn2(fn))(qenv(fn), v87, v99);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    stack[0] = v99;
    v99 = stack[-2];
    goto v37;
/* error exit handlers */
v155:
    popv(4);
    return nil;
}



/* Code for times!-in!-vector */

static Lisp_Object MS_CDECL CC_timesKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v29,
                         Lisp_Object v86, Lisp_Object v32,
                         Lisp_Object v31, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v57, v156, v230, v60, v210, v211, v157, v158, v159, v160, v58, v161, v59, v231;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "times-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for times-in-vector");
#endif
    if (stack >= stacklimit)
    {
        push5(v31,v32,v86,v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v29,v86,v32,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v159 = v31;
    v160 = v32;
    v58 = v86;
    v161 = v29;
    v59 = v0;
/* end of prologue */
    v57 = v161;
    v56 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v57)) < ((int32_t)(v56))) goto v93;
    v57 = v160;
    v56 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v57)) < ((int32_t)(v56))) goto v93;
    v57 = v161;
    v56 = v160;
    v56 = (Lisp_Object)(int32_t)((int32_t)v57 + (int32_t)v56 - TAG_FIXNUM);
    v231 = v56;
    v56 = (Lisp_Object)1; /* 0 */
    v230 = v56;
    goto v155;

v155:
    v57 = v231;
    v56 = v230;
    v56 = (Lisp_Object)(int32_t)((int32_t)v57 - (int32_t)v56 + TAG_FIXNUM);
    v56 = ((intptr_t)(v56) < 0 ? lisp_true : nil);
    if (v56 == nil) goto v74;
    v56 = (Lisp_Object)1; /* 0 */
    v157 = v56;
    goto v7;

v7:
    v57 = v161;
    v56 = v157;
    v56 = (Lisp_Object)(int32_t)((int32_t)v57 - (int32_t)v56 + TAG_FIXNUM);
    v56 = ((intptr_t)(v56) < 0 ? lisp_true : nil);
    if (!(v56 == nil)) { popv(1); return onevalue(v231); }
    v57 = v59;
    v56 = v157;
    v56 = *(Lisp_Object *)((char *)v57 + (CELL-TAG_VECTOR) + ((int32_t)v56/(16/CELL)));
    v158 = v56;
    v56 = (Lisp_Object)1; /* 0 */
    v211 = v56;
    goto v116;

v116:
    v57 = v160;
    v56 = v211;
    v56 = (Lisp_Object)(int32_t)((int32_t)v57 - (int32_t)v56 + TAG_FIXNUM);
    v56 = ((intptr_t)(v56) < 0 ? lisp_true : nil);
    if (v56 == nil) goto v232;
    v56 = v157;
    v56 = (Lisp_Object)((int32_t)(v56) + 0x10);
    v157 = v56;
    goto v7;

v232:
    v57 = v157;
    v56 = v211;
    v56 = (Lisp_Object)(int32_t)((int32_t)v57 + (int32_t)v56 - TAG_FIXNUM);
    v210 = v159;
    v60 = v56;
    v57 = v159;
    v230 = *(Lisp_Object *)((char *)v57 + (CELL-TAG_VECTOR) + ((int32_t)v56/(16/CELL)));
    v156 = v158;
    v57 = v58;
    v56 = v211;
    v56 = *(Lisp_Object *)((char *)v57 + (CELL-TAG_VECTOR) + ((int32_t)v56/(16/CELL)));
    v56 = Lmodular_times(nil, v156, v56);
    env = stack[0];
    {   int32_t w = int_of_fixnum(v230) + int_of_fixnum(v56);
        if (w >= current_modulus) w -= current_modulus;
        v56 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v210 + (CELL-TAG_VECTOR) + ((int32_t)v60/(16/CELL))) = v56;
    v56 = v211;
    v56 = (Lisp_Object)((int32_t)(v56) + 0x10);
    v211 = v56;
    goto v116;

v74:
    v156 = v159;
    v57 = v230;
    v56 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v156 + (CELL-TAG_VECTOR) + ((int32_t)v57/(16/CELL))) = v56;
    v56 = v230;
    v56 = (Lisp_Object)((int32_t)(v56) + 0x10);
    v230 = v56;
    goto v155;

v93:
    v56 = (Lisp_Object)-15; /* -1 */
    { popv(1); return onevalue(v56); }
}



/* Code for !*i2gi */

static Lisp_Object CC_Hi2gi(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v94, v96;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *i2gi");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v93 = v0;
/* end of prologue */
    v96 = elt(env, 1); /* !:gi!: */
    v94 = v93;
    v93 = (Lisp_Object)1; /* 0 */
    return list2star(v96, v94, v93);
}



/* Code for diff */

static Lisp_Object CC_diff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v1;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v29;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    goto v37;

v37:
    v141 = stack[-3];
    if (!consp(v141)) goto v38;
    v141 = stack[-3];
    v141 = qcar(v141);
    if (!consp(v141)) goto v38;
    v141 = stack[-3];
    v141 = qcar(v141);
    v1 = qcar(v141);
    v141 = (Lisp_Object)17; /* 1 */
    v141 = cons(v1, v141);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    stack[0] = ncons(v141);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    v141 = stack[-3];
    v141 = qcar(v141);
    v1 = qcdr(v141);
    v141 = stack[-2];
    v141 = CC_diff(env, v1, v141);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    fn = elt(env, 2); /* multf */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v141);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    v141 = stack[-3];
    v141 = qcar(v141);
    stack[0] = qcdr(v141);
    v141 = stack[-3];
    v141 = qcar(v141);
    v1 = qcar(v141);
    v141 = stack[-2];
    fn = elt(env, 3); /* diffp1 */
    v141 = (*qfn2(fn))(qenv(fn), v1, v141);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    fn = elt(env, 2); /* multf */
    v141 = (*qfn2(fn))(qenv(fn), stack[0], v141);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    fn = elt(env, 4); /* addf */
    v1 = (*qfn2(fn))(qenv(fn), stack[-1], v141);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    v141 = stack[-4];
    v141 = cons(v1, v141);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    stack[-4] = v141;
    v141 = stack[-3];
    v141 = qcdr(v141);
    stack[-3] = v141;
    goto v37;

v38:
    v141 = qvalue(elt(env, 1)); /* nil */
    v1 = v141;
    goto v39;

v39:
    v141 = stack[-4];
    if (v141 == nil) { popv(6); return onevalue(v1); }
    v141 = stack[-4];
    v141 = qcar(v141);
    fn = elt(env, 4); /* addf */
    v141 = (*qfn2(fn))(qenv(fn), v141, v1);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    v1 = v141;
    v141 = stack[-4];
    v141 = qcdr(v141);
    stack[-4] = v141;
    goto v39;
/* error exit handlers */
v127:
    popv(6);
    return nil;
}



/* Code for sfto_davp */

static Lisp_Object CC_sfto_davp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v1;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_davp");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v29;
    stack[-1] = v0;
/* end of prologue */

v92:
    v141 = stack[-1];
    if (!consp(v141)) goto v39;
    v141 = stack[-1];
    v141 = qcar(v141);
    if (!consp(v141)) goto v39;
    v141 = stack[-1];
    v141 = qcar(v141);
    v141 = qcar(v141);
    v1 = qcdr(v141);
    v141 = (Lisp_Object)33; /* 2 */
    v141 = (Lisp_Object)greaterp2(v1, v141);
    nil = C_nil;
    if (exception_pending()) goto v21;
    v141 = v141 ? lisp_true : nil;
    env = stack[-2];
    if (v141 == nil) goto v108;
    v141 = stack[0];
    if (v141 == nil) goto v35;
    v141 = stack[-1];
    v141 = qcar(v141);
    v141 = qcar(v141);
    v1 = qcar(v141);
    v141 = stack[0];
    if (equal(v1, v141)) goto v35;
    v141 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v141); }

v35:
    v141 = stack[-1];
    v141 = qcar(v141);
    v1 = qcdr(v141);
    v141 = stack[-1];
    v141 = qcar(v141);
    v141 = qcar(v141);
    v141 = qcar(v141);
    v141 = CC_sfto_davp(env, v1, v141);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-2];
    if (v141 == nil) goto v122;
    v141 = stack[-1];
    v141 = qcdr(v141);
    v1 = v141;
    v141 = stack[-1];
    v141 = qcar(v141);
    v141 = qcar(v141);
    v141 = qcar(v141);
    stack[0] = v141;
    v141 = v1;
    stack[-1] = v141;
    goto v92;

v122:
    v141 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v141); }

v108:
    v141 = stack[-1];
    v141 = qcar(v141);
    v1 = qcdr(v141);
    v141 = stack[0];
    v141 = CC_sfto_davp(env, v1, v141);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-2];
    if (v141 == nil) goto v111;
    v141 = stack[-1];
    v141 = qcdr(v141);
    stack[-1] = v141;
    goto v92;

v111:
    v141 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v141); }

v39:
    v141 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v141); }
/* error exit handlers */
v21:
    popv(3);
    return nil;
}



/* Code for gcdf1 */

static Lisp_Object CC_gcdf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v244, v245;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdf1");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v29;
    stack[-2] = v0;
/* end of prologue */
    v244 = stack[-2];
    if (v244 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v244 = stack[-1];
    if (v244 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v245 = stack[-2];
    v244 = (Lisp_Object)17; /* 1 */
    if (v245 == v244) goto v19;
    v245 = stack[-1];
    v244 = (Lisp_Object)17; /* 1 */
    if (v245 == v244) goto v19;
    v244 = stack[-2];
    if (!consp(v244)) goto v114;
    v244 = stack[-2];
    v244 = qcar(v244);
    if (!consp(v244)) goto v114;
    v244 = stack[-1];
    if (!consp(v244)) goto v107;
    v244 = stack[-1];
    v244 = qcar(v244);
    if (!consp(v244)) goto v107;
    v244 = stack[-2];
    fn = elt(env, 14); /* num!-exponents */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    if (v244 == nil) goto v125;
    v244 = stack[-1];
    fn = elt(env, 14); /* num!-exponents */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    if (v244 == nil) goto v125;
    v245 = stack[-2];
    v244 = stack[-1];
    fn = elt(env, 15); /* quotf1 */
    v244 = (*qfn2(fn))(qenv(fn), v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    if (!(v244 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v245 = stack[-1];
    v244 = stack[-2];
    fn = elt(env, 15); /* quotf1 */
    v244 = (*qfn2(fn))(qenv(fn), v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    if (!(v244 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v125:
    v245 = stack[-2];
    v244 = stack[-1];
    fn = elt(env, 16); /* gcdf2 */
    v244 = (*qfn2(fn))(qenv(fn), v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    stack[-3] = v244;
    v244 = qvalue(elt(env, 3)); /* !*gcd */
    if (v244 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v245 = qvalue(elt(env, 1)); /* dmode!* */
    v244 = elt(env, 4); /* (!:rd!: !:cr!:) */
    v244 = Lmemq(nil, v245, v244);
    if (!(v244 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v245 = stack[-2];
    v244 = stack[-3];
    fn = elt(env, 15); /* quotf1 */
    v244 = (*qfn2(fn))(qenv(fn), v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    if (v244 == nil) goto v82;
    v245 = stack[-1];
    v244 = stack[-3];
    fn = elt(env, 15); /* quotf1 */
    v244 = (*qfn2(fn))(qenv(fn), v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    if (!(v244 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v82:
    v244 = qvalue(elt(env, 5)); /* !*ncmp */
    if (v244 == nil) goto v60;
    v244 = stack[-2];
    fn = elt(env, 17); /* noncomfp1 */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    if (!(v244 == nil)) goto v156;

v60:
    v244 = qvalue(elt(env, 5)); /* !*ncmp */
    if (v244 == nil) goto v209;
    v244 = stack[-1];
    fn = elt(env, 17); /* noncomfp1 */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    if (!(v244 == nil)) goto v156;

v209:
    v244 = qvalue(elt(env, 6)); /* t */
    fn = elt(env, 18); /* terpri!* */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    v244 = elt(env, 7); /* "CATASTROPHIC ERROR *****" */
    fn = elt(env, 19); /* lprie */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    stack[0] = elt(env, 8); /* "gcdf failed" */
    v245 = stack[-2];
    v244 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 20); /* prepf1 */
    v244 = (*qfn2(fn))(qenv(fn), v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    v245 = v244;
    v244 = v245;
    if (v244 == nil) goto v247;
    v244 = v245;
    fn = elt(env, 21); /* replus */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    stack[-2] = v244;
    goto v170;

v170:
    v245 = stack[-1];
    v244 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 20); /* prepf1 */
    v244 = (*qfn2(fn))(qenv(fn), v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    v245 = v244;
    v244 = v245;
    if (v244 == nil) goto v248;
    v244 = v245;
    fn = elt(env, 21); /* replus */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    goto v164;

v164:
    v244 = list3(stack[0], stack[-2], v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    fn = elt(env, 22); /* printty */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    v245 = elt(env, 10); /* " " */
    v244 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 23); /* lpriw */
    v244 = (*qfn2(fn))(qenv(fn), v245, v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    v244 = elt(env, 11); /* "Please report output and input listing on the sourceforge bug tracker" 
*/
    v245 = v244;
    v244 = v245;
    qvalue(elt(env, 12)) = v244; /* errmsg!* */
    v244 = qvalue(elt(env, 13)); /* !*protfg */
    if (!(v244 == nil)) goto v249;
    v244 = v245;
    fn = elt(env, 19); /* lprie */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-4];
    goto v249;

v249:
    v244 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v246;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v248:
    v244 = (Lisp_Object)1; /* 0 */
    goto v164;

v247:
    v244 = (Lisp_Object)1; /* 0 */
    stack[-2] = v244;
    goto v170;

v156:
    v244 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v244); }

v107:
    v245 = qvalue(elt(env, 1)); /* dmode!* */
    v244 = elt(env, 2); /* field */
    v244 = Lflagp(nil, v245, v244);
    env = stack[-4];
    if (v244 == nil) goto v5;
    v244 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v244); }

v5:
    v245 = stack[-1];
    v244 = stack[-2];
    {
        popv(5);
        fn = elt(env, 24); /* gcdfd1 */
        return (*qfn2(fn))(qenv(fn), v245, v244);
    }

v114:
    v245 = qvalue(elt(env, 1)); /* dmode!* */
    v244 = elt(env, 2); /* field */
    v244 = Lflagp(nil, v245, v244);
    env = stack[-4];
    if (v244 == nil) goto v88;
    v244 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v244); }

v88:
    v245 = stack[-2];
    v244 = stack[-1];
    {
        popv(5);
        fn = elt(env, 24); /* gcdfd1 */
        return (*qfn2(fn))(qenv(fn), v245, v244);
    }

v19:
    v244 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v244); }
/* error exit handlers */
v246:
    popv(5);
    return nil;
}



/* Code for unplus */

static Lisp_Object CC_unplus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v176, v6, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unplus");
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
    v7 = nil;
    goto v24;

v24:
    v176 = stack[-1];
    if (!consp(v176)) goto v49;
    v176 = stack[-1];
    v6 = qcar(v176);
    v176 = elt(env, 1); /* plus */
    if (v6 == v176) goto v46;
    v176 = stack[-1];
    v176 = qcar(v176);
    if (!consp(v176)) goto v114;
    v176 = stack[-1];
    v6 = qcar(v176);
    v176 = elt(env, 1); /* plus */
    if (!consp(v6)) goto v114;
    v6 = qcar(v6);
    if (!(v6 == v176)) goto v114;
    stack[-2] = v7;
    v176 = stack[-1];
    v176 = qcar(v176);
    stack[0] = qcdr(v176);
    v176 = stack[-1];
    v176 = qcdr(v176);
    v176 = CC_unplus(env, v176);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-3];
    v176 = Lappend(nil, stack[0], v176);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-3];
    {
        Lisp_Object v177 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v177, v176);
    }

v114:
    v176 = stack[-1];
    v176 = qcar(v176);
    v6 = v7;
    v176 = cons(v176, v6);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-3];
    v7 = v176;
    v176 = stack[-1];
    v176 = qcdr(v176);
    stack[-1] = v176;
    goto v24;

v46:
    v176 = stack[-1];
    v176 = qcdr(v176);
    stack[-1] = v176;
    goto v24;

v49:
    v6 = v7;
    v176 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v6, v176);
    }
/* error exit handlers */
v108:
    popv(4);
    return nil;
}



/* Code for ibalp_mk2 */

static Lisp_Object MS_CDECL CC_ibalp_mk2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v29,
                         Lisp_Object v86, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v19, v20;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ibalp_mk2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_mk2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v96 = v86;
    v19 = v29;
    v20 = v0;
/* end of prologue */
    return list3(v20, v19, v96);
}



/* Code for cgp_evlmon */

static Lisp_Object CC_cgp_evlmon(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_evlmon");
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
    v24 = v0;
/* end of prologue */
    fn = elt(env, 1); /* cgp_rp */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dip_evlmon */
        return (*qfn1(fn))(qenv(fn), v24);
    }
/* error exit handlers */
v92:
    popv(1);
    return nil;
}



/* Code for checktag */

static Lisp_Object CC_checktag(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checktag");
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
    v81 = v0;
/* end of prologue */
    v25 = qvalue(elt(env, 1)); /* char */
    if (equal(v25, v81)) goto v24;
    v25 = elt(env, 2); /* "Problem" */
    v81 = elt(env, 3); /* "problem" */
    fn = elt(env, 4); /* errorml */
    v81 = (*qfn2(fn))(qenv(fn), v25, v81);
    errexit();
    goto v24;

v24:
    v81 = nil;
    return onevalue(v81);
}



/* Code for initwght */

static Lisp_Object CC_initwght(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v243, v84, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for initwght");
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
    stack[-3] = v0;
/* end of prologue */
    v243 = (Lisp_Object)1; /* 0 */
    stack[-5] = v243;
    stack[0] = v243;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v84 = qvalue(elt(env, 2)); /* maxvar */
    v243 = stack[-3];
    v243 = plus2(v84, v243);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    v84 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v243/(16/CELL)));
    v243 = (Lisp_Object)65; /* 4 */
    v243 = *(Lisp_Object *)((char *)v84 + (CELL-TAG_VECTOR) + ((int32_t)v243/(16/CELL)));
    stack[-4] = v243;
    goto v104;

v104:
    v243 = stack[-4];
    if (v243 == nil) goto v85;
    v243 = stack[-4];
    v243 = qcar(v243);
    stack[-2] = v243;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v84 = qvalue(elt(env, 2)); /* maxvar */
    v243 = stack[-2];
    v243 = qcar(v243);
    v243 = plus2(v84, v243);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    v84 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v243/(16/CELL)));
    v243 = (Lisp_Object)1; /* 0 */
    v243 = *(Lisp_Object *)((char *)v84 + (CELL-TAG_VECTOR) + ((int32_t)v243/(16/CELL)));
    if (v243 == nil) goto v15;
    v243 = stack[-2];
    v243 = qcdr(v243);
    v243 = qcar(v243);
    fn = elt(env, 5); /* dm!-abs */
    v243 = (*qfn1(fn))(qenv(fn), v243);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    v149 = v243;
    v243 = v149;
    if (!consp(v243)) goto v7;
    v243 = v149;
    v84 = qcar(v243);
    v243 = elt(env, 4); /* onep */
    v243 = get(v84, v243);
    env = stack[-6];
    v84 = v149;
    v243 = Lapply1(nil, v243, v84);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    goto v6;

v6:
    if (!(v243 == nil)) goto v8;
    v243 = stack[-5];
    v243 = add1(v243);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    stack[-5] = v243;
    goto v8;

v8:
    v243 = stack[0];
    v243 = add1(v243);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    stack[0] = v243;
    goto v15;

v15:
    v243 = stack[-4];
    v243 = qcdr(v243);
    stack[-4] = v243;
    goto v104;

v7:
    v243 = v149;
    v243 = Lonep(nil, v243);
    env = stack[-6];
    goto v6;

v85:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v84 = qvalue(elt(env, 2)); /* maxvar */
    v243 = stack[-3];
    v243 = plus2(v84, v243);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    stack[-4] = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v243/(16/CELL)));
    stack[-3] = (Lisp_Object)17; /* 1 */
    stack[-2] = stack[0];
    stack[-1] = stack[-5];
    v84 = (Lisp_Object)49; /* 3 */
    v243 = stack[-5];
    v243 = times2(v84, v243);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    v243 = plus2(stack[0], v243);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-6];
    v243 = acons(stack[-2], stack[-1], v243);
    nil = C_nil;
    if (exception_pending()) goto v242;
    *(Lisp_Object *)((char *)stack[-4] + (CELL-TAG_VECTOR) + ((int32_t)stack[-3]/(16/CELL))) = v243;
    v243 = nil;
    { popv(7); return onevalue(v243); }
/* error exit handlers */
v242:
    popv(7);
    return nil;
}



/* Code for gsetsugar */

static Lisp_Object CC_gsetsugar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gsetsugar");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v17 = v29;
    stack[-1] = v0;
/* end of prologue */
    v16 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v16 == nil) goto v38;
    stack[-2] = stack[-1];
    stack[0] = elt(env, 3); /* sugar */
    v16 = v17;
    if (!(v16 == nil)) goto v100;
    v16 = stack[-1];
    fn = elt(env, 4); /* vdptdeg */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-3];
    goto v100;

v100:
    fn = elt(env, 5); /* vdpputprop */
    v16 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v16);
    nil = C_nil;
    if (exception_pending()) goto v45;
    goto v37;

v37:
    if (v16 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    else { popv(4); return onevalue(v16); }

v38:
    v16 = qvalue(elt(env, 2)); /* nil */
    goto v37;
/* error exit handlers */
v45:
    popv(4);
    return nil;
}



/* Code for termordp */

static Lisp_Object CC_termordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termordp");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v29;
    v93 = v0;
/* end of prologue */
    fn = elt(env, 1); /* wedgefax */
    stack[-1] = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v93 = stack[0];
    fn = elt(env, 1); /* wedgefax */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    {
        Lisp_Object v20 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* monordp */
        return (*qfn2(fn))(qenv(fn), v20, v93);
    }
/* error exit handlers */
v19:
    popv(3);
    return nil;
}



/* Code for formclis */

static Lisp_Object MS_CDECL CC_formclis(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v29,
                         Lisp_Object v86, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v89, v90;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formclis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formclis");
#endif
    if (stack >= stacklimit)
    {
        push3(v86,v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v29,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v86;
    stack[-1] = v29;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v37;

v37:
    v45 = stack[-2];
    if (v45 == nil) goto v104;
    v45 = stack[-2];
    v90 = qcar(v45);
    v89 = stack[-1];
    v45 = stack[0];
    fn = elt(env, 1); /* formc */
    v89 = (*qfnn(fn))(qenv(fn), 3, v90, v89, v45);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-4];
    v45 = stack[-3];
    v45 = cons(v89, v45);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-4];
    stack[-3] = v45;
    v45 = stack[-2];
    v45 = qcdr(v45);
    stack[-2] = v45;
    goto v37;

v104:
    v45 = stack[-3];
        popv(5);
        return Lnreverse(nil, v45);
/* error exit handlers */
v15:
    popv(5);
    return nil;
}



/* Code for mv!-pow!-!+ */

static Lisp_Object CC_mvKpowKL(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v90;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-+");
#endif
    if (stack >= stacklimit)
    {
        push2(v29,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v29);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v29;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v92;

v92:
    v89 = stack[-1];
    if (v89 == nil) goto v39;
    v89 = stack[-1];
    v90 = qcar(v89);
    v89 = stack[0];
    v89 = qcar(v89);
    v90 = plus2(v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-3];
    v89 = stack[-2];
    v89 = cons(v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-3];
    stack[-2] = v89;
    v89 = stack[-1];
    v89 = qcdr(v89);
    stack[-1] = v89;
    v89 = stack[0];
    v89 = qcdr(v89);
    stack[0] = v89;
    goto v92;

v39:
    v89 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v89);
    }
/* error exit handlers */
v14:
    popv(4);
    return nil;
}



/* Code for dp_term */

static Lisp_Object CC_dp_term(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v49;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_term");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v95 = v29;
    v49 = v0;
/* end of prologue */
    return cons(v95, v49);
}



/* Code for gperm */

static Lisp_Object CC_gperm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm");
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
    stack[-1] = nil;
    goto v93;

v93:
    v47 = stack[0];
    v122 = (Lisp_Object)1; /* 0 */
    v122 = (Lisp_Object)greaterp2(v47, v122);
    nil = C_nil;
    if (exception_pending()) goto v7;
    v122 = v122 ? lisp_true : nil;
    env = stack[-4];
    if (v122 == nil) goto v92;
    v47 = stack[0];
    v122 = stack[-1];
    v122 = cons(v47, v122);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    stack[-1] = v122;
    v122 = stack[0];
    v122 = sub1(v122);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    stack[0] = v122;
    goto v93;

v92:
    v122 = stack[-1];
    fn = elt(env, 2); /* gperm0 */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    stack[-3] = v122;
    v122 = stack[-3];
    if (v122 == nil) goto v105;
    v122 = stack[-3];
    v122 = qcar(v122);
    fn = elt(env, 3); /* pkp */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    v122 = ncons(v122);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    stack[-1] = v122;
    stack[-2] = v122;
    goto v45;

v45:
    v122 = stack[-3];
    v122 = qcdr(v122);
    stack[-3] = v122;
    v122 = stack[-3];
    if (v122 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v122 = stack[-3];
    v122 = qcar(v122);
    fn = elt(env, 3); /* pkp */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    v122 = ncons(v122);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    v122 = Lrplacd(nil, stack[0], v122);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    v122 = stack[-1];
    v122 = qcdr(v122);
    stack[-1] = v122;
    goto v45;

v105:
    v122 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v122); }
/* error exit handlers */
v7:
    popv(5);
    return nil;
}



/* Code for aronep!: */

static Lisp_Object CC_aronepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v49;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aronep:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v95 = v0;
/* end of prologue */
    v49 = qcdr(v95);
    v95 = (Lisp_Object)17; /* 1 */
    v95 = (v49 == v95 ? lisp_true : nil);
    return onevalue(v95);
}



/* Code for clear!-column */

static Lisp_Object MS_CDECL CC_clearKcolumn(Lisp_Object env, int nargs,
                         Lisp_Object v29, Lisp_Object v86,
                         Lisp_Object v32, Lisp_Object v31, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v279, v280, v281, v282, v182, v183, v181, v283, v284, v285;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "clear-column");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clear-column");
#endif
    if (stack >= stacklimit)
    {
        push4(v31,v32,v86,v29);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v29,v86,v32,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v32;
    v279 = v86;
    stack[-2] = v29;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* null!-space!-basis */
    qvalue(elt(env, 1)) = nil; /* null!-space!-basis */
    qvalue(elt(env, 1)) = v279; /* null!-space!-basis */
    v279 = (Lisp_Object)1; /* 0 */
    goto v16;

v16:
    v281 = stack[-1];
    v280 = v279;
    v281 = *(Lisp_Object *)((char *)v281 + (CELL-TAG_VECTOR) + ((int32_t)v280/(16/CELL)));
    v280 = stack[-2];
    v281 = *(Lisp_Object *)((char *)v281 + (CELL-TAG_VECTOR) + ((int32_t)v280/(16/CELL)));
    v280 = (Lisp_Object)1; /* 0 */
    if (v281 == v280) goto v107;
    v281 = v279;
    v280 = stack[-2];
    if (!(((int32_t)(v281)) < ((int32_t)(v280)))) goto v111;
    v281 = stack[-1];
    v280 = v279;
    v281 = *(Lisp_Object *)((char *)v281 + (CELL-TAG_VECTOR) + ((int32_t)v280/(16/CELL)));
    v280 = v279;
    v281 = *(Lisp_Object *)((char *)v281 + (CELL-TAG_VECTOR) + ((int32_t)v280/(16/CELL)));
    v280 = (Lisp_Object)1; /* 0 */
    if (!(v281 == v280)) goto v107;

v111:
    v281 = stack[-1];
    v280 = v279;
    v280 = *(Lisp_Object *)((char *)v281 + (CELL-TAG_VECTOR) + ((int32_t)v280/(16/CELL)));
    v285 = v280;
    v282 = stack[-1];
    v281 = v279;
    v280 = stack[-1];
    v279 = stack[-2];
    v279 = *(Lisp_Object *)((char *)v280 + (CELL-TAG_VECTOR) + ((int32_t)v279/(16/CELL)));
    *(Lisp_Object *)((char *)v282 + (CELL-TAG_VECTOR) + ((int32_t)v281/(16/CELL))) = v279;
    v280 = stack[-1];
    v279 = stack[-2];
    v281 = v285;
    *(Lisp_Object *)((char *)v280 + (CELL-TAG_VECTOR) + ((int32_t)v279/(16/CELL))) = v281;
    v280 = stack[-1];
    v279 = stack[-2];
    v280 = *(Lisp_Object *)((char *)v280 + (CELL-TAG_VECTOR) + ((int32_t)v279/(16/CELL)));
    v279 = stack[-2];
    v279 = *(Lisp_Object *)((char *)v280 + (CELL-TAG_VECTOR) + ((int32_t)v279/(16/CELL)));
    v279 = Lmodular_reciprocal(nil, v279);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v279);
        if (w != 0) w = current_modulus - w;
        v279 = fixnum_of_int(w);
    }
    v285 = v279;
    v279 = (Lisp_Object)1; /* 0 */
    v284 = v279;
    goto v252;

v252:
    v280 = stack[0];
    v279 = v284;
    v279 = (Lisp_Object)(int32_t)((int32_t)v280 - (int32_t)v279 + TAG_FIXNUM);
    v279 = ((intptr_t)(v279) < 0 ? lisp_true : nil);
    if (v279 == nil) goto v156;
    v279 = stack[-2];
    v182 = v279;
    goto v287;

v287:
    v280 = stack[0];
    v279 = v182;
    v279 = (Lisp_Object)(int32_t)((int32_t)v280 - (int32_t)v279 + TAG_FIXNUM);
    v279 = ((intptr_t)(v279) < 0 ? lisp_true : nil);
    if (v279 == nil) goto v187;
    v279 = qvalue(elt(env, 1)); /* null!-space!-basis */
    goto v38;

v38:
    qvalue(elt(env, 1)) = stack[-3]; /* null!-space!-basis */
    { popv(5); return onevalue(v279); }

v187:
    v280 = stack[-1];
    v279 = stack[-2];
    v282 = *(Lisp_Object *)((char *)v280 + (CELL-TAG_VECTOR) + ((int32_t)v279/(16/CELL)));
    v281 = v182;
    v280 = stack[-1];
    v279 = stack[-2];
    v280 = *(Lisp_Object *)((char *)v280 + (CELL-TAG_VECTOR) + ((int32_t)v279/(16/CELL)));
    v279 = v182;
    v280 = *(Lisp_Object *)((char *)v280 + (CELL-TAG_VECTOR) + ((int32_t)v279/(16/CELL)));
    v279 = v285;
    v279 = Lmodular_times(nil, v280, v279);
    env = stack[-4];
    *(Lisp_Object *)((char *)v282 + (CELL-TAG_VECTOR) + ((int32_t)v281/(16/CELL))) = v279;
    v279 = v182;
    v279 = (Lisp_Object)((int32_t)(v279) + 0x10);
    v182 = v279;
    goto v287;

v156:
    v280 = v284;
    v279 = stack[-2];
    if (equal(v280, v279)) goto v151;
    v280 = stack[-1];
    v279 = v284;
    v280 = *(Lisp_Object *)((char *)v280 + (CELL-TAG_VECTOR) + ((int32_t)v279/(16/CELL)));
    v279 = stack[-2];
    v279 = *(Lisp_Object *)((char *)v280 + (CELL-TAG_VECTOR) + ((int32_t)v279/(16/CELL)));
    v283 = v279;
    v280 = v283;
    v279 = (Lisp_Object)1; /* 0 */
    if (v280 == v279) goto v151;
    v280 = v283;
    v279 = v285;
    v279 = Lmodular_times(nil, v280, v279);
    env = stack[-4];
    v283 = v279;
    v279 = stack[-2];
    v181 = v279;
    goto v170;

v170:
    v280 = stack[0];
    v279 = v181;
    v279 = (Lisp_Object)(int32_t)((int32_t)v280 - (int32_t)v279 + TAG_FIXNUM);
    v279 = ((intptr_t)(v279) < 0 ? lisp_true : nil);
    if (!(v279 == nil)) goto v151;
    v280 = stack[-1];
    v279 = v284;
    v183 = *(Lisp_Object *)((char *)v280 + (CELL-TAG_VECTOR) + ((int32_t)v279/(16/CELL)));
    v182 = v181;
    v280 = stack[-1];
    v279 = v284;
    v280 = *(Lisp_Object *)((char *)v280 + (CELL-TAG_VECTOR) + ((int32_t)v279/(16/CELL)));
    v279 = v181;
    v282 = *(Lisp_Object *)((char *)v280 + (CELL-TAG_VECTOR) + ((int32_t)v279/(16/CELL)));
    v281 = v283;
    v280 = stack[-1];
    v279 = stack[-2];
    v280 = *(Lisp_Object *)((char *)v280 + (CELL-TAG_VECTOR) + ((int32_t)v279/(16/CELL)));
    v279 = v181;
    v279 = *(Lisp_Object *)((char *)v280 + (CELL-TAG_VECTOR) + ((int32_t)v279/(16/CELL)));
    v279 = Lmodular_times(nil, v281, v279);
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v282) + int_of_fixnum(v279);
        if (w >= current_modulus) w -= current_modulus;
        v279 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v183 + (CELL-TAG_VECTOR) + ((int32_t)v182/(16/CELL))) = v279;
    v279 = v181;
    v279 = (Lisp_Object)((int32_t)(v279) + 0x10);
    v181 = v279;
    goto v170;

v151:
    v279 = v284;
    v279 = (Lisp_Object)((int32_t)(v279) + 0x10);
    v284 = v279;
    goto v252;

v107:
    v281 = (Lisp_Object)((int32_t)(v279) + 0x10);
    v279 = v281;
    v280 = stack[0];
    if (!(((int32_t)(v281)) > ((int32_t)(v280)))) goto v16;
    v280 = stack[-2];
    v279 = qvalue(elt(env, 1)); /* null!-space!-basis */
    v279 = cons(v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v286;
    env = stack[-4];
    goto v38;
/* error exit handlers */
v286:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* null!-space!-basis */
    popv(5);
    return nil;
}



/* Code for cl_apply2ats */

static Lisp_Object CC_cl_apply2ats(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v29)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v96, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_apply2ats");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v94 = v29;
    v96 = v0;
/* end of prologue */
    v19 = v96;
    v96 = v94;
    v94 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* cl_apply2ats1 */
        return (*qfnn(fn))(qenv(fn), 3, v19, v96, v94);
    }
}



/* Code for vdp_poly */

static Lisp_Object CC_vdp_poly(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v37;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_poly");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v37 = v0;
/* end of prologue */
    v37 = qcdr(v37);
    v37 = qcdr(v37);
    v37 = qcdr(v37);
    v37 = qcar(v37);
    return onevalue(v37);
}



/* Code for multiom */

static Lisp_Object CC_multiom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multiom");
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
    v43 = stack[0];
    v69 = Llength(nil, v43);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    v43 = (Lisp_Object)17; /* 1 */
    if (v69 == v43) goto v92;
    v43 = stack[0];
    v43 = qcar(v43);
    fn = elt(env, 2); /* objectom */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    v43 = stack[0];
    v43 = qcdr(v43);
    v43 = CC_multiom(env, v43);
    nil = C_nil;
    if (exception_pending()) goto v16;
    goto v24;

v24:
    v43 = nil;
    { popv(2); return onevalue(v43); }

v92:
    v43 = stack[0];
    v43 = qcar(v43);
    fn = elt(env, 2); /* objectom */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v16;
    goto v24;
/* error exit handlers */
v16:
    popv(2);
    return nil;
}



setup_type const u07_setup[] =
{
    {"form",                    CC_form,        too_many_1,    wrong_no_1},
    {"red-weight1",             too_few_2,      CC_redKweight1,wrong_no_2},
    {"dp_times_bc",             too_few_2,      CC_dp_times_bc,wrong_no_2},
    {"pdmult",                  too_few_2,      CC_pdmult,     wrong_no_2},
    {"gperm1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm1},
    {"arzerop:",                CC_arzeropT,    too_many_1,    wrong_no_1},
    {"cl_cflip",                too_few_2,      CC_cl_cflip,   wrong_no_2},
    {"sfto_gcdf*",              too_few_2,      CC_sfto_gcdfH, wrong_no_2},
    {"exceeds-order",           too_few_2,      CC_exceedsKorder,wrong_no_2},
    {"qqe_qtidp",               CC_qqe_qtidp,   too_many_1,    wrong_no_1},
    {"aex_deg",                 too_few_2,      CC_aex_deg,    wrong_no_2},
    {"rl_sacat",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_sacat},
    {"omobjs",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobjs},
    {"rationalizei",            CC_rationalizei,too_many_1,    wrong_no_1},
    {"comm_kernels1",           too_few_2,      CC_comm_kernels1,wrong_no_2},
    {"diplength",               CC_diplength,   too_many_1,    wrong_no_1},
    {"boundindp",               too_few_2,      CC_boundindp,  wrong_no_2},
    {"plus:",                   too_few_2,      CC_plusT,      wrong_no_2},
    {"rd:minusp",               CC_rdTminusp,   too_many_1,    wrong_no_1},
    {"areallindices",           CC_areallindices,too_many_1,   wrong_no_1},
    {"symbid",                  too_few_2,      CC_symbid,     wrong_no_2},
    {"mv-pow-minusp",           CC_mvKpowKminusp,too_many_1,   wrong_no_1},
    {"dp_sum",                  too_few_2,      CC_dp_sum,     wrong_no_2},
    {"pv_sort2a",               too_few_2,      CC_pv_sort2a,  wrong_no_2},
    {"ordn",                    CC_ordn,        too_many_1,    wrong_no_1},
    {"general-times-term-mod-p",too_few_2,      CC_generalKtimesKtermKmodKp,wrong_no_2},
    {"cl_varl1",                CC_cl_varl1,    too_many_1,    wrong_no_1},
    {"stable-sortip",           too_few_2,      CC_stableKsortip,wrong_no_2},
    {"ckrn1",                   CC_ckrn1,       too_many_1,    wrong_no_1},
    {"rl_prepat",               CC_rl_prepat,   too_many_1,    wrong_no_1},
    {"pasf_susipost",           too_few_2,      CC_pasf_susipost,wrong_no_2},
    {"ibalp_varlt1",            too_few_2,      CC_ibalp_varlt1,wrong_no_2},
    {"ratpoly_mvartest",        too_few_2,      CC_ratpoly_mvartest,wrong_no_2},
    {"ev_comp",                 too_few_2,      CC_ev_comp,    wrong_no_2},
    {"letmtr3",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_letmtr3},
    {"mintype",                 CC_mintype,     too_many_1,    wrong_no_1},
    {"off_mod_reval",           CC_off_mod_reval,too_many_1,   wrong_no_1},
    {"bcsum",                   too_few_2,      CC_bcsum,      wrong_no_2},
    {"contr1-strand",           too_few_2,      CC_contr1Kstrand,wrong_no_2},
    {"add2resultbuf",           too_few_2,      CC_add2resultbuf,wrong_no_2},
    {"errorset2",               CC_errorset2,   too_many_1,    wrong_no_1},
    {"mv-pow-mv-term-+",        too_few_2,      CC_mvKpowKmvKtermKL,wrong_no_2},
    {"groeb=testa",             too_few_2,      CC_groebMtesta,wrong_no_2},
    {"tsym4",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_tsym4},
    {"times-in-vector",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_timesKinKvector},
    {"*i2gi",                   CC_Hi2gi,       too_many_1,    wrong_no_1},
    {"diff",                    too_few_2,      CC_diff,       wrong_no_2},
    {"sfto_davp",               too_few_2,      CC_sfto_davp,  wrong_no_2},
    {"gcdf1",                   too_few_2,      CC_gcdf1,      wrong_no_2},
    {"unplus",                  CC_unplus,      too_many_1,    wrong_no_1},
    {"ibalp_mk2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ibalp_mk2},
    {"cgp_evlmon",              CC_cgp_evlmon,  too_many_1,    wrong_no_1},
    {"checktag",                CC_checktag,    too_many_1,    wrong_no_1},
    {"initwght",                CC_initwght,    too_many_1,    wrong_no_1},
    {"gsetsugar",               too_few_2,      CC_gsetsugar,  wrong_no_2},
    {"termordp",                too_few_2,      CC_termordp,   wrong_no_2},
    {"formclis",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formclis},
    {"mv-pow-+",                too_few_2,      CC_mvKpowKL,   wrong_no_2},
    {"dp_term",                 too_few_2,      CC_dp_term,    wrong_no_2},
    {"gperm",                   CC_gperm,       too_many_1,    wrong_no_1},
    {"aronep:",                 CC_aronepT,     too_many_1,    wrong_no_1},
    {"clear-column",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_clearKcolumn},
    {"cl_apply2ats",            too_few_2,      CC_cl_apply2ats,wrong_no_2},
    {"vdp_poly",                CC_vdp_poly,    too_many_1,    wrong_no_1},
    {"multiom",                 CC_multiom,     too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u07", (two_args *)"21724 8240720 6358325", 0}
};

/* end of generated code */
