
/* $destdir\u07.c        Machine generated C code */

/* Signature: 00000000 21-Apr-2014 */

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
#if !defined UNDER_CE && !defined EMBEDDED
#if ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS                  1
#endif
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
#define TYPE_FOREIGN        TYPE_SPARE 
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
#define font_of_char(n)  (((int32_t)(n) >> 29) & 0x03)
#define bits_of_char(n)  (0)
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0x001fffff)
#define pack_char(font, code)                                      \
    ((Lisp_Object)((((uint32_t)(font)) << 29) |                    \
                   (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF pack_char(0, 0x001fffff)
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
#define UNWIND_FNAME      0x100       
#define UNWIND_ARGS       0x200       
#define UNWIND_ERROR      (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND     0x400       
#ifdef DEBUG
#define SHOW_FNAME  (exit_reason == UNWIND_THROW || \
                     (exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS   (exit_reason == UNWIND_THROW || \
                     (exit_reason & UNWIND_ARGS) != 0)
#else
#define SHOW_FNAME  ((exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS   ((exit_reason & UNWIND_ARGS) != 0)
#endif
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
#define verbos_flag (miscflags & GC_MSG_BITS)
#define HEADLINE_FLAG 0x08
#define FNAME_FLAG    0x10
#define ARGS_FLAG     0x20
#define BACKTRACE_MSG_BITS 0x38
 
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
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
extern CSLbool restartp;
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern Lisp_Object *C_stackbase, *C_stacktop;
#endif
extern Lisp_Object multiplication_buffer;
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
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(char *file, int line);
extern void show_stack();
#define if_check_stack \
   if (check_stack(__FILE__,__LINE__)) \
   {   show_stack(); return aerror("stack overflow"); }
#else
#define if_check_stack \
   {   char *p = (char *)&p; \
       if (p < C_stack_limit) return aerror("stack overflow"); \
   }
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
extern intptr_t modulus_is_large;
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
extern Lisp_Object gchook, resources, callstack, procstack, procmem, trap_time;
#ifdef COMMON
extern Lisp_Object keyword_package;
extern Lisp_Object all_packages, package_symbol, internal_symbol;
extern Lisp_Object external_symbol, inherited_symbol;
extern Lisp_Object key_key, allow_other_keys, aux_key;
extern Lisp_Object format_symbol;
extern Lisp_Object expand_def_symbol, allow_key_key;
#endif
extern Lisp_Object declare_symbol, special_symbol, large_modulus;
extern Lisp_Object used_space, avail_space, eof_symbol;
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
#define modulus_is_large      BASE[32]
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
#define trap_time             BASE[158]
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
#define large_modulus         BASE[184]
#define used_space            BASE[185]
#define avail_space           BASE[186]
#define eof_symbol            BASE[187]
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
#ifndef NO_BYTECOUNT
extern const char *name_of_caller;
#endif
extern int garbage_collection_permitted;
#define MAX_INPUT_FILES         40  
#define MAX_SYMBOLS_TO_DEFINE   40
#define MAX_FASL_PATHS          20
extern char *files_to_read[MAX_INPUT_FILES],
     *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
     *fasl_paths[MAX_FASL_PATHS];
extern int csl_argc;
extern char **csl_argv;
extern int fasl_output_file, output_directory;
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif
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
extern int errorset_min, errorset_max;
extern int number_of_input_files,
    number_of_symbols_to_define,
    number_of_fasl_paths,
    init_flags;
extern int native_code_tag;
extern char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
extern int force_reclaim_method, reclaim_trap_count;
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
extern void *extract_pointer(Lisp_Object a);
extern Lisp_Object Lencapsulatedp(Lisp_Object nil, Lisp_Object a);
typedef void initfn(Lisp_Object *, Lisp_Object **, Lisp_Object * volatile *);
extern int load_dynamic(char *objname, char *modname,
                        Lisp_Object name, Lisp_Object fns);
extern Lisp_Object Linstate_c_code(Lisp_Object nil,
                                   Lisp_Object name, Lisp_Object fns);
extern Lisp_Object characterify(Lisp_Object a);
extern Lisp_Object char_to_id(int ch);
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
extern Lisp_Object noisy_Ceval(Lisp_Object u, Lisp_Object env);
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
                         Lisp_Object env, Lisp_Object fname, int noisy);
extern Lisp_Object apply_lambda(Lisp_Object def, int nargs,
                         Lisp_Object env, Lisp_Object name, int noisy);
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
#define validate_string(a) 
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
#define noisy_eval(a, b) noisy_Ceval(a, b)
#define noisy_voideval(a, b) noisy_Ceval(a, b)
#else
#define eval(a, b) \
    (is_cons(a) ? Ceval(a, b) : \
     is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
                     onevalue(qvalue(a))) : \
     onevalue(a))
#define voideval(a, b) \
    if (is_cons(a)) Ceval(a, b) 
#define noisy_eval(a, b) \
    (is_cons(a) ? noisy_Ceval(a, b) : \
     is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
                     onevalue(qvalue(a))) : \
     onevalue(a))
#define noisy_voideval(a, b) \
    if (is_cons(a)) noisy_Ceval(a, b) 
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
                            Lisp_Object env, int compilerp, int noisy);
extern Lisp_Object mv_call_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object noisy_mv_call_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object progn_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object noisy_progn_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object quote_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object tagbody_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object noisy_tagbody_fn(Lisp_Object args, Lisp_Object env);
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
#define _pi       ((12868.0 - 0.036490896206895257)/4096.0)
#define _half_pi  ((12868.0 - 0.036490896206895257)/8192.0)
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
extern Lisp_Object make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern Lisp_Object make_n_word_bignum(int32_t a1, uint32_t a2,
                                      uint32_t a3, int32_t n);
extern Lisp_Object make_lisp_integer32(int32_t n);
extern Lisp_Object make_lisp_integer64(int64_t n);
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
#if defined HAVE_LIBPTHREAD || defined WIN32
#include <semaphore.h>
#ifdef WIN32
#include <windows.h>
extern HANDLE kara_thread1, kara_thread2;
#define KARARESULT DWORD
#define KARAARG    LPVOID
extern KARARESULT WINAPI kara_worker1(KARAARG p);
extern KARARESULT WINAPI kara_worker2(KARAARG p);
#else
#include <pthread.h>
extern pthread_t kara_thread1, kara_thread2;
#define KARARESULT void *
#define KARAARG    void *
#define WINAPI
extern KARARESULT kara_worker1(KARAARG p);
extern KARARESULT kara_worker2(KARAARG p);
#endif
extern sem_t kara_sem1a, kara_sem1b, kara_sem1c,
             kara_sem2a, kara_sem2b, kara_sem2c;
extern int karatsuba_parallel;
#ifndef KARATSUBA_PARALLEL_CUTOFF
#  define KARATSUBA_PARALLEL_CUTOFF 120
#endif
#endif 
#ifndef KARATSUBA_CUTOFF
#define KARATSUBA_CUTOFF 12
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
extern Lisp_Object bytecounts1(Lisp_Object env, Lisp_Object a);
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
extern Lisp_Object tracesetfunarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracesetbytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object jitcompileme1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracebyteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracesetbyteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebyteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracesetbyteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracesetbytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object traceinterpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracesetinterpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracehardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracesethardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracehardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracesethardoptrest1(Lisp_Object def, Lisp_Object a);
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
extern Lisp_Object Lthrow_nil(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltraceset(Lisp_Object env, Lisp_Object a);
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
extern Lisp_Object tracesetfunarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracebyteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesetbyteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebyteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesetbyteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesetbytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object jitcompileme2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object traceinterpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracesetinterpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracehardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesethardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracehardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesethardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
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
extern Lisp_Object Lthrow_one_value(Lisp_Object env, Lisp_Object a, Lisp_Object b);
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
extern Lisp_Object MS_CDECL tracesetfunargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbyteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbyteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompilemen(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL traceinterpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetinterpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracesethardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracesethardoptrestn(Lisp_Object def, int nargs, ...);
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


/* Code for domain!*p */

static Lisp_Object CC_domainHp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for domain*p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0000;
/* end of prologue */
    v0003 = v0004;
    if (v0003 == nil) goto v0005;
    v0003 = v0004;
    v0003 = (is_number(v0003) ? lisp_true : nil);
    if (!(v0003 == nil)) return onevalue(v0003);
    v0003 = v0004;
    if (!consp(v0003)) goto v0006;
    v0003 = v0004;
    v0003 = qcar(v0003);
    v0004 = qvalue(elt(env, 2)); /* domainlist!* */
    v0003 = Lmemq(nil, v0003, v0004);
    return onevalue(v0003);

v0006:
    v0003 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0003);

v0005:
    v0003 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0003);
}



/* Code for sfpx */

static Lisp_Object CC_sfpx(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0013, v0014, v0015, v0016;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfpx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0012 = v0000;
/* end of prologue */
    v0016 = v0012;
    v0015 = qvalue(elt(env, 1)); /* nil */
    v0014 = qvalue(elt(env, 1)); /* nil */
    v0013 = (Lisp_Object)1; /* 0 */
    v0012 = qvalue(elt(env, 2)); /* t */
    {
        fn = elt(env, 3); /* sfpx1 */
        return (*qfnn(fn))(qenv(fn), 5, v0016, v0015, v0014, v0013, v0012);
    }
}



/* Code for ckpreci!# */

static Lisp_Object CC_ckpreciC(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0024, v0025;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ckpreci#");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0023 = stack[0];
    v0023 = qcar(v0023);
    fn = elt(env, 3); /* timesip */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-2];
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    v0023 = qcar(v0023);
    fn = elt(env, 3); /* timesip */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-2];
    v0025 = stack[-1];
    v0024 = v0023;
    v0023 = qvalue(elt(env, 1)); /* !*complex */
    if (v0023 == nil) goto v0027;
    v0023 = v0025;
    if (v0023 == nil) goto v0015;
    v0023 = v0024;
    if (!(v0023 == nil)) goto v0015;
    v0023 = stack[0];
    v0023 = qcar(v0023);
    v0024 = qcdr(v0023);
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    v0023 = qcar(v0023);
    {
        popv(3);
        fn = elt(env, 4); /* ckprec2!# */
        return (*qfn2(fn))(qenv(fn), v0024, v0023);
    }

v0015:
    v0023 = v0024;
    if (v0023 == nil) goto v0028;
    v0023 = v0025;
    if (!(v0023 == nil)) goto v0028;
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    v0023 = qcar(v0023);
    v0024 = qcdr(v0023);
    v0023 = stack[0];
    v0023 = qcar(v0023);
    {
        popv(3);
        fn = elt(env, 4); /* ckprec2!# */
        return (*qfn2(fn))(qenv(fn), v0024, v0023);
    }

v0028:
    v0023 = nil;
    { popv(3); return onevalue(v0023); }

v0027:
    v0023 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0023); }
/* error exit handlers */
v0026:
    popv(3);
    return nil;
}



/* Code for red!-weight */

static Lisp_Object CC_redKweight(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0013;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red-weight");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */
    v0012 = stack[-1];
    fn = elt(env, 1); /* nonzero!-length */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0012);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-3];
    v0013 = stack[-1];
    v0012 = stack[0];
    fn = elt(env, 2); /* red!-weight1 */
    v0012 = (*qfn2(fn))(qenv(fn), v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    {
        Lisp_Object v0032 = stack[-2];
        popv(4);
        return cons(v0032, v0012);
    }
/* error exit handlers */
v0031:
    popv(4);
    return nil;
}



/* Code for resimp1 */

static Lisp_Object CC_resimp1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for resimp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0033 = stack[0];
    v0034 = qcar(v0033);
    v0033 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* subf1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-2];
    v0033 = stack[0];
    v0034 = qcdr(v0033);
    v0033 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* subf1 */
    v0033 = (*qfn2(fn))(qenv(fn), v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-2];
    fn = elt(env, 5); /* quotsq */
    v0033 = (*qfn2(fn))(qenv(fn), stack[-1], v0033);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-2];
    stack[0] = v0033;
    v0033 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 3)) = v0033; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v0035:
    popv(3);
    return nil;
}



/* Code for pappl_pv */

static Lisp_Object CC_pappl_pv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0048;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pappl_pv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v0047 = v0029;
    stack[-4] = v0000;
/* end of prologue */
    stack[-5] = v0047;
    v0047 = stack[-5];
    if (v0047 == nil) goto v0027;
    v0047 = stack[-5];
    v0047 = qcar(v0047);
    v0048 = v0047;
    stack[0] = qcar(v0048);
    v0048 = stack[-4];
    v0047 = qcdr(v0047);
    fn = elt(env, 2); /* pappl0 */
    v0047 = (*qfn2(fn))(qenv(fn), v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-6];
    v0047 = cons(stack[0], v0047);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-6];
    v0047 = ncons(v0047);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-6];
    stack[-2] = v0047;
    stack[-3] = v0047;
    goto v0019;

v0019:
    v0047 = stack[-5];
    v0047 = qcdr(v0047);
    stack[-5] = v0047;
    v0047 = stack[-5];
    if (v0047 == nil) goto v0050;
    stack[-1] = stack[-2];
    v0047 = stack[-5];
    v0047 = qcar(v0047);
    v0048 = v0047;
    stack[0] = qcar(v0048);
    v0048 = stack[-4];
    v0047 = qcdr(v0047);
    fn = elt(env, 2); /* pappl0 */
    v0047 = (*qfn2(fn))(qenv(fn), v0048, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-6];
    v0047 = cons(stack[0], v0047);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-6];
    v0047 = ncons(v0047);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-6];
    v0047 = Lrplacd(nil, stack[-1], v0047);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-6];
    v0047 = stack[-2];
    v0047 = qcdr(v0047);
    stack[-2] = v0047;
    goto v0019;

v0050:
    v0047 = stack[-3];
    goto v0051;

v0051:
    {
        popv(7);
        fn = elt(env, 3); /* pv_sort */
        return (*qfn1(fn))(qenv(fn), v0047);
    }

v0027:
    v0047 = qvalue(elt(env, 1)); /* nil */
    goto v0051;
/* error exit handlers */
v0049:
    popv(7);
    return nil;
}



/* Code for aronep!: */

static Lisp_Object CC_aronepT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0052;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aronep:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0030 = v0000;
/* end of prologue */
    v0052 = qcdr(v0030);
    v0030 = (Lisp_Object)17; /* 1 */
    v0030 = (v0052 == v0030 ? lisp_true : nil);
    return onevalue(v0030);
}



/* Code for gizerop!: */

static Lisp_Object CC_gizeropT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045, v0006, v0033;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gizerop:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0033 = v0000;
/* end of prologue */
    v0045 = v0033;
    v0045 = qcdr(v0045);
    v0006 = qcar(v0045);
    v0045 = (Lisp_Object)1; /* 0 */
    if (v0006 == v0045) goto v0008;
    v0045 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0045);

v0008:
    v0045 = v0033;
    v0045 = qcdr(v0045);
    v0006 = qcdr(v0045);
    v0045 = (Lisp_Object)1; /* 0 */
    v0045 = (v0006 == v0045 ? lisp_true : nil);
    return onevalue(v0045);
}



/* Code for lispapply */

static Lisp_Object CC_lispapply(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0046, v0022;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lispapply");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0046 = v0029;
    v0022 = v0000;
/* end of prologue */
    v0053 = v0022;
    if (!consp(v0053)) goto v0006;
    stack[-1] = elt(env, 1); /* rlisp */
    stack[0] = (Lisp_Object)33; /* 2 */
    v0053 = elt(env, 2); /* "Apply called with non-id arg" */
    v0046 = v0022;
    v0053 = list2(v0053, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    {
        Lisp_Object v0050 = stack[-1];
        Lisp_Object v0055 = stack[0];
        popv(3);
        fn = elt(env, 3); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0050, v0055, v0053);
    }

v0006:
    v0053 = v0022;
    {
        popv(3);
        fn = elt(env, 4); /* apply */
        return (*qfn2(fn))(qenv(fn), v0053, v0046);
    }
/* error exit handlers */
v0054:
    popv(3);
    return nil;
}



/* Code for reordsq */

static Lisp_Object CC_reordsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reordsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0007 = stack[0];
    v0007 = qcar(v0007);
    fn = elt(env, 1); /* reorder */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    fn = elt(env, 1); /* reorder */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    {
        Lisp_Object v0011 = stack[-1];
        popv(3);
        return cons(v0011, v0007);
    }
/* error exit handlers */
v0010:
    popv(3);
    return nil;
}



/* Code for frvarsof */

