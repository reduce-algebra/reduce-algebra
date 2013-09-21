
/* $destdir/u05.c        Machine generated C code */

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


/* Code for subs2f1 */

static Lisp_Object CC_subs2f1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0102, v0103, v0104, v0105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subs2f1");
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
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v0000;
/* end of prologue */
    v0101 = stack[-8];
    if (!consp(v0101)) goto v0106;
    v0101 = stack[-8];
    v0101 = qcar(v0101);
    v0101 = (consp(v0101) ? nil : lisp_true);
    goto v0107;

v0107:
    if (v0101 == nil) goto v0108;
    v0101 = stack[-8];
    {
        popv(11);
        fn = elt(env, 12); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v0101);
    }

v0108:
    stack[-2] = nil;
    goto v0109;

v0109:
    v0101 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v0101;
    v0101 = stack[-8];
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    stack[-9] = v0101;
    v0102 = qvalue(elt(env, 2)); /* nil */
    v0101 = (Lisp_Object)17; /* 1 */
    v0101 = cons(v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    stack[-3] = v0101;
    goto v0111;

v0111:
    v0101 = stack[-8];
    if (v0101 == nil) goto v0112;
    v0102 = stack[-8];
    v0101 = stack[-9];
    fn = elt(env, 13); /* degr */
    v0102 = (*qfn2(fn))(qenv(fn), v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    v0101 = (Lisp_Object)1; /* 0 */
    v0101 = (v0102 == v0101 ? lisp_true : nil);
    goto v0113;

v0113:
    if (!(v0101 == nil)) goto v0114;
    v0101 = stack[-8];
    v0102 = qcar(v0101);
    v0101 = stack[-4];
    v0101 = cons(v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    stack[-4] = v0101;
    v0101 = stack[-8];
    v0101 = qcdr(v0101);
    stack[-8] = v0101;
    goto v0111;

v0114:
    v0101 = qvalue(elt(env, 3)); /* powlis!* */
    stack[-5] = v0101;
    goto v0115;

v0115:
    v0101 = stack[-5];
    if (v0101 == nil) goto v0116;
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    v0102 = qcar(v0101);
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    if (equal(v0102, v0101)) goto v0117;
    v0102 = stack[-9];
    v0101 = elt(env, 4); /* expt */
    if (!consp(v0102)) goto v0118;
    v0102 = qcar(v0102);
    if (!(v0102 == v0101)) goto v0118;
    v0101 = stack[-9];
    v0101 = qcdr(v0101);
    v0102 = qcar(v0101);
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    if (equal(v0102, v0101)) goto v0119;
    v0101 = qvalue(elt(env, 2)); /* nil */
    goto v0120;

v0120:
    if (v0101 == nil) goto v0121;
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    v0102 = qcdr(v0101);
    v0101 = stack[-9];
    v0101 = qcdr(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    v0101 = Ldivide(nil, v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    stack[-7] = v0101;
    v0101 = stack[-7];
    v0102 = qcar(v0101);
    v0101 = (Lisp_Object)1; /* 0 */
    if (v0102 == v0101) goto v0122;
    v0101 = stack[-9];
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    fn = elt(env, 14); /* simp */
    v0102 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    v0101 = stack[-7];
    v0101 = qcar(v0101);
    fn = elt(env, 15); /* exptsq */
    v0101 = (*qfn2(fn))(qenv(fn), v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    stack[-6] = v0101;
    goto v0123;

v0123:
    v0101 = stack[-7];
    v0102 = qcdr(v0101);
    v0101 = (Lisp_Object)1; /* 0 */
    if (v0102 == v0101) goto v0124;
    stack[-1] = qvalue(elt(env, 6)); /* alglist!* */
    qvalue(elt(env, 6)) = nil; /* alglist!* */
    stack[0] = qvalue(elt(env, 7)); /* dmode!* */
    qvalue(elt(env, 7)) = nil; /* dmode!* */
    v0101 = qvalue(elt(env, 2)); /* nil */
    v0101 = ncons(v0101);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-10];
    qvalue(elt(env, 6)) = v0101; /* alglist!* */
    v0101 = stack[-7];
    v0102 = qcdr(v0101);
    v0101 = stack[-9];
    v0101 = qcdr(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    v0101 = cons(v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-10];
    fn = elt(env, 16); /* cancel */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-10];
    stack[-7] = v0101;
    qvalue(elt(env, 7)) = stack[0]; /* dmode!* */
    qvalue(elt(env, 6)) = stack[-1]; /* alglist!* */
    v0101 = stack[-9];
    v0101 = qcdr(v0101);
    v0102 = qcar(v0101);
    v0101 = stack[-7];
    v0101 = qcar(v0101);
    v0103 = cons(v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0102 = qcar(v0101);
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    fn = elt(env, 17); /* subs2p */
    v0102 = (*qfnn(fn))(qenv(fn), 3, v0103, v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    v0101 = stack[-7];
    v0101 = qcdr(v0101);
    fn = elt(env, 18); /* raddsq */
    v0102 = (*qfn2(fn))(qenv(fn), v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    v0101 = stack[-6];
    fn = elt(env, 19); /* multsq */
    v0101 = (*qfn2(fn))(qenv(fn), v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    stack[-6] = v0101;
    goto v0124;

v0124:
    stack[0] = stack[-6];
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0101 = CC_subs2f1(env, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    fn = elt(env, 19); /* multsq */
    v0102 = (*qfn2(fn))(qenv(fn), stack[0], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    v0101 = stack[-3];
    fn = elt(env, 20); /* addsq */
    v0101 = (*qfn2(fn))(qenv(fn), v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    stack[-3] = v0101;
    goto v0126;

v0126:
    v0101 = stack[-4];
    v0101 = qcdr(v0101);
    stack[-4] = v0101;
    v0101 = stack[-4];
    if (!(v0101 == nil)) goto v0114;

v0127:
    v0101 = stack[-8];
    if (!consp(v0101)) goto v0128;
    v0101 = stack[-8];
    v0101 = qcar(v0101);
    v0101 = (consp(v0101) ? nil : lisp_true);
    goto v0129;

v0129:
    if (v0101 == nil) goto v0130;
    v0101 = stack[-8];
    fn = elt(env, 12); /* !*d2q */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    stack[-4] = v0101;
    goto v0131;

v0131:
    v0101 = qvalue(elt(env, 10)); /* !*exp */
    if (!(v0101 == nil)) goto v0132;
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    fn = elt(env, 21); /* mkprod */
    stack[0] = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    v0101 = stack[-4];
    v0101 = qcdr(v0101);
    fn = elt(env, 21); /* mkprod */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    v0101 = cons(stack[0], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    stack[-4] = v0101;
    goto v0132;

v0132:
    v0102 = stack[-3];
    v0101 = stack[-4];
    fn = elt(env, 20); /* addsq */
    v0101 = (*qfn2(fn))(qenv(fn), v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    stack[-4] = v0101;
    v0101 = stack[-2];
    if (v0101 == nil) { Lisp_Object res = stack[-4]; popv(11); return onevalue(res); }
    v0101 = stack[-2];
    v0101 = qcar(v0101);
    stack[-3] = v0101;
    v0101 = stack[-2];
    v0101 = qcdr(v0101);
    stack[-2] = v0101;
    goto v0131;

v0130:
    v0102 = stack[-3];
    v0101 = stack[-2];
    v0101 = cons(v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    stack[-2] = v0101;
    goto v0109;

v0128:
    v0101 = qvalue(elt(env, 1)); /* t */
    goto v0129;

v0122:
    v0102 = (Lisp_Object)17; /* 1 */
    v0101 = (Lisp_Object)17; /* 1 */
    v0101 = cons(v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    stack[-6] = v0101;
    goto v0123;

v0121:
    v0101 = stack[-5];
    v0101 = qcdr(v0101);
    stack[-5] = v0101;
    goto v0115;

v0119:
    v0101 = stack[-9];
    v0101 = qcdr(v0101);
    v0101 = qcdr(v0101);
    v0102 = qcar(v0101);
    v0101 = elt(env, 5); /* quotient */
    if (!consp(v0102)) goto v0133;
    v0102 = qcar(v0102);
    if (!(v0102 == v0101)) goto v0133;
    v0101 = stack[-9];
    v0101 = qcdr(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0102 = qcar(v0101);
    v0101 = (Lisp_Object)17; /* 1 */
    if (v0102 == v0101) goto v0134;
    v0101 = qvalue(elt(env, 2)); /* nil */
    goto v0120;

v0134:
    v0101 = stack[-9];
    v0101 = qcdr(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    v0101 = (is_number(v0101) ? lisp_true : nil);
    goto v0120;

v0133:
    v0101 = qvalue(elt(env, 2)); /* nil */
    goto v0120;

v0118:
    v0101 = qvalue(elt(env, 2)); /* nil */
    goto v0120;

v0117:
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    v0103 = qcar(v0101);
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0102 = qcar(v0101);
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    fn = elt(env, 17); /* subs2p */
    v0101 = (*qfnn(fn))(qenv(fn), 3, v0103, v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    stack[-6] = v0101;
    goto v0124;

v0116:
    v0101 = qvalue(elt(env, 8)); /* powlis1!* */
    stack[-5] = v0101;
    goto v0135;

v0135:
    v0101 = stack[-5];
    if (v0101 == nil) goto v0136;
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    v0105 = qcar(v0101);
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0104 = qcar(v0101);
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcdr(v0101);
    v0103 = qcar(v0101);
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    v0102 = qcar(v0101);
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    fn = elt(env, 22); /* mtchp */
    v0101 = (*qfnn(fn))(qenv(fn), 5, v0105, v0104, v0103, v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    stack[-6] = v0101;
    if (!(v0101 == nil)) goto v0124;
    v0101 = stack[-5];
    v0101 = qcdr(v0101);
    stack[-5] = v0101;
    goto v0135;

v0136:
    v0102 = stack[-9];
    v0101 = elt(env, 4); /* expt */
    if (!consp(v0102)) goto v0137;
    v0102 = qcar(v0102);
    if (!(v0102 == v0101)) goto v0137;
    v0101 = qvalue(elt(env, 9)); /* !*structure */
    v0101 = (v0101 == nil ? lisp_true : nil);
    goto v0138;

v0138:
    if (!(v0101 == nil)) goto v0139;
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    v0102 = qcar(v0101);
    v0101 = (Lisp_Object)17; /* 1 */
    v0101 = cons(v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    v0102 = ncons(v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    v0101 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0101 = CC_subs2f1(env, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    fn = elt(env, 19); /* multsq */
    v0102 = (*qfn2(fn))(qenv(fn), stack[0], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    v0101 = stack[-3];
    fn = elt(env, 20); /* addsq */
    v0101 = (*qfn2(fn))(qenv(fn), v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    stack[-3] = v0101;
    goto v0126;

v0139:
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    v0102 = qcdr(v0101);
    v0101 = (Lisp_Object)17; /* 1 */
    if (v0102 == v0101) goto v0140;
    v0101 = qvalue(elt(env, 2)); /* nil */
    goto v0141;

v0141:
    if (v0101 == nil) goto v0142;
    v0102 = stack[-9];
    v0101 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 23); /* mksq */
    v0101 = (*qfn2(fn))(qenv(fn), v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    stack[-6] = v0101;
    goto v0143;

v0143:
    stack[0] = stack[-6];
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0101 = CC_subs2f1(env, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    fn = elt(env, 19); /* multsq */
    v0102 = (*qfn2(fn))(qenv(fn), stack[0], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    v0101 = stack[-3];
    fn = elt(env, 20); /* addsq */
    v0101 = (*qfn2(fn))(qenv(fn), v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    stack[-3] = v0101;
    v0101 = stack[-4];
    v0101 = qcdr(v0101);
    stack[-4] = v0101;
    v0101 = stack[-4];
    if (v0101 == nil) goto v0127;
    else goto v0139;

v0142:
    v0101 = stack[-9];
    v0101 = qcdr(v0101);
    stack[0] = qcar(v0101);
    v0103 = elt(env, 11); /* times */
    v0101 = stack[-9];
    v0101 = qcdr(v0101);
    v0101 = qcdr(v0101);
    v0102 = qcar(v0101);
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0101 = list3(v0103, v0102, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    v0101 = list2(stack[0], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    fn = elt(env, 24); /* simpexpt */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-10];
    stack[-6] = v0101;
    goto v0143;

v0140:
    v0101 = stack[-9];
    v0101 = qcdr(v0101);
    v0102 = qcar(v0101);
    v0101 = elt(env, 4); /* expt */
    v0101 = Leqcar(nil, v0102, v0101);
    env = stack[-10];
    v0101 = (v0101 == nil ? lisp_true : nil);
    goto v0141;

v0137:
    v0101 = qvalue(elt(env, 2)); /* nil */
    goto v0138;

v0112:
    v0101 = qvalue(elt(env, 1)); /* t */
    goto v0113;

v0106:
    v0101 = qvalue(elt(env, 1)); /* t */
    goto v0107;
/* error exit handlers */
v0125:
    env = stack[-10];
    qvalue(elt(env, 7)) = stack[0]; /* dmode!* */
    qvalue(elt(env, 6)) = stack[-1]; /* alglist!* */
    popv(11);
    return nil;
v0110:
    popv(11);
    return nil;
}



/* Code for ofsf_posdefp */

static Lisp_Object CC_ofsf_posdefp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0144, v0145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_posdefp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0145 = v0000;
/* end of prologue */
    v0144 = qvalue(elt(env, 1)); /* !*rlpos */
    if (v0144 == nil) goto v0146;
    v0144 = v0145;
    {
        fn = elt(env, 2); /* ofsf_posdefp!-pos */
        return (*qfn1(fn))(qenv(fn), v0144);
    }

v0146:
    v0144 = v0145;
    {
        fn = elt(env, 3); /* sfto_tsqsumf */
        return (*qfn1(fn))(qenv(fn), v0144);
    }
}



/* Code for rl_susibin */

static Lisp_Object CC_rl_susibin(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0151, v0108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_susibin");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0151 = v0147;
    v0108 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_susibin!* */
    v0151 = list2(v0108, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-1];
    {
        Lisp_Object v0054 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0054, v0151);
    }
/* error exit handlers */
v0013:
    popv(2);
    return nil;
}



/* Code for sfto_dcontentf */

static Lisp_Object CC_sfto_dcontentf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0148, v0152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_dcontentf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0148 = v0000;
/* end of prologue */
    v0152 = v0148;
    v0148 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* sfto_dcontentf1 */
        return (*qfn2(fn))(qenv(fn), v0152, v0148);
    }
}



/* Code for omobj */

static Lisp_Object MS_CDECL CC_omobj(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0153, v0154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omobj");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omobj");
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
    v0153 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 4); /* compress!* */
    v0154 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[0];
    v0153 = qvalue(elt(env, 2)); /* omfuncs!* */
    v0153 = Lassoc(nil, v0154, v0153);
    v0154 = v0153;
    if (v0153 == nil) goto v0100;
    v0153 = v0154;
    v0153 = qcdr(v0153);
    v0154 = qcar(v0153);
    v0153 = qvalue(elt(env, 3)); /* nil */
    {
        popv(1);
        fn = elt(env, 5); /* apply */
        return (*qfn2(fn))(qenv(fn), v0154, v0153);
    }

v0100:
    v0153 = nil;
    { popv(1); return onevalue(v0153); }
/* error exit handlers */
v0109:
    popv(1);
    return nil;
}



/* Code for round!:mt */

static Lisp_Object CC_roundTmt(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for round:mt");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0147;
    stack[-2] = v0000;
/* end of prologue */
    v0167 = stack[-2];
    v0088 = elt(env, 1); /* !:rd!: */
    if (!consp(v0167)) goto v0027;
    v0167 = qcar(v0167);
    if (!(v0167 == v0088)) goto v0027;
    v0088 = stack[-2];
    v0088 = qcdr(v0088);
    v0088 = (consp(v0088) ? nil : lisp_true);
    v0088 = (v0088 == nil ? lisp_true : nil);
    goto v0168;

v0168:
    if (v0088 == nil) goto v0169;
    v0088 = stack[-1];
    v0088 = integerp(v0088);
    if (v0088 == nil) goto v0114;
    v0167 = stack[-1];
    v0088 = (Lisp_Object)1; /* 0 */
    v0088 = (Lisp_Object)greaterp2(v0167, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    v0088 = v0088 ? lisp_true : nil;
    env = stack[-4];
    goto v0106;

v0106:
    if (v0088 == nil) goto v0171;
    v0088 = stack[-2];
    v0088 = qcdr(v0088);
    v0088 = qcar(v0088);
    v0088 = Labsval(nil, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-4];
    fn = elt(env, 3); /* msd */
    v0167 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-4];
    v0088 = stack[-1];
    v0088 = difference2(v0167, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-4];
    v0167 = sub1(v0088);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-4];
    stack[-1] = v0167;
    v0088 = (Lisp_Object)1; /* 0 */
    v0088 = (Lisp_Object)lessp2(v0167, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    v0088 = v0088 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0088 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0167 = stack[-1];
    v0088 = (Lisp_Object)1; /* 0 */
    if (v0167 == v0088) goto v0172;
    stack[-3] = elt(env, 1); /* !:rd!: */
    v0088 = stack[-2];
    v0088 = qcdr(v0088);
    stack[0] = qcar(v0088);
    v0088 = stack[-1];
    v0088 = negate(v0088);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v0088);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-4];
    v0088 = stack[-2];
    v0088 = qcdr(v0088);
    v0167 = qcdr(v0088);
    v0088 = stack[-1];
    v0088 = plus2(v0167, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-4];
    v0088 = list2star(stack[-3], stack[0], v0088);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 4); /* round!:last */
        return (*qfn1(fn))(qenv(fn), v0088);
    }

v0172:
    v0088 = stack[-2];
    {
        popv(5);
        fn = elt(env, 4); /* round!:last */
        return (*qfn1(fn))(qenv(fn), v0088);
    }

v0171:
    v0088 = elt(env, 0); /* round!:mt */
    {
        popv(5);
        fn = elt(env, 5); /* bflerrmsg */
        return (*qfn1(fn))(qenv(fn), v0088);
    }

v0114:
    v0088 = qvalue(elt(env, 2)); /* nil */
    goto v0106;

v0169:
    v0088 = qvalue(elt(env, 2)); /* nil */
    goto v0106;

v0027:
    v0088 = qvalue(elt(env, 2)); /* nil */
    goto v0168;
/* error exit handlers */
v0170:
    popv(5);
    return nil;
}



/* Code for dm!-difference */

static Lisp_Object CC_dmKdifference(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dm-difference");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0147;
    v0054 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* zero2nil */
    v0007 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-1];
    v0054 = stack[0];
    fn = elt(env, 2); /* !:difference */
    v0054 = (*qfn2(fn))(qenv(fn), v0007, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    v0007 = v0054;
    v0054 = v0007;
    if (!(v0054 == nil)) { popv(2); return onevalue(v0007); }
    v0054 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v0054); }
/* error exit handlers */
v0003:
    popv(2);
    return nil;
}



/* Code for genp */

static Lisp_Object CC_genp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0049, v0003;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for genp");
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
    v0049 = v0000;
/* end of prologue */
    v0007 = v0049;
    if (!consp(v0007)) goto v0152;
    v0007 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0007); }

v0152:
    v0003 = v0049;
    v0007 = elt(env, 1); /* gen */
    v0007 = get(v0003, v0007);
    env = stack[0];
    if (!(v0007 == nil)) { popv(1); return onevalue(v0007); }
    v0007 = v0049;
    {
        popv(1);
        fn = elt(env, 3); /* mgenp */
        return (*qfn1(fn))(qenv(fn), v0007);
    }
}



/* Code for boundindp */

static Lisp_Object CC_boundindp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0115, v0116, v0135;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for boundindp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0135 = v0147;
    v0116 = v0000;
/* end of prologue */

v0173:
    v0114 = v0116;
    if (v0114 == nil) goto v0106;
    v0114 = v0116;
    v0115 = qcar(v0114);
    v0114 = v0135;
    v0114 = Lmember(nil, v0115, v0114);
    if (v0114 == nil) goto v0154;
    v0114 = v0116;
    v0114 = qcdr(v0114);
    v0116 = v0114;
    goto v0173;

v0154:
    v0114 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0114);

v0106:
    v0114 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0114);
}



/* Code for round!:last */

static Lisp_Object CC_roundTlast(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0181, v0094, v0163;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for round:last");
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
    v0094 = v0000;
/* end of prologue */
    v0181 = v0094;
    v0181 = qcdr(v0181);
    stack[0] = qcar(v0181);
    v0181 = v0094;
    v0181 = qcdr(v0181);
    v0181 = qcdr(v0181);
    v0094 = add1(v0181);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-3];
    v0181 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = stack[0];
    stack[-1] = v0094;
    stack[0] = v0181;
    v0094 = stack[-2];
    v0181 = (Lisp_Object)1; /* 0 */
    v0181 = (Lisp_Object)lessp2(v0094, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    v0181 = v0181 ? lisp_true : nil;
    env = stack[-3];
    if (v0181 == nil) goto v0145;
    v0181 = stack[-2];
    v0181 = negate(v0181);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-3];
    stack[-2] = v0181;
    v0181 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0181;
    goto v0145;

v0145:
    v0181 = stack[-2];
    v0181 = Levenp(nil, v0181);
    env = stack[-3];
    if (v0181 == nil) goto v0183;
    v0094 = stack[-2];
    v0181 = (Lisp_Object)-15; /* -1 */
    v0181 = ash(v0094, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-3];
    goto v0154;

v0154:
    stack[-2] = v0181;
    v0181 = stack[0];
    if (v0181 == nil) goto v0112;
    v0181 = stack[-2];
    v0181 = negate(v0181);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-3];
    stack[-2] = v0181;
    goto v0112;

v0112:
    v0163 = elt(env, 3); /* !:rd!: */
    v0094 = stack[-2];
    v0181 = stack[-1];
    popv(4);
    return list2star(v0163, v0094, v0181);

v0183:
    v0094 = stack[-2];
    v0181 = (Lisp_Object)-15; /* -1 */
    v0181 = ash(v0094, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-3];
    v0181 = add1(v0181);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-3];
    goto v0154;
/* error exit handlers */
v0182:
    popv(4);
    return nil;
}



/* Code for abs!: */

static Lisp_Object CC_absT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0135, v0183;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for abs:");
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
    v0135 = stack[0];
    v0135 = qcdr(v0135);
    v0183 = qcar(v0135);
    v0135 = (Lisp_Object)1; /* 0 */
    v0135 = (Lisp_Object)greaterp2(v0183, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    v0135 = v0135 ? lisp_true : nil;
    env = stack[-2];
    if (!(v0135 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = elt(env, 1); /* !:rd!: */
    v0135 = stack[0];
    v0135 = qcdr(v0135);
    v0135 = qcar(v0135);
    v0183 = negate(v0135);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    v0135 = stack[0];
    v0135 = qcdr(v0135);
    v0135 = qcdr(v0135);
    {
        Lisp_Object v0185 = stack[-1];
        popv(3);
        return list2star(v0185, v0183, v0135);
    }
/* error exit handlers */
v0131:
    popv(3);
    return nil;
}



/* Code for simpminus */

static Lisp_Object CC_simpminus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0168, v0144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpminus");
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
    v0168 = v0000;
/* end of prologue */
    v0144 = v0168;
    v0168 = elt(env, 1); /* minus */
    fn = elt(env, 2); /* carx */
    v0168 = (*qfn2(fn))(qenv(fn), v0144, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[0];
    fn = elt(env, 3); /* simp */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0145;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); /* negsq */
        return (*qfn1(fn))(qenv(fn), v0168);
    }
/* error exit handlers */
v0145:
    popv(1);
    return nil;
}



/* Code for getroad */

static Lisp_Object CC_getroad(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0185, v0179, v0180, v0187;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getroad");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0180 = v0147;
    v0187 = v0000;
/* end of prologue */

v0173:
    v0185 = v0180;
    if (v0185 == nil) goto v0106;
    v0185 = v0187;
    v0179 = qcdr(v0185);
    v0185 = v0180;
    v0185 = qcar(v0185);
    v0185 = qcdr(v0185);
    if (equal(v0179, v0185)) goto v0003;
    v0185 = v0180;
    v0185 = qcdr(v0185);
    v0180 = v0185;
    goto v0173;

v0003:
    v0185 = v0187;
    v0185 = qcar(v0185);
    v0179 = v0180;
    v0179 = qcar(v0179);
    v0179 = qcar(v0179);
    fn = elt(env, 1); /* qassoc */
    v0185 = (*qfn2(fn))(qenv(fn), v0185, v0179);
    errexit();
    v0185 = qcdr(v0185);
    return onevalue(v0185);

v0106:
    v0185 = (Lisp_Object)17; /* 1 */
    return onevalue(v0185);
}



/* Code for getrmacro */

static Lisp_Object CC_getrmacro(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0189, v0190, v0164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getrmacro");
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
    v0189 = stack[0];
    if (symbolp(v0189)) goto v0106;
    v0189 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0189); }

v0106:
    v0189 = stack[0];
    fn = elt(env, 5); /* getd */
    v0189 = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-1];
    v0164 = v0189;
    if (v0189 == nil) goto v0154;
    v0189 = v0164;
    v0190 = qcar(v0189);
    v0189 = elt(env, 2); /* macro */
    if (v0190 == v0189) { popv(2); return onevalue(v0164); }
    else goto v0154;

v0154:
    v0190 = stack[0];
    v0189 = elt(env, 3); /* inline */
    v0189 = get(v0190, v0189);
    env = stack[-1];
    v0164 = v0189;
    if (v0189 == nil) goto v0169;
    v0189 = elt(env, 3); /* inline */
    v0190 = v0164;
    popv(2);
    return cons(v0189, v0190);

v0169:
    v0190 = stack[0];
    v0189 = elt(env, 4); /* smacro */
    v0189 = get(v0190, v0189);
    env = stack[-1];
    v0164 = v0189;
    if (v0189 == nil) goto v0191;
    v0189 = elt(env, 4); /* smacro */
    v0190 = v0164;
    popv(2);
    return cons(v0189, v0190);

v0191:
    v0189 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0189); }
/* error exit handlers */
v0174:
    popv(2);
    return nil;
}



/* Code for dp_diff */

static Lisp_Object CC_dp_diff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0168, v0144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_diff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0168 = v0147;
    v0144 = v0000;
/* end of prologue */
    stack[0] = v0144;
    fn = elt(env, 1); /* dp_neg */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-1];
    {
        Lisp_Object v0149 = stack[0];
        popv(2);
        fn = elt(env, 2); /* dp_sum */
        return (*qfn2(fn))(qenv(fn), v0149, v0168);
    }
/* error exit handlers */
v0184:
    popv(2);
    return nil;
}



