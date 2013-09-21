
/* $destdir/u06.c        Machine generated C code */

/* Signature: 00000000 21-Sep-2013 */

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
#ifdef OLD_VERSION
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
#else 
#define font_of_char(n)  (((int32_t)(n) >> 29) & 0x03)
#define bits_of_char(n)  (0)
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0x001fffff)
#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((uint32_t)(font)) << 29) |                    \
                   (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF ((Lisp_Object)(int32_t)0xff000402)
#endif  
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
extern Lisp_Object used_space, avail_space;
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
extern Lisp_Object Lthrow_nil(Lisp_Object env, Lisp_Object a);
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


/* Code for isarb_compl */

static Lisp_Object CC_isarb_compl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004, v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for isarb_compl");
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
    v0004 = v0000;
/* end of prologue */
    v0003 = v0004;
    v0003 = Lconsp(nil, v0003);
    env = stack[0];
    if (v0003 == nil) goto v0006;
    v0003 = v0004;
    v0005 = qcar(v0003);
    v0003 = elt(env, 1); /* arbcomplex */
    if (v0005 == v0003) goto v0007;
    v0003 = v0004;
    v0003 = qcdr(v0003);
    fn = elt(env, 4); /* multi_isarb_compl */
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    goto v0006;

v0006:
    v0003 = nil;
    { popv(1); return onevalue(v0003); }

v0007:
    v0003 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v0003; /* found_compl */
    goto v0006;
/* error exit handlers */
v0008:
    popv(1);
    return nil;
}



/* Code for downwght */

static Lisp_Object CC_downwght(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011, v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for downwght");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0000;
/* end of prologue */
    v0011 = stack[-1];
    fn = elt(env, 1); /* delhisto */
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    v0012 = stack[-1];
    v0011 = stack[0];
    fn = elt(env, 2); /* downwght1 */
    v0011 = (*qfn2(fn))(qenv(fn), v0012, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    v0011 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* inshisto */
        return (*qfn1(fn))(qenv(fn), v0011);
    }
/* error exit handlers */
v0013:
    popv(3);
    return nil;
}



/* Code for vdpgetprop */

static Lisp_Object CC_vdpgetprop(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0024, v0025, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpgetprop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0025 = v0009;
    v0026 = v0000;
/* end of prologue */
    v0023 = v0026;
    if (v0023 == nil) goto v0006;
    v0024 = v0026;
    v0023 = elt(env, 2); /* vdp */
    if (!consp(v0024)) goto v0002;
    v0024 = qcar(v0024);
    if (!(v0024 == v0023)) goto v0002;
    v0023 = v0025;
    v0024 = v0026;
    v0024 = qcdr(v0024);
    v0024 = qcdr(v0024);
    v0024 = qcdr(v0024);
    v0024 = qcdr(v0024);
    v0024 = qcar(v0024);
    v0023 = Lassoc(nil, v0023, v0024);
    v0024 = v0023;
    v0023 = v0024;
    if (v0023 == nil) goto v0027;
    v0023 = v0024;
    v0023 = qcdr(v0023);
    { popv(3); return onevalue(v0023); }

v0027:
    v0023 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0023); }

v0002:
    stack[-1] = elt(env, 3); /* dipoly */
    stack[0] = (Lisp_Object)113; /* 7 */
    v0023 = elt(env, 4); /* "vdpgetprop given a non-vdp as 1st parameter" 
*/
    v0024 = v0026;
    v0023 = list3(v0023, v0024, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    {
        Lisp_Object v0029 = stack[-1];
        Lisp_Object v0030 = stack[0];
        popv(3);
        fn = elt(env, 5); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0029, v0030, v0023);
    }

v0006:
    v0023 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0023); }
/* error exit handlers */
v0028:
    popv(3);
    return nil;
}



/* Code for termordp */

static Lisp_Object CC_termordp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for termordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    v0032 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* wedgefax */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    v0032 = stack[0];
    fn = elt(env, 1); /* wedgefax */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    {
        Lisp_Object v0022 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* monordp */
        return (*qfn2(fn))(qenv(fn), v0022, v0032);
    }
/* error exit handlers */
v0012:
    popv(3);
    return nil;
}



/* Code for !:difference */

static Lisp_Object CC_Tdifference(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0041, v0042, v0043;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :difference");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0042 = v0009;
    v0043 = v0000;
/* end of prologue */
    v0040 = v0043;
    if (v0040 == nil) goto v0006;
    v0040 = v0042;
    if (v0040 == nil) return onevalue(v0043);
    v0041 = v0043;
    v0040 = v0042;
    if (equal(v0041, v0040)) goto v0044;
    v0040 = v0043;
    if (!consp(v0040)) goto v0017;
    v0040 = qvalue(elt(env, 1)); /* nil */
    goto v0016;

v0016:
    if (v0040 == nil) goto v0014;
    v0040 = v0043;
    v0041 = v0042;
    return difference2(v0040, v0041);

v0014:
    v0041 = v0043;
    v0040 = elt(env, 2); /* difference */
    {
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0041, v0042, v0040);
    }

v0017:
    v0040 = v0042;
    v0040 = (consp(v0040) ? nil : lisp_true);
    goto v0016;

v0044:
    v0040 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0040);

v0006:
    v0040 = v0042;
    {
        fn = elt(env, 4); /* !:minus */
        return (*qfn1(fn))(qenv(fn), v0040);
    }
}



/* Code for domain!*p */

static Lisp_Object CC_domainHp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008, v0045;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for domain*p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0045 = v0000;
/* end of prologue */
    v0008 = v0045;
    if (v0008 == nil) goto v0046;
    v0008 = v0045;
    v0008 = (is_number(v0008) ? lisp_true : nil);
    if (!(v0008 == nil)) return onevalue(v0008);
    v0008 = v0045;
    if (!consp(v0008)) goto v0003;
    v0008 = v0045;
    v0008 = qcar(v0008);
    v0045 = qvalue(elt(env, 2)); /* domainlist!* */
    v0008 = Lmemq(nil, v0008, v0045);
    return onevalue(v0008);

v0003:
    v0008 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0008);

v0046:
    v0008 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0008);
}



/* Code for raddf */

static Lisp_Object CC_raddf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068, v0069;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for raddf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0009;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0070;

v0070:
    v0068 = stack[-2];
    if (v0068 == nil) goto v0032;
    v0068 = stack[-1];
    if (v0068 == nil) goto v0071;
    v0068 = stack[-2];
    if (!consp(v0068)) goto v0072;
    v0068 = stack[-2];
    v0068 = qcar(v0068);
    v0068 = (consp(v0068) ? nil : lisp_true);
    goto v0073;

v0073:
    if (v0068 == nil) goto v0008;
    stack[0] = stack[-3];
    v0069 = stack[-2];
    v0068 = stack[-1];
    fn = elt(env, 2); /* addd */
    v0068 = (*qfn2(fn))(qenv(fn), v0069, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    {
        Lisp_Object v0075 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0075, v0068);
    }

v0008:
    v0068 = stack[-1];
    if (!consp(v0068)) goto v0027;
    v0068 = stack[-1];
    v0068 = qcar(v0068);
    v0068 = (consp(v0068) ? nil : lisp_true);
    goto v0076;

v0076:
    if (v0068 == nil) goto v0077;
    stack[0] = stack[-3];
    v0069 = stack[-1];
    v0068 = stack[-2];
    fn = elt(env, 2); /* addd */
    v0068 = (*qfn2(fn))(qenv(fn), v0069, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    {
        Lisp_Object v0078 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0078, v0068);
    }

v0077:
    v0068 = stack[-2];
    v0068 = qcar(v0068);
    v0069 = qcar(v0068);
    v0068 = stack[-1];
    v0068 = qcar(v0068);
    v0068 = qcar(v0068);
    if (equal(v0069, v0068)) goto v0079;
    v0068 = stack[-2];
    v0068 = qcar(v0068);
    v0069 = qcar(v0068);
    v0068 = stack[-1];
    v0068 = qcar(v0068);
    v0068 = qcar(v0068);
    fn = elt(env, 4); /* ordpp */
    v0068 = (*qfn2(fn))(qenv(fn), v0069, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    if (v0068 == nil) goto v0080;
    v0068 = stack[-2];
    v0069 = qcar(v0068);
    v0068 = stack[-3];
    v0068 = cons(v0069, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    stack[-3] = v0068;
    v0068 = stack[-2];
    v0068 = qcdr(v0068);
    stack[-2] = v0068;
    goto v0070;

v0080:
    v0068 = stack[-1];
    v0069 = qcar(v0068);
    v0068 = stack[-3];
    v0068 = cons(v0069, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    stack[-3] = v0068;
    v0068 = stack[-1];
    v0068 = qcdr(v0068);
    stack[-1] = v0068;
    goto v0070;

v0079:
    v0068 = stack[-2];
    v0068 = qcar(v0068);
    stack[0] = qcar(v0068);
    v0068 = stack[-2];
    v0068 = qcar(v0068);
    v0069 = qcdr(v0068);
    v0068 = stack[-1];
    v0068 = qcar(v0068);
    v0068 = qcdr(v0068);
    v0069 = CC_raddf(env, v0069, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    v0068 = stack[-3];
    v0068 = acons(stack[0], v0069, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    stack[-3] = v0068;
    v0068 = stack[-2];
    v0068 = qcdr(v0068);
    stack[-2] = v0068;
    v0068 = stack[-1];
    v0068 = qcdr(v0068);
    stack[-1] = v0068;
    goto v0070;

v0027:
    v0068 = qvalue(elt(env, 1)); /* t */
    goto v0076;

v0072:
    v0068 = qvalue(elt(env, 1)); /* t */
    goto v0073;

v0071:
    v0069 = stack[-3];
    v0068 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0069, v0068);
    }

v0032:
    v0069 = stack[-3];
    v0068 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0069, v0068);
    }
/* error exit handlers */
v0074:
    popv(5);
    return nil;
}



/* Code for eofcheck */

static Lisp_Object MS_CDECL CC_eofcheck(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0008;
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
    v0008 = qvalue(elt(env, 1)); /* program!* */
    v0005 = qvalue(elt(env, 2)); /* !$eof!$ */
    if (v0008 == v0005) goto v0012;
    v0005 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v0005); }

v0012:
    v0008 = qvalue(elt(env, 3)); /* ttype!* */
    v0005 = (Lisp_Object)49; /* 3 */
    if (v0008 == v0005) goto v0044;
    v0005 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v0005); }

v0044:
    v0005 = qvalue(elt(env, 4)); /* eof!* */
    v0005 = add1(v0005);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[0];
    qvalue(elt(env, 4)) = v0005; /* eof!* */
    { popv(1); return onevalue(v0005); }
/* error exit handlers */
v0045:
    popv(1);
    return nil;
}



/* Code for red!-weight */

static Lisp_Object CC_redKweight(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0002;
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
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0000;
/* end of prologue */
    v0013 = stack[-1];
    fn = elt(env, 1); /* nonzero!-length */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-3];
    v0002 = stack[-1];
    v0013 = stack[0];
    fn = elt(env, 2); /* red!-weight1 */
    v0013 = (*qfn2(fn))(qenv(fn), v0002, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    {
        Lisp_Object v0082 = stack[-2];
        popv(4);
        return cons(v0082, v0013);
    }
/* error exit handlers */
v0071:
    popv(4);
    return nil;
}



/* Code for dp_sum */

static Lisp_Object CC_dp_sum(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0096, v0097;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_sum");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0000;
/* end of prologue */

v0098:
    v0052 = stack[-1];
    if (v0052 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0052 = stack[0];
    if (v0052 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0052 = stack[-1];
    fn = elt(env, 1); /* dp_lmon */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-3];
    v0052 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-3];
    fn = elt(env, 2); /* mo_compare */
    v0052 = (*qfn2(fn))(qenv(fn), stack[-2], v0052);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-3];
    v0097 = v0052;
    v0096 = v0097;
    v0052 = (Lisp_Object)17; /* 1 */
    if (v0096 == v0052) goto v0100;
    v0096 = v0097;
    v0052 = (Lisp_Object)-15; /* -1 */
    if (v0096 == v0052) goto v0026;
    v0052 = stack[-1];
    fn = elt(env, 3); /* dp_lc */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-3];
    v0052 = stack[0];
    fn = elt(env, 3); /* dp_lc */
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-3];
    fn = elt(env, 4); /* bc_sum */
    v0052 = (*qfn2(fn))(qenv(fn), stack[-2], v0052);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-3];
    stack[-2] = v0052;
    v0052 = stack[-2];
    fn = elt(env, 5); /* bc_zero!? */
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-3];
    if (v0052 == nil) goto v0058;
    v0052 = stack[-1];
    v0096 = qcdr(v0052);
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    stack[-1] = v0096;
    stack[0] = v0052;
    goto v0098;

v0058:
    v0052 = stack[-1];
    fn = elt(env, 1); /* dp_lmon */
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-3];
    fn = elt(env, 6); /* dp_term */
    stack[-2] = (*qfn2(fn))(qenv(fn), stack[-2], v0052);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-3];
    v0052 = stack[-1];
    v0096 = qcdr(v0052);
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    v0052 = CC_dp_sum(env, v0096, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    {
        Lisp_Object v0101 = stack[-2];
        popv(4);
        return cons(v0101, v0052);
    }

v0026:
    v0052 = stack[0];
    stack[-2] = qcar(v0052);
    v0096 = stack[-1];
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    v0052 = CC_dp_sum(env, v0096, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    {
        Lisp_Object v0102 = stack[-2];
        popv(4);
        return cons(v0102, v0052);
    }

v0100:
    v0052 = stack[-1];
    stack[-2] = qcar(v0052);
    v0052 = stack[-1];
    v0096 = qcdr(v0052);
    v0052 = stack[0];
    v0052 = CC_dp_sum(env, v0096, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    {
        Lisp_Object v0103 = stack[-2];
        popv(4);
        return cons(v0103, v0052);
    }
/* error exit handlers */
v0099:
    popv(4);
    return nil;
}



/* Code for resimp1 */

static Lisp_Object CC_resimp1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0005;
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
    v0004 = stack[0];
    v0005 = qcar(v0004);
    v0004 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* subf1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-2];
    v0004 = stack[0];
    v0005 = qcdr(v0004);
    v0004 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* subf1 */
    v0004 = (*qfn2(fn))(qenv(fn), v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-2];
    fn = elt(env, 5); /* quotsq */
    v0004 = (*qfn2(fn))(qenv(fn), stack[-1], v0004);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-2];
    stack[0] = v0004;
    v0004 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 3)) = v0004; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v0073:
    popv(3);
    return nil;
}



/* Code for aronep!: */

static Lisp_Object CC_aronepT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0007;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aronep:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0010 = v0000;
/* end of prologue */
    v0007 = qcdr(v0010);
    v0010 = (Lisp_Object)17; /* 1 */
    v0010 = (v0007 == v0010 ? lisp_true : nil);
    return onevalue(v0010);
}



/* Code for omobjs */

static Lisp_Object MS_CDECL CC_omobjs(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036, v0107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omobjs");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omobjs");
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
    push(nil);
/* end of prologue */
    v0107 = qvalue(elt(env, 1)); /* char */
    v0036 = elt(env, 2); /* (!/ o m a) */
    if (equal(v0107, v0036)) goto v0070;
    fn = elt(env, 4); /* omobj */
    v0036 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-1];
    stack[0] = v0036;
    fn = elt(env, 5); /* lex */
    v0036 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-1];
    v0036 = CC_omobjs(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    v0107 = stack[0];
    if (v0107 == nil) goto v0082;
    v0107 = stack[0];
    popv(2);
    return cons(v0107, v0036);

v0082:
    v0107 = stack[0];
        popv(2);
        return Lappend(nil, v0107, v0036);

v0070:
    v0036 = nil;
    { popv(2); return onevalue(v0036); }
/* error exit handlers */
v0108:
    popv(2);
    return nil;
}



/* Code for isarb_int */

