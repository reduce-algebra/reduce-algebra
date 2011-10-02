
/* $destdir\u31.c        Machine generated C code */

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


/* Code for cl_sitheo */

static Lisp_Object CC_cl_sitheo(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0017, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_sitheo");
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
    stack[-3] = nil;
    stack[-1] = nil;
    stack[0] = qvalue(elt(env, 1)); /* !*rlsiexpla */
    qvalue(elt(env, 1)) = nil; /* !*rlsiexpla */
    v0016 = qvalue(elt(env, 2)); /* !*rlsithok */
    if (v0016 == nil) goto v0019;
    v0016 = stack[-2];
    goto v0020;

v0020:
    qvalue(elt(env, 1)) = stack[0]; /* !*rlsiexpla */
    { popv(5); return onevalue(v0016); }

v0019:
    v0016 = stack[-2];
    if (v0016 == nil) goto v0021;
    v0016 = stack[-2];
    v0016 = qcar(v0016);
    stack[-3] = v0016;
    v0016 = stack[-2];
    v0016 = qcdr(v0016);
    stack[-2] = v0016;
    v0017 = stack[-3];
    v0016 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 7); /* cl_simplat */
    v0016 = (*qfn2(fn))(qenv(fn), v0017, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-4];
    v0018 = v0016;
    v0017 = v0018;
    v0016 = elt(env, 4); /* false */
    if (v0017 == v0016) goto v0023;
    v0017 = v0018;
    v0016 = elt(env, 6); /* true */
    if (v0017 == v0016) goto v0019;
    v0017 = v0018;
    v0016 = stack[-1];
    v0016 = cons(v0017, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-4];
    stack[-1] = v0016;
    goto v0019;

v0023:
    v0016 = elt(env, 5); /* inctheo */
    stack[-3] = v0016;
    v0016 = qvalue(elt(env, 3)); /* nil */
    stack[-2] = v0016;
    goto v0019;

v0021:
    v0017 = stack[-3];
    v0016 = elt(env, 5); /* inctheo */
    if (v0017 == v0016) goto v0024;
    v0016 = stack[-1];
    goto v0020;

v0024:
    v0016 = elt(env, 5); /* inctheo */
    goto v0020;
/* error exit handlers */
v0022:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[0]; /* !*rlsiexpla */
    popv(5);
    return nil;
}



/* Code for maxfrom */

static Lisp_Object CC_maxfrom(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0025)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0019;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxfrom");
#endif
    if (stack >= stacklimit)
    {
        push2(v0025,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0025);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0029 = v0025;
    v0019 = v0000;
/* end of prologue */
    stack[0] = v0019;
    v0019 = add1(v0029);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-1];
    v0029 = (Lisp_Object)1; /* 0 */
    {
        Lisp_Object v0031 = stack[0];
        popv(2);
        fn = elt(env, 1); /* maxfrom1 */
        return (*qfnn(fn))(qenv(fn), 3, v0031, v0019, v0029);
    }
/* error exit handlers */
v0030:
    popv(2);
    return nil;
}



/* Code for expf */

static Lisp_Object CC_expf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0025)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0059;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expf");
#endif
    if (stack >= stacklimit)
    {
        push2(v0025,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0025);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0025;
    stack[-2] = v0000;
/* end of prologue */
    v0058 = stack[-2];
    if (v0058 == nil) goto v0002;
    v0059 = stack[-2];
    v0058 = (Lisp_Object)17; /* 1 */
    if (v0059 == v0058) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0058 = stack[-2];
    if (!consp(v0058)) goto v0060;
    v0058 = stack[-2];
    if (!consp(v0058)) goto v0061;
    v0058 = stack[-2];
    v0058 = qcar(v0058);
    v0058 = (consp(v0058) ? nil : lisp_true);
    goto v0062;

v0062:
    if (v0058 == nil) goto v0063;
    v0059 = stack[-2];
    v0058 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* !:expt */
        return (*qfn2(fn))(qenv(fn), v0059, v0058);
    }

v0063:
    v0058 = stack[-2];
    v0058 = qcdr(v0058);
    if (v0058 == nil) goto v0004;
    v0059 = stack[-2];
    v0058 = stack[-1];
    {
        popv(5);
        fn = elt(env, 4); /* mksp!* */
        return (*qfn2(fn))(qenv(fn), v0059, v0058);
    }

v0004:
    v0058 = stack[-2];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0059 = qcdr(v0058);
    v0058 = stack[-1];
    v0058 = times2(v0059, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    stack[0] = v0058;
    v0059 = stack[0];
    v0058 = (Lisp_Object)1; /* 0 */
    v0058 = (Lisp_Object)greaterp2(v0059, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    v0058 = v0058 ? lisp_true : nil;
    env = stack[-4];
    if (v0058 == nil) goto v0065;
    v0058 = stack[-2];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    if (!consp(v0058)) goto v0066;
    v0058 = stack[-2];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0058 = (consp(v0058) ? nil : lisp_true);
    v0058 = (v0058 == nil ? lisp_true : nil);
    goto v0067;

v0067:
    if (v0058 == nil) goto v0065;
    v0058 = stack[-2];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0059 = qcar(v0058);
    v0058 = stack[0];
    fn = elt(env, 5); /* exptf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0059, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    v0058 = stack[-2];
    v0058 = qcar(v0058);
    v0059 = qcdr(v0058);
    v0058 = stack[-1];
    v0058 = CC_expf(env, v0059, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    {
        Lisp_Object v0068 = stack[0];
        popv(5);
        fn = elt(env, 6); /* multf */
        return (*qfn2(fn))(qenv(fn), v0068, v0058);
    }

v0065:
    v0058 = stack[-2];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    stack[-3] = qcar(v0058);
    v0058 = stack[-2];
    v0058 = qcar(v0058);
    v0059 = qcdr(v0058);
    v0058 = stack[-1];
    v0058 = CC_expf(env, v0059, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    v0058 = acons(stack[-3], stack[0], v0058);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    popv(5);
    return ncons(v0058);

v0066:
    v0058 = qvalue(elt(env, 1)); /* nil */
    goto v0067;

v0061:
    v0058 = qvalue(elt(env, 2)); /* t */
    goto v0062;

v0060:
    stack[0] = (Lisp_Object)17; /* 1 */
    v0058 = stack[-1];
    v0058 = negate(v0058);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    v0058 = Lexpt(nil, stack[-2], v0058);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    {
        Lisp_Object v0069 = stack[0];
        popv(5);
        fn = elt(env, 7); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v0069, v0058);
    }

v0002:
    v0058 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0058); }
/* error exit handlers */
v0064:
    popv(5);
    return nil;
}



/* Code for mk!+real!+inner!+product */

static Lisp_Object CC_mkLrealLinnerLproduct(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0025)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076, v0077;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+real+inner+product");
#endif
    if (stack >= stacklimit)
    {
        push2(v0025,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0025);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0025;
    stack[-3] = v0000;
/* end of prologue */
    v0076 = stack[-3];
    fn = elt(env, 6); /* get!+vec!+dim */
    stack[0] = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    v0076 = stack[-2];
    fn = elt(env, 6); /* get!+vec!+dim */
    v0076 = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    if (equal(stack[0], v0076)) goto v0079;
    v0076 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v0076 == nil)) goto v0060;
    v0076 = elt(env, 2); /* "wrong dimensions in innerproduct" */
    fn = elt(env, 7); /* lprie */
    v0076 = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    goto v0060;

v0060:
    v0076 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    goto v0079;

