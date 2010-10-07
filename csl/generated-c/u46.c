
/* $destdir\u46.c        Machine generated C code */

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


/* Code for lto_almerge */

static Lisp_Object CC_lto_almerge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_almerge");
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
    v22 = v0;
/* end of prologue */

v25:
    v23 = v22;
    if (v23 == nil) goto v26;
    v23 = v22;
    v23 = qcdr(v23);
    if (v23 == nil) goto v27;
    v23 = v22;
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    if (v23 == nil) goto v28;
    v23 = v22;
    stack[0] = qcar(v23);
    v23 = qcdr(v22);
    v22 = stack[-3];
    v22 = CC_lto_almerge(env, v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    v22 = list2(stack[0], v22);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    v23 = stack[-3];
    stack[-3] = v23;
    goto v25;

v28:
    v23 = v22;
    v23 = qcdr(v23);
    v23 = qcar(v23);
    stack[-4] = v23;
    v22 = qcar(v22);
    stack[-2] = v22;
    goto v30;

v30:
    v22 = stack[-2];
    if (v22 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v22 = stack[-2];
    v22 = qcar(v22);
    v23 = v22;
    v22 = v23;
    v24 = qcar(v22);
    v22 = stack[-4];
    v22 = Lassoc(nil, v24, v22);
    v24 = v22;
    v22 = v24;
    if (v22 == nil) goto v31;
    stack[-1] = v24;
    stack[0] = stack[-3];
    v22 = v23;
    v22 = qcdr(v22);
    v23 = v24;
    v23 = qcdr(v23);
    v22 = list2(v22, v23);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    fn = elt(env, 2); /* apply */
    v22 = (*qfn2(fn))(qenv(fn), stack[0], v22);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    fn = elt(env, 3); /* setcdr */
    v22 = (*qfn2(fn))(qenv(fn), stack[-1], v22);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    goto v32;

v32:
    v22 = stack[-2];
    v22 = qcdr(v22);
    stack[-2] = v22;
    goto v30;

v31:
    v22 = stack[-4];
    v22 = cons(v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    stack[-4] = v22;
    goto v32;

v27:
    v22 = qcar(v22);
    { popv(6); return onevalue(v22); }

v26:
    v22 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v22); }
/* error exit handlers */
v29:
    popv(6);
    return nil;
}



/* Code for girationalize!: */

static Lisp_Object CC_girationalizeT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v56, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for girationalize:");
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
    stack[-5] = nil;
    stack[-3] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    v55 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v55; /* !*gcd */
    stack[-1] = stack[-5];
    v55 = stack[-4];
    v55 = qcdr(v55);
    stack[-5] = v55;
    fn = elt(env, 4); /* conjgd */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-6];
    stack[0] = v55;
    if (equal(stack[-1], v55)) goto v59;
    stack[-2] = stack[0];
    v56 = stack[-5];
    v55 = stack[0];
    fn = elt(env, 5); /* addf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-6];
    v55 = stack[-5];
    fn = elt(env, 6); /* negf */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-6];
    fn = elt(env, 5); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v55);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-6];
    v57 = elt(env, 3); /* !:gi!: */
    v56 = (Lisp_Object)1; /* 0 */
    v55 = (Lisp_Object)17; /* 1 */
    v55 = list2star(v57, v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-6];
    fn = elt(env, 7); /* multf */
    v55 = (*qfn2(fn))(qenv(fn), stack[0], v55);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-6];
    fn = elt(env, 8); /* gcdf */
    v56 = (*qfn2(fn))(qenv(fn), stack[-1], v55);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-6];
    v55 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 9); /* quotf */
    v55 = (*qfn2(fn))(qenv(fn), v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-6];
    fn = elt(env, 9); /* quotf */
    v55 = (*qfn2(fn))(qenv(fn), stack[-2], v55);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-6];
    stack[0] = v55;
    v55 = stack[-4];
    v56 = qcar(v55);
    v55 = stack[0];
    fn = elt(env, 7); /* multf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-6];
    v56 = stack[-5];
    v55 = stack[0];
    fn = elt(env, 7); /* multf */
    v55 = (*qfn2(fn))(qenv(fn), v56, v55);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-6];
    fn = elt(env, 10); /* gigcdsq */
    v55 = (*qfn2(fn))(qenv(fn), stack[-1], v55);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-6];
    goto v60;

v60:
    qvalue(elt(env, 1)) = stack[-3]; /* !*gcd */
    { popv(7); return onevalue(v55); }

v59:
    v55 = stack[-4];
    goto v60;
/* error exit handlers */
v58:
    env = stack[-6];
    qvalue(elt(env, 1)) = stack[-3]; /* !*gcd */
    popv(7);
    return nil;
}



/* Code for null!+vec!+p */

static Lisp_Object CC_nullLvecLp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for null+vec+p");
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
    v61 = v0;
/* end of prologue */
    fn = elt(env, 2); /* mk!+squared!+norm */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[0];
    fn = elt(env, 3); /* my!+nullsq!+p */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[0];
    if (v61 == nil) goto v33;
    v61 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v61); }

v33:
    v61 = nil;
    { popv(1); return onevalue(v61); }
/* error exit handlers */
v62:
    popv(1);
    return nil;
}



/* Code for coeffs */

static Lisp_Object CC_coeffs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v74;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeffs");
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
    stack[-2] = nil;
    v73 = stack[-4];
    v73 = qcar(v73);
    v73 = qcar(v73);
    v73 = qcar(v73);
    stack[-1] = v73;
    v73 = stack[-4];
    v73 = qcar(v73);
    v73 = qcar(v73);
    v73 = qcdr(v73);
    stack[-5] = v73;
    goto v75;

v75:
    v73 = stack[-4];
    if (!consp(v73)) goto v76;
    v73 = stack[-4];
    v73 = qcar(v73);
    if (!consp(v73)) goto v76;
    v73 = stack[-4];
    v73 = qcar(v73);
    v73 = qcar(v73);
    v74 = qcar(v73);
    v73 = stack[-1];
    if (!(v74 == v73)) goto v76;
    v73 = stack[-4];
    v73 = qcar(v73);
    v73 = qcar(v73);
    v73 = qcdr(v73);
    stack[-3] = v73;
    v73 = (Lisp_Object)17; /* 1 */
    stack[0] = v73;
    goto v77;

v77:
    v74 = stack[-5];
    v73 = stack[-3];
    v73 = difference2(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-6];
    v74 = sub1(v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-6];
    v73 = stack[0];
    v73 = difference2(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-6];
    v73 = Lminusp(nil, v73);
    env = stack[-6];
    if (v73 == nil) goto v43;
    v73 = stack[-4];
    v73 = qcar(v73);
    v74 = qcdr(v73);
    v73 = stack[-2];
    v73 = cons(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-6];
    stack[-2] = v73;
    v73 = stack[-4];
    v73 = qcdr(v73);
    stack[-4] = v73;
    v73 = stack[-3];
    stack[-5] = v73;
    goto v75;

v43:
    v74 = qvalue(elt(env, 1)); /* nil */
    v73 = stack[-2];
    v73 = cons(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-6];
    stack[-2] = v73;
    v73 = stack[0];
    v73 = add1(v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-6];
    stack[0] = v73;
    goto v77;

v76:
    v73 = (Lisp_Object)17; /* 1 */
    stack[0] = v73;
    goto v58;

v58:
    v73 = stack[-5];
    v74 = sub1(v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-6];
    v73 = stack[0];
    v73 = difference2(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-6];
    v73 = Lminusp(nil, v73);
    env = stack[-6];
    if (v73 == nil) goto v4;
    v74 = stack[-4];
    v73 = stack[-2];
    v73 = cons(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
        popv(7);
        return Lnreverse(nil, v73);

v4:
    v74 = qvalue(elt(env, 1)); /* nil */
    v73 = stack[-2];
    v73 = cons(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-6];
    stack[-2] = v73;
    v73 = stack[0];
    v73 = add1(v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-6];
    stack[0] = v73;
    goto v58;
/* error exit handlers */
v78:
    popv(7);
    return nil;
}



/* Code for bc_quot */

static Lisp_Object CC_bc_quot(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_quot");
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
    v19 = v0;
/* end of prologue */
    v81 = v19;
    v19 = stack[0];
    fn = elt(env, 2); /* qremf */
    v19 = (*qfn2(fn))(qenv(fn), v81, v19);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    v81 = v19;
    v19 = v81;
    v19 = qcdr(v19);
    if (v19 == nil) goto v82;
    v81 = stack[0];
    v19 = elt(env, 1); /* "denominator" */
    {
        popv(2);
        fn = elt(env, 3); /* typerr */
        return (*qfn2(fn))(qenv(fn), v81, v19);
    }

v82:
    v19 = v81;
    v19 = qcar(v19);
    {
        popv(2);
        fn = elt(env, 4); /* bc!=simp */
        return (*qfn1(fn))(qenv(fn), v19);
    }
/* error exit handlers */
v30:
    popv(2);
    return nil;
}



/* Code for sum_prodir */