/* Code for resimp */

static Lisp_Object CC_resimp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0100, v0107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for resimp");
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
    v0107 = v0000;
/* end of prologue */
    v0100 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v0100; /* varstack!* */
    v0100 = v0107;
    fn = elt(env, 3); /* resimp1 */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0146;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    { popv(2); return onevalue(v0100); }
/* error exit handlers */
v0146:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    popv(2);
    return nil;
}



/* Code for insert_pv1 */

static Lisp_Object MS_CDECL CC_insert_pv1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0147,
                         Lisp_Object v0188, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0197, v0121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "insert_pv1");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for insert_pv1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0188,v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0147,v0188);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0188;
    stack[-1] = v0147;
    stack[-2] = v0000;
/* end of prologue */

v0107:
    v0197 = stack[-1];
    if (v0197 == nil) goto v0148;
    v0197 = stack[-2];
    if (v0197 == nil) goto v0111;
    v0197 = stack[-1];
    v0197 = qcar(v0197);
    v0197 = qcar(v0197);
    v0121 = qcdr(v0197);
    v0197 = stack[-2];
    v0197 = qcar(v0197);
    v0197 = qcdr(v0197);
    v0197 = (Lisp_Object)greaterp2(v0121, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    v0197 = v0197 ? lisp_true : nil;
    env = stack[-4];
    if (v0197 == nil) goto v0161;
    v0197 = stack[-1];
    v0197 = qcdr(v0197);
    stack[-3] = v0197;
    v0197 = stack[-1];
    v0121 = qcar(v0197);
    v0197 = stack[-2];
    fn = elt(env, 2); /* reduce_pv */
    v0197 = (*qfn2(fn))(qenv(fn), v0121, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    fn = elt(env, 3); /* pv_renorm */
    v0121 = (*qfn1(fn))(qenv(fn), v0197);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    v0197 = stack[0];
    v0197 = cons(v0121, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    stack[0] = v0197;
    v0197 = stack[-3];
    stack[-1] = v0197;
    goto v0107;

v0161:
    v0197 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v0197;
    v0121 = stack[-2];
    v0197 = stack[0];
    v0197 = cons(v0121, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    stack[0] = v0197;
    v0197 = stack[-3];
    stack[-2] = v0197;
    goto v0107;

v0111:
    v0197 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0197;
    v0197 = stack[-1];
    v0197 = qcdr(v0197);
    stack[-3] = v0197;
    v0197 = stack[-1];
    v0121 = qcar(v0197);
    v0197 = stack[0];
    v0197 = cons(v0121, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    stack[0] = v0197;
    v0197 = stack[-3];
    stack[-1] = v0197;
    goto v0107;

v0148:
    v0197 = stack[-2];
    if (v0197 == nil) goto v0184;
    v0121 = stack[-2];
    v0197 = stack[0];
    v0197 = cons(v0121, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0198;
        popv(5);
        return Lnreverse(nil, v0197);

v0184:
    v0197 = stack[0];
        popv(5);
        return Lnreverse(nil, v0197);
/* error exit handlers */
v0198:
    popv(5);
    return nil;
}



/* Code for modplus!: */

static Lisp_Object CC_modplusT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0145, v0184;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for modplus:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0145 = v0147;
    v0184 = v0000;
/* end of prologue */
    v0184 = qcdr(v0184);
    v0145 = qcdr(v0145);
    fn = elt(env, 1); /* general!-modular!-plus */
    v0145 = (*qfn2(fn))(qenv(fn), v0184, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v0145);
    }
/* error exit handlers */
v0149:
    popv(1);
    return nil;
}



/* Code for kernord */

static Lisp_Object CC_kernord(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for kernord");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0007 = v0147;
    stack[0] = v0000;
/* end of prologue */
    v0049 = stack[0];
    fn = elt(env, 1); /* kernord!-split */
    v0007 = (*qfn2(fn))(qenv(fn), v0049, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    stack[0] = v0007;
    v0007 = stack[0];
    v0007 = qcar(v0007);
    fn = elt(env, 2); /* kernord!-sort */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    fn = elt(env, 2); /* kernord!-sort */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    {
        Lisp_Object v0153 = stack[-1];
        popv(3);
        return Lappend(nil, v0153, v0007);
    }
/* error exit handlers */
v0027:
    popv(3);
    return nil;
}



/* Code for ibalp_minclnr */

static Lisp_Object CC_ibalp_minclnr(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0201, v0172;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_minclnr");
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
    v0172 = v0000;
/* end of prologue */
    v0201 = (Lisp_Object)1600001; /* 100000 */
    stack[-2] = v0201;
    v0201 = v0172;
    stack[-1] = v0201;
    goto v0146;

v0146:
    v0201 = stack[-1];
    if (v0201 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0201 = stack[-1];
    v0201 = qcar(v0201);
    stack[0] = v0201;
    v0201 = stack[0];
    v0201 = qcdr(v0201);
    v0201 = qcdr(v0201);
    v0201 = qcdr(v0201);
    v0201 = qcdr(v0201);
    v0201 = qcar(v0201);
    if (!(v0201 == nil)) goto v0013;
    v0201 = stack[0];
    v0201 = qcdr(v0201);
    v0201 = qcdr(v0201);
    v0172 = qcar(v0201);
    v0201 = stack[0];
    v0201 = qcdr(v0201);
    v0201 = qcdr(v0201);
    v0201 = qcdr(v0201);
    v0201 = qcar(v0201);
    v0172 = plus2(v0172, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    v0201 = stack[-2];
    v0201 = (Lisp_Object)lessp2(v0172, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    v0201 = v0201 ? lisp_true : nil;
    env = stack[-3];
    if (v0201 == nil) goto v0013;
    v0201 = stack[0];
    v0201 = qcdr(v0201);
    v0201 = qcdr(v0201);
    v0172 = qcar(v0201);
    v0201 = stack[0];
    v0201 = qcdr(v0201);
    v0201 = qcdr(v0201);
    v0201 = qcdr(v0201);
    v0201 = qcar(v0201);
    v0201 = plus2(v0172, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-3];
    stack[-2] = v0201;
    goto v0013;

v0013:
    v0201 = stack[-1];
    v0201 = qcdr(v0201);
    stack[-1] = v0201;
    goto v0146;
/* error exit handlers */
v0097:
    popv(4);
    return nil;
}



/* Code for sfto_mvartest */

static Lisp_Object CC_sfto_mvartest(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0115, v0116;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_mvartest");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0115 = v0147;
    v0116 = v0000;
/* end of prologue */
    v0114 = v0116;
    if (!consp(v0114)) goto v0146;
    v0114 = v0116;
    v0114 = qcar(v0114);
    v0114 = (consp(v0114) ? nil : lisp_true);
    goto v0106;

v0106:
    if (v0114 == nil) goto v0151;
    v0114 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0114);

v0151:
    v0114 = v0116;
    v0114 = qcar(v0114);
    v0114 = qcar(v0114);
    v0114 = qcar(v0114);
    v0114 = (v0114 == v0115 ? lisp_true : nil);
    return onevalue(v0114);

v0146:
    v0114 = qvalue(elt(env, 1)); /* t */
    goto v0106;
}



/* Code for powers2 */

static Lisp_Object MS_CDECL CC_powers2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0147,
                         Lisp_Object v0188, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0164, v0175, v0174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "powers2");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for powers2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0188,v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0147,v0188);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0188;
    stack[-1] = v0147;
    stack[-2] = v0000;
/* end of prologue */

v0107:
    v0164 = stack[-2];
    if (!consp(v0164)) goto v0145;
    v0164 = stack[-2];
    v0164 = qcar(v0164);
    v0164 = (consp(v0164) ? nil : lisp_true);
    goto v0144;

v0144:
    if (v0164 == nil) goto v0131;
    v0164 = stack[-2];
    if (v0164 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0175 = stack[0];
    v0164 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); /* powers4 */
        return (*qfn2(fn))(qenv(fn), v0175, v0164);
    }

v0131:
    v0164 = stack[-2];
    v0164 = qcar(v0164);
    v0164 = qcdr(v0164);
    stack[-3] = v0164;
    v0164 = stack[-2];
    v0174 = qcdr(v0164);
    v0175 = stack[-1];
    v0164 = stack[0];
    v0164 = CC_powers2(env, 3, v0174, v0175, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    stack[-1] = v0164;
    v0164 = stack[-2];
    v0164 = qcar(v0164);
    v0175 = qcar(v0164);
    v0164 = stack[0];
    v0164 = cons(v0175, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    stack[0] = v0164;
    v0164 = stack[-3];
    stack[-2] = v0164;
    goto v0107;

v0145:
    v0164 = qvalue(elt(env, 1)); /* t */
    goto v0144;
/* error exit handlers */
v0201:
    popv(5);
    return nil;
}



/* Code for rank */

static Lisp_Object CC_rank(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0159, v0160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rank");
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
    v0159 = qvalue(elt(env, 1)); /* !*mcd */
    if (v0159 == nil) goto v0152;
    v0159 = stack[-2];
    v0159 = qcar(v0159);
    v0159 = qcar(v0159);
    v0159 = qcdr(v0159);
    { popv(5); return onevalue(v0159); }

v0152:
    v0159 = stack[-2];
    v0159 = qcar(v0159);
    v0159 = qcar(v0159);
    v0159 = qcdr(v0159);
    stack[-1] = v0159;
    v0159 = stack[-2];
    v0159 = qcar(v0159);
    v0159 = qcar(v0159);
    v0159 = qcar(v0159);
    stack[0] = v0159;
    goto v0151;

v0151:
    v0159 = stack[-2];
    v0159 = qcar(v0159);
    v0159 = qcar(v0159);
    v0159 = qcdr(v0159);
    stack[-3] = v0159;
    v0159 = stack[-2];
    v0159 = qcdr(v0159);
    if (v0159 == nil) goto v0185;
    v0159 = stack[-2];
    v0159 = qcdr(v0159);
    stack[-2] = v0159;
    v0160 = stack[-2];
    v0159 = stack[0];
    fn = elt(env, 2); /* degr */
    v0160 = (*qfn2(fn))(qenv(fn), v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    v0159 = (Lisp_Object)1; /* 0 */
    if (!(v0160 == v0159)) goto v0151;
    v0160 = stack[-3];
    v0159 = (Lisp_Object)1; /* 0 */
    v0159 = (Lisp_Object)lessp2(v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    v0159 = v0159 ? lisp_true : nil;
    env = stack[-4];
    if (v0159 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0160 = stack[-1];
    v0159 = (Lisp_Object)1; /* 0 */
    v0159 = (Lisp_Object)lessp2(v0160, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    v0159 = v0159 ? lisp_true : nil;
    if (v0159 == nil) goto v0205;
    v0159 = stack[-3];
    popv(5);
    return negate(v0159);

v0205:
    v0160 = stack[-1];
    v0159 = stack[-3];
    popv(5);
    return difference2(v0160, v0159);

v0185:
    v0160 = stack[-1];
    v0159 = stack[-3];
    popv(5);
    return difference2(v0160, v0159);
/* error exit handlers */
v0089:
    popv(5);
    return nil;
}



/* Code for mathml */

static Lisp_Object MS_CDECL CC_mathml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mathml");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mathml");
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
    fn = elt(env, 2); /* lex */
    v0107 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* sub_math */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v0106:
    popv(1);
    return nil;
}



/* Code for bcsum */

static Lisp_Object CC_bcsum(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0180, v0187, v0195;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcsum");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0147;
    stack[-1] = v0000;
/* end of prologue */
    v0180 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v0180 == nil) goto v0007;
    v0187 = stack[-1];
    v0180 = stack[0];
    v0180 = plus2(v0187, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v0180);
    }

v0007:
    v0195 = stack[-1];
    v0187 = stack[0];
    v0180 = elt(env, 2); /* plus2 */
    fn = elt(env, 4); /* bcint2op */
    v0180 = (*qfnn(fn))(qenv(fn), 3, v0195, v0187, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-2];
    if (!(v0180 == nil)) { popv(3); return onevalue(v0180); }
    v0187 = stack[-1];
    v0180 = stack[0];
    fn = elt(env, 5); /* addsq */
    v0180 = (*qfn2(fn))(qenv(fn), v0187, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); /* bccheckz */
        return (*qfn1(fn))(qenv(fn), v0180);
    }
/* error exit handlers */
v0169:
    popv(3);
    return nil;
}



/* Code for mknwedge */

static Lisp_Object CC_mknwedge(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0186, v0013;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mknwedge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0013 = v0000;
/* end of prologue */
    v0186 = v0013;
    v0186 = qcdr(v0186);
    if (v0186 == nil) goto v0149;
    v0186 = elt(env, 1); /* wedge */
    return cons(v0186, v0013);

v0149:
    v0186 = v0013;
    v0186 = qcar(v0186);
    return onevalue(v0186);
}



/* Code for worderp */

static Lisp_Object CC_worderp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0214, v0215, v0216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for worderp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0147;
    stack[-1] = v0000;
/* end of prologue */

v0173:
    v0214 = stack[-1];
    if (!consp(v0214)) goto v0183;
    v0214 = stack[-1];
    v0214 = qcar(v0214);
    if (!symbolp(v0214)) v0214 = nil;
    else { v0214 = qfastgets(v0214);
           if (v0214 != nil) { v0214 = elt(v0214, 16); /* indexvar */
#ifdef RECORD_GET
             if (v0214 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v0214 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v0214 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v0214 == SPID_NOPROP) v0214 = nil; else v0214 = lisp_true; }}
#endif
    if (v0214 == nil) goto v0115;
    v0214 = stack[0];
    if (!consp(v0214)) goto v0109;
    v0214 = stack[0];
    v0214 = qcar(v0214);
    if (!symbolp(v0214)) v0214 = nil;
    else { v0214 = qfastgets(v0214);
           if (v0214 != nil) { v0214 = elt(v0214, 16); /* indexvar */
#ifdef RECORD_GET
             if (v0214 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v0214 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v0214 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v0214 == SPID_NOPROP) v0214 = nil; else v0214 = lisp_true; }}
#endif
    goto v0152;

v0152:
    if (v0214 == nil) goto v0146;
    v0215 = stack[-1];
    v0214 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* indexvarordp */
        return (*qfn2(fn))(qenv(fn), v0215, v0214);
    }

v0146:
    v0214 = stack[-1];
    if (!consp(v0214)) goto v0177;
    v0215 = stack[-1];
    v0214 = qvalue(elt(env, 3)); /* kord!* */
    v0214 = Lmemq(nil, v0215, v0214);
    goto v0217;

v0217:
    if (v0214 == nil) goto v0218;
    v0214 = stack[0];
    if (!consp(v0214)) goto v0181;
    v0215 = stack[0];
    v0214 = qvalue(elt(env, 3)); /* kord!* */
    v0214 = Lmemq(nil, v0215, v0214);
    goto v0176;

v0176:
    if (v0214 == nil) goto v0219;
    v0215 = stack[-1];
    v0214 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* ordop */
        return (*qfn2(fn))(qenv(fn), v0215, v0214);
    }

v0219:
    v0214 = stack[0];
    fn = elt(env, 6); /* peel */
    v0214 = (*qfn1(fn))(qenv(fn), v0214);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-2];
    v0216 = v0214;
    v0215 = stack[-1];
    v0214 = v0216;
    if (v0215 == v0214) goto v0198;
    v0214 = stack[-1];
    v0215 = v0216;
    stack[-1] = v0214;
    stack[0] = v0215;
    goto v0173;