static Lisp_Object CC_isarb_int(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004, v0005;
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
    v0004 = v0000;
/* end of prologue */
    v0003 = v0004;
    v0003 = Lconsp(nil, v0003);
    env = stack[0];
    if (v0003 == nil) goto v0006;
    v0003 = v0004;
    v0005 = qcar(v0003);
    v0003 = elt(env, 1); /* arbint */
    if (v0005 == v0003) goto v0007;
    v0003 = v0004;
    v0003 = qcdr(v0003);
    fn = elt(env, 4); /* multi_isarb_int */
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    goto v0006;

v0006:
    v0003 = nil;
    { popv(1); return onevalue(v0003); }

v0007:
    v0003 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v0003; /* found_int */
    goto v0006;
/* error exit handlers */
v0008:
    popv(1);
    return nil;
}



/* Code for ps!:evaluate */

static Lisp_Object CC_psTevaluate(Lisp_Object env,
                         Lisp_Object v0009, Lisp_Object v0106)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0041;
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
        push2(v0106,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0106);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0106;
    v0040 = v0009;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v0040; /* ps */
    v0041 = qvalue(elt(env, 1)); /* ps */
    v0040 = stack[-2];
    fn = elt(env, 3); /* ps!:get!-term */
    v0040 = (*qfn2(fn))(qenv(fn), v0041, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-4];
    stack[-1] = v0040;
    v0040 = stack[-1];
    if (v0040 == nil) goto v0002;
    v0040 = stack[-1];
    goto v0070;

v0070:
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    { popv(5); return onevalue(v0040); }

v0002:
    v0040 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 4); /* ps!:last!-term */
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-4];
    v0040 = add1(v0040);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-4];
    stack[0] = v0040;
    goto v0018;

v0018:
    v0041 = stack[-2];
    v0040 = stack[0];
    v0040 = difference2(v0041, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-4];
    v0040 = Lminusp(nil, v0040);
    env = stack[-4];
    if (v0040 == nil) goto v0014;
    v0040 = stack[-1];
    goto v0070;

v0014:
    v0041 = qvalue(elt(env, 1)); /* ps */
    v0040 = stack[0];
    fn = elt(env, 5); /* ps!:evaluate!-next */
    v0040 = (*qfn2(fn))(qenv(fn), v0041, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-4];
    stack[-1] = v0040;
    v0040 = stack[0];
    v0040 = add1(v0040);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-4];
    stack[0] = v0040;
    goto v0018;
/* error exit handlers */
v0027:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    popv(5);
    return nil;
}



/* Code for noncomp2f */

static Lisp_Object CC_noncomp2f(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0066, v0067;
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

v0006:
    v0066 = stack[0];
    if (!consp(v0066)) goto v0007;
    v0066 = stack[0];
    v0066 = qcar(v0066);
    v0066 = (consp(v0066) ? nil : lisp_true);
    goto v0010;

v0010:
    if (v0066 == nil) goto v0031;
    v0066 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0066); }

v0031:
    v0066 = stack[0];
    v0066 = qcar(v0066);
    v0066 = qcar(v0066);
    v0066 = qcar(v0066);
    v0067 = v0066;
    if (!consp(v0066)) goto v0039;
    v0066 = v0067;
    v0066 = qcar(v0066);
    if (!symbolp(v0066)) v0066 = nil;
    else { v0066 = qfastgets(v0066);
           if (v0066 != nil) { v0066 = elt(v0066, 0); /* noncom */
#ifdef RECORD_GET
             if (v0066 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0066 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0066 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0066 == SPID_NOPROP) v0066 = nil; else v0066 = lisp_true; }}
#endif
    if (v0066 == nil) goto v0110;
    v0066 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0066); }

v0110:
    v0066 = stack[0];
    v0066 = qcar(v0066);
    v0066 = qcdr(v0066);
    v0066 = CC_noncomp2f(env, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-1];
    if (v0066 == nil) goto v0111;
    v0066 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0066); }

v0111:
    v0066 = stack[0];
    v0066 = qcdr(v0066);
    stack[0] = v0066;
    goto v0006;

v0039:
    v0066 = v0067;
    if (!symbolp(v0066)) v0066 = nil;
    else { v0066 = qfastgets(v0066);
           if (v0066 != nil) { v0066 = elt(v0066, 0); /* noncom */
#ifdef RECORD_GET
             if (v0066 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0066 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0066 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0066 == SPID_NOPROP) v0066 = nil; else v0066 = lisp_true; }}
#endif
    if (v0066 == nil) goto v0111;
    v0066 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0066); }

v0007:
    v0066 = qvalue(elt(env, 1)); /* t */
    goto v0010;
/* error exit handlers */
v0015:
    popv(2);
    return nil;
}



/* Code for contr1!-strand */

static Lisp_Object CC_contr1Kstrand(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0021, v0013, v0002;
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
    v0022 = v0009;
    v0021 = v0000;
/* end of prologue */
    v0002 = v0021;
    v0013 = v0022;
    v0021 = qvalue(elt(env, 1)); /* nil */
    v0022 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* contr2!-strand */
        return (*qfnn(fn))(qenv(fn), 4, v0002, v0013, v0021, v0022);
    }
}



/* Code for add2inputbuf */

static Lisp_Object CC_add2inputbuf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0018, v0019;
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
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0000;
/* end of prologue */
    fn = elt(env, 6); /* terminalp */
    v0020 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    if (v0020 == nil) goto v0010;
    v0020 = qvalue(elt(env, 2)); /* !*nosave!* */
    goto v0081;

v0081:
    if (v0020 == nil) goto v0038;
    v0020 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v0020); }

v0038:
    v0019 = qvalue(elt(env, 4)); /* statcounter */
    v0018 = stack[0];
    v0020 = stack[-1];
    v0018 = list3(v0019, v0018, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    v0020 = qvalue(elt(env, 5)); /* inputbuflis!* */
    v0020 = cons(v0018, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-2];
    qvalue(elt(env, 5)) = v0020; /* inputbuflis!* */
    v0020 = nil;
    { popv(3); return onevalue(v0020); }

v0010:
    v0020 = qvalue(elt(env, 1)); /* t */
    goto v0081;
/* error exit handlers */
v0037:
    popv(3);
    return nil;
}



/* Code for ckpreci!# */

static Lisp_Object CC_ckpreciC(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0041, v0042;
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
    v0040 = stack[0];
    v0040 = qcar(v0040);
    fn = elt(env, 3); /* timesip */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-2];
    v0040 = stack[0];
    v0040 = qcdr(v0040);
    v0040 = qcar(v0040);
    fn = elt(env, 3); /* timesip */
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-2];
    v0042 = stack[-1];
    v0041 = v0040;
    v0040 = qvalue(elt(env, 1)); /* !*complex */
    if (v0040 == nil) goto v0032;
    v0040 = v0042;
    if (v0040 == nil) goto v0039;
    v0040 = v0041;
    if (!(v0040 == nil)) goto v0039;
    v0040 = stack[0];
    v0040 = qcar(v0040);
    v0041 = qcdr(v0040);
    v0040 = stack[0];
    v0040 = qcdr(v0040);
    v0040 = qcar(v0040);
    {
        popv(3);
        fn = elt(env, 4); /* ckprec2!# */
        return (*qfn2(fn))(qenv(fn), v0041, v0040);
    }

v0039:
    v0040 = v0041;
    if (v0040 == nil) goto v0105;
    v0040 = v0042;
    if (!(v0040 == nil)) goto v0105;
    v0040 = stack[0];
    v0040 = qcdr(v0040);
    v0040 = qcar(v0040);
    v0041 = qcdr(v0040);
    v0040 = stack[0];
    v0040 = qcar(v0040);
    {
        popv(3);
        fn = elt(env, 4); /* ckprec2!# */
        return (*qfn2(fn))(qenv(fn), v0041, v0040);
    }

v0105:
    v0040 = nil;
    { popv(3); return onevalue(v0040); }

v0032:
    v0040 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0040); }
/* error exit handlers */
v0076:
    popv(3);
    return nil;
}



/* Code for mv!-pow!-minusp */

static Lisp_Object CC_mvKpowKminusp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0038;
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

v0098:
    v0082 = stack[0];
    if (v0082 == nil) goto v0046;
    v0082 = stack[0];
    v0038 = qcar(v0082);
    v0082 = (Lisp_Object)1; /* 0 */
    v0082 = (Lisp_Object)lessp2(v0038, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    v0082 = v0082 ? lisp_true : nil;
    env = stack[-1];
    if (!(v0082 == nil)) { popv(2); return onevalue(v0082); }
    v0082 = stack[0];
    v0082 = qcdr(v0082);
    stack[0] = v0082;
    goto v0098;

v0046:
    v0082 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0082); }
/* error exit handlers */
v0017:
    popv(2);
    return nil;
}



/* Code for divd */

static Lisp_Object CC_divd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0117, v0118, v0119;
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
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0009;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0070;

v0070:
    v0117 = stack[-1];
    if (v0117 == nil) goto v0031;
    v0117 = stack[-2];
    if (v0117 == nil) goto v0034;
    v0117 = stack[-2];
    if (!consp(v0117)) goto v0120;
    v0117 = stack[-2];
    v0117 = qcar(v0117);
    v0117 = (consp(v0117) ? nil : lisp_true);
    goto v0027;

v0027:
    if (v0117 == nil) goto v0088;
    stack[0] = stack[-3];
    v0118 = stack[-2];
    v0117 = stack[-1];
    fn = elt(env, 5); /* divdm */
    v0117 = (*qfn2(fn))(qenv(fn), v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    {
        Lisp_Object v0058 = stack[0];
        popv(5);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0058, v0117);
    }

v0088:
    v0117 = stack[-2];
    v0117 = qcar(v0117);
    stack[0] = qcar(v0117);
    v0117 = stack[-2];
    v0117 = qcar(v0117);
    v0118 = qcdr(v0117);
    v0117 = stack[-1];
    v0118 = CC_divd(env, v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    v0117 = stack[-3];
    v0117 = acons(stack[0], v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    stack[-3] = v0117;
    v0117 = stack[-2];
    v0117 = qcdr(v0117);
    stack[-2] = v0117;
    goto v0070;

v0120:
    v0117 = qvalue(elt(env, 4)); /* t */
    goto v0027;

v0034:
    v0117 = stack[-3];
    {
        popv(5);
        fn = elt(env, 6); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0117);
    }

v0031:
    v0117 = stack[-2];
    if (v0117 == nil) goto v0021;
    stack[0] = stack[-3];
    v0119 = elt(env, 1); /* poly */
    v0118 = (Lisp_Object)33; /* 2 */
    v0117 = elt(env, 3); /* "Zero divisor" */
    fn = elt(env, 7); /* rerror */
    v0117 = (*qfnn(fn))(qenv(fn), 3, v0119, v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    {
        Lisp_Object v0055 = stack[0];
        popv(5);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0055, v0117);
    }

v0021:
    stack[0] = stack[-3];
    v0119 = elt(env, 1); /* poly */
    v0118 = (Lisp_Object)17; /* 1 */
    v0117 = elt(env, 2); /* "0/0 formed" */
    fn = elt(env, 7); /* rerror */
    v0117 = (*qfnn(fn))(qenv(fn), 3, v0119, v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-4];
    {
        Lisp_Object v0122 = stack[0];
        popv(5);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0122, v0117);
    }
/* error exit handlers */
v0121:
    popv(5);
    return nil;
}



/* Code for pappl_pv */

static Lisp_Object CC_pappl_pv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090, v0125;
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
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v0090 = v0009;
    stack[-4] = v0000;
/* end of prologue */
    stack[-5] = v0090;
    v0090 = stack[-5];
    if (v0090 == nil) goto v0032;
    v0090 = stack[-5];
    v0090 = qcar(v0090);
    v0125 = v0090;
    stack[0] = qcar(v0125);
    v0125 = stack[-4];
    v0090 = qcdr(v0090);
    fn = elt(env, 2); /* pappl0 */
    v0090 = (*qfn2(fn))(qenv(fn), v0125, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-6];
    v0090 = cons(stack[0], v0090);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-6];
    v0090 = ncons(v0090);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-6];
    stack[-2] = v0090;
    stack[-3] = v0090;
    goto v0031;

v0031:
    v0090 = stack[-5];
    v0090 = qcdr(v0090);
    stack[-5] = v0090;
    v0090 = stack[-5];
    if (v0090 == nil) goto v0037;
    stack[-1] = stack[-2];
    v0090 = stack[-5];
    v0090 = qcar(v0090);
    v0125 = v0090;
    stack[0] = qcar(v0125);
    v0125 = stack[-4];
    v0090 = qcdr(v0090);
    fn = elt(env, 2); /* pappl0 */
    v0090 = (*qfn2(fn))(qenv(fn), v0125, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-6];
    v0090 = cons(stack[0], v0090);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-6];
    v0090 = ncons(v0090);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-6];
    v0090 = Lrplacd(nil, stack[-1], v0090);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-6];
    v0090 = stack[-2];
    v0090 = qcdr(v0090);
    stack[-2] = v0090;
    goto v0031;

v0037:
    v0090 = stack[-3];
    goto v0104;

v0104:
    {
        popv(7);
        fn = elt(env, 3); /* pv_sort */
        return (*qfn1(fn))(qenv(fn), v0090);
    }

v0032:
    v0090 = qvalue(elt(env, 1)); /* nil */
    goto v0104;
/* error exit handlers */
v0093:
    popv(7);
    return nil;
}



/* Code for reordsq */

static Lisp_Object CC_reordsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044;
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
    v0044 = stack[0];
    v0044 = qcar(v0044);
    fn = elt(env, 1); /* reorder */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-2];
    v0044 = stack[0];
    v0044 = qcdr(v0044);
    fn = elt(env, 1); /* reorder */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    {
        Lisp_Object v0021 = stack[-1];
        popv(3);
        return cons(v0021, v0044);
    }
/* error exit handlers */
v0022:
    popv(3);
    return nil;
}



/* Code for simpexpon */

static Lisp_Object CC_simpexpon(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0081, v0010;
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
    v0081 = v0000;
/* end of prologue */
    v0010 = v0081;
    v0081 = elt(env, 1); /* simp!* */
    {
        fn = elt(env, 2); /* simpexpon1 */
        return (*qfn2(fn))(qenv(fn), v0010, v0081);
    }
}



/* Code for frvarsof */

static Lisp_Object CC_frvarsof(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0065, v0076, v0027, v0120;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for frvarsof");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0076 = v0009;
    v0027 = v0000;
/* end of prologue */

v0010:
    v0120 = v0027;
    v0065 = qvalue(elt(env, 1)); /* frlis!* */
    v0065 = Lmemq(nil, v0120, v0065);
    if (v0065 == nil) goto v0081;
    v0120 = v0027;
    v0065 = v0076;
    v0065 = Lmemq(nil, v0120, v0065);
    if (!(v0065 == nil)) { popv(2); return onevalue(v0076); }
    stack[0] = v0076;
    v0065 = v0027;
    v0065 = ncons(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    {
        Lisp_Object v0024 = stack[0];
        popv(2);
        return Lappend(nil, v0024, v0065);
    }

v0081:
    v0065 = v0027;
    if (!consp(v0065)) { popv(2); return onevalue(v0076); }
    v0065 = v0027;
    v0065 = qcdr(v0065);
    stack[0] = v0065;
    v0065 = v0027;
    v0065 = qcar(v0065);
    v0065 = CC_frvarsof(env, v0065, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-1];
    v0076 = v0065;
    v0065 = stack[0];
    v0027 = v0065;
    goto v0010;
/* error exit handlers */
v0023:
    popv(2);
    return nil;
}



/* Code for ibalp_calcmom */

static Lisp_Object CC_ibalp_calcmom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0033;
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
    v0015 = stack[0];
    v0015 = qcdr(v0015);
    v0015 = qcdr(v0015);
    v0015 = qcdr(v0015);
    v0015 = qcdr(v0015);
    v0033 = qcar(v0015);
    v0015 = stack[0];
    v0015 = qcdr(v0015);
    v0015 = qcdr(v0015);
    v0015 = qcdr(v0015);
    v0015 = qcdr(v0015);
    v0015 = qcdr(v0015);
    v0015 = qcar(v0015);
    v0033 = plus2(v0033, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    v0015 = (Lisp_Object)513; /* 32 */
    stack[-1] = times2(v0033, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-2];
    v0015 = stack[0];
    v0015 = qcdr(v0015);
    v0015 = qcdr(v0015);
    v0015 = qcdr(v0015);
    v0015 = qcdr(v0015);
    v0033 = qcar(v0015);
    v0015 = stack[0];
    v0015 = qcdr(v0015);
    v0015 = qcdr(v0015);
    v0015 = qcdr(v0015);
    v0015 = qcdr(v0015);
    v0015 = qcdr(v0015);
    v0015 = qcar(v0015);
    v0015 = times2(v0033, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    {
        Lisp_Object v0041 = stack[-1];
        popv(3);
        return plus2(v0041, v0015);
    }
/* error exit handlers */
v0040:
    popv(3);
    return nil;
}



/* Code for ev_comp */

static Lisp_Object CC_ev_comp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0013;
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
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0021 = v0009;
    v0013 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dip_sortevcomp!* */
    v0021 = list2(v0013, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-1];
    {
        Lisp_Object v0039 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0039, v0021);
    }
/* error exit handlers */
v0001:
    popv(2);
    return nil;
}



