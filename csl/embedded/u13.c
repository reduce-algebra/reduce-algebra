
/* $destdir\u13.c        Machine generated C code */

/* Signature: 00000000 28-Sep-2011 */

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
extern char *C_stack_limit;
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
extern int csl_argc;
extern char **csl_argv;
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


/* Code for guesspftype */

static Lisp_Object CC_guesspftype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0008, v0009;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for guesspftype");
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
    v0007 = stack[0];
    if (!consp(v0007)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0007 = stack[0];
    v0008 = qcar(v0007);
    v0007 = elt(env, 1); /* (wedge d partdf hodge innerprod liedf) */
    v0007 = Lmemq(nil, v0008, v0007);
    if (!(v0007 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    v0009 = Llength(nil, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0007 = stack[0];
    v0008 = qcar(v0007);
    v0007 = elt(env, 2); /* ifdegree */
    v0007 = get(v0008, v0007);
    env = stack[-1];
    v0007 = Lassoc(nil, v0009, v0007);
    if (v0007 == nil) goto v0011;
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    fn = elt(env, 3); /* xvarlistp */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    if (v0007 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else goto v0011;

v0011:
    v0007 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* mknwedge */
        return (*qfn1(fn))(qenv(fn), v0007);
    }
/* error exit handlers */
v0010:
    popv(2);
    return nil;
}



/* Code for equalreplaceby */

static Lisp_Object CC_equalreplaceby(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0015;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for equalreplaceby");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0014 = v0000;
/* end of prologue */
    v0015 = elt(env, 1); /* replaceby */
    return cons(v0015, v0014);
}



/* Code for inttovec */

static Lisp_Object CC_inttovec(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inttovec");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0018 = v0016;
    v0017 = v0000;
/* end of prologue */
    stack[0] = v0018;
    fn = elt(env, 1); /* inttovec!-solve */
    v0017 = (*qfn2(fn))(qenv(fn), v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-1];
    {
        Lisp_Object v0020 = stack[0];
        popv(2);
        fn = elt(env, 2); /* inttovec1 */
        return (*qfn2(fn))(qenv(fn), v0020, v0017);
    }
/* error exit handlers */
v0019:
    popv(2);
    return nil;
}



/* Code for assert_uninstall_all */

static Lisp_Object MS_CDECL CC_assert_uninstall_all(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_uninstall_all");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_uninstall_all");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0013 = qvalue(elt(env, 1)); /* !*assert */
    if (v0013 == nil) goto v0021;
    v0013 = qvalue(elt(env, 2)); /* assert_functionl!* */
    {
        fn = elt(env, 3); /* assert_uninstall */
        return (*qfn1(fn))(qenv(fn), v0013);
    }

v0021:
    v0013 = nil;
    return onevalue(v0013);
}



/* Code for eqdummy */

static Lisp_Object CC_eqdummy(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0026, v0027, v0028;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for eqdummy");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0026 = v0016;
    v0028 = v0000;
/* end of prologue */
    v0027 = v0028;
    if (v0027 == nil) goto v0029;
    v0027 = elt(env, 2); /* dummy */
    v0027 = get(v0028, v0027);
    env = stack[0];
    v0028 = qcar(v0027);
    v0027 = v0026;
    v0026 = elt(env, 2); /* dummy */
    v0026 = get(v0027, v0026);
    v0026 = qcar(v0026);
    v0026 = (v0028 == v0026 ? lisp_true : nil);
    { popv(1); return onevalue(v0026); }

v0029:
    v0026 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0026); }
}



/* Code for numlist_ordp */

static Lisp_Object CC_numlist_ordp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0033, v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numlist_ordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0032 = v0016;
    v0033 = v0000;
/* end of prologue */
    v0005 = v0033;
    v0033 = v0032;
    v0032 = elt(env, 1); /* lambda_ls8o1j_2 */
    {
        fn = elt(env, 2); /* cons_ordp */
        return (*qfnn(fn))(qenv(fn), 3, v0005, v0033, v0032);
    }
}



/* Code for lambda_ls8o1j_2 */

static Lisp_Object CC_lambda_ls8o1j_2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0030;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_ls8o1j_2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0015 = v0016;
    v0030 = v0000;
/* end of prologue */
        return Lleq(nil, v0030, v0015);
}



/* Code for extmult */

static Lisp_Object CC_extmult(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0056;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extmult");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0016;
    stack[-3] = v0000;
/* end of prologue */
    v0055 = stack[-3];
    if (v0055 == nil) goto v0012;
    v0055 = stack[-2];
    v0055 = (v0055 == nil ? lisp_true : nil);
    goto v0013;

v0013:
    if (v0055 == nil) goto v0019;
    v0055 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0055); }

v0019:
    v0055 = stack[-3];
    v0055 = qcar(v0055);
    v0055 = qcar(v0055);
    v0056 = qcar(v0055);
    v0055 = stack[-2];
    v0055 = qcar(v0055);
    v0055 = qcar(v0055);
    fn = elt(env, 3); /* ordexn */
    v0055 = (*qfn2(fn))(qenv(fn), v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-5];
    v0056 = v0055;
    v0055 = v0056;
    if (v0055 == nil) goto v0058;
    v0055 = v0056;
    stack[-4] = qcdr(v0055);
    v0055 = v0056;
    v0055 = qcar(v0055);
    if (v0055 == nil) goto v0059;
    v0055 = stack[-3];
    v0055 = qcar(v0055);
    v0056 = qcdr(v0055);
    v0055 = stack[-2];
    v0055 = qcar(v0055);
    v0055 = qcdr(v0055);
    fn = elt(env, 4); /* c!:subs2multf */
    v0055 = (*qfn2(fn))(qenv(fn), v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-5];
    fn = elt(env, 5); /* negf */
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-5];
    stack[-1] = v0055;
    goto v0060;

v0060:
    v0055 = stack[-3];
    v0055 = qcar(v0055);
    v0056 = ncons(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-5];
    v0055 = stack[-2];
    v0055 = qcdr(v0055);
    stack[0] = CC_extmult(env, v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-5];
    v0055 = stack[-3];
    v0056 = qcdr(v0055);
    v0055 = stack[-2];
    v0055 = CC_extmult(env, v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-5];
    fn = elt(env, 6); /* extadd */
    v0055 = (*qfn2(fn))(qenv(fn), stack[0], v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    {
        Lisp_Object v0061 = stack[-4];
        Lisp_Object v0062 = stack[-1];
        popv(6);
        return acons(v0061, v0062, v0055);
    }

v0059:
    v0055 = stack[-3];
    v0055 = qcar(v0055);
    v0056 = qcdr(v0055);
    v0055 = stack[-2];
    v0055 = qcar(v0055);
    v0055 = qcdr(v0055);
    fn = elt(env, 4); /* c!:subs2multf */
    v0055 = (*qfn2(fn))(qenv(fn), v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-5];
    stack[-1] = v0055;
    goto v0060;

v0058:
    v0055 = stack[-3];
    v0056 = qcdr(v0055);
    v0055 = stack[-2];
    stack[0] = CC_extmult(env, v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-5];
    v0055 = stack[-3];
    v0055 = qcar(v0055);
    v0056 = ncons(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-5];
    v0055 = stack[-2];
    v0055 = qcdr(v0055);
    v0055 = CC_extmult(env, v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-5];
    {
        Lisp_Object v0063 = stack[0];
        popv(6);
        fn = elt(env, 6); /* extadd */
        return (*qfn2(fn))(qenv(fn), v0063, v0055);
    }

v0012:
    v0055 = qvalue(elt(env, 1)); /* t */
    goto v0013;
/* error exit handlers */
v0057:
    popv(6);
    return nil;
}



/* Code for simp!*sq */

static Lisp_Object CC_simpHsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0064;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp*sq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0064 = v0000;
/* end of prologue */
    v0018 = v0064;
    v0018 = qcdr(v0018);
    v0018 = qcar(v0018);
    if (v0018 == nil) goto v0032;
    v0018 = qvalue(elt(env, 1)); /* !*resimp */
    if (!(v0018 == nil)) goto v0032;
    v0018 = v0064;
    v0018 = qcar(v0018);
    return onevalue(v0018);

v0032:
    v0018 = v0064;
    v0018 = qcar(v0018);
    {
        fn = elt(env, 2); /* resimp1 */
        return (*qfn1(fn))(qenv(fn), v0018);
    }
}



/* Code for mkzl */

static Lisp_Object CC_mkzl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkzl");
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
    goto v0014;

v0014:
    v0024 = stack[0];
    v0002 = (Lisp_Object)17; /* 1 */
    if (v0024 == v0002) goto v0013;
    v0024 = (Lisp_Object)1; /* 0 */
    v0002 = stack[-1];
    v0002 = cons(v0024, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-2];
    stack[-1] = v0002;
    v0002 = stack[0];
    v0002 = sub1(v0002);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-2];
    stack[0] = v0002;
    goto v0014;

v0013:
    v0002 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0002);
    }
/* error exit handlers */
v0026:
    popv(3);
    return nil;
}



/* Code for ibalp_clausep */

static Lisp_Object CC_ibalp_clausep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0068;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_clausep");
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
    v0022 = stack[0];
    fn = elt(env, 3); /* ibalp_litp */
    v0022 = (*qfn1(fn))(qenv(fn), v0022);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-1];
    if (!(v0022 == nil)) { popv(2); return onevalue(v0022); }
    v0022 = stack[0];
    if (!consp(v0022)) goto v0017;
    v0022 = stack[0];
    v0022 = qcar(v0022);
    v0068 = v0022;
    goto v0031;

v0031:
    v0022 = elt(env, 1); /* or */
    if (v0068 == v0022) goto v0012;
    v0022 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0022); }

v0012:
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    {
        popv(2);
        fn = elt(env, 4); /* ibalp_litlp */
        return (*qfn1(fn))(qenv(fn), v0022);
    }

v0017:
    v0022 = stack[0];
    v0068 = v0022;
    goto v0031;
/* error exit handlers */
v0027:
    popv(2);
    return nil;
}



/* Code for aex_mvaroccurtest */

static Lisp_Object CC_aex_mvaroccurtest(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_mvaroccurtest");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0016;
    v0030 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v0031 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-1];
    v0030 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* ratpoly_mvartest */
        return (*qfn2(fn))(qenv(fn), v0031, v0030);
    }
/* error exit handlers */
v0033:
    popv(2);
    return nil;
}



/* Code for ofsf_sacatlp */

static Lisp_Object CC_ofsf_sacatlp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0028, v0003, v0004, v0069;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sacatlp");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0028 = v0016;
    v0069 = v0000;
/* end of prologue */
    v0028 = qcar(v0028);
    v0004 = v0028;
    v0028 = v0069;
    v0028 = qcdr(v0028);
    v0003 = qcar(v0028);
    v0028 = v0004;
    v0028 = qcdr(v0028);
    v0028 = qcar(v0028);
    if (equal(v0003, v0028)) goto v0022;
    v0028 = v0069;
    v0028 = qcdr(v0028);
    v0028 = qcar(v0028);
    v0003 = v0004;
    v0003 = qcdr(v0003);
    v0003 = qcar(v0003);
    fn = elt(env, 2); /* ordp */
    v0028 = (*qfn2(fn))(qenv(fn), v0028, v0003);
    errexit();
    goto v0054;

v0054:
    v0028 = (v0028 == nil ? lisp_true : nil);
    return onevalue(v0028);

v0022:
    v0028 = qvalue(elt(env, 1)); /* nil */
    goto v0054;
}



/* Code for cr!:prep */

static Lisp_Object CC_crTprep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cr:prep");
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
    v0024 = elt(env, 1); /* !:rd!: */
    v0002 = stack[0];
    v0002 = qcdr(v0002);
    v0002 = qcar(v0002);
    v0002 = cons(v0024, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-2];
    fn = elt(env, 2); /* rd!:prep */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-2];
    v0024 = elt(env, 1); /* !:rd!: */
    v0002 = stack[0];
    v0002 = qcdr(v0002);
    v0002 = qcdr(v0002);
    v0002 = cons(v0024, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-2];
    fn = elt(env, 2); /* rd!:prep */
    v0002 = (*qfn1(fn))(qenv(fn), v0002);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-2];
    v0002 = cons(stack[-1], v0002);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* crprep1 */
        return (*qfn1(fn))(qenv(fn), v0002);
    }
/* error exit handlers */
v0026:
    popv(3);
    return nil;
}



/* Code for initwght */

static Lisp_Object CC_initwght(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0096, v0097, v0098;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for initwght");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0000;
/* end of prologue */
    v0096 = (Lisp_Object)1; /* 0 */
    stack[-5] = v0096;
    stack[0] = v0096;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0097 = qvalue(elt(env, 2)); /* maxvar */
    v0096 = stack[-3];
    v0096 = plus2(v0097, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    v0097 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0096/(16/CELL)));
    v0096 = (Lisp_Object)65; /* 4 */
    v0096 = *(Lisp_Object *)((char *)v0097 + (CELL-TAG_VECTOR) + ((int32_t)v0096/(16/CELL)));
    stack[-4] = v0096;
    goto v0014;