v0198:
    v0214 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v0214); }

v0181:
    v0214 = qvalue(elt(env, 2)); /* t */
    goto v0176;

v0218:
    v0214 = stack[0];
    if (!consp(v0214)) goto v0167;
    v0215 = stack[0];
    v0214 = qvalue(elt(env, 3)); /* kord!* */
    v0214 = Lmemq(nil, v0215, v0214);
    goto v0088;

v0088:
    if (v0214 == nil) goto v0076;
    v0214 = stack[-1];
    fn = elt(env, 6); /* peel */
    v0214 = (*qfn1(fn))(qenv(fn), v0214);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-2];
    v0216 = v0214;
    v0215 = v0216;
    v0214 = stack[0];
    if (v0215 == v0214) goto v0221;
    v0215 = v0216;
    v0214 = stack[0];
    stack[-1] = v0215;
    stack[0] = v0214;
    goto v0173;

v0221:
    v0214 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0214); }

v0076:
    v0214 = stack[-1];
    fn = elt(env, 6); /* peel */
    v0214 = (*qfn1(fn))(qenv(fn), v0214);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-2];
    stack[-1] = v0214;
    v0214 = stack[0];
    fn = elt(env, 6); /* peel */
    v0214 = (*qfn1(fn))(qenv(fn), v0214);
    nil = C_nil;
    if (exception_pending()) goto v0220;
    env = stack[-2];
    stack[0] = v0214;
    goto v0173;

v0167:
    v0214 = qvalue(elt(env, 2)); /* t */
    goto v0088;

v0177:
    v0214 = qvalue(elt(env, 2)); /* t */
    goto v0217;

v0109:
    v0214 = qvalue(elt(env, 1)); /* nil */
    goto v0152;

v0115:
    v0214 = qvalue(elt(env, 1)); /* nil */
    goto v0152;

v0183:
    v0214 = qvalue(elt(env, 1)); /* nil */
    goto v0152;
/* error exit handlers */
v0220:
    popv(3);
    return nil;
}



/* Code for vecopp */

static Lisp_Object CC_vecopp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0177, v0178, v0098;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vecopp");
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
    v0098 = v0000;
/* end of prologue */
    v0177 = v0098;
    if (symbolp(v0177)) goto v0144;
    v0177 = qvalue(elt(env, 1)); /* nil */
    goto v0100;

v0100:
    if (!(v0177 == nil)) return onevalue(v0177);
    v0177 = v0098;
    if (!consp(v0177)) goto v0218;
    v0177 = v0098;
    v0177 = qcar(v0177);
    if (!symbolp(v0177)) v0178 = nil;
    else { v0178 = qfastgets(v0177);
           if (v0178 != nil) { v0178 = elt(v0178, 18); /* phystype */
#ifdef RECORD_GET
             if (v0178 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0178 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0178 == SPID_NOPROP) v0178 = nil; }}
#endif
    v0177 = elt(env, 2); /* vector */
    if (v0178 == v0177) goto v0154;
    v0177 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0177);

v0154:
    v0177 = v0098;
    v0177 = qcdr(v0177);
    v0177 = qcar(v0177);
    fn = elt(env, 3); /* isanindex */
    v0177 = (*qfn1(fn))(qenv(fn), v0177);
    errexit();
    v0177 = (v0177 == nil ? lisp_true : nil);
    return onevalue(v0177);

v0218:
    v0177 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0177);

v0144:
    v0177 = v0098;
    if (!symbolp(v0177)) v0178 = nil;
    else { v0178 = qfastgets(v0177);
           if (v0178 != nil) { v0178 = elt(v0178, 18); /* phystype */
#ifdef RECORD_GET
             if (v0178 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0178 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0178 == SPID_NOPROP) v0178 = nil; }}