static Lisp_Object CC_frvarsof(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0026, v0058, v0039;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for frvarsof");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0026 = v0029;
    v0058 = v0000;
/* end of prologue */

v0030:
    v0039 = v0058;
    v0057 = qvalue(elt(env, 1)); /* frlis!* */
    v0057 = Lmemq(nil, v0039, v0057);
    if (v0057 == nil) goto v0020;
    v0039 = v0058;
    v0057 = v0026;
    v0057 = Lmemq(nil, v0039, v0057);
    if (!(v0057 == nil)) { popv(2); return onevalue(v0026); }
    stack[0] = v0026;
    v0057 = v0058;
    v0057 = ncons(v0057);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    {
        Lisp_Object v0060 = stack[0];
        popv(2);
        return Lappend(nil, v0060, v0057);
    }

v0020:
    v0057 = v0058;
    if (!consp(v0057)) { popv(2); return onevalue(v0026); }
    v0057 = v0058;
    v0057 = qcdr(v0057);
    stack[0] = v0057;
    v0057 = v0058;
    v0057 = qcar(v0057);
    v0057 = CC_frvarsof(env, v0057, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-1];
    v0026 = v0057;
    v0057 = stack[0];
    v0058 = v0057;
    goto v0030;
/* error exit handlers */
v0059:
    popv(2);
    return nil;
}



/* Code for mri_0mk2 */

static Lisp_Object MS_CDECL CC_mri_0mk2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011, v0012, v0013, v0014;
    Lisp_Object v0061, v0029, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mri_0mk2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0029 = va_arg(aa, Lisp_Object);
    v0061 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_0mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0013 = v0061;
    v0011 = v0029;
    v0012 = v0000;
/* end of prologue */
    v0014 = qvalue(elt(env, 1)); /* nil */
    return list4(v0012, v0011, v0014, v0013);
}



/* Code for isarb_int */

static Lisp_Object CC_isarb_int(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0033, v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for isarb_int");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0033 = v0000;
/* end of prologue */
    v0006 = v0033;
    v0006 = Lconsp(nil, v0006);
    env = stack[0];
    if (v0006 == nil) goto v0044;
    v0006 = v0033;
    v0034 = qcar(v0006);
    v0006 = elt(env, 1); /* arbint */
    if (v0034 == v0006) goto v0052;
    v0006 = v0033;
    v0006 = qcdr(v0006);
    fn = elt(env, 4); /* multi_isarb_int */
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    goto v0044;

v0044:
    v0006 = nil;
    { popv(1); return onevalue(v0006); }

v0052:
    v0006 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v0006; /* found_int */
    goto v0044;
/* error exit handlers */
v0003:
    popv(1);
    return nil;
}



/* Code for equal!: */

static Lisp_Object CC_equalT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0017;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for equal:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */
    v0038 = stack[-1];
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    v0038 = (Lisp_Object)zerop(v0038);
    v0038 = v0038 ? lisp_true : nil;
    env = stack[-3];
    if (v0038 == nil) goto v0051;
    v0038 = stack[0];
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    v0038 = (Lisp_Object)zerop(v0038);
    v0038 = v0038 ? lisp_true : nil;
    env = stack[-3];
    goto v0036;

v0036:
    if (!(v0038 == nil)) { popv(4); return onevalue(v0038); }
    v0038 = stack[-1];
    fn = elt(env, 2); /* normbf */
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-3];
    stack[-1] = v0038;
    v0038 = qcdr(v0038);
    stack[-2] = qcdr(v0038);
    v0038 = stack[0];
    fn = elt(env, 2); /* normbf */
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-3];
    stack[0] = v0038;
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    if (equal(stack[-2], v0038)) goto v0022;
    v0038 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0038); }

v0022:
    v0038 = stack[-1];
    v0038 = qcdr(v0038);
    v0017 = qcar(v0038);
    v0038 = stack[0];
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    v0038 = (equal(v0017, v0038) ? lisp_true : nil);
    { popv(4); return onevalue(v0038); }

v0051:
    v0038 = qvalue(elt(env, 1)); /* nil */
    goto v0036;
/* error exit handlers */
v0024:
    popv(4);
    return nil;
}



/* Code for noncomp2f */

static Lisp_Object CC_noncomp2f(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0064, v0065;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomp2f");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */

v0044:
    v0064 = stack[0];
    if (!consp(v0064)) goto v0052;
    v0064 = stack[0];
    v0064 = qcar(v0064);
    v0064 = (consp(v0064) ? nil : lisp_true);
    goto v0030;

v0030:
    if (v0064 == nil) goto v0019;
    v0064 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0064); }

v0019:
    v0064 = stack[0];
    v0064 = qcar(v0064);
    v0064 = qcar(v0064);
    v0064 = qcar(v0064);
    v0065 = v0064;
    if (!consp(v0064)) goto v0015;
    v0064 = v0065;
    v0064 = qcar(v0064);
    if (!symbolp(v0064)) v0064 = nil;
    else { v0064 = qfastgets(v0064);
           if (v0064 != nil) { v0064 = elt(v0064, 0); /* noncom */
#ifdef RECORD_GET
             if (v0064 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0064 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0064 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0064 == SPID_NOPROP) v0064 = nil; else v0064 = lisp_true; }}
#endif
    if (v0064 == nil) goto v0053;
    v0064 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0064); }

v0053:
    v0064 = stack[0];
    v0064 = qcar(v0064);
    v0064 = qcdr(v0064);
    v0064 = CC_noncomp2f(env, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-1];
    if (v0064 == nil) goto v0036;
    v0064 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0064); }

v0036:
    v0064 = stack[0];
    v0064 = qcdr(v0064);
    stack[0] = v0064;
    goto v0044;

v0015:
    v0064 = v0065;
    if (!symbolp(v0064)) v0064 = nil;
    else { v0064 = qfastgets(v0064);
           if (v0064 != nil) { v0064 = elt(v0064, 0); /* noncom */
#ifdef RECORD_GET
             if (v0064 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0064 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0064 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0064 == SPID_NOPROP) v0064 = nil; else v0064 = lisp_true; }}
#endif
    if (v0064 == nil) goto v0036;
    v0064 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0064); }

v0052:
    v0064 = qvalue(elt(env, 1)); /* t */
    goto v0030;
/* error exit handlers */
v0038:
    popv(2);
    return nil;
}



/* Code for contr1!-strand */

static Lisp_Object CC_contr1Kstrand(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0011, v0012, v0013;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for contr1-strand");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0010 = v0029;
    v0011 = v0000;
/* end of prologue */
    v0013 = v0011;
    v0012 = v0010;
    v0011 = qvalue(elt(env, 1)); /* nil */
    v0010 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* contr2!-strand */
        return (*qfnn(fn))(qenv(fn), 4, v0013, v0012, v0011, v0010);
    }
}



/* Code for setcloc!* */

static Lisp_Object MS_CDECL CC_setclocH(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0015, v0016;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setcloc*");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setcloc*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v0014 = qvalue(elt(env, 1)); /* ifl!* */
    if (v0014 == nil) goto v0056;
    v0014 = qvalue(elt(env, 1)); /* ifl!* */
    v0016 = qcar(v0014);
    v0015 = (Lisp_Object)17; /* 1 */
    v0014 = qvalue(elt(env, 3)); /* curline!* */
    v0014 = list2star(v0016, v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[0];
    goto v0061;

v0061:
    qvalue(elt(env, 4)) = v0014; /* cloc!* */
    { popv(1); return onevalue(v0014); }

v0056:
    v0014 = qvalue(elt(env, 2)); /* nil */
    goto v0061;
/* error exit handlers */
v0031:
    popv(1);
    return nil;
}



/* Code for simpexpon */

static Lisp_Object CC_simpexpon(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpexpon");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0020 = v0000;
/* end of prologue */
    v0030 = v0020;
    v0020 = elt(env, 1); /* simp!* */
    {
        fn = elt(env, 2); /* simpexpon1 */
        return (*qfn2(fn))(qenv(fn), v0030, v0020);
    }
}



/* Code for clear!-column */

static Lisp_Object MS_CDECL CC_clearKcolumn(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0139, v0140, v0141, v0142, v0143, v0144, v0145, v0146, v0147, v0148;
    Lisp_Object v0005, v0056, v0061, v0029;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "clear-column");
    va_start(aa, nargs);
    v0029 = va_arg(aa, Lisp_Object);
    v0061 = va_arg(aa, Lisp_Object);
    v0056 = va_arg(aa, Lisp_Object);
    v0005 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for clear-column");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0005,v0056,v0061,v0029);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0029,v0061,v0056,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0005;
    stack[-1] = v0056;
    v0139 = v0061;
    stack[-2] = v0029;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* null!-space!-basis */
    qvalue(elt(env, 1)) = nil; /* null!-space!-basis */
    qvalue(elt(env, 1)) = v0139; /* null!-space!-basis */
    v0139 = (Lisp_Object)1; /* 0 */
    goto v0035;

v0035:
    v0141 = stack[-1];
    v0140 = v0139;
    v0141 = *(Lisp_Object *)((char *)v0141 + (CELL-TAG_VECTOR) + ((int32_t)v0140/(16/CELL)));
    v0140 = stack[-2];
    v0141 = *(Lisp_Object *)((char *)v0141 + (CELL-TAG_VECTOR) + ((int32_t)v0140/(16/CELL)));
    v0140 = (Lisp_Object)1; /* 0 */
    if (v0141 == v0140) goto v0015;
    v0141 = v0139;
    v0140 = stack[-2];
    if (((int32_t)(v0141)) < ((int32_t)(v0140))) goto v0149;
    v0140 = qvalue(elt(env, 3)); /* nil */
    goto v0014;

v0014:
    if (v0140 == nil) goto v0150;
    v0141 = (Lisp_Object)((int32_t)(v0139) + 0x10);
    v0139 = v0141;
    v0140 = stack[0];
    if (!(((int32_t)(v0141)) > ((int32_t)(v0140)))) goto v0035;
    v0140 = stack[-2];
    v0139 = qvalue(elt(env, 1)); /* null!-space!-basis */
    v0139 = cons(v0140, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    goto v0051;

v0051:
    qvalue(elt(env, 1)) = stack[-3]; /* null!-space!-basis */
    { popv(5); return onevalue(v0139); }

v0150:
    v0141 = stack[-1];
    v0140 = v0139;
    v0140 = *(Lisp_Object *)((char *)v0141 + (CELL-TAG_VECTOR) + ((int32_t)v0140/(16/CELL)));
    v0148 = v0140;
    v0142 = stack[-1];
    v0141 = v0139;
    v0140 = stack[-1];
    v0139 = stack[-2];
    v0139 = *(Lisp_Object *)((char *)v0140 + (CELL-TAG_VECTOR) + ((int32_t)v0139/(16/CELL)));
    *(Lisp_Object *)((char *)v0142 + (CELL-TAG_VECTOR) + ((int32_t)v0141/(16/CELL))) = v0139;
    v0140 = stack[-1];
    v0139 = stack[-2];
    v0141 = v0148;
    *(Lisp_Object *)((char *)v0140 + (CELL-TAG_VECTOR) + ((int32_t)v0139/(16/CELL))) = v0141;
    v0140 = stack[-1];
    v0139 = stack[-2];
    v0140 = *(Lisp_Object *)((char *)v0140 + (CELL-TAG_VECTOR) + ((int32_t)v0139/(16/CELL)));
    v0139 = stack[-2];
    v0139 = *(Lisp_Object *)((char *)v0140 + (CELL-TAG_VECTOR) + ((int32_t)v0139/(16/CELL)));
    v0139 = Lmodular_reciprocal(nil, v0139);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v0139);
        if (w != 0) w = current_modulus - w;
        v0139 = fixnum_of_int(w);
    }
    v0148 = v0139;
    v0139 = (Lisp_Object)1; /* 0 */
    v0147 = v0139;
    goto v0152;

v0152:
    v0140 = stack[0];
    v0139 = v0147;
    v0139 = (Lisp_Object)(int32_t)((int32_t)v0140 - (int32_t)v0139 + TAG_FIXNUM);
    v0139 = ((intptr_t)(v0139) < 0 ? lisp_true : nil);
    if (v0139 == nil) goto v0153;
    v0139 = stack[-2];
    v0143 = v0139;
    goto v0154;

v0154:
    v0140 = stack[0];
    v0139 = v0143;
    v0139 = (Lisp_Object)(int32_t)((int32_t)v0140 - (int32_t)v0139 + TAG_FIXNUM);
    v0139 = ((intptr_t)(v0139) < 0 ? lisp_true : nil);
    if (v0139 == nil) goto v0155;
    v0139 = qvalue(elt(env, 1)); /* null!-space!-basis */
    goto v0051;

v0155:
    v0140 = stack[-1];
    v0139 = stack[-2];
    v0142 = *(Lisp_Object *)((char *)v0140 + (CELL-TAG_VECTOR) + ((int32_t)v0139/(16/CELL)));
    v0141 = v0143;
    v0140 = stack[-1];
    v0139 = stack[-2];
    v0140 = *(Lisp_Object *)((char *)v0140 + (CELL-TAG_VECTOR) + ((int32_t)v0139/(16/CELL)));
    v0139 = v0143;
    v0140 = *(Lisp_Object *)((char *)v0140 + (CELL-TAG_VECTOR) + ((int32_t)v0139/(16/CELL)));
    v0139 = v0148;
    v0139 = Lmodular_times(nil, v0140, v0139);
    env = stack[-4];
    *(Lisp_Object *)((char *)v0142 + (CELL-TAG_VECTOR) + ((int32_t)v0141/(16/CELL))) = v0139;
    v0139 = v0143;
    v0139 = (Lisp_Object)((int32_t)(v0139) + 0x10);
    v0143 = v0139;
    goto v0154;

v0153:
    v0140 = v0147;
    v0139 = stack[-2];
    if (equal(v0140, v0139)) goto v0156;
    v0140 = stack[-1];
    v0139 = v0147;
    v0140 = *(Lisp_Object *)((char *)v0140 + (CELL-TAG_VECTOR) + ((int32_t)v0139/(16/CELL)));
    v0139 = stack[-2];
    v0139 = *(Lisp_Object *)((char *)v0140 + (CELL-TAG_VECTOR) + ((int32_t)v0139/(16/CELL)));
    v0146 = v0139;
    v0140 = v0146;
    v0139 = (Lisp_Object)1; /* 0 */
    if (v0140 == v0139) goto v0156;
    v0140 = v0146;
    v0139 = v0148;
    v0139 = Lmodular_times(nil, v0140, v0139);
    env = stack[-4];
    v0146 = v0139;
    v0139 = stack[-2];
    v0145 = v0139;
    goto v0157;

v0157:
    v0140 = stack[0];
    v0139 = v0145;
    v0139 = (Lisp_Object)(int32_t)((int32_t)v0140 - (int32_t)v0139 + TAG_FIXNUM);
    v0139 = ((intptr_t)(v0139) < 0 ? lisp_true : nil);
    if (!(v0139 == nil)) goto v0156;
    v0140 = stack[-1];
    v0139 = v0147;
    v0144 = *(Lisp_Object *)((char *)v0140 + (CELL-TAG_VECTOR) + ((int32_t)v0139/(16/CELL)));
    v0143 = v0145;
    v0140 = stack[-1];
    v0139 = v0147;
    v0140 = *(Lisp_Object *)((char *)v0140 + (CELL-TAG_VECTOR) + ((int32_t)v0139/(16/CELL)));
    v0139 = v0145;
    v0142 = *(Lisp_Object *)((char *)v0140 + (CELL-TAG_VECTOR) + ((int32_t)v0139/(16/CELL)));
    v0141 = v0146;
    v0140 = stack[-1];
    v0139 = stack[-2];
    v0140 = *(Lisp_Object *)((char *)v0140 + (CELL-TAG_VECTOR) + ((int32_t)v0139/(16/CELL)));
    v0139 = v0145;
    v0139 = *(Lisp_Object *)((char *)v0140 + (CELL-TAG_VECTOR) + ((int32_t)v0139/(16/CELL)));
    v0139 = Lmodular_times(nil, v0141, v0139);
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v0142) + int_of_fixnum(v0139);
        if (w >= current_modulus) w -= current_modulus;
        v0139 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v0144 + (CELL-TAG_VECTOR) + ((int32_t)v0143/(16/CELL))) = v0139;
    v0139 = v0145;
    v0139 = (Lisp_Object)((int32_t)(v0139) + 0x10);
    v0145 = v0139;
    goto v0157;

v0156:
    v0139 = v0147;
    v0139 = (Lisp_Object)((int32_t)(v0139) + 0x10);
    v0147 = v0139;
    goto v0152;