/* Code for minusp!: */

static Lisp_Object CC_minuspT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0019, v0105;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for minusp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0105 = v0000;
/* end of prologue */
    v0019 = v0105;
    v0018 = elt(env, 1); /* !:rd!: */
    if (!consp(v0019)) goto v0039;
    v0019 = qcar(v0019);
    if (!(v0019 == v0018)) goto v0039;
    v0018 = v0105;
    v0018 = qcdr(v0018);
    v0018 = (consp(v0018) ? nil : lisp_true);
    v0018 = (v0018 == nil ? lisp_true : nil);
    goto v0111;

v0111:
    if (v0018 == nil) goto v0072;
    v0018 = v0105;
    v0018 = qcdr(v0018);
    v0019 = qcar(v0018);
    v0018 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v0019, v0018);

v0072:
    v0018 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0018);

v0039:
    v0018 = qvalue(elt(env, 2)); /* nil */
    goto v0111;
}



/* Code for difff */

static Lisp_Object CC_difff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0096, v0097, v0053;
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
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0009;
    stack[-2] = v0000;
/* end of prologue */
    v0096 = stack[-2];
    if (!consp(v0096)) goto v0031;
    v0096 = stack[-2];
    v0096 = qcar(v0096);
    if (!consp(v0096)) goto v0001;
    v0096 = stack[-2];
    v0096 = qcar(v0096);
    v0097 = qcar(v0096);
    v0096 = (Lisp_Object)17; /* 1 */
    v0096 = cons(v0097, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-4];
    v0097 = ncons(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-4];
    v0096 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0097, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-4];
    v0096 = stack[-2];
    v0096 = qcar(v0096);
    v0097 = qcdr(v0096);
    v0096 = stack[-1];
    v0096 = CC_difff(env, v0097, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    stack[-3] = (*qfn2(fn))(qenv(fn), stack[0], v0096);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-4];
    v0096 = stack[-2];
    v0096 = qcar(v0096);
    v0097 = qcar(v0096);
    v0096 = stack[-1];
    fn = elt(env, 4); /* diffp */
    stack[0] = (*qfn2(fn))(qenv(fn), v0097, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-4];
    v0096 = stack[-2];
    v0096 = qcar(v0096);
    v0097 = qcdr(v0096);
    v0096 = (Lisp_Object)17; /* 1 */
    v0096 = cons(v0097, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    v0096 = (*qfn2(fn))(qenv(fn), stack[0], v0096);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-4];
    fn = elt(env, 5); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v0096);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-4];
    v0096 = stack[-2];
    v0097 = qcdr(v0096);
    v0096 = stack[-1];
    v0096 = CC_difff(env, v0097, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-4];
    {
        Lisp_Object v0103 = stack[0];
        popv(5);
        fn = elt(env, 5); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0103, v0096);
    }

v0001:
    v0096 = stack[-2];
    v0097 = qcar(v0096);
    v0096 = elt(env, 2); /* domain!-diff!-fn */
    v0096 = get(v0097, v0096);
    env = stack[-4];
    v0097 = v0096;
    v0096 = v0097;
    if (v0096 == nil) goto v0137;
    v0053 = v0097;
    v0097 = stack[-2];
    v0096 = stack[-1];
        popv(5);
        return Lapply2(nil, 3, v0053, v0097, v0096);

v0137:
    v0097 = qvalue(elt(env, 1)); /* nil */
    v0096 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0097, v0096);

v0031:
    v0097 = qvalue(elt(env, 1)); /* nil */
    v0096 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0097, v0096);
/* error exit handlers */
v0102:
    popv(5);
    return nil;
}



/* Code for reval1 */

static Lisp_Object CC_reval1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0196, v0197, v0198;
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
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0009;
    stack[-2] = v0000;
/* end of prologue */
    v0196 = qvalue(elt(env, 1)); /* !*revalp */
    if (v0196 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0196 = qvalue(elt(env, 2)); /* varstack!* */
    stack[-3] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v0196; /* varstack!* */
    v0196 = stack[-2];
    if (v0196 == nil) goto v0013;
    v0196 = stack[-2];
    v0196 = Lstringp(nil, v0196);
    env = stack[-4];
    if (v0196 == nil) goto v0071;
    v0196 = stack[-2];
    goto v0012;

v0012:
    qvalue(elt(env, 2)) = stack[-3]; /* varstack!* */
    { popv(5); return onevalue(v0196); }

v0071:
    v0196 = stack[-2];
    v0196 = integerp(v0196);
    if (v0196 == nil) goto v0003;
    v0196 = qvalue(elt(env, 4)); /* dmode!* */
    if (!symbolp(v0196)) v0196 = nil;
    else { v0196 = qfastgets(v0196);
           if (v0196 != nil) { v0196 = elt(v0196, 5); /* convert */
#ifdef RECORD_GET
             if (v0196 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v0196 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v0196 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v0196 == SPID_NOPROP) v0196 = nil; else v0196 = lisp_true; }}
#endif
    if (v0196 == nil) goto v0108;
    v0197 = stack[-2];
    v0196 = stack[-1];
    fn = elt(env, 20); /* reval2 */
    v0196 = (*qfn2(fn))(qenv(fn), v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    goto v0012;

v0108:
    v0196 = stack[-2];
    goto v0012;

v0003:
    v0196 = stack[-2];
    if (!consp(v0196)) goto v0137;
    v0196 = stack[-2];
    v0196 = qcar(v0196);
    if (symbolp(v0196)) goto v0200;
    v0197 = stack[-2];
    v0196 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 21); /* errpri2 */
    v0196 = (*qfn2(fn))(qenv(fn), v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    goto v0021;

v0021:
    v0196 = stack[-2];
    fn = elt(env, 22); /* getrtype */
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    stack[0] = v0196;
    if (v0196 == nil) goto v0201;
    v0197 = stack[0];
    v0196 = elt(env, 6); /* evfn */
    v0196 = get(v0197, v0196);
    env = stack[-4];
    v0198 = v0196;
    if (v0196 == nil) goto v0202;
    v0197 = stack[-2];
    v0196 = stack[-1];
    v0196 = Lapply2(nil, 3, v0198, v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    goto v0012;

v0202:
    stack[-2] = elt(env, 11); /* alg */
    stack[-1] = (Lisp_Object)1617; /* 101 */
    v0197 = elt(env, 12); /* "Missing evaluation for type" */
    v0196 = stack[0];
    v0196 = list2(v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    fn = elt(env, 23); /* rerror */
    v0196 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    goto v0012;

v0201:
    v0196 = stack[-2];
    if (!consp(v0196)) goto v0203;
    v0196 = stack[-2];
    v0196 = qcdr(v0196);
    if (!consp(v0196)) goto v0204;
    v0196 = stack[-2];
    v0196 = qcdr(v0196);
    v0196 = qcar(v0196);
    fn = elt(env, 22); /* getrtype */
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    v0198 = v0196;
    if (v0196 == nil) goto v0205;
    v0197 = v0198;
    v0196 = elt(env, 13); /* list */
    if (v0197 == v0196) goto v0206;
    v0196 = qvalue(elt(env, 3)); /* nil */
    goto v0207;

v0207:
    if (v0196 == nil) goto v0208;
    v0196 = qvalue(elt(env, 3)); /* nil */
    goto v0209;

v0209:
    if (v0196 == nil) goto v0210;
    v0198 = stack[0];
    v0197 = stack[-2];
    v0196 = stack[-1];
    v0196 = Lapply2(nil, 3, v0198, v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    goto v0012;

v0210:
    v0197 = stack[-2];
    v0196 = stack[-1];
    fn = elt(env, 20); /* reval2 */
    v0196 = (*qfn2(fn))(qenv(fn), v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    goto v0012;

v0208:
    v0197 = v0198;
    v0196 = elt(env, 14); /* aggregatefn */
    v0196 = get(v0197, v0196);
    env = stack[-4];
    stack[0] = v0196;
    if (v0196 == nil) goto v0211;
    v0197 = stack[0];
    v0196 = elt(env, 15); /* matrixmap */
    if (v0197 == v0196) goto v0212;
    v0196 = qvalue(elt(env, 7)); /* t */
    goto v0213;

v0213:
    if (v0196 == nil) goto v0214;
    v0196 = stack[-2];
    v0197 = qcar(v0196);
    v0196 = elt(env, 17); /* boolean */
    v0196 = Lflagp(nil, v0197, v0196);
    env = stack[-4];
    if (v0196 == nil) goto v0215;
    v0196 = qvalue(elt(env, 3)); /* nil */
    goto v0209;

v0215:
    v0196 = qvalue(elt(env, 18)); /* !*listargs */
    if (v0196 == nil) goto v0216;
    v0196 = qvalue(elt(env, 3)); /* nil */
    goto v0209;

v0216:
    v0196 = stack[-2];
    v0197 = qcar(v0196);
    v0196 = elt(env, 19); /* listargp */
    v0196 = Lflagp(nil, v0197, v0196);
    env = stack[-4];
    v0196 = (v0196 == nil ? lisp_true : nil);
    goto v0209;

v0214:
    v0196 = qvalue(elt(env, 3)); /* nil */
    goto v0209;

v0212:
    v0196 = stack[-2];
    v0197 = qcar(v0196);
    v0196 = elt(env, 16); /* matmapfn */
    v0196 = Lflagp(nil, v0197, v0196);
    env = stack[-4];
    goto v0213;

v0211:
    v0196 = qvalue(elt(env, 3)); /* nil */
    goto v0209;

v0206:
    v0196 = stack[-2];
    v0196 = qcdr(v0196);
    v0196 = qcdr(v0196);
    goto v0207;

v0205:
    v0196 = qvalue(elt(env, 3)); /* nil */
    goto v0209;

v0204:
    v0196 = qvalue(elt(env, 3)); /* nil */
    goto v0209;

v0203:
    v0196 = qvalue(elt(env, 3)); /* nil */
    goto v0209;

v0200:
    v0196 = stack[-2];
    v0197 = qcar(v0196);
    v0196 = elt(env, 8); /* !*sq */
    if (v0197 == v0196) goto v0097;
    v0196 = stack[-2];
    v0196 = qcar(v0196);
    if (!symbolp(v0196)) v0196 = nil;
    else { v0196 = qfastgets(v0196);
           if (v0196 != nil) { v0196 = elt(v0196, 39); /* remember */
#ifdef RECORD_GET
             if (v0196 == SPID_NOPROP)
                record_get(elt(fastget_names, 39), 0),
                v0196 = nil;
             else record_get(elt(fastget_names, 39), 1),
                v0196 = lisp_true; }
           else record_get(elt(fastget_names, 39), 0); }
#else
             if (v0196 == SPID_NOPROP) v0196 = nil; else v0196 = lisp_true; }}
#endif
    if (v0196 == nil) goto v0217;
    v0197 = stack[-2];
    v0196 = stack[-1];
    fn = elt(env, 24); /* rmmbreval */
    v0196 = (*qfn2(fn))(qenv(fn), v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    goto v0012;

v0217:
    v0196 = stack[-2];
    v0196 = qcar(v0196);
    if (!symbolp(v0196)) v0196 = nil;
    else { v0196 = qfastgets(v0196);
           if (v0196 != nil) { v0196 = elt(v0196, 59); /* opfn */
#ifdef RECORD_GET
             if (v0196 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v0196 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v0196 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v0196 == SPID_NOPROP) v0196 = nil; else v0196 = lisp_true; }}
#endif
    if (v0196 == nil) goto v0218;
    v0196 = stack[-2];
    fn = elt(env, 25); /* opfneval */
    v0197 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    v0196 = stack[-1];
    v0196 = CC_reval1(env, v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    goto v0012;

v0218:
    v0196 = stack[-2];
    v0196 = qcar(v0196);
    if (!symbolp(v0196)) v0196 = nil;
    else { v0196 = qfastgets(v0196);
           if (v0196 != nil) { v0196 = elt(v0196, 45); /* psopfn */
#ifdef RECORD_GET
             if (v0196 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v0196 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v0196 == SPID_NOPROP) v0196 = nil; }}
#endif
    stack[0] = v0196;
    if (v0196 == nil) goto v0219;
    v0197 = stack[0];
    v0196 = stack[-2];
    v0196 = qcdr(v0196);
    v0196 = Lapply1(nil, v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    stack[-2] = v0196;
    v0197 = stack[0];
    v0196 = elt(env, 10); /* cleanupfn */
    v0196 = get(v0197, v0196);
    env = stack[-4];
    stack[0] = v0196;
    if (v0196 == nil) goto v0220;
    v0198 = stack[0];
    v0197 = stack[-2];
    v0196 = stack[-1];
    v0196 = Lapply2(nil, 3, v0198, v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    stack[-2] = v0196;
    goto v0220;

v0220:
    v0196 = stack[-2];
    goto v0012;

v0219:
    v0196 = stack[-2];
    v0196 = qcar(v0196);
    fn = elt(env, 26); /* arrayp */
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    if (v0196 == nil) goto v0021;
    v0196 = stack[-2];
    fn = elt(env, 27); /* getelv */
    v0197 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    v0196 = stack[-1];
    v0196 = CC_reval1(env, v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    goto v0012;

v0097:
    v0196 = stack[-2];
    v0196 = qcdr(v0196);
    v0196 = qcdr(v0196);
    v0196 = qcar(v0196);
    if (v0196 == nil) goto v0221;
    v0196 = qvalue(elt(env, 9)); /* !*resimp */
    if (!(v0196 == nil)) goto v0221;
    v0196 = stack[-1];
    if (v0196 == nil) goto v0048;
    v0196 = stack[-2];
    v0196 = qcdr(v0196);
    v0196 = qcar(v0196);
    fn = elt(env, 28); /* prepsqxx */
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    goto v0012;

v0048:
    v0196 = stack[-2];
    goto v0012;

v0221:
    v0197 = stack[-2];
    v0196 = stack[-1];
    fn = elt(env, 20); /* reval2 */
    v0196 = (*qfn2(fn))(qenv(fn), v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    goto v0012;

v0137:
    v0196 = qvalue(elt(env, 5)); /* subfg!* */
    if (v0196 == nil) goto v0033;
    v0196 = stack[-2];
    if (!(symbolp(v0196))) goto v0021;
    v0196 = stack[-2];
    if (!symbolp(v0196)) v0196 = nil;
    else { v0196 = qfastgets(v0196);
           if (v0196 != nil) { v0196 = elt(v0196, 4); /* avalue */
#ifdef RECORD_GET
             if (v0196 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0196 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0196 == SPID_NOPROP) v0196 = nil; }}
#endif
    stack[0] = v0196;
    if (v0196 == nil) goto v0021;
    v0197 = stack[-2];
    v0196 = qvalue(elt(env, 2)); /* varstack!* */
    v0196 = Lmemq(nil, v0197, v0196);
    if (v0196 == nil) goto v0092;
    v0196 = stack[-2];
    fn = elt(env, 29); /* recursiveerror */
    v0196 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    goto v0021;

v0092:
    v0197 = stack[-2];
    v0196 = qvalue(elt(env, 2)); /* varstack!* */
    v0196 = cons(v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0196; /* varstack!* */
    v0196 = stack[0];
    v0197 = qcar(v0196);
    v0196 = elt(env, 6); /* evfn */
    v0196 = get(v0197, v0196);
    env = stack[-4];
    v0198 = v0196;
    if (v0196 == nil) goto v0119;
    v0197 = stack[-2];
    v0196 = stack[-1];
    v0196 = Lapply2(nil, 3, v0198, v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    goto v0012;

v0119:
    v0196 = stack[0];
    v0196 = qcdr(v0196);
    v0197 = qcar(v0196);
    v0196 = stack[-1];
    v0196 = CC_reval1(env, v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-4];
    goto v0012;

v0033:
    v0196 = stack[-2];
    goto v0012;

v0013:
    v0196 = qvalue(elt(env, 3)); /* nil */
    goto v0012;
/* error exit handlers */
v0199:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; /* varstack!* */
    popv(5);
    return nil;
}



/* Code for groebsearchinlist */

static Lisp_Object CC_groebsearchinlist(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0008;
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
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0000;
/* end of prologue */

v0006:
    v0005 = stack[0];
    if (v0005 == nil) goto v0104;
    v0005 = stack[0];
    v0005 = qcar(v0005);
    v0005 = qcdr(v0005);
    v0008 = qcar(v0005);
    v0005 = stack[-1];
    fn = elt(env, 2); /* buchvevdivides!? */
    v0005 = (*qfn2(fn))(qenv(fn), v0008, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-2];
    if (v0005 == nil) goto v0016;
    v0005 = stack[0];
    v0005 = qcar(v0005);
    { popv(3); return onevalue(v0005); }

v0016:
    v0005 = stack[0];
    v0005 = qcdr(v0005);
    stack[0] = v0005;
    goto v0006;

v0104:
    v0005 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0005); }
/* error exit handlers */
v0072:
    popv(3);
    return nil;
}



/* Code for formc */

static Lisp_Object MS_CDECL CC_formc(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0106, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0061, v0062, v0114, v0222;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formc");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0106,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0009,v0106);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0106;
    stack[-1] = v0009;
    stack[-2] = v0000;
/* end of prologue */
    v0061 = qvalue(elt(env, 1)); /* !*rlisp88 */
    if (v0061 == nil) goto v0036;
    v0062 = stack[-2];
    v0061 = elt(env, 2); /* modefn */
    v0061 = Lflagpcar(nil, v0062, v0061);
    env = stack[-3];
    if (v0061 == nil) goto v0036;
    v0061 = stack[-2];
    v0062 = qcar(v0061);
    v0061 = elt(env, 3); /* symbolic */
    if (v0062 == v0061) goto v0036;
    v0062 = elt(env, 4); /* "algebraic expression" */
    v0061 = elt(env, 5); /* "Rlisp88 form" */
    {
        popv(4);
        fn = elt(env, 8); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0062, v0061);
    }

v0036:
    v0062 = stack[0];
    v0061 = elt(env, 6); /* algebraic */
    if (v0062 == v0061) goto v0067;
    v0061 = qvalue(elt(env, 7)); /* nil */
    goto v0105;

v0105:
    if (!(v0061 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0222 = stack[-2];
    v0114 = stack[-1];
    v0062 = elt(env, 3); /* symbolic */
    v0061 = stack[0];
    {
        popv(4);
        fn = elt(env, 9); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v0222, v0114, v0062, v0061);
    }

v0067:
    v0062 = stack[-2];
    v0061 = stack[-1];
    fn = elt(env, 10); /* intexprnp */
    v0061 = (*qfn2(fn))(qenv(fn), v0062, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-3];
    goto v0105;
/* error exit handlers */
v0063:
    popv(4);
    return nil;
}



/* Code for dp_ecart */

static Lisp_Object CC_dp_ecart(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0001;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_ecart");
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
    v0001 = stack[0];
    if (v0001 == nil) goto v0046;
    v0001 = stack[0];
    fn = elt(env, 1); /* dp!=ecart */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0001);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-2];
    v0001 = stack[0];
    fn = elt(env, 2); /* dp_lmon */
    v0001 = (*qfn1(fn))(qenv(fn), v0001);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-2];
    fn = elt(env, 3); /* mo_ecart */
    v0001 = (*qfn1(fn))(qenv(fn), v0001);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    {
        Lisp_Object v0082 = stack[-1];
        popv(3);
        return difference2(v0082, v0001);
    }

v0046:
    v0001 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0001); }
/* error exit handlers */
v0071:
    popv(3);
    return nil;
}



/* Code for oprin */

static Lisp_Object CC_oprin(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0027, v0120;
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
    v0027 = stack[0];
    if (!symbolp(v0027)) v0027 = nil;
    else { v0027 = qfastgets(v0027);
           if (v0027 != nil) { v0027 = elt(v0027, 37); /* prtch */
#ifdef RECORD_GET
             if (v0027 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v0027 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v0027 == SPID_NOPROP) v0027 = nil; }}
#endif
    stack[-1] = v0027;
    v0027 = stack[-1];
    if (v0027 == nil) goto v0111;
    v0027 = qvalue(elt(env, 2)); /* !*fort */
    if (v0027 == nil) goto v0022;
    v0027 = stack[-1];
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0027);
    }

v0022:
    v0027 = qvalue(elt(env, 3)); /* !*list */
    if (v0027 == nil) goto v0039;
    v0027 = qvalue(elt(env, 4)); /* obrkp!* */
    if (v0027 == nil) goto v0039;
    v0120 = stack[0];
    v0027 = elt(env, 5); /* (plus minus) */
    v0027 = Lmemq(nil, v0120, v0027);
    if (v0027 == nil) goto v0039;
    v0027 = qvalue(elt(env, 6)); /* testing!-width!* */
    if (v0027 == nil) goto v0036;
    v0027 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 8)) = v0027; /* overflowed!* */
    { popv(3); return onevalue(v0027); }

v0036:
    v0027 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 10); /* terpri!* */
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0027 = stack[-1];
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0027);
    }

