
/* $destdir\u38.c        Machine generated C code */

/* Signature: 00000000 24-Aug-2011 */

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


/* Code for difbf */

static Lisp_Object CC_difbf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v68, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difbf");
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
    stack[-6] = v1;
    stack[-7] = v0;
/* end of prologue */
    v67 = stack[-7];
    v67 = qcdr(v67);
    v68 = qcar(v67);
    stack[-8] = v68;
    v67 = (Lisp_Object)1; /* 0 */
    if (v68 == v67) goto v70;
    v67 = stack[-6];
    v67 = qcdr(v67);
    v68 = qcar(v67);
    stack[-5] = v68;
    v67 = (Lisp_Object)1; /* 0 */
    if (v68 == v67) goto v71;
    v67 = stack[-7];
    v67 = qcdr(v67);
    v68 = qcdr(v67);
    stack[-4] = v68;
    v67 = stack[-6];
    v67 = qcdr(v67);
    v67 = qcdr(v67);
    stack[-3] = v67;
    v68 = difference2(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    stack[-2] = v68;
    v67 = (Lisp_Object)1; /* 0 */
    if (v68 == v67) goto v73;
    stack[-1] = stack[-2];
    v67 = stack[-8];
    v67 = Labsval(nil, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    fn = elt(env, 3); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    v67 = stack[-5];
    v67 = Labsval(nil, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    fn = elt(env, 3); /* msd */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    v67 = difference2(stack[0], v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    v67 = plus2(stack[-1], v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    stack[-1] = v67;
    v67 = qvalue(elt(env, 2)); /* !:bprec!: */
    v67 = add1(v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    stack[0] = v67;
    v68 = stack[-1];
    v67 = stack[0];
    v67 = (Lisp_Object)greaterp2(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    v67 = v67 ? lisp_true : nil;
    env = stack[-9];
    if (v67 == nil) goto v74;
    v67 = stack[-7];
    goto v75;

v75:
    stack[-2] = v67;
    v67 = stack[-2];
    v67 = qcdr(v67);
    v67 = qcar(v67);
    v69 = v67;
    v68 = v69;
    v67 = (Lisp_Object)1; /* 0 */
    if (v68 == v67) goto v76;
    v68 = v69;
    v67 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 4); /* inorm */
    v67 = (*qfn2(fn))(qenv(fn), v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    v69 = v67;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v67 = v69;
    stack[0] = qcar(v67);
    v67 = v69;
    v68 = qcdr(v67);
    v67 = stack[-2];
    v67 = qcdr(v67);
    v67 = qcdr(v67);
    v67 = plus2(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    {
        Lisp_Object v77 = stack[-1];
        Lisp_Object v78 = stack[0];
        popv(10);
        return list2star(v77, v78, v67);
    }

v76:
    v69 = elt(env, 1); /* !:rd!: */
    v68 = (Lisp_Object)1; /* 0 */
    v67 = (Lisp_Object)1; /* 0 */
    popv(10);
    return list2star(v69, v68, v67);

v74:
    v67 = stack[0];
    v67 = negate(v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    v67 = (Lisp_Object)lessp2(stack[-1], v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    v67 = v67 ? lisp_true : nil;
    env = stack[-9];
    if (v67 == nil) goto v79;
    stack[0] = elt(env, 1); /* !:rd!: */
    v67 = stack[-6];
    v67 = qcdr(v67);
    v67 = qcar(v67);
    v68 = negate(v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    v67 = stack[-6];
    v67 = qcdr(v67);
    v67 = qcdr(v67);
    v67 = list2star(stack[0], v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    goto v75;

v79:
    v68 = stack[-2];
    v67 = (Lisp_Object)1; /* 0 */
    v67 = (Lisp_Object)greaterp2(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    v67 = v67 ? lisp_true : nil;
    env = stack[-9];
    if (v67 == nil) goto v80;
    stack[0] = elt(env, 1); /* !:rd!: */
    v68 = stack[-8];
    v67 = stack[-2];
    v68 = Lash1(nil, v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    v67 = stack[-5];
    v68 = difference2(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    v67 = stack[-3];
    v67 = list2star(stack[0], v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    goto v75;

v80:
    stack[0] = elt(env, 1); /* !:rd!: */
    stack[-1] = stack[-8];
    stack[-3] = stack[-5];
    v67 = stack[-2];
    v67 = negate(v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    v67 = Lash1(nil, stack[-3], v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    v68 = difference2(stack[-1], v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    v67 = stack[-4];
    v67 = list2star(stack[0], v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    goto v75;

v73:
    stack[0] = elt(env, 1); /* !:rd!: */
    v68 = stack[-8];
    v67 = stack[-5];
    v68 = difference2(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    v67 = stack[-4];
    v67 = list2star(stack[0], v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    goto v75;

v71:
    v67 = stack[-7];
    goto v75;

v70:
    stack[0] = elt(env, 1); /* !:rd!: */
    v67 = stack[-6];
    v67 = qcdr(v67);
    v67 = qcar(v67);
    v68 = negate(v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    v67 = stack[-6];
    v67 = qcdr(v67);
    v67 = qcdr(v67);
    v67 = list2star(stack[0], v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-9];
    goto v75;
/* error exit handlers */
v72:
    popv(10);
    return nil;
}



/* Code for repartf */

static Lisp_Object CC_repartf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repartf");
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
    v101 = elt(env, 1); /* i */
    v100 = qvalue(elt(env, 2)); /* kord!* */
    v100 = cons(v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    stack[-3] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v100; /* kord!* */
    v100 = stack[0];
    fn = elt(env, 6); /* reorder */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-4];
    stack[-2] = v100;
    v100 = stack[-2];
    if (!consp(v100)) goto v104;
    v100 = stack[-2];
    v100 = qcar(v100);
    v100 = (consp(v100) ? nil : lisp_true);
    goto v105;

v105:
    if (v100 == nil) goto v106;
    v100 = stack[-2];
    if (!consp(v100)) goto v107;
    v100 = stack[-2];
    v101 = qcar(v100);
    v100 = elt(env, 4); /* cmpxfn */
    v100 = get(v101, v100);
    env = stack[-4];
    if (v100 == nil) goto v73;
    v100 = stack[-2];
    stack[-1] = qcar(v100);
    v100 = stack[-2];
    v100 = qcdr(v100);
    stack[0] = qcar(v100);
    v100 = stack[-2];
    v101 = qcar(v100);
    v100 = elt(env, 5); /* i2d */
    v101 = get(v101, v100);
    env = stack[-4];
    v100 = (Lisp_Object)1; /* 0 */
    v100 = Lapply1(nil, v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-4];
    v100 = qcdr(v100);
    v100 = qcar(v100);
    v100 = list2star(stack[-1], stack[0], v100);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-4];
    fn = elt(env, 7); /* int!-equiv!-chk */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-4];
    goto v108;

v108:
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    { popv(5); return onevalue(v100); }

v73:
    v100 = stack[-2];
    goto v108;

v107:
    v100 = stack[-2];
    goto v108;

v106:
    v100 = stack[-2];
    v100 = qcar(v100);
    v100 = qcar(v100);
    v101 = qcar(v100);
    v100 = elt(env, 1); /* i */
    if (v101 == v100) goto v109;
    v100 = stack[-2];
    v100 = qcar(v100);
    v101 = qcar(v100);
    v100 = (Lisp_Object)17; /* 1 */
    v100 = cons(v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-4];
    stack[0] = ncons(v100);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-4];
    v100 = stack[-2];
    v100 = qcar(v100);
    v100 = qcdr(v100);
    v100 = CC_repartf(env, v100);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-4];
    fn = elt(env, 8); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v100);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-4];
    v100 = stack[-2];
    v100 = qcdr(v100);
    v100 = CC_repartf(env, v100);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-4];
    fn = elt(env, 9); /* addf */
    v100 = (*qfn2(fn))(qenv(fn), stack[0], v100);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-4];
    goto v108;

v109:
    v100 = stack[-2];
    v100 = qcdr(v100);
    v100 = CC_repartf(env, v100);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-4];
    goto v108;

v104:
    v100 = qvalue(elt(env, 3)); /* t */
    goto v105;
/* error exit handlers */
v103:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    popv(5);
    return nil;
v102:
    popv(5);
    return nil;
}



/* Code for ev_mtest!? */

static Lisp_Object CC_ev_mtestW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v110, v111, v71, v97;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_mtest?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v111 = v1;
    v71 = v0;
/* end of prologue */
    v63 = qvalue(elt(env, 1)); /* t */
    v97 = v63;
    goto v43;

v43:
    v63 = v71;
    if (v63 == nil) return onevalue(v97);
    v63 = v97;
    if (v63 == nil) return onevalue(v97);
    v63 = v71;
    v110 = qcar(v63);
    v63 = v111;
    v63 = qcar(v63);
    if (((int32_t)(v110)) < ((int32_t)(v63))) goto v112;
    v63 = v71;
    v63 = qcdr(v63);
    v71 = v63;
    v63 = v111;
    v63 = qcdr(v63);
    v111 = v63;
    goto v43;

v112:
    v63 = qvalue(elt(env, 2)); /* nil */
    v97 = v63;
    v71 = v63;
    goto v43;
}



/* Code for pdiffvars */

static Lisp_Object CC_pdiffvars(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v113)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pdiffvars");
#endif
    if (stack >= stacklimit)
    {
        push2(v113,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v113);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v113;
    v63 = v1;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* ind */
    qvalue(elt(env, 1)) = nil; /* ind */
    qvalue(elt(env, 1)) = v63; /* ind */
    v63 = qvalue(elt(env, 1)); /* ind */
    if (v63 == nil) goto v84;
    v110 = stack[-1];
    v63 = qvalue(elt(env, 1)); /* ind */
    v63 = qcar(v63);
    fn = elt(env, 2); /* pnth */
    v63 = (*qfn2(fn))(qenv(fn), v110, v63);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    stack[0] = qcar(v63);
    v63 = qvalue(elt(env, 1)); /* ind */
    v110 = qcdr(v63);
    v63 = stack[-1];
    v63 = CC_pdiffvars(env, v110, v63);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v63 = cons(stack[0], v63);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    goto v31;

v31:
    qvalue(elt(env, 1)) = stack[-2]; /* ind */
    { popv(4); return onevalue(v63); }

v84:
    v63 = nil;
    goto v31;
/* error exit handlers */
v98:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* ind */
    popv(4);
    return nil;
}



/* Code for varsinsf */

static Lisp_Object CC_varsinsf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for varsinsf");
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
    v94 = v1;
    stack[-1] = v0;
/* end of prologue */
    v122 = stack[-1];
    if (!consp(v122)) goto v43;
    v122 = stack[-1];
    v122 = qcar(v122);
    v122 = (consp(v122) ? nil : lisp_true);
    goto v44;

v44:
    if (!(v122 == nil)) { popv(4); return onevalue(v94); }

v123:
    v122 = stack[-1];
    if (!consp(v122)) goto v124;
    v122 = stack[-1];
    v122 = qcar(v122);
    v122 = (consp(v122) ? nil : lisp_true);
    goto v107;

v107:
    if (!(v122 == nil)) { popv(4); return onevalue(v94); }
    v122 = stack[-1];
    v122 = qcar(v122);
    stack[-2] = qcdr(v122);
    stack[0] = v94;
    v94 = stack[-1];
    v94 = qcar(v94);
    v94 = qcar(v94);
    v94 = qcar(v94);
    v94 = ncons(v94);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    fn = elt(env, 3); /* union */
    v94 = (*qfn2(fn))(qenv(fn), stack[0], v94);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v94 = CC_varsinsf(env, stack[-2], v94);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v122 = stack[-1];
    v122 = qcdr(v122);
    stack[-1] = v122;
    goto v123;

v124:
    v122 = qvalue(elt(env, 1)); /* t */
    goto v107;

v43:
    v122 = qvalue(elt(env, 1)); /* t */
    goto v44;
/* error exit handlers */
v125:
    popv(4);
    return nil;
}



/* Code for column_dim */

static Lisp_Object CC_column_dim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64;
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
    v64 = qvalue(elt(env, 1)); /* !*fast_la */
    if (v64 == nil) goto v16;
    v64 = qvalue(elt(env, 2)); /* nil */
    goto v43;

v43:
    if (v64 == nil) goto v20;
    v64 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v64 == nil)) goto v126;
    v64 = elt(env, 4); /* "Error in column_dim: input should be a matrix." 
*/
    fn = elt(env, 5); /* lprie */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-1];
    goto v126;

v126:
    v64 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-1];
    goto v20;

v20:
    v64 = stack[0];
    fn = elt(env, 6); /* size_of_matrix */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v127;
    v64 = qcdr(v64);
    v64 = qcar(v64);
    { popv(2); return onevalue(v64); }

v16:
    v64 = stack[0];
    fn = elt(env, 7); /* matrixp */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-1];
    v64 = (v64 == nil ? lisp_true : nil);
    goto v43;
/* error exit handlers */
v127:
    popv(2);
    return nil;
}



/* Code for vdpsimpcont */

static Lisp_Object CC_vdpsimpcont(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v134, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpsimpcont");
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
    v56 = stack[-1];
    v56 = qcdr(v56);
    v56 = qcdr(v56);
    v56 = qcdr(v56);
    v56 = qcar(v56);
    stack[0] = v56;
    v56 = stack[0];
    if (v56 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v56 = stack[0];
    fn = elt(env, 3); /* dipsimpcont */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    stack[-2] = v56;
    v56 = stack[-2];
    v56 = qcdr(v56);
    fn = elt(env, 4); /* dip2vdp */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    stack[-1] = v56;
    v56 = stack[-2];
    v56 = qcar(v56);
    stack[-2] = v56;
    v56 = stack[-2];
    fn = elt(env, 5); /* evzero!? */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    if (v56 == nil) goto v114;
    v56 = qvalue(elt(env, 1)); /* nil */
    goto v90;

v90:
    if (v56 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v94 = stack[-1];
    v134 = elt(env, 2); /* monfac */
    v56 = stack[-2];
    fn = elt(env, 6); /* vdpputprop */
    v56 = (*qfnn(fn))(qenv(fn), 3, v94, v134, v56);
    nil = C_nil;
    if (exception_pending()) goto v135;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v114:
    v56 = stack[0];
    v56 = qcdr(v56);
    v56 = qcdr(v56);
    if (!(v56 == nil)) goto v90;
    v56 = stack[-2];
    fn = elt(env, 7); /* evtdeg */
    v134 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    v56 = (Lisp_Object)17; /* 1 */
    v56 = (Lisp_Object)greaterp2(v134, v56);
    nil = C_nil;
    if (exception_pending()) goto v135;
    v56 = v56 ? lisp_true : nil;
    env = stack[-3];
    goto v90;
/* error exit handlers */
v135:
    popv(4);
    return nil;
}



/* Code for dim!<!=deg */

static Lisp_Object CC_dimRMdeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dim<=deg");
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
    v115 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dimex!* */
    fn = elt(env, 4); /* deg!*form */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    fn = elt(env, 5); /* negf */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    fn = elt(env, 6); /* addf */
    v115 = (*qfn2(fn))(qenv(fn), stack[0], v115);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    v116 = v115;
    v115 = v116;
    if (v115 == nil) goto v108;
    v115 = v116;
    v115 = integerp(v115);
    if (v115 == nil) goto v65;
    v115 = (Lisp_Object)1; /* 0 */
        popv(2);
        return Lleq(nil, v116, v115);

v65:
    v115 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v115); }

v108:
    v115 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v115); }
/* error exit handlers */
v110:
    popv(2);
    return nil;
}



/* Code for rassoc */

static Lisp_Object CC_rassoc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v114, v107, v124;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rassoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v107 = v1;
    v124 = v0;
/* end of prologue */

v20:
    v90 = v107;
    if (!consp(v90)) goto v44;
    v114 = v124;
    v90 = v107;
    v90 = qcar(v90);
    v90 = qcdr(v90);
    if (equal(v114, v90)) goto v138;
    v90 = v107;
    v90 = qcdr(v90);
    v107 = v90;
    goto v20;

v138:
    v90 = v107;
    v90 = qcar(v90);
    return onevalue(v90);

v44:
    v90 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v90);
}



