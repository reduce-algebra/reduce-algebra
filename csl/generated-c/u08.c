
/* $destdir\u08.c        Machine generated C code */

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


/* Code for letmtr3 */

static Lisp_Object MS_CDECL CC_letmtr3(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v77, v78, v79, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "letmtr3");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for letmtr3");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    v76 = stack[-3];
    v76 = qcdr(v76);
    v76 = qcdr(v76);
    if (v76 == nil) goto v81;
    v77 = stack[-1];
    v76 = elt(env, 1); /* sparsemat */
    if (!consp(v77)) goto v82;
    v77 = qcar(v77);
    if (!(v77 == v76)) goto v82;
    v76 = stack[-3];
    v76 = qcdr(v76);
    fn = elt(env, 12); /* revlis */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    stack[-4] = v76;
    fn = elt(env, 13); /* numlis */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    if (v76 == nil) goto v84;
    v76 = stack[-4];
    v77 = Llength(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    v76 = (Lisp_Object)33; /* 2 */
    v76 = Lneq(nil, v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    goto v85;

v85:
    if (v76 == nil) goto v86;
    v80 = elt(env, 7); /* "Syntax error:" */
    v79 = stack[-3];
    v78 = elt(env, 8); /* "invalid" */
    v77 = qvalue(elt(env, 9)); /* nil */
    v76 = elt(env, 10); /* hold */
    {
        popv(6);
        fn = elt(env, 14); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v80, v79, v78, v77, v76);
    }

v86:
    v76 = stack[-1];
    v76 = qcdr(v76);
    v77 = qcar(v76);
    v76 = stack[-4];
    v76 = qcar(v76);
    v76 = *(Lisp_Object *)((char *)v77 + (CELL-TAG_VECTOR) + ((int32_t)v76/(16/CELL)));
    v79 = v76;
    v76 = v79;
    if (v76 == nil) goto v87;
    v76 = stack[-4];
    v76 = qcdr(v76);
    v77 = qcar(v76);
    v76 = v79;
    v76 = Latsoc(nil, v77, v76);
    v78 = v76;
    v76 = v78;
    if (v76 == nil) goto v88;
    v77 = stack[-2];
    v76 = (Lisp_Object)1; /* 0 */
    if (v77 == v76) goto v89;
    v76 = qvalue(elt(env, 9)); /* nil */
    goto v90;

v90:
    if (v76 == nil) goto v91;
    v76 = v79;
    v76 = qcdr(v76);
    v76 = qcdr(v76);
    if (v76 == nil) goto v92;
    stack[0] = v79;
    v76 = v78;
    v77 = v79;
    v76 = Ldelete(nil, v76, v77);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    v76 = qcdr(v76);
    v76 = Lrplacd(nil, stack[0], v76);
    nil = C_nil;
    if (exception_pending()) goto v83;
    goto v93;

v93:
    v76 = nil;
    { popv(6); return onevalue(v76); }

v92:
    v76 = stack[-1];
    v76 = qcdr(v76);
    v77 = qcar(v76);
    v76 = stack[-4];
    v76 = qcar(v76);
    v78 = qvalue(elt(env, 9)); /* nil */
    *(Lisp_Object *)((char *)v77 + (CELL-TAG_VECTOR) + ((int32_t)v76/(16/CELL))) = v78;
    goto v93;

v91:
    v77 = v78;
    v76 = stack[-2];
    v76 = Lrplacd(nil, v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v83;
    goto v93;

v89:
    v77 = stack[0];
    v76 = elt(env, 11); /* cx */
    v76 = (v77 == v76 ? lisp_true : nil);
    v76 = (v76 == nil ? lisp_true : nil);
    goto v90;

v88:
    v77 = stack[-2];
    v76 = (Lisp_Object)1; /* 0 */
    if (v77 == v76) goto v94;
    v76 = qvalue(elt(env, 9)); /* nil */
    goto v95;

v95:
    if (!(v76 == nil)) goto v93;
    v76 = stack[-4];
    v76 = qcdr(v76);
    v77 = qcar(v76);
    v78 = v79;
    v76 = stack[-2];
    fn = elt(env, 15); /* sortcolelem */
    v76 = (*qfnn(fn))(qenv(fn), 3, v77, v78, v76);
    nil = C_nil;
    if (exception_pending()) goto v83;
    goto v93;

v94:
    v77 = stack[0];
    v76 = elt(env, 11); /* cx */
    v76 = (v77 == v76 ? lisp_true : nil);
    v76 = (v76 == nil ? lisp_true : nil);
    goto v95;

v87:
    v77 = stack[-2];
    v76 = (Lisp_Object)1; /* 0 */
    if (v77 == v76) goto v96;
    v76 = qvalue(elt(env, 9)); /* nil */
    goto v97;

v97:
    if (!(v76 == nil)) goto v93;
    v76 = stack[-1];
    v76 = qcdr(v76);
    stack[-3] = qcar(v76);
    v76 = stack[-4];
    stack[-1] = qcar(v76);
    v76 = qvalue(elt(env, 9)); /* nil */
    stack[0] = ncons(v76);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    v76 = stack[-4];
    v76 = qcdr(v76);
    v77 = qcar(v76);
    v76 = stack[-2];
    v76 = cons(v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    v76 = list2(stack[0], v76);
    nil = C_nil;
    if (exception_pending()) goto v83;
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v76;
    goto v93;

v96:
    v77 = stack[0];
    v76 = elt(env, 11); /* cx */
    v76 = (v77 == v76 ? lisp_true : nil);
    v76 = (v76 == nil ? lisp_true : nil);
    goto v97;

v84:
    v76 = qvalue(elt(env, 6)); /* t */
    goto v85;

v82:
    v78 = elt(env, 2); /* "Matrix" */
    v76 = stack[-3];
    v77 = qcar(v76);
    v76 = elt(env, 3); /* "not set" */
    v76 = list3(v78, v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    v77 = v76;
    v76 = v77;
    qvalue(elt(env, 4)) = v76; /* errmsg!* */
    v76 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v76 == nil)) goto v98;
    v76 = v77;
    fn = elt(env, 16); /* lprie */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    goto v98;

v98:
    v76 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    goto v86;

v81:
    v77 = stack[-1];
    v76 = elt(env, 1); /* sparsemat */
    if (!consp(v77)) goto v99;
    v77 = qcar(v77);
    if (!(v77 == v76)) goto v99;
    v76 = stack[-3];
    v76 = qcdr(v76);
    fn = elt(env, 12); /* revlis */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    stack[-4] = v76;
    fn = elt(env, 13); /* numlis */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    if (v76 == nil) goto v100;
    v76 = stack[-4];
    v77 = Llength(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    v76 = (Lisp_Object)17; /* 1 */
    v76 = Lneq(nil, v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    goto v101;

v101:
    if (v76 == nil) goto v102;
    v80 = elt(env, 7); /* "Syntax error:" */
    v79 = stack[-3];
    v78 = elt(env, 8); /* "invalid" */
    v77 = qvalue(elt(env, 9)); /* nil */
    v76 = elt(env, 10); /* hold */
    {
        popv(6);
        fn = elt(env, 14); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v80, v79, v78, v77, v76);
    }

v102:
    v76 = stack[-1];
    v76 = qcdr(v76);
    v78 = qcar(v76);
    v76 = stack[-3];
    v76 = qcdr(v76);
    v77 = qcar(v76);
    v76 = stack[-2];
    *(Lisp_Object *)((char *)v78 + (CELL-TAG_VECTOR) + ((int32_t)v77/(16/CELL))) = v76;
    goto v93;

v100:
    v76 = qvalue(elt(env, 6)); /* t */
    goto v101;

v99:
    v78 = elt(env, 2); /* "Matrix" */
    v76 = stack[-3];
    v77 = qcar(v76);
    v76 = elt(env, 3); /* "not set" */
    v76 = list3(v78, v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    v77 = v76;
    v76 = v77;
    qvalue(elt(env, 4)) = v76; /* errmsg!* */
    v76 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v76 == nil)) goto v103;
    v76 = v77;
    fn = elt(env, 16); /* lprie */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-5];
    goto v103;

v103:
    v76 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v83;
    goto v102;
/* error exit handlers */
v83:
    popv(6);
    return nil;
}



/* Code for comm_kernels1 */

static Lisp_Object CC_comm_kernels1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comm_kernels1");
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
    stack[-2] = v1;
    v111 = v0;
/* end of prologue */

v113:
    v112 = v111;
    if (!consp(v112)) goto v114;
    v112 = v111;
    v112 = qcar(v112);
    v112 = (consp(v112) ? nil : lisp_true);
    goto v115;

v115:
    if (!(v112 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v112 = v111;
    v112 = qcar(v112);
    v112 = qcar(v112);
    v112 = qcar(v112);
    stack[-3] = v112;
    v112 = v111;
    v112 = qcar(v112);
    stack[-1] = qcdr(v112);
    stack[0] = qcdr(v111);
    v112 = stack[-3];
    v111 = stack[-2];
    v111 = Lmemq(nil, v112, v111);
    if (!(v111 == nil)) goto v71;
    v111 = qvalue(elt(env, 2)); /* !*ncmp */
    if (v111 == nil) goto v116;
    v111 = stack[-3];
    fn = elt(env, 3); /* noncomp1 */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    if (!(v111 == nil)) goto v71;

v116:
    v111 = stack[-3];
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v111 = Lappend(nil, stack[-2], v111);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    goto v117;

v117:
    v112 = CC_comm_kernels1(env, stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v111 = stack[-1];
    stack[-2] = v112;
    goto v113;

v71:
    v111 = stack[-2];
    goto v117;

v114:
    v112 = qvalue(elt(env, 1)); /* t */
    goto v115;
/* error exit handlers */
v69:
    popv(5);
    return nil;
}



/* Code for fortranop */

static Lisp_Object CC_fortranop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v121, v122;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fortranop");
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
    v122 = v0;
/* end of prologue */
    v121 = v122;
    v120 = elt(env, 1); /* !*fortranop!* */
    v120 = get(v121, v120);
    if (v120 == nil) return onevalue(v122);
    else return onevalue(v120);
}



/* Code for ckpreci!# */

static Lisp_Object CC_ckpreciC(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135, v136, v137, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ckpreci#");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v60 = v0;
/* end of prologue */
    v135 = v60;
    v136 = qcar(v135);
    v135 = elt(env, 1); /* times */
    if (!consp(v136)) goto v107;
    v136 = qcar(v136);
    if (!(v136 == v135)) goto v107;
    v136 = elt(env, 2); /* i */
    v135 = v60;
    v135 = qcar(v135);
    v135 = qcdr(v135);
    v135 = Lmemq(nil, v136, v135);
    v137 = v135;
    goto v75;

v75:
    v135 = v60;
    v135 = qcdr(v135);
    v136 = qcar(v135);
    v135 = elt(env, 1); /* times */
    if (!consp(v136)) goto v108;
    v136 = qcar(v136);
    if (!(v136 == v135)) goto v108;
    v136 = elt(env, 2); /* i */
    v135 = v60;
    v135 = qcdr(v135);
    v135 = qcar(v135);
    v135 = qcdr(v135);
    v135 = Lmemq(nil, v136, v135);
    goto v138;

v138:
    v136 = v135;
    v135 = qvalue(elt(env, 4)); /* !*complex */
    if (v135 == nil) goto v139;
    v135 = v137;
    if (v135 == nil) goto v140;
    v135 = v136;
    if (!(v135 == nil)) goto v140;
    v135 = v60;
    v135 = qcar(v135);
    v135 = qcdr(v135);
    v136 = v60;
    v136 = qcdr(v136);
    v136 = qcar(v136);
    {
        fn = elt(env, 5); /* ckprec2!# */
        return (*qfn2(fn))(qenv(fn), v135, v136);
    }

v140:
    v135 = v136;
    if (v135 == nil) goto v141;
    v135 = v137;
    if (!(v135 == nil)) goto v141;
    v135 = v60;
    v135 = qcdr(v135);
    v135 = qcar(v135);
    v135 = qcdr(v135);
    v136 = v60;
    v136 = qcar(v136);
    {
        fn = elt(env, 5); /* ckprec2!# */
        return (*qfn2(fn))(qenv(fn), v135, v136);
    }

v141:
    v135 = nil;
    return onevalue(v135);

v139:
    v135 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v135);

v108:
    v135 = qvalue(elt(env, 3)); /* nil */
    goto v138;

v107:
    v135 = qvalue(elt(env, 3)); /* nil */
    v137 = v135;
    goto v75;
}



/* Code for compactfmatch2 */

static Lisp_Object CC_compactfmatch2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v110;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compactfmatch2");
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
    v74 = stack[0];
    if (!consp(v74)) goto v143;
    v74 = stack[0];
    v110 = qcar(v74);
    v74 = elt(env, 2); /* !~ */
    if (v110 == v74) goto v115;
    v74 = stack[0];
    v74 = qcar(v74);
    stack[-1] = CC_compactfmatch2(env, v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-2];
    v74 = stack[0];
    v74 = qcdr(v74);
    v74 = CC_compactfmatch2(env, v74);
    nil = C_nil;
    if (exception_pending()) goto v144;
    {
        Lisp_Object v117 = stack[-1];
        popv(3);
        return Lappend(nil, v117, v74);
    }

v115:
    v74 = stack[0];
    popv(3);
    return ncons(v74);

v143:
    v74 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v74); }
/* error exit handlers */
v144:
    popv(3);
    return nil;
}



/* Code for divd */

static Lisp_Object CC_divd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for divd");
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
    stack[-3] = nil;
    goto v11;

v11:
    v155 = stack[-1];
    if (v155 == nil) goto v114;
    v155 = stack[-2];
    if (v155 == nil) goto v157;
    v155 = stack[-2];
    if (!consp(v155)) goto v116;
    v155 = stack[-2];
    v155 = qcar(v155);
    v155 = (consp(v155) ? nil : lisp_true);
    goto v158;

