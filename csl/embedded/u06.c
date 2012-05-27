
/* $destdir\u06.c        Machine generated C code */

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


/* Code for token1 */

static Lisp_Object MS_CDECL CC_token1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0130, v0131, v0132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "token1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for token1");
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
    v0130 = qvalue(elt(env, 1)); /* crchar!* */
    stack[-3] = v0130;
    goto v0133;

v0133:
    v0130 = stack[-3];
    v0130 = Lwhitespace_char_p(nil, v0130);
    env = stack[-4];
    if (v0130 == nil) goto v0134;
    v0131 = stack[-3];
    v0130 = qvalue(elt(env, 2)); /* !$eol!$ */
    if (v0131 == v0130) goto v0135;
    v0130 = qvalue(elt(env, 4)); /* nil */
    goto v0136;

v0136:
    if (!(v0130 == nil)) goto v0134;
    fn = elt(env, 35); /* readch1 */
    v0130 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    stack[-3] = v0130;
    goto v0133;

v0134:
    v0130 = stack[-3];
    v0130 = Ldigitp(nil, v0130);
    env = stack[-4];
    if (v0130 == nil) goto v0138;
    v0130 = stack[-3];
    {
        popv(5);
        fn = elt(env, 36); /* token!-number */
        return (*qfn1(fn))(qenv(fn), v0130);
    }

v0138:
    v0130 = stack[-3];
    v0130 = Lalpha_char_p(nil, v0130);
    env = stack[-4];
    if (!(v0130 == nil)) goto v0139;
    v0131 = stack[-3];
    v0130 = elt(env, 5); /* tokprop */
    v0130 = get(v0131, v0130);
    env = stack[-4];
    stack[-2] = v0130;
    if (v0130 == nil) goto v0140;
    v0131 = stack[-2];
    v0130 = qvalue(elt(env, 4)); /* nil */
    {
        popv(5);
        fn = elt(env, 37); /* lispapply */
        return (*qfn2(fn))(qenv(fn), v0131, v0130);
    }

v0140:
    v0131 = stack[-3];
    v0130 = elt(env, 6); /* !% */
    if (v0131 == v0130) goto v0141;
    v0130 = qvalue(elt(env, 4)); /* nil */
    goto v0142;

v0142:
    if (v0130 == nil) goto v0143;
    stack[-1] = qvalue(elt(env, 20)); /* !*lower */
    qvalue(elt(env, 20)) = nil; /* !*lower */
    v0130 = qvalue(elt(env, 21)); /* !*raise */
    stack[0] = v0130;
    v0130 = qvalue(elt(env, 4)); /* nil */
    qvalue(elt(env, 21)) = v0130; /* !*raise */
    goto v0144;

v0144:
    fn = elt(env, 35); /* readch1 */
    v0131 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[-4];
    v0130 = qvalue(elt(env, 2)); /* !$eol!$ */
    if (!(v0131 == v0130)) goto v0144;
    v0130 = stack[0];
    qvalue(elt(env, 21)) = v0130; /* !*raise */
    qvalue(elt(env, 20)) = stack[-1]; /* !*lower */
    fn = elt(env, 35); /* readch1 */
    v0130 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    stack[-3] = v0130;
    goto v0133;

v0143:
    v0131 = stack[-3];
    v0130 = elt(env, 8); /* !! */
    if (v0131 == v0130) goto v0146;
    v0130 = qvalue(elt(env, 4)); /* nil */
    goto v0147;

v0147:
    if (!(v0130 == nil)) goto v0148;
    v0131 = stack[-3];
    v0130 = elt(env, 11); /* !" */
    if (v0131 == v0130) goto v0149;
    v0130 = (Lisp_Object)49; /* 3 */
    qvalue(elt(env, 12)) = v0130; /* ttype!* */
    v0131 = stack[-3];
    v0130 = qvalue(elt(env, 13)); /* !$eof!$ */
    if (!(v0131 == v0130)) goto v0150;
    v0130 = elt(env, 14); /* !  */
    qvalue(elt(env, 1)) = v0130; /* crchar!* */
    fn = elt(env, 38); /* filenderr */
    v0130 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    goto v0150;

v0150:
    v0130 = stack[-3];
    qvalue(elt(env, 15)) = v0130; /* nxtsym!* */
    v0131 = stack[-3];
    v0130 = elt(env, 16); /* delchar */
    v0130 = Lflagp(nil, v0131, v0130);
    env = stack[-4];
    if (v0130 == nil) goto v0151;
    v0130 = elt(env, 14); /* !  */
    qvalue(elt(env, 1)) = v0130; /* crchar!* */
    goto v0152;

v0152:
    v0131 = stack[-3];
    v0130 = elt(env, 17); /* !- */
    if (v0131 == v0130) goto v0153;
    v0130 = qvalue(elt(env, 4)); /* nil */
    goto v0154;

v0154:
    if (v0130 == nil) goto v0155;
    v0130 = qvalue(elt(env, 1)); /* crchar!* */
    fn = elt(env, 36); /* token!-number */
    v0130 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    stack[-3] = v0130;
    v0130 = stack[-3];
    if (is_number(v0130)) goto v0156;
    v0130 = stack[-3];
    stack[0] = qcdr(v0130);
    v0131 = elt(env, 19); /* minus */
    v0130 = stack[-3];
    v0130 = qcdr(v0130);
    v0130 = qcar(v0130);
    v0130 = Lapply1(nil, v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    v0130 = Lrplaca(nil, stack[0], v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v0156:
    v0131 = elt(env, 19); /* minus */
    v0130 = stack[-3];
        popv(5);
        return Lapply1(nil, v0131, v0130);

v0155:
    v0130 = qvalue(elt(env, 15)); /* nxtsym!* */
    { popv(5); return onevalue(v0130); }

v0153:
    v0130 = qvalue(elt(env, 1)); /* crchar!* */
    v0130 = Ldigitp(nil, v0130);
    env = stack[-4];
    if (v0130 == nil) goto v0157;
    v0130 = qvalue(elt(env, 18)); /* !*minusliter */
    goto v0154;

v0157:
    v0130 = qvalue(elt(env, 4)); /* nil */
    goto v0154;

v0151:
    fn = elt(env, 35); /* readch1 */
    v0130 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    qvalue(elt(env, 1)) = v0130; /* crchar!* */
    goto v0152;

v0149:
    stack[0] = qvalue(elt(env, 20)); /* !*lower */
    qvalue(elt(env, 20)) = nil; /* !*lower */
    v0130 = qvalue(elt(env, 21)); /* !*raise */
    stack[-1] = v0130;
    v0130 = qvalue(elt(env, 4)); /* nil */
    qvalue(elt(env, 21)) = v0130; /* !*raise */
    goto v0158;

v0158:
    v0131 = stack[-3];
    v0130 = stack[-2];
    v0130 = cons(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-4];
    stack[-2] = v0130;
    fn = elt(env, 35); /* readch1 */
    v0131 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-4];
    stack[-3] = v0131;
    v0130 = qvalue(elt(env, 13)); /* !$eof!$ */
    if (v0131 == v0130) goto v0160;
    v0131 = stack[-3];
    v0130 = elt(env, 11); /* !" */
    if (!(v0131 == v0130)) goto v0158;

v0161:
    v0131 = stack[-3];
    v0130 = stack[-2];
    v0130 = cons(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-4];
    stack[-2] = v0130;
    fn = elt(env, 35); /* readch1 */
    v0130 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-4];
    stack[-3] = v0130;
    v0131 = stack[-3];
    v0130 = elt(env, 11); /* !" */
    if (v0131 == v0130) goto v0158;
    v0130 = stack[-2];
    v0130 = Lnreverse(nil, v0130);
    env = stack[-4];
    v0130 = Lcompress(nil, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-4];
    qvalue(elt(env, 15)) = v0130; /* nxtsym!* */
    v0130 = stack[-1];
    qvalue(elt(env, 21)) = v0130; /* !*raise */
    qvalue(elt(env, 20)) = stack[0]; /* !*lower */
    v0130 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 12)) = v0130; /* ttype!* */
    v0130 = stack[-3];
    qvalue(elt(env, 1)) = v0130; /* crchar!* */
    goto v0155;

v0160:
    v0130 = stack[-1];
    qvalue(elt(env, 21)) = v0130; /* !*raise */
    v0130 = elt(env, 14); /* !  */
    qvalue(elt(env, 1)) = v0130; /* crchar!* */
    v0131 = elt(env, 34); /* "***** End-of-file in string" */
    v0130 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 39); /* lpriw */
    v0130 = (*qfn2(fn))(qenv(fn), v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-4];
    fn = elt(env, 38); /* filenderr */
    v0130 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-4];
    goto v0161;

v0148:
    stack[0] = qvalue(elt(env, 20)); /* !*lower */
    qvalue(elt(env, 20)) = nil; /* !*lower */
    v0130 = qvalue(elt(env, 21)); /* !*raise */
    stack[-1] = v0130;
    v0130 = qvalue(elt(env, 4)); /* nil */
    qvalue(elt(env, 21)) = v0130; /* !*raise */
    v0131 = stack[-3];
    v0130 = stack[-2];
    v0130 = cons(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-4];
    stack[-2] = v0130;
    fn = elt(env, 35); /* readch1 */
    v0130 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-4];
    stack[-3] = v0130;
    v0130 = stack[-1];
    qvalue(elt(env, 21)) = v0130; /* !*raise */
    qvalue(elt(env, 20)) = stack[0]; /* !*lower */
    goto v0139;

v0139:
    v0130 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 12)) = v0130; /* ttype!* */
    goto v0163;

