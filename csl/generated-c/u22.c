
/* $destdir/u22.c        Machine generated C code */

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


/* Code for !:dmtimeslst */

static Lisp_Object CC_Tdmtimeslst(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :dmtimeslst");
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
    v0004 = v0000;
/* end of prologue */
    v0003 = v0004;
    if (v0003 == nil) goto v0005;
    v0003 = v0004;
    v0003 = qcdr(v0003);
    if (v0003 == nil) goto v0006;
    v0003 = v0004;
    stack[0] = qcar(v0003);
    v0003 = v0004;
    v0003 = qcdr(v0003);
    v0003 = CC_Tdmtimeslst(env, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-1];
    {
        Lisp_Object v0008 = stack[0];
        popv(2);
        fn = elt(env, 1); /* !:times */
        return (*qfn2(fn))(qenv(fn), v0008, v0003);
    }

v0006:
    v0003 = v0004;
    v0003 = qcar(v0003);
    { popv(2); return onevalue(v0003); }

v0005:
    v0003 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v0003); }
/* error exit handlers */
v0007:
    popv(2);
    return nil;
}



/* Code for formde */

static Lisp_Object MS_CDECL CC_formde(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0010, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0023, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formde");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formde");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0009,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0010;
    stack[-5] = v0009;
    v0022 = v0000;
/* end of prologue */
    stack[-6] = elt(env, 1); /* procedure */
    v0023 = v0022;
    v0023 = qcdr(v0023);
    stack[-3] = qcar(v0023);
    stack[-2] = elt(env, 2); /* symbolic */
    stack[-1] = elt(env, 3); /* expr */
    v0023 = v0022;
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    stack[0] = qcar(v0023);
    v0023 = v0022;
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    v0023 = qcdr(v0023);
    if (v0023 == nil) goto v0025;
    v0023 = elt(env, 4); /* progn */
    v0022 = qcdr(v0022);
    v0022 = qcdr(v0022);
    v0022 = qcdr(v0022);
    v0022 = cons(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-7];
    goto v0027;

v0027:
    v0022 = list3(stack[-1], stack[0], v0022);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-7];
    v0024 = list3star(stack[-6], stack[-3], stack[-2], v0022);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-7];
    v0023 = stack[-5];
    v0022 = stack[-4];
    {
        popv(8);
        fn = elt(env, 5); /* formproc */
        return (*qfnn(fn))(qenv(fn), 3, v0024, v0023, v0022);
    }

v0025:
    v0022 = qcdr(v0022);
    v0022 = qcdr(v0022);
    v0022 = qcdr(v0022);
    v0022 = qcar(v0022);
    goto v0027;
/* error exit handlers */
v0026:
    popv(8);
    return nil;
}



/* Code for mv!-domainlist */

static Lisp_Object CC_mvKdomainlist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-domainlist");
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
    v0004 = nil;
    goto v0028;

v0028:
    v0003 = stack[0];
    if (v0003 == nil) goto v0006;
    v0003 = stack[0];
    v0003 = qcar(v0003);
    v0003 = qcdr(v0003);
    v0003 = cons(v0003, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-1];
    v0004 = v0003;
    v0003 = stack[0];
    v0003 = qcdr(v0003);
    stack[0] = v0003;
    goto v0028;

v0006:
    v0003 = v0004;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0003);
    }
/* error exit handlers */
v0007:
    popv(2);
    return nil;
}



/* Code for dv_ind2var */

static Lisp_Object CC_dv_ind2var(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0019;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dv_ind2var");
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
    stack[-1] = stack[0];
    v0033 = qvalue(elt(env, 1)); /* g_dvnames */
    fn = elt(env, 3); /* upbve */
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-2];
    v0033 = (Lisp_Object)lesseq2(stack[-1], v0033);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    v0033 = v0033 ? lisp_true : nil;
    env = stack[-2];
    if (v0033 == nil) goto v0003;
    stack[-1] = qvalue(elt(env, 1)); /* g_dvnames */
    v0033 = stack[0];
    v0033 = sub1(v0033);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    v0033 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0033/(16/CELL)));
    { popv(3); return onevalue(v0033); }

v0003:
    v0019 = qvalue(elt(env, 2)); /* g_dvbase */
    v0033 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* mkid */
        return (*qfn2(fn))(qenv(fn), v0019, v0033);
    }
/* error exit handlers */
v0034:
    popv(3);
    return nil;
}



/* Code for !:expt */

static Lisp_Object CC_Texpt(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0074, v0075, v0076;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :expt");
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
    stack[-3] = v0009;
    stack[-4] = v0000;
/* end of prologue */
    v0074 = stack[-4];
    if (v0074 == nil) goto v0011;
    v0075 = stack[-3];
    v0074 = (Lisp_Object)1; /* 0 */
    if (v0075 == v0074) goto v0027;
    v0075 = stack[-3];
    v0074 = (Lisp_Object)17; /* 1 */
    if (v0075 == v0074) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v0075 = stack[-4];
    v0074 = (Lisp_Object)17; /* 1 */
    if (v0075 == v0074) goto v0077;
    v0075 = stack[-3];
    v0074 = (Lisp_Object)1; /* 0 */
    v0074 = (Lisp_Object)lessp2(v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    v0074 = v0074 ? lisp_true : nil;
    env = stack[-6];
    if (v0074 == nil) goto v0079;
    v0074 = stack[-4];
    fn = elt(env, 5); /* fieldp */
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-6];
    if (v0074 == nil) goto v0080;
    v0074 = stack[-4];
    stack[0] = v0074;
    goto v0081;

v0081:
    v0074 = stack[-3];
    v0074 = negate(v0074);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-6];
    v0074 = CC_Texpt(env, stack[0], v0074);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 6); /* !:recip */
        return (*qfn1(fn))(qenv(fn), v0074);
    }

v0080:
    v0074 = stack[-4];
    fn = elt(env, 7); /* mkratnum */
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-6];
    stack[0] = v0074;
    goto v0081;

v0079:
    v0074 = stack[-4];
    if (!consp(v0074)) goto v0082;
    v0074 = stack[-4];
    v0075 = qcar(v0074);
    v0074 = elt(env, 4); /* expt */
    v0074 = get(v0075, v0074);
    env = stack[-6];
    stack[-2] = v0074;
    if (v0074 == nil) goto v0083;
    v0076 = stack[-2];
    v0075 = stack[-4];
    v0074 = stack[-3];
        popv(7);
        return Lapply2(nil, 3, v0076, v0075, v0074);

v0083:
    v0074 = stack[-4];
    v0074 = qcar(v0074);
    if (!symbolp(v0074)) v0075 = nil;
    else { v0075 = qfastgets(v0074);
           if (v0075 != nil) { v0075 = elt(v0075, 34); /* i2d */
#ifdef RECORD_GET
             if (v0075 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0075 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0075 == SPID_NOPROP) v0075 = nil; }}
#endif
    v0074 = (Lisp_Object)17; /* 1 */
    v0074 = Lapply1(nil, v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-6];
    stack[-5] = v0074;
    v0074 = stack[-4];
    v0074 = qcar(v0074);
    if (!symbolp(v0074)) v0074 = nil;
    else { v0074 = qfastgets(v0074);
           if (v0074 != nil) { v0074 = elt(v0074, 54); /* times */
#ifdef RECORD_GET
             if (v0074 != SPID_NOPROP)
                record_get(elt(fastget_names, 54), 1);
             else record_get(elt(fastget_names, 54), 0),
                v0074 = nil; }
           else record_get(elt(fastget_names, 54), 0); }
#else
             if (v0074 == SPID_NOPROP) v0074 = nil; }}
#endif
    stack[-2] = v0074;
    goto v0084;

v0084:
    v0074 = stack[-3];
    stack[-1] = v0074;
    stack[0] = (Lisp_Object)33; /* 2 */
    v0075 = stack[-3];
    v0074 = (Lisp_Object)33; /* 2 */
    v0074 = quot2(v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-6];
    stack[-3] = v0074;
    v0074 = times2(stack[0], v0074);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-6];
    v0075 = difference2(stack[-1], v0074);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-6];
    v0074 = (Lisp_Object)1; /* 0 */
    if (v0075 == v0074) goto v0085;
    v0076 = stack[-2];
    v0075 = stack[-4];
    v0074 = stack[-5];
    v0074 = Lapply2(nil, 3, v0076, v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-6];
    stack[-5] = v0074;
    goto v0085;

v0085:
    v0075 = stack[-3];
    v0074 = (Lisp_Object)1; /* 0 */
    if (v0075 == v0074) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    v0076 = stack[-2];
    v0075 = stack[-4];
    v0074 = stack[-4];
    v0074 = Lapply2(nil, 3, v0076, v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-6];
    stack[-4] = v0074;
    goto v0084;

v0082:
    v0075 = stack[-4];
    v0074 = stack[-3];
        popv(7);
        return Lexpt(nil, v0075, v0074);

v0077:
    v0074 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v0074); }

v0027:
    v0074 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v0074); }

v0011:
    v0075 = stack[-3];
    v0074 = (Lisp_Object)1; /* 0 */
    if (v0075 == v0074) goto v0031;
    v0074 = qvalue(elt(env, 3)); /* nil */
    { popv(7); return onevalue(v0074); }

v0031:
    v0076 = elt(env, 1); /* poly */
    v0075 = (Lisp_Object)177; /* 11 */
    v0074 = elt(env, 2); /* "0/0 formed" */
    {
        popv(7);
        fn = elt(env, 8); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0076, v0075, v0074);
    }
/* error exit handlers */
v0078:
    popv(7);
    return nil;
}



/* Code for bndtst */

static Lisp_Object CC_bndtst(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0011;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bndtst");
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
    v0087 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* abs!: */
    v0011 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[0];
    v0087 = qvalue(elt(env, 1)); /* tentothetenth!*!* */
    {
        popv(1);
        fn = elt(env, 3); /* greaterp!: */
        return (*qfn2(fn))(qenv(fn), v0011, v0087);
    }
/* error exit handlers */
v0032:
    popv(1);
    return nil;
}



/* Code for n_nary */

static Lisp_Object CC_n_nary(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0065;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for n_nary");
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
    v0024 = stack[-1];
    v0065 = qcar(v0024);
    v0024 = elt(env, 1); /* e */
    if (v0065 == v0024) goto v0030;
    v0024 = qvalue(elt(env, 3)); /* nil */
    goto v0086;

v0086:
    if (v0024 == nil) goto v0070;
    v0024 = stack[-1];
    v0065 = qcdr(v0024);
    v0024 = elt(env, 4); /* exp */
    fn = elt(env, 10); /* unary */
    v0024 = (*qfn2(fn))(qenv(fn), v0065, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    goto v0093;

v0093:
    v0024 = nil;
    { popv(3); return onevalue(v0024); }

v0070:
    v0024 = elt(env, 5); /* "<apply>" */
    fn = elt(env, 11); /* printout */
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-2];
    v0024 = elt(env, 6); /* "<" */
    v0024 = Lprinc(nil, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-2];
    v0024 = stack[0];
    v0024 = Lprinc(nil, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-2];
    v0024 = elt(env, 7); /* "/>" */
    v0024 = Lprinc(nil, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-2];
    v0065 = qvalue(elt(env, 8)); /* indent */
    v0024 = (Lisp_Object)49; /* 3 */
    v0024 = plus2(v0065, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-2];
    qvalue(elt(env, 8)) = v0024; /* indent */
    v0024 = stack[-1];
    fn = elt(env, 12); /* multi_elem */
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-2];
    v0065 = qvalue(elt(env, 8)); /* indent */
    v0024 = (Lisp_Object)49; /* 3 */
    v0024 = difference2(v0065, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-2];
    qvalue(elt(env, 8)) = v0024; /* indent */
    v0024 = elt(env, 9); /* "</apply>" */
    fn = elt(env, 11); /* printout */
    v0024 = (*qfn1(fn))(qenv(fn), v0024);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    goto v0093;

v0030:
    v0065 = stack[0];
    v0024 = elt(env, 2); /* power */
    v0024 = (v0065 == v0024 ? lisp_true : nil);
    goto v0086;
/* error exit handlers */
v0092:
    popv(3);
    return nil;
}



/* Code for recaliasbacksubst */

static Lisp_Object CC_recaliasbacksubst(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for recaliasbacksubst");
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
    stack[-3] = v0009;
    stack[0] = v0000;
/* end of prologue */
    v0082 = stack[0];
    if (!consp(v0082)) goto v0090;
    v0082 = stack[0];
    fn = elt(env, 3); /* constp */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    goto v0006;

v0006:
    if (v0082 == nil) goto v0070;
    v0103 = stack[0];
    v0082 = stack[-3];
    v0082 = Lassoc(nil, v0103, v0082);
    if (v0082 == nil) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v0103 = stack[0];
    v0082 = stack[-3];
    v0082 = Lassoc(nil, v0103, v0082);
    v0082 = qcdr(v0082);
    { popv(6); return onevalue(v0082); }

v0070:
    v0082 = stack[0];
    stack[-4] = v0082;
    v0082 = stack[-4];
    if (v0082 == nil) goto v0105;
    v0082 = stack[-4];
    v0082 = qcar(v0082);
    v0103 = v0082;
    v0082 = stack[-3];
    v0082 = CC_recaliasbacksubst(env, v0103, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    v0082 = ncons(v0082);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    stack[-1] = v0082;
    stack[-2] = v0082;
    goto v0106;

v0106:
    v0082 = stack[-4];
    v0082 = qcdr(v0082);
    stack[-4] = v0082;
    v0082 = stack[-4];
    if (v0082 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0082 = stack[-4];
    v0082 = qcar(v0082);
    v0103 = v0082;
    v0082 = stack[-3];
    v0082 = CC_recaliasbacksubst(env, v0103, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    v0082 = ncons(v0082);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    v0082 = Lrplacd(nil, stack[0], v0082);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-5];
    v0082 = stack[-1];
    v0082 = qcdr(v0082);
    stack[-1] = v0082;
    goto v0106;

v0105:
    v0082 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0082); }

v0090:
    v0082 = qvalue(elt(env, 1)); /* t */
    goto v0006;
/* error exit handlers */
v0104:
    popv(6);
    return nil;
}