v158:
    if (v155 == nil) goto v64;
    stack[0] = stack[-3];
    v156 = stack[-2];
    v155 = stack[-1];
    fn = elt(env, 6); /* divdm */
    v155 = (*qfn2(fn))(qenv(fn), v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-4];
    {
        Lisp_Object v58 = stack[0];
        popv(5);
        fn = elt(env, 7); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v58, v155);
    }

v64:
    v155 = stack[-2];
    v155 = qcar(v155);
    stack[0] = qcar(v155);
    v155 = stack[-2];
    v155 = qcar(v155);
    v156 = qcdr(v155);
    v155 = stack[-1];
    v156 = CC_divd(env, v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-4];
    v155 = stack[-3];
    v155 = acons(stack[0], v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-4];
    stack[-3] = v155;
    v155 = stack[-2];
    v155 = qcdr(v155);
    stack[-2] = v155;
    goto v11;

v116:
    v155 = qvalue(elt(env, 5)); /* t */
    goto v158;

v157:
    v155 = stack[-3];
    {
        popv(5);
        fn = elt(env, 7); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v155);
    }

v114:
    v155 = stack[-2];
    if (v155 == nil) goto v160;
    stack[0] = stack[-3];
    v155 = elt(env, 4); /* "Zero divisor" */
    v156 = v155;
    v155 = v156;
    qvalue(elt(env, 2)) = v155; /* errmsg!* */
    v155 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v155 == nil)) goto v103;
    v155 = v156;
    fn = elt(env, 8); /* lprie */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-4];
    goto v103;

v103:
    v155 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-4];
    v155 = nil;
    {
        Lisp_Object v57 = stack[0];
        popv(5);
        fn = elt(env, 7); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v57, v155);
    }

v160:
    stack[0] = stack[-3];
    v155 = elt(env, 1); /* "0/0 formed" */
    v156 = v155;
    v155 = v156;
    qvalue(elt(env, 2)) = v155; /* errmsg!* */
    v155 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v155 == nil)) goto v161;
    v155 = v156;
    fn = elt(env, 8); /* lprie */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-4];
    goto v161;

v161:
    v155 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-4];
    v155 = nil;
    {
        Lisp_Object v162 = stack[0];
        popv(5);
        fn = elt(env, 7); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v162, v155);
    }
/* error exit handlers */
v159:
    popv(5);
    return nil;
}



/* Code for dp_sum */

static Lisp_Object CC_dp_sum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v53, v167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_sum");
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

v113:
    v55 = stack[-1];
    if (v55 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v55 = stack[0];
    if (v55 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v55 = stack[-1];
    fn = elt(env, 1); /* dp_lmon */
    stack[-2] = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v55 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    fn = elt(env, 2); /* mo_compare */
    v55 = (*qfn2(fn))(qenv(fn), stack[-2], v55);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v167 = v55;
    v53 = v167;
    v55 = (Lisp_Object)17; /* 1 */
    if (v53 == v55) goto v130;
    v53 = v167;
    v55 = (Lisp_Object)-15; /* -1 */
    if (v53 == v55) goto v140;
    v55 = stack[-1];
    fn = elt(env, 3); /* dp_lc */
    stack[-2] = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v55 = stack[0];
    fn = elt(env, 3); /* dp_lc */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    fn = elt(env, 4); /* bc_sum */
    v55 = (*qfn2(fn))(qenv(fn), stack[-2], v55);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    stack[-2] = v55;
    v55 = stack[-2];
    fn = elt(env, 5); /* bc_zero!? */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    if (v55 == nil) goto v168;
    v55 = stack[-1];
    v53 = qcdr(v55);
    v55 = stack[0];
    v55 = qcdr(v55);
    stack[-1] = v53;
    stack[0] = v55;
    goto v113;

v168:
    v55 = stack[-1];
    fn = elt(env, 1); /* dp_lmon */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    fn = elt(env, 6); /* dp_term */
    stack[-2] = (*qfn2(fn))(qenv(fn), stack[-2], v55);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v55 = stack[-1];
    v53 = qcdr(v55);
    v55 = stack[0];
    v55 = qcdr(v55);
    v55 = CC_dp_sum(env, v53, v55);
    nil = C_nil;
    if (exception_pending()) goto v98;
    {
        Lisp_Object v169 = stack[-2];
        popv(4);
        return cons(v169, v55);
    }

v140:
    v55 = stack[0];
    stack[-2] = qcar(v55);
    v53 = stack[-1];
    v55 = stack[0];
    v55 = qcdr(v55);
    v55 = CC_dp_sum(env, v53, v55);
    nil = C_nil;
    if (exception_pending()) goto v98;
    {
        Lisp_Object v170 = stack[-2];
        popv(4);
        return cons(v170, v55);
    }

v130:
    v55 = stack[-1];
    stack[-2] = qcar(v55);
    v55 = stack[-1];
    v53 = qcdr(v55);
    v55 = stack[0];
    v55 = CC_dp_sum(env, v53, v55);
    nil = C_nil;
    if (exception_pending()) goto v98;
    {
        Lisp_Object v171 = stack[-2];
        popv(4);
        return cons(v171, v55);
    }
/* error exit handlers */
v98:
    popv(4);
    return nil;
}



/* Code for ord */

static Lisp_Object CC_ord(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v173, v154, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ord");
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
    v81 = v0;
/* end of prologue */
    v154 = qvalue(elt(env, 1)); /* ordering */
    v173 = elt(env, 2); /* lex */
    if (v154 == v173) goto v121;
    v173 = v81;
    v173 = qcar(v173);
    { popv(1); return onevalue(v173); }

v121:
    v173 = elt(env, 3); /* plus */
    v154 = v81;
    v173 = cons(v173, v154);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); /* eval */
        return (*qfn1(fn))(qenv(fn), v173);
    }
/* error exit handlers */
v138:
    popv(1);
    return nil;
}



/* Code for vecp */

static Lisp_Object CC_vecp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v159, v58, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vecp");
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
    v58 = v0;
/* end of prologue */
    v179 = v58;
    if (v179 == nil) goto v118;
    v179 = v58;
    v179 = (is_number(v179) ? lisp_true : nil);
    goto v180;

v180:
    if (v179 == nil) goto v115;
    v179 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v179); }

v115:
    v179 = v58;
    if (!consp(v179)) goto v75;
    v179 = v58;
    v179 = Lthreevectorp(nil, v179);
    env = stack[0];
    if (v179 == nil) goto v70;
    v179 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v179); }

v70:
    v179 = v58;
    v179 = qcar(v179);
    v57 = v179;
    if (!consp(v179)) goto v181;
    v179 = qvalue(elt(env, 2)); /* nil */
    goto v109;

v109:
    if (v179 == nil) goto v149;
    v179 = v58;
    v179 = qcdr(v179);
    v179 = qcar(v179);
    {
        popv(1);
        fn = elt(env, 8); /* isvectorindex */
        return (*qfn1(fn))(qenv(fn), v179);
    }

v149:
    v159 = v57;
    v179 = elt(env, 5); /* vectorfn */
    v179 = Lflagp(nil, v159, v179);
    env = stack[0];
    if (v179 == nil) goto v182;
    v179 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v179); }

v182:
    v159 = v57;
    v179 = elt(env, 6); /* varithop */
    v179 = Lflagp(nil, v159, v179);
    env = stack[0];
    if (v179 == nil) goto v61;
    v179 = qvalue(elt(env, 1)); /* t */
    goto v64;

v64:
    if (v179 == nil) goto v183;
    v179 = v58;
    v179 = qcdr(v179);
    {
        popv(1);
        fn = elt(env, 9); /* hasonevector */
        return (*qfn1(fn))(qenv(fn), v179);
    }

v183:
    v179 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v179); }

v61:
    v159 = v57;
    v179 = elt(env, 7); /* vectormapping */
    v179 = Lflagp(nil, v159, v179);
    env = stack[0];
    goto v64;

v181:
    v159 = v57;
    v179 = elt(env, 3); /* rtype */
    v159 = get(v159, v179);
    env = stack[0];
    v179 = elt(env, 4); /* !3vector */
    v179 = (v159 == v179 ? lisp_true : nil);
    goto v109;

v75:
    v159 = v58;
    v179 = elt(env, 3); /* rtype */
    v159 = get(v159, v179);
    env = stack[0];
    v179 = elt(env, 4); /* !3vector */
    if (v159 == v179) goto v107;
    v179 = v58;
        popv(1);
        return Lthreevectorp(nil, v179);

v107:
    v179 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v179); }

v118:
    v179 = qvalue(elt(env, 1)); /* t */
    goto v180;
}



/* Code for pappl_pv */

static Lisp_Object CC_pappl_pv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pappl_pv");
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
    push(nil);
/* copy arguments values to proper place */
    v163 = v1;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = v163;
    v163 = stack[-5];
    if (v163 == nil) goto v134;
    v163 = stack[-5];
    v163 = qcar(v163);
    v186 = v163;
    stack[0] = qcar(v186);
    v186 = stack[-4];
    v163 = qcdr(v163);
    fn = elt(env, 2); /* pappl0 */
    v163 = (*qfn2(fn))(qenv(fn), v186, v163);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-6];
    v163 = cons(stack[0], v163);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-6];
    v163 = ncons(v163);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-6];
    stack[-2] = v163;
    stack[-3] = v163;
    goto v114;

v114:
    v163 = stack[-5];
    v163 = qcdr(v163);
    stack[-5] = v163;
    v163 = stack[-5];
    if (v163 == nil) goto v104;
    stack[-1] = stack[-2];
    v163 = stack[-5];
    v163 = qcar(v163);
    v186 = v163;
    stack[0] = qcar(v186);
    v186 = stack[-4];
    v163 = qcdr(v163);
    fn = elt(env, 2); /* pappl0 */
    v163 = (*qfn2(fn))(qenv(fn), v186, v163);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-6];
    v163 = cons(stack[0], v163);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-6];
    v163 = ncons(v163);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-6];
    v163 = Lrplacd(nil, stack[-1], v163);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-6];
    v163 = stack[-2];
    v163 = qcdr(v163);
    stack[-2] = v163;
    goto v114;

v104:
    v163 = stack[-3];
    goto v115;

v115:
    {
        popv(7);
        fn = elt(env, 3); /* pv_sort */
        return (*qfn1(fn))(qenv(fn), v163);
    }

v134:
    v163 = qvalue(elt(env, 1)); /* nil */
    goto v115;
/* error exit handlers */
v149:
    popv(7);
    return nil;
}



/* Code for general!-plus!-mod!-p */

static Lisp_Object CC_generalKplusKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210, v211;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-plus-mod-p");
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
    stack[0] = nil;
    goto v11;

v11:
    v210 = stack[-3];
    if (v210 == nil) goto v134;
    v210 = stack[-2];
    if (v210 == nil) goto v212;
    v210 = stack[-3];
    if (!consp(v210)) goto v110;
    v210 = stack[-3];
    v210 = qcar(v210);
    v210 = (consp(v210) ? nil : lisp_true);
    goto v74;

v74:
    if (v210 == nil) goto v178;
    v210 = stack[-2];
    if (!consp(v210)) goto v213;
    v210 = stack[-2];
    v210 = qcar(v210);
    v210 = (consp(v210) ? nil : lisp_true);
    goto v153;

v153:
    if (v210 == nil) goto v214;
    v211 = stack[-3];
    v210 = stack[-2];
    fn = elt(env, 3); /* general!-modular!-plus */
    v210 = (*qfn2(fn))(qenv(fn), v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-5];
    v211 = v210;
    v210 = v211;
    v210 = (Lisp_Object)zerop(v210);
    v210 = v210 ? lisp_true : nil;
    env = stack[-5];
    if (v210 == nil) goto v127;
    v210 = qvalue(elt(env, 2)); /* nil */
    goto v100;

v100:
    {
        Lisp_Object v216 = stack[0];
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v216, v210);
    }

v127:
    v210 = v211;
    goto v100;

v214:
    v210 = stack[-2];
    v211 = qcar(v210);
    v210 = stack[0];
    v210 = cons(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-5];
    stack[0] = v210;
    v210 = stack[-2];
    v210 = qcdr(v210);
    stack[-2] = v210;
    goto v11;

v213:
    v210 = qvalue(elt(env, 1)); /* t */
    goto v153;

v178:
    v210 = stack[-2];
    if (!consp(v210)) goto v217;
    v210 = stack[-2];
    v210 = qcar(v210);
    v210 = (consp(v210) ? nil : lisp_true);
    goto v123;

v123:
    if (v210 == nil) goto v159;
    v210 = stack[-3];
    v211 = qcar(v210);
    v210 = stack[0];
    v210 = cons(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-5];
    stack[0] = v210;
    v210 = stack[-3];
    v210 = qcdr(v210);
    stack[-3] = v210;
    goto v11;

v159:
    v210 = stack[-3];
    v210 = qcar(v210);
    v211 = qcar(v210);
    v210 = stack[-2];
    v210 = qcar(v210);
    v210 = qcar(v210);
    if (equal(v211, v210)) goto v218;
    v210 = stack[-3];
    v210 = qcar(v210);
    v210 = qcar(v210);
    v211 = qcar(v210);
    v210 = stack[-2];
    v210 = qcar(v210);
    v210 = qcar(v210);
    v210 = qcar(v210);
    if (equal(v211, v210)) goto v219;
    v210 = qvalue(elt(env, 2)); /* nil */
    goto v220;

v220:
    if (!(v210 == nil)) goto v31;
    v210 = stack[-3];
    v210 = qcar(v210);
    v210 = qcar(v210);
    v211 = qcar(v210);
    v210 = stack[-2];
    v210 = qcar(v210);
    v210 = qcar(v210);
    v210 = qcar(v210);
    if (equal(v211, v210)) goto v221;
    v210 = stack[-3];
    v210 = qcar(v210);
    v210 = qcar(v210);
    v211 = qcar(v210);
    v210 = stack[-2];
    v210 = qcar(v210);
    v210 = qcar(v210);
    v210 = qcar(v210);
    fn = elt(env, 5); /* ordop */
    v210 = (*qfn2(fn))(qenv(fn), v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-5];
    goto v87;

