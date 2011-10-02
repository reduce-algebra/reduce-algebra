
/* $destdir\u16.c        Machine generated C code */

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


/* Code for sf2mv1 */

static Lisp_Object MS_CDECL CC_sf2mv1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025, v0026, v0027;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sf2mv1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sf2mv1");
#endif
    if (stack >= stacklimit)
    {
        push3(v0002,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0025 = v0002;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* varlist */
    qvalue(elt(env, 1)) = nil; /* varlist */
    qvalue(elt(env, 1)) = v0025; /* varlist */
    goto v0028;

v0028:
    v0025 = stack[-3];
    if (v0025 == nil) goto v0029;
    v0025 = stack[-3];
    if (!consp(v0025)) goto v0030;
    v0025 = stack[-3];
    v0025 = qcar(v0025);
    v0025 = (consp(v0025) ? nil : lisp_true);
    goto v0031;

v0031:
    if (v0025 == nil) goto v0032;
    stack[0] = stack[-2];
    v0025 = qvalue(elt(env, 1)); /* varlist */
    v0025 = Llength(nil, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    fn = elt(env, 4); /* nzeros */
    v0025 = (*qfn1(fn))(qenv(fn), v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    v0026 = Lappend(nil, stack[0], v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    v0025 = stack[-3];
    v0025 = cons(v0026, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    v0025 = ncons(v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    goto v0034;

v0034:
    qvalue(elt(env, 1)) = stack[-4]; /* varlist */
    { popv(6); return onevalue(v0025); }

v0032:
    v0025 = stack[-3];
    v0025 = qcar(v0025);
    v0025 = qcar(v0025);
    v0026 = qcar(v0025);
    v0025 = qvalue(elt(env, 1)); /* varlist */
    v0025 = qcar(v0025);
    if (equal(v0026, v0025)) goto v0035;
    stack[0] = stack[-2];
    v0025 = (Lisp_Object)1; /* 0 */
    v0025 = ncons(v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    v0025 = Lappend(nil, stack[0], v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    stack[-2] = v0025;
    v0025 = qvalue(elt(env, 1)); /* varlist */
    v0025 = qcdr(v0025);
    qvalue(elt(env, 1)) = v0025; /* varlist */
    goto v0028;

v0035:
    v0025 = stack[-3];
    v0025 = qcar(v0025);
    stack[-1] = qcdr(v0025);
    stack[0] = stack[-2];
    v0025 = stack[-3];
    v0025 = qcar(v0025);
    v0025 = qcar(v0025);
    v0025 = qcdr(v0025);
    v0025 = ncons(v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    v0026 = Lappend(nil, stack[0], v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    v0025 = qvalue(elt(env, 1)); /* varlist */
    v0025 = qcdr(v0025);
    stack[0] = CC_sf2mv1(env, 3, stack[-1], v0026, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    v0025 = stack[-3];
    v0027 = qcdr(v0025);
    v0026 = stack[-2];
    v0025 = qvalue(elt(env, 1)); /* varlist */
    v0025 = CC_sf2mv1(env, 3, v0027, v0026, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    v0025 = Lappend(nil, stack[0], v0025);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-5];
    goto v0034;

v0030:
    v0025 = qvalue(elt(env, 3)); /* t */
    goto v0031;

v0029:
    v0025 = qvalue(elt(env, 2)); /* nil */
    goto v0034;
/* error exit handlers */
v0033:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* varlist */
    popv(6);
    return nil;
}



/* Code for rnminusp!: */

static Lisp_Object CC_rnminuspT(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0044, v0045;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnminusp:");
#endif
    if (stack >= stacklimit)
    {
        push(v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0044 = v0036;
/* end of prologue */
    v0043 = v0044;
    v0043 = qcdr(v0043);
    v0043 = qcar(v0043);
    v0044 = v0043;
    if (!consp(v0043)) goto v0046;
    v0043 = v0044;
    v0045 = qcar(v0043);
    v0043 = elt(env, 1); /* minusp */
    v0043 = get(v0045, v0043);
        return Lapply1(nil, v0043, v0044);

v0046:
    v0043 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v0044, v0043);
}



/* Code for di_restore */

static Lisp_Object CC_di_restore(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for di_restore");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0048 = v0036;
/* end of prologue */
    v0028 = v0048;
    v0048 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* di_restore1 */
        return (*qfn2(fn))(qenv(fn), v0028, v0048);
    }
}



/* Code for resimpf */

static Lisp_Object CC_resimpf(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0029;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resimpf");
#endif
    if (stack >= stacklimit)
    {
        push(v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0029 = v0036;
/* end of prologue */
    v0049 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v0049; /* varstack!* */
    v0049 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* subf1 */
    v0049 = (*qfn2(fn))(qenv(fn), v0029, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    v0049 = qcar(v0049);
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    { popv(2); return onevalue(v0049); }
/* error exit handlers */
v0041:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    popv(2);
    return nil;
}



/* Code for numeric!-content */

static Lisp_Object CC_numericKcontent(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0055, v0056;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numeric-content");
#endif
    if (stack >= stacklimit)
    {
        push(v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
/* end of prologue */

v0057:
    v0035 = stack[0];
    if (!consp(v0035)) goto v0028;
    v0035 = stack[0];
    v0035 = qcar(v0035);
    v0035 = (consp(v0035) ? nil : lisp_true);
    goto v0048;

v0048:
    if (v0035 == nil) goto v0047;
    v0035 = stack[0];
    fn = elt(env, 2); /* minusf */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    if (v0035 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0035 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* negf */
        return (*qfn1(fn))(qenv(fn), v0035);
    }

v0047:
    v0035 = stack[0];
    v0035 = qcdr(v0035);
    if (v0035 == nil) goto v0059;
    v0035 = stack[0];
    v0035 = qcar(v0035);
    v0035 = qcdr(v0035);
    v0035 = CC_numericKcontent(env, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    v0056 = v0035;
    v0055 = v0056;
    v0035 = (Lisp_Object)17; /* 1 */
    if (v0055 == v0035) { popv(3); return onevalue(v0056); }
    stack[-1] = v0056;
    v0035 = stack[0];
    v0035 = qcdr(v0035);
    v0035 = CC_numericKcontent(env, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    fn = elt(env, 4); /* gcddd */
    v0035 = (*qfn2(fn))(qenv(fn), stack[-1], v0035);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    v0056 = v0035;
    { popv(3); return onevalue(v0056); }

v0059:
    v0035 = stack[0];
    v0035 = qcar(v0035);
    v0035 = qcdr(v0035);
    stack[0] = v0035;
    goto v0057;

v0028:
    v0035 = qvalue(elt(env, 1)); /* t */
    goto v0048;
/* error exit handlers */
v0058:
    popv(3);
    return nil;
}



/* Code for cl_identifyat */

static Lisp_Object CC_cl_identifyat(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068, v0053;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_identifyat");
#endif
    if (stack >= stacklimit)
    {
        push(v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
/* end of prologue */
    v0053 = stack[0];
    v0068 = elt(env, 1); /* true */
    if (v0053 == v0068) goto v0028;
    v0053 = stack[0];
    v0068 = elt(env, 3); /* false */
    v0068 = (v0053 == v0068 ? lisp_true : nil);
    goto v0048;

v0048:
    if (!(v0068 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0053 = stack[0];
    v0068 = qvalue(elt(env, 4)); /* cl_identify!-atl!* */
    v0068 = Lmember(nil, v0053, v0068);
    v0053 = v0068;
    if (v0068 == nil) goto v0069;
    v0068 = v0053;
    v0068 = qcar(v0068);
    { popv(2); return onevalue(v0068); }

v0069:
    v0053 = stack[0];
    v0068 = qvalue(elt(env, 4)); /* cl_identify!-atl!* */
    v0068 = cons(v0053, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-1];
    qvalue(elt(env, 4)) = v0068; /* cl_identify!-atl!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0028:
    v0068 = qvalue(elt(env, 2)); /* t */
    goto v0048;
/* error exit handlers */
v0070:
    popv(2);
    return nil;
}



/* Code for evaluatecoeffts */

static Lisp_Object CC_evaluatecoeffts(Lisp_Object env,
                         Lisp_Object v0036, Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0080, v0081;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluatecoeffts");
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0036,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
    stack[-1] = v0036;
/* end of prologue */
    v0079 = stack[-1];
    if (v0079 == nil) goto v0005;
    v0079 = stack[-1];
    if (!consp(v0079)) goto v0082;
    v0079 = stack[-1];
    v0079 = qcar(v0079);
    v0079 = (consp(v0079) ? nil : lisp_true);
    goto v0047;

v0047:
    if (v0079 == nil) goto v0083;
    v0080 = stack[-1];
    v0079 = (Lisp_Object)1; /* 0 */
    if (!(v0080 == v0079)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0079 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0079); }

v0083:
    v0079 = stack[-1];
    v0079 = qcar(v0079);
    v0079 = qcar(v0079);
    v0080 = qcar(v0079);
    v0079 = qvalue(elt(env, 3)); /* indexlist */
    v0079 = Lmember(nil, v0080, v0079);
    if (v0079 == nil) goto v0013;
    v0079 = stack[-1];
    v0079 = qcar(v0079);
    v0079 = qcar(v0079);
    v0081 = qcar(v0079);
    v0080 = stack[0];
    v0079 = qvalue(elt(env, 3)); /* indexlist */
    fn = elt(env, 4); /* valuecoefft */
    v0079 = (*qfnn(fn))(qenv(fn), 3, v0081, v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-3];
    goto v0085;

v0085:
    stack[-2] = v0079;
    v0079 = stack[-1];
    v0079 = qcar(v0079);
    v0080 = qcdr(v0079);
    v0079 = stack[0];
    v0079 = CC_evaluatecoeffts(env, v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-3];
    fn = elt(env, 5); /* !*multf */
    v0079 = (*qfn2(fn))(qenv(fn), stack[-2], v0079);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-3];
    stack[-2] = v0079;
    v0079 = stack[-1];
    v0080 = qcdr(v0079);
    v0079 = stack[0];
    v0079 = CC_evaluatecoeffts(env, v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-3];
    {
        Lisp_Object v0086 = stack[-2];
        popv(4);
        fn = elt(env, 6); /* addf */
        return (*qfn2(fn))(qenv(fn), v0086, v0079);
    }

v0013:
    v0079 = stack[-1];
    v0079 = qcar(v0079);
    v0080 = qcar(v0079);
    v0079 = (Lisp_Object)17; /* 1 */
    v0079 = cons(v0080, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-3];
    v0079 = ncons(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-3];
    goto v0085;

v0082:
    v0079 = qvalue(elt(env, 1)); /* t */
    goto v0047;

v0005:
    v0079 = qvalue(elt(env, 1)); /* t */
    goto v0047;
/* error exit handlers */
v0084:
    popv(4);
    return nil;
}



/* Code for ibalp_readclause */

static Lisp_Object CC_ibalp_readclause(Lisp_Object env,
                         Lisp_Object v0036, Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0120, v0121, v0122, v0123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_readclause");
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0036,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0000;
    v0120 = v0036;
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    v0120 = qcdr(v0120);
    stack[-4] = v0120;
    stack[-5] = qvalue(elt(env, 1)); /* nil */
    stack[-1] = qvalue(elt(env, 1)); /* nil */
    stack[0] = (Lisp_Object)1; /* 0 */
    v0123 = (Lisp_Object)1; /* 0 */
    v0122 = qvalue(elt(env, 1)); /* nil */
    v0121 = qvalue(elt(env, 1)); /* nil */
    v0120 = qvalue(elt(env, 1)); /* nil */
    v0120 = list4(v0123, v0122, v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-9];
    v0120 = list3star(stack[-5], stack[-1], stack[0], v0120);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-9];
    stack[-5] = v0120;
    v0120 = qvalue(elt(env, 2)); /* t */
    stack[-1] = v0120;
    goto v0023;

v0023:
    v0120 = stack[-1];
    if (v0120 == nil) goto v0022;
    v0120 = stack[-4];
    if (v0120 == nil) goto v0022;
    v0120 = stack[-4];
    v0120 = qcar(v0120);
    stack[-8] = v0120;
    v0121 = stack[-8];
    v0120 = elt(env, 3); /* true */
    if (v0121 == v0120) goto v0018;
    v0120 = stack[-4];
    v0120 = qcdr(v0120);
    stack[-4] = v0120;
    v0121 = stack[-8];
    v0120 = elt(env, 4); /* false */
    if (v0121 == v0120) goto v0023;
    v0120 = stack[-8];
    if (!consp(v0120)) goto v0075;
    v0120 = stack[-8];
    v0120 = qcar(v0120);
    v0121 = v0120;
    goto v0125;

v0125:
    v0120 = elt(env, 5); /* not */
    if (v0121 == v0120) goto v0017;
    v0120 = stack[-8];
    fn = elt(env, 6); /* ibalp_arg2l */
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-9];
    stack[-6] = v0120;
    v0120 = stack[-8];
    fn = elt(env, 7); /* ibalp_arg2r */
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-9];
    goto v0126;

v0126:
    v0121 = v0120;
    v0120 = (Lisp_Object)17; /* 1 */
    v0120 = Leqn(nil, v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-9];
    if (v0120 == nil) goto v0127;
    v0121 = stack[-6];
    v0120 = stack[-3];
    v0120 = Lmemq(nil, v0121, v0120);
    if (!(v0120 == nil)) goto v0023;
    v0120 = stack[-5];
    v0120 = qcdr(v0120);
    stack[0] = qcdr(v0120);
    v0120 = stack[-5];
    v0120 = qcdr(v0120);
    v0120 = qcdr(v0120);
    v0120 = qcar(v0120);
    v0120 = add1(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-9];
    fn = elt(env, 8); /* setcar */
    v0120 = (*qfn2(fn))(qenv(fn), stack[0], v0120);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-9];
    v0121 = stack[-6];
    v0120 = stack[-3];
    v0120 = cons(v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-9];
    stack[-3] = v0120;
    v0123 = stack[-5];
    v0122 = stack[-7];
    v0121 = stack[-6];
    v0120 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 9); /* ibalp_process!-var */
    v0120 = (*qfnn(fn))(qenv(fn), 4, v0123, v0122, v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-9];
    stack[-7] = v0120;
    goto v0023;

v0127:
    v0121 = stack[-6];
    v0120 = stack[-2];
    v0120 = Lmemq(nil, v0121, v0120);
    if (!(v0120 == nil)) goto v0023;
    v0120 = stack[-5];
    v0120 = qcdr(v0120);
    v0120 = qcdr(v0120);
    stack[0] = qcdr(v0120);
    v0120 = stack[-5];
    v0120 = qcdr(v0120);
    v0120 = qcdr(v0120);
    v0120 = qcdr(v0120);
    v0120 = qcar(v0120);
    v0120 = add1(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-9];
    fn = elt(env, 8); /* setcar */
    v0120 = (*qfn2(fn))(qenv(fn), stack[0], v0120);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-9];
    v0121 = stack[-6];
    v0120 = stack[-2];
    v0120 = cons(v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-9];
    stack[-2] = v0120;
    v0123 = stack[-5];
    v0122 = stack[-7];
    v0121 = stack[-6];
    v0120 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 9); /* ibalp_process!-var */
    v0120 = (*qfnn(fn))(qenv(fn), 4, v0123, v0122, v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-9];
    stack[-7] = v0120;
    goto v0023;

v0017:
    v0120 = stack[-8];
    v0120 = qcdr(v0120);
    v0120 = qcar(v0120);
    fn = elt(env, 6); /* ibalp_arg2l */
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-9];
    stack[-6] = v0120;
    stack[0] = (Lisp_Object)17; /* 1 */
    v0120 = stack[-8];
    v0120 = qcdr(v0120);
    v0120 = qcar(v0120);
    fn = elt(env, 7); /* ibalp_arg2r */
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0124;
    env = stack[-9];
    v0120 = (Lisp_Object)(int32_t)((int32_t)stack[0] - (int32_t)v0120 + TAG_FIXNUM);
    goto v0126;

v0075:
    v0120 = stack[-8];
    v0121 = v0120;
    goto v0125;

v0018:
    v0120 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v0120;
    goto v0023;

v0022:
    v0120 = stack[-1];
    if (v0120 == nil) goto v0128;
    v0121 = stack[-5];
    v0120 = stack[-7];
    popv(10);
    return cons(v0121, v0120);

v0128:
    v0121 = elt(env, 3); /* true */
    v0120 = stack[-7];
    popv(10);
    return cons(v0121, v0120);
/* error exit handlers */
v0124:
    popv(10);
    return nil;
}



/* Code for ratpoly_1 */

static Lisp_Object MS_CDECL CC_ratpoly_1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ratpoly_1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_1");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0002 = (Lisp_Object)17; /* 1 */
    {
        fn = elt(env, 1); /* simp */
        return (*qfn1(fn))(qenv(fn), v0002);
    }
}



/* Code for mapins */

static Lisp_Object CC_mapins(Lisp_Object env,
                         Lisp_Object v0036, Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0062, v0063;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mapins");
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0036,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
    stack[-1] = v0036;
/* end of prologue */
    stack[-2] = nil;
    goto v0003;

v0003:
    v0052 = stack[0];
    if (v0052 == nil) goto v0005;
    v0062 = stack[-1];
    v0052 = stack[0];
    v0052 = qcar(v0052);
    v0052 = qcar(v0052);
    v0063 = cons(v0062, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-3];
    v0052 = stack[0];
    v0052 = qcar(v0052);
    v0062 = qcdr(v0052);
    v0052 = stack[-2];
    v0052 = acons(v0063, v0062, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-3];
    stack[-2] = v0052;
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    stack[0] = v0052;
    goto v0003;

v0005:
    v0052 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0052);
    }
/* error exit handlers */
v0131:
    popv(4);
    return nil;
}



/* Code for om2mml */

static Lisp_Object MS_CDECL CC_om2mml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "om2mml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for om2mml");
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
    fn = elt(env, 3); /* om2ir */
    v0082 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-1];
    stack[0] = v0082;
    v0082 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 4); /* terpri!* */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-1];
    v0082 = elt(env, 2); /* "Intermediate representation:" */
    v0082 = Lprinc(nil, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-1];
    v0082 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 4); /* terpri!* */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-1];
    v0082 = stack[0];
    v0082 = Lprinc(nil, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-1];
    v0082 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 4); /* terpri!* */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-1];
    v0082 = stack[0];
    fn = elt(env, 5); /* ir2mml */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    v0082 = nil;
    { popv(2); return onevalue(v0082); }
/* error exit handlers */
v0066:
    popv(2);
    return nil;
}