#endif
    v0177 = elt(env, 2); /* vector */
    v0177 = (v0178 == v0177 ? lisp_true : nil);
    goto v0100;
}



/* Code for !*ssave */

static Lisp_Object CC_Hssave(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0121, v0205, v0156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *ssave");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0147;
    stack[-3] = v0000;
/* end of prologue */
    v0121 = qvalue(elt(env, 1)); /* !*uncached */
    if (!(v0121 == nil)) goto v0100;
    stack[-4] = qvalue(elt(env, 2)); /* alglist!* */
    v0205 = qvalue(elt(env, 3)); /* !*sub2 */
    v0121 = stack[-3];
    v0205 = cons(v0205, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-5];
    v0121 = qvalue(elt(env, 2)); /* alglist!* */
    v0121 = qcar(v0121);
    stack[-1] = v0205;
    stack[0] = v0121;
    v0121 = stack[0];
    if (v0121 == nil) goto v0135;
    v0205 = qvalue(elt(env, 5)); /* alglist_count!* */
    v0121 = qvalue(elt(env, 6)); /* alglist_limit!* */
    v0121 = (Lisp_Object)greaterp2(v0205, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    v0121 = v0121 ? lisp_true : nil;
    env = stack[-5];
    goto v0116;

v0116:
    if (v0121 == nil) goto v0097;
    v0121 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 5)) = v0121; /* alglist_count!* */
    v0156 = (Lisp_Object)161; /* 10 */
    v0205 = (Lisp_Object)49; /* 3 */
    v0121 = elt(env, 7); /* 2.0 */
    fn = elt(env, 9); /* mkhash */
    v0121 = (*qfnn(fn))(qenv(fn), 3, v0156, v0205, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-5];
    stack[0] = v0121;
    v0156 = stack[-2];
    v0205 = stack[0];
    v0121 = stack[-1];
    fn = elt(env, 10); /* puthash */
    v0121 = (*qfnn(fn))(qenv(fn), 3, v0156, v0205, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-5];
    v0121 = stack[0];
    goto v0145;

v0145:
    v0121 = Lrplaca(nil, stack[-4], v0121);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-5];
    goto v0100;

v0100:
    v0121 = qvalue(elt(env, 8)); /* simpcount!* */
    v0121 = sub1(v0121);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-5];
    qvalue(elt(env, 8)) = v0121; /* simpcount!* */
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v0097:
    v0156 = stack[-2];
    v0205 = stack[0];
    v0121 = stack[-1];
    fn = elt(env, 10); /* puthash */
    v0121 = (*qfnn(fn))(qenv(fn), 3, v0156, v0205, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-5];
    v0121 = qvalue(elt(env, 5)); /* alglist_count!* */
    v0121 = add1(v0121);
    nil = C_nil;
    if (exception_pending()) goto v0225;
    env = stack[-5];
    qvalue(elt(env, 5)) = v0121; /* alglist_count!* */
    v0121 = stack[0];
    goto v0145;

v0135:
    v0121 = qvalue(elt(env, 4)); /* t */
    goto v0116;
/* error exit handlers */
v0225:
    popv(6);
    return nil;
}



/* Code for pv_sort2a */

static Lisp_Object CC_pv_sort2a(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0160, v0211;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pv_sort2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0147;
    stack[-1] = v0000;
/* end of prologue */

v0173:
    v0160 = stack[0];
    v0160 = qcdr(v0160);
    if (v0160 == nil) goto v0150;
    v0160 = stack[-1];
    v0211 = qcdr(v0160);
    v0160 = stack[0];
    v0160 = qcar(v0160);
    v0160 = qcdr(v0160);
    v0160 = (Lisp_Object)greaterp2(v0211, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    v0160 = v0160 ? lisp_true : nil;
    env = stack[-3];
    if (v0160 == nil) goto v0161;
    v0160 = stack[0];
    v0160 = qcdr(v0160);
    stack[0] = v0160;
    goto v0173;

v0161:
    v0160 = stack[0];
    v0211 = qcar(v0160);
    v0160 = stack[0];
    v0160 = qcdr(v0160);
    v0160 = cons(v0211, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-3];
    stack[-2] = v0160;
    v0211 = stack[0];
    v0160 = stack[-1];
    v0211 = Lrplaca(nil, v0211, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    v0160 = stack[-2];
        popv(4);
        return Lrplacd(nil, v0211, v0160);

v0150:
    v0160 = stack[-1];
    v0211 = qcdr(v0160);
    v0160 = stack[0];
    v0160 = qcar(v0160);
    v0160 = qcdr(v0160);
    v0160 = (Lisp_Object)greaterp2(v0211, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    v0160 = v0160 ? lisp_true : nil;
    env = stack[-3];
    if (v0160 == nil) goto v0131;
    v0160 = stack[-1];
    v0160 = ncons(v0160);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    {
        Lisp_Object v0229 = stack[0];
        popv(4);
        return Lrplacd(nil, v0229, v0160);
    }

v0131:
    v0160 = stack[0];
    v0211 = qcar(v0160);
    v0160 = stack[0];
    v0160 = qcdr(v0160);
    v0160 = cons(v0211, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-3];
    stack[-2] = v0160;
    v0211 = stack[0];
    v0160 = stack[-1];
    v0211 = Lrplaca(nil, v0211, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    v0160 = stack[-2];
        popv(4);
        return Lrplacd(nil, v0211, v0160);
/* error exit handlers */
v0089:
    popv(4);
    return nil;
}



/* Code for mkgi */

static Lisp_Object CC_mkgi(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0145, v0184, v0149;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkgi");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0145 = v0147;
    v0184 = v0000;
/* end of prologue */
    v0149 = elt(env, 1); /* !:gi!: */
    return list2star(v0149, v0184, v0145);
}



/* Code for tayexp!-min2 */

static Lisp_Object CC_tayexpKmin2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108, v0186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tayexp-min2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0147;
    stack[-1] = v0000;
/* end of prologue */
    v0186 = stack[-1];
    v0108 = stack[0];
    fn = elt(env, 1); /* tayexp!-lessp */
    v0108 = (*qfn2(fn))(qenv(fn), v0186, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    if (v0108 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
/* error exit handlers */
v0007:
    popv(2);
    return nil;
}



/* Code for qqe_qtidp */

static Lisp_Object CC_qqe_qtidp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0152, v0168;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_qtidp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0152 = v0000;
/* end of prologue */
    if (!symbolp(v0152)) v0152 = nil;
    else { v0152 = qfastgets(v0152);
           if (v0152 != nil) { v0152 = elt(v0152, 10); /* idtype */
#ifdef RECORD_GET
             if (v0152 != SPID_NOPROP)
                record_get(elt(fastget_names, 10), 1);
             else record_get(elt(fastget_names, 10), 0),
                v0152 = nil; }
           else record_get(elt(fastget_names, 10), 0); }
#else
             if (v0152 == SPID_NOPROP) v0152 = nil; }}
#endif
    v0168 = elt(env, 1); /* qt */
    v0152 = (v0152 == v0168 ? lisp_true : nil);
    return onevalue(v0152);
}



/* Code for emtch */

static Lisp_Object CC_emtch(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for emtch");
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
    stack[0] = v0000;
/* end of prologue */
    v0054 = stack[0];
    if (!consp(v0054)) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v0054 = stack[0];
    fn = elt(env, 1); /* opmtch */
    v0054 = (*qfn1(fn))(qenv(fn), v0054);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    v0007 = v0054;
    v0054 = v0007;
    if (v0054 == nil) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    else { popv(1); return onevalue(v0007); }
/* error exit handlers */
v0003:
    popv(1);
    return nil;
}



/* Code for subscriptedvarp */

static Lisp_Object CC_subscriptedvarp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0154, v0109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subscriptedvarp");
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
    v0109 = qvalue(elt(env, 1)); /* nil */
    v0154 = stack[0];
    fn = elt(env, 3); /* symtabget */
    v0154 = (*qfn2(fn))(qenv(fn), v0109, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-1];
    v0109 = Llength(nil, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-1];
    v0154 = (Lisp_Object)33; /* 2 */
    v0154 = (Lisp_Object)greaterp2(v0109, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    v0154 = v0154 ? lisp_true : nil;
    env = stack[-1];
    if (!(v0154 == nil)) { popv(2); return onevalue(v0154); }
    v0154 = stack[0];
    v0109 = elt(env, 2); /* subscripted */
        popv(2);
        return Lflagp(nil, v0154, v0109);
/* error exit handlers */
v0114:
    popv(2);
    return nil;
}



/* Code for fast!-column!-dim */

static Lisp_Object CC_fastKcolumnKdim(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0168, v0144;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fast-column-dim");
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
    v0168 = v0000;
/* end of prologue */
    v0144 = v0168;
    v0168 = (Lisp_Object)1; /* 0 */
    v0168 = *(Lisp_Object *)((char *)v0144 + (CELL-TAG_VECTOR) + ((int32_t)v0168/(16/CELL)));
    v0168 = Lupbv(nil, v0168);
    errexit();
    return add1(v0168);
}



/* Code for xdegree */

static Lisp_Object CC_xdegree(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0145, v0184;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xdegree");
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
    v0145 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* deg!*form */
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    errexit();
    v0184 = v0145;
    v0145 = v0184;
    if (!(v0145 == nil)) return onevalue(v0184);
    v0145 = (Lisp_Object)1; /* 0 */
    return onevalue(v0145);
}



/* Code for deg!*form */

static Lisp_Object CC_degHform(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0238, v0079, v0078;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for deg*form");
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

v0239:
    v0238 = stack[0];
    if (!consp(v0238)) goto v0196;
    v0238 = stack[0];
    v0238 = qcar(v0238);
    v0078 = v0238;
    v0238 = v0078;
    if (!symbolp(v0238)) v0238 = nil;
    else { v0238 = qfastgets(v0238);
           if (v0238 != nil) { v0238 = elt(v0238, 16); /* indexvar */
#ifdef RECORD_GET
             if (v0238 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v0238 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v0238 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v0238 == SPID_NOPROP) v0238 = nil; else v0238 = lisp_true; }}
#endif
    if (v0238 == nil) goto v0240;
    v0238 = stack[0];
    v0238 = qcdr(v0238);
    v0079 = Llength(nil, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-2];
    v0238 = stack[0];
    v0238 = qcar(v0238);
    if (!symbolp(v0238)) v0238 = nil;
    else { v0238 = qfastgets(v0238);
           if (v0238 != nil) { v0238 = elt(v0238, 25); /* ifdegree */
#ifdef RECORD_GET
             if (v0238 != SPID_NOPROP)
                record_get(elt(fastget_names, 25), 1);
             else record_get(elt(fastget_names, 25), 0),
                v0238 = nil; }
           else record_get(elt(fastget_names, 25), 0); }
#else
             if (v0238 == SPID_NOPROP) v0238 = nil; }}
#endif
    v0238 = Lassoc(nil, v0079, v0238);
    v0079 = v0238;
    v0238 = v0079;
    if (v0238 == nil) goto v0177;
    v0238 = v0079;
    v0238 = qcdr(v0238);
    { popv(3); return onevalue(v0238); }

v0177:
    v0238 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0238); }

v0240:
    v0079 = v0078;
    v0238 = elt(env, 2); /* wedge */
    if (v0079 == v0238) goto v0099;
    v0079 = v0078;
    v0238 = elt(env, 3); /* d */
    if (v0079 == v0238) goto v0228;
    v0079 = v0078;
    v0238 = elt(env, 4); /* hodge */
    if (v0079 == v0238) goto v0205;
    v0079 = v0078;
    v0238 = elt(env, 6); /* partdf */
    if (v0079 == v0238) goto v0160;
    v0079 = v0078;
    v0238 = elt(env, 7); /* liedf */
    if (v0079 == v0238) goto v0086;
    v0079 = v0078;
    v0238 = elt(env, 8); /* innerprod */
    if (v0079 == v0238) goto v0207;
    v0079 = v0078;
    v0238 = elt(env, 9); /* (plus minus difference quotient) */
    v0238 = Lmemq(nil, v0079, v0238);
    if (v0238 == nil) goto v0077;
    v0238 = stack[0];
    v0238 = qcdr(v0238);
    v0238 = qcar(v0238);
    stack[0] = v0238;
    goto v0239;

v0077:
    v0079 = v0078;
    v0238 = elt(env, 10); /* times */
    if (v0079 == v0238) goto v0081;
    v0238 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0238); }

v0081:
    v0238 = stack[0];
    v0238 = qcdr(v0238);
    {
        popv(3);
        fn = elt(env, 11); /* deg!*farg */
        return (*qfn1(fn))(qenv(fn), v0238);
    }

v0207:
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v0238 = stack[0];
    v0238 = qcdr(v0238);
    v0238 = qcdr(v0238);
    v0238 = qcar(v0238);
    v0238 = CC_degHform(env, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-2];
    {
        Lisp_Object v0242 = stack[-1];
        popv(3);
        fn = elt(env, 12); /* addd */
        return (*qfn2(fn))(qenv(fn), v0242, v0238);
    }

v0086:
    v0238 = stack[0];
    v0238 = qcdr(v0238);
    v0238 = qcdr(v0238);
    v0238 = qcar(v0238);
    stack[0] = v0238;
    goto v0239;

v0160:
    v0238 = stack[0];
    v0238 = qcdr(v0238);
    v0238 = qcdr(v0238);
    if (v0238 == nil) goto v0167;
    v0238 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0238); }

v0167:
    v0238 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v0238); }

v0205:
    stack[-1] = qvalue(elt(env, 5)); /* dimex!* */
    v0238 = stack[0];
    v0238 = qcdr(v0238);
    v0238 = qcar(v0238);
    v0238 = CC_degHform(env, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-2];
    fn = elt(env, 13); /* negf */
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-2];
    {
        Lisp_Object v0243 = stack[-1];
        popv(3);
        fn = elt(env, 14); /* addf */
        return (*qfn2(fn))(qenv(fn), v0243, v0238);
    }

v0228:
    stack[-1] = (Lisp_Object)17; /* 1 */
    v0238 = stack[0];
    v0238 = qcdr(v0238);
    v0238 = qcar(v0238);
    v0238 = CC_degHform(env, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-2];
    {
        Lisp_Object v0244 = stack[-1];
        popv(3);
        fn = elt(env, 12); /* addd */
        return (*qfn2(fn))(qenv(fn), v0244, v0238);
    }

v0099:
    v0238 = stack[0];
    v0238 = qcdr(v0238);
    {
        popv(3);
        fn = elt(env, 11); /* deg!*farg */
        return (*qfn1(fn))(qenv(fn), v0238);
    }

v0196:
    v0238 = stack[0];
    if (!symbolp(v0238)) v0238 = nil;
    else { v0238 = qfastgets(v0238);
           if (v0238 != nil) { v0238 = elt(v0238, 29); /* fdegree */
#ifdef RECORD_GET
             if (v0238 != SPID_NOPROP)
                record_get(elt(fastget_names, 29), 1);
             else record_get(elt(fastget_names, 29), 0),
                v0238 = nil; }
           else record_get(elt(fastget_names, 29), 0); }
#else
             if (v0238 == SPID_NOPROP) v0238 = nil; }}
