
/* $destdir\u46.c        Machine generated C code */

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


/* Code for rm_neg_pow */

static Lisp_Object CC_rm_neg_pow(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rm_neg_pow");
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
    v21 = stack[-1];
    if (!consp(v21)) goto v23;
    v21 = stack[-1];
    v21 = qcar(v21);
    if (!consp(v21)) goto v23;
    v21 = stack[-1];
    v21 = qcar(v21);
    v21 = qcar(v21);
    v21 = qcdr(v21);
    v21 = Lminusp(nil, v21);
    env = stack[-3];
    if (v21 == nil) goto v24;
    stack[-2] = (Lisp_Object)17; /* 1 */
    v21 = stack[-1];
    v21 = qcar(v21);
    v21 = qcar(v21);
    stack[0] = qcar(v21);
    v21 = stack[-1];
    v21 = qcar(v21);
    v21 = qcar(v21);
    v21 = qcdr(v21);
    v22 = negate(v21);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    v21 = (Lisp_Object)17; /* 1 */
    v22 = acons(stack[0], v22, v21);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    v21 = qvalue(elt(env, 1)); /* nil */
    stack[0] = list2star(stack[-2], v22, v21);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    v21 = stack[-1];
    v21 = qcar(v21);
    v21 = qcdr(v21);
    v21 = CC_rm_neg_pow(env, v21);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    fn = elt(env, 2); /* multsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v21);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    v21 = stack[-1];
    v21 = qcdr(v21);
    v21 = CC_rm_neg_pow(env, v21);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    {
        Lisp_Object v26 = stack[0];
        popv(4);
        fn = elt(env, 3); /* addsq */
        return (*qfn2(fn))(qenv(fn), v26, v21);
    }

v24:
    v21 = stack[-1];
    v21 = qcar(v21);
    v22 = qcar(v21);
    v21 = (Lisp_Object)17; /* 1 */
    v21 = cons(v22, v21);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    v22 = ncons(v21);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    v21 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v22, v21);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    v21 = stack[-1];
    v21 = qcar(v21);
    v21 = qcdr(v21);
    v21 = CC_rm_neg_pow(env, v21);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    fn = elt(env, 2); /* multsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v21);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    v21 = stack[-1];
    v21 = qcdr(v21);
    v21 = CC_rm_neg_pow(env, v21);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    {
        Lisp_Object v27 = stack[0];
        popv(4);
        fn = elt(env, 3); /* addsq */
        return (*qfn2(fn))(qenv(fn), v27, v21);
    }

v23:
    v22 = stack[-1];
    v21 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v22, v21);
/* error exit handlers */
v25:
    popv(4);
    return nil;
}



/* Code for vevzero!?1 */

static Lisp_Object CC_vevzeroW1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v31, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevzero?1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v31 = v0;
/* end of prologue */

v33:
    v30 = v31;
    v30 = (v30 == nil ? lisp_true : nil);
    if (!(v30 == nil)) return onevalue(v30);
    v30 = v31;
    v32 = qcar(v30);
    v30 = (Lisp_Object)1; /* 0 */
    if (v32 == v30) goto v34;
    v30 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v30);

v34:
    v30 = v31;
    v30 = qcdr(v30);
    v30 = (v30 == nil ? lisp_true : nil);
    if (!(v30 == nil)) return onevalue(v30);
    v30 = v31;
    v30 = qcdr(v30);
    v32 = qcar(v30);
    v30 = (Lisp_Object)1; /* 0 */
    if (v32 == v30) goto v35;
    v30 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v30);

v35:
    v30 = v31;
    v30 = qcdr(v30);
    v30 = qcdr(v30);
    v31 = v30;
    goto v33;
}



/* Code for xriterion_2 */

static Lisp_Object MS_CDECL CC_xriterion_2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v36,
                         Lisp_Object v37, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v56, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xriterion_2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xriterion_2");
#endif
    if (stack >= stacklimit)
    {
        push3(v37,v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v36,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v37;
    stack[-1] = v36;
    stack[-2] = v0;
/* end of prologue */

v33:
    v55 = stack[-1];
    if (v55 == nil) goto v58;
    v55 = stack[-2];
    v55 = qcdr(v55);
    v56 = qcar(v55);
    v55 = elt(env, 2); /* wedge_pair */
    if (v56 == v55) goto v59;
    v55 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v55); }

v59:
    v55 = stack[-1];
    v55 = qcar(v55);
    stack[-3] = v55;
    v57 = stack[-3];
    v56 = (Lisp_Object)17; /* 1 */
    v55 = (Lisp_Object)17; /* 1 */
    v55 = list2star(v57, v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v56 = ncons(v55);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v55 = stack[-2];
    v55 = qcdr(v55);
    v55 = qcdr(v55);
    v55 = qcar(v55);
    if (equal(v56, v55)) goto v9;
    v56 = stack[-3];
    v55 = stack[-3];
    v56 = list2(v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v55 = stack[-2];
    v55 = qcar(v55);
    fn = elt(env, 7); /* xdiv */
    v55 = (*qfn2(fn))(qenv(fn), v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    if (v55 == nil) goto v61;
    v56 = stack[-3];
    v55 = stack[-2];
    v55 = qcdr(v55);
    v55 = qcdr(v55);
    v55 = qcdr(v55);
    v55 = qcar(v55);
    fn = elt(env, 8); /* make_wedge_pair */
    v55 = (*qfn2(fn))(qenv(fn), v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v56 = v55;
    v55 = v56;
    v55 = (v55 == nil ? lisp_true : nil);
    if (!(v55 == nil)) goto v62;
    v55 = stack[0];
    fn = elt(env, 9); /* find_item */
    v55 = (*qfn2(fn))(qenv(fn), v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v55 = (v55 == nil ? lisp_true : nil);
    goto v62;

v62:
    if (v55 == nil) goto v63;
    v55 = qvalue(elt(env, 3)); /* !*trxideal */
    if (v55 == nil) goto v64;
    v55 = elt(env, 4); /* "criterion 2 hit" */
    fn = elt(env, 10); /* eval */
    v57 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v56 = qvalue(elt(env, 1)); /* nil */
    v55 = elt(env, 5); /* last */
    fn = elt(env, 11); /* assgnpri */
    v55 = (*qfnn(fn))(qenv(fn), 3, v57, v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    goto v64;

v64:
    v55 = qvalue(elt(env, 6)); /* t */
    goto v65;

v65:
    if (!(v55 == nil)) { popv(5); return onevalue(v55); }
    v57 = stack[-2];
    v55 = stack[-1];
    v56 = qcdr(v55);
    v55 = stack[0];
    stack[-2] = v57;
    stack[-1] = v56;
    stack[0] = v55;
    goto v33;

v63:
    v55 = qvalue(elt(env, 1)); /* nil */
    goto v65;

v61:
    v55 = qvalue(elt(env, 1)); /* nil */
    goto v65;

v9:
    v55 = qvalue(elt(env, 1)); /* nil */
    goto v65;

v58:
    v55 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v55); }
/* error exit handlers */
v60:
    popv(5);
    return nil;
}



/* Code for r2flbf */

static Lisp_Object CC_r2flbf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2flbf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v67 = v0;
/* end of prologue */
    v66 = qvalue(elt(env, 1)); /* !*bftag */
    if (v66 == nil) goto v68;
    v66 = v67;
    {
        fn = elt(env, 2); /* r2bf */
        return (*qfn1(fn))(qenv(fn), v66);
    }

v68:
    v66 = v67;
    {
        fn = elt(env, 3); /* r2fl */
        return (*qfn1(fn))(qenv(fn), v66);
    }
}



/* Code for !*ex2sf */

static Lisp_Object CC_Hex2sf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *ex2sf");
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
    stack[-2] = nil;
    goto v72;

v72:
    v18 = stack[-1];
    if (v18 == nil) goto v73;
    v18 = stack[-1];
    v18 = qcar(v18);
    v18 = qcar(v18);
    v18 = qcar(v18);
    if (v18 == nil) goto v34;
    v18 = stack[-1];
    v18 = qcar(v18);
    v18 = qcar(v18);
    v16 = qcar(v18);
    v18 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v16, v18);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    v18 = stack[-1];
    v18 = qcar(v18);
    v18 = qcdr(v18);
    fn = elt(env, 1); /* subs2chk */
    v16 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    v18 = stack[-2];
    v18 = acons(stack[0], v16, v18);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    stack[-2] = v18;
    v18 = stack[-1];
    v18 = qcdr(v18);
    stack[-1] = v18;
    goto v72;

v34:
    stack[0] = stack[-2];
    v18 = stack[-1];
    v18 = qcar(v18);
    v18 = qcdr(v18);
    fn = elt(env, 1); /* subs2chk */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    {
        Lisp_Object v17 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v17, v18);
    }

v73:
    v18 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v18);
    }
/* error exit handlers */
v74:
    popv(4);
    return nil;
}



/* Code for lf!=zero */

static Lisp_Object CC_lfMzero(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lf=zero");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v72 = v0;
/* end of prologue */
    v72 = qcdr(v72);
    v72 = (v72 == nil ? lisp_true : nil);
    return onevalue(v72);
}



/* Code for !*n2a */

static Lisp_Object CC_Hn2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *n2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v75 = v0;
/* end of prologue */
    v59 = v75;
    v59 = integerp(v59);
    if (!(v59 == nil)) return onevalue(v75);
    v59 = qvalue(elt(env, 1)); /* !*nosq */
    if (v59 == nil) goto v66;
    v59 = v75;
    {
        fn = elt(env, 2); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v59);
    }

v66:
    v59 = v75;
    {
        fn = elt(env, 3); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v59);
    }
}



/* Code for mk_rep_mat */

static Lisp_Object CC_mk_rep_mat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v36)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_rep_mat");
#endif
    if (stack >= stacklimit)
    {
        push2(v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v36);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v36;
    stack[0] = v0;
/* end of prologue */
    v78 = stack[-1];
    v78 = qcar(v78);
    v78 = qcdr(v78);
    v78 = qcar(v78);
    fn = elt(env, 2); /* get!+row!+nr */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-3];
    fn = elt(env, 3); /* mk!+unit!+mat */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-3];
    v79 = v78;
    v78 = stack[0];
    stack[-2] = v78;
    goto v80;

v80:
    v78 = stack[-2];
    if (v78 == nil) { popv(4); return onevalue(v79); }
    v78 = stack[-2];
    v78 = qcar(v78);
    stack[0] = v79;
    v79 = v78;
    v78 = stack[-1];
    fn = elt(env, 4); /* get_rep_of_generator */
    v78 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-3];
    fn = elt(env, 5); /* mk!+mat!+mult!+mat */
    v78 = (*qfn2(fn))(qenv(fn), stack[0], v78);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-3];
    v79 = v78;
    v78 = stack[-2];
    v78 = qcdr(v78);
    stack[-2] = v78;
    goto v80;
/* error exit handlers */
v31:
    popv(4);
    return nil;
}



/* Code for freeof!-dfl */

static Lisp_Object CC_freeofKdfl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v36)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeof-dfl");
#endif
    if (stack >= stacklimit)
    {
        push2(v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v36);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v36;
    stack[-1] = v0;
/* end of prologue */

v72:
    v9 = stack[-1];
    if (v9 == nil) goto v73;
    v9 = stack[-1];
    v76 = qcar(v9);
    v9 = stack[0];
    fn = elt(env, 3); /* freeof!-df */
    v9 = (*qfn2(fn))(qenv(fn), v76, v9);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-2];
    if (v9 == nil) goto v82;
    v9 = stack[-1];
    v9 = qcdr(v9);
    stack[-1] = v9;
    goto v72;

v82:
    v9 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v9); }

v73:
    v9 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v9); }
/* error exit handlers */
v81:
    popv(3);
    return nil;
}



/* Code for aex_add */

static Lisp_Object CC_aex_add(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v36)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_add");
#endif
    if (stack >= stacklimit)
    {
        push2(v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v36);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v36;
    stack[-3] = v0;
/* end of prologue */
    v79 = stack[-3];
    fn = elt(env, 2); /* aex_ex */
    stack[0] = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    v79 = stack[-2];
    fn = elt(env, 2); /* aex_ex */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    fn = elt(env, 3); /* ratpoly_add */
    stack[-4] = (*qfn2(fn))(qenv(fn), stack[0], v79);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    v79 = stack[-3];
    fn = elt(env, 4); /* aex_ctx */
    stack[0] = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    v79 = stack[-2];
    fn = elt(env, 4); /* aex_ctx */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    fn = elt(env, 5); /* ctx_union */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v79);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v79 = stack[-3];
    fn = elt(env, 6); /* aex_reducedtag */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    if (v79 == nil) goto v81;
    v79 = stack[-2];
    fn = elt(env, 6); /* aex_reducedtag */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    goto v85;