/* Code for strand!-alg!-top */

static Lisp_Object MS_CDECL CC_strandKalgKtop(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v113, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v132, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "strand-alg-top");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for strand-alg-top");
#endif
    if (stack >= stacklimit)
    {
        push3(v113,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v113);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v113;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v132 = stack[-2];
    v98 = stack[0];
    fn = elt(env, 2); /* deletez1 */
    v98 = (*qfn2(fn))(qenv(fn), v132, v98);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-3];
    stack[-2] = v98;
    v139 = stack[0];
    v132 = stack[-1];
    v98 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 3); /* color!-strand */
    v98 = (*qfnn(fn))(qenv(fn), 3, v139, v132, v98);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-3];
    stack[0] = v98;
    v132 = stack[-2];
    v98 = stack[0];
    fn = elt(env, 4); /* contract!-strand */
    v98 = (*qfn2(fn))(qenv(fn), v132, v98);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-3];
    stack[-2] = v98;
    v139 = stack[-2];
    v132 = stack[0];
    v98 = qvalue(elt(env, 1)); /* nil */
    {
        popv(4);
        fn = elt(env, 5); /* dstr!-to!-alg */
        return (*qfnn(fn))(qenv(fn), 3, v139, v132, v98);
    }
/* error exit handlers */
v119:
    popv(4);
    return nil;
}



/* Code for reduce!-weights */

static Lisp_Object MS_CDECL CC_reduceKweights(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v113, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "reduce-weights");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-weights");
#endif
    if (stack >= stacklimit)
    {
        push3(v113,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v113);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v113;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = nil;
    v143 = stack[-5];
    v142 = stack[-3];
    fn = elt(env, 2); /* red!-weight */
    v142 = (*qfn2(fn))(qenv(fn), v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    stack[-2] = v142;
    goto v112;

v112:
    v143 = stack[-5];
    v142 = stack[-4];
    fn = elt(env, 3); /* mv!-domainlist!-!+ */
    v142 = (*qfn2(fn))(qenv(fn), v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    stack[-1] = v142;
    v143 = stack[-1];
    v142 = stack[-3];
    fn = elt(env, 2); /* red!-weight */
    v142 = (*qfn2(fn))(qenv(fn), v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    stack[0] = v142;
    v143 = stack[0];
    v142 = stack[-2];
    fn = elt(env, 4); /* red!-weight!-less!-p */
    v142 = (*qfn2(fn))(qenv(fn), v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    if (v142 == nil) goto v136;
    v142 = qvalue(elt(env, 1)); /* t */
    stack[-6] = v142;
    v142 = stack[-1];
    stack[-5] = v142;
    v142 = stack[0];
    stack[-2] = v142;
    goto v112;

v136:
    v142 = stack[-6];
    if (!(v142 == nil)) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }

v121:
    v143 = stack[-5];
    v142 = stack[-4];
    fn = elt(env, 5); /* mv!-domainlist!-!- */
    v142 = (*qfn2(fn))(qenv(fn), v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    stack[-1] = v142;
    v143 = stack[-1];
    v142 = stack[-3];
    fn = elt(env, 2); /* red!-weight */
    v142 = (*qfn2(fn))(qenv(fn), v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    stack[0] = v142;
    v143 = stack[0];
    v142 = stack[-2];
    fn = elt(env, 4); /* red!-weight!-less!-p */
    v142 = (*qfn2(fn))(qenv(fn), v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    if (v142 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v142 = stack[-1];
    stack[-5] = v142;
    v142 = stack[0];
    stack[-2] = v142;
    goto v121;
/* error exit handlers */
v144:
    popv(8);
    return nil;
}



/* Code for fs!:timescoeff */

static Lisp_Object CC_fsTtimescoeff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v153, v154, v155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:timescoeff");
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

v156:
    v101 = stack[-2];
    if (v101 == nil) goto v20;
    v154 = stack[-3];
    v153 = stack[-2];
    v101 = (Lisp_Object)1; /* 0 */
    v101 = *(Lisp_Object *)((char *)v153 + (CELL-TAG_VECTOR) + ((int32_t)v101/(16/CELL)));
    fn = elt(env, 4); /* multsq */
    v101 = (*qfn2(fn))(qenv(fn), v154, v101);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    stack[0] = v101;
    v153 = stack[0];
    v101 = elt(env, 2); /* (nil . 1) */
    if (equal(v153, v101)) goto v124;
    v101 = (Lisp_Object)49; /* 3 */
    v101 = Lmkvect(nil, v101);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    stack[-4] = v101;
    v154 = stack[-4];
    v153 = (Lisp_Object)1; /* 0 */
    v101 = stack[0];
    *(Lisp_Object *)((char *)v154 + (CELL-TAG_VECTOR) + ((int32_t)v153/(16/CELL))) = v101;
    v155 = stack[-4];
    v154 = (Lisp_Object)17; /* 1 */
    v153 = stack[-2];
    v101 = (Lisp_Object)17; /* 1 */
    v101 = *(Lisp_Object *)((char *)v153 + (CELL-TAG_VECTOR) + ((int32_t)v101/(16/CELL)));
    *(Lisp_Object *)((char *)v155 + (CELL-TAG_VECTOR) + ((int32_t)v154/(16/CELL))) = v101;
    v155 = stack[-4];
    v154 = (Lisp_Object)33; /* 2 */
    v153 = stack[-2];
    v101 = (Lisp_Object)33; /* 2 */
    v101 = *(Lisp_Object *)((char *)v153 + (CELL-TAG_VECTOR) + ((int32_t)v101/(16/CELL)));
    *(Lisp_Object *)((char *)v155 + (CELL-TAG_VECTOR) + ((int32_t)v154/(16/CELL))) = v101;
    stack[-1] = stack[-4];
    stack[0] = (Lisp_Object)49; /* 3 */
    v154 = stack[-3];
    v153 = stack[-2];
    v101 = (Lisp_Object)49; /* 3 */
    v101 = *(Lisp_Object *)((char *)v153 + (CELL-TAG_VECTOR) + ((int32_t)v101/(16/CELL)));
    v101 = CC_fsTtimescoeff(env, v154, v101);
    nil = C_nil;
    if (exception_pending()) goto v157;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v101;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }

v124:
    v101 = elt(env, 3); /* "zero in times" */
    v101 = Lprint(nil, v101);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    v154 = stack[-3];
    v153 = stack[-2];
    v101 = (Lisp_Object)49; /* 3 */
    v101 = *(Lisp_Object *)((char *)v153 + (CELL-TAG_VECTOR) + ((int32_t)v101/(16/CELL)));
    stack[-3] = v154;
    stack[-2] = v101;
    goto v156;

v20:
    v101 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v101); }
/* error exit handlers */
v157:
    popv(6);
    return nil;
}



/* Code for addnew */

static Lisp_Object MS_CDECL CC_addnew(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v113, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v151, v118, v119, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "addnew");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addnew");
#endif
    if (stack >= stacklimit)
    {
        push3(v113,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v113);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v113;
    v119 = v1;
    v61 = v0;
/* end of prologue */
    v118 = qvalue(elt(env, 1)); /* gv */
    v151 = v119;
    v133 = v61;
    *(Lisp_Object *)((char *)v118 + (CELL-TAG_VECTOR) + ((int32_t)v151/(16/CELL))) = v133;
    v118 = qvalue(elt(env, 2)); /* bv */
    v151 = v119;
    v133 = qvalue(elt(env, 3)); /* t */
    *(Lisp_Object *)((char *)v118 + (CELL-TAG_VECTOR) + ((int32_t)v151/(16/CELL))) = v133;
    v133 = v61;
    if (v133 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = v119;
    v133 = v61;
    fn = elt(env, 4); /* ljet */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    v151 = cons(stack[-1], v133);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    v133 = stack[0];
    fn = elt(env, 5); /* insert */
    v133 = (*qfn2(fn))(qenv(fn), v151, v133);
    nil = C_nil;
    if (exception_pending()) goto v152;
    { popv(3); return onevalue(v133); }
/* error exit handlers */
v152:
    popv(3);
    return nil;
}



/* Code for !*q2f */

static Lisp_Object CC_Hq2f(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v71, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *q2f");
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
    v97 = v0;
/* end of prologue */
    v111 = v97;
    v71 = qcdr(v111);
    v111 = (Lisp_Object)17; /* 1 */
    if (v71 == v111) goto v26;
    v111 = v97;
    v111 = qcar(v111);
    if (v111 == nil) goto v70;
    v71 = v97;
    v111 = elt(env, 1); /* prepf */
    fn = elt(env, 3); /* sqform */
    v111 = (*qfn2(fn))(qenv(fn), v71, v111);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[0];
    v71 = v111;
    goto v112;

v112:
    v111 = elt(env, 2); /* polynomial */
    {
        popv(1);
        fn = elt(env, 4); /* typerr */
        return (*qfn2(fn))(qenv(fn), v71, v111);
    }

v70:
    v111 = (Lisp_Object)1; /* 0 */
    v71 = v111;
    goto v112;

v26:
    v111 = v97;
    v111 = qcar(v111);
    { popv(1); return onevalue(v111); }
/* error exit handlers */
v98:
    popv(1);
    return nil;
}



/* Code for conjgd */

static Lisp_Object CC_conjgd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v167, v168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conjgd");
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
    v168 = nil;
    v167 = stack[-1];
    if (!consp(v167)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v167 = stack[-1];
    if (!consp(v167)) goto v105;
    v167 = stack[-1];
    v167 = qcar(v167);
    v167 = (consp(v167) ? nil : lisp_true);
    goto v99;

v99:
    if (v167 == nil) goto v136;
    v167 = stack[-1];
    v168 = qcar(v167);
    v167 = elt(env, 2); /* cmpxfn */
    v167 = get(v168, v167);
    env = stack[-3];
    v168 = v167;
    goto v81;

v81:
    if (v167 == nil) goto v138;
    stack[-2] = v168;
    v167 = stack[-1];
    v167 = qcdr(v167);
    stack[0] = qcar(v167);
    v167 = stack[-1];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    if (is_number(v167)) goto v169;
    v167 = stack[-1];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    if (!consp(v167)) goto v125;
    v167 = stack[-1];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcar(v167);
    v167 = (consp(v167) ? nil : lisp_true);
    goto v135;

v135:
    if (v167 == nil) goto v170;
    v167 = stack[-1];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcar(v167);
    v167 = (is_number(v167) ? lisp_true : nil);
    v167 = (v167 == nil ? lisp_true : nil);
    goto v94;

v94:
    if (v167 == nil) goto v171;
    v167 = stack[-1];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    fn = elt(env, 5); /* !:minus */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    goto v132;

v132:
    {
        Lisp_Object v173 = stack[-2];
        Lisp_Object v174 = stack[0];
        popv(4);
        return Lapply2(nil, 3, v173, v174, v167);
    }

v171:
    v167 = stack[-1];
    v168 = qcar(v167);
    v167 = elt(env, 4); /* realtype */
    v168 = get(v168, v167);
    env = stack[-3];
    v167 = stack[-1];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = cons(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-3];
    fn = elt(env, 5); /* !:minus */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    v167 = qcdr(v167);
    goto v132;

v170:
    v167 = qvalue(elt(env, 3)); /* nil */
    goto v94;

v125:
    v167 = qvalue(elt(env, 1)); /* t */
    goto v135;

v169:
    v167 = stack[-1];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = negate(v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    goto v132;

v138:
    v167 = stack[-1];
    if (!consp(v167)) goto v175;
    v167 = stack[-1];
    v167 = qcar(v167);
    v167 = (consp(v167) ? nil : lisp_true);
    goto v176;

v176:
    if (!(v167 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v167 = stack[-1];
    v167 = qcar(v167);
    v168 = qcar(v167);
    v167 = (Lisp_Object)17; /* 1 */
    v167 = cons(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-3];
    stack[0] = ncons(v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-3];
    v167 = stack[-1];
    v167 = qcar(v167);
    v167 = qcdr(v167);
    v167 = CC_conjgd(env, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-3];
    fn = elt(env, 6); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-3];
    v167 = stack[-1];
    v167 = qcdr(v167);
    v167 = CC_conjgd(env, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-3];
    {
        Lisp_Object v177 = stack[0];
        popv(4);
        fn = elt(env, 7); /* addf */
        return (*qfn2(fn))(qenv(fn), v177, v167);
    }

v175:
    v167 = qvalue(elt(env, 1)); /* t */
    goto v176;

v136:
    v167 = qvalue(elt(env, 3)); /* nil */
    goto v81;

v105:
    v167 = qvalue(elt(env, 1)); /* t */
    goto v99;
/* error exit handlers */
v172:
    popv(4);
    return nil;
}



/* Code for mri_opn */

static Lisp_Object CC_mri_opn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v178;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_opn");
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
    v108 = v0;
/* end of prologue */
    fn = elt(env, 1); /* mri_op */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    errexit();
    v178 = v108;
    v108 = v178;
    if (!consp(v108)) return onevalue(v178);
    v108 = v178;
    v108 = qcar(v108);
    return onevalue(v108);
}



/* Code for pasf_anegateat */

static Lisp_Object CC_pasf_anegateat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_anegateat");
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
    v30 = stack[-1];
    v186 = elt(env, 1); /* true */
    if (v30 == v186) goto v166;
    v30 = stack[-1];
    v186 = elt(env, 3); /* false */
    v186 = (v30 == v186 ? lisp_true : nil);
    goto v178;

v178:
    if (v186 == nil) goto v81;
    v186 = stack[-1];
    v30 = v186;
    goto v44;

v44:
    v186 = elt(env, 4); /* (cong ncong) */
    v186 = Lmemq(nil, v30, v186);
    if (v186 == nil) goto v187;
    v30 = stack[-1];
    v186 = elt(env, 1); /* true */
    if (v30 == v186) goto v95;
    v30 = stack[-1];
    v186 = elt(env, 3); /* false */
    v186 = (v30 == v186 ? lisp_true : nil);
    goto v58;

v58:
    if (v186 == nil) goto v135;
    v186 = stack[-1];
    goto v149;

v149:
    fn = elt(env, 5); /* pasf_anegrel */
    v30 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-3];
    v186 = stack[-1];
    v186 = qcar(v186);
    v186 = qcdr(v186);
    fn = elt(env, 6); /* pasf_mkop */
    stack[-2] = (*qfn2(fn))(qenv(fn), v30, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-3];
    v186 = stack[-1];
    v186 = qcdr(v186);
    v186 = qcar(v186);
    fn = elt(env, 7); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-3];
    v186 = stack[-1];
    v186 = qcdr(v186);
    v186 = qcdr(v186);
    v186 = qcar(v186);
    fn = elt(env, 7); /* negf */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    {
        Lisp_Object v189 = stack[-2];
        Lisp_Object v190 = stack[0];
        popv(4);
        return list3(v189, v190, v186);
    }

v135:
    v186 = stack[-1];
    v186 = qcar(v186);
    v186 = Lconsp(nil, v186);
    env = stack[-3];
    if (v186 == nil) goto v48;
    v186 = stack[-1];
    v186 = qcar(v186);
    v186 = qcar(v186);
    goto v149;

v48:
    v186 = stack[-1];
    v186 = qcar(v186);
    goto v149;

v95:
    v186 = qvalue(elt(env, 2)); /* t */
    goto v58;

v187:
    v30 = stack[-1];
    v186 = elt(env, 1); /* true */
    if (v30 == v186) goto v103;
    v30 = stack[-1];
    v186 = elt(env, 3); /* false */
    v186 = (v30 == v186 ? lisp_true : nil);
    goto v102;

v102:
    if (v186 == nil) goto v155;
    v186 = stack[-1];
    goto v153;

v153:
    fn = elt(env, 5); /* pasf_anegrel */
    stack[-2] = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-3];
    v186 = stack[-1];
    v186 = qcdr(v186);
    v186 = qcar(v186);
    fn = elt(env, 7); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-3];
    v186 = stack[-1];
    v186 = qcdr(v186);
    v186 = qcdr(v186);
    v186 = qcar(v186);
    fn = elt(env, 7); /* negf */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    {
        Lisp_Object v32 = stack[-2];
        Lisp_Object v191 = stack[0];
        popv(4);
        return list3(v32, v191, v186);
    }

v155:
    v186 = stack[-1];
    v186 = qcar(v186);
    v186 = Lconsp(nil, v186);
    env = stack[-3];
    if (v186 == nil) goto v192;
    v186 = stack[-1];
    v186 = qcar(v186);
    v186 = qcar(v186);
    goto v153;

v192:
    v186 = stack[-1];
    v186 = qcar(v186);
    goto v153;

v103:
    v186 = qvalue(elt(env, 2)); /* t */
    goto v102;

v81:
    v186 = stack[-1];
    v186 = qcar(v186);
    v186 = Lconsp(nil, v186);
    env = stack[-3];
    if (v186 == nil) goto v132;
    v186 = stack[-1];
    v186 = qcar(v186);
    v186 = qcar(v186);
    v30 = v186;
    goto v44;

v132:
    v186 = stack[-1];
    v186 = qcar(v186);
    v30 = v186;
    goto v44;

v166:
    v186 = qvalue(elt(env, 2)); /* t */
    goto v178;
/* error exit handlers */
v188:
    popv(4);
    return nil;
}