v87:
    if (!(v210 == nil)) goto v31;
    v210 = stack[-2];
    v211 = qcar(v210);
    v210 = stack[0];
    v210 = cons(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-5];
    stack[0] = v210;
    v210 = stack[-2];
    v210 = qcdr(v210);
    stack[-2] = v210;
    goto v11;

v31:
    v210 = stack[-3];
    v211 = qcar(v210);
    v210 = stack[0];
    v210 = cons(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-5];
    stack[0] = v210;
    v210 = stack[-3];
    v210 = qcdr(v210);
    stack[-3] = v210;
    goto v11;

v221:
    v210 = qvalue(elt(env, 2)); /* nil */
    goto v87;

v219:
    v210 = stack[-3];
    v210 = qcar(v210);
    v210 = qcar(v210);
    v211 = qcdr(v210);
    v210 = stack[-2];
    v210 = qcar(v210);
    v210 = qcar(v210);
    v210 = qcdr(v210);
    v210 = ((intptr_t)v211 > (intptr_t)v210) ? lisp_true : nil;
    goto v220;

v218:
    stack[-4] = stack[0];
    v210 = stack[-3];
    v210 = qcar(v210);
    stack[-1] = qcar(v210);
    v210 = stack[-3];
    v210 = qcar(v210);
    v211 = qcdr(v210);
    v210 = stack[-2];
    v210 = qcar(v210);
    v210 = qcdr(v210);
    stack[0] = CC_generalKplusKmodKp(env, v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-5];
    v210 = stack[-3];
    v211 = qcdr(v210);
    v210 = stack[-2];
    v210 = qcdr(v210);
    v210 = CC_generalKplusKmodKp(env, v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-5];
    fn = elt(env, 6); /* adjoin!-term */
    v210 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-5];
    {
        Lisp_Object v222 = stack[-4];
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v222, v210);
    }

v217:
    v210 = qvalue(elt(env, 1)); /* t */
    goto v123;

v110:
    v210 = qvalue(elt(env, 1)); /* t */
    goto v74;

v212:
    v211 = stack[0];
    v210 = stack[-3];
    {
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v211, v210);
    }

v134:
    v211 = stack[0];
    v210 = stack[-2];
    {
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v211, v210);
    }
/* error exit handlers */
v215:
    popv(6);
    return nil;
}



/* Code for ofsf_clnegrel */

static Lisp_Object CC_ofsf_clnegrel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_clnegrel");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v134 = v1;
    v120 = v0;
/* end of prologue */
    if (!(v134 == nil)) return onevalue(v120);
    v134 = v120;
    {
        fn = elt(env, 1); /* ofsf_lnegrel */
        return (*qfn1(fn))(qenv(fn), v134);
    }
}



/* Code for totallessp */

static Lisp_Object CC_totallessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for totallessp");
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
    v160 = v1;
    v209 = v0;
/* end of prologue */
    fn = elt(env, 2); /* totalcompare */
    v160 = (*qfn2(fn))(qenv(fn), v209, v160);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[0];
    v209 = elt(env, 1); /* less */
    v160 = (v160 == v209 ? lisp_true : nil);
    { popv(1); return onevalue(v160); }
/* error exit handlers */
v132:
    popv(1);
    return nil;
}



/* Code for exceeds!-order */

static Lisp_Object CC_exceedsKorder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exceeds-order");
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

v113:
    v100 = stack[-1];
    if (v100 == nil) goto v15;
    v100 = stack[0];
    v100 = qcar(v100);
    stack[-2] = v100;
    v100 = (Lisp_Object)1; /* 0 */
    v176 = v100;
    goto v107;

v107:
    v100 = stack[-2];
    if (v100 == nil) goto v142;
    v100 = stack[-2];
    v100 = qcar(v100);
    fn = elt(env, 3); /* tayexp!-plus2 */
    v100 = (*qfn2(fn))(qenv(fn), v100, v176);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    v176 = v100;
    v100 = stack[-2];
    v100 = qcdr(v100);
    stack[-2] = v100;
    goto v107;

v142:
    v100 = v176;
    v176 = v100;
    v100 = stack[-1];
    v100 = qcar(v100);
    fn = elt(env, 4); /* tayexp!-lessp */
    v100 = (*qfn2(fn))(qenv(fn), v176, v100);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    if (v100 == nil) goto v134;
    v100 = stack[-1];
    v176 = qcdr(v100);
    v100 = stack[0];
    v100 = qcdr(v100);
    stack[-1] = v176;
    stack[0] = v100;
    goto v113;

v134:
    v100 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v100); }

v15:
    v100 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v100); }
/* error exit handlers */
v116:
    popv(4);
    return nil;
}



/* Code for rl_simpat */

static Lisp_Object CC_rl_simpat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simpat");
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
    v118 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_simpat!* */
    v118 = ncons(v118);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-1];
    {
        Lisp_Object v120 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v120, v118);
    }
/* error exit handlers */
v134:
    popv(2);
    return nil;
}



/* Code for ibalp_litp */

static Lisp_Object CC_ibalp_litp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_litp");
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
    v74 = stack[0];
    fn = elt(env, 3); /* ibalp_atomp */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-1];
    if (!(v74 == nil)) { popv(2); return onevalue(v74); }
    v74 = stack[0];
    if (!consp(v74)) goto v160;
    v74 = stack[0];
    v74 = qcar(v74);
    v110 = v74;
    goto v134;

v134:
    v74 = elt(env, 1); /* not */
    if (v110 == v74) goto v114;
    v74 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v74); }

v114:
    v74 = stack[0];
    v74 = qcdr(v74);
    v74 = qcar(v74);
    {
        popv(2);
        fn = elt(env, 3); /* ibalp_atomp */
        return (*qfn1(fn))(qenv(fn), v74);
    }

v160:
    v74 = stack[0];
    v110 = v74;
    goto v134;
/* error exit handlers */
v185:
    popv(2);
    return nil;
}



/* Code for ratpoly_ldeg */

static Lisp_Object CC_ratpoly_ldeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_ldeg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    v15 = qcar(v15);
    {
        fn = elt(env, 1); /* numpoly_ldeg */
        return (*qfn1(fn))(qenv(fn), v15);
    }
}



/* Code for groebcpcompless!? */

static Lisp_Object CC_groebcpcomplessW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v145, v174, v225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebcpcompless?");
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
    v147 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v147 == nil) goto v136;
    v147 = stack[-1];
    v147 = qcdr(v147);
    v147 = qcdr(v147);
    v147 = qcdr(v147);
    v145 = qcar(v147);
    v147 = stack[0];
    v147 = qcdr(v147);
    v147 = qcdr(v147);
    v147 = qcdr(v147);
    v147 = qcar(v147);
    stack[-2] = difference2(v145, v147);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-3];
    v147 = stack[-1];
    v145 = qcar(v147);
    v147 = stack[0];
    v147 = qcar(v147);
    fn = elt(env, 3); /* vevcomp */
    v147 = (*qfn2(fn))(qenv(fn), v145, v147);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-3];
    v225 = stack[-2];
    v174 = v147;
    v145 = v225;
    v147 = (Lisp_Object)1; /* 0 */
    if (v145 == v147) goto v126;
    v145 = v225;
    v147 = (Lisp_Object)1; /* 0 */
        popv(4);
        return Llessp(nil, v145, v147);

v126:
    v145 = v174;
    v147 = (Lisp_Object)1; /* 0 */
    if (v145 == v147) goto v227;
    v145 = v174;
    v147 = (Lisp_Object)1; /* 0 */
        popv(4);
        return Llessp(nil, v145, v147);

v227:
    v147 = stack[-1];
    v147 = qcdr(v147);
    v147 = qcdr(v147);
    v145 = qcar(v147);
    v147 = elt(env, 2); /* number */
    fn = elt(env, 4); /* vdpgetprop */
    stack[-1] = (*qfn2(fn))(qenv(fn), v145, v147);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-3];
    v147 = stack[0];
    v147 = qcdr(v147);
    v147 = qcdr(v147);
    v145 = qcar(v147);
    v147 = elt(env, 2); /* number */
    fn = elt(env, 4); /* vdpgetprop */
    v147 = (*qfn2(fn))(qenv(fn), v145, v147);
    nil = C_nil;
    if (exception_pending()) goto v226;
    {
        Lisp_Object v168 = stack[-1];
        popv(4);
        return Llessp(nil, v168, v147);
    }

v136:
    v147 = stack[-1];
    v145 = qcar(v147);
    v147 = stack[0];
    v147 = qcar(v147);
    {
        popv(4);
        fn = elt(env, 5); /* vevcompless!? */
        return (*qfn2(fn))(qenv(fn), v145, v147);
    }
/* error exit handlers */
v226:
    popv(4);
    return nil;
}



/* Code for deg!*farg */

static Lisp_Object CC_degHfarg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deg*farg");
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
    v73 = v0;
/* end of prologue */
    v104 = v73;
    v104 = qcdr(v104);
    if (v104 == nil) goto v143;
    stack[-1] = nil;
    v104 = v73;
    stack[0] = v104;
    goto v209;

v209:
    v104 = stack[0];
    if (v104 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v104 = stack[0];
    v104 = qcar(v104);
    fn = elt(env, 2); /* deg!*form */
    v73 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-2];
    v104 = stack[-1];
    fn = elt(env, 3); /* addf */
    v104 = (*qfn2(fn))(qenv(fn), v73, v104);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-2];
    stack[-1] = v104;
    v104 = stack[0];
    v104 = qcdr(v104);
    stack[0] = v104;
    goto v209;

v143:
    v104 = v73;
    v104 = qcar(v104);
    {
        popv(3);
        fn = elt(env, 2); /* deg!*form */
        return (*qfn1(fn))(qenv(fn), v104);
    }
/* error exit handlers */
v72:
    popv(3);
    return nil;
}



/* Code for getphystypesf */

static Lisp_Object CC_getphystypesf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystypesf");
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

v113:
    v142 = stack[0];
    if (v142 == nil) goto v115;
    v142 = stack[0];
    fn = elt(env, 3); /* domain!*p */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    goto v6;

v6:
    if (v142 == nil) goto v93;
    v142 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v142); }

v93:
    v142 = stack[0];
    v142 = qcar(v142);
    v142 = qcar(v142);
    v142 = qcar(v142);
    fn = elt(env, 4); /* getphystype */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    if (!(v142 == nil)) { popv(2); return onevalue(v142); }
    v142 = stack[0];
    v142 = qcar(v142);
    v142 = qcdr(v142);
    stack[0] = v142;
    goto v113;

v115:
    v142 = qvalue(elt(env, 1)); /* t */
    goto v6;
/* error exit handlers */
v75:
    popv(2);
    return nil;
}



/* Code for contrsp */

static Lisp_Object CC_contrsp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v117, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contrsp");
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
    v144 = stack[-1];
    v144 = qcdr(v144);
    v131 = qcar(v144);
    v144 = stack[-1];
    v144 = qcdr(v144);
    v144 = qcdr(v144);
    v117 = qcar(v144);
    v144 = stack[0];
    fn = elt(env, 1); /* contrsp2 */
    v144 = (*qfnn(fn))(qenv(fn), 3, v131, v117, v144);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-2];
    if (!(v144 == nil)) { popv(3); return onevalue(v144); }
    v144 = stack[-1];
    v144 = qcdr(v144);
    v144 = qcdr(v144);
    v131 = qcar(v144);
    v144 = stack[-1];
    v144 = qcdr(v144);
    v117 = qcar(v144);
    v144 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* contrsp2 */
        return (*qfnn(fn))(qenv(fn), 3, v131, v117, v144);
    }
/* error exit handlers */
v73:
    popv(3);
    return nil;
}



/* Code for quotfd */

static Lisp_Object CC_quotfd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v176, v181, v152, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfd");
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
    v181 = v1;
    v152 = v0;
/* end of prologue */
    v158 = v152;
    v176 = v181;
    if (equal(v158, v176)) goto v15;
    v158 = qvalue(elt(env, 1)); /* dmode!* */
    v176 = elt(env, 2); /* field */
    v176 = Lflagp(nil, v158, v176);
    env = stack[0];
    if (v176 == nil) goto v122;
    v176 = v152;
    {
        popv(1);
        fn = elt(env, 4); /* divd */
        return (*qfn2(fn))(qenv(fn), v176, v181);
    }

v122:
    v176 = v152;
    if (!consp(v176)) goto v185;
    v176 = v152;
    v176 = qcar(v176);
    v176 = (consp(v176) ? nil : lisp_true);
    goto v99;

v99:
    if (v176 == nil) goto v126;
    v176 = v152;
    {
        popv(1);
        fn = elt(env, 5); /* quotdd */
        return (*qfn2(fn))(qenv(fn), v176, v181);
    }

v126:
    v176 = v152;
    {
        popv(1);
        fn = elt(env, 6); /* quotk */
        return (*qfn2(fn))(qenv(fn), v176, v181);
    }

v185:
    v176 = qvalue(elt(env, 3)); /* t */
    goto v99;

v15:
    v176 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v176); }
}



/* Code for rnquotient!: */

static Lisp_Object CC_rnquotientT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnquotient:");
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
    v75 = stack[-1];
    v75 = qcdr(v75);
    v74 = qcar(v75);
    v75 = stack[0];
    v75 = qcdr(v75);
    v75 = qcdr(v75);
    stack[-2] = times2(v74, v75);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    v75 = stack[-1];
    v75 = qcdr(v75);
    v74 = qcdr(v75);
    v75 = stack[0];
    v75 = qcdr(v75);
    v75 = qcar(v75);
    v75 = times2(v74, v75);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    {
        Lisp_Object v117 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v117, v75);
    }
/* error exit handlers */
v144:
    popv(4);
    return nil;
}



/* Code for raiseind!: */

static Lisp_Object CC_raiseindT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v120;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for raiseind:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v134 = v0;
/* end of prologue */
    v120 = v134;
    if (!consp(v120)) return onevalue(v134);
    v134 = qcdr(v134);
    v134 = qcar(v134);
    return onevalue(v134);
}



/* Code for reduce!-mod!-p */