#endif
    v0079 = v0238;
    v0238 = v0079;
    if (v0238 == nil) goto v0150;
    v0238 = v0079;
    v0238 = qcar(v0238);
    { popv(3); return onevalue(v0238); }

v0150:
    v0238 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0238); }
/* error exit handlers */
v0241:
    popv(3);
    return nil;
}



/* Code for convchk */

static Lisp_Object CC_convchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0113, v0112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for convchk");
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
    v0093 = v0000;
/* end of prologue */
    v0113 = qvalue(elt(env, 1)); /* !*!*roundbf */
    if (v0113 == nil) goto v0173;
    v0113 = v0093;
    if (!(!consp(v0113))) { popv(1); return onevalue(v0093); }
    v0113 = v0093;
    v0113 = Lfloatp(nil, v0113);
    env = stack[0];
    if (v0113 == nil) goto v0186;
    {
        popv(1);
        fn = elt(env, 3); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v0093);
    }

v0186:
    v0113 = v0093;
    if (!(!consp(v0113))) goto v0049;
    v0113 = v0093;
    v0113 = integerp(v0113);
    if (v0113 == nil) goto v0195;
    v0112 = elt(env, 2); /* !:rd!: */
    v0113 = v0093;
    v0093 = (Lisp_Object)1; /* 0 */
    v0093 = list2star(v0112, v0113, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[0];
    goto v0049;

v0049:
    {
        popv(1);
        fn = elt(env, 4); /* normbf */
        return (*qfn1(fn))(qenv(fn), v0093);
    }

v0195:
    fn = elt(env, 5); /* read!:num */
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[0];
    goto v0049;

v0173:
    v0113 = v0093;
    if (!consp(v0113)) { popv(1); return onevalue(v0093); }
    {
        popv(1);
        fn = elt(env, 6); /* bf2flck */
        return (*qfn1(fn))(qenv(fn), v0093);
    }
/* error exit handlers */
v0191:
    popv(1);
    return nil;
}



/* Code for red!-char!-downcase */

static Lisp_Object CC_redKcharKdowncase(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0054, v0007;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red-char-downcase");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0054 = v0000;
/* end of prologue */
    v0013 = v0054;
    v0007 = qvalue(elt(env, 1)); /* charassoc!* */
    v0013 = Latsoc(nil, v0013, v0007);
    v0007 = v0013;
    v0013 = v0007;
    if (v0013 == nil) return onevalue(v0054);
    v0013 = v0007;
    v0013 = qcdr(v0013);
    return onevalue(v0013);
}



/* Code for delallasc */

static Lisp_Object CC_delallasc(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0185, v0179, v0180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delallasc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0147;
    stack[-1] = v0000;
/* end of prologue */
    v0180 = nil;
    goto v0100;

v0100:
    v0185 = stack[0];
    if (v0185 == nil) goto v0146;
    v0179 = stack[-1];
    v0185 = stack[0];
    v0185 = qcar(v0185);
    v0185 = qcar(v0185);
    if (v0179 == v0185) goto v0145;
    v0185 = stack[0];
    v0185 = qcar(v0185);
    v0179 = v0180;
    v0185 = cons(v0185, v0179);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-2];
    v0180 = v0185;
    v0185 = stack[0];
    v0185 = qcdr(v0185);
    stack[0] = v0185;
    goto v0100;

v0145:
    v0185 = stack[0];
    v0185 = qcdr(v0185);
    stack[0] = v0185;
    goto v0100;

v0146:
    v0185 = v0180;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0185);
    }
/* error exit handlers */
v0165:
    popv(3);
    return nil;
}



/* Code for getphystype!*sq */

static Lisp_Object CC_getphystypeHsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getphystype*sq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0100 = v0000;
/* end of prologue */
    v0100 = qcar(v0100);
    v0100 = qcar(v0100);
    {
        fn = elt(env, 1); /* getphystypesf */
        return (*qfn1(fn))(qenv(fn), v0100);
    }
}



/* Code for contrsp2 */

static Lisp_Object MS_CDECL CC_contrsp2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0147,
                         Lisp_Object v0188, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0112, v0191;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "contrsp2");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for contrsp2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0188,v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0147,v0188);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0188;
    stack[-1] = v0147;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = (Lisp_Object)33; /* 2 */
    v0112 = stack[-2];
    v0112 = Llength(nil, v0112);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-4];
    if (stack[-3] == v0112) goto v0186;
    v0112 = nil;
    { popv(5); return onevalue(v0112); }

v0186:
    v0191 = stack[0];
    v0112 = stack[-2];
    v0112 = qcar(v0112);
    if (equal(v0191, v0112)) goto v0154;
    v0191 = stack[0];
    v0112 = stack[-2];
    v0112 = qcdr(v0112);
    v0112 = qcar(v0112);
    if (equal(v0191, v0112)) goto v0217;
    v0112 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0112); }

v0217:
    v0112 = stack[-2];
    v0191 = qcar(v0112);
    v0112 = stack[-1];
    popv(5);
    return cons(v0191, v0112);

v0154:
    v0112 = stack[-2];
    v0112 = qcdr(v0112);
    v0191 = qcar(v0112);
    v0112 = stack[-1];
    popv(5);
    return cons(v0191, v0112);
/* error exit handlers */
v0164:
    popv(5);
    return nil;
}



/* Code for get!-print!-name */

static Lisp_Object CC_getKprintKname(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0149, v0150;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get-print-name");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0150 = v0000;
/* end of prologue */
    v0149 = v0150;
    if (symbolp(v0149)) goto v0152;
    v0149 = qvalue(elt(env, 1)); /* nil */
    goto v0100;

v0100:
    if (v0149 == nil) return onevalue(v0150);
    else return onevalue(v0149);

v0152:
    v0149 = v0150;
    if (!symbolp(v0149)) v0149 = nil;
    else { v0149 = qfastgets(v0149);
           if (v0149 != nil) { v0149 = elt(v0149, 12); /* oldnam */
#ifdef RECORD_GET
             if (v0149 != SPID_NOPROP)
                record_get(elt(fastget_names, 12), 1);
             else record_get(elt(fastget_names, 12), 0),
                v0149 = nil; }
           else record_get(elt(fastget_names, 12), 0); }
#else
             if (v0149 == SPID_NOPROP) v0149 = nil; }}
#endif
    goto v0100;
}



/* Code for groeb!=testa */

static Lisp_Object CC_groebMtesta(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groeb=testa");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0147;
    v0003 = v0000;
/* end of prologue */
    v0004 = v0003;
    v0003 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* nth */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0004, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-2];
    v0004 = stack[0];
    v0003 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* nth */
    v0003 = (*qfn2(fn))(qenv(fn), v0004, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-2];
    {
        Lisp_Object v0109 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* mo_divides!? */
        return (*qfn2(fn))(qenv(fn), v0109, v0003);
    }
/* error exit handlers */
v0154:
    popv(3);
    return nil;
}



/* Code for pcmult */

static Lisp_Object CC_pcmult(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0172, v0228;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pcmult");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0147;
    v0172 = v0000;
/* end of prologue */
    stack[-5] = v0172;
    v0172 = stack[-5];
    if (v0172 == nil) goto v0168;
    v0172 = stack[-5];
    v0172 = qcar(v0172);
    v0228 = v0172;
    stack[0] = qcar(v0228);
    v0228 = stack[-4];
    v0172 = qcdr(v0172);
    fn = elt(env, 2); /* cprod */
    v0172 = (*qfn2(fn))(qenv(fn), v0228, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-6];
    v0172 = cons(stack[0], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-6];
    v0172 = ncons(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-6];
    stack[-2] = v0172;
    stack[-3] = v0172;
    goto v0106;

v0106:
    v0172 = stack[-5];
    v0172 = qcdr(v0172);
    stack[-5] = v0172;
    v0172 = stack[-5];
    if (v0172 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v0172 = stack[-5];
    v0172 = qcar(v0172);
    v0228 = v0172;
    stack[0] = qcar(v0228);
    v0228 = stack[-4];
    v0172 = qcdr(v0172);
    fn = elt(env, 2); /* cprod */
    v0172 = (*qfn2(fn))(qenv(fn), v0228, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-6];
    v0172 = cons(stack[0], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-6];
    v0172 = ncons(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-6];
    v0172 = Lrplacd(nil, stack[-1], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-6];
    v0172 = stack[-2];
    v0172 = qcdr(v0172);
    stack[-2] = v0172;
    goto v0106;

v0168:
    v0172 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0172); }
/* error exit handlers */
v0162:
    popv(7);
    return nil;
}



/* Code for gperm1 */

static Lisp_Object MS_CDECL CC_gperm1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0147,
                         Lisp_Object v0188, Lisp_Object v0245, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0212, v0202, v0189;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "gperm1");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gperm1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0245,v0188,v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0147,v0188,v0245);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0245;
    stack[-2] = v0188;
    stack[-3] = v0147;
    stack[-4] = v0000;
/* end of prologue */

v0146:
    v0212 = stack[-4];
    if (v0212 == nil) goto v0149;
    v0212 = stack[-4];
    v0212 = qcdr(v0212);
    stack[-5] = v0212;
    v0212 = stack[-4];
    v0202 = qcar(v0212);
    v0212 = stack[-2];
    v0212 = cons(v0202, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-6];
    stack[0] = v0212;
    v0202 = stack[-3];
    v0212 = stack[-2];
    v0212 = cons(v0202, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-6];
    fn = elt(env, 1); /* rev */
    v0202 = (*qfn2(fn))(qenv(fn), stack[-4], v0212);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-6];
    v0212 = stack[-1];
    v0212 = cons(v0202, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-6];
    stack[-1] = v0212;
    v0212 = stack[0];
    stack[-2] = v0212;
    v0212 = stack[-5];
    stack[-4] = v0212;
    goto v0146;

v0149:
    v0189 = stack[-3];
    v0202 = stack[-2];
    v0212 = stack[-1];
    popv(7);
    return acons(v0189, v0202, v0212);
/* error exit handlers */
v0094:
    popv(7);
    return nil;
}



/* Code for arzerop!: */

static Lisp_Object CC_arzeropT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0173;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for arzerop:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0173 = v0000;
/* end of prologue */
    v0173 = qcdr(v0173);
    v0173 = (v0173 == nil ? lisp_true : nil);
    return onevalue(v0173);
}



/* Code for c!:ordexp */

static Lisp_Object CC_cTordexp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0131, v0185, v0179, v0180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for c:ordexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0185 = v0147;
    v0179 = v0000;
/* end of prologue */

v0173:
    v0131 = v0179;
    if (v0131 == nil) goto v0106;
    v0131 = v0179;
    v0180 = qcar(v0131);
    v0131 = v0185;
    v0131 = qcar(v0131);
    if (equal(v0180, v0131)) goto v0168;
    v0131 = v0179;
    v0131 = qcar(v0131);
    v0185 = qcar(v0185);
    {
        fn = elt(env, 2); /* c!:ordxp */
        return (*qfn2(fn))(qenv(fn), v0131, v0185);
    }

v0168:
    v0131 = v0179;
    v0131 = qcdr(v0131);
    v0179 = v0131;
    v0131 = v0185;
    v0131 = qcdr(v0131);
    v0185 = v0131;
    goto v0173;

v0106:
    v0131 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0131);
}



/* Code for minus!-mod!-p */

static Lisp_Object CC_minusKmodKp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0199, v0240;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for minus-mod-p");
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
    stack[-2] = nil;
    goto v0173;

v0173:
    v0199 = stack[-1];
    if (v0199 == nil) goto v0106;
    v0199 = stack[-1];
    if (!consp(v0199)) goto v0150;
    v0199 = stack[-1];
    v0199 = qcar(v0199);
    v0199 = (consp(v0199) ? nil : lisp_true);
    goto v0149;

v0149:
    if (v0199 == nil) goto v0127;
    v0240 = stack[-2];
    v0199 = stack[-1];
    {   int32_t w = int_of_fixnum(v0199);
        if (w != 0) w = current_modulus - w;
        v0199 = fixnum_of_int(w);
    }
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0240, v0199);
    }

v0127:
    v0199 = stack[-1];
    v0199 = qcar(v0199);
    stack[0] = qcar(v0199);
    v0199 = stack[-1];
    v0199 = qcar(v0199);
    v0199 = qcdr(v0199);
    v0240 = CC_minusKmodKp(env, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-3];
    v0199 = stack[-2];
    v0199 = acons(stack[0], v0240, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-3];
    stack[-2] = v0199;
    v0199 = stack[-1];
    v0199 = qcdr(v0199);
    stack[-1] = v0199;
    goto v0173;

v0150:
    v0199 = qvalue(elt(env, 1)); /* t */
    goto v0149;

v0106:
    v0199 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0199);
    }
/* error exit handlers */
v0113:
    popv(4);
    return nil;
}



/* Code for stable!-sortip */