v0039:
    v0027 = stack[0];
    if (!symbolp(v0027)) v0027 = nil;
    else { v0027 = qfastgets(v0027);
           if (v0027 != nil) { v0027 = elt(v0027, 61); /* spaced */
#ifdef RECORD_GET
             if (v0027 == SPID_NOPROP)
                record_get(elt(fastget_names, 61), 0),
                v0027 = nil;
             else record_get(elt(fastget_names, 61), 1),
                v0027 = lisp_true; }
           else record_get(elt(fastget_names, 61), 0); }
#else
             if (v0027 == SPID_NOPROP) v0027 = nil; else v0027 = lisp_true; }}
#endif
    if (v0027 == nil) goto v0042;
    v0027 = elt(env, 1); /* " " */
    fn = elt(env, 9); /* prin2!* */
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0027 = stack[-1];
    fn = elt(env, 9); /* prin2!* */
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0027 = elt(env, 1); /* " " */
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0027);
    }

v0042:
    v0027 = stack[-1];
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0027);
    }

v0111:
    v0027 = elt(env, 1); /* " " */
    fn = elt(env, 9); /* prin2!* */
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0027 = stack[0];
    fn = elt(env, 9); /* prin2!* */
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0027 = elt(env, 1); /* " " */
    {
        popv(3);
        fn = elt(env, 9); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0027);
    }
/* error exit handlers */
v0024:
    popv(3);
    return nil;
}



/* Code for rnplus!: */

static Lisp_Object CC_rnplusT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0067, v0109;
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
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0000;
/* end of prologue */
    v0067 = stack[-1];
    v0067 = qcdr(v0067);
    v0109 = qcar(v0067);
    v0067 = stack[0];
    v0067 = qcdr(v0067);
    v0067 = qcdr(v0067);
    stack[-2] = times2(v0109, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    v0067 = stack[-1];
    v0067 = qcdr(v0067);
    v0109 = qcdr(v0067);
    v0067 = stack[0];
    v0067 = qcdr(v0067);
    v0067 = qcar(v0067);
    v0067 = times2(v0109, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    stack[-2] = plus2(stack[-2], v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    v0067 = stack[-1];
    v0067 = qcdr(v0067);
    v0109 = qcdr(v0067);
    v0067 = stack[0];
    v0067 = qcdr(v0067);
    v0067 = qcdr(v0067);
    v0067 = times2(v0109, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    {
        Lisp_Object v0040 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v0040, v0067);
    }
/* error exit handlers */
v0035:
    popv(4);
    return nil;
}



/* Code for general!-plus!-mod!-p */

static Lisp_Object CC_generalKplusKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0178, v0138;
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
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0009;
    stack[-3] = v0000;
/* end of prologue */
    stack[0] = nil;
    goto v0070;

v0070:
    v0178 = stack[-3];
    if (v0178 == nil) goto v0032;
    v0178 = stack[-2];
    if (v0178 == nil) goto v0071;
    v0178 = stack[-3];
    if (!consp(v0178)) goto v0072;
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    v0178 = (consp(v0178) ? nil : lisp_true);
    goto v0073;

v0073:
    if (v0178 == nil) goto v0008;
    v0178 = stack[-2];
    if (!consp(v0178)) goto v0066;
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = (consp(v0178) ? nil : lisp_true);
    goto v0137;

v0137:
    if (v0178 == nil) goto v0061;
    v0138 = stack[-3];
    v0178 = stack[-2];
    fn = elt(env, 3); /* general!-modular!-plus */
    v0178 = (*qfn2(fn))(qenv(fn), v0138, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-5];
    fn = elt(env, 4); /* !*n2f */
    v0178 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-5];
    {
        Lisp_Object v0241 = stack[0];
        popv(6);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0241, v0178);
    }

v0061:
    v0178 = stack[-2];
    v0138 = qcar(v0178);
    v0178 = stack[0];
    v0178 = cons(v0138, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-5];
    stack[0] = v0178;
    v0178 = stack[-2];
    v0178 = qcdr(v0178);
    stack[-2] = v0178;
    goto v0070;

v0066:
    v0178 = qvalue(elt(env, 1)); /* t */
    goto v0137;

v0008:
    v0178 = stack[-2];
    if (!consp(v0178)) goto v0136;
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = (consp(v0178) ? nil : lisp_true);
    goto v0088;

v0088:
    if (v0178 == nil) goto v0117;
    v0178 = stack[-3];
    v0138 = qcar(v0178);
    v0178 = stack[0];
    v0178 = cons(v0138, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-5];
    stack[0] = v0178;
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    stack[-3] = v0178;
    goto v0070;

v0117:
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    v0138 = qcar(v0178);
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    if (equal(v0138, v0178)) goto v0087;
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0138 = qcar(v0178);
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    if (equal(v0138, v0178)) goto v0242;
    v0178 = qvalue(elt(env, 2)); /* nil */
    goto v0243;

v0243:
    if (!(v0178 == nil)) goto v0244;
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0138 = qcar(v0178);
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    if (equal(v0138, v0178)) goto v0182;
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0138 = qcar(v0178);
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    fn = elt(env, 6); /* ordop */
    v0178 = (*qfn2(fn))(qenv(fn), v0138, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-5];
    goto v0245;

v0245:
    if (!(v0178 == nil)) goto v0244;
    v0178 = stack[-2];
    v0138 = qcar(v0178);
    v0178 = stack[0];
    v0178 = cons(v0138, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-5];
    stack[0] = v0178;
    v0178 = stack[-2];
    v0178 = qcdr(v0178);
    stack[-2] = v0178;
    goto v0070;

v0244:
    v0178 = stack[-3];
    v0138 = qcar(v0178);
    v0178 = stack[0];
    v0178 = cons(v0138, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-5];
    stack[0] = v0178;
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    stack[-3] = v0178;
    goto v0070;

v0182:
    v0178 = qvalue(elt(env, 2)); /* nil */
    goto v0245;

v0242:
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0138 = qcdr(v0178);
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcar(v0178);
    v0178 = qcdr(v0178);
    v0178 = ((intptr_t)v0138 > (intptr_t)v0178) ? lisp_true : nil;
    goto v0243;

v0087:
    stack[-4] = stack[0];
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    stack[-1] = qcar(v0178);
    v0178 = stack[-3];
    v0178 = qcar(v0178);
    v0138 = qcdr(v0178);
    v0178 = stack[-2];
    v0178 = qcar(v0178);
    v0178 = qcdr(v0178);
    stack[0] = CC_generalKplusKmodKp(env, v0138, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-5];
    v0178 = stack[-3];
    v0138 = qcdr(v0178);
    v0178 = stack[-2];
    v0178 = qcdr(v0178);
    v0178 = CC_generalKplusKmodKp(env, v0138, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-5];
    fn = elt(env, 7); /* adjoin!-term */
    v0178 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-5];
    {
        Lisp_Object v0246 = stack[-4];
        popv(6);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0246, v0178);
    }

v0136:
    v0178 = qvalue(elt(env, 1)); /* t */
    goto v0088;

v0072:
    v0178 = qvalue(elt(env, 1)); /* t */
    goto v0073;

v0071:
    v0138 = stack[0];
    v0178 = stack[-3];
    {
        popv(6);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0138, v0178);
    }

v0032:
    v0138 = stack[0];
    v0178 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0138, v0178);
    }
/* error exit handlers */
v0166:
    popv(6);
    return nil;
}



/* Code for sort!-factors */

static Lisp_Object CC_sortKfactors(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0081, v0010;
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
    v0081 = v0000;
/* end of prologue */
    v0010 = v0081;
    v0081 = elt(env, 1); /* orderfactors */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v0010, v0081);
    }
}



/* Code for ibalp_varlat */

static Lisp_Object CC_ibalp_varlat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044;
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
    v0044 = stack[0];
    fn = elt(env, 1); /* ibalp_arg2l */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-2];
    fn = elt(env, 2); /* ibalp_varlt */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-2];
    v0044 = stack[0];
    fn = elt(env, 3); /* ibalp_arg2r */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-2];
    fn = elt(env, 2); /* ibalp_varlt */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-2];
    {
        Lisp_Object v0021 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* union */
        return (*qfn2(fn))(qenv(fn), v0021, v0044);
    }
/* error exit handlers */
v0022:
    popv(3);
    return nil;
}



/* Code for checktag */

static Lisp_Object CC_checktag(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0116, v0071;
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
    v0116 = v0000;
/* end of prologue */
    v0071 = qvalue(elt(env, 1)); /* char */
    if (equal(v0071, v0116)) goto v0006;
    v0071 = elt(env, 2); /* "Problem" */
    v0116 = elt(env, 3); /* "problem" */
    fn = elt(env, 4); /* errorml */
    v0116 = (*qfn2(fn))(qenv(fn), v0071, v0116);
    errexit();
    goto v0006;

v0006:
    v0116 = nil;
    return onevalue(v0116);
}



/* Code for simp!* */

static Lisp_Object CC_simpH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0099, v0101;
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
    v0101 = stack[-2];
    v0099 = elt(env, 2); /* !*sq */
    if (!consp(v0101)) goto v0072;
    v0101 = qcar(v0101);
    if (!(v0101 == v0099)) goto v0072;
    v0099 = stack[-2];
    v0099 = qcdr(v0099);
    v0099 = qcdr(v0099);
    v0099 = qcar(v0099);
    if (v0099 == nil) goto v0071;
    v0099 = qvalue(elt(env, 4)); /* !*resimp */
    v0099 = (v0099 == nil ? lisp_true : nil);
    goto v0010;

v0010:
    if (v0099 == nil) goto v0037;
    v0099 = stack[-2];
    v0099 = qcdr(v0099);
    v0099 = qcar(v0099);
    goto v0006;

v0006:
    qvalue(elt(env, 1)) = stack[-3]; /* !*asymp!* */
    { popv(5); return onevalue(v0099); }