v85:
    {
        Lisp_Object v86 = stack[-4];
        Lisp_Object v87 = stack[-1];
        Lisp_Object v49 = stack[0];
        popv(6);
        fn = elt(env, 7); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v86, v87, v49, v79);
    }

v81:
    v79 = qvalue(elt(env, 1)); /* nil */
    goto v85;
/* error exit handlers */
v69:
    popv(6);
    return nil;
}



/* Code for lowlimitrd */

static Lisp_Object MS_CDECL CC_lowlimitrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "lowlimitrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lowlimitrd");
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
    v90 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    stack[0] = v90;
    fn = elt(env, 5); /* lex */
    v90 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v82 = qvalue(elt(env, 1)); /* char */
    v90 = elt(env, 2); /* (!/ l o w l i m i t) */
    if (equal(v82, v90)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v82 = elt(env, 3); /* "</lowlimit>" */
    v90 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 6); /* errorml */
    v90 = (*qfn2(fn))(qenv(fn), v82, v90);
    nil = C_nil;
    if (exception_pending()) goto v65;
    v90 = nil;
    { popv(2); return onevalue(v90); }
/* error exit handlers */
v65:
    popv(2);
    return nil;
}



/* Code for column_dim */

static Lisp_Object CC_column_dim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for column_dim");
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
    v88 = qvalue(elt(env, 1)); /* !*fast_la */
    if (!(v88 == nil)) goto v72;
    v88 = stack[0];
    fn = elt(env, 4); /* matrixp */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-1];
    if (!(v88 == nil)) goto v72;
    v88 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v88 == nil)) goto v89;
    v88 = elt(env, 3); /* "Error in column_dim: input should be a matrix." 
*/
    fn = elt(env, 5); /* lprie */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-1];
    goto v89;

v89:
    v88 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-1];
    goto v72;

v72:
    v88 = stack[0];
    fn = elt(env, 6); /* size_of_matrix */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v82;
    v88 = qcdr(v88);
    v88 = qcar(v88);
    { popv(2); return onevalue(v88); }
/* error exit handlers */
v82:
    popv(2);
    return nil;
}



/* Code for xpndwedge */

static Lisp_Object CC_xpndwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xpndwedge");
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
    goto v58;

v58:
    v30 = stack[0];
    v30 = qcdr(v30);
    if (v30 == nil) goto v92;
    v30 = stack[0];
    v30 = qcar(v30);
    fn = elt(env, 1); /* partitop */
    v31 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    v30 = stack[-1];
    v30 = cons(v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    stack[-1] = v30;
    v30 = stack[0];
    v30 = qcdr(v30);
    stack[0] = v30;
    goto v58;

v92:
    v30 = stack[0];
    v30 = qcar(v30);
    fn = elt(env, 1); /* partitop */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    fn = elt(env, 2); /* mkunarywedge */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    v31 = v30;
    goto v73;

v73:
    v30 = stack[-1];
    if (v30 == nil) { popv(3); return onevalue(v31); }
    v30 = stack[-1];
    v30 = qcar(v30);
    fn = elt(env, 3); /* wedgepf2 */
    v30 = (*qfn2(fn))(qenv(fn), v30, v31);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    v31 = v30;
    v30 = stack[-1];
    v30 = qcdr(v30);
    stack[-1] = v30;
    goto v73;
/* error exit handlers */
v86:
    popv(3);
    return nil;
}



/* Code for !:quotient */

static Lisp_Object CC_Tquotient(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v36)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v99, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :quotient");
#endif
    if (stack >= stacklimit)
    {
        push2(v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v36);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v99 = v36;
    stack[0] = v0;
/* end of prologue */
    v98 = stack[0];
    if (v98 == nil) goto v72;
    v64 = stack[0];
    v98 = (Lisp_Object)1; /* 0 */
    if (v64 == v98) goto v72;
    v98 = v99;
    if (v98 == nil) goto v19;
    v64 = v99;
    v98 = (Lisp_Object)1; /* 0 */
    if (v64 == v98) goto v19;
    v98 = stack[0];
    if (!(!consp(v98))) goto v100;
    v98 = v99;
    if (!(!consp(v98))) goto v100;
    v98 = qvalue(elt(env, 5)); /* dmode!* */
    if (v98 == nil) goto v70;
    v98 = v99;
    fn = elt(env, 8); /* !:recip */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-1];
    v99 = v98;
    if (!consp(v99)) goto v47;
    v64 = stack[0];
    v99 = v98;
    v98 = elt(env, 6); /* times */
    {
        popv(2);
        fn = elt(env, 9); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v64, v99, v98);
    }

v47:
    v99 = stack[0];
    popv(2);
    return times2(v99, v98);

v70:
    v98 = stack[0];
    popv(2);
    return quot2(v98, v99);

v100:
    v64 = stack[0];
    v98 = elt(env, 7); /* quotient */
    {
        popv(2);
        fn = elt(env, 9); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v64, v99, v98);
    }

v19:
    v98 = elt(env, 2); /* "Zero divisor" */
    v99 = v98;
    v98 = v99;
    qvalue(elt(env, 3)) = v98; /* errmsg!* */
    v98 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v98 == nil)) goto v81;
    v98 = v99;
    fn = elt(env, 10); /* lprie */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-1];
    goto v81;

v81:
    v98 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v101;
    v98 = nil;
    { popv(2); return onevalue(v98); }

v72:
    v98 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v98); }
/* error exit handlers */
v101:
    popv(2);
    return nil;
}



/* Code for s_actual_world1 */

static Lisp_Object CC_s_actual_world1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v58;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for s_actual_world1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v58 = v0;
/* end of prologue */
    v58 = qcar(v58);
    v58 = qcar(v58);
    v58 = qcar(v58);
    return onevalue(v58);
}



/* Code for !*sf2ex */

static Lisp_Object CC_Hsf2ex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v36)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v47, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *sf2ex");
#endif
    if (stack >= stacklimit)
    {
        push2(v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v36);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v36;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v58;

v58:
    v105 = stack[-1];
    if (v105 == nil) goto v68;
    v105 = stack[-1];
    if (!consp(v105)) goto v107;
    v105 = stack[-1];
    v105 = qcar(v105);
    if (!consp(v105)) goto v107;
    v105 = stack[-1];
    v105 = qcar(v105);
    v105 = qcar(v105);
    v47 = qcar(v105);
    v105 = stack[0];
    v105 = Lmemq(nil, v47, v105);
    if (v105 == nil) goto v107;
    v105 = stack[-1];
    v105 = qcar(v105);
    v105 = qcar(v105);
    v105 = qcar(v105);
    v106 = ncons(v105);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v105 = stack[-1];
    v105 = qcar(v105);
    v47 = qcdr(v105);
    v105 = stack[-2];
    v105 = acons(v106, v47, v105);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    stack[-2] = v105;
    v105 = stack[-1];
    v105 = qcdr(v105);
    stack[-1] = v105;
    goto v58;

v107:
    stack[0] = stack[-2];
    v105 = qvalue(elt(env, 1)); /* nil */
    v47 = ncons(v105);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v105 = stack[-1];
    v105 = cons(v47, v105);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v105 = ncons(v105);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    {
        Lisp_Object v94 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v94, v105);
    }

v68:
    v105 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v105);
    }
/* error exit handlers */
v95:
    popv(4);
    return nil;
}



/* Code for get!-current!-representation */

static Lisp_Object CC_getKcurrentKrepresentation(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v85;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-current-representation");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v108 = v0;
/* end of prologue */
    v85 = elt(env, 1); /* currep */
    return get(v108, v85);
}



/* Code for ofsf_smmkatl!-and */

static Lisp_Object MS_CDECL CC_ofsf_smmkatlKand(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v36,
                         Lisp_Object v37, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v120, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_smmkatl-and");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smmkatl-and");
#endif
    if (stack >= stacklimit)
    {
        push3(v37,v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v36,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v37;
    v119 = v36;
    stack[-4] = v0;
/* end of prologue */
    v120 = qvalue(elt(env, 1)); /* !*rlsipw */
    if (!(v120 == nil)) goto v73;
    v120 = qvalue(elt(env, 2)); /* !*rlsipo */
    if (v120 == nil) goto v73;
    v121 = elt(env, 3); /* and */
    v120 = v119;
    v119 = stack[-3];
    {
        popv(7);
        fn = elt(env, 5); /* ofsf_irl2atl */
        return (*qfnn(fn))(qenv(fn), 3, v121, v120, v119);
    }

v73:
    stack[-5] = v119;
    goto v65;

v65:
    v119 = stack[-5];
    if (v119 == nil) goto v81;
    v119 = stack[-5];
    v119 = qcar(v119);
    v120 = v119;
    v121 = qcar(v120);
    v120 = stack[-4];
    v120 = Latsoc(nil, v121, v120);
    v121 = v120;
    v120 = v121;
    if (v120 == nil) goto v18;
    v120 = v119;
    v119 = stack[-3];
    fn = elt(env, 6); /* ofsf_smmkatl!-and1 */
    v119 = (*qfnn(fn))(qenv(fn), 3, v121, v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-6];
    goto v87;

v87:
    stack[-2] = v119;
    v119 = stack[-2];
    fn = elt(env, 7); /* lastpair */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-6];
    stack[-1] = v119;
    v119 = stack[-5];
    v119 = qcdr(v119);
    stack[-5] = v119;
    v119 = stack[-1];
    if (!consp(v119)) goto v65;
    else goto v9;

v9:
    v119 = stack[-5];
    if (v119 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v119 = stack[-5];
    v119 = qcar(v119);
    v120 = v119;
    v121 = qcar(v120);
    v120 = stack[-4];
    v120 = Latsoc(nil, v121, v120);
    v121 = v120;
    v120 = v121;
    if (v120 == nil) goto v123;
    v120 = v119;
    v119 = stack[-3];
    fn = elt(env, 6); /* ofsf_smmkatl!-and1 */
    v119 = (*qfnn(fn))(qenv(fn), 3, v121, v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-6];
    goto v124;

v124:
    v119 = Lrplacd(nil, stack[0], v119);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-6];
    v119 = stack[-1];
    fn = elt(env, 7); /* lastpair */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-6];
    stack[-1] = v119;
    v119 = stack[-5];
    v119 = qcdr(v119);
    stack[-5] = v119;
    goto v9;

v123:
    v121 = elt(env, 3); /* and */
    v120 = v119;
    v119 = stack[-3];
    fn = elt(env, 8); /* ofsf_ir2atl */
    v119 = (*qfnn(fn))(qenv(fn), 3, v121, v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-6];
    goto v124;

v18:
    v120 = elt(env, 3); /* and */
    v121 = v119;
    v119 = stack[-3];
    fn = elt(env, 8); /* ofsf_ir2atl */
    v119 = (*qfnn(fn))(qenv(fn), 3, v120, v121, v119);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-6];
    goto v87;

v81:
    v119 = qvalue(elt(env, 4)); /* nil */
    { popv(7); return onevalue(v119); }
/* error exit handlers */
v122:
    popv(7);
    return nil;
}



/* Code for replace!-nth */

static Lisp_Object MS_CDECL CC_replaceKnth(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v36,
                         Lisp_Object v37, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "replace-nth");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replace-nth");
#endif
    if (stack >= stacklimit)
    {
        push3(v37,v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v36,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v37;
    stack[-1] = v36;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v23;

v23:
    v69 = stack[-1];
    v32 = (Lisp_Object)17; /* 1 */
    if (v69 == v32) goto v34;
    v32 = stack[-2];
    v69 = qcar(v32);
    v32 = stack[-3];
    v32 = cons(v69, v32);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    stack[-3] = v32;
    v32 = stack[-2];
    v32 = qcdr(v32);
    stack[-2] = v32;
    v32 = stack[-1];
    v32 = sub1(v32);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    stack[-1] = v32;
    goto v23;

v34:
    stack[-1] = stack[-3];
    v69 = stack[0];
    v32 = stack[-2];
    v32 = qcdr(v32);
    v32 = cons(v69, v32);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    {
        Lisp_Object v125 = stack[-1];
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v125, v32);
    }
/* error exit handlers */
v61:
    popv(5);
    return nil;
}



