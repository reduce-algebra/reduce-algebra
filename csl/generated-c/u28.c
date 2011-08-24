
/* $destdir\u28.c        Machine generated C code */

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


/* Code for polynomread */

static Lisp_Object CC_polynomread(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v22, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomread");
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
    v21 = stack[0];
    if (v21 == nil) goto v24;
    v21 = stack[0];
    if (!consp(v21)) goto v25;
    v21 = stack[0];
    v21 = qcar(v21);
    v21 = (consp(v21) ? nil : lisp_true);
    goto v26;

v26:
    if (v21 == nil) goto v27;
    v22 = stack[0];
    v21 = (Lisp_Object)33; /* 2 */
    v22 = Cremainder(v22, v21);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    v21 = (Lisp_Object)17; /* 1 */
    v21 = Leqn(nil, v22, v21);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    if (v21 == nil) goto v29;
    fn = elt(env, 5); /* createmonomunit */
    v22 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    v21 = qvalue(elt(env, 1)); /* nil */
    v23 = qvalue(elt(env, 1)); /* nil */
    popv(3);
    return list2star(v22, v21, v23);

v29:
    v21 = qvalue(elt(env, 1)); /* nil */
    popv(3);
    return ncons(v21);

v27:
    v21 = stack[0];
    v21 = qcar(v21);
    v21 = qcar(v21);
    v22 = qcar(v21);
    v21 = qvalue(elt(env, 3)); /* fluidbibasisvariables */
    v21 = Lmember(nil, v22, v21);
    if (v21 == nil) goto v30;
    v21 = stack[0];
    v21 = qcar(v21);
    v21 = qcdr(v21);
    v23 = CC_polynomread(env, v21);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    v21 = stack[0];
    v21 = qcar(v21);
    v21 = qcar(v21);
    v22 = qcar(v21);
    v21 = qvalue(elt(env, 4)); /* fluidbibasissinglevariablemonomialsa 
*/
    v21 = Lassoc(nil, v22, v21);
    v21 = qcdr(v21);
    fn = elt(env, 6); /* polynommultiplybymonom */
    stack[-1] = (*qfn2(fn))(qenv(fn), v23, v21);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    v21 = stack[0];
    v21 = qcdr(v21);
    v21 = CC_polynomread(env, v21);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    {
        Lisp_Object v31 = stack[-1];
        popv(3);
        fn = elt(env, 7); /* polynomadd */
        return (*qfn2(fn))(qenv(fn), v31, v21);
    }

v30:
    v21 = stack[0];
    v21 = qcar(v21);
    v21 = qcdr(v21);
    stack[-1] = CC_polynomread(env, v21);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    fn = elt(env, 5); /* createmonomunit */
    v21 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    fn = elt(env, 6); /* polynommultiplybymonom */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v21);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    v21 = stack[0];
    v21 = qcdr(v21);
    v21 = CC_polynomread(env, v21);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    fn = elt(env, 7); /* polynomadd */
    v21 = (*qfn2(fn))(qenv(fn), stack[-1], v21);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    v21 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v21); }

v25:
    v21 = qvalue(elt(env, 2)); /* t */
    goto v26;

v24:
    v21 = qvalue(elt(env, 1)); /* nil */
    popv(3);
    return ncons(v21);
/* error exit handlers */
v28:
    popv(3);
    return nil;
}



/* Code for giintgcd */

static Lisp_Object CC_giintgcd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v44, v45, v7;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for giintgcd");
#endif
    if (stack >= stacklimit)
    {
        push2(v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v44 = v32;
    v45 = v0;
/* end of prologue */

v20:
    v7 = v44;
    v43 = (Lisp_Object)17; /* 1 */
    if (v7 == v43) goto v46;
    v43 = v45;
    if (v43 == nil) { popv(2); return onevalue(v44); }
    v43 = v45;
    if (!consp(v43)) goto v47;
    v7 = v45;
    v43 = elt(env, 1); /* !:gi!: */
    if (!consp(v7)) goto v48;
    v7 = qcar(v7);
    if (!(v7 == v43)) goto v48;
    v43 = v45;
    v43 = qcdr(v43);
    stack[0] = qcar(v43);
    v43 = v45;
    v43 = qcdr(v43);
    v43 = qcdr(v43);
    v43 = Lgcd(nil, v43, v44);
    nil = C_nil;
    if (exception_pending()) goto v49;
    {
        Lisp_Object v50 = stack[0];
        popv(2);
        return Lgcd(nil, v50, v43);
    }

v48:
    v43 = v45;
    v43 = qcar(v43);
    v43 = qcdr(v43);
    stack[0] = v43;
    v43 = v45;
    v43 = qcdr(v43);
    v43 = CC_giintgcd(env, v43, v44);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-1];
    v44 = v43;
    v43 = stack[0];
    v45 = v43;
    goto v20;

v47:
    v43 = v45;
        popv(2);
        return Lgcd(nil, v43, v44);

v46:
    v43 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v43); }
/* error exit handlers */
v49:
    popv(2);
    return nil;
}



/* Code for makecoeffpairshom */

static Lisp_Object MS_CDECL CC_makecoeffpairshom(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v32,
                         Lisp_Object v51, Lisp_Object v42, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v119, v120, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "makecoeffpairshom");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makecoeffpairshom");