/* Code for bc_minus!? */

static Lisp_Object CC_bc_minusW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_minus?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v26 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* minusf */
        return (*qfn1(fn))(qenv(fn), v26);
    }
}



/* Code for vdp_getprop */

static Lisp_Object CC_vdp_getprop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_getprop");
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
    v65 = v1;
    v66 = v0;
/* end of prologue */
    stack[0] = v65;
    v65 = v66;
    fn = elt(env, 2); /* vdp_plist */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    v65 = Latsoc(nil, stack[0], v65);
    v66 = v65;
    v65 = v66;
    if (v65 == nil) goto v104;
    v65 = v66;
    v65 = qcdr(v65);
    { popv(2); return onevalue(v65); }

v104:
    v65 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v65); }
/* error exit handlers */
v70:
    popv(2);
    return nil;
}



/* Code for lowupperlimitml */

static Lisp_Object CC_lowupperlimitml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lowupperlimitml");
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
    v90 = elt(env, 1); /* "<lowlimit>" */
    fn = elt(env, 7); /* printout */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-1];
    v90 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 8); /* indent!* */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-1];
    v90 = stack[0];
    v90 = qcdr(v90);
    v90 = qcar(v90);
    fn = elt(env, 9); /* expression */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-1];
    v90 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 8); /* indent!* */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-1];
    v90 = elt(env, 4); /* "</lowlimit>" */
    fn = elt(env, 7); /* printout */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-1];
    v90 = elt(env, 5); /* "<uplimit>" */
    fn = elt(env, 7); /* printout */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-1];
    v90 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 8); /* indent!* */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-1];
    v90 = stack[0];
    v90 = qcdr(v90);
    v90 = qcdr(v90);
    v90 = qcar(v90);
    fn = elt(env, 9); /* expression */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-1];
    v90 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 8); /* indent!* */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-1];
    v90 = elt(env, 6); /* "</uplimit>" */
    fn = elt(env, 7); /* printout */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v107;
    v90 = nil;
    { popv(2); return onevalue(v90); }
/* error exit handlers */
v107:
    popv(2);
    return nil;
}



/* Code for ps!:term!-rthpow */

static Lisp_Object MS_CDECL CC_psTtermKrthpow(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v113, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ps:term-rthpow");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:term-rthpow");
#endif
    if (stack >= stacklimit)
    {
        push3(v113,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v113);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v113;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v129 = stack[-3];
    v128 = stack[-2];
    fn = elt(env, 2); /* ps!:get!-term */
    v128 = (*qfn2(fn))(qenv(fn), v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    stack[-4] = v128;
    v128 = stack[-4];
    if (!(v128 == nil)) goto v60;
    v128 = stack[-3];
    fn = elt(env, 3); /* ps!:last!-term */
    v128 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    v128 = add1(v128);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    stack[0] = v128;
    goto v62;

v62:
    v129 = stack[-2];
    v128 = stack[0];
    v128 = difference2(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    v128 = Lminusp(nil, v128);
    env = stack[-5];
    if (!(v128 == nil)) goto v60;
    v129 = stack[-3];
    v128 = stack[0];
    fn = elt(env, 4); /* ps!:set!-rthpow */
    v128 = (*qfn2(fn))(qenv(fn), v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    stack[-4] = v128;
    v128 = stack[0];
    v128 = add1(v128);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-5];
    stack[0] = v128;
    goto v62;

v60:
    v129 = stack[-4];
    v128 = stack[-1];
    {
        popv(6);
        fn = elt(env, 5); /* ps!:evaluate */
        return (*qfn2(fn))(qenv(fn), v129, v128);
    }
/* error exit handlers */
v149:
    popv(6);
    return nil;
}



/* Code for greatertype */

static Lisp_Object CC_greatertype(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v197, v34, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for greatertype");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v197 = qvalue(elt(env, 1)); /* optlang!* */
    if (v197 == nil) goto v66;
    v197 = qvalue(elt(env, 1)); /* optlang!* */
    v34 = v197;
    goto v108;

v108:
    v197 = elt(env, 3); /* conversion */
    v197 = get(v34, v197);
    env = stack[-8];
    fn = elt(env, 6); /* eval */
    v197 = (*qfn1(fn))(qenv(fn), v197);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-8];
    stack[-7] = v197;
    v197 = stack[-7];
    v34 = qcar(v197);
    v197 = stack[-5];
    if (equal(v34, v197)) goto v114;
    v197 = stack[-7];
    v34 = qcar(v197);
    v197 = stack[-6];
    if (!(equal(v34, v197))) goto v93;
    v197 = qvalue(elt(env, 5)); /* nil */
    stack[-1] = v197;
    { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }

v93:
    v197 = stack[-7];
    v197 = qcdr(v197);
    stack[-7] = v197;
    if (v197 == nil) { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }
    v197 = stack[-4];
    if (!(v197 == nil)) { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }
    v197 = stack[-7];
    v197 = qcar(v197);
    v35 = v197;
    goto v125;

v125:
    v197 = v35;
    if (v197 == nil) goto v135;
    v197 = stack[-2];
    if (!(v197 == nil)) goto v135;
    v197 = v35;
    v34 = qcar(v197);
    v197 = stack[-6];
    if (!(equal(v34, v197))) goto v199;
    v197 = qvalue(elt(env, 4)); /* t */
    stack[-3] = v197;
    goto v199;

v199:
    v197 = v35;
    v34 = qcar(v197);
    v197 = stack[-5];
    if (equal(v34, v197)) goto v200;
    v197 = v35;
    v197 = qcdr(v197);
    v35 = v197;
    goto v125;

v200:
    v197 = qvalue(elt(env, 4)); /* t */
    stack[-2] = v197;
    goto v125;

v135:
    v197 = stack[-2];
    if (v197 == nil) goto v146;
    v197 = v35;
    v197 = qcdr(v197);
    v35 = v197;
    goto v88;

v88:
    v197 = v35;
    if (v197 == nil) goto v146;
    v197 = stack[-1];
    if (!(v197 == nil)) goto v146;
    v197 = v35;
    v34 = qcar(v197);
    v197 = stack[-6];
    if (equal(v34, v197)) goto v155;
    v197 = v35;
    v197 = qcdr(v197);
    v35 = v197;
    goto v88;

v155:
    v197 = qvalue(elt(env, 4)); /* t */
    stack[-1] = v197;
    stack[-3] = v197;
    goto v88;

v146:
    v197 = stack[-3];
    if (v197 == nil) goto v180;
    v197 = stack[-2];
    if (!(v197 == nil)) goto v180;

v36:
    stack[0] = (Lisp_Object)65; /* 4 */
    v34 = stack[-6];
    v197 = stack[-5];
    v197 = cons(v34, v197);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-8];
    fn = elt(env, 7); /* typerror */
    v197 = (*qfn2(fn))(qenv(fn), stack[0], v197);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-8];
    goto v93;