v0163:
    v0131 = stack[-3];
    v0130 = stack[-2];
    v0130 = cons(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    stack[-2] = v0130;
    fn = elt(env, 35); /* readch1 */
    v0130 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    stack[-3] = v0130;
    v0130 = Ldigitp(nil, v0130);
    env = stack[-4];
    if (!(v0130 == nil)) goto v0163;
    v0130 = stack[-3];
    v0130 = Lalpha_char_p(nil, v0130);
    env = stack[-4];
    if (!(v0130 == nil)) goto v0163;
    v0131 = stack[-3];
    v0130 = elt(env, 8); /* !! */
    if (v0131 == v0130) goto v0148;
    v0131 = stack[-3];
    v0130 = elt(env, 17); /* !- */
    if (v0131 == v0130) goto v0164;
    v0130 = qvalue(elt(env, 4)); /* nil */
    goto v0165;

v0165:
    if (v0130 == nil) goto v0166;
    v0131 = elt(env, 8); /* !! */
    v0130 = stack[-2];
    v0130 = cons(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    stack[-2] = v0130;
    goto v0163;

v0166:
    v0131 = stack[-3];
    v0130 = elt(env, 22); /* !_ */
    if (v0131 == v0130) goto v0163;
    v0131 = stack[-3];
    v0130 = elt(env, 23); /* !: */
    if (!(v0131 == v0130)) goto v0167;
    fn = elt(env, 35); /* readch1 */
    v0130 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    stack[-3] = v0130;
    v0131 = stack[-3];
    v0130 = elt(env, 23); /* !: */
    if (v0131 == v0130) goto v0168;
    v0130 = stack[-3];
    v0130 = Lalpha_char_p(nil, v0130);
    env = stack[-4];
    if (v0130 == nil) goto v0169;
    v0130 = stack[-3];
    v0130 = ncons(v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    qvalue(elt(env, 26)) = v0130; /* peekchar!* */
    v0130 = elt(env, 23); /* !: */
    stack[-3] = v0130;
    v0130 = qvalue(elt(env, 27)); /* !*report_colons */
    if (v0130 == nil) goto v0167;
    v0130 = qvalue(elt(env, 28)); /* !*msg */
    if (v0130 == nil) goto v0167;
    stack[-1] = elt(env, 29); /* "***" */
    stack[0] = elt(env, 30); /* "Symbol with colon in starts as" */
    v0130 = stack[-2];
    v0130 = Lreverse(nil, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    v0130 = Lcompress(nil, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    v0130 = list2(stack[0], v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    fn = elt(env, 39); /* lpriw */
    v0130 = (*qfn2(fn))(qenv(fn), stack[-1], v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    goto v0167;

v0167:
    v0130 = stack[-2];
    v0130 = Lnreverse(nil, v0130);
    env = stack[-4];
    v0130 = Lcompress(nil, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    v0130 = Lintern(nil, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    stack[-2] = v0130;
    v0131 = stack[-2];
    v0130 = qvalue(elt(env, 24)); /* !*line!-marker */
    if (equal(v0131, v0130)) goto v0170;
    v0130 = stack[-2];
    qvalue(elt(env, 15)) = v0130; /* nxtsym!* */
    goto v0171;

v0171:
    v0130 = stack[-3];
    qvalue(elt(env, 1)) = v0130; /* crchar!* */
    goto v0155;

v0170:
    v0130 = qvalue(elt(env, 25)); /* curline!* */
    qvalue(elt(env, 15)) = v0130; /* nxtsym!* */
    goto v0171;

v0169:
    v0130 = stack[-3];
    v0130 = ncons(v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    qvalue(elt(env, 26)) = v0130; /* peekchar!* */
    v0130 = elt(env, 23); /* !: */
    stack[-3] = v0130;
    goto v0167;

v0168:
    fn = elt(env, 35); /* readch1 */
    v0130 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    stack[-3] = v0130;
    v0130 = stack[-3];
    v0130 = Lalpha_char_p(nil, v0130);
    env = stack[-4];
    if (v0130 == nil) goto v0172;
    v0131 = elt(env, 23); /* !: */
    v0130 = stack[-3];
    v0130 = list2(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    qvalue(elt(env, 26)) = v0130; /* peekchar!* */
    v0130 = elt(env, 23); /* !: */
    stack[-3] = v0130;
    v0130 = qvalue(elt(env, 27)); /* !*report_colons */
    if (v0130 == nil) goto v0167;
    v0130 = qvalue(elt(env, 28)); /* !*msg */
    if (v0130 == nil) goto v0167;
    stack[-1] = elt(env, 29); /* "***" */
    stack[0] = elt(env, 32); /* "Symbol with double colon in starts as" 
*/
    v0130 = stack[-2];
    v0130 = Lreverse(nil, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    v0130 = Lcompress(nil, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    v0130 = list2(stack[0], v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    fn = elt(env, 39); /* lpriw */
    v0130 = (*qfn2(fn))(qenv(fn), stack[-1], v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    goto v0167;

v0172:
    v0131 = elt(env, 23); /* !: */
    v0130 = stack[-3];
    v0130 = list2(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    qvalue(elt(env, 26)) = v0130; /* peekchar!* */
    v0130 = elt(env, 23); /* !: */
    stack[-3] = v0130;
    goto v0167;

v0164:
    v0130 = qvalue(elt(env, 18)); /* !*minusliter */
    goto v0165;

v0146:
    v0130 = qvalue(elt(env, 9)); /* !*micro!-version */
    if (v0130 == nil) goto v0173;
    v0130 = qvalue(elt(env, 10)); /* !*defn */
    v0130 = (v0130 == nil ? lisp_true : nil);
    goto v0174;

v0174:
    v0130 = (v0130 == nil ? lisp_true : nil);
    goto v0147;

v0173:
    v0130 = qvalue(elt(env, 4)); /* nil */
    goto v0174;

v0141:
    v0130 = qvalue(elt(env, 7)); /* !*savecomments!* */
    v0130 = (v0130 == nil ? lisp_true : nil);
    goto v0142;

v0135:
    v0130 = qvalue(elt(env, 3)); /* !*eoldelimp */
    goto v0136;
/* error exit handlers */
v0162:
    env = stack[-4];
    qvalue(elt(env, 20)) = stack[0]; /* !*lower */
    popv(5);
    return nil;
v0159:
    env = stack[-4];
    qvalue(elt(env, 20)) = stack[0]; /* !*lower */
    popv(5);
    return nil;
v0145:
    env = stack[-4];
    qvalue(elt(env, 20)) = stack[-1]; /* !*lower */
    popv(5);
    return nil;
v0137:
    popv(5);
    return nil;
}



/* Code for dp_diff */

static Lisp_Object CC_dp_diff(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0177, v0168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_diff");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0177 = v0004;
    v0168 = v0175;
/* end of prologue */
    stack[0] = v0168;
    fn = elt(env, 1); /* dp_neg */
    v0177 = (*qfn1(fn))(qenv(fn), v0177);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-1];
    {
        Lisp_Object v0179 = stack[0];
        popv(2);
        fn = elt(env, 2); /* dp_sum */
        return (*qfn2(fn))(qenv(fn), v0179, v0177);
    }
/* error exit handlers */
v0178:
    popv(2);
    return nil;
}



/* Code for dquot */

static Lisp_Object CC_dquot(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0187, v0188, v0189;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dquot");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
    stack[-1] = v0175;
/* end of prologue */
    stack[-2] = nil;
    goto v0167;

v0167:
    v0187 = stack[-1];
    v0188 = qcar(v0187);
    v0187 = stack[0];
    v0187 = qcar(v0187);
    v0187 = difference2(v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-3];
    v0189 = v0187;
    v0188 = v0189;
    v0187 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v0188)) < ((int32_t)(v0187))) goto v0191;
    v0188 = v0189;
    v0187 = stack[-2];
    v0187 = cons(v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-3];
    stack[-2] = v0187;
    v0187 = stack[0];
    v0187 = qcdr(v0187);
    stack[0] = v0187;
    v0187 = stack[-1];
    v0187 = qcdr(v0187);
    stack[-1] = v0187;
    v0187 = stack[0];
    if (!(v0187 == nil)) goto v0167;
    v0187 = stack[-2];
        popv(4);
        return Lnreverse(nil, v0187);

v0191:
    v0187 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0187); }
/* error exit handlers */
v0190:
    popv(4);
    return nil;
}



/* Code for pv_sort1 */

static Lisp_Object CC_pv_sort1(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0194, v0195;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_sort1");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
    stack[-1] = v0175;
/* end of prologue */

v0133:
    v0194 = stack[-1];
    if (v0194 == nil) goto v0176;
    v0194 = stack[-1];
    v0194 = qcar(v0194);
    v0195 = qcdr(v0194);
    v0194 = stack[0];
    v0194 = qcar(v0194);
    v0194 = qcdr(v0194);
    v0194 = (Lisp_Object)lessp2(v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    v0194 = v0194 ? lisp_true : nil;
    env = stack[-3];
    if (v0194 == nil) goto v0126;
    v0194 = stack[-1];
    v0194 = qcdr(v0194);
    stack[-2] = v0194;
    v0194 = stack[-1];
    v0195 = qcar(v0194);
    v0194 = stack[0];
    v0194 = cons(v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    stack[0] = v0194;
    v0194 = stack[-2];
    stack[-1] = v0194;
    goto v0133;

v0126:
    v0194 = stack[-1];
    v0194 = qcdr(v0194);
    stack[-2] = v0194;
    v0194 = stack[-1];
    v0195 = qcar(v0194);
    v0194 = stack[0];
    fn = elt(env, 1); /* pv_sort2 */
    v0194 = (*qfn2(fn))(qenv(fn), v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    stack[0] = v0194;
    v0194 = stack[-2];
    stack[-1] = v0194;
    goto v0133;

v0176:
    v0194 = stack[0];
        popv(4);
        return Lnreverse(nil, v0194);
/* error exit handlers */
v0196:
    popv(4);
    return nil;
}



/* Code for general!-modular!-reciprocal */

static Lisp_Object CC_generalKmodularKreciprocal(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0194, v0195, v0190, v0201;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-reciprocal");
#endif
    if (stack >= stacklimit)
    {
        push(v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0175);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0175;
/* end of prologue */
    v0194 = qvalue(elt(env, 1)); /* !*balanced_mod */
    if (v0194 == nil) goto v0127;
    v0195 = stack[0];
    v0194 = (Lisp_Object)1; /* 0 */
    v0194 = (Lisp_Object)lessp2(v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    v0194 = v0194 ? lisp_true : nil;
    env = stack[-2];
    if (v0194 == nil) goto v0127;
    stack[-1] = qvalue(elt(env, 2)); /* current!-modulus */
    v0195 = stack[0];
    v0194 = qvalue(elt(env, 2)); /* current!-modulus */
    v0190 = plus2(v0195, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-2];
    v0195 = (Lisp_Object)1; /* 0 */
    v0194 = (Lisp_Object)17; /* 1 */
    {
        Lisp_Object v0203 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* general!-reciprocal!-by!-gcd */
        return (*qfnn(fn))(qenv(fn), 4, v0203, v0190, v0195, v0194);
    }

v0127:
    v0201 = qvalue(elt(env, 2)); /* current!-modulus */
    v0190 = stack[0];
    v0195 = (Lisp_Object)1; /* 0 */
    v0194 = (Lisp_Object)17; /* 1 */
    {
        popv(3);
        fn = elt(env, 3); /* general!-reciprocal!-by!-gcd */
        return (*qfnn(fn))(qenv(fn), 4, v0201, v0190, v0195, v0194);
    }
/* error exit handlers */
v0202:
    popv(3);
    return nil;
}



/* Code for anform1 */

static Lisp_Object CC_anform1(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0213, v0214;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for anform1");
#endif
    if (stack >= stacklimit)
    {
        push(v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0175);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0175;
/* end of prologue */
    v0213 = stack[-1];
    v0213 = qcar(v0213);
    stack[-2] = v0213;
    v0213 = stack[-1];
    v0213 = qcdr(v0213);
    stack[-1] = v0213;
    v0213 = stack[-2];
    if (!consp(v0213)) goto v0155;
    v0213 = stack[-2];
    v0213 = CC_anform1(env, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    v0213 = stack[-1];
    {
        popv(4);
        fn = elt(env, 8); /* anforml */
        return (*qfn1(fn))(qenv(fn), v0213);
    }

v0155:
    v0213 = stack[-2];
    if (symbolp(v0213)) goto v0184;
    v0213 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0213); }

v0184:
    v0214 = stack[-2];
    v0213 = elt(env, 2); /* dclglb */
    v0213 = Lflagp(nil, v0214, v0213);
    env = stack[-3];
    if (v0213 == nil) goto v0216;
    v0214 = stack[-2];
    v0213 = elt(env, 3); /* glb2rf */
    v0213 = Lflagp(nil, v0214, v0213);
    env = stack[-3];
    if (!(v0213 == nil)) goto v0198;
    v0213 = stack[-2];
    v0214 = ncons(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    v0213 = elt(env, 3); /* glb2rf */
    v0213 = Lflag(nil, v0214, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    v0214 = stack[-2];
    v0213 = qvalue(elt(env, 4)); /* globs!* */
    v0213 = cons(v0214, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    qvalue(elt(env, 4)) = v0213; /* globs!* */
    goto v0198;

v0198:
    v0213 = stack[-1];
    {
        popv(4);
        fn = elt(env, 8); /* anforml */
        return (*qfn1(fn))(qenv(fn), v0213);
    }

v0216:
    v0214 = stack[-2];
    v0213 = qvalue(elt(env, 5)); /* locls!* */
    v0213 = Lassoc(nil, v0214, v0213);
    if (v0213 == nil) goto v0149;
    v0213 = stack[-1];
    {
        popv(4);
        fn = elt(env, 8); /* anforml */
        return (*qfn1(fn))(qenv(fn), v0213);
    }

v0149:
    v0213 = stack[-2];
    fn = elt(env, 9); /* add2calls */
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    stack[0] = stack[-2];
    v0213 = stack[-1];
    v0213 = Llength(nil, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    fn = elt(env, 10); /* checkargcount */
    v0213 = (*qfn2(fn))(qenv(fn), stack[0], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    v0214 = stack[-2];
    v0213 = elt(env, 6); /* noanl */
    v0213 = Lflagp(nil, v0214, v0213);
    env = stack[-3];
    if (!(v0213 == nil)) goto v0217;
    v0214 = stack[-2];
    v0213 = elt(env, 7); /* anlfn */
    v0213 = get(v0214, v0213);
    env = stack[-3];
    v0214 = v0213;
    if (v0213 == nil) goto v0218;
    v0213 = stack[-1];
    v0213 = Lapply1(nil, v0214, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    goto v0217;

v0217:
    v0213 = nil;
    { popv(4); return onevalue(v0213); }

v0218:
    v0213 = stack[-1];
    fn = elt(env, 8); /* anforml */
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    goto v0217;
/* error exit handlers */
v0215:
    popv(4);
    return nil;
}



/* Code for lto_catsoc */

static Lisp_Object CC_lto_catsoc(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0219, v0149;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_catsoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0219 = v0004;
    v0149 = v0175;
/* end of prologue */
    v0219 = Latsoc(nil, v0149, v0219);
    v0149 = v0219;
    v0219 = v0149;
    if (v0219 == nil) goto v0178;
    v0219 = v0149;
    v0219 = qcdr(v0219);
    return onevalue(v0219);

v0178:
    v0219 = nil;
    return onevalue(v0219);
}



/* Code for gcdf1 */

static Lisp_Object CC_gcdf1(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0163, v0241;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdf1");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0004;
    stack[-2] = v0175;
/* end of prologue */
    v0163 = stack[-2];
    if (v0163 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0163 = stack[-1];
    if (v0163 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0241 = stack[-2];
    v0163 = (Lisp_Object)17; /* 1 */
    if (v0241 == v0163) goto v0149;
    v0241 = stack[-1];
    v0163 = (Lisp_Object)17; /* 1 */
    v0163 = (v0241 == v0163 ? lisp_true : nil);
    goto v0219;

v0219:
    if (v0163 == nil) goto v0242;
    v0163 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0163); }

v0242:
    v0163 = stack[-2];
    if (!consp(v0163)) goto v0211;
    v0163 = stack[-2];
    v0163 = qcar(v0163);
    v0163 = (consp(v0163) ? nil : lisp_true);
    goto v0243;

v0243:
    if (v0163 == nil) goto v0244;
    v0241 = qvalue(elt(env, 2)); /* dmode!* */
    v0163 = elt(env, 3); /* field */
    v0163 = Lflagp(nil, v0241, v0163);
    env = stack[-4];
    if (v0163 == nil) goto v0245;
    v0163 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0163); }

v0245:
    v0241 = stack[-2];
    v0163 = stack[-1];
    {
        popv(5);
        fn = elt(env, 10); /* gcdfd1 */
        return (*qfn2(fn))(qenv(fn), v0241, v0163);
    }

v0244:
    v0163 = stack[-1];
    if (!consp(v0163)) goto v0140;
    v0163 = stack[-1];
    v0163 = qcar(v0163);
    v0163 = (consp(v0163) ? nil : lisp_true);
    goto v0246;

v0246:
    if (v0163 == nil) goto v0142;
    v0241 = qvalue(elt(env, 2)); /* dmode!* */
    v0163 = elt(env, 3); /* field */
    v0163 = Lflagp(nil, v0241, v0163);
    env = stack[-4];
    if (v0163 == nil) goto v0115;
    v0163 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0163); }

v0115:
    v0241 = stack[-1];
    v0163 = stack[-2];
    {
        popv(5);
        fn = elt(env, 10); /* gcdfd1 */
        return (*qfn2(fn))(qenv(fn), v0241, v0163);
    }

v0142:
    v0163 = qvalue(elt(env, 4)); /* !*anygcd */
    if (v0163 == nil) goto v0247;
    v0163 = stack[-2];
    fn = elt(env, 11); /* num!-exponents */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-4];
    if (v0163 == nil) goto v0214;
    v0163 = stack[-1];
    fn = elt(env, 11); /* num!-exponents */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-4];
    v0163 = (v0163 == nil ? lisp_true : nil);
    goto v0248;

v0248:
    if (!(v0163 == nil)) goto v0249;
    v0241 = stack[-2];
    v0163 = stack[-1];
    fn = elt(env, 12); /* quotf1 */
    v0163 = (*qfn2(fn))(qenv(fn), v0241, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-4];
    if (!(v0163 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0241 = stack[-1];
    v0163 = stack[-2];
    fn = elt(env, 12); /* quotf1 */
    v0163 = (*qfn2(fn))(qenv(fn), v0241, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-4];
    if (!(v0163 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v0249:
    v0241 = stack[-2];
    v0163 = stack[-1];
    fn = elt(env, 13); /* gcdf2 */
    v0163 = (*qfn2(fn))(qenv(fn), v0241, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-4];
    stack[-3] = v0163;
    v0163 = qvalue(elt(env, 5)); /* !*gcd */
    if (v0163 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v0241 = qvalue(elt(env, 2)); /* dmode!* */
    v0163 = elt(env, 6); /* (!:rd!: !:cr!:) */
    v0163 = Lmemq(nil, v0241, v0163);
    if (v0163 == nil) goto v0250;
    v0163 = qvalue(elt(env, 7)); /* nil */
    goto v0152;

v0152:
    if (v0163 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v0163 = qvalue(elt(env, 8)); /* !*ncmp */
    if (v0163 == nil) goto v0098;
    v0163 = stack[-2];
    fn = elt(env, 14); /* noncomfp1 */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-4];
    if (!(v0163 == nil)) goto v0251;

v0098:
    v0163 = qvalue(elt(env, 8)); /* !*ncmp */
    if (v0163 == nil) goto v0252;
    v0163 = stack[-1];
    fn = elt(env, 14); /* noncomfp1 */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-4];
    if (!(v0163 == nil)) goto v0251;

v0252:
    stack[0] = elt(env, 9); /* "gcdf failed" */
    v0163 = stack[-2];
    fn = elt(env, 15); /* prepf */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-4];
    v0163 = stack[-1];
    fn = elt(env, 15); /* prepf */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-4];
    v0163 = list3(stack[0], stack[-2], v0163);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-4];
    fn = elt(env, 16); /* errach */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v0251:
    v0163 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0163); }

v0250:
    v0241 = stack[-2];
    v0163 = stack[-3];
    fn = elt(env, 12); /* quotf1 */
    v0163 = (*qfn2(fn))(qenv(fn), v0241, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-4];
    if (v0163 == nil) goto v0253;
    v0241 = stack[-1];
    v0163 = stack[-3];
    fn = elt(env, 12); /* quotf1 */
    v0163 = (*qfn2(fn))(qenv(fn), v0241, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-4];
    v0163 = (v0163 == nil ? lisp_true : nil);
    goto v0152;

v0253:
    v0163 = qvalue(elt(env, 1)); /* t */
    goto v0152;

v0214:
    v0163 = qvalue(elt(env, 1)); /* t */
    goto v0248;

v0247:
    v0163 = qvalue(elt(env, 1)); /* t */
    goto v0248;

v0140:
    v0163 = qvalue(elt(env, 1)); /* t */
    goto v0246;

v0211:
    v0163 = qvalue(elt(env, 1)); /* t */
    goto v0243;

v0149:
    v0163 = qvalue(elt(env, 1)); /* t */
    goto v0219;
/* error exit handlers */
v0093:
    popv(5);
    return nil;
}



/* Code for resimp1 */

static Lisp_Object CC_resimp1(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0125, v0136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resimp1");
#endif
    if (stack >= stacklimit)
    {
        push(v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0175);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0175;
/* end of prologue */
    v0125 = stack[0];
    v0136 = qcar(v0125);
    v0125 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* subf1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0136, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-2];
    v0125 = stack[0];
    v0136 = qcdr(v0125);
    v0125 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* subf1 */
    v0125 = (*qfn2(fn))(qenv(fn), v0136, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-2];
    fn = elt(env, 5); /* invsq */
    v0125 = (*qfn1(fn))(qenv(fn), v0125);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-2];
    fn = elt(env, 6); /* multsq */
    v0125 = (*qfn2(fn))(qenv(fn), stack[-1], v0125);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-2];
    stack[0] = v0125;
    v0125 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 3)) = v0125; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v0200:
    popv(3);
    return nil;
}



/* Code for rl_susibin */

static Lisp_Object CC_rl_susibin(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0186, v0219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_susibin");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0186 = v0004;
    v0219 = v0175;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_susibin!* */
    v0186 = list2(v0219, v0186);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-1];
    {
        Lisp_Object v0254 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0254, v0186);
    }
/* error exit handlers */
v0191:
    popv(2);
    return nil;
}



/* Code for ibalp_varlat */

static Lisp_Object CC_ibalp_varlat(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0255;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_varlat");
#endif
    if (stack >= stacklimit)
    {
        push(v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0175);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0175;
/* end of prologue */
    v0255 = stack[0];
    fn = elt(env, 1); /* ibalp_arg2l */
    v0255 = (*qfn1(fn))(qenv(fn), v0255);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-2];
    fn = elt(env, 2); /* ibalp_varlt */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0255);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-2];
    v0255 = stack[0];
    fn = elt(env, 3); /* ibalp_arg2r */
    v0255 = (*qfn1(fn))(qenv(fn), v0255);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-2];
    fn = elt(env, 2); /* ibalp_varlt */
    v0255 = (*qfn1(fn))(qenv(fn), v0255);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-2];
    {
        Lisp_Object v0186 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* union */
        return (*qfn2(fn))(qenv(fn), v0186, v0255);
    }
/* error exit handlers */
v0242:
    popv(3);
    return nil;
}



/* Code for powers2 */

static Lisp_Object MS_CDECL CC_powers2(Lisp_Object env, int nargs,
                         Lisp_Object v0175, Lisp_Object v0004,
                         Lisp_Object v0007, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0256, v0216, v0257;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "powers2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powers2");
#endif
    if (stack >= stacklimit)
    {
        push3(v0007,v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0175,v0004,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0007;
    stack[-1] = v0004;
    stack[-2] = v0175;
/* end of prologue */

v0148:
    v0256 = stack[-2];
    if (!consp(v0256)) goto v0255;
    v0256 = stack[-2];
    v0256 = qcar(v0256);
    v0256 = (consp(v0256) ? nil : lisp_true);
    goto v0168;

v0168:
    if (v0256 == nil) goto v0258;
    v0256 = stack[-2];
    if (v0256 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0216 = stack[0];
    v0256 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); /* powers4 */
        return (*qfn2(fn))(qenv(fn), v0216, v0256);
    }

v0258:
    v0256 = stack[-2];
    v0256 = qcar(v0256);
    v0256 = qcdr(v0256);
    stack[-3] = v0256;
    v0256 = stack[-2];
    v0257 = qcdr(v0256);
    v0216 = stack[-1];
    v0256 = stack[0];
    v0256 = CC_powers2(env, 3, v0257, v0216, v0256);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-4];
    stack[-1] = v0256;
    v0256 = stack[-2];
    v0256 = qcar(v0256);
    v0216 = qcar(v0256);
    v0256 = stack[0];
    v0256 = cons(v0216, v0256);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-4];
    stack[0] = v0256;
    v0256 = stack[-3];
    stack[-2] = v0256;
    goto v0148;

v0255:
    v0256 = qvalue(elt(env, 1)); /* t */
    goto v0168;
/* error exit handlers */
v0122:
    popv(5);
    return nil;
}



/* Code for rl_sacat */

static Lisp_Object MS_CDECL CC_rl_sacat(Lisp_Object env, int nargs,
                         Lisp_Object v0175, Lisp_Object v0004,
                         Lisp_Object v0007, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0254, v0259, v0192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "rl_sacat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_sacat");
#endif
    if (stack >= stacklimit)
    {
        push3(v0007,v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0175,v0004,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0254 = v0007;
    v0259 = v0004;
    v0192 = v0175;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_sacat!* */
    v0254 = list3(v0192, v0259, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-1];
    {
        Lisp_Object v0193 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0193, v0254);
    }
/* error exit handlers */
v0134:
    popv(2);
    return nil;
}



/* Code for retattributes */

static Lisp_Object CC_retattributes(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0239, v0123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for retattributes");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
    stack[-1] = v0175;
/* end of prologue */

v0261:
    v0239 = stack[0];
    if (v0239 == nil) goto v0148;
    v0123 = stack[-1];
    v0239 = stack[0];
    v0239 = qcar(v0239);
    fn = elt(env, 2); /* find */
    v0239 = (*qfn2(fn))(qenv(fn), v0123, v0239);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-3];
    v0123 = v0239;
    if (v0123 == nil) goto v0195;
    v0123 = stack[0];
    v0123 = qcar(v0123);
    stack[-2] = list2(v0123, v0239);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-3];
    v0123 = stack[-1];
    v0239 = stack[0];
    v0239 = qcdr(v0239);
    v0239 = CC_retattributes(env, v0123, v0239);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    {
        Lisp_Object v0245 = stack[-2];
        popv(4);
        return cons(v0245, v0239);
    }