static Lisp_Object CC_reduceKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-mod-p");
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
    v109 = stack[-1];
    if (v109 == nil) goto v143;
    v109 = stack[-1];
    if (!consp(v109)) goto v119;
    v109 = stack[-1];
    v109 = qcar(v109);
    v109 = (consp(v109) ? nil : lisp_true);
    goto v118;

v118:
    if (v109 == nil) goto v185;
    v109 = stack[-1];
    v109 = Lmodular_number(nil, v109);
    env = stack[-3];
    v165 = v109;
    v109 = v165;
    v109 = (Lisp_Object)zerop(v109);
    v109 = v109 ? lisp_true : nil;
    env = stack[-3];
    if (v109 == nil) { popv(4); return onevalue(v165); }
    v109 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v109); }

v185:
    v109 = stack[-1];
    v109 = qcar(v109);
    stack[-2] = qcar(v109);
    v109 = stack[-1];
    v109 = qcar(v109);
    v109 = qcdr(v109);
    stack[0] = CC_reduceKmodKp(env, v109);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-3];
    v109 = stack[-1];
    v109 = qcdr(v109);
    v109 = CC_reduceKmodKp(env, v109);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-3];
    {
        Lisp_Object v139 = stack[-2];
        Lisp_Object v67 = stack[0];
        popv(4);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v139, v67, v109);
    }

v119:
    v109 = qvalue(elt(env, 2)); /* t */
    goto v118;

v143:
    v109 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v109); }
/* error exit handlers */
v157:
    popv(4);
    return nil;
}



/* Code for !*sqprint */

static Lisp_Object CC_Hsqprint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *sqprint");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v11 = v0;
/* end of prologue */
    v11 = qcdr(v11);
    v11 = qcar(v11);
    {
        fn = elt(env, 1); /* sqprint */
        return (*qfn1(fn))(qenv(fn), v11);
    }
}



/* Code for wulessp!* */

static Lisp_Object CC_wulesspH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wulessp*");
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
    v144 = stack[-1];
    v185 = stack[0];
    fn = elt(env, 3); /* wulessp */
    v185 = (*qfn2(fn))(qenv(fn), v144, v185);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    if (v185 == nil) goto v209;
    v185 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v185); }

v209:
    v144 = stack[0];
    v185 = stack[-1];
    fn = elt(env, 3); /* wulessp */
    v185 = (*qfn2(fn))(qenv(fn), v144, v185);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    if (v185 == nil) goto v161;
    v185 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v185); }

v161:
    v144 = stack[-1];
    v185 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* totallessp */
        return (*qfn2(fn))(qenv(fn), v144, v185);
    }
/* error exit handlers */
v130:
    popv(3);
    return nil;
}



/* Code for canonsq */

static Lisp_Object CC_canonsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v248, v249, v250;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for canonsq");
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
    v248 = stack[-2];
    v249 = qcdr(v248);
    v248 = (Lisp_Object)17; /* 1 */
    if (v249 == v248) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v248 = stack[-2];
    v248 = qcar(v248);
    if (v248 == nil) goto v132;
    stack[-1] = nil;
    v248 = qvalue(elt(env, 2)); /* asymplis!* */
    if (v248 == nil) goto v74;
    v248 = stack[-2];
    v249 = qcar(v248);
    v248 = stack[-2];
    v248 = qcdr(v248);
    fn = elt(env, 10); /* gcdf */
    v249 = (*qfn2(fn))(qenv(fn), v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[-3] = v249;
    v248 = (Lisp_Object)17; /* 1 */
    if (v249 == v248) goto v74;
    v248 = stack[-2];
    v249 = qcar(v248);
    v248 = stack[-3];
    fn = elt(env, 11); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v248 = stack[-2];
    v249 = qcdr(v248);
    v248 = stack[-3];
    fn = elt(env, 11); /* quotf */
    v248 = (*qfn2(fn))(qenv(fn), v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v248 = cons(stack[0], v248);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[-2] = v248;
    goto v74;

v74:
    v248 = stack[-2];
    v248 = qcdr(v248);
    fn = elt(env, 12); /* lnc */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[-3] = v248;
    v249 = stack[-3];
    v248 = (Lisp_Object)17; /* 1 */
    if (v249 == v248) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v248 = stack[-3];
    if (!consp(v248)) goto v64;
    v248 = stack[-3];
    v249 = qcar(v248);
    v248 = elt(env, 3); /* minusp */
    v249 = get(v249, v248);
    env = stack[-4];
    v248 = stack[-3];
    v248 = Lapply1(nil, v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    if (v248 == nil) goto v149;
    v248 = stack[-2];
    v248 = qcar(v248);
    fn = elt(env, 13); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v248 = stack[-2];
    v248 = qcdr(v248);
    fn = elt(env, 13); /* negf */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v248 = cons(stack[0], v248);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[-2] = v248;
    v248 = stack[-3];
    v249 = qcar(v248);
    v248 = elt(env, 4); /* difference */
    stack[0] = get(v249, v248);
    env = stack[-4];
    v248 = stack[-3];
    v249 = qcar(v248);
    v248 = elt(env, 5); /* i2d */
    v249 = get(v249, v248);
    env = stack[-4];
    v248 = (Lisp_Object)1; /* 0 */
    v249 = Lapply1(nil, v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v248 = stack[-3];
    v248 = Lapply2(nil, 3, stack[0], v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[-3] = v248;
    goto v149;

v149:
    v248 = stack[-3];
    if (is_number(v248)) goto v251;
    v249 = qvalue(elt(env, 6)); /* dmode!* */
    v248 = elt(env, 7); /* unitsfn */
    v248 = get(v249, v248);
    env = stack[-4];
    stack[-1] = v248;
    goto v86;

v86:
    if (v248 == nil) goto v252;
    v250 = stack[-1];
    v249 = stack[-2];
    v248 = stack[-3];
        popv(5);
        return Lapply2(nil, 3, v250, v249, v248);

v252:
    v249 = qvalue(elt(env, 6)); /* dmode!* */
    v248 = elt(env, 8); /* field */
    v248 = Lflagp(nil, v249, v248);
    env = stack[-4];
    if (v248 == nil) goto v253;
    v248 = qvalue(elt(env, 9)); /* t */
    goto v41;

v41:
    if (v248 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v249 = stack[-3];
    v248 = stack[-2];
    {
        popv(5);
        fn = elt(env, 14); /* fieldconv */
        return (*qfn2(fn))(qenv(fn), v249, v248);
    }

v253:
    v248 = stack[-3];
    if (!consp(v248)) goto v33;
    v248 = stack[-3];
    v249 = qcar(v248);
    v248 = elt(env, 8); /* field */
    v248 = Lflagp(nil, v249, v248);
    env = stack[-4];
    goto v41;

v33:
    v248 = qvalue(elt(env, 1)); /* nil */
    goto v41;

v251:
    v248 = qvalue(elt(env, 1)); /* nil */
    goto v86;

v64:
    v248 = stack[-3];
    v248 = Lminusp(nil, v248);
    env = stack[-4];
    if (v248 == nil) goto v149;
    v248 = stack[-2];
    v248 = qcar(v248);
    fn = elt(env, 13); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v248 = stack[-2];
    v248 = qcdr(v248);
    fn = elt(env, 13); /* negf */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v248 = cons(stack[0], v248);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[-2] = v248;
    v248 = stack[-3];
    v248 = negate(v248);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[-3] = v248;
    goto v149;

v132:
    v249 = qvalue(elt(env, 1)); /* nil */
    v248 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v249, v248);
/* error exit handlers */
v188:
    popv(5);
    return nil;
}



/* Code for ctx_new */

static Lisp_Object MS_CDECL CC_ctx_new(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ctx_new");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ctx_new");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v3 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* ctx_fromial */
        return (*qfn1(fn))(qenv(fn), v3);
    }
}



/* Code for omair */

static Lisp_Object MS_CDECL CC_omair(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v178, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omair");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omair");
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
    stack[0] = nil;
    fn = elt(env, 4); /* lex */
    v178 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-2];
    fn = elt(env, 5); /* omobj */
    v178 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-2];
    stack[-1] = v178;
    v178 = stack[-1];
    v75 = qcar(v178);
    v178 = elt(env, 1); /* matrix */
    if (v75 == v178) goto v107;
    fn = elt(env, 4); /* lex */
    v178 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-2];
    fn = elt(env, 6); /* omobjs */
    v178 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-2];
    stack[0] = v178;
    v178 = elt(env, 2); /* (!/ o m a) */
    fn = elt(env, 7); /* checktag */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v99;
    goto v107;

v107:
    v75 = stack[-1];
    v178 = stack[0];
        popv(3);
        return Lappend(nil, v75, v178);
/* error exit handlers */
v99:
    popv(3);
    return nil;
}



/* Code for vdpgetprop */

static Lisp_Object CC_vdpgetprop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v140, v177, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpgetprop");
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
    v177 = v1;
    v105 = v0;
/* end of prologue */
    v116 = v105;
    if (v116 == nil) goto v15;
    v140 = v105;
    v116 = elt(env, 2); /* vdp */
    if (!consp(v140)) goto v132;
    v140 = qcar(v140);
    if (!(v140 == v116)) goto v132;
    v116 = v177;
    v140 = v105;
    v140 = qcdr(v140);
    v140 = qcdr(v140);
    v140 = qcdr(v140);
    v140 = qcdr(v140);
    v140 = qcar(v140);
    v116 = Lassoc(nil, v116, v140);
    v140 = v116;
    v116 = v140;
    if (v116 == nil) goto v181;
    v116 = v140;
    v116 = qcdr(v116);
    { popv(1); return onevalue(v116); }

v181:
    v116 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v116); }

v132:
    v116 = elt(env, 3); /* "vdpgetprop given a non-vdp as 1st parameter" 
*/
    v140 = v105;
    v116 = list3(v116, v140, v177);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[0];
    v140 = v116;
    v116 = v140;
    qvalue(elt(env, 4)) = v116; /* errmsg!* */
    v116 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v116 == nil)) goto v110;
    v116 = v140;
    fn = elt(env, 6); /* lprie */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[0];
    goto v110;

v110:
    v116 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v106;
    v116 = nil;
    { popv(1); return onevalue(v116); }

v15:
    v116 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v116); }
/* error exit handlers */
v106:
    popv(1);
    return nil;
}



/* Code for addpf */

static Lisp_Object CC_addpf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v48, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addpf");
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
    goto v11;

v11:
    v47 = stack[-2];
    if (v47 == nil) goto v134;
    v47 = stack[-1];
    if (v47 == nil) goto v212;
    v47 = stack[-2];
    v47 = qcar(v47);
    v48 = qcar(v47);
    v47 = (Lisp_Object)17; /* 1 */
    if (v48 == v47) goto v213;
    v47 = stack[-1];
    v47 = qcar(v47);
    v48 = qcar(v47);
    v47 = (Lisp_Object)17; /* 1 */
    if (v48 == v47) goto v163;
    v47 = stack[-2];
    v47 = qcar(v47);
    v48 = qcar(v47);
    v47 = stack[-1];
    v47 = qcar(v47);
    v47 = qcar(v47);
    if (equal(v48, v47)) goto v66;
    v47 = stack[-2];
    v47 = qcar(v47);
    v48 = qcar(v47);
    v47 = stack[-1];
    v47 = qcar(v47);
    v47 = qcar(v47);
    fn = elt(env, 1); /* ordop */
    v47 = (*qfn2(fn))(qenv(fn), v48, v47);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    if (v47 == nil) goto v256;
    v47 = stack[-2];
    v48 = qcar(v47);
    v47 = stack[0];
    v47 = cons(v48, v47);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    stack[0] = v47;
    v47 = stack[-2];
    v47 = qcdr(v47);
    stack[-2] = v47;
    goto v11;

v256:
    v47 = stack[-1];
    v48 = qcar(v47);
    v47 = stack[0];
    v47 = cons(v48, v47);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    stack[0] = v47;
    v47 = stack[-1];
    v47 = qcdr(v47);
    stack[-1] = v47;
    goto v11;

v66:
    stack[-3] = stack[0];
    v47 = stack[-2];
    v47 = qcar(v47);
    v48 = qcdr(v47);
    v47 = stack[-1];
    v47 = qcar(v47);
    v47 = qcdr(v47);
    fn = elt(env, 2); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v48, v47);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    v47 = stack[-2];
    v48 = qcdr(v47);
    v47 = stack[-1];
    v47 = qcdr(v47);
    v47 = CC_addpf(env, v48, v47);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    v48 = stack[0];
    v49 = v48;
    v49 = qcar(v49);
    if (v49 == nil) goto v208;
    v49 = stack[-2];
    v49 = qcar(v49);
    v49 = qcar(v49);
    v47 = acons(v49, v48, v47);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    goto v208;

v208:
    {
        Lisp_Object v219 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v219, v47);
    }

v163:
    v48 = stack[-1];
    v47 = stack[-2];
    fn = elt(env, 4); /* addmpf */
    v47 = (*qfn2(fn))(qenv(fn), v48, v47);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    {
        Lisp_Object v257 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v257, v47);
    }

v213:
    v48 = stack[-2];
    v47 = stack[-1];
    fn = elt(env, 4); /* addmpf */
    v47 = (*qfn2(fn))(qenv(fn), v48, v47);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    {
        Lisp_Object v43 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v43, v47);
    }

v212:
    v48 = stack[0];
    v47 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v48, v47);
    }

v134:
    v48 = stack[0];
    v47 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v48, v47);
    }
/* error exit handlers */
v198:
    popv(5);
    return nil;
}



/* Code for fortranprecedence */

static Lisp_Object CC_fortranprecedence(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v121;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fortranprecedence");
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
    v120 = v0;
/* end of prologue */
    v121 = v120;
    v120 = elt(env, 1); /* !*fortranprecedence!* */
    v120 = get(v121, v120);
    if (!(v120 == nil)) return onevalue(v120);
    v120 = (Lisp_Object)145; /* 9 */
    return onevalue(v120);
}



/* Code for has_parents */