v0014:
    v0096 = stack[-4];
    if (v0096 == nil) goto v0034;
    v0096 = stack[-4];
    v0096 = qcar(v0096);
    stack[-2] = v0096;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0097 = qvalue(elt(env, 2)); /* maxvar */
    v0096 = stack[-2];
    v0096 = qcar(v0096);
    v0096 = plus2(v0097, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    v0097 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0096/(16/CELL)));
    v0096 = (Lisp_Object)1; /* 0 */
    v0096 = *(Lisp_Object *)((char *)v0097 + (CELL-TAG_VECTOR) + ((int32_t)v0096/(16/CELL)));
    if (v0096 == nil) goto v0100;
    v0096 = stack[-2];
    v0096 = qcdr(v0096);
    v0096 = qcar(v0096);
    fn = elt(env, 5); /* dm!-abs */
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    v0098 = v0096;
    v0096 = v0098;
    if (!consp(v0096)) goto v0101;
    v0096 = v0098;
    v0097 = qcar(v0096);
    v0096 = elt(env, 4); /* onep */
    v0096 = get(v0097, v0096);
    env = stack[-6];
    v0097 = v0098;
    v0096 = Lapply1(nil, v0096, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    goto v0102;

v0102:
    if (!(v0096 == nil)) goto v0103;
    v0096 = stack[-5];
    v0096 = add1(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    stack[-5] = v0096;
    goto v0103;

v0103:
    v0096 = stack[0];
    v0096 = add1(v0096);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    stack[0] = v0096;
    goto v0100;

v0100:
    v0096 = stack[-4];
    v0096 = qcdr(v0096);
    stack[-4] = v0096;
    goto v0014;

v0101:
    v0096 = v0098;
    v0096 = Lonep(nil, v0096);
    env = stack[-6];
    goto v0102;

v0034:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0097 = qvalue(elt(env, 2)); /* maxvar */
    v0096 = stack[-3];
    v0096 = plus2(v0097, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    stack[-4] = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0096/(16/CELL)));
    stack[-3] = (Lisp_Object)17; /* 1 */
    stack[-2] = stack[0];
    stack[-1] = stack[-5];
    v0097 = (Lisp_Object)49; /* 3 */
    v0096 = stack[-5];
    v0096 = times2(v0097, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    v0096 = plus2(stack[0], v0096);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    env = stack[-6];
    v0096 = acons(stack[-2], stack[-1], v0096);
    nil = C_nil;
    if (exception_pending()) goto v0099;
    *(Lisp_Object *)((char *)stack[-4] + (CELL-TAG_VECTOR) + ((int32_t)stack[-3]/(16/CELL))) = v0096;
    v0096 = nil;
    { popv(7); return onevalue(v0096); }
/* error exit handlers */
v0099:
    popv(7);
    return nil;
}



/* Code for bcplus!? */

static Lisp_Object CC_bcplusW(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0020;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcplus?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0019 = v0000;
/* end of prologue */
    v0019 = qcar(v0019);
    v0020 = v0019;
    v0019 = v0020;
    if (is_number(v0019)) goto v0005;
    v0019 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0019);

v0005:
    v0019 = (Lisp_Object)1; /* 0 */
        return Lgreaterp(nil, v0020, v0019);
}



/* Code for vevmaptozero1 */

static Lisp_Object CC_vevmaptozero1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0104;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevmaptozero1");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0023 = v0016;
    stack[0] = v0000;
/* end of prologue */

v0029:
    v0104 = stack[0];
    if (v0104 == nil) { popv(2); return onevalue(v0023); }
    v0104 = stack[0];
    v0104 = qcdr(v0104);
    stack[0] = v0104;
    v0104 = (Lisp_Object)1; /* 0 */
    v0023 = cons(v0104, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-1];
    goto v0029;
/* error exit handlers */
v0065:
    popv(2);
    return nil;
}



/* Code for physopaeval */

static Lisp_Object CC_physopaeval(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071, v0112, v0113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopaeval");
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
    v0071 = stack[0];
    fn = elt(env, 7); /* physopp */
    v0071 = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-1];
    if (v0071 == nil) goto v0013;
    v0112 = stack[0];
    v0071 = elt(env, 1); /* rvalue */
    v0071 = get(v0112, v0071);
    env = stack[-1];
    v0113 = v0071;
    if (v0071 == nil) goto v0032;
    v0071 = v0113;
    v0112 = qcar(v0071);
    v0071 = elt(env, 2); /* !*sq */
    if (!(v0112 == v0071)) { popv(2); return onevalue(v0113); }
    v0071 = qvalue(elt(env, 3)); /* !*nosq */
    if (v0071 == nil) goto v0028;
    v0071 = v0113;
    v0071 = qcdr(v0071);
    v0071 = qcar(v0071);
    {
        popv(2);
        fn = elt(env, 8); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v0071);
    }

v0028:
    v0071 = v0113;
    v0071 = qcdr(v0071);
    v0071 = qcar(v0071);
    {
        popv(2);
        fn = elt(env, 9); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v0071);
    }

v0032:
    v0071 = stack[0];
    if (!consp(v0071)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0071 = stack[0];
    v0112 = qcar(v0071);
    v0071 = elt(env, 4); /* psimpfn */
    v0071 = get(v0112, v0071);
    env = stack[-1];
    v0113 = v0071;
    if (v0071 == nil) goto v0101;
    v0112 = v0113;
    v0071 = stack[0];
        popv(2);
        return Lapply1(nil, v0112, v0071);

v0101:
    v0071 = stack[0];
    v0112 = qcar(v0071);
    v0071 = elt(env, 5); /* opmtch */
    v0071 = get(v0112, v0071);
    env = stack[-1];
    if (v0071 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0071 = stack[0];
    fn = elt(env, 10); /* opmtch!* */
    v0071 = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    v0113 = v0071;
    if (v0071 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v0113); }

v0013:
    v0071 = stack[0];
    if (!consp(v0071)) goto v0114;
    v0071 = stack[0];
    v0112 = qcar(v0071);
    v0071 = elt(env, 2); /* !*sq */
    v0071 = (v0112 == v0071 ? lisp_true : nil);
    goto v0048;

v0048:
    if (v0071 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0071 = qvalue(elt(env, 3)); /* !*nosq */
    if (v0071 == nil) goto v0034;
    v0071 = stack[0];
    v0071 = qcdr(v0071);
    v0071 = qcar(v0071);
    {
        popv(2);
        fn = elt(env, 8); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v0071);
    }

v0034:
    v0071 = stack[0];
    v0071 = qcdr(v0071);
    v0071 = qcar(v0071);
    {
        popv(2);
        fn = elt(env, 9); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v0071);
    }

v0114:
    v0071 = qvalue(elt(env, 6)); /* nil */
    goto v0048;
/* error exit handlers */
v0055:
    popv(2);
    return nil;
}



/* Code for zero!-roads */

static Lisp_Object CC_zeroKroads(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zero-roads");
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

v0115:
    v0068 = stack[0];
    if (v0068 == nil) goto v0021;
    v0068 = stack[0];
    v0068 = qcar(v0068);
    fn = elt(env, 2); /* z!-roads */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    v0026 = v0068;
    v0068 = v0026;
    if (v0068 == nil) goto v0053;
    stack[-1] = v0026;
    v0068 = stack[0];
    v0068 = qcdr(v0068);
    v0068 = CC_zeroKroads(env, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    {
        Lisp_Object v0004 = stack[-1];
        popv(3);
        return cons(v0004, v0068);
    }

v0053:
    v0068 = stack[0];
    v0068 = qcdr(v0068);
    stack[0] = v0068;
    goto v0115;

v0021:
    v0068 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0068); }
/* error exit handlers */
v0003:
    popv(3);
    return nil;
}



/* Code for assert_install */

static Lisp_Object CC_assert_install(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0067;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_install");
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
    v0067 = v0000;
/* end of prologue */
    v0104 = qvalue(elt(env, 1)); /* !*assert */
    if (v0104 == nil) goto v0029;
    v0104 = v0067;
    stack[0] = v0104;
    goto v0014;

v0014:
    v0104 = stack[0];
    if (v0104 == nil) goto v0032;
    v0104 = stack[0];
    v0104 = qcar(v0104);
    fn = elt(env, 3); /* assert_install1 */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-1];
    v0104 = stack[0];
    v0104 = qcdr(v0104);
    stack[0] = v0104;
    goto v0014;

v0032:
    v0104 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0104); }

v0029:
    v0104 = nil;
    { popv(2); return onevalue(v0104); }
/* error exit handlers */
v0001:
    popv(2);
    return nil;
}



/* Code for mo!=revlexcomp */

static Lisp_Object CC_moMrevlexcomp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=revlexcomp");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0016;
    stack[-1] = v0000;
/* end of prologue */
    v0116 = stack[-1];
    stack[-2] = Llength(nil, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    v0116 = stack[0];
    v0116 = Llength(nil, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v0116))) goto v0029;
    v0116 = stack[0];
    stack[-2] = Llength(nil, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    v0116 = stack[-1];
    v0116 = Llength(nil, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v0116))) goto v0006;
    v0116 = stack[-1];
    stack[-1] = Lreverse(nil, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    v0116 = stack[0];
    v0116 = Lreverse(nil, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-3];
    fn = elt(env, 1); /* mo!=degcomp */
    v0116 = (*qfn2(fn))(qenv(fn), stack[-1], v0116);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    popv(4);
    return negate(v0116);

v0006:
    v0116 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v0116); }

v0029:
    v0116 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v0116); }
/* error exit handlers */
v0011:
    popv(4);
    return nil;
}



/* Code for dv_cambhead */

static Lisp_Object CC_dv_cambhead(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0100, v0117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_cambhead");
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

v0115:
    v0100 = stack[0];
    fn = elt(env, 4); /* listp */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    if (v0100 == nil) goto v0029;
    v0100 = stack[0];
    stack[-1] = qcar(v0100);
    v0117 = elt(env, 1); /* expt */
    v0100 = elt(env, 2); /* minus */
    v0100 = list2(v0117, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    v0100 = Lmember(nil, stack[-1], v0100);
    if (v0100 == nil) goto v0015;
    v0100 = stack[0];
    v0100 = qcdr(v0100);
    v0100 = qcar(v0100);
    stack[0] = v0100;
    goto v0115;

v0015:
    v0100 = stack[0];
    fn = elt(env, 4); /* listp */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    if (v0100 == nil) goto v0029;
    v0100 = stack[0];
    v0100 = qcar(v0100);
    { popv(3); return onevalue(v0100); }

v0029:
    v0100 = nil;
    { popv(3); return onevalue(v0100); }
/* error exit handlers */
v0118:
    popv(3);
    return nil;
}



/* Code for expt!-mod!-p */

static Lisp_Object CC_exptKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0049, v0102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expt-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0102 = v0016;
    stack[0] = v0000;
/* end of prologue */
    v0049 = v0102;
    v0087 = (Lisp_Object)1; /* 0 */
    if (v0049 == v0087) goto v0029;
    v0049 = v0102;
    v0087 = (Lisp_Object)17; /* 1 */
    if (v0049 == v0087) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0049 = v0102;
    v0087 = (Lisp_Object)33; /* 2 */
    v0087 = Ldivide(nil, v0049, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-2];
    stack[-1] = v0087;
    v0049 = stack[0];
    v0087 = stack[-1];
    v0087 = qcar(v0087);
    v0087 = CC_exptKmodKp(env, v0049, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-2];
    v0102 = v0087;
    v0087 = v0102;
    v0049 = v0102;
    fn = elt(env, 1); /* times!-mod!-p */
    v0087 = (*qfn2(fn))(qenv(fn), v0087, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-2];
    v0102 = v0087;
    v0087 = stack[-1];
    v0049 = qcdr(v0087);
    v0087 = (Lisp_Object)1; /* 0 */
    if (v0049 == v0087) { popv(3); return onevalue(v0102); }
    v0049 = v0102;
    v0087 = stack[0];
    fn = elt(env, 1); /* times!-mod!-p */
    v0087 = (*qfn2(fn))(qenv(fn), v0049, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    v0102 = v0087;
    { popv(3); return onevalue(v0102); }

v0029:
    v0087 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0087); }
/* error exit handlers */
v0042:
    popv(3);
    return nil;
}



/* Code for get_group_in */

static Lisp_Object CC_get_group_in(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0121;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_group_in");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0121 = v0000;
/* end of prologue */
    v0121 = qcar(v0121);
    return onevalue(v0121);
}



/* Code for qqe_ofsf_simplat1 */

static Lisp_Object CC_qqe_ofsf_simplat1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0069, v0090;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_ofsf_simplat1");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0016;
    stack[-1] = v0000;
/* end of prologue */
    v0090 = stack[-1];
    v0069 = stack[0];
    fn = elt(env, 2); /* qqe_simplat1 */
    v0069 = (*qfn2(fn))(qenv(fn), v0090, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-3];
    stack[-2] = v0069;
    v0090 = stack[-2];
    v0069 = elt(env, 1); /* (true false) */
    v0069 = Lmemq(nil, v0090, v0069);
    if (!(v0069 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0069 = stack[-1];
    fn = elt(env, 3); /* qqe_op */
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-3];
    fn = elt(env, 4); /* qqe_rqopp */
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-3];
    if (!(v0069 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0090 = stack[-2];
    v0069 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* ofsf_simplat1 */
        return (*qfn2(fn))(qenv(fn), v0090, v0069);
    }
/* error exit handlers */
v0120:
    popv(4);
    return nil;
}



/* Code for rl_negateat */

static Lisp_Object CC_rl_negateat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_negateat");
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
    v0015 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_negateat!* */
    v0015 = ncons(v0015);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-1];
    {
        Lisp_Object v0032 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0032, v0015);
    }
/* error exit handlers */
v0031:
    popv(2);
    return nil;
}



/* Code for ibalp_redclause */

static Lisp_Object CC_ibalp_redclause(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0069;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_redclause");
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
    stack[0] = nil;
    v0004 = stack[-1];
    v0004 = qcar(v0004);
    stack[-2] = v0004;
    goto v0014;

v0014:
    v0004 = stack[-2];
    if (v0004 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0004 = stack[0];
    if (!(v0004 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0004 = stack[-2];
    v0069 = qcar(v0004);
    v0004 = stack[-1];
    v0004 = qcdr(v0004);
    v0004 = qcar(v0004);
    fn = elt(env, 3); /* ibalp_vmember */
    v0004 = (*qfn2(fn))(qenv(fn), v0069, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    if (v0004 == nil) goto v0019;
    v0004 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0004;
    goto v0019;

v0019:
    v0004 = stack[-2];
    v0004 = qcdr(v0004);
    stack[-2] = v0004;
    goto v0014;
/* error exit handlers */
v0117:
    popv(4);
    return nil;
}



/* Code for aex_simplenullp */

static Lisp_Object CC_aex_simplenullp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_simplenullp");
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
    v0029 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* ratpoly_nullp */
        return (*qfn1(fn))(qenv(fn), v0029);
    }
/* error exit handlers */
v0121:
    popv(1);
    return nil;
}



/* Code for variablesir */

static Lisp_Object MS_CDECL CC_variablesir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0100, v0117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "variablesir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for variablesir");
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
    v0117 = qvalue(elt(env, 1)); /* char */
    v0100 = elt(env, 2); /* (!/ o m b v a r) */
    if (equal(v0117, v0100)) goto v0121;
    fn = elt(env, 4); /* omvir */
    v0100 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-1];
    stack[0] = v0100;
    fn = elt(env, 5); /* lex */
    v0100 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-1];
    v0100 = CC_variablesir(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    v0117 = stack[0];
    if (v0117 == nil) goto v0104;
    v0117 = stack[0];
    popv(2);
    return cons(v0117, v0100);

v0104:
    v0117 = stack[0];
        popv(2);
        return Lappend(nil, v0117, v0100);

v0121:
    v0100 = nil;
    { popv(2); return onevalue(v0100); }
/* error exit handlers */
v0011:
    popv(2);
    return nil;
}



/* Code for lid */