v0037:
    v0101 = qvalue(elt(env, 5)); /* mul!* */
    v0099 = qvalue(elt(env, 6)); /* !*sub2 */
    v0099 = cons(v0101, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    stack[-1] = v0099;
    v0099 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 5)) = v0099; /* mul!* */
    v0099 = stack[-2];
    fn = elt(env, 14); /* simp */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    stack[-2] = v0099;
    v0099 = qvalue(elt(env, 7)); /* !*nospurp */
    if (v0099 == nil) goto v0015;
    v0101 = qvalue(elt(env, 5)); /* mul!* */
    v0099 = elt(env, 8); /* (isimpq) */
    fn = elt(env, 15); /* union */
    v0099 = (*qfn2(fn))(qenv(fn), v0101, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    qvalue(elt(env, 5)) = v0099; /* mul!* */
    goto v0015;

v0015:
    v0099 = qvalue(elt(env, 5)); /* mul!* */
    stack[0] = v0099;
    goto v0025;

v0025:
    v0099 = stack[0];
    if (v0099 == nil) goto v0024;
    v0099 = stack[0];
    v0099 = qcar(v0099);
    v0101 = v0099;
    v0099 = stack[-2];
    v0099 = Lapply1(nil, v0101, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    stack[-2] = v0099;
    v0099 = stack[0];
    v0099 = qcdr(v0099);
    stack[0] = v0099;
    goto v0025;

v0024:
    v0099 = stack[-1];
    v0099 = qcar(v0099);
    qvalue(elt(env, 5)) = v0099; /* mul!* */
    v0099 = stack[-2];
    fn = elt(env, 16); /* subs2 */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    stack[-2] = v0099;
    v0099 = qvalue(elt(env, 9)); /* !*combinelogs */
    if (v0099 == nil) goto v0095;
    v0099 = stack[-2];
    fn = elt(env, 17); /* clogsq!* */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    stack[-2] = v0099;
    goto v0095;

v0095:
    v0101 = qvalue(elt(env, 10)); /* dmode!* */
    v0099 = elt(env, 11); /* !:gi!: */
    if (v0101 == v0099) goto v0248;
    v0099 = qvalue(elt(env, 3)); /* nil */
    goto v0249;

v0249:
    if (v0099 == nil) goto v0135;
    v0099 = stack[-2];
    fn = elt(env, 18); /* girationalize!: */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    stack[-2] = v0099;
    goto v0079;

v0079:
    v0099 = stack[-1];
    v0099 = qcdr(v0099);
    qvalue(elt(env, 6)) = v0099; /* !*sub2 */
    v0099 = qvalue(elt(env, 1)); /* !*asymp!* */
    if (v0099 == nil) goto v0250;
    v0099 = qvalue(elt(env, 13)); /* !*rationalize */
    if (v0099 == nil) goto v0250;
    v0099 = stack[-2];
    fn = elt(env, 19); /* gcdchk */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    stack[-2] = v0099;
    goto v0250;

v0250:
    v0099 = stack[-2];
    goto v0006;

v0135:
    v0099 = qvalue(elt(env, 13)); /* !*rationalize */
    if (v0099 == nil) goto v0251;
    v0099 = stack[-2];
    fn = elt(env, 20); /* rationalizesq */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    stack[-2] = v0099;
    goto v0079;

v0251:
    v0099 = stack[-2];
    fn = elt(env, 21); /* rationalizei */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    env = stack[-4];
    stack[-2] = v0099;
    goto v0079;

v0248:
    v0099 = qvalue(elt(env, 12)); /* !*norationalgi */
    v0099 = (v0099 == nil ? lisp_true : nil);
    goto v0249;

v0071:
    v0099 = qvalue(elt(env, 3)); /* nil */
    goto v0010;

v0072:
    v0099 = qvalue(elt(env, 3)); /* nil */
    goto v0010;
/* error exit handlers */
v0051:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* !*asymp!* */
    popv(5);
    return nil;
}



/* Code for symtabget */

static Lisp_Object CC_symtabget(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0137, v0066, v0067, v0109;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for symtabget");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0067 = v0009;
    v0066 = v0000;
/* end of prologue */
    v0137 = v0067;
    if (v0137 == nil) goto v0046;
    v0137 = v0066;
    if (!(v0137 == nil)) goto v0031;
    v0137 = qvalue(elt(env, 1)); /* !*symboltable!* */
    v0137 = qcar(v0137);
    goto v0031;

v0031:
    v0066 = v0137;
    goto v0046;

v0046:
    v0137 = v0066;
    if (v0137 == nil) goto v0012;
    v0137 = v0067;
    v0109 = elt(env, 2); /* (!*type!* !*params!* !*decs!*) */
    v0137 = Lmemq(nil, v0137, v0109);
    if (v0137 == nil) goto v0105;
    v0137 = v0066;
    v0066 = v0067;
    return get(v0137, v0066);

v0105:
    v0137 = v0067;
    if (!symbolp(v0066)) v0066 = nil;
    else { v0066 = qfastgets(v0066);
           if (v0066 != nil) { v0066 = elt(v0066, 58); /* !*decs!* */
#ifdef RECORD_GET
             if (v0066 != SPID_NOPROP)
                record_get(elt(fastget_names, 58), 1);
             else record_get(elt(fastget_names, 58), 0),
                v0066 = nil; }
           else record_get(elt(fastget_names, 58), 0); }
#else
             if (v0066 == SPID_NOPROP) v0066 = nil; }}
#endif
    v0137 = Lassoc(nil, v0137, v0066);
    return onevalue(v0137);

v0012:
    v0137 = qvalue(elt(env, 1)); /* !*symboltable!* */
    return onevalue(v0137);
}



/* Code for groebcpcompless!? */

static Lisp_Object CC_groebcpcomplessW(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0117, v0118, v0119, v0252;
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
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0000;
/* end of prologue */
    v0117 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v0117 == nil) goto v0249;
    v0117 = stack[-1];
    v0117 = qcdr(v0117);
    v0117 = qcdr(v0117);
    v0117 = qcdr(v0117);
    v0118 = qcar(v0117);
    v0117 = stack[0];
    v0117 = qcdr(v0117);
    v0117 = qcdr(v0117);
    v0117 = qcdr(v0117);
    v0117 = qcar(v0117);
    stack[-2] = difference2(v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    v0117 = stack[-1];
    v0118 = qcar(v0117);
    v0117 = stack[0];
    v0117 = qcar(v0117);
    fn = elt(env, 3); /* vevcomp */
    v0117 = (*qfn2(fn))(qenv(fn), v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    v0252 = stack[-2];
    v0119 = v0117;
    v0118 = v0252;
    v0117 = (Lisp_Object)1; /* 0 */
    if (v0118 == v0117) goto v0040;
    v0118 = v0252;
    v0117 = (Lisp_Object)1; /* 0 */
        popv(4);
        return Llessp(nil, v0118, v0117);

v0040:
    v0118 = v0119;
    v0117 = (Lisp_Object)1; /* 0 */
    if (v0118 == v0117) goto v0222;
    v0118 = v0119;
    v0117 = (Lisp_Object)1; /* 0 */
        popv(4);
        return Llessp(nil, v0118, v0117);

v0222:
    v0117 = stack[-1];
    v0117 = qcdr(v0117);
    v0117 = qcdr(v0117);
    v0118 = qcar(v0117);
    v0117 = elt(env, 2); /* number */
    fn = elt(env, 4); /* vdpgetprop */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-3];
    v0117 = stack[0];
    v0117 = qcdr(v0117);
    v0117 = qcdr(v0117);
    v0118 = qcar(v0117);
    v0117 = elt(env, 2); /* number */
    fn = elt(env, 4); /* vdpgetprop */
    v0117 = (*qfn2(fn))(qenv(fn), v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    {
        Lisp_Object v0058 = stack[-1];
        popv(4);
        return Llessp(nil, v0058, v0117);
    }

v0249:
    v0117 = stack[-1];
    v0118 = qcar(v0117);
    v0117 = stack[0];
    v0117 = qcar(v0117);
    {
        popv(4);
        fn = elt(env, 5); /* vevcompless!? */
        return (*qfn2(fn))(qenv(fn), v0118, v0117);
    }
/* error exit handlers */
v0121:
    popv(4);
    return nil;
}



/* Code for layout!-formula */

static Lisp_Object MS_CDECL CC_layoutKformula(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0106, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "layout-formula");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for layout-formula");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0106,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0009,v0106);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0106;
    stack[-7] = v0009;
    stack[-8] = v0000;
/* end of prologue */
    stack[-9] = qvalue(elt(env, 1)); /* ycoord!* */
    qvalue(elt(env, 1)) = nil; /* ycoord!* */
    stack[-5] = qvalue(elt(env, 2)); /* ymin!* */
    qvalue(elt(env, 2)) = nil; /* ymin!* */
    stack[-4] = qvalue(elt(env, 3)); /* ymax!* */
    qvalue(elt(env, 3)) = nil; /* ymax!* */
    stack[-3] = qvalue(elt(env, 4)); /* posn!* */
    qvalue(elt(env, 4)) = nil; /* posn!* */
    stack[-2] = qvalue(elt(env, 5)); /* pline!* */
    qvalue(elt(env, 5)) = nil; /* pline!* */
    stack[-1] = qvalue(elt(env, 6)); /* testing!-width!* */
    qvalue(elt(env, 6)) = nil; /* testing!-width!* */
    stack[0] = qvalue(elt(env, 7)); /* overflowed!* */
    qvalue(elt(env, 7)) = nil; /* overflowed!* */
    v0089 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 7)) = v0089; /* overflowed!* */
    qvalue(elt(env, 5)) = v0089; /* pline!* */
    v0089 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v0089; /* ymax!* */
    qvalue(elt(env, 2)) = v0089; /* ymin!* */
    qvalue(elt(env, 1)) = v0089; /* ycoord!* */
    v0089 = qvalue(elt(env, 9)); /* orig!* */
    qvalue(elt(env, 4)) = v0089; /* posn!* */
    v0089 = qvalue(elt(env, 10)); /* t */
    qvalue(elt(env, 6)) = v0089; /* testing!-width!* */
    v0089 = stack[-6];
    if (v0089 == nil) goto v0105;
    v0133 = stack[-6];
    v0089 = elt(env, 11); /* inbrackets */
    if (v0133 == v0089) goto v0071;
    v0089 = stack[-6];
    fn = elt(env, 14); /* oprin */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-10];
    goto v0105;

v0105:
    v0133 = stack[-8];
    v0089 = stack[-7];
    fn = elt(env, 15); /* maprint */
    v0089 = (*qfn2(fn))(qenv(fn), v0133, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-10];
    v0133 = stack[-6];
    v0089 = elt(env, 11); /* inbrackets */
    if (!(v0133 == v0089)) goto v0094;
    v0089 = elt(env, 13); /* ")" */
    fn = elt(env, 16); /* prin2!* */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-10];
    goto v0094;

v0094:
    v0089 = qvalue(elt(env, 7)); /* overflowed!* */
    if (v0089 == nil) goto v0026;
    v0089 = qvalue(elt(env, 8)); /* nil */
    goto v0007;

v0007:
    qvalue(elt(env, 7)) = stack[0]; /* overflowed!* */
    qvalue(elt(env, 6)) = stack[-1]; /* testing!-width!* */
    qvalue(elt(env, 5)) = stack[-2]; /* pline!* */
    qvalue(elt(env, 4)) = stack[-3]; /* posn!* */
    qvalue(elt(env, 3)) = stack[-4]; /* ymax!* */
    qvalue(elt(env, 2)) = stack[-5]; /* ymin!* */
    qvalue(elt(env, 1)) = stack[-9]; /* ycoord!* */
    { popv(11); return onevalue(v0089); }

v0026:
    stack[-7] = qvalue(elt(env, 5)); /* pline!* */
    v0133 = qvalue(elt(env, 4)); /* posn!* */
    v0089 = qvalue(elt(env, 9)); /* orig!* */
    stack[-6] = difference2(v0133, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-10];
    v0133 = qvalue(elt(env, 2)); /* ymin!* */
    v0089 = qvalue(elt(env, 3)); /* ymax!* */
    v0089 = cons(v0133, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-10];
    v0089 = acons(stack[-7], stack[-6], v0089);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-10];
    goto v0007;

v0071:
    v0089 = elt(env, 12); /* "(" */
    fn = elt(env, 16); /* prin2!* */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-10];
    goto v0105;
/* error exit handlers */
v0249:
    env = stack[-10];
    qvalue(elt(env, 7)) = stack[0]; /* overflowed!* */
    qvalue(elt(env, 6)) = stack[-1]; /* testing!-width!* */
    qvalue(elt(env, 5)) = stack[-2]; /* pline!* */
    qvalue(elt(env, 4)) = stack[-3]; /* posn!* */
    qvalue(elt(env, 3)) = stack[-4]; /* ymax!* */
    qvalue(elt(env, 2)) = stack[-5]; /* ymin!* */
    qvalue(elt(env, 1)) = stack[-9]; /* ycoord!* */
    popv(11);
    return nil;
}



/* Code for red!-ratios2 */

static Lisp_Object MS_CDECL CC_redKratios2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0106, Lisp_Object v0049, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0113, v0056, v0054, v0194;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "red-ratios2");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red-ratios2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0049,v0106,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0009,v0106,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0049;
    stack[-2] = v0106;
    stack[-3] = v0009;
    stack[-4] = v0000;
/* end of prologue */

v0098:
    v0113 = stack[-4];
    if (v0113 == nil) goto v0010;
    v0056 = stack[-2];
    v0113 = stack[-3];
    v0113 = qcar(v0113);
    stack[0] = times2(v0056, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-6];
    stack[-5] = stack[0];
    v0056 = stack[-1];
    v0113 = stack[-4];
    v0113 = qcar(v0113);
    v0113 = times2(v0056, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-6];
    if (equal(stack[0], v0113)) goto v0094;
    v0113 = qvalue(elt(env, 1)); /* nil */
    goto v0021;

v0021:
    if (v0113 == nil) goto v0133;
    v0056 = stack[-1];
    v0113 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* red!-lowest!-terms */
        return (*qfn2(fn))(qenv(fn), v0056, v0113);
    }

v0133:
    v0113 = stack[-4];
    v0194 = qcdr(v0113);
    v0113 = stack[-3];
    v0054 = qcdr(v0113);
    v0056 = stack[-2];
    v0113 = stack[-1];
    stack[-4] = v0194;
    stack[-3] = v0054;
    stack[-2] = v0056;
    stack[-1] = v0113;
    goto v0098;

v0094:
    v0056 = stack[-5];
    v0113 = (Lisp_Object)1; /* 0 */
    if (v0056 == v0113) goto v0125;
    v0056 = stack[-1];
    v0113 = stack[-2];
    v0056 = Lgcd(nil, v0056, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-6];
    v0113 = stack[-1];
    v0056 = Cremainder(v0056, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-6];
    v0113 = (Lisp_Object)1; /* 0 */
    v0113 = (v0056 == v0113 ? lisp_true : nil);
    goto v0021;

v0125:
    v0113 = qvalue(elt(env, 1)); /* nil */
    goto v0021;

v0010:
    v0113 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0113); }
/* error exit handlers */
v0057:
    popv(7);
    return nil;
}



/* Code for ordn */

static Lisp_Object CC_ordn(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordn");
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
    v0036 = v0000;
/* end of prologue */
    v0037 = v0036;
    if (v0037 == nil) goto v0046;
    v0037 = v0036;
    v0037 = qcdr(v0037);
    if (v0037 == nil) { popv(2); return onevalue(v0036); }
    v0037 = v0036;
    v0037 = qcdr(v0037);
    v0037 = qcdr(v0037);
    if (v0037 == nil) goto v0013;
    v0037 = v0036;
    stack[0] = qcar(v0037);
    v0037 = v0036;
    v0037 = qcdr(v0037);
    v0037 = CC_ordn(env, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-1];
    {
        Lisp_Object v0108 = stack[0];
        popv(2);
        fn = elt(env, 2); /* ordad */
        return (*qfn2(fn))(qenv(fn), v0108, v0037);
    }

v0013:
    v0037 = v0036;
    v0037 = qcar(v0037);
    v0036 = qcdr(v0036);
    v0036 = qcar(v0036);
    {
        popv(2);
        fn = elt(env, 3); /* ord2 */
        return (*qfn2(fn))(qenv(fn), v0037, v0036);
    }

v0046:
    v0037 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0037); }
/* error exit handlers */
v0126:
    popv(2);
    return nil;
}



/* Code for divide!: */

static Lisp_Object MS_CDECL CC_divideT(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0106, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0025;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "divide:");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for divide:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0106,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0009,v0106);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0106;
    stack[-2] = v0009;
    stack[-3] = v0000;