static Lisp_Object CC_has_parents(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v161, v142, v178;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for has_parents");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v161 = v0;
/* end of prologue */
    v161 = qcdr(v161);
    v161 = qcar(v161);
    v178 = v161;
    v161 = v178;
    v142 = qcar(v161);
    v161 = elt(env, 1); /* !? */
    if (v142 == v161) goto v154;
    v161 = v178;
    v161 = qcdr(v161);
    v142 = elt(env, 1); /* !? */
        return Lneq(nil, v161, v142);

v154:
    v161 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v161);
}



/* Code for mkid */

static Lisp_Object CC_mkid(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v181, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkid");
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
    v181 = v0;
/* end of prologue */
    v152 = v181;
    if (symbolp(v152)) goto v11;
    v152 = v181;
    v181 = elt(env, 1); /* "MKID root" */
    {
        popv(3);
        fn = elt(env, 4); /* typerr */
        return (*qfn2(fn))(qenv(fn), v152, v181);
    }

v11:
    v152 = stack[0];
    if (!consp(v152)) goto v132;
    v152 = qvalue(elt(env, 2)); /* nil */
    goto v209;

v209:
    if (v152 == nil) goto v258;
    stack[-1] = Lexplode(nil, v181);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    v181 = stack[0];
    v181 = Lexplode(nil, v181);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    v181 = Lnconc(nil, stack[-1], v181);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    v181 = Lcompress(nil, v181);
    nil = C_nil;
    if (exception_pending()) goto v140;
        popv(3);
        return Lintern(nil, v181);

v258:
    v152 = stack[0];
    v181 = elt(env, 3); /* "MKID index" */
    {
        popv(3);
        fn = elt(env, 4); /* typerr */
        return (*qfn2(fn))(qenv(fn), v152, v181);
    }

v132:
    v152 = stack[0];
    v152 = Lsymbolp(nil, v152);
    env = stack[-2];
    if (!(v152 == nil)) goto v209;
    v152 = stack[0];
    v152 = integerp(v152);
    if (v152 == nil) goto v161;
    v152 = stack[0];
    v152 = Lminusp(nil, v152);
    env = stack[-2];
    v152 = (v152 == nil ? lisp_true : nil);
    goto v209;

v161:
    v152 = qvalue(elt(env, 2)); /* nil */
    goto v209;
/* error exit handlers */
v140:
    popv(3);
    return nil;
}



/* Code for red!-weight!-less!-p */

static Lisp_Object CC_redKweightKlessKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v117, v131, v130;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-weight-less-p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v117 = v1;
    v131 = v0;
/* end of prologue */
    v144 = v131;
    v130 = qcar(v144);
    v144 = v117;
    v144 = qcar(v144);
    if (equal(v130, v144)) goto v93;
    v144 = v131;
    v144 = qcar(v144);
    v117 = qcar(v117);
        return Llessp(nil, v144, v117);

v93:
    v144 = v131;
    v144 = qcdr(v144);
    v117 = qcdr(v117);
        return Llessp(nil, v144, v117);
}



/* Code for bas_make1 */

static Lisp_Object MS_CDECL CC_bas_make1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "bas_make1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bas_make1");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v2;
    stack[-3] = v1;
    v154 = v0;
/* end of prologue */
    stack[-4] = v154;
    stack[-1] = stack[-3];
    v154 = stack[-3];
    stack[0] = Llength(nil, v154);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-5];
    v154 = stack[-3];
    fn = elt(env, 1); /* dp_ecart */
    v81 = (*qfn1(fn))(qenv(fn), v154);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-5];
    v154 = stack[-2];
    v154 = list2(v81, v154);
    nil = C_nil;
    if (exception_pending()) goto v74;
    {
        Lisp_Object v110 = stack[-4];
        Lisp_Object v99 = stack[-1];
        Lisp_Object v185 = stack[0];
        popv(6);
        return list3star(v110, v99, v185, v154);
    }
/* error exit handlers */
v74:
    popv(6);
    return nil;
}



/* Code for flatsizec */

static Lisp_Object CC_flatsizec(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for flatsizec");
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
    v81 = stack[0];
    if (v81 == nil) goto v143;
    v81 = stack[0];
    if (!consp(v81)) goto v115;
    v81 = stack[0];
    v81 = qcar(v81);
    stack[-1] = CC_flatsizec(env, v81);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-2];
    v81 = stack[0];
    v81 = qcdr(v81);
    v81 = CC_flatsizec(env, v81);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-2];
    v81 = add1(v81);
    nil = C_nil;
    if (exception_pending()) goto v142;
    {
        Lisp_Object v178 = stack[-1];
        popv(3);
        return plus2(v178, v81);
    }

v115:
    v81 = stack[0];
        popv(3);
        return Llengthc(nil, v81);

v143:
    v81 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v81); }
/* error exit handlers */
v142:
    popv(3);
    return nil;
}



/* Code for mapcons */

static Lisp_Object CC_mapcons(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v258;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mapcons");
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
    v126 = v0;
/* end of prologue */
    stack[-4] = v126;
    v126 = stack[-4];
    if (v126 == nil) goto v119;
    v126 = stack[-4];
    v126 = qcar(v126);
    v258 = stack[-3];
    v126 = cons(v258, v126);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-5];
    v126 = ncons(v126);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-5];
    stack[-1] = v126;
    stack[-2] = v126;
    goto v115;

v115:
    v126 = stack[-4];
    v126 = qcdr(v126);
    stack[-4] = v126;
    v126 = stack[-4];
    if (v126 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v126 = stack[-4];
    v126 = qcar(v126);
    v258 = stack[-3];
    v126 = cons(v258, v126);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-5];
    v126 = ncons(v126);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-5];
    v126 = Lrplacd(nil, stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-5];
    v126 = stack[-1];
    v126 = qcdr(v126);
    stack[-1] = v126;
    goto v115;

v119:
    v126 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v126); }
/* error exit handlers */
v176:
    popv(6);
    return nil;
}



/* Code for processcarpartitie1 */

static Lisp_Object MS_CDECL CC_processcarpartitie1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3,
                         Lisp_Object v143, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v103, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "processcarpartitie1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for processcarpartitie1");
#endif
    if (stack >= stacklimit)
    {
        push5(v143,v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v2,v3,v143);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v143;
    stack[-4] = v3;
    stack[-5] = v2;
    v129 = v1;
    stack[-6] = v0;
/* end of prologue */

v114:
    v103 = v129;
    if (v103 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    v103 = v129;
    v103 = qcdr(v103);
    stack[-7] = v103;
    stack[-2] = stack[-5];
    stack[-1] = stack[-6];
    stack[0] = v129;
    v103 = stack[-4];
    v108 = qcar(v103);
    v103 = qcar(v129);
    v129 = stack[-4];
    v129 = qcdr(v129);
    v103 = list2star(v108, v103, v129);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    v129 = stack[-3];
    fn = elt(env, 1); /* processpartitie1 */
    v129 = (*qfnn(fn))(qenv(fn), 5, stack[-2], stack[-1], stack[0], v103, v129);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-8];
    stack[-3] = v129;
    v129 = stack[-7];
    goto v114;
/* error exit handlers */
v101:
    popv(9);
    return nil;
}



/* Code for ofsf_smwmkatl */

static Lisp_Object MS_CDECL CC_ofsf_smwmkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v130, v104, v73, v223;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smwmkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smwmkatl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v130 = v3;
    v104 = v2;
    v73 = v1;
    v223 = v0;
/* end of prologue */
    v131 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v131 == nil) goto v154;
    v131 = v223;
    {
        fn = elt(env, 2); /* cl_susimkatl */
        return (*qfnn(fn))(qenv(fn), 4, v131, v73, v104, v130);
    }

v154:
    v131 = v223;
    {
        fn = elt(env, 3); /* ofsf_smmkatl */
        return (*qfnn(fn))(qenv(fn), 4, v131, v73, v104, v130);
    }
}



/* Code for qqe_number!-of!-tails!-in!-qterm */

static Lisp_Object CC_qqe_numberKofKtailsKinKqterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v161, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_number-of-tails-in-qterm");
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

v143:
    v161 = stack[0];
    if (!consp(v161)) goto v6;
    v161 = stack[0];
    fn = elt(env, 2); /* qqe_op */
    v142 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    v161 = elt(env, 1); /* (ladd radd) */
    v161 = Lmemq(nil, v142, v161);
    if (v161 == nil) goto v212;
    v161 = stack[0];
    fn = elt(env, 3); /* qqe_arg2r */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    stack[0] = v161;
    goto v143;

v212:
    v161 = stack[0];
    fn = elt(env, 4); /* qqe_arg2l */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    v161 = CC_qqe_numberKofKtailsKinKqterm(env, v161);
    nil = C_nil;
    if (exception_pending()) goto v75;
    popv(2);
    return add1(v161);

v6:
    v161 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v161); }
/* error exit handlers */
v75:
    popv(2);
    return nil;
}



/* Code for rl_susitf */

static Lisp_Object CC_rl_susitf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_susitf");
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
    v160 = v1;
    v209 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_susitf!* */
    v160 = list2(v209, v160);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-1];
    {
        Lisp_Object v224 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v224, v160);
    }
/* error exit handlers */
v172:
    popv(2);
    return nil;
}



/* Code for rl_gettype */

static Lisp_Object CC_rl_gettype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v138, v161;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_gettype");
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
    v138 = v0;
/* end of prologue */
    v161 = v138;
    v81 = elt(env, 1); /* avalue */
    v81 = get(v161, v81);
    env = stack[0];
    v161 = v81;
    v81 = v161;
    if (v81 == nil) goto v172;
    v81 = v161;
    v81 = qcar(v81);
    { popv(1); return onevalue(v81); }

v172:
    v81 = v138;
    v138 = elt(env, 2); /* rtype */
    popv(1);
    return get(v81, v138);
}



/* Code for expression */

static Lisp_Object CC_expression(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v183, v226;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expression");
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
    v226 = v0;
/* end of prologue */
    v156 = v226;
    if (!consp(v156)) goto v6;
    v156 = v226;
    v183 = qcar(v156);
    v156 = elt(env, 1); /* !:rd!: */
    if (v183 == v156) goto v119;
    v156 = v226;
    v183 = qcar(v156);
    v156 = qvalue(elt(env, 2)); /* unary!* */
    v156 = Lassoc(nil, v183, v156);
    v183 = v156;
    if (v156 == nil) goto v149;
    v156 = v183;
    v156 = qcdr(v156);
    v156 = qcdr(v156);
    v156 = qcar(v156);
    if (v156 == nil) goto v164;
    v156 = v183;
    v156 = qcdr(v156);
    stack[0] = qcar(v156);
    v156 = v226;
    v156 = qcdr(v156);
    v183 = qcdr(v183);
    v183 = qcdr(v183);
    v183 = qcar(v183);
    v156 = list2(v156, v183);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-1];
    fn = elt(env, 6); /* apply */
    v156 = (*qfn2(fn))(qenv(fn), stack[0], v156);
    nil = C_nil;
    if (exception_pending()) goto v179;
    goto v11;

v11:
    v156 = nil;
    { popv(2); return onevalue(v156); }

v164:
    v156 = v183;
    v156 = qcdr(v156);
    stack[0] = qcar(v156);
    v156 = v226;
    v156 = qcdr(v156);
    v156 = ncons(v156);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-1];
    fn = elt(env, 6); /* apply */
    v156 = (*qfn2(fn))(qenv(fn), stack[0], v156);
    nil = C_nil;
    if (exception_pending()) goto v179;
    goto v11;

v149:
    v156 = v226;
    v183 = qcar(v156);
    v156 = elt(env, 3); /* !*sq */
    if (v183 == v156) goto v127;
    v156 = v226;
    fn = elt(env, 7); /* operator_fn */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v179;
    goto v11;

v127:
    v156 = v226;
    v156 = qcdr(v156);
    v156 = qcar(v156);
    v156 = qcar(v156);
    if (v156 == nil) goto v64;
    v156 = v226;
    v156 = qcdr(v156);
    v183 = qcar(v156);
    v156 = elt(env, 4); /* prepf */
    fn = elt(env, 8); /* sqform */
    v156 = (*qfn2(fn))(qenv(fn), v183, v156);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-1];
    goto v63;

v63:
    v156 = CC_expression(env, v156);
    nil = C_nil;
    if (exception_pending()) goto v179;
    goto v11;

v64:
    v156 = (Lisp_Object)1; /* 0 */
    goto v63;

v119:
    v156 = v226;
    fn = elt(env, 9); /* printout */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v179;
    goto v11;

v6:
    v156 = v226;
    fn = elt(env, 10); /* f4 */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v179;
    goto v11;
/* error exit handlers */
v179:
    popv(2);
    return nil;
}



/* Code for c!:extadd */

static Lisp_Object CC_cTextadd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v207, v56, v218;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:extadd");
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
    goto v11;

v11:
    v207 = stack[-2];
    if (v207 == nil) goto v134;
    v207 = stack[-1];
    if (v207 == nil) goto v212;
    v207 = stack[-2];
    v207 = qcar(v207);
    v56 = qcar(v207);
    v207 = stack[-1];
    v207 = qcar(v207);
    v207 = qcar(v207);
    if (equal(v56, v207)) goto v71;
    v207 = stack[-2];
    v207 = qcar(v207);
    v56 = qcar(v207);
    v207 = stack[-1];
    v207 = qcar(v207);
    v207 = qcar(v207);
    fn = elt(env, 1); /* c!:ordexp */
    v207 = (*qfn2(fn))(qenv(fn), v56, v207);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-4];
    if (v207 == nil) goto v159;
    v207 = stack[-2];
    v56 = qcar(v207);
    v207 = stack[0];
    v207 = cons(v56, v207);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-4];
    stack[0] = v207;
    v207 = stack[-2];
    v207 = qcdr(v207);
    stack[-2] = v207;
    goto v11;

v159:
    v207 = stack[-1];
    v56 = qcar(v207);
    v207 = stack[0];
    v207 = cons(v56, v207);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-4];
    stack[0] = v207;
    v207 = stack[-1];
    v207 = qcdr(v207);
    stack[-1] = v207;
    goto v11;