v0149:
    v0141 = stack[-1];
    v0140 = v0139;
    v0141 = *(Lisp_Object *)((char *)v0141 + (CELL-TAG_VECTOR) + ((int32_t)v0140/(16/CELL)));
    v0140 = v0139;
    v0141 = *(Lisp_Object *)((char *)v0141 + (CELL-TAG_VECTOR) + ((int32_t)v0140/(16/CELL)));
    v0140 = (Lisp_Object)1; /* 0 */
    v0140 = (v0141 == v0140 ? lisp_true : nil);
    v0140 = (v0140 == nil ? lisp_true : nil);
    goto v0014;

v0015:
    v0140 = qvalue(elt(env, 2)); /* t */
    goto v0014;
/* error exit handlers */
v0151:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* null!-space!-basis */
    popv(5);
    return nil;
}



/* Code for rread1 */

static Lisp_Object MS_CDECL CC_rread1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115, v0169, v0170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rread1");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rread1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
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
    fn = elt(env, 15); /* ptoken */
    v0115 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-2];
    stack[-1] = v0115;
    v0169 = qvalue(elt(env, 1)); /* ttype!* */
    v0115 = (Lisp_Object)49; /* 3 */
    if (v0169 == v0115) goto v0060;
    v0115 = stack[-1];
    if (symbolp(v0115)) goto v0012;
    v0169 = stack[-1];
    v0115 = elt(env, 4); /* !:dn!: */
    if (!consp(v0169)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0169 = qcar(v0169);
    if (!(v0169 == v0115)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0170 = stack[-1];
    v0169 = qvalue(elt(env, 5)); /* nil */
    v0115 = elt(env, 6); /* symbolic */
    {
        popv(3);
        fn = elt(env, 16); /* dnform */
        return (*qfnn(fn))(qenv(fn), 3, v0170, v0169, v0115);
    }

v0012:
    v0115 = qvalue(elt(env, 2)); /* !*quotenewnam */
    if (v0115 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0169 = stack[-1];
    v0115 = elt(env, 3); /* quotenewnam */
    v0115 = get(v0169, v0115);
    stack[0] = v0115;
    if (v0115 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    else { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v0060:
    v0169 = stack[-1];
    v0115 = elt(env, 7); /* !( */
    if (v0169 == v0115) goto v0040;
    v0169 = stack[-1];
    v0115 = elt(env, 8); /* !+ */
    if (v0169 == v0115) goto v0134;
    v0169 = stack[-1];
    v0115 = elt(env, 10); /* !- */
    v0115 = (v0169 == v0115 ? lisp_true : nil);
    goto v0136;

v0136:
    if (v0115 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    fn = elt(env, 15); /* ptoken */
    v0115 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-2];
    stack[0] = v0115;
    v0169 = stack[0];
    v0115 = elt(env, 4); /* !:dn!: */
    if (!consp(v0169)) goto v0172;
    v0169 = qcar(v0169);
    if (!(v0169 == v0115)) goto v0172;
    v0170 = stack[0];
    v0169 = qvalue(elt(env, 5)); /* nil */
    v0115 = elt(env, 6); /* symbolic */
    fn = elt(env, 16); /* dnform */
    v0115 = (*qfnn(fn))(qenv(fn), 3, v0170, v0169, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-2];
    stack[0] = v0115;
    goto v0172;

v0172:
    v0115 = stack[0];
    if (is_number(v0115)) goto v0119;
    v0115 = elt(env, 11); /* " " */
    qvalue(elt(env, 12)) = v0115; /* nxtsym!* */
    v0169 = elt(env, 13); /* "Syntax error: improper number" */
    v0115 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 17); /* symerr */
    v0115 = (*qfn2(fn))(qenv(fn), v0169, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v0119:
    v0169 = stack[-1];
    v0115 = elt(env, 10); /* !- */
    if (!(v0169 == v0115)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0169 = elt(env, 14); /* minus */
    v0115 = stack[0];
    v0115 = Lapply1(nil, v0169, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    stack[0] = v0115;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v0134:
    v0115 = qvalue(elt(env, 9)); /* t */
    goto v0136;

v0040:
    {
        popv(3);
        fn = elt(env, 18); /* rrdls */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v0171:
    popv(3);
    return nil;
}



/* Code for ckrn */

static Lisp_Object CC_ckrn(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0023;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ckrn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0018 = qvalue(elt(env, 1)); /* dmode!* */
    if (!symbolp(v0018)) v0018 = nil;
    else { v0018 = qfastgets(v0018);
           if (v0018 != nil) { v0018 = elt(v0018, 3); /* field */
#ifdef RECORD_GET
             if (v0018 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0018 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0018 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0018 == SPID_NOPROP) v0018 = nil; else v0018 = lisp_true; }}
#endif
    if (v0018 == nil) goto v0014;
    v0023 = qvalue(elt(env, 1)); /* dmode!* */
    v0018 = elt(env, 2); /* (!:rd!: !:cr!:) */
    v0018 = Lmemq(nil, v0023, v0018);
    v0018 = (v0018 == nil ? lisp_true : nil);
    goto v0036;

v0036:
    if (v0018 == nil) goto v0037;
    v0018 = stack[0];
    fn = elt(env, 4); /* lnc */
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-2];
    stack[-1] = v0018;
    v0023 = stack[0];
    fn = elt(env, 5); /* quotfd */
    v0018 = (*qfn2(fn))(qenv(fn), v0023, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-2];
    fn = elt(env, 6); /* ckrn1 */
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-2];
    fn = elt(env, 7); /* multf */
    v0018 = (*qfn2(fn))(qenv(fn), stack[-1], v0018);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    v0023 = v0018;
    if (!(v0023 == nil)) { popv(3); return onevalue(v0018); }
    v0018 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0018); }

v0037:
    v0018 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* ckrn1 */
        return (*qfn1(fn))(qenv(fn), v0018);
    }

v0014:
    v0018 = qvalue(elt(env, 3)); /* nil */
    goto v0036;
/* error exit handlers */
v0167:
    popv(3);
    return nil;
}



/* Code for ibalp_calcmom */

static Lisp_Object CC_ibalp_calcmom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0017;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_calcmom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0038 = stack[0];
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0017 = qcar(v0038);
    v0038 = stack[0];
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    v0017 = plus2(v0017, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-2];
    v0038 = (Lisp_Object)513; /* 32 */
    stack[-1] = times2(v0017, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-2];
    v0038 = stack[0];
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0017 = qcar(v0038);
    v0038 = stack[0];
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    v0038 = times2(v0017, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    {
        Lisp_Object v0024 = stack[-1];
        popv(3);
        return plus2(v0024, v0038);
    }
/* error exit handlers */
v0023:
    popv(3);
    return nil;
}



/* Code for cgp_evlmon */

static Lisp_Object CC_cgp_evlmon(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cgp_evlmon");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0044 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* cgp_rp */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dip_evlmon */
        return (*qfn1(fn))(qenv(fn), v0044);
    }
/* error exit handlers */
v0043:
    popv(1);
    return nil;
}



/* Code for checktag */

static Lisp_Object CC_checktag(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for checktag");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0016 = v0000;
/* end of prologue */
    v0031 = qvalue(elt(env, 1)); /* char */
    if (equal(v0031, v0016)) goto v0044;
    v0031 = elt(env, 2); /* "Problem" */
    v0016 = elt(env, 3); /* "problem" */
    fn = elt(env, 4); /* errorml */
    v0016 = (*qfn2(fn))(qenv(fn), v0031, v0016);
    errexit();
    goto v0044;

v0044:
    v0016 = nil;
    return onevalue(v0016);
}



/* Code for retimes1 */

static Lisp_Object CC_retimes1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0179, v0180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for retimes1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = nil;
    goto v0044;

v0044:
    v0179 = stack[0];
    if (v0179 == nil) goto v0051;
    v0179 = stack[0];
    v0180 = qcar(v0179);
    v0179 = (Lisp_Object)17; /* 1 */
    if (v0180 == v0179) goto v0027;
    v0179 = stack[0];
    v0179 = qcar(v0179);
    v0179 = Lminusp(nil, v0179);
    env = stack[-2];
    if (v0179 == nil) goto v0002;
    v0179 = qvalue(elt(env, 1)); /* !*bool */
    v0179 = (v0179 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v0179; /* !*bool */
    v0179 = stack[0];
    v0179 = qcar(v0179);
    v0180 = negate(v0179);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    v0179 = stack[0];
    v0179 = qcdr(v0179);
    v0179 = cons(v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    stack[0] = v0179;
    goto v0044;

v0002:
    v0179 = stack[0];
    v0179 = qcar(v0179);
    if (!consp(v0179)) goto v0062;
    v0179 = stack[0];
    v0179 = qcar(v0179);
    v0180 = qcar(v0179);
    v0179 = elt(env, 2); /* minus */
    if (v0180 == v0179) goto v0024;
    v0179 = stack[0];
    v0179 = qcar(v0179);
    v0180 = qcar(v0179);
    v0179 = elt(env, 3); /* times */
    if (v0180 == v0179) goto v0130;
    v0179 = stack[0];
    v0180 = qcar(v0179);
    v0179 = stack[-1];
    v0179 = cons(v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    stack[-1] = v0179;
    v0179 = stack[0];
    v0179 = qcdr(v0179);
    stack[0] = v0179;
    goto v0044;

v0130:
    v0179 = stack[0];
    v0179 = qcar(v0179);
    v0180 = qcdr(v0179);
    v0179 = stack[0];
    v0179 = qcdr(v0179);
    v0179 = Lappend(nil, v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    stack[0] = v0179;
    goto v0044;

v0024:
    v0179 = qvalue(elt(env, 1)); /* !*bool */
    v0179 = (v0179 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v0179; /* !*bool */
    v0179 = stack[0];
    v0179 = qcar(v0179);
    v0179 = qcdr(v0179);
    v0180 = qcar(v0179);
    v0179 = stack[0];
    v0179 = qcdr(v0179);
    v0179 = cons(v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    stack[0] = v0179;
    goto v0044;

v0062:
    v0179 = stack[0];
    v0180 = qcar(v0179);
    v0179 = stack[-1];
    v0179 = cons(v0180, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-2];
    stack[-1] = v0179;
    v0179 = stack[0];
    v0179 = qcdr(v0179);
    stack[0] = v0179;
    goto v0044;

v0027:
    v0179 = stack[0];
    v0179 = qcdr(v0179);
    stack[0] = v0179;
    goto v0044;

v0051:
    v0179 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0179);
    }
/* error exit handlers */
v0121:
    popv(3);
    return nil;
}



/* Code for rd!:minus */

static Lisp_Object CC_rdTminus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0016;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:minus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0016 = v0000;
/* end of prologue */
    v0015 = v0016;
    v0015 = qcdr(v0015);
    if (!consp(v0015)) goto v0019;
    v0015 = v0016;
    {
        popv(1);
        fn = elt(env, 2); /* minus!: */
        return (*qfn1(fn))(qenv(fn), v0015);
    }

v0019:
    stack[0] = elt(env, 1); /* !:rd!: */
    v0015 = v0016;
    v0015 = qcdr(v0015);
    v0015 = negate(v0015);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    {
        Lisp_Object v0002 = stack[0];
        popv(1);
        return cons(v0002, v0015);
    }
/* error exit handlers */
v0032:
    popv(1);
    return nil;
}



/* Code for reval1 */

static Lisp_Object CC_reval1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0236, v0237, v0238;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reval1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0029;
    stack[-2] = v0000;
/* end of prologue */
    v0236 = qvalue(elt(env, 1)); /* !*revalp */
    if (v0236 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0236 = qvalue(elt(env, 2)); /* varstack!* */
    stack[-3] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v0236; /* varstack!* */
    v0236 = stack[-2];
    if (v0236 == nil) goto v0012;
    v0236 = stack[-2];
    v0236 = Lstringp(nil, v0236);
    env = stack[-4];
    if (v0236 == nil) goto v0031;
    v0236 = stack[-2];
    goto v0009;

v0009:
    qvalue(elt(env, 2)) = stack[-3]; /* varstack!* */
    { popv(5); return onevalue(v0236); }

v0031:
    v0236 = stack[-2];
    v0236 = integerp(v0236);
    if (v0236 == nil) goto v0006;
    v0236 = qvalue(elt(env, 4)); /* dmode!* */
    if (!symbolp(v0236)) v0236 = nil;
    else { v0236 = qfastgets(v0236);
           if (v0236 != nil) { v0236 = elt(v0236, 5); /* convert */
#ifdef RECORD_GET
             if (v0236 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v0236 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v0236 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v0236 == SPID_NOPROP) v0236 = nil; else v0236 = lisp_true; }}
#endif
    if (v0236 == nil) goto v0239;
    v0237 = stack[-2];
    v0236 = stack[-1];
    fn = elt(env, 20); /* reval2 */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0009;

v0239:
    v0236 = stack[-2];
    goto v0009;

v0006:
    v0236 = stack[-2];
    if (!consp(v0236)) goto v0168;
    v0236 = stack[-2];
    v0236 = qcar(v0236);
    if (symbolp(v0236)) goto v0241;
    v0237 = stack[-2];
    v0236 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 21); /* errpri2 */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0011;

v0011:
    v0236 = stack[-2];
    fn = elt(env, 22); /* getrtype */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    stack[0] = v0236;
    if (v0236 == nil) goto v0242;
    v0237 = stack[0];
    v0236 = elt(env, 6); /* evfn */
    v0236 = get(v0237, v0236);
    env = stack[-4];
    v0238 = v0236;
    if (v0236 == nil) goto v0243;
    v0237 = stack[-2];
    v0236 = stack[-1];
    v0236 = Lapply2(nil, 3, v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0009;

v0243:
    stack[-2] = elt(env, 11); /* alg */
    stack[-1] = (Lisp_Object)1617; /* 101 */
    v0237 = elt(env, 12); /* "Missing evaluation for type" */
    v0236 = stack[0];
    v0236 = list2(v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    fn = elt(env, 23); /* rerror */
    v0236 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0009;

v0242:
    v0236 = stack[-2];
    if (!consp(v0236)) goto v0244;
    v0236 = stack[-2];
    v0236 = qcdr(v0236);
    if (!consp(v0236)) goto v0245;
    v0236 = stack[-2];
    v0236 = qcdr(v0236);
    v0236 = qcar(v0236);
    fn = elt(env, 22); /* getrtype */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    v0238 = v0236;
    if (v0236 == nil) goto v0246;
    v0237 = v0238;
    v0236 = elt(env, 13); /* list */
    if (v0237 == v0236) goto v0067;
    v0236 = qvalue(elt(env, 3)); /* nil */
    goto v0077;

v0077:
    if (v0236 == nil) goto v0071;
    v0236 = qvalue(elt(env, 3)); /* nil */
    goto v0247;

v0247:
    if (v0236 == nil) goto v0248;
    v0238 = stack[0];
    v0237 = stack[-2];
    v0236 = stack[-1];
    v0236 = Lapply2(nil, 3, v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0009;

v0248:
    v0237 = stack[-2];
    v0236 = stack[-1];
    fn = elt(env, 20); /* reval2 */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0009;

v0071:
    v0237 = v0238;
    v0236 = elt(env, 14); /* aggregatefn */
    v0236 = get(v0237, v0236);
    env = stack[-4];
    stack[0] = v0236;
    if (v0236 == nil) goto v0249;
    v0237 = stack[0];
    v0236 = elt(env, 15); /* matrixmap */
    if (v0237 == v0236) goto v0250;
    v0236 = qvalue(elt(env, 7)); /* t */
    goto v0147;

v0147:
    if (v0236 == nil) goto v0251;
    v0236 = stack[-2];
    v0237 = qcar(v0236);
    v0236 = elt(env, 17); /* boolean */
    v0236 = Lflagp(nil, v0237, v0236);
    env = stack[-4];
    if (v0236 == nil) goto v0252;
    v0236 = qvalue(elt(env, 3)); /* nil */
    goto v0247;

v0252:
    v0236 = qvalue(elt(env, 18)); /* !*listargs */
    if (v0236 == nil) goto v0253;
    v0236 = qvalue(elt(env, 3)); /* nil */
    goto v0247;

v0253:
    v0236 = stack[-2];
    v0237 = qcar(v0236);
    v0236 = elt(env, 19); /* listargp */
    v0236 = Lflagp(nil, v0237, v0236);
    env = stack[-4];
    v0236 = (v0236 == nil ? lisp_true : nil);
    goto v0247;

v0251:
    v0236 = qvalue(elt(env, 3)); /* nil */
    goto v0247;

v0250:
    v0236 = stack[-2];
    v0237 = qcar(v0236);
    v0236 = elt(env, 16); /* matmapfn */
    v0236 = Lflagp(nil, v0237, v0236);
    env = stack[-4];
    goto v0147;

v0249:
    v0236 = qvalue(elt(env, 3)); /* nil */
    goto v0247;

v0067:
    v0236 = stack[-2];
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    goto v0077;

v0246:
    v0236 = qvalue(elt(env, 3)); /* nil */
    goto v0247;

v0245:
    v0236 = qvalue(elt(env, 3)); /* nil */
    goto v0247;

v0244:
    v0236 = qvalue(elt(env, 3)); /* nil */
    goto v0247;

v0241:
    v0236 = stack[-2];
    v0237 = qcar(v0236);
    v0236 = elt(env, 8); /* !*sq */
    if (v0237 == v0236) goto v0119;
    v0236 = stack[-2];
    v0236 = qcar(v0236);
    if (!symbolp(v0236)) v0236 = nil;
    else { v0236 = qfastgets(v0236);
           if (v0236 != nil) { v0236 = elt(v0236, 39); /* remember */
#ifdef RECORD_GET
             if (v0236 == SPID_NOPROP)
                record_get(elt(fastget_names, 39), 0),
                v0236 = nil;
             else record_get(elt(fastget_names, 39), 1),
                v0236 = lisp_true; }
           else record_get(elt(fastget_names, 39), 0); }
#else
             if (v0236 == SPID_NOPROP) v0236 = nil; else v0236 = lisp_true; }}
#endif
    if (v0236 == nil) goto v0254;
    v0237 = stack[-2];
    v0236 = stack[-1];
    fn = elt(env, 24); /* rmmbreval */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0009;

v0254:
    v0236 = stack[-2];
    v0236 = qcar(v0236);
    if (!symbolp(v0236)) v0236 = nil;
    else { v0236 = qfastgets(v0236);
           if (v0236 != nil) { v0236 = elt(v0236, 59); /* opfn */
#ifdef RECORD_GET
             if (v0236 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v0236 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v0236 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v0236 == SPID_NOPROP) v0236 = nil; else v0236 = lisp_true; }}
#endif
    if (v0236 == nil) goto v0255;
    v0236 = stack[-2];
    fn = elt(env, 25); /* opfneval */
    v0237 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    v0236 = stack[-1];
    v0236 = CC_reval1(env, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0009;

v0255:
    v0236 = stack[-2];
    v0236 = qcar(v0236);
    if (!symbolp(v0236)) v0236 = nil;
    else { v0236 = qfastgets(v0236);
           if (v0236 != nil) { v0236 = elt(v0236, 45); /* psopfn */
#ifdef RECORD_GET
             if (v0236 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v0236 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v0236 == SPID_NOPROP) v0236 = nil; }}
#endif
    stack[0] = v0236;
    if (v0236 == nil) goto v0256;
    v0237 = stack[0];
    v0236 = stack[-2];
    v0236 = qcdr(v0236);
    v0236 = Lapply1(nil, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    stack[-2] = v0236;
    v0237 = stack[0];
    v0236 = elt(env, 10); /* cleanupfn */
    v0236 = get(v0237, v0236);
    env = stack[-4];
    stack[0] = v0236;
    if (v0236 == nil) goto v0103;
    v0238 = stack[0];
    v0237 = stack[-2];
    v0236 = stack[-1];
    v0236 = Lapply2(nil, 3, v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    stack[-2] = v0236;
    goto v0103;

v0103:
    v0236 = stack[-2];
    goto v0009;

v0256:
    v0236 = stack[-2];
    v0236 = qcar(v0236);
    fn = elt(env, 26); /* arrayp */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    if (v0236 == nil) goto v0011;
    v0236 = stack[-2];
    fn = elt(env, 27); /* getelv */
    v0237 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    v0236 = stack[-1];
    v0236 = CC_reval1(env, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0009;

v0119:
    v0236 = stack[-2];
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    v0236 = qcar(v0236);
    if (v0236 == nil) goto v0257;
    v0236 = qvalue(elt(env, 9)); /* !*resimp */
    if (!(v0236 == nil)) goto v0257;
    v0236 = stack[-1];
    if (v0236 == nil) goto v0258;
    v0236 = stack[-2];
    v0236 = qcdr(v0236);
    v0236 = qcar(v0236);
    fn = elt(env, 28); /* prepsqxx */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0009;

v0258:
    v0236 = stack[-2];
    goto v0009;

v0257:
    v0237 = stack[-2];
    v0236 = stack[-1];
    fn = elt(env, 20); /* reval2 */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0009;

v0168:
    v0236 = qvalue(elt(env, 5)); /* subfg!* */
    if (v0236 == nil) goto v0017;
    v0236 = stack[-2];
    if (!(symbolp(v0236))) goto v0011;
    v0236 = stack[-2];
    if (!symbolp(v0236)) v0236 = nil;
    else { v0236 = qfastgets(v0236);
           if (v0236 != nil) { v0236 = elt(v0236, 4); /* avalue */
#ifdef RECORD_GET
             if (v0236 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0236 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0236 == SPID_NOPROP) v0236 = nil; }}
#endif
    stack[0] = v0236;
    if (v0236 == nil) goto v0011;
    v0237 = stack[-2];
    v0236 = qvalue(elt(env, 2)); /* varstack!* */
    v0236 = Lmemq(nil, v0237, v0236);
    if (v0236 == nil) goto v0133;
    v0236 = stack[-2];
    fn = elt(env, 29); /* recursiveerror */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0011;

v0133:
    v0237 = stack[-2];
    v0236 = qvalue(elt(env, 2)); /* varstack!* */
    v0236 = cons(v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0236; /* varstack!* */
    v0236 = stack[0];
    v0237 = qcar(v0236);
    v0236 = elt(env, 6); /* evfn */
    v0236 = get(v0237, v0236);
    env = stack[-4];
    v0238 = v0236;
    if (v0236 == nil) goto v0259;
    v0237 = stack[-2];
    v0236 = stack[-1];
    v0236 = Lapply2(nil, 3, v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0009;

v0259:
    v0236 = stack[0];
    v0236 = qcdr(v0236);
    v0237 = qcar(v0236);
    v0236 = stack[-1];
    v0236 = CC_reval1(env, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0009;

v0017:
    v0236 = stack[-2];
    goto v0009;

v0012:
    v0236 = qvalue(elt(env, 3)); /* nil */
    goto v0009;
/* error exit handlers */
v0240:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; /* varstack!* */
    popv(5);
    return nil;
}



/* Code for groebsearchinlist */

static Lisp_Object CC_groebsearchinlist(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0003;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebsearchinlist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */

v0044:
    v0034 = stack[0];
    if (v0034 == nil) goto v0051;
    v0034 = stack[0];
    v0034 = qcar(v0034);
    v0034 = qcdr(v0034);
    v0003 = qcar(v0034);
    v0034 = stack[-1];
    fn = elt(env, 2); /* buchvevdivides!? */
    v0034 = (*qfn2(fn))(qenv(fn), v0003, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-2];
    if (v0034 == nil) goto v0001;
    v0034 = stack[0];
    v0034 = qcar(v0034);
    { popv(3); return onevalue(v0034); }

v0001:
    v0034 = stack[0];
    v0034 = qcdr(v0034);
    stack[0] = v0034;
    goto v0044;

v0051:
    v0034 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0034); }
/* error exit handlers */
v0021:
    popv(3);
    return nil;
}



/* Code for eofcheck */

static Lisp_Object MS_CDECL CC_eofcheck(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0003;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "eofcheck");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for eofcheck");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v0003 = qvalue(elt(env, 1)); /* program!* */
    v0034 = qvalue(elt(env, 2)); /* !$eof!$ */
    if (v0003 == v0034) goto v0009;
    v0034 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v0034); }

v0009:
    v0003 = qvalue(elt(env, 3)); /* ttype!* */
    v0034 = (Lisp_Object)49; /* 3 */
    if (v0003 == v0034) goto v0007;
    v0034 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v0034); }

v0007:
    v0034 = qvalue(elt(env, 4)); /* eof!* */
    v0034 = add1(v0034);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[0];
    qvalue(elt(env, 4)) = v0034; /* eof!* */
    { popv(1); return onevalue(v0034); }
/* error exit handlers */
v0004:
    popv(1);
    return nil;
}



/* Code for mv!-pow!-minusp */

static Lisp_Object CC_mvKpowKminusp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0002;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-pow-minusp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */

v0260:
    v0032 = stack[0];
    if (v0032 == nil) goto v0005;
    v0032 = stack[0];
    v0002 = qcar(v0032);
    v0032 = (Lisp_Object)1; /* 0 */
    v0032 = (Lisp_Object)lessp2(v0002, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    v0032 = v0032 ? lisp_true : nil;
    env = stack[-1];
    if (!(v0032 == nil)) { popv(2); return onevalue(v0032); }
    v0032 = stack[0];
    v0032 = qcdr(v0032);
    stack[0] = v0032;
    goto v0260;

v0005:
    v0032 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0032); }
/* error exit handlers */
v0045:
    popv(2);
    return nil;
}



/* Code for rnplus!: */

static Lisp_Object CC_rnplusT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0065, v0037;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnplus:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */
    v0065 = stack[-1];
    v0065 = qcdr(v0065);
    v0037 = qcar(v0065);
    v0065 = stack[0];
    v0065 = qcdr(v0065);
    v0065 = qcdr(v0065);
    stack[-2] = times2(v0037, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-3];
    v0065 = stack[-1];
    v0065 = qcdr(v0065);
    v0037 = qcdr(v0065);
    v0065 = stack[0];
    v0065 = qcdr(v0065);
    v0065 = qcar(v0065);
    v0065 = times2(v0037, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-3];
    stack[-2] = plus2(stack[-2], v0065);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-3];
    v0065 = stack[-1];
    v0065 = qcdr(v0065);
    v0037 = qcdr(v0065);
    v0065 = stack[0];
    v0065 = qcdr(v0065);
    v0065 = qcdr(v0065);
    v0065 = times2(v0037, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-3];
    {
        Lisp_Object v0023 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v0023, v0065);
    }