#endif
    if (stack >= stacklimit)
    {
        push4(v42,v51,v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v32,v51,v42);
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
    stack[-11] = v42;
    stack[-12] = v51;
    stack[-13] = v32;
    stack[-14] = v0;
/* end of prologue */
    v118 = stack[-12];
    if (v118 == nil) goto v122;
    v118 = stack[-13];
    v118 = qcar(v118);
    stack[-15] = v118;
    goto v123;

v123:
    stack[0] = stack[-11];
    v118 = stack[-14];
    v119 = qcar(v118);
    v118 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v118 = (*qfn2(fn))(qenv(fn), v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    fn = elt(env, 4); /* tayexp!-times2 */
    v118 = (*qfn2(fn))(qenv(fn), stack[0], v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    fn = elt(env, 5); /* tayexp!-minusp */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    if (v118 == nil) goto v15;
    v118 = qvalue(elt(env, 2)); /* nil */
    { popv(17); return onevalue(v118); }

v15:
    v118 = stack[-14];
    v121 = qcdr(v118);
    v118 = stack[-13];
    v120 = qcdr(v118);
    v118 = stack[-12];
    v119 = qcdr(v118);
    v118 = stack[-11];
    v118 = CC_makecoeffpairshom(env, 4, v121, v120, v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    stack[-7] = v118;
    v118 = stack[-7];
    if (v118 == nil) goto v125;
    v118 = stack[-7];
    v118 = qcar(v118);
    stack[-3] = v118;
    stack[-2] = stack[-15];
    v118 = stack[-3];
    stack[-1] = qcar(v118);
    v118 = stack[-13];
    stack[0] = qcar(v118);
    v118 = stack[-12];
    v119 = qcar(v118);
    v118 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v118 = (*qfn2(fn))(qenv(fn), v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v119 = (*qfn2(fn))(qenv(fn), stack[0], v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    v118 = stack[-3];
    v118 = qcdr(v118);
    v118 = cons(v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    v118 = acons(stack[-2], stack[-1], v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    v118 = ncons(v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    stack[-5] = v118;
    stack[-6] = v118;
    goto v14;

v14:
    v118 = stack[-7];
    v118 = qcdr(v118);
    stack[-7] = v118;
    v118 = stack[-7];
    if (v118 == nil) goto v126;
    stack[-4] = stack[-5];
    v118 = stack[-7];
    v118 = qcar(v118);
    stack[-3] = v118;
    stack[-2] = stack[-15];
    v118 = stack[-3];
    stack[-1] = qcar(v118);
    v118 = stack[-13];
    stack[0] = qcar(v118);
    v118 = stack[-12];
    v119 = qcar(v118);
    v118 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v118 = (*qfn2(fn))(qenv(fn), v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v119 = (*qfn2(fn))(qenv(fn), stack[0], v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    v118 = stack[-3];
    v118 = qcdr(v118);
    v118 = cons(v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    v118 = acons(stack[-2], stack[-1], v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    v118 = ncons(v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    v118 = Lrplacd(nil, stack[-4], v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    v118 = stack[-5];
    v118 = qcdr(v118);
    stack[-5] = v118;
    goto v14;

v126:
    v118 = stack[-6];
    goto v127;

v127:
    stack[-10] = v118;
    v118 = stack[-10];
    fn = elt(env, 7); /* lastpair */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    stack[-9] = v118;
    v119 = stack[-15];
    v118 = stack[-11];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v118 = (*qfn2(fn))(qenv(fn), v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    stack[-15] = v118;
    v118 = stack[-9];
    if (!consp(v118)) goto v123;
    else goto v128;

v128:
    stack[0] = stack[-11];
    v118 = stack[-14];
    v119 = qcar(v118);
    v118 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v118 = (*qfn2(fn))(qenv(fn), v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    fn = elt(env, 4); /* tayexp!-times2 */
    v118 = (*qfn2(fn))(qenv(fn), stack[0], v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    fn = elt(env, 5); /* tayexp!-minusp */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    if (!(v118 == nil)) { Lisp_Object res = stack[-10]; popv(17); return onevalue(res); }
    stack[-8] = stack[-9];
    v118 = stack[-14];
    v121 = qcdr(v118);
    v118 = stack[-13];
    v120 = qcdr(v118);
    v118 = stack[-12];
    v119 = qcdr(v118);
    v118 = stack[-11];
    v118 = CC_makecoeffpairshom(env, 4, v121, v120, v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    stack[-7] = v118;
    v118 = stack[-7];
    if (v118 == nil) goto v129;
    v118 = stack[-7];
    v118 = qcar(v118);
    stack[-3] = v118;
    stack[-2] = stack[-15];
    v118 = stack[-3];
    stack[-1] = qcar(v118);
    v118 = stack[-13];
    stack[0] = qcar(v118);
    v118 = stack[-12];
    v119 = qcar(v118);
    v118 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v118 = (*qfn2(fn))(qenv(fn), v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v119 = (*qfn2(fn))(qenv(fn), stack[0], v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    v118 = stack[-3];
    v118 = qcdr(v118);
    v118 = cons(v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    v118 = acons(stack[-2], stack[-1], v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    v118 = ncons(v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    stack[-5] = v118;
    stack[-6] = v118;
    goto v130;

v130:
    v118 = stack[-7];
    v118 = qcdr(v118);
    stack[-7] = v118;
    v118 = stack[-7];
    if (v118 == nil) goto v131;
    stack[-4] = stack[-5];
    v118 = stack[-7];
    v118 = qcar(v118);
    stack[-3] = v118;
    stack[-2] = stack[-15];
    v118 = stack[-3];
    stack[-1] = qcar(v118);
    v118 = stack[-13];
    stack[0] = qcar(v118);
    v118 = stack[-12];
    v119 = qcar(v118);
    v118 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v118 = (*qfn2(fn))(qenv(fn), v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v119 = (*qfn2(fn))(qenv(fn), stack[0], v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    v118 = stack[-3];
    v118 = qcdr(v118);
    v118 = cons(v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    v118 = acons(stack[-2], stack[-1], v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    v118 = ncons(v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    v118 = Lrplacd(nil, stack[-4], v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    v118 = stack[-5];
    v118 = qcdr(v118);
    stack[-5] = v118;
    goto v130;

v131:
    v118 = stack[-6];
    goto v132;

v132:
    v118 = Lrplacd(nil, stack[-8], v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    v118 = stack[-9];
    fn = elt(env, 7); /* lastpair */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    stack[-9] = v118;
    v119 = stack[-15];
    v118 = stack[-11];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v118 = (*qfn2(fn))(qenv(fn), v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-16];
    stack[-15] = v118;
    goto v128;

v129:
    v118 = qvalue(elt(env, 2)); /* nil */
    goto v132;

v125:
    v118 = qvalue(elt(env, 2)); /* nil */
    goto v127;

v122:
    v118 = elt(env, 1); /* ((nil)) */
    { popv(17); return onevalue(v118); }
/* error exit handlers */
v124:
    popv(17);
    return nil;
}



/* Code for ithlistelem */

static Lisp_Object CC_ithlistelem(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ithlistelem");
#endif
    if (stack >= stacklimit)
    {
        push2(v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v32;
    stack[-1] = v0;
/* end of prologue */
    v137 = stack[-1];
    if (v137 == nil) goto v139;
    v137 = stack[-1];
    v138 = qcar(v137);
    v137 = stack[0];
    fn = elt(env, 1); /* pnth */
    v137 = (*qfn2(fn))(qenv(fn), v138, v137);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-3];
    stack[-2] = qcar(v137);
    v137 = stack[-1];
    v138 = qcdr(v137);
    v137 = stack[0];
    v137 = CC_ithlistelem(env, v138, v137);
    nil = C_nil;
    if (exception_pending()) goto v17;
    {
        Lisp_Object v117 = stack[-2];
        popv(4);
        return cons(v117, v137);
    }

v139:
    v137 = nil;
    { popv(4); return onevalue(v137); }
/* error exit handlers */
v17:
    popv(4);
    return nil;
}



/* Code for testpr */

static Lisp_Object MS_CDECL CC_testpr(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v32,
                         Lisp_Object v51, Lisp_Object v42, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v101, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "testpr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testpr");
#endif
    if (stack >= stacklimit)
    {
        push4(v42,v51,v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v32,v51,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v42;
    stack[-6] = v51;
    stack[0] = v32;
    v155 = v0;
/* end of prologue */
    stack[-3] = nil;
    v101 = qvalue(elt(env, 1)); /* jsi */
    stack[-2] = v101;
    stack[-1] = qvalue(elt(env, 2)); /* codmat */
    v101 = qvalue(elt(env, 3)); /* maxvar */
    v155 = plus2(v101, v155);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-8];
    v101 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v155/(16/CELL)));
    v155 = (Lisp_Object)65; /* 4 */
    v155 = *(Lisp_Object *)((char *)v101 + (CELL-TAG_VECTOR) + ((int32_t)v155/(16/CELL)));
    stack[-7] = v155;
    stack[-1] = qvalue(elt(env, 2)); /* codmat */
    v101 = qvalue(elt(env, 3)); /* maxvar */
    v155 = stack[0];
    v155 = plus2(v101, v155);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-8];
    v101 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v155/(16/CELL)));
    v155 = (Lisp_Object)65; /* 4 */
    v155 = *(Lisp_Object *)((char *)v101 + (CELL-TAG_VECTOR) + ((int32_t)v155/(16/CELL)));
    stack[-4] = v155;
    goto v35;

v35:
    v155 = stack[-2];
    if (v155 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    v155 = stack[-7];
    if (v155 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    v155 = stack[-2];
    v101 = qcar(v155);
    stack[-1] = v101;
    v155 = stack[-7];
    v155 = qcar(v155);
    v155 = qcar(v155);
    v102 = v155;
    if (equal(v101, v155)) goto v157;
    v155 = stack[-1];
    v101 = v102;
    v155 = (Lisp_Object)greaterp2(v155, v101);
    nil = C_nil;
    if (exception_pending()) goto v156;
    v155 = v155 ? lisp_true : nil;
    env = stack[-8];
    if (v155 == nil) goto v158;
    v155 = stack[-7];
    v155 = qcdr(v155);
    stack[-7] = v155;
    goto v35;

v158:
    v155 = stack[-2];
    v155 = qcdr(v155);
    stack[-2] = v155;
    goto v35;

v157:
    v101 = stack[-1];
    v155 = stack[-4];
    fn = elt(env, 5); /* pnthxzz */
    v155 = (*qfn2(fn))(qenv(fn), v101, v155);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-8];
    stack[-4] = v155;
    v155 = stack[-7];
    v155 = qcar(v155);
    v155 = qcdr(v155);
    v101 = qcar(v155);
    v155 = stack[-5];
    fn = elt(env, 6); /* dm!-times */
    stack[0] = (*qfn2(fn))(qenv(fn), v101, v155);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-8];
    v155 = stack[-4];
    v155 = qcar(v155);
    v155 = qcdr(v155);
    v101 = qcar(v155);
    v155 = stack[-6];
    fn = elt(env, 6); /* dm!-times */
    v155 = (*qfn2(fn))(qenv(fn), v101, v155);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-8];
    fn = elt(env, 7); /* dm!-difference */
    v155 = (*qfn2(fn))(qenv(fn), stack[0], v155);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-8];
    fn = elt(env, 8); /* zeropp */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-8];
    if (v155 == nil) goto v10;
    v101 = stack[-1];
    v155 = stack[-3];
    v155 = cons(v101, v155);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-8];
    stack[-3] = v155;
    goto v10;

v10:
    v155 = stack[-2];
    v155 = qcdr(v155);
    stack[-2] = v155;
    v155 = stack[-7];
    v155 = qcdr(v155);
    stack[-7] = v155;
    goto v35;
/* error exit handlers */
v156:
    popv(9);
    return nil;
}



/* Code for dipcondense */

static Lisp_Object CC_dipcondense(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipcondense");
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
    stack[-2] = v0;
/* end of prologue */
    v148 = qvalue(elt(env, 1)); /* dipevlist!* */
    stack[-3] = v148;
    goto v46;

v46:
    v148 = stack[-2];
    if (v148 == nil) goto v160;
    v148 = stack[-2];
    v148 = qcar(v148);
    stack[-1] = v148;
    goto v161;

v161:
    v148 = stack[-3];
    v148 = qcdr(v148);
    if (v148 == nil) goto v162;
    v148 = stack[-2];
    v149 = qcar(v148);
    v148 = stack[-3];
    v148 = qcdr(v148);
    v148 = qcar(v148);
    fn = elt(env, 3); /* evcompless!? */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-4];
    if (v148 == nil) goto v162;
    v148 = stack[-3];
    v148 = qcdr(v148);
    stack[-3] = v148;
    goto v161;

v162:
    v148 = stack[-3];
    v148 = qcdr(v148);
    if (v148 == nil) goto v163;
    v149 = stack[-1];
    v148 = stack[-3];
    v148 = qcdr(v148);
    v148 = qcar(v148);
    if (!(equal(v149, v148))) goto v163;
    v149 = stack[-2];
    v148 = stack[-3];
    v148 = qcdr(v148);
    v148 = qcar(v148);
    fn = elt(env, 4); /* setcar */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-4];
    goto v105;

v105:
    v148 = stack[-2];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    stack[-2] = v148;
    goto v46;

v163:
    stack[0] = stack[-3];
    v149 = stack[-1];
    v148 = stack[-3];
    v148 = qcdr(v148);
    v148 = cons(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-4];
    fn = elt(env, 5); /* setcdr */
    v148 = (*qfn2(fn))(qenv(fn), stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-4];
    goto v105;

v160:
    v148 = nil;
    { popv(5); return onevalue(v148); }
/* error exit handlers */
v6:
    popv(5);
    return nil;
}



/* Code for size_of_matrix */

static Lisp_Object CC_size_of_matrix(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164, v165;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for size_of_matrix");
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
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v164 = stack[0];
    v164 = Llength(nil, v164);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    v164 = plus2(stack[-1], v164);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    stack[-1] = v164;
    v164 = stack[0];
    v164 = qcdr(v164);
    v164 = qcar(v164);
    v164 = Llength(nil, v164);
    nil = C_nil;
    if (exception_pending()) goto v39;
    v165 = stack[-1];
    popv(3);
    return list2(v165, v164);
/* error exit handlers */
v39:
    popv(3);
    return nil;
}



/* Code for f2dip1 */

static Lisp_Object MS_CDECL CC_f2dip1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v32,
                         Lisp_Object v51, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v168, v8, v6, v169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "f2dip1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2dip1");
#endif
    if (stack >= stacklimit)
    {
        push3(v51,v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v32,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v51;
    stack[-1] = v32;
    stack[-2] = v0;
/* end of prologue */
    v10 = stack[-2];
    if (v10 == nil) goto v139;
    v10 = stack[-2];
    if (!consp(v10)) goto v88;
    v10 = stack[-2];
    v10 = qcar(v10);
    v10 = (consp(v10) ? nil : lisp_true);
    goto v25;

v25:
    if (v10 == nil) goto v27;
    v10 = stack[0];
    v10 = (is_number(v10) ? lisp_true : nil);
    if (!(v10 == nil)) goto v38;
    v10 = stack[0];
    fn = elt(env, 3); /* f2dip11 */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    goto v38;

v38:
    v10 = stack[-2];
    fn = elt(env, 4); /* bcfd */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    fn = elt(env, 5); /* bcprod */
    v10 = (*qfn2(fn))(qenv(fn), stack[0], v10);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    v168 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v144 = stack[-1];
        popv(5);
        return list2star(v144, v10, v168);
    }

v27:
    v10 = stack[-2];
    v10 = qcar(v10);
    v10 = qcar(v10);
    v169 = qcar(v10);
    v10 = stack[-2];
    v10 = qcar(v10);
    v10 = qcar(v10);
    v6 = qcdr(v10);
    v10 = stack[-2];
    v10 = qcar(v10);
    v8 = qcdr(v10);
    v168 = stack[-1];
    v10 = stack[0];
    fn = elt(env, 6); /* f2dip2 */
    stack[-3] = (*qfnn(fn))(qenv(fn), 5, v169, v6, v8, v168, v10);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    v10 = stack[-2];
    v8 = qcdr(v10);
    v168 = stack[-1];
    v10 = stack[0];
    v10 = CC_f2dip1(env, 3, v8, v168, v10);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    {
        Lisp_Object v171 = stack[-3];
        popv(5);
        fn = elt(env, 7); /* dipsum */
        return (*qfn2(fn))(qenv(fn), v171, v10);
    }

v88:
    v10 = qvalue(elt(env, 2)); /* t */
    goto v25;

v139:
    v10 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v10); }
/* error exit handlers */
v170:
    popv(5);
    return nil;
}



/* Code for get!:const */

static Lisp_Object CC_getTconst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v171, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get:const");
#endif
    if (stack >= stacklimit)
    {
        push2(v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v32;
    stack[-1] = v0;
/* end of prologue */
    v171 = stack[-1];
    if (!consp(v171)) goto v46;
    v171 = qvalue(elt(env, 1)); /* nil */
    goto v160;

v160:
    if (v171 == nil) goto v148;
    v173 = stack[-1];
    v171 = elt(env, 2); /* save!:c */
    v171 = get(v173, v171);
    env = stack[-2];
    stack[-1] = v171;
    v171 = stack[-1];
    if (v171 == nil) goto v14;
    v171 = stack[-1];
    v173 = qcar(v171);
    v171 = stack[0];
    v171 = (Lisp_Object)lessp2(v173, v171);
    nil = C_nil;
    if (exception_pending()) goto v30;
    v171 = v171 ? lisp_true : nil;
    env = stack[-2];
    goto v127;

v127:
    if (v171 == nil) goto v12;
    v171 = elt(env, 4); /* not_found */
    { popv(3); return onevalue(v171); }

v12:
    v171 = stack[-1];
    v173 = qcar(v171);
    v171 = stack[0];
    if (equal(v173, v171)) goto v115;
    v171 = stack[-1];
    v173 = qcdr(v171);
    v171 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v173, v171);
    }

v115:
    v171 = stack[-1];
    v171 = qcdr(v171);
    { popv(3); return onevalue(v171); }

v14:
    v171 = qvalue(elt(env, 3)); /* t */
    goto v127;

v148:
    stack[0] = (Lisp_Object)1; /* 0 */
    v173 = elt(env, 5); /* "Invalid argument to" */
    v171 = elt(env, 0); /* get!:const */
    v171 = list2(v173, v171);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-2];
    {
        Lisp_Object v114 = stack[0];
        popv(3);
        fn = elt(env, 7); /* error */
        return (*qfn2(fn))(qenv(fn), v114, v171);
    }

v46:
    v171 = stack[0];
    v171 = integerp(v171);
    if (v171 == nil) goto v88;
    v173 = stack[0];
    v171 = (Lisp_Object)1; /* 0 */
    v171 = (Lisp_Object)greaterp2(v173, v171);
    nil = C_nil;
    if (exception_pending()) goto v30;
    v171 = v171 ? lisp_true : nil;
    env = stack[-2];
    goto v160;

v88:
    v171 = qvalue(elt(env, 1)); /* nil */
    goto v160;
/* error exit handlers */
v30:
    popv(3);
    return nil;
}



/* Code for r2findindex1 */

static Lisp_Object MS_CDECL CC_r2findindex1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v32,
                         Lisp_Object v51, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v17, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "r2findindex1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2findindex1");
#endif
    if (stack >= stacklimit)
    {
        push3(v51,v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v32,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v17 = v51;
    stack[0] = v32;
    stack[-1] = v0;
/* end of prologue */

v139:
    v19 = stack[0];
    if (v19 == nil) goto v46;
    v117 = stack[-1];
    v19 = stack[0];
    v19 = qcar(v19);
    if (equal(v117, v19)) { popv(3); return onevalue(v17); }
    v19 = stack[0];
    v19 = qcdr(v19);
    stack[0] = v19;
    v19 = v17;
    v19 = add1(v19);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    v17 = v19;
    goto v139;

v46:
    v19 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v19 == nil)) goto v56;
    v19 = elt(env, 2); /* "index not found" */
    fn = elt(env, 3); /* lprie */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    goto v56;

v56:
    v19 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v105;
    v19 = nil;
    { popv(3); return onevalue(v19); }
/* error exit handlers */
v105:
    popv(3);
    return nil;
}



/* Code for list!-evaluate */

static Lisp_Object MS_CDECL CC_listKevaluate(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v32,
                         Lisp_Object v51, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v176, v115, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "list-evaluate");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list-evaluate");
#endif
    if (stack >= stacklimit)
    {
        push3(v51,v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v32,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v51;
    stack[-4] = v32;
    v176 = v0;
/* end of prologue */
    stack[-5] = v176;
    v176 = stack[-5];
    if (v176 == nil) goto v25;
    v176 = stack[-5];
    v176 = qcar(v176);
    v11 = v176;
    v115 = stack[-4];
    v176 = stack[-3];
    fn = elt(env, 2); /* evaluate */
    v176 = (*qfnn(fn))(qenv(fn), 3, v11, v115, v176);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-6];
    v176 = ncons(v176);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-6];
    stack[-1] = v176;
    stack[-2] = v176;
    goto v46;

v46:
    v176 = stack[-5];
    v176 = qcdr(v176);
    stack[-5] = v176;
    v176 = stack[-5];
    if (v176 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v176 = stack[-5];
    v176 = qcar(v176);
    v11 = v176;
    v115 = stack[-4];
    v176 = stack[-3];
    fn = elt(env, 2); /* evaluate */
    v176 = (*qfnn(fn))(qenv(fn), 3, v11, v115, v176);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-6];
    v176 = ncons(v176);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-6];
    v176 = Lrplacd(nil, stack[0], v176);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-6];
    v176 = stack[-1];
    v176 = qcdr(v176);
    stack[-1] = v176;
    goto v46;

v25:
    v176 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v176); }
/* error exit handlers */
v163:
    popv(7);
    return nil;
}



/* Code for getupper */

static Lisp_Object CC_getupper(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v26;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getupper");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v20 = v0;
/* end of prologue */
    v26 = qvalue(elt(env, 1)); /* metricu!* */
    v20 = Latsoc(nil, v20, v26);
    v20 = qcdr(v20);
    return onevalue(v20);
}



/* Code for z!-roads */

static Lisp_Object CC_zKroads(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v177, v43, v44;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for z-roads");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v44 = v0;
/* end of prologue */
    v43 = (Lisp_Object)1; /* 0 */
    v177 = v44;
    v177 = qcar(v177);
    v177 = qcar(v177);
    v177 = qcdr(v177);
    if (v43 == v177) goto v24;
    v43 = (Lisp_Object)1; /* 0 */
    v177 = v44;
    v177 = qcar(v177);
    v177 = qcdr(v177);
    v177 = qcar(v177);
    v177 = qcdr(v177);
    if (v43 == v177) goto v162;
    v43 = (Lisp_Object)1; /* 0 */
    v177 = v44;
    v177 = qcar(v177);
    v177 = qcdr(v177);
    v177 = qcdr(v177);
    v177 = qcar(v177);
    v177 = qcdr(v177);
    if (v43 == v177) goto v138;
    v177 = qvalue(elt(env, 1)); /* nil */
    goto v42;

v42:
    v43 = v177;
    v177 = v43;
    if (v177 == nil) goto v35;
    v177 = v43;
    v177 = qcar(v177);
    v43 = v44;
    v43 = qcdr(v43);
    return cons(v177, v43);

v35:
    v177 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v177);

v138:
    v177 = v44;
    v177 = qcar(v177);
    v177 = qcdr(v177);
    v177 = qcdr(v177);
    v177 = qcar(v177);
    goto v42;

v162:
    v177 = v44;
    v177 = qcar(v177);
    v177 = qcdr(v177);
    v177 = qcar(v177);
    goto v42;

v24:
    v177 = v44;
    v177 = qcar(v177);
    v177 = qcar(v177);
    goto v42;
}



/* Code for split_cov_cont_ids */

static Lisp_Object CC_split_cov_cont_ids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v48, v176;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split_cov_cont_ids");
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
    stack[0] = nil;
    goto v160;

v160:
    v36 = stack[-1];
    if (v36 == nil) goto v34;
    v36 = stack[-1];
    v36 = qcar(v36);
    v176 = v36;
    v48 = v176;
    v36 = elt(env, 2); /* minus */
    if (!consp(v48)) goto v37;
    v48 = qcar(v48);
    if (!(v48 == v36)) goto v37;
    v36 = v176;
    v36 = qcdr(v36);
    v48 = qcar(v36);
    v36 = stack[-2];
    v36 = cons(v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-3];
    stack[-2] = v36;
    goto v162;

v162:
    v36 = stack[-1];
    v36 = qcdr(v36);
    stack[-1] = v36;
    goto v160;

v37:
    v48 = v176;
    v36 = stack[0];
    v36 = cons(v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-3];
    stack[0] = v36;
    goto v162;

v34:
    v36 = stack[-2];
    v48 = Lnreverse(nil, v36);
    env = stack[-3];
    v36 = stack[0];
    v36 = Lnreverse(nil, v36);
    popv(4);
    return list2(v48, v36);
/* error exit handlers */
v178:
    popv(4);
    return nil;
}



/* Code for polynomwrite */

static Lisp_Object CC_polynomwrite(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomwrite");
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
    goto v147;

v147:
    v34 = stack[0];
    v34 = qcar(v34);
    if (v34 == nil) goto v160;
    v34 = stack[0];
    v153 = qcar(v34);
    v34 = (Lisp_Object)1; /* 0 */
    v153 = *(Lisp_Object *)((char *)v153 + (CELL-TAG_VECTOR) + ((int32_t)v34/(16/CELL)));
    v34 = (Lisp_Object)1; /* 0 */
    if (v153 == v34) goto v16;
    v34 = stack[0];
    v34 = qcar(v34);
    fn = elt(env, 1); /* monomwrite */
    v153 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    v34 = stack[-1];
    v34 = cons(v153, v34);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    stack[-1] = v34;
    v34 = stack[0];
    v34 = qcdr(v34);
    stack[0] = v34;
    goto v147;

v16:
    v153 = stack[-1];
    v34 = (Lisp_Object)17; /* 1 */
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v153, v34);
    }

v160:
    v34 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v34);
    }
/* error exit handlers */
v152:
    popv(3);
    return nil;
}



/* Code for pasf_subfof1 */

static Lisp_Object MS_CDECL CC_pasf_subfof1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v32,
                         Lisp_Object v51, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v187;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pasf_subfof1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_subfof1");
#endif
    if (stack >= stacklimit)
    {
        push3(v51,v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v32,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v51;
    stack[-2] = v32;
    stack[-3] = v0;
/* end of prologue */
    v92 = stack[-3];
    v92 = Lconsp(nil, v92);
    env = stack[-5];
    if (v92 == nil) goto v30;
    v92 = stack[-3];
    v92 = qcar(v92);
    v92 = Lconsp(nil, v92);
    env = stack[-5];
    if (v92 == nil) goto v30;
    v92 = stack[-3];
    v92 = qcar(v92);
    v187 = qcar(v92);
    v92 = elt(env, 1); /* (cong ncong) */
    v92 = Lmemq(nil, v187, v92);
    if (v92 == nil) goto v30;
    v187 = stack[-3];
    v92 = elt(env, 2); /* true */
    if (v187 == v92) goto v93;
    v187 = stack[-3];
    v92 = elt(env, 4); /* false */
    v92 = (v187 == v92 ? lisp_true : nil);
    goto v106;

v106:
    if (v92 == nil) goto v105;
    v92 = stack[-3];
    stack[-4] = v92;
    goto v7;

v7:
    v92 = stack[-3];
    v92 = qcar(v92);
    stack[0] = qcdr(v92);
    v187 = stack[-2];
    v92 = stack[-1];
    v92 = cons(v187, v92);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-5];
    v92 = ncons(v92);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-5];
    fn = elt(env, 5); /* subf */
    v92 = (*qfn2(fn))(qenv(fn), stack[0], v92);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-5];
    v92 = qcar(v92);
    v92 = cons(stack[-4], v92);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-5];
    stack[-4] = v92;
    goto v189;