static Lisp_Object MS_CDECL CC_sum_prodir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v91, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "sum_prodir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sum_prodir");
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
    v91 = qvalue(elt(env, 1)); /* atts */
    v90 = elt(env, 2); /* name */
    fn = elt(env, 5); /* find */
    v90 = (*qfn2(fn))(qenv(fn), v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    v90 = Lintern(nil, v90);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    stack[-2] = v90;
    fn = elt(env, 6); /* lex */
    v90 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    fn = elt(env, 7); /* omobj */
    v90 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    stack[0] = v90;
    v91 = elt(env, 3); /* lowupperlimit */
    v90 = stack[0];
    v90 = qcdr(v90);
    v90 = cons(v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    stack[0] = v90;
    fn = elt(env, 6); /* lex */
    v90 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    fn = elt(env, 7); /* omobj */
    v90 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    stack[-4] = v90;
    v90 = stack[-4];
    fn = elt(env, 8); /* lambdavar */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    stack[-1] = v90;
    v90 = stack[-4];
    fn = elt(env, 9); /* lambdafun */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    stack[-4] = v90;
    v91 = stack[-2];
    v90 = qvalue(elt(env, 4)); /* nil */
    stack[-2] = list2(v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    v31 = stack[0];
    v91 = stack[-4];
    v90 = qvalue(elt(env, 4)); /* nil */
    v90 = list2star(v31, v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    v90 = Lappend(nil, stack[-1], v90);
    nil = C_nil;
    if (exception_pending()) goto v92;
    {
        Lisp_Object v93 = stack[-2];
        popv(6);
        return Lappend(nil, v93, v90);
    }
/* error exit handlers */
v92:
    popv(6);
    return nil;
}



/* Code for listofvarnames */

static Lisp_Object CC_listofvarnames(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listofvarnames");
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
    v109 = stack[0];
    fn = elt(env, 5); /* listp */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    if (v109 == nil) goto v16;
    v109 = stack[0];
    stack[-4] = v109;
    v109 = stack[-4];
    if (v109 == nil) goto v41;
    v109 = stack[-4];
    v109 = qcar(v109);
    stack[0] = v109;
    v109 = stack[0];
    fn = elt(env, 6); /* domain!*p */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    if (v109 == nil) goto v72;
    v110 = qvalue(elt(env, 3)); /* nil */
    v109 = elt(env, 4); /* free */
    v109 = cons(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    goto v112;

v112:
    v109 = ncons(v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    stack[-2] = v109;
    stack[-3] = v109;
    goto v113;

v113:
    v109 = stack[-4];
    v109 = qcdr(v109);
    stack[-4] = v109;
    v109 = stack[-4];
    if (v109 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v109 = stack[-4];
    v109 = qcar(v109);
    stack[0] = v109;
    v109 = stack[0];
    fn = elt(env, 6); /* domain!*p */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    if (v109 == nil) goto v114;
    v110 = qvalue(elt(env, 3)); /* nil */
    v109 = elt(env, 4); /* free */
    v109 = cons(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    goto v2;

v2:
    v109 = ncons(v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    v109 = Lrplacd(nil, stack[-1], v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    v109 = stack[-2];
    v109 = qcdr(v109);
    stack[-2] = v109;
    goto v113;

v114:
    v109 = stack[0];
    if (!consp(v109)) goto v115;
    v109 = stack[0];
    v109 = qcar(v109);
    if (symbolp(v109)) goto v116;
    v109 = stack[0];
    v109 = qcar(v109);
    v109 = qcar(v109);
    if (symbolp(v109)) goto v117;
    v109 = nil;
    goto v2;

v117:
    v109 = stack[0];
    v109 = qcar(v109);
    v110 = qcar(v109);
    v109 = elt(env, 4); /* free */
    v109 = cons(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    goto v2;

v116:
    v109 = stack[0];
    v110 = qcar(v109);
    v109 = elt(env, 4); /* free */
    v109 = cons(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    goto v2;

v115:
    v110 = qvalue(elt(env, 3)); /* nil */
    v109 = elt(env, 4); /* free */
    v109 = cons(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    goto v2;

v72:
    v109 = stack[0];
    if (!consp(v109)) goto v46;
    v109 = stack[0];
    v109 = qcar(v109);
    if (symbolp(v109)) goto v11;
    v109 = stack[0];
    v109 = qcar(v109);
    v109 = qcar(v109);
    if (symbolp(v109)) goto v14;
    v109 = nil;
    goto v112;

v14:
    v109 = stack[0];
    v109 = qcar(v109);
    v110 = qcar(v109);
    v109 = elt(env, 4); /* free */
    v109 = cons(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    goto v112;

v11:
    v109 = stack[0];
    v110 = qcar(v109);
    v109 = elt(env, 4); /* free */
    v109 = cons(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    goto v112;

v46:
    v110 = qvalue(elt(env, 3)); /* nil */
    v109 = elt(env, 4); /* free */
    v109 = cons(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    goto v112;

v41:
    v109 = qvalue(elt(env, 3)); /* nil */
    { popv(6); return onevalue(v109); }

v16:
    v109 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v109 == nil)) goto v80;
    v109 = elt(env, 2); /* "invalid argument to listofvarnames" */
    fn = elt(env, 7); /* lprie */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-5];
    goto v80;

v80:
    v109 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v111;
    v109 = nil;
    { popv(6); return onevalue(v109); }
/* error exit handlers */
v111:
    popv(6);
    return nil;
}



/* Code for mk_parents_prim */

static Lisp_Object CC_mk_parents_prim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_parents_prim");
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
    v112 = stack[0];
    v85 = Llength(nil, v112);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    v112 = (Lisp_Object)49; /* 3 */
    if (!(v85 == v112)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v112 = stack[0];
    fn = elt(env, 1); /* s_noparents */
    v112 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    v85 = v112;
    if (v85 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v85 = stack[0];
    v112 = qcar(v112);
    fn = elt(env, 2); /* mk_edge_parents */
    v112 = (*qfn2(fn))(qenv(fn), v85, v112);
    nil = C_nil;
    if (exception_pending()) goto v44;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v44:
    popv(2);
    return nil;
}



/* Code for dp!=comp */

static Lisp_Object CC_dpMcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=comp");
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
    goto v60;

v60:
    v44 = stack[0];
    if (v44 == nil) goto v26;
    v44 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    fn = elt(env, 2); /* mo_comp */
    v119 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    v44 = stack[-1];
    v44 = Leqn(nil, v119, v44);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    if (v44 == nil) goto v105;
    v44 = stack[0];
    v119 = qcar(v44);
    v44 = stack[-2];
    v44 = cons(v119, v44);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    stack[-2] = v44;
    v44 = stack[0];
    v44 = qcdr(v44);
    stack[0] = v44;
    goto v60;

v105:
    v44 = stack[0];
    v44 = qcdr(v44);
    stack[0] = v44;
    goto v60;

v26:
    v44 = stack[-2];
    {
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v44);
    }
/* error exit handlers */
v87:
    popv(4);
    return nil;
}



/* Code for !*s2i */

static Lisp_Object CC_Hs2i(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *s2i");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v75 = v0;
/* end of prologue */
    v76 = v75;
    v76 = integerp(v76);
    if (!(v76 == nil)) return onevalue(v75);
    v76 = elt(env, 1); /* "integer" */
    {
        fn = elt(env, 2); /* typerr */
        return (*qfn2(fn))(qenv(fn), v75, v76);
    }
}



/* Code for rl_pnf */

static Lisp_Object CC_rl_pnf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_pnf");
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
    v80 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_pnf!* */
    v80 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    {
        Lisp_Object v82 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v82, v80);
    }
/* error exit handlers */
v62:
    popv(2);
    return nil;
}



/* Code for interglue */

static Lisp_Object MS_CDECL CC_interglue(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v38, Lisp_Object v8, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v167, v168;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "interglue");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for interglue");
#endif
    if (stack >= stacklimit)
    {
        push4(v8,v38,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v38,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v8;
    stack[-2] = v38;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v167 = stack[-4];
    if (v167 == nil) goto v169;
    v167 = stack[-3];
    if (v167 == nil) goto v169;
    v167 = stack[-4];
    if (!(!consp(v167))) goto v169;
    v167 = stack[-3];
    if (!(!consp(v167))) goto v169;
    v168 = stack[-4];
    v167 = elt(env, 2); /* class */
    v167 = get(v168, v167);
    env = stack[-6];
    stack[0] = v167;
    v168 = stack[-3];
    v167 = elt(env, 2); /* class */
    v167 = get(v168, v167);
    env = stack[-6];
    v168 = stack[0];
    v167 = get(v168, v167);
    env = stack[-6];
    stack[-5] = v167;
    v167 = stack[-5];
    if (v167 == nil) goto v170;
    v168 = stack[-4];
    v167 = elt(env, 3); /* !\co!  */
    if (v168 == v167) goto v11;
    v168 = stack[-5];
    v167 = (Lisp_Object)1; /* 0 */
    v167 = (Lisp_Object)lessp2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v171;
    v167 = v167 ? lisp_true : nil;
    env = stack[-6];
    if (v167 == nil) goto v172;
    v168 = stack[-2];
    v167 = (Lisp_Object)1; /* 0 */
    v167 = (Lisp_Object)greaterp2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v171;
    v167 = v167 ? lisp_true : nil;
    env = stack[-6];
    if (v167 == nil) goto v55;
    v167 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v167); }

v55:
    v167 = stack[-5];
    v167 = negate(v167);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-6];
    stack[-5] = v167;
    goto v172;

v172:
    v168 = stack[-5];
    v167 = (Lisp_Object)17; /* 1 */
    if (v168 == v167) goto v67;
    v168 = stack[-5];
    v167 = (Lisp_Object)33; /* 2 */
    if (v168 == v167) goto v173;
    v168 = stack[-5];
    v167 = (Lisp_Object)49; /* 3 */
    if (v168 == v167) goto v174;
    v167 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v167); }

v174:
    stack[0] = (Lisp_Object)10485761; /* 655360 */
    v168 = stack[-1];
    v167 = (Lisp_Object)161; /* 10 */
    v168 = times2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-6];
    v167 = (Lisp_Object)801; /* 50 */
    v167 = difference2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v171;
    {
        Lisp_Object v175 = stack[0];
        popv(7);
        return list2(v175, v167);
    }

v173:
    v168 = stack[-4];
    v167 = elt(env, 4); /* !+ */
    if (v168 == v167) goto v176;
    v168 = stack[-4];
    v167 = elt(env, 5); /* !- */
    if (v168 == v167) goto v176;
    v168 = stack[-3];
    v167 = elt(env, 4); /* !+ */
    if (v168 == v167) goto v177;
    v168 = stack[-3];
    v167 = elt(env, 5); /* !- */
    if (!(v168 == v167)) goto v178;
    v168 = stack[0];
    v167 = elt(env, 6); /* ord */
    if (v168 == v167) goto v179;
    v168 = stack[0];
    v167 = elt(env, 7); /* clo */
    if (!(v168 == v167)) goto v178;

v179:
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v168 = stack[-1];
    v167 = (Lisp_Object)481; /* 30 */
    v168 = times2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-6];
    v167 = (Lisp_Object)3361; /* 210 */
    v167 = difference2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v171;
    {
        Lisp_Object v180 = stack[0];
        popv(7);
        return list2(v180, v167);
    }

v178:
    v168 = stack[-4];
    v167 = elt(env, 8); /* !\cdot!  */
    if (v168 == v167) goto v181;
    v168 = stack[-3];
    v167 = elt(env, 8); /* !\cdot!  */
    if (v168 == v167) goto v182;
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v168 = stack[-1];
    v167 = (Lisp_Object)161; /* 10 */
    v167 = times2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v171;
    {
        Lisp_Object v183 = stack[0];
        popv(7);
        return list2(v183, v167);
    }

v182:
    v167 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v167); }

v181:
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v168 = stack[-1];
    v167 = (Lisp_Object)161; /* 10 */
    v168 = times2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-6];
    v167 = (Lisp_Object)801; /* 50 */
    v167 = plus2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v171;
    {
        Lisp_Object v184 = stack[0];
        popv(7);
        return list2(v184, v167);
    }

v177:
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v168 = stack[-1];
    v167 = (Lisp_Object)481; /* 30 */
    v168 = times2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-6];
    v167 = (Lisp_Object)6241; /* 390 */
    v167 = difference2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v171;
    {
        Lisp_Object v185 = stack[0];
        popv(7);
        return list2(v185, v167);
    }

v176:
    v167 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v167); }

v67:
    stack[0] = (Lisp_Object)1295361; /* 80960 */
    v168 = stack[-1];
    v167 = (Lisp_Object)161; /* 10 */
    v168 = times2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-6];
    v167 = (Lisp_Object)321; /* 20 */
    v167 = plus2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v171;
    {
        Lisp_Object v186 = stack[0];
        popv(7);
        return list2(v186, v167);
    }

v11:
    v168 = (Lisp_Object)1; /* 0 */
    v167 = (Lisp_Object)-159999; /* -10000 */
    popv(7);
    return list2(v168, v167);

v170:
    v167 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v167); }

v169:
    v167 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v167); }
/* error exit handlers */
v171:
    popv(7);
    return nil;
}



/* Code for get!*real!*irreducible!*rep */

static Lisp_Object CC_getHrealHirreducibleHrep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*real*irreducible*rep");
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
    v79 = stack[-1];
    stack[-2] = ncons(v79);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-3];
    v19 = elt(env, 1); /* realrep */
    v79 = stack[0];
    fn = elt(env, 2); /* mkid */
    v79 = (*qfn2(fn))(qenv(fn), v19, v79);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-3];
    v79 = get(stack[-1], v79);
    env = stack[-3];
    v79 = qcdr(v79);
    v79 = Lappend(nil, stack[-2], v79);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 3); /* mk_resimp_rep */
        return (*qfn1(fn))(qenv(fn), v79);
    }
/* error exit handlers */
v42:
    popv(4);
    return nil;
}



/* Code for quotf!* */

static Lisp_Object CC_quotfH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v191, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotf*");
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
    v7 = stack[-1];
    if (v7 == nil) goto v33;
    v191 = stack[-1];
    v7 = stack[0];
    fn = elt(env, 9); /* quotf */
    v7 = (*qfn2(fn))(qenv(fn), v191, v7);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    v191 = v7;
    v7 = v191;
    if (!(v7 == nil)) { popv(3); return onevalue(v191); }
    v191 = stack[-1];
    v7 = stack[0];
    v7 = cons(v191, v7);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    fn = elt(env, 10); /* rationalizesq */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    v92 = v7;
    v7 = v92;
    v191 = qcdr(v7);
    v7 = (Lisp_Object)17; /* 1 */
    if (v191 == v7) goto v72;
    v7 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 11); /* terpri!* */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    v7 = elt(env, 3); /* "CATASTROPHIC ERROR *****" */
    fn = elt(env, 12); /* lprie */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    v92 = elt(env, 4); /* "DIVISION FAILED" */
    v191 = stack[-1];
    v7 = stack[0];
    v7 = list3(v92, v191, v7);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    fn = elt(env, 13); /* printty */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    v191 = elt(env, 5); /* " " */
    v7 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 14); /* lpriw */
    v7 = (*qfn2(fn))(qenv(fn), v191, v7);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    v7 = elt(env, 6); /* "Please report output and input listing on the sourceforge bug tracker" 
*/
    v191 = v7;
    v7 = v191;
    qvalue(elt(env, 7)) = v7; /* errmsg!* */
    v7 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v7 == nil)) goto v192;
    v7 = v191;
    fn = elt(env, 12); /* lprie */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-2];
    goto v192;

v192:
    v7 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v7 = nil;
    { popv(3); return onevalue(v7); }

v72:
    v7 = v92;
    v7 = qcar(v7);
    { popv(3); return onevalue(v7); }

v33:
    v7 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v7); }
/* error exit handlers */
v37:
    popv(3);
    return nil;
}



/* Code for iv_cutcongs2 */

static Lisp_Object CC_iv_cutcongs2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v190, v70, v71;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for iv_cutcongs2");
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
    v71 = v0;