/* error exit handlers */
v0018:
    popv(4);
    return nil;
}



/* Code for general!-plus!-mod!-p */

static Lisp_Object CC_generalKplusKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0212, v0181;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-plus-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0029;
    stack[-3] = v0000;
/* end of prologue */
    stack[0] = nil;
    goto v0043;

v0043:
    v0212 = stack[-3];
    if (v0212 == nil) goto v0027;
    v0212 = stack[-2];
    if (v0212 == nil) goto v0031;
    v0212 = stack[-3];
    if (!consp(v0212)) goto v0021;
    v0212 = stack[-3];
    v0212 = qcar(v0212);
    v0212 = (consp(v0212) ? nil : lisp_true);
    goto v0035;

v0035:
    if (v0212 == nil) goto v0003;
    v0212 = stack[-2];
    if (!consp(v0212)) goto v0064;
    v0212 = stack[-2];
    v0212 = qcar(v0212);
    v0212 = (consp(v0212) ? nil : lisp_true);
    goto v0168;

v0168:
    if (v0212 == nil) goto v0136;
    v0181 = stack[-3];
    v0212 = stack[-2];
    fn = elt(env, 3); /* general!-modular!-plus */
    v0212 = (*qfn2(fn))(qenv(fn), v0181, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-5];
    fn = elt(env, 4); /* !*n2f */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-5];
    {
        Lisp_Object v0277 = stack[0];
        popv(6);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0277, v0212);
    }

v0136:
    v0212 = stack[-2];
    v0181 = qcar(v0212);
    v0212 = stack[0];
    v0212 = cons(v0181, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-5];
    stack[0] = v0212;
    v0212 = stack[-2];
    v0212 = qcdr(v0212);
    stack[-2] = v0212;
    goto v0043;

v0064:
    v0212 = qvalue(elt(env, 1)); /* t */
    goto v0168;

v0003:
    v0212 = stack[-2];
    if (!consp(v0212)) goto v0175;
    v0212 = stack[-2];
    v0212 = qcar(v0212);
    v0212 = (consp(v0212) ? nil : lisp_true);
    goto v0278;

v0278:
    if (v0212 == nil) goto v0173;
    v0212 = stack[-3];
    v0181 = qcar(v0212);
    v0212 = stack[0];
    v0212 = cons(v0181, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-5];
    stack[0] = v0212;
    v0212 = stack[-3];
    v0212 = qcdr(v0212);
    stack[-3] = v0212;
    goto v0043;

v0173:
    v0212 = stack[-3];
    v0212 = qcar(v0212);
    v0181 = qcar(v0212);
    v0212 = stack[-2];
    v0212 = qcar(v0212);
    v0212 = qcar(v0212);
    if (equal(v0181, v0212)) goto v0279;
    v0212 = stack[-3];
    v0212 = qcar(v0212);
    v0212 = qcar(v0212);
    v0181 = qcar(v0212);
    v0212 = stack[-2];
    v0212 = qcar(v0212);
    v0212 = qcar(v0212);
    v0212 = qcar(v0212);
    if (equal(v0181, v0212)) goto v0280;
    v0212 = qvalue(elt(env, 2)); /* nil */
    goto v0281;

v0281:
    if (!(v0212 == nil)) goto v0282;
    v0212 = stack[-3];
    v0212 = qcar(v0212);
    v0212 = qcar(v0212);
    v0181 = qcar(v0212);
    v0212 = stack[-2];
    v0212 = qcar(v0212);
    v0212 = qcar(v0212);
    v0212 = qcar(v0212);
    if (equal(v0181, v0212)) goto v0216;
    v0212 = stack[-3];
    v0212 = qcar(v0212);
    v0212 = qcar(v0212);
    v0181 = qcar(v0212);
    v0212 = stack[-2];
    v0212 = qcar(v0212);
    v0212 = qcar(v0212);
    v0212 = qcar(v0212);
    fn = elt(env, 6); /* ordop */
    v0212 = (*qfn2(fn))(qenv(fn), v0181, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-5];
    goto v0106;

v0106:
    if (!(v0212 == nil)) goto v0282;
    v0212 = stack[-2];
    v0181 = qcar(v0212);
    v0212 = stack[0];
    v0212 = cons(v0181, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-5];
    stack[0] = v0212;
    v0212 = stack[-2];
    v0212 = qcdr(v0212);
    stack[-2] = v0212;
    goto v0043;

v0282:
    v0212 = stack[-3];
    v0181 = qcar(v0212);
    v0212 = stack[0];
    v0212 = cons(v0181, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-5];
    stack[0] = v0212;
    v0212 = stack[-3];
    v0212 = qcdr(v0212);
    stack[-3] = v0212;
    goto v0043;

v0216:
    v0212 = qvalue(elt(env, 2)); /* nil */
    goto v0106;

v0280:
    v0212 = stack[-3];
    v0212 = qcar(v0212);
    v0212 = qcar(v0212);
    v0181 = qcdr(v0212);
    v0212 = stack[-2];
    v0212 = qcar(v0212);
    v0212 = qcar(v0212);
    v0212 = qcdr(v0212);
    v0212 = ((intptr_t)v0181 > (intptr_t)v0212) ? lisp_true : nil;
    goto v0281;

v0279:
    stack[-4] = stack[0];
    v0212 = stack[-3];
    v0212 = qcar(v0212);
    stack[-1] = qcar(v0212);
    v0212 = stack[-3];
    v0212 = qcar(v0212);
    v0181 = qcdr(v0212);
    v0212 = stack[-2];
    v0212 = qcar(v0212);
    v0212 = qcdr(v0212);
    stack[0] = CC_generalKplusKmodKp(env, v0181, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-5];
    v0212 = stack[-3];
    v0181 = qcdr(v0212);
    v0212 = stack[-2];
    v0212 = qcdr(v0212);
    v0212 = CC_generalKplusKmodKp(env, v0181, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-5];
    fn = elt(env, 7); /* adjoin!-term */
    v0212 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0212);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-5];
    {
        Lisp_Object v0283 = stack[-4];
        popv(6);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0283, v0212);
    }

v0175:
    v0212 = qvalue(elt(env, 1)); /* t */
    goto v0278;

v0021:
    v0212 = qvalue(elt(env, 1)); /* t */
    goto v0035;

v0031:
    v0181 = stack[0];
    v0212 = stack[-3];
    {
        popv(6);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0181, v0212);
    }

v0027:
    v0181 = stack[0];
    v0212 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0181, v0212);
    }
/* error exit handlers */
v0206:
    popv(6);
    return nil;
}



/* Code for lalr_cached_goto */

static Lisp_Object CC_lalr_cached_goto(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0013;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_cached_goto");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0012 = v0029;
    v0013 = v0000;
/* end of prologue */
    stack[0] = v0013;
    v0013 = v0012;
    v0012 = qvalue(elt(env, 1)); /* goto_cache */
    fn = elt(env, 2); /* gethash */
    v0012 = (*qfn2(fn))(qenv(fn), v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    v0012 = Lassoc(nil, stack[0], v0012);
    v0012 = qcdr(v0012);
    { popv(1); return onevalue(v0012); }
/* error exit handlers */
v0015:
    popv(1);
    return nil;
}



/* Code for ofsf_vareqnp */

static Lisp_Object CC_ofsf_vareqnp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036, v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_vareqnp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0036 = v0029;
    v0051 = v0000;
/* end of prologue */
    v0036 = qcdr(v0036);
    v0036 = qcar(v0036);
    {
        fn = elt(env, 1); /* sfto_varisnump */
        return (*qfn1(fn))(qenv(fn), v0036);
    }
}