v0079:
    v0077 = qvalue(elt(env, 3)); /* nil */
    v0076 = (Lisp_Object)17; /* 1 */
    v0076 = cons(v0077, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    stack[0] = v0076;
    v0076 = (Lisp_Object)17; /* 1 */
    stack[-4] = v0076;
    goto v0080;

v0080:
    v0076 = stack[-3];
    fn = elt(env, 6); /* get!+vec!+dim */
    v0077 = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    v0076 = stack[-4];
    v0076 = difference2(v0077, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    v0076 = Lminusp(nil, v0076);
    env = stack[-5];
    if (v0076 == nil) goto v0081;
    v0076 = qvalue(elt(env, 4)); /* t */
    stack[-1] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v0076; /* !*sub2 */
    v0076 = stack[0];
    fn = elt(env, 8); /* subs2 */
    v0076 = (*qfn1(fn))(qenv(fn), v0076);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-5];
    stack[0] = v0076;
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0081:
    stack[-1] = stack[0];
    v0077 = stack[-3];
    v0076 = stack[-4];
    fn = elt(env, 9); /* get!+vec!+entry */
    stack[0] = (*qfn2(fn))(qenv(fn), v0077, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    v0077 = stack[-2];
    v0076 = stack[-4];
    fn = elt(env, 9); /* get!+vec!+entry */
    v0076 = (*qfn2(fn))(qenv(fn), v0077, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    fn = elt(env, 10); /* multsq */
    v0076 = (*qfn2(fn))(qenv(fn), stack[0], v0076);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    fn = elt(env, 11); /* addsq */
    v0076 = (*qfn2(fn))(qenv(fn), stack[-1], v0076);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    stack[0] = v0076;
    v0076 = stack[-4];
    v0076 = add1(v0076);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    stack[-4] = v0076;
    goto v0080;
/* error exit handlers */
v0082:
    env = stack[-5];
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    popv(6);
    return nil;
v0078:
    popv(6);
    return nil;
}



/* Code for cl_susiupdknowl2 */

static Lisp_Object MS_CDECL CC_cl_susiupdknowl2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0025,
                         Lisp_Object v0006, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0097, v0098, v0099, v0100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_susiupdknowl2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susiupdknowl2");
#endif
    if (stack >= stacklimit)
    {
        push3(v0006,v0025,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0025,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0006;
    stack[-5] = v0025;
    stack[-6] = v0000;
/* end of prologue */
    stack[-3] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    v0097 = stack[-5];
    stack[-2] = v0097;
    v0097 = qvalue(elt(env, 1)); /* nil */
    v0100 = v0097;
    v0097 = stack[-5];
    v0099 = v0097;
    goto v0030;

v0030:
    v0097 = v0099;
    if (v0097 == nil) goto v0057;
    v0097 = v0099;
    v0097 = qcar(v0097);
    v0098 = stack[-6];
    if (!(equal(v0098, v0097))) goto v0101;
    v0097 = lisp_true;
    v0100 = v0097;
    goto v0101;

v0101:
    v0097 = v0099;
    v0097 = qcdr(v0097);
    v0099 = v0097;
    goto v0030;

v0057:
    v0097 = v0100;
    if (!(v0097 == nil)) { Lisp_Object res = stack[-5]; popv(9); return onevalue(res); }

v0102:
    v0097 = stack[-2];
    if (v0097 == nil) goto v0103;
    v0097 = stack[-2];
    v0097 = qcar(v0097);
    stack[-7] = v0097;
    v0097 = stack[-2];
    v0097 = qcdr(v0097);
    stack[-2] = v0097;
    v0098 = stack[-7];
    v0097 = stack[-6];
    fn = elt(env, 4); /* rl_susibin */
    v0097 = (*qfn2(fn))(qenv(fn), v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-8];
    stack[-3] = v0097;
    v0098 = stack[-3];
    v0097 = elt(env, 2); /* false */
    if (v0098 == v0097) goto v0105;
    v0099 = stack[-3];
    v0098 = stack[-5];
    v0097 = stack[-7];
    fn = elt(env, 5); /* cl_susiinter */
    v0097 = (*qfnn(fn))(qenv(fn), 3, v0099, v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-8];
    stack[-3] = v0097;
    v0098 = stack[0];
    v0097 = stack[-3];
    v0097 = qcdr(v0097);
    v0097 = qcar(v0097);
    v0097 = Lnconc(nil, v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-8];
    stack[0] = v0097;
    v0097 = stack[-3];
    v0097 = qcar(v0097);
    stack[-5] = v0097;
    v0097 = stack[-3];
    v0097 = qcdr(v0097);
    v0097 = qcdr(v0097);
    v0097 = qcar(v0097);
    if (!(v0097 == nil)) goto v0106;

v0106:
    v0097 = stack[-3];
    v0097 = qcdr(v0097);
    v0097 = qcdr(v0097);
    v0097 = qcdr(v0097);
    v0097 = qcar(v0097);
    if (v0097 == nil) goto v0102;
    v0097 = qvalue(elt(env, 3)); /* t */
    stack[-1] = v0097;
    v0097 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0097;
    goto v0102;

v0105:
    v0097 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0097;
    goto v0102;

v0103:
    v0098 = stack[-3];
    v0097 = elt(env, 2); /* false */
    if (v0098 == v0097) goto v0107;
    v0097 = stack[-1];
    if (!(v0097 == nil)) goto v0108;
    v0098 = stack[-6];
    v0097 = stack[-5];
    v0097 = cons(v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-8];
    stack[-5] = v0097;
    goto v0108;

v0108:
    v0097 = stack[0];
    if (v0097 == nil) { Lisp_Object res = stack[-5]; popv(9); return onevalue(res); }
    v0097 = stack[0];
    v0099 = qcar(v0097);
    v0098 = stack[-5];
    v0097 = stack[-4];
    v0097 = CC_cl_susiupdknowl2(env, 3, v0099, v0098, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-8];
    stack[-5] = v0097;
    v0098 = stack[-5];
    v0097 = elt(env, 2); /* false */
    if (v0098 == v0097) goto v0109;
    v0097 = stack[0];
    v0097 = qcdr(v0097);
    stack[0] = v0097;
    goto v0108;

v0109:
    v0097 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0097;
    goto v0108;

v0107:
    v0097 = elt(env, 2); /* false */
    { popv(9); return onevalue(v0097); }
/* error exit handlers */
v0104:
    popv(9);
    return nil;
}



/* Code for ofsf_sacrel */

static Lisp_Object MS_CDECL CC_ofsf_sacrel(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0025,
                         Lisp_Object v0006, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0015, v0055, v0056;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_sacrel");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sacrel");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0014 = v0006;
    v0055 = v0025;
    v0056 = v0000;
/* end of prologue */
    v0015 = v0014;
    v0014 = elt(env, 1); /* or */
    if (v0015 == v0014) goto v0019;
    v0014 = v0056;
    v0015 = v0055;
    {
        fn = elt(env, 2); /* ofsf_sacrel!-and */
        return (*qfn2(fn))(qenv(fn), v0014, v0015);
    }

v0019:
    v0014 = v0056;
    v0015 = v0055;
    {
        fn = elt(env, 3); /* ofsf_sacrel!-or */
        return (*qfn2(fn))(qenv(fn), v0014, v0015);
    }
}



/* Code for setfuncsnaryrd */

static Lisp_Object MS_CDECL CC_setfuncsnaryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0116, v0075;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setfuncsnaryrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setfuncsnaryrd");
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
    v0116 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-1];
    stack[0] = v0116;
    v0116 = stack[0];
    v0116 = Lconsp(nil, v0116);
    env = stack[-1];
    if (v0116 == nil) goto v0001;
    v0116 = stack[0];
    v0116 = qcdr(v0116);
    v0116 = qcar(v0116);
    if (v0116 == nil) goto v0001;
    v0116 = stack[0];
    v0116 = qcdr(v0116);
    v0116 = qcar(v0116);
    v0116 = qcar(v0116);
    v0116 = qcdr(v0116);
    v0116 = qcar(v0116);
    v0075 = Lintern(nil, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-1];
    v0116 = elt(env, 1); /* multiset */
    if (!(v0075 == v0116)) goto v0001;
    v0116 = elt(env, 1); /* multiset */
    qvalue(elt(env, 2)) = v0116; /* mmlatts */
    goto v0001;

v0001:
    v0116 = stack[0];
    if (v0116 == nil) goto v0063;
    v0116 = CC_setfuncsnaryrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    {
        Lisp_Object v0050 = stack[0];
        popv(2);
        return cons(v0050, v0116);
    }

v0063:
    v0116 = nil;
    { popv(2); return onevalue(v0116); }
/* error exit handlers */
v0011:
    popv(2);
    return nil;
}



/* Code for indexsymmetrize */

static Lisp_Object CC_indexsymmetrize(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0119, v0004, v0005;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indexsymmetrize");
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
    v0119 = stack[-2];
    v0004 = qcar(v0119);
    v0119 = elt(env, 1); /* indxsymmetrize */
    v0119 = get(v0004, v0119);
    env = stack[-4];
    stack[-3] = v0119;
    v0119 = (Lisp_Object)17; /* 1 */
    stack[0] = v0119;
    v0004 = (Lisp_Object)17; /* 1 */
    v0119 = stack[-2];
    v0119 = qcdr(v0119);
    v0119 = cons(v0004, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-4];
    stack[-1] = v0119;
    goto v0020;

v0020:
    v0119 = stack[-3];
    if (v0119 == nil) goto v0015;
    v0119 = stack[-3];
    v0004 = qcar(v0119);
    v0119 = stack[-1];
    v0119 = qcdr(v0119);
    v0119 = Lapply1(nil, v0004, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-4];
    stack[-1] = v0119;
    v0119 = stack[-1];
    if (v0119 == nil) goto v0051;
    v0119 = stack[-1];
    v0004 = qcar(v0119);
    v0119 = stack[0];
    v0119 = times2(v0004, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-4];
    stack[0] = v0119;
    v0119 = stack[-3];
    v0119 = qcdr(v0119);
    stack[-3] = v0119;
    goto v0020;

v0051:
    v0119 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v0119); }

v0015:
    v0005 = stack[0];
    v0119 = stack[-2];
    v0004 = qcar(v0119);
    v0119 = stack[-1];
    v0119 = qcdr(v0119);
    popv(5);
    return list2star(v0005, v0004, v0119);
/* error exit handlers */
v0018:
    popv(5);
    return nil;
}



/* Code for applsmacro */

static Lisp_Object MS_CDECL CC_applsmacro(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0025,
                         Lisp_Object v0006, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0157, v0158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "applsmacro");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for applsmacro");