v180:
    v197 = stack[-3];
    if (v197 == nil) goto v201;
    v197 = qvalue(elt(env, 5)); /* nil */
    goto v202;

v202:
    if (!(v197 == nil)) goto v36;
    v197 = stack[-3];
    if (v197 == nil) goto v93;
    v197 = stack[-2];
    if (v197 == nil) goto v93;
    v197 = qvalue(elt(env, 4)); /* t */
    stack[-4] = v197;
    goto v93;

v201:
    v197 = stack[-2];
    goto v202;

v114:
    v197 = qvalue(elt(env, 4)); /* t */
    stack[-1] = v197;
    { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }

v66:
    v197 = elt(env, 2); /* fortran */
    v34 = v197;
    goto v108;
/* error exit handlers */
v198:
    popv(9);
    return nil;
}



/* Code for sfpf */

static Lisp_Object CC_sfpf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v116;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfpf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v116 = v0;
/* end of prologue */
    v115 = v116;
    if (!consp(v115)) goto v44;
    v115 = v116;
    v115 = qcar(v115);
    v115 = (consp(v115) ? nil : lisp_true);
    goto v25;

v25:
    if (v115 == nil) goto v26;
    v115 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v115);

v26:
    v115 = v116;
    v115 = qcar(v115);
    v115 = qcar(v115);
    v115 = qcar(v115);
    if (!consp(v115)) goto v124;
    v115 = v116;
    v115 = qcar(v115);
    v115 = qcar(v115);
    v115 = qcar(v115);
    v115 = qcar(v115);
    v115 = (consp(v115) ? nil : lisp_true);
    v115 = (v115 == nil ? lisp_true : nil);
    return onevalue(v115);

v124:
    v115 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v115);

v44:
    v115 = qvalue(elt(env, 1)); /* t */
    goto v25;
}



/* Code for dipnumcontent */

static Lisp_Object CC_dipnumcontent(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipnumcontent");
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

v31:
    v64 = stack[0];
    fn = elt(env, 1); /* bcone!? */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    if (!(v64 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v64 = stack[-1];
    if (v64 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v64 = stack[-1];
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    stack[-2] = v64;
    v62 = stack[0];
    v64 = stack[-1];
    v64 = qcdr(v64);
    v64 = qcar(v64);
    fn = elt(env, 2); /* vbcgcd */
    v64 = (*qfn2(fn))(qenv(fn), v62, v64);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    stack[0] = v64;
    v64 = stack[-2];
    stack[-1] = v64;
    goto v31;
/* error exit handlers */
v115:
    popv(4);
    return nil;
}



/* Code for groebsaveltermbc */

static Lisp_Object CC_groebsaveltermbc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v56, v134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebsaveltermbc");
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
    v141 = stack[0];
    fn = elt(env, 3); /* vbc2a */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-2];
    stack[0] = v141;
    v141 = stack[0];
    if (is_number(v141)) goto v178;
    v141 = stack[0];
    fn = elt(env, 4); /* constant_exprp */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-2];
    v141 = (v141 == nil ? lisp_true : nil);
    goto v43;

v43:
    if (v141 == nil) goto v25;
    v141 = stack[0];
    fn = elt(env, 5); /* simp */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-2];
    v141 = qcar(v141);
    fn = elt(env, 6); /* fctrf */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-2];
    v141 = qcdr(v141);
    stack[-1] = v141;
    goto v126;

v126:
    v141 = stack[-1];
    if (v141 == nil) goto v114;
    v141 = stack[-1];
    v141 = qcar(v141);
    v134 = v141;
    v141 = v134;
    v141 = qcar(v141);
    fn = elt(env, 7); /* prepf */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-2];
    v134 = v141;
    v56 = v134;
    v141 = qvalue(elt(env, 2)); /* glterms */
    v141 = Lmember(nil, v56, v141);
    if (!(v141 == nil)) goto v110;
    stack[0] = qvalue(elt(env, 2)); /* glterms */
    v141 = v134;
    v141 = ncons(v141);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-2];
    v141 = Lnconc(nil, stack[0], v141);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-2];
    goto v110;

v110:
    v141 = stack[-1];
    v141 = qcdr(v141);
    stack[-1] = v141;
    goto v126;

v114:
    v141 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v141); }

v25:
    v141 = nil;
    { popv(3); return onevalue(v141); }

v178:
    v141 = qvalue(elt(env, 1)); /* nil */
    goto v43;
/* error exit handlers */
v149:
    popv(3);
    return nil;
}



/* Code for xpartitk */

static Lisp_Object CC_xpartitk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v91, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xpartitk");
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
    v91 = stack[0];
    v121 = elt(env, 1); /* (wedge partdf) */
    fn = elt(env, 2); /* memqcar */
    v121 = (*qfn2(fn))(qenv(fn), v91, v121);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-1];
    if (v121 == nil) goto v133;
    v121 = stack[0];
    fn = elt(env, 3); /* reval */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-1];
    v130 = v121;
    v91 = v130;
    v121 = stack[0];
    if (equal(v91, v121)) goto v114;
    v121 = v130;
    {
        popv(2);
        fn = elt(env, 4); /* xpartitop */
        return (*qfn1(fn))(qenv(fn), v121);
    }

v114:
    v130 = stack[0];
    v91 = (Lisp_Object)17; /* 1 */
    v121 = (Lisp_Object)17; /* 1 */
    v121 = list2star(v130, v91, v121);
    nil = C_nil;
    if (exception_pending()) goto v129;
    popv(2);
    return ncons(v121);

v133:
    v130 = stack[0];
    v91 = (Lisp_Object)17; /* 1 */
    v121 = (Lisp_Object)17; /* 1 */
    v121 = list2star(v130, v91, v121);
    nil = C_nil;
    if (exception_pending()) goto v129;
    popv(2);
    return ncons(v121);
/* error exit handlers */
v129:
    popv(2);
    return nil;
}



/* Code for delasc */

static Lisp_Object CC_delasc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v61;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delasc");
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
    goto v44;

v44:
    v119 = stack[0];
    if (v119 == nil) goto v25;
    v119 = stack[0];
    v119 = qcar(v119);
    if (!consp(v119)) goto v112;
    v61 = stack[-1];
    v119 = stack[0];
    v119 = qcar(v119);
    v119 = qcar(v119);
    v119 = Lneq(nil, v61, v119);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    goto v104;

v104:
    if (v119 == nil) goto v178;
    v119 = stack[0];
    v61 = qcar(v119);
    v119 = stack[-2];
    v119 = cons(v61, v119);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    stack[-2] = v119;
    goto v178;

v178:
    v119 = stack[0];
    v119 = qcdr(v119);
    stack[0] = v119;
    goto v44;

v112:
    v119 = qvalue(elt(env, 2)); /* t */
    goto v104;

v25:
    v119 = stack[-2];
        popv(4);
        return Lnreverse(nil, v119);
/* error exit handlers */
v93:
    popv(4);
    return nil;
}



/* Code for indordlp */

static Lisp_Object CC_indordlp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v57, v92, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indordlp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v57 = v1;
    v92 = v0;
/* end of prologue */

v20:
    v59 = v92;
    if (v59 == nil) goto v44;
    v59 = v57;
    if (v59 == nil) goto v138;
    v59 = v92;
    v73 = qcar(v59);
    v59 = v57;
    v59 = qcar(v59);
    if (equal(v73, v59)) goto v178;
    v59 = v92;
    v59 = qcar(v59);
    if (!consp(v59)) goto v107;
    v59 = v57;
    v59 = qcar(v59);
    if (!consp(v59)) goto v169;
    v59 = v92;
    v59 = qcar(v59);
    v59 = qcdr(v59);
    v59 = qcar(v59);
    v57 = qcar(v57);
    v57 = qcdr(v57);
    v57 = qcar(v57);
    {
        fn = elt(env, 3); /* indordp */
        return (*qfn2(fn))(qenv(fn), v59, v57);
    }

v169:
    v59 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v59);

v107:
    v59 = v57;
    v59 = qcar(v59);
    if (!consp(v59)) goto v111;
    v59 = qvalue(elt(env, 2)); /* t */
    return onevalue(v59);

v111:
    v59 = v92;
    v59 = qcar(v59);
    v57 = qcar(v57);
    {
        fn = elt(env, 3); /* indordp */
        return (*qfn2(fn))(qenv(fn), v59, v57);
    }

v178:
    v59 = v92;
    v59 = qcdr(v59);
    v92 = v59;
    v59 = v57;
    v59 = qcdr(v59);
    v57 = v59;
    goto v20;

v138:
    v59 = qvalue(elt(env, 2)); /* t */
    return onevalue(v59);

v44:
    v59 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v59);
}



/* Code for s_noparents */

static Lisp_Object CC_s_noparents(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for s_noparents");
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
    goto v20;

v20:
    v64 = stack[0];
    if (v64 == nil) goto v44;
    v64 = stack[0];
    v64 = qcar(v64);
    fn = elt(env, 1); /* has_parents */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    if (v64 == nil) goto v65;
    v64 = stack[0];
    v64 = qcdr(v64);
    stack[0] = v64;
    goto v20;

v65:
    v64 = stack[0];
    v62 = qcar(v64);
    v64 = stack[-1];
    v64 = cons(v62, v64);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    stack[-1] = v64;
    v64 = stack[0];
    v64 = qcdr(v64);
    stack[0] = v64;
    goto v20;

v44:
    v64 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v64);
    }
/* error exit handlers */
v136:
    popv(3);
    return nil;
}



/* Code for !*hfac */

static Lisp_Object CC_Hhfac(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *hfac");
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
    v121 = stack[0];
    v121 = integerp(v121);
    if (v121 == nil) goto v44;
    v91 = stack[0];
    v121 = (Lisp_Object)1; /* 0 */
    v121 = (Lisp_Object)lessp2(v91, v121);
    nil = C_nil;
    if (exception_pending()) goto v128;
    v121 = v121 ? lisp_true : nil;
    env = stack[-1];
    if (!(v121 == nil)) goto v25;
    v91 = stack[0];
    v121 = (Lisp_Object)33; /* 2 */
    v121 = (Lisp_Object)greaterp2(v91, v121);
    nil = C_nil;
    if (exception_pending()) goto v128;
    v121 = v121 ? lisp_true : nil;
    env = stack[-1];
    goto v25;

v25:
    if (v121 == nil) goto v151;
    v121 = elt(env, 2); /* "Invalid index" */
    v91 = v121;
    v121 = v91;
    qvalue(elt(env, 3)) = v121; /* errmsg!* */
    v121 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v121 == nil)) goto v63;
    v121 = v91;
    fn = elt(env, 6); /* lprie */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-1];
    goto v63;

v63:
    v121 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v128;
    v121 = nil;
    { popv(2); return onevalue(v121); }

v151:
    v121 = elt(env, 5); /* hfactors */
    fn = elt(env, 7); /* getavalue */
    v91 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v128;
    v121 = stack[0];
    v121 = *(Lisp_Object *)((char *)v91 + (CELL-TAG_VECTOR) + ((int32_t)v121/(16/CELL)));
    { popv(2); return onevalue(v121); }

v44:
    v121 = qvalue(elt(env, 1)); /* t */
    goto v25;
/* error exit handlers */
v128:
    popv(2);
    return nil;
}



/* Code for mod!/ */

static Lisp_Object CC_modV(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v124, v64, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod/");
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
    v107 = v1;
    v124 = v0;
/* end of prologue */
    stack[0] = v124;
    v62 = qvalue(elt(env, 1)); /* current!-modulus */
    v64 = v107;
    v124 = (Lisp_Object)1; /* 0 */
    v107 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 2); /* general!-reciprocal!-by!-gcd */
    v107 = (*qfnn(fn))(qenv(fn), 4, v62, v64, v124, v107);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-1];
    v107 = times2(stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-1];
    v124 = qvalue(elt(env, 1)); /* current!-modulus */
    popv(2);
    return Cremainder(v107, v124);
/* error exit handlers */
v137:
    popv(2);
    return nil;
}



/* Code for cl_nnfnot */

static Lisp_Object CC_cl_nnfnot(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_nnfnot");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v16 = v0;
/* end of prologue */
    v75 = v16;
    v16 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* cl_nnf1 */
        return (*qfn2(fn))(qenv(fn), v75, v16);
    }
}



/* Code for addfactors */