v0195:
    v0123 = stack[-1];
    v0239 = stack[0];
    v0239 = qcdr(v0239);
    stack[-1] = v0123;
    stack[0] = v0239;
    goto v0261;

v0148:
    v0239 = nil;
    { popv(4); return onevalue(v0239); }
/* error exit handlers */
v0257:
    popv(4);
    return nil;
}



/* Code for mintype */

static Lisp_Object CC_mintype(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0177, v0168;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mintype");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0177 = v0175;
/* end of prologue */
    v0168 = v0177;
    if (!consp(v0168)) return onevalue(v0177);
    v0177 = qcar(v0177);
    return onevalue(v0177);
}



/* Code for ident */

static Lisp_Object CC_ident(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object v0182;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ident");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0182 = v0175;
/* end of prologue */
    return onevalue(v0182);
}



/* Code for bcsum */

static Lisp_Object CC_bcsum(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0244, v0240, v0243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcsum");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
    stack[-1] = v0175;
/* end of prologue */
    v0244 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v0244 == nil) goto v0259;
    v0240 = stack[-1];
    v0244 = stack[0];
    v0244 = plus2(v0240, v0244);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v0244);
    }

v0259:
    v0243 = stack[-1];
    v0240 = stack[0];
    v0244 = elt(env, 2); /* plus2 */
    fn = elt(env, 4); /* bcint2op */
    v0244 = (*qfnn(fn))(qenv(fn), 3, v0243, v0240, v0244);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-2];
    if (!(v0244 == nil)) { popv(3); return onevalue(v0244); }
    v0240 = stack[-1];
    v0244 = stack[0];
    fn = elt(env, 5); /* addsq */
    v0244 = (*qfn2(fn))(qenv(fn), v0240, v0244);
    nil = C_nil;
    if (exception_pending()) goto v0263;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); /* bccheckz */
        return (*qfn1(fn))(qenv(fn), v0244);
    }
/* error exit handlers */
v0263:
    popv(3);
    return nil;
}



/* Code for evtdeg */

static Lisp_Object CC_evtdeg(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0264, v0134, v0193;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evtdeg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0134 = v0175;
/* end of prologue */
    v0264 = (Lisp_Object)1; /* 0 */
    goto v0133;

v0133:
    v0193 = v0134;
    if (v0193 == nil) return onevalue(v0264);
    v0193 = v0134;
    v0193 = qcar(v0193);
    v0264 = (Lisp_Object)(int32_t)((int32_t)v0193 + (int32_t)v0264 - TAG_FIXNUM);
    v0134 = qcdr(v0134);
    goto v0133;
}



/* Code for worderp */

static Lisp_Object CC_worderp(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0105, v0226, v0157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for worderp");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
    stack[-1] = v0175;
/* end of prologue */

v0275:
    v0105 = stack[-1];
    if (!consp(v0105)) goto v0138;
    v0105 = stack[-1];
    v0226 = qcar(v0105);
    v0105 = elt(env, 1); /* indexvar */
    v0105 = Lflagp(nil, v0226, v0105);
    env = stack[-2];
    if (v0105 == nil) goto v0211;
    v0105 = stack[0];
    if (!consp(v0105)) goto v0244;
    v0105 = stack[0];
    v0226 = qcar(v0105);
    v0105 = elt(env, 1); /* indexvar */
    v0105 = Lflagp(nil, v0226, v0105);
    env = stack[-2];
    goto v0155;

v0155:
    if (v0105 == nil) goto v0176;
    v0226 = stack[-1];
    v0105 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* indexvarordp */
        return (*qfn2(fn))(qenv(fn), v0226, v0105);
    }

v0176:
    v0105 = stack[-1];
    if (!consp(v0105)) goto v0210;
    v0226 = stack[-1];
    v0105 = qvalue(elt(env, 4)); /* kord!* */
    v0105 = Lmemq(nil, v0226, v0105);
    goto v0209;

v0209:
    if (v0105 == nil) goto v0202;
    v0105 = stack[0];
    if (!consp(v0105)) goto v0276;
    v0226 = stack[0];
    v0105 = qvalue(elt(env, 4)); /* kord!* */
    v0105 = Lmemq(nil, v0226, v0105);
    goto v0277;

v0277:
    if (v0105 == nil) goto v0117;
    v0226 = stack[-1];
    v0105 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* ordop */
        return (*qfn2(fn))(qenv(fn), v0226, v0105);
    }

v0117:
    v0105 = stack[0];
    fn = elt(env, 7); /* peel */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-2];
    v0157 = v0105;
    v0226 = stack[-1];
    v0105 = v0157;
    if (v0226 == v0105) goto v0235;
    v0105 = stack[-1];
    v0226 = v0157;
    stack[-1] = v0105;
    stack[0] = v0226;
    goto v0275;

v0235:
    v0105 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v0105); }

v0276:
    v0105 = qvalue(elt(env, 3)); /* t */
    goto v0277;

v0202:
    v0105 = stack[0];
    if (!consp(v0105)) goto v0279;
    v0226 = stack[0];
    v0105 = qvalue(elt(env, 4)); /* kord!* */
    v0105 = Lmemq(nil, v0226, v0105);
    goto v0280;

v0280:
    if (v0105 == nil) goto v0281;
    v0105 = stack[-1];
    fn = elt(env, 7); /* peel */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-2];
    v0157 = v0105;
    v0226 = v0157;
    v0105 = stack[0];
    if (v0226 == v0105) goto v0229;
    v0226 = v0157;
    v0105 = stack[0];
    stack[-1] = v0226;
    stack[0] = v0105;
    goto v0275;

v0229:
    v0105 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0105); }

v0281:
    v0105 = stack[-1];
    fn = elt(env, 7); /* peel */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-2];
    stack[-1] = v0105;
    v0105 = stack[0];
    fn = elt(env, 7); /* peel */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-2];
    stack[0] = v0105;
    goto v0275;

v0279:
    v0105 = qvalue(elt(env, 3)); /* t */
    goto v0280;

v0210:
    v0105 = qvalue(elt(env, 3)); /* t */
    goto v0209;

v0244:
    v0105 = qvalue(elt(env, 2)); /* nil */
    goto v0155;

v0211:
    v0105 = qvalue(elt(env, 2)); /* nil */
    goto v0155;

v0138:
    v0105 = qvalue(elt(env, 2)); /* nil */
    goto v0155;
/* error exit handlers */
v0278:
    popv(3);
    return nil;
}



/* Code for algid */

static Lisp_Object CC_algid(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0262, v0125, v0136;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for algid");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0262 = v0004;
    v0136 = v0175;
/* end of prologue */
    v0125 = v0136;
    v0262 = Latsoc(nil, v0125, v0262);
    if (!(v0262 == nil)) return onevalue(v0136);
    v0125 = v0136;
    v0262 = elt(env, 1); /* share */
    v0262 = Lflagp(nil, v0125, v0262);
    if (!(v0262 == nil)) return onevalue(v0136);
    v0262 = v0136;
        return Lmkquote(nil, v0262);
}



/* Code for layout!-formula */

static Lisp_Object MS_CDECL CC_layoutKformula(Lisp_Object env, int nargs,
                         Lisp_Object v0175, Lisp_Object v0004,
                         Lisp_Object v0007, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0286, v0272;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "layout-formula");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for layout-formula");