#endif
    if (stack >= stacklimit)
    {
        push3(v0006,v0025,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0025,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0006;
    stack[-7] = v0025;
    v0158 = v0000;
/* end of prologue */
    stack[-6] = nil;
    stack[-5] = qvalue(elt(env, 1)); /* varlist */
    qvalue(elt(env, 1)) = nil; /* varlist */
    v0157 = v0158;
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    qvalue(elt(env, 1)) = v0157; /* varlist */
    v0157 = v0158;
    v0157 = qcdr(v0157);
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    stack[-8] = v0157;
    v0157 = qvalue(elt(env, 1)); /* varlist */
    stack[-1] = Llength(nil, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = stack[-7];
    v0157 = Llength(nil, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    if (equal(stack[-1], v0157)) goto v0030;
    v0158 = elt(env, 2); /* "Argument mismatch for SMACRO" */
    v0157 = stack[0];
    v0157 = list2(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0158 = v0157;
    v0157 = v0158;
    qvalue(elt(env, 3)) = v0157; /* errmsg!* */
    v0157 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v0157 == nil)) goto v0117;
    v0157 = v0158;
    fn = elt(env, 8); /* lprie */
    v0157 = (*qfn1(fn))(qenv(fn), v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    goto v0117;

v0117:
    v0157 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    goto v0030;

v0030:
    v0157 = stack[-7];
    fn = elt(env, 9); /* no!-side!-effect!-listp */
    v0157 = (*qfn1(fn))(qenv(fn), v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    if (!(v0157 == nil)) goto v0119;
    v0158 = qvalue(elt(env, 1)); /* varlist */
    v0157 = stack[-8];
    fn = elt(env, 10); /* one!-entry!-listp */
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    if (!(v0157 == nil)) goto v0119;
    v0157 = qvalue(elt(env, 1)); /* varlist */
    v0158 = Llength(nil, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = (Lisp_Object)17; /* 1 */
    v0157 = (Lisp_Object)greaterp2(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    v0157 = v0157 ? lisp_true : nil;
    env = stack[-9];
    if (v0157 == nil) goto v0102;
    v0157 = qvalue(elt(env, 1)); /* varlist */
    stack[-4] = v0157;
    v0157 = stack[-4];
    if (v0157 == nil) goto v0078;
    v0157 = stack[-4];
    v0157 = qcar(v0157);
    stack[0] = v0157;
    v0157 = elt(env, 6); /* g */
    v0157 = Lgensym1(nil, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = cons(stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = ncons(v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    stack[-2] = v0157;
    stack[-3] = v0157;
    goto v0046;

v0046:
    v0157 = stack[-4];
    v0157 = qcdr(v0157);
    stack[-4] = v0157;
    v0157 = stack[-4];
    if (v0157 == nil) goto v0160;
    stack[-1] = stack[-2];
    v0157 = stack[-4];
    v0157 = qcar(v0157);
    stack[0] = v0157;
    v0157 = elt(env, 6); /* g */
    v0157 = Lgensym1(nil, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = cons(stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = ncons(v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = Lrplacd(nil, stack[-1], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = stack[-2];
    v0157 = qcdr(v0157);
    stack[-2] = v0157;
    goto v0046;

v0160:
    v0157 = stack[-3];
    goto v0045;

v0045:
    stack[0] = v0157;
    v0158 = stack[0];
    v0157 = stack[-8];
    fn = elt(env, 11); /* subla!-q */
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    stack[-8] = v0157;
    v0157 = stack[0];
    stack[-3] = v0157;
    v0157 = stack[-3];
    if (v0157 == nil) goto v0161;
    v0157 = stack[-3];
    v0157 = qcar(v0157);
    v0157 = qcdr(v0157);
    v0157 = ncons(v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    stack[-1] = v0157;
    stack[-2] = v0157;
    goto v0162;

v0162:
    v0157 = stack[-3];
    v0157 = qcdr(v0157);
    stack[-3] = v0157;
    v0157 = stack[-3];
    if (v0157 == nil) goto v0163;
    stack[0] = stack[-1];
    v0157 = stack[-3];
    v0157 = qcar(v0157);
    v0157 = qcdr(v0157);
    v0157 = ncons(v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = Lrplacd(nil, stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = stack[-1];
    v0157 = qcdr(v0157);
    stack[-1] = v0157;
    goto v0162;

v0163:
    v0157 = stack[-2];
    goto v0033;

v0033:
    qvalue(elt(env, 1)) = v0157; /* varlist */
    goto v0102;

v0102:
    v0157 = stack[-7];
    stack[-1] = v0157;
    goto v0164;

v0164:
    v0157 = stack[-1];
    if (v0157 == nil) goto v0165;
    v0157 = stack[-1];
    v0157 = qcar(v0157);
    stack[0] = v0157;
    v0157 = stack[0];
    fn = elt(env, 12); /* no!-side!-effectp */
    v0157 = (*qfn1(fn))(qenv(fn), v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    if (!(v0157 == nil)) goto v0166;
    v0157 = qvalue(elt(env, 1)); /* varlist */
    v0158 = qcar(v0157);
    v0157 = stack[-8];
    fn = elt(env, 13); /* one!-entryp */
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    if (!(v0157 == nil)) goto v0166;
    stack[-2] = stack[-6];
    v0157 = qvalue(elt(env, 1)); /* varlist */
    v0158 = qcar(v0157);
    v0157 = stack[0];
    v0157 = cons(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = ncons(v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = Lnconc(nil, stack[-2], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    stack[-6] = v0157;
    goto v0167;

v0167:
    v0157 = qvalue(elt(env, 1)); /* varlist */
    v0157 = qcdr(v0157);
    qvalue(elt(env, 1)) = v0157; /* varlist */
    v0157 = stack[-1];
    v0157 = qcdr(v0157);
    stack[-1] = v0157;
    goto v0164;

v0166:
    v0157 = qvalue(elt(env, 1)); /* varlist */
    v0158 = qcar(v0157);
    v0157 = stack[0];
    v0157 = cons(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0158 = ncons(v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = stack[-8];
    fn = elt(env, 11); /* subla!-q */
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    stack[-8] = v0157;
    goto v0167;

v0165:
    v0157 = stack[-6];
    if (v0157 == nil) goto v0168;
    stack[-4] = elt(env, 7); /* lambda */
    v0157 = stack[-6];
    stack[-3] = v0157;
    v0157 = stack[-3];
    if (v0157 == nil) goto v0169;
    v0157 = stack[-3];
    v0157 = qcar(v0157);
    v0157 = qcar(v0157);
    v0157 = ncons(v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    stack[-1] = v0157;
    stack[-2] = v0157;
    goto v0170;

v0170:
    v0157 = stack[-3];
    v0157 = qcdr(v0157);
    stack[-3] = v0157;
    v0157 = stack[-3];
    if (v0157 == nil) goto v0171;
    stack[0] = stack[-1];
    v0157 = stack[-3];
    v0157 = qcar(v0157);
    v0157 = qcar(v0157);
    v0157 = ncons(v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = Lrplacd(nil, stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = stack[-1];
    v0157 = qcdr(v0157);
    stack[-1] = v0157;
    goto v0170;

v0171:
    v0157 = stack[-2];
    v0158 = v0157;
    goto v0172;

v0172:
    v0157 = stack[-8];
    stack[-3] = list3(stack[-4], v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = stack[-6];
    stack[-4] = v0157;
    v0157 = stack[-4];
    if (v0157 == nil) goto v0173;
    v0157 = stack[-4];
    v0157 = qcar(v0157);
    v0157 = qcdr(v0157);
    v0157 = ncons(v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    stack[-1] = v0157;
    stack[-2] = v0157;
    goto v0174;

v0174:
    v0157 = stack[-4];
    v0157 = qcdr(v0157);
    stack[-4] = v0157;
    v0157 = stack[-4];
    if (v0157 == nil) goto v0175;
    stack[0] = stack[-1];
    v0157 = stack[-4];
    v0157 = qcar(v0157);
    v0157 = qcdr(v0157);
    v0157 = ncons(v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = Lrplacd(nil, stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = stack[-1];
    v0157 = qcdr(v0157);
    stack[-1] = v0157;
    goto v0174;

v0175:
    v0157 = stack[-2];
    goto v0176;

v0176:
    v0157 = cons(stack[-3], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    stack[0] = v0157;
    v0157 = stack[0];
    goto v0086;

v0086:
    qvalue(elt(env, 1)) = stack[-5]; /* varlist */
    { popv(10); return onevalue(v0157); }

v0173:
    v0157 = qvalue(elt(env, 5)); /* nil */
    goto v0176;

v0169:
    v0157 = qvalue(elt(env, 5)); /* nil */
    v0158 = v0157;
    goto v0172;

v0168:
    v0157 = stack[-8];
    goto v0086;

v0161:
    v0157 = qvalue(elt(env, 5)); /* nil */
    goto v0033;

v0078:
    v0157 = qvalue(elt(env, 5)); /* nil */
    goto v0045;

v0119:
    v0158 = qvalue(elt(env, 1)); /* varlist */
    v0157 = stack[-7];
    fn = elt(env, 14); /* pair */
    v0158 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    v0157 = stack[-8];
    fn = elt(env, 11); /* subla!-q */
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-9];
    goto v0086;
/* error exit handlers */
v0159:
    env = stack[-9];
    qvalue(elt(env, 1)) = stack[-5]; /* varlist */
    popv(10);
    return nil;
}



/* Code for reduce */

static Lisp_Object CC_reduce(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0025)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011, v0050, v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce");
#endif
    if (stack >= stacklimit)
    {
        push2(v0025,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0025);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0025;
    v0011 = v0000;
/* end of prologue */
    stack[0] = v0011;
    v0011 = qvalue(elt(env, 1)); /* !*yyy */
    if (v0011 == nil) goto v0086;
    v0050 = stack[0];
    v0011 = stack[-1];
    fn = elt(env, 3); /* reduce!-ratios */
    v0011 = (*qfn2(fn))(qenv(fn), v0050, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    stack[0] = v0011;
    goto v0086;

v0086:
    v0011 = stack[-1];
    fn = elt(env, 4); /* set!-weights */
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    stack[-2] = v0011;
    v0011 = qvalue(elt(env, 2)); /* !*xxx */
    if (v0011 == nil) goto v0179;
    v0051 = stack[0];
    v0050 = stack[-1];
    v0011 = stack[-2];
    fn = elt(env, 5); /* reduce!-columns */
    v0011 = (*qfnn(fn))(qenv(fn), 3, v0051, v0050, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    stack[0] = v0011;
    goto v0179;

v0179:
    v0011 = qvalue(elt(env, 2)); /* !*xxx */
    if (v0011 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0051 = stack[0];
    v0050 = stack[-1];
    v0011 = stack[-2];
    fn = elt(env, 6); /* reduce!-weights */
    v0011 = (*qfnn(fn))(qenv(fn), 3, v0051, v0050, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    stack[0] = v0011;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
/* error exit handlers */
v0178:
    popv(4);
    return nil;
}



/* Code for fs!:make!-nullangle */

static Lisp_Object MS_CDECL CC_fsTmakeKnullangle(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071, v0063, v0052;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "fs:make-nullangle");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:make-nullangle");
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
    v0071 = (Lisp_Object)113; /* 7 */
    v0071 = Lmkvect(nil, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-2];
    stack[-1] = v0071;
    v0071 = (Lisp_Object)1; /* 0 */
    stack[0] = v0071;
    goto v0057;

v0057:
    v0063 = (Lisp_Object)113; /* 7 */
    v0071 = stack[0];
    v0071 = difference2(v0063, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-2];
    v0071 = Lminusp(nil, v0071);
    env = stack[-2];
    if (!(v0071 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0052 = stack[-1];
    v0063 = stack[0];
    v0071 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v0052 + (CELL-TAG_VECTOR) + ((int32_t)v0063/(16/CELL))) = v0071;
    v0071 = stack[0];
    v0071 = add1(v0071);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-2];
    stack[0] = v0071;
    goto v0057;
/* error exit handlers */
v0117:
    popv(3);
    return nil;
}



/* Code for red!=hide */

static Lisp_Object CC_redMhide(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0180, v0074;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red=hide");
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
    v0180 = v0000;
/* end of prologue */
    stack[-5] = v0180;
    v0180 = stack[-5];
    if (v0180 == nil) goto v0026;
    v0180 = stack[-5];
    v0180 = qcar(v0180);
    stack[-1] = v0180;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v0180 = stack[-1];
    v0180 = qcar(v0180);
    fn = elt(env, 2); /* mo_neg */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-6];
    fn = elt(env, 3); /* mo_times_ei */
    v0074 = (*qfn2(fn))(qenv(fn), stack[0], v0180);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-6];
    v0180 = stack[-1];
    v0180 = qcdr(v0180);
    v0180 = cons(v0074, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-6];
    v0180 = ncons(v0180);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-6];
    stack[-3] = v0180;
    stack[-4] = v0180;
    goto v0020;

v0020:
    v0180 = stack[-5];
    v0180 = qcdr(v0180);
    stack[-5] = v0180;
    v0180 = stack[-5];
    if (v0180 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[-2] = stack[-3];
    v0180 = stack[-5];
    v0180 = qcar(v0180);
    stack[-1] = v0180;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v0180 = stack[-1];
    v0180 = qcar(v0180);
    fn = elt(env, 2); /* mo_neg */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-6];
    fn = elt(env, 3); /* mo_times_ei */
    v0074 = (*qfn2(fn))(qenv(fn), stack[0], v0180);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-6];
    v0180 = stack[-1];
    v0180 = qcdr(v0180);
    v0180 = cons(v0074, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-6];
    v0180 = ncons(v0180);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-6];
    v0180 = Lrplacd(nil, stack[-2], v0180);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-6];
    v0180 = stack[-3];
    v0180 = qcdr(v0180);
    stack[-3] = v0180;
    goto v0020;

v0026:
    v0180 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0180); }
/* error exit handlers */
v0037:
    popv(7);
    return nil;
}



/* Code for taylorp */

static Lisp_Object CC_taylorp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0101;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for taylorp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0101 = v0000;
/* end of prologue */
    v0054 = v0101;
    if (!consp(v0054)) goto v0156;
    v0054 = v0101;
    v0054 = qcar(v0054);
    if (!consp(v0054)) goto v0060;
    v0054 = v0101;
    v0054 = qcar(v0054);
    v0054 = qcar(v0054);
    v0101 = elt(env, 1); /* taylor */
        return Lflagp(nil, v0054, v0101);

v0060:
    v0054 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0054);

v0156:
    v0054 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0054);
}



/* Code for ofsf_at2ir */

static Lisp_Object CC_ofsf_at2ir(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0025)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0183, v0044, v0067;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_at2ir");
#endif
    if (stack >= stacklimit)
    {
        push2(v0025,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0025);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0025;
    v0044 = v0000;
/* end of prologue */
    v0183 = v0044;
    v0183 = qcar(v0183);
    stack[-4] = v0183;
    v0183 = v0044;
    v0183 = qcdr(v0183);
    v0183 = qcar(v0183);
    stack[-2] = v0183;
    stack[0] = v0183;
    goto v0019;

v0019:
    v0183 = stack[0];
    if (!consp(v0183)) goto v0060;
    v0183 = stack[0];
    v0183 = qcar(v0183);
    v0183 = (consp(v0183) ? nil : lisp_true);
    goto v0112;

v0112:
    if (v0183 == nil) goto v0030;
    stack[-1] = stack[-2];
    v0183 = stack[0];
    fn = elt(env, 3); /* negf */
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-5];
    fn = elt(env, 4); /* addf */
    v0183 = (*qfn2(fn))(qenv(fn), stack[-1], v0183);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-5];
    stack[-2] = v0183;
    v0183 = stack[-2];
    fn = elt(env, 5); /* sfto_dcontentf */
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-5];
    stack[-1] = v0183;
    v0044 = stack[-2];
    v0183 = stack[-1];
    fn = elt(env, 6); /* quotf */
    v0183 = (*qfn2(fn))(qenv(fn), v0044, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-5];
    stack[-2] = v0183;
    v0044 = stack[0];
    v0183 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0044, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-5];
    v0044 = stack[-1];
    v0183 = (Lisp_Object)17; /* 1 */
    v0183 = cons(v0044, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-5];
    fn = elt(env, 7); /* invsq */
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-5];
    fn = elt(env, 8); /* multsq */
    v0183 = (*qfn2(fn))(qenv(fn), stack[0], v0183);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-5];
    stack[0] = v0183;
    stack[-1] = stack[-2];
    v0067 = stack[-3];
    v0044 = stack[-4];
    v0183 = stack[0];
    v0183 = list2star(v0067, v0044, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-5];
    v0044 = qvalue(elt(env, 2)); /* nil */
    {
        Lisp_Object v0185 = stack[-1];
        popv(6);
        return list2star(v0185, v0183, v0044);
    }

v0030:
    v0183 = stack[0];
    v0183 = qcdr(v0183);
    stack[0] = v0183;
    goto v0019;

v0060:
    v0183 = qvalue(elt(env, 1)); /* t */
    goto v0112;
/* error exit handlers */
v0184:
    popv(6);
    return nil;
}



/* Code for createsinglevariablemonom */

static Lisp_Object CC_createsinglevariablemonom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071, v0063, v0052;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for createsinglevariablemonom");
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
    v0071 = (Lisp_Object)17; /* 1 */
    v0071 = Lmkvect(nil, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-4];
    stack[-3] = v0071;
    v0052 = stack[-3];
    v0063 = (Lisp_Object)1; /* 0 */
    v0071 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v0052 + (CELL-TAG_VECTOR) + ((int32_t)v0063/(16/CELL))) = v0071;
    stack[-1] = stack[-3];
    stack[0] = (Lisp_Object)17; /* 1 */
    v0052 = stack[-2];
    v0063 = qvalue(elt(env, 1)); /* nil */
    v0071 = qvalue(elt(env, 1)); /* nil */
    v0071 = list2star(v0052, v0063, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0071;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v0013:
    popv(5);
    return nil;
}



/* Code for gigcdsq */

static Lisp_Object CC_gigcdsq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0025)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gigcdsq");
#endif
    if (stack >= stacklimit)
    {
        push2(v0025,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0025);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0025;
    stack[-1] = v0000;
/* end of prologue */
    v0004 = stack[-1];
    if (v0004 == nil) goto v0024;
    v0005 = stack[0];
    v0004 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 2); /* giintgcd */
    v0004 = (*qfn2(fn))(qenv(fn), v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    stack[-2] = v0004;
    v0005 = stack[-2];
    v0004 = (Lisp_Object)17; /* 1 */
    if (v0005 == v0004) goto v0187;
    v0005 = stack[-1];
    v0004 = stack[-2];
    fn = elt(env, 2); /* giintgcd */
    v0005 = (*qfn2(fn))(qenv(fn), v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    stack[-2] = v0005;
    v0004 = (Lisp_Object)17; /* 1 */
    v0004 = Lneq(nil, v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    goto v0112;

v0112:
    if (v0004 == nil) goto v0024;
    v0005 = stack[-1];
    v0004 = stack[-2];
    fn = elt(env, 3); /* quotf */
    v0004 = (*qfn2(fn))(qenv(fn), v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-3];
    stack[-1] = v0004;
    v0005 = stack[0];
    v0004 = stack[-2];
    fn = elt(env, 3); /* quotf */
    v0004 = (*qfn2(fn))(qenv(fn), v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    stack[0] = v0004;
    goto v0024;

v0024:
    v0005 = stack[-1];
    v0004 = stack[0];
    popv(4);
    return cons(v0005, v0004);

v0187:
    v0004 = qvalue(elt(env, 1)); /* nil */
    goto v0112;
/* error exit handlers */
v0017:
    popv(4);
    return nil;
}



/* Code for pasf_dt */

static Lisp_Object CC_pasf_dt(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0223, v0224, v0225, v0226;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_dt");
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
    v0224 = stack[0];
    v0223 = elt(env, 1); /* true */
    if (v0224 == v0223) goto v0027;
    v0224 = stack[0];
    v0223 = elt(env, 3); /* false */
    v0223 = (v0224 == v0223 ? lisp_true : nil);
    goto v0026;

v0026:
    if (!(v0223 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0223 = stack[0];
    v0223 = qcdr(v0223);
    v0223 = qcar(v0223);
    fn = elt(env, 18); /* pasf_pdp */
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-1];
    v0226 = v0223;
    v0224 = stack[0];
    v0223 = elt(env, 1); /* true */
    if (v0224 == v0223) goto v0117;
    v0224 = stack[0];
    v0223 = elt(env, 3); /* false */
    v0223 = (v0224 == v0223 ? lisp_true : nil);
    goto v0061;

v0061:
    if (v0223 == nil) goto v0052;
    v0223 = stack[0];
    goto v0071;

v0071:
    v0225 = v0223;
    v0224 = v0226;
    v0223 = elt(env, 4); /* pdef */
    if (v0224 == v0223) goto v0155;
    v0223 = qvalue(elt(env, 6)); /* nil */
    goto v0228;

v0228:
    if (v0223 == nil) goto v0229;
    v0223 = elt(env, 3); /* false */
    { popv(2); return onevalue(v0223); }

v0229:
    v0224 = v0226;
    v0223 = elt(env, 7); /* ndef */
    if (v0224 == v0223) goto v0230;
    v0223 = qvalue(elt(env, 6)); /* nil */
    goto v0106;

v0106:
    if (v0223 == nil) goto v0231;
    v0223 = elt(env, 3); /* false */
    { popv(2); return onevalue(v0223); }

v0231:
    v0224 = v0226;
    v0223 = elt(env, 4); /* pdef */
    if (v0224 == v0223) goto v0232;
    v0223 = qvalue(elt(env, 6)); /* nil */
    goto v0233;

v0233:
    if (v0223 == nil) goto v0161;
    v0223 = elt(env, 1); /* true */
    { popv(2); return onevalue(v0223); }

v0161:
    v0224 = v0226;
    v0223 = elt(env, 7); /* ndef */
    if (v0224 == v0223) goto v0085;
    v0223 = qvalue(elt(env, 6)); /* nil */
    goto v0234;

v0234:
    if (v0223 == nil) goto v0099;
    v0223 = elt(env, 1); /* true */
    { popv(2); return onevalue(v0223); }

v0099:
    v0224 = v0226;
    v0223 = elt(env, 11); /* psdef */
    if (v0224 == v0223) goto v0235;
    v0223 = qvalue(elt(env, 6)); /* nil */
    goto v0147;

v0147:
    if (v0223 == nil) goto v0236;
    v0223 = elt(env, 3); /* false */
    { popv(2); return onevalue(v0223); }

v0236:
    v0224 = v0226;
    v0223 = elt(env, 13); /* nsdef */
    if (v0224 == v0223) goto v0237;
    v0223 = qvalue(elt(env, 6)); /* nil */
    goto v0238;

v0238:
    if (v0223 == nil) goto v0239;
    v0223 = elt(env, 3); /* false */
    { popv(2); return onevalue(v0223); }

v0239:
    v0224 = v0226;
    v0223 = elt(env, 11); /* psdef */
    if (v0224 == v0223) goto v0240;
    v0223 = qvalue(elt(env, 6)); /* nil */
    goto v0142;

v0142:
    if (v0223 == nil) goto v0241;
    v0223 = elt(env, 1); /* true */
    { popv(2); return onevalue(v0223); }

v0241:
    v0224 = v0226;
    v0223 = elt(env, 13); /* nsdef */
    if (v0224 == v0223) goto v0242;
    v0223 = qvalue(elt(env, 6)); /* nil */
    goto v0243;

v0243:
    if (v0223 == nil) goto v0244;
    v0223 = elt(env, 1); /* true */
    { popv(2); return onevalue(v0223); }

v0244:
    v0224 = v0226;
    v0223 = elt(env, 11); /* psdef */
    if (v0224 == v0223) goto v0245;
    v0223 = qvalue(elt(env, 6)); /* nil */
    goto v0170;

v0170:
    if (v0223 == nil) goto v0246;
    v0224 = elt(env, 14); /* greaterp */
    v0223 = stack[0];
    v0223 = qcdr(v0223);
    v0223 = qcar(v0223);
    v0225 = qvalue(elt(env, 6)); /* nil */
    popv(2);
    return list3(v0224, v0223, v0225);

v0246:
    v0224 = v0226;
    v0223 = elt(env, 13); /* nsdef */
    if (v0224 == v0223) goto v0247;
    v0223 = qvalue(elt(env, 6)); /* nil */
    goto v0126;

v0126:
    if (v0223 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0224 = elt(env, 12); /* lessp */
    v0223 = stack[0];
    v0223 = qcdr(v0223);
    v0223 = qcar(v0223);
    v0225 = qvalue(elt(env, 6)); /* nil */
    popv(2);
    return list3(v0224, v0223, v0225);

v0247:
    v0224 = v0225;
    v0223 = elt(env, 17); /* neq */
    v0223 = (v0224 == v0223 ? lisp_true : nil);
    goto v0126;

v0245:
    v0224 = v0225;
    v0223 = elt(env, 17); /* neq */
    v0223 = (v0224 == v0223 ? lisp_true : nil);
    goto v0170;

v0242:
    v0224 = v0225;
    v0223 = elt(env, 16); /* leq */
    v0223 = (v0224 == v0223 ? lisp_true : nil);
    goto v0243;

v0240:
    v0224 = v0225;
    v0223 = elt(env, 15); /* geq */
    v0223 = (v0224 == v0223 ? lisp_true : nil);
    goto v0142;

v0237:
    v0224 = v0225;
    v0223 = elt(env, 14); /* greaterp */
    v0223 = (v0224 == v0223 ? lisp_true : nil);
    goto v0238;

v0235:
    v0224 = v0225;
    v0223 = elt(env, 12); /* lessp */
    v0223 = (v0224 == v0223 ? lisp_true : nil);
    goto v0147;

v0085:
    v0224 = v0225;
    v0223 = elt(env, 10); /* (neq lessp leq) */
    v0223 = Lmemq(nil, v0224, v0223);
    goto v0234;

v0232:
    v0224 = v0225;
    v0223 = elt(env, 9); /* (neq greaterp geq) */
    v0223 = Lmemq(nil, v0224, v0223);
    goto v0233;

v0230:
    v0224 = v0225;
    v0223 = elt(env, 8); /* (equal greaterp geq) */
    v0223 = Lmemq(nil, v0224, v0223);
    goto v0106;

v0155:
    v0224 = v0225;
    v0223 = elt(env, 5); /* (equal lessp leq) */
    v0223 = Lmemq(nil, v0224, v0223);
    goto v0228;

v0052:
    v0223 = stack[0];
    v0223 = qcar(v0223);
    v0223 = Lconsp(nil, v0223);
    env = stack[-1];
    if (v0223 == nil) goto v0105;
    v0223 = stack[0];
    v0223 = qcar(v0223);
    v0223 = qcar(v0223);
    goto v0071;

v0105:
    v0223 = stack[0];
    v0223 = qcar(v0223);
    goto v0071;

v0117:
    v0223 = qvalue(elt(env, 2)); /* t */
    goto v0061;

v0027:
    v0223 = qvalue(elt(env, 2)); /* t */
    goto v0026;
/* error exit handlers */
v0227:
    popv(2);
    return nil;
}



/* Code for rl_surep */

static Lisp_Object CC_rl_surep(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0025)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_surep");
#endif
    if (stack >= stacklimit)
    {
        push2(v0025,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0025);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0030 = v0025;
    v0031 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_surep!* */
    v0030 = list2(v0031, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-1];
    {
        Lisp_Object v0112 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0112, v0030);
    }
/* error exit handlers */
v0111:
    popv(2);
    return nil;
}



/* Code for setrd */

static Lisp_Object MS_CDECL CC_setrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118, v0156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setrd");
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
    v0118 = elt(env, 1); /* (t y p e != s e t !$) */
    qvalue(elt(env, 2)) = v0118; /* atts */
    stack[0] = elt(env, 3); /* list */
    fn = elt(env, 4); /* stats_getargs */
    v0118 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-1];
    v0118 = cons(stack[0], v0118);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-1];
    v0156 = v0118;
    v0118 = v0156;
    stack[0] = qcar(v0118);
    v0118 = v0156;
    v0118 = qcdr(v0118);
    fn = elt(env, 5); /* norepeat */
    v0118 = (*qfn1(fn))(qenv(fn), v0118);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    {
        Lisp_Object v0054 = stack[0];
        popv(2);
        return cons(v0054, v0118);
    }
/* error exit handlers */
v0053:
    popv(2);
    return nil;
}



/* Code for ps!:zerop!: */

static Lisp_Object CC_psTzeropT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0019;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:zerop:");
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
    fn = elt(env, 2); /* ps!:value */
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[0];
    v0019 = v0029;
    v0029 = v0019;
    if (is_number(v0029)) goto v0026;
    v0029 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0029); }

v0026:
    v0029 = v0019;
        popv(1);
        return Lzerop(nil, v0029);
/* error exit handlers */
v0057:
    popv(1);
    return nil;
}



/* Code for maxl */

static Lisp_Object CC_maxl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0117, v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxl");
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
    goto v0001;

v0001:
    v0117 = stack[0];
    if (v0117 == nil) goto v0020;
    v0117 = stack[0];
    v0012 = qcar(v0117);
    v0117 = stack[-1];
    v0117 = cons(v0012, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-2];
    stack[-1] = v0117;
    v0117 = stack[0];
    v0117 = qcdr(v0117);
    stack[0] = v0117;
    goto v0001;

v0020:
    v0117 = (Lisp_Object)-159999; /* -10000 */
    v0012 = v0117;
    goto v0089;

v0089:
    v0117 = stack[-1];
    if (v0117 == nil) { popv(3); return onevalue(v0012); }
    v0117 = stack[-1];
    v0117 = qcar(v0117);
    fn = elt(env, 1); /* max */
    v0117 = (*qfn2(fn))(qenv(fn), v0117, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-2];
    v0012 = v0117;
    v0117 = stack[-1];
    v0117 = qcdr(v0117);
    stack[-1] = v0117;
    goto v0089;
/* error exit handlers */
v0187:
    popv(3);
    return nil;
}



/* Code for assgnpri */

static Lisp_Object MS_CDECL CC_assgnpri(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0025,
                         Lisp_Object v0006, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0168, v0266, v0241;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "assgnpri");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assgnpri");
#endif
    if (stack >= stacklimit)
    {
        push3(v0006,v0025,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0025,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0006;
    stack[-1] = v0025;
    stack[-2] = v0000;
/* end of prologue */
    v0168 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v0168; /* overflowed!* */
    qvalue(elt(env, 3)) = v0168; /* testing!-width!* */
    v0168 = stack[-2];
    if (!(v0168 == nil)) goto v0086;
    v0168 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0168;
    goto v0086;

v0086:
    v0168 = qvalue(elt(env, 4)); /* !*nero */
    if (v0168 == nil) goto v0029;
    v0266 = stack[-2];
    v0168 = (Lisp_Object)1; /* 0 */
    if (!(v0266 == v0168)) goto v0029;
    v0168 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0168); }

v0029:
    v0168 = qvalue(elt(env, 5)); /* !*tex */
    if (v0168 == nil) goto v0110;
    v0241 = stack[-2];
    v0266 = stack[-1];
    v0168 = stack[0];
    {
        popv(5);
        fn = elt(env, 20); /* texpri */
        return (*qfnn(fn))(qenv(fn), 3, v0241, v0266, v0168);
    }

v0110:
    v0168 = elt(env, 6); /* vecp */
    fn = elt(env, 21); /* getd */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    if (v0168 == nil) goto v0101;
    v0168 = stack[-2];
    fn = elt(env, 6); /* vecp */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    if (v0168 == nil) goto v0101;
    v0266 = stack[-2];
    v0168 = elt(env, 7); /* mat */
    {
        popv(5);
        fn = elt(env, 22); /* vecpri */
        return (*qfn2(fn))(qenv(fn), v0266, v0168);
    }

v0101:
    v0168 = stack[-2];
    fn = elt(env, 23); /* getrtype */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    v0241 = v0168;
    if (v0168 == nil) goto v0033;
    v0266 = v0241;
    v0168 = elt(env, 8); /* sprifn */
    v0168 = Lflagp(nil, v0266, v0168);
    env = stack[-4];
    if (v0168 == nil) goto v0048;
    v0168 = qvalue(elt(env, 9)); /* outputhandler!* */
    v0168 = (v0168 == nil ? lisp_true : nil);
    goto v0049;

v0049:
    if (v0168 == nil) goto v0033;
    v0168 = stack[-1];
    if (v0168 == nil) goto v0092;
    v0241 = elt(env, 12); /* setq */
    v0168 = stack[-1];
    v0266 = qcar(v0168);
    v0168 = stack[-2];
    v0168 = list3(v0241, v0266, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    v0266 = qvalue(elt(env, 9)); /* outputhandler!* */
    if (v0266 == nil) goto v0103;
    v0241 = qvalue(elt(env, 9)); /* outputhandler!* */
    v0266 = elt(env, 13); /* maprin */
    v0168 = Lapply2(nil, 3, v0241, v0266, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    goto v0267;

v0267:
    v0168 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0168); }

v0103:
    v0266 = qvalue(elt(env, 2)); /* overflowed!* */
    if (!(v0266 == nil)) goto v0267;
    v0266 = v0168;
    v0168 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 24); /* maprint */
    v0168 = (*qfn2(fn))(qenv(fn), v0266, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    goto v0267;

v0092:
    v0266 = v0241;
    v0168 = elt(env, 10); /* tag */
    v0266 = get(v0266, v0168);
    env = stack[-4];
    v0168 = elt(env, 11); /* prifn */
    v0266 = get(v0266, v0168);
    env = stack[-4];
    v0168 = stack[-2];
    v0168 = Lapply1(nil, v0266, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    goto v0267;

v0033:
    v0266 = stack[0];
    v0168 = elt(env, 14); /* (first only) */
    v0168 = Lmemq(nil, v0266, v0168);
    if (v0168 == nil) goto v0149;
    v0168 = qvalue(elt(env, 15)); /* t */
    fn = elt(env, 25); /* terpri!* */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    goto v0149;

v0149:
    v0168 = stack[-1];
    fn = elt(env, 26); /* evalvars */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    stack[-1] = v0168;
    v0168 = qvalue(elt(env, 16)); /* !*fort */
    if (v0168 == nil) goto v0268;
    v0241 = stack[-2];
    v0266 = stack[-1];
    v0168 = stack[0];
    fn = elt(env, 27); /* fvarpri */
    v0168 = (*qfnn(fn))(qenv(fn), 3, v0241, v0266, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    v0168 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0168); }

v0268:
    v0168 = stack[-1];
    if (v0168 == nil) goto v0269;
    stack[-3] = elt(env, 12); /* setq */
    v0168 = stack[-2];
    v0168 = ncons(v0168);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    v0168 = Lnconc(nil, stack[-1], v0168);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    v0168 = cons(stack[-3], v0168);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    goto v0097;

v0097:
    v0266 = qvalue(elt(env, 9)); /* outputhandler!* */
    if (v0266 == nil) goto v0270;
    v0241 = qvalue(elt(env, 9)); /* outputhandler!* */
    v0266 = elt(env, 13); /* maprin */
    v0168 = Lapply2(nil, 3, v0241, v0266, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    goto v0209;

v0209:
    v0168 = stack[0];
    if (v0168 == nil) goto v0271;
    v0266 = stack[0];
    v0168 = elt(env, 17); /* first */
    v0168 = (v0266 == v0168 ? lisp_true : nil);
    goto v0239;

v0239:
    if (v0168 == nil) goto v0143;
    v0168 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0168); }

v0143:
    v0168 = qvalue(elt(env, 18)); /* !*nat */
    if (!(v0168 == nil)) goto v0204;
    v0168 = elt(env, 19); /* "$" */
    fn = elt(env, 28); /* prin2!* */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    goto v0204;

v0204:
    v0168 = qvalue(elt(env, 18)); /* !*nat */
    v0168 = (v0168 == nil ? lisp_true : nil);
    fn = elt(env, 25); /* terpri!* */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    v0168 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0168); }

v0271:
    v0168 = qvalue(elt(env, 15)); /* t */
    goto v0239;

v0270:
    v0266 = qvalue(elt(env, 2)); /* overflowed!* */
    if (!(v0266 == nil)) goto v0209;
    v0266 = v0168;
    v0168 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 24); /* maprint */
    v0168 = (*qfn2(fn))(qenv(fn), v0266, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    goto v0209;

v0269:
    v0168 = stack[-2];
    goto v0097;

v0048:
    v0168 = qvalue(elt(env, 1)); /* nil */
    goto v0049;
/* error exit handlers */
v0202:
    popv(5);
    return nil;
}



/* Code for decimal2internal */

static Lisp_Object CC_decimal2internal(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0025)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0221, v0178, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for decimal2internal");
#endif
    if (stack >= stacklimit)
    {
        push2(v0025,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0025);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0025;
    stack[-1] = v0000;
/* end of prologue */
    v0178 = stack[0];
    v0221 = (Lisp_Object)1; /* 0 */
    v0221 = (Lisp_Object)geq2(v0178, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    v0221 = v0221 ? lisp_true : nil;
    env = stack[-3];
    if (v0221 == nil) goto v0080;
    stack[-2] = elt(env, 1); /* !:rd!: */
    v0178 = (Lisp_Object)161; /* 10 */
    v0221 = stack[0];
    v0221 = Lexpt(nil, v0178, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-3];
    v0178 = times2(stack[-1], v0221);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    v0221 = (Lisp_Object)1; /* 0 */
    {
        Lisp_Object v0095 = stack[-2];
        popv(4);
        return list2star(v0095, v0178, v0221);
    }

v0080:
    v0007 = elt(env, 1); /* !:rd!: */
    v0178 = stack[-1];
    v0221 = (Lisp_Object)1; /* 0 */
    stack[-1] = list2star(v0007, v0178, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-3];
    v0221 = stack[0];
    v0221 = negate(v0221);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-3];
    {
        Lisp_Object v0021 = stack[-1];
        popv(4);
        fn = elt(env, 2); /* divide!-by!-power!-of!-ten */
        return (*qfn2(fn))(qenv(fn), v0021, v0221);
    }
/* error exit handlers */
v0024:
    popv(4);
    return nil;
}



/* Code for indexvp */

static Lisp_Object CC_indexvp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0177;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indexvp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0177 = v0000;
/* end of prologue */
    v0031 = v0177;
    if (!consp(v0031)) goto v0019;
    v0031 = v0177;
    v0031 = qcar(v0031);
    v0177 = elt(env, 1); /* indexvar */
        return Lflagp(nil, v0031, v0177);

v0019:
    v0031 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0031);
}



/* Code for !*f2di */

static Lisp_Object CC_Hf2di(Lisp_Object env,
                         Lisp_Object v0025, Lisp_Object v0006)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0281, v0140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *f2di");
#endif
    if (stack >= stacklimit)
    {
        push2(v0006,v0025);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0025,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v0281 = v0006;
    stack[-5] = v0025;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* varlist */
    qvalue(elt(env, 1)) = nil; /* varlist */
    qvalue(elt(env, 1)) = v0281; /* varlist */
    v0281 = stack[-5];
    if (v0281 == nil) goto v0096;
    v0281 = stack[-5];
    if (!consp(v0281)) goto v0030;
    v0281 = stack[-5];
    v0281 = qcar(v0281);
    v0281 = (consp(v0281) ? nil : lisp_true);
    goto v0057;

v0057:
    if (v0281 == nil) goto v0282;
    v0281 = qvalue(elt(env, 1)); /* varlist */
    stack[-3] = v0281;
    v0281 = stack[-3];
    if (v0281 == nil) goto v0012;
    v0281 = (Lisp_Object)1; /* 0 */
    v0281 = ncons(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-7];
    stack[-1] = v0281;
    stack[-2] = v0281;
    goto v0052;

v0052:
    v0281 = stack[-3];
    v0281 = qcdr(v0281);
    stack[-3] = v0281;
    v0281 = stack[-3];
    if (v0281 == nil) goto v0050;
    stack[0] = stack[-1];
    v0281 = (Lisp_Object)1; /* 0 */
    v0281 = ncons(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-7];
    v0281 = Lrplacd(nil, stack[0], v0281);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-7];
    v0281 = stack[-1];
    v0281 = qcdr(v0281);
    stack[-1] = v0281;
    goto v0052;

v0050:
    v0281 = stack[-2];
    goto v0063;

v0063:
    fn = elt(env, 4); /* addgt */
    v0140 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-7];
    v0281 = stack[-5];
    v0281 = cons(v0140, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-7];
    v0281 = ncons(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-7];
    goto v0001;

v0001:
    qvalue(elt(env, 1)) = stack[-6]; /* varlist */
    { popv(8); return onevalue(v0281); }

v0012:
    v0281 = qvalue(elt(env, 2)); /* nil */
    goto v0063;

v0282:
    v0281 = stack[-5];
    v0281 = qcar(v0281);
    v0281 = qcar(v0281);
    v0140 = qcar(v0281);
    v0281 = qvalue(elt(env, 1)); /* varlist */
    v0281 = Lmember(nil, v0140, v0281);
    if (v0281 == nil) goto v0216;
    v0281 = stack[-5];
    v0281 = qcar(v0281);
    v0140 = qcdr(v0281);
    v0281 = qvalue(elt(env, 1)); /* varlist */
    stack[-4] = CC_Hf2di(env, v0140, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-7];
    v0281 = qvalue(elt(env, 1)); /* varlist */
    stack[-3] = v0281;
    v0281 = stack[-3];
    if (v0281 == nil) goto v0260;
    v0281 = stack[-3];
    v0281 = qcar(v0281);
    v0140 = v0281;
    v0281 = stack[-5];
    v0281 = qcar(v0281);
    v0281 = qcar(v0281);
    v0281 = qcar(v0281);
    if (equal(v0140, v0281)) goto v0233;
    v0281 = (Lisp_Object)1; /* 0 */
    goto v0039;

v0039:
    v0281 = ncons(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-7];
    stack[-1] = v0281;
    stack[-2] = v0281;
    goto v0283;

v0283:
    v0281 = stack[-3];
    v0281 = qcdr(v0281);
    stack[-3] = v0281;
    v0281 = stack[-3];
    if (v0281 == nil) goto v0034;
    stack[0] = stack[-1];
    v0281 = stack[-3];
    v0281 = qcar(v0281);
    v0140 = v0281;
    v0281 = stack[-5];
    v0281 = qcar(v0281);
    v0281 = qcar(v0281);
    v0281 = qcar(v0281);
    if (equal(v0140, v0281)) goto v0109;
    v0281 = (Lisp_Object)1; /* 0 */
    goto v0284;

v0284:
    v0281 = ncons(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-7];
    v0281 = Lrplacd(nil, stack[0], v0281);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-7];
    v0281 = stack[-1];
    v0281 = qcdr(v0281);
    stack[-1] = v0281;
    goto v0283;

v0109:
    v0281 = stack[-5];
    v0281 = qcar(v0281);
    v0281 = qcar(v0281);
    v0281 = qcdr(v0281);
    goto v0284;

v0034:
    v0281 = stack[-2];
    goto v0285;

v0285:
    fn = elt(env, 4); /* addgt */
    v0281 = (*qfn1(fn))(qenv(fn), v0281);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-7];
    fn = elt(env, 5); /* pdmult */
    v0281 = (*qfn2(fn))(qenv(fn), stack[-4], v0281);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-7];
    stack[0] = v0281;
    goto v0237;