static Lisp_Object CC_stableKsortip(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0255, v0256, v0072;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for stable-sortip");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0147;
    stack[-3] = v0000;
/* end of prologue */
    v0255 = stack[-3];
    if (v0255 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0255 = stack[-3];
    stack[-4] = v0255;
    v0255 = stack[-3];
    v0255 = qcdr(v0255);
    stack[-1] = v0255;
    v0255 = stack[-1];
    if (v0255 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0255 = stack[-1];
    v0255 = qcdr(v0255);
    stack[-3] = v0255;
    v0255 = stack[-3];
    if (v0255 == nil) goto v0135;
    v0255 = stack[-4];
    stack[-3] = v0255;
    goto v0176;

v0176:
    v0255 = stack[-1];
    if (v0255 == nil) goto v0174;
    v0072 = stack[-2];
    v0255 = stack[-1];
    v0256 = qcar(v0255);
    v0255 = stack[-3];
    v0255 = qcar(v0255);
    v0255 = Lapply2(nil, 3, v0072, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-5];
    if (!(v0255 == nil)) goto v0174;
    v0255 = stack[-1];
    stack[-3] = v0255;
    v0255 = stack[-1];
    v0255 = qcdr(v0255);
    stack[-1] = v0255;
    goto v0176;

v0174:
    v0255 = stack[-1];
    if (v0255 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v0255 = stack[-4];
    stack[-1] = v0255;
    v0255 = stack[-1];
    v0255 = qcdr(v0255);
    v0255 = qcdr(v0255);
    stack[-3] = v0255;
    goto v0160;

v0160:
    v0255 = stack[-3];
    if (v0255 == nil) goto v0159;
    v0255 = stack[-3];
    v0255 = qcdr(v0255);
    if (v0255 == nil) goto v0159;
    v0255 = stack[-1];
    v0255 = qcdr(v0255);
    stack[-1] = v0255;
    v0255 = stack[-3];
    v0255 = qcdr(v0255);
    v0255 = qcdr(v0255);
    stack[-3] = v0255;
    goto v0160;

v0159:
    v0255 = stack[-1];
    stack[-3] = v0255;
    v0255 = stack[-1];
    v0255 = qcdr(v0255);
    stack[-1] = v0255;
    v0256 = stack[-3];
    v0255 = qvalue(elt(env, 1)); /* nil */
    v0255 = Lrplacd(nil, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-5];
    v0256 = stack[-4];
    v0255 = stack[-2];
    v0255 = CC_stableKsortip(env, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-5];
    stack[-4] = v0255;
    v0256 = stack[-1];
    v0255 = stack[-2];
    v0255 = CC_stableKsortip(env, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-5];
    stack[-1] = v0255;
    v0255 = qvalue(elt(env, 1)); /* nil */
    v0255 = ncons(v0255);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-5];
    stack[0] = v0255;
    stack[-3] = v0255;
    goto v0258;

v0258:
    v0255 = stack[-4];
    if (v0255 == nil) goto v0259;
    v0255 = stack[-1];
    if (v0255 == nil) goto v0259;
    v0072 = stack[-2];
    v0255 = stack[-1];
    v0256 = qcar(v0255);
    v0255 = stack[-4];
    v0255 = qcar(v0255);
    v0255 = Lapply2(nil, 3, v0072, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-5];
    if (v0255 == nil) goto v0260;
    v0256 = stack[0];
    v0255 = stack[-1];
    v0255 = Lrplacd(nil, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-5];
    v0255 = stack[-1];
    stack[0] = v0255;
    v0255 = stack[-1];
    v0255 = qcdr(v0255);
    stack[-1] = v0255;
    goto v0258;

v0260:
    v0256 = stack[0];
    v0255 = stack[-4];
    v0255 = Lrplacd(nil, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-5];
    v0255 = stack[-4];
    stack[0] = v0255;
    v0255 = stack[-4];
    v0255 = qcdr(v0255);
    stack[-4] = v0255;
    goto v0258;

v0259:
    v0255 = stack[-4];
    if (v0255 == nil) goto v0261;
    v0255 = stack[-4];
    stack[-1] = v0255;
    goto v0261;

v0261:
    v0256 = stack[0];
    v0255 = stack[-1];
    v0255 = Lrplacd(nil, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    v0255 = stack[-3];
    v0255 = qcdr(v0255);
    { popv(6); return onevalue(v0255); }

v0135:
    v0072 = stack[-2];
    v0255 = stack[-1];
    v0256 = qcar(v0255);
    v0255 = stack[-4];
    v0255 = qcar(v0255);
    v0255 = Lapply2(nil, 3, v0072, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-5];
    if (v0255 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v0255 = stack[-4];
    v0255 = qcar(v0255);
    stack[-3] = v0255;
    v0256 = stack[-4];
    v0255 = stack[-1];
    v0255 = qcar(v0255);
    v0255 = Lrplaca(nil, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    env = stack[-5];
    v0256 = stack[-1];
    v0255 = stack[-3];
    v0255 = Lrplaca(nil, v0256, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v0257:
    popv(6);
    return nil;
}



/* Code for exchk2 */

static Lisp_Object CC_exchk2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0229, v0117, v0236;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exchk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0147;
    stack[-1] = v0000;
/* end of prologue */

v0100:
    v0229 = stack[-1];
    if (v0229 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0229 = stack[-1];
    v0229 = qcdr(v0229);
    stack[-2] = v0229;
    v0229 = stack[-1];
    v0229 = qcar(v0229);
    v0229 = qcdr(v0229);
    fn = elt(env, 6); /* prepsqx */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-3];
    v0236 = v0229;
    v0117 = (Lisp_Object)17; /* 1 */
    if (v0236 == v0117) goto v0109;
    v0117 = qvalue(elt(env, 1)); /* !*nosqrts */
    if (v0117 == nil) goto v0113;
    v0236 = elt(env, 2); /* expt */
    v0117 = stack[-1];
    v0117 = qcar(v0117);
    v0117 = qcar(v0117);
    v0229 = list3(v0236, v0117, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-3];
    v0117 = v0229;
    goto v0186;

v0186:
    v0229 = stack[0];
    v0229 = cons(v0117, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-3];
    stack[0] = v0229;
    v0229 = stack[-2];
    stack[-1] = v0229;
    goto v0100;

v0113:
    v0236 = v0229;
    v0117 = elt(env, 3); /* (quotient 1 2) */
    if (equal(v0236, v0117)) goto v0175;
    v0236 = v0229;
    v0117 = elt(env, 5); /* 0.5 */
    if (equal(v0236, v0117)) goto v0222;
    v0236 = elt(env, 2); /* expt */
    v0117 = stack[-1];
    v0117 = qcar(v0117);
    v0117 = qcar(v0117);
    v0229 = list3(v0236, v0117, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-3];
    v0117 = v0229;
    goto v0186;

v0222:
    v0117 = elt(env, 4); /* sqrt */
    v0229 = stack[-1];
    v0229 = qcar(v0229);
    v0229 = qcar(v0229);
    v0229 = list2(v0117, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-3];
    v0117 = v0229;
    goto v0186;

v0175:
    v0117 = elt(env, 4); /* sqrt */
    v0229 = stack[-1];
    v0229 = qcar(v0229);
    v0229 = qcar(v0229);
    v0229 = list2(v0117, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-3];
    v0117 = v0229;
    goto v0186;

v0109:
    v0229 = stack[-1];
    v0229 = qcar(v0229);
    v0229 = qcar(v0229);
    v0117 = v0229;
    goto v0186;
/* error exit handlers */
v0171:
    popv(4);
    return nil;
}



/* Code for mri_type */

static Lisp_Object CC_mri_type(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0151, v0108;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_type");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0108 = v0000;
/* end of prologue */
    v0151 = v0108;
    v0151 = qcdr(v0151);
    v0151 = qcdr(v0151);
    v0151 = qcdr(v0151);
    if (v0151 == nil) goto v0196;
    v0151 = v0108;
    v0151 = qcdr(v0151);
    v0151 = qcdr(v0151);
    v0151 = qcdr(v0151);
    v0151 = qcar(v0151);
    return onevalue(v0151);

v0196:
    v0151 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0151);
}



/* Code for find */

static Lisp_Object CC_find(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0165, v0166, v0169, v0218;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for find");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0166 = v0147;
    v0169 = v0000;
/* end of prologue */

v0146:
    v0218 = v0166;
    v0165 = nil;
    if (v0218 == v0165) goto v0107;
    v0165 = v0166;
    v0165 = qcar(v0165);
    v0169 = Lmember(nil, v0165, v0169);
    v0165 = v0166;
    v0165 = qcdr(v0165);
    v0166 = v0165;
    goto v0146;

v0107:
    v0165 = v0169;
    if (v0165 == nil) goto v0007;
    v0165 = v0169;
    v0165 = qcdr(v0165);
    return onevalue(v0165);

v0007:
    v0165 = elt(env, 1); /* (stop) */
    return onevalue(v0165);
}



/* Code for sortcolelem */

static Lisp_Object MS_CDECL CC_sortcolelem(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0147,
                         Lisp_Object v0188, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0121, v0205;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sortcolelem");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sortcolelem");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0188,v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0147,v0188);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0188;
    stack[-2] = v0147;
    stack[-3] = v0000;
/* end of prologue */
    stack[0] = nil;
    v0121 = stack[-2];
    v0121 = qcdr(v0121);
    stack[-4] = v0121;
    goto v0168;

v0168:
    v0121 = stack[0];
    if (v0121 == nil) goto v0145;
    v0121 = nil;
    { popv(6); return onevalue(v0121); }

v0145:
    v0121 = stack[-4];
    if (v0121 == nil) goto v0003;
    v0205 = stack[-3];
    v0121 = stack[-4];
    v0121 = qcar(v0121);
    v0121 = qcar(v0121);
    v0121 = (Lisp_Object)lessp2(v0205, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    v0121 = v0121 ? lisp_true : nil;
    env = stack[-5];
    if (v0121 == nil) goto v0095;
    stack[0] = stack[-2];
    v0205 = stack[-3];
    v0121 = stack[-1];
    v0121 = cons(v0205, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-5];
    v0205 = ncons(v0121);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-5];
    v0121 = stack[-4];
    v0121 = Lrplacd(nil, v0205, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-5];
    v0121 = Lrplacd(nil, stack[0], v0121);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-5];
    v0121 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0121;
    goto v0168;

v0095:
    v0205 = stack[-3];
    v0121 = stack[-4];
    v0121 = qcar(v0121);
    v0121 = qcar(v0121);
    v0121 = (Lisp_Object)greaterp2(v0205, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    v0121 = v0121 ? lisp_true : nil;
    env = stack[-5];
    if (v0121 == nil) goto v0168;
    v0121 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0121;
    v0121 = stack[-2];
    v0121 = qcdr(v0121);
    stack[-2] = v0121;
    v0121 = stack[-2];
    v0121 = qcdr(v0121);
    stack[-4] = v0121;
    goto v0168;

v0003:
    stack[0] = stack[-2];
    v0205 = stack[-3];
    v0121 = stack[-1];
    v0121 = cons(v0205, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-5];
    v0121 = ncons(v0121);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-5];
    v0121 = Lrplacd(nil, stack[0], v0121);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-5];
    v0121 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0121;
    goto v0168;
/* error exit handlers */
v0203:
    popv(6);
    return nil;
}



/* Code for pnthxzz */

static Lisp_Object CC_pnthxzz(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115, v0116, v0135, v0183;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pnthxzz");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0135 = v0147;
    v0183 = v0000;
/* end of prologue */

v0173:
    v0115 = v0135;
    if (v0115 == nil) goto v0168;
    v0115 = v0135;
    v0115 = qcar(v0115);
    v0116 = qcar(v0115);
    v0115 = v0183;
    v0115 = (equal(v0116, v0115) ? lisp_true : nil);
    goto v0152;

v0152:
    if (!(v0115 == nil)) return onevalue(v0135);
    v0115 = v0135;
    v0115 = qcdr(v0115);
    v0135 = v0115;
    goto v0173;

v0168:
    v0115 = qvalue(elt(env, 1)); /* t */
    goto v0152;
}



/* Code for vevtdeg */

static Lisp_Object CC_vevtdeg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0187, v0195, v0165;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vevtdeg");
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
    v0195 = nil;
    goto v0100;

v0100:
    v0187 = stack[0];
    if (v0187 == nil) goto v0107;
    v0187 = stack[0];
    v0187 = qcar(v0187);
    v0187 = cons(v0187, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-1];
    v0195 = v0187;
    v0187 = stack[0];
    v0187 = qcdr(v0187);
    stack[0] = v0187;
    goto v0100;

v0107:
    v0187 = (Lisp_Object)1; /* 0 */
    goto v0106;

v0106:
    v0165 = v0195;
    if (v0165 == nil) { popv(2); return onevalue(v0187); }
    v0165 = v0195;
    v0165 = qcar(v0165);
    v0187 = (Lisp_Object)(int32_t)((int32_t)v0165 + (int32_t)v0187 - TAG_FIXNUM);
    v0195 = qcdr(v0195);
    goto v0106;
/* error exit handlers */
v0169:
    popv(2);
    return nil;
}



/* Code for !*collectphysops */

static Lisp_Object CC_Hcollectphysops(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0152, v0168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *collectphysops");
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
    v0152 = v0000;
/* end of prologue */
    v0168 = v0152;
    v0152 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* !*collectphysops_reversed */
    v0152 = (*qfn2(fn))(qenv(fn), v0168, v0152);
    errexit();
        return Lnreverse(nil, v0152);
}



/* Code for sfpx */

static Lisp_Object CC_sfpx(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108, v0186, v0013, v0054, v0007;
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
    v0108 = v0000;
/* end of prologue */
    v0007 = v0108;
    v0054 = qvalue(elt(env, 1)); /* nil */
    v0013 = qvalue(elt(env, 1)); /* nil */
    v0186 = (Lisp_Object)1; /* 0 */
    v0108 = qvalue(elt(env, 2)); /* t */
    {
        fn = elt(env, 3); /* sfpx1 */
        return (*qfnn(fn))(qenv(fn), 5, v0007, v0054, v0013, v0186, v0108);
    }
}



/* Code for gcdf!* */

static Lisp_Object CC_gcdfH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0184, v0149, v0150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdf*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0149 = v0147;
    v0150 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    v0184 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v0184; /* !*gcd */
    v0184 = v0150;
    fn = elt(env, 3); /* gcdf */
    v0184 = (*qfn2(fn))(qenv(fn), v0184, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    { popv(2); return onevalue(v0184); }
/* error exit handlers */
v0108:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    popv(2);
    return nil;
}



/* Code for tsym4 */

static Lisp_Object MS_CDECL CC_tsym4(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0147,
                         Lisp_Object v0188, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0195, v0165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "tsym4");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tsym4");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0188,v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0147,v0188);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0188;
    stack[-1] = v0147;
    v0195 = v0000;
/* end of prologue */

v0107:
    v0165 = v0195;
    if (v0165 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0165 = v0195;
    v0165 = qcdr(v0165);
    stack[-2] = v0165;
    v0165 = stack[-1];
    v0165 = qcdr(v0165);
    v0195 = qcar(v0195);
    fn = elt(env, 1); /* pv_applp */
    v0165 = (*qfn2(fn))(qenv(fn), v0165, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-3];
    v0195 = stack[0];
    fn = elt(env, 2); /* sieve_pv */
    v0195 = (*qfn2(fn))(qenv(fn), v0165, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-3];
    fn = elt(env, 3); /* pv_renorm */
    v0165 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-3];
    v0195 = stack[0];
    fn = elt(env, 4); /* insert_pv */
    v0195 = (*qfn2(fn))(qenv(fn), v0165, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-3];
    stack[0] = v0195;
    v0195 = stack[-2];
    goto v0107;
/* error exit handlers */
v0200:
    popv(4);
    return nil;
}



/* Code for general!-modular!-reciprocal */

static Lisp_Object CC_generalKmodularKreciprocal(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0099, v0199, v0240, v0246;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-reciprocal");
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
    v0099 = qvalue(elt(env, 1)); /* !*balanced_mod */
    if (v0099 == nil) goto v0179;
    v0199 = stack[0];
    v0099 = (Lisp_Object)1; /* 0 */
    v0099 = (Lisp_Object)lessp2(v0199, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    v0099 = v0099 ? lisp_true : nil;
    env = stack[-2];
    if (v0099 == nil) goto v0179;
    stack[-1] = qvalue(elt(env, 2)); /* current!-modulus */
    v0199 = stack[0];
    v0099 = qvalue(elt(env, 2)); /* current!-modulus */
    v0240 = plus2(v0199, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-2];
    v0199 = (Lisp_Object)1; /* 0 */
    v0099 = (Lisp_Object)17; /* 1 */
    {
        Lisp_Object v0112 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* general!-reciprocal!-by!-gcd */
        return (*qfnn(fn))(qenv(fn), 4, v0112, v0240, v0199, v0099);
    }

v0179:
    v0246 = qvalue(elt(env, 2)); /* current!-modulus */
    v0240 = stack[0];
    v0199 = (Lisp_Object)1; /* 0 */
    v0099 = (Lisp_Object)17; /* 1 */
    {
        popv(3);
        fn = elt(env, 3); /* general!-reciprocal!-by!-gcd */
        return (*qfnn(fn))(qenv(fn), 4, v0246, v0240, v0199, v0099);
    }
/* error exit handlers */
v0113:
    popv(3);
    return nil;
}



/* Code for mri_0mk2 */

static Lisp_Object MS_CDECL CC_mri_0mk2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0147,
                         Lisp_Object v0188, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0151, v0108, v0186, v0013;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mri_0mk2");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_0mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0186 = v0188;
    v0151 = v0147;
    v0108 = v0000;
/* end of prologue */
    v0013 = qvalue(elt(env, 1)); /* nil */
    return list4(v0108, v0151, v0013, v0186);
}