/* Code for make!-unique!-freevars */

static Lisp_Object CC_makeKuniqueKfreevars(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108, v0109, v0110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make-unique-freevars");
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
    v0109 = v0000;
/* end of prologue */
    v0108 = v0109;
    if (!consp(v0108)) goto v0011;
    v0108 = v0109;
    stack[-3] = v0108;
    v0108 = stack[-3];
    if (v0108 == nil) goto v0026;
    v0108 = stack[-3];
    v0108 = qcar(v0108);
    v0108 = CC_makeKuniqueKfreevars(env, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0108 = ncons(v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    stack[-1] = v0108;
    stack[-2] = v0108;
    goto v0092;

v0092:
    v0108 = stack[-3];
    v0108 = qcdr(v0108);
    stack[-3] = v0108;
    v0108 = stack[-3];
    if (v0108 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0108 = stack[-3];
    v0108 = qcar(v0108);
    v0108 = CC_makeKuniqueKfreevars(env, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0108 = ncons(v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0108 = Lrplacd(nil, stack[0], v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0108 = stack[-1];
    v0108 = qcdr(v0108);
    stack[-1] = v0108;
    goto v0092;

v0026:
    v0108 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v0108); }

v0011:
    v0110 = v0109;
    v0108 = elt(env, 1); /* gen */
    v0108 = get(v0110, v0108);
    env = stack[-4];
    if (v0108 == nil) { popv(5); return onevalue(v0109); }
    v0110 = v0109;
    v0108 = qvalue(elt(env, 2)); /* freevarlist!* */
    v0108 = Latsoc(nil, v0110, v0108);
    stack[0] = v0108;
    v0108 = stack[0];
    if (!(v0108 == nil)) goto v0008;
    stack[0] = v0109;
    fn = elt(env, 5); /* pm!:gensym */
    v0108 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0108 = cons(stack[0], v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    stack[0] = v0108;
    v0108 = stack[0];
    v0110 = qcdr(v0108);
    v0109 = elt(env, 1); /* gen */
    v0108 = qvalue(elt(env, 3)); /* t */
    v0108 = Lputprop(nil, 3, v0110, v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    v0109 = stack[0];
    v0108 = qvalue(elt(env, 2)); /* freevarlist!* */
    v0108 = cons(v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0108; /* freevarlist!* */
    goto v0008;

v0008:
    v0108 = stack[0];
    v0108 = qcdr(v0108);
    { popv(5); return onevalue(v0108); }
/* error exit handlers */
v0111:
    popv(5);
    return nil;
}



/* Code for noncomexpf */

static Lisp_Object CC_noncomexpf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomexpf");
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

v0112:
    v0034 = stack[0];
    if (!consp(v0034)) goto v0006;
    v0034 = stack[0];
    v0034 = qcar(v0034);
    v0034 = (consp(v0034) ? nil : lisp_true);
    goto v0102;

v0102:
    if (v0034 == nil) goto v0005;
    v0034 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0034); }

v0005:
    v0034 = stack[0];
    v0034 = qcar(v0034);
    v0034 = qcar(v0034);
    v0034 = qcar(v0034);
    fn = elt(env, 3); /* noncomp */
    v0034 = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-1];
    if (!(v0034 == nil)) { popv(2); return onevalue(v0034); }
    v0034 = stack[0];
    v0034 = qcar(v0034);
    v0034 = qcdr(v0034);
    v0034 = CC_noncomexpf(env, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-1];
    if (!(v0034 == nil)) { popv(2); return onevalue(v0034); }
    v0034 = stack[0];
    v0034 = qcdr(v0034);
    stack[0] = v0034;
    goto v0112;

v0006:
    v0034 = qvalue(elt(env, 1)); /* t */
    goto v0102;
/* error exit handlers */
v0018:
    popv(2);
    return nil;
}



/* Code for my_letmtr */

static Lisp_Object MS_CDECL CC_my_letmtr(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0010, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0128, v0129, v0130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "my_letmtr");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for my_letmtr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0009,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0010;
    stack[-4] = v0009;
    stack[-5] = v0000;
/* end of prologue */
    stack[-2] = nil;
    v0129 = stack[-3];
    v0128 = elt(env, 1); /* mat */
    if (!consp(v0129)) goto v0031;
    v0129 = qcar(v0129);
    if (!(v0129 == v0128)) goto v0031;
    v0128 = stack[-5];
    v0128 = qcdr(v0128);
    stack[-6] = v0128;
    v0128 = stack[-6];
    if (v0128 == nil) goto v0089;
    v0128 = stack[-6];
    v0128 = qcar(v0128);
    v0129 = v0128;
    v0128 = v0129;
    v0128 = integerp(v0128);
    if (v0128 == nil) goto v0131;
    v0128 = v0129;
    goto v0012;

v0012:
    v0128 = ncons(v0128);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-7];
    stack[-1] = v0128;
    stack[-2] = v0128;
    goto v0077;

v0077:
    v0128 = stack[-6];
    v0128 = qcdr(v0128);
    stack[-6] = v0128;
    v0128 = stack[-6];
    if (v0128 == nil) goto v0132;
    stack[0] = stack[-1];
    v0128 = stack[-6];
    v0128 = qcar(v0128);
    v0129 = v0128;
    v0128 = v0129;
    v0128 = integerp(v0128);
    if (v0128 == nil) goto v0061;
    v0128 = v0129;
    goto v0082;

v0082:
    v0128 = ncons(v0128);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-7];
    v0128 = Lrplacd(nil, stack[0], v0128);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-7];
    v0128 = stack[-1];
    v0128 = qcdr(v0128);
    stack[-1] = v0128;
    goto v0077;

v0061:
    v0128 = v0129;
    fn = elt(env, 8); /* reval */
    v0128 = (*qfn1(fn))(qenv(fn), v0128);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-7];
    goto v0082;

v0132:
    v0128 = stack[-2];
    goto v0105;

v0105:
    stack[-2] = v0128;
    fn = elt(env, 9); /* numlis */
    v0128 = (*qfn1(fn))(qenv(fn), v0128);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-7];
    if (v0128 == nil) goto v0099;
    v0128 = stack[-2];
    v0129 = Llength(nil, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-7];
    v0128 = (Lisp_Object)33; /* 2 */
    v0128 = Lneq(nil, v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-7];
    goto v0100;

v0100:
    if (v0128 == nil) goto v0054;
    v0129 = stack[-5];
    v0128 = elt(env, 7); /* hold */
    {
        popv(8);
        fn = elt(env, 10); /* errpri2 */
        return (*qfn2(fn))(qenv(fn), v0129, v0128);
    }

v0054:
    v0128 = stack[-3];
    v0129 = qcdr(v0128);
    v0128 = stack[-2];
    v0128 = qcar(v0128);
    fn = elt(env, 11); /* nth */
    v0129 = (*qfn2(fn))(qenv(fn), v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-7];
    v0128 = stack[-2];
    v0128 = qcdr(v0128);
    v0128 = qcar(v0128);
    fn = elt(env, 12); /* pnth */
    v0129 = (*qfn2(fn))(qenv(fn), v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-7];
    v0128 = stack[-4];
    v0128 = Lrplaca(nil, v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    v0128 = nil;
    { popv(8); return onevalue(v0128); }

v0099:
    v0128 = qvalue(elt(env, 6)); /* t */
    goto v0100;

v0131:
    v0128 = v0129;
    fn = elt(env, 8); /* reval */
    v0128 = (*qfn1(fn))(qenv(fn), v0128);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-7];
    goto v0012;

v0089:
    v0128 = qvalue(elt(env, 5)); /* nil */
    goto v0105;

v0031:
    stack[-1] = elt(env, 2); /* matrix */
    stack[0] = (Lisp_Object)161; /* 10 */
    v0130 = elt(env, 3); /* "Matrix" */
    v0128 = stack[-5];
    v0129 = qcar(v0128);
    v0128 = elt(env, 4); /* "not set" */
    v0128 = list3(v0130, v0129, v0128);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-7];
    fn = elt(env, 13); /* rerror */
    v0128 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0128);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-7];
    goto v0054;
/* error exit handlers */
v0047:
    popv(8);
    return nil;
}



/* Code for nconc2 */

static Lisp_Object CC_nconc2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0134, v0127;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nconc2");
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
    v0134 = v0009;
    v0127 = v0000;
/* end of prologue */
    v0019 = v0127;
    if (!consp(v0019)) { popv(2); return onevalue(v0134); }
    v0019 = v0127;
    stack[0] = v0019;
    goto v0135;

v0135:
    v0019 = stack[0];
    v0019 = qcdr(v0019);
    v0019 = Lconsp(nil, v0019);
    env = stack[-1];
    if (v0019 == nil) goto v0003;
    v0019 = stack[0];
    v0019 = qcdr(v0019);
    stack[0] = v0019;
    goto v0135;

v0003:
    v0019 = stack[0];
    v0019 = Lrplacd(nil, v0019, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0017:
    popv(2);
    return nil;
}



/* Code for fortexp */

static Lisp_Object CC_fortexp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086, v0087;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fortexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0086 = v0000;
/* end of prologue */
    v0087 = v0086;
    v0086 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 1); /* fortexp1 */
        return (*qfn2(fn))(qenv(fn), v0087, v0086);
    }
}



/* Code for physopsimp */

static Lisp_Object CC_physopsimp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0180, v0181, v0182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physopsimp");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0000;
/* end of prologue */
    stack[-4] = nil;
    v0180 = stack[-6];
    if (symbolp(v0180)) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v0180 = stack[-6];
    v0180 = qcar(v0180);
    stack[-7] = v0180;
    v0180 = stack[-6];
    v0180 = qcdr(v0180);
    stack[-5] = v0180;
    v0180 = stack[-5];
    if (v0180 == nil) goto v0003;
    v0180 = stack[-5];
    v0180 = qcar(v0180);
    stack[0] = v0180;
    v0180 = stack[0];
    if (!(symbolp(v0180))) goto v0125;
    v0180 = stack[0];
    fn = elt(env, 7); /* isanindex */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    if (!(v0180 == nil)) goto v0127;
    v0180 = stack[0];
    fn = elt(env, 8); /* isavarindex */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    if (!(v0180 == nil)) goto v0127;

v0125:
    v0180 = stack[0];
    fn = elt(env, 9); /* physopsm!* */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    goto v0134;