#endif
    if (stack >= stacklimit)
    {
        push3(v0007,v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0175,v0004,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0007;
    stack[-7] = v0004;
    stack[-8] = v0175;
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
    v0286 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 7)) = v0286; /* overflowed!* */
    qvalue(elt(env, 5)) = v0286; /* pline!* */
    v0286 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v0286; /* ymax!* */
    qvalue(elt(env, 2)) = v0286; /* ymin!* */
    qvalue(elt(env, 1)) = v0286; /* ycoord!* */
    v0286 = qvalue(elt(env, 9)); /* orig!* */
    qvalue(elt(env, 4)) = v0286; /* posn!* */
    v0286 = qvalue(elt(env, 10)); /* t */
    qvalue(elt(env, 6)) = v0286; /* testing!-width!* */
    v0286 = stack[-6];
    if (v0286 == nil) goto v0126;
    v0272 = stack[-6];
    v0286 = elt(env, 11); /* inbrackets */
    if (v0272 == v0286) goto v0192;
    v0286 = stack[-6];
    fn = elt(env, 14); /* oprin */
    v0286 = (*qfn1(fn))(qenv(fn), v0286);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-10];
    goto v0126;

v0126:
    v0272 = stack[-8];
    v0286 = stack[-7];
    fn = elt(env, 15); /* maprint */
    v0286 = (*qfn2(fn))(qenv(fn), v0272, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-10];
    v0272 = stack[-6];
    v0286 = elt(env, 11); /* inbrackets */
    if (!(v0272 == v0286)) goto v0138;
    v0286 = elt(env, 13); /* ")" */
    fn = elt(env, 16); /* prin2!* */
    v0286 = (*qfn1(fn))(qenv(fn), v0286);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-10];
    goto v0138;

v0138:
    v0286 = qvalue(elt(env, 7)); /* overflowed!* */
    if (v0286 == nil) goto v0257;
    v0286 = qvalue(elt(env, 8)); /* nil */
    goto v0177;

v0177:
    qvalue(elt(env, 7)) = stack[0]; /* overflowed!* */
    qvalue(elt(env, 6)) = stack[-1]; /* testing!-width!* */
    qvalue(elt(env, 5)) = stack[-2]; /* pline!* */
    qvalue(elt(env, 4)) = stack[-3]; /* posn!* */
    qvalue(elt(env, 3)) = stack[-4]; /* ymax!* */
    qvalue(elt(env, 2)) = stack[-5]; /* ymin!* */
    qvalue(elt(env, 1)) = stack[-9]; /* ycoord!* */
    { popv(11); return onevalue(v0286); }

v0257:
    stack[-7] = qvalue(elt(env, 5)); /* pline!* */
    v0272 = qvalue(elt(env, 4)); /* posn!* */
    v0286 = qvalue(elt(env, 9)); /* orig!* */
    stack[-6] = difference2(v0272, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-10];
    v0272 = qvalue(elt(env, 2)); /* ymin!* */
    v0286 = qvalue(elt(env, 3)); /* ymax!* */
    v0286 = cons(v0272, v0286);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-10];
    v0286 = acons(stack[-7], stack[-6], v0286);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-10];
    goto v0177;

v0192:
    v0286 = elt(env, 12); /* "(" */
    fn = elt(env, 16); /* prin2!* */
    v0286 = (*qfn1(fn))(qenv(fn), v0286);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-10];
    goto v0126;
/* error exit handlers */
v0117:
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



/* Code for !*collectphysops */

static Lisp_Object CC_Hcollectphysops(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0155, v0177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *collectphysops");
#endif
    if (stack >= stacklimit)
    {
        push(v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0175);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0155 = v0175;
/* end of prologue */
    v0177 = v0155;
    v0155 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* !*collectphysops_reversed */
    v0155 = (*qfn2(fn))(qenv(fn), v0177, v0155);
    errexit();
        return Lnreverse(nil, v0155);
}



/* Code for contrsp2 */

static Lisp_Object MS_CDECL CC_contrsp2(Lisp_Object env, int nargs,
                         Lisp_Object v0175, Lisp_Object v0004,
                         Lisp_Object v0007, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0203, v0209;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "contrsp2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contrsp2");
#endif
    if (stack >= stacklimit)
    {
        push3(v0007,v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0175,v0004,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0007;
    stack[-1] = v0004;
    stack[-2] = v0175;
/* end of prologue */
    stack[-3] = (Lisp_Object)33; /* 2 */
    v0203 = stack[-2];
    v0203 = Llength(nil, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0256;
    env = stack[-4];
    if (stack[-3] == v0203) goto v0149;
    v0203 = nil;
    { popv(5); return onevalue(v0203); }

v0149:
    v0209 = stack[0];
    v0203 = stack[-2];
    v0203 = qcar(v0203);
    if (equal(v0209, v0203)) goto v0185;
    v0209 = stack[0];
    v0203 = stack[-2];
    v0203 = qcdr(v0203);
    v0203 = qcar(v0203);
    if (equal(v0209, v0203)) goto v0187;
    v0203 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0203); }

v0187:
    v0203 = stack[-2];
    v0209 = qcar(v0203);
    v0203 = stack[-1];
    popv(5);
    return cons(v0209, v0203);

v0185:
    v0203 = stack[-2];
    v0203 = qcdr(v0203);
    v0209 = qcar(v0203);
    v0203 = stack[-1];
    popv(5);
    return cons(v0209, v0203);
/* error exit handlers */
v0256:
    popv(5);
    return nil;
}



/* Code for form1 */

static Lisp_Object MS_CDECL CC_form1(Lisp_Object env, int nargs,
                         Lisp_Object v0175, Lisp_Object v0004,
                         Lisp_Object v0007, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0368, v0369, v0370, v0371;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "form1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for form1");
#endif
    if (stack >= stacklimit)
    {
        push3(v0007,v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0175,v0004,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0007;
    stack[-2] = v0004;
    stack[-3] = v0175;
/* end of prologue */

v0261:
    v0368 = stack[-3];
    if (!consp(v0368)) goto v0167;
    v0368 = stack[-3];
    v0368 = qcar(v0368);
    if (!consp(v0368)) goto v0256;
    v0370 = stack[-3];
    v0369 = stack[-2];
    v0368 = stack[-1];
    {
        popv(6);
        fn = elt(env, 33); /* form2 */
        return (*qfnn(fn))(qenv(fn), 3, v0370, v0369, v0368);
    }

v0256:
    v0368 = stack[-3];
    v0368 = qcar(v0368);
    if (symbolp(v0368)) goto v0147;
    v0368 = stack[-3];
    v0369 = qcar(v0368);
    v0368 = elt(env, 4); /* "operator" */
    fn = elt(env, 34); /* typerr */
    v0368 = (*qfn2(fn))(qenv(fn), v0369, v0368);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-5];
    goto v0372;

v0372:
    v0369 = stack[-1];
    v0368 = elt(env, 9); /* symbolic */
    if (v0369 == v0368) goto v0373;
    v0368 = stack[-3];
    v0369 = qcar(v0368);
    v0368 = elt(env, 24); /* opfn */
    v0368 = Lflagp(nil, v0369, v0368);
    env = stack[-5];
    goto v0374;

v0374:
    if (v0368 == nil) goto v0375;
    v0368 = stack[-3];
    fn = elt(env, 35); /* argnochk */
    v0368 = (*qfn1(fn))(qenv(fn), v0368);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-5];
    goto v0375;

v0375:
    v0368 = stack[-3];
    v0370 = qcdr(v0368);
    v0369 = stack[-2];
    v0368 = stack[-1];
    fn = elt(env, 36); /* formlis */
    v0368 = (*qfnn(fn))(qenv(fn), 3, v0370, v0369, v0368);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-5];
    stack[-4] = v0368;
    v0369 = stack[-4];
    v0368 = stack[-3];
    v0368 = qcdr(v0368);
    if (equal(v0369, v0368)) goto v0376;
    v0368 = stack[-3];
    v0369 = qcar(v0368);
    v0368 = stack[-4];
    v0368 = cons(v0369, v0368);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-5];
    goto v0377;

v0377:
    stack[0] = v0368;
    v0369 = stack[-1];
    v0368 = elt(env, 9); /* symbolic */
    if (v0369 == v0368) goto v0056;
    v0368 = stack[-3];
    v0369 = qcar(v0368);
    v0368 = elt(env, 16); /* stat */
    v0368 = get(v0369, v0368);
    env = stack[-5];
    if (!(v0368 == nil)) goto v0378;
    v0368 = stack[-3];
    v0368 = qcdr(v0368);
    if (v0368 == nil) goto v0379;
    v0368 = stack[-3];
    v0368 = qcdr(v0368);
    v0369 = qcar(v0368);
    v0368 = elt(env, 25); /* quote */
    if (!consp(v0369)) goto v0380;
    v0369 = qcar(v0369);
    if (!(v0369 == v0368)) goto v0380;
    v0368 = qvalue(elt(env, 26)); /* !*micro!-version */
    if (v0368 == nil) goto v0381;
    v0368 = qvalue(elt(env, 27)); /* !*defn */
    v0368 = (v0368 == nil ? lisp_true : nil);
    goto v0382;

v0382:
    v0368 = (v0368 == nil ? lisp_true : nil);
    goto v0049;

v0049:
    if (!(v0368 == nil)) goto v0378;
    v0369 = stack[0];
    v0368 = stack[-2];
    fn = elt(env, 37); /* intexprnp */
    v0368 = (*qfn2(fn))(qenv(fn), v0369, v0368);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-5];
    if (v0368 == nil) goto v0383;
    v0368 = qvalue(elt(env, 28)); /* !*composites */
    if (v0368 == nil) goto v0042;
    v0368 = qvalue(elt(env, 10)); /* nil */
    goto v0378;

v0378:
    if (v0368 == nil) goto v0384;
    v0369 = stack[0];
    v0368 = stack[-1];
    {
        popv(6);
        fn = elt(env, 38); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v0369, v0368);
    }

v0384:
    v0369 = stack[-1];
    v0368 = elt(env, 30); /* algebraic */
    if (v0369 == v0368) goto v0385;
    v0370 = stack[0];
    v0369 = stack[-2];
    v0368 = elt(env, 30); /* algebraic */
    v0371 = CC_form1(env, 3, v0370, v0369, v0368);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-5];
    v0370 = stack[-2];
    v0369 = stack[-1];
    v0368 = elt(env, 30); /* algebraic */
    {
        popv(6);
        fn = elt(env, 39); /* convertmode1 */
        return (*qfnn(fn))(qenv(fn), 4, v0371, v0370, v0369, v0368);
    }

v0385:
    stack[0] = elt(env, 31); /* list */
    v0368 = stack[-3];
    v0369 = qcar(v0368);
    v0368 = stack[-2];
    v0368 = Latsoc(nil, v0369, v0368);
    if (!(v0368 == nil)) goto v0386;
    v0368 = stack[-3];
    v0369 = qcar(v0368);
    v0368 = elt(env, 32); /* share */
    v0368 = Lflagp(nil, v0369, v0368);
    env = stack[-5];
    if (!(v0368 == nil)) goto v0386;
    v0368 = stack[-3];
    v0368 = qcar(v0368);
    v0368 = Lmkquote(nil, v0368);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    v0369 = v0368;
    goto v0387;

v0387:
    v0368 = stack[-4];
    {
        Lisp_Object v0022 = stack[0];
        popv(6);
        return list2star(v0022, v0369, v0368);
    }

v0386:
    v0368 = stack[-3];
    v0368 = qcar(v0368);
    v0369 = v0368;
    goto v0387;

v0042:
    v0369 = qvalue(elt(env, 29)); /* current!-modulus */
    v0368 = (Lisp_Object)17; /* 1 */
    v0368 = (v0369 == v0368 ? lisp_true : nil);
    goto v0378;

v0383:
    v0368 = qvalue(elt(env, 10)); /* nil */
    goto v0378;

v0381:
    v0368 = qvalue(elt(env, 10)); /* nil */
    goto v0382;

v0380:
    v0368 = qvalue(elt(env, 10)); /* nil */
    goto v0049;

v0379:
    v0368 = qvalue(elt(env, 10)); /* nil */
    goto v0049;

v0056:
    v0368 = qvalue(elt(env, 13)); /* t */
    goto v0378;

v0376:
    v0368 = stack[-3];
    goto v0377;

v0373:
    v0368 = qvalue(elt(env, 13)); /* t */
    goto v0374;

v0147:
    v0368 = stack[-3];
    v0369 = qcar(v0368);
    v0368 = elt(env, 5); /* comment */
    if (v0369 == v0368) goto v0117;
    v0368 = stack[-3];
    v0369 = qcar(v0368);
    v0368 = elt(env, 6); /* noform */
    v0368 = Lflagp(nil, v0369, v0368);
    env = stack[-5];
    if (!(v0368 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0368 = stack[-3];
    v0369 = qcar(v0368);
    v0368 = elt(env, 7); /* rtype */
    v0369 = get(v0369, v0368);
    env = stack[-5];
    v0368 = elt(env, 8); /* array */
    if (v0369 == v0368) goto v0388;
    v0368 = qvalue(elt(env, 10)); /* nil */
    goto v0389;

v0389:
    if (v0368 == nil) goto v0274;
    stack[0] = elt(env, 11); /* getel */
    v0370 = stack[-3];
    v0369 = stack[-2];
    v0368 = stack[-1];
    fn = elt(env, 40); /* intargfn */
    v0368 = (*qfnn(fn))(qenv(fn), 3, v0370, v0369, v0368);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    {
        Lisp_Object v0390 = stack[0];
        popv(6);
        return list2(v0390, v0368);
    }

v0274:
    v0368 = stack[-3];
    v0368 = qcdr(v0368);
    if (v0368 == nil) goto v0391;
    v0368 = stack[-3];
    v0369 = qcar(v0368);
    v0368 = elt(env, 7); /* rtype */
    v0369 = get(v0369, v0368);
    env = stack[-5];
    v0368 = elt(env, 12); /* vector */
    if (v0369 == v0368) goto v0253;
    v0368 = stack[-3];
    v0368 = qcdr(v0368);
    v0368 = qcar(v0368);
    v0368 = Lsimple_vectorp(nil, v0368);
    env = stack[-5];
    if (!(v0368 == nil)) goto v0278;
    v0368 = stack[-3];
    v0368 = qcdr(v0368);
    v0369 = qcar(v0368);
    v0368 = elt(env, 14); /* vecfn */
    v0368 = Lflagpcar(nil, v0369, v0368);
    env = stack[-5];
    goto v0278;

v0278:
    if (v0368 == nil) goto v0391;
    v0370 = stack[-3];
    v0369 = stack[-2];
    v0368 = stack[-1];
    {
        popv(6);
        fn = elt(env, 41); /* getvect */
        return (*qfnn(fn))(qenv(fn), 3, v0370, v0369, v0368);
    }

v0391:
    v0368 = stack[-3];
    v0369 = qcar(v0368);
    v0368 = elt(env, 2); /* modefn */
    v0368 = Lflagp(nil, v0369, v0368);
    env = stack[-5];
    if (v0368 == nil) goto v0392;
    v0368 = stack[-3];
    v0368 = qcdr(v0368);
    v0370 = qcar(v0368);
    v0369 = stack[-2];
    v0368 = stack[-3];
    v0368 = qcar(v0368);
    v0371 = CC_form1(env, 3, v0370, v0369, v0368);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-5];
    v0370 = stack[-2];
    v0369 = stack[-1];
    v0368 = stack[-3];
    v0368 = qcar(v0368);
    {
        popv(6);
        fn = elt(env, 39); /* convertmode1 */
        return (*qfnn(fn))(qenv(fn), 4, v0371, v0370, v0369, v0368);
    }

v0392:
    v0368 = stack[-3];
    v0369 = qcar(v0368);
    v0368 = elt(env, 15); /* formfn */
    v0368 = get(v0369, v0368);
    env = stack[-5];
    stack[-4] = v0368;
    if (v0368 == nil) goto v0082;
    v0371 = stack[-4];
    v0370 = stack[-3];
    v0369 = stack[-2];
    v0368 = stack[-1];
    v0369 = Lapply3(nil, 4, v0371, v0370, v0369, v0368);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-5];
    v0368 = stack[-1];
    {
        popv(6);
        fn = elt(env, 38); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v0369, v0368);
    }