/* end of prologue */
    stack[0] = stack[-1];
    v0024 = stack[-2];
    v0024 = qcdr(v0024);
    v0024 = qcar(v0024);
    v0024 = Labsval(nil, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-5];
    fn = elt(env, 2); /* msd */
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-5];
    v0024 = add1(v0024);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-5];
    v0024 = plus2(stack[0], v0024);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-5];
    fn = elt(env, 3); /* conv!:mt */
    v0024 = (*qfn2(fn))(qenv(fn), stack[-3], v0024);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-5];
    stack[-3] = v0024;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v0024 = stack[-3];
    v0024 = qcdr(v0024);
    v0025 = qcar(v0024);
    v0024 = stack[-2];
    v0024 = qcdr(v0024);
    v0024 = qcar(v0024);
    stack[0] = quot2(v0025, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-5];
    v0024 = stack[-3];
    v0024 = qcdr(v0024);
    v0025 = qcdr(v0024);
    v0024 = stack[-2];
    v0024 = qcdr(v0024);
    v0024 = qcdr(v0024);
    v0024 = difference2(v0025, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-5];
    v0024 = list2star(stack[-4], stack[0], v0024);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-5];
    stack[-3] = v0024;
    v0025 = stack[-3];
    v0024 = stack[-1];
    {
        popv(6);
        fn = elt(env, 4); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v0025, v0024);
    }
/* error exit handlers */
v0030:
    popv(6);
    return nil;
}



/* Code for reduce!-mod!-p */

static Lisp_Object CC_reduceKmodKp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0107;
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
    v0107 = stack[-1];
    if (v0107 == nil) goto v0046;
    v0107 = stack[-1];
    if (!consp(v0107)) goto v0007;
    v0107 = stack[-1];
    v0107 = qcar(v0107);
    v0107 = (consp(v0107) ? nil : lisp_true);
    goto v0010;

v0010:
    if (v0107 == nil) goto v0016;
    v0107 = stack[-1];
    v0107 = Lmodular_number(nil, v0107);
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 3); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v0107);
    }

v0016:
    v0107 = stack[-1];
    v0107 = qcar(v0107);
    stack[-2] = qcar(v0107);
    v0107 = stack[-1];
    v0107 = qcar(v0107);
    v0107 = qcdr(v0107);
    stack[0] = CC_reduceKmodKp(env, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0107 = stack[-1];
    v0107 = qcdr(v0107);
    v0107 = CC_reduceKmodKp(env, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    {
        Lisp_Object v0137 = stack[-2];
        Lisp_Object v0066 = stack[0];
        popv(4);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0137, v0066, v0107);
    }

v0007:
    v0107 = qvalue(elt(env, 2)); /* t */
    goto v0010;

v0046:
    v0107 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0107); }
/* error exit handlers */
v0094:
    popv(4);
    return nil;
}



/* Code for retimes1 */

static Lisp_Object CC_retimes1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0132, v0057;
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
    goto v0006;

v0006:
    v0132 = stack[0];
    if (v0132 == nil) goto v0104;
    v0132 = stack[0];
    v0057 = qcar(v0132);
    v0132 = (Lisp_Object)17; /* 1 */
    if (v0057 == v0132) goto v0032;
    v0132 = stack[0];
    v0132 = qcar(v0132);
    v0132 = Lminusp(nil, v0132);
    env = stack[-2];
    if (v0132 == nil) goto v0038;
    v0132 = qvalue(elt(env, 1)); /* !*bool */
    v0132 = (v0132 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v0132; /* !*bool */
    v0132 = stack[0];
    v0132 = qcar(v0132);
    v0057 = negate(v0132);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    v0132 = stack[0];
    v0132 = qcdr(v0132);
    v0132 = cons(v0057, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    stack[0] = v0132;
    goto v0006;

v0038:
    v0132 = stack[0];
    v0132 = qcar(v0132);
    if (!consp(v0132)) goto v0094;
    v0132 = stack[0];
    v0132 = qcar(v0132);
    v0057 = qcar(v0132);
    v0132 = elt(env, 2); /* minus */
    if (v0057 == v0132) goto v0041;
    v0132 = stack[0];
    v0132 = qcar(v0132);
    v0057 = qcar(v0132);
    v0132 = elt(env, 3); /* times */
    if (v0057 == v0132) goto v0255;
    v0132 = stack[0];
    v0057 = qcar(v0132);
    v0132 = stack[-1];
    v0132 = cons(v0057, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    stack[-1] = v0132;
    v0132 = stack[0];
    v0132 = qcdr(v0132);
    stack[0] = v0132;
    goto v0006;

v0255:
    v0132 = stack[0];
    v0132 = qcar(v0132);
    v0057 = qcdr(v0132);
    v0132 = stack[0];
    v0132 = qcdr(v0132);
    v0132 = Lappend(nil, v0057, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    stack[0] = v0132;
    goto v0006;

v0041:
    v0132 = qvalue(elt(env, 1)); /* !*bool */
    v0132 = (v0132 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v0132; /* !*bool */
    v0132 = stack[0];
    v0132 = qcar(v0132);
    v0132 = qcdr(v0132);
    v0057 = qcar(v0132);
    v0132 = stack[0];
    v0132 = qcdr(v0132);
    v0132 = cons(v0057, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    stack[0] = v0132;
    goto v0006;

v0094:
    v0132 = stack[0];
    v0057 = qcar(v0132);
    v0132 = stack[-1];
    v0132 = cons(v0057, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    stack[-1] = v0132;
    v0132 = stack[0];
    v0132 = qcdr(v0132);
    stack[0] = v0132;
    goto v0006;

v0032:
    v0132 = stack[0];
    v0132 = qcdr(v0132);
    stack[0] = v0132;
    goto v0006;

v0104:
    v0132 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0132);
    }
/* error exit handlers */
v0058:
    popv(3);
    return nil;
}



/* Code for rl_prepat */

static Lisp_Object CC_rl_prepat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010;
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
    v0010 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_prepat!* */
    v0010 = ncons(v0010);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-1];
    {
        Lisp_Object v0044 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0044, v0010);
    }
/* error exit handlers */
v0032:
    popv(2);
    return nil;
}



/* Code for xxsort */

static Lisp_Object CC_xxsort(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0081, v0010;
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
    v0081 = v0000;
/* end of prologue */
    v0010 = v0081;
    v0081 = elt(env, 1); /* lambda_mth9cq_1 */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v0010, v0081);
    }
}



/* Code for lambda_mth9cq_1 */

static Lisp_Object CC_lambda_mth9cq_1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0001;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_mth9cq_1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0002 = v0009;
    v0001 = v0000;
/* end of prologue */
    v0001 = qcar(v0001);
    v0002 = qcar(v0002);
    fn = elt(env, 1); /* termorder */
    v0001 = (*qfn2(fn))(qenv(fn), v0001, v0002);
    errexit();
    v0002 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v0001, v0002);
}



/* Code for gcdf */

static Lisp_Object CC_gcdf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0249, v0248;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0009;
    stack[-3] = v0000;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = nil; /* !*exp */
    stack[-1] = qvalue(elt(env, 2)); /* !*rounded */
    qvalue(elt(env, 2)) = nil; /* !*rounded */
    v0249 = qvalue(elt(env, 3)); /* !*mcd */
    stack[0] = v0249;
    v0249 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 1)) = v0249; /* !*exp */
    v0249 = stack[-3];
    if (!consp(v0249)) goto v0002;
    v0249 = stack[-3];
    v0249 = qcar(v0249);
    v0249 = (consp(v0249) ? nil : lisp_true);
    goto v0013;

v0013:
    if (v0249 == nil) goto v0004;
    v0249 = qvalue(elt(env, 4)); /* t */
    goto v0011;

v0011:
    if (v0249 == nil) goto v0064;
    v0249 = qvalue(elt(env, 7)); /* !*combineexpt */
    if (v0249 == nil) goto v0090;
    v0249 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 3)) = v0249; /* !*mcd */
    goto v0090;

v0090:
    v0248 = stack[-3];
    v0249 = stack[-2];
    fn = elt(env, 8); /* gcdf1 */
    v0249 = (*qfn2(fn))(qenv(fn), v0248, v0249);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-5];
    goto v0010;

v0010:
    stack[-3] = v0249;
    v0249 = stack[0];
    qvalue(elt(env, 3)) = v0249; /* !*mcd */
    v0249 = stack[-3];
    fn = elt(env, 9); /* minusf */
    v0249 = (*qfn1(fn))(qenv(fn), v0249);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-5];
    if (v0249 == nil) goto v0134;
    v0249 = stack[-3];
    fn = elt(env, 10); /* negf */
    v0249 = (*qfn1(fn))(qenv(fn), v0249);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-5];
    goto v0111;

v0111:
    qvalue(elt(env, 2)) = stack[-1]; /* !*rounded */
    qvalue(elt(env, 1)) = stack[-4]; /* !*exp */
    { popv(6); return onevalue(v0249); }

v0134:
    v0249 = stack[-3];
    goto v0111;

v0064:
    v0248 = stack[-3];
    v0249 = stack[-2];
    fn = elt(env, 11); /* ezgcdf */
    v0249 = (*qfn2(fn))(qenv(fn), v0248, v0249);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-5];
    goto v0010;

v0004:
    v0249 = stack[-2];
    if (!consp(v0249)) goto v0018;
    v0249 = stack[-2];
    v0249 = qcar(v0249);
    v0249 = (consp(v0249) ? nil : lisp_true);
    goto v0020;

v0020:
    if (v0249 == nil) goto v0094;
    v0249 = qvalue(elt(env, 4)); /* t */
    goto v0011;

v0094:
    v0249 = qvalue(elt(env, 5)); /* !*ezgcd */
    if (v0249 == nil) goto v0109;
    v0249 = qvalue(elt(env, 6)); /* dmode!* */
    if (!(v0249 == nil)) goto v0011;
    v0249 = stack[-3];
    fn = elt(env, 12); /* free!-powerp */
    v0249 = (*qfn1(fn))(qenv(fn), v0249);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-5];
    if (!(v0249 == nil)) goto v0011;
    v0249 = stack[-2];
    fn = elt(env, 12); /* free!-powerp */
    v0249 = (*qfn1(fn))(qenv(fn), v0249);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-5];
    goto v0011;

v0109:
    v0249 = qvalue(elt(env, 4)); /* t */
    goto v0011;

v0018:
    v0249 = qvalue(elt(env, 4)); /* t */
    goto v0020;

v0002:
    v0249 = qvalue(elt(env, 4)); /* t */
    goto v0013;
/* error exit handlers */
v0194:
    env = stack[-5];
    qvalue(elt(env, 2)) = stack[-1]; /* !*rounded */
    qvalue(elt(env, 1)) = stack[-4]; /* !*exp */
    popv(6);
    return nil;
}



/* Code for mintype */

static Lisp_Object CC_mintype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0032;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mintype");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0007 = v0000;
/* end of prologue */
    v0032 = v0007;
    if (!consp(v0032)) return onevalue(v0007);
    v0007 = qcar(v0007);
    return onevalue(v0007);
}



/* Code for addpf */

static Lisp_Object CC_addpf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0260, v0261, v0262;
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
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0009;
    stack[-2] = v0000;
/* end of prologue */
    stack[0] = nil;
    goto v0070;

v0070:
    v0260 = stack[-2];
    if (v0260 == nil) goto v0032;
    v0260 = stack[-1];
    if (v0260 == nil) goto v0071;
    v0260 = stack[-2];
    v0260 = qcar(v0260);
    v0261 = qcar(v0260);
    v0260 = (Lisp_Object)17; /* 1 */
    if (v0261 == v0260) goto v0066;
    v0260 = stack[-1];
    v0260 = qcar(v0260);
    v0261 = qcar(v0260);
    v0260 = (Lisp_Object)17; /* 1 */
    if (v0261 == v0260) goto v0090;
    v0260 = stack[-2];
    v0260 = qcar(v0260);
    v0261 = qcar(v0260);
    v0260 = stack[-1];
    v0260 = qcar(v0260);
    v0260 = qcar(v0260);
    if (equal(v0261, v0260)) goto v0263;
    v0260 = stack[-2];
    v0260 = qcar(v0260);
    v0261 = qcar(v0260);
    v0260 = stack[-1];
    v0260 = qcar(v0260);
    v0260 = qcar(v0260);
    fn = elt(env, 1); /* ordop */
    v0260 = (*qfn2(fn))(qenv(fn), v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-4];
    if (v0260 == nil) goto v0264;
    v0260 = stack[-2];
    v0261 = qcar(v0260);
    v0260 = stack[0];
    v0260 = cons(v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-4];
    stack[0] = v0260;
    v0260 = stack[-2];
    v0260 = qcdr(v0260);
    stack[-2] = v0260;
    goto v0070;

v0264:
    v0260 = stack[-1];
    v0261 = qcar(v0260);
    v0260 = stack[0];
    v0260 = cons(v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-4];
    stack[0] = v0260;
    v0260 = stack[-1];
    v0260 = qcdr(v0260);
    stack[-1] = v0260;
    goto v0070;

v0263:
    stack[-3] = stack[0];
    v0260 = stack[-2];
    v0260 = qcar(v0260);
    v0261 = qcdr(v0260);
    v0260 = stack[-1];
    v0260 = qcar(v0260);
    v0260 = qcdr(v0260);
    fn = elt(env, 2); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-4];
    v0260 = stack[-2];
    v0261 = qcdr(v0260);
    v0260 = stack[-1];
    v0260 = qcdr(v0260);
    v0260 = CC_addpf(env, v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-4];
    v0261 = stack[0];
    v0262 = v0261;
    v0262 = qcar(v0262);
    if (v0262 == nil) goto v0112;
    v0262 = stack[-2];
    v0262 = qcar(v0262);
    v0262 = qcar(v0262);
    v0260 = acons(v0262, v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-4];
    goto v0112;

v0112:
    {
        Lisp_Object v0189 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0189, v0260);
    }

v0090:
    v0261 = stack[-1];
    v0260 = stack[-2];
    fn = elt(env, 4); /* addmpf */
    v0260 = (*qfn2(fn))(qenv(fn), v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-4];
    {
        Lisp_Object v0265 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0265, v0260);
    }

v0066:
    v0261 = stack[-2];
    v0260 = stack[-1];
    fn = elt(env, 4); /* addmpf */
    v0260 = (*qfn2(fn))(qenv(fn), v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-4];
    {
        Lisp_Object v0218 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0218, v0260);
    }

v0071:
    v0261 = stack[0];
    v0260 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0261, v0260);
    }

v0032:
    v0261 = stack[0];
    v0260 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0261, v0260);
    }
/* error exit handlers */
v0188:
    popv(5);
    return nil;
}



/* Code for make!-set */

static Lisp_Object CC_makeKset(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make-set");
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
    v0010 = v0000;
/* end of prologue */
    v0007 = v0010;
    v0010 = elt(env, 1); /* set!-ordp */
    fn = elt(env, 2); /* sort */
    v0010 = (*qfn2(fn))(qenv(fn), v0007, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* makelist */
        return (*qfn1(fn))(qenv(fn), v0010);
    }
/* error exit handlers */
v0032:
    popv(1);
    return nil;
}



/* Code for csl_timbf */

static Lisp_Object CC_csl_timbf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0026, v0128, v0124;
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
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0009;
    stack[-3] = v0000;
/* end of prologue */
    v0026 = stack[-3];
    v0026 = qcdr(v0026);
    v0128 = qcar(v0026);
    v0026 = stack[-2];
    v0026 = qcdr(v0026);
    v0026 = qcar(v0026);
    v0026 = times2(v0128, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-5];
    v0124 = v0026;
    v0128 = v0124;
    v0026 = (Lisp_Object)1; /* 0 */
    if (v0128 == v0026) goto v0002;
    v0128 = v0124;
    v0026 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 4); /* inorm */
    v0026 = (*qfn2(fn))(qenv(fn), v0128, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-5];
    v0124 = v0026;
    stack[-4] = elt(env, 3); /* !:rd!: */
    v0026 = v0124;
    stack[-1] = qcar(v0026);
    v0026 = v0124;
    stack[0] = qcdr(v0026);
    v0026 = stack[-3];
    v0026 = qcdr(v0026);
    v0128 = qcdr(v0026);
    v0026 = stack[-2];
    v0026 = qcdr(v0026);
    v0026 = qcdr(v0026);
    v0026 = plus2(v0128, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-5];
    v0026 = plus2(stack[0], v0026);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    {
        Lisp_Object v0061 = stack[-4];
        Lisp_Object v0062 = stack[-1];
        popv(6);
        return list2star(v0061, v0062, v0026);
    }

v0002:
    v0026 = elt(env, 1); /* (!:rd!: 0 . 0) */
    { popv(6); return onevalue(v0026); }
/* error exit handlers */
v0125:
    popv(6);
    return nil;
}



/* Code for putpline */