/* Code for freeof!-df */

static Lisp_Object CC_freeofKdf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v36)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeof-df");
#endif
    if (stack >= stacklimit)
    {
        push2(v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v36);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v36;
    stack[-1] = v0;
/* end of prologue */
    v18 = stack[-1];
    if (!consp(v18)) goto v72;
    v18 = stack[-1];
    v16 = qcar(v18);
    v18 = elt(env, 2); /* df */
    if (v16 == v18) goto v91;
    v18 = stack[-1];
    v16 = qcdr(v18);
    v18 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* freeof!-dfl */
        return (*qfn2(fn))(qenv(fn), v16, v18);
    }

v91:
    v18 = stack[-1];
    v18 = qcdr(v18);
    v16 = qcar(v18);
    v18 = stack[0];
    v18 = CC_freeofKdf(env, v16, v18);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    if (v18 == nil) goto v84;
    v16 = stack[0];
    v18 = stack[-1];
    v18 = qcdr(v18);
    v18 = qcdr(v18);
    fn = elt(env, 5); /* smember */
    v18 = (*qfn2(fn))(qenv(fn), v16, v18);
    nil = C_nil;
    if (exception_pending()) goto v126;
    v18 = (v18 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v18); }

v84:
    v18 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v18); }

v72:
    v18 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v18); }
/* error exit handlers */
v126:
    popv(3);
    return nil;
}



/* Code for cl_applysac2 */

static Lisp_Object MS_CDECL CC_cl_applysac2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v36,
                         Lisp_Object v37, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v134, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_applysac2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_applysac2");
#endif
    if (stack >= stacklimit)
    {
        push3(v37,v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v36,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v37;
    v134 = v36;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    v133 = v134;
    if (v133 == nil) goto v80;
    v133 = v134;
    stack[0] = v133;
    goto v71;

v71:
    v133 = stack[0];
    if (v133 == nil) goto v91;
    v135 = stack[-2];
    v133 = stack[0];
    v134 = qcar(v133);
    v133 = stack[-1];
    fn = elt(env, 7); /* cl_subandcut */
    v134 = (*qfnn(fn))(qenv(fn), 3, v135, v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    stack[-3] = v134;
    v133 = elt(env, 2); /* keep1 */
    if (!(v134 == v133)) goto v91;
    v133 = stack[0];
    v133 = qcdr(v133);
    stack[0] = v133;
    goto v71;

v91:
    v133 = stack[-3];
    if (v133 == nil) goto v61;
    v133 = stack[0];
    if (v133 == nil) goto v118;
    v134 = stack[-3];
    v133 = elt(env, 5); /* keep2 */
    if (v134 == v133) goto v137;
    v134 = stack[-3];
    v133 = elt(env, 6); /* failed */
    if (v134 == v133) goto v25;
    v135 = qvalue(elt(env, 3)); /* nil */
    v134 = stack[-3];
    v133 = stack[0];
    v133 = qcdr(v133);
    popv(5);
    return acons(v135, v134, v133);

v25:
    v135 = stack[-2];
    v133 = stack[0];
    v134 = qcdr(v133);
    v133 = stack[-1];
    v133 = CC_cl_applysac2(env, 3, v135, v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    stack[-3] = v133;
    v134 = stack[-3];
    v133 = elt(env, 4); /* break */
    if (v134 == v133) goto v115;
    v134 = stack[0];
    v133 = stack[-3];
    v133 = qcdr(v133);
    fn = elt(env, 8); /* setcdr */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    v133 = stack[-3];
    v134 = qcar(v133);
    v133 = stack[0];
    popv(5);
    return cons(v134, v133);

v115:
    v133 = elt(env, 4); /* break */
    { popv(5); return onevalue(v133); }

v137:
    v134 = qvalue(elt(env, 3)); /* nil */
    v133 = stack[0];
    popv(5);
    return cons(v134, v133);

v118:
    v134 = qvalue(elt(env, 1)); /* t */
    v133 = stack[-2];
    v133 = cons(v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    popv(5);
    return ncons(v133);

v61:
    v133 = elt(env, 4); /* break */
    { popv(5); return onevalue(v133); }

v80:
    v134 = qvalue(elt(env, 1)); /* t */
    v133 = stack[-2];
    v133 = cons(v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    popv(5);
    return ncons(v133);
/* error exit handlers */
v136:
    popv(5);
    return nil;
}



/* Code for seprd */

static Lisp_Object MS_CDECL CC_seprd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "seprd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for seprd");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v65 = qvalue(elt(env, 2)); /* char */
    v54 = elt(env, 3); /* (s e p !/) */
    if (equal(v65, v54)) goto v73;
    v65 = elt(env, 4); /* "<sep/>" */
    v54 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 5); /* errorml */
    v54 = (*qfn2(fn))(qenv(fn), v65, v54);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[0];
    goto v73;

v73:
    fn = elt(env, 6); /* lex */
    v54 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[0];
    v54 = qvalue(elt(env, 2)); /* char */
        popv(1);
        return Lcompress(nil, v54);
/* error exit handlers */
v9:
    popv(1);
    return nil;
}



/* Code for search4facf */

static Lisp_Object MS_CDECL CC_search4facf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v36,
                         Lisp_Object v37, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "search4facf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for search4facf");
#endif
    if (stack >= stacklimit)
    {
        push3(v37,v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v36,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v37;
    stack[-3] = v36;
    stack[-4] = v0;
/* end of prologue */
    v97 = stack[-3];
    if (v97 == nil) goto v108;
    v97 = stack[-3];
    v97 = qcar(v97);
    stack[-5] = v97;
    goto v75;

v75:
    v97 = stack[-5];
    if (v97 == nil) goto v90;
    stack[-1] = stack[-4];
    v97 = stack[-3];
    stack[0] = qcdr(v97);
    v97 = stack[-5];
    v96 = qcar(v97);
    v97 = stack[-2];
    v97 = cons(v96, v97);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-6];
    v97 = CC_search4facf(env, 3, stack[-1], stack[0], v97);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-6];
    v96 = v97;
    v97 = v96;
    if (!(v97 == nil)) { popv(7); return onevalue(v96); }
    v97 = stack[-5];
    v97 = qcdr(v97);
    stack[-5] = v97;
    goto v75;

v90:
    v97 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v97); }

v108:
    v96 = stack[-4];
    v97 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* tryfactorf */
        return (*qfn2(fn))(qenv(fn), v96, v97);
    }
/* error exit handlers */
v102:
    popv(7);
    return nil;
}



/* Code for getvariables */

static Lisp_Object CC_getvariables(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getvariables");
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
    v34 = v0;
/* end of prologue */
    v50 = v34;
    stack[0] = qcar(v50);
    v50 = v34;
    v34 = qcdr(v50);
    v50 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* varsinsf */
    v50 = (*qfn2(fn))(qenv(fn), v34, v50);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    {
        Lisp_Object v75 = stack[0];
        popv(2);
        fn = elt(env, 2); /* varsinsf */
        return (*qfn2(fn))(qenv(fn), v75, v50);
    }
/* error exit handlers */
v59:
    popv(2);
    return nil;
}



/* Code for codfac */

static Lisp_Object MS_CDECL CC_codfac(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "codfac");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for codfac");
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
    v144 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v144;
    goto v89;

v89:
    v119 = (Lisp_Object)-15; /* -1 */
    v144 = stack[-1];
    v144 = difference2(v119, v144);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v144 = Lminusp(nil, v144);
    env = stack[-3];
    if (!(v144 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v119 = qvalue(elt(env, 4)); /* maxvar */
    v144 = stack[-1];
    v144 = plus2(v119, v144);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v119 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v144/(16/CELL)));
    v144 = (Lisp_Object)49; /* 3 */
    v119 = *(Lisp_Object *)((char *)v119 + (CELL-TAG_VECTOR) + ((int32_t)v144/(16/CELL)));
    v144 = (Lisp_Object)-15; /* -1 */
    if (v119 == v144) goto v71;
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v119 = qvalue(elt(env, 4)); /* maxvar */
    v144 = stack[-1];
    v144 = plus2(v119, v144);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v119 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v144/(16/CELL)));
    v144 = (Lisp_Object)49; /* 3 */
    v119 = *(Lisp_Object *)((char *)v119 + (CELL-TAG_VECTOR) + ((int32_t)v144/(16/CELL)));
    v144 = (Lisp_Object)-31; /* -2 */
    if (v119 == v144) goto v71;
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v119 = qvalue(elt(env, 4)); /* maxvar */
    v144 = stack[-1];
    v144 = plus2(v119, v144);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v119 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v144/(16/CELL)));
    v144 = (Lisp_Object)33; /* 2 */
    v119 = *(Lisp_Object *)((char *)v119 + (CELL-TAG_VECTOR) + ((int32_t)v144/(16/CELL)));
    v144 = elt(env, 5); /* times */
    if (!(v119 == v144)) goto v71;
    v144 = stack[-1];
    fn = elt(env, 7); /* samefar */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v119 = v144;
    if (v144 == nil) goto v71;
    v144 = qvalue(elt(env, 6)); /* t */
    stack[-2] = v144;
    v144 = v119;
    stack[0] = v144;
    goto v39;

v39:
    v144 = stack[0];
    if (v144 == nil) goto v71;
    v144 = stack[0];
    v144 = qcar(v144);
    v119 = stack[-1];
    fn = elt(env, 8); /* commonfac */
    v144 = (*qfn2(fn))(qenv(fn), v119, v144);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v144 = stack[0];
    v144 = qcdr(v144);
    stack[0] = v144;
    goto v39;

v71:
    v144 = stack[-1];
    v144 = add1(v144);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    stack[-1] = v144;
    goto v89;
/* error exit handlers */
v145:
    popv(4);
    return nil;
}



/* Code for let3 */

static Lisp_Object MS_CDECL CC_let3(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v36,
                         Lisp_Object v37, Lisp_Object v77,
                         Lisp_Object v113, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v184, v185, v186, v187, v188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "let3");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for let3");
#endif
    if (stack >= stacklimit)
    {
        push5(v113,v77,v37,v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v36,v37,v77,v113);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v113;
    stack[-2] = v77;
    stack[-3] = v37;
    stack[-4] = v36;
    stack[-5] = v0;
/* end of prologue */
    v183 = stack[-5];
    stack[-6] = v183;
    v183 = stack[-6];
    if (v183 == nil) goto v80;
    v183 = stack[-6];
    if (is_number(v183)) goto v29;
    v183 = stack[-4];
    fn = elt(env, 12); /* getrtype */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    stack[0] = v183;
    v183 = stack[-2];
    if (v183 == nil) goto v16;
    v183 = stack[-6];
    if (!(symbolp(v183))) goto v16;
    v184 = stack[-6];
    v183 = elt(env, 5); /* rtype */
    v183 = Lremprop(nil, v184, v183);
    env = stack[-7];
    v184 = stack[-6];
    v183 = elt(env, 6); /* avalue */
    v183 = Lremprop(nil, v184, v183);
    env = stack[-7];
    goto v16;

v16:
    v183 = stack[-6];
    fn = elt(env, 12); /* getrtype */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    v184 = v183;
    if (v183 == nil) goto v142;
    v185 = v184;
    v183 = elt(env, 7); /* typeletfn */
    v183 = get(v185, v183);
    env = stack[-7];
    v185 = v183;
    if (v183 == nil) goto v134;
    v183 = v185;
    if (!consp(v183)) goto v116;
    v183 = elt(env, 8); /* "Apply called with non-id arg" */
    v184 = v185;
    v183 = list2(v183, v184);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    v184 = v183;
    v183 = v184;
    qvalue(elt(env, 9)) = v183; /* errmsg!* */
    v183 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v183 == nil)) goto v26;
    v183 = v184;
    fn = elt(env, 13); /* lprie */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    goto v26;

v26:
    v183 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v189;
    v183 = nil;
    { popv(8); return onevalue(v183); }

v116:
    stack[-3] = v185;
    stack[-5] = stack[-6];
    stack[-1] = stack[-4];
    stack[0] = v184;
    v183 = stack[-4];
    fn = elt(env, 12); /* getrtype */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    v183 = list2(stack[-2], v183);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    v183 = list3star(stack[-5], stack[-1], stack[0], v183);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    {
        Lisp_Object v190 = stack[-3];
        popv(8);
        fn = elt(env, 14); /* apply */
        return (*qfn2(fn))(qenv(fn), v190, v183);
    }