/* Code for wulessp */

static Lisp_Object CC_wulessp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0273;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wulessp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */
    v0273 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v0273 = (*qfn1(fn))(qenv(fn), v0273);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    if (v0273 == nil) goto v0012;
    v0273 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0273;
    goto v0019;

v0019:
    v0273 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v0273 = (*qfn1(fn))(qenv(fn), v0273);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    if (v0273 == nil) goto v0003;
    v0273 = qvalue(elt(env, 1)); /* nil */
    goto v0020;

v0020:
    fn = elt(env, 3); /* symbollessp */
    v0273 = (*qfn2(fn))(qenv(fn), stack[-2], v0273);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    if (!(v0273 == nil)) { popv(4); return onevalue(v0273); }
    v0273 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v0273 = (*qfn1(fn))(qenv(fn), v0273);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    if (v0273 == nil) goto v0017;
    v0273 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0273;
    goto v0137;

v0137:
    v0273 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v0273 = (*qfn1(fn))(qenv(fn), v0273);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    if (v0273 == nil) goto v0060;
    v0273 = qvalue(elt(env, 1)); /* nil */
    goto v0063;

v0063:
    if (equal(stack[-2], v0273)) goto v0234;
    v0273 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0273); }

v0234:
    v0273 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v0273 = (*qfn1(fn))(qenv(fn), v0273);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    if (v0273 == nil) goto v0166;
    v0273 = (Lisp_Object)1; /* 0 */
    stack[-1] = v0273;
    goto v0047;

v0047:
    v0273 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v0273 = (*qfn1(fn))(qenv(fn), v0273);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    if (v0273 == nil) goto v0284;
    v0273 = (Lisp_Object)1; /* 0 */
    goto v0048;

v0048:
    {
        Lisp_Object v0127 = stack[-1];
        popv(4);
        return Llessp(nil, v0127, v0273);
    }

v0284:
    v0273 = stack[0];
    v0273 = qcar(v0273);
    v0273 = qcar(v0273);
    v0273 = qcdr(v0273);
    goto v0048;

v0166:
    v0273 = stack[-1];
    v0273 = qcar(v0273);
    v0273 = qcar(v0273);
    v0273 = qcdr(v0273);
    stack[-1] = v0273;
    goto v0047;

v0060:
    v0273 = stack[0];
    v0273 = qcar(v0273);
    v0273 = qcar(v0273);
    v0273 = qcar(v0273);
    goto v0063;

v0017:
    v0273 = stack[-1];
    v0273 = qcar(v0273);
    v0273 = qcar(v0273);
    v0273 = qcar(v0273);
    stack[-2] = v0273;
    goto v0137;

v0003:
    v0273 = stack[0];
    v0273 = qcar(v0273);
    v0273 = qcar(v0273);
    v0273 = qcar(v0273);
    goto v0020;

v0012:
    v0273 = stack[-1];
    v0273 = qcar(v0273);
    v0273 = qcar(v0273);
    v0273 = qcar(v0273);
    stack[-2] = v0273;
    goto v0019;
/* error exit handlers */
v0126:
    popv(4);
    return nil;
}



/* Code for sort!-factors */

static Lisp_Object CC_sortKfactors(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sort-factors");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0020 = v0000;
/* end of prologue */
    v0030 = v0020;
    v0020 = elt(env, 1); /* orderfactors */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v0030, v0020);
    }
}



/* Code for ibalp_varlat */

static Lisp_Object CC_ibalp_varlat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_varlat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0007 = stack[0];
    fn = elt(env, 1); /* ibalp_arg2l */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    fn = elt(env, 2); /* ibalp_varlt */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    v0007 = stack[0];
    fn = elt(env, 3); /* ibalp_arg2r */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    fn = elt(env, 2); /* ibalp_varlt */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    {
        Lisp_Object v0011 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* union */
        return (*qfn2(fn))(qenv(fn), v0011, v0007);
    }
/* error exit handlers */
v0010:
    popv(3);
    return nil;
}



/* Code for ps!:evaluate */

static Lisp_Object CC_psTevaluate(Lisp_Object env,
                         Lisp_Object v0029, Lisp_Object v0061)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:evaluate");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0061,v0029);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0029,v0061);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0061;
    v0023 = v0029;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v0023; /* ps */
    v0024 = qvalue(elt(env, 1)); /* ps */
    v0023 = stack[-2];
    fn = elt(env, 3); /* ps!:get!-term */
    v0023 = (*qfn2(fn))(qenv(fn), v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-4];
    stack[-1] = v0023;
    v0023 = stack[-1];
    if (v0023 == nil) goto v0013;
    v0023 = stack[-1];
    goto v0043;

v0043:
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    { popv(5); return onevalue(v0023); }

v0013:
    v0023 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 4); /* ps!:last!-term */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-4];
    v0023 = add1(v0023);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-4];
    stack[0] = v0023;
    goto v0022;

v0022:
    v0024 = stack[-2];
    v0023 = stack[0];
    v0023 = difference2(v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-4];
    v0023 = Lminusp(nil, v0023);
    env = stack[-4];
    if (v0023 == nil) goto v0261;
    v0023 = stack[-1];
    goto v0043;

v0261:
    v0024 = qvalue(elt(env, 1)); /* ps */
    v0023 = stack[0];
    fn = elt(env, 5); /* ps!:evaluate!-next */
    v0023 = (*qfn2(fn))(qenv(fn), v0024, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-4];
    stack[-1] = v0023;
    v0023 = stack[0];
    v0023 = add1(v0023);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-4];
    stack[0] = v0023;
    goto v0022;
/* error exit handlers */
v0058:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    popv(5);
    return nil;
}



/* Code for difff */

static Lisp_Object CC_difff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118, v0119, v0120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for difff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0029;
    stack[-2] = v0000;
/* end of prologue */
    v0118 = stack[-2];
    if (!consp(v0118)) goto v0019;
    v0118 = stack[-2];
    v0118 = qcar(v0118);
    if (!consp(v0118)) goto v0014;
    v0118 = stack[-2];
    v0118 = qcar(v0118);
    v0119 = qcar(v0118);
    v0118 = (Lisp_Object)17; /* 1 */
    v0118 = cons(v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-4];
    v0119 = ncons(v0118);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-4];
    v0118 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-4];
    v0118 = stack[-2];
    v0118 = qcar(v0118);
    v0119 = qcdr(v0118);
    v0118 = stack[-1];
    v0118 = CC_difff(env, v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    stack[-3] = (*qfn2(fn))(qenv(fn), stack[0], v0118);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-4];
    v0118 = stack[-2];
    v0118 = qcar(v0118);
    v0119 = qcar(v0118);
    v0118 = stack[-1];
    fn = elt(env, 4); /* diffp */
    stack[0] = (*qfn2(fn))(qenv(fn), v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-4];
    v0118 = stack[-2];
    v0118 = qcar(v0118);
    v0119 = qcdr(v0118);
    v0118 = (Lisp_Object)17; /* 1 */
    v0118 = cons(v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    v0118 = (*qfn2(fn))(qenv(fn), stack[0], v0118);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-4];
    fn = elt(env, 5); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v0118);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-4];
    v0118 = stack[-2];
    v0119 = qcdr(v0118);
    v0118 = stack[-1];
    v0118 = CC_difff(env, v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-4];
    {
        Lisp_Object v0289 = stack[0];
        popv(5);
        fn = elt(env, 5); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0289, v0118);
    }

v0014:
    v0118 = stack[-2];
    v0119 = qcar(v0118);
    v0118 = elt(env, 2); /* domain!-diff!-fn */
    v0118 = get(v0119, v0118);
    env = stack[-4];
    v0119 = v0118;
    v0118 = v0119;
    if (v0118 == nil) goto v0168;
    v0120 = v0119;
    v0119 = stack[-2];
    v0118 = stack[-1];
        popv(5);
        return Lapply2(nil, 3, v0120, v0119, v0118);

v0168:
    v0119 = qvalue(elt(env, 1)); /* nil */
    v0118 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0119, v0118);

v0019:
    v0119 = qvalue(elt(env, 1)); /* nil */
    v0118 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0119, v0118);
/* error exit handlers */
v0158:
    popv(5);
    return nil;
}



/* Code for simp!* */

static Lisp_Object CC_simpH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0290, v0159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simp*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* !*asymp!* */
    qvalue(elt(env, 1)) = nil; /* !*asymp!* */
    v0159 = stack[-2];
    v0290 = elt(env, 2); /* !*sq */
    if (!consp(v0159)) goto v0021;
    v0159 = qcar(v0159);
    if (!(v0159 == v0290)) goto v0021;
    v0290 = stack[-2];
    v0290 = qcdr(v0290);
    v0290 = qcdr(v0290);
    v0290 = qcar(v0290);
    if (v0290 == nil) goto v0031;
    v0290 = qvalue(elt(env, 4)); /* !*resimp */
    v0290 = (v0290 == nil ? lisp_true : nil);
    goto v0030;

v0030:
    if (v0290 == nil) goto v0050;
    v0290 = stack[-2];
    v0290 = qcdr(v0290);
    v0290 = qcar(v0290);
    goto v0044;

v0044:
    qvalue(elt(env, 1)) = stack[-3]; /* !*asymp!* */
    { popv(5); return onevalue(v0290); }

v0050:
    v0159 = qvalue(elt(env, 5)); /* mul!* */
    v0290 = qvalue(elt(env, 6)); /* !*sub2 */
    v0290 = cons(v0159, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-4];
    stack[-1] = v0290;
    v0290 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 5)) = v0290; /* mul!* */
    v0290 = stack[-2];
    fn = elt(env, 14); /* simp */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-4];
    stack[-2] = v0290;
    v0290 = qvalue(elt(env, 7)); /* !*nospurp */
    if (v0290 == nil) goto v0038;
    v0159 = qvalue(elt(env, 5)); /* mul!* */
    v0290 = elt(env, 8); /* (isimpq) */
    fn = elt(env, 15); /* union */
    v0290 = (*qfn2(fn))(qenv(fn), v0159, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-4];
    qvalue(elt(env, 5)) = v0290; /* mul!* */
    goto v0038;

v0038:
    v0290 = qvalue(elt(env, 5)); /* mul!* */
    stack[0] = v0290;
    goto v0177;

v0177:
    v0290 = stack[0];
    if (v0290 == nil) goto v0060;
    v0290 = stack[0];
    v0290 = qcar(v0290);
    v0159 = v0290;
    v0290 = stack[-2];
    v0290 = Lapply1(nil, v0159, v0290);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-4];
    stack[-2] = v0290;
    v0290 = stack[0];
    v0290 = qcdr(v0290);
    stack[0] = v0290;
    goto v0177;

v0060:
    v0290 = stack[-1];
    v0290 = qcar(v0290);
    qvalue(elt(env, 5)) = v0290; /* mul!* */
    v0290 = stack[-2];
    fn = elt(env, 16); /* subs2 */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-4];
    stack[-2] = v0290;
    v0290 = qvalue(elt(env, 9)); /* !*combinelogs */
    if (v0290 == nil) goto v0273;
    v0290 = stack[-2];
    fn = elt(env, 17); /* clogsq!* */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-4];
    stack[-2] = v0290;
    goto v0273;

v0273:
    v0159 = qvalue(elt(env, 10)); /* dmode!* */
    v0290 = elt(env, 11); /* !:gi!: */
    if (v0159 == v0290) goto v0291;
    v0290 = qvalue(elt(env, 3)); /* nil */
    goto v0292;

v0292:
    if (v0290 == nil) goto v0128;
    v0290 = stack[-2];
    fn = elt(env, 18); /* girationalize!: */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-4];
    stack[-2] = v0290;
    goto v0232;

v0232:
    v0290 = stack[-1];
    v0290 = qcdr(v0290);
    qvalue(elt(env, 6)) = v0290; /* !*sub2 */
    v0290 = qvalue(elt(env, 1)); /* !*asymp!* */
    if (v0290 == nil) goto v0293;
    v0290 = qvalue(elt(env, 13)); /* !*rationalize */
    if (v0290 == nil) goto v0293;
    v0290 = stack[-2];
    fn = elt(env, 19); /* gcdchk */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-4];
    stack[-2] = v0290;
    goto v0293;

v0293:
    v0290 = stack[-2];
    goto v0044;

v0128:
    v0290 = qvalue(elt(env, 13)); /* !*rationalize */
    if (v0290 == nil) goto v0294;
    v0290 = stack[-2];
    fn = elt(env, 20); /* rationalizesq */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-4];
    stack[-2] = v0290;
    goto v0232;

v0294:
    v0290 = stack[-2];
    fn = elt(env, 21); /* rationalizei */
    v0290 = (*qfn1(fn))(qenv(fn), v0290);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-4];
    stack[-2] = v0290;
    goto v0232;

v0291:
    v0290 = qvalue(elt(env, 12)); /* !*norationalgi */
    v0290 = (v0290 == nil ? lisp_true : nil);
    goto v0292;

v0031:
    v0290 = qvalue(elt(env, 3)); /* nil */
    goto v0030;

v0021:
    v0290 = qvalue(elt(env, 3)); /* nil */
    goto v0030;
/* error exit handlers */
v0223:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* !*asymp!* */
    popv(5);
    return nil;
}



/* Code for symtabget */

static Lisp_Object CC_symtabget(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0168, v0064, v0065, v0037;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for symtabget");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0065 = v0029;
    v0064 = v0000;
/* end of prologue */
    v0168 = v0065;
    if (v0168 == nil) goto v0005;
    v0168 = v0064;
    if (!(v0168 == nil)) goto v0019;
    v0168 = qvalue(elt(env, 1)); /* !*symboltable!* */
    v0168 = qcar(v0168);
    goto v0019;

v0019:
    v0064 = v0168;
    goto v0005;

v0005:
    v0168 = v0064;
    if (v0168 == nil) goto v0009;
    v0168 = v0065;
    v0037 = elt(env, 2); /* (!*type!* !*params!* !*decs!*) */
    v0168 = Lmemq(nil, v0168, v0037);
    if (v0168 == nil) goto v0028;
    v0168 = v0064;
    v0064 = v0065;
    return get(v0168, v0064);

v0028:
    v0168 = v0065;
    if (!symbolp(v0064)) v0064 = nil;
    else { v0064 = qfastgets(v0064);
           if (v0064 != nil) { v0064 = elt(v0064, 58); /* !*decs!* */
#ifdef RECORD_GET
             if (v0064 != SPID_NOPROP)
                record_get(elt(fastget_names, 58), 1);
             else record_get(elt(fastget_names, 58), 0),
                v0064 = nil; }
           else record_get(elt(fastget_names, 58), 0); }
#else
             if (v0064 == SPID_NOPROP) v0064 = nil; }}
#endif
    v0168 = Lassoc(nil, v0168, v0064);
    return onevalue(v0168);

v0009:
    v0168 = qvalue(elt(env, 1)); /* !*symboltable!* */
    return onevalue(v0168);
}



/* Code for groebcpcompless!? */

static Lisp_Object CC_groebcpcomplessW(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0173, v0174, v0259, v0295;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebcpcompless?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */
    v0173 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v0173 == nil) goto v0292;
    v0173 = stack[-1];
    v0173 = qcdr(v0173);
    v0173 = qcdr(v0173);
    v0173 = qcdr(v0173);
    v0174 = qcar(v0173);
    v0173 = stack[0];
    v0173 = qcdr(v0173);
    v0173 = qcdr(v0173);
    v0173 = qcdr(v0173);
    v0173 = qcar(v0173);
    stack[-2] = difference2(v0174, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-3];
    v0173 = stack[-1];
    v0174 = qcar(v0173);
    v0173 = stack[0];
    v0173 = qcar(v0173);
    fn = elt(env, 3); /* vevcomp */
    v0173 = (*qfn2(fn))(qenv(fn), v0174, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-3];
    v0295 = stack[-2];
    v0259 = v0173;
    v0174 = v0295;
    v0173 = (Lisp_Object)1; /* 0 */
    if (v0174 == v0173) goto v0023;
    v0174 = v0295;
    v0173 = (Lisp_Object)1; /* 0 */
        popv(4);
        return Llessp(nil, v0174, v0173);

v0023:
    v0174 = v0259;
    v0173 = (Lisp_Object)1; /* 0 */
    if (v0174 == v0173) goto v0132;
    v0174 = v0259;
    v0173 = (Lisp_Object)1; /* 0 */
        popv(4);
        return Llessp(nil, v0174, v0173);