static Lisp_Object CC_putpline(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0248, v0254, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for putpline");
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
    v0254 = qvalue(elt(env, 1)); /* posn!* */
    v0248 = stack[0];
    v0248 = qcar(v0248);
    v0248 = qcdr(v0248);
    stack[-1] = (Lisp_Object)(int32_t)((int32_t)v0254 + (int32_t)v0248 - TAG_FIXNUM);
    v0248 = qvalue(elt(env, 2)); /* nil */
    v0254 = Llinelength(nil, v0248);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    v0248 = qvalue(elt(env, 3)); /* spare!* */
    v0248 = (Lisp_Object)(int32_t)((int32_t)v0254 - (int32_t)v0248 + TAG_FIXNUM);
    v0248 = (Lisp_Object)greaterp2(stack[-1], v0248);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    v0248 = v0248 ? lisp_true : nil;
    env = stack[-2];
    if (v0248 == nil) goto v0137;
    v0248 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 10); /* terpri!* */
    v0248 = (*qfn1(fn))(qenv(fn), v0248);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    goto v0137;

v0137:
    v0254 = qvalue(elt(env, 1)); /* posn!* */
    v0248 = qvalue(elt(env, 5)); /* orig!* */
    v0095 = (Lisp_Object)(int32_t)((int32_t)v0254 - (int32_t)v0248 + TAG_FIXNUM);
    v0254 = qvalue(elt(env, 6)); /* ycoord!* */
    v0248 = stack[0];
    v0248 = qcar(v0248);
    v0248 = qcar(v0248);
    fn = elt(env, 11); /* update!-pline */
    v0254 = (*qfnn(fn))(qenv(fn), 3, v0095, v0254, v0248);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    v0248 = qvalue(elt(env, 7)); /* pline!* */
    v0248 = Lappend(nil, v0254, v0248);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    qvalue(elt(env, 7)) = v0248; /* pline!* */
    v0254 = qvalue(elt(env, 1)); /* posn!* */
    v0248 = stack[0];
    v0248 = qcar(v0248);
    v0248 = qcdr(v0248);
    v0248 = (Lisp_Object)(int32_t)((int32_t)v0254 + (int32_t)v0248 - TAG_FIXNUM);
    qvalue(elt(env, 1)) = v0248; /* posn!* */
    v0095 = qvalue(elt(env, 8)); /* ymin!* */
    v0248 = stack[0];
    v0248 = qcdr(v0248);
    v0254 = qcar(v0248);
    v0248 = qvalue(elt(env, 6)); /* ycoord!* */
    v0248 = (Lisp_Object)(int32_t)((int32_t)v0254 + (int32_t)v0248 - TAG_FIXNUM);
    fn = elt(env, 12); /* min */
    v0248 = (*qfn2(fn))(qenv(fn), v0095, v0248);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    qvalue(elt(env, 8)) = v0248; /* ymin!* */
    v0095 = qvalue(elt(env, 9)); /* ymax!* */
    v0248 = stack[0];
    v0248 = qcdr(v0248);
    v0254 = qcdr(v0248);
    v0248 = qvalue(elt(env, 6)); /* ycoord!* */
    v0248 = (Lisp_Object)(int32_t)((int32_t)v0254 + (int32_t)v0248 - TAG_FIXNUM);
    fn = elt(env, 13); /* max */
    v0248 = (*qfn2(fn))(qenv(fn), v0095, v0248);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    qvalue(elt(env, 9)) = v0248; /* ymax!* */
    v0248 = nil;
    { popv(3); return onevalue(v0248); }
/* error exit handlers */
v0054:
    popv(3);
    return nil;
}



/* Code for evaluate0 */

static Lisp_Object CC_evaluate0(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0032;
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
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    v0007 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* evaluate!-horner */
    v0032 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-1];
    v0007 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* evaluate1 */
        return (*qfn2(fn))(qenv(fn), v0032, v0007);
    }
/* error exit handlers */
v0011:
    popv(2);
    return nil;
}



/* Code for sroad */

static Lisp_Object MS_CDECL CC_sroad(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0106, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0034, v0035;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sroad");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sroad");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0106,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0009,v0106);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0106;
    stack[-1] = v0009;
    stack[-2] = v0000;
/* end of prologue */
    v0035 = nil;
    goto v0111;

v0111:
    v0033 = stack[0];
    if (v0033 == nil) goto v0081;
    v0034 = stack[-2];
    v0033 = stack[0];
    v0033 = qcar(v0033);
    if (equal(v0034, v0033)) goto v0038;
    v0033 = stack[0];
    v0033 = qcar(v0033);
    v0034 = v0035;
    v0033 = cons(v0033, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    v0035 = v0033;
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    stack[0] = v0033;
    goto v0111;

v0038:
    stack[-2] = v0035;
    v0034 = stack[-1];
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    v0033 = Lappend(nil, v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-3];
    {
        Lisp_Object v0065 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0065, v0033);
    }

v0081:
    v0033 = v0035;
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0033);
    }
/* error exit handlers */
v0043:
    popv(4);
    return nil;
}



/* Code for lispapply */

static Lisp_Object CC_lispapply(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0110, v0020, v0018;
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
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0020 = v0009;
    v0018 = v0000;
/* end of prologue */
    v0110 = v0018;
    if (!consp(v0110)) goto v0003;
    stack[-1] = elt(env, 1); /* rlisp */
    stack[0] = (Lisp_Object)33; /* 2 */
    v0110 = elt(env, 2); /* "Apply called with non-id arg" */
    v0020 = v0018;
    v0110 = list2(v0110, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    {
        Lisp_Object v0037 = stack[-1];
        Lisp_Object v0036 = stack[0];
        popv(3);
        fn = elt(env, 3); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0037, v0036, v0110);
    }

v0003:
    v0110 = v0018;
    {
        popv(3);
        fn = elt(env, 4); /* apply */
        return (*qfn2(fn))(qenv(fn), v0110, v0020);
    }
/* error exit handlers */
v0100:
    popv(3);
    return nil;
}



/* Code for simpplus */

static Lisp_Object CC_simpplus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0126, v0108;
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
    v0126 = stack[0];
    v0108 = Llength(nil, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    v0126 = (Lisp_Object)33; /* 2 */
    if (!(v0108 == v0126)) goto v0001;
    v0126 = stack[0];
    fn = elt(env, 2); /* ckpreci!# */
    v0126 = (*qfn1(fn))(qenv(fn), v0126);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    goto v0001;

v0001:
    v0108 = qvalue(elt(env, 1)); /* nil */
    v0126 = (Lisp_Object)17; /* 1 */
    v0126 = cons(v0108, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    stack[-1] = v0126;
    goto v0006;

v0006:
    v0126 = stack[0];
    if (v0126 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0126 = stack[0];
    fn = elt(env, 3); /* simpcar */
    v0108 = (*qfn1(fn))(qenv(fn), v0126);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    v0126 = stack[-1];
    fn = elt(env, 4); /* addsq */
    v0126 = (*qfn2(fn))(qenv(fn), v0108, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    stack[-1] = v0126;
    v0126 = stack[0];
    v0126 = qcdr(v0126);
    stack[0] = v0126;
    goto v0006;
/* error exit handlers */
v0137:
    popv(3);
    return nil;
}



/* Code for rnquotient!: */

static Lisp_Object CC_rnquotientT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045, v0073;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnquotient:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0000;
/* end of prologue */
    v0045 = stack[-1];
    v0045 = qcdr(v0045);
    v0073 = qcar(v0045);
    v0045 = stack[0];
    v0045 = qcdr(v0045);
    v0045 = qcdr(v0045);
    stack[-2] = times2(v0073, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-3];
    v0045 = stack[-1];
    v0045 = qcdr(v0045);
    v0073 = qcdr(v0045);
    v0045 = stack[0];
    v0045 = qcdr(v0045);
    v0045 = qcar(v0045);
    v0045 = times2(v0073, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-3];
    {
        Lisp_Object v0019 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v0019, v0045);
    }
/* error exit handlers */
v0018:
    popv(4);
    return nil;
}



/* Code for dp!=ecart */

static Lisp_Object CC_dpMecart(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0107, v0126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp=ecart");
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
    goto v0070;

v0070:
    v0107 = stack[0];
    if (v0107 == nil) goto v0111;
    v0107 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-2];
    fn = elt(env, 2); /* mo_ecart */
    v0126 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-2];
    v0107 = stack[-1];
    v0107 = cons(v0126, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-2];
    stack[-1] = v0107;
    v0107 = stack[0];
    v0107 = qcdr(v0107);
    stack[0] = v0107;
    goto v0070;

v0111:
    v0107 = (Lisp_Object)1; /* 0 */
    v0126 = v0107;
    goto v0104;

v0104:
    v0107 = stack[-1];
    if (v0107 == nil) { popv(3); return onevalue(v0126); }
    v0107 = stack[-1];
    v0107 = qcar(v0107);
    v0107 = Lmax2(nil, v0107, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-2];
    v0126 = v0107;
    v0107 = stack[-1];
    v0107 = qcdr(v0107);
    stack[-1] = v0107;
    goto v0104;
/* error exit handlers */
v0094:
    popv(3);
    return nil;
}



/* Code for sc_kern */

static Lisp_Object CC_sc_kern(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_kern");
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
    v0044 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* g_sc_ve */
    v0044 = sub1(v0044);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    v0044 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0044/(16/CELL)));
    v0044 = qcdr(v0044);
    v0044 = qcdr(v0044);
    v0044 = qcar(v0044);
    { popv(1); return onevalue(v0044); }
/* error exit handlers */
v0012:
    popv(1);
    return nil;
}



/* Code for setdiff */

static Lisp_Object CC_setdiff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setdiff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    v0003 = v0000;
/* end of prologue */

v0006:
    v0004 = stack[0];
    if (v0004 == nil) { popv(2); return onevalue(v0003); }
    v0004 = v0003;
    if (v0004 == nil) goto v0007;
    v0004 = stack[0];
    v0004 = qcar(v0004);
    v0003 = Ldelete(nil, v0004, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    v0004 = stack[0];
    v0004 = qcdr(v0004);
    stack[0] = v0004;
    goto v0006;

v0007:
    v0003 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0003); }
/* error exit handlers */
v0008:
    popv(2);
    return nil;
}



/* Code for qqe_number!-of!-tails!-in!-qterm */

static Lisp_Object CC_qqe_numberKofKtailsKinKqterm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0005;
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

v0046:
    v0004 = stack[0];
    if (!consp(v0004)) goto v0111;
    v0004 = stack[0];
    fn = elt(env, 2); /* qqe_op */
    v0005 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0004 = elt(env, 1); /* (ladd radd) */
    v0004 = Lmemq(nil, v0005, v0004);
    if (v0004 == nil) goto v0071;
    v0004 = stack[0];
    fn = elt(env, 3); /* qqe_arg2r */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    stack[0] = v0004;
    goto v0046;

v0071:
    v0004 = stack[0];
    fn = elt(env, 4); /* qqe_arg2l */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0004 = CC_qqe_numberKofKtailsKinKqterm(env, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    popv(2);
    return add1(v0004);

v0111:
    v0004 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v0004); }
/* error exit handlers */
v0045:
    popv(2);
    return nil;
}



/* Code for ibalp_varlt1 */

static Lisp_Object CC_ibalp_varlt1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0124, v0028, v0029;
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
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    v0029 = v0000;
/* end of prologue */
    v0028 = v0029;
    v0124 = (Lisp_Object)1; /* 0 */
    if (v0028 == v0124) goto v0010;
    v0028 = v0029;
    v0124 = (Lisp_Object)17; /* 1 */
    v0124 = (v0028 == v0124 ? lisp_true : nil);
    goto v0081;

v0081:
    if (v0124 == nil) goto v0070;
    v0124 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0124); }

v0070:
    v0124 = v0029;
    if (symbolp(v0124)) goto v0018;
    v0124 = v0029;
    fn = elt(env, 3); /* ibalp_argn */
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-2];
    stack[-1] = v0124;
    goto v0094;

v0094:
    v0124 = stack[-1];
    if (v0124 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0124 = stack[-1];
    v0124 = qcar(v0124);
    v0028 = v0124;
    v0124 = stack[0];
    v0124 = CC_ibalp_varlt1(env, v0028, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-2];
    stack[0] = v0124;
    v0124 = stack[-1];
    v0124 = qcdr(v0124);
    stack[-1] = v0124;
    goto v0094;

v0018:
    v0028 = v0029;
    v0124 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* lto_insertq */
        return (*qfn2(fn))(qenv(fn), v0028, v0124);
    }

v0010:
    v0124 = qvalue(elt(env, 1)); /* t */
    goto v0081;
/* error exit handlers */
v0090:
    popv(3);
    return nil;
}



/* Code for rl_smupdknowl */

static Lisp_Object MS_CDECL CC_rl_smupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0106, Lisp_Object v0049, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0016, v0017, v0003;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "rl_smupdknowl");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_smupdknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0049,v0106,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0009,v0106,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0038 = v0049;
    v0016 = v0106;
    v0017 = v0009;
    v0003 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_smupdknowl!* */
    v0038 = list4(v0003, v0017, v0016, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-1];
    {
        Lisp_Object v0008 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0008, v0038);
    }
/* error exit handlers */
v0005:
    popv(2);
    return nil;
}



/* Code for multiom */

static Lisp_Object CC_multiom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0003;
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
    v0017 = stack[0];
    v0003 = Llength(nil, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-1];
    v0017 = (Lisp_Object)17; /* 1 */
    if (v0003 == v0017) goto v0070;
    v0017 = stack[0];
    v0017 = qcar(v0017);
    fn = elt(env, 2); /* objectom */
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    env = stack[-1];
    v0017 = stack[0];
    v0017 = qcdr(v0017);
    v0017 = CC_multiom(env, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    goto v0006;

v0006:
    v0017 = nil;
    { popv(2); return onevalue(v0017); }

v0070:
    v0017 = stack[0];
    v0017 = qcar(v0017);
    fn = elt(env, 2); /* objectom */
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    goto v0006;
/* error exit handlers */
v0005:
    popv(2);
    return nil;
}



/* Code for letmtr3 */

static Lisp_Object MS_CDECL CC_letmtr3(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0106, Lisp_Object v0049, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0295, v0296, v0212, v0297;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "letmtr3");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for letmtr3");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0049,v0106,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0009,v0106,v0049);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0049;
    stack[-3] = v0106;
    stack[-4] = v0009;
    stack[-5] = v0000;
/* end of prologue */
    stack[-6] = nil;
    v0295 = stack[-5];
    v0295 = qcdr(v0295);
    v0295 = qcdr(v0295);
    if (v0295 == nil) goto v0017;
    v0296 = stack[-3];
    v0295 = elt(env, 1); /* sparsemat */
    if (!consp(v0296)) goto v0252;
    v0296 = qcar(v0296);
    if (!(v0296 == v0295)) goto v0252;
    v0295 = stack[-5];
    v0295 = qcdr(v0295);
    fn = elt(env, 9); /* revlis */
    v0295 = (*qfn1(fn))(qenv(fn), v0295);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-7];
    stack[-6] = v0295;
    fn = elt(env, 10); /* numlis */
    v0295 = (*qfn1(fn))(qenv(fn), v0295);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-7];
    if (v0295 == nil) goto v0200;
    v0295 = stack[-6];
    v0296 = Llength(nil, v0295);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-7];
    v0295 = (Lisp_Object)33; /* 2 */
    v0295 = Lneq(nil, v0296, v0295);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-7];
    goto v0053;

v0053:
    if (v0295 == nil) goto v0230;
    v0296 = stack[-5];
    v0295 = elt(env, 6); /* hold */
    {
        popv(8);
        fn = elt(env, 11); /* errpri2 */
        return (*qfn2(fn))(qenv(fn), v0296, v0295);
    }

v0230:
    v0295 = stack[-3];
    v0295 = qcdr(v0295);
    v0296 = qcar(v0295);
    v0295 = stack[-6];
    v0295 = qcar(v0295);
    v0295 = *(Lisp_Object *)((char *)v0296 + (CELL-TAG_VECTOR) + ((int32_t)v0295/(16/CELL)));
    v0297 = v0295;
    v0295 = v0297;
    if (v0295 == nil) goto v0299;
    v0295 = stack[-6];
    v0295 = qcdr(v0295);
    v0296 = qcar(v0295);
    v0295 = v0297;
    v0295 = Latsoc(nil, v0296, v0295);
    v0212 = v0295;
    v0295 = v0212;
    if (v0295 == nil) goto v0246;
    v0296 = stack[-4];
    v0295 = (Lisp_Object)1; /* 0 */
    if (v0296 == v0295) goto v0300;
    v0295 = qvalue(elt(env, 7)); /* nil */
    goto v0144;