v0134:
    v0180 = ncons(v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    stack[-2] = v0180;
    stack[-3] = v0180;
    goto v0016;

v0016:
    v0180 = stack[-5];
    v0180 = qcdr(v0180);
    stack[-5] = v0180;
    v0180 = stack[-5];
    if (v0180 == nil) goto v0088;
    stack[-1] = stack[-2];
    v0180 = stack[-5];
    v0180 = qcar(v0180);
    stack[0] = v0180;
    v0180 = stack[0];
    if (!(symbolp(v0180))) goto v0097;
    v0180 = stack[0];
    fn = elt(env, 7); /* isanindex */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    if (!(v0180 == nil)) goto v0184;
    v0180 = stack[0];
    fn = elt(env, 8); /* isavarindex */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    if (!(v0180 == nil)) goto v0184;

v0097:
    v0180 = stack[0];
    fn = elt(env, 9); /* physopsm!* */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    goto v0131;

v0131:
    v0180 = ncons(v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0180 = Lrplacd(nil, stack[-1], v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0180 = stack[-2];
    v0180 = qcdr(v0180);
    stack[-2] = v0180;
    goto v0016;

v0184:
    v0180 = stack[0];
    goto v0131;

v0088:
    v0180 = stack[-3];
    goto v0030;

v0030:
    stack[0] = v0180;
    stack[-5] = stack[-7];
    v0180 = stack[0];
    stack[-3] = v0180;
    v0180 = stack[-3];
    if (v0180 == nil) goto v0038;
    v0180 = stack[-3];
    v0180 = qcar(v0180);
    v0182 = v0180;
    v0181 = v0182;
    v0180 = elt(env, 2); /* !*sq */
    if (!consp(v0181)) goto v0185;
    v0181 = qcar(v0181);
    if (!(v0181 == v0180)) goto v0185;
    v0180 = v0182;
    v0180 = qcdr(v0180);
    v0180 = qcar(v0180);
    fn = elt(env, 10); /* prepsqxx */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    goto v0186;

v0186:
    v0180 = ncons(v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    stack[-1] = v0180;
    stack[-2] = v0180;
    goto v0104;

v0104:
    v0180 = stack[-3];
    v0180 = qcdr(v0180);
    stack[-3] = v0180;
    v0180 = stack[-3];
    if (v0180 == nil) goto v0187;
    stack[0] = stack[-1];
    v0180 = stack[-3];
    v0180 = qcar(v0180);
    v0182 = v0180;
    v0181 = v0182;
    v0180 = elt(env, 2); /* !*sq */
    if (!consp(v0181)) goto v0188;
    v0181 = qcar(v0181);
    if (!(v0181 == v0180)) goto v0188;
    v0180 = v0182;
    v0180 = qcdr(v0180);
    v0180 = qcar(v0180);
    fn = elt(env, 10); /* prepsqxx */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    goto v0128;

v0128:
    v0180 = ncons(v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0180 = Lrplacd(nil, stack[0], v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0180 = stack[-1];
    v0180 = qcdr(v0180);
    stack[-1] = v0180;
    goto v0104;

v0188:
    v0180 = v0182;
    goto v0128;

v0187:
    v0180 = stack[-2];
    goto v0123;

v0123:
    v0180 = cons(stack[-5], v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    stack[-6] = v0180;
    v0180 = stack[-6];
    fn = elt(env, 11); /* opmtch!* */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    stack[0] = v0180;
    if (!(v0180 == nil)) { Lisp_Object res = stack[0]; popv(9); return onevalue(res); }
    v0180 = stack[-6];
    fn = elt(env, 12); /* scalopp */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    if (v0180 == nil) goto v0189;
    v0180 = stack[-7];
    fn = elt(env, 13); /* tensopp */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    if (v0180 == nil) goto v0189;
    v0181 = stack[-7];
    v0180 = elt(env, 3); /* tensdimen */
    v0180 = get(v0181, v0180);
    env = stack[-8];
    stack[-5] = v0180;
    v0180 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0180;
    v0181 = stack[-5];
    v0180 = stack[-3];
    v0180 = difference2(v0181, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0180 = Lminusp(nil, v0180);
    env = stack[-8];
    if (v0180 == nil) goto v0190;
    v0180 = qvalue(elt(env, 1)); /* nil */
    goto v0191;

v0191:
    stack[0] = v0180;
    v0180 = stack[-6];
    v0180 = qcdr(v0180);
    v0181 = Llength(nil, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0180 = stack[-5];
    v0180 = (Lisp_Object)greaterp2(v0181, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    v0180 = v0180 ? lisp_true : nil;
    env = stack[-8];
    if (v0180 == nil) goto v0192;
    v0180 = stack[-6];
    stack[-1] = qcdr(v0180);
    v0180 = stack[-5];
    v0180 = add1(v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    fn = elt(env, 14); /* pnth */
    v0180 = (*qfn2(fn))(qenv(fn), stack[-1], v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    stack[-5] = v0180;
    goto v0193;

v0193:
    v0180 = stack[-7];
    if (!symbolp(v0180)) v0180 = nil;
    else { v0180 = qfastgets(v0180);
           if (v0180 != nil) { v0180 = elt(v0180, 43); /* symmetric */
#ifdef RECORD_GET
             if (v0180 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v0180 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v0180 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v0180 == SPID_NOPROP) v0180 = nil; else v0180 = lisp_true; }}
#endif
    if (v0180 == nil) goto v0194;
    stack[-1] = stack[-7];
    v0180 = stack[0];
    fn = elt(env, 15); /* ordn */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0180 = cons(stack[-1], v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    stack[-6] = v0180;
    goto v0195;

v0195:
    v0180 = stack[-5];
    if (v0180 == nil) goto v0196;
    v0181 = stack[-6];
    v0180 = stack[-5];
    v0180 = Lappend(nil, v0181, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    stack[-6] = v0180;
    goto v0196;

v0196:
    v0180 = stack[-4];
    if (v0180 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v0181 = elt(env, 6); /* minus */
    v0180 = stack[-6];
    popv(9);
    return list2(v0181, v0180);

v0194:
    v0181 = stack[-7];
    v0180 = elt(env, 4); /* antisymmetric */
    v0180 = Lflagp(nil, v0181, v0180);
    env = stack[-8];
    if (v0180 == nil) goto v0197;
    v0180 = stack[0];
    fn = elt(env, 16); /* repeats */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    if (v0180 == nil) goto v0198;
    v0180 = (Lisp_Object)1; /* 0 */
    { popv(9); return onevalue(v0180); }

v0198:
    v0180 = stack[0];
    fn = elt(env, 15); /* ordn */
    v0181 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    stack[-1] = v0181;
    v0180 = stack[0];
    fn = elt(env, 17); /* permp */
    v0180 = (*qfn2(fn))(qenv(fn), v0181, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    if (!(v0180 == nil)) goto v0199;
    v0180 = qvalue(elt(env, 5)); /* t */
    stack[-4] = v0180;
    goto v0199;

v0199:
    v0180 = stack[-1];
    stack[0] = v0180;
    v0181 = stack[-7];
    v0180 = stack[0];
    v0180 = cons(v0181, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    stack[-6] = v0180;
    goto v0195;

v0197:
    v0181 = stack[-7];
    v0180 = stack[0];
    v0180 = cons(v0181, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    stack[-6] = v0180;
    goto v0195;

v0192:
    v0180 = qvalue(elt(env, 1)); /* nil */
    stack[-5] = v0180;
    goto v0193;

v0190:
    v0180 = stack[-6];
    v0181 = qcdr(v0180);
    v0180 = stack[-3];
    fn = elt(env, 18); /* nth */
    v0180 = (*qfn2(fn))(qenv(fn), v0181, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0180 = ncons(v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    stack[-1] = v0180;
    stack[-2] = v0180;
    goto v0200;

v0200:
    v0180 = stack[-3];
    v0180 = add1(v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    stack[-3] = v0180;
    v0181 = stack[-5];
    v0180 = stack[-3];
    v0180 = difference2(v0181, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0180 = Lminusp(nil, v0180);
    env = stack[-8];
    if (v0180 == nil) goto v0201;
    v0180 = stack[-2];
    goto v0191;

v0201:
    stack[0] = stack[-1];
    v0180 = stack[-6];
    v0181 = qcdr(v0180);
    v0180 = stack[-3];
    fn = elt(env, 18); /* nth */
    v0180 = (*qfn2(fn))(qenv(fn), v0181, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0180 = ncons(v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0180 = Lrplacd(nil, stack[0], v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0180 = stack[-1];
    v0180 = qcdr(v0180);
    stack[-1] = v0180;
    goto v0200;

v0189:
    v0180 = stack[-6];
    fn = elt(env, 19); /* vecopp */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    if (v0180 == nil) goto v0202;
    v0180 = stack[-6];
    fn = elt(env, 20); /* listp */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    if (v0180 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v0180 = stack[-6];
    v0180 = qcdr(v0180);
    v0180 = qcar(v0180);
    fn = elt(env, 21); /* putanewindex!* */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }

v0202:
    v0180 = stack[-6];
    fn = elt(env, 13); /* tensopp */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    if (v0180 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v0180 = stack[-6];
    fn = elt(env, 20); /* listp */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    if (v0180 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v0180 = (Lisp_Object)17; /* 1 */
    stack[0] = v0180;
    goto v0203;

v0203:
    v0180 = stack[-6];
    v0180 = qcdr(v0180);
    v0181 = Llength(nil, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0180 = stack[0];
    v0180 = difference2(v0181, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0180 = Lminusp(nil, v0180);
    env = stack[-8];
    if (!(v0180 == nil)) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v0180 = stack[-6];
    v0181 = qcdr(v0180);
    v0180 = stack[0];
    fn = elt(env, 18); /* nth */
    v0180 = (*qfn2(fn))(qenv(fn), v0181, v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    fn = elt(env, 21); /* putanewindex!* */
    v0180 = (*qfn1(fn))(qenv(fn), v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    v0180 = stack[0];
    v0180 = add1(v0180);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-8];
    stack[0] = v0180;
    goto v0203;

v0185:
    v0180 = v0182;
    goto v0186;

v0038:
    v0180 = qvalue(elt(env, 1)); /* nil */
    goto v0123;

v0127:
    v0180 = stack[0];
    goto v0134;

v0003:
    v0180 = qvalue(elt(env, 1)); /* nil */
    goto v0030;
/* error exit handlers */
v0183:
    popv(9);
    return nil;
}



/* Code for mk!-strand!-vertex2 */

static Lisp_Object MS_CDECL CC_mkKstrandKvertex2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0010, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0135, v0205, v0072;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mk-strand-vertex2");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk-strand-vertex2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0135 = v0010;
    v0205 = v0009;
    v0072 = v0000;
/* end of prologue */
    return list3(v0072, v0205, v0135);
}



/* Code for assert_stat1 */

static Lisp_Object MS_CDECL CC_assert_stat1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0208;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_stat1");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_stat1");
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
    stack[0] = nil;
    fn = elt(env, 8); /* scan */
    v0208 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-1];
    v0038 = elt(env, 1); /* !*lpar!* */
    if (v0208 == v0038) goto v0004;
    v0208 = elt(env, 2); /* "expecting '(' in assert but found" */
    v0038 = qvalue(elt(env, 3)); /* cursym!* */
    v0038 = list2(v0208, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-1];
    fn = elt(env, 9); /* rederr */
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-1];
    goto v0004;

v0004:
    fn = elt(env, 8); /* scan */
    v0208 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-1];
    v0038 = elt(env, 4); /* !*rpar!* */
    if (!(v0208 == v0038)) goto v0018;
    v0038 = qvalue(elt(env, 5)); /* nil */
    { popv(2); return onevalue(v0038); }

v0018:
    v0208 = qvalue(elt(env, 3)); /* cursym!* */
    v0038 = stack[0];
    v0038 = cons(v0208, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-1];
    stack[0] = v0038;
    fn = elt(env, 8); /* scan */
    v0038 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-1];
    v0208 = qvalue(elt(env, 3)); /* cursym!* */
    v0038 = elt(env, 6); /* !*comma!* */
    if (v0208 == v0038) goto v0024;
    v0208 = qvalue(elt(env, 3)); /* cursym!* */
    v0038 = elt(env, 4); /* !*rpar!* */
    v0038 = Lneq(nil, v0208, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-1];
    goto v0077;

v0077:
    if (v0038 == nil) goto v0209;
    v0208 = elt(env, 7); /* "expecting ',' or ')' in assert but found" 
*/
    v0038 = qvalue(elt(env, 3)); /* cursym!* */
    v0038 = list2(v0208, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-1];
    fn = elt(env, 9); /* rederr */
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-1];
    goto v0209;

v0209:
    v0208 = qvalue(elt(env, 3)); /* cursym!* */
    v0038 = elt(env, 6); /* !*comma!* */
    if (!(v0208 == v0038)) goto v0174;
    fn = elt(env, 8); /* scan */
    v0038 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-1];
    goto v0174;

v0174:
    v0208 = qvalue(elt(env, 3)); /* cursym!* */
    v0038 = elt(env, 4); /* !*rpar!* */
    if (!(v0208 == v0038)) goto v0018;
    v0038 = stack[0];
        popv(2);
        return Lnreverse(nil, v0038);

v0024:
    v0038 = qvalue(elt(env, 5)); /* nil */
    goto v0077;
/* error exit handlers */
v0084:
    popv(2);
    return nil;
}



/* Code for aex_freeidl */

static Lisp_Object CC_aex_freeidl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0204;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_freeidl");
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
    v0204 = stack[0];
    fn = elt(env, 1); /* aex_ex */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-2];
    fn = elt(env, 2); /* ratpoly_idl */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-2];
    v0204 = stack[0];
    fn = elt(env, 3); /* aex_ctx */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-2];
    fn = elt(env, 4); /* ctx_idl */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-2];
    {
        Lisp_Object v0073 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* lto_setminus */
        return (*qfn2(fn))(qenv(fn), v0073, v0204);
    }
/* error exit handlers */
v0072:
    popv(3);
    return nil;
}



/* Code for matrix_rows */

static Lisp_Object CC_matrix_rows(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0134, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matrix_rows");
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
    v0134 = stack[0];
    if (v0134 == nil) goto v0028;
    v0134 = elt(env, 1); /* "<matrixrow>" */
    fn = elt(env, 5); /* printout */
    v0134 = (*qfn1(fn))(qenv(fn), v0134);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-1];
    v0127 = qvalue(elt(env, 2)); /* indent */
    v0134 = (Lisp_Object)49; /* 3 */
    v0134 = plus2(v0127, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0134; /* indent */
    v0134 = stack[0];
    v0134 = qcar(v0134);
    fn = elt(env, 6); /* row */
    v0134 = (*qfn1(fn))(qenv(fn), v0134);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-1];
    v0127 = qvalue(elt(env, 2)); /* indent */
    v0134 = (Lisp_Object)49; /* 3 */
    v0134 = difference2(v0127, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0134; /* indent */
    v0134 = elt(env, 3); /* "</matrixrow>" */
    fn = elt(env, 5); /* printout */
    v0134 = (*qfn1(fn))(qenv(fn), v0134);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-1];
    v0134 = stack[0];
    v0134 = qcdr(v0134);
    v0134 = CC_matrix_rows(env, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    goto v0028;

v0028:
    v0134 = nil;
    { popv(2); return onevalue(v0134); }
/* error exit handlers */
v0017:
    popv(2);
    return nil;
}



/* Code for convprc2 */

static Lisp_Object CC_convprc2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0210, v0211, v0064;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for convprc2");
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
    v0210 = stack[-1];
    fn = elt(env, 4); /* convprec */
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-2];
    stack[-1] = v0210;
    v0210 = stack[0];
    fn = elt(env, 4); /* convprec */
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0210; /* yy!! */
    v0210 = qvalue(elt(env, 2)); /* !*roundbf */
    if (v0210 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0210 = qvalue(elt(env, 1)); /* yy!! */
    v0211 = v0210;
    v0211 = Lfloatp(nil, v0211);
    env = stack[-2];
    if (v0211 == nil) goto v0016;
    fn = elt(env, 5); /* fl2bf */
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-2];
    goto v0135;

v0135:
    qvalue(elt(env, 1)) = v0210; /* yy!! */
    v0210 = stack[-1];
    v0210 = Lfloatp(nil, v0210);
    env = stack[-2];
    if (v0210 == nil) goto v0089;
    v0210 = stack[-1];
    {
        popv(3);
        fn = elt(env, 5); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v0210);
    }

v0089:
    v0210 = stack[-1];
    if (!consp(v0210)) goto v0079;
    v0210 = stack[-1];
    goto v0020;

v0020:
    {
        popv(3);
        fn = elt(env, 6); /* normbf */
        return (*qfn1(fn))(qenv(fn), v0210);
    }

v0079:
    v0210 = stack[-1];
    v0210 = integerp(v0210);
    if (v0210 == nil) goto v0080;
    v0064 = elt(env, 3); /* !:rd!: */
    v0211 = stack[-1];
    v0210 = (Lisp_Object)1; /* 0 */
    v0210 = list2star(v0064, v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-2];
    goto v0020;

v0080:
    v0210 = stack[-1];
    fn = elt(env, 7); /* read!:num */
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-2];
    goto v0020;

v0016:
    v0211 = v0210;
    if (!(!consp(v0211))) goto v0014;
    v0211 = v0210;
    v0211 = integerp(v0211);
    if (v0211 == nil) goto v0207;
    v0064 = elt(env, 3); /* !:rd!: */
    v0211 = v0210;
    v0210 = (Lisp_Object)1; /* 0 */
    v0210 = list2star(v0064, v0211, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-2];
    goto v0014;

v0014:
    fn = elt(env, 6); /* normbf */
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-2];
    goto v0135;

v0207:
    fn = elt(env, 7); /* read!:num */
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-2];
    goto v0014;
/* error exit handlers */
v0096:
    popv(3);
    return nil;
}



/* Code for edge_new_parents */

static Lisp_Object CC_edge_new_parents(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0027, v0033, v0019;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for edge_new_parents");
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
    v0019 = v0000;
/* end of prologue */
    v0027 = v0019;
    v0033 = qcar(v0027);
    v0027 = qvalue(elt(env, 1)); /* old_edge_list */
    v0027 = Lassoc(nil, v0033, v0027);
    if (v0027 == nil) goto v0205;
    v0027 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0027); }

v0205:
    v0027 = v0019;
    v0027 = qcdr(v0027);
    v0027 = qcar(v0027);
    v0033 = v0027;
    v0033 = qcar(v0033);
    v0027 = qcdr(v0027);
    v0027 = list2(v0033, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* edge_new_parent */
        return (*qfn1(fn))(qenv(fn), v0027);
    }
/* error exit handlers */
v0134:
    popv(1);
    return nil;
}



/* Code for assert_stat!-parse */

static Lisp_Object MS_CDECL CC_assert_statKparse(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0211, v0064, v0122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_stat-parse");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_stat-parse");
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
    push3(nil, nil, nil);
/* end of prologue */
    fn = elt(env, 9); /* scan */
    v0211 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    stack[-2] = v0211;
    fn = elt(env, 9); /* scan */
    v0064 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    v0211 = elt(env, 1); /* !*colon!* */
    if (v0064 == v0211) goto v0006;
    v0064 = elt(env, 2); /* "expecting ':' in assert but found" */
    v0211 = qvalue(elt(env, 3)); /* cursym!* */
    v0211 = list2(v0064, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    fn = elt(env, 10); /* rederr */
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    goto v0006;

v0006:
    fn = elt(env, 11); /* assert_stat1 */
    v0211 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    stack[-1] = v0211;
    fn = elt(env, 9); /* scan */
    v0064 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    v0211 = elt(env, 4); /* difference */
    if (v0064 == v0211) goto v0214;
    v0211 = qvalue(elt(env, 5)); /* t */
    goto v0027;

v0027:
    if (v0211 == nil) goto v0071;
    v0064 = elt(env, 7); /* "expecting '->' in assert but found" */
    v0211 = qvalue(elt(env, 3)); /* cursym!* */
    v0211 = list2(v0064, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    fn = elt(env, 10); /* rederr */
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    goto v0071;

v0071:
    fn = elt(env, 9); /* scan */
    v0211 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    stack[0] = v0211;
    fn = elt(env, 9); /* scan */
    v0211 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    if (!symbolp(v0211)) v0211 = nil;
    else { v0211 = qfastgets(v0211);
           if (v0211 != nil) { v0211 = elt(v0211, 55); /* delim */
#ifdef RECORD_GET
             if (v0211 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v0211 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v0211 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v0211 == SPID_NOPROP) v0211 = nil; else v0211 = lisp_true; }}
#endif
    if (!(v0211 == nil)) goto v0063;
    v0064 = elt(env, 8); /* "expecting end of assert but found" */
    v0211 = qvalue(elt(env, 3)); /* cursym!* */
    v0211 = list2(v0064, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    fn = elt(env, 10); /* rederr */
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    goto v0063;

v0063:
    v0122 = stack[-2];
    v0064 = stack[-1];
    v0211 = stack[0];
    popv(4);
    return list3(v0122, v0064, v0211);

v0214:
    fn = elt(env, 9); /* scan */
    v0064 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    v0211 = elt(env, 6); /* greaterp */
    v0211 = Lneq(nil, v0064, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    goto v0027;
/* error exit handlers */
v0123:
    popv(4);
    return nil;
}



/* Code for list_is_all_free */

static Lisp_Object CC_list_is_all_free(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for list_is_all_free");
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
    v0030 = stack[0];
    if (v0030 == nil) goto v0102;
    v0030 = stack[0];
    v0030 = qcar(v0030);
    fn = elt(env, 3); /* nodum_varp */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0001;
    env = stack[-1];
    if (v0030 == nil) goto v0073;
    v0030 = stack[0];
    v0030 = qcdr(v0030);
    stack[0] = v0030;
    goto v0005;

v0073:
    v0030 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0030); }

v0102:
    v0030 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0030); }
/* error exit handlers */
v0001:
    popv(2);
    return nil;
}



/* Code for subf */

static Lisp_Object CC_subf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0085, v0170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subf");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0009;
    stack[-7] = v0000;
/* end of prologue */
    stack[-8] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    stack[-5] = nil;
    stack[-4] = nil;
    v0085 = qvalue(elt(env, 2)); /* nil */
    v0085 = ncons(v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    qvalue(elt(env, 1)) = v0085; /* alglist!* */
    v0085 = stack[-7];
    if (!consp(v0085)) goto v0072;
    v0085 = stack[-7];
    v0085 = qcar(v0085);
    v0085 = (consp(v0085) ? nil : lisp_true);
    goto v0205;

v0205:
    if (v0085 == nil) goto v0204;
    v0085 = stack[-7];
    fn = elt(env, 7); /* !*d2q */
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    goto v0006;

v0006:
    qvalue(elt(env, 1)) = stack[-8]; /* alglist!* */
    { popv(10); return onevalue(v0085); }

v0204:
    v0085 = qvalue(elt(env, 4)); /* ncmp!* */
    if (v0085 == nil) goto v0099;
    v0085 = stack[-7];
    fn = elt(env, 8); /* noncomexpf */
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    if (v0085 == nil) goto v0099;
    v0170 = stack[-7];
    v0085 = stack[-6];
    fn = elt(env, 9); /* subf1 */
    v0085 = (*qfn2(fn))(qenv(fn), v0170, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    goto v0006;

v0099:
    v0085 = stack[-6];
    stack[-3] = v0085;
    v0085 = stack[-3];
    if (v0085 == nil) goto v0101;
    v0085 = stack[-3];
    v0085 = qcar(v0085);
    v0085 = qcar(v0085);
    v0085 = ncons(v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    stack[-1] = v0085;
    stack[-2] = v0085;
    goto v0223;

v0223:
    v0085 = stack[-3];
    v0085 = qcdr(v0085);
    stack[-3] = v0085;
    v0085 = stack[-3];
    if (v0085 == nil) goto v0131;
    stack[0] = stack[-1];
    v0085 = stack[-3];
    v0085 = qcar(v0085);
    v0085 = qcar(v0085);
    v0085 = ncons(v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    v0085 = Lrplacd(nil, stack[0], v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    v0085 = stack[-1];
    v0085 = qcdr(v0085);
    stack[-1] = v0085;
    goto v0223;

v0131:
    v0085 = stack[-2];
    stack[0] = v0085;
    goto v0095;

v0095:
    v0170 = stack[-7];
    v0085 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 10); /* kernord */
    v0085 = (*qfn2(fn))(qenv(fn), v0170, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    fn = elt(env, 11); /* intersection */
    v0085 = (*qfn2(fn))(qenv(fn), stack[0], v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    v0085 = Lreverse(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    stack[0] = v0085;
    v0085 = stack[0];
    fn = elt(env, 12); /* setkorder */
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    stack[0] = v0085;
    v0085 = stack[-7];
    fn = elt(env, 13); /* reorder */
    v0170 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    v0085 = stack[-6];
    fn = elt(env, 9); /* subf1 */
    v0085 = (*qfn2(fn))(qenv(fn), v0170, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    stack[-7] = v0085;
    goto v0224;

v0224:
    v0170 = stack[-7];
    v0085 = stack[-4];
    v0085 = Lmember(nil, v0170, v0085);
    if (v0085 == nil) goto v0058;
    v0085 = qvalue(elt(env, 2)); /* nil */
    goto v0111;

v0111:
    if (v0085 == nil) goto v0108;
    v0170 = stack[-7];
    v0085 = stack[-4];
    v0085 = cons(v0170, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    stack[-4] = v0085;
    v0085 = stack[-5];
    fn = elt(env, 14); /* simp */
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    stack[-7] = v0085;
    goto v0224;

v0108:
    v0085 = stack[0];
    fn = elt(env, 12); /* setkorder */
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    v0085 = stack[-7];
    v0085 = qcar(v0085);
    fn = elt(env, 13); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    v0085 = stack[-7];
    v0085 = qcdr(v0085);
    fn = elt(env, 13); /* reorder */
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    v0085 = cons(stack[0], v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    goto v0006;

v0058:
    stack[-1] = elt(env, 5); /* expt */
    v0085 = stack[-7];
    v0085 = qcar(v0085);
    fn = elt(env, 15); /* kernels */
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    v0085 = Latsoc(nil, stack[-1], v0085);
    if (!(v0085 == nil)) goto v0046;
    stack[-1] = elt(env, 5); /* expt */
    v0085 = stack[-7];
    v0085 = qcdr(v0085);
    fn = elt(env, 15); /* kernels */
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    v0085 = Latsoc(nil, stack[-1], v0085);
    if (!(v0085 == nil)) goto v0046;
    v0085 = qvalue(elt(env, 2)); /* nil */
    goto v0111;

v0046:
    v0085 = stack[-7];
    fn = elt(env, 16); /* prepsq */
    v0170 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0222;
    env = stack[-9];
    stack[-5] = v0170;
    v0085 = qvalue(elt(env, 6)); /* varstack!* */
    v0085 = Lmember(nil, v0170, v0085);
    v0085 = (v0085 == nil ? lisp_true : nil);
    goto v0111;

v0101:
    v0085 = qvalue(elt(env, 2)); /* nil */
    stack[0] = v0085;
    goto v0095;

v0072:
    v0085 = qvalue(elt(env, 3)); /* t */
    goto v0205;
/* error exit handlers */
v0222:
    env = stack[-9];
    qvalue(elt(env, 1)) = stack[-8]; /* alglist!* */
    popv(10);
    return nil;
}



/* Code for width */

static Lisp_Object CC_width(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0126, v0021;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for width");
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
    v0126 = v0000;
/* end of prologue */
    v0021 = v0126;
    v0079 = elt(env, 1); /* textag */
    v0079 = get(v0021, v0079);
    env = stack[-2];
    stack[-1] = v0079;
    v0079 = stack[-1];
    if (!(v0079 == nil)) goto v0098;
    v0079 = elt(env, 2); /* "cannot find item " */
    v0126 = list2(v0079, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-2];
    v0079 = elt(env, 3); /* fatal */
    fn = elt(env, 5); /* tri!-error */
    v0079 = (*qfn2(fn))(qenv(fn), v0126, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-2];
    goto v0098;

v0098:
    v0126 = stack[0];
    v0079 = (Lisp_Object)1; /* 0 */
    v0079 = (Lisp_Object)greaterp2(v0126, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    v0079 = v0079 ? lisp_true : nil;
    env = stack[-2];
    if (v0079 == nil) goto v0019;
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    if (v0079 == nil) goto v0019;
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    stack[-1] = v0079;
    v0079 = stack[0];
    v0079 = sub1(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-2];
    stack[0] = v0079;
    goto v0098;

v0019:
    v0079 = stack[-1];
    v0079 = qcar(v0079);
    if (!(v0079 == nil)) { popv(3); return onevalue(v0079); }
    v0079 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0079); }
/* error exit handlers */
v0022:
    popv(3);
    return nil;
}



/* Code for matpri */

static Lisp_Object CC_matpri(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0011;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matpri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0087 = v0000;
/* end of prologue */
    v0011 = qcdr(v0087);
    v0087 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* matpri1 */
        return (*qfn2(fn))(qenv(fn), v0011, v0087);
    }
}



/* Code for qqe_arg!-check!-lb!-rb */

static Lisp_Object CC_qqe_argKcheckKlbKrb(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0099, v0207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_arg-check-lb-rb");
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
    v0099 = stack[0];
    v0099 = qcdr(v0099);
    v0099 = qcar(v0099);
    v0207 = v0099;
    v0099 = stack[0];
    v0099 = qcdr(v0099);
    v0099 = qcdr(v0099);
    v0099 = qcar(v0099);
    stack[-1] = v0099;
    v0099 = v0207;
    fn = elt(env, 3); /* qqe_arg!-check!-b */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    if (!(v0099 == nil)) goto v0204;
    fn = elt(env, 4); /* qqe_arg!-check!-marked!-ids!-rollback */
    v0099 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    v0207 = stack[0];
    v0099 = elt(env, 1); /* "type conflict: arguments don't fit
             binary op with basic type args" */
    fn = elt(env, 5); /* typerr */
    v0099 = (*qfn2(fn))(qenv(fn), v0207, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    goto v0204;

v0204:
    v0099 = stack[-1];
    fn = elt(env, 3); /* qqe_arg!-check!-b */
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    if (!(v0099 == nil)) goto v0007;
    fn = elt(env, 4); /* qqe_arg!-check!-marked!-ids!-rollback */
    v0099 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    v0207 = stack[0];
    v0099 = elt(env, 1); /* "type conflict: arguments don't fit
             binary op with basic type args" */
    fn = elt(env, 5); /* typerr */
    v0099 = (*qfn2(fn))(qenv(fn), v0207, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    goto v0007;

v0007:
    v0099 = nil;
    { popv(3); return onevalue(v0099); }
/* error exit handlers */
v0125:
    popv(3);
    return nil;
}



/* Code for pasf_floor */

static Lisp_Object CC_pasf_floor(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0224, v0059, v0060;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_floor");
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
    v0224 = stack[-1];
    if (!consp(v0224)) goto v0032;
    v0224 = stack[-1];
    v0224 = qcar(v0224);
    v0224 = (consp(v0224) ? nil : lisp_true);
    goto v0011;

v0011:
    if (v0224 == nil) goto v0027;
    v0224 = stack[0];
    if (!consp(v0224)) goto v0002;
    v0224 = stack[0];
    v0224 = qcar(v0224);
    v0224 = (consp(v0224) ? nil : lisp_true);
    goto v0006;

v0006:
    if (v0224 == nil) goto v0108;
    v0224 = stack[-1];
    if (v0224 == nil) goto v0034;
    v0059 = stack[-1];
    v0224 = stack[0];
    v0059 = Cremainder(v0059, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    v0224 = (Lisp_Object)1; /* 0 */
    if (v0059 == v0224) goto v0079;
    v0059 = stack[-1];
    v0224 = stack[0];
    v0059 = times2(v0059, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    v0224 = (Lisp_Object)1; /* 0 */
    v0224 = (Lisp_Object)greaterp2(v0059, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    v0224 = v0224 ? lisp_true : nil;
    env = stack[-2];
    if (v0224 == nil) goto v0176;
    v0059 = stack[-1];
    v0224 = stack[0];
    v0224 = quot2(v0059, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    goto v0207;

v0207:
    fn = elt(env, 4); /* simp */
    v0224 = (*qfn1(fn))(qenv(fn), v0224);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    v0224 = qcar(v0224);
    { popv(3); return onevalue(v0224); }

v0176:
    v0059 = stack[-1];
    v0224 = stack[0];
    v0224 = quot2(v0059, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    v0224 = sub1(v0224);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    goto v0207;

v0079:
    v0059 = stack[-1];
    v0224 = stack[0];
    v0224 = quot2(v0059, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    goto v0207;

v0034:
    v0224 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0224); }

v0108:
    v0060 = elt(env, 3); /* "pasf_floor: not a domain valued sf in input" 
*/
    v0059 = stack[-1];
    v0224 = stack[0];
    v0224 = list3(v0060, v0059, v0224);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 5); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0224);
    }

v0002:
    v0224 = qvalue(elt(env, 1)); /* t */
    goto v0006;

v0027:
    v0224 = qvalue(elt(env, 2)); /* nil */
    goto v0006;

v0032:
    v0224 = qvalue(elt(env, 1)); /* t */
    goto v0011;
/* error exit handlers */
v0118:
    popv(3);
    return nil;
}



/* Code for evmtest!? */

static Lisp_Object CC_evmtestW(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0017, v0018, v0070;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evmtest?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0017 = v0009;
    v0018 = v0000;
/* end of prologue */

v0028:
    v0034 = v0018;
    if (v0034 == nil) goto v0033;
    v0034 = v0017;
    if (v0034 == nil) goto v0033;
    v0034 = v0018;
    v0070 = qcar(v0034);
    v0034 = v0017;
    v0034 = qcar(v0034);
    if (((int32_t)(v0070)) < ((int32_t)(v0034))) goto v0008;
    v0034 = v0018;
    v0034 = qcdr(v0034);
    v0018 = v0034;
    v0034 = v0017;
    v0034 = qcdr(v0034);
    v0017 = v0034;
    goto v0028;

v0008:
    v0034 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0034);

v0033:
    v0034 = v0017;
    {
        fn = elt(env, 2); /* evzero!? */
        return (*qfn1(fn))(qenv(fn), v0034);
    }
}



/* Code for gvar1 */

static Lisp_Object CC_gvar1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0228, v0179, v0118, v0119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gvar1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0119 = v0009;
    v0118 = v0000;
/* end of prologue */

v0028:
    v0228 = v0118;
    if (v0228 == nil) goto v0011;
    v0228 = v0118;
    v0228 = (is_number(v0228) ? lisp_true : nil);
    if (!(v0228 == nil)) goto v0087;
    v0179 = v0118;
    v0228 = elt(env, 2); /* i */
    if (v0179 == v0228) goto v0015;
    v0228 = qvalue(elt(env, 4)); /* nil */
    goto v0087;

v0087:
    if (!(v0228 == nil)) return onevalue(v0119);
    v0228 = v0118;
    if (!consp(v0228)) goto v0207;
    v0228 = v0118;
    v0228 = qcar(v0228);
    if (!symbolp(v0228)) v0228 = nil;
    else { v0228 = qfastgets(v0228);
           if (v0228 != nil) { v0228 = elt(v0228, 8); /* dname */
#ifdef RECORD_GET
             if (v0228 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0228 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0228 == SPID_NOPROP) v0228 = nil; }}
#endif
    if (!(v0228 == nil)) return onevalue(v0119);
    v0228 = v0118;
    v0179 = qcar(v0228);
    v0228 = elt(env, 5); /* (plus times expt difference minus) */
    v0228 = Lmemq(nil, v0179, v0228);
    if (v0228 == nil) goto v0095;
    v0228 = v0118;
    v0228 = qcdr(v0228);
    v0179 = v0119;
    {
        fn = elt(env, 7); /* gvarlis1 */
        return (*qfn2(fn))(qenv(fn), v0228, v0179);
    }

v0095:
    v0228 = v0118;
    v0179 = qcar(v0228);
    v0228 = elt(env, 6); /* quotient */
    if (v0179 == v0228) goto v0064;
    v0179 = v0118;
    v0228 = v0119;
    v0228 = Lmember(nil, v0179, v0228);
    if (!(v0228 == nil)) return onevalue(v0119);
    v0228 = v0118;
    v0179 = v0119;
    return cons(v0228, v0179);

v0064:
    v0228 = v0118;
    v0228 = qcdr(v0228);
    v0228 = qcar(v0228);
    v0118 = v0228;
    goto v0028;

v0207:
    v0179 = v0118;
    v0228 = v0119;
    v0228 = Lmember(nil, v0179, v0228);
    if (!(v0228 == nil)) return onevalue(v0119);
    v0228 = v0118;
    v0179 = v0119;
    return cons(v0228, v0179);

v0015:
    v0228 = qvalue(elt(env, 3)); /* !*complex */
    goto v0087;

v0011:
    v0228 = qvalue(elt(env, 1)); /* t */
    goto v0087;
}



/* Code for basisformp */

static Lisp_Object CC_basisformp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0073, v0091;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for basisformp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0091 = v0000;
/* end of prologue */
    v0073 = v0091;
    if (!consp(v0073)) goto v0135;
    v0073 = v0091;
    v0091 = qvalue(elt(env, 1)); /* basisforml!* */
    v0073 = Lmemq(nil, v0073, v0091);
    return onevalue(v0073);

v0135:
    v0073 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0073);
}



/* Code for getrlist */

static Lisp_Object CC_getrlist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0100, v0099, v0207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getrlist");
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
    v0207 = v0000;
/* end of prologue */
    v0099 = v0207;
    v0100 = elt(env, 1); /* list */
    if (!consp(v0099)) goto v0071;
    v0099 = qcar(v0099);
    if (!(v0099 == v0100)) goto v0071;
    v0100 = v0207;
    v0100 = qcdr(v0100);
    { popv(1); return onevalue(v0100); }

v0071:
    v0099 = v0207;
    v0100 = elt(env, 2); /* !*sq */
    if (!consp(v0099)) goto v0018;
    v0099 = qcar(v0099);
    if (!(v0099 == v0100)) goto v0018;
    v0100 = v0207;
    v0100 = qcdr(v0100);
    v0100 = qcar(v0100);
    fn = elt(env, 4); /* prepsq */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[0];
    v0099 = v0100;
    goto v0030;

v0030:
    v0100 = elt(env, 3); /* "list" */
    {
        popv(1);
        fn = elt(env, 5); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0099, v0100);
    }

v0018:
    v0100 = v0207;
    v0099 = v0100;
    goto v0030;
/* error exit handlers */
v0214:
    popv(1);
    return nil;
}



/* Code for sublap */

static Lisp_Object CC_sublap(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0211, v0064;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sublap");
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
    v0211 = stack[-1];
    if (v0211 == nil) goto v0011;
    v0211 = stack[0];
    v0211 = (v0211 == nil ? lisp_true : nil);
    goto v0087;

v0087:
    if (!(v0211 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0211 = stack[0];
    if (!consp(v0211)) goto v0030;
    v0211 = stack[0];
    v0064 = qcar(v0211);
    v0211 = elt(env, 2); /* app */
    v0211 = Lflagp(nil, v0064, v0211);
    env = stack[-3];
    if (v0211 == nil) goto v0131;
    v0064 = stack[-1];
    v0211 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* sublap1 */
        return (*qfn2(fn))(qenv(fn), v0064, v0211);
    }

v0131:
    v0064 = stack[-1];
    v0211 = stack[0];
    v0211 = qcar(v0211);
    stack[-2] = CC_sublap(env, v0064, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-3];
    v0064 = stack[-1];
    v0211 = stack[0];
    v0211 = qcdr(v0211);
    v0211 = CC_sublap(env, v0064, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    {
        Lisp_Object v0123 = stack[-2];
        popv(4);
        return cons(v0123, v0211);
    }

v0030:
    v0211 = stack[0];
    if (is_number(v0211)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0064 = stack[0];
    v0211 = stack[-1];
    v0211 = Latsoc(nil, v0064, v0211);
    v0064 = v0211;
    if (v0211 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0211 = v0064;
    v0211 = qcdr(v0211);
    { popv(4); return onevalue(v0211); }

v0011:
    v0211 = qvalue(elt(env, 1)); /* t */
    goto v0087;
/* error exit handlers */
v0124:
    popv(4);
    return nil;
}



/* Code for l!-subst */

static Lisp_Object MS_CDECL CC_lKsubst(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0010, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0106, v0125, v0068;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "l-subst");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for l-subst");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0009,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0010;
    stack[-1] = v0009;
    stack[-2] = v0000;
/* end of prologue */
    v0068 = nil;
    goto v0102;

v0102:
    v0106 = stack[0];
    if (v0106 == nil) goto v0086;
    v0125 = stack[-1];
    v0106 = stack[0];
    v0106 = qcar(v0106);
    if (equal(v0125, v0106)) goto v0014;
    v0106 = stack[0];
    v0106 = qcar(v0106);
    v0125 = v0068;
    v0106 = cons(v0106, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0068 = v0106;
    v0106 = stack[0];
    v0106 = qcdr(v0106);
    stack[0] = v0106;
    goto v0102;

v0014:
    v0106 = stack[-2];
    v0125 = v0068;
    v0106 = cons(v0106, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-3];
    v0068 = v0106;
    v0106 = stack[0];
    v0106 = qcdr(v0106);
    stack[0] = v0106;
    goto v0102;

v0086:
    v0106 = v0068;
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0106);
    }
/* error exit handlers */
v0107:
    popv(4);
    return nil;
}



/* Code for formrlis */

static Lisp_Object MS_CDECL CC_formrlis(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0010, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0229, v0187, v0219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formrlis");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formrlis");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0009,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0229 = v0010;
    stack[-1] = v0009;
    stack[-2] = v0000;
/* end of prologue */
    v0229 = stack[-2];
    v0187 = qcar(v0229);
    v0229 = elt(env, 1); /* flagop */
    v0229 = Lflagp(nil, v0187, v0229);
    env = stack[-4];
    if (v0229 == nil) goto v0073;
    v0229 = stack[-2];
    v0229 = qcdr(v0229);
    fn = elt(env, 8); /* idlistp */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-4];
    if (v0229 == nil) goto v0123;
    stack[-3] = elt(env, 7); /* flag */
    stack[0] = elt(env, 2); /* list */
    v0229 = stack[-2];
    v0219 = qcdr(v0229);
    v0187 = stack[-1];
    v0229 = elt(env, 4); /* algebraic */
    fn = elt(env, 9); /* formlis */
    v0229 = (*qfnn(fn))(qenv(fn), 3, v0219, v0187, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-4];
    stack[0] = cons(stack[0], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-4];
    v0229 = stack[-2];
    v0229 = qcar(v0229);
    v0229 = Lmkquote(nil, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    {
        Lisp_Object v0230 = stack[-3];
        Lisp_Object v0231 = stack[0];
        popv(5);
        return list3(v0230, v0231, v0229);
    }

v0123:
    v0187 = elt(env, 5); /* !*comma!* */
    v0229 = stack[-2];
    v0229 = qcdr(v0229);
    v0187 = cons(v0187, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-4];
    v0229 = elt(env, 6); /* "identifier list" */
    {
        popv(5);
        fn = elt(env, 10); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0187, v0229);
    }

v0073:
    v0229 = stack[-2];
    stack[-3] = qcar(v0229);
    stack[0] = elt(env, 2); /* list */
    v0229 = stack[-2];
    v0187 = qcar(v0229);
    v0229 = elt(env, 3); /* share */
    if (v0187 == v0229) goto v0033;
    v0229 = stack[-2];
    v0219 = qcdr(v0229);
    v0187 = stack[-1];
    v0229 = elt(env, 4); /* algebraic */
    fn = elt(env, 9); /* formlis */
    v0229 = (*qfnn(fn))(qenv(fn), 3, v0219, v0187, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-4];
    goto v0071;

v0071:
    v0229 = cons(stack[0], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    {
        Lisp_Object v0116 = stack[-3];
        popv(5);
        return list2(v0116, v0229);
    }

v0033:
    stack[-1] = nil;
    v0229 = stack[-2];
    v0229 = qcdr(v0229);
    stack[-2] = v0229;
    goto v0106;

v0106:
    v0229 = stack[-2];
    if (v0229 == nil) goto v0077;
    v0229 = stack[-2];
    v0229 = qcar(v0229);
    v0187 = Lmkquote(nil, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-4];
    v0229 = stack[-1];
    v0229 = cons(v0187, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-4];
    stack[-1] = v0229;
    v0229 = stack[-2];
    v0229 = qcdr(v0229);
    stack[-2] = v0229;
    goto v0106;

v0077:
    v0229 = stack[-1];
    fn = elt(env, 11); /* reversip!* */
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-4];
    goto v0071;
/* error exit handlers */
v0055:
    popv(5);
    return nil;
}



/* Code for rootextractf */

static Lisp_Object CC_rootextractf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0247, v0248, v0151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rootextractf");
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
/* copy arguments values to proper place */
    stack[-3] = v0000;
/* end of prologue */
    v0247 = stack[-3];
    if (!consp(v0247)) goto v0006;
    v0247 = stack[-3];
    v0247 = qcar(v0247);
    v0247 = (consp(v0247) ? nil : lisp_true);
    goto v0102;

v0102:
    if (!(v0247 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0247 = stack[-3];
    v0247 = qcar(v0247);
    v0247 = qcar(v0247);
    v0247 = qcar(v0247);
    stack[-4] = v0247;
    v0247 = stack[-3];
    v0247 = qcar(v0247);
    v0247 = qcar(v0247);
    v0247 = qcdr(v0247);
    stack[0] = v0247;
    v0247 = stack[-3];
    v0247 = qcdr(v0247);
    v0247 = CC_rootextractf(env, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-5];
    stack[-2] = v0247;
    v0247 = stack[-3];
    v0247 = qcar(v0247);
    v0247 = qcdr(v0247);
    v0247 = CC_rootextractf(env, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-5];
    stack[-1] = v0247;
    v0247 = stack[-1];
    if (v0247 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v0247 = stack[-4];
    if (!consp(v0247)) goto v0105;
    v0247 = stack[-4];
    v0248 = qcar(v0247);
    v0247 = elt(env, 2); /* sqrt */
    if (v0248 == v0247) goto v0013;
    v0247 = stack[-4];
    v0248 = qcar(v0247);
    v0247 = elt(env, 3); /* expt */
    if (v0248 == v0247) goto v0103;
    v0247 = qvalue(elt(env, 5)); /* nil */
    goto v0012;

v0012:
    if (v0247 == nil) goto v0250;
    v0151 = stack[0];
    v0247 = stack[-4];
    v0248 = qcar(v0247);
    v0247 = elt(env, 2); /* sqrt */
    if (v0248 == v0247) goto v0117;
    v0247 = stack[-4];
    v0247 = qcdr(v0247);
    v0247 = qcdr(v0247);
    v0247 = qcar(v0247);
    v0247 = qcdr(v0247);
    v0247 = qcdr(v0247);
    v0247 = qcar(v0247);
    goto v0055;

v0055:
    v0247 = Ldivide(nil, v0151, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-5];
    stack[0] = v0247;
    v0247 = stack[0];
    v0248 = qcar(v0247);
    v0247 = (Lisp_Object)1; /* 0 */
    if (v0248 == v0247) goto v0049;
    v0247 = stack[-4];
    v0247 = qcdr(v0247);
    v0247 = qcar(v0247);
    if (is_number(v0247)) goto v0036;
    v0247 = stack[-4];
    v0247 = qcdr(v0247);
    v0248 = qcar(v0247);
    v0247 = stack[0];
    v0247 = qcar(v0247);
    v0247 = list2(v0248, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-5];
    fn = elt(env, 6); /* simpexpt */
    v0247 = (*qfn1(fn))(qenv(fn), v0247);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-5];
    v0151 = v0247;
    v0247 = v0151;
    v0248 = qcdr(v0247);
    v0247 = (Lisp_Object)17; /* 1 */
    if (v0248 == v0247) goto v0251;
    v0247 = stack[-3];
    v0247 = qcar(v0247);
    v0247 = qcar(v0247);
    v0247 = qcdr(v0247);
    stack[0] = v0247;
    goto v0250;

v0250:
    v0248 = stack[0];
    v0247 = (Lisp_Object)1; /* 0 */
    if (v0248 == v0247) goto v0252;
    v0247 = stack[-1];
    if (v0247 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v0248 = stack[-4];
    v0247 = stack[0];
    fn = elt(env, 7); /* to */
    v0151 = (*qfn2(fn))(qenv(fn), v0248, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    v0248 = stack[-1];
    v0247 = stack[-2];
    popv(6);
    return acons(v0151, v0248, v0247);

v0252:
    v0248 = stack[-1];
    v0247 = stack[-2];
    {
        popv(6);
        fn = elt(env, 8); /* addf */
        return (*qfn2(fn))(qenv(fn), v0248, v0247);
    }

v0251:
    v0247 = v0151;
    v0248 = qcar(v0247);
    v0247 = stack[-1];
    fn = elt(env, 9); /* multf */
    v0247 = (*qfn2(fn))(qenv(fn), v0248, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-5];
    stack[-1] = v0247;
    v0247 = stack[0];
    v0247 = qcdr(v0247);
    stack[0] = v0247;
    goto v0250;

v0036:
    v0247 = stack[-4];
    v0247 = qcdr(v0247);
    v0248 = qcar(v0247);
    v0247 = stack[0];
    v0247 = qcar(v0247);
    v0248 = Lexpt(nil, v0248, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-5];
    v0247 = stack[-1];
    fn = elt(env, 10); /* multd */
    v0247 = (*qfn2(fn))(qenv(fn), v0248, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-5];
    stack[-1] = v0247;
    v0247 = stack[0];
    v0247 = qcdr(v0247);
    stack[0] = v0247;
    goto v0250;

v0049:
    v0247 = stack[-1];
    if (v0247 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v0247 = stack[-3];
    v0247 = qcar(v0247);
    v0151 = qcar(v0247);
    v0248 = stack[-1];
    v0247 = stack[-2];
    popv(6);
    return acons(v0151, v0248, v0247);

v0117:
    v0247 = (Lisp_Object)33; /* 2 */
    goto v0055;

v0103:
    v0247 = stack[-4];
    v0247 = qcdr(v0247);
    v0247 = qcdr(v0247);
    v0248 = qcar(v0247);
    v0247 = elt(env, 4); /* quotient */
    if (!consp(v0248)) goto v0058;
    v0248 = qcar(v0248);
    if (!(v0248 == v0247)) goto v0058;
    v0247 = stack[-4];
    v0247 = qcdr(v0247);
    v0247 = qcdr(v0247);
    v0247 = qcar(v0247);
    v0247 = qcdr(v0247);
    v0248 = qcar(v0247);
    v0247 = (Lisp_Object)17; /* 1 */
    if (v0248 == v0247) goto v0220;
    v0247 = qvalue(elt(env, 5)); /* nil */
    goto v0012;

v0220:
    v0247 = stack[-4];
    v0247 = qcdr(v0247);
    v0247 = qcdr(v0247);
    v0247 = qcar(v0247);
    v0247 = qcdr(v0247);
    v0247 = qcdr(v0247);
    v0247 = qcar(v0247);
    v0247 = (is_number(v0247) ? lisp_true : nil);
    goto v0012;

v0058:
    v0247 = qvalue(elt(env, 5)); /* nil */
    goto v0012;

v0013:
    v0247 = qvalue(elt(env, 1)); /* t */
    goto v0012;

v0105:
    v0247 = stack[-3];
    v0247 = qcar(v0247);
    v0151 = qcar(v0247);
    v0248 = stack[-1];
    v0247 = stack[-2];
    popv(6);
    return acons(v0151, v0248, v0247);

v0006:
    v0247 = qvalue(elt(env, 1)); /* t */
    goto v0102;
/* error exit handlers */
v0249:
    popv(6);
    return nil;
}



/* Code for dfconst */

static Lisp_Object CC_dfconst(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0016;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dfconst");
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
    v0030 = stack[0];
    v0030 = qcar(v0030);
    if (v0030 == nil) goto v0005;
    v0030 = qvalue(elt(env, 2)); /* zlist */
    fn = elt(env, 3); /* vp2 */
    v0016 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-1];
    v0030 = stack[0];
    v0030 = cons(v0016, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    popv(2);
    return ncons(v0030);

v0005:
    v0030 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0030); }
/* error exit handlers */
v0002:
    popv(2);
    return nil;
}



/* Code for pasf_smordtable */

static Lisp_Object MS_CDECL CC_pasf_smordtable(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0010, Lisp_Object v0133, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0106, v0125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pasf_smordtable");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_smordtable");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0133,v0010,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0009,v0010,v0133);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0133;
    stack[-1] = v0010;
    stack[-2] = v0009;
    stack[-3] = v0000;
/* end of prologue */
    v0125 = stack[-1];
    v0106 = stack[0];
    v0106 = (Lisp_Object)lessp2(v0125, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    v0106 = v0106 ? lisp_true : nil;
    env = stack[-4];
    if (v0106 == nil) goto v0004;
    v0125 = stack[-3];
    v0106 = stack[-2];
    {
        popv(5);
        fn = elt(env, 2); /* pasf_smordtable2 */
        return (*qfn2(fn))(qenv(fn), v0125, v0106);
    }

v0004:
    v0125 = stack[-1];
    v0106 = stack[0];
    v0106 = (Lisp_Object)greaterp2(v0125, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    v0106 = v0106 ? lisp_true : nil;
    env = stack[-4];
    if (v0106 == nil) goto v0098;
    v0125 = stack[-3];
    v0106 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* pasf_smordtable1 */
        return (*qfn2(fn))(qenv(fn), v0125, v0106);
    }

v0098:
    v0106 = elt(env, 1); /* "abused smordtable" */
    v0106 = ncons(v0106);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 4); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0106);
    }
/* error exit handlers */
v0107:
    popv(5);
    return nil;
}



/* Code for containerml */

static Lisp_Object CC_containerml(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0098, v0100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for containerml");
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
    v0100 = stack[0];
    v0098 = elt(env, 1); /* integer_interval */
    if (!(v0100 == v0098)) goto v0093;
    v0098 = elt(env, 2); /* interval */
    stack[0] = v0098;
    goto v0093;

v0093:
    v0098 = elt(env, 3); /* "<" */
    fn = elt(env, 9); /* printout */
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-2];
    v0098 = stack[0];
    v0098 = Lprinc(nil, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-2];
    v0098 = stack[-1];
    v0100 = qcar(v0098);
    v0098 = elt(env, 4); /* "" */
    fn = elt(env, 10); /* attributesml */
    v0098 = (*qfn2(fn))(qenv(fn), v0100, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-2];
    v0098 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 11); /* indent!* */
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-2];
    v0098 = stack[-1];
    v0098 = qcdr(v0098);
    fn = elt(env, 12); /* multi_elem */
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-2];
    v0098 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 11); /* indent!* */
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-2];
    v0098 = elt(env, 7); /* "</" */
    fn = elt(env, 9); /* printout */
    v0098 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-2];
    v0098 = stack[0];
    v0098 = Lprinc(nil, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-2];
    v0098 = elt(env, 8); /* ">" */
    v0098 = Lprinc(nil, v0098);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    v0098 = nil;
    { popv(3); return onevalue(v0098); }
/* error exit handlers */
v0214:
    popv(3);
    return nil;
}



/* Code for dm!-mkfloat */

static Lisp_Object CC_dmKmkfloat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0030;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dm-mkfloat");
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
    v0031 = v0000;
/* end of prologue */
    v0030 = v0031;
    v0030 = Lintegerp(nil, v0030);
    env = stack[0];
    if (v0030 == nil) { popv(1); return onevalue(v0031); }
    v0030 = elt(env, 1); /* !:rd!: */
    if (!symbolp(v0030)) v0030 = nil;
    else { v0030 = qfastgets(v0030);
           if (v0030 != nil) { v0030 = elt(v0030, 34); /* i2d */
#ifdef RECORD_GET
             if (v0030 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0030 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0030 == SPID_NOPROP) v0030 = nil; }}
#endif
        popv(1);
        return Lapply1(nil, v0030, v0031);
}