v0132:
    v0173 = stack[-1];
    v0173 = qcdr(v0173);
    v0173 = qcdr(v0173);
    v0174 = qcar(v0173);
    v0173 = elt(env, 2); /* number */
    fn = elt(env, 4); /* vdpgetprop */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0174, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-3];
    v0173 = stack[0];
    v0173 = qcdr(v0173);
    v0173 = qcdr(v0173);
    v0174 = qcar(v0173);
    v0173 = elt(env, 2); /* number */
    fn = elt(env, 4); /* vdpgetprop */
    v0173 = (*qfn2(fn))(qenv(fn), v0174, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    {
        Lisp_Object v0121 = stack[-1];
        popv(4);
        return Llessp(nil, v0121, v0173);
    }

v0292:
    v0173 = stack[-1];
    v0174 = qcar(v0173);
    v0173 = stack[0];
    v0173 = qcar(v0173);
    {
        popv(4);
        fn = elt(env, 5); /* vevcompless!? */
        return (*qfn2(fn))(qenv(fn), v0174, v0173);
    }
/* error exit handlers */
v0162:
    popv(4);
    return nil;
}



/* Code for add2inputbuf */

static Lisp_Object CC_add2inputbuf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0046, v0022, v0138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add2inputbuf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */
    fn = elt(env, 6); /* terminalp */
    v0046 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-2];
    if (v0046 == nil) goto v0030;
    v0046 = qvalue(elt(env, 2)); /* !*nosave!* */
    goto v0020;

v0020:
    if (v0046 == nil) goto v0002;
    v0046 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v0046); }

v0002:
    v0138 = qvalue(elt(env, 4)); /* statcounter */
    v0022 = stack[0];
    v0046 = stack[-1];
    v0022 = list3(v0138, v0022, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-2];
    v0046 = qvalue(elt(env, 5)); /* inputbuflis!* */
    v0046 = cons(v0022, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-2];
    qvalue(elt(env, 5)) = v0046; /* inputbuflis!* */
    v0046 = nil;
    { popv(3); return onevalue(v0046); }

v0030:
    v0046 = qvalue(elt(env, 1)); /* t */
    goto v0020;
/* error exit handlers */
v0050:
    popv(3);
    return nil;
}



/* Code for simpplus */

static Lisp_Object CC_simpplus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0063, v0239;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpplus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0063 = stack[0];
    v0239 = Llength(nil, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-2];
    v0063 = (Lisp_Object)33; /* 2 */
    if (!(v0239 == v0063)) goto v0014;
    v0063 = stack[0];
    fn = elt(env, 2); /* ckpreci!# */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-2];
    goto v0014;

v0014:
    v0239 = qvalue(elt(env, 1)); /* nil */
    v0063 = (Lisp_Object)17; /* 1 */
    v0063 = cons(v0239, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-2];
    stack[-1] = v0063;
    goto v0044;

v0044:
    v0063 = stack[0];
    if (v0063 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0063 = stack[0];
    fn = elt(env, 3); /* simpcar */
    v0239 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-2];
    v0063 = stack[-1];
    fn = elt(env, 4); /* addsq */
    v0063 = (*qfn2(fn))(qenv(fn), v0239, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-2];
    stack[-1] = v0063;
    v0063 = stack[0];
    v0063 = qcdr(v0063);
    stack[0] = v0063;
    goto v0044;
/* error exit handlers */
v0168:
    popv(3);
    return nil;
}



/* Code for divd */

static Lisp_Object CC_divd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0173, v0174, v0259;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for divd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0029;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0043;

v0043:
    v0173 = stack[-1];
    if (v0173 == nil) goto v0019;
    v0173 = stack[-2];
    if (v0173 == nil) goto v0178;
    v0173 = stack[-2];
    if (!consp(v0173)) goto v0039;
    v0173 = stack[-2];
    v0173 = qcar(v0173);
    v0173 = (consp(v0173) ? nil : lisp_true);
    goto v0058;

v0058:
    if (v0173 == nil) goto v0278;
    stack[0] = stack[-3];
    v0174 = stack[-2];
    v0173 = stack[-1];
    fn = elt(env, 5); /* divdm */
    v0173 = (*qfn2(fn))(qenv(fn), v0174, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-4];
    {
        Lisp_Object v0121 = stack[0];
        popv(5);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0121, v0173);
    }

v0278:
    v0173 = stack[-2];
    v0173 = qcar(v0173);
    stack[0] = qcar(v0173);
    v0173 = stack[-2];
    v0173 = qcar(v0173);
    v0174 = qcdr(v0173);
    v0173 = stack[-1];
    v0174 = CC_divd(env, v0174, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-4];
    v0173 = stack[-3];
    v0173 = acons(stack[0], v0174, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-4];
    stack[-3] = v0173;
    v0173 = stack[-2];
    v0173 = qcdr(v0173);
    stack[-2] = v0173;
    goto v0043;

v0039:
    v0173 = qvalue(elt(env, 4)); /* t */
    goto v0058;

v0178:
    v0173 = stack[-3];
    {
        popv(5);
        fn = elt(env, 6); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0173);
    }

v0019:
    v0173 = stack[-2];
    if (v0173 == nil) goto v0011;
    stack[0] = stack[-3];
    v0259 = elt(env, 1); /* poly */
    v0174 = (Lisp_Object)33; /* 2 */
    v0173 = elt(env, 3); /* "Zero divisor" */
    fn = elt(env, 7); /* rerror */
    v0173 = (*qfnn(fn))(qenv(fn), 3, v0259, v0174, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-4];
    {
        Lisp_Object v0123 = stack[0];
        popv(5);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0123, v0173);
    }

v0011:
    stack[0] = stack[-3];
    v0259 = elt(env, 1); /* poly */
    v0174 = (Lisp_Object)17; /* 1 */
    v0173 = elt(env, 2); /* "0/0 formed" */
    fn = elt(env, 7); /* rerror */
    v0173 = (*qfnn(fn))(qenv(fn), 3, v0259, v0174, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-4];
    {
        Lisp_Object v0229 = stack[0];
        popv(5);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0229, v0173);
    }
/* error exit handlers */
v0162:
    popv(5);
    return nil;
}



/* Code for divide!: */

static Lisp_Object MS_CDECL CC_divideT(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0060, v0177;
    Lisp_Object fn;
    Lisp_Object v0061, v0029, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "divide:");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0029 = va_arg(aa, Lisp_Object);
    v0061 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for divide:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0061,v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0029,v0061);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0061;
    stack[-2] = v0029;
    stack[-3] = v0000;
/* end of prologue */
    stack[0] = stack[-1];
    v0060 = stack[-2];
    v0060 = qcdr(v0060);
    v0060 = qcar(v0060);
    v0060 = Labsval(nil, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    fn = elt(env, 2); /* msd */
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    v0060 = add1(v0060);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    v0060 = plus2(stack[0], v0060);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    fn = elt(env, 3); /* conv!:mt */
    v0060 = (*qfn2(fn))(qenv(fn), stack[-3], v0060);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    stack[-3] = v0060;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v0060 = stack[-3];
    v0060 = qcdr(v0060);
    v0177 = qcar(v0060);
    v0060 = stack[-2];
    v0060 = qcdr(v0060);
    v0060 = qcar(v0060);
    stack[0] = quot2(v0177, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    v0060 = stack[-3];
    v0060 = qcdr(v0060);
    v0177 = qcdr(v0060);
    v0060 = stack[-2];
    v0060 = qcdr(v0060);
    v0060 = qcdr(v0060);
    v0060 = difference2(v0177, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    v0060 = list2star(stack[-4], stack[0], v0060);
    nil = C_nil;
    if (exception_pending()) goto v0234;
    env = stack[-5];
    stack[-3] = v0060;
    v0177 = stack[-3];
    v0060 = stack[-1];
    {
        popv(6);
        fn = elt(env, 4); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v0177, v0060);
    }
/* error exit handlers */
v0234:
    popv(6);
    return nil;
}



/* Code for reduce!-mod!-p */

static Lisp_Object CC_reduceKmodKp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    v0137 = stack[-1];
    if (v0137 == nil) goto v0005;
    v0137 = stack[-1];
    if (!consp(v0137)) goto v0052;
    v0137 = stack[-1];
    v0137 = qcar(v0137);
    v0137 = (consp(v0137) ? nil : lisp_true);
    goto v0030;

v0030:
    if (v0137 == nil) goto v0001;
    v0137 = stack[-1];
    v0137 = Lmodular_number(nil, v0137);
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 3); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v0137);
    }

v0001:
    v0137 = stack[-1];
    v0137 = qcar(v0137);
    stack[-2] = qcar(v0137);
    v0137 = stack[-1];
    v0137 = qcar(v0137);
    v0137 = qcdr(v0137);
    stack[0] = CC_reduceKmodKp(env, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-3];
    v0137 = stack[-1];
    v0137 = qcdr(v0137);
    v0137 = CC_reduceKmodKp(env, v0137);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-3];
    {
        Lisp_Object v0168 = stack[-2];
        Lisp_Object v0064 = stack[0];
        popv(4);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0168, v0064, v0137);
    }

v0052:
    v0137 = qvalue(elt(env, 2)); /* t */
    goto v0030;

v0005:
    v0137 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0137); }
/* error exit handlers */
v0062:
    popv(4);
    return nil;
}



/* Code for lalr_print_items */

static Lisp_Object CC_lalr_print_items(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0117, v0114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_print_items");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    v0117 = v0000;
/* end of prologue */
    v0117 = Lprinc(nil, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    v0117 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    v0117 = stack[0];
    stack[-6] = v0117;
    goto v0030;

v0030:
    v0117 = stack[-6];
    if (v0117 == nil) goto v0020;
    v0117 = stack[-6];
    v0117 = qcar(v0117);
    stack[-5] = v0117;
    v0117 = elt(env, 2); /* "Item number " */
    v0117 = Lprinc(nil, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    v0117 = stack[-5];
    v0117 = qcdr(v0117);
    v0117 = Lprin(nil, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    v0117 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    v0117 = stack[-5];
    v0114 = qcar(v0117);
    v0117 = elt(env, 3); /* ordp */
    fn = elt(env, 9); /* sort */
    v0117 = (*qfn2(fn))(qenv(fn), v0114, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    stack[-3] = v0117;
    goto v0034;

v0034:
    v0117 = stack[-3];
    if (v0117 == nil) goto v0033;
    v0117 = stack[-3];
    v0117 = qcar(v0117);
    stack[-2] = v0117;
    v0117 = stack[-2];
    v0117 = qcar(v0117);
    v0117 = qcar(v0117);
    fn = elt(env, 10); /* lalr_prin_symbol */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    v0117 = elt(env, 4); /* " ->" */
    v0117 = Lprinc(nil, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    v0117 = stack[-2];
    v0117 = qcar(v0117);
    v0117 = qcdr(v0117);
    stack[-1] = v0117;
    goto v0025;

v0025:
    v0117 = stack[-1];
    if (v0117 == nil) goto v0024;
    v0117 = stack[-1];
    v0117 = qcar(v0117);
    stack[0] = v0117;
    v0117 = elt(env, 5); /* " " */
    v0117 = Lprinc(nil, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    v0117 = stack[0];
    fn = elt(env, 10); /* lalr_prin_symbol */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    v0117 = stack[-1];
    v0117 = qcdr(v0117);
    stack[-1] = v0117;
    goto v0025;

v0024:
    v0117 = elt(env, 6); /* "  :  " */
    v0117 = Lprinc(nil, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    v0117 = stack[-2];
    v0117 = qcdr(v0117);
    v0117 = qcar(v0117);
    fn = elt(env, 10); /* lalr_prin_symbol */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    v0117 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    v0117 = stack[-3];
    v0117 = qcdr(v0117);
    stack[-3] = v0117;
    goto v0034;

v0033:
    v0117 = qvalue(elt(env, 7)); /* goto_cache */
    fn = elt(env, 11); /* hashcontents */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    stack[-4] = v0117;
    goto v0275;

v0275:
    v0117 = stack[-4];
    if (v0117 == nil) goto v0228;
    v0117 = stack[-4];
    v0117 = qcar(v0117);
    stack[-3] = v0117;
    v0117 = stack[-3];
    v0117 = qcdr(v0117);
    stack[-2] = v0117;
    goto v0292;

v0292:
    v0117 = stack[-2];
    if (v0117 == nil) goto v0129;
    v0117 = stack[-2];
    v0117 = qcar(v0117);
    stack[-1] = v0117;
    v0117 = stack[-1];
    v0114 = qcar(v0117);
    v0117 = stack[-5];
    v0117 = qcdr(v0117);
    if (!(equal(v0114, v0117))) goto v0179;
    stack[0] = (Lisp_Object)161; /* 10 */
    v0117 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    v0117 = difference2(stack[0], v0117);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    v0117 = Lxtab(nil, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    v0117 = stack[-3];
    v0117 = qcar(v0117);
    fn = elt(env, 10); /* lalr_prin_symbol */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    v0117 = elt(env, 8); /* " GOTO state " */
    v0117 = Lprinc(nil, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    v0117 = stack[-1];
    v0117 = qcdr(v0117);
    v0117 = Lprin(nil, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    v0117 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-7];
    goto v0179;

v0179:
    v0117 = stack[-2];
    v0117 = qcdr(v0117);
    stack[-2] = v0117;
    goto v0292;

v0129:
    v0117 = stack[-4];
    v0117 = qcdr(v0117);
    stack[-4] = v0117;
    goto v0275;

v0228:
    v0117 = stack[-6];
    v0117 = qcdr(v0117);
    stack[-6] = v0117;
    goto v0030;

v0020:
    v0117 = nil;
    { popv(8); return onevalue(v0117); }
/* error exit handlers */
v0258:
    popv(8);
    return nil;
}



/* Code for anforml */

static Lisp_Object CC_anforml(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0176, v0288;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for anforml");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */

v0043:
    v0176 = stack[0];
    if (!consp(v0176)) goto v0044;
    v0176 = stack[0];
    v0176 = qcar(v0176);
    fn = elt(env, 6); /* anform */
    v0176 = (*qfn1(fn))(qenv(fn), v0176);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-1];
    v0176 = stack[0];
    v0176 = qcdr(v0176);
    stack[0] = v0176;
    goto v0043;

v0044:
    v0176 = stack[0];
    if (v0176 == nil) goto v0012;
    v0176 = qvalue(elt(env, 2)); /* !*globals */
    if (v0176 == nil) goto v0012;
    v0176 = stack[0];
    if (v0176 == nil) goto v0012;
    v0288 = stack[0];
    v0176 = lisp_true;
    if (v0288 == v0176) goto v0057;
    v0176 = stack[0];
    if (symbolp(v0176)) goto v0037;
    v0176 = qvalue(elt(env, 1)); /* nil */
    goto v0035;

v0035:
    if (v0176 == nil) goto v0012;
    v0288 = stack[0];
    v0176 = elt(env, 4); /* glb2rf */
    v0176 = Lflagp(nil, v0288, v0176);
    env = stack[-1];
    if (!(v0176 == nil)) goto v0012;
    v0176 = stack[0];
    v0288 = ncons(v0176);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-1];
    v0176 = elt(env, 4); /* glb2rf */
    v0176 = Lflag(nil, v0288, v0176);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-1];
    v0288 = stack[0];
    v0176 = qvalue(elt(env, 5)); /* globs!* */
    v0176 = cons(v0288, v0176);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-1];
    qvalue(elt(env, 5)) = v0176; /* globs!* */
    goto v0012;

v0012:
    v0176 = nil;
    { popv(2); return onevalue(v0176); }

v0037:
    v0288 = stack[0];
    v0176 = qvalue(elt(env, 3)); /* locls!* */
    v0176 = Lassoc(nil, v0288, v0176);
    v0176 = (v0176 == nil ? lisp_true : nil);
    goto v0035;

v0057:
    v0176 = qvalue(elt(env, 1)); /* nil */
    goto v0035;
/* error exit handlers */
v0131:
    popv(2);
    return nil;
}



/* Code for ofsf_posvarpat */

static Lisp_Object CC_ofsf_posvarpat(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0137, v0063, v0239;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_posvarpat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    v0239 = v0000;
/* end of prologue */
    v0137 = v0239;
    if (!consp(v0137)) goto v0051;
    v0137 = v0239;
    v0137 = qcar(v0137);
    goto v0036;

v0036:
    stack[-1] = v0137;
    v0063 = stack[-1];
    v0137 = elt(env, 1); /* (greaterp geq) */
    v0137 = Lmemq(nil, v0063, v0137);
    if (v0137 == nil) goto v0011;
    v0137 = v0239;
    v0137 = qcdr(v0137);
    v0137 = qcar(v0137);
    fn = elt(env, 3); /* sfto_varp */
    v0063 = (*qfn1(fn))(qenv(fn), v0137);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    v0137 = stack[0];
    if (v0063 == v0137) { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
    v0137 = nil;
    { popv(2); return onevalue(v0137); }

v0011:
    v0137 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0137); }

v0051:
    v0137 = v0239;
    goto v0036;
/* error exit handlers */
v0168:
    popv(2);
    return nil;
}



/* Code for polynomclone */

static Lisp_Object CC_polynomclone(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0003;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for polynomclone");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0034 = v0000;
/* end of prologue */
    stack[-1] = nil;
    stack[0] = v0034;
    goto v0019;

v0019:
    v0034 = stack[0];
    if (v0034 == nil) goto v0051;
    v0034 = stack[0];
    v0034 = qcar(v0034);
    fn = elt(env, 2); /* monomclone */
    v0003 = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-2];
    v0034 = stack[-1];
    v0034 = cons(v0003, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-2];
    stack[-1] = v0034;
    v0034 = stack[0];
    v0034 = qcdr(v0034);
    stack[0] = v0034;
    goto v0019;

v0051:
    v0034 = stack[-1];
        popv(3);
        return Lreverse(nil, v0034);
/* error exit handlers */
v0021:
    popv(3);
    return nil;
}



/* Code for ordpa */

static Lisp_Object CC_ordpa(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0126, v0127, v0173, v0174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordpa");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0127 = v0029;
    v0173 = v0000;
/* end of prologue */

v0044:
    v0126 = v0173;
    if (v0126 == nil) goto v0051;
    v0126 = v0127;
    if (v0126 == nil) goto v0027;
    v0126 = v0173;
    v0126 = Lsimple_vectorp(nil, v0126);
    env = stack[0];
    if (v0126 == nil) goto v0011;
    v0126 = v0127;
    v0126 = Lsimple_vectorp(nil, v0126);
    env = stack[0];
    if (v0126 == nil) goto v0021;
    v0126 = v0173;
    {
        popv(1);
        fn = elt(env, 3); /* ordpv */
        return (*qfn2(fn))(qenv(fn), v0126, v0127);
    }

v0021:
    v0126 = v0127;
    v0126 = (consp(v0126) ? nil : lisp_true);
    { popv(1); return onevalue(v0126); }

v0011:
    v0126 = v0173;
    if (!consp(v0126)) goto v0138;
    v0126 = v0127;
    if (!consp(v0126)) goto v0165;
    v0126 = v0173;
    v0174 = qcar(v0126);
    v0126 = v0127;
    v0126 = qcar(v0126);
    if (equal(v0174, v0126)) goto v0278;
    v0126 = v0173;
    v0126 = qcar(v0126);
    v0173 = v0126;
    v0126 = v0127;
    v0126 = qcar(v0126);
    v0127 = v0126;
    goto v0044;

v0278:
    v0126 = v0173;
    v0126 = qcdr(v0126);
    v0173 = v0126;
    v0126 = v0127;
    v0126 = qcdr(v0126);
    v0127 = v0126;
    goto v0044;

v0165:
    v0126 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v0126); }

v0138:
    v0126 = v0127;
    if (!consp(v0126)) goto v0137;
    v0126 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0126); }