v0237:
    v0281 = stack[-5];
    v0140 = qcdr(v0281);
    v0281 = qvalue(elt(env, 1)); /* varlist */
    v0281 = CC_Hf2di(env, v0140, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-7];
    fn = elt(env, 6); /* psum */
    v0281 = (*qfn2(fn))(qenv(fn), stack[0], v0281);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-7];
    goto v0001;

v0233:
    v0281 = stack[-5];
    v0281 = qcar(v0281);
    v0281 = qcar(v0281);
    v0281 = qcdr(v0281);
    goto v0039;

v0260:
    v0281 = qvalue(elt(env, 2)); /* nil */
    goto v0285;

v0216:
    v0281 = stack[-5];
    v0281 = qcar(v0281);
    v0140 = qcdr(v0281);
    v0281 = qvalue(elt(env, 1)); /* varlist */
    stack[0] = CC_Hf2di(env, v0140, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-7];
    v0281 = stack[-5];
    v0281 = qcar(v0281);
    v0140 = qcar(v0281);
    v0281 = (Lisp_Object)17; /* 1 */
    v0281 = cons(v0140, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-7];
    v0281 = ncons(v0281);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-7];
    fn = elt(env, 7); /* pcmult */
    v0281 = (*qfn2(fn))(qenv(fn), stack[0], v0281);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-7];
    stack[0] = v0281;
    goto v0237;