static Lisp_Object CC_addfactors(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v122, v149, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addfactors");
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
    v149 = v1;
    v150 = v0;
/* end of prologue */
    v122 = v150;
    v94 = (Lisp_Object)17; /* 1 */
    if (v122 == v94) goto v20;
    v122 = v149;
    v94 = (Lisp_Object)17; /* 1 */
    if (v122 == v94) { popv(3); return onevalue(v150); }
    v122 = v150;
    v94 = elt(env, 1); /* times */
    if (!consp(v122)) goto v121;
    v122 = qcar(v122);
    if (!(v122 == v94)) goto v121;
    stack[-1] = elt(env, 1); /* times */
    v94 = v150;
    stack[0] = qcdr(v94);
    v94 = v149;
    fn = elt(env, 2); /* prepf */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    v94 = ncons(v94);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    v94 = Lnconc(nil, stack[0], v94);
    nil = C_nil;
    if (exception_pending()) goto v58;
    {
        Lisp_Object v95 = stack[-1];
        popv(3);
        return cons(v95, v94);
    }

v121:
    stack[0] = v150;
    v94 = v149;
    fn = elt(env, 2); /* prepf */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    v94 = list2(stack[0], v94);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* retimes */
        return (*qfn1(fn))(qenv(fn), v94);
    }

v20:
    v94 = v149;
    {
        popv(3);
        fn = elt(env, 2); /* prepf */
        return (*qfn1(fn))(qenv(fn), v94);
    }
/* error exit handlers */
v58:
    popv(3);
    return nil;
}



/* Code for ofsf_simplequal */

static Lisp_Object CC_ofsf_simplequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v55, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_simplequal");
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
    v54 = stack[-2];
    fn = elt(env, 8); /* ofsf_posdefp */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-4];
    stack[-3] = v54;
    v55 = stack[-3];
    v54 = elt(env, 1); /* stsq */
    if (v55 == v54) goto v138;
    v54 = stack[-2];
    fn = elt(env, 9); /* sfto_sqfpartf */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-4];
    stack[0] = v54;
    v54 = stack[0];
    fn = elt(env, 8); /* ofsf_posdefp */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-4];
    v52 = v54;
    v55 = v52;
    v54 = elt(env, 1); /* stsq */
    if (v55 == v54) goto v131;
    v54 = qvalue(elt(env, 3)); /* !*rlsitsqspl */
    if (v54 == nil) goto v53;
    v54 = qvalue(elt(env, 4)); /* !*rlsiexpla */
    if (!(v54 == nil)) goto v129;
    v54 = qvalue(elt(env, 5)); /* !*rlsiexpl */
    if (v54 == nil) goto v53;
    v55 = stack[-1];
    v54 = elt(env, 6); /* and */
    if (!(v55 == v54)) goto v53;

v129:
    v55 = v52;
    v54 = elt(env, 7); /* tsq */
    if (v55 == v54) goto v130;
    v55 = stack[-3];
    v54 = elt(env, 7); /* tsq */
    if (!(v55 == v54)) goto v53;
    v54 = stack[-2];
    {
        popv(5);
        fn = elt(env, 10); /* ofsf_tsqsplequal */
        return (*qfn1(fn))(qenv(fn), v54);
    }

v53:
    v55 = stack[0];
    v54 = stack[-1];
    {
        popv(5);
        fn = elt(env, 11); /* ofsf_facequal!* */
        return (*qfn2(fn))(qenv(fn), v55, v54);
    }

v130:
    v54 = stack[0];
    {
        popv(5);
        fn = elt(env, 10); /* ofsf_tsqsplequal */
        return (*qfn1(fn))(qenv(fn), v54);
    }

v131:
    v54 = elt(env, 2); /* false */
    { popv(5); return onevalue(v54); }

v138:
    v54 = elt(env, 2); /* false */
    { popv(5); return onevalue(v54); }
/* error exit handlers */
v203:
    popv(5);
    return nil;
}



/* Code for factorf */

static Lisp_Object CC_factorf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v218, v219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for factorf");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0;
/* end of prologue */
    v4 = qvalue(elt(env, 1)); /* current!-modulus */
    stack[-7] = qvalue(elt(env, 1)); /* current!-modulus */
    qvalue(elt(env, 1)) = v4; /* current!-modulus */
    stack[-6] = qvalue(elt(env, 2)); /* m!-image!-variable */
    qvalue(elt(env, 2)) = nil; /* m!-image!-variable */
    stack[-4] = nil;
    v4 = stack[-3];
    if (!consp(v4)) goto v99;
    v4 = stack[-3];
    v4 = qcar(v4);
    v4 = (consp(v4) ? nil : lisp_true);
    goto v166;

v166:
    if (v4 == nil) goto v114;
    v4 = stack[-3];
    v4 = ncons(v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    goto v75;

v75:
    qvalue(elt(env, 2)) = stack[-6]; /* m!-image!-variable */
    qvalue(elt(env, 1)) = stack[-7]; /* current!-modulus */
    { popv(9); return onevalue(v4); }

v114:
    v218 = stack[-3];
    v4 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 7); /* kernord */
    v4 = (*qfn2(fn))(qenv(fn), v218, v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    v218 = v4;
    v4 = qvalue(elt(env, 5)); /* !*kernreverse */
    if (v4 == nil) goto v115;
    v4 = v218;
    v4 = Lreverse(nil, v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    v218 = v4;
    goto v115;

v115:
    v4 = v218;
    fn = elt(env, 8); /* setkorder */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    stack[-5] = v4;
    v4 = stack[-3];
    fn = elt(env, 9); /* reorder */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    stack[-3] = v4;
    v4 = stack[-3];
    fn = elt(env, 10); /* minusf */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    if (v4 == nil) goto v151;
    v4 = stack[-4];
    v4 = (v4 == nil ? lisp_true : nil);
    stack[-4] = v4;
    v4 = stack[-3];
    fn = elt(env, 11); /* negf */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    stack[-3] = v4;
    goto v151;

v151:
    v4 = stack[-3];
    fn = elt(env, 12); /* comfac */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    stack[-2] = v4;
    v218 = stack[-3];
    v4 = stack[-2];
    v4 = qcdr(v4);
    fn = elt(env, 13); /* quotf1 */
    v4 = (*qfn2(fn))(qenv(fn), v218, v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    stack[-3] = v4;
    v4 = stack[-3];
    if (!consp(v4)) goto v59;
    v4 = stack[-3];
    v4 = qcar(v4);
    v4 = (consp(v4) ? nil : lisp_true);
    goto v96;

v96:
    if (v4 == nil) goto v135;
    v4 = elt(env, 6); /* "Improper factors in factorf" */
    v4 = ncons(v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    fn = elt(env, 14); /* errach */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    goto v135;

v135:
    v4 = stack[-2];
    v4 = qcar(v4);
    stack[-1] = v4;
    v4 = stack[-2];
    v4 = qcdr(v4);
    fn = elt(env, 15); /* fctrf1 */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    stack[-2] = v4;
    v4 = stack[-1];
    if (v4 == nil) goto v55;
    v4 = stack[-2];
    stack[0] = qcar(v4);
    v4 = stack[-1];
    v219 = qcar(v4);
    v218 = (Lisp_Object)17; /* 1 */
    v4 = (Lisp_Object)17; /* 1 */
    v4 = acons(v219, v218, v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    v218 = ncons(v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    v4 = stack[-1];
    v4 = qcdr(v4);
    v218 = cons(v218, v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    v4 = stack[-2];
    v4 = qcdr(v4);
    v4 = list2star(stack[0], v218, v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    stack[-2] = v4;
    goto v55;

v55:
    v4 = stack[-3];
    v4 = qcar(v4);
    v4 = qcar(v4);
    v4 = qcar(v4);
    qvalue(elt(env, 2)) = v4; /* m!-image!-variable */
    v4 = stack[-3];
    fn = elt(env, 16); /* factorize!-primitive!-polynomial */
    v218 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    v4 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 17); /* distribute!.multiplicity */
    v4 = (*qfn2(fn))(qenv(fn), v218, v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    stack[-3] = v4;
    v4 = stack[-5];
    fn = elt(env, 8); /* setkorder */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    v4 = stack[-4];
    if (v4 == nil) goto v36;
    v4 = stack[-3];
    v4 = qcar(v4);
    v4 = qcar(v4);
    fn = elt(env, 11); /* negf */
    v219 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    v4 = stack[-3];
    v4 = qcar(v4);
    v218 = qcdr(v4);
    v4 = stack[-3];
    v4 = qcdr(v4);
    v4 = acons(v219, v218, v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    stack[-3] = v4;
    goto v36;

v36:
    v218 = (Lisp_Object)17; /* 1 */
    v4 = stack[-3];
    v4 = cons(v218, v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    stack[-1] = v4;
    v4 = stack[-2];
    v218 = qcar(v4);
    v4 = stack[-1];
    v4 = qcar(v4);
    fn = elt(env, 18); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v218, v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    v4 = stack[-2];
    v218 = qcdr(v4);
    v4 = stack[-1];
    v4 = qcdr(v4);
    v4 = Lappend(nil, v218, v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    v4 = cons(stack[0], v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    stack[-3] = v4;
    v4 = stack[-3];
    stack[-5] = qcar(v4);
    v4 = stack[-3];
    v4 = qcdr(v4);
    stack[-4] = v4;
    v4 = stack[-4];
    if (v4 == nil) goto v24;
    v4 = stack[-4];
    v4 = qcar(v4);
    stack[0] = v4;
    v4 = stack[0];
    v4 = qcar(v4);
    fn = elt(env, 9); /* reorder */
    v218 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    v4 = stack[0];
    v4 = qcdr(v4);
    v4 = cons(v218, v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    v4 = ncons(v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    stack[-2] = v4;
    stack[-3] = v4;
    goto v220;

v220:
    v4 = stack[-4];
    v4 = qcdr(v4);
    stack[-4] = v4;
    v4 = stack[-4];
    if (v4 == nil) goto v221;
    stack[-1] = stack[-2];
    v4 = stack[-4];
    v4 = qcar(v4);
    stack[0] = v4;
    v4 = stack[0];
    v4 = qcar(v4);
    fn = elt(env, 9); /* reorder */
    v218 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    v4 = stack[0];
    v4 = qcdr(v4);
    v4 = cons(v218, v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    v4 = ncons(v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    v4 = Lrplacd(nil, stack[-1], v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    v4 = stack[-2];
    v4 = qcdr(v4);
    stack[-2] = v4;
    goto v220;

v221:
    v4 = stack[-3];
    goto v17;

v17:
    v4 = cons(stack[-5], v4);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    goto v75;

v24:
    v4 = qvalue(elt(env, 4)); /* nil */
    goto v17;

v59:
    v4 = qvalue(elt(env, 3)); /* t */
    goto v96;

v99:
    v4 = qvalue(elt(env, 3)); /* t */
    goto v166;
/* error exit handlers */
v67:
    env = stack[-8];
    qvalue(elt(env, 2)) = stack[-6]; /* m!-image!-variable */
    qvalue(elt(env, 1)) = stack[-7]; /* current!-modulus */
    popv(9);
    return nil;
}



/* Code for acfsf_0mk2 */

static Lisp_Object CC_acfsf_0mk2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v108, v178;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for acfsf_0mk2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v81 = v1;
    v108 = v0;
/* end of prologue */
    v178 = qvalue(elt(env, 1)); /* nil */
    return list3(v108, v81, v178);
}



/* Code for quotientml */

static Lisp_Object CC_quotientml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotientml");
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
    v94 = stack[0];
    v94 = qcar(v94);
    if (!(is_number(v94))) goto v136;
    v94 = stack[0];
    v94 = qcdr(v94);
    v94 = qcar(v94);
    if (!(is_number(v94))) goto v136;
    v94 = qvalue(elt(env, 1)); /* !*web */
    if (v94 == nil) goto v166;
    v94 = elt(env, 3); /* "<cn type=&quot;rational&quot;> " */
    fn = elt(env, 9); /* printout */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-1];
    goto v178;

v178:
    v94 = stack[0];
    v94 = qcar(v94);
    v94 = Lprinc(nil, v94);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-1];
    v94 = elt(env, 4); /* " <sep/> " */
    v94 = Lprinc(nil, v94);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-1];
    v94 = stack[0];
    v94 = qcdr(v94);
    v94 = qcar(v94);
    v94 = Lprinc(nil, v94);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-1];
    v94 = elt(env, 5); /* " </cn>" */
    v94 = Lprinc(nil, v94);
    nil = C_nil;
    if (exception_pending()) goto v150;
    goto v20;

v20:
    v94 = nil;
    { popv(2); return onevalue(v94); }

v166:
    v94 = elt(env, 2); /* "<cn type=""rational""> " */
    fn = elt(env, 9); /* printout */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-1];
    goto v178;

v136:
    v94 = elt(env, 6); /* "<apply><divide/>" */
    fn = elt(env, 9); /* printout */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-1];
    v122 = qvalue(elt(env, 7)); /* indent */
    v94 = (Lisp_Object)49; /* 3 */
    v94 = plus2(v122, v94);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-1];
    qvalue(elt(env, 7)) = v94; /* indent */
    v94 = stack[0];
    v94 = qcar(v94);
    fn = elt(env, 10); /* expression */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-1];
    v94 = stack[0];
    v94 = qcdr(v94);
    v94 = qcar(v94);
    fn = elt(env, 10); /* expression */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-1];
    v122 = qvalue(elt(env, 7)); /* indent */
    v94 = (Lisp_Object)49; /* 3 */
    v94 = difference2(v122, v94);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-1];
    qvalue(elt(env, 7)) = v94; /* indent */
    v94 = elt(env, 8); /* "</apply>" */
    fn = elt(env, 9); /* printout */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v150;
    goto v20;
/* error exit handlers */
v150:
    popv(2);
    return nil;
}



/* Code for is_buble */

static Lisp_Object CC_is_buble(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v139, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for is_buble");
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
    v133 = stack[-1];
    v139 = stack[0];
    fn = elt(env, 2); /* diff_vertex */
    v139 = (*qfn2(fn))(qenv(fn), v133, v139);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-3];
    v139 = Llength(nil, v139);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-3];
    stack[-2] = v139;
    v133 = stack[-2];
    v139 = (Lisp_Object)33; /* 2 */
    v139 = (Lisp_Object)geq2(v133, v139);
    nil = C_nil;
    if (exception_pending()) goto v61;
    v139 = v139 ? lisp_true : nil;
    env = stack[-3];
    if (v139 == nil) goto v136;
    v139 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v139); }

v136:
    v133 = (Lisp_Object)33; /* 2 */
    v139 = stack[-2];
    stack[-2] = times2(v133, v139);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-3];
    v139 = stack[0];
    v139 = ncons(v139);
    nil = C_nil;
    if (exception_pending()) goto v61;
    {
        Lisp_Object v60 = stack[-2];
        Lisp_Object v169 = stack[-1];
        popv(4);
        return list2star(v60, v169, v139);
    }