v0137:
    v0126 = v0173;
    if (is_number(v0126)) goto v0168;
    v0126 = v0127;
    if (symbolp(v0126)) goto v0042;
    v0126 = v0127;
    v0126 = (is_number(v0126) ? lisp_true : nil);
    { popv(1); return onevalue(v0126); }

v0042:
    v0126 = v0173;
        popv(1);
        return Lorderp(nil, v0126, v0127);

v0168:
    v0126 = v0127;
    if (is_number(v0126)) goto v0024;
    v0126 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0126); }

v0024:
    v0126 = v0173;
    v0126 = (Lisp_Object)lessp2(v0126, v0127);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    v0126 = v0126 ? lisp_true : nil;
    v0126 = (v0126 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v0126); }

v0027:
    v0126 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v0126); }

v0051:
    v0126 = v0127;
    v0126 = (v0126 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v0126); }
/* error exit handlers */
v0259:
    popv(1);
    return nil;
}



/* Code for wuorderp */

static Lisp_Object CC_wuorderp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0259, v0295, v0179, v0180, v0286, v0162;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wuorderp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0286 = v0029;
    v0162 = v0000;
/* end of prologue */
    v0179 = nil;
    v0295 = v0162;
    v0259 = v0286;
    if (v0295 == v0259) goto v0019;
    v0259 = qvalue(elt(env, 2)); /* wukord!* */
    v0180 = v0259;
    goto v0015;

v0015:
    v0259 = v0180;
    if (v0259 == nil) goto v0014;
    v0259 = v0179;
    if (!(v0259 == nil)) goto v0014;
    v0295 = v0162;
    v0259 = v0180;
    v0259 = qcar(v0259);
    if (v0295 == v0259) goto v0062;
    v0295 = v0286;
    v0259 = v0180;
    v0259 = qcar(v0259);
    if (v0295 == v0259) goto v0235;
    v0259 = v0180;
    v0259 = qcdr(v0259);
    v0180 = v0259;
    goto v0015;

v0235:
    v0295 = v0162;
    v0259 = v0180;
    v0259 = qcdr(v0259);
    v0259 = Lmemq(nil, v0295, v0259);
    if (v0259 == nil) goto v0276;
    v0259 = elt(env, 4); /* no */
    goto v0149;

v0149:
    v0179 = v0259;
    goto v0015;

v0276:
    v0259 = elt(env, 3); /* yes */
    goto v0149;

v0062:
    v0295 = v0286;
    v0259 = v0180;
    v0259 = qcdr(v0259);
    v0259 = Lmemq(nil, v0295, v0259);
    if (v0259 == nil) goto v0024;
    v0259 = elt(env, 3); /* yes */
    goto v0063;

v0063:
    v0179 = v0259;
    goto v0015;

v0024:
    v0259 = elt(env, 4); /* no */
    goto v0063;

v0014:
    v0259 = v0179;
    if (v0259 == nil) goto v0273;
    v0259 = v0179;
    v0295 = elt(env, 3); /* yes */
    v0259 = (v0259 == v0295 ? lisp_true : nil);
    return onevalue(v0259);

v0273:
    v0259 = v0162;
    v0295 = v0286;
    v0259 = Lorderp(nil, v0259, v0295);
    errexit();
    v0259 = (v0259 == nil ? lisp_true : nil);
    return onevalue(v0259);

v0019:
    v0259 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0259);
}



/* Code for rl_prepat */

static Lisp_Object CC_rl_prepat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_prepat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0030 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_prepat!* */
    v0030 = ncons(v0030);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-1];
    {
        Lisp_Object v0007 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0007, v0030);
    }
/* error exit handlers */
v0027:
    popv(2);
    return nil;
}



/* Code for xxsort */

static Lisp_Object CC_xxsort(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xxsort");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0020 = v0000;
/* end of prologue */
    v0030 = v0020;
    v0020 = elt(env, 1); /* lambda_n4e0tj_1 */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v0030, v0020);
    }
}



/* Code for lambda_n4e0tj_1 */

static Lisp_Object CC_lambda_n4e0tj_1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0014;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_n4e0tj_1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0013 = v0029;
    v0014 = v0000;
/* end of prologue */
    v0014 = qcar(v0014);
    v0013 = qcar(v0013);
    fn = elt(env, 1); /* termorder */
    v0014 = (*qfn2(fn))(qenv(fn), v0014, v0013);
    errexit();
    v0013 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v0014, v0013);
}



/* Code for ev_comp */

static Lisp_Object CC_ev_comp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011, v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev_comp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0011 = v0029;
    v0012 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dip_sortevcomp!* */
    v0011 = list2(v0012, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-1];
    {
        Lisp_Object v0015 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0015, v0011);
    }
/* error exit handlers */
v0014:
    popv(2);
    return nil;
}



/* Code for mintype */

static Lisp_Object CC_mintype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0027;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mintype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0052 = v0000;
/* end of prologue */
    v0027 = v0052;
    if (!consp(v0027)) return onevalue(v0052);
    v0052 = qcar(v0052);
    return onevalue(v0052);
}



/* Code for addpf */

static Lisp_Object CC_addpf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0111, v0110, v0092;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addpf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0029;
    stack[-2] = v0000;
/* end of prologue */
    stack[0] = nil;
    goto v0043;

v0043:
    v0111 = stack[-2];
    if (v0111 == nil) goto v0027;
    v0111 = stack[-1];
    if (v0111 == nil) goto v0031;
    v0111 = stack[-2];
    v0111 = qcar(v0111);
    v0110 = qcar(v0111);
    v0111 = (Lisp_Object)17; /* 1 */
    if (v0110 == v0111) goto v0064;
    v0111 = stack[-1];
    v0111 = qcar(v0111);
    v0110 = qcar(v0111);
    v0111 = (Lisp_Object)17; /* 1 */
    if (v0110 == v0111) goto v0047;
    v0111 = stack[-2];
    v0111 = qcar(v0111);
    v0110 = qcar(v0111);
    v0111 = stack[-1];
    v0111 = qcar(v0111);
    v0111 = qcar(v0111);
    if (equal(v0110, v0111)) goto v0164;
    v0111 = stack[-2];
    v0111 = qcar(v0111);
    v0110 = qcar(v0111);
    v0111 = stack[-1];
    v0111 = qcar(v0111);
    v0111 = qcar(v0111);
    fn = elt(env, 1); /* ordop */
    v0111 = (*qfn2(fn))(qenv(fn), v0110, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-4];
    if (v0111 == nil) goto v0300;
    v0111 = stack[-2];
    v0110 = qcar(v0111);
    v0111 = stack[0];
    v0111 = cons(v0110, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-4];
    stack[0] = v0111;
    v0111 = stack[-2];
    v0111 = qcdr(v0111);
    stack[-2] = v0111;
    goto v0043;

v0300:
    v0111 = stack[-1];
    v0110 = qcar(v0111);
    v0111 = stack[0];
    v0111 = cons(v0110, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-4];
    stack[0] = v0111;
    v0111 = stack[-1];
    v0111 = qcdr(v0111);
    stack[-1] = v0111;
    goto v0043;

v0164:
    stack[-3] = stack[0];
    v0111 = stack[-2];
    v0111 = qcar(v0111);
    v0110 = qcdr(v0111);
    v0111 = stack[-1];
    v0111 = qcar(v0111);
    v0111 = qcdr(v0111);
    fn = elt(env, 2); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v0110, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-4];
    v0111 = stack[-2];
    v0110 = qcdr(v0111);
    v0111 = stack[-1];
    v0111 = qcdr(v0111);
    v0111 = CC_addpf(env, v0110, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-4];
    v0110 = stack[0];
    v0092 = v0110;
    v0092 = qcar(v0092);
    if (v0092 == nil) goto v0231;
    v0092 = stack[-2];
    v0092 = qcar(v0092);
    v0092 = qcar(v0092);
    v0111 = acons(v0092, v0110, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-4];
    goto v0231;

v0231:
    {
        Lisp_Object v0222 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0222, v0111);
    }

v0047:
    v0110 = stack[-1];
    v0111 = stack[-2];
    fn = elt(env, 4); /* addmpf */
    v0111 = (*qfn2(fn))(qenv(fn), v0110, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-4];
    {
        Lisp_Object v0301 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0301, v0111);
    }

v0064:
    v0110 = stack[-2];
    v0111 = stack[-1];
    fn = elt(env, 4); /* addmpf */
    v0111 = (*qfn2(fn))(qenv(fn), v0110, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0221;
    env = stack[-4];
    {
        Lisp_Object v0255 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0255, v0111);
    }

v0031:
    v0110 = stack[0];
    v0111 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0110, v0111);
    }

v0027:
    v0110 = stack[0];
    v0111 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0110, v0111);
    }
/* error exit handlers */
v0221:
    popv(5);
    return nil;
}



/* Code for csl_timbf */

static Lisp_Object CC_csl_timbf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0302, v0285, v0041;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for csl_timbf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0029;
    stack[-3] = v0000;
/* end of prologue */
    v0302 = stack[-3];
    v0302 = qcdr(v0302);
    v0285 = qcar(v0302);
    v0302 = stack[-2];
    v0302 = qcdr(v0302);
    v0302 = qcar(v0302);
    v0302 = times2(v0285, v0302);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-5];
    v0041 = v0302;
    v0285 = v0041;
    v0302 = (Lisp_Object)1; /* 0 */
    if (v0285 == v0302) goto v0013;
    v0285 = v0041;
    v0302 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 4); /* inorm */
    v0302 = (*qfn2(fn))(qenv(fn), v0285, v0302);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-5];
    v0041 = v0302;
    stack[-4] = elt(env, 3); /* !:rd!: */
    v0302 = v0041;
    stack[-1] = qcar(v0302);
    v0302 = v0041;
    stack[0] = qcdr(v0302);
    v0302 = stack[-3];
    v0302 = qcdr(v0302);
    v0285 = qcdr(v0302);
    v0302 = stack[-2];
    v0302 = qcdr(v0302);
    v0302 = qcdr(v0302);
    v0302 = plus2(v0285, v0302);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-5];
    v0302 = plus2(stack[0], v0302);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    {
        Lisp_Object v0136 = stack[-4];
        Lisp_Object v0134 = stack[-1];
        popv(6);
        return list2star(v0136, v0134, v0302);
    }

v0013:
    v0302 = elt(env, 1); /* (!:rd!: 0 . 0) */
    { popv(6); return onevalue(v0302); }
/* error exit handlers */
v0048:
    popv(6);
    return nil;
}



/* Code for evaluate0 */

static Lisp_Object CC_evaluate0(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0027;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evaluate0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    v0052 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* evaluate!-horner */
    v0027 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    v0052 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* evaluate1 */
        return (*qfn2(fn))(qenv(fn), v0027, v0052);
    }
/* error exit handlers */
v0008:
    popv(2);
    return nil;
}



/* Code for sroad */

static Lisp_Object MS_CDECL CC_sroad(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0178, v0018;
    Lisp_Object fn;
    Lisp_Object v0061, v0029, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sroad");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0029 = va_arg(aa, Lisp_Object);
    v0061 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sroad");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0061,v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0029,v0061);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0061;
    stack[-1] = v0029;
    stack[-2] = v0000;
/* end of prologue */
    v0018 = nil;
    goto v0036;

v0036:
    v0017 = stack[0];
    if (v0017 == nil) goto v0020;
    v0178 = stack[-2];
    v0017 = stack[0];
    v0017 = qcar(v0017);
    if (equal(v0178, v0017)) goto v0002;
    v0017 = stack[0];
    v0017 = qcar(v0017);
    v0178 = v0018;
    v0017 = cons(v0017, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-3];
    v0018 = v0017;
    v0017 = stack[0];
    v0017 = qcdr(v0017);
    stack[0] = v0017;
    goto v0036;

v0002:
    stack[-2] = v0018;
    v0178 = stack[-1];
    v0017 = stack[0];
    v0017 = qcdr(v0017);
    v0017 = Lappend(nil, v0178, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-3];
    {
        Lisp_Object v0057 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0057, v0017);
    }

v0020:
    v0017 = v0018;
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0017);
    }
/* error exit handlers */
v0167:
    popv(4);
    return nil;
}



/* Code for formc */

static Lisp_Object MS_CDECL CC_formc(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0136, v0134, v0135, v0132;
    Lisp_Object fn;
    Lisp_Object v0061, v0029, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formc");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0029 = va_arg(aa, Lisp_Object);
    v0061 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0061,v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0029,v0061);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0061;
    stack[-1] = v0029;
    stack[-2] = v0000;
/* end of prologue */
    v0136 = qvalue(elt(env, 1)); /* !*rlisp88 */
    if (v0136 == nil) goto v0055;
    v0134 = stack[-2];
    v0136 = elt(env, 2); /* modefn */
    v0136 = Lflagpcar(nil, v0134, v0136);
    env = stack[-3];
    if (v0136 == nil) goto v0055;
    v0136 = stack[-2];
    v0134 = qcar(v0136);
    v0136 = elt(env, 3); /* symbolic */
    if (v0134 == v0136) goto v0055;
    v0134 = elt(env, 4); /* "algebraic expression" */
    v0136 = elt(env, 5); /* "Rlisp88 form" */
    {
        popv(4);
        fn = elt(env, 8); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0134, v0136);
    }

v0055:
    v0134 = stack[0];
    v0136 = elt(env, 6); /* algebraic */
    if (v0134 == v0136) goto v0065;
    v0136 = qvalue(elt(env, 7)); /* nil */
    goto v0028;