v0030:
    v0281 = qvalue(elt(env, 3)); /* t */
    goto v0057;

v0096:
    v0281 = qvalue(elt(env, 2)); /* nil */
    goto v0001;
/* error exit handlers */
v0142:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* varlist */
    popv(8);
    return nil;
}



/* Code for nodum_varp */

static Lisp_Object CC_nodum_varp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0221, v0178;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nodum_varp");
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
    v0221 = stack[0];
    fn = elt(env, 7); /* listp */
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    if (v0221 == nil) goto v0019;
    v0221 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0221); }

v0019:
    v0178 = stack[0];
    v0221 = elt(env, 2); /* dummy */
    v0221 = Lflagp(nil, v0178, v0221);
    env = stack[-1];
    if (v0221 == nil) goto v0101;
    v0221 = qvalue(elt(env, 1)); /* t */
    goto v0027;

v0027:
    if (v0221 == nil) goto v0051;
    v0221 = qvalue(elt(env, 6)); /* nil */
    { popv(2); return onevalue(v0221); }

v0051:
    v0221 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0221); }

v0101:
    v0221 = stack[0];
    fn = elt(env, 8); /* ad_splitname */
    v0221 = (*qfn1(fn))(qenv(fn), v0221);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    v0178 = qcar(v0221);
    v0221 = qvalue(elt(env, 3)); /* g_dvbase */
    if (equal(v0178, v0221)) goto v0053;
    v0178 = elt(env, 4); /* !~dv */
    v0221 = elt(env, 5); /* !~dva */
    v0221 = list2(v0178, v0221);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-1];
    v0221 = Lmember(nil, stack[0], v0221);
    goto v0027;