v134:
    stack[-3] = stack[-6];
    stack[-1] = stack[-4];
    stack[0] = v184;
    v183 = stack[-4];
    fn = elt(env, 12); /* getrtype */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    {
        Lisp_Object v191 = stack[-3];
        Lisp_Object v192 = stack[-1];
        Lisp_Object v193 = stack[0];
        Lisp_Object v194 = stack[-2];
        popv(8);
        fn = elt(env, 15); /* typelet */
        return (*qfnn(fn))(qenv(fn), 5, v191, v192, v193, v194, v183);
    }

v142:
    v183 = stack[0];
    if (v183 == nil) goto v195;
    v184 = stack[0];
    v183 = elt(env, 11); /* yetunknowntype */
    if (v184 == v183) goto v195;
    v184 = stack[0];
    v183 = elt(env, 7); /* typeletfn */
    v183 = get(v184, v183);
    env = stack[-7];
    v185 = v183;
    if (v183 == nil) goto v196;
    v183 = v185;
    if (!consp(v183)) goto v197;
    v183 = elt(env, 8); /* "Apply called with non-id arg" */
    v184 = v185;
    v183 = list2(v183, v184);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    v184 = v183;
    v183 = v184;
    qvalue(elt(env, 9)) = v183; /* errmsg!* */
    v183 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v183 == nil)) goto v198;
    v183 = v184;
    fn = elt(env, 13); /* lprie */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    goto v198;

v198:
    v183 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v189;
    v183 = nil;
    { popv(8); return onevalue(v183); }

v197:
    stack[-3] = v185;
    stack[-5] = stack[-6];
    stack[-1] = qvalue(elt(env, 3)); /* nil */
    v184 = stack[-2];
    v183 = stack[0];
    v183 = list2(v184, v183);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    v183 = list3star(stack[-5], stack[-4], stack[-1], v183);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    {
        Lisp_Object v199 = stack[-3];
        popv(8);
        fn = elt(env, 14); /* apply */
        return (*qfn2(fn))(qenv(fn), v199, v183);
    }

v196:
    v187 = stack[-6];
    v186 = stack[-4];
    v185 = qvalue(elt(env, 3)); /* nil */
    v184 = stack[-2];
    v183 = stack[0];
    {
        popv(8);
        fn = elt(env, 15); /* typelet */
        return (*qfnn(fn))(qenv(fn), 5, v187, v186, v185, v184, v183);
    }

v195:
    v188 = stack[-5];
    v187 = stack[-4];
    v186 = stack[-3];
    v185 = stack[-6];
    v184 = stack[-2];
    v183 = stack[-1];
    fn = elt(env, 16); /* letscalar */
    v183 = (*qfnn(fn))(qenv(fn), 6, v188, v187, v186, v185, v184, v183);
    nil = C_nil;
    if (exception_pending()) goto v189;
    v183 = nil;
    { popv(8); return onevalue(v183); }

v29:
    v187 = elt(env, 1); /* "Substitution for" */
    v186 = stack[-5];
    v185 = elt(env, 2); /* "not allowed" */
    v184 = qvalue(elt(env, 3)); /* nil */
    v183 = qvalue(elt(env, 4)); /* t */
    {
        popv(8);
        fn = elt(env, 17); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v187, v186, v185, v184, v183);
    }

v80:
    v183 = (Lisp_Object)1; /* 0 */
    stack[-5] = v183;
    v187 = elt(env, 1); /* "Substitution for" */
    v186 = stack[-5];
    v185 = elt(env, 2); /* "not allowed" */
    v184 = qvalue(elt(env, 3)); /* nil */
    v183 = qvalue(elt(env, 4)); /* t */
    {
        popv(8);
        fn = elt(env, 17); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v187, v186, v185, v184, v183);
    }
/* error exit handlers */
v189:
    popv(8);
    return nil;
}



/* Code for tot!-asym!-indp */

static Lisp_Object CC_totKasymKindp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tot-asym-indp");
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

v33:
    v106 = stack[0];
    v106 = (v106 == nil ? lisp_true : nil);
    if (!(v106 == nil)) { popv(2); return onevalue(v106); }
    v106 = stack[0];
    v106 = qcdr(v106);
    v106 = (v106 == nil ? lisp_true : nil);
    if (!(v106 == nil)) { popv(2); return onevalue(v106); }
    v106 = stack[0];
    v63 = qcar(v106);
    v106 = stack[0];
    v106 = qcdr(v106);
    v106 = qcar(v106);
    if (equal(v63, v106)) goto v66;
    v106 = stack[0];
    v106 = qcar(v106);
    if (!consp(v106)) goto v83;
    v106 = stack[0];
    v106 = qcar(v106);
    fn = elt(env, 2); /* indxchk */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-1];
    if (!(v106 == nil)) goto v90;
    v106 = stack[0];
    v106 = qcdr(v106);
    v106 = qcar(v106);
    fn = elt(env, 2); /* indxchk */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-1];
    if (!(v106 == nil)) goto v90;
    v106 = stack[0];
    v63 = qcar(v106);
    v106 = stack[0];
    v106 = qcdr(v106);
    v106 = qcar(v106);
    fn = elt(env, 3); /* indordlp */
    v106 = (*qfn2(fn))(qenv(fn), v63, v106);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-1];
    goto v90;

v90:
    if (v106 == nil) goto v66;
    v106 = stack[0];
    v106 = qcdr(v106);
    stack[0] = v106;
    goto v33;

v66:
    v106 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v106); }

v83:
    v106 = stack[0];
    v63 = qcar(v106);
    v106 = stack[0];
    v106 = qcdr(v106);
    v106 = qcar(v106);
    fn = elt(env, 4); /* indordp */
    v106 = (*qfn2(fn))(qenv(fn), v63, v106);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-1];
    goto v90;
/* error exit handlers */
v200:
    popv(2);
    return nil;
}



/* Code for kernelp */

static Lisp_Object CC_kernelp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernelp");
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
    v11 = stack[0];
    if (v11 == nil) goto v113;
    v11 = stack[0];
    fn = elt(env, 4); /* domain!*p */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-1];
    if (!(v11 == nil)) goto v113;
    v11 = stack[0];
    if (symbolp(v11)) goto v23;
    v11 = stack[0];
    fn = elt(env, 5); /* listp */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-1];
    if (v11 == nil) goto v107;
    v11 = stack[0];
    v11 = qcar(v11);
    if (!(symbolp(v11))) goto v107;
    v11 = stack[0];
    v28 = qcar(v11);
    v11 = elt(env, 3); /* (!*sq set setq plus minus difference times quotient) 
*/
    v11 = Lmemq(nil, v28, v11);
    if (!(v11 == nil)) goto v107;
    v11 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v11); }

v107:
    v11 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v11); }

v23:
    v11 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v11); }

v113:
    v11 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v11); }
/* error exit handlers */
v104:
    popv(2);
    return nil;
}



/* Code for find_triangles1 */

static Lisp_Object CC_find_triangles1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v36)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v54, v65, v9, v76, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_triangles1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v82 = v36;
    v54 = v0;
/* end of prologue */
    v83 = qvalue(elt(env, 1)); /* nil */
    v65 = v54;
    v76 = qcar(v65);
    v9 = qvalue(elt(env, 1)); /* nil */
    v65 = v54;
    v65 = qcdr(v65);
    v65 = qcar(v65);
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v54 = qcar(v54);
    {
        fn = elt(env, 2); /* select_triangles */
        return (*qfnn(fn))(qenv(fn), 6, v83, v76, v9, v65, v54, v82);
    }
}



/* Code for rfirst */

static Lisp_Object CC_rfirst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v103, v10, v48, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rfirst");
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
    v102 = stack[0];
    v102 = qcar(v102);
    stack[0] = v102;
    v102 = stack[0];
    fn = elt(env, 6); /* listeval0 */
    v103 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-2];
    stack[-1] = v103;
    v102 = elt(env, 1); /* list */
    if (!consp(v103)) goto v75;
    v103 = qcar(v103);
    if (!(v103 == v102)) goto v75;

v73:
    v102 = stack[-1];
    v102 = qcdr(v102);
    if (v102 == nil) goto v15;
    v102 = stack[-1];
    v102 = qcdr(v102);
    v102 = qcar(v102);
    {
        popv(3);
        fn = elt(env, 7); /* reval */
        return (*qfn1(fn))(qenv(fn), v102);
    }

v15:
    v105 = elt(env, 3); /* "Expression" */
    v48 = stack[0];
    v10 = elt(env, 4); /* "does not have part" */
    v103 = (Lisp_Object)17; /* 1 */
    v102 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 8); /* msgpri */
    v102 = (*qfnn(fn))(qenv(fn), 5, v105, v48, v10, v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v63;
    v102 = nil;
    { popv(3); return onevalue(v102); }

v75:
    v102 = stack[0];
    fn = elt(env, 9); /* aeval */
    v103 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-2];
    stack[-1] = v103;
    v102 = elt(env, 1); /* list */
    if (!consp(v103)) goto v9;
    v103 = qcar(v103);
    if (v103 == v102) goto v73;
    else goto v9;

v9:
    v103 = stack[0];
    v102 = elt(env, 2); /* "list" */
    fn = elt(env, 10); /* typerr */
    v102 = (*qfn2(fn))(qenv(fn), v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-2];
    goto v73;
/* error exit handlers */
v63:
    popv(3);
    return nil;
}



/* Code for prepcadr */

static Lisp_Object CC_prepcadr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepcadr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v91 = v0;
/* end of prologue */
    v75 = v91;
    v75 = qcdr(v75);
    v75 = qcar(v75);
    v75 = qcar(v75);
    if (v75 == nil) goto v113;
    v75 = v91;
    v75 = qcdr(v75);
    v91 = qcar(v75);
    v75 = elt(env, 1); /* prepf */
    {
        fn = elt(env, 2); /* sqform */
        return (*qfn2(fn))(qenv(fn), v91, v75);
    }

v113:
    v75 = (Lisp_Object)1; /* 0 */
    return onevalue(v75);
}



/* Code for dummy_nam */

static Lisp_Object CC_dummy_nam(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dummy_nam");
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
    v23 = v0;
/* end of prologue */
    fn = elt(env, 4); /* ordn */
    v66 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[0];
    v23 = elt(env, 1); /* symbolic */
    fn = elt(env, 5); /* list2vect!* */
    v23 = (*qfn2(fn))(qenv(fn), v66, v23);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[0];
    qvalue(elt(env, 2)) = v23; /* g_dvnames */
    v23 = qvalue(elt(env, 3)); /* t */
    { popv(1); return onevalue(v23); }
/* error exit handlers */
v67:
    popv(1);
    return nil;
}



/* Code for makeupsf */

static Lisp_Object MS_CDECL CC_makeupsf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v36,
                         Lisp_Object v37, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204, v205, v206, v207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "makeupsf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makeupsf");
#endif
    if (stack >= stacklimit)
    {
        push3(v37,v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v36,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v37;
    stack[-1] = v36;
    v207 = v0;
/* end of prologue */
    v204 = v207;
    v204 = qcar(v204);
    if (!consp(v204)) goto v83;
    v204 = v207;
    v205 = qcdr(v204);
    v204 = (Lisp_Object)17; /* 1 */
    if (v205 == v204) goto v83;
    v204 = v207;
    v204 = qcar(v204);
    v205 = qcar(v204);
    v204 = elt(env, 1); /* sqrt */
    if (v205 == v204) goto v96;
    v204 = v207;
    v204 = qcar(v204);
    v206 = v204;
    v204 = v206;
    v205 = qcar(v204);
    v204 = elt(env, 2); /* expt */
    if (v205 == v204) goto v143;
    v204 = qvalue(elt(env, 3)); /* nil */
    goto v95;

v95:
    if (v204 == nil) goto v208;
    v204 = v207;
    v205 = qcar(v204);
    v204 = stack[-1];
    v206 = v207;
    v206 = qcdr(v206);
    fn = elt(env, 5); /* !*multfexpt */
    v205 = (*qfnn(fn))(qenv(fn), 3, v205, v204, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-2];
    v204 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* addf */
        return (*qfn2(fn))(qenv(fn), v205, v204);
    }

v208:
    v205 = v207;
    v204 = (Lisp_Object)17; /* 1 */
    v204 = cons(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-2];
    v205 = ncons(v204);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-2];
    v204 = stack[-1];
    fn = elt(env, 7); /* multf */
    v205 = (*qfn2(fn))(qenv(fn), v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-2];
    v204 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* addf */
        return (*qfn2(fn))(qenv(fn), v205, v204);
    }