static Lisp_Object CC_lid(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0031;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lid");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0030 = v0000;
/* end of prologue */
    v0031 = v0030;
    if (!consp(v0031)) return onevalue(v0030);
    v0030 = qcar(v0030);
    return onevalue(v0030);
}



/* Code for invp */

static Lisp_Object CC_invp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0052, v0123;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for invp");
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
    v0123 = v0000;
/* end of prologue */
    v0052 = v0123;
    v0091 = elt(env, 1); /* unit */
    if (v0052 == v0091) return onevalue(v0123);
    v0091 = v0123;
    if (!consp(v0091)) goto v0017;
    v0091 = v0123;
    v0052 = qcar(v0091);
    v0091 = elt(env, 3); /* (comm anticomm) */
    v0091 = Lmember(nil, v0052, v0091);
    if (v0091 == nil) goto v0092;
    v0052 = elt(env, 4); /* quotient */
    v0091 = (Lisp_Object)17; /* 1 */
    return list3(v0052, v0091, v0123);

v0092:
    v0091 = v0123;
    v0052 = qcar(v0091);
    v0091 = elt(env, 2); /* inverse */
    v0091 = get(v0052, v0091);
    v0052 = v0123;
    v0052 = qcdr(v0052);
    return cons(v0091, v0052);

v0017:
    v0091 = v0123;
    v0052 = elt(env, 2); /* inverse */
    return get(v0091, v0052);
}



/* Code for formcond1 */

static Lisp_Object MS_CDECL CC_formcond1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0016,
                         Lisp_Object v0066, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0125, v0126, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formcond1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formcond1");
#endif
    if (stack >= stacklimit)
    {
        push3(v0066,v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0016,v0066);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0066;
    stack[-2] = v0016;
    stack[-3] = v0000;
/* end of prologue */
    stack[-4] = nil;
    goto v0054;

v0054:
    v0125 = stack[-3];
    if (v0125 == nil) goto v0014;
    v0125 = stack[-3];
    v0125 = qcar(v0125);
    v0127 = qcar(v0125);
    v0126 = stack[-2];
    v0125 = stack[-1];
    fn = elt(env, 1); /* formbool */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0127, v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-5];
    v0125 = stack[-3];
    v0125 = qcar(v0125);
    v0125 = qcdr(v0125);
    v0127 = qcar(v0125);
    v0126 = stack[-2];
    v0125 = stack[-1];
    fn = elt(env, 2); /* formc */
    v0125 = (*qfnn(fn))(qenv(fn), 3, v0127, v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-5];
    v0126 = list2(stack[0], v0125);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-5];
    v0125 = stack[-4];
    v0125 = cons(v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-5];
    stack[-4] = v0125;
    v0125 = stack[-3];
    v0125 = qcdr(v0125);
    stack[-3] = v0125;
    goto v0054;

v0014:
    v0125 = stack[-4];
    {
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0125);
    }
/* error exit handlers */
v0052:
    popv(6);
    return nil;
}



/* Code for mkarray1 */

static Lisp_Object CC_mkarray1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0110, v0128;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkarray1");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0016;
    stack[-5] = v0000;
/* end of prologue */
    v0110 = stack[-5];
    if (v0110 == nil) goto v0030;
    v0110 = stack[-5];
    v0110 = qcar(v0110);
    v0110 = sub1(v0110);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    stack[-6] = v0110;
    v0110 = stack[-6];
    v0110 = Lmkvect(nil, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    stack[-3] = v0110;
    v0110 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0110;
    goto v0011;

v0011:
    v0128 = stack[-6];
    v0110 = stack[-2];
    v0110 = difference2(v0128, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    v0110 = Lminusp(nil, v0110);
    env = stack[-7];
    if (!(v0110 == nil)) { Lisp_Object res = stack[-3]; popv(8); return onevalue(res); }
    stack[-1] = stack[-3];
    stack[0] = stack[-2];
    v0110 = stack[-5];
    v0128 = qcdr(v0110);
    v0110 = stack[-4];
    v0110 = CC_mkarray1(env, v0128, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0110;
    v0110 = stack[-2];
    v0110 = add1(v0110);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-7];
    stack[-2] = v0110;
    goto v0011;

v0030:
    v0128 = stack[-4];
    v0110 = elt(env, 1); /* symbolic */
    if (v0128 == v0110) goto v0014;
    v0110 = (Lisp_Object)1; /* 0 */
    { popv(8); return onevalue(v0110); }

v0014:
    v0110 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v0110); }
/* error exit handlers */
v0129:
    popv(8);
    return nil;
}



/* Code for !:divide */

static Lisp_Object CC_Tdivide(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0125, v0126, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :divide");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0126 = v0016;
    v0127 = v0000;
/* end of prologue */
    v0125 = v0127;
    if (v0125 == nil) goto v0029;
    v0125 = v0126;
    if (v0125 == nil) goto v0014;
    v0125 = v0127;
    if (!consp(v0125)) goto v0070;
    v0125 = qvalue(elt(env, 1)); /* nil */
    goto v0053;

v0053:
    if (v0125 == nil) goto v0124;
    v0125 = v0127;
    {
        popv(1);
        fn = elt(env, 6); /* dividef */
        return (*qfn2(fn))(qenv(fn), v0125, v0126);
    }

v0124:
    v0125 = elt(env, 5); /* divide */
    {
        popv(1);
        fn = elt(env, 7); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0127, v0126, v0125);
    }

v0070:
    v0125 = v0126;
    v0125 = (consp(v0125) ? nil : lisp_true);
    goto v0053;

v0014:
    v0125 = elt(env, 2); /* "zero divisor" */
    v0126 = v0125;
    v0125 = v0126;
    qvalue(elt(env, 3)) = v0125; /* errmsg!* */
    v0125 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v0125 == nil)) goto v0018;
    v0125 = v0126;
    fn = elt(env, 8); /* lprie */
    v0125 = (*qfn1(fn))(qenv(fn), v0125);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[0];
    goto v0018;

v0018:
    v0125 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    v0125 = nil;
    { popv(1); return onevalue(v0125); }

v0029:
    v0125 = qvalue(elt(env, 1)); /* nil */
    popv(1);
    return ncons(v0125);
/* error exit handlers */
v0122:
    popv(1);
    return nil;
}



/* Code for gperm0 */

static Lisp_Object CC_gperm0(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0025;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm0");
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
    v0025 = v0000;
/* end of prologue */
    v0020 = v0025;
    if (v0020 == nil) goto v0021;
    v0020 = v0025;
    stack[0] = qcdr(v0020);
    v0020 = v0025;
    v0020 = qcar(v0020);
    v0020 = ncons(v0020);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-1];
    v0020 = ncons(v0020);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-1];
    {
        Lisp_Object v0067 = stack[0];
        popv(2);
        fn = elt(env, 2); /* gperm3 */
        return (*qfn2(fn))(qenv(fn), v0067, v0020);
    }

v0021:
    v0020 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0020); }
/* error exit handlers */
v0104:
    popv(2);
    return nil;
}



/* Code for freeofl */

static Lisp_Object CC_freeofl(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0119, v0092;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeofl");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0016;
    stack[-1] = v0000;
/* end of prologue */

v0115:
    v0010 = stack[0];
    if (v0010 == nil) goto v0029;
    v0010 = stack[0];
    v0119 = qcar(v0010);
    v0010 = stack[-1];
    fn = elt(env, 4); /* smember */
    v0010 = (*qfn2(fn))(qenv(fn), v0119, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    if (!(v0010 == nil)) goto v0008;
    v0010 = stack[0];
    v0092 = qcar(v0010);
    v0119 = stack[-1];
    v0010 = qvalue(elt(env, 2)); /* depl!* */
    v0010 = Lassoc(nil, v0119, v0010);
    v0010 = Lmember(nil, v0092, v0010);
    if (!(v0010 == nil)) goto v0008;
    v0119 = stack[-1];
    v0010 = stack[0];
    v0010 = qcdr(v0010);
    stack[-1] = v0119;
    stack[0] = v0010;
    goto v0115;

v0008:
    v0010 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v0010); }

v0029:
    v0010 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0010); }
/* error exit handlers */
v0125:
    popv(3);
    return nil;
}



/* Code for xread1 */

static Lisp_Object CC_xread1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0361, v0362, v0363;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xread1");
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
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0000;
/* end of prologue */
    stack[-8] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v0361 = qvalue(elt(env, 1)); /* commentlist!* */
    if (v0361 == nil) goto v0030;
    v0361 = qvalue(elt(env, 1)); /* commentlist!* */
    stack[-1] = v0361;
    v0361 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 1)) = v0361; /* commentlist!* */
    goto v0030;

v0030:
    v0361 = qvalue(elt(env, 3)); /* cursym!* */
    stack[-3] = v0361;
    goto v0031;

v0031:
    v0361 = stack[-3];
    if (!(symbolp(v0361))) goto v0032;
    v0362 = stack[-3];
    v0361 = elt(env, 4); /* !*lpar!* */
    if (v0362 == v0361) goto v0006;
    v0362 = stack[-3];
    v0361 = elt(env, 5); /* !*rpar!* */
    if (v0362 == v0361) goto v0018;
    v0362 = stack[-3];
    v0361 = elt(env, 6); /* infix */
    v0361 = get(v0362, v0361);
    env = stack[-9];
    stack[-4] = v0361;
    if (!(v0361 == nil)) goto v0064;
    v0362 = stack[-3];
    v0361 = elt(env, 7); /* delim */
    v0361 = Lflagp(nil, v0362, v0361);
    env = stack[-9];
    if (v0361 == nil) goto v0060;
    v0362 = qvalue(elt(env, 3)); /* cursym!* */
    v0361 = elt(env, 30); /* !*semicol!* */
    if (v0362 == v0361) goto v0364;
    fn = elt(env, 57); /* eolcheck */
    v0361 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    goto v0364;

v0364:
    v0362 = stack[-3];
    v0361 = elt(env, 50); /* !*colon!* */
    if (v0362 == v0361) goto v0366;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0367;

v0367:
    if (!(v0361 == nil)) goto v0368;
    v0362 = stack[-3];
    v0361 = elt(env, 53); /* nodel */
    v0361 = Lflagp(nil, v0362, v0361);
    env = stack[-9];
    if (v0361 == nil) goto v0369;
    v0361 = stack[-7];
    if (v0361 == nil) goto v0370;
    v0362 = stack[-7];
    v0361 = elt(env, 28); /* group */
    if (v0362 == v0361) goto v0371;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0372;

v0372:
    if (!(v0361 == nil)) goto v0368;
    v0361 = stack[-7];
    if (!(symbolp(v0361))) goto v0024;
    v0362 = stack[-7];
    v0361 = elt(env, 24); /* paren */
    if (v0362 == v0361) goto v0373;
    v0362 = stack[-7];
    v0361 = elt(env, 23); /* struct */
    v0361 = Lflagp(nil, v0362, v0361);
    env = stack[-9];
    goto v0374;