/* Code for ibalp_commonlenisone */

static Lisp_Object CC_ibalp_commonlenisone(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_commonlenisone");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0147;
    stack[-1] = v0000;
/* end of prologue */
    v0004 = stack[-1];
    if (v0004 == nil) goto v0106;
    v0004 = qvalue(elt(env, 1)); /* nil */
    goto v0107;

v0107:
    if (!(v0004 == nil)) { popv(3); return onevalue(v0004); }
    v0004 = stack[0];
    if (v0004 == nil) goto v0151;
    v0004 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0004); }

v0151:
    v0004 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* ibalp_lenisone */
        return (*qfn1(fn))(qenv(fn), v0004);
    }

v0106:
    v0004 = stack[0];
    fn = elt(env, 2); /* ibalp_lenisone */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-2];
    goto v0107;
/* error exit handlers */
v0154:
    popv(3);
    return nil;
}



/* Code for ratpoly_idl */

static Lisp_Object CC_ratpoly_idl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratpoly_idl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0173 = v0000;
/* end of prologue */
    v0173 = qcar(v0173);
    {
        fn = elt(env, 1); /* kernels */
        return (*qfn1(fn))(qenv(fn), v0173);
    }
}



/* Code for sfto_dcontentf1 */

static Lisp_Object CC_sfto_dcontentf1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0240, v0246, v0194;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_dcontentf1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0147;
    v0246 = v0000;
/* end of prologue */

v0152:
    v0194 = stack[0];
    v0240 = (Lisp_Object)17; /* 1 */
    if (v0194 == v0240) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0240 = v0246;
    if (!consp(v0240)) goto v0007;
    v0240 = v0246;
    v0240 = qcar(v0240);
    v0240 = (consp(v0240) ? nil : lisp_true);
    goto v0054;

v0054:
    if (v0240 == nil) goto v0179;
    v0240 = v0246;
    fn = elt(env, 2); /* absf */
    v0246 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-2];
    v0240 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* sfto_gcdf */
        return (*qfn2(fn))(qenv(fn), v0246, v0240);
    }

v0179:
    v0240 = v0246;
    v0240 = qcdr(v0240);
    stack[-1] = v0240;
    v0240 = v0246;
    v0240 = qcar(v0240);
    v0246 = qcdr(v0240);
    v0240 = stack[0];
    v0240 = CC_sfto_dcontentf1(env, v0246, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0112;
    env = stack[-2];
    stack[0] = v0240;
    v0240 = stack[-1];
    v0246 = v0240;
    goto v0152;

v0007:
    v0240 = qvalue(elt(env, 1)); /* t */
    goto v0054;
/* error exit handlers */
v0112:
    popv(3);
    return nil;
}



/* Code for multi_elem */

static Lisp_Object CC_multi_elem(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0153, v0154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multi_elem");
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
    v0153 = stack[0];
    v0154 = Llength(nil, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-1];
    v0153 = (Lisp_Object)17; /* 1 */
    if (v0154 == v0153) goto v0100;
    v0153 = stack[0];
    v0153 = qcar(v0153);
    fn = elt(env, 2); /* expression */
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-1];
    v0153 = stack[0];
    v0153 = qcdr(v0153);
    v0153 = CC_multi_elem(env, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    goto v0173;

v0173:
    v0153 = nil;
    { popv(2); return onevalue(v0153); }

v0100:
    v0153 = stack[0];
    v0153 = qcar(v0153);
    fn = elt(env, 2); /* expression */
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    goto v0173;
/* error exit handlers */
v0111:
    popv(2);
    return nil;
}



/* Code for rationalizei */

static Lisp_Object CC_rationalizei(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090, v0263;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rationalizei");
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
    v0090 = stack[-1];
    v0090 = qcdr(v0090);
    stack[-2] = v0090;
    v0263 = v0090;
    v0090 = v0263;
    if (!consp(v0090)) goto v0149;
    v0090 = v0263;
    v0090 = qcar(v0090);
    v0090 = (consp(v0090) ? nil : lisp_true);
    goto v0184;

v0184:
    if (!(v0090 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0263 = elt(env, 2); /* i */
    v0090 = stack[-2];
    v0090 = Lsmemq(nil, v0263, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    if (v0090 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0263 = elt(env, 2); /* i */
    v0090 = qvalue(elt(env, 3)); /* kord!* */
    v0090 = cons(v0263, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    stack[0] = qvalue(elt(env, 3)); /* kord!* */
    qvalue(elt(env, 3)) = v0090; /* kord!* */
    v0090 = stack[-1];
    fn = elt(env, 6); /* reordsq */
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-3];
    stack[-2] = v0090;
    qvalue(elt(env, 3)) = stack[0]; /* kord!* */
    v0090 = stack[-2];
    v0090 = qcdr(v0090);
    stack[0] = v0090;
    v0090 = qcar(v0090);
    v0263 = qcar(v0090);
    v0090 = elt(env, 4); /* (i . 1) */
    if (equal(v0263, v0090)) goto v0178;
    v0090 = qvalue(elt(env, 5)); /* nil */
    goto v0177;

v0177:
    if (v0090 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0263 = elt(env, 2); /* i */
    v0090 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 7); /* to */
    v0263 = (*qfn2(fn))(qenv(fn), v0263, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    v0090 = (Lisp_Object)17; /* 1 */
    v0090 = cons(v0263, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    stack[-1] = ncons(v0090);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    v0090 = stack[-2];
    v0090 = qcar(v0090);
    fn = elt(env, 8); /* reorder */
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    fn = elt(env, 9); /* multf */
    v0090 = (*qfn2(fn))(qenv(fn), stack[-1], v0090);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    fn = elt(env, 10); /* negf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[-3];
    v0090 = stack[0];
    v0090 = qcar(v0090);
    v0090 = qcdr(v0090);
    fn = elt(env, 8); /* reorder */
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    {
        Lisp_Object v0267 = stack[-1];
        popv(4);
        return cons(v0267, v0090);
    }

v0178:
    v0090 = stack[0];
    v0090 = qcdr(v0090);
    v0090 = (v0090 == nil ? lisp_true : nil);
    goto v0177;

v0149:
    v0090 = qvalue(elt(env, 1)); /* t */
    goto v0184;
/* error exit handlers */
v0236:
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[0]; /* kord!* */
    popv(4);
    return nil;
v0117:
    popv(4);
    return nil;
}



/* Code for gsetsugar */

static Lisp_Object CC_gsetsugar(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0111, v0114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gsetsugar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0114 = v0147;
    stack[-1] = v0000;
/* end of prologue */
    v0111 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v0111 == nil) goto v0106;
    stack[-2] = stack[-1];
    stack[0] = elt(env, 3); /* sugar */
    v0111 = v0114;
    if (!(v0111 == nil)) goto v0186;
    v0111 = stack[-1];
    fn = elt(env, 4); /* vdptdeg */
    v0111 = (*qfn1(fn))(qenv(fn), v0111);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-3];
    goto v0186;

v0186:
    fn = elt(env, 5); /* vdpputprop */
    v0111 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v0111);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    goto v0107;

v0107:
    if (v0111 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    else { popv(4); return onevalue(v0111); }

v0106:
    v0111 = qvalue(elt(env, 2)); /* nil */
    goto v0107;
/* error exit handlers */
v0183:
    popv(4);
    return nil;
}



/* Code for maxdeg */

static Lisp_Object CC_maxdeg(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0135, v0183;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for maxdeg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0147;
    stack[-1] = v0000;
/* end of prologue */

v0100:
    v0135 = stack[-1];
    if (v0135 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0135 = stack[-1];
    v0135 = qcar(v0135);
    v0183 = qcdr(v0135);
    v0135 = stack[0];
    v0135 = qcdr(v0135);
    v0135 = (Lisp_Object)greaterp2(v0183, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    v0135 = v0135 ? lisp_true : nil;
    env = stack[-2];
    if (v0135 == nil) goto v0111;
    v0135 = stack[-1];
    v0135 = qcdr(v0135);
    v0183 = v0135;
    v0135 = stack[-1];
    v0135 = qcar(v0135);
    stack[0] = v0135;
    v0135 = v0183;
    stack[-1] = v0135;
    goto v0100;

v0111:
    v0135 = stack[-1];
    v0135 = qcdr(v0135);
    stack[-1] = v0135;
    goto v0100;
/* error exit handlers */
v0131:
    popv(3);
    return nil;
}



/* Code for getphystype */

static Lisp_Object CC_getphystype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0227, v0159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getphystype");
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
    v0227 = stack[0];
    fn = elt(env, 8); /* physopp */
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-2];
    if (v0227 == nil) goto v0106;
    v0227 = stack[0];
    fn = elt(env, 9); /* scalopp */
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-2];
    if (v0227 == nil) goto v0145;
    v0227 = elt(env, 1); /* scalar */
    { popv(3); return onevalue(v0227); }

v0145:
    v0227 = stack[0];
    fn = elt(env, 10); /* vecopp */
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-2];
    if (v0227 == nil) goto v0108;
    v0227 = elt(env, 2); /* vector */
    { popv(3); return onevalue(v0227); }

v0108:
    v0227 = stack[0];
    fn = elt(env, 11); /* tensopp */
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-2];
    if (v0227 == nil) goto v0049;
    v0227 = elt(env, 3); /* tensor */
    { popv(3); return onevalue(v0227); }

v0049:
    v0227 = stack[0];
    fn = elt(env, 12); /* statep */
    v0227 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-2];
    if (v0227 == nil) goto v0115;
    v0227 = elt(env, 4); /* state */
    { popv(3); return onevalue(v0227); }

v0115:
    v0227 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v0227); }

v0106:
    v0227 = stack[0];
    if (!consp(v0227)) goto v0183;
    v0227 = stack[0];
    v0227 = qcar(v0227);
    if (!symbolp(v0227)) v0159 = nil;
    else { v0159 = qfastgets(v0227);
           if (v0159 != nil) { v0159 = elt(v0159, 18); /* phystype */
#ifdef RECORD_GET
             if (v0159 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0159 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0159 == SPID_NOPROP) v0159 = nil; }}
#endif
    v0227 = v0159;
    if (!(v0159 == nil)) { popv(3); return onevalue(v0227); }
    v0227 = stack[0];
    v0159 = qcar(v0227);
    v0227 = elt(env, 6); /* phystypefn */
    v0159 = get(v0159, v0227);
    env = stack[-2];
    v0227 = v0159;
    if (v0159 == nil) goto v0169;
    v0159 = v0227;
    v0227 = stack[0];
    v0227 = qcdr(v0227);
        popv(3);
        return Lapply1(nil, v0159, v0227);

v0169:
    v0227 = stack[0];
    fn = elt(env, 13); /* collectphystype */
    v0159 = (*qfn1(fn))(qenv(fn), v0227);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-2];
    v0227 = v0159;
    if (v0159 == nil) goto v0190;
    v0159 = v0227;
    v0159 = qcdr(v0159);
    if (v0159 == nil) goto v0181;
    v0159 = elt(env, 4); /* state */
    v0227 = Lmember(nil, v0159, v0227);
    if (v0227 == nil) goto v0192;
    v0227 = elt(env, 4); /* state */
    { popv(3); return onevalue(v0227); }

v0192:
    stack[-1] = elt(env, 0); /* getphystype */
    v0159 = elt(env, 7); /* "PHYSOP type conflict in" */
    v0227 = stack[0];
    v0227 = list2(v0159, v0227);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-2];
    {
        Lisp_Object v0263 = stack[-1];
        popv(3);
        fn = elt(env, 14); /* rederr2 */
        return (*qfn2(fn))(qenv(fn), v0263, v0227);
    }

v0181:
    v0227 = qcar(v0227);
    { popv(3); return onevalue(v0227); }

v0190:
    v0227 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v0227); }

v0183:
    v0227 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v0227); }
/* error exit handlers */
v0090:
    popv(3);
    return nil;
}



/* Code for setcloc!* */

static Lisp_Object MS_CDECL CC_setclocH(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0054, v0007;
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
    v0013 = qvalue(elt(env, 1)); /* ifl!* */
    if (v0013 == nil) goto v0245;
    v0013 = qvalue(elt(env, 1)); /* ifl!* */
    v0007 = qcar(v0013);
    v0054 = (Lisp_Object)17; /* 1 */
    v0013 = qvalue(elt(env, 3)); /* curline!* */
    v0013 = list2star(v0007, v0054, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[0];
    goto v0188;

v0188:
    qvalue(elt(env, 4)) = v0013; /* cloc!* */
    { popv(1); return onevalue(v0013); }

v0245:
    v0013 = qvalue(elt(env, 2)); /* nil */
    goto v0188;
/* error exit handlers */
v0049:
    popv(1);
    return nil;
}



/* Code for dp_term */

static Lisp_Object CC_dp_term(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0152, v0168;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dp_term");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0152 = v0147;
    v0168 = v0000;
/* end of prologue */
    return cons(v0152, v0168);
}



/* Code for dquot */

static Lisp_Object CC_dquot(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0217, v0177, v0178;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dquot");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0147;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0148;

v0148:
    v0217 = stack[-1];
    v0177 = qcar(v0217);
    v0217 = stack[0];
    v0217 = qcar(v0217);
    v0217 = difference2(v0177, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-3];
    v0178 = v0217;
    v0177 = v0178;
    v0217 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v0177)) < ((int32_t)(v0217))) goto v0013;
    v0177 = v0178;
    v0217 = stack[-2];
    v0217 = cons(v0177, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-3];
    stack[-2] = v0217;
    v0217 = stack[0];
    v0217 = qcdr(v0217);
    stack[0] = v0217;
    v0217 = stack[-1];
    v0217 = qcdr(v0217);
    stack[-1] = v0217;
    v0217 = stack[0];
    if (!(v0217 == nil)) goto v0148;
    v0217 = stack[-2];
        popv(4);
        return Lnreverse(nil, v0217);

v0013:
    v0217 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0217); }
/* error exit handlers */
v0240:
    popv(4);
    return nil;
}



/* Code for gperm */

static Lisp_Object CC_gperm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0201, v0172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gperm");
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
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = nil;
    goto v0144;

v0144:
    v0172 = stack[0];
    v0201 = (Lisp_Object)1; /* 0 */
    v0201 = (Lisp_Object)greaterp2(v0172, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    v0201 = v0201 ? lisp_true : nil;
    env = stack[-4];
    if (v0201 == nil) goto v0100;
    v0172 = stack[0];
    v0201 = stack[-1];
    v0201 = cons(v0172, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-4];
    stack[-1] = v0201;
    v0201 = stack[0];
    v0201 = sub1(v0201);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-4];
    stack[0] = v0201;
    goto v0144;

v0100:
    v0201 = stack[-1];
    fn = elt(env, 2); /* gperm0 */
    v0201 = (*qfn1(fn))(qenv(fn), v0201);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-4];
    stack[-3] = v0201;
    v0201 = stack[-3];
    if (v0201 == nil) goto v0179;
    v0201 = stack[-3];
    v0201 = qcar(v0201);
    fn = elt(env, 3); /* pkp */
    v0201 = (*qfn1(fn))(qenv(fn), v0201);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-4];
    v0201 = ncons(v0201);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-4];
    stack[-1] = v0201;
    stack[-2] = v0201;
    goto v0183;

