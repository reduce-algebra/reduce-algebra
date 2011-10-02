
/* $destdir\u15.c        Machine generated C code */

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


/* Code for exptf */

static Lisp_Object CC_exptf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0015, v0016;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptf");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0015 = stack[0];
    v0014 = (Lisp_Object)1; /* 0 */
    v0014 = (Lisp_Object)lessp2(v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    v0014 = v0014 ? lisp_true : nil;
    env = stack[-2];
    if (v0014 == nil) goto v0018;
    v0016 = elt(env, 1); /* "exptf" */
    v0015 = stack[-1];
    v0014 = stack[0];
    v0014 = list3(v0016, v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* errach */
        return (*qfn1(fn))(qenv(fn), v0014);
    }

v0018:
    v0014 = stack[-1];
    if (!consp(v0014)) goto v0019;
    v0014 = stack[-1];
    v0014 = qcar(v0014);
    v0014 = (consp(v0014) ? nil : lisp_true);
    goto v0020;

v0020:
    if (v0014 == nil) goto v0021;
    v0015 = stack[-1];
    v0014 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* !:expt */
        return (*qfn2(fn))(qenv(fn), v0015, v0014);
    }

v0021:
    v0014 = qvalue(elt(env, 3)); /* !*exp */
    if (!(v0014 == nil)) goto v0022;
    v0014 = stack[-1];
    fn = elt(env, 6); /* kernlp */
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-2];
    if (!(v0014 == nil)) goto v0022;
    v0015 = stack[-1];
    v0014 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* mksfpf */
        return (*qfn2(fn))(qenv(fn), v0015, v0014);
    }

v0022:
    v0015 = stack[-1];
    v0014 = stack[0];
    {
        popv(3);
        fn = elt(env, 8); /* exptf1 */
        return (*qfn2(fn))(qenv(fn), v0015, v0014);
    }

v0019:
    v0014 = qvalue(elt(env, 2)); /* t */
    goto v0020;
/* error exit handlers */
v0017:
    popv(3);
    return nil;
}



/* Code for cl_susiupdknowl */

static Lisp_Object MS_CDECL CC_cl_susiupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0023, Lisp_Object v0024, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0034, v0035, v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_susiupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susiupdknowl");
#endif
    if (stack >= stacklimit)
    {
        push4(v0024,v0023,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0023,v0024);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0024;
    v0033 = v0023;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0037;

v0037:
    v0034 = stack[-1];
    if (v0034 == nil) goto v0038;
    v0034 = stack[-1];
    v0034 = qcar(v0034);
    stack[-3] = v0034;
    v0034 = stack[-1];
    v0034 = qcdr(v0034);
    stack[-1] = v0034;
    v0036 = stack[-2];
    v0035 = stack[-3];
    v0034 = v0033;
    v0033 = stack[0];
    fn = elt(env, 4); /* cl_susiupdknowl1 */
    v0033 = (*qfnn(fn))(qenv(fn), 4, v0036, v0035, v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-4];
    v0035 = v0033;
    v0034 = elt(env, 2); /* false */
    if (!(v0035 == v0034)) goto v0037;
    v0034 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v0034;
    v0034 = elt(env, 3); /* break */
    stack[-3] = v0034;
    goto v0037;

v0038:
    v0035 = stack[-3];
    v0034 = elt(env, 3); /* break */
    if (!(v0035 == v0034)) { popv(5); return onevalue(v0033); }
    v0033 = elt(env, 2); /* false */
    { popv(5); return onevalue(v0033); }
/* error exit handlers */
v0002:
    popv(5);
    return nil;
}



/* Code for tobvarir */

static Lisp_Object CC_tobvarir(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0019;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tobvarir");
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
    v0020 = stack[-1];
    if (v0020 == nil) goto v0027;
    stack[-2] = elt(env, 1); /* bvar */
    v0020 = stack[-1];
    v0019 = qcar(v0020);
    v0020 = (Lisp_Object)17; /* 1 */
    stack[0] = list2(v0019, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-3];
    v0020 = stack[-1];
    v0020 = qcdr(v0020);
    v0020 = CC_tobvarir(env, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    {
        Lisp_Object v0043 = stack[-2];
        Lisp_Object v0044 = stack[0];
        popv(4);
        return acons(v0043, v0044, v0020);
    }

v0027:
    v0020 = nil;
    { popv(4); return onevalue(v0020); }
/* error exit handlers */
v0042:
    popv(4);
    return nil;
}



/* Code for bc2a */

static Lisp_Object CC_bc2a(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0021;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0021 = v0000;
/* end of prologue */
    v0041 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (!(v0041 == nil)) return onevalue(v0021);
    v0041 = v0021;
    v0041 = qcar(v0041);
    if (v0041 == nil) goto v0045;
    v0041 = elt(env, 2); /* prepf */
    {
        fn = elt(env, 3); /* sqform */
        return (*qfn2(fn))(qenv(fn), v0021, v0041);
    }

v0045:
    v0041 = (Lisp_Object)1; /* 0 */
    return onevalue(v0041);
}



/* Code for listdiff */

static Lisp_Object CC_listdiff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008, v0020;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listdiff");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0008 = v0000;
/* end of prologue */

v0027:
    v0020 = stack[0];
    if (v0020 == nil) { popv(2); return onevalue(v0008); }
    v0020 = v0008;
    if (v0020 == nil) goto v0045;
    v0020 = stack[0];
    v0020 = qcar(v0020);
    v0008 = Ldelete(nil, v0020, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-1];
    v0020 = stack[0];
    v0020 = qcdr(v0020);
    stack[0] = v0020;
    goto v0027;

v0045:
    v0008 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0008); }
/* error exit handlers */
v0032:
    popv(2);
    return nil;
}



/* Code for inttovec1 */

static Lisp_Object CC_inttovec1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0022;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inttovec1");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0022 = stack[-1];
    v0048 = (Lisp_Object)17; /* 1 */
    if (v0022 == v0048) goto v0027;
    v0048 = stack[-1];
    v0022 = sub1(v0048);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-3];
    v0048 = stack[0];
    v0048 = qcdr(v0048);
    fn = elt(env, 1); /* inttovec!-solve */
    v0048 = (*qfn2(fn))(qenv(fn), v0022, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-3];
    stack[-2] = v0048;
    v0048 = stack[0];
    v0022 = qcar(v0048);
    v0048 = stack[-2];
    v0048 = qcar(v0048);
    stack[0] = difference2(v0022, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-3];
    v0048 = stack[-1];
    v0022 = sub1(v0048);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-3];
    v0048 = stack[-2];
    v0048 = CC_inttovec1(env, v0022, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    {
        Lisp_Object v0004 = stack[0];
        popv(4);
        return cons(v0004, v0048);
    }

v0027:
    v0048 = stack[0];
    v0048 = qcar(v0048);
    popv(4);
    return ncons(v0048);
/* error exit handlers */
v0049:
    popv(4);
    return nil;
}



/* Code for cstimes */

static Lisp_Object CC_cstimes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0004, v0005, v0033;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cstimes");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0004 = v0001;
    v0005 = v0000;
/* end of prologue */

v0018:
    v0049 = v0005;
    if (v0049 == nil) goto v0051;
    v0049 = v0005;
    v0033 = qcar(v0049);
    v0049 = (Lisp_Object)17; /* 1 */
    if (v0033 == v0049) goto v0031;
    v0049 = v0005;
    v0049 = qcdr(v0049);
    stack[0] = v0049;
    v0049 = v0005;
    v0049 = qcar(v0049);
    v0049 = cons(v0049, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    v0004 = v0049;
    v0049 = stack[0];
    v0005 = v0049;
    goto v0018;

v0031:
    v0049 = v0005;
    v0049 = qcdr(v0049);
    v0005 = v0049;
    goto v0018;

v0051:
    v0049 = v0004;
    if (v0049 == nil) goto v0013;
    v0049 = v0004;
    v0049 = qcdr(v0049);
    if (v0049 == nil) goto v0039;
    v0049 = elt(env, 1); /* times */
    popv(2);
    return cons(v0049, v0004);

v0039:
    v0049 = v0004;
    v0049 = qcar(v0049);
    { popv(2); return onevalue(v0049); }

v0013:
    v0049 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v0049); }
/* error exit handlers */
v0035:
    popv(2);
    return nil;
}



/* Code for repasc */

static Lisp_Object MS_CDECL CC_repasc(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0023, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0060, v0061, v0062;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "repasc");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repasc");
#endif
    if (stack >= stacklimit)
    {
        push3(v0023,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0023);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0023;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0062 = nil;
    goto v0063;

v0063:
    v0060 = stack[0];
    if (v0060 == nil) goto v0013;
    v0061 = stack[-2];
    v0060 = stack[0];
    v0060 = qcar(v0060);
    v0060 = qcar(v0060);
    if (equal(v0061, v0060)) goto v0048;
    v0060 = stack[0];
    v0060 = qcar(v0060);
    v0061 = v0062;
    v0060 = cons(v0060, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    v0062 = v0060;
    v0060 = stack[0];
    v0060 = qcdr(v0060);
    stack[0] = v0060;
    goto v0063;

v0048:
    stack[-3] = v0062;
    v0062 = stack[-2];
    v0061 = stack[-1];
    v0060 = stack[0];
    v0060 = qcdr(v0060);
    v0060 = acons(v0062, v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    {
        Lisp_Object v0065 = stack[-3];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0065, v0060);
    }

v0013:
    stack[0] = v0062;
    v0062 = elt(env, 1); /* "key" */
    v0061 = stack[-2];
    v0060 = elt(env, 2); /* "not found" */
    v0060 = list3(v0062, v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    v0061 = v0060;
    v0060 = v0061;
    qvalue(elt(env, 3)) = v0060; /* errmsg!* */
    v0060 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v0060 == nil)) goto v0043;
    v0060 = v0061;
    fn = elt(env, 6); /* lprie */
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    goto v0043;

v0043:
    v0060 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    v0060 = nil;
    {
        Lisp_Object v0066 = stack[0];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0066, v0060);
    }
/* error exit handlers */
v0064:
    popv(5);
    return nil;
}



/* Code for formsetq */

static Lisp_Object MS_CDECL CC_formsetq(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0023, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071, v0060, v0061, v0062, v0072;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formsetq");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formsetq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0061 = v0023;
    v0062 = v0001;
    v0072 = v0000;
/* end of prologue */
    v0060 = v0061;
    v0071 = elt(env, 1); /* symbolic */
    if (v0060 == v0071) goto v0008;
    v0071 = v0072;
    v0060 = v0062;
    {
        fn = elt(env, 4); /* formsetq0 */
        return (*qfnn(fn))(qenv(fn), 3, v0071, v0060, v0061);
    }

v0008:
    v0071 = v0072;
    v0071 = qcdr(v0071);
    v0060 = qcar(v0071);
    v0071 = elt(env, 2); /* list */
    if (!consp(v0060)) goto v0038;
    v0060 = qcar(v0060);
    if (!(v0060 == v0071)) goto v0038;
    v0071 = v0072;
    v0060 = v0062;
    {
        fn = elt(env, 5); /* formsetq1 */
        return (*qfnn(fn))(qenv(fn), 3, v0071, v0060, v0061);
    }

v0038:
    v0071 = v0072;
    v0071 = qcdr(v0071);
    v0060 = qcar(v0071);
    v0071 = elt(env, 3); /* cons */
    if (!consp(v0060)) goto v0016;
    v0060 = qcar(v0060);
    if (!(v0060 == v0071)) goto v0016;
    v0071 = v0072;
    v0060 = v0062;
    {
        fn = elt(env, 6); /* formsetq2 */
        return (*qfnn(fn))(qenv(fn), 3, v0071, v0060, v0061);
    }

v0016:
    v0071 = v0072;
    v0060 = v0062;
    {
        fn = elt(env, 4); /* formsetq0 */
        return (*qfnn(fn))(qenv(fn), 3, v0071, v0060, v0061);
    }
}



/* Code for th_match */

static Lisp_Object CC_th_match(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for th_match");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0042 = stack[-1];
    v0031 = stack[0];
    fn = elt(env, 2); /* th_match0 */
    v0031 = (*qfn2(fn))(qenv(fn), v0042, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-2];
    if (v0031 == nil) goto v0027;
    v0031 = stack[-1];
    v0031 = qcdr(v0031);
    v0031 = qcar(v0031);
    fn = elt(env, 3); /* dl_get */
    v0031 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-2];
    stack[-1] = Llength(nil, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-2];
    v0031 = stack[0];
    v0031 = qcdr(v0031);
    v0031 = qcar(v0031);
    fn = elt(env, 3); /* dl_get */
    v0031 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-2];
    v0031 = Llength(nil, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    v0031 = (equal(stack[-1], v0031) ? lisp_true : nil);
    { popv(3); return onevalue(v0031); }

v0027:
    v0031 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0031); }
/* error exit handlers */
v0073:
    popv(3);
    return nil;
}



/* Code for general!-expt!-mod!-p */

static Lisp_Object CC_generalKexptKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076, v0017, v0077;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-expt-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0077 = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0017 = v0077;
    v0076 = (Lisp_Object)1; /* 0 */
    if (v0017 == v0076) goto v0027;
    v0017 = v0077;
    v0076 = (Lisp_Object)17; /* 1 */
    if (v0017 == v0076) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0017 = v0077;
    v0076 = (Lisp_Object)33; /* 2 */
    v0076 = Ldivide(nil, v0017, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    stack[-1] = v0076;
    v0017 = stack[0];
    v0076 = stack[-1];
    v0076 = qcar(v0076);
    v0076 = CC_generalKexptKmodKp(env, v0017, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    v0077 = v0076;
    v0076 = v0077;
    v0017 = v0077;
    fn = elt(env, 1); /* general!-times!-mod!-p */
    v0076 = (*qfn2(fn))(qenv(fn), v0076, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    v0077 = v0076;
    v0076 = stack[-1];
    v0017 = qcdr(v0076);
    v0076 = (Lisp_Object)1; /* 0 */
    if (v0017 == v0076) { popv(3); return onevalue(v0077); }
    v0017 = v0077;
    v0076 = stack[0];
    fn = elt(env, 1); /* general!-times!-mod!-p */
    v0076 = (*qfn2(fn))(qenv(fn), v0017, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    v0077 = v0076;
    { popv(3); return onevalue(v0077); }

v0027:
    v0076 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0076); }
/* error exit handlers */
v0052:
    popv(3);
    return nil;
}



/* Code for simpqg */

static Lisp_Object CC_simpqg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0079;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpqg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0037 = v0000;
/* end of prologue */
    v0079 = v0037;
    v0037 = elt(env, 1); /* qg */
    {
        fn = elt(env, 2); /* simpcv */
        return (*qfn2(fn))(qenv(fn), v0079, v0037);
    }
}