v189:
    v92 = stack[-3];
    v92 = qcdr(v92);
    stack[0] = qcar(v92);
    v187 = stack[-2];
    v92 = stack[-1];
    v92 = cons(v187, v92);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-5];
    v92 = ncons(v92);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-5];
    fn = elt(env, 5); /* subf */
    v92 = (*qfn2(fn))(qenv(fn), stack[0], v92);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-5];
    stack[0] = qcar(v92);
    v92 = stack[-3];
    v92 = qcdr(v92);
    v92 = qcdr(v92);
    stack[-3] = qcar(v92);
    v187 = stack[-2];
    v92 = stack[-1];
    v92 = cons(v187, v92);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-5];
    v92 = ncons(v92);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-5];
    fn = elt(env, 5); /* subf */
    v92 = (*qfn2(fn))(qenv(fn), stack[-3], v92);
    nil = C_nil;
    if (exception_pending()) goto v188;
    v92 = qcar(v92);
    {
        Lisp_Object v190 = stack[-4];
        Lisp_Object v191 = stack[0];
        popv(6);
        return list3(v190, v191, v92);
    }

v105:
    v92 = stack[-3];
    v92 = qcar(v92);
    v92 = Lconsp(nil, v92);
    env = stack[-5];
    if (v92 == nil) goto v33;
    v92 = stack[-3];
    v92 = qcar(v92);
    v92 = qcar(v92);
    stack[-4] = v92;
    goto v7;

v33:
    v92 = stack[-3];
    v92 = qcar(v92);
    stack[-4] = v92;
    goto v7;

v93:
    v92 = qvalue(elt(env, 3)); /* t */
    goto v106;

v30:
    v187 = stack[-3];
    v92 = elt(env, 2); /* true */
    if (v187 == v92) goto v192;
    v187 = stack[-3];
    v92 = elt(env, 4); /* false */
    v92 = (v187 == v92 ? lisp_true : nil);
    goto v173;

v173:
    if (v92 == nil) goto v144;
    v92 = stack[-3];
    goto v113;

v113:
    stack[-4] = v92;
    goto v189;

v144:
    v92 = stack[-3];
    v92 = qcar(v92);
    v92 = Lconsp(nil, v92);
    env = stack[-5];
    if (v92 == nil) goto v193;
    v92 = stack[-3];
    v92 = qcar(v92);
    v92 = qcar(v92);
    goto v113;

v193:
    v92 = stack[-3];
    v92 = qcar(v92);
    goto v113;

v192:
    v92 = qvalue(elt(env, 3)); /* t */
    goto v173;
/* error exit handlers */
v188:
    popv(6);
    return nil;
}



/* Code for listrd */

static Lisp_Object MS_CDECL CC_listrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v149, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "listrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listrd");
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
    v149 = qvalue(elt(env, 1)); /* atts */
    v148 = elt(env, 2); /* (o r d e r) */
    fn = elt(env, 11); /* search_att */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-2];
    stack[-1] = v148;
    v148 = elt(env, 3); /* (t y p e != l i s t !$) */
    qvalue(elt(env, 1)) = v148; /* atts */
    stack[0] = elt(env, 4); /* list */
    fn = elt(env, 12); /* stats_getargs */
    v148 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-2];
    v148 = cons(stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-2];
    v149 = v148;
    stack[0] = v149;
    v9 = stack[-1];
    v149 = elt(env, 5); /* (l e x i c o g r a p h i c) */
    if (!(equal(v9, v149))) goto v15;
    v149 = elt(env, 6); /* sortlist */
    v9 = v148;
    v148 = elt(env, 7); /* lexog */
    v148 = list3(v149, v9, v148);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-2];
    fn = elt(env, 13); /* aeval */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-2];
    goto v15;