v0374:
    if (v0361 == nil) goto v0024;
    v0362 = elt(env, 55); /* "Too few right parentheses" */
    v0361 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0361 = (*qfn2(fn))(qenv(fn), v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    goto v0024;

v0024:
    v0361 = stack[-4];
    if (v0361 == nil) goto v0375;
    v0362 = elt(env, 27); /* "Improper delimiter" */
    v0361 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0361 = (*qfn2(fn))(qenv(fn), v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    goto v0376;

v0376:
    v0361 = (Lisp_Object)1; /* 0 */
    stack[-4] = v0361;
    goto v0023;

v0023:
    v0361 = stack[-6];
    if (!(v0361 == nil)) goto v0377;
    v0362 = elt(env, 27); /* "Improper delimiter" */
    v0361 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0361 = (*qfn2(fn))(qenv(fn), v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    goto v0377;

v0377:
    v0361 = stack[-6];
    v0361 = qcar(v0361);
    stack[0] = v0361;
    goto v0104;

v0104:
    v0361 = stack[-6];
    v0361 = qcdr(v0361);
    stack[-6] = v0361;
    v0361 = stack[-6];
    if (v0361 == nil) goto v0378;
    v0361 = stack[-6];
    v0361 = qcar(v0361);
    if (!consp(v0361)) goto v0379;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0380;

v0380:
    if (v0361 == nil) goto v0381;
    v0362 = elt(env, 34); /* "Missing operator" */
    v0361 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0361 = (*qfn2(fn))(qenv(fn), v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    goto v0381;

v0381:
    v0361 = stack[-6];
    v0362 = qcar(v0361);
    v0361 = stack[0];
    v0361 = list2(v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[0] = v0361;
    goto v0104;

v0379:
    v0361 = stack[-6];
    v0361 = qcar(v0361);
    v0361 = Lsymbolp(nil, v0361);
    env = stack[-9];
    v0361 = (v0361 == nil ? lisp_true : nil);
    goto v0380;

v0378:
    v0362 = stack[0];
    v0361 = stack[-8];
    v0361 = cons(v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-8] = v0361;
    goto v0065;

v0065:
    v0361 = stack[-5];
    if (v0361 == nil) goto v0382;
    v0362 = stack[-4];
    v0361 = stack[-5];
    v0361 = qcar(v0361);
    v0361 = qcar(v0361);
    v0361 = (Lisp_Object)lessp2(v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    v0361 = v0361 ? lisp_true : nil;
    env = stack[-9];
    if (!(v0361 == nil)) goto v0383;
    v0362 = stack[-4];
    v0361 = stack[-5];
    v0361 = qcar(v0361);
    v0361 = qcar(v0361);
    if (equal(v0362, v0361)) goto v0384;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0385;

v0385:
    if (!(v0361 == nil)) goto v0383;

v0386:
    v0363 = stack[-4];
    v0362 = stack[-3];
    v0361 = stack[-5];
    v0361 = acons(v0363, v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-5] = v0361;
    v0362 = stack[-3];
    v0361 = elt(env, 25); /* !*comma!* */
    if (!(v0362 == v0361)) goto v0025;
    v0361 = stack[-5];
    v0361 = qcdr(v0361);
    if (!(v0361 == nil)) goto v0005;
    v0361 = stack[-7];
    if (v0361 == nil) goto v0387;
    v0362 = stack[-7];
    v0361 = elt(env, 38); /* (lambda paren) */
    v0361 = Lmemq(nil, v0362, v0361);
    if (!(v0361 == nil)) goto v0388;
    v0362 = stack[-7];
    v0361 = elt(env, 23); /* struct */
    v0361 = Lflagp(nil, v0362, v0361);
    env = stack[-9];
    goto v0388;

v0388:
    if (!(v0361 == nil)) goto v0005;

v0022:
    v0361 = stack[-8];
    v0361 = qcdr(v0361);
    if (v0361 == nil) goto v0389;
    v0361 = elt(env, 56); /* "Please send hearn@rand.org your program!!" 
*/
    v0361 = Lprint(nil, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    v0362 = elt(env, 27); /* "Improper delimiter" */
    v0361 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0361 = (*qfn2(fn))(qenv(fn), v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    v0361 = nil;
    { popv(10); return onevalue(v0361); }

v0389:
    v0361 = stack[-8];
    v0362 = qcar(v0361);
    v0361 = stack[-1];
    {
        popv(10);
        fn = elt(env, 59); /* xcomment */
        return (*qfn2(fn))(qenv(fn), v0362, v0361);
    }

v0005:
    fn = elt(env, 60); /* scan */
    v0361 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-3] = v0361;
    goto v0031;

v0387:
    v0361 = qvalue(elt(env, 13)); /* t */
    goto v0388;

v0025:
    v0361 = stack[-2];
    stack[-3] = v0361;
    goto v0031;

v0383:
    v0361 = stack[-8];
    v0361 = qcdr(v0361);
    v0362 = qcar(v0361);
    v0361 = elt(env, 39); /* not */
    if (!consp(v0362)) goto v0390;
    v0362 = qcar(v0362);
    if (!(v0362 == v0361)) goto v0390;
    v0361 = stack[-5];
    v0361 = qcar(v0361);
    v0363 = qcar(v0361);
    v0362 = elt(env, 40); /* member */
    v0361 = elt(env, 6); /* infix */
    v0361 = get(v0362, v0361);
    env = stack[-9];
    v0361 = (Lisp_Object)geq2(v0363, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    v0361 = v0361 ? lisp_true : nil;
    env = stack[-9];
    goto v0391;

v0391:
    if (v0361 == nil) goto v0392;
    v0362 = elt(env, 41); /* "NOT" */
    v0361 = elt(env, 42); /* "infix operator" */
    fn = elt(env, 61); /* typerr */
    v0361 = (*qfn2(fn))(qenv(fn), v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    goto v0392;

v0392:
    v0361 = stack[-8];
    v0361 = qcdr(v0361);
    v0362 = qcar(v0361);
    v0361 = elt(env, 33); /* !*!*un!*!* */
    if (v0362 == v0361) goto v0393;
    v0361 = stack[-5];
    v0361 = qcar(v0361);
    stack[0] = qcdr(v0361);
    v0361 = stack[-8];
    v0362 = qcar(v0361);
    v0361 = stack[-5];
    v0361 = qcar(v0361);
    v0361 = qcdr(v0361);
    if (!consp(v0362)) goto v0394;
    v0362 = qcar(v0362);
    if (!(v0362 == v0361)) goto v0394;
    v0361 = stack[-5];
    v0361 = qcar(v0361);
    v0362 = qcdr(v0361);
    v0361 = elt(env, 35); /* nary */
    v0361 = Lflagp(nil, v0362, v0361);
    env = stack[-9];
    goto v0395;

v0395:
    if (v0361 == nil) goto v0396;
    v0361 = stack[-8];
    v0361 = qcdr(v0361);
    v0362 = qcar(v0361);
    v0361 = stack[-8];
    v0361 = qcar(v0361);
    v0361 = qcdr(v0361);
    v0361 = cons(v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    goto v0397;

v0397:
    v0361 = cons(stack[0], v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[0] = v0361;
    goto v0398;

v0398:
    v0361 = stack[-5];
    v0361 = qcdr(v0361);
    stack[-5] = v0361;
    v0362 = stack[0];
    v0361 = stack[-8];
    v0361 = qcdr(v0361);
    v0361 = qcdr(v0361);
    v0361 = cons(v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-8] = v0361;
    goto v0065;

v0396:
    v0361 = stack[-8];
    v0361 = qcdr(v0361);
    v0362 = qcar(v0361);
    v0361 = stack[-8];
    v0361 = qcar(v0361);
    v0361 = list2(v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    goto v0397;

v0394:
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0395;

v0393:
    v0361 = stack[-8];
    v0362 = qcar(v0361);
    v0361 = elt(env, 33); /* !*!*un!*!* */
    if (v0362 == v0361) goto v0386;
    v0361 = stack[-5];
    v0361 = qcar(v0361);
    v0362 = qcdr(v0361);
    v0361 = stack[-8];
    v0361 = qcar(v0361);
    v0361 = list2(v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[0] = v0361;
    goto v0398;

v0390:
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0391;

v0384:
    v0362 = stack[-3];
    v0361 = stack[-5];
    v0361 = qcar(v0361);
    v0361 = qcdr(v0361);
    if (v0362 == v0361) goto v0399;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0400;

v0400:
    if (v0361 == nil) goto v0401;
    v0361 = qvalue(elt(env, 13)); /* t */
    goto v0385;

v0401:
    v0361 = stack[-5];
    v0361 = qcar(v0361);
    v0362 = qcdr(v0361);
    v0361 = elt(env, 37); /* alt */
    v0361 = get(v0362, v0361);
    env = stack[-9];
    goto v0385;

v0399:
    v0362 = stack[-3];
    v0361 = elt(env, 35); /* nary */
    v0361 = Lflagp(nil, v0362, v0361);
    env = stack[-9];
    if (v0361 == nil) goto v0402;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0400;

v0402:
    v0362 = stack[-3];
    v0361 = elt(env, 36); /* right */
    v0361 = Lflagp(nil, v0362, v0361);
    env = stack[-9];
    v0361 = (v0361 == nil ? lisp_true : nil);
    goto v0400;

v0382:
    v0362 = stack[-4];
    v0361 = (Lisp_Object)1; /* 0 */
    if (v0362 == v0361) goto v0022;
    else goto v0386;

v0375:
    v0361 = stack[-8];
    if (v0361 == nil) goto v0403;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0404;

v0404:
    if (v0361 == nil) goto v0376;
    v0362 = qvalue(elt(env, 2)); /* nil */
    v0361 = stack[-1];
    {
        popv(10);
        fn = elt(env, 59); /* xcomment */
        return (*qfn2(fn))(qenv(fn), v0362, v0361);
    }

v0403:
    v0361 = stack[-6];
    if (v0361 == nil) goto v0405;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0404;

v0405:
    v0361 = stack[-5];
    v0361 = (v0361 == nil ? lisp_true : nil);
    goto v0404;

v0373:
    v0361 = qvalue(elt(env, 13)); /* t */
    goto v0374;

v0368:
    v0362 = elt(env, 27); /* "Improper delimiter" */
    v0361 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0361 = (*qfn2(fn))(qenv(fn), v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    goto v0024;

v0371:
    v0362 = stack[-3];
    v0361 = elt(env, 54); /* (!*rsqbkt!* !*rcbkt!* !*rsqb!*) */
    v0361 = Lmemq(nil, v0362, v0361);
    v0361 = (v0361 == nil ? lisp_true : nil);
    goto v0372;

v0370:
    v0361 = qvalue(elt(env, 13)); /* t */
    goto v0372;

v0369:
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0372;

v0366:
    v0362 = stack[-7];
    v0361 = elt(env, 51); /* for */
    if (v0362 == v0361) goto v0406;
    v0361 = qvalue(elt(env, 52)); /* !*blockp */
    if (v0361 == nil) goto v0407;
    v0361 = stack[-6];
    if (v0361 == nil) goto v0408;
    v0361 = stack[-6];
    v0361 = qcar(v0361);
    if (!consp(v0361)) goto v0409;
    v0361 = qvalue(elt(env, 13)); /* t */
    goto v0367;

v0409:
    v0361 = stack[-6];
    v0361 = qcdr(v0361);
    goto v0367;

v0408:
    v0361 = qvalue(elt(env, 13)); /* t */
    goto v0367;

v0407:
    v0361 = qvalue(elt(env, 13)); /* t */
    goto v0367;

v0406:
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0367;

v0060:
    v0362 = stack[-3];
    v0361 = elt(env, 8); /* stat */
    v0361 = get(v0362, v0361);
    env = stack[-9];
    stack[-4] = v0361;
    if (v0361 == nil) goto v0109;
    v0362 = stack[-4];
    v0361 = elt(env, 43); /* endstat */
    if (v0362 == v0361) goto v0410;
    fn = elt(env, 57); /* eolcheck */
    v0361 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    goto v0410;

v0410:
    v0362 = stack[-3];
    v0361 = elt(env, 44); /* go */
    v0361 = Lflagp(nil, v0362, v0361);
    env = stack[-9];
    if (v0361 == nil) goto v0411;
    v0361 = qvalue(elt(env, 13)); /* t */
    goto v0412;

v0412:
    if (v0361 == nil) goto v0032;
    v0362 = stack[-3];
    v0361 = elt(env, 48); /* procedure */
    if (v0362 == v0361) goto v0413;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0414;

v0414:
    if (v0361 == nil) goto v0415;
    v0361 = stack[-6];
    if (v0361 == nil) goto v0416;
    v0361 = stack[-6];
    v0361 = qcdr(v0361);
    if (!(v0361 == nil)) goto v0417;
    v0361 = qvalue(elt(env, 9)); /* !*reduce4 */
    if (!(v0361 == nil)) goto v0417;
    v0361 = stack[-6];
    v0361 = qcar(v0361);
    fn = elt(env, 62); /* procstat1 */
    v0361 = (*qfn1(fn))(qenv(fn), v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    v0361 = ncons(v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-6] = v0361;
    goto v0418;

v0418:
    v0361 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v0361;
    goto v0030;

v0417:
    v0362 = elt(env, 49); /* "proc form" */
    v0361 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0361 = (*qfn2(fn))(qenv(fn), v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    goto v0418;

v0416:
    v0361 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 62); /* procstat1 */
    v0361 = (*qfn1(fn))(qenv(fn), v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    v0361 = ncons(v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-6] = v0361;
    goto v0418;

v0415:
    v0362 = stack[-4];
    v0361 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 63); /* lispapply */
    v0362 = (*qfn2(fn))(qenv(fn), v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    v0361 = stack[-6];
    v0361 = cons(v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-6] = v0361;
    goto v0418;

v0413:
    v0361 = qvalue(elt(env, 9)); /* !*reduce4 */
    goto v0414;

v0032:
    v0361 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v0361;
    goto v0036;

v0036:
    v0362 = stack[-3];
    v0361 = stack[-6];
    v0361 = cons(v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-6] = v0361;
    v0361 = stack[-3];
    if (is_number(v0361)) goto v0419;
    v0362 = stack[-3];
    v0361 = elt(env, 12); /* !:dn!: */
    if (!consp(v0362)) goto v0420;
    v0362 = qcar(v0362);
    if (!(v0362 == v0361)) goto v0420;
    v0361 = qvalue(elt(env, 13)); /* t */
    goto v0421;

v0421:
    if (!(v0361 == nil)) goto v0419;

v0422:
    v0362 = stack[-7];
    v0361 = elt(env, 21); /* proc */
    if (v0362 == v0361) goto v0423;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0424;

v0424:
    if (v0361 == nil) goto v0005;
    v0362 = elt(env, 22); /* "Syntax error in procedure header" */
    v0361 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0361 = (*qfn2(fn))(qenv(fn), v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    goto v0005;

v0423:
    v0361 = stack[-6];
    v0362 = Llength(nil, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    v0361 = (Lisp_Object)33; /* 2 */
    v0361 = (Lisp_Object)greaterp2(v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    v0361 = v0361 ? lisp_true : nil;
    env = stack[-9];
    goto v0424;

v0419:
    v0362 = stack[-2];
    v0361 = qvalue(elt(env, 15)); /* !$eol!$ */
    if (v0362 == v0361) goto v0425;
    v0361 = qvalue(elt(env, 16)); /* nxtsym!* */
    fn = elt(env, 64); /* chknewnam */
    v0361 = (*qfn1(fn))(qenv(fn), v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-2] = v0361;
    if (symbolp(v0361)) goto v0426;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0427;

v0427:
    if (v0361 == nil) goto v0422;
    v0361 = elt(env, 20); /* times */
    qvalue(elt(env, 3)) = v0361; /* cursym!* */
    goto v0030;

v0426:
    v0362 = stack[-2];
    v0361 = elt(env, 7); /* delim */
    v0361 = Lflagp(nil, v0362, v0361);
    env = stack[-9];
    if (v0361 == nil) goto v0428;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0427;

v0428:
    v0362 = stack[-2];
    v0361 = elt(env, 17); /* switch!* */
    v0361 = get(v0362, v0361);
    env = stack[-9];
    if (v0361 == nil) goto v0429;
    v0362 = stack[-2];
    v0361 = elt(env, 18); /* !( */
    if (v0362 == v0361) goto v0429;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0427;

v0429:
    v0362 = stack[-2];
    v0361 = elt(env, 6); /* infix */
    v0361 = get(v0362, v0361);
    env = stack[-9];
    if (v0361 == nil) goto v0430;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0427;

v0430:
    v0361 = qvalue(elt(env, 19)); /* !*eoldelimp */
    if (v0361 == nil) goto v0431;
    v0362 = stack[-2];
    v0361 = qvalue(elt(env, 15)); /* !$eol!$ */
    v0361 = (v0362 == v0361 ? lisp_true : nil);
    goto v0432;

v0432:
    v0361 = (v0361 == nil ? lisp_true : nil);
    goto v0427;

v0431:
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0432;

v0425:
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0427;

v0420:
    v0362 = stack[-3];
    v0361 = elt(env, 14); /* !:int!: */
    v0361 = Leqcar(nil, v0362, v0361);
    env = stack[-9];
    goto v0421;

v0411:
    v0362 = stack[-7];
    v0361 = elt(env, 21); /* proc */
    if (v0362 == v0361) goto v0433;
    v0362 = stack[-4];
    v0361 = elt(env, 45); /* endstatfn */
    v0361 = Lflagp(nil, v0362, v0361);
    env = stack[-9];
    if (v0361 == nil) goto v0434;
    v0361 = qvalue(elt(env, 13)); /* t */
    goto v0412;

v0434:
    v0362 = qvalue(elt(env, 16)); /* nxtsym!* */
    v0361 = elt(env, 46); /* delchar */
    v0361 = Lflagp(nil, v0362, v0361);
    env = stack[-9];
    if (v0361 == nil) goto v0435;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0412;

v0435:
    v0362 = qvalue(elt(env, 16)); /* nxtsym!* */
    v0361 = elt(env, 47); /* !, */
    v0361 = (v0362 == v0361 ? lisp_true : nil);
    v0361 = (v0361 == nil ? lisp_true : nil);
    goto v0412;

v0433:
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0412;

v0109:
    v0361 = qvalue(elt(env, 9)); /* !*reduce4 */
    if (v0361 == nil) goto v0436;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0044;

v0044:
    if (v0361 == nil) goto v0032;
    v0362 = elt(env, 11); /* decstat */
    v0361 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 63); /* lispapply */
    v0362 = (*qfn2(fn))(qenv(fn), v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    v0361 = stack[-6];
    v0361 = cons(v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-6] = v0361;
    goto v0030;

v0436:
    v0362 = stack[-3];
    v0361 = elt(env, 10); /* type */
    v0361 = Lflagp(nil, v0362, v0361);
    env = stack[-9];
    goto v0044;

v0064:
    fn = elt(env, 57); /* eolcheck */
    v0361 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    v0362 = stack[-3];
    v0361 = elt(env, 25); /* !*comma!* */
    if (v0362 == v0361) goto v0437;
    fn = elt(env, 60); /* scan */
    v0361 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-2] = v0361;
    if (!consp(v0361)) goto v0438;
    v0361 = qvalue(elt(env, 13)); /* t */
    goto v0439;

v0439:
    if (!(v0361 == nil)) goto v0019;
    v0362 = stack[-2];
    v0361 = elt(env, 5); /* !*rpar!* */
    if (v0362 == v0361) goto v0440;
    v0362 = stack[-2];
    v0361 = elt(env, 25); /* !*comma!* */
    if (v0362 == v0361) goto v0441;
    v0362 = stack[-2];
    v0361 = elt(env, 7); /* delim */
    v0361 = Lflagp(nil, v0362, v0361);
    env = stack[-9];
    goto v0442;

v0442:
    if (v0361 == nil) goto v0443;
    v0361 = stack[-4];
    if (v0361 == nil) goto v0444;
    v0361 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v0361;
    goto v0444;

v0444:
    v0362 = stack[-3];
    v0361 = stack[-6];
    v0361 = cons(v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-6] = v0361;
    goto v0025;

v0443:
    v0362 = stack[-2];
    v0361 = elt(env, 4); /* !*lpar!* */
    if (v0362 == v0361) goto v0445;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0446;

v0446:
    if (!(v0361 == nil)) goto v0031;

v0019:
    v0361 = stack[-6];
    if (!(v0361 == nil)) goto v0023;
    v0362 = stack[-3];
    v0361 = elt(env, 31); /* unary */
    v0361 = get(v0362, v0361);
    env = stack[-9];
    stack[-3] = v0361;
    if (!(v0361 == nil)) goto v0447;
    v0362 = elt(env, 32); /* "Redundant operator" */
    v0361 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0361 = (*qfn2(fn))(qenv(fn), v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    goto v0447;

v0447:
    v0362 = elt(env, 33); /* !*!*un!*!* */
    v0361 = stack[-8];
    v0361 = cons(v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-8] = v0361;
    goto v0386;

v0445:
    fn = elt(env, 57); /* eolcheck */
    v0361 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    if (v0361 == nil) goto v0448;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0446;

v0448:
    fn = elt(env, 60); /* scan */
    v0361 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    v0361 = qvalue(elt(env, 19)); /* !*eoldelimp */
    if (v0361 == nil) goto v0449;
    v0362 = qvalue(elt(env, 3)); /* cursym!* */
    v0361 = elt(env, 30); /* !*semicol!* */
    if (v0362 == v0361) goto v0448;
    else goto v0449;

v0449:
    v0361 = elt(env, 24); /* paren */
    v0361 = CC_xread1(env, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-2] = v0361;
    if (!consp(v0361)) goto v0450;
    v0361 = stack[-2];
    v0362 = qcar(v0361);
    v0361 = elt(env, 25); /* !*comma!* */
    if (v0362 == v0361) goto v0451;
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0446;

v0451:
    v0362 = stack[-3];
    v0361 = stack[-2];
    v0361 = qcdr(v0361);
    v0361 = cons(v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-3] = v0361;
    goto v0446;

v0450:
    v0361 = qvalue(elt(env, 2)); /* nil */
    goto v0446;

v0441:
    v0361 = qvalue(elt(env, 13)); /* t */
    goto v0442;

v0440:
    v0361 = qvalue(elt(env, 13)); /* t */
    goto v0442;

v0438:
    v0361 = stack[-2];
    v0361 = (is_number(v0361) ? lisp_true : nil);
    if (!(v0361 == nil)) goto v0439;
    v0362 = stack[-2];
    v0361 = elt(env, 12); /* !:dn!: */
    if (!consp(v0362)) goto v0452;
    v0362 = qcar(v0362);
    if (!(v0362 == v0361)) goto v0452;
    v0361 = qvalue(elt(env, 13)); /* t */
    goto v0439;

v0452:
    v0362 = stack[-2];
    v0361 = elt(env, 14); /* !:int!: */
    v0361 = Leqcar(nil, v0362, v0361);
    env = stack[-9];
    goto v0439;

v0437:
    v0361 = qvalue(elt(env, 13)); /* t */
    goto v0439;

v0018:
    v0361 = stack[-7];
    if (v0361 == nil) goto v0453;
    v0362 = stack[-7];
    v0361 = elt(env, 28); /* group */
    if (v0362 == v0361) goto v0454;
    v0362 = stack[-7];
    v0361 = elt(env, 21); /* proc */
    v0361 = (v0362 == v0361 ? lisp_true : nil);
    goto v0455;

v0455:
    if (v0361 == nil) goto v0024;
    v0362 = elt(env, 29); /* "Too many right parentheses" */
    v0361 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0361 = (*qfn2(fn))(qenv(fn), v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    goto v0064;

v0454:
    v0361 = qvalue(elt(env, 13)); /* t */
    goto v0455;

v0453:
    v0361 = qvalue(elt(env, 13)); /* t */
    goto v0455;

v0006:
    fn = elt(env, 57); /* eolcheck */
    v0361 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    v0361 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v0361;
    fn = elt(env, 60); /* scan */
    v0362 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    v0361 = elt(env, 5); /* !*rpar!* */
    if (v0362 == v0361) goto v0017;
    v0362 = stack[-6];
    v0361 = elt(env, 23); /* struct */
    v0361 = Lflagpcar(nil, v0362, v0361);
    env = stack[-9];
    if (v0361 == nil) goto v0456;
    v0361 = stack[-6];
    v0361 = qcar(v0361);
    v0361 = CC_xread1(env, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-3] = v0361;
    goto v0457;

v0457:
    v0362 = stack[-7];
    v0361 = elt(env, 23); /* struct */
    v0361 = Lflagp(nil, v0362, v0361);
    env = stack[-9];
    if (v0361 == nil) goto v0458;
    v0362 = stack[-3];
    v0361 = elt(env, 25); /* !*comma!* */
    if (!consp(v0362)) goto v0459;
    v0362 = qcar(v0362);
    if (!(v0362 == v0361)) goto v0459;
    v0361 = stack[-3];
    v0361 = qcdr(v0361);
    goto v0460;

v0460:
    stack[-3] = v0361;
    goto v0036;

v0459:
    v0361 = stack[-3];
    v0361 = ncons(v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    goto v0460;

v0458:
    v0362 = stack[-3];
    v0361 = elt(env, 25); /* !*comma!* */
    if (!consp(v0362)) goto v0036;
    v0362 = qcar(v0362);
    if (!(v0362 == v0361)) goto v0036;
    v0361 = stack[-6];
    if (v0361 == nil) goto v0461;
    v0361 = stack[-6];
    v0363 = qcar(v0361);
    v0361 = stack[-3];
    v0362 = qcdr(v0361);
    v0361 = stack[-6];
    v0361 = qcdr(v0361);
    v0361 = acons(v0363, v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-6] = v0361;
    goto v0005;

v0461:
    v0362 = stack[-7];
    v0361 = elt(env, 26); /* lambda */
    if (v0362 == v0361) goto v0036;
    v0362 = elt(env, 27); /* "Improper delimiter" */
    v0361 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v0361 = (*qfn2(fn))(qenv(fn), v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    goto v0005;

v0456:
    v0361 = elt(env, 24); /* paren */
    v0361 = CC_xread1(env, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-3] = v0361;
    goto v0457;

v0017:
    v0361 = stack[-6];
    if (v0361 == nil) goto v0005;
    v0361 = stack[-6];
    v0361 = qcar(v0361);
    v0362 = ncons(v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    v0361 = stack[-6];
    v0361 = qcdr(v0361);
    v0361 = cons(v0362, v0361);
    nil = C_nil;
    if (exception_pending()) goto v0365;
    env = stack[-9];
    stack[-6] = v0361;
    goto v0005;
/* error exit handlers */
v0365:
    popv(10);
    return nil;
}



/* Code for cl_atfp */

static Lisp_Object CC_cl_atfp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0472, v0473, v0474;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_atfp");
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
    v0473 = v0000;
/* end of prologue */
    v0472 = v0473;
    if (!consp(v0472)) goto v0021;
    v0472 = v0473;
    v0472 = qcar(v0472);
    goto v0080;

v0080:
    v0474 = v0472;
    v0473 = v0474;
    v0472 = elt(env, 1); /* true */
    if (v0473 == v0472) goto v0018;
    v0473 = v0474;
    v0472 = elt(env, 3); /* false */
    v0472 = (v0473 == v0472 ? lisp_true : nil);
    goto v0017;

v0017:
    if (v0472 == nil) goto v0130;
    v0472 = qvalue(elt(env, 2)); /* t */
    goto v0032;

v0032:
    v0472 = (v0472 == nil ? lisp_true : nil);
    return onevalue(v0472);

v0130:
    v0473 = v0474;
    v0472 = elt(env, 4); /* or */
    if (v0473 == v0472) goto v0092;
    v0473 = v0474;
    v0472 = elt(env, 5); /* and */
    v0472 = (v0473 == v0472 ? lisp_true : nil);
    goto v0119;

v0119:
    if (v0472 == nil) goto v0102;
    v0472 = qvalue(elt(env, 2)); /* t */
    goto v0008;

v0008:
    if (v0472 == nil) goto v0047;
    v0472 = qvalue(elt(env, 2)); /* t */
    goto v0118;

v0118:
    if (v0472 == nil) goto v0056;
    v0472 = qvalue(elt(env, 2)); /* t */
    goto v0032;

v0056:
    v0473 = v0474;
    v0472 = elt(env, 10); /* ex */
    if (v0473 == v0472) goto v0037;
    v0473 = v0474;
    v0472 = elt(env, 11); /* all */
    v0472 = (v0473 == v0472 ? lisp_true : nil);
    goto v0113;

v0113:
    if (v0472 == nil) goto v0099;
    v0472 = qvalue(elt(env, 2)); /* t */
    goto v0032;

v0099:
    v0473 = v0474;
    v0472 = elt(env, 12); /* bex */
    if (v0473 == v0472) goto v0475;
    v0473 = v0474;
    v0472 = elt(env, 13); /* ball */
    v0472 = (v0473 == v0472 ? lisp_true : nil);
    goto v0476;

v0476:
    if (v0472 == nil) goto v0477;
    v0472 = qvalue(elt(env, 2)); /* t */
    goto v0032;

v0477:
    v0473 = v0474;
    v0472 = elt(env, 14); /* rl_external */
    v0472 = get(v0473, v0472);
    goto v0032;

v0475:
    v0472 = qvalue(elt(env, 2)); /* t */
    goto v0476;

v0037:
    v0472 = qvalue(elt(env, 2)); /* t */
    goto v0113;

v0047:
    v0473 = v0474;
    v0472 = elt(env, 7); /* impl */
    if (v0473 == v0472) goto v0478;
    v0473 = v0474;
    v0472 = elt(env, 8); /* repl */
    if (v0473 == v0472) goto v0045;
    v0473 = v0474;
    v0472 = elt(env, 9); /* equiv */
    v0472 = (v0473 == v0472 ? lisp_true : nil);
    goto v0118;

v0045:
    v0472 = qvalue(elt(env, 2)); /* t */
    goto v0118;

v0478:
    v0472 = qvalue(elt(env, 2)); /* t */
    goto v0118;

v0102:
    v0473 = v0474;
    v0472 = elt(env, 6); /* not */
    v0472 = (v0473 == v0472 ? lisp_true : nil);
    goto v0008;

v0092:
    v0472 = qvalue(elt(env, 2)); /* t */
    goto v0119;

v0018:
    v0472 = qvalue(elt(env, 2)); /* t */
    goto v0017;

v0021:
    v0472 = v0473;
    goto v0080;
}



/* Code for ibalp_lenisone */

static Lisp_Object CC_ibalp_lenisone(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0032;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_lenisone");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0032 = v0000;
/* end of prologue */
    v0031 = v0032;
    if (v0031 == nil) goto v0021;
    v0031 = v0032;
    v0031 = qcdr(v0031);
    v0031 = (v0031 == nil ? lisp_true : nil);
    return onevalue(v0031);

v0021:
    v0031 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0031);
}



/* Code for numpoly_nullp */

static Lisp_Object CC_numpoly_nullp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0018;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numpoly_nullp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0018 = v0000;
/* end of prologue */
    v0017 = v0018;
    if (v0017 == nil) goto v0021;
    v0017 = (Lisp_Object)1; /* 0 */
    v0017 = (v0018 == v0017 ? lisp_true : nil);
    return onevalue(v0017);

v0021:
    v0017 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0017);
}



/* Code for inshisto */

static Lisp_Object CC_inshisto(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0475, v0481, v0099;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inshisto");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0481 = qvalue(elt(env, 2)); /* maxvar */
    v0475 = stack[-3];
    v0475 = plus2(v0481, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-5];
    v0481 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0475/(16/CELL)));
    v0475 = (Lisp_Object)1; /* 0 */
    v0475 = *(Lisp_Object *)((char *)v0481 + (CELL-TAG_VECTOR) + ((int32_t)v0475/(16/CELL)));
    if (v0475 == nil) goto v0029;
    v0481 = stack[-3];
    v0475 = (Lisp_Object)1; /* 0 */
    v0475 = (Lisp_Object)geq2(v0481, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    v0475 = v0475 ? lisp_true : nil;
    env = stack[-5];
    if (v0475 == nil) goto v0029;
    stack[0] = qvalue(elt(env, 3)); /* codhisto */
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0481 = qvalue(elt(env, 2)); /* maxvar */
    v0475 = stack[-3];
    v0475 = plus2(v0481, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-5];
    v0481 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0475/(16/CELL)));
    v0475 = (Lisp_Object)17; /* 1 */
    v0475 = *(Lisp_Object *)((char *)v0481 + (CELL-TAG_VECTOR) + ((int32_t)v0475/(16/CELL)));
    v0481 = qcdr(v0475);
    v0475 = (Lisp_Object)3201; /* 200 */
    fn = elt(env, 6); /* min */
    v0475 = (*qfn2(fn))(qenv(fn), v0481, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-5];
    stack[-2] = v0475;
    v0475 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0475/(16/CELL)));
    stack[-4] = v0475;
    if (v0475 == nil) goto v0482;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0481 = qvalue(elt(env, 2)); /* maxvar */
    v0475 = stack[-4];
    v0475 = plus2(v0481, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-5];
    v0481 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0475/(16/CELL)));
    v0475 = (Lisp_Object)113; /* 7 */
    v0481 = *(Lisp_Object *)((char *)v0481 + (CELL-TAG_VECTOR) + ((int32_t)v0475/(16/CELL)));
    v0475 = stack[-3];
    v0475 = Lrplaca(nil, v0481, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-5];
    goto v0072;

v0072:
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0481 = qvalue(elt(env, 2)); /* maxvar */
    v0475 = stack[-3];
    v0475 = plus2(v0481, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-5];
    stack[-1] = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0475/(16/CELL)));
    stack[0] = (Lisp_Object)113; /* 7 */
    v0481 = qvalue(elt(env, 5)); /* nil */
    v0475 = stack[-4];
    v0475 = cons(v0481, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    env = stack[-5];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0475;
    v0099 = qvalue(elt(env, 3)); /* codhisto */
    v0481 = stack[-2];
    v0475 = stack[-3];
    *(Lisp_Object *)((char *)v0099 + (CELL-TAG_VECTOR) + ((int32_t)v0481/(16/CELL))) = v0475;
    v0475 = nil;
    { popv(6); return onevalue(v0475); }

v0482:
    v0481 = stack[-2];
    v0475 = qvalue(elt(env, 4)); /* headhisto */
    v0475 = (Lisp_Object)greaterp2(v0481, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0465;
    v0475 = v0475 ? lisp_true : nil;
    env = stack[-5];
    if (v0475 == nil) goto v0072;
    v0475 = stack[-2];
    qvalue(elt(env, 4)) = v0475; /* headhisto */
    goto v0072;

v0029:
    v0475 = nil;
    { popv(6); return onevalue(v0475); }
/* error exit handlers */
v0465:
    popv(6);
    return nil;
}



/* Code for evenfree */

static Lisp_Object CC_evenfree(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0052;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evenfree");
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
    v0091 = stack[0];
    if (v0091 == nil) goto v0021;
    v0091 = stack[0];
    if (is_number(v0091)) goto v0030;
    v0091 = stack[0];
    v0091 = qcar(v0091);
    v0052 = ncons(v0091);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    v0091 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 2); /* qremd */
    v0091 = (*qfn2(fn))(qenv(fn), v0052, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    v0091 = qcdr(v0091);
    stack[-1] = v0091;
    v0091 = stack[-1];
    fn = elt(env, 3); /* minusf */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    if (v0091 == nil) goto v0126;
    v0091 = stack[-1];
    fn = elt(env, 4); /* negf */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    stack[-1] = v0091;
    goto v0028;

v0028:
    v0091 = stack[0];
    v0091 = qcdr(v0091);
    v0091 = CC_evenfree(env, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    {
        Lisp_Object v0059 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* addf */
        return (*qfn2(fn))(qenv(fn), v0059, v0091);
    }

v0126:
    v0091 = stack[-1];
    stack[-1] = v0091;
    goto v0028;

v0030:
    v0052 = stack[0];
    v0091 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 2); /* qremd */
    v0091 = (*qfn2(fn))(qenv(fn), v0052, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    v0091 = qcdr(v0091);
    stack[0] = v0091;
    v0091 = stack[0];
    fn = elt(env, 3); /* minusf */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    if (v0091 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0091 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* negf */
        return (*qfn1(fn))(qenv(fn), v0091);
    }

v0021:
    v0091 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0091); }
/* error exit handlers */
v0103:
    popv(3);
    return nil;
}



/* Code for revalind */

static Lisp_Object CC_revalind(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0117, v0120, v0011;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for revalind");
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
    stack[0] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v0117 = qvalue(elt(env, 2)); /* nil */
    v0117 = ncons(v0117);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0117; /* alglist!* */
    v0117 = qvalue(elt(env, 3)); /* subfg!* */
    stack[-2] = v0117;
    v0117 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v0117; /* subfg!* */
    v0011 = elt(env, 4); /* !0 */
    v0120 = (Lisp_Object)1; /* 0 */
    v0117 = stack[-1];
    v0117 = Lsubst(nil, 3, v0011, v0120, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-3];
    stack[-1] = v0117;
    v0117 = stack[-1];
    fn = elt(env, 6); /* simp */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-3];
    v0120 = v0117;
    v0117 = v0120;
    v0117 = qcar(v0117);
    if (v0117 == nil) goto v0065;
    v0117 = elt(env, 5); /* prepf */
    fn = elt(env, 7); /* sqform */
    v0117 = (*qfn2(fn))(qenv(fn), v0120, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-3];
    goto v0067;

v0067:
    v0120 = v0117;
    v0117 = stack[-2];
    qvalue(elt(env, 3)) = v0117; /* subfg!* */
    v0117 = v0120;
    qvalue(elt(env, 1)) = stack[0]; /* alglist!* */
    { popv(4); return onevalue(v0117); }

v0065:
    v0117 = (Lisp_Object)1; /* 0 */
    goto v0067;
/* error exit handlers */
v0007:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[0]; /* alglist!* */
    popv(4);
    return nil;
}



/* Code for all_defined_vertex */

static Lisp_Object CC_all_defined_vertex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0017, v0018, v0064;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for all_defined_vertex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0006 = v0016;
    v0017 = v0000;
/* end of prologue */
    v0064 = v0017;
    v0018 = qvalue(elt(env, 1)); /* nil */
    v0017 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* al1_defined_vertex */
        return (*qfnn(fn))(qenv(fn), 4, v0064, v0018, v0017, v0006);
    }
}



/* Code for getmatelem */

static Lisp_Object CC_getmatelem(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0491, v0492, v0493;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getmatelem");
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

v0014:
    v0491 = stack[-1];
    v0492 = Llength(nil, v0491);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-3];
    v0491 = (Lisp_Object)49; /* 3 */
    if (v0492 == v0491) goto v0065;
    v0492 = stack[-1];
    v0491 = elt(env, 1); /* "matrix element" */
    fn = elt(env, 12); /* typerr */
    v0491 = (*qfn2(fn))(qenv(fn), v0492, v0491);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-3];
    goto v0065;

v0065:
    v0491 = stack[-1];
    v0492 = qcar(v0491);
    v0491 = elt(env, 2); /* avalue */
    v0491 = get(v0492, v0491);
    env = stack[-3];
    stack[-2] = v0491;
    v0491 = stack[-2];
    if (v0491 == nil) goto v0090;
    v0491 = stack[-2];
    v0492 = qcar(v0491);
    v0491 = elt(env, 4); /* matrix */
    v0491 = (v0492 == v0491 ? lisp_true : nil);
    v0491 = (v0491 == nil ? lisp_true : nil);
    goto v0069;

v0069:
    if (v0491 == nil) goto v0480;
    v0491 = stack[-1];
    v0492 = qcar(v0491);
    v0491 = elt(env, 5); /* "matrix" */
    fn = elt(env, 12); /* typerr */
    v0491 = (*qfn2(fn))(qenv(fn), v0492, v0491);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-3];
    goto v0027;

v0027:
    v0491 = stack[-1];
    v0491 = qcdr(v0491);
    v0491 = qcar(v0491);
    fn = elt(env, 13); /* reval_without_mod */
    v0491 = (*qfn1(fn))(qenv(fn), v0491);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-3];
    stack[0] = v0491;
    v0491 = stack[0];
    v0491 = integerp(v0491);
    if (v0491 == nil) goto v0084;
    v0492 = stack[0];
    v0491 = (Lisp_Object)1; /* 0 */
    v0491 = (Lisp_Object)lesseq2(v0492, v0491);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    v0491 = v0491 ? lisp_true : nil;
    env = stack[-3];
    goto v0083;

v0083:
    if (v0491 == nil) goto v0467;
    v0492 = stack[0];
    v0491 = elt(env, 11); /* "positive integer" */
    fn = elt(env, 12); /* typerr */
    v0491 = (*qfn2(fn))(qenv(fn), v0492, v0491);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-3];
    goto v0467;

v0467:
    v0491 = stack[-2];
    v0492 = qcdr(v0491);
    v0491 = stack[0];
    fn = elt(env, 14); /* pnth */
    v0491 = (*qfn2(fn))(qenv(fn), v0492, v0491);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-3];
    v0491 = qcar(v0491);
    stack[-2] = v0491;
    v0491 = stack[-1];
    v0491 = qcdr(v0491);
    v0491 = qcdr(v0491);
    v0491 = qcar(v0491);
    fn = elt(env, 13); /* reval_without_mod */
    v0491 = (*qfn1(fn))(qenv(fn), v0491);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-3];
    stack[0] = v0491;
    v0491 = stack[0];
    v0491 = integerp(v0491);
    if (v0491 == nil) goto v0495;
    v0492 = stack[0];
    v0491 = (Lisp_Object)1; /* 0 */
    v0491 = (Lisp_Object)lesseq2(v0492, v0491);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    v0491 = v0491 ? lisp_true : nil;
    env = stack[-3];
    goto v0465;

v0465:
    if (v0491 == nil) goto v0473;
    v0492 = stack[0];
    v0491 = elt(env, 11); /* "positive integer" */
    fn = elt(env, 12); /* typerr */
    v0491 = (*qfn2(fn))(qenv(fn), v0492, v0491);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-3];
    goto v0473;