v71:
    stack[-3] = stack[0];
    v207 = stack[-2];
    v207 = qcar(v207);
    v56 = qcdr(v207);
    v207 = stack[-1];
    v207 = qcar(v207);
    v207 = qcdr(v207);
    fn = elt(env, 2); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v56, v207);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-4];
    v207 = stack[-2];
    v56 = qcdr(v207);
    v207 = stack[-1];
    v207 = qcdr(v207);
    v207 = CC_cTextadd(env, v56, v207);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-4];
    v56 = stack[0];
    v218 = v56;
    if (v218 == nil) goto v164;
    v218 = stack[-2];
    v218 = qcar(v218);
    v218 = qcar(v218);
    v207 = acons(v218, v56, v207);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-4];
    goto v164;

v164:
    {
        Lisp_Object v200 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v200, v207);
    }

v212:
    v56 = stack[0];
    v207 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v56, v207);
    }

v134:
    v56 = stack[0];
    v207 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v56, v207);
    }
/* error exit handlers */
v199:
    popv(5);
    return nil;
}



/* Code for unbind */

static Lisp_Object CC_unbind(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v224, v133, v212;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unbind");
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
    v172 = v0;
/* end of prologue */
    v212 = v172;
    v133 = elt(env, 1); /* binding */
    v224 = v172;
    v172 = elt(env, 1); /* binding */
    v172 = get(v224, v172);
    v172 = qcdr(v172);
        return Lputprop(nil, 3, v212, v133, v172);
}



/* Code for on */

static Lisp_Object CC_on(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v173, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for on");
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
    v173 = v0;
/* end of prologue */
    stack[0] = v173;
    goto v15;

v15:
    v173 = stack[0];
    if (v173 == nil) goto v114;
    v173 = stack[0];
    v173 = qcar(v173);
    v154 = v173;
    v173 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 3); /* onoff */
    v173 = (*qfn2(fn))(qenv(fn), v154, v173);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-1];
    v173 = stack[0];
    v173 = qcdr(v173);
    stack[0] = v173;
    goto v15;

v114:
    v173 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v173); }
/* error exit handlers */
v138:
    popv(2);
    return nil;
}



/* Code for dim!<deg */

static Lisp_Object CC_dimRdeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dim<deg");
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
    v81 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dimex!* */
    fn = elt(env, 4); /* deg!*farg */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-1];
    fn = elt(env, 5); /* negf */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-1];
    fn = elt(env, 6); /* addf */
    v81 = (*qfn2(fn))(qenv(fn), stack[0], v81);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-1];
    v138 = v81;
    v81 = v138;
    if (!(is_number(v81))) goto v107;
    v81 = v138;
    v81 = Lminusp(nil, v81);
    env = stack[-1];
    if (v81 == nil) goto v107;
    v81 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v81); }

v107:
    v81 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v81); }
/* error exit handlers */
v142:
    popv(2);
    return nil;
}



/* Code for contr2!-strand */

static Lisp_Object MS_CDECL CC_contr2Kstrand(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v225, v155, v156, v183;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "contr2-strand");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contr2-strand");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v113:
    v225 = stack[-3];
    if (v225 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v225 = stack[-3];
    v155 = qcar(v225);
    v225 = stack[-2];
    fn = elt(env, 3); /* contrsp */
    v225 = (*qfn2(fn))(qenv(fn), v155, v225);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    v156 = v225;
    v225 = v156;
    if (v225 == nil) goto v64;
    v225 = v156;
    v155 = qcar(v225);
    v225 = v156;
    v225 = qcdr(v225);
    v225 = Lmember(nil, v155, v225);
    if (v225 == nil) goto v142;
    v155 = stack[-3];
    v225 = stack[-1];
        popv(5);
        return Lappend(nil, v155, v225);

v142:
    v225 = stack[0];
    if (v225 == nil) goto v152;
    v225 = stack[-3];
    v155 = qcdr(v225);
    v225 = stack[-1];
    {
        popv(5);
        fn = elt(env, 4); /* contr2 */
        return (*qfnn(fn))(qenv(fn), 3, v156, v155, v225);
    }

v152:
    v225 = stack[-3];
    v155 = qcdr(v225);
    v225 = stack[-1];
    fn = elt(env, 4); /* contr2 */
    v183 = (*qfnn(fn))(qenv(fn), 3, v156, v155, v225);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    v156 = stack[-2];
    v155 = qvalue(elt(env, 1)); /* nil */
    v225 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v183;
    stack[-2] = v156;
    stack[-1] = v155;
    stack[0] = v225;
    goto v113;

v64:
    v225 = stack[-3];
    stack[0] = qcdr(v225);
    v225 = stack[-3];
    v155 = qcar(v225);
    v225 = stack[-1];
    v155 = cons(v155, v225);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    v225 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = stack[0];
    stack[-1] = v155;
    stack[0] = v225;
    goto v113;
/* error exit handlers */
v58:
    popv(5);
    return nil;
}



/* Code for formprogn */

static Lisp_Object MS_CDECL CC_formprogn(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v212, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formprogn");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formprogn");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v133 = v2;
    v212 = v1;
    v107 = v0;
/* end of prologue */
    stack[0] = elt(env, 1); /* progn */
    v107 = qcdr(v107);
    fn = elt(env, 2); /* formclis */
    v133 = (*qfnn(fn))(qenv(fn), 3, v107, v212, v133);
    nil = C_nil;
    if (exception_pending()) goto v154;
    {
        Lisp_Object v81 = stack[0];
        popv(1);
        return cons(v81, v133);
    }
/* error exit handlers */
v154:
    popv(1);
    return nil;
}



/* Code for getel */

static Lisp_Object CC_getel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v176, v181;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getel");
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
    v100 = stack[-1];
    v176 = qcar(v100);
    v100 = elt(env, 1); /* dimension */
    v100 = get(v176, v100);
    env = stack[-3];
    stack[-2] = v100;
    v100 = stack[-2];
    stack[0] = Llength(nil, v100);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    v100 = stack[-1];
    v100 = qcdr(v100);
    v100 = Llength(nil, v100);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    if (equal(stack[0], v100)) goto v213;
    v100 = elt(env, 2); /* "Incorrect array reference" */
    v176 = v100;
    v100 = v176;
    qvalue(elt(env, 3)) = v100; /* errmsg!* */
    v100 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v100 == nil)) goto v178;
    v100 = v176;
    fn = elt(env, 6); /* lprie */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    goto v178;

v178:
    v100 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v140;
    v100 = nil;
    { popv(4); return onevalue(v100); }

v213:
    v100 = stack[-1];
    v176 = qcar(v100);
    v100 = elt(env, 5); /* avalue */
    v100 = get(v176, v100);
    env = stack[-3];
    v100 = qcdr(v100);
    v181 = qcar(v100);
    v100 = stack[-1];
    v176 = qcdr(v100);
    v100 = stack[-2];
    {
        popv(4);
        fn = elt(env, 7); /* getel1 */
        return (*qfnn(fn))(qenv(fn), 3, v181, v176, v100);
    }
/* error exit handlers */
v140:
    popv(4);
    return nil;
}



/* Code for wtchk */

static Lisp_Object CC_wtchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v100, v176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wtchk");
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
    v101 = stack[-1];
    if (v101 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v101 = stack[-2];
    stack[-3] = ncons(v101);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    stack[0] = elt(env, 1); /* k!* */
    v100 = stack[-1];
    v101 = stack[-2];
    v101 = qcar(v101);
    v101 = qcdr(v101);
    v100 = times2(v100, v101);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    v101 = (Lisp_Object)17; /* 1 */
    v101 = acons(stack[0], v100, v101);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    v101 = ncons(v101);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    fn = elt(env, 3); /* quotf */
    v101 = (*qfn2(fn))(qenv(fn), stack[-3], v101);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    v100 = v101;
    v101 = v100;
    if (v101 == nil) goto v164;
    v101 = v100;
    v101 = qcar(v101);
    { popv(5); return onevalue(v101); }

v164:
    v176 = elt(env, 2); /* "weight confusion" */
    v100 = stack[-2];
    v101 = stack[-1];
    v101 = list3(v176, v100, v101);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 4); /* errach */
        return (*qfn1(fn))(qenv(fn), v101);
    }
/* error exit handlers */
v140:
    popv(5);
    return nil;
}



/* Code for ckrn */

static Lisp_Object CC_ckrn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ckrn");
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
    v100 = qvalue(elt(env, 1)); /* dmode!* */
    v101 = elt(env, 2); /* field */
    v101 = Lflagp(nil, v100, v101);
    env = stack[-2];
    if (v101 == nil) goto v154;
    v100 = qvalue(elt(env, 1)); /* dmode!* */
    v101 = elt(env, 3); /* (!:rd!: !:cr!:) */
    v101 = Lmemq(nil, v100, v101);
    v101 = (v101 == nil ? lisp_true : nil);
    goto v6;

v6:
    if (v101 == nil) goto v258;
    v101 = stack[0];
    fn = elt(env, 5); /* lnc */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    stack[-1] = v101;
    v100 = stack[0];
    fn = elt(env, 6); /* quotfd */
    v101 = (*qfn2(fn))(qenv(fn), v100, v101);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    fn = elt(env, 7); /* ckrn1 */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    fn = elt(env, 8); /* multf */
    v101 = (*qfn2(fn))(qenv(fn), stack[-1], v101);
    nil = C_nil;
    if (exception_pending()) goto v152;
    v100 = v101;
    if (!(v100 == nil)) { popv(3); return onevalue(v101); }
    v101 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v101); }

v258:
    v101 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* ckrn1 */
        return (*qfn1(fn))(qenv(fn), v101);
    }

v154:
    v101 = qvalue(elt(env, 4)); /* nil */
    goto v6;
/* error exit handlers */
v152:
    popv(3);
    return nil;
}



/* Code for processpartitie1 */

static Lisp_Object MS_CDECL CC_processpartitie1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3,
                         Lisp_Object v143, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v167, v199, v200, v263, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "processpartitie1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for processpartitie1");
#endif
    if (stack >= stacklimit)
    {
        push5(v143,v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v2,v3,v143);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v143;
    stack[-1] = v3;
    v200 = v2;
    v263 = v1;
    stack[-2] = v0;
/* end of prologue */

v115:
    v167 = stack[-2];
    if (v167 == nil) goto v118;
    v167 = stack[-2];
    v199 = qcar(v167);
    v167 = (Lisp_Object)1; /* 0 */
    if (v199 == v167) goto v157;
    v167 = stack[-2];
    v199 = qcar(v167);
    v167 = v263;
    if (equal(v199, v167)) goto v127;
    v167 = stack[-2];
    stack[-3] = qcar(v167);
    v199 = elt(env, 3); /* graadlijst */
    v167 = elt(env, 4); /* avalue */
    v167 = get(v199, v167);
    env = stack[-4];
    v167 = qcdr(v167);
    v167 = qcar(v167);
    v199 = qcdr(v167);
    v167 = stack[-2];
    v167 = qcar(v167);
    fn = elt(env, 5); /* pnth */
    v167 = (*qfn2(fn))(qenv(fn), v199, v167);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-4];
    v167 = qcar(v167);
    v263 = qcdr(v167);
    v167 = stack[-2];
    v200 = qcdr(v167);
    v199 = stack[-1];
    v167 = stack[0];
    {
        Lisp_Object v265 = stack[-3];
        popv(5);
        fn = elt(env, 6); /* processcarpartitie1 */
        return (*qfnn(fn))(qenv(fn), 5, v265, v263, v200, v199, v167);
    }

v127:
    v98 = v263;
    v263 = v200;
    v167 = stack[-2];
    v200 = qcdr(v167);
    v199 = stack[-1];
    v167 = stack[0];
    {
        popv(5);
        fn = elt(env, 6); /* processcarpartitie1 */
        return (*qfnn(fn))(qenv(fn), 5, v98, v263, v200, v199, v167);
    }

v157:
    v167 = stack[-2];
    v167 = qcdr(v167);
    stack[-2] = v167;
    goto v115;

v118:
    v167 = stack[-1];
    v167 = qcar(v167);
    if (v167 == nil) goto v172;
    stack[-3] = elt(env, 1); /* times */
    stack[-2] = elt(env, 2); /* ext */
    v167 = stack[-1];
    v167 = qcar(v167);
    fn = elt(env, 7); /* ordn */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-4];
    v199 = Lreverse(nil, v167);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-4];
    v167 = stack[-1];
    v167 = qcdr(v167);
    v199 = acons(stack[-2], v199, v167);
    nil = C_nil;
    if (exception_pending()) goto v264;
    v167 = stack[0];
    {
        Lisp_Object v266 = stack[-3];
        popv(5);
        return acons(v266, v199, v167);
    }

v172:
    v200 = elt(env, 1); /* times */
    v167 = stack[-1];
    v199 = qcdr(v167);
    v167 = stack[0];
    popv(5);
    return acons(v200, v199, v167);
/* error exit handlers */
v264:
    popv(5);
    return nil;
}



/* Code for wuorderp */

static Lisp_Object CC_wuorderp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v174, v225, v155, v156, v183, v226;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wuorderp");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v183 = v1;
    v226 = v0;
/* end of prologue */
    v155 = nil;
    v225 = v226;
    v174 = v183;
    if (v225 == v174) goto v114;
    v174 = qvalue(elt(env, 2)); /* wukord!* */
    v156 = v174;
    goto v224;

v224:
    v174 = v156;
    if (v174 == nil) goto v172;
    v174 = v155;
    if (!(v174 == nil)) goto v172;
    v225 = v226;
    v174 = v156;
    v174 = qcar(v174);
    if (v225 == v174) goto v164;
    v225 = v183;
    v174 = v156;
    v174 = qcar(v174);
    if (v225 == v174) goto v112;
    v174 = v156;
    v174 = qcdr(v174);
    v156 = v174;
    goto v224;

v112:
    v225 = v226;
    v174 = v156;
    v174 = qcdr(v174);
    v174 = Lmemq(nil, v225, v174);
    if (v174 == nil) goto v128;
    v174 = elt(env, 4); /* no */
    goto v106;