v15:
    v9 = stack[-1];
    v149 = elt(env, 8); /* (n u m e r i c) */
    if (equal(v9, v149)) goto v175;
    v9 = elt(env, 6); /* sortlist */
    v149 = v148;
    v148 = elt(env, 10); /* pred */
    v148 = list3(v9, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-2];
    fn = elt(env, 13); /* aeval */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v8;
    goto v127;

v127:
    v149 = v148;
    if (!(v149 == nil)) { popv(3); return onevalue(v148); }
    v148 = stack[0];
    { popv(3); return onevalue(v148); }

v175:
    v9 = elt(env, 6); /* sortlist */
    v149 = v148;
    v148 = elt(env, 9); /* numer */
    v148 = list3(v9, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-2];
    fn = elt(env, 13); /* aeval */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v8;
    goto v127;
/* error exit handlers */
v8:
    popv(3);
    return nil;
}



/* Code for compl */

static Lisp_Object CC_compl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v117, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compl");
#endif
    if (stack >= stacklimit)
    {
        push2(v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v32;
    stack[-1] = v0;
/* end of prologue */
    v38 = nil;
    goto v139;

v139:
    v17 = stack[-1];
    if (v17 == nil) goto v46;
    v17 = stack[-1];
    v117 = qcar(v17);
    v17 = stack[0];
    v17 = Lmember(nil, v117, v17);
    if (v17 == nil) goto v165;
    v17 = stack[-1];
    v17 = qcdr(v17);
    stack[-1] = v17;
    goto v139;

v165:
    v17 = stack[-1];
    v17 = qcar(v17);
    v117 = v38;
    v17 = cons(v17, v117);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-2];
    v38 = v17;
    v17 = stack[-1];
    v17 = qcdr(v17);
    stack[-1] = v17;
    goto v139;

v46:
    v17 = v38;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v17);
    }
/* error exit handlers */
v107:
    popv(3);
    return nil;
}



/* Code for spcol_dim */

static Lisp_Object CC_spcol_dim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spcol_dim");
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
    v138 = qvalue(elt(env, 1)); /* !*fast_la */
    if (v138 == nil) goto v20;
    v138 = qvalue(elt(env, 2)); /* nil */
    goto v150;

v150:
    if (v138 == nil) goto v139;
    v138 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v138 == nil)) goto v135;
    v138 = elt(env, 4); /* "Error in spcol_dim: input should be a matrix." 
*/
    fn = elt(env, 5); /* lprie */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    goto v135;

v135:
    v138 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    goto v139;

v139:
    v138 = stack[0];
    fn = elt(env, 6); /* spmatlength */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v18;
    v138 = qcdr(v138);
    v138 = qcdr(v138);
    v138 = qcar(v138);
    { popv(2); return onevalue(v138); }

v20:
    v138 = stack[0];
    fn = elt(env, 7); /* matrixp */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    v138 = (v138 == nil ? lisp_true : nil);
    goto v150;
/* error exit handlers */
v18:
    popv(2);
    return nil;
}



/* Code for dm!-gt */

static Lisp_Object CC_dmKgt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v18, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-gt");
#endif
    if (stack >= stacklimit)
    {
        push2(v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v18 = v32;
    v179 = v0;
/* end of prologue */
    fn = elt(env, 2); /* dm!-difference */
    v179 = (*qfn2(fn))(qenv(fn), v18, v179);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[0];
    v19 = v179;
    v179 = v19;
    if (!consp(v179)) goto v88;
    v179 = v19;
    v18 = qcar(v179);
    v179 = elt(env, 1); /* minusp */
    v179 = get(v18, v179);
    v18 = v19;
        popv(1);
        return Lapply1(nil, v179, v18);

v88:
    v179 = v19;
        popv(1);
        return Lminusp(nil, v179);
/* error exit handlers */
v17:
    popv(1);
    return nil;
}



/* Code for groebspolynom3 */

static Lisp_Object CC_groebspolynom3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v196;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebspolynom3");
#endif
    if (stack >= stacklimit)
    {
        push2(v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v41 = v32;
    v196 = v0;
/* end of prologue */
    fn = elt(env, 1); /* groebspolynom4 */
    v41 = (*qfn2(fn))(qenv(fn), v196, v41);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-1];
    stack[0] = v41;
    v41 = stack[0];
    fn = elt(env, 2); /* groebsavelterm */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v161;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v161:
    popv(2);
    return nil;
}



/* Code for mkexdf */

static Lisp_Object CC_mkexdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkexdf");
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
    v134 = v0;
/* end of prologue */
    v133 = elt(env, 1); /* d */
    v134 = list2(v133, v134);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-1];
    stack[0] = v134;
    fn = elt(env, 2); /* opmtch */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-1];
    v133 = v134;
    if (v134 == nil) goto v194;
    v134 = v133;
    {
        popv(2);
        fn = elt(env, 3); /* partitop */
        return (*qfn1(fn))(qenv(fn), v134);
    }

v194:
    v134 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* mkupf */
        return (*qfn1(fn))(qenv(fn), v134);
    }
/* error exit handlers */
v123:
    popv(2);
    return nil;
}



/* Code for r2oaddspecies */

static Lisp_Object CC_r2oaddspecies(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v117;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2oaddspecies");
#endif
    if (stack >= stacklimit)
    {
        push2(v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v32;
    stack[-1] = v0;
/* end of prologue */
    v117 = stack[-1];
    v17 = stack[0];
    v17 = Lassoc(nil, v117, v17);
    if (!(v17 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v17 = elt(env, 1); /* "new species: " */
    v17 = Lprinc(nil, v17);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    v17 = stack[-1];
    v17 = Lprinc(nil, v17);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    v17 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    v117 = stack[-1];
    v17 = (Lisp_Object)1; /* 0 */
    v17 = cons(v117, v17);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    v17 = ncons(v17);
    nil = C_nil;
    if (exception_pending()) goto v105;
    {
        Lisp_Object v107 = stack[0];
        popv(3);
        return Lappend(nil, v107, v17);
    }
/* error exit handlers */
v105:
    popv(3);
    return nil;
}



/* Code for mkassign */

static Lisp_Object CC_mkassign(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v56, v40;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkassign");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v88 = v32;
    v56 = v0;
/* end of prologue */
    v40 = elt(env, 1); /* setq */
    return list3(v40, v56, v88);
}



/* Code for vunion */

static Lisp_Object CC_vunion(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v144;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vunion");
#endif
    if (stack >= stacklimit)
    {
        push2(v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v32;
    stack[-2] = v0;
/* end of prologue */
    v170 = stack[-2];
    if (v170 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v170 = stack[-2];
    v170 = qcar(v170);
    v144 = qcar(v170);
    v170 = stack[-1];
    v170 = Lassoc(nil, v144, v170);
    stack[-3] = v170;
    if (v170 == nil) goto v134;
    v170 = stack[-2];
    v170 = qcar(v170);
    v144 = qcdr(v170);
    v170 = stack[-3];
    v170 = qcdr(v170);
    v170 = (Lisp_Object)greaterp2(v144, v170);
    nil = C_nil;
    if (exception_pending()) goto v30;
    v170 = v170 ? lisp_true : nil;
    env = stack[-4];
    if (v170 == nil) goto v7;
    v170 = stack[-2];
    stack[0] = qcar(v170);
    v170 = stack[-2];
    stack[-2] = qcdr(v170);
    v144 = stack[-3];
    v170 = stack[-1];
    v170 = Ldelete(nil, v144, v170);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-4];
    v170 = CC_vunion(env, stack[-2], v170);
    nil = C_nil;
    if (exception_pending()) goto v30;
    {
        Lisp_Object v114 = stack[0];
        popv(5);
        return cons(v114, v170);
    }

v7:
    stack[0] = stack[-3];
    v170 = stack[-2];
    stack[-2] = qcdr(v170);
    v144 = stack[-3];
    v170 = stack[-1];
    v170 = Ldelete(nil, v144, v170);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-4];
    v170 = CC_vunion(env, stack[-2], v170);
    nil = C_nil;
    if (exception_pending()) goto v30;
    {
        Lisp_Object v198 = stack[0];
        popv(5);
        return cons(v198, v170);
    }

v134:
    v170 = stack[-2];
    stack[0] = qcar(v170);
    v170 = stack[-2];
    v144 = qcdr(v170);
    v170 = stack[-1];
    v170 = CC_vunion(env, v144, v170);
    nil = C_nil;
    if (exception_pending()) goto v30;
    {
        Lisp_Object v111 = stack[0];
        popv(5);
        return cons(v111, v170);
    }
/* error exit handlers */
v30:
    popv(5);
    return nil;
}



/* Code for subs2p */

static Lisp_Object MS_CDECL CC_subs2p(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v32,
                         Lisp_Object v51, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v173, v192, v1;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subs2p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2p");
#endif
    if (stack >= stacklimit)
    {
        push3(v51,v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v32,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v51;
    stack[-1] = v32;
    stack[-2] = v0;
/* end of prologue */
    v173 = stack[-2];
    v173 = qcdr(v173);
    v173 = integerp(v173);
    if (v173 == nil) goto v26;
    v173 = stack[-2];
    v192 = qcdr(v173);
    v173 = stack[-1];
    v173 = Ldivide(nil, v192, v173);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    stack[-1] = v173;
    v192 = qcar(v173);
    v173 = (Lisp_Object)1; /* 0 */
    v173 = (v192 == v173 ? lisp_true : nil);
    goto v20;

v20:
    if (v173 == nil) goto v153;
    v192 = stack[-2];
    v173 = (Lisp_Object)17; /* 1 */
    v173 = cons(v192, v173);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    v192 = ncons(v173);
    nil = C_nil;
    if (exception_pending()) goto v111;
    v173 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v192, v173);

v153:
    v173 = stack[0];
    fn = elt(env, 2); /* simp */
    v192 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    v173 = stack[-1];
    v173 = qcar(v173);
    fn = elt(env, 3); /* exptsq */
    v173 = (*qfn2(fn))(qenv(fn), v192, v173);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    stack[0] = v173;
    v173 = stack[-1];
    v192 = qcdr(v173);
    v173 = (Lisp_Object)1; /* 0 */
    if (v192 == v173) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v173 = stack[-2];
    v1 = qcar(v173);
    v173 = stack[-1];
    v192 = qcdr(v173);
    v173 = (Lisp_Object)17; /* 1 */
    v173 = acons(v1, v192, v173);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    v192 = ncons(v173);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    v173 = (Lisp_Object)17; /* 1 */
    v192 = cons(v192, v173);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    v173 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); /* multsq */
        return (*qfn2(fn))(qenv(fn), v192, v173);
    }

v26:
    v173 = qvalue(elt(env, 1)); /* t */
    goto v20;
/* error exit handlers */
v111:
    popv(4);
    return nil;
}



/* Code for mod_eval_uni_poly */

static Lisp_Object CC_mod_eval_uni_poly(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v203, v204, v205;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod_eval_uni_poly");
#endif
    if (stack >= stacklimit)
    {
        push2(v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v32;
    stack[-2] = v0;
/* end of prologue */
    v203 = stack[-2];
    if (!consp(v203)) goto v147;
    v203 = stack[-2];
    v203 = qcar(v203);
    v203 = qcdr(v203);
    fn = elt(env, 3); /* mod!# */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v205 = v203;
    v203 = stack[-2];
    v203 = qcar(v203);
    v203 = qcar(v203);
    v203 = qcdr(v203);
    v204 = v203;
    v203 = stack[-2];
    v203 = qcdr(v203);
    stack[-2] = v203;
    goto v123;

v123:
    v203 = stack[-2];
    if (!consp(v203)) goto v199;
    stack[-3] = v205;
    stack[0] = stack[-1];
    v203 = stack[-2];
    v203 = qcar(v203);
    v203 = qcar(v203);
    v203 = qcdr(v203);
    v203 = difference2(v204, v203);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    fn = elt(env, 4); /* general!-modular!-expt */
    v203 = (*qfn2(fn))(qenv(fn), stack[0], v203);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v204 = times2(stack[-3], v203);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v203 = qvalue(elt(env, 2)); /* current!-modulus */
    stack[0] = Cremainder(v204, v203);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v203 = stack[-2];
    v203 = qcar(v203);
    v203 = qcdr(v203);
    fn = elt(env, 3); /* mod!# */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    fn = elt(env, 5); /* general!-modular!-plus */
    v203 = (*qfn2(fn))(qenv(fn), stack[0], v203);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v205 = v203;
    v203 = stack[-2];
    v203 = qcar(v203);
    v203 = qcar(v203);
    v203 = qcdr(v203);
    v204 = v203;
    v203 = stack[-2];
    v203 = qcdr(v203);
    stack[-2] = v203;
    goto v123;

v199:
    stack[0] = v205;
    v203 = stack[-1];
    fn = elt(env, 4); /* general!-modular!-expt */
    v203 = (*qfn2(fn))(qenv(fn), v203, v204);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v204 = times2(stack[0], v203);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v203 = qvalue(elt(env, 2)); /* current!-modulus */
    v203 = Cremainder(v204, v203);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v205 = v203;
    v203 = stack[-2];
    if (v203 == nil) { popv(5); return onevalue(v205); }
    stack[0] = v205;
    v203 = stack[-2];
    fn = elt(env, 3); /* mod!# */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    fn = elt(env, 5); /* general!-modular!-plus */
    v203 = (*qfn2(fn))(qenv(fn), stack[0], v203);
    nil = C_nil;
    if (exception_pending()) goto v94;
    v205 = v203;
    { popv(5); return onevalue(v205); }

v147:
    v203 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* mod!# */
        return (*qfn1(fn))(qenv(fn), v203);
    }
/* error exit handlers */
v94:
    popv(5);
    return nil;
}



/* Code for preptayexp */

static Lisp_Object CC_preptayexp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preptayexp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v0;
/* end of prologue */
    v26 = v25;
    if (!consp(v26)) return onevalue(v25);
    v26 = v25;
    {
        fn = elt(env, 1); /* rnprep!: */
        return (*qfn1(fn))(qenv(fn), v26);
    }
}



/* Code for domainvalchk */

static Lisp_Object CC_domainvalchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v197, v202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for domainvalchk");
#endif
    if (stack >= stacklimit)
    {
        push2(v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v32;
    stack[-1] = v0;
/* end of prologue */
    v197 = qvalue(elt(env, 1)); /* dmode!* */
    v125 = elt(env, 0); /* domainvalchk */
    v125 = get(v197, v125);
    env = stack[-3];
    stack[-2] = v125;
    if (v125 == nil) goto v160;
    v202 = stack[-2];
    v197 = stack[-1];
    v125 = stack[0];
        popv(4);
        return Lapply2(nil, 3, v202, v197, v125);

v160:
    v125 = stack[0];
    v125 = Lreverse(nil, v125);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-3];
    stack[0] = v125;
    goto v139;

v139:
    v125 = stack[0];
    if (v125 == nil) goto v18;
    v125 = stack[0];
    v125 = qcar(v125);
    v197 = qcdr(v125);
    v125 = (Lisp_Object)17; /* 1 */
    if (v197 == v125) goto v27;
    v125 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v125); }

v27:
    v125 = stack[0];
    v125 = qcar(v125);
    fn = elt(env, 3); /* mk!*sq */
    v197 = (*qfn1(fn))(qenv(fn), v125);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-3];
    v125 = stack[-2];
    v125 = cons(v197, v125);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-3];
    stack[-2] = v125;
    v125 = stack[0];
    v125 = qcdr(v125);
    stack[0] = v125;
    goto v139;

v18:
    v197 = stack[-1];
    v125 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); /* valuechk */
        return (*qfn2(fn))(qenv(fn), v197, v125);
    }