v0473:
    v0492 = stack[-2];
    v0491 = stack[0];
    fn = elt(env, 14); /* pnth */
    v0491 = (*qfn2(fn))(qenv(fn), v0492, v0491);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    v0491 = qcar(v0491);
    { popv(4); return onevalue(v0491); }

v0495:
    v0491 = qvalue(elt(env, 3)); /* t */
    goto v0465;

v0084:
    v0491 = qvalue(elt(env, 3)); /* t */
    goto v0083;

v0480:
    v0491 = stack[-2];
    v0491 = qcdr(v0491);
    v0492 = qcar(v0491);
    stack[-2] = v0492;
    v0491 = elt(env, 6); /* mat */
    if (!consp(v0492)) goto v0091;
    v0492 = qcar(v0492);
    if (v0492 == v0491) goto v0027;
    else goto v0091;

v0091:
    v0491 = stack[-2];
    if (symbolp(v0491)) goto v0359;
    v0493 = elt(env, 7); /* "Matrix" */
    v0491 = stack[-1];
    v0492 = qcar(v0491);
    v0491 = elt(env, 8); /* "not set" */
    v0491 = list3(v0493, v0492, v0491);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-3];
    v0492 = v0491;
    v0491 = v0492;
    qvalue(elt(env, 9)) = v0491; /* errmsg!* */
    v0491 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v0491 == nil)) goto v0496;
    v0491 = v0492;
    fn = elt(env, 15); /* lprie */
    v0491 = (*qfn1(fn))(qenv(fn), v0491);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-3];
    goto v0496;