v106:
    v155 = v174;
    goto v224;

v128:
    v174 = elt(env, 3); /* yes */
    goto v106;

v164:
    v225 = v183;
    v174 = v156;
    v174 = qcdr(v174);
    v174 = Lmemq(nil, v225, v174);
    if (v174 == nil) goto v258;
    v174 = elt(env, 3); /* yes */
    goto v71;

v71:
    v155 = v174;
    goto v224;

v258:
    v174 = elt(env, 4); /* no */
    goto v71;

v172:
    v174 = v155;
    if (v174 == nil) goto v166;
    v174 = v155;
    v225 = elt(env, 3); /* yes */
    v174 = (v174 == v225 ? lisp_true : nil);
    return onevalue(v174);

v166:
    v174 = v226;
    v225 = v183;
    v174 = Lorderp(nil, v174, v225);
    errexit();
    v174 = (v174 == nil ? lisp_true : nil);
    return onevalue(v174);

v114:
    v174 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v174);
}



/* Code for kernp */

static Lisp_Object CC_kernp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v112, v163;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v112 = v0;
/* end of prologue */
    v111 = v112;
    v163 = qcdr(v111);
    v111 = (Lisp_Object)17; /* 1 */
    if (v163 == v111) goto v143;
    v111 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v111);

v143:
    v111 = v112;
    v111 = qcar(v111);
    v112 = v111;
    v163 = v111;
    v111 = v163;
    if (!consp(v111)) goto v133;
    v111 = v163;
    v111 = qcar(v111);
    v111 = (consp(v111) ? nil : lisp_true);
    goto v224;

v224:
    if (v111 == nil) goto v122;
    v111 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v111);

v122:
    v111 = v112;
    v111 = qcdr(v111);
    if (v111 == nil) goto v104;
    v111 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v111);

v104:
    v111 = v112;
    v111 = qcar(v111);
    v163 = qcdr(v111);
    v111 = (Lisp_Object)17; /* 1 */
    if (v163 == v111) goto v129;
    v111 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v111);

v129:
    v111 = v112;
    v111 = qcar(v111);
    v111 = qcar(v111);
    v112 = qcdr(v111);
    v111 = (Lisp_Object)17; /* 1 */
    v111 = (v112 == v111 ? lisp_true : nil);
    return onevalue(v111);

v133:
    v111 = qvalue(elt(env, 1)); /* t */
    goto v224;
}



/* Code for qqe_ofsf_prepat */

static Lisp_Object CC_qqe_ofsf_prepat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_ofsf_prepat");
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
    fn = elt(env, 1); /* qqe_op */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-1];
    fn = elt(env, 2); /* qqe_rqopp */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-1];
    if (v121 == nil) goto v118;
    v121 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); /* qqe_prepat */
        return (*qfn1(fn))(qenv(fn), v121);
    }

v118:
    v121 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* ofsf_prepat */
        return (*qfn1(fn))(qenv(fn), v121);
    }
/* error exit handlers */
v93:
    popv(2);
    return nil;
}



/* Code for ibalp_atomp */

static Lisp_Object CC_ibalp_atomp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_atomp");
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
    v158 = stack[0];
    v152 = elt(env, 1); /* true */
    if (v158 == v152) goto v115;
    v158 = stack[0];
    v152 = elt(env, 3); /* false */
    v152 = (v158 == v152 ? lisp_true : nil);
    goto v6;

v6:
    if (v152 == nil) goto v110;
    v152 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v152); }

v110:
    v152 = stack[0];
    if (!consp(v152)) goto v104;
    v152 = stack[0];
    v152 = qcar(v152);
    v158 = v152;
    goto v185;

v185:
    v152 = elt(env, 4); /* equal */
    if (v158 == v152) goto v75;
    v152 = qvalue(elt(env, 5)); /* nil */
    { popv(2); return onevalue(v152); }

v75:
    v152 = stack[0];
    fn = elt(env, 6); /* ibalp_arg2l */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-1];
    if (symbolp(v152)) goto v258;
    v152 = qvalue(elt(env, 5)); /* nil */
    { popv(2); return onevalue(v152); }

v258:
    v152 = stack[0];
    fn = elt(env, 7); /* ibalp_arg2r */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v140;
    v152 = (is_number(v152) ? lisp_true : nil);
    { popv(2); return onevalue(v152); }

v104:
    v152 = stack[0];
    v158 = v152;
    goto v185;

v115:
    v152 = qvalue(elt(env, 2)); /* t */
    goto v6;
/* error exit handlers */
v140:
    popv(2);
    return nil;
}



/* Code for basicom */

static Lisp_Object CC_basicom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for basicom");
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
    v161 = stack[0];
    if (is_number(v161)) goto v11;
    v161 = stack[0];
    if (!(symbolp(v161))) goto v15;
    v161 = stack[0];
    fn = elt(env, 1); /* variableom */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v178;
    goto v15;

v15:
    v161 = nil;
    { popv(2); return onevalue(v161); }

v11:
    v161 = stack[0];
    v161 = integerp(v161);
    if (v161 == nil) goto v180;
    v161 = stack[0];
    fn = elt(env, 2); /* integerom */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-1];
    goto v180;

v180:
    v161 = stack[0];
    v161 = Lfloatp(nil, v161);
    env = stack[-1];
    if (v161 == nil) goto v15;
    v161 = stack[0];
    fn = elt(env, 3); /* floatom */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v178;
    goto v15;
/* error exit handlers */
v178:
    popv(2);
    return nil;
}



/* Code for off */

static Lisp_Object CC_off(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v173, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for off");
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
    v173 = v0;
/* end of prologue */
    stack[0] = v173;
    goto v15;

v15:
    v173 = stack[0];
    if (v173 == nil) goto v114;
    v173 = stack[0];
    v173 = qcar(v173);
    v154 = v173;
    v173 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* onoff */
    v173 = (*qfn2(fn))(qenv(fn), v154, v173);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-1];
    v173 = stack[0];
    v173 = qcdr(v173);
    stack[0] = v173;
    goto v15;

v114:
    v173 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v173); }
/* error exit handlers */
v138:
    popv(2);
    return nil;
}



/* Code for diplength */

static Lisp_Object CC_diplength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v223;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diplength");
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
    goto v11;

v11:
    v73 = stack[0];
    if (v73 == nil) goto v6;
    v223 = (Lisp_Object)17; /* 1 */
    v73 = stack[-1];
    v73 = cons(v223, v73);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-2];
    stack[-1] = v73;
    v73 = stack[0];
    v73 = qcdr(v73);
    v73 = qcdr(v73);
    stack[0] = v73;
    goto v11;

v6:
    v73 = (Lisp_Object)1; /* 0 */
    v223 = v73;
    goto v115;

v115:
    v73 = stack[-1];
    if (v73 == nil) { popv(3); return onevalue(v223); }
    v73 = stack[-1];
    v73 = qcar(v73);
    v73 = plus2(v73, v223);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-2];
    v223 = v73;
    v73 = stack[-1];
    v73 = qcdr(v73);
    stack[-1] = v73;
    goto v115;
/* error exit handlers */
v70:
    popv(3);
    return nil;
}



/* Code for !*kp2f */

static Lisp_Object CC_Hkp2f(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *kp2f");
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
    v81 = stack[0];
    v154 = (Lisp_Object)1; /* 0 */
    v154 = (Lisp_Object)greaterp2(v81, v154);
    nil = C_nil;
    if (exception_pending()) goto v142;
    v154 = v154 ? lisp_true : nil;
    env = stack[-2];
    if (v154 == nil) goto v212;
    v81 = stack[-1];
    v154 = stack[0];
    fn = elt(env, 1); /* mksq */
    v154 = (*qfn2(fn))(qenv(fn), v81, v154);
    nil = C_nil;
    if (exception_pending()) goto v142;
    v154 = qcar(v154);
    { popv(3); return onevalue(v154); }

v212:
    v154 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v154); }
/* error exit handlers */
v142:
    popv(3);
    return nil;
}



/* Code for covposp */

static Lisp_Object CC_covposp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v224, v133;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for covposp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v224 = v0;
/* end of prologue */

v113:
    v133 = v224;
    if (v133 == nil) goto v143;
    v133 = v224;
    v133 = qcar(v133);
    if (!consp(v133)) goto v209;
    v224 = qcdr(v224);
    goto v113;

v209:
    v224 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v224);

v143:
    v224 = qvalue(elt(env, 1)); /* t */
    return onevalue(v224);
}



/* Code for opnum!* */

static Lisp_Object CC_opnumH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v116, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opnum*");
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
    v116 = v0;
/* end of prologue */
    stack[-1] = nil;
    v158 = v116;
    if (symbolp(v158)) goto v115;
    stack[0] = v116;
    v158 = v116;
    fn = elt(env, 3); /* collectindices */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-2];
    fn = elt(env, 4); /* removeindices */
    v158 = (*qfn2(fn))(qenv(fn), stack[0], v158);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-2];
    v116 = v158;
    goto v115;

v115:
    v158 = v116;
    if (symbolp(v158)) goto v133;
    v158 = v116;
    v158 = qcar(v158);
    v116 = qcdr(v116);
    stack[-1] = v116;
    goto v110;

v110:
    v116 = v158;
    v158 = elt(env, 2); /* opnum */
    v158 = get(v116, v158);
    env = stack[-2];
    v140 = v158;
    v116 = stack[-1];
    v158 = v140;
    v158 = Lassoc(nil, v116, v158);
    v116 = v158;
    if (v158 == nil) goto v258;
    v158 = v116;
    v158 = qcdr(v158);
    { popv(3); return onevalue(v158); }

v258:
    v158 = qvalue(elt(env, 1)); /* nil */
    v116 = v140;
    v158 = Lassoc(nil, v158, v116);
    v158 = qcdr(v158);
    { popv(3); return onevalue(v158); }

v133:
    v158 = v116;
    goto v110;
/* error exit handlers */
v106:
    popv(3);
    return nil;
}



/* Code for formcond */

static Lisp_Object MS_CDECL CC_formcond(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v212, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formcond");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formcond");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v133 = v2;
    v212 = v1;
    v107 = v0;
/* end of prologue */
    stack[0] = elt(env, 1); /* cond */
    v107 = qcdr(v107);
    fn = elt(env, 2); /* formcond1 */
    v133 = (*qfnn(fn))(qenv(fn), 3, v107, v212, v133);
    nil = C_nil;
    if (exception_pending()) goto v154;
    {
        Lisp_Object v81 = stack[0];
        popv(1);
        return cons(v81, v133);
    }
/* error exit handlers */
v154:
    popv(1);
    return nil;
}



/* Code for red!-ratios1 */

static Lisp_Object CC_redKratios1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v73, v223, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-ratios1");
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

v113:
    v104 = stack[-1];
    if (v104 == nil) goto v15;
    v104 = stack[-1];
    v71 = qcdr(v104);
    v104 = stack[0];
    v223 = qcdr(v104);
    v104 = stack[-1];
    v73 = qcar(v104);
    v104 = stack[0];
    v104 = qcar(v104);
    fn = elt(env, 2); /* red!-ratios2 */
    v104 = (*qfnn(fn))(qenv(fn), 4, v71, v223, v73, v104);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-2];
    if (!(v104 == nil)) { popv(3); return onevalue(v104); }
    v104 = stack[-1];
    v73 = qcdr(v104);
    v104 = stack[0];
    v104 = qcdr(v104);
    stack[-1] = v73;
    stack[0] = v104;
    goto v113;

v15:
    v104 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v104); }
/* error exit handlers */
v164:
    popv(3);
    return nil;
}



/* Code for subsetp */

static Lisp_Object CC_subsetp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v185, v144, v117;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subsetp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v185 = v1;
    v144 = v0;
/* end of prologue */

v113:
    v99 = v144;
    if (v99 == nil) goto v15;
    v99 = v144;
    v117 = qcar(v99);
    v99 = v185;
    v99 = Lmember(nil, v117, v99);
    if (v99 == nil) goto v134;
    v99 = v144;
    v144 = qcdr(v99);
    v99 = v185;
    v185 = v99;
    goto v113;

v134:
    v99 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v99);

v15:
    v99 = qvalue(elt(env, 1)); /* t */
    return onevalue(v99);
}



/* Code for quotk */

static Lisp_Object CC_quotk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v184, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotk");
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
    v106 = stack[-1];
    v106 = qcar(v106);
    v184 = qcdr(v106);
    v106 = stack[0];
    fn = elt(env, 2); /* quotf1 */
    v106 = (*qfn2(fn))(qenv(fn), v184, v106);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-3];
    stack[-2] = v106;
    v106 = stack[-2];
    if (v106 == nil) goto v140;
    v106 = stack[-1];
    v106 = qcdr(v106);
    if (v106 == nil) goto v154;
    v106 = stack[-1];
    v184 = qcdr(v106);
    v106 = stack[0];
    fn = elt(env, 2); /* quotf1 */
    v106 = (*qfn2(fn))(qenv(fn), v184, v106);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-3];
    v184 = v106;
    v106 = v184;
    if (v106 == nil) goto v152;
    v106 = stack[-1];
    v106 = qcar(v106);
    v111 = qcar(v106);
    v106 = stack[-2];
    popv(4);
    return acons(v111, v106, v184);

v152:
    v106 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v106); }

v154:
    v106 = stack[-1];
    v106 = qcar(v106);
    v184 = qcar(v106);
    v106 = stack[-2];
    v106 = cons(v184, v106);
    nil = C_nil;
    if (exception_pending()) goto v68;
    popv(4);
    return ncons(v106);

v140:
    v106 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v106); }
/* error exit handlers */
v68:
    popv(4);
    return nil;
}



/* Code for gperm2 */

static Lisp_Object MS_CDECL CC_gperm2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v104, v73, v223;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "gperm2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm2");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    v130 = v0;
/* end of prologue */