v143:
    v204 = v206;
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcar(v204);
    v206 = v204;
    v204 = v206;
    if (!consp(v204)) goto v124;
    v204 = v206;
    v205 = qcar(v204);
    v204 = elt(env, 4); /* quotient */
    if (v205 == v204) goto v99;
    v204 = qvalue(elt(env, 3)); /* nil */
    goto v95;

v99:
    v204 = v206;
    v204 = qcdr(v204);
    v204 = qcar(v204);
    if (is_number(v204)) goto v39;
    v204 = qvalue(elt(env, 3)); /* nil */
    goto v95;

v39:
    v204 = v206;
    v204 = qcdr(v204);
    v204 = qcdr(v204);
    v204 = qcar(v204);
    v204 = (is_number(v204) ? lisp_true : nil);
    goto v95;

v124:
    v204 = qvalue(elt(env, 3)); /* nil */
    goto v95;

v96:
    v204 = v207;
    v205 = qcar(v204);
    v204 = stack[-1];
    v206 = v207;
    v206 = qcdr(v206);
    fn = elt(env, 8); /* !*multfsqrt */
    v205 = (*qfnn(fn))(qenv(fn), 3, v205, v204, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-2];
    v204 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* addf */
        return (*qfn2(fn))(qenv(fn), v205, v204);
    }

v83:
    v205 = v207;
    v204 = (Lisp_Object)17; /* 1 */
    v204 = cons(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-2];
    v205 = ncons(v204);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-2];
    v204 = stack[-1];
    fn = elt(env, 7); /* multf */
    v205 = (*qfn2(fn))(qenv(fn), v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-2];
    v204 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* addf */
        return (*qfn2(fn))(qenv(fn), v205, v204);
    }
/* error exit handlers */
v209:
    popv(3);
    return nil;
}



/* Code for bf2rn1 */