/* error exit handlers */
v5:
    popv(4);
    return nil;
}



/* Code for enter!-sorted */

static Lisp_Object CC_enterKsorted(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for enter-sorted");
#endif
    if (stack >= stacklimit)
    {
        push2(v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v32;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v139;

v139:
    v36 = stack[0];
    if (v36 == nil) goto v25;
    v36 = stack[-1];
    v48 = qcar(v36);
    v36 = stack[0];
    v36 = qcar(v36);
    v36 = qcar(v36);
    fn = elt(env, 1); /* taydegree!< */
    v36 = (*qfn2(fn))(qenv(fn), v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-3];
    if (v36 == nil) goto v29;
    v48 = stack[-1];
    v36 = stack[0];
    v36 = cons(v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-3];
    {
        Lisp_Object v178 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v178, v36);
    }

v29:
    v36 = stack[0];
    v48 = qcar(v36);
    v36 = stack[-2];
    v36 = cons(v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-3];
    stack[-2] = v36;
    v36 = stack[0];
    v36 = qcdr(v36);
    stack[0] = v36;
    goto v139;

v25:
    stack[0] = stack[-2];
    v36 = stack[-1];
    v36 = ncons(v36);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-3];
    {
        Lisp_Object v125 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v125, v36);
    }
/* error exit handlers */
v12:
    popv(4);
    return nil;
}



/* Code for matrixom */

static Lisp_Object CC_matrixom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixom");
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
    v161 = elt(env, 1); /* "<OMA>" */
    fn = elt(env, 6); /* printout */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-1];
    v161 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 7); /* indent!* */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-1];
    v161 = elt(env, 3); /* "<OMS cd=""linalg1"" name=""matrix""/>" */
    fn = elt(env, 6); /* printout */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-1];
    v161 = stack[0];
    v161 = qcdr(v161);
    v161 = qcdr(v161);
    v161 = qcdr(v161);
    v161 = qcar(v161);
    fn = elt(env, 8); /* matrixrowom */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-1];
    v161 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 7); /* indent!* */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-1];
    v161 = elt(env, 5); /* "</OMA>" */
    fn = elt(env, 6); /* printout */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v195;
    v161 = nil;
    { popv(2); return onevalue(v161); }
/* error exit handlers */
v195:
    popv(2);
    return nil;
}



/* Code for countof */

static Lisp_Object CC_countof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v106;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for countof");
#endif
    if (stack >= stacklimit)
    {
        push2(v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v32;
    stack[-1] = v0;
/* end of prologue */
    v106 = stack[-1];
    v107 = stack[0];
    if (equal(v106, v107)) goto v147;
    v107 = stack[0];
    if (!consp(v107)) goto v56;
    v106 = stack[-1];
    v107 = stack[0];
    v107 = qcar(v107);
    stack[-2] = CC_countof(env, v106, v107);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    v106 = stack[-1];
    v107 = stack[0];
    v107 = qcdr(v107);
    v107 = CC_countof(env, v106, v107);
    nil = C_nil;
    if (exception_pending()) goto v13;
    {
        Lisp_Object v15 = stack[-2];
        popv(4);
        return plus2(v15, v107);
    }

v56:
    v107 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v107); }

v147:
    v107 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v107); }
/* error exit handlers */
v13:
    popv(4);
    return nil;
}



/* Code for remdiff */

static Lisp_Object CC_remdiff(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remdiff");
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
    stack[-1] = v0;
/* end of prologue */
    v144 = stack[-1];
    if (symbolp(v144)) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v144 = stack[-1];
    fn = elt(env, 5); /* constp */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    if (!(v144 == nil)) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v144 = stack[-1];
    v171 = qcar(v144);
    v144 = elt(env, 1); /* difference */
    if (v171 == v144) goto v47;
    v144 = stack[-1];
    stack[-4] = qcar(v144);
    v144 = stack[-1];
    v144 = qcdr(v144);
    stack[-3] = v144;
    v144 = stack[-3];
    if (v144 == nil) goto v202;
    v144 = stack[-3];
    v144 = qcar(v144);
    v144 = CC_remdiff(env, v144);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v144 = ncons(v144);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    stack[-1] = v144;
    stack[-2] = v144;
    goto v11;

v11:
    v144 = stack[-3];
    v144 = qcdr(v144);
    stack[-3] = v144;
    v144 = stack[-3];
    if (v144 == nil) goto v110;
    stack[0] = stack[-1];
    v144 = stack[-3];
    v144 = qcar(v144);
    v144 = CC_remdiff(env, v144);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v144 = ncons(v144);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v144 = Lrplacd(nil, stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v144 = stack[-1];
    v144 = qcdr(v144);
    stack[-1] = v144;
    goto v11;

v110:
    v144 = stack[-2];
    goto v152;

v152:
    {
        Lisp_Object v111 = stack[-4];
        popv(6);
        return cons(v111, v144);
    }

v202:
    v144 = qvalue(elt(env, 4)); /* nil */
    goto v152;

v47:
    stack[-3] = elt(env, 2); /* plus */
    v144 = stack[-1];
    v144 = qcdr(v144);
    v144 = qcar(v144);
    stack[-2] = CC_remdiff(env, v144);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    stack[0] = elt(env, 3); /* minus */
    v144 = stack[-1];
    v144 = qcdr(v144);
    v144 = qcdr(v144);
    v144 = qcar(v144);
    v144 = CC_remdiff(env, v144);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v144 = list2(stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v144 = list3(stack[-3], stack[-2], v144);
    nil = C_nil;
    if (exception_pending()) goto v198;
    { popv(6); return onevalue(v144); }
/* error exit handlers */
v198:
    popv(6);
    return nil;
}



/* Code for !:!:quotient */

static Lisp_Object CC_TTquotient(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ::quotient");
#endif
    if (stack >= stacklimit)
    {
        push2(v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v19 = v32;
    v18 = v0;
/* end of prologue */
    stack[0] = v18;
    v18 = v19;
    v18 = integerp(v18);
    if (v18 == nil) goto v137;
    v18 = v19;
    fn = elt(env, 2); /* chkint!* */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-1];
    v19 = v18;
    if (!(!consp(v19))) goto v122;
    v19 = elt(env, 1); /* !:rd!: */
    v18 = cons(v19, v18);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-1];
    goto v122;

v122:
    {
        Lisp_Object v38 = stack[0];
        popv(2);
        fn = elt(env, 3); /* !:quotient */
        return (*qfn2(fn))(qenv(fn), v38, v18);
    }

v137:
    v18 = v19;
    goto v122;
/* error exit handlers */
v117:
    popv(2);
    return nil;
}



/* Code for mktails */

static Lisp_Object MS_CDECL CC_mktails(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v32,
                         Lisp_Object v51, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v178, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mktails");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mktails");
#endif
    if (stack >= stacklimit)
    {
        push3(v51,v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v32,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v178 = v51;
    stack[-2] = v32;
    v125 = v0;
/* end of prologue */
    stack[0] = nil;
    v12 = v125;
    if (v12 == nil) goto v40;
    v12 = v125;
    stack[-3] = v12;
    v12 = v178;
    stack[-1] = v12;
    goto v47;

v47:
    v12 = stack[-3];
    if (v12 == nil) goto v175;
    v12 = stack[-3];
    v125 = qcar(v12);
    v178 = stack[-2];
    v12 = stack[-1];
    fn = elt(env, 2); /* mktails1 */
    v12 = (*qfnn(fn))(qenv(fn), 3, v125, v178, v12);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-4];
    v178 = v12;
    v12 = v178;
    v12 = qcdr(v12);
    stack[-1] = v12;
    v12 = v178;
    v178 = qcar(v12);
    v12 = stack[0];
    v12 = Lappend(nil, v178, v12);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-4];
    stack[0] = v12;
    v12 = stack[-3];
    v12 = qcdr(v12);
    stack[-3] = v12;
    goto v47;

v175:
    v178 = stack[0];
    v12 = stack[-1];
    popv(5);
    return cons(v178, v12);

v40:
    v12 = qvalue(elt(env, 1)); /* nil */
    popv(5);
    return cons(v12, v178);
/* error exit handlers */
v172:
    popv(5);
    return nil;
}



/* Code for mv!-compact2 */

static Lisp_Object CC_mvKcompact2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v48, v176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-compact2");
#endif
    if (stack >= stacklimit)
    {
        push2(v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v32;
    stack[-1] = v0;
/* end of prologue */
    v48 = stack[-1];
    v36 = stack[0];
    fn = elt(env, 2); /* equiv!-coeffs */
    v36 = (*qfn2(fn))(qenv(fn), v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-3];
    stack[-2] = v36;
    v36 = stack[0];
    fn = elt(env, 3); /* mv!-domainlist */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-3];
    v48 = stack[-2];
    fn = elt(env, 4); /* reduce */
    v36 = (*qfn2(fn))(qenv(fn), v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-3];
    v176 = v36;
    v48 = v176;
    v36 = stack[-2];
    if (equal(v48, v36)) goto v123;
    v48 = v176;
    v36 = stack[-2];
    fn = elt(env, 5); /* mv!-domainlist!-!- */
    v36 = (*qfn2(fn))(qenv(fn), v48, v36);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-3];
    fn = elt(env, 6); /* mv!-coeff!-replace */
    v48 = (*qfn2(fn))(qenv(fn), stack[0], v36);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-3];
    v36 = stack[-1];
    {
        popv(4);
        fn = elt(env, 7); /* mv!-!+ */
        return (*qfn2(fn))(qenv(fn), v48, v36);
    }