/* end of prologue */
    v190 = stack[0];
    v190 = qcar(v190);
    v70 = qcar(v190);
    v190 = elt(env, 1); /* cong */
    if (v70 == v190) goto v40;
    v190 = stack[0];
    v190 = qcdr(v190);
    v70 = v71;
    v70 = difference2(v190, v70);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v190 = stack[0];
    v190 = qcar(v190);
    v190 = qcdr(v190);
    v70 = Cremainder(v70, v190);
    nil = C_nil;
    if (exception_pending()) goto v12;
    v190 = (Lisp_Object)1; /* 0 */
    v190 = (v70 == v190 ? lisp_true : nil);
    v190 = (v190 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v190); }

v40:
    v190 = stack[0];
    v190 = qcdr(v190);
    v70 = v71;
    v70 = difference2(v190, v70);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v190 = stack[0];
    v190 = qcar(v190);
    v190 = qcdr(v190);
    v70 = Cremainder(v70, v190);
    nil = C_nil;
    if (exception_pending()) goto v12;
    v190 = (Lisp_Object)1; /* 0 */
    v190 = (v70 == v190 ? lisp_true : nil);
    { popv(2); return onevalue(v190); }
/* error exit handlers */
v12:
    popv(2);
    return nil;
}



/* Code for tendstoml */

static Lisp_Object CC_tendstoml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tendstoml");
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
    v79 = elt(env, 1); /* "<apply><tendsto" */
    fn = elt(env, 6); /* printout */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v79 = stack[0];
    v19 = qcar(v79);
    v79 = elt(env, 2); /* "/" */
    fn = elt(env, 7); /* attributesml */
    v79 = (*qfn2(fn))(qenv(fn), v19, v79);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v79 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 8); /* indent!* */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v79 = stack[0];
    v79 = qcdr(v79);
    v79 = qcar(v79);
    fn = elt(env, 9); /* expression */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v79 = stack[0];
    v79 = qcdr(v79);
    v79 = qcdr(v79);
    v79 = qcar(v79);
    fn = elt(env, 9); /* expression */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v79 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 8); /* indent!* */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v79 = elt(env, 5); /* "</apply>" */
    fn = elt(env, 6); /* printout */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v118;
    v79 = nil;
    { popv(2); return onevalue(v79); }
/* error exit handlers */
v118:
    popv(2);
    return nil;
}



/* Code for poch!*sub!*1 */

static Lisp_Object MS_CDECL CC_pochHsubH1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "poch*sub*1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for poch*sub*1");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v38;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v61:
    v45 = stack[-1];
    v52 = (Lisp_Object)1; /* 0 */
    if (v45 == v52) goto v75;
    v45 = stack[-2];
    v52 = qvalue(elt(env, 1)); /* bfone!* */
    fn = elt(env, 2); /* plus!: */
    v52 = (*qfn2(fn))(qenv(fn), v45, v52);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    stack[-3] = v52;
    v52 = stack[-1];
    v52 = sub1(v52);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    stack[-1] = v52;
    v45 = stack[0];
    v52 = stack[-2];
    fn = elt(env, 3); /* csl_timbf */
    v52 = (*qfn2(fn))(qenv(fn), v45, v52);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    stack[0] = v52;
    v52 = stack[-3];
    stack[-2] = v52;
    goto v61;

v75:
    v45 = stack[0];
    v52 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* csl_timbf */
        return (*qfn2(fn))(qenv(fn), v45, v52);
    }
/* error exit handlers */
v86:
    popv(5);
    return nil;
}



/* Code for look_for_rational */

static Lisp_Object MS_CDECL CC_look_for_rational(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v66, v197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "look_for_rational");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for look_for_rational");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v38;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v114 = stack[0];
    v66 = qcar(v114);
    v114 = elt(env, 1); /* sqrt */
    if (!(v66 == v114)) goto v44;
    v114 = stack[0];
    v114 = qcdr(v114);
    v66 = qcar(v114);
    v114 = stack[-1];
    if (!(equal(v66, v114))) goto v44;
    v197 = stack[-2];
    v66 = stack[-1];
    v114 = (Lisp_Object)33; /* 2 */
    {
        popv(4);
        fn = elt(env, 5); /* look_for_rational1 */
        return (*qfnn(fn))(qenv(fn), 3, v197, v66, v114);
    }

v44:
    v114 = stack[0];
    v66 = qcar(v114);
    v114 = elt(env, 2); /* expt */
    if (!(v66 == v114)) goto v96;
    v114 = stack[0];
    v114 = qcdr(v114);
    v66 = qcar(v114);
    v114 = stack[-1];
    if (!(equal(v66, v114))) goto v96;
    v114 = stack[0];
    v114 = qcdr(v114);
    v114 = qcdr(v114);
    v114 = qcar(v114);
    fn = elt(env, 6); /* listp */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-3];
    if (v114 == nil) goto v96;
    v114 = stack[0];
    v114 = qcdr(v114);
    v114 = qcdr(v114);
    v114 = qcar(v114);
    v66 = qcar(v114);
    v114 = elt(env, 3); /* quotient */
    if (!(v66 == v114)) goto v96;
    v114 = stack[0];
    v114 = qcdr(v114);
    v114 = qcdr(v114);
    v114 = qcar(v114);
    v114 = qcdr(v114);
    v114 = qcar(v114);
    if (!(is_number(v114))) goto v96;
    v114 = stack[0];
    v114 = qcdr(v114);
    v114 = qcdr(v114);
    v114 = qcar(v114);
    v114 = qcdr(v114);
    v114 = qcdr(v114);
    v114 = qcar(v114);
    if (!(is_number(v114))) goto v96;
    v197 = stack[-2];
    v66 = stack[-1];
    v114 = stack[0];
    v114 = qcdr(v114);
    v114 = qcdr(v114);
    v114 = qcar(v114);
    v114 = qcdr(v114);
    v114 = qcdr(v114);
    v114 = qcar(v114);
    {
        popv(4);
        fn = elt(env, 5); /* look_for_rational1 */
        return (*qfnn(fn))(qenv(fn), 3, v197, v66, v114);
    }

v96:
    v114 = qvalue(elt(env, 4)); /* nil */
    { popv(4); return onevalue(v114); }
/* error exit handlers */
v4:
    popv(4);
    return nil;
}



/* Code for rm_neg_pow */

static Lisp_Object CC_rm_neg_pow(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v66;
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
    v114 = stack[-1];
    if (!consp(v114)) goto v61;
    v114 = stack[-1];
    v114 = qcar(v114);
    if (!consp(v114)) goto v61;
    v114 = stack[-1];
    v114 = qcar(v114);
    v114 = qcar(v114);
    v114 = qcdr(v114);
    v114 = Lminusp(nil, v114);
    env = stack[-3];
    if (v114 == nil) goto v92;
    stack[-2] = (Lisp_Object)17; /* 1 */
    v114 = stack[-1];
    v114 = qcar(v114);
    v114 = qcar(v114);
    stack[0] = qcar(v114);
    v114 = stack[-1];
    v114 = qcar(v114);
    v114 = qcar(v114);
    v114 = qcdr(v114);
    v66 = negate(v114);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-3];
    v114 = (Lisp_Object)17; /* 1 */
    v66 = acons(stack[0], v66, v114);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-3];
    v114 = qvalue(elt(env, 1)); /* nil */
    stack[0] = list2star(stack[-2], v66, v114);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-3];
    v114 = stack[-1];
    v114 = qcar(v114);
    v114 = qcdr(v114);
    v114 = CC_rm_neg_pow(env, v114);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-3];
    fn = elt(env, 2); /* multsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v114);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-3];
    v114 = stack[-1];
    v114 = qcdr(v114);
    v114 = CC_rm_neg_pow(env, v114);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-3];
    {
        Lisp_Object v4 = stack[0];
        popv(4);
        fn = elt(env, 3); /* addsq */
        return (*qfn2(fn))(qenv(fn), v4, v114);
    }

v92:
    v114 = stack[-1];
    v114 = qcar(v114);
    v66 = qcar(v114);
    v114 = (Lisp_Object)17; /* 1 */
    v114 = cons(v66, v114);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-3];
    v66 = ncons(v114);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-3];
    v114 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v66, v114);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-3];
    v114 = stack[-1];
    v114 = qcar(v114);
    v114 = qcdr(v114);
    v114 = CC_rm_neg_pow(env, v114);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-3];
    fn = elt(env, 2); /* multsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v114);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-3];
    v114 = stack[-1];
    v114 = qcdr(v114);
    v114 = CC_rm_neg_pow(env, v114);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-3];
    {
        Lisp_Object v5 = stack[0];
        popv(4);
        fn = elt(env, 3); /* addsq */
        return (*qfn2(fn))(qenv(fn), v5, v114);
    }

v61:
    v66 = stack[-1];
    v114 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v66, v114);
/* error exit handlers */
v200:
    popv(4);
    return nil;
}



/* Code for vevzero!?1 */

static Lisp_Object CC_vevzeroW1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v45, v108;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevzero?1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v45 = v0;
/* end of prologue */

v25:
    v52 = v45;
    v52 = (v52 == nil ? lisp_true : nil);
    if (!(v52 == nil)) return onevalue(v52);
    v52 = v45;
    v108 = qcar(v52);
    v52 = (Lisp_Object)1; /* 0 */
    if (v108 == v52) goto v75;
    v52 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v52);

v75:
    v52 = v45;
    v52 = qcdr(v52);
    v52 = (v52 == nil ? lisp_true : nil);
    if (!(v52 == nil)) return onevalue(v52);
    v52 = v45;
    v52 = qcdr(v52);
    v108 = qcar(v52);
    v52 = (Lisp_Object)1; /* 0 */
    if (v108 == v52) goto v119;
    v52 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v52);

v119:
    v52 = v45;
    v52 = qcdr(v52);
    v52 = qcdr(v52);
    v45 = v52;
    goto v25;
}



/* Code for xriterion_2 */

static Lisp_Object MS_CDECL CC_xriterion_2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v201, v116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xriterion_2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xriterion_2");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v38;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v25:
    v74 = stack[-1];
    if (v74 == nil) goto v60;
    v74 = stack[-2];
    v74 = qcdr(v74);
    v201 = qcar(v74);
    v74 = elt(env, 2); /* wedge_pair */
    if (v201 == v74) goto v103;
    v74 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v74); }