/* Code for revalx */

static Lisp_Object CC_revalx(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011, v0009;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for revalx");
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
    v0009 = v0000;
/* end of prologue */
    v0011 = v0009;
    if (!consp(v0011)) goto v0080;
    v0011 = v0009;
    v0011 = qcar(v0011);
    v0011 = (consp(v0011) ? nil : lisp_true);
    v0011 = (v0011 == nil ? lisp_true : nil);
    goto v0078;

v0078:
    if (v0011 == nil) goto v0081;
    v0011 = v0009;
    fn = elt(env, 2); /* prepf */
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[0];
    goto v0054;

v0054:
    {
        popv(1);
        fn = elt(env, 3); /* reval */
        return (*qfn1(fn))(qenv(fn), v0011);
    }

v0081:
    v0011 = v0009;
    goto v0054;

v0080:
    v0011 = qvalue(elt(env, 1)); /* nil */
    goto v0078;
/* error exit handlers */
v0010:
    popv(1);
    return nil;
}



/* Code for setunion */

static Lisp_Object CC_setunion(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0083, v0084, v0085;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setunion");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0084 = v0000;
/* end of prologue */

v0027:
    v0083 = stack[0];
    if (v0083 == nil) { popv(3); return onevalue(v0084); }
    v0083 = stack[0];
    v0085 = qcar(v0083);
    v0083 = v0084;
    v0083 = Lmember(nil, v0085, v0083);
    if (v0083 == nil) goto v0021;
    v0083 = stack[0];
    v0083 = qcdr(v0083);
    stack[0] = v0083;
    goto v0027;

v0021:
    stack[-1] = v0084;
    v0083 = stack[0];
    v0083 = qcar(v0083);
    v0083 = ncons(v0083);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    v0083 = Lappend(nil, stack[-1], v0083);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    v0084 = v0083;
    v0083 = stack[0];
    v0083 = qcdr(v0083);
    stack[0] = v0083;
    goto v0027;
/* error exit handlers */
v0029:
    popv(3);
    return nil;
}



/* Code for vdp_zero!? */

static Lisp_Object CC_vdp_zeroW(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0027;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_zero?");
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
    v0027 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* vdp_poly */
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    errexit();
    v0027 = (v0027 == nil ? lisp_true : nil);
    return onevalue(v0027);
}



/* Code for vdpred */

static Lisp_Object CC_vdpred(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0062, v0072;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpred");
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
    v0062 = stack[-3];
    v0062 = qcdr(v0062);
    v0062 = qcdr(v0062);
    v0062 = qcdr(v0062);
    v0062 = qcar(v0062);
    v0062 = qcdr(v0062);
    v0062 = qcdr(v0062);
    stack[-4] = v0062;
    v0062 = stack[-4];
    if (v0062 == nil) goto v0059;
    stack[-2] = elt(env, 1); /* vdp */
    v0062 = stack[-4];
    stack[-1] = qcar(v0062);
    v0062 = stack[-4];
    v0062 = qcdr(v0062);
    stack[0] = qcar(v0062);
    v0072 = stack[-4];
    v0062 = qvalue(elt(env, 2)); /* nil */
    v0062 = list2(v0072, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-5];
    v0062 = list3star(stack[-2], stack[-1], stack[0], v0062);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-5];
    stack[-4] = v0062;
    v0062 = qvalue(elt(env, 3)); /* !*gsugar */
    if (v0062 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v0072 = stack[-3];
    v0062 = elt(env, 4); /* sugar */
    fn = elt(env, 5); /* vdpgetprop */
    v0072 = (*qfn2(fn))(qenv(fn), v0072, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-5];
    v0062 = v0072;
    if (v0072 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v0072 = stack[-4];
    fn = elt(env, 6); /* gsetsugar */
    v0062 = (*qfn2(fn))(qenv(fn), v0072, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }

v0059:
    stack[-2] = elt(env, 1); /* vdp */
    stack[-1] = qvalue(elt(env, 2)); /* nil */
    v0062 = qvalue(elt(env, 2)); /* nil */
    stack[0] = ncons(v0062);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-5];
    v0072 = qvalue(elt(env, 2)); /* nil */
    v0062 = qvalue(elt(env, 2)); /* nil */
    v0062 = list2(v0072, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    {
        Lisp_Object v0086 = stack[-2];
        Lisp_Object v0087 = stack[-1];
        Lisp_Object v0088 = stack[0];
        popv(6);
        return list3star(v0086, v0087, v0088, v0062);
    }
/* error exit handlers */
v0066:
    popv(6);
    return nil;
}



/* Code for freeoffl */

static Lisp_Object CC_freeoffl(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0044;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeoffl");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0089:
    v0043 = stack[0];
    if (v0043 == nil) goto v0027;
    v0044 = stack[-1];
    v0043 = stack[0];
    v0043 = qcar(v0043);
    fn = elt(env, 3); /* freeoff */
    v0043 = (*qfn2(fn))(qenv(fn), v0044, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    if (v0043 == nil) goto v0012;
    v0044 = stack[-1];
    v0043 = stack[0];
    v0043 = qcdr(v0043);
    stack[-1] = v0044;
    stack[0] = v0043;
    goto v0089;

v0012:
    v0043 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0043); }

v0027:
    v0043 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0043); }
/* error exit handlers */
v0084:
    popv(3);
    return nil;
}



/* Code for triviallcm */

static Lisp_Object MS_CDECL CC_triviallcm(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0023, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "triviallcm");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for triviallcm");
#endif
    if (stack >= stacklimit)
    {
        push3(v0023,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0023);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0023;
    v0082 = v0001;
    v0059 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* xdiv */
    v0082 = (*qfn2(fn))(qenv(fn), v0082, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    v0059 = stack[0];
    v0059 = (equal(v0082, v0059) ? lisp_true : nil);
    { popv(1); return onevalue(v0059); }
/* error exit handlers */
v0075:
    popv(1);
    return nil;
}



/* Code for listeval */

static Lisp_Object CC_listeval(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0113, v0114, v0115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listeval");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0113 = qvalue(elt(env, 1)); /* simpcount!* */
    v0114 = add1(v0113);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-6];
    qvalue(elt(env, 1)) = v0114; /* simpcount!* */
    v0113 = qvalue(elt(env, 2)); /* simplimit!* */
    v0113 = (Lisp_Object)greaterp2(v0114, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    v0113 = v0113 ? lisp_true : nil;
    env = stack[-6];
    if (v0113 == nil) goto v0054;
    v0113 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v0113; /* simpcount!* */
    v0113 = elt(env, 3); /* "Simplification recursion too deep" */
    v0114 = v0113;
    v0113 = v0114;
    qvalue(elt(env, 4)) = v0113; /* errmsg!* */
    v0113 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v0113 == nil)) goto v0070;
    v0113 = v0114;
    fn = elt(env, 12); /* lprie */
    v0113 = (*qfn1(fn))(qenv(fn), v0113);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-6];
    goto v0070;

v0070:
    v0113 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-6];
    goto v0054;

v0054:
    v0113 = stack[0];
    if (!consp(v0113)) goto v0043;
    v0113 = stack[0];
    v0114 = qcar(v0113);
    v0113 = elt(env, 8); /* list */
    if (v0114 == v0113) goto v0117;
    v0113 = stack[0];
    v0114 = qcar(v0113);
    v0113 = elt(env, 10); /* listfn */
    v0113 = get(v0114, v0113);
    env = stack[-6];
    v0114 = v0113;
    v0113 = v0114;
    if (v0113 == nil) goto v0118;
    v0115 = v0114;
    v0113 = stack[0];
    v0114 = qcdr(v0113);
    v0113 = stack[-4];
    v0113 = Lapply2(nil, 3, v0115, v0114, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-6];
    goto v0019;

v0019:
    stack[0] = v0113;
    v0113 = qvalue(elt(env, 1)); /* simpcount!* */
    v0113 = sub1(v0113);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-6];
    qvalue(elt(env, 1)) = v0113; /* simpcount!* */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v0118:
    v0113 = elt(env, 11); /* "Illegal operation on lists" */
    v0114 = v0113;
    v0113 = v0114;
    qvalue(elt(env, 4)) = v0113; /* errmsg!* */
    v0113 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v0113 == nil)) goto v0119;
    v0113 = v0114;
    fn = elt(env, 12); /* lprie */
    v0113 = (*qfn1(fn))(qenv(fn), v0113);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-6];
    goto v0119;

v0119:
    v0113 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-6];
    v0113 = nil;
    goto v0019;

v0117:
    stack[-5] = elt(env, 8); /* list */
    v0113 = stack[0];
    v0113 = qcdr(v0113);
    stack[-3] = v0113;
    v0113 = stack[-3];
    if (v0113 == nil) goto v0120;
    v0113 = stack[-3];
    v0113 = qcar(v0113);
    v0114 = v0113;
    v0113 = stack[-4];
    fn = elt(env, 13); /* reval1 */
    v0113 = (*qfn2(fn))(qenv(fn), v0114, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-6];
    v0113 = ncons(v0113);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-6];
    stack[-1] = v0113;
    stack[-2] = v0113;
    goto v0121;

v0121:
    v0113 = stack[-3];
    v0113 = qcdr(v0113);
    stack[-3] = v0113;
    v0113 = stack[-3];
    if (v0113 == nil) goto v0122;
    stack[0] = stack[-1];
    v0113 = stack[-3];
    v0113 = qcar(v0113);
    v0114 = v0113;
    v0113 = stack[-4];
    fn = elt(env, 13); /* reval1 */
    v0113 = (*qfn2(fn))(qenv(fn), v0114, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-6];
    v0113 = ncons(v0113);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-6];
    v0113 = Lrplacd(nil, stack[0], v0113);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-6];
    v0113 = stack[-1];
    v0113 = qcdr(v0113);
    stack[-1] = v0113;
    goto v0121;

v0122:
    v0113 = stack[-2];
    goto v0066;

v0066:
    v0113 = cons(stack[-5], v0113);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-6];
    goto v0019;

v0120:
    v0113 = qvalue(elt(env, 9)); /* nil */
    goto v0066;

v0043:
    v0114 = stack[0];
    v0113 = elt(env, 6); /* avalue */
    v0113 = get(v0114, v0113);
    env = stack[-6];
    v0115 = v0113;
    v0114 = stack[0];
    v0113 = elt(env, 7); /* share */
    v0113 = Lflagp(nil, v0114, v0113);
    env = stack[-6];
    if (v0113 == nil) goto v0058;
    v0113 = stack[0];
    fn = elt(env, 14); /* eval */
    v0113 = (*qfn1(fn))(qenv(fn), v0113);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-6];
    v0114 = v0113;
    goto v0007;

v0007:
    v0113 = stack[-4];
    v0113 = CC_listeval(env, v0114, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-6];
    goto v0019;

v0058:
    v0113 = v0115;
    if (v0113 == nil) goto v0014;
    v0113 = v0115;
    v0113 = qcdr(v0113);
    v0113 = qcar(v0113);
    v0114 = v0113;
    goto v0007;

v0014:
    v0114 = stack[0];
    v0113 = elt(env, 8); /* list */
    fn = elt(env, 15); /* typerr */
    v0113 = (*qfn2(fn))(qenv(fn), v0114, v0113);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-6];
    v0114 = v0113;
    goto v0007;
/* error exit handlers */
v0116:
    popv(7);
    return nil;
}



/* Code for indord2 */

static Lisp_Object CC_indord2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indord2");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0031 = stack[-1];
    v0030 = stack[0];
    fn = elt(env, 1); /* indordp */
    v0030 = (*qfn2(fn))(qenv(fn), v0031, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    if (v0030 == nil) goto v0010;
    v0031 = stack[-1];
    v0030 = stack[0];
    popv(2);
    return list2(v0031, v0030);

v0010:
    v0031 = stack[0];
    v0030 = stack[-1];
    popv(2);
    return list2(v0031, v0030);
/* error exit handlers */
v0044:
    popv(2);
    return nil;
}



/* Code for my_freeof */

static Lisp_Object CC_my_freeof(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008, v0020, v0019;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for my_freeof");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0020 = stack[0];
    v0008 = stack[-1];
    fn = elt(env, 3); /* smember */
    v0008 = (*qfn2(fn))(qenv(fn), v0020, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-2];
    if (v0008 == nil) goto v0080;
    v0008 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0008); }

v0080:
    v0019 = qvalue(elt(env, 1)); /* depl!* */
    v0020 = stack[-1];
    v0008 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* freeofdepl */
        return (*qfnn(fn))(qenv(fn), 3, v0019, v0020, v0008);
    }
/* error exit handlers */
v0031:
    popv(3);
    return nil;
}



/* Code for map__edges */

static Lisp_Object CC_map__edges(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0029;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for map__edges");
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
    goto v0018;

v0018:
    v0047 = stack[0];
    if (v0047 == nil) goto v0063;
    v0047 = stack[0];
    v0029 = qcar(v0047);
    v0047 = stack[-1];
    v0047 = cons(v0029, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-2];
    stack[-1] = v0047;
    v0047 = stack[0];
    v0047 = qcdr(v0047);
    stack[0] = v0047;
    goto v0018;

v0063:
    v0047 = qvalue(elt(env, 1)); /* nil */
    v0029 = v0047;
    goto v0078;

v0078:
    v0047 = stack[-1];
    if (v0047 == nil) { popv(3); return onevalue(v0029); }
    v0047 = stack[-1];
    v0047 = qcar(v0047);
    fn = elt(env, 2); /* union_edges */
    v0047 = (*qfn2(fn))(qenv(fn), v0047, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-2];
    v0029 = v0047;
    v0047 = stack[-1];
    v0047 = qcdr(v0047);
    stack[-1] = v0047;
    goto v0078;
/* error exit handlers */
v0007:
    popv(3);
    return nil;
}