/* Code for s!-nextarg */

static Lisp_Object CC_sKnextarg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0074, v0075, v0076;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for s-nextarg");
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
    v0074 = qvalue(elt(env, 1)); /* !*udebug */
    if (v0074 == nil) goto v0102;
    v0074 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 13); /* uprint */
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-2];
    goto v0102;

v0102:
    v0074 = qvalue(elt(env, 3)); /* comb */
    if (!(v0074 == nil)) goto v0003;
    v0074 = qvalue(elt(env, 4)); /* i */
    v0074 = add1(v0074);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0074; /* i */
    v0074 = stack[0];
    fn = elt(env, 14); /* initcomb */
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-2];
    qvalue(elt(env, 3)) = v0074; /* comb */
    goto v0003;

v0003:
    v0075 = stack[0];
    v0074 = qvalue(elt(env, 3)); /* comb */
    fn = elt(env, 15); /* getcomb */
    v0074 = (*qfn2(fn))(qenv(fn), v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-2];
    stack[-1] = v0074;
    if (v0074 == nil) goto v0259;
    v0075 = qvalue(elt(env, 4)); /* i */
    v0074 = (Lisp_Object)17; /* 1 */
    if (v0075 == v0074) goto v0068;
    v0074 = qvalue(elt(env, 2)); /* nil */
    goto v0017;