v103:
    v74 = stack[-1];
    v74 = qcar(v74);
    stack[-3] = v74;
    v116 = stack[-3];
    v201 = (Lisp_Object)17; /* 1 */
    v74 = (Lisp_Object)17; /* 1 */
    v74 = list2star(v116, v201, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v201 = ncons(v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v74 = stack[-2];
    v74 = qcdr(v74);
    v74 = qcdr(v74);
    v74 = qcar(v74);
    if (equal(v201, v74)) goto v81;
    v201 = stack[-3];
    v74 = stack[-3];
    v201 = list2(v201, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v74 = stack[-2];
    v74 = qcar(v74);
    fn = elt(env, 7); /* xdiv */
    v74 = (*qfn2(fn))(qenv(fn), v201, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    if (v74 == nil) goto v32;
    v201 = stack[-3];
    v74 = stack[-2];
    v74 = qcdr(v74);
    v74 = qcdr(v74);
    v74 = qcdr(v74);
    v74 = qcar(v74);
    fn = elt(env, 8); /* make_wedge_pair */
    v74 = (*qfn2(fn))(qenv(fn), v201, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v201 = v74;
    v74 = v201;
    v74 = (v74 == nil ? lisp_true : nil);
    if (!(v74 == nil)) goto v35;
    v74 = stack[0];
    fn = elt(env, 9); /* find_item */
    v74 = (*qfn2(fn))(qenv(fn), v201, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v74 = (v74 == nil ? lisp_true : nil);
    goto v35;

v35:
    if (v74 == nil) goto v43;
    v74 = qvalue(elt(env, 3)); /* !*trxideal */
    if (v74 == nil) goto v58;
    v74 = elt(env, 4); /* "criterion 2 hit" */
    fn = elt(env, 10); /* eval */
    v116 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v201 = qvalue(elt(env, 1)); /* nil */
    v74 = elt(env, 5); /* last */
    fn = elt(env, 11); /* assgnpri */
    v74 = (*qfnn(fn))(qenv(fn), 3, v116, v201, v74);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    goto v58;

v58:
    v74 = qvalue(elt(env, 6)); /* t */
    goto v19;

v19:
    if (!(v74 == nil)) { popv(5); return onevalue(v74); }
    v116 = stack[-2];
    v74 = stack[-1];
    v201 = qcdr(v74);
    v74 = stack[0];
    stack[-2] = v116;
    stack[-1] = v201;
    stack[0] = v74;
    goto v25;

v43:
    v74 = qvalue(elt(env, 1)); /* nil */
    goto v19;

v32:
    v74 = qvalue(elt(env, 1)); /* nil */
    goto v19;

v81:
    v74 = qvalue(elt(env, 1)); /* nil */
    goto v19;

v60:
    v74 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v74); }
/* error exit handlers */
v78:
    popv(5);
    return nil;
}



/* Code for r2flbf */

static Lisp_Object CC_r2flbf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2flbf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v82 = v0;
/* end of prologue */
    v62 = qvalue(elt(env, 1)); /* !*bftag */
    if (v62 == nil) goto v26;
    v62 = v82;
    {
        fn = elt(env, 2); /* r2bf */
        return (*qfn1(fn))(qenv(fn), v62);
    }

v26:
    v62 = v82;
    {
        fn = elt(env, 3); /* r2fl */
        return (*qfn1(fn))(qenv(fn), v62);
    }
}



/* Code for !*ex2sf */

static Lisp_Object CC_Hex2sf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v195, v199;
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
    goto v33;

v33:
    v195 = stack[-1];
    if (v195 == nil) goto v120;
    v195 = stack[-1];
    v195 = qcar(v195);
    v195 = qcar(v195);
    v195 = qcar(v195);
    if (v195 == nil) goto v75;
    v195 = stack[-1];
    v195 = qcar(v195);
    v195 = qcar(v195);
    v199 = qcar(v195);
    v195 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v199, v195);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    v195 = stack[-1];
    v195 = qcar(v195);
    v195 = qcdr(v195);
    fn = elt(env, 1); /* subs2chk */
    v199 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    v195 = stack[-2];
    v195 = acons(stack[0], v199, v195);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    stack[-2] = v195;
    v195 = stack[-1];
    v195 = qcdr(v195);
    stack[-1] = v195;
    goto v33;

v75:
    stack[0] = stack[-2];
    v195 = stack[-1];
    v195 = qcar(v195);
    v195 = qcdr(v195);
    fn = elt(env, 1); /* subs2chk */
    v195 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    {
        Lisp_Object v47 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v47, v195);
    }

v120:
    v195 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v195);
    }
/* error exit handlers */
v69:
    popv(4);
    return nil;
}



/* Code for lf!=zero */

static Lisp_Object CC_lfMzero(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lf=zero");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v33 = v0;
/* end of prologue */
    v33 = qcdr(v33);
    v33 = (v33 == nil ? lisp_true : nil);
    return onevalue(v33);
}



/* Code for !*n2a */

static Lisp_Object CC_Hn2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *n2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v28 = v0;
/* end of prologue */
    v103 = v28;
    v103 = integerp(v103);
    if (!(v103 == nil)) return onevalue(v28);
    v103 = qvalue(elt(env, 1)); /* !*nosq */
    if (v103 == nil) goto v62;
    v103 = v28;
    {
        fn = elt(env, 2); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v103);
    }

v62:
    v103 = v28;
    {
        fn = elt(env, 3); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v103);
    }
}



/* Code for mk_rep_mat */

static Lisp_Object CC_mk_rep_mat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_rep_mat");
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
    stack[0] = v0;
/* end of prologue */
    v202 = stack[-1];
    v202 = qcar(v202);
    v202 = qcdr(v202);
    v202 = qcar(v202);
    fn = elt(env, 2); /* get!+row!+nr */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-3];
    fn = elt(env, 3); /* mk!+unit!+mat */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-3];
    v9 = v202;
    v202 = stack[0];
    stack[-2] = v202;
    goto v27;

v27:
    v202 = stack[-2];
    if (v202 == nil) { popv(4); return onevalue(v9); }
    v202 = stack[-2];
    v202 = qcar(v202);
    stack[0] = v9;
    v9 = v202;
    v202 = stack[-1];
    fn = elt(env, 4); /* get_rep_of_generator */
    v202 = (*qfn2(fn))(qenv(fn), v9, v202);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-3];
    fn = elt(env, 5); /* mk!+mat!+mult!+mat */
    v202 = (*qfn2(fn))(qenv(fn), stack[0], v202);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-3];
    v9 = v202;
    v202 = stack[-2];
    v202 = qcdr(v202);
    stack[-2] = v202;
    goto v27;
/* error exit handlers */
v45:
    popv(4);
    return nil;
}



/* Code for freeof!-dfl */

static Lisp_Object CC_freeofKdfl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeof-dfl");
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

v33:
    v81 = stack[-1];
    if (v81 == nil) goto v120;
    v81 = stack[-1];
    v118 = qcar(v81);
    v81 = stack[0];
    fn = elt(env, 3); /* freeof!-df */
    v81 = (*qfn2(fn))(qenv(fn), v118, v81);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-2];
    if (v81 == nil) goto v41;
    v81 = stack[-1];
    v81 = qcdr(v81);
    stack[-1] = v81;
    goto v33;

v41:
    v81 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v81); }

v120:
    v81 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v81); }
/* error exit handlers */
v106:
    popv(3);
    return nil;
}



/* Code for aex_add */

static Lisp_Object CC_aex_add(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_add");
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
    v9 = stack[-3];
    fn = elt(env, 2); /* aex_ex */
    stack[0] = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v9 = stack[-2];
    fn = elt(env, 2); /* aex_ex */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    fn = elt(env, 3); /* ratpoly_add */
    stack[-4] = (*qfn2(fn))(qenv(fn), stack[0], v9);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v9 = stack[-3];
    fn = elt(env, 4); /* aex_ctx */
    stack[0] = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    v9 = stack[-2];
    fn = elt(env, 4); /* aex_ctx */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    fn = elt(env, 5); /* ctx_union */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v9);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v9 = stack[-3];
    fn = elt(env, 6); /* aex_reducedtag */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    if (v9 == nil) goto v106;
    v9 = stack[-2];
    fn = elt(env, 6); /* aex_reducedtag */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-5];
    goto v80;

v80:
    {
        Lisp_Object v17 = stack[-4];
        Lisp_Object v18 = stack[-1];
        Lisp_Object v86 = stack[0];
        popv(6);
        fn = elt(env, 7); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v17, v18, v86, v9);
    }

v106:
    v9 = qvalue(elt(env, 1)); /* nil */
    goto v80;
/* error exit handlers */
v170:
    popv(6);
    return nil;
}



/* Code for lowlimitrd */

static Lisp_Object MS_CDECL CC_lowlimitrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v41;
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
    v40 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    stack[0] = v40;
    fn = elt(env, 5); /* lex */
    v40 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v41 = qvalue(elt(env, 1)); /* char */
    v40 = elt(env, 2); /* (!/ l o w l i m i t) */
    if (equal(v41, v40)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v41 = elt(env, 3); /* "</lowlimit>" */
    v40 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 6); /* errorml */
    v40 = (*qfn2(fn))(qenv(fn), v41, v40);
    nil = C_nil;
    if (exception_pending()) goto v19;
    v40 = nil;
    { popv(2); return onevalue(v40); }
/* error exit handlers */
v19:
    popv(2);
    return nil;
}



/* Code for column_dim */

static Lisp_Object CC_column_dim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187;
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
    v187 = qvalue(elt(env, 1)); /* !*fast_la */
    if (!(v187 == nil)) goto v33;
    v187 = stack[0];
    fn = elt(env, 4); /* matrixp */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    if (!(v187 == nil)) goto v33;
    v187 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v187 == nil)) goto v196;
    v187 = elt(env, 3); /* "Error in column_dim: input should be a matrix." 
*/
    fn = elt(env, 5); /* lprie */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    goto v196;

v196:
    v187 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    goto v33;

v33:
    v187 = stack[0];
    fn = elt(env, 6); /* size_of_matrix */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v41;
    v187 = qcdr(v187);
    v187 = qcar(v187);
    { popv(2); return onevalue(v187); }
/* error exit handlers */
v41:
    popv(2);
    return nil;
}



/* Code for xpndwedge */

static Lisp_Object CC_xpndwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v45;
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
    goto v60;

v60:
    v52 = stack[0];
    v52 = qcdr(v52);
    if (v52 == nil) goto v169;
    v52 = stack[0];
    v52 = qcar(v52);
    fn = elt(env, 1); /* partitop */
    v45 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    v52 = stack[-1];
    v52 = cons(v45, v52);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    stack[-1] = v52;
    v52 = stack[0];
    v52 = qcdr(v52);
    stack[0] = v52;
    goto v60;

v169:
    v52 = stack[0];
    v52 = qcar(v52);
    fn = elt(env, 1); /* partitop */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    fn = elt(env, 2); /* mkunarywedge */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    v45 = v52;
    goto v120;

v120:
    v52 = stack[-1];
    if (v52 == nil) { popv(3); return onevalue(v45); }
    v52 = stack[-1];
    v52 = qcar(v52);
    fn = elt(env, 3); /* wedgepf2 */
    v52 = (*qfn2(fn))(qenv(fn), v52, v45);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    v45 = v52;
    v52 = stack[-1];
    v52 = qcdr(v52);
    stack[-1] = v52;
    goto v120;
/* error exit handlers */
v17:
    popv(3);
    return nil;
}



/* Code for !:quotient */

static Lisp_Object CC_Tquotient(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v203, v172, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :quotient");
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
    v172 = v1;
    stack[0] = v0;
/* end of prologue */
    v203 = stack[0];
    if (v203 == nil) goto v33;
    v58 = stack[0];
    v203 = (Lisp_Object)1; /* 0 */
    if (v58 == v203) goto v33;
    v203 = v172;
    if (v203 == nil) goto v53;
    v58 = v172;
    v203 = (Lisp_Object)1; /* 0 */
    if (v58 == v203) goto v53;
    v203 = stack[0];
    if (!(!consp(v203))) goto v93;
    v203 = v172;
    if (!(!consp(v203))) goto v93;
    v203 = qvalue(elt(env, 5)); /* dmode!* */
    if (v203 == nil) goto v46;
    v203 = v172;
    fn = elt(env, 8); /* !:recip */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-1];
    v172 = v203;
    if (!consp(v172)) goto v12;
    v58 = stack[0];
    v172 = v203;
    v203 = elt(env, 6); /* times */
    {
        popv(2);
        fn = elt(env, 9); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v58, v172, v203);
    }

v12:
    v172 = stack[0];
    popv(2);
    return times2(v172, v203);

v46:
    v203 = stack[0];
    popv(2);
    return quot2(v203, v172);

v93:
    v58 = stack[0];
    v203 = elt(env, 7); /* quotient */
    {
        popv(2);
        fn = elt(env, 9); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v58, v172, v203);
    }

v53:
    v203 = elt(env, 2); /* "Zero divisor" */
    v172 = v203;
    v203 = v172;
    qvalue(elt(env, 3)) = v203; /* errmsg!* */
    v203 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v203 == nil)) goto v106;
    v203 = v172;
    fn = elt(env, 10); /* lprie */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-1];
    goto v106;

v106:
    v203 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v2;
    v203 = nil;
    { popv(2); return onevalue(v203); }

v33:
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v203); }
/* error exit handlers */
v2:
    popv(2);
    return nil;
}



/* Code for s_actual_world1 */

static Lisp_Object CC_s_actual_world1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v60;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for s_actual_world1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v60 = v0;
/* end of prologue */
    v60 = qcar(v60);
    v60 = qcar(v60);
    v60 = qcar(v60);
    return onevalue(v60);
}



/* Code for !*sf2ex */

static Lisp_Object CC_Hsf2ex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v12, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *sf2ex");
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
    goto v60;

v60:
    v48 = stack[-1];
    if (v48 == nil) goto v26;
    v48 = stack[-1];
    if (!consp(v48)) goto v42;
    v48 = stack[-1];
    v48 = qcar(v48);
    if (!consp(v48)) goto v42;
    v48 = stack[-1];
    v48 = qcar(v48);
    v48 = qcar(v48);
    v12 = qcar(v48);
    v48 = stack[0];
    v48 = Lmemq(nil, v12, v48);
    if (v48 == nil) goto v42;
    v48 = stack[-1];
    v48 = qcar(v48);
    v48 = qcar(v48);
    v48 = qcar(v48);
    v13 = ncons(v48);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-3];
    v48 = stack[-1];
    v48 = qcar(v48);
    v12 = qcdr(v48);
    v48 = stack[-2];
    v48 = acons(v13, v12, v48);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-3];
    stack[-2] = v48;
    v48 = stack[-1];
    v48 = qcdr(v48);
    stack[-1] = v48;
    goto v60;