v6:
    v104 = v130;
    if (v104 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v104 = v130;
    v104 = qcdr(v104);
    stack[-2] = v104;
    v104 = qcar(v130);
    v130 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* rev */
    v223 = (*qfn2(fn))(qenv(fn), v104, v130);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-3];
    v73 = stack[-1];
    v104 = qvalue(elt(env, 1)); /* nil */
    v130 = stack[0];
    fn = elt(env, 3); /* gperm1 */
    v130 = (*qfnn(fn))(qenv(fn), 4, v223, v73, v104, v130);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-3];
    stack[0] = v130;
    v130 = stack[-2];
    goto v6;
/* error exit handlers */
v164:
    popv(4);
    return nil;
}



/* Code for times!-in!-vector */

static Lisp_Object MS_CDECL CC_timesKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3,
                         Lisp_Object v143, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v236, v270, v51, v254, v52, v271, v203, v272, v273, v256, v195, v220, v274, v240, v241;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "times-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for times-in-vector");
#endif
    if (stack >= stacklimit)
    {
        push5(v143,v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v2,v3,v143);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v256 = v143;
    v195 = v3;
    v220 = v2;
    v274 = v1;
    v240 = v0;
/* end of prologue */
    v270 = v274;
    v236 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v270)) < ((int32_t)(v236))) goto v134;
    v270 = v195;
    v236 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v270)) < ((int32_t)(v236))) goto v134;
    v270 = v274;
    v236 = v195;
    v236 = (Lisp_Object)(int32_t)((int32_t)v270 + (int32_t)v236 - TAG_FIXNUM);
    v241 = v236;
    v236 = (Lisp_Object)1; /* 0 */
    v254 = v236;
    goto v153;

v153:
    v270 = v241;
    v236 = v254;
    v236 = (Lisp_Object)(int32_t)((int32_t)v270 - (int32_t)v236 + TAG_FIXNUM);
    v236 = ((intptr_t)(v236) < 0 ? lisp_true : nil);
    if (v236 == nil) goto v157;
    v236 = (Lisp_Object)1; /* 0 */
    v272 = v236;
    goto v69;

v69:
    v270 = v274;
    v236 = v272;
    v236 = (Lisp_Object)(int32_t)((int32_t)v270 - (int32_t)v236 + TAG_FIXNUM);
    v236 = ((intptr_t)(v236) < 0 ? lisp_true : nil);
    if (!(v236 == nil)) { popv(1); return onevalue(v241); }
    v270 = v240;
    v236 = v272;
    v236 = *(Lisp_Object *)((char *)v270 + (CELL-TAG_VECTOR) + ((int32_t)v236/(16/CELL)));
    v273 = v236;
    v236 = (Lisp_Object)1; /* 0 */
    v203 = v236;
    goto v60;

v60:
    v270 = v195;
    v236 = v203;
    v236 = (Lisp_Object)(int32_t)((int32_t)v270 - (int32_t)v236 + TAG_FIXNUM);
    v236 = ((intptr_t)(v236) < 0 ? lisp_true : nil);
    if (v236 == nil) goto v225;
    v236 = v272;
    v236 = (Lisp_Object)((int32_t)(v236) + 0x10);
    v272 = v236;
    goto v69;

v225:
    v270 = v272;
    v236 = v203;
    v236 = (Lisp_Object)(int32_t)((int32_t)v270 + (int32_t)v236 - TAG_FIXNUM);
    v271 = v256;
    v52 = v236;
    v270 = v256;
    v254 = *(Lisp_Object *)((char *)v270 + (CELL-TAG_VECTOR) + ((int32_t)v236/(16/CELL)));
    v51 = v273;
    v270 = v220;
    v236 = v203;
    v236 = *(Lisp_Object *)((char *)v270 + (CELL-TAG_VECTOR) + ((int32_t)v236/(16/CELL)));
    v236 = Lmodular_times(nil, v51, v236);
    env = stack[0];
    {   int32_t w = int_of_fixnum(v254) + int_of_fixnum(v236);
        if (w >= current_modulus) w -= current_modulus;
        v236 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v271 + (CELL-TAG_VECTOR) + ((int32_t)v52/(16/CELL))) = v236;
    v236 = v203;
    v236 = (Lisp_Object)((int32_t)(v236) + 0x10);
    v203 = v236;
    goto v60;

v157:
    v51 = v256;
    v270 = v254;
    v236 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v51 + (CELL-TAG_VECTOR) + ((int32_t)v270/(16/CELL))) = v236;
    v236 = v254;
    v236 = (Lisp_Object)((int32_t)(v236) + 0x10);
    v254 = v236;
    goto v153;

v134:
    v236 = (Lisp_Object)-15; /* -1 */
    { popv(1); return onevalue(v236); }
}



/* Code for tr_write */

static Lisp_Object CC_tr_write(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v173, v154;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tr_write");
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
    v154 = v0;
/* end of prologue */
    v173 = qvalue(elt(env, 1)); /* !*trsolve */
    if (v173 == nil) goto v15;
    v173 = v154;
    stack[0] = v173;
    goto v180;

v180:
    v173 = stack[0];
    if (v173 == nil) goto v114;
    v173 = stack[0];
    v173 = qcar(v173);
    v173 = Lprinc(nil, v173);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-1];
    v173 = stack[0];
    v173 = qcdr(v173);
    stack[0] = v173;
    goto v180;

v114:
        popv(2);
        return Lterpri(nil, 0);

v15:
    v173 = nil;
    { popv(2); return onevalue(v173); }
/* error exit handlers */
v138:
    popv(2);
    return nil;
}



/* Code for msappend */

static Lisp_Object CC_msappend(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v106;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msappend");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v1;
    v105 = v0;
/* end of prologue */
    stack[-5] = v105;
    v105 = stack[-5];
    if (v105 == nil) goto v119;
    v105 = stack[-5];
    v105 = qcar(v105);
    stack[0] = stack[-4];
    v106 = stack[-4];
    v105 = Lsublis(nil, v106, v105);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-6];
    v105 = Lappend(nil, stack[0], v105);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-6];
    v105 = ncons(v105);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-6];
    stack[-2] = v105;
    stack[-3] = v105;
    goto v115;

v115:
    v105 = stack[-5];
    v105 = qcdr(v105);
    stack[-5] = v105;
    v105 = stack[-5];
    if (v105 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v105 = stack[-5];
    v105 = qcar(v105);
    stack[0] = stack[-4];
    v106 = stack[-4];
    v105 = Lsublis(nil, v106, v105);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-6];
    v105 = Lappend(nil, stack[0], v105);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-6];
    v105 = ncons(v105);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-6];
    v105 = Lrplacd(nil, stack[-1], v105);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-6];
    v105 = stack[-2];
    v105 = qcdr(v105);
    stack[-2] = v105;
    goto v115;

v119:
    v105 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v105); }
/* error exit handlers */
v247:
    popv(7);
    return nil;
}



/* Code for ibalp_simpat */

static Lisp_Object CC_ibalp_simpat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_simpat");
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
    v172 = stack[-1];
    stack[-2] = qcar(v172);
    v172 = stack[-1];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    fn = elt(env, 1); /* ibalp_simpterm */
    stack[0] = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-3];
    v172 = stack[-1];
    v172 = qcdr(v172);
    v172 = qcdr(v172);
    v172 = qcar(v172);
    fn = elt(env, 1); /* ibalp_simpterm */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-3];
    {
        Lisp_Object v173 = stack[-2];
        Lisp_Object v154 = stack[0];
        popv(4);
        fn = elt(env, 2); /* ibalp_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v173, v154, v172);
    }
/* error exit handlers */
v107:
    popv(4);
    return nil;
}



/* Code for poly!-abs */

static Lisp_Object CC_polyKabs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for poly-abs");
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
    v134 = stack[0];
    fn = elt(env, 1); /* poly!-minusp */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-1];
    if (v134 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v134 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* negf */
        return (*qfn1(fn))(qenv(fn), v134);
    }
/* error exit handlers */
v121:
    popv(2);
    return nil;
}



setup_type const u08_setup[] =
{
    {"letmtr3",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_letmtr3},
    {"comm_kernels1",           too_few_2,      CC_comm_kernels1,wrong_no_2},
    {"fortranop",               CC_fortranop,   too_many_1,    wrong_no_1},
    {"ckpreci#",                CC_ckpreciC,    too_many_1,    wrong_no_1},
    {"compactfmatch2",          CC_compactfmatch2,too_many_1,  wrong_no_1},
    {"divd",                    too_few_2,      CC_divd,       wrong_no_2},
    {"dp_sum",                  too_few_2,      CC_dp_sum,     wrong_no_2},
    {"ord",                     CC_ord,         too_many_1,    wrong_no_1},
    {"vecp",                    CC_vecp,        too_many_1,    wrong_no_1},
    {"pappl_pv",                too_few_2,      CC_pappl_pv,   wrong_no_2},
    {"general-plus-mod-p",      too_few_2,      CC_generalKplusKmodKp,wrong_no_2},
    {"ofsf_clnegrel",           too_few_2,      CC_ofsf_clnegrel,wrong_no_2},
    {"totallessp",              too_few_2,      CC_totallessp, wrong_no_2},
    {"exceeds-order",           too_few_2,      CC_exceedsKorder,wrong_no_2},
    {"rl_simpat",               CC_rl_simpat,   too_many_1,    wrong_no_1},
    {"ibalp_litp",              CC_ibalp_litp,  too_many_1,    wrong_no_1},
    {"ratpoly_ldeg",            CC_ratpoly_ldeg,too_many_1,    wrong_no_1},
    {"groebcpcompless?",        too_few_2,      CC_groebcpcomplessW,wrong_no_2},
    {"deg*farg",                CC_degHfarg,    too_many_1,    wrong_no_1},
    {"getphystypesf",           CC_getphystypesf,too_many_1,   wrong_no_1},
    {"contrsp",                 too_few_2,      CC_contrsp,    wrong_no_2},
    {"quotfd",                  too_few_2,      CC_quotfd,     wrong_no_2},
    {"rnquotient:",             too_few_2,      CC_rnquotientT,wrong_no_2},
    {"raiseind:",               CC_raiseindT,   too_many_1,    wrong_no_1},
    {"reduce-mod-p",            CC_reduceKmodKp,too_many_1,    wrong_no_1},
    {"*sqprint",                CC_Hsqprint,    too_many_1,    wrong_no_1},
    {"wulessp*",                too_few_2,      CC_wulesspH,   wrong_no_2},
    {"canonsq",                 CC_canonsq,     too_many_1,    wrong_no_1},
    {"ctx_new",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_ctx_new},
    {"omair",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omair},
    {"vdpgetprop",              too_few_2,      CC_vdpgetprop, wrong_no_2},
    {"addpf",                   too_few_2,      CC_addpf,      wrong_no_2},
    {"fortranprecedence",       CC_fortranprecedence,too_many_1,wrong_no_1},
    {"has_parents",             CC_has_parents, too_many_1,    wrong_no_1},
    {"mkid",                    too_few_2,      CC_mkid,       wrong_no_2},
    {"red-weight-less-p",       too_few_2,      CC_redKweightKlessKp,wrong_no_2},
    {"bas_make1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_bas_make1},
    {"flatsizec",               CC_flatsizec,   too_many_1,    wrong_no_1},
    {"mapcons",                 too_few_2,      CC_mapcons,    wrong_no_2},
    {"processcarpartitie1",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_processcarpartitie1},
    {"ofsf_smwmkatl",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smwmkatl},
    {"qqe_number-of-tails-in-qterm",CC_qqe_numberKofKtailsKinKqterm,too_many_1,wrong_no_1},
    {"rl_susitf",               too_few_2,      CC_rl_susitf,  wrong_no_2},
    {"rl_gettype",              CC_rl_gettype,  too_many_1,    wrong_no_1},
    {"expression",              CC_expression,  too_many_1,    wrong_no_1},
    {"c:extadd",                too_few_2,      CC_cTextadd,   wrong_no_2},
    {"unbind",                  CC_unbind,      too_many_1,    wrong_no_1},
    {"on",                      CC_on,          too_many_1,    wrong_no_1},
    {"dim<deg",                 CC_dimRdeg,     too_many_1,    wrong_no_1},
    {"contr2-strand",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_contr2Kstrand},
    {"formprogn",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_formprogn},
    {"getel",                   CC_getel,       too_many_1,    wrong_no_1},
    {"wtchk",                   too_few_2,      CC_wtchk,      wrong_no_2},
    {"ckrn",                    CC_ckrn,        too_many_1,    wrong_no_1},
    {"processpartitie1",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_processpartitie1},
    {"wuorderp",                too_few_2,      CC_wuorderp,   wrong_no_2},
    {"kernp",                   CC_kernp,       too_many_1,    wrong_no_1},
    {"qqe_ofsf_prepat",         CC_qqe_ofsf_prepat,too_many_1, wrong_no_1},
    {"ibalp_atomp",             CC_ibalp_atomp, too_many_1,    wrong_no_1},
    {"basicom",                 CC_basicom,     too_many_1,    wrong_no_1},
    {"off",                     CC_off,         too_many_1,    wrong_no_1},
    {"diplength",               CC_diplength,   too_many_1,    wrong_no_1},
    {"*kp2f",                   too_few_2,      CC_Hkp2f,      wrong_no_2},
    {"covposp",                 CC_covposp,     too_many_1,    wrong_no_1},
    {"opnum*",                  CC_opnumH,      too_many_1,    wrong_no_1},
    {"formcond",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formcond},
    {"red-ratios1",             too_few_2,      CC_redKratios1,wrong_no_2},
    {"subsetp",                 too_few_2,      CC_subsetp,    wrong_no_2},
    {"quotk",                   too_few_2,      CC_quotk,      wrong_no_2},
    {"gperm2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm2},
    {"times-in-vector",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_timesKinKvector},
    {"tr_write",                CC_tr_write,    too_many_1,    wrong_no_1},
    {"msappend",                too_few_2,      CC_msappend,   wrong_no_2},
    {"ibalp_simpat",            CC_ibalp_simpat,too_many_1,    wrong_no_1},
    {"poly-abs",                CC_polyKabs,    too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u08", (two_args *)"2418 5331755 9535540", 0}
};

/* end of generated code */