v0082:
    v0368 = stack[-3];
    v0369 = qcar(v0368);
    v0368 = elt(env, 16); /* stat */
    v0369 = get(v0369, v0368);
    env = stack[-5];
    v0368 = elt(env, 17); /* rlis */
    if (v0369 == v0368) goto v0393;
    v0368 = stack[-3];
    v0369 = qcar(v0368);
    v0368 = elt(env, 18); /* !*comma!* */
    if (!(v0369 == v0368)) goto v0372;
    v0368 = stack[-3];
    v0368 = qcdr(v0368);
    v0368 = qcar(v0368);
    if (!consp(v0368)) goto v0394;
    v0368 = stack[-3];
    v0368 = qcdr(v0368);
    v0368 = qcdr(v0368);
    v0368 = qcar(v0368);
    if (!consp(v0368)) goto v0395;
    v0368 = qvalue(elt(env, 10)); /* nil */
    goto v0396;

v0396:
    if (v0368 == nil) goto v0397;
    v0368 = stack[-3];
    v0368 = qcdr(v0368);
    v0368 = qcar(v0368);
    v0369 = qcar(v0368);
    v0368 = elt(env, 20); /* "invalid except at head of block" */
    v0368 = list2(v0369, v0368);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-5];
    v0369 = v0368;
    v0368 = v0369;
    qvalue(elt(env, 21)) = v0368; /* errmsg!* */
    v0368 = qvalue(elt(env, 22)); /* !*protfg */
    if (!(v0368 == nil)) goto v0398;
    v0368 = v0369;
    fn = elt(env, 42); /* lprie */
    v0368 = (*qfn1(fn))(qenv(fn), v0368);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-5];
    goto v0398;

v0398:
    v0368 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-5];
    goto v0372;

v0397:
    v0369 = elt(env, 23); /* "Syntax error: , invalid after" */
    v0368 = stack[-3];
    v0368 = qcdr(v0368);
    v0368 = qcar(v0368);
    v0368 = list2(v0369, v0368);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-5];
    v0369 = v0368;
    v0368 = v0369;
    qvalue(elt(env, 21)) = v0368; /* errmsg!* */
    v0368 = qvalue(elt(env, 22)); /* !*protfg */
    if (!(v0368 == nil)) goto v0399;
    v0368 = v0369;
    fn = elt(env, 42); /* lprie */
    v0368 = (*qfn1(fn))(qenv(fn), v0368);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-5];
    goto v0399;

v0399:
    v0368 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-5];
    goto v0372;

v0395:
    v0368 = stack[-3];
    v0368 = qcdr(v0368);
    v0368 = qcar(v0368);
    v0369 = qcar(v0368);
    v0368 = elt(env, 19); /* type */
    v0368 = Lflagp(nil, v0369, v0368);
    env = stack[-5];
    goto v0396;

v0394:
    v0368 = qvalue(elt(env, 10)); /* nil */
    goto v0396;

v0393:
    v0370 = stack[-3];
    v0369 = stack[-2];
    v0368 = stack[-1];
    fn = elt(env, 43); /* formrlis */
    v0369 = (*qfnn(fn))(qenv(fn), 3, v0370, v0369, v0368);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-5];
    v0368 = stack[-1];
    {
        popv(6);
        fn = elt(env, 38); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v0369, v0368);
    }

v0253:
    v0368 = qvalue(elt(env, 13)); /* t */
    goto v0278;

v0388:
    v0369 = stack[-1];
    v0368 = elt(env, 9); /* symbolic */
    v0368 = (v0369 == v0368 ? lisp_true : nil);
    goto v0389;

v0117:
    v0368 = stack[-3];
    fn = elt(env, 44); /* lastpair */
    v0368 = (*qfn1(fn))(qenv(fn), v0368);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-5];
    v0370 = qcar(v0368);
    v0369 = stack[-2];
    v0368 = stack[-1];
    stack[-3] = v0370;
    stack[-2] = v0369;
    stack[-1] = v0368;
    goto v0261;

v0167:
    v0368 = stack[-3];
    if (!(symbolp(v0368))) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0369 = stack[-3];
    v0368 = elt(env, 1); /* ed */
    if (v0369 == v0368) goto v0219;
    v0369 = stack[-3];
    v0368 = elt(env, 2); /* modefn */
    v0368 = Lflagp(nil, v0369, v0368);
    env = stack[-5];
    if (v0368 == nil) goto v0211;
    v0368 = stack[-3];
    {
        popv(6);
        fn = elt(env, 45); /* set!-global!-mode */
        return (*qfn1(fn))(qenv(fn), v0368);
    }

v0211:
    v0369 = stack[-1];
    v0368 = elt(env, 3); /* idfn */
    v0368 = get(v0369, v0368);
    stack[-4] = v0368;
    if (v0368 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0370 = stack[-4];
    v0369 = stack[-3];
    v0368 = stack[-2];
        popv(6);
        return Lapply2(nil, 3, v0370, v0369, v0368);

v0219:
    v0368 = stack[-3];
    popv(6);
    return ncons(v0368);
/* error exit handlers */
v0021:
    popv(6);
    return nil;
}



/* Code for simpdiff */

static Lisp_Object CC_simpdiff(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpdiff");
#endif
    if (stack >= stacklimit)
    {
        push(v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0175);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0175;
/* end of prologue */
    v0179 = stack[0];
    fn = elt(env, 1); /* ckpreci!# */
    v0179 = (*qfn1(fn))(qenv(fn), v0179);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-2];
    v0179 = stack[0];
    v0179 = qcar(v0179);
    fn = elt(env, 2); /* simp */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0179);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-2];
    v0179 = stack[0];
    v0179 = qcdr(v0179);
    fn = elt(env, 3); /* simpminus */
    v0179 = (*qfn1(fn))(qenv(fn), v0179);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-2];
    {
        Lisp_Object v0149 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0149, v0179);
    }
/* error exit handlers */
v0219:
    popv(3);
    return nil;
}



/* Code for mv!-pow!-minusp */

static Lisp_Object CC_mvKpowKminusp(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0264, v0134;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-minusp");
#endif
    if (stack >= stacklimit)
    {
        push(v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0175);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0175;
/* end of prologue */

v0261:
    v0264 = stack[0];
    if (v0264 == nil) goto v0183;
    v0264 = stack[0];
    v0134 = qcar(v0264);
    v0264 = (Lisp_Object)1; /* 0 */
    v0264 = (Lisp_Object)lessp2(v0134, v0264);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    v0264 = v0264 ? lisp_true : nil;
    env = stack[-1];
    if (!(v0264 == nil)) { popv(2); return onevalue(v0264); }
    v0264 = stack[0];
    v0264 = qcdr(v0264);
    stack[0] = v0264;
    goto v0261;

v0183:
    v0264 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0264); }
/* error exit handlers */
v0184:
    popv(2);
    return nil;
}



/* Code for dp_term */

static Lisp_Object CC_dp_term(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0155, v0177;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_term");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0155 = v0004;
    v0177 = v0175;
/* end of prologue */
    return cons(v0155, v0177);
}



/* Code for pcmult */

static Lisp_Object CC_pcmult(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0237, v0238;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pcmult");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0004;
    v0237 = v0175;
/* end of prologue */
    stack[-5] = v0237;
    v0237 = stack[-5];
    if (v0237 == nil) goto v0177;
    v0237 = stack[-5];
    v0237 = qcar(v0237);
    v0238 = v0237;
    stack[0] = qcar(v0238);
    v0238 = stack[-4];
    v0237 = qcdr(v0237);
    fn = elt(env, 2); /* cprod */
    v0237 = (*qfn2(fn))(qenv(fn), v0238, v0237);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-6];
    v0237 = cons(stack[0], v0237);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-6];
    v0237 = ncons(v0237);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-6];
    stack[-2] = v0237;
    stack[-3] = v0237;
    goto v0139;

v0139:
    v0237 = stack[-5];
    v0237 = qcdr(v0237);
    stack[-5] = v0237;
    v0237 = stack[-5];
    if (v0237 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v0237 = stack[-5];
    v0237 = qcar(v0237);
    v0238 = v0237;
    stack[0] = qcar(v0238);
    v0238 = stack[-4];
    v0237 = qcdr(v0237);
    fn = elt(env, 2); /* cprod */
    v0237 = (*qfn2(fn))(qenv(fn), v0238, v0237);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-6];
    v0237 = cons(stack[0], v0237);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-6];
    v0237 = ncons(v0237);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-6];
    v0237 = Lrplacd(nil, stack[-1], v0237);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-6];
    v0237 = stack[-2];
    v0237 = qcdr(v0237);
    stack[-2] = v0237;
    goto v0139;

v0177:
    v0237 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0237); }
/* error exit handlers */
v0276:
    popv(7);
    return nil;
}



/* Code for pv_applp */

static Lisp_Object CC_pv_applp(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0238, v0118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_applp");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0004;
    v0238 = v0175;
/* end of prologue */
    stack[-5] = v0238;
    v0238 = stack[-5];
    if (v0238 == nil) goto v0168;
    v0238 = stack[-5];
    v0238 = qcar(v0238);
    v0118 = v0238;
    v0238 = v0118;
    stack[0] = qcar(v0238);
    v0238 = v0118;
    v0118 = qcdr(v0238);
    v0238 = stack[-4];
    fn = elt(env, 2); /* pappl0 */
    v0238 = (*qfn2(fn))(qenv(fn), v0118, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-6];
    v0238 = cons(stack[0], v0238);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-6];
    v0238 = ncons(v0238);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-6];
    stack[-2] = v0238;
    stack[-3] = v0238;
    goto v0176;

v0176:
    v0238 = stack[-5];
    v0238 = qcdr(v0238);
    stack[-5] = v0238;
    v0238 = stack[-5];
    if (v0238 == nil) goto v0244;
    stack[-1] = stack[-2];
    v0238 = stack[-5];
    v0238 = qcar(v0238);
    v0118 = v0238;
    v0238 = v0118;
    stack[0] = qcar(v0238);
    v0238 = v0118;
    v0118 = qcdr(v0238);
    v0238 = stack[-4];
    fn = elt(env, 2); /* pappl0 */
    v0238 = (*qfn2(fn))(qenv(fn), v0118, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-6];
    v0238 = cons(stack[0], v0238);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-6];
    v0238 = ncons(v0238);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-6];
    v0238 = Lrplacd(nil, stack[-1], v0238);
    nil = C_nil;
    if (exception_pending()) goto v0285;
    env = stack[-6];
    v0238 = stack[-2];
    v0238 = qcdr(v0238);
    stack[-2] = v0238;
    goto v0176;

v0244:
    v0238 = stack[-3];
    goto v0139;

v0139:
    {
        popv(7);
        fn = elt(env, 3); /* pv_sort */
        return (*qfn1(fn))(qenv(fn), v0238);
    }

v0168:
    v0238 = qvalue(elt(env, 1)); /* nil */
    goto v0139;
/* error exit handlers */
v0285:
    popv(7);
    return nil;
}



/* Code for !*id2num */

static Lisp_Object CC_Hid2num(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0219, v0149;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *id2num");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0219 = v0175;
/* end of prologue */
    v0149 = qvalue(elt(env, 1)); /* pair_id_num!* */
    v0219 = Lassoc(nil, v0219, v0149);
    v0149 = v0219;
    if (v0219 == nil) goto v0133;
    v0219 = v0149;
    v0219 = qcdr(v0219);
    return onevalue(v0219);

v0133:
    v0219 = nil;
    return onevalue(v0219);
}



/* Code for aronep!: */

static Lisp_Object CC_aronepT(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0155, v0177;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aronep:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0155 = v0175;
/* end of prologue */
    v0177 = qcdr(v0155);
    v0155 = (Lisp_Object)17; /* 1 */
    v0155 = (v0177 == v0155 ? lisp_true : nil);
    return onevalue(v0155);
}



/* Code for exptmod!: */

static Lisp_Object CC_exptmodT(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0168, v0255;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptmod:");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0168 = v0004;
    v0255 = v0175;
/* end of prologue */
    v0255 = qcdr(v0255);
    fn = elt(env, 1); /* general!-modular!-expt */
    v0168 = (*qfn2(fn))(qenv(fn), v0255, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v0168);
    }
/* error exit handlers */
v0178:
    popv(1);
    return nil;
}



/* Code for minus!-mod!-p */

static Lisp_Object CC_minusKmodKp(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0195, v0190;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minus-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push(v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0175);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0175;
/* end of prologue */
    stack[-2] = nil;
    goto v0275;

v0275:
    v0195 = stack[-1];
    if (v0195 == nil) goto v0139;
    v0195 = stack[-1];
    if (!consp(v0195)) goto v0242;
    v0195 = stack[-1];
    v0195 = qcar(v0195);
    v0195 = (consp(v0195) ? nil : lisp_true);
    goto v0179;

v0179:
    if (v0195 == nil) goto v0181;
    v0190 = stack[-2];
    v0195 = stack[-1];
    {   int32_t w = int_of_fixnum(v0195);
        if (w != 0) w = current_modulus - w;
        v0195 = fixnum_of_int(w);
    }
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0190, v0195);
    }