v42:
    stack[0] = stack[-2];
    v48 = qvalue(elt(env, 1)); /* nil */
    v12 = ncons(v48);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-3];
    v48 = stack[-1];
    v48 = cons(v12, v48);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-3];
    v48 = ncons(v48);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-3];
    {
        Lisp_Object v189 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v189, v48);
    }

v26:
    v48 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v48);
    }
/* error exit handlers */
v188:
    popv(4);
    return nil;
}



/* Code for get!-current!-representation */

static Lisp_Object CC_getKcurrentKrepresentation(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v80;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-current-representation");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v59 = v0;
/* end of prologue */
    v80 = elt(env, 1); /* currep */
    return get(v59, v80);
}



/* Code for ofsf_smmkatl!-and */

static Lisp_Object MS_CDECL CC_ofsf_smmkatlKand(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v209, v210, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_smmkatl-and");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smmkatl-and");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v38;
    v209 = v1;
    stack[-4] = v0;
/* end of prologue */
    v210 = qvalue(elt(env, 1)); /* !*rlsipw */
    if (!(v210 == nil)) goto v120;
    v210 = qvalue(elt(env, 2)); /* !*rlsipo */
    if (v210 == nil) goto v120;
    v173 = elt(env, 3); /* and */
    v210 = v209;
    v209 = stack[-3];
    {
        popv(7);
        fn = elt(env, 5); /* ofsf_irl2atl */
        return (*qfnn(fn))(qenv(fn), 3, v173, v210, v209);
    }

v120:
    stack[-5] = v209;
    goto v19;

v19:
    v209 = stack[-5];
    if (v209 == nil) goto v106;
    v209 = stack[-5];
    v209 = qcar(v209);
    v210 = v209;
    v173 = qcar(v210);
    v210 = stack[-4];
    v210 = Latsoc(nil, v173, v210);
    v173 = v210;
    v210 = v173;
    if (v210 == nil) goto v195;
    v210 = v209;
    v209 = stack[-3];
    fn = elt(env, 6); /* ofsf_smmkatl!-and1 */
    v209 = (*qfnn(fn))(qenv(fn), 3, v173, v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-6];
    goto v18;

v18:
    stack[-2] = v209;
    v209 = stack[-2];
    fn = elt(env, 7); /* lastpair */
    v209 = (*qfn1(fn))(qenv(fn), v209);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-6];
    stack[-1] = v209;
    v209 = stack[-5];
    v209 = qcdr(v209);
    stack[-5] = v209;
    v209 = stack[-1];
    if (!consp(v209)) goto v19;
    else goto v81;

v81:
    v209 = stack[-5];
    if (v209 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v209 = stack[-5];
    v209 = qcar(v209);
    v210 = v209;
    v173 = qcar(v210);
    v210 = stack[-4];
    v210 = Latsoc(nil, v173, v210);
    v173 = v210;
    v210 = v173;
    if (v210 == nil) goto v22;
    v210 = v209;
    v209 = stack[-3];
    fn = elt(env, 6); /* ofsf_smmkatl!-and1 */
    v209 = (*qfnn(fn))(qenv(fn), 3, v173, v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-6];
    goto v56;

v56:
    v209 = Lrplacd(nil, stack[0], v209);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-6];
    v209 = stack[-1];
    fn = elt(env, 7); /* lastpair */
    v209 = (*qfn1(fn))(qenv(fn), v209);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-6];
    stack[-1] = v209;
    v209 = stack[-5];
    v209 = qcdr(v209);
    stack[-5] = v209;
    goto v81;

v22:
    v173 = elt(env, 3); /* and */
    v210 = v209;
    v209 = stack[-3];
    fn = elt(env, 8); /* ofsf_ir2atl */
    v209 = (*qfnn(fn))(qenv(fn), 3, v173, v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-6];
    goto v56;

v195:
    v210 = elt(env, 3); /* and */
    v173 = v209;
    v209 = stack[-3];
    fn = elt(env, 8); /* ofsf_ir2atl */
    v209 = (*qfnn(fn))(qenv(fn), 3, v210, v173, v209);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-6];
    goto v18;

v106:
    v209 = qvalue(elt(env, 4)); /* nil */
    { popv(7); return onevalue(v209); }
/* error exit handlers */
v211:
    popv(7);
    return nil;
}



/* Code for replace!-nth */

static Lisp_Object MS_CDECL CC_replaceKnth(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "replace-nth");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replace-nth");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v38;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v61;

v61:
    v170 = stack[-1];
    v108 = (Lisp_Object)17; /* 1 */
    if (v170 == v108) goto v75;
    v108 = stack[-2];
    v170 = qcar(v108);
    v108 = stack[-3];
    v108 = cons(v170, v108);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    stack[-3] = v108;
    v108 = stack[-2];
    v108 = qcdr(v108);
    stack[-2] = v108;
    v108 = stack[-1];
    v108 = sub1(v108);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    stack[-1] = v108;
    goto v61;

v75:
    stack[-1] = stack[-3];
    v170 = stack[0];
    v108 = stack[-2];
    v108 = qcdr(v108);
    v108 = cons(v170, v108);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    {
        Lisp_Object v194 = stack[-1];
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v194, v108);
    }
/* error exit handlers */
v32:
    popv(5);
    return nil;
}



/* Code for freeof!-df */

static Lisp_Object CC_freeofKdf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v195, v199;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeof-df");
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
    v195 = stack[-1];
    if (!consp(v195)) goto v33;
    v195 = stack[-1];
    v199 = qcar(v195);
    v195 = elt(env, 2); /* df */
    if (v199 == v195) goto v88;
    v195 = stack[-1];
    v199 = qcdr(v195);
    v195 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* freeof!-dfl */
        return (*qfn2(fn))(qenv(fn), v199, v195);
    }

v88:
    v195 = stack[-1];
    v195 = qcdr(v195);
    v199 = qcar(v195);
    v195 = stack[0];
    v195 = CC_freeofKdf(env, v199, v195);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    if (v195 == nil) goto v104;
    v199 = stack[0];
    v195 = stack[-1];
    v195 = qcdr(v195);
    v195 = qcdr(v195);
    fn = elt(env, 5); /* smember */
    v195 = (*qfn2(fn))(qenv(fn), v199, v195);
    nil = C_nil;
    if (exception_pending()) goto v50;
    v195 = (v195 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v195); }

v104:
    v195 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v195); }

v33:
    v195 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v195); }
/* error exit handlers */
v50:
    popv(3);
    return nil;
}



/* Code for cl_applysac2 */

static Lisp_Object MS_CDECL CC_cl_applysac2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v213, v214, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_applysac2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_applysac2");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v38;
    v214 = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    v213 = v214;
    if (v213 == nil) goto v27;
    v213 = v214;
    stack[0] = v213;
    goto v113;

v113:
    v213 = stack[0];
    if (v213 == nil) goto v88;
    v97 = stack[-2];
    v213 = stack[0];
    v214 = qcar(v213);
    v213 = stack[-1];
    fn = elt(env, 7); /* cl_subandcut */
    v214 = (*qfnn(fn))(qenv(fn), 3, v97, v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-4];
    stack[-3] = v214;
    v213 = elt(env, 2); /* keep1 */
    if (!(v214 == v213)) goto v88;
    v213 = stack[0];
    v213 = qcdr(v213);
    stack[0] = v213;
    goto v113;

v88:
    v213 = stack[-3];
    if (v213 == nil) goto v32;
    v213 = stack[0];
    if (v213 == nil) goto v11;
    v214 = stack[-3];
    v213 = elt(env, 5); /* keep2 */
    if (v214 == v213) goto v192;
    v214 = stack[-3];
    v213 = elt(env, 6); /* failed */
    if (v214 == v213) goto v200;
    v97 = qvalue(elt(env, 3)); /* nil */
    v214 = stack[-3];
    v213 = stack[0];
    v213 = qcdr(v213);
    popv(5);
    return acons(v97, v214, v213);

v200:
    v97 = stack[-2];
    v213 = stack[0];
    v214 = qcdr(v213);
    v213 = stack[-1];
    v213 = CC_cl_applysac2(env, 3, v97, v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-4];
    stack[-3] = v213;
    v214 = stack[-3];
    v213 = elt(env, 4); /* break */
    if (v214 == v213) goto v207;
    v214 = stack[0];
    v213 = stack[-3];
    v213 = qcdr(v213);
    fn = elt(env, 8); /* setcdr */
    v213 = (*qfn2(fn))(qenv(fn), v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v110;
    v213 = stack[-3];
    v214 = qcar(v213);
    v213 = stack[0];
    popv(5);
    return cons(v214, v213);

v207:
    v213 = elt(env, 4); /* break */
    { popv(5); return onevalue(v213); }

v192:
    v214 = qvalue(elt(env, 3)); /* nil */
    v213 = stack[0];
    popv(5);
    return cons(v214, v213);

v11:
    v214 = qvalue(elt(env, 1)); /* t */
    v213 = stack[-2];
    v213 = cons(v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v110;
    popv(5);
    return ncons(v213);

v32:
    v213 = elt(env, 4); /* break */
    { popv(5); return onevalue(v213); }

v27:
    v214 = qvalue(elt(env, 1)); /* t */
    v213 = stack[-2];
    v213 = cons(v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v110;
    popv(5);
    return ncons(v213);
/* error exit handlers */
v110:
    popv(5);
    return nil;
}



/* Code for seprd */

static Lisp_Object MS_CDECL CC_seprd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v19;
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
    v19 = qvalue(elt(env, 2)); /* char */
    v79 = elt(env, 3); /* (s e p !/) */
    if (equal(v19, v79)) goto v120;
    v19 = elt(env, 4); /* "<sep/>" */
    v79 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 5); /* errorml */
    v79 = (*qfn2(fn))(qenv(fn), v19, v79);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[0];
    goto v120;

v120:
    fn = elt(env, 6); /* lex */
    v79 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[0];
    v79 = qvalue(elt(env, 2)); /* char */
        popv(1);
        return Lcompress(nil, v79);
/* error exit handlers */
v81:
    popv(1);
    return nil;
}



/* Code for search4facf */

static Lisp_Object MS_CDECL CC_search4facf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "search4facf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for search4facf");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v38;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v107 = stack[-3];
    if (v107 == nil) goto v59;
    v107 = stack[-3];
    v107 = qcar(v107);
    stack[-5] = v107;
    goto v28;

v28:
    v107 = stack[-5];
    if (v107 == nil) goto v40;
    stack[-1] = stack[-4];
    v107 = stack[-3];
    stack[0] = qcdr(v107);
    v107 = stack[-5];
    v49 = qcar(v107);
    v107 = stack[-2];
    v107 = cons(v49, v107);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-6];
    v107 = CC_search4facf(env, 3, stack[-1], stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-6];
    v49 = v107;
    v107 = v49;
    if (!(v107 == nil)) { popv(7); return onevalue(v49); }
    v107 = stack[-5];
    v107 = qcdr(v107);
    stack[-5] = v107;
    goto v28;

v40:
    v107 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v107); }

v59:
    v49 = stack[-4];
    v107 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* tryfactorf */
        return (*qfn2(fn))(qenv(fn), v49, v107);
    }
/* error exit handlers */
v204:
    popv(7);
    return nil;
}



/* Code for getvariables */

static Lisp_Object CC_getvariables(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v75;
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
    v75 = v0;
/* end of prologue */
    v76 = v75;
    stack[0] = qcar(v76);
    v76 = v75;
    v75 = qcdr(v76);
    v76 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* varsinsf */
    v76 = (*qfn2(fn))(qenv(fn), v75, v76);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    {
        Lisp_Object v28 = stack[0];
        popv(2);
        fn = elt(env, 2); /* varsinsf */
        return (*qfn2(fn))(qenv(fn), v28, v76);
    }
/* error exit handlers */
v103:
    popv(2);
    return nil;
}



/* Code for codfac */