/* error exit handlers */
v61:
    popv(4);
    return nil;
}



/* Code for groeb!=testc1 */

static Lisp_Object CC_groebMtestc1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=testc1");
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
    v132 = stack[0];
    v98 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 1); /* pnth */
    v98 = (*qfn2(fn))(qenv(fn), v132, v98);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v98 = qcar(v98);
    fn = elt(env, 2); /* bas_dpoly */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    fn = elt(env, 3); /* dp_lmon */
    stack[-1] = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v132 = stack[0];
    v98 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 1); /* pnth */
    v98 = (*qfn2(fn))(qenv(fn), v132, v98);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v98 = qcar(v98);
    fn = elt(env, 2); /* bas_dpoly */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    fn = elt(env, 3); /* dp_lmon */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    fn = elt(env, 4); /* mo_sum */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v98);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v132 = stack[0];
    v98 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* pnth */
    v98 = (*qfn2(fn))(qenv(fn), v132, v98);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v98 = qcar(v98);
    {
        Lisp_Object v118 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* mo_equal!? */
        return (*qfn2(fn))(qenv(fn), v118, v98);
    }
/* error exit handlers */
v151:
    popv(3);
    return nil;
}



/* Code for checkcoeffts */

static Lisp_Object CC_checkcoeffts(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checkcoeffts");
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

v156:
    v93 = stack[-1];
    if (v93 == nil) goto v20;
    v93 = stack[-1];
    v93 = qcar(v93);
    v120 = qcar(v93);
    v93 = stack[0];
    fn = elt(env, 3); /* evaluatecoeffts */
    v93 = (*qfn2(fn))(qenv(fn), v120, v93);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v120 = v93;
    v93 = v120;
    if (v93 == nil) goto v114;
    v93 = (Lisp_Object)1; /* 0 */
    v93 = (v120 == v93 ? lisp_true : nil);
    goto v90;

v90:
    if (v93 == nil) goto v70;
    v93 = stack[-1];
    v120 = qcdr(v93);
    v93 = stack[0];
    stack[-1] = v120;
    stack[0] = v93;
    goto v156;

v70:
    v93 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v93); }

v114:
    v93 = qvalue(elt(env, 1)); /* t */
    goto v90;

v20:
    v93 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v93); }
/* error exit handlers */
v130:
    popv(3);
    return nil;
}



/* Code for pasf_dnf */

static Lisp_Object CC_pasf_dnf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_dnf");
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
    v75 = v0;
/* end of prologue */
    fn = elt(env, 2); /* pasf_pnf */
    v138 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[0];
    v75 = elt(env, 1); /* dnf */
    {
        popv(1);
        fn = elt(env, 3); /* pasf_pbnf */
        return (*qfn2(fn))(qenv(fn), v138, v75);
    }
/* error exit handlers */
v84:
    popv(1);
    return nil;
}



/* Code for bra_mk */

static Lisp_Object MS_CDECL CC_bra_mk(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v113, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v178, v166;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "bra_mk");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bra_mk");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v108 = v113;
    v178 = v1;
    v166 = v0;
/* end of prologue */
    return list3(v166, v178, v108);
}



/* Code for ofsf_sacrel!-and */

static Lisp_Object CC_ofsf_sacrelKand(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v123, v70;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sacrel-and");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v66 = v1;
    v123 = v0;
/* end of prologue */
    v70 = elt(env, 1); /* ((lessp (lessp . keep) (leq . keep2) (equal . drop) (neq . keep2) (geq . drop) (greaterp . drop)) (leq (lessp . keep1) (leq . keep) (equal . keep1) (neq . lessp) (geq . equal
) (greaterp . drop)) (equal (lessp . drop) (leq . keep2) (equal . keep) (neq . drop) (geq . keep2) (greaterp . drop)) (neq (lessp . keep1) (leq . lessp) (equal . drop) (neq . keep) (geq . greaterp) (g
reaterp . keep1)) (geq (lessp . drop) (leq . equal) (equal . keep1) (neq . greaterp) (geq . keep) (greaterp . keep1)) (greaterp (lessp . drop) (leq . drop) (equal . drop) (neq . keep2) (geq . keep2) (
greaterp . keep))) */
    v66 = Latsoc(nil, v66, v70);
    v66 = qcdr(v66);
    v66 = Latsoc(nil, v123, v66);
    v66 = qcdr(v66);
    return onevalue(v66);
}



/* Code for csymbolrd */

static Lisp_Object MS_CDECL CC_csymbolrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v65, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "csymbolrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for csymbolrd");
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
    fn = elt(env, 2); /* fnrd */
    v126 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    stack[0] = v126;
    fn = elt(env, 3); /* stats_getargs */
    v126 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    v65 = v126;
    v126 = stack[0];
    v66 = qvalue(elt(env, 1)); /* nil */
    popv(2);
    return list2star(v126, v66, v65);
/* error exit handlers */
v70:
    popv(2);
    return nil;
}



/* Code for operator */

static Lisp_Object CC_operator(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for operator");
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
    v104 = v0;
/* end of prologue */
    stack[0] = v104;
    goto v20;

v20:
    v104 = stack[0];
    if (v104 == nil) goto v43;
    v104 = stack[0];
    v104 = qcar(v104);
    fn = elt(env, 2); /* mkop */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-1];
    v104 = stack[0];
    v104 = qcdr(v104);
    stack[0] = v104;
    goto v20;

v43:
    v104 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v104); }
/* error exit handlers */
v126:
    popv(2);
    return nil;
}



/* Code for sroot1 */

static Lisp_Object CC_sroot1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v191, v225, v226;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sroot1");
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
    stack[0] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* freevars */
    qvalue(elt(env, 1)) = nil; /* freevars */
    stack[-1] = qvalue(elt(env, 2)); /* substitution */
    qvalue(elt(env, 2)) = nil; /* substitution */
    v191 = qvalue(elt(env, 3)); /* rpt */
    v32 = elt(env, 4); /* inf */
    if (v191 == v32) goto v124;
    v191 = qvalue(elt(env, 3)); /* rpt */
    v32 = (Lisp_Object)1; /* 0 */
    v32 = (Lisp_Object)lesseq2(v191, v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    v32 = v32 ? lisp_true : nil;
    env = stack[-5];
    goto v81;

v81:
    if (!(v32 == nil)) goto v16;
    v32 = stack[-3];
    if (!consp(v32)) goto v115;
    v32 = stack[-3];
    v191 = qcar(v32);
    v32 = stack[0];
    v32 = qcdr(v32);
    v32 = qcar(v32);
    v32 = qcar(v32);
    v32 = Lneq(nil, v191, v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    goto v136;

v136:
    if (!(v32 == nil)) goto v16;
    v32 = stack[0];
    v32 = qcdr(v32);
    v32 = qcar(v32);
    fn = elt(env, 12); /* findnewvars */
    v191 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    v32 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 13); /* union */
    v32 = (*qfn2(fn))(qenv(fn), v191, v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    qvalue(elt(env, 1)) = v32; /* freevars */
    v32 = stack[0];
    v32 = qcdr(v32);
    v32 = qcdr(v32);
    v32 = qcar(v32);
    qvalue(elt(env, 2)) = v32; /* substitution */
    v32 = qvalue(elt(env, 1)); /* freevars */
    stack[-4] = v32;
    goto v59;

v59:
    v32 = stack[-4];
    if (v32 == nil) goto v96;
    v32 = stack[-4];
    v32 = qcar(v32);
    fn = elt(env, 14); /* newenv */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    v32 = stack[-4];
    v32 = qcdr(v32);
    stack[-4] = v32;
    goto v59;

v96:
    v32 = qvalue(elt(env, 7)); /* !*trpm */
    if (v32 == nil) goto v163;
    v32 = elt(env, 8); /* "Trying rule  " */
    v32 = Lprinc(nil, v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    v32 = stack[0];
    fn = elt(env, 15); /* rprint */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    v32 = elt(env, 9); /* "against      " */
    v32 = Lprinc(nil, v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    v32 = stack[-3];
    fn = elt(env, 15); /* rprint */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    goto v163;

v163:
    v32 = stack[0];
    v32 = qcdr(v32);
    v226 = qcar(v32);
    v225 = stack[-3];
    v191 = qvalue(elt(env, 6)); /* t */
    v32 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 16); /* amatch */
    v32 = (*qfnn(fn))(qenv(fn), 4, v226, v225, v191, v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    stack[-4] = v32;
    v32 = qvalue(elt(env, 7)); /* !*trpm */
    if (v32 == nil) goto v176;
    v32 = stack[-4];
    if (v32 == nil) goto v187;
    v32 = elt(env, 10); /* "producing    " */
    v32 = Lprinc(nil, v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    v32 = stack[-4];
    fn = elt(env, 17); /* embed!-null!-fn */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    stack[-4] = v32;
    fn = elt(env, 15); /* rprint */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    goto v46;

v46:
    v32 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    goto v176;

v176:
    v32 = qvalue(elt(env, 1)); /* freevars */
    stack[0] = v32;
    goto v160;

v160:
    v32 = stack[0];
    if (v32 == nil) goto v227;
    v32 = stack[0];
    v32 = qcar(v32);
    fn = elt(env, 18); /* restorenv */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    v32 = stack[0];
    v32 = qcdr(v32);
    stack[0] = v32;
    goto v160;

v227:
    v32 = stack[-4];
    if (v32 == nil) goto v188;
    v191 = qvalue(elt(env, 3)); /* rpt */
    v32 = elt(env, 4); /* inf */
    if (v191 == v32) goto v36;
    v32 = qvalue(elt(env, 3)); /* rpt */
    v32 = sub1(v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    qvalue(elt(env, 3)) = v32; /* rpt */
    goto v36;

v36:
    v32 = stack[-4];
    fn = elt(env, 17); /* embed!-null!-fn */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    goto v25;

v25:
    qvalue(elt(env, 2)) = stack[-1]; /* substitution */
    qvalue(elt(env, 1)) = stack[-2]; /* freevars */
    { popv(6); return onevalue(v32); }

v188:
    v32 = stack[-3];
    goto v25;

v187:
    v32 = elt(env, 11); /* "failed" */
    v32 = Lprinc(nil, v32);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    v32 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-5];
    goto v46;

v16:
    v32 = stack[-3];
    goto v25;

v115:
    v32 = qvalue(elt(env, 6)); /* t */
    goto v136;

v124:
    v32 = qvalue(elt(env, 5)); /* nil */
    goto v81;
/* error exit handlers */
v29:
    env = stack[-5];
    qvalue(elt(env, 2)) = stack[-1]; /* substitution */
    qvalue(elt(env, 1)) = stack[-2]; /* freevars */
    popv(6);
    return nil;
}



/* Code for ratnump */

static Lisp_Object CC_ratnump(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v178;
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
    v108 = v0;
/* end of prologue */
    fn = elt(env, 2); /* simp!* */
    v178 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[0];
    v108 = v178;
    v178 = qcar(v178);
    if (!consp(v178)) goto v26;
    v108 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v108); }

v26:
    v108 = qcdr(v108);
    v108 = (consp(v108) ? nil : lisp_true);
    { popv(1); return onevalue(v108); }
/* error exit handlers */
v166:
    popv(1);
    return nil;
}



/* Code for remove_least_item */

static Lisp_Object CC_remove_least_item(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remove_least_item");
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
    v62 = v0;
/* end of prologue */

v26:
    v127 = v62;
    v127 = qcdr(v127);
    if (v127 == nil) goto v25;
    v127 = v62;
    v127 = qcdr(v127);
    v127 = qcar(v127);
    v127 = qcdr(v127);
    if (v127 == nil) goto v112;
    v62 = qcdr(v62);
    v62 = qcar(v62);
    goto v26;

v112:
    {
        popv(1);
        fn = elt(env, 3); /* remove_root_item */
        return (*qfn1(fn))(qenv(fn), v62);
    }

v25:
    v62 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v62 == nil)) goto v81;
    v62 = elt(env, 2); /* "How did we get here?" */
    fn = elt(env, 4); /* lprie */
    v62 = (*qfn1(fn))(qenv(fn), v62);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[0];
    goto v81;

v81:
    v62 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v137;
    v62 = nil;
    { popv(1); return onevalue(v62); }
/* error exit handlers */
v137:
    popv(1);
    return nil;
}