v123:
    v36 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v36); }
/* error exit handlers */
v178:
    popv(4);
    return nil;
}



/* Code for msolve!-poly1 */

static Lisp_Object CC_msolveKpoly1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v226, v227, v228;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msolve-poly1");
#endif
    if (stack >= stacklimit)
    {
        push2(v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v32;
    stack[-5] = v0;
/* end of prologue */
    v226 = stack[-5];
    if (!consp(v226)) goto v56;
    v226 = stack[-5];
    v226 = qcar(v226);
    v226 = (consp(v226) ? nil : lisp_true);
    goto v88;

v88:
    if (!(v226 == nil)) goto v109;
    v226 = stack[-5];
    v226 = qcar(v226);
    v226 = qcar(v226);
    v227 = qcdr(v226);
    v226 = (Lisp_Object)17; /* 1 */
    if (!(v227 == v226)) goto v109;
    v226 = stack[-5];
    v226 = qcar(v226);
    v226 = qcdr(v226);
    fn = elt(env, 6); /* safe!-modrecip */
    v226 = (*qfn1(fn))(qenv(fn), v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    stack[0] = v226;
    v226 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v226; /* erfg!* */
    v226 = stack[0];
    if (v226 == nil) goto v109;
    v226 = stack[-5];
    v226 = qcdr(v226);
    fn = elt(env, 7); /* negf */
    v226 = (*qfn1(fn))(qenv(fn), v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    fn = elt(env, 8); /* multf */
    v226 = (*qfn2(fn))(qenv(fn), stack[0], v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    fn = elt(env, 9); /* moduntag */
    v226 = (*qfn1(fn))(qenv(fn), v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    stack[0] = v226;
    v226 = stack[0];
    if (v226 == nil) goto v159;
    v227 = stack[0];
    v226 = (Lisp_Object)1; /* 0 */
    v226 = (Lisp_Object)lessp2(v227, v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    v226 = v226 ? lisp_true : nil;
    env = stack[-7];
    if (!(v226 == nil)) goto v175;
    v227 = stack[0];
    v226 = qvalue(elt(env, 4)); /* current!-modulus */
    v226 = (Lisp_Object)greaterp2(v227, v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    v226 = v226 ? lisp_true : nil;
    env = stack[-7];
    if (!(v226 == nil)) goto v175;

v159:
    v226 = stack[0];
    v226 = ncons(v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    stack[0] = v226;
    goto v160;

v160:
    v226 = stack[0];
    stack[-5] = v226;
    v226 = stack[-5];
    if (v226 == nil) goto v74;
    v226 = stack[-5];
    v226 = qcar(v226);
    stack[0] = stack[-4];
    fn = elt(env, 10); /* prepf */
    v226 = (*qfn1(fn))(qenv(fn), v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    v226 = cons(stack[0], v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    v226 = ncons(v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    v226 = ncons(v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    stack[-2] = v226;
    stack[-3] = v226;
    goto v230;

v230:
    v226 = stack[-5];
    v226 = qcdr(v226);
    stack[-5] = v226;
    v226 = stack[-5];
    if (v226 == nil) { Lisp_Object res = stack[-3]; popv(8); return onevalue(res); }
    stack[-1] = stack[-2];
    v226 = stack[-5];
    v226 = qcar(v226);
    stack[0] = stack[-4];
    fn = elt(env, 10); /* prepf */
    v226 = (*qfn1(fn))(qenv(fn), v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    v226 = cons(stack[0], v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    v226 = ncons(v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    v226 = ncons(v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    v226 = Lrplacd(nil, stack[-1], v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    v226 = stack[-2];
    v226 = qcdr(v226);
    stack[-2] = v226;
    goto v230;

v74:
    v226 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v226); }

v175:
    v226 = stack[0];
    fn = elt(env, 11); /* general!-modular!-number */
    v226 = (*qfn1(fn))(qenv(fn), v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    stack[0] = v226;
    goto v159;

v109:
    v228 = stack[-5];
    v227 = stack[-4];
    v226 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 12); /* lowestdeg */
    v226 = (*qfnn(fn))(qenv(fn), 3, v228, v227, v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    stack[-6] = v226;
    v227 = stack[-6];
    v226 = (Lisp_Object)1; /* 0 */
    v226 = (Lisp_Object)greaterp2(v227, v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    v226 = v226 ? lisp_true : nil;
    env = stack[-7];
    if (v226 == nil) goto v231;
    stack[0] = stack[-5];
    v228 = elt(env, 5); /* expt */
    v227 = stack[-4];
    v226 = stack[-6];
    v226 = list3(v228, v227, v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    fn = elt(env, 13); /* simp */
    v226 = (*qfn1(fn))(qenv(fn), v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    v226 = qcar(v226);
    fn = elt(env, 14); /* quotf */
    v226 = (*qfn2(fn))(qenv(fn), stack[0], v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    stack[-5] = v226;
    goto v231;

v231:
    v226 = stack[-5];
    fn = elt(env, 9); /* moduntag */
    v226 = (*qfn1(fn))(qenv(fn), v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    fn = elt(env, 15); /* general!-reduce!-mod!-p */
    v226 = (*qfn1(fn))(qenv(fn), v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    stack[-5] = v226;
    v226 = (Lisp_Object)17; /* 1 */
    stack[-3] = v226;
    goto v141;

v141:
    v226 = qvalue(elt(env, 4)); /* current!-modulus */
    v227 = sub1(v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    v226 = stack[-3];
    v226 = difference2(v227, v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    v226 = Lminusp(nil, v226);
    env = stack[-7];
    if (v226 == nil) goto v232;
    v226 = qvalue(elt(env, 2)); /* nil */
    goto v233;

v233:
    stack[0] = v226;
    v227 = stack[-6];
    v226 = (Lisp_Object)1; /* 0 */
    v226 = (Lisp_Object)greaterp2(v227, v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    v226 = v226 ? lisp_true : nil;
    env = stack[-7];
    if (v226 == nil) goto v160;
    v226 = qvalue(elt(env, 2)); /* nil */
    v226 = ncons(v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    v226 = Lappend(nil, stack[0], v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    stack[0] = v226;
    goto v160;

v232:
    v228 = stack[-5];
    v227 = stack[-4];
    v226 = stack[-3];
    fn = elt(env, 16); /* general!-evaluate!-mod!-p */
    v226 = (*qfnn(fn))(qenv(fn), 3, v228, v227, v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    if (v226 == nil) goto v180;
    v226 = nil;
    goto v102;

v102:
    stack[-2] = v226;
    v226 = stack[-2];
    fn = elt(env, 17); /* lastpair */
    v226 = (*qfn1(fn))(qenv(fn), v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    stack[-1] = v226;
    v226 = stack[-3];
    v226 = add1(v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    stack[-3] = v226;
    v226 = stack[-1];
    if (!consp(v226)) goto v141;
    else goto v191;

v191:
    v226 = qvalue(elt(env, 4)); /* current!-modulus */
    v227 = sub1(v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    v226 = stack[-3];
    v226 = difference2(v227, v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    v226 = Lminusp(nil, v226);
    env = stack[-7];
    if (v226 == nil) goto v234;
    v226 = stack[-2];
    goto v233;

v234:
    stack[0] = stack[-1];
    v228 = stack[-5];
    v227 = stack[-4];
    v226 = stack[-3];
    fn = elt(env, 16); /* general!-evaluate!-mod!-p */
    v226 = (*qfnn(fn))(qenv(fn), 3, v228, v227, v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    if (v226 == nil) goto v235;
    v226 = nil;
    goto v236;

v236:
    v226 = Lrplacd(nil, stack[0], v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    v226 = stack[-1];
    fn = elt(env, 17); /* lastpair */
    v226 = (*qfn1(fn))(qenv(fn), v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    stack[-1] = v226;
    v226 = stack[-3];
    v226 = add1(v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    stack[-3] = v226;
    goto v191;

v235:
    v226 = stack[-3];
    v226 = ncons(v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    goto v236;

v180:
    v226 = stack[-3];
    v226 = ncons(v226);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    goto v102;

v56:
    v226 = qvalue(elt(env, 1)); /* t */
    goto v88;
/* error exit handlers */
v229:
    popv(8);
    return nil;
}



/* Code for reduce!-mod!-eigf */

static Lisp_Object CC_reduceKmodKeigf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-mod-eigf");
#endif
    if (stack >= stacklimit)
    {
        push2(v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v32;
    v106 = v0;
/* end of prologue */
    v93 = qvalue(elt(env, 1)); /* !*sub2 */
    stack[-3] = qvalue(elt(env, 1)); /* !*sub2 */
    qvalue(elt(env, 1)) = v93; /* !*sub2 */
    v93 = v106;
    v93 = qcar(v93);
    stack[-1] = qcar(v93);
    v93 = v106;
    v93 = qcdr(v93);
    v106 = qcar(v106);
    v106 = qcdr(v106);
    v106 = cons(v93, v106);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    fn = elt(env, 2); /* cancel */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    stack[0] = v106;
    v106 = stack[0];
    v106 = qcar(v106);
    fn = elt(env, 3); /* negf */
    v93 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    v106 = stack[0];
    v106 = qcdr(v106);
    v106 = cons(v93, v106);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    v93 = cons(stack[-1], v106);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    v106 = stack[-2];
    fn = elt(env, 4); /* reduce!-eival!-powers */
    v106 = (*qfn2(fn))(qenv(fn), v93, v106);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    fn = elt(env, 5); /* subs2 */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* !*sub2 */
    { popv(5); return onevalue(v106); }
/* error exit handlers */
v29:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* !*sub2 */
    popv(5);
    return nil;
}



/* Code for cl_apply2ats1 */

static Lisp_Object MS_CDECL CC_cl_apply2ats1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v32,
                         Lisp_Object v51, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v256, v257, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_apply2ats1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_apply2ats1");
#endif
    if (stack >= stacklimit)
    {
        push3(v51,v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v32,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v51;
    stack[-5] = v32;
    stack[-1] = v0;
/* end of prologue */
    v256 = stack[-1];
    if (!consp(v256)) goto v46;
    v256 = stack[-1];
    v256 = qcar(v256);
    goto v160;

v160:
    v67 = v256;
    v257 = v67;
    v256 = elt(env, 1); /* true */
    if (v257 == v256) goto v135;
    v257 = v67;
    v256 = elt(env, 3); /* false */
    v256 = (v257 == v256 ? lisp_true : nil);
    goto v195;

v195:
    if (!(v256 == nil)) { Lisp_Object res = stack[-1]; popv(8); return onevalue(res); }
    v257 = v67;
    v256 = elt(env, 4); /* ex */
    if (v257 == v256) goto v13;
    v257 = v67;
    v256 = elt(env, 5); /* all */
    v256 = (v257 == v256 ? lisp_true : nil);
    goto v14;

v14:
    if (v256 == nil) goto v144;
    stack[-2] = v67;
    v256 = stack[-1];
    v256 = qcdr(v256);
    stack[0] = qcar(v256);
    v256 = stack[-1];
    v256 = qcdr(v256);
    v256 = qcdr(v256);
    v67 = qcar(v256);
    v257 = stack[-5];
    v256 = stack[-4];
    v256 = CC_cl_apply2ats1(env, 3, v67, v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    {
        Lisp_Object v259 = stack[-2];
        Lisp_Object v260 = stack[0];
        popv(8);
        return list3(v259, v260, v256);
    }

v144:
    v257 = v67;
    v256 = elt(env, 6); /* bex */
    if (v257 == v256) goto v113;
    v257 = v67;
    v256 = elt(env, 7); /* ball */
    v256 = (v257 == v256 ? lisp_true : nil);
    goto v112;

v112:
    if (v256 == nil) goto v261;
    stack[-3] = v67;
    v256 = stack[-1];
    v256 = qcdr(v256);
    stack[-2] = qcar(v256);
    v256 = stack[-1];
    v256 = qcdr(v256);
    v256 = qcdr(v256);
    v67 = qcar(v256);
    v257 = stack[-5];
    v256 = stack[-4];
    stack[0] = CC_cl_apply2ats1(env, 3, v67, v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-7];
    v256 = stack[-1];
    v256 = qcdr(v256);
    v256 = qcdr(v256);
    v256 = qcdr(v256);
    v67 = qcar(v256);
    v257 = stack[-5];
    v256 = stack[-4];
    v256 = CC_cl_apply2ats1(env, 3, v67, v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    {
        Lisp_Object v262 = stack[-3];
        Lisp_Object v263 = stack[-2];
        Lisp_Object v264 = stack[0];
        popv(8);
        return list4(v262, v263, v264, v256);
    }

v261:
    v257 = v67;
    v256 = elt(env, 8); /* or */
    if (v257 == v256) goto v92;
    v257 = v67;
    v256 = elt(env, 9); /* and */
    v256 = (v257 == v256 ? lisp_true : nil);
    goto v91;

v91:
    if (v256 == nil) goto v265;
    v256 = qvalue(elt(env, 2)); /* t */
    goto v266;

v266:
    if (v256 == nil) goto v55;
    v256 = qvalue(elt(env, 2)); /* t */
    goto v222;

v222:
    if (v256 == nil) goto v267;
    stack[-6] = v67;
    v256 = stack[-1];
    v256 = qcdr(v256);
    stack[-3] = v256;
    v256 = stack[-3];
    if (v256 == nil) goto v268;
    v256 = stack[-3];
    v256 = qcar(v256);
    v67 = v256;
    v257 = stack[-5];
    v256 = stack[-4];
    v256 = CC_cl_apply2ats1(env, 3, v67, v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-7];
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-7];
    stack[-1] = v256;
    stack[-2] = v256;
    goto v269;

v269:
    v256 = stack[-3];
    v256 = qcdr(v256);
    stack[-3] = v256;
    v256 = stack[-3];
    if (v256 == nil) goto v270;
    stack[0] = stack[-1];
    v256 = stack[-3];
    v256 = qcar(v256);
    v67 = v256;
    v257 = stack[-5];
    v256 = stack[-4];
    v256 = CC_cl_apply2ats1(env, 3, v67, v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-7];
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-7];
    v256 = Lrplacd(nil, stack[0], v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-7];
    v256 = stack[-1];
    v256 = qcdr(v256);
    stack[-1] = v256;
    goto v269;

v270:
    v256 = stack[-2];
    goto v271;

v271:
    {
        Lisp_Object v52 = stack[-6];
        popv(8);
        return cons(v52, v256);
    }

v268:
    v256 = qvalue(elt(env, 14)); /* nil */
    goto v271;

v267:
    stack[0] = stack[-5];
    v257 = stack[-1];
    v256 = stack[-4];
    v256 = cons(v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-7];
    {
        Lisp_Object v53 = stack[0];
        popv(8);
        fn = elt(env, 15); /* apply */
        return (*qfn2(fn))(qenv(fn), v53, v256);
    }

v55:
    v257 = v67;
    v256 = elt(env, 11); /* impl */
    if (v257 == v256) goto v71;
    v257 = v67;
    v256 = elt(env, 12); /* repl */
    if (v257 == v256) goto v272;
    v257 = v67;
    v256 = elt(env, 13); /* equiv */
    v256 = (v257 == v256 ? lisp_true : nil);
    goto v222;

v272:
    v256 = qvalue(elt(env, 2)); /* t */
    goto v222;

v71:
    v256 = qvalue(elt(env, 2)); /* t */
    goto v222;

v265:
    v257 = v67;
    v256 = elt(env, 10); /* not */
    v256 = (v257 == v256 ? lisp_true : nil);
    goto v266;

v92:
    v256 = qvalue(elt(env, 2)); /* t */
    goto v91;

v113:
    v256 = qvalue(elt(env, 2)); /* t */
    goto v112;

v13:
    v256 = qvalue(elt(env, 2)); /* t */
    goto v14;

v135:
    v256 = qvalue(elt(env, 2)); /* t */
    goto v195;

v46:
    v256 = stack[-1];
    goto v160;
/* error exit handlers */
v258:
    popv(8);
    return nil;
}



/* Code for checkdifference */

static Lisp_Object CC_checkdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v164, v165, v174;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checkdifference");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v165 = v32;
    v174 = v0;
/* end of prologue */
    v164 = v165;
    v123 = (Lisp_Object)1; /* 0 */
    if (v164 == v123) return onevalue(v174);
    v123 = elt(env, 1); /* difference */
    v164 = v174;
    return list3(v123, v164, v165);
}



/* Code for rtypepart */

static Lisp_Object CC_rtypepart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rtypepart");
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
    v25 = v0;
/* end of prologue */
    v25 = qcar(v25);
    fn = elt(env, 3); /* getrtype */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[0];
    if (v25 == nil) goto v150;
    v25 = elt(env, 1); /* yetunknowntype */
    { popv(1); return onevalue(v25); }

v150:
    v25 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v25); }
/* error exit handlers */
v88:
    popv(1);
    return nil;
}



/* Code for testord */

static Lisp_Object CC_testord(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v32)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v174, v16;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testord");
#endif
    if (stack >= stacklimit)
    {
        push2(v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v32);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v32;
    stack[-1] = v0;
/* end of prologue */

v147:
    v174 = stack[-1];
    if (v174 == nil) goto v160;
    v174 = stack[-1];
    v16 = qcar(v174);
    v174 = stack[0];
    v174 = qcar(v174);
    v174 = (Lisp_Object)lesseq2(v16, v174);
    nil = C_nil;
    if (exception_pending()) goto v137;
    v174 = v174 ? lisp_true : nil;
    env = stack[-2];
    if (v174 == nil) goto v123;
    v174 = stack[-1];
    v174 = qcdr(v174);
    stack[-1] = v174;
    v174 = stack[0];
    v174 = qcdr(v174);
    stack[0] = v174;
    goto v147;

v123:
    v174 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v174); }

v160:
    v174 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v174); }
/* error exit handlers */
v137:
    popv(3);
    return nil;
}



/* Code for gen!+can!+bas */

static Lisp_Object CC_genLcanLbas(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v282, v84;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gen+can+bas");
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
    v84 = (Lisp_Object)17; /* 1 */
    v282 = (Lisp_Object)17; /* 1 */
    v282 = cons(v84, v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    stack[-10] = v282;
    v84 = qvalue(elt(env, 1)); /* nil */
    v282 = (Lisp_Object)17; /* 1 */
    v282 = cons(v84, v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    stack[-8] = v282;
    v282 = (Lisp_Object)17; /* 1 */
    stack[-7] = v282;
    v84 = stack[-9];
    v282 = stack[-7];
    v282 = difference2(v84, v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    v282 = Lminusp(nil, v282);
    env = stack[-11];
    if (v282 == nil) goto v39;
    v282 = qvalue(elt(env, 1)); /* nil */
    { popv(12); return onevalue(v282); }

v39:
    v282 = (Lisp_Object)17; /* 1 */
    stack[-3] = v282;
    v84 = stack[-9];
    v282 = stack[-3];
    v282 = difference2(v84, v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    v282 = Lminusp(nil, v282);
    env = stack[-11];
    if (v282 == nil) goto v163;
    v282 = qvalue(elt(env, 1)); /* nil */
    goto v15;

v15:
    v282 = ncons(v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    stack[-5] = v282;
    stack[-6] = v282;
    goto v165;

v165:
    v282 = stack[-7];
    v282 = add1(v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    stack[-7] = v282;
    v84 = stack[-9];
    v282 = stack[-7];
    v282 = difference2(v84, v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    v282 = Lminusp(nil, v282);
    env = stack[-11];
    if (!(v282 == nil)) { Lisp_Object res = stack[-6]; popv(12); return onevalue(res); }
    stack[-4] = stack[-5];
    v282 = (Lisp_Object)17; /* 1 */
    stack[-3] = v282;
    v84 = stack[-9];
    v282 = stack[-3];
    v282 = difference2(v84, v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    v282 = Lminusp(nil, v282);
    env = stack[-11];
    if (v282 == nil) goto v283;
    v282 = qvalue(elt(env, 1)); /* nil */
    goto v284;

v284:
    v282 = ncons(v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    v282 = Lrplacd(nil, stack[-4], v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    v282 = stack[-5];
    v282 = qcdr(v282);
    stack[-5] = v282;
    goto v165;

v283:
    v84 = stack[-7];
    v282 = stack[-3];
    if (equal(v84, v282)) goto v251;
    v282 = stack[-8];
    goto v285;

v285:
    v282 = ncons(v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    stack[-1] = v282;
    stack[-2] = v282;
    goto v224;

v224:
    v282 = stack[-3];
    v282 = add1(v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    stack[-3] = v282;
    v84 = stack[-9];
    v282 = stack[-3];
    v282 = difference2(v84, v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    v282 = Lminusp(nil, v282);
    env = stack[-11];
    if (v282 == nil) goto v216;
    v282 = stack[-2];
    goto v284;

v216:
    stack[0] = stack[-1];
    v84 = stack[-7];
    v282 = stack[-3];
    if (equal(v84, v282)) goto v286;
    v282 = stack[-8];
    goto v132;

v132:
    v282 = ncons(v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    v282 = Lrplacd(nil, stack[0], v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    v282 = stack[-1];
    v282 = qcdr(v282);
    stack[-1] = v282;
    goto v224;

v286:
    v282 = stack[-10];
    goto v132;

v251:
    v282 = stack[-10];
    goto v285;

v163:
    v84 = stack[-7];
    v282 = stack[-3];
    if (equal(v84, v282)) goto v202;
    v282 = stack[-8];
    goto v197;

v197:
    v282 = ncons(v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    stack[-1] = v282;
    stack[-2] = v282;
    goto v29;

v29:
    v282 = stack[-3];
    v282 = add1(v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    stack[-3] = v282;
    v84 = stack[-9];
    v282 = stack[-3];
    v282 = difference2(v84, v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    v282 = Lminusp(nil, v282);
    env = stack[-11];
    if (v282 == nil) goto v112;
    v282 = stack[-2];
    goto v15;

v112:
    stack[0] = stack[-1];
    v84 = stack[-7];
    v282 = stack[-3];
    if (equal(v84, v282)) goto v114;
    v282 = stack[-8];
    goto v30;

v30:
    v282 = ncons(v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    v282 = Lrplacd(nil, stack[0], v282);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-11];
    v282 = stack[-1];
    v282 = qcdr(v282);
    stack[-1] = v282;
    goto v29;

v114:
    v282 = stack[-10];
    goto v30;

v202:
    v282 = stack[-10];
    goto v197;
/* error exit handlers */
v214:
    popv(12);
    return nil;
}



/* Code for cl_susiinter */

static Lisp_Object MS_CDECL CC_cl_susiinter(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v32,
                         Lisp_Object v51, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23, v225, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_susiinter");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susiinter");
#endif
    if (stack >= stacklimit)
    {
        push3(v51,v32,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v32,v51);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v51;
    stack[-4] = v32;
    v22 = v0;
/* end of prologue */
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    stack[0] = v22;
    goto v26;

v26:
    v22 = stack[0];
    if (v22 == nil) goto v198;
    v22 = stack[0];
    v22 = qcar(v22);
    v225 = v22;
    v22 = v225;
    v23 = qcar(v22);
    v22 = elt(env, 2); /* ignore */
    if (v23 == v22) goto v134;
    v22 = v225;
    v23 = qcar(v22);
    v22 = elt(env, 4); /* delete */
    if (v23 == v22) goto v36;
    v22 = v225;
    v23 = qcar(v22);
    v22 = elt(env, 5); /* add */
    if (!(v23 == v22)) goto v136;
    v22 = v225;
    v23 = qcdr(v22);
    v22 = stack[-5];
    v22 = cons(v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-6];
    stack[-5] = v22;
    goto v136;

v136:
    v22 = stack[0];
    v22 = qcdr(v22);
    stack[0] = v22;
    goto v26;

v36:
    v22 = v225;
    v22 = qcdr(v22);
    if (v22 == nil) goto v166;
    v22 = qvalue(elt(env, 3)); /* t */
    stack[-1] = v22;
    goto v136;

v166:
    v23 = stack[-3];
    v22 = stack[-4];
    fn = elt(env, 6); /* delqip */
    v22 = (*qfn2(fn))(qenv(fn), v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-6];
    stack[-4] = v22;
    goto v136;

v134:
    v22 = v225;
    v22 = qcdr(v22);
    if (v22 == nil) goto v154;
    v22 = qvalue(elt(env, 3)); /* t */
    stack[-2] = v22;
    v22 = v225;
    v23 = qcdr(v22);
    v22 = stack[-5];
    v22 = cons(v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-6];
    stack[-5] = v22;
    goto v136;

v154:
    v23 = stack[-3];
    v22 = elt(env, 2); /* ignore */
    fn = elt(env, 7); /* setcdr */
    v22 = (*qfn2(fn))(qenv(fn), v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-6];
    goto v136;

v198:
    v94 = stack[-4];
    v225 = stack[-5];
    v23 = stack[-2];
    v22 = stack[-1];
    popv(7);
    return list4(v94, v225, v23, v22);
/* error exit handlers */
v219:
    popv(7);
    return nil;
}



/* Code for rl_updcache */

static Lisp_Object MS_CDECL CC_rl_updcache(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v4;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rl_updcache");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_updcache");
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
    v126 = qvalue(elt(env, 1)); /* rl_bbl!* */
    stack[0] = v126;
    goto v24;

v24:
    v126 = stack[0];
    if (v126 == nil) goto v165;
    v126 = stack[0];
    v126 = qcar(v126);
    v4 = v126;
    v126 = qvalue(elt(env, 2)); /* nil */
    v126 = Lset(nil, v4, v126);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-1];
    v126 = stack[0];
    v126 = qcdr(v126);
    stack[0] = v126;
    goto v24;

v165:
    v126 = qvalue(elt(env, 3)); /* rl_cid!* */
    v4 = qcar(v126);
    v126 = elt(env, 4); /* rl_params */
    v126 = get(v4, v126);
    env = stack[-1];
    stack[0] = v126;
    goto v123;

v123:
    v126 = stack[0];
    if (v126 == nil) goto v47;
    v126 = stack[0];
    v126 = qcar(v126);
    v4 = v126;
    v4 = qcar(v4);
    v126 = qcdr(v126);
    v126 = Lset(nil, v4, v126);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-1];
    v126 = stack[0];
    v126 = qcdr(v126);
    stack[0] = v126;
    goto v123;

v47:
    v126 = qvalue(elt(env, 5)); /* rl_servl!* */
    stack[0] = v126;
    goto v36;

v36:
    v126 = stack[0];
    if (v126 == nil) goto v109;
    v126 = stack[0];
    v126 = qcar(v126);
    v4 = v126;
    v126 = qvalue(elt(env, 2)); /* nil */
    v126 = Lset(nil, v4, v126);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-1];
    v126 = stack[0];
    v126 = qcdr(v126);
    stack[0] = v126;
    goto v36;

v109:
    v126 = qvalue(elt(env, 3)); /* rl_cid!* */
    v4 = qcar(v126);
    v126 = elt(env, 6); /* rl_services */
    v126 = get(v4, v126);
    env = stack[-1];
    stack[0] = v126;
    goto v157;

v157:
    v126 = stack[0];
    if (v126 == nil) goto v169;
    v126 = stack[0];
    v126 = qcar(v126);
    v4 = v126;
    v4 = qcar(v4);
    v126 = qcdr(v126);
    v126 = Lset(nil, v4, v126);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-1];
    v126 = stack[0];
    v126 = qcdr(v126);
    stack[0] = v126;
    goto v157;

v169:
    v126 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v126); }
/* error exit handlers */
v203:
    popv(2);
    return nil;
}



/* Code for semanticml */

static Lisp_Object CC_semanticml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for semanticml");
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
    v50 = stack[0];
    v110 = Llength(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = (Lisp_Object)17; /* 1 */
    v50 = (Lisp_Object)greaterp2(v110, v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    v50 = v50 ? lisp_true : nil;
    env = stack[-1];
    if (v50 == nil) goto v147;
    v50 = elt(env, 1); /* "<apply>" */
    fn = elt(env, 15); /* printout */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = elt(env, 3); /* "<fn>" */
    fn = elt(env, 15); /* printout */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    goto v147;

v147:
    v50 = elt(env, 5); /* "<semantic>" */
    fn = elt(env, 15); /* printout */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = elt(env, 6); /* "<ci><mo>" */
    fn = elt(env, 15); /* printout */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = stack[0];
    v50 = qcar(v50);
    v50 = qcar(v50);
    v50 = Lprinc(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = elt(env, 7); /* "</mo></ci>" */
    v50 = Lprinc(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = elt(env, 8); /* "<annotation-xml encoding=""OpenMath"">" */
    fn = elt(env, 15); /* printout */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = elt(env, 9); /* "<" */
    fn = elt(env, 15); /* printout */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = stack[0];
    v50 = qcar(v50);
    v50 = qcdr(v50);
    v50 = qcar(v50);
    fn = elt(env, 17); /* list2string */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = elt(env, 10); /* ">" */
    v50 = Lprinc(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = elt(env, 11); /* "</annotation-xml>" */
    fn = elt(env, 15); /* printout */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = elt(env, 12); /* "</semantic>" */
    fn = elt(env, 15); /* printout */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = stack[0];
    v110 = Llength(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = (Lisp_Object)17; /* 1 */
    v50 = (Lisp_Object)greaterp2(v110, v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    v50 = v50 ? lisp_true : nil;
    env = stack[-1];
    if (v50 == nil) goto v175;
    v50 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = elt(env, 13); /* "</fn>" */
    fn = elt(env, 15); /* printout */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = stack[0];
    v50 = qcdr(v50);
    fn = elt(env, 18); /* multi_elem */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-1];
    v50 = elt(env, 14); /* "</apply>" */
    fn = elt(env, 15); /* printout */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v108;
    goto v175;

v175:
    v50 = nil;
    { popv(2); return onevalue(v50); }
/* error exit handlers */
v108:
    popv(2);
    return nil;
}



/* Code for boolvalue!* */

static Lisp_Object CC_boolvalueH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v162, v161;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for boolvalue*");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v161 = v0;
/* end of prologue */
    v162 = v161;
    if (v162 == nil) goto v24;
    v162 = (Lisp_Object)1; /* 0 */
    v162 = (v161 == v162 ? lisp_true : nil);
    v162 = (v162 == nil ? lisp_true : nil);
    return onevalue(v162);

v24:
    v162 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v162);
}



/* Code for ldf!-simp */

static Lisp_Object CC_ldfKsimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v33, v177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-simp");
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
    v33 = v0;
/* end of prologue */
    v5 = v33;
    if (v5 == nil) goto v24;
    v5 = v33;
    v5 = qcdr(v5);
    if (v5 == nil) goto v40;
    v5 = v33;
    fn = elt(env, 3); /* prepf */
    v5 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    fn = elt(env, 4); /* simp */
    v5 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    v5 = qcar(v5);
    stack[-1] = v5;
    v5 = stack[-1];
    if (!consp(v5)) goto v107;
    v5 = stack[-1];
    v5 = qcar(v5);
    v5 = (consp(v5) ? nil : lisp_true);
    goto v105;

v105:
    if (!(v5 == nil)) goto v17;
    stack[0] = stack[-1];
    v5 = stack[-1];
    fn = elt(env, 5); /* comfac */
    v5 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    v5 = qcdr(v5);
    fn = elt(env, 6); /* quotf */
    v5 = (*qfn2(fn))(qenv(fn), stack[0], v5);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    stack[-1] = v5;
    goto v17;

v17:
    v5 = stack[-1];
    fn = elt(env, 7); /* minusf */
    v5 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    if (v5 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v5 = stack[-1];
    {
        popv(3);
        fn = elt(env, 8); /* negf */
        return (*qfn1(fn))(qenv(fn), v5);
    }

v107:
    v5 = qvalue(elt(env, 2)); /* t */
    goto v105;

v40:
    v5 = v33;
    v5 = qcar(v5);
    v5 = qcar(v5);
    v177 = qcar(v5);
    v33 = (Lisp_Object)17; /* 1 */
    v5 = (Lisp_Object)17; /* 1 */
    v5 = acons(v177, v33, v5);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    v5 = ncons(v5);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    fn = elt(env, 3); /* prepf */
    v5 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    fn = elt(env, 4); /* simp */
    v5 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v45;
    v5 = qcar(v5);
    { popv(3); return onevalue(v5); }

v24:
    v5 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v5); }
/* error exit handlers */
v45:
    popv(3);
    return nil;
}



setup_type const u28_setup[] =
{
    {"polynomread",             CC_polynomread, too_many_1,    wrong_no_1},
    {"giintgcd",                too_few_2,      CC_giintgcd,   wrong_no_2},
    {"makecoeffpairshom",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_makecoeffpairshom},
    {"ithlistelem",             too_few_2,      CC_ithlistelem,wrong_no_2},
    {"testpr",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_testpr},
    {"dipcondense",             CC_dipcondense, too_many_1,    wrong_no_1},
    {"size_of_matrix",          CC_size_of_matrix,too_many_1,  wrong_no_1},
    {"f2dip1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_f2dip1},
    {"get:const",               too_few_2,      CC_getTconst,  wrong_no_2},
    {"r2findindex1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_r2findindex1},
    {"list-evaluate",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_listKevaluate},
    {"getupper",                CC_getupper,    too_many_1,    wrong_no_1},
    {"z-roads",                 CC_zKroads,     too_many_1,    wrong_no_1},
    {"split_cov_cont_ids",      CC_split_cov_cont_ids,too_many_1,wrong_no_1},
    {"polynomwrite",            CC_polynomwrite,too_many_1,    wrong_no_1},
    {"pasf_subfof1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_subfof1},
    {"listrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_listrd},
    {"compl",                   too_few_2,      CC_compl,      wrong_no_2},
    {"spcol_dim",               CC_spcol_dim,   too_many_1,    wrong_no_1},
    {"dm-gt",                   too_few_2,      CC_dmKgt,      wrong_no_2},
    {"groebspolynom3",          too_few_2,      CC_groebspolynom3,wrong_no_2},
    {"mkexdf",                  CC_mkexdf,      too_many_1,    wrong_no_1},
    {"r2oaddspecies",           too_few_2,      CC_r2oaddspecies,wrong_no_2},
    {"mkassign",                too_few_2,      CC_mkassign,   wrong_no_2},
    {"vunion",                  too_few_2,      CC_vunion,     wrong_no_2},
    {"subs2p",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_subs2p},
    {"mod_eval_uni_poly",       too_few_2,      CC_mod_eval_uni_poly,wrong_no_2},
    {"preptayexp",              CC_preptayexp,  too_many_1,    wrong_no_1},
    {"domainvalchk",            too_few_2,      CC_domainvalchk,wrong_no_2},
    {"enter-sorted",            too_few_2,      CC_enterKsorted,wrong_no_2},
    {"matrixom",                CC_matrixom,    too_many_1,    wrong_no_1},
    {"countof",                 too_few_2,      CC_countof,    wrong_no_2},
    {"remdiff",                 CC_remdiff,     too_many_1,    wrong_no_1},
    {"::quotient",              too_few_2,      CC_TTquotient, wrong_no_2},
    {"mktails",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mktails},
    {"mv-compact2",             too_few_2,      CC_mvKcompact2,wrong_no_2},
    {"msolve-poly1",            too_few_2,      CC_msolveKpoly1,wrong_no_2},
    {"reduce-mod-eigf",         too_few_2,      CC_reduceKmodKeigf,wrong_no_2},
    {"cl_apply2ats1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_apply2ats1},
    {"checkdifference",         too_few_2,      CC_checkdifference,wrong_no_2},
    {"rtypepart",               CC_rtypepart,   too_many_1,    wrong_no_1},
    {"testord",                 too_few_2,      CC_testord,    wrong_no_2},
    {"gen+can+bas",             CC_genLcanLbas, too_many_1,    wrong_no_1},
    {"cl_susiinter",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiinter},
    {"rl_updcache",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_updcache},
    {"semanticml",              CC_semanticml,  too_many_1,    wrong_no_1},
    {"boolvalue*",              CC_boolvalueH,  too_many_1,    wrong_no_1},
    {"ldf-simp",                CC_ldfKsimp,    too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u28", (two_args *)"4841 5282130 1452768", 0}
};

/* end of generated code */