v0053:
    v0221 = qvalue(elt(env, 1)); /* t */
    goto v0027;
/* error exit handlers */
v0008:
    popv(2);
    return nil;
}



/* Code for balance_mod */

static Lisp_Object CC_balance_mod(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0025)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0015;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for balance_mod");
#endif
    if (stack >= stacklimit)
    {
        push2(v0025,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0025);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0025;
    stack[-1] = v0000;
/* end of prologue */
    v0015 = stack[-1];
    v0014 = stack[-1];
    v0015 = plus2(v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-2];
    v0014 = stack[0];
    v0014 = (Lisp_Object)greaterp2(v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    v0014 = v0014 ? lisp_true : nil;
    if (v0014 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0015 = stack[-1];
    v0014 = stack[0];
    popv(3);
    return difference2(v0015, v0014);
/* error exit handlers */
v0023:
    popv(3);
    return nil;
}



/* Code for use!-berlekamp */

static Lisp_Object MS_CDECL CC_useKberlekamp(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0025,
                         Lisp_Object v0006, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0306, v0175, v0307, v0308, v0309, v0310, v0311;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "use-berlekamp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for use-berlekamp");
#endif
    if (stack >= stacklimit)
    {
        push3(v0006,v0025,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0025,v0006);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0006;
    stack[-5] = v0025;
    stack[-6] = v0000;
/* end of prologue */
    v0306 = qvalue(elt(env, 1)); /* dpoly */
    v0306 = (Lisp_Object)((int32_t)(v0306) - 0x10);
    stack[-3] = v0306;
    v0306 = stack[-3];
    v0306 = Lmkvect(nil, v0306);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-8];
    stack[-7] = v0306;
    v0306 = (Lisp_Object)1; /* 0 */
    stack[0] = v0306;
    goto v0179;

v0179:
    v0175 = stack[-3];
    v0306 = stack[0];
    v0306 = (Lisp_Object)(int32_t)((int32_t)v0175 - (int32_t)v0306 + TAG_FIXNUM);
    v0306 = ((intptr_t)(v0306) < 0 ? lisp_true : nil);
    if (v0306 == nil) goto v0111;
    v0308 = stack[-6];
    v0307 = stack[-5];
    v0175 = qvalue(elt(env, 3)); /* poly!-vector */
    v0306 = qvalue(elt(env, 1)); /* dpoly */
    fn = elt(env, 5); /* remainder!-in!-vector */
    v0306 = (*qfnn(fn))(qenv(fn), 4, v0308, v0307, v0175, v0306);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-8];
    stack[-5] = v0306;
    v0306 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0306;
    v0306 = stack[-3];
    v0306 = Lmkvect(nil, v0306);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-8];
    stack[-1] = v0306;
    v0307 = stack[-1];
    v0175 = (Lisp_Object)1; /* 0 */
    v0306 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v0307 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL))) = v0306;
    v0306 = (Lisp_Object)17; /* 1 */
    stack[0] = v0306;
    goto v0152;