v0017:
    if (v0074 == nil) goto v0081;
    v0074 = stack[-1];
    v0074 = qcar(v0074);
    v0075 = qcar(v0074);
    v0074 = stack[-1];
    v0074 = qcdr(v0074);
    popv(3);
    return cons(v0075, v0074);

v0081:
    v0075 = qvalue(elt(env, 4)); /* i */
    v0074 = (Lisp_Object)1; /* 0 */
    if (v0075 == v0074) goto v0226;
    v0074 = qvalue(elt(env, 2)); /* nil */
    goto v0184;

v0184:
    if (v0074 == nil) goto v0065;
    v0075 = elt(env, 6); /* (null!-fn) */
    v0074 = stack[0];
    popv(3);
    return cons(v0075, v0074);

v0065:
    v0074 = qvalue(elt(env, 7)); /* acontract */
    if (v0074 == nil) goto v0104;
    v0075 = qvalue(elt(env, 4)); /* i */
    v0074 = qvalue(elt(env, 5)); /* upb */
    v0074 = (Lisp_Object)lesseq2(v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    v0074 = v0074 ? lisp_true : nil;
    env = stack[-2];
    if (v0074 == nil) goto v0104;
    v0076 = qvalue(elt(env, 8)); /* op */
    v0074 = stack[-1];
    v0075 = qcar(v0074);
    v0074 = stack[-1];
    v0074 = qcdr(v0074);
    v0074 = acons(v0076, v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 16); /* mval */
        return (*qfn1(fn))(qenv(fn), v0074);
    }