static Lisp_Object CC_bf2rn1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v194, v199, v234, v235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bf2rn1");
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
    stack[-10] = nil;
    stack[-8] = nil;
    stack[-7] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-2] = nil;
    stack[0] = nil;
    v194 = stack[-9];
    v194 = qcdr(v194);
    v199 = qcar(v194);
    v194 = (Lisp_Object)1; /* 0 */
    v194 = (Lisp_Object)lessp2(v199, v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    v194 = v194 ? lisp_true : nil;
    env = stack[-11];
    if (v194 == nil) goto v20;
    v194 = qvalue(elt(env, 1)); /* t */
    stack[-10] = v194;
    stack[-1] = elt(env, 2); /* !:rd!: */
    v194 = stack[-9];
    v194 = qcdr(v194);
    v194 = qcar(v194);
    v199 = negate(v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    v194 = stack[-9];
    v194 = qcdr(v194);
    v194 = qcdr(v194);
    v194 = list2star(stack[-1], v199, v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    stack[-9] = v194;
    goto v20;

v20:
    v194 = stack[-9];
    stack[-3] = v194;
    goto v80;

v80:
    v194 = stack[-9];
    v194 = qcdr(v194);
    v199 = qcar(v194);
    v194 = stack[-9];
    v194 = qcdr(v194);
    v194 = qcdr(v194);
    v235 = v199;
    v234 = v194;
    v199 = v234;
    v194 = (Lisp_Object)1; /* 0 */
    if (v199 == v194) goto v18;
    v194 = v235;
    v199 = v234;
    v194 = ash(v194, v199);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    goto v125;

v125:
    stack[-1] = v194;
    v234 = elt(env, 2); /* !:rd!: */
    v199 = stack[-1];
    v194 = (Lisp_Object)1; /* 0 */
    v194 = list2star(v234, v199, v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    fn = elt(env, 5); /* csl_normbf */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    fn = elt(env, 6); /* difbf */
    v194 = (*qfn2(fn))(qenv(fn), stack[-9], v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    stack[-9] = v194;
    v194 = stack[-4];
    if (v194 == nil) goto v182;
    stack[-2] = stack[-8];
    v199 = stack[-1];
    v194 = stack[-7];
    v194 = times2(v199, v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    v194 = plus2(stack[-2], v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    v199 = v194;
    v194 = stack[-7];
    stack[-8] = v194;
    v194 = v199;
    stack[-7] = v194;
    v194 = stack[0];
    stack[-2] = v194;
    stack[0] = stack[-6];
    v199 = stack[-1];
    v194 = stack[-5];
    v194 = times2(v199, v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    v194 = plus2(stack[0], v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    v199 = v194;
    v194 = stack[-5];
    stack[-6] = v194;
    v194 = v199;
    stack[-5] = v194;
    goto v178;

v178:
    stack[-1] = stack[-3];
    v234 = elt(env, 2); /* !:rd!: */
    v199 = stack[-7];
    v194 = (Lisp_Object)1; /* 0 */
    stack[0] = list2star(v234, v199, v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    v234 = elt(env, 2); /* !:rd!: */
    v199 = stack[-5];
    v194 = (Lisp_Object)1; /* 0 */
    v199 = list2star(v234, v199, v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    v194 = qvalue(elt(env, 3)); /* !:bprec!: */
    fn = elt(env, 7); /* divide!: */
    v194 = (*qfnn(fn))(qenv(fn), 3, stack[0], v199, v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    fn = elt(env, 5); /* csl_normbf */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    fn = elt(env, 6); /* difbf */
    v194 = (*qfn2(fn))(qenv(fn), stack[-1], v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    stack[-1] = v194;
    v194 = stack[-1];
    v194 = qcdr(v194);
    v199 = qcar(v194);
    v194 = (Lisp_Object)1; /* 0 */
    v194 = (Lisp_Object)greaterp2(v199, v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    v194 = v194 ? lisp_true : nil;
    env = stack[-11];
    if (v194 == nil) goto v237;
    v194 = stack[-1];
    goto v238;

v238:
    stack[0] = v194;
    v194 = stack[-9];
    v194 = qcdr(v194);
    v199 = qcar(v194);
    v194 = (Lisp_Object)1; /* 0 */
    if (v199 == v194) goto v239;
    v194 = stack[0];
    v194 = qcdr(v194);
    v199 = qcar(v194);
    v194 = (Lisp_Object)1; /* 0 */
    if (v199 == v194) goto v239;
    v194 = stack[-2];
    if (v194 == nil) goto v240;
    v199 = stack[-2];
    v194 = stack[0];
    fn = elt(env, 8); /* greaterp!: */
    v194 = (*qfn2(fn))(qenv(fn), v199, v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    if (!(v194 == nil)) goto v240;
    v194 = stack[-10];
    if (v194 == nil) goto v147;
    v194 = stack[-8];
    v199 = negate(v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    v194 = stack[-6];
    popv(12);
    return cons(v199, v194);

v147:
    v199 = stack[-8];
    v194 = stack[-6];
    popv(12);
    return cons(v199, v194);

v240:
    v234 = qvalue(elt(env, 4)); /* bfone!* */
    v199 = stack[-9];
    v194 = qvalue(elt(env, 3)); /* !:bprec!: */
    fn = elt(env, 7); /* divide!: */
    v194 = (*qfnn(fn))(qenv(fn), 3, v234, v199, v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    fn = elt(env, 5); /* csl_normbf */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    stack[-9] = v194;
    goto v80;

v239:
    v194 = stack[-10];
    if (v194 == nil) goto v196;
    v194 = stack[-7];
    v199 = negate(v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    v194 = stack[-5];
    popv(12);
    return cons(v199, v194);

v196:
    v199 = stack[-7];
    v194 = stack[-5];
    popv(12);
    return cons(v199, v194);

v237:
    stack[0] = elt(env, 2); /* !:rd!: */
    v194 = stack[-1];
    v194 = qcdr(v194);
    v194 = qcar(v194);
    v199 = negate(v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    v194 = stack[-1];
    v194 = qcdr(v194);
    v194 = qcdr(v194);
    v194 = list2star(stack[0], v199, v194);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-11];
    goto v238;

v182:
    v194 = qvalue(elt(env, 1)); /* t */
    stack[-4] = v194;
    v194 = (Lisp_Object)17; /* 1 */
    stack[-8] = v194;
    v194 = stack[-1];
    stack[-7] = v194;
    v194 = (Lisp_Object)1; /* 0 */
    stack[-6] = v194;
    v194 = (Lisp_Object)17; /* 1 */
    stack[-5] = v194;
    goto v178;

v18:
    v194 = v235;
    goto v125;
/* error exit handlers */
v236:
    popv(12);
    return nil;
}



/* Code for cl_pop */

static Lisp_Object CC_cl_pop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v77;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_pop");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v77 = v0;
/* end of prologue */
    return onevalue(v77);
}



/* Code for get_mat */

static Lisp_Object CC_get_mat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v36)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_mat");
#endif
    if (stack >= stacklimit)
    {
        push2(v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v36);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v36;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = nil;
    v137 = stack[-2];
    v142 = elt(env, 1); /* id */
    if (v137 == v142) goto v68;
    v142 = qvalue(elt(env, 2)); /* nil */
    stack[-3] = v142;
    goto v83;

v83:
    v142 = stack[-1];
    v137 = Llength(nil, v142);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v142 = (Lisp_Object)1; /* 0 */
    v142 = (Lisp_Object)greaterp2(v137, v142);
    nil = C_nil;
    if (exception_pending()) goto v62;
    v142 = v142 ? lisp_true : nil;
    env = stack[-4];
    if (v142 == nil) goto v46;
    v142 = stack[-3];
    if (!(v142 == nil)) goto v46;
    v137 = stack[-2];
    v142 = stack[-1];
    v142 = qcar(v142);
    v142 = qcar(v142);
    if (!(equal(v137, v142))) goto v15;
    v142 = stack[-1];
    v142 = qcar(v142);
    v142 = qcdr(v142);
    v142 = qcar(v142);
    stack[0] = v142;
    v142 = qvalue(elt(env, 3)); /* t */
    stack[-3] = v142;
    goto v15;

v15:
    v142 = stack[-1];
    v142 = qcdr(v142);
    stack[-1] = v142;
    goto v83;

v46:
    v142 = stack[-3];
    if (!(v142 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v142 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v142 == nil)) goto v95;
    v142 = elt(env, 5); /* "error in get_mat" */
    fn = elt(env, 6); /* lprie */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    goto v95;

v95:
    v142 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v62;
    v142 = nil;
    { popv(5); return onevalue(v142); }

v68:
    v142 = stack[-1];
    v142 = qcar(v142);
    v142 = qcdr(v142);
    v142 = qcar(v142);
    fn = elt(env, 7); /* get!+row!+nr */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 8); /* mk!+unit!+mat */
        return (*qfn1(fn))(qenv(fn), v142);
    }
/* error exit handlers */
v62:
    popv(5);
    return nil;
}



/* Code for nonpolyp */

static Lisp_Object CC_nonpolyp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v36)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonpolyp");
#endif
    if (stack >= stacklimit)
    {
        push2(v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v36);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v36;
    stack[-1] = v0;
/* end of prologue */

v33:
    v12 = stack[-1];
    if (!consp(v12)) goto v72;
    v12 = stack[-1];
    v12 = qcar(v12);
    if (!consp(v12)) goto v72;
    v12 = stack[-1];
    v12 = qcar(v12);
    v12 = qcar(v12);
    v118 = qcar(v12);
    v12 = stack[0];
    if (v118 == v12) goto v34;
    v12 = stack[-1];
    v12 = qcar(v12);
    v12 = qcar(v12);
    v118 = qcar(v12);
    v12 = stack[0];
    fn = elt(env, 2); /* depend!-p */
    v12 = (*qfn2(fn))(qenv(fn), v118, v12);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    goto v50;

v50:
    if (!(v12 == nil)) { popv(3); return onevalue(v12); }
    v12 = stack[-1];
    v12 = qcar(v12);
    v118 = qcdr(v12);
    v12 = stack[0];
    v12 = CC_nonpolyp(env, v118, v12);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    if (!(v12 == nil)) { popv(3); return onevalue(v12); }
    v12 = stack[-1];
    v118 = qcdr(v12);
    v12 = stack[0];
    stack[-1] = v118;
    stack[0] = v12;
    goto v33;

v34:
    v12 = qvalue(elt(env, 1)); /* nil */
    goto v50;

v72:
    v12 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v12); }
/* error exit handlers */
v10:
    popv(3);
    return nil;
}



/* Code for limitrd */

static Lisp_Object MS_CDECL CC_limitrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v231, v230, v172, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "limitrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for limitrd");
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
    stack[-2] = nil;
    stack[-1] = nil;
    fn = elt(env, 13); /* lex */
    v231 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    v230 = qvalue(elt(env, 1)); /* char */
    v231 = elt(env, 2); /* (b v a r) */
    if (equal(v230, v231)) goto v108;
    v231 = qvalue(elt(env, 4)); /* nil */
    stack[-3] = v231;
    goto v49;

v49:
    v230 = qvalue(elt(env, 1)); /* char */
    v231 = elt(env, 5); /* (l o w l i m i t) */
    if (equal(v230, v231)) goto v86;
    v230 = qvalue(elt(env, 1)); /* char */
    v231 = elt(env, 6); /* (c o n d i t i o n) */
    if (equal(v230, v231)) goto v74;
    v231 = qvalue(elt(env, 4)); /* nil */
    stack[-2] = v231;
    goto v69;

v69:
    fn = elt(env, 14); /* mathml2 */
    v231 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    stack[0] = v231;
    fn = elt(env, 13); /* lex */
    v231 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    v231 = stack[-2];
    if (v231 == nil) goto v6;
    v231 = stack[-1];
    if (v231 == nil) goto v129;
    v231 = nil;
    { popv(5); return onevalue(v231); }

v129:
    v231 = stack[-2];
    v230 = qcar(v231);
    v231 = elt(env, 10); /* (a b o v e) */
    if (equal(v230, v231)) goto v51;
    v173 = stack[0];
    v172 = stack[-3];
    v231 = stack[-2];
    v231 = qcdr(v231);
    v230 = qcar(v231);
    v231 = elt(env, 12); /* min */
    {
        popv(5);
        fn = elt(env, 15); /* alg_limit */
        return (*qfnn(fn))(qenv(fn), 4, v173, v172, v230, v231);
    }

v51:
    v173 = stack[0];
    v172 = stack[-3];
    v231 = stack[-2];
    v231 = qcdr(v231);
    v230 = qcar(v231);
    v231 = elt(env, 11); /* plus */
    {
        popv(5);
        fn = elt(env, 15); /* alg_limit */
        return (*qfnn(fn))(qenv(fn), 4, v173, v172, v230, v231);
    }

v6:
    v173 = stack[0];
    v172 = stack[-3];
    v230 = stack[-1];
    v231 = elt(env, 9); /* norm */
    {
        popv(5);
        fn = elt(env, 15); /* alg_limit */
        return (*qfnn(fn))(qenv(fn), 4, v173, v172, v230, v231);
    }

v74:
    fn = elt(env, 16); /* conditionrd */
    v231 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    stack[-2] = v231;
    v230 = qvalue(elt(env, 1)); /* char */
    v231 = elt(env, 7); /* (!/ c o n d i t i o n) */
    if (equal(v230, v231)) goto v106;
    v230 = elt(env, 8); /* "</condition>" */
    v231 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 17); /* errorml */
    v231 = (*qfn2(fn))(qenv(fn), v230, v231);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    goto v106;

v106:
    fn = elt(env, 13); /* lex */
    v231 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    goto v69;

v86:
    fn = elt(env, 18); /* lowlimitrd */
    v231 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    stack[-1] = v231;
    fn = elt(env, 13); /* lex */
    v231 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    goto v69;

v108:
    fn = elt(env, 19); /* bvarrd */
    v231 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    stack[-3] = v231;
    v231 = stack[-3];
    v231 = qcdr(v231);
    v230 = qcar(v231);
    v231 = (Lisp_Object)17; /* 1 */
    v231 = Leqn(nil, v230, v231);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    if (v231 == nil) goto v28;
    v231 = stack[-3];
    v231 = qcar(v231);
    stack[-3] = v231;
    goto v84;

v84:
    fn = elt(env, 13); /* lex */
    v231 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    goto v49;

v28:
    v230 = elt(env, 3); /* "<degree>" */
    v231 = (Lisp_Object)129; /* 8 */
    fn = elt(env, 17); /* errorml */
    v231 = (*qfn2(fn))(qenv(fn), v230, v231);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-4];
    goto v84;
/* error exit handlers */
v205:
    popv(5);
    return nil;
}



/* Code for formoptimize1 */

static Lisp_Object MS_CDECL CC_formoptimize1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v36,
                         Lisp_Object v37, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v260, v261, v189;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formoptimize1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formoptimize1");
#endif
    if (stack >= stacklimit)
    {
        push3(v37,v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v36,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v37;
    stack[-7] = v36;
    stack[-1] = v0;
/* end of prologue */

v33:
    v260 = stack[-1];
    fn = elt(env, 12); /* constp */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-9];
    if (v260 == nil) goto v92;
    v260 = stack[-1];
        popv(10);
        return Lmkquote(nil, v260);

v92:
    v260 = stack[-1];
    if (!consp(v260)) goto v23;
    v260 = stack[-1];
    v261 = qcar(v260);
    v260 = elt(env, 1); /* (!:rd!: !:cr!: !:crn!: !:dn!:) */
    v260 = Lmember(nil, v261, v260);
    if (v260 == nil) goto v78;
    v260 = stack[-1];
    v260 = qcdr(v260);
    fn = elt(env, 13); /* chopchop */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-9];
    stack[-1] = v260;
    v260 = stack[-1];
    v261 = qcar(v260);
    v260 = stack[-1];
    v260 = qcdr(v260);
    fn = elt(env, 14); /* decimal2internal */
    v260 = (*qfn2(fn))(qenv(fn), v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
        popv(10);
        return Lmkquote(nil, v260);

v78:
    v260 = stack[-1];
    v261 = qcar(v260);
    v260 = elt(env, 2); /* !:int!: */
    if (v261 == v260) goto v35;
    v261 = stack[-1];
    v260 = elt(env, 3); /* eval */
    if (!consp(v261)) goto v24;
    v261 = qcar(v261);
    if (!(v261 == v260)) goto v24;
    stack[-2] = elt(env, 4); /* sq2pre */
    stack[0] = elt(env, 5); /* aeval */
    v260 = stack[-1];
    v260 = qcdr(v260);
    v189 = qcar(v260);
    v261 = stack[-7];
    v260 = stack[-6];
    fn = elt(env, 15); /* form1 */
    v260 = (*qfnn(fn))(qenv(fn), 3, v189, v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-9];
    v260 = list2(stack[0], v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
    {
        Lisp_Object v263 = stack[-2];
        popv(10);
        return list2(v263, v260);
    }

v24:
    v260 = stack[-1];
    v261 = qcar(v260);
    v260 = elt(env, 6); /* (lsetq rsetq lrsetq) */
    v260 = Lmemq(nil, v261, v260);
    if (v260 == nil) goto v264;
    v260 = stack[-1];
    v260 = qcar(v260);
    stack[-8] = v260;
    v260 = stack[-1];
    v260 = qcdr(v260);
    v260 = qcar(v260);
    stack[0] = v260;
    v260 = stack[-1];
    v260 = qcdr(v260);
    v260 = qcdr(v260);
    v260 = qcar(v260);
    stack[-5] = v260;
    v261 = stack[-8];
    v260 = elt(env, 7); /* (lsetq lrsetq) */
    v260 = Lmemq(nil, v261, v260);
    if (v260 == nil) goto v265;
    v260 = stack[0];
    fn = elt(env, 16); /* listp */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-9];
    if (v260 == nil) goto v265;
    v260 = stack[0];
    stack[-4] = qcar(v260);
    v260 = stack[0];
    v260 = qcdr(v260);
    stack[-3] = v260;
    v260 = stack[-3];
    if (v260 == nil) goto v145;
    v260 = stack[-3];
    v260 = qcar(v260);
    v261 = elt(env, 3); /* eval */
    v260 = list2(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-9];
    v260 = ncons(v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-9];
    stack[-1] = v260;
    stack[-2] = v260;
    goto v144;

v144:
    v260 = stack[-3];
    v260 = qcdr(v260);
    stack[-3] = v260;
    v260 = stack[-3];
    if (v260 == nil) goto v174;
    stack[0] = stack[-1];
    v260 = stack[-3];
    v260 = qcar(v260);
    v261 = elt(env, 3); /* eval */
    v260 = list2(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-9];
    v260 = ncons(v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-9];
    v260 = Lrplacd(nil, stack[0], v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-9];
    v260 = stack[-1];
    v260 = qcdr(v260);
    stack[-1] = v260;
    goto v144;

v174:
    v260 = stack[-2];
    goto v56;

v56:
    v260 = cons(stack[-4], v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-9];
    stack[0] = v260;
    goto v265;

v265:
    v261 = stack[-8];
    v260 = elt(env, 9); /* (rsetq lrsetq) */
    v260 = Lmemq(nil, v261, v260);
    if (v260 == nil) goto v266;
    v261 = elt(env, 3); /* eval */
    v260 = stack[-5];
    v260 = list2(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-9];
    stack[-5] = v260;
    goto v266;

v266:
    v189 = elt(env, 10); /* setq */
    v261 = stack[0];
    v260 = stack[-5];
    v189 = list3(v189, v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-9];
    v261 = stack[-7];
    v260 = stack[-6];
    stack[-1] = v189;
    stack[-7] = v261;
    stack[-6] = v260;
    goto v33;

v145:
    v260 = qvalue(elt(env, 8)); /* nil */
    goto v56;

v264:
    stack[-4] = elt(env, 11); /* list */
    v260 = stack[-1];
    stack[-3] = v260;
    v260 = stack[-3];
    if (v260 == nil) goto v267;
    v260 = stack[-3];
    v260 = qcar(v260);
    v189 = v260;
    v261 = stack[-7];
    v260 = stack[-6];
    v260 = CC_formoptimize1(env, 3, v189, v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-9];
    v260 = ncons(v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-9];
    stack[-1] = v260;
    stack[-2] = v260;
    goto v214;

v214:
    v260 = stack[-3];
    v260 = qcdr(v260);
    stack[-3] = v260;
    v260 = stack[-3];
    if (v260 == nil) goto v268;
    stack[0] = stack[-1];
    v260 = stack[-3];
    v260 = qcar(v260);
    v189 = v260;
    v261 = stack[-7];
    v260 = stack[-6];
    v260 = CC_formoptimize1(env, 3, v189, v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-9];
    v260 = ncons(v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-9];
    v260 = Lrplacd(nil, stack[0], v260);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-9];
    v260 = stack[-1];
    v260 = qcdr(v260);
    stack[-1] = v260;
    goto v214;

v268:
    v260 = stack[-2];
    goto v162;

v162:
    {
        Lisp_Object v269 = stack[-4];
        popv(10);
        return cons(v269, v260);
    }

v267:
    v260 = qvalue(elt(env, 8)); /* nil */
    goto v162;

v35:
    v260 = stack[-1];
    v260 = qcdr(v260);
    v260 = qcar(v260);
        popv(10);
        return Lmkquote(nil, v260);

v23:
    v260 = stack[-1];
        popv(10);
        return Lmkquote(nil, v260);
/* error exit handlers */
v262:
    popv(10);
    return nil;
}



/* Code for xregister_wedge_pair */

static Lisp_Object MS_CDECL CC_xregister_wedge_pair(Lisp_Object env, int nargs, ...)
{
    Lisp_Object v37;
    argcheck(nargs, 0, "xregister_wedge_pair");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xregister_wedge_pair");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v37 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v37);
}



/* Code for denlist */

static Lisp_Object CC_denlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v36)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for denlist");
#endif
    if (stack >= stacklimit)
    {
        push2(v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v36);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v36;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v58;

v58:
    v74 = stack[-1];
    if (v74 == nil) goto v68;
    v74 = stack[-1];
    v74 = qcar(v74);
    v17 = Llength(nil, v74);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    v74 = (Lisp_Object)33; /* 2 */
    if (v17 == v74) goto v9;
    v74 = stack[-1];
    v17 = qcar(v74);
    v74 = stack[0];
    fn = elt(env, 1); /* ev!-denom3 */
    v17 = (*qfn2(fn))(qenv(fn), v17, v74);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    v74 = stack[-2];
    v74 = cons(v17, v74);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    stack[-2] = v74;
    v74 = stack[-1];
    v74 = qcdr(v74);
    stack[-1] = v74;
    goto v58;

v9:
    v74 = stack[-1];
    v17 = qcar(v74);
    v74 = stack[0];
    fn = elt(env, 2); /* ev!-denom2 */
    v17 = (*qfn2(fn))(qenv(fn), v17, v74);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    v74 = stack[-2];
    v74 = cons(v17, v74);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    stack[-2] = v74;
    v74 = stack[-1];
    v74 = qcdr(v74);
    stack[-1] = v74;
    goto v58;

v68:
    v74 = stack[-2];
    {
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v74);
    }
/* error exit handlers */
v102:
    popv(4);
    return nil;
}



/* Code for red_redpol */

static Lisp_Object CC_red_redpol(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v36)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_redpol");
#endif
    if (stack >= stacklimit)
    {
        push2(v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v36);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v9 = v36;
    stack[0] = v0;
/* end of prologue */
    fn = elt(env, 2); /* red_prepare */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-1];
    v76 = qvalue(elt(env, 1)); /* !*red_total */
    if (v76 == nil) goto v71;
    v76 = stack[0];
    fn = elt(env, 3); /* red_totalred */
    v9 = (*qfn2(fn))(qenv(fn), v76, v9);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-1];
    goto v108;

v108:
    {
        popv(2);
        fn = elt(env, 4); /* red_extract */
        return (*qfn1(fn))(qenv(fn), v9);
    }

v71:
    v76 = stack[0];
    fn = elt(env, 5); /* red_topred */
    v9 = (*qfn2(fn))(qenv(fn), v76, v9);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-1];
    goto v108;
/* error exit handlers */
v107:
    popv(2);
    return nil;
}