v0152:
    v0175 = stack[-3];
    v0306 = stack[0];
    v0306 = (Lisp_Object)(int32_t)((int32_t)v0175 - (int32_t)v0306 + TAG_FIXNUM);
    v0306 = ((intptr_t)(v0306) < 0 ? lisp_true : nil);
    if (v0306 == nil) goto v0107;
    v0175 = stack[-7];
    v0306 = stack[-3];
    {
        popv(9);
        fn = elt(env, 6); /* find!-null!-space */
        return (*qfn2(fn))(qenv(fn), v0175, v0306);
    }

v0107:
    v0175 = qvalue(elt(env, 4)); /* current!-modulus */
    v0306 = qvalue(elt(env, 1)); /* dpoly */
    if (((int32_t)(v0175)) > ((int32_t)(v0306))) goto v0090;
    v0306 = (Lisp_Object)1; /* 0 */
    v0308 = v0306;
    goto v0312;

v0312:
    v0306 = qvalue(elt(env, 4)); /* current!-modulus */
    v0175 = (Lisp_Object)((int32_t)(v0306) - 0x10);
    v0306 = v0308;
    v0306 = (Lisp_Object)(int32_t)((int32_t)v0175 - (int32_t)v0306 + TAG_FIXNUM);
    v0306 = ((intptr_t)(v0306) < 0 ? lisp_true : nil);
    if (v0306 == nil) goto v0109;
    v0306 = (Lisp_Object)1; /* 0 */
    v0309 = v0306;
    goto v0313;

v0313:
    v0175 = stack[-2];
    v0306 = v0309;
    v0306 = (Lisp_Object)(int32_t)((int32_t)v0175 - (int32_t)v0306 + TAG_FIXNUM);
    v0306 = ((intptr_t)(v0306) < 0 ? lisp_true : nil);
    if (v0306 == nil) goto v0314;
    v0175 = stack[-2];
    v0306 = qvalue(elt(env, 4)); /* current!-modulus */
    v0306 = (Lisp_Object)(int32_t)((int32_t)v0175 + (int32_t)v0306 - TAG_FIXNUM);
    stack[-2] = v0306;
    goto v0315;

v0315:
    v0308 = stack[-4];
    v0307 = stack[-2];
    v0175 = qvalue(elt(env, 3)); /* poly!-vector */
    v0306 = qvalue(elt(env, 1)); /* dpoly */
    fn = elt(env, 5); /* remainder!-in!-vector */
    v0306 = (*qfnn(fn))(qenv(fn), 4, v0308, v0307, v0175, v0306);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-8];
    stack[-2] = v0306;
    v0306 = (Lisp_Object)1; /* 0 */
    v0311 = v0306;
    goto v0137;

v0137:
    v0175 = stack[-2];
    v0306 = v0311;
    v0306 = (Lisp_Object)(int32_t)((int32_t)v0175 - (int32_t)v0306 + TAG_FIXNUM);
    v0306 = ((intptr_t)(v0306) < 0 ? lisp_true : nil);
    if (v0306 == nil) goto v0242;
    v0175 = stack[-7];
    v0306 = stack[0];
    v0308 = *(Lisp_Object *)((char *)v0175 + (CELL-TAG_VECTOR) + ((int32_t)v0306/(16/CELL)));
    v0307 = stack[0];
    v0175 = stack[-7];
    v0306 = stack[0];
    v0175 = *(Lisp_Object *)((char *)v0175 + (CELL-TAG_VECTOR) + ((int32_t)v0306/(16/CELL)));
    v0306 = stack[0];
    v0175 = *(Lisp_Object *)((char *)v0175 + (CELL-TAG_VECTOR) + ((int32_t)v0306/(16/CELL)));
    v0306 = (Lisp_Object)17; /* 1 */
    {   int32_t w = int_of_fixnum(v0175) - int_of_fixnum(v0306);
        if (w < 0) w += current_modulus;
        v0306 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v0308 + (CELL-TAG_VECTOR) + ((int32_t)v0307/(16/CELL))) = v0306;
    v0306 = stack[0];
    v0306 = (Lisp_Object)((int32_t)(v0306) + 0x10);
    stack[0] = v0306;
    goto v0152;

v0242:
    v0175 = stack[-7];
    v0306 = v0311;
    v0310 = *(Lisp_Object *)((char *)v0175 + (CELL-TAG_VECTOR) + ((int32_t)v0306/(16/CELL)));
    v0309 = stack[0];
    v0308 = stack[-1];
    v0307 = v0311;
    v0175 = stack[-4];
    v0306 = v0311;
    v0306 = *(Lisp_Object *)((char *)v0175 + (CELL-TAG_VECTOR) + ((int32_t)v0306/(16/CELL)));
    *(Lisp_Object *)((char *)v0308 + (CELL-TAG_VECTOR) + ((int32_t)v0307/(16/CELL))) = v0306;
    *(Lisp_Object *)((char *)v0310 + (CELL-TAG_VECTOR) + ((int32_t)v0309/(16/CELL))) = v0306;
    v0306 = v0311;
    v0306 = (Lisp_Object)((int32_t)(v0306) + 0x10);
    v0311 = v0306;
    goto v0137;

v0314:
    v0308 = stack[-4];
    v0175 = qvalue(elt(env, 4)); /* current!-modulus */
    v0306 = v0309;
    v0307 = (Lisp_Object)(int32_t)((int32_t)v0175 + (int32_t)v0306 - TAG_FIXNUM);
    v0175 = stack[-1];
    v0306 = v0309;
    v0306 = *(Lisp_Object *)((char *)v0175 + (CELL-TAG_VECTOR) + ((int32_t)v0306/(16/CELL)));
    *(Lisp_Object *)((char *)v0308 + (CELL-TAG_VECTOR) + ((int32_t)v0307/(16/CELL))) = v0306;
    v0306 = v0309;
    v0306 = (Lisp_Object)((int32_t)(v0306) + 0x10);
    v0309 = v0306;
    goto v0313;

v0109:
    v0307 = stack[-4];
    v0175 = v0308;
    v0306 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v0307 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL))) = v0306;
    v0306 = v0308;
    v0306 = (Lisp_Object)((int32_t)(v0306) + 0x10);
    v0308 = v0306;
    goto v0312;

v0090:
    v0309 = stack[-1];
    v0308 = stack[-2];
    v0307 = stack[-6];
    v0175 = stack[-5];
    v0306 = stack[-4];
    fn = elt(env, 7); /* times!-in!-vector */
    v0306 = (*qfnn(fn))(qenv(fn), 5, v0309, v0308, v0307, v0175, v0306);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-8];
    stack[-2] = v0306;
    goto v0315;

v0111:
    v0306 = stack[-3];
    v0306 = Lmkvect(nil, v0306);
    nil = C_nil;
    if (exception_pending()) goto v0224;
    env = stack[-8];
    v0309 = v0306;
    v0306 = (Lisp_Object)1; /* 0 */
    v0308 = v0306;
    goto v0013;

v0013:
    v0175 = stack[-3];
    v0306 = v0308;
    v0306 = (Lisp_Object)(int32_t)((int32_t)v0175 - (int32_t)v0306 + TAG_FIXNUM);
    v0306 = ((intptr_t)(v0306) < 0 ? lisp_true : nil);
    if (v0306 == nil) goto v0010;
    v0175 = stack[-7];
    v0306 = stack[0];
    v0307 = v0309;
    *(Lisp_Object *)((char *)v0175 + (CELL-TAG_VECTOR) + ((int32_t)v0306/(16/CELL))) = v0307;
    v0306 = stack[0];
    v0306 = (Lisp_Object)((int32_t)(v0306) + 0x10);
    stack[0] = v0306;
    goto v0179;

v0010:
    v0307 = v0309;
    v0175 = v0308;
    v0306 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v0307 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL))) = v0306;
    v0306 = v0308;
    v0306 = (Lisp_Object)((int32_t)(v0306) + 0x10);
    v0308 = v0306;
    goto v0013;