v0104:
    v0074 = qvalue(elt(env, 9)); /* mcontract */
    if (v0074 == nil) goto v0260;
    v0075 = qvalue(elt(env, 4)); /* i */
    v0074 = qvalue(elt(env, 5)); /* upb */
    v0074 = (Lisp_Object)lesseq2(v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    v0074 = v0074 ? lisp_true : nil;
    env = stack[-2];
    if (v0074 == nil) goto v0260;
    v0076 = elt(env, 10); /* null!-fn */
    v0074 = stack[-1];
    v0075 = qcar(v0074);
    v0074 = stack[-1];
    v0074 = qcdr(v0074);
    popv(3);
    return acons(v0076, v0075, v0074);

v0260:
    v0074 = qvalue(elt(env, 11)); /* expand */
    if (v0074 == nil) goto v0261;
    v0074 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 11)) = v0074; /* expand */
    v0075 = qvalue(elt(env, 12)); /* identity */
    v0074 = stack[0];
    popv(3);
    return cons(v0075, v0074);

v0261:
    v0074 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0074); }

v0226:
    v0075 = qvalue(elt(env, 4)); /* i */
    v0074 = qvalue(elt(env, 5)); /* upb */
    v0074 = (Lisp_Object)lesseq2(v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    v0074 = v0074 ? lisp_true : nil;
    env = stack[-2];
    goto v0184;

v0068:
    v0075 = qvalue(elt(env, 4)); /* i */
    v0074 = qvalue(elt(env, 5)); /* upb */
    v0074 = (Lisp_Object)lesseq2(v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    v0074 = v0074 ? lisp_true : nil;
    env = stack[-2];
    goto v0017;

v0259:
    v0075 = qvalue(elt(env, 4)); /* i */
    v0074 = (Lisp_Object)1; /* 0 */
    if (v0075 == v0074) goto v0189;
    v0074 = qvalue(elt(env, 2)); /* nil */
    goto v0262;

v0262:
    if (v0074 == nil) goto v0049;
    v0075 = elt(env, 6); /* (null!-fn) */
    v0074 = stack[0];
    popv(3);
    return cons(v0075, v0074);

v0049:
    v0074 = qvalue(elt(env, 11)); /* expand */
    if (v0074 == nil) goto v0191;
    v0074 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 11)) = v0074; /* expand */
    v0075 = qvalue(elt(env, 12)); /* identity */
    v0074 = stack[0];
    popv(3);
    return cons(v0075, v0074);