static Lisp_Object MS_CDECL CC_codfac(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v176, v209;
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
    v176 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v176;
    goto v196;

v196:
    v209 = (Lisp_Object)-15; /* -1 */
    v176 = stack[-1];
    v176 = difference2(v209, v176);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-3];
    v176 = Lminusp(nil, v176);
    env = stack[-3];
    if (!(v176 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v209 = qvalue(elt(env, 4)); /* maxvar */
    v176 = stack[-1];
    v176 = plus2(v209, v176);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-3];
    v209 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v176/(16/CELL)));
    v176 = (Lisp_Object)49; /* 3 */
    v209 = *(Lisp_Object *)((char *)v209 + (CELL-TAG_VECTOR) + ((int32_t)v176/(16/CELL)));
    v176 = (Lisp_Object)-15; /* -1 */
    if (v209 == v176) goto v113;
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v209 = qvalue(elt(env, 4)); /* maxvar */
    v176 = stack[-1];
    v176 = plus2(v209, v176);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-3];
    v209 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v176/(16/CELL)));
    v176 = (Lisp_Object)49; /* 3 */
    v209 = *(Lisp_Object *)((char *)v209 + (CELL-TAG_VECTOR) + ((int32_t)v176/(16/CELL)));
    v176 = (Lisp_Object)-31; /* -2 */
    if (v209 == v176) goto v113;
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v209 = qvalue(elt(env, 4)); /* maxvar */
    v176 = stack[-1];
    v176 = plus2(v209, v176);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-3];
    v209 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v176/(16/CELL)));
    v176 = (Lisp_Object)33; /* 2 */
    v209 = *(Lisp_Object *)((char *)v209 + (CELL-TAG_VECTOR) + ((int32_t)v176/(16/CELL)));
    v176 = elt(env, 5); /* times */
    if (!(v209 == v176)) goto v113;
    v176 = stack[-1];
    fn = elt(env, 7); /* samefar */
    v176 = (*qfn1(fn))(qenv(fn), v176);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-3];
    v209 = v176;
    if (v176 == nil) goto v113;
    v176 = qvalue(elt(env, 6)); /* t */
    stack[-2] = v176;
    v176 = v209;
    stack[0] = v176;
    goto v24;

v24:
    v176 = stack[0];
    if (v176 == nil) goto v113;
    v176 = stack[0];
    v176 = qcar(v176);
    v209 = stack[-1];
    fn = elt(env, 8); /* commonfac */
    v176 = (*qfn2(fn))(qenv(fn), v209, v176);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-3];
    v176 = stack[0];
    v176 = qcdr(v176);
    stack[0] = v176;
    goto v24;

v113:
    v176 = stack[-1];
    v176 = add1(v176);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-3];
    stack[-1] = v176;
    goto v196;
/* error exit handlers */
v217:
    popv(4);
    return nil;
}



/* Code for let3 */

static Lisp_Object MS_CDECL CC_let3(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v38, Lisp_Object v8,
                         Lisp_Object v16, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v243, v244, v245, v246, v247, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "let3");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for let3");
#endif
    if (stack >= stacklimit)
    {
        push5(v16,v8,v38,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v38,v8,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v16;
    stack[-2] = v8;
    stack[-3] = v38;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v243 = stack[-5];
    stack[-6] = v243;
    v243 = stack[-6];
    if (v243 == nil) goto v27;
    v243 = stack[-6];
    if (is_number(v243)) goto v72;
    v243 = stack[-4];
    fn = elt(env, 12); /* getrtype */
    v243 = (*qfn1(fn))(qenv(fn), v243);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-7];
    stack[0] = v243;
    v243 = stack[-2];
    if (v243 == nil) goto v199;
    v243 = stack[-6];
    if (!(symbolp(v243))) goto v199;
    v244 = stack[-6];
    v243 = elt(env, 5); /* rtype */
    v243 = Lremprop(nil, v244, v243);
    env = stack[-7];
    v244 = stack[-6];
    v243 = elt(env, 6); /* avalue */
    v243 = Lremprop(nil, v244, v243);
    env = stack[-7];
    goto v199;

v199:
    v243 = stack[-6];
    fn = elt(env, 12); /* getrtype */
    v243 = (*qfn1(fn))(qenv(fn), v243);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-7];
    v244 = v243;
    if (v243 == nil) goto v84;
    v245 = v244;
    v243 = elt(env, 7); /* typeletfn */
    v243 = get(v245, v243);
    env = stack[-7];
    v245 = v243;
    if (v243 == nil) goto v214;
    v243 = v245;
    if (!consp(v243)) goto v208;
    v243 = elt(env, 8); /* "Apply called with non-id arg" */
    v244 = v245;
    v243 = list2(v243, v244);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-7];
    v244 = v243;
    v243 = v244;
    qvalue(elt(env, 9)) = v243; /* errmsg!* */
    v243 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v243 == nil)) goto v4;
    v243 = v244;
    fn = elt(env, 13); /* lprie */
    v243 = (*qfn1(fn))(qenv(fn), v243);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-7];
    goto v4;

v4:
    v243 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v132;
    v243 = nil;
    { popv(8); return onevalue(v243); }

v208:
    stack[-3] = v245;
    stack[-5] = stack[-6];
    stack[-1] = stack[-4];
    stack[0] = v244;
    v243 = stack[-4];
    fn = elt(env, 12); /* getrtype */
    v243 = (*qfn1(fn))(qenv(fn), v243);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-7];
    v243 = list2(stack[-2], v243);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-7];
    v243 = list3star(stack[-5], stack[-1], stack[0], v243);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-7];
    {
        Lisp_Object v248 = stack[-3];
        popv(8);
        fn = elt(env, 14); /* apply */
        return (*qfn2(fn))(qenv(fn), v248, v243);
    }

v214:
    stack[-3] = stack[-6];
    stack[-1] = stack[-4];
    stack[0] = v244;
    v243 = stack[-4];
    fn = elt(env, 12); /* getrtype */
    v243 = (*qfn1(fn))(qenv(fn), v243);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-7];
    {
        Lisp_Object v249 = stack[-3];
        Lisp_Object v250 = stack[-1];
        Lisp_Object v251 = stack[0];
        Lisp_Object v252 = stack[-2];
        popv(8);
        fn = elt(env, 15); /* typelet */
        return (*qfnn(fn))(qenv(fn), 5, v249, v250, v251, v252, v243);
    }

v84:
    v243 = stack[0];
    if (v243 == nil) goto v253;
    v244 = stack[0];
    v243 = elt(env, 11); /* yetunknowntype */
    if (v244 == v243) goto v253;
    v244 = stack[0];
    v243 = elt(env, 7); /* typeletfn */
    v243 = get(v244, v243);
    env = stack[-7];
    v245 = v243;
    if (v243 == nil) goto v254;
    v243 = v245;
    if (!consp(v243)) goto v255;
    v243 = elt(env, 8); /* "Apply called with non-id arg" */
    v244 = v245;
    v243 = list2(v243, v244);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-7];
    v244 = v243;
    v243 = v244;
    qvalue(elt(env, 9)) = v243; /* errmsg!* */
    v243 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v243 == nil)) goto v152;
    v243 = v244;
    fn = elt(env, 13); /* lprie */
    v243 = (*qfn1(fn))(qenv(fn), v243);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-7];
    goto v152;

v152:
    v243 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v132;
    v243 = nil;
    { popv(8); return onevalue(v243); }

v255:
    stack[-3] = v245;
    stack[-5] = stack[-6];
    stack[-1] = qvalue(elt(env, 3)); /* nil */
    v244 = stack[-2];
    v243 = stack[0];
    v243 = list2(v244, v243);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-7];
    v243 = list3star(stack[-5], stack[-4], stack[-1], v243);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-7];
    {
        Lisp_Object v256 = stack[-3];
        popv(8);
        fn = elt(env, 14); /* apply */
        return (*qfn2(fn))(qenv(fn), v256, v243);
    }

v254:
    v247 = stack[-6];
    v246 = stack[-4];
    v245 = qvalue(elt(env, 3)); /* nil */
    v244 = stack[-2];
    v243 = stack[0];
    {
        popv(8);
        fn = elt(env, 15); /* typelet */
        return (*qfnn(fn))(qenv(fn), 5, v247, v246, v245, v244, v243);
    }

v253:
    v130 = stack[-5];
    v247 = stack[-4];
    v246 = stack[-3];
    v245 = stack[-6];
    v244 = stack[-2];
    v243 = stack[-1];
    fn = elt(env, 16); /* letscalar */
    v243 = (*qfnn(fn))(qenv(fn), 6, v130, v247, v246, v245, v244, v243);
    nil = C_nil;
    if (exception_pending()) goto v132;
    v243 = nil;
    { popv(8); return onevalue(v243); }

v72:
    v247 = elt(env, 1); /* "Substitution for" */
    v246 = stack[-5];
    v245 = elt(env, 2); /* "not allowed" */
    v244 = qvalue(elt(env, 3)); /* nil */
    v243 = qvalue(elt(env, 4)); /* t */
    {
        popv(8);
        fn = elt(env, 17); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v247, v246, v245, v244, v243);
    }

v27:
    v243 = (Lisp_Object)1; /* 0 */
    stack[-5] = v243;
    v247 = elt(env, 1); /* "Substitution for" */
    v246 = stack[-5];
    v245 = elt(env, 2); /* "not allowed" */
    v244 = qvalue(elt(env, 3)); /* nil */
    v243 = qvalue(elt(env, 4)); /* t */
    {
        popv(8);
        fn = elt(env, 17); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v247, v246, v245, v244, v243);
    }
/* error exit handlers */
v132:
    popv(8);
    return nil;
}



/* Code for tot!-asym!-indp */

static Lisp_Object CC_totKasymKindp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v43;
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

v25:
    v13 = stack[0];
    v13 = (v13 == nil ? lisp_true : nil);
    if (!(v13 == nil)) { popv(2); return onevalue(v13); }
    v13 = stack[0];
    v13 = qcdr(v13);
    v13 = (v13 == nil ? lisp_true : nil);
    if (!(v13 == nil)) { popv(2); return onevalue(v13); }
    v13 = stack[0];
    v43 = qcar(v13);
    v13 = stack[0];
    v13 = qcdr(v13);
    v13 = qcar(v13);
    if (equal(v43, v13)) goto v62;
    v13 = stack[0];
    v13 = qcar(v13);
    if (!consp(v13)) goto v30;
    v13 = stack[0];
    v13 = qcar(v13);
    fn = elt(env, 2); /* indxchk */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-1];
    if (!(v13 == nil)) goto v40;
    v13 = stack[0];
    v13 = qcdr(v13);
    v13 = qcar(v13);
    fn = elt(env, 2); /* indxchk */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-1];
    if (!(v13 == nil)) goto v40;
    v13 = stack[0];
    v43 = qcar(v13);
    v13 = stack[0];
    v13 = qcdr(v13);
    v13 = qcar(v13);
    fn = elt(env, 3); /* indordlp */
    v13 = (*qfn2(fn))(qenv(fn), v43, v13);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-1];
    goto v40;

v40:
    if (v13 == nil) goto v62;
    v13 = stack[0];
    v13 = qcdr(v13);
    stack[0] = v13;
    goto v25;

v62:
    v13 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v13); }

v30:
    v13 = stack[0];
    v43 = qcar(v13);
    v13 = stack[0];
    v13 = qcdr(v13);
    v13 = qcar(v13);
    fn = elt(env, 4); /* indordp */
    v13 = (*qfn2(fn))(qenv(fn), v43, v13);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-1];
    goto v40;
/* error exit handlers */
v257:
    popv(2);
    return nil;
}



/* Code for kernelp */

static Lisp_Object CC_kernelp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v85;
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
    v112 = stack[0];
    if (v112 == nil) goto v16;
    v112 = stack[0];
    fn = elt(env, 4); /* domain!*p */
    v112 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    if (!(v112 == nil)) goto v16;
    v112 = stack[0];
    if (symbolp(v112)) goto v61;
    v112 = stack[0];
    fn = elt(env, 5); /* listp */
    v112 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    if (v112 == nil) goto v42;
    v112 = stack[0];
    v112 = qcar(v112);
    if (!(symbolp(v112))) goto v42;
    v112 = stack[0];
    v85 = qcar(v112);
    v112 = elt(env, 3); /* (!*sq set setq plus minus difference times quotient) 
*/
    v112 = Lmemq(nil, v85, v112);
    if (!(v112 == nil)) goto v42;
    v112 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v112); }

v42:
    v112 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v112); }

v61:
    v112 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v112); }

v16:
    v112 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v112); }
/* error exit handlers */
v44:
    popv(2);
    return nil;
}



/* Code for find_triangles1 */

static Lisp_Object CC_find_triangles1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v79, v19, v81, v118, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_triangles1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v41 = v1;
    v79 = v0;
/* end of prologue */
    v30 = qvalue(elt(env, 1)); /* nil */
    v19 = v79;
    v118 = qcar(v19);
    v81 = qvalue(elt(env, 1)); /* nil */
    v19 = v79;
    v19 = qcdr(v19);
    v19 = qcar(v19);
    v79 = qcdr(v79);
    v79 = qcdr(v79);
    v79 = qcar(v79);
    {
        fn = elt(env, 2); /* select_triangles */
        return (*qfnn(fn))(qenv(fn), 6, v30, v118, v81, v19, v79, v41);
    }
}