v0181:
    v0195 = stack[-1];
    v0195 = qcar(v0195);
    stack[0] = qcar(v0195);
    v0195 = stack[-1];
    v0195 = qcar(v0195);
    v0195 = qcdr(v0195);
    v0190 = CC_minusKmodKp(env, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    v0195 = stack[-2];
    v0195 = acons(stack[0], v0190, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    stack[-2] = v0195;
    v0195 = stack[-1];
    v0195 = qcdr(v0195);
    stack[-1] = v0195;
    goto v0275;

v0242:
    v0195 = qvalue(elt(env, 1)); /* t */
    goto v0179;

v0139:
    v0195 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0195);
    }
/* error exit handlers */
v0202:
    popv(4);
    return nil;
}



/* Code for sfto_gcdf */

static Lisp_Object CC_sfto_gcdf(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0190, v0201;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_gcdf");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
    stack[-1] = v0175;
/* end of prologue */
    v0190 = qvalue(elt(env, 1)); /* !*rldavgcd */
    if (v0190 == nil) goto v0176;
    v0201 = stack[-1];
    v0190 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* sfto_davp */
    v0190 = (*qfn2(fn))(qenv(fn), v0201, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-3];
    if (!(v0190 == nil)) goto v0179;
    v0201 = stack[0];
    v0190 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* sfto_davp */
    v0190 = (*qfn2(fn))(qenv(fn), v0201, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-3];
    if (!(v0190 == nil)) goto v0179;
    v0201 = stack[-1];
    v0190 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* ezgcdf */
        return (*qfn2(fn))(qenv(fn), v0201, v0190);
    }

v0179:
    v0190 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = qvalue(elt(env, 3)); /* !*ezgcd */
    qvalue(elt(env, 3)) = v0190; /* !*ezgcd */
    v0201 = stack[-1];
    v0190 = stack[0];
    fn = elt(env, 6); /* gcdf */
    v0190 = (*qfn2(fn))(qenv(fn), v0201, v0190);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; /* !*ezgcd */
    { popv(4); return onevalue(v0190); }

v0176:
    v0201 = stack[-1];
    v0190 = stack[0];
    {
        popv(4);
        fn = elt(env, 6); /* gcdf */
        return (*qfn2(fn))(qenv(fn), v0201, v0190);
    }
/* error exit handlers */
v0209:
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; /* !*ezgcd */
    popv(4);
    return nil;
v0203:
    popv(4);
    return nil;
}



/* Code for prepsq!*2 */

static Lisp_Object CC_prepsqH2(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0255, v0178, v0179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsq*2");
#endif
    if (stack >= stacklimit)
    {
        push(v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0175);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0255 = v0175;
/* end of prologue */
    v0179 = v0255;
    v0178 = (Lisp_Object)17; /* 1 */
    v0255 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepsq!*1 */
    v0255 = (*qfnn(fn))(qenv(fn), 3, v0179, v0178, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* replus */
        return (*qfn1(fn))(qenv(fn), v0255);
    }
/* error exit handlers */
v0242:
    popv(1);
    return nil;
}



/* Code for raddf */

static Lisp_Object CC_raddf(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0404, v0360;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for raddf");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0004;
    stack[-2] = v0175;
/* end of prologue */
    stack[-3] = nil;
    goto v0133;

v0133:
    v0404 = stack[-2];
    if (v0404 == nil) goto v0168;
    v0404 = stack[-1];
    if (v0404 == nil) goto v0192;
    v0404 = stack[-2];
    if (!consp(v0404)) goto v0200;
    v0404 = stack[-2];
    v0404 = qcar(v0404);
    v0404 = (consp(v0404) ? nil : lisp_true);
    goto v0199;

v0199:
    if (v0404 == nil) goto v0136;
    stack[0] = stack[-3];
    v0360 = stack[-2];
    v0404 = stack[-1];
    fn = elt(env, 2); /* addd */
    v0404 = (*qfn2(fn))(qenv(fn), v0360, v0404);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    {
        Lisp_Object v0221 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0221, v0404);
    }

v0136:
    v0404 = stack[-1];
    if (!consp(v0404)) goto v0210;
    v0404 = stack[-1];
    v0404 = qcar(v0404);
    v0404 = (consp(v0404) ? nil : lisp_true);
    goto v0209;

v0209:
    if (v0404 == nil) goto v0405;
    stack[0] = stack[-3];
    v0360 = stack[-1];
    v0404 = stack[-2];
    fn = elt(env, 2); /* addd */
    v0404 = (*qfn2(fn))(qenv(fn), v0360, v0404);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    {
        Lisp_Object v0152 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0152, v0404);
    }

v0405:
    v0404 = stack[-2];
    v0404 = qcar(v0404);
    v0360 = qcar(v0404);
    v0404 = stack[-1];
    v0404 = qcar(v0404);
    v0404 = qcar(v0404);
    if (equal(v0360, v0404)) goto v0236;
    v0404 = stack[-2];
    v0404 = qcar(v0404);
    v0360 = qcar(v0404);
    v0404 = stack[-1];
    v0404 = qcar(v0404);
    v0404 = qcar(v0404);
    fn = elt(env, 4); /* ordpp */
    v0404 = (*qfn2(fn))(qenv(fn), v0360, v0404);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    if (v0404 == nil) goto v0230;
    v0404 = stack[-2];
    v0360 = qcar(v0404);
    v0404 = stack[-3];
    v0404 = cons(v0360, v0404);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    stack[-3] = v0404;
    v0404 = stack[-2];
    v0404 = qcdr(v0404);
    stack[-2] = v0404;
    goto v0133;

v0230:
    v0404 = stack[-1];
    v0360 = qcar(v0404);
    v0404 = stack[-3];
    v0404 = cons(v0360, v0404);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    stack[-3] = v0404;
    v0404 = stack[-1];
    v0404 = qcdr(v0404);
    stack[-1] = v0404;
    goto v0133;

v0236:
    v0404 = stack[-2];
    v0404 = qcar(v0404);
    stack[0] = qcar(v0404);
    v0404 = stack[-2];
    v0404 = qcar(v0404);
    v0360 = qcdr(v0404);
    v0404 = stack[-1];
    v0404 = qcar(v0404);
    v0404 = qcdr(v0404);
    v0360 = CC_raddf(env, v0360, v0404);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    v0404 = stack[-3];
    v0404 = acons(stack[0], v0360, v0404);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-4];
    stack[-3] = v0404;
    v0404 = stack[-2];
    v0404 = qcdr(v0404);
    stack[-2] = v0404;
    v0404 = stack[-1];
    v0404 = qcdr(v0404);
    stack[-1] = v0404;
    goto v0133;

v0210:
    v0404 = qvalue(elt(env, 1)); /* t */
    goto v0209;

v0200:
    v0404 = qvalue(elt(env, 1)); /* t */
    goto v0199;

v0192:
    v0360 = stack[-3];
    v0404 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0360, v0404);
    }

v0168:
    v0360 = stack[-3];
    v0404 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0360, v0404);
    }
/* error exit handlers */
v0153:
    popv(5);
    return nil;
}



/* Code for stable!-sortip */

static Lisp_Object CC_stableKsortip(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0411, v0355, v0100;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for stable-sortip");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0004;
    stack[-3] = v0175;
/* end of prologue */
    v0411 = stack[-3];
    if (v0411 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0411 = stack[-3];
    stack[-4] = v0411;
    v0411 = stack[-3];
    v0411 = qcdr(v0411);
    stack[-1] = v0411;
    v0411 = stack[-1];
    if (v0411 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0411 = stack[-1];
    v0411 = qcdr(v0411);
    stack[-3] = v0411;
    v0411 = stack[-3];
    if (v0411 == nil) goto v0200;
    v0411 = stack[-4];
    stack[-3] = v0411;
    goto v0245;

v0245:
    v0411 = stack[-1];
    if (v0411 == nil) goto v0257;
    v0100 = stack[-2];
    v0411 = stack[-1];
    v0355 = qcar(v0411);
    v0411 = stack[-3];
    v0411 = qcar(v0411);
    v0411 = Lapply2(nil, 3, v0100, v0355, v0411);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-5];
    if (!(v0411 == nil)) goto v0257;
    v0411 = stack[-1];
    stack[-3] = v0411;
    v0411 = stack[-1];
    v0411 = qcdr(v0411);
    stack[-1] = v0411;
    goto v0245;

v0257:
    v0411 = stack[-1];
    if (v0411 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v0411 = stack[-4];
    stack[-1] = v0411;
    v0411 = stack[-1];
    v0411 = qcdr(v0411);
    v0411 = qcdr(v0411);
    stack[-3] = v0411;
    goto v0174;

v0174:
    v0411 = stack[-3];
    if (v0411 == nil) goto v0115;
    v0411 = stack[-3];
    v0411 = qcdr(v0411);
    if (v0411 == nil) goto v0115;
    v0411 = stack[-1];
    v0411 = qcdr(v0411);
    stack[-1] = v0411;
    v0411 = stack[-3];
    v0411 = qcdr(v0411);
    v0411 = qcdr(v0411);
    stack[-3] = v0411;
    goto v0174;

v0115:
    v0411 = stack[-1];
    stack[-3] = v0411;
    v0411 = stack[-1];
    v0411 = qcdr(v0411);
    stack[-1] = v0411;
    v0355 = stack[-3];
    v0411 = qvalue(elt(env, 1)); /* nil */
    v0411 = Lrplacd(nil, v0355, v0411);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-5];
    v0355 = stack[-4];
    v0411 = stack[-2];
    v0411 = CC_stableKsortip(env, v0355, v0411);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-5];
    stack[-4] = v0411;
    v0355 = stack[-1];
    v0411 = stack[-2];
    v0411 = CC_stableKsortip(env, v0355, v0411);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-5];
    stack[-1] = v0411;
    v0411 = qvalue(elt(env, 1)); /* nil */
    v0411 = ncons(v0411);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-5];
    stack[0] = v0411;
    stack[-3] = v0411;
    goto v0412;

v0412:
    v0411 = stack[-4];
    if (v0411 == nil) goto v0413;
    v0411 = stack[-1];
    if (v0411 == nil) goto v0413;
    v0100 = stack[-2];
    v0411 = stack[-1];
    v0355 = qcar(v0411);
    v0411 = stack[-4];
    v0411 = qcar(v0411);
    v0411 = Lapply2(nil, 3, v0100, v0355, v0411);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-5];
    if (v0411 == nil) goto v0224;
    v0355 = stack[0];
    v0411 = stack[-1];
    v0411 = Lrplacd(nil, v0355, v0411);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-5];
    v0411 = stack[-1];
    stack[0] = v0411;
    v0411 = stack[-1];
    v0411 = qcdr(v0411);
    stack[-1] = v0411;
    goto v0412;

v0224:
    v0355 = stack[0];
    v0411 = stack[-4];
    v0411 = Lrplacd(nil, v0355, v0411);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-5];
    v0411 = stack[-4];
    stack[0] = v0411;
    v0411 = stack[-4];
    v0411 = qcdr(v0411);
    stack[-4] = v0411;
    goto v0412;

v0413:
    v0411 = stack[-4];
    if (v0411 == nil) goto v0414;
    v0411 = stack[-4];
    stack[-1] = v0411;
    goto v0414;

v0414:
    v0355 = stack[0];
    v0411 = stack[-1];
    v0411 = Lrplacd(nil, v0355, v0411);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    v0411 = stack[-3];
    v0411 = qcdr(v0411);
    { popv(6); return onevalue(v0411); }

v0200:
    v0100 = stack[-2];
    v0411 = stack[-1];
    v0355 = qcar(v0411);
    v0411 = stack[-4];
    v0411 = qcar(v0411);
    v0411 = Lapply2(nil, 3, v0100, v0355, v0411);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-5];
    if (v0411 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v0411 = stack[-4];
    v0411 = qcar(v0411);
    stack[-3] = v0411;
    v0355 = stack[-4];
    v0411 = stack[-1];
    v0411 = qcar(v0411);
    v0411 = Lrplaca(nil, v0355, v0411);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-5];
    v0355 = stack[-1];
    v0411 = stack[-3];
    v0411 = Lrplaca(nil, v0355, v0411);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v0094:
    popv(6);
    return nil;
}



/* Code for mri_2pasfat */

static Lisp_Object CC_mri_2pasfat(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0178, v0179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_2pasfat");
#endif
    if (stack >= stacklimit)
    {
        push(v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0175);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0175;
/* end of prologue */
    v0178 = stack[0];
    fn = elt(env, 2); /* mri_op */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-2];
    v0178 = stack[0];
    fn = elt(env, 3); /* mri_arg2l */
    v0178 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-2];
    v0179 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0149 = stack[-1];
        popv(3);
        return list3(v0149, v0178, v0179);
    }
/* error exit handlers */
v0219:
    popv(3);
    return nil;
}



/* Code for qqe_qtidp */