v0191:
    v0074 = nil;
    { popv(3); return onevalue(v0074); }

v0189:
    v0075 = qvalue(elt(env, 4)); /* i */
    v0074 = qvalue(elt(env, 5)); /* upb */
    v0074 = (Lisp_Object)lesseq2(v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    v0074 = v0074 ? lisp_true : nil;
    env = stack[-2];
    goto v0262;
/* error exit handlers */
v0258:
    popv(3);
    return nil;
}



/* Code for xlcm */

static Lisp_Object CC_xlcm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0060;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xlcm");
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
    stack[-2] = nil;
    goto v0093;

v0093:
    v0059 = stack[-1];
    if (v0059 == nil) goto v0032;
    v0059 = stack[-1];
    v0060 = qcar(v0059);
    v0059 = (Lisp_Object)17; /* 1 */
    v0059 = (v0060 == v0059 ? lisp_true : nil);
    goto v0011;

v0011:
    if (v0059 == nil) goto v0086;
    v0060 = stack[-2];
    v0059 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0060, v0059);
    }

v0086:
    v0059 = stack[0];
    if (v0059 == nil) goto v0018;
    v0059 = stack[0];
    v0060 = qcar(v0059);
    v0059 = (Lisp_Object)17; /* 1 */
    v0059 = (v0060 == v0059 ? lisp_true : nil);
    goto v0017;

v0017:
    if (v0059 == nil) goto v0126;
    v0060 = stack[-2];
    v0059 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0060, v0059);
    }

v0126:
    v0059 = stack[-1];
    v0060 = qcar(v0059);
    v0059 = stack[0];
    v0059 = qcar(v0059);
    if (v0060 == v0059) goto v0092;
    v0059 = stack[-1];
    v0060 = qcar(v0059);
    v0059 = stack[0];
    v0059 = qcar(v0059);
    fn = elt(env, 3); /* factorordp */
    v0059 = (*qfn2(fn))(qenv(fn), v0060, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-3];
    if (v0059 == nil) goto v0109;
    v0059 = stack[-1];
    v0060 = qcar(v0059);
    v0059 = stack[-2];
    v0059 = cons(v0060, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-3];
    stack[-2] = v0059;
    v0059 = stack[-1];
    v0059 = qcdr(v0059);
    stack[-1] = v0059;
    goto v0093;

v0109:
    v0059 = stack[0];
    v0060 = qcar(v0059);
    v0059 = stack[-2];
    v0059 = cons(v0060, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-3];
    stack[-2] = v0059;
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    stack[0] = v0059;
    goto v0093;

v0092:
    v0059 = stack[-1];
    v0060 = qcar(v0059);
    v0059 = stack[-2];
    v0059 = cons(v0060, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-3];
    stack[-2] = v0059;
    v0059 = stack[-1];
    v0059 = qcdr(v0059);
    stack[-1] = v0059;
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    stack[0] = v0059;
    goto v0093;

v0018:
    v0059 = qvalue(elt(env, 1)); /* t */
    goto v0017;

v0032:
    v0059 = qvalue(elt(env, 1)); /* t */
    goto v0011;
/* error exit handlers */
v0119:
    popv(4);
    return nil;
}



/* Code for !*xadd */

static Lisp_Object CC_Hxadd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0077, v0107, v0223, v0257;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *xadd");
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
    v0257 = v0009;
    stack[0] = v0000;
/* end of prologue */
    v0077 = v0257;
    v0223 = v0077;
    goto v0090;

v0090:
    v0077 = v0223;
    if (v0077 == nil) goto v0006;
    v0077 = stack[0];
    v0107 = qcar(v0077);
    v0077 = v0223;
    v0077 = qcar(v0077);
    v0077 = qcar(v0077);
    if (equal(v0107, v0077)) goto v0006;
    v0077 = v0223;
    v0077 = qcdr(v0077);
    v0223 = v0077;
    goto v0090;

v0006:
    v0077 = v0223;
    if (v0077 == nil) goto v0099;
    v0077 = v0223;
    v0077 = qcar(v0077);
    v0107 = v0257;
    v0077 = Ldelete(nil, v0077, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    v0257 = v0077;
    goto v0099;

v0099:
    v0077 = stack[0];
    v0107 = v0257;
    popv(1);
    return cons(v0077, v0107);
/* error exit handlers */
v0089:
    popv(1);
    return nil;
}



/* Code for one!-entryp */

static Lisp_Object CC_oneKentryp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0099, v0207;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for one-entryp");
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

v0028:
    v0099 = stack[0];
    if (!consp(v0099)) goto v0006;
    v0207 = stack[-1];
    v0099 = stack[0];
    v0099 = qcar(v0099);
    v0099 = Lsmemq(nil, v0207, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    if (v0099 == nil) goto v0070;
    v0207 = stack[-1];
    v0099 = stack[0];
    v0099 = qcdr(v0099);
    v0099 = Lsmemq(nil, v0207, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-2];
    if (v0099 == nil) goto v0127;
    v0099 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0099); }

v0127:
    v0099 = stack[0];
    v0099 = qcar(v0099);
    stack[0] = v0099;
    goto v0028;

v0070:
    v0099 = stack[0];
    v0099 = qcdr(v0099);
    stack[0] = v0099;
    goto v0028;

v0006:
    v0099 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0099); }
/* error exit handlers */
v0125:
    popv(3);
    return nil;
}



/* Code for lastcar */

static Lisp_Object CC_lastcar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0016;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lastcar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0030 = v0000;
/* end of prologue */

v0005:
    v0016 = v0030;
    if (v0016 == nil) goto v0102;
    v0016 = v0030;
    v0016 = qcdr(v0016);
    if (v0016 == nil) goto v0087;
    v0030 = qcdr(v0030);
    goto v0005;

v0087:
    v0030 = qcar(v0030);
    return onevalue(v0030);

v0102:
    v0030 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0030);
}



/* Code for insert */

static Lisp_Object CC_insert(Lisp_Object env,
                         Lisp_Object v0009, Lisp_Object v0010)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0066, v0067;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for insert");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0010,v0009);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0009,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0066 = v0010;
    stack[-1] = v0009;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* gg!* */
    qvalue(elt(env, 1)) = nil; /* gg!* */
    qvalue(elt(env, 1)) = v0066; /* gg!* */
    stack[0] = nil;
    goto v0032;