/* Code for sfpx1 */

static Lisp_Object MS_CDECL CC_sfpx1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0023, Lisp_Object v0024,
                         Lisp_Object v0054, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0148, v0149, v0150, v0151, v0152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "sfpx1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfpx1");
#endif
    if (stack >= stacklimit)
    {
        push5(v0054,v0024,v0023,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0001,v0023,v0024,v0054);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0054;
    stack[-4] = v0024;
    stack[-5] = v0023;
    stack[-6] = v0001;
    v0151 = v0000;
/* end of prologue */

v0089:
    v0148 = v0151;
    if (!consp(v0148)) goto v0081;
    v0148 = v0151;
    v0148 = qcar(v0148);
    v0148 = (consp(v0148) ? nil : lisp_true);
    goto v0082;

v0082:
    if (v0148 == nil) goto v0080;
    v0148 = qvalue(elt(env, 1)); /* t */
    { popv(9); return onevalue(v0148); }

v0080:
    v0148 = v0151;
    v0148 = Lconsp(nil, v0148);
    env = stack[-8];
    if (v0148 == nil) goto v0030;
    v0148 = v0151;
    v0148 = qcar(v0148);
    v0149 = v0151;
    v0149 = qcdr(v0149);
    stack[-2] = v0149;
    v0149 = v0148;
    v0149 = Lconsp(nil, v0149);
    env = stack[-8];
    if (v0149 == nil) goto v0029;
    v0149 = v0148;
    v0149 = qcdr(v0149);
    stack[-7] = v0149;
    v0148 = qcar(v0148);
    stack[0] = v0148;
    v0148 = stack[0];
    v0148 = Lconsp(nil, v0148);
    env = stack[-8];
    if (v0148 == nil) goto v0048;
    v0148 = stack[0];
    v0148 = qcar(v0148);
    stack[-1] = v0148;
    v0148 = stack[-1];
    fn = elt(env, 3); /* assert_kernelp */
    v0148 = (*qfn1(fn))(qenv(fn), v0148);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-8];
    if (v0148 == nil) goto v0034;
    v0148 = stack[0];
    v0148 = qcdr(v0148);
    stack[0] = v0148;
    v0149 = stack[-1];
    v0148 = stack[-5];
    if (v0149 == v0148) goto v0061;
    v0148 = stack[-5];
    if (v0148 == nil) goto v0154;
    v0149 = stack[-5];
    v0148 = stack[-6];
    v0148 = cons(v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-8];
    stack[-6] = v0148;
    goto v0154;

v0154:
    v0148 = stack[-3];
    if (v0148 == nil) goto v0155;
    v0148 = stack[-6];
    if (v0148 == nil) goto v0155;
    v0149 = stack[-1];
    v0148 = (Lisp_Object)17; /* 1 */
    stack[-4] = cons(v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-8];
    v0148 = stack[-6];
    v0149 = qcar(v0148);
    v0148 = (Lisp_Object)17; /* 1 */
    v0148 = cons(v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-8];
    fn = elt(env, 4); /* ordpp */
    v0148 = (*qfn2(fn))(qenv(fn), stack[-4], v0148);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-8];
    if (v0148 == nil) goto v0155;
    v0148 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0148); }

v0155:
    stack[-4] = stack[-7];
    v0149 = stack[-1];
    v0148 = stack[-6];
    v0151 = cons(v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-8];
    v0150 = qvalue(elt(env, 2)); /* nil */
    v0149 = (Lisp_Object)1; /* 0 */
    v0148 = stack[-3];
    v0148 = CC_sfpx1(env, 5, stack[-4], v0151, v0150, v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-8];
    if (v0148 == nil) goto v0156;
    v0151 = stack[-2];
    v0152 = stack[-6];
    v0150 = stack[-1];
    v0149 = stack[0];
    v0148 = stack[-3];
    stack[-6] = v0152;
    stack[-5] = v0150;
    stack[-4] = v0149;
    stack[-3] = v0148;
    goto v0089;

v0156:
    v0148 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0148); }

v0061:
    v0149 = stack[0];
    v0148 = stack[-4];
    v0148 = (Lisp_Object)lessp2(v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    v0148 = v0148 ? lisp_true : nil;
    env = stack[-8];
    if (v0148 == nil) goto v0067;
    stack[-1] = stack[-7];
    v0149 = stack[-5];
    v0148 = stack[-6];
    v0151 = cons(v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-8];
    v0150 = qvalue(elt(env, 2)); /* nil */
    v0149 = (Lisp_Object)1; /* 0 */
    v0148 = stack[-3];
    v0148 = CC_sfpx1(env, 5, stack[-1], v0151, v0150, v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-8];
    if (v0148 == nil) goto v0107;
    v0151 = stack[-2];
    v0152 = stack[-6];
    v0150 = stack[-5];
    v0149 = stack[0];
    v0148 = stack[-3];
    stack[-6] = v0152;
    stack[-5] = v0150;
    stack[-4] = v0149;
    stack[-3] = v0148;
    goto v0089;

v0107:
    v0148 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0148); }

v0067:
    v0148 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0148); }

v0034:
    v0148 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0148); }

v0048:
    v0148 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0148); }

v0029:
    v0148 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0148); }

v0030:
    v0148 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0148); }

v0081:
    v0148 = qvalue(elt(env, 1)); /* t */
    goto v0082;
/* error exit handlers */
v0153:
    popv(9);
    return nil;
}



/* Code for mo_neworder */

static Lisp_Object CC_mo_neworder(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_neworder");
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
    v0090 = v0000;
/* end of prologue */
    v0090 = qcar(v0090);
    fn = elt(env, 1); /* mo!=shorten */
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-1];
    stack[0] = v0090;
    fn = elt(env, 2); /* mo!=deglist */
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    {
        Lisp_Object v0039 = stack[0];
        popv(2);
        return cons(v0039, v0090);
    }
/* error exit handlers */
v0040:
    popv(2);
    return nil;
}



/* Code for pv_times1 */

static Lisp_Object MS_CDECL CC_pv_times1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0023, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0032, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pv_times1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_times1");
#endif
    if (stack >= stacklimit)
    {
        push3(v0023,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0023);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0032 = v0023;
    stack[0] = v0001;
    v0019 = v0000;
/* end of prologue */

v0063:
    v0030 = v0019;
    if (v0030 == nil) { popv(3); return onevalue(v0032); }
    v0030 = v0019;
    v0030 = qcdr(v0030);
    stack[-1] = v0030;
    v0030 = qcar(v0019);
    v0019 = stack[0];
    fn = elt(env, 1); /* pv_times2 */
    v0019 = (*qfnn(fn))(qenv(fn), 3, v0030, v0019, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    v0032 = v0019;
    v0019 = stack[-1];
    goto v0063;
/* error exit handlers */
v0043:
    popv(3);
    return nil;
}



/* Code for rootrnd */

static Lisp_Object CC_rootrnd(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0079;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rootrnd");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0037 = v0000;
/* end of prologue */
    v0079 = v0037;
    v0037 = qvalue(elt(env, 1)); /* acc!# */
    {
        fn = elt(env, 2); /* rtrnda */
        return (*qfn2(fn))(qenv(fn), v0079, v0037);
    }
}



/* Code for quotient!-mod!-p */

static Lisp_Object CC_quotientKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0147, v0145, v0105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotient-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0147 = stack[-1];
    if (v0147 == nil) goto v0027;
    v0147 = stack[-1];
    if (!consp(v0147)) goto v0013;
    v0147 = stack[-1];
    v0147 = qcar(v0147);
    v0147 = (consp(v0147) ? nil : lisp_true);
    goto v0012;

v0012:
    if (v0147 == nil) goto v0079;
    v0147 = stack[-1];
    fn = elt(env, 5); /* safe!-modular!-reciprocal */
    v0147 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-4];
    v0145 = stack[-1];
    if (v0145 == nil) goto v0020;
    v0145 = stack[-2];
    {
        popv(5);
        fn = elt(env, 6); /* multiply!-by!-constant!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0145, v0147);
    }

v0020:
    v0147 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v0147; /* exact!-quotient!-flag */
    { popv(5); return onevalue(v0147); }

v0079:
    v0147 = stack[-2];
    if (v0147 == nil) goto v0029;
    v0147 = stack[-2];
    if (!consp(v0147)) goto v0038;
    v0147 = stack[-2];
    v0147 = qcar(v0147);
    v0147 = (consp(v0147) ? nil : lisp_true);
    goto v0167;

v0167:
    if (v0147 == nil) goto v0034;
    v0147 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v0147; /* exact!-quotient!-flag */
    { popv(5); return onevalue(v0147); }

v0034:
    v0147 = stack[-2];
    v0147 = qcar(v0147);
    v0147 = qcar(v0147);
    v0145 = qcar(v0147);
    v0147 = stack[-1];
    v0147 = qcar(v0147);
    v0147 = qcar(v0147);
    v0147 = qcar(v0147);
    if (equal(v0145, v0147)) goto v0017;
    v0147 = stack[-2];
    v0147 = qcar(v0147);
    v0147 = qcar(v0147);
    v0145 = qcar(v0147);
    v0147 = stack[-1];
    v0147 = qcar(v0147);
    v0147 = qcar(v0147);
    v0147 = qcar(v0147);
    fn = elt(env, 7); /* ordop */
    v0147 = (*qfn2(fn))(qenv(fn), v0145, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-4];
    if (v0147 == nil) goto v0168;
    v0147 = stack[-2];
    v0147 = qcar(v0147);
    stack[-3] = qcar(v0147);
    v0147 = stack[-2];
    v0147 = qcar(v0147);
    v0145 = qcdr(v0147);
    v0147 = stack[-1];
    stack[0] = CC_quotientKmodKp(env, v0145, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-4];
    v0147 = stack[-2];
    v0145 = qcdr(v0147);
    v0147 = stack[-1];
    v0147 = CC_quotientKmodKp(env, v0145, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-4];
    {
        Lisp_Object v0169 = stack[-3];
        Lisp_Object v0103 = stack[0];
        popv(5);
        fn = elt(env, 8); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0169, v0103, v0147);
    }

v0168:
    v0147 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v0147; /* exact!-quotient!-flag */
    { popv(5); return onevalue(v0147); }

v0017:
    v0105 = stack[-2];
    v0145 = stack[-1];
    v0147 = stack[-1];
    v0147 = qcar(v0147);
    v0147 = qcar(v0147);
    v0147 = qcar(v0147);
    {
        popv(5);
        fn = elt(env, 9); /* xquotient!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 3, v0105, v0145, v0147);
    }

v0038:
    v0147 = qvalue(elt(env, 2)); /* t */
    goto v0167;

v0029:
    v0147 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v0147); }

v0013:
    v0147 = qvalue(elt(env, 2)); /* t */
    goto v0012;

v0027:
    v0147 = elt(env, 1); /* "B=0 IN QUOTIENT-MOD-P" */
    {
        popv(5);
        fn = elt(env, 10); /* errorf */
        return (*qfn1(fn))(qenv(fn), v0147);
    }
/* error exit handlers */
v0166:
    popv(5);
    return nil;
}



/* Code for rlis */

static Lisp_Object MS_CDECL CC_rlis(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0064, v0065, v0066;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rlis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rlis");
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
    v0064 = qvalue(elt(env, 1)); /* cursym!* */
    stack[0] = v0064;
    fn = elt(env, 8); /* scan */
    v0065 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    v0064 = elt(env, 2); /* delim */
    v0064 = Lflagp(nil, v0065, v0064);
    env = stack[-2];
    if (v0064 == nil) goto v0078;
    v0064 = stack[0];
    v0065 = qvalue(elt(env, 3)); /* nil */
    popv(3);
    return list2(v0064, v0065);

v0078:
    v0064 = qvalue(elt(env, 4)); /* !*reduce4 */
    if (v0064 == nil) goto v0170;
    stack[-1] = stack[0];
    stack[0] = elt(env, 5); /* list */
    v0064 = elt(env, 6); /* lambda */
    fn = elt(env, 9); /* xread1 */
    v0064 = (*qfn1(fn))(qenv(fn), v0064);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    v0066 = v0064;
    v0065 = v0066;
    v0064 = elt(env, 7); /* !*comma!* */
    if (!consp(v0065)) goto v0068;
    v0065 = qcar(v0065);
    if (!(v0065 == v0064)) goto v0068;
    v0064 = v0066;
    v0064 = qcdr(v0064);
    goto v0083;

v0083:
    v0064 = cons(stack[0], v0064);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    {
        Lisp_Object v0107 = stack[-1];
        popv(3);
        return list2(v0107, v0064);
    }

v0068:
    v0064 = v0066;
    v0064 = ncons(v0064);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    goto v0083;

v0170:
    v0064 = elt(env, 6); /* lambda */
    fn = elt(env, 9); /* xread1 */
    v0064 = (*qfn1(fn))(qenv(fn), v0064);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    v0066 = v0064;
    v0065 = v0066;
    v0064 = elt(env, 7); /* !*comma!* */
    if (!consp(v0065)) goto v0072;
    v0065 = qcar(v0065);
    if (!(v0065 == v0064)) goto v0072;
    v0064 = v0066;
    v0064 = qcdr(v0064);
    goto v0056;

v0056:
    {
        Lisp_Object v0106 = stack[0];
        popv(3);
        return cons(v0106, v0064);
    }

v0072:
    v0064 = v0066;
    v0064 = ncons(v0064);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    goto v0056;
/* error exit handlers */
v0088:
    popv(3);
    return nil;
}



/* Code for mml2om */