/* Code for gi */

static Lisp_Object CC_gi(Lisp_Object env,
                         Lisp_Object v36, Lisp_Object v37)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gi");
#endif
    if (stack >= stacklimit)
    {
        push2(v37,v36);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v36,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v37;
    v31 = v36;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = nil; /* gg */
    qvalue(elt(env, 1)) = v31; /* gg */
    stack[-2] = nil;
    v31 = qvalue(elt(env, 1)); /* gg */
    stack[-1] = v31;
    goto v67;

v67:
    v31 = stack[-1];
    if (v31 == nil) goto v66;
    v31 = stack[-1];
    v31 = qcar(v31);
    stack[0] = v31;
    v31 = stack[0];
    v31 = qcdr(v31);
    fn = elt(env, 3); /* class */
    v32 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-5];
    v31 = stack[-3];
    if (!(equal(v32, v31))) goto v46;
    v32 = stack[0];
    v31 = stack[-2];
    v31 = cons(v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-5];
    stack[-2] = v31;
    goto v46;

v46:
    v31 = stack[-1];
    v31 = qcdr(v31);
    stack[-1] = v31;
    goto v67;

v66:
    v31 = stack[-2];
    qvalue(elt(env, 1)) = stack[-4]; /* gg */
    { popv(6); return onevalue(v31); }
/* error exit handlers */
v61:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* gg */
    popv(6);
    return nil;
}



/* Code for dv_skelsplit1 */