v0032:
    v0066 = qvalue(elt(env, 1)); /* gg!* */
    if (v0066 == nil) goto v0099;
    v0066 = stack[-1];
    v0067 = qcdr(v0066);
    v0066 = qvalue(elt(env, 1)); /* gg!* */
    v0066 = qcar(v0066);
    v0066 = qcdr(v0066);
    fn = elt(env, 3); /* dless */
    v0066 = (*qfn2(fn))(qenv(fn), v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    if (v0066 == nil) goto v0099;
    v0066 = qvalue(elt(env, 1)); /* gg!* */
    v0067 = qcar(v0066);
    v0066 = stack[0];
    v0066 = cons(v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    stack[0] = v0066;
    v0066 = qvalue(elt(env, 1)); /* gg!* */
    v0066 = qcdr(v0066);
    qvalue(elt(env, 1)) = v0066; /* gg!* */
    goto v0032;

v0099:
    v0066 = stack[0];
    stack[0] = Lnreverse(nil, v0066);
    env = stack[-3];
    v0067 = stack[-1];
    v0066 = qvalue(elt(env, 1)); /* gg!* */
    v0066 = cons(v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    v0066 = Lappend(nil, stack[0], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* gg!* */
    { popv(4); return onevalue(v0066); }
/* error exit handlers */
v0126:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* gg!* */
    popv(4);
    return nil;
}



/* Code for plusdf */

static Lisp_Object CC_plusdf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0263, v0083;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for plusdf");
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
    goto v0093;

v0093:
    v0058 = stack[-2];
    if (v0058 == nil) goto v0032;
    v0058 = stack[-1];
    if (v0058 == nil) goto v0002;
    v0058 = stack[-2];
    v0058 = qcar(v0058);
    v0263 = qcar(v0058);
    v0058 = stack[-1];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    if (equal(v0263, v0058)) goto v0099;
    v0058 = stack[-2];
    v0058 = qcar(v0058);
    v0263 = qcar(v0058);
    v0058 = stack[-1];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    fn = elt(env, 1); /* orddf */
    v0058 = (*qfn2(fn))(qenv(fn), v0263, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    if (v0058 == nil) goto v0228;
    v0058 = stack[-2];
    v0263 = qcar(v0058);
    v0058 = stack[0];
    v0058 = cons(v0263, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    stack[0] = v0058;
    v0058 = stack[-2];
    v0058 = qcdr(v0058);
    stack[-2] = v0058;
    goto v0093;

v0228:
    v0058 = stack[-1];
    v0263 = qcar(v0058);
    v0058 = stack[0];
    v0058 = cons(v0263, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    stack[0] = v0058;
    v0058 = stack[-1];
    v0058 = qcdr(v0058);
    stack[-1] = v0058;
    goto v0093;

v0099:
    stack[-3] = stack[0];
    v0058 = stack[-2];
    v0058 = qcar(v0058);
    v0263 = qcdr(v0058);
    v0058 = stack[-1];
    v0058 = qcar(v0058);
    v0058 = qcdr(v0058);
    fn = elt(env, 2); /* !*addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v0263, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    v0058 = stack[-2];
    v0263 = qcdr(v0058);
    v0058 = stack[-1];
    v0058 = qcdr(v0058);
    v0058 = CC_plusdf(env, v0263, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    v0263 = stack[0];
    v0083 = v0263;
    v0083 = qcar(v0083);
    if (v0083 == nil) goto v0106;
    v0083 = stack[-2];
    v0083 = qcar(v0083);
    v0083 = qcar(v0083);
    v0058 = acons(v0083, v0263, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-4];
    goto v0106;

v0106:
    {
        Lisp_Object v0264 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0264, v0058);
    }

v0002:
    v0263 = stack[0];
    v0058 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0263, v0058);
    }

v0032:
    v0263 = stack[0];
    v0058 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0263, v0058);
    }
/* error exit handlers */
v0054:
    popv(5);
    return nil;
}



/* Code for qqe_prepat */

static Lisp_Object CC_qqe_prepat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0133;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_prepat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0133 = v0000;
/* end of prologue */
    return onevalue(v0133);
}



/* Code for pasf_sisub */

static Lisp_Object MS_CDECL CC_pasf_sisub(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0009,
                         Lisp_Object v0010, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0298, v0299, v0300, v0301, v0302, v0303;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pasf_sisub");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_sisub");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0009,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0009,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0010;
    stack[-5] = v0009;
    stack[-1] = v0000;
/* end of prologue */
    v0298 = stack[-1];
    if (!consp(v0298)) goto v0090;
    v0298 = stack[-1];
    v0298 = qcar(v0298);
    goto v0006;

v0006:
    stack[-6] = v0298;
    v0299 = stack[-6];
    v0298 = elt(env, 1); /* ex */
    if (v0299 == v0298) goto v0001;
    v0299 = stack[-6];
    v0298 = elt(env, 3); /* all */
    v0298 = (v0299 == v0298 ? lisp_true : nil);
    goto v0016;

v0016:
    if (v0298 == nil) goto v0081;
    stack[-2] = stack[-6];
    v0298 = stack[-1];
    v0298 = qcdr(v0298);
    stack[0] = qcar(v0298);
    v0298 = stack[-1];
    v0298 = qcdr(v0298);
    v0298 = qcdr(v0298);
    v0300 = qcar(v0298);
    v0299 = stack[-5];
    v0298 = stack[-4];
    v0298 = CC_pasf_sisub(env, 3, v0300, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    {
        Lisp_Object v0305 = stack[-2];
        Lisp_Object v0306 = stack[0];
        popv(8);
        return list3(v0305, v0306, v0298);
    }

v0081:
    v0299 = stack[-6];
    v0298 = elt(env, 4); /* bex */
    if (v0299 == v0298) goto v0092;
    v0299 = stack[-6];
    v0298 = elt(env, 5); /* ball */
    v0298 = (v0299 == v0298 ? lisp_true : nil);
    goto v0184;

v0184:
    if (v0298 == nil) goto v0054;
    stack[-3] = stack[-6];
    v0298 = stack[-1];
    v0298 = qcdr(v0298);
    stack[-2] = qcar(v0298);
    v0298 = stack[-1];
    v0298 = qcdr(v0298);
    v0298 = qcdr(v0298);
    v0300 = qcar(v0298);
    v0299 = stack[-5];
    v0298 = stack[-4];
    stack[0] = CC_pasf_sisub(env, 3, v0300, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-7];
    v0298 = stack[-1];
    v0298 = qcdr(v0298);
    v0298 = qcdr(v0298);
    v0298 = qcdr(v0298);
    v0300 = qcar(v0298);
    v0299 = stack[-5];
    v0298 = stack[-4];
    v0298 = CC_pasf_sisub(env, 3, v0300, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    {
        Lisp_Object v0307 = stack[-3];
        Lisp_Object v0308 = stack[-2];
        Lisp_Object v0309 = stack[0];
        popv(8);
        return list4(v0307, v0308, v0309, v0298);
    }

v0054:
    v0299 = stack[-6];
    v0298 = elt(env, 6); /* and */
    if (v0299 == v0298) goto v0117;
    v0299 = stack[-6];
    v0298 = elt(env, 9); /* or */
    if (v0299 == v0298) goto v0254;
    v0299 = stack[-6];
    v0298 = elt(env, 9); /* or */
    if (v0299 == v0298) goto v0074;
    v0299 = stack[-6];
    v0298 = elt(env, 6); /* and */
    v0298 = (v0299 == v0298 ? lisp_true : nil);
    goto v0036;

v0036:
    if (v0298 == nil) goto v0241;
    v0298 = qvalue(elt(env, 2)); /* t */
    goto v0310;

v0310:
    if (v0298 == nil) goto v0160;
    v0298 = qvalue(elt(env, 2)); /* t */
    goto v0311;

v0311:
    if (v0298 == nil) goto v0312;
    v0298 = stack[-1];
    v0298 = qcdr(v0298);
    stack[-3] = v0298;
    v0298 = stack[-3];
    if (v0298 == nil) goto v0313;
    v0298 = stack[-3];
    v0298 = qcar(v0298);
    v0300 = v0298;
    v0299 = stack[-5];
    v0298 = stack[-4];
    v0298 = CC_pasf_sisub(env, 3, v0300, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-7];
    v0298 = ncons(v0298);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-7];
    stack[-1] = v0298;
    stack[-2] = v0298;
    goto v0314;

v0314:
    v0298 = stack[-3];
    v0298 = qcdr(v0298);
    stack[-3] = v0298;
    v0298 = stack[-3];
    if (v0298 == nil) goto v0199;
    stack[0] = stack[-1];
    v0298 = stack[-3];
    v0298 = qcar(v0298);
    v0300 = v0298;
    v0299 = stack[-5];
    v0298 = stack[-4];
    v0298 = CC_pasf_sisub(env, 3, v0300, v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-7];
    v0298 = ncons(v0298);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-7];
    v0298 = Lrplacd(nil, stack[0], v0298);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-7];
    v0298 = stack[-1];
    v0298 = qcdr(v0298);
    stack[-1] = v0298;
    goto v0314;

v0199:
    v0298 = stack[-2];
    goto v0192;

v0192:
    v0299 = v0298;
    v0298 = v0299;
    if (v0298 == nil) goto v0315;
    v0298 = v0299;
    v0298 = qcdr(v0298);
    if (v0298 == nil) goto v0315;
    v0298 = stack[-6];
    popv(8);
    return cons(v0298, v0299);

v0315:
    v0298 = v0299;
    if (v0298 == nil) goto v0316;
    v0298 = v0299;
    v0298 = qcar(v0298);
    { popv(8); return onevalue(v0298); }

v0316:
    v0299 = stack[-6];
    v0298 = elt(env, 6); /* and */
    if (v0299 == v0298) goto v0317;
    v0298 = elt(env, 8); /* false */
    { popv(8); return onevalue(v0298); }

v0317:
    v0298 = elt(env, 7); /* true */
    { popv(8); return onevalue(v0298); }

v0313:
    v0298 = qvalue(elt(env, 14)); /* nil */
    goto v0192;

v0312:
    v0299 = stack[-6];
    v0298 = elt(env, 7); /* true */
    if (v0299 == v0298) goto v0318;
    v0299 = stack[-6];
    v0298 = elt(env, 8); /* false */
    v0298 = (v0299 == v0298 ? lisp_true : nil);
    goto v0319;

v0319:
    if (!(v0298 == nil)) { Lisp_Object res = stack[-1]; popv(8); return onevalue(res); }
    v0298 = stack[-1];
    stack[0] = qcar(v0298);
    v0298 = stack[-1];
    v0298 = qcdr(v0298);
    stack[-1] = qcar(v0298);
    v0299 = stack[-5];
    v0298 = stack[-4];
    v0298 = cons(v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-7];
    v0298 = ncons(v0298);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-7];
    fn = elt(env, 15); /* subf */
    v0298 = (*qfn2(fn))(qenv(fn), stack[-1], v0298);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-7];
    v0299 = qcar(v0298);
    v0298 = qvalue(elt(env, 14)); /* nil */
    v0299 = list3(stack[0], v0299, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-7];
    v0298 = stack[-6];
    {
        popv(8);
        fn = elt(env, 16); /* pasf_simplat1 */
        return (*qfn2(fn))(qenv(fn), v0299, v0298);
    }

v0318:
    v0298 = qvalue(elt(env, 2)); /* t */
    goto v0319;

v0160:
    v0299 = stack[-6];
    v0298 = elt(env, 11); /* impl */
    if (v0299 == v0298) goto v0240;
    v0299 = stack[-6];
    v0298 = elt(env, 12); /* repl */
    if (v0299 == v0298) goto v0320;
    v0299 = stack[-6];
    v0298 = elt(env, 13); /* equiv */
    v0298 = (v0299 == v0298 ? lisp_true : nil);
    goto v0311;

v0320:
    v0298 = qvalue(elt(env, 2)); /* t */
    goto v0311;

v0240:
    v0298 = qvalue(elt(env, 2)); /* t */
    goto v0311;

v0241:
    v0299 = stack[-6];
    v0298 = elt(env, 10); /* not */
    v0298 = (v0299 == v0298 ? lisp_true : nil);
    goto v0310;

v0074:
    v0298 = qvalue(elt(env, 2)); /* t */
    goto v0036;

v0254:
    v0303 = elt(env, 9); /* or */
    v0298 = stack[-1];
    v0302 = qcdr(v0298);
    v0301 = stack[-5];
    v0300 = stack[-4];
    v0299 = elt(env, 8); /* false */
    v0298 = elt(env, 7); /* true */
    {
        popv(8);
        fn = elt(env, 17); /* pasf_sisub!-gand */
        return (*qfnn(fn))(qenv(fn), 6, v0303, v0302, v0301, v0300, v0299, v0298);
    }

v0117:
    v0303 = elt(env, 6); /* and */
    v0298 = stack[-1];
    v0302 = qcdr(v0298);
    v0301 = stack[-5];
    v0300 = stack[-4];
    v0299 = elt(env, 7); /* true */
    v0298 = elt(env, 8); /* false */
    {
        popv(8);
        fn = elt(env, 17); /* pasf_sisub!-gand */
        return (*qfnn(fn))(qenv(fn), 6, v0303, v0302, v0301, v0300, v0299, v0298);
    }

v0092:
    v0298 = qvalue(elt(env, 2)); /* t */
    goto v0184;

v0001:
    v0298 = qvalue(elt(env, 2)); /* t */
    goto v0016;

v0090:
    v0298 = stack[-1];
    goto v0006;
/* error exit handlers */
v0304:
    popv(8);
    return nil;
}



/* Code for lto_setminus */

static Lisp_Object CC_lto_setminus(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0009)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0081, v0213, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lto_setminus");
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
    stack[-3] = v0009;
    v0081 = v0000;
/* end of prologue */
    stack[-4] = v0081;
    goto v0006;

v0006:
    v0081 = stack[-4];
    if (v0081 == nil) goto v0032;
    v0081 = stack[-4];
    v0081 = qcar(v0081);
    v0026 = v0081;
    v0213 = v0026;
    v0081 = stack[-3];
    v0081 = Lmember(nil, v0213, v0081);
    if (v0081 == nil) goto v0016;
    v0081 = nil;
    goto v0030;

v0030:
    stack[-2] = v0081;
    v0081 = stack[-2];
    fn = elt(env, 2); /* lastpair */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    stack[-1] = v0081;
    v0081 = stack[-4];
    v0081 = qcdr(v0081);
    stack[-4] = v0081;
    v0081 = stack[-1];
    if (!consp(v0081)) goto v0006;
    else goto v0090;

v0090:
    v0081 = stack[-4];
    if (v0081 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0081 = stack[-4];
    v0081 = qcar(v0081);
    v0026 = v0081;
    v0213 = v0026;
    v0081 = stack[-3];
    v0081 = Lmember(nil, v0213, v0081);
    if (v0081 == nil) goto v0067;
    v0081 = nil;
    goto v0077;

v0077:
    v0081 = Lrplacd(nil, stack[0], v0081);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    v0081 = stack[-1];
    fn = elt(env, 2); /* lastpair */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    stack[-1] = v0081;
    v0081 = stack[-4];
    v0081 = qcdr(v0081);
    stack[-4] = v0081;
    goto v0090;

v0067:
    v0081 = v0026;
    v0081 = ncons(v0081);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    goto v0077;

v0016:
    v0081 = v0026;
    v0081 = ncons(v0081);
    nil = C_nil;
    if (exception_pending()) goto v0226;
    env = stack[-5];
    goto v0030;

v0032:
    v0081 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0081); }
/* error exit handlers */
v0226:
    popv(6);
    return nil;
}



setup_type const u22_setup[] =
{
    {":dmtimeslst",             CC_Tdmtimeslst, too_many_1,    wrong_no_1},
    {"formde",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_formde},
    {"mv-domainlist",           CC_mvKdomainlist,too_many_1,   wrong_no_1},
    {"dv_ind2var",              CC_dv_ind2var,  too_many_1,    wrong_no_1},
    {":expt",                   too_few_2,      CC_Texpt,      wrong_no_2},
    {"bndtst",                  CC_bndtst,      too_many_1,    wrong_no_1},
    {"n_nary",                  too_few_2,      CC_n_nary,     wrong_no_2},
    {"recaliasbacksubst",       too_few_2,      CC_recaliasbacksubst,wrong_no_2},
    {"make-unique-freevars",    CC_makeKuniqueKfreevars,too_many_1,wrong_no_1},
    {"noncomexpf",              CC_noncomexpf,  too_many_1,    wrong_no_1},
    {"my_letmtr",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_my_letmtr},
    {"nconc2",                  too_few_2,      CC_nconc2,     wrong_no_2},
    {"fortexp",                 CC_fortexp,     too_many_1,    wrong_no_1},
    {"physopsimp",              CC_physopsimp,  too_many_1,    wrong_no_1},
    {"mk-strand-vertex2",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkKstrandKvertex2},
    {"assert_stat1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_stat1},
    {"aex_freeidl",             CC_aex_freeidl, too_many_1,    wrong_no_1},
    {"matrix_rows",             CC_matrix_rows, too_many_1,    wrong_no_1},
    {"convprc2",                too_few_2,      CC_convprc2,   wrong_no_2},
    {"edge_new_parents",        CC_edge_new_parents,too_many_1,wrong_no_1},
    {"assert_stat-parse",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_statKparse},
    {"list_is_all_free",        CC_list_is_all_free,too_many_1,wrong_no_1},
    {"subf",                    too_few_2,      CC_subf,       wrong_no_2},
    {"width",                   too_few_2,      CC_width,      wrong_no_2},
    {"matpri",                  CC_matpri,      too_many_1,    wrong_no_1},
    {"qqe_arg-check-lb-rb",     CC_qqe_argKcheckKlbKrb,too_many_1,wrong_no_1},
    {"pasf_floor",              too_few_2,      CC_pasf_floor, wrong_no_2},
    {"evmtest?",                too_few_2,      CC_evmtestW,   wrong_no_2},
    {"gvar1",                   too_few_2,      CC_gvar1,      wrong_no_2},
    {"basisformp",              CC_basisformp,  too_many_1,    wrong_no_1},
    {"getrlist",                CC_getrlist,    too_many_1,    wrong_no_1},
    {"sublap",                  too_few_2,      CC_sublap,     wrong_no_2},
    {"l-subst",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_lKsubst},
    {"formrlis",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formrlis},
    {"rootextractf",            CC_rootextractf,too_many_1,    wrong_no_1},
    {"dfconst",                 CC_dfconst,     too_many_1,    wrong_no_1},
    {"pasf_smordtable",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smordtable},
    {"containerml",             too_few_2,      CC_containerml,wrong_no_2},
    {"dm-mkfloat",              CC_dmKmkfloat,  too_many_1,    wrong_no_1},
    {"s-nextarg",               CC_sKnextarg,   too_many_1,    wrong_no_1},
    {"xlcm",                    too_few_2,      CC_xlcm,       wrong_no_2},
    {"*xadd",                   too_few_2,      CC_Hxadd,      wrong_no_2},
    {"one-entryp",              too_few_2,      CC_oneKentryp, wrong_no_2},
    {"lastcar",                 CC_lastcar,     too_many_1,    wrong_no_1},
    {"insert",                  too_few_2,      CC_insert,     wrong_no_2},
    {"plusdf",                  too_few_2,      CC_plusdf,     wrong_no_2},
    {"qqe_prepat",              CC_qqe_prepat,  too_many_1,    wrong_no_1},
    {"pasf_sisub",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_sisub},
    {"lto_setminus",            too_few_2,      CC_lto_setminus,wrong_no_2},
    {NULL, (one_args *)"u22", (two_args *)"1638 8572664 6271807", 0}
};

/* end of generated code */