v0496:
    v0491 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-3];
    goto v0027;

v0359:
    v0492 = stack[-2];
    v0491 = stack[-1];
    v0491 = qcdr(v0491);
    v0491 = cons(v0492, v0491);
    nil = C_nil;
    if (exception_pending()) goto v0494;
    env = stack[-3];
    stack[-1] = v0491;
    goto v0014;

v0090:
    v0491 = qvalue(elt(env, 3)); /* t */
    goto v0069;
/* error exit handlers */
v0494:
    popv(4);
    return nil;
}



/* Code for b!:extadd */

static Lisp_Object CC_bTextadd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0113, v0037, v0055;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for b:extadd");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0016;
    stack[-2] = v0000;
/* end of prologue */
    stack[0] = nil;
    goto v0121;

v0121:
    v0113 = stack[-2];
    if (v0113 == nil) goto v0031;
    v0113 = stack[-1];
    if (v0113 == nil) goto v0023;
    v0113 = stack[-2];
    v0113 = qcar(v0113);
    v0037 = qcar(v0113);
    v0113 = stack[-1];
    v0113 = qcar(v0113);
    v0113 = qcar(v0113);
    if (equal(v0037, v0113)) goto v0120;
    v0113 = stack[-2];
    v0113 = qcar(v0113);
    v0037 = qcar(v0113);
    v0113 = stack[-1];
    v0113 = qcar(v0113);
    v0113 = qcar(v0113);
    fn = elt(env, 1); /* b!:ordexp */
    v0113 = (*qfn2(fn))(qenv(fn), v0037, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    if (v0113 == nil) goto v0039;
    v0113 = stack[-2];
    v0037 = qcar(v0113);
    v0113 = stack[0];
    v0113 = cons(v0037, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    stack[0] = v0113;
    v0113 = stack[-2];
    v0113 = qcdr(v0113);
    stack[-2] = v0113;
    goto v0121;

v0039:
    v0113 = stack[-1];
    v0037 = qcar(v0113);
    v0113 = stack[0];
    v0113 = cons(v0037, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    stack[0] = v0113;
    v0113 = stack[-1];
    v0113 = qcdr(v0113);
    stack[-1] = v0113;
    goto v0121;

v0120:
    stack[-3] = stack[0];
    v0113 = stack[-2];
    v0113 = qcar(v0113);
    v0037 = qcdr(v0113);
    v0113 = stack[-1];
    v0113 = qcar(v0113);
    v0113 = qcdr(v0113);
    fn = elt(env, 2); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0037, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    v0113 = stack[-2];
    v0037 = qcdr(v0113);
    v0113 = stack[-1];
    v0113 = qcdr(v0113);
    v0113 = CC_bTextadd(env, v0037, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    v0037 = stack[0];
    v0055 = v0037;
    if (v0055 == nil) goto v0041;
    v0055 = stack[-2];
    v0055 = qcar(v0055);
    v0055 = qcar(v0055);
    v0113 = acons(v0055, v0037, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-4];
    goto v0041;

v0041:
    {
        Lisp_Object v0074 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0074, v0113);
    }

v0023:
    v0037 = stack[0];
    v0113 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0037, v0113);
    }

v0031:
    v0037 = stack[0];
    v0113 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0037, v0113);
    }