static Lisp_Object CC_qqe_qtidp(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0242, v0186;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_qtidp");
#endif
    if (stack >= stacklimit)
    {
        push(v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0175);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0242 = v0175;
/* end of prologue */
    v0186 = v0242;
    v0242 = elt(env, 1); /* idtype */
    v0242 = get(v0186, v0242);
    env = stack[0];
    v0186 = elt(env, 2); /* qt */
    v0242 = (v0242 == v0186 ? lisp_true : nil);
    { popv(1); return onevalue(v0242); }
}



/* Code for difff */

static Lisp_Object CC_difff(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0111, v0110, v0402;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difff");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0004;
    stack[-2] = v0175;
/* end of prologue */
    v0111 = stack[-2];
    if (!consp(v0111)) goto v0176;
    v0111 = stack[-2];
    v0111 = qcar(v0111);
    if (!consp(v0111)) goto v0191;
    v0111 = stack[-2];
    v0111 = qcar(v0111);
    v0110 = qcar(v0111);
    v0111 = (Lisp_Object)17; /* 1 */
    v0111 = cons(v0110, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0416;
    env = stack[-4];
    v0110 = ncons(v0111);
    nil = C_nil;
    if (exception_pending()) goto v0416;
    env = stack[-4];
    v0111 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0110, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0416;
    env = stack[-4];
    v0111 = stack[-2];
    v0111 = qcar(v0111);
    v0110 = qcdr(v0111);
    v0111 = stack[-1];
    v0111 = CC_difff(env, v0110, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0416;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    stack[-3] = (*qfn2(fn))(qenv(fn), stack[0], v0111);
    nil = C_nil;
    if (exception_pending()) goto v0416;
    env = stack[-4];
    v0111 = stack[-2];
    v0111 = qcar(v0111);
    v0110 = qcar(v0111);
    v0111 = stack[-1];
    fn = elt(env, 4); /* diffp */
    stack[0] = (*qfn2(fn))(qenv(fn), v0110, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0416;
    env = stack[-4];
    v0111 = stack[-2];
    v0111 = qcar(v0111);
    v0110 = qcdr(v0111);
    v0111 = (Lisp_Object)17; /* 1 */
    v0111 = cons(v0110, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0416;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    v0111 = (*qfn2(fn))(qenv(fn), stack[0], v0111);
    nil = C_nil;
    if (exception_pending()) goto v0416;
    env = stack[-4];
    fn = elt(env, 5); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v0111);
    nil = C_nil;
    if (exception_pending()) goto v0416;
    env = stack[-4];
    v0111 = stack[-2];
    v0110 = qcdr(v0111);
    v0111 = stack[-1];
    v0111 = CC_difff(env, v0110, v0111);
    nil = C_nil;
    if (exception_pending()) goto v0416;
    env = stack[-4];
    {
        Lisp_Object v0268 = stack[0];
        popv(5);
        fn = elt(env, 5); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0268, v0111);
    }

v0191:
    v0111 = stack[-2];
    v0110 = qcar(v0111);
    v0111 = elt(env, 2); /* domain!-diff!-fn */
    v0111 = get(v0110, v0111);
    env = stack[-4];
    v0110 = v0111;
    v0111 = v0110;
    if (v0111 == nil) goto v0260;
    v0402 = v0110;
    v0110 = stack[-2];
    v0111 = stack[-1];
        popv(5);
        return Lapply2(nil, 3, v0402, v0110, v0111);

v0260:
    v0110 = qvalue(elt(env, 1)); /* nil */
    v0111 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0110, v0111);

v0176:
    v0110 = qvalue(elt(env, 1)); /* nil */
    v0111 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0110, v0111);
/* error exit handlers */
v0416:
    popv(5);
    return nil;
}



/* Code for symtabget */

static Lisp_Object CC_symtabget(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0195, v0190, v0201, v0273;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symtabget");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0273 = v0004;
    v0201 = v0175;
/* end of prologue */
    v0195 = v0273;
    if (v0195 == nil) goto v0183;
    v0195 = v0201;
    if (!(v0195 == nil)) goto v0176;
    v0195 = qvalue(elt(env, 1)); /* !*symboltable!* */
    v0195 = qcar(v0195);
    goto v0176;

v0176:
    v0201 = v0195;
    goto v0183;

v0183:
    v0195 = v0201;
    if (v0195 == nil) goto v0179;
    v0190 = v0273;
    v0195 = elt(env, 2); /* (!*type!* !*params!* !*decs!*) */
    v0195 = Lmemq(nil, v0190, v0195);
    if (v0195 == nil) goto v0126;
    v0195 = v0201;
    v0190 = v0273;
    return get(v0195, v0190);

v0126:
    v0190 = v0273;
    v0195 = elt(env, 3); /* !*decs!* */
    v0195 = get(v0201, v0195);
    v0195 = Lassoc(nil, v0190, v0195);
    return onevalue(v0195);

v0179:
    v0195 = qvalue(elt(env, 1)); /* !*symboltable!* */
    return onevalue(v0195);
}



/* Code for termordp */

static Lisp_Object CC_termordp(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termordp");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
    v0168 = v0175;
/* end of prologue */
    fn = elt(env, 1); /* wedgefax */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-2];
    v0168 = stack[0];
    fn = elt(env, 1); /* wedgefax */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0179;
    env = stack[-2];
    {
        Lisp_Object v0242 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* monordp */
        return (*qfn2(fn))(qenv(fn), v0242, v0168);
    }
/* error exit handlers */
v0179:
    popv(3);
    return nil;
}



/* Code for putpline */

static Lisp_Object CC_putpline(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115, v0174, v0173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for putpline");
#endif
    if (stack >= stacklimit)
    {
        push(v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0175);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0175;
/* end of prologue */
    v0174 = qvalue(elt(env, 1)); /* posn!* */
    v0115 = stack[0];
    v0115 = qcar(v0115);
    v0115 = qcdr(v0115);
    stack[-1] = (Lisp_Object)(int32_t)((int32_t)v0174 + (int32_t)v0115 - TAG_FIXNUM);
    v0115 = qvalue(elt(env, 2)); /* nil */
    v0174 = Llinelength(nil, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-2];
    v0115 = qvalue(elt(env, 3)); /* spare!* */
    v0115 = (Lisp_Object)(int32_t)((int32_t)v0174 - (int32_t)v0115 + TAG_FIXNUM);
    v0115 = (Lisp_Object)greaterp2(stack[-1], v0115);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    v0115 = v0115 ? lisp_true : nil;
    env = stack[-2];
    if (v0115 == nil) goto v0260;
    v0115 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 10); /* terpri!* */
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-2];
    goto v0260;

v0260:
    v0174 = qvalue(elt(env, 1)); /* posn!* */
    v0115 = qvalue(elt(env, 5)); /* orig!* */
    v0173 = (Lisp_Object)(int32_t)((int32_t)v0174 - (int32_t)v0115 + TAG_FIXNUM);
    v0174 = qvalue(elt(env, 6)); /* ycoord!* */
    v0115 = stack[0];
    v0115 = qcar(v0115);
    v0115 = qcar(v0115);
    fn = elt(env, 11); /* update!-pline */
    v0174 = (*qfnn(fn))(qenv(fn), 3, v0173, v0174, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-2];
    v0115 = qvalue(elt(env, 7)); /* pline!* */
    v0115 = Lappend(nil, v0174, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-2];
    qvalue(elt(env, 7)) = v0115; /* pline!* */
    v0174 = qvalue(elt(env, 1)); /* posn!* */
    v0115 = stack[0];
    v0115 = qcar(v0115);
    v0115 = qcdr(v0115);
    v0115 = (Lisp_Object)(int32_t)((int32_t)v0174 + (int32_t)v0115 - TAG_FIXNUM);
    qvalue(elt(env, 1)) = v0115; /* posn!* */
    v0173 = qvalue(elt(env, 8)); /* ymin!* */
    v0115 = stack[0];
    v0115 = qcdr(v0115);
    v0174 = qcar(v0115);
    v0115 = qvalue(elt(env, 6)); /* ycoord!* */
    v0115 = (Lisp_Object)(int32_t)((int32_t)v0174 + (int32_t)v0115 - TAG_FIXNUM);
    fn = elt(env, 12); /* min */
    v0115 = (*qfn2(fn))(qenv(fn), v0173, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-2];
    qvalue(elt(env, 8)) = v0115; /* ymin!* */
    v0173 = qvalue(elt(env, 9)); /* ymax!* */
    v0115 = stack[0];
    v0115 = qcdr(v0115);
    v0174 = qcdr(v0115);
    v0115 = qvalue(elt(env, 6)); /* ycoord!* */
    v0115 = (Lisp_Object)(int32_t)((int32_t)v0174 + (int32_t)v0115 - TAG_FIXNUM);
    fn = elt(env, 13); /* max */
    v0115 = (*qfn2(fn))(qenv(fn), v0173, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-2];
    qvalue(elt(env, 9)) = v0115; /* ymax!* */
    v0115 = nil;
    { popv(3); return onevalue(v0115); }
/* error exit handlers */
v0207:
    popv(3);
    return nil;
}



/* Code for vecopp */

static Lisp_Object CC_vecopp(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0210, v0239, v0123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vecopp");
#endif
    if (stack >= stacklimit)
    {
        push(v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0175);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0239 = v0175;
/* end of prologue */
    v0210 = v0239;
    if (symbolp(v0210)) goto v0219;
    v0210 = qvalue(elt(env, 1)); /* nil */
    goto v0133;

v0133:
    if (!(v0210 == nil)) { popv(1); return onevalue(v0210); }
    v0210 = v0239;
    if (!consp(v0210)) goto v0202;
    v0210 = v0239;
    v0123 = qcar(v0210);
    v0210 = elt(env, 2); /* phystype */
    v0123 = get(v0123, v0210);
    env = stack[0];
    v0210 = elt(env, 3); /* vector */
    if (v0123 == v0210) goto v0200;
    v0210 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0210); }

v0200:
    v0210 = v0239;
    v0210 = qcdr(v0210);
    v0210 = qcar(v0210);
    fn = elt(env, 4); /* isanindex */
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    v0210 = (v0210 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v0210); }

v0202:
    v0210 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0210); }

v0219:
    v0123 = v0239;
    v0210 = elt(env, 2); /* phystype */
    v0123 = get(v0123, v0210);
    env = stack[0];
    v0210 = elt(env, 3); /* vector */
    v0210 = (v0123 == v0210 ? lisp_true : nil);
    goto v0133;
/* error exit handlers */
v0124:
    popv(1);
    return nil;
}



/* Code for symbid */