/* Code for defined_vertex */

static Lisp_Object CC_defined_vertex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for defined_vertex");
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

v20:
    v124 = stack[-1];
    if (v124 == nil) goto v44;
    v124 = stack[-1];
    v64 = qcar(v124);
    v124 = stack[0];
    fn = elt(env, 3); /* memq_edgelist */
    v124 = (*qfn2(fn))(qenv(fn), v64, v124);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-2];
    if (v124 == nil) goto v90;
    v124 = stack[-1];
    v124 = qcdr(v124);
    stack[-1] = v124;
    goto v20;

v90:
    v124 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v124); }

v44:
    v124 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v124); }
/* error exit handlers */
v137:
    popv(3);
    return nil;
}



/* Code for dp!=retimes */

static Lisp_Object CC_dpMretimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v98, v132;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=retimes");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v98 = v0;
/* end of prologue */

v43:
    v97 = v98;
    v132 = qcar(v97);
    v97 = (Lisp_Object)17; /* 1 */
    if (v132 == v97) goto v25;
    v97 = v98;
    v97 = qcdr(v97);
    if (v97 == nil) goto v131;
    v97 = elt(env, 1); /* times */
    return cons(v97, v98);

v131:
    v97 = v98;
    v97 = qcar(v97);
    return onevalue(v97);

v25:
    v97 = v98;
    v97 = qcdr(v97);
    if (v97 == nil) goto v123;
    v97 = v98;
    v97 = qcdr(v97);
    v98 = v97;
    goto v43;

v123:
    v97 = (Lisp_Object)17; /* 1 */
    return onevalue(v97);
}



/* Code for algebnp */

static Lisp_Object CC_algebnp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v132;
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

v156:
    v98 = stack[0];
    if (!consp(v98)) goto v26;
    v98 = stack[0];
    v132 = qcar(v98);
    v98 = elt(env, 2); /* !:ar!: */
    if (v132 == v98) goto v44;
    v98 = stack[0];
    if (!consp(v98)) goto v65;
    v98 = stack[0];
    v98 = qcar(v98);
    v98 = (consp(v98) ? nil : lisp_true);
    goto v126;

v126:
    if (v98 == nil) goto v64;
    v98 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v98); }

v64:
    v98 = stack[0];
    v98 = qcar(v98);
    v98 = qcdr(v98);
    v98 = CC_algebnp(env, v98);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-1];
    if (!(v98 == nil)) { popv(2); return onevalue(v98); }
    v98 = stack[0];
    v98 = qcdr(v98);
    stack[0] = v98;
    goto v156;

v65:
    v98 = qvalue(elt(env, 3)); /* t */
    goto v126;

v44:
    v98 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v98); }

v26:
    v98 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v98); }
/* error exit handlers */
v133:
    popv(2);
    return nil;
}



/* Code for movebds */

static Lisp_Object MS_CDECL CC_movebds(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v113, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "movebds");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for movebds");
#endif
    if (stack >= stacklimit)
    {
        push3(v113,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v113);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v113;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v110 = qvalue(elt(env, 1)); /* !*intp */
    v63 = stack[-1];
    fn = elt(env, 2); /* sgn1 */
    v110 = (*qfn2(fn))(qenv(fn), v110, v63);
    nil = C_nil;
    if (exception_pending()) goto v98;
    v63 = stack[0];
    if (equal(v110, v63)) goto v65;
    v110 = stack[-2];
    v63 = stack[-1];
        popv(3);
        return Lrplaca(nil, v110, v63);

v65:
    v110 = stack[-2];
    v63 = stack[-1];
        popv(3);
        return Lrplacd(nil, v110, v63);
/* error exit handlers */
v98:
    popv(3);
    return nil;
}



/* Code for gd_newtype */

static Lisp_Object CC_gd_newtype(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v141, v56, v134;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gd_newtype");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v56 = v1;
    v134 = v0;
/* end of prologue */
    v141 = v134;
    v129 = v56;
    if (v141 == v129) return onevalue(v134);
    v141 = v134;
    v129 = elt(env, 1); /* gec */
    if (v141 == v129) goto v131;
    v141 = v134;
    v129 = elt(env, 2); /* geg */
    if (v141 == v129) return onevalue(v56);
    v141 = v56;
    v129 = elt(env, 1); /* gec */
    if (v141 == v129) goto v151;
    v129 = elt(env, 4); /* ger */
    return onevalue(v129);

v151:
    v129 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v129);

v131:
    v141 = v56;
    v129 = elt(env, 2); /* geg */
    if (v141 == v129) goto v70;
    v129 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v129);

v70:
    v129 = elt(env, 1); /* gec */
    return onevalue(v129);
}



/* Code for addexptsdf */

static Lisp_Object CC_addexptsdf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addexptsdf");
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
    goto v31;

v31:
    v134 = stack[-1];
    if (v134 == nil) goto v43;
    v134 = stack[0];
    if (v134 == nil) goto v62;
    v134 = stack[-1];
    v94 = qcar(v134);
    v134 = stack[0];
    v134 = qcar(v134);
    fn = elt(env, 3); /* exptplus */
    v94 = (*qfn2(fn))(qenv(fn), v94, v134);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    v134 = stack[-2];
    v134 = cons(v94, v134);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    stack[-2] = v134;
    v134 = stack[-1];
    v134 = qcdr(v134);
    stack[-1] = v134;
    v134 = stack[0];
    v134 = qcdr(v134);
    stack[0] = v134;
    goto v31;

v62:
    stack[0] = stack[-2];
    v134 = elt(env, 2); /* "Y too long" */
    fn = elt(env, 4); /* interr */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    {
        Lisp_Object v125 = stack[0];
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v125, v134);
    }

v43:
    v134 = stack[0];
    if (v134 == nil) goto v81;
    stack[0] = stack[-2];
    v134 = elt(env, 1); /* "X too long" */
    fn = elt(env, 4); /* interr */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    {
        Lisp_Object v58 = stack[0];
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v58, v134);
    }

v81:
    v134 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v134);
    }
/* error exit handlers */
v135:
    popv(4);
    return nil;
}



/* Code for min2!-order */

static Lisp_Object MS_CDECL CC_min2Korder(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v113, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "min2-order");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for min2-order");
#endif
    if (stack >= stacklimit)
    {
        push3(v113,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v113);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v113;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    goto v25;

v25:
    v140 = stack[-3];
    if (v140 == nil) goto v16;
    v140 = stack[-1];
    v140 = qcar(v140);
    stack[0] = v140;
    v140 = (Lisp_Object)1; /* 0 */
    v53 = v140;
    goto v117;

v117:
    v140 = stack[0];
    if (v140 == nil) goto v64;
    v140 = stack[0];
    v140 = qcar(v140);
    fn = elt(env, 1); /* tayexp!-plus2 */
    v140 = (*qfn2(fn))(qenv(fn), v140, v53);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-5];
    v53 = v140;
    v140 = stack[0];
    v140 = qcdr(v140);
    stack[0] = v140;
    goto v117;

v64:
    v140 = v53;
    stack[0] = v140;
    v53 = stack[0];
    v140 = stack[-2];
    v140 = qcar(v140);
    fn = elt(env, 2); /* tayexp!-greaterp */
    v140 = (*qfn2(fn))(qenv(fn), v53, v140);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-5];
    if (v140 == nil) goto v95;
    v53 = stack[0];
    v140 = stack[-3];
    v140 = qcar(v140);
    fn = elt(env, 3); /* tayexp!-min2 */
    v140 = (*qfn2(fn))(qenv(fn), v53, v140);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-5];
    v53 = v140;
    goto v104;

v104:
    v140 = stack[-4];
    v140 = cons(v53, v140);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-5];
    stack[-4] = v140;
    v140 = stack[-3];
    v140 = qcdr(v140);
    stack[-3] = v140;
    v140 = stack[-2];
    v140 = qcdr(v140);
    stack[-2] = v140;
    v140 = stack[-1];
    v140 = qcdr(v140);
    stack[-1] = v140;
    goto v25;

v95:
    v140 = stack[-3];
    v140 = qcar(v140);
    v53 = v140;
    goto v104;

v16:
    v140 = stack[-4];
    {
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v140);
    }
/* error exit handlers */
v89:
    popv(6);
    return nil;
}



/* Code for depend!-l */

static Lisp_Object CC_dependKl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for depend-l");
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

v20:
    v90 = stack[-1];
    if (v90 == nil) goto v44;
    v90 = stack[-1];
    v90 = qcar(v90);
    fn = elt(env, 3); /* simp */
    v114 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v90 = stack[0];
    fn = elt(env, 4); /* depend!-sq */
    v90 = (*qfn2(fn))(qenv(fn), v114, v90);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    if (v90 == nil) goto v123;
    v90 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v90); }

v123:
    v90 = stack[-1];
    v90 = qcdr(v90);
    stack[-1] = v90;
    goto v20;

v44:
    v90 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v90); }
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for pasf_ordatp */

static Lisp_Object CC_pasf_ordatp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v229, v164, v224, v87, v88, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_ordatp");
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
    v87 = v1;
    v88 = v0;
/* end of prologue */
    v229 = v88;
    v229 = qcdr(v229);
    v229 = qcar(v229);
    v86 = v229;
    v229 = v87;
    v229 = qcdr(v229);
    v229 = qcar(v229);
    v224 = v229;
    v164 = v86;
    v229 = v224;
    if (equal(v164, v229)) goto v132;
    v229 = v86;
    v164 = v224;
    {
        popv(1);
        fn = elt(env, 4); /* ordp */
        return (*qfn2(fn))(qenv(fn), v229, v164);
    }

v132:
    v164 = v88;
    v229 = elt(env, 1); /* true */
    if (v164 == v229) goto v97;
    v164 = v88;
    v229 = elt(env, 3); /* false */
    v229 = (v164 == v229 ? lisp_true : nil);
    goto v71;

v71:
    if (v229 == nil) goto v110;
    v229 = v88;
    v224 = v229;
    goto v53;

v53:
    v164 = v87;
    v229 = elt(env, 1); /* true */
    if (v164 == v229) goto v106;
    v164 = v87;
    v229 = elt(env, 3); /* false */
    v229 = (v164 == v229 ? lisp_true : nil);
    goto v230;

v230:
    if (v229 == nil) goto v185;
    v229 = v87;
    goto v137;

v137:
    {
        popv(1);
        fn = elt(env, 5); /* pasf_ordrelp */
        return (*qfn2(fn))(qenv(fn), v224, v229);
    }

v185:
    v229 = v87;
    v229 = qcar(v229);
    v229 = Lconsp(nil, v229);
    env = stack[0];
    if (v229 == nil) goto v146;
    v229 = v87;
    v229 = qcar(v229);
    v229 = qcar(v229);
    goto v137;

v146:
    v229 = v87;
    v229 = qcar(v229);
    goto v137;

v106:
    v229 = qvalue(elt(env, 2)); /* t */
    goto v230;

v110:
    v229 = v88;
    v229 = qcar(v229);
    v229 = Lconsp(nil, v229);
    env = stack[0];
    if (v229 == nil) goto v95;
    v229 = v88;
    v229 = qcar(v229);
    v229 = qcar(v229);
    v224 = v229;
    goto v53;

v95:
    v229 = v88;
    v229 = qcar(v229);
    v224 = v229;
    goto v53;

v97:
    v229 = qvalue(elt(env, 2)); /* t */
    goto v71;
}



/* Code for aex_minus */

static Lisp_Object CC_aex_minus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_minus");
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
    v98 = stack[-3];
    fn = elt(env, 2); /* aex_ex */
    stack[0] = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    v98 = stack[-2];
    fn = elt(env, 2); /* aex_ex */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    fn = elt(env, 3); /* ratpoly_minus */
    stack[-4] = (*qfn2(fn))(qenv(fn), stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    v98 = stack[-3];
    fn = elt(env, 4); /* aex_ctx */
    stack[0] = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    v98 = stack[-2];
    fn = elt(env, 4); /* aex_ctx */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    fn = elt(env, 5); /* ctx_union */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v98 = stack[-3];
    fn = elt(env, 6); /* aex_reducedtag */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    if (v98 == nil) goto v137;
    v98 = stack[-2];
    fn = elt(env, 6); /* aex_reducedtag */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    goto v75;

v75:
    {
        Lisp_Object v61 = stack[-4];
        Lisp_Object v60 = stack[-1];
        Lisp_Object v169 = stack[0];
        popv(6);
        fn = elt(env, 7); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v61, v60, v169, v98);
    }

v137:
    v98 = qvalue(elt(env, 1)); /* nil */
    goto v75;
/* error exit handlers */
v119:
    popv(6);
    return nil;
}



/* Code for dip_condense */

static Lisp_Object CC_dip_condense(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v27;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip_condense");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v27 = v0;
/* end of prologue */
    return onevalue(v27);
}