/* Code for resume */

static Lisp_Object CC_resume(Lisp_Object env,
                         Lisp_Object v0036, Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0062, v0063, v0073;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resume");
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0036,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0052 = v0000;
    v0062 = v0036;
/* end of prologue */
    v0063 = v0052;
    if (v0063 == nil) goto v0130;
    v0063 = v0052;
    v0063 = qcar(v0063);
    v0073 = qcar(v0063);
    v0063 = v0052;
    v0063 = qcar(v0063);
    v0063 = qcdr(v0063);
    v0063 = qcar(v0063);
    v0052 = qcdr(v0052);
    {
        popv(1);
        fn = elt(env, 3); /* amatch */
        return (*qfnn(fn))(qenv(fn), 4, v0073, v0063, v0062, v0052);
    }

v0130:
    v0052 = v0062;
    fn = elt(env, 4); /* chk */
    v0062 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[0];
    v0052 = qvalue(elt(env, 1)); /* t */
    if (v0062 == v0052) goto v0064;
    v0052 = nil;
    { popv(1); return onevalue(v0052); }

v0064:
    v0052 = qvalue(elt(env, 2)); /* substitution */
    {
        popv(1);
        fn = elt(env, 5); /* bsubs */
        return (*qfn1(fn))(qenv(fn), v0052);
    }
/* error exit handlers */
v0022:
    popv(1);
    return nil;
}



/* Code for setmat */

static Lisp_Object MS_CDECL CC_setmat(Lisp_Object env, int nargs,
                         Lisp_Object v0036, Lisp_Object v0000,
                         Lisp_Object v0001, Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0077, v0058, v0132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "setmat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setmat");