static Lisp_Object CC_dv_skelsplit1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v36)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v319, v320;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skelsplit1");
#endif
    if (stack >= stacklimit)
    {
        push2(v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v36);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v36;
    stack[-11] = v0;
/* end of prologue */
    stack[-12] = nil;
    stack[-9] = nil;
    stack[-8] = nil;
    stack[-7] = nil;
    stack[-6] = nil;
    v319 = stack[-11];
    v319 = qcdr(v319);
    v319 = qcar(v319);
    if (is_number(v319)) goto v19;
    v319 = stack[-11];
    v319 = qcdr(v319);
    v319 = Llength(nil, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    stack[0] = v319;
    v319 = stack[0];
    v319 = sub1(v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = Lmkvect(nil, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    stack[-5] = v319;
    v319 = stack[0];
    stack[-4] = v319;
    v319 = stack[-11];
    v319 = qcdr(v319);
    v319 = Lreverse(nil, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    stack[-3] = v319;
    goto v181;

v181:
    v319 = stack[-3];
    if (v319 == nil) goto v322;
    v319 = stack[-3];
    v319 = qcar(v319);
    stack[-2] = v319;
    stack[-1] = stack[-5];
    v319 = stack[-4];
    stack[0] = sub1(v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v320 = stack[-2];
    v319 = stack[-10];
    v319 = CC_dv_skelsplit1(env, v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v319;
    stack[0] = stack[-5];
    v319 = stack[-4];
    v319 = sub1(v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v319/(16/CELL)));
    v320 = qcar(v319);
    v319 = stack[-6];
    v319 = cons(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    stack[-6] = v319;
    v320 = stack[-4];
    v319 = stack[-12];
    v319 = cons(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    stack[-12] = v319;
    v319 = stack[-4];
    v319 = sub1(v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    stack[-4] = v319;
    v319 = stack[-3];
    v319 = qcdr(v319);
    stack[-3] = v319;
    goto v181;

v322:
    v319 = stack[-6];
    stack[-3] = v319;
    goto v202;

v202:
    v319 = stack[-3];
    if (v319 == nil) goto v230;
    v319 = stack[-3];
    v319 = qcar(v319);
    fn = elt(env, 3); /* copy */
    v319 = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    stack[-2] = v319;
    v319 = stack[-2];
    fn = elt(env, 4); /* lastpair */
    v319 = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    stack[-1] = v319;
    v319 = stack[-3];
    v319 = qcdr(v319);
    stack[-3] = v319;
    v319 = stack[-1];
    if (!consp(v319)) goto v202;
    else goto v136;

v136:
    v319 = stack[-3];
    if (v319 == nil) goto v323;
    stack[0] = stack[-1];
    v319 = stack[-3];
    v319 = qcar(v319);
    fn = elt(env, 3); /* copy */
    v319 = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = Lrplacd(nil, stack[0], v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = stack[-1];
    fn = elt(env, 4); /* lastpair */
    v319 = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    stack[-1] = v319;
    v319 = stack[-3];
    v319 = qcdr(v319);
    stack[-3] = v319;
    goto v136;

v323:
    v319 = stack[-2];
    goto v242;

v242:
    stack[-6] = v319;
    goto v324;

v324:
    v319 = stack[-11];
    v320 = qcar(v319);
    v319 = elt(env, 2); /* !* */
    if (v320 == v319) goto v167;
    v319 = stack[-12];
    stack[-3] = v319;
    goto v260;

v260:
    v319 = stack[-3];
    if (v319 == nil) goto v325;
    v319 = stack[-3];
    v319 = qcar(v319);
    stack[-2] = v319;
    v319 = stack[-9];
    if (v319 == nil) goto v326;
    stack[0] = stack[-5];
    v319 = stack[-2];
    v319 = sub1(v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v319/(16/CELL)));
    v320 = qcar(v319);
    v319 = stack[-9];
    v319 = qcar(v319);
    if (equal(v320, v319)) goto v327;
    v320 = stack[-9];
    v319 = stack[-7];
    v319 = cons(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    stack[-7] = v319;
    stack[0] = stack[-5];
    v319 = stack[-2];
    v319 = sub1(v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v319/(16/CELL)));
    stack[-1] = qcar(v319);
    stack[0] = stack[-5];
    v319 = stack[-2];
    v319 = sub1(v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v319/(16/CELL)));
    v320 = qcdr(v319);
    v319 = qvalue(elt(env, 1)); /* nil */
    v319 = list2star(stack[-1], v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    stack[-9] = v319;
    goto v262;

v262:
    v319 = stack[-3];
    v319 = qcdr(v319);
    stack[-3] = v319;
    goto v260;

v327:
    stack[-1] = stack[-9];
    stack[0] = stack[-5];
    v319 = stack[-2];
    v319 = sub1(v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v319/(16/CELL)));
    v320 = qcdr(v319);
    v319 = stack[-9];
    v319 = qcdr(v319);
    v319 = cons(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = Lrplacd(nil, stack[-1], v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    goto v262;

v326:
    stack[0] = stack[-5];
    v319 = stack[-2];
    v319 = sub1(v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v319/(16/CELL)));
    stack[-1] = qcar(v319);
    stack[0] = stack[-5];
    v319 = stack[-2];
    v319 = sub1(v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v319/(16/CELL)));
    v320 = qcdr(v319);
    v319 = qvalue(elt(env, 1)); /* nil */
    v319 = list2star(stack[-1], v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    stack[-9] = v319;
    goto v262;

v325:
    v320 = stack[-9];
    v319 = stack[-7];
    v319 = cons(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    stack[-7] = v319;
    v319 = stack[-7];
    stack[-1] = v319;
    goto v328;

v328:
    v319 = stack[-1];
    if (v319 == nil) goto v329;
    v319 = stack[-1];
    v319 = qcar(v319);
    v320 = v319;
    v319 = v320;
    v319 = qcdr(v319);
    if (v319 == nil) goto v330;
    v319 = stack[-11];
    stack[0] = qcar(v319);
    v319 = v320;
    v319 = qcdr(v319);
    v319 = Lreverse(nil, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = cons(stack[0], v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v320 = v319;
    v319 = stack[-8];
    v319 = cons(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    stack[-8] = v319;
    goto v330;

v330:
    v319 = stack[-1];
    v319 = qcdr(v319);
    stack[-1] = v319;
    goto v328;

v329:
    v319 = stack[-8];
    v320 = Llength(nil, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = (Lisp_Object)17; /* 1 */
    if (v320 == v319) goto v331;
    v320 = elt(env, 2); /* !* */
    v319 = stack[-8];
    v319 = cons(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    stack[-8] = v319;
    goto v332;

v332:
    v320 = stack[-6];
    v319 = stack[-8];
    popv(14);
    return cons(v320, v319);

v331:
    v319 = stack[-8];
    v319 = qcar(v319);
    stack[-8] = v319;
    goto v332;

v167:
    v319 = stack[-12];
    v319 = Lreverse(nil, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    stack[-2] = v319;
    goto v258;

v258:
    v319 = stack[-2];
    if (v319 == nil) goto v250;
    v319 = stack[-2];
    v319 = qcar(v319);
    stack[-1] = v319;
    stack[0] = stack[-5];
    v319 = stack[-1];
    v319 = sub1(v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v319/(16/CELL)));
    v319 = qcdr(v319);
    if (v319 == nil) goto v333;
    stack[0] = stack[-5];
    v319 = stack[-1];
    v319 = sub1(v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v319/(16/CELL)));
    v320 = qcdr(v319);
    v319 = stack[-8];
    v319 = cons(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    stack[-8] = v319;
    goto v333;

v333:
    v319 = stack[-2];
    v319 = qcdr(v319);
    stack[-2] = v319;
    goto v258;

v250:
    v319 = stack[-8];
    v320 = Llength(nil, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = (Lisp_Object)17; /* 1 */
    if (v320 == v319) goto v155;
    v319 = stack[-8];
    if (v319 == nil) goto v183;
    v320 = elt(env, 2); /* !* */
    v319 = stack[-8];
    v319 = cons(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    stack[-8] = v319;
    goto v183;

v183:
    v320 = stack[-6];
    v319 = stack[-8];
    popv(14);
    return cons(v320, v319);

v155:
    v319 = stack[-8];
    v319 = qcar(v319);
    stack[-8] = v319;
    goto v183;

v230:
    v319 = qvalue(elt(env, 1)); /* nil */
    goto v242;

v19:
    v319 = stack[-10];
    stack[-5] = v319;
    v319 = stack[-11];
    v319 = qcdr(v319);
    stack[-12] = v319;
    v319 = stack[-11];
    v319 = qcdr(v319);
    stack[-4] = v319;
    v319 = stack[-4];
    if (v319 == nil) goto v81;
    v319 = stack[-4];
    v319 = qcar(v319);
    stack[0] = stack[-5];
    v319 = sub1(v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v319/(16/CELL)));
    v319 = qcar(v319);
    v319 = ncons(v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    stack[-2] = v319;
    stack[-3] = v319;
    goto v65;

v65:
    v319 = stack[-4];
    v319 = qcdr(v319);
    stack[-4] = v319;
    v319 = stack[-4];
    if (v319 == nil) goto v18;
    stack[-1] = stack[-2];
    v319 = stack[-4];
    v319 = qcar(v319);
    stack[0] = stack[-5];
    v319 = sub1(v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v319/(16/CELL)));
    v319 = qcar(v319);
    v319 = ncons(v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = Lrplacd(nil, stack[-1], v319);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-13];
    v319 = stack[-2];
    v319 = qcdr(v319);
    stack[-2] = v319;
    goto v65;

v18:
    v319 = stack[-3];
    goto v54;

v54:
    stack[-6] = v319;
    goto v324;

v81:
    v319 = qvalue(elt(env, 1)); /* nil */
    goto v54;
/* error exit handlers */
v321:
    popv(14);
    return nil;
}



/* Code for addfactors */

static Lisp_Object CC_addfactors(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v36)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v26, v27, v40;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addfactors");
#endif
    if (stack >= stacklimit)
    {
        push2(v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v36);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v27 = v36;
    v40 = v0;
/* end of prologue */
    v26 = v40;
    v25 = (Lisp_Object)17; /* 1 */
    if (v26 == v25) goto v80;
    v26 = v27;
    v25 = (Lisp_Object)17; /* 1 */
    if (v26 == v25) { popv(3); return onevalue(v40); }
    v26 = v40;
    v25 = elt(env, 2); /* times */
    if (!consp(v26)) goto v93;
    v26 = qcar(v26);
    if (!(v26 == v25)) goto v93;
    stack[-1] = elt(env, 2); /* times */
    v25 = v40;
    stack[0] = qcdr(v25);
    v26 = v27;
    v25 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* prepf1 */
    v25 = (*qfn2(fn))(qenv(fn), v26, v25);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    v26 = v25;
    v25 = v26;
    if (v25 == nil) goto v117;
    v25 = v26;
    fn = elt(env, 4); /* replus */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    goto v94;

v94:
    v25 = ncons(v25);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    v25 = Lnconc(nil, stack[0], v25);
    nil = C_nil;
    if (exception_pending()) goto v39;
    {
        Lisp_Object v131 = stack[-1];
        popv(3);
        return cons(v131, v25);
    }

v117:
    v25 = (Lisp_Object)1; /* 0 */
    goto v94;

v93:
    stack[0] = v40;
    v26 = v27;
    v25 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* prepf1 */
    v25 = (*qfn2(fn))(qenv(fn), v26, v25);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    v26 = v25;
    v25 = v26;
    if (v25 == nil) goto v2;
    v25 = v26;
    fn = elt(env, 4); /* replus */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    goto v24;

v24:
    v25 = list2(stack[0], v25);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 5); /* retimes */
        return (*qfn1(fn))(qenv(fn), v25);
    }

v2:
    v25 = (Lisp_Object)1; /* 0 */
    goto v24;

v80:
    v26 = v27;
    v25 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* prepf1 */
    v25 = (*qfn2(fn))(qenv(fn), v26, v25);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    v26 = v25;
    v25 = v26;
    if (v25 == nil) goto v71;
    v25 = v26;
    {
        popv(3);
        fn = elt(env, 4); /* replus */
        return (*qfn1(fn))(qenv(fn), v25);
    }

v71:
    v25 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v25); }
/* error exit handlers */
v39:
    popv(3);
    return nil;
}



/* Code for rule!-list */

static Lisp_Object CC_ruleKlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v36)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v324, v252, v221, v336, v198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rule-list");
#endif
    if (stack >= stacklimit)
    {
        push2(v36,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v36);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v36;
    stack[-2] = v0;
/* end of prologue */

v68:
    v324 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v324; /* frasc!* */
    v324 = stack[-2];
    if (v324 == nil) goto v66;
    stack[0] = stack[-2];
    v324 = qvalue(elt(env, 1)); /* nil */
    v324 = ncons(v324);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    if (equal(stack[0], v324)) goto v66;
    v324 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 3)) = v324; /* mcond!* */
    v324 = stack[-2];
    v324 = qcar(v324);
    stack[-3] = v324;
    v324 = stack[-3];
    if (symbolp(v324)) goto v104;
    v324 = stack[-3];
    v252 = qcar(v324);
    v324 = elt(env, 6); /* list */
    if (v252 == v324) goto v62;
    v324 = stack[-3];
    v252 = qcar(v324);
    v324 = elt(env, 8); /* equal */
    if (v252 == v324) goto v124;
    v324 = stack[-3];
    v252 = qcar(v324);
    v324 = elt(env, 12); /* replaceby */
    if (v252 == v324) goto v65;
    v252 = stack[-3];
    v324 = elt(env, 13); /* "rule" */
    fn = elt(env, 16); /* typerr */
    v324 = (*qfn2(fn))(qenv(fn), v252, v324);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    goto v65;

v65:
    v324 = stack[-3];
    v324 = qcdr(v324);
    v324 = qcar(v324);
    fn = elt(env, 17); /* remove!-free!-vars */
    v324 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    stack[0] = v324;
    v324 = stack[-3];
    v324 = qcdr(v324);
    v324 = qcdr(v324);
    v252 = qcar(v324);
    v324 = elt(env, 14); /* when */
    if (!consp(v252)) goto v338;
    v252 = qcar(v252);
    if (!(v252 == v324)) goto v338;
    v324 = stack[-3];
    v324 = qcdr(v324);
    v324 = qcdr(v324);
    v324 = qcar(v324);
    v324 = qcdr(v324);
    v324 = qcdr(v324);
    v324 = qcar(v324);
    fn = elt(env, 18); /* remove!-free!-vars!* */
    v221 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    v252 = qvalue(elt(env, 1)); /* nil */
    v324 = elt(env, 15); /* algebraic */
    fn = elt(env, 19); /* formbool */
    v324 = (*qfnn(fn))(qenv(fn), 3, v221, v252, v324);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    qvalue(elt(env, 3)) = v324; /* mcond!* */
    v324 = stack[-3];
    v324 = qcdr(v324);
    v324 = qcdr(v324);
    v324 = qcar(v324);
    v324 = qcdr(v324);
    v324 = qcar(v324);
    fn = elt(env, 18); /* remove!-free!-vars!* */
    v324 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    goto v224;

v224:
    v198 = stack[0];
    v336 = v324;
    v221 = qvalue(elt(env, 2)); /* frasc!* */
    v252 = qvalue(elt(env, 3)); /* mcond!* */
    v324 = stack[-1];
    fn = elt(env, 20); /* rule!* */
    v324 = (*qfnn(fn))(qenv(fn), 5, v198, v336, v221, v252, v324);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    v324 = stack[-2];
    v324 = qcdr(v324);
    stack[-2] = v324;
    goto v68;

v338:
    v324 = stack[-3];
    v324 = qcdr(v324);
    v324 = qcdr(v324);
    v324 = qcar(v324);
    fn = elt(env, 18); /* remove!-free!-vars!* */
    v324 = (*qfn1(fn))(qenv(fn), v324);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    goto v224;

v124:
    v324 = qvalue(elt(env, 9)); /* !*msg */
    if (v324 == nil) goto v65;
    v252 = elt(env, 10); /* "***" */
    v324 = elt(env, 11); /* "Please use => instead of = in rules" */
    fn = elt(env, 21); /* lpriw */
    v324 = (*qfn2(fn))(qenv(fn), v252, v324);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    goto v65;

v62:
    v324 = stack[-3];
    v252 = qcdr(v324);
    v324 = stack[-2];
    v324 = qcdr(v324);
    v324 = Lappend(nil, v252, v324);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    stack[-2] = v324;
    goto v68;

v104:
    v252 = stack[-3];
    v324 = elt(env, 5); /* avalue */
    v324 = get(v252, v324);
    env = stack[-4];
    v221 = v324;
    if (v324 == nil) goto v47;
    v324 = v221;
    v252 = qcar(v324);
    v324 = elt(env, 6); /* list */
    if (!(v252 == v324)) goto v47;
    v324 = v221;
    v324 = qcdr(v324);
    v324 = qcar(v324);
    v324 = qcdr(v324);
    v252 = Lreverse(nil, v324);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    v324 = stack[-2];
    v324 = qcdr(v324);
    v324 = Lappend(nil, v252, v324);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    stack[-2] = v324;
    goto v68;

v47:
    v252 = stack[-3];
    v324 = elt(env, 7); /* "rule list" */
    fn = elt(env, 16); /* typerr */
    v324 = (*qfn2(fn))(qenv(fn), v252, v324);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    goto v65;

v66:
    v324 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 3)) = v324; /* mcond!* */
    { popv(5); return onevalue(v324); }
/* error exit handlers */
v337:
    popv(5);
    return nil;
}



setup_type const u46_setup[] =
{
    {"rm_neg_pow",              CC_rm_neg_pow,  too_many_1,    wrong_no_1},
    {"vevzero?1",               CC_vevzeroW1,   too_many_1,    wrong_no_1},
    {"xriterion_2",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_xriterion_2},
    {"r2flbf",                  CC_r2flbf,      too_many_1,    wrong_no_1},
    {"*ex2sf",                  CC_Hex2sf,      too_many_1,    wrong_no_1},
    {"lf=zero",                 CC_lfMzero,     too_many_1,    wrong_no_1},
    {"*n2a",                    CC_Hn2a,        too_many_1,    wrong_no_1},
    {"mk_rep_mat",              too_few_2,      CC_mk_rep_mat, wrong_no_2},
    {"freeof-dfl",              too_few_2,      CC_freeofKdfl, wrong_no_2},
    {"aex_add",                 too_few_2,      CC_aex_add,    wrong_no_2},
    {"lowlimitrd",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_lowlimitrd},
    {"column_dim",              CC_column_dim,  too_many_1,    wrong_no_1},
    {"xpndwedge",               CC_xpndwedge,   too_many_1,    wrong_no_1},
    {":quotient",               too_few_2,      CC_Tquotient,  wrong_no_2},
    {"s_actual_world1",         CC_s_actual_world1,too_many_1, wrong_no_1},
    {"*sf2ex",                  too_few_2,      CC_Hsf2ex,     wrong_no_2},
    {"get-current-representation",CC_getKcurrentKrepresentation,too_many_1,wrong_no_1},
    {"ofsf_smmkatl-and",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smmkatlKand},
    {"replace-nth",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_replaceKnth},
    {"freeof-df",               too_few_2,      CC_freeofKdf,  wrong_no_2},
    {"cl_applysac2",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_applysac2},
    {"seprd",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_seprd},
    {"search4facf",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_search4facf},
    {"getvariables",            CC_getvariables,too_many_1,    wrong_no_1},
    {"codfac",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_codfac},
    {"let3",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_let3},
    {"tot-asym-indp",           CC_totKasymKindp,too_many_1,   wrong_no_1},
    {"kernelp",                 CC_kernelp,     too_many_1,    wrong_no_1},
    {"find_triangles1",         too_few_2,      CC_find_triangles1,wrong_no_2},
    {"rfirst",                  CC_rfirst,      too_many_1,    wrong_no_1},
    {"prepcadr",                CC_prepcadr,    too_many_1,    wrong_no_1},
    {"dummy_nam",               CC_dummy_nam,   too_many_1,    wrong_no_1},
    {"makeupsf",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeupsf},
    {"bf2rn1",                  CC_bf2rn1,      too_many_1,    wrong_no_1},
    {"cl_pop",                  CC_cl_pop,      too_many_1,    wrong_no_1},
    {"get_mat",                 too_few_2,      CC_get_mat,    wrong_no_2},
    {"nonpolyp",                too_few_2,      CC_nonpolyp,   wrong_no_2},
    {"limitrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_limitrd},
    {"formoptimize1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_formoptimize1},
    {"xregister_wedge_pair",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_xregister_wedge_pair},
    {"denlist",                 too_few_2,      CC_denlist,    wrong_no_2},
    {"red_redpol",              too_few_2,      CC_red_redpol, wrong_no_2},
    {"gi",                      too_few_2,      CC_gi,         wrong_no_2},
    {"dv_skelsplit1",           too_few_2,      CC_dv_skelsplit1,wrong_no_2},
    {"addfactors",              too_few_2,      CC_addfactors, wrong_no_2},
    {"rule-list",               too_few_2,      CC_ruleKlist,  wrong_no_2},
    {NULL, (one_args *)"u46", (two_args *)"11209 8603331 497475", 0}
};

/* end of generated code */