/* Code for integralir */

static Lisp_Object MS_CDECL CC_integralir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v230;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "integralir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for integralir");
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
    v230 = qvalue(elt(env, 1)); /* atts */
    v109 = elt(env, 2); /* name */
    fn = elt(env, 7); /* find */
    v109 = (*qfn2(fn))(qenv(fn), v230, v109);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    v109 = Lintern(nil, v109);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    stack[-1] = v109;
    v109 = elt(env, 3); /* (bvar x 1) */
    v109 = ncons(v109);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    stack[0] = v109;
    v230 = stack[-1];
    v109 = elt(env, 5); /* defint */
    if (!(v230 == v109)) goto v104;
    fn = elt(env, 8); /* lex */
    v109 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    fn = elt(env, 9); /* omobj */
    v109 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    goto v104;

v104:
    fn = elt(env, 8); /* lex */
    v109 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    fn = elt(env, 9); /* omobj */
    v109 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    stack[-2] = v109;
    v109 = stack[-2];
    v109 = Lconsp(nil, v109);
    env = stack[-3];
    if (v109 == nil) goto v134;
    v109 = stack[-2];
    v230 = qcar(v109);
    v109 = elt(env, 6); /* lambda */
    if (!(v230 == v109)) goto v134;
    v109 = stack[-2];
    fn = elt(env, 10); /* lambdavar */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    stack[0] = v109;
    v109 = stack[-2];
    fn = elt(env, 11); /* lambdafun */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    stack[-2] = v109;
    goto v134;

v134:
    v230 = stack[-1];
    v109 = qvalue(elt(env, 4)); /* nil */
    stack[-1] = list2(v230, v109);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    v109 = stack[-2];
    v109 = ncons(v109);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    v109 = Lappend(nil, stack[0], v109);
    nil = C_nil;
    if (exception_pending()) goto v51;
    {
        Lisp_Object v232 = stack[-1];
        popv(4);
        return Lappend(nil, v232, v109);
    }
/* error exit handlers */
v51:
    popv(4);
    return nil;
}



/* Code for crnprimp */

static Lisp_Object CC_crnprimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v48, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crnprimp");
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
    v47 = stack[0];
    v47 = qcdr(v47);
    v48 = qcar(v47);
    v47 = (Lisp_Object)17; /* 1 */
    if (v48 == v47) goto v105;
    v47 = qvalue(elt(env, 1)); /* nil */
    goto v25;

v25:
    if (v47 == nil) goto v137;
    v47 = elt(env, 2); /* i */
    { popv(3); return onevalue(v47); }

v137:
    v47 = stack[0];
    stack[-1] = qcar(v47);
    v47 = stack[0];
    v47 = qcdr(v47);
    v47 = qcar(v47);
    fn = elt(env, 5); /* !:minus */
    v48 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-2];
    v47 = stack[0];
    v47 = qcdr(v47);
    v47 = qcdr(v47);
    v47 = list2star(stack[-1], v48, v47);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-2];
    v148 = v47;
    v47 = v148;
    v47 = qcdr(v47);
    v48 = qcar(v47);
    v47 = (Lisp_Object)17; /* 1 */
    if (v48 == v47) goto v94;
    v47 = qvalue(elt(env, 1)); /* nil */
    goto v169;

v169:
    if (v47 == nil) goto v170;
    v47 = elt(env, 3); /* minus */
    v48 = elt(env, 2); /* i */
    popv(3);
    return list2(v47, v48);

v170:
    stack[-1] = elt(env, 4); /* times */
    v47 = stack[0];
    fn = elt(env, 6); /* rnprep!: */
    v47 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-2];
    v48 = elt(env, 2); /* i */
    {
        Lisp_Object v171 = stack[-1];
        popv(3);
        return list3(v171, v47, v48);
    }

v94:
    v47 = v148;
    v47 = qcdr(v47);
    v48 = qcdr(v47);
    v47 = (Lisp_Object)17; /* 1 */
    v47 = (v48 == v47 ? lisp_true : nil);
    goto v169;

v105:
    v47 = stack[0];
    v47 = qcdr(v47);
    v48 = qcdr(v47);
    v47 = (Lisp_Object)17; /* 1 */
    v47 = (v48 == v47 ? lisp_true : nil);
    goto v25;
/* error exit handlers */
v163:
    popv(3);
    return nil;
}



/* Code for arprep!: */

static Lisp_Object CC_arprepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v178;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arprep:");
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
    v178 = v0;
/* end of prologue */
    v108 = qvalue(elt(env, 1)); /* !*reexpress */
    if (v108 == nil) goto v75;
    v108 = v178;
    v108 = qcdr(v108);
    fn = elt(env, 2); /* express!-in!-arvars */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[0];
    goto v26;

v26:
    {
        popv(1);
        fn = elt(env, 3); /* prepf */
        return (*qfn1(fn))(qenv(fn), v108);
    }

v75:
    v108 = v178;
    v108 = qcdr(v108);
    goto v26;
/* error exit handlers */
v166:
    popv(1);
    return nil;
}



/* Code for make_spoly_pair */

static Lisp_Object CC_make_spoly_pair(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v203, v228, v47, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make_spoly_pair");
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

v138:
    v228 = stack[-2];
    v203 = stack[-3];
    fn = elt(env, 3); /* pfordp */
    v203 = (*qfn2(fn))(qenv(fn), v228, v203);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    if (v203 == nil) goto v123;
    v203 = stack[-2];
    v228 = v203;
    v203 = stack[-3];
    stack[-2] = v203;
    v203 = v228;
    stack[-3] = v203;
    goto v138;

v123:
    v203 = stack[-3];
    fn = elt(env, 4); /* xval */
    stack[0] = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    v203 = stack[-2];
    fn = elt(env, 4); /* xval */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    fn = elt(env, 5); /* xlcm */
    v203 = (*qfn2(fn))(qenv(fn), stack[0], v203);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    stack[-4] = v203;
    v203 = stack[-3];
    v203 = qcdr(v203);
    if (!(v203 == nil)) goto v120;
    v203 = stack[-2];
    v203 = qcdr(v203);
    if (!(v203 == nil)) goto v120;
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v203); }

v120:
    stack[-1] = stack[-4];
    v203 = stack[-3];
    fn = elt(env, 4); /* xval */
    stack[0] = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    v203 = stack[-2];
    fn = elt(env, 4); /* xval */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    fn = elt(env, 6); /* triviallcm */
    v203 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v203);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    if (v203 == nil) goto v169;
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v203); }

v169:
    v203 = stack[-4];
    fn = elt(env, 7); /* mknwedge */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    fn = elt(env, 8); /* xdegreecheck */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-5];
    if (v203 == nil) goto v92;
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v203); }

v92:
    v47 = stack[-4];
    v48 = elt(env, 2); /* spoly_pair */
    v228 = stack[-3];
    v203 = stack[-2];
    popv(6);
    return list4(v47, v48, v228, v203);
/* error exit handlers */
v49:
    popv(6);
    return nil;
}



/* Code for evalsubset */

static Lisp_Object CC_evalsubset(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v70, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalsubset");
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
    v123 = v1;
    v70 = v0;
/* end of prologue */
    v117 = elt(env, 1); /* subset */
    fn = elt(env, 2); /* evalsetbool */
    v123 = (*qfnn(fn))(qenv(fn), 3, v117, v70, v123);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[0];
    v70 = v123;
    v123 = v70;
    if (!consp(v123)) { popv(1); return onevalue(v70); }
    v123 = v70;
    {
        popv(1);
        fn = elt(env, 3); /* evalsymsubset */
        return (*qfn1(fn))(qenv(fn), v123);
    }
/* error exit handlers */
v131:
    popv(1);
    return nil;
}



setup_type const u38_setup[] =
{
    {"difbf",                   too_few_2,      CC_difbf,      wrong_no_2},
    {"repartf",                 CC_repartf,     too_many_1,    wrong_no_1},
    {"ev_mtest?",               too_few_2,      CC_ev_mtestW,  wrong_no_2},
    {"pdiffvars",               too_few_2,      CC_pdiffvars,  wrong_no_2},
    {"varsinsf",                too_few_2,      CC_varsinsf,   wrong_no_2},
    {"column_dim",              CC_column_dim,  too_many_1,    wrong_no_1},
    {"vdpsimpcont",             CC_vdpsimpcont, too_many_1,    wrong_no_1},
    {"dim<=deg",                CC_dimRMdeg,    too_many_1,    wrong_no_1},
    {"rassoc",                  too_few_2,      CC_rassoc,     wrong_no_2},
    {"strand-alg-top",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_strandKalgKtop},
    {"reduce-weights",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_reduceKweights},
    {"fs:timescoeff",           too_few_2,      CC_fsTtimescoeff,wrong_no_2},
    {"addnew",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_addnew},
    {"*q2f",                    CC_Hq2f,        too_many_1,    wrong_no_1},
    {"conjgd",                  CC_conjgd,      too_many_1,    wrong_no_1},
    {"mri_opn",                 CC_mri_opn,     too_many_1,    wrong_no_1},
    {"pasf_anegateat",          CC_pasf_anegateat,too_many_1,  wrong_no_1},
    {"bc_minus?",               CC_bc_minusW,   too_many_1,    wrong_no_1},
    {"vdp_getprop",             too_few_2,      CC_vdp_getprop,wrong_no_2},
    {"lowupperlimitml",         CC_lowupperlimitml,too_many_1, wrong_no_1},
    {"ps:term-rthpow",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_psTtermKrthpow},
    {"greatertype",             too_few_2,      CC_greatertype,wrong_no_2},
    {"sfpf",                    CC_sfpf,        too_many_1,    wrong_no_1},
    {"dipnumcontent",           too_few_2,      CC_dipnumcontent,wrong_no_2},
    {"groebsaveltermbc",        CC_groebsaveltermbc,too_many_1,wrong_no_1},
    {"xpartitk",                CC_xpartitk,    too_many_1,    wrong_no_1},
    {"delasc",                  too_few_2,      CC_delasc,     wrong_no_2},
    {"indordlp",                too_few_2,      CC_indordlp,   wrong_no_2},
    {"s_noparents",             CC_s_noparents, too_many_1,    wrong_no_1},
    {"*hfac",                   CC_Hhfac,       too_many_1,    wrong_no_1},
    {"mod/",                    too_few_2,      CC_modV,       wrong_no_2},
    {"cl_nnfnot",               CC_cl_nnfnot,   too_many_1,    wrong_no_1},
    {"addfactors",              too_few_2,      CC_addfactors, wrong_no_2},
    {"ofsf_simplequal",         too_few_2,      CC_ofsf_simplequal,wrong_no_2},
    {"factorf",                 CC_factorf,     too_many_1,    wrong_no_1},
    {"acfsf_0mk2",              too_few_2,      CC_acfsf_0mk2, wrong_no_2},
    {"quotientml",              CC_quotientml,  too_many_1,    wrong_no_1},
    {"is_buble",                too_few_2,      CC_is_buble,   wrong_no_2},
    {"groeb=testc1",            CC_groebMtestc1,too_many_1,    wrong_no_1},
    {"checkcoeffts",            too_few_2,      CC_checkcoeffts,wrong_no_2},
    {"pasf_dnf",                CC_pasf_dnf,    too_many_1,    wrong_no_1},
    {"bra_mk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_bra_mk},
    {"ofsf_sacrel-and",         too_few_2,      CC_ofsf_sacrelKand,wrong_no_2},
    {"csymbolrd",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_csymbolrd},
    {"operator",                CC_operator,    too_many_1,    wrong_no_1},
    {"sroot1",                  too_few_2,      CC_sroot1,     wrong_no_2},
    {"ratnump",                 CC_ratnump,     too_many_1,    wrong_no_1},
    {"remove_least_item",       CC_remove_least_item,too_many_1,wrong_no_1},
    {"defined_vertex",          too_few_2,      CC_defined_vertex,wrong_no_2},
    {"dp=retimes",              CC_dpMretimes,  too_many_1,    wrong_no_1},
    {"algebnp",                 CC_algebnp,     too_many_1,    wrong_no_1},
    {"movebds",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_movebds},
    {"gd_newtype",              too_few_2,      CC_gd_newtype, wrong_no_2},
    {"addexptsdf",              too_few_2,      CC_addexptsdf, wrong_no_2},
    {"min2-order",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_min2Korder},
    {"depend-l",                too_few_2,      CC_dependKl,   wrong_no_2},
    {"pasf_ordatp",             too_few_2,      CC_pasf_ordatp,wrong_no_2},
    {"aex_minus",               too_few_2,      CC_aex_minus,  wrong_no_2},
    {"dip_condense",            CC_dip_condense,too_many_1,    wrong_no_1},
    {"integralir",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_integralir},
    {"crnprimp",                CC_crnprimp,    too_many_1,    wrong_no_1},
    {"arprep:",                 CC_arprepT,     too_many_1,    wrong_no_1},
    {"make_spoly_pair",         too_few_2,      CC_make_spoly_pair,wrong_no_2},
    {"evalsubset",              too_few_2,      CC_evalsubset, wrong_no_2},
    {NULL, (one_args *)"u38", (two_args *)"4792 9769899 5014339", 0}
};

/* end of generated code */