static Lisp_Object MS_CDECL CC_mml2om(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mml2om");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mml2om");
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
    fn = elt(env, 3); /* mml2ir */
    v0090 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-1];
    stack[0] = v0090;
    v0090 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 4); /* terpri!* */
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-1];
    v0090 = elt(env, 2); /* "Intermediate representation: " */
    v0090 = Lprinc(nil, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-1];
    v0090 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 4); /* terpri!* */
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-1];
    v0090 = stack[0];
    v0090 = Lprint(nil, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-1];
    v0090 = stack[0];
    fn = elt(env, 5); /* ir2om */
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    v0090 = nil;
    { popv(2); return onevalue(v0090); }
/* error exit handlers */
v0040:
    popv(2);
    return nil;
}



/* Code for vevlcm */

static Lisp_Object CC_vevlcm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0165, v0076;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevlcm");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0076 = nil;
    goto v0078;

v0078:
    v0016 = stack[-1];
    if (v0016 == nil) goto v0063;
    v0016 = stack[0];
    if (v0016 == nil) goto v0063;
    v0016 = stack[-1];
    v0165 = qcar(v0016);
    v0016 = stack[0];
    v0016 = qcar(v0016);
    if (((int32_t)(v0165)) > ((int32_t)(v0016))) goto v0010;
    v0016 = stack[0];
    v0016 = qcar(v0016);
    goto v0081;

v0081:
    v0165 = v0076;
    v0016 = cons(v0016, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-2];
    v0076 = v0016;
    v0016 = stack[-1];
    v0016 = qcdr(v0016);
    stack[-1] = v0016;
    v0016 = stack[0];
    v0016 = qcdr(v0016);
    stack[0] = v0016;
    goto v0078;

v0010:
    v0016 = stack[-1];
    v0016 = qcar(v0016);
    goto v0081;

v0063:
    v0016 = v0076;
    v0016 = Lnreverse(nil, v0016);
    env = stack[-2];
    v0076 = v0016;
    v0016 = stack[-1];
    if (v0016 == nil) goto v0058;
    v0165 = v0076;
    v0016 = stack[-1];
    v0016 = Lnconc(nil, v0165, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    v0076 = v0016;
    { popv(3); return onevalue(v0076); }

v0058:
    v0016 = stack[0];
    if (v0016 == nil) { popv(3); return onevalue(v0076); }
    v0165 = v0076;
    v0016 = stack[0];
    v0016 = Lnconc(nil, v0165, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    v0076 = v0016;
    { popv(3); return onevalue(v0076); }
/* error exit handlers */
v0112:
    popv(3);
    return nil;
}



/* Code for oprinla */

static Lisp_Object CC_oprinla(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0171, v0057, v0167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for oprinla");
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
    v0057 = v0000;
/* end of prologue */
    v0167 = v0057;
    v0171 = elt(env, 1); /* lapr */
    v0171 = get(v0167, v0171);
    env = stack[0];
    v0167 = v0171;
    if (v0171 == nil) goto v0075;
    v0171 = v0167;
    fn = elt(env, 5); /* prin2la */
    v0171 = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    goto v0018;

v0018:
    v0171 = nil;
    { popv(1); return onevalue(v0171); }

v0075:
    v0167 = v0057;
    v0171 = elt(env, 2); /* prtch */
    v0171 = get(v0167, v0171);
    env = stack[0];
    v0167 = v0171;
    if (v0171 == nil) goto v0031;
    v0171 = v0167;
    fn = elt(env, 5); /* prin2la */
    v0171 = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    goto v0018;

v0031:
    v0167 = v0057;
    v0171 = elt(env, 3); /* lapop */
    v0171 = get(v0167, v0171);
    env = stack[0];
    v0167 = v0171;
    if (v0171 == nil) goto v0028;
    v0171 = v0167;
    fn = elt(env, 5); /* prin2la */
    v0171 = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[0];
    v0171 = elt(env, 4); /* !  */
    fn = elt(env, 5); /* prin2la */
    v0171 = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    goto v0018;

v0028:
    v0171 = v0057;
    fn = elt(env, 6); /* prinlatom */
    v0171 = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    goto v0018;
/* error exit handlers */
v0038:
    popv(1);
    return nil;
}



/* Code for fortexp */

static Lisp_Object CC_fortexp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0079;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fortexp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0037 = v0000;
/* end of prologue */
    v0079 = v0037;
    v0037 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 1); /* fortexp1 */
        return (*qfn2(fn))(qenv(fn), v0079, v0037);
    }
}



/* Code for command */

static Lisp_Object MS_CDECL CC_command(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0203, v0204, v0205, v0206;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "command");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for command");
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
    stack[-3] = qvalue(elt(env, 1)); /* errmsg!* */
    qvalue(elt(env, 1)) = nil; /* errmsg!* */
    stack[-2] = qvalue(elt(env, 2)); /* loopdelimslist!* */
    qvalue(elt(env, 2)) = nil; /* loopdelimslist!* */
    v0203 = qvalue(elt(env, 3)); /* !*demo */
    if (v0203 == nil) goto v0013;
    v0203 = qvalue(elt(env, 4)); /* ifl!* */
    if (v0203 == nil) goto v0013;
    fn = elt(env, 32); /* commdemo */
    v0203 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    goto v0063;

v0063:
    qvalue(elt(env, 2)) = stack[-2]; /* loopdelimslist!* */
    qvalue(elt(env, 1)) = stack[-3]; /* errmsg!* */
    { popv(5); return onevalue(v0203); }

v0013:
    v0203 = qvalue(elt(env, 5)); /* !*slin */
    if (v0203 == nil) goto v0011;
    v0203 = qvalue(elt(env, 7)); /* !*reduce4 */
    goto v0070;

v0070:
    if (!(v0203 == nil)) goto v0078;
    v0203 = qvalue(elt(env, 4)); /* ifl!* */
    if (v0203 == nil) goto v0030;
    v0203 = qvalue(elt(env, 4)); /* ifl!* */
    v0205 = qcar(v0203);
    v0204 = (Lisp_Object)17; /* 1 */
    v0203 = qvalue(elt(env, 9)); /* curline!* */
    v0203 = list2star(v0205, v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    goto v0032;

v0032:
    qvalue(elt(env, 10)) = v0203; /* cloc!* */
    v0203 = qvalue(elt(env, 11)); /* lreadfn!* */
    if (v0203 == nil) goto v0034;
    v0204 = qvalue(elt(env, 11)); /* lreadfn!* */
    v0203 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 33); /* lispapply */
    v0203 = (*qfn2(fn))(qenv(fn), v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    goto v0038;

v0038:
    stack[-1] = v0203;
    goto v0051;

v0051:
    v0203 = qvalue(elt(env, 7)); /* !*reduce4 */
    if (v0203 == nil) goto v0053;
    v0203 = qvalue(elt(env, 28)); /* !*debug */
    if (v0203 == nil) goto v0208;
    v0203 = elt(env, 29); /* "Parse: " */
    v0203 = Lprinc(nil, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    stack[0] = stack[-1];
    v0203 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    fn = elt(env, 34); /* superprinm */
    v0203 = (*qfn2(fn))(qenv(fn), stack[0], v0203);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    v0203 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    goto v0208;

v0208:
    v0204 = qvalue(elt(env, 20)); /* key!* */
    v0203 = elt(env, 30); /* !*semicol!* */
    if (v0204 == v0203) goto v0078;
    v0203 = qvalue(elt(env, 7)); /* !*reduce4 */
    if (v0203 == nil) goto v0209;
    v0203 = stack[-1];
    fn = elt(env, 35); /* n_form */
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    stack[-1] = v0203;
    goto v0210;

v0210:
    v0203 = qvalue(elt(env, 28)); /* !*debug */
    if (v0203 == nil) goto v0211;
    v0203 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    v0203 = elt(env, 31); /* "Form: " */
    v0203 = Lprinc(nil, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    stack[0] = stack[-1];
    v0203 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    fn = elt(env, 34); /* superprinm */
    v0203 = (*qfn2(fn))(qenv(fn), stack[0], v0203);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    v0203 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    goto v0211;

v0211:
    v0203 = stack[-1];
    goto v0063;

v0209:
    v0203 = stack[-1];
    fn = elt(env, 36); /* form */
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    stack[-1] = v0203;
    goto v0210;

v0078:
    fn = elt(env, 37); /* readch1 */
    v0203 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    qvalue(elt(env, 12)) = v0203; /* crchar!* */
    v0204 = qvalue(elt(env, 12)); /* crchar!* */
    v0203 = qvalue(elt(env, 13)); /* !$eol!$ */
    if (equal(v0204, v0203)) goto v0078;
    fn = elt(env, 38); /* command1 */
    v0203 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    stack[-1] = v0203;
    goto v0051;

v0053:
    v0203 = qvalue(elt(env, 14)); /* !*struct */
    if (v0203 == nil) goto v0138;
    v0203 = stack[-1];
    fn = elt(env, 39); /* structchk */
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    stack[-1] = v0203;
    goto v0138;

v0138:
    v0203 = qvalue(elt(env, 15)); /* !*pret */
    if (v0203 == nil) goto v0212;
    v0203 = stack[-1];
    if (!consp(v0203)) goto v0107;
    v0203 = stack[-1];
    v0204 = qcar(v0203);
    v0203 = elt(env, 16); /* (in out shut) */
    v0203 = Lmemq(nil, v0204, v0203);
    v0203 = (v0203 == nil ? lisp_true : nil);
    goto v0088;

v0088:
    if (v0203 == nil) goto v0212;
    v0203 = stack[-1];
    if (v0203 == nil) goto v0133;
    v0203 = qvalue(elt(env, 8)); /* nil */
    goto v0136;

v0136:
    if (v0203 == nil) goto v0168;
    v0203 = elt(env, 18); /* end */
    fn = elt(env, 40); /* rprint */
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    goto v0212;

v0212:
    v0203 = qvalue(elt(env, 5)); /* !*slin */
    if (v0203 == nil) goto v0144;
    v0204 = elt(env, 19); /* symbolic */
    v0203 = stack[-1];
    v0203 = list2(v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    goto v0063;

v0144:
    v0203 = stack[-1];
    fn = elt(env, 36); /* form */
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    v0204 = v0203;
    v0205 = qvalue(elt(env, 20)); /* key!* */
    v0203 = elt(env, 21); /* modefn */
    v0203 = Lflagp(nil, v0205, v0203);
    env = stack[-4];
    if (v0203 == nil) goto v0213;
    v0203 = qvalue(elt(env, 20)); /* key!* */
    goto v0214;

v0214:
    stack[0] = v0203;
    v0206 = v0204;
    v0205 = qvalue(elt(env, 8)); /* nil */
    v0204 = elt(env, 19); /* symbolic */
    fn = elt(env, 41); /* convertmode1 */
    v0203 = (*qfnn(fn))(qenv(fn), 4, v0206, v0205, v0204, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    v0203 = list2(stack[0], v0203);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    goto v0063;

v0213:
    v0203 = v0204;
    if (!consp(v0203)) goto v0215;
    v0203 = v0204;
    v0205 = qcar(v0203);
    v0203 = elt(env, 22); /* quote */
    if (v0205 == v0203) goto v0216;
    v0203 = v0204;
    v0203 = qcar(v0203);
    if (!(symbolp(v0203))) goto v0217;
    v0203 = v0204;
    v0205 = qcar(v0203);
    v0203 = elt(env, 23); /* nochange */
    v0203 = Lflagp(nil, v0205, v0203);
    env = stack[-4];
    if (v0203 == nil) goto v0123;
    v0203 = qvalue(elt(env, 6)); /* t */
    goto v0218;

v0218:
    if (v0203 == nil) goto v0217;
    v0203 = v0204;
    v0205 = qcar(v0203);
    v0203 = elt(env, 26); /* (setq setel setf) */
    v0203 = Lmemq(nil, v0205, v0203);
    if (v0203 == nil) goto v0151;
    v0203 = v0204;
    v0203 = qcdr(v0203);
    v0203 = qcdr(v0203);
    v0205 = qcar(v0203);
    v0203 = elt(env, 22); /* quote */
    v0203 = Leqcar(nil, v0205, v0203);
    env = stack[-4];
    goto v0219;

v0219:
    if (v0203 == nil) goto v0220;
    v0203 = elt(env, 19); /* symbolic */
    goto v0214;

v0220:
    v0203 = qvalue(elt(env, 27)); /* !*mode */
    goto v0214;

v0151:
    v0203 = qvalue(elt(env, 8)); /* nil */
    goto v0219;

v0217:
    v0203 = qvalue(elt(env, 6)); /* t */
    goto v0219;

v0123:
    v0203 = v0204;
    v0205 = qcar(v0203);
    v0203 = elt(env, 24); /* intfn */
    v0203 = Lflagp(nil, v0205, v0203);
    env = stack[-4];
    if (v0203 == nil) goto v0221;
    v0203 = qvalue(elt(env, 6)); /* t */
    goto v0218;

v0221:
    v0203 = v0204;
    v0205 = qcar(v0203);
    v0203 = elt(env, 25); /* list */
    v0203 = (v0205 == v0203 ? lisp_true : nil);
    goto v0218;

v0216:
    v0203 = qvalue(elt(env, 8)); /* nil */
    goto v0219;

v0215:
    v0203 = qvalue(elt(env, 8)); /* nil */
    goto v0219;

v0168:
    v0203 = stack[-1];
    fn = elt(env, 40); /* rprint */
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    v0203 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    goto v0212;

v0133:
    v0204 = qvalue(elt(env, 17)); /* cursym!* */
    v0203 = elt(env, 18); /* end */
    v0203 = (v0204 == v0203 ? lisp_true : nil);
    goto v0136;

v0107:
    v0203 = qvalue(elt(env, 6)); /* t */
    goto v0088;

v0034:
    v0203 = Lread(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-4];
    goto v0038;

v0030:
    v0203 = qvalue(elt(env, 8)); /* nil */
    goto v0032;

v0011:
    v0203 = qvalue(elt(env, 6)); /* t */
    goto v0070;
/* error exit handlers */
v0207:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-2]; /* loopdelimslist!* */
    qvalue(elt(env, 1)) = stack[-3]; /* errmsg!* */
    popv(5);
    return nil;
}



/* Code for dp_neg */

static Lisp_Object CC_dp_neg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_neg");
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
    v0005 = v0000;
/* end of prologue */
    stack[-4] = v0005;
    v0005 = stack[-4];
    if (v0005 == nil) goto v0079;
    v0005 = stack[-4];
    v0005 = qcar(v0005);
    v0033 = v0005;
    v0005 = v0033;
    stack[0] = qcar(v0005);
    v0005 = v0033;
    v0005 = qcdr(v0005);
    fn = elt(env, 2); /* bc_neg */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    v0005 = cons(stack[0], v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    v0005 = ncons(v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    stack[-2] = v0005;
    stack[-3] = v0005;
    goto v0063;

v0063:
    v0005 = stack[-4];
    v0005 = qcdr(v0005);
    stack[-4] = v0005;
    v0005 = stack[-4];
    if (v0005 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v0005 = stack[-4];
    v0005 = qcar(v0005);
    v0033 = v0005;
    v0005 = v0033;
    stack[0] = qcar(v0005);
    v0005 = v0033;
    v0005 = qcdr(v0005);
    fn = elt(env, 2); /* bc_neg */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    v0005 = cons(stack[0], v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    v0005 = ncons(v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    v0005 = Lrplacd(nil, stack[-1], v0005);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-5];
    v0005 = stack[-2];
    v0005 = qcdr(v0005);
    stack[-2] = v0005;
    goto v0063;

v0079:
    v0005 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0005); }
/* error exit handlers */
v0056:
    popv(6);
    return nil;
}



/* Code for simp!-prop!-order */

static Lisp_Object CC_simpKpropKorder(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0028, v0006, v0007;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop-order");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0028 = v0001;
    v0006 = v0000;
/* end of prologue */

v0027:
    v0029 = v0006;
    if (v0029 == nil) goto v0078;
    v0029 = v0006;
    v0029 = qcar(v0029);
    v0007 = qcar(v0029);
    v0029 = v0028;
    v0029 = qcar(v0029);
    v0029 = qcar(v0029);
    if (equal(v0007, v0029)) goto v0045;
    v0029 = v0006;
    v0029 = qcar(v0029);
    v0028 = qcar(v0029);
    v0029 = elt(env, 2); /* prop!* */
    if (v0028 == v0029) goto v0008;
    v0029 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0029);

v0008:
    v0029 = qvalue(elt(env, 3)); /* t */
    return onevalue(v0029);

v0045:
    v0029 = v0006;
    v0029 = qcdr(v0029);
    v0006 = v0029;
    v0029 = v0028;
    v0029 = qcdr(v0029);
    v0028 = v0029;
    goto v0027;

v0078:
    v0029 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0029);
}



/* Code for symbvarlst */

static Lisp_Object MS_CDECL CC_symbvarlst(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0023, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0198, v0136, v0137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "symbvarlst");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbvarlst");
#endif
    if (stack >= stacklimit)
    {
        push3(v0023,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0023);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v0198 = v0023;
    stack[-4] = v0001;
    v0137 = v0000;
/* end of prologue */
    v0136 = v0198;
    v0198 = elt(env, 1); /* symbolic */
    if (v0136 == v0198) goto v0037;
    v0198 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v0198); }

v0037:
    v0198 = v0137;
    stack[-5] = v0198;
    goto v0078;

v0078:
    v0198 = stack[-5];
    if (v0198 == nil) goto v0011;
    v0198 = stack[-5];
    v0198 = qcar(v0198);
    v0198 = Lconsp(nil, v0198);
    env = stack[-6];
    if (v0198 == nil) goto v0073;
    v0198 = stack[-5];
    v0198 = qcar(v0198);
    v0198 = qcar(v0198);
    goto v0008;

v0008:
    stack[0] = v0198;
    v0198 = stack[0];
    v0198 = Lsymbol_specialp(nil, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    if (v0198 == nil) goto v0069;
    v0198 = qvalue(elt(env, 2)); /* nil */
    goto v0007;

v0007:
    if (v0198 == nil) goto v0047;
    v0198 = qvalue(elt(env, 4)); /* !*msg */
    if (v0198 == nil) goto v0047;
    stack[-3] = elt(env, 5); /* "***" */
    stack[-2] = elt(env, 6); /* "local variable" */
    stack[-1] = stack[0];
    stack[0] = elt(env, 7); /* "in procedure" */
    v0136 = qvalue(elt(env, 8)); /* fname!* */
    v0198 = elt(env, 9); /* "not used" */
    v0198 = list2(v0136, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    v0198 = list3star(stack[-2], stack[-1], stack[0], v0198);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    fn = elt(env, 10); /* lpriw */
    v0198 = (*qfn2(fn))(qenv(fn), stack[-3], v0198);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    goto v0047;

v0047:
    v0198 = stack[-5];
    v0198 = qcdr(v0198);
    stack[-5] = v0198;
    goto v0078;

v0069:
    v0198 = stack[0];
    v0198 = Lsymbol_globalp(nil, v0198);
    env = stack[-6];
    if (v0198 == nil) goto v0033;
    v0198 = qvalue(elt(env, 2)); /* nil */
    goto v0007;

v0033:
    v0136 = stack[0];
    v0198 = stack[-4];
    v0198 = Lsmemq(nil, v0136, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-6];
    if (v0198 == nil) goto v0049;
    v0198 = qvalue(elt(env, 2)); /* nil */
    goto v0007;

v0049:
    v0198 = qvalue(elt(env, 3)); /* !*novarmsg */
    v0198 = (v0198 == nil ? lisp_true : nil);
    goto v0007;

v0073:
    v0198 = stack[-5];
    v0198 = qcar(v0198);
    goto v0008;

v0011:
    v0198 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v0198); }
/* error exit handlers */
v0122:
    popv(7);
    return nil;
}