v0028:
    if (!(v0136 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0132 = stack[-2];
    v0135 = stack[-1];
    v0134 = elt(env, 3); /* symbolic */
    v0136 = stack[0];
    {
        popv(4);
        fn = elt(env, 9); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v0132, v0135, v0134, v0136);
    }

v0065:
    v0134 = stack[-2];
    v0136 = stack[-1];
    fn = elt(env, 10); /* intexprnp */
    v0136 = (*qfn2(fn))(qenv(fn), v0134, v0136);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-3];
    goto v0028;
/* error exit handlers */
v0276:
    popv(4);
    return nil;
}



/* Code for simpdiff */

static Lisp_Object CC_simpdiff(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpdiff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0008 = stack[0];
    fn = elt(env, 1); /* ckpreci!# */
    v0008 = (*qfn1(fn))(qenv(fn), v0008);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-2];
    v0008 = stack[0];
    fn = elt(env, 2); /* simpcar */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0008);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-2];
    v0008 = stack[0];
    v0008 = qcdr(v0008);
    fn = elt(env, 3); /* simpminus */
    v0008 = (*qfn1(fn))(qenv(fn), v0008);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-2];
    {
        Lisp_Object v0012 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0012, v0008);
    }
/* error exit handlers */
v0011:
    popv(3);
    return nil;
}



/* Code for oprin */

static Lisp_Object CC_oprin(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0039;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for oprin");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0058 = stack[0];
    if (!symbolp(v0058)) v0058 = nil;
    else { v0058 = qfastgets(v0058);
           if (v0058 != nil) { v0058 = elt(v0058, 37); /* prtch */
#ifdef RECORD_GET
             if (v0058 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v0058 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v0058 == SPID_NOPROP) v0058 = nil; }}
#endif
    stack[-1] = v0058;
    v0058 = stack[-1];
    if (v0058 == nil) goto v0036;
    v0058 = qvalue(elt(env, 2)); /* !*fort */
    if (v0058 == nil) goto v0010;
    v0058 = stack[-1];
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0058);
    }

v0010:
    v0058 = qvalue(elt(env, 3)); /* !*list */
    if (v0058 == nil) goto v0015;
    v0058 = qvalue(elt(env, 4)); /* obrkp!* */
    if (v0058 == nil) goto v0015;
    v0039 = stack[0];
    v0058 = elt(env, 5); /* (plus minus) */
    v0058 = Lmemq(nil, v0039, v0058);
    if (v0058 == nil) goto v0015;
    v0058 = qvalue(elt(env, 6)); /* testing!-width!* */
    if (v0058 == nil) goto v0055;
    v0058 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 8)) = v0058; /* overflowed!* */
    { popv(3); return onevalue(v0058); }

v0055:
    v0058 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 10); /* terpri!* */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-2];
    v0058 = stack[-1];
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0058);
    }

v0015:
    v0058 = stack[0];
    if (!symbolp(v0058)) v0058 = nil;
    else { v0058 = qfastgets(v0058);
           if (v0058 != nil) { v0058 = elt(v0058, 61); /* spaced */
#ifdef RECORD_GET
             if (v0058 == SPID_NOPROP)
                record_get(elt(fastget_names, 61), 0),
                v0058 = nil;
             else record_get(elt(fastget_names, 61), 1),
                v0058 = lisp_true; }
           else record_get(elt(fastget_names, 61), 0); }
#else
             if (v0058 == SPID_NOPROP) v0058 = nil; else v0058 = lisp_true; }}
#endif
    if (v0058 == nil) goto v0025;
    v0058 = elt(env, 1); /* " " */
    fn = elt(env, 9); /* prin2!* */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-2];
    v0058 = stack[-1];
    fn = elt(env, 9); /* prin2!* */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-2];
    v0058 = elt(env, 1); /* " " */
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0058);
    }

v0025:
    v0058 = stack[-1];
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0058);
    }

v0036:
    v0058 = elt(env, 1); /* " " */
    fn = elt(env, 9); /* prin2!* */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-2];
    v0058 = stack[0];
    fn = elt(env, 9); /* prin2!* */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-2];
    v0058 = elt(env, 1); /* " " */
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0058);
    }
/* error exit handlers */
v0060:
    popv(3);
    return nil;
}



/* Code for quotdd */

static Lisp_Object CC_quotdd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0166, v0165, v0233;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotdd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    stack[-1] = v0000;
/* end of prologue */
    v0166 = stack[-1];
    if (!(!consp(v0166))) goto v0047;
    v0166 = stack[0];
    if (!consp(v0166)) goto v0010;
    v0166 = stack[0];
    v0166 = qcar(v0166);
    if (!symbolp(v0166)) v0166 = nil;
    else { v0166 = qfastgets(v0166);
           if (v0166 != nil) { v0166 = elt(v0166, 34); /* i2d */
#ifdef RECORD_GET
             if (v0166 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0166 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0166 == SPID_NOPROP) v0166 = nil; }}
#endif
    v0233 = v0166;
    if (v0166 == nil) goto v0050;
    v0165 = v0233;
    v0166 = stack[-1];
    v0166 = Lapply1(nil, v0165, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-2];
    stack[-1] = v0166;
    goto v0047;

v0047:
    v0233 = stack[-1];
    v0165 = stack[0];
    v0166 = elt(env, 2); /* quotient */
    {
        popv(3);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0233, v0165, v0166);
    }

v0050:
    v0166 = stack[0];
    if (!consp(v0166)) goto v0024;
    v0166 = qvalue(elt(env, 1)); /* nil */
    goto v0023;

v0023:
    if (v0166 == nil) goto v0047;
    v0165 = v0233;
    v0166 = stack[0];
    v0166 = Lapply1(nil, v0165, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-2];
    stack[0] = v0166;
    goto v0047;

v0024:
    v0166 = stack[-1];
    v0166 = qcar(v0166);
    if (!symbolp(v0166)) v0166 = nil;
    else { v0166 = qfastgets(v0166);
           if (v0166 != nil) { v0166 = elt(v0166, 34); /* i2d */
#ifdef RECORD_GET
             if (v0166 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0166 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0166 == SPID_NOPROP) v0166 = nil; }}
#endif
    v0233 = v0166;
    goto v0023;

v0010:
    v0165 = stack[-1];
    v0166 = stack[0];
    v0166 = Ldivide(nil, v0165, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-2];
    v0233 = v0166;
    v0166 = v0233;
    v0165 = qcdr(v0166);
    v0166 = (Lisp_Object)1; /* 0 */
    if (v0165 == v0166) goto v0002;
    v0166 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0166); }

v0002:
    v0166 = v0233;
    v0166 = qcar(v0166);
    { popv(3); return onevalue(v0166); }
/* error exit handlers */
v0278:
    popv(3);
    return nil;
}



/* Code for setdiff */

static Lisp_Object CC_setdiff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0033;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setdiff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    v0006 = v0000;
/* end of prologue */

v0044:
    v0033 = stack[0];
    if (v0033 == nil) { popv(2); return onevalue(v0006); }
    v0033 = v0006;
    if (v0033 == nil) goto v0052;
    v0033 = stack[0];
    v0033 = qcar(v0033);
    v0006 = Ldelete(nil, v0033, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-1];
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    stack[0] = v0033;
    goto v0044;

v0052:
    v0006 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0006); }
/* error exit handlers */
v0003:
    popv(2);
    return nil;
}



/* Code for qqe_number!-of!-tails!-in!-qterm */

static Lisp_Object CC_qqe_numberKofKtailsKinKqterm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_number-of-tails-in-qterm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */

v0005:
    v0033 = stack[0];
    if (!consp(v0033)) goto v0036;
    v0033 = stack[0];
    fn = elt(env, 2); /* qqe_op */
    v0034 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-1];
    v0033 = elt(env, 1); /* (ladd radd) */
    v0033 = Lmemq(nil, v0034, v0033);
    if (v0033 == nil) goto v0031;
    v0033 = stack[0];
    fn = elt(env, 3); /* qqe_arg2r */
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-1];
    stack[0] = v0033;
    goto v0005;

v0031:
    v0033 = stack[0];
    fn = elt(env, 4); /* qqe_arg2l */
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-1];
    v0033 = CC_qqe_numberKofKtailsKinKqterm(env, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    popv(2);
    return add1(v0033);

v0036:
    v0033 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v0033); }
/* error exit handlers */
v0004:
    popv(2);
    return nil;
}



/* Code for ibalp_varlt1 */

static Lisp_Object CC_ibalp_varlt1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0029)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0149, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_varlt1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0029,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0029);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0029;
    v0042 = v0000;
/* end of prologue */
    v0149 = v0042;
    v0041 = (Lisp_Object)1; /* 0 */
    if (v0149 == v0041) goto v0030;
    v0149 = v0042;
    v0041 = (Lisp_Object)17; /* 1 */
    v0041 = (v0149 == v0041 ? lisp_true : nil);
    goto v0020;

v0020:
    if (v0041 == nil) goto v0043;
    v0041 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0041); }

v0043:
    v0041 = v0042;
    if (symbolp(v0041)) goto v0022;
    v0041 = v0042;
    fn = elt(env, 3); /* ibalp_argn */
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-2];
    stack[-1] = v0041;
    goto v0062;

v0062:
    v0041 = stack[-1];
    if (v0041 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0041 = stack[-1];
    v0041 = qcar(v0041);
    v0149 = v0041;
    v0041 = stack[0];
    v0041 = CC_ibalp_varlt1(env, v0149, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-2];
    stack[0] = v0041;
    v0041 = stack[-1];
    v0041 = qcdr(v0041);
    stack[-1] = v0041;
    goto v0062;

v0022:
    v0149 = v0042;
    v0041 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* lto_insertq */
        return (*qfn2(fn))(qenv(fn), v0149, v0041);
    }

v0030:
    v0041 = qvalue(elt(env, 1)); /* t */
    goto v0020;
/* error exit handlers */
v0047:
    popv(3);
    return nil;
}



/* Code for multiom */

static Lisp_Object CC_multiom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multiom");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0045 = stack[0];
    v0006 = Llength(nil, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-1];
    v0045 = (Lisp_Object)17; /* 1 */
    if (v0006 == v0045) goto v0043;
    v0045 = stack[0];
    v0045 = qcar(v0045);
    fn = elt(env, 2); /* objectom */
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-1];
    v0045 = stack[0];
    v0045 = qcdr(v0045);
    v0045 = CC_multiom(env, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    goto v0044;

v0044:
    v0045 = nil;
    { popv(2); return onevalue(v0045); }

v0043:
    v0045 = stack[0];
    v0045 = qcar(v0045);
    fn = elt(env, 2); /* objectom */
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    goto v0044;
/* error exit handlers */
v0034:
    popv(2);
    return nil;
}



setup_type const u07_setup[] =
{
    {"domain*p",                CC_domainHp,    too_many_1,    wrong_no_1},
    {"sfpx",                    CC_sfpx,        too_many_1,    wrong_no_1},
    {"ckpreci#",                CC_ckpreciC,    too_many_1,    wrong_no_1},
    {"red-weight",              too_few_2,      CC_redKweight, wrong_no_2},
    {"resimp1",                 CC_resimp1,     too_many_1,    wrong_no_1},
    {"pappl_pv",                too_few_2,      CC_pappl_pv,   wrong_no_2},
    {"aronep:",                 CC_aronepT,     too_many_1,    wrong_no_1},
    {"gizerop:",                CC_gizeropT,    too_many_1,    wrong_no_1},
    {"lispapply",               too_few_2,      CC_lispapply,  wrong_no_2},
    {"reordsq",                 CC_reordsq,     too_many_1,    wrong_no_1},
    {"frvarsof",                too_few_2,      CC_frvarsof,   wrong_no_2},
    {"mri_0mk2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mri_0mk2},
    {"isarb_int",               CC_isarb_int,   too_many_1,    wrong_no_1},
    {"equal:",                  too_few_2,      CC_equalT,     wrong_no_2},
    {"noncomp2f",               CC_noncomp2f,   too_many_1,    wrong_no_1},
    {"contr1-strand",           too_few_2,      CC_contr1Kstrand,wrong_no_2},
    {"setcloc*",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_setclocH},
    {"simpexpon",               CC_simpexpon,   too_many_1,    wrong_no_1},
    {"clear-column",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_clearKcolumn},
    {"rread1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_rread1},
    {"ckrn",                    CC_ckrn,        too_many_1,    wrong_no_1},
    {"ibalp_calcmom",           CC_ibalp_calcmom,too_many_1,   wrong_no_1},
    {"cgp_evlmon",              CC_cgp_evlmon,  too_many_1,    wrong_no_1},
    {"checktag",                CC_checktag,    too_many_1,    wrong_no_1},
    {"retimes1",                CC_retimes1,    too_many_1,    wrong_no_1},
    {"rd:minus",                CC_rdTminus,    too_many_1,    wrong_no_1},
    {"reval1",                  too_few_2,      CC_reval1,     wrong_no_2},
    {"groebsearchinlist",       too_few_2,      CC_groebsearchinlist,wrong_no_2},
    {"eofcheck",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_eofcheck},
    {"mv-pow-minusp",           CC_mvKpowKminusp,too_many_1,   wrong_no_1},
    {"rnplus:",                 too_few_2,      CC_rnplusT,    wrong_no_2},
    {"general-plus-mod-p",      too_few_2,      CC_generalKplusKmodKp,wrong_no_2},
    {"lalr_cached_goto",        too_few_2,      CC_lalr_cached_goto,wrong_no_2},
    {"ofsf_vareqnp",            too_few_2,      CC_ofsf_vareqnp,wrong_no_2},
    {"wulessp",                 too_few_2,      CC_wulessp,    wrong_no_2},
    {"sort-factors",            CC_sortKfactors,too_many_1,    wrong_no_1},
    {"ibalp_varlat",            CC_ibalp_varlat,too_many_1,    wrong_no_1},
    {"ps:evaluate",             too_few_2,      CC_psTevaluate,wrong_no_2},
    {"difff",                   too_few_2,      CC_difff,      wrong_no_2},
    {"simp*",                   CC_simpH,       too_many_1,    wrong_no_1},
    {"symtabget",               too_few_2,      CC_symtabget,  wrong_no_2},
    {"groebcpcompless?",        too_few_2,      CC_groebcpcomplessW,wrong_no_2},
    {"add2inputbuf",            too_few_2,      CC_add2inputbuf,wrong_no_2},
    {"simpplus",                CC_simpplus,    too_many_1,    wrong_no_1},
    {"divd",                    too_few_2,      CC_divd,       wrong_no_2},
    {"divide:",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_divideT},
    {"reduce-mod-p",            CC_reduceKmodKp,too_many_1,    wrong_no_1},
    {"lalr_print_items",        too_few_2,      CC_lalr_print_items,wrong_no_2},
    {"anforml",                 CC_anforml,     too_many_1,    wrong_no_1},
    {"ofsf_posvarpat",          too_few_2,      CC_ofsf_posvarpat,wrong_no_2},
    {"polynomclone",            CC_polynomclone,too_many_1,    wrong_no_1},
    {"ordpa",                   too_few_2,      CC_ordpa,      wrong_no_2},
    {"wuorderp",                too_few_2,      CC_wuorderp,   wrong_no_2},
    {"rl_prepat",               CC_rl_prepat,   too_many_1,    wrong_no_1},
    {"xxsort",                  CC_xxsort,      too_many_1,    wrong_no_1},
    {"lambda_n4e0tj_1",         too_few_2,      CC_lambda_n4e0tj_1,wrong_no_2},
    {"ev_comp",                 too_few_2,      CC_ev_comp,    wrong_no_2},
    {"mintype",                 CC_mintype,     too_many_1,    wrong_no_1},
    {"addpf",                   too_few_2,      CC_addpf,      wrong_no_2},
    {"csl_timbf",               too_few_2,      CC_csl_timbf,  wrong_no_2},
    {"evaluate0",               too_few_2,      CC_evaluate0,  wrong_no_2},
    {"sroad",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_sroad},
    {"formc",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_formc},
    {"simpdiff",                CC_simpdiff,    too_many_1,    wrong_no_1},
    {"oprin",                   CC_oprin,       too_many_1,    wrong_no_1},
    {"quotdd",                  too_few_2,      CC_quotdd,     wrong_no_2},
    {"setdiff",                 too_few_2,      CC_setdiff,    wrong_no_2},
    {"qqe_number-of-tails-in-qterm",CC_qqe_numberKofKtailsKinKqterm,too_many_1,wrong_no_1},
    {"ibalp_varlt1",            too_few_2,      CC_ibalp_varlt1,wrong_no_2},
    {"multiom",                 CC_multiom,     too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u07", (two_args *)"12868 9764884 5480412", 0}
};

/* end of generated code */