/* error exit handlers */
v0073:
    popv(5);
    return nil;
}



/* Code for negate!-term */

static Lisp_Object CC_negateKterm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for negate-term");
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
    v0032 = v0000;
/* end of prologue */
    v0031 = v0032;
    stack[0] = qcar(v0031);
    v0031 = v0032;
    v0031 = qcdr(v0031);
    fn = elt(env, 1); /* minus!-mod!-p */
    v0031 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0005;
    {
        Lisp_Object v0006 = stack[0];
        popv(1);
        return cons(v0006, v0031);
    }
/* error exit handlers */
v0005:
    popv(1);
    return nil;
}



/* Code for defineargs */

static Lisp_Object CC_defineargs(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0111, v0110, v0128, v0087;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for defineargs");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0016;
    stack[-1] = v0000;
/* end of prologue */
    v0110 = stack[-1];
    v0111 = elt(env, 1); /* number!-of!-args */
    v0111 = get(v0110, v0111);
    env = stack[-2];
    v0110 = v0111;
    v0111 = v0110;
    if (v0111 == nil) goto v0019;
    v0128 = stack[0];
    v0111 = v0110;
    if (equal(v0128, v0111)) goto v0070;
    v0128 = stack[-1];
    v0111 = elt(env, 3); /* calledby */
    v0128 = get(v0128, v0111);
    env = stack[-2];
    v0111 = v0128;
    if (v0128 == nil) goto v0052;
    v0087 = stack[-1];
    v0128 = stack[0];
    fn = elt(env, 4); /* instdof */
    v0111 = (*qfnn(fn))(qenv(fn), 4, v0087, v0128, v0110, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    goto v0052;

v0052:
    v0110 = stack[-1];
    v0111 = stack[0];
    fn = elt(env, 5); /* hasarg */
    v0111 = (*qfn2(fn))(qenv(fn), v0110, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    v0111 = nil;
    { popv(3); return onevalue(v0111); }

v0070:
    v0111 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0111); }

v0019:
    v0110 = stack[-1];
    v0111 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* hasarg */
        return (*qfn2(fn))(qenv(fn), v0110, v0111);
    }
/* error exit handlers */
v0101:
    popv(3);
    return nil;
}



/* Code for ofsf_smmkatl */

static Lisp_Object MS_CDECL CC_ofsf_smmkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0016,
                         Lisp_Object v0066, Lisp_Object v0080, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0069, v0090, v0116, v0100, v0117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smmkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smmkatl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0116 = v0080;
    v0100 = v0066;
    v0117 = v0016;
    v0069 = v0000;
/* end of prologue */
    v0090 = v0069;
    v0069 = elt(env, 1); /* and */
    if (v0090 == v0069) goto v0006;
    v0069 = v0117;
    v0090 = v0100;
    {
        fn = elt(env, 2); /* ofsf_smmkatl!-or */
        return (*qfnn(fn))(qenv(fn), 3, v0069, v0090, v0116);
    }

v0006:
    v0069 = v0117;
    v0090 = v0100;
    {
        fn = elt(env, 3); /* ofsf_smmkatl!-and */
        return (*qfnn(fn))(qenv(fn), 3, v0069, v0090, v0116);
    }
}



/* Code for qqe_simplat1 */

static Lisp_Object CC_qqe_simplat1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0124, v0010, v0119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplat1");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0016;
    stack[-1] = v0000;
/* end of prologue */
    v0124 = stack[-1];
    fn = elt(env, 3); /* qqe_op */
    v0124 = (*qfn1(fn))(qenv(fn), v0124);
    nil = C_nil;
    if (exception_pending()) goto v0130;
    env = stack[-2];
    v0119 = v0124;
    v0010 = v0119;
    v0124 = elt(env, 1); /* (qequal qneq) */
    v0124 = Lmemq(nil, v0010, v0124);
    if (v0124 == nil) goto v0018;
    v0010 = v0119;
    v0124 = elt(env, 2); /* qequal */
    if (v0010 == v0124) goto v0027;
    v0010 = stack[-1];
    v0124 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* qqe_simplqneq */
        return (*qfn2(fn))(qenv(fn), v0010, v0124);
    }

v0027:
    v0010 = stack[-1];
    v0124 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* qqe_simplqequal */
        return (*qfn2(fn))(qenv(fn), v0010, v0124);
    }

v0018:
    v0010 = stack[-1];
    v0124 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* qqe_simplbtat */
        return (*qfn2(fn))(qenv(fn), v0010, v0124);
    }
/* error exit handlers */
v0130:
    popv(3);
    return nil;
}



/* Code for ibalp_hassimple */

static Lisp_Object CC_ibalp_hassimple(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090, v0116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_hassimple");
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
    v0090 = v0000;
/* end of prologue */
    stack[-1] = nil;
    stack[0] = v0090;
    goto v0012;

v0012:
    v0090 = stack[0];
    if (v0090 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0090 = stack[-1];
    if (!(v0090 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0090 = stack[0];
    v0090 = qcar(v0090);
    v0116 = qcar(v0090);
    v0090 = stack[0];
    v0090 = qcar(v0090);
    v0090 = qcdr(v0090);
    v0090 = qcar(v0090);
    fn = elt(env, 2); /* ibalp_commonlenisone */
    v0090 = (*qfn2(fn))(qenv(fn), v0116, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-2];
    if (v0090 == nil) goto v0064;
    v0090 = stack[0];
    v0090 = qcar(v0090);
    stack[-1] = v0090;
    goto v0064;

v0064:
    v0090 = stack[0];
    v0090 = qcdr(v0090);
    stack[0] = v0090;
    goto v0012;
/* error exit handlers */
v0120:
    popv(3);
    return nil;
}



/* Code for constsml */

static Lisp_Object CC_constsml(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0129, v0359;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for constsml");
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
    v0129 = stack[0];
    if (!(is_number(v0129))) goto v0029;
    v0129 = elt(env, 1); /* "<cn" */
    fn = elt(env, 13); /* printout */
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-1];
    v0129 = stack[0];
    v0129 = Lfloatp(nil, v0129);
    env = stack[-1];
    if (v0129 == nil) goto v0032;
    v0129 = elt(env, 2); /* " type=""real""> " */
    v0129 = Lprinc(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-1];
    goto v0030;

v0030:
    v0129 = stack[0];
    v0129 = Lprinc(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-1];
    v0129 = elt(env, 5); /* " </cn>" */
    v0129 = Lprinc(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-1];
    goto v0029;

v0029:
    v0129 = stack[0];
    if (!(symbolp(v0129))) goto v0068;
    v0129 = stack[0];
    v0359 = Lintern(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-1];
    v0129 = qvalue(elt(env, 6)); /* constants!* */
    v0129 = Lmember(nil, v0359, v0129);
    if (v0129 == nil) goto v0093;
    v0129 = elt(env, 7); /* "<cn type=""constant""> " */
    fn = elt(env, 13); /* printout */
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-1];
    v0129 = stack[0];
    v0129 = Lprinc(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-1];
    v0129 = elt(env, 5); /* " </cn>" */
    v0129 = Lprinc(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    goto v0068;

v0068:
    v0129 = nil;
    { popv(2); return onevalue(v0129); }

v0093:
    v0129 = elt(env, 8); /* "<ci" */
    fn = elt(env, 13); /* printout */
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-1];
    v0129 = stack[0];
    fn = elt(env, 14); /* listp */
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-1];
    if (v0129 == nil) goto v0051;
    v0129 = elt(env, 9); /* " type=""list""> " */
    v0129 = Lprinc(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-1];
    goto v0122;

v0122:
    v0129 = stack[0];
    v0129 = Lprinc(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-1];
    v0129 = elt(env, 11); /* " </ci>" */
    v0129 = Lprinc(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    goto v0068;

v0051:
    v0129 = stack[0];
    v0129 = Lsimple_vectorp(nil, v0129);
    env = stack[-1];
    if (v0129 == nil) goto v0110;
    v0129 = elt(env, 10); /* " type=""vector""> " */
    v0129 = Lprinc(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-1];
    goto v0122;

v0110:
    v0129 = elt(env, 4); /* "> " */
    v0129 = Lprinc(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-1];
    goto v0122;

v0032:
    v0129 = stack[0];
    v0129 = integerp(v0129);
    if (v0129 == nil) goto v0104;
    v0129 = elt(env, 3); /* " type=""integer""> " */
    v0129 = Lprinc(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-1];
    goto v0030;

v0104:
    v0129 = elt(env, 4); /* "> " */
    v0129 = Lprinc(nil, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-1];
    goto v0030;
/* error exit handlers */
v0109:
    popv(2);
    return nil;
}



/* Code for simprecip */

static Lisp_Object CC_simprecip(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0026, v0027;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simprecip");
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
    v0027 = v0000;
/* end of prologue */
    v0026 = qvalue(elt(env, 1)); /* !*mcd */
    if (v0026 == nil) goto v0006;
    v0026 = elt(env, 2); /* recip */
    fn = elt(env, 3); /* carx */
    v0026 = (*qfn2(fn))(qenv(fn), v0027, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[0];
    fn = elt(env, 4); /* simp */
    v0026 = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 5); /* invsq */
        return (*qfn1(fn))(qenv(fn), v0026);
    }

v0006:
    v0026 = elt(env, 2); /* recip */
    fn = elt(env, 3); /* carx */
    v0027 = (*qfn2(fn))(qenv(fn), v0027, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[0];
    v0026 = (Lisp_Object)-15; /* -1 */
    v0026 = list2(v0027, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 6); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v0026);
    }
/* error exit handlers */
v0028:
    popv(1);
    return nil;
}



/* Code for list!-mgen */

static Lisp_Object CC_listKmgen(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0069;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list-mgen");
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
    v0069 = v0000;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* i */
    qvalue(elt(env, 1)) = nil; /* i */
    v0004 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v0004; /* i */
    v0004 = v0069;
    stack[0] = v0004;
    goto v0012;

v0012:
    v0004 = stack[0];
    if (v0004 == nil) goto v0013;
    v0004 = stack[0];
    v0004 = qcar(v0004);
    v0069 = v0004;
    v0004 = v0069;
    if (!consp(v0004)) goto v0067;
    v0004 = qvalue(elt(env, 2)); /* nil */
    goto v0104;

v0104:
    if (v0004 == nil) goto v0019;
    v0004 = qvalue(elt(env, 1)); /* i */
    v0004 = add1(v0004);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0004; /* i */
    goto v0019;

v0019:
    v0004 = stack[0];
    v0004 = qcdr(v0004);
    stack[0] = v0004;
    goto v0012;

v0067:
    v0004 = v0069;
    fn = elt(env, 3); /* mgenp */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-2];
    goto v0104;

v0013:
    v0004 = qvalue(elt(env, 1)); /* i */
    qvalue(elt(env, 1)) = stack[-1]; /* i */
    { popv(3); return onevalue(v0004); }
/* error exit handlers */
v0100:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* i */
    popv(3);
    return nil;
}



/* Code for vbcgcd */

static Lisp_Object CC_vbcgcd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vbcgcd");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0016;
    stack[-1] = v0000;
/* end of prologue */
    v0038 = stack[-1];
    v0082 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v0082 = (*qfn2(fn))(qenv(fn), v0038, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-2];
    if (v0082 == nil) goto v0030;
    v0038 = stack[0];
    v0082 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v0082 = (*qfn2(fn))(qenv(fn), v0038, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    env = stack[-2];
    v0082 = (v0082 == nil ? lisp_true : nil);
    goto v0015;

v0015:
    if (v0082 == nil) goto v0100;
    v0082 = elt(env, 2); /* (1 . 1) */
    { popv(3); return onevalue(v0082); }

v0100:
    v0082 = stack[-1];
    v0038 = qcdr(v0082);
    v0082 = (Lisp_Object)17; /* 1 */
    if (v0038 == v0082) goto v0008;
    v0082 = qvalue(elt(env, 3)); /* nil */
    goto v0069;

v0069:
    if (v0082 == nil) goto v0469;
    v0082 = stack[-1];
    v0082 = qcar(v0082);
    v0082 = integerp(v0082);
    if (v0082 == nil) goto v0089;
    v0082 = stack[0];
    v0082 = qcar(v0082);
    v0082 = integerp(v0082);
    if (v0082 == nil) goto v0089;
    v0082 = stack[-1];
    v0038 = qcar(v0082);
    v0082 = stack[0];
    v0082 = qcar(v0082);
    v0038 = Lgcd(nil, v0038, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    v0082 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0038, v0082);

v0089:
    v0082 = stack[-1];
    v0038 = qcar(v0082);
    v0082 = stack[0];
    v0082 = qcar(v0082);
    fn = elt(env, 5); /* gcdf!* */
    v0038 = (*qfn2(fn))(qenv(fn), v0038, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0355;
    v0082 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0038, v0082);

v0469:
    v0038 = (Lisp_Object)17; /* 1 */
    v0082 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0038, v0082);

v0008:
    v0082 = stack[0];
    v0038 = qcdr(v0082);
    v0082 = (Lisp_Object)17; /* 1 */
    v0082 = (v0038 == v0082 ? lisp_true : nil);
    goto v0069;

v0030:
    v0082 = qvalue(elt(env, 1)); /* t */
    goto v0015;
/* error exit handlers */
v0355:
    popv(3);
    return nil;
}



/* Code for groebcplistsortin */

static Lisp_Object CC_groebcplistsortin(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0020;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebcplistsortin");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0016;
    v0020 = v0000;
/* end of prologue */
    v0019 = stack[0];
    if (v0019 == nil) goto v0029;
    v0019 = stack[0];
    fn = elt(env, 1); /* groebcplistsortin1 */
    v0019 = (*qfn2(fn))(qenv(fn), v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }

v0029:
    v0019 = v0020;
    popv(1);
    return ncons(v0019);
/* error exit handlers */
v0023:
    popv(1);
    return nil;
}



/* Code for termordp!! */

static Lisp_Object CC_termordpB(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0065, v0001, v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termordp!");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0016;
    v0053 = v0000;
/* end of prologue */
    v0001 = v0053;
    v0065 = stack[0];
    if (equal(v0001, v0065)) goto v0023;
    v0065 = v0053;
    fn = elt(env, 2); /* guesspftype */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0065 = stack[0];
    fn = elt(env, 2); /* guesspftype */
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    {
        Lisp_Object v0022 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* termordp */
        return (*qfn2(fn))(qenv(fn), v0022, v0065);
    }

v0023:
    v0065 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0065); }
/* error exit handlers */
v0024:
    popv(3);
    return nil;
}



/* Code for putd */