/* Code for rfirst */

static Lisp_Object CC_rfirst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204, v190, v70, v71, v48;
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
    v204 = stack[0];
    v204 = qcar(v204);
    stack[0] = v204;
    v204 = stack[0];
    fn = elt(env, 6); /* listeval0 */
    v190 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-2];
    stack[-1] = v190;
    v204 = elt(env, 1); /* list */
    if (!consp(v190)) goto v28;
    v190 = qcar(v190);
    if (!(v190 == v204)) goto v28;

v120:
    v204 = stack[-1];
    v204 = qcdr(v204);
    if (v204 == nil) goto v87;
    v204 = stack[-1];
    v204 = qcdr(v204);
    v204 = qcar(v204);
    {
        popv(3);
        fn = elt(env, 7); /* reval */
        return (*qfn1(fn))(qenv(fn), v204);
    }

v87:
    v48 = elt(env, 3); /* "Expression" */
    v71 = stack[0];
    v70 = elt(env, 4); /* "does not have part" */
    v190 = (Lisp_Object)17; /* 1 */
    v204 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 8); /* msgpri */
    v204 = (*qfnn(fn))(qenv(fn), 5, v48, v71, v70, v190, v204);
    nil = C_nil;
    if (exception_pending()) goto v43;
    v204 = nil;
    { popv(3); return onevalue(v204); }

v28:
    v204 = stack[0];
    fn = elt(env, 9); /* aeval */
    v190 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-2];
    stack[-1] = v190;
    v204 = elt(env, 1); /* list */
    if (!consp(v190)) goto v81;
    v190 = qcar(v190);
    if (v190 == v204) goto v120;
    else goto v81;

v81:
    v190 = stack[0];
    v204 = elt(env, 2); /* "list" */
    fn = elt(env, 10); /* typerr */
    v204 = (*qfn2(fn))(qenv(fn), v190, v204);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-2];
    goto v120;
/* error exit handlers */
v43:
    popv(3);
    return nil;
}



/* Code for prepcadr */

static Lisp_Object CC_prepcadr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepcadr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v88 = v0;
/* end of prologue */
    v28 = v88;
    v28 = qcdr(v28);
    v28 = qcar(v28);
    v28 = qcar(v28);
    if (v28 == nil) goto v16;
    v28 = v88;
    v28 = qcdr(v28);
    v88 = qcar(v28);
    v28 = elt(env, 1); /* prepf */
    {
        fn = elt(env, 2); /* sqform */
        return (*qfn2(fn))(qenv(fn), v88, v28);
    }

v16:
    v28 = (Lisp_Object)1; /* 0 */
    return onevalue(v28);
}



/* Code for dummy_nam */

static Lisp_Object CC_dummy_nam(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v62;
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
    v61 = v0;
/* end of prologue */
    fn = elt(env, 4); /* ordn */
    v62 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[0];
    v61 = elt(env, 1); /* symbolic */
    fn = elt(env, 5); /* list2vect!* */
    v61 = (*qfn2(fn))(qenv(fn), v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[0];
    qvalue(elt(env, 2)) = v61; /* g_dvnames */
    v61 = qvalue(elt(env, 3)); /* t */
    { popv(1); return onevalue(v61); }
/* error exit handlers */
v82:
    popv(1);
    return nil;
}



/* Code for makeupsf */

static Lisp_Object MS_CDECL CC_makeupsf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v162, v161, v258, v177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "makeupsf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makeupsf");
#endif
    if (stack >= stacklimit)
    {
        push3(v38,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v38;
    stack[-1] = v1;
    v177 = v0;
/* end of prologue */
    v162 = v177;
    v162 = qcar(v162);
    if (!consp(v162)) goto v30;
    v162 = v177;
    v161 = qcdr(v162);
    v162 = (Lisp_Object)17; /* 1 */
    if (v161 == v162) goto v30;
    v162 = v177;
    v162 = qcar(v162);
    v161 = qcar(v162);
    v162 = elt(env, 1); /* sqrt */
    if (v161 == v162) goto v49;
    v162 = v177;
    v162 = qcar(v162);
    v258 = v162;
    v162 = v258;
    v161 = qcar(v162);
    v162 = elt(env, 2); /* expt */
    if (v161 == v162) goto v34;
    v162 = qvalue(elt(env, 3)); /* nil */
    goto v188;

v188:
    if (v162 == nil) goto v259;
    v162 = v177;
    v161 = qcar(v162);
    v162 = stack[-1];
    v258 = v177;
    v258 = qcdr(v258);
    fn = elt(env, 5); /* !*multfexpt */
    v161 = (*qfnn(fn))(qenv(fn), 3, v161, v162, v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-2];
    v162 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* addf */
        return (*qfn2(fn))(qenv(fn), v161, v162);
    }

v259:
    v161 = v177;
    v162 = (Lisp_Object)17; /* 1 */
    v162 = cons(v161, v162);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-2];
    v161 = ncons(v162);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-2];
    v162 = stack[-1];
    fn = elt(env, 7); /* multf */
    v161 = (*qfn2(fn))(qenv(fn), v161, v162);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-2];
    v162 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* addf */
        return (*qfn2(fn))(qenv(fn), v161, v162);
    }

v34:
    v162 = v258;
    v162 = qcdr(v162);
    v162 = qcdr(v162);
    v162 = qcar(v162);
    v258 = v162;
    v162 = v258;
    if (!consp(v162)) goto v56;
    v162 = v258;
    v161 = qcar(v162);
    v162 = elt(env, 4); /* quotient */
    if (v161 == v162) goto v172;
    v162 = qvalue(elt(env, 3)); /* nil */
    goto v188;

v172:
    v162 = v258;
    v162 = qcdr(v162);
    v162 = qcar(v162);
    if (is_number(v162)) goto v24;
    v162 = qvalue(elt(env, 3)); /* nil */
    goto v188;

v24:
    v162 = v258;
    v162 = qcdr(v162);
    v162 = qcdr(v162);
    v162 = qcar(v162);
    v162 = (is_number(v162) ? lisp_true : nil);
    goto v188;

v56:
    v162 = qvalue(elt(env, 3)); /* nil */
    goto v188;

v49:
    v162 = v177;
    v161 = qcar(v162);
    v162 = stack[-1];
    v258 = v177;
    v258 = qcdr(v258);
    fn = elt(env, 8); /* !*multfsqrt */
    v161 = (*qfnn(fn))(qenv(fn), 3, v161, v162, v258);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-2];
    v162 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* addf */
        return (*qfn2(fn))(qenv(fn), v161, v162);
    }

v30:
    v161 = v177;
    v162 = (Lisp_Object)17; /* 1 */
    v162 = cons(v161, v162);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-2];
    v161 = ncons(v162);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-2];
    v162 = stack[-1];
    fn = elt(env, 7); /* multf */
    v161 = (*qfn2(fn))(qenv(fn), v161, v162);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-2];
    v162 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* addf */
        return (*qfn2(fn))(qenv(fn), v161, v162);
    }
/* error exit handlers */
v260:
    popv(3);
    return nil;
}



/* Code for bf2rn1 */