/* error exit handlers */
v0224:
    popv(9);
    return nil;
}



/* Code for rl_smrmknowl */

static Lisp_Object CC_rl_smrmknowl(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0025)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_smrmknowl");
#endif
    if (stack >= stacklimit)
    {
        push2(v0025,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0025);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0030 = v0025;
    v0031 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_smrmknowl!* */
    v0030 = list2(v0031, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-1];
    {
        Lisp_Object v0112 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0112, v0030);
    }
/* error exit handlers */
v0111:
    popv(2);
    return nil;
}



/* Code for give!*position */

static Lisp_Object CC_giveHposition(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0025)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for give*position");
#endif
    if (stack >= stacklimit)
    {
        push2(v0025,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0025);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0025;
    stack[-3] = v0000;
/* end of prologue */
    v0005 = (Lisp_Object)17; /* 1 */
    stack[-4] = v0005;
    v0005 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v0005;
    goto v0026;

v0026:
    v0005 = stack[-1];
    if (v0005 == nil) goto v0112;
    v0005 = qvalue(elt(env, 1)); /* nil */
    goto v0057;

v0057:
    if (v0005 == nil) goto v0096;
    v0180 = stack[-2];
    v0005 = stack[-4];
    fn = elt(env, 5); /* pnth */
    v0005 = (*qfn2(fn))(qenv(fn), v0180, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    v0180 = qcar(v0005);
    v0005 = stack[-3];
    if (equal(v0180, v0005)) goto v0056;
    v0005 = stack[-4];
    v0005 = add1(v0005);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    stack[-4] = v0005;
    goto v0026;

v0056:
    v0005 = qvalue(elt(env, 2)); /* t */
    stack[-1] = v0005;
    goto v0026;

v0096:
    v0005 = stack[-1];
    if (!(v0005 == nil)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v0005 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v0005 == nil)) goto v0024;
    v0005 = elt(env, 4); /* "error in give position" */
    fn = elt(env, 6); /* lprie */
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    goto v0024;

v0024:
    v0005 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }

v0112:
    stack[0] = stack[-4];
    v0005 = stack[-2];
    v0005 = Llength(nil, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-5];
    v0005 = (Lisp_Object)lesseq2(stack[0], v0005);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    v0005 = v0005 ? lisp_true : nil;
    env = stack[-5];
    goto v0057;
/* error exit handlers */
v0047:
    popv(6);
    return nil;
}



/* Code for pasf_smordtable */

static Lisp_Object MS_CDECL CC_pasf_smordtable(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0025,
                         Lisp_Object v0006, Lisp_Object v0009, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011, v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pasf_smordtable");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smordtable");
#endif
    if (stack >= stacklimit)
    {
        push4(v0009,v0006,v0025,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0025,v0006,v0009);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0009;
    stack[-1] = v0006;
    stack[-2] = v0025;
    stack[-3] = v0000;
/* end of prologue */
    v0050 = stack[-1];
    v0011 = stack[0];
    v0011 = (Lisp_Object)lessp2(v0050, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    v0011 = v0011 ? lisp_true : nil;
    env = stack[-4];
    if (v0011 == nil) goto v0053;
    v0050 = stack[-3];
    v0011 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* pasf_smordtable2 */
        return (*qfn2(fn))(qenv(fn), v0050, v0011);
    }

v0053:
    v0050 = stack[-1];
    v0011 = stack[0];
    v0011 = (Lisp_Object)greaterp2(v0050, v0011);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    v0011 = v0011 ? lisp_true : nil;
    env = stack[-4];
    if (v0011 == nil) goto v0117;
    v0050 = stack[-3];
    v0011 = stack[-2];
    {
        popv(5);
        fn = elt(env, 4); /* pasf_smordtable1 */
        return (*qfn2(fn))(qenv(fn), v0050, v0011);
    }

v0117:
    v0011 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v0011 == nil)) goto v0272;
    v0011 = elt(env, 2); /* "abused smordtable" */
    v0011 = ncons(v0011);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-4];
    fn = elt(env, 5); /* lprie */
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-4];
    goto v0272;

v0272:
    v0011 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    v0011 = nil;
    { popv(5); return onevalue(v0011); }
/* error exit handlers */
v0178:
    popv(5);
    return nil;
}



/* Code for dvfsf_simplat1 */

static Lisp_Object CC_dvfsf_simplat1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0025)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0178, v0007, v0008;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_simplat1");
#endif
    if (stack >= stacklimit)
    {
        push2(v0025,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0025);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0025;
    stack[-2] = v0000;
/* end of prologue */
    v0178 = stack[-2];
    fn = elt(env, 4); /* dvfsf_op */
    v0178 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-4];
    v0008 = v0178;
    v0007 = v0008;
    v0178 = elt(env, 1); /* equal */
    if (v0007 == v0178) goto v0028;
    v0007 = v0008;
    v0178 = elt(env, 3); /* neq */
    v0178 = (v0007 == v0178 ? lisp_true : nil);
    goto v0113;

v0113:
    if (v0178 == nil) goto v0187;
    stack[0] = v0008;
    v0178 = stack[-2];
    fn = elt(env, 5); /* dvfsf_arg2l */
    v0007 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-4];
    v0178 = stack[-1];
    {
        Lisp_Object v0049 = stack[0];
        popv(5);
        fn = elt(env, 6); /* dvfsf_safield */
        return (*qfnn(fn))(qenv(fn), 3, v0049, v0007, v0178);
    }

v0187:
    stack[-3] = v0008;
    v0178 = stack[-2];
    fn = elt(env, 5); /* dvfsf_arg2l */
    stack[0] = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-4];
    v0178 = stack[-2];
    fn = elt(env, 7); /* dvfsf_arg2r */
    v0007 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-4];
    v0178 = stack[-1];
    {
        Lisp_Object v0072 = stack[-3];
        Lisp_Object v0105 = stack[0];
        popv(5);
        fn = elt(env, 8); /* dvfsf_saval */
        return (*qfnn(fn))(qenv(fn), 4, v0072, v0105, v0007, v0178);
    }

v0028:
    v0178 = qvalue(elt(env, 2)); /* t */
    goto v0113;
/* error exit handlers */
v0021:
    popv(5);
    return nil;
}



/* Code for minusrd */

static Lisp_Object MS_CDECL CC_minusrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0156, v0115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "minusrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minusrd");
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
    fn = elt(env, 1); /* mathml */
    v0156 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-1];
    stack[0] = v0156;
    fn = elt(env, 1); /* mathml */
    v0156 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-1];
    v0115 = v0156;
    if (v0115 == nil) goto v0086;
    v0115 = stack[0];
    fn = elt(env, 2); /* alg_difference */
    v0156 = (*qfn2(fn))(qenv(fn), v0115, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-1];
    stack[0] = v0156;
    fn = elt(env, 3); /* lex */
    v0156 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0086:
    v0156 = stack[0];
    fn = elt(env, 4); /* alg_minus */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    stack[0] = v0156;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0054:
    popv(2);
    return nil;
}



/* Code for freeof */

static Lisp_Object CC_freeof(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0025)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0079, v0110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeof");
#endif
    if (stack >= stacklimit)
    {
        push2(v0025,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0025);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0025;
    stack[-1] = v0000;
/* end of prologue */
    v0079 = stack[0];
    v0101 = stack[-1];
    fn = elt(env, 2); /* smember */
    v0101 = (*qfn2(fn))(qenv(fn), v0079, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-2];
    if (!(v0101 == nil)) goto v0003;
    v0079 = stack[0];
    v0101 = stack[-1];
    v0110 = qvalue(elt(env, 1)); /* depl!* */
    v0101 = Lassoc(nil, v0101, v0110);
    v0101 = Lmember(nil, v0079, v0101);
    goto v0003;

v0003:
    v0101 = (v0101 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v0101); }
/* error exit handlers */
v0055:
    popv(3);
    return nil;
}



setup_type const u31_setup[] =
{
    {"cl_sitheo",               CC_cl_sitheo,   too_many_1,    wrong_no_1},
    {"maxfrom",                 too_few_2,      CC_maxfrom,    wrong_no_2},
    {"expf",                    too_few_2,      CC_expf,       wrong_no_2},
    {"mk+real+inner+product",   too_few_2,      CC_mkLrealLinnerLproduct,wrong_no_2},
    {"cl_susiupdknowl2",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiupdknowl2},
    {"ofsf_sacrel",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_sacrel},
    {"setfuncsnaryrd",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_setfuncsnaryrd},
    {"indexsymmetrize",         CC_indexsymmetrize,too_many_1, wrong_no_1},
    {"applsmacro",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_applsmacro},
    {"reduce",                  too_few_2,      CC_reduce,     wrong_no_2},
    {"fs:make-nullangle",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_fsTmakeKnullangle},
    {"red=hide",                CC_redMhide,    too_many_1,    wrong_no_1},
    {"taylorp",                 CC_taylorp,     too_many_1,    wrong_no_1},
    {"ofsf_at2ir",              too_few_2,      CC_ofsf_at2ir, wrong_no_2},
    {"createsinglevariablemonom",CC_createsinglevariablemonom,too_many_1,wrong_no_1},
    {"gigcdsq",                 too_few_2,      CC_gigcdsq,    wrong_no_2},
    {"pasf_dt",                 CC_pasf_dt,     too_many_1,    wrong_no_1},
    {"rl_surep",                too_few_2,      CC_rl_surep,   wrong_no_2},
    {"setrd",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_setrd},
    {"ps:zerop:",               CC_psTzeropT,   too_many_1,    wrong_no_1},
    {"maxl",                    CC_maxl,        too_many_1,    wrong_no_1},
    {"assgnpri",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_assgnpri},
    {"decimal2internal",        too_few_2,      CC_decimal2internal,wrong_no_2},
    {"indexvp",                 CC_indexvp,     too_many_1,    wrong_no_1},
    {"*f2di",                   too_few_2,      CC_Hf2di,      wrong_no_2},
    {"nodum_varp",              CC_nodum_varp,  too_many_1,    wrong_no_1},
    {"balance_mod",             too_few_2,      CC_balance_mod,wrong_no_2},
    {"use-berlekamp",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_useKberlekamp},
    {"rl_smrmknowl",            too_few_2,      CC_rl_smrmknowl,wrong_no_2},
    {"give*position",           too_few_2,      CC_giveHposition,wrong_no_2},
    {"pasf_smordtable",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smordtable},
    {"dvfsf_simplat1",          too_few_2,      CC_dvfsf_simplat1,wrong_no_2},
    {"minusrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_minusrd},
    {"freeof",                  too_few_2,      CC_freeof,     wrong_no_2},
    {NULL, (one_args *)"u31", (two_args *)"2653 4050305 4262160", 0}
};

/* end of generated code */