static Lisp_Object MS_CDECL CC_putd(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0016,
                         Lisp_Object v0066, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0350, v0351, v0335;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "putd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for putd");
#endif
    if (stack >= stacklimit)
    {
        push3(v0066,v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0016,v0066);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0066;
    stack[-1] = v0016;
    stack[-2] = v0000;
/* end of prologue */
    v0351 = stack[0];
    v0350 = elt(env, 1); /* funarg */
    if (!consp(v0351)) goto v0029;
    v0351 = qcar(v0351);
    if (!(v0351 == v0350)) goto v0029;
    v0351 = elt(env, 2); /* lambda */
    v0350 = stack[0];
    v0350 = qcdr(v0350);
    v0350 = qcdr(v0350);
    v0350 = cons(v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0504;
    env = stack[-3];
    stack[0] = v0350;
    goto v0029;

v0029:
    v0350 = stack[-2];
    if (!symbolp(v0350)) v0350 = nil;
    else { v0350 = qfastgets(v0350);
           if (v0350 != nil) { v0350 = elt(v0350, 1); /* lose */
#ifdef RECORD_GET
             if (v0350 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v0350 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v0350 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v0350 == SPID_NOPROP) v0350 = nil; else v0350 = lisp_true; }}
#endif
    if (v0350 == nil) goto v0069;
    v0350 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0504;
    env = stack[-3];
    v0350 = elt(env, 3); /* "+++ " */
    v0350 = Lprinc(nil, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0504;
    env = stack[-3];
    v0350 = stack[-2];
    v0350 = Lprin(nil, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0504;
    env = stack[-3];
    v0350 = elt(env, 4); /* " not defined (LOSE flag)" */
    v0350 = Lprintc(nil, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0504;
    env = stack[-3];
    v0350 = qvalue(elt(env, 5)); /* nil */
    { popv(4); return onevalue(v0350); }

v0069:
    v0350 = qvalue(elt(env, 6)); /* !*redefmsg */
    if (v0350 == nil) goto v0122;
    v0350 = stack[-2];
    fn = elt(env, 15); /* getd */
    v0350 = (*qfn1(fn))(qenv(fn), v0350);
    nil = C_nil;
    if (exception_pending()) goto v0504;
    env = stack[-3];
    if (v0350 == nil) goto v0122;
    v0350 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0504;
    env = stack[-3];
    v0350 = elt(env, 3); /* "+++ " */
    v0350 = Lprinc(nil, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0504;
    env = stack[-3];
    v0350 = stack[-2];
    v0350 = Lprin(nil, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0504;
    env = stack[-3];
    v0350 = elt(env, 7); /* " redefined" */
    v0350 = Lprintc(nil, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0504;
    env = stack[-3];
    goto v0122;

v0122:
    v0351 = stack[-1];
    v0350 = elt(env, 8); /* expr */
    if (v0351 == v0350) goto v0103;
    v0351 = stack[-1];
    v0350 = elt(env, 9); /* subr */
    if (v0351 == v0350) goto v0109;
    v0351 = stack[-1];
    v0350 = elt(env, 10); /* macro */
    if (v0351 == v0350) goto v0106;
    v0350 = qvalue(elt(env, 5)); /* nil */
    goto v0105;

v0105:
    if (v0350 == nil) goto v0056;
    v0335 = elt(env, 11); /* dm */
    v0351 = stack[-2];
    v0350 = stack[0];
    v0350 = qcdr(v0350);
    v0350 = list2star(v0335, v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0504;
    env = stack[-3];
    fn = elt(env, 16); /* eval */
    v0350 = (*qfn1(fn))(qenv(fn), v0350);
    nil = C_nil;
    if (exception_pending()) goto v0504;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v0056:
    v0351 = stack[-1];
    v0350 = elt(env, 12); /* fexpr */
    if (v0351 == v0350) goto v0062;
    v0350 = qvalue(elt(env, 5)); /* nil */
    goto v0113;

v0113:
    if (v0350 == nil) goto v0427;
    v0335 = elt(env, 13); /* df */
    v0351 = stack[-2];
    v0350 = stack[0];
    v0350 = qcdr(v0350);
    v0350 = list2star(v0335, v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0504;
    env = stack[-3];
    fn = elt(env, 16); /* eval */
    v0350 = (*qfn1(fn))(qenv(fn), v0350);
    nil = C_nil;
    if (exception_pending()) goto v0504;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v0427:
    v0351 = elt(env, 14); /* "Bad type ~S in putd" */
    v0350 = stack[-1];
    fn = elt(env, 17); /* error */
    v0350 = (*qfn2(fn))(qenv(fn), v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0504;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v0062:
    v0351 = stack[0];
    v0350 = elt(env, 2); /* lambda */
    v0350 = Leqcar(nil, v0351, v0350);
    env = stack[-3];
    goto v0113;

v0106:
    v0351 = stack[0];
    v0350 = elt(env, 2); /* lambda */
    v0350 = Leqcar(nil, v0351, v0350);
    env = stack[-3];
    goto v0105;

v0109:
    v0351 = stack[-2];
    v0350 = stack[0];
    v0350 = Lsymbol_set_definition(nil, v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0504;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v0103:
    v0351 = stack[-2];
    v0350 = stack[0];
    v0350 = Lsymbol_set_definition(nil, v0351, v0350);
    nil = C_nil;
    if (exception_pending()) goto v0504;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v0504:
    popv(4);
    return nil;
}



/* Code for setel */

static Lisp_Object CC_setel(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0016)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0123, v0480, v0103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setel");
#endif
    if (stack >= stacklimit)
    {
        push2(v0016,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0016);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0016;
    stack[-2] = v0000;
/* end of prologue */
    v0052 = stack[-2];
    v0123 = qcar(v0052);
    v0052 = elt(env, 1); /* dimension */
    v0052 = get(v0123, v0052);
    env = stack[-4];
    stack[-3] = v0052;
    v0052 = stack[-3];
    stack[0] = Llength(nil, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-4];
    v0052 = stack[-2];
    v0052 = qcdr(v0052);
    v0052 = Llength(nil, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-4];
    if (equal(stack[0], v0052)) goto v0124;
    v0052 = elt(env, 2); /* "Incorrect array reference" */
    v0123 = v0052;
    v0052 = v0123;
    qvalue(elt(env, 3)) = v0052; /* errmsg!* */
    v0052 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v0052 == nil)) goto v0022;
    v0052 = v0123;
    fn = elt(env, 6); /* lprie */
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-4];
    goto v0022;

v0022:
    v0052 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    v0052 = nil;
    { popv(5); return onevalue(v0052); }

v0124:
    v0052 = stack[-2];
    v0123 = qcar(v0052);
    v0052 = elt(env, 5); /* avalue */
    v0052 = get(v0123, v0052);
    env = stack[-4];
    v0052 = qcdr(v0052);
    v0103 = qcar(v0052);
    v0052 = stack[-2];
    v0480 = qcdr(v0052);
    v0123 = stack[-1];
    v0052 = stack[-3];
    {
        popv(5);
        fn = elt(env, 7); /* setel1 */
        return (*qfnn(fn))(qenv(fn), 4, v0103, v0480, v0123, v0052);
    }
/* error exit handlers */
v0110:
    popv(5);
    return nil;
}



/* Code for mv2sf1 */

static Lisp_Object MS_CDECL CC_mv2sf1(Lisp_Object env, int nargs,
                         Lisp_Object v0016, Lisp_Object v0066,
                         Lisp_Object v0080, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0126, v0127, v0122, v0094;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mv2sf1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv2sf1");
#endif
    if (stack >= stacklimit)
    {
        push3(v0080,v0066,v0016);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0016,v0066,v0080);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0126 = v0080;
    v0094 = v0066;
    v0122 = v0016;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* varlist */
    qvalue(elt(env, 1)) = nil; /* varlist */
    qvalue(elt(env, 1)) = v0126; /* varlist */
    goto v0015;

v0015:
    v0126 = v0122;
    if (v0126 == nil) goto v0032;
    v0126 = v0122;
    v0127 = qcar(v0126);
    v0126 = (Lisp_Object)1; /* 0 */
    if (v0127 == v0126) goto v0017;
    v0126 = qvalue(elt(env, 1)); /* varlist */
    stack[-1] = qcar(v0126);
    v0126 = v0122;
    stack[0] = qcar(v0126);
    v0126 = v0122;
    v0127 = qcdr(v0126);
    v0122 = v0094;
    v0126 = qvalue(elt(env, 1)); /* varlist */
    v0126 = qcdr(v0126);
    v0126 = CC_mv2sf1(env, 3, v0127, v0122, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-3];
    v0126 = acons(stack[-1], stack[0], v0126);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-3];
    v0126 = ncons(v0126);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-3];
    goto v0054;

v0054:
    qvalue(elt(env, 1)) = stack[-2]; /* varlist */
    { popv(4); return onevalue(v0126); }

v0017:
    v0126 = v0122;
    v0126 = qcdr(v0126);
    v0122 = v0126;
    v0126 = qvalue(elt(env, 1)); /* varlist */
    v0126 = qcdr(v0126);
    qvalue(elt(env, 1)) = v0126; /* varlist */
    goto v0015;

v0032:
    v0126 = v0094;
    goto v0054;
/* error exit handlers */
v0052:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* varlist */
    popv(4);
    return nil;
}



setup_type const u13_setup[] =
{
    {"guesspftype",             CC_guesspftype, too_many_1,    wrong_no_1},
    {"equalreplaceby",          CC_equalreplaceby,too_many_1,  wrong_no_1},
    {"inttovec",                too_few_2,      CC_inttovec,   wrong_no_2},
    {"assert_uninstall_all",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_uninstall_all},
    {"eqdummy",                 too_few_2,      CC_eqdummy,    wrong_no_2},
    {"numlist_ordp",            too_few_2,      CC_numlist_ordp,wrong_no_2},
    {"lambda_ls8o1j_2",         too_few_2,      CC_lambda_ls8o1j_2,wrong_no_2},
    {"extmult",                 too_few_2,      CC_extmult,    wrong_no_2},
    {"simp*sq",                 CC_simpHsq,     too_many_1,    wrong_no_1},
    {"mkzl",                    CC_mkzl,        too_many_1,    wrong_no_1},
    {"ibalp_clausep",           CC_ibalp_clausep,too_many_1,   wrong_no_1},
    {"aex_mvaroccurtest",       too_few_2,      CC_aex_mvaroccurtest,wrong_no_2},
    {"ofsf_sacatlp",            too_few_2,      CC_ofsf_sacatlp,wrong_no_2},
    {"cr:prep",                 CC_crTprep,     too_many_1,    wrong_no_1},
    {"initwght",                CC_initwght,    too_many_1,    wrong_no_1},
    {"bcplus?",                 CC_bcplusW,     too_many_1,    wrong_no_1},
    {"vevmaptozero1",           too_few_2,      CC_vevmaptozero1,wrong_no_2},
    {"physopaeval",             CC_physopaeval, too_many_1,    wrong_no_1},
    {"zero-roads",              CC_zeroKroads,  too_many_1,    wrong_no_1},
    {"assert_install",          CC_assert_install,too_many_1,  wrong_no_1},
    {"mo=revlexcomp",           too_few_2,      CC_moMrevlexcomp,wrong_no_2},
    {"dv_cambhead",             CC_dv_cambhead, too_many_1,    wrong_no_1},
    {"expt-mod-p",              too_few_2,      CC_exptKmodKp, wrong_no_2},
    {"get_group_in",            CC_get_group_in,too_many_1,    wrong_no_1},
    {"qqe_ofsf_simplat1",       too_few_2,      CC_qqe_ofsf_simplat1,wrong_no_2},
    {"rl_negateat",             CC_rl_negateat, too_many_1,    wrong_no_1},
    {"ibalp_redclause",         CC_ibalp_redclause,too_many_1, wrong_no_1},
    {"aex_simplenullp",         CC_aex_simplenullp,too_many_1, wrong_no_1},
    {"variablesir",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_variablesir},
    {"lid",                     CC_lid,         too_many_1,    wrong_no_1},
    {"invp",                    CC_invp,        too_many_1,    wrong_no_1},
    {"formcond1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_formcond1},
    {"mkarray1",                too_few_2,      CC_mkarray1,   wrong_no_2},
    {":divide",                 too_few_2,      CC_Tdivide,    wrong_no_2},
    {"gperm0",                  CC_gperm0,      too_many_1,    wrong_no_1},
    {"freeofl",                 too_few_2,      CC_freeofl,    wrong_no_2},
    {"xread1",                  CC_xread1,      too_many_1,    wrong_no_1},
    {"cl_atfp",                 CC_cl_atfp,     too_many_1,    wrong_no_1},
    {"ibalp_lenisone",          CC_ibalp_lenisone,too_many_1,  wrong_no_1},
    {"numpoly_nullp",           CC_numpoly_nullp,too_many_1,   wrong_no_1},
    {"inshisto",                CC_inshisto,    too_many_1,    wrong_no_1},
    {"evenfree",                CC_evenfree,    too_many_1,    wrong_no_1},
    {"revalind",                CC_revalind,    too_many_1,    wrong_no_1},
    {"all_defined_vertex",      too_few_2,      CC_all_defined_vertex,wrong_no_2},
    {"getmatelem",              CC_getmatelem,  too_many_1,    wrong_no_1},
    {"b:extadd",                too_few_2,      CC_bTextadd,   wrong_no_2},
    {"negate-term",             CC_negateKterm, too_many_1,    wrong_no_1},
    {"defineargs",              too_few_2,      CC_defineargs, wrong_no_2},
    {"ofsf_smmkatl",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smmkatl},
    {"qqe_simplat1",            too_few_2,      CC_qqe_simplat1,wrong_no_2},
    {"ibalp_hassimple",         CC_ibalp_hassimple,too_many_1, wrong_no_1},
    {"constsml",                CC_constsml,    too_many_1,    wrong_no_1},
    {"simprecip",               CC_simprecip,   too_many_1,    wrong_no_1},
    {"list-mgen",               CC_listKmgen,   too_many_1,    wrong_no_1},
    {"vbcgcd",                  too_few_2,      CC_vbcgcd,     wrong_no_2},
    {"groebcplistsortin",       too_few_2,      CC_groebcplistsortin,wrong_no_2},
    {"termordp!",               too_few_2,      CC_termordpB,  wrong_no_2},
    {"putd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_putd},
    {"setel",                   too_few_2,      CC_setel,      wrong_no_2},
    {"mv2sf1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mv2sf1},
    {NULL, (one_args *)"u13", (two_args *)"10772 5691036 2390222", 0}
};

/* end of generated code */