v0183:
    v0201 = stack[-3];
    v0201 = qcdr(v0201);
    stack[-3] = v0201;
    v0201 = stack[-3];
    if (v0201 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0201 = stack[-3];
    v0201 = qcar(v0201);
    fn = elt(env, 3); /* pkp */
    v0201 = (*qfn1(fn))(qenv(fn), v0201);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-4];
    v0201 = ncons(v0201);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-4];
    v0201 = Lrplacd(nil, stack[0], v0201);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-4];
    v0201 = stack[-1];
    v0201 = qcdr(v0201);
    stack[-1] = v0201;
    goto v0183;

v0179:
    v0201 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0201); }
/* error exit handlers */
v0095:
    popv(5);
    return nil;
}



/* Code for gizerop!: */

static Lisp_Object CC_gizeropT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0153, v0154, v0109;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gizerop:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0109 = v0000;
/* end of prologue */
    v0153 = v0109;
    v0153 = qcdr(v0153);
    v0154 = qcar(v0153);
    v0153 = (Lisp_Object)1; /* 0 */
    if (v0154 == v0153) goto v0184;
    v0153 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0153);

v0184:
    v0153 = v0109;
    v0153 = qcdr(v0153);
    v0154 = qcdr(v0153);
    v0153 = (Lisp_Object)1; /* 0 */
    v0153 = (v0154 == v0153 ? lisp_true : nil);
    return onevalue(v0153);
}



/* Code for mcharg2 */

static Lisp_Object MS_CDECL CC_mcharg2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0147,
                         Lisp_Object v0188, Lisp_Object v0245, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0074, v0120, v0272;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "mcharg2");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mcharg2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0245,v0188,v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0147,v0188,v0245);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-6] = v0245;
    stack[-7] = v0188;
    stack[-8] = v0147;
    stack[-9] = v0000;
/* end of prologue */
    v0074 = stack[-9];
    if (v0074 == nil) { Lisp_Object res = stack[-7]; popv(12); return onevalue(res); }
    v0074 = stack[-9];
    v0120 = qcar(v0074);
    v0074 = stack[-8];
    v0074 = qcar(v0074);
    fn = elt(env, 2); /* mchk */
    v0074 = (*qfn2(fn))(qenv(fn), v0120, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-11];
    v0120 = v0074;
    v0074 = stack[-9];
    v0074 = qcdr(v0074);
    stack[-9] = v0074;
    v0074 = stack[-8];
    v0074 = qcdr(v0074);
    stack[-8] = v0074;
    v0074 = v0120;
    stack[-10] = v0074;
    goto v0115;

v0115:
    v0074 = stack[-10];
    if (v0074 == nil) goto v0127;
    v0074 = stack[-10];
    v0074 = qcar(v0074);
    stack[-2] = v0074;
    stack[-1] = stack[-9];
    v0272 = stack[-2];
    v0120 = stack[-8];
    v0074 = stack[-6];
    fn = elt(env, 3); /* updtemplate */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0272, v0120, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-11];
    v0120 = stack[-7];
    v0074 = stack[-2];
    fn = elt(env, 4); /* msappend */
    v0120 = (*qfn2(fn))(qenv(fn), v0120, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-11];
    v0074 = stack[-6];
    v0074 = CC_mcharg2(env, 4, stack[-1], stack[0], v0120, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-11];
    stack[-5] = v0074;
    v0074 = stack[-5];
    fn = elt(env, 5); /* lastpair */
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-11];
    stack[-4] = v0074;
    v0074 = stack[-10];
    v0074 = qcdr(v0074);
    stack[-10] = v0074;
    v0074 = stack[-4];
    if (!consp(v0074)) goto v0115;
    else goto v0116;

v0116:
    v0074 = stack[-10];
    if (v0074 == nil) { Lisp_Object res = stack[-5]; popv(12); return onevalue(res); }
    stack[-3] = stack[-4];
    v0074 = stack[-10];
    v0074 = qcar(v0074);
    stack[-2] = v0074;
    stack[-1] = stack[-9];
    v0272 = stack[-2];
    v0120 = stack[-8];
    v0074 = stack[-6];
    fn = elt(env, 3); /* updtemplate */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0272, v0120, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-11];
    v0120 = stack[-7];
    v0074 = stack[-2];
    fn = elt(env, 4); /* msappend */
    v0120 = (*qfn2(fn))(qenv(fn), v0120, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-11];
    v0074 = stack[-6];
    v0074 = CC_mcharg2(env, 4, stack[-1], stack[0], v0120, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-11];
    v0074 = Lrplacd(nil, stack[-3], v0074);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-11];
    v0074 = stack[-4];
    fn = elt(env, 5); /* lastpair */
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-11];
    stack[-4] = v0074;
    v0074 = stack[-10];
    v0074 = qcdr(v0074);
    stack[-10] = v0074;
    goto v0116;

v0127:
    v0074 = qvalue(elt(env, 1)); /* nil */
    { popv(12); return onevalue(v0074); }
/* error exit handlers */
v0206:
    popv(12);
    return nil;
}



/* Code for cgp_evlmon */

static Lisp_Object CC_cgp_evlmon(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0173;
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
    v0173 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* cgp_rp */
    v0173 = (*qfn1(fn))(qenv(fn), v0173);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dip_evlmon */
        return (*qfn1(fn))(qenv(fn), v0173);
    }
/* error exit handlers */
v0100:
    popv(1);
    return nil;
}



/* Code for quotfd */

static Lisp_Object CC_quotfd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0194, v0093, v0113, v0112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotfd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0113 = v0147;
    v0112 = v0000;
/* end of prologue */
    v0093 = v0112;
    v0194 = v0113;
    if (equal(v0093, v0194)) goto v0173;
    v0194 = qvalue(elt(env, 1)); /* dmode!* */
    if (!symbolp(v0194)) v0194 = nil;
    else { v0194 = qfastgets(v0194);
           if (v0194 != nil) { v0194 = elt(v0194, 3); /* field */
#ifdef RECORD_GET
             if (v0194 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0194 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0194 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0194 == SPID_NOPROP) v0194 = nil; else v0194 = lisp_true; }}
#endif
    if (v0194 == nil) goto v0149;
    v0194 = v0112;
    v0093 = v0113;
    {
        fn = elt(env, 3); /* divd */
        return (*qfn2(fn))(qenv(fn), v0194, v0093);
    }

v0149:
    v0194 = v0112;
    if (!consp(v0194)) goto v0111;
    v0194 = v0112;
    v0194 = qcar(v0194);
    v0194 = (consp(v0194) ? nil : lisp_true);
    goto v0109;

v0109:
    if (v0194 == nil) goto v0177;
    v0194 = v0112;
    v0093 = v0113;
    {
        fn = elt(env, 4); /* quotdd */
        return (*qfn2(fn))(qenv(fn), v0194, v0093);
    }

v0177:
    v0194 = v0112;
    v0093 = v0113;
    {
        fn = elt(env, 5); /* quotk */
        return (*qfn2(fn))(qenv(fn), v0194, v0093);
    }

v0111:
    v0194 = qvalue(elt(env, 2)); /* t */
    goto v0109;

v0173:
    v0194 = (Lisp_Object)17; /* 1 */
    return onevalue(v0194);
}



/* Code for retattributes */

static Lisp_Object CC_retattributes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0147)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0202, v0189;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for retattributes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0147,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0147);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0147;
    stack[-1] = v0000;
/* end of prologue */

v0239:
    v0202 = stack[0];
    if (v0202 == nil) goto v0107;
    v0189 = stack[-1];
    v0202 = stack[0];
    v0202 = qcar(v0202);
    fn = elt(env, 2); /* find */
    v0202 = (*qfn2(fn))(qenv(fn), v0189, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-3];
    v0189 = v0202;
    if (v0189 == nil) goto v0199;
    v0189 = stack[0];
    v0189 = qcar(v0189);
    stack[-2] = list2(v0189, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-3];
    v0189 = stack[-1];
    v0202 = stack[0];
    v0202 = qcdr(v0202);
    v0202 = CC_retattributes(env, v0189, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    {
        Lisp_Object v0176 = stack[-2];
        popv(4);
        return cons(v0176, v0202);
    }

v0199:
    v0189 = stack[-1];
    v0202 = stack[0];
    v0202 = qcdr(v0202);
    stack[-1] = v0189;
    stack[0] = v0202;
    goto v0239;

v0107:
    v0202 = nil;
    { popv(4); return onevalue(v0202); }
/* error exit handlers */
v0174:
    popv(4);
    return nil;
}



setup_type const u05_setup[] =
{
    {"subs2f1",                 CC_subs2f1,     too_many_1,    wrong_no_1},
    {"ofsf_posdefp",            CC_ofsf_posdefp,too_many_1,    wrong_no_1},
    {"rl_susibin",              too_few_2,      CC_rl_susibin, wrong_no_2},
    {"sfto_dcontentf",          CC_sfto_dcontentf,too_many_1,  wrong_no_1},
    {"omobj",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobj},
    {"round:mt",                too_few_2,      CC_roundTmt,   wrong_no_2},
    {"dm-difference",           too_few_2,      CC_dmKdifference,wrong_no_2},
    {"genp",                    CC_genp,        too_many_1,    wrong_no_1},
    {"boundindp",               too_few_2,      CC_boundindp,  wrong_no_2},
    {"round:last",              CC_roundTlast,  too_many_1,    wrong_no_1},
    {"abs:",                    CC_absT,        too_many_1,    wrong_no_1},
    {"simpminus",               CC_simpminus,   too_many_1,    wrong_no_1},
    {"getroad",                 too_few_2,      CC_getroad,    wrong_no_2},
    {"getrmacro",               CC_getrmacro,   too_many_1,    wrong_no_1},
    {"dp_diff",                 too_few_2,      CC_dp_diff,    wrong_no_2},
    {"resimp",                  CC_resimp,      too_many_1,    wrong_no_1},
    {"insert_pv1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_insert_pv1},
    {"modplus:",                too_few_2,      CC_modplusT,   wrong_no_2},
    {"kernord",                 too_few_2,      CC_kernord,    wrong_no_2},
    {"ibalp_minclnr",           CC_ibalp_minclnr,too_many_1,   wrong_no_1},
    {"sfto_mvartest",           too_few_2,      CC_sfto_mvartest,wrong_no_2},
    {"powers2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_powers2},
    {"rank",                    CC_rank,        too_many_1,    wrong_no_1},
    {"mathml",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mathml},
    {"bcsum",                   too_few_2,      CC_bcsum,      wrong_no_2},
    {"mknwedge",                CC_mknwedge,    too_many_1,    wrong_no_1},
    {"worderp",                 too_few_2,      CC_worderp,    wrong_no_2},
    {"vecopp",                  CC_vecopp,      too_many_1,    wrong_no_1},
    {"*ssave",                  too_few_2,      CC_Hssave,     wrong_no_2},
    {"pv_sort2a",               too_few_2,      CC_pv_sort2a,  wrong_no_2},
    {"mkgi",                    too_few_2,      CC_mkgi,       wrong_no_2},
    {"tayexp-min2",             too_few_2,      CC_tayexpKmin2,wrong_no_2},
    {"qqe_qtidp",               CC_qqe_qtidp,   too_many_1,    wrong_no_1},
    {"emtch",                   CC_emtch,       too_many_1,    wrong_no_1},
    {"subscriptedvarp",         CC_subscriptedvarp,too_many_1, wrong_no_1},
    {"fast-column-dim",         CC_fastKcolumnKdim,too_many_1, wrong_no_1},
    {"xdegree",                 CC_xdegree,     too_many_1,    wrong_no_1},
    {"deg*form",                CC_degHform,    too_many_1,    wrong_no_1},
    {"convchk",                 CC_convchk,     too_many_1,    wrong_no_1},
    {"red-char-downcase",       CC_redKcharKdowncase,too_many_1,wrong_no_1},
    {"delallasc",               too_few_2,      CC_delallasc,  wrong_no_2},
    {"getphystype*sq",          CC_getphystypeHsq,too_many_1,  wrong_no_1},
    {"contrsp2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_contrsp2},
    {"get-print-name",          CC_getKprintKname,too_many_1,  wrong_no_1},
    {"groeb=testa",             too_few_2,      CC_groebMtesta,wrong_no_2},
    {"pcmult",                  too_few_2,      CC_pcmult,     wrong_no_2},
    {"gperm1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm1},
    {"arzerop:",                CC_arzeropT,    too_many_1,    wrong_no_1},
    {"c:ordexp",                too_few_2,      CC_cTordexp,   wrong_no_2},
    {"minus-mod-p",             CC_minusKmodKp, too_many_1,    wrong_no_1},
    {"stable-sortip",           too_few_2,      CC_stableKsortip,wrong_no_2},
    {"exchk2",                  too_few_2,      CC_exchk2,     wrong_no_2},
    {"mri_type",                CC_mri_type,    too_many_1,    wrong_no_1},
    {"find",                    too_few_2,      CC_find,       wrong_no_2},
    {"sortcolelem",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_sortcolelem},
    {"pnthxzz",                 too_few_2,      CC_pnthxzz,    wrong_no_2},
    {"vevtdeg",                 CC_vevtdeg,     too_many_1,    wrong_no_1},
    {"*collectphysops",         CC_Hcollectphysops,too_many_1, wrong_no_1},
    {"sfpx",                    CC_sfpx,        too_many_1,    wrong_no_1},
    {"gcdf*",                   too_few_2,      CC_gcdfH,      wrong_no_2},
    {"tsym4",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_tsym4},
    {"general-modular-reciprocal",CC_generalKmodularKreciprocal,too_many_1,wrong_no_1},
    {"mri_0mk2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mri_0mk2},
    {"ibalp_commonlenisone",    too_few_2,      CC_ibalp_commonlenisone,wrong_no_2},
    {"ratpoly_idl",             CC_ratpoly_idl, too_many_1,    wrong_no_1},
    {"sfto_dcontentf1",         too_few_2,      CC_sfto_dcontentf1,wrong_no_2},
    {"multi_elem",              CC_multi_elem,  too_many_1,    wrong_no_1},
    {"rationalizei",            CC_rationalizei,too_many_1,    wrong_no_1},
    {"gsetsugar",               too_few_2,      CC_gsetsugar,  wrong_no_2},
    {"maxdeg",                  too_few_2,      CC_maxdeg,     wrong_no_2},
    {"getphystype",             CC_getphystype, too_many_1,    wrong_no_1},
    {"setcloc*",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_setclocH},
    {"dp_term",                 too_few_2,      CC_dp_term,    wrong_no_2},
    {"dquot",                   too_few_2,      CC_dquot,      wrong_no_2},
    {"gperm",                   CC_gperm,       too_many_1,    wrong_no_1},
    {"gizerop:",                CC_gizeropT,    too_many_1,    wrong_no_1},
    {"mcharg2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg2},
    {"cgp_evlmon",              CC_cgp_evlmon,  too_many_1,    wrong_no_1},
    {"quotfd",                  too_few_2,      CC_quotfd,     wrong_no_2},
    {"retattributes",           too_few_2,      CC_retattributes,wrong_no_2},
    {NULL, (one_args *)"u05", (two_args *)"16895 8512347 9669586", 0}
};

/* end of generated code */