/* Code for setqget */

static Lisp_Object MS_CDECL CC_setqget(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0008;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setqget");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setqget");
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
    v0021 = qvalue(elt(env, 1)); /* fluidbibasissetq */
    v0021 = qcar(v0021);
    stack[-1] = v0021;
    v0021 = qvalue(elt(env, 1)); /* fluidbibasissetq */
    stack[0] = v0021;
    v0008 = stack[0];
    v0021 = stack[0];
    v0021 = qcdr(v0021);
    v0021 = qcar(v0021);
    v0008 = Lrplaca(nil, v0008, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    v0021 = stack[0];
    v0021 = qcdr(v0021);
    v0021 = qcdr(v0021);
    v0021 = Lrplacd(nil, v0008, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v0032:
    popv(3);
    return nil;
}



/* Code for mk!+mat!+mult!+mat */

static Lisp_Object CC_mkLmatLmultLmat(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0279, v0280, v0281;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+mat+mult+mat");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
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
    stack[-13] = v0001;
    stack[-14] = v0000;
/* end of prologue */
    v0279 = stack[-14];
    fn = elt(env, 7); /* matrix!+p */
    v0279 = (*qfn1(fn))(qenv(fn), v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    if (!(v0279 == nil)) goto v0013;
    v0279 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v0279 == nil)) goto v0075;
    v0279 = elt(env, 2); /* "no matrix in mult" */
    fn = elt(env, 8); /* lprie */
    v0279 = (*qfn1(fn))(qenv(fn), v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    goto v0075;

v0075:
    v0279 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    goto v0013;

v0013:
    v0279 = stack[-13];
    fn = elt(env, 7); /* matrix!+p */
    v0279 = (*qfn1(fn))(qenv(fn), v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    if (!(v0279 == nil)) goto v0020;
    v0279 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v0279 == nil)) goto v0073;
    v0279 = elt(env, 2); /* "no matrix in mult" */
    fn = elt(env, 8); /* lprie */
    v0279 = (*qfn1(fn))(qenv(fn), v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    goto v0073;

v0073:
    v0279 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    goto v0020;

v0020:
    v0279 = stack[-14];
    fn = elt(env, 9); /* get!+col!+nr */
    v0279 = (*qfn1(fn))(qenv(fn), v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[-15] = v0279;
    v0279 = stack[-14];
    fn = elt(env, 10); /* get!+row!+nr */
    v0279 = (*qfn1(fn))(qenv(fn), v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[-12] = v0279;
    v0279 = stack[-13];
    fn = elt(env, 9); /* get!+col!+nr */
    v0279 = (*qfn1(fn))(qenv(fn), v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[-11] = v0279;
    stack[0] = stack[-15];
    v0279 = stack[-13];
    fn = elt(env, 10); /* get!+row!+nr */
    v0279 = (*qfn1(fn))(qenv(fn), v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    if (equal(stack[0], v0279)) goto v0038;
    v0279 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v0279 == nil)) goto v0036;
    v0279 = elt(env, 3); /* "matrices can not be multiplied" */
    fn = elt(env, 8); /* lprie */
    v0279 = (*qfn1(fn))(qenv(fn), v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    goto v0036;

v0036:
    v0279 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    goto v0038;

v0038:
    v0279 = (Lisp_Object)17; /* 1 */
    stack[-10] = v0279;
    v0280 = stack[-12];
    v0279 = stack[-10];
    v0279 = difference2(v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0279 = Lminusp(nil, v0279);
    env = stack[-16];
    if (v0279 == nil) goto v0138;
    v0279 = qvalue(elt(env, 4)); /* nil */
    { popv(17); return onevalue(v0279); }

v0138:
    v0279 = (Lisp_Object)17; /* 1 */
    stack[-5] = v0279;
    v0280 = stack[-11];
    v0279 = stack[-5];
    v0279 = difference2(v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0279 = Lminusp(nil, v0279);
    env = stack[-16];
    if (v0279 == nil) goto v0158;
    v0279 = qvalue(elt(env, 4)); /* nil */
    goto v0107;

v0107:
    v0279 = ncons(v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[-8] = v0279;
    stack[-9] = v0279;
    goto v0017;

v0017:
    v0279 = stack[-10];
    v0279 = add1(v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[-10] = v0279;
    v0280 = stack[-12];
    v0279 = stack[-10];
    v0279 = difference2(v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0279 = Lminusp(nil, v0279);
    env = stack[-16];
    if (!(v0279 == nil)) { Lisp_Object res = stack[-9]; popv(17); return onevalue(res); }
    stack[-7] = stack[-8];
    v0279 = (Lisp_Object)17; /* 1 */
    stack[-6] = v0279;
    v0280 = stack[-11];
    v0279 = stack[-6];
    v0279 = difference2(v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0279 = Lminusp(nil, v0279);
    env = stack[-16];
    if (v0279 == nil) goto v0210;
    v0279 = qvalue(elt(env, 4)); /* nil */
    goto v0283;

v0283:
    v0279 = ncons(v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0279 = Lrplacd(nil, stack[-7], v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0279 = stack[-8];
    v0279 = qcdr(v0279);
    stack[-8] = v0279;
    goto v0017;

v0210:
    v0280 = qvalue(elt(env, 4)); /* nil */
    v0279 = (Lisp_Object)17; /* 1 */
    v0279 = cons(v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[0] = v0279;
    v0279 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0279;
    goto v0284;

v0284:
    v0280 = stack[-15];
    v0279 = stack[-1];
    v0279 = difference2(v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0279 = Lminusp(nil, v0279);
    env = stack[-16];
    if (v0279 == nil) goto v0285;
    v0279 = qvalue(elt(env, 5)); /* t */
    stack[-1] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v0279; /* !*sub2 */
    v0279 = stack[0];
    fn = elt(env, 11); /* subs2 */
    v0279 = (*qfn1(fn))(qenv(fn), v0279);
    nil = C_nil;
    if (exception_pending()) goto v0286;
    env = stack[-16];
    stack[0] = v0279;
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    v0279 = stack[0];
    v0279 = ncons(v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[-4] = v0279;
    stack[-5] = v0279;
    goto v0287;

v0287:
    v0279 = stack[-6];
    v0279 = add1(v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[-6] = v0279;
    v0280 = stack[-11];
    v0279 = stack[-6];
    v0279 = difference2(v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0279 = Lminusp(nil, v0279);
    env = stack[-16];
    if (v0279 == nil) goto v0288;
    v0279 = stack[-5];
    goto v0283;

v0288:
    stack[-3] = stack[-4];
    v0280 = qvalue(elt(env, 4)); /* nil */
    v0279 = (Lisp_Object)17; /* 1 */
    v0279 = cons(v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[0] = v0279;
    v0279 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0279;
    goto v0289;

v0289:
    v0280 = stack[-15];
    v0279 = stack[-2];
    v0279 = difference2(v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0279 = Lminusp(nil, v0279);
    env = stack[-16];
    if (v0279 == nil) goto v0290;
    v0279 = qvalue(elt(env, 5)); /* t */
    stack[-1] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v0279; /* !*sub2 */
    v0279 = stack[0];
    fn = elt(env, 11); /* subs2 */
    v0279 = (*qfn1(fn))(qenv(fn), v0279);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-16];
    stack[0] = v0279;
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    v0279 = stack[0];
    v0279 = ncons(v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0279 = Lrplacd(nil, stack[-3], v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0279 = stack[-4];
    v0279 = qcdr(v0279);
    stack[-4] = v0279;
    goto v0287;

v0290:
    stack[-1] = stack[0];
    v0281 = stack[-14];
    v0280 = stack[-10];
    v0279 = stack[-2];
    fn = elt(env, 12); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0281, v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0281 = stack[-13];
    v0280 = stack[-2];
    v0279 = stack[-6];
    fn = elt(env, 12); /* get!+mat!+entry */
    v0279 = (*qfnn(fn))(qenv(fn), 3, v0281, v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    fn = elt(env, 13); /* multsq */
    v0279 = (*qfn2(fn))(qenv(fn), stack[0], v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    fn = elt(env, 14); /* addsq */
    v0279 = (*qfn2(fn))(qenv(fn), stack[-1], v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[0] = v0279;
    v0279 = stack[-2];
    v0279 = add1(v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[-2] = v0279;
    goto v0289;

v0285:
    stack[-2] = stack[0];
    v0281 = stack[-14];
    v0280 = stack[-10];
    v0279 = stack[-1];
    fn = elt(env, 12); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0281, v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0281 = stack[-13];
    v0280 = stack[-1];
    v0279 = stack[-6];
    fn = elt(env, 12); /* get!+mat!+entry */
    v0279 = (*qfnn(fn))(qenv(fn), 3, v0281, v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    fn = elt(env, 13); /* multsq */
    v0279 = (*qfn2(fn))(qenv(fn), stack[0], v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    fn = elt(env, 14); /* addsq */
    v0279 = (*qfn2(fn))(qenv(fn), stack[-2], v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[0] = v0279;
    v0279 = stack[-1];
    v0279 = add1(v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[-1] = v0279;
    goto v0284;

v0158:
    v0280 = qvalue(elt(env, 4)); /* nil */
    v0279 = (Lisp_Object)17; /* 1 */
    v0279 = cons(v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[0] = v0279;
    v0279 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0279;
    goto v0160;

v0160:
    v0280 = stack[-15];
    v0279 = stack[-1];
    v0279 = difference2(v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0279 = Lminusp(nil, v0279);
    env = stack[-16];
    if (v0279 == nil) goto v0292;
    v0279 = qvalue(elt(env, 5)); /* t */
    stack[-1] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v0279; /* !*sub2 */
    v0279 = stack[0];
    fn = elt(env, 11); /* subs2 */
    v0279 = (*qfn1(fn))(qenv(fn), v0279);
    nil = C_nil;
    if (exception_pending()) goto v0293;
    env = stack[-16];
    stack[0] = v0279;
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    v0279 = stack[0];
    v0279 = ncons(v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[-3] = v0279;
    stack[-4] = v0279;
    goto v0106;

v0106:
    v0279 = stack[-5];
    v0279 = add1(v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[-5] = v0279;
    v0280 = stack[-11];
    v0279 = stack[-5];
    v0279 = difference2(v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0279 = Lminusp(nil, v0279);
    env = stack[-16];
    if (v0279 == nil) goto v0294;
    v0279 = stack[-4];
    goto v0107;

v0294:
    stack[-2] = stack[-3];
    v0280 = qvalue(elt(env, 4)); /* nil */
    v0279 = (Lisp_Object)17; /* 1 */
    v0279 = cons(v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[0] = v0279;
    v0279 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0279;
    goto v0221;

v0221:
    v0280 = stack[-15];
    v0279 = stack[-1];
    v0279 = difference2(v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0279 = Lminusp(nil, v0279);
    env = stack[-16];
    if (v0279 == nil) goto v0139;
    v0279 = qvalue(elt(env, 5)); /* t */
    stack[-1] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v0279; /* !*sub2 */
    v0279 = stack[0];
    fn = elt(env, 11); /* subs2 */
    v0279 = (*qfn1(fn))(qenv(fn), v0279);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-16];
    stack[0] = v0279;
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    v0279 = stack[0];
    v0279 = ncons(v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0279 = Lrplacd(nil, stack[-2], v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0279 = stack[-3];
    v0279 = qcdr(v0279);
    stack[-3] = v0279;
    goto v0106;

v0139:
    stack[-6] = stack[0];
    v0281 = stack[-14];
    v0280 = stack[-10];
    v0279 = stack[-1];
    fn = elt(env, 12); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0281, v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0281 = stack[-13];
    v0280 = stack[-1];
    v0279 = stack[-5];
    fn = elt(env, 12); /* get!+mat!+entry */
    v0279 = (*qfnn(fn))(qenv(fn), 3, v0281, v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    fn = elt(env, 13); /* multsq */
    v0279 = (*qfn2(fn))(qenv(fn), stack[0], v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    fn = elt(env, 14); /* addsq */
    v0279 = (*qfn2(fn))(qenv(fn), stack[-6], v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[0] = v0279;
    v0279 = stack[-1];
    v0279 = add1(v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[-1] = v0279;
    goto v0221;

v0292:
    stack[-2] = stack[0];
    v0281 = stack[-14];
    v0280 = stack[-10];
    v0279 = stack[-1];
    fn = elt(env, 12); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0281, v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    v0281 = stack[-13];
    v0280 = stack[-1];
    v0279 = stack[-5];
    fn = elt(env, 12); /* get!+mat!+entry */
    v0279 = (*qfnn(fn))(qenv(fn), 3, v0281, v0280, v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    fn = elt(env, 13); /* multsq */
    v0279 = (*qfn2(fn))(qenv(fn), stack[0], v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    fn = elt(env, 14); /* addsq */
    v0279 = (*qfn2(fn))(qenv(fn), stack[-2], v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[0] = v0279;
    v0279 = stack[-1];
    v0279 = add1(v0279);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-16];
    stack[-1] = v0279;
    goto v0160;
/* error exit handlers */
v0295:
    env = stack[-16];
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    popv(17);
    return nil;
v0293:
    env = stack[-16];
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    popv(17);
    return nil;
v0291:
    env = stack[-16];
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    popv(17);
    return nil;
v0286:
    env = stack[-16];
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    popv(17);
    return nil;
v0282:
    popv(17);
    return nil;
}



/* Code for ratpoly_lc */

static Lisp_Object CC_ratpoly_lc(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0013;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_lc");
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
    stack[0] = v0000;
/* end of prologue */
    v0012 = stack[0];
    v0012 = qcar(v0012);
    fn = elt(env, 1); /* numpoly_lc */
    v0013 = (*qfn1(fn))(qenv(fn), v0012);
    nil = C_nil;
    if (exception_pending()) goto v0080;
    v0012 = stack[0];
    v0012 = qcdr(v0012);
    popv(1);
    return cons(v0013, v0012);
/* error exit handlers */
v0080:
    popv(1);
    return nil;
}



/* Code for getsetvars */

static Lisp_Object CC_getsetvars(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0170, v0056;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getsetvars");
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
    goto v0027;

v0027:
    v0170 = stack[0];
    if (!consp(v0170)) goto v0078;
    v0170 = stack[0];
    v0056 = qcar(v0170);
    v0170 = elt(env, 1); /* (setel setk) */
    v0170 = Lmemq(nil, v0056, v0170);
    if (v0170 == nil) goto v0085;
    v0170 = stack[0];
    v0170 = qcdr(v0170);
    v0170 = qcar(v0170);
    fn = elt(env, 3); /* getsetvarlis */
    v0056 = (*qfn1(fn))(qenv(fn), v0170);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    v0170 = stack[-1];
    v0170 = cons(v0056, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    stack[-1] = v0170;
    v0170 = stack[0];
    v0170 = qcdr(v0170);
    v0170 = qcdr(v0170);
    v0170 = qcar(v0170);
    stack[0] = v0170;
    goto v0027;

v0085:
    v0170 = stack[0];
    v0056 = qcar(v0170);
    v0170 = elt(env, 2); /* setq */
    if (v0056 == v0170) goto v0057;
    v0170 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0170);
    }

v0057:
    v0170 = stack[0];
    v0170 = qcdr(v0170);
    v0170 = qcar(v0170);
    v0056 = Lmkquote(nil, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    v0170 = stack[-1];
    v0170 = cons(v0056, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    stack[-1] = v0170;
    v0170 = stack[0];
    v0170 = qcdr(v0170);
    v0170 = qcdr(v0170);
    v0170 = qcar(v0170);
    stack[0] = v0170;
    goto v0027;

v0078:
    v0170 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0170);
    }
/* error exit handlers */
v0003:
    popv(3);
    return nil;
}



/* Code for merge!-ind!-vars */

static Lisp_Object CC_mergeKindKvars(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068, v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for merge-ind-vars");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0068 = qvalue(elt(env, 1)); /* !*nocommutedf */
    if (!(v0068 == nil)) goto v0073;
    v0068 = qvalue(elt(env, 2)); /* !*commutedf */
    if (v0068 == nil) goto v0090;
    v0068 = qvalue(elt(env, 3)); /* nil */
    goto v0079;

v0079:
    if (!(v0068 == nil)) goto v0073;
    v0049 = stack[0];
    v0068 = stack[-1];
    v0068 = qcdr(v0068);
    v0068 = qcdr(v0068);
    {
        popv(4);
        fn = elt(env, 4); /* derad */
        return (*qfn2(fn))(qenv(fn), v0049, v0068);
    }

v0073:
    v0049 = stack[0];
    v0068 = stack[-1];
    v0068 = qcdr(v0068);
    v0068 = qcdr(v0068);
    {
        popv(4);
        fn = elt(env, 5); /* derad!* */
        return (*qfn2(fn))(qenv(fn), v0049, v0068);
    }

v0090:
    v0068 = stack[-1];
    v0068 = qcdr(v0068);
    stack[-2] = qcar(v0068);
    v0049 = stack[0];
    v0068 = stack[-1];
    v0068 = qcdr(v0068);
    v0068 = qcdr(v0068);
    v0068 = cons(v0049, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-3];
    v0068 = Lmemq(nil, stack[-2], v0068);
    goto v0079;
/* error exit handlers */
v0034:
    popv(4);
    return nil;
}



/* Code for vdpsave */

static Lisp_Object CC_vdpsave(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0024;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpsave");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0024 = v0000;
/* end of prologue */
    return onevalue(v0024);
}



/* Code for prinlatom */

static Lisp_Object CC_prinlatom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0055;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prinlatom");
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
    v0055 = stack[-1];
    v0056 = elt(env, 1); /* font */
    v0056 = get(v0055, v0056);
    env = stack[-3];
    stack[-2] = v0056;
    if (v0056 == nil) goto v0010;
    v0056 = stack[-2];
    fn = elt(env, 5); /* prin2la */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    goto v0010;

v0010:
    v0055 = stack[-1];
    v0056 = elt(env, 2); /* accent */
    v0056 = get(v0055, v0056);
    env = stack[-3];
    stack[0] = v0056;
    if (v0056 == nil) goto v0084;
    v0056 = stack[0];
    fn = elt(env, 5); /* prin2la */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    goto v0084;

v0084:
    v0055 = stack[-1];
    v0056 = elt(env, 3); /* name */
    v0056 = get(v0055, v0056);
    env = stack[-3];
    v0055 = v0056;
    if (v0056 == nil) goto v0171;
    v0056 = v0055;
    fn = elt(env, 5); /* prin2la */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    goto v0043;

v0043:
    v0056 = stack[0];
    if (v0056 == nil) goto v0048;
    v0056 = elt(env, 4); /* "}" */
    fn = elt(env, 5); /* prin2la */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    goto v0048;

v0048:
    v0056 = stack[-2];
    if (v0056 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0056 = elt(env, 4); /* "}" */
    fn = elt(env, 5); /* prin2la */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v0171:
    v0056 = stack[-1];
    fn = elt(env, 6); /* testchar1 */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    fn = elt(env, 5); /* prin2la */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    goto v0043;
/* error exit handlers */
v0015:
    popv(4);
    return nil;
}



/* Code for insertparens */

static Lisp_Object CC_insertparens(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insertparens");
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
    v0039 = v0000;
/* end of prologue */
    stack[-1] = elt(env, 1); /* !( */
    stack[0] = v0039;
    v0039 = elt(env, 2); /* !) */
    v0039 = ncons(v0039);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-2];
    v0039 = Lappend(nil, stack[0], v0039);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    {
        Lisp_Object v0075 = stack[-1];
        popv(3);
        return cons(v0075, v0039);
    }
/* error exit handlers */
v0081:
    popv(3);
    return nil;
}



/* Code for deleteall */

static Lisp_Object CC_deleteall(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0073, v0083, v0084, v0085;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deleteall");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0084 = nil;
    goto v0063;

v0063:
    v0073 = stack[0];
    if (v0073 == nil) { popv(4); return onevalue(v0084); }
    v0073 = stack[0];
    v0073 = qcar(v0073);
    v0085 = v0073;
    v0073 = stack[0];
    v0073 = qcdr(v0073);
    stack[0] = v0073;
    v0083 = v0085;
    v0073 = stack[-1];
    if (equal(v0083, v0073)) goto v0063;
    stack[-2] = v0084;
    v0073 = v0085;
    v0073 = ncons(v0073);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    v0073 = Lnconc(nil, stack[-2], v0073);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    v0084 = v0073;
    goto v0063;
/* error exit handlers */
v0028:
    popv(4);
    return nil;
}



/* Code for lesspcdr */

static Lisp_Object CC_lesspcdr(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0013;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lesspcdr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0012 = v0001;
    v0013 = v0000;
/* end of prologue */
    v0013 = qcdr(v0013);
    v0012 = qcdr(v0012);
        return Llessp(nil, v0013, v0012);
}



/* Code for set!-global!-mode */

static Lisp_Object CC_setKglobalKmode(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for set-global-mode");
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
    v0010 = qvalue(elt(env, 1)); /* nil */
    v0010 = ncons(v0010);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0010; /* alglist!* */
    v0010 = stack[-2];
    qvalue(elt(env, 3)) = v0010; /* !*mode */
    stack[-3] = elt(env, 4); /* null */
    stack[-1] = elt(env, 5); /* setq */
    stack[0] = elt(env, 3); /* !*mode */
    v0010 = stack[-2];
    v0010 = Lmkquote(nil, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-4];
    v0010 = list3(stack[-1], stack[0], v0010);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    {
        Lisp_Object v0032 = stack[-3];
        popv(5);
        return list2(v0032, v0010);
    }
/* error exit handlers */
v0019:
    popv(5);
    return nil;
}



/* Code for setk */

static Lisp_Object CC_setk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0163, v0121, v0296;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setk");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0121 = v0000;
/* end of prologue */
    v0163 = v0121;
    if (!consp(v0163)) goto v0087;
    v0163 = v0121;
    v0296 = qcar(v0163);
    v0163 = elt(env, 1); /* evalargfn */
    v0163 = get(v0296, v0163);
    env = stack[-2];
    v0296 = v0163;
    v0163 = v0296;
    if (v0163 == nil) goto v0048;
    v0163 = v0121;
    stack[-1] = qcar(v0163);
    v0163 = v0296;
    v0121 = qcdr(v0121);
    v0163 = Lapply1(nil, v0163, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-2];
    v0121 = cons(stack[-1], v0163);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-2];
    v0163 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v0121, v0163);
    }

v0048:
    v0163 = v0121;
    v0296 = qcar(v0163);
    v0163 = elt(env, 2); /* rtype */
    v0296 = get(v0296, v0163);
    env = stack[-2];
    v0163 = elt(env, 3); /* matrix */
    if (v0296 == v0163) goto v0074;
    v0163 = v0121;
    stack[-1] = qcar(v0163);
    v0163 = v0121;
    v0163 = qcdr(v0163);
    fn = elt(env, 5); /* revlis */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-2];
    v0121 = cons(stack[-1], v0163);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-2];
    v0163 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v0121, v0163);
    }

v0074:
    v0163 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v0121, v0163);
    }

v0087:
    v0163 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v0121, v0163);
    }
/* error exit handlers */
v0223:
    popv(3);
    return nil;
}



/* Code for sf_member */

static Lisp_Object CC_sf_member(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0060, v0061;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sf_member");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0089:
    v0060 = stack[0];
    if (!consp(v0060)) goto v0051;
    v0060 = stack[0];
    v0060 = qcar(v0060);
    v0060 = (consp(v0060) ? nil : lisp_true);
    goto v0078;

v0078:
    if (v0060 == nil) goto v0009;
    v0060 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0060); }

v0009:
    v0061 = stack[-1];
    v0060 = stack[0];
    v0060 = qcar(v0060);
    v0060 = qcar(v0060);
    v0060 = qcar(v0060);
    if (equal(v0061, v0060)) goto v0070;
    v0060 = stack[0];
    v0060 = qcar(v0060);
    v0060 = qcar(v0060);
    v0060 = qcar(v0060);
    if (!consp(v0060)) goto v0025;
    v0061 = stack[-1];
    v0060 = stack[0];
    v0060 = qcar(v0060);
    v0060 = qcar(v0060);
    v0060 = qcar(v0060);
    v0060 = qcdr(v0060);
    fn = elt(env, 3); /* arglist_member */
    v0060 = (*qfn2(fn))(qenv(fn), v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    goto v0075;

v0075:
    if (!(v0060 == nil)) { popv(3); return onevalue(v0060); }
    v0061 = stack[-1];
    v0060 = stack[0];
    v0060 = qcar(v0060);
    v0060 = qcdr(v0060);
    v0060 = CC_sf_member(env, v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    if (!(v0060 == nil)) { popv(3); return onevalue(v0060); }
    v0061 = stack[-1];
    v0060 = stack[0];
    v0060 = qcdr(v0060);
    stack[-1] = v0061;
    stack[0] = v0060;
    goto v0089;

v0025:
    v0060 = qvalue(elt(env, 2)); /* nil */
    goto v0075;

v0070:
    v0060 = qvalue(elt(env, 1)); /* t */
    goto v0075;

v0051:
    v0060 = qvalue(elt(env, 1)); /* t */
    goto v0078;
/* error exit handlers */
v0111:
    popv(3);
    return nil;
}



/* Code for dl_get2 */

static Lisp_Object CC_dl_get2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0029, v0028, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dl_get2");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0029 = v0001;
    v0028 = v0000;
/* end of prologue */

v0018:
    v0047 = v0028;
    if (v0047 == nil) { popv(2); return onevalue(v0029); }
    v0047 = v0028;
    v0006 = qcar(v0047);
    v0047 = elt(env, 1); /* dummy */
    v0047 = get(v0006, v0047);
    env = stack[-1];
    if (v0047 == nil) goto v0083;
    v0047 = v0028;
    v0047 = qcdr(v0047);
    stack[0] = v0047;
    v0047 = v0028;
    v0028 = qcar(v0047);
    v0047 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 3); /* di_insert */
    v0047 = (*qfnn(fn))(qenv(fn), 3, v0028, v0029, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-1];
    v0029 = v0047;
    v0047 = stack[0];
    v0028 = v0047;
    goto v0018;

v0083:
    v0047 = v0028;
    v0047 = qcdr(v0047);
    v0028 = v0047;
    goto v0018;
/* error exit handlers */
v0069:
    popv(2);
    return nil;
}



/* Code for ilcm */

static Lisp_Object CC_ilcm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0016, v0165, v0076;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ilcm");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0165 = v0001;
    v0076 = v0000;
/* end of prologue */
    v0016 = v0076;
    v0015 = (Lisp_Object)1; /* 0 */
    if (v0016 == v0015) goto v0051;
    v0016 = v0165;
    v0015 = (Lisp_Object)1; /* 0 */
    v0015 = (v0016 == v0015 ? lisp_true : nil);
    goto v0078;

v0078:
    if (v0015 == nil) goto v0032;
    v0015 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0015); }

v0032:
    v0016 = v0076;
    v0015 = (Lisp_Object)17; /* 1 */
    if (v0016 == v0015) { popv(3); return onevalue(v0165); }
    v0016 = v0165;
    v0015 = (Lisp_Object)17; /* 1 */
    if (v0016 == v0015) { popv(3); return onevalue(v0076); }
    stack[-1] = v0076;
    stack[0] = v0165;
    v0015 = v0076;
    v0016 = v0165;
    v0015 = Lgcd(nil, v0015, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-2];
    v0015 = quot2(stack[0], v0015);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    {
        Lisp_Object v0138 = stack[-1];
        popv(3);
        return times2(v0138, v0015);
    }

v0051:
    v0015 = qvalue(elt(env, 1)); /* t */
    goto v0078;
/* error exit handlers */
v0112:
    popv(3);
    return nil;
}



/* Code for reverse!-num */

static Lisp_Object CC_reverseKnum(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0171, v0057;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reverse-num");
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
    v0057 = stack[0];
    v0171 = (Lisp_Object)1; /* 0 */
    if (v0057 == v0171) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0057 = stack[0];
    v0171 = (Lisp_Object)1; /* 0 */
    v0171 = (Lisp_Object)lessp2(v0057, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    v0171 = v0171 ? lisp_true : nil;
    env = stack[-2];
    if (v0171 == nil) goto v0084;
    v0171 = stack[0];
    stack[-1] = negate(v0171);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    v0171 = stack[0];
    v0171 = negate(v0171);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    fn = elt(env, 1); /* ilog2 */
    v0171 = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    v0171 = add1(v0171);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    fn = elt(env, 2); /* reverse!-num1 */
    v0171 = (*qfn2(fn))(qenv(fn), stack[-1], v0171);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    popv(3);
    return negate(v0171);

v0084:
    stack[-1] = stack[0];
    v0171 = stack[0];
    fn = elt(env, 1); /* ilog2 */
    v0171 = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    v0171 = add1(v0171);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    {
        Lisp_Object v0046 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* reverse!-num1 */
        return (*qfn2(fn))(qenv(fn), v0046, v0171);
    }
/* error exit handlers */
v0058:
    popv(3);
    return nil;
}



/* Code for readprogn */

static Lisp_Object MS_CDECL CC_readprogn(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0046;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "readprogn");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for readprogn");
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
    goto v0090;

v0090:
    fn = elt(env, 7); /* scan */
    v0058 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    v0058 = qvalue(elt(env, 1)); /* !*eoldelimp */
    if (v0058 == nil) goto v0039;
    v0046 = qvalue(elt(env, 2)); /* cursym!* */
    v0058 = elt(env, 3); /* !*semicol!* */
    if (v0046 == v0058) goto v0090;
    else goto v0039;

v0039:
    v0058 = elt(env, 4); /* group */
    fn = elt(env, 8); /* xread1 */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    v0058 = ncons(v0058);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    v0058 = Lnconc(nil, stack[0], v0058);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    stack[0] = v0058;
    v0046 = qvalue(elt(env, 2)); /* cursym!* */
    v0058 = elt(env, 5); /* !*rsqbkt!* */
    if (!(v0046 == v0058)) goto v0090;
    fn = elt(env, 7); /* scan */
    v0058 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    v0046 = elt(env, 6); /* progn */
    v0058 = stack[0];
    popv(2);
    return cons(v0046, v0058);
/* error exit handlers */
v0022:
    popv(2);
    return nil;
}



/* Code for ibalp_initwl */

static Lisp_Object CC_ibalp_initwl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0148, v0149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_initwl");
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
    v0148 = v0000;
/* end of prologue */
    stack[-4] = nil;
    stack[-2] = v0148;
    goto v0037;

v0037:
    v0148 = stack[-2];
    if (v0148 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v0148 = stack[-2];
    v0148 = qcar(v0148);
    stack[-1] = v0148;
    v0148 = (Lisp_Object)1; /* 0 */
    stack[-5] = v0148;
    v0148 = stack[-1];
    v0148 = qcar(v0148);
    stack[-3] = v0148;
    goto v0043;

v0043:
    v0149 = stack[-5];
    v0148 = (Lisp_Object)33; /* 2 */
    v0148 = Leqn(nil, v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-6];
    if (v0148 == nil) goto v0030;
    v0148 = qvalue(elt(env, 1)); /* nil */
    goto v0032;

v0032:
    if (v0148 == nil) goto v0009;
    v0148 = stack[-1];
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    stack[0] = qcdr(v0148);
    v0148 = stack[-3];
    v0149 = qcar(v0148);
    v0148 = stack[-1];
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcar(v0148);
    v0148 = cons(v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0148 = (*qfn2(fn))(qenv(fn), stack[0], v0148);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-6];
    v0148 = stack[-3];
    v0148 = qcar(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    stack[0] = qcdr(v0148);
    v0149 = stack[-1];
    v0148 = stack[-3];
    v0148 = qcar(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcar(v0148);
    v0148 = cons(v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0148 = (*qfn2(fn))(qenv(fn), stack[0], v0148);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-6];
    v0148 = stack[-5];
    v0148 = add1(v0148);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-6];
    stack[-5] = v0148;
    v0148 = stack[-3];
    v0148 = qcdr(v0148);
    stack[-3] = v0148;
    goto v0043;

v0009:
    v0148 = stack[-1];
    v0148 = qcdr(v0148);
    v0148 = qcar(v0148);
    stack[-3] = v0148;
    goto v0305;

v0305:
    v0149 = stack[-5];
    v0148 = (Lisp_Object)33; /* 2 */
    v0148 = Leqn(nil, v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-6];
    if (v0148 == nil) goto v0306;
    v0148 = qvalue(elt(env, 1)); /* nil */
    goto v0200;

v0200:
    if (v0148 == nil) goto v0307;
    v0148 = stack[-1];
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    stack[0] = qcdr(v0148);
    v0148 = stack[-3];
    v0149 = qcar(v0148);
    v0148 = stack[-1];
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcar(v0148);
    v0148 = cons(v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0148 = (*qfn2(fn))(qenv(fn), stack[0], v0148);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-6];
    v0148 = stack[-3];
    v0148 = qcar(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    stack[0] = qcdr(v0148);
    v0149 = stack[-1];
    v0148 = stack[-3];
    v0148 = qcar(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcar(v0148);
    v0148 = cons(v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0148 = (*qfn2(fn))(qenv(fn), stack[0], v0148);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-6];
    v0148 = stack[-5];
    v0148 = add1(v0148);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-6];
    stack[-5] = v0148;
    v0148 = stack[-3];
    v0148 = qcdr(v0148);
    stack[-3] = v0148;
    goto v0305;

v0307:
    v0149 = stack[-5];
    v0148 = (Lisp_Object)33; /* 2 */
    v0148 = (Lisp_Object)lessp2(v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    v0148 = v0148 ? lisp_true : nil;
    env = stack[-6];
    if (v0148 == nil) goto v0123;
    v0149 = stack[-1];
    v0148 = stack[-4];
    v0148 = cons(v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-6];
    stack[-4] = v0148;
    goto v0123;

v0123:
    v0148 = stack[-2];
    v0148 = qcdr(v0148);
    stack[-2] = v0148;
    goto v0037;

v0306:
    v0148 = stack[-3];
    goto v0200;

v0030:
    v0148 = stack[-3];
    goto v0032;
/* error exit handlers */
v0304:
    popv(7);
    return nil;
}



/* Code for poly!-minusp */

static Lisp_Object CC_polyKminusp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0032;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for poly-minusp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0019 = v0000;
/* end of prologue */

v0054:
    v0032 = v0019;
    if (v0032 == nil) goto v0063;
    v0032 = v0019;
    if (!consp(v0032)) goto v0090;
    v0032 = v0019;
    v0032 = qcar(v0032);
    v0032 = (consp(v0032) ? nil : lisp_true);
    goto v0013;

v0013:
    if (v0032 == nil) goto v0010;
        return Lminusp(nil, v0019);

v0010:
    v0019 = qcar(v0019);
    v0019 = qcdr(v0019);
    goto v0054;

v0090:
    v0032 = qvalue(elt(env, 2)); /* t */
    goto v0013;

v0063:
    v0019 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0019);
}



/* Code for ofsf_sacat */

static Lisp_Object MS_CDECL CC_ofsf_sacat(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0023, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0033, v0034, v0035;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_sacat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sacat");
#endif
    if (stack >= stacklimit)
    {
        push3(v0023,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0023);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0034 = v0023;
    v0035 = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0005 = stack[0];
    v0005 = qcdr(v0005);
    v0033 = qcar(v0005);
    v0005 = v0035;
    v0005 = qcdr(v0005);
    v0005 = qcar(v0005);
    if (equal(v0033, v0005)) goto v0011;
    v0005 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0005); }

v0011:
    v0005 = stack[0];
    v0005 = qcar(v0005);
    v0033 = v0035;
    v0033 = qcar(v0033);
    fn = elt(env, 3); /* ofsf_sacrel */
    v0005 = (*qfnn(fn))(qenv(fn), 3, v0005, v0033, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-1];
    v0034 = v0005;
    v0033 = v0034;
    v0005 = elt(env, 2); /* (drop keep keep1 keep2) */
    v0005 = Lmemq(nil, v0033, v0005);
    if (!(v0005 == nil)) { popv(2); return onevalue(v0034); }
    v0033 = v0034;
    v0005 = stack[0];
    v0005 = qcdr(v0005);
    v0005 = qcar(v0005);
    v0034 = qvalue(elt(env, 1)); /* nil */
    popv(2);
    return list3(v0033, v0005, v0034);
/* error exit handlers */
v0074:
    popv(2);
    return nil;
}



/* Code for ir2om */

static Lisp_Object CC_ir2om(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0080;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ir2om");
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
    v0080 = (Lisp_Object)33; /* 2 */
    qvalue(elt(env, 1)) = v0080; /* ind */
    v0080 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 2)) = v0080; /* indent */
    v0080 = elt(env, 3); /* "<OMOBJ>" */
    fn = elt(env, 7); /* printout */
    v0080 = (*qfn1(fn))(qenv(fn), v0080);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    v0080 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 8); /* indent!* */
    v0080 = (*qfn1(fn))(qenv(fn), v0080);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    v0080 = stack[0];
    fn = elt(env, 9); /* objectom */
    v0080 = (*qfn1(fn))(qenv(fn), v0080);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    v0080 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 8); /* indent!* */
    v0080 = (*qfn1(fn))(qenv(fn), v0080);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    v0080 = elt(env, 6); /* "</OMOBJ>" */
    fn = elt(env, 7); /* printout */
    v0080 = (*qfn1(fn))(qenv(fn), v0080);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    v0080 = nil;
    { popv(2); return onevalue(v0080); }
/* error exit handlers */
v0039:
    popv(2);
    return nil;
}



/* Code for cr!:minusp */

static Lisp_Object CC_crTminusp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0046, v0048;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cr:minusp");
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
    v0058 = v0000;
/* end of prologue */
    v0046 = v0058;
    v0046 = qcdr(v0046);
    v0046 = qcar(v0046);
    v0058 = qcdr(v0058);
    v0058 = qcdr(v0058);
    v0048 = v0046;
    v0046 = v0058;
    v0058 = v0048;
    if (!consp(v0058)) goto v0045;
    v0058 = v0046;
    v0058 = qcar(v0058);
    v0058 = (Lisp_Object)zerop(v0058);
    v0058 = v0058 ? lisp_true : nil;
    env = stack[0];
    if (v0058 == nil) goto v0043;
    v0058 = v0048;
    v0046 = qcar(v0058);
    v0058 = (Lisp_Object)1; /* 0 */
        popv(1);
        return Llessp(nil, v0046, v0058);

v0043:
    v0058 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0058); }

v0045:
    v0058 = v0046;
    v0058 = (Lisp_Object)zerop(v0058);
    v0058 = v0058 ? lisp_true : nil;
    env = stack[0];
    if (v0058 == nil) goto v0040;
    v0046 = v0048;
    v0058 = (Lisp_Object)1; /* 0 */
        popv(1);
        return Llessp(nil, v0046, v0058);

v0040:
    v0058 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0058); }
}



/* Code for xord_deglex */

static Lisp_Object CC_xord_deglex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0035, v0036, v0074;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xord_deglex");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0034 = stack[-1];
    v0035 = qcar(v0034);
    v0034 = (Lisp_Object)17; /* 1 */
    if (v0035 == v0034) goto v0027;
    v0034 = stack[0];
    v0035 = qcar(v0034);
    v0034 = (Lisp_Object)17; /* 1 */
    if (v0035 == v0034) goto v0080;
    v0034 = stack[-1];
    fn = elt(env, 3); /* xdegreemon */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-3];
    v0034 = stack[0];
    fn = elt(env, 3); /* xdegreemon */
    v0034 = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-3];
    v0074 = stack[-2];
    v0036 = v0034;
    v0035 = v0074;
    v0034 = v0036;
    if (equal(v0035, v0034)) goto v0007;
    v0034 = v0074;
    v0035 = v0036;
        popv(4);
        return Lgreaterp(nil, v0034, v0035);

v0007:
    v0035 = stack[-1];
    v0034 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); /* xord_lex */
        return (*qfn2(fn))(qenv(fn), v0035, v0034);
    }

v0080:
    v0034 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v0034); }

v0027:
    v0034 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0034); }
/* error exit handlers */
v0002:
    popv(4);
    return nil;
}



/* Code for fortranname */

static Lisp_Object CC_fortranname(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0055;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fortranname");
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
    v0056 = stack[0];
    v0056 = Lstringp(nil, v0056);
    env = stack[-1];
    if (v0056 == nil) goto v0080;
    v0056 = stack[0];
    {
        popv(2);
        fn = elt(env, 9); /* stringtoatom */
        return (*qfn1(fn))(qenv(fn), v0056);
    }

v0080:
    v0055 = stack[0];
    v0056 = qvalue(elt(env, 1)); /* !*notfortranfuns!* */
    v0056 = Lmemq(nil, v0055, v0056);
    if (v0056 == nil) goto v0012;
    v0056 = qvalue(elt(env, 2)); /* !*stdout!* */
    v0056 = qcdr(v0056);
    v0056 = Lwrs(nil, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-1];
    v0056 = elt(env, 3); /* "*** WARNING: " */
    v0056 = Lprinc(nil, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-1];
    v0056 = stack[0];
    v0056 = Lprin(nil, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-1];
    v0056 = elt(env, 4); /* " is not an intrinsic Fortran function" */
    v0056 = Lprinc(nil, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-1];
    v0056 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-1];
    goto v0012;

v0012:
    v0056 = qvalue(elt(env, 6)); /* !*double */
    if (v0056 == nil) goto v0004;
    v0055 = stack[0];
    v0056 = elt(env, 7); /* !*doublename!* */
    v0056 = get(v0055, v0056);
    if (v0056 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v0056); }

v0004:
    v0055 = stack[0];
    v0056 = elt(env, 8); /* !*fortranname!* */
    v0056 = get(v0055, v0056);
    if (v0056 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v0056); }
/* error exit handlers */
v0003:
    popv(2);
    return nil;
}



/* Code for physop2sq */

static Lisp_Object CC_physop2sq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0099, v0097, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physop2sq");
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

v0089:
    v0099 = stack[0];
    fn = elt(env, 5); /* physopp */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-2];
    if (v0099 == nil) goto v0078;
    v0097 = stack[0];
    v0099 = elt(env, 1); /* rvalue */
    v0099 = get(v0097, v0099);
    env = stack[-2];
    stack[-1] = v0099;
    if (v0099 == nil) goto v0013;
    v0099 = stack[-1];
    stack[0] = v0099;
    goto v0089;

v0013:
    v0099 = stack[0];
    if (symbolp(v0099)) goto v0043;
    v0099 = stack[0];
    v0097 = qcar(v0099);
    v0099 = elt(env, 2); /* psimpfn */
    v0099 = get(v0097, v0099);
    env = stack[-2];
    stack[-1] = v0099;
    if (v0099 == nil) goto v0106;
    v0097 = stack[-1];
    v0099 = stack[0];
    v0099 = Lapply1(nil, v0097, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-2];
    stack[-1] = v0099;
    fn = elt(env, 5); /* physopp */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-2];
    if (v0099 == nil) goto v0111;
    v0091 = stack[-1];
    v0097 = (Lisp_Object)17; /* 1 */
    v0099 = (Lisp_Object)17; /* 1 */
    v0099 = acons(v0091, v0097, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-2];
    v0097 = ncons(v0099);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    v0099 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0097, v0099);