#endif
    if (stack >= stacklimit)
    {
        push4(v0002,v0001,v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0036,v0000,v0001,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0002;
    stack[-1] = v0001;
    stack[-2] = v0000;
    stack[-3] = v0036;
/* end of prologue */
    v0077 = qvalue(elt(env, 1)); /* !*modular */
    if (v0077 == nil) goto v0003;
    v0077 = elt(env, 2); /* modular */
    v0077 = ncons(v0077);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    fn = elt(env, 6); /* off */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    v0077 = elt(env, 3); /* mod_was_on */
    v0077 = ncons(v0077);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    fn = elt(env, 7); /* on */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    goto v0003;

v0003:
    v0077 = stack[-2];
    v0077 = integerp(v0077);
    if (v0077 == nil) goto v0129;
    v0077 = stack[-2];
    goto v0067;

v0067:
    stack[-2] = v0077;
    v0077 = stack[-1];
    v0077 = integerp(v0077);
    if (v0077 == nil) goto v0043;
    v0077 = stack[-1];
    goto v0065;

v0065:
    stack[-1] = v0077;
    v0132 = stack[-3];
    v0058 = stack[-2];
    v0077 = stack[-1];
    v0132 = list3(v0132, v0058, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    v0058 = stack[0];
    v0077 = stack[-3];
    fn = elt(env, 8); /* my_letmtr */
    v0077 = (*qfnn(fn))(qenv(fn), 3, v0132, v0058, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    v0077 = qvalue(elt(env, 5)); /* !*mod_was_on */
    if (v0077 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v0077 = elt(env, 2); /* modular */
    v0077 = ncons(v0077);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    fn = elt(env, 7); /* on */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    v0077 = elt(env, 3); /* mod_was_on */
    v0077 = ncons(v0077);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    fn = elt(env, 6); /* off */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v0043:
    v0077 = stack[-1];
    fn = elt(env, 9); /* reval */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    goto v0065;

v0129:
    v0077 = stack[-2];
    fn = elt(env, 9); /* reval */
    v0077 = (*qfn1(fn))(qenv(fn), v0077);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    goto v0067;
/* error exit handlers */
v0133:
    popv(5);
    return nil;
}



/* Code for rd!:plus */

static Lisp_Object CC_rdTplus(Lisp_Object env,
                         Lisp_Object v0036, Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0153, v0154, v0093;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:plus");
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0036,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
    stack[0] = v0036;
/* end of prologue */
    v0153 = qvalue(elt(env, 1)); /* nil */
    v0154 = v0153;
    v0153 = qvalue(elt(env, 2)); /* !*!*roundbf */
    if (v0153 == nil) goto v0028;
    v0153 = qvalue(elt(env, 1)); /* nil */
    goto v0048;

v0048:
    if (v0153 == nil) goto v0155;
    v0153 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v0153, v0154);

v0155:
    v0154 = stack[0];
    v0153 = stack[-1];
    fn = elt(env, 8); /* convprc2 */
    v0153 = (*qfn2(fn))(qenv(fn), v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    stack[-3] = v0153;
    v0153 = qvalue(elt(env, 4)); /* yy!! */
    stack[-2] = v0153;
    v0153 = stack[-3];
    if (!consp(v0153)) goto v0014;
    v0154 = stack[-3];
    v0153 = stack[-2];
    fn = elt(env, 9); /* plubf */
    v0153 = (*qfn2(fn))(qenv(fn), v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    goto v0035;

v0035:
    stack[0] = v0153;
    v0093 = stack[0];
    v0154 = stack[-3];
    v0153 = stack[-2];
    fn = elt(env, 10); /* rdzchk */
    v0153 = (*qfnn(fn))(qenv(fn), 3, v0093, v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    v0154 = v0153;
    v0153 = v0154;
    if (!(!consp(v0153))) { popv(5); return onevalue(v0154); }
    v0153 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v0153, v0154);

v0014:
    stack[-1] = elt(env, 5); /* plus2 */
    v0153 = stack[-3];
    stack[0] = Lmkquote(nil, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    v0153 = stack[-2];
    v0153 = Lmkquote(nil, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    v0093 = list3(stack[-1], stack[0], v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    v0154 = qvalue(elt(env, 1)); /* nil */
    v0153 = qvalue(elt(env, 6)); /* !*backtrace */
    fn = elt(env, 11); /* errorset */
    v0153 = (*qfnn(fn))(qenv(fn), 3, v0093, v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    v0154 = v0153;
    v0153 = v0154;
    if (!consp(v0153)) goto v0072;
    v0153 = v0154;
    v0153 = qcdr(v0153);
    goto v0071;

v0071:
    if (v0153 == nil) goto v0157;
    fn = elt(env, 12); /* rndbfon */
    v0153 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    v0153 = stack[-3];
    v0153 = Lfloatp(nil, v0153);
    env = stack[-4];
    if (v0153 == nil) goto v0111;
    v0153 = stack[-3];
    fn = elt(env, 13); /* fl2bf */
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    stack[0] = v0153;
    goto v0086;

v0086:
    stack[-3] = stack[0];
    v0153 = stack[-2];
    v0153 = Lfloatp(nil, v0153);
    env = stack[-4];
    if (v0153 == nil) goto v0158;
    v0153 = stack[-2];
    fn = elt(env, 13); /* fl2bf */
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    goto v0159;

v0159:
    stack[-2] = v0153;
    fn = elt(env, 9); /* plubf */
    v0153 = (*qfn2(fn))(qenv(fn), stack[0], v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    goto v0035;

v0158:
    v0153 = stack[-2];
    if (!consp(v0153)) goto v0160;
    v0153 = stack[-2];
    goto v0161;

v0161:
    fn = elt(env, 14); /* csl_normbf */
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    goto v0159;

v0160:
    v0153 = stack[-2];
    v0153 = integerp(v0153);
    if (v0153 == nil) goto v0162;
    v0093 = elt(env, 3); /* !:rd!: */
    v0154 = stack[-2];
    v0153 = (Lisp_Object)1; /* 0 */
    v0153 = list2star(v0093, v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    goto v0161;

v0162:
    v0153 = stack[-2];
    fn = elt(env, 15); /* read!:num */
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    goto v0161;

v0111:
    v0153 = stack[-3];
    if (!consp(v0153)) goto v0163;
    v0153 = stack[-3];
    goto v0164;

v0164:
    fn = elt(env, 14); /* csl_normbf */
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    stack[0] = v0153;
    goto v0086;

v0163:
    v0153 = stack[-3];
    v0153 = integerp(v0153);
    if (v0153 == nil) goto v0165;
    v0093 = elt(env, 3); /* !:rd!: */
    v0154 = stack[-3];
    v0153 = (Lisp_Object)1; /* 0 */
    v0153 = list2star(v0093, v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    goto v0164;

v0165:
    v0153 = stack[-3];
    fn = elt(env, 15); /* read!:num */
    v0153 = (*qfn1(fn))(qenv(fn), v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    goto v0164;

v0157:
    v0153 = v0154;
    v0153 = qcar(v0153);
    goto v0035;

v0072:
    v0153 = qvalue(elt(env, 7)); /* t */
    goto v0071;

v0028:
    v0153 = stack[0];
    v0153 = qcdr(v0153);
    if (!consp(v0153)) goto v0041;
    v0153 = qvalue(elt(env, 1)); /* nil */
    goto v0048;

v0041:
    v0153 = stack[-1];
    v0153 = qcdr(v0153);
    if (!consp(v0153)) goto v0117;
    v0153 = qvalue(elt(env, 1)); /* nil */
    goto v0048;

v0117:
    v0153 = stack[0];
    v0154 = qcdr(v0153);
    v0153 = stack[-1];
    v0153 = qcdr(v0153);
    fn = elt(env, 16); /* safe!-fp!-plus */
    v0153 = (*qfn2(fn))(qenv(fn), v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-4];
    v0154 = v0153;
    goto v0048;
/* error exit handlers */
v0156:
    popv(5);
    return nil;
}



/* Code for total!-degree!-in!-powers */

static Lisp_Object CC_totalKdegreeKinKpowers(Lisp_Object env,
                         Lisp_Object v0036, Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0168, v0169;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for total-degree-in-powers");
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0036,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
    stack[-1] = v0036;
/* end of prologue */

v0170:
    v0007 = stack[-1];
    if (v0007 == nil) goto v0005;
    v0007 = stack[-1];
    if (!consp(v0007)) goto v0082;
    v0007 = stack[-1];
    v0007 = qcar(v0007);
    v0007 = (consp(v0007) ? nil : lisp_true);
    goto v0047;

v0047:
    if (!(v0007 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0007 = stack[-1];
    v0007 = qcar(v0007);
    v0007 = qcar(v0007);
    v0168 = qcar(v0007);
    v0007 = stack[0];
    v0007 = Latsoc(nil, v0168, v0007);
    stack[-2] = v0007;
    if (v0007 == nil) goto v0133;
    v0007 = stack[-1];
    v0007 = qcar(v0007);
    v0007 = qcar(v0007);
    v0168 = qcdr(v0007);
    v0007 = stack[-2];
    v0007 = qcdr(v0007);
    v0007 = (Lisp_Object)greaterp2(v0168, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    v0007 = v0007 ? lisp_true : nil;
    env = stack[-3];
    if (v0007 == nil) goto v0171;
    v0168 = stack[-2];
    v0007 = stack[-1];
    v0007 = qcar(v0007);
    v0007 = qcar(v0007);
    v0007 = qcdr(v0007);
    v0007 = Lrplacd(nil, v0168, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    goto v0171;

v0171:
    v0007 = stack[-1];
    stack[-2] = qcdr(v0007);
    v0007 = stack[-1];
    v0007 = qcar(v0007);
    v0168 = qcdr(v0007);
    v0007 = stack[0];
    v0007 = CC_totalKdegreeKinKpowers(env, v0168, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    stack[-1] = stack[-2];
    stack[0] = v0007;
    goto v0170;

v0133:
    v0007 = stack[-1];
    v0007 = qcar(v0007);
    v0007 = qcar(v0007);
    v0169 = qcar(v0007);
    v0007 = stack[-1];
    v0007 = qcar(v0007);
    v0007 = qcar(v0007);
    v0168 = qcdr(v0007);
    v0007 = stack[0];
    v0007 = acons(v0169, v0168, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    stack[0] = v0007;
    goto v0171;

v0082:
    v0007 = qvalue(elt(env, 1)); /* t */
    goto v0047;

v0005:
    v0007 = qvalue(elt(env, 1)); /* t */
    goto v0047;
/* error exit handlers */
v0027:
    popv(4);
    return nil;
}



/* Code for begin1 */

static Lisp_Object MS_CDECL CC_begin1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0212, v0213, v0214;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "begin1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for begin1");
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
    v0212 = Ltime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0212; /* otime!* */
    v0212 = elt(env, 2); /* gctime */
    fn = elt(env, 63); /* getd */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    if (v0212 == nil) goto v0024;
    v0212 = Lgctime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    qvalue(elt(env, 3)) = v0212; /* ogctime!* */
    goto v0029;

v0029:
    v0212 = qvalue(elt(env, 1)); /* otime!* */
    qvalue(elt(env, 4)) = v0212; /* otime3!* */
    qvalue(elt(env, 5)) = v0212; /* otime2!* */
    qvalue(elt(env, 6)) = v0212; /* otime1!* */
    v0212 = qvalue(elt(env, 3)); /* ogctime!* */
    qvalue(elt(env, 7)) = v0212; /* ogctime3!* */
    qvalue(elt(env, 8)) = v0212; /* ogctime2!* */
    qvalue(elt(env, 9)) = v0212; /* ogctime1!* */
    v0212 = elt(env, 10); /* !*semicol!* */
    qvalue(elt(env, 11)) = v0212; /* cursym!* */
    goto v0003;

v0003:
    v0212 = qvalue(elt(env, 12)); /* !*int */
    if (v0212 == nil) goto v0117;
    v0212 = qvalue(elt(env, 13)); /* ifl!* */
    if (!(v0212 == nil)) goto v0117;
    v0212 = qvalue(elt(env, 14)); /* !*nosave!* */
    if (!(v0212 == nil)) goto v0043;
    v0213 = qvalue(elt(env, 15)); /* statcounter */
    v0212 = (Lisp_Object)1; /* 0 */
    if (v0213 == v0212) goto v0043;
    fn = elt(env, 64); /* add2buflis */
    v0212 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    goto v0043;

v0043:
    fn = elt(env, 65); /* update_prompt */
    v0212 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    goto v0117;

v0117:
    v0212 = qvalue(elt(env, 16)); /* nil */
    qvalue(elt(env, 14)) = v0212; /* !*nosave!* */
    v0212 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 17)) = v0212; /* !*strind */
    v0212 = qvalue(elt(env, 16)); /* nil */
    stack[-2] = v0212;
    v0212 = qvalue(elt(env, 18)); /* !*time */
    if (v0212 == nil) goto v0054;
    v0212 = elt(env, 19); /* (showtime) */
    fn = elt(env, 66); /* eval */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    goto v0054;

v0054:
    v0212 = qvalue(elt(env, 20)); /* !*output */
    if (v0212 == nil) goto v0050;
    v0212 = qvalue(elt(env, 21)); /* ofl!* */
    if (v0212 == nil) goto v0078;
    v0212 = qvalue(elt(env, 16)); /* nil */
    goto v0056;

v0056:
    if (v0212 == nil) goto v0050;
    v0212 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    goto v0050;

v0050:
    v0212 = qvalue(elt(env, 24)); /* tslin!* */
    if (v0212 == nil) goto v0216;
    v0212 = qvalue(elt(env, 24)); /* tslin!* */
    v0212 = qcar(v0212);
    qvalue(elt(env, 25)) = v0212; /* !*slin */
    v0212 = qvalue(elt(env, 24)); /* tslin!* */
    v0212 = qcdr(v0212);
    qvalue(elt(env, 26)) = v0212; /* lreadfn!* */
    v0212 = qvalue(elt(env, 16)); /* nil */
    qvalue(elt(env, 24)) = v0212; /* tslin!* */
    goto v0216;

v0216:
    v0212 = qvalue(elt(env, 27)); /* initl!* */
    stack[-1] = v0212;
    goto v0034;

v0034:
    v0212 = stack[-1];
    if (v0212 == nil) goto v0217;
    v0212 = stack[-1];
    stack[0] = qcar(v0212);
    v0212 = stack[-1];
    v0213 = qcar(v0212);
    v0212 = elt(env, 28); /* initl */
    v0212 = get(v0213, v0212);
    env = stack[-3];
    fn = elt(env, 66); /* eval */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    v0212 = Lset(nil, stack[0], v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    v0212 = stack[-1];
    v0212 = qcdr(v0212);
    stack[-1] = v0212;
    goto v0034;

v0217:
    v0213 = qvalue(elt(env, 29)); /* forkeywords!* */
    v0212 = elt(env, 30); /* delim */
    v0212 = Lremflag(nil, v0213, v0212);
    env = stack[-3];
    v0213 = qvalue(elt(env, 31)); /* repeatkeywords!* */
    v0212 = elt(env, 30); /* delim */
    v0212 = Lremflag(nil, v0213, v0212);
    env = stack[-3];
    v0213 = qvalue(elt(env, 32)); /* whilekeywords!* */
    v0212 = elt(env, 30); /* delim */
    v0212 = Lremflag(nil, v0213, v0212);
    env = stack[-3];
    v0212 = qvalue(elt(env, 12)); /* !*int */
    if (v0212 == nil) goto v0106;
    v0212 = qvalue(elt(env, 16)); /* nil */
    qvalue(elt(env, 33)) = v0212; /* erfg!* */
    goto v0106;

v0106:
    v0213 = qvalue(elt(env, 11)); /* cursym!* */
    v0212 = elt(env, 34); /* end */
    if (v0213 == v0212) goto v0218;
    v0212 = qvalue(elt(env, 12)); /* !*int */
    if (v0212 == nil) goto v0219;
    v0212 = qvalue(elt(env, 13)); /* ifl!* */
    if (!(v0212 == nil)) goto v0219;
    v0213 = qvalue(elt(env, 35)); /* key!* */
    v0212 = elt(env, 36); /* ed */
    if (v0213 == v0212) goto v0219;
    v0212 = qvalue(elt(env, 37)); /* promptexp!* */
    fn = elt(env, 67); /* printprompt */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    goto v0219;

v0219:
    v0214 = elt(env, 38); /* (command) */
    v0213 = qvalue(elt(env, 39)); /* t */
    v0212 = qvalue(elt(env, 40)); /* !*backtrace */
    fn = elt(env, 68); /* errorset */
    v0212 = (*qfnn(fn))(qenv(fn), 3, v0214, v0213, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    stack[-1] = v0212;
    v0212 = qvalue(elt(env, 20)); /* !*output */
    if (v0212 == nil) goto v0098;
    v0212 = qvalue(elt(env, 41)); /* !*echo */
    if (v0212 == nil) goto v0098;
    v0212 = qvalue(elt(env, 42)); /* !*extraecho */
    if (v0212 == nil) goto v0098;
    v0212 = qvalue(elt(env, 12)); /* !*int */
    if (v0212 == nil) goto v0156;
    v0212 = qvalue(elt(env, 13)); /* ifl!* */
    goto v0220;

v0220:
    if (v0212 == nil) goto v0098;
    v0212 = qvalue(elt(env, 22)); /* !*defn */
    if (!(v0212 == nil)) goto v0098;
    v0212 = qvalue(elt(env, 43)); /* !*demo */
    if (!(v0212 == nil)) goto v0098;
    v0212 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    goto v0098;

v0098:
    v0212 = stack[-1];
    if (!consp(v0212)) goto v0124;
    v0212 = stack[-1];
    v0212 = qcdr(v0212);
    goto v0221;

v0221:
    if (v0212 == nil) goto v0222;
    v0213 = qvalue(elt(env, 56)); /* program!* */
    v0212 = qvalue(elt(env, 57)); /* !$eof!$ */
    if (v0213 == v0212) goto v0223;
    v0212 = qvalue(elt(env, 16)); /* nil */
    goto v0224;

v0224:
    if (!(v0212 == nil)) goto v0047;
    v0213 = qvalue(elt(env, 52)); /* eof!* */
    v0212 = (Lisp_Object)1; /* 0 */
    v0212 = (Lisp_Object)greaterp2(v0213, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    v0212 = v0212 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0212 == nil)) goto v0047;
    v0213 = stack[-1];
    v0212 = elt(env, 59); /* "BEGIN invalid" */
    if (equal(v0213, v0212)) goto v0003;
    v0212 = qvalue(elt(env, 39)); /* t */
    stack[-2] = v0212;
    goto v0048;

v0048:
    v0212 = qvalue(elt(env, 25)); /* !*slin */
    if (!(v0212 == nil)) goto v0028;
    v0212 = qvalue(elt(env, 39)); /* t */
    fn = elt(env, 69); /* comm1 */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    goto v0028;

v0028:
    v0212 = qvalue(elt(env, 39)); /* t */
    qvalue(elt(env, 33)) = v0212; /* erfg!* */
    v0212 = qvalue(elt(env, 12)); /* !*int */
    if (v0212 == nil) goto v0225;
    v0212 = qvalue(elt(env, 16)); /* nil */
    goto v0226;

v0226:
    if (v0212 == nil) goto v0227;
    v0212 = qvalue(elt(env, 39)); /* t */
    qvalue(elt(env, 22)) = v0212; /* !*defn */
    v0212 = qvalue(elt(env, 39)); /* t */
    qvalue(elt(env, 41)) = v0212; /* !*echo */
    v0212 = qvalue(elt(env, 61)); /* cmsg!* */
    if (!(v0212 == nil)) goto v0228;
    v0212 = elt(env, 62); /* "Continuing with parsing only ..." */
    fn = elt(env, 70); /* lprie */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    goto v0228;

v0228:
    v0212 = qvalue(elt(env, 39)); /* t */
    qvalue(elt(env, 61)) = v0212; /* cmsg!* */
    goto v0003;

v0227:
    v0212 = qvalue(elt(env, 60)); /* !*errcont */
    if (v0212 == nil) goto v0229;
    v0212 = qvalue(elt(env, 16)); /* nil */
    qvalue(elt(env, 33)) = v0212; /* erfg!* */
    goto v0003;

v0229:
    v0212 = stack[-2];
    fn = elt(env, 71); /* pause1 */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    v0214 = v0212;
    v0212 = v0214;
    if (v0212 == nil) goto v0230;
    v0212 = v0214;
    fn = elt(env, 66); /* eval */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    v0212 = (v0212 == nil ? lisp_true : nil);
    { popv(4); return onevalue(v0212); }

v0230:
    v0212 = qvalue(elt(env, 16)); /* nil */
    qvalue(elt(env, 33)) = v0212; /* erfg!* */
    goto v0003;

v0225:
    v0212 = qvalue(elt(env, 60)); /* !*errcont */
    v0212 = (v0212 == nil ? lisp_true : nil);
    goto v0226;

v0047:
    v0212 = qvalue(elt(env, 48)); /* crbuf1!* */
    if (v0212 == nil) goto v0231;
    v0212 = qvalue(elt(env, 49)); /* !*msg */
    if (v0212 == nil) goto v0232;
    v0213 = elt(env, 50); /* "***" */
    v0212 = elt(env, 51); /* "Closing object improperly removed. Redo edit." 
*/
    fn = elt(env, 72); /* lpriw */
    v0212 = (*qfn2(fn))(qenv(fn), v0213, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    goto v0232;

v0232:
    v0212 = qvalue(elt(env, 16)); /* nil */
    qvalue(elt(env, 48)) = v0212; /* crbuf1!* */
    v0212 = qvalue(elt(env, 16)); /* nil */
    { popv(4); return onevalue(v0212); }

v0231:
    v0213 = qvalue(elt(env, 52)); /* eof!* */
    v0212 = (Lisp_Object)65; /* 4 */
    v0212 = (Lisp_Object)greaterp2(v0213, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    v0212 = v0212 ? lisp_true : nil;
    env = stack[-3];
    if (v0212 == nil) goto v0233;
    v0212 = qvalue(elt(env, 49)); /* !*msg */
    if (v0212 == nil) goto v0234;
    v0213 = elt(env, 50); /* "***" */
    v0212 = elt(env, 53); /* "End-of-file read" */
    fn = elt(env, 72); /* lpriw */
    v0212 = (*qfn2(fn))(qenv(fn), v0213, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    goto v0234;

v0234:
    v0212 = elt(env, 54); /* (bye) */
    {
        popv(4);
        fn = elt(env, 66); /* eval */
        return (*qfn1(fn))(qenv(fn), v0212);
    }

v0233:
    v0212 = qvalue(elt(env, 12)); /* !*int */
    if (v0212 == nil) goto v0235;
    v0212 = qvalue(elt(env, 13)); /* ifl!* */
    if (!(v0212 == nil)) goto v0235;
    v0212 = qvalue(elt(env, 16)); /* nil */
    qvalue(elt(env, 55)) = v0212; /* crbuf!* */
    v0212 = qvalue(elt(env, 39)); /* t */
    qvalue(elt(env, 14)) = v0212; /* !*nosave!* */
    goto v0003;

v0235:
    v0212 = qvalue(elt(env, 16)); /* nil */
    { popv(4); return onevalue(v0212); }

v0223:
    v0213 = qvalue(elt(env, 58)); /* ttype!* */
    v0212 = (Lisp_Object)49; /* 3 */
    if (v0213 == v0212) goto v0236;
    v0212 = qvalue(elt(env, 16)); /* nil */
    goto v0224;

v0236:
    v0212 = qvalue(elt(env, 52)); /* eof!* */
    v0212 = add1(v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    qvalue(elt(env, 52)) = v0212; /* eof!* */
    goto v0224;

v0222:
    v0212 = stack[-1];
    v0212 = qcar(v0212);
    stack[-1] = v0212;
    v0212 = stack[-1];
    v0213 = qcar(v0212);
    v0212 = elt(env, 44); /* symbolic */
    if (v0213 == v0212) goto v0237;
    v0212 = qvalue(elt(env, 16)); /* nil */
    goto v0238;

v0238:
    if (v0212 == nil) goto v0239;
    v0212 = stack[-1];
    v0212 = qcdr(v0212);
    v0212 = qcar(v0212);
    fn = elt(env, 66); /* eval */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    fn = elt(env, 73); /* xmodloop */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    v0214 = v0212;
    goto v0240;

v0240:
    v0212 = v0214;
    if (v0212 == nil) goto v0003;
    v0213 = v0214;
    v0212 = elt(env, 34); /* end */
    if (v0213 == v0212) goto v0241;
    v0213 = v0214;
    v0212 = elt(env, 46); /* err2 */
    if (v0213 == v0212) goto v0048;
    v0213 = v0214;
    v0212 = elt(env, 47); /* err3 */
    if (v0213 == v0212) goto v0028;
    else goto v0047;

v0241:
    v0212 = qvalue(elt(env, 16)); /* nil */
    { popv(4); return onevalue(v0212); }

v0239:
    v0212 = stack[-1];
    fn = elt(env, 74); /* begin11 */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    v0214 = v0212;
    goto v0240;

v0237:
    v0212 = stack[-1];
    v0212 = qcdr(v0212);
    v0213 = qcar(v0212);
    v0212 = elt(env, 45); /* xmodule */
    v0212 = Leqcar(nil, v0213, v0212);
    env = stack[-3];
    goto v0238;

v0124:
    v0212 = qvalue(elt(env, 39)); /* t */
    goto v0221;

v0156:
    v0212 = qvalue(elt(env, 39)); /* t */
    goto v0220;

v0218:
    v0212 = elt(env, 34); /* end */
    fn = elt(env, 69); /* comm1 */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-3];
    v0212 = qvalue(elt(env, 16)); /* nil */
    { popv(4); return onevalue(v0212); }

v0078:
    v0212 = qvalue(elt(env, 12)); /* !*int */
    if (v0212 == nil) goto v0242;
    v0212 = qvalue(elt(env, 13)); /* ifl!* */
    if (!(v0212 == nil)) goto v0242;
    v0212 = qvalue(elt(env, 22)); /* !*defn */
    if (v0212 == nil) goto v0243;
    v0212 = qvalue(elt(env, 16)); /* nil */
    goto v0056;

v0243:
    v0212 = qvalue(elt(env, 23)); /* !*lessspace */
    v0212 = (v0212 == nil ? lisp_true : nil);
    goto v0056;

v0242:
    v0212 = qvalue(elt(env, 16)); /* nil */
    goto v0056;

v0024:
    v0212 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v0212; /* ogctime!* */
    goto v0029;
/* error exit handlers */
v0215:
    popv(4);
    return nil;
}



/* Code for red_divtest */

static Lisp_Object CC_red_divtest(Lisp_Object env,
                         Lisp_Object v0036, Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0039;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_divtest");
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0036,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
    stack[-1] = v0036;
/* end of prologue */

v0004:
    v0059 = stack[-1];
    if (v0059 == nil) goto v0047;
    v0059 = stack[-1];
    v0059 = qcar(v0059);
    fn = elt(env, 2); /* bas_dpoly */
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    fn = elt(env, 3); /* dp_lmon */
    v0039 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    v0059 = stack[0];
    fn = elt(env, 4); /* mo_vdivides!? */
    v0059 = (*qfn2(fn))(qenv(fn), v0039, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-2];
    if (v0059 == nil) goto v0117;
    v0059 = stack[-1];
    v0059 = qcar(v0059);
    { popv(3); return onevalue(v0059); }

v0117:
    v0059 = stack[-1];
    v0059 = qcdr(v0059);
    stack[-1] = v0059;
    goto v0004;

v0047:
    v0059 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0059); }
/* error exit handlers */
v0043:
    popv(3);
    return nil;
}



/* Code for il_simp */

static Lisp_Object CC_il_simp(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for il_simp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0048 = v0036;
/* end of prologue */
    v0028 = v0048;
    v0048 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* il_simp1 */
        return (*qfn2(fn))(qenv(fn), v0028, v0048);
    }
}



/* Code for repeats */

static Lisp_Object CC_repeats(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0062, v0063;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repeats");
#endif
    if (stack >= stacklimit)
    {
        push(v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
/* end of prologue */
    v0063 = nil;
    goto v0004;

v0004:
    v0052 = stack[0];
    if (v0052 == nil) goto v0047;
    v0052 = stack[0];
    v0062 = qcar(v0052);
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    v0052 = Lmember(nil, v0062, v0052);
    if (v0052 == nil) goto v0044;
    v0052 = stack[0];
    v0052 = qcar(v0052);
    v0062 = v0063;
    v0052 = cons(v0052, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    v0063 = v0052;
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    stack[0] = v0052;
    goto v0004;

v0044:
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    stack[0] = v0052;
    goto v0004;

v0047:
    v0052 = v0063;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0052);
    }
/* error exit handlers */
v0022:
    popv(2);
    return nil;
}



/* Code for arglist_member */

static Lisp_Object CC_arglist_member(Lisp_Object env,
                         Lisp_Object v0036, Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0070;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arglist_member");
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0036,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
    stack[-1] = v0036;
/* end of prologue */

v0170:
    v0054 = stack[0];
    if (!consp(v0054)) goto v0245;
    v0070 = stack[-1];
    v0054 = stack[0];
    v0054 = qcar(v0054);
    if (equal(v0070, v0054)) goto v0049;
    v0054 = stack[0];
    v0054 = qcar(v0054);
    if (!consp(v0054)) goto v0063;
    v0070 = stack[-1];
    v0054 = stack[0];
    v0054 = qcar(v0054);
    v0054 = qcdr(v0054);
    v0054 = CC_arglist_member(env, v0070, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-2];
    goto v0046;

v0046:
    if (!(v0054 == nil)) { popv(3); return onevalue(v0054); }
    v0070 = stack[-1];
    v0054 = stack[0];
    v0054 = qcdr(v0054);
    stack[-1] = v0070;
    stack[0] = v0054;
    goto v0170;

v0063:
    v0054 = qvalue(elt(env, 2)); /* nil */
    goto v0046;

v0049:
    v0054 = qvalue(elt(env, 1)); /* t */
    goto v0046;

v0245:
    v0054 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0054); }
/* error exit handlers */
v0019:
    popv(3);
    return nil;
}



/* Code for mconv */

static Lisp_Object CC_mconv(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0118, v0117, v0064;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mconv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0064 = v0036;
/* end of prologue */
    v0038 = qvalue(elt(env, 1)); /* dmode!* */
    v0117 = v0038;
    v0038 = v0117;
    if (v0038 == nil) goto v0003;
    v0118 = v0117;
    v0038 = elt(env, 3); /* !:gi!: */
    if (v0118 == v0038) goto v0048;
    v0038 = v0117;
    goto v0004;

v0004:
    qvalue(elt(env, 5)) = v0038; /* dmd!* */
    v0038 = v0064;
    {
        fn = elt(env, 6); /* mconv1 */
        return (*qfn1(fn))(qenv(fn), v0038);
    }

v0048:
    v0038 = elt(env, 4); /* !:crn!: */
    goto v0004;

v0003:
    v0038 = elt(env, 2); /* !:rn!: */
    goto v0004;
}



/* Code for remlocs */

static Lisp_Object CC_remlocs(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0140, v0246;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remlocs");
#endif
    if (stack >= stacklimit)
    {
        push(v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0246 = v0036;
/* end of prologue */
    v0140 = qvalue(elt(env, 1)); /* !*globals */
    if (v0140 == nil) goto v0003;
    v0140 = v0246;
    stack[-2] = v0140;
    goto v0049;

v0049:
    v0140 = stack[-2];
    if (v0140 == nil) goto v0003;
    v0140 = stack[-2];
    v0140 = qcar(v0140);
    stack[-1] = v0140;
    v0246 = stack[-1];
    v0140 = qvalue(elt(env, 3)); /* locls!* */
    v0140 = Lassoc(nil, v0246, v0140);
    stack[-3] = v0140;
    v0140 = stack[-3];
    if (!(v0140 == nil)) goto v0040;
    v0140 = elt(env, 4); /* begin */
    fn = elt(env, 7); /* getd */
    v0140 = (*qfn1(fn))(qenv(fn), v0140);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-4];
    if (v0140 == nil) goto v0247;
    v0140 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v0140 == nil)) goto v0131;
    v0246 = elt(env, 6); /* " Lvar confused" */
    v0140 = stack[-1];
    v0140 = list2(v0246, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-4];
    fn = elt(env, 8); /* lprie */
    v0140 = (*qfn1(fn))(qenv(fn), v0140);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-4];
    goto v0131;

v0131:
    v0140 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-4];
    goto v0040;

v0040:
    v0140 = stack[-3];
    v0140 = qcdr(v0140);
    v0140 = qcdr(v0140);
    if (v0140 == nil) goto v0171;
    v0246 = stack[-3];
    v0140 = stack[-3];
    v0140 = qcdr(v0140);
    v0140 = qcdr(v0140);
    v0140 = Lrplacd(nil, v0246, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-4];
    goto v0015;

v0015:
    v0140 = stack[-2];
    v0140 = qcdr(v0140);
    stack[-2] = v0140;
    goto v0049;

v0171:
    v0246 = stack[-3];
    v0140 = qvalue(elt(env, 3)); /* locls!* */
    fn = elt(env, 9); /* efface1 */
    v0140 = (*qfn2(fn))(qenv(fn), v0246, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-4];
    qvalue(elt(env, 3)) = v0140; /* locls!* */
    goto v0015;

v0247:
    stack[0] = (Lisp_Object)1; /* 0 */
    v0246 = elt(env, 6); /* " Lvar confused" */
    v0140 = stack[-1];
    v0140 = list2(v0246, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-4];
    fn = elt(env, 10); /* error */
    v0140 = (*qfn2(fn))(qenv(fn), stack[0], v0140);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-4];
    goto v0040;

v0003:
    v0140 = nil;
    { popv(5); return onevalue(v0140); }
/* error exit handlers */
v0072:
    popv(5);
    return nil;
}



/* Code for ofsf_entry2at1 */

static Lisp_Object MS_CDECL CC_ofsf_entry2at1(Lisp_Object env, int nargs,
                         Lisp_Object v0036, Lisp_Object v0000,
                         Lisp_Object v0001, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0119, v0052, v0062;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_entry2at1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_entry2at1");
#endif
    if (stack >= stacklimit)
    {
        push3(v0001,v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0036,v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
    v0119 = v0036;
/* end of prologue */
    v0052 = stack[-1];
    v0062 = qcar(v0052);
    v0052 = v0119;
    v0119 = elt(env, 1); /* and */
    v0119 = (v0052 == v0119 ? lisp_true : nil);
    fn = elt(env, 3); /* ofsf_clnegrel */
    stack[-2] = (*qfn2(fn))(qenv(fn), v0062, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-3];
    v0052 = stack[0];
    v0119 = stack[-1];
    v0119 = qcdr(v0119);
    fn = elt(env, 4); /* addsq */
    v0119 = (*qfn2(fn))(qenv(fn), v0052, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-3];
    v0119 = qcar(v0119);
    v0052 = qvalue(elt(env, 2)); /* nil */
    {
        Lisp_Object v0131 = stack[-2];
        popv(4);
        return list3(v0131, v0119, v0052);
    }
/* error exit handlers */
v0023:
    popv(4);
    return nil;
}



/* Code for ibalp_process!-var */

static Lisp_Object MS_CDECL CC_ibalp_processKvar(Lisp_Object env, int nargs,
                         Lisp_Object v0036, Lisp_Object v0000,
                         Lisp_Object v0001, Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0263, v0264, v0198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ibalp_process-var");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_process-var");
#endif
    if (stack >= stacklimit)
    {
        push4(v0002,v0001,v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0036,v0000,v0001,v0002);
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
    stack[-11] = v0002;
    stack[-12] = v0001;
    stack[-13] = v0000;
    stack[-14] = v0036;
/* end of prologue */
    stack[0] = elt(env, 1); /* !! */
    v0263 = stack[-12];
    v0263 = Lexplode(nil, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    v0263 = cons(stack[0], v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    v0263 = Lcompress(nil, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    v0263 = Lintern(nil, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    stack[-12] = v0263;
    v0264 = stack[-12];
    v0263 = stack[-13];
    v0263 = Latsoc(nil, v0264, v0263);
    v0264 = v0263;
    if (v0263 == nil) goto v0045;
    v0263 = v0264;
    v0263 = qcdr(v0263);
    stack[0] = v0263;
    goto v0168;

v0168:
    v0264 = stack[-11];
    v0263 = (Lisp_Object)17; /* 1 */
    v0263 = Leqn(nil, v0264, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    if (v0263 == nil) goto v0203;
    v0263 = stack[0];
    v0263 = qcdr(v0263);
    stack[-1] = qcdr(v0263);
    v0264 = stack[-14];
    v0263 = stack[0];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcar(v0263);
    v0263 = cons(v0264, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    fn = elt(env, 3); /* setcar */
    v0263 = (*qfn2(fn))(qenv(fn), stack[-1], v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    v0263 = stack[0];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    stack[-1] = qcdr(v0263);
    v0263 = stack[0];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcar(v0263);
    v0263 = add1(v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    fn = elt(env, 3); /* setcar */
    v0263 = (*qfn2(fn))(qenv(fn), stack[-1], v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    v0263 = stack[0];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    stack[-1] = qcdr(v0263);
    v0263 = stack[0];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcar(v0263);
    v0263 = add1(v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    fn = elt(env, 3); /* setcar */
    v0263 = (*qfn2(fn))(qenv(fn), stack[-1], v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    stack[-1] = stack[-14];
    v0264 = stack[0];
    v0263 = stack[-14];
    v0263 = qcar(v0263);
    v0263 = cons(v0264, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    fn = elt(env, 3); /* setcar */
    v0263 = (*qfn2(fn))(qenv(fn), stack[-1], v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    { Lisp_Object res = stack[-13]; popv(17); return onevalue(res); }

v0203:
    v0263 = stack[0];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    stack[-1] = qcdr(v0263);
    v0264 = stack[-14];
    v0263 = stack[0];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcar(v0263);
    v0263 = cons(v0264, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    fn = elt(env, 3); /* setcar */
    v0263 = (*qfn2(fn))(qenv(fn), stack[-1], v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    v0263 = stack[0];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    stack[-1] = qcdr(v0263);
    v0263 = stack[0];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcar(v0263);
    v0263 = add1(v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    fn = elt(env, 3); /* setcar */
    v0263 = (*qfn2(fn))(qenv(fn), stack[-1], v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    v0263 = stack[0];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    stack[-1] = qcdr(v0263);
    v0263 = stack[0];
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcdr(v0263);
    v0263 = qcar(v0263);
    v0263 = add1(v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    fn = elt(env, 3); /* setcar */
    v0263 = (*qfn2(fn))(qenv(fn), stack[-1], v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    v0263 = stack[-14];
    stack[-1] = qcdr(v0263);
    v0264 = stack[0];
    v0263 = stack[-14];
    v0263 = qcdr(v0263);
    v0263 = qcar(v0263);
    v0263 = cons(v0264, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    fn = elt(env, 3); /* setcar */
    v0263 = (*qfn2(fn))(qenv(fn), stack[-1], v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    { Lisp_Object res = stack[-13]; popv(17); return onevalue(res); }

v0045:
    stack[-15] = stack[-12];
    stack[-10] = qvalue(elt(env, 2)); /* nil */
    stack[-9] = qvalue(elt(env, 2)); /* nil */
    stack[-8] = qvalue(elt(env, 2)); /* nil */
    stack[-7] = (Lisp_Object)1; /* 0 */
    stack[-6] = (Lisp_Object)1; /* 0 */
    stack[-5] = (Lisp_Object)-15; /* -1 */
    stack[-4] = qvalue(elt(env, 2)); /* nil */
    stack[-3] = (Lisp_Object)1; /* 0 */
    stack[-2] = (Lisp_Object)1; /* 0 */
    stack[-1] = qvalue(elt(env, 2)); /* nil */
    stack[0] = (Lisp_Object)1; /* 0 */
    v0198 = qvalue(elt(env, 2)); /* nil */
    v0264 = (Lisp_Object)1; /* 0 */
    v0263 = qvalue(elt(env, 2)); /* nil */
    v0263 = list3(v0198, v0264, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    v0263 = list3star(stack[-2], stack[-1], stack[0], v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    v0263 = list3star(stack[-5], stack[-4], stack[-3], v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    v0263 = list3star(stack[-8], stack[-7], stack[-6], v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    v0263 = list3star(stack[-15], stack[-10], stack[-9], v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    stack[0] = v0263;
    v0198 = stack[-12];
    v0264 = stack[0];
    v0263 = stack[-13];
    v0263 = acons(v0198, v0264, v0263);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-16];
    stack[-13] = v0263;
    goto v0168;
/* error exit handlers */
v0265:
    popv(17);
    return nil;
}



/* Code for cgp_ci */

static Lisp_Object CC_cgp_ci(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0028, v0046;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_ci");
#endif
    if (stack >= stacklimit)
    {
        push(v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0028 = v0036;
/* end of prologue */
    v0046 = v0028;
    v0028 = (Lisp_Object)97; /* 6 */
    fn = elt(env, 1); /* pnth */
    v0028 = (*qfn2(fn))(qenv(fn), v0046, v0028);
    errexit();
    v0028 = qcar(v0028);
    return onevalue(v0028);
}



/* Code for !*wedgepf2pf */

static Lisp_Object CC_Hwedgepf2pf(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0037, v0043;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *wedgepf2pf");
#endif
    if (stack >= stacklimit)
    {
        push(v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
/* end of prologue */
    stack[-1] = nil;
    goto v0004;

v0004:
    v0040 = stack[0];
    if (v0040 == nil) goto v0047;
    v0040 = stack[0];
    v0040 = qcar(v0040);
    v0040 = qcar(v0040);
    fn = elt(env, 1); /* mkuwedge */
    v0043 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    v0040 = stack[0];
    v0040 = qcar(v0040);
    v0037 = qcdr(v0040);
    v0040 = stack[-1];
    v0040 = acons(v0043, v0037, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    stack[-1] = v0040;
    v0040 = stack[0];
    v0040 = qcdr(v0040);
    stack[0] = v0040;
    goto v0004;

v0047:
    v0040 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0040);
    }
/* error exit handlers */
v0020:
    popv(3);
    return nil;
}



/* Code for assert_error */

static Lisp_Object MS_CDECL CC_assert_error(Lisp_Object env, int nargs,
                         Lisp_Object v0036, Lisp_Object v0000,
                         Lisp_Object v0001, Lisp_Object v0002,
                         Lisp_Object v0057, Lisp_Object v0004, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0267, v0205, v0206;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "assert_error");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_error");
#endif
    if (stack >= stacklimit)
    {
        push6(v0004,v0057,v0002,v0001,v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0036,v0000,v0001,v0002,v0057,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0004;
    v0267 = v0057;
    stack[-2] = v0002;
    stack[-3] = v0001;
    stack[-4] = v0000;
    stack[-5] = v0036;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* !*lower */
    qvalue(elt(env, 1)) = nil; /* !*lower */
    v0267 = qvalue(elt(env, 2)); /* !*assertstatistics */
    if (v0267 == nil) goto v0023;
    v0205 = stack[-5];
    v0267 = qvalue(elt(env, 3)); /* assertstatistics!* */
    v0267 = Latsoc(nil, v0205, v0267);
    v0267 = qcdr(v0267);
    v0205 = v0267;
    v0267 = v0205;
    v0267 = qcdr(v0267);
    stack[0] = qcdr(v0267);
    v0267 = v0205;
    v0267 = qcdr(v0267);
    v0267 = qcdr(v0267);
    v0267 = qcar(v0267);
    v0267 = add1(v0267);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-7];
    fn = elt(env, 13); /* setcar */
    v0267 = (*qfn2(fn))(qenv(fn), stack[0], v0267);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-7];
    goto v0023;

v0023:
    v0205 = stack[-2];
    v0267 = (Lisp_Object)1; /* 0 */
    v0267 = Leqn(nil, v0205, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-7];
    if (v0267 == nil) goto v0013;
    stack[0] = elt(env, 4); /* "declaration" */
    v0206 = stack[-5];
    v0205 = stack[-4];
    v0267 = stack[-3];
    fn = elt(env, 14); /* assert_format */
    v0206 = (*qfnn(fn))(qenv(fn), 3, v0206, v0205, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-7];
    v0205 = elt(env, 5); /* "violated by result" */
    v0267 = stack[-1];
    v0267 = list4(stack[0], v0206, v0205, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-7];
    goto v0062;

v0062:
    v0205 = qvalue(elt(env, 8)); /* !*assertbreak */
    if (v0205 == nil) goto v0257;
    v0205 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v0205 == nil)) goto v0209;
    fn = elt(env, 15); /* lprie */
    v0267 = (*qfn1(fn))(qenv(fn), v0267);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-7];
    goto v0209;

v0209:
    v0267 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-7];
    goto v0268;

v0268:
    v0267 = nil;
    qvalue(elt(env, 1)) = stack[-6]; /* !*lower */
    { popv(8); return onevalue(v0267); }

v0257:
    v0205 = qvalue(elt(env, 10)); /* !*msg */
    if (v0205 == nil) goto v0268;
    v0205 = elt(env, 12); /* "***" */
    fn = elt(env, 16); /* lpriw */
    v0267 = (*qfn2(fn))(qenv(fn), v0205, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-7];
    goto v0268;

v0013:
    stack[0] = elt(env, 4); /* "declaration" */
    v0206 = stack[-5];
    v0205 = stack[-4];
    v0267 = stack[-3];
    fn = elt(env, 14); /* assert_format */
    stack[-4] = (*qfnn(fn))(qenv(fn), 3, v0206, v0205, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-7];
    stack[-3] = elt(env, 6); /* "violated by" */
    v0205 = elt(env, 7); /* arg */
    v0267 = stack[-2];
    fn = elt(env, 17); /* mkid */
    v0205 = (*qfn2(fn))(qenv(fn), v0205, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-7];
    v0267 = stack[-1];
    v0267 = list2(v0205, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-7];
    v0267 = list3star(stack[0], stack[-4], stack[-3], v0267);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-7];
    goto v0062;
/* error exit handlers */
v0165:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* !*lower */
    popv(8);
    return nil;
}



/* Code for mo_neg */

static Lisp_Object CC_mo_neg(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0074;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_neg");
#endif
    if (stack >= stacklimit)
    {
        push(v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0036;
/* end of prologue */
    v0074 = stack[-2];
    v0074 = qcar(v0074);
    stack[-4] = v0074;
    v0074 = stack[-4];
    if (v0074 == nil) goto v0067;
    v0074 = stack[-4];
    v0074 = qcar(v0074);
    v0074 = negate(v0074);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-5];
    v0074 = ncons(v0074);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-5];
    stack[-1] = v0074;
    stack[-3] = v0074;
    goto v0049;

v0049:
    v0074 = stack[-4];
    v0074 = qcdr(v0074);
    stack[-4] = v0074;
    v0074 = stack[-4];
    if (v0074 == nil) goto v0039;
    stack[0] = stack[-1];
    v0074 = stack[-4];
    v0074 = qcar(v0074);
    v0074 = negate(v0074);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-5];
    v0074 = ncons(v0074);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-5];
    v0074 = Lrplacd(nil, stack[0], v0074);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-5];
    v0074 = stack[-1];
    v0074 = qcdr(v0074);
    stack[-1] = v0074;
    goto v0049;

v0039:
    v0074 = stack[-3];
    stack[-4] = v0074;
    goto v0004;

v0004:
    v0074 = stack[-2];
    v0074 = qcdr(v0074);
    stack[-3] = v0074;
    v0074 = stack[-3];
    if (v0074 == nil) goto v0019;
    v0074 = stack[-3];
    v0074 = qcar(v0074);
    v0074 = negate(v0074);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-5];
    v0074 = ncons(v0074);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-5];
    stack[-1] = v0074;
    stack[-2] = v0074;
    goto v0053;

v0053:
    v0074 = stack[-3];
    v0074 = qcdr(v0074);
    stack[-3] = v0074;
    v0074 = stack[-3];
    if (v0074 == nil) goto v0132;
    stack[0] = stack[-1];
    v0074 = stack[-3];
    v0074 = qcar(v0074);
    v0074 = negate(v0074);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-5];
    v0074 = ncons(v0074);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-5];
    v0074 = Lrplacd(nil, stack[0], v0074);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-5];
    v0074 = stack[-1];
    v0074 = qcdr(v0074);
    stack[-1] = v0074;
    goto v0053;

v0132:
    v0074 = stack[-2];
    goto v0003;

v0003:
    {
        Lisp_Object v0216 = stack[-4];
        popv(6);
        return cons(v0216, v0074);
    }

v0019:
    v0074 = qvalue(elt(env, 1)); /* nil */
    goto v0003;

v0067:
    v0074 = qvalue(elt(env, 1)); /* nil */
    stack[-4] = v0074;
    goto v0004;
/* error exit handlers */
v0151:
    popv(6);
    return nil;
}



/* Code for pappend */

static Lisp_Object CC_pappend(Lisp_Object env,
                         Lisp_Object v0036, Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0132, v0166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pappend");
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0036,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
    stack[-4] = v0036;
/* end of prologue */
    v0132 = stack[-4];
    fn = elt(env, 2); /* unpkp */
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    stack[-4] = v0132;
    v0132 = stack[-4];
    v0132 = Llength(nil, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    stack[-5] = v0132;
    v0132 = stack[0];
    fn = elt(env, 2); /* unpkp */
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    stack[0] = v0132;
    v0132 = stack[0];
    stack[-3] = v0132;
    v0132 = stack[-3];
    if (v0132 == nil) goto v0031;
    v0132 = stack[-3];
    v0132 = qcar(v0132);
    v0166 = v0132;
    v0132 = stack[-5];
    v0132 = plus2(v0166, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    v0132 = ncons(v0132);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    stack[-1] = v0132;
    stack[-2] = v0132;
    goto v0082;

v0082:
    v0132 = stack[-3];
    v0132 = qcdr(v0132);
    stack[-3] = v0132;
    v0132 = stack[-3];
    if (v0132 == nil) goto v0062;
    stack[0] = stack[-1];
    v0132 = stack[-3];
    v0132 = qcar(v0132);
    v0166 = v0132;
    v0132 = stack[-5];
    v0132 = plus2(v0166, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    v0132 = ncons(v0132);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    v0132 = Lrplacd(nil, stack[0], v0132);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    v0132 = stack[-1];
    v0132 = qcdr(v0132);
    stack[-1] = v0132;
    goto v0082;

v0062:
    v0132 = stack[-2];
    goto v0041;

v0041:
    stack[0] = v0132;
    v0166 = stack[-4];
    v0132 = stack[0];
    v0132 = Lappend(nil, v0166, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 3); /* pkp */
        return (*qfn1(fn))(qenv(fn), v0132);
    }

v0031:
    v0132 = qvalue(elt(env, 1)); /* nil */
    goto v0041;
/* error exit handlers */
v0113:
    popv(7);
    return nil;
}



/* Code for set!-general!-modulus */

static Lisp_Object CC_setKgeneralKmodulus(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0061, v0245;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for set-general-modulus");
#endif
    if (stack >= stacklimit)
    {
        push(v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
/* end of prologue */
    v0061 = stack[0];
    if (is_number(v0061)) goto v0029;
    v0061 = qvalue(elt(env, 1)); /* t */
    goto v0034;

v0034:
    if (v0061 == nil) goto v0244;
    v0061 = qvalue(elt(env, 2)); /* current!-modulus */
    { popv(3); return onevalue(v0061); }

v0244:
    v0061 = qvalue(elt(env, 2)); /* current!-modulus */
    stack[-1] = v0061;
    v0061 = stack[0];
    qvalue(elt(env, 2)) = v0061; /* current!-modulus */
    v0245 = stack[0];
    v0061 = (Lisp_Object)33; /* 2 */
    v0061 = quot2(v0245, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    qvalue(elt(env, 3)) = v0061; /* modulus!/2 */
    v0245 = stack[0];
    v0061 = qvalue(elt(env, 4)); /* largest!-small!-modulus */
    v0061 = (Lisp_Object)lesseq2(v0245, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    v0061 = v0061 ? lisp_true : nil;
    env = stack[-2];
    if (v0061 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0061 = stack[0];
    v0061 = Lset_small_modulus(nil, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v0029:
    v0245 = stack[0];
    v0061 = (Lisp_Object)1; /* 0 */
    v0061 = (v0245 == v0061 ? lisp_true : nil);
    goto v0034;
/* error exit handlers */
v0054:
    popv(3);
    return nil;
}



/* Code for simpatom */

static Lisp_Object CC_simpatom(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0289, v0239, v0290;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpatom");
#endif
    if (stack >= stacklimit)
    {
        push(v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
/* end of prologue */
    v0289 = stack[0];
    if (v0289 == nil) goto v0047;
    v0289 = stack[0];
    if (is_number(v0289)) goto v0030;
    v0289 = stack[0];
    v0289 = Lstringp(nil, v0289);
    env = stack[-2];
    if (v0289 == nil) goto v0165;
    v0239 = elt(env, 8); /* "String" */
    v0289 = stack[0];
    v0239 = list2(v0239, v0289);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-2];
    v0289 = elt(env, 9); /* "identifier" */
    {
        popv(3);
        fn = elt(env, 18); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0239, v0289);
    }

v0165:
    v0239 = stack[0];
    v0289 = elt(env, 10); /* share */
    v0289 = Lflagp(nil, v0239, v0289);
    env = stack[-2];
    if (v0289 == nil) goto v0292;
    v0289 = stack[0];
    fn = elt(env, 19); /* eval */
    v0289 = (*qfn1(fn))(qenv(fn), v0289);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-2];
    v0290 = v0289;
    v0239 = v0290;
    v0289 = stack[0];
    if (v0239 == v0289) goto v0103;
    v0289 = v0290;
    {
        popv(3);
        fn = elt(env, 20); /* simp */
        return (*qfn1(fn))(qenv(fn), v0289);
    }

v0103:
    v0239 = stack[0];
    v0289 = (Lisp_Object)17; /* 1 */
    {
        popv(3);
        fn = elt(env, 21); /* mksq */
        return (*qfn2(fn))(qenv(fn), v0239, v0289);
    }

v0292:
    v0239 = stack[0];
    v0289 = elt(env, 11); /* idvalfn */
    v0289 = get(v0239, v0289);
    env = stack[-2];
    v0290 = v0289;
    if (v0289 == nil) goto v0293;
    v0239 = v0290;
    v0289 = stack[0];
        popv(3);
        return Lapply1(nil, v0239, v0289);

v0293:
    v0289 = qvalue(elt(env, 12)); /* !*numval */
    if (v0289 == nil) goto v0294;
    v0289 = qvalue(elt(env, 3)); /* dmode!* */
    if (v0289 == nil) goto v0294;
    v0239 = stack[0];
    v0289 = elt(env, 13); /* constant */
    v0289 = Lflagp(nil, v0239, v0289);
    env = stack[-2];
    if (v0289 == nil) goto v0238;
    v0239 = stack[0];
    v0289 = qvalue(elt(env, 3)); /* dmode!* */
    v0289 = get(v0239, v0289);
    env = stack[-2];
    v0290 = v0289;
    if (v0289 == nil) goto v0295;
    stack[-1] = elt(env, 14); /* lispapply */
    v0289 = v0290;
    v0239 = Lmkquote(nil, v0289);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-2];
    v0289 = qvalue(elt(env, 1)); /* nil */
    v0290 = list3(stack[-1], v0239, v0289);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-2];
    v0239 = qvalue(elt(env, 1)); /* nil */
    v0289 = qvalue(elt(env, 15)); /* !*backtrace */
    fn = elt(env, 22); /* errorset */
    v0289 = (*qfnn(fn))(qenv(fn), 3, v0290, v0239, v0289);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-2];
    v0290 = v0289;
    v0239 = v0289;
    v0289 = v0239;
    if (!consp(v0289)) goto v0296;
    v0289 = v0239;
    v0289 = qcdr(v0289);
    goto v0297;

v0297:
    v0289 = (v0289 == nil ? lisp_true : nil);
    goto v0135;

v0135:
    if (v0289 == nil) goto v0294;
    v0289 = v0290;
    v0289 = qcar(v0289);
    {
        popv(3);
        fn = elt(env, 23); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v0289);
    }

v0294:
    v0289 = stack[0];
    fn = elt(env, 24); /* getrtype */
    v0289 = (*qfn1(fn))(qenv(fn), v0289);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-2];
    if (v0289 == nil) goto v0298;
    v0239 = stack[0];
    v0289 = elt(env, 17); /* scalar */
    fn = elt(env, 18); /* typerr */
    v0289 = (*qfn2(fn))(qenv(fn), v0239, v0289);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    v0289 = nil;
    { popv(3); return onevalue(v0289); }

v0298:
    v0239 = stack[0];
    v0289 = (Lisp_Object)17; /* 1 */
    {
        popv(3);
        fn = elt(env, 21); /* mksq */
        return (*qfn2(fn))(qenv(fn), v0239, v0289);
    }

v0296:
    v0289 = qvalue(elt(env, 16)); /* t */
    goto v0297;

v0295:
    v0289 = qvalue(elt(env, 1)); /* nil */
    goto v0135;

v0238:
    v0289 = qvalue(elt(env, 1)); /* nil */
    goto v0135;

v0030:
    v0239 = stack[0];
    v0289 = (Lisp_Object)1; /* 0 */
    if (v0239 == v0289) goto v0130;
    v0289 = stack[0];
    v0289 = integerp(v0289);
    if (v0289 == nil) goto v0063;
    v0239 = qvalue(elt(env, 3)); /* dmode!* */
    v0289 = elt(env, 4); /* !:mod!: */
    if (v0239 == v0289) goto v0115;
    v0289 = qvalue(elt(env, 1)); /* nil */
    goto v0054;

v0054:
    if (v0289 == nil) goto v0009;
    v0239 = qvalue(elt(env, 1)); /* nil */
    v0289 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0239, v0289);

v0009:
    v0239 = qvalue(elt(env, 3)); /* dmode!* */
    v0289 = elt(env, 6); /* convert */
    v0289 = Lflagp(nil, v0239, v0289);
    env = stack[-2];
    if (v0289 == nil) goto v0258;
    v0239 = stack[0];
    v0289 = (Lisp_Object)17; /* 1 */
    v0289 = Lneq(nil, v0239, v0289);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-2];
    goto v0085;

v0085:
    if (v0289 == nil) goto v0126;
    v0239 = qvalue(elt(env, 3)); /* dmode!* */
    v0289 = elt(env, 7); /* i2d */
    v0239 = get(v0239, v0289);
    env = stack[-2];
    v0289 = stack[0];
    v0289 = Lapply1(nil, v0239, v0289);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 23); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v0289);
    }

v0126:
    v0239 = stack[0];
    v0289 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0239, v0289);

v0258:
    v0289 = qvalue(elt(env, 1)); /* nil */
    goto v0085;

v0115:
    v0239 = qvalue(elt(env, 5)); /* current!-modulus */
    v0289 = (Lisp_Object)17; /* 1 */
    v0289 = (v0239 == v0289 ? lisp_true : nil);
    goto v0054;

v0063:
    stack[-1] = elt(env, 2); /* !:rd!: */
    v0289 = stack[0];
    fn = elt(env, 25); /* fl2bf */
    v0289 = (*qfn1(fn))(qenv(fn), v0289);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    v0239 = qcdr(v0289);
    v0289 = (Lisp_Object)17; /* 1 */
    {
        Lisp_Object v0299 = stack[-1];
        popv(3);
        return acons(v0299, v0239, v0289);
    }

v0130:
    v0239 = qvalue(elt(env, 1)); /* nil */
    v0289 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0239, v0289);

v0047:
    v0239 = qvalue(elt(env, 1)); /* nil */
    v0289 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0239, v0289);
/* error exit handlers */
v0291:
    popv(3);
    return nil;
}



/* Code for gettype */

static Lisp_Object CC_gettype(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0262, v0171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gettype");
#endif
    if (stack >= stacklimit)
    {
        push(v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
/* end of prologue */
    v0262 = stack[0];
    if (is_number(v0262)) goto v0057;
    v0262 = stack[0];
    if (!consp(v0262)) goto v0041;
    v0262 = qvalue(elt(env, 2)); /* t */
    goto v0028;

v0028:
    if (v0262 == nil) goto v0040;
    v0262 = elt(env, 3); /* form */
    { popv(2); return onevalue(v0262); }

v0040:
    v0171 = stack[0];
    v0262 = elt(env, 4); /* simpfn */
    v0262 = get(v0171, v0262);
    env = stack[-1];
    if (v0262 == nil) goto v0022;
    v0262 = elt(env, 5); /* operator */
    { popv(2); return onevalue(v0262); }

v0022:
    v0171 = stack[0];
    v0262 = elt(env, 6); /* avalue */
    v0262 = get(v0171, v0262);
    env = stack[-1];
    if (v0262 == nil) goto v0063;
    v0171 = stack[0];
    v0262 = elt(env, 6); /* avalue */
    v0262 = get(v0171, v0262);
    v0262 = qcar(v0262);
    { popv(2); return onevalue(v0262); }

v0063:
    v0262 = stack[0];
    fn = elt(env, 13); /* getd */
    v0262 = (*qfn1(fn))(qenv(fn), v0262);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-1];
    if (v0262 == nil) goto v0019;
    v0262 = elt(env, 7); /* procedure */
    { popv(2); return onevalue(v0262); }

v0019:
    v0262 = stack[0];
    v0262 = Lsymbol_globalp(nil, v0262);
    env = stack[-1];
    if (v0262 == nil) goto v0116;
    v0262 = elt(env, 8); /* global */
    { popv(2); return onevalue(v0262); }

v0116:
    v0262 = stack[0];
    v0262 = Lsymbol_specialp(nil, v0262);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-1];
    if (v0262 == nil) goto v0015;
    v0262 = elt(env, 9); /* fluid */
    { popv(2); return onevalue(v0262); }

v0015:
    v0171 = stack[0];
    v0262 = elt(env, 10); /* parm */
    v0262 = Lflagp(nil, v0171, v0262);
    env = stack[-1];
    if (v0262 == nil) goto v0085;
    v0262 = elt(env, 11); /* parameter */
    { popv(2); return onevalue(v0262); }

v0085:
    v0262 = stack[0];
    v0171 = elt(env, 12); /* rtype */
    popv(2);
    return get(v0262, v0171);

v0041:
    v0262 = stack[0];
    if (v0262 == nil) goto v0024;
    v0262 = stack[0];
    v0262 = Lsymbolp(nil, v0262);
    env = stack[-1];
    v0262 = (v0262 == nil ? lisp_true : nil);
    goto v0028;

v0024:
    v0262 = qvalue(elt(env, 2)); /* t */
    goto v0028;

v0057:
    v0262 = elt(env, 1); /* number */
    { popv(2); return onevalue(v0262); }
/* error exit handlers */
v0152:
    popv(2);
    return nil;
}



/* Code for pasf_vf */

static Lisp_Object CC_pasf_vf(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0081, v0209, v0287;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_vf");
#endif
    if (stack >= stacklimit)
    {
        push(v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0209 = v0036;
/* end of prologue */
    v0287 = v0209;
    v0081 = elt(env, 1); /* true */
    if (v0287 == v0081) goto v0029;
    v0287 = v0209;
    v0081 = elt(env, 3); /* false */
    v0081 = (v0287 == v0081 ? lisp_true : nil);
    goto v0049;

v0049:
    if (v0081 == nil) goto v0048;
    v0081 = qvalue(elt(env, 4)); /* nil */
    goto v0005;

v0005:
    if (v0081 == nil) { popv(1); return onevalue(v0209); }
    v0081 = v0209;
    v0081 = Lconsp(nil, v0081);
    env = stack[0];
    if (v0081 == nil) goto v0258;
    v0081 = v0209;
    v0081 = qcar(v0081);
    v0081 = Lconsp(nil, v0081);
    env = stack[0];
    if (v0081 == nil) goto v0258;
    v0081 = v0209;
    v0081 = qcar(v0081);
    v0287 = qcar(v0081);
    v0081 = elt(env, 5); /* (cong ncong) */
    v0081 = Lmemq(nil, v0287, v0081);
    if (v0081 == nil) goto v0258;
    v0081 = v0209;
    v0081 = qcar(v0081);
    v0081 = qcdr(v0081);
    if (!consp(v0081)) goto v0013;
    v0081 = v0209;
    v0081 = qcar(v0081);
    v0081 = qcdr(v0081);
    v0081 = qcar(v0081);
    v0081 = (consp(v0081) ? nil : lisp_true);
    goto v0015;

v0015:
    if (!(v0081 == nil)) goto v0258;
    v0081 = v0209;
    v0081 = qcdr(v0081);
    v0081 = qcar(v0081);
    if (!(v0081 == nil)) { popv(1); return onevalue(v0209); }
    v0081 = elt(env, 3); /* false */
    { popv(1); return onevalue(v0081); }

v0258:
    v0081 = v0209;
    v0081 = qcar(v0081);
    v0209 = qcdr(v0209);
    v0209 = qcar(v0209);
    fn = elt(env, 6); /* pasf_evalatp */
    v0081 = (*qfn2(fn))(qenv(fn), v0081, v0209);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[0];
    if (v0081 == nil) goto v0026;
    v0081 = elt(env, 1); /* true */
    { popv(1); return onevalue(v0081); }

v0026:
    v0081 = elt(env, 3); /* false */
    { popv(1); return onevalue(v0081); }

v0013:
    v0081 = qvalue(elt(env, 2)); /* t */
    goto v0015;

v0048:
    v0081 = v0209;
    v0081 = qcdr(v0081);
    v0081 = qcar(v0081);
    if (!consp(v0081)) goto v0044;
    v0081 = v0209;
    v0081 = qcdr(v0081);
    v0081 = qcar(v0081);
    v0081 = qcar(v0081);
    v0081 = (consp(v0081) ? nil : lisp_true);
    goto v0005;

v0044:
    v0081 = qvalue(elt(env, 2)); /* t */
    goto v0005;

v0029:
    v0081 = qvalue(elt(env, 2)); /* t */
    goto v0049;
/* error exit handlers */
v0033:
    popv(1);
    return nil;
}



/* Code for ibalp_unvar!-unsatlist */

static Lisp_Object CC_ibalp_unvarKunsatlist(Lisp_Object env,
                         Lisp_Object v0036, Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0312, v0313;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_unvar-unsatlist");
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0036,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0000;
    v0312 = v0036;
/* end of prologue */
    stack[-5] = v0312;
    goto v0005;

v0005:
    v0312 = stack[-5];
    if (v0312 == nil) goto v0047;
    v0312 = stack[-5];
    v0312 = qcar(v0312);
    stack[-3] = v0312;
    v0312 = stack[-3];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    stack[0] = qcdr(v0312);
    v0313 = stack[-4];
    v0312 = stack[-3];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcar(v0312);
    fn = elt(env, 2); /* delq */
    v0312 = (*qfn2(fn))(qenv(fn), v0313, v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v0312 = (*qfn2(fn))(qenv(fn), stack[0], v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    v0312 = stack[-3];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcar(v0312);
    if (!(v0312 == nil)) goto v0023;
    v0312 = stack[-3];
    v0312 = qcar(v0312);
    stack[-2] = v0312;
    goto v0054;

v0054:
    v0312 = stack[-2];
    if (v0312 == nil) goto v0053;
    v0312 = stack[-2];
    v0312 = qcar(v0312);
    stack[-1] = v0312;
    v0312 = stack[-1];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    stack[0] = qcdr(v0312);
    v0312 = stack[-1];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcar(v0312);
    v0312 = add1(v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v0312 = (*qfn2(fn))(qenv(fn), stack[0], v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    v0312 = stack[-1];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    stack[0] = qcdr(v0312);
    v0312 = stack[-1];
    fn = elt(env, 4); /* ibalp_calcmom */
    v0312 = (*qfn1(fn))(qenv(fn), v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v0312 = (*qfn2(fn))(qenv(fn), stack[0], v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    v0312 = stack[-2];
    v0312 = qcdr(v0312);
    stack[-2] = v0312;
    goto v0054;

v0053:
    v0312 = stack[-3];
    v0312 = qcdr(v0312);
    v0312 = qcar(v0312);
    stack[-2] = v0312;
    goto v0072;

v0072:
    v0312 = stack[-2];
    if (v0312 == nil) goto v0071;
    v0312 = stack[-2];
    v0312 = qcar(v0312);
    stack[-1] = v0312;
    v0312 = stack[-1];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    stack[0] = qcdr(v0312);
    v0312 = stack[-1];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcar(v0312);
    v0312 = add1(v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v0312 = (*qfn2(fn))(qenv(fn), stack[0], v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    v0312 = stack[-1];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    stack[0] = qcdr(v0312);
    v0312 = stack[-1];
    fn = elt(env, 4); /* ibalp_calcmom */
    v0312 = (*qfn1(fn))(qenv(fn), v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v0312 = (*qfn2(fn))(qenv(fn), stack[0], v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    v0312 = stack[-2];
    v0312 = qcdr(v0312);
    stack[-2] = v0312;
    goto v0072;

v0071:
    v0312 = stack[-3];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcar(v0312);
    stack[-1] = v0312;
    goto v0106;

v0106:
    v0312 = stack[-1];
    if (v0312 == nil) goto v0134;
    v0312 = stack[-1];
    v0312 = qcar(v0312);
    v0313 = v0312;
    v0313 = qcdr(v0313);
    v0313 = qcdr(v0313);
    v0313 = qcdr(v0313);
    v0313 = qcdr(v0313);
    v0313 = qcdr(v0313);
    v0313 = qcdr(v0313);
    v0313 = qcdr(v0313);
    v0313 = qcdr(v0313);
    v0313 = qcdr(v0313);
    stack[0] = qcdr(v0313);
    v0313 = stack[-3];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcar(v0312);
    fn = elt(env, 2); /* delq */
    v0312 = (*qfn2(fn))(qenv(fn), v0313, v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v0312 = (*qfn2(fn))(qenv(fn), stack[0], v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    v0312 = stack[-1];
    v0312 = qcdr(v0312);
    stack[-1] = v0312;
    goto v0106;

v0134:
    v0312 = stack[-3];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0313 = qcdr(v0312);
    v0312 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* setcar */
    v0312 = (*qfn2(fn))(qenv(fn), v0313, v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    v0312 = stack[-3];
    fn = elt(env, 5); /* ibalp_getnewwl */
    v0312 = (*qfn1(fn))(qenv(fn), v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    stack[-1] = v0312;
    v0312 = stack[-3];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    stack[0] = qcdr(v0312);
    v0313 = stack[-1];
    v0312 = stack[-3];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcar(v0312);
    v0312 = cons(v0313, v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v0312 = (*qfn2(fn))(qenv(fn), stack[0], v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    v0312 = stack[-1];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    stack[0] = qcdr(v0312);
    v0313 = stack[-3];
    v0312 = stack[-1];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcar(v0312);
    v0312 = cons(v0313, v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v0312 = (*qfn2(fn))(qenv(fn), stack[0], v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    v0312 = stack[-3];
    fn = elt(env, 5); /* ibalp_getnewwl */
    v0312 = (*qfn1(fn))(qenv(fn), v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    stack[-1] = v0312;
    v0312 = stack[-1];
    if (v0312 == nil) goto v0023;
    v0312 = stack[-3];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    stack[0] = qcdr(v0312);
    v0313 = stack[-1];
    v0312 = stack[-3];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcar(v0312);
    v0312 = cons(v0313, v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v0312 = (*qfn2(fn))(qenv(fn), stack[0], v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    v0312 = stack[-1];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    stack[0] = qcdr(v0312);
    v0313 = stack[-3];
    v0312 = stack[-1];
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcdr(v0312);
    v0312 = qcar(v0312);
    v0312 = cons(v0313, v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v0312 = (*qfn2(fn))(qenv(fn), stack[0], v0312);
    nil = C_nil;
    if (exception_pending()) goto v0314;
    env = stack[-6];
    goto v0023;

v0023:
    v0312 = stack[-5];
    v0312 = qcdr(v0312);
    stack[-5] = v0312;
    goto v0005;

v0047:
    v0312 = nil;
    { popv(7); return onevalue(v0312); }
/* error exit handlers */
v0314:
    popv(7);
    return nil;
}



/* Code for aex_mult */

static Lisp_Object CC_aex_mult(Lisp_Object env,
                         Lisp_Object v0036, Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_mult");
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0036,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
    stack[-2] = v0036;
/* end of prologue */
    v0023 = stack[-2];
    fn = elt(env, 2); /* aex_ex */
    stack[0] = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    v0023 = stack[-1];
    fn = elt(env, 2); /* aex_ex */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    fn = elt(env, 3); /* ratpoly_mult */
    stack[-3] = (*qfn2(fn))(qenv(fn), stack[0], v0023);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    v0023 = stack[-2];
    fn = elt(env, 4); /* aex_ctx */
    stack[0] = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    v0023 = stack[-1];
    fn = elt(env, 4); /* aex_ctx */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    fn = elt(env, 5); /* ctx_union */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0023);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    v0023 = stack[-2];
    fn = elt(env, 6); /* aex_lcnttag */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    if (v0023 == nil) goto v0043;
    v0023 = stack[-1];
    fn = elt(env, 6); /* aex_lcnttag */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-4];
    v0131 = v0023;
    goto v0048;

v0048:
    v0023 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0060 = stack[-3];
        Lisp_Object v0061 = stack[0];
        popv(5);
        fn = elt(env, 7); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v0060, v0061, v0131, v0023);
    }

v0043:
    v0023 = qvalue(elt(env, 1)); /* nil */
    v0131 = v0023;
    goto v0048;
/* error exit handlers */
v0032:
    popv(5);
    return nil;
}



/* Code for ev_tdeg */

static Lisp_Object CC_ev_tdeg(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0117, v0064, v0065;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_tdeg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0064 = v0036;
/* end of prologue */
    v0117 = (Lisp_Object)1; /* 0 */
    goto v0047;

v0047:
    v0065 = v0064;
    if (v0065 == nil) return onevalue(v0117);
    v0065 = v0064;
    v0065 = qcar(v0065);
    v0117 = (Lisp_Object)(int32_t)((int32_t)v0065 + (int32_t)v0117 - TAG_FIXNUM);
    v0064 = qcdr(v0064);
    goto v0047;
}



/* Code for omsir */

static Lisp_Object MS_CDECL CC_omsir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0160, v0282;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omsir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omsir");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* end of prologue */
    stack[-1] = nil;
    v0160 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0160;
    v0282 = qvalue(elt(env, 2)); /* atts */
    v0160 = elt(env, 3); /* name */
    fn = elt(env, 12); /* find */
    v0160 = (*qfn2(fn))(qenv(fn), v0282, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    v0160 = Lintern(nil, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    stack[-5] = v0160;
    v0282 = qvalue(elt(env, 2)); /* atts */
    v0160 = elt(env, 4); /* cd */
    fn = elt(env, 12); /* find */
    v0160 = (*qfn2(fn))(qenv(fn), v0282, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    v0160 = Lintern(nil, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    stack[-3] = v0160;
    v0160 = stack[-5];
    v0282 = Lexplode(nil, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    v0160 = elt(env, 5); /* (v e c t o r) */
    if (equal(v0282, v0160)) goto v0040;
    v0160 = stack[-5];
    v0282 = Lintern(nil, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    v0160 = qvalue(elt(env, 7)); /* mmleq!* */
    v0160 = Lmember(nil, v0282, v0160);
    stack[-4] = v0160;
    goto v0039;

v0039:
    v0160 = stack[-4];
    if (!(v0160 == nil)) goto v0053;
    v0282 = stack[-5];
    v0160 = qvalue(elt(env, 8)); /* special_cases!* */
    v0160 = Lassoc(nil, v0282, v0160);
    stack[-4] = v0160;
    if (v0160 == nil) goto v0151;
    v0160 = stack[-4];
    v0160 = Lreverse(nil, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    v0160 = qcar(v0160);
    stack[-2] = v0160;
    v0160 = stack[-2];
    if (v0160 == nil) goto v0113;
    v0160 = stack[-2];
    v0160 = ncons(v0160);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    stack[-2] = v0160;
    goto v0113;

v0113:
    v0160 = stack[-4];
    v0160 = Lreverse(nil, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    v0160 = qcdr(v0160);
    stack[0] = qcar(v0160);
    v0160 = stack[-4];
    v0160 = qcdr(v0160);
    v0160 = Lreverse(nil, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    v0160 = qcdr(v0160);
    v0160 = qcdr(v0160);
    v0160 = Lreverse(nil, v0160);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    v0160 = cons(stack[0], v0160);
    nil = C_nil;
    if (exception_pending()) goto v0316;
    env = stack[-6];
    stack[-4] = v0160;
    goto v0053;

v0053:
    v0160 = stack[-4];
    if (v0160 == nil) goto v0080;
    v0160 = stack[-4];
    v0282 = qcar(v0160);
    v0160 = qvalue(elt(env, 10)); /* valid_om!* */
    v0160 = Lassoc(nil, v0282, v0160);
    stack[-1] = v0160;
    goto v0080;

v0080:
    v0160 = stack[-1];
    if (v0160 == nil) goto v0112;
    v0160 = stack[-1];
    v0160 = qcdr(v0160);
    v0160 = qcar(v0160);
    stack[-1] = v0160;
    goto v0112;

v0112:
    v0160 = stack[-4];
    if (v0160 == nil) goto v0267;
    v0282 = stack[-3];
    v0160 = stack[-1];
    v0160 = (v0160 == nil ? lisp_true : nil);
    v0160 = (equal(v0282, v0160) ? lisp_true : nil);
    goto v0266;

v0266:
    if (v0160 == nil) goto v0105;
    v0160 = stack[-5];
    {
        popv(7);
        fn = elt(env, 13); /* encodeir */
        return (*qfn1(fn))(qenv(fn), v0160);
    }

v0105:
    v0160 = stack[-4];
    v0282 = qcar(v0160);
    v0160 = stack[-2];
    popv(7);
    return list2(v0282, v0160);

v0267:
    v0160 = qvalue(elt(env, 11)); /* t */
    goto v0266;

v0151:
    v0282 = stack[-5];
    v0160 = qvalue(elt(env, 9)); /* special_cases2!* */
    v0282 = Lassoc(nil, v0282, v0160);
    v0160 = v0282;
    if (v0282 == nil) goto v0053;
    v0282 = v0160;
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    v0160 = qcdr(v0160);
    v0160 = qcdr(v0160);
    {
        popv(7);
        fn = elt(env, 14); /* apply */
        return (*qfn2(fn))(qenv(fn), v0282, v0160);
    }

v0040:
    v0160 = elt(env, 6); /* (vectorml linalg1) */
    stack[-4] = v0160;
    goto v0039;
/* error exit handlers */
v0316:
    popv(7);
    return nil;
}



/* Code for ps!:minusp!: */

static Lisp_Object CC_psTminuspT(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object v0002;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:minusp:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0002 = v0036;
/* end of prologue */
    v0002 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0002);
}



/* Code for spband_matrix */

static Lisp_Object CC_spband_matrix(Lisp_Object env,
                         Lisp_Object v0036, Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0329, v0265, v0269;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spband_matrix");
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0036,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0000;
    stack[-8] = v0036;
/* end of prologue */
    stack[0] = stack[-7];
    v0269 = elt(env, 1); /* spm */
    v0265 = stack[-7];
    v0329 = stack[-7];
    v0329 = list3(v0269, v0265, v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    fn = elt(env, 10); /* mkempspmat */
    v0329 = (*qfn2(fn))(qenv(fn), stack[0], v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    stack[-9] = v0329;
    v0329 = stack[-7];
    v0329 = integerp(v0329);
    if (!(v0329 == nil)) goto v0043;
    v0329 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v0329 == nil)) goto v0073;
    v0329 = elt(env, 3); /* "Error in spband_matrix(second argument): should be an integer." 
*/
    fn = elt(env, 11); /* lprie */
    v0329 = (*qfn1(fn))(qenv(fn), v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    goto v0073;

v0073:
    v0329 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    goto v0043;

v0043:
    v0329 = stack[-8];
    if (!consp(v0329)) goto v0060;
    v0329 = stack[-8];
    v0265 = qcar(v0329);
    v0329 = elt(env, 4); /* list */
    if (v0265 == v0329) goto v0054;
    v0329 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v0329 == nil)) goto v0058;
    v0329 = elt(env, 5); /* "Error in spband_matrix(first argument): should be single value or list." 
*/
    fn = elt(env, 11); /* lprie */
    v0329 = (*qfn1(fn))(qenv(fn), v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    goto v0058;

v0058:
    v0329 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    goto v0032;

v0032:
    v0329 = stack[-8];
    v0329 = Llength(nil, v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    stack[-4] = v0329;
    v0329 = stack[-4];
    v0329 = Levenp(nil, v0329);
    env = stack[-10];
    if (v0329 == nil) goto v0216;
    v0329 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v0329 == nil)) goto v0014;
    v0329 = elt(env, 6); /* "Error in spband matrix(first argument): number of elements must be odd." 
*/
    fn = elt(env, 11); /* lprie */
    v0329 = (*qfn1(fn))(qenv(fn), v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    goto v0014;

v0014:
    v0329 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    goto v0216;

v0216:
    stack[0] = elt(env, 7); /* quotient */
    v0329 = stack[-4];
    v0265 = add1(v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    v0329 = (Lisp_Object)33; /* 2 */
    v0329 = list3(stack[0], v0265, v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    fn = elt(env, 12); /* reval */
    v0329 = (*qfn1(fn))(qenv(fn), v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    stack[-3] = v0329;
    v0329 = stack[-3];
    v0329 = integerp(v0329);
    if (v0329 == nil) goto v0330;
    v0329 = stack[-3];
    v0265 = v0329;
    goto v0026;

v0026:
    v0329 = stack[-7];
    v0329 = (Lisp_Object)greaterp2(v0265, v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    v0329 = v0329 ? lisp_true : nil;
    env = stack[-10];
    if (v0329 == nil) goto v0006;
    v0329 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v0329 == nil)) goto v0217;
    v0329 = elt(env, 8); /* "Error in spband_matrix: too many elements. Band matrix is overflowing." 
*/
    fn = elt(env, 11); /* lprie */
    v0329 = (*qfn1(fn))(qenv(fn), v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    goto v0217;

v0217:
    v0329 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    goto v0006;

v0006:
    v0329 = (Lisp_Object)33; /* 2 */
    stack[-5] = v0329;
    v0329 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0329;
    goto v0147;

v0147:
    v0265 = stack[-7];
    v0329 = stack[-2];
    v0329 = difference2(v0265, v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    v0329 = Lminusp(nil, v0329);
    env = stack[-10];
    if (!(v0329 == nil)) { Lisp_Object res = stack[-9]; popv(11); return onevalue(res); }
    v0265 = stack[-2];
    v0329 = stack[-3];
    v0329 = (Lisp_Object)lesseq2(v0265, v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    v0329 = v0329 ? lisp_true : nil;
    env = stack[-10];
    if (v0329 == nil) goto v0160;
    v0329 = (Lisp_Object)17; /* 1 */
    stack[-6] = v0329;
    goto v0254;

v0254:
    v0265 = stack[-3];
    v0329 = stack[-2];
    v0265 = difference2(v0265, v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    v0329 = stack[-6];
    v0265 = plus2(v0265, v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    v0329 = (Lisp_Object)1; /* 0 */
    v0329 = (Lisp_Object)greaterp2(v0265, v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    v0329 = v0329 ? lisp_true : nil;
    env = stack[-10];
    if (v0329 == nil) goto v0237;
    v0265 = stack[-6];
    v0329 = stack[-7];
    v0329 = (Lisp_Object)lesseq2(v0265, v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    v0329 = v0329 ? lisp_true : nil;
    env = stack[-10];
    if (v0329 == nil) goto v0237;
    v0265 = stack[-3];
    v0329 = stack[-2];
    v0265 = difference2(v0265, v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    v0329 = stack[-6];
    v0265 = plus2(v0265, v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    v0329 = stack[-4];
    v0329 = (Lisp_Object)lesseq2(v0265, v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    v0329 = v0329 ? lisp_true : nil;
    env = stack[-10];
    if (v0329 == nil) goto v0237;
    v0269 = stack[-9];
    v0265 = stack[-2];
    v0329 = stack[-6];
    stack[-1] = list3(v0269, v0265, v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    stack[0] = stack[-8];
    v0265 = stack[-3];
    v0329 = stack[-2];
    v0265 = difference2(v0265, v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    v0329 = stack[-6];
    v0329 = plus2(v0265, v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    fn = elt(env, 13); /* pnth */
    v0329 = (*qfn2(fn))(qenv(fn), stack[0], v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    v0269 = qcar(v0329);
    v0265 = stack[-9];
    v0329 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 14); /* letmtr3 */
    v0329 = (*qfnn(fn))(qenv(fn), 4, stack[-1], v0269, v0265, v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    v0329 = stack[-6];
    v0329 = add1(v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    stack[-6] = v0329;
    goto v0254;

v0237:
    v0265 = stack[-2];
    v0329 = stack[-3];
    v0329 = (Lisp_Object)greaterp2(v0265, v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    v0329 = v0329 ? lisp_true : nil;
    env = stack[-10];
    if (v0329 == nil) goto v0264;
    v0329 = stack[-5];
    v0329 = add1(v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    stack[-5] = v0329;
    goto v0264;

v0264:
    v0329 = stack[-2];
    v0329 = add1(v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    stack[-2] = v0329;
    goto v0147;

v0160:
    v0329 = stack[-5];
    stack[-6] = v0329;
    goto v0254;

v0330:
    v0329 = stack[-3];
    fn = elt(env, 12); /* reval */
    v0329 = (*qfn1(fn))(qenv(fn), v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    v0265 = v0329;
    goto v0026;

v0054:
    v0329 = stack[-8];
    v0329 = qcdr(v0329);
    stack[-8] = v0329;
    goto v0032;

v0060:
    v0329 = stack[-8];
    v0329 = ncons(v0329);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-10];
    stack[-8] = v0329;
    goto v0032;
/* error exit handlers */
v0241:
    popv(11);
    return nil;
}



/* Code for matsm!* */

static Lisp_Object CC_matsmH(Lisp_Object env,
                         Lisp_Object v0036, Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matsm*");
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0036,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0003 = v0000;
    v0034 = v0036;
/* end of prologue */
    v0003 = v0034;
    fn = elt(env, 1); /* matsm */
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* matsm!*1 */
        return (*qfn1(fn))(qenv(fn), v0003);
    }
/* error exit handlers */
v0047:
    popv(1);
    return nil;
}



/* Code for dipevlcomp */

static Lisp_Object CC_dipevlcomp(Lisp_Object env,
                         Lisp_Object v0036, Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipevlcomp");
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0036,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0029 = v0000;
    v0042 = v0036;
/* end of prologue */
    v0042 = qcar(v0042);
    v0029 = qcar(v0029);
    fn = elt(env, 1); /* evcompless!? */
    v0029 = (*qfn2(fn))(qenv(fn), v0042, v0029);
    errexit();
    v0029 = (v0029 == nil ? lisp_true : nil);
    return onevalue(v0029);
}



/* Code for !*pf2wedgepf */

static Lisp_Object CC_Hpf2wedgepf(Lisp_Object env,
                         Lisp_Object v0036)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0037, v0043;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *pf2wedgepf");
#endif
    if (stack >= stacklimit)
    {
        push(v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0036;
/* end of prologue */
    stack[-1] = nil;
    goto v0004;

v0004:
    v0040 = stack[0];
    if (v0040 == nil) goto v0047;
    v0040 = stack[0];
    v0040 = qcar(v0040);
    v0040 = qcar(v0040);
    fn = elt(env, 1); /* wedgefax */
    v0043 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    v0040 = stack[0];
    v0040 = qcar(v0040);
    v0037 = qcdr(v0040);
    v0040 = stack[-1];
    v0040 = acons(v0043, v0037, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    stack[-1] = v0040;
    v0040 = stack[0];
    v0040 = qcdr(v0040);
    stack[0] = v0040;
    goto v0004;

v0047:
    v0040 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0040);
    }
/* error exit handlers */
v0020:
    popv(3);
    return nil;
}



/* Code for removeindices */

static Lisp_Object CC_removeindices(Lisp_Object env,
                         Lisp_Object v0036, Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0267, v0205;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for removeindices");
#endif
    if (stack >= stacklimit)
    {
        push2(v0000,v0036);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0036,v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0000;
    stack[-3] = v0036;
/* end of prologue */
    v0205 = elt(env, 0); /* removeindices */
    v0267 = elt(env, 1); /* tracing */
    v0267 = Lflagp(nil, v0205, v0267);
    env = stack[-5];
    if (v0267 == nil) goto v0034;
    stack[-4] = elt(env, 0); /* removeindices */
    stack[-1] = elt(env, 2); /* "u= " */
    stack[0] = stack[-3];
    v0205 = elt(env, 3); /* " x= " */
    v0267 = stack[-2];
    v0267 = list2(v0205, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-5];
    v0267 = list3star(stack[-4], stack[-1], stack[0], v0267);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-5];
    fn = elt(env, 7); /* trwrite */
    v0267 = (*qfn1(fn))(qenv(fn), v0267);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-5];
    goto v0034;

v0034:
    v0267 = stack[-2];
    if (v0267 == nil) goto v0131;
    v0267 = stack[-3];
    v0267 = Lsymbolp(nil, v0267);
    env = stack[-5];
    if (!(v0267 == nil)) goto v0023;
    v0267 = stack[-3];
    fn = elt(env, 8); /* !*physopp */
    v0267 = (*qfn1(fn))(qenv(fn), v0267);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-5];
    v0267 = (v0267 == nil ? lisp_true : nil);
    goto v0023;

v0023:
    if (!(v0267 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0267 = stack[-2];
    if (!(symbolp(v0267))) goto v0051;
    v0267 = stack[-2];
    fn = elt(env, 9); /* isanindex */
    v0267 = (*qfn1(fn))(qenv(fn), v0267);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-5];
    if (!(v0267 == nil)) goto v0051;

v0013:
    v0205 = elt(env, 0); /* removeindices */
    v0267 = elt(env, 5); /* "invalid arguments to removeindices" */
    fn = elt(env, 10); /* rederr2 */
    v0267 = (*qfn2(fn))(qenv(fn), v0205, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-5];
    goto v0167;

v0167:
    v0267 = stack[-3];
    v0267 = qcar(v0267);
    stack[0] = v0267;
    v0267 = stack[-3];
    v0267 = qcdr(v0267);
    stack[-3] = v0267;
    v0267 = stack[-3];
    if (v0267 == nil) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v0267 = stack[-2];
    if (symbolp(v0267)) goto v0151;
    v0267 = stack[-2];
    stack[-1] = v0267;
    goto v0072;

v0072:
    v0267 = stack[-1];
    if (v0267 == nil) goto v0150;
    v0267 = stack[-1];
    v0267 = qcar(v0267);
    v0205 = v0267;
    v0267 = stack[-3];
    v0267 = Ldelete(nil, v0205, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-5];
    stack[-3] = v0267;
    v0267 = stack[-1];
    v0267 = qcdr(v0267);
    stack[-1] = v0267;
    goto v0072;

v0150:
    v0267 = stack[-3];
    if (v0267 == nil) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v0205 = stack[0];
    v0267 = stack[-3];
    popv(6);
    return cons(v0205, v0267);

v0151:
    v0205 = stack[-2];
    v0267 = stack[-3];
    v0267 = Ldelete(nil, v0205, v0267);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    stack[-3] = v0267;
    goto v0150;

v0051:
    v0267 = stack[-2];
    fn = elt(env, 11); /* idlistp */
    v0267 = (*qfn1(fn))(qenv(fn), v0267);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-5];
    if (v0267 == nil) goto v0167;
    v0267 = stack[-2];
    fn = elt(env, 12); /* areallindices */
    v0267 = (*qfn1(fn))(qenv(fn), v0267);
    nil = C_nil;
    if (exception_pending()) goto v0147;
    env = stack[-5];
    if (v0267 == nil) goto v0013;
    else goto v0167;

v0131:
    v0267 = qvalue(elt(env, 4)); /* t */
    goto v0023;
/* error exit handlers */
v0147:
    popv(6);
    return nil;
}



setup_type const u16_setup[] =
{
    {"sf2mv1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_sf2mv1},
    {"rnminusp:",               CC_rnminuspT,   too_many_1,    wrong_no_1},
    {"di_restore",              CC_di_restore,  too_many_1,    wrong_no_1},
    {"resimpf",                 CC_resimpf,     too_many_1,    wrong_no_1},
    {"numeric-content",         CC_numericKcontent,too_many_1, wrong_no_1},
    {"cl_identifyat",           CC_cl_identifyat,too_many_1,   wrong_no_1},
    {"evaluatecoeffts",         too_few_2,      CC_evaluatecoeffts,wrong_no_2},
    {"ibalp_readclause",        too_few_2,      CC_ibalp_readclause,wrong_no_2},
    {"ratpoly_1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ratpoly_1},
    {"mapins",                  too_few_2,      CC_mapins,     wrong_no_2},
    {"om2mml",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_om2mml},
    {"resume",                  too_few_2,      CC_resume,     wrong_no_2},
    {"setmat",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_setmat},
    {"rd:plus",                 too_few_2,      CC_rdTplus,    wrong_no_2},
    {"total-degree-in-powers",  too_few_2,      CC_totalKdegreeKinKpowers,wrong_no_2},
    {"begin1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_begin1},
    {"red_divtest",             too_few_2,      CC_red_divtest,wrong_no_2},
    {"il_simp",                 CC_il_simp,     too_many_1,    wrong_no_1},
    {"repeats",                 CC_repeats,     too_many_1,    wrong_no_1},
    {"arglist_member",          too_few_2,      CC_arglist_member,wrong_no_2},
    {"mconv",                   CC_mconv,       too_many_1,    wrong_no_1},
    {"remlocs",                 CC_remlocs,     too_many_1,    wrong_no_1},
    {"ofsf_entry2at1",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_entry2at1},
    {"ibalp_process-var",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_ibalp_processKvar},
    {"cgp_ci",                  CC_cgp_ci,      too_many_1,    wrong_no_1},
    {"*wedgepf2pf",             CC_Hwedgepf2pf, too_many_1,    wrong_no_1},
    {"assert_error",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_error},
    {"mo_neg",                  CC_mo_neg,      too_many_1,    wrong_no_1},
    {"pappend",                 too_few_2,      CC_pappend,    wrong_no_2},
    {"set-general-modulus",     CC_setKgeneralKmodulus,too_many_1,wrong_no_1},
    {"simpatom",                CC_simpatom,    too_many_1,    wrong_no_1},
    {"gettype",                 CC_gettype,     too_many_1,    wrong_no_1},
    {"pasf_vf",                 CC_pasf_vf,     too_many_1,    wrong_no_1},
    {"ibalp_unvar-unsatlist",   too_few_2,      CC_ibalp_unvarKunsatlist,wrong_no_2},
    {"aex_mult",                too_few_2,      CC_aex_mult,   wrong_no_2},
    {"ev_tdeg",                 CC_ev_tdeg,     too_many_1,    wrong_no_1},
    {"omsir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omsir},
    {"ps:minusp:",              CC_psTminuspT,  too_many_1,    wrong_no_1},
    {"spband_matrix",           too_few_2,      CC_spband_matrix,wrong_no_2},
    {"matsm*",                  too_few_2,      CC_matsmH,     wrong_no_2},
    {"dipevlcomp",              too_few_2,      CC_dipevlcomp, wrong_no_2},
    {"*pf2wedgepf",             CC_Hpf2wedgepf, too_many_1,    wrong_no_1},
    {"removeindices",           too_few_2,      CC_removeindices,wrong_no_2},
    {NULL, (one_args *)"u16", (two_args *)"14665 2833615 3916234", 0}
};

/* end of generated code */