static Lisp_Object CC_bf2rn1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v252, v256, v277, v127;
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
    v252 = stack[-9];
    v252 = qcdr(v252);
    v256 = qcar(v252);
    v252 = (Lisp_Object)1; /* 0 */
    v252 = (Lisp_Object)lessp2(v256, v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    v252 = v252 ? lisp_true : nil;
    env = stack[-11];
    if (v252 == nil) goto v54;
    v252 = qvalue(elt(env, 1)); /* t */
    stack[-10] = v252;
    stack[-1] = elt(env, 2); /* !:rd!: */
    v252 = stack[-9];
    v252 = qcdr(v252);
    v252 = qcar(v252);
    v256 = negate(v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    v252 = stack[-9];
    v252 = qcdr(v252);
    v252 = qcdr(v252);
    v252 = list2star(stack[-1], v256, v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    stack[-9] = v252;
    goto v54;

v54:
    v252 = stack[-9];
    stack[-3] = v252;
    goto v27;

v27:
    v252 = stack[-9];
    v252 = qcdr(v252);
    v256 = qcar(v252);
    v252 = stack[-9];
    v252 = qcdr(v252);
    v252 = qcdr(v252);
    v127 = v256;
    v277 = v252;
    v256 = v277;
    v252 = (Lisp_Object)1; /* 0 */
    if (v256 == v252) goto v195;
    v252 = v127;
    v256 = v277;
    v252 = ash(v252, v256);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    goto v194;

v194:
    stack[-1] = v252;
    v277 = elt(env, 2); /* !:rd!: */
    v256 = stack[-1];
    v252 = (Lisp_Object)1; /* 0 */
    v252 = list2star(v277, v256, v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    fn = elt(env, 5); /* csl_normbf */
    v252 = (*qfn1(fn))(qenv(fn), v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    fn = elt(env, 6); /* difbf */
    v252 = (*qfn2(fn))(qenv(fn), stack[-9], v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    stack[-9] = v252;
    v252 = stack[-4];
    if (v252 == nil) goto v55;
    stack[-2] = stack[-8];
    v256 = stack[-1];
    v252 = stack[-7];
    v252 = times2(v256, v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    v252 = plus2(stack[-2], v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    v256 = v252;
    v252 = stack[-7];
    stack[-8] = v252;
    v252 = v256;
    stack[-7] = v252;
    v252 = stack[0];
    stack[-2] = v252;
    stack[0] = stack[-6];
    v256 = stack[-1];
    v252 = stack[-5];
    v252 = times2(v256, v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    v252 = plus2(stack[0], v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    v256 = v252;
    v252 = stack[-5];
    stack[-6] = v252;
    v252 = v256;
    stack[-5] = v252;
    goto v99;

v99:
    stack[-1] = stack[-3];
    v277 = elt(env, 2); /* !:rd!: */
    v256 = stack[-7];
    v252 = (Lisp_Object)1; /* 0 */
    stack[0] = list2star(v277, v256, v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    v277 = elt(env, 2); /* !:rd!: */
    v256 = stack[-5];
    v252 = (Lisp_Object)1; /* 0 */
    v256 = list2star(v277, v256, v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    v252 = qvalue(elt(env, 3)); /* !:bprec!: */
    fn = elt(env, 7); /* divide!: */
    v252 = (*qfnn(fn))(qenv(fn), 3, stack[0], v256, v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    fn = elt(env, 5); /* csl_normbf */
    v252 = (*qfn1(fn))(qenv(fn), v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    fn = elt(env, 6); /* difbf */
    v252 = (*qfn2(fn))(qenv(fn), stack[-1], v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    stack[-1] = v252;
    v252 = stack[-1];
    v252 = qcdr(v252);
    v256 = qcar(v252);
    v252 = (Lisp_Object)1; /* 0 */
    v252 = (Lisp_Object)greaterp2(v256, v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    v252 = v252 ? lisp_true : nil;
    env = stack[-11];
    if (v252 == nil) goto v279;
    v252 = stack[-1];
    goto v280;

v280:
    stack[0] = v252;
    v252 = stack[-9];
    v252 = qcdr(v252);
    v256 = qcar(v252);
    v252 = (Lisp_Object)1; /* 0 */
    if (v256 == v252) goto v151;
    v252 = stack[0];
    v252 = qcdr(v252);
    v256 = qcar(v252);
    v252 = (Lisp_Object)1; /* 0 */
    if (v256 == v252) goto v151;
    v252 = stack[-2];
    if (v252 == nil) goto v281;
    v256 = stack[-2];
    v252 = stack[0];
    fn = elt(env, 8); /* greaterp!: */
    v252 = (*qfn2(fn))(qenv(fn), v256, v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    if (!(v252 == nil)) goto v281;
    v252 = stack[-10];
    if (v252 == nil) goto v219;
    v252 = stack[-8];
    v256 = negate(v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    v252 = stack[-6];
    popv(12);
    return cons(v256, v252);

v219:
    v256 = stack[-8];
    v252 = stack[-6];
    popv(12);
    return cons(v256, v252);

v281:
    v277 = qvalue(elt(env, 4)); /* bfone!* */
    v256 = stack[-9];
    v252 = qvalue(elt(env, 3)); /* !:bprec!: */
    fn = elt(env, 7); /* divide!: */
    v252 = (*qfnn(fn))(qenv(fn), 3, v277, v256, v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    fn = elt(env, 5); /* csl_normbf */
    v252 = (*qfn1(fn))(qenv(fn), v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    stack[-9] = v252;
    goto v27;

v151:
    v252 = stack[-10];
    if (v252 == nil) goto v254;
    v252 = stack[-7];
    v256 = negate(v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    v252 = stack[-5];
    popv(12);
    return cons(v256, v252);

v254:
    v256 = stack[-7];
    v252 = stack[-5];
    popv(12);
    return cons(v256, v252);

v279:
    stack[0] = elt(env, 2); /* !:rd!: */
    v252 = stack[-1];
    v252 = qcdr(v252);
    v252 = qcar(v252);
    v256 = negate(v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    v252 = stack[-1];
    v252 = qcdr(v252);
    v252 = qcdr(v252);
    v252 = list2star(stack[0], v256, v252);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-11];
    goto v280;

v55:
    v252 = qvalue(elt(env, 1)); /* t */
    stack[-4] = v252;
    v252 = (Lisp_Object)17; /* 1 */
    stack[-8] = v252;
    v252 = stack[-1];
    stack[-7] = v252;
    v252 = (Lisp_Object)1; /* 0 */
    stack[-6] = v252;
    v252 = (Lisp_Object)17; /* 1 */
    stack[-5] = v252;
    goto v99;

v195:
    v252 = v127;
    goto v194;
/* error exit handlers */
v278:
    popv(12);
    return nil;
}



/* Code for even_action */

static Lisp_Object CC_even_action(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v46, v32, v194;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for even_action");
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
    v46 = qvalue(elt(env, 1)); /* nil */
    v86 = (Lisp_Object)17; /* 1 */
    v86 = cons(v46, v86);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    v46 = v86;
    v86 = stack[0];
    stack[-2] = v86;
    goto v54;

v54:
    v86 = stack[-2];
    if (v86 == nil) { popv(4); return onevalue(v46); }
    v86 = stack[-2];
    v86 = qcar(v86);
    stack[0] = v46;
    v194 = stack[-1];
    v46 = v86;
    v32 = qcdr(v46);
    v46 = qcar(v86);
    v86 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 2); /* even_action_sf */
    v86 = (*qfnn(fn))(qenv(fn), 4, v194, v32, v46, v86);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    fn = elt(env, 3); /* addsq */
    v86 = (*qfn2(fn))(qenv(fn), stack[0], v86);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    v46 = v86;
    v86 = stack[-2];
    v86 = qcdr(v86);
    stack[-2] = v86;
    goto v54;
/* error exit handlers */
v49:
    popv(4);
    return nil;
}



/* Code for cl_pop */

static Lisp_Object CC_cl_pop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v8;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_pop");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    return onevalue(v8);
}



/* Code for get_mat */

static Lisp_Object CC_get_mat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_mat");
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
    stack[0] = nil;
    v192 = stack[-2];
    v84 = elt(env, 1); /* id */
    if (v192 == v84) goto v26;
    v84 = qvalue(elt(env, 2)); /* nil */
    stack[-3] = v84;
    goto v30;

v30:
    v84 = stack[-1];
    v192 = Llength(nil, v84);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    v84 = (Lisp_Object)1; /* 0 */
    v84 = (Lisp_Object)greaterp2(v192, v84);
    nil = C_nil;
    if (exception_pending()) goto v35;
    v84 = v84 ? lisp_true : nil;
    env = stack[-4];
    if (v84 == nil) goto v89;
    v84 = stack[-3];
    if (!(v84 == nil)) goto v89;
    v192 = stack[-2];
    v84 = stack[-1];
    v84 = qcar(v84);
    v84 = qcar(v84);
    if (!(equal(v192, v84))) goto v87;
    v84 = stack[-1];
    v84 = qcar(v84);
    v84 = qcdr(v84);
    v84 = qcar(v84);
    stack[0] = v84;
    v84 = qvalue(elt(env, 3)); /* t */
    stack[-3] = v84;
    goto v87;

v87:
    v84 = stack[-1];
    v84 = qcdr(v84);
    stack[-1] = v84;
    goto v30;

v89:
    v84 = stack[-3];
    if (!(v84 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v84 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v84 == nil)) goto v188;
    v84 = elt(env, 5); /* "error in get_mat" */
    fn = elt(env, 6); /* lprie */
    v84 = (*qfn1(fn))(qenv(fn), v84);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    goto v188;

v188:
    v84 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v35;
    v84 = nil;
    { popv(5); return onevalue(v84); }

v26:
    v84 = stack[-1];
    v84 = qcar(v84);
    v84 = qcdr(v84);
    v84 = qcar(v84);
    fn = elt(env, 7); /* get!+row!+nr */
    v84 = (*qfn1(fn))(qenv(fn), v84);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 8); /* mk!+unit!+mat */
        return (*qfn1(fn))(qenv(fn), v84);
    }
/* error exit handlers */
v35:
    popv(5);
    return nil;
}



/* Code for nonpolyp */

static Lisp_Object CC_nonpolyp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonpolyp");
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

v25:
    v10 = stack[-1];
    if (!consp(v10)) goto v33;
    v10 = stack[-1];
    v10 = qcar(v10);
    if (!consp(v10)) goto v33;
    v10 = stack[-1];
    v10 = qcar(v10);
    v10 = qcar(v10);
    v11 = qcar(v10);
    v10 = stack[0];
    if (v11 == v10) goto v75;
    v10 = stack[-1];
    v10 = qcar(v10);
    v10 = qcar(v10);
    v11 = qcar(v10);
    v10 = stack[0];
    fn = elt(env, 2); /* depend!-p */
    v10 = (*qfn2(fn))(qenv(fn), v11, v10);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-2];
    goto v76;

v76:
    if (!(v10 == nil)) { popv(3); return onevalue(v10); }
    v10 = stack[-1];
    v10 = qcar(v10);
    v11 = qcdr(v10);
    v10 = stack[0];
    v10 = CC_nonpolyp(env, v11, v10);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-2];
    if (!(v10 == nil)) { popv(3); return onevalue(v10); }
    v10 = stack[-1];
    v11 = qcdr(v10);
    v10 = stack[0];
    stack[-1] = v11;
    stack[0] = v10;
    goto v25;

v75:
    v10 = qvalue(elt(env, 1)); /* nil */
    goto v76;

v33:
    v10 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v10); }
/* error exit handlers */
v70:
    popv(3);
    return nil;
}



/* Code for limitrd */

static Lisp_Object MS_CDECL CC_limitrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v275, v274, v238, v111;
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
    v275 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-4];
    v274 = qvalue(elt(env, 1)); /* char */
    v275 = elt(env, 2); /* (b v a r) */
    if (equal(v274, v275)) goto v59;
    v275 = qvalue(elt(env, 4)); /* nil */
    stack[-3] = v275;
    goto v86;

v86:
    v274 = qvalue(elt(env, 1)); /* char */
    v275 = elt(env, 5); /* (l o w l i m i t) */
    if (equal(v274, v275)) goto v17;
    v274 = qvalue(elt(env, 1)); /* char */
    v275 = elt(env, 6); /* (c o n d i t i o n) */
    if (equal(v274, v275)) goto v69;
    v275 = qvalue(elt(env, 4)); /* nil */
    stack[-2] = v275;
    goto v170;

v170:
    fn = elt(env, 14); /* mathml2 */
    v275 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-4];
    stack[0] = v275;
    fn = elt(env, 13); /* lex */
    v275 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-4];
    v275 = stack[-2];
    if (v275 == nil) goto v94;
    v275 = stack[-1];
    if (v275 == nil) goto v212;
    v275 = nil;
    { popv(5); return onevalue(v275); }

v212:
    v275 = stack[-2];
    v274 = qcar(v275);
    v275 = elt(env, 10); /* (a b o v e) */
    if (equal(v274, v275)) goto v64;
    v111 = stack[0];
    v238 = stack[-3];
    v275 = stack[-2];
    v275 = qcdr(v275);
    v274 = qcar(v275);
    v275 = elt(env, 12); /* min */
    {
        popv(5);
        fn = elt(env, 15); /* alg_limit */
        return (*qfnn(fn))(qenv(fn), 4, v111, v238, v274, v275);
    }

v64:
    v111 = stack[0];
    v238 = stack[-3];
    v275 = stack[-2];
    v275 = qcdr(v275);
    v274 = qcar(v275);
    v275 = elt(env, 11); /* plus */
    {
        popv(5);
        fn = elt(env, 15); /* alg_limit */
        return (*qfnn(fn))(qenv(fn), 4, v111, v238, v274, v275);
    }

v94:
    v111 = stack[0];
    v238 = stack[-3];
    v274 = stack[-1];
    v275 = elt(env, 9); /* norm */
    {
        popv(5);
        fn = elt(env, 15); /* alg_limit */
        return (*qfnn(fn))(qenv(fn), 4, v111, v238, v274, v275);
    }

v69:
    fn = elt(env, 16); /* conditionrd */
    v275 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-4];
    stack[-2] = v275;
    v274 = qvalue(elt(env, 1)); /* char */
    v275 = elt(env, 7); /* (!/ c o n d i t i o n) */
    if (equal(v274, v275)) goto v13;
    v274 = elt(env, 8); /* "</condition>" */
    v275 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 17); /* errorml */
    v275 = (*qfn2(fn))(qenv(fn), v274, v275);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-4];
    goto v13;

v13:
    fn = elt(env, 13); /* lex */
    v275 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-4];
    goto v170;

v17:
    fn = elt(env, 18); /* lowlimitrd */
    v275 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-4];
    stack[-1] = v275;
    fn = elt(env, 13); /* lex */
    v275 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-4];
    goto v170;

v59:
    fn = elt(env, 19); /* bvarrd */
    v275 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-4];
    stack[-3] = v275;
    v275 = stack[-3];
    v275 = qcdr(v275);
    v274 = qcar(v275);
    v275 = (Lisp_Object)17; /* 1 */
    v275 = Leqn(nil, v274, v275);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-4];
    if (v275 == nil) goto v85;
    v275 = stack[-3];
    v275 = qcar(v275);
    stack[-3] = v275;
    goto v104;

v104:
    fn = elt(env, 13); /* lex */
    v275 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-4];
    goto v86;

v85:
    v274 = elt(env, 3); /* "<degree>" */
    v275 = (Lisp_Object)129; /* 8 */
    fn = elt(env, 17); /* errorml */
    v275 = (*qfn2(fn))(qenv(fn), v274, v275);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-4];
    goto v104;
/* error exit handlers */
v161:
    popv(5);
    return nil;
}



setup_type const u46_setup[] =
{
    {"lto_almerge",             too_few_2,      CC_lto_almerge,wrong_no_2},
    {"girationalize:",          CC_girationalizeT,too_many_1,  wrong_no_1},
    {"null+vec+p",              CC_nullLvecLp,  too_many_1,    wrong_no_1},
    {"coeffs",                  CC_coeffs,      too_many_1,    wrong_no_1},
    {"bc_quot",                 too_few_2,      CC_bc_quot,    wrong_no_2},
    {"sum_prodir",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_sum_prodir},
    {"listofvarnames",          CC_listofvarnames,too_many_1,  wrong_no_1},
    {"mk_parents_prim",         CC_mk_parents_prim,too_many_1, wrong_no_1},
    {"dp=comp",                 too_few_2,      CC_dpMcomp,    wrong_no_2},
    {"*s2i",                    CC_Hs2i,        too_many_1,    wrong_no_1},
    {"rl_pnf",                  CC_rl_pnf,      too_many_1,    wrong_no_1},
    {"interglue",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_interglue},
    {"get*real*irreducible*rep",too_few_2,      CC_getHrealHirreducibleHrep,wrong_no_2},
    {"quotf*",                  too_few_2,      CC_quotfH,     wrong_no_2},
    {"iv_cutcongs2",            too_few_2,      CC_iv_cutcongs2,wrong_no_2},
    {"tendstoml",               CC_tendstoml,   too_many_1,    wrong_no_1},
    {"poch*sub*1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_pochHsubH1},
    {"look_for_rational",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_look_for_rational},
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
    {"even_action",             too_few_2,      CC_even_action,wrong_no_2},
    {"cl_pop",                  CC_cl_pop,      too_many_1,    wrong_no_1},
    {"get_mat",                 too_few_2,      CC_get_mat,    wrong_no_2},
    {"nonpolyp",                too_few_2,      CC_nonpolyp,   wrong_no_2},
    {"limitrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_limitrd},
    {NULL, (one_args *)"u46", (two_args *)"21506 7294798 3431489", 0}
};

/* end of generated code */