v0144:
    if (v0295 == nil) goto v0301;
    v0295 = v0297;
    v0295 = qcdr(v0295);
    v0295 = qcdr(v0295);
    if (v0295 == nil) goto v0302;
    stack[0] = v0297;
    v0295 = v0212;
    v0296 = v0297;
    v0295 = Ldelete(nil, v0295, v0296);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-7];
    v0295 = qcdr(v0295);
    v0295 = Lrplacd(nil, stack[0], v0295);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    goto v0022;

v0022:
    v0295 = nil;
    { popv(8); return onevalue(v0295); }

v0302:
    v0295 = stack[-3];
    v0295 = qcdr(v0295);
    v0296 = qcar(v0295);
    v0295 = stack[-6];
    v0295 = qcar(v0295);
    v0212 = qvalue(elt(env, 7)); /* nil */
    *(Lisp_Object *)((char *)v0296 + (CELL-TAG_VECTOR) + ((int32_t)v0295/(16/CELL))) = v0212;
    goto v0022;

v0301:
    v0296 = v0212;
    v0295 = stack[-4];
    v0295 = Lrplacd(nil, v0296, v0295);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    goto v0022;

v0300:
    v0296 = stack[-2];
    v0295 = elt(env, 8); /* cx */
    v0295 = (v0296 == v0295 ? lisp_true : nil);
    v0295 = (v0295 == nil ? lisp_true : nil);
    goto v0144;

v0246:
    v0296 = stack[-4];
    v0295 = (Lisp_Object)1; /* 0 */
    if (v0296 == v0295) goto v0303;
    v0295 = qvalue(elt(env, 7)); /* nil */
    goto v0304;

v0304:
    if (!(v0295 == nil)) goto v0022;
    v0295 = stack[-6];
    v0295 = qcdr(v0295);
    v0296 = qcar(v0295);
    v0212 = v0297;
    v0295 = stack[-4];
    fn = elt(env, 12); /* sortcolelem */
    v0295 = (*qfnn(fn))(qenv(fn), 3, v0296, v0212, v0295);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    goto v0022;

v0303:
    v0296 = stack[-2];
    v0295 = elt(env, 8); /* cx */
    v0295 = (v0296 == v0295 ? lisp_true : nil);
    v0295 = (v0295 == nil ? lisp_true : nil);
    goto v0304;

v0299:
    v0296 = stack[-4];
    v0295 = (Lisp_Object)1; /* 0 */
    if (v0296 == v0295) goto v0305;
    v0295 = qvalue(elt(env, 7)); /* nil */
    goto v0262;

v0262:
    if (!(v0295 == nil)) goto v0022;
    v0295 = stack[-3];
    v0295 = qcdr(v0295);
    stack[-2] = qcar(v0295);
    v0295 = stack[-6];
    stack[-1] = qcar(v0295);
    v0295 = qvalue(elt(env, 7)); /* nil */
    stack[0] = ncons(v0295);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-7];
    v0295 = stack[-6];
    v0295 = qcdr(v0295);
    v0296 = qcar(v0295);
    v0295 = stack[-4];
    v0295 = cons(v0296, v0295);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-7];
    v0295 = list2(stack[0], v0295);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v0295;
    goto v0022;

v0305:
    v0296 = stack[-2];
    v0295 = elt(env, 8); /* cx */
    v0295 = (v0296 == v0295 ? lisp_true : nil);
    v0295 = (v0295 == nil ? lisp_true : nil);
    goto v0262;

v0200:
    v0295 = qvalue(elt(env, 5)); /* t */
    goto v0053;

v0252:
    stack[-1] = elt(env, 2); /* matrix */
    stack[0] = (Lisp_Object)161; /* 10 */
    v0212 = elt(env, 3); /* "Matrix" */
    v0295 = stack[-5];
    v0296 = qcar(v0295);
    v0295 = elt(env, 4); /* "not set" */
    v0295 = list3(v0212, v0296, v0295);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-7];
    fn = elt(env, 13); /* rerror */
    v0295 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0295);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-7];
    goto v0230;

v0017:
    v0296 = stack[-3];
    v0295 = elt(env, 1); /* sparsemat */
    if (!consp(v0296)) goto v0110;
    v0296 = qcar(v0296);
    if (!(v0296 == v0295)) goto v0110;
    v0295 = stack[-5];
    v0295 = qcdr(v0295);
    fn = elt(env, 9); /* revlis */
    v0295 = (*qfn1(fn))(qenv(fn), v0295);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-7];
    stack[-6] = v0295;
    fn = elt(env, 10); /* numlis */
    v0295 = (*qfn1(fn))(qenv(fn), v0295);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-7];
    if (v0295 == nil) goto v0065;
    v0295 = stack[-6];
    v0296 = Llength(nil, v0295);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-7];
    v0295 = (Lisp_Object)17; /* 1 */
    v0295 = Lneq(nil, v0296, v0295);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-7];
    goto v0043;

v0043:
    if (v0295 == nil) goto v0115;
    v0296 = stack[-5];
    v0295 = elt(env, 6); /* hold */
    {
        popv(8);
        fn = elt(env, 11); /* errpri2 */
        return (*qfn2(fn))(qenv(fn), v0296, v0295);
    }

v0115:
    v0295 = stack[-3];
    v0295 = qcdr(v0295);
    v0212 = qcar(v0295);
    v0295 = stack[-5];
    v0295 = qcdr(v0295);
    v0296 = qcar(v0295);
    v0295 = stack[-4];
    *(Lisp_Object *)((char *)v0212 + (CELL-TAG_VECTOR) + ((int32_t)v0296/(16/CELL))) = v0295;
    goto v0022;

v0065:
    v0295 = qvalue(elt(env, 5)); /* t */
    goto v0043;

v0110:
    stack[-1] = elt(env, 2); /* matrix */
    stack[0] = (Lisp_Object)161; /* 10 */
    v0212 = elt(env, 3); /* "Matrix" */
    v0295 = stack[-5];
    v0296 = qcar(v0295);
    v0295 = elt(env, 4); /* "not set" */
    v0295 = list3(v0212, v0296, v0295);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    env = stack[-7];
    fn = elt(env, 13); /* rerror */
    v0295 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0295);
    nil = C_nil;
    if (exception_pending()) goto v0298;
    goto v0115;
/* error exit handlers */
v0298:
    popv(8);
    return nil;
}



/* Code for evtdeg */

static Lisp_Object CC_evtdeg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0038, v0016;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evtdeg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0038 = v0000;
/* end of prologue */
    v0082 = (Lisp_Object)1; /* 0 */
    goto v0070;

v0070:
    v0016 = v0038;
    if (v0016 == nil) return onevalue(v0082);
    v0016 = v0038;
    v0016 = qcar(v0016);
    v0082 = (Lisp_Object)(int32_t)((int32_t)v0016 + (int32_t)v0082 - TAG_FIXNUM);
    v0038 = qcdr(v0038);
    goto v0070;
}



/* Code for deg!*farg */

static Lisp_Object CC_degHfarg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for deg*farg");
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
    v0036 = v0000;
/* end of prologue */
    v0037 = v0036;
    v0037 = qcdr(v0037);
    if (v0037 == nil) goto v0046;
    stack[-1] = nil;
    v0037 = v0036;
    stack[0] = v0037;
    goto v0013;

v0013:
    v0037 = stack[0];
    if (v0037 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0037 = stack[0];
    v0037 = qcar(v0037);
    fn = elt(env, 2); /* deg!*form */
    v0036 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    v0037 = stack[-1];
    fn = elt(env, 3); /* addf */
    v0037 = (*qfn2(fn))(qenv(fn), v0036, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-2];
    stack[-1] = v0037;
    v0037 = stack[0];
    v0037 = qcdr(v0037);
    stack[0] = v0037;
    goto v0013;

v0046:
    v0037 = v0036;
    v0037 = qcar(v0037);
    {
        popv(3);
        fn = elt(env, 2); /* deg!*form */
        return (*qfn1(fn))(qenv(fn), v0037);
    }
/* error exit handlers */
v0108:
    popv(3);
    return nil;
}



/* Code for rread */

static Lisp_Object MS_CDECL CC_rread(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0046;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rread");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rread");
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
    v0046 = elt(env, 1); /* " '" */
    fn = elt(env, 2); /* prin2x */
    v0046 = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* rread1 */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v0006:
    popv(1);
    return nil;
}



/* Code for simpdiff */

static Lisp_Object CC_simpdiff(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011;
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
    v0011 = stack[0];
    fn = elt(env, 1); /* ckpreci!# */
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-2];
    v0011 = stack[0];
    fn = elt(env, 2); /* simpcar */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-2];
    v0011 = stack[0];
    v0011 = qcdr(v0011);
    fn = elt(env, 3); /* simpminus */
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-2];
    {
        Lisp_Object v0013 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0013, v0011);
    }
/* error exit handlers */
v0021:
    popv(3);
    return nil;
}



/* Code for mv!-pow!-mv!-term!-!+ */

static Lisp_Object CC_mvKpowKmvKtermKL(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0001;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-pow-mv-term-+");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    v0002 = v0000;
/* end of prologue */
    v0001 = v0002;
    v0002 = stack[0];
    v0002 = qcar(v0002);
    fn = elt(env, 1); /* mv!-pow!-!+ */
    v0001 = (*qfn2(fn))(qenv(fn), v0001, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    v0002 = stack[0];
    v0002 = qcdr(v0002);
    popv(1);
    return cons(v0001, v0002);
/* error exit handlers */
v0116:
    popv(1);
    return nil;
}



setup_type const u06_setup[] =
{
    {"isarb_compl",             CC_isarb_compl, too_many_1,    wrong_no_1},
    {"downwght",                too_few_2,      CC_downwght,   wrong_no_2},
    {"vdpgetprop",              too_few_2,      CC_vdpgetprop, wrong_no_2},
    {"termordp",                too_few_2,      CC_termordp,   wrong_no_2},
    {":difference",             too_few_2,      CC_Tdifference,wrong_no_2},
    {"domain*p",                CC_domainHp,    too_many_1,    wrong_no_1},
    {"raddf",                   too_few_2,      CC_raddf,      wrong_no_2},
    {"eofcheck",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_eofcheck},
    {"red-weight",              too_few_2,      CC_redKweight, wrong_no_2},
    {"dp_sum",                  too_few_2,      CC_dp_sum,     wrong_no_2},
    {"resimp1",                 CC_resimp1,     too_many_1,    wrong_no_1},
    {"aronep:",                 CC_aronepT,     too_many_1,    wrong_no_1},
    {"omobjs",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobjs},
    {"isarb_int",               CC_isarb_int,   too_many_1,    wrong_no_1},
    {"ps:evaluate",             too_few_2,      CC_psTevaluate,wrong_no_2},
    {"noncomp2f",               CC_noncomp2f,   too_many_1,    wrong_no_1},
    {"contr1-strand",           too_few_2,      CC_contr1Kstrand,wrong_no_2},
    {"add2inputbuf",            too_few_2,      CC_add2inputbuf,wrong_no_2},
    {"ckpreci#",                CC_ckpreciC,    too_many_1,    wrong_no_1},
    {"mv-pow-minusp",           CC_mvKpowKminusp,too_many_1,   wrong_no_1},
    {"divd",                    too_few_2,      CC_divd,       wrong_no_2},
    {"pappl_pv",                too_few_2,      CC_pappl_pv,   wrong_no_2},
    {"reordsq",                 CC_reordsq,     too_many_1,    wrong_no_1},
    {"simpexpon",               CC_simpexpon,   too_many_1,    wrong_no_1},
    {"frvarsof",                too_few_2,      CC_frvarsof,   wrong_no_2},
    {"ibalp_calcmom",           CC_ibalp_calcmom,too_many_1,   wrong_no_1},
    {"ev_comp",                 too_few_2,      CC_ev_comp,    wrong_no_2},
    {"minusp:",                 CC_minuspT,     too_many_1,    wrong_no_1},
    {"difff",                   too_few_2,      CC_difff,      wrong_no_2},
    {"reval1",                  too_few_2,      CC_reval1,     wrong_no_2},
    {"groebsearchinlist",       too_few_2,      CC_groebsearchinlist,wrong_no_2},
    {"formc",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_formc},
    {"dp_ecart",                CC_dp_ecart,    too_many_1,    wrong_no_1},
    {"oprin",                   CC_oprin,       too_many_1,    wrong_no_1},
    {"rnplus:",                 too_few_2,      CC_rnplusT,    wrong_no_2},
    {"general-plus-mod-p",      too_few_2,      CC_generalKplusKmodKp,wrong_no_2},
    {"sort-factors",            CC_sortKfactors,too_many_1,    wrong_no_1},
    {"ibalp_varlat",            CC_ibalp_varlat,too_many_1,    wrong_no_1},
    {"checktag",                CC_checktag,    too_many_1,    wrong_no_1},
    {"simp*",                   CC_simpH,       too_many_1,    wrong_no_1},
    {"symtabget",               too_few_2,      CC_symtabget,  wrong_no_2},
    {"groebcpcompless?",        too_few_2,      CC_groebcpcomplessW,wrong_no_2},
    {"layout-formula",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_layoutKformula},
    {"red-ratios2",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_redKratios2},
    {"ordn",                    CC_ordn,        too_many_1,    wrong_no_1},
    {"divide:",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_divideT},
    {"reduce-mod-p",            CC_reduceKmodKp,too_many_1,    wrong_no_1},
    {"retimes1",                CC_retimes1,    too_many_1,    wrong_no_1},
    {"rl_prepat",               CC_rl_prepat,   too_many_1,    wrong_no_1},
    {"xxsort",                  CC_xxsort,      too_many_1,    wrong_no_1},
    {"lambda_mth9cq_1",         too_few_2,      CC_lambda_mth9cq_1,wrong_no_2},
    {"gcdf",                    too_few_2,      CC_gcdf,       wrong_no_2},
    {"mintype",                 CC_mintype,     too_many_1,    wrong_no_1},
    {"addpf",                   too_few_2,      CC_addpf,      wrong_no_2},
    {"make-set",                CC_makeKset,    too_many_1,    wrong_no_1},
    {"csl_timbf",               too_few_2,      CC_csl_timbf,  wrong_no_2},
    {"putpline",                CC_putpline,    too_many_1,    wrong_no_1},
    {"evaluate0",               too_few_2,      CC_evaluate0,  wrong_no_2},
    {"sroad",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_sroad},
    {"lispapply",               too_few_2,      CC_lispapply,  wrong_no_2},
    {"simpplus",                CC_simpplus,    too_many_1,    wrong_no_1},
    {"rnquotient:",             too_few_2,      CC_rnquotientT,wrong_no_2},
    {"dp=ecart",                CC_dpMecart,    too_many_1,    wrong_no_1},
    {"sc_kern",                 CC_sc_kern,     too_many_1,    wrong_no_1},
    {"setdiff",                 too_few_2,      CC_setdiff,    wrong_no_2},
    {"qqe_number-of-tails-in-qterm",CC_qqe_numberKofKtailsKinKqterm,too_many_1,wrong_no_1},
    {"ibalp_varlt1",            too_few_2,      CC_ibalp_varlt1,wrong_no_2},
    {"rl_smupdknowl",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_smupdknowl},
    {"multiom",                 CC_multiom,     too_many_1,    wrong_no_1},
    {"letmtr3",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_letmtr3},
    {"evtdeg",                  CC_evtdeg,      too_many_1,    wrong_no_1},
    {"deg*farg",                CC_degHfarg,    too_many_1,    wrong_no_1},
    {"rread",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_rread},
    {"simpdiff",                CC_simpdiff,    too_many_1,    wrong_no_1},
    {"mv-pow-mv-term-+",        too_few_2,      CC_mvKpowKmvKtermKL,wrong_no_2},
    {NULL, (one_args *)"u06", (two_args *)"7284 907515 3675894", 0}
};

/* end of generated code */