static Lisp_Object CC_symbid(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0274, v0150, v0389, v0409;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbid");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0389 = v0004;
    stack[0] = v0175;
/* end of prologue */
    v0274 = qvalue(elt(env, 1)); /* fname!* */
    if (v0274 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0150 = qvalue(elt(env, 2)); /* ftype!* */
    v0274 = elt(env, 3); /* (macro smacro) */
    v0274 = Lmemq(nil, v0150, v0274);
    if (v0274 == nil) goto v0264;
    v0274 = qvalue(elt(env, 9)); /* nil */
    goto v0155;

v0155:
    if (v0274 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0274 = qvalue(elt(env, 10)); /* !*msg */
    if (v0274 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = elt(env, 11); /* "***" */
    v0409 = elt(env, 12); /* "nonlocal use of undeclared variable" */
    v0389 = stack[0];
    v0150 = elt(env, 13); /* "in procedure" */
    v0274 = qvalue(elt(env, 1)); /* fname!* */
    v0274 = list4(v0409, v0389, v0150, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0279;
    env = stack[-2];
    fn = elt(env, 14); /* lpriw */
    v0274 = (*qfn2(fn))(qenv(fn), stack[-1], v0274);
    nil = C_nil;
    if (exception_pending()) goto v0279;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v0264:
    v0274 = stack[0];
    v0150 = v0389;
    v0274 = Latsoc(nil, v0274, v0150);
    if (!(v0274 == nil)) goto v0259;
    v0274 = stack[0];
    v0274 = Lsymbol_specialp(nil, v0274);
    nil = C_nil;
    if (exception_pending()) goto v0279;
    env = stack[-2];
    if (!(v0274 == nil)) goto v0259;
    v0274 = stack[0];
    v0274 = Lsymbol_globalp(nil, v0274);
    env = stack[-2];
    if (!(v0274 == nil)) goto v0259;
    v0274 = stack[0];
    if (v0274 == nil) goto v0211;
    v0150 = stack[0];
    v0274 = qvalue(elt(env, 4)); /* t */
    if (v0150 == v0274) goto v0197;
    v0150 = stack[0];
    v0274 = elt(env, 5); /* share */
    v0274 = Lflagp(nil, v0150, v0274);
    env = stack[-2];
    if (v0274 == nil) goto v0142;
    v0274 = qvalue(elt(env, 4)); /* t */
    goto v0259;

v0259:
    v0274 = (v0274 == nil ? lisp_true : nil);
    goto v0155;

v0142:
    v0274 = qvalue(elt(env, 6)); /* !*comp */
    if (!(v0274 == nil)) goto v0259;
    v0274 = qvalue(elt(env, 7)); /* !*cref */
    if (!(v0274 == nil)) goto v0259;
    v0150 = stack[0];
    v0274 = elt(env, 8); /* constant!? */
    v0274 = get(v0150, v0274);
    env = stack[-2];
    goto v0259;

v0197:
    v0274 = qvalue(elt(env, 4)); /* t */
    goto v0259;

v0211:
    v0274 = qvalue(elt(env, 4)); /* t */
    goto v0259;
/* error exit handlers */
v0279:
    popv(3);
    return nil;
}



/* Code for errorset2 */

static Lisp_Object CC_errorset2(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0242, v0186, v0219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for errorset2");
#endif
    if (stack >= stacklimit)
    {
        push(v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0175);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0186 = v0175;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*protfg */
    qvalue(elt(env, 1)) = nil; /* !*protfg */
    v0242 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v0242; /* !*protfg */
    v0219 = v0186;
    v0186 = qvalue(elt(env, 3)); /* nil */
    v0242 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 4); /* errorset */
    v0242 = (*qfnn(fn))(qenv(fn), 3, v0219, v0186, v0242);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*protfg */
    { popv(2); return onevalue(v0242); }
/* error exit handlers */
v0191:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*protfg */
    popv(2);
    return nil;
}



/* Code for mv!-pow!-mv!-term!-!+ */

static Lisp_Object CC_mvKpowKmvKtermKL(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0149, v0191;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-mv-term-+");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
    v0149 = v0175;
/* end of prologue */
    v0191 = v0149;
    v0149 = stack[0];
    v0149 = qcar(v0149);
    fn = elt(env, 1); /* mv!-pow!-!+ */
    v0191 = (*qfn2(fn))(qenv(fn), v0191, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0259;
    v0149 = stack[0];
    v0149 = qcdr(v0149);
    popv(1);
    return cons(v0191, v0149);
/* error exit handlers */
v0259:
    popv(1);
    return nil;
}



/* Code for insert_pv1 */

static Lisp_Object MS_CDECL CC_insert_pv1(Lisp_Object env, int nargs,
                         Lisp_Object v0175, Lisp_Object v0004,
                         Lisp_Object v0007, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0272, v0114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "insert_pv1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insert_pv1");
#endif
    if (stack >= stacklimit)
    {
        push3(v0007,v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0175,v0004,v0007);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0007;
    stack[-1] = v0004;
    stack[-2] = v0175;
/* end of prologue */

v0148:
    v0272 = stack[-1];
    if (v0272 == nil) goto v0167;
    v0272 = stack[-2];
    if (v0272 == nil) goto v0125;
    v0272 = stack[-1];
    v0272 = qcar(v0272);
    v0272 = qcar(v0272);
    v0114 = qcdr(v0272);
    v0272 = stack[-2];
    v0272 = qcar(v0272);
    v0272 = qcdr(v0272);
    v0272 = (Lisp_Object)greaterp2(v0114, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    v0272 = v0272 ? lisp_true : nil;
    env = stack[-4];
    if (v0272 == nil) goto v0277;
    v0272 = stack[-1];
    v0272 = qcdr(v0272);
    stack[-3] = v0272;
    v0272 = stack[-1];
    v0114 = qcar(v0272);
    v0272 = stack[-2];
    fn = elt(env, 2); /* reduce_pv */
    v0272 = (*qfn2(fn))(qenv(fn), v0114, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-4];
    fn = elt(env, 3); /* pv_renorm */
    v0114 = (*qfn1(fn))(qenv(fn), v0272);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-4];
    v0272 = stack[0];
    v0272 = cons(v0114, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-4];
    stack[0] = v0272;
    v0272 = stack[-3];
    stack[-1] = v0272;
    goto v0148;

v0277:
    v0272 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v0272;
    v0114 = stack[-2];
    v0272 = stack[0];
    v0272 = cons(v0114, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-4];
    stack[0] = v0272;
    v0272 = stack[-3];
    stack[-2] = v0272;
    goto v0148;

v0125:
    v0272 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0272;
    v0272 = stack[-1];
    v0272 = qcdr(v0272);
    stack[-3] = v0272;
    v0272 = stack[-1];
    v0114 = qcar(v0272);
    v0272 = stack[0];
    v0272 = cons(v0114, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-4];
    stack[0] = v0272;
    v0272 = stack[-3];
    stack[-1] = v0272;
    goto v0148;

v0167:
    v0272 = stack[-2];
    if (v0272 == nil) goto v0178;
    v0114 = stack[-2];
    v0272 = stack[0];
    v0272 = cons(v0114, v0272);
    nil = C_nil;
    if (exception_pending()) goto v0208;
        popv(5);
        return Lnreverse(nil, v0272);

v0178:
    v0272 = stack[0];
        popv(5);
        return Lnreverse(nil, v0272);
/* error exit handlers */
v0208:
    popv(5);
    return nil;
}



/* Code for polynomclone */

static Lisp_Object CC_polynomclone(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0125, v0136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomclone");
#endif
    if (stack >= stacklimit)
    {
        push(v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0175);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0125 = v0175;
/* end of prologue */
    stack[-1] = nil;
    stack[0] = v0125;
    goto v0176;

v0176:
    v0125 = stack[0];
    if (v0125 == nil) goto v0139;
    v0125 = stack[0];
    v0125 = qcar(v0125);
    fn = elt(env, 2); /* monomclone */
    v0136 = (*qfn1(fn))(qenv(fn), v0125);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-2];
    v0125 = stack[-1];
    v0125 = cons(v0136, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-2];
    stack[-1] = v0125;
    v0125 = stack[0];
    v0125 = qcdr(v0125);
    stack[0] = v0125;
    goto v0176;

v0139:
    v0125 = stack[-1];
        popv(3);
        return Lreverse(nil, v0125);
/* error exit handlers */
v0200:
    popv(3);
    return nil;
}



/* Code for setdiff */

static Lisp_Object CC_setdiff(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0185, v0262;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setdiff");
#endif
    if (stack >= stacklimit)
    {
        push2(v0004,v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0175,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
    v0185 = v0175;
/* end of prologue */

v0275:
    v0262 = stack[0];
    if (v0262 == nil) { popv(2); return onevalue(v0185); }
    v0262 = v0185;
    if (v0262 == nil) goto v0177;
    v0262 = stack[0];
    v0262 = qcar(v0262);
    v0185 = Ldelete(nil, v0262, v0185);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-1];
    v0262 = stack[0];
    v0262 = qcdr(v0262);
    stack[0] = v0262;
    goto v0275;

v0177:
    v0185 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0185); }
/* error exit handlers */
v0136:
    popv(2);
    return nil;
}



/* Code for pasf_susipost */

static Lisp_Object CC_pasf_susipost(Lisp_Object env,
                         Lisp_Object v0175, Lisp_Object v0004)
{
    Lisp_Object v0183, v0275;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_susipost");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0183 = v0004;
    v0275 = v0175;
/* end of prologue */
    return onevalue(v0275);
}



/* Code for ibalp_mk2 */

static Lisp_Object MS_CDECL CC_ibalp_mk2(Lisp_Object env, int nargs,
                         Lisp_Object v0175, Lisp_Object v0004,
                         Lisp_Object v0007, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0178, v0179, v0242;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ibalp_mk2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_mk2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0178 = v0007;
    v0179 = v0004;
    v0242 = v0175;
/* end of prologue */
    return list3(v0242, v0179, v0178);
}



/* Code for omobjs */

static Lisp_Object MS_CDECL CC_omobjs(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0240, v0243;
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
    v0243 = qvalue(elt(env, 1)); /* char */
    v0240 = elt(env, 2); /* (!/ o m a) */
    if (equal(v0243, v0240)) goto v0133;
    fn = elt(env, 4); /* omobj */
    v0240 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-1];
    stack[0] = v0240;
    fn = elt(env, 5); /* lex */
    v0240 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    env = stack[-1];
    v0240 = CC_omobjs(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0212;
    v0243 = stack[0];
    if (v0243 == nil) goto v0264;
    v0243 = stack[0];
    popv(2);
    return cons(v0243, v0240);

v0264:
    v0243 = stack[0];
        popv(2);
        return Lappend(nil, v0243, v0240);

v0133:
    v0240 = nil;
    { popv(2); return onevalue(v0240); }
/* error exit handlers */
v0212:
    popv(2);
    return nil;
}



/* Code for simp!* */

static Lisp_Object CC_simpH(Lisp_Object env,
                         Lisp_Object v0175)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0231, v0232;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp*");
#endif
    if (stack >= stacklimit)
    {
        push(v0175);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0175);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0175;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* !*asymp!* */
    qvalue(elt(env, 1)) = nil; /* !*asymp!* */
    v0232 = stack[-2];
    v0231 = elt(env, 2); /* !*sq */
    if (!consp(v0232)) goto v0200;
    v0232 = qcar(v0232);
    if (!(v0232 == v0231)) goto v0200;
    v0231 = stack[-2];
    v0231 = qcdr(v0231);
    v0231 = qcdr(v0231);
    v0231 = qcar(v0231);
    if (v0231 == nil) goto v0192;
    v0231 = qvalue(elt(env, 4)); /* !*resimp */
    v0231 = (v0231 == nil ? lisp_true : nil);
    goto v0155;

v0155:
    if (v0231 == nil) goto v0244;
    v0231 = stack[-2];
    v0231 = qcdr(v0231);
    v0231 = qcar(v0231);
    goto v0275;

v0275:
    qvalue(elt(env, 1)) = stack[-3]; /* !*asymp!* */
    { popv(5); return onevalue(v0231); }

v0244:
    v0232 = qvalue(elt(env, 5)); /* mul!* */
    v0231 = qvalue(elt(env, 6)); /* !*sub2 */
    v0231 = cons(v0232, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    stack[-1] = v0231;
    v0231 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 5)) = v0231; /* mul!* */
    v0231 = stack[-2];
    fn = elt(env, 14); /* simp */
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    stack[-2] = v0231;
    v0231 = qvalue(elt(env, 7)); /* !*nospurp */
    if (v0231 == nil) goto v0197;
    v0232 = qvalue(elt(env, 5)); /* mul!* */
    v0231 = elt(env, 8); /* (isimpq) */
    fn = elt(env, 15); /* union */
    v0231 = (*qfn2(fn))(qenv(fn), v0232, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    qvalue(elt(env, 5)) = v0231; /* mul!* */
    goto v0197;

v0197:
    v0231 = qvalue(elt(env, 5)); /* mul!* */
    stack[0] = v0231;
    goto v0216;

v0216:
    v0231 = stack[0];
    if (v0231 == nil) goto v0256;
    v0231 = stack[0];
    v0231 = qcar(v0231);
    v0232 = v0231;
    v0231 = stack[-2];
    v0231 = Lapply1(nil, v0232, v0231);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    stack[-2] = v0231;
    v0231 = stack[0];
    v0231 = qcdr(v0231);
    stack[0] = v0231;
    goto v0216;

v0256:
    v0231 = stack[-1];
    v0231 = qcar(v0231);
    qvalue(elt(env, 5)) = v0231; /* mul!* */
    v0231 = stack[-2];
    fn = elt(env, 16); /* subs2 */
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    stack[-2] = v0231;
    v0231 = qvalue(elt(env, 9)); /* !*combinelogs */
    if (v0231 == nil) goto v0173;
    v0231 = stack[-2];
    fn = elt(env, 17); /* clogsq!* */
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    stack[-2] = v0231;
    goto v0173;

v0173:
    v0232 = qvalue(elt(env, 10)); /* dmode!* */
    v0231 = elt(env, 11); /* !:gi!: */
    if (v0232 == v0231) goto v0115;
    v0231 = qvalue(elt(env, 3)); /* nil */
    goto v0117;

v0117:
    if (v0231 == nil) goto v0271;
    v0231 = stack[-2];
    fn = elt(env, 18); /* girationalize!: */
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    stack[-2] = v0231;
    goto v0236;

v0236:
    v0231 = stack[-1];
    v0231 = qcdr(v0231);
    qvalue(elt(env, 6)) = v0231; /* !*sub2 */
    v0231 = qvalue(elt(env, 1)); /* !*asymp!* */
    if (v0231 == nil) goto v0267;
    v0231 = qvalue(elt(env, 13)); /* !*rationalize */
    if (v0231 == nil) goto v0267;
    v0231 = stack[-2];
    fn = elt(env, 19); /* gcdchk */
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    stack[-2] = v0231;
    goto v0267;

v0267:
    v0231 = stack[-2];
    goto v0275;

v0271:
    v0231 = qvalue(elt(env, 13)); /* !*rationalize */
    if (v0231 == nil) goto v0112;
    v0231 = stack[-2];
    fn = elt(env, 20); /* rationalizesq */
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    stack[-2] = v0231;
    goto v0236;

v0112:
    v0231 = stack[-2];
    fn = elt(env, 21); /* rationalizei */
    v0231 = (*qfn1(fn))(qenv(fn), v0231);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    stack[-2] = v0231;
    goto v0236;

v0115:
    v0231 = qvalue(elt(env, 12)); /* !*norationalgi */
    v0231 = (v0231 == nil ? lisp_true : nil);
    goto v0117;

v0192:
    v0231 = qvalue(elt(env, 3)); /* nil */
    goto v0155;

v0200:
    v0231 = qvalue(elt(env, 3)); /* nil */
    goto v0155;
/* error exit handlers */
v0388:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* !*asymp!* */
    popv(5);
    return nil;
}



setup_type const u06_setup[] =
{
    {"token1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_token1},
    {"dp_diff",                 too_few_2,      CC_dp_diff,    wrong_no_2},
    {"dquot",                   too_few_2,      CC_dquot,      wrong_no_2},
    {"pv_sort1",                too_few_2,      CC_pv_sort1,   wrong_no_2},
    {"general-modular-reciprocal",CC_generalKmodularKreciprocal,too_many_1,wrong_no_1},
    {"anform1",                 CC_anform1,     too_many_1,    wrong_no_1},
    {"lto_catsoc",              too_few_2,      CC_lto_catsoc, wrong_no_2},
    {"gcdf1",                   too_few_2,      CC_gcdf1,      wrong_no_2},
    {"resimp1",                 CC_resimp1,     too_many_1,    wrong_no_1},
    {"rl_susibin",              too_few_2,      CC_rl_susibin, wrong_no_2},
    {"ibalp_varlat",            CC_ibalp_varlat,too_many_1,    wrong_no_1},
    {"powers2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_powers2},
    {"rl_sacat",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_sacat},
    {"retattributes",           too_few_2,      CC_retattributes,wrong_no_2},
    {"mintype",                 CC_mintype,     too_many_1,    wrong_no_1},
    {"ident",                   CC_ident,       too_many_1,    wrong_no_1},
    {"bcsum",                   too_few_2,      CC_bcsum,      wrong_no_2},
    {"evtdeg",                  CC_evtdeg,      too_many_1,    wrong_no_1},
    {"worderp",                 too_few_2,      CC_worderp,    wrong_no_2},
    {"algid",                   too_few_2,      CC_algid,      wrong_no_2},
    {"layout-formula",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_layoutKformula},
    {"*collectphysops",         CC_Hcollectphysops,too_many_1, wrong_no_1},
    {"contrsp2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_contrsp2},
    {"form1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_form1},
    {"simpdiff",                CC_simpdiff,    too_many_1,    wrong_no_1},
    {"mv-pow-minusp",           CC_mvKpowKminusp,too_many_1,   wrong_no_1},
    {"dp_term",                 too_few_2,      CC_dp_term,    wrong_no_2},
    {"pcmult",                  too_few_2,      CC_pcmult,     wrong_no_2},
    {"pv_applp",                too_few_2,      CC_pv_applp,   wrong_no_2},
    {"*id2num",                 CC_Hid2num,     too_many_1,    wrong_no_1},
    {"aronep:",                 CC_aronepT,     too_many_1,    wrong_no_1},
    {"exptmod:",                too_few_2,      CC_exptmodT,   wrong_no_2},
    {"minus-mod-p",             CC_minusKmodKp, too_many_1,    wrong_no_1},
    {"sfto_gcdf",               too_few_2,      CC_sfto_gcdf,  wrong_no_2},
    {"prepsq*2",                CC_prepsqH2,    too_many_1,    wrong_no_1},
    {"raddf",                   too_few_2,      CC_raddf,      wrong_no_2},
    {"stable-sortip",           too_few_2,      CC_stableKsortip,wrong_no_2},
    {"mri_2pasfat",             CC_mri_2pasfat, too_many_1,    wrong_no_1},
    {"qqe_qtidp",               CC_qqe_qtidp,   too_many_1,    wrong_no_1},
    {"difff",                   too_few_2,      CC_difff,      wrong_no_2},
    {"symtabget",               too_few_2,      CC_symtabget,  wrong_no_2},
    {"termordp",                too_few_2,      CC_termordp,   wrong_no_2},
    {"putpline",                CC_putpline,    too_many_1,    wrong_no_1},
    {"vecopp",                  CC_vecopp,      too_many_1,    wrong_no_1},
    {"symbid",                  too_few_2,      CC_symbid,     wrong_no_2},
    {"errorset2",               CC_errorset2,   too_many_1,    wrong_no_1},
    {"mv-pow-mv-term-+",        too_few_2,      CC_mvKpowKmvKtermKL,wrong_no_2},
    {"insert_pv1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_insert_pv1},
    {"polynomclone",            CC_polynomclone,too_many_1,    wrong_no_1},
    {"setdiff",                 too_few_2,      CC_setdiff,    wrong_no_2},
    {"pasf_susipost",           too_few_2,      CC_pasf_susipost,wrong_no_2},
    {"ibalp_mk2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ibalp_mk2},
    {"omobjs",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobjs},
    {"simp*",                   CC_simpH,       too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u06", (two_args *)"15993 5239221 4002149", 0}
};

/* end of generated code */