v0111:
    v0099 = stack[-1];
    fn = elt(env, 6); /* physopsm!* */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    v0099 = qcdr(v0099);
    v0099 = qcar(v0099);
    { popv(3); return onevalue(v0099); }

v0106:
    v0099 = stack[0];
    v0097 = qcar(v0099);
    v0099 = elt(env, 3); /* opmtch */
    v0099 = get(v0097, v0099);
    env = stack[-2];
    if (v0099 == nil) goto v0109;
    v0099 = stack[0];
    fn = elt(env, 7); /* opmtch!* */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-2];
    stack[-1] = v0099;
    if (v0099 == nil) goto v0109;
    v0099 = stack[-1];
    stack[0] = v0099;
    goto v0089;

v0109:
    v0091 = stack[0];
    v0097 = (Lisp_Object)17; /* 1 */
    v0099 = (Lisp_Object)17; /* 1 */
    v0099 = acons(v0091, v0097, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-2];
    v0097 = ncons(v0099);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    v0099 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0097, v0099);

v0043:
    v0091 = stack[0];
    v0097 = (Lisp_Object)17; /* 1 */
    v0099 = (Lisp_Object)17; /* 1 */
    v0099 = acons(v0091, v0097, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-2];
    v0097 = ncons(v0099);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    v0099 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0097, v0099);

v0078:
    v0099 = stack[0];
    if (!consp(v0099)) goto v0305;
    v0099 = stack[0];
    v0097 = qcar(v0099);
    v0099 = elt(env, 4); /* !*sq */
    if (v0097 == v0099) goto v0102;
    v0099 = stack[0];
    fn = elt(env, 8); /* getphystype */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-2];
    if (v0099 == nil) goto v0310;
    v0099 = stack[0];
    fn = elt(env, 6); /* physopsm!* */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-2];
    stack[0] = v0099;
    goto v0089;

v0310:
    v0099 = stack[0];
    {
        popv(3);
        fn = elt(env, 9); /* simp */
        return (*qfn1(fn))(qenv(fn), v0099);
    }

v0102:
    v0099 = stack[0];
    v0099 = qcdr(v0099);
    v0099 = qcar(v0099);
    { popv(3); return onevalue(v0099); }

v0305:
    v0099 = stack[0];
    {
        popv(3);
        fn = elt(env, 9); /* simp */
        return (*qfn1(fn))(qenv(fn), v0099);
    }
/* error exit handlers */
v0195:
    popv(3);
    return nil;
}



setup_type const u15_setup[] =
{
    {"exptf",                   too_few_2,      CC_exptf,      wrong_no_2},
    {"cl_susiupdknowl",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiupdknowl},
    {"tobvarir",                CC_tobvarir,    too_many_1,    wrong_no_1},
    {"bc2a",                    CC_bc2a,        too_many_1,    wrong_no_1},
    {"listdiff",                too_few_2,      CC_listdiff,   wrong_no_2},
    {"inttovec1",               too_few_2,      CC_inttovec1,  wrong_no_2},
    {"cstimes",                 too_few_2,      CC_cstimes,    wrong_no_2},
    {"repasc",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_repasc},
    {"formsetq",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formsetq},
    {"th_match",                too_few_2,      CC_th_match,   wrong_no_2},
    {"general-expt-mod-p",      too_few_2,      CC_generalKexptKmodKp,wrong_no_2},
    {"simpqg",                  CC_simpqg,      too_many_1,    wrong_no_1},
    {"revalx",                  CC_revalx,      too_many_1,    wrong_no_1},
    {"setunion",                too_few_2,      CC_setunion,   wrong_no_2},
    {"vdp_zero?",               CC_vdp_zeroW,   too_many_1,    wrong_no_1},
    {"vdpred",                  CC_vdpred,      too_many_1,    wrong_no_1},
    {"freeoffl",                too_few_2,      CC_freeoffl,   wrong_no_2},
    {"triviallcm",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_triviallcm},
    {"listeval",                too_few_2,      CC_listeval,   wrong_no_2},
    {"indord2",                 too_few_2,      CC_indord2,    wrong_no_2},
    {"my_freeof",               too_few_2,      CC_my_freeof,  wrong_no_2},
    {"map__edges",              CC_map__edges,  too_many_1,    wrong_no_1},
    {"sfpx1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_sfpx1},
    {"mo_neworder",             CC_mo_neworder, too_many_1,    wrong_no_1},
    {"pv_times1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_pv_times1},
    {"rootrnd",                 CC_rootrnd,     too_many_1,    wrong_no_1},
    {"quotient-mod-p",          too_few_2,      CC_quotientKmodKp,wrong_no_2},
    {"rlis",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_rlis},
    {"mml2om",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mml2om},
    {"vevlcm",                  too_few_2,      CC_vevlcm,     wrong_no_2},
    {"oprinla",                 CC_oprinla,     too_many_1,    wrong_no_1},
    {"fortexp",                 CC_fortexp,     too_many_1,    wrong_no_1},
    {"command",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_command},
    {"dp_neg",                  CC_dp_neg,      too_many_1,    wrong_no_1},
    {"simp-prop-order",         too_few_2,      CC_simpKpropKorder,wrong_no_2},
    {"symbvarlst",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_symbvarlst},
    {"setqget",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_setqget},
    {"mk+mat+mult+mat",         too_few_2,      CC_mkLmatLmultLmat,wrong_no_2},
    {"ratpoly_lc",              CC_ratpoly_lc,  too_many_1,    wrong_no_1},
    {"getsetvars",              CC_getsetvars,  too_many_1,    wrong_no_1},
    {"merge-ind-vars",          too_few_2,      CC_mergeKindKvars,wrong_no_2},
    {"vdpsave",                 CC_vdpsave,     too_many_1,    wrong_no_1},
    {"prinlatom",               CC_prinlatom,   too_many_1,    wrong_no_1},
    {"insertparens",            CC_insertparens,too_many_1,    wrong_no_1},
    {"deleteall",               too_few_2,      CC_deleteall,  wrong_no_2},
    {"lesspcdr",                too_few_2,      CC_lesspcdr,   wrong_no_2},
    {"set-global-mode",         CC_setKglobalKmode,too_many_1, wrong_no_1},
    {"setk",                    too_few_2,      CC_setk,       wrong_no_2},
    {"sf_member",               too_few_2,      CC_sf_member,  wrong_no_2},
    {"dl_get2",                 too_few_2,      CC_dl_get2,    wrong_no_2},
    {"ilcm",                    too_few_2,      CC_ilcm,       wrong_no_2},
    {"reverse-num",             CC_reverseKnum, too_many_1,    wrong_no_1},
    {"readprogn",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_readprogn},
    {"ibalp_initwl",            CC_ibalp_initwl,too_many_1,    wrong_no_1},
    {"poly-minusp",             CC_polyKminusp, too_many_1,    wrong_no_1},
    {"ofsf_sacat",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_sacat},
    {"ir2om",                   CC_ir2om,       too_many_1,    wrong_no_1},
    {"cr:minusp",               CC_crTminusp,   too_many_1,    wrong_no_1},
    {"xord_deglex",             too_few_2,      CC_xord_deglex,wrong_no_2},
    {"fortranname",             CC_fortranname, too_many_1,    wrong_no_1},
    {"physop2sq",               CC_physop2sq,   too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u15", (two_args *)"12508 5192371 9895892", 0}
};

/* end of generated code */
